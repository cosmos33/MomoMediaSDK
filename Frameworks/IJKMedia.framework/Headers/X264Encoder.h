//
//  VTBH264Encoder.h
//  IJKMedia
//
//  Created by wang.guijie@immomo.com on 5/12/16.
//  Copyright © 2015 immomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IJKVideoEncoder.h"

@interface X264Encoder :IJKVideoEncoder
-(void)setUserDefineSeiPayload:(NSData *)seiPayload;
-(NSData *)getUserDefineSeiData;
@end
