//****************************************************************************
//****************************************************************************
//**            (C)Copyright 1993-2018 Supermicro Computer, Inc.            **
//****************************************************************************
//****************************************************************************
//  File History
//
//  Rev. 1.01
//    Bug Fix:  
//    Reason:   Add RAID 2208 settings.
//    Auditor:  Durant Lin
//    Date:     Oct/02/2018
//
//  Rev. 1.00
//    Bug Fix:  Initial revision.
//    Reason:
//    Auditor:  Durant Lin
//    Date:     Sep/28/2018
//
//****************************************************************************
#include "SmcLsiRaidOOBSetup.h"

SMC_LSI_HII_HANDLE*	mSmcLsiHiiHandleTable = NULL;

//Since this module doesn't report to TSE, use dummy functions.
//EFI_HII_CONFIG_ACCESS_PROTOCOL	SmcLsiOOBConfigAccess = { NULL, NULL, NULL };
EFI_GUID	gSmcLsiOOBSetupFormSetGuid = SMC_LSI_OOB_FORM_SET_GUID;

CALLBACK_INFO SmcLsiOOBSetupCallBack[] = {
        { &gSmcLsiOOBSetupFormSetGuid, NULL, 0, 0, 0 }
};

EFI_HII_HANDLE	GetHiiHandle(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){
		
	EFI_HII_HANDLE	pHandle;

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	pHandle = pPrivate->HIIHandle;

	return pHandle;
}

EFI_GUID*	GetFormSetGuid(SMC_LSI_RAID_OOB_SETUP_PROTOCOL*	pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return &pPrivate->FormSetGuid;
}
EFI_STRING_ID	GetFormSetNameID(SMC_LSI_RAID_OOB_SETUP_PROTOCOL*	pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->FormSetNameID;
}
UINT16	GetFormID(SMC_LSI_RAID_OOB_SETUP_PROTOCOL*	pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->FormID;
}
UINT16	GetFormIdStart(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return ++pPrivate->FormIdStart;
}
UINT16	GetFormIdNow(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->FormIdStart;
}
UINT16	GetQIdStart(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return ++pPrivate->QIdStart;
}
UINT16	GetQIdNow(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->QIdStart;
}
UINT16	GetVIdStart(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return ++pPrivate->VarIdStart;
}
UINT16	GetVIdNow(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->VarIdStart;
}
EFI_GUID*	GetVarGuid(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return &pPrivate->VarGuid;
}
UINT16	GetFormGoToLabel(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->FormGoToLabel;
}
UINT16	GetFormLabel(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->FormLabel;
}
UINT16	GetOtherLableStart(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return ++pPrivate->OtherLabelStart;
}
UINT16	GetOtherLableNow(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->OtherLabelStart;
}
UINT8*	GetSetupData(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->RaidSetupVfr;
}

UINT8*	GetSetupString(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	SMC_LSI_RAID_OOB_SETUP_PRIVATE*	pPrivate = NULL;
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupProtocol,pProtocol);

	return pPrivate->RaidSetupString;
}

CHAR16*	GetHDGName(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	static	CHAR16 HardDrivesGroupName[] = HARD_DRIVES_GROUP;

	return HardDrivesGroupName;
}

CHAR16*	GetRDGName(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	static	CHAR16 RaidDrivesGroupName[] = RAID_DRIVES_GROUP;	

	return RaidDrivesGroupName;
}

CHAR16*	GetJBODName(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	static	CHAR16 JBODsGroupName[] = JBOD_DRIVES_GROUP;	

	return JBODsGroupName;
}

CHAR8* GetSmcItemsVarName(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	static	CHAR8 SmcItemsVarName[] = FOR_SMC_ITEMS_VAR_NAME;	

	return SmcItemsVarName;
}

CHAR8* GetRaidVarName(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	static	CHAR8 RaidItemsVarName[] = FOR_RAID_ITEMS_VAR_NAME;	

	return RaidItemsVarName;
}

