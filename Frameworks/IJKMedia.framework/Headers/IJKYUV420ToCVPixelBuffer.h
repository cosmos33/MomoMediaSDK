//
//  IJKYUV420ToCVPixelBuffer.h
//  IJKMedia
//
//  Created by wangqiangqiang on 2017/3/27.
//  Copyright © 2017年 MOMO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

typedef struct YUV420PFrame {
    int width;  //width of video frame
    int height;  //height of video frame
    int yStride;  //stride of Y data buffer
    int uStride;  //stride of U data buffer
    int vStride;  //stride of V data buffer
    void* yBuffer;  //Y data buffer
    void* uBuffer;  //U data buffer
    void* vBuffer;  //V data buffer
} YUV420PFrame;

@interface IJKYUV420ToCVPixelBuffer : NSObject

- (instancetype)initWithFrameSize:(CGSize)frameSize;

- (CVPixelBufferRef)convertYUV420ToPixelBuffer:(YUV420PFrame)videoFrame CF_RETURNS_NOT_RETAINED;

- (CMSampleBufferRef)convertYUV420ToSampleBuffer:(YUV420PFrame)videoFrame CF_RETURNS_NOT_RETAINED;

@end
