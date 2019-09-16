//
//  MLMWaterMarkFilter.h
//  MLVideoProcessing
//
//  Created by 杨乃川 on 2019/3/29.
//

#import <Foundation/Foundation.h>
@import MetalPetal;
NS_ASSUME_NONNULL_BEGIN

@interface MLMWaterMarkFilter : NSObject<MTIUnaryFilter>
@property (nonatomic, assign) BOOL disable;

@end

NS_ASSUME_NONNULL_END
