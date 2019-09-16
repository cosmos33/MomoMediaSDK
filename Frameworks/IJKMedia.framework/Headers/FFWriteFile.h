//
//  FFWriteFile.h
//  ExampleRecorder
//
//  Created by wangqiangqiang on 2016/10/29.
//  Copyright © 2016年 Alan Skipp. All rights reserved.
//

#ifndef FFWriteFile_h
#define FFWriteFile_h

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface FFWriteFile : NSObject

- (BOOL)startWithPath:(NSString *)path fileFormat:(NSString *)format;
- (void)stop;

- (void)addVideoStreamWithWidth:(int)width height:(int)height bitrate:(int)vBitrate;
- (void)addAudioStreamWithSampleRate:(int)sampleRate channels:(int)channelNum bitrate:(int)aBitrate isHeAAC:(BOOL)isHigh;

- (void)pushDate:(NSData *)data
             pts:(CMTime)pts
             dts:(CMTime)dts
        isParams:(BOOL)isParams
         isVideo:(BOOL)isVideo
      isKeyFrame:(BOOL)isKeyFrame;

+ (double)getFileDuration:(NSString*)path;
@end

#endif /* FFWriteFile_h */
