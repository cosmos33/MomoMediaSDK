//
//  IJKAudioEncoder.h


#import "IJKEncoder.h"

@interface IJKAudioEncoder : IJKEncoder

@property (nonatomic) NSUInteger sampleRate;
@property (nonatomic) NSUInteger channels;

- (instancetype) initWithBitrate:(NSUInteger)bitrate sampleRate:(NSUInteger)sampleRate channels:(NSUInteger)channels;

@end
