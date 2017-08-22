section .text
	global _ft_strlen

_ft_strlen:
	push rbp
	xor r8, r8 ;initialise r8 a 0
_loop_strlen:
	cmp [rdi + r8], byte 0
	je _end_strlen
	inc r8
	jmp _loop_strlen
_end_strlen:
	mov rax, r8
	pop rbp
	ret
