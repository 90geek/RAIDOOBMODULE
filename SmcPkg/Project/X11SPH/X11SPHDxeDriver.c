//****************************************************************************
//**                                                                        **
//**            (C)Copyright 1993-2016 Supermicro Computer, Inc.            **
//**                                                                        **
//****************************************************************************
//  File History
//
//  Rev. 1.04
//    Bug Fix:  Fix BMC can't get LAN Mac address.
//    Reason:
//    Auditor:  William Hsu
//    Date:     Jan/11/2017
//
//  Rev. 1.03
//    Bug Fix:  Correct SMBIOS Type 8.
//    Reason:   
//    Auditor:  William Hsu
//    Date:     Dec/30/2016
//
//  Rev. 1.01
//    Bug Fix:  Initialize revision
//    Reason:   Clone from Sample folder.
//    Auditor:  William Hsu
//    Date:     Dec/29/2016
//
//****************************************************************************
//****************************************************************************
//<AMI_FHDR_START>
//----------------------------------------------------------------------------
//
// Name:		ProjectDxeDriver.c
//
// Description:
//  This file implement function of PROJECTDRIVER_PROTOCOL
//
//----------------------------------------------------------------------------
//<AMI_FHDR_END>
#include <Token.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/GpioLib.h>
#include <Library/MmPciBaseLib.h>
#include <PciBus.h>
#include "X11SPHDxeDriver.h"
#include "SmcLib.h"
#include "SmcSetupModify.h"
#include "HideSetupItem.h"
#include <Protocol/AmiSmbios.h>
#include <Library/MmPciBaseLib.h>

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  OVERRIDE_IOBP
//
// Description :  override IOBP setting for USB3/ SATA SI
//
// Parameters:  None
//
// Returns     :  Override IOBP setting in PEI phase
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
VOID
OVERRIDE_IOBP(VOID)
{
    DEBUG((EFI_D_INFO, "OVERRIDE_IOBP entry.\n"));

    DEBUG((EFI_D_INFO, "OVERRIDE_IOBP end.\n"));
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  ProjectCheckAdjustVID
//
// Description :  Send out the Project Adjust VID
//
// Parameters  :  NONE
//
// Returns     :  Project Adjust VID
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT8 EFIAPI ProjectCheckAdjustVID(VOID)
{
    return 0;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  GetGPUDID
//
// Description :  Get GPU device id
//
// Parameters  :  NONE
//
// Returns     :  Get GPU device id
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT16 EFIAPI GetGPUDID(VOID)
{
    return 0;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  ProjectGetBID
//
// Description :  Send out the Project BID
//
// Parameters  :  NONE
//
// Returns     :  Project BID
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT8 EFIAPI GetProjectBID(VOID)
{
    return 0x00;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  ProjectCheckBMCPresent
//
// Description :  Check BMC Present or not
//
// Parameters  :  NONE
//
// Returns     :  1: BMC Present  0: MBC not present
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
UINT8 EFIAPI ProjectCheckBMCPresent(VOID)
{
    UINT8 ReturnVal = 0;
    return ReturnVal;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
// Name:  GetOnBoardLanMacAddress
//
// Description: 
//  Get onboard lan Mac address in PEI phase. BIOS should decode
//  PCIE root port bus temporary and then to set Lan resource to
//  get Mac address. BIOS must remove all temporary setting before
//  exit this routine
//
// Input:
//      IN UINT16 LanRootPortCfg - Onbaord lan pcie root port BDF
//      IN OUT UINT8 *LanMacAddressStart1 - Point to start address of LAN 1 MAC structure
//      IN OUT UINT8 *LanMacAddressStart2 - Point to start address of LAN 2 MAC structure
//
// Output:      
//      EFI_SUCCESS (return)
//
//----------------------------------------------------------------------------
//<AMI_PHDR_END>
EFI_STATUS
GetOnBoardLanMacAddress (
    IN  UINT16	BDF,
    IN  UINT8	*TempBuffer
)
{
    EFI_STATUS Status = EFI_SUCCESS;
    UINT32	Data32;

    DEBUG((-1, "GetOnBoardLanMacAddress start.\n"));
    
    MemSet (TempBuffer, 6, 0);
    
    Data32 = *(UINT32*)MmPciAddress(0, (UINT8)(BDF >> 8), (UINT8)((BDF >> 3) & 0x1f),
		    (UINT8)(BDF & 0x07), 0);
    
    if(Data32 == 0xffffffff)	return Status;
    
    TempBuffer[0]++;	//add LAN number.
    
    *(UINT8*)MmPciAddress(0, (UINT8)(BDF >> 8), (UINT8)((BDF >> 3) & 0x1f), (UINT8)(BDF & 0x07), 0x04) |= 0x06;

    Data32 = *(UINT32*)MmPciAddress(0, (UINT8)(BDF >> 8), (UINT8)((BDF >> 3) & 0x1f),
		    (UINT8)(BDF & 0x07), 0x10);

    Data32 = (Data32 & 0xfffffff0) + 0x1E2120;
    gBS->CopyMem(TempBuffer + 1, (UINT8*)Data32, 4);

    Data32 = *(UINT32*)MmPciAddress(0, (UINT8)(BDF >> 8), (UINT8)((BDF >> 3) & 0x1f),
    		    (UINT8)(BDF & 0x07), 0x10);

    Data32 = (Data32 & 0xfffffff0) + 0x1E2140;
    gBS->CopyMem(TempBuffer + 5, (UINT8*)Data32, 2);

    DEBUG((-1, "GetOnBoardLanMacAddress end.\n"));
    return Status;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  ProjectHardwareInfo
//
// Description :  Create Project own Hareware Information
//
// Parameters  :  OUT: HardWareInfoData
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS EFIAPI ProjectHardwareInfo(
    OUT	UINT8	*HardWareInfoData,
    OUT	UINT8	*LanMacInfoData
)
{
    EFI_STATUS	Status = EFI_SUCCESS;
    UINT16	BDF, Bus;

    HardWareInfoData[3] = 0x00;
    BDF = SmcBDFTransfer(PcdGet32(PcdSmcOBLan1BDF));
    Bus = GetOnBoardLanBus(BDF); 
    BDF = Bus << 8;
    GetOnBoardLanMacAddress(BDF, (HardWareInfoData + 3));

    // LanMacInfoData parameter data is used by 0x9E command
    // IPMI 0x9E command data:
    // Byte 0    : LAN number N  (exclude NumLan of 0x30 0x20 command)
    // Byte 1-6  : LAN port M MAC address
    // Byte 7-12 : LAN port M+1 MAC address
    LanMacInfoData[0] = 0;
    
    BDF = (Bus << 8) + 1;
    GetOnBoardLanMacAddress(BDF, LanMacInfoData);

    return Status;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  CheckAudioHandle
//
// Description :  Handle audio function in board level
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS EFIAPI CheckAudioHandle(VOID)
{
    return EFI_SUCCESS;
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  GetProjectPciEBifurcate
//
// Description :  Handle audio function in board level
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS EFIAPI GetProjectPciEBifurcate(IN OUT IIO_CONFIG *SetupData)
{
    EFI_STATUS	Status = EFI_SUCCESS;
    DEBUG((EFI_D_INFO, "DXE GetProjectPciEBifurcate Start.\n"));

    DEBUG((EFI_D_INFO, "DXE GetProjectPciEBifurcate End.\n"));
    return EFI_SUCCESS;
}
//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  X11SPHSmbiosUpdate
//
// Description :  Update SMBIOS information after ReadyToBootEvent
//
// Returns     :  none
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
VOID
X11SPHSmbiosUpdate()
{
    EFI_STATUS  Status;
    UINT8       *TempBuffer;
    UINT16      TempBufferSize;
    UINT16      Handle;
    AMI_SMBIOS_PROTOCOL *SmbiosProtocol;
    UINT8       index, temp_ID;
    UINT32      temp, X11SPH_SKU_GPIO[] = SKU_TBL_GPIO_Tbl;


    DEBUG((EFI_D_INFO, "X11SPH SmbiosUpdate entry.\n"));
    Status = gBS->LocateProtocol(&gAmiSmbiosProtocolGuid,NULL,&SmbiosProtocol);
    if(EFI_ERROR(Status))
        return;

//          GPP_C13  GPP_C12  LAN
//          0            0  X557
//          0            1  CS4227

    temp_ID = 0;
    for(index=0; index<2; index++) {
        GpioGetInputValue(X11SPH_SKU_GPIO[index], &temp);
        temp_ID |= temp << index;
    }

    // X557 10G Base T
    if(temp_ID==0) {
        // Delete instance 3 from SMBIOS Type 8
        Status = SmbiosProtocol->SmbiosReadStrucByType(8, 3, &TempBuffer, &TempBufferSize);
        if(!EFI_ERROR(Status)) {
            Handle = ((SMBIOS_STRUCTURE_HEADER*)TempBuffer)->Handle;
            SmbiosProtocol->SmbiosDeleteStructure(Handle);
            gBS->FreePool(TempBuffer);
        }
    }
    else if(temp_ID==1) { // CS4227 SFP +
        // Delete instance 4  from SMBIOS Type 8
        Status = SmbiosProtocol->SmbiosReadStrucByType(8, 4, &TempBuffer, &TempBufferSize);
        if(!EFI_ERROR(Status)) {
            Handle = ((SMBIOS_STRUCTURE_HEADER*)TempBuffer)->Handle;
            SmbiosProtocol->SmbiosDeleteStructure(Handle);
            gBS->FreePool(TempBuffer);
        }
    }  
    DEBUG((EFI_D_INFO, "X11SPH SmbiosUpdate end.\n"));
}

/*-----------------12/23/2014 8:39PM----------------
 * Coding for every platform
 * --------------------------------------------------*/
/*
//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   :  SetProjectPciECTLE
//
// Description :  Handle PciE CTLE override in board level
// 		Instance	Function	Port	Description
//		0		D6:F0 		0	DMI without Gen3 support
//		1		D6:F1		1	Port 1 CTLE
//		3		D6:F3		2	Port 2 CTLE
//		7		D7:F0		3	Port 3 CTLE
// Input:
//	IN IIO_GLOBALS	*IioGlobalData
//	IN UINT8	Iio
//	IN UINT8	BusNumber
//
// Output:      
//      EFI_SUCCESS (return)
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>

EFI_STATUS EFIAPI
SetProjectPciECTLE(
    IN IIO_GLOBALS	*IioGlobalData,
    IN UINT8	Iio,
    IN UINT8	BusNumber
)
{
    TRACE((-1, "SetProjectPciECTLE entry.\n"));
    TRACE((-1, "SetProjectPciECTLE end.\n"));
    return EFI_SUCCESS;
}
 */

PROJECTDRIVER_PROTOCOL ProjectInterface =
{
    ProjectCheckAdjustVID,
    GetGPUDID,
    GetProjectBID,
    NULL,
    ProjectHardwareInfo,
    ProjectCheckBMCPresent,
    CheckAudioHandle,
    GetProjectPciEBifurcate,
    NULL,
    NULL,
    NULL
};


//<AMI_PHDR_START>
//----------------------------------------------------------------------------
// Procedure:   X11SPHReadyToBootCallBack
//
// Description: Run at ready to boot.
//
// Input:       IN EFI_EVENT   Event
//              IN VOID        *Context
//
// Output:      None
//
// Modified:
//
// Referrals:
//
// Notes:
//----------------------------------------------------------------------------
//<AMI_PHDR_END>
VOID
X11SPHReadyToBootCallBack (
    IN EFI_EVENT Event,
    IN VOID *Context
)
{
    EFI_STATUS	Status = EFI_SUCCESS;

    DEBUG((EFI_D_INFO, "X11SPHReadyToBootCallBack Entry.\n"));
    
    X11SPHSmbiosUpdate();
    gBS->CloseEvent(Event);
}

//<AMI_PHDR_START>
//----------------------------------------------------------------------------
//
// Procedure   : X11SPHDriverInit
//
// Description : Project DXE initial code
//
// Parameters  : None
//
// Returns     :  EFI_SUCCESS
//
//----------------------------------------------------------------------------
//<AMI_PHDR_START>
EFI_STATUS
X11SPHDxeDriverInit(
    IN	EFI_HANDLE	ImageHandle,
    IN	EFI_SYSTEM_TABLE	*SystemTable
)
{
    EFI_STATUS	Status;
    EFI_HANDLE	Handle = NULL;
    EFI_EVENT	X11SPHReadyToBootEvent, HideItemEvent;
    VOID        *HideItemReg;
    static EFI_GUID guidReadyToBoot = EFI_EVENT_GROUP_READY_TO_BOOT;

    DEBUG((EFI_D_INFO, "ProjectDriver Init\n"));

    Status = gBS->InstallProtocolInterface(
		    &Handle,
		    &gProjectOwnProtocolGuid ,
		    EFI_NATIVE_INTERFACE,
		    &ProjectInterface);

    ASSERT_EFI_ERROR(Status);

    Status = gBS->CreateEventEx(
		    EVT_NOTIFY_SIGNAL,
		    TPL_CALLBACK, 
		    X11SPHReadyToBootCallBack,
		    NULL,
		    &guidReadyToBoot,
		    &X11SPHReadyToBootEvent);

    Status = gBS->CreateEvent(
                      EVT_NOTIFY_SIGNAL,
                      TPL_CALLBACK,
                      X11SPHHideSetupItem,
                      NULL,
                      &HideItemEvent);

    if(!Status){
	Status = gBS->RegisterProtocolNotify(
                      &gSetupModifyProtocolGuid,
                      HideItemEvent,
                      &HideItemReg);
    }

    OVERRIDE_IOBP();
    
    DEBUG((EFI_D_INFO, "Exit ProjectDriver Init\n"));

    return Status;
}
