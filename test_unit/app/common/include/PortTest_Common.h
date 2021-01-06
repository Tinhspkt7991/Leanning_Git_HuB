/*============================================================================*/
/* Project      = AUTOSAR Renesas RCAR MCAL Components                        */
/* Module       = PortTest_Common.h                                           */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Definition of macroes                                                      */
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

#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include "Det.h"
#include "Port.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define PORT_FAIL                    0
#define PORT_PASS                    1
/* Defined in Port_PBTypes.h */
/* Alternative modes for Port_SetPinMode() API */
#define APP_ALT0                     (Port_PinModeType)0x00
#define APP_ALT1                     (Port_PinModeType)0x01
#define APP_ALT2                     (Port_PinModeType)0x02
#define APP_ALT3                     (Port_PinModeType)0x03
#define APP_ALT4                     (Port_PinModeType)0x04
#define APP_ALT5                     (Port_PinModeType)0x05
#define APP_ALT6                     (Port_PinModeType)0x06
#define APP_ALT7                     (Port_PinModeType)0x07
#define APP_ALT8                     (Port_PinModeType)0x08
#define APP_ALT9                     (Port_PinModeType)0x09
#define APP_ALT10                    (Port_PinModeType)0x0A
#define APP_ALT11                    (Port_PinModeType)0x0B
#define PORT_INVALID_MODE            (Port_PinModeType)0x0C
#define DIO                          (Port_PinModeType)0xFF
#define INTERRUPT                    (Port_PinModeType)0xFE
/*--------------------- End of macro 'protected_write'------------------------*/

#endif /* PORTTEST_COMMON_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
