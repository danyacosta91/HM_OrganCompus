comment!
###############################################################################
subrutina Numero Primo
entrada: ax valor que se quiere saber si es primo
salida:  ax primo retornado
############################################################################### 
!
nprimo:
    push bx
    push cx
    push dx
    mov cx,0
    mov bx,0
    cmp ax,2
    je nprimo_casobase
    
nprimo_proceso:
    inc cx
    mov dx,0
    push ax
    div cx
    pop ax
    cmp dx,0
    jne nprimo_proceso
    inc bx
    cmp ax,cx
    jne nprimo_proceso
    jmp nprimo_seraprimo
    
nprimo_seraprimo:
    cmp bx,2
    jg nprimo_noprimo
    mov ax,1
    jmp nprimo_imprimir    

nprimo_noprimo:
    mov ax,0
    jmp nprimo_imprimir

nprimo_casobase:
    mov ax,1
    jmp nprimo_imprimir

nprimo_imprimir:
    pop dx
    pop cx
    pop bx
    ret