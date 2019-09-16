//
//  IJKAudioOutput.h
//  IJKMediaPublisherDemo
//
//  Created by zhai.jianfeng on 12/10/15.
//  Copyright © 2015 zhai.jianfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@protocol IJKAudioInput <NSObject>
- (void)setInputSamplebuffer:(NSData*)newInputSamplebuffer atTime:(CMTime)frameTime samplerate:(NSInteger) sr channels:(NSInteger)chs sampleFormat:(NSInteger)fmt;
- (void)endProcessing;
@end
@interface IJKAudioOutput : NSObject

@property(nonatomic, strong)NSMutableArray *targets;
@property(nonatomic, weak)NSData *outputSampleBuffer;
@property(nonatomic)CMTime outputSampleTime;
@property(nonatomic) NSInteger samplerate;
@property(nonatomic) NSInteger channels;
@property(nonatomic) NSInteger sampleFormat;


- (instancetype)initWithSamplerate:(NSInteger)sr channels:(NSInteger)chs sampleFormat:(NSInteger)fmt;
- (void)addTarget:(id<IJKAudioInput>)newTarget;
- (void)removeTarget:(id<IJKAudioInput>)targetToRemove;
- (void)removeAllTargets;
- (void)informTargetsAboutNewSample:(NSData*)newSample atTime:(CMTime)sampleTime;
@end
