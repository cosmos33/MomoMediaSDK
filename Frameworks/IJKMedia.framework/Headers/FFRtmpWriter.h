//
//  FFRtmpWriter.h

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@protocol FFRtmpWriterDelegate <NSObject>
- (void) writeFailedWithError:(NSError*)error;
//- (void) netwowkTooSlow;
@end

@interface FFRtmpWriter : NSObject

@property (nonatomic, copy) NSString *uuid;
@property (nonatomic) dispatch_queue_t conversionQueue;
@property (nonatomic, strong, readonly) NSString *streamPath;
@property(nonatomic, weak) id<FFRtmpWriterDelegate> delegate;
@property(nonatomic) BOOL isEnableDynamicBitrate;
@property(nonatomic, assign) BOOL isRealtimeSend;

- (instancetype) initWithStreamPath:(NSString *)path serverTime:(int64_t)serverTime;

- (void) addVideoStreamWithWidth:(int)width height:(int)height bitrate:(int)vBitrate;
- (void) addVideoStreamWithWidth:(int)width height:(int)height bitrate:(int)vBitrate useHevc:(BOOL)enable;
- (void) addAudioStreamWithSampleRate:(int)sampleRate channels:(int)channelNum bitrate:(int)aBitrate;

- (BOOL) prepareForWriting:(NSError**)error;

- (void) processEncodedData:(NSData*)data presentationTimestamp:(CMTime)pts streamIndex:(NSUInteger)streamIndex isKeyFrame:(BOOL)isKeyFrame; // TODO refactor this

- (void) processEncodedData:(NSData*)data
      presentationTimestamp:(CMTime)pts
            decodeTimestamp:(CMTime)dts
                streamIndex:(NSUInteger)streamIndex
                 isKeyFrame:(BOOL)isKeyFrame;

- (BOOL) finishWriting:(NSError**)error;
-(void)setVideoExtradata:(NSData *) extradata;
-(int)videoStreamIdx;
-(int)audioStreamIdx;
- (NSString*)getIpAddr;
- (long)getMuxSize;
- (long)getSendSize;
- (uint64_t)getTcpConnectTime;
- (uint64_t)getSendDataTime;

- (int32_t)getCacheDurationInMs;
- (int32_t)getAudioCacheDurationInMs;
- (int32_t)getVideoCachePacket;
- (int32_t)getAudioCachePacket;
- (long) getBufferLen;

- (uint64_t)getFirstDtsInMs;
- (uint64_t)getLatestDtsInMs;
- (uint64_t)getTotalSendOutBytes;
@end
