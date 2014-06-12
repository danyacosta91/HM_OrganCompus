comment!
###############################################################################
subrutina lsttotxt
entrada: esi apuntador a la lista de valores
         edi puntero donde se pondra el texto
salida:  edi apuntara a donde se ponga el espacio en blanco al final del string
############################################################################### 
!
lsttotxt:
    push esi
    push ax
    cmp word ptr [esi],0
    je lsttotxt_listavacia
lsttotxt_next:
    cmp word ptr [esi],0
    je lsttotxt_alcero
    mov ax,[esi]
    call bintotxt
    add esi,2
    mov byte ptr [edi],44
    inc edi
    jmp lsttotxt_next
lsttotxt_alcero:
    dec edi
lsttotxt_listavacia:
    mov byte ptr [edi],32
    pop ax
    pop esi
    ret