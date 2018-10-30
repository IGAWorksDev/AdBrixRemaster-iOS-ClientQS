//
//  ViewController.swift
//  TestApp-IOS-Abx-RemasterHyBrid
//
//  Created by igaworks on 2018. 9. 18..
//  Copyright © 2018년 igaworks. All rights reserved.
//

import UIKit
import WebKit
import AdBrixRM
import JavaScriptCore

class ViewController: UIViewController, WKNavigationDelegate {
    
    var WKView_main: WKWebView!
    
    let ABXRM_PAYMENT: [Int: String] =
        [
            1:"CreditCard",
            2:"BankTransfer",
            3:"MobilePayment",
            4:":ETC"
    ]
    
    let ABXRM_CURRENCY: [String] =
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
    
    @IBOutlet weak var View_root: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        WKView_main = WKWebView.init()
        
        WKView_main.frame = CGRect(x: self.View_root.frame.origin.x, y: self.View_root.frame.origin.y, width: self.View_root.frame.size.width, height: self.View_root.frame.size.height)
        self.View_root.addSubview(WKView_main)
        
        WKView_main.navigationDelegate = self
        
        let address = "http://tech.ad-brix.com/adbrix_hybrid_sample_web/index.html"
//        let address = "https://s3-ap-northeast-1.amazonaws.com/static.adbrix.igaworks.com/tech_support/adbrix/hybrid_web/adbrixHybrid.html"
        
        let url = URL(string: address)
        let request = URLRequest(url: url!)
        WKView_main.load(request)
      
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }

    @available(iOS 8.0, *)
    func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
        var isAdbrixContains = false
             
        if let url = navigationAction.request.url, let schm = url.scheme, let funcName = url.host {
          
            print("info :: url-\(url),\(webView.url!), scheme-\(schm)")
            
//            info :: purchase,{
//                category = "A.B";
//                currencyCode = KRW;
//                orderid = O123;
//                productId = P123;
//                productName = ABS;
//                quantity = 1;
//                unitPrice = 123;
//            }

            if let dic = Utils.getURLParmaters(url) {
                
                if ("adbrix" == schm) {
                    
                    if (funcName.contains(Constants.FUNC_purchase) || funcName.contains(Constants.FUNC_viewList) || funcName.contains(Constants.FUNC_addToWishList) || funcName.contains(Constants.FUNC_share) || funcName.contains(Constants.FUNC_search) || funcName.contains(Constants.FUNC_productView) ||
                        funcName.contains(Constants.FUNC_addToCart)
                        ) {
                        
                        isAdbrixContains = true
                        
                        var cateArr :Array<String> = Array()
                        
                        if let cate = (dic[Constants.DIC_category] as? String) {
                            
                            let categories =  cate.components(separatedBy: ".")
                            for str in categories {
                                
                                if cateArr.count >= 5 {
                                    break
                                }
                                cateArr.append(str)
                                
                            }
                            
                        }
                        else {
                            if cateArr.count < 5 {
                                cateArr.append("")
                            }
                            
                        }
                        
                        if let productId = dic[Constants.DIC_productId], let productName = dic[Constants.DIC_productName], let price = dic[Constants.DIC_unitPrice], let quantity = dic[Constants.DIC_quantity], let currencyString = dic[Constants.DIC_currencyCode] {
                            
                            var arr : Array<AdBrixRmCommerceProductModel> = Array()
                            
                            if let priceNum = (price as? NSString), let quantityNum = (quantity as? NSString) {
                                
                                
                                
                                let productModel = AdBrixRM.getInstance.createCommerceProductData(
                                    productId: productId as! String
                                    ,productName: productName as! String
                                    ,price: Double(priceNum.integerValue)
                                    ,quantity: quantityNum.integerValue
                                    ,discount: 0.00
                                    ,currencyString: self.validCurreny(currencyString as! String)
                                    ,category: AdBrixRM.getInstance.createCommerceProductCategoryDataByArray(categoryArray: cateArr)
                                    ,productAttrsMap: nil
                                )
                                
                                arr.append(productModel)
                                
                                
                                if funcName.contains(Constants.FUNC_purchase) {
                                    
                                    if let orderId = dic[Constants.DIC_orderId] {
                                        
                                        AdBrixRM.getInstance.commonPurchase(
                                            orderId: orderId as! String,
                                            productInfo: arr,
                                            discount: 0.00,
                                            deliveryCharge: 0.00,
                                            paymentMethod:
                                            AdBrixRM.getInstance.convertPayment(self.validPayment(Constants.ABXRM_PAYMENT[1] ?? "CreditCard"))
                                        )
                                    }
                                    
                                    
                                }
                               
                                else if funcName.contains(Constants.FUNC_productView) {
                                    AdBrixRM.getInstance.commerceProductView(productInfo: productModel)
                                }
                                else if funcName.contains(Constants.FUNC_viewList) {
                                    AdBrixRM.getInstance.commerceListView(productInfo: arr)
                                }
                                else if funcName.contains(Constants.FUNC_addToCart) {
                                    AdBrixRM.getInstance.commerceAddToCart(productInfo: arr)
                                }
                                else if funcName.contains(Constants.FUNC_addToWishList) {
                                    AdBrixRM.getInstance.commerceAddToWishList(productInfo: arr[0])
                                }
                                else if funcName.contains(Constants.FUNC_share) {
                                    if let shareName = dic[Constants.DIC_sharingChannel] {
                                        AdBrixRM.getInstance.commerceShare(channel: AdBrixRM.getInstance.convertChannel(self.validSharingChannel(shareName as! String)), productInfo: arr[0])
                                    }
                                }
                                else if funcName.contains(Constants.FUNC_search) {
                                    if let keyword = dic[Constants.DIC_keyword] {
                                        AdBrixRM.getInstance.commerceSearch(productInfo: arr, keyword: keyword as! String)
                                    }
                                    
                                }
                                
                            }
                            
                            
                            
                            
                        }
                        
                    }
                    
                    
                }
            }
            
            
        }
        
        
        
        decisionHandler(isAdbrixContains ? .cancel : .allow)
        
    }
    
    
    
    @IBAction func click_toObjC(_ sender: Any) {
    }
    
    
    public func validCurreny(_ code :String) -> String {
        
        var type = "KRW";
        
        for v in Constants.ABXRM_CURRENCY {
            if v == code {
                type = v
                break
            }
        }
        
        
        return type
    }
  
    public func validPayment(_ code :String) -> Int{
        
        
        var type = 1;
        
        for v in Constants.ABXRM_PAYMENT {
            if v.value == code {
                type = v.key
                break
            }
        }
        
        return type
    }
    
    public func validSharingChannel(_ code :String) -> Int{
        
        
        var type = 1;
        
        for v in Constants.ABXRM_SHARINGCHANNEL {
            if v.value == code {
                type = v.key
                break
            }
        }
        
        return type
    }
    
    
}

