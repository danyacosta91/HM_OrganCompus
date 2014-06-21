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
     titulo db "Letra Repitente",0
     texto db "UNIVERSIDAD TECNOLOGICA CENTROAMERICANA",0
     mensaje db "En el texto: "
     mensajel db "                                              "
     mensajel2 db " La letra que mas se repite es la: "
     repitetxt db "                                                           ",0
.code
include removerEspacios.inc
include repite.inc
include cptxt.inc
include ordenarTexto.inc
start:
    mov esi,offset texto
    mov edi,offset mensajel
    call cptxt
    mov esi,offset texto
    mov edi,offset repitetxt
    call repite
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