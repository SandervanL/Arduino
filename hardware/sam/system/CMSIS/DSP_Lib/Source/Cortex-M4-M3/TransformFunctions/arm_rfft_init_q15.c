/* ----------------------------------------------------------------------  
* Copyright (C) 2010 ARM Limited. All rights reserved.  
*  
* $Date:        29. November 2010  
* $Revision: 	V1.0.3  
*  
* Project: 	    CMSIS DSP Library  
* Title:	    arm_rfft_init_q15.c  
*  
* Description:	RFFT & RIFFT Q15 initialisation function  
*  
* Target Processor: Cortex-M4/Cortex-M3
*  
* Version 1.0.3 2010/11/29 
*    Re-organized the CMSIS folders and updated documentation.  
*   
* Version 1.0.2 2010/11/11  
*    Documentation updated.   
*  
* Version 1.0.1 2010/10/05   
*    Production release and review comments incorporated.  
*  
* Version 1.0.0 2010/09/20   
*    Production release and review comments incorporated  
*  
* Version 0.0.7  2010/06/10   
*    Misra-C changes done  
* -------------------------------------------------------------------- */ 
 
 
#include "arm_math.h" 
 
/**  
 * @ingroup groupTransforms  
 */ 
 
/**  
 * @addtogroup RFFT_RIFFT  
 * @{  
 */ 
 
 
 
