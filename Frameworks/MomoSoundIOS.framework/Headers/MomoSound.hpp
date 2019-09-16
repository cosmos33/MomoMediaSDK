//
//  MomoSound.hpp
//  Lixiaoming 
//
//  Created by allen on 2017/7/11.
//  Copyright © 2017年 MOMO_I128. All rights reserved.
//

#ifndef _MomoSound_H_
#define _MomoSound_H_

#include <stdio.h>
#include <string.h>
#include <cmath>
#include <vector>

#ifndef _INT16_T
#define _INT16_T
typedef	short			int16_t;
#endif /* _INT16_T */

using namespace std;
#define MAX_FRAME_LENGTH 8192
//变调和EQ分别提供两个独立的借口，具体的接口定义如下：
//变调模块：
typedef struct
{
    int     rate;       // 采样率
    int     nChannels;  // 声道数
    int     pitch;      // 基频变调范围 -10 ～ 10。  defalut = 0
    int     nReserved[4]; //保留字段
} Ctrl_Params_SoundTune;

//EQ模块：
//控制参数为：
typedef struct
{
    int     rate;       // 采样率
    int     nChannels;  // 声道数
    int     sndMode;    // EQ模式：-4 ～ 4   defalut = 0
    int     nReserved[4]; //保留字段
} Ctrl_Params_SoundEq;

typedef struct
{
    int     rate;       // 采样率
    int     nChannels;  // 声道数
    int     type;       // 类型 0:原音 1:怪兽音 2:娃娃音 3:机器人（偏男音） 4:机器人（偏女音）
    int     nReserved[4]; //保留字段
} Ctrl_Params_AEFilter;


//函数接口：

//变调函数接口：
class SoundPitchShift {
    const int FRAMENUM;
public:
    SoundPitchShift();
    ~SoundPitchShift();
    void ProcessSound(char*  input_buf, int input_len, Ctrl_Params_SoundTune &params, char*  ret_ptr, int* ret_len);
    void Init(Ctrl_Params_SoundTune &params);
private:
    int nSamples;
    int buffSizeSamples;
    int buffSizeProc;
    void* pitchshift_ptr;
    int delay;
    int out_len;
    int pitch_old;
    int16_t *out_ptr;
    std::vector<int16_t> outbuf;
};

//EQ函数接口：
class SoundParamEq {
public:
    SoundParamEq();
    ~SoundParamEq();
    
    int ProcessSound(const char* input_buf, int input_len, Ctrl_Params_SoundEq &params , char* ret_ptr, int* ret_len);
private:
    std::vector<float> history;
};

class AEFilter{
    int max_overlap_size;
public:
    AEFilter();
    ~AEFilter();

    bool ProcessSound(char* input_ptr, int input_len, Ctrl_Params_AEFilter &params, char* ret_ptr, int* ret_len);
    
private:
    void *SoundPitchShift_ptr_;
    void *SoundPitchShift_ptr2_;
    void *SoundParamEq_ptr_;
    std::vector<char> overlap_buf;
    std::vector<char> overlap_buf2;
    std::vector<int16_t> tmp;
};



#endif /* _MomoSound_H_ */
