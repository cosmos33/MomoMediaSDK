//
//  MDResourceLoader.h
//  IJKMedia
//
//  Created by lm on 17/2/23.
//  Copyright © 2017年 MOMO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IJKFFMoviePlayerController.h"
extern NSString *kPreDownLoadFinish;
extern NSString *kPreDownLoaderName;
extern NSString *kVideoConfigSyncFinish;
extern NSString *kDownLoadingSize;
extern NSString * const kDownloadingUrl;

/**
 加载代理，可用于实现缓存、预加载、自定义网络请求等。
 在调用IJKFFMoviePlayerController的-prepareToPlay之前设置数据源启用。
 通过给播放器的AVFormatContext设置自定义AVIOContext实现。
 */
@interface MDResourceLoader : NSOperation

//url对应的缓存地址
+(NSString*)cachePathWithUrl:(NSString*)urlStr;

- (instancetype)initWithUrl:(NSURL*)url frameCount:(NSInteger)maxPreLoadFrameCount cacheRootPath:(NSString*)rootPath;

- (void)setHttpParams:(NSDictionary*)paramDict;

- (BOOL)isPlayingDownLoadFinish;

- (NSString*)relativePath;

- (void)stopLoading;

/**
 文件长度，小于0表示未读取或读取失败
 */
@property (atomic, assign, readonly) int64_t totalSize;

/**
 当前读取数据的偏移
 */
@property (atomic, assign, readonly) uint64_t currentOffset;

//加载标记
@property (nonatomic, assign) BOOL   enableDownLoad;

@property (nonatomic, assign) int  defaultCacheSize;
@property (nonatomic, assign) BOOL useBlockDownLoad; //直接整块下载, 不解帧

@end

@interface IJKFFMoviePlayerController (MDResourceLoader)

/**
 设置资源加载器，可在调用-prepareToPlay之前设置。若未设置则不启用资源加载器，播放器按正常方式请求和加载数据。
 
 @param resourceloader 资源加载器
 */
- (void)setResourceLoader:(MDResourceLoader *)resourceloader;

- (id)resourceLoader;

@end