/**  
* \par  
* Generation floating point real_CoefA array:  
* \par  
* n = 1024  
* <pre>for (i = 0; i < n; i++)  
*  {  
*    pATable[2 * i] = 0.5 * (1.0 - sin (2 * PI / (double) (2 * n) * (double) i));  
*    pATable[2 * i + 1] = 0.5 * (-1.0 * cos (2 * PI / (double) (2 * n) * (double) i));  
*  } </pre>  
* \par  
* Convert to fixed point Q15 format  
*       round(pATable[i] * pow(2, 15))  
*/ 
 
 
static const q15_t realCoefAQ15[2048] = { 
 
  0x4000, 0xc000, 0x3fce, 0xc000, 0x3f9b, 0xc000, 0x3f69, 0xc001, 
  0x3f37, 0xc001, 0x3f05, 0xc002, 0x3ed2, 0xc003, 0x3ea0, 0xc004, 
  0x3e6e, 0xc005, 0x3e3c, 0xc006, 0x3e09, 0xc008, 0x3dd7, 0xc009, 
  0x3da5, 0xc00b, 0x3d73, 0xc00d, 0x3d40, 0xc00f, 0x3d0e, 0xc011, 
  0x3cdc, 0xc014, 0x3caa, 0xc016, 0x3c78, 0xc019, 0x3c45, 0xc01c, 
  0x3c13, 0xc01f, 0x3be1, 0xc022, 0x3baf, 0xc025, 0x3b7d, 0xc029, 
  0x3b4b, 0xc02c, 0x3b19, 0xc030, 0x3ae6, 0xc034, 0x3ab4, 0xc038, 
  0x3a82, 0xc03c, 0x3a50, 0xc041, 0x3a1e, 0xc045, 0x39ec, 0xc04a, 
  0x39ba, 0xc04f, 0x3988, 0xc054, 0x3956, 0xc059, 0x3924, 0xc05e, 
  0x38f2, 0xc064, 0x38c0, 0xc069, 0x388e, 0xc06f, 0x385c, 0xc075, 
  0x382a, 0xc07b, 0x37f9, 0xc081, 0x37c7, 0xc088, 0x3795, 0xc08e, 
  0x3763, 0xc095, 0x3731, 0xc09c, 0x36ff, 0xc0a3, 0x36ce, 0xc0aa, 
  0x369c, 0xc0b1, 0x366a, 0xc0b9, 0x3639, 0xc0c0, 0x3607, 0xc0c8, 
  0x35d5, 0xc0d0, 0x35a4, 0xc0d8, 0x3572, 0xc0e0, 0x3540, 0xc0e9, 
  0x350f, 0xc0f1, 0x34dd, 0xc0fa, 0x34ac, 0xc103, 0x347b, 0xc10c, 
  0x3449, 0xc115, 0x3418, 0xc11e, 0x33e6, 0xc128, 0x33b5, 0xc131, 
  0x3384, 0xc13b, 0x3352, 0xc145, 0x3321, 0xc14f, 0x32f0, 0xc159, 
  0x32bf, 0xc163, 0x328e, 0xc16e, 0x325c, 0xc178, 0x322b, 0xc183, 
  0x31fa, 0xc18e, 0x31c9, 0xc199, 0x3198, 0xc1a4, 0x3167, 0xc1b0, 
  0x3136, 0xc1bb, 0x3105, 0xc1c7, 0x30d5, 0xc1d3, 0x30a4, 0xc1df, 
  0x3073, 0xc1eb, 0x3042, 0xc1f7, 0x3012, 0xc204, 0x2fe1, 0xc210, 
  0x2fb0, 0xc21d, 0x2f80, 0xc22a, 0x2f4f, 0xc237, 0x2f1f, 0xc244, 
  0x2eee, 0xc251, 0x2ebe, 0xc25f, 0x2e8d, 0xc26d, 0x2e5d, 0xc27a, 
  0x2e2d, 0xc288, 0x2dfc, 0xc296, 0x2dcc, 0xc2a5, 0x2d9c, 0xc2b3, 
  0x2d6c, 0xc2c1, 0x2d3c, 0xc2d0, 0x2d0c, 0xc2df, 0x2cdc, 0xc2ee, 
  0x2cac, 0xc2fd, 0x2c7c, 0xc30c, 0x2c4c, 0xc31c, 0x2c1c, 0xc32b, 
  0x2bed, 0xc33b, 0x2bbd, 0xc34b, 0x2b8d, 0xc35b, 0x2b5e, 0xc36b, 
  0x2b2e, 0xc37b, 0x2aff, 0xc38c, 0x2acf, 0xc39c, 0x2aa0, 0xc3ad, 
  0x2a70, 0xc3be, 0x2a41, 0xc3cf, 0x2a12, 0xc3e0, 0x29e3, 0xc3f1, 
  0x29b4, 0xc403, 0x2984, 0xc414, 0x2955, 0xc426, 0x2926, 0xc438, 
  0x28f7, 0xc44a, 0x28c9, 0xc45c, 0x289a, 0xc46e, 0x286b, 0xc481, 
  0x283c, 0xc493, 0x280e, 0xc4a6, 0x27df, 0xc4b9, 0x27b1, 0xc4cc, 
  0x2782, 0xc4df, 0x2754, 0xc4f2, 0x2725, 0xc506, 0x26f7, 0xc51a, 
  0x26c9, 0xc52d, 0x269b, 0xc541, 0x266d, 0xc555, 0x263f, 0xc569, 
  0x2611, 0xc57e, 0x25e3, 0xc592, 0x25b5, 0xc5a7, 0x2587, 0xc5bb, 
  0x2559, 0xc5d0, 0x252c, 0xc5e5, 0x24fe, 0xc5fa, 0x24d0, 0xc610, 
  0x24a3, 0xc625, 0x2476, 0xc63b, 0x2448, 0xc650, 0x241b, 0xc666, 
  0x23ee, 0xc67c, 0x23c1, 0xc692, 0x2394, 0xc6a8, 0x2367, 0xc6bf, 
  0x233a, 0xc6d5, 0x230d, 0xc6ec, 0x22e0, 0xc703, 0x22b3, 0xc71a, 
  0x2287, 0xc731, 0x225a, 0xc748, 0x222d, 0xc75f, 0x2201, 0xc777, 
  0x21d5, 0xc78f, 0x21a8, 0xc7a6, 0x217c, 0xc7be, 0x2150, 0xc7d6, 
  0x2124, 0xc7ee, 0x20f8, 0xc807, 0x20cc, 0xc81f, 0x20a0, 0xc838, 
  0x2074, 0xc850, 0x2049, 0xc869, 0x201d, 0xc882, 0x1ff1, 0xc89b, 
  0x1fc6, 0xc8b5, 0x1f9b, 0xc8ce, 0x1f6f, 0xc8e8, 0x1f44, 0xc901, 
  0x1f19, 0xc91b, 0x1eee, 0xc935, 0x1ec3, 0xc94f, 0x1e98, 0xc969, 
  0x1e6d, 0xc983, 0x1e42, 0xc99e, 0x1e18, 0xc9b8, 0x1ded, 0xc9d3, 
  0x1dc3, 0xc9ee, 0x1d98, 0xca09, 0x1d6e, 0xca24, 0x1d44, 0xca3f, 
  0x1d19, 0xca5b, 0x1cef, 0xca76, 0x1cc5, 0xca92, 0x1c9b, 0xcaad, 
  0x1c72, 0xcac9, 0x1c48, 0xcae5, 0x1c1e, 0xcb01, 0x1bf5, 0xcb1e, 
  0x1bcb, 0xcb3a, 0x1ba2, 0xcb56, 0x1b78, 0xcb73, 0x1b4f, 0xcb90, 
  0x1b26, 0xcbad, 0x1afd, 0xcbca, 0x1ad4, 0xcbe7, 0x1aab, 0xcc04, 
  0x1a82, 0xcc21, 0x1a5a, 0xcc3f, 0x1a31, 0xcc5d, 0x1a08, 0xcc7a, 
  0x19e0, 0xcc98, 0x19b8, 0xccb6, 0x198f, 0xccd4, 0x1967, 0xccf3, 
  0x193f, 0xcd11, 0x1917, 0xcd30, 0x18ef, 0xcd4e, 0x18c8, 0xcd6d, 
  0x18a0, 0xcd8c, 0x1878, 0xcdab, 0x1851, 0xcdca, 0x182a, 0xcde9, 
  0x1802, 0xce08, 0x17db, 0xce28, 0x17b4, 0xce47, 0x178d, 0xce67, 
  0x1766, 0xce87, 0x173f, 0xcea7, 0x1719, 0xcec7, 0x16f2, 0xcee7, 
  0x16cb, 0xcf07, 0x16a5, 0xcf28, 0x167f, 0xcf48, 0x1659, 0xcf69, 
  0x1632, 0xcf8a, 0x160c, 0xcfab, 0x15e6, 0xcfcc, 0x15c1, 0xcfed, 
  0x159b, 0xd00e, 0x1575, 0xd030, 0x1550, 0xd051, 0x152a, 0xd073, 
  0x1505, 0xd094, 0x14e0, 0xd0b6, 0x14bb, 0xd0d8, 0x1496, 0xd0fa, 
  0x1471, 0xd11c, 0x144c, 0xd13e, 0x1428, 0xd161, 0x1403, 0xd183, 
  0x13df, 0xd1a6, 0x13ba, 0xd1c9, 0x1396, 0xd1eb, 0x1372, 0xd20e, 
  0x134e, 0xd231, 0x132a, 0xd255, 0x1306, 0xd278, 0x12e2, 0xd29b, 
  0x12bf, 0xd2bf, 0x129b, 0xd2e2, 0x1278, 0xd306, 0x1255, 0xd32a, 
  0x1231, 0xd34e, 0x120e, 0xd372, 0x11eb, 0xd396, 0x11c9, 0xd3ba, 
  0x11a6, 0xd3df, 0x1183, 0xd403, 0x1161, 0xd428, 0x113e, 0xd44c, 
  0x111c, 0xd471, 0x10fa, 0xd496, 0x10d8, 0xd4bb, 0x10b6, 0xd4e0, 
  0x1094, 0xd505, 0x1073, 0xd52a, 0x1051, 0xd550, 0x1030, 0xd575, 
  0x100e, 0xd59b, 0xfed, 0xd5c1, 0xfcc, 0xd5e6, 0xfab, 0xd60c, 
  0xf8a, 0xd632, 0xf69, 0xd659, 0xf48, 0xd67f, 0xf28, 0xd6a5, 
  0xf07, 0xd6cb, 0xee7, 0xd6f2, 0xec7, 0xd719, 0xea7, 0xd73f, 
  0xe87, 0xd766, 0xe67, 0xd78d, 0xe47, 0xd7b4, 0xe28, 0xd7db, 
  0xe08, 0xd802, 0xde9, 0xd82a, 0xdca, 0xd851, 0xdab, 0xd878, 
  0xd8c, 0xd8a0, 0xd6d, 0xd8c8, 0xd4e, 0xd8ef, 0xd30, 0xd917, 
  0xd11, 0xd93f, 0xcf3, 0xd967, 0xcd4, 0xd98f, 0xcb6, 0xd9b8, 
  0xc98, 0xd9e0, 0xc7a, 0xda08, 0xc5d, 0xda31, 0xc3f, 0xda5a, 
  0xc21, 0xda82, 0xc04, 0xdaab, 0xbe7, 0xdad4, 0xbca, 0xdafd, 
  0xbad, 0xdb26, 0xb90, 0xdb4f, 0xb73, 0xdb78, 0xb56, 0xdba2, 
  0xb3a, 0xdbcb, 0xb1e, 0xdbf5, 0xb01, 0xdc1e, 0xae5, 0xdc48, 
  0xac9, 0xdc72, 0xaad, 0xdc9b, 0xa92, 0xdcc5, 0xa76, 0xdcef, 
  0xa5b, 0xdd19, 0xa3f, 0xdd44, 0xa24, 0xdd6e, 0xa09, 0xdd98, 
  0x9ee, 0xddc3, 0x9d3, 0xdded, 0x9b8, 0xde18, 0x99e, 0xde42, 
  0x983, 0xde6d, 0x969, 0xde98, 0x94f, 0xdec3, 0x935, 0xdeee, 
  0x91b, 0xdf19, 0x901, 0xdf44, 0x8e8, 0xdf6f, 0x8ce, 0xdf9b, 
  0x8b5, 0xdfc6, 0x89b, 0xdff1, 0x882, 0xe01d, 0x869, 0xe049, 
  0x850, 0xe074, 0x838, 0xe0a0, 0x81f, 0xe0cc, 0x807, 0xe0f8, 
  0x7ee, 0xe124, 0x7d6, 0xe150, 0x7be, 0xe17c, 0x7a6, 0xe1a8, 
  0x78f, 0xe1d5, 0x777, 0xe201, 0x75f, 0xe22d, 0x748, 0xe25a, 
  0x731, 0xe287, 0x71a, 0xe2b3, 0x703, 0xe2e0, 0x6ec, 0xe30d, 
  0x6d5, 0xe33a, 0x6bf, 0xe367, 0x6a8, 0xe394, 0x692, 0xe3c1, 
  0x67c, 0xe3ee, 0x666, 0xe41b, 0x650, 0xe448, 0x63b, 0xe476, 
  0x625, 0xe4a3, 0x610, 0xe4d0, 0x5fa, 0xe4fe, 0x5e5, 0xe52c, 
  0x5d0, 0xe559, 0x5bb, 0xe587, 0x5a7, 0xe5b5, 0x592, 0xe5e3, 
  0x57e, 0xe611, 0x569, 0xe63f, 0x555, 0xe66d, 0x541, 0xe69b, 
  0x52d, 0xe6c9, 0x51a, 0xe6f7, 0x506, 0xe725, 0x4f2, 0xe754, 
  0x4df, 0xe782, 0x4cc, 0xe7b1, 0x4b9, 0xe7df, 0x4a6, 0xe80e, 
  0x493, 0xe83c, 0x481, 0xe86b, 0x46e, 0xe89a, 0x45c, 0xe8c9, 
  0x44a, 0xe8f7, 0x438, 0xe926, 0x426, 0xe955, 0x414, 0xe984, 
  0x403, 0xe9b4, 0x3f1, 0xe9e3, 0x3e0, 0xea12, 0x3cf, 0xea41, 
  0x3be, 0xea70, 0x3ad, 0xeaa0, 0x39c, 0xeacf, 0x38c, 0xeaff, 
  0x37b, 0xeb2e, 0x36b, 0xeb5e, 0x35b, 0xeb8d, 0x34b, 0xebbd, 
  0x33b, 0xebed, 0x32b, 0xec1c, 0x31c, 0xec4c, 0x30c, 0xec7c, 
  0x2fd, 0xecac, 0x2ee, 0xecdc, 0x2df, 0xed0c, 0x2d0, 0xed3c, 
  0x2c1, 0xed6c, 0x2b3, 0xed9c, 0x2a5, 0xedcc, 0x296, 0xedfc, 
  0x288, 0xee2d, 0x27a, 0xee5d, 0x26d, 0xee8d, 0x25f, 0xeebe, 
  0x251, 0xeeee, 0x244, 0xef1f, 0x237, 0xef4f, 0x22a, 0xef80, 
  0x21d, 0xefb0, 0x210, 0xefe1, 0x204, 0xf012, 0x1f7, 0xf042, 
  0x1eb, 0xf073, 0x1df, 0xf0a4, 0x1d3, 0xf0d5, 0x1c7, 0xf105, 
  0x1bb, 0xf136, 0x1b0, 0xf167, 0x1a4, 0xf198, 0x199, 0xf1c9, 
  0x18e, 0xf1fa, 0x183, 0xf22b, 0x178, 0xf25c, 0x16e, 0xf28e, 
  0x163, 0xf2bf, 0x159, 0xf2f0, 0x14f, 0xf321, 0x145, 0xf352, 
  0x13b, 0xf384, 0x131, 0xf3b5, 0x128, 0xf3e6, 0x11e, 0xf418, 
  0x115, 0xf449, 0x10c, 0xf47b, 0x103, 0xf4ac, 0xfa, 0xf4dd, 
  0xf1, 0xf50f, 0xe9, 0xf540, 0xe0, 0xf572, 0xd8, 0xf5a4, 
  0xd0, 0xf5d5, 0xc8, 0xf607, 0xc0, 0xf639, 0xb9, 0xf66a, 
  0xb1, 0xf69c, 0xaa, 0xf6ce, 0xa3, 0xf6ff, 0x9c, 0xf731, 
  0x95, 0xf763, 0x8e, 0xf795, 0x88, 0xf7c7, 0x81, 0xf7f9, 
  0x7b, 0xf82a, 0x75, 0xf85c, 0x6f, 0xf88e, 0x69, 0xf8c0, 
  0x64, 0xf8f2, 0x5e, 0xf924, 0x59, 0xf956, 0x54, 0xf988, 
  0x4f, 0xf9ba, 0x4a, 0xf9ec, 0x45, 0xfa1e, 0x41, 0xfa50, 
  0x3c, 0xfa82, 0x38, 0xfab4, 0x34, 0xfae6, 0x30, 0xfb19, 
  0x2c, 0xfb4b, 0x29, 0xfb7d, 0x25, 0xfbaf, 0x22, 0xfbe1, 
  0x1f, 0xfc13, 0x1c, 0xfc45, 0x19, 0xfc78, 0x16, 0xfcaa, 
  0x14, 0xfcdc, 0x11, 0xfd0e, 0xf, 0xfd40, 0xd, 0xfd73, 
  0xb, 0xfda5, 0x9, 0xfdd7, 0x8, 0xfe09, 0x6, 0xfe3c, 
  0x5, 0xfe6e, 0x4, 0xfea0, 0x3, 0xfed2, 0x2, 0xff05, 
  0x1, 0xff37, 0x1, 0xff69, 0x0, 0xff9b, 0x0, 0xffce, 
  0x0, 0x0, 0x0, 0x32, 0x0, 0x65, 0x1, 0x97, 
  0x1, 0xc9, 0x2, 0xfb, 0x3, 0x12e, 0x4, 0x160, 
  0x5, 0x192, 0x6, 0x1c4, 0x8, 0x1f7, 0x9, 0x229, 
  0xb, 0x25b, 0xd, 0x28d, 0xf, 0x2c0, 0x11, 0x2f2, 
  0x14, 0x324, 0x16, 0x356, 0x19, 0x388, 0x1c, 0x3bb, 
  0x1f, 0x3ed, 0x22, 0x41f, 0x25, 0x451, 0x29, 0x483, 
  0x2c, 0x4b5, 0x30, 0x4e7, 0x34, 0x51a, 0x38, 0x54c, 
  0x3c, 0x57e, 0x41, 0x5b0, 0x45, 0x5e2, 0x4a, 0x614, 
  0x4f, 0x646, 0x54, 0x678, 0x59, 0x6aa, 0x5e, 0x6dc, 
  0x64, 0x70e, 0x69, 0x740, 0x6f, 0x772, 0x75, 0x7a4, 
  0x7b, 0x7d6, 0x81, 0x807, 0x88, 0x839, 0x8e, 0x86b, 
  0x95, 0x89d, 0x9c, 0x8cf, 0xa3, 0x901, 0xaa, 0x932, 
  0xb1, 0x964, 0xb9, 0x996, 0xc0, 0x9c7, 0xc8, 0x9f9, 
  0xd0, 0xa2b, 0xd8, 0xa5c, 0xe0, 0xa8e, 0xe9, 0xac0, 
  0xf1, 0xaf1, 0xfa, 0xb23, 0x103, 0xb54, 0x10c, 0xb85, 
  0x115, 0xbb7, 0x11e, 0xbe8, 0x128, 0xc1a, 0x131, 0xc4b, 
  0x13b, 0xc7c, 0x145, 0xcae, 0x14f, 0xcdf, 0x159, 0xd10, 
  0x163, 0xd41, 0x16e, 0xd72, 0x178, 0xda4, 0x183, 0xdd5, 
  0x18e, 0xe06, 0x199, 0xe37, 0x1a4, 0xe68, 0x1b0, 0xe99, 
  0x1bb, 0xeca, 0x1c7, 0xefb, 0x1d3, 0xf2b, 0x1df, 0xf5c, 
  0x1eb, 0xf8d, 0x1f7, 0xfbe, 0x204, 0xfee, 0x210, 0x101f, 
  0x21d, 0x1050, 0x22a, 0x1080, 0x237, 0x10b1, 0x244, 0x10e1, 
  0x251, 0x1112, 0x25f, 0x1142, 0x26d, 0x1173, 0x27a, 0x11a3, 
  0x288, 0x11d3, 0x296, 0x1204, 0x2a5, 0x1234, 0x2b3, 0x1264, 
  0x2c1, 0x1294, 0x2d0, 0x12c4, 0x2df, 0x12f4, 0x2ee, 0x1324, 
  0x2fd, 0x1354, 0x30c, 0x1384, 0x31c, 0x13b4, 0x32b, 0x13e4, 
  0x33b, 0x1413, 0x34b, 0x1443, 0x35b, 0x1473, 0x36b, 0x14a2, 
  0x37b, 0x14d2, 0x38c, 0x1501, 0x39c, 0x1531, 0x3ad, 0x1560, 
  0x3be, 0x1590, 0x3cf, 0x15bf, 0x3e0, 0x15ee, 0x3f1, 0x161d, 
  0x403, 0x164c, 0x414, 0x167c, 0x426, 0x16ab, 0x438, 0x16da, 
  0x44a, 0x1709, 0x45c, 0x1737, 0x46e, 0x1766, 0x481, 0x1795, 
  0x493, 0x17c4, 0x4a6, 0x17f2, 0x4b9, 0x1821, 0x4cc, 0x184f, 
  0x4df, 0x187e, 0x4f2, 0x18ac, 0x506, 0x18db, 0x51a, 0x1909, 
  0x52d, 0x1937, 0x541, 0x1965, 0x555, 0x1993, 0x569, 0x19c1, 
  0x57e, 0x19ef, 0x592, 0x1a1d, 0x5a7, 0x1a4b, 0x5bb, 0x1a79, 
  0x5d0, 0x1aa7, 0x5e5, 0x1ad4, 0x5fa, 0x1b02, 0x610, 0x1b30, 
  0x625, 0x1b5d, 0x63b, 0x1b8a, 0x650, 0x1bb8, 0x666, 0x1be5, 
  0x67c, 0x1c12, 0x692, 0x1c3f, 0x6a8, 0x1c6c, 0x6bf, 0x1c99, 
  0x6d5, 0x1cc6, 0x6ec, 0x1cf3, 0x703, 0x1d20, 0x71a, 0x1d4d, 
  0x731, 0x1d79, 0x748, 0x1da6, 0x75f, 0x1dd3, 0x777, 0x1dff, 
  0x78f, 0x1e2b, 0x7a6, 0x1e58, 0x7be, 0x1e84, 0x7d6, 0x1eb0, 
  0x7ee, 0x1edc, 0x807, 0x1f08, 0x81f, 0x1f34, 0x838, 0x1f60, 
  0x850, 0x1f8c, 0x869, 0x1fb7, 0x882, 0x1fe3, 0x89b, 0x200f, 
  0x8b5, 0x203a, 0x8ce, 0x2065, 0x8e8, 0x2091, 0x901, 0x20bc, 
  0x91b, 0x20e7, 0x935, 0x2112, 0x94f, 0x213d, 0x969, 0x2168, 
  0x983, 0x2193, 0x99e, 0x21be, 0x9b8, 0x21e8, 0x9d3, 0x2213, 
  0x9ee, 0x223d, 0xa09, 0x2268, 0xa24, 0x2292, 0xa3f, 0x22bc, 
  0xa5b, 0x22e7, 0xa76, 0x2311, 0xa92, 0x233b, 0xaad, 0x2365, 
  0xac9, 0x238e, 0xae5, 0x23b8, 0xb01, 0x23e2, 0xb1e, 0x240b, 
  0xb3a, 0x2435, 0xb56, 0x245e, 0xb73, 0x2488, 0xb90, 0x24b1, 
  0xbad, 0x24da, 0xbca, 0x2503, 0xbe7, 0x252c, 0xc04, 0x2555, 
  0xc21, 0x257e, 0xc3f, 0x25a6, 0xc5d, 0x25cf, 0xc7a, 0x25f8, 
  0xc98, 0x2620, 0xcb6, 0x2648, 0xcd4, 0x2671, 0xcf3, 0x2699, 
  0xd11, 0x26c1, 0xd30, 0x26e9, 0xd4e, 0x2711, 0xd6d, 0x2738, 
  0xd8c, 0x2760, 0xdab, 0x2788, 0xdca, 0x27af, 0xde9, 0x27d6, 
  0xe08, 0x27fe, 0xe28, 0x2825, 0xe47, 0x284c, 0xe67, 0x2873, 
  0xe87, 0x289a, 0xea7, 0x28c1, 0xec7, 0x28e7, 0xee7, 0x290e, 
  0xf07, 0x2935, 0xf28, 0x295b, 0xf48, 0x2981, 0xf69, 0x29a7, 
  0xf8a, 0x29ce, 0xfab, 0x29f4, 0xfcc, 0x2a1a, 0xfed, 0x2a3f, 
  0x100e, 0x2a65, 0x1030, 0x2a8b, 0x1051, 0x2ab0, 0x1073, 0x2ad6, 
  0x1094, 0x2afb, 0x10b6, 0x2b20, 0x10d8, 0x2b45, 0x10fa, 0x2b6a, 
  0x111c, 0x2b8f, 0x113e, 0x2bb4, 0x1161, 0x2bd8, 0x1183, 0x2bfd, 
  0x11a6, 0x2c21, 0x11c9, 0x2c46, 0x11eb, 0x2c6a, 0x120e, 0x2c8e, 
  0x1231, 0x2cb2, 0x1255, 0x2cd6, 0x1278, 0x2cfa, 0x129b, 0x2d1e, 
  0x12bf, 0x2d41, 0x12e2, 0x2d65, 0x1306, 0x2d88, 0x132a, 0x2dab, 
  0x134e, 0x2dcf, 0x1372, 0x2df2, 0x1396, 0x2e15, 0x13ba, 0x2e37, 
  0x13df, 0x2e5a, 0x1403, 0x2e7d, 0x1428, 0x2e9f, 0x144c, 0x2ec2, 
  0x1471, 0x2ee4, 0x1496, 0x2f06, 0x14bb, 0x2f28, 0x14e0, 0x2f4a, 
  0x1505, 0x2f6c, 0x152a, 0x2f8d, 0x1550, 0x2faf, 0x1575, 0x2fd0, 
  0x159b, 0x2ff2, 0x15c1, 0x3013, 0x15e6, 0x3034, 0x160c, 0x3055, 
  0x1632, 0x3076, 0x1659, 0x3097, 0x167f, 0x30b8, 0x16a5, 0x30d8, 
  0x16cb, 0x30f9, 0x16f2, 0x3119, 0x1719, 0x3139, 0x173f, 0x3159, 
  0x1766, 0x3179, 0x178d, 0x3199, 0x17b4, 0x31b9, 0x17db, 0x31d8, 
  0x1802, 0x31f8, 0x182a, 0x3217, 0x1851, 0x3236, 0x1878, 0x3255, 
  0x18a0, 0x3274, 0x18c8, 0x3293, 0x18ef, 0x32b2, 0x1917, 0x32d0, 
  0x193f, 0x32ef, 0x1967, 0x330d, 0x198f, 0x332c, 0x19b8, 0x334a, 
  0x19e0, 0x3368, 0x1a08, 0x3386, 0x1a31, 0x33a3, 0x1a5a, 0x33c1, 
  0x1a82, 0x33df, 0x1aab, 0x33fc, 0x1ad4, 0x3419, 0x1afd, 0x3436, 
  0x1b26, 0x3453, 0x1b4f, 0x3470, 0x1b78, 0x348d, 0x1ba2, 0x34aa, 
  0x1bcb, 0x34c6, 0x1bf5, 0x34e2, 0x1c1e, 0x34ff, 0x1c48, 0x351b, 
  0x1c72, 0x3537, 0x1c9b, 0x3553, 0x1cc5, 0x356e, 0x1cef, 0x358a, 
  0x1d19, 0x35a5, 0x1d44, 0x35c1, 0x1d6e, 0x35dc, 0x1d98, 0x35f7, 
  0x1dc3, 0x3612, 0x1ded, 0x362d, 0x1e18, 0x3648, 0x1e42, 0x3662, 
  0x1e6d, 0x367d, 0x1e98, 0x3697, 0x1ec3, 0x36b1, 0x1eee, 0x36cb, 
  0x1f19, 0x36e5, 0x1f44, 0x36ff, 0x1f6f, 0x3718, 0x1f9b, 0x3732, 
  0x1fc6, 0x374b, 0x1ff1, 0x3765, 0x201d, 0x377e, 0x2049, 0x3797, 
  0x2074, 0x37b0, 0x20a0, 0x37c8, 0x20cc, 0x37e1, 0x20f8, 0x37f9, 
  0x2124, 0x3812, 0x2150, 0x382a, 0x217c, 0x3842, 0x21a8, 0x385a, 
  0x21d5, 0x3871, 0x2201, 0x3889, 0x222d, 0x38a1, 0x225a, 0x38b8, 
  0x2287, 0x38cf, 0x22b3, 0x38e6, 0x22e0, 0x38fd, 0x230d, 0x3914, 
  0x233a, 0x392b, 0x2367, 0x3941, 0x2394, 0x3958, 0x23c1, 0x396e, 
  0x23ee, 0x3984, 0x241b, 0x399a, 0x2448, 0x39b0, 0x2476, 0x39c5, 
  0x24a3, 0x39db, 0x24d0, 0x39f0, 0x24fe, 0x3a06, 0x252c, 0x3a1b, 
  0x2559, 0x3a30, 0x2587, 0x3a45, 0x25b5, 0x3a59, 0x25e3, 0x3a6e, 
  0x2611, 0x3a82, 0x263f, 0x3a97, 0x266d, 0x3aab, 0x269b, 0x3abf, 
  0x26c9, 0x3ad3, 0x26f7, 0x3ae6, 0x2725, 0x3afa, 0x2754, 0x3b0e, 
  0x2782, 0x3b21, 0x27b1, 0x3b34, 0x27df, 0x3b47, 0x280e, 0x3b5a, 
  0x283c, 0x3b6d, 0x286b, 0x3b7f, 0x289a, 0x3b92, 0x28c9, 0x3ba4, 
  0x28f7, 0x3bb6, 0x2926, 0x3bc8, 0x2955, 0x3bda, 0x2984, 0x3bec, 
  0x29b4, 0x3bfd, 0x29e3, 0x3c0f, 0x2a12, 0x3c20, 0x2a41, 0x3c31, 
  0x2a70, 0x3c42, 0x2aa0, 0x3c53, 0x2acf, 0x3c64, 0x2aff, 0x3c74, 
  0x2b2e, 0x3c85, 0x2b5e, 0x3c95, 0x2b8d, 0x3ca5, 0x2bbd, 0x3cb5, 
  0x2bed, 0x3cc5, 0x2c1c, 0x3cd5, 0x2c4c, 0x3ce4, 0x2c7c, 0x3cf4, 
  0x2cac, 0x3d03, 0x2cdc, 0x3d12, 0x2d0c, 0x3d21, 0x2d3c, 0x3d30, 
  0x2d6c, 0x3d3f, 0x2d9c, 0x3d4d, 0x2dcc, 0x3d5b, 0x2dfc, 0x3d6a, 
  0x2e2d, 0x3d78, 0x2e5d, 0x3d86, 0x2e8d, 0x3d93, 0x2ebe, 0x3da1, 
  0x2eee, 0x3daf, 0x2f1f, 0x3dbc, 0x2f4f, 0x3dc9, 0x2f80, 0x3dd6, 
  0x2fb0, 0x3de3, 0x2fe1, 0x3df0, 0x3012, 0x3dfc, 0x3042, 0x3e09, 
  0x3073, 0x3e15, 0x30a4, 0x3e21, 0x30d5, 0x3e2d, 0x3105, 0x3e39, 
  0x3136, 0x3e45, 0x3167, 0x3e50, 0x3198, 0x3e5c, 0x31c9, 0x3e67, 
  0x31fa, 0x3e72, 0x322b, 0x3e7d, 0x325c, 0x3e88, 0x328e, 0x3e92, 
  0x32bf, 0x3e9d, 0x32f0, 0x3ea7, 0x3321, 0x3eb1, 0x3352, 0x3ebb, 
  0x3384, 0x3ec5, 0x33b5, 0x3ecf, 0x33e6, 0x3ed8, 0x3418, 0x3ee2, 
  0x3449, 0x3eeb, 0x347b, 0x3ef4, 0x34ac, 0x3efd, 0x34dd, 0x3f06, 
  0x350f, 0x3f0f, 0x3540, 0x3f17, 0x3572, 0x3f20, 0x35a4, 0x3f28, 
  0x35d5, 0x3f30, 0x3607, 0x3f38, 0x3639, 0x3f40, 0x366a, 0x3f47, 
  0x369c, 0x3f4f, 0x36ce, 0x3f56, 0x36ff, 0x3f5d, 0x3731, 0x3f64, 
  0x3763, 0x3f6b, 0x3795, 0x3f72, 0x37c7, 0x3f78, 0x37f9, 0x3f7f, 
  0x382a, 0x3f85, 0x385c, 0x3f8b, 0x388e, 0x3f91, 0x38c0, 0x3f97, 
  0x38f2, 0x3f9c, 0x3924, 0x3fa2, 0x3956, 0x3fa7, 0x3988, 0x3fac, 
  0x39ba, 0x3fb1, 0x39ec, 0x3fb6, 0x3a1e, 0x3fbb, 0x3a50, 0x3fbf, 
  0x3a82, 0x3fc4, 0x3ab4, 0x3fc8, 0x3ae6, 0x3fcc, 0x3b19, 0x3fd0, 
  0x3b4b, 0x3fd4, 0x3b7d, 0x3fd7, 0x3baf, 0x3fdb, 0x3be1, 0x3fde, 
  0x3c13, 0x3fe1, 0x3c45, 0x3fe4, 0x3c78, 0x3fe7, 0x3caa, 0x3fea, 
  0x3cdc, 0x3fec, 0x3d0e, 0x3fef, 0x3d40, 0x3ff1, 0x3d73, 0x3ff3, 
  0x3da5, 0x3ff5, 0x3dd7, 0x3ff7, 0x3e09, 0x3ff8, 0x3e3c, 0x3ffa, 
  0x3e6e, 0x3ffb, 0x3ea0, 0x3ffc, 0x3ed2, 0x3ffd, 0x3f05, 0x3ffe, 
  0x3f37, 0x3fff, 0x3f69, 0x3fff, 0x3f9b, 0x4000, 0x3fce, 0x4000 
}; 
 
