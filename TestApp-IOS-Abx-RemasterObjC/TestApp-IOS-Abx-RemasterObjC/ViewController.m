//
//  ViewController.m
//  TestApp-IOS-Abx-RemasterObjC
//
//  Created by igaworks on 2018. 2. 6..
//  Copyright © 2018년 igaworks. All rights reserved.
//

#import "ViewController.h"
#import <AdBrixRM/AdBrixRM-Swift.h>
//#import <AdBrixRM/AdBrixRM.h>

@interface ViewController ()
@property (nonatomic) AdBrixRM* adBrix;
@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setSetup];
    _adBrix = [AdBrixRM sharedInstance];
//    adBrix = [AdBrixRM sharedInstance];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void) setSetup {
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(dismissKeyboard)];
    
    [self.view addGestureRecognizer:tap];
    
}


- (IBAction)click_event:(id)sender {
   
    //Data만 전송
    [_adBrix eventWithEventName:@"objcEvent"];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(NSDate) 전송
    //[_adBrix eventWithEventName:@"objcEventNDate" eventDate:[NSDate date]];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
//    NSDateFormatter *dateFormatter=[[NSDateFormatter alloc] init];
//    [dateFormatter setDateFormat:[_adBrix AdBrixDateFormat]];
    //[_adBrix eventWithEventName:@"objcEventNDateStr" eventDateStr:[dateFormatter stringFromDate:[NSDate date]]];
}

- (IBAction)click_eventSub:(id)sender {
    
    //Data만 전송
//    NSMutableDictionary *evtDic = [NSMutableDictionary dictionary];
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:
                            @"testValue",@"testKey"
                          , @"testValue2",@"testKey1"
                          , nil];
    
//    NSString *keys = @"testKey";
//
//    for (int i = 0; i<130; i++) {
//        [evtDic setValue:@"testValue" forKey:[keys stringByAppendingString:[@(i) stringValue]]];
//    }
    
    [_adBrix eventWithEventName:@"objcEvent" value:dict];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(NSDate) 전송
    //[_adBrix eventWithEventName:@"objcEventNDate" value:dict eventDate:[NSDate date]];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix eventWithEventName:@"objcEventNDate" value:dict eventDateStr:[self getDateStr]];
    
}



- (IBAction)click_setAge:(id)sender {
     [_adBrix setAgeWithInt:[_TextField_age.text intValue]];
}
- (IBAction)change_gender:(UISegmentedControl *)sender {
    
    if (sender != nil) {
        NSInteger selectedSegment = sender.selectedSegmentIndex;
        [_adBrix setGenderWithAdBrixGenderType:(selectedSegment+1) == 1 ? AdBrixGenderTypeFemale : AdBrixGenderTypeMale];
    
    }
  
}

- (IBAction)click_login:(id)sender {
    
    //Data만 전송
    [_adBrix loginWithUserId:_TextField_userId.text];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix loginWithUserId:_TextField_userId.text eventDateStr:[self getDateStr]];
   
    //유저 로그인 초기화
    //[_adBrix loginWithUserId:@""];
}

- (IBAction)click_setUserProp:(id)sender {
    
    NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:_UITextField_propValue.text,_UITextField_propKey.text, nil];
    

    //NSDictionary *dictPrev = [_adBrix getUserProperties];
    
    [_adBrix setUserPropertiesWithDictionary:dict];
    
    
}

