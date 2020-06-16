	.text
	.globl	square
	.p2align	1
	.type	square,@function
square:
.square_.bb0:
	addi sp, sp, 0
	lui t2, %hi(g7)
	lw t2, %lo(g7)(t2)
	rem a1, a0, t2
	lui t2, %hi(g7)
	lw t2, %lo(g7)(t2)
	rem t2, a0, t2
	mul a0, a1, t2
	j .square_.bb1
.square_.bb1:
	addi sp, sp, 0
	ret

	.globl	gcd
	.p2align	1
	.type	gcd,@function
gcd:
.gcd_.bb0:
	addi sp, sp, -16
	sw ra, 12(sp)
	mv ra, a0
	j .gcd_.bb1
.gcd_.bb1:
	xori t0, a1, 0
	seqz t0, t0
	bne t0, zero, .gcd_.bb2
	j .gcd_.bb4
.gcd_.bb2:
	j .gcd_.bb3
.gcd_.bb3:
	mv a0, ra
	lw ra, 12(sp)
	addi sp, sp, 16
	ret
.gcd_.bb4:
	j .gcd_.bb5
.gcd_.bb5:
	slt t0, ra, a1
	bne t0, zero, .gcd_.bb6
	j .gcd_.bb7
.gcd_.bb6:
	mv a0, a1
	mv a1, ra
	call gcd
	mv ra, a0
	j .gcd_.bb3
.gcd_.bb7:
	rem ra, ra, a1
	mv a0, a1
	mv a1, ra
	call gcd
	mv ra, a0
	j .gcd_.bb3

	.globl	lcm
	.p2align	1
	.type	lcm,@function
lcm:
.lcm_.bb0:
	addi sp, sp, -16
	sw s0, 12(sp)
	sw s1, 8(sp)
	sw ra, 4(sp)
	mv s1, a0
	mv s0, a1
	mv a0, s1
	mv a1, s0
	call gcd
	div ra, s1, a0
	mul a0, ra, s0
	j .lcm_.bb1
.lcm_.bb1:
	lw s0, 12(sp)
	lw s1, 8(sp)
	lw ra, 4(sp)
	addi sp, sp, 16
	ret

	.globl	Rand
	.p2align	1
	.type	Rand,@function
Rand:
.Rand_.bb0:
	addi sp, sp, 0
	li t0, 1
	j .Rand_.bb1
.Rand_.bb1:
	slti a0, t0, 3
	bne a0, zero, .Rand_.bb2
	j .Rand_.bb4
.Rand_.bb2:
	lui a0, %hi(g17)
	lw a1, %lo(g17)(a0)
	lui a0, %hi(g14)
	lw a0, %lo(g14)(a0)
	mul a1, a1, a0
	lui a0, %hi(g15)
	lw a0, %lo(g15)(a0)
	add a1, a1, a0
	lui a0, %hi(g16)
	lw a0, %lo(g16)(a0)
	rem a1, a1, a0
	lui a0, %hi(g17)
	sw a1, %lo(g17)(a0)
	j .Rand_.bb3
.Rand_.bb3:
	addi t0, t0, 1
	j .Rand_.bb1
.Rand_.bb4:
	j .Rand_.bb5
.Rand_.bb5:
	lui t0, %hi(g17)
	lw t0, %lo(g17)(t0)
	slti t0, t0, 0
	bne t0, zero, .Rand_.bb6
	j .Rand_.bb9
.Rand_.bb6:
	lui t0, %hi(g17)
	lw t0, %lo(g17)(t0)
	sub a0, zero, t0
	lui t0, %hi(g17)
	sw a0, %lo(g17)(t0)
	j .Rand_.bb7
.Rand_.bb7:
	lui t0, %hi(g17)
	lw a0, %lo(g17)(t0)
	j .Rand_.bb8
.Rand_.bb8:
	addi sp, sp, 0
	ret
.Rand_.bb9:
	j .Rand_.bb7

	.globl	RandRange
	.p2align	1
	.type	RandRange,@function
RandRange:
.RandRange_.bb0:
	addi sp, sp, -16
	sw s0, 12(sp)
	sw s1, 8(sp)
	sw ra, 4(sp)
	mv s1, a0
	mv s0, a1
	call Rand
	sub ra, s0, s1
	addi ra, ra, 1
	rem ra, a0, ra
	add ra, s1, ra
	addi a0, ra, 1
	j .RandRange_.bb1
.RandRange_.bb1:
	lw s0, 12(sp)
	lw s1, 8(sp)
	lw ra, 4(sp)
	addi sp, sp, 16
	ret

	.globl	init
	.p2align	1
	.type	init,@function
init:
.init_.bb0:
	addi sp, sp, -32
	sw s0, 28(sp)
	sw s1, 24(sp)
	sw s2, 20(sp)
	sw s3, 16(sp)
	sw ra, 12(sp)
	li ra, 560020
	addi a0, ra, 4
	call malloc
	li ra, 140005
	sw ra, 0(a0)
	addi s3, a0, 4
	li ra, 2
	j .init_.bb1
.init_.bb1:
	lui t0, %hi(g7)
	lw t0, %lo(g7)(t0)
	slt t0, ra, t0
	bne t0, zero, .init_.bb2
	j .init_.bb4
