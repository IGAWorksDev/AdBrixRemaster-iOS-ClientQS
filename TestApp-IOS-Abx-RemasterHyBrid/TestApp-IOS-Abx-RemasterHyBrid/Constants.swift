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
    
    @objc
    public static let ABXRM_PAYMENT: [Int: String] =
        [
            1:"CreditCard",
            2:"BankTransfer",
            3:"MobilePayment",
            4:":ETC"
    ]
    
    @objc
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
    
}
