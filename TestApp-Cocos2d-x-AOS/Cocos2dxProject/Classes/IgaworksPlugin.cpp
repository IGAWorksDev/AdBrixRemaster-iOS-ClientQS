#include "IgaworksPlugin.h"
#include <map>
#include <string>


//USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <jni.h>
#include <android/log.h>
#include "platform/android/jni/JniHelper.h"

#define  LOG_TAG    "IGAW_COCOS2DX"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

#define  IGAW_ADBRIX_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawAdbrixCocos2dxPlugin"
#define  IGAW_ADPOPCORN_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawAdpopcornCocos2dxPlugin"
#define  IGAW_COMMON_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawCommonCocos2dxPlugin"
#define  IGAW_COUPON_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawCouponCocos2dxPlugin"
#define  IGAW_DISPLAYAD_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawDisplayAdCocos2dxPlugin"
#define  IGAW_LIVEOPS_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawLiveOpsCocos2dxPlugin"
#define  IGAW_PROMOTION_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawPromotionCocos2dxPlugin"
#define	 IGAW_NANOO_PLUGIN_CLASS_NAME "com/igaworks/plugin/cocos2dx/IgawNanooCocos2dxPlugin"

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#else
#define LOGD(...)

#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

typedef struct JniMethodInfo_
{
    JNIEnv *    env;
    jclass      classId;
    jmethodID   methodId;
} JniMethodInfo;

