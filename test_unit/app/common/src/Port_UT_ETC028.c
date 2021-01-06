/*============================================================================*/
/* Project      = AUTOSAR Renesas RCar MCAL Components                        */
/* Module       = Port_ETC028.c                                               */
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
uint32 value;
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
  /*  Invoke Port_SetToDioMode() API  to set the  pin to mode.                */

  /*--------------------------------------------------------------------------*/
  Port_SetToDioMode(Port_PortGroup0_PortPin0);
  Port_SetToDioMode(Port_PortGroup0_PortPin1);
  Port_SetToDioMode(Port_PortGroup0_PortPin2);
  Port_SetToDioMode(Port_PortGroup0_PortPin3);
  Port_SetToDioMode(Port_PortGroup0_PortPin4);
  Port_SetToDioMode(Port_PortGroup0_PortPin5);
  Port_SetToDioMode(Port_PortGroup0_PortPin6);
  Port_SetToDioMode(Port_PortGroup0_PortPin7);
  Port_SetToDioMode(Port_PortGroup0_PortPin8);
  Port_SetToDioMode(Port_PortGroup0_PortPin9);
  Port_SetToDioMode(Port_PortGroup0_PortPin10);
  Port_SetToDioMode(Port_PortGroup0_PortPin11);
  Port_SetToDioMode(Port_PortGroup0_PortPin12);
  Port_SetToDioMode(Port_PortGroup0_PortPin13);
  Port_SetToDioMode(Port_PortGroup0_PortPin14);
  Port_SetToDioMode(Port_PortGroup0_PortPin15);
  
  Port_SetToAlternateMode(Port_PortGroup3_PortPin0);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin1);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin2);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin3);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin4);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin5);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin6);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin7);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin8);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin9);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin10);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin11);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin12);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin13);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin14);
  Port_SetToAlternateMode(Port_PortGroup3_PortPin15);


  /* Check the PortGroup0, PortGroup3 registers */
  AES_TEST_ASSERT(((GPSR0 & 0xFFFF) == 0x0000)
    &&((IOINTSEL0 & 0xFFFF) == 0x0000));

  AES_TEST_ASSERT((GPSR3 & 0xFFFF) == 0xFFFF);
  
  AES_Report_Result();
  
}
/* End of main() function */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
