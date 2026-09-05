global	ft_list_size

; [rdi] == struct->data
; [rdi + 8] == struct->next

section .text
extern malloc

global _start

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


_start:
  push rbp
  mov rbp, rsp
  ; allocate 40 bytes of space on the stack
  sub rsp, 40
  
  ; now we want to initialize num1 and num2
  mov dword [rsp - 8], 1
  mov dword [rsp - 4], 2

  ; We have our numbers. Now assign the address of num1 to the first location in elem1 (which is for the data ptr)
  lea rax, [rsp - 8]
  mov [rsp - 40], rax
  ; Now assign the address of elem2 to the second index of elem1
  lea rax, [rsp - 24]
  mov [rsp - 32], rax
  
  ; Elem1 is done. Now we initialize elem2. The address of num2 needs to be put in index 0, and 0x0 needs to be put in index 1
  lea rax, [rsp - 4]
  mov [rsp - 24], rax
  mov [rsp - 16], 0
  
  lea rdi, [rsp - 40]
  call ft_list_size
  mov rsp, rbp
  pop rbp
  ret
  
ft_list_size:
  xor		rax, rax
  push	rbp
	mov		rbp, rsp
	sub		rsp, 8
	mov		[rbp - 8], rdi

	ls.loop:
		cmp	[rdi], 0
		je	ls.return
		inc	rax
		mov	rdi, [rdi + 8]
    jmp ls.loop

	ls.return:
		mov		rdi, [rbp - 8]
		mov		rsp, rbp
		pop		rbp
		ret
