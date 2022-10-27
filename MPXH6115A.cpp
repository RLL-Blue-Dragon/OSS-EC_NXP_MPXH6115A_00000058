// License       : License.txt
// Specifications: Spec-MPXH6115A.pdf
/*-- File Header Comment Start -----------------------------------------------*/
// File Name        : MPXH6115A.cpp
// Reason for change: 01.00.00 : 20/10/'22 : New Release
// Nickname         : Blue Dragon
/*-- File Header Comment End -------------------------------------------------*/

#include        "MPXH6115A.h"

#if     iMPXH6115A_ma == iSMA                           // Simple moving average filter
static float32 MPXH6115A_sma_buf[iMPXH6115A_SMA_num];
static sma_f32_t MPXH6115A_Phy_SMA =
{
        iInitial ,                                      // Initial state
        iMPXH6115A_SMA_num ,                            // Simple moving average number & buf size
        0U ,                                            // buffer position
        0.0F ,                                          // sum
        &MPXH6115A_sma_buf[0]                           // buffer
};

#elif   iMPXH6115A_ma == iEMA                           // Exponential moving average filter
static ema_f32_t MPXH6115A_Phy_EMA =
{
        iInitial ,                                      // Initial state
        0.0F ,                                          // Xn-1
        iMPXH6115A_EMA_K                                // Exponential smoothing factor 
};

#elif   iMPXH6115A_ma == iWMA                           // Weighted moving average filter
static float32 MPXH6115A_wma_buf[iMPXH6115A_WMA_num];
static wma_f32_t MPXH6115A_Phy_WMA =
{
        iInitial ,                                      // Initial state
        iMPXH6115A_WMA_num ,                            // Weighted moving average number & buf size
        0U ,                                            // buffer poition
        iMPXH6115A_WMA_num * (iMPXH6115A_WMA_num + 1)/2 , // kn sum
        &MPXH6115A_wma_buf[0]                           // Xn buffer
};

#else                                                   // Non-moving average filter
#endif

#define iDummy_adr       0xffffffff                     // Dummy address

const tbl_adc_t tbl_MPXH6115A =
{
        iMPXH6115A              ,
        iMPXH6115A_pin          ,
        iMPXH6115A_xoff         ,
        iMPXH6115A_yoff         ,
        iMPXH6115A_gain         ,
        iMPXH6115A_max          ,
        iMPXH6115A_min          ,
        iMPXH6115A_ma           ,
        
#if     iMPXH6115A_ma == iSMA                           // Simple moving average filter
        &MPXH6115A_Phy_SMA      ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#elif   iMPXH6115A_ma == iEMA                           // Exponential moving average filter
        (sma_f32_t*)iDummy_adr  ,
        &MPXH6115A_Phy_EMA      ,
        (wma_f32_t*)iDummy_adr
#elif   iMPXH6115A_ma == iWMA                           // Weighted moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        &MPXH6115A_Phy_WMA
#else                                                   // Non-moving average filter
        (sma_f32_t*)iDummy_adr  ,
        (ema_f32_t*)iDummy_adr  ,
        (wma_f32_t*)iDummy_adr
#endif

};