/**  
* \par 
* Generation of real_CoefB array:  
* \par  
* n = 1024  
* <pre>for (i = 0; i < n; i++)  
*  {  
*    pBTable[2 * i] = 0.5 * (1.0 + sin (2 * PI / (double) (2 * n) * (double) i));  
*    pBTable[2 * i + 1] = 0.5 * (1.0 * cos (2 * PI / (double) (2 * n) * (double) i));  
*  } </pre> 
* \par  
* Convert to fixed point Q15 format  
*       round(pBTable[i] * pow(2, 15))  
*  
*/ 
 
static const q15_t realCoefBQ15[2048] = { 
  0x4000, 0x4000, 0x4032, 0x4000, 0x4065, 0x4000, 0x4097, 0x3fff, 
  0x40c9, 0x3fff, 0x40fb, 0x3ffe, 0x412e, 0x3ffd, 0x4160, 0x3ffc, 
  0x4192, 0x3ffb, 0x41c4, 0x3ffa, 0x41f7, 0x3ff8, 0x4229, 0x3ff7, 
  0x425b, 0x3ff5, 0x428d, 0x3ff3, 0x42c0, 0x3ff1, 0x42f2, 0x3fef, 
  0x4324, 0x3fec, 0x4356, 0x3fea, 0x4388, 0x3fe7, 0x43bb, 0x3fe4, 
  0x43ed, 0x3fe1, 0x441f, 0x3fde, 0x4451, 0x3fdb, 0x4483, 0x3fd7, 
  0x44b5, 0x3fd4, 0x44e7, 0x3fd0, 0x451a, 0x3fcc, 0x454c, 0x3fc8, 
  0x457e, 0x3fc4, 0x45b0, 0x3fbf, 0x45e2, 0x3fbb, 0x4614, 0x3fb6, 
  0x4646, 0x3fb1, 0x4678, 0x3fac, 0x46aa, 0x3fa7, 0x46dc, 0x3fa2, 
  0x470e, 0x3f9c, 0x4740, 0x3f97, 0x4772, 0x3f91, 0x47a4, 0x3f8b, 
  0x47d6, 0x3f85, 0x4807, 0x3f7f, 0x4839, 0x3f78, 0x486b, 0x3f72, 
  0x489d, 0x3f6b, 0x48cf, 0x3f64, 0x4901, 0x3f5d, 0x4932, 0x3f56, 
  0x4964, 0x3f4f, 0x4996, 0x3f47, 0x49c7, 0x3f40, 0x49f9, 0x3f38, 
  0x4a2b, 0x3f30, 0x4a5c, 0x3f28, 0x4a8e, 0x3f20, 0x4ac0, 0x3f17, 
  0x4af1, 0x3f0f, 0x4b23, 0x3f06, 0x4b54, 0x3efd, 0x4b85, 0x3ef4, 
  0x4bb7, 0x3eeb, 0x4be8, 0x3ee2, 0x4c1a, 0x3ed8, 0x4c4b, 0x3ecf, 
  0x4c7c, 0x3ec5, 0x4cae, 0x3ebb, 0x4cdf, 0x3eb1, 0x4d10, 0x3ea7, 
  0x4d41, 0x3e9d, 0x4d72, 0x3e92, 0x4da4, 0x3e88, 0x4dd5, 0x3e7d, 
  0x4e06, 0x3e72, 0x4e37, 0x3e67, 0x4e68, 0x3e5c, 0x4e99, 0x3e50, 
  0x4eca, 0x3e45, 0x4efb, 0x3e39, 0x4f2b, 0x3e2d, 0x4f5c, 0x3e21, 
  0x4f8d, 0x3e15, 0x4fbe, 0x3e09, 0x4fee, 0x3dfc, 0x501f, 0x3df0, 
  0x5050, 0x3de3, 0x5080, 0x3dd6, 0x50b1, 0x3dc9, 0x50e1, 0x3dbc, 
  0x5112, 0x3daf, 0x5142, 0x3da1, 0x5173, 0x3d93, 0x51a3, 0x3d86, 
  0x51d3, 0x3d78, 0x5204, 0x3d6a, 0x5234, 0x3d5b, 0x5264, 0x3d4d, 
  0x5294, 0x3d3f, 0x52c4, 0x3d30, 0x52f4, 0x3d21, 0x5324, 0x3d12, 
  0x5354, 0x3d03, 0x5384, 0x3cf4, 0x53b4, 0x3ce4, 0x53e4, 0x3cd5, 
  0x5413, 0x3cc5, 0x5443, 0x3cb5, 0x5473, 0x3ca5, 0x54a2, 0x3c95, 
  0x54d2, 0x3c85, 0x5501, 0x3c74, 0x5531, 0x3c64, 0x5560, 0x3c53, 
  0x5590, 0x3c42, 0x55bf, 0x3c31, 0x55ee, 0x3c20, 0x561d, 0x3c0f, 
  0x564c, 0x3bfd, 0x567c, 0x3bec, 0x56ab, 0x3bda, 0x56da, 0x3bc8, 
  0x5709, 0x3bb6, 0x5737, 0x3ba4, 0x5766, 0x3b92, 0x5795, 0x3b7f, 
  0x57c4, 0x3b6d, 0x57f2, 0x3b5a, 0x5821, 0x3b47, 0x584f, 0x3b34, 
  0x587e, 0x3b21, 0x58ac, 0x3b0e, 0x58db, 0x3afa, 0x5909, 0x3ae6, 
  0x5937, 0x3ad3, 0x5965, 0x3abf, 0x5993, 0x3aab, 0x59c1, 0x3a97, 
  0x59ef, 0x3a82, 0x5a1d, 0x3a6e, 0x5a4b, 0x3a59, 0x5a79, 0x3a45, 
  0x5aa7, 0x3a30, 0x5ad4, 0x3a1b, 0x5b02, 0x3a06, 0x5b30, 0x39f0, 
  0x5b5d, 0x39db, 0x5b8a, 0x39c5, 0x5bb8, 0x39b0, 0x5be5, 0x399a, 
  0x5c12, 0x3984, 0x5c3f, 0x396e, 0x5c6c, 0x3958, 0x5c99, 0x3941, 
  0x5cc6, 0x392b, 0x5cf3, 0x3914, 0x5d20, 0x38fd, 0x5d4d, 0x38e6, 
  0x5d79, 0x38cf, 0x5da6, 0x38b8, 0x5dd3, 0x38a1, 0x5dff, 0x3889, 
  0x5e2b, 0x3871, 0x5e58, 0x385a, 0x5e84, 0x3842, 0x5eb0, 0x382a, 
  0x5edc, 0x3812, 0x5f08, 0x37f9, 0x5f34, 0x37e1, 0x5f60, 0x37c8, 
  0x5f8c, 0x37b0, 0x5fb7, 0x3797, 0x5fe3, 0x377e, 0x600f, 0x3765, 
  0x603a, 0x374b, 0x6065, 0x3732, 0x6091, 0x3718, 0x60bc, 0x36ff, 
  0x60e7, 0x36e5, 0x6112, 0x36cb, 0x613d, 0x36b1, 0x6168, 0x3697, 
  0x6193, 0x367d, 0x61be, 0x3662, 0x61e8, 0x3648, 0x6213, 0x362d, 
  0x623d, 0x3612, 0x6268, 0x35f7, 0x6292, 0x35dc, 0x62bc, 0x35c1, 
  0x62e7, 0x35a5, 0x6311, 0x358a, 0x633b, 0x356e, 0x6365, 0x3553, 
  0x638e, 0x3537, 0x63b8, 0x351b, 0x63e2, 0x34ff, 0x640b, 0x34e2, 
  0x6435, 0x34c6, 0x645e, 0x34aa, 0x6488, 0x348d, 0x64b1, 0x3470, 
  0x64da, 0x3453, 0x6503, 0x3436, 0x652c, 0x3419, 0x6555, 0x33fc, 
  0x657e, 0x33df, 0x65a6, 0x33c1, 0x65cf, 0x33a3, 0x65f8, 0x3386, 
  0x6620, 0x3368, 0x6648, 0x334a, 0x6671, 0x332c, 0x6699, 0x330d, 
  0x66c1, 0x32ef, 0x66e9, 0x32d0, 0x6711, 0x32b2, 0x6738, 0x3293, 
  0x6760, 0x3274, 0x6788, 0x3255, 0x67af, 0x3236, 0x67d6, 0x3217, 
  0x67fe, 0x31f8, 0x6825, 0x31d8, 0x684c, 0x31b9, 0x6873, 0x3199, 
  0x689a, 0x3179, 0x68c1, 0x3159, 0x68e7, 0x3139, 0x690e, 0x3119, 
  0x6935, 0x30f9, 0x695b, 0x30d8, 0x6981, 0x30b8, 0x69a7, 0x3097, 
  0x69ce, 0x3076, 0x69f4, 0x3055, 0x6a1a, 0x3034, 0x6a3f, 0x3013, 
  0x6a65, 0x2ff2, 0x6a8b, 0x2fd0, 0x6ab0, 0x2faf, 0x6ad6, 0x2f8d, 
  0x6afb, 0x2f6c, 0x6b20, 0x2f4a, 0x6b45, 0x2f28, 0x6b6a, 0x2f06, 
  0x6b8f, 0x2ee4, 0x6bb4, 0x2ec2, 0x6bd8, 0x2e9f, 0x6bfd, 0x2e7d, 
  0x6c21, 0x2e5a, 0x6c46, 0x2e37, 0x6c6a, 0x2e15, 0x6c8e, 0x2df2, 
  0x6cb2, 0x2dcf, 0x6cd6, 0x2dab, 0x6cfa, 0x2d88, 0x6d1e, 0x2d65, 
  0x6d41, 0x2d41, 0x6d65, 0x2d1e, 0x6d88, 0x2cfa, 0x6dab, 0x2cd6, 
  0x6dcf, 0x2cb2, 0x6df2, 0x2c8e, 0x6e15, 0x2c6a, 0x6e37, 0x2c46, 
  0x6e5a, 0x2c21, 0x6e7d, 0x2bfd, 0x6e9f, 0x2bd8, 0x6ec2, 0x2bb4, 
  0x6ee4, 0x2b8f, 0x6f06, 0x2b6a, 0x6f28, 0x2b45, 0x6f4a, 0x2b20, 
  0x6f6c, 0x2afb, 0x6f8d, 0x2ad6, 0x6faf, 0x2ab0, 0x6fd0, 0x2a8b, 
  0x6ff2, 0x2a65, 0x7013, 0x2a3f, 0x7034, 0x2a1a, 0x7055, 0x29f4, 
  0x7076, 0x29ce, 0x7097, 0x29a7, 0x70b8, 0x2981, 0x70d8, 0x295b, 
  0x70f9, 0x2935, 0x7119, 0x290e, 0x7139, 0x28e7, 0x7159, 0x28c1, 
  0x7179, 0x289a, 0x7199, 0x2873, 0x71b9, 0x284c, 0x71d8, 0x2825, 
  0x71f8, 0x27fe, 0x7217, 0x27d6, 0x7236, 0x27af, 0x7255, 0x2788, 
  0x7274, 0x2760, 0x7293, 0x2738, 0x72b2, 0x2711, 0x72d0, 0x26e9, 
  0x72ef, 0x26c1, 0x730d, 0x2699, 0x732c, 0x2671, 0x734a, 0x2648, 
  0x7368, 0x2620, 0x7386, 0x25f8, 0x73a3, 0x25cf, 0x73c1, 0x25a6, 
  0x73df, 0x257e, 0x73fc, 0x2555, 0x7419, 0x252c, 0x7436, 0x2503, 
  0x7453, 0x24da, 0x7470, 0x24b1, 0x748d, 0x2488, 0x74aa, 0x245e, 
  0x74c6, 0x2435, 0x74e2, 0x240b, 0x74ff, 0x23e2, 0x751b, 0x23b8, 
  0x7537, 0x238e, 0x7553, 0x2365, 0x756e, 0x233b, 0x758a, 0x2311, 
  0x75a5, 0x22e7, 0x75c1, 0x22bc, 0x75dc, 0x2292, 0x75f7, 0x2268, 
  0x7612, 0x223d, 0x762d, 0x2213, 0x7648, 0x21e8, 0x7662, 0x21be, 
  0x767d, 0x2193, 0x7697, 0x2168, 0x76b1, 0x213d, 0x76cb, 0x2112, 
  0x76e5, 0x20e7, 0x76ff, 0x20bc, 0x7718, 0x2091, 0x7732, 0x2065, 
  0x774b, 0x203a, 0x7765, 0x200f, 0x777e, 0x1fe3, 0x7797, 0x1fb7, 
  0x77b0, 0x1f8c, 0x77c8, 0x1f60, 0x77e1, 0x1f34, 0x77f9, 0x1f08, 
  0x7812, 0x1edc, 0x782a, 0x1eb0, 0x7842, 0x1e84, 0x785a, 0x1e58, 
  0x7871, 0x1e2b, 0x7889, 0x1dff, 0x78a1, 0x1dd3, 0x78b8, 0x1da6, 
  0x78cf, 0x1d79, 0x78e6, 0x1d4d, 0x78fd, 0x1d20, 0x7914, 0x1cf3, 
  0x792b, 0x1cc6, 0x7941, 0x1c99, 0x7958, 0x1c6c, 0x796e, 0x1c3f, 
  0x7984, 0x1c12, 0x799a, 0x1be5, 0x79b0, 0x1bb8, 0x79c5, 0x1b8a, 
  0x79db, 0x1b5d, 0x79f0, 0x1b30, 0x7a06, 0x1b02, 0x7a1b, 0x1ad4, 
  0x7a30, 0x1aa7, 0x7a45, 0x1a79, 0x7a59, 0x1a4b, 0x7a6e, 0x1a1d, 
  0x7a82, 0x19ef, 0x7a97, 0x19c1, 0x7aab, 0x1993, 0x7abf, 0x1965, 
  0x7ad3, 0x1937, 0x7ae6, 0x1909, 0x7afa, 0x18db, 0x7b0e, 0x18ac, 
  0x7b21, 0x187e, 0x7b34, 0x184f, 0x7b47, 0x1821, 0x7b5a, 0x17f2, 
  0x7b6d, 0x17c4, 0x7b7f, 0x1795, 0x7b92, 0x1766, 0x7ba4, 0x1737, 
  0x7bb6, 0x1709, 0x7bc8, 0x16da, 0x7bda, 0x16ab, 0x7bec, 0x167c, 
  0x7bfd, 0x164c, 0x7c0f, 0x161d, 0x7c20, 0x15ee, 0x7c31, 0x15bf, 
  0x7c42, 0x1590, 0x7c53, 0x1560, 0x7c64, 0x1531, 0x7c74, 0x1501, 
  0x7c85, 0x14d2, 0x7c95, 0x14a2, 0x7ca5, 0x1473, 0x7cb5, 0x1443, 
  0x7cc5, 0x1413, 0x7cd5, 0x13e4, 0x7ce4, 0x13b4, 0x7cf4, 0x1384, 
  0x7d03, 0x1354, 0x7d12, 0x1324, 0x7d21, 0x12f4, 0x7d30, 0x12c4, 
  0x7d3f, 0x1294, 0x7d4d, 0x1264, 0x7d5b, 0x1234, 0x7d6a, 0x1204, 
  0x7d78, 0x11d3, 0x7d86, 0x11a3, 0x7d93, 0x1173, 0x7da1, 0x1142, 
  0x7daf, 0x1112, 0x7dbc, 0x10e1, 0x7dc9, 0x10b1, 0x7dd6, 0x1080, 
  0x7de3, 0x1050, 0x7df0, 0x101f, 0x7dfc, 0xfee, 0x7e09, 0xfbe, 
  0x7e15, 0xf8d, 0x7e21, 0xf5c, 0x7e2d, 0xf2b, 0x7e39, 0xefb, 
  0x7e45, 0xeca, 0x7e50, 0xe99, 0x7e5c, 0xe68, 0x7e67, 0xe37, 
  0x7e72, 0xe06, 0x7e7d, 0xdd5, 0x7e88, 0xda4, 0x7e92, 0xd72, 
  0x7e9d, 0xd41, 0x7ea7, 0xd10, 0x7eb1, 0xcdf, 0x7ebb, 0xcae, 
  0x7ec5, 0xc7c, 0x7ecf, 0xc4b, 0x7ed8, 0xc1a, 0x7ee2, 0xbe8, 
  0x7eeb, 0xbb7, 0x7ef4, 0xb85, 0x7efd, 0xb54, 0x7f06, 0xb23, 
  0x7f0f, 0xaf1, 0x7f17, 0xac0, 0x7f20, 0xa8e, 0x7f28, 0xa5c, 
  0x7f30, 0xa2b, 0x7f38, 0x9f9, 0x7f40, 0x9c7, 0x7f47, 0x996, 
  0x7f4f, 0x964, 0x7f56, 0x932, 0x7f5d, 0x901, 0x7f64, 0x8cf, 
  0x7f6b, 0x89d, 0x7f72, 0x86b, 0x7f78, 0x839, 0x7f7f, 0x807, 
  0x7f85, 0x7d6, 0x7f8b, 0x7a4, 0x7f91, 0x772, 0x7f97, 0x740, 
  0x7f9c, 0x70e, 0x7fa2, 0x6dc, 0x7fa7, 0x6aa, 0x7fac, 0x678, 
  0x7fb1, 0x646, 0x7fb6, 0x614, 0x7fbb, 0x5e2, 0x7fbf, 0x5b0, 
  0x7fc4, 0x57e, 0x7fc8, 0x54c, 0x7fcc, 0x51a, 0x7fd0, 0x4e7, 
  0x7fd4, 0x4b5, 0x7fd7, 0x483, 0x7fdb, 0x451, 0x7fde, 0x41f, 
  0x7fe1, 0x3ed, 0x7fe4, 0x3bb, 0x7fe7, 0x388, 0x7fea, 0x356, 
  0x7fec, 0x324, 0x7fef, 0x2f2, 0x7ff1, 0x2c0, 0x7ff3, 0x28d, 
  0x7ff5, 0x25b, 0x7ff7, 0x229, 0x7ff8, 0x1f7, 0x7ffa, 0x1c4, 
  0x7ffb, 0x192, 0x7ffc, 0x160, 0x7ffd, 0x12e, 0x7ffe, 0xfb, 
  0x7fff, 0xc9, 0x7fff, 0x97, 0x7fff, 0x65, 0x7fff, 0x32, 
  0x7fff, 0x0, 0x7fff, 0xffce, 0x7fff, 0xff9b, 0x7fff, 0xff69, 
  0x7fff, 0xff37, 0x7ffe, 0xff05, 0x7ffd, 0xfed2, 0x7ffc, 0xfea0, 
  0x7ffb, 0xfe6e, 0x7ffa, 0xfe3c, 0x7ff8, 0xfe09, 0x7ff7, 0xfdd7, 
  0x7ff5, 0xfda5, 0x7ff3, 0xfd73, 0x7ff1, 0xfd40, 0x7fef, 0xfd0e, 
  0x7fec, 0xfcdc, 0x7fea, 0xfcaa, 0x7fe7, 0xfc78, 0x7fe4, 0xfc45, 
  0x7fe1, 0xfc13, 0x7fde, 0xfbe1, 0x7fdb, 0xfbaf, 0x7fd7, 0xfb7d, 
  0x7fd4, 0xfb4b, 0x7fd0, 0xfb19, 0x7fcc, 0xfae6, 0x7fc8, 0xfab4, 
  0x7fc4, 0xfa82, 0x7fbf, 0xfa50, 0x7fbb, 0xfa1e, 0x7fb6, 0xf9ec, 
  0x7fb1, 0xf9ba, 0x7fac, 0xf988, 0x7fa7, 0xf956, 0x7fa2, 0xf924, 
  0x7f9c, 0xf8f2, 0x7f97, 0xf8c0, 0x7f91, 0xf88e, 0x7f8b, 0xf85c, 
  0x7f85, 0xf82a, 0x7f7f, 0xf7f9, 0x7f78, 0xf7c7, 0x7f72, 0xf795, 
  0x7f6b, 0xf763, 0x7f64, 0xf731, 0x7f5d, 0xf6ff, 0x7f56, 0xf6ce, 
  0x7f4f, 0xf69c, 0x7f47, 0xf66a, 0x7f40, 0xf639, 0x7f38, 0xf607, 
  0x7f30, 0xf5d5, 0x7f28, 0xf5a4, 0x7f20, 0xf572, 0x7f17, 0xf540, 
  0x7f0f, 0xf50f, 0x7f06, 0xf4dd, 0x7efd, 0xf4ac, 0x7ef4, 0xf47b, 
  0x7eeb, 0xf449, 0x7ee2, 0xf418, 0x7ed8, 0xf3e6, 0x7ecf, 0xf3b5, 
  0x7ec5, 0xf384, 0x7ebb, 0xf352, 0x7eb1, 0xf321, 0x7ea7, 0xf2f0, 
  0x7e9d, 0xf2bf, 0x7e92, 0xf28e, 0x7e88, 0xf25c, 0x7e7d, 0xf22b, 
  0x7e72, 0xf1fa, 0x7e67, 0xf1c9, 0x7e5c, 0xf198, 0x7e50, 0xf167, 
  0x7e45, 0xf136, 0x7e39, 0xf105, 0x7e2d, 0xf0d5, 0x7e21, 0xf0a4, 
  0x7e15, 0xf073, 0x7e09, 0xf042, 0x7dfc, 0xf012, 0x7df0, 0xefe1, 
  0x7de3, 0xefb0, 0x7dd6, 0xef80, 0x7dc9, 0xef4f, 0x7dbc, 0xef1f, 
  0x7daf, 0xeeee, 0x7da1, 0xeebe, 0x7d93, 0xee8d, 0x7d86, 0xee5d, 
  0x7d78, 0xee2d, 0x7d6a, 0xedfc, 0x7d5b, 0xedcc, 0x7d4d, 0xed9c, 
  0x7d3f, 0xed6c, 0x7d30, 0xed3c, 0x7d21, 0xed0c, 0x7d12, 0xecdc, 
  0x7d03, 0xecac, 0x7cf4, 0xec7c, 0x7ce4, 0xec4c, 0x7cd5, 0xec1c, 
  0x7cc5, 0xebed, 0x7cb5, 0xebbd, 0x7ca5, 0xeb8d, 0x7c95, 0xeb5e, 
  0x7c85, 0xeb2e, 0x7c74, 0xeaff, 0x7c64, 0xeacf, 0x7c53, 0xeaa0, 
  0x7c42, 0xea70, 0x7c31, 0xea41, 0x7c20, 0xea12, 0x7c0f, 0xe9e3, 
  0x7bfd, 0xe9b4, 0x7bec, 0xe984, 0x7bda, 0xe955, 0x7bc8, 0xe926, 
  0x7bb6, 0xe8f7, 0x7ba4, 0xe8c9, 0x7b92, 0xe89a, 0x7b7f, 0xe86b, 
  0x7b6d, 0xe83c, 0x7b5a, 0xe80e, 0x7b47, 0xe7df, 0x7b34, 0xe7b1, 
  0x7b21, 0xe782, 0x7b0e, 0xe754, 0x7afa, 0xe725, 0x7ae6, 0xe6f7, 
  0x7ad3, 0xe6c9, 0x7abf, 0xe69b, 0x7aab, 0xe66d, 0x7a97, 0xe63f, 
  0x7a82, 0xe611, 0x7a6e, 0xe5e3, 0x7a59, 0xe5b5, 0x7a45, 0xe587, 
  0x7a30, 0xe559, 0x7a1b, 0xe52c, 0x7a06, 0xe4fe, 0x79f0, 0xe4d0, 
  0x79db, 0xe4a3, 0x79c5, 0xe476, 0x79b0, 0xe448, 0x799a, 0xe41b, 
  0x7984, 0xe3ee, 0x796e, 0xe3c1, 0x7958, 0xe394, 0x7941, 0xe367, 
  0x792b, 0xe33a, 0x7914, 0xe30d, 0x78fd, 0xe2e0, 0x78e6, 0xe2b3, 
  0x78cf, 0xe287, 0x78b8, 0xe25a, 0x78a1, 0xe22d, 0x7889, 0xe201, 
  0x7871, 0xe1d5, 0x785a, 0xe1a8, 0x7842, 0xe17c, 0x782a, 0xe150, 
  0x7812, 0xe124, 0x77f9, 0xe0f8, 0x77e1, 0xe0cc, 0x77c8, 0xe0a0, 
  0x77b0, 0xe074, 0x7797, 0xe049, 0x777e, 0xe01d, 0x7765, 0xdff1, 
  0x774b, 0xdfc6, 0x7732, 0xdf9b, 0x7718, 0xdf6f, 0x76ff, 0xdf44, 
  0x76e5, 0xdf19, 0x76cb, 0xdeee, 0x76b1, 0xdec3, 0x7697, 0xde98, 
  0x767d, 0xde6d, 0x7662, 0xde42, 0x7648, 0xde18, 0x762d, 0xdded, 
  0x7612, 0xddc3, 0x75f7, 0xdd98, 0x75dc, 0xdd6e, 0x75c1, 0xdd44, 
  0x75a5, 0xdd19, 0x758a, 0xdcef, 0x756e, 0xdcc5, 0x7553, 0xdc9b, 
  0x7537, 0xdc72, 0x751b, 0xdc48, 0x74ff, 0xdc1e, 0x74e2, 0xdbf5, 
  0x74c6, 0xdbcb, 0x74aa, 0xdba2, 0x748d, 0xdb78, 0x7470, 0xdb4f, 
  0x7453, 0xdb26, 0x7436, 0xdafd, 0x7419, 0xdad4, 0x73fc, 0xdaab, 
  0x73df, 0xda82, 0x73c1, 0xda5a, 0x73a3, 0xda31, 0x7386, 0xda08, 
  0x7368, 0xd9e0, 0x734a, 0xd9b8, 0x732c, 0xd98f, 0x730d, 0xd967, 
  0x72ef, 0xd93f, 0x72d0, 0xd917, 0x72b2, 0xd8ef, 0x7293, 0xd8c8, 
  0x7274, 0xd8a0, 0x7255, 0xd878, 0x7236, 0xd851, 0x7217, 0xd82a, 
  0x71f8, 0xd802, 0x71d8, 0xd7db, 0x71b9, 0xd7b4, 0x7199, 0xd78d, 
  0x7179, 0xd766, 0x7159, 0xd73f, 0x7139, 0xd719, 0x7119, 0xd6f2, 
  0x70f9, 0xd6cb, 0x70d8, 0xd6a5, 0x70b8, 0xd67f, 0x7097, 0xd659, 
  0x7076, 0xd632, 0x7055, 0xd60c, 0x7034, 0xd5e6, 0x7013, 0xd5c1, 
  0x6ff2, 0xd59b, 0x6fd0, 0xd575, 0x6faf, 0xd550, 0x6f8d, 0xd52a, 
  0x6f6c, 0xd505, 0x6f4a, 0xd4e0, 0x6f28, 0xd4bb, 0x6f06, 0xd496, 
  0x6ee4, 0xd471, 0x6ec2, 0xd44c, 0x6e9f, 0xd428, 0x6e7d, 0xd403, 
  0x6e5a, 0xd3df, 0x6e37, 0xd3ba, 0x6e15, 0xd396, 0x6df2, 0xd372, 
  0x6dcf, 0xd34e, 0x6dab, 0xd32a, 0x6d88, 0xd306, 0x6d65, 0xd2e2, 
  0x6d41, 0xd2bf, 0x6d1e, 0xd29b, 0x6cfa, 0xd278, 0x6cd6, 0xd255, 
  0x6cb2, 0xd231, 0x6c8e, 0xd20e, 0x6c6a, 0xd1eb, 0x6c46, 0xd1c9, 
  0x6c21, 0xd1a6, 0x6bfd, 0xd183, 0x6bd8, 0xd161, 0x6bb4, 0xd13e, 
  0x6b8f, 0xd11c, 0x6b6a, 0xd0fa, 0x6b45, 0xd0d8, 0x6b20, 0xd0b6, 
  0x6afb, 0xd094, 0x6ad6, 0xd073, 0x6ab0, 0xd051, 0x6a8b, 0xd030, 
  0x6a65, 0xd00e, 0x6a3f, 0xcfed, 0x6a1a, 0xcfcc, 0x69f4, 0xcfab, 
  0x69ce, 0xcf8a, 0x69a7, 0xcf69, 0x6981, 0xcf48, 0x695b, 0xcf28, 
  0x6935, 0xcf07, 0x690e, 0xcee7, 0x68e7, 0xcec7, 0x68c1, 0xcea7, 
  0x689a, 0xce87, 0x6873, 0xce67, 0x684c, 0xce47, 0x6825, 0xce28, 
  0x67fe, 0xce08, 0x67d6, 0xcde9, 0x67af, 0xcdca, 0x6788, 0xcdab, 
  0x6760, 0xcd8c, 0x6738, 0xcd6d, 0x6711, 0xcd4e, 0x66e9, 0xcd30, 
  0x66c1, 0xcd11, 0x6699, 0xccf3, 0x6671, 0xccd4, 0x6648, 0xccb6, 
  0x6620, 0xcc98, 0x65f8, 0xcc7a, 0x65cf, 0xcc5d, 0x65a6, 0xcc3f, 
  0x657e, 0xcc21, 0x6555, 0xcc04, 0x652c, 0xcbe7, 0x6503, 0xcbca, 
  0x64da, 0xcbad, 0x64b1, 0xcb90, 0x6488, 0xcb73, 0x645e, 0xcb56, 
  0x6435, 0xcb3a, 0x640b, 0xcb1e, 0x63e2, 0xcb01, 0x63b8, 0xcae5, 
  0x638e, 0xcac9, 0x6365, 0xcaad, 0x633b, 0xca92, 0x6311, 0xca76, 
  0x62e7, 0xca5b, 0x62bc, 0xca3f, 0x6292, 0xca24, 0x6268, 0xca09, 
  0x623d, 0xc9ee, 0x6213, 0xc9d3, 0x61e8, 0xc9b8, 0x61be, 0xc99e, 
  0x6193, 0xc983, 0x6168, 0xc969, 0x613d, 0xc94f, 0x6112, 0xc935, 
  0x60e7, 0xc91b, 0x60bc, 0xc901, 0x6091, 0xc8e8, 0x6065, 0xc8ce, 
  0x603a, 0xc8b5, 0x600f, 0xc89b, 0x5fe3, 0xc882, 0x5fb7, 0xc869, 
  0x5f8c, 0xc850, 0x5f60, 0xc838, 0x5f34, 0xc81f, 0x5f08, 0xc807, 
  0x5edc, 0xc7ee, 0x5eb0, 0xc7d6, 0x5e84, 0xc7be, 0x5e58, 0xc7a6, 
  0x5e2b, 0xc78f, 0x5dff, 0xc777, 0x5dd3, 0xc75f, 0x5da6, 0xc748, 
  0x5d79, 0xc731, 0x5d4d, 0xc71a, 0x5d20, 0xc703, 0x5cf3, 0xc6ec, 
  0x5cc6, 0xc6d5, 0x5c99, 0xc6bf, 0x5c6c, 0xc6a8, 0x5c3f, 0xc692, 
  0x5c12, 0xc67c, 0x5be5, 0xc666, 0x5bb8, 0xc650, 0x5b8a, 0xc63b, 
  0x5b5d, 0xc625, 0x5b30, 0xc610, 0x5b02, 0xc5fa, 0x5ad4, 0xc5e5, 
  0x5aa7, 0xc5d0, 0x5a79, 0xc5bb, 0x5a4b, 0xc5a7, 0x5a1d, 0xc592, 
  0x59ef, 0xc57e, 0x59c1, 0xc569, 0x5993, 0xc555, 0x5965, 0xc541, 
  0x5937, 0xc52d, 0x5909, 0xc51a, 0x58db, 0xc506, 0x58ac, 0xc4f2, 
  0x587e, 0xc4df, 0x584f, 0xc4cc, 0x5821, 0xc4b9, 0x57f2, 0xc4a6, 
  0x57c4, 0xc493, 0x5795, 0xc481, 0x5766, 0xc46e, 0x5737, 0xc45c, 
  0x5709, 0xc44a, 0x56da, 0xc438, 0x56ab, 0xc426, 0x567c, 0xc414, 
  0x564c, 0xc403, 0x561d, 0xc3f1, 0x55ee, 0xc3e0, 0x55bf, 0xc3cf, 
  0x5590, 0xc3be, 0x5560, 0xc3ad, 0x5531, 0xc39c, 0x5501, 0xc38c, 
  0x54d2, 0xc37b, 0x54a2, 0xc36b, 0x5473, 0xc35b, 0x5443, 0xc34b, 
  0x5413, 0xc33b, 0x53e4, 0xc32b, 0x53b4, 0xc31c, 0x5384, 0xc30c, 
  0x5354, 0xc2fd, 0x5324, 0xc2ee, 0x52f4, 0xc2df, 0x52c4, 0xc2d0, 
  0x5294, 0xc2c1, 0x5264, 0xc2b3, 0x5234, 0xc2a5, 0x5204, 0xc296, 
  0x51d3, 0xc288, 0x51a3, 0xc27a, 0x5173, 0xc26d, 0x5142, 0xc25f, 
  0x5112, 0xc251, 0x50e1, 0xc244, 0x50b1, 0xc237, 0x5080, 0xc22a, 
  0x5050, 0xc21d, 0x501f, 0xc210, 0x4fee, 0xc204, 0x4fbe, 0xc1f7, 
  0x4f8d, 0xc1eb, 0x4f5c, 0xc1df, 0x4f2b, 0xc1d3, 0x4efb, 0xc1c7, 
  0x4eca, 0xc1bb, 0x4e99, 0xc1b0, 0x4e68, 0xc1a4, 0x4e37, 0xc199, 
  0x4e06, 0xc18e, 0x4dd5, 0xc183, 0x4da4, 0xc178, 0x4d72, 0xc16e, 
  0x4d41, 0xc163, 0x4d10, 0xc159, 0x4cdf, 0xc14f, 0x4cae, 0xc145, 
  0x4c7c, 0xc13b, 0x4c4b, 0xc131, 0x4c1a, 0xc128, 0x4be8, 0xc11e, 
  0x4bb7, 0xc115, 0x4b85, 0xc10c, 0x4b54, 0xc103, 0x4b23, 0xc0fa, 
  0x4af1, 0xc0f1, 0x4ac0, 0xc0e9, 0x4a8e, 0xc0e0, 0x4a5c, 0xc0d8, 
  0x4a2b, 0xc0d0, 0x49f9, 0xc0c8, 0x49c7, 0xc0c0, 0x4996, 0xc0b9, 
  0x4964, 0xc0b1, 0x4932, 0xc0aa, 0x4901, 0xc0a3, 0x48cf, 0xc09c, 
  0x489d, 0xc095, 0x486b, 0xc08e, 0x4839, 0xc088, 0x4807, 0xc081, 
  0x47d6, 0xc07b, 0x47a4, 0xc075, 0x4772, 0xc06f, 0x4740, 0xc069, 
  0x470e, 0xc064, 0x46dc, 0xc05e, 0x46aa, 0xc059, 0x4678, 0xc054, 
  0x4646, 0xc04f, 0x4614, 0xc04a, 0x45e2, 0xc045, 0x45b0, 0xc041, 
  0x457e, 0xc03c, 0x454c, 0xc038, 0x451a, 0xc034, 0x44e7, 0xc030, 
  0x44b5, 0xc02c, 0x4483, 0xc029, 0x4451, 0xc025, 0x441f, 0xc022, 
  0x43ed, 0xc01f, 0x43bb, 0xc01c, 0x4388, 0xc019, 0x4356, 0xc016, 
  0x4324, 0xc014, 0x42f2, 0xc011, 0x42c0, 0xc00f, 0x428d, 0xc00d, 
  0x425b, 0xc00b, 0x4229, 0xc009, 0x41f7, 0xc008, 0x41c4, 0xc006, 
  0x4192, 0xc005, 0x4160, 0xc004, 0x412e, 0xc003, 0x40fb, 0xc002, 
  0x40c9, 0xc001, 0x4097, 0xc001, 0x4065, 0xc000, 0x4032, 0xc000 
}; 
 
