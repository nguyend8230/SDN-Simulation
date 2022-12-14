// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: register.proto

#include "register.pb.h"
#include "register.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace register_service {

static const char* RegisterService_method_names[] = {
  "/register_service.RegisterService/GetAllRegisterArrays",
  "/register_service.RegisterService/GetRegisterArray",
  "/register_service.RegisterService/CreateRegisterArray",
  "/register_service.RegisterService/DeleteRegisterArray",
  "/register_service.RegisterService/ReadValue",
  "/register_service.RegisterService/WriteValue",
};

std::unique_ptr< RegisterService::Stub> RegisterService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< RegisterService::Stub> stub(new RegisterService::Stub(channel, options));
  return stub;
}

RegisterService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetAllRegisterArrays_(RegisterService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetRegisterArray_(RegisterService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CreateRegisterArray_(RegisterService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DeleteRegisterArray_(RegisterService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ReadValue_(RegisterService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_WriteValue_(RegisterService_method_names[5], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status RegisterService::Stub::GetAllRegisterArrays(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::register_service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::google::protobuf::Empty, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetAllRegisterArrays_, context, request, response);
}

void RegisterService::Stub::async::GetAllRegisterArrays(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::register_service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::google::protobuf::Empty, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetAllRegisterArrays_, context, request, response, std::move(f));
}

void RegisterService::Stub::async::GetAllRegisterArrays(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::register_service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetAllRegisterArrays_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::PrepareAsyncGetAllRegisterArraysRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::register_service::Response, ::google::protobuf::Empty, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetAllRegisterArrays_, context, request);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::AsyncGetAllRegisterArraysRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetAllRegisterArraysRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status RegisterService::Stub::GetRegisterArray(::grpc::ClientContext* context, const ::register_service::GetRequest& request, ::register_service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::register_service::GetRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetRegisterArray_, context, request, response);
}

void RegisterService::Stub::async::GetRegisterArray(::grpc::ClientContext* context, const ::register_service::GetRequest* request, ::register_service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::register_service::GetRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRegisterArray_, context, request, response, std::move(f));
}

void RegisterService::Stub::async::GetRegisterArray(::grpc::ClientContext* context, const ::register_service::GetRequest* request, ::register_service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetRegisterArray_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::PrepareAsyncGetRegisterArrayRaw(::grpc::ClientContext* context, const ::register_service::GetRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::register_service::Response, ::register_service::GetRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetRegisterArray_, context, request);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::AsyncGetRegisterArrayRaw(::grpc::ClientContext* context, const ::register_service::GetRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetRegisterArrayRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status RegisterService::Stub::CreateRegisterArray(::grpc::ClientContext* context, const ::register_service::CreateRequest& request, ::register_service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::register_service::CreateRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CreateRegisterArray_, context, request, response);
}

void RegisterService::Stub::async::CreateRegisterArray(::grpc::ClientContext* context, const ::register_service::CreateRequest* request, ::register_service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::register_service::CreateRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateRegisterArray_, context, request, response, std::move(f));
}

void RegisterService::Stub::async::CreateRegisterArray(::grpc::ClientContext* context, const ::register_service::CreateRequest* request, ::register_service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CreateRegisterArray_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::PrepareAsyncCreateRegisterArrayRaw(::grpc::ClientContext* context, const ::register_service::CreateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::register_service::Response, ::register_service::CreateRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CreateRegisterArray_, context, request);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::AsyncCreateRegisterArrayRaw(::grpc::ClientContext* context, const ::register_service::CreateRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCreateRegisterArrayRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status RegisterService::Stub::DeleteRegisterArray(::grpc::ClientContext* context, const ::register_service::DeleteRequest& request, ::register_service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::register_service::DeleteRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DeleteRegisterArray_, context, request, response);
}

void RegisterService::Stub::async::DeleteRegisterArray(::grpc::ClientContext* context, const ::register_service::DeleteRequest* request, ::register_service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::register_service::DeleteRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteRegisterArray_, context, request, response, std::move(f));
}

void RegisterService::Stub::async::DeleteRegisterArray(::grpc::ClientContext* context, const ::register_service::DeleteRequest* request, ::register_service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DeleteRegisterArray_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::PrepareAsyncDeleteRegisterArrayRaw(::grpc::ClientContext* context, const ::register_service::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::register_service::Response, ::register_service::DeleteRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DeleteRegisterArray_, context, request);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::AsyncDeleteRegisterArrayRaw(::grpc::ClientContext* context, const ::register_service::DeleteRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDeleteRegisterArrayRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status RegisterService::Stub::ReadValue(::grpc::ClientContext* context, const ::register_service::ReadItemRequest& request, ::register_service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::register_service::ReadItemRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ReadValue_, context, request, response);
}

void RegisterService::Stub::async::ReadValue(::grpc::ClientContext* context, const ::register_service::ReadItemRequest* request, ::register_service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::register_service::ReadItemRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReadValue_, context, request, response, std::move(f));
}

void RegisterService::Stub::async::ReadValue(::grpc::ClientContext* context, const ::register_service::ReadItemRequest* request, ::register_service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ReadValue_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::PrepareAsyncReadValueRaw(::grpc::ClientContext* context, const ::register_service::ReadItemRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::register_service::Response, ::register_service::ReadItemRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ReadValue_, context, request);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::AsyncReadValueRaw(::grpc::ClientContext* context, const ::register_service::ReadItemRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncReadValueRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status RegisterService::Stub::WriteValue(::grpc::ClientContext* context, const ::register_service::WriteItemRequest& request, ::register_service::Response* response) {
  return ::grpc::internal::BlockingUnaryCall< ::register_service::WriteItemRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_WriteValue_, context, request, response);
}

void RegisterService::Stub::async::WriteValue(::grpc::ClientContext* context, const ::register_service::WriteItemRequest* request, ::register_service::Response* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::register_service::WriteItemRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_WriteValue_, context, request, response, std::move(f));
}

void RegisterService::Stub::async::WriteValue(::grpc::ClientContext* context, const ::register_service::WriteItemRequest* request, ::register_service::Response* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_WriteValue_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::PrepareAsyncWriteValueRaw(::grpc::ClientContext* context, const ::register_service::WriteItemRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::register_service::Response, ::register_service::WriteItemRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_WriteValue_, context, request);
}

::grpc::ClientAsyncResponseReader< ::register_service::Response>* RegisterService::Stub::AsyncWriteValueRaw(::grpc::ClientContext* context, const ::register_service::WriteItemRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncWriteValueRaw(context, request, cq);
  result->StartCall();
  return result;
}

RegisterService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterService::Service, ::google::protobuf::Empty, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::google::protobuf::Empty* req,
             ::register_service::Response* resp) {
               return service->GetAllRegisterArrays(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterService::Service, ::register_service::GetRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::register_service::GetRequest* req,
             ::register_service::Response* resp) {
               return service->GetRegisterArray(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterService::Service, ::register_service::CreateRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::register_service::CreateRequest* req,
             ::register_service::Response* resp) {
               return service->CreateRegisterArray(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterService::Service, ::register_service::DeleteRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::register_service::DeleteRequest* req,
             ::register_service::Response* resp) {
               return service->DeleteRegisterArray(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterService::Service, ::register_service::ReadItemRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::register_service::ReadItemRequest* req,
             ::register_service::Response* resp) {
               return service->ReadValue(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      RegisterService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< RegisterService::Service, ::register_service::WriteItemRequest, ::register_service::Response, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](RegisterService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::register_service::WriteItemRequest* req,
             ::register_service::Response* resp) {
               return service->WriteValue(ctx, req, resp);
             }, this)));
}

RegisterService::Service::~Service() {
}

::grpc::Status RegisterService::Service::GetAllRegisterArrays(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::register_service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RegisterService::Service::GetRegisterArray(::grpc::ServerContext* context, const ::register_service::GetRequest* request, ::register_service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RegisterService::Service::CreateRegisterArray(::grpc::ServerContext* context, const ::register_service::CreateRequest* request, ::register_service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RegisterService::Service::DeleteRegisterArray(::grpc::ServerContext* context, const ::register_service::DeleteRequest* request, ::register_service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RegisterService::Service::ReadValue(::grpc::ServerContext* context, const ::register_service::ReadItemRequest* request, ::register_service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status RegisterService::Service::WriteValue(::grpc::ServerContext* context, const ::register_service::WriteItemRequest* request, ::register_service::Response* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace register_service

