.section .text
.global setjmp
setjmp:
	mov [rdi], rbx
	lea r8, [rsp+8]
	mov [rdi+8], r8
	mov [rdi+16], rbp
	mov [rdi+24], r12
	mov [rdi+32], r13
	mov [rdi+40], r14
	mov [rdi+48], r15
	mov r8, [rsp]
	mov [rdi+56], r8
	mov rax, 0
	ret

.global longjmp
longjmp:
	mov rax, rsi
	test rax, rax
	jnz not_zero
	mov rax, 1
not_zero:
	mov rbx, [rdi]
	mov rsp, [rdi+8]
	mov rbp, [rdi+16]
	mov r12, [rdi+24]
	mov r13, [rdi+32]
	mov r14, [rdi+40]
	mov r15, [rdi+48]
	jmp [rdi+56]
