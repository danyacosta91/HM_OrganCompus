comment!
###############################################################################
subrutina bintotxt
entrada: esi apuntador a la lista de valores
         edi puntero donde se pondra el texto
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
cantImpares:
    push ax
    push esi
    push dx
    push cx
    push bx
    mov dx,0
    mov bx,0
    mov cl,2
    mov ax,word ptr [esi]
cantImpares_next:
    cmp ax,0
    je cantImpares_listavacia
    div cx
    cmp dx,0
    jne cantImpares_impar
    inc esi
    inc esi
    mov ax,word ptr [esi]
    mov dx,0
    jmp cantImpares_next
cantImpares_impar:
    inc bx
    inc esi
    inc esi
    mov ax,word ptr [esi]
    mov dx,0
    jmp cantImpares_next
cantImpares_listavacia:
    mov ax,bx
    call bintotxt
    pop bx
    pop cx
    pop dx
    pop esi
    pop ax
    ret