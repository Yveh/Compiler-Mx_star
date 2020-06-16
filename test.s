	.text
	.globl	digt
	.p2align	1
	.type	digt,@function
digt:
.digt_.bb0:
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
	j .digt_.bb1
.digt_.bb1:
	xori a1, a0, 0
	seqz a1, a1
	bne a1, zero, .digt_.bb2
	j .digt_.bb4
.digt_.bb2:
	mv t0, t0
	j .digt_.bb3
.digt_.bb3:
	mv a0, t0
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
.digt_.bb4:
	j .digt_.bb5
.digt_.bb5:
	xori a1, a0, 1
	seqz a1, a1
	bne a1, zero, .digt_.bb6
	j .digt_.bb7
.digt_.bb6:
	mv t0, t0
	j .digt_.bb3
.digt_.bb7:
	j .digt_.bb8
.digt_.bb8:
	xori a1, a0, 2
	seqz a1, a1
	bne a1, zero, .digt_.bb9
	j .digt_.bb10
.digt_.bb9:
	mv t0, t0
	j .digt_.bb3
.digt_.bb10:
	j .digt_.bb11
.digt_.bb11:
	xori a1, a0, 3
	seqz a1, a1
	bne a1, zero, .digt_.bb12
	j .digt_.bb13
.digt_.bb12:
	mv t0, t0
	j .digt_.bb3
.digt_.bb13:
	j .digt_.bb14
.digt_.bb14:
	xori a1, a0, 4
	seqz a1, a1
	bne a1, zero, .digt_.bb15
	j .digt_.bb16
.digt_.bb15:
	mv t0, t0
	j .digt_.bb3
.digt_.bb16:
	j .digt_.bb17
.digt_.bb17:
	xori a1, a0, 5
	seqz a1, a1
	bne a1, zero, .digt_.bb18
	j .digt_.bb19
.digt_.bb18:
	mv t0, t0
	j .digt_.bb3
.digt_.bb19:
	j .digt_.bb20
.digt_.bb20:
	xori a1, a0, 6
	seqz a1, a1
	bne a1, zero, .digt_.bb21
	j .digt_.bb22
.digt_.bb21:
	mv t0, t0
	j .digt_.bb3
.digt_.bb22:
	j .digt_.bb23
.digt_.bb23:
	xori a1, a0, 7
	seqz a1, a1
	bne a1, zero, .digt_.bb24
	j .digt_.bb25
.digt_.bb24:
	mv t0, t0
	j .digt_.bb3
.digt_.bb25:
	j .digt_.bb26
.digt_.bb26:
	xori a1, a0, 8
	seqz a1, a1
	bne a1, zero, .digt_.bb27
	j .digt_.bb28
.digt_.bb27:
	mv t0, t0
	j .digt_.bb3
.digt_.bb28:
	j .digt_.bb29
.digt_.bb29:
	xori a0, a0, 9
	seqz a0, a0
	bne a0, zero, .digt_.bb30
	j .digt_.bb31
.digt_.bb30:
	mv t0, t0
	j .digt_.bb3
.digt_.bb31:
	li t0, 0
	j .digt_.bb3

	.globl	s2
	.p2align	1
	.type	s2,@function
s2:
.s2_.bb0:
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
	mv s1, a0
	j .s2_.bb1
.s2_.bb1:
	li ra, 9
	slt ra, ra, s1
	xori ra, ra, 1
	bne ra, zero, .s2_.bb2
	j .s2_.bb4
.s2_.bb2:
	mv a0, s1
	call digt
	mv a1, a0
	la a0, .str.138
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	la a1, .str.139
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .s2_.bb3
.s2_.bb3:
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
.s2_.bb4:
	li ra, 10
	div a0, s1, ra
	mv a0, a0
	call digt
	mv a1, a0
	la a0, .str.140
	mv a1, a1
	call string_strcat
	mv s0, a0
	li ra, 10
	rem a0, s1, ra
	mv a0, a0
	call digt
	mv a1, a0
	mv a0, s0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	la a1, .str.141
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .s2_.bb3

	.globl	c2
	.p2align	1
	.type	c2,@function
c2:
.c2_.bb0:
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
	mv s1, a0
	j .c2_.bb1
.c2_.bb1:
	li ra, 9
	slt ra, ra, s1
	xori ra, ra, 1
	bne ra, zero, .c2_.bb2
	j .c2_.bb4
.c2_.bb2:
	mv a0, s1
	call digt
	mv a1, a0
	la a0, .str.142
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	la a1, .str.143
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .c2_.bb3
.c2_.bb3:
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
.c2_.bb4:
	li ra, 10
	div a0, s1, ra
	mv a0, a0
	call digt
	mv a1, a0
	la a0, .str.144
	mv a1, a1
	call string_strcat
	mv s0, a0
	li ra, 10
	rem a0, s1, ra
	mv a0, a0
	call digt
	mv a1, a0
	mv a0, s0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	la a1, .str.145
	call string_strcat
	mv a0, a0
	mv a0, a0
	j .c2_.bb3

	.globl	main
	.p2align	1
	.type	main,@function
