	.file	"test.c"
	.section	.rodata
.LC0:
	.string	"%d "
	.text
	.globl	test
	.type	test, @function
test:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	a.2684(%rip), %eax
	addl	$1, %eax
	movl	%eax, a.2684(%rip)
	movl	a.2684(%rip), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	test, .-test
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	call	test
	addl	$1, -4(%rbp)
.L3:
	cmpl	$9, -4(%rbp)
	jle	.L4
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.data
	.align 4
	.type	a.2684, @object
	.size	a.2684, 4
a.2684:
	.long	1
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
