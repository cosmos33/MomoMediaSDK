//
//  MLStreamMediaSource.h
//  MLStreamPublisher
//
//  Created by wangqiangqiang on 2018/9/21.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

//请注意要和MLVideoProcessing中的MLMediaSource定义保持一直
@protocol MLStreamMediaSource;

@protocol MLStreamMediaDataConsumer <NSObject>

@optional

- (void)mediaSource:(id<MLStreamMediaSource>)source didOutputVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;
- (void)mediaSource:(id<MLStreamMediaSource>)source didOutputAudioSampleBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)mediaSource:(id<MLStreamMediaSource>)source didRenderAudioData:(NSData*)sampleBuffer;

@end


@protocol MLStreamMediaSource <NSObject>

- (void)addDataConsumer:(id<MLStreamMediaDataConsumer>)dataConsumer;

- (void)removeDataConsumer:(id<MLStreamMediaDataConsumer>)dataConsumer;

@end
