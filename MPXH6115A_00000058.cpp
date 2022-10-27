// License       : License.txt
// Specifications: Spec-00000058.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXH6115A_00000058.cpp
// BSL              : 00000058
// Model number     : NXP MPXH6115A
// Spec               Component type       : ADC
//                    OS                   : Mbed
//                    Calculation          : Floating-point
//                    Conversion type      : Linear
//                    Moving average filter: Moving average filter select
//                    Diagnosis            : Range (Min to Max)
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include "MPXH6115A.h"

AnalogIn MPXH6115A_adc( iMPXH6115A_pin , iVref );       // AnalogIn object

// Main Function
pp2ap_adc_t MPXH6115A_00000058( void )
{
        pp2ap_adc_t res = pp_00000058( MPXH6115A_adc , tbl_MPXH6115A );
        return( res );
}
