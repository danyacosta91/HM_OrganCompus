comment!
###############################################################################
subrutina menorlst
entrada: esi apuntador a la lista de valores
         edi puntero donde se pondra el texto
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
menorlst:
    push ax
    push esi
    push cx
    mov ax,word ptr [esi]
    mov cx,ax
menorlst_next:
    cmp ax,0
    je menorlst_listavacia
    cmp cx,ax
    jg menorlst_menor
    inc esi
    inc esi
    mov ax,word ptr [esi]
    jmp menorlst_next
menorlst_menor:
    mov cx,ax
    inc esi
    inc esi
    mov ax,word ptr [esi]
    jmp menorlst_next
menorlst_listavacia:
    mov ax,cx
    call bintotxt
    pop cx
    pop esi
    pop ax
    ret