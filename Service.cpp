//
// Created by majipeng on 12/5/16.
//
#define LOG_TAG "mjp"

#include <utils/Log.h>
#include "MyService.h"


#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>
#include <utils/String16.h>
namespace android {

class MyServiceProxy : public BnMyService{

    int say(){
     ALOGD("c++.say()");
    return 2016;
    }
 };
}

int main(int , char* []) {
    android::sp<android::IServiceManager> sm = android::defaultServiceManager();
    android::sp<android::MyServiceProxy> proxy = new android::MyServiceProxy();
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