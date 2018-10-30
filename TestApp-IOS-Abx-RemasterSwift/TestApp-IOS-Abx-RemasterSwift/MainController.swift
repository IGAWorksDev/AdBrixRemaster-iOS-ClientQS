//
//  MainController.swift
//  TestApp-IOS-Abx-RemasterSwift
//
//  Created by igaworks on 2018. 2. 7..
//  Copyright © 2018년 igaworks. All rights reserved.
//

import Foundation
import UIKit
import AdBrixRM

class MainContoller : UIViewController {
    
    @IBOutlet weak var Button_event: UIButton!
    @IBOutlet weak var Button_eventSub: UIButton!
    @IBOutlet weak var Button_setAge: UIButton!
    @IBOutlet weak var Seg_setGender: UISegmentedControl!
    @IBOutlet weak var Button_login: UIButton!
    @IBOutlet weak var TextField_age: UITextField!
    @IBOutlet weak var TextField_userId: UITextField!
    @IBOutlet weak var Button_setUserproperties: UIButton!
    @IBOutlet weak var TextField_propKey: UITextField!
    @IBOutlet weak var TextField_propValue: UITextField!
    @IBOutlet weak var Button_commerceViewHome :UIButton!
    @IBOutlet weak var Button_commerceCategoryView :UIButton!
    @IBOutlet weak var Button_commerceProductView :UIButton!
    @IBOutlet weak var Button_commerceAddToCart :UIButton!
    @IBOutlet weak var Button_commerceAddToCartBulk :UIButton!
    @IBOutlet weak var Button_commerceAddToWishList :UIButton!
    @IBOutlet weak var Button_commerceReviewOrder :UIButton!
    @IBOutlet weak var Button_commerceReviewOrderBulk :UIButton!

    @IBOutlet weak var Button_commerceRefund :UIButton!
    @IBOutlet weak var Button_commerceRefundBulk :UIButton!
    @IBOutlet weak var Button_commerceSearch :UIButton!
    @IBOutlet weak var Button_commerceShare :UIButton!
    
    
    @IBOutlet weak var Button_commerceListView :UIButton!
    @IBOutlet weak var Button_commerceCartView :UIButton!
    @IBOutlet weak var Button_commercePaymentInfoAdded :UIButton!
    
    
    @IBOutlet weak var Button_commonPurchase :UIButton!
    @IBOutlet weak var Button_commonPurchaseBulk :UIButton!
    
    
    @IBOutlet weak var Button_gameLevelAchieved :UIButton!
    @IBOutlet weak var Button_gameTutorialCompleted :UIButton!
    @IBOutlet weak var Button_gameCharacterCreated :UIButton!
    @IBOutlet weak var Button_gameStageCleared :UIButton!
    
   
    
