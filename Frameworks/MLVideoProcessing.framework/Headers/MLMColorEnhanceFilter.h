//
//  MLMColorEnhanceFilter.h
//  MLVideoProcessing
//
//  Created by 杨乃川 on 2019/4/8.
//

#import <Foundation/Foundation.h>
@import MetalPetal;
@class MLColorEnhancement;
NS_ASSUME_NONNULL_BEGIN

@interface MLMColorEnhanceFilter : NSObject<MTIUnaryFilter>
@property (nonatomic, strong) MLColorEnhancement *colorEnhancement;
@end

NS_ASSUME_NONNULL_END
