//
//  IJKAudioFilter.h
//  IJKMediaPublisherDemo
//
//  Created by zhai.jianfeng on 12/10/15.
//  Copyright © 2015 zhai.jianfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IJKAudioOutput.h"

@interface IJKAudioFilter : IJKAudioOutput <IJKAudioInput>


- (void)informTargetsAboutNewSample:(NSData*)newSample atTime:(CMTime)sampleTime;
- (void)processAudioSample:(NSData*)newInputSamplebuffer;
@end


