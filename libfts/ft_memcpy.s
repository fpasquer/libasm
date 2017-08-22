;void						*ft_memcpy(void *dest, void const *src, size_t n)

section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
_while:
	cmp rdx, 0				;n > 0
	jle _end_memcpy			;go to the end
	dec rdx					;n--
	mov r8b, [rsi + rdx]	;r8b(1 octet) = src[n]
	mov [rdi + rdx], r8b	;dest[n] = r8b(1 octet)
	jmp _while				;go to the start of the loop
_end_memcpy:
	mov rax, rdi			;return *dest
	pop rbp
	ret
