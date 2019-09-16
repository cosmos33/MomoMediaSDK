//
//  MomoMediaEngine.h
//  Pods
//
//  Created by hrs on 2019/8/29.
//

#ifndef MomoMediaEngine_h
#define MomoMediaEngine_h
#import <Foundation/Foundation.h>
@class MomoMediaPublisher;
@protocol MomoMediaPublisherDelegate <NSObject>

@optional
// 推流器开始推流
- (void)MomoMediaEngineDidStartPublishing:(MomoMediaPublisher*)publisher error:(NSError*)error;
// 推流器停止推流
- (void)MomoMediaEngineDidStopPublishing:(MomoMediaPublisher*)publisher error:(NSError*)error;
// 推流器推流失败
- (void)MomoMediaEnginePublishingFailed:(MomoMediaPublisher *)publisher error:(NSError*)error;
// 推流卡顿开始
- (void)MomoMediaEnginePublishingStartBuffer:(MomoMediaPublisher*)publisher error:(NSError*)error;
// 推流卡顿结束
- (void)MomoMediaEnginePublishingEndBuffer:(MomoMediaPublisher *)publisher error:(NSError*)error;
@end

@interface MomoMediaPublishConfiguration : NSObject
//分辨率
@property(nonatomic, assign) CGSize videoEncodeSize;
//帧率
@property(nonatomic, assign) int videoFPS;
//视频编码码率（单位bps）
@property(nonatomic, assign) int videoBitRate;
@property(nonatomic, assign) BOOL enableAutoBitRate;
@property(nonatomic, assign) int videoBitRateMax;
@property(nonatomic, assign) int videoBitRateMin;
//码率（音频）
@property(nonatomic, assign) int audioSampleRate;
//音频声道数
@property(nonatomic, assign) int audioChannels;
//音频编码码率(单位bps)
@property(nonatomic, assign) int audioBitRate;
//耳返
@property(nonatomic, assign) BOOL enableAudioPreview;
//噪声抑制
@property(nonatomic, assign) BOOL enableNAS;

@end

@protocol MLStreamMediaDataConsumer;
@interface MomoMediaPublisher : NSObject <MLStreamMediaDataConsumer>

@property (nonatomic, weak) id<MomoMediaPublisherDelegate> delegate;

//当前的推流状态,1为正在推流,0位推流结束.
@property (nonatomic, assign) BOOL isPushing;

@property(nonatomic,readonly) NSString *rtmpURL;

//可以动态的设置耳返
@property(nonatomic, assign) BOOL enableAudioPreview;

//初始化推流器,如果通过setupOnContainerView设置view,此处的view设置为nil
- (instancetype)initWithMomoMediaPublisher:(UIView *)view inputVideoSize:(CGSize)inputVideoSize;

//设置预览
- (void)setupOnContainerView:(UIView *)containerView;
//设置推流参数
- (void)setPublishConfig:(MomoMediaPublishConfiguration*)config;
//设置推流地址
- (void)startPublish:(NSString*)rtmpURL;
//停止推流
- (void)stopPublish;

- (void)setMute:(BOOL)bEnable;//设置静音

- (void)pausePublish;//退后台调用该接口

- (void)resumePublish;//回前台恢复推流调用该接口
@end
#endif /* MomoMediaEngine_h */
