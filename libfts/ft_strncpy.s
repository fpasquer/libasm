;char						*ft_strncpy(char *dest, char const *src, size_t n);
section .text
	global _ft_strncpy
	extern _ft_memcpy
	extern _ft_strlen

_ft_strncpy:
	push rbp
	mov r15, rdi			;r15 = dest
	mov rdi, rsi			;src param 1 de ft_strlen
	call _ft_strlen			;rax = len src
	cmp rax, rdx			;if (n >= len str)
	jge _start_cpy
	mov rdx, rax			;n = len str
_start_cpy:
	mov rdi, r15			;dest param 1 de ft_memcpy
							;src param 2 de ft_memcpy
							;n param 3 de ft_memcpy
	call _ft_memcpy
	pop rbp
	ret
