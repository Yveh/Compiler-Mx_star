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
	call vector_init
	la a0, .str.0
	call print
	mv a0, s1
	call vector_tostring
	mv a0, a0
	mv a0, a0
	call println
	li a0, 4
	mv a0, a0
	call malloc
	mv s0, a0
	mv a0, s0
	mv a1, s1
	call vector_copy
	mv a0, a0
	j .main_.bb5
.main_.bb5:
	mv a0, s0
	li a1, 3
	mv a1, a1
	li a2, 817
	mv a2, a2
	call vector_set
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
	call vector_tostring
	mv a0, a0
	mv a0, a0
	call println
	la a0, .str.3
	call print
	mv a0, s1
	mv a1, s0
	call vector_add
	mv a0, a0
	mv a0, a0
	call vector_tostring
	mv a0, a0
	mv a0, a0
	call println
	la a0, .str.4
	call print
	mv a0, s1
	mv a1, s0
	call vector_dot
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
	call vector_scalarInPlaceMultiply
	mv a0, a0
	mv a0, a0
	call vector_tostring
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

	.globl	vector_init
	.p2align	1
	.type	vector_init,@function
vector_init:
.vector_init_.bb0:
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
	j .vector_init_.bb1
.vector_init_.bb1:
	xori ra, s2, 0
	seqz ra, ra
	bne ra, zero, .vector_init_.bb2
	j .vector_init_.bb4
.vector_init_.bb2:
	li s0, 0
	j .vector_init_.bb3
.vector_init_.bb3:
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
.vector_init_.bb4:
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
	j .vector_init_.bb5
.vector_init_.bb5:
	mv a0, s2
	call _size
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .vector_init_.bb6
	j .vector_init_.bb8
.vector_init_.bb6:
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
	j .vector_init_.bb7
.vector_init_.bb7:
	addi s0, s0, 1
	mv s0, s0
	j .vector_init_.bb5
.vector_init_.bb8:
	mv s0, s0
	j .vector_init_.bb3

	.globl	vector_getDim
	.p2align	1
	.type	vector_getDim,@function
vector_getDim:
.vector_getDim_.bb0:
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
	j .vector_getDim_.bb1
.vector_getDim_.bb1:
	addi ra, a0, 0
	lw ra, 0(ra)
	xori ra, ra, 0
	seqz ra, ra
	bne ra, zero, .vector_getDim_.bb2
	j .vector_getDim_.bb4
.vector_getDim_.bb2:
	li a0, 0
	j .vector_getDim_.bb3
.vector_getDim_.bb3:
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
.vector_getDim_.bb4:
	addi ra, a0, 0
	lw a0, 0(ra)
	mv a0, a0
	call _size
	mv a0, a0
	mv a0, a0
	j .vector_getDim_.bb3

	.globl	vector_dot
	.p2align	1
	.type	vector_dot,@function
vector_dot:
.vector_dot_.bb0:
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
	j .vector_dot_.bb1
.vector_dot_.bb1:
	call malloc
	mv a0, a0
	slt ra, s1, a0
	bne ra, zero, .vector_dot_.bb2
	j .vector_dot_.bb3
.vector_dot_.bb2:
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
	j .vector_dot_.bb1
.vector_dot_.bb3:
	mv s0, s0
	j .vector_dot_.bb4
.vector_dot_.bb4:
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

	.globl	vector_scalarInPlaceMultiply
	.p2align	1
	.type	vector_scalarInPlaceMultiply,@function
vector_scalarInPlaceMultiply:
.vector_scalarInPlaceMultiply_.bb0:
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
	j .vector_scalarInPlaceMultiply_.bb1
.vector_scalarInPlaceMultiply_.bb1:
	addi ra, s2, 0
	lw ra, 0(ra)
	xori ra, ra, 0
	seqz ra, ra
	bne ra, zero, .vector_scalarInPlaceMultiply_.bb2
	j .vector_scalarInPlaceMultiply_.bb4
.vector_scalarInPlaceMultiply_.bb2:
	li s0, 0
	li a0, 0
	j .vector_scalarInPlaceMultiply_.bb3
.vector_scalarInPlaceMultiply_.bb3:
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
.vector_scalarInPlaceMultiply_.bb4:
	li s0, 0
	j .vector_scalarInPlaceMultiply_.bb5
.vector_scalarInPlaceMultiply_.bb5:
	call malloc
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .vector_scalarInPlaceMultiply_.bb6
	j .vector_scalarInPlaceMultiply_.bb8
.vector_scalarInPlaceMultiply_.bb6:
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
	j .vector_scalarInPlaceMultiply_.bb7
.vector_scalarInPlaceMultiply_.bb7:
	addi s0, s0, 1
	mv s0, s0
	j .vector_scalarInPlaceMultiply_.bb5
.vector_scalarInPlaceMultiply_.bb8:
	mv s0, s0
	mv a0, s2
	j .vector_scalarInPlaceMultiply_.bb3

	.globl	vector_add
	.p2align	1
	.type	vector_add,@function
vector_add:
.vector_add_.bb0:
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
	j .vector_add_.bb1
