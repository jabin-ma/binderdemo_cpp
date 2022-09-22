//
// Created by majipeng on 12/5/16.
//

#include <utils/Log.h>
#include <htzx/BnNativeService.h>


#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/PermissionCache.h>
#include <utils/String16.h>
#include "NativeService.h"

using namespace android;

int main(int , char* []) {
    ProcessState::self()->startThreadPool();
    
    sp<NativeService> proxy = new NativeService();
    status_t ret = defaultServiceManager()->addService(String16("com.android.majipeng.IMyService"), proxy);//register to SM
    if (ret != android::OK) {//
        ALOGE("Couldn't register binder service!");
        return -1;
    }

    IPCThreadState::self()->joinThreadPool();
    return 0;
}
