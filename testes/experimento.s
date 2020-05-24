	.text
	.file	"testes/experimento.ll"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	xorl	%eax, %eax
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.str.int,@object        # @.str.int
	.section	.rodata,"a",@progbits
	.globl	.str.int
.str.int:
	.asciz	"%d"
	.size	.str.int, 3

	.type	.str.double,@object     # @.str.double
	.globl	.str.double
.str.double:
	.asciz	"%.16e"
	.size	.str.double, 6

	.type	.str.true,@object       # @.str.true
	.globl	.str.true
.str.true:
	.asciz	"true"
	.size	.str.true, 5

	.type	.str.false,@object      # @.str.false
	.globl	.str.false
.str.false:
	.asciz	"false"
	.size	.str.false, 6


	.section	".note.GNU-stack","",@progbits
