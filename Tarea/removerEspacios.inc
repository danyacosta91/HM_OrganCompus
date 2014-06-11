comment!
###############################################################################
subrutina removerEspacios
entrada: edi puntero donde se pondra el texto
         esi puntero donde se pondra el texto
salida:  esi apuntara al siguiente caracter despues de haber puesto el texto
############################################################################### 
!
removerEspacios:
    push cx
    push esi
    mov cl,1 ;dl es "ignorar espacio"
removerEspacios_next:
    cmp byte ptr [esi],0
    je removerEspacios_elcero
    cmp byte ptr [esi],32
    je removerEspacios_espacio
    mov cl,0
removerEspacios_copiar:
    ;mov byte ptr [edi],[esi]
    mov ch,[esi]
    mov [edi],ch
    inc edi
removerEspacios_incesi:
    inc esi
    jmp removerEspacios_next
removerEspacios_espacio:
    cmp cl,1
    je removerEspacios_incesi
    mov cl,1
    jmp removerEspacios_copiar
removerEspacios_elcero:
    mov esi,edi
    dec esi
    cmp byte ptr [edi],0
    jne removerEspacios_aretornar
removerEspacios_aretornar:
    mov byte ptr [edi],0
    inc edi
    dec esi
    pop esi
    pop cx
    ret