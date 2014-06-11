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
     titulo db "Maximo Comun Divisor",0
     mensaje db "El maximo comun divisor de:  "
     mensajel db "                                     "
     msg db " y "
     mensajel1 db "                                     "
     mensajel2 db " es: "
     mcdL db "                        ",0
     valor1 dw 1000
     valor2 dw 750
.code
include bintotxt.inc
include removerEspacios.inc
include mcd.inc
start:
    mov ax,valor1
    mov edi,offset mensajel
    call bintotxt
    mov ax,valor2
    mov edi,offset mensajel1
    call bintotxt
    mov ax,valor1
    mov bx,valor2
    call mcd
    mov edi,offset mcdL
    call bintotxt
    mov esi,offset mensaje
    mov edi,offset mensaje
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