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
     titulo db "Mayor Elemento",0
     mensaje db "El elemento menor de la lista: "
     mensajel db "                                     "
     mensajel2 db " es: "
     menortxt db "               ",0
     lista dw 12,20,30,12,4,8,16,0
.code
include bintotxt.inc
include removerEspacios.inc
include lsttotxt.inc
include menorlst.inc
start:
    mov esi,offset lista
    mov edi,offset mensajel
    call lsttotxt
    mov esi,offset lista
    mov edi,offset menortxt
    call menorlst
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