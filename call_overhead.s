	.arch armv6
	.eabi_attribute 28, 1
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"call_overhead.c"
	.text
	.align	2
	.global	call0
	.arch armv6
	.syntax unified
	.arm
	.fpu vfp
	.type	call0, %function
call0:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call0, .-call0
	.align	2
	.global	call1
	.syntax unified
	.arm
	.fpu vfp
	.type	call1, %function
call1:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call1, .-call1
	.align	2
	.global	call2
	.syntax unified
	.arm
	.fpu vfp
	.type	call2, %function
call2:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #12
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call2, .-call2
	.align	2
	.global	call3
	.syntax unified
	.arm
	.fpu vfp
	.type	call3, %function
call3:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call3, .-call3
	.align	2
	.global	call4
	.syntax unified
	.arm
	.fpu vfp
	.type	call4, %function
call4:
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call4, .-call4
	.align	2
	.global	call5
	.syntax unified
	.arm
	.fpu vfp
	.type	call5, %function
call5:
	@ args = 4, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call5, .-call5
	.align	2
	.global	call6
	.syntax unified
	.arm
	.fpu vfp
	.type	call6, %function
call6:
	@ args = 8, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call6, .-call6
	.align	2
	.global	call7
	.syntax unified
	.arm
	.fpu vfp
	.type	call7, %function
call7:
	@ args = 12, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	str	fp, [sp, #-4]!
	add	fp, sp, #0
	sub	sp, sp, #20
	str	r0, [fp, #-8]
	str	r1, [fp, #-12]
	str	r2, [fp, #-16]
	str	r3, [fp, #-20]
	nop
	add	sp, fp, #0
	@ sp needed
	ldr	fp, [sp], #4
	bx	lr
	.size	call7, .-call7
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%u\012\000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu vfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 56
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #72
	str	r0, [fp, #-56]
	str	r1, [fp, #-60]
	ldr	r3, [fp, #-60]
	add	r3, r3, #4
	ldr	r3, [r3]
	mov	r2, #10
	mov	r1, #0
	mov	r0, r3
	bl	strtol
	str	r0, [fp, #-40]
	mov	r3, #0
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-48]
	mov	r3, #1000
	str	r3, [fp, #-52]
	mov	r3, #-2147483641
	.syntax divided
@ 43 "call_overhead.c" 1
	MCR p15, 0, r3, c9, c12, 0	

@ 0 "" 2
	.arm
	.syntax unified
	mov	r3, #-2147483633
	.syntax divided
@ 44 "call_overhead.c" 1
	MCR p15, 0, r3, c9, c12, 3	

@ 0 "" 2
	.arm
	.syntax unified
	ldr	r3, [fp, #-40]
	cmp	r3, #0
	bne	.L10
	.syntax divided
@ 47 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L11
.L12:
	bl	call0
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L11:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L12
	.syntax divided
@ 51 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L10:
	ldr	r3, [fp, #-40]
	cmp	r3, #1
	bne	.L13
	.syntax divided
@ 57 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L14
.L15:
	mov	r0, #0
	bl	call1
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L14:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L15
	.syntax divided
@ 61 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L13:
	ldr	r3, [fp, #-40]
	cmp	r3, #2
	bne	.L16
	.syntax divided
@ 67 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L17
.L18:
	mov	r1, #0
	mov	r0, #0
	bl	call2
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L17:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L18
	.syntax divided
@ 71 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L16:
	ldr	r3, [fp, #-40]
	cmp	r3, #3
	bne	.L19
	.syntax divided
@ 77 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-20]
	b	.L20
.L21:
	mov	r2, #0
	mov	r1, #0
	mov	r0, #0
	bl	call3
	ldr	r3, [fp, #-20]
	add	r3, r3, #1
	str	r3, [fp, #-20]
.L20:
	ldr	r2, [fp, #-20]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L21
	.syntax divided
@ 81 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L19:
	ldr	r3, [fp, #-40]
	cmp	r3, #4
	bne	.L22
	.syntax divided
@ 87 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-24]
	b	.L23
.L24:
	mov	r3, #0
	mov	r2, #0
	mov	r1, #0
	mov	r0, #0
	bl	call4
	ldr	r3, [fp, #-24]
	add	r3, r3, #1
	str	r3, [fp, #-24]
.L23:
	ldr	r2, [fp, #-24]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L24
	.syntax divided
@ 91 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L22:
	ldr	r3, [fp, #-40]
	cmp	r3, #5
	bne	.L25
	.syntax divided
@ 97 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-28]
	b	.L26
.L27:
	mov	r3, #0
	str	r3, [sp]
	mov	r3, #0
	mov	r2, #0
	mov	r1, #0
	mov	r0, #0
	bl	call5
	ldr	r3, [fp, #-28]
	add	r3, r3, #1
	str	r3, [fp, #-28]
.L26:
	ldr	r2, [fp, #-28]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L27
	.syntax divided
@ 101 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L25:
	ldr	r3, [fp, #-40]
	cmp	r3, #6
	bne	.L28
	.syntax divided
@ 107 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-32]
	b	.L29
.L30:
	mov	r3, #0
	str	r3, [sp, #4]
	mov	r3, #0
	str	r3, [sp]
	mov	r3, #0
	mov	r2, #0
	mov	r1, #0
	mov	r0, #0
	bl	call6
	ldr	r3, [fp, #-32]
	add	r3, r3, #1
	str	r3, [fp, #-32]
.L29:
	ldr	r2, [fp, #-32]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L30
	.syntax divided
@ 111 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L28:
	ldr	r3, [fp, #-40]
	cmp	r3, #7
	bne	.L31
	.syntax divided
@ 117 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-44]
	mov	r3, #0
	str	r3, [fp, #-36]
	b	.L32
.L33:
	mov	r3, #0
	str	r3, [sp, #8]
	mov	r3, #0
	str	r3, [sp, #4]
	mov	r3, #0
	str	r3, [sp]
	mov	r3, #0
	mov	r2, #0
	mov	r1, #0
	mov	r0, #0
	bl	call7
	ldr	r3, [fp, #-36]
	add	r3, r3, #1
	str	r3, [fp, #-36]
.L32:
	ldr	r2, [fp, #-36]
	ldr	r3, [fp, #-52]
	cmp	r2, r3
	blt	.L33
	.syntax divided
@ 121 "call_overhead.c" 1
	mrc p15, 0, r3, c9, c13, 0
@ 0 "" 2
	.arm
	.syntax unified
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-48]
	ldr	r3, [fp, #-44]
	sub	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L35
	bl	printf
.L31:
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L36:
	.align	2
.L35:
	.word	.LC0
	.size	main, .-main
	.ident	"GCC: (Raspbian 8.3.0-6+rpi1) 8.3.0"
	.section	.note.GNU-stack,"",%progbits
