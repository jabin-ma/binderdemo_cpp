//
// Created by ubuntu on 2022/9/22.
//

#ifndef ANDROID_NATIVESESSION_H
#define ANDROID_NATIVESESSION_H

#endif //ANDROID_NATIVESESSION_H
#include <htzx/BnNativeSession.h>

using htzx::BnNativeSession;
using android::binder::Status;

class NativeSession : public BnNativeSession{

   public:
   NativeSession();
   Status sayMyName() override;
};