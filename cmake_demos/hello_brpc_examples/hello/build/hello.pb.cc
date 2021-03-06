// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: hello.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "hello.pb.h"

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

const ::google::protobuf::Descriptor* HelloRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HelloRequest_reflection_ = NULL;
const ::google::protobuf::Descriptor* HelloResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  HelloResponse_reflection_ = NULL;
const ::google::protobuf::ServiceDescriptor* HelloService_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_hello_2eproto() {
  protobuf_AddDesc_hello_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "hello.proto");
  GOOGLE_CHECK(file != NULL);
  HelloRequest_descriptor_ = file->message_type(0);
  static const int HelloRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloRequest, message_),
  };
  HelloRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HelloRequest_descriptor_,
      HelloRequest::default_instance_,
      HelloRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HelloRequest));
  HelloResponse_descriptor_ = file->message_type(1);
  static const int HelloResponse_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloResponse, message_),
  };
  HelloResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      HelloResponse_descriptor_,
      HelloResponse::default_instance_,
      HelloResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(HelloResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(HelloResponse));
  HelloService_descriptor_ = file->service(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_hello_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HelloRequest_descriptor_, &HelloRequest::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    HelloResponse_descriptor_, &HelloResponse::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_hello_2eproto() {
  delete HelloRequest::default_instance_;
  delete HelloRequest_reflection_;
  delete HelloResponse::default_instance_;
  delete HelloResponse_reflection_;
}

void protobuf_AddDesc_hello_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013hello.proto\022\007example\"\037\n\014HelloRequest\022\017"
    "\n\007message\030\001 \002(\t\" \n\rHelloResponse\022\017\n\007mess"
    "age\030\001 \002(\t2F\n\014HelloService\0226\n\005Hello\022\025.exa"
    "mple.HelloRequest\032\026.example.HelloRespons"
    "eB\003\200\001\001", 166);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "hello.proto", &protobuf_RegisterTypes);
  HelloRequest::default_instance_ = new HelloRequest();
  HelloResponse::default_instance_ = new HelloResponse();
  HelloRequest::default_instance_->InitAsDefaultInstance();
  HelloResponse::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_hello_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_hello_2eproto {
  StaticDescriptorInitializer_hello_2eproto() {
    protobuf_AddDesc_hello_2eproto();
  }
} static_descriptor_initializer_hello_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int HelloRequest::kMessageFieldNumber;
#endif  // !_MSC_VER

HelloRequest::HelloRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.HelloRequest)
}

void HelloRequest::InitAsDefaultInstance() {
}

HelloRequest::HelloRequest(const HelloRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:example.HelloRequest)
}

void HelloRequest::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HelloRequest::~HelloRequest() {
  // @@protoc_insertion_point(destructor:example.HelloRequest)
  SharedDtor();
}

void HelloRequest::SharedDtor() {
  if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete message_;
  }
  if (this != default_instance_) {
  }
}

void HelloRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HelloRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HelloRequest_descriptor_;
}

const HelloRequest& HelloRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_hello_2eproto();
  return *default_instance_;
}

HelloRequest* HelloRequest::default_instance_ = NULL;

HelloRequest* HelloRequest::New() const {
  return new HelloRequest;
}

void HelloRequest::Clear() {
  if (has_message()) {
    if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      message_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HelloRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:example.HelloRequest)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string message = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->message().data(), this->message().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "message");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:example.HelloRequest)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:example.HelloRequest)
  return false;
#undef DO_
}

void HelloRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:example.HelloRequest)
  // required string message = 1;
  if (has_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->message(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:example.HelloRequest)
}

::google::protobuf::uint8* HelloRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.HelloRequest)
  // required string message = 1;
  if (has_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->message(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.HelloRequest)
  return target;
}

int HelloRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string message = 1;
    if (has_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->message());
    }

  }
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

void HelloRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HelloRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HelloRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HelloRequest::MergeFrom(const HelloRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_message()) {
      set_message(from.message());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HelloRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HelloRequest::CopyFrom(const HelloRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HelloRequest::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void HelloRequest::Swap(HelloRequest* other) {
  if (other != this) {
    std::swap(message_, other->message_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HelloRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HelloRequest_descriptor_;
  metadata.reflection = HelloRequest_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int HelloResponse::kMessageFieldNumber;
#endif  // !_MSC_VER

HelloResponse::HelloResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:example.HelloResponse)
}

void HelloResponse::InitAsDefaultInstance() {
}

HelloResponse::HelloResponse(const HelloResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:example.HelloResponse)
}

void HelloResponse::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  message_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

HelloResponse::~HelloResponse() {
  // @@protoc_insertion_point(destructor:example.HelloResponse)
  SharedDtor();
}

void HelloResponse::SharedDtor() {
  if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete message_;
  }
  if (this != default_instance_) {
  }
}

void HelloResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* HelloResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HelloResponse_descriptor_;
}

const HelloResponse& HelloResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_hello_2eproto();
  return *default_instance_;
}

HelloResponse* HelloResponse::default_instance_ = NULL;

HelloResponse* HelloResponse::New() const {
  return new HelloResponse;
}

void HelloResponse::Clear() {
  if (has_message()) {
    if (message_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
      message_->clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool HelloResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:example.HelloResponse)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string message = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_message()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->message().data(), this->message().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "message");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:example.HelloResponse)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:example.HelloResponse)
  return false;
#undef DO_
}

void HelloResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:example.HelloResponse)
  // required string message = 1;
  if (has_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "message");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->message(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:example.HelloResponse)
}

::google::protobuf::uint8* HelloResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:example.HelloResponse)
  // required string message = 1;
  if (has_message()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->message().data(), this->message().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "message");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->message(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:example.HelloResponse)
  return target;
}

int HelloResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string message = 1;
    if (has_message()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->message());
    }

  }
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

void HelloResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const HelloResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const HelloResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void HelloResponse::MergeFrom(const HelloResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_message()) {
      set_message(from.message());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void HelloResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void HelloResponse::CopyFrom(const HelloResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HelloResponse::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void HelloResponse::Swap(HelloResponse* other) {
  if (other != this) {
    std::swap(message_, other->message_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata HelloResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = HelloResponse_descriptor_;
  metadata.reflection = HelloResponse_reflection_;
  return metadata;
}


// ===================================================================

HelloService::~HelloService() {}

const ::google::protobuf::ServiceDescriptor* HelloService::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return HelloService_descriptor_;
}

const ::google::protobuf::ServiceDescriptor* HelloService::GetDescriptor() {
  protobuf_AssignDescriptorsOnce();
  return HelloService_descriptor_;
}

void HelloService::Hello(::google::protobuf::RpcController* controller,
                         const ::example::HelloRequest*,
                         ::example::HelloResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method Hello() not implemented.");
  done->Run();
}

void HelloService::CallMethod(const ::google::protobuf::MethodDescriptor* method,
                             ::google::protobuf::RpcController* controller,
                             const ::google::protobuf::Message* request,
                             ::google::protobuf::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), HelloService_descriptor_);
  switch(method->index()) {
    case 0:
      Hello(controller,
             ::google::protobuf::down_cast<const ::example::HelloRequest*>(request),
             ::google::protobuf::down_cast< ::example::HelloResponse*>(response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::google::protobuf::Message& HelloService::GetRequestPrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HelloRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

const ::google::protobuf::Message& HelloService::GetResponsePrototype(
    const ::google::protobuf::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::example::HelloResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *reinterpret_cast< ::google::protobuf::Message*>(NULL);
  }
}

HelloService_Stub::HelloService_Stub(::google::protobuf::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
HelloService_Stub::HelloService_Stub(
    ::google::protobuf::RpcChannel* channel,
    ::google::protobuf::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::google::protobuf::Service::STUB_OWNS_CHANNEL) {}
HelloService_Stub::~HelloService_Stub() {
  if (owns_channel_) delete channel_;
}

void HelloService_Stub::Hello(::google::protobuf::RpcController* controller,
                              const ::example::HelloRequest* request,
                              ::example::HelloResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)

}  // namespace example

// @@protoc_insertion_point(global_scope)
