section .text
global ft_list_size

ft_list_size:
	mov rax, 0

_ft_list_size_loop:
	cmp rdi, 0
	je _ft_list_size_done

	mov rdi, qword [rdi + 8]
	inc rax
	jmp _ft_list_size_loop

_ft_list_size_done:
	ret

