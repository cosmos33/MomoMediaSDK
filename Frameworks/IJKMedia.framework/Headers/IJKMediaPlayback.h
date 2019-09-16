/*
 * IJKMediaPlayback.h
 *
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
//#import <MediaPlayer/MediaPlayer.h>
#import <MediaPlayer/MPMoviePlayerController.h>

@protocol IJKMediaPlayback;


#pragma mark IJKMediaPlayback

@protocol IJKMediaPlayback <NSObject>

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;
- (void)shutdown;
- (void)setPauseInBackground:(BOOL)pause;
- (void)setMute:(BOOL)mute;
- (NSString *const)getServerIpAddr;
- (void)setPlayerSpeedRate: (float)rate;
- (float const)playerSpeedRate;
- (uint64_t)currentPlaybackPts;
- (long)getStreamReceiveSize;

- (long)getAudioReceiveSize;
- (long)getVideoReceiveSize;
- (long)getAudioCacheDuration;
- (long)getVideoCacheDuration;
- (long)getAudioDecodeSize;
- (long)getVideoDecodeCount;
- (long)getAudioRenderSize;
- (long)getVideoRenderCount;

- (uint64_t)getMetaTime;
- (uint64_t)getTcpConnectTime;
- (uint64_t)getStreamMetaTime;
- (uint64_t)getFirstVideoReceiveTime;
- (uint64_t)getFirstAudioReceiveTime;
- (uint64_t)getFirstVideoDecodeTime;
- (uint64_t)getFirstAudioDecodeTime;
- (uint64_t)getFirstVideoRenderTime;
- (uint64_t)getFirstAudioRenderTime;
- (uint32_t)getStreamCount;


@property(nonatomic, readonly)  UIView *view;
@property(nonatomic)            NSTimeInterval currentPlaybackTime;
@property(nonatomic, readonly)  NSTimeInterval duration;
@property(nonatomic, readonly)  NSTimeInterval playableDuration;
@property(nonatomic, readonly)  NSInteger bufferingProgress;

@property(nonatomic, readonly)  BOOL isPreparedToPlay;
@property(nonatomic, readonly)  MPMoviePlaybackState playbackState;
@property(nonatomic, readonly)  MPMovieLoadState loadState;

@property(nonatomic, readonly) int64_t numberOfBytesTransferred;

@property(nonatomic) MPMovieControlStyle controlStyle;
@property(nonatomic) MPMovieScalingMode scalingMode;
@property(nonatomic) BOOL shouldAutoplay;

@property (nonatomic) BOOL allowsMediaAirPlay;
@property (nonatomic) BOOL isDanmakuMediaAirPlay;
@property (nonatomic, readonly) BOOL airPlayMediaActive;

- (UIImage *)thumbnailImageAtCurrentTime;

#pragma mark Notifications

#ifdef __cplusplus
#define IJK_EXTERN extern "C" __attribute__((visibility ("default")))
#else
#define IJK_EXTERN extern __attribute__((visibility ("default")))
#endif

IJK_EXTERN NSString *const IJKMediaPlaybackIsPreparedToPlayDidChangeNotification;

IJK_EXTERN NSString *const IJKMoviePlayerLoadStateDidChangeNotification;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackDidFinishNotification;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackStateDidChangeNotification;

IJK_EXTERN NSString *const IJKMoviePlayerIsAirPlayVideoActiveDidChangeNotification;
IJK_EXTERN NSString *const IJKMoviePlayerVideoDecoderOpenNotification;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackFastSpeedStartedNotification;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackFastSpeedStoppedNotification;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackVideoRenderingNotification;

// momo live modify
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackFastDropStartedNotification;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackFastDropStoppedNotification;
// momo live modify end

IJK_EXTERN NSString *const IJKMoviePlayerPlaybackUpdateH264SEI;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackPostAudioPacket;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackPostAudioCallback;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackPostOriginAudioCallback;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackVideoSizeChanged;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackWindowSizeChanged;

IJK_EXTERN NSString *const IJKMoviePlayerPlaybackLoopStart;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackCurrentGop;

IJK_EXTERN NSString *const IJKMoviePlayerPlaybackRestartAudioQueue;

IJK_EXTERN NSString *const IJKMoviePlayerPlaybackVideoTsBackError;
IJK_EXTERN NSString *const IJKMoviePlayerPlaybackChangeMaxBuffer;
@end

#pragma mark IJKMediaResource

@protocol IJKMediaSegmentResolver <NSObject>

- (NSString *)urlOfSegment:(int)segmentPosition;

@end
