null_terminator equ 00
horizontal_tab	equ 09
new_line		equ 0a
vertical_tab	equ 0b
form_feed		equ 0c
carriage_return	equ 0d
space			equ 20
plus_sign		equ 2b
minus_sign		equ 2d

global ft_atoi_base

ft_atoi_base:
	xor		rax, rax

	.validate_base_loop:
		cmp	[rsi + rax], byte null_terminator ; Did we reach the null terminator yet?
		je .validate_base_loop_done ; If yes, exit the validate base loop

		; Now we check if the char at index RAX is a '+' (43) or a '-' (45), both of which mean base is an invalid argument
		cmp [rsi + rax], byte plus_sign
		je .set_invalid ;
		cmp [rsi + rax], byte minus_sign
		je	.set_invalid

		; Next we check if the char at index RAX is one of the whitespace characters (9, 10, 11, 12, 13, and 32).
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

		.check_dups_loop:
			cmp rax, 0

	.validate_base_loop_done:
		cmp rax, 2
		jl	.set_invalid

.return:
	pop		rsi
	pop		rdi
	ret

.set_invalid:
	xor		rax, rax
	jmp		.return

.check_duplicates:
	mov		r8, rax
	xor		r9, r9

	xor		r8, r8
	.check_dups_loop2:
		dec r8 ; This needs to be done at the start of the first iteration too because at this point the value in r8 is identical to the value in rax
		mov	r9b, [rsi + r8]
		cmp r9b, byte [rsi + rax]
		je	.set_invalid
		cmp r8, 0
		jne .check_dups_loop

.check_and_increment:
	cmp		rax, 0
	jne		check_duplicates
	jmp		.validate_base_loop