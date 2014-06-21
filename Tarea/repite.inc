comment!
###############################################################################
subrutina repite
entrada: esi apuntador a la lista de valores
         edi puntero donde se pondra el texto
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
repite:
    call ordenarTexto
    mov esi,offset texto
    mov edi,offset texto
    call removerEspacios
    push ax
    push bx
    push cx
    push dx
    mov esi,offset texto
    mov edi,offset repitetxt
    push edi
    mov dx,0
repite_next:
    mov al,byte ptr [esi]
    mov ah,0
    cmp ax,0
    je repite_retornar
    mov cx,1
    mov edi,esi
    inc edi
repite_cmp:
    mov bl,byte ptr [edi]
    mov bh,0
    cmp bx,ax
    jne repite_incesi
    cmp bx,0
    je repite_retornar
    inc cx
    inc edi
    jmp repite_cmp
repite_incesi:
    cmp dl,cl
    jl repite_incdx
repite_saltos:
    inc esi
    dec cx
    cmp cx,0
    jne repite_saltos
    jmp repite_next
repite_incdx:
    mov dl,cl
    dec edi
    mov dh,byte ptr [edi]
repite_retornar:
    pop edi
    mov byte ptr [edi],dh
    pop dx
    pop cx
    pop bx
    pop ax
    ret