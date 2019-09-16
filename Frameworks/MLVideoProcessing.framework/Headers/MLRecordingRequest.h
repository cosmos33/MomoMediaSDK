//
//  MLRecordingRequest.h
//  MLVideoProcessing
//
//  Created by 杨乃川 on 2019/5/21.
//

#import <Foundation/Foundation.h>
@class MLVideoRecorderOption;
typedef NS_OPTIONS(NSUInteger, MLRecordOption) {
    MLRecordOptionNone = 0,
    MLRecordOptionOrigin = 1 << 0,
    MLRecordOptionProcessed = 1 << 1,
    MLRecordOptionOriginAndProcessed = MLRecordOptionOrigin | MLRecordOptionProcessed
};
NS_ASSUME_NONNULL_BEGIN

@interface MLRecordingRequest : NSObject

@property (nonatomic, assign, readonly) MLRecordOption type;
@property (nonatomic, assign, readonly) NSUInteger customize;
@property (nonatomic, copy, readonly) MLVideoRecorderOption *option;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)requestWithJSONDictionary:(NSDictionary *)jsonDict;
- (instancetype)initWithJSONDictionary:(NSDictionary *)jsonDict;
@end

NS_ASSUME_NONNULL_END
