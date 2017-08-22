;void						ft_memdel(void **ptr);
section .text
	global _ft_memdel
	extern _free

_ft_memdel:
	push rbp
	mov r15, [rdi]			;r15 = *ptr
	mov r14, rdi			;r14 = ptr
	mov rdi, r15			;param 1 de free = *ptr
	call _free
	xor r14, r14			;passe ptr a NULL
	pop rbp
	ret
