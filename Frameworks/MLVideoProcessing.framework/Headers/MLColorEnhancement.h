//
//  MLColorEnhancemnet.h
//  MLVideoProcessing
//
//  Created by 杨乃川 on 2018/12/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, MLColorEnhanceOption) {
    MLColorEnhanceOptionNone = 0,
    MLColorEnhanceOptionSaturation = 1 << 0,
    MLColorEnhanceOptionContrast = 1 << 1,
    MLColorEnhanceOptionUSMSharpening = 1 << 2,
    MLColorEnhancementAll = MLColorEnhanceOptionSaturation|MLColorEnhanceOptionContrast|MLColorEnhanceOptionUSMSharpening
};


@interface MLColorEnhancement : NSObject
@property (nonatomic, assign) MLColorEnhanceOption option;
@property (nonatomic, assign) float saturation;
@property (nonatomic, assign) float contrast;
@property (nonatomic, assign) float usmRadius;
@property (nonatomic, assign) float usmScale;
@property (nonatomic, assign) float usmThreshold;

@end

NS_ASSUME_NONNULL_END
