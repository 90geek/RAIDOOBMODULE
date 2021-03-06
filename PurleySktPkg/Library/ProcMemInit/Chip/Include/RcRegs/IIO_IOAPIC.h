//
// This file contains 'Framework Code' and is licensed as such
// under the terms of your license agreement with Intel or your
// vendor.  This file may not be modified, except as allowed by
// additional terms of your license agreement.
//
// **************************************************************************
// *                                                                        *
// *      Intel Restricted Secret                                           *
// *                                                                        *
// *      Reference Code                                                    *
// *                                                                        *
// *      Copyright (c) 2007-2016, Intel Corporation.                       *
// *                                                                        *
// *      This software and associated documentation (if any) is furnished  *
// *      under a license and may only be used or copied in accordance      *
// *      with the terms of the license. Except as permitted by such        *
// *      license, no part of this software or documentation may be         *
// *      reproduced, stored in a retrieval system, or transmitted in any   *
// *      form or by any means without the express written consent of       *
// *      Intel Corporation.                                                *
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
// *  PURPOSE:                                                              *
// *                                                                        *
// *      This file contains Silicon register definitions.                  *
// *                                                                        *
// **************************************************************************
//
/* Date Stamp: 9/13/2016 */

#ifndef IIO_IOAPIC_h
#define IIO_IOAPIC_h

#include "DataTypes.h"

/* Device and Function specifications:                                        */
/* For all target CPUs:                                                       */
/* IIO_IOAPIC_DEV 5                                                           */
/* IIO_IOAPIC_FUN 4                                                           */

/* VID_IIO_IOAPIC_REG supported on:                                           */
/*       SKX_A0 (0x2012C000)                                                  */
/*       SKX (0x2012C000)                                                     */
/* Register default value:              0x8086                                */
#define VID_IIO_IOAPIC_REG 0x11032000
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x000
 */
typedef union {
  struct {
    UINT16 vendor_identification_number : 16;
    /* vendor_identification_number - Bits[15:0], RO, default = 16'b1000000010000110 
       The value is assigned by PCI-SIG to Intel.
     */
  } Bits;
  UINT16 Data;
} VID_IIO_IOAPIC_STRUCT;


/* DID_IIO_IOAPIC_REG supported on:                                           */
/*       SKX_A0 (0x2012C002)                                                  */
/*       SKX (0x2012C002)                                                     */
/* Register default value:              0x2036                                */
#define DID_IIO_IOAPIC_REG 0x11032002
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x002
 */
typedef union {
  struct {
    UINT16 device_identification_number : 16;
    /* device_identification_number - Bits[15:0], RO, default = 16'b0010000000110110 
       //TODO_HSXA0_SYNC
       Device ID values vary from function to function. Bits 15:8 are equal to 0x0E for 
       Ivytown. The following list is a breakdown of the function groups.0x0E00 - 
       0x0E1F : PCI Express and DMI ports 
       0x0E20 - 0x0E3F : IO Features (CBDMA, APIC, VT, RAS, LT)
       0x0E40 - 0x0E5F : Performance Monitors
       0x0E60 - 0x0E7F : DFX
       0x0E80 - 0x0E9F : Quick Path Interface
       0x0EA0 - 0x0EBF : Home Agent/Memory Controller
       0x0EC0 - 0x0EDF : Power Management
       0x0EE0 - 0x0EFF : Cbo/Ring
       //TODO_HSXA0_SYNC
       //SKX:Oct 18 2012: Post HSX sync values should be as below
       Device ID values vary from function to function. Bits 15:8 are equal to 0x2F for 
       the processor. The following list is a breakdown of the function groups. 
       0x2F00 - 0x2F1F : PCI Express and DMI ports
       0x2F20 - 0x2F3F : IO Features (CBDMA, APIC, VT, RAS, Intel TXT)
       0x2F40 - 0x2F5F : Performance Monitors
       0x2F60 - 0x2F7F : DFX
       0x2F80 - 0x2F9F : Intel Quick Path Interface
       0x2FA0 - 0x2FBF : Home Agent/Memory Controller
       0x2FC0 - 0x2FDF : Power Management
       0x2FE0 - 0x2FFF : Cbo/Ring
       
     */
  } Bits;
  UINT16 Data;
} DID_IIO_IOAPIC_STRUCT;


