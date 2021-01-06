/*============================================================================*/
/* Project      = AUTOSAR Renesas RCar MCAL Components                        */
/* Module       = PortTest_Specific.h                                         */
/*============================================================================*/
/*                                  COPYRIGHT                                 */
/*============================================================================*/
/* Copyright(c) 2016 Renesas Electronics Corporation                          */
/*============================================================================*/
/* Purpose:                                                                   */
/* Provision for compiler macros and external declarations.                   */
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

#ifndef TEST_SPECIFIC_H
#define TEST_SPECIFIC_H

#define Device "H3"

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define NUM_OF_TEST_RESULT_PER_GROUP    10
#define NUM_OF_TESTED_PORT_GROUP_05      8
#define NUM_OF_TESTED_PORT_GROUP         9

#define MaxPin  154
/* Port group 0: configuration registers */
#define IOINTSEL0                           *((volatile uint32 *)(0xE6050000UL))
#define INOUTSEL0                           *((volatile uint32 *)(0xE6050004UL))
#define OUTDT0                              *((volatile uint32 *)(0xE6050008UL))
#define INDT0                               *((volatile uint32 *)(0xE605000CUL))
#define INTDT0                              *((volatile uint32 *)(0xE6050010UL))
#define INTCLR0                             *((volatile uint32 *)(0xE6050014UL))
#define INTMSK0                             *((volatile uint32 *)(0xE6050018UL))
#define MSKCLR0                             *((volatile uint32 *)(0xE605001CUL))
#define POSNEG0                             *((volatile uint32 *)(0xE6050020UL))
#define EDGLEVEL0                           *((volatile uint32 *)(0xE6050024UL))
#define FILONOFF0                           *((volatile uint32 *)(0xE6050028UL))
#define INTMSKS0                            *((volatile uint32 *)(0xE6050038UL))
#define MSKCLRS0                            *((volatile uint32 *)(0xE605003CUL))
#define OUTDTSEL0                           *((volatile uint32 *)(0xE6050040UL))
#define OUTDTH0                             *((volatile uint32 *)(0xE6050044UL))
#define OUTDTL0                             *((volatile uint32 *)(0xE6050048UL))
#define BOTHEDGE0                           *((volatile uint32 *)(0xE605004CUL))


/* Port group 1: configuration registers */
#define IOINTSEL1                           *((volatile uint32 *)(0xE6051000UL))
#define INOUTSEL1                           *((volatile uint32 *)(0xE6051004UL))
#define OUTDT1                              *((volatile uint32 *)(0xE6051008UL))
#define INDT1                               *((volatile uint32 *)(0xE605100CUL))
#define INTDT1                              *((volatile uint32 *)(0xE6051010UL))
#define INTCLR1                             *((volatile uint32 *)(0xE6051014UL))
#define INTMSK1                             *((volatile uint32 *)(0xE6051018UL))
#define MSKCLR1                             *((volatile uint32 *)(0xE605101CUL))
#define POSNEG1                             *((volatile uint32 *)(0xE6051020UL))
#define EDGLEVEL1                           *((volatile uint32 *)(0xE6051024UL))
#define FILONOFF1                           *((volatile uint32 *)(0xE6051028UL))
#define INTMSKS1                            *((volatile uint32 *)(0xE6051038UL))
#define MSKCLRS1                            *((volatile uint32 *)(0xE605103CUL))
#define OUTDTSEL1                           *((volatile uint32 *)(0xE6051040UL))
#define OUTDTH1                             *((volatile uint32 *)(0xE6051044UL))
#define OUTDTL1                             *((volatile uint32 *)(0xE6051048UL))
#define BOTHEDGE1                           *((volatile uint32 *)(0xE605104CUL))


