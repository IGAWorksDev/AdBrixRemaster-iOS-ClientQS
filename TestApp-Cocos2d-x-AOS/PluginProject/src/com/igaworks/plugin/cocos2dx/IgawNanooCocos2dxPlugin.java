package com.igaworks.plugin.cocos2dx;

import android.app.Activity;
import android.util.Log;

import com.igaworks.interfaces.HttpCallbackListener;
import com.igaworks.nanoo.IgawNanoo;

public class IgawNanooCocos2dxPlugin {
	private static Activity currentActivity = null;
	
	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}
	
	public static void openFanPage(boolean openAutomatically){
		currentActivity.runOnUiThread(new Runnable(){
			private boolean openAutomatically;
			
			public Runnable start(boolean openAutomatically){
				this.openAutomatically = openAutomatically;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawNanoo.openFanPage(currentActivity, openAutomatically, new HttpCallbackListener() {
					
					@Override
					public void callback(String url) {
						// TODO Auto-generated method stub
						if(url == null) url = "";
						Log.d("IgawNanooCocos2dxPlugin", "OnOpenFanPageListener >> url: " + (url.equals("") ? "null" : url)); // OnPlayBtnClickListener
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(16, url);
					}
				});
			}
		}.start(openAutomatically));
		
	}
	
}