- (IBAction)click_commerceViewHome:(id)sender {
    [_adBrix commerceViewHome];
    
    //with extra dictionary
    //[_adBrix commerceViewHomeWithCommerceExtraAttr:commerceExtraDict];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix commerceViewHomeWithEventDateStr:[self getDateStr]];
    
   
    
    //Order Attr 사용시
    //[_adBrix commerceViewHomeWithCommerceExtraAttr:[self getExtraDic]];
    //[_adBrix commerceViewHomeWithCommerceExtraAttr:[self getExtraDic] eventDateStr:[self getDateStr]];
    
}
- (IBAction)click_commerceCategoryView:(id)sender {
    
    AdBrixRmCommerceProductModel *productModel = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                      productName:@"이월특가 나염 맨투맨"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                         category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                    productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                        @"9", @"no",
                                                                                                                                                        @"black", @"color",
                                                                                                                                                        @"XXL", @"size"
                                                                                                                                                        , nil]
                                                                                                   ]
                                                   ];
    
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel];
    
    //카테고리 [기획전]을 열었을때
    [_adBrix commerceCategoryViewWithCategory:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"] productInfo: productArray];
    
    //카테고리 [바겐세일]을 열었을때
    [_adBrix commerceCategoryViewWithCategory:[_adBrix createCommerceProductCategoryDataWithCategory:@"바겐세일" category2:@"바겐세일1-1" category3:@"바겐세일1-2"] productInfo: productArray];
    
   
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix commerceCategoryViewWithCategory:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"] productInfo: productArray eventDateStr:[self getDateStr]];
    
    //Order Attr 사용시
    //[_adBrix commerceCategoryViewWithCategory:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"] productInfo: productArray orderAttr: [self getExtraDic]];
    //[_adBrix commerceCategoryViewWithCategory:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"] productInfo: productArray orderAttr: [self getExtraDic] eventDateStr:[self getDateStr]];
}
- (IBAction)click_commerceProductView:(id)sender {
    
    //가을 맞이 슬렉스 10종 특가
    NSDictionary *extraDict = [NSDictionary dictionaryWithObjectsAndKeys:
                                   @"9", @"no",
                                   @"black", @"color",
                                   @"XXL", @"size"
                                    , nil];
    
    AdBrixRmCommerceProductModel *productModel = [
                                                  _adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                  productName:@"가을 맞이 슬렉스 10종 특가"
                                                  price:10000.00
                                                  quantity:1
                                                  discount:1000.00
                                                  currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                  category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:extraDict]
                                                  ];
    
    
    //상품 상세보기
    [_adBrix commerceProductViewWithProductInfo:productModel];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix commerceProductViewWithProductInfo:productModel eventDateStr:[self getDateStr]];
    
    //Order Attr 사용시
    //[_adBrix commerceProductViewWithProductInfo:productModel orderAttr:[self getExtraDic]];
    //[_adBrix commerceProductViewWithProductInfo:productModel orderAttr:[self getExtraDic] eventDateStr:[self getDateStr]];
}

- (IBAction)click_commerceAddToCart:(id)sender {
    
    //가을 맞이 슬렉스 10종 특가
    NSDictionary *extraDict = [NSDictionary dictionaryWithObjectsAndKeys:
                               @"9", @"no",
                               @"black", @"color",
                               @"XXL", @"size"
                               , nil];
    
    AdBrixRmCommerceProductModel *productModel = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                   productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                 price:10000.00
                                                                              quantity:1
                                                                              discount:1000.00
                                                                        currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                              category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                         productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:extraDict]
                                        ];
    
    //NSMutableArray방식
    //NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    //[productArray addObject:productModel];
    //[productArray addObject:productModel2];
    
    //NSArray방식
    NSArray *productArray = [[NSArray alloc] initWithObjects:productModel, nil];
    [_adBrix commerceAddToCartWithProductInfo:productArray];
    
   
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix commerceAddToCartWithProductInfo:productArray eventDateStr:[self getDateStr]];
    
    //Order Attr 사용시
    //[_adBrix commerceAddToCartWithProductInfo:productArray orderAttr:[self getExtraDic]];
    //[_adBrix commerceAddToCartWithProductInfo:productArray orderAttr:[self getExtraDic] eventDateStr:[self getDateStr]];
     
}

