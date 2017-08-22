;char						*ft_strcpy(char *dest, char const *src);
section .text
	global _ft_strcpy
	extern _ft_memcpy
	extern _ft_strlen

_ft_strcpy:
	push rbp
	mov r15, rdi			;r15 = dest
	mov rdi, rsi			;src param 1 de ft_strlen
	call _ft_strlen			;rax = len src
	inc rax					;rax++ pour le '\0'
	mov rdi, r15			;dest param 1 de ft_memcpy
							;src param 2 de ft_memcpy
	mov rdx, rax			;len src param 3 de ft_memcpy
	call _ft_memcpy
	pop rbp
	ret
