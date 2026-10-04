// EXPORTED & PLT DISASSEMBLY FOR libfntvcrash.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfntvcrash.so (SHA-256: 91B4BFD158229E340D5C7F6722DF9D1A1AB72B9E3A5DD72DA903BAD571FA7E11)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 1, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfntvcrash.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000000cd30 <.plt>:
    cd30:      	stp	x16, x30, [sp, #-0x10]!
    cd34:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cd38:      	ldr	x17, [x16, #0x3f8]
    cd3c:      	add	x16, x16, #0x3f8
    cd40:      	br	x17
    cd44:      	nop
    cd48:      	nop
    cd4c:      	nop

000000000000cd50 <__cxa_finalize@plt>:
    cd50:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cd54:      	ldr	x17, [x16, #0x400]
    cd58:      	add	x16, x16, #0x400
    cd5c:      	br	x17

000000000000cd60 <__cxa_atexit@plt>:
    cd60:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cd64:      	ldr	x17, [x16, #0x408]
    cd68:      	add	x16, x16, #0x408
    cd6c:      	br	x17

000000000000cd70 <gettimeofday@plt>:
    cd70:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cd74:      	ldr	x17, [x16, #0x410]
    cd78:      	add	x16, x16, #0x410
    cd7c:      	br	x17

000000000000cd80 <__errno@plt>:
    cd80:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cd84:      	ldr	x17, [x16, #0x418]
    cd88:      	add	x16, x16, #0x418
    cd8c:      	br	x17

000000000000cd90 <localtime_r@plt>:
    cd90:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cd94:      	ldr	x17, [x16, #0x420]
    cd98:      	add	x16, x16, #0x420
    cd9c:      	br	x17

000000000000cda0 <strdup@plt>:
    cda0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cda4:      	ldr	x17, [x16, #0x428]
    cda8:      	add	x16, x16, #0x428
    cdac:      	br	x17

000000000000cdb0 <getpid@plt>:
    cdb0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cdb4:      	ldr	x17, [x16, #0x430]
    cdb8:      	add	x16, x16, #0x430
    cdbc:      	br	x17

000000000000cdc0 <free@plt>:
    cdc0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cdc4:      	ldr	x17, [x16, #0x438]
    cdc8:      	add	x16, x16, #0x438
    cdcc:      	br	x17

000000000000cdd0 <lseek@plt>:
    cdd0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cdd4:      	ldr	x17, [x16, #0x440]
    cdd8:      	add	x16, x16, #0x440
    cddc:      	br	x17

000000000000cde0 <close@plt>:
    cde0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cde4:      	ldr	x17, [x16, #0x448]
    cde8:      	add	x16, x16, #0x448
    cdec:      	br	x17

000000000000cdf0 <__strlen_chk@plt>:
    cdf0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cdf4:      	ldr	x17, [x16, #0x450]
    cdf8:      	add	x16, x16, #0x450
    cdfc:      	br	x17

000000000000ce00 <__open_2@plt>:
    ce00:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce04:      	ldr	x17, [x16, #0x458]
    ce08:      	add	x16, x16, #0x458
    ce0c:      	br	x17

000000000000ce10 <syscall@plt>:
    ce10:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce14:      	ldr	x17, [x16, #0x460]
    ce18:      	add	x16, x16, #0x460
    ce1c:      	br	x17

000000000000ce20 <memcmp@plt>:
    ce20:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce24:      	ldr	x17, [x16, #0x468]
    ce28:      	add	x16, x16, #0x468
    ce2c:      	br	x17

000000000000ce30 <rename@plt>:
    ce30:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce34:      	ldr	x17, [x16, #0x470]
    ce38:      	add	x16, x16, #0x470
    ce3c:      	br	x17

000000000000ce40 <open@plt>:
    ce40:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce44:      	ldr	x17, [x16, #0x478]
    ce48:      	add	x16, x16, #0x478
    ce4c:      	br	x17

000000000000ce50 <read@plt>:
    ce50:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce54:      	ldr	x17, [x16, #0x480]
    ce58:      	add	x16, x16, #0x480
    ce5c:      	br	x17

000000000000ce60 <strlen@plt>:
    ce60:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce64:      	ldr	x17, [x16, #0x488]
    ce68:      	add	x16, x16, #0x488
    ce6c:      	br	x17

000000000000ce70 <calloc@plt>:
    ce70:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce74:      	ldr	x17, [x16, #0x490]
    ce78:      	add	x16, x16, #0x490
    ce7c:      	br	x17

000000000000ce80 <eventfd@plt>:
    ce80:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce84:      	ldr	x17, [x16, #0x498]
    ce88:      	add	x16, x16, #0x498
    ce8c:      	br	x17

000000000000ce90 <pthread_create@plt>:
    ce90:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ce94:      	ldr	x17, [x16, #0x4a0]
    ce98:      	add	x16, x16, #0x4a0
    ce9c:      	br	x17

000000000000cea0 <pthread_mutex_lock@plt>:
    cea0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cea4:      	ldr	x17, [x16, #0x4a8]
    cea8:      	add	x16, x16, #0x4a8
    ceac:      	br	x17

000000000000ceb0 <clock_gettime@plt>:
    ceb0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ceb4:      	ldr	x17, [x16, #0x4b0]
    ceb8:      	add	x16, x16, #0x4b0
    cebc:      	br	x17

000000000000cec0 <gettid@plt>:
    cec0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cec4:      	ldr	x17, [x16, #0x4b8]
    cec8:      	add	x16, x16, #0x4b8
    cecc:      	br	x17

000000000000ced0 <prctl@plt>:
    ced0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    ced4:      	ldr	x17, [x16, #0x4c0]
    ced8:      	add	x16, x16, #0x4c0
    cedc:      	br	x17

000000000000cee0 <pthread_mutex_unlock@plt>:
    cee0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cee4:      	ldr	x17, [x16, #0x4c8]
    cee8:      	add	x16, x16, #0x4c8
    ceec:      	br	x17

000000000000cef0 <_exit@plt>:
    cef0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cef4:      	ldr	x17, [x16, #0x4d0]
    cef8:      	add	x16, x16, #0x4d0
    cefc:      	br	x17

000000000000cf00 <dup2@plt>:
    cf00:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf04:      	ldr	x17, [x16, #0x4d8]
    cf08:      	add	x16, x16, #0x4d8
    cf0c:      	br	x17

000000000000cf10 <pthread_join@plt>:
    cf10:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf14:      	ldr	x17, [x16, #0x4e0]
    cf18:      	add	x16, x16, #0x4e0
    cf1c:      	br	x17

000000000000cf20 <write@plt>:
    cf20:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf24:      	ldr	x17, [x16, #0x4e8]
    cf28:      	add	x16, x16, #0x4e8
    cf2c:      	br	x17

000000000000cf30 <malloc@plt>:
    cf30:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf34:      	ldr	x17, [x16, #0x4f0]
    cf38:      	add	x16, x16, #0x4f0
    cf3c:      	br	x17

000000000000cf40 <mkdir@plt>:
    cf40:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf44:      	ldr	x17, [x16, #0x4f8]
    cf48:      	add	x16, x16, #0x4f8
    cf4c:      	br	x17

000000000000cf50 <uname@plt>:
    cf50:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf54:      	ldr	x17, [x16, #0x500]
    cf58:      	add	x16, x16, #0x500
    cf5c:      	br	x17

000000000000cf60 <__memcpy_chk@plt>:
    cf60:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf64:      	ldr	x17, [x16, #0x508]
    cf68:      	add	x16, x16, #0x508
    cf6c:      	br	x17

000000000000cf70 <__strncpy_chk2@plt>:
    cf70:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf74:      	ldr	x17, [x16, #0x510]
    cf78:      	add	x16, x16, #0x510
    cf7c:      	br	x17

000000000000cf80 <sigaltstack@plt>:
    cf80:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf84:      	ldr	x17, [x16, #0x518]
    cf88:      	add	x16, x16, #0x518
    cf8c:      	br	x17

000000000000cf90 <sigfillset@plt>:
    cf90:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cf94:      	ldr	x17, [x16, #0x520]
    cf98:      	add	x16, x16, #0x520
    cf9c:      	br	x17

000000000000cfa0 <sigaction@plt>:
    cfa0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cfa4:      	ldr	x17, [x16, #0x528]
    cfa8:      	add	x16, x16, #0x528
    cfac:      	br	x17

000000000000cfb0 <sigemptyset@plt>:
    cfb0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cfb4:      	ldr	x17, [x16, #0x530]
    cfb8:      	add	x16, x16, #0x530
    cfbc:      	br	x17

000000000000cfc0 <dladdr@plt>:
    cfc0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cfc4:      	ldr	x17, [x16, #0x538]
    cfc8:      	add	x16, x16, #0x538
    cfcc:      	br	x17

000000000000cfd0 <fopen@plt>:
    cfd0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cfd4:      	ldr	x17, [x16, #0x540]
    cfd8:      	add	x16, x16, #0x540
    cfdc:      	br	x17

000000000000cfe0 <fclose@plt>:
    cfe0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cfe4:      	ldr	x17, [x16, #0x548]
    cfe8:      	add	x16, x16, #0x548
    cfec:      	br	x17

000000000000cff0 <access@plt>:
    cff0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    cff4:      	ldr	x17, [x16, #0x550]
    cff8:      	add	x16, x16, #0x550
    cffc:      	br	x17

000000000000d000 <fgets@plt>:
    d000:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d004:      	ldr	x17, [x16, #0x558]
    d008:      	add	x16, x16, #0x558
    d00c:      	br	x17

000000000000d010 <vsnprintf@plt>:
    d010:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d014:      	ldr	x17, [x16, #0x560]
    d018:      	add	x16, x16, #0x560
    d01c:      	br	x17

000000000000d020 <munmap@plt>:
    d020:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d024:      	ldr	x17, [x16, #0x568]
    d028:      	add	x16, x16, #0x568
    d02c:      	br	x17

000000000000d030 <strcmp@plt>:
    d030:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d034:      	ldr	x17, [x16, #0x570]
    d038:      	add	x16, x16, #0x570
    d03c:      	br	x17

000000000000d040 <sscanf@plt>:
    d040:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d044:      	ldr	x17, [x16, #0x578]
    d048:      	add	x16, x16, #0x578
    d04c:      	br	x17

000000000000d050 <fstat@plt>:
    d050:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d054:      	ldr	x17, [x16, #0x580]
    d058:      	add	x16, x16, #0x580
    d05c:      	br	x17

000000000000d060 <mmap@plt>:
    d060:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d064:      	ldr	x17, [x16, #0x588]
    d068:      	add	x16, x16, #0x588
    d06c:      	br	x17

000000000000d070 <dl_iterate_phdr@plt>:
    d070:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d074:      	ldr	x17, [x16, #0x590]
    d078:      	add	x16, x16, #0x590
    d07c:      	br	x17

000000000000d080 <fprintf@plt>:
    d080:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d084:      	ldr	x17, [x16, #0x598]
    d088:      	add	x16, x16, #0x598
    d08c:      	br	x17

000000000000d090 <fflush@plt>:
    d090:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d094:      	ldr	x17, [x16, #0x5a0]
    d098:      	add	x16, x16, #0x5a0
    d09c:      	br	x17

000000000000d0a0 <abort@plt>:
    d0a0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d0a4:      	ldr	x17, [x16, #0x5a8]
    d0a8:      	add	x16, x16, #0x5a8
    d0ac:      	br	x17

000000000000d0b0 <memcpy@plt>:
    d0b0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d0b4:      	ldr	x17, [x16, #0x5b0]
    d0b8:      	add	x16, x16, #0x5b0
    d0bc:      	br	x17

000000000000d0c0 <pthread_rwlock_wrlock@plt>:
    d0c0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d0c4:      	ldr	x17, [x16, #0x5b8]
    d0c8:      	add	x16, x16, #0x5b8
    d0cc:      	br	x17

000000000000d0d0 <pthread_rwlock_unlock@plt>:
    d0d0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d0d4:      	ldr	x17, [x16, #0x5c0]
    d0d8:      	add	x16, x16, #0x5c0
    d0dc:      	br	x17

000000000000d0e0 <memset@plt>:
    d0e0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d0e4:      	ldr	x17, [x16, #0x5c8]
    d0e8:      	add	x16, x16, #0x5c8
    d0ec:      	br	x17

000000000000d0f0 <pthread_rwlock_rdlock@plt>:
    d0f0:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d0f4:      	ldr	x17, [x16, #0x5d0]
    d0f8:      	add	x16, x16, #0x5d0
    d0fc:      	br	x17

000000000000d100 <fwrite@plt>:
    d100:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d104:      	ldr	x17, [x16, #0x5d8]
    d108:      	add	x16, x16, #0x5d8
    d10c:      	br	x17

000000000000d110 <__stack_chk_fail@plt>:
    d110:      	adrp	x16, 0x11000 <__stack_chk_fail@plt+0x3ef0>
    d114:      	ldr	x17, [x16, #0x5e0]
    d118:      	add	x16, x16, #0x5e0
    d11c:      	br	x17