- (IBAction)click_commerceAddToCartBulk:(id)sender {
    
    //가을 맞이 슬렉스 10종 특가
    NSDictionary *productExtraDict = [NSDictionary dictionaryWithObjectsAndKeys:
                               @"9", @"no",
                               @"black", @"color",
                               @"XXL", @"size"
                               , nil];
    
    AdBrixRmCommerceProductModel *productModel = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                   productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                  price:10000.00
                                                                                quantity:1
                                                                                discount:1000.00
                                                                         currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                               category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                          productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:productExtraDict]
                                         ];
    
    //이월특가 나염 맨투맨
    NSDictionary *productExtraDict2 = [NSDictionary dictionaryWithObjectsAndKeys:
                               @"13", @"no",
                               @"gray", @"color",
                               @"XXL", @"size"
                               , nil];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                    productName:@"이월특가 나염 맨투맨"
                                                                                          price:10000.00
                                                                                       quantity:1
                                                                                       discount:1000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:productExtraDict2]
                                         ];
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel];
    [productArray addObject:productModel2];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel,productModel2, nil];
    
    //장바구니 담기
    [_adBrix commerceAddToCartWithProductInfo:productArray];
    
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix commerceAddToCartWithProductInfo:productArray eventDateStr:[self getDateStr]];
    
    //Order Attr 사용시
    //[_adBrix commerceAddToCartWithProductInfo:productArray orderAttr:[self getExtraDic]];
    //[_adBrix commerceAddToCartWithProductInfo:productArray orderAttr:[self getExtraDic] eventDateStr:[self getDateStr]];
    
 
}

- (IBAction)click_commerceAddToWishList:(id)sender {
    
    //가을 맞이 슬렉스 10종 특가
    NSDictionary *extraDict = [NSDictionary dictionaryWithObjectsAndKeys:
                               @"9", @"no",
                               @"black", @"color",
                               @"XXL", @"size"
                               , nil];
    
    AdBrixRmCommerceProductModel *productModel = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                   productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                         price:10000.00
                                                                                      quantity:1
                                                                                      discount:5000.00
                                                                                currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                      category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                 productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:extraDict]
                                                ];
    
    //위시리스트(관심상품) 추가
    [_adBrix commerceAddToWishListWithProductInfo:productModel];
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    //[_adBrix commerceAddToWishListWithProductInfo:productModel eventDateStr:[self getDateStr]];
    
    //Order Attr 사용시
    //[_adBrix commerceAddToWishListWithProductInfo:productModel orderAttr:[self getExtraDic]];
    //[_adBrix commerceAddToWishListWithProductInfo:productModel orderAttr:[self getExtraDic] eventDateStr:[self getDateStr]];
    
}
- (IBAction)click_commerceReviewOrder:(id)sender {
    
    /*
     [ 가을 맞이 슬렉스 10종 특가 1개]
     쿠폰까지 써서 배송비 3500원을 할인받음
     할인은 상품에 적용 되었음.
     */
    
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                    productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                          price:10000.00
                                                                                       quantity:1
                                                                                       discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                         @"9", @"no",
                                                                                                         @"black", @"color",
                                                                                                         @"XXL", @"size"
                                                                                                         , nil]
                                                                                                 ]
                                                 ];
    
//    AdBrixRmCommerceProductModel *productModel3 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
//                                                                                      productName:@"가을 맞이 슬렉스 10종 특가"
//                                                                                            price:10000.00
//                                                                                         quantity:1
//                                                                                         discount:5000.00
//                                                                                   currencyString:nil
//                                                                                         category:nil
//                                                                                    productAttrsMap:nil
//                                                   ];
    
    
    
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1, nil];
    
    //주문검토하기
    [_adBrix commerceReviewOrderWithOrderId:@"100021"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
    ];
    
    /*
     
   
     
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    [_adBrix commerceReviewOrderWithOrderId:@"100021"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
                               eventDateStr:[self getDateStr]
    ];
    
    */
    
    
    
    //Order Attr 사용시
    /*
     
    [_adBrix commerceReviewOrderWithOrderId:@"100021"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
                            orderAttr:[self getExtraDic]
     ];
    [_adBrix commerceReviewOrderWithOrderId:@"100021"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
                          orderAttr:[self getExtraDic]
                               eventDateStr:[self getDateStr]
     ];
     
     */
}

