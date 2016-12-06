//
// Created by majipeng on 12/5/16.
//
#define LOG_TAG "mjp"
#include "MyService.h"
#include <utils/Log.h>

namespace android {

const android::String16 IMyService::descriptor("com.android.majipeng.IMyService");
const android::String16& IMyService::getInterfaceDescriptor() const {
    return IMyService::descriptor;
}

status_t  BnMyService::onTransact( uint32_t code,const Parcel& data,Parcel* reply,uint32_t flags)
    {
          ALOGD("onTransact %d",code);
          switch (code)
          {
                case SAY:
                {
                 CHECK_INTERFACE(IMyService,data,reply);
                 int result=say();
                 reply->writeNoException();
                 reply->writeInt32(result);
                 return NO_ERROR;
                }
                default:
                 return BBinder::onTransact(code, data, reply, flags);
          }
           return NO_ERROR;
     };
}//namespace android
