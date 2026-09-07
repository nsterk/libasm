global	ft_list_size

; [rdi] == struct->data
; [rdi + 8] == struct->next

; struct elem1; <--- 16 bytes local variable
; struct elem2; <--- 16 bytes local var
; int num1 ; <---- 4 bytes local var
; int num2 ; <---- 4 bytes local var

; 16 + 16 = 32, 4 + 5 = 8,32 + 8 = 40, === 40 bytes of local vars on stack


; [rsp - 40] is for elem1

  ; [rsp - 40] is elem1.data
  ; [rsp - 32] is elem1.next
  
; [rsp - 24] is for elem2
  ; [rsp - 24] is elem2.data
  ; [rsp - 16] is elem2.next
; [rsp - 8] is for num1
; [rsp - 4] is for num2
  
ft_list_size:
  xor		rax, rax
  push	rbp
	mov		rbp, rsp
	sub		rsp, 8
	mov		[rbp - 8], rdi

	ls.loop:
		cmp rdi, 0
		je	ls.return
		inc	rax
		mov	rdi, [rdi + 8]
    jmp ls.loop

	ls.return:
		mov		rdi, [rbp - 8]
		mov		rsp, rbp
		pop		rbp
		ret
