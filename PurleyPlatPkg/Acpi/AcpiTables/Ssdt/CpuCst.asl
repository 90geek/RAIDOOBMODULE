//
// This file contains an 'Intel Peripheral Driver' and is      
// licensed for Intel CPUs and chipsets under the terms of your
// license agreement with Intel or your vendor.  This file may 
// be modified by the user, subject to additional terms of the 
// license agreement                                           
//
/*++
  
Copyright 2016, Intel Corporation.

This source code and any documentation accompanying it ("Material") is furnished
under license and may only be used or copied in accordance with the terms of that
license.  No license, express or implied, by estoppel or otherwise, to any
intellectual property rights is granted to you by disclosure or delivery of these
Materials.  The Materials are subject to change without notice and should not be
construed as a commitment by Intel Corporation to market, license, sell or support
any product or technology.  Unless otherwise provided for in the license under which
this Material is provided, the Material is provided AS IS, with no warranties of
any kind, express or implied, including without limitation the implied warranties
of fitness, merchantability, or non-infringement.  Except as expressly permitted by
the license for the Material, neither Intel Corporation nor its suppliers assumes
any responsibility for any errors or inaccuracies that may appear herein.  Except
as expressly permitted by the license for the Material, no part of the Material
may be reproduced, stored in a retrieval system, transmitted in any form, or
distributed by any means without the express written consent of Intel Corporation.

  Module Name:
  
    CpuCst.asl
  
  Abstract:
  
    Contains root level name space objects for Cpu 0..F with HWP (HW P-States) support
  
NOTES:-
 This Processor Power Management BIOS Source Code is furnished under license
 and may only be used or copied in accordance with the terms of the license.
 The information in this document is furnished for informational use only, is
 subject to change without notice, and should not be construed as a commitment
 by Intel Corporation. Intel Corporation assumes no responsibility or liability
 for any errors or inaccuracies that may appear in this document or any
 software that may be provided in association with this document.

 Except as permitted by such license, no part of this document may be
 reproduced, stored in a retrieval system, or transmitted in any form or by
 any means without the express written consent of Intel Corporation.

 WARNING: You are authorized and licensed to install and use this BIOS code
 ONLY on an IST PC. This utility may damage any system that does not
 meet these requirements.

  An IST PC is a computer which
  (1) Is capable of seamlessly and automatically transitioning among
      multiple performance states (potentially operating at different
      efficiency ratings) based upon power source changes, end user
      preference, processor performance demand, and thermal conditions; and
  (2) Includes an Intel Pentium II processors, Intel Pentium III
      processor, Mobile Intel Pentium III Processor-M, Mobile Intel Pentium 4
      Processor-M, Intel Pentium M Processor, or any other future Intel 
      processors that incorporates the capability to transition between 
      different performance states by altering some, or any combination of, 
      the following processor attributes: core voltage, core frequency, bus 
      frequency, number of processor cores available, or any other attribute 
      that changes the efficiency (instructions/unit time-power) at which the 
      processor operates.

--*/

//
// Sync with Library\ProcMemInit\Platform\Include\PlatformHost.h
//
#define  PCH_ACPI_PORT_C3_ADDR                0x514
#define  PCH_ACPI_PORT_C6_ADDR                0x515
#define  PCH_ACPI_PORT_C7_ADDR                0x516

// Note: 
// These tables are static as defined here. But they are patched during
// POST from UpdateTables () function in AcpiPlatformHooks.c  to make 
// them dynamic and reflect the user configuration and capabilities for 
// particular system boot and OS session

DefinitionBlock (
  "CPUCST.aml",     // Output Filename
  "OEM4",           // Signature
  2,                // SSDT Revision
  "INTEL",          // OEMID
  "CPU  CST",       // Table ID
  0x3000            // OEM Revision
  ) {

  External(PETE, IntObj)
  External(TSLM, PkgObj)
  External (HWEN, FieldUnitObj) //HWPM
  External (PSEN, FieldUnitObj)
  External (TSEN, FieldUnitObj)
  External (FGTS, FieldUnitObj)
  External (SCKN, FieldUnitObj)

  #undef   ToName
  #define  ToName(x)  x##00
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##01
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##02
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##03
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##04
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##05
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##06
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##07
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##08
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##09
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##0A
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##0B
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##0C
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##0D
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##0E
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##0F
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##10
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##11
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##12
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##13
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##14
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##15
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##16
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##17
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##18
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##19
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##1A
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##1B
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##1C
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##1D
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##1E
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##1F
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##20
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##21
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##22
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##23
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##24
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##25
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##26
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##27
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##28
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##29
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##2A
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##2B
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##2C
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##2D
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##2E
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##2F
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##30
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##31
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##32
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##33
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##34
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##35
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##36
  #include "ProcCst.asi"

  #undef   ToName
  #define  ToName(x)  x##37
  #include "ProcCst.asi"
 }

