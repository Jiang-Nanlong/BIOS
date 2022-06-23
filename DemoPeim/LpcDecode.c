//***********************************************************************
//*                                                                     *
//*   Copyright (c) 1985-2019, American Megatrends International LLC.   *
//*                                                                     *
//*      All rights reserved. Subject to AMI licensing agreement.       *
//*                                                                     *
//***********************************************************************

#include <AmiDxeLib.h>
#include <Library/PciLib.h>

EFI_STATUS LpcDecodeEntryPoint(
     IN  EFI_PEI_FILE_HANDLE   FileHandle,
     IN CONST EFI_PEI_SERVICES     *PeiServices
)
{
    //InitAmiLib(ImageHandle,SystemTable);
    static UINT16 LpcRegisterContents = PciRead16(0x80);  //寄存器内的值
    int Bit12 = (int)((LpcRegisterContents >> 12)& 0x1);    //第12位bit值
    int Bit9To8 = (int)((LpcRegisterContents >> 8)& 0x3);    //获取第8-9位bit的值
    int Bit6To4 = (int)((LpcRegisterContents >> 4)& 0x3);    //获取第4-6位bit的值
    int Bit2To0 = (int)(LpcRegisterContents & 0x3);       //获取第2位bit的值
    if(Bit12)
            printf("FDD Decode Range : 3F0h - 3F5h,3F7h");
        else
            printf("FDD Decode Range : 370h - 375h,377h");

    switch(Bit9To8)
    {
        case 0:
            printf("LPT Decode Range : 378h - 37Fh and 778h - 77Fh");
            break;
        case 1:
            printf("LPT Decode Range : 278h - 27Fh and 678h - 67Fh");
            break;
        case 2:
            printf("LPT Decode Range : 3BCh - 3BEh and 78Ch - 78Eh");
            break;
        case 3:
            break;
    }
    switch(Bit6To4)
        {
            case 0:
                printf("ComB Decode Range : 3F8h-3FFh(COM1)");
                break;
            case 1:
                printf("ComB Decode Range : 2F8h - 2FFh(COM2)");
                break;
            case 2:
                printf("ComB Decode Range : 220h-227h");
                break;
            case 3:
                printf("ComB Decode Range : 228h-22Fh");
                break;
            case 4:
                printf("ComB Decode Range : 238h-23Fh");
                break;
            case 5:
                printf("ComB Decode Range : 2E8h-2EFh(COM4)");
                break;
            case 6:
                printf("ComB Decode Range : 338h-33Fh");
                break;
            case 7:
                printf("ComB Decode Range : 3E8h-3EFh(COM3)");
                break;
        }
    switch(Bit2To0)
        {
            case 0:
                printf("ComA Decode Range : 3F8h-3FFh(COM1)");
                break;
            case 1:
                printf("ComA Decode Range : 2F8h - 2FFh(COM2)");
                break;
            case 2:
                printf("ComA Decode Range : 220h-227h");
                break;
            case 3:
                printf("ComA Decode Range : 228h-22Fh");
                break;
            case 4:
                printf("ComA Decode Range : 238h-23Fh");
                break;
            case 5:
                printf("ComA Decode Range : 2E8h-2EFh(COM4)");
                break;
            case 6:
                printf("ComA Decode Range : 338h-33Fh");
                break;
            case 7:
                printf("ComA Decode Range : 3E8h-3EFh(COM3)");
                break;
        }
    return EFI_SUCCESS;
}
