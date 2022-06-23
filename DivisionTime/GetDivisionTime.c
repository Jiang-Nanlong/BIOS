//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *
//*                                                                     *
//*      All rights reserved. Subject to AMI licensing agreement.       *
//*                                                                     *
//***********************************************************************

#include <AmiDxeLib.h>
#include <Include\AmiLib.h>

EFI_STATUS GetDivisionTimeEntryPoint(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
)
{
    UINT64 begin,end,time=0;
	InitAmiLib(ImageHandle,SystemTable);
	begin = GetCpuTimer();
	int result = 1/1;
	end = GetCpuTimer();
	time = end - begin;
	DEBUG((-1,"The program running time is:%d\n",time));
	return EFI_SUCCESS;
}

