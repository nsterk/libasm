global ft_atoi_base

null_terminator	equ 0x0
horizontal_tab	equ 0x9
new_line		equ 0xa
vertical_tab	equ 0xb
form_feed		equ 0xc
carriage_return	equ 0xd
space			equ 0x20
plus_sign		equ 0x2b
minus_sign		equ 0x2d

; TO DO
; - add sign handling for str .(- or +)

ft_atoi_base:
	xor		rax, rax
	xor		r10, r10

	.validate_base_loop:
		cmp	[rsi + r10], byte null_terminator 		;Did we reach the null terminator yet?
		je .validate_base_loop_done 				;If yes, exit the validate base loop

		;The following instructions check whether the character at the current index is '+'. '-', or a whitespace character. If yes, the base is invalid
		cmp [rsi + r10], byte plus_sign
		je .return
		cmp [rsi + r10], byte minus_sign
		je	.return
		cmp [rsi + r10], byte horizontal_tab
		je	.return
		cmp [rsi + r10], byte new_line
		je	.return
		cmp [rsi + r10], byte vertical_tab
		je	.return
		cmp [rsi + r10], byte form_feed
		je	.return
		cmp [rsi + r10], byte carriage_return
		je	.return
		cmp [rsi + r10], byte space
		je	.return

		xor r8, r8

	.check_dups_loop:
		cmp r10, r8
		je	.inc_r10_and_jump_val_base_loop
		mov	r9b, [rsi + r8]
		cmp r9b, [rsi + r10]
		je	.return
		inc	r8
		
	.inc_r10_and_jump_val_base_loop:
		inc	r10
		jmp	.validate_base_loop

	.validate_base_loop_done:
		cmp r10, 2
		jl	.return

	.skip_whitespace:
		cmp [rdi], byte null_terminator
		je	.return
		cmp [rdi], byte horizontal_tab
		je	.inc_rdi_and_jump_skip_whitespace
		cmp [rdi], byte new_line
		je	.inc_rdi_and_jump_skip_whitespace
		cmp [rdi], byte vertical_tab
		je	.inc_rdi_and_jump_skip_whitespace
		cmp [rdi], byte form_feed
		je	.inc_rdi_and_jump_skip_whitespace
		cmp [rdi], byte carriage_return
		je	.inc_rdi_and_jump_skip_whitespace
		cmp [rdi], byte space
		je	.inc_rdi_and_jump_skip_whitespace

	xor	r11b, r11b		; This is where we will store whether str is negative (val = 1) or not (val = 0)
	
	cmp [rdi], byte minus_sign
	je .set_sign_flag_and_jump_inc_rdi_jump_get_value
	
	cmp [rdi], byte plus_sign
	je	.inc_rdi_and_jump_get_value

	.get_value:
		cmp [rdi], byte null_terminator
		je	.handle_sign
		xor	r9, r9
		xor rdx, rdx
	
	.get_value_loop:
		cmp rdx, r10	; r10 contains the length of our base. If we've reached the end of base, there is no value to assign to the current char and it means that we have our final number.
		je	.handle_sign
		mov	r9b, [rsi + rdx]
		cmp	r9b, [rdi]
		je .convert
		inc	rdx
		jmp .get_value_loop

	.convert:
		imul	rax, r10
		add		rax, rdx
		inc		rdi
		; conversion functoin : num = num * base_len + value;
			; num == rax
			; base_len == r10
			; value == rdx
		jmp .get_value
		
	.handle_sign:
		cmp	r11b, 0
		je	.return
		neg rax

	.return:
		ret

	.set_invalid:
		xor		rax, rax
		jmp		.return

	.inc_rdi_and_jump_skip_whitespace:
		inc		rdi
		jmp		.skip_whitespace

	.inc_rdi_and_jump_get_value:
		inc		rdi
		jmp		.get_value
	
	.set_sign_flag_and_jump_inc_rdi_jump_get_value:
		mov		r11, 1
		jmp		.inc_rdi_and_jump_get_value
