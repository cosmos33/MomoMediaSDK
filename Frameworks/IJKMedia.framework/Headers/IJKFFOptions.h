/*
 * IJKFFOptions.h
 *
 * Copyright (c) 2013-2015 Zhang Rui <bbcallen@gmail.com>
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

typedef enum IJKFFOptionCategory {
    kIJKFFOptionCategoryFormat = 1,
    kIJKFFOptionCategoryCodec  = 2,
    kIJKFFOptionCategorySws    = 3,
    kIJKFFOptionCategoryPlayer = 4,
} IJKFFOptionCategory;

// for codec option 'skip_loop_filter' and 'skip_frame'
typedef enum IJKAVDiscard {
    /* We leave some space between them for extensions (drop some
     * keyframes for intra-only or drop just some bidir frames). */
    IJK_AVDISCARD_NONE    =-16, ///< discard nothing
    IJK_AVDISCARD_DEFAULT =  0, ///< discard useless packets like 0 size packets in avi
    IJK_AVDISCARD_NONREF  =  8, ///< discard all non reference
    IJK_AVDISCARD_BIDIR   = 16, ///< discard all bidirectional frames
    IJK_AVDISCARD_NONKEY  = 32, ///< discard all frames except keyframes
    IJK_AVDISCARD_ALL     = 48, ///< discard all
} IJKAVDiscard;

typedef struct IjkMediaPlayer IjkMediaPlayer;

@interface IJKFFOptions : NSObject

+(IJKFFOptions *)optionsByDefault;
+(IJKFFOptions *)optionsByDefaultWithConfigs:(int)configs;
-(void)applyTo:(IjkMediaPlayer *)mediaPlayer;

- (void)setOptionValue:(NSString *)value
                forKey:(NSString *)key
            ofCategory:(IJKFFOptionCategory)category;

- (void)setOptionIntValue:(int64_t)value
                   forKey:(NSString *)key
               ofCategory:(IJKFFOptionCategory)category;


-(void)setFormatOptionValue:       (NSString *)value forKey:(NSString *)key;
-(void)setCodecOptionValue:        (NSString *)value forKey:(NSString *)key;
-(void)setSwsOptionValue:          (NSString *)value forKey:(NSString *)key;
-(void)setPlayerOptionValue:       (NSString *)value forKey:(NSString *)key;

-(void)setFormatOptionIntValue:    (int64_t)value forKey:(NSString *)key;
-(void)setCodecOptionIntValue:     (int64_t)value forKey:(NSString *)key;
-(void)setSwsOptionIntValue:       (int64_t)value forKey:(NSString *)key;
-(void)setPlayerOptionIntValue:    (int64_t)value forKey:(NSString *)key;

-(void)setMaxFps:(int)value;
-(void)setFrameDrop:(int)value;
-(void)setVideoPictureSize:(int)value;
-(void)setVideoToolboxEnabled:(BOOL)value;
-(void)setVideoToolboxMaxFrameWidth:(int)value;

-(void)setReconnect:(int)value;
-(void)setTimeout:(int64_t)value;
-(void)setUserAgent:(NSString *)value;

-(void)setSkipLoopFilter:(IJKAVDiscard)value;
-(void)setSkipFrame:(IJKAVDiscard)value;
#define VTB_CONFIG_OFFSET 1
#define LOOP_FILTER_CONFIG_OFFSET 4
#define SKIP_FRAME_CONFIG_OFFSET 4

#define VTB_ENABLE_MASK (1 << VTB_CONFIG_OFFSET)
#define LOOP_FILTER_MASK (1 << LOOP_FILTER_CONFIG_OFFSET)
#define SKIP_FRAME_MASK (1 << SKIP_FRAME_CONFIG_OFFSET)

@end

typedef NS_OPTIONS(NSUInteger, MDIJKPlayerConfigsMask) {
    MDIJKPlayerConfigsMaskVTBEnable = VTB_ENABLE_MASK,
    MDIJKPlayerConfigsMaskLoopFilter = LOOP_FILTER_MASK,
    MDIJKPlayerConfigsMaskSkipFrame = SKIP_FRAME_MASK,
    MDIJKPlayerConfigsMaskNotManageAudioSession = 1 << 16, //是否不由播放器管理AudioSession
    MDIJKPlayerConfigsMaskNotManageIdleTimer = 1 << 17, //是否不由播放器管理IdleTimer
    MDIJKPlayerConfigsMaskNoFastFindStream = 1 << 18, //是否不使用fastFindStream
    MDIJKPlayerConfigsMaskAudioQueueRestartEnable = 1 << 19 //是否重启audioqueue
};