- (IBAction)click_commerceReviewOrderBulk:(id)sender {
    /*
     [ 가을 맞이 슬렉스 10종 특가 1개, 이월특가 나염 맨투맨 1개] = 총 2개 상품
     쿠폰까지 써서 배송비 3500원을 할인받음
     할인은 각 상품별로 적용 되었음.
     */
    
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                    productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                          price:10000.00
                                                                                       quantity:1
                                                                                       discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                         @"9", @"no",
                                                                                                         @"black", @"color",
                                                                                                         @"XXL", @"size"
                                                                                                         , nil]
                                                                                                 ]
                                                 ];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                    productName:@"이월특가 나염 맨투맨"
                                                                                          price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                        @"9", @"no",
                                                                                                        @"black", @"color",
                                                                                                        @"XXL", @"size"
                                                                                                        , nil]
                                                                                                 ]
                                                 ];
    
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    [productArray addObject:productModel2];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1, productModel2, nil];
    
    //주문검토하기
    [_adBrix commerceReviewOrderWithOrderId:@"30290121"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00];
    
    /*
     
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    [_adBrix commerceReviewOrderWithOrderId:@"30290121"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
                               eventDateStr:[self getDateStr]
    ];
    
    */
    
    
    //Order Attr 사용시
    /*
     
    [_adBrix commerceReviewOrderWithOrderId:@"30290121"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
                            orderAttr:[self getExtraDic]
     ];
    
    [_adBrix commerceReviewOrderWithOrderId:@"30290121"
                                productInfo:productArray
                                   discount:0.00
                             deliveryCharge:3500.00
                          orderAttr:[self getExtraDic]
                               eventDateStr:[self getDateStr]
     ];
     
     */
}



- (IBAction)click_commerceRefund:(id)sender {
    
    /* 일괄 주문 중에서 가을 맞이 슬렉스 10종 특가 1개 환불. 배송비 3500원이 청구됨. */
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                    productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                          price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                      @"9", @"no",
                                                                                                                                                      @"black", @"color",
                                                                                                                                                      @"XXL", @"size"
                                                                                                                                                      , nil]
                                                                                                 ]
                                                 ];
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1, nil];
    
    //주문 취소(환불)
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:3500.00];
    /*
     
   
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:3500.00
                          eventDateStr:[self getDateStr]
    ];
    
    */
    
    //Order Attr 사용시
    /*
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:3500.00
                     orderAttr:[self getExtraDic]
     ];
    
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:3500.00
                     orderAttr:[self getExtraDic]
                          eventDateStr:[self getDateStr]
     ];
     */
}

- (IBAction)click_commerceRefundBulk:(id)sender {
    /* 일괄 주문 중에서 가을 맞이 슬렉스 10종 특가 1개, 이월특가 나염 맨투맨 1개, 모두 환불. 배송비 미청구. */
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                    productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                          price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                      @"9", @"no",
                                                                                                                                                      @"black", @"color",
                                                                                                                                                      @"XXL", @"size"
                                                                                                                                                      , nil]
                                                                                                 ]
                                                 ];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                    productName:@"이월특가 나염 맨투맨"
                                                                                          price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                      @"9", @"no",
                                                                                                                                                      @"black", @"color",
                                                                                                                                                      @"XXL", @"size"
                                                                                                                                                      , nil]
                                                                                                 ]
                                                 ];
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    [productArray addObject:productModel2];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1, productModel2, nil];
    
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:0.00];
    
    /*
   
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:0.00
                          eventDateStr:[self getDateStr]
    ];
    
    */
    
    //Order Attr 사용시
    /*
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:0.00
                     orderAttr:[self getExtraDic]
     ];
    
    [_adBrix commerceRefundWithOrderId:@"290192012"
                           productInfo:productArray
                         penaltyCharge:0.00
                     orderAttr:[self getExtraDic]
                          eventDateStr:[self getDateStr]
     ];
     */
}

