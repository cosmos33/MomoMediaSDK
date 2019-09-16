#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "MLBeautySettings.h"
#import "MLCameraSource.h"
#import "MLColorEnhancement.h"
#import "MLCVDetectorController.h"
#import "MLGPUImageDecorationManager.h"
#import "MLGPUImageLogarithmYFilter.h"
#import "MLGPUImageSkinSmoothingMethod.h"
#import "MLGPUImageVibranceFilter.h"
#import "MLGPUImageVideoProcessor.h"
#import "MLMColorEnhanceFilter.h"
#import "MLMediaSource.h"
#import "MLMetalPetalVideoProcessor.h"
#import "MLMWaterMarkFilter.h"
#import "MLObjectTriggeredDecoration.h"
#import "MLPlayerBufferProcessor.h"
#import "MLRecordingRequest.h"
#import "MLVideoProcessor.h"
#import "MLVideoRecorder.h"
#import "MLVideoWatermarkProducer.h"
#import "MLVideoWatermarkView.h"
#import "MLWaterMark.h"

FOUNDATION_EXPORT double MLVideoProcessingVersionNumber;
FOUNDATION_EXPORT const unsigned char MLVideoProcessingVersionString[];

