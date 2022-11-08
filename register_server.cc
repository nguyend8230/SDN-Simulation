#include "register_server.h"

using namespace std;

RegisterServiceImpl::RegisterServiceImpl() {
}

void RegisterServiceImpl::BuildRegisterArrayResponse(::register_service::Response* response,
                                std::map<std::string, RegisterArray*>::iterator it) {
    if (it == _registers.end()) {
        return;
    }

    // Task: Copy the register array `it` to response (follow the following five instructions)
    
    // 1. Get the register array from `it`
    RegisterArray* curr_reg = it->second;

    // 2. Add a new register array to `response`
    RegisterArray* new_reg = response->mutable_arrays()->add_arrays();
    new_reg->set_name(curr_reg->name());
    new_reg->set_capacity(curr_reg->capacity());
    new_reg->set_size(curr_reg->size());

    // 3. Copy items from `curr_reg` to `new_reg`
    ::google::protobuf::RepeatedField<uint32_t>::iterator curr_it;

    for(google::protobuf::uint32 i : curr_reg->items()) {
        // 5. Add an item
        new_reg->mutable_items()->Add(i);
    }
}

::grpc::Status
RegisterServiceImpl::GetAllRegisterArrays(::grpc::ServerContext* context,
                                          const ::google::protobuf::Empty* request,
                                          ::register_service::Response* response) {
    
    // Task: output all register arrays to `response`

    // Iterate over the register arrays in `_registers`, and call `BuildRegisterArrayResponse`
    std::map<std::string, RegisterArray*>::iterator it;

    for(it = _registers.begin(); it != _registers.end(); it++) {
        RegisterServiceImpl::BuildRegisterArrayResponse(response, it);
    }

    return Status::OK;
}

::grpc::Status
RegisterServiceImpl::GetRegisterArray(::grpc::ServerContext* context,
                                      const ::register_service::GetRequest* request,
                                      ::register_service::Response* response) {
    std::string name = request->name();

    // Task: output the requested register array to `response`
    // 1. Search for the register array in `_registers`
    // 2. If it doesn't exist, the body of the `if` statement should execute
    // 3. Otherwise, call BuildRegisterArrayResponse

    std::map<std::string, RegisterArray*>::iterator it = _registers.find(name);
    if (!_registers.count(name)) {
        std::string msg("[GET] Register " + name + " doesn't exist");
        return Status(StatusCode::NOT_FOUND, msg);
    }

    // Call BuildRegisterArrayResponse
    RegisterServiceImpl::BuildRegisterArrayResponse(response, it);
    
    return Status::OK;
}

::grpc::Status
RegisterServiceImpl::CreateRegisterArray(::grpc::ServerContext* context,
                                         const ::register_service::CreateRequest* request,
                                         ::register_service::Response* response) {
    std::string name = request->name();
    uint32_t capacity = request->capacity();
    
    // Task: create a new register array
    // 1. Search for the register array in `_registers`
    // 2. If it exists, the body of the `if` statement should execute
    // 3. Otherwise, create a new RegisterArray object and add it to `_registers`
    // All new items should be zero'd
 
    if (_registers.count(name)) {
        std::string msg("[CREATE] Register: " + name + " already exists");
        return Status(StatusCode::ALREADY_EXISTS, msg);
    }
    else {
        register_service::RegisterArray* r = new register_service::RegisterArray();

        r->set_name(name); // set the name
        r->set_size(0); // set the size
        r->set_capacity(capacity); // set the capacity
        
        // All items are initialized with zeros
        for (int i = 0; i < capacity; i++) {
            r->mutable_items()->Add(0);
        }

        // Add the register array to `_registers`
        _registers[name] = r;
    }
    
    _written_indices.insert(std::pair<std::string, std::set<uint32_t>*>(name, new std::set<uint32_t>()));
    return Status::OK;
}

::grpc::Status
RegisterServiceImpl::DeleteRegisterArray(::grpc::ServerContext* context,
                                         const ::register_service::DeleteRequest* request,
                                         ::register_service::Response* response) {
    std::string name = request->name();

    // Task: delete a register array
    // 1. Search for the register array in `_registers`
    // 2. If it doesn't exist, the body of the `if` statement should execute
    // 3. Otherwise, remove the register array from `_registers` and `_written_indices`
    
    if (!_registers.count(name)) {
        std::string msg("[DELETE] Register: " + name + " doesn't exist");
        return Status(StatusCode::NOT_FOUND, msg);
    }
    
    // Remove the register array from `_registers`
    _registers.erase(name);
    _written_indices.erase(name);

    return Status::OK;
}

::grpc::Status
RegisterServiceImpl::ReadValue(::grpc::ServerContext* context,
                               const ::register_service::ReadItemRequest* request,
                               ::register_service::Response* response) {
    std::string name = request->name();
    uint32_t index = request->index();

    // Task: read a value from a register array
    // 1. Search for the register array in `_registers`
    // 2. If it doesn't exist, the body of the first `if` statement should execute
    // 2. If it exists:
    // 2.a) if `index` is larger than register's capacity, the body of the second `if` statement should execute
    // 2.b) Otherwise, read the value to `response`
    
    if (!_registers.count(name)) {
        std::string msg("[READ] Register: " + name + " doesn't exist");
        return Status(StatusCode::NOT_FOUND, msg);
    }

    RegisterArray* r = _registers[name];

    if (index >= r->capacity()) {
        std::string msg("[READ] Register: " + name + ", Index: " + std::to_string(index) + " invalid");
        return Status(StatusCode::OUT_OF_RANGE, msg);
    }

    // get the value here
    uint32_t value = r->items().Get(index);

    response->set_value(value);
    return Status::OK;
}

::grpc::Status
RegisterServiceImpl::WriteValue(::grpc::ServerContext* context,
                                const ::register_service::WriteItemRequest* request,
                                ::register_service::Response* response) {
    std::string name = request->name();
    uint32_t index = request->index();
    uint32_t value = request->value();

    // Task: write a value to a register array
    // 1. Search for the register array in `_registers`
    // 2. If it doesn't exist, the body of the first `if` statement should execute
    // 2. If it exists:
    // 2.a) if `index` is larger than register's capacity, the body of the second `if` statement should execute
    // 2.b) Otherwise, modify the item using the given `index`

    std::map<std::string, std::set<uint32_t>*>::iterator it_wrt = _written_indices.find(name);

    if (!_registers.count(name)) {
        std::string msg("[WRITE] Register: " + name + " doesn't exist");
        return Status(StatusCode::NOT_FOUND, msg);
    }

    RegisterArray* r = _registers[name];

    uint32_t capacity = r->capacity();
    uint32_t size = r->size();

    
    if (index >= capacity) {
        std::string msg("[WRITE] Register: " + name + ", Index: " + std::to_string(index) + " invalid");
        return Status(StatusCode::OUT_OF_RANGE, msg);
    }

    // Modify the item here
    r->mutable_items()->Set(index, value);
    
    // Keep these lines
    std::set<uint32_t>* written = it_wrt->second;
    std::set<uint32_t>::iterator it_idx = written->find(index);
    if (it_idx == written->end()) {
        written->insert(index);
        r->set_size(size + 1);
    }
    
    return Status::OK;
}
