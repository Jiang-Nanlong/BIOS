//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *
//*                                                                     *
//*      All rights reserved. Subject to AMI licensing agreement.       *
//*                                                                     *
//***********************************************************************

#include <AmiDxeLib.h>
#include <Library/CpuCspLib.h>

EFI_STATUS GetCpuInfoEntryPoint(
	IN EFI_HANDLE ImageHandle,
	IN EFI_SYSTEM_TABLE *SystemTable
)
{
    UINT32 RegEax, RegEbx, RegEcx, RegEdx;
	InitAmiLib(ImageHandle,SystemTable);
	CPULib_CpuID(0, &RegEax, &RegEbx, &RegEcx, &RegEdx);
	DEBUG((-1,"///*************************************\n"));
	DEBUG((-1,"RegEbx:%x\n",RegEbx));
	DEBUG((-1,"RegEbx:%x\n",RegEcx));
	DEBUG((-1,"RegEbx:%x\n",RegEdx));
	
	CPULib_CpuID(1, &RegEax, &RegEbx, &RegEcx, &RegEdx);
	DEBUG((-1,"stepping ID:%x\n",(RegEax&0xF)));        //stepping ID
	DEBUG((-1,"model:%x\n",((RegEax>>4)&0xF)));         //model
	DEBUG((-1,"family ID:%x\n",((RegEax>>8)&0xF)));     //family ID
	DEBUG((-1,"extended model ID:%x\n",((RegEax>>16)&0xF)));        //extended model ID
	DEBUG((-1,"extended family ID:%x\n",((RegEax>>20)&0xFF)));      //extended family ID
	DEBUG((-1,"///*************************************\n"));
	
	return EFI_SUCCESS;
}

