/*============================================================================*/
/* Project      = R-CarGen3 AUTOSAR MCAL Development Project                  */
/* Module       = Interrupt_VectorTable.c                                     */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2017-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains interrupt vector table                                  */
/*                                                                            */
/*============================================================================*/
/*                                                                            */
/* Unless otherwise agreed upon in writing between your company and           */
/* Renesas Electronics Corporation the following shall apply!                 */
/*                                                                            */
/* Warranty Disclaimer                                                        */
/*                                                                            */
/* There is no warranty of any kind whatsoever granted by Renesas. Any        */
/* warranty is expressly disclaimed and excluded by Renesas, either expressed */
/* or implied, including but not limited to those for non-infringement of     */
/* intellectual property, merchantability and/or fitness for the particular   */
/* purpose.                                                                   */
/*                                                                            */
/* Renesas shall not have any obligation to maintain, service or provide bug  */
/* fixes for the supplied Product(s) and/or the Application.                  */
/*                                                                            */
/* Each User is solely responsible for determining the appropriateness of     */
/* using the Product(s) and assumes all risks associated with its exercise    */
/* of rights under this Agreement, including, but not limited to the risks    */
/* and costs of program errors, compliance with applicable laws, damage to    */
/* or loss of data, programs or equipment, and unavailability or              */
/* interruption of operations.                                                */
/*                                                                            */
/* Limitation of Liability                                                    */
/*                                                                            */
/* In no event shall Renesas be liable to the User for any incidental,        */
/* consequential, indirect, or punitive damage (including but not limited     */
/* to lost profits) regardless of whether such liability is based on breach   */
/* of contract, tort, strict liability, breach of warranties, failure of      */
/* essential purpose or otherwise and even if advised of the possibility of   */
/* such damages. Renesas shall not be liable for any services or products     */
/* provided by third party vendors, developers or consultants identified or   */
/* referred to the User by Renesas in connection with the Product(s) and/or   */
/* the Application.                                                           */
/*                                                                            */
/*============================================================================*/
/* Environment:                                                               */
/*              Devices:        H3                                            */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  10-Jan-2017  : Initial Version
 * V1.0.1:  20-May-2017  : Update pre-compile option for CAN ISR
 * V1.0.2:  18-Jul-2017  : Update TMU_CH01_ISR for ETH sample application usage
 * V1.0.3:  15-Sep-2017  : Remove EMM interrupt handlers (H3 not supported).
 * V1.0.4:  10-Feb-2018  : Added one TMU interrupt handler to handle scheduled
 *                         functions.
 * V1.0.5:  26-Apr-2018  : Update file name for modules CAN, ETH and CDDICCOM
 * V1.0.6:  02-Oct-2018  : Remove mapping CAN_WAKEUP0_ISR in VectorTable.
 */
/******************************************************************************/

/*****************************************************************************/
/*                Module Specific header file inclusions                     */
/*****************************************************************************/
#include "Interrupt_VectorTable.h"
#include "Platform_Types.h"
#include "gic_cr7.h"
#include "gic_rcar.h"


#if (defined(GPT_MODULE_SAMPLE) || defined(GPT_MODULE_TEST))
    #define GPT_INT_TABLE
#endif
#if (defined(SPI_MODULE_SAMPLE) || defined(SPI_MODULE_TEST))
    #define SPI_INT_TABLE
#endif
#if (defined(CAN_MODULE_SAMPLE) || defined(GLOBAL_MODULE_TEST))
	#define CAN_INT_TABLE
#endif
#if (defined(ETH_MODULE_SAMPLE) || defined(ETH_MODULE_TEST))
    #define ETH_INT_TABLE
#endif
#if (defined(CDDICCOM_MODULE_SAMPLE) || defined(CDDICCOM_MODULE_TEST))
	#define CDDICCOM_INT_TABLE
#endif

#if (defined(MCU_MODULE_SAMPLE) && !defined(GLOBAL_SAMPLE))
#include "App_MCU_Specific_Sample.h"
#endif

#ifdef CDDBUSMONITOR_MODULE_SAMPLE
#include "CDD_BusMonitor_Irq.h"
#include "CDD_BusMonitor.h"
#endif

#ifdef CDDCMT1_MODULE_SAMPLE
#include "CDD_Cmt1_Irq.h"
#include "CDD_Cmt1.h"
#endif

#ifdef CDDSUCMT_MODULE_SAMPLE
#include "CDD_SUCMT_Irq.h"
#endif

#ifdef GPT_INT_TABLE
#include "Gpt_Irq.h"
#include "Gpt.h"
#endif