extern "C"
{
	static JNIEnv* getJNIEnv(void) {
		JavaVM* jvm = cocos2d::JniHelper::getJavaVM();
		if (NULL == jvm) {
			LOGD("Failed to get JNIEnv. JniHelper::getJavaVM() is NULL");
			return NULL;
		}

		JNIEnv *env = NULL;
		jint ret = jvm->GetEnv((void**)&env, JNI_VERSION_1_4);

		switch (ret) {
			case JNI_OK :
				return env;

			case JNI_EDETACHED :
				if (jvm->AttachCurrentThread(&env, NULL) < 0)
				{
					LOGD("Failed to get the environment using AttachCurrentThread()");
					return NULL;
				} else {
					return env;
				}

			case JNI_EVERSION :
				LOGD("JNI interface version 1.4 not supported");
			default :
				LOGD("Failed to get the environment using GetEnv()");
				return NULL;
		}
	}

	static bool getStaticMethodInfo(JniMethodInfo &methodinfo, const char *methodName, const char *methodSignature, int sdkType) {
		JNIEnv *pEnv = getJNIEnv();
	    if (!pEnv) {
	        return false;
	    }

	    jclass classId;

	    if(sdkType == ADBRIX_SDK){
	    	classId = pEnv->FindClass(IGAW_ADBRIX_PLUGIN_CLASS_NAME);
	    	if (!classId) {
				LOGD("Failed to find class of %s", IGAW_ADBRIX_PLUGIN_CLASS_NAME);
				return false;
			}
	    }
	    else if(sdkType == ADPOPCORN_SDK){
			classId = pEnv->FindClass(IGAW_ADPOPCORN_PLUGIN_CLASS_NAME);
			if (!classId) {
				LOGD("Failed to find class of %s", IGAW_ADPOPCORN_PLUGIN_CLASS_NAME);
				return false;
			}
		}
	    else if(sdkType == COMMON_SDK){
			classId = pEnv->FindClass(IGAW_COMMON_PLUGIN_CLASS_NAME);
			if (!class
				LOGD("Failed to find class of %s", IGAW_COMMON_PLUGIN_CLASS_NAME);
				return false;
			}
		}
	    else if(sdkType == COUPON_SDK){
			classId = pEnv->FindClass(IGAW_COUPON_PLUGIN_CLASS_NAME);
			if (!classId) {
				LOGD("Failed to find class of %s", IGAW_COUPON_PLUGIN_CLASS_NAME);
				return false;
			}
		}
	    else if(sdkType == DISPLAY_SDK){
			classId = pEnv->FindClass(IGAW_DISPLAYAD_PLUGIN_CLASS_NAME);
			if (!classId) {
				LOGD("Failed to find class of %s", IGAW_DISPLAYAD_PLUGIN_CLASS_NAME);
				return false;
			}
		}
	    else if(sdkType == LIVEOPS_SDK){
	    	classId = pEnv->FindClass(IGAW_LIVEOPS_PLUGIN_CLASS_NAME);
	    	if (!classId) {
				LOGD("Failed to find class of %s", IGAW_LIVEOPS_PLUGIN_CLASS_NAME);
				return false;
			}
	    }
		else if(sdkType == NANOO_SDK){
			classId = pEnv->FindClass(IGAW_NANOO_PLUGIN_CLASS_NAME);
	    	if (!classId) {
				LOGD("Failed to find class of %s", IGAW_NANOO_PLUGIN_CLASS_NAME);
				return false;
			}
		}
	    else if(sdkType == PROMOTION_SDK){
	    	classId = pEnv->FindClass(IGAW_PROMOTION_PLUGIN_CLASS_NAME);
	    	if (!classId) {
				LOGD("Failed to find class of %s", IGAW_PROMOTION_PLUGIN_CLASS_NAME);
				return false;
			}
	    }

		jmethodID methodId = pEnv->GetStaticMethodID(classId, methodName, methodSignature);
		if (!methodId) {
			LOGD("Failed to find static method id of %s", methodName);
			pEnv->DeleteLocalRef(classId);
			return false;
		}

		methodinfo.env = pEnv;
		methodinfo.classId = classId;
		methodinfo.methodId = methodId;

		return true;
	}

	static void callStaticMethod(const char*methodName, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "()V", sdkType)) {
			return;
		}

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodWithStringParam(const char*methodName, const char* param, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;)V", sdkType)) {
			return;
		}

		jstring paramName = methodInfo.env->NewStringUTF(param);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName);
		methodInfo.env->DeleteLocalRef(paramName);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodWithStringStringParam(const char*methodName, const char* param1, const char* param2, int sdkType) {
			JniMethodInfo methodInfo;

			if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;Ljava/lang/String;)V", sdkType)) {
				return;
			}

			jstring paramName1 = methodInfo.env->NewStringUTF(param1);
			jstring paramName2 = methodInfo.env->NewStringUTF(param2);

			methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName1, paramName2);
			methodInfo.env->DeleteLocalRef(paramName1);
			methodInfo.env->DeleteLocalRef(paramName2);
			methodInfo.env->DeleteLocalRef(methodInfo.classId);
		}

	static void callStaticMethodWithStringIntParam(const char*methodName, const char* param1, int param2, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;I)V", sdkType)) {
			return;
		}

		jstring paramName1 = methodInfo.env->NewStringUTF(param1);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName1, param2);
		methodInfo.env->DeleteLocalRef(paramName1);
		
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodWithIntParam(const char*methodName, int param, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(I)V", sdkType)) {
			return;
		}

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodWithIntStringParam(const char*methodName, int param, const char* param2, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(ILjava/lang/String;)V", sdkType)) {
			return;
		}


		jstring paramName2 = methodInfo.env->NewStringUTF(param2);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param, paramName2);
		methodInfo.env->DeleteLocalRef(paramName2);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}


	static void callStaticMethodWithBooleanParam(const char*methodName, bool param, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Z)V", sdkType)) {
			return;
		}

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodWithBooleanBooleanParam(const char*methodName, bool param1, bool param2, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(ZZ)V", sdkType)) {
			return;
		}

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param1, param2);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodWithDoubleDoubleParam(const char*methodName, double param1, double param2, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(DD)V", sdkType)) {
			return;
		}

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param1, param2);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	static void callStaticMethodForSetTargetIntData(const char*methodName, const char* userGroup, int userData, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;I)V", sdkType)) {
			return;
		}
		
		jstring juserGroup = methodInfo.env->NewStringUTF(userGroup);
		
		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, juserGroup, userData);
		methodInfo.env->DeleteLocalRef(juserGroup);
		
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	static void callStaticMethodForSetTargetLongData(const char*methodName, const char* userGroup, long userData, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;J)V", sdkType)) {
			return;
		}
		
		jstring juserGroup = methodInfo.env->NewStringUTF(userGroup);
		jlong   juserData = (jlong)userData;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, juserGroup, juserData);
		methodInfo.env->DeleteLocalRef(juserGroup);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	static void callStaticMethodForSetTargetFloatData(const char*methodName, const char* userGroup, float userData, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;F)V", sdkType)) {
			return;
		}
		
		jstring juserGroup = methodInfo.env->NewStringUTF(userGroup);
		jfloat juserData = (jfloat)userData;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, juserGroup, juserData);
		methodInfo.env->DeleteLocalRef(juserGroup);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	static void callStaticMethodForSetTargetBoolData(const char*methodName, const char* userGroup, bool userData, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;Z)V", sdkType)) {
			return;
		}
		
		jstring juserGroup = methodInfo.env->NewStringUTF(userGroup);
		
		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, juserGroup, userData);
		methodInfo.env->DeleteLocalRef(juserGroup);
		
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	static void callStaticMethodForSetNormalClientPushEvent(const char*methodName, long second, const char* contentText, int eventId, bool alwaysIsShown, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(JLjava/lang/String;IZ)V", sdkType)) {
			return;
		}

		jstring paramName1 = methodInfo.env->NewStringUTF(contentText);
		jlong jsecond = (jlong)second;

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, jsecond, paramName1, eventId, alwaysIsShown);
		methodInfo.env->DeleteLocalRef(paramName1);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodForSetBigTextClientPushEvent(const char*methodName, long second, const char* contentText, const char* bigContentTitle, const char* bigText, const char* summaryText, int eventId, bool alwaysIsShown, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(JLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;IZ)V", sdkType)) {
			return;
		}

		jstring paramName1 = methodInfo.env->NewStringUTF(contentText);
		jstring paramName2 = methodInfo.env->NewStringUTF(bigContentTitle);
		jstring paramName3 = methodInfo.env->NewStringUTF(bigText);
		jstring paramName4 = methodInfo.env->NewStringUTF(summaryText);
		jlong jsecond = (jlong)second;

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, jsecond, paramName1, paramName2, paramName3, paramName4, eventId, alwaysIsShown);
		methodInfo.env->DeleteLocalRef(paramName1);
		methodInfo.env->DeleteLocalRef(paramName2);
		methodInfo.env->DeleteLocalRef(paramName3);
		methodInfo.env->DeleteLocalRef(paramName4);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	static void callStaticMethodForCommcerceV2Purchase(const char*methodName, const char *productID, double price, int currency, int paymentMethod, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;DII)V", sdkType)) {
			return;
		}

		jstring paramName1 = methodInfo.env->NewStringUTF(productID);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName1, price, currency, paymentMethod);
		methodInfo.env->DeleteLocalRef(paramName1);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

	
	static void callStaticMethodForCommcerceV2PurchaseII(const char*methodName, const char *orderID, const char *purchaseDetail, double discount, double deliveryCharge, int paymentMethod, int sdkType)
	{
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;Ljava/lang/String;DDI)V", sdkType)) {
			return;
		}

		jstring paramName1 = methodInfo.env->NewStringUTF(orderID);
		jstring paramName2 = methodInfo.env->NewStringUTF(purchaseDetail);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName1, paramName2, discount, deliveryCharge, paymentMethod);
		methodInfo.env->DeleteLocalRef(paramName1);
		methodInfo.env->DeleteLocalRef(paramName2);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	

	void Java_com_igaworks_plugin_cocos2dx_IgaworksCocos2dxPlugin_sendCallbackMessageType1(JNIEnv *env, jobject thisObj, jint methodId, jstring param) {
		const char *pname = env->GetStringUTFChars(param, NULL);

		IgaworksCocos2dxCallbackListener *handler = IgaworksPlugin::getCallbackListener();

		if (handler != NULL) {
			switch(methodId) {
			// Adpopcorn
			case 1: // OnClosedOfferWallPage
				handler->OnClosedOfferWallPage();
				break;
			// Common
			case 2: // OnDidGiveRewardItemResult
				handler->OnDidGiveRewardItemResult(pname);
				break;
		//	case 3: // OnGetRewardInfo
		//		handler->OnGetRewardInfo(pname);
		//		break;
			// Coupon
			case 4: // OnSendCouponSucceed
				handler->OnSendCouponSucceed(pname);
				break;
			case 5: // OnSendCouponFailed
				handler->OnSendCouponFailed(pname);
				break;
			// Display AD
			case 6: // OnInterstitialReceiveSuccess
				handler->OnInterstitialReceiveSuccess();
				break;
		//	case 7: // OnInterstitialReceiveFailed
		//		handler->OnInterstitialReceiveFailed(pname);
		//		break;
			case 8: // OnInterstitialClosed
				handler->OnInterstitialClosed();
				break;
			case 9: // OnPopupAdReceiveSuccess
				handler->OnPopupAdReceiveSuccess();
				break;
		//	case 10: // OnPopupAdReceiveFailed
		//		handler->OnPopupAdReceiveFailed(pname);
		//		break;
			case 11: // OnPopupAdClosed
				handler->OnPopupAdClosed();
				break;
			case 12: // OnNativeAdRequestSucceeded
				handler->OnNativeAdRequestSucceeded(pname);
				break;
		//	case 13: // OnNativeAdRequestFailed
		//		handler->OnPopupAdClosed();
		//		break;
			// LiveOps
			//case 14: // OnLiveOpsNotification
				//handler->OnLiveOpsNotification(pname);
				//break;
			// Promotion
			case 15: // OnPlayBtnClickListener
				handler->OnPlayBtnClickListener();
				break;
			case 16: //Nanoo >> OnOpenFanPageListener
				handler->OnOpenFanPageListener(pname);
				break;
			case 17: //LiveOps Popup >> OnLiveOpsDeepLinkEventListener
				handler->OnLiveOpsDeepLinkEventListener(pname);
				break;
			case 18:
				handler->OnSuccessLiveOpsPopupResourceEventListener();
				break;
			case 19:
				handler->OnFailLiveOpsPopupResourceEventListener();
				break;
			case 20:
				handler->OnRegistrationIdEventListener(pname);
				break;
			case 21:
				handler->OnSuccessLiveOpsGCMPushEnableEventListener();
				break;
			case 22:
				handler->OnFailLiveOpsGCMPushEnableEventListener();
				break;
			case 23:
				handler->OnLiveOpsPopupClick();
				break;
			case 24:
				handler->OnLiveOpsCancelPopupBtnClick();
				break;
			}
		}

		env->ReleaseStringUTFChars(param, pname);
	}

	void Java_com_igaworks_plugin_cocos2dx_IgaworksCocos2dxPlugin_sendCallbackMessageType2(JNIEnv *env, jobject thisObj, jint methodId,
		jint code, jstring message) {
		const char *pmessage = env->GetStringUTFChars(message, NULL);

		IgaworksCocos2dxCallbackListener *handler = IgaworksPlugin::getCallbackListener();

		if (handler != NULL) {
			switch(methodId) {
			// Display AD
			case 7: // OnInterstitialReceiveFailed
				handler->OnInterstitialReceiveFailed(code, pmessage);
				break;
			case 10: // OnPopupAdReceiveFailed
				handler->OnPopupAdReceiveFailed(code, pmessage);
				break;
			// Native AD
			case 13: // OnNativeAdRequestFailed
				handler->OnNativeAdRequestFailed(code, pmessage);
				break;
			}
		}
		env->ReleaseStringUTFChars(message, pmessage);
	}

	void Java_com_igaworks_plugin_cocos2dx_IgaworksCocos2dxPlugin_sendCallbackMessageType3(JNIEnv *env, jobject thisObj, jint methodId, bool arg0) {
		IgaworksCocos2dxCallbackListener *handler = IgaworksPlugin::getCallbackListener();

		if (handler != NULL) {
			switch(methodId) {
			// Display AD
			case 16: // OnBtnClickListener
				handler->OnBtnClickListener(arg0);
				break;
			}
		}
	}

	void Java_com_igaworks_plugin_cocos2dx_IgaworksCocos2dxPlugin_sendRewardCallbackMessage(JNIEnv *env, jobject thisObj,
		jstring campaignKey, jstring campaignName, jstring quantity, jstring cv, jstring rewardKey) {
		const char *pcampaignKey = env->GetStringUTFChars(campaignKey, NULL);
		const char *pcampaignName = env->GetStringUTFChars(campaignName, NULL);
		const char *pquantity = env->GetStringUTFChars(quantity, NULL);
		const char *pcv = env->GetStringUTFChars(cv, NULL);
		const char *prewardKey = env->GetStringUTFChars(rewardKey, NULL);

		IgaworksCocos2dxCallbackListener *handler = IgaworksPlugin::getCallbackListener();

		if (handler != NULL) {
	//		switch(methodId) {
	//		case 3: // OnGetRewardInfo
				handler->OnGetRewardInfo(pcampaignKey, pcampaignName, pquantity, pcv, prewardKey);
	//			break;
	//		}
		}

		env->ReleaseStringUTFChars(campaignKey, pcampaignKey);
		env->ReleaseStringUTFChars(campaignName, pcampaignName);
		env->ReleaseStringUTFChars(quantity, pquantity);
		env->ReleaseStringUTFChars(cv, pcv);
		env->ReleaseStringUTFChars(rewardKey, prewardKey);
	}
} // extern "C"

