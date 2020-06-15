        .text
        .globl	print
        .p2align	2
        .type	print,@function
print:                                  # @print
        addi    sp, sp, -16
        sw      ra, 12(sp)
        add     a1, zero, a0
        lui     a0, %hi(.L.str)
        addi    a0, a0, %lo(.L.str)
        call    printf
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	printInt
        .p2align	2
        .type	printInt,@function
printInt:                               # @printInt
        addi    sp, sp, -16
        sw      ra, 12(sp)
        add     a1, zero, a0
        lui     a0, %hi(.L.str.1)
        addi    a0, a0, %lo(.L.str.1)
        call    printf
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	printlnInt
        .p2align	2
        .type	printlnInt,@function
printlnInt:                             # @printlnInt
        addi    sp, sp, -16
        sw      ra, 12(sp)
        add     a1, zero, a0
        lui     a0, %hi(.L.str.2)
        addi    a0, a0, %lo(.L.str.2)
        call    printf
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	getString
        .p2align	2
        .type	getString,@function
getString:                              # @getString
        addi    sp, sp, -16
        sw      ra, 12(sp)
        sw      s0, 8(sp)
        addi    a0, zero, 128
        call    malloc
        add     s0, zero, a0
        lui     a0, %hi(.L.str)
        addi    a0, a0, %lo(.L.str)
        add     a1, zero, s0
        call    scanf
        add     a0, zero, s0
        lw      s0, 8(sp)
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	getInt
        .p2align	2
        .type	getInt,@function
getInt:                                 # @getInt
        addi    sp, sp, -16
        sw      ra, 12(sp)
        lui     a0, %hi(.L.str.1)
        addi    a0, a0, %lo(.L.str.1)
        addi    a1, sp, 8
        call    scanf
        lw      a0, 8(sp)
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	toString
        .p2align	2
        .type	toString,@function
toString:                               # @toString
        addi    sp, sp, -16
        sw      ra, 12(sp)
        sw      s0, 8(sp)
        sw      s1, 4(sp)
        add     s0, zero, a0
        addi    a0, zero, 12
        call    malloc
        add     s1, zero, a0
        lui     a0, %hi(.L.str.1)
        addi    a1, a0, %lo(.L.str.1)
        add     a0, zero, s1
        add     a2, zero, s0
        call    sprintf
        add     a0, zero, s1
        lw      s1, 4(sp)
        lw      s0, 8(sp)
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	string_ord
        .p2align	2
        .type	string_ord,@function
string_ord:                             # @string_ord
        add     a0, a0, a1
        lbu     a0, 0(a0)
        ret

        .globl	array_size
        .p2align	2
        .type	array_size,@function
array_size:                             # @array_size
        lw      a0, -4(a0)
        ret

        .globl	string_substring
        .p2align	2
        .type	string_substring,@function
string_substring:                       # @string_substring
        addi    sp, sp, -32
        sw      ra, 28(sp)
        sw      s0, 24(sp)
        sw      s1, 20(sp)
        sw      s2, 16(sp)
        sw      s3, 12(sp)
        add     s0, zero, a1
        add     s2, zero, a0
        sub     s3, a2, a1
        addi    a0, s3, 1
        call    malloc
        add     s1, zero, a0
        add     a1, s2, s0
        add     a2, zero, s3
        call    memcpy
        add     a0, zero, s1
        lw      s3, 12(sp)
        lw      s2, 16(sp)
        lw      s1, 20(sp)
        lw      s0, 24(sp)
        lw      ra, 28(sp)
        addi    sp, sp, 32
        ret

        .globl	string_parseInt
        .p2align	2
        .type	string_parseInt,@function
string_parseInt:                        # @string_parseInt
        addi    sp, sp, -16
        sw      ra, 12(sp)
        lui     a1, %hi(.L.str.1)
        addi    a1, a1, %lo(.L.str.1)
        addi    a2, sp, 8
        call    sscanf
        lw      a0, 8(sp)
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	string_length
        .p2align	2
        .type	string_length,@function
string_length:                          # @string_length
        addi    sp, sp, -16
        sw      ra, 12(sp)
        call    strlen
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	string_strcat
        .p2align	2
        .type	string_strcat,@function
string_strcat:                          # @string_strcat
        addi    sp, sp, -32
        sw      ra, 28(sp)
        sw      s0, 24(sp)
        sw      s1, 20(sp)
        sw      s2, 16(sp)
        sw      s3, 12(sp)
        add     s2, zero, a1
        add     s3, zero, a0
        call    strlen
        add     s0, zero, a0
        add     a0, zero, s2
        call    strlen
        add     a0, a0, s0
        addi    a0, a0, 1
        call    malloc
        add     s1, zero, a0
        add     a1, zero, s3
        add     a2, zero, s0
        call    memcpy
        add     a0, zero, s1
        add     a1, zero, s2
        call    strcat
        add     a0, zero, s1
        lw      s3, 12(sp)
        lw      s2, 16(sp)
        lw      s1, 20(sp)
        lw      s0, 24(sp)
        lw      ra, 28(sp)
        addi    sp, sp, 32
        ret

        .globl	string_equal
        .p2align	2
        .type	string_equal,@function
string_equal:                           # @string_equal
        addi    sp, sp, -16
        sw      ra, 12(sp)
        call    strcmp
        seqz    a0, a0
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	string_less
        .p2align	2
        .type	string_less,@function
string_less:                            # @string_less
        addi    sp, sp, -16
        sw      ra, 12(sp)
        call    strcmp
        srli    a0, a0, 31
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .globl	string_greater
        .p2align	2
        .type	string_greater,@function
string_greater:                         # @string_greater
        addi    sp, sp, -16
        sw      ra, 12(sp)
        call    strcmp
        sgtz    a0, a0
        lw      ra, 12(sp)
        addi    sp, sp, 16
        ret

        .data
.L.str:
        .asciz  "%s"

.L.str.1:
        .asciz  "%d"

.L.str.2:
        .asciz  "%d\n"