#ifdef SPI_INT_TABLE
#include "Spi_Irq.h"
#endif

#ifdef CAN_INT_TABLE
#include "Can.h"
#include "Can_Irq.h"
#endif


#if !defined(CAN_MODULE_DENSO_SAMPLE) && defined(CAN_MODULE_SAMPLE) && \
!defined(GLOBAL_SAMPLE)
#include "App_CAN_Specific_Sample.h"
#endif

#ifdef ETH_INT_TABLE
#include "Eth.h"
#include "Eth_Irq.h"
#endif

#if (defined(ETH_MODULE_SAMPLE_SPECIFIC) || defined(ETH_MODULE_SAMPLE)) && \
!defined(GLOBAL_SAMPLE)
#include "App_ETH_Specific_Sample.h"
#endif

#ifdef CDDICCOM_MODULE_SAMPLE
#include "App_CDD_ICCOM_Specific_Sample.h"
#include "CDD_Iccom.h"
#include "CDD_Iccom_Irq.h"
#endif

#ifdef ADC_MODULE_SAMPLE
#include "Adc_Irq.h"
#include "Adc.h"
#endif

#ifdef GLOBAL_MODULE_TEST
#include "App_Global_Device_Sample.h"
#include "Can.h"
#include "Can_Irq.h"
#endif

#ifdef GLOBAL_SAMPLE
#include "App_Global_Sample.h"
#endif
/* Set the linker to place in the opportune location (Deafult=0x200)  */
/*****************************************************************************/
/*                         ISR Definition                                    */
/*****************************************************************************/
void Dumpy_Handler(void)
{


}

/******************************************************************************/
/*                          Interrupt Vector Table                            */
/******************************************************************************/

/* The table of interrupt handlers */
const FUNCT IntVectors[]  =
{
  /* 0 */
  Dumpy_Handler,
  /* 1 */
  Dumpy_Handler,
  /* 2 */
  Dumpy_Handler,
  /* 3 */
  Dumpy_Handler,
  /* 4 */
  Dumpy_Handler,
  /* 5 */
  Dumpy_Handler,
  /* 6 */
  Dumpy_Handler,
  /* 7 */
  Dumpy_Handler,
  /* 8 */
  Dumpy_Handler,
  /* 9 */
  Dumpy_Handler,
  /* 10 */
  Dumpy_Handler,
  /* 11 */
  Dumpy_Handler,
  /* 12 */
  Dumpy_Handler,
  /* 13 */
  Dumpy_Handler,
  /* 14 */
  Dumpy_Handler,
  /* 15 */
  Dumpy_Handler,
  /* 16 */
  Dumpy_Handler,
  /* 17 */
  Dumpy_Handler,
  /* 18 */
  Dumpy_Handler,
  /* 19 */
  Dumpy_Handler,
  /* 20 */
  Dumpy_Handler,
  /* 21 */
  Dumpy_Handler,
  /* 22 */
  Dumpy_Handler,
  /* 23 */
  Dumpy_Handler,
  /* 24 */
  Dumpy_Handler,
  /* 25 */
  Dumpy_Handler,
  /* 26 */
  Dumpy_Handler,
  /* 27 */
  Dumpy_Handler,
  /* 28 */
  Dumpy_Handler,
  /* 29 */
  Dumpy_Handler,
  /* 30 */
  Dumpy_Handler,
  /* 31 */
  Dumpy_Handler,
  /* 32 */
  Dumpy_Handler,
  /* 33 */
  Dumpy_Handler,
  /* 34 */
  Dumpy_Handler,
  /* 35 */
  Dumpy_Handler,
  /* 36 */
  Dumpy_Handler,
  /* 37 */
  Dumpy_Handler,
  /* 38 */
  Dumpy_Handler,
  /* 39 */
  Dumpy_Handler,
  /* 40 */
  Dumpy_Handler,
  /* 41 */
  Dumpy_Handler,
  /* 42 */
  Dumpy_Handler,
  /* 43 */
  Dumpy_Handler,
  /* 44 */
  Dumpy_Handler,
  /* 45 */
  Dumpy_Handler,
  /* 46 */
  Dumpy_Handler,
  /* 47 */
  Dumpy_Handler,
  /* 48 */
  Dumpy_Handler,
  /* 49 */
  Dumpy_Handler,
  /* 50 */
  Dumpy_Handler,
  /* 51 */
  Dumpy_Handler,
  /* 52 */
  Dumpy_Handler,
  /* 53 */
  Dumpy_Handler,
  /* 54 */
  Dumpy_Handler,
  /* 55 */
  Dumpy_Handler,
  /* 56 */
  Dumpy_Handler,
  /* 57 */
  Dumpy_Handler,
  /* 58 */
  Dumpy_Handler,
  /* 59 */
  Dumpy_Handler,
  /* 60 */
  Dumpy_Handler,
  /* 61 */
#ifdef CAN_INT_TABLE
    #if ((CAN_CHANNEL_INTERRUPT == STD_ON) || (CAN_PUBLIC_ICOM_SUPPORT == STD_ON))
       #define CAN_CHANNEL_ISR
    #else
       #define Dumpy_Handler
    #endif
#endif
  /* 62 */
#ifdef CAN_INT_TABLE
    #if (((CAN_RXFIFO_INTERRUPT == STD_ON) && (CAN_RX_FIFO == STD_ON)) || \
    (CAN_PUBLIC_ICOM_SUPPORT == STD_ON))
       #define CAN_GLOBAL_ISR
    #else
       #define Dumpy_Handler
    #endif
