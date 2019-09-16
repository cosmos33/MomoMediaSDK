//
//  MLAudioProcess.h
//  MomoChat
//
//  Created by MOMO on 2017/7/10.
//  Copyright © 2017年 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MLAudioProcess : NSObject

// pitch, -10 - 10
- (int)pitchShift:(NSData *)data
          withRate:(int)sample_rate
       withChannel:(int)channels
         withPitch:(int)pitch;

// eq, -4 - 4
- (int)paramEQ:(NSData *)data
      withRate:(int)sample_rate
   withChannel:(int)channels
        withEQ:(int)eq;

// aefilter
// 1 - monster, 2 - baby, 3 - robot male, 4 - robot female
- (int)aeFilter:(NSData *)data
       withRate:(int)sample_rate
    withChannel:(int)channels
       withType:(int)type;

@end
