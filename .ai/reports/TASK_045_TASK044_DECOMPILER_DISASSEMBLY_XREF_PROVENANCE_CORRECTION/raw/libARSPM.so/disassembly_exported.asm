// EXPORTED & PLT DISASSEMBLY FOR libARSPM.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libARSPM.so (SHA-256: EC420F2EEC97CF2DEBBF4778045CFD0AC08B78EAE656A4F90E282D49B3EF0114)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 56, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libARSPM.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000004f09a0 <.plt>:
  4f09a0:      	stp	x16, x30, [sp, #-0x10]!
  4f09a4:      	adrp	x16, 0x50e000
  4f09a8:      	ldr	x17, [x16, #0xf30]
  4f09ac:      	add	x16, x16, #0xf30
  4f09b0:      	br	x17
  4f09b4:      	nop
  4f09b8:      	nop
  4f09bc:      	nop

00000000004f09c0 <__cxa_finalize@plt>:
  4f09c0:      	adrp	x16, 0x50e000
  4f09c4:      	ldr	x17, [x16, #0xf38]
  4f09c8:      	add	x16, x16, #0xf38
  4f09cc:      	br	x17

00000000004f09d0 <__cxa_atexit@plt>:
  4f09d0:      	adrp	x16, 0x50e000
  4f09d4:      	ldr	x17, [x16, #0xf40]
  4f09d8:      	add	x16, x16, #0xf40
  4f09dc:      	br	x17

00000000004f09e0 <__register_atfork@plt>:
  4f09e0:      	adrp	x16, 0x50e000
  4f09e4:      	ldr	x17, [x16, #0xf48]
  4f09e8:      	add	x16, x16, #0xf48
  4f09ec:      	br	x17

00000000004f09f0 <_Znwm@plt>:
  4f09f0:      	adrp	x16, 0x50e000
  4f09f4:      	ldr	x17, [x16, #0xf50]
  4f09f8:      	add	x16, x16, #0xf50
  4f09fc:      	br	x17

00000000004f0a00 <_ZdlPv@plt>:
  4f0a00:      	adrp	x16, 0x50e000
  4f0a04:      	ldr	x17, [x16, #0xf58]
  4f0a08:      	add	x16, x16, #0xf58
  4f0a0c:      	br	x17

00000000004f0a10 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  4f0a10:      	adrp	x16, 0x50e000
  4f0a14:      	ldr	x17, [x16, #0xf60]
  4f0a18:      	add	x16, x16, #0xf60
  4f0a1c:      	br	x17

00000000004f0a20 <__stack_chk_fail@plt>:
  4f0a20:      	adrp	x16, 0x50e000
  4f0a24:      	ldr	x17, [x16, #0xf68]
  4f0a28:      	add	x16, x16, #0xf68
  4f0a2c:      	br	x17

00000000004f0a30 <strlen@plt>:
  4f0a30:      	adrp	x16, 0x50e000
  4f0a34:      	ldr	x17, [x16, #0xf70]
  4f0a38:      	add	x16, x16, #0xf70
  4f0a3c:      	br	x17

00000000004f0a40 <memmove@plt>:
  4f0a40:      	adrp	x16, 0x50e000
  4f0a44:      	ldr	x17, [x16, #0xf78]
  4f0a48:      	add	x16, x16, #0xf78
  4f0a4c:      	br	x17

00000000004f0a50 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  4f0a50:      	adrp	x16, 0x50e000
  4f0a54:      	ldr	x17, [x16, #0xf80]
  4f0a58:      	add	x16, x16, #0xf80
  4f0a5c:      	br	x17

00000000004f0a60 <printf@plt>:
  4f0a60:      	adrp	x16, 0x50e000
  4f0a64:      	ldr	x17, [x16, #0xf88]
  4f0a68:      	add	x16, x16, #0xf88
  4f0a6c:      	br	x17

00000000004f0a70 <free@plt>:
  4f0a70:      	adrp	x16, 0x50e000
  4f0a74:      	ldr	x17, [x16, #0xf90]
  4f0a78:      	add	x16, x16, #0xf90
  4f0a7c:      	br	x17

00000000004f0a80 <_Znam@plt>:
  4f0a80:      	adrp	x16, 0x50e000
  4f0a84:      	ldr	x17, [x16, #0xf98]
  4f0a88:      	add	x16, x16, #0xf98
  4f0a8c:      	br	x17

00000000004f0a90 <puts@plt>:
  4f0a90:      	adrp	x16, 0x50e000
  4f0a94:      	ldr	x17, [x16, #0xfa0]
  4f0a98:      	add	x16, x16, #0xfa0
  4f0a9c:      	br	x17

00000000004f0aa0 <malloc@plt>:
  4f0aa0:      	adrp	x16, 0x50e000
  4f0aa4:      	ldr	x17, [x16, #0xfa8]
  4f0aa8:      	add	x16, x16, #0xfa8
  4f0aac:      	br	x17

00000000004f0ab0 <memcpy@plt>:
  4f0ab0:      	adrp	x16, 0x50e000
  4f0ab4:      	ldr	x17, [x16, #0xfb0]
  4f0ab8:      	add	x16, x16, #0xfb0
  4f0abc:      	br	x17

00000000004f0ac0 <__cxa_begin_catch@plt>:
  4f0ac0:      	adrp	x16, 0x50e000
  4f0ac4:      	ldr	x17, [x16, #0xfb8]
  4f0ac8:      	add	x16, x16, #0xfb8
  4f0acc:      	br	x17

00000000004f0ad0 <_ZSt9terminatev@plt>:
  4f0ad0:      	adrp	x16, 0x50e000
  4f0ad4:      	ldr	x17, [x16, #0xfc0]
  4f0ad8:      	add	x16, x16, #0xfc0
  4f0adc:      	br	x17

00000000004f0ae0 <__cxa_allocate_exception@plt>:
  4f0ae0:      	adrp	x16, 0x50e000
  4f0ae4:      	ldr	x17, [x16, #0xfc8]
  4f0ae8:      	add	x16, x16, #0xfc8
  4f0aec:      	br	x17

00000000004f0af0 <__cxa_throw@plt>:
  4f0af0:      	adrp	x16, 0x50e000
  4f0af4:      	ldr	x17, [x16, #0xfd0]
  4f0af8:      	add	x16, x16, #0xfd0
  4f0afc:      	br	x17

00000000004f0b00 <__cxa_free_exception@plt>:
  4f0b00:      	adrp	x16, 0x50e000
  4f0b04:      	ldr	x17, [x16, #0xfd8]
  4f0b08:      	add	x16, x16, #0xfd8
  4f0b0c:      	br	x17

00000000004f0b10 <_ZNSt11logic_errorC2EPKc@plt>:
  4f0b10:      	adrp	x16, 0x50e000
  4f0b14:      	ldr	x17, [x16, #0xfe0]
  4f0b18:      	add	x16, x16, #0xfe0
  4f0b1c:      	br	x17

00000000004f0b20 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  4f0b20:      	adrp	x16, 0x50e000
  4f0b24:      	ldr	x17, [x16, #0xfe8]
  4f0b28:      	add	x16, x16, #0xfe8
  4f0b2c:      	br	x17

00000000004f0b30 <memset@plt>:
  4f0b30:      	adrp	x16, 0x50e000
  4f0b34:      	ldr	x17, [x16, #0xff0]
  4f0b38:      	add	x16, x16, #0xff0
  4f0b3c:      	br	x17

00000000004f0b40 <__cxa_end_catch@plt>:
  4f0b40:      	adrp	x16, 0x50e000
  4f0b44:      	ldr	x17, [x16, #0xff8]
  4f0b48:      	add	x16, x16, #0xff8
  4f0b4c:      	br	x17

00000000004f0b50 <_ZdaPv@plt>:
  4f0b50:      	adrp	x16, 0x50f000
  4f0b54:      	ldr	x17, [x16]
  4f0b58:      	add	x16, x16, #0x0
  4f0b5c:      	br	x17

00000000004f0b60 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  4f0b60:      	adrp	x16, 0x50f000
  4f0b64:      	ldr	x17, [x16, #0x8]
  4f0b68:      	add	x16, x16, #0x8
  4f0b6c:      	br	x17

00000000004f0b70 <__android_log_vprint@plt>:
  4f0b70:      	adrp	x16, 0x50f000
  4f0b74:      	ldr	x17, [x16, #0x10]
  4f0b78:      	add	x16, x16, #0x10
  4f0b7c:      	br	x17

00000000004f0b80 <inflateReset@plt>:
  4f0b80:      	adrp	x16, 0x50f000
  4f0b84:      	ldr	x17, [x16, #0x18]
  4f0b88:      	add	x16, x16, #0x18
  4f0b8c:      	br	x17

00000000004f0b90 <adler32@plt>:
  4f0b90:      	adrp	x16, 0x50f000
  4f0b94:      	ldr	x17, [x16, #0x20]
  4f0b98:      	add	x16, x16, #0x20
  4f0b9c:      	br	x17

00000000004f0ba0 <inflateEnd@plt>:
  4f0ba0:      	adrp	x16, 0x50f000
  4f0ba4:      	ldr	x17, [x16, #0x28]
  4f0ba8:      	add	x16, x16, #0x28
  4f0bac:      	br	x17

00000000004f0bb0 <crc32@plt>:
  4f0bb0:      	adrp	x16, 0x50f000
  4f0bb4:      	ldr	x17, [x16, #0x30]
  4f0bb8:      	add	x16, x16, #0x30
  4f0bbc:      	br	x17

00000000004f0bc0 <inflateReset2@plt>:
  4f0bc0:      	adrp	x16, 0x50f000
  4f0bc4:      	ldr	x17, [x16, #0x38]
  4f0bc8:      	add	x16, x16, #0x38
  4f0bcc:      	br	x17

00000000004f0bd0 <inflate@plt>:
  4f0bd0:      	adrp	x16, 0x50f000
  4f0bd4:      	ldr	x17, [x16, #0x40]
  4f0bd8:      	add	x16, x16, #0x40
  4f0bdc:      	br	x17

00000000004f0be0 <inflateInit2_@plt>:
  4f0be0:      	adrp	x16, 0x50f000
  4f0be4:      	ldr	x17, [x16, #0x48]
  4f0be8:      	add	x16, x16, #0x48
  4f0bec:      	br	x17

00000000004f0bf0 <malloc_usable_size@plt>:
  4f0bf0:      	adrp	x16, 0x50f000
  4f0bf4:      	ldr	x17, [x16, #0x50]
  4f0bf8:      	add	x16, x16, #0x50
  4f0bfc:      	br	x17

00000000004f0c00 <sem_destroy@plt>:
  4f0c00:      	adrp	x16, 0x50f000
  4f0c04:      	ldr	x17, [x16, #0x58]
  4f0c08:      	add	x16, x16, #0x58
  4f0c0c:      	br	x17

00000000004f0c10 <sem_init@plt>:
  4f0c10:      	adrp	x16, 0x50f000
  4f0c14:      	ldr	x17, [x16, #0x60]
  4f0c18:      	add	x16, x16, #0x60
  4f0c1c:      	br	x17

00000000004f0c20 <sem_post@plt>:
  4f0c20:      	adrp	x16, 0x50f000
  4f0c24:      	ldr	x17, [x16, #0x68]
  4f0c28:      	add	x16, x16, #0x68
  4f0c2c:      	br	x17

00000000004f0c30 <sem_wait@plt>:
  4f0c30:      	adrp	x16, 0x50f000
  4f0c34:      	ldr	x17, [x16, #0x70]
  4f0c38:      	add	x16, x16, #0x70
  4f0c3c:      	br	x17

00000000004f0c40 <__errno@plt>:
  4f0c40:      	adrp	x16, 0x50f000
  4f0c44:      	ldr	x17, [x16, #0x78]
  4f0c48:      	add	x16, x16, #0x78
  4f0c4c:      	br	x17

00000000004f0c50 <abort@plt>:
  4f0c50:      	adrp	x16, 0x50f000
  4f0c54:      	ldr	x17, [x16, #0x80]
  4f0c58:      	add	x16, x16, #0x80
  4f0c5c:      	br	x17

00000000004f0c60 <__cxa_guard_acquire@plt>:
  4f0c60:      	adrp	x16, 0x50f000
  4f0c64:      	ldr	x17, [x16, #0x88]
  4f0c68:      	add	x16, x16, #0x88
  4f0c6c:      	br	x17

00000000004f0c70 <__cxa_guard_release@plt>:
  4f0c70:      	adrp	x16, 0x50f000
  4f0c74:      	ldr	x17, [x16, #0x90]
  4f0c78:      	add	x16, x16, #0x90
  4f0c7c:      	br	x17

00000000004f0c80 <memcmp@plt>:
  4f0c80:      	adrp	x16, 0x50f000
  4f0c84:      	ldr	x17, [x16, #0x98]
  4f0c88:      	add	x16, x16, #0x98
  4f0c8c:      	br	x17

00000000004f0c90 <strcmp@plt>:
  4f0c90:      	adrp	x16, 0x50f000
  4f0c94:      	ldr	x17, [x16, #0xa0]
  4f0c98:      	add	x16, x16, #0xa0
  4f0c9c:      	br	x17

00000000004f0ca0 <acos@plt>:
  4f0ca0:      	adrp	x16, 0x50f000
  4f0ca4:      	ldr	x17, [x16, #0xa8]
  4f0ca8:      	add	x16, x16, #0xa8
  4f0cac:      	br	x17

00000000004f0cb0 <cos@plt>:
  4f0cb0:      	adrp	x16, 0x50f000
  4f0cb4:      	ldr	x17, [x16, #0xb0]
  4f0cb8:      	add	x16, x16, #0xb0
  4f0cbc:      	br	x17

00000000004f0cc0 <cbrt@plt>:
  4f0cc0:      	adrp	x16, 0x50f000
  4f0cc4:      	ldr	x17, [x16, #0xb8]
  4f0cc8:      	add	x16, x16, #0xb8
  4f0ccc:      	br	x17

00000000004f0cd0 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
  4f0cd0:      	adrp	x16, 0x50f000
  4f0cd4:      	ldr	x17, [x16, #0xc0]
  4f0cd8:      	add	x16, x16, #0xc0
  4f0cdc:      	br	x17

00000000004f0ce0 <sincosf@plt>:
  4f0ce0:      	adrp	x16, 0x50f000
  4f0ce4:      	ldr	x17, [x16, #0xc8]
  4f0ce8:      	add	x16, x16, #0xc8
  4f0cec:      	br	x17

00000000004f0cf0 <tanf@plt>:
  4f0cf0:      	adrp	x16, 0x50f000
  4f0cf4:      	ldr	x17, [x16, #0xd0]
  4f0cf8:      	add	x16, x16, #0xd0
  4f0cfc:      	br	x17

00000000004f0d00 <expf@plt>:
  4f0d00:      	adrp	x16, 0x50f000
  4f0d04:      	ldr	x17, [x16, #0xd8]
  4f0d08:      	add	x16, x16, #0xd8
  4f0d0c:      	br	x17

00000000004f0d10 <exp@plt>:
  4f0d10:      	adrp	x16, 0x50f000
  4f0d14:      	ldr	x17, [x16, #0xe0]
  4f0d18:      	add	x16, x16, #0xe0
  4f0d1c:      	br	x17

00000000004f0d20 <_ZNSt6__ndk16locale7classicEv@plt>:
  4f0d20:      	adrp	x16, 0x50f000
  4f0d24:      	ldr	x17, [x16, #0xe8]
  4f0d28:      	add	x16, x16, #0xe8
  4f0d2c:      	br	x17

00000000004f0d30 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  4f0d30:      	adrp	x16, 0x50f000
  4f0d34:      	ldr	x17, [x16, #0xf0]
  4f0d38:      	add	x16, x16, #0xf0
  4f0d3c:      	br	x17

00000000004f0d40 <fmodf@plt>:
  4f0d40:      	adrp	x16, 0x50f000
  4f0d44:      	ldr	x17, [x16, #0xf8]
  4f0d48:      	add	x16, x16, #0xf8
  4f0d4c:      	br	x17

00000000004f0d50 <atan2f@plt>:
  4f0d50:      	adrp	x16, 0x50f000
  4f0d54:      	ldr	x17, [x16, #0x100]
  4f0d58:      	add	x16, x16, #0x100
  4f0d5c:      	br	x17

00000000004f0d60 <cosf@plt>:
  4f0d60:      	adrp	x16, 0x50f000
  4f0d64:      	ldr	x17, [x16, #0x108]
  4f0d68:      	add	x16, x16, #0x108
  4f0d6c:      	br	x17

00000000004f0d70 <acosf@plt>:
  4f0d70:      	adrp	x16, 0x50f000
  4f0d74:      	ldr	x17, [x16, #0x110]
  4f0d78:      	add	x16, x16, #0x110
  4f0d7c:      	br	x17

00000000004f0d80 <powf@plt>:
  4f0d80:      	adrp	x16, 0x50f000
  4f0d84:      	ldr	x17, [x16, #0x118]
  4f0d88:      	add	x16, x16, #0x118
  4f0d8c:      	br	x17

00000000004f0d90 <logf@plt>:
  4f0d90:      	adrp	x16, 0x50f000
  4f0d94:      	ldr	x17, [x16, #0x120]
  4f0d98:      	add	x16, x16, #0x120
  4f0d9c:      	br	x17

00000000004f0da0 <nextafterf@plt>:
  4f0da0:      	adrp	x16, 0x50f000
  4f0da4:      	ldr	x17, [x16, #0x128]
  4f0da8:      	add	x16, x16, #0x128
  4f0dac:      	br	x17

00000000004f0db0 <__emutls_get_address@plt>:
  4f0db0:      	adrp	x16, 0x50f000
  4f0db4:      	ldr	x17, [x16, #0x130]
  4f0db8:      	add	x16, x16, #0x130
  4f0dbc:      	br	x17

00000000004f0dc0 <strncmp@plt>:
  4f0dc0:      	adrp	x16, 0x50f000
  4f0dc4:      	ldr	x17, [x16, #0x138]
  4f0dc8:      	add	x16, x16, #0x138
  4f0dcc:      	br	x17

00000000004f0dd0 <snprintf@plt>:
  4f0dd0:      	adrp	x16, 0x50f000
  4f0dd4:      	ldr	x17, [x16, #0x140]
  4f0dd8:      	add	x16, x16, #0x140
  4f0ddc:      	br	x17

00000000004f0de0 <vsnprintf@plt>:
  4f0de0:      	adrp	x16, 0x50f000
  4f0de4:      	ldr	x17, [x16, #0x148]
  4f0de8:      	add	x16, x16, #0x148
  4f0dec:      	br	x17

00000000004f0df0 <strstr@plt>:
  4f0df0:      	adrp	x16, 0x50f000
  4f0df4:      	ldr	x17, [x16, #0x150]
  4f0df8:      	add	x16, x16, #0x150
  4f0dfc:      	br	x17

00000000004f0e00 <strchr@plt>:
  4f0e00:      	adrp	x16, 0x50f000
  4f0e04:      	ldr	x17, [x16, #0x158]
  4f0e08:      	add	x16, x16, #0x158
  4f0e0c:      	br	x17

00000000004f0e10 <strspn@plt>:
  4f0e10:      	adrp	x16, 0x50f000
  4f0e14:      	ldr	x17, [x16, #0x160]
  4f0e18:      	add	x16, x16, #0x160
  4f0e1c:      	br	x17

00000000004f0e20 <strcspn@plt>:
  4f0e20:      	adrp	x16, 0x50f000
  4f0e24:      	ldr	x17, [x16, #0x168]
  4f0e28:      	add	x16, x16, #0x168
  4f0e2c:      	br	x17

00000000004f0e30 <log2f@plt>:
  4f0e30:      	adrp	x16, 0x50f000
  4f0e34:      	ldr	x17, [x16, #0x170]
  4f0e38:      	add	x16, x16, #0x170
  4f0e3c:      	br	x17

00000000004f0e40 <_ZNSt6__ndk112__next_primeEm@plt>:
  4f0e40:      	adrp	x16, 0x50f000
  4f0e44:      	ldr	x17, [x16, #0x178]
  4f0e48:      	add	x16, x16, #0x178
  4f0e4c:      	br	x17

00000000004f0e50 <strtod@plt>:
  4f0e50:      	adrp	x16, 0x50f000
  4f0e54:      	ldr	x17, [x16, #0x180]
  4f0e58:      	add	x16, x16, #0x180
  4f0e5c:      	br	x17

00000000004f0e60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  4f0e60:      	adrp	x16, 0x50f000
  4f0e64:      	ldr	x17, [x16, #0x188]
  4f0e68:      	add	x16, x16, #0x188
  4f0e6c:      	br	x17

00000000004f0e70 <cbrtf@plt>:
  4f0e70:      	adrp	x16, 0x50f000
  4f0e74:      	ldr	x17, [x16, #0x190]
  4f0e78:      	add	x16, x16, #0x190
  4f0e7c:      	br	x17

00000000004f0e80 <fmod@plt>:
  4f0e80:      	adrp	x16, 0x50f000
  4f0e84:      	ldr	x17, [x16, #0x198]
  4f0e88:      	add	x16, x16, #0x198
  4f0e8c:      	br	x17

00000000004f0e90 <erff@plt>:
  4f0e90:      	adrp	x16, 0x50f000
  4f0e94:      	ldr	x17, [x16, #0x1a0]
  4f0e98:      	add	x16, x16, #0x1a0
  4f0e9c:      	br	x17

00000000004f0ea0 <realloc@plt>:
  4f0ea0:      	adrp	x16, 0x50f000
  4f0ea4:      	ldr	x17, [x16, #0x1a8]
  4f0ea8:      	add	x16, x16, #0x1a8
  4f0eac:      	br	x17

00000000004f0eb0 <calloc@plt>:
  4f0eb0:      	adrp	x16, 0x50f000
  4f0eb4:      	ldr	x17, [x16, #0x1b0]
  4f0eb8:      	add	x16, x16, #0x1b0
  4f0ebc:      	br	x17

00000000004f0ec0 <fopen@plt>:
  4f0ec0:      	adrp	x16, 0x50f000
  4f0ec4:      	ldr	x17, [x16, #0x1b8]
  4f0ec8:      	add	x16, x16, #0x1b8
  4f0ecc:      	br	x17

00000000004f0ed0 <fwrite@plt>:
  4f0ed0:      	adrp	x16, 0x50f000
  4f0ed4:      	ldr	x17, [x16, #0x1c0]
  4f0ed8:      	add	x16, x16, #0x1c0
  4f0edc:      	br	x17

00000000004f0ee0 <fflush@plt>:
  4f0ee0:      	adrp	x16, 0x50f000
  4f0ee4:      	ldr	x17, [x16, #0x1c8]
  4f0ee8:      	add	x16, x16, #0x1c8
  4f0eec:      	br	x17

00000000004f0ef0 <fclose@plt>:
  4f0ef0:      	adrp	x16, 0x50f000
  4f0ef4:      	ldr	x17, [x16, #0x1d0]
  4f0ef8:      	add	x16, x16, #0x1d0
  4f0efc:      	br	x17

00000000004f0f00 <stat@plt>:
  4f0f00:      	adrp	x16, 0x50f000
  4f0f04:      	ldr	x17, [x16, #0x1d8]
  4f0f08:      	add	x16, x16, #0x1d8
  4f0f0c:      	br	x17

00000000004f0f10 <fprintf@plt>:
  4f0f10:      	adrp	x16, 0x50f000
  4f0f14:      	ldr	x17, [x16, #0x1e0]
  4f0f18:      	add	x16, x16, #0x1e0
  4f0f1c:      	br	x17

00000000004f0f20 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
  4f0f20:      	adrp	x16, 0x50f000
  4f0f24:      	ldr	x17, [x16, #0x1e8]
  4f0f28:      	add	x16, x16, #0x1e8
  4f0f2c:      	br	x17

00000000004f0f30 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  4f0f30:      	adrp	x16, 0x50f000
  4f0f34:      	ldr	x17, [x16, #0x1f0]
  4f0f38:      	add	x16, x16, #0x1f0
  4f0f3c:      	br	x17

00000000004f0f40 <_ZNSt6__ndk19to_stringEi@plt>:
  4f0f40:      	adrp	x16, 0x50f000
  4f0f44:      	ldr	x17, [x16, #0x1f8]
  4f0f48:      	add	x16, x16, #0x1f8
  4f0f4c:      	br	x17

00000000004f0f50 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
  4f0f50:      	adrp	x16, 0x50f000
  4f0f54:      	ldr	x17, [x16, #0x200]
  4f0f58:      	add	x16, x16, #0x200
  4f0f5c:      	br	x17

00000000004f0f60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  4f0f60:      	adrp	x16, 0x50f000
  4f0f64:      	ldr	x17, [x16, #0x208]
  4f0f68:      	add	x16, x16, #0x208
  4f0f6c:      	br	x17

00000000004f0f70 <memchr@plt>:
  4f0f70:      	adrp	x16, 0x50f000
  4f0f74:      	ldr	x17, [x16, #0x210]
  4f0f78:      	add	x16, x16, #0x210
  4f0f7c:      	br	x17

00000000004f0f80 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  4f0f80:      	adrp	x16, 0x50f000
  4f0f84:      	ldr	x17, [x16, #0x218]
  4f0f88:      	add	x16, x16, #0x218
  4f0f8c:      	br	x17

00000000004f0f90 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  4f0f90:      	adrp	x16, 0x50f000
  4f0f94:      	ldr	x17, [x16, #0x220]
  4f0f98:      	add	x16, x16, #0x220
  4f0f9c:      	br	x17

00000000004f0fa0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  4f0fa0:      	adrp	x16, 0x50f000
  4f0fa4:      	ldr	x17, [x16, #0x228]
  4f0fa8:      	add	x16, x16, #0x228
  4f0fac:      	br	x17

00000000004f0fb0 <_ZNSt6__ndk18ios_base5imbueERKNS_6localeE@plt>:
  4f0fb0:      	adrp	x16, 0x50f000
  4f0fb4:      	ldr	x17, [x16, #0x230]
  4f0fb8:      	add	x16, x16, #0x230
  4f0fbc:      	br	x17

00000000004f0fc0 <_ZNSt6__ndk16localeD1Ev@plt>:
  4f0fc0:      	adrp	x16, 0x50f000
  4f0fc4:      	ldr	x17, [x16, #0x238]
  4f0fc8:      	add	x16, x16, #0x238
  4f0fcc:      	br	x17

00000000004f0fd0 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
  4f0fd0:      	adrp	x16, 0x50f000
  4f0fd4:      	ldr	x17, [x16, #0x240]
  4f0fd8:      	add	x16, x16, #0x240
  4f0fdc:      	br	x17

00000000004f0fe0 <_ZNSt6__ndk16localeaSERKS0_@plt>:
  4f0fe0:      	adrp	x16, 0x50f000
  4f0fe4:      	ldr	x17, [x16, #0x248]
  4f0fe8:      	add	x16, x16, #0x248
  4f0fec:      	br	x17

00000000004f0ff0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf@plt>:
  4f0ff0:      	adrp	x16, 0x50f000
  4f0ff4:      	ldr	x17, [x16, #0x250]
  4f0ff8:      	add	x16, x16, #0x250
  4f0ffc:      	br	x17

00000000004f1000 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
  4f1000:      	adrp	x16, 0x50f000
  4f1004:      	ldr	x17, [x16, #0x258]
  4f1008:      	add	x16, x16, #0x258
  4f100c:      	br	x17

00000000004f1010 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERd@plt>:
  4f1010:      	adrp	x16, 0x50f000
  4f1014:      	ldr	x17, [x16, #0x260]
  4f1018:      	add	x16, x16, #0x260
  4f101c:      	br	x17

00000000004f1020 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  4f1020:      	adrp	x16, 0x50f000
  4f1024:      	ldr	x17, [x16, #0x268]
  4f1028:      	add	x16, x16, #0x268
  4f102c:      	br	x17

00000000004f1030 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
  4f1030:      	adrp	x16, 0x50f000
  4f1034:      	ldr	x17, [x16, #0x270]
  4f1038:      	add	x16, x16, #0x270
  4f103c:      	br	x17

00000000004f1040 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  4f1040:      	adrp	x16, 0x50f000
  4f1044:      	ldr	x17, [x16, #0x278]
  4f1048:      	add	x16, x16, #0x278
  4f104c:      	br	x17

00000000004f1050 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  4f1050:      	adrp	x16, 0x50f000
  4f1054:      	ldr	x17, [x16, #0x280]
  4f1058:      	add	x16, x16, #0x280
  4f105c:      	br	x17

00000000004f1060 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf@plt>:
  4f1060:      	adrp	x16, 0x50f000
  4f1064:      	ldr	x17, [x16, #0x288]
  4f1068:      	add	x16, x16, #0x288
  4f106c:      	br	x17

00000000004f1070 <strtoull@plt>:
  4f1070:      	adrp	x16, 0x50f000
  4f1074:      	ldr	x17, [x16, #0x290]
  4f1078:      	add	x16, x16, #0x290
  4f107c:      	br	x17

00000000004f1080 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  4f1080:      	adrp	x16, 0x50f000
  4f1084:      	ldr	x17, [x16, #0x298]
  4f1088:      	add	x16, x16, #0x298
  4f108c:      	br	x17

00000000004f1090 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
  4f1090:      	adrp	x16, 0x50f000
  4f1094:      	ldr	x17, [x16, #0x2a0]
  4f1098:      	add	x16, x16, #0x2a0
  4f109c:      	br	x17

00000000004f10a0 <_ZNSt6__ndk19to_stringEm@plt>:
  4f10a0:      	adrp	x16, 0x50f000
  4f10a4:      	ldr	x17, [x16, #0x2a8]
  4f10a8:      	add	x16, x16, #0x2a8
  4f10ac:      	br	x17

00000000004f10b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
  4f10b0:      	adrp	x16, 0x50f000
  4f10b4:      	ldr	x17, [x16, #0x2b0]
  4f10b8:      	add	x16, x16, #0x2b0
  4f10bc:      	br	x17

00000000004f10c0 <remainder@plt>:
  4f10c0:      	adrp	x16, 0x50f000
  4f10c4:      	ldr	x17, [x16, #0x2b8]
  4f10c8:      	add	x16, x16, #0x2b8
  4f10cc:      	br	x17

00000000004f10d0 <sin@plt>:
  4f10d0:      	adrp	x16, 0x50f000
  4f10d4:      	ldr	x17, [x16, #0x2c0]
  4f10d8:      	add	x16, x16, #0x2c0
  4f10dc:      	br	x17

00000000004f10e0 <tan@plt>:
  4f10e0:      	adrp	x16, 0x50f000
  4f10e4:      	ldr	x17, [x16, #0x2c8]
  4f10e8:      	add	x16, x16, #0x2c8
  4f10ec:      	br	x17

00000000004f10f0 <sinh@plt>:
  4f10f0:      	adrp	x16, 0x50f000
  4f10f4:      	ldr	x17, [x16, #0x2d0]
  4f10f8:      	add	x16, x16, #0x2d0
  4f10fc:      	br	x17

00000000004f1100 <cosh@plt>:
  4f1100:      	adrp	x16, 0x50f000
  4f1104:      	ldr	x17, [x16, #0x2d8]
  4f1108:      	add	x16, x16, #0x2d8
  4f110c:      	br	x17

00000000004f1110 <tanh@plt>:
  4f1110:      	adrp	x16, 0x50f000
  4f1114:      	ldr	x17, [x16, #0x2e0]
  4f1118:      	add	x16, x16, #0x2e0
  4f111c:      	br	x17

00000000004f1120 <asin@plt>:
  4f1120:      	adrp	x16, 0x50f000
  4f1124:      	ldr	x17, [x16, #0x2e8]
  4f1128:      	add	x16, x16, #0x2e8
  4f112c:      	br	x17

00000000004f1130 <atan@plt>:
  4f1130:      	adrp	x16, 0x50f000
  4f1134:      	ldr	x17, [x16, #0x2f0]
  4f1138:      	add	x16, x16, #0x2f0
  4f113c:      	br	x17

00000000004f1140 <atan2@plt>:
  4f1140:      	adrp	x16, 0x50f000
  4f1144:      	ldr	x17, [x16, #0x2f8]
  4f1148:      	add	x16, x16, #0x2f8
  4f114c:      	br	x17

00000000004f1150 <asinh@plt>:
  4f1150:      	adrp	x16, 0x50f000
  4f1154:      	ldr	x17, [x16, #0x300]
  4f1158:      	add	x16, x16, #0x300
  4f115c:      	br	x17

00000000004f1160 <acosh@plt>:
  4f1160:      	adrp	x16, 0x50f000
  4f1164:      	ldr	x17, [x16, #0x308]
  4f1168:      	add	x16, x16, #0x308
  4f116c:      	br	x17

00000000004f1170 <atanh@plt>:
  4f1170:      	adrp	x16, 0x50f000
  4f1174:      	ldr	x17, [x16, #0x310]
  4f1178:      	add	x16, x16, #0x310
  4f117c:      	br	x17

00000000004f1180 <pow@plt>:
  4f1180:      	adrp	x16, 0x50f000
  4f1184:      	ldr	x17, [x16, #0x318]
  4f1188:      	add	x16, x16, #0x318
  4f118c:      	br	x17

00000000004f1190 <log@plt>:
  4f1190:      	adrp	x16, 0x50f000
  4f1194:      	ldr	x17, [x16, #0x320]
  4f1198:      	add	x16, x16, #0x320
  4f119c:      	br	x17

00000000004f11a0 <exp2@plt>:
  4f11a0:      	adrp	x16, 0x50f000
  4f11a4:      	ldr	x17, [x16, #0x328]
  4f11a8:      	add	x16, x16, #0x328
  4f11ac:      	br	x17

00000000004f11b0 <log2@plt>:
  4f11b0:      	adrp	x16, 0x50f000
  4f11b4:      	ldr	x17, [x16, #0x330]
  4f11b8:      	add	x16, x16, #0x330
  4f11bc:      	br	x17

00000000004f11c0 <_ZNSt6__ndk19to_stringEl@plt>:
  4f11c0:      	adrp	x16, 0x50f000
  4f11c4:      	ldr	x17, [x16, #0x338]
  4f11c8:      	add	x16, x16, #0x338
  4f11cc:      	br	x17

00000000004f11d0 <strcpy@plt>:
  4f11d0:      	adrp	x16, 0x50f000
  4f11d4:      	ldr	x17, [x16, #0x340]
  4f11d8:      	add	x16, x16, #0x340
  4f11dc:      	br	x17

00000000004f11e0 <fileno@plt>:
  4f11e0:      	adrp	x16, 0x50f000
  4f11e4:      	ldr	x17, [x16, #0x348]
  4f11e8:      	add	x16, x16, #0x348
  4f11ec:      	br	x17

00000000004f11f0 <fstat@plt>:
  4f11f0:      	adrp	x16, 0x50f000
  4f11f4:      	ldr	x17, [x16, #0x350]
  4f11f8:      	add	x16, x16, #0x350
  4f11fc:      	br	x17

00000000004f1200 <munmap@plt>:
  4f1200:      	adrp	x16, 0x50f000
  4f1204:      	ldr	x17, [x16, #0x358]
  4f1208:      	add	x16, x16, #0x358
  4f120c:      	br	x17

00000000004f1210 <mmap@plt>:
  4f1210:      	adrp	x16, 0x50f000
  4f1214:      	ldr	x17, [x16, #0x360]
  4f1218:      	add	x16, x16, #0x360
  4f121c:      	br	x17

00000000004f1220 <vprintf@plt>:
  4f1220:      	adrp	x16, 0x50f000
  4f1224:      	ldr	x17, [x16, #0x368]
  4f1228:      	add	x16, x16, #0x368
  4f122c:      	br	x17

00000000004f1230 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
  4f1230:      	adrp	x16, 0x50f000
  4f1234:      	ldr	x17, [x16, #0x370]
  4f1238:      	add	x16, x16, #0x370
  4f123c:      	br	x17

00000000004f1240 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm@plt>:
  4f1240:      	adrp	x16, 0x50f000
  4f1244:      	ldr	x17, [x16, #0x378]
  4f1248:      	add	x16, x16, #0x378
  4f124c:      	br	x17

00000000004f1250 <exp2f@plt>:
  4f1250:      	adrp	x16, 0x50f000
  4f1254:      	ldr	x17, [x16, #0x380]
  4f1258:      	add	x16, x16, #0x380
  4f125c:      	br	x17

00000000004f1260 <ilogbf@plt>:
  4f1260:      	adrp	x16, 0x50f000
  4f1264:      	ldr	x17, [x16, #0x388]
  4f1268:      	add	x16, x16, #0x388
  4f126c:      	br	x17

00000000004f1270 <eglGetProcAddress@plt>:
  4f1270:      	adrp	x16, 0x50f000
  4f1274:      	ldr	x17, [x16, #0x390]
  4f1278:      	add	x16, x16, #0x390
  4f127c:      	br	x17

00000000004f1280 <__system_property_get@plt>:
  4f1280:      	adrp	x16, 0x50f000
  4f1284:      	ldr	x17, [x16, #0x398]
  4f1288:      	add	x16, x16, #0x398
  4f128c:      	br	x17

00000000004f1290 <atoi@plt>:
  4f1290:      	adrp	x16, 0x50f000
  4f1294:      	ldr	x17, [x16, #0x3a0]
  4f1298:      	add	x16, x16, #0x3a0
  4f129c:      	br	x17

00000000004f12a0 <wmemchr@plt>:
  4f12a0:      	adrp	x16, 0x50f000
  4f12a4:      	ldr	x17, [x16, #0x3a8]
  4f12a8:      	add	x16, x16, #0x3a8
  4f12ac:      	br	x17

00000000004f12b0 <sscanf@plt>:
  4f12b0:      	adrp	x16, 0x50f000
  4f12b4:      	ldr	x17, [x16, #0x3b0]
  4f12b8:      	add	x16, x16, #0x3b0
  4f12bc:      	br	x17

00000000004f12c0 <longjmp@plt>:
  4f12c0:      	adrp	x16, 0x50f000
  4f12c4:      	ldr	x17, [x16, #0x3b8]
  4f12c8:      	add	x16, x16, #0x3b8
  4f12cc:      	br	x17

00000000004f12d0 <setjmp@plt>:
  4f12d0:      	adrp	x16, 0x50f000
  4f12d4:      	ldr	x17, [x16, #0x3c0]
  4f12d8:      	add	x16, x16, #0x3c0
  4f12dc:      	br	x17

00000000004f12e0 <_ZNSt6__ndk15alignEmmRPvRm@plt>:
  4f12e0:      	adrp	x16, 0x50f000
  4f12e4:      	ldr	x17, [x16, #0x3c8]
  4f12e8:      	add	x16, x16, #0x3c8
  4f12ec:      	br	x17

00000000004f12f0 <fputc@plt>:
  4f12f0:      	adrp	x16, 0x50f000
  4f12f4:      	ldr	x17, [x16, #0x3d0]
  4f12f8:      	add	x16, x16, #0x3d0
  4f12fc:      	br	x17

00000000004f1300 <fread@plt>:
  4f1300:      	adrp	x16, 0x50f000
  4f1304:      	ldr	x17, [x16, #0x3d8]
  4f1308:      	add	x16, x16, #0x3d8
  4f130c:      	br	x17

00000000004f1310 <strrchr@plt>:
  4f1310:      	adrp	x16, 0x50f000
  4f1314:      	ldr	x17, [x16, #0x3e0]
  4f1318:      	add	x16, x16, #0x3e0
  4f131c:      	br	x17

00000000004f1320 <strtof@plt>:
  4f1320:      	adrp	x16, 0x50f000
  4f1324:      	ldr	x17, [x16, #0x3e8]
  4f1328:      	add	x16, x16, #0x3e8
  4f132c:      	br	x17

00000000004f1330 <atanf@plt>:
  4f1330:      	adrp	x16, 0x50f000
  4f1334:      	ldr	x17, [x16, #0x3f0]
  4f1338:      	add	x16, x16, #0x3f0
  4f133c:      	br	x17

00000000004f1340 <asinf@plt>:
  4f1340:      	adrp	x16, 0x50f000
  4f1344:      	ldr	x17, [x16, #0x3f8]
  4f1348:      	add	x16, x16, #0x3f8
  4f134c:      	br	x17

00000000004f1350 <sinf@plt>:
  4f1350:      	adrp	x16, 0x50f000
  4f1354:      	ldr	x17, [x16, #0x400]
  4f1358:      	add	x16, x16, #0x400
  4f135c:      	br	x17

00000000004f1360 <bsearch@plt>:
  4f1360:      	adrp	x16, 0x50f000
  4f1364:      	ldr	x17, [x16, #0x408]
  4f1368:      	add	x16, x16, #0x408
  4f136c:      	br	x17

00000000004f1370 <getenv@plt>:
  4f1370:      	adrp	x16, 0x50f000
  4f1374:      	ldr	x17, [x16, #0x410]
  4f1378:      	add	x16, x16, #0x410
  4f137c:      	br	x17

00000000004f1380 <strtoul@plt>:
  4f1380:      	adrp	x16, 0x50f000
  4f1384:      	ldr	x17, [x16, #0x418]
  4f1388:      	add	x16, x16, #0x418
  4f138c:      	br	x17

00000000004f1390 <open@plt>:
  4f1390:      	adrp	x16, 0x50f000
  4f1394:      	ldr	x17, [x16, #0x420]
  4f1398:      	add	x16, x16, #0x420
  4f139c:      	br	x17

00000000004f13a0 <read@plt>:
  4f13a0:      	adrp	x16, 0x50f000
  4f13a4:      	ldr	x17, [x16, #0x428]
  4f13a8:      	add	x16, x16, #0x428
  4f13ac:      	br	x17

00000000004f13b0 <close@plt>:
  4f13b0:      	adrp	x16, 0x50f000
  4f13b4:      	ldr	x17, [x16, #0x430]
  4f13b8:      	add	x16, x16, #0x430
  4f13bc:      	br	x17

00000000004f13c0 <gettimeofday@plt>:
  4f13c0:      	adrp	x16, 0x50f000
  4f13c4:      	ldr	x17, [x16, #0x438]
  4f13c8:      	add	x16, x16, #0x438
  4f13cc:      	br	x17

00000000004f13d0 <getpid@plt>:
  4f13d0:      	adrp	x16, 0x50f000
  4f13d4:      	ldr	x17, [x16, #0x440]
  4f13d8:      	add	x16, x16, #0x440
  4f13dc:      	br	x17

00000000004f13e0 <fputs@plt>:
  4f13e0:      	adrp	x16, 0x50f000
  4f13e4:      	ldr	x17, [x16, #0x448]
  4f13e8:      	add	x16, x16, #0x448
  4f13ec:      	br	x17

00000000004f13f0 <getauxval@plt>:
  4f13f0:      	adrp	x16, 0x50f000
  4f13f4:      	ldr	x17, [x16, #0x450]
  4f13f8:      	add	x16, x16, #0x450
  4f13fc:      	br	x17

00000000004f1400 <pthread_rwlock_wrlock@plt>:
  4f1400:      	adrp	x16, 0x50f000
  4f1404:      	ldr	x17, [x16, #0x458]
  4f1408:      	add	x16, x16, #0x458
  4f140c:      	br	x17

00000000004f1410 <pthread_rwlock_unlock@plt>:
  4f1410:      	adrp	x16, 0x50f000
  4f1414:      	ldr	x17, [x16, #0x460]
  4f1418:      	add	x16, x16, #0x460
  4f141c:      	br	x17

00000000004f1420 <dl_iterate_phdr@plt>:
  4f1420:      	adrp	x16, 0x50f000
  4f1424:      	ldr	x17, [x16, #0x468]
  4f1428:      	add	x16, x16, #0x468
  4f142c:      	br	x17

00000000004f1430 <pthread_rwlock_rdlock@plt>:
  4f1430:      	adrp	x16, 0x50f000
  4f1434:      	ldr	x17, [x16, #0x470]
  4f1438:      	add	x16, x16, #0x470
  4f143c:      	br	x17

00000000004f1440 <syscall@plt>:
  4f1440:      	adrp	x16, 0x50f000
  4f1444:      	ldr	x17, [x16, #0x478]
  4f1448:      	add	x16, x16, #0x478
  4f144c:      	br	x17
