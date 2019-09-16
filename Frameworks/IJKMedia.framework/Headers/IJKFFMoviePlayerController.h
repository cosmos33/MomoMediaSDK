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

#import "IJKMediaPlayback.h"
#import "IJKFFOptions.h"
#import "pulldetect.h"

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
#define k_IJKM_KEY_CHANNELS       @"channels"

#define kk_IJKM_KEY_STREAMS       @"streams"

typedef enum IJKLogLevel {
    k_IJK_LOG_UNKNOWN = 0,
    k_IJK_LOG_DEFAULT = 1,

    k_IJK_LOG_VERBOSE = 2,
    k_IJK_LOG_DEBUG   = 3,
    k_IJK_LOG_INFO    = 4,
    k_IJK_LOG_WARN    = 5,
    k_IJK_LOG_ERROR   = 6,
    k_IJK_LOG_FATAL   = 7,
    k_IJK_LOG_SILENT  = 8,
} IJKLogLevel;

@interface IJKFFMoviePlayerController : NSObject <IJKMediaPlayback>

- (id)initWithContentURL:(NSURL *)aUrl
             withOptions:(IJKFFOptions *)options;

- (id)initWithContentURL:(NSURL *)aUrl
             withOptions:(IJKFFOptions *)options
     withSegmentResolver:(id<IJKMediaSegmentResolver>)segmentResolver;

- (id)initWithContentURLString:(NSString *)aUrlString
                   withOptions:(IJKFFOptions *)options
           withSegmentResolver:(id<IJKMediaSegmentResolver>)segmentResolver;

- (id)initWithContentURLString:(NSString *)aUrlString
                   withConfigs:(int)configs
           withSegmentResolver:(id<IJKMediaSegmentResolver>)segmentResolver
                      withView:(UIView*)view;

- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;

- (void)unregisterApplicationObserverAll;

- (void)setPauseInBackground:(BOOL)pause;
- (BOOL)isVideoToolboxOpen;

+ (void)setLogReport:(BOOL)preferLogReport;
+ (void)setLogLevel:(IJKLogLevel)logLevel;

@property(nonatomic, readonly) CGFloat fpsInMeta;
@property(nonatomic, readonly) CGFloat fpsAtOutput;

@property (nonatomic,readonly) NSDictionary *mediaMetadata;

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
- (void)setPlayerDisableAudio;
- (void)setPlayerDisableVideo;

- (uint64_t)currentPlaybackPts;
- (void)setPlayerSpeedRate: (float)rate;

- (void)setSpeedControl:(int) normaldur fastDur:(int) fasterdur fastRate:(float) fasterrate veryfastDur:(int) veryfasterdur veryfastRate:(float) veryfasterrate;

// momo live modify
- (void)mlSetLowerLatency:(Boolean)enable
                 withBase:(int)base
         withSpeedTrigger:(int)speed_trigger
          withDropTrigger:(int)drop_trigger
            withSpeedRate:(double)speed_rate;

- (void)mlSetHighWaterMark:(int)hwm_start
               withCurrent:(int)hwm_current
                  withNext:(int)hwm_next
                   withMax:(int)hwm_max
         withCheckInterval:(int)hwm_check_interval;

- (int)mlGetCurrentHighWaterMark;
// momo live modify end

//调用-prepareToPlay前设置是否用于非直播业务，默认NO，用于区分部分业务相关的处理
- (void)setPlaybackOnly:(BOOL)playbackOnly;
//设置循环播放次数，默认1，设为0表示无限循环
- (void)setLoop:(int)loop;
//播放配置调试参数,defaultWater 首次buffer时长, nextWather 非首次buffer时长,checkTick 检测间隔
- (void)setIJKPlayOption:(int)defaultWater nextWater:(int)nextWater checkTick:(int)checkTick;
//是否延迟销毁，默认NO
- (void)setDelayDestroy:(BOOL)delayDestroy;
//是否忽略硬解码错误，默认YES
- (void)setIgnoreVTDErr:(BOOL)ignore;
//关闭播放器，完成时回调completion。正常关闭finished为YES，若调用时已关闭或关闭中finished为NO
- (void)shutdownWithCompletion:(void (^)(BOOL finished))completion;
- (void)shutdownWithDetectCompletion:(void (^)(BOOL finished, HttpDetecter *httpDetect, int detectCount))completion;
//打开多音轨，默认不打开
- (void)openAudioTracks:(BOOL)enable;
//设置播放的音轨，默认是1，只有打开多音轨才支持设置，如双音轨可设置1、2
- (void)setAudioTrackIndex:(int)index;

#ifdef DEBUG_DUMP_FILE
- (void)setDumpFilename: (NSString *)filename;
#endif

- (float const)playerSpeedRate;
- (NSString*const)getServerIpAddr;
- (NSString*const)getCDNIpAddr;
- (NSString*const)getClientIpAddr;
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
- (int)getHttpDetectInfoWithHttpDetecter: (HttpDetecter *)httpDetecter;
- (uint64_t)getStreamMetaTime;
- (uint64_t)getFirstVideoReceiveTime;
- (uint64_t)getFirstAudioReceiveTime;
- (uint64_t)getFirstVideoDecodeTime;
- (uint64_t)getFirstAudioDecodeTime;
- (uint64_t)getFirstVideoRenderTime;
- (uint64_t)getFirstAudioRenderTime;
- (uint32_t)getStreamCount;
- (NSData *)getH264SEI;
- (double)getVideoBufferDurationInSec;

//call getVideoSize after observeMoviePlayerPlaybackVideoRendering
- (CGSize)getVideoSize;

//when screen record start set flag YES, or set flag NO
- (void)recordAudio:(BOOL)enable;
//when live aid push audio, start set flag YES, or set flag NO
- (void)switchAudioCallback:(BOOL)enable;
//set audio playback volume (0 ~ 1.0)
- (void)setAudioPlaybackVolume:(float)volume;
//origin pcm data without process
- (void)switchOriginAudioCallback:(BOOL)enable;

- (void)mlSetMaxBufferCache:(int)max_buffer_cache;

- (void)setDynamicBuffer:(BOOL)enable;

- (void)setMaxDropBaseCache:(int)max_drop_base;
@end

#define IJK_FF_IO_TYPE_READ (1)



