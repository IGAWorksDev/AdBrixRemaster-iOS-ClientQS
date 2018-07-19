//
//  ViewController.h
//  TestApp-IOS-Abx-RemasterObjC
//
//  Created by igaworks on 2018. 2. 6..
//  Copyright © 2018년 igaworks. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIButton *Button_gdprForgetMe;

- (IBAction)click_gdprForgetMe:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_event;
- (IBAction)click_event:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_eventSub;
- (IBAction)click_eventSub:(id)sender;


@property (weak, nonatomic) IBOutlet UITextField *TextField_age;

@property (weak, nonatomic) IBOutlet UIButton *Button_setAge;
- (IBAction)click_setAge:(id)sender;

@property (weak, nonatomic) IBOutlet UISegmentedControl *Segment_gender;

- (IBAction)change_gender:(id)sender;

@property (weak, nonatomic) IBOutlet UITextField *TextField_userId;

@property (weak, nonatomic) IBOutlet UIButton *Button_login;

- (IBAction)click_login:(id)sender;

@property (weak, nonatomic) IBOutlet UITextField *UITextField_propKey;
@property (weak, nonatomic) IBOutlet UITextField *UITextField_propValue;
@property (weak, nonatomic) IBOutlet UIButton *UIButton_setUserProp;
- (IBAction)click_setUserProp:(id)sender;







@property (weak, nonatomic) IBOutlet UIButton *Button_commerceViewHome;

- (IBAction)click_commerceViewHome:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceCategoryView;

- (IBAction)click_commerceCategoryView:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceProductView;

- (IBAction)click_commerceProductView:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceAddToCart;

- (IBAction)click_commerceAddToCart:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceAddToCartBulk;

- (IBAction)click_commerceAddToCartBulk:(id)sender;


@property (weak, nonatomic) IBOutlet UIButton *Button_commerceAddToWishList;

- (IBAction)click_commerceAddToWishList:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceReviewOrder;

- (IBAction)click_commerceReviewOrder:(id)sender;
@property (weak, nonatomic) IBOutlet UIButton *Button_commerceReviewOrderBulk;
- (IBAction)click_commerceReviewOrderBulk:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commonPurchase;
- (IBAction)click_commonPurchase:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commonPurchaseBulk;
- (IBAction)click_commonPurchaseBulk:(id)sender;


@property (weak, nonatomic) IBOutlet UIButton *Button_commerceRefund;

- (IBAction)click_commerceRefund:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceRefundBulk;

- (IBAction)click_commerceRefundBulk:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceSearch;

- (IBAction)click_commerceSearch:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_commerceShare;

- (IBAction)click_commerceShare:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_listView;
- (IBAction)click_commerceListView:(id)sender;

@property (weak, nonatomic) IBOutlet UIButton *Button_cartView;
- (IBAction)click_commerceCartView:(id)sender;


@property (weak, nonatomic) IBOutlet UIButton *Button_paymentInfoAdded;
- (IBAction)click_commercePaymentInfoAdded:(id)sender;


@property (weak, nonatomic) IBOutlet UIButton *Button_LevelAchieved;
- (IBAction)click_levelAchieved:(id)sender;



@property (weak, nonatomic) IBOutlet UIButton *Button_tutorialCompleted;
- (IBAction)click_tutorialCompleted:(id)sender;


@property (weak, nonatomic) IBOutlet UIButton *Button_characterCreated;
- (IBAction)click_characterCreated:(id)sender;



@property (weak, nonatomic) IBOutlet UIButton *Button_stageCleared;
- (IBAction)click_stageCleared:(id)sender;


@end

