package com.igaworks.plugin.cocos2dx;

import android.app.Activity;
import android.util.Log;

import com.igaworks.displayad.IgawDisplayAd;
import com.igaworks.displayad.common.DAErrorCode;
import com.igaworks.displayad.interfaces.IEndingAdEventCallbackListener;
import com.igaworks.displayad.interfaces.IEndingAdResultCallbackListener;
import com.igaworks.displayad.interfaces.IInterstitialEventCallbackListener;
import com.igaworks.displayad.interfaces.IPopupEventCallbackListener;
import com.igaworks.nativead.IgawNativeAd;
import com.igaworks.nativead.IgawNativeAdErrorCode;
import com.igaworks.nativead.IgawNativeAdListener;

public class IgawDisplayAdCocos2dxPlugin{
	private static Activity currentActivity = null;	

	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}

	public static void initDisplayAd(){
		initDisplayAd(false, false);
	}
	
	public static void initDisplayAd(boolean isTestMode, boolean enableDetailLog){
		currentActivity.runOnUiThread(new Runnable(){
			private boolean isTestMode, enableDetailLog;
			
			public Runnable start(boolean isTestMode, boolean enableDetailLog){
				this.isTestMode = isTestMode;
				this.enableDetailLog = enableDetailLog;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.init(currentActivity, isTestMode, enableDetailLog);
			}			
		}.start(isTestMode, enableDetailLog));
	}
	
	public static void destroy(){
		currentActivity.runOnUiThread(new Runnable(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.destroy();
			}			
		});
	}
	
	public static void showInterstitialAd(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.setInterstitialEventCallbackListener(currentActivity, spotKey, new IInterstitialEventCallbackListener(){

					@Override
					public void OnInterstitialClosed() {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnInterstitialClosed"); // OnInterstitialClosed
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(8, "");
					}

					@Override
					public void OnInterstitialReceiveFailed(DAErrorCode errorCode) {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnInterstitialReceiveFailed"); // OnInterstitialReceiveFailed
						IgaworksCocos2dxPlugin.sendCallbackMessageType2(7, errorCode.getErrorCode(), errorCode.getErrorMessage());
					}

					@Override
					public void OnInterstitialReceiveSuccess() {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnInterstitialReceiveSuccess"); //  OnInterstitialReceiveSuccess
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(6, "");
					}
					
				});
				IgawDisplayAd.showInterstitialAd(currentActivity, spotKey);
			}			
		}.start(spotKey));
	}

	public static void loadEndingAd(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.loadEndingAd(currentActivity, spotKey);
			}			
		}.start(spotKey));
	}
	
	public static void showEndingAd(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub				
				IgawDisplayAd.showEndingAd(currentActivity, spotKey);
			}			
		}.start(spotKey));
	}
	
	public static void showEndingAd(String spotKey, boolean hideEndingAdNormalPopup){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			private boolean hideEndingAdNormalPopup;
			public Runnable start(String spotKey, boolean hideEndingAdNormalPopup){
				this.spotKey = spotKey;
				this.hideEndingAdNormalPopup = hideEndingAdNormalPopup; 
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub		
				IgawDisplayAd.showEndingAd(currentActivity, spotKey, hideEndingAdNormalPopup);
			}			
		}.start(spotKey, hideEndingAdNormalPopup));
	}
	
	public static void setEndingAdEventCallbackListener(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.setEndingAdEventCallbackListener(currentActivity, spotKey, new IEndingAdEventCallbackListener(){
					@Override
					public void OnBtnClickListener(boolean finish) {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnBtnClickListener"); //  OnBtnClickListener
						IgaworksCocos2dxPlugin.sendCallbackMessageType3(16, finish);
					}
				
				});
			}			
		}.start(spotKey));
	}
	
	public static void setEndingAdResultCallbackListener(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.setEndingAdResultCallbackListener(currentActivity, spotKey, new IEndingAdResultCallbackListener(){

					@Override
					public void OnEndingAdFailedToShow() {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnEndingAdFailedToShow"); //  OnEndingAdFailedToShow
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(25, "");
					}

					@Override
					public void OnEndingAdShowed() {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnEndingAdShowed"); //  OnEndingAdShowed
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(25, "");
					}
					
				});
			}			
		}.start(spotKey));
	}
	
	public static void showPopupAd(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawDisplayAd.setPopupEventCallbackListener(currentActivity, spotKey, new IPopupEventCallbackListener(){

					@Override
					public void OnPopupAdClosed() {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnPopupAdClosed"); // OnPopupAdClosed
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(11, "");
					}

					@Override
					public void OnPopupAdReceiveFailed(DAErrorCode errorCode) {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnPopupAdReceiveFailed"); // OnPopupAdReceiveFailed
						IgaworksCocos2dxPlugin.sendCallbackMessageType2(10, errorCode.getErrorCode(), errorCode.getErrorMessage());
					}

					@Override
					public void OnPopupAdReceiveSuccess() {
						// TODO Auto-generated method stub
						Log.d("IgawDisplayAdCocos2dxPlugin", "OnPopupAdReceiveSuccess"); // OnPopupAdReceiveSuccess
						IgaworksCocos2dxPlugin.sendCallbackMessageType1(9, "");
					}
					
				});
				IgawDisplayAd.showPopupAd(currentActivity, spotKey);
			}			
		}.start(spotKey));
	}
	
	public static void setRefreshTime(int seconds){
		IgawDisplayAd.setRefreshTime(seconds);
	}
	
	public static void setLocation(double latitude, double longitude){
		IgawDisplayAd.setLocation(latitude, longitude);
	}
	
	// Native Ad.
	private static IgawNativeAd igawNativeAd = null;
	public static void loadNativeAd(String spotKey){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String spotKey = "";
			public Runnable start(String spotKey){
				this.spotKey = spotKey;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(igawNativeAd != null){
					igawNativeAd.destroyAd();
				}
				igawNativeAd = new IgawNativeAd(currentActivity, spotKey, new IgawNativeAdListener(){
					@Override
					public void OnNativeAdRequestFailed(IgawNativeAdErrorCode errorCode) {
						// TODO Auto-generated method stub
						IgaworksCocos2dxPlugin.sendCallbackMessageType2(13, errorCode.getErrorCode(), errorCode.getErrorMessage());
					}
		
					@Override
					public void OnNativeAdRequestSucceeded(IgawNativeAd nativeAd) {
						// TODO Auto-generated method stub
						if(nativeAd != null){
							String nativeAdContents = nativeAd.getNativeAdContents();
							if(nativeAdContents != null)
								IgaworksCocos2dxPlugin.sendCallbackMessageType1(12, nativeAdContents);
							else{
								IgawNativeAdErrorCode errorResult = new IgawNativeAdErrorCode(IgawNativeAdErrorCode.EXCEPTION);
								IgaworksCocos2dxPlugin.sendCallbackMessageType2(13, errorResult.getErrorCode(), errorResult.getErrorMessage());
							}
						}
					}
				});
				igawNativeAd.loadAd();
			}			
		}.start(spotKey));
	}
	
	public static void destroyNativeAd(){
		currentActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(igawNativeAd != null){
					igawNativeAd.destroyAd();
				}
			}			
		});
	}

	public static void impressionAction(){
		currentActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(igawNativeAd != null){
					igawNativeAd.impressionAction();
				}
			}			
		});
	}
	
	public static void clickAction(){
		currentActivity.runOnUiThread(new Runnable() {
			@Override
			public void run() {
				// TODO Auto-generated method stub
				if(igawNativeAd != null){
					igawNativeAd.clickAction(currentActivity);
				}
			}			
		});
	}
}
