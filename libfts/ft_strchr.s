;char						*ft_strchr(char const *str, int c);
section .text
	global _ft_strchr

_ft_strchr:
	push rbp
	xor r15, r15			;r15 = 0
_while:						;while (str[r15] != '\0')
	cmp [rdi + r15], byte 0
	je _end_while			;leave the while
	cmp [rdi + r15], sil	;if(str[r15] == c)
	je _c_found
	inc r15					;r15++
	jmp _while				;go to the start of the while
_end_while:
	cmp rsi, 0				;check si c = '\0'
	je _c_found
	xor rax, rax			;return NULL
	pop rbp
	ret
_c_found:					;return str[r15]
	mov rax, rdi
	add rax, r15
	pop rbp
	ret
