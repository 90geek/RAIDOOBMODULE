//*****************************************************************//
//*****************************************************************//
//*****************************************************************//
//**                                                             **//
//**        (C)Copyright 1985-2010, American Megatrends, Inc.    **//
//**                                                             **//
//**                     All Rights Reserved.                    **//
//**                                                             **//
//**             5555 Oakbrook Pkwy   , Norcross, GA 30071       **//
//**                                                             **//
//**                       Phone: (770)-246-8600                 **//
//**                                                             **//
//*****************************************************************//
//*****************************************************************//
//*****************************************************************//
// $Archive: /Alaska/SOURCE/Modules/AMITSE2_0/AMITSE/TseLite/StyleHook/styleHook31.c $
//
// $Author: Madhans $
//
// $Revision: 1 $
//
// $Date: 1/06/11 7:36p $
//
//*****************************************************************//
//*****************************************************************//
//*****************************************************************//
/** @file styleHook31.c
    Contains generic or default style functions.

**/
//**********************************************************************
#include "minisetup.h"



/**
    This function is called whenever a user returns (or navigates back) 
    from a submenu page causing a complete page redraw. OEMs may use this hook to set item focus. 
    The default behavior sets focus to the previously focused page item. 

    @param page FRAME_DATA *frame 
				
    @retval VOID

**/
VOID StyleSubPageItemFocus(PAGE_DATA *page, FRAME_DATA *frame )
{
}
//*****************************************************************//
//*****************************************************************//
//**                                                             **//
//**        (C)Copyright 1985-2010, American Megatrends, Inc.    **//
//**                                                             **//
//**                       All Rights Reserved.                  **//
//**                                                             **//
//**             5555 Oakbrook Pkwy   , Norcross, GA 30071       **//
//**                                                             **//
//**                       Phone: (770)-246-8600                 **//
//**                                                             **//
//*****************************************************************//
//*****************************************************************//