.init_.bb2:
	li t0, 4
	mul t0, ra, t0
	add t0, s3, t0
	sw ra, 0(t0)
	j .init_.bb3
.init_.bb3:
	addi ra, ra, 1
	j .init_.bb1
.init_.bb4:
	li s2, 2
	li s1, 0
	j .init_.bb5
.init_.bb5:
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	slt ra, s2, ra
	bne ra, zero, .init_.bb6
	j .init_.bb12
.init_.bb6:
	li s1, 1
	j .init_.bb7
.init_.bb7:
	li ra, 15
	slt ra, ra, s1
	xori ra, ra, 1
	bne ra, zero, .init_.bb8
	j .init_.bb10
.init_.bb8:
	li ra, 4
	mul ra, s2, ra
	add s0, s3, ra
	li ra, 4
	mul ra, s2, ra
	add ra, s3, ra
	lw a0, 0(ra)
	call square
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	rem ra, a0, ra
	sw ra, 0(s0)
	j .init_.bb9
.init_.bb9:
	addi s1, s1, 1
	j .init_.bb7
.init_.bb10:
	j .init_.bb11
.init_.bb11:
	addi s2, s2, 1
	j .init_.bb5
.init_.bb12:
	li s2, 2
	li s1, 0
	li s0, 0
	j .init_.bb13
.init_.bb13:
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	slt ra, s2, ra
	bne ra, zero, .init_.bb14
	j .init_.bb23
.init_.bb14:
	li ra, 4
	mul ra, s2, ra
	add ra, s3, ra
	lw a0, 0(ra)
	li s0, 1
	j .init_.bb15
.init_.bb15:
	j .init_.bb16
.init_.bb16:
	call square
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	rem s1, a0, ra
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 4
	mul ra, s1, ra
	add t0, t0, ra
	li ra, 1
	sw ra, 0(t0)
	j .init_.bb17
.init_.bb17:
	li ra, 4
	mul ra, s2, ra
	add ra, s3, ra
	lw ra, 0(ra)
	xor ra, s1, ra
	seqz ra, ra
	bne ra, zero, .init_.bb18
	j .init_.bb21
.init_.bb18:
	j .init_.bb19
.init_.bb19:
	lui ra, %hi(g9)
	lw a0, %lo(g9)(ra)
	mv a1, s0
	call lcm
	lui ra, %hi(g9)
	sw a0, %lo(g9)(ra)
	j .init_.bb20
.init_.bb20:
	addi s2, s2, 1
	j .init_.bb13
.init_.bb21:
	j .init_.bb22
.init_.bb22:
	addi s0, s0, 1
	mv a0, s1
	j .init_.bb15
.init_.bb23:
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 0
	add t0, t0, ra
	li ra, 1
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 4
	add t0, t0, ra
	li ra, 1
	sw ra, 0(t0)
	j .init_.bb24
.init_.bb24:
	lw s0, 28(sp)
	lw s1, 24(sp)
	lw s2, 20(sp)
	lw s3, 16(sp)
	lw ra, 12(sp)
	addi sp, sp, 32
	ret

	.globl	build
	.p2align	1
	.type	build,@function
build:
.build_.bb0:
	addi sp, sp, -32
	sw s0, 28(sp)
	sw s1, 24(sp)
	sw s2, 20(sp)
	sw s3, 16(sp)
	sw s4, 12(sp)
	sw s5, 8(sp)
	sw s6, 4(sp)
	sw ra, 0(sp)
	mv s6, a0
	mv s3, a2
	j .build_.bb1
.build_.bb1:
	xor ra, a1, s3
	seqz ra, ra
	bne ra, zero, .build_.bb2
	j .build_.bb20
.build_.bb2:
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s6, ra
	add t1, t0, ra
	lui ra, %hi(g4)
	lw t0, %lo(g4)(ra)
	li ra, 4
	mul ra, a1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	sw ra, 0(t1)
	j .build_.bb3
.build_.bb3:
	lui ra, %hi(g4)
	lw t0, %lo(g4)(ra)
	li ra, 4
	mul ra, a1, ra
	add ra, t0, ra
	lw t0, 0(ra)
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	slt ra, t0, ra
	bne ra, zero, .build_.bb4
	j .build_.bb28
.build_.bb4:
	lui ra, %hi(g4)
	lw t0, %lo(g4)(ra)
	li ra, 4
	mul ra, a1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	slti ra, ra, 0
	xori ra, ra, 1
	bne ra, zero, .build_.bb5
	j .build_.bb29
.build_.bb5:
	li s5, 1
	j .build_.bb6
.build_.bb6:
	bne s5, zero, .build_.bb7
	j .build_.bb30
.build_.bb7:
	lui ra, %hi(g1)
	lw t1, %lo(g1)(ra)
	lui ra, %hi(g4)
	lw t0, %lo(g4)(ra)
	li ra, 4
	mul ra, a1, ra
	add ra, t0, ra
	lw t0, 0(ra)
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	rem t0, t0, ra
	li ra, 4
	mul ra, t0, ra
	add ra, t1, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .build_.bb8
	j .build_.bb31
