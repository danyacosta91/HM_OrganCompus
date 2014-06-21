comment!
###############################################################################
subrutina ordenarTexto
entrada: esi apuntador a la lista de valores
############################################################################### 
!
ordenarTexto:
    push ax
    push bx
    push cx
    push esi
    mov al,byte ptr [esi]
    mov ah,0
ordenarTexto_next:
    cmp ax,0
    je ordenarTexto_listavacia
    mov edi,esi
    inc edi
    mov bl,byte ptr [edi]
    mov bh,0
ordenarTexto_preguntar:
    cmp bx,0
    je ordenarTexto_incEsi
    cmp bx,ax
    jl ordenarTexto_mayor
    inc edi
    mov bl,byte ptr [edi]
    mov bh,0
    jmp ordenarTexto_preguntar
ordenarTexto_incEsi:
    inc esi
    mov al,byte ptr [esi]
    mov ah,0
    jmp ordenarTexto_next
ordenarTexto_mayor:
    mov byte ptr [esi],bl
    mov byte ptr [edi],al
    inc edi
    mov bl,byte ptr [edi]
    mov al,byte ptr [esi]
    mov bh,0
    mov ah,0
    jmp ordenarTexto_preguntar
ordenarTexto_listavacia:
    pop esi
    pop cx
    pop bx
    pop ax
    ret