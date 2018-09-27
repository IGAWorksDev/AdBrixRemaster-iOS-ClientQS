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

@property(nonatomic) NSMutableArray* Currency;

@property(nonatomic) NSDictionary* Payments;


@end

@implementation AdBrixRMSampleObjC

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    _WKView_main = [[WKWebView alloc] init];
    
     _WKView_main.frame = CGRectMake(self.view.frame.origin.x,self.view.frame.origin.y, self.view.frame.size.width, self.view.frame.size.height);
    
    [[self View_main] addSubview:_WKView_main];
    
    NSString *urlString = @"https://s3-ap-northeast-1.amazonaws.com/static.adbrix.igaworks.com/tech_support/adbrix/hybrid_web/adbrixHybrid.html";
    NSURL *url = [NSURL URLWithString:urlString];
    NSURLRequest *urlRequest = [NSURLRequest requestWithURL:url];
    [_WKView_main setNavigationDelegate:self];
    [_WKView_main loadRequest:urlRequest];
    
    _Payments = [NSDictionary dictionaryWithObjectsAndKeys:
       @"val1", @"key1",
       @"val2", @"key2"
                 , nil];
    
//    arrayOfStrings
//
//    _Currency = [NSMutableArray array];
//    [_Currency addObject:@"KRW"];
//    [_Currency addObject:@"USD"];
//    [_Currency addObject:@"JPY"];
//    [_Currency addObject:@"EUR"];
//    [_Currency addObject:@"GBP"];
//    [_Currency addObject:@"CNY"];
//    [_Currency addObject:@"TWD"];
//    [_Currency addObject:@"HKD"];
//    [_Currency addObject:@"IDR"];
//    [_Currency addObject:@"INR"];
//    [_Currency addObject:@"RUB"];
//    [_Currency addObject:@"THB"];
//    [_Currency addObject:@"VND"];
//    [_Currency addObject:@"MYR"];
    
    
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
    
    
    if ([scheme isEqualToString:@"AdBrixRM"] || [scheme isEqualToString:@"adbrix"]) {
        
        NSString *funcName = [[req URL] host];
        NSDictionary *adbrixEventDict = [Utils getURLParmaters:url];
        NSLog(@"AdBrixRM parameters : %@", adbrixEventDict);
        
        if ([funcName containsString:@"purchase"] || [funcName containsString:@"refund"]|| [funcName containsString:@"list_view"] || [funcName containsString:@"add_to_cart"] || [funcName containsString:@"search"] ) {
            
            isAdBrixCotains = true;
            
            NSArray* categoryList = [[adbrixEventDict valueForKey:@"category"] componentsSeparatedByString:@"."];
            
            
            AdBrixRmCommerceProductModel *productModel = [[AdBrixRM sharedInstance] createCommerceProductDataWithProductId:[adbrixEventDict valueForKey:@"pid"]
                                                                                                                productName:[adbrixEventDict valueForKey:@"pname"]
                                                                                                                      price:[[adbrixEventDict valueForKey:@"price"] doubleValue]
                                                                                                                   quantity:[[adbrixEventDict valueForKey:@"quantity"] integerValue]
                                                                                                                   discount:0.00
                                                                                                             currencyString:[self validCurreny:[adbrixEventDict valueForKey:@"currency_code"]]
                                                                                                                   category:[[AdBrixRM sharedInstance] createCommerceProductCategoryDataByArrayWithCategoryArray:categoryList]
                                                                                                            productAttrsMap:[[AdBrixRM sharedInstance] createCommerceProductAttrDataWithDictionary:nil]
                                                           ];
            
            //NSMutableArray방식
            NSMutableArray<AdBrixRmCommerceProductModel *> *productArray = [NSMutableArray array];
            [productArray addObject:productModel];
            
            
            
            if ([funcName containsString:@"purchase"] || [funcName containsString:@"refund"]|| [funcName containsString:@"list_view"] || [funcName containsString:@"add_to_cart"] || [funcName containsString:@"search"] ) {
            }
            else if ([funcName containsString:@"purchase"]) {
                
                if ([adbrixEventDict valueForKey:@"oid"] &&
                    [adbrixEventDict valueForKey:@"deliveryCharge"] &&
                    [adbrixEventDict valueForKey:@"paymentMethod"]) {
                    
                    [[AdBrixRM sharedInstance] commonPurchaseWithOrderId:[adbrixEventDict valueForKey:@"oid"]
                                                             productInfo:productArray
                                                                discount:0.00
                                                          deliveryCharge:[[adbrixEventDict valueForKey:@"deliveryCharge"] doubleValue]
                                                           paymentMethod:[self validPayment:[adbrixEventDict valueForKey:@"paymentMethod"]]
                     ];
                    
                    
                }
                
                
            }
            else if ([funcName containsString:@"refund"]) {
                if ([adbrixEventDict valueForKey:@"oid"] && [adbrixEventDict valueForKey:@"penaltyCharge"]) {
                    [[AdBrixRM sharedInstance] commerceRefundWithOrderId:[adbrixEventDict valueForKey:@"oid"] productInfo:productArray penaltyCharge:[[adbrixEventDict valueForKey:@"penaltyCharge"] doubleValue]];
                }
                
            }
            else if ([funcName containsString:@"product_view"]) {
                [[AdBrixRM sharedInstance] commerceProductViewWithProductInfo:productModel];
            }
            else if ([funcName containsString:@"list_view"]) {
                [[AdBrixRM sharedInstance] commerceListViewWithProductInfo:productArray];
            }
            else if ([funcName containsString:@"add_to_cart"]) {
                [[AdBrixRM sharedInstance] commerceAddToCartWithProductInfo:productArray];
            }
            else if ([funcName containsString:@"search"]) {
                if ([funcName containsString:@"keyword"]) {
                    [[AdBrixRM sharedInstance] commerceSearchWithProductInfo:productArray keyword:[adbrixEventDict valueForKey:@"keyword"]];
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
    
    for(id key in _Payments) {
        if([code containsString:[_Payments objectForKey:key]]) {
            type = [_Payments objectForKey:key];
            break;
        }
        
    }
    
    return type;
}

- (NSInteger) validPayment:(NSString*)code {
    
    
    NSInteger type = 4;
    
    for(int i = 0; i < [_Currency count]; i++) {
        if([code containsString:_Currency[i]]) {
            type = i;
            break;
        }
    }
   
    return type;
}



@end
