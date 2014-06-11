comment!
###############################################################################
subrutina fibonacci
entrada: ax valor que se quiere sacar el fibonacci
salida:  ax fibonacci retornado
############################################################################### 
!
fibonacci:
    push bx
    push cx
    push dx
    mov cx,1
    mov bx,cx
    dec ax
    dec ax
 fibonacci_casobase:   
    cmp ax,0
    je fibonacci_retornar
    mov dx,cx
    add cx,bx
    mov bx,dx
    dec ax
    jmp fibonacci_casobase
fibonacci_retornar:
    mov ax,cx
    pop dx
    pop cx
    pop bx
    ret