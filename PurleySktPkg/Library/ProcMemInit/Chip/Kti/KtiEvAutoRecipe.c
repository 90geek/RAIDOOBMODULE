/*++
  This file contains 'Framework Code' and is licensed as such
  under the terms of your license agreement with Intel or your
  vendor.  This file may not be modified, except as allowed by
  additional terms of your license agreement.
--*/
/*++
// **************************************************************************
// *                                                                        *
// *      Intel Restricted Secret                                           *
// *                                                                        *
// *      KTI Reference Code                                                *
// *                                                                        *
// *      ESS - Enterprise Silicon Software                                 *
// *                                                                        *
// *      Copyright (c) 2013 - 2016 Intel Corp.                             *
// *                                                                        *
// *      This program has been developed by Intel Corporation.             *
// *      Licensee has Intel's permission to incorporate this source code   *
// *      into their product, royalty free.  This source code may NOT be    *
// *      redistributed to anyone without Intel's written permission.       *
// *                                                                        *
// *      Intel specifically disclaims all warranties, express or           *
// *      implied, and all liability, including consequential and other     *
// *      indirect damages, for the use of this code, including liability   *
// *      for infringement of any proprietary rights, and including the     *
// *      warranties of merchantability and fitness for a particular        *
// *      purpose.  Intel does not assume any responsibility for any        *
// *      errors which may appear in this code nor any responsibility to    *
// *      update it.                                                        *
// *                                                                        *
// **************************************************************************
// **************************************************************************
// *                                                                        *
// *  PURPOSE: Conatins the logic for automated uniPhy recipe programming   *
// *                                                                        *
// *                                                                        *
// **************************************************************************
--*/

#include "DataTypes.h"
#include "PlatformHost.h"
#include "SysHost.h"
#include "SysFunc.h"
#include "KtiLib.h"
#include "KtiMisc.h"
#include "EvAutoRecipe.h"
#include "SysHostChip.h"


// Contains the declaration for table KtiEvRecipeTablePtr
// This file is generated by running the script on given XLS file
#include "KtiEvRecipeTable_SKX.h"

/**

  Check if the CPU type in EV recipe row is valid.

  @param host              - Pointer to the system host (root) structure
  @param ProcessorTypeMask - Supported processor type bitmask from EV recipe row

  @retval TRUE/FALSE

**/
STATIC
BOOLEAN
IsValidCpuType (
  struct sysHost *host,
  UINT64         ProcessorTypeMask
  )
{
    UINT8 curCpuType = host->var.common.cpuType;

    //
    // Note: We don't have a wild card for cpuType in the automation
    //
    if (curCpuType == CPU_SKX && ProcessorTypeMask == SKX_SOCKET) {
      return TRUE;
    } else {
      return FALSE;
    }
}

/**

  Check if the CPU SKU in EV recipe row is valid.

  @param host        - Pointer to the system host (root) structure
  @param SkuTypeMask - Supported processor SKU bitmask from EV recipe row

  @retval TRUE/FALSE

**/
STATIC
BOOLEAN
IsValidSkuType (
  struct sysHost *host,
  UINT16         SkuTypeMask
  )
{
  //
  //  Note: currently there is only one SKX SKU - SP, thus there is no
  //  host structure variable to check SKU against. This function
  //  will always return TRUE for now, until (if at all) the SKU
  //  concept comes back, in which case the code will be updated.
  //
  return TRUE;
}

/**

  Check if the CPU stepping in EV recipe row is valid.

  @param host         - Pointer to the system host (root) structure
  @param SteppingMask - Supported processor stepping bitmask from EV recipe row

  @retval TRUE/FALSE

**/
STATIC
BOOLEAN
IsValidStepping (
  struct sysHost *host,
  UINT64         SteppingMask
  )
{
  UINT8 curStepping = host->var.common.stepping;  // stepping is based on the lowest nibble resulting from CPUID execution
  BOOLEAN Result = FALSE;

  if (SteppingMask & (UINT64)(1 << curStepping)) { 
    Result = TRUE;
  }


  return Result;
}

