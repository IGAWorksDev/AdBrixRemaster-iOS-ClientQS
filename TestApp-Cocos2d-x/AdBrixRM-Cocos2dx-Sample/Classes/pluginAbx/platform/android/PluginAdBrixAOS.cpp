#include "PluginAdBrixAOS.h"
#include <map>
#include <string>


//USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)

#include <jni.h>
#include <android/log.h>
#include "platform/android/jni/JniHelper.h"
#include "json.h"

#define  LOG_TAG    "AdBrixRM_COCOS2DX"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

#define  IGAW_ADBRIX_PLUGIN_CLASS_NAME "com/igaworks/v2/core/cocos2dx/AbxCocos2dxPlugin"

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

    static void callStaticMethodWithStringStringStringParam(const char*methodName, const char* param1, const char* param2, const char* param3, int sdkType) {
        JniMethodInfo methodInfo;

        if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V", sdkType)) {
            return;
        }

        jstring paramName1 = methodInfo.env->NewStringUTF(param1);
        jstring paramName2 = methodInfo.env->NewStringUTF(param2);
        jstring paramName3 = methodInfo.env->NewStringUTF(param3);


        methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName1, paramName2, paramName3);
        methodInfo.env->DeleteLocalRef(paramName1);
        methodInfo.env->DeleteLocalRef(paramName2);
        methodInfo.env->DeleteLocalRef(paramName3);
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

    static void callStaticMethodWithIntIntParam(const char*methodName, int param, int param2, int sdkType) {
        JniMethodInfo methodInfo;

        if (!getStaticMethodInfo(methodInfo, methodName, "(II)V", sdkType)) {
            return;
        }

        methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param, param2);
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

	static void callStaticMethodWithBooleanBooleanParam(const char* methodName, bool param1, bool param2, int sdkType) {
		JniMethodInfo methodInfo;

		if (!getStaticMethodInfo(methodInfo, methodName, "(ZZ)V", sdkType)) {
			return;
		}

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param1, param2);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}

    static void callStaticMethodWithBooleanStringParam(const char* methodName, bool param1, const char* param2, int sdkType) {
        JniMethodInfo methodInfo;

        if (!getStaticMethodInfo(methodInfo, methodName, "(ZLjava/lang/String;)V", sdkType)) {
            return;
        }

		LOGD("Called callStaticMethodWithBooleanStringParam");
        jstring paramName2 = methodInfo.env->NewStringUTF(param2);

        methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param1, paramName2);
        methodInfo.env->DeleteLocalRef(paramName2);
        methodInfo.env->DeleteLocalRef(methodInfo.classId);
    }

    static void callStaticMethodWithBooleanBooleanStringParam(const char*methodName, bool param1, bool param2, const char* param3, int sdkType) {
        JniMethodInfo methodInfo;

        if (!getStaticMethodInfo(methodInfo, methodName, "(ZZLjava/lang/String;)V", sdkType)) {
            return;
        }

        methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, param1, param2, param3);
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

	static void callStaticMethodForCommonPurchase(const char*methodName, const char *orderID, const char *purchaseDetail, double discount, double deliveryCharge, int paymentMethod,  const char* param3, int sdkType)
	{
		JniMethodInfo methodInfo;

        if (!getStaticMethodInfo(methodInfo, methodName, "(Ljava/lang/String;Ljava/lang/String;DDILjava/lang/String;)V", sdkType)) {
			return;
		}

		jstring paramName1 = methodInfo.env->NewStringUTF(orderID);
		jstring paramName2 = methodInfo.env->NewStringUTF(purchaseDetail);
        jstring paramName3 = methodInfo.env->NewStringUTF(param3);

        LOGD("Called callStaticMethodForCommonPurchase : %s", purchaseDetail);
        LOGD("Called callStaticMethodForCommonPurchase : %s", param3);

		methodInfo.env->CallStaticVoidMethod(methodInfo.classId, methodInfo.methodId, paramName1, paramName2, discount, deliveryCharge, paymentMethod, paramName3);
		methodInfo.env->DeleteLocalRef(paramName1);
		methodInfo.env->DeleteLocalRef(paramName2);
        methodInfo.env->DeleteLocalRef(paramName3);
		methodInfo.env->DeleteLocalRef(methodInfo.classId);
	}
	


} // extern "C"

// ADBRIX Remaster API
void PluginAdBrixAOS::gdprForgetMe() {
    LOGD("Called gdprForgetMe");
    callStaticMethod("gdprForgetMe", ADBRIX_SDK);
}

void PluginAdBrixAOS::event(const char* name, std::string jsonParam) {
    LOGD("Called event");
    callStaticMethodWithStringStringParam("event", name, jsonParam.c_str(), ADBRIX_SDK);
}

void PluginAdBrixAOS::login(const char* user_id) {
    LOGD("Called login");
    callStaticMethodWithStringParam("login", user_id, ADBRIX_SDK);
}

