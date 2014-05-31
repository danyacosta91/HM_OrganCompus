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
        texto db "Hola 10",0
        titulo db "Inversion",0
        mensaje db "El texto invertido es: "
        mensaje2 db "**************"
    .code
    start:
        mov edi,offset texto
        mov esi,offset mensaje2
        push 0
    ingresar:
        mov al,[edi]
        mov ah,0
        push ax
        inc edi
        cmp ax,0
        jne ingresar
        pop ax
    sacar:
        pop ax
        mov [esi],al
        inc esi
        cmp ax,0
        jne sacar
    imprimir:
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