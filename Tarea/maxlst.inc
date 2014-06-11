comment!
###############################################################################
subrutina maxlst
entrada: esi apuntador a la lista de valores
         edi puntero donde se pondra el texto
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
maxlst:
    push ax
    push esi
    push cx
    mov ax,word ptr [esi]
    mov cx,ax
maxlst_next:
    cmp ax,0
    je maxlst_listavacia
    cmp cx,ax
    jl maxlst_mayor
    inc esi
    inc esi
    mov ax,word ptr [esi]
    jmp maxlst_next
maxlst_mayor:
    mov cx,ax
    inc esi
    inc esi
    mov ax,word ptr [esi]
    jmp maxlst_next
maxlst_listavacia:
    mov ax,cx
    call bintotxt
    pop cx
    pop esi
    pop ax
    ret