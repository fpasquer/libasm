%define WRITE 0x2000004

%define STDOUT 1

section .text
	global _ft_putstr
	extern _ft_strlen

_ft_putstr:
	push rbp
	call _ft_strlen ;rax = len must be print
	cmp rax, 0
	je _empty_str
	lea rsi, [rel rdi]
	mov rdi, STDOUT
	mov rdx, rax
	mov rax, WRITE
	syscall
	pop rbp
	ret
_empty_str:
	xor rax, rax
	pop rbp
	ret
