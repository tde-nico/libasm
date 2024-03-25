section .text
global ft_list_sort
extern ft_list_size

ft_list_sort:
	mov r11, rdi
	mov r12, rsi
	mov rdi, qword [rdi]
	call ft_list_size
	mov rcx, rax

_ft_list_sort_iter:
	mov rdx, qword [r11]
	cmp rcx, 0
	je _ft_list_sort_done

_ft_list_sort_swap:
	cmp qword [rdx + 8], 0
	je _ft_list_sort_iter_next

	mov rdi, qword [rdx]
	mov rsi, qword [rdx + 8]
	mov rsi, qword [rsi]
	push rdx
	push rcx
	push r11
	call r12
	pop r11
	pop rcx
	pop rdx
	cmp eax, 0
	jle _ft_list_sort_swap_next

	mov rdi, qword [rdx]
	mov r10, qword [rdx + 8]
	mov rsi, qword [r10]
	mov qword [rdx], rsi
	mov qword [r10], rdi

_ft_list_sort_swap_next:
	mov rdx, qword [rdx + 8]
	jmp _ft_list_sort_swap

_ft_list_sort_iter_next:
	dec rcx
	jmp _ft_list_sort_iter

_ft_list_sort_done:
	mov rdi, r11
	mov rsi, r12
	ret
