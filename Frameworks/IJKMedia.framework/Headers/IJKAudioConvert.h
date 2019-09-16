//
//  IJKAudioConvert.h
//  IJKMedia
//
//  Created by wangqiangqiang on 2016/11/21.
//  Copyright © 2016年 MOMO. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IJKAudioConvert : NSObject

@property(nonatomic) int sampleRate;
@property(nonatomic) int channels;

- (instancetype)initWithSampleRate:(int)sampleRate channels:(int)channels;

- (NSData *)convert:(NSData *)data sampleRate:(int)sampleRate channels:(int)channels;

@end
