//
//  IJKFrame.h


#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@interface IJKFrame : NSObject

@property (nonatomic, strong) NSData *data;
@property (nonatomic) CMTime pts;
@property (nonatomic) CMTime dts;

- (instancetype) initWithData:(NSData*)data
                          pts:(CMTime)pts
                          dts:(CMTime)dts;

@end
