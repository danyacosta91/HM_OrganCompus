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
     titulo db "Palindromo",0
     msg db "(1) si es palindromo, (0) si no es palindromo.",10
     mensaje db "La palabra:  "
     mensajel db "                                     "
     mensajel2 db " ,resultado: "
     palindroL db "                        ",0
     ini db "anitalavalatina",0
     fin equ $-2
.code
include bintotxt.inc
include removerEspacios.inc
include palindromo.inc
include cptxt.inc
start:
    mov esi,offset ini
    mov edi,offset mensajel
    call cptxt
    mov esi,offset ini
    mov edi,offset fin
    push bx
    push cx
    call palindromo
    pop cx
    pop bx
    mov edi,offset palindroL
    call bintotxt
    mov esi,offset mensaje
    mov edi,offset mensaje
    call removerEspacios
aimprimir:
    push MB_OKCANCEL
    push offset titulo
    push offset msg
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