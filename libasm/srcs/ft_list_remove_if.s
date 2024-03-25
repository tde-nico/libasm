section .text
global ft_list_remove_if
extern free

ft_list_remove_ptr:
	push rdi
	mov r8, qword [rdi]
	cmp qword [rdi], rsi
	jne _ft_list_remove_change

	mov r10, qword [rsi + 8]
	mov qword [rdi], r10
	mov rdi, rsi
	jmp _ft_list_remove_free

_ft_list_remove_change:
	mov r9, qword [r8 + 8]
	cmp r9, rsi
	je _ft_list_remove_delete
	mov r8, r9
	jmp _ft_list_remove_change

_ft_list_remove_delete:
	mov r10, qword [rsi + 8]
	mov qword [r8 + 8], r10
	mov rdi, rsi

_ft_list_remove_free:
	push r11
	call free wrt ..plt
	pop r11
	pop rdi
	ret


ft_list_remove_if:
	push rdi
	push rsi
	mov r11, rdi
	mov r12, rsi
	mov r13, rdx
	mov r14, rcx
	mov rbx, qword [rdi]

_ft_list_remove_if_loop:
	cmp rbx, qword 0
	je _ft_list_remove_if_done

	mov r15, qword [rbx + 8]
	push r15

	mov rdi, qword [rbx]
	mov rsi, r12
	call r13
	cmp rax, 0
	jne _ft_list_remove_if_loop_remove_next

_ft_list_remove_if_loop_remove:
	mov rdi, qword [rbx]
	call r14
	mov rdi, r11
	mov rsi, rbx
	call ft_list_remove_ptr

_ft_list_remove_if_loop_remove_next:
	pop rbx
	jmp _ft_list_remove_if_loop

_ft_list_remove_if_done:
	pop rsi
	pop rdi
	ret
