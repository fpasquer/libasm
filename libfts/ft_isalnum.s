section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	push rbp
	call _ft_isalpha
	cmp rax, 1
	je _true
	call _ft_isdigit
	cmp rax, 1
	je _true
	mov rax, 0
	pop rbp
	ret
_true:
	mov rax, 1
	pop rbp
	ret
