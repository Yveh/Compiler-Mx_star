	.text
	.globl	qpow
	.p2align	1
	.type	qpow,@function
qpow:
.qpow_.bb0:
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
	mv %14, a0
	mv %15, a1
	mv %16, a2
	li %17, 1
	mv %18, %14
	mv %19, %15
	j .qpow_.bb1
.qpow_.bb1:
	slt %20, zero, %19
	bne %20, zero, .qpow_.bb2
	j .qpow_.bb6
.qpow_.bb2:
	j .qpow_.bb3
.qpow_.bb3:
	andi %21, %19, 1
	xori %23, %21, 1
	seqz %22, %23
	bne %22, zero, .qpow_.bb4
	j .qpow_.bb8
.qpow_.bb4:
	mul %24, %17, %18
	rem %25, %24, %16
	mv %26, %25
	j .qpow_.bb5
.qpow_.bb5:
	mul %27, %18, %18
	rem %28, %27, %16
	li %30, 2
	div %29, %19, %30
	mv %17, %26
	mv %18, %28
	mv %19, %29
	j .qpow_.bb1
.qpow_.bb6:
	mv %31, %17
	j .qpow_.bb7
.qpow_.bb7:
	mv a0, %31
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
.qpow_.bb8:
	mv %26, %17
	j .qpow_.bb5

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
	li %14, 2
	mv a0, %14
	li %15, 10
	mv a1, %15
	li %16, 10000
	mv a2, %16
	call qpow
	mv %17, a0
	mv a0, %17
	call toString
	mv %18, a0
	mv a0, %18
	call println
	li %19, 0
	j .main_.bb1
.main_.bb1:
	mv a0, %19
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

