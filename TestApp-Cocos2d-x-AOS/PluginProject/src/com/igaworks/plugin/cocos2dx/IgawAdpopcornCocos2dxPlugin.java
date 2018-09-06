package com.igaworks.plugin.cocos2dx;

import android.app.Activity;
import android.util.Log;

import com.igaworks.adpopcorn.IgawAdpopcorn;
import com.igaworks.adpopcorn.IgawAdpopcornExtension;
import com.igaworks.adpopcorn.cores.common.APError;
import com.igaworks.adpopcorn.interfaces.IAPLoadVideoAdEventListener;
import com.igaworks.adpopcorn.interfaces.IAPShowVideoAdEventListener;
import com.igaworks.adpopcorn.interfaces.IAdPOPcornEventListener;

public class IgawAdpopcornCocos2dxPlugin{
	private static Activity currentActivity = null;	
	
	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
		IgawAdpopcornExtension.isUnityPlatfrom(true);
	}

	public static void openOfferwall(){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcorn.setEventListener(currentActivity, new IAdPOPcornEventListener(){
						@Override
						public void OnClosedOfferWallPage() {
							// TODO Auto-generated method stub
							Log.d("IgawAdpopcornCocos2dxPlugin", "OnClosedOfferWallPage");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(1, "");
						}				
					});
					IgawAdpopcorn.openOfferWall(currentActivity);
				}			
			});
		}catch(Exception e){e.printStackTrace();}
	}
	
	public static void setSensorLandscapeEnable(boolean flag){
		try{
			IgawAdpopcorn.setSensorLandscapeEnable(currentActivity, flag);
		}catch(Exception e){}
	}
	
	public static void setEventListener(){
	}

	public static void openBanner(String campaignKey){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				private String campaignKey = "";
				
				public Runnable start(String campaignKey){
					this.campaignKey = campaignKey;
					return this;
				}
				
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcornExtension.openBanner(currentActivity, campaignKey);
				}			
			}.start(campaignKey));
		}catch(Exception e){e.printStackTrace();}
	}

	/*public static void openCouponBox(){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcornExtension.openCouponBox(currentActivity);
				}			
			});
		}catch(Exception e){e.printStackTrace();}
	}*/
	
	public static void getClientPendingRewardItems(){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcornExtension.getClientPendingRewardItems(currentActivity);
				}			
			});
		}catch(Exception e){e.printStackTrace();}
	}
	
	public static void openPromotionEvent(){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcornExtension.openPromotionEvent(currentActivity);
				}			
			});
		}catch(Exception e){e.printStackTrace();}
	}
	
	public static void didGiveRewardItem(String cv, String rewardKey){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				private String cv = "";
				private String rewardKey = "";
				
				public Runnable start(String cv, String rewardKey){
					this.cv = cv;
					this.rewardKey = rewardKey;
					return this;
				}
				
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcornExtension.didGiveRewardItemForUnityPlugin(currentActivity, cv, rewardKey);
				}			
			}.start(cv, rewardKey));
		}catch(Exception e){e.printStackTrace();}
	}
	
	public static void loadVideoAd(){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcorn.loadVideoAd(currentActivity, new IAPLoadVideoAdEventListener(){

						@Override
						public void OnLoadVideoAdFailure(APError apError) {
							// TODO Auto-generated method stub
							Log.d("IgawAdpopcornCocos2dxPlugin", "OnLoadVideoAdFailure");
							IgaworksCocos2dxPlugin.sendCallbackMessageType2(27, apError.getErrorCode(), apError.getErrorMessage());
						}

						@Override
						public void OnLoadVideoAdSuccess() {
							// TODO Auto-generated method stub
							Log.d("IgawAdpopcornCocos2dxPlugin", "OnLoadVideoAdSuccess");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(28, "");
						}
						
					});
				}			
			});
		}catch(Exception e){e.printStackTrace();}
	}
	
	public static void showVideoAd(){
		try{
			currentActivity.runOnUiThread(new Runnable(){
				@Override
				public void run() {
					// TODO Auto-generated method stub
					IgawAdpopcorn.showVideoAd(currentActivity, new IAPShowVideoAdEventListener(){

						@Override
						public void OnShowVideoAdFailure(APError apError) {
							// TODO Auto-generated method stub
							Log.d("IgawAdpopcornCocos2dxPlugin", "OnShowVideoAdFailure");
							IgaworksCocos2dxPlugin.sendCallbackMessageType2(29, apError.getErrorCode(), apError.getErrorMessage());
						}

						@Override
						public void OnShowVideoAdSuccess() {
							// TODO Auto-generated method stub
							Log.d("IgawAdpopcornCocos2dxPlugin", "OnShowVideoAdSuccess");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(30, "");
						}

						@Override
						public void OnVideoAdClose() {
							// TODO Auto-generated method stub
							Log.d("IgawAdpopcornCocos2dxPlugin", "OnVideoAdClose");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(31, "");
						}
						
					});
				}			
			});
		}catch(Exception e){e.printStackTrace();}
	}
}
