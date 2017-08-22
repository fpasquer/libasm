section .text
	global _ft_isdigit

_ft_isdigit:
	push rbp
	cmp rdi, 48 ;0
	jl _false
	cmp rdi, 57 ;9
	jg _false
	mov rax, 1
	pop rbp
	ret
_false:
	mov rax, 0
	pop rbp
	ret