.build_.bb8:
	li s4, 1
	j .build_.bb9
.build_.bb9:
	bne s4, zero, .build_.bb10
	j .build_.bb32
.build_.bb10:
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s6, ra
	add t0, t0, ra
	li ra, 1
	sw ra, 0(t0)
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s6, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 0
	add t1, t0, ra
	lui ra, %hi(g4)
	lw t0, %lo(g4)(ra)
	li ra, 4
	mul ra, a1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	sw ra, 0(t1)
	li s3, 1
	j .build_.bb11
.build_.bb11:
	lui ra, %hi(g9)
	lw ra, %lo(g9)(ra)
	slt ra, s3, ra
	bne ra, zero, .build_.bb12
	j .build_.bb14
.build_.bb12:
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s6, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, s3, ra
	add s0, t0, ra
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s6, ra
	add ra, t0, ra
	lw t1, 0(ra)
	addi t0, s3, -1
	li ra, 4
	mul ra, t0, ra
	add ra, t1, ra
	lw a0, 0(ra)
	call square
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	rem ra, a0, ra
	sw ra, 0(s0)
	j .build_.bb13
.build_.bb13:
	addi s3, s3, 1
	j .build_.bb11
.build_.bb14:
	j .build_.bb15
.build_.bb15:
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 4
	mul ra, s6, ra
	add ra, t0, ra
	sw zero, 0(ra)
	li s2, 0
	li s1, 0
	li s0, 0
	j .build_.bb16
.build_.bb16:
	j .build_.bb17
.build_.bb17:
	lw s0, 28(sp)
	lw s1, 24(sp)
	lw s2, 20(sp)
	lw s3, 16(sp)
	lw s4, 12(sp)
	lw s5, 8(sp)
	lw s6, 4(sp)
	lw ra, 0(sp)
	addi sp, sp, 32
	ret
.build_.bb18:
	li s4, 0
	j .build_.bb9
.build_.bb19:
	li s5, 0
	j .build_.bb6
.build_.bb20:
	li ra, 2
	mul s0, s6, ra
	li ra, 2
	mul ra, s6, ra
	addi s1, ra, 1
	add t0, a1, s3
	li ra, 2
	div s2, t0, ra
	mv a0, s0
	mv a2, s2
	call build
	addi a1, s2, 1
	mv a0, s1
	mv a2, s3
	call build
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s6, ra
	add t2, t0, ra
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw t1, 0(ra)
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	add ra, t1, ra
	sw ra, 0(t2)
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s6, ra
	add t2, t0, ra
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw t1, 0(ra)
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	and ra, t1, ra
	sw ra, 0(t2)
	j .build_.bb21
.build_.bb21:
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s6, ra
	add ra, t0, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .build_.bb22
	j .build_.bb33
.build_.bb22:
	li s3, 0
	j .build_.bb23
.build_.bb23:
	lui ra, %hi(g9)
	lw ra, %lo(g9)(ra)
	slt ra, s3, ra
	bne ra, zero, .build_.bb24
	j .build_.bb26
.build_.bb24:
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s6, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, s3, ra
	add t2, t0, ra
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, s3, ra
	add ra, t0, ra
	lw t1, 0(ra)
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, s3, ra
	add ra, t0, ra
	lw ra, 0(ra)
	add ra, t1, ra
	sw ra, 0(t2)
	j .build_.bb25
.build_.bb25:
	addi s3, s3, 1
	j .build_.bb23
.build_.bb26:
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	sw zero, 0(ra)
	j .build_.bb27
.build_.bb27:
	li s5, 0
	li s4, 0
	j .build_.bb16
.build_.bb28:
	j .build_.bb19
.build_.bb29:
	j .build_.bb19
.build_.bb30:
	j .build_.bb18
.build_.bb31:
	j .build_.bb18
.build_.bb32:
	li s3, 0
	j .build_.bb15
.build_.bb33:
	li s3, 0
	j .build_.bb27

	.globl	pushdown
	.p2align	1
	.type	pushdown,@function
pushdown:
.pushdown_.bb0:
	addi sp, sp, 0
	j .pushdown_.bb1
.pushdown_.bb1:
	lui t0, %hi(g3)
	lw t1, %lo(g3)(t0)
	li t0, 4
	mul t0, a0, t0
	add t0, t1, t0
	lw t0, 0(t0)
	slt t0, zero, t0
	bne t0, zero, .pushdown_.bb2
	j .pushdown_.bb5