main:
.main_.bb0:
	addi sp, sp, -16
	mv s0, s0
	sw s0, 12(sp)
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
	sw ra, 8(sp)
	li ra, 1024
	addi a0, ra, 4
	mv a0, a0
	call malloc
	mv a0, a0
	li ra, 256
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g1)
	sw t0, %lo(g1)(ra)
	li ra, 1024
	addi a0, ra, 4
	mv a0, a0
	call malloc
	mv a0, a0
	li ra, 256
	sw ra, 0(a0)
	addi t0, a0, 4
	lui ra, %hi(g2)
	sw t0, %lo(g2)(ra)
	la t0, .str.0
	lui ra, %hi(g3)
	sw t0, %lo(g3)(ra)
	la t0, .str.1
	lui ra, %hi(g4)
	sw t0, %lo(g4)(ra)
	la t0, .str.2
	lui ra, %hi(g5)
	sw t0, %lo(g5)(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add t0, t0, ra
	la ra, .str.3
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 4
	add t0, t0, ra
	la ra, .str.4
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 8
	add t0, t0, ra
	la ra, .str.5
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 12
	add t0, t0, ra
	la ra, .str.6
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 16
	add t0, t0, ra
	la ra, .str.7
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 20
	add t0, t0, ra
	la ra, .str.8
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 24
	add t0, t0, ra
	la ra, .str.9
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add t0, t0, ra
	la ra, .str.10
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add t0, t0, ra
	la ra, .str.11
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 36
	add t0, t0, ra
	la ra, .str.12
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add t0, t0, ra
	la ra, .str.13
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 44
	add t0, t0, ra
	la ra, .str.14
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 48
	add t0, t0, ra
	la ra, .str.15
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 52
	add t0, t0, ra
	la ra, .str.16
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 56
	add t0, t0, ra
	la ra, .str.17
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add t0, t0, ra
	la ra, .str.18
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add t0, t0, ra
	la ra, .str.19
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add t0, t0, ra
	la ra, .str.20
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 72
	add t0, t0, ra
	la ra, .str.21
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 76
	add t0, t0, ra
	la ra, .str.22
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 80
	add t0, t0, ra
	la ra, .str.23
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 84
	add t0, t0, ra
	la ra, .str.24
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 88
	add t0, t0, ra
	la ra, .str.25
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 92
	add t0, t0, ra
	la ra, .str.26
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 96
	add t0, t0, ra
	la ra, .str.27
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 100
	add t0, t0, ra
	la ra, .str.28
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add t0, t0, ra
	la ra, .str.29
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 108
	add t0, t0, ra
	la ra, .str.30
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add t0, t0, ra
	la ra, .str.31
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 116
	add t0, t0, ra
	la ra, .str.32
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 120
	add t0, t0, ra
	la ra, .str.33
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 124
	add t0, t0, ra
	la ra, .str.34
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 128
	add t0, t0, ra
	la ra, .str.35
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 132
	add t0, t0, ra
	la ra, .str.36
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 136
	add t0, t0, ra
	la ra, .str.37
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 140
	add t0, t0, ra
	la ra, .str.38
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 144
	add t0, t0, ra
	la ra, .str.39
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 148
	add t0, t0, ra
	la ra, .str.40
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 152
	add t0, t0, ra
	la ra, .str.41
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 156
	add t0, t0, ra
	la ra, .str.42
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 160
	add t0, t0, ra
	la ra, .str.43
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 164
	add t0, t0, ra
	la ra, .str.44
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 168
	add t0, t0, ra
	la ra, .str.45
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 172
	add t0, t0, ra
	la ra, .str.46
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 176
	add t0, t0, ra
	la ra, .str.47
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 180
	add t0, t0, ra
	la ra, .str.48
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 184
	add t0, t0, ra
	la ra, .str.49
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 188
	add t0, t0, ra
	la ra, .str.50
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 192
	add t0, t0, ra
	la ra, .str.51
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 196
	add t0, t0, ra
	la ra, .str.52
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 200
	add t0, t0, ra
	la ra, .str.53
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 204
	add t0, t0, ra
	la ra, .str.54
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 208
	add t0, t0, ra
	la ra, .str.55
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 212
	add t0, t0, ra
	la ra, .str.56
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 216
	add t0, t0, ra
	la ra, .str.57
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 220
	add t0, t0, ra
	la ra, .str.58
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 224
	add t0, t0, ra
	la ra, .str.59
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 228
	add t0, t0, ra
	la ra, .str.60
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add t0, t0, ra
	la ra, .str.61
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add t0, t0, ra
	la ra, .str.62
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 240
	add t0, t0, ra
	la ra, .str.63
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 244
	add t0, t0, ra
	la ra, .str.64
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 248
	add t0, t0, ra
	la ra, .str.65
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 252
	add t0, t0, ra
	la ra, .str.66
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 256
	add t0, t0, ra
	la ra, .str.67
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add t0, t0, ra
	la ra, .str.68
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add t0, t0, ra
	la ra, .str.69
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add t0, t0, ra
	la ra, .str.70
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add t0, t0, ra
	la ra, .str.71
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add t0, t0, ra
	la ra, .str.72
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 280
	add t0, t0, ra
	la ra, .str.73
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add t0, t0, ra
	la ra, .str.74
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 288
	add t0, t0, ra
	la ra, .str.75
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 292
	add t0, t0, ra
	la ra, .str.76
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 296
	add t0, t0, ra
	la ra, .str.77
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 300
	add t0, t0, ra
	la ra, .str.78
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add t0, t0, ra
	la ra, .str.79
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 308
	add t0, t0, ra
	la ra, .str.80
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 312
	add t0, t0, ra
	la ra, .str.81
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 316
	add t0, t0, ra
	la ra, .str.82
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add t0, t0, ra
	la ra, .str.83
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add t0, t0, ra
	la ra, .str.84
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add t0, t0, ra
	la ra, .str.85
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add t0, t0, ra
	la ra, .str.86
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 336
	add t0, t0, ra
	la ra, .str.87
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 340
	add t0, t0, ra
	la ra, .str.88
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add t0, t0, ra
	la ra, .str.89
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 348
	add t0, t0, ra
	la ra, .str.90
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 352
	add t0, t0, ra
	la ra, .str.91
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 356
	add t0, t0, ra
	la ra, .str.92
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 360
	add t0, t0, ra
	la ra, .str.93
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 364
	add t0, t0, ra
	la ra, .str.94
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 368
	add t0, t0, ra
	la ra, .str.95
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 0
	add t0, t0, ra
	la ra, .str.96
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 4
	add t0, t0, ra
	la ra, .str.97
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 8
	add t0, t0, ra
	la ra, .str.98
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 12
	add t0, t0, ra
	la ra, .str.99
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 16
	add t0, t0, ra
	la ra, .str.100
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 20
	add t0, t0, ra
	la ra, .str.101
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 24
	add t0, t0, ra
	la ra, .str.102
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 28
	add t0, t0, ra
	la ra, .str.103
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 32
	add t0, t0, ra
	la ra, .str.104
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 36
	add t0, t0, ra
	la ra, .str.105
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 40
	add t0, t0, ra
	la ra, .str.106
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 44
	add t0, t0, ra
	la ra, .str.107
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 48
	add t0, t0, ra
	la ra, .str.108
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 52
	add t0, t0, ra
	la ra, .str.109
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 56
	add t0, t0, ra
	la ra, .str.110
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 60
	add t0, t0, ra
	la ra, .str.111
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 64
	add t0, t0, ra
	la ra, .str.112
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 68
	add t0, t0, ra
	la ra, .str.113
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 72
	add t0, t0, ra
	la ra, .str.114
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 76
	add t0, t0, ra
	la ra, .str.115
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 80
	add t0, t0, ra
	la ra, .str.116
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 84
	add t0, t0, ra
	la ra, .str.117
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 88
	add t0, t0, ra
	la ra, .str.118
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 92
	add t0, t0, ra
	la ra, .str.119
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 96
	add t0, t0, ra
	la ra, .str.120
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 100
	add t0, t0, ra
	la ra, .str.121
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 104
	add t0, t0, ra
	la ra, .str.122
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 108
	add t0, t0, ra
	la ra, .str.123
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 112
	add t0, t0, ra
	la ra, .str.124
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 116
	add t0, t0, ra
	la ra, .str.125
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 120
	add t0, t0, ra
	la ra, .str.126
	sw ra, 0(t0)
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 124
	add t0, t0, ra
	la ra, .str.127
	sw ra, 0(t0)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 356
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 72
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 72
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 76
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 76
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 80
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 80
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 84
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 84
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 88
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 88
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 92
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 92
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 344
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 96
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 96
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 364
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 340
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 80
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 84
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 340
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 80
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 84
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 356
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 108
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 96
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 56
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 16
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 364
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 356
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 272
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 108
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 96
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 268
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 332
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 232
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 56
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 264
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 28
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 16
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 64
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 60
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 32
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 40
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 236
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 364
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 260
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 308
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 252
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 316
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g5)
	lw a1, %lo(g5)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 324
	add ra, t0, ra
	lw a0, 0(ra)
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 328
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 320
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 284
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 304
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 276
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 0
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 252
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 68
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 256
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 112
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g5)
	lw a1, %lo(g5)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g5)
	lw a1, %lo(g5)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 104
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 0
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call println
	li s0, 0
	j .main_.bb1
