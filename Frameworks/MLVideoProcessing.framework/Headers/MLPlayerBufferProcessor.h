//
//  MLPlayerBufferProcessor.h
//  MomoChat
//
//  Created by 杨乃川 on 2018/5/31.
//  Copyright © 2018年 wemomo.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MLPlayerBufferProcessor : NSObject
@property (nonatomic, assign) BOOL enable;

@property (nonatomic, assign) float  saturation;

@property (nonatomic, assign) float  sharpening;

 
// kCVPixelFormatType_1Monochrome    = 0x00000001, /* 1 bit indexed */
//kCVPixelFormatType_2Indexed       = 0x00000002, /* 2 bit indexed */
//kCVPixelFormatType_4Indexed       = 0x00000004, /* 4 bit indexed */
//kCVPixelFormatType_8Indexed       = 0x00000008, /* 8 bit indexed */
//kCVPixelFormatType_1IndexedGray_WhiteIsZero = 0x00000021, /* 1 bit indexed gray, white is zero */
//kCVPixelFormatType_2IndexedGray_WhiteIsZero = 0x00000022, /* 2 bit indexed gray, white is zero */
//kCVPixelFormatType_4IndexedGray_WhiteIsZero = 0x00000024, /* 4 bit indexed gray, white is zero */
//kCVPixelFormatType_8IndexedGray_WhiteIsZero = 0x00000028, /* 8 bit indexed gray, white is zero */
//kCVPixelFormatType_16BE555        = 0x00000010, /* 16 bit BE RGB 555 */
//kCVPixelFormatType_16LE555        = 'L555',     /* 16 bit LE RGB 555 */
//kCVPixelFormatType_16LE5551       = '5551',     /* 16 bit LE RGB 5551 */
//kCVPixelFormatType_16BE565        = 'B565',     /* 16 bit BE RGB 565 */
//kCVPixelFormatType_16LE565        = 'L565',     /* 16 bit LE RGB 565 */
//kCVPixelFormatType_24RGB          = 0x00000018, /* 24 bit RGB */
//kCVPixelFormatType_24BGR          = '24BG',     /* 24 bit BGR */
//kCVPixelFormatType_32ARGB         = 0x00000020, /* 32 bit ARGB */
//kCVPixelFormatType_32BGRA         = 'BGRA',     /* 32 bit BGRA */
//kCVPixelFormatType_32ABGR         = 'ABGR',     /* 32 bit ABGR */
//kCVPixelFormatType_32RGBA         = 'RGBA',     /* 32 bit RGBA */
//kCVPixelFormatType_64ARGB         = 'b64a',     /* 64 bit ARGB, 16-bit big-endian samples */
//kCVPixelFormatType_48RGB          = 'b48r',     /* 48 bit RGB, 16-bit big-endian samples */
//kCVPixelFormatType_32AlphaGray    = 'b32a',     /* 32 bit AlphaGray, 16-bit big-endian samples, black is zero */
//kCVPixelFormatType_16Gray         = 'b16g',     /* 16 bit Grayscale, 16-bit big-endian samples, black is zero */
//kCVPixelFormatType_30RGB          = 'R10k',     /* 30 bit RGB, 10-bit big-endian samples, 2 unused padding bits (at least significant end). */
//kCVPixelFormatType_422YpCbCr8     = '2vuy',     /* Component Y'CbCr 8-bit 4:2:2, ordered Cb Y'0 Cr Y'1 */
//kCVPixelFormatType_4444YpCbCrA8   = 'v408',     /* Component Y'CbCrA 8-bit 4:4:4:4, ordered Cb Y' Cr A */
//kCVPixelFormatType_4444YpCbCrA8R  = 'r408',     /* Component Y'CbCrA 8-bit 4:4:4:4, rendering format. full range alpha, zero biased YUV, ordered A Y' Cb Cr */
//kCVPixelFormatType_4444AYpCbCr8   = 'y408',     /* Component Y'CbCrA 8-bit 4:4:4:4, ordered A Y' Cb Cr, full range alpha, video range Y'CbCr. */
//kCVPixelFormatType_4444AYpCbCr16  = 'y416',     /* Component Y'CbCrA 16-bit 4:4:4:4, ordered A Y' Cb Cr, full range alpha, video range Y'CbCr, 16-bit little-endian samples. */
//kCVPixelFormatType_444YpCbCr8     = 'v308',     /* Component Y'CbCr 8-bit 4:4:4 */
//kCVPixelFormatType_422YpCbCr16    = 'v216',     /* Component Y'CbCr 10,12,14,16-bit 4:2:2 */
//kCVPixelFormatType_422YpCbCr10    = 'v210',     /* Component Y'CbCr 10-bit 4:2:2 */
//kCVPixelFormatType_444YpCbCr10    = 'v410',     /* Component Y'CbCr 10-bit 4:4:4 */
//kCVPixelFormatType_420YpCbCr8Planar = 'y420',   /* Planar Component Y'CbCr 8-bit 4:2:0.  baseAddr points to a big-endian CVPlanarPixelBufferInfo_YCbCrPlanar struct */
//kCVPixelFormatType_420YpCbCr8PlanarFullRange    = 'f420',   /* Planar Component Y'CbCr 8-bit 4:2:0, full range.  baseAddr points to a big-endian CVPlanarPixelBufferInfo_YCbCrPlanar struct */
//kCVPixelFormatType_422YpCbCr_4A_8BiPlanar = 'a2vy', /* First plane: Video-range Component Y'CbCr 8-bit 4:2:2, ordered Cb Y'0 Cr Y'1; second plane: alpha 8-bit 0-255 */
//kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange = '420v', /* Bi-Planar Component Y'CbCr 8-bit 4:2:0, video-range (luma=[16,235] chroma=[16,240]).  baseAddr points to a big-endian CVPlanarPixelBufferInfo_YCbCrBiPlanar struct */
//kCVPixelFormatType_420YpCbCr8BiPlanarFullRange  = '420f', /* Bi-Planar Component Y'CbCr 8-bit 4:2:0, full-range (luma=[0,255] chroma=[1,255]).  baseAddr points to a big-endian CVPlanarPixelBufferInfo_YCbCrBiPlanar struct */
//kCVPixelFormatType_422YpCbCr8_yuvs = 'yuvs',     /* Component Y'CbCr 8-bit 4:2:2, ordered Y'0 Cb Y'1 Cr */
//kCVPixelFormatType_422YpCbCr8FullRange = 'yuvf', /* Component Y'CbCr 8-bit 4:2:2, full range, ordered Y'0 Cb Y'1 Cr */
//kCVPixelFormatType_OneComponent8  = 'L008',     /* 8 bit one component, black is zero */
//kCVPixelFormatType_TwoComponent8  = '2C08',     /* 8 bit two component, black is zero */
//kCVPixelFormatType_30RGBLEPackedWideGamut = 'w30r', /* little-endian RGB101010, 2 MSB are zero, wide-gamut (384-895) */
//kCVPixelFormatType_ARGB2101010LEPacked = 'l10r',     /* little-endian ARGB2101010 full-range ARGB */
//kCVPixelFormatType_OneComponent16Half  = 'L00h',     /* 16 bit one component IEEE half-precision float, 16-bit little-endian samples */
//kCVPixelFormatType_OneComponent32Float = 'L00f',     /* 32 bit one component IEEE float, 32-bit little-endian samples */
//kCVPixelFormatType_TwoComponent16Half  = '2C0h',     /* 16 bit two component IEEE half-precision float, 16-bit little-endian samples */
//kCVPixelFormatType_TwoComponent32Float = '2C0f',     /* 32 bit two component IEEE float, 32-bit little-endian samples */
//kCVPixelFormatType_64RGBAHalf          = 'RGhA',     /* 64 bit RGBA IEEE half-precision float, 16-bit little-endian samples */
//kCVPixelFormatType_128RGBAFloat        = 'RGfA',     /* 128 bit RGBA IEEE float, 32-bit little-endian samples */
//kCVPixelFormatType_14Bayer_GRBG        = 'grb4',     /* Bayer 14-bit Little-Endian, packed in 16-bits, ordered G R G R... alternating with B G B G... */
//kCVPixelFormatType_14Bayer_RGGB        = 'rgg4',     /* Bayer 14-bit Little-Endian, packed in 16-bits, ordered R G R G... alternating with G B G B... */
//kCVPixelFormatType_14Bayer_BGGR        = 'bgg4',     /* Bayer 14-bit Little-Endian, packed in 16-bits, ordered B G B G... alternating with G R G R... */
//kCVPixelFormatType_14Bayer_GBRG        = 'gbr4',     /* Bayer 14-bit Little-Endian, packed in 16-bits, ordered G B G B... alternating with R G R G... */
//kCVPixelFormatType_DisparityFloat16     = 'hdis',     /* IEEE754-2008 binary16 (half float), describing the normalized shift when comparing two images. Units are 1/meters: ( pixelShift / (pixelFocalLength * baselineInMeters) ) */
//kCVPixelFormatType_DisparityFloat32     = 'fdis',     /* IEEE754-2008 binary32 float, describing the normalized shift when comparing two images. Units are 1/meters: ( pixelShift / (pixelFocalLength * baselineInMeters) ) */
//kCVPixelFormatType_DepthFloat16         = 'hdep',     /* IEEE754-2008 binary16 (half float), describing the depth (distance to an object) in meters */
//kCVPixelFormatType_DepthFloat32         = 'fdep',     /* IEEE754-2008 binary32 float, describing the depth (distance to an object) in meters */
//kCVPixelFormatType_420YpCbCr10BiPlanarVideoRange = 'x420', /* 2 plane YCbCr10 4:2:0, each 10 bits in the MSBs of 16bits, video-range (luma=[64,940] chroma=[64,960]) */
//kCVPixelFormatType_422YpCbCr10BiPlanarVideoRange = 'x422', /* 2 plane YCbCr10 4:2:2, each 10 bits in the MSBs of 16bits, video-range (luma=[64,940] chroma=[64,960]) */
//kCVPixelFormatType_444YpCbCr10BiPlanarVideoRange = 'x444', /* 2 plane YCbCr10 4:4:4, each 10 bits in the MSBs of 16bits, video-range (luma=[64,940] chroma=[64,960]) */
//kCVPixelFormatType_420YpCbCr10BiPlanarFullRange  = 'xf20', /* 2 plane YCbCr10 4:2:0, each 10 bits in the MSBs of 16bits, full-range (Y range 0-1023) */
//kCVPixelFormatType_422YpCbCr10BiPlanarFullRange  = 'xf22', /* 2 plane YCbCr10 4:2:2, each 10 bits in the MSBs of 16bits, full-range (Y range 0-1023) */
//kCVPixelFormatType_444YpCbCr10BiPlanarFullRange  = 'xf44', /* 2 plane YCbCr10 4:4:4, each 10 bits in the MSBs of 16bits, full-range (Y range 0-1023) */

@property (nonatomic) long  pixelBufferFormatType;
- (CVPixelBufferRef)pixelBufferWithPlayerBuffer:(CVPixelBufferRef)pixelBuffer CF_RETURNS_NOT_RETAINED;

@end
