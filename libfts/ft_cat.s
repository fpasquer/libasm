;void						ft_cat(int fd)
%define READ 0x2000003
%define WRITE 0x2000004
%define CLOSE 0x2000006
%define INT_MAX 0x7fffffff
%define BUFF_SIZE 70000

section .bss
	buff: resb BUFF_SIZE

section .text
	global _ft_cat

_ft_cat:
	push rbp
	cmp rdi, INT_MAX		;si fd invalid
	jg _end_ft_cat			;quite ft_cat
	mov r15, rdi			;r15 = fd
	lea rsi, [rel  buff]	;rsi = buff param 2 de read et write
_while:
	mov rdi, r15			;rdi = fd param 1 de read
	mov rdx, BUFF_SIZE		;rdx = BUFF_SIZE param 3 de read et write
	mov rax, READ			;prepare le call de read
	syscall					;call read
	jc _end_ft_cat
	cmp rax, 0				;check si quelque chose a ete lu
	jle _end_ft_cat
	mov rdi, 1				;rdi = 1 param 1 de write
	mov rdx, rax			;affiche juste la partie lu de read
	mov rax, WRITE
	syscall					;call write
	jmp _while
_end_ft_cat:
	mov rdi, r15
	mov rax, CLOSE
	syscall
	mov rax, 1
	pop rbp
	ret
