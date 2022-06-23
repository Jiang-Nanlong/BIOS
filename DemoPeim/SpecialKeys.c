//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *
//*                                                                     *
//*      All rights reserved. Subject to AMI licensing agreement.       *
//*                                                                     *
//***********************************************************************

#include <AmiDxeLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>

#define KEYBORAD_STATUS_BYTE 0X17
EFI_STATUS KeysOfKeyboardEntryPoint(
        IN  EFI_PEI_FILE_HANDLE   FileHandle,
        IN CONST EFI_PEI_SERVICES     *PeiServices
)
{
	//InitAmiLib(ImageHandle,SystemTable);
    UINT16 KeyboardStatus = MmioRead16(KEYBORAD_STATUS_BYTE);
    if(KeyboardStatus&0x80)
        DEBUG((DEBUG_INFO,"insert mode on"));
    else
        DEBUG((DEBUG_INFO,"insert mode off"));
    if(KeyboardStatus&0x600)
        DEBUG((DEBUG_INFO,"<Caps Lock>key on"));
    else
        DEBUG((DEBUG_INFO,"<Caps Lock>key off"));
    if(KeyboardStatus&0x30)
        DEBUG((DEBUG_INFO,"<Num Lock>key on"));
    else
        DEBUG((DEBUG_INFO,"<Num Lock>key off"));
    if(KeyboardStatus&0x10)
        DEBUG((DEBUG_INFO,"<Scroll Lock>key on"));
    else
        DEBUG((DEBUG_INFO,"<Scroll Lock>key off"));
    if(KeyboardStatus&0x8)
        DEBUG((DEBUG_INFO,"<Alt>key passed"));
    else
        DEBUG((DEBUG_INFO,"<Alt>key not passed"));
    if(KeyboardStatus&0x6)
        DEBUG((DEBUG_INFO,"<Ctrl>key passed"));
    else
        DEBUG((DEBUG_INFO,"<Ctrl>key not passed"));
    if(KeyboardStatus&0x3)
        DEBUG((DEBUG_INFO,"Left <Shift>key passed"));
    else
        DEBUG((DEBUG_INFO,"Left <Shift>key not passed"));
    if(KeyboardStatus&0x1)
        DEBUG((DEBUG_INFO,"Right <Shift>key passed"));
    else
        DEBUG((DEBUG_INFO,"Right <Shift>key not passed"));
    if(KeyboardStatus&0x8000)
        DEBUG((DEBUG_INFO,"<Ins>key passed"));
    else
        DEBUG((DEBUG_INFO,"<Ins>key not passed"));
    if(KeyboardStatus&0x6000)
        DEBUG((DEBUG_INFO,"<Caps Lock>key passed"));
    else
        DEBUG((DEBUG_INFO,"<Caps Lock>key not passed"));
    if(KeyboardStatus&0x3000)
        DEBUG((DEBUG_INFO,"<Num Lock>key passed"));
    else
        DEBUG((DEBUG_INFO,"<Num Lock>key not passed"));
    if(KeyboardStatus&0x1000)
        DEBUG((DEBUG_INFO,"<Scroll Lock> passed"));
    else
        DEBUG((DEBUG_INFO,"<Scroll Lock> not passed"));
    if(KeyboardStatus&0x800)
        DEBUG((DEBUG_INFO,"<Ctrl><Num Lock>state active"));
    else
        DEBUG((DEBUG_INFO,"<Ctrl><Num Lock>state not active"));
    if(KeyboardStatus&0x600)
        DEBUG((DEBUG_INFO,"<SysReq>key passed"));
    else
        DEBUG((DEBUG_INFO,"<SysReq>key not passed"));
    if(KeyboardStatus&0x300)
        DEBUG((DEBUG_INFO,"Left <Alt>key passed"));
    else
        DEBUG((DEBUG_INFO,"Left <Alt>key not passed"));
    if(KeyboardStatus&0x100)
        DEBUG((DEBUG_INFO,"Left <Ctrl>key passed"));
    else
        DEBUG((DEBUG_INFO,"Left <Ctrl>key not passed"));
    
	return EFI_SUCCESS;
}

