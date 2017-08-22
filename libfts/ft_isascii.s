section .text
	global _ft_isascii

_ft_isascii:
	push rbp
	cmp rdi, 0
	jl _false
	cmp rdi, 127
	jg _false
	mov rax, 1
	pop rbp
	ret
_false:
	mov rax, 0
	pop rbp
	ret
