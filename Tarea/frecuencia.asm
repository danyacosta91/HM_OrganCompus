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
     titulo db "Frecuencia",0
     mensaje db "En la lista: "
     mensajel db "                                     "
     mensajel2 db 13,10,"#    repite: ",13,10
     frecuenciatxt db "                                                                              ",0
     lista dw 23,21,22,13,23,13,0
.code
include bintotxt.inc
include removerEspacios.inc
include lsttotxt.inc
include frecuencia.inc
include ordenarLista.inc
start:
    mov esi,offset lista
    mov edi,offset mensajel
    call lsttotxt
    mov esi,offset lista
    mov edi,offset frecuenciatxt
    call frecuencia
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