section .text
	global _ft_isalpha

_ft_isalpha:
	push rbp
_maj:
	cmp rdi, 65 ;A
	jl _false
	cmp rdi, 90 ;Z
	jg _min
	jmp _true
_min:
	cmp rdi, 97 ;a
	jl _false
	cmp rdi, 122 ;z
	jg _false
_true:
	mov rax, 1
	pop rbp
	ret
_false:
	mov rax, 0
	pop rbp
	ret
