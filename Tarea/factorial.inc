comment!
###############################################################################
subrutina factorial
entrada: ax valor que se quiere sacar el factorial
salida:  ax factorial retornado
############################################################################### 
!
factorial:
    push bx
    push dx
    cmp ax,1
    je factorial_casobase
    mov bx,ax
    dec ax
    call factorial
    mul bx
factorial_casobase:
    pop dx
    pop bx
    ret