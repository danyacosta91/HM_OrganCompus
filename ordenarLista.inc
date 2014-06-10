comment!
###############################################################################
subrutina bintotxt
entrada: esi apuntador a la lista de valores
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
ordenarLista:
    push ax
    push bx
    push cx
    push esi
    mov ax,word ptr [esi]
ordenarLista_next:
    cmp ax,0
    je ordenarLista_listavacia
    mov edi,esi
    add edi,2
    mov bx,word ptr [edi]
ordenarLista_preguntar:
    cmp bx,0
    je ordenarLista_incEsi
    cmp bx,ax
    jl ordenarLista_mayor
    add edi,2
    mov bx,word ptr [edi]
    jmp ordenarLista_preguntar
ordenarLista_incEsi:
    add esi,2
    mov ax,word ptr [esi]
    jmp ordenarLista_next
ordenarLista_mayor:
    mov word ptr [esi],bx
    mov word ptr [edi],ax
    add edi,2
    mov bx,word ptr [edi]
    mov ax,word ptr [esi]
    jmp ordenarLista_preguntar
ordenarLista_listavacia:
    pop esi
    pop cx
    pop bx
    pop ax
    ret