.pushdown_.bb2:
	li t0, 2
	mul t0, a0, t0
	li t1, 2
	mul t1, a0, t1
	addi t1, t1, 1
	lui a2, %hi(g2)
	lw a3, %lo(g2)(a2)
	li a2, 4
	mul a2, t0, a2
	add a4, a3, a2
	lui a2, %hi(g2)
	lw a3, %lo(g2)(a2)
	li a2, 4
	mul a2, t0, a2
	add a2, a3, a2
	lw a5, 0(a2)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, a0, a2
	add a2, a3, a2
	lw a2, 0(a2)
	add a3, a5, a2
	lui a2, %hi(g9)
	lw a2, %lo(g9)(a2)
	rem a2, a3, a2
	sw a2, 0(a4)
	lui a2, %hi(g12)
	lw a3, %lo(g12)(a2)
	li a2, 4
	mul a2, t0, a2
	add a4, a3, a2
	lui a2, %hi(g11)
	lw a3, %lo(g11)(a2)
	li a2, 4
	mul a2, t0, a2
	add a2, a3, a2
	lw a5, 0(a2)
	lui a2, %hi(g2)
	lw a3, %lo(g2)(a2)
	li a2, 4
	mul a2, t0, a2
	add a2, a3, a2
	lw a3, 0(a2)
	li a2, 4
	mul a2, a3, a2
	add a2, a5, a2
	lw a2, 0(a2)
	sw a2, 0(a4)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, t0, a2
	add a4, a3, a2
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, t0, a2
	add a2, a3, a2
	lw a5, 0(a2)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, a0, a2
	add a2, a3, a2
	lw a2, 0(a2)
	add a3, a5, a2
	lui a2, %hi(g9)
	lw a2, %lo(g9)(a2)
	rem a2, a3, a2
	sw a2, 0(a4)
	lui a2, %hi(g2)
	lw a3, %lo(g2)(a2)
	li a2, 4
	mul a2, t1, a2
	add a4, a3, a2
	lui a2, %hi(g2)
	lw a3, %lo(g2)(a2)
	li a2, 4
	mul a2, t1, a2
	add a2, a3, a2
	lw a5, 0(a2)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, a0, a2
	add a2, a3, a2
	lw a2, 0(a2)
	add a3, a5, a2
	lui a2, %hi(g9)
	lw a2, %lo(g9)(a2)
	rem a2, a3, a2
	sw a2, 0(a4)
	lui a2, %hi(g12)
	lw a3, %lo(g12)(a2)
	li a2, 4
	mul a2, t1, a2
	add a4, a3, a2
	lui a2, %hi(g11)
	lw a3, %lo(g11)(a2)
	li a2, 4
	mul a2, t1, a2
	add a2, a3, a2
	lw a5, 0(a2)
	lui a2, %hi(g2)
	lw a3, %lo(g2)(a2)
	li a2, 4
	mul a2, t1, a2
	add a2, a3, a2
	lw a3, 0(a2)
	li a2, 4
	mul a2, a3, a2
	add a2, a5, a2
	lw a2, 0(a2)
	sw a2, 0(a4)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, t1, a2
	add a4, a3, a2
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, t1, a2
	add a2, a3, a2
	lw a5, 0(a2)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a2, a0, a2
	add a2, a3, a2
	lw a2, 0(a2)
	add a3, a5, a2
	lui a2, %hi(g9)
	lw a2, %lo(g9)(a2)
	rem a2, a3, a2
	sw a2, 0(a4)
	lui a2, %hi(g3)
	lw a3, %lo(g3)(a2)
	li a2, 4
	mul a0, a0, a2
	add a0, a3, a0
	sw zero, 0(a0)
	j .pushdown_.bb3
.pushdown_.bb3:
	j .pushdown_.bb4
.pushdown_.bb4:
	addi sp, sp, 0
	ret
.pushdown_.bb5:
	li t1, 0
	li t0, 0
	j .pushdown_.bb3

	.globl	update
	.p2align	1
	.type	update,@function
update:
.update_.bb0:
	addi sp, sp, -32
	sw s0, 28(sp)
	sw s1, 24(sp)
	sw s2, 20(sp)
	sw s3, 16(sp)
	sw s4, 12(sp)
	sw s5, 8(sp)
	sw ra, 4(sp)
	mv s5, a0
	mv s4, a1
	mv s3, a2
	j .update_.bb1
.update_.bb1:
	lui ra, %hi(g18)
	lw ra, %lo(g18)(ra)
	slt ra, s4, ra
	xori ra, ra, 1
	bne ra, zero, .update_.bb2
	j .update_.bb39
.update_.bb2:
	lui ra, %hi(g19)
	lw ra, %lo(g19)(ra)
	slt ra, ra, s3
	xori ra, ra, 1
	bne ra, zero, .update_.bb3
	j .update_.bb40
.update_.bb3:
	li ra, 1
	j .update_.bb4
.update_.bb4:
	bne ra, zero, .update_.bb5
	j .update_.bb41
.update_.bb5:
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .update_.bb6
	j .update_.bb42
.update_.bb6:
	li ra, 1
	j .update_.bb7
.update_.bb7:
	bne ra, zero, .update_.bb8
	j .update_.bb10
.update_.bb8:
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 4
	mul ra, s5, ra
	add t1, t0, ra
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw ra, 0(ra)
	addi t0, ra, 1
	lui ra, %hi(g9)
	lw ra, %lo(g9)(ra)
	rem ra, t0, ra
	sw ra, 0(t1)
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s5, ra
	add t2, t0, ra
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw t1, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, t0, ra
	add ra, t1, ra
	lw ra, 0(ra)
	sw ra, 0(t2)
	lui ra, %hi(g3)
	lw t0, %lo(g3)(ra)
	li ra, 4
	mul ra, s5, ra
	add t1, t0, ra
	lui ra, %hi(g3)
	lw t0, %lo(g3)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw ra, 0(ra)
	addi t0, ra, 1
	lui ra, %hi(g9)
	lw ra, %lo(g9)(ra)
	rem ra, t0, ra
	sw ra, 0(t1)
	li ra, 0
	li s3, 0
	li s2, 0
	li s1, 0
	li s0, 0
	j .update_.bb9
