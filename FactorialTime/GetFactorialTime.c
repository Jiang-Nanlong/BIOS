//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *
//*                                                                     *
//*      All rights reserved. Subject to AMI licensing agreement.       *
//*                                                                     *
//***********************************************************************

#include <AmiDxeLib.h>
#include <Include\AmiLib.h>

EFI_STATUS GetFactorialTimeEntryPoint(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
)
{
    UINT64 begin,end,time=0;
    UINT64 result = 1,i=1;
    InitAmiLib(ImageHandle,SystemTable);
    begin = GetCpuTimer();
    for(i=1;i<=10;i++)
    {
        result = result * i;
    }
    end = GetCpuTimer();
    time = end - begin;
    DEBUG((-1,"The program running time is:%d\n",time));
	return EFI_SUCCESS;
}

