	.text
	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
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
	li t2, 0
	bne t2, zero, .main_.bb1
	j .main_.bb21
.main_.bb1:
	li t2, 5
	div t2, t2, zero
	xori t2, t2, 1
	snez t2, t2
	bne t2, zero, .main_.bb2
	j .main_.bb22
.main_.bb2:
	li t2, 1
	j .main_.bb3
.main_.bb3:
	j .main_.bb4
.main_.bb4:
	bne t2, zero, .main_.bb5
	j .main_.bb19
.main_.bb5:
	li a0, 10
	j .main_.bb6
.main_.bb6:
	xori t2, a0, 10
	seqz t2, t2
	bne t2, zero, .main_.bb7
	j .main_.bb23
.main_.bb7:
	li t2, 5
	div t2, t2, zero
	xori t2, t2, 0
	seqz t2, t2
	bne t2, zero, .main_.bb8
	j .main_.bb24
.main_.bb8:
	li t2, 1
	j .main_.bb9
.main_.bb9:
	bne t2, zero, .main_.bb10
	j .main_.bb25
.main_.bb10:
	li t2, 1
	bne t2, zero, .main_.bb11
	j .main_.bb26
.main_.bb11:
	li t2, 1
	j .main_.bb12
.main_.bb12:
	xori t2, t2, 1
	j .main_.bb13
.main_.bb13:
	bne t2, zero, .main_.bb14
	j .main_.bb27
.main_.bb14:
	li a0, 30
	j .main_.bb15
.main_.bb15:
	mv a0, a0
	j .main_.bb16
.main_.bb16:
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
.main_.bb17:
	li t2, 0
	j .main_.bb12
.main_.bb18:
	li t2, 0
	j .main_.bb9
.main_.bb19:
	li a0, 20
	j .main_.bb6
.main_.bb20:
	li t2, 0
	j .main_.bb3
.main_.bb21:
	j .main_.bb20
.main_.bb22:
	j .main_.bb20
.main_.bb23:
	j .main_.bb18
.main_.bb24:
	j .main_.bb18
.main_.bb25:
	j .main_.bb17
.main_.bb26:
	j .main_.bb17
.main_.bb27:
	mv a0, a0
	j .main_.bb15

