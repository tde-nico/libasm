section .text
global ft_strlen

ft_strlen:
	mov rax, rdi

_ft_strlen_loop:
	cmp byte [rax], byte 0
	je _ft_strlen_done
	inc rax
	jmp _ft_strlen_loop

_ft_strlen_done:
	sub rax, rdi
	ret
