// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from tezos_like_wallet.djinni

#ifndef DJINNI_GENERATED_TEZOSOPERATIONTAG_HPP_JNI_
#define DJINNI_GENERATED_TEZOSOPERATIONTAG_HPP_JNI_

#include "../../api/TezosOperationTag.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class TezosOperationTag final : ::djinni::JniEnum {
public:
    using CppType = ::ledger::core::api::TezosOperationTag;
    using JniType = jobject;

    using Boxed = TezosOperationTag;

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return static_cast<CppType>(::djinni::JniClass<TezosOperationTag>::get().ordinal(jniEnv, j)); }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, CppType c) { return ::djinni::JniClass<TezosOperationTag>::get().create(jniEnv, static_cast<jint>(c)); }

private:
    TezosOperationTag() : JniEnum("co/ledger/core/TezosOperationTag") {}
    friend ::djinni::JniClass<TezosOperationTag>;
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_TEZOSOPERATIONTAG_HPP_JNI_