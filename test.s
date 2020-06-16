	.text
	.globl	qpow
	.p2align	1
	.type	qpow,@function
qpow:
.qpow_.bb0:
	addi sp, sp, 0
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
	mv t0, a0
	mv a1, a1
	mv a2, a2
	li a0, 1
	mv t0, t0
	mv a1, a1
	j .qpow_.bb1
.qpow_.bb1:
	slt a3, zero, a1
	bne a3, zero, .qpow_.bb2
	j .qpow_.bb6
.qpow_.bb2:
	j .qpow_.bb3
.qpow_.bb3:
	andi a3, a1, 1
	xori a3, a3, 1
	seqz a3, a3
	bne a3, zero, .qpow_.bb4
	j .qpow_.bb8
.qpow_.bb4:
	mul a0, a0, t0
	rem a0, a0, a2
	mv a0, a0
	j .qpow_.bb5
.qpow_.bb5:
	mul t0, t0, t0
	rem t0, t0, a2
	li a3, 2
	div a1, a1, a3
	mv a0, a0
	mv t0, t0
	mv a1, a1
	j .qpow_.bb1
.qpow_.bb6:
	mv a0, a0
	j .qpow_.bb7
.qpow_.bb7:
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
	mv ra, ra
	addi sp, sp, 0
	ret
.qpow_.bb8:
	mv a0, a0
	j .qpow_.bb5

	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
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
	li a0, 2
	mv a0, a0
	li a1, 10
	mv a1, a1
	li a2, 10000
	mv a2, a2
	call qpow
	mv a0, a0
	mv a0, a0
	call toString
	mv a0, a0
	mv a0, a0
	call println
	li a0, 0
	j .main_.bb1
.main_.bb1:
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

