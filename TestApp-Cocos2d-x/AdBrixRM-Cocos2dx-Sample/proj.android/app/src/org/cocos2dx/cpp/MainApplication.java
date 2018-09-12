package org.cocos2dx.cpp;

import android.app.Application;
import android.os.Build;

import com.igaworks.v2.core.AdBrixRm;
import com.igaworks.v2.core.application.AbxActivityHelper;
import com.igaworks.v2.core.application.AbxActivityLifecycleCallbacks;

//public class MainApplication extends AbxApplication {
public class MainApplication extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
        AbxActivityHelper.initializeSdk(getApplicationContext(), "AppKey", "SecretKey");
        AdBrixRm.login("AdBrixRemasterAOSTest");

        AdBrixRm.setEnableLocationListening(true);
        if (Build.VERSION.SDK_INT >= 14) {
            registerActivityLifecycleCallbacks(new AbxActivityLifecycleCallbacks());
        }
        AdBrixRm.setCustomDeviceId("CustomDeviceId");
        AdBrixRm.setAge(30);
        AdBrixRm.setGender(AdBrixRm.AbxGender.MALE);
        AdBrixRm.setLogLevel(AdBrixRm.AdBrixLogLevel.ERROR);
        AdBrixRm.setEventUploadCountInterval(AdBrixRm.AdBrixEventUploadCountInterval.MIN);
        AdBrixRm.setEventUploadTimeInterval(AdBrixRm.AdBrixEventUploadTimeInterval.MIN);

    }
}
