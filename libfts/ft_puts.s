section .data
NULL:
	.string db "(null)", 0
NEW_LINE:
	.string db "", 10, 0

section .text
	global _ft_puts
	extern _ft_putstr

_ft_puts:
	push rbp
	cmp rdi, 0
	je _STR_NULL
	call _ft_putstr
	jmp _NEW_LINE
_STR_NULL:
	lea rdi, [rel NULL.string]
	call _ft_putstr
_NEW_LINE:
	lea rdi, [rel NEW_LINE.string]
	call _ft_putstr
	mov rax, 0xa
	pop rbp
	ret
