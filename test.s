	.text
	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
	addi sp, sp, -16
	mv s0, s0
	sw s0, 12(sp)
	mv s1, s1
	sw s1, 8(sp)
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 4(sp)
	li a0, 4
	mv a0, a0
	call malloc
	mv s1, a0
	li ra, 40
	addi a0, ra, 4
	mv a0, a0
	call malloc
	mv a0, a0
	li ra, 10
	sw ra, 0(a0)
	addi a1, a0, 4
	li ra, 0
	j .main_.bb1
.main_.bb1:
	slti t0, ra, 10
	bne t0, zero, .main_.bb2
	j .main_.bb4
.main_.bb2:
	li t0, 4
	mul t0, ra, t0
	add t1, a1, t0
	li t0, 9
	sub t0, t0, ra
	sw t0, 0(t1)
	j .main_.bb3
.main_.bb3:
	addi ra, ra, 1
	mv ra, ra
	j .main_.bb1
.main_.bb4:
	mv a0, s1
	mv a1, a1
	call init
	la a0, .str.0
	call print
	mv a0, s1
	call tostring
	mv a0, a0
	mv a0, a0
	call println
	li a0, 4
	mv a0, a0
	call malloc
	mv s0, a0
	mv a0, s0
	mv a1, s1
	call copy
	mv a0, a0
	j .main_.bb5
.main_.bb5:
	mv a0, s0
	li a1, 3
	mv a1, a1
	li a2, 817
	mv a2, a2
	call set
	mv a0, a0
	bne a0, zero, .main_.bb6
	j .main_.bb9
.main_.bb6:
	la a0, .str.1
	call println
	j .main_.bb7
.main_.bb7:
	la a0, .str.2
	call print
	mv a0, s0
	call tostring
	mv a0, a0
	mv a0, a0
	call println
	la a0, .str.3
	call print
	mv a0, s1
	mv a1, s0
	call add
	mv a0, a0
	mv a0, a0
	call tostring
	mv a0, a0
	mv a0, a0
	call println
	la a0, .str.4
	call print
	mv a0, s1
	mv a1, s0
	call dot
	mv a0, a0
	mv a0, a0
	call toString
	mv a0, a0
	mv a0, a0
	call println
	la a0, .str.5
	call print
	li a1, 8
	mv a0, s0
	mv a1, a1
	call scalarInPlaceMultiply
	mv a0, a0
	mv a0, a0
	call tostring
	mv a0, a0
	mv a0, a0
	call println
	li a0, 0
	j .main_.bb8
.main_.bb8:
	mv a0, a0
	lw s0, 12(sp)
	mv s0, s0
	lw s1, 8(sp)
	mv s1, s1
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 4(sp)
	mv ra, ra
	addi sp, sp, 16
	ret
.main_.bb9:
	j .main_.bb7

	.globl	init
	.p2align	1
	.type	init,@function
init:
.init_.bb0:
	addi sp, sp, -32
	mv s0, s0
	sw s0, 28(sp)
	mv s1, s1
	sw s1, 24(sp)
	mv s2, s2
	sw s2, 20(sp)
	mv s3, s3
	sw s3, 16(sp)
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 12(sp)
	mv s3, a0
	mv s2, a1
	j .init_.bb1
.init_.bb1:
	xori ra, s2, 0
	seqz ra, ra
	bne ra, zero, .init_.bb2
	j .init_.bb4
.init_.bb2:
	li s0, 0
	j .init_.bb3
.init_.bb3:
	lw s0, 28(sp)
	mv s0, s0
	lw s1, 24(sp)
	mv s1, s1
	lw s2, 20(sp)
	mv s2, s2
	lw s3, 16(sp)
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 12(sp)
	mv ra, ra
	addi sp, sp, 32
	ret
.init_.bb4:
	addi s1, s3, 0
	mv a0, s2
	call _size
	mv s0, a0
	li ra, 4
	mul ra, s0, ra
	addi a0, ra, 4
	mv a0, a0
	call malloc
	mv a0, a0
	sw s0, 0(a0)
	addi ra, a0, 4
	sw ra, 0(s1)
	li s0, 0
	j .init_.bb5
.init_.bb5:
	mv a0, s2
	call _size
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .init_.bb6
	j .init_.bb8
.init_.bb6:
	addi ra, s3, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add t0, t0, ra
	li ra, 4
	mul ra, s0, ra
	add ra, s2, ra
	lw ra, 0(ra)
	sw ra, 0(t0)
	j .init_.bb7
.init_.bb7:
	addi s0, s0, 1
	mv s0, s0
	j .init_.bb5
