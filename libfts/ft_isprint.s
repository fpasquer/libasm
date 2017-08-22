section .text
	global _ft_isprint

_ft_isprint:
	cmp rdi, 32 ;sp
	jl _false
	cmp rdi, 126 ;~
	jg _false
	mov rax, 1
	ret
_false:
	mov rax, 0
	ret
