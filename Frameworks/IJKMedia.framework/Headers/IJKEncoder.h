//
//  IJKEncoder.h
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class IJKFrame, IJKEncoder;

@protocol IJKSampleBufferEncoder <NSObject>
- (void) encodeSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end

@protocol IJKEncoderDelegate <NSObject>
- (void) encoder:(IJKEncoder*)encoder encodedFrame:(IJKFrame*)frame;
@end

@interface IJKEncoder : NSObject

@property (nonatomic) NSUInteger bitrate;
@property (nonatomic) dispatch_queue_t callbackQueue;
@property (nonatomic, weak) id<IJKEncoderDelegate> delegate;

- (instancetype) initWithBitrate:(NSUInteger)bitrate;
- (void) stopProcess:(NSError**)error;
@end
