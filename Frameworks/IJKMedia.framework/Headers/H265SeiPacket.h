//
//  H265SeiPacket.h
//  IJKMedia
//
//  Created by wangqiangqiang on 2018/8/15.
//  Copyright © 2018年 MOMO. All rights reserved.
//

#ifndef h265_sei_packet_h
#define h265_sei_packet_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t h265_sei_get_packet_size(uint32_t contentSize);

//Annexb数据包里有startcode
int h265_sei_fill_packet(unsigned char * packet, bool isAnnexb, const char * content, uint32_t contentSize);
 
#endif /* h265_sei_packet_h */