// ADPOPCORN API
void IgaworksPlugin::openOfferwall() {
	callStaticMethod("openOfferwall", ADPOPCORN_SDK);
}

void IgaworksPlugin::setSensorLandscapeEnable(bool flag) {
	callStaticMethodWithBooleanParam("setSensorLandscapeEnable", flag, ADPOPCORN_SDK);
}

void IgaworksPlugin::openBanner(const char* campaignKey) {
	callStaticMethodWithStringParam("openBanner", campaignKey, ADPOPCORN_SDK);
}

void IgaworksPlugin::openPromotionEvent() {
	callStaticMethod("openPromotionEvent", ADPOPCORN_SDK);
}

void IgaworksPlugin::getClientPendingRewardItems() {
	callStaticMethod("getClientPendingRewardItems", ADPOPCORN_SDK);
}

void IgaworksPlugin::didGiveRewardItem(const char* cv, const char* rewardKey) {
	callStaticMethodWithStringStringParam("didGiveRewardItem", cv, rewardKey, ADPOPCORN_SDK);
}

// COMMON API
void IgaworksPlugin::startApplication() {
	//callStaticMethod("startApplication", COMMON_SDK);
}

void IgaworksPlugin::startSession() {
	callStaticMethod("startSession", COMMON_SDK);
}

