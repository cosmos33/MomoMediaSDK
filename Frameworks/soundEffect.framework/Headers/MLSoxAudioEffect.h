//
//  MLSoxAudioEffect.h
//  soxSoundEffects
//
//  Created by MOMO on 2019/1/8.
//  Copyright © 2019年 MOMO. All rights reserved.
//

#ifndef MLSoxAudioEffect_h
#define MLSoxAudioEffect_h
@interface MLSoxAudioEffect : NSObject

@property (nonatomic, readonly) int sampleRate;
@property (nonatomic, readonly) int channel;

- (void)openWithSampleRate:(int)sampleRate channel:(int)channel frameLength:(int)frameLength;
- (void)close;
- (NSData *)processData:(NSData *)input;

@end

#endif /* MLSoxAudioEffect_h */
