	.text
	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
	addi sp, sp, 0
	mv t0, s0
	mv t0, s1
	mv t0, s2
	mv t0, s3
	mv t0, s4
	mv t0, s5
	mv t0, s6
	mv t0, s7
	mv t0, s8
	mv t0, s9
	mv t0, s10
	mv t0, s11
	mv t0, ra
	li a0, 4
	mv a0, a0
	call printInt
	li a0, 0
	j .main_.bb1
.main_.bb1:
	mv a0, a0
	mv s0, t0
	mv s1, t0
	mv s2, t0
	mv s3, t0
	mv s4, t0
	mv s5, t0
	mv s6, t0
	mv s7, t0
	mv s8, t0
	mv s9, t0
	mv s10, t0
	mv s11, t0
	mv ra, t0
	addi sp, sp, 0
	ret

