//
// This file contains 'Framework Code' and is licensed as such
// under the terms of your license agreement with Intel or your
// vendor.  This file may not be modified, except as allowed by
// additional terms of your license agreement.
//
/** @file
  UbaGpioInitLib implementation.

  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>
  This software and associated documentation (if any) is furnished
  under a license and may only be used or copied in accordance
  with the terms of the license. Except as permitted by such
  license, no part of this software or documentation may be
  reproduced, stored in a retrieval system, or transmitted in any
  form or by any means without the express written consent of
  Intel Corporation.
**/

#include <PiPei.h>
#include <Ppi/UbaCfgDb.h>
#include <Library/PeiServicesLib.h>
#include <Library/DebugLib.h>
#include <Library/PcdLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UbaGpioInitLib.h>
#include <Library/GpioLib.h>
#include <Library/PeiDxeSmmGpioLib/GpioLibrary.h>
#include <Library/HobLib.h>

/**
  Configure GPIO

  @param[in]  PlatformInfo
**/

static GPIO_INIT_CONFIG meSPIConfig[] =
{
  { GPIO_SKL_H_GPP_A0, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_0_LPC_RCIN_N_ESPI_ALERT1_N
  { GPIO_SKL_H_GPP_A1, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermWpu20K, GpioPadConfigLock } },//GPP_A_1_LAD_0_ESPI_IO_0
  { GPIO_SKL_H_GPP_A2, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermWpu20K, GpioPadConfigLock } },//GPP_A_2_LAD_1_ESPI_IO_1
  { GPIO_SKL_H_GPP_A3, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermWpu20K, GpioPadConfigLock } },//GPP_A_3_LAD_2_ESPI_IO_2
  { GPIO_SKL_H_GPP_A4, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermWpu20K, GpioPadConfigLock } },//GPP_A_4_LAD_3_ESPI_IO_3
  { GPIO_SKL_H_GPP_A5, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermWpu20K, GpioPadConfigLock } },//GPP_A_5_LPC_LFRAME_N_ESPI_CS0_N
  { GPIO_SKL_H_GPP_A6, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_6_IRQ_LPC_SERIRQ_ESPI_CS1_N
  { GPIO_SKL_H_GPP_A7, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_7_IRQ_LPC_PIRQA_N_ESPI_ALERT0_N
  { GPIO_SKL_H_GPP_A8, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirInOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_8_FM_LPC_CLKRUN_N
  { GPIO_SKL_H_GPP_A9, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermWpd20K, GpioPadConfigLock } },//GPP_A_9_CLK_24M_66M_LPC0_ESPI
  { GPIO_SKL_H_GPP_A10, { GpioPadModeNative1, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_10_TP_PCH_GPP_A_10
  { GPIO_SKL_H_GPP_A11, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_11_FM_LPC_PME_N
  { GPIO_SKL_H_GPP_A12, { GpioPadModeGpio, GpioHostOwnAcpi, GpioDirInInv, GpioOutDefault, GpioIntLevel | GpioIntSci, GpioResetNormal, GpioTermNone } },//GPP_A_12_IRQ_PCH_SCI_WHEA_N
  { GPIO_SKL_H_GPP_A13, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock | GpioOutputStateLock } },//GPP_A_13_FM_EUP_LOT6_N
  { GPIO_SKL_H_GPP_A14, { GpioPadModeNative3, GpioHostOwnGpio, GpioDirOut, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_14_ESPI_RESET_N
  { GPIO_SKL_H_GPP_A15, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirIn, GpioOutDefault, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock } },//GPP_A_15_SUSACK_N
  { GPIO_SKL_H_GPP_A16, { GpioPadModeGpio, GpioHostOwnGpio, GpioDirOut, GpioOutHigh, GpioIntDis, GpioResetDeep, GpioTermNone, GpioPadConfigLock | GpioOutputStateLock } },// CLK_48MHZ_PCH [GPP_A_16_CLKOUT_LPC_2]
};


VOID 
UpdateeSPIConfiguration (
  IN UINT32                    NumberOfItems,
  IN GPIO_INIT_CONFIG          *GpioInitTableAddress
) 
{
  UINT8 Index1, Index2;

  for(Index1 = 0; Index1 < sizeof (meSPIConfig)/sizeof (GPIO_INIT_CONFIG); Index1++) {
    for (Index2 = 0; Index2 < NumberOfItems; Index2++) {
      if (meSPIConfig[Index1].GpioPad == (GpioInitTableAddress+Index2)->GpioPad){
        (GpioInitTableAddress + Index2)->GpioConfig = meSPIConfig[Index1].GpioConfig;
      }
    }
  }
}

EFI_STATUS
PlatformInitGpios (
  VOID
)
{
  EFI_STATUS                            Status;
  UBA_CONFIG_DATABASE_PPI               *UbaConfigPpi = NULL;
  GPIO_INIT_CONFIG                      *GpioTable;
  UINTN                                 TableSize;
  UINT32                                SpiConfigValue;
  GPIO_INIT_CONFIG                      *mPchGpioInitData = NULL;
  VOID                                  *HobPtr;
  
  Status = PeiServicesLocatePpi (
              &gUbaConfigDatabasePpiGuid, 
              0,
              NULL,
              &UbaConfigPpi
              );
  if (EFI_ERROR(Status)) {
    return Status;
  }

  TableSize = PcdGet32(PcdOemSku_GPIO_TABLE_SIZE);
  DEBUG ((DEBUG_ERROR, "UBA:Size of GpioTable 0x%X, blocks: 0x%X.\n", TableSize, (TableSize/sizeof (GPIO_INIT_CONFIG)) ));
  Status = PeiServicesAllocatePool (TableSize, &GpioTable);
  if (EFI_ERROR(Status)) {
   return Status;
  }
  Status = UbaConfigPpi->GetData (
                                UbaConfigPpi,
                                &gPlatformGpioInitDataGuid,
                                GpioTable,
                                &TableSize
                                );
  
  if (EFI_ERROR(Status)) {
    return Status;
  }

  SpiConfigValue = 0;
  PchPcrRead32(PID_ESPISPI, R_PCH_PCR_SPI_CONF_VALUE, &SpiConfigValue);
  DEBUG((DEBUG_ERROR, "SPI Config Value = %x; ", SpiConfigValue));
  if (SpiConfigValue & B_ESPI_ENABLE_STRAP) {
    DEBUG((DEBUG_ERROR, "eSPI Mode\n"));
  } else {
    DEBUG((DEBUG_ERROR, "LPC Mode\n"));
  }

  if (SpiConfigValue & B_ESPI_ENABLE_STRAP) {
    mPchGpioInitData = AllocateZeroPool((UINTN)TableSize);
    if (mPchGpioInitData != NULL){
      CopyMem(mPchGpioInitData, GpioTable, TableSize);
      UpdateeSPIConfiguration((UINT32)(TableSize / sizeof(GPIO_INIT_CONFIG)), mPchGpioInitData);
    } else {
      DEBUG ((DEBUG_ERROR, "\n*** ERROR!!!! AllocateZeroPool returned NULL pointer when trying to allocate buffer for 'mPchGpioInitData'!!!! ***\n"));
      ASSERT_EFI_ERROR (EFI_OUT_OF_RESOURCES);
      return Status;
    }
  } else {
    // Point to LPC config values
    mPchGpioInitData = GpioTable;
  }

  DEBUG ((DEBUG_ERROR, "UBA: Start ConfigureGpio().\n"));
  Status = GpioConfigurePads (TableSize/sizeof (GPIO_INIT_CONFIG), mPchGpioInitData);
  DEBUG ((DEBUG_ERROR, "UBA: ConfigureGpio() end.\n"));

  HobPtr = BuildGuidDataHob (
             &gPlatformGpioConfigGuid,
             mPchGpioInitData,
             TableSize
             );
  if (HobPtr == NULL) {
    DEBUG ((DEBUG_ERROR, "PlatformInitGpios(): ERROR: BuildGuidDataHob failed!\n"));
    ASSERT (FALSE);
    return EFI_OUT_OF_RESOURCES;
  }

  return Status;
}
