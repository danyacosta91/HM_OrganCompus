comment!
###############################################################################
subrutina frecuencia
entrada: esi apuntador a la lista de valores
         edi puntero donde se pondra el texto
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
frecuencia:
    push ax
    push bx
    push cx
    call ordenarLista
    mov edi,offset frecuenciatxt
frecuencia_next:
    mov ax,word ptr [esi]
    cmp ax,0
    je frecuencia_retornar
    mov cx,1
    push edi
    mov edi,esi
    inc edi
    inc edi
frecuencia_cmp:
    mov bx,word ptr [edi]
    cmp bx,ax
    jne frecuencia_incesi
    cmp bx,0
    je frecuencia_retornar
    inc cx
    inc edi
    inc edi
    jmp frecuencia_cmp
frecuencia_incesi:
    pop edi
    call bintotxt
    inc edi
    inc edi
    mov byte ptr [edi],32
    add edi,2
    mov byte ptr [edi],32
    add edi,2
    mov byte ptr [edi],32
    add edi,2
    mov ax,cx
    call bintotxt
    inc edi
    inc edi
    mov byte ptr [edi],10
    inc edi
    inc edi
frecuencia_saltos:
    inc esi
    inc esi
    dec cx
    cmp cx,0
    jne frecuencia_saltos
    jmp frecuencia_next
frecuencia_retornar:
    pop cx
    pop bx
    pop ax
    ret