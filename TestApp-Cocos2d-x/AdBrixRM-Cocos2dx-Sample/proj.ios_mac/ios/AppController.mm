/****************************************************************************
 Copyright (c) 2010-2013 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#import "AppController.h"
#import "cocos2d.h"
#import "AppDelegate.h"
#import "RootViewController.h"
#import <AdSupport/AdSupport.h>

#import "AdBrixRM/AdBrixRM-Swift.h"

@interface AppController () <AdBrixRMDeeplinkDelegate> {}
@end

@implementation AppController

@synthesize window;

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    //AdBrix Remaster Init -- start
    AdBrixRM *adBrix = [AdBrixRM sharedInstance]; //또는 AdBrixRM *adBrixs = AdBrixRM.sharedInstance;
    
    if (NSClassFromString(@"ASIdentifierManager")) {
        NSUUID *ifa =[[ASIdentifierManager sharedManager]advertisingIdentifier];
        [adBrix setAppleAdvertisingIdentifier:[ifa UUIDString]];
    }

    [adBrix setLogLevel:AdBrixLogLevelERROR];
    [adBrix setEventUploadCountInterval:AdBrixEventUploadCountIntervalMIN];
    [adBrix setEventUploadTimeInterval:AdBrixEventUploadTimeIntervalMIN];
    [adBrix setDeeplinkDelegateWithDelegate:self];
    [adBrix initAdBrixWithAppKey:@"fnbFMvaGgkGVcajnoIeUTw" secretKey:@"mj2kvH7FL0Gdv15yaX2Cuw"];
    //AdBrix Remaster Init -- end
    
    cocos2d::Application *app = cocos2d::Application::getInstance();
    
    // Initialize the GLView attributes
    app->initGLContextAttrs();
    cocos2d::GLViewImpl::convertAttrs();
    
    // Override point for customization after application launch.

    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];

    // Use RootViewController to manage CCEAGLView
    _viewController = [[RootViewController alloc]init];
    _viewController.wantsFullScreenLayout = YES;
    

    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: _viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:_viewController];
    }

    [window makeKeyAndVisible];

    [[UIApplication sharedApplication] setStatusBarHidden:true];
    
    // IMPORTANT: Setting the GLView should be done after creating the RootViewController
    cocos2d::GLView *glview = cocos2d::GLViewImpl::createWithEAGLView((__bridge void *)_viewController.view);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    
    //run the cocos2d-x game scene
    app->run();

    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    // We don't need to call this method any more. It will interrupt user defined game pause&resume logic
    /* cocos2d::Director::getInstance()->pause(); */
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    // We don't need to call this method any more. It will interrupt user defined game pause&resume logic
    /* cocos2d::Director::getInstance()->resume(); */
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::Application::getInstance()->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    cocos2d::Application::getInstance()->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}



#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}



#if __has_feature(objc_arc)
#else
- (void)dealloc {
    [window release];
    [_viewController release];
    [super dealloc];
}
#endif


/**
 start deeplink
 */
#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_9_0

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation
{
    NSLog(@"DEEPLINK :: DeepLink Called !! - %@", url);
    [[AdBrixRM sharedInstance] deepLinkOpenWithUrl:url];
    
    return YES;
}
#else

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary *)options
{
    NSLog(@"DEEPLINK :: DeepLink Called !!! - %@", url);
    [[AdBrixRM sharedInstance] deepLinkOpenWithUrl:url];
    
    return YES;
    
}
#endif

-(BOOL)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray * _Nullable))restorationHandler{
    if ([userActivity.activityType isEqualToString: NSUserActivityTypeBrowsingWeb]) {
        NSURL *url = userActivity.webpageURL;
        NSLog(@"DEEPLINK :: UniversialLink Called !! - %@", url);
        [[AdBrixRM sharedInstance] deepLinkOpenWithUrl:url];
    }
    return YES;
}

//deferred deeplink url
- (void)didReceiveDeeplinkWithDeeplink:(NSString * _Nonnull)deeplink {
    NSLog(@"didReceiveDeeplinkWithDeeplink: %@", deeplink);
}

/**
 end deeplink
 */


- (void)application:(UIApplication*)application didReceiveLocalNotification:(UILocalNotification *)notification
{
    
}


#if __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_7_0
#warning "Remote push open tracking is counted only when user touches notification center under iOS SDK 7.0"
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{
    
}
#else
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler
{
    
}
#endif

- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    NSLog(@"deviceToken: %@", deviceToken);
    
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    NSLog(@"Device Token Register Failed: %@", error);
}



@end