#endif
  /* 63 */
  Dumpy_Handler,
  /* 64 */
  Dumpy_Handler,
  /* 65 */
  Dumpy_Handler,
  /* 66 */
  Dumpy_Handler,
  /* 67 */
  Dumpy_Handler,
  /* 68 */
  Dumpy_Handler,
  /* 69 */
  Dumpy_Handler,
  /* 70 */
  Dumpy_Handler,
  /* 71 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh00Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 72 */
  #if(defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh01Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 73 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh02Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 74 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh03Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 75 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh04Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 76 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh05Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 77 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh06Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 78 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh07Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 79 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh08Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 80 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh09Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 81 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh10Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 82 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh11Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 83 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh12Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 84 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh13Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 85 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh14Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 86 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh15Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 87 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh16Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 88 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_RX_INTERRUPT == STD_ON)
  Eth_AvbCh17Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 89 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_TX_INTERRUPT == STD_ON)
  Eth_AvbCh18Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 90 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_TX_INTERRUPT == STD_ON)
  Eth_AvbCh19Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 91 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_TX_INTERRUPT == STD_ON)
  Eth_AvbCh20Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 92 */
  #if (defined ETH_INT_TABLE) && (ETH_CTRL_ENABLE_TX_INTERRUPT == STD_ON)
  Eth_AvbCh21Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 93 */
  #ifdef ETH_MODULE_SAMPLE
  Eth_AvbCh22Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 94 */
  #ifdef ETH_MODULE_SAMPLE
  Eth_AvbCh23Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 95 */
  #ifdef ETH_MODULE_SAMPLE
  Eth_AvbCh24Isr,
  #else
  Dumpy_Handler,
  #endif
  /* 96 */
  Dumpy_Handler,
  /* 97 */
  Dumpy_Handler,
  /* 98 */
  Dumpy_Handler,
  /* 99 */
  Dumpy_Handler,
  /* 100 */
  Dumpy_Handler,
  /* 101 */
  Dumpy_Handler,
  /* 102 */
  Dumpy_Handler,
  /* 103 */
  Dumpy_Handler,
  /* 104 */
  Dumpy_Handler,
  /* 105 */
  Dumpy_Handler,
  /* 106 */
  Dumpy_Handler,
  /* 107 */
  Dumpy_Handler,
  /* 108 */
  Dumpy_Handler,
  /* 109 */
  Dumpy_Handler,
  /* 110 */
  Dumpy_Handler,
  /* 111 */
  Dumpy_Handler,
  /* 112 */
  Dumpy_Handler,
  /* 113 */
  Dumpy_Handler,
  /* 114 */
  Dumpy_Handler,
  /* 115 */
  Dumpy_Handler,
  /* 116 */
  Dumpy_Handler,
  /* 117 */
  Dumpy_Handler,
  /* 118 */
  Dumpy_Handler,
  /* 119 */
  Dumpy_Handler,
  /* 120 */
  Dumpy_Handler,
  /* 121 */
  Dumpy_Handler,
  /* 122 */
  Dumpy_Handler,
  /* 123 */
  Dumpy_Handler,
  /* 124 */
  Dumpy_Handler,
  /* 125 */
  Dumpy_Handler,
  /* 126 */
  Dumpy_Handler,
  /* 127 */
  Dumpy_Handler,
  /* 128 */
  Dumpy_Handler,
  /* 129 */
  Dumpy_Handler,
  /* 130 */
  Dumpy_Handler,
  /* 131 */
  Dumpy_Handler,
  /* 132 */
  Dumpy_Handler,
  /* 133 */
  Dumpy_Handler,
  /* 134 */
  Dumpy_Handler,
  /* 135 */
  Dumpy_Handler,
  /* 136 */
  Dumpy_Handler,
  /* 137 */
  Dumpy_Handler,
  /* 138 */
  Dumpy_Handler,
  /* 139 */
  Dumpy_Handler,
  /* 140 */
  Dumpy_Handler,
  /* 141 */
  Dumpy_Handler,
  /* 142 */
  Dumpy_Handler,
  /* 143 */
  Dumpy_Handler,
  /* 144 */
  Dumpy_Handler,
  /* 145 */
  Dumpy_Handler,
  /* 146 */
  Dumpy_Handler,
  /* 147 */
  Dumpy_Handler,
  /* 148 */
  Dumpy_Handler,
  /* 149 */
  Dumpy_Handler,
  /* 150 */
