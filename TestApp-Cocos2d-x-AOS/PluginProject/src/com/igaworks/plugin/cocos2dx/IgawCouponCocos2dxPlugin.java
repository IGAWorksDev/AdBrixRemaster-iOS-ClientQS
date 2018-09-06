package com.igaworks.plugin.cocos2dx;

import java.util.ArrayList;
import java.util.List;

import org.apache.http.NameValuePair;
import org.apache.http.client.utils.URLEncodedUtils;
import org.apache.http.message.BasicNameValuePair;

import android.app.Activity;
import android.app.Dialog;
import android.util.Log;

import com.igaworks.coupon.IgawCoupon;
import com.igaworks.coupon.interfaces.CouponCallbackListener;
import com.igaworks.coupon.model.ValidationResultModel;

public class IgawCouponCocos2dxPlugin{
	private static Activity currentActivity = null;	

	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}
	
	public static void showCouponDialog(boolean showResultMsgToast){
		currentActivity.runOnUiThread(new Runnable(){
			private boolean showResultMsgToast;
			
			public Runnable start(boolean showResultMsgToast){
				this.showResultMsgToast = showResultMsgToast;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCoupon.showCouponDialog(currentActivity, showResultMsgToast, new CouponCallbackListener(){

					@Override
					public void run(Dialog dialog, ValidationResultModel result) {
						// TODO Auto-generated method stub
						List<NameValuePair> params = new ArrayList<NameValuePair>();
						params.add(new BasicNameValuePair("Message", result.getMessage()));
						params.add(new BasicNameValuePair("ItemKey", result.getItemKey() + ""));
						params.add(new BasicNameValuePair("ItemName", result.getItemName()));
						params.add(new BasicNameValuePair("Quantity", result.getQuantity() + ""));
						
						String param = URLEncodedUtils.format(params, "utf-8");
						
						if(result.getResult()){
							if (dialog!= null) dialog.dismiss();
							Log.d("IgawCouponCocos2dxPlugin", "OnSendCouponSucceed");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(4, param);
						}else{
							Log.d("IgawCouponCocos2dxPlugin", "OnSendCouponFailed");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(5, result.getMessage());
						}
					}
				});
			}	
			
		}.start(showResultMsgToast));
	}
	
	public static void checkCoupon(String couponText){
		currentActivity.runOnUiThread(new Runnable(){
			
			private String couponText = "";
			public Runnable start(String couponText){
				this.couponText = couponText;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawCoupon.checkCoupon(currentActivity, couponText, new CouponCallbackListener(){

					@Override
					public void run(Dialog dialog, ValidationResultModel result) {
						// TODO Auto-generated method stub
						List<NameValuePair> params = new ArrayList<NameValuePair>();
						params.add(new BasicNameValuePair("Message", result.getMessage()));
						params.add(new BasicNameValuePair("ItemKey", result.getItemKey() + ""));
						params.add(new BasicNameValuePair("ItemName", result.getItemName()));
						params.add(new BasicNameValuePair("Quantity", result.getQuantity() + ""));
						
						String param = URLEncodedUtils.format(params, "utf-8");
						
						if(result.getResult()){
							Log.d("IgawCouponCocos2dxPlugin", "OnSendCouponSucceed");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(4, param);
						}else{
							Log.d("IgawCouponCocos2dxPlugin", "OnSendCouponFailed");
							IgaworksCocos2dxPlugin.sendCallbackMessageType1(5, result.getMessage());
						}
					}
					
				});
			}			
		}.start(couponText));
	}
}
