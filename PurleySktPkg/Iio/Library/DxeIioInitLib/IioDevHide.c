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

  IioDevHide.h

Abstract:

  Houses all function definition of IioDevFuncHideTable 

Revision History:

--*/

#include <IioPlatformData.h>

//
// IioDevFuncHideTable is the default definition of the Devices/Functions
// that need to be hidden after Pcie Resources Allocation
// Table defintion is as follows:run
// Column = Funcion0 -7
// Row  = C-Stack, Pstack0-2 and MCP-Stacks 0-1
// Item = Bit 0-31 is related to every Device Number
// So for example Column 0 and Row 0
// 0x00000080 = Hides Dev 7 Func 0 of C-Stack (IIO Dfx)
//
// Here are the list of the DFX devices hide by default. For now it applies to all sockets
//
//---------------------------------------------------------------------------------------------------------------------
// Stack/Function | 0          | 1         |    2       |  3         |  4       |  5      |   6          |  7         |
//---------------------------------------------------------------------------------------------------------------------
// IIO_CSTACK     | 7          | 5         |            |            |7         |         | 7,6          |  7         |
//---------------------------------------------------------------------------------------------------------------------
// IIO_PSTACK0    | 7,20-23,31 |7,20-23,31 | 7,20-23,31 |7,20-23,31  |7,20-22,31|20-22,31 | 7,6,20-22,31 | 20-22,7, 31|
//---------------------------------------------------------------------------------------------------------------------
// IIO_PSTACK1    | 7          | 7,8,9     | 7          | 7          |7         |         |              |            |
//---------------------------------------------------------------------------------------------------------------------
// IIO_PSTACK2    | 7          | 7         | 16,14,7    | 18,21,22,23|7         |         | 18,7,6       |  7,18,22   |
//---------------------------------------------------------------------------------------------------------------------
// IIO_PSTACK3    | 7          |           |            |            |7         |         | 7,6          |  7         |
//---------------------------------------------------------------------------------------------------------------------
// IIO_PSTACK4    | 7          |           |            |            |7         |         | 7,6          |  7         |
//---------------------------------------------------------------------------------------------------------------------

IIO_DEVFUNHIDE_TABLE IioDevFuncHideTable[] = {
  { // socket 0
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // Socket 1
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // Socket 2
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // Socket 3
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // socket 4
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // Socket 5
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // Socket 6
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  },
  { // Socket 7
      //  FUN0       FUNC1       FUNC2       FUNC3        FUNC4       FUNC5       FUNC6        FUNC7
   {{0x00000080, 0x00000020, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_CSTACK
   {0x80F00080, 0x80F00080, 0x80F00080, 0x80F00080, 0x80700080, 0x80700000, 0x807000a0, 0x80700080}, // IIO_PSTACK0
   {0x00000080, 0x00000380, 0x00000080, 0x00000080, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK1
   {0x00000080, 0x00000080, 0x0001c080, 0x00E54080, 0x00000080, 0x00000000, 0x000400a0, 0x00440080}, // IIO_PSTACK2
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}, // IIO_PSTACK3
   {0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000080, 0x00000000, 0x000000a0, 0x00000080}}  // IIO_PSTACK4
  }
};
