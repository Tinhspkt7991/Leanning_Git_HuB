/*============================================================================*/
/* Project      = AUTOSAR Renesas RCar MCAL Components                        */
/* Module       = Port_UT_ETC031.c                                             */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* This file contains the test application to test the invocation of DET.     */
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
 * V1.0.0:  10-Jul-2018  : Initial Version
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

/*******************************************************************************
**                      Global Variables                                      **
*******************************************************************************/

/*******************************************************************************
**                      Main Function Definitions                             **
*******************************************************************************/

int main(void)
{
  /* A loop to avoid the controller going into a free-running mode */
  
  /*--------------------------------------------------------------------------*/
  /* Step 1:                                                                  */
  /* Invoke the Port_Init API with valid parameters                           */
  /*                                                                          */
  /*--------------------------------------------------------------------------*/
  Port_Init(PortConfigSet);
  /*--------------------------------------------------------------------------*/
  /* Step 2:                                                                  */
  /* Invoke the Port_SetPinDirection API with valid parameters                */
  /*                                                                          */
  /*--------------------------------------------------------------------------*/
  Port_SetPinDirection(Port_PortGroup0_PortPin0, PORT_PIN_OUT);
  /*--------------------------------------------------------------------------*/
  /* Step 3:                                                                  */
  /* Check Det_ReportError() will be invoked with the parameters              */
  /*                                                                          */
  /*--------------------------------------------------------------------------*/
  AES_TEST_ASSERT(E_OK == Det_TestLastReportError(PORT_MODULE_ID,
          PORT_INSTANCE_ID,PORT_SET_PIN_DIR_SID,PORT_E_DIRECTION_UNCHANGEABLE));
  AES_Report_Result();
}
/* End of main() function */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
