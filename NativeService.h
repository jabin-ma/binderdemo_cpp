//
// Created by ubuntu on 2022/9/22.
//

#ifndef ANDROID_PERFMANAGER_H
#define ANDROID_PERFMANAGER_H

#endif //ANDROID_PERFMANAGER_H

#include <htzx/BnNativeService.h>

using htzx::BnNativeService;
using android::binder::Status;

class NativeService : public BnNativeService{

   public:
   NativeService();
   Status createSession(android::sp<htzx::INativeSession>* _aidl_return) override;
};