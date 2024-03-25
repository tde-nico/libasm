section .text
global ft_strcpy

ft_strcpy:
	xor rax, rax

_ft_strcpy_loop:
	cmp byte [rsi + rax], byte 0
	je _ft_strcpy_done
	mov dl, byte [rsi + rax]
	mov byte [rdi + rax], dl
	inc rax
	jmp _ft_strcpy_loop

_ft_strcpy_done:
	mov byte [rdi + rax], byte 0
	mov rax, rdi
	ret
