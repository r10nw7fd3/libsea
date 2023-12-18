.section .text
.global _start
_start:
	pop rdi
	pop rsi
	call main
	mov rdi, rax
	mov rax, 60
	syscall
