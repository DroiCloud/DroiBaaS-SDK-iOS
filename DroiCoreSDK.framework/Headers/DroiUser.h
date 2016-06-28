/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import "DroiObject.h"
#import "DroiError.h"
@import UIKit;

typedef void(^DroiSignUpCallback)(BOOL result, DroiError* error);

@class UIView;
@protocol IOAuthProvider <NSObject>

@required
- (BOOL) isTokenValid;
- (NSString*) sessionToken;
- (NSString*) OAuthProviderName;
@end

DroiObjectName(@"_User")
@interface DroiUser : DroiObject

DroiExpose
@property NSString* UserId;

DroiExpose
@property (getter=getPassword, setter=setPassword:) NSString* Password;

DroiExpose
@property NSString* Email;

DroiExpose
@property BOOL Enabled;

#pragma mark - Properties

@property (readonly, getter=getSessionToken) NSString* sessionToken;

#pragma mark - Static Methods
+ (instancetype) getCurrentUser;
+ (id) getCurrentUserByUserClass:(Class) userClazz;

+ (instancetype) login: (NSString*) userId password:(NSString*) password error:(DroiError**) error;
+ (id) loginByUserClass : (NSString*) userId password:(NSString*) password userClass:(Class) userClazz error:(DroiError**) error;

// TODO: OAuth
+ (instancetype) loginWithOAuth : (UIView*) view oauth:(id<IOAuthProvider>) provider userClass:(Class) userClazz error:(DroiError**) error;
+ (instancetype) loginWithOAuth : (UIView*) view oauth:(id<IOAuthProvider>) provider error:(DroiError**) error;
+ (instancetype) loginWithAnonymous:(DroiError**) error;

#pragma mark - Login/Logout
- (DroiError*) signUp;
- (NSString*) signUpInBackground:(DroiSignUpCallback) callback;
- (void) cancelBackgroundTask : (NSString*) taskId;
- (DroiError*) logout;

#pragma mark - Save methods
- (DroiError*) save;
- (NSString*) saveInBackground:(DroiObjectCallback)callback;
- (void) saveEventually;

#pragma mark - Status
+ (BOOL) autoAnonymousUser;
+ (void) setAutoAnonymousUser:(BOOL) autoAnonymousUser;
- (BOOL) isEmailVerified;
- (BOOL) isAuthorized;
- (BOOL) isAnonymous;

@end