/**  
* @brief  Initialization function for the Q15 RFFT/RIFFT. 
* @param[in, out] *S             points to an instance of the Q15 RFFT/RIFFT structure. 
* @param[in]      *S_CFFT        points to an instance of the Q15 CFFT/CIFFT structure. 
* @param[in]      fftLenReal     length of the FFT. 
* @param[in]      ifftFlagR      flag that selects forward (ifftFlagR=0) or inverse (ifftFlagR=1) transform. 
* @param[in]      bitReverseFlag flag that enables (bitReverseFlag=1) or disables (bitReverseFlag=0) bit reversal of output. 
* @return		The function returns ARM_MATH_SUCCESS if initialization is successful or ARM_MATH_ARGUMENT_ERROR if <code>fftLenReal</code> is not a supported value. 
*  
* \par Description: 
* \par 
* The parameter <code>fftLenReal</code>	Specifies length of RFFT/RIFFT Process. Supported FFT Lengths are 128, 512, 2048.  
* \par  
* The parameter <code>ifftFlagR</code> controls whether a forward or inverse transform is computed.  
* Set(=1) ifftFlagR to calculate RIFFT, otherwise RFFT is calculated.  
* \par  
* The parameter <code>bitReverseFlag</code> controls whether output is in normal order or bit reversed order.  
* Set(=1) bitReverseFlag for output to be in normal order otherwise output is in bit reversed order. 
* \par  
* This function also initializes Twiddle factor table.   
*/ 
 
