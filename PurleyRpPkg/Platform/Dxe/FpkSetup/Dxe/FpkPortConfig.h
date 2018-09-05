/**
  This file contains an 'Intel Peripheral Driver' and is
  licensed for Intel CPUs and chipsets under the terms of your
  license agreement with Intel or your vendor.  This file may
  be modified by the user, subject to additional terms of the
  license agreement
**/
/**

Copyright (c) 2016, Intel Corporation. All rights reserved
This software and associated documentation (if any) is furnished
under a license and may only be used or copied in accordance
with the terms of the license. Except as permitted by such
license, no part of this software or documentation may be
reproduced, stored in a retrieval system, or transmitted in any
form or by any means without the express written consent of
Intel Corporation.

**/

#ifndef _FPKSETUP_FPKPORTCONFIG_H
#define _FPKSETUP_FPKPORTCONFIG_H

/**
  Checks if PortConfig disables all functions.

  @param[in]  PortConfig  PortConfig array.

  @retval     TRUE        PortConfig array disables all functions.
  @retval     FALSE       PortConfig array enables one (or more) function(s).

**/
BOOLEAN
FpkDoesPortConfigDisableAllFunctions (
  IN UINT8 *PortConfig
  );

/**
  Checks if PortConfig enables all functions and ports.

  @param[in]  PortConfig  PortConfig array.

  @retval     TRUE        PortConfig array enables all functions and ports.
  @retval     FALSE       PortConfig array disables one (or more) function(s) or port(s).

**/
BOOLEAN
FpkDoesPortConfigEnableAllFunctionsAndPorts (
  IN UINT8 *PortConfig
  );

/**
  Checks if PortConfig disables any function or port.

  @param[in]  PortConfig  PortConfig array.

  @retval     TRUE        PortConfig array disables one (or more) function(s) or port(s).
  @retval     FALSE       PortConfig array enables all functions and ports.

**/
BOOLEAN
FpkDoesPortConfigDisableAnyFunctionOrPort (
  IN UINT8 *PortConfig
  );

/**
  Checks if two port configurations are equal.

  @param[in]  PortConfig1  PortConfig array.
  @param[in]  PortConfig2  PortConfig array.

  @retval     TRUE         PortConfig1 is equal to PortConfig2.
  @retval     FALSE        PortConfig1 and PortConfig2 are different.

**/
BOOLEAN
FpkArePortConfigsEqual (
  IN UINT8 *PortConfig1,
  IN UINT8 *PortConfig2
  );

/**
  Copies one port configuration to another.

  @param[in]   PortConfigSrc  Source port configuration.
  @param[out]  PortConfigDst  Destination port configuration.

**/
VOID
FpkPortConfigCopy (
  IN  UINT8 *PortConfigSrc,
  OUT UINT8 *PortConfigDst
  );

/**
  Converts PortConfig array to ND EFI driver's EFI_ADAPTER_INFO_FPK_FUNC_DISABLE struct.

  @param[in]   PortConfig  PortConfig array.
  @param[out]  FpkFuncDis  Pointer to EFI_ADAPTER_INFO_FPK_FUNC_DISABLE struct.

**/
VOID
FpkConvertPortConfigToFpkFuncDis (
  IN  UINT8                             *PortConfig,
  OUT EFI_ADAPTER_INFO_FPK_FUNC_DISABLE *FpkFuncDis
  );

/**
  Checks if two EFI_ADAPTER_INFO_FPK_FUNC_DISABLE structs are equal.

  @param[in]  FpkFuncDis1  Pointer to EFI_ADAPTER_INFO_FPK_FUNC_DISABLE struct.
  @param[in]  FpkFuncDis2  Pointer to EFI_ADAPTER_INFO_FPK_FUNC_DISABLE struct.

  @retval     TRUE         Structs pointed by FpkFuncDis1 and FpkFuncDis2 are equal.
  @retval     FALSE        Structs pointed by FpkFuncDis1 and FpkFuncDis2 are different.

*/
BOOLEAN
FpkAreFuncDisEqual (
  IN EFI_ADAPTER_INFO_FPK_FUNC_DISABLE *FpkFuncDis1,
  IN EFI_ADAPTER_INFO_FPK_FUNC_DISABLE *FpkFuncDis2
  );

/**
  Checks if given port is mapped (present on board).

  @param  PortNumber  Port number (0-3).

  @retval TRUE        Port is mapped (present on board).
  @retval FALSE       Port is not mapped (not present on board).

*/
BOOLEAN
FpkIsPortMapped (
  UINT8 PortNumber
  );

/**
  Stores pointer to platform's FPK port-to-function map in module variable for internal use.

  This function must be called before calling either of following functions:
  - FpkDoesPortConfigDisableAllFunctions
  - FpkDoesPortConfigEnableAllFunctionsAndPorts
  - FpkDoesPortConfigDisableAnyFunctionOrPort
  - FpkConvertPortConfigToFpkFuncDis
  - FpkIsPortMapped

  @param[in]  PlatformFpkPortToFuncMapPtr      PLATFORM_FPK_PORT_MAP array.
  @param      PlatformFpkPortToFuncMapEntries  Number of entries in array pointed
                                               by PlatformFpkPortToFuncMapPtr.

**/
VOID
FpkSetPortToFuncMap (
  IN PLATFORM_FPK_PORT_MAP *PlatformFpkPortToFuncMapPtr,
     UINT8                 PlatformFpkPortToFuncMapEntries
  );

#endif // !_FPKSETUP_FPKPORTCONFIG_H