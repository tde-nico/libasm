section .text
global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor rdx, rdx

_ft_strcmp_loop:
	mov al, byte [rdi]
	mov dl, byte [rsi]
	cmp al, byte 0
	je _ft_strcmp_done
	cmp dl, byte 0
	je _ft_strcmp_done
	cmp al, dl
	jne _ft_strcmp_done
	inc rdi
	inc rsi
	jmp _ft_strcmp_loop

_ft_strcmp_done:
	sub rax, rdx
	ret
