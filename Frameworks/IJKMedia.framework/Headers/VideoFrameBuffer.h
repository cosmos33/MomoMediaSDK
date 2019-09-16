//
//  VideoFrameBuffer.h
//  IJKMedia
//
//  Created by wang.guijie on 3/13/17.
//  Copyright © 2017 MOMO. All rights reserved.
//

#ifndef VideoFrameBuffer_h
#define VideoFrameBuffer_h

typedef enum {
    VIDEO_FRAME_FORMAT_I420 = 1,
    VIDEO_FRAME_FORMAT_NV12 = 2,
    VIDEO_FRAME_FORMAT_RGB24 = 3,
} VideoFrameFormat;

typedef struct {
    VideoFrameFormat format;
    int width;
    int height;
    int planes;
    uint16_t *pitches;
    uint8_t **pixels;
    void *opaque;        /**CVPixelbuffer */
} VideoFrame;


#endif /* VideoFrameBuffer_h */