#ifdef CDDBUSMONITOR_MODULE_SAMPLE
  CDD_BUSMONITOR_ISR,
#else
  Dumpy_Handler,
#endif
  /* 151 */
  Dumpy_Handler,
  /* 152 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH00_ISR_API == STD_ON)
  CDD_CMT1_CH00_ISR,
#else
  Dumpy_Handler,
#endif
  /* 153 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH01_ISR_API == STD_ON)
  CDD_CMT1_CH01_ISR,
#else
  Dumpy_Handler,
#endif
  /* 154 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH02_ISR_API == STD_ON)
  CDD_CMT1_CH02_ISR,
#else
  Dumpy_Handler,
#endif
  /* 155 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH03_ISR_API == STD_ON)
  CDD_CMT1_CH03_ISR,
#else
  Dumpy_Handler,
#endif
  /* 156 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH04_ISR_API == STD_ON)
  CDD_CMT1_CH04_ISR,
#else
  Dumpy_Handler,
#endif
  /* 157 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH05_ISR_API == STD_ON)
  CDD_CMT1_CH05_ISR,
#else
  Dumpy_Handler,
#endif
  /* 158 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH06_ISR_API == STD_ON)
  CDD_CMT1_CH06_ISR,
#else
  Dumpy_Handler,
#endif
  /* 159 */
#if defined(CDDCMT1_MODULE_SAMPLE) && (CMT1_CH07_ISR_API == STD_ON)
  CDD_CMT1_CH07_ISR,
#else
  Dumpy_Handler,
#endif
  /* 160 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH03_ISR_API == STD_ON)
  TMU_CH03_ISR,
#elif (defined(MCU_MODULE_SAMPLE) && !defined(GLOBAL_SAMPLE))
  TMU3_Isr,
#else
  Dumpy_Handler,
#endif
  /* 161 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH04_ISR_API == STD_ON)
  TMU_CH04_ISR,
#else
  Dumpy_Handler,
#endif
  /* 162 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH05_ISR_API == STD_ON)
  TMU_CH05_ISR,
#else
  Dumpy_Handler,
#endif
  /* 163 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH09_ISR_API == STD_ON)
  TMU_CH09_ISR,
#else
  Dumpy_Handler,
#endif
  /* 164 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH10_ISR_API == STD_ON)
  TMU_CH10_ISR,
#else
  Dumpy_Handler,
#endif
  /* 165 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH11_ISR_API == STD_ON)
    TMU_CH11_ISR,
#else
  Dumpy_Handler,
#endif
  /* 166 */
  Dumpy_Handler,
  /* 167 */
  Dumpy_Handler,
  /* 168 */
#if (defined (GPT_INT_TABLE) && (GPT_TMU_CH00_ISR_API == STD_ON)) || \
  defined(ETH_MODULE_SAMPLE_SPECIFIC) || defined(GLOBAL_SAMPLE)
  TMU_CH00_ISR,
#elif defined (CDDICCOM_INT_TABLE)
  Appl_Scheduler_Task,
#elif defined(CAN_MODULE_SAMPLE) && \
!defined(GLOBAL_SAMPLE) && !defined(CAN_MODULE_DENSO_SAMPLE)
  CAN_Scheduler_Task,
#else
  Dumpy_Handler,
#endif
  /* 169 */
#if ((defined (GPT_INT_TABLE) && (GPT_TMU_CH01_ISR_API == STD_ON)) || \
  defined(ETH_MODULE_SAMPLE_SPECIFIC) || defined(ETH_MODULE_SAMPLE)) && \
  !defined(GLOBAL_SAMPLE)
  TMU_CH01_ISR,
#else
  Dumpy_Handler,
#endif
  /* 170 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH02_ISR_API == STD_ON)
  TMU_CH02_ISR,
#else
  Dumpy_Handler,
#endif
  /* 171 */
#ifdef CDDSUCMT_MODULE_SAMPLE
  CDD_SUCMT_ISR,
#else
  Dumpy_Handler,
