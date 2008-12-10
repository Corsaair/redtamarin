PUBLIC saveRegs64

EXTRN	__imp_VirtualQuery:PROC

MEMORY_BASIC_INFORMATION struct
    BaseAddress			dq		?
    AllocationBase		dq		?
    AllocationProtect	dd		?
    somepad				dd		?
    RegionSize			dq		?
    State				dd		?
    Protect				dd		?
    _Type				dd		?
    otherpad			dd		?
MEMORY_BASIC_INFORMATION ends

.data?

mib MEMORY_BASIC_INFORMATION <>

.code

saveRegs64: ; proc saves : qword : stack : qword _size : dword
	
	; RCX, RDX, R8 pushed here, don't save below
	mov [rsp+8h],	rcx ; saves
	mov [rsp+10h],	rdx ; _stack
	mov [rsp+18h],	r8	; _size
	
	; save all the registers?
	mov [rcx],		rax
	mov	[rcx+8h],	rbx
	mov [rcx+10h],	r9
	mov [rcx+18h],	r12
	mov [rcx+20h],	r13
	mov [rcx+28h],	r14
	mov [rcx+30h],	r15
	mov [rcx+38h],	rsi
	mov [rcx+40h],	rdi
	
	; params for VirtualQuery
	mov	 r8d, 48
  	lea	 rdx, mib
	mov	 rcx, rsp

	; make room on the stack
	sub		rsp, 20h	
	call	 QWORD PTR __imp_VirtualQuery
	add		rsp, 20h
	
  	mov	 rax, mib.BaseAddress
	mov	 rcx, rsp
	sub	 rcx, rax ; rcx = StackTop - mib.BaseAddress
	mov	 rax, rcx
  	mov	 rcx, mib.RegionSize ; DWORD PTR __mib$[rsp+24]
	sub	 rcx, rax
  	mov	 rax, rcx
  	
  	mov	 rcx, [rsp+18h] ; _size
	mov	 [rcx], rax	;
	mov  rcx, [rsp+10h]
	mov	 [rcx], rsp
	
	ret
END