void IgaworksPlugin::endSession() {
	callStaticMethod("endSession", COMMON_SDK);
}

void IgaworksPlugin::setUserId(const char* userId) {
	callStaticMethodWithStringParam("setUserId", userId, COMMON_SDK);
}

void IgaworksPlugin::setClientRewardEventListener() {
	callStaticMethod("setClientRewardEventListener", COMMON_SDK);
}

// DISPLAY AD API
void IgaworksPlugin::initDisplayAd() {
	callStaticMethod("initDisplayAd", DISPLAY_SDK);
}

void IgaworksPlugin::initDisplayAd(bool isTestMode, bool enableDetailLog) {
	callStaticMethodWithBooleanBooleanParam("initDisplayAd", isTestMode, enableDetailLog, DISPLAY_SDK);
}

void IgaworksPlugin::destroy() {
	callStaticMethod("destroy", DISPLAY_SDK);
}

void IgaworksPlugin::showInterstitialAd(const char* spotKey) {
	callStaticMethodWithStringParam("showInterstitialAd", spotKey, DISPLAY_SDK);
}

void IgaworksPlugin::loadEndingAd(const char* spotKey) {
	callStaticMethodWithStringParam("loadEndingAd", spotKey, DISPLAY_SDK);
}

void IgaworksPlugin::showEndingAd(const char* spotKey) {
	callStaticMethodWithStringParam("showEndingAd", spotKey, DISPLAY_SDK);
}

