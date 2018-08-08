//
//  AppDelegate.swift
//  TestApp-IOS-Abx-RemasterSwift
//
//  Created by igaworks on 2018. 2. 6..
//  Copyright © 2018년 igaworks. All rights reserved.
//

import UIKit
import AdBrixRM
import AdSupport
import CoreLocation

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, CLLocationManagerDelegate {

    var window: UIWindow?
    var locationManager:CLLocationManager!

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        let adBrix = AdBrixRM.getInstance
        
        //광고id
        if ((NSClassFromString("ASIdentifierManager")) != nil) {
            let ifa :UUID = ASIdentifierManager.shared().advertisingIdentifier
            adBrix.setAppleAdvertisingIdentifier(ifa.uuidString)
            
        //    print("ifa UUIDString :: \(ifa.uuidString)")
        }
        
        
        adBrix.setLogLevel(AdBrixRM.AdBrixLogLevel.ERROR)
        adBrix.setEventUploadCountInterval(AdBrixRM.AdBrixEventUploadCountInterval.MIN)
        adBrix.setEventUploadTimeInterval(AdBrixRM.AdBrixEventUploadTimeInterval.MIN)
        
        adBrix.initAdBrix(appKey: "key", secretKey:"key")
        adBrix.setLocation(latitude: 32.514, longitude: 126.986)
        
                
        locationManager = CLLocationManager()
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
        locationManager.distanceFilter = 200
        locationManager.requestWhenInUseAuthorization()
        locationManager.startUpdatingLocation()
        
        return true
    }

    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }

    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }

    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }

    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }

    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }
    
    func application(_ application: UIApplication, open url: URL, sourceApplication: String?, annotation: Any?) -> Bool {
        let adBrix = AdBrixRM.getInstance
        adBrix.deepLinkOpen(url: url)
        return true
    }
    
    func application(_ app: UIApplication, open url: URL, options: [UIApplicationOpenURLOptionsKey : Any] = [:]) -> Bool {
//        let alertController = UIAlertController(title: "deep link test", message: "deep link push open", preferredStyle: .alert)
//        let okAction = UIAlertAction(title: "Confirm", style: .default) { (result : UIAlertAction) -> Void in }
//        alertController.addAction(okAction)
//        self.window?.rootViewController?.present(alertController, animated: true, completion: nil)
//
        // pass open url for commerce conversion
        let adBrix = AdBrixRM.getInstance
        adBrix.deepLinkOpen(url: url)
        
        return true
    }
    
    
//    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
//
//        print("location error is = \(error.localizedDescription)")
//
//    }
//
//
//    func locationManager(_ manager: CLLocationManager,
//                         didUpdateLocations locations: [CLLocation]) {
//
//        if let loc = manager.location {
//            let locValue:CLLocationCoordinate2D = (manager.location?.coordinate)!
//            print("Current Locations = \(locValue.latitude) \(locValue.longitude)")
//        }
//
//    }


}

