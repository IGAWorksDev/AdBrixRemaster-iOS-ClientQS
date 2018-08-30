//
//  PluginLiveOps.m
//  PluginLiveOps
//
//  Created by 강기태 on 2015. 8. 10..
//  Copyright (c) 2015년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "InterfaceAds.h"
#import "AdsWrapper.h"

#import <LiveOps/LiveOps.h>

@interface PluginLiveOps : NSObject <InterfaceAds>

/*!
 @abstract
 liveOps push 초기화
 */
- (void)initPush;






/*!
 @abstract
 remote push 활성화/비활성화
 
 @param isEnabled              remove push on/off.
 */
- (void)setRemotePushEnable:(BOOL)isEnabled;


/*!
 @abstract
 local push 등록
 
 @param Id                     유니크 아이디
 @param date                   local push 노출 시간
 @param bodyText               local push 출력될 내용
 @param buttonText             local push 확인 버튼에 출력될 텍스트
 @param sound                  local push 소리 설정
 @param badgeNum               앱아이콘에 표시될 뱃지 숫자
 @param payloadDict            local push 노출시 리스너에 전달될 Dictionary형태의 데이터
 
 */
- (void)registerLocalPushNotification:(NSInteger)Id date:(NSDate*)date body:(NSString*)bodyText button:(NSString*)buttonText soundName:(NSString*)sound badgeNumber:(NSInteger)badgeNum customPayload:(NSDictionary*)payloadDict;

/*!
 @abstract
 등록되어있던 local push를 취소
 
 @param Id                     취소하려는 local push의 유니크 아이디
 */
- (void)cancelLocalPush:(NSInteger)Id;

/*!
 @abstract
 조건 검색을 위한 타게팅 데이터 설정
 
 @param obj                    설정하려는 데이터. NSNumber, NSString, NSDate, NSNull만이 가능하다.
 @param key                    데이터의 키값
 */
- (void)setTargetingData:(id)obj withKey:(NSString*)key;

/*!
 @abstract
 설정된 타게팅 데이터들을 즉시 서버로 업데이트.
 flush를 호출하지 않으면 앱이 백그라운드 상태로 전환되는 시점에 모아진 내용을 한번에 전송한다.
 */
- (void)flush;






/*!
 @abstract
 팝업 데이터를 서버로부터 받아온다.
 
 @param block                  전송이 끝난 시점에 호출되는 콜백 함수. 콜백이 호출된 이후부터 새로 갱신된 데이터가 적용된다.
 */
- (void)getPopups;

/*!
 @abstract
 getPopups를 통해 저장된 내용대로 팝업들을 출력
 
 @param popupSpaceKey          출력하려는 팝업들이 위치한 spaceKey
 */
- (void)showPopups:(NSString*)popupSpaceKey;

/*!
 @abstract
 지정된 viewController위에 getPopups를 통해 저장된 내용대로 팝업들을 출력
 viewController를 지정하는 점을 제외하고 showPopups:(NSString*)popupSpaceKey 와 동일
 
 @param popupSpaceKey          출력하려는 팝업들이 위치한 spaceKey
 @param viewCtrler             지정된 viewCtrler위에 출력한다.
 */
- (void)showPopups:(NSString*)popupSpaceKey withViewController:(UIViewController*)viewCtrler;

/*!
 @abstract
 현재 출력된 팝업을 닫는다.
 팝업 닫기버튼을 유저가 직접 누른 것과 동일한 효과
 */
- (void)destroyPopup;

/*!
 @abstract
 현재 출력된 팝업을 닫고 뒤에 출력될 팝업까지 전부 취소한다.
 */
- (void)destroyAllPopups;

///*!
// @abstract
// 팝업 링크를 터치하여 이동되는 시점에 호출될 콜백함수를 지정
// 
// @param block                  팝업 링크가 오픈되는 시점에 호출되는 콜백 함수.
// */
//- (void)setPopupLinkListener:(LiveOpsPopupLinkCallback)block;
//
///*!
// @abstract
// 팝업이 닫히는 시점에 호출될 콜백함수를 지정
// 
// @param block                  팝업이 닫히는 시점에 호출되는 콜백 함수.
// */
//- (void)setPopupCloseListener:(LiveOpsPopupCloseCallback)block;

@end