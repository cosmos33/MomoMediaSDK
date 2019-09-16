//
//  IJKSplitAudioPlayer.h
//  IJKMedia
//
//  Created by zhai.jianfeng on 12/10/15.
//  Copyright © 2015 bilibili. All rights reserved.
//

#import "IJKMediaPlayback.h"
#import "IJKFFOptions.h"

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

typedef enum IJKAudioLogLevel {
    k_IJK_AUDIO_LOG_UNKNOWN = 0,
    k_IJK_AUDIO_LOG_DEFAULT = 1,
    
    k_IJK_AUDIO_LOG_VERBOSE = 2,
    k_IJK_AUDIO_LOG_DEBUG   = 3,
    k_IJK_AUDIO_LOG_INFO    = 4,
    k_IJK_AUDIO_LOG_WARN    = 5,
    k_IJK_AUDIO_LOG_ERROR   = 6,
    k_IJK_AUDIO_LOG_FATAL   = 7,
    k_IJK_AUDIO_LOG_SILENT  = 8,
} IJKAudioLogLevel;

@protocol IJKAudioSpliter <NSObject>
-(void)queueSample:(NSData*)data samplerate:(NSInteger)sr channels:(NSInteger)chs samplesize:(NSInteger)ss;
-(NSInteger)getSampleRate;
-(NSInteger)getChannel;
-(NSInteger)getSampleFormat;
@end

@interface IJKAudioPlayerController : NSObject <IJKMediaPlayback>

@property(nonatomic, weak) id<IJKAudioSpliter>spliteDelegate;
- (id)initWithContentURLString:(NSString *)aUrlString
                   withConfigs:(int)configs
           withSegmentResolver:(id<IJKMediaSegmentResolver>)segmentResolver;

- (void)decodeWithoutPlay;
- (void)prepareToPlay;
- (void)play;
- (void)pause;
- (void)stop;
- (BOOL)isPlaying;

- (void)unregisterApplicationObserverAll;

- (void)setPauseInBackground:(BOOL)pause;
- (BOOL)isVideoToolboxOpen;

@property(nonatomic, readonly) CGFloat fpsInMeta;
@property(nonatomic, readonly) CGFloat fpsAtOutput;

- (void)setFormatOptionValue:       (NSString *)value forKey:(NSString *)key;
- (void)setCodecOptionValue:        (NSString *)value forKey:(NSString *)key;
- (void)setSwsOptionValue:          (NSString *)value forKey:(NSString *)key;
- (void)setPlayerOptionValue:       (NSString *)value forKey:(NSString *)key;

- (void)setFormatOptionIntValue:    (int64_t)value forKey:(NSString *)key;
- (void)setCodecOptionIntValue:     (int64_t)value forKey:(NSString *)key;
- (void)setSwsOptionIntValue:       (int64_t)value forKey:(NSString *)key;
- (void)setPlayerOptionIntValue:    (int64_t)value forKey:(NSString *)key;
- (NSTimeInterval)currentPlaybackPosition;
- (uint64_t)currentPlaybackPts;
#pragma add for mixerfilter

#pragma do not useful
- (void)setPlayerSpeedRate: (float)rate;
- (float)playerSpeedRate;
- (NSString *)getServerIpAddr;
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

- (NSData*)get_audio_decoded_sample;

- (void)setDumpFullPathFilename:(char *)fullPathFilename;
@end