#endif
  /* 172 */
  Dumpy_Handler,
  /* 173 */
  Dumpy_Handler,
  /* 174 */
  Dumpy_Handler,
  /* 175 */
  Dumpy_Handler,
  /* 176 */
  Dumpy_Handler,
  /* 177 */
  Dumpy_Handler,
  /* 178 */
  Dumpy_Handler,
  /* 179 */
  Dumpy_Handler,
  /* 180 */
  Dumpy_Handler,
  /* 181 */
  Dumpy_Handler,
  /* 182 */
  Dumpy_Handler,
  /* 183 */
  Dumpy_Handler,
  /* 184 */
  Dumpy_Handler,
  /* 185 */
  Dumpy_Handler,
  /* 186 */
  Dumpy_Handler,
  /* 187 */
  Dumpy_Handler,
  /* 188 */
  #if defined (SPI_INT_TABLE) && (SPI_MSIOF0_ISR_API == STD_ON)
  SPI_MSIOF0_ISR,
  #else
  Dumpy_Handler,
  #endif
  /* 189 */
  #if defined (SPI_INT_TABLE) && (SPI_MSIOF1_ISR_API == STD_ON)
  SPI_MSIOF1_ISR,
  #else
  Dumpy_Handler,
  #endif
  /* 190 */
  Dumpy_Handler,
  /* 191 */
  #if defined (SPI_INT_TABLE) && (SPI_MSIOF3_ISR_API == STD_ON)
  SPI_MSIOF3_ISR,
  #else
  Dumpy_Handler,
  #endif
  /* 192 */
  Dumpy_Handler,
  /* 193 */
  Dumpy_Handler,
  /* 194 */
  Dumpy_Handler,
  /* 195 */
  Dumpy_Handler,
  /* 196 */
  Dumpy_Handler,
  /* 197 */
  Dumpy_Handler,
  /* 198 */
  Dumpy_Handler,
  /* 199 */
  Dumpy_Handler,
  /* 200 */
  Dumpy_Handler,
  /* 201 */
  Dumpy_Handler,
  /* 202 */
  Dumpy_Handler,
  /* 203 */
  Dumpy_Handler,
  /* 204 */
  Dumpy_Handler,
  /* 205 */
  Dumpy_Handler,
  /* 206 */
  Dumpy_Handler,
  /* 207 */
  Dumpy_Handler,
  /* 208 */
  Dumpy_Handler,
  /* 209 */
  Dumpy_Handler,
  /* 210 */
  Dumpy_Handler,
  /* 211 */
  Dumpy_Handler,
  /* 212 */
  Dumpy_Handler,
  /* 213 */
  Dumpy_Handler,
  /* 214 */
  Dumpy_Handler,
  /* 215 */
  Dumpy_Handler,
  /* 216 */
  Dumpy_Handler,
  /* 217 */
  Dumpy_Handler,
  /* 218 */
  Dumpy_Handler,
  /* 219 */
  Dumpy_Handler,
  /* 220 */
  Dumpy_Handler,
  /* 221 */
  Dumpy_Handler,
  /* 222 */
  Dumpy_Handler,
  /* 223 */
  Dumpy_Handler,
  /* 224 */
  Dumpy_Handler,
  /* 225 */
  Dumpy_Handler,
  /* 226 */
  Dumpy_Handler,
  /* 227 */
  Dumpy_Handler,
  /* 228 */
  Dumpy_Handler,
  /* 229 */
  Dumpy_Handler,
  /* 230 */
  Dumpy_Handler,
  /* 231 */
  Dumpy_Handler,
  /* 232 */
  Dumpy_Handler,
  /* 233 */
  Dumpy_Handler,
  /* 234 */
  Dumpy_Handler,
  /* 235 */
  Dumpy_Handler,
  /* 236 */
  Dumpy_Handler,
  /* 237 */
  Dumpy_Handler,
  /* 238 */
  Dumpy_Handler,
  /* 239 */
  Dumpy_Handler,
  /* 240 */
  Dumpy_Handler,
  /* 241 */
  Dumpy_Handler,
  /* 242 */
  Dumpy_Handler,
  /* 243 */
  Dumpy_Handler,
  /* 244 */
  Dumpy_Handler,
  /* 245 */
  Dumpy_Handler,
  /* 246 */
  Dumpy_Handler,
  /* 247 */
  Dumpy_Handler,
  /* 248 */
  Dumpy_Handler,
  /* 249 */
  Dumpy_Handler,
  /* 250 */
  Dumpy_Handler,
  /* 251 */
  Dumpy_Handler,
  /* 252 */
  Dumpy_Handler,
  /* 253 */
  Dumpy_Handler,
  /* 254 */
  Dumpy_Handler,
  /* 255 */
  Dumpy_Handler,
  /* 256 */