.main_.bb1:
	slti ra, s0, 93
	bne ra, zero, .main_.bb2
	j .main_.bb4
.main_.bb2:
	mv a0, s0
	call c2
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g2)
	lw t0, %lo(g2)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g3)
	lw a1, %lo(g3)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	j .main_.bb3
.main_.bb3:
	addi s0, s0, 1
	mv s0, s0
	j .main_.bb1
.main_.bb4:
	li s0, 0
	j .main_.bb5
.main_.bb5:
	slti ra, s0, 32
	bne ra, zero, .main_.bb6
	j .main_.bb8
.main_.bb6:
	mv a0, s0
	call s2
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw a1, 0(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g4)
	lw a1, %lo(g4)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	lui ra, %hi(g3)
	lw a1, %lo(g3)(ra)
	mv a0, a0
	mv a1, a1
	call string_strcat
	mv a0, a0
	mv a0, a0
	call println
	j .main_.bb7
.main_.bb7:
	addi s0, s0, 1
	mv s0, s0
	j .main_.bb5
.main_.bb8:
	li s0, 1
	j .main_.bb9
.main_.bb9:
	slti ra, s0, 32
	bne ra, zero, .main_.bb10
	j .main_.bb12
.main_.bb10:
	lui ra, %hi(g1)
	lw t0, %lo(g1)(ra)
	li ra, 4
	mul ra, s0, ra
	add ra, t0, ra
	lw a0, 0(ra)
	mv a0, a0
	call println
	j .main_.bb11
