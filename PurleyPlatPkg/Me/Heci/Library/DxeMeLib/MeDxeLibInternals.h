/** @file
  Header file for functions to get Intel ME information

@copyright
  Copyright (c) 2006 - 2016 Intel Corporation. All rights reserved
  This software and associated documentation (if any) is furnished
  under a license and may only be used or copied in accordance
  with the terms of the license. Except as permitted by the
  license, no part of this software or documentation may be
  reproduced, stored in a retrieval system, or transmitted in any
  form or by any means without the express written consent of
  Intel Corporation.
  This file contains an 'Intel Peripheral Driver' and is uniquely
  identified as "Intel Reference Module" and is licensed for Intel
  CPUs and chipsets under the terms of your license agreement with
  Intel or your vendor. This file may be modified by the user, subject
  to additional terms of the license agreement.

@par Specification Reference:
**/
#ifndef _ME_DXE_LIB_INTERNALS_H_
#define _ME_DXE_LIB_INTERNALS_H_

#include <PiDxe.h>
#include <Library/IoLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PerformanceLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Guid/StatusCodeDataTypeId.h>
#include <Library/TimerLib.h>
#define EVENT_REC_TOK                   "EventRec"

#include <Protocol/Wdt.h>
#include <Protocol/PchReset.h>
#include <Library/DxeMeLib.h>
#include <Library/MmPciBaseLib.h>
#include <Library/PchInfoLib.h>
#include <MeChipset.h>
#include <HeciRegs.h>

#endif