.update_.bb9:
	lw s0, 28(sp)
	lw s1, 24(sp)
	lw s2, 20(sp)
	lw s3, 16(sp)
	lw s4, 12(sp)
	lw s5, 8(sp)
	lw ra, 4(sp)
	addi sp, sp, 32
	ret
.update_.bb10:
	j .update_.bb11
.update_.bb11:
	xor ra, s4, s3
	seqz ra, ra
	bne ra, zero, .update_.bb12
	j .update_.bb20
.update_.bb12:
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s5, ra
	add s0, t0, ra
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw a0, 0(ra)
	call square
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	rem ra, a0, ra
	sw ra, 0(s0)
	j .update_.bb13
.update_.bb13:
	lui ra, %hi(g1)
	lw t1, %lo(g1)(ra)
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, t0, ra
	add ra, t1, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .update_.bb14
	j .update_.bb43
.update_.bb14:
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s5, ra
	add t0, t0, ra
	li ra, 1
	sw ra, 0(t0)
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 0
	add t1, t0, ra
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw ra, 0(ra)
	sw ra, 0(t1)
	li s3, 1
	j .update_.bb15
.update_.bb15:
	lui ra, %hi(g9)
	lw ra, %lo(g9)(ra)
	slt ra, s3, ra
	bne ra, zero, .update_.bb16
	j .update_.bb18
.update_.bb16:
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw t0, 0(ra)
	li ra, 4
	mul ra, s3, ra
	add s0, t0, ra
	lui ra, %hi(g11)
	lw t0, %lo(g11)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw t1, 0(ra)
	addi t0, s3, -1
	li ra, 4
	mul ra, t0, ra
	add ra, t1, ra
	lw a0, 0(ra)
	call square
	lui ra, %hi(g7)
	lw ra, %lo(g7)(ra)
	rem ra, a0, ra
	sw ra, 0(s0)
	j .update_.bb17
.update_.bb17:
	addi s3, s3, 1
	j .update_.bb15
.update_.bb18:
	j .update_.bb19
.update_.bb19:
	li ra, 0
	li s2, 0
	li s1, 0
	li s0, 0
	j .update_.bb9
.update_.bb20:
	j .update_.bb21
.update_.bb21:
	lui ra, %hi(g3)
	lw t0, %lo(g3)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .update_.bb22
	j .update_.bb44
.update_.bb22:
	mv a0, s5
	call pushdown
	j .update_.bb23
.update_.bb23:
	li ra, 2
	mul s0, s5, ra
	li ra, 2
	mul ra, s5, ra
	addi s1, ra, 1
	add t0, s4, s3
	li ra, 2
	div s2, t0, ra
	j .update_.bb24
.update_.bb24:
	lui ra, %hi(g18)
	lw ra, %lo(g18)(ra)
	slt ra, s2, ra
	xori ra, ra, 1
	bne ra, zero, .update_.bb25
	j .update_.bb45
.update_.bb25:
	mv a0, s0
	mv a1, s4
	mv a2, s2
	call update
	j .update_.bb26
.update_.bb26:
	j .update_.bb27
.update_.bb27:
	lui ra, %hi(g19)
	lw t0, %lo(g19)(ra)
	addi ra, s2, 1
	slt ra, t0, ra
	xori ra, ra, 1
	bne ra, zero, .update_.bb28
	j .update_.bb46
.update_.bb28:
	addi a1, s2, 1
	mv a0, s1
	mv a2, s3
	call update
	j .update_.bb29
.update_.bb29:
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s5, ra
	add t2, t0, ra
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw t1, 0(ra)
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	add ra, t1, ra
	sw ra, 0(t2)
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s5, ra
	add t2, t0, ra
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw t1, 0(ra)
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s1, ra
	add ra, t0, ra
	lw ra, 0(ra)
	and ra, t1, ra
	sw ra, 0(t2)
	j .update_.bb30
.update_.bb30:
	lui ra, %hi(g10)
	lw t0, %lo(g10)(ra)
	li ra, 4
	mul ra, s5, ra
	add ra, t0, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .update_.bb31
	j .update_.bb47
.update_.bb31:
	li ra, 0
	j .update_.bb32
.update_.bb32:
	lui t0, %hi(g9)
	lw t0, %lo(g9)(t0)
	slt t0, ra, t0
	bne t0, zero, .update_.bb33
	j .update_.bb35