/* Port group 2: configuration registers */
#define IOINTSEL2                           *((volatile uint32 *)(0xE6052000UL))
#define INOUTSEL2                           *((volatile uint32 *)(0xE6052004UL))
#define OUTDT2                              *((volatile uint32 *)(0xE6052008UL))
#define INDT2                               *((volatile uint32 *)(0xE605200CUL))
#define INTDT2                              *((volatile uint32 *)(0xE6052010UL))
#define INTCLR2                             *((volatile uint32 *)(0xE6052014UL))
#define INTMSK2                             *((volatile uint32 *)(0xE6052018UL))
#define MSKCLR2                             *((volatile uint32 *)(0xE605201CUL))
#define POSNEG2                             *((volatile uint32 *)(0xE6052020UL))
#define EDGLEVEL2                           *((volatile uint32 *)(0xE6052024UL))
#define FILONOFF2                           *((volatile uint32 *)(0xE6052028UL))
#define INTMSKS2                            *((volatile uint32 *)(0xE6052038UL))
#define MSKCLRS2                            *((volatile uint32 *)(0xE605203CUL))
#define OUTDTSEL2                           *((volatile uint32 *)(0xE6052040UL))
#define OUTDTH2                             *((volatile uint32 *)(0xE6052044UL))
#define OUTDTL2                             *((volatile uint32 *)(0xE6052048UL))
#define BOTHEDGE2                           *((volatile uint32 *)(0xE605204CUL))


/* Port group 3: configuration registers */
#define IOINTSEL3                           *((volatile uint32 *)(0xE6053000UL))
#define INOUTSEL3                           *((volatile uint32 *)(0xE6053004UL))
#define OUTDT3                              *((volatile uint32 *)(0xE6053008UL))
#define INDT3                               *((volatile uint32 *)(0xE605300CUL))
#define INTDT3                              *((volatile uint32 *)(0xE6053010UL))
#define INTCLR3                             *((volatile uint32 *)(0xE6053014UL))
#define INTMSK3                             *((volatile uint32 *)(0xE6053018UL))
#define MSKCLR3                             *((volatile uint32 *)(0xE605301CUL))
#define POSNEG3                             *((volatile uint32 *)(0xE6053020UL))
#define EDGLEVEL3                           *((volatile uint32 *)(0xE6053024UL))
#define FILONOFF3                           *((volatile uint32 *)(0xE6053028UL))
#define INTMSKS3                            *((volatile uint32 *)(0xE6053038UL))
#define MSKCLRS3                            *((volatile uint32 *)(0xE605303CUL))
#define OUTDTSEL3                           *((volatile uint32 *)(0xE6053040UL))
#define OUTDTH3                             *((volatile uint32 *)(0xE6053044UL))
#define OUTDTL3                             *((volatile uint32 *)(0xE6053048UL))
#define BOTHEDGE3                           *((volatile uint32 *)(0xE605304CUL))


/* Port group 4: configuration registers */
#define IOINTSEL4                           *((volatile uint32 *)(0xE6054000UL))
#define INOUTSEL4                           *((volatile uint32 *)(0xE6054004UL))
#define OUTDT4                              *((volatile uint32 *)(0xE6054008UL))
#define INDT4                               *((volatile uint32 *)(0xE605400CUL))
#define INTDT4                              *((volatile uint32 *)(0xE6054010UL))
#define INTCLR4                             *((volatile uint32 *)(0xE6054014UL))
#define INTMSK4                             *((volatile uint32 *)(0xE6054018UL))
#define MSKCLR4                             *((volatile uint32 *)(0xE605401CUL))
#define POSNEG4                             *((volatile uint32 *)(0xE6054020UL))
#define EDGLEVEL4                           *((volatile uint32 *)(0xE6054024UL))
#define FILONOFF4                           *((volatile uint32 *)(0xE6054028UL))
#define INTMSKS4                            *((volatile uint32 *)(0xE6054038UL))
#define MSKCLRS4                            *((volatile uint32 *)(0xE605403CUL))
#define OUTDTSEL4                           *((volatile uint32 *)(0xE6054040UL))
#define OUTDTH4                             *((volatile uint32 *)(0xE6054044UL))
#define OUTDTL4                             *((volatile uint32 *)(0xE6054048UL))
#define BOTHEDGE4                           *((volatile uint32 *)(0xE605404CUL))


