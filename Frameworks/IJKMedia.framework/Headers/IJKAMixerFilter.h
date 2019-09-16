//
//  IJKAMixerFilter.h
//  IJKMedia
//
//  Created by zhai.jianfeng on 12/10/15.
//  Copyright © 2015 bilibili. All rights reserved.
//

#import "IJKAudioFilter.h"
#import "IJKAudioPlayerController.h"

@interface IJKAMixerFilter : IJKAudioFilter <IJKAudioSpliter>
@property(strong) NSMutableArray *slaverSamples;
@property (nonatomic, assign) float micVolume;
@property (nonatomic, assign) float musicVolume;
@end