- (IBAction)click_commerceSearch:(id)sender {
    
    /* 나이키 운동화 검색*/
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"n24jsda922"
                                                                                    productName:@"[나이키] 나이키NIKE WMNS AIR MAX THEA WHITE womens 599409-103"
                                                                                          price:105000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"[나이키]운동화기획전"]
                                                                                  productAttrsMap:nil
                                                 ];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"saf323dsa23d4f"
                                                                                    productName:@"[나이키] 나이키NIKE WMNS AIR MAX THEA WHITE womens 599409-103"
                                                                                          price:105000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"[나이키]운동화기획전"]
                                                                                  productAttrsMap:nil
                                                 ];
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    [productArray addObject:productModel2];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1, productModel2, nil];
    
    [_adBrix commerceSearchWithProductInfo:productArray
                                   keyword:@"나이키 운동화"];
    
    /*
    
    
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    [_adBrix commerceSearchWithProductInfo:productArray
                                   keyword:@"나이키 운동화"
                              eventDateStr:[self getDateStr]
    ];
    
    */
    
    //Order Attr 사용시
    /*
    [_adBrix commerceSearchWithProductInfo:productArray
                                   keyword:@"나이키 운동화"
                         orderAttr:[self getExtraDic]
     ];
    
    [_adBrix commerceSearchWithProductInfo:productArray
                                   keyword:@"나이키 운동화"
                         orderAttr:[self getExtraDic]
                              eventDateStr:[self getDateStr]
     ];
     */
    
}
- (IBAction)click_commerceShare:(id)sender {
    
    /* 가을 맞이 슬렉스 10종 특가 상품을 카카오톡으로 공유*/
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                    productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                          price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                 currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                       category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                      @"9", @"no",
                                                                                                                                                      @"black", @"color",
                                                                                                                                                      @"XXL", @"size"
                                                                                                                                                      , nil]
                                                                                                 ]
                                                 ];
 
    [_adBrix commerceShareWithChannel:AdBrixSharingChannelAdBrixSharingKakaoTalk
                          productInfo:productModel1];
    
    /*
     
   
    //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
    [_adBrix commerceShareWithChannel:AdBrixSharingChannelAdBrixSharingKakaoTalk
                          productInfo:productModel1 eventDateStr:[self getDateStr]
    ];
    
    */
    
    //Order Attr 사용시
    /*
    [_adBrix commerceShareWithChannel:AdBrixSharingChannelAdBrixSharingKakaoTalk
                          productInfo:productModel1
                    orderAttr:[self getExtraDic]
     ];
    
    [_adBrix commerceShareWithChannel:AdBrixSharingChannelAdBrixSharingKakaoTalk
                          productInfo:productModel1
                    orderAttr:[self getExtraDic]
                         eventDateStr:[self getDateStr]
     ];
     */
}


// MARK -- just util logic not relate AdBrix

- (void) animateTextField: (UITextField*) textField up: (BOOL) up{
    int txtPosition = (textField.frame.origin.y - 140);
    const int movementDistance = (txtPosition < 0 ? 0 : txtPosition); // tweak as needed
    const float movementDuration = 0.3f; // tweak as needed
    
    int movement = (up ? -movementDistance : movementDistance);
    
    [UIView beginAnimations: @"anim" context: nil];
    [UIView setAnimationBeginsFromCurrentState: YES];
    [UIView setAnimationDuration: movementDuration];
    self.view.frame = CGRectOffset(self.view.frame, 0, movement);
    [UIView commitAnimations];
}

- (void)textFieldDidBeginEditing:(UITextField *)textField{
    [self animateTextField: textField up: YES];
}

- (void)textFieldDidEndEditing:(UITextField *)textField{
    [self animateTextField: textField up: NO];
}

- (BOOL)textFieldShouldReturn:(UITextField *)theTextField {
    [theTextField resignFirstResponder];
    return YES;
}