.update_.bb33:
	lui t0, %hi(g11)
	lw t1, %lo(g11)(t0)
	li t0, 4
	mul t0, s5, t0
	add t0, t1, t0
	lw t1, 0(t0)
	li t0, 4
	mul t0, ra, t0
	add t2, t1, t0
	lui t0, %hi(g11)
	lw t1, %lo(g11)(t0)
	li t0, 4
	mul t0, s0, t0
	add t0, t1, t0
	lw a0, 0(t0)
	lui t0, %hi(g2)
	lw t1, %lo(g2)(t0)
	li t0, 4
	mul t0, s0, t0
	add t0, t1, t0
	lw t0, 0(t0)
	add t1, ra, t0
	lui t0, %hi(g9)
	lw t0, %lo(g9)(t0)
	rem t1, t1, t0
	li t0, 4
	mul t0, t1, t0
	add t0, a0, t0
	lw a0, 0(t0)
	lui t0, %hi(g11)
	lw t1, %lo(g11)(t0)
	li t0, 4
	mul t0, s1, t0
	add t0, t1, t0
	lw a1, 0(t0)
	lui t0, %hi(g2)
	lw t1, %lo(g2)(t0)
	li t0, 4
	mul t0, s1, t0
	add t0, t1, t0
	lw t0, 0(t0)
	add t1, ra, t0
	lui t0, %hi(g9)
	lw t0, %lo(g9)(t0)
	rem t1, t1, t0
	li t0, 4
	mul t0, t1, t0
	add t0, a1, t0
	lw t0, 0(t0)
	add t0, a0, t0
	sw t0, 0(t2)
	j .update_.bb34
.update_.bb34:
	addi ra, ra, 1
	j .update_.bb32
.update_.bb35:
	lui t0, %hi(g2)
	lw t1, %lo(g2)(t0)
	li t0, 4
	mul t0, s5, t0
	add t0, t1, t0
	sw zero, 0(t0)
	j .update_.bb36
.update_.bb36:
	li s3, 0
	j .update_.bb9
.update_.bb37:
	li ra, 0
	j .update_.bb7
.update_.bb38:
	li ra, 0
	j .update_.bb4
.update_.bb39:
	j .update_.bb38
.update_.bb40:
	j .update_.bb38
.update_.bb41:
	j .update_.bb37
.update_.bb42:
	j .update_.bb37
.update_.bb43:
	li s3, 0
	j .update_.bb19
.update_.bb44:
	j .update_.bb23
.update_.bb45:
	j .update_.bb26
.update_.bb46:
	j .update_.bb29
.update_.bb47:
	li ra, 0
	j .update_.bb36

	.globl	query
	.p2align	1
	.type	query,@function
query:
.query_.bb0:
	addi sp, sp, -32
	sw s0, 28(sp)
	sw s1, 24(sp)
	sw s2, 20(sp)
	sw s3, 16(sp)
	sw s4, 12(sp)
	sw ra, 8(sp)
	mv s3, a1
	mv s4, a2
	j .query_.bb1
.query_.bb1:
	lui ra, %hi(g18)
	lw ra, %lo(g18)(ra)
	slt ra, s3, ra
	xori ra, ra, 1
	bne ra, zero, .query_.bb2
	j .query_.bb18
.query_.bb2:
	lui ra, %hi(g19)
	lw ra, %lo(g19)(ra)
	slt ra, ra, s4
	xori ra, ra, 1
	bne ra, zero, .query_.bb3
	j .query_.bb19
.query_.bb3:
	li ra, 1
	j .query_.bb4
.query_.bb4:
	bne ra, zero, .query_.bb5
	j .query_.bb7
.query_.bb5:
	lui ra, %hi(g12)
	lw t0, %lo(g12)(ra)
	li ra, 4
	mul ra, a0, ra
	add ra, t0, ra
	lw a0, 0(ra)
	li s3, 0
	li s2, 0
	li s1, 0
	li s0, 0
	j .query_.bb6
.query_.bb6:
	lw s0, 28(sp)
	lw s1, 24(sp)
	lw s2, 20(sp)
	lw s3, 16(sp)
	lw s4, 12(sp)
	lw ra, 8(sp)
	addi sp, sp, 32
	ret
.query_.bb7:
	li ra, 2
	mul s0, a0, ra
	li ra, 2
	mul ra, a0, ra
	addi s1, ra, 1
	add t0, s3, s4
	li ra, 2
	div s2, t0, ra
	j .query_.bb8
.query_.bb8:
	lui ra, %hi(g3)
	lw t0, %lo(g3)(ra)
	li ra, 4
	mul ra, a0, ra
	add ra, t0, ra
	lw ra, 0(ra)
	slt ra, zero, ra
	bne ra, zero, .query_.bb9
	j .query_.bb20
.query_.bb9:
	call pushdown
	j .query_.bb10
.query_.bb10:
	j .query_.bb11
.query_.bb11:
	lui ra, %hi(g18)
	lw ra, %lo(g18)(ra)
	slt ra, s2, ra
	xori ra, ra, 1
	bne ra, zero, .query_.bb12
	j .query_.bb21
.query_.bb12:
	mv a0, s0
	mv a1, s3
	mv a2, s2
	call query
	addi t0, a0, 0
	lui ra, %hi(g16)
	lw ra, %lo(g16)(ra)
	rem s3, t0, ra
	j .query_.bb13
.query_.bb13:
	j .query_.bb14
