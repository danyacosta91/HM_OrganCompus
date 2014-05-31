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
        titulo db "Programa de Suma",0
        mensaje db "La Suma es: "
        mensajer db "           ",0
        
    .code
    start:
        mov ax,valor1
        add ax,valor2
        mov ecx,0
        mov bx,10
        mov esi,offset mensajer
    lazo:
        cmp ax,0
        je asacar
        inc ecx
        mov dx,0
        div bx
        push dx
        jmp lazo
    asacar:
        cmp ecx,0
        je eracero
    lazo2:
        pop ax
        add ax,48
        mov [esi],al
        inc esi
        loop lazo2
        jmp aimprimir
    eracero:
        mov al,'0';es equivalente a escribir mov al,48
        mov [esi],al
        inc esi
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