UINT16 GetSmcRaidVarSize(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	return sizeof(SMC_ITEMS_VAR_DATA);
}

UINT32*	GetSmcRaidCmdOffset(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){
	
	static UINT32	CmdOffset[] = { 
		 STRUCT_OFFSET(SMC_ITEMS_VAR_DATA,CMD1),
		 STRUCT_OFFSET(SMC_ITEMS_VAR_DATA,CMD2),
		 STRUCT_OFFSET(SMC_ITEMS_VAR_DATA,CMD3),
		 ((UINT32)-1)
	};
	
	return CmdOffset;
}

SMC_RAID_CMD_RAIDTYPE_TO_VALUE_MAP* GetSmcRaidTypeToValueMap(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){

	return mSmcRaidTypeToValueMapTable;
}


EFI_STATUS SmcLsiSetupDownDummyFunc(SMC_LSI_RAID_OOB_SETUP_PROTOCOL* pProtocol){
	return EFI_SUCCESS;
}

UINT8	GetRaidIndex(SMC_LSI_RAID_TYPE	RaidType){
	static	UINT8	Raid3108Index = 0;
	static	UINT8	Raid9260Index = 0;
	static  UINT8	Raid2208Index = 0;

	UINT8	ReturnIndex = 0;

	switch(RaidType){
		case RAID_3108:
			ReturnIndex = Raid3108Index++;
			break;
		case RAID_9260:
			ReturnIndex = Raid9260Index++;
			break;
		case RAID_2208:
			ReturnIndex = Raid2208Index++;
			break;
		default:
			break;
	}
	return ReturnIndex;
}

EFI_STATUS LoopToInitialTables(
		VOID*	Table, 
		SMC_LSI_HII_HANDLE* pTemp, 
		UINT8* pLocalBuffer, 
		UINTN Index, 
		UINTN HeaderSize, 
		UINTN TotalSize, 
		UINTN TableOffset, 
		UINTN NextOffset){

#define GET_TABLEHEADER()\
	((TABLE_COMMON_HEADER*)((UINT8*)CmnHeader + (Index * HeaderSize)))
	
	TABLE_COMMON_HEADER*	CmnHeader = NULL;
	CmnHeader = Table;

	if( GET_TABLEHEADER()->LsiRaidTypeIndex == RAID_NULL) return EFI_NO_MEDIA;
	if( pTemp->RaidCardType == GET_TABLEHEADER()->LsiRaidTypeIndex){
		UINT8* 	pTempBuffer = NULL;
		
		gBS->AllocatePool(EfiBootServicesData,TotalSize,&pTempBuffer);
		MemSet(pTempBuffer,TotalSize,0x00);
		MemCpy(pTempBuffer, GET_TABLEHEADER(),HeaderSize);

		if(!(!!pLocalBuffer)){
			pLocalBuffer = pTempBuffer;
			*(UINT32*)((UINT8*)pTemp + TableOffset) = (UINT32)pTempBuffer;
		}else {
			*(UINT32*)(pLocalBuffer + NextOffset) = (UINT32)pTempBuffer;
			pLocalBuffer = pTempBuffer;
		}
	}
	return LoopToInitialTables(Table,pTemp,pLocalBuffer,Index+1,HeaderSize,TotalSize,TableOffset,NextOffset);
}

EFI_STATUS	LoopToInitialChRecrodsTable(SMC_LSI_HII_HANDLE* pTemp){
	return LoopToInitialTables(
				mSmcLsiChRecordsTable,
				pTemp,
				NULL,
				0,
				sizeof(SMC_RAID_CHRECORD_HEADER),
				sizeof(SMC_RAID_CHRECORD_SET),
				STRUCT_OFFSET(SMC_LSI_HII_HANDLE,RaidCardChRecordTable),
				STRUCT_OFFSET(SMC_RAID_CHRECORD_SET,ChRecordNext)
			);
}

