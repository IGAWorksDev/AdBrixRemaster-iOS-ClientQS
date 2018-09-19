//
//  AdBrixRMSampleObjC.h
//  TestApp-IOS-Abx-RemasterHyBrid
//
//  Created by igaworks on 2018. 9. 18..
//  Copyright © 2018년 igaworks. All rights reserved.
//

#ifndef AdBrixRMSampleObjC_h
#define AdBrixRMSampleObjC_h


#endif /* AdBrixRMSampleObjC_h */


#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "Utils.h"

#define AbxPayment @[@"KRW",@"USD",@"JPY",@"EUR",@"GBP",@"CNY",@"TWD",@"HKD",@"IDR",@"INR",@"RUB",@"THB",@"VND",@"MYR"];



@interface AdBrixRMSampleObjC : UIViewController <WKNavigationDelegate>
@property (weak, nonatomic) IBOutlet UIButton *Button_toSwift;
@property (weak, nonatomic) IBOutlet UIView *View_main;

- (IBAction)click_toObjC:(id)sender;


@end
