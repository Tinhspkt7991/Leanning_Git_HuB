/*============================================================================*/
/* Project      = AUTOSAR Renesas RCar MCAL Components                        */
/* Module       = Port_ETC024.c                                               */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file is a sample file for preparation of testing.                     */
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
/*              Devices:        R-Car H3                                      */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V1.0.0:  01-Apr-2016  : Initial Version
 */
/******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PortTest_Common.h"
#include "Det.h"
#include "Port.h"
#include "Port_Ram.h"
#include "Lib_Error_Check.h"
#include "PortTest_Specific.h"

/*******************************************************************************
**                      Global Variables                                      **
*******************************************************************************/

/*******************************************************************************
**                      Main Function Definitions                             **
*******************************************************************************/

int main(void)
{
  /*--------------------------------------------------------------------------*/
  /* Step 1:                                                                  */
  /* Invoke the Port_Init API with valid parameter.                           */
  /*                                                                          */
  /*--------------------------------------------------------------------------*/
  Port_Init(PortConfigSet);  

  /*--------------------------------------------------------------------------*/
  /* Step 2:                                                                  */
  /* Invoke Port_SetPinMode() API to set the requested pin to alternate mode. */
  
  Port_SetPinMode(Port_PortGroup1_PortPin0, APP_ALT0);
 /* Check the GPSR,IPSR, MODSEL PortGroup1 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && 
   ((IPSR1 & 0xF0000000) == 0x00000000));
 
  Port_SetPinMode(Port_PortGroup1_PortPin0, APP_ALT1);
 /* Check the GPSR,IPSR, MODSEL PortGroup1 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && 
   ((IPSR1 & 0xF0000000) == 0x10000000));
 
  Port_SetPinMode(Port_PortGroup1_PortPin0, APP_ALT2);
 /* Check the GPSR,IPSR, MODSEL PortGroup1 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && 
   ((IPSR1 & 0xF0000000) == 0x20000000) && 
     ((MOD_SEL0 & 0xE0000000) == 0x20000000));
 
  Port_SetPinMode(Port_PortGroup1_PortPin0, APP_ALT4);
 /* Check the GPSR,IPSR, MODSEL PortGroup1 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && 
   ((IPSR1 & 0xF0000000) == 0x40000000));

  Port_SetPinMode(Port_PortGroup1_PortPin0, APP_ALT6);
 /* Check the GPSR,IPSR, MODSEL PortGroup1 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && 
   ((IPSR1 & 0xF0000000) == 0x60000000));


  Port_SetPinMode(Port_PortGroup1_PortPin0, APP_ALT9);
 /* Check the GPSR,IPSR, MODSEL PortGroup1 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && 
   ((IPSR1 & 0xF0000000) == 0x90000000) && 
     ((MOD_SEL1 & 0x0004) == 0x0000));

 Port_SetPinMode(Port_PortGroup5_PortPin0, DIO);
  /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
  AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0000) 
    && ((IOINTSEL5 & 0x0001) == 0x0000));
    
 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT1);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001) && 
   ((IPSR11 & 0xF000000) == 0x1000000) && 
     ((MOD_SEL0 & 0x10000) == 0x10000));
 
 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT2);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001) && 
   ((IPSR11 & 0xF000000) == 0x2000000)&& 
     ((MOD_SEL0 & 0x7000000) == 0x1000000));


 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT3);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001) && 
   ((IPSR11 & 0xF000000) == 0x3000000) && 
     ((MOD_SEL2 & 0x20000) == 0x20000));

 
 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT4);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001) &&
   ((IPSR11 & 0xF000000) == 0x4000000) && 
     ((MOD_SEL0 & 0x200000) == 0x0000));


 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT5);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001)
   && ((IPSR11 & 0xF000000) == 0x5000000) && 
     ((MOD_SEL1 & 0x60000) == 0x20000));

   
 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT6);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001) && 
   ((IPSR11 & 0xF000000) == 0x6000000)&& ((MOD_SEL1 & 0xE00000) == 0x400000));
  
 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT7);
 /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001)
   && ((IPSR11 & 0xF000000) == 0x7000000)&& 
     ((MOD_SEL0 & 0x00C0) == 0x0040));

 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT9);   
  /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001)
   && ((IPSR11 & 0xF000000) == 0x9000000));
   
 Port_SetPinMode(Port_PortGroup5_PortPin0, APP_ALT10);   
  /* Check the GPSR,IPSR, MODSEL PortGroup5 for PortPin 0 */
 AES_TEST_ASSERT(((GPSR5 & 0x0001) == 0x0001)
   && ((IPSR11 & 0xF000000) == 0xA000000)
   && ((MOD_SEL2 & 0x4000000) == 0x4000000));    
   
   
 AES_TEST_ASSERT(((GPSR1 & 0x0001) == 0x0001) && ((GPSR5 & 0x0001) == 0x0001)
   && ((IPSR11 & 0xF000000) == 0xA000000) &&
     ((MOD_SEL0 & 0xE72100C0) == 0x21010040)
       && ((MOD_SEL1 & 0xE60004) == 0x420000)
         && ((MOD_SEL2 & 0x4020000) == 0x4020000));   

 AES_Report_Result();
}
/* End of main() function */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
