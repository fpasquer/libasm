;char						*ft_strcat(char *s1, char const *s2);
section .text
	global _ft_strcat

_ft_strcat:
	push rbp
	xor r8, r8				;r8 = 0
	xor r9, r9				;r9 = 0
_s1_loop:
	cmp [rdi + r8], byte 0	;s1[r8] != '\0'
	jle _s2_loop			;quite _s1_loop
	inc r8					;r8++
	jmp _s1_loop			;go debut _s1_loop
_s2_loop:
	cmp [rsi + r9], byte 0
	jle _end
	mov r10b, [rsi + r9]
	mov [rdi + r8], r10b
	inc r8
	inc r9
	jmp _s2_loop
_end:
	mov [rdi + r8], byte 0
	mov rax, rdi
	pop rbp
	ret