EFI_STATUS	LoopToInitialFormRefSearchTable(SMC_LSI_HII_HANDLE* pTemp){
	return LoopToInitialTables(
				mSmcLsiRaidFormRefSearchTable,
				pTemp,
				NULL,
				0,
				sizeof(SMC_LSI_RAID_FORM_HEADER),
				sizeof(SMC_LSI_RAID_FORM_SET),
				STRUCT_OFFSET(SMC_LSI_HII_HANDLE,RaidCardAccessForms),
				STRUCT_OFFSET(SMC_LSI_RAID_FORM_SET,pFormNext)
			);
}

EFI_STATUS	LoopToInitialItemsTable(SMC_LSI_HII_HANDLE* pTemp){
	return LoopToInitialTables(
				mSmcLsiItemsTable,
				pTemp,
				NULL,
				0,
				sizeof(SMC_RAID_ITEMS_HEADER),
				sizeof(SMC_RAID_ITEMS_SET),
				STRUCT_OFFSET(SMC_LSI_HII_HANDLE,RaidCardInfItems),
				STRUCT_OFFSET(SMC_RAID_ITEMS_SET,pItemsNext)
			);
}

VOID	AddSmcLsiHiiHandle(SMC_LSI_RAID_TYPE RaidType,EFI_HII_HANDLE RaidHiiHandle){
	static 	SMC_LSI_HII_HANDLE*			pLocal 			= NULL;
	SMC_LSI_HII_HANDLE*					pTemp 			= NULL;

	gBS->AllocatePool(EfiBootServicesData,sizeof(SMC_LSI_HII_HANDLE),&pTemp);
	MemSet(pTemp,sizeof(SMC_LSI_HII_HANDLE),0x00);

	pTemp->RaidCardType			= RaidType;
	pTemp->RaidCardIndex		= GetRaidIndex(RaidType);
	pTemp->RaidCardHiiHandle	= RaidHiiHandle;
	pTemp->RaidCardAccessForms	= NULL;
	pTemp->pNext				= NULL;

	LoopToInitialChRecrodsTable(pTemp);
	LoopToInitialFormRefSearchTable(pTemp);
	LoopToInitialItemsTable(pTemp);

	if(! (!!pLocal)){
		pLocal = mSmcLsiHiiHandleTable = pTemp;
	}else{
		pLocal->pNext 	= pTemp;
		pLocal 			= pLocal->pNext;
	}

	DEBUG((-1,"pLocal RaidCardType[%x], RaidCardIndex[%x], RaidCardHiiHandle[%08x]\n",pLocal->RaidCardType,pLocal->RaidCardIndex,(UINT32)pLocal->RaidCardHiiHandle));
	return;
}

