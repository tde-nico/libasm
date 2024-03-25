section .text
global ft_atoi_base
extern ft_strlen

ft_check_duplicate:
	xor rax, rax
	mov rbx, rcx
	inc rbx

_ft_check_duplicate_loop:
	mov r12b, byte [rdi + rbx]
	cmp r12b, 0
	je _ft_check_duplicate_done
	cmp r12b, dl
	je _ft_check_duplicate_error
	inc rbx
	jmp _ft_check_duplicate_loop

_ft_check_duplicate_error:
	mov rax, 1
_ft_check_duplicate_done:
	ret


ft_is_base_valid:
	call ft_strlen
	cmp rax, 2
	jl _ft_is_base_valid_error
	xor rcx, rcx

_ft_is_base_valid_loop:
	mov rax, 1
	mov dl, byte [rdi + rcx]
	cmp dl, byte 0
	je _ft_is_base_valid_done

	cmp dl, byte '-'
	je _ft_is_base_valid_error
	cmp dl, byte '+'
	je _ft_is_base_valid_error
	cmp dl, byte ' '
	je _ft_is_base_valid_error
	cmp dl, byte 9
	je _ft_is_base_valid_error
	cmp dl, byte 13
	je _ft_is_base_valid_error

_ft_is_base_valid_continue:
	call ft_check_duplicate
	cmp rax, 1
	je _ft_is_base_valid_error
	inc rcx
	jmp _ft_is_base_valid_loop

_ft_is_base_valid_error:
	xor rax, rax
_ft_is_base_valid_done:
	ret


ft_atoi_base:
	push rdi
	push rsi
	push r12
	push r11
	push r10
	push r9
	push rbx
	push rcx
	push rdx

	mov r11, rdi
	mov rdi, rsi
	call ft_is_base_valid
	cmp rax, 0
	je _ft_atoi_base_done

	call ft_strlen
	mov r10, rax
	mov rsi, r11
	mov r11, 1
_ft_atoi_base_skip_space:
	mov dl, byte [rsi]
	cmp dl, byte ' '
	jne _ft_atoi_base_skip_signs
	inc rsi
	jmp _ft_atoi_base_skip_space

_ft_atoi_base_skip_signs:
	cmp dl, byte '+'
	je _ft_atoi_base_skip_signs_next
	cmp dl, byte '-'
	jne _ft_atoi_base_convert_number_init
	imul r11, -1

_ft_atoi_base_skip_signs_next:
	inc rsi
	mov dl, byte [rsi]
	jmp _ft_atoi_base_skip_signs

_ft_atoi_base_convert_number_init:
	xor rcx, rcx
	mov rax, 0
	dec rdi
	mov r9, 0

_ft_atoi_base_convert_number:
	cmp dl, byte 0
	je _ft_atoi_base_done
	call ft_check_duplicate
	cmp rax, 0
	je _ft_atoi_base_end

	imul r9, r10
	dec rbx
	add r9, rbx

	mov rax, r9
	imul rax, r11
	inc rsi
	mov dl, byte [rsi]
	jmp _ft_atoi_base_convert_number

_ft_atoi_base_end:
	mov rax, r9
	imul rax, r11
_ft_atoi_base_done:
	pop rdx
	pop rcx
	pop rbx
	pop r9
	pop r10
	pop r11
	pop r12
	pop rsi
	pop rdi
	ret
