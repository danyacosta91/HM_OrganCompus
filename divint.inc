comment!
###############################################################################
subrutina divint
entrada: ax valor de dividende
         bx valor de divisor
         cx valor entero
salida:  ax valor de entero de la division
############################################################################### 
!
divint:
    cmp ax,bx
    jl divint_retornar
    sub ax,bx
    call divint
    inc cx
divint_retornar:
    mov ax,cx
    ret
    