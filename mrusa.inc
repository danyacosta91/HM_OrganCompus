comment!
###############################################################################
subrutina mrusa
entrada: ax multiplicando "m"
         bx multiplicador "n"
         si temporal a "m" para caso impar
salida:  ax multiplicacion
############################################################################### 
!
mrusa:
    push bx
    push cx
    push dx
    mov dx,0
    mov cx,2
    cmp bx,1
    je mrusa_casobase
mrusa_next:
    push bx
    mov bx,2
    mul bx
    pop bx
    push ax
    mov ax,bx
    div cx
    mov bx,ax
    pop ax
    cmp dx,0
    je mrusa_par
mrusa_impar:
    cmp bx,1
    mov dx,0
    je mrusa_casobase
    push ax
    mov cx,2
    div cx
    add si,ax
    pop ax
    call mrusa
    jmp mrusa_casobase
mrusa_par:    
    call mrusa
mrusa_casobase:
    pop dx
    pop cx
    pop bx
    ret