.main_.bb11:
	addi s0, s0, 1
	mv s0, s0
	j .main_.bb9
.main_.bb12:
	li a0, 0
	j .main_.bb13
.main_.bb13:
	mv a0, a0
	lw s0, 12(sp)
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
	lw ra, 8(sp)
	mv ra, ra
	addi sp, sp, 16
	ret

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

	.type	.str.0 ,@object
	.section	.rodata
.str.0:
	.asciz	";"
	.size	.str.0, 147

	.type	.str.1 ,@object
	.section	.rodata
.str.1:
	.asciz	"\""
	.size	.str.1, 147

	.type	.str.2 ,@object
	.section	.rodata
.str.2:
	.asciz	"\\"
	.size	.str.2, 147

	.type	.str.3 ,@object
	.section	.rodata
.str.3:
	.asciz	" "
	.size	.str.3, 147

	.type	.str.4 ,@object
	.section	.rodata
.str.4:
	.asciz	"!"
	.size	.str.4, 147

	.type	.str.5 ,@object
	.section	.rodata
.str.5:
	.asciz	"#"
	.size	.str.5, 147

	.type	.str.6 ,@object
	.section	.rodata
.str.6:
	.asciz	"$"
	.size	.str.6, 147

	.type	.str.7 ,@object
	.section	.rodata
.str.7:
	.asciz	"%"
	.size	.str.7, 147

	.type	.str.8 ,@object
	.section	.rodata
.str.8:
	.asciz	"&"
	.size	.str.8, 147

	.type	.str.9 ,@object
	.section	.rodata
.str.9:
	.asciz	"'"
	.size	.str.9, 147

	.type	.str.10 ,@object
	.section	.rodata
.str.10:
	.asciz	"("
	.size	.str.10, 147

	.type	.str.11 ,@object
	.section	.rodata
.str.11:
	.asciz	")"
	.size	.str.11, 147

	.type	.str.12 ,@object
	.section	.rodata
.str.12:
	.asciz	"*"
	.size	.str.12, 147

	.type	.str.13 ,@object
	.section	.rodata
.str.13:
	.asciz	"+"
	.size	.str.13, 147

	.type	.str.14 ,@object
	.section	.rodata
.str.14:
	.asciz	","
	.size	.str.14, 147

	.type	.str.15 ,@object
	.section	.rodata
.str.15:
	.asciz	"-"
	.size	.str.15, 147

	.type	.str.16 ,@object
	.section	.rodata
.str.16:
	.asciz	"."
	.size	.str.16, 147

	.type	.str.17 ,@object
	.section	.rodata
.str.17:
	.asciz	"/"
	.size	.str.17, 147

	.type	.str.18 ,@object
	.section	.rodata
.str.18:
	.asciz	"0"
	.size	.str.18, 147

	.type	.str.19 ,@object
	.section	.rodata
.str.19:
	.asciz	"1"
	.size	.str.19, 147

	.type	.str.20 ,@object
	.section	.rodata
.str.20:
	.asciz	"2"
	.size	.str.20, 147

	.type	.str.21 ,@object
	.section	.rodata