/* Port group 5: configuration registers */
#define IOINTSEL5                           *((volatile uint32 *)(0xE6055000UL))
#define INOUTSEL5                           *((volatile uint32 *)(0xE6055004UL))
#define OUTDT5                              *((volatile uint32 *)(0xE6055008UL))
#define INDT5                               *((volatile uint32 *)(0xE605500CUL))
#define INTDT5                              *((volatile uint32 *)(0xE6055010UL))
#define INTCLR5                             *((volatile uint32 *)(0xE6055014UL))
#define INTMSK5                             *((volatile uint32 *)(0xE6055018UL))
#define MSKCLR5                             *((volatile uint32 *)(0xE605501CUL))
#define POSNEG5                             *((volatile uint32 *)(0xE6055020UL))
#define EDGLEVEL5                           *((volatile uint32 *)(0xE6055024UL))
#define FILONOFF5                           *((volatile uint32 *)(0xE6055028UL))
#define INTMSKS5                            *((volatile uint32 *)(0xE6055038UL))
#define MSKCLRS5                            *((volatile uint32 *)(0xE605503CUL))
#define OUTDTSEL5                           *((volatile uint32 *)(0xE6055040UL))
#define OUTDTH5                             *((volatile uint32 *)(0xE6055044UL))
#define OUTDTL5                             *((volatile uint32 *)(0xE6055048UL))
#define BOTHEDGE5                           *((volatile uint32 *)(0xE605504CUL))


/* Port group 6: configuration registers */
#define IOINTSEL6                           *((volatile uint32 *)(0xE6055400UL))
#define INOUTSEL6                           *((volatile uint32 *)(0xE6055404UL))
#define OUTDT6                              *((volatile uint32 *)(0xE6055408UL))
#define INDT6                               *((volatile uint32 *)(0xE605540CUL))
#define INTDT6                              *((volatile uint32 *)(0xE6055410UL))
#define INTCLR6                             *((volatile uint32 *)(0xE6055414UL))
#define INTMSK6                             *((volatile uint32 *)(0xE6055418UL))
#define MSKCLR6                             *((volatile uint32 *)(0xE605541CUL))
#define POSNEG6                             *((volatile uint32 *)(0xE6055420UL))
#define EDGLEVEL6                           *((volatile uint32 *)(0xE6055424UL))
#define FILONOFF6                           *((volatile uint32 *)(0xE6055428UL))
#define INTMSKS6                            *((volatile uint32 *)(0xE6055438UL))
#define MSKCLRS6                            *((volatile uint32 *)(0xE605543CUL))
#define OUTDTSEL6                           *((volatile uint32 *)(0xE6055440UL))
#define OUTDTH6                             *((volatile uint32 *)(0xE6055444UL))
#define OUTDTL6                             *((volatile uint32 *)(0xE6055448UL))
#define BOTHEDGE6                           *((volatile uint32 *)(0xE605544CUL))


/* Port group 7: configuration registers */
#define IOINTSEL7                           *((volatile uint32 *)(0xE6055800UL))
#define INOUTSEL7                           *((volatile uint32 *)(0xE6055804UL))
#define OUTDT7                              *((volatile uint32 *)(0xE6055808UL))
#define INDT7                               *((volatile uint32 *)(0xE605580CUL))
#define INTDT7                              *((volatile uint32 *)(0xE6055810UL))
#define INTCLR7                             *((volatile uint32 *)(0xE6055814UL))
#define INTMSK7                             *((volatile uint32 *)(0xE6055818UL))
#define MSKCLR7                             *((volatile uint32 *)(0xE605581CUL))
#define POSNEG7                             *((volatile uint32 *)(0xE6055820UL))
#define EDGLEVEL7                           *((volatile uint32 *)(0xE6055824UL))
#define FILONOFF7                           *((volatile uint32 *)(0xE6055828UL))
#define INTMSKS7                            *((volatile uint32 *)(0xE6055838UL))
#define MSKCLRS7                            *((volatile uint32 *)(0xE605583CUL))
#define OUTDTSEL7                           *((volatile uint32 *)(0xE6055840UL))
#define OUTDTH7                             *((volatile uint32 *)(0xE6055844UL))
#define OUTDTL7                             *((volatile uint32 *)(0xE6055848UL))
#define BOTHEDGE7                           *((volatile uint32 *)(0xE605584CUL))


/*Port enable/disable multiplex pin                                           */
#define PMMR                                *((volatile uint32 *)(0xE6060000UL))

