comment!
###############################################################################
subrutina mcd
entrada: ax valor que se quiere sacar el factorial
         bx
salida:  ax factorial retornado
############################################################################### 
!
mcd:
    push bx
    cmp ax,bx
    je mcd_casobase
    jg mcd_mayor
    sub bx,ax
    call mcd
    jmp mcd_casobase
mcd_mayor:
    sub ax,bx
    call mcd
mcd_casobase:
    pop bx
    ret