.vector_add_.bb1:
	call malloc
	mv s0, a0
	mv a0, s3
	call vector_getDim
	mv a0, a0
	xor ra, s0, a0
	snez ra, ra
	bne ra, zero, .vector_add_.bb13
	j .vector_add_.bb11
.vector_add_.bb2:
	li ra, 1
	j .vector_add_.bb3
.vector_add_.bb3:
	bne ra, zero, .vector_add_.bb4
	j .vector_add_.bb6
.vector_add_.bb4:
	li s0, 0
	li s2, 0
	li a0, 0
	j .vector_add_.bb5
.vector_add_.bb5:
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
.vector_add_.bb6:
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
	j .vector_add_.bb7
.vector_add_.bb7:
	call malloc
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .vector_add_.bb8
	j .vector_add_.bb10
.vector_add_.bb8:
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
	j .vector_add_.bb9
.vector_add_.bb9:
	addi s0, s0, 1
	mv s0, s0
	j .vector_add_.bb7
.vector_add_.bb10:
	mv s0, s0
	mv s2, s2
	mv a0, s2
	j .vector_add_.bb5
.vector_add_.bb11:
	call malloc
	mv a0, a0
	xori ra, a0, 0
	seqz ra, ra
	bne ra, zero, .vector_add_.bb14
	j .vector_add_.bb12
.vector_add_.bb12:
	li ra, 0
	j .vector_add_.bb3
.vector_add_.bb13:
	j .vector_add_.bb2
.vector_add_.bb14:
	j .vector_add_.bb2

	.globl	vector_set
	.p2align	1
	.type	vector_set,@function
vector_set:
.vector_set_.bb0:
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
	j .vector_set_.bb1
.vector_set_.bb1:
	call malloc
	mv a0, a0
	slt ra, a0, s1
	bne ra, zero, .vector_set_.bb2
	j .vector_set_.bb4
.vector_set_.bb2:
	li a0, 0
	j .vector_set_.bb3
.vector_set_.bb3:
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
.vector_set_.bb4:
	addi ra, s2, 0
	lw t0, 0(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	sw s0, 0(ra)
	li a0, 1
	j .vector_set_.bb3

	.globl	vector_tostring
	.p2align	1
	.type	vector_tostring,@function
vector_tostring:
.vector_tostring_.bb0:
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
	j .vector_tostring_.bb1
.vector_tostring_.bb1:
	call malloc
	mv a0, a0
	slt ra, zero, a0
	bne ra, zero, .vector_tostring_.bb2
	j .vector_tostring_.bb9
.vector_tostring_.bb2:
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
	j .vector_tostring_.bb3
.vector_tostring_.bb3:
	li s1, 1
	mv s0, a0
	j .vector_tostring_.bb4
.vector_tostring_.bb4:
	call malloc
	mv a0, a0
	slt ra, s1, a0
	bne ra, zero, .vector_tostring_.bb5
	j .vector_tostring_.bb7
.vector_tostring_.bb5:
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
	j .vector_tostring_.bb6
.vector_tostring_.bb6:
	addi s1, s1, 1
	mv s1, s1
	mv s0, a0
	j .vector_tostring_.bb4
.vector_tostring_.bb7:
	mv a0, s0
	la a1, .str.8
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .vector_tostring_.bb8
.vector_tostring_.bb8:
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
.vector_tostring_.bb9:
	la a0, .str.6
	j .vector_tostring_.bb3

	.globl	vector_copy
	.p2align	1
	.type	vector_copy,@function
vector_copy:
.vector_copy_.bb0:
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
	j .vector_copy_.bb1
.vector_copy_.bb1:
	xori ra, s2, 0
	seqz ra, ra
	bne ra, zero, .vector_copy_.bb2
	j .vector_copy_.bb4
.vector_copy_.bb2:
	li s0, 0
	li a0, 0
	j .vector_copy_.bb3
.vector_copy_.bb3:
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
.vector_copy_.bb4:
	j .vector_copy_.bb5
.vector_copy_.bb5:
	mv a0, s2
	call vector_getDim
	mv a0, a0
	xori ra, a0, 0
	seqz ra, ra
	bne ra, zero, .vector_copy_.bb6
	j .vector_copy_.bb8
.vector_copy_.bb6:
	addi ra, s3, 0
	sw zero, 0(ra)
	li s0, 0
	j .vector_copy_.bb7
.vector_copy_.bb7:
	mv s0, s0
	li a0, 1
	j .vector_copy_.bb3
.vector_copy_.bb8:
	addi s1, s3, 0
	mv a0, s2
	call vector_getDim
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
	j .vector_copy_.bb9
.vector_copy_.bb9:
	call malloc
	mv a0, a0
	slt ra, s0, a0
	bne ra, zero, .vector_copy_.bb10
	j .vector_copy_.bb12
.vector_copy_.bb10:
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
	j .vector_copy_.bb11
.vector_copy_.bb11:
	addi s0, s0, 1
	mv s0, s0
	j .vector_copy_.bb9
.vector_copy_.bb12:
	mv s0, s0
	j .vector_copy_.bb7

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