#ifdef CDDICCOM_MODULE_SAMPLE
  MFIS_ARIICR0_ISR,
#else
  Dumpy_Handler,
#endif
  /* 257 */
  Dumpy_Handler,
  /* 258 */
  Dumpy_Handler,
  /* 259 */
  Dumpy_Handler,
  /* 260 */
  Dumpy_Handler,
  /* 261 */
  Dumpy_Handler,
  /* 262 */
  Dumpy_Handler,
  /* 263 */
  Dumpy_Handler,
  /* 264 */
  Dumpy_Handler,
  /* 265 */
  Dumpy_Handler,
  /* 266 */
  Dumpy_Handler,
  /* 267 */
  Dumpy_Handler,
  /* 268 */
  Dumpy_Handler,
  /* 269 */
  Dumpy_Handler,
  /* 270 */
  Dumpy_Handler,
  /* 271 */
  Dumpy_Handler,
  /* 272 */
  Dumpy_Handler,
  /* 273 */
  Dumpy_Handler,
  /* 274 */
  Dumpy_Handler,
  /* 275 */
  Dumpy_Handler,
  /* 276 */
  Dumpy_Handler,
  /* 277 */
  Dumpy_Handler,
  /* 278 */
  Dumpy_Handler,
  /* 279 */
  Dumpy_Handler,
  /* 280 */
  Dumpy_Handler,
  /* 281 */
  Dumpy_Handler,
  /* 282 */
  Dumpy_Handler,
  /* 283 */
  Dumpy_Handler,
  /* 284 */
  Dumpy_Handler,
  /* 285 */
  Dumpy_Handler,
  /* 286 */
  Dumpy_Handler,
  /* 287 */
  Dumpy_Handler,
  /* 288 */
  Dumpy_Handler,
  /* 289 */
  Dumpy_Handler,
  /* 290 */
  Dumpy_Handler,
  /* 291 */
  Dumpy_Handler,
  /* 292 */
  Dumpy_Handler,
  /* 293 */
  Dumpy_Handler,
  /* 294 */
  Dumpy_Handler,
  /* 295 */
  Dumpy_Handler,
  /* 296 */
  Dumpy_Handler,
  /* 297 */
  Dumpy_Handler,
  /* 298 */
  Dumpy_Handler,
  /* 299 */
  Dumpy_Handler,
  /* 300 */
  Dumpy_Handler,
  /* 301 */
  Dumpy_Handler,
  /* 302 */
  Dumpy_Handler,
  /* 303 */
  Dumpy_Handler,
  /* 304 */
  Dumpy_Handler,
  /* 305 */
  Dumpy_Handler,
  /* 306 */
  Dumpy_Handler,
  /* 307 */
  Dumpy_Handler,
  /* 308 */
  Dumpy_Handler,
  /* 309 */
  Dumpy_Handler,
  /* 310 */
  Dumpy_Handler,
  /* 311 */
  Dumpy_Handler,
  /* 312 */
  Dumpy_Handler,
  /* 313 */
  Dumpy_Handler,
  /* 314 */
  Dumpy_Handler,
  /* 315 */
  Dumpy_Handler,
  /* 316 */
  Dumpy_Handler,
  /* 317 */
  Dumpy_Handler,
  /* 318 */
  Dumpy_Handler,
  /* 319 */
  Dumpy_Handler,
  /* 320 */
  Dumpy_Handler,
  /* 321 */
  Dumpy_Handler,
  /* 322 */
  Dumpy_Handler,
  /* 323 */
  Dumpy_Handler,
  /* 324 */
  Dumpy_Handler,
  /* 325 */
  Dumpy_Handler,
  /* 326 */
  Dumpy_Handler,
  /* 327 */
  Dumpy_Handler,
  /* 328 */
  Dumpy_Handler,
  /* 329 */
  Dumpy_Handler,
  /* 330 */
  Dumpy_Handler,
  /* 331 */
  Dumpy_Handler,
  /* 332 */
  Dumpy_Handler,
  /* 333 */
  Dumpy_Handler,
  /* 334 */
  Dumpy_Handler,
  /* 335 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH06_ISR_API == STD_ON)
  TMU_CH06_ISR,
#else
  Dumpy_Handler,
#endif
  /* 336 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH07_ISR_API == STD_ON)
  TMU_CH07_ISR,
#else
  Dumpy_Handler,
#endif
  /* 337 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH08_ISR_API == STD_ON)
  TMU_CH08_ISR,
#else
  Dumpy_Handler,
#endif
  /* 338 */
  Dumpy_Handler,
  /* 339 */
  Dumpy_Handler,
  /* 340 */
  Dumpy_Handler,
  /* 341 */
  Dumpy_Handler,
  /* 342 */
  Dumpy_Handler,
  /* 343 */
  Dumpy_Handler,
  /* 344 */
  Dumpy_Handler,
  /* 345 */
  Dumpy_Handler,
  /* 346 */
  Dumpy_Handler,
  /* 347 */
  Dumpy_Handler,
  /* 348 */
  Dumpy_Handler,
  /* 349 */
  Dumpy_Handler,
  /* 350 */
  Dumpy_Handler,
  /* 351 */
  Dumpy_Handler,
  /* 352 */
  Dumpy_Handler,
  /* 353 */
  Dumpy_Handler,
  /* 354 */
  Dumpy_Handler,
  /* 355 */
  Dumpy_Handler,
  /* 356 */
  Dumpy_Handler,
  /* 357 */
  Dumpy_Handler,
  /* 358 */
  Dumpy_Handler,
  /* 359 */
  Dumpy_Handler,
  /* 360 */
  Dumpy_Handler,
  /* 361 */
  Dumpy_Handler,
  /* 362 */
  Dumpy_Handler,
  /* 363 */
  Dumpy_Handler,
  /* 364 */
  Dumpy_Handler,
  /* 365 */
  Dumpy_Handler,
  /* 366 */
  Dumpy_Handler,
  /* 367 */
  Dumpy_Handler,
  /* 368 */
  Dumpy_Handler,
  /* 369 */
  Dumpy_Handler,
  /* 370 */
  Dumpy_Handler,
  /* 371 */
  Dumpy_Handler,
  /* 372 */
  Dumpy_Handler,
  /* 373 */
  Dumpy_Handler,
  /* 374 */
  Dumpy_Handler,
  /* 375 */
  Dumpy_Handler,
  /* 376 */
  Dumpy_Handler,
  /* 377 */
  Dumpy_Handler,
  /* 378 */
  Dumpy_Handler,
  /* 379 */
  Dumpy_Handler,
  /* 380 */
  Dumpy_Handler,
  /* 381 */
  Dumpy_Handler,
  /* 382 */
  Dumpy_Handler,
  /* 383 */
  Dumpy_Handler,
  /* 384 */
  Dumpy_Handler,
  /* 385 */
  Dumpy_Handler,
  /* 386 */
  Dumpy_Handler,
  /* 387 */
  Dumpy_Handler,
  /* 388 */
  Dumpy_Handler,
  /* 389 */
  Dumpy_Handler,
  /* 390 */
  Dumpy_Handler,
  /* 391 */
  Dumpy_Handler,
  /* 392 */
  Dumpy_Handler,
  /* 393 */
  Dumpy_Handler,
  /* 394 */
  Dumpy_Handler,
  /* 395 */
  Dumpy_Handler,
  /* 396 */
  Dumpy_Handler,
  /* 397 */
  Dumpy_Handler,
  /* 398 */
  Dumpy_Handler,
  /* 399 */
  Dumpy_Handler,
  /* 400 */
  Dumpy_Handler,
  /* 401 */
  Dumpy_Handler,
  /* 402 */
  Dumpy_Handler,
  /* 403 */
  Dumpy_Handler,
  /* 404 */
  Dumpy_Handler,
  /* 405 */
  Dumpy_Handler,
  /* 406 */
  Dumpy_Handler,
  /* 407 */
  Dumpy_Handler,
  /* 408 */
  Dumpy_Handler,
  /* 409 */
  Dumpy_Handler,
  /* 410 */
  Dumpy_Handler,
  /* 411 */
  Dumpy_Handler,
  /* 412 */
  Dumpy_Handler,
  /* 413 */
  Dumpy_Handler,
  /* 414 */
  Dumpy_Handler,
  /* 415 */
  Dumpy_Handler,
  /* 416 */
  Dumpy_Handler,
  /* 417 */
  Dumpy_Handler,
  /* 418 */
  Dumpy_Handler,
  /* 419 */
  Dumpy_Handler,
  /* 420 */
  Dumpy_Handler,
  /* 421 */
  Dumpy_Handler,
  /* 422 */
  Dumpy_Handler,
  /* 423 */
  Dumpy_Handler,
  /* 424 */
  Dumpy_Handler,
  /* 425 */
  Dumpy_Handler,
  /* 426 */
  Dumpy_Handler,
  /* 427 */
  Dumpy_Handler,
  /* 428 */
  Dumpy_Handler,
  /* 429 */
  Dumpy_Handler,
  /* 430 */
  Dumpy_Handler,
  /* 431 */
  Dumpy_Handler,
  /* 432 */
  Dumpy_Handler,
  /* 433 */
  Dumpy_Handler,
  /* 434 */
  Dumpy_Handler,
  /* 435 */
  Dumpy_Handler,
  /* 436 */
  Dumpy_Handler,
  /* 437 */
  Dumpy_Handler,
  /* 438 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH12_ISR_API == STD_ON)
  TMU_CH12_ISR,
#else
  Dumpy_Handler,
#endif
  /* 439 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH13_ISR_API == STD_ON)
  TMU_CH13_ISR,
#else
  Dumpy_Handler,
#endif
  /* 440 */