/**

  Check if the Socket ID in EV recipe row is valid.

  @param SocId          - Socket ID being programmed
  @param SocketListMask - Socket ID bitmask from EV recipe row

  @retval TRUE/FALSE

**/
STATIC
BOOLEAN
IsValidSocket (
  UINT8  SocId,
  UINT32 SocketListMask
  )
{
    if (SocketListMask == WILDCARD_32) {
      //
      // When mask is 0xFFFF_FFFF, return TRUE irrespective of current CPU
      //
      return TRUE;
    }

    if (SocketListMask & (1 << SocId)) {
      return TRUE;
    } else {
      return FALSE;
    }
}

/**

  Check if the KTI Port index in EV recipe row is valid.

  @param PortId       - Index of the KTI port being programmed
  @param PortListMask - KTI port bitmask from EV recipe row

  @retval TRUE/FALSE

**/
STATIC
BOOLEAN
IsValidPort (
  UINT8  PortId,
  UINT32 PortListMask
  )
{
    if (PortListMask == WILDCARD_32) {
      //
      // When mask is 0xFFFF_FFFF, return TRUE irrespective of current CPU
      //
      return TRUE;
    }

    if (PortListMask & (1 << PortId)) {
      return TRUE;
    } else {
      return FALSE;
    }
}

/**

  Apply UniPhy recipe overrides, if necessary.

  @param host - Pointer to the system host (root) structure
  @param Soc  - Socket ID being programmed
  @param Link - KTI port being programmed
  @param Type - Register access type
  @param Addr - Register address
  @param Mask - Register bitfield mask
  @param Data - Value to program into the register

  @retval TRUE  - Register override successfully performed
  @retval FALSE - No need to override the register/override failed

**/
STATIC
BOOLEAN
OverrideUniphyValues (
  struct sysHost *host,
  UINT8          Soc,
  UINT8          Link,
  UINT8          Type,
  UINT32         Addr,
  UINT32         Mask,
  UINT32         *Data
  )
{
  return FALSE;
}

/**
  Check if the Config index in EV recipe row is valid.
  Current supported configs are KTI_CFG, FPGA_CFG, and WILDCARD_16
  
  @param host       - Pointer to the system host (root) structure
  @param Socket     - Socket ID of register to be programmed
  @param PortId       - Index of the KTI port being programmed
  @param Config     - Config value from KTI EV recipe (WILDCARD_16, KTI_CFG, or FPGA_CFG)
  
  @retval TRUE/FALSE
**/
STATIC 
BOOLEAN 
IsValidConfig ( 
  struct sysHost *host, 
  UINT8  Socket,
  UINT8  PortId,
  UINT16 Config 
  ) 
{ 
  if (Config == WILDCARD_16) {
    //Always program WILDCARD_16 configs
    return TRUE;
  } else if (Config == (1 << KTI_CFG)) {
    //If the part is NON-FPGA, recognize KTI_CFG
    if (host->var.kti.OutKtiFpgaPresent[Socket] == 0) {
      return TRUE;
    //If the part is FPGA && not the LINK connect to FPGA, recognize KTI_CFG
    } else if (PortId != XEON_FPGA_PORT) {
      return TRUE;
    }
  } else if (Config == (1 << FPGA_CFG)) {
    //If the part is an FPGA SKU, recognize FPGA_CFG
    if (host->var.kti.OutKtiFpgaPresent[Socket] == 1 && PortId == XEON_FPGA_PORT) {
      return TRUE;
    }
  }

  //unrecognized config 
  return FALSE; 
}

