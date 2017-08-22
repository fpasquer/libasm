;char						*ft_strrchr(char const *str, int c);
section .text
	global _ft_strrchr
	extern _ft_strlen

_ft_strrchr:
	push rbp
	call _ft_strlen			;rax = len str
	mov r15, rax			;r15 = len str
	xor rax, rax			;rax = NULL
_while:
	cmp r15, 0				;while(r15 >= 0)
	jl _end_while
	cmp [rdi + r15], sil	;if(str[r15] == c)
	je _c_found
	dec r15					;r15--
	jmp _while
_c_found:					;save l'adresse de str[r15]
	mov rax, rdi
	add rax, r15
_end_while:
	pop rbp
	ret
