package com.igaworks.plugin.cocos2dx;

import android.app.Activity;
import android.util.Log;

import com.igaworks.liveops.IgawLiveOps;
import com.igaworks.liveops.livepopup.LiveOpsDeepLinkEventListener;
import com.igaworks.liveops.livepopup.LiveOpsPopupEventListener;
import com.igaworks.liveops.livepopup.LiveOpsPopupResourceEventListener;
import com.igaworks.liveops.pushservice.LiveOpsGCMPushEnableEventListener;
import com.igaworks.liveops.pushservice.RegistrationIdEventListener;

public class IgawLiveOpsCocos2dxPlugin{
	private static Activity currentActivity = null;	

	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}
	
	public static void initializeLiveOps(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.initialize(currentActivity);
			}			
		});
	}
	
	public static void initializeLiveOps(final String senderIDs){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.initialize(currentActivity, senderIDs);
			}			
		});
	}
	
	public static void resumeLiveOps(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.resume(currentActivity);
			}			
		});
	}
	
/*	public static void setLiveOpsNotificationCallback(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setLiveOpsNotificationCallback(new LiveOpsNotificationCallback(){

					@Override
					public void onPushReceived(JSONObject arg0) {
						// TODO Auto-generated method stub
						Log.d("IgawLiveOpsCocos2dxPlugin", "OnLiveOpsNotification"); // OnLiveOpsNotification
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(14, arg0 == null ? "" : arg0.toString());
					}					
				});
			}			
		});
	}*/
	
	public static void setTargetingData(String userGroup, String userData){
		currentActivity.runOnUiThread(new Runnable(){
			private String userGroup, userData;
			
			public Runnable start(String userGroup, String userData){
				this.userGroup = userGroup;
				this.userData = userData;
				return this;
			}
			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setTargetingData(currentActivity, userGroup, (String)userData);
			}			
		}.start(userGroup, userData));
	}
	
	public static void setTargetingData(String userGroup, int userData){
		currentActivity.runOnUiThread(new Runnable(){
			private String userGroup;
			private int userData;
			
			public Runnable start(String userGroup, int userData){
				this.userGroup = userGroup;
				this.userData = userData;
				return this;
			}
			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setTargetingData(currentActivity, userGroup, userData);
			}			
		}.start(userGroup, userData));
	}
	
	public static void setTargetingData(String userGroup, long userData){
		currentActivity.runOnUiThread(new Runnable(){
			private String userGroup;
			private long userData;
			
			public Runnable start(String userGroup, long userData){
				this.userGroup = userGroup;
				this.userData = userData;
				return this;
			}
			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setTargetingData(currentActivity, userGroup, userData);
			}			
		}.start(userGroup, userData));
	}
	
	public static void setTargetingData(String userGroup, float userData){
		currentActivity.runOnUiThread(new Runnable(){
			private String userGroup;
			private float userData;
			
			public Runnable start(String userGroup, float userData){
				this.userGroup = userGroup;
				this.userData = userData;
				return this;
			}
			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setTargetingData(currentActivity, userGroup, userData);
			}			
		}.start(userGroup, userData));
	}
	
	public static void setTargetingData(String userGroup, boolean userData){
		currentActivity.runOnUiThread(new Runnable(){
			private String userGroup;
			private boolean userData;
			
			public Runnable start(String userGroup, boolean userData){
				this.userGroup = userGroup;
				this.userData = userData;
				return this;
			}
			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setTargetingData(currentActivity, userGroup, userData);
			}			
		}.start(userGroup, userData));
	}
	
	
	public static void setNormalClientPushEvent(long second, String contentText, int eventId, boolean alwaysIsShown){
		currentActivity.runOnUiThread(new Runnable(){
			private long second;
			private String contentText;
			private int eventId;
			private boolean alwaysIsShown;
			
			public Runnable start(long second, String contentText, int eventId, boolean alwaysIsShown){
				this.second = second;
				this.contentText = contentText;
				this.eventId = eventId;
				this.alwaysIsShown = alwaysIsShown;
				return this;
			}
			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setNormalClientPushEvent(currentActivity, second, contentText, eventId, alwaysIsShown);
			}			
		}.start(second, contentText, eventId, alwaysIsShown));
	}
	
	public static void setBigTextClientPushEvent(long second, String contentText, String bigContentTitle, String bigText, String summaryText, int eventId, boolean alwaysIsShown){
		currentActivity.runOnUiThread(new Runnable(){
			private long second;
			private String contentText;
			private String bigContentTitle;
			private String bigText;
			private String summaryText;
			private int eventId;
			private boolean alwaysIsShown;
			
			public Runnable start(long second, String contentText, String bigContentTitle, String bigText, String summaryText, int eventId, boolean alwaysIsShown){
				this.second = second;
				this.contentText = contentText;
				this.bigContentTitle = bigContentTitle;
				this.bigText = bigText;
				this.summaryText = summaryText;
				this.eventId = eventId;
				this.alwaysIsShown = alwaysIsShown;
				return this;
			}			
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setBigTextClientPushEvent(currentActivity, second, contentText, bigContentTitle, bigText, summaryText, eventId, alwaysIsShown);
			}			
		}.start(second, contentText, bigContentTitle, bigText, summaryText, eventId, alwaysIsShown));
	}
	
	public static void enableService(boolean enable){
		currentActivity.runOnUiThread(new Runnable(){
			private boolean enable;
			
			public Runnable start(boolean enable){
				this.enable = enable;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.enableService(currentActivity, enable);
			}			
		}.start(enable));
	}
	
	
	public static void enableServiceWithCallback(boolean enable){
		Log.d("IgawLiveOpsCocos2dxPlugin", "enableServiceWithCallback" + "This Api is deprecated and noting to do");
//		currentActivity.runOnUiThread(new Runnable(){
//			private boolean enable;
//			
//			public Runnable start(boolean enable){
//				this.enable = enable;
//				return this;
//			}
//			
//			@Override
//			public void run() {
//				// TODO Auto-generated method stub
//				IgawLiveOps.enableService(currentActivity, enable, new LiveOpsGCMPushEnableEventListener() {
//					
//					@Override
//					public void onEnableService(boolean isSuccess) {
//						// TODO Auto-generated method stub
//						if(isSuccess){
//							Log.d("IgawLiveOpsCocos2dxPlugin", "OnSuccessLiveOpsGCMPushEnableEventListener >> isSuccess: " + isSuccess); 
//							IgaworksCocos2dxPlugin.sendCallbackMessageType1(21, "");	
//						}else{
//							Log.d("IgawLiveOpsCocos2dxPlugin", "OnFailLiveOpsPopupResourceEventListener >> isSuccess: " + isSuccess); 
//							IgaworksCocos2dxPlugin.sendCallbackMessageType1(22, "");	
//						}
//					}
//				});
//			}			
//		}.start(enable));
	}
	
	
	public static void cancelClientPushEvent(int eventId){
		currentActivity.runOnUiThread(new Runnable(){
			private int eventId;
			
			public Runnable start(int eventId){
				this.eventId = eventId;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.cancelClientPushEvent(currentActivity, eventId);
			}			
		}.start(eventId));
	}
	
	public static void setNotificationIconName(String notificationIconName){
		currentActivity.runOnUiThread(new Runnable(){
			private String notificationIconName;
			
			public Runnable start(String notificationIconName){
				this.notificationIconName = notificationIconName;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setNotificationIconName(currentActivity, notificationIconName);
			}			
		}.start(notificationIconName));
	}
	
