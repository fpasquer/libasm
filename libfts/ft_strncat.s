section .text
	global _ft_strncat

_ft_strncat:
	mov r8, 0
	push rbp
_s1_loopncat:
	cmp [rdi + r8], byte 0
	jle _s2_ncat
	cmp rdx, 0
	jle _end_strncat
	inc r8
	dec rdx
	jmp _s1_loopncat
_s2_ncat:
	mov r9, 0
_s2_loopncat:
	cmp [rsi + r9], byte 0
	jle _end_strncat
	cmp rdx, 0
	jle _end_strncat
	mov r10, [rsi + r9]
	mov [rdi + r8], r10
	inc r9
	inc r8
	dec rdx
	jmp _s2_loopncat
_end_strncat:
	mov [rdi + r8], byte 0
	mov rax, rdi
	pop rbp
	ret
