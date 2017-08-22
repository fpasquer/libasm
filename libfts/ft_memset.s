section .text
	global _ft_memset

_ft_memset:
	push rbp
_start_loop:
	cmp rdx, 0
	jle _end_memset
	mov [rdi + rdx - 1], sil ;sil pour avoir que les 8 bytes que j'ai besoin
	dec rdx
	jmp _start_loop
_end_memset:
	mov rax, rdi
	pop rbp
	ret