BOOLEAN SearchForLsiFormSetByHiiOrder(){

	EFI_HII_HANDLE*				HiiHandleBuffer = NULL;
	UINTN						BufferSize = 0;
	UINTN						Index = 0;
	UINTN						NameIndex = 0;
	BOOLEAN						SearchFind = FALSE;

	EFI_HII_PACKAGE_LIST_HEADER *HiiPackageList = NULL;
    EFI_HII_PACKAGE_HEADER 		*IfrPackagePtr;
    EFI_IFR_OP_HEADER* 			pEFI_IFR_OP_HEADER = NULL;
	EFI_IFR_FORM_SET*  			pEFI_IFR_FORM_SET = NULL;
	CHAR16*			   			TempS = NULL;
	EFI_STATUS					PackStatus	= EFI_SUCCESS;

	PackStatus = GetListPackageListsHandle(&BufferSize,&HiiHandleBuffer);

	for(Index = 0; !EFI_ERROR(PackStatus) ;Index++){

		if(HiiHandleBuffer[Index] == NULL || Index >= BufferSize/sizeof(EFI_HII_HANDLE)) break;
		
		HiiPackageList = GetHiiPackageList(HiiHandleBuffer[Index]);
		if(! (!!HiiPackageList)) break;
    	for (IfrPackagePtr = (EFI_HII_PACKAGE_HEADER*)(HiiPackageList+1);
        	 IfrPackagePtr < (EFI_HII_PACKAGE_HEADER*)((UINT8*)HiiPackageList+HiiPackageList->PackageLength);
        	 IfrPackagePtr = (EFI_HII_PACKAGE_HEADER*)((UINT8*)IfrPackagePtr+IfrPackagePtr->Length)){

			if(IfrPackagePtr->Type == EFI_HII_PACKAGE_FORMS){
				pEFI_IFR_OP_HEADER = (EFI_IFR_OP_HEADER*)((UINT8*)IfrPackagePtr + sizeof (EFI_HII_PACKAGE_HEADER));	
				if (pEFI_IFR_OP_HEADER->OpCode == EFI_IFR_FORM_SET_OP) {
					pEFI_IFR_FORM_SET = (EFI_IFR_FORM_SET*)pEFI_IFR_OP_HEADER;
					TempS = GetHiiString(HiiHandleBuffer[Index],pEFI_IFR_FORM_SET->FormSetTitle);
					DEBUG((-1," FormSetTitle :: %s\n",TempS));
					DEBUG((-1," Guid :: %g\n",pEFI_IFR_FORM_SET->Guid));
						
					for(NameIndex=0;RaidName[NameIndex].LsiRaidTypeIndex != RAID_NULL;++NameIndex){
						if(MemCmp(TempS,RaidName[NameIndex].FormRaidName,StrLen(RaidName[NameIndex].FormRaidName) * sizeof(CHAR16)) == 0){
							DEBUG((-1,"Find RaidName[%d] :: <%s>\n",NameIndex,RaidName[NameIndex].FormRaidName));
							AddSmcLsiHiiHandle(RaidName[NameIndex].LsiRaidTypeIndex,HiiHandleBuffer[Index]);
							SearchFind = TRUE;
						}
					}	
				}
			}
		}
	}
	return SearchFind;
}

