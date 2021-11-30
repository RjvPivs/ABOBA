;(void* arr, void* indexes, int len)
global BinSort
BinSort:
section .data							
section .text							
        push rbp
        mov rbp,rsp
        mov rdi,rdi;arr
        mov rsi,rsi; indexes
        mov rdx, rdx; len
        mov r8, 1; index i
        mov r9, 0;index j

bigloop:
    cmp r8, rdx
    jge exit
    movsd xmm0,qword[rdi+r8*8];r10=rsi[i], key r10 to xmm0
    movsd xmm1, qword[rsi+r8*8]; key index r15 to xmm1
    call position
    mov r9, r8
    dec r9
    mov rcx, 1
    loop fff
    movsd qword[rdi+r11*8], xmm0
    movsd qword[rsi, r11*8], xmm1
    mov r11, 0; start is 0 again
    inc r8
    cmp r8, rdx
    jge exit
    jl bigloop
    
position:
mov r11, 0; r11 is start
mov r12, r11; r12 = i, r12 is end
dec r12; r12=i-1
mov rcx, 1
loop search

fff:
cmp r9, r11
jl ccc
mov r14,r9
inc r14
movsd xmm2,qword[rdi+r14*8] 
movsd qword[rdi+r9*8], xmm2;arr[j+1]=arr[j]
movsd xmm2,qword[rsi+r14*8]
movsd qword[rsi+r9*8],xmm2
dec r9

search:
cmp r11, r12
jg ccc
mov r13, r12; mid
sub r13, r11
sar r13, 1
add r13, r11
movsd xmm1, qword[rdi+r13*8]
comisd xmm0, xmm1
jb ddd
comisd xmm1, xmm0
jbe bbb

ccc:
dec rcx
ret
bbb:
;if key < arr[mid]
mov r12, r13
 inc r12
 ret
 ddd:
 ; key > arr[mid]
 mov r12, r13
 dec r12
 ret 
exit:
leave
ret
