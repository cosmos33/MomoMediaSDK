//Created By zhang.jialiang
#ifndef AV_DETECT_URL_H
#define AV_DETECT_URL_H

#define MAX_URL_SIZE 4096
#define MAX_HTTP_RECONNECT_TIMES (10)
typedef struct HttpDetecter {
    uint64_t timestamp;                                         //本地时间戳, 毫秒， 以下所有计时都以此为开始时间
    int unixErrno;                                              // 系统错误码, linux GetLastErrcode, 默认为0
    int ffmpegErrno;                                              // ffmpeg 错误码, 默认为0
    uint64_t dnsTime;                                            // dns 解析耗时,  毫秒
    uint64_t tcpConnectTime;                                    // tcp 从拉流到连接成功耗时, 毫秒
    uint64_t httpTime;                                          // 从发起拉流请求到收到http 200 ok / 302跳转 耗时，毫秒
    int httpResponseCode;                                       // http response 返回码
    uint64_t firstPacketTime;                                   //开始拉流到收到第一包数据所耗时间， 毫秒
    uint64_t firstIFrameTime;                                   //开始拉流到第一个I帧到达所耗时间， 毫秒
    char url[MAX_URL_SIZE];                                             //拉流地址，若存在302跳转， 则为302跳转后的url
    char cdnIp[128+1];                                             // cdn节点ip， 失败时为0.0.0.0, 若存在302跳转，则为跳转后的cdnip
}HttpDetecter;

#endif