void IgaworksPlugin::showPopupAd(const char* spotKey) {
	callStaticMethodWithStringParam("showPopupAd", spotKey, DISPLAY_SDK);
}

void IgaworksPlugin::setRefreshTime(int seconds) {
	callStaticMethodWithIntParam("setRefreshTime", seconds, DISPLAY_SDK);
}

void IgaworksPlugin::setLocation(double latitude, double longitude) {
	callStaticMethodWithDoubleDoubleParam("setLocation", latitude, longitude, DISPLAY_SDK);
}

void IgaworksPlugin::loadNativeAd(const char* spotKey){
	callStaticMethodWithStringParam("loadNativeAd", spotKey, DISPLAY_SDK);
}

void IgaworksPlugin::destroyNativeAd(){
	callStaticMethod("destroyNativeAd", DISPLAY_SDK);
}

void IgaworksPlugin::impressionAction(){
	callStaticMethod("impressionAction", DISPLAY_SDK);
}

void IgaworksPlugin::clickAction(){
	callStaticMethod("clickAction", DISPLAY_SDK);
}

void IgaworksPlugin::setEndingAdEventCallbackListener(const char* spotKey){
	callStaticMethodWithStringParam("setEndingAdEventCallbackListener", spotKey, DISPLAY_SDK);
}