EFI_STATUS SmcLsiOOBSetupDriverStart(SMC_LSI_RAID_OOB_SETUP_DRIVER*	pDriver){

	EFI_STATUS		Status			= EFI_SUCCESS;
	UINTN			Index			= 0;
	EFI_GUID		lFormSetGuid	= SMC_LSI_OOB_FORM_SET_GUID;
	EFI_GUID		lVarGuid		= SMC_LSI_OOB_VAR_GUID;

	SMC_LSI_RAID_OOB_SETUP_PROTOCOL*		mSmcLsiRaidOOBSetupProtocol = NULL;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			pPrivate = NULL;

	DEBUG((-1,"SmcLsiOOBSetupDriverStart Entry\n"));

	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupDriver,pDriver);

	if(!(!!SearchForLsiFormSetByHiiOrder())) return EFI_LOAD_ERROR;

	gBS->AllocatePool(EfiBootServicesData,sizeof(SMC_LSI_RAID_OOB_SETUP_PROTOCOL),&mSmcLsiRaidOOBSetupProtocol);
	MemSet(mSmcLsiRaidOOBSetupProtocol,sizeof(SMC_LSI_RAID_OOB_SETUP_PROTOCOL),0x00);

	mSmcLsiRaidOOBSetupProtocol->SmcLsiDetailedStatus			= 0x0;
	mSmcLsiRaidOOBSetupProtocol->DetailedDebugMessage			= SMC_RAID_DETAILED_DEBUG_MESSAGE;
	mSmcLsiRaidOOBSetupProtocol->SmcSetupStatus					= EFI_NOT_READY;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiHaveNvData				= FALSE;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiRaidNameTable			= RaidName; 
	mSmcLsiRaidOOBSetupProtocol->SmcLsiHiiHandleTable 			= mSmcLsiHiiHandleTable;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiAfterDownFuncTable		= mSmcLsiAfterDwonFuncTable;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiAfterLoadFuncTable		= mSmcLsiAfterLoadFuncTable;

	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormId				= GetFormID;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormSetGuid			= GetFormSetGuid;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormSetNameId			= GetFormSetNameID;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormGoToLabel			= GetFormGoToLabel;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormLabel				= GetFormLabel;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetHiiHandle				= GetHiiHandle;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetQIdStart				= GetQIdStart;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetQidNow				= GetQIdNow;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormIdStart			= GetFormIdStart;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetFormIdNow				= GetFormIdNow;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetVIdStart				= GetVIdStart;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetVIdNow				= GetVIdNow;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetOLabelStart			= GetOtherLableStart;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetOLabelNow				= GetOtherLableNow;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetVarGuid				= GetVarGuid;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetSetupData				= GetSetupData;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetSetupString			= GetSetupString;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetHdgName				= GetHDGName;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetRdgName				= GetRDGName;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetJBODName				= GetJBODName;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetSmcItemsVarName		= GetSmcItemsVarName;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetRaidVarName			= GetRaidVarName;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetSmcRaidVarSize		= GetSmcRaidVarSize;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetSmcRaidCmdOffset		= GetSmcRaidCmdOffset;
	mSmcLsiRaidOOBSetupProtocol->SmcLsiGetSmcRaidTypeToValueMap	= GetSmcRaidTypeToValueMap;


	pPrivate->HIIHandle 					= NULL;		//Will update after LoadResources
	pPrivate->FormSetNameID					= STRING_TOKEN(STR_SMC_LSI_OOB_TITLE); 
	pPrivate->FormID						= SMC_LSI_OOB_FORM;
	pPrivate->QIdStart						= SMC_LSI_OOB_Q_ID_START;
	pPrivate->FormIdStart					= SMC_LSI_OOB_FORM_START;	
	pPrivate->VarIdStart					= SMC_LSI_OOB_VAR_ID_START;
	pPrivate->FormGoToLabel					= SMC_LSI_OOB_FORM_GOTO_LABEL;
	pPrivate->FormLabel						= SMC_LSI_OOB_FORM_LABEL;
	pPrivate->OtherLabelStart				= SMC_LSI_OOB_OTHER_LABEL_START;
	pPrivate->FormSetGuid					= lFormSetGuid;
	pPrivate->VarGuid						= lVarGuid;
	pPrivate->HaveRaidResource				= TRUE;
	pPrivate->Process						= DRIVER_INSTALL;

	pPrivate->RaidSetupVfr					= NULL;
	pPrivate->RaidSetupString				= NULL;

	MemCpy(&pPrivate->SmcLsiRaidOOBSetupProtocol,mSmcLsiRaidOOBSetupProtocol,sizeof(SMC_LSI_RAID_OOB_SETUP_PROTOCOL));

	Status = gBS->InstallProtocolInterface(
					&pPrivate->DriverHandle,
					&gSmcLsiRaidOobSetupProtocolGuid,
					EFI_NATIVE_INTERFACE,
					&pPrivate->SmcLsiRaidOOBSetupProtocol
				);
	DEBUG((-1,"SmcLsiOOBSetupDriverStart InstallProtocolInterface gSmcLsiRaidOobSetupProtocolGuid Status[%r]\n",Status));
	if(EFI_ERROR(Status)) return Status;

    return EFI_SUCCESS;
}

