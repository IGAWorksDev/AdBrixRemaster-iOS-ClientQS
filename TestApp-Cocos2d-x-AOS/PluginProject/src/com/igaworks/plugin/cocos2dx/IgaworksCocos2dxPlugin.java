package com.igaworks.plugin.cocos2dx;

import android.app.Activity;

public class IgaworksCocos2dxPlugin{
	
	private static String PluginVersion = "1.0.7a";
	private static Activity currentActivity = null;	
	
	public static native void sendCallbackMessageType1(int callbackType, String message);
	public static native void sendCallbackMessageType2(int callbackType, int code, String message);
	public static native void sendCallbackMessageType3(int callbackType, boolean arg0);
	public static native void sendRewardCallbackMessage(String campaignKey, String campaignName, String quantity, String cv, String rewardKey);

	public static void setCocos2dxActivity(Activity activity){		
		IgawAdbrixCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawAdpopcornCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawCommonCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawCouponCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawDisplayAdCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawLiveOpsCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawPromotionCocos2dxPlugin.setCocos2dxActivity(activity);
		IgawNanooCocos2dxPlugin.setCocos2dxActivity(activity);
		
		currentActivity = activity;		
	}
}
