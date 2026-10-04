// EXPORTED & PLT DISASSEMBLY FOR libhttpelf.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhttpelf.so (SHA-256: 26CA2AC83E64FE651C4CBC15CF124FC8D86A51F560D753A6FAE7CC840DD3EA91)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 1, JNI Methods: 1


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhttpelf.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000000b970 <.plt>:
    b970:      	stp	x16, x30, [sp, #-0x10]!
    b974:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b978:      	ldr	x17, [x16, #0xe40]
    b97c:      	add	x16, x16, #0xe40
    b980:      	br	x17
    b984:      	nop
    b988:      	nop
    b98c:      	nop

000000000000b990 <__cxa_finalize@plt>:
    b990:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b994:      	ldr	x17, [x16, #0xe48]
    b998:      	add	x16, x16, #0xe48
    b99c:      	br	x17

000000000000b9a0 <__cxa_atexit@plt>:
    b9a0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b9a4:      	ldr	x17, [x16, #0xe50]
    b9a8:      	add	x16, x16, #0xe50
    b9ac:      	br	x17

000000000000b9b0 <memcpy@plt>:
    b9b0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b9b4:      	ldr	x17, [x16, #0xe58]
    b9b8:      	add	x16, x16, #0xe58
    b9bc:      	br	x17

000000000000b9c0 <strlen@plt>:
    b9c0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b9c4:      	ldr	x17, [x16, #0xe60]
    b9c8:      	add	x16, x16, #0xe60
    b9cc:      	br	x17

000000000000b9d0 <strcpy@plt>:
    b9d0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b9d4:      	ldr	x17, [x16, #0xe68]
    b9d8:      	add	x16, x16, #0xe68
    b9dc:      	br	x17

000000000000b9e0 <__stack_chk_fail@plt>:
    b9e0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b9e4:      	ldr	x17, [x16, #0xe70]
    b9e8:      	add	x16, x16, #0xe70
    b9ec:      	br	x17

000000000000b9f0 <_ZdaPv@plt>:
    b9f0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    b9f4:      	ldr	x17, [x16, #0xe78]
    b9f8:      	add	x16, x16, #0xe78
    b9fc:      	br	x17

000000000000ba00 <_Znwm@plt>:
    ba00:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba04:      	ldr	x17, [x16, #0xe80]
    ba08:      	add	x16, x16, #0xe80
    ba0c:      	br	x17

000000000000ba10 <_ZdlPv@plt>:
    ba10:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba14:      	ldr	x17, [x16, #0xe88]
    ba18:      	add	x16, x16, #0xe88
    ba1c:      	br	x17

000000000000ba20 <gettimeofday@plt>:
    ba20:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba24:      	ldr	x17, [x16, #0xe90]
    ba28:      	add	x16, x16, #0xe90
    ba2c:      	br	x17

000000000000ba30 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
    ba30:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba34:      	ldr	x17, [x16, #0xe98]
    ba38:      	add	x16, x16, #0xe98
    ba3c:      	br	x17

000000000000ba40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
    ba40:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba44:      	ldr	x17, [x16, #0xea0]
    ba48:      	add	x16, x16, #0xea0
    ba4c:      	br	x17

000000000000ba50 <_Znam@plt>:
    ba50:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba54:      	ldr	x17, [x16, #0xea8]
    ba58:      	add	x16, x16, #0xea8
    ba5c:      	br	x17

000000000000ba60 <__vsnprintf_chk@plt>:
    ba60:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba64:      	ldr	x17, [x16, #0xeb0]
    ba68:      	add	x16, x16, #0xeb0
    ba6c:      	br	x17

000000000000ba70 <__cxa_allocate_exception@plt>:
    ba70:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba74:      	ldr	x17, [x16, #0xeb8]
    ba78:      	add	x16, x16, #0xeb8
    ba7c:      	br	x17

000000000000ba80 <__cxa_throw@plt>:
    ba80:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba84:      	ldr	x17, [x16, #0xec0]
    ba88:      	add	x16, x16, #0xec0
    ba8c:      	br	x17

000000000000ba90 <__cxa_free_exception@plt>:
    ba90:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    ba94:      	ldr	x17, [x16, #0xec8]
    ba98:      	add	x16, x16, #0xec8
    ba9c:      	br	x17

000000000000baa0 <_ZNSt11logic_errorC2EPKc@plt>:
    baa0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    baa4:      	ldr	x17, [x16, #0xed0]
    baa8:      	add	x16, x16, #0xed0
    baac:      	br	x17

000000000000bab0 <__memcpy_chk@plt>:
    bab0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bab4:      	ldr	x17, [x16, #0xed8]
    bab8:      	add	x16, x16, #0xed8
    babc:      	br	x17

000000000000bac0 <memset@plt>:
    bac0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bac4:      	ldr	x17, [x16, #0xee0]
    bac8:      	add	x16, x16, #0xee0
    bacc:      	br	x17

000000000000bad0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
    bad0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bad4:      	ldr	x17, [x16, #0xee8]
    bad8:      	add	x16, x16, #0xee8
    badc:      	br	x17

000000000000bae0 <fprintf@plt>:
    bae0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bae4:      	ldr	x17, [x16, #0xef0]
    bae8:      	add	x16, x16, #0xef0
    baec:      	br	x17

000000000000baf0 <fflush@plt>:
    baf0:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    baf4:      	ldr	x17, [x16, #0xef8]
    baf8:      	add	x16, x16, #0xef8
    bafc:      	br	x17

000000000000bb00 <abort@plt>:
    bb00:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb04:      	ldr	x17, [x16, #0xf00]
    bb08:      	add	x16, x16, #0xf00
    bb0c:      	br	x17

000000000000bb10 <pthread_rwlock_wrlock@plt>:
    bb10:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb14:      	ldr	x17, [x16, #0xf08]
    bb18:      	add	x16, x16, #0xf08
    bb1c:      	br	x17

000000000000bb20 <pthread_rwlock_unlock@plt>:
    bb20:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb24:      	ldr	x17, [x16, #0xf10]
    bb28:      	add	x16, x16, #0xf10
    bb2c:      	br	x17

000000000000bb30 <malloc@plt>:
    bb30:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb34:      	ldr	x17, [x16, #0xf18]
    bb38:      	add	x16, x16, #0xf18
    bb3c:      	br	x17

000000000000bb40 <free@plt>:
    bb40:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb44:      	ldr	x17, [x16, #0xf20]
    bb48:      	add	x16, x16, #0xf20
    bb4c:      	br	x17

000000000000bb50 <dl_iterate_phdr@plt>:
    bb50:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb54:      	ldr	x17, [x16, #0xf28]
    bb58:      	add	x16, x16, #0xf28
    bb5c:      	br	x17

000000000000bb60 <pthread_rwlock_rdlock@plt>:
    bb60:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb64:      	ldr	x17, [x16, #0xf30]
    bb68:      	add	x16, x16, #0xf30
    bb6c:      	br	x17

000000000000bb70 <getpid@plt>:
    bb70:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb74:      	ldr	x17, [x16, #0xf38]
    bb78:      	add	x16, x16, #0xf38
    bb7c:      	br	x17

000000000000bb80 <syscall@plt>:
    bb80:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb84:      	ldr	x17, [x16, #0xf40]
    bb88:      	add	x16, x16, #0xf40
    bb8c:      	br	x17

000000000000bb90 <fwrite@plt>:
    bb90:      	adrp	x16, 0xf000 <fwrite@plt+0x3470>
    bb94:      	ldr	x17, [x16, #0xf48]
    bb98:      	add	x16, x16, #0xf48
    bb9c:      	br	x17
