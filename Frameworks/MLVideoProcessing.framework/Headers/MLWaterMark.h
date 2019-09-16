//
//  MLWaterMark.h
//  MLVideoProcessing
//
//  Created by 杨乃川 on 2019/4/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MLWaterMark: NSObject
@property (nonatomic, assign, readonly) NSTimeInterval showDuration;
@property (nonatomic, assign, readonly) NSTimeInterval hideDuration;
@property (nonatomic, assign, readonly) CGRect rect;
@property (nonatomic, copy, readonly) NSURL *imageURL;

- (instancetype)initWaterMark:(NSURL *)imageURL displayRect:(CGRect)rect show:(NSTimeInterval)show hide:(NSTimeInterval)hide;
+ (instancetype)defaultWaterMarkWithDisplayRect:(CGRect)rect;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
