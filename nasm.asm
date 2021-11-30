global CountPunc
CountPunc:
section .data							
	stringPunctuation	db ".,!?-():;",0
        stringInt db "%i",0
section .text							
        push rbp
        mov rbp,rsp
        mov r10,rdi
        mov r11,rsi
        mov r8d,0    ; counter
        mov r9,0    ; alph counter
        lea rsi,[stringPunctuation]	; 	search argument
bigloop:
        lea rdi,[r10] 	;	string
        mov rcx,r11
        lodsb
        cld
search:
        scasb
        je char_found
return:
        loop search
        inc r9
        cmp r9,9
        jne bigloop
        cvtsi2sd xmm0, r8d
        jmp exit
exit:
cvtsi2sd xmm1,r11
divsd xmm1,xmm0
movsd xmm0,xmm1
leave
ret

char_found:
    inc r8d
    jmp return
