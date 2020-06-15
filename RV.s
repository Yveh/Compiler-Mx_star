	.text
	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
	addi sp, sp, 0
	mv %1, s0
	mv %2, s1
	mv %3, s2
	mv %4, s3
	mv %5, s4
	mv %6, s5
	mv %7, s6
	mv %8, s7
	mv %9, s8
	mv %10, s9
	mv %11, s10
	mv %12, s11
	mv %13, ra
	li %14, 4
	mv a0, %14
	call printInt
	li %15, 0
	j .main_.bb1
.main_.bb1:
	mv a0, %15
	mv s0, %1
	mv s1, %2
	mv s2, %3
	mv s3, %4
	mv s4, %5
	mv s5, %6
	mv s6, %7
	mv s7, %8
	mv s8, %9
	mv s9, %10
	mv s10, %11
	mv s11, %12
	mv ra, %13
	addi sp, sp, 0
	ret