// ADBRIX API
void IgaworksPlugin::setAge(int age){
	callStaticMethodWithIntParam("setAge", age, ADBRIX_SDK);
}
void IgaworksPlugin::setGender(int gender){
	callStaticMethodWithIntParam("setGender", gender, ADBRIX_SDK);
}
void IgaworksPlugin::firstTimeExperience(const char* name){
	callStaticMethodWithStringParam("firstTimeExperience", name, ADBRIX_SDK);
}
void IgaworksPlugin::retention(const char* name){
	callStaticMethodWithStringParam("retention", name, ADBRIX_SDK);
}
void IgaworksPlugin::retention(const char* name, const char* param){
	callStaticMethodWithStringStringParam("retention", name, param, ADBRIX_SDK);
}
void IgaworksPlugin::buy(const char* name){
	callStaticMethodWithStringParam("buy", name, ADBRIX_SDK);
}
void IgaworksPlugin::setCustomCohort(int cohortVar, const char* value)
{
	callStaticMethodWithIntStringParam("setCustomCohort", cohortVar, value, ADBRIX_SDK);
}
void IgaworksPlugin::purchase(const char * productID, double price, int currency, int paymentMethod) {
	callStaticMethodForCommcerceV2Purchase("purchase", productID, price, currency, paymentMethod, ADBRIX_SDK);
}
void IgaworksPlugin::purchase(const char * orderID, const char * purchaseDetail, double discount, double deliveryCharge, int paymentMethod)
{
	callStaticMethodForCommcerceV2PurchaseII("purchase", orderID, purchaseDetail, discount, deliveryCharge, paymentMethod, ADBRIX_SDK);
}
// COUPON API
void IgaworksPlugin::showCouponDialog(bool showResultMsgToast){
	callStaticMethodWithBooleanParam("showCouponDialog", showResultMsgToast, COUPON_SDK);
}
void IgaworksPlugin::checkCoupon(const char* couponText){
	callStaticMethodWithStringParam("checkCoupon", couponText, COUPON_SDK);
}

// NANOO API
void IgaworksPlugin::openFanPage(bool openAutomatically){
	callStaticMethodWithBooleanParam("openFanPage", openAutomatically, NANOO_SDK);
}

