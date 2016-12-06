//
// Created by majipeng on 12/5/16.
//

#ifndef ANDROID_MYSERVICE_H
#define ANDROID_MYSERVICE_H

#endif //ANDROID_MYSERVICE_H
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class IMyService : public IInterface{

public :

      enum {
        SAY= IBinder::FIRST_CALL_TRANSACTION + 0,
       };

       static const android::String16 descriptor;
       virtual const android::String16& getInterfaceDescriptor() const;
       IMyService() {}
       virtual ~IMyService() {}

       virtual int say()=0;
};


//server
class BnMyService : public BnInterface<IMyService>{

        virtual status_t onTransact( uint32_t code,
                                        const Parcel& data,
                                        Parcel* reply,
                                        uint32_t flags = 0);
   };
}//namespace android
