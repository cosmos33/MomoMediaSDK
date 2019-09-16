/*
 * IJKFFMoviePlayerController.h
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

#include "VideoFrameBuffer.h"
#import "IJKMediaPlayback.h"
#import "IJKFFOptions.h"
#import "IJKSDLGLView.h"

// media meta
#define k_IJKM_KEY_FORMAT         @"format"
#define k_IJKM_KEY_DURATION_US    @"duration_us"
#define k_IJKM_KEY_START_US       @"start_us"
#define k_IJKM_KEY_BITRATE        @"bitrate"

// stream meta
#define k_IJKM_KEY_TYPE           @"type"
#define k_IJKM_VAL_TYPE__VIDEO    @"video"
#define k_IJKM_VAL_TYPE__AUDIO    @"audio"
#define k_IJKM_VAL_TYPE__UNKNOWN  @"unknown"

#define k_IJKM_KEY_CODEC_NAME      @"codec_name"
#define k_IJKM_KEY_CODEC_PROFILE   @"codec_profile"
#define k_IJKM_KEY_CODEC_LONG_NAME @"codec_long_name"

// stream: video
#define k_IJKM_KEY_WIDTH          @"width"
#define k_IJKM_KEY_HEIGHT         @"height"
#define k_IJKM_KEY_FPS_NUM        @"fps_num"
#define k_IJKM_KEY_FPS_DEN        @"fps_den"
#define k_IJKM_KEY_TBR_NUM        @"tbr_num"
#define k_IJKM_KEY_TBR_DEN        @"tbr_den"
#define k_IJKM_KEY_SAR_NUM        @"sar_num"
#define k_IJKM_KEY_SAR_DEN        @"sar_den"
// stream: audio
#define k_IJKM_KEY_SAMPLE_RATE    @"sample_rate"
#define k_IJKM_KEY_CHANNEL_LAYOUT @"channel_layout"

#define kk_IJKM_KEY_STREAMS       @"streams"

typedef enum {
    audioType = 0,
    videoType = 1,
} MediaType;

typedef enum IJKConferenceLogLevel {
    k_IJK_CONFERENCE_LOG_UNKNOWN = 0,
    k_IJK_CONFERENCE_LOG_DEFAULT = 1,

    k_IJK_CONFERENCE_LOG_VERBOSE = 2,
    k_IJK_CONFERENCE_LOG_DEBUG   = 3,
    k_IJK_CONFERENCE_LOG_INFO    = 4,
    k_IJK_CONFERENCE_LOG_WARN    = 5,
    k_IJK_CONFERENCE_LOG_ERROR   = 6,
    k_IJK_CONFERENCE_LOG_FATAL   = 7,
    k_IJK_CONFERENCE_LOG_SILENT  = 8,
} IJKConferenceLogLevel;

@protocol IJKFFConferencePlayerControllerDelegate <NSObject>
-(void) startRender;
-(void) videoFrameCallback:(VideoFrame *)vp;
@end

@interface IJKFFConferencePlayerController : NSObject <IJKMediaPlayback>

- (id)initWithContentURLStringWithDelegate:(id<IJKFFConferencePlayerControllerDelegate>)delegate
                                aUrlString:(NSString *)aUrlString
                               withConfigs:(int)configs
                       withSegmentResolver:(id<IJKMediaSegmentResolver>)segmentResolver
                                renderView:(IJKSDLGLView *)renderView;

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;

- (void)unregisterApplicationObserverAll;

- (void)setPauseInBackground:(BOOL)pause;
- (BOOL)isVideoToolboxOpen;
- (void)enableVideoFrameCallback:(BOOL)enable;

+ (void)setLogReport:(BOOL)preferLogReport;
+ (void)setLogLevel:(IJKConferenceLogLevel)logLevel;

@property(nonatomic, readonly) CGFloat fpsInMeta;
@property(nonatomic, readonly) CGFloat fpsAtOutput;

- (void)setOptionValue:(NSString *)value
                forKey:(NSString *)key
            ofCategory:(IJKFFOptionCategory)category;

- (void)setOptionIntValue:(NSInteger)value
                   forKey:(NSString *)key
               ofCategory:(IJKFFOptionCategory)category;

- (void)setFormatOptionValue:       (NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:        (NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:          (NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:       (NSString *)value forKey:(NSString *)key;

- (void)setFormatOptionIntValue:    (int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:     (int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:       (int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:    (int64_t)value forKey:(NSString *)key;

- (uint64_t)currentPlaybackPts;
- (void)setPlayerSpeedRate: (float)rate;
- (float const)playerSpeedRate;
- (NSString*const)getServerIpAddr;
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

- (uint64_t)getLastVideoRenderTimeInMs;
- (void)putConferenceDataWithType:(MediaType)mediaType data:(uint8_t *)data size:(int)size pts:(int64_t)pts keyFrame:(BOOL)keyFrame;
- (void)setVideoExtradata:(void *)data len:(int)len width:(int)width height:(int)height;
@end

#define IJK_FF_IO_TYPE_READ (1)


