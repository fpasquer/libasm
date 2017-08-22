section .text
	global _ft_tolower

_ft_tolower:
	push rbp
	cmp rdi, 65
	jl _ret_rdi
	cmp rdi, 90
	jg _ret_rdi
	add rdi, 32
_ret_rdi:
	mov rax, rdi
	pop rbp
	ret