EFI_STATUS SmcLsiOOBSetupDriverDownload(SMC_LSI_RAID_OOB_SETUP_DRIVER*	pDriver){

	EFI_STATUS								Status			= EFI_NOT_READY;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			pPrivate 		= NULL;

	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupDriver,pDriver);
	
	if(!!pPrivate->HaveRaidResource && pPrivate->Process >= DRIVER_INSTALL){
		Status = SmcLsiRaidLib_DownLoad(&pPrivate->SmcLsiRaidOOBSetupProtocol);
		DEBUG((-1,"SmcLsiOOBSetupDriverDownload Status[%r]\n",Status));
		if(!EFI_ERROR(Status)) pPrivate->Process = DRIVER_DOWNLOAD;
	}
	return Status;
}
EFI_STATUS SmcLsiOOBSetupDriverLoadResource(SMC_LSI_RAID_OOB_SETUP_DRIVER*	pDriver){

	EFI_STATUS								Status			= EFI_NOT_READY;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			pPrivate 		= NULL;

	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupDriver,pDriver);

	//Temporary in here to check resoucre and Debug.
	if(pPrivate->Process == DRIVER_DOWNLOAD){
		
    	Status = LoadResources( pPrivate->DriverHandle,
                            	sizeof(SmcLsiOOBSetupCallBack)/sizeof(CALLBACK_INFO), 
                            	SmcLsiOOBSetupCallBack, 
                            	NULL 
                          		);
		
		DEBUG((-1,"SmcLsiOOBSetupDriverLoadResource LoadResources Status[%r]\n",Status));
		
		if(!EFI_ERROR(Status)) {
			pPrivate->HIIHandle = SmcLsiOOBSetupCallBack[0].HiiHandle;
			Status = SmcLsiRaidLib_AddDynamicItems(&pPrivate->SmcLsiRaidOOBSetupProtocol);

			DEBUG((-1,"SmcLsiOOBSetupDriverLoadResource AddRaidDynamicItems Status[%r]\n",Status));
		}
	}
	
	return Status;
}

EFI_STATUS	SmcLsiOOBSetupDriverGetNvData(SMC_LSI_RAID_OOB_SETUP_DRIVER*  pDriver, BOOLEAN  ReNew,OUT SMC_LSI_RAID_OOB_SETUP_NVSTRUCT*  pNVStruct){
	
	EFI_STATUS								Status 			= EFI_NOT_READY;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			pPrivate 		= NULL;

	if(pNVStruct == NULL) return EFI_BUFFER_TOO_SMALL;
/*
	if(pNVStruct->SmcRaidVarName 	!= NULL || 
	   pNVStruct->SmcRaidVarGuid 	!= NULL || 
	   pNVStruct->SmcRaidVarSize 	!= NULL ||
	   pNVStruct->SmcRaidVarBuffer	!= NULL)
		return EFI_INVALID_PARAMETER; 
*/
	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupDriver,pDriver);

	if(pPrivate->Process == DRIVER_DOWNLOAD){

		Status = SmcLsiRaidLib_ParseNvData(&pPrivate->SmcLsiRaidOOBSetupProtocol,
										   (!!ReNew),
										   &pNVStruct->SmcRaidVarName,
										   &pNVStruct->SmcRaidVarGuid,
										   &pNVStruct->SmcRaidVarSize,
										   &pNVStruct->SmcRaidVarBuffer);

//		DEBUG((-1,"SmcLsiRaidLib_ParseNvData Status[%r]\n",Status));
		return Status;
	}
	return Status;
}

EFI_STATUS	SmcLsiOOBSetupDriverCollectData(SMC_LSI_RAID_OOB_SETUP_DRIVER*  pDriver, CHAR16* VarName, EFI_GUID* VarGuid, UINTN VarSize, UINT8* VarBuffer){
	
	EFI_STATUS								Status 			= EFI_NOT_READY;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			pPrivate 		= NULL;

	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupDriver,pDriver);

	if(pPrivate->Process == DRIVER_DOWNLOAD){

		Status = SmcLsiRaidLib_CollectData(&pPrivate->SmcLsiRaidOOBSetupProtocol,VarName,VarGuid,VarSize,VarBuffer);

//		DEBUG((-1,"SmcLsiRaidLib_CollectData Status[%r]\n",Status));
		return Status;
	}
	return Status;
}

