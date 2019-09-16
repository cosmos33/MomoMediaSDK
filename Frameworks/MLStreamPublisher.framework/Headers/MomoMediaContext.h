//
//  MomoMediaContext.h
//  Pods
//
//  Created by hrs on 2019/9/6.
//

#ifndef MomoMediaContext_h
#define MomoMediaContext_h

#import <Foundation/Foundation.h>

@interface MomoMediaContext : NSObject

#pragma mark - getter
/**
 获取当前sdk版本号

 @return 当前sdk版本号
 */
+ (NSString *)sdkVersion;

/**
 获取当前设置的user id

 @return user id
 */
+ (NSString *)userID;

/**
 获取当前设置的room id

 @return room id
 */
+ (NSString *)roomID;

/**
 获取当前设置的app id

 @return app id
 */
+ (NSString *)appid;

/**
 获取当前设置的app秘钥

 @return app秘钥
 */
+ (NSString *)secret;

/**
 获取当前设置的app私有版本号（注意：是私有版本号，非appsStore显示的公开版本）

 @return app私有版本号
 */
+ (NSString *)appVerNum;

#pragma mark - setter
/**
 设置room id

 @param roomID room id
 */
+ (void)setRoomID:(NSString *)roomID;


#pragma mark - init method
/**
 初始化sdk

 @param appId app唯一标识
 @param secret app对应的sdk秘钥
 @param appVerNum app私有版本号（注意：是私有版本号，公开版本号无需设置，sdk内自动读取工程配置）
 @param userId 用户id
 */
+ (void)initSDKWithAppId:(NSString *)appId
                  secret:(NSString *)secret
               appVerNum:(NSString *)appVerNum
                  userId:(NSString *)userId;

@end
#endif /* MomoMediaContext_h */