    let adBrix = AdBrixRM.getInstance
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
    }
    
    override func didReceiveMemoryWarning() {
         super.didReceiveMemoryWarning()
    }
    
    @IBAction func Click_event(_ sender: Any) {
        
        adBrix.event(eventName: "click")
       
        adBrix.event(eventName: "click", eventDateStr: self.getDateStr())
    }
    @IBAction func Click_eventSub(_ sender: Any) {
        
        let dicTest = ["click":"button"]
        adBrix.event(eventName: "detail", value: dicTest)
        
        
        //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - adBrix.AdBrixDateFormat format 준수
        //adBrix.event(eventName: "detail", value: dicTest, eventDateStr:  self.getDateStr())
        
    }
    
    
    @IBAction func Click_setAge(_ sender: Any) {
        
        if let age :String = self.TextField_age.text, age.count > 0 {
            if let ageInteger = Int(age) {
                adBrix.setAge(int: ageInteger)
            }
            
        }
        
    }
    
    @IBAction func Change_setGender(_ sender: UISegmentedControl) {
        
        let selectedSegment :Int = sender.selectedSegmentIndex
        
        adBrix.setGender(adBrixGenderType: (selectedSegment+1) == 1 ? AdBrixRM.AdBrixGenderType.Female : AdBrixRM.AdBrixGenderType.Male)
        
    }
    
    @IBAction func Click_setUserId(_ sender: Any) {
        if let id = self.TextField_userId.text {
            
            adBrix.login(userId: id)
            
           
            
            //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - adBrix.AdBrixDateFormat format 준수
           
            //adBrix.login(userId: id, eventDateStr:  self.getDateStr())
            
            //유저 로그인 초기화
            //adBrix.login(userId: "")
        }
        
    }
    
    @IBAction func Click_setUserProperties(_ sender: Any) {
        if let key = self.TextField_propKey.text {
            if let value = self.TextField_propValue.text {
                
                let dicData : [String: Any] = [
                    key : value
                ]
                
                adBrix.setUserProperties(dictionary: dicData)
            }
        }
    }
    
       
    @IBAction func click_commerceViewHome(_ sender: Any) {
        adBrix.commerceViewHome()
        
        
        //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - adBrix.AdBrixDateFormat format 준수
        //adBrix.commerceViewHome(eventDateStr:  self.getDateStr())
        
        //Order Attr 사용시
        //adBrix.commerceViewHome(orderAttr: self.getExtraAttrDic() )
        //adBrix.commerceViewHome(orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
   
    @IBAction func click_commerceCategoryView(_ sender: Any) {
        
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487401"
            ,productName: "이월특가 나염 맨투맨"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "13",
                "color" : "gray",
                "size" : "XXL"
                ]
            )
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        
        //카테고리1개
        adBrix.commerceCategoryView(category: adBrix.createCommerceProductCategoryData(category: "기획전"), productInfo: arr)
        //let formatter = DateFormatter()
        //formatter.dateFormat = adBrix.AdBrixDateFormat
        //formatter.timeZone = TimeZone(identifier: "UTC")
        //adBrix.commerceCategoryView(category: adBrix.createCommerceProductCategoryData(category: "기획전"), productInfo: arr, eventDateStr: formatter.string(from: Date()))
        
        //카테고리 1개 이상 5개 이하
        //adBrix.commerceCategoryView(category: adBrix.createCommerceProductCategoryData(category: "바겐세일", category2: "바겐세일1-1", category3: "바겐세일1-2"), productInfo: arr)
        
        //Order Attr 사용시
        //adBrix.commerceCategoryView(category: adBrix.createCommerceProductCategoryData(category: "기획전"), productInfo: arr, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceCategoryView(category: adBrix.createCommerceProductCategoryData(category: "기획전"), productInfo: arr, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
        
        
    }
    
    @IBAction func click_commerceProductView(_ sender: Any) {
        
        //가을 맞이 슬렉스 10종 특가
        let dicData : [String: String] = [
            "no" : "9",
            "color" : "black",
            "size" : "XXL"
        ]
        
        //상품 상세보기
        adBrix.commerceProductView(
                productInfo: adBrix.createCommerceProductData(
                     productId: "productId01"
                    ,productName: "productName01"
                    ,price: 10000.00
                    ,quantity: 1
                    ,discount: 5000.0
                    ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
                    ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
                    ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: dicData)
                )
        )
        
        
        let formatter = DateFormatter()
        formatter.dateFormat = adBrix.AdBrixDateFormat
        formatter.timeZone = TimeZone(identifier: "UTC")
        
        adBrix.commerceProductView(
            productInfo: adBrix.createCommerceProductData(
                productId: "productId01"
                ,productName: "productName01"
                ,price: 10000.00
                ,quantity: 1
                ,discount: 5000.0
                ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
                ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
                ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: dicData)
            )
            
        )
        
        adBrix.commerceProductView(
            productInfo: adBrix.createCommerceProductData(
                 productId: "productId01"
                ,productName: "productName01"
                ,price: 10000.00
                ,quantity: 1
                ,discount: 5000.0
                ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
                ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
                ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: dicData)
            ),
            eventDateStr: self.getDateStr()
        )
        
        //Order Attr 사용시
//        adBrix.commerceProductView(
//            productInfo: adBrix.createCommerceProductData(
//                productId: "productId01"
//                ,productName: "productName01"
//                ,price: 10000.00
//                ,quantity: 1
//                ,discount: 5000.0
//                ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
//                ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
//                ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: dicData)
//            ),
//            orderAttr: self.getExtraAttrDic()
//        )
//
//        adBrix.commerceProductView(
//            productInfo: adBrix.createCommerceProductData(
//                productId: "productId01"
//                ,productName: "productName01"
//                ,price: 10000.00
//                ,quantity: 1
//                ,discount: 5000.0
//                ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
//                ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
//                ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: dicData)
//            ),
//            orderAttr: self.getExtraAttrDic(),
//            eventDateStr: self.getDateStr()
//        )
        
    }
    
   
    @IBAction func click_commerceAddToCart(_ sender: Any) {
        
        //가을 맞이 슬렉스 10종 특가
        let dicData : [String: String] = [
            "no" : "9",
            "color" : "black",
            "size" : "XXL"
        ]
        
        let productModel = adBrix.createCommerceProductData(
            productId: "productId01"
            ,productName: "productName01"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: dicData)
        )
       
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        
        //장바구니 담기
        adBrix.commerceAddToCart(productInfo: arr)
        
