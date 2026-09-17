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
		xor	r9, r9

		.check_dups_loop:
			cmp rax, r8
			je	.inc_rax_and_jump_val_base_loop
			xor	r9, r9
			mov	r9b, [rsi + r8]
			cmp r9b, byte [rsi + rax]
			je	.set_invalid
			inc	r8
	
		.inc_rax_and_jump_val_base_loop:
			inc	rax
			jmp	.validate_base_loop

	.validate_base_loop_done:
		cmp rax, 2
		jl	.set_invalid

.return:
	ret

.set_invalid:
	xor		rax, rax
	jmp		.return