.str.21:
	.asciz	"3"
	.size	.str.21, 147

	.type	.str.22 ,@object
	.section	.rodata
.str.22:
	.asciz	"4"
	.size	.str.22, 147

	.type	.str.23 ,@object
	.section	.rodata
.str.23:
	.asciz	"5"
	.size	.str.23, 147

	.type	.str.24 ,@object
	.section	.rodata
.str.24:
	.asciz	"6"
	.size	.str.24, 147

	.type	.str.25 ,@object
	.section	.rodata
.str.25:
	.asciz	"7"
	.size	.str.25, 147

	.type	.str.26 ,@object
	.section	.rodata
.str.26:
	.asciz	"8"
	.size	.str.26, 147

	.type	.str.27 ,@object
	.section	.rodata
.str.27:
	.asciz	"9"
	.size	.str.27, 147

	.type	.str.28 ,@object
	.section	.rodata
.str.28:
	.asciz	":"
	.size	.str.28, 147

	.type	.str.29 ,@object
	.section	.rodata
.str.29:
	.asciz	";"
	.size	.str.29, 147

	.type	.str.30 ,@object
	.section	.rodata
.str.30:
	.asciz	"<"
	.size	.str.30, 147

	.type	.str.31 ,@object
	.section	.rodata
.str.31:
	.asciz	"="
	.size	.str.31, 147

	.type	.str.32 ,@object
	.section	.rodata
.str.32:
	.asciz	">"
	.size	.str.32, 147

	.type	.str.33 ,@object
	.section	.rodata
.str.33:
	.asciz	"?"
	.size	.str.33, 147

	.type	.str.34 ,@object
	.section	.rodata
.str.34:
	.asciz	"@"
	.size	.str.34, 147

	.type	.str.35 ,@object
	.section	.rodata
.str.35:
	.asciz	"A"
	.size	.str.35, 147

	.type	.str.36 ,@object
	.section	.rodata
.str.36:
	.asciz	"B"
	.size	.str.36, 147

	.type	.str.37 ,@object
	.section	.rodata
.str.37:
	.asciz	"C"
	.size	.str.37, 147

	.type	.str.38 ,@object
	.section	.rodata
.str.38:
	.asciz	"D"
	.size	.str.38, 147

	.type	.str.39 ,@object
	.section	.rodata
.str.39:
	.asciz	"E"
	.size	.str.39, 147

	.type	.str.40 ,@object
	.section	.rodata
.str.40:
	.asciz	"F"
	.size	.str.40, 147

	.type	.str.41 ,@object
	.section	.rodata
.str.41:
	.asciz	"G"
	.size	.str.41, 147

	.type	.str.42 ,@object
	.section	.rodata
.str.42:
	.asciz	"H"
	.size	.str.42, 147

	.type	.str.43 ,@object
	.section	.rodata
.str.43:
	.asciz	"I"
	.size	.str.43, 147

	.type	.str.44 ,@object
	.section	.rodata
.str.44:
	.asciz	"J"
	.size	.str.44, 147

	.type	.str.45 ,@object
	.section	.rodata
.str.45:
	.asciz	"K"
	.size	.str.45, 147

	.type	.str.46 ,@object
	.section	.rodata
.str.46:
	.asciz	"L"
	.size	.str.46, 147

	.type	.str.47 ,@object
	.section	.rodata
.str.47:
	.asciz	"M"
	.size	.str.47, 147

	.type	.str.48 ,@object
	.section	.rodata
.str.48:
	.asciz	"N"
	.size	.str.48, 147

	.type	.str.49 ,@object
	.section	.rodata
.str.49:
	.asciz	"O"
	.size	.str.49, 147

	.type	.str.50 ,@object
	.section	.rodata
.str.50:
	.asciz	"P"
	.size	.str.50, 147

	.type	.str.51 ,@object
	.section	.rodata
.str.51:
	.asciz	"Q"
	.size	.str.51, 147

	.type	.str.52 ,@object
	.section	.rodata
.str.52:
	.asciz	"R"
	.size	.str.52, 147

	.type	.str.53 ,@object
	.section	.rodata
.str.53:
	.asciz	"S"
	.size	.str.53, 147

	.type	.str.54 ,@object
	.section	.rodata
.str.54:
	.asciz	"T"
	.size	.str.54, 147

	.type	.str.55 ,@object
	.section	.rodata
.str.55:
	.asciz	"U"
	.size	.str.55, 147

	.type	.str.56 ,@object
	.section	.rodata
.str.56:
	.asciz	"V"
	.size	.str.56, 147

	.type	.str.57 ,@object
	.section	.rodata
.str.57:
	.asciz	"W"
	.size	.str.57, 147

	.type	.str.58 ,@object
	.section	.rodata
.str.58:
	.asciz	"X"
	.size	.str.58, 147

	.type	.str.59 ,@object
	.section	.rodata
