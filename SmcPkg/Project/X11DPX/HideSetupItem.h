//****************************************************************************
//**                                                                        **
//**            (C)Copyright 1993-2016 Supermicro Computer, Inc.            **
//**                                                                        **
//****************************************************************************
//  File History
//
//  Rev. 1.00
//    Bug Fix:  Initialize revision
//    Reason:
//    Auditor:  Hartmann Hsieh
//    Date:     Dec/27/2016
//
//****************************************************************************
//****************************************************************************

//**********************************************************************
//<AMI_FHDR_START>
//
// Name:        HideSetupItem.h
//
// Description: Add hide setup items for the project.
//
//<AMI_FHDR_END>
//**********************************************************************

#ifndef __SMC_HIDESETUPITEM__H__
#define __SMC_HIDESETUPITEM__H__

VOID X11DPXHideSetupItem (
    IN EFI_EVENT Event,
    IN VOID *Context
);

#endif // __SMC_HIDESETUPITEM__H__

