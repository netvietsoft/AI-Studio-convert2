// EXPORTED & PLT DISASSEMBLY FOR libfile_lock_pgl.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfile_lock_pgl.so (SHA-256: D14096B150B4B2F21263FDB4F1C61EEA3FCD76804C776DE2395B13DFBE1D8CA0)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 6, JNI Methods: 6


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfile_lock_pgl.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000000e60 <.plt>:
     e60:      	stp	x16, x30, [sp, #-0x10]!
     e64:      	adrp	x16, 0x5000
     e68:      	ldr	x17, [x16, #0xe8]
     e6c:      	add	x16, x16, #0xe8
     e70:      	br	x17
     e74:      	nop
     e78:      	nop
     e7c:      	nop

0000000000000e80 <__cxa_finalize@plt>:
     e80:      	adrp	x16, 0x5000
     e84:      	ldr	x17, [x16, #0xf0]
     e88:      	add	x16, x16, #0xf0
     e8c:      	br	x17

0000000000000e90 <__cxa_atexit@plt>:
     e90:      	adrp	x16, 0x5000
     e94:      	ldr	x17, [x16, #0xf8]
     e98:      	add	x16, x16, #0xf8
     e9c:      	br	x17

0000000000000ea0 <fcntl@plt>:
     ea0:      	adrp	x16, 0x5000
     ea4:      	ldr	x17, [x16, #0x100]
     ea8:      	add	x16, x16, #0x100
     eac:      	br	x17

0000000000000eb0 <__android_log_print@plt>:
     eb0:      	adrp	x16, 0x5000
     eb4:      	ldr	x17, [x16, #0x108]
     eb8:      	add	x16, x16, #0x108
     ebc:      	br	x17

0000000000000ec0 <__errno@plt>:
     ec0:      	adrp	x16, 0x5000
     ec4:      	ldr	x17, [x16, #0x110]
     ec8:      	add	x16, x16, #0x110
     ecc:      	br	x17

0000000000000ed0 <strerror@plt>:
     ed0:      	adrp	x16, 0x5000
     ed4:      	ldr	x17, [x16, #0x118]
     ed8:      	add	x16, x16, #0x118
     edc:      	br	x17

0000000000000ee0 <__stack_chk_fail@plt>:
     ee0:      	adrp	x16, 0x5000
     ee4:      	ldr	x17, [x16, #0x120]
     ee8:      	add	x16, x16, #0x120
     eec:      	br	x17

0000000000000ef0 <open@plt>:
     ef0:      	adrp	x16, 0x5000
     ef4:      	ldr	x17, [x16, #0x128]
     ef8:      	add	x16, x16, #0x128
     efc:      	br	x17

0000000000000f00 <close@plt>:
     f00:      	adrp	x16, 0x5000
     f04:      	ldr	x17, [x16, #0x130]
     f08:      	add	x16, x16, #0x130
     f0c:      	br	x17