- (void) dismissKeyboard {
    [self.view endEditing:YES];
}

    
- (NSString *)getDateStr
{
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    NSTimeZone *timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
    
    [dateFormatter setTimeZone:timeZone];
    [dateFormatter setDateFormat:[_adBrix AdBrixDateFormat]];
    dateFormatter.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"en_US"];
    NSString *dateString = [dateFormatter stringFromDate:[NSDate date]];
    
    return dateString;
}

- (NSDictionary *) getExtraDic {
    return [NSDictionary dictionaryWithObjectsAndKeys:
            @"val1", @"key1",
            @"val2", @"key2"
            , nil];
}

- (IBAction)click_commerceListView:(id)sender {
    
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                      productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                         category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                        @"9", @"no",
                                                                                                                                                        @"black", @"color",
                                                                                                                                                        @"XXL", @"size"
                                                                                                                                                        , nil]
                                                                                                   ]
                                                   ];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                      productName:@"이월특가 나염 맨투맨"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:nil
                                                                                         category:nil
                                                                                  productAttrsMap:nil
                                                   ];
    
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    [productArray addObject:productModel2];
    
    [_adBrix commerceListViewWithProductInfo:productArray];

//    [_adBrix commerceListViewWithProductInfo:productArray orderAttr:[self getExtraDic]];
    
}
- (IBAction)click_commerceCartView:(id)sender {
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                      productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                         category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                        @"9", @"no",
                                                                                                                                                        @"black", @"color",
                                                                                                                                                        @"XXL", @"size"
                                                                                                                                                        , nil]
                                                                                                   ]
                                                   ];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                      productName:@"이월특가 나염 맨투맨"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:nil
                                                                                         category:nil
                                                                                  productAttrsMap:nil
                                                   ];
    
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    [productArray addObject:productModel2];
    
    [_adBrix commerceCartViewWithProductInfo:productArray];
}
- (IBAction)click_commercePaymentInfoAdded:(id)sender {
    
    [_adBrix commercePaymentInfoAddedWithPaymentInfoAttr:[NSDictionary dictionaryWithObjectsAndKeys:
                                                          @"kbcard", @"creditcard"
                                                          , nil]];
}


