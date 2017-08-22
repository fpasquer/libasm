section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	push rbp
	call _ft_strlen		;rax = len de str
	mov r15, rdi		;r15 = str = source
	add rax, 1				;rax++
	mov r14, rax		;longueur de la dest '\0'compris
	mov rdi, rax		;pour envoyer la longueur a malloc
	call _malloc		;rax = ptr de dest
	cmp rax, 0			;malloc failled
	jle _error_malloc
	mov rdi, rax		;retour de malloc param 1 a ft_memcpy
	mov rsi, r15		;deplace str dans le param 2 de ft_memcpy
	mov rdx, r14		;len a copier param 3 de ft_memcpy
	call _ft_memcpy		;appel de ft_memcpy
	pop rbp
	ret
_error_malloc:
	xor rax, rax ;retourne NULL
	pop rbp
	ret