/**

  This function loops through each entry in the KtiEvRecipeTablePtr of KtiEvAutoRecipeEntry.h file
  and updates the registers based on processor type, subtype, bitrates and stepping conditions.
  This function is called for all valid ports of all valid sockets.

  @param host      - Pointer to the system host (root) structure
  @param Socket    - SocId we are looking up
  @param LinkIndex - Link# on socket

  @retval Status - return KTI_SUCCESS on successful programming

**/
KTI_STATUS
KtiEvAutoRecipe (
  struct sysHost      *host,
  UINT8               Socket,
  UINT8               LinkIndex
  )
{
  UINT32      RegAddr32, Data = 0, OverriddenData = 0;
  UINT8       Bus, PortDevice, Function, UnitId, LinkIndexForLbc;
  UINT16      Offset;
  UINT8       WinSubType, WinRegAddr;
  UINT32      TableIndex, NumEntries;
  BOOLEAN     CpuTypeCmp, SkuTypeCmp, SteppingCmp, SocketTypeCmp, PortTypeCmp, LinkSpeedCmp, ConfigTypeCmp;
  BOOLEAN     PrintDebug = FALSE;
  UINT32      LinkSpeed;
  UINT32      KtiEvRecipeTableSize = 0;
  CHAR        TmpArea[HELP_STR_CHARS + 1];
  UINT64_STRUCT          RetCode;
  UINT32                 VcuCmd32;
  UINT32                 VcuData32;
  VCU_API_DATA_FIELD     VcuApiField;

  EV_RECIPE_HEADER *KtiEvHdrTablePtr = NULL;
  EV_RECIPE_ENTRY  *KtiEvRecipeTablePtr = NULL;

  //
  // Point to the right EV Recipe Table
  //
  if (host->var.common.cpuType == CPU_SKX) {
    KtiEvHdrTablePtr = (EV_RECIPE_HEADER*) &KtiEvHdrTable_SKX;
    KtiEvRecipeTablePtr = (EV_RECIPE_ENTRY*) &KtiEvRecipeTable_SKX;
    KtiEvRecipeTableSize = sizeof(KtiEvRecipeTable_SKX);
  } else {
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Automated uniphy EV recipe not supported for CPUs other SKX"));
    KTI_ASSERT (FALSE, ERR_SW_CHECK, MINOR_ERR_SW_CHECK_4);
  }

  //
  // Verify the signature, before parsing the EVRecipe entries
  //
  if (KtiEvHdrTablePtr->Signature != EV_AUTO_RECIPE_SIGNATURE) {
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Invalid or incorrect signature found. Aborting UniPhy programming ."));
    KTI_ASSERT (FALSE, ERR_SW_CHECK, MINOR_ERR_SW_CHECK_5);
  }

  PrintDebug = (KtiEvHdrTablePtr->DebugMode == 0) ? FALSE : TRUE;

  //
  // Dump the EV header contents, if debug is enabled
  //
  if (PrintDebug == TRUE) {
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  ---- EV Header Dump <start> ----"));
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Signature : 0x%08X", KtiEvHdrTablePtr->Signature));

    //
    // Copy to a local buffer with max limit control before printing
    //
    MemSetLocal((UINT8*) TmpArea, 0, HELP_STR_CHARS + 1);
    MemCopy((UINT8*)TmpArea, (UINT8*)KtiEvHdrTablePtr->Revision, REV_STR_CHARS);
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Uniphy Version : %s", TmpArea));
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Entries count : %d", KtiEvHdrTablePtr->NumberEntries));

    //
    // Copy to a local buffer with max limit control before printing
    //
    MemSetLocal((UINT8*) TmpArea, 0, HELP_STR_CHARS + 1);
    MemCopy( (UINT8*)TmpArea, (UINT8*)KtiEvHdrTablePtr->HelperString, HELP_STR_CHARS);
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Info : %s", TmpArea));
    KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  ---- EV Header Dump <end> ----"));
  }

  //
  // Get the bus number for uncore bus
  //
  Bus = host->var.common.StackBus[Socket][IIO_PSTACK2];

  //
  // Loop though all the recipe entries in KtiEvRecipeTablePtr and apply the recipe if applicable
  //
  NumEntries = KtiEvRecipeTableSize/sizeof (EV_RECIPE_ENTRY);

  for (TableIndex = 0; TableIndex < NumEntries; TableIndex++) {
    if (PrintDebug == TRUE) {
      KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Fetching EV Recipe Entry at index %d    [OK]", TableIndex));
    } // Print Debug

    //
    // Skip register access when BDF is 3:15:3
    //
    Function = (KtiEvRecipeTablePtr[TableIndex].RegisterAddress >> 12) & 0x7;
    Offset   = (KtiEvRecipeTablePtr[TableIndex].RegisterAddress) & 0xfff;

    //
    // Mapping between the port and device number
    //
    PortDevice = LinkIndex + 14;

    //
    // If we're hitting 15:3 it means we're on port 1
    //
    if((PortDevice == 15) && (Function == 3)) {
      //
      // If port 0 is valid on this socket, this shared register is programmed
      // when the recipe is programmed on port 0, otherwise we need to program
      // the shared register on device 14
      //
      if (host->var.kti.CpuInfo[Socket].LepInfo[0].Valid == TRUE) {
        continue;
      } else {
        PortDevice = 14;
      }
    }

    //
    // Verify if the Processor Type, SubType (SKU) and Stepping match with the EV Recipe Entry
    //
    CpuTypeCmp    = IsValidCpuType (host, KtiEvRecipeTablePtr[TableIndex].ProcessorType);
    SkuTypeCmp    = IsValidSkuType (host, KtiEvRecipeTablePtr[TableIndex].Skus);
    SteppingCmp   = IsValidStepping (host, KtiEvRecipeTablePtr[TableIndex].Steppings);
    SocketTypeCmp = IsValidSocket (Socket, KtiEvRecipeTablePtr[TableIndex].SocBitmap);
    PortTypeCmp   = IsValidPort (LinkIndex, KtiEvRecipeTablePtr[TableIndex].PortBitmap);
    ConfigTypeCmp = IsValidConfig (host, Socket, LinkIndex, KtiEvRecipeTablePtr[TableIndex].Config);

    //
    // Verify the link speed
    //
    LinkSpeedCmp = FALSE;
    LinkSpeed = host->var.kti.OutPerLinkSpeed[Socket][LinkIndex];

    if (KtiEvRecipeTablePtr[TableIndex].BitRates != WILDCARD_32) {
      if ((1 << LinkSpeed) & KtiEvRecipeTablePtr[TableIndex].BitRates){
         LinkSpeedCmp = TRUE;
      }
    } else {
      LinkSpeedCmp = TRUE;
    } // BitRates test

    //
    // Print verbose info on reason for this entry to be applied or not
    //
    if (PrintDebug == TRUE) {
      KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  TableIndex %d : CpuTypeCmp=%d, SkuTypeCmp=%d, SteppingCmp=%d, LinkSpeedCmp=%d, SocketTypeCmp=%d, PortTypeCmp=%d, ConfigTypeCmp=%d",
                                TableIndex, CpuTypeCmp, SkuTypeCmp, SteppingCmp, LinkSpeedCmp, SocketTypeCmp, PortTypeCmp, ConfigTypeCmp));
    }

    //
    // Process the EV Recipe Entry only when its cpu type and stepping match the current processor's type and stepping
    //
    if (CpuTypeCmp && SkuTypeCmp && SteppingCmp && LinkSpeedCmp && SocketTypeCmp && PortTypeCmp && ConfigTypeCmp) {

      //
      // Check if this is CSR and IAR access. Program based on the type of access
      //
      if (KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_CSR) {

        //
        // Compute the register address
        //
#ifdef    SEGMENT_ACCESS
        RegAddr32 = (host->var.common.mmCfgBaseL[Socket] | PCIE_REG_ADDR (Bus, PortDevice, Function, Offset));
#else
        RegAddr32 = (host->var.common.mmCfgBase | PCIE_REG_ADDR (Bus, PortDevice, Function, Offset));
#endif

        //
        // Fetch the register value
        //
        //
        // Check register size and read data
        //
        switch (KtiEvRecipeTablePtr[TableIndex].RegisterSize) {
          case sizeof (UINT32):
            Data = *(volatile UINT32 *) RegAddr32;
            break;
          case sizeof (UINT16):
            Data = *(volatile UINT16 *) RegAddr32;
            break;
          case sizeof (UINT8):
            Data = *(volatile UINT8 *) RegAddr32;
            break;
          default:
            FatalError (host, ERR_INVALID_REG_ACCESS, ERR_INVALID_READ_REG_SIZE);
            break;
        } // switch case
        if (PrintDebug == TRUE) {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  CSR Read access for TableIndex=%d, RegAddr32=0x%08X, Data=0x%08X.\n", TableIndex, RegAddr32, Data));
        } // Print Debug

        // Update the data with the values from the EV Recipe
        Data = ((Data & KtiEvRecipeTablePtr[TableIndex].FieldMask) | KtiEvRecipeTablePtr[TableIndex].Data);

        // Write the data
        switch (KtiEvRecipeTablePtr[TableIndex].RegisterSize) {
          case sizeof (UINT32):
            *(volatile UINT32 *) RegAddr32 = Data;
            break;

          case sizeof (UINT16):
            *(volatile UINT16 *) RegAddr32 = (UINT16) Data;
            break;

          case sizeof (UINT8):
            *(volatile UINT8 *) RegAddr32 = (UINT8) Data;
            break;

          default:
            FatalError (host, ERR_INVALID_REG_ACCESS, ERR_INVALID_WRITE_REG_SIZE);
            break;
        } // switch case

        if (PrintDebug == TRUE) {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  CSR Write access for TableIndex=%d, RegAddr32=0x%08X, Data=0x%08X.\n", TableIndex, RegAddr32, Data));
        } // Print Debug
      } else if (KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_KTI_IAR) {

        RegAddr32 = KtiEvRecipeTablePtr[TableIndex].RegisterAddress;
        WinSubType = WINDOW1_ACCESS_SUB_TYPE (RegAddr32);
        WinRegAddr = WINDOW1_ACCESS_REG_ADDR (RegAddr32);

        if (WinSubType == WINDOW1_IAR_IOVB_BCAST) {
          //
          // For IOVB broadcast, can read any lane as an intial value to modify, so read lane 0
          // After cold reset, all lanes should have the same values
          //
          Data = KtiReadIar (host, Socket, LinkIndex, 0, WinRegAddr);

          if (PrintDebug == TRUE) {
            KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  IAR Read Access for TableIndex=%d, RegAddr32=0x%08X, WinSubType=0x%02X, WinRegAddr=0x%02X, Data=0x%02X\n", TableIndex, RegAddr32, WinSubType, WinRegAddr, Data));
          } // Print Debug

          //
          // Update the data with the values from the EV Recipe or overridden values
          //
          if (OverrideUniphyValues (host, Socket, LinkIndex, KtiEvRecipeTablePtr[TableIndex].AccessType, RegAddr32, KtiEvRecipeTablePtr[TableIndex].FieldMask, &OverriddenData)) {
            if (PrintDebug == TRUE) {
              KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Match with Overrides Table.Applying OverriddenData=0x%08X instead of tabular data.\n", OverriddenData));
            } // Print Debug
            Data = ((Data & KtiEvRecipeTablePtr[TableIndex].FieldMask) | OverriddenData);
          } else {
            Data = ((Data & KtiEvRecipeTablePtr[TableIndex].FieldMask) | KtiEvRecipeTablePtr[TableIndex].Data);
          } // OverrideUniphyValues check

          //
          // Write the IOVB registers back
          //
          KtiWriteIar (host, Socket, LinkIndex, KTILIB_IAR_BCAST, WinRegAddr, (UINT8)Data);

          if (PrintDebug == TRUE) {
            KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  IAR Write Access for TableIndex=%d, RegAddr32=0x%08X, WinSubType=0x%02X, WinRegAddr=0x%02X, Data=0x%02X\n", TableIndex, RegAddr32, WinSubType, WinRegAddr, Data));
          } // Print Debug
        } else if (WinSubType == WINDOW1_IAR_IOVB) {
          //
          // Loop through the lane bitmask
          //
          for (UnitId = 0; UnitId < MAX_KTI_LANES; UnitId++) {
            if (KtiEvRecipeTablePtr[TableIndex].LaneBitmap & (1 << UnitId)) {
              //
              // Read the IOVB registers first into Data
              //
              Data = KtiReadIar (host, Socket, LinkIndex, UnitId, WinRegAddr);

              if (PrintDebug == TRUE) {
                KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  IAR Read Access for TableIndex=%d, RegAddr32=0x%08X, WinSubType=0x%02X, WinRegAddr=0x%02X, Data=0x%02X\n", TableIndex, RegAddr32, WinSubType, WinRegAddr, Data));
              } // Print Debug

              //
              // Update the data with the values from the EV Recipe or overridden values
              //
              if (OverrideUniphyValues (host, Socket, LinkIndex, KtiEvRecipeTablePtr[TableIndex].AccessType, RegAddr32, KtiEvRecipeTablePtr[TableIndex].FieldMask, &OverriddenData)) {
                if (PrintDebug == TRUE) {
                  KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Match with Overrides Table.Applying OverriddenData=0x%08X instead of tabular data.\n", OverriddenData));
                } // Print Debug
                Data = ((Data & KtiEvRecipeTablePtr[TableIndex].FieldMask) | OverriddenData);
              } else {
                Data = ((Data & KtiEvRecipeTablePtr[TableIndex].FieldMask) | KtiEvRecipeTablePtr[TableIndex].Data);
              } // OverrideUniphyValues check

              //
              // Write the IOVB registers back
              //
              KtiWriteIar (host, Socket, LinkIndex, UnitId, WinRegAddr, (UINT8)Data);

              if (PrintDebug == TRUE) {
                KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  IAR Write Access for TableIndex=%d, RegAddr32=0x%08X, WinSubType=0x%02X, WinRegAddr=0x%02X, Data=0x%02X\n", TableIndex, RegAddr32, WinSubType, WinRegAddr, Data));
              } // Print Debug
            } // Valid UnitId
          } // For UnitId
        } else {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Aborting. Don\'t know to apply EVEntry at TableIndex=%d, sub-type=%u, Unknown sub-type.", TableIndex, WinSubType));
          FatalError(host, ERR_INVALID_REG_ACCESS, ERR_UNKNOWN_REG_TYPE);
        } // WinSubType check
      } else if (KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_LBC_AFE || KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_LBC_COM) {

        //
        // LBC COM is shared between ports; ports 0 and 1 use instance 0, port 2 uses instance 2; instance 1 is invalid
        //
        if (KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_LBC_COM && LinkIndex == 1) {
          //
          // If port 0 is valid on this socket, there is no need to program again since KTI Misc is shared
          //
          if (host->var.kti.CpuInfo[Socket].LepInfo[0].Valid == TRUE) {
            continue;
          } else {
            LinkIndexForLbc = 0;
          }
        } else {
          LinkIndexForLbc = LinkIndex;
        }

        //
        // Perform a blind LBC write
        //
        KtiWriteLbc (host,
                     Socket,
                     LinkIndexForLbc,
                     KtiEvRecipeTablePtr[TableIndex].AccessType,
                     KtiEvRecipeTablePtr[TableIndex].LaneBitmap,
                     KtiEvRecipeTablePtr[TableIndex].RegisterAddress,
                     KtiEvRecipeTablePtr[TableIndex].Data
                     );
      } else if (((host->var.common.cpuType == CPU_SKX) && (host->var.common.stepping < B0_REV_SKX)) &&
                 (KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_LBC_COM_VCU)) {
        KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  TYPE_LBC_COM_VCU is not supported!!!\n\r"));

      } else if (((host->var.common.cpuType == CPU_SKX) && (host->var.common.stepping < B0_REV_SKX)) &&
                 (KtiEvRecipeTablePtr[TableIndex].AccessType == TYPE_CSR_VCU)) {
        if (host->var.common.emulation & SIMICS_FLAG) {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  TYPE_CSR_VCU is not supported in Simics!!!\n\r"));
          continue;
        }
        //
        // OPEN SEQUENCE for READ
        //
        VcuCmd32 =  VCODE_API_OPCODE_OPEN_SEQUENCE;
        VcuData32 = VCODE_API_SEQ_ID_READ_LOCAL_CSR;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);
        KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n OPEN SEQUENCE for READ_RetCode=%x %x\n", RetCode.hi, RetCode.lo));
        if (RetCode.lo != VCODE_MAILBOX_CC_SUCCESS)  {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RetCode error=%x\n", RetCode.lo));
        }

        //
        // READ LOCAL CSR
        //
        KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RegisterSize=%x\n", KtiEvRecipeTablePtr[TableIndex].RegisterSize));
        VcuApiField.Bits.Bus      = (KtiEvRecipeTablePtr[TableIndex].RegisterAddress >> 20) & 0x7;
        VcuApiField.Bits.Device   = (KtiEvRecipeTablePtr[TableIndex].RegisterAddress >> 15) & 0x1F;
        VcuApiField.Bits.Function = Function;
        VcuApiField.Bits.Offset   = Offset;

        switch (KtiEvRecipeTablePtr[TableIndex].RegisterSize) {
          case sizeof (UINT64):
            VcuApiField.Bits.LengthCode = 3;
            break;
          case sizeof (UINT32):
            VcuApiField.Bits.LengthCode = 2;
            break;
          case sizeof (UINT16):
            VcuApiField.Bits.LengthCode = 1;
            break;
          case sizeof (UINT8):
            VcuApiField.Bits.LengthCode = 0;
            break;
          default:
            FatalError (host, ERR_INVALID_REG_ACCESS, ERR_INVALID_READ_REG_SIZE);
            break;
        }


        VcuCmd32 =  VCODE_API_OPCODE_READ_LOCAL_CSR;
        VcuData32 = VcuApiField.Data;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);

        if (RetCode.lo != VCODE_MAILBOX_CC_SUCCESS)  {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RetCode error=%x\n", RetCode.lo));
        }

        //
        // READ CSR DATA
        //
        VcuCmd32 =  VCODE_API_OPCODE_READ_DATA;
        VcuData32 = 0;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);
        if (RetCode.lo != VCODE_MAILBOX_CC_SUCCESS)  {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RetCode error=%x\n", RetCode.lo));
        }

        Data = RetCode.hi;
        Data = ((Data & KtiEvRecipeTablePtr[TableIndex].FieldMask) | KtiEvRecipeTablePtr[TableIndex].Data);

        //
        // CLOSE SEQUENCE
        //
        VcuCmd32 =  VCODE_API_OPCODE_CLOSE_SEQUENCE;
        VcuData32 = VCODE_API_SEQ_ID_READ_LOCAL_CSR;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);

        //
        // OPEN SEQUENCE for WRITE
        //
        VcuCmd32 =  VCODE_API_OPCODE_OPEN_SEQUENCE;
        VcuData32 = VCODE_API_SEQ_ID_WRITE_LOCAL_CSR;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);
        if (RetCode.lo != VCODE_MAILBOX_CC_SUCCESS)  {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RetCode error=%x\n", RetCode.lo));
        }

        //
        // WRITE LOCAL CSR
        //
        VcuCmd32 =  VCODE_API_OPCODE_WRITE_LOCAL_CSR;
        VcuData32 = VcuApiField.Data;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);
        if (RetCode.lo != VCODE_MAILBOX_CC_SUCCESS)  {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RetCode error=%x\n", RetCode.lo));
        }

        //
        // WRITE CSR DATA
        //
        VcuCmd32 =  VCODE_API_OPCODE_WRITE_DATA;
        VcuData32 = Data;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);

        if (RetCode.lo != VCODE_MAILBOX_CC_SUCCESS)  {
          KtiDebugPrintInfo1((host, KTI_DEBUG_INFO0, "\n RetCode error=%x\n", RetCode.lo));
        }

        //
        // CLOSE SEQUENCE
        //
        VcuCmd32 =  VCODE_API_OPCODE_CLOSE_SEQUENCE;
        VcuData32 = VCODE_API_SEQ_ID_WRITE_LOCAL_CSR;
        RetCode = WriteBios2VcuMailboxCommand(host, Socket, VcuCmd32, VcuData32);
      } else {
        KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Aborting. Don\'t how know to apply EVEntry at TableIndex=%d, access type=%u, Unknown access type.", TableIndex, KtiEvRecipeTablePtr[TableIndex].AccessType));
        FatalError (host, ERR_INVALID_REG_ACCESS, ERR_INVALID_READ_REG_SIZE);
      } // AccessType checks for CSR, KTI IAR, and LBC

    } else {
     if (PrintDebug == TRUE) {
       KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Not applying. EVRecipe checks failed for EVEntry at TableIndex=%d", TableIndex));
     } // Print Debug
    } // CpuTypeCmp && SkuTypeCmp && SteppingCmp && LinkSpeedCmp checks
  } // for loop

  KtiDebugPrintInfo1((host, KTI_DEBUG_INFO1, "\n  Socket %u Port %u : KTI UniPhy recipe v%s programmed\n", Socket, LinkIndex, KtiEvHdrTablePtr->Revision));
  return KTI_SUCCESS;
}
