/*============================================================================*/
/* Project      = R-CarGen3 AUTOSAR MCAL Development Project                  */
/* Module       = SchM_Port.c                                                 */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2015-2018 Renesas Electronics Corporation                     */
/*============================================================================*/
/* Purpose:                                                                   */
/* This application file contains the Schm PORT Stub functions.               */
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
/*              Devices:      R-Car Series, 3rd Generation                    */
/*============================================================================*/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 1.0.0      14-Jan-2016      Initial Version
 * 1.0.1      13-Apr-2018      Change ENABLE_INTERRUPT to EnableAllInterrupts
 *                             Change DISABLE_INTERRUPT to DisableAllInterrupts
 */
/******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Os.h"
#include "SchM_Port.h"

/*******************************************************************************
**        SchM_Enter_Port_SET_PIN_MODE_PROTECTION()                           **
*******************************************************************************/
void SchM_Enter_Port_SET_PIN_MODE_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_SET_PIN_MODE_PROTECTION()                            **
*******************************************************************************/
void SchM_Exit_Port_SET_PIN_MODE_PROTECTION(void)
{
  EnableAllInterrupts();
}

/*******************************************************************************
**        SchM_Enter_Port_SET_PIN_DIR_PROTECTION()                            **
*******************************************************************************/
void SchM_Enter_Port_SET_PIN_DIR_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_SET_PIN_DIR_PROTECTION()                        **
*******************************************************************************/
void SchM_Exit_Port_SET_PIN_DIR_PROTECTION(void)
{
  EnableAllInterrupts();
}

/*******************************************************************************
**        SchM_Enter_Port_SET_TO_DIO_ALT_PROTECTION()                    **
*******************************************************************************/
void SchM_Enter_Port_SET_TO_DIO_ALT_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_SET_TO_DIO_ALT_PROTECTION()                     **
*******************************************************************************/
void SchM_Exit_Port_SET_TO_DIO_ALT_PROTECTION(void)
{
  EnableAllInterrupts();
}

/*******************************************************************************
**        SchM_Enter_Port_REFRESH_PORT_INTERNAL_PROTECTION()                  **
*******************************************************************************/
void SchM_Enter_Port_REFRESH_PORT_INTERNAL_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_REFRESH_PORT_INTERNAL_PROTECTION()              **
*******************************************************************************/
void SchM_Exit_Port_REFRESH_PORT_INTERNAL_PROTECTION(void)
{
  EnableAllInterrupts();
}

/*******************************************************************************
**        SchM_Enter_Port_SET_PIN_DEFAULT_MODE_PROTECTION()              **
*******************************************************************************/
void SchM_Enter_Port_SET_PIN_DEFAULT_MODE_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_SET_PIN_DEFAULT_MODE_PROTECTION()               **
*******************************************************************************/
void SchM_Exit_Port_SET_PIN_DEFAULT_MODE_PROTECTION(void)
{
  EnableAllInterrupts();
}

/*******************************************************************************
**        SchM_Enter_Port_SET_PIN_DEFAULT_DIR_PROTECTION()               **
*******************************************************************************/
void SchM_Enter_Port_SET_PIN_DEFAULT_DIR_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_SET_PIN_DEFAULT_DIR_PROTECTION()                **
*******************************************************************************/
void SchM_Exit_Port_SET_PIN_DEFAULT_DIR_PROTECTION(void)
{
  EnableAllInterrupts();
}
/*******************************************************************************
**        SchM_Enter_Port_SET_PIN_DEFAULT_DIR_PROTECTION()                    **
*******************************************************************************/
void SchM_Enter_Port_REGISTER_PROTECTION(void)
{
  DisableAllInterrupts();
}

/*******************************************************************************
**        SchM_Exit_Port_SET_PIN_DEFAULT_DIR_PROTECTION()                     **
*******************************************************************************/
void SchM_Exit_Port_REGISTER_PROTECTION(void)
{
  EnableAllInterrupts();
}

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
