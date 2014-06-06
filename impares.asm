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
     titulo db "Cantidad de impares",0
     mensaje db "La lista de valores es: "
     mensajel db "                                     "
     mensajel2 db " tiene: "
     impartxt db "               numeros impares",0
     lista dw 1051,358,1420,11,51,0
.code
include bintotxt.inc
include removerEspacios.inc
include lsttotxt.inc
include cantImpares.inc
start:
    mov esi,offset lista
    mov edi,offset mensajel
    call lsttotxt
    mov esi,offset lista
    mov edi,offset impartxt
    call cantImpares
    mov edi,offset mensaje
    mov esi,offset mensaje
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