.query_.bb14:
	lui ra, %hi(g19)
	lw t0, %lo(g19)(ra)
	addi ra, s2, 1
	slt ra, t0, ra
	xori ra, ra, 1
	bne ra, zero, .query_.bb15
	j .query_.bb22
.query_.bb15:
	addi a1, s2, 1
	mv a0, s1
	mv a2, s4
	call query
	add t0, s3, a0
	lui ra, %hi(g16)
	lw ra, %lo(g16)(ra)
	rem s3, t0, ra
	j .query_.bb16
.query_.bb16:
	mv a0, s3
	j .query_.bb6
.query_.bb17:
	li ra, 0
	j .query_.bb4
.query_.bb18:
	j .query_.bb17
.query_.bb19:
	j .query_.bb17
.query_.bb20:
	j .query_.bb10
.query_.bb21:
	li s3, 0
	j .query_.bb13
.query_.bb22:
	j .query_.bb16

	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
	addi sp, sp, -16
	sw s0, 12(sp)
	sw s1, 8(sp)
	sw ra, 4(sp)
	li ra, 2000020
	addi a0, ra, 4
	call malloc
	li ra, 500005
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g1)
	sw t0, %lo(g1)(ra)
	li ra, 2000020
	addi a0, ra, 4
	call malloc
	li ra, 500005
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g2)
	sw t0, %lo(g2)(ra)
	li ra, 2000020
	addi a0, ra, 4
	call malloc
	li ra, 500005
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g3)
	sw t0, %lo(g3)(ra)
	li ra, 800020
	addi a0, ra, 4
	call malloc
	li ra, 200005
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g4)
	sw t0, %lo(g4)(ra)
	li t0, 1
	lui ra, %hi(g9)
	sw t0, %lo(g9)(ra)
	li ra, 2000020
	addi a0, ra, 4
	call malloc
	li ra, 500005
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g10)
	sw t0, %lo(g10)(ra)
	li s0, 2000020
	addi a0, s0, 4
	call malloc
	li ra, 500005
	sw ra, 0(a0)
	addi s1, a0, 4
	add s0, a0, s0
	j .main_.bb1
.main_.bb1:
	slt ra, s0, s1
	xori ra, ra, 1
	bne ra, zero, .main_.bb2
	j .main_.bb3
.main_.bb2:
	li ra, 320
	addi a0, ra, 4
	call malloc
	li ra, 80
	sw ra, 0(a0)
	addi ra, a0, 4
	sw ra, 0(s0)
	addi s0, s0, -4
	j .main_.bb1
.main_.bb3:
	lui ra, %hi(g11)
	sw s1, %lo(g11)(ra)
	li ra, 2000020
	addi a0, ra, 4
	call malloc
	li ra, 500005
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g12)
	sw t0, %lo(g12)(ra)
	lui ra, %hi(g13)
	sw zero, %lo(g13)(ra)
	li t0, 13131
	lui ra, %hi(g14)
	sw t0, %lo(g14)(ra)
	li t0, 5353
	lui ra, %hi(g15)
	sw t0, %lo(g15)(ra)
	li ra, 32768
	addi t0, ra, -7
	lui ra, %hi(g16)
	sw t0, %lo(g16)(ra)
	li t0, 1
	lui ra, %hi(g17)
	sw t0, %lo(g17)(ra)
	lui ra, %hi(g18)
	sw zero, %lo(g18)(ra)
	lui ra, %hi(g19)
	sw zero, %lo(g19)(ra)
	call getInt
	lui ra, %hi(g5)
	sw a0, %lo(g5)(ra)
	call getInt
	lui ra, %hi(g6)
	sw a0, %lo(g6)(ra)
	call getInt
	lui ra, %hi(g7)
	sw a0, %lo(g7)(ra)
	li s1, 1
	j .main_.bb4
.main_.bb4:
	lui ra, %hi(g5)
	lw ra, %lo(g5)(ra)
	slt ra, ra, s1
	xori ra, ra, 1
	bne ra, zero, .main_.bb5
	j .main_.bb7
.main_.bb5:
	lui ra, %hi(g4)
	lw t0, %lo(g4)(ra)
	li ra, 4
	mul ra, s1, ra
	add s0, t0, ra
	lui ra, %hi(g7)
	lw a1, %lo(g7)(ra)
	mv a0, zero
	call RandRange
	sw a0, 0(s0)
	j .main_.bb6
.main_.bb6:
	addi s1, s1, 1
	j .main_.bb4
.main_.bb7:
	call init
	lui ra, %hi(g5)
	lw a2, %lo(g5)(ra)
	li a0, 1
	li a1, 1
	call build
	j .main_.bb8
.main_.bb8:
	lui ra, %hi(g6)
	lw ra, %lo(g6)(ra)
	slt ra, zero, ra
	bne ra, zero, .main_.bb9
	j .main_.bb19
.main_.bb9:
	call Rand
	li ra, 2
	rem t0, a0, ra
	lui ra, %hi(g8)
	sw t0, %lo(g8)(ra)
	lui ra, %hi(g5)
	lw a1, %lo(g5)(ra)
	li a0, 1
	call RandRange
	lui ra, %hi(g18)
	sw a0, %lo(g18)(ra)
	lui ra, %hi(g5)
	lw a1, %lo(g5)(ra)
	li a0, 1
	call RandRange
	lui ra, %hi(g19)
	sw a0, %lo(g19)(ra)
	j .main_.bb10
