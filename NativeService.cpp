//
// Created by ubuntu on 2022/9/22.
//

#include "NativeService.h"
#include "NativeSession.h"
#include <utils/Log.h>
NativeService::NativeService(){

}

Status NativeService::createSession(android::sp<htzx::INativeSession>* _aidl_return){
        ALOGD("createSession");
        *_aidl_return = android::sp<NativeSession>::make();
        return Status::ok();
}