void PluginAdBrixAOS::setUserProperties(const char* key, const char* value) {
    LOGD("Called setUserProperties");
    callStaticMethodWithStringStringParam("setUserProperties", key, value, ADBRIX_SDK);
}

void PluginAdBrixAOS::commonPurchase(const char * orderID, const char * productSingle, double discount, double deliveryCharge, int paymentMethod, std::string jsonParam)  {
    LOGD("Called commonPurchase");
    callStaticMethodForCommonPurchase("commonPurchaseSingle", orderID, productSingle, discount, deliveryCharge, paymentMethod, jsonParam.c_str(), ADBRIX_SDK);
}

void PluginAdBrixAOS::commonSignUp(int signChannelIdx, std::string jsonParam) {
    LOGD("Called commonSignUp");
    callStaticMethodWithIntStringParam("commonSignUp", signChannelIdx, jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::commonUseCredit(std::string jsonParam) {
    LOGD("Called commonUseCredit");
    callStaticMethodWithStringParam("commonUseCredit", jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::commonAppUpdate(const char * prev_ver, const char * curr_ver, std::string jsonParam) {
    LOGD("Called commonAppUpdate");
    callStaticMethodWithStringStringStringParam("commonAppUpdate", prev_ver, curr_ver, jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::commonInvite(int inviteChannelIdx, std::string jsonParam) {
    LOGD("Called commonInvite");
    callStaticMethodWithIntStringParam("commonInvite", inviteChannelIdx, jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::gameTutorialCompleted(bool is_skip, std::string jsonParam) {
    LOGD("Called gameTutorialCompleted");
    callStaticMethodWithBooleanStringParam("gameTutorialCompleted", is_skip, jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::gameLevelAchieved(int level, std::string jsonParam) {
    LOGD("Called gameLevelAchieved");
    callStaticMethodWithIntStringParam("gameLevelAchieved", level, jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::gameCharacterCreated(std::string jsonParam) {
    LOGD("Called gameCharacterCreated");
    callStaticMethodWithStringParam("gameCharacterCreated", jsonParam.c_str(), ADBRIX_SDK);
}
void PluginAdBrixAOS::gameStageCleared(const char* stageName, std::string jsonParam) {
    LOGD("Called gameStageCleared");
    callStaticMethodWithStringStringParam("gameStageCleared", stageName, jsonParam.c_str(), ADBRIX_SDK);
}

void deeplinkOpen() {
    callStaticMethod("deepLinkOpen", ADBRIX_SDK);
}


#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
}

#else

#endif



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


std::string AdBrixCommerceProductModel::create(const char* productId, const char* productName, double price, double discount, int quantity, int currencyString, AdBrixCommerceProductCategoryModel* category, AdBrixCommerceProductAttrModel *extraAttrs)
{


    auto sPrice = std::to_string(price);
    auto sDiscount = std::to_string(discount);
    auto sQuantity = std::to_string(quantity);

    Json::Value root;

    root["productId"] = productId;
    root["productName"] = productName;
    root["price"] = sPrice;
    root["currency"] = currencyString;
    root["discount"] = sDiscount;
    root["quantity"] = sQuantity;
    root["category"] = category->categoryFullString;

    Json::Value extra_attrs;

    if(extraAttrs != NULL)
    {
        for (int i = 0; i < 5; i ++) {
            if((extraAttrs->getKey(i) != NULL) && (extraAttrs->getValue(i) != NULL)) {
                extra_attrs[extraAttrs->getKey(i)] = extraAttrs->getValue(i);
            }

        }
    }
    root["extra_attrs"] = extra_attrs;

    Json::StreamWriterBuilder builder;
    std::string output = Json::writeString(builder, root);

    return output;


//	std::string jsonString;
//	std::string extra_attrs[5];
//	std::string total_extra_attrs;
//	for (int i = 0; i < 5; i++)
//	{
//		if (extraAttrs->getKey(i) != NULL && extraAttrs->getValue(i) != NULL)
//		{
//			if(i != 4)extra_attrs[i] = cocos2d::StringUtils::format("\"%s\": \"%s\", ", extraAttrs->getKey(i), extraAttrs->getValue(i));
//			else extra_attrs[i] = cocos2d::StringUtils::format("\"%s\": \"%s\"", extraAttrs->getKey(i), extraAttrs->getValue(i));
//		}
//		else
//		{
//			extra_attrs[i] = "";
//		}
//	}
//
//	total_extra_attrs = cocos2d::StringUtils::format("{%s %s %s %s %s}", extra_attrs[0].c_str(), extra_attrs[1].c_str(), extra_attrs[2].c_str(), extra_attrs[3].c_str(), extra_attrs[4].c_str());
//
//	jsonString = cocos2d::StringUtils::format("{\"productId\": \"%s\", \"productName\": \"%s\", \"price\": %g, \"currency\": \"%d\", \"discount\": %g, \"quantity\": %d, \"category\": \"%s\", \"extra_attrs\": %s}",
//		productId, productName, price, currencyString, discount, quantity, category->categoryFullString.c_str(), total_extra_attrs.c_str());
//
//	return jsonString;
}