.main_.bb10:
	lui ra, %hi(g19)
	lw t0, %lo(g19)(ra)
	lui ra, %hi(g18)
	lw ra, %lo(g18)(ra)
	slt ra, ra, t0
	xori ra, ra, 1
	bne ra, zero, .main_.bb11
	j .main_.bb12
.main_.bb11:
	lui ra, %hi(g5)
	lw a1, %lo(g5)(ra)
	li a0, 1
	call RandRange
	lui ra, %hi(g19)
	sw a0, %lo(g19)(ra)
	j .main_.bb10
.main_.bb12:
	j .main_.bb13
.main_.bb13:
	lui ra, %hi(g8)
	lw ra, %lo(g8)(ra)
	xori ra, ra, 0
	seqz ra, ra
	bne ra, zero, .main_.bb14
	j .main_.bb21
.main_.bb14:
	lui ra, %hi(g5)
	lw a2, %lo(g5)(ra)
	li a0, 1
	li a1, 1
	call update
	j .main_.bb15
.main_.bb15:
	j .main_.bb16
.main_.bb16:
	lui ra, %hi(g8)
	lw ra, %lo(g8)(ra)
	xori ra, ra, 1
	seqz ra, ra
	bne ra, zero, .main_.bb17
	j .main_.bb22
.main_.bb17:
	lui ra, %hi(g13)
	lw s0, %lo(g13)(ra)
	lui ra, %hi(g5)
	lw a2, %lo(g5)(ra)
	li a0, 1
	li a1, 1
	call query
	add t0, s0, a0
	lui ra, %hi(g16)
	lw ra, %lo(g16)(ra)
	rem t0, t0, ra
	lui ra, %hi(g13)
	sw t0, %lo(g13)(ra)
	j .main_.bb18
.main_.bb18:
	lui ra, %hi(g6)
	lw ra, %lo(g6)(ra)
	addi t0, ra, -1
	lui ra, %hi(g6)
	sw t0, %lo(g6)(ra)
	j .main_.bb8
.main_.bb19:
	lui ra, %hi(g13)
	lw a0, %lo(g13)(ra)
	call toString
	call print
	li a0, 0
	j .main_.bb20
.main_.bb20:
	lw s0, 12(sp)
	lw s1, 8(sp)
	lw ra, 4(sp)
	addi sp, sp, 16
	ret
.main_.bb21:
	j .main_.bb15
.main_.bb22:
	j .main_.bb18

	.type	g1,@object
	.section	.data
	.globl	g1
	.p2align	2
g1:
	.zero	4
	.size	g1, 4

	.type	g2,@object
	.section	.data
	.globl	g2
	.p2align	2
g2:
	.zero	4
	.size	g2, 4

	.type	g3,@object
	.section	.data
	.globl	g3
	.p2align	2
g3:
	.zero	4
	.size	g3, 4

	.type	g4,@object
	.section	.data
	.globl	g4
	.p2align	2
g4:
	.zero	4
	.size	g4, 4

	.type	g5,@object
	.section	.data
	.globl	g5
	.p2align	2
g5:
	.zero	4
	.size	g5, 4

	.type	g6,@object
	.section	.data
	.globl	g6
	.p2align	2
g6:
	.zero	4
	.size	g6, 4

	.type	g7,@object
	.section	.data
	.globl	g7
	.p2align	2
g7:
	.zero	4
	.size	g7, 4

	.type	g8,@object
	.section	.data
	.globl	g8
	.p2align	2
g8:
	.zero	4
	.size	g8, 4

	.type	g9,@object
	.section	.data
	.globl	g9
	.p2align	2
g9:
	.zero	4
	.size	g9, 4

	.type	g10,@object
	.section	.data
	.globl	g10
	.p2align	2
g10:
	.zero	4
	.size	g10, 4

	.type	g11,@object
	.section	.data
	.globl	g11
	.p2align	2
g11:
	.zero	4
	.size	g11, 4

	.type	g12,@object
	.section	.data
	.globl	g12
	.p2align	2
g12:
	.zero	4
	.size	g12, 4

	.type	g13,@object
	.section	.data
	.globl	g13
	.p2align	2
g13:
	.zero	4
	.size	g13, 4

	.type	g14,@object
	.section	.data
	.globl	g14
	.p2align	2
g14:
	.zero	4
	.size	g14, 4

	.type	g15,@object
	.section	.data
	.globl	g15
	.p2align	2
g15:
	.zero	4
	.size	g15, 4

	.type	g16,@object
	.section	.data
	.globl	g16
	.p2align	2
g16:
	.zero	4
	.size	g16, 4

	.type	g17,@object
	.section	.data
	.globl	g17
	.p2align	2
g17:
	.zero	4
	.size	g17, 4

	.type	g18,@object
	.section	.data
	.globl	g18
	.p2align	2
g18:
	.zero	4
	.size	g18, 4

	.type	g19,@object
	.section	.data
	.globl	g19
	.p2align	2
g19:
	.zero	4
	.size	g19, 4

