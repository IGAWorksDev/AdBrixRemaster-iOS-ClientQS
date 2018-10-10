//
//  AdBrixRMSampleObjC.m
//  TestApp-IOS-Abx-RemasterHyBrid
//
//  Created by igaworks on 2018. 9. 18..
//  Copyright © 2018년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdBrixRMSampleObjC.h"
#import "TestApp-IOS-Abx-RemasterHyBrid-Bridging-Header.h"
#import <AdBrixRm/AdBrixRM-Swift.h>
#import <AdSupport/AdSupport.h>
#import <iAd/iAd.h>



@interface AdBrixRMSampleObjC ()

@property(strong,nonatomic) WKWebView *WKView_main;

@property(nonatomic) NSArray* Currency;
@property(nonatomic) NSArray* Payments;
@property(nonatomic) NSArray* ShareChannel;

@end



@implementation AdBrixRMSampleObjC

NSString* const FUNC_search = @"search";
NSString* const FUNC_share = @"share";
NSString* const FUNC_addToWishList = @"addToWishList";
NSString* const FUNC_addToCart = @"addToCart";
NSString* const FUNC_viewList = @"viewList";
NSString* const FUNC_productView = @"productView";
NSString* const FUNC_purchase = @"purchase";
NSString* const DIC_viewList = @"viewList";
NSString* const DIC_keyword = @"keyword";
NSString* const DIC_sharingChannel = @"sharingChannel";
NSString* const DIC_orderId = @"orderId";
NSString* const DIC_productId = @"productId";
NSString* const DIC_productName = @"productName";
NSString* const DIC_unitPrice = @"unitPrice";
NSString* const DIC_quantity = @"quantity";
NSString* const DIC_currencyCode = @"currencyCode";
NSString* const DIC_category = @"category";

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _WKView_main = [[WKWebView alloc] init];
    
     _WKView_main.frame = CGRectMake(self.view.frame.origin.x,self.view.frame.origin.y, self.view.frame.size.width, self.view.frame.size.height);
    
    [[self View_main] addSubview:_WKView_main];
    
    NSString *urlString = @"http://tech.ad-brix.com/adbrix_hybrid_sample_web/index.html";
    
    NSURL *url = [NSURL URLWithString:urlString];
    NSURLRequest *urlRequest = [NSURLRequest requestWithURL:url];
    [_WKView_main setNavigationDelegate:self];
    [_WKView_main loadRequest:urlRequest];
    
    _Payments = [NSArray arrayWithObjects: @"CreditCard",@"BankTransfer",@"MobilePayment",@"ETC", nil];
    _Currency = [NSArray arrayWithObjects: @"KRW",@"USD",@"JPY",@"EUR",@"GBP",@"CNY",@"TWD",@"HKD",@"IDR",@"INR",@"RUB",@"THB",@"VND",@"MYR", nil];
    _ShareChannel = [NSArray arrayWithObjects: @"Kakao",@"Naver",@"Line",@"Google",@"Facebook",@"Twitter",@"WhatsApp",@"QQ",@"WeChat",@"ETC", nil];
    
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}




