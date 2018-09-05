//
// This file contains an 'Intel Pre-EFI Module' and is licensed
// for Intel CPUs and Chipsets under the terms of your license
// agreement with Intel or your vendor.  This file may be
// modified by the user, subject to additional terms of the
// license agreement
//
/*************************************************************************
 *
 * Reference Code
 *
 * ESS - Enterprise Silicon Software
 *
 * INTEL CONFIDENTIAL
 *
 * Copyright (c) 2006 - 2016, Intel Corporation All Rights Reserved.
 *
 * The source code contained or described herein and all documents
 * related to the source code ("Material") are owned by Intel
 * Corporation or its suppliers or licensors. Title to the Material
 * remains with Intel Corporation or its suppliers and licensors.
 * The Material contains trade secrets and proprietary and confidential
 * information of Intel or its suppliers and licensors. The Material
 * is protected by worldwide copyright and trade secret laws and treaty
 * provisions.  No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel's prior express written permission.
 *
 * No license under any patent, copyright, trade secret or other
 * intellectual property right is granted to or conferred upon you
 * by disclosure or delivery of the Materials, either expressly,
 * by implication, inducement, estoppel or otherwise. Any license
 * under such intellectual property rights must be express and
 * approved by Intel in writing.
 *
 ************************************************************************/
#ifndef  _platformhost_h
#define  _platformhost_h

//
// MAX Number of Processor supported by Intel platform
//
#include "MaxSocket.h"

#ifndef MAX_CORE
#define MAX_CORE                       28         // Maximum cores per CPU (SKX)
#define MAX_CORE_BITMASK               0xFFFFFFF    // for SKX CPU
#endif

#ifndef MAX_KTI_PORTS
#define MAX_KTI_PORTS                   3  // Max KTI ports supported
#endif

//
// Post Package Repair
//
#define PPR_SUPPORT 1
#define MAX_PPR_ADDR_ENTRIES           20

// Select one of the following platforms
//#define DVP_PLATFORM  1  // DVP
//
#define CRB_PLATFORM  1    // SRP

#ifndef DVP_PLATFORM
#ifndef CRB_PLATFORM

//#define ASM_INC       1

/*
 MULTIPLE_PLATFORM_SUPPORT should be defined when the user KNOWS that inputs
  (the ones defined to zero under this flag below) are given via sysSetup structure
*/
#define MULTIPLE_PLATFORM_SUPPORT  1
#endif
#endif

#if !defined(SILENT_MODE)
// APTIOV_SERVER_OVERRIDE_RC_START : MRC debug messages are controlled through EXTERNAL CC FLAGS
//#define SERIAL_DBG_MSG  1 
// APTIOV_SERVER_OVERRIDE_RC_END : MRC debug messages are controlled through EXTERNAL CC FLAGS
#endif
#define RC_BEGIN_END_DEBUG_HOOKS

//#define HW_EMULATION 1

#define SOFT_SDV_FLAG   BIT0      // flag to indicate running on Soft SDV
#define VP_FLAG         BIT1      // flag to indicate running on VP
#define SIMICS_FLAG     BIT2      // flag to indicate running on Simics
#define RTL_SIM_FLAG    BIT3      // flag to indicate running on the RTL simulator
#define QUIET_MODE      BIT16     // flag to enable minimal debug messages
#define RANDOM_TRAINING BIT17     // flag to enable random training responses from Simics
#define FORCE_SETUP     BIT18     // flag to force BIOS setup
#define DDR_TRAINING_EN BIT19     // flag to tell the BIOS to execute DDR training
//
// Enumerated Platform SMBUS controllers
//

#define PLATFORM_SMBUS_CONTROLLER_PROCESSOR   0
#define PLATFORM_SMBUS_CONTROLLER_PCH         1

#ifndef TypePlatformDefault
//
// Platform types - if not defined already
//
typedef enum {
  TypeNeonCityEPRP = 0x00,
  TypeNeonCityEPECB,
  TypeOpalCitySTHI,
  TypePurleyLBGEPDVP,
  TypeWolfPass,
  TypeBuchananPass,
  TypeCrescentCity,
  TypeHedtEV,
  TypeHedtCRB,
  TypeLightningRidgeEXRP,
  TypeLightningRidgeEXECB1,
  TypeLightningRidgeEXECB2,
  TypeLightningRidgeEXECB3,
  TypeLightningRidgeEXECB4,
  TypeLightningRidgeEX8S1N,
  TypeLightningRidgeEX8S2N,
  TypeBarkPeak,
  TypeKyanite,
  TypeSawtoothPass,  // We need to keep the value of TypeSawtoothPass unchanged
  TypeNeonCityFPGA,
  TypeOpalCityFPGA,
  TypeYubaCityRP
} EFI_PLATFORM_TYPE;


#define TypePlatformUnknown       0xFF
#define TypePlatformMin           TypeNeonCityEPRP
#define TypePlatformMax           TypeYubaCityRP
#define TypePlatformDefault       TypeNeonCityEPRP
#define TypePlatformOpalCityPPV   6
#define TypePlatformOpalCityCPV   7
#endif


//
// Enumerated Unique Platform Component IDs
//
#define NOT_INITIALIZED                 0
#define SPD                             1
#define DCP_ISL9072X                    2
#define DCP_AD5247                      3
#define MTS                             4  //TSOD
#define RSTPLD                          5
#define NO_DEV                          0xFFFF
//
// Default I/O base addresses
//
#define  REG_ACPI_BASE_ADDRESS          0x40
#define  PM_ENABLE                      0x44
#define  IO_REG_ACPI_TIMER              0x08
#define  REG_GPIO_BASE_ADDRESS          0x48
#ifdef MINIBIOS_BUILD
#define  ICH_PMBASE_ADDR                0x500
#endif //MINIBIOS_BUILD

//
//#define  ICH_GPIOBASE_ADDR              0x500
#define  ICH_SMBBASE_ADDR               0x700
#define  R_PCH_SMBUS_PCICMD             0x04
#define  B_PCH_SMBUS_PCICMD_IOSE        BIT0
#define  R_PCH_SMBUS_BASE               0x20
#define  B_PCH_SMBUS_BASE_BAR           0x0000FFE0
#define  R_PCH_SMBUS_HOSTC              0x40
#define  B_PCH_SMBUS_HOSTC_HST_EN       BIT0
//
#define  SERIAL_DBG_COM_BASE            0x3F8
//
// Platform SMBUS definitions
//
#define SMB_SEG0                        0
#define SMB_SEG1                        1
#define SMB_SEG2                        2
#define SMB_SEG3                        3

//
// Major Warning codes
//
#define  WARN_SETUP_INVALID         0x01
#define  WARN_MINOR_WILDCARD  0xff

#define  SMB_TIMEOUT    100000     // 100 ms
#define  SMB_RETRY_LIMIT   20       // 2 sec
#define  CATCHALL_TIMEOUT  100000    // 100 ms
#ifndef  MMCFG_BASE_ADDRESS
#define  MMCFG_BASE_ADDRESS  0x80000000
#endif
#define FOUR_GB_MEM         0x40                // 4GB in 64MB units
#define MAX_MEM_ADDR        0x40000             // 46-bit addressing (256MB units)
#define HIGH_GAP            1                   // High gap (256 MB units)
#define MMCFG_SIZE          256*1024*1024       // MMCFG Size (in Bytes)
#define MMIOH_SIZE          0                   // MMIOH Size Granularity per stack (1GB, (1<<(2*size)))
#define DEFAULT_COM_PORT    0x80
//
//-----------------------------------------------------------------------------
//
#include "MemPlatform.h"

#endif   // _platformhost_h

