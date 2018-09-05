//
// This file contains an 'Intel Peripheral Driver' and is      
// licensed for Intel CPUs and chipsets under the terms of your
// license agreement with Intel or your vendor.  This file may 
// be modified by the user, subject to additional terms of the 
// license agreement                                           
//
/*++

Copyright (c)  2016 Intel Corporation. All rights reserved
This software and associated documentation (if any) is furnished
under a license and may only be used or copied in accordance
with the terms of the license. Except as permitted by such
license, no part of this software or documentation may be
reproduced, stored in a retrieval system, or transmitted in any
form or by any means without the express written consent of
Intel Corporation.


Module Name:

  IioInitPeiLib.h

Abstract:

  This file provides required function headers publish for IioInitLib

--*/

#ifndef _IIO_INIT_PEI_LIB_H_
#define _IIO_INIT_PEI_LIB_H_

IIO_STATUS
IioDmiTcVcSetup (
  IN  IIO_GLOBALS         *IioGlobalData
  );

VOID
IioDmiTcVcProg (
  IN  IIO_GLOBALS *IioGlobalData
  );

VOID
IioDmiTcVcPoll (
  IN IIO_GLOBALS         *IioGlobalData
  );

VOID
IioDmiGen3Prog (
  IN  IIO_GLOBALS *IioGlobalData
  );

VOID
IioDmiGen2Prog (
  IN  IIO_GLOBALS *IioGlobalData
  );

#endif // _IIO_INIT_LIB_PEI_H_