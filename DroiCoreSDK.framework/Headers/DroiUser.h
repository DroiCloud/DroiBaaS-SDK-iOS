/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import "DroiObject.h"
@import UIKit;

typedef NS_ENUM(int, SignUpState) {
    SIGNUP_OK = 0,
    SIGNUP_FAIL = -1,
    SIGNUP_FAIL_ALREADY_LOGIN = -2,
    SIGNUP_FAIL_ALREADY_EXISTS = -3
};

typedef void(^DroiSignUpCallback)(SignUpState state);

@class UIView;
@protocol IOAuthProvider <NSObject>

@required
- (BOOL) isTokenValid;
- (NSString*) sessionToken;
- (NSString*) OAuthProviderName;
@end

DroiClassName(@"_User")
@interface DroiUser : DroiObject

DroiExpose
@property NSString* UserId;

DroiExpose
@property NSString* Password;

DroiExpose
@property NSString* Email;

#pragma mark - Static Methods
+ (instancetype) getCurrentUser;
+ (instancetype) getCurrentUserByUserClass:(Class) userClazz;

+ (instancetype) login: (NSString*) userId password:(NSString*) password;
+ (instancetype) loginByUserClass : (NSString*) userId password:(NSString*) password userClass:(Class) userClazz;

// TODO: OAuth
+ (instancetype) loginWithOAuth : (UIView*) view oauth:(id<IOAuthProvider>) provider;
+ (instancetype) loginWithAnonymous;

#pragma mark - Login/Logout
- (SignUpState) signUp;
- (NSString*) signUpInBackground:(DroiSignUpCallback) callback;
- (void) cancelBackgroundTask : (NSString*) taskId;
- (void) logout;

#pragma mark - Save methods
- (BOOL) save;
- (NSString*) saveInBackground:(DroiObjectCallback)callback;
- (void) saveEventually;

#pragma mark - Status
+ (BOOL) autoAnonymousUser;
+ (void) setAutoAnonymousUser:(BOOL) autoAnonymousUser;
- (NSString*) getSessionToken;
- (BOOL) isEmailVerified;
- (BOOL) isAuthorized;
- (BOOL) isAnonymous;

@end