.str.59:
	.asciz	"Y"
	.size	.str.59, 147

	.type	.str.60 ,@object
	.section	.rodata
.str.60:
	.asciz	"Z"
	.size	.str.60, 147

	.type	.str.61 ,@object
	.section	.rodata
.str.61:
	.asciz	"["
	.size	.str.61, 147

	.type	.str.62 ,@object
	.section	.rodata
.str.62:
	.asciz	"]"
	.size	.str.62, 147

	.type	.str.63 ,@object
	.section	.rodata
.str.63:
	.asciz	"^"
	.size	.str.63, 147

	.type	.str.64 ,@object
	.section	.rodata
.str.64:
	.asciz	"_"
	.size	.str.64, 147

	.type	.str.65 ,@object
	.section	.rodata
.str.65:
	.asciz	"`"
	.size	.str.65, 147

	.type	.str.66 ,@object
	.section	.rodata
.str.66:
	.asciz	"a"
	.size	.str.66, 147

	.type	.str.67 ,@object
	.section	.rodata
.str.67:
	.asciz	"b"
	.size	.str.67, 147

	.type	.str.68 ,@object
	.section	.rodata
.str.68:
	.asciz	"c"
	.size	.str.68, 147

	.type	.str.69 ,@object
	.section	.rodata
.str.69:
	.asciz	"d"
	.size	.str.69, 147

	.type	.str.70 ,@object
	.section	.rodata
.str.70:
	.asciz	"e"
	.size	.str.70, 147

	.type	.str.71 ,@object
	.section	.rodata
.str.71:
	.asciz	"f"
	.size	.str.71, 147

	.type	.str.72 ,@object
	.section	.rodata
.str.72:
	.asciz	"g"
	.size	.str.72, 147

	.type	.str.73 ,@object
	.section	.rodata
.str.73:
	.asciz	"h"
	.size	.str.73, 147

	.type	.str.74 ,@object
	.section	.rodata
.str.74:
	.asciz	"i"
	.size	.str.74, 147

	.type	.str.75 ,@object
	.section	.rodata
.str.75:
	.asciz	"j"
	.size	.str.75, 147

	.type	.str.76 ,@object
	.section	.rodata
.str.76:
	.asciz	"k"
	.size	.str.76, 147

	.type	.str.77 ,@object
	.section	.rodata
.str.77:
	.asciz	"l"
	.size	.str.77, 147

	.type	.str.78 ,@object
	.section	.rodata
.str.78:
	.asciz	"m"
	.size	.str.78, 147

	.type	.str.79 ,@object
	.section	.rodata
.str.79:
	.asciz	"n"
	.size	.str.79, 147

	.type	.str.80 ,@object
	.section	.rodata
.str.80:
	.asciz	"o"
	.size	.str.80, 147

	.type	.str.81 ,@object
	.section	.rodata
.str.81:
	.asciz	"p"
	.size	.str.81, 147

	.type	.str.82 ,@object
	.section	.rodata
.str.82:
	.asciz	"q"
	.size	.str.82, 147

	.type	.str.83 ,@object
	.section	.rodata
.str.83:
	.asciz	"r"
	.size	.str.83, 147

	.type	.str.84 ,@object
	.section	.rodata
.str.84:
	.asciz	"s"
	.size	.str.84, 147

	.type	.str.85 ,@object
	.section	.rodata
.str.85:
	.asciz	"t"
	.size	.str.85, 147

	.type	.str.86 ,@object
	.section	.rodata
.str.86:
	.asciz	"u"
	.size	.str.86, 147

	.type	.str.87 ,@object
	.section	.rodata
.str.87:
	.asciz	"v"
	.size	.str.87, 147

	.type	.str.88 ,@object
	.section	.rodata
.str.88:
	.asciz	"w"
	.size	.str.88, 147

	.type	.str.89 ,@object
	.section	.rodata
.str.89:
	.asciz	"x"
	.size	.str.89, 147

	.type	.str.90 ,@object
	.section	.rodata
.str.90:
	.asciz	"y"
	.size	.str.90, 147

	.type	.str.91 ,@object
	.section	.rodata
.str.91:
	.asciz	"z"
	.size	.str.91, 147

	.type	.str.92 ,@object
	.section	.rodata
.str.92:
	.asciz	"{"
	.size	.str.92, 147

	.type	.str.93 ,@object
	.section	.rodata
.str.93:
	.asciz	"|"
	.size	.str.93, 147

	.type	.str.94 ,@object
	.section	.rodata
.str.94:
	.asciz	"}"
	.size	.str.94, 147

	.type	.str.95 ,@object
	.section	.rodata
.str.95:
	.asciz	"~"
	.size	.str.95, 147

	.type	.str.96 ,@object
	.section	.rodata