EFI_STATUS	SmcLsiOOBSetupDriverHandleDataStart(SMC_LSI_RAID_OOB_SETUP_DRIVER*  pDriver){
	
	EFI_STATUS								Status 			= EFI_NOT_READY;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			pPrivate 		= NULL;

	pPrivate = STRUCT_START(SMC_LSI_RAID_OOB_SETUP_PRIVATE,SmcLsiRaidOOBSetupDriver,pDriver);

	if(pPrivate->Process == DRIVER_DOWNLOAD){

		Status = SmcLsiRaidLib_HandleData(&pPrivate->SmcLsiRaidOOBSetupProtocol);

//		DEBUG((-1,"SmcLsiOOBSetupDriverHandleDataStart Status[%r]\n",Status));
		return Status;
	}
	return Status;
}


EFI_STATUS SmcLsiRaidOOBSetupEntry(
	IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
){
  
	EFI_STATUS	Status = EFI_SUCCESS;
	SMC_LSI_RAID_OOB_SETUP_PRIVATE*			SmcLsiRaidPrivateData = NULL;
	SMC_LSI_RAID_OOB_SETUP_DRIVER*			SmcLsiRaidOobSetupDriver = NULL;

	DEBUG((-1,"SmcLsiRaidOOBSetupEntry Entry\n"));

	InitAmiLib(ImageHandle, SystemTable);
	
	gBS->AllocatePool(EfiBootServicesData,sizeof(SMC_LSI_RAID_OOB_SETUP_PRIVATE),&SmcLsiRaidPrivateData);
	gBS->AllocatePool(EfiBootServicesData,sizeof(SMC_LSI_RAID_OOB_SETUP_DRIVER),&SmcLsiRaidOobSetupDriver);

	MemSet(SmcLsiRaidPrivateData,sizeof(SMC_LSI_RAID_OOB_SETUP_PRIVATE), 0x00);

	SmcLsiRaidOobSetupDriver->SmcLsiSetupDriverStart 			= SmcLsiOOBSetupDriverStart;
	SmcLsiRaidOobSetupDriver->SmcLsiSetupDriverDownload			= SmcLsiOOBSetupDriverDownload;
	SmcLsiRaidOobSetupDriver->SmcLsiSetupDriverLoadR			= SmcLsiOOBSetupDriverLoadResource;
	SmcLsiRaidOobSetupDriver->SmcLsiSetupDriverGetNvData		= SmcLsiOOBSetupDriverGetNvData;
	SmcLsiRaidOobSetupDriver->SmcLsiSetupDriverCollectData		= SmcLsiOOBSetupDriverCollectData;
	SmcLsiRaidOobSetupDriver->SmcLsiSetupDriverHandleDataStart	= SmcLsiOOBSetupDriverHandleDataStart;

	SmcLsiRaidPrivateData->DriverHandle					= ImageHandle;
	SmcLsiRaidPrivateData->HaveRaidResource				= FALSE;
	SmcLsiRaidPrivateData->Process						= DRIVER_INITIAL;

	MemCpy(&SmcLsiRaidPrivateData->SmcLsiRaidOOBSetupDriver,SmcLsiRaidOobSetupDriver,sizeof(SMC_LSI_RAID_OOB_SETUP_DRIVER));

	Status = gBS->InstallProtocolInterface(
				&SmcLsiRaidPrivateData->DriverHandle,
				&gSmcLsiRaidOobSetupDriverGuid,
				EFI_NATIVE_INTERFACE,
				&SmcLsiRaidPrivateData->SmcLsiRaidOOBSetupDriver
			);

	DEBUG((-1,"InstallProtocolInterface SmcLsiRaidOOBSetupDriver Status[%r]\n",Status));

    DEBUG((-1, "[SMC_OOB] :: SmcLsiRaidOOBSetupEntry End.\n"));
    return EFI_SUCCESS;
}
