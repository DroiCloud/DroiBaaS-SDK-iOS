/*
 * Copyright (c) 2016-present Shanghai Droi Technology Co., Ltd.
 * All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "DroiObject.h"

#define MAX_AVAILABLE_FILE_SIZE 10485760

typedef NS_ENUM(int, GetFileCode) {
    GETFILE_OK,
    GETFILE_FAIL,
    GETFILE_NOT_READY
};

@interface DroiGetFileResult : NSObject
@property NSData* data;
@property GetFileCode code;
@end

typedef void(^DroiGetFileCallback)(DroiGetFileResult* result);
typedef void(^DroiSaveFileCallback)(BOOL result);
typedef void(^DroiFileProgressCallback)(long current, long max);

@interface DroiFile : NSObject
+ (instancetype) fileWithFileName:(NSString*) fileName;
+ (instancetype) fileWithFileName:(NSString*) fileName mimeType:(NSString*) mimeType;
+ (instancetype) fileWithData:(NSData*) data name:(NSString*) name;
+ (instancetype) fileWithData:(NSData*) data;
+ (instancetype) fileWithData:(NSData*) data mimeType:(NSString*) mimeType;
+ (instancetype) fileWithData:(NSData*) data name:(NSString*) name mimeType:(NSString*) mimeType;

- (DroiGetFileResult*) get;
- (void) getInBackground:(DroiGetFileCallback) callback;
- (void) getInBackground:(DroiGetFileCallback) callback progressCallback:(DroiFileProgressCallback) progressCallback;

@property BOOL localStorage;
@end
