//
//  MLVideoRecorder.h
//  MLVideoProcessing
//
//  Created by 杨乃川 on 2019/4/28.
//

#import <Foundation/Foundation.h>
@import AVFoundation;

NS_ASSUME_NONNULL_BEGIN
@interface MLVideoRecorderOption : NSObject<NSCopying>
@property (nonatomic, assign) NSUInteger frameRate;
@property (nonatomic, assign) NSUInteger secondInLength;
@property (nonatomic, copy) NSString  *fileName;
@property (nonatomic, copy) NSString  *prefix;
@property (nonatomic, copy) NSString  *surfix;
@property (nonatomic, assign) NSUInteger  bitRate;
@property (nonatomic, assign) CGSize  videoSize;
@property (nonatomic, assign) BOOL audioEnable;

@end

@interface MLVideoRecorder : NSObject

@property (nonatomic, assign) BOOL readyToPrepare;

- (instancetype)initWithFileName:(NSString *)name frameRate:(NSUInteger)frameRate secondInLength:(NSUInteger)second;
+ (instancetype)new NS_UNAVAILABLE;

+ (NSArray <NSURL *>*)videoFiles;

+ (void)deleteVideoFileWithURL:(NSURL *)url error:(NSError **)error;

- (void)prepareRecorderOption:(MLVideoRecorderOption *)option error:(NSError **)error;

- (void)feedSampleBuffer:(CMSampleBufferRef)sampleBuffer;

- (void)videoRecording:(nullable void(^)(float percentage))processing fileSaved:(nullable void(^)(NSURL * _Nullable localURL,  NSError * _Nullable error))completion; // percentage 100.0 means completion

@end




NS_ASSUME_NONNULL_END
