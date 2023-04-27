section .data
fmt db "Hello, Holberton",0xA,0
len equ $-fmt

section .text
global main

main:
push fmt
call printf
add esp, 4
mov eax, 1
xor ebx, ebx
int 0x80

extern printf