//        let formatter = DateFormatter()
//        formatter.dateFormat = adBrix.AdBrixDateFormat
//        formatter.timeZone = TimeZone(identifier: "UTC")
//        adBrix.commerceAddToCart(productInfo: arr, eventDateStr: formatter.string(from: Date()))
        
        //Order Attr 사용시
        //adBrix.commerceAddToCart(productInfo: arr, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceAddToCart(productInfo: arr, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    @IBAction func click_commerceAddToCartBulk(_ sender: Any) {
        
        //가을 맞이 슬렉스 10종 특가
        let extraDict : [String: String] = [
            "no" : "9",
            "color" : "black",
            "size" : "XXL"
        ]
        
        
        let productModel = adBrix.createCommerceProductData(
             productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: extraDict)
        )
        
        //이월특가 나염 맨투맨
        let extraDict2 : [String: String] = [
            "no" : "13",
            "color" : "gray",
            "size" : "XXL"
        ]
        
        let productModel2 = adBrix.createCommerceProductData(
             productId: "5385487401"
            ,productName: "이월특가 나염 맨투맨"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "cate1")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: extraDict2)
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        
        //장바구니 담기
        adBrix.commerceAddToCart(productInfo: arr)
        
        //Order Attr 사용시
        //adBrix.commerceAddToCart(productInfo: arr, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceAddToCart(productInfo: arr, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
   
    @IBAction func click_commerceAddToWishList(_ sender: Any) {
        
        //가을 맞이 슬렉스 10종 특가
        let extraDict : [String: String] = [
            "no" : "9",
            "color" : "black",
            "size" : "XXL"
        ]
        
        
        
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: extraDict)
        )
        
        //위시리스트(관심상품) 추가
        adBrix.commerceAddToWishList(productInfo: productModel)
        
        //Order Attr 사용시
        //adBrix.commerceAddToWishList(productInfo: productModel, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceAddToWishList(productInfo: productModel, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    @IBAction func click_commerceReviewOrder(_ sender: Any) {
        
        /*
         [ 가을 맞이 슬렉스 10종 특가 1개]
         쿠폰까지 써서 배송비 3500원을 할인받음
         할인은 상품에 적용 되었음.
         */
        
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        
        //주문검토하기
        adBrix.commerceReviewOrder(orderId: "100021", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00)
        
        //Extra Attrs 사용시
        //adBrix.commerceReviewOrder(orderId: "100021", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceReviewOrder(orderId: "100021", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    @IBAction func click_commerceReviewOrderBulk(_ sender: Any) {
        
        /*
         [ 가을 맞이 슬렉스 10종 특가 1개, 이월특가 나염 맨투맨 1개] = 총 2개 상품
         쿠폰까지 써서 배송비 3500원을 할인받음
         할인은 각 상품별로 적용 되었음.
         */
        
            let productModel = adBrix.createCommerceProductData(
                productId: "5385487400"
                ,productName: "가을 맞이 슬렉스 10종 특가"
                ,price: 10000.00
                ,quantity: 1
                ,discount: 5000.0
                ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
                ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
                ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                    "no" : "9",
                    "color" : "black",
                    "size" : "XXL"
                    ]
                )
            )
        
            let productModel2 = adBrix.createCommerceProductData(
                productId: "5385487401"
                ,productName: "이월특가 나염 맨투맨"
                ,price: 10000.00
                ,quantity: 1
                ,discount: 5000.0
                ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
                ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
                ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                    "no" : "13",
                    "color" : "gray",
                    "size" : "XXL"
                    ]
                )
            )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        adBrix.commerceReviewOrder(orderId: "100021", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00)
        
        //Order Attr 사용시
        //adBrix.commerceReviewOrder(orderId: "100021", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceReviewOrder(orderId: "100021", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
   
    
    
    
    
    @IBAction func click_commerceRefund(_ sender: Any) {
        
        /* 일괄 주문 중에서 가을 맞이 슬렉스 10종 특가 1개 환불. 배송비 3500원이 청구됨. */
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
         
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        
        //주문 취소(환불)
        adBrix.commerceRefund(orderId: "290192012", productInfo: arr, penaltyCharge: 3500.00)
        
        //Order Attr 사용시
        //adBrix.commerceRefund(orderId: "290192012", productInfo: arr, penaltyCharge: 3500.00, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceRefund(orderId: "290192012", productInfo: arr, penaltyCharge: 3500.00, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    @IBAction func click_commerceRefundBulk(_ sender: Any) {
        /* 일괄 주문 중에서 가을 맞이 슬렉스 10종 특가 1개, 이월특가 나염 맨투맨 1개, 모두 환불. 배송비 미청구. */
        
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        let productModel2 = adBrix.createCommerceProductData(
            productId: "5385487401"
            ,productName: "이월특가 나염 맨투맨"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "13",
                "color" : "gray",
                "size" : "XXL"
                ]
            )
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        
        //주문 취소(환불)
        adBrix.commerceRefund(orderId: "290192012", productInfo: arr, penaltyCharge: 0.00)
        
        //Order Attr 사용시
        //adBrix.commerceRefund(orderId: "290192012", productInfo: arr, penaltyCharge: 0.00, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceRefund(orderId: "290192012", productInfo: arr, penaltyCharge: 0.00, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
   
    @IBAction func click_commerceSearch(_ sender: Any) {
        
        /* 나이키 운동화 검색*/
        let productModel = adBrix.createCommerceProductData(
            productId: "n24jsda922"
            ,productName: "[나이키] 나이키NIKE WMNS AIR MAX THEA WHITE womens 599409-103"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "[나이키]운동화기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [:])
        )
        
        let productModel2 = adBrix.createCommerceProductData(
            productId: "saf323dsa23d4f"
            ,productName: "[나이키] 나이키NIKE WMNS AIR MAX THEA WHITE womens 599409-103"
            ,price: 105000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "[나이키]운동화기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [:])
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        
        adBrix.commerceSearch(productInfo: arr, keyword: "나이키 운동화")
        
        //Order Attr 사용시
        //adBrix.commerceSearch(productInfo: arr, keyword: "나이키 운동화", orderAttr: self.getExtraAttrDic())
        //adBrix.commerceSearch(productInfo: arr, keyword: "나이키 운동화", orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    @IBAction func click_commerceShare(_ sender: Any) {
        
        /* 가을 맞이 슬렉스 10종 특가 상품을 카카오톡으로 공유*/
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        adBrix.commerceShare(channel: AdBrixRM.AdBrixSharingChannel.AdBrixSharingKakaoTalk, productInfo: productModel)
        
        //Order Attr 사용시
        //adBrix.commerceShare(channel: AdBrixRM.AdBrixSharingChannel.AdBrixSharingKakaoTalk, productInfo: productModel, orderAttr: self.getExtraAttrDic())
        //adBrix.commerceShare(channel: AdBrixRM.AdBrixSharingChannel.AdBrixSharingKakaoTalk, productInfo: productModel, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    @IBAction func click_commerceListView(_ sender: Any) {
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        let productModel2 = adBrix.createCommerceProductData(
            productId: "5385487401"
            ,productName: "이월특가 나염 맨투맨"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "13",
                "color" : "gray",
                "size" : "XXL"
                ]
            )
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        adBrix.commerceListView(productInfo: arr)
    }
    
    @IBAction func click_commerceCartView(_ sender: Any) {
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        let productModel2 = adBrix.createCommerceProductData(
            productId: "5385487401"
            ,productName: "이월특가 나염 맨투맨"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "13",
                "color" : "gray",
                "size" : "XXL"
                ]
            )
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        adBrix.commerceCartView(productInfo: arr)
    }
    
    @IBAction func click_commercePaymentInfoAdded(_ sender: Any) {
        adBrix.commercePaymentInfoAdded(paymentInfoAttr: [
            "creditcard" : "kbcard"])
    }
    
    @IBAction func click_commonPurchase(_ sender: Any) {
        
        /*
         [ 가을 맞이 슬렉스 10종 특가 1개 ] = 총 1개 상품
         쿠폰까지 써서 배송비 3500원을 할인받음
         할인은 상품에 적용 되었음.
         */
        
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        
        //상품 결제 - 신용카드
        adBrix.commonPurchase(orderId: "290192012", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, paymentMethod: AdBrixRM.AdbrixPaymentMethod.CreditCard)
        
        //Order Attr 사용시
        //adBrix.commonPurchase(orderId: "290192012", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, paymentMethod: AdBrixRM.AdbrixPaymentMethod.CreditCard, orderAttr: self.getExtraAttrDic())
        //adBrix.commonPurchase(orderId: "290192012", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, paymentMethod: AdBrixRM.AdbrixPaymentMethod.CreditCard, orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    @IBAction func click_commonPurchaseBulk(_ sender: Any) {
        
        /*
         [ 가을 맞이 슬렉스 10종 특가 1개, 이월특가 나염 맨투맨 1개 ] = 총 2개 상품
         쿠폰까지 써서 배송비 3500원을 할인받음
         할인은 각 상품에 적용 되었음.
         */
        
        let productModel = adBrix.createCommerceProductData(
            productId: "5385487400"
            ,productName: "가을 맞이 슬렉스 10종 특가"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전", category2: "썸머페스티벌")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "9",
                "color" : "black",
                "size" : "XXL"
                ]
            )
        )
        
        let productModel2 = adBrix.createCommerceProductData(
            productId: "5385487401"
            ,productName: "이월특가 나염 맨투맨"
            ,price: 10000.00
            ,quantity: 1
            ,discount: 5000.0
            ,currencyString: adBrix.getCurrencyStringByAdBrixCurrencyType(AdBrixRM.AdBrixCurrencyType.KRW)
            ,category: adBrix.createCommerceProductCategoryData(category: "기획전")
            ,productAttrsMap: adBrix.createCommerceProductAttrData(dictionary: [
                "no" : "13",
                "color" : "gray",
                "size" : "XXL"
                ]
            )
        )
        
