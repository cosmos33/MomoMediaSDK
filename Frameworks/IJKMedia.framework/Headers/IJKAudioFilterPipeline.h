//
//  IJKAudioFilterPipeline.h
//  IJKMediaPublisherDemo
//
//  Created by zhai.jianfeng on 12/10/15.
//  Copyright © 2015 zhai.jianfeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "IJKAudioFilter.h"
@interface IJKAudioFilterPipeline : NSObject

@property (nonatomic, strong) IJKAudioOutput *input;
@property (nonatomic, strong) id <IJKAudioInput> output;
@property (nonatomic, strong) NSMutableArray *filters;

- (id) initWithOrderedFilters:(NSArray*) filters input:(IJKAudioOutput*)input output:(id <IJKAudioInput>)output;
- (void) addFilter:(IJKAudioOutput<IJKAudioInput> *)filter;
- (void) addFilter:(IJKAudioOutput<IJKAudioInput> *)filter atIndex:(NSUInteger)insertIndex;
- (void) replaceFilterAtIndex:(NSUInteger)index withFilter:(IJKAudioOutput<IJKAudioInput> *)filter;
- (void) replaceAllFilters:(NSArray *) newFilters;
- (void) removeFilter:(IJKAudioOutput<IJKAudioInput> *)filter;
- (void) removeFilterAtIndex:(NSUInteger)index;
- (void) removeAllFilters;
@end