.str.96:
	.asciz	"int main(){int i=0;// Quine is a a program that produces its source code as output."
	.size	.str.96, 147

	.type	.str.97 ,@object
	.section	.rodata
.str.97:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[0]+c[66]+c[71]+c[69]+c[82]+c[7]+c[71]+c[76]+c[82]+c[0]+c[86]+c[8]+c[89]);"
	.size	.str.97, 147

	.type	.str.98 ,@object
	.section	.rodata
.str.98:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[15]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[15]+a2q+c[26]);"
	.size	.str.98, 147

	.type	.str.99 ,@object
	.section	.rodata
.str.99:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[16]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[16]+a2q+c[26]);"
	.size	.str.99, 147

	.type	.str.100 ,@object
	.section	.rodata
.str.100:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[17]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[17]+a2q+c[26]);"
	.size	.str.100, 147

	.type	.str.101 ,@object
	.section	.rodata
.str.101:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[18]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[18]+a2q+c[26]);"
	.size	.str.101, 147

	.type	.str.102 ,@object
	.section	.rodata
.str.102:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[19]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[19]+a2q+c[26]);"
	.size	.str.102, 147

	.type	.str.103 ,@object
	.section	.rodata
.str.103:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[20]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[20]+a2q+c[26]);"
	.size	.str.103, 147

	.type	.str.104 ,@object
	.section	.rodata
.str.104:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[21]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[21]+a2q+c[26]);"
	.size	.str.104, 147

	.type	.str.105 ,@object
	.section	.rodata
.str.105:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[22]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[22]+a2q+c[26]);"
	.size	.str.105, 147

	.type	.str.106 ,@object
	.section	.rodata
.str.106:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[23]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[23]+a2q+c[26]);"
	.size	.str.106, 147

	.type	.str.107 ,@object
	.section	.rodata
.str.107:
	.asciz	"println(c[71]+c[68]+c[7]+c[86]+c[28]+c[28]+c[24]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[24]+a2q+c[26]);"
	.size	.str.107, 147

	.type	.str.108 ,@object
	.section	.rodata
.str.108:
	.asciz	"println(c[91]);"
	.size	.str.108, 147

	.type	.str.109 ,@object
	.section	.rodata
.str.109:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[58]+c[59]+c[0]+c[81]+c[28]+c[76]+c[67]+c[85]+c[0]+c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[58]+c[17]+c[20]+c[21]+c[59]+c[26]);"
	.size	.str.109, 147

	.type	.str.110 ,@object
	.section	.rodata
.str.110:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[58]+c[59]+c[0]+c[65]+c[28]+c[76]+c[67]+c[85]+c[0]+c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[58]+c[17]+c[20]+c[21]+c[59]+c[26]);"
	.size	.str.110, 147

	.type	.str.111 ,@object
	.section	.rodata
.str.111:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[0]+c[81]+c[17]+c[7]+c[71]+c[76]+c[82]+c[0]+c[81]+c[81]+c[8]+c[89]);"
	.size	.str.111, 147

	.type	.str.112 ,@object
	.section	.rodata
.str.112:
	.asciz	"println(c[71]+c[68]+c[7]+c[81]+c[81]+c[27]+c[28]+c[24]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[81]+c[58]+a2q+c[10]+c[66]+c[71]+c[69]+c[82]+c[7]+c[81]+c[81]+c[8]+c[10]+a2q+c[59]+c[28]+a2q+c[26]);"
	.size	.str.112, 147

	.type	.str.113 ,@object
	.section	.rodata
.str.113:
	.asciz	"println(c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[81]+c[58]+a2q+c[10]+c[66]+c[71]+c[69]+c[82]+c[7]+c[81]+c[81]+c[14]+c[16]+c[15]+c[8]+c[10]+c[66]+c[71]+c[69]+c[82]+c[7]+c[81]+c[81]+c[4]+c[16]+c[15]+c[8]+c[10]+a2q+c[59]+c[28]+a2q+c[26]);"
	.size	.str.113, 147

	.type	.str.114 ,@object
	.section	.rodata
.str.114:
	.asciz	"println(c[91]);"
	.size	.str.114, 147

	.type	.str.115 ,@object
	.section	.rodata
.str.115:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[0]+c[65]+c[17]+c[7]+c[71]+c[76]+c[82]+c[0]+c[65]+c[65]+c[8]+c[89]);"
	.size	.str.115, 147

	.type	.str.116 ,@object
	.section	.rodata
.str.116:
	.asciz	"println(c[71]+c[68]+c[7]+c[65]+c[65]+c[27]+c[28]+c[24]+c[8]+c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[65]+c[58]+a2q+c[10]+c[66]+c[71]+c[69]+c[82]+c[7]+c[65]+c[65]+c[8]+c[10]+a2q+c[59]+c[28]+a2q+c[26]);"
	.size	.str.116, 147

	.type	.str.117 ,@object
	.section	.rodata
