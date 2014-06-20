comment!
###############################################################################
subrutina ackerman
entrada: ax valor de "m"
         bx valor de "n"
salida:  ax resultado
############################################################################### 
!
ackerman:
    cmp ax,0
    je ackerman_casobase
ackerman_mayor:
    dec ax
    cmp bx,0
    je ackerman_decm
ackerman_decn:
    push ax
    inc ax
    dec bx
    call ackerman
    pop ax
    call ackerman
    ret
ackerman_decm:
    mov bx,1
    call ackerman
    ret
ackerman_casobase:
    inc bx
    mov ax,bx
    ret