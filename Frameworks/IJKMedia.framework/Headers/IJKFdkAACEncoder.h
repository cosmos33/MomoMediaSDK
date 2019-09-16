//
//  IJKFdkAACEncoder.h
//  IJKMedia
//
//  Created by MOMO on 2019/3/21.
//  Copyright © 2019年 MOMO. All rights reserved.
//

#ifndef IJKFdkAACEncoder_h
#define IJKFdkAACEncoder_h
#import "IJKAudioEncoder.h"
#import "IJKAudioOutput.h"
@interface IJKFdkAACEncoder : IJKAudioEncoder <IJKAudioInput>

@property (nonatomic) dispatch_queue_t encoderQueue;
@property (nonatomic) BOOL addADTSHeader;
@end
@interface FdkCacheBuf : NSObject

@end

#endif /* IJKFdkAACEncoder_h */
