//
//  IJKVideoEncoder.h


#import "IJKEncoder.h"

@interface IJKVideoEncoder : IJKEncoder

@property (nonatomic, readwrite) NSUInteger width;
@property (nonatomic, readwrite) NSUInteger height;
@property (nonatomic, readonly, nullable) CVPixelBufferPoolRef pixelBufferPool;
@property (nonatomic, strong, nullable) NSMutableData *videoSPSandPPS;
@property (atomic) BOOL isStart;
@property (nonatomic, assign) BOOL useDataRateLimit;  //default NO

- (_Nonnull instancetype) initWithBitrate:(NSUInteger)bitrate width:(int)width height:(int)height;
- (BOOL) encodePixelBuffer:(nonnull CVPixelBufferRef)pixerBuffer prestime:(CMTime)frameTime duration:(CMTime)duration;
- (void) prepareForEncode;
- (uint64_t) getTotalBytesProduct;
- (uint64_t) getLatestDtsInMs;
- (void)setUserDefineSeiPayload:(NSData *_Nullable)seiPayload;
- (NSData *_Nonnull)getUserDefineSeiData;
- (void)dynamicChangeBitrate:(int)bitrate;
@end
