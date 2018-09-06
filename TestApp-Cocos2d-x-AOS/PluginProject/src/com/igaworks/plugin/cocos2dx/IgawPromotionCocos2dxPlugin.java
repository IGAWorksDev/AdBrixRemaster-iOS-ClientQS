package com.igaworks.plugin.cocos2dx;

import android.app.Activity;
import android.util.Log;

import com.igaworks.adbrix.interfaces.ADBrixCallbackListener;
import com.igaworks.promotion.IgawPromotion;

public class IgawPromotionCocos2dxPlugin{
	private static Activity currentActivity = null;	

	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}
	
	public static void showAD(String name){
		currentActivity.runOnUiThread(new Runnable(){
			private String name;
			
			public Runnable start(String name){
				this.name = name;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawPromotion.showAD(name, currentActivity, new ADBrixCallbackListener(){

					@Override
					public void run() {
						// TODO Auto-generated method stub
						Log.d("IgawPromotionCocos2dxPlugin", "OnPlayBtnClickListener"); // OnPlayBtnClickListener
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(15, "");
					}
					
				});
			}
		}.start(name));
	}
	
	public static void hideAD() {
		currentActivity.runOnUiThread(new Runnable(){
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawPromotion.hideAD();
			}
		});
	}
}
