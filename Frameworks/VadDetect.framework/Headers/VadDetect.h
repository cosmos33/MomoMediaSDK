//
//  vadDetect.h
//  VadDetect
//
//  Created by hrs on 2019/6/18.
//  Copyright © 2019 hrs. All rights reserved.
//

#ifndef vadDetect_h
#define vadDetect_h
#import <Foundation/Foundation.h>
@interface VadDetect: NSObject
/*
 * samplerate Valid values are 8000, 16000, 32000 and 48000.
 * channel Valid values are 1, 2. The default is 1.
 * mode Valid modes are 0 ("quality"), 1 ("low bitrate"), 2 ("aggressive"), and 3
 * ("very aggressive"). The default mode is 0.
 */
- (void)createVadDetect:(int)samplerate channels:(int)channel mode:(int)mode;

- (int)fvad_process:(NSData*)inputData length:(size_t)length;

- (void)fvad_free;
@end

#endif /* vadDetect_h */
