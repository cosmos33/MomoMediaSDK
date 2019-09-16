//
//  MDPlayerCacheManager.h
//  IJKMedia
//
//  Created by lm on 17/2/24.
//  Copyright © 2017年 MOMO. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NSDictionary* (^MDUrlPostParamsBlock)(NSString **urlSting);

extern NSString* kCleanVideoNotificationKey;

@class MDResourceLoader;
@interface MDPlayerCacheManager : NSObject

//设置播放器和预加载配置
- (void)setCacheOptions:(NSDictionary*)options;

//根据urlString获取请求参数
- (void)setPostParamsBlock:(MDUrlPostParamsBlock)paramBlock;

//添加预加载缓存任务列表
- (void)addPreDownLoadTaskWithUrlStrList:(NSArray*)list;

//添加播放任务, 全局会保存唯一变量
- (MDResourceLoader*)addPlayTaskWithUrl:(NSString*)urlStr;

//全局不会保存, 直接返回一个临时变量
- (MDResourceLoader*)addNewPlayTaskWithUrl:(NSString*)urlStr;

//暂停正在下载任务
- (void)suspendAllDownLoadTask;

//恢复正在下载任务
- (void)resumeAllDownLoadTask;

//删除所有缓存
- (void)removeAllCache;

//删除url对应缓存
- (void)removeCacheWithUrl:(NSString*)urlStr;

//播放下载停止
- (void)stopPlayingDownLoad;

//根据清理规则，清理磁盘缓存
- (void)cleanCache;

@end
