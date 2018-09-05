//****************************************************************************
//**                                                                        **
//**            (C)Copyright 1993-2016 Supermicro Computer, Inc.            **
//**                                                                        **
//****************************************************************************
//  File History
//
//  Rev. 1.00
//    Bug Fix:  Initialize revision
//    Reason:   Clone from Sample folder.
//    Auditor:  Jacker Yeh
//    Date:     Feb/04/2016
//
//****************************************************************************
//****************************************************************************

//----------------------------------------------------------------------------
// Include File(s)
//----------------------------------------------------------------------------
#include "token.h"
#include "SuperMPeiDriver.h"

// {A0E5A45F-5374-46b3-B51E-D310B2C48AAE}
#define EFI_PROJECT_OWN_PEI_PROTOCOL_GUID \
  { \
     0xa0e5a45f, 0x5374, 0x46b3, 0xb5, 0x1e, 0xd3, 0x10, 0xb2, 0xc4, 0x8a, 0xae \
  }

#define ENABLE            1
#define DISABLE           0
#define NO_SLT_IMP        0xFF
#define SLT_IMP           1
#define HIDE              1
#define NOT_HIDE          0
#define VPP_PORT_0        0
#define VPP_PORT_1        1
#define VPP_PORT_MAX      0xFF
#define VPP_ADDR_MAX      0xFF
#define PWR_VAL_MAX       0xFF
#define PWR_SCL_MAX       0xFF

VOID
OemEnableHotPlug (
    IN OUT  IIO_CONFIG  *SetupData,
    IN UINT8 Port,
    IN UINT8 VppPort,
    IN UINT8 VppAddress,
    IN UINT8 PortOwnership
  );

//***************************************************************************
//**                                                                       **
//**       (C)Copyright 1993-2012 Supermicro Computer, Inc.                **
//**                                                                       **
//**                                                                       **
//***************************************************************************
//***************************************************************************