.init_.bb8:
	mv s0, s0
	j .init_.bb3

	.globl	getDim
	.p2align	1
	.type	getDim,@function
getDim:
.getDim_.bb0:
	addi sp, sp, -16
	mv s0, s0
	mv s1, s1
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 12(sp)
	mv a0, a0
	j .getDim_.bb1
.getDim_.bb1:
	addi ra, a0, 0
	lw ra, 0(ra)
	xori ra, ra, 0
	seqz ra, ra
	bne ra, zero, .getDim_.bb2
	j .getDim_.bb4
.getDim_.bb2:
	li a0, 0
	j .getDim_.bb3
.getDim_.bb3:
	mv a0, a0
	mv s0, s0
	mv s1, s1
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 12(sp)
	mv ra, ra
	addi sp, sp, 16
	ret
.getDim_.bb4:
	addi ra, a0, 0
	lw a0, 0(ra)
	mv a0, a0
	call _size
	mv a0, a0
	mv a0, a0
	j .getDim_.bb3

	.globl	dot
	.p2align	1
	.type	dot,@function
dot:
.dot_.bb0:
	addi sp, sp, -32
	mv s0, s0
	sw s0, 28(sp)
	mv s1, s1
	sw s1, 24(sp)
	mv s2, s2
	sw s2, 20(sp)
	mv s3, s3
	sw s3, 16(sp)
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 12(sp)
	mv s3, a0
	mv s2, a1
	li s0, 0
	li s1, 0
	j .dot_.bb1
.dot_.bb1:
	call malloc
	mv a0, a0
	slt ra, s1, a0
	bne ra, zero, .dot_.bb2
	j .dot_.bb3
.dot_.bb2:
	addi ra, s3, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw t1, 0(ra)
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	mul s0, t1, ra
	addi s1, s1, 1
	mv s0, s0
	mv s1, s1
	j .dot_.bb1
.dot_.bb3:
	mv s0, s0
	j .dot_.bb4
.dot_.bb4:
	mv a0, s0
	lw s0, 28(sp)
	mv s0, s0
	lw s1, 24(sp)
	mv s1, s1
	lw s2, 20(sp)
	mv s2, s2
	lw s3, 16(sp)
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 12(sp)
	mv ra, ra
	addi sp, sp, 32
	ret

	.globl	scalarInPlaceMultiply
	.p2align	1
	.type	scalarInPlaceMultiply,@function
scalarInPlaceMultiply:
.scalarInPlaceMultiply_.bb0:
	addi sp, sp, -16
	mv s0, s0
	sw s0, 12(sp)
	mv s1, s1
	sw s1, 8(sp)
	mv s2, s2
	sw s2, 4(sp)
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 0(sp)
	mv s2, a0
	mv s1, a1
	j .scalarInPlaceMultiply_.bb1
.scalarInPlaceMultiply_.bb1:
	addi ra, s2, 0
	lw ra, 0(ra)
	xori ra, ra, 0
	seqz ra, ra
	bne ra, zero, .scalarInPlaceMultiply_.bb2
	j .scalarInPlaceMultiply_.bb4
.scalarInPlaceMultiply_.bb2:
	li s0, 0
	li a0, 0
	j .scalarInPlaceMultiply_.bb3
.scalarInPlaceMultiply_.bb3:
	mv a0, a0
	lw s0, 12(sp)
	mv s0, s0
	lw s1, 8(sp)
	mv s1, s1
	lw s2, 4(sp)
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 0(sp)
	mv ra, ra
	addi sp, sp, 16
	ret
.scalarInPlaceMultiply_.bb4:
	li s0, 0
	j .scalarInPlaceMultiply_.bb5
.scalarInPlaceMultiply_.bb5:
	call malloc
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .scalarInPlaceMultiply_.bb6
	j .scalarInPlaceMultiply_.bb8
.scalarInPlaceMultiply_.bb6:
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add t1, t0, ra
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw ra, 0(ra)
	mul ra, s1, ra
	sw ra, 0(t1)
	j .scalarInPlaceMultiply_.bb7
.scalarInPlaceMultiply_.bb7:
	addi s0, s0, 1
	mv s0, s0
	j .scalarInPlaceMultiply_.bb5
.scalarInPlaceMultiply_.bb8:
	mv s0, s0
	mv a0, s2
	j .scalarInPlaceMultiply_.bb3

	.globl	add
	.p2align	1
	.type	add,@function
