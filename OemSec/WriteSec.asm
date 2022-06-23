;***********************************************************************
;*                                                                     *
;*                  Copyright (c) 1985-2020, AMI.                      *
;*                                                                     *
;*      All rights reserved. Subject to AMI licensing agreement.       *
;*                                                                     *
;***********************************************************************
;----------------------------------------------------------------------------
        INCLUDE token.equ
;----------------------------------------------------------------------------

.686p
.xmm
.model small, c
.code
EXTERN OemSecWriteInfoEnd:NEAR32

OemSecWriteInfo PROC PUBLIC

    mov dx,0xCF8     ;Store port CF8 in the DX register
    mov eax,0x800FA02C    ;Store the write address in the EAX register
    out dx,eax      ;Write the eax register contents to port CF8
    
    mov dx,0xCFC     ;Writes the read port to the DX register
    mov eax,0x12345678   ;The number to be modified is written to the EAX register
    out dx,eax      ;;Write the eax register contents to port CFC
    jmp OemSecWriteInfoEnd
    OemSecWriteInfo ENDP
END
