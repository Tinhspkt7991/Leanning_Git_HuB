/*============================================================================*/
/* Project      = AUTOSAR Renesas RCar MCAL Components                        */
/* Module       = Port_UT_ETC017.c                                            */
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
  /* Check valid register. */
  /*--------------------------------------------------------------------------*/
  AES_TEST_ASSERT(((GPSR0 & 0x000F) == 0x0000) 
    && ((GPSR1 & 0x000F) == 0x000F) && ((IPSR1 & 0xF0000000) == 0x90000000)
      && ((IPSR2 & 0x0FFF) == 0x0642) && ((MOD_SEL1 & 0x0004) == 0x0000)
        && ((MOD_SEL0 & 0x60000000) == 0x20000000) 
          && ((PUEN2 & 0x3C00) == 0x2000) && ((PUD2 & 0x3C00) == 0x2000));
  /*--------------------------------------------------------------------------*/
  /* Step 3:                                                                  */
  /* Set valid register. */
  PMMR = ~(GPSR0 |= 0x0F); GPSR0 |= 0x0F;
  PMMR = ~(GPSR1 &= ~(uint32)0x0F); GPSR1 &= ~(uint32)0x0F;
  PMMR = ~(IPSR1 |= 0xF0000000); IPSR1 |= 0xF0000000; 
  PMMR = ~(IPSR2 |= 0xFFF); IPSR2 |= 0xFFF;
  PMMR = ~(MOD_SEL1 |= 0x0004);MOD_SEL1 |= 0x0004; 
  PMMR = ~(MOD_SEL0 |= 0x60000000);MOD_SEL0 |= 0x60000000;
  PMMR = ~(PUEN2 |= 0x3C00);PUEN2 |= 0x3C00;
  PMMR = ~(PUD2 |= 0x3C00);PUD2 |= 0x3C00;

    
  /*--------------------------------------------------------------------------*/
  /* Step 3:                                                                  */
  /* Invoke the Port_ConfigurationRegisterCheck API with valid parameters     */
  /*                                                                          */
  /*--------------------------------------------------------------------------*/
  Port_ConfigurationRegisterCheck(PORT_TRANSIENT_CHECK_ON);
  /*--------------------------------------------------------------------------*/
  /* Step 4:                                                                  */
  /* Check AES_TEST_ASSERT() will be invoked with the parameters              */
  /*                                                                          */
  /*--------------------------------------------------------------------------*/
  AES_TEST_ASSERT(((GPSR0 & 0x000F) == 0x0000) 
    && ((GPSR1 & 0x000F) == 0x000F) && ((IPSR1 & 0xF0000000) == 0x90000000)
      && ((IPSR2 & 0x0FFF) == 0x0642) && ((MOD_SEL1 & 0x0004) == 0x0000)
        && ((MOD_SEL0 & 0x60000000) == 0x20000000) 
          && ((PUEN2 & 0x3C00) == 0x2000) && ((PUD2 & 0x3C00) == 0x2000));
  AES_TEST_ASSERT((RFSO0 & 0x0006) == 0x0002);  
  AES_Report_Result();
}
/* End of main() function */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
