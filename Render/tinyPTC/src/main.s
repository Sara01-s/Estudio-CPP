	.file	"main.cpp"
	.text
	.section	.rodata
	.align 4
	.type	_ZL1R, @object
	.size	_ZL1R, 4
_ZL1R:
	.long	16711680
	.align 4
	.type	_ZL1G, @object
	.size	_ZL1G, 4
_ZL1G:
	.long	65280
	.align 4
	.type	_ZL1B, @object
	.size	_ZL1B, 4
_ZL1B:
	.long	255
	.globl	_window
	.bss
	.align 32
	.type	_window, @object
	.size	_window, 921600
_window:
	.zero	921600
	.globl	_sprite
	.data
	.align 16
	.type	_sprite, @object
	.size	_sprite, 24
_sprite:
	.long	16711680
	.long	65280
	.long	255
	.long	16711680
	.long	65280
	.long	65280
	.section	.rodata
.LC0:
	.string	"window"
	.text
	.globl	main
	.type	main, @function
main:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$360, %edx
	movl	$640, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	ptc_open@PLT
.L8:
	movl	$0, -28(%rbp)
	jmp	.L2
.L3:
	movl	-28(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	_window(%rip), %rax
	movl	$16711680, (%rdx,%rax)
	addl	$1, -28(%rbp)
.L2:
	cmpl	$230399, -28(%rbp)
	jbe	.L3
	leaq	_window(%rip), %rax
	movq	%rax, -16(%rbp)
	leaq	_sprite(%rip), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L4
.L7:
	movl	$0, -20(%rbp)
	jmp	.L5
.L6:
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	%edx, (%rax)
	addq	$4, -16(%rbp)
	addq	$4, -8(%rbp)
	addl	$1, -20(%rbp)
.L5:
	cmpl	$3, -20(%rbp)
	jbe	.L6
	addq	$2544, -8(%rbp)
	addl	$1, -24(%rbp)
.L4:
	cmpl	$3, -24(%rbp)
	jbe	.L7
	leaq	_window(%rip), %rax
	movq	%rax, %rdi
	call	ptc_update@PLT
	jmp	.L8
	.cfi_endproc
.LFE15:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
