//
//  Constants.swift
//  TestApp-IOS-Abx-RemasterHyBrid
//
//  Created by igaworks on 2018. 9. 19..
//  Copyright © 2018년 igaworks. All rights reserved.
//

import Foundation

@objc
public class Constants : NSObject {
    
    public static let getInstance : Constants  = Constants()
    
    @objc
    public class func sharedInstance() -> Constants {
        return Constants.getInstance
    }
    
    private override init() {}
    
    public static let ABXRM_PAYMENT: [Int: String] =
        [
            1:"CreditCard",
            2:"BankTransfer",
            3:"MobilePayment",
            4:":ETC"
    ]
    
    public static let ABXRM_SHARINGCHANNEL: [Int: String] =
        [
            1:"Facebook"
            ,2:"KakaoTalk"
            ,3:"KakaoStory"
            ,4:"Line"
            ,5:"WhatsApp"
            ,6:"QQ"
            ,7:"WeChat"
            ,8:"SMS"
            ,9:"Email"
            ,10:"CopyUrl"
            ,11:"ETC"
    ]
    
    public static let ABXRM_CURRENCY: [String] =
        [
            "KRW",
            "USD",
            "JPY",
            "EUR",
            "GBP",
            "CNY",
            "TWD",
            "HKD",
            "IDR",
            "INR",
            "RUB",
            "THB",
            "VND",
            "MYR"
    ]
    
    public static let FUNC_search = "search"
    
    public static let FUNC_share = "share"
    
    public static let FUNC_addToWishList = "addToWishList"
    
    public static let FUNC_addToCart = "addToCart"
    
    public static let FUNC_viewList = "viewList"
    
    public static let FUNC_productView = "productView"
    
    public static let FUNC_purchase = "purchase"
    
    public static let DIC_viewList = "viewList"
    
    public static let DIC_keyword = "keyword"
    
    public static let DIC_sharingChannel = "sharingChannel"
    
    public static let DIC_orderId = "orderId"
    
    public static let DIC_productId = "productId"
    
    public static let DIC_productName = "productName"
    
    public static let DIC_unitPrice = "unitPrice"
    
    
    public static let DIC_quantity = "quantity"
    
    public static let DIC_currencyCode = "currencyCode"
    
    public static let DIC_category = "category"
    
    
    
}
