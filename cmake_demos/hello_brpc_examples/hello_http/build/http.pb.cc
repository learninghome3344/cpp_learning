// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: http.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "http.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace example {

namespace {

const ::google::protobuf::Descriptor* HttpRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HttpRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* HttpResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HttpResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* HttpService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* FileService_descriptor_ = NULL;
const ::google::protobuf::ServiceDescriptor* QueueService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_http_2eproto() {
  protobuf_AddDesc_http_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "http.proto");
  GOOGLE_CHECK(file != NULL);
  HttpRequest_descriptor_ = file->message_type(0);
  static const int HttpRequest_offsets_[1] = {
  };
  HttpRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HttpRequest_descriptor_,
      HttpRequest::default_instance_,
      HttpRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HttpRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HttpRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HttpRequest));
  HttpResponse_descriptor_ = file->message_type(1);
  static const int HttpResponse_offsets_[1] = {
  };
  HttpResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HttpResponse_descriptor_,
      HttpResponse::default_instance_,
      HttpResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HttpResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HttpResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HttpResponse));
  HttpService_descriptor_ = file->service(0);
  FileService_descriptor_ = file->service(1);
  QueueService_descriptor_ = file->service(2);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_http_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HttpRequest_descriptor_, &HttpRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HttpResponse_descriptor_, &HttpResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_http_2eproto() {
  delete HttpRequest::default_instance_;
  delete HttpRequest_reflection_;
  delete HttpResponse::default_instance_;
  delete HttpResponse_reflection_;
}

void protobuf_AddDesc_http_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nhttp.proto\022\007example\"\r\n\013HttpRequest\"\016\n\014"
    "HttpResponse2\201\001\n\013HttpService\0224\n\005Hello\022\024."
    "example.HttpRequest\032\025.example.HttpRespon"
    "se\022<\n\rHelloProtobuf\022\024.example.HttpReques"
    "t\032\025.example.HttpResponse2L\n\013FileService\022"
    "=\n\016default_method\022\024.example.HttpRequest\032"
    "\025.example.HttpResponse2\262\001\n\014QueueService\022"
    "4\n\005start\022\024.example.HttpRequest\032\025.example"
    ".HttpResponse\0223\n\004stop\022\024.example.HttpRequ"
    "est\032\025.example.HttpResponse\0227\n\010getstats\022\024"
    ".example.HttpRequest\032\025.example.HttpRespo"
    "nseB\003\200\001\001", 448);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "http.proto", &protobuf_RegisterTypes);
  HttpRequest::default_instance_ = new HttpRequest();
  HttpResponse::default_instance_ = new HttpResponse();
  HttpRequest::default_instance_->InitAsDefaultInstance();
  HttpResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_http_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_http_2eproto {
  StaticDescriptorInitializer_http_2eproto() {
    protobuf_AddDesc_http_2eproto();
  }
} static_descriptor_initializer_http_2eproto_;

// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

HttpRequest::HttpRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.HttpRequest)
}

void HttpRequest::InitAsDefaultInstance() {
}

HttpRequest::HttpRequest(const HttpRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:example.HttpRequest)
}

void HttpRequest::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HttpRequest::~HttpRequest() {
  // @@protoc_insertion_point(destructor:example.HttpRequest)
  SharedDtor();
}

void HttpRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void HttpRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HttpRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HttpRequest_descriptor_;
}

const HttpRequest& HttpRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_http_2eproto();
  return *default_instance_;
}

HttpRequest* HttpRequest::default_instance_ = NULL;

HttpRequest* HttpRequest::New() const {
  return new HttpRequest;
}

void HttpRequest::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HttpRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:example.HttpRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:example.HttpRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:example.HttpRequest)
  return false;
#undef DO_
}

void HttpRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:example.HttpRequest)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:example.HttpRequest)
}

::google::protobuf::uint8* HttpRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.HttpRequest)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.HttpRequest)
  return target;
}

int HttpRequest::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HttpRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HttpRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HttpRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HttpRequest::MergeFrom(const HttpRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HttpRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HttpRequest::CopyFrom(const HttpRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HttpRequest::IsInitialized() const {

  return true;
}

void HttpRequest::Swap(HttpRequest* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HttpRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HttpRequest_descriptor_;
  metadata.reflection = HttpRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

HttpResponse::HttpResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.HttpResponse)
}

void HttpResponse::InitAsDefaultInstance() {
}

HttpResponse::HttpResponse(const HttpResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:example.HttpResponse)
}

void HttpResponse::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HttpResponse::~HttpResponse() {
  // @@protoc_insertion_point(destructor:example.HttpResponse)
  SharedDtor();
}

void HttpResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void HttpResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HttpResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HttpResponse_descriptor_;
}

const HttpResponse& HttpResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_http_2eproto();
  return *default_instance_;
}

HttpResponse* HttpResponse::default_instance_ = NULL;