// LIVEOPS API
void IgaworksPlugin::initializeLiveOps(){
	callStaticMethod("initializeLiveOps", LIVEOPS_SDK);
}
void IgaworksPlugin::initializeLiveOps(const char* senderIDs){	
	callStaticMethodWithStringParam("initializeLiveOps", senderIDs, LIVEOPS_SDK);
}
void IgaworksPlugin::registerFCMToken(const char* refreshedToken) {
	callStaticMethodWithStringParam("registerFCMToken", refreshedToken, LIVEOPS_SDK);
}
void IgaworksPlugin::resumeLiveOps(){
	callStaticMethod("resumeLiveOps", LIVEOPS_SDK);
}
//void IgaworksPlugin::setLiveOpsNotificationCallback(){
//	callStaticMethod("setLiveOpsNotificationCallback", LIVEOPS_SDK);
//}
void IgaworksPlugin::setTargetingData(const char* userGroup, const char* userData){
	callStaticMethodWithStringStringParam("setTargetingData", userGroup, userData, LIVEOPS_SDK);
}
void IgaworksPlugin::setTargetingData(const char* userGroup, int userData){
	callStaticMethodForSetTargetIntData("setTargetingData", userGroup, userData, LIVEOPS_SDK);
}
void IgaworksPlugin::setTargetingData(const char* userGroup, long userData){
	callStaticMethodForSetTargetLongData("setTargetingData", userGroup, userData, LIVEOPS_SDK);
}
void IgaworksPlugin::setTargetingData(const char* userGroup, float userData){
	callStaticMethodForSetTargetFloatData("setTargetingData", userGroup, userData, LIVEOPS_SDK);
}
void IgaworksPlugin::setTargetingData(const char* userGroup, bool userData){
	callStaticMethodForSetTargetBoolData("setTargetingData", userGroup, userData, LIVEOPS_SDK);
}
void IgaworksPlugin::setNormalClientPushEvent(long second, const char* contentText, int eventId, bool alwaysIsShown){
	callStaticMethodForSetNormalClientPushEvent("setNormalClientPushEvent", second, contentText, eventId, alwaysIsShown, LIVEOPS_SDK);
}
void IgaworksPlugin::setBigTextClientPushEvent(long second, const char* contentText, const char* bigContentTitle, const char* bigText, const char* summaryText, int eventId, bool alwaysIsShown){
	callStaticMethodForSetBigTextClientPushEvent("setBigTextClientPushEvent", second, contentText, bigContentTitle, bigText, summaryText, eventId, alwaysIsShown, LIVEOPS_SDK);
}
void IgaworksPlugin::enableService(bool enable){
	callStaticMethodWithBooleanParam("enableService", enable, LIVEOPS_SDK);
}
void IgaworksPlugin::enableServiceWithCallback(bool enable){
	callStaticMethodWithBooleanParam("enableServiceWithCallback", enable, LIVEOPS_SDK);
}
void IgaworksPlugin::cancelClientPushEvent(int eventId){
	callStaticMethodWithIntParam("cancelClientPushEvent", eventId, LIVEOPS_SDK);
}
void IgaworksPlugin::setNotificationIconName(const char* notificationIconName){
	callStaticMethodWithStringParam("setNotificationIconName", notificationIconName, LIVEOPS_SDK);
}
void IgaworksPlugin::showPopUp(const char* spaceKey){
	callStaticMethodWithStringParam("showPopUp", spaceKey, LIVEOPS_SDK);
}
void IgaworksPlugin::requestPopupResource(){
	callStaticMethod("requestPopupResource", LIVEOPS_SDK);
}
void IgaworksPlugin::destroyPopup(){
	callStaticMethod("destroyPopup", LIVEOPS_SDK);
}
void IgaworksPlugin::destroyAllPopups(){
	callStaticMethod("destroyAllPopups", LIVEOPS_SDK);
}
void IgaworksPlugin::flush(){
	callStaticMethod("flush", LIVEOPS_SDK);
}
void IgaworksPlugin::setLiveOpsPopupEventListener(){
	callStaticMethod("setLiveOpsPopupEventListener", LIVEOPS_SDK);
}


// PROMOTION API
void IgaworksPlugin::showAD(const char* name){
	callStaticMethodWithStringParam("showAD", name, PROMOTION_SDK);
}
void IgaworksPlugin::hideAD(){
	callStaticMethod("hideAD", PROMOTION_SDK);
}

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
}

#else

#endif

IgaworksCocos2dxCallbackListener *IgaworksPlugin::callbackListener = NULL;

void IgaworksPlugin::setCallbackListener(IgaworksCocos2dxCallbackListener *listener) {
	callbackListener = listener;
}

IgaworksCocos2dxCallbackListener *IgaworksPlugin::getCallbackListener() {
	return callbackListener;
}

AdBrixCommerceProductAttrModel::AdBrixCommerceProductAttrModel(std::map<std::string, std::string> attrData)
{
	int count = 0;

	for (int i = 0; i < 5; i++)
	{
		this->Key[i] = NULL;
		this->Value[i] = NULL;
	}

	for (const auto& kv : attrData)

	{
		this->Key[count] = kv.first.c_str();
		this->Value[count] = kv.second.c_str();
		count++;
	}
}

AdBrixCommerceProductAttrModel* AdBrixCommerceProductAttrModel::create(std::map<std::string, std::string> attrData)
{
	AdBrixCommerceProductAttrModel *pObj = new AdBrixCommerceProductAttrModel(attrData);
	return pObj;
}

const char* AdBrixCommerceProductAttrModel::getValue(int pIndex)
{
	return Value[pIndex];
}

const char* AdBrixCommerceProductAttrModel::getKey(int pIndex)
{
	return Key[pIndex];
}

AdBrixCommerceProductCategoryModel * AdBrixCommerceProductCategoryModel::create(std::string category1)
{
	AdBrixCommerceProductCategoryModel *pObj = new AdBrixCommerceProductCategoryModel();
	pObj->category1 = category1;
	pObj->category2 = "";
	pObj->category3 = "";
	pObj->category4 = "";
	pObj->category5 = "";
	pObj->categoryFullString = pObj->category1;

	return pObj;
}