/*	Move this to Cocos2dxActivity
 * public static void setNotificationIconStyle(String smallIcon, String largeIcon, String iconbackground_argb){
		int parseColor = HexToInt(iconbackground_argb);
		currentActivity.runOnUiThread(new Runnable(){
			private String smallIcon;
			private String largeIcon;
			private int parseColor;
			
			public Runnable start(String smallIcon, String largeIcon, int parseColor){
				this.smallIcon = smallIcon;
				this.largeIcon = largeIcon;
				this.parseColor = parseColor;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setNotificationIconStyle(currentActivity, smallIcon, largeIcon, parseColor);
			}			
		}.start(smallIcon, largeIcon, parseColor));
	}*/
	
	public static void showPopUp(String spaceKey){
		currentActivity.runOnUiThread(new Runnable(){
			private String spaceKey;
			
			public Runnable start(String spaceKey){
				this.spaceKey = spaceKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.showPopUp(currentActivity, spaceKey, new LiveOpsDeepLinkEventListener() {
					
					@Override
					public void onReceiveDeeplinkData(String deeplink_json) {
						// TODO Auto-generated method stub
						if(deeplink_json == null) deeplink_json = "";
						Log.d("IgawLiveOpsCocos2dxPlugin", "OnLiveOpsDeepLinkEventListener >> deepLink: " + (deeplink_json.equals("") ? "null" : deeplink_json)); 
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(17, deeplink_json);
						
					}
				});
			}			
		}.start(spaceKey));
	}
	
	public static void requestPopupResource(){
		currentActivity.runOnUiThread(new Runnable(){
			
			public Runnable start(){
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.requestPopupResource(currentActivity, new LiveOpsPopupResourceEventListener() {
					
					@Override
					public void onReceiveResource(boolean isSuccess) {
						// TODO Auto-generated method stub
						if(isSuccess){
							Log.d("IgawLiveOpsCocos2dxPlugin", "OnSuccessLiveOpsPopupResourceEventListener >> isSuccess: " + isSuccess); 
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(18, "");	
						}else{
							Log.d("IgawLiveOpsCocos2dxPlugin", "OnFailLiveOpsPopupResourceEventListener >> isSuccess: " + isSuccess); 
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(19, "");	
						}
						
					}
				});
			}			
		}.start());
	}
	
	public static void destroyPopup(){
		currentActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.destroyPopup();
			}
		});
	}
	
	public static void destroyAllPopups(){
		currentActivity.runOnUiThread(new Runnable() {
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.destroyAllPopups();
			}
		});
	}
	
	public static void flush(){
		currentActivity.runOnUiThread(new Runnable() {
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.flush(currentActivity);
			}
		});
	}
	public static void setRegistrationIdEventListener(){
		currentActivity.runOnUiThread(new Runnable(){
			
			public Runnable start(){
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setRegistrationIdEventListener(new RegistrationIdEventListener() {
					
					@Override
					public void onReceiveRegistrationId(String regID) {
						// TODO Auto-generated method stub
						if(regID == null) regID = "";
						Log.d("IgawLiveOpsCocos2dxPlugin", "OnRegistrationIdEventListener >> registration ID: " + regID); 
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(20, regID);
					}
				});
			}			
		}.start());
	}
	
	public static void setLiveOpsPopupEventListener(){
		currentActivity.runOnUiThread(new Runnable() {
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.setLiveOpsPopupEventListener(new LiveOpsPopupEventListener() {
					
					@Override
					public void onPopupClick() {
						// TODO Auto-generated method stub
						Log.d("IgawLiveOpsCocos2dxPlugin", "LiveOpsPopupEventListener >> onPopupClick"); 
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(23, "");
					}
					
					@Override
					public void onCancelPopupBtnClick() {
						// TODO Auto-generated method stub
						Log.d("IgawLiveOpsCocos2dxPlugin", "LiveOpsPopupEventListener >> onCancelPopupBtnClick"); 
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(24, "");
					}
				});
			}
		});
	}

	public static void registerFCMToken(String refreshedToken){
		currentActivity.runOnUiThread(new Runnable(){
			private String refreshedToken;
			
			public Runnable start(String refreshedToken){
				this.refreshedToken = refreshedToken;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawLiveOps.registerFCMToken(currentActivity, refreshedToken);
			}	
		}.start(refreshedToken));
	}
	
	
}