/*Port mode register                                                          */
#define GPSR0                               *((volatile uint32 *)(0xE6060100UL))
#define GPSR1                               *((volatile uint32 *)(0xE6060104UL))
#define GPSR2                               *((volatile uint32 *)(0xE6060108UL))
#define GPSR3                               *((volatile uint32 *)(0xE606010CUL))
#define GPSR4                               *((volatile uint32 *)(0xE6060110UL))
#define GPSR5                               *((volatile uint32 *)(0xE6060114UL))
#define GPSR6                               *((volatile uint32 *)(0xE6060118UL))
#define GPSR7                               *((volatile uint32 *)(0xE606011CUL))

/*Port mode control register                                                  */
#define IPSR0                               *((volatile uint32 *)(0xE6060200UL))
#define IPSR1                               *((volatile uint32 *)(0xE6060204UL))
#define IPSR2                               *((volatile uint32 *)(0xE6060208UL))
#define IPSR3                               *((volatile uint32 *)(0xE606020CUL))
#define IPSR4                               *((volatile uint32 *)(0xE6060210UL))
#define IPSR5                               *((volatile uint32 *)(0xE6060214UL))
#define IPSR6                               *((volatile uint32 *)(0xE6060218UL))
#define IPSR7                               *((volatile uint32 *)(0xE606021CUL))
#define IPSR8                               *((volatile uint32 *)(0xE6060220UL))
#define IPSR9                               *((volatile uint32 *)(0xE6060224UL))
#define IPSR10                              *((volatile uint32 *)(0xE6060228UL))
#define IPSR11                              *((volatile uint32 *)(0xE606022CUL))
#define IPSR12                              *((volatile uint32 *)(0xE6060230UL))
#define IPSR13                              *((volatile uint32 *)(0xE6060234UL))
#define IPSR14                              *((volatile uint32 *)(0xE6060238UL))
#define IPSR15                              *((volatile uint32 *)(0xE606023CUL))
#define IPSR16                              *((volatile uint32 *)(0xE6060240UL))
#define IPSR17                              *((volatile uint32 *)(0xE6060244UL))
#define IPSR18                              *((volatile uint32 *)(0xE6060248UL))

/* Pull enable register                                                       */
#define PUEN0                               *((volatile uint32 *)(0xE6060400UL))
#define PUEN1                               *((volatile uint32 *)(0xE6060404UL))
#define PUEN2                               *((volatile uint32 *)(0xE6060408UL))
#define PUEN3                               *((volatile uint32 *)(0xE606040CUL))
#define PUEN4                               *((volatile uint32 *)(0xE6060410UL))
#define PUEN5                               *((volatile uint32 *)(0xE6060414UL))
#define PUEN6                               *((volatile uint32 *)(0xE6060418UL))

/* Pull-up/ down control register                                             */
#define PUD0                                *((volatile uint32 *)(0xE6060440UL))
#define PUD1                                *((volatile uint32 *)(0xE6060444UL))
#define PUD2                                *((volatile uint32 *)(0xE6060448UL))
#define PUD3                                *((volatile uint32 *)(0xE606044CUL))
#define PUD4                                *((volatile uint32 *)(0xE6060450UL))
#define PUD5                                *((volatile uint32 *)(0xE6060454UL))
#define PUD6                                *((volatile uint32 *)(0xE6060458UL))

/*Module select register*/
#define MOD_SEL0                            *((volatile uint32 *)(0xE6060500UL))
#define MOD_SEL1                            *((volatile uint32 *)(0xE6060504UL))
#define MOD_SEL2                            *((volatile uint32 *)(0xE6060508UL))


#define RFSO0                               *((volatile uint32 *)(0xFFE80008UL)) 
#define RFSO1                               *((volatile uint32 *)(0xFFE81008UL))
#define RFSO2                               *((volatile uint32 *)(0xFFE82008UL))
#define RFSO3                               *((volatile uint32 *)(0xFFE83008UL))
#define RFSO4                               *((volatile uint32 *)(0xFFE84008UL))
#define RFSO5                               *((volatile uint32 *)(0xFFE85008UL))
#define RFSO6                               *((volatile uint32 *)(0xFFE86008UL))

/*FUSE_MON register*/
#define FUSE_MON0                           *((volatile uint32 *)(0xE60603E4UL))
/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/


#endif /* PORTTEST_SPECIFIC_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
