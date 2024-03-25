section .text
global ft_read
extern __errno_location

ft_read:
	mov rax, 0
	syscall
	cmp rax, 0
	jge _ft_read_done

	neg rax
	mov r12, rax
	call __errno_location wrt ..plt
	mov [rax], r12
	mov rax, -1

_ft_read_done:
	ret