arm_status arm_rfft_init_q15( 
  arm_rfft_instance_q15 * S, 
  arm_cfft_radix4_instance_q15 * S_CFFT, 
  uint32_t fftLenReal, 
  uint32_t ifftFlagR, 
  uint32_t bitReverseFlag) 
{ 
 
  /*  Initialise the default arm status */ 
  arm_status status = ARM_MATH_SUCCESS; 
 
  /*  Initialize the Real FFT length */ 
  S->fftLenReal = (uint16_t) fftLenReal; 
 
  /*  Initialize the Complex FFT length */ 
  S->fftLenBy2 = (uint16_t) fftLenReal / 2u; 
 
  /*  Initialize the Twiddle coefficientA pointer */ 
  S->pTwiddleAReal = (q15_t *) realCoefAQ15; 
 
  /*  Initialize the Twiddle coefficientB pointer */ 
  S->pTwiddleBReal = (q15_t *) realCoefBQ15; 
 
  /*  Initialize the Flag for selection of RFFT or RIFFT */ 
  S->ifftFlagR = (uint8_t) ifftFlagR; 
 
  /*  Initialize the Flag for calculation Bit reversal or not */ 
  S->bitReverseFlagR = (uint8_t) bitReverseFlag; 
 
  /*  Initialization of coef modifier depending on the FFT length */ 
  switch (S->fftLenReal) 
  { 
  case 2048u: 
    S->twidCoefRModifier = 1u; 
    break; 
  case 512u: 
    S->twidCoefRModifier = 4u; 
    break; 
  case 128u: 
    S->twidCoefRModifier = 16u; 
    break; 
  default: 
    /*  Reporting argument error if rfftSize is not valid value */ 
    status = ARM_MATH_ARGUMENT_ERROR; 
    break; 
  } 
 
  /* Init Complex FFT Instance */ 
  S->pCfft = S_CFFT; 
 
  if(S->ifftFlagR) 
  { 
    /* Initializes the CIFFT Module for fftLenreal/2 length */ 
    arm_cfft_radix4_init_q15(S->pCfft, S->fftLenBy2, 1u, 1u); 
  } 
  else 
  { 
    /* Initializes the CFFT Module for fftLenreal/2 length */ 
    arm_cfft_radix4_init_q15(S->pCfft, S->fftLenBy2, 0u, 1u); 
  } 
 
  /* return the status of RFFT Init function */ 
  return (status); 
 
} 
 
  /**  
   * @} end of RFFT_RIFFT group  
   */ 
