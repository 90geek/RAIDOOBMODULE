/** @file
  The PEI Library Implements ActiveManagement Support.

@copyright
  Copyright (c) 2014 - 2016 Intel Corporation. All rights reserved
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

#include <PiPei.h>
#include <Library/DebugLib.h>
#include <Library/PeiServicesLib.h>
#include <Ppi/AmtPolicyPpi.h>
#include <Library/PeiAmtLib.h>
#include "PeiAlertStandardFormat.h"

/**
  Check some AMT policies are valid for debugging unexpected problem if these 
  values are not initialized or assigned incorrect resource.

**/
VOID
AmtValidatePolicy (
  VOID
  )
{
}

