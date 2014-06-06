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
     valor1 dw 1000
     valor2 dw 1500
     titulo db "Programa de suma",0
     mensaje db "La suma de "
     valor1t db "                y "
     valor2t db "                es "
     mensajer db "                ",0
.code
include bintotxt.inc
include removerEspacios.inc
start:
    mov ax,valor1
    mov edi,offset valor1t
    call bintotxt
    mov edi,offset valor1t
    mov ax,valor2
    mov edi,offset valor2t
    call bintotxt
    add ax,valor1
    mov edi,offset mensaje
    call bintotxt
    mov esi,offset mensaje
    mov edi,esi
    call removerEspacios
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