section .text
	global _ft_toupper

_ft_toupper:
	push rbp
	cmp rdi, 97
	jl _ret_rdi
	cmp rdi, 122
	jg _ret_rdi
	sub rdi, 32
_ret_rdi:
	mov rax, rdi
	pop rbp
	ret
