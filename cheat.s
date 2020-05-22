	.text
	.file	"cheat.ll"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp2:
	.cfi_def_cfa_register %rbp
	movl	$0, -12(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -24(%rbp)
	movl	$1, -4(%rbp)
	movl	$1, %eax
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.globl	joca
	.p2align	4, 0x90
	.type	joca,@function
joca:                                   # @joca
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp5:
	.cfi_def_cfa_register %rbp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	joca, .Lfunc_end1-joca
	.cfi_endproc

	.type	i,@object               # @i
	.comm	i,4,4

	.ident	"clang version 3.9.1-19ubuntu1 (tags/RELEASE_391/rc2)"
	.section	".note.GNU-stack","",@progbits
