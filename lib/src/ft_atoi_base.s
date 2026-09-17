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

	.validate_base_loop:
		cmp	[rsi + rax], byte null_terminator 		;Did we reach the null terminator yet?
		je .validate_base_loop_done 				;If yes, exit the validate base loop

		;The following instructions check whether the character at the current index is '+'. '-', or a whitespace character. If yes, the base is invalid
		cmp [rsi + rax], byte plus_sign
		je .set_invalid
		cmp [rsi + rax], byte minus_sign
		je	.set_invalid
		cmp [rsi + rax], byte horizontal_tab
		je	.set_invalid
		cmp [rsi + rax], byte new_line
		je	.set_invalid
		cmp [rsi + rax], byte vertical_tab
		je	.set_invalid
		cmp [rsi + rax], byte form_feed
		je	.set_invalid
		cmp [rsi + rax], byte carriage_return
		je	.set_invalid
		cmp [rsi + rax], byte space
		je	.set_invalid

		xor r8, r8

	.check_dups_loop:
		cmp rax, r8
		je	.inc_rax_and_jump_val_base_loop
		mov	r9b, [rsi + r8]
		cmp r9b, [rsi + rax]
		je	.set_invalid
		inc	r8
		
	.inc_rax_and_jump_val_base_loop:
		inc	rax
		jmp	.validate_base_loop

	.validate_base_loop_done:
		cmp rax, 2
		jl	.set_invalid

	mov r10, rax		; The length of our base is now in RAX. This is where we will be putting the converted value, so we're moving this value into r10.
	xor	rax, rax		; Set RAX to 0 again so our conversion actually works

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

	xor r11b, r11b		; This is where we will store whether str is negative (val != 0) or not (val == 0)
	
	cmp [rdi], byte minus_sign
	je .set_sign_flag_and_jump_inc_rdi_jump_convert
	
	cmp [rdi], byte plus_sign
	je	.inc_rdi_and_jump_convert

	.convert:
		.get_value:
			xor	r9, r9
			.get_value_loop:

	.return:
		ret

	.set_invalid:
		xor		rax, rax
		jmp		.return

	.inc_rdi_and_jump_skip_whitespace:
		inc		rdi
		jmp		.skip_whitespace

	.inc_rdi_and_jump_convert:
		inc		rdi
		jmp		.convert
	
	.set_sign_flag_and_jump_inc_rdi_jump_convert:
		mov		r11b, 1
		jmp		.convert