- (IBAction)click_commonPurchase:(id)sender {
    /*
     [ 가을 맞이 슬렉스 10종 특가 1개 ] = 총 1개 상품
     쿠폰까지 써서 배송비 3500원을 할인받음
     할인은 상품에 적용 되었음.
     */
    
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                      productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:3500.00
                                                                                   currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                         category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                        @"9", @"no",
                                                                                                                                                        @"black", @"color",
                                                                                                                                                        @"XXL", @"size"
                                                                                                                                                        , nil]
                                                                                                   ]
                                                   ];
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1, nil];
    
    //상품 결제 - 신용카드
    [_adBrix commonPurchaseWithOrderId:@"290192012"
                             productInfo:productArray
                                discount:0.00
                          deliveryCharge:3500.00
                           paymentMethod:AdbrixPaymentMethodCreditCard
     ];
    
    
    /*
     
     
     //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
     [_adBrix commonPurchaseWithOrderId:@"290192012"
     productInfo:productArray
     discount:0.00
     deliveryCharge:3500.00
     paymentMethod:AdbrixPaymentMethodCreditCard
     eventDateStr:[self getDateStr]
     ];
     
     */
    
    //Order Attr 사용시
    /*
     [_adBrix commonPurchaseWithOrderId:@"290192012"
     productInfo:productArray
     discount:0.00
     deliveryCharge:3500.00
     paymentMethod:AdbrixPaymentMethodCreditCard
     orderAttr:[self getExtraDic]
     ];
     
     [_adBrix commonPurchaseWithOrderId:@"290192012"
     productInfo:productArray
     discount:0.00
     deliveryCharge:3500.00
     paymentMethod:AdbrixPaymentMethodCreditCard
     orderAttr:[self getExtraDic]
     eventDateStr:[self getDateStr]
     ];
     */
}
- (IBAction)click_commonPurchaseBulk:(id)sender {
    
    /*
     [ 가을 맞이 슬렉스 10종 특가 1개, 이월특가 나염 맨투맨 1개 ] = 총 2개 상품
     쿠폰까지 써서 배송비 3500원을 할인받음
     할인은 각 상품에 적용 되었음.
     */
    
    AdBrixRmCommerceProductModel *productModel1 = [_adBrix createCommerceProductDataWithProductId:@"5385487400"
                                                                                      productName:@"가을 맞이 슬렉스 10종 특가"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:[_adBrix getCurrencyString:AdBrixCurrencyTypeKRW]
                                                                                         category:[_adBrix createCommerceProductCategoryDataWithCategory:@"기획전"]
                                                                                  productAttrsMap:[_adBrix createCommerceProductAttrDataWithDictionary:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                                                                                                        @"9", @"no",
                                                                                                                                                        @"black", @"color",
                                                                                                                                                        @"XXL", @"size"
                                                                                                                                                        , nil]
                                                                                                   ]
                                                   ];
    
    AdBrixRmCommerceProductModel *productModel2 = [_adBrix createCommerceProductDataWithProductId:@"5385487401"
                                                                                      productName:@"이월특가 나염 맨투맨"
                                                                                            price:10000.00
                                                                                         quantity:1
                                                                                         discount:5000.00
                                                                                   currencyString:nil
                                                                                         category:nil
                                                                                  productAttrsMap:nil
                                                   ];
    
    
    //NSMutableArray방식
    NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
    [productArray addObject:productModel1];
    [productArray addObject:productModel2];
    
    //NSArray방식
    //NSArray *productArray = [[NSArray alloc] initWithObjects:productModel1,productModel2, nil];
    
    //상품 결제 - 모바일 결제
    [_adBrix commonPurchaseWithOrderId:@"290192012"
                             productInfo:productArray
                                discount:10000.00
                          deliveryCharge:3500.00
                           paymentMethod:AdbrixPaymentMethodCreditCard
     ];
    
    /*
     
     
     
     //Data + 클라이언트 앱 기준 이벤트 시각(formatted Date String) 전송 - AdBrixDateFormat format 준수
     [_adBrix commonPurchaseWithOrderId:@"290192012"
     productInfo:productArray
     discount:0.00
     deliveryCharge:3500.00
     paymentMethod:AdbrixPaymentMethodCreditCard
     eventDateStr:[self getDateStr]
     ];
     
     */
    
    
    //Order Attr 사용시
    /*
     [_adBrix commonPurchaseWithOrderId:@"290192012"
     productInfo:productArray
     discount:10000.00
     deliveryCharge:3500.00
     paymentMethod:AdbrixPaymentMethodCreditCard
     orderAttr:[self getExtraDic]
     ];
     
     [_adBrix commonPurchaseWithOrderId:@"290192012"
     productInfo:productArray
     discount:10000.00
     deliveryCharge:3500.00
     paymentMethod:AdbrixPaymentMethodCreditCard
     orderAttr:[self getExtraDic]
     eventDateStr:[self getDateStr]
     ];
     */
}
- (IBAction)click_levelAchieved:(id)sender {
    [_adBrix gameLevelAchievedWithLevel:15];
}
- (IBAction)click_tutorialCompleted:(id)sender {
    [_adBrix gameTutorialCompletedWithIsSkip:false];
}
- (IBAction)click_characterCreated:(id)sender {
    [_adBrix gameCharacterCreated];
    [_adBrix gameCharacterCreatedWithGameInfoAttr:[NSDictionary dictionaryWithObjectsAndKeys:
                                                   @"adbrixer", @"character_name"
                                                   , nil]];
    
}
- (IBAction)click_stageCleared:(id)sender {
    [_adBrix gameStageClearedWithStageName:@"1-1"];
    [_adBrix gameStageClearedWithStageName:@"1-1" gameInfoAttr:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                @"none", @"stage_redeem"
                                                                , nil]];
}

- (IBAction)click_gdprForgetMe:(id)sender {
    [_adBrix gdprForgetMe];
}
@end
