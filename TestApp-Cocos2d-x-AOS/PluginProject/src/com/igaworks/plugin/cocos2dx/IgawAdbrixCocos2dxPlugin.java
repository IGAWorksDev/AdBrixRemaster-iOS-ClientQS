package com.igaworks.plugin.cocos2dx;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.app.Activity;
import android.util.Log;

import com.igaworks.adbrix.IgawAdbrix;
import com.igaworks.adbrix.interfaces.ADBrixInterface.CohortVariable;
import com.igaworks.commerce.IgawCommerce.Currency;
import com.igaworks.commerce.IgawCommerceProductAttrModel;
import com.igaworks.commerce.IgawCommerceProductCategoryModel;
import com.igaworks.commerce.IgawCommerceProductModel;
import com.igaworks.core.IgawConstant;
import com.igaworks.core.IgawLogger;

public class IgawAdbrixCocos2dxPlugin{
	private static Activity currentActivity = null;	

	public static void setCocos2dxActivity(Activity activity){
		currentActivity = activity;
	}
	
	public static void setAge(int age){
		currentActivity.runOnUiThread(new Runnable(){
			private int age;
			
			public Runnable start(int age){
				this.age = age;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawAdbrix.setAge(age);
			}
		}.start(age));
	}
	
	public static void setGender(int gender) {
		currentActivity.runOnUiThread(new Runnable(){
			private int gender;
			
			public Runnable start(int gender){
				this.gender = gender;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawAdbrix.setGender(gender);
			}
		}.start(gender));
	}
	
	
	public static void firstTimeExperience(String name){
		currentActivity.runOnUiThread(new Runnable(){
			private String name = "";
			
			public Runnable start(String name){
				this.name = name;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawAdbrix.firstTimeExperience(name);
			}
		}.start(name));
	}
	
	public static void retention(String name){
		currentActivity.runOnUiThread(new Runnable(){
			private String name = "";
			
			public Runnable start(String name){
				this.name = name;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawAdbrix.retention(name);
			}
		}.start(name));
	}
	
	public static void retention(String name, String param){
		currentActivity.runOnUiThread(new Runnable(){
			private String name = "";
			private String param = "";
			
			public Runnable start(String name, String param){
				this.name = name;
				this.param = param;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawAdbrix.retention(name, param);
			}
		}.start(name, param));
	}
	
	public static void buy(String name){
		currentActivity.runOnUiThread(new Runnable(){
			private String name = "";
			
			public Runnable start(String name){
				this.name = name;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
				IgawAdbrix.buy(name);
			}
		}.start(name));
	}
	
	public static void setCustomCohort(int cohortVar, String value)
	{
		currentActivity.runOnUiThread(new Runnable(){
			private int cohortVar;
			private String value = "";
			
			public Runnable start(int cohortVar, String value)
			{
				this.cohortVar = cohortVar;
				this.value = value;
				return this;
			}
			
			@Override
			public void run() {
				// TODO Auto-generated method stub				
				if(cohortVar == 1) IgawAdbrix.setCustomCohort(CohortVariable.COHORT_1, value);
				if(cohortVar == 2) IgawAdbrix.setCustomCohort(CohortVariable.COHORT_2, value);
				if(cohortVar == 3) IgawAdbrix.setCustomCohort(CohortVariable.COHORT_3, value);
				if(cohortVar > 3 || cohortVar < 0) Log.w(IgawConstant.QA_TAG, "Cocos2dx > setCustomCohort > Invalid cohort value: " + cohortVar);				
			}
		}.start(cohortVar, value));
	}
	
