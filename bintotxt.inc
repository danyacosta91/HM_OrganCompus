comment!
###############################################################################
subrutina bintotxt
entrada: ax  valor en binario
         edi puntero donde se pondra el texto
salida:  edi apuntara al siguiente caracter despues de haber puesto el texto
############################################################################### 
!
bintotxt:
    push ax
    push bx 
    push ecx
    push dx
    mov ecx,0
    mov bx,10
    bintotxt_lazo:
        cmp ax,0
        je bintotxt_asacar
        inc ecx
        mov dx,0
        div bx
        push dx
        jmp bintotxt_lazo
    bintotxt_asacar:
        cmp ecx,0
        je bintotxt_eracero
    bintotxt_lazo2:
        pop ax
        add ax,48
        mov [edi],al
        inc edi
        loop bintotxt_lazo2
        jmp bintotxt_aretornar
    bintotxt_eracero:
        mov al,'0';es equivalente a escribir mov al,48
        mov [edi],al
        inc edi
    bintotxt_aretornar:        
        pop dx
        pop ecx
        pop bx
        pop ax
        ret