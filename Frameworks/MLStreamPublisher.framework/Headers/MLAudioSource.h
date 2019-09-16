//
//  MLAudioSource.h
//  MomoChat
//
//  Created by wangqiangqiang on 2017/5/4.
//  Copyright © 2017年 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MLStreamMediaSource.h"

FOUNDATION_EXPORT NSString * const MLAudioCpatureAdjustAudioTimestampNotification;

@interface MLAudioSource : NSObject <MLStreamMediaSource>

@property (nonatomic, assign) BOOL audioOutputEnabled;
@property (nonatomic, assign) BOOL audioMuteEnabled;
@property (nonatomic, assign) BOOL notManagerAudioSession;
@property (nonatomic, assign) BOOL useVpio;

- (instancetype)init UNAVAILABLE_ATTRIBUTE;
- (instancetype)initWithAudioSampleRate:(int)sampleRate audioChannels:(int)numberOfChannels;
- (instancetype)initWithAudioSampleRate:(int)sampleRate audioChannels:(int)numberOfChannels useVpio:(BOOL)enable;
- (void)applicationWillResignActive:(NSNotification *)notification;
- (void)applicationDidBecomeActive:(NSNotification *)notification;
@end
