/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */


#import <Foundation/Foundation.h>

#define PERMISSION_READ 1
#define PERMISSION_WRITE 2

@interface DroiPermission : NSObject

#pragma mark - Default Permission
+ (instancetype) getDefaultPermission;
+ (void) setDefaultPermission : (DroiPermission*) permission;

#pragma mark - User/Group Read/Write Permission
- (void) setUserReadPermission:(NSString*) userId flag:(BOOL) enabled;
- (void) setUserWritePermission:(NSString*) userId flag:(BOOL) enabled;
- (void) setGroupReadPermission:(NSString*) groupId flag:(BOOL) enabled;
- (void) setGroupWritePermission:(NSString*) groupId flag:(BOOL) enabled;

#pragma mark - Serialization/Deserialization
- (NSDictionary*) toJson;
+ (instancetype) fromJson:(NSDictionary*) json;
@end
