//
//  MomoMediaEngine.h
//  Pods
//
//  Created by hrs on 2019/8/29.
//

#ifndef MomoMediaEngine_h
#define MomoMediaEngine_h
#import <Foundation/Foundation.h>
@class MomoMediaPlayer;
@protocol MomoMediaPlayerDelegate <NSObject>
@optional
- (void)MomoMediaPlayerStartRendering:(MomoMediaPlayer*)player; //播放器开始渲染
- (void)MomoMediaPlayerDidFinish:(MomoMediaPlayer*)player; //播放正常结束
- (void)MomoMediaPlayerFailed:(MomoMediaPlayer*)player; //播放失败
- (void)MomoMediaPlayerStartBuffer:(MomoMediaPlayer*)player; //播放卡顿开始
- (void)MomoMediaPlayerEndBuffer:(MomoMediaPlayer*)player; //播放卡顿结束
@end

@interface MomoMediaPlayerConfiguration : NSObject
//暂时没有参数添加
@end

@interface MomoMediaPlayer : NSObject

@property (nonatomic, weak) id<MomoMediaPlayerDelegate> delegate;
//配置拉流参数,此处正式没有参数.
@property (nonatomic, strong) MomoMediaPlayerConfiguration *config;
//正在拉流的状态,1正在拉流,0拉流结束
@property (nonatomic, assign) BOOL isPlaying;

//初始化播放器,可以通过此接口传入view和url,也可以分别通过startPlayWithURL和setupOnContainerView来设置view和url
- (instancetype)initWithURL:(NSString*)url view:(UIView *)view;

//开始播放,带播放地址的开始,
- (void)startPlayWithURL:(NSString*)url;

//设置预览
- (void)setupOnContainerView:(UIView *)containerView;

//开始播放
- (void)startPlay;

//停止播放
- (void)stopPlay;

//设置播放模式,暂时没有实现
- (void)setAudioRoute:(int)audioRoute;

//音量大小,volume 范围0~1
- (void)setVolume:(float)volume;

//暂停播放
- (void)pause;

//恢复播放,暂时没有实现
- (void)resume;
@end

#endif /* MomoMediaEngine_h */