//        var model: AdBrixRmCommerceProductAttrModel = AdBrixRmCommerceProductAttrModel()
//        model.setAttr()
//        model.setAttr()
        
        var arr : Array<AdBrixRmCommerceProductModel> = Array()
        arr.append(productModel)
        arr.append(productModel2)
        
        //상품 결제 - 모바일 결제
        adBrix.commonPurchase(orderId: "290192012", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, paymentMethod:
            AdBrixRM.AdbrixPaymentMethod.CreditCard
        )
        
        //Order Attr 사용시
        //adBrix.commonPurchase(orderId: "290192012", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, paymentMethod:AdBrixRM.AdbrixPaymentMethod.CreditCard,orderAttr: self.getExtraAttrDic())
        
        //adBrix.commonPurchase(orderId: "290192012", productInfo: arr, discount: 0.00, deliveryCharge: 3500.00, paymentMethod:AdBrixRM.AdbrixPaymentMethod.CreditCard,orderAttr: self.getExtraAttrDic(), eventDateStr: self.getDateStr())
    }
    
    
    
    
    @IBAction func click_gameLevelAchieved(_ sender: Any) {
        adBrix.gameLevelAchieved(level: 15)
    }
    
    @IBAction func click_gameTutorialCompleted(_ sender: Any) {
        adBrix.gameTutorialCompleted(isSkip: false)
    }
    
    @IBAction func click_gameCharacterCreated(_ sender: Any) {
        adBrix.gameCharacterCreated()
        adBrix.gameCharacterCreated(gameInfoAttr: [
            "nickname" : "adbrixer",
            ])
    }
    
    @IBAction func click_stageCleared(_ sender: Any) {
        adBrix.gameStageCleared(stageName: "1-1")
        adBrix.gameStageCleared(stageName: "1-1", gameInfoAttr: [
            "stage_redeem" : "none",
            ])
//        
//        adBrix.commonSignUp(channel: AdBrixRM.AdBrixSignUpChannel.AdBrixSignUpKakaoChannel)
//        adBrix.commonUseCredit(commonAttr: ["gold":"100"])
//        adBrix.commonAppUpdate(prev_ver: "1.0", curr_ver: "1.1")
//        adBrix.commonInvite(channel: AdBrixRM.AdBrixInviteChannel.AdBrixInviteLineChannel)
    }
    
    func getDateStr() -> String {
        let formatter = DateFormatter()
        formatter.dateFormat = adBrix.AdBrixDateFormat
        formatter.timeZone = TimeZone(identifier: "UTC")
        return formatter.string(from: Date())
    }
    
    func getExtraAttrDic() -> Dictionary<String, Any> {
        return [
            "key1" : "value1",
            "key2" : "value2"
        ]
    }
}
