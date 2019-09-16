//
//  VideoEncoder.h

#import <Foundation/Foundation.h>
#import "AVFoundation/AVAssetWriter.h"
#import "AVFoundation/AVAssetWriterInput.h"
#import "AVFoundation/AVMediaFormat.h"
#import "AVFoundation/AVVideoSettings.h"

@interface VideoEncoder : NSObject
{
    AVAssetWriter* _writer;
    AVAssetWriterInput* _writerInput;
//    AVAssetWriterInputPixelBufferAdaptor *_writerPixelBufferInput;
    NSString* _path;
}
@property (nonatomic, readonly, nullable) CVPixelBufferPoolRef pixelBufferPool;
@property NSString* path;
@property (nonatomic, readonly) NSUInteger bitrate;
@property (nonatomic, readonly, nullable) AVAssetWriterInputPixelBufferAdaptor * writerPixelBufferInput;
+ (VideoEncoder*) encoderForPath:(NSString*) path Height:(int) height andWidth:(int) width bitrate:(int)bitrate;

- (void) initPath:(NSString*)path Height:(int) height andWidth:(int) width bitrate:(int)bitrate;
- (void) finishWithCompletionHandler:(void (^)(void))handler;
- (BOOL) encodeFrame:(CMSampleBufferRef) sampleBuffer;
- (BOOL) encodePixelFrame:(nonnull CVPixelBufferRef) pixelBuffer prestime:(CMTime)frameTime;
- (void) prepareForEncode;
- (void)stopProcess:(NSError ** )error;

@end
