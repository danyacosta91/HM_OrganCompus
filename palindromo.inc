comment!
###############################################################################
subrutina palindromo
entrada: esi apuntador a inicio de palabra
         edi apuntador a final de palabra
salida:  ax valor 0 o 1 si es o no palindromo
############################################################################### 
!
palindromo:
    mov bl,[esi]
    mov bh,0
    mov cl,[edi]
    mov ch,0
    cmp bx,cx
    jne palindromo_falso
    jge palindromo_verdadero
    inc esi
    dec edi
    call palindromo
palindromo_falso:
    mov ax,0
    ret
palindromo_verdadero:
    mov ax,1
    ret
    