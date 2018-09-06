package com.igaworks.plugin.cocos2dx;

import android.app.Activity;
import android.util.Log;

import com.igaworks.IgawCommon;
import com.igaworks.interfaces.IgawRewardItem;
import com.igaworks.interfaces.IgawRewardItemEventListener;

public class IgawCommonCocos2dxPlugin{
	private static Activity currentActivity = null;	

	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}
	
	public static void startApplication(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCommon.startApplication(currentActivity);
			}			
		});
	}
	
	public static void startSession(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCommon.startSession(currentActivity);
			}			
		});
	}
	
	public static void endSession(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCommon.endSession();
			}			
		});
	}
	
	public static void setUserId(String userId){
		currentActivity.runOnUiThread(new Runnable(){
			private String userId = "";
			
			public Runnable start(String userId){
				this.userId = userId;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCommon.setUserId(userId);
			}
		}.start(userId));
	}
	
	public static void setClientRewardEventListener(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCommon.setClientRewardEventListener(new IgawRewardItemEventListener(){
					@Override
					public void onDidGiveRewardItemResult(boolean isSuccess, String message, int resultCode, String completedRewardKey) {
						// TODO Auto-generated method stub
						Log.d("IgawCommonCocos2dxPlugin", "OnDidGiveRewardItemResult");
						String msg = String.valueOf(isSuccess);
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(2, msg);
					}

					@Override
					public void onGetRewardInfo(boolean isSuccess, String message, IgawRewardItem[] rewardItems){
						// TODO Auto-generated method stub
						Log.d("IgawCommonCocos2dxPlugin", "OnGetRewardInfo");
						if (isSuccess){
							if (rewardItems.length == 0) {
								Log.d("IgawCommonCocos2dxPlugin", "There is no Reward Info for user.");
							} else {
								Log.d("IgawCommonCocos2dxPlugin", "Detected Igaworks Reward Info.");
								//int index = 1;
								for (IgawRewardItem rewardItem : rewardItems){
									
								/*	String rewardInfo = 
											"campaignkey=" + rewardItem.getCampaignKey() + 
											"&campaignname=" + rewardItem.getCampaignTitle() + 
											"&quantity=" + rewardItem.getRewardQuantity() + 
											"&cv=" + rewardItem.getCV() + 
											"&rewardkey=" + rewardItem.getRTID() +
											"&index=" + index + 
											"&length=" + rewardItems.length;
									
									index++;
									IgaworksCocos2dxPlugin.sendCallbackMessage(3, rewardInfo);*/
									IgaworksCocos2dxPlugin.sendRewardCallbackMessage(rewardItem.getCampaignKey(),
											rewardItem.getCampaignTitle(), rewardItem.getRewardQuantity() + "", rewardItem.getCV(), rewardItem.getRTID());
								}
							}
						}						
					}					
				});
			}
		});
	}
}
