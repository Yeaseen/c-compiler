.MODEL SMALL
.STACK 100H

.DATA

a2 dw ?
t1 dw ?
t2 dw ?
t3 dw ?
a3 dw ?
b3 dw ?
t4 dw ?
t5 dw ?
t6 dw ?


.CODE

MAIN PROC

MOV AX, @DATA
MOV DS, AX

mov ax,1
mov a3,ax
mov t4,1

mov ax,2
mov b3,ax
mov t5,1

push dx,0
ret 


MAIN ENDP



END MAIN

f proc near

push ax
push bx
push cx
push dx
mov dx,0
mov ax,2
mul a2
mov t1,ax

push dx,-2222
ret 
mov ax,9
mov a2,ax
mov t2,1



mov ax,
mov t3,ax
pop dx
pop cx
pop bx
pop ax
ret

f endp

