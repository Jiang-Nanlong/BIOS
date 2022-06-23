//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *
//*                                                                     *
//*      All rights reserved. Subject to AMI licensing agreement.       *
//*                                                                     *
//***********************************************************************

#include <AmiDxeLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>

#define PCI_CONFIG_ADDRESS 0xcf8    //PCI address port
#define PCI_CONFIG_DATA 0xcfc       //PCI data port
/*
 * There are up to 256 PCI buses in the system,
 * each bus has a maximum of 32 devices, 
 * each device has up to 8 functions, 
 * and each function has a configuration space of 256 bytes,
 * so the total configuration space is 16M.
 * */
EFI_STATUS ParseConfigurationSpaceEntryPoint(
        IN  EFI_PEI_FILE_HANDLE   FileHandle,
        IN CONST EFI_PEI_SERVICES     *PeiServices
)
{
    int bus,dev,func,count = 0;
    UINT32 dwData0,dwData1,dwData2,dwAddr;
    UINT16 VID,DID,dwClassCode,RID,SVID,SID;

    for(bus=0;bus<256;bus++)
    {
        for(dev=0;dev<32;dev++)
        {
            for(func=0;func<8;func++)
            {
                dwAddr = BIT31|((bus & 0XFF)<< 16)|((dev & 0x1F)<<11)|((func & 0x7) << 8);
                IoWrite32(PCI_CONFIG_ADDRESS, dwAddr);
                dwData0 = IoRead32(PCI_CONFIG_DATA);
                IoWrite32(PCI_CONFIG_ADDRESS, dwAddr+0x8);
                dwData1 = IoRead32(PCI_CONFIG_DATA);
                IoWrite32(PCI_CONFIG_ADDRESS, dwAddr+0x2c);
                dwData2 = IoRead32(PCI_CONFIG_DATA);
                if(dwData0!=0xffffffff && dwData1!=0xffffffff && dwData2!=0xffffffff)
                {
                    count++;
                    VID=dwData0&0xffff;
                    DID=(dwData0>>16)&0xffff;
                    RID=dwData1&0xff;
                    dwClassCode=(dwData1>>8)&0xffffff;
                    SVID=dwData2&0xffff;
                    SID=(dwData2>>16)&0xffff;
                    DEBUG((DEBUG_INFO,"%04x\t%04x\t%02x\t%06x\t%04x\t%04x\t%02x\t%02x\t%02x\n",VID,DID,RID,dwClassCode,SVID,SID,bus,dev,func));
                }
            }
        }
    }
    DEBUG((DEBUG_INFO,"Find PCI Device %d",count));
	return EFI_SUCCESS;
}