.str.117:
	.asciz	"println(c[80]+c[67]+c[82]+c[83]+c[80]+c[76]+c[0]+a2q+c[65]+c[58]+a2q+c[10]+c[66]+c[71]+c[69]+c[82]+c[7]+c[65]+c[65]+c[14]+c[16]+c[15]+c[8]+c[10]+c[66]+c[71]+c[69]+c[82]+c[7]+c[65]+c[65]+c[4]+c[16]+c[15]+c[8]+c[10]+a2q+c[59]+c[28]+a2q+c[26]);"
	.size	.str.117, 147

	.type	.str.118 ,@object
	.section	.rodata
.str.118:
	.asciz	"println(c[91]);"
	.size	.str.118, 147

	.type	.str.119 ,@object
	.section	.rodata
.str.119:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[0]+c[65]+c[77]+c[28]+a2q+c[26]+a2q+c[26]);"
	.size	.str.119, 147

	.type	.str.120 ,@object
	.section	.rodata
.str.120:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[0]+c[63]+c[17]+c[79]+c[28]+a2q+a2b+a2q+a2q+c[26]);"
	.size	.str.120, 147

	.type	.str.121 ,@object
	.section	.rodata
.str.121:
	.asciz	"println(c[81]+c[82]+c[80]+c[71]+c[76]+c[69]+c[0]+c[63]+c[17]+c[64]+c[28]+a2q+a2b+a2b+a2q+c[26]);"
	.size	.str.121, 147

	.type	.str.122 ,@object
	.section	.rodata
.str.122:
	.asciz	"println(s[0]);"
	.size	.str.122, 147

	.type	.str.123 ,@object
	.section	.rodata
.str.123:
	.asciz	"for(i=0;i<93;i++)println(c2(i)+a2q+c[i]+a2q+co);"
	.size	.str.123, 147

	.type	.str.124 ,@object
	.section	.rodata
.str.124:
	.asciz	"for(i=0;i<32;i++)println(s2(i)+a2q+s[i]+a2q+co);"
	.size	.str.124, 147

	.type	.str.125 ,@object
	.section	.rodata
.str.125:
	.asciz	"for(i=1;i<32;i++)println(s[i]);"
	.size	.str.125, 147

	.type	.str.126 ,@object
	.section	.rodata
.str.126:
	.asciz	"return 0;"
	.size	.str.126, 147

	.type	.str.127 ,@object
	.section	.rodata
.str.127:
	.asciz	"}"
	.size	.str.127, 147

	.type	.str.128 ,@object
	.section	.rodata
.str.128:
	.asciz	"0"
	.size	.str.128, 147

	.type	.str.129 ,@object
	.section	.rodata
.str.129:
	.asciz	"1"
	.size	.str.129, 147

	.type	.str.130 ,@object
	.section	.rodata
.str.130:
	.asciz	"2"
	.size	.str.130, 147

	.type	.str.131 ,@object
	.section	.rodata
.str.131:
	.asciz	"3"
	.size	.str.131, 147

	.type	.str.132 ,@object
	.section	.rodata
.str.132:
	.asciz	"4"
	.size	.str.132, 147

	.type	.str.133 ,@object
	.section	.rodata
.str.133:
	.asciz	"5"
	.size	.str.133, 147

	.type	.str.134 ,@object
	.section	.rodata
.str.134:
	.asciz	"6"
	.size	.str.134, 147

	.type	.str.135 ,@object
	.section	.rodata
.str.135:
	.asciz	"7"
	.size	.str.135, 147

	.type	.str.136 ,@object
	.section	.rodata
.str.136:
	.asciz	"8"
	.size	.str.136, 147

	.type	.str.137 ,@object
	.section	.rodata
.str.137:
	.asciz	"9"
	.size	.str.137, 147

	.type	.str.138 ,@object
	.section	.rodata
.str.138:
	.asciz	"s["
	.size	.str.138, 147

	.type	.str.139 ,@object
	.section	.rodata
.str.139:
	.asciz	"]="
	.size	.str.139, 147

	.type	.str.140 ,@object
	.section	.rodata
.str.140:
	.asciz	"s["
	.size	.str.140, 147

	.type	.str.141 ,@object
	.section	.rodata
.str.141:
	.asciz	"]="
	.size	.str.141, 147

	.type	.str.142 ,@object
	.section	.rodata
.str.142:
	.asciz	"c["
	.size	.str.142, 147

	.type	.str.143 ,@object
	.section	.rodata
.str.143:
	.asciz	"]="
	.size	.str.143, 147

	.type	.str.144 ,@object
	.section	.rodata
.str.144:
	.asciz	"c["
	.size	.str.144, 147

	.type	.str.145 ,@object
	.section	.rodata
.str.145:
	.asciz	"]="
	.size	.str.145, 147

