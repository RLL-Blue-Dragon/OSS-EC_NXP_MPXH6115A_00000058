// License       : License.txt
// Specifications: Spec-MPXH6115A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXH6115A.h
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#ifndef __MPXH6115A_H__
#define __MPXH6115A_H__

#include "user_define.h"

// Components number
#define iMPXH6115A              119U                    // NXP MPXH6115A

// MPXH6115A System Parts definitions
#define iMPXH6115A_xoff         ( -0.095F*iADC_vdd )    // X offset [V]
#define iMPXH6115A_yoff         0.0F                    // Y offset [kPa]
#define iMPXH6115A_gain         ( 0.009F*iADC_vdd )     // Gain [V/kPa]
#define iMPXH6115A_max          115.0F                  // Pressure Max [kPa]
#define iMPXH6115A_min          15.0F                   // Pressure Min [kPa]

extern const tbl_adc_t tbl_MPXH6115A;

#endif /*__MPXH6115A_H__*/
