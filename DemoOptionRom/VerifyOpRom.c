//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *

#include <AmiDxeLib.h>
#include <Library/IoLib.h>
#include <Library/DebugLib.h>
#include <Library/PciLib.h>

EFI_STATUS VerifyOpRomEntryPoint(
        IN EFI_HANDLE       ImageHandle,
            IN EFI_SYSTEM_TABLE *SystemTable
)
{
    UINT16 bus,dev,func,count = 0;
    InitAmiLib(ImageHandle, SystemTable);
    for(bus=0;bus<256;bus++)
    {
        for(dev=0;dev<32;dev++)
        {
            for(func=0;func<8;func++)
            {
                UINT32 dwData0=0,dwData1 = 0;
                dwData0 = PciRead32(PCI_LIB_ADDRESS(bus,dev,func,0));
                dwData1 = PciRead32(PCI_LIB_ADDRESS(bus,dev,func,0x30));
                if(dwData0!=0xFFFFFFFF)
                {
                    if(dwData1!=0x0)
                    {
                        count++;
                        DEBUG((-1,"Expansion ROM Base Address:%x\n",dwData1));
                    }
                    else
                    {
                        DEBUG((-1,"The device's expansion ROM address space is disabled."));
                        DEBUG((-1,"%x %x %x\n",bus,dev,func));
                    }
                }
            }
        }
    }
    DEBUG((-1,"ADDRESS:%x\n",PCI_LIB_ADDRESS(0,31,2,0)));
    DEBUG((-1,"ADDRESS:%x\n",PCI_LIB_ADDRESS(0,31,2,0x2C)));
    DEBUG((-1,"Find PCI Device %d\n",count));
    return EFI_SUCCESS;
}
