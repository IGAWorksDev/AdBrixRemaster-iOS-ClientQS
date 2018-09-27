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
        
        let address = "https://s3-ap-northeast-1.amazonaws.com/static.adbrix.igaworks.com/tech_support/adbrix/hybrid_web/adbrixHybrid.html"
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
          
            if let dic = Utils.getURLParmaters(url) {
                
                
                print("info :: \(url),\(schm),\(funcName),\(dic)")
                
                if ("AdBrixRM" == schm || "adbrix" == schm) {
                    
                    if (funcName.contains("purchase") || funcName.contains("refund") || funcName.contains("list_view") || funcName.contains("add_to_cart") || funcName.contains("search")) {
                        
                        isAdbrixContains = true
                        
                        var cateArr :Array<String> = Array()
                        
                        if let cate = (dic["category"] as? String) {
                            
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
                        
                        if let productId = dic["pid"], let productName = dic["pname"], let price = dic["price"], let quantity = dic["quantity"], let currencyString = dic["currency_code"] {
                            
                            let productModel = AdBrixRM.getInstance.createCommerceProductData(
                                productId: productId as! String
                                ,productName: productName as! String
                                ,price: price as! Double
                                ,quantity: quantity as! Int
                                ,discount: 0.00
                                ,currencyString: self.validCurreny(currencyString as! String)
                                ,category: AdBrixRM.getInstance.createCommerceProductCategoryDataByArray(categoryArray: cateArr)
                                ,productAttrsMap: nil
                            )
                            
                            var arr : Array<AdBrixRmCommerceProductModel> = Array()
                            arr.append(productModel)
                            
                            if funcName.contains("purchase") {
                                
                                if let orderId = dic["oid"],
                                    let deliveryCharge = dic["deliveryCharge"],
                                    let paymentMethod = dic["paymentMethod"] {
                                    
                                    AdBrixRM.getInstance.commonPurchase(
                                        orderId: orderId as! String,
                                        productInfo: arr,
                                        discount: 0.00,
                                        deliveryCharge: deliveryCharge as! Double,
                                        paymentMethod:
                                        AdBrixRM.getInstance.convertPayment(self.validPayment(paymentMethod as! String))
                                    )
                                }
                                
                              
                            }
                            else if funcName.contains("refund") {
                                if let orderId = dic["oid"], let penaltyCharge = dic["penaltyCharge"] {
                                    AdBrixRM.getInstance.commerceRefund(orderId: orderId as! String, productInfo: arr, penaltyCharge: penaltyCharge as! Double)
                                }
                                
                            }
                            else if funcName.contains("product_view") {
                                AdBrixRM.getInstance.commerceProductView(productInfo: productModel)
                            }
                            else if funcName.contains("list_view") {
                                AdBrixRM.getInstance.commerceListView(productInfo: arr)
                            }
                            else if funcName.contains("add_to_cart") {
                                AdBrixRM.getInstance.commerceAddToCart(productInfo: arr)
                            }
                            else if funcName.contains("search") {
                                if let keyword = dic["keyword"] {
                                    AdBrixRM.getInstance.commerceSearch(productInfo: arr, keyword: keyword as! String)
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
        
        
        var type = 4;
        
        for v in Constants.ABXRM_PAYMENT {
            if v.value == code {
                type = v.key
                break
            }
        }
        
        return type
    }
    
    
    
}