#pragma mark - WKNavigationDelegate

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(nonnull WKNavigationAction *)navigationAction decisionHandler:(nonnull void (^)(WKNavigationActionPolicy))decisionHandler {
    
   
    NSURLRequest* req = navigationAction.request;
    NSURL* url = req.URL;
    NSString* scheme = [url scheme];
    BOOL isAdBrixCotains = false;
    
    NSLog(@"AdBrixRM scheme : %@", scheme);
    if ([scheme isEqualToString:@"AdBrixRM"] || [scheme isEqualToString:@"adbrix"]) {
        
        NSString *funcName = [[req URL] host];
        NSDictionary *adbrixEventDict = [Utils getURLParmaters:url];
        NSLog(@"AdBrixRM parameters : %@", adbrixEventDict);
        
        if ([funcName containsString:FUNC_productView] || [funcName containsString:FUNC_search]|| [funcName containsString:FUNC_share] || [funcName containsString:FUNC_addToWishList] || [funcName containsString:FUNC_addToCart] || [funcName containsString:FUNC_viewList] || [funcName containsString:FUNC_purchase] ) {
     
            
            
            NSArray* categoryList = [[adbrixEventDict valueForKey:@"category"] componentsSeparatedByString:@"."];
            
            
            AdBrixRmCommerceProductModel *productModel = [[AdBrixRM sharedInstance] createCommerceProductDataWithProductId:[adbrixEventDict valueForKey:DIC_productId]
                                                                                                                productName:[adbrixEventDict valueForKey:DIC_productName]
                                                                                                                      price:[[adbrixEventDict valueForKey:DIC_unitPrice] doubleValue]
                                                                                                                   quantity:[[adbrixEventDict valueForKey:DIC_quantity] integerValue]
                                                                                                                   discount:0.00
                                                                                                             currencyString:[self validCurreny:[adbrixEventDict valueForKey:DIC_currencyCode]]
                                                                                                                   category:[[AdBrixRM sharedInstance] createCommerceProductCategoryDataByArrayWithCategoryArray:categoryList]
                                                                                                            productAttrsMap:[[AdBrixRM sharedInstance] createCommerceProductAttrDataWithDictionary:nil]
                                                           ];
            
            //NSMutableArray방식
            NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
            [productArray addObject:productModel];
            
                        
            
            if ([funcName containsString:FUNC_purchase]) {
                
                if ([adbrixEventDict valueForKey:DIC_orderId]) {
                    isAdBrixCotains = true;
                    [[AdBrixRM sharedInstance] commonPurchaseWithOrderId:[adbrixEventDict valueForKey:DIC_orderId]
                                                             productInfo:productArray
                                                                discount:0.00
                                                          deliveryCharge:0.00
                                                           paymentMethod:[self validPayment:[adbrixEventDict valueForKey:@"CreditCard"]]
                     ];
                    
                    
                }
                
                
            }
            else if ([funcName containsString:FUNC_productView]) {
                isAdBrixCotains = true;
                [[AdBrixRM sharedInstance] commerceProductViewWithProductInfo:productModel];
            }
            else if ([funcName containsString:FUNC_addToCart]) {
                isAdBrixCotains = true;
                [[AdBrixRM sharedInstance] commerceAddToCartWithProductInfo:productArray];
            }
            else if ([funcName containsString:FUNC_viewList]) {
                isAdBrixCotains = true;
                [[AdBrixRM sharedInstance] commerceListViewWithProductInfo:productArray];
            }
          
            else if ([funcName containsString:FUNC_addToWishList]) {
                isAdBrixCotains = true;
                [[AdBrixRM sharedInstance] commerceAddToWishListWithProductInfo:productModel];
            }
            else if ([funcName containsString:FUNC_share]) {
                if ([adbrixEventDict valueForKey:DIC_sharingChannel]) {
                    isAdBrixCotains = true;
                    [[AdBrixRM sharedInstance] commerceShareWithChannel: [[AdBrixRM sharedInstance] convertChannel:[self validSharingChannel:[adbrixEventDict valueForKey:DIC_sharingChannel]]]  productInfo:productModel];
                }
               
            }
            else if ([funcName containsString:FUNC_search]) {
                if ([adbrixEventDict valueForKey:DIC_keyword]) {
                    isAdBrixCotains = true;
                    [[AdBrixRM sharedInstance] commerceSearchWithProductInfo:productArray keyword:[adbrixEventDict valueForKey:DIC_keyword]];
                }
            }
           
            
           
        }
        
        
        
        
        
    }
  
    
    if (isAdBrixCotains) {
        decisionHandler(WKNavigationActionPolicyCancel);
    }
    else {
        NSLog(@"NOT AdBrixRM .. ");
        decisionHandler(WKNavigationActionPolicyAllow);
    }
    
}


- (IBAction)click_toObjC:(id)sender {
    
}


- (NSString*) validCurreny:(NSString*)code {
    
    NSString* type = @"KRW";
    
    for(int i = 0; i < [_Currency count]; i++) {
        if([code containsString:_Currency[i]]) {
            type = _Currency[i];
            break;
        }
    }
    
    return type;
}

- (NSInteger) validPayment:(NSString*)code {
    
    
    NSInteger type = 1;
    
    for(int i = 0; i < [_Payments count]; i++) {
        if([code containsString:_Payments[i]]) {
            type = i;
            break;
        }
    }
   
    return type;
}

- (NSInteger) validSharingChannel:(NSString*)code {
    
    
    NSInteger type = 1;
    
    
    for(int i = 0; i < [_ShareChannel count]; i++) {
        if([code containsString:_ShareChannel[i]]) {
            type = i;
            break;
        }
    }
    
    return type;
}


@end
