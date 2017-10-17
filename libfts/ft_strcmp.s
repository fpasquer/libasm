section .text
	global _ft_strcmp
	extern _ft_puts

_ft_strcmp:
	push rbp
	xor r12, r12					;r12 = 0
_loop_str:
	mov r13, [rdi + r12]
	mov r14, [rsi + r12]
	cmp r13, byte 0						;s1[r12] != 0
	jmp _end_loop
	cmp r14, byte 0						;s2[r12] != 0
	jmp _end_loop
	cmp r13, r14					;s1[r12] != s2[r12]
	jne _end_loop
	inc r12							;r12++
	jmp _loop_str
_end_loop:
	mov rax, r13
	sub rax, r14
	pop rbp
	ret
