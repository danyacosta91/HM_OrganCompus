; #########################################################################

      .386
      .model flat, stdcall    
      option casemap :none   ; case sensitive

; #########################################################################

      include \masm32\include\windows.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc

      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib

; #########################################################################
.data
     titulo db "Paint",0
     mensaje db "********",13,10
             db "*------*",13,10
             db "*-----**",13,10
             db "*---*-**",13,10
             db "*-**--**",13,10
             db "**--**-*",13,10
             db "*------*",13,10
             db "********",13,10,13,10
             db "********",13,10
             db "*------*",13,10
             db "*-----**",13,10
             db "*---*-**",13,10
             db "*-**--**",13,10
             db "**--**-*",13,10
             db "*------*",13,10
             db "********",0
     fila dw 2
     columna dw 3
.code
include paint.inc
include bintotxt.inc
start:
    mov ax,fila
    mov bx,columna
    call paint
aimprimir:
    push MB_OKCANCEL
    push offset titulo
    push offset mensaje
    push 0
    call MessageBox
    push 0
    call ExitProcess
    ; --------------------------------------------------------
    ; The following are the same function calls using MASM
    ; "invoke" syntax. It is clearer code, it is type checked
    ; against a function prototype and it is less error prone.
    ; --------------------------------------------------------

    ; invoke MessageBox,0,ADDR szMsg,ADDR szDlgTitle,MB_OK
    ; invoke ExitProcess,0

end start