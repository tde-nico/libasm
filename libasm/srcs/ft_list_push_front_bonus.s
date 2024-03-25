section .text
global ft_list_push_front
extern malloc

ft_list_push_front:
	push rdi
	push rsi
	mov rdi, 16
	call malloc wrt ..plt
	pop rsi
	pop rdi
	cmp rax, 0
	je _ft_list_push_front_done

	mov qword [rax], rsi
	cmp qword [rdi], qword 0
	je _ft_list_push_front_new

	push rdx
	mov rdx, qword [rdi]
	mov qword [rax + 8], rdx
	mov qword [rdi], rax
	pop rdx
	jmp _ft_list_push_front_done

_ft_list_push_front_new:
	mov [rdi], rax
	mov qword [rax + 8], 0

_ft_list_push_front_done:
	ret
