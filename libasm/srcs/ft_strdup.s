section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push rbp
	push rdi
	push rsi
	mov rbp, rsp
	and rsp, 0xfffffffffffffff0

	call ft_strlen
	inc rax
	mov r12, rdi
	mov rdi, rax
	call malloc wrt ..plt
	cmp rax, 0
	je _ft_strdup_end

	mov rsi, r12
	mov rdi, rax
	call ft_strcpy

_ft_strdup_end:
	mov rsp, rbp
	pop rsi
	pop rdi
	pop rbp
	ret
