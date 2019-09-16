//
//  MLPublisherCameraConfiguration.h
//  MomoChat
//
//  Created by wangqiangqiang on 2017/11/14.
//  Copyright © 2017年 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef NS_ENUM(NSInteger, MLVideoCaptureQuality) {
    MLVideoCaptureQualityLow = 0,
    MLVideoCaptureQualityMedium = 1,
    MLVideoCaptureQualityHigh = 2,
    MLVideoCaptureQualitySuper = 3,
};

typedef NS_ENUM(NSInteger, MLMediaCaptureDevicePosition) {
    MLMediaCaptureDevicePositionBack = 0,
    MLMediaCaptureDevicePositionFront = 1,
};

typedef NS_ENUM(NSUInteger, MLPublisherCameraOutputAspectRatio) {
    MLPublisherCameraOutputAspectRatio9x16,
    MLPublisherCameraOutputAspectRatio1x1,
    MLPublisherCameraOutputAspectRatio3x4
};

@interface MLPublisherCameraConfiguration : NSObject

@property (nonatomic,copy,readonly) NSString *captureSessionPreset;
@property (nonatomic,readonly) AVCaptureDevicePosition captureDevicePosition;
@property (nonatomic,readonly) CGRect cropRegion;
@property (nonatomic,readonly) CGSize videoFrameSize;
@property (nonatomic,readonly) CGFloat scale;

+ (instancetype)configurationWithCaptureQuality:(MLVideoCaptureQuality)quality
                                 devicePosition:(MLMediaCaptureDevicePosition)position
                           preferredAspectRatio:(MLPublisherCameraOutputAspectRatio)preferredAspectRatio;

+ (instancetype)configurationWithCaptureQuality:(MLVideoCaptureQuality)quality
                                 devicePosition:(MLMediaCaptureDevicePosition)position
                                  preferredSize:(CGSize)preferredSize;

+ (instancetype)configurationWithCaptureQuality:(MLVideoCaptureQuality)quality
                                 devicePosition:(MLMediaCaptureDevicePosition)position
                                  preferredSize:(CGSize)preferredSize
                                  isOrientation:(BOOL)isOrientation;

@end
