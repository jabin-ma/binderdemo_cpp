//
// Created by ubuntu on 2022/9/22.
//

#include "NativeSession.h"
#include <utils/Log.h>

NativeSession::NativeSession(){

}

Status NativeSession::sayMyName(){
    ALOGD("I'm Session");
    return Status::ok();
  }
