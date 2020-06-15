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
	mv a0, a0
	li t2, 2
	div t2, a0, t2
	sw t2, 0(a0)
	mv a0, a0
	j .qpow_.bb1
.qpow_.bb1:
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
	li a0, 10
	mv a0, a0
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

