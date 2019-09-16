//
//  AACEncoder.h
//  FFmpegEncoder
//

#import "IJKAudioEncoder.h"
#import "IJKAudioOutput.h"
@interface IJKAACEncoder : IJKAudioEncoder <IJKAudioInput>

@property (nonatomic) dispatch_queue_t encoderQueue;
@property (nonatomic) BOOL addADTSHeader;
@end
@interface CacheBuf : NSObject

@end