add:
.add_.bb0:
	addi sp, sp, -32
	mv s0, s0
	sw s0, 28(sp)
	mv s1, s1
	sw s1, 24(sp)
	mv s2, s2
	sw s2, 20(sp)
	mv s3, s3
	sw s3, 16(sp)
	mv s4, s4
	sw s4, 12(sp)
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 8(sp)
	mv s4, a0
	mv s3, a1
	j .add_.bb1
.add_.bb1:
	call malloc
	mv s0, a0
	mv a0, s3
	call getDim
	mv a0, a0
	xor ra, s0, a0
	snez ra, ra
	bne ra, zero, .add_.bb13
	j .add_.bb11
.add_.bb2:
	li ra, 1
	j .add_.bb3
.add_.bb3:
	bne ra, zero, .add_.bb4
	j .add_.bb6
.add_.bb4:
	li s0, 0
	li s2, 0
	li a0, 0
	j .add_.bb5
.add_.bb5:
	mv a0, a0
	lw s0, 28(sp)
	mv s0, s0
	lw s1, 24(sp)
	mv s1, s1
	lw s2, 20(sp)
	mv s2, s2
	lw s3, 16(sp)
	mv s3, s3
	lw s4, 12(sp)
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 8(sp)
	mv ra, ra
	addi sp, sp, 32
	ret
.add_.bb6:
	li a0, 4
	mv a0, a0
	call malloc
	mv s2, a0
	addi s1, s2, 0
	call malloc
	mv s0, a0
	li ra, 4
	mul ra, s0, ra
	addi a0, ra, 4
	mv a0, a0
	call malloc
	mv a0, a0
	sw s0, 0(a0)
	addi ra, a0, 4
	sw ra, 0(s1)
	li s0, 0
	j .add_.bb7
.add_.bb7:
	call malloc
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .add_.bb8
	j .add_.bb10
.add_.bb8:
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add t2, t0, ra
	addi ra, s4, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw t1, 0(ra)
	addi ra, s3, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw ra, 0(ra)
	add ra, t1, ra
	sw ra, 0(t2)
	j .add_.bb9
.add_.bb9:
	addi s0, s0, 1
	mv s0, s0
	j .add_.bb7
.add_.bb10:
	mv s0, s0
	mv s2, s2
	mv a0, s2
	j .add_.bb5
.add_.bb11:
	call malloc
	mv a0, a0
	xori ra, a0, 0
	seqz ra, ra
	bne ra, zero, .add_.bb14
	j .add_.bb12
.add_.bb12:
	li ra, 0
	j .add_.bb3
.add_.bb13:
	j .add_.bb2
.add_.bb14:
	j .add_.bb2

	.globl	set
	.p2align	1
	.type	set,@function
set:
.set_.bb0:
	addi sp, sp, -16
	mv s0, s0
	sw s0, 12(sp)
	mv s1, s1
	sw s1, 8(sp)
	mv s2, s2
	sw s2, 4(sp)
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 0(sp)
	mv s2, a0
	mv s1, a1
	mv s0, a2
	j .set_.bb1
.set_.bb1:
	call malloc
	mv a0, a0
	slt ra, a0, s1
	bne ra, zero, .set_.bb2
	j .set_.bb4
.set_.bb2:
	li a0, 0
	j .set_.bb3
.set_.bb3:
	mv a0, a0
	lw s0, 12(sp)
	mv s0, s0
	lw s1, 8(sp)
	mv s1, s1
	lw s2, 4(sp)
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 0(sp)
	mv ra, ra
	addi sp, sp, 16
	ret
.set_.bb4:
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	sw s0, 0(ra)
	li a0, 1
	j .set_.bb3

	.globl	tostring
	.p2align	1
	.type	tostring,@function
tostring:
.tostring_.bb0:
	addi sp, sp, -16
	mv s0, s0
	sw s0, 12(sp)
	mv s1, s1
	sw s1, 8(sp)
	mv s2, s2
	sw s2, 4(sp)
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 0(sp)
	mv s2, a0
	j .tostring_.bb1
.tostring_.bb1:
	call malloc
	mv a0, a0
	slt ra, zero, a0
	bne ra, zero, .tostring_.bb2
	j .tostring_.bb9
.tostring_.bb2:
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 0
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call toString
	mv a1, a0
	la a0, .str.6
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .tostring_.bb3
.tostring_.bb3:
	li s1, 1
	mv s0, a0
	j .tostring_.bb4
.tostring_.bb4:
	call malloc
	mv a0, a0
	slt ra, s1, a0
	bne ra, zero, .tostring_.bb5
	j .tostring_.bb7