	public static IgawCommerceProductModel MakeProductFromJsonForCommerceV2(String purchaseDataJsonString)
	{
		try {
			Log.i("HOIIL", "purchase data" + purchaseDataJsonString);
			JSONArray root = new JSONArray(("[" +purchaseDataJsonString + "]"));


			if(root.length() < 1)
			{
				IgawLogger.Logging(currentActivity.getApplicationContext(), IgawConstant.QA_TAG, "commerceV2PlugIn error : No purhcase item.", IgawLogger.LOG_E, false);
				return null;
			}
			Log.i("HOIIL", "root is" + root);
			for(int i = 0; i < root.length(); i++)
			{	
				try{
					JSONObject item = root.getJSONObject(i);

					IgawCommerceProductModel pItem = new IgawCommerceProductModel();
					Log.i("HOIIL", "1" + pItem);
					if(item.has("productId"))
					{
						pItem.setProductID(item.getString("productId"));
					}
					else
					{
						throw new Exception("No productId attribute.");
					}
					Log.i("HOIIL", "2" + pItem);
					if(item.has("productName"))
					{
						pItem.setProductName(item.getString("productName"));
					}
					else
					{
						throw new Exception("No productName attribute.");
					}
					Log.i("HOIIL", "3" + pItem);
					if(item.has("price"))
					{
						pItem.setPrice(Double.parseDouble(item.getString("price")));
					}
					else
					{
						throw new Exception("No price attribute.");
					}
					Log.i("HOIIL", "4" + pItem);
					if(item.has("discount"))
					{
						pItem.setDiscount(Double.parseDouble(item.getString("discount")));
					}
					else
					{
						throw new Exception("No discount attribute.");
					}
					Log.i("HOIIL", "5" + pItem);
					if(item.has("quantity"))
					{
						pItem.setQuantity(Integer.parseInt(item.getString("quantity")));
					}
					else
					{
						throw new Exception("No quantity attribute.");
					}
					Log.i("HOIIL", "6" + pItem);
					if(item.has("currency"))
					{
						int intCurrency = Integer.parseInt(item.getString("currency"));
						if(intCurrency == 1)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.KR_KRW);
						else if(intCurrency == 2)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.US_USD);
						else if(intCurrency == 3)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.JP_JPY);
						else if(intCurrency == 4)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.EU_EUR);
						else if(intCurrency == 5)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.UK_GBP);
						else if(intCurrency == 6)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.CN_CNY);
						else if(intCurrency == 7)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.TW_TWD);
						else if(intCurrency == 8)pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.HK_HKD);
						else pItem.setCurrency(com.igaworks.commerce.IgawCommerce.Currency.KR_KRW);
						
						pItem.setCurrency(Currency.getCurrencyByCurrencyCode(item.getString("currency")));
					}
					else
					{
						throw new Exception("No currency attribute.");
					}
					Log.i("HOIIL", "7" + pItem);
					if(item.has("category"))
					{
						String[] categories = new String[5];
						String[] temp = item.getString("category") != null ? item.getString("category").split("\\.") : new String[0];

						for(int j = 0; j < temp.length; j++)
						{
							categories[j] = temp[j];
						}

						pItem.setCategory(IgawCommerceProductCategoryModel.create(categories[0], categories[1], categories[2], categories[3], categories[4]));
					}
					else
					{
						throw new Exception("No category attribute.");
					}
					Log.i("HOIIL", "8" + pItem);
					if(item.has("extra_attrs"))
					{
						final JSONObject subItem = item.getJSONObject("extra_attrs");
						HashMap<String, String> map = new HashMap<String, String>();
						final int n = subItem.length();

						Iterator<?> keys = subItem.keys();

						while( keys.hasNext() )
						{
							String key = (String)keys.next();
							String value = subItem.getString(key); 
							map.put(key, value);

						}
						pItem.setExtraAttrs(IgawCommerceProductAttrModel.create(map));
					}
					else
					{
						throw new Exception("No extra_attrs attribute.");
					}
					Log.i("HOIIL", "9" + pItem);
					return pItem;
				}
				catch(Exception e)
				{
					IgawLogger.Logging(currentActivity.getApplicationContext(), IgawConstant.QA_TAG, "purchase error : invalid item = " + purchaseDataJsonString, IgawLogger.LOG_E, false);
				}
			}
		} 
		catch (JSONException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	public static List<IgawCommerceProductModel> MakeProductsFromJsonForCommerceV2(String purchaseDataJsonString)
	{
		try {
			JSONArray root = new JSONArray(purchaseDataJsonString);


			if(root.length() < 1)
			{
				IgawLogger.Logging(currentActivity.getApplicationContext(), IgawConstant.QA_TAG, "commerceV2PlugIn error : No purhcase item.", IgawLogger.LOG_E, false);
				return null;
			}

			ArrayList<IgawCommerceProductModel> items = new ArrayList<IgawCommerceProductModel>();

			for(int i = 0; i < root.length(); i++)
			{	
				try{
					JSONObject item = root.getJSONObject(i);

					IgawCommerceProductModel pItem = new IgawCommerceProductModel();

					if(item.has("productId"))
					{
						IgawLogger.Logging(currentActivity.getApplicationContext(), IgawConstant.QA_TAG, "Productname is " + item.getString("productId"), IgawLogger.LOG_I, false);
						pItem.setProductID(item.getString("productId"));
					}
					else
					{
						throw new Exception("No productId attribute.");
					}

					if(item.has("productName"))
					{
						pItem.setProductName(item.getString("productName"));
					}
					else
					{
						throw new Exception("No productName attribute.");
					}

					if(item.has("price"))
					{
						pItem.setPrice(Double.parseDouble(item.getString("price")));
					}
					else
					{
						throw new Exception("No price attribute.");
					}

					if(item.has("discount"))
					{
						pItem.setDiscount(Double.parseDouble(item.getString("discount")));
					}
					else
					{
						throw new Exception("No discount attribute.");
					}

					if(item.has("quantity"))
					{
						pItem.setQuantity(Integer.parseInt(item.getString("quantity")));
					}
					else
					{
						throw new Exception("No quantity attribute.");
					}

					if(item.has("currency"))
					{
						pItem.setCurrency(Currency.getCurrencyByCurrencyCode(item.getString("currency")));
					}
					else
					{
						throw new Exception("No currency attribute.");
					}

					if(item.has("category"))
					{
						String[] categories = new String[5];
						String[] temp = item.getString("category") != null ? item.getString("category").split("\\.") : new String[0];

						for(int j = 0; j < temp.length; j++)
						{
							categories[j] = temp[j];
						}

						pItem.setCategory(IgawCommerceProductCategoryModel.create(categories[0], categories[1], categories[2], categories[3], categories[4]));
					}
					else
					{
						throw new Exception("No category attribute.");
					}

					if(item.has("extra_attrs"))
					{
						final JSONObject subItem = item.getJSONObject("extra_attrs");
						HashMap<String, String> map = new HashMap<String, String>();
						final int n = subItem.length();

						Iterator<?> keys = subItem.keys();

						while( keys.hasNext() )
						{
							String key = (String)keys.next();
							String value = subItem.getString(key); 
							map.put(key, value);

						}
						pItem.setExtraAttrs(IgawCommerceProductAttrModel.create(map));
					}
					else
					{
						throw new Exception("No extra_attrs attribute.");
					}
					items.add(pItem);
				}
				catch(Exception e)
				{
					IgawLogger.Logging(currentActivity.getApplicationContext(), IgawConstant.QA_TAG, "purchase error : invalid item = " + purchaseDataJsonString, IgawLogger.LOG_E, false);
				}
			}
			
			return items;
		} 
		catch (JSONException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}
	
	public static void purchase(String productID, double price, int currency, int paymentMethod)
	{
		currentActivity.runOnUiThread(new Runnable(){
			private String produtID = "";
			private double price = 0.0;
			private com.igaworks.commerce.IgawCommerce.Currency currency = com.igaworks.commerce.IgawCommerce.Currency.KR_KRW;
			private com.igaworks.commerce.IgawCommerce.IgawPaymentMethod paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.CreditCard;
			
			public Runnable start(String productID, double price, int currency, int paymentMethod){
				this.produtID = productID;
				this.price = price;
				
				if(currency == 1)this.currency = com.igaworks.commerce.IgawCommerce.Currency.KR_KRW;
				else if(currency == 2)this.currency = com.igaworks.commerce.IgawCommerce.Currency.US_USD;
				else if(currency == 3)this.currency = com.igaworks.commerce.IgawCommerce.Currency.JP_JPY;
				else if(currency == 4)this.currency = com.igaworks.commerce.IgawCommerce.Currency.EU_EUR;
				else if(currency == 5)this.currency = com.igaworks.commerce.IgawCommerce.Currency.UK_GBP;
				else if(currency == 6)this.currency = com.igaworks.commerce.IgawCommerce.Currency.CN_CNY;
				else if(currency == 7)this.currency = com.igaworks.commerce.IgawCommerce.Currency.TW_TWD;
				else if(currency == 8)this.currency = com.igaworks.commerce.IgawCommerce.Currency.HK_HKD;
				else this.currency = com.igaworks.commerce.IgawCommerce.Currency.KR_KRW;
				
				
				if(paymentMethod == 1)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.CreditCard;
				else if(paymentMethod == 2)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.BankTransfer;
				else if(paymentMethod == 3)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.MobilePayment;
				else if(paymentMethod == 4)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.ETC;
				else this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.ETC;
				
				return this;
			}
			
			@Override
			public void run() 
			{
				IgawAdbrix.Commerce.purchase(currentActivity.getApplicationContext(), produtID, price, currency, paymentMethod);
			}
		}.start(productID, price, currency, paymentMethod));
	}
	
	public static void purchase(String orderID, String purchaseDataJsonString,
			double discount, double deliveryCharge, int paymentMethod)
	{
		currentActivity.runOnUiThread(new Runnable(){
			private String orderID = "";
			IgawCommerceProductModel item = null;
			private double discount = 0.0;
			private double deliveryCharge = 0.0;
			
			private com.igaworks.commerce.IgawCommerce.IgawPaymentMethod paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.CreditCard;
			
			public Runnable start(String orderID, String purchaseDataJsonString,
					double discount, double deliveryCharge, int paymentMethod){
				this.orderID = orderID;
				
				Log.i("HOIIL", "product string is" + purchaseDataJsonString);
				this.item = (IgawCommerceProductModel)MakeProductFromJsonForCommerceV2(purchaseDataJsonString);
				this.discount = discount;
				this.deliveryCharge = deliveryCharge;
				
				if(paymentMethod == 1)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.CreditCard;
				else if(paymentMethod == 2)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.BankTransfer;
				else if(paymentMethod == 3)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.MobilePayment;
				else if(paymentMethod == 4)this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.ETC;
				else this.paymentMethod = com.igaworks.commerce.IgawCommerce.IgawPaymentMethod.ETC;
				
				return this;
			}
			
			@Override
			public void run() 
			{
				IgawAdbrix.Commerce.purchase(currentActivity.getApplicationContext(), orderID, item, discount, deliveryCharge, paymentMethod);
			}
		}.start(orderID, purchaseDataJsonString, discount, deliveryCharge, paymentMethod));
	}
	
}
