org 100h

Test_write_byte_hex:
mov dl,7bh
call Write_byte_hex
int 20h

Write_byte_hex:
push dx
mov cl, 04h
shr dl,cl
call Write_digit_hex
pop dx
and dl,0fh
call Write_digit_hex
ret

Write_digit_hex:
cmp dl,09h
ja 124h
add dl,30h
jmp 127h
add dl,37h
call Write_char
ret

Write_char:
push ax
mov ah,02h
int 21h
pop ax
ret