#if defined (GPT_INT_TABLE) && (GPT_TMU_CH14_ISR_API == STD_ON)
  TMU_CH14_ISR,
#else
  Dumpy_Handler,
#endif
  /* 441 */
  Dumpy_Handler,
  /* 442 */
  Dumpy_Handler,
  /* 443 */
  Dumpy_Handler,
  /* 444 */
  Dumpy_Handler,
  /* 445 */
  Dumpy_Handler,
  /* 446 */
  Dumpy_Handler,
  /* 447 */
  Dumpy_Handler,
  /* 448 */
  Dumpy_Handler,
  /* 449 */
  Dumpy_Handler,
  /* 450 */
  Dumpy_Handler,
  /* 451 */
  Dumpy_Handler,
  /* 452 */
  Dumpy_Handler,
  /* 453 */
  Dumpy_Handler,
  /* 454 */
  Dumpy_Handler,
  /* 455 */
  Dumpy_Handler,
  /* 456 */
  Dumpy_Handler,
  /* 457 */
  Dumpy_Handler,
  /* 458 */
  Dumpy_Handler,
  /* 459 */
  Dumpy_Handler,
  /* 460 */
  Dumpy_Handler,
  /* 461 */
  Dumpy_Handler,
  /* 462 */
  Dumpy_Handler,
  /* 463 */
  Dumpy_Handler,
  /* 464 */
  Dumpy_Handler,
  /* 465 */
  Dumpy_Handler,
  /* 466 */
  Dumpy_Handler,
  /* 467 */
  Dumpy_Handler,
  /* 468 */
  Dumpy_Handler,
  /* 469 */
  Dumpy_Handler,
  /* 470 */
  Dumpy_Handler,
  /* 471 */
  Dumpy_Handler,
  /* 472 */
  Dumpy_Handler,
  /* 473 */
  Dumpy_Handler,
  /* 474 */
  Dumpy_Handler,
  /* 475 */
  Dumpy_Handler,
  /* 476 */
  Dumpy_Handler,
  /* 477 */
  Dumpy_Handler,
  /* 478 */
  Dumpy_Handler,
  /* 479 */
  Dumpy_Handler,
  /* 480 */
  Dumpy_Handler,
  /* 481 */
  Dumpy_Handler,
  /* 482 */
  Dumpy_Handler,
  /* 483 */
  Dumpy_Handler,
  /* 484 */
  Dumpy_Handler,
  /* 485 */
  Dumpy_Handler,
  /* 486 */
  Dumpy_Handler,
  /* 487 */
  Dumpy_Handler,
  /* 488 */
  Dumpy_Handler,
  /* 489 */
  Dumpy_Handler,
  /* 490 */
  Dumpy_Handler,
  /* 491 */
  Dumpy_Handler,
  /* 492 */
  Dumpy_Handler,
  /* 493 */
  Dumpy_Handler,
  /* 494 */
  Dumpy_Handler,
  /* 495 */
  Dumpy_Handler,
  /* 496 */
  Dumpy_Handler,
  /* 497 */
  Dumpy_Handler,
  /* 498 */
  Dumpy_Handler,
  /* 499 */
  Dumpy_Handler,
  /* 500 */
  Dumpy_Handler,
  /* 501 */
  Dumpy_Handler,
  /* 502 */
  Dumpy_Handler,
  /* 503 */
  Dumpy_Handler,
  /* 504 */
  Dumpy_Handler,
  /* 505 */
  Dumpy_Handler,
  /* 506 */
  Dumpy_Handler,
  /* 507 */
  Dumpy_Handler,
  /* 508 */
  Dumpy_Handler,
  /* 509 */
  Dumpy_Handler,
  /* 510 */
  Dumpy_Handler,
  /* 511 */
  Dumpy_Handler,
};

/******************************************************************************
**                          End of File                                      **
*******************************************************************************/