/* PCICMD_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x2012C004)                                                  */
/*       SKX (0x2012C004)                                                     */
/* Register default value:              0x0000                                */
#define PCICMD_IIO_IOAPIC_REG 0x11032004
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x004
 */
typedef union {
  struct {
    UINT16 iose : 1;
    /* iose - Bits[0:0], RO, default = 1'b0 
       1
     */
    UINT16 mse : 1;
    /* mse - Bits[1:1], RW, default = 1'b0 
       1
     */
    UINT16 bme : 1;
    /* bme - Bits[2:2], RW, default = 1'b0 
       1
     */
    UINT16 spcen : 1;
    /* spcen - Bits[3:3], RO, default = 1'b0 
       1
     */
    UINT16 memwrinv : 1;
    /* memwrinv - Bits[4:4], RO, default = 1'b0 
       1
     */
    UINT16 vga : 1;
    /* vga - Bits[5:5], RO, default = 1'b0 
       1
     */
    UINT16 perrrsp : 1;
    /* perrrsp - Bits[6:6], RO, default = 1'b0 
       1
     */
    UINT16 idsel : 1;
    /* idsel - Bits[7:7], RO, default = 1'b0 
       1
     */
    UINT16 serre : 1;
    /* serre - Bits[8:8], RO, default = 1'b0 
       1
     */
    UINT16 fb2be : 1;
    /* fb2be - Bits[9:9], RO, default = 1'b0 
       1
     */
    UINT16 intxdisable : 1;
    /* intxdisable - Bits[10:10], RO, default = 1'b0 
       1
     */
    UINT16 rsvd : 5;
    /* rsvd - Bits[15:11], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT16 Data;
} PCICMD_IIO_IOAPIC_STRUCT;


/* PCISTS_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x2012C006)                                                  */
/*       SKX (0x2012C006)                                                     */
/* Register default value:              0x0010                                */
#define PCISTS_IIO_IOAPIC_REG 0x11032006
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x006
 */
typedef union {
  struct {
    UINT16 rsvd_0 : 3;
    /* rsvd_0 - Bits[2:0], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT16 intxst : 1;
    /* intxst - Bits[3:3], RO, default = 1'b0 
       1
     */
    UINT16 capl : 1;
    /* capl - Bits[4:4], RO, default = 1'b1 
       1
     */
    UINT16 sixtysixmhzcap : 1;
    /* sixtysixmhzcap - Bits[5:5], RO, default = 1'b0 
       1
     */
    UINT16 rsvd_6 : 1;
    /* rsvd_6 - Bits[6:6], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT16 fb2bcap : 1;
    /* fb2bcap - Bits[7:7], RO, default = 1'b0 
       1
     */
    UINT16 medierr : 1;
    /* medierr - Bits[8:8], RO, default = 1'b0 
       1
     */
    UINT16 devselt : 2;
    /* devselt - Bits[10:9], RO, default = 2'b00 
       1
     */
    UINT16 sta : 1;
    /* sta - Bits[11:11], RO, default = 1'b0 
       1
     */
    UINT16 rta : 1;
    /* rta - Bits[12:12], RO, default = 1'b0 
       1
     */
    UINT16 rma : 1;
    /* rma - Bits[13:13], RO, default = 1'b0 
       1
     */
    UINT16 sse : 1;
    /* sse - Bits[14:14], RO, default = 1'b0 
       1
     */
    UINT16 dpe : 1;
    /* dpe - Bits[15:15], RO, default = 1'b0 
       1
     */
  } Bits;
  UINT16 Data;
} PCISTS_IIO_IOAPIC_STRUCT;


/* RID_IIO_IOAPIC_REG supported on:                                           */
/*       SKX_A0 (0x1012C008)                                                  */
/*       SKX (0x1012C008)                                                     */
/* Register default value:              0x00                                  */
#define RID_IIO_IOAPIC_REG 0x11031008
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * Revision ID
 */
typedef union {
  struct {
    UINT8 revision_id : 8;
    /* revision_id - Bits[7:0], RO, default = 8'h0 
       
       	  Revision ID.
       	
     */
  } Bits;
  UINT8 Data;
} RID_IIO_IOAPIC_STRUCT;


/* CCR_N0_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x1012C009)                                                  */
/*       SKX (0x1012C009)                                                     */
/* Register default value:              0x20                                  */
#define CCR_N0_IIO_IOAPIC_REG 0x11031009
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * Class Code Register
 */
typedef union {
  struct {
    UINT8 interface : 8;
    /* interface - Bits[7:0], RO, default = 8'h20 
       
       	  Base revision.
       	
     */
  } Bits;
  UINT8 Data;
} CCR_N0_IIO_IOAPIC_STRUCT;


/* CCR_N1_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x2012C00A)                                                  */
/*       SKX (0x2012C00A)                                                     */
/* Register default value:              0x0800                                */
#define CCR_N1_IIO_IOAPIC_REG 0x1103200A
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * Class Code Register
 */
typedef union {
  struct {
    UINT16 sub_class : 8;
    /* sub_class - Bits[7:0], RO, default = 8'h0 
       
       	  Base revision.
       	
     */
    UINT16 base_class : 8;
    /* base_class - Bits[15:8], RO, default = 8'h8 
       
       	  Base revision.
       	
     */
  } Bits;
  UINT16 Data;
} CCR_N1_IIO_IOAPIC_STRUCT;


/* CLSR_IIO_IOAPIC_REG supported on:                                          */
/*       SKX_A0 (0x1012C00C)                                                  */
/*       SKX (0x1012C00C)                                                     */
/* Register default value:              0x00                                  */
#define CLSR_IIO_IOAPIC_REG 0x1103100C
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x00c
 */
typedef union {
  struct {
    UINT8 clsr : 8;
    /* clsr - Bits[7:0], RW, default = 8'b00000000 
       1
     */
  } Bits;
  UINT8 Data;
} CLSR_IIO_IOAPIC_STRUCT;


/* HDR_IIO_IOAPIC_REG supported on:                                           */
/*       SKX_A0 (0x1012C00E)                                                  */
/*       SKX (0x1012C00E)                                                     */
/* Register default value:              0x80                                  */
#define HDR_IIO_IOAPIC_REG 0x1103100E
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x00e
 */
typedef union {
  struct {
    UINT8 configuration_layout : 7;
    /* configuration_layout - Bits[6:0], RO, default = 7'b0000000 
       This field identifies the format of the configuration header layout. It is Type 
       0 for all these devices. The default is 00h, indicating a 'endpoint device'. 
     */
    UINT8 multi_function_device : 1;
    /* multi_function_device - Bits[7:7], RO, default = 1'b1 
       This bit defaults to 1b since all these devices are multi-function
     */
  } Bits;
  UINT8 Data;
} HDR_IIO_IOAPIC_STRUCT;


/* MBAR_IIO_IOAPIC_REG supported on:                                          */
/*       SKX_A0 (0x4012C010)                                                  */
/*       SKX (0x4012C010)                                                     */
/* Register default value:              0x00000000                            */
#define MBAR_IIO_IOAPIC_REG 0x11034010
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x010
 */
typedef union {
  struct {
    UINT32 memory_space : 1;
    /* memory_space - Bits[0:0], RO, default = 1'b0 
       This Base Address Register indicates memory space.
     */
    UINT32 type : 2;
    /* type - Bits[2:1], RO, default = 2'b00 
       The IOAPIC registers can only be placed below 4G system address space.
     */
    UINT32 prefetchable : 1;
    /* prefetchable - Bits[3:3], RO, default = 1'b0 
       The IOxAPIC registers are not prefetchable.
     */
    UINT32 rsvd : 8;
    /* rsvd - Bits[11:4], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT32 bar : 20;
    /* bar - Bits[31:12], RW, default = 20'b00000000000000000000 
       This marks the 4KB aligned 32-bit base address for memory-mapped registers of 
       I/OxAPICSide 
     */
  } Bits;
  UINT32 Data;
} MBAR_IIO_IOAPIC_STRUCT;


/* SVID_IIO_IOAPIC_REG supported on:                                          */
/*       SKX_A0 (0x2012C02C)                                                  */
/*       SKX (0x2012C02C)                                                     */
/* Register default value:              0x8086                                */
#define SVID_IIO_IOAPIC_REG 0x1103202C
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x02c
 */
typedef union {
  struct {
    UINT16 svid : 16;
    /* svid - Bits[15:0], RW_O, default = 16'b1000000010000110 
       1
     */
  } Bits;
  UINT16 Data;
} SVID_IIO_IOAPIC_STRUCT;


/* SDID_IIO_IOAPIC_REG supported on:                                          */
/*       SKX_A0 (0x2012C02E)                                                  */
/*       SKX (0x2012C02E)                                                     */
/* Register default value:              0x0000                                */
#define SDID_IIO_IOAPIC_REG 0x1103202E
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * This value is used to identify a particular subsystem.
 */
typedef union {
  struct {
    UINT16 sdid : 16;
    /* sdid - Bits[15:0], RW_O, default = 16'b0000000000000000 
       1
     */
  } Bits;
  UINT16 Data;
} SDID_IIO_IOAPIC_STRUCT;


/* CAPPTR_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x1012C034)                                                  */
/*       SKX (0x1012C034)                                                     */
/* Register default value:              0x44                                  */
#define CAPPTR_IIO_IOAPIC_REG 0x11031034
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x034
 */
typedef union {
  struct {
    UINT8 capability_pointer : 8;
    /* capability_pointer - Bits[7:0], RO, default = 8'b01000100 
       Points to the first capability structure for the device which is the PCIe 
       capability. 
     */
  } Bits;
  UINT8 Data;
} CAPPTR_IIO_IOAPIC_STRUCT;


/* INTLIN_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x1012C03C)                                                  */
/*       SKX (0x1012C03C)                                                     */
/* Register default value:              0x00                                  */
#define INTLIN_IIO_IOAPIC_REG 0x1103103C
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x03c
 */
typedef union {
  struct {
    UINT8 intlin_reg : 8;
    /* intlin_reg - Bits[7:0], RO, default = 8'b00000000  */
  } Bits;
  UINT8 Data;
} INTLIN_IIO_IOAPIC_STRUCT;


/* INTPIN_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x1012C03D)                                                  */
/*       SKX (0x1012C03D)                                                     */
/* Register default value:              0x00                                  */
#define INTPIN_IIO_IOAPIC_REG 0x1103103D
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x03d
 */
typedef union {
  struct {
    UINT8 intpin_reg : 8;
    /* intpin_reg - Bits[7:0], RO, default = 8'b00000000 
       1
     */
  } Bits;
  UINT8 Data;
} INTPIN_IIO_IOAPIC_STRUCT;


/* ABAR_IIO_IOAPIC_REG supported on:                                          */
/*       SKX_A0 (0x2012C040)                                                  */
/*       SKX (0x2012C040)                                                     */
/* Register default value:              0x0000                                */
#define ABAR_IIO_IOAPIC_REG 0x11032040
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x040
 */
typedef union {
  struct {
    UINT16 base_address_11 : 4;
    /* base_address_11 - Bits[3:0], RW, default = 4'b0000 
       8] (ZBAD)These bits determine the low order bits of the I/O APIC address map. 
       When a memory address is recognized by the IIO which matches 
       FECX_YZ00-to-FECX_YZFF, the IIO will respond to the cycle and access the 
       internal I/O APIC. 
     */
    UINT16 base_address_15 : 4;
    /* base_address_15 - Bits[7:4], RW, default = 4'b0000 
       12] (YBAD)These bits determine the low order bits of the I/O APIC address map. 
       When a memory address is recognized by the IIO which matches 
       FECX_YZ00-to-FECX_YZFF, the IIO will respond to the cycle and access the 
       internal I/O APIC. 
     */
    UINT16 base_address_19 : 4;
    /* base_address_19 - Bits[11:8], RW, default = 4'b0000 
       16] (XBAD)These bits determine the high order bits of the I/O APIC address map. 
       When a memory address is recognized by the IIO which matches 
       FECX_YZ00-to-FECX_YZFF, the IIO will respond to the cycle and access the 
       internal I/O APIC. 
     */
    UINT16 rsvd : 3;
    /* rsvd - Bits[14:12], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT16 abar_enable : 1;
    /* abar_enable - Bits[15:15], RW, default = 1'b0 
       When set, the range FECX_YZ00 to FECX_YZFF is enabled as an alternate access 
       method to the IOxAPIC registers and these addresses are claimed by the IIO's 
       internal I/OxAPIC regardless of the setting the MSE bit in the I/OxAPIC config 
       space. Bits 'XYZ' are defined below.Side 
     */
  } Bits;
  UINT16 Data;
} ABAR_IIO_IOAPIC_STRUCT;


/* PXPCAP_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x4012C044)                                                  */
/*       SKX (0x4012C044)                                                     */
/* Register default value:              0x0091E010                            */
#define PXPCAP_IIO_IOAPIC_REG 0x11034044
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x044
 */
typedef union {
  struct {
    UINT32 capability_id : 8;
    /* capability_id - Bits[7:0], RO, default = 8'b00010000 
       Provides the PCI Express capability ID assigned by PCI-SIG.
     */
    UINT32 next_ptr : 8;
    /* next_ptr - Bits[15:8], RO, default = 8'b11100000 
       Pointer to the next capability. Set to 0 to indicate there are no more 
       capability structures. 
     */
    UINT32 capability_version : 4;
    /* capability_version - Bits[19:16], RO, default = 4'b0001 
       PCI Express Capability is Compliant with Version 1.0 of the PCI Express Spec.
       Note:
       This capability structure is not compliant with Versions beyond 1.0, since they 
       require additional capability registers to be reserved. The only purpose for 
       this capability structure is to make enhanced configuration space available. 
       Minimizing the size of this structure is accomplished by reporting version 1.0 
       compliancy and reporting that this is an integrated root port device. As such, 
       only three Dwords of configuration space are required for this structure. 
       
     */
    UINT32 device_port_type : 4;
    /* device_port_type - Bits[23:20], RO, default = 4'b1001 
       Device type is Root Complex Integrated Endpoint
     */
    UINT32 slot_implemented : 1;
    /* slot_implemented - Bits[24:24], RO, default = 1'b0  */
    UINT32 interrupt_message_number : 5;
    /* interrupt_message_number - Bits[29:25], RO, default = 5'b00000 
       1
     */
    UINT32 rsvd : 2;
    /* rsvd - Bits[31:30], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT32 Data;
} PXPCAP_IIO_IOAPIC_STRUCT;


/* SNAPSHOT_INDEX_IIO_IOAPIC_REG supported on:                                */
/*       SKX_A0 (0x1012C080)                                                  */
/*       SKX (0x1012C080)                                                     */
/* Register default value:              0x00                                  */
#define SNAPSHOT_INDEX_IIO_IOAPIC_REG 0x11031080
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x080
 */
typedef union {
  struct {
    UINT8 ssidx : 8;
    /* ssidx - Bits[7:0], RW, default = 8'b00000000  */
  } Bits;
  UINT8 Data;
} SNAPSHOT_INDEX_IIO_IOAPIC_STRUCT;


/* SNAPSHOT_WINDOW_IIO_IOAPIC_REG supported on:                               */
/*       SKX_A0 (0x4012C090)                                                  */
/*       SKX (0x4012C090)                                                     */
/* Register default value:              0x00000000                            */
#define SNAPSHOT_WINDOW_IIO_IOAPIC_REG 0x11034090
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x090
 */
typedef union {
  struct {
    UINT32 sswindow : 32;
    /* sswindow - Bits[31:0], RO_V, default = 32'b00000000000000000000000000000000  */
  } Bits;
  UINT32 Data;
} SNAPSHOT_WINDOW_IIO_IOAPIC_STRUCT;


/* IOAPICTETPC_IIO_IOAPIC_REG supported on:                                   */
/*       SKX_A0 (0x4012C0A0)                                                  */
/*       SKX (0x4012C0A0)                                                     */
/* Register default value:              0x00000000                            */
#define IOAPICTETPC_IIO_IOAPIC_REG 0x110340A0
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x0a0
 */
typedef union {
  struct {
    UINT32 rsvd_intentry_prog_ctrl_0 : 1;
    /* rsvd_intentry_prog_ctrl_0 - Bits[0:0], RO, default = 1'b0 
       
                reserved
       
     */
    UINT32 porta_intb : 1;
    /* porta_intb - Bits[1:1], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 4
                            1: src/int is connected to IOAPIC table entry 1
       
     */
    UINT32 rsvd_intentry_prog_ctrl_5_2 : 4;
    /* rsvd_intentry_prog_ctrl_5_2 - Bits[5:2], RO, default = 4'b0000  */
    UINT32 portb_intc : 1;
    /* portb_intc - Bits[6:6], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 4 
                            1: src/int is connected to IOAPIC table entry 3 
       
     */
    UINT32 rsvd_intentry_prog_ctrl_8_7 : 2;
    /* rsvd_intentry_prog_ctrl_8_7 - Bits[8:7], RO, default = 2'b00  */
    UINT32 portc_intb : 1;
    /* portc_intb - Bits[9:9], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 5
                            1: src/int is connected to IOAPIC table entry 3
       
     */
    UINT32 rsvd_intentry_prog_ctrl_12_10 : 3;
    /* rsvd_intentry_prog_ctrl_12_10 - Bits[12:10], RO, default = 3'b000  */
    UINT32 portd_intb : 1;
    /* portd_intb - Bits[13:13], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 6
                            1: src/int is connected to IOAPIC table entry 7
       
     */
    UINT32 rsvd_intentry_prog_ctrl_14 : 1;
    /* rsvd_intentry_prog_ctrl_14 - Bits[14:14], RO, default = 1'b0  */
    UINT32 portd_intd : 1;
    /* portd_intd - Bits[15:15], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 5
                            1: src/int is connected to IOAPIC table entry 1
       
     */
    UINT32 rsvd_intentry_prog_ctrl_17_16 : 2;
    /* rsvd_intentry_prog_ctrl_17_16 - Bits[17:16], RO, default = 2'b00  */
    UINT32 cb_intc : 1;
    /* cb_intc - Bits[18:18], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 2 
                            1: src/int is connected to IOAPIC table entry 1 
       
     */
    UINT32 cb_intd : 1;
    /* cb_intd - Bits[19:19], RW, default = 1'b0 
       0: src/int is connected to IOAPIC table entry 3
                            1: src/int is connected to IOAPIC table entry 4
       
     */
    UINT32 rsvd : 12;
    /* rsvd - Bits[31:20], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT32 Data;
} IOAPICTETPC_IIO_IOAPIC_STRUCT;


/* PMCAP_IIO_IOAPIC_REG supported on:                                         */
/*       SKX_A0 (0x4012C0E0)                                                  */
/*       SKX (0x4012C0E0)                                                     */
/* Register default value:              0x00030001                            */
#define PMCAP_IIO_IOAPIC_REG 0x110340E0
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x0e0
 */
typedef union {
  struct {
    UINT32 capability_id : 8;
    /* capability_id - Bits[7:0], RO, default = 8'b00000001 
       Provides the PM capability ID assigned by PCI-SIG.
     */
    UINT32 next_capability_pointer : 8;
    /* next_capability_pointer - Bits[15:8], RO, default = 8'b00000000 
       1
     */
    UINT32 version : 3;
    /* version - Bits[18:16], RW_O, default = 3'b011 
       This field is set to 3h (PM 1.2 compliant) as version number.
     */
    UINT32 pme_clock : 1;
    /* pme_clock - Bits[19:19], RO, default = 1'b0  */
    UINT32 rsvd : 1;
    /* rsvd - Bits[20:20], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT32 device_specific_initialization : 1;
    /* device_specific_initialization - Bits[21:21], RO, default = 1'b0 
       1
     */
    UINT32 aux_current : 3;
    /* aux_current - Bits[24:22], RO, default = 3'b000  */
    UINT32 d1_support : 1;
    /* d1_support - Bits[25:25], RO, default = 1'b0  */
    UINT32 d2_support : 1;
    /* d2_support - Bits[26:26], RO, default = 1'b0  */
    UINT32 pme_support : 5;
    /* pme_support - Bits[31:27], RO, default = 5'b00000 
       Bits 31, 30 and 27 must be set to \q1\q for PCI-PCI bridge structures 
       representing ports on root complexes. 
     */
  } Bits;
  UINT32 Data;
} PMCAP_IIO_IOAPIC_STRUCT;


/* PMCSR_IIO_IOAPIC_REG supported on:                                         */
/*       SKX_A0 (0x4012C0E4)                                                  */
/*       SKX (0x4012C0E4)                                                     */
/* Register default value:              0x00000008                            */
#define PMCSR_IIO_IOAPIC_REG 0x110340E4
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x0e4
 */
typedef union {
  struct {
    UINT32 power_state : 2;
    /* power_state - Bits[1:0], RW_V, default = 2'b00  */
    UINT32 rsvd_2 : 1;
    /* rsvd_2 - Bits[2:2], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT32 rstd3hotd0 : 1;
    /* rstd3hotd0 - Bits[3:3], RO, default = 1'b1  */
    UINT32 rsvd_4 : 4;
    /* rsvd_4 - Bits[7:4], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT32 pmeen : 1;
    /* pmeen - Bits[8:8], RO, default = 1'b0  */
    UINT32 dsel : 4;
    /* dsel - Bits[12:9], RO, default = 4'b0000  */
    UINT32 dscl : 2;
    /* dscl - Bits[14:13], RO, default = 2'b00  */
    UINT32 pmests : 1;
    /* pmests - Bits[15:15], RO, default = 1'b0  */
    UINT32 rsvd_16 : 6;
    /* rsvd_16 - Bits[21:16], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT32 b2b3 : 1;
    /* b2b3 - Bits[22:22], RO, default = 1'b0  */
    UINT32 bpcce : 1;
    /* bpcce - Bits[23:23], RO, default = 1'b0  */
    UINT32 data : 8;
    /* data - Bits[31:24], RO, default = 8'b00000000  */
  } Bits;
  UINT32 Data;
} PMCSR_IIO_IOAPIC_STRUCT;


/* IPC_DFX_SPARE_REG0_IIO_IOAPIC_REG supported on:                            */
/*       SKX_A0 (0x4012C284)                                                  */
/*       SKX (0x4012C284)                                                     */
/* Register default value:              0x80000000                            */
#define IPC_DFX_SPARE_REG0_IIO_IOAPIC_REG 0x11034284
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 07_4_0x284
 */
typedef union {
  struct {
    UINT32 rsvd_0 : 31;
    UINT32 ntb_reevaluate_en : 1;
    /* ntb_reevaluate_en - Bits[31:31], RWS_L, default = 1'b1 
       dfx bit for ntb reevaluate_en
     */
  } Bits;
  UINT32 Data;
} IPC_DFX_SPARE_REG0_IIO_IOAPIC_STRUCT;


/* IOADSELS0_IIO_IOAPIC_REG supported on:                                     */
/*       SKX_A0 (0x4012C290)                                                  */
/*       SKX (0x4012C290)                                                     */
/* Register default value:              0x00000000                            */
#define IOADSELS0_IIO_IOAPIC_REG 0x11034290
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x288
 */
typedef union {
  struct {
    UINT32 rsvd_0 : 27;
    /* rsvd_0 - Bits[26:0], n/a, default = n/a 
       Padding added by header generation tool.
     */
    UINT32 sw2ipc_aer_event_sel : 1;
    /* sw2ipc_aer_event_sel - Bits[27:27], RWS, default = 1'b0  */
    UINT32 sw2ipc_aer_negedge_msk : 1;
    /* sw2ipc_aer_negedge_msk - Bits[28:28], RWS, default = 1'b0  */
    UINT32 rsvd_29 : 3;
    /* rsvd_29 - Bits[31:29], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT32 Data;
} IOADSELS0_IIO_IOAPIC_STRUCT;


/* IOINTSRC0_IIO_IOAPIC_REG supported on:                                     */
/*       SKX_A0 (0x4012C2A0)                                                  */
/*       SKX (0x4012C2A0)                                                     */
/* Register default value:              0x00000000                            */
#define IOINTSRC0_IIO_IOAPIC_REG 0x110342A0
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x2a0
 */
typedef union {
  struct {
    UINT32 int_src0 : 22;
    /* int_src0 - Bits[21:0], RW_V, default = 22'b0 
       
       bit interrupt source
       21: INTA Root Port Non-NTB
       20: INTA Root Port NTB
       19: INTD CB DMA
       18: INTC CB DMA
       17: INTB CB DMA
       16: INTA CB DMA
       15: INTD Port 3
       14: INTC Port 3
       13: INTB Port 3
       12: INTA Port 3
       11: INTD Port 2
       10: INTC Port 2
       9: INTB Port 2
       8: INTA Port 2
       7: INTD Port 1
       6: INTC Port 1
       5: INTB Port 1
       4: INTA Port 1
       3: INTD Port 0
       2: INTC Port 0
       1: INTB Port 0
       0: INTA Port 0
     */
    UINT32 rsvd : 10;
    /* rsvd - Bits[31:22], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT32 Data;
} IOINTSRC0_IIO_IOAPIC_STRUCT;


/* IOREMINTCNT_IIO_IOAPIC_REG supported on:                                   */
/*       SKX_A0 (0x4012C2A8)                                                  */
/*       SKX (0x4012C2A8)                                                     */
/* Register default value:              0x00000000                            */
#define IOREMINTCNT_IIO_IOAPIC_REG 0x110342A8
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x2a8
 */
typedef union {
  struct {
    UINT32 rem_int_cnt : 32;
    /* rem_int_cnt - Bits[31:0], RW_V, default = 32'b00000000000000000000000000000000 
       1
     */
  } Bits;
  UINT32 Data;
} IOREMINTCNT_IIO_IOAPIC_STRUCT;


/* IOREMGPECNT_IIO_IOAPIC_REG supported on:                                   */
/*       SKX_A0 (0x4012C2AC)                                                  */
/*       SKX (0x4012C2AC)                                                     */
/* Register default value:              0x00000000                            */
#define IOREMGPECNT_IIO_IOAPIC_REG 0x110342AC
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x2ac
 */
typedef union {
  struct {
    UINT32 gpe_cnt : 8;
    /* gpe_cnt - Bits[7:0], RW_V, default = 8'b00000000 
       1
     */
    UINT32 pmgpe_cnt : 8;
    /* pmgpe_cnt - Bits[15:8], RW_V, default = 8'b00000000 
       1
     */
    UINT32 hpgpe_cnt : 8;
    /* hpgpe_cnt - Bits[23:16], RW_V, default = 8'b00000000 
       1
     */
    UINT32 rsvd : 8;
    /* rsvd - Bits[31:24], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT32 Data;
} IOREMGPECNT_IIO_IOAPIC_STRUCT;


/* IOXAPICPARERRINJCTL_IIO_IOAPIC_REG supported on:                           */
/*       SKX_A0 (0x4012C2C0)                                                  */
/*       SKX (0x4012C2C0)                                                     */
/* Register default value:              0x00000000                            */
#define IOXAPICPARERRINJCTL_IIO_IOAPIC_REG 0x110342C0
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x2c0
 */
typedef union {
  struct {
    UINT32 pf : 4;
    /* pf - Bits[3:0], RWS_L, default = 4'b0000 
       pf[3:0]
     */
    UINT32 rsvd_4 : 14;
    UINT32 notused : 4;
    /* notused - Bits[21:18], RWS_L, default = 4'b0000 
       1
     */
    UINT32 rsvd_22 : 2;
    UINT32 bfs : 2;
    /* bfs - Bits[25:24], RWS_L, default = 2'b00 
       bfs[1:0]
     */
    UINT32 rsvd_26 : 4;
    UINT32 eirfs : 1;
    /* eirfs - Bits[30:30], RWS_L, default = 1'b0  */
    UINT32 eie : 1;
    /* eie - Bits[31:31], RWS_L, default = 1'b0  */
  } Bits;
  UINT32 Data;
} IOXAPICPARERRINJCTL_IIO_IOAPIC_STRUCT;


/* FAUXGV_IIO_IOAPIC_REG supported on:                                        */
/*       SKX_A0 (0x4012C2C4)                                                  */
/*       SKX (0x4012C2C4)                                                     */
/* Register default value:              0x00000000                            */
#define FAUXGV_IIO_IOAPIC_REG 0x110342C4
/* Struct format extracted from XML file SKX\1.5.4.CFG.xml.
 * generated by critter 05_4_0x2c4
 */
typedef union {
  struct {
    UINT32 fauxgven : 1;
    /* fauxgven - Bits[0:0], RWS_L, default = 1'b0  */
    UINT32 rsvd : 31;
    /* rsvd - Bits[31:1], n/a, default = n/a 
       Padding added by header generation tool.
     */
  } Bits;
  UINT32 Data;
} FAUXGV_IIO_IOAPIC_STRUCT;


#endif /* IIO_IOAPIC_h */