AdBrixCommerceProductCategoryModel * AdBrixCommerceProductCategoryModel::create(std::string category1, std::string category2)
{
	AdBrixCommerceProductCategoryModel *pObj = new AdBrixCommerceProductCategoryModel();
	pObj->category1 = category1;
	pObj->category2 = category2;
	pObj->category3 = "";
	pObj->category4 = "";
	pObj->category5 = "";
	pObj->categoryFullString = pObj->category1 + "." + pObj->category2;
	
	return pObj;
}

AdBrixCommerceProductCategoryModel * AdBrixCommerceProductCategoryModel::create(std::string category1, std::string category2, std::string category3)
{
	AdBrixCommerceProductCategoryModel *pObj = new AdBrixCommerceProductCategoryModel();
	pObj->category1 = category1;
	pObj->category2 = category2;
	pObj->category3 = category3;
	pObj->category4 = "";
	pObj->category5 = "";
	pObj->categoryFullString = pObj->category1 + "." + pObj->category2 + "." + pObj->category3;

	return pObj;
}

AdBrixCommerceProductCategoryModel * AdBrixCommerceProductCategoryModel::create(std::string category1, std::string category2, std::string category3, std::string category4)
{
	AdBrixCommerceProductCategoryModel *pObj = new AdBrixCommerceProductCategoryModel();
	pObj->category1 = category1;
	pObj->category2 = category2;
	pObj->category3 = category3;
	pObj->category4 = category4;
	pObj->category5 = "";
	pObj->categoryFullString = pObj->category1 + "." + pObj->category2 + "." + pObj->category3 + "." + pObj->category4;

	return pObj;
}

AdBrixCommerceProductCategoryModel * AdBrixCommerceProductCategoryModel::create(std::string category1, std::string category2, std::string category3, std::string category4, std::string category5)
{
	AdBrixCommerceProductCategoryModel *pObj = new AdBrixCommerceProductCategoryModel();
	pObj->category1 = category1;
	pObj->category2 = category2;
	pObj->category3 = category3;
	pObj->category4 = category4;
	pObj->category5 = category5;
	pObj->categoryFullString = pObj->category1 + "." + pObj->category2 + "." + pObj->category3 + "." + pObj->category4 + "." + pObj->category5;

	return pObj;
}

//AdBrixCommerceProductModel::AdBrixCommerceProductModel(std::string productId, 
//	std::string productName, 
//	double price, 
//	double discount, 
//	int quantity, 
//	int currencyString, 
//	AdBrixCommerceProductCategoryModel *category, 
//	AdBrixCommerceProductAttrModel *extraAttrs)
//{
//	_productID = productId;
//	_productName = productName;
//	_price = price;
//	_discount = discount;
//	_quantity = quantity;
//	_currencyString = currencyString;
//	_category = category->categoryFullString;
//}

std::string AdBrixCommerceProductModel::create(const char* productId, const char* productName, double price, double discount, int quantity, int currencyString, AdBrixCommerceProductCategoryModel* category, AdBrixCommerceProductAttrModel *extraAttrs)
{	
	std::string jsonString;
	std::string extra_attrs[5];
	std::string total_extra_attrs;
	for (int i = 0; i < 5; i++)
	{
		if (extraAttrs->getKey(i) != NULL && extraAttrs->getValue(i) != NULL)
		{
			if(i != 4)extra_attrs[i] = cocos2d::StringUtils::format("\"%s\": \"%s\", ", extraAttrs->getKey(i), extraAttrs->getValue(i));
			else extra_attrs[i] = cocos2d::StringUtils::format("\"%s\": \"%s\"", extraAttrs->getKey(i), extraAttrs->getValue(i));
		}
		else
		{
			extra_attrs[i] = "";
		}
	}

	total_extra_attrs = cocos2d::StringUtils::format("{%s %s %s %s %s}", extra_attrs[0].c_str(), extra_attrs[1].c_str(), extra_attrs[2].c_str(), extra_attrs[3].c_str(), extra_attrs[4].c_str());
	
	jsonString = cocos2d::StringUtils::format("{\"productId\": \"%s\", \"productName\": \"%s\", \"price\": %g, \"currency\": \"%d\", \"discount\": %g, \"quantity\": %d, \"category\": \"%s\", \"extra_attrs\": %s}",
		productId, productName, price, currencyString, discount, quantity, category->categoryFullString.c_str(), total_extra_attrs.c_str());
	
	return jsonString;
}
