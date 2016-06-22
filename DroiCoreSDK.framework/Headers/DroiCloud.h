/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import "DroiObject.h"

/**
 *  Callback method for background task
 *
 *  @param result The callback result. This data type should be DroiObject extension
 */
typedef void(^DroiCloudCallback)(id result);


@interface DroiCloud : NSObject
+ (id) callCloudService : (NSString*) name parameter : (DroiObject*) parameter  andClassType : (Class) clazz;
+ (NSString*) callCloudServiceInBackground : (NSString*) name parameter : (DroiObject*) parameter andCallback : (DroiCloudCallback) callback withClassType : (Class) clazz;
@end
