;char						*ft_strjoin(char const *s1, char const *s2);
section .text
	global _ft_strjoin
	extern _ft_strdup
	extern _ft_memcpy
	extern _malloc
	extern _ft_strlen
	extern _ft_strcat

_ft_strjoin:
	push rbp
	cmp rdi, 0				;check si s1 est null
	je _s1_null
	mov r13, rdi			;r13 = s1
	mov r11, rsi			;r11 = s2
	call _ft_strlen			;appel ft_strlen(rdi = s1)
	mov r15, rax			;r15 = len s1
	inc r15					;ajoute 1 a la len de s1 pour le '\0'
	mov r12, r15			;mem len s1
	mov rdi, rsi			;rdi = s2
	call _ft_strlen			;appel ft_strlen(rdi = s2)
	mov r14, rax			;r14 = len s2
	add r15, r14			;r15 += r14 => len du malloc
	mov rdi, r15			;param 1 de malloc
	call _malloc			;appel malloc
	cmp rax, 0				;check return de malloc
	jle _failled			;jump pour retourner NULL
	mov rdi, rax			;param 1 de ft_memcpy return de malloc
	mov rsi, r13			;param 2 de ft_memcpy s1
	mov rdx, r12			;param 3 de ft_memcpy len a copier
	call _ft_memcpy			;copie s1 dans le retour de malloc
	mov rdi, rax			;param 1 de ft_strcat ret de ft_memcpy ret malloc
	mov rsi, r11			;param 2 de ft_strcat s2
	call _ft_strcat			;appel ft_strcat
	pop rbp
	ret
_s1_null:
	mov rdi, rsi			;rdi = s2
	call _ft_strdup			;appel de ft_strdup
	pop rbp
	ret
_failled:
	xor rax, rax			; ret NULL car malloc failled
	pop rbp
	ret