HttpResponse* HttpResponse::New() const {
  return new HttpResponse;
}

void HttpResponse::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HttpResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:example.HttpResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:example.HttpResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:example.HttpResponse)
  return false;
#undef DO_
}

void HttpResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:example.HttpResponse)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:example.HttpResponse)
}

::google::protobuf::uint8* HttpResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.HttpResponse)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.HttpResponse)
  return target;
}

int HttpResponse::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void HttpResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HttpResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HttpResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HttpResponse::MergeFrom(const HttpResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HttpResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HttpResponse::CopyFrom(const HttpResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HttpResponse::IsInitialized() const {

  return true;
}

void HttpResponse::Swap(HttpResponse* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HttpResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HttpResponse_descriptor_;
  metadata.reflection = HttpResponse_reflection_;
  return metadata;
}


// ===================================================================

HttpService::~HttpService() {}

const ::google::protobuf::ServiceDescriptor* HttpService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HttpService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* HttpService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return HttpService_descriptor_;
}

void HttpService::Hello(::google::protobuf::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Hello() not implemented.");
  done->Run();
}

void HttpService::HelloProtobuf(::google::protobuf::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method HelloProtobuf() not implemented.");
  done->Run();
}

void HttpService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), HttpService_descriptor_);
  switch(method->index()) {
    case 0:
      Hello(controller,
             ::google::protobuf::down_cast<const ::example::HttpRequest*>(request),
             ::google::protobuf::down_cast< ::example::HttpResponse*>(response),
             done);
      break;
    case 1:
      HelloProtobuf(controller,
             ::google::protobuf::down_cast<const ::example::HttpRequest*>(request),
             ::google::protobuf::down_cast< ::example::HttpResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& HttpService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    case 1:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& HttpService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    case 1:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

HttpService_Stub::HttpService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
HttpService_Stub::HttpService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
HttpService_Stub::~HttpService_Stub() {
  if (owns_channel_) delete channel_;
}

void HttpService_Stub::Hello(::google::protobuf::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void HttpService_Stub::HelloProtobuf(::google::protobuf::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
// ===================================================================

FileService::~FileService() {}

const ::google::protobuf::ServiceDescriptor* FileService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FileService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* FileService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return FileService_descriptor_;
}

void FileService::default_method(::google::protobuf::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method default_method() not implemented.");
  done->Run();
}

void FileService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), FileService_descriptor_);
  switch(method->index()) {
    case 0:
      default_method(controller,
             ::google::protobuf::down_cast<const ::example::HttpRequest*>(request),
             ::google::protobuf::down_cast< ::example::HttpResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& FileService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& FileService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

FileService_Stub::FileService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
FileService_Stub::FileService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
FileService_Stub::~FileService_Stub() {
  if (owns_channel_) delete channel_;
}

void FileService_Stub::default_method(::google::protobuf::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
// ===================================================================

QueueService::~QueueService() {}

const ::google::protobuf::ServiceDescriptor* QueueService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QueueService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* QueueService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return QueueService_descriptor_;
}

void QueueService::start(::google::protobuf::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method start() not implemented.");
  done->Run();
}

void QueueService::stop(::google::protobuf::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method stop() not implemented.");
  done->Run();
}

void QueueService::getstats(::google::protobuf::RpcController* controller,
                         const ::example::HttpRequest*,
                         ::example::HttpResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method getstats() not implemented.");
  done->Run();
}

void QueueService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), QueueService_descriptor_);
  switch(method->index()) {
    case 0:
      start(controller,
             ::google::protobuf::down_cast<const ::example::HttpRequest*>(request),
             ::google::protobuf::down_cast< ::example::HttpResponse*>(response),
             done);
      break;
    case 1:
      stop(controller,
             ::google::protobuf::down_cast<const ::example::HttpRequest*>(request),
             ::google::protobuf::down_cast< ::example::HttpResponse*>(response),
             done);
      break;
    case 2:
      getstats(controller,
             ::google::protobuf::down_cast<const ::example::HttpRequest*>(request),
             ::google::protobuf::down_cast< ::example::HttpResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& QueueService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpRequest::default_instance();
    case 1:
      return ::example::HttpRequest::default_instance();
    case 2:
      return ::example::HttpRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& QueueService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HttpResponse::default_instance();
    case 1:
      return ::example::HttpResponse::default_instance();
    case 2:
      return ::example::HttpResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

QueueService_Stub::QueueService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
QueueService_Stub::QueueService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
QueueService_Stub::~QueueService_Stub() {
  if (owns_channel_) delete channel_;
}

void QueueService_Stub::start(::google::protobuf::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}
void QueueService_Stub::stop(::google::protobuf::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(1),
                       controller, request, response, done);
}
void QueueService_Stub::getstats(::google::protobuf::RpcController* controller,
                              const ::example::HttpRequest* request,
                              ::example::HttpResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(2),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace example

// @@protoc_insertion_point(global_scope)