.tostring_.bb5:
	mv a0, s0
	la a1, .str.7
	call string_strcat
	mv s0, a0
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call toString
	mv a1, a0
	mv a0, s0
	mv a1, a1
	call string_strcat
	mv a0, a0
	j .tostring_.bb6
.tostring_.bb6:
	addi s1, s1, 1
	mv s1, s1
	mv s0, a0
	j .tostring_.bb4
.tostring_.bb7:
	mv a0, s0
	la a1, .str.8
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .tostring_.bb8
.tostring_.bb8:
	mv a0, a0
	lw s0, 12(sp)
	mv s0, s0
	lw s1, 8(sp)
	mv s1, s1
	lw s2, 4(sp)
	mv s2, s2
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 0(sp)
	mv ra, ra
	addi sp, sp, 16
	ret
.tostring_.bb9:
	mv a0, s5
	j .tostring_.bb3

	.globl	copy
	.p2align	1
	.type	copy,@function
copy:
.copy_.bb0:
	addi sp, sp, -32
	mv s0, s0
	sw s0, 28(sp)
	mv s1, s1
	sw s1, 24(sp)
	mv s2, s2
	sw s2, 20(sp)
	mv s3, s3
	sw s3, 16(sp)
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	mv ra, ra
	sw ra, 12(sp)
	mv s3, a0
	mv s2, a1
	j .copy_.bb1
.copy_.bb1:
	xori ra, s2, 0
	seqz ra, ra
	bne ra, zero, .copy_.bb2
	j .copy_.bb4
.copy_.bb2:
	li s0, 0
	li a0, 0
	j .copy_.bb3
.copy_.bb3:
	mv a0, a0
	lw s0, 28(sp)
	mv s0, s0
	lw s1, 24(sp)
	mv s1, s1
	lw s2, 20(sp)
	mv s2, s2
	lw s3, 16(sp)
	mv s3, s3
	mv s4, s4
	mv s5, s5
	mv s6, s6
	mv s7, s7
	mv s8, s8
	mv s9, s9
	mv s10, s10
	mv s11, s11
	lw ra, 12(sp)
	mv ra, ra
	addi sp, sp, 32
	ret
.copy_.bb4:
	j .copy_.bb5
.copy_.bb5:
	mv a0, s2
	call getDim
	mv a0, a0
	xori ra, a0, 0
	seqz ra, ra
	bne ra, zero, .copy_.bb6
	j .copy_.bb8
.copy_.bb6:
	addi ra, s3, 0
	sw zero, 0(ra)
	li s0, 0
	j .copy_.bb7
.copy_.bb7:
	mv s0, s0
	li a0, 1
	j .copy_.bb3
.copy_.bb8:
	addi s1, s3, 0
	mv a0, s2
	call getDim
	mv s0, a0
	li ra, 4
	mul ra, s0, ra
	addi a0, ra, 4
	mv a0, a0
	call malloc
	mv a0, a0
	sw s0, 0(a0)
	addi ra, a0, 4
	sw ra, 0(s1)
	li s0, 0
	j .copy_.bb9
.copy_.bb9:
	call malloc
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .copy_.bb10
	j .copy_.bb12
.copy_.bb10:
	addi ra, s3, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add t1, t0, ra
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw ra, 0(ra)
	sw ra, 0(t1)
	j .copy_.bb11
.copy_.bb11:
	addi s0, s0, 1
	mv s0, s0
	j .copy_.bb9
.copy_.bb12:
	mv s0, s0
	j .copy_.bb7

	.type	.str.0 ,@object
	.section	.rodata
.str.0:
	.asciz	"vector x: "
	.size	.str.0, 10

	.type	.str.1 ,@object
	.section	.rodata
.str.1:
	.asciz	"excited!"
	.size	.str.1, 10

	.type	.str.2 ,@object
	.section	.rodata
.str.2:
	.asciz	"vector y: "
	.size	.str.2, 10

	.type	.str.3 ,@object
	.section	.rodata
.str.3:
	.asciz	"x + y: "
	.size	.str.3, 10

	.type	.str.4 ,@object
	.section	.rodata
.str.4:
	.asciz	"x * y: "
	.size	.str.4, 10

	.type	.str.5 ,@object
	.section	.rodata
.str.5:
	.asciz	"(1 << 3) * y: "
	.size	.str.5, 10

	.type	.str.6 ,@object
	.section	.rodata
.str.6:
	.asciz	"( "
	.size	.str.6, 10

	.type	.str.7 ,@object
	.section	.rodata
.str.7:
	.asciz	", "
	.size	.str.7, 10

	.type	.str.8 ,@object
	.section	.rodata
.str.8:
	.asciz	" )"
	.size	.str.8, 10

