// EXPORTED & PLT DISASSEMBLY FOR libfantasy.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfantasy.so (SHA-256: FEFB87A88745A4AA8E8DCC421C7EC46A91A648E7AFEF86A312D1A3776A8C7724)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 197, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfantasy.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000002238a0 <.plt>:
  2238a0:      	stp	x16, x30, [sp, #-0x10]!
  2238a4:      	adrp	x16, 0x283000
  2238a8:      	ldr	x17, [x16, #0x200]
  2238ac:      	add	x16, x16, #0x200
  2238b0:      	br	x17
  2238b4:      	nop
  2238b8:      	nop
  2238bc:      	nop

00000000002238c0 <__cxa_finalize@plt>:
  2238c0:      	adrp	x16, 0x283000
  2238c4:      	ldr	x17, [x16, #0x208]
  2238c8:      	add	x16, x16, #0x208
  2238cc:      	br	x17

00000000002238d0 <__cxa_atexit@plt>:
  2238d0:      	adrp	x16, 0x283000
  2238d4:      	ldr	x17, [x16, #0x210]
  2238d8:      	add	x16, x16, #0x210
  2238dc:      	br	x17

00000000002238e0 <__register_atfork@plt>:
  2238e0:      	adrp	x16, 0x283000
  2238e4:      	ldr	x17, [x16, #0x218]
  2238e8:      	add	x16, x16, #0x218
  2238ec:      	br	x17

00000000002238f0 <_Znwm@plt>:
  2238f0:      	adrp	x16, 0x283000
  2238f4:      	ldr	x17, [x16, #0x220]
  2238f8:      	add	x16, x16, #0x220
  2238fc:      	br	x17

0000000000223900 <__stack_chk_fail@plt>:
  223900:      	adrp	x16, 0x283000
  223904:      	ldr	x17, [x16, #0x228]
  223908:      	add	x16, x16, #0x228
  22390c:      	br	x17

0000000000223910 <__emutls_get_address@plt>:
  223910:      	adrp	x16, 0x283000
  223914:      	ldr	x17, [x16, #0x230]
  223918:      	add	x16, x16, #0x230
  22391c:      	br	x17

0000000000223920 <vsnprintf@plt>:
  223920:      	adrp	x16, 0x283000
  223924:      	ldr	x17, [x16, #0x238]
  223928:      	add	x16, x16, #0x238
  22392c:      	br	x17

0000000000223930 <memcpy@plt>:
  223930:      	adrp	x16, 0x283000
  223934:      	ldr	x17, [x16, #0x240]
  223938:      	add	x16, x16, #0x240
  22393c:      	br	x17

0000000000223940 <_ZdlPv@plt>:
  223940:      	adrp	x16, 0x283000
  223944:      	ldr	x17, [x16, #0x248]
  223948:      	add	x16, x16, #0x248
  22394c:      	br	x17

0000000000223950 <strlen@plt>:
  223950:      	adrp	x16, 0x283000
  223954:      	ldr	x17, [x16, #0x250]
  223958:      	add	x16, x16, #0x250
  22395c:      	br	x17

0000000000223960 <memmove@plt>:
  223960:      	adrp	x16, 0x283000
  223964:      	ldr	x17, [x16, #0x258]
  223968:      	add	x16, x16, #0x258
  22396c:      	br	x17

0000000000223970 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
  223970:      	adrp	x16, 0x283000
  223974:      	ldr	x17, [x16, #0x260]
  223978:      	add	x16, x16, #0x260
  22397c:      	br	x17

0000000000223980 <_ZSt9terminatev@plt>:
  223980:      	adrp	x16, 0x283000
  223984:      	ldr	x17, [x16, #0x268]
  223988:      	add	x16, x16, #0x268
  22398c:      	br	x17

0000000000223990 <__cxa_guard_acquire@plt>:
  223990:      	adrp	x16, 0x283000
  223994:      	ldr	x17, [x16, #0x270]
  223998:      	add	x16, x16, #0x270
  22399c:      	br	x17

00000000002239a0 <__cxa_guard_release@plt>:
  2239a0:      	adrp	x16, 0x283000
  2239a4:      	ldr	x17, [x16, #0x278]
  2239a8:      	add	x16, x16, #0x278
  2239ac:      	br	x17

00000000002239b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
  2239b0:      	adrp	x16, 0x283000
  2239b4:      	ldr	x17, [x16, #0x280]
  2239b8:      	add	x16, x16, #0x280
  2239bc:      	br	x17

00000000002239c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  2239c0:      	adrp	x16, 0x283000
  2239c4:      	ldr	x17, [x16, #0x288]
  2239c8:      	add	x16, x16, #0x288
  2239cc:      	br	x17

00000000002239d0 <free@plt>:
  2239d0:      	adrp	x16, 0x283000
  2239d4:      	ldr	x17, [x16, #0x290]
  2239d8:      	add	x16, x16, #0x290
  2239dc:      	br	x17

00000000002239e0 <_ZdaPv@plt>:
  2239e0:      	adrp	x16, 0x283000
  2239e4:      	ldr	x17, [x16, #0x298]
  2239e8:      	add	x16, x16, #0x298
  2239ec:      	br	x17

00000000002239f0 <memset@plt>:
  2239f0:      	adrp	x16, 0x283000
  2239f4:      	ldr	x17, [x16, #0x2a0]
  2239f8:      	add	x16, x16, #0x2a0
  2239fc:      	br	x17

0000000000223a00 <posix_memalign@plt>:
  223a00:      	adrp	x16, 0x283000
  223a04:      	ldr	x17, [x16, #0x2a8]
  223a08:      	add	x16, x16, #0x2a8
  223a0c:      	br	x17

0000000000223a10 <memcmp@plt>:
  223a10:      	adrp	x16, 0x283000
  223a14:      	ldr	x17, [x16, #0x2b0]
  223a18:      	add	x16, x16, #0x2b0
  223a1c:      	br	x17

0000000000223a20 <log2@plt>:
  223a20:      	adrp	x16, 0x283000
  223a24:      	ldr	x17, [x16, #0x2b8]
  223a28:      	add	x16, x16, #0x2b8
  223a2c:      	br	x17

0000000000223a30 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv@plt>:
  223a30:      	adrp	x16, 0x283000
  223a34:      	ldr	x17, [x16, #0x2c0]
  223a38:      	add	x16, x16, #0x2c0
  223a3c:      	br	x17

0000000000223a40 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
  223a40:      	adrp	x16, 0x283000
  223a44:      	ldr	x17, [x16, #0x2c8]
  223a48:      	add	x16, x16, #0x2c8
  223a4c:      	br	x17

0000000000223a50 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
  223a50:      	adrp	x16, 0x283000
  223a54:      	ldr	x17, [x16, #0x2d0]
  223a58:      	add	x16, x16, #0x2d0
  223a5c:      	br	x17

0000000000223a60 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
  223a60:      	adrp	x16, 0x283000
  223a64:      	ldr	x17, [x16, #0x2d8]
  223a68:      	add	x16, x16, #0x2d8
  223a6c:      	br	x17

0000000000223a70 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  223a70:      	adrp	x16, 0x283000
  223a74:      	ldr	x17, [x16, #0x2e0]
  223a78:      	add	x16, x16, #0x2e0
  223a7c:      	br	x17

0000000000223a80 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  223a80:      	adrp	x16, 0x283000
  223a84:      	ldr	x17, [x16, #0x2e8]
  223a88:      	add	x16, x16, #0x2e8
  223a8c:      	br	x17

0000000000223a90 <_ZNSt6__ndk15mutex4lockEv@plt>:
  223a90:      	adrp	x16, 0x283000
  223a94:      	ldr	x17, [x16, #0x2f0]
  223a98:      	add	x16, x16, #0x2f0
  223a9c:      	br	x17

0000000000223aa0 <_ZNSt6__ndk15mutex6unlockEv@plt>:
  223aa0:      	adrp	x16, 0x283000
  223aa4:      	ldr	x17, [x16, #0x2f8]
  223aa8:      	add	x16, x16, #0x2f8
  223aac:      	br	x17

0000000000223ab0 <_ZNSt6__ndk15mutexD1Ev@plt>:
  223ab0:      	adrp	x16, 0x283000
  223ab4:      	ldr	x17, [x16, #0x300]
  223ab8:      	add	x16, x16, #0x300
  223abc:      	br	x17

0000000000223ac0 <__android_log_write@plt>:
  223ac0:      	adrp	x16, 0x283000
  223ac4:      	ldr	x17, [x16, #0x308]
  223ac8:      	add	x16, x16, #0x308
  223acc:      	br	x17

0000000000223ad0 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  223ad0:      	adrp	x16, 0x283000
  223ad4:      	ldr	x17, [x16, #0x310]
  223ad8:      	add	x16, x16, #0x310
  223adc:      	br	x17

0000000000223ae0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  223ae0:      	adrp	x16, 0x283000
  223ae4:      	ldr	x17, [x16, #0x318]
  223ae8:      	add	x16, x16, #0x318
  223aec:      	br	x17

0000000000223af0 <malloc@plt>:
  223af0:      	adrp	x16, 0x283000
  223af4:      	ldr	x17, [x16, #0x320]
  223af8:      	add	x16, x16, #0x320
  223afc:      	br	x17

0000000000223b00 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
  223b00:      	adrp	x16, 0x283000
  223b04:      	ldr	x17, [x16, #0x328]
  223b08:      	add	x16, x16, #0x328
  223b0c:      	br	x17

0000000000223b10 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  223b10:      	adrp	x16, 0x283000
  223b14:      	ldr	x17, [x16, #0x330]
  223b18:      	add	x16, x16, #0x330
  223b1c:      	br	x17

0000000000223b20 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  223b20:      	adrp	x16, 0x283000
  223b24:      	ldr	x17, [x16, #0x338]
  223b28:      	add	x16, x16, #0x338
  223b2c:      	br	x17

0000000000223b30 <_ZNSt6__ndk16localeD1Ev@plt>:
  223b30:      	adrp	x16, 0x283000
  223b34:      	ldr	x17, [x16, #0x340]
  223b38:      	add	x16, x16, #0x340
  223b3c:      	br	x17

0000000000223b40 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  223b40:      	adrp	x16, 0x283000
  223b44:      	ldr	x17, [x16, #0x348]
  223b48:      	add	x16, x16, #0x348
  223b4c:      	br	x17

0000000000223b50 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
  223b50:      	adrp	x16, 0x283000
  223b54:      	ldr	x17, [x16, #0x350]
  223b58:      	add	x16, x16, #0x350
  223b5c:      	br	x17

0000000000223b60 <_Znam@plt>:
  223b60:      	adrp	x16, 0x283000
  223b64:      	ldr	x17, [x16, #0x358]
  223b68:      	add	x16, x16, #0x358
  223b6c:      	br	x17

0000000000223b70 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  223b70:      	adrp	x16, 0x283000
  223b74:      	ldr	x17, [x16, #0x360]
  223b78:      	add	x16, x16, #0x360
  223b7c:      	br	x17

0000000000223b80 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  223b80:      	adrp	x16, 0x283000
  223b84:      	ldr	x17, [x16, #0x368]
  223b88:      	add	x16, x16, #0x368
  223b8c:      	br	x17

0000000000223b90 <_ZNSt6__ndk19to_stringEj@plt>:
  223b90:      	adrp	x16, 0x283000
  223b94:      	ldr	x17, [x16, #0x370]
  223b98:      	add	x16, x16, #0x370
  223b9c:      	br	x17

0000000000223ba0 <pthread_self@plt>:
  223ba0:      	adrp	x16, 0x283000
  223ba4:      	ldr	x17, [x16, #0x378]
  223ba8:      	add	x16, x16, #0x378
  223bac:      	br	x17

0000000000223bb0 <pthread_setname_np@plt>:
  223bb0:      	adrp	x16, 0x283000
  223bb4:      	ldr	x17, [x16, #0x380]
  223bb8:      	add	x16, x16, #0x380
  223bbc:      	br	x17

0000000000223bc0 <setpriority@plt>:
  223bc0:      	adrp	x16, 0x283000
  223bc4:      	ldr	x17, [x16, #0x388]
  223bc8:      	add	x16, x16, #0x388
  223bcc:      	br	x17

0000000000223bd0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
  223bd0:      	adrp	x16, 0x283000
  223bd4:      	ldr	x17, [x16, #0x390]
  223bd8:      	add	x16, x16, #0x390
  223bdc:      	br	x17

0000000000223be0 <_ZNSt6__ndk112__next_primeEm@plt>:
  223be0:      	adrp	x16, 0x283000
  223be4:      	ldr	x17, [x16, #0x398]
  223be8:      	add	x16, x16, #0x398
  223bec:      	br	x17

0000000000223bf0 <strstr@plt>:
  223bf0:      	adrp	x16, 0x283000
  223bf4:      	ldr	x17, [x16, #0x3a0]
  223bf8:      	add	x16, x16, #0x3a0
  223bfc:      	br	x17

0000000000223c00 <dlclose@plt>:
  223c00:      	adrp	x16, 0x283000
  223c04:      	ldr	x17, [x16, #0x3a8]
  223c08:      	add	x16, x16, #0x3a8
  223c0c:      	br	x17

0000000000223c10 <dlopen@plt>:
  223c10:      	adrp	x16, 0x283000
  223c14:      	ldr	x17, [x16, #0x3b0]
  223c18:      	add	x16, x16, #0x3b0
  223c1c:      	br	x17

0000000000223c20 <strncmp@plt>:
  223c20:      	adrp	x16, 0x283000
  223c24:      	ldr	x17, [x16, #0x3b8]
  223c28:      	add	x16, x16, #0x3b8
  223c2c:      	br	x17

0000000000223c30 <dlsym@plt>:
  223c30:      	adrp	x16, 0x283000
  223c34:      	ldr	x17, [x16, #0x3c0]
  223c38:      	add	x16, x16, #0x3c0
  223c3c:      	br	x17

0000000000223c40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  223c40:      	adrp	x16, 0x283000
  223c44:      	ldr	x17, [x16, #0x3c8]
  223c48:      	add	x16, x16, #0x3c8
  223c4c:      	br	x17

0000000000223c50 <sched_yield@plt>:
  223c50:      	adrp	x16, 0x283000
  223c54:      	ldr	x17, [x16, #0x3d0]
  223c58:      	add	x16, x16, #0x3d0
  223c5c:      	br	x17

0000000000223c60 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm@plt>:
  223c60:      	adrp	x16, 0x283000
  223c64:      	ldr	x17, [x16, #0x3d8]
  223c68:      	add	x16, x16, #0x3d8
  223c6c:      	br	x17

0000000000223c70 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj@plt>:
  223c70:      	adrp	x16, 0x283000
  223c74:      	ldr	x17, [x16, #0x3e0]
  223c78:      	add	x16, x16, #0x3e0
  223c7c:      	br	x17

0000000000223c80 <_ZNSt13exception_ptrD1Ev@plt>:
  223c80:      	adrp	x16, 0x283000
  223c84:      	ldr	x17, [x16, #0x3e8]
  223c88:      	add	x16, x16, #0x3e8
  223c8c:      	br	x17

0000000000223c90 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
  223c90:      	adrp	x16, 0x283000
  223c94:      	ldr	x17, [x16, #0x3f0]
  223c98:      	add	x16, x16, #0x3f0
  223c9c:      	br	x17

0000000000223ca0 <_ZNSt6__ndk16thread4joinEv@plt>:
  223ca0:      	adrp	x16, 0x283000
  223ca4:      	ldr	x17, [x16, #0x3f8]
  223ca8:      	add	x16, x16, #0x3f8
  223cac:      	br	x17

0000000000223cb0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
  223cb0:      	adrp	x16, 0x283000
  223cb4:      	ldr	x17, [x16, #0x400]
  223cb8:      	add	x16, x16, #0x400
  223cbc:      	br	x17

0000000000223cc0 <_ZNSt6__ndk16threadD1Ev@plt>:
  223cc0:      	adrp	x16, 0x283000
  223cc4:      	ldr	x17, [x16, #0x408]
  223cc8:      	add	x16, x16, #0x408
  223ccc:      	br	x17

0000000000223cd0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
  223cd0:      	adrp	x16, 0x283000
  223cd4:      	ldr	x17, [x16, #0x410]
  223cd8:      	add	x16, x16, #0x410
  223cdc:      	br	x17

0000000000223ce0 <pthread_create@plt>:
  223ce0:      	adrp	x16, 0x283000
  223ce4:      	ldr	x17, [x16, #0x418]
  223ce8:      	add	x16, x16, #0x418
  223cec:      	br	x17

0000000000223cf0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
  223cf0:      	adrp	x16, 0x283000
  223cf4:      	ldr	x17, [x16, #0x420]
  223cf8:      	add	x16, x16, #0x420
  223cfc:      	br	x17

0000000000223d00 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
  223d00:      	adrp	x16, 0x283000
  223d04:      	ldr	x17, [x16, #0x428]
  223d08:      	add	x16, x16, #0x428
  223d0c:      	br	x17

0000000000223d10 <_ZNSt6__ndk16locale7classicEv@plt>:
  223d10:      	adrp	x16, 0x283000
  223d14:      	ldr	x17, [x16, #0x430]
  223d18:      	add	x16, x16, #0x430
  223d1c:      	br	x17

0000000000223d20 <_ZNSt6__ndk18ios_base5imbueERKNS_6localeE@plt>:
  223d20:      	adrp	x16, 0x283000
  223d24:      	ldr	x17, [x16, #0x438]
  223d28:      	add	x16, x16, #0x438
  223d2c:      	br	x17

0000000000223d30 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
  223d30:      	adrp	x16, 0x283000
  223d34:      	ldr	x17, [x16, #0x440]
  223d38:      	add	x16, x16, #0x440
  223d3c:      	br	x17

0000000000223d40 <_ZNSt6__ndk16localeaSERKS0_@plt>:
  223d40:      	adrp	x16, 0x283000
  223d44:      	ldr	x17, [x16, #0x448]
  223d48:      	add	x16, x16, #0x448
  223d4c:      	br	x17

0000000000223d50 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
  223d50:      	adrp	x16, 0x283000
  223d54:      	ldr	x17, [x16, #0x450]
  223d58:      	add	x16, x16, #0x450
  223d5c:      	br	x17

0000000000223d60 <_ZNSt6__ndk115future_categoryEv@plt>:
  223d60:      	adrp	x16, 0x283000
  223d64:      	ldr	x17, [x16, #0x458]
  223d68:      	add	x16, x16, #0x458
  223d6c:      	br	x17

0000000000223d70 <_ZNSt6__ndk112future_errorC1ENS_10error_codeE@plt>:
  223d70:      	adrp	x16, 0x283000
  223d74:      	ldr	x17, [x16, #0x460]
  223d78:      	add	x16, x16, #0x460
  223d7c:      	br	x17

0000000000223d80 <abort@plt>:
  223d80:      	adrp	x16, 0x283000
  223d84:      	ldr	x17, [x16, #0x468]
  223d88:      	add	x16, x16, #0x468
  223d8c:      	br	x17

0000000000223d90 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
  223d90:      	adrp	x16, 0x283000
  223d94:      	ldr	x17, [x16, #0x470]
  223d98:      	add	x16, x16, #0x470
  223d9c:      	br	x17

0000000000223da0 <_ZNSt6__ndk117__assoc_sub_state10__sub_waitERNS_11unique_lockINS_5mutexEEE@plt>:
  223da0:      	adrp	x16, 0x283000
  223da4:      	ldr	x17, [x16, #0x478]
  223da8:      	add	x16, x16, #0x478
  223dac:      	br	x17

0000000000223db0 <_ZNSt13exception_ptrC1ERKS_@plt>:
  223db0:      	adrp	x16, 0x283000
  223db4:      	ldr	x17, [x16, #0x480]
  223db8:      	add	x16, x16, #0x480
  223dbc:      	br	x17

0000000000223dc0 <_ZSt17rethrow_exceptionSt13exception_ptr@plt>:
  223dc0:      	adrp	x16, 0x283000
  223dc4:      	ldr	x17, [x16, #0x488]
  223dc8:      	add	x16, x16, #0x488
  223dcc:      	br	x17

0000000000223dd0 <_ZNSt6__ndk114__shared_countD2Ev@plt>:
  223dd0:      	adrp	x16, 0x283000
  223dd4:      	ldr	x17, [x16, #0x490]
  223dd8:      	add	x16, x16, #0x490
  223ddc:      	br	x17

0000000000223de0 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
  223de0:      	adrp	x16, 0x283000
  223de4:      	ldr	x17, [x16, #0x498]
  223de8:      	add	x16, x16, #0x498
  223dec:      	br	x17

0000000000223df0 <pthread_setspecific@plt>:
  223df0:      	adrp	x16, 0x283000
  223df4:      	ldr	x17, [x16, #0x4a0]
  223df8:      	add	x16, x16, #0x4a0
  223dfc:      	br	x17

0000000000223e00 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
  223e00:      	adrp	x16, 0x283000
  223e04:      	ldr	x17, [x16, #0x4a8]
  223e08:      	add	x16, x16, #0x4a8
  223e0c:      	br	x17

0000000000223e10 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
  223e10:      	adrp	x16, 0x283000
  223e14:      	ldr	x17, [x16, #0x4b0]
  223e18:      	add	x16, x16, #0x4b0
  223e1c:      	br	x17

0000000000223e20 <_ZNSt6__ndk19to_stringEm@plt>:
  223e20:      	adrp	x16, 0x283000
  223e24:      	ldr	x17, [x16, #0x4b8]
  223e28:      	add	x16, x16, #0x4b8
  223e2c:      	br	x17

0000000000223e30 <_ZNSt6__ndk19to_stringEi@plt>:
  223e30:      	adrp	x16, 0x283000
  223e34:      	ldr	x17, [x16, #0x4c0]
  223e38:      	add	x16, x16, #0x4c0
  223e3c:      	br	x17

0000000000223e40 <_ZNSt6__ndk19to_stringEd@plt>:
  223e40:      	adrp	x16, 0x283000
  223e44:      	ldr	x17, [x16, #0x4c8]
  223e48:      	add	x16, x16, #0x4c8
  223e4c:      	br	x17

0000000000223e50 <_ZNSt6__ndk19to_stringEl@plt>:
  223e50:      	adrp	x16, 0x283000
  223e54:      	ldr	x17, [x16, #0x4d0]
  223e58:      	add	x16, x16, #0x4d0
  223e5c:      	br	x17

0000000000223e60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
  223e60:      	adrp	x16, 0x283000
  223e64:      	ldr	x17, [x16, #0x4d8]
  223e68:      	add	x16, x16, #0x4d8
  223e6c:      	br	x17

0000000000223e70 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm@plt>:
  223e70:      	adrp	x16, 0x283000
  223e74:      	ldr	x17, [x16, #0x4e0]
  223e78:      	add	x16, x16, #0x4e0
  223e7c:      	br	x17

0000000000223e80 <fflush@plt>:
  223e80:      	adrp	x16, 0x283000
  223e84:      	ldr	x17, [x16, #0x4e8]
  223e88:      	add	x16, x16, #0x4e8
  223e8c:      	br	x17

0000000000223e90 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  223e90:      	adrp	x16, 0x283000
  223e94:      	ldr	x17, [x16, #0x4f0]
  223e98:      	add	x16, x16, #0x4f0
  223e9c:      	br	x17

0000000000223ea0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__grow_byEmmmmmm@plt>:
  223ea0:      	adrp	x16, 0x283000
  223ea4:      	ldr	x17, [x16, #0x4f8]
  223ea8:      	add	x16, x16, #0x4f8
  223eac:      	br	x17

0000000000223eb0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  223eb0:      	adrp	x16, 0x283000
  223eb4:      	ldr	x17, [x16, #0x500]
  223eb8:      	add	x16, x16, #0x500
  223ebc:      	br	x17

0000000000223ec0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  223ec0:      	adrp	x16, 0x283000
  223ec4:      	ldr	x17, [x16, #0x508]
  223ec8:      	add	x16, x16, #0x508
  223ecc:      	br	x17

0000000000223ed0 <strcmp@plt>:
  223ed0:      	adrp	x16, 0x283000
  223ed4:      	ldr	x17, [x16, #0x510]
  223ed8:      	add	x16, x16, #0x510
  223edc:      	br	x17

0000000000223ee0 <__strchr_chk@plt>:
  223ee0:      	adrp	x16, 0x283000
  223ee4:      	ldr	x17, [x16, #0x518]
  223ee8:      	add	x16, x16, #0x518
  223eec:      	br	x17

0000000000223ef0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
  223ef0:      	adrp	x16, 0x283000
  223ef4:      	ldr	x17, [x16, #0x520]
  223ef8:      	add	x16, x16, #0x520
  223efc:      	br	x17

0000000000223f00 <memchr@plt>:
  223f00:      	adrp	x16, 0x283000
  223f04:      	ldr	x17, [x16, #0x528]
  223f08:      	add	x16, x16, #0x528
  223f0c:      	br	x17

0000000000223f10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEt@plt>:
  223f10:      	adrp	x16, 0x283000
  223f14:      	ldr	x17, [x16, #0x530]
  223f18:      	add	x16, x16, #0x530
  223f1c:      	br	x17

0000000000223f20 <strcpy@plt>:
  223f20:      	adrp	x16, 0x283000
  223f24:      	ldr	x17, [x16, #0x538]
  223f28:      	add	x16, x16, #0x538
  223f2c:      	br	x17

0000000000223f30 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc@plt>:
  223f30:      	adrp	x16, 0x283000
  223f34:      	ldr	x17, [x16, #0x540]
  223f38:      	add	x16, x16, #0x540
  223f3c:      	br	x17

0000000000223f40 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
  223f40:      	adrp	x16, 0x283000
  223f44:      	ldr	x17, [x16, #0x548]
  223f48:      	add	x16, x16, #0x548
  223f4c:      	br	x17

0000000000223f50 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
  223f50:      	adrp	x16, 0x283000
  223f54:      	ldr	x17, [x16, #0x550]
  223f58:      	add	x16, x16, #0x550
  223f5c:      	br	x17

0000000000223f60 <_ZNSt6__ndk16__sortIRNS_6__lessIjjEEPjEEvT0_S5_T_@plt>:
  223f60:      	adrp	x16, 0x283000
  223f64:      	ldr	x17, [x16, #0x558]
  223f68:      	add	x16, x16, #0x558
  223f6c:      	br	x17

0000000000223f70 <wmemchr@plt>:
  223f70:      	adrp	x16, 0x283000
  223f74:      	ldr	x17, [x16, #0x560]
  223f78:      	add	x16, x16, #0x560
  223f7c:      	br	x17

0000000000223f80 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKc@plt>:
  223f80:      	adrp	x16, 0x283000
  223f84:      	ldr	x17, [x16, #0x568]
  223f88:      	add	x16, x16, #0x568
  223f8c:      	br	x17

0000000000223f90 <__vsnprintf_chk@plt>:
  223f90:      	adrp	x16, 0x283000
  223f94:      	ldr	x17, [x16, #0x570]
  223f98:      	add	x16, x16, #0x570
  223f9c:      	br	x17

0000000000223fa0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
  223fa0:      	adrp	x16, 0x283000
  223fa4:      	ldr	x17, [x16, #0x578]
  223fa8:      	add	x16, x16, #0x578
  223fac:      	br	x17

0000000000223fb0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb@plt>:
  223fb0:      	adrp	x16, 0x283000
  223fb4:      	ldr	x17, [x16, #0x580]
  223fb8:      	add	x16, x16, #0x580
  223fbc:      	br	x17

0000000000223fc0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm@plt>:
  223fc0:      	adrp	x16, 0x283000
  223fc4:      	ldr	x17, [x16, #0x588]
  223fc8:      	add	x16, x16, #0x588
  223fcc:      	br	x17

0000000000223fd0 <localeconv@plt>:
  223fd0:      	adrp	x16, 0x283000
  223fd4:      	ldr	x17, [x16, #0x590]
  223fd8:      	add	x16, x16, #0x590
  223fdc:      	br	x17

0000000000223fe0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
  223fe0:      	adrp	x16, 0x283000
  223fe4:      	ldr	x17, [x16, #0x598]
  223fe8:      	add	x16, x16, #0x598
  223fec:      	br	x17

0000000000223ff0 <__strcat_chk@plt>:
  223ff0:      	adrp	x16, 0x283000
  223ff4:      	ldr	x17, [x16, #0x5a0]
  223ff8:      	add	x16, x16, #0x5a0
  223ffc:      	br	x17

0000000000224000 <__vsprintf_chk@plt>:
  224000:      	adrp	x16, 0x283000
  224004:      	ldr	x17, [x16, #0x5a8]
  224008:      	add	x16, x16, #0x5a8
  22400c:      	br	x17

0000000000224010 <getauxval@plt>:
  224010:      	adrp	x16, 0x283000
  224014:      	ldr	x17, [x16, #0x5b0]
  224018:      	add	x16, x16, #0x5b0
  22401c:      	br	x17

0000000000224020 <__system_property_get@plt>:
  224020:      	adrp	x16, 0x283000
  224024:      	ldr	x17, [x16, #0x5b8]
  224028:      	add	x16, x16, #0x5b8
  22402c:      	br	x17
