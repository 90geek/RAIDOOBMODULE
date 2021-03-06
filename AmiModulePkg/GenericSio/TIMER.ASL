
//*************************************************************************
//*************************************************************************
//**                                                                     **
//**        (C)Copyright 1985-2010, American Megatrends, Inc.            **
//**                                                                     **
//**                       All Rights Reserved.                          **
//**                                                                     **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093           **
//**                                                                     **
//**                       Phone: (770)-246-8600                         **
//**                                                                     **
//*************************************************************************
//*************************************************************************
// $Header: /Alaska/BIN/Chipset/Intel/SouthBridge/CougarPoint_A/Chipset/ASL/Timer.asl 1     2/24/10 11:04p Tonywu $
//
// $Revision: 1 $
//
// $Date: 2/24/10 11:04p $
//**********************************************************************;
//**********************************************************************;
//-------------------------
// Timer
//-------------------------
Device(TMR) {
	Name(_HID,EISAID("PNP0100"))
	Name(_CRS, ResourceTemplate()
	{
		IO(Decode16, 0x40, 0x40, 0, 0x4)
		IRQNoFlags(){0}
	})
}	// End of TMR
//*************************************************************************
//*************************************************************************
//**                                                                     **
//**        (C)Copyright 1985-2010, American Megatrends, Inc.            **
//**                                                                     **
//**                       All Rights Reserved.                          **
//**                                                                     **
//**      5555 Oakbrook Parkway, Suite 200, Norcross, GA 30093           **
//**                                                                     **
//**                       Phone: (770)-246-8600                         **
//**                                                                     **
//*************************************************************************
//*************************************************************************
