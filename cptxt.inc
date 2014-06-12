comment!
###############################################################################
subrutina cptxt
entrada: esi apuntador a inicio de palabra
         edi apuntador donde se copiara la palabra
salida:  edi palabra copiada a lo que apuntaba edi
############################################################################### 
!
cptxt:
    mov al,[esi]
    mov ah,0
    cmp ax,0
    je cptxt_retornar
    mov [edi],al
    inc esi
    inc edi
    jmp cptxt
cptxt_retornar:
    ret
    