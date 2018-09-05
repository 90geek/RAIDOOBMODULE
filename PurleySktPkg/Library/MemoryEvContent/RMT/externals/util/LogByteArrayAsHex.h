/**
  This file contains an 'Intel Peripheral Driver' and uniquely
  identified as "Intel Reference Module" and is
  licensed for Intel CPUs and chipsets under the terms of your
  license agreement with Intel or your vendor.  This file may
  be modified by the user, subject to additional terms of the
  license agreement
**/
/**
@copyright
  Copyright (c) 2014-2015 Intel Corporation. All rights reserved
  This software and associated documentation (if any) is furnished
  under a license and may only be used or copied in accordance
  with the terms of the license. Except as permitted by such
  license, no part of this software or documentation may be
  reproduced, stored in a retrieval system, or transmitted in any
  form or by any means without the express written consent of
  Intel Corporation.

@file
  LogByteArrayAsHex.h

@brief
  This file contains definitions for a function to log the byte arrays.
**/
#ifndef __LOG_BYTE_ARRAY_AS_HEX_H__
#define __LOG_BYTE_ARRAY_AS_HEX_H__

#ifdef SSA_FLAG

#include "ssabios.h"

/**
@brief
  This function logs the given array of bytes from highest to lowest as hex.
  This function does NOT start the log with "0x" or end it with "\n".

  @param[in, out]  SsaServicesHandle  Pointer to SSA services.
  @param[in]       pArray             Pointer to array of bytes to log.
  @param[in]       ByteCount          Number of bytes to log.

  @retval  Nothing.
**/
VOID LogByteArrayAsHex(
  IN OUT SSA_BIOS_SERVICES_PPI *SsaServicesHandle,
  IN CONST UINT8 *pArray,
  IN UINT8 ByteCount);

#endif  // SSA_FLAG
#endif // __LOG_BYTE_ARRAY_AS_HEX_H__

// end file LogByteArrayAsHex.h
