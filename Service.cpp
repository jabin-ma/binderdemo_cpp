//
// Created by majipeng on 12/5/16.
//
#define LOG_TAG "mjp"

#include <utils/Log.h>
#include <htzx/BnMyService.h>


#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>
#include <utils/String16.h>

using htzx::BnMyService;
using android::binder::Status;

class MyServiceProxy : public BnMyService{

   Status say(int32_t* _aidl_return) override {
    *_aidl_return = 2016;
     ALOGD("c++.say()");
    return Status::ok();
  }
 };

int main(int , char* []) {
    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    android::sp<MyServiceProxy> proxy = new MyServiceProxy();
    android::status_t ret = sm->addService(
            android::String16("com.android.majipeng.IMyService"), proxy);//register to SM
    if (ret != android::OK) {//
        ALOGE("Couldn't register binder service!");
        return -1;
    }
    /*
     * single thread
     */
    android::IPCThreadState::self()->joinThreadPool();
    return 0;
}
