// EXPORTED & PLT DISASSEMBLY FOR libARKernelInterface.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libARKernelInterface.so (SHA-256: 594C5085475D8BB58BAACB20293AEC805211AA5CCC53B3542F3149196D354953)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 912, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libARKernelInterface.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000010468d0 <.plt>:
 10468d0:      	stp	x16, x30, [sp, #-0x10]!
 10468d4:      	adrp	x16, 0x10c6000
 10468d8:      	ldr	x17, [x16, #0x9b0]
 10468dc:      	add	x16, x16, #0x9b0
 10468e0:      	br	x17
 10468e4:      	nop
 10468e8:      	nop
 10468ec:      	nop

00000000010468f0 <__cxa_finalize@plt>:
 10468f0:      	adrp	x16, 0x10c6000
 10468f4:      	ldr	x17, [x16, #0x9b8]
 10468f8:      	add	x16, x16, #0x9b8
 10468fc:      	br	x17

0000000001046900 <__cxa_atexit@plt>:
 1046900:      	adrp	x16, 0x10c6000
 1046904:      	ldr	x17, [x16, #0x9c0]
 1046908:      	add	x16, x16, #0x9c0
 104690c:      	br	x17

0000000001046910 <__android_log_print@plt>:
 1046910:      	adrp	x16, 0x10c6000
 1046914:      	ldr	x17, [x16, #0x9c8]
 1046918:      	add	x16, x16, #0x9c8
 104691c:      	br	x17

0000000001046920 <strlen@plt>:
 1046920:      	adrp	x16, 0x10c6000
 1046924:      	ldr	x17, [x16, #0x9d0]
 1046928:      	add	x16, x16, #0x9d0
 104692c:      	br	x17

0000000001046930 <_Znam@plt>:
 1046930:      	adrp	x16, 0x10c6000
 1046934:      	ldr	x17, [x16, #0x9d8]
 1046938:      	add	x16, x16, #0x9d8
 104693c:      	br	x17

0000000001046940 <strcpy@plt>:
 1046940:      	adrp	x16, 0x10c6000
 1046944:      	ldr	x17, [x16, #0x9e0]
 1046948:      	add	x16, x16, #0x9e0
 104694c:      	br	x17

0000000001046950 <__stack_chk_fail@plt>:
 1046950:      	adrp	x16, 0x10c6000
 1046954:      	ldr	x17, [x16, #0x9e8]
 1046958:      	add	x16, x16, #0x9e8
 104695c:      	br	x17

0000000001046960 <sysconf@plt>:
 1046960:      	adrp	x16, 0x10c6000
 1046964:      	ldr	x17, [x16, #0x9f0]
 1046968:      	add	x16, x16, #0x9f0
 104696c:      	br	x17

0000000001046970 <memset@plt>:
 1046970:      	adrp	x16, 0x10c6000
 1046974:      	ldr	x17, [x16, #0x9f8]
 1046978:      	add	x16, x16, #0x9f8
 104697c:      	br	x17

0000000001046980 <_ZdaPv@plt>:
 1046980:      	adrp	x16, 0x10c6000
 1046984:      	ldr	x17, [x16, #0xa00]
 1046988:      	add	x16, x16, #0xa00
 104698c:      	br	x17

0000000001046990 <__vsprintf_chk@plt>:
 1046990:      	adrp	x16, 0x10c6000
 1046994:      	ldr	x17, [x16, #0xa08]
 1046998:      	add	x16, x16, #0xa08
 104699c:      	br	x17

00000000010469a0 <strstr@plt>:
 10469a0:      	adrp	x16, 0x10c6000
 10469a4:      	ldr	x17, [x16, #0xa10]
 10469a8:      	add	x16, x16, #0xa10
 10469ac:      	br	x17

00000000010469b0 <pthread_getspecific@plt>:
 10469b0:      	adrp	x16, 0x10c6000
 10469b4:      	ldr	x17, [x16, #0xa18]
 10469b8:      	add	x16, x16, #0xa18
 10469bc:      	br	x17

00000000010469c0 <pthread_self@plt>:
 10469c0:      	adrp	x16, 0x10c6000
 10469c4:      	ldr	x17, [x16, #0xa20]
 10469c8:      	add	x16, x16, #0xa20
 10469cc:      	br	x17

00000000010469d0 <pthread_key_create@plt>:
 10469d0:      	adrp	x16, 0x10c6000
 10469d4:      	ldr	x17, [x16, #0xa28]
 10469d8:      	add	x16, x16, #0xa28
 10469dc:      	br	x17

00000000010469e0 <pthread_setspecific@plt>:
 10469e0:      	adrp	x16, 0x10c6000
 10469e4:      	ldr	x17, [x16, #0xa30]
 10469e8:      	add	x16, x16, #0xa30
 10469ec:      	br	x17

00000000010469f0 <_Znwm@plt>:
 10469f0:      	adrp	x16, 0x10c6000
 10469f4:      	ldr	x17, [x16, #0xa38]
 10469f8:      	add	x16, x16, #0xa38
 10469fc:      	br	x17

0000000001046a00 <memmove@plt>:
 1046a00:      	adrp	x16, 0x10c6000
 1046a04:      	ldr	x17, [x16, #0xa40]
 1046a08:      	add	x16, x16, #0xa40
 1046a0c:      	br	x17

0000000001046a10 <memcpy@plt>:
 1046a10:      	adrp	x16, 0x10c6000
 1046a14:      	ldr	x17, [x16, #0xa48]
 1046a18:      	add	x16, x16, #0xa48
 1046a1c:      	br	x17

0000000001046a20 <_ZdlPv@plt>:
 1046a20:      	adrp	x16, 0x10c6000
 1046a24:      	ldr	x17, [x16, #0xa50]
 1046a28:      	add	x16, x16, #0xa50
 1046a2c:      	br	x17

0000000001046a30 <__cxa_allocate_exception@plt>:
 1046a30:      	adrp	x16, 0x10c6000
 1046a34:      	ldr	x17, [x16, #0xa58]
 1046a38:      	add	x16, x16, #0xa58
 1046a3c:      	br	x17

0000000001046a40 <__cxa_throw@plt>:
 1046a40:      	adrp	x16, 0x10c6000
 1046a44:      	ldr	x17, [x16, #0xa60]
 1046a48:      	add	x16, x16, #0xa60
 1046a4c:      	br	x17

0000000001046a50 <__cxa_free_exception@plt>:
 1046a50:      	adrp	x16, 0x10c6000
 1046a54:      	ldr	x17, [x16, #0xa68]
 1046a58:      	add	x16, x16, #0xa68
 1046a5c:      	br	x17

0000000001046a60 <_ZNSt11logic_errorC2EPKc@plt>:
 1046a60:      	adrp	x16, 0x10c6000
 1046a64:      	ldr	x17, [x16, #0xa70]
 1046a68:      	add	x16, x16, #0xa70
 1046a6c:      	br	x17

0000000001046a70 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
 1046a70:      	adrp	x16, 0x10c6000
 1046a74:      	ldr	x17, [x16, #0xa78]
 1046a78:      	add	x16, x16, #0xa78
 1046a7c:      	br	x17

0000000001046a80 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
 1046a80:      	adrp	x16, 0x10c6000
 1046a84:      	ldr	x17, [x16, #0xa80]
 1046a88:      	add	x16, x16, #0xa80
 1046a8c:      	br	x17

0000000001046a90 <__cxa_begin_catch@plt>:
 1046a90:      	adrp	x16, 0x10c6000
 1046a94:      	ldr	x17, [x16, #0xa88]
 1046a98:      	add	x16, x16, #0xa88
 1046a9c:      	br	x17

0000000001046aa0 <_ZSt9terminatev@plt>:
 1046aa0:      	adrp	x16, 0x10c6000
 1046aa4:      	ldr	x17, [x16, #0xa90]
 1046aa8:      	add	x16, x16, #0xa90
 1046aac:      	br	x17

0000000001046ab0 <__cxa_guard_acquire@plt>:
 1046ab0:      	adrp	x16, 0x10c6000
 1046ab4:      	ldr	x17, [x16, #0xa98]
 1046ab8:      	add	x16, x16, #0xa98
 1046abc:      	br	x17

0000000001046ac0 <__cxa_guard_release@plt>:
 1046ac0:      	adrp	x16, 0x10c6000
 1046ac4:      	ldr	x17, [x16, #0xaa0]
 1046ac8:      	add	x16, x16, #0xaa0
 1046acc:      	br	x17

0000000001046ad0 <memcmp@plt>:
 1046ad0:      	adrp	x16, 0x10c6000
 1046ad4:      	ldr	x17, [x16, #0xaa8]
 1046ad8:      	add	x16, x16, #0xaa8
 1046adc:      	br	x17

0000000001046ae0 <__cxa_guard_abort@plt>:
 1046ae0:      	adrp	x16, 0x10c6000
 1046ae4:      	ldr	x17, [x16, #0xab0]
 1046ae8:      	add	x16, x16, #0xab0
 1046aec:      	br	x17

0000000001046af0 <__memcpy_chk@plt>:
 1046af0:      	adrp	x16, 0x10c6000
 1046af4:      	ldr	x17, [x16, #0xab8]
 1046af8:      	add	x16, x16, #0xab8
 1046afc:      	br	x17

0000000001046b00 <_ZNSt9exceptionD2Ev@plt>:
 1046b00:      	adrp	x16, 0x10c6000
 1046b04:      	ldr	x17, [x16, #0xac0]
 1046b08:      	add	x16, x16, #0xac0
 1046b0c:      	br	x17

0000000001046b10 <__dynamic_cast@plt>:
 1046b10:      	adrp	x16, 0x10c6000
 1046b14:      	ldr	x17, [x16, #0xac8]
 1046b18:      	add	x16, x16, #0xac8
 1046b1c:      	br	x17

0000000001046b20 <__android_log_vprint@plt>:
 1046b20:      	adrp	x16, 0x10c6000
 1046b24:      	ldr	x17, [x16, #0xad0]
 1046b28:      	add	x16, x16, #0xad0
 1046b2c:      	br	x17

0000000001046b30 <AAssetManager_open@plt>:
 1046b30:      	adrp	x16, 0x10c6000
 1046b34:      	ldr	x17, [x16, #0xad8]
 1046b38:      	add	x16, x16, #0xad8
 1046b3c:      	br	x17

0000000001046b40 <AAsset_getRemainingLength@plt>:
 1046b40:      	adrp	x16, 0x10c6000
 1046b44:      	ldr	x17, [x16, #0xae0]
 1046b48:      	add	x16, x16, #0xae0
 1046b4c:      	br	x17

0000000001046b50 <AAsset_seek@plt>:
 1046b50:      	adrp	x16, 0x10c6000
 1046b54:      	ldr	x17, [x16, #0xae8]
 1046b58:      	add	x16, x16, #0xae8
 1046b5c:      	br	x17

0000000001046b60 <AAsset_getBuffer@plt>:
 1046b60:      	adrp	x16, 0x10c6000
 1046b64:      	ldr	x17, [x16, #0xaf0]
 1046b68:      	add	x16, x16, #0xaf0
 1046b6c:      	br	x17

0000000001046b70 <AAsset_read@plt>:
 1046b70:      	adrp	x16, 0x10c6000
 1046b74:      	ldr	x17, [x16, #0xaf8]
 1046b78:      	add	x16, x16, #0xaf8
 1046b7c:      	br	x17

0000000001046b80 <AAsset_close@plt>:
 1046b80:      	adrp	x16, 0x10c6000
 1046b84:      	ldr	x17, [x16, #0xb00]
 1046b88:      	add	x16, x16, #0xb00
 1046b8c:      	br	x17

0000000001046b90 <AAssetManager_fromJava@plt>:
 1046b90:      	adrp	x16, 0x10c6000
 1046b94:      	ldr	x17, [x16, #0xb08]
 1046b98:      	add	x16, x16, #0xb08
 1046b9c:      	br	x17

0000000001046ba0 <AAsset_getLength@plt>:
 1046ba0:      	adrp	x16, 0x10c6000
 1046ba4:      	ldr	x17, [x16, #0xb10]
 1046ba8:      	add	x16, x16, #0xb10
 1046bac:      	br	x17

0000000001046bb0 <AndroidBitmap_getInfo@plt>:
 1046bb0:      	adrp	x16, 0x10c6000
 1046bb4:      	ldr	x17, [x16, #0xb18]
 1046bb8:      	add	x16, x16, #0xb18
 1046bbc:      	br	x17

0000000001046bc0 <AndroidBitmap_lockPixels@plt>:
 1046bc0:      	adrp	x16, 0x10c6000
 1046bc4:      	ldr	x17, [x16, #0xb20]
 1046bc8:      	add	x16, x16, #0xb20
 1046bcc:      	br	x17

0000000001046bd0 <AndroidBitmap_unlockPixels@plt>:
 1046bd0:      	adrp	x16, 0x10c6000
 1046bd4:      	ldr	x17, [x16, #0xb28]
 1046bd8:      	add	x16, x16, #0xb28
 1046bdc:      	br	x17

0000000001046be0 <eglDestroySurface@plt>:
 1046be0:      	adrp	x16, 0x10c6000
 1046be4:      	ldr	x17, [x16, #0xb30]
 1046be8:      	add	x16, x16, #0xb30
 1046bec:      	br	x17

0000000001046bf0 <eglGetCurrentSurface@plt>:
 1046bf0:      	adrp	x16, 0x10c6000
 1046bf4:      	ldr	x17, [x16, #0xb38]
 1046bf8:      	add	x16, x16, #0xb38
 1046bfc:      	br	x17

0000000001046c00 <eglMakeCurrent@plt>:
 1046c00:      	adrp	x16, 0x10c6000
 1046c04:      	ldr	x17, [x16, #0xb40]
 1046c08:      	add	x16, x16, #0xb40
 1046c0c:      	br	x17

0000000001046c10 <eglDestroyContext@plt>:
 1046c10:      	adrp	x16, 0x10c6000
 1046c14:      	ldr	x17, [x16, #0xb48]
 1046c18:      	add	x16, x16, #0xb48
 1046c1c:      	br	x17

0000000001046c20 <eglGetCurrentContext@plt>:
 1046c20:      	adrp	x16, 0x10c6000
 1046c24:      	ldr	x17, [x16, #0xb50]
 1046c28:      	add	x16, x16, #0xb50
 1046c2c:      	br	x17

0000000001046c30 <eglGetDisplay@plt>:
 1046c30:      	adrp	x16, 0x10c6000
 1046c34:      	ldr	x17, [x16, #0xb58]
 1046c38:      	add	x16, x16, #0xb58
 1046c3c:      	br	x17

0000000001046c40 <eglTerminate@plt>:
 1046c40:      	adrp	x16, 0x10c6000
 1046c44:      	ldr	x17, [x16, #0xb60]
 1046c48:      	add	x16, x16, #0xb60
 1046c4c:      	br	x17

0000000001046c50 <eglChooseConfig@plt>:
 1046c50:      	adrp	x16, 0x10c6000
 1046c54:      	ldr	x17, [x16, #0xb68]
 1046c58:      	add	x16, x16, #0xb68
 1046c5c:      	br	x17

0000000001046c60 <eglInitialize@plt>:
 1046c60:      	adrp	x16, 0x10c6000
 1046c64:      	ldr	x17, [x16, #0xb70]
 1046c68:      	add	x16, x16, #0xb70
 1046c6c:      	br	x17

0000000001046c70 <eglCreateContext@plt>:
 1046c70:      	adrp	x16, 0x10c6000
 1046c74:      	ldr	x17, [x16, #0xb78]
 1046c78:      	add	x16, x16, #0xb78
 1046c7c:      	br	x17

0000000001046c80 <eglCreatePbufferSurface@plt>:
 1046c80:      	adrp	x16, 0x10c6000
 1046c84:      	ldr	x17, [x16, #0xb80]
 1046c88:      	add	x16, x16, #0xb80
 1046c8c:      	br	x17

0000000001046c90 <eglCreateWindowSurface@plt>:
 1046c90:      	adrp	x16, 0x10c6000
 1046c94:      	ldr	x17, [x16, #0xb88]
 1046c98:      	add	x16, x16, #0xb88
 1046c9c:      	br	x17

0000000001046ca0 <eglGetCurrentDisplay@plt>:
 1046ca0:      	adrp	x16, 0x10c6000
 1046ca4:      	ldr	x17, [x16, #0xb90]
 1046ca8:      	add	x16, x16, #0xb90
 1046cac:      	br	x17

0000000001046cb0 <eglGetConfigs@plt>:
 1046cb0:      	adrp	x16, 0x10c6000
 1046cb4:      	ldr	x17, [x16, #0xb98]
 1046cb8:      	add	x16, x16, #0xb98
 1046cbc:      	br	x17

0000000001046cc0 <eglGetError@plt>:
 1046cc0:      	adrp	x16, 0x10c6000
 1046cc4:      	ldr	x17, [x16, #0xba0]
 1046cc8:      	add	x16, x16, #0xba0
 1046ccc:      	br	x17

0000000001046cd0 <glBindRenderbuffer@plt>:
 1046cd0:      	adrp	x16, 0x10c6000
 1046cd4:      	ldr	x17, [x16, #0xba8]
 1046cd8:      	add	x16, x16, #0xba8
 1046cdc:      	br	x17

0000000001046ce0 <glTexParameteri@plt>:
 1046ce0:      	adrp	x16, 0x10c6000
 1046ce4:      	ldr	x17, [x16, #0xbb0]
 1046ce8:      	add	x16, x16, #0xbb0
 1046cec:      	br	x17

0000000001046cf0 <glVertexAttribPointer@plt>:
 1046cf0:      	adrp	x16, 0x10c6000
 1046cf4:      	ldr	x17, [x16, #0xbb8]
 1046cf8:      	add	x16, x16, #0xbb8
 1046cfc:      	br	x17

0000000001046d00 <glDrawArrays@plt>:
 1046d00:      	adrp	x16, 0x10c6000
 1046d04:      	ldr	x17, [x16, #0xbc0]
 1046d08:      	add	x16, x16, #0xbc0
 1046d0c:      	br	x17

0000000001046d10 <glLineWidth@plt>:
 1046d10:      	adrp	x16, 0x10c6000
 1046d14:      	ldr	x17, [x16, #0xbc8]
 1046d18:      	add	x16, x16, #0xbc8
 1046d1c:      	br	x17

0000000001046d20 <glRenderbufferStorage@plt>:
 1046d20:      	adrp	x16, 0x10c6000
 1046d24:      	ldr	x17, [x16, #0xbd0]
 1046d28:      	add	x16, x16, #0xbd0
 1046d2c:      	br	x17

0000000001046d30 <glUniformMatrix4fv@plt>:
 1046d30:      	adrp	x16, 0x10c6000
 1046d34:      	ldr	x17, [x16, #0xbd8]
 1046d38:      	add	x16, x16, #0xbd8
 1046d3c:      	br	x17

0000000001046d40 <glBindFramebuffer@plt>:
 1046d40:      	adrp	x16, 0x10c6000
 1046d44:      	ldr	x17, [x16, #0xbe0]
 1046d48:      	add	x16, x16, #0xbe0
 1046d4c:      	br	x17

0000000001046d50 <glBufferData@plt>:
 1046d50:      	adrp	x16, 0x10c6000
 1046d54:      	ldr	x17, [x16, #0xbe8]
 1046d58:      	add	x16, x16, #0xbe8
 1046d5c:      	br	x17

0000000001046d60 <glGetProgramInfoLog@plt>:
 1046d60:      	adrp	x16, 0x10c6000
 1046d64:      	ldr	x17, [x16, #0xbf0]
 1046d68:      	add	x16, x16, #0xbf0
 1046d6c:      	br	x17

0000000001046d70 <glLinkProgram@plt>:
 1046d70:      	adrp	x16, 0x10c6000
 1046d74:      	ldr	x17, [x16, #0xbf8]
 1046d78:      	add	x16, x16, #0xbf8
 1046d7c:      	br	x17

0000000001046d80 <glBlendFuncSeparate@plt>:
 1046d80:      	adrp	x16, 0x10c6000
 1046d84:      	ldr	x17, [x16, #0xc00]
 1046d88:      	add	x16, x16, #0xc00
 1046d8c:      	br	x17

0000000001046d90 <glClearDepthf@plt>:
 1046d90:      	adrp	x16, 0x10c6000
 1046d94:      	ldr	x17, [x16, #0xc08]
 1046d98:      	add	x16, x16, #0xc08
 1046d9c:      	br	x17

0000000001046da0 <glGetActiveUniform@plt>:
 1046da0:      	adrp	x16, 0x10c6000
 1046da4:      	ldr	x17, [x16, #0xc10]
 1046da8:      	add	x16, x16, #0xc10
 1046dac:      	br	x17

0000000001046db0 <glGetShaderiv@plt>:
 1046db0:      	adrp	x16, 0x10c6000
 1046db4:      	ldr	x17, [x16, #0xc18]
 1046db8:      	add	x16, x16, #0xc18
 1046dbc:      	br	x17

0000000001046dc0 <glClearStencil@plt>:
 1046dc0:      	adrp	x16, 0x10c6000
 1046dc4:      	ldr	x17, [x16, #0xc20]
 1046dc8:      	add	x16, x16, #0xc20
 1046dcc:      	br	x17

0000000001046dd0 <glFramebufferTexture2D@plt>:
 1046dd0:      	adrp	x16, 0x10c6000
 1046dd4:      	ldr	x17, [x16, #0xc28]
 1046dd8:      	add	x16, x16, #0xc28
 1046ddc:      	br	x17

0000000001046de0 <glGenFramebuffers@plt>:
 1046de0:      	adrp	x16, 0x10c6000
 1046de4:      	ldr	x17, [x16, #0xc30]
 1046de8:      	add	x16, x16, #0xc30
 1046dec:      	br	x17

0000000001046df0 <glGetIntegerv@plt>:
 1046df0:      	adrp	x16, 0x10c6000
 1046df4:      	ldr	x17, [x16, #0xc38]
 1046df8:      	add	x16, x16, #0xc38
 1046dfc:      	br	x17

0000000001046e00 <glViewport@plt>:
 1046e00:      	adrp	x16, 0x10c6000
 1046e04:      	ldr	x17, [x16, #0xc40]
 1046e08:      	add	x16, x16, #0xc40
 1046e0c:      	br	x17

0000000001046e10 <glDeleteProgram@plt>:
 1046e10:      	adrp	x16, 0x10c6000
 1046e14:      	ldr	x17, [x16, #0xc48]
 1046e18:      	add	x16, x16, #0xc48
 1046e1c:      	br	x17

0000000001046e20 <glDisableVertexAttribArray@plt>:
 1046e20:      	adrp	x16, 0x10c6000
 1046e24:      	ldr	x17, [x16, #0xc50]
 1046e28:      	add	x16, x16, #0xc50
 1046e2c:      	br	x17

0000000001046e30 <glAttachShader@plt>:
 1046e30:      	adrp	x16, 0x10c6000
 1046e34:      	ldr	x17, [x16, #0xc58]
 1046e38:      	add	x16, x16, #0xc58
 1046e3c:      	br	x17

0000000001046e40 <glEnableVertexAttribArray@plt>:
 1046e40:      	adrp	x16, 0x10c6000
 1046e44:      	ldr	x17, [x16, #0xc60]
 1046e48:      	add	x16, x16, #0xc60
 1046e4c:      	br	x17

0000000001046e50 <glUniform4f@plt>:
 1046e50:      	adrp	x16, 0x10c6000
 1046e54:      	ldr	x17, [x16, #0xc68]
 1046e58:      	add	x16, x16, #0xc68
 1046e5c:      	br	x17

0000000001046e60 <glGetAttribLocation@plt>:
 1046e60:      	adrp	x16, 0x10c6000
 1046e64:      	ldr	x17, [x16, #0xc70]
 1046e68:      	add	x16, x16, #0xc70
 1046e6c:      	br	x17

0000000001046e70 <glHint@plt>:
 1046e70:      	adrp	x16, 0x10c6000
 1046e74:      	ldr	x17, [x16, #0xc78]
 1046e78:      	add	x16, x16, #0xc78
 1046e7c:      	br	x17

0000000001046e80 <glUniform1f@plt>:
 1046e80:      	adrp	x16, 0x10c6000
 1046e84:      	ldr	x17, [x16, #0xc80]
 1046e88:      	add	x16, x16, #0xc80
 1046e8c:      	br	x17

0000000001046e90 <glGetError@plt>:
 1046e90:      	adrp	x16, 0x10c6000
 1046e94:      	ldr	x17, [x16, #0xc88]
 1046e98:      	add	x16, x16, #0xc88
 1046e9c:      	br	x17

0000000001046ea0 <glShaderSource@plt>:
 1046ea0:      	adrp	x16, 0x10c6000
 1046ea4:      	ldr	x17, [x16, #0xc90]
 1046ea8:      	add	x16, x16, #0xc90
 1046eac:      	br	x17

0000000001046eb0 <glUniform4fv@plt>:
 1046eb0:      	adrp	x16, 0x10c6000
 1046eb4:      	ldr	x17, [x16, #0xc98]
 1046eb8:      	add	x16, x16, #0xc98
 1046ebc:      	br	x17

0000000001046ec0 <glUniformMatrix3fv@plt>:
 1046ec0:      	adrp	x16, 0x10c6000
 1046ec4:      	ldr	x17, [x16, #0xca0]
 1046ec8:      	add	x16, x16, #0xca0
 1046ecc:      	br	x17

0000000001046ed0 <glCopyTexSubImage2D@plt>:
 1046ed0:      	adrp	x16, 0x10c6000
 1046ed4:      	ldr	x17, [x16, #0xca8]
 1046ed8:      	add	x16, x16, #0xca8
 1046edc:      	br	x17

0000000001046ee0 <glBindTexture@plt>:
 1046ee0:      	adrp	x16, 0x10c6000
 1046ee4:      	ldr	x17, [x16, #0xcb0]
 1046ee8:      	add	x16, x16, #0xcb0
 1046eec:      	br	x17

0000000001046ef0 <glUniform1i@plt>:
 1046ef0:      	adrp	x16, 0x10c6000
 1046ef4:      	ldr	x17, [x16, #0xcb8]
 1046ef8:      	add	x16, x16, #0xcb8
 1046efc:      	br	x17

0000000001046f00 <glEnable@plt>:
 1046f00:      	adrp	x16, 0x10c6000
 1046f04:      	ldr	x17, [x16, #0xcc0]
 1046f08:      	add	x16, x16, #0xcc0
 1046f0c:      	br	x17

0000000001046f10 <glGetString@plt>:
 1046f10:      	adrp	x16, 0x10c6000
 1046f14:      	ldr	x17, [x16, #0xcc8]
 1046f18:      	add	x16, x16, #0xcc8
 1046f1c:      	br	x17

0000000001046f20 <glCreateProgram@plt>:
 1046f20:      	adrp	x16, 0x10c6000
 1046f24:      	ldr	x17, [x16, #0xcd0]
 1046f28:      	add	x16, x16, #0xcd0
 1046f2c:      	br	x17

0000000001046f30 <glBindBuffer@plt>:
 1046f30:      	adrp	x16, 0x10c6000
 1046f34:      	ldr	x17, [x16, #0xcd8]
 1046f38:      	add	x16, x16, #0xcd8
 1046f3c:      	br	x17

0000000001046f40 <glBlendEquation@plt>:
 1046f40:      	adrp	x16, 0x10c6000
 1046f44:      	ldr	x17, [x16, #0xce0]
 1046f48:      	add	x16, x16, #0xce0
 1046f4c:      	br	x17

0000000001046f50 <glColorMask@plt>:
 1046f50:      	adrp	x16, 0x10c6000
 1046f54:      	ldr	x17, [x16, #0xce8]
 1046f58:      	add	x16, x16, #0xce8
 1046f5c:      	br	x17

0000000001046f60 <glGenerateMipmap@plt>:
 1046f60:      	adrp	x16, 0x10c6000
 1046f64:      	ldr	x17, [x16, #0xcf0]
 1046f68:      	add	x16, x16, #0xcf0
 1046f6c:      	br	x17

0000000001046f70 <glFlush@plt>:
 1046f70:      	adrp	x16, 0x10c6000
 1046f74:      	ldr	x17, [x16, #0xcf8]
 1046f78:      	add	x16, x16, #0xcf8
 1046f7c:      	br	x17

0000000001046f80 <glBufferSubData@plt>:
 1046f80:      	adrp	x16, 0x10c6000
 1046f84:      	ldr	x17, [x16, #0xd00]
 1046f88:      	add	x16, x16, #0xd00
 1046f8c:      	br	x17

0000000001046f90 <glCompileShader@plt>:
 1046f90:      	adrp	x16, 0x10c6000
 1046f94:      	ldr	x17, [x16, #0xd08]
 1046f98:      	add	x16, x16, #0xd08
 1046f9c:      	br	x17

0000000001046fa0 <glScissor@plt>:
 1046fa0:      	adrp	x16, 0x10c6000
 1046fa4:      	ldr	x17, [x16, #0xd10]
 1046fa8:      	add	x16, x16, #0xd10
 1046fac:      	br	x17

0000000001046fb0 <glGenRenderbuffers@plt>:
 1046fb0:      	adrp	x16, 0x10c6000
 1046fb4:      	ldr	x17, [x16, #0xd18]
 1046fb8:      	add	x16, x16, #0xd18
 1046fbc:      	br	x17

0000000001046fc0 <glTexImage2D@plt>:
 1046fc0:      	adrp	x16, 0x10c6000
 1046fc4:      	ldr	x17, [x16, #0xd20]
 1046fc8:      	add	x16, x16, #0xd20
 1046fcc:      	br	x17

0000000001046fd0 <glDeleteFramebuffers@plt>:
 1046fd0:      	adrp	x16, 0x10c6000
 1046fd4:      	ldr	x17, [x16, #0xd28]
 1046fd8:      	add	x16, x16, #0xd28
 1046fdc:      	br	x17

0000000001046fe0 <glUniform3fv@plt>:
 1046fe0:      	adrp	x16, 0x10c6000
 1046fe4:      	ldr	x17, [x16, #0xd30]
 1046fe8:      	add	x16, x16, #0xd30
 1046fec:      	br	x17

0000000001046ff0 <glUniformMatrix2fv@plt>:
 1046ff0:      	adrp	x16, 0x10c6000
 1046ff4:      	ldr	x17, [x16, #0xd38]
 1046ff8:      	add	x16, x16, #0xd38
 1046ffc:      	br	x17

0000000001047000 <glActiveTexture@plt>:
 1047000:      	adrp	x16, 0x10c6000
 1047004:      	ldr	x17, [x16, #0xd40]
 1047008:      	add	x16, x16, #0xd40
 104700c:      	br	x17

0000000001047010 <glUniform3f@plt>:
 1047010:      	adrp	x16, 0x10c6000
 1047014:      	ldr	x17, [x16, #0xd48]
 1047018:      	add	x16, x16, #0xd48
 104701c:      	br	x17

0000000001047020 <glGetFloatv@plt>:
 1047020:      	adrp	x16, 0x10c6000
 1047024:      	ldr	x17, [x16, #0xd50]
 1047028:      	add	x16, x16, #0xd50
 104702c:      	br	x17

0000000001047030 <glBlendColor@plt>:
 1047030:      	adrp	x16, 0x10c6000
 1047034:      	ldr	x17, [x16, #0xd58]
 1047038:      	add	x16, x16, #0xd58
 104703c:      	br	x17

0000000001047040 <glGetActiveAttrib@plt>:
 1047040:      	adrp	x16, 0x10c6000
 1047044:      	ldr	x17, [x16, #0xd60]
 1047048:      	add	x16, x16, #0xd60
 104704c:      	br	x17

0000000001047050 <glGenBuffers@plt>:
 1047050:      	adrp	x16, 0x10c6000
 1047054:      	ldr	x17, [x16, #0xd68]
 1047058:      	add	x16, x16, #0xd68
 104705c:      	br	x17

0000000001047060 <glGetProgramiv@plt>:
 1047060:      	adrp	x16, 0x10c6000
 1047064:      	ldr	x17, [x16, #0xd70]
 1047068:      	add	x16, x16, #0xd70
 104706c:      	br	x17

0000000001047070 <glGetBooleanv@plt>:
 1047070:      	adrp	x16, 0x10c6000
 1047074:      	ldr	x17, [x16, #0xd78]
 1047078:      	add	x16, x16, #0xd78
 104707c:      	br	x17

0000000001047080 <glGetUniformLocation@plt>:
 1047080:      	adrp	x16, 0x10c6000
 1047084:      	ldr	x17, [x16, #0xd80]
 1047088:      	add	x16, x16, #0xd80
 104708c:      	br	x17

0000000001047090 <glIsTexture@plt>:
 1047090:      	adrp	x16, 0x10c6000
 1047094:      	ldr	x17, [x16, #0xd88]
 1047098:      	add	x16, x16, #0xd88
 104709c:      	br	x17

00000000010470a0 <glTexSubImage2D@plt>:
 10470a0:      	adrp	x16, 0x10c6000
 10470a4:      	ldr	x17, [x16, #0xd90]
 10470a8:      	add	x16, x16, #0xd90
 10470ac:      	br	x17

00000000010470b0 <glUniform2fv@plt>:
 10470b0:      	adrp	x16, 0x10c6000
 10470b4:      	ldr	x17, [x16, #0xd98]
 10470b8:      	add	x16, x16, #0xd98
 10470bc:      	br	x17

00000000010470c0 <glCreateShader@plt>:
 10470c0:      	adrp	x16, 0x10c6000
 10470c4:      	ldr	x17, [x16, #0xda0]
 10470c8:      	add	x16, x16, #0xda0
 10470cc:      	br	x17

00000000010470d0 <glDeleteTextures@plt>:
 10470d0:      	adrp	x16, 0x10c6000
 10470d4:      	ldr	x17, [x16, #0xda8]
 10470d8:      	add	x16, x16, #0xda8
 10470dc:      	br	x17

00000000010470e0 <glFrontFace@plt>:
 10470e0:      	adrp	x16, 0x10c6000
 10470e4:      	ldr	x17, [x16, #0xdb0]
 10470e8:      	add	x16, x16, #0xdb0
 10470ec:      	br	x17

00000000010470f0 <glGenTextures@plt>:
 10470f0:      	adrp	x16, 0x10c6000
 10470f4:      	ldr	x17, [x16, #0xdb8]
 10470f8:      	add	x16, x16, #0xdb8
 10470fc:      	br	x17

0000000001047100 <glBlendFunc@plt>:
 1047100:      	adrp	x16, 0x10c6000
 1047104:      	ldr	x17, [x16, #0xdc0]
 1047108:      	add	x16, x16, #0xdc0
 104710c:      	br	x17

0000000001047110 <glDepthFunc@plt>:
 1047110:      	adrp	x16, 0x10c6000
 1047114:      	ldr	x17, [x16, #0xdc8]
 1047118:      	add	x16, x16, #0xdc8
 104711c:      	br	x17

0000000001047120 <glDrawElements@plt>:
 1047120:      	adrp	x16, 0x10c6000
 1047124:      	ldr	x17, [x16, #0xdd0]
 1047128:      	add	x16, x16, #0xdd0
 104712c:      	br	x17

0000000001047130 <glReadPixels@plt>:
 1047130:      	adrp	x16, 0x10c6000
 1047134:      	ldr	x17, [x16, #0xdd8]
 1047138:      	add	x16, x16, #0xdd8
 104713c:      	br	x17

0000000001047140 <glDeleteShader@plt>:
 1047140:      	adrp	x16, 0x10c6000
 1047144:      	ldr	x17, [x16, #0xde0]
 1047148:      	add	x16, x16, #0xde0
 104714c:      	br	x17

0000000001047150 <glDepthMask@plt>:
 1047150:      	adrp	x16, 0x10c6000
 1047154:      	ldr	x17, [x16, #0xde8]
 1047158:      	add	x16, x16, #0xde8
 104715c:      	br	x17

0000000001047160 <glIsEnabled@plt>:
 1047160:      	adrp	x16, 0x10c6000
 1047164:      	ldr	x17, [x16, #0xdf0]
 1047168:      	add	x16, x16, #0xdf0
 104716c:      	br	x17

0000000001047170 <glDeleteBuffers@plt>:
 1047170:      	adrp	x16, 0x10c6000
 1047174:      	ldr	x17, [x16, #0xdf8]
 1047178:      	add	x16, x16, #0xdf8
 104717c:      	br	x17

0000000001047180 <glFinish@plt>:
 1047180:      	adrp	x16, 0x10c6000
 1047184:      	ldr	x17, [x16, #0xe00]
 1047188:      	add	x16, x16, #0xe00
 104718c:      	br	x17

0000000001047190 <glDisable@plt>:
 1047190:      	adrp	x16, 0x10c6000
 1047194:      	ldr	x17, [x16, #0xe08]
 1047198:      	add	x16, x16, #0xe08
 104719c:      	br	x17

00000000010471a0 <glPixelStorei@plt>:
 10471a0:      	adrp	x16, 0x10c6000
 10471a4:      	ldr	x17, [x16, #0xe10]
 10471a8:      	add	x16, x16, #0xe10
 10471ac:      	br	x17

00000000010471b0 <glStencilFunc@plt>:
 10471b0:      	adrp	x16, 0x10c6000
 10471b4:      	ldr	x17, [x16, #0xe18]
 10471b8:      	add	x16, x16, #0xe18
 10471bc:      	br	x17

00000000010471c0 <glUseProgram@plt>:
 10471c0:      	adrp	x16, 0x10c6000
 10471c4:      	ldr	x17, [x16, #0xe20]
 10471c8:      	add	x16, x16, #0xe20
 10471cc:      	br	x17

00000000010471d0 <glDeleteRenderbuffers@plt>:
 10471d0:      	adrp	x16, 0x10c6000
 10471d4:      	ldr	x17, [x16, #0xe28]
 10471d8:      	add	x16, x16, #0xe28
 10471dc:      	br	x17

00000000010471e0 <glStencilMask@plt>:
 10471e0:      	adrp	x16, 0x10c6000
 10471e4:      	ldr	x17, [x16, #0xe30]
 10471e8:      	add	x16, x16, #0xe30
 10471ec:      	br	x17

00000000010471f0 <glUniform1iv@plt>:
 10471f0:      	adrp	x16, 0x10c6000
 10471f4:      	ldr	x17, [x16, #0xe38]
 10471f8:      	add	x16, x16, #0xe38
 10471fc:      	br	x17

0000000001047200 <glUniform2f@plt>:
 1047200:      	adrp	x16, 0x10c6000
 1047204:      	ldr	x17, [x16, #0xe40]
 1047208:      	add	x16, x16, #0xe40
 104720c:      	br	x17

0000000001047210 <glCheckFramebufferStatus@plt>:
 1047210:      	adrp	x16, 0x10c6000
 1047214:      	ldr	x17, [x16, #0xe48]
 1047218:      	add	x16, x16, #0xe48
 104721c:      	br	x17

0000000001047220 <glUniform1fv@plt>:
 1047220:      	adrp	x16, 0x10c6000
 1047224:      	ldr	x17, [x16, #0xe50]
 1047228:      	add	x16, x16, #0xe50
 104722c:      	br	x17

0000000001047230 <glClearColor@plt>:
 1047230:      	adrp	x16, 0x10c6000
 1047234:      	ldr	x17, [x16, #0xe58]
 1047238:      	add	x16, x16, #0xe58
 104723c:      	br	x17

0000000001047240 <glTexParameterf@plt>:
 1047240:      	adrp	x16, 0x10c6000
 1047244:      	ldr	x17, [x16, #0xe60]
 1047248:      	add	x16, x16, #0xe60
 104724c:      	br	x17

0000000001047250 <glClear@plt>:
 1047250:      	adrp	x16, 0x10c6000
 1047254:      	ldr	x17, [x16, #0xe68]
 1047258:      	add	x16, x16, #0xe68
 104725c:      	br	x17

0000000001047260 <glCullFace@plt>:
 1047260:      	adrp	x16, 0x10c6000
 1047264:      	ldr	x17, [x16, #0xe70]
 1047268:      	add	x16, x16, #0xe70
 104726c:      	br	x17

0000000001047270 <glFramebufferRenderbuffer@plt>:
 1047270:      	adrp	x16, 0x10c6000
 1047274:      	ldr	x17, [x16, #0xe78]
 1047278:      	add	x16, x16, #0xe78
 104727c:      	br	x17

0000000001047280 <glGetShaderInfoLog@plt>:
 1047280:      	adrp	x16, 0x10c6000
 1047284:      	ldr	x17, [x16, #0xe80]
 1047288:      	add	x16, x16, #0xe80
 104728c:      	br	x17

0000000001047290 <glStencilOp@plt>:
 1047290:      	adrp	x16, 0x10c6000
 1047294:      	ldr	x17, [x16, #0xe88]
 1047298:      	add	x16, x16, #0xe88
 104729c:      	br	x17

00000000010472a0 <glUniform2i@plt>:
 10472a0:      	adrp	x16, 0x10c6000
 10472a4:      	ldr	x17, [x16, #0xe90]
 10472a8:      	add	x16, x16, #0xe90
 10472ac:      	br	x17

00000000010472b0 <glClearBufferfv@plt>:
 10472b0:      	adrp	x16, 0x10c6000
 10472b4:      	ldr	x17, [x16, #0xe98]
 10472b8:      	add	x16, x16, #0xe98
 10472bc:      	br	x17

00000000010472c0 <glVertexAttribDivisor@plt>:
 10472c0:      	adrp	x16, 0x10c6000
 10472c4:      	ldr	x17, [x16, #0xea0]
 10472c8:      	add	x16, x16, #0xea0
 10472cc:      	br	x17

00000000010472d0 <glBlitFramebuffer@plt>:
 10472d0:      	adrp	x16, 0x10c6000
 10472d4:      	ldr	x17, [x16, #0xea8]
 10472d8:      	add	x16, x16, #0xea8
 10472dc:      	br	x17

00000000010472e0 <glGenVertexArrays@plt>:
 10472e0:      	adrp	x16, 0x10c6000
 10472e4:      	ldr	x17, [x16, #0xeb0]
 10472e8:      	add	x16, x16, #0xeb0
 10472ec:      	br	x17

00000000010472f0 <glDeleteVertexArrays@plt>:
 10472f0:      	adrp	x16, 0x10c6000
 10472f4:      	ldr	x17, [x16, #0xeb8]
 10472f8:      	add	x16, x16, #0xeb8
 10472fc:      	br	x17

0000000001047300 <glWaitSync@plt>:
 1047300:      	adrp	x16, 0x10c6000
 1047304:      	ldr	x17, [x16, #0xec0]
 1047308:      	add	x16, x16, #0xec0
 104730c:      	br	x17

0000000001047310 <glDrawElementsInstanced@plt>:
 1047310:      	adrp	x16, 0x10c6000
 1047314:      	ldr	x17, [x16, #0xec8]
 1047318:      	add	x16, x16, #0xec8
 104731c:      	br	x17

0000000001047320 <glRenderbufferStorageMultisample@plt>:
 1047320:      	adrp	x16, 0x10c6000
 1047324:      	ldr	x17, [x16, #0xed0]
 1047328:      	add	x16, x16, #0xed0
 104732c:      	br	x17

0000000001047330 <glInvalidateFramebuffer@plt>:
 1047330:      	adrp	x16, 0x10c6000
 1047334:      	ldr	x17, [x16, #0xed8]
 1047338:      	add	x16, x16, #0xed8
 104733c:      	br	x17

0000000001047340 <glTexImage3D@plt>:
 1047340:      	adrp	x16, 0x10c6000
 1047344:      	ldr	x17, [x16, #0xee0]
 1047348:      	add	x16, x16, #0xee0
 104734c:      	br	x17

0000000001047350 <glMapBufferRange@plt>:
 1047350:      	adrp	x16, 0x10c6000
 1047354:      	ldr	x17, [x16, #0xee8]
 1047358:      	add	x16, x16, #0xee8
 104735c:      	br	x17

0000000001047360 <glBindVertexArray@plt>:
 1047360:      	adrp	x16, 0x10c6000
 1047364:      	ldr	x17, [x16, #0xef0]
 1047368:      	add	x16, x16, #0xef0
 104736c:      	br	x17

0000000001047370 <glDeleteSync@plt>:
 1047370:      	adrp	x16, 0x10c6000
 1047374:      	ldr	x17, [x16, #0xef8]
 1047378:      	add	x16, x16, #0xef8
 104737c:      	br	x17

0000000001047380 <glFenceSync@plt>:
 1047380:      	adrp	x16, 0x10c6000
 1047384:      	ldr	x17, [x16, #0xf00]
 1047388:      	add	x16, x16, #0xf00
 104738c:      	br	x17

0000000001047390 <glVertexAttribIPointer@plt>:
 1047390:      	adrp	x16, 0x10c6000
 1047394:      	ldr	x17, [x16, #0xf08]
 1047398:      	add	x16, x16, #0xf08
 104739c:      	br	x17

00000000010473a0 <glUnmapBuffer@plt>:
 10473a0:      	adrp	x16, 0x10c6000
 10473a4:      	ldr	x17, [x16, #0xf10]
 10473a8:      	add	x16, x16, #0xf10
 10473ac:      	br	x17

00000000010473b0 <glDrawBuffers@plt>:
 10473b0:      	adrp	x16, 0x10c6000
 10473b4:      	ldr	x17, [x16, #0xf18]
 10473b8:      	add	x16, x16, #0xf18
 10473bc:      	br	x17

00000000010473c0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
 10473c0:      	adrp	x16, 0x10c6000
 10473c4:      	ldr	x17, [x16, #0xf20]
 10473c8:      	add	x16, x16, #0xf20
 10473cc:      	br	x17

00000000010473d0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv@plt>:
 10473d0:      	adrp	x16, 0x10c6000
 10473d4:      	ldr	x17, [x16, #0xf28]
 10473d8:      	add	x16, x16, #0xf28
 10473dc:      	br	x17

00000000010473e0 <_ZNSt6__ndk15mutexD1Ev@plt>:
 10473e0:      	adrp	x16, 0x10c6000
 10473e4:      	ldr	x17, [x16, #0xf30]
 10473e8:      	add	x16, x16, #0xf30
 10473ec:      	br	x17

00000000010473f0 <_ZNSt6__ndk19to_stringEf@plt>:
 10473f0:      	adrp	x16, 0x10c6000
 10473f4:      	ldr	x17, [x16, #0xf38]
 10473f8:      	add	x16, x16, #0xf38
 10473fc:      	br	x17

0000000001047400 <_ZNSt13runtime_errorD2Ev@plt>:
 1047400:      	adrp	x16, 0x10c6000
 1047404:      	ldr	x17, [x16, #0xf40]
 1047408:      	add	x16, x16, #0xf40
 104740c:      	br	x17

0000000001047410 <_ZNSt6__ndk19to_stringEi@plt>:
 1047410:      	adrp	x16, 0x10c6000
 1047414:      	ldr	x17, [x16, #0xf48]
 1047418:      	add	x16, x16, #0xf48
 104741c:      	br	x17

0000000001047420 <_ZNSt6__ndk19to_stringEj@plt>:
 1047420:      	adrp	x16, 0x10c6000
 1047424:      	ldr	x17, [x16, #0xf50]
 1047428:      	add	x16, x16, #0xf50
 104742c:      	br	x17

0000000001047430 <_ZNSt6__ndk19to_stringEm@plt>:
 1047430:      	adrp	x16, 0x10c6000
 1047434:      	ldr	x17, [x16, #0xf58]
 1047438:      	add	x16, x16, #0xf58
 104743c:      	br	x17

0000000001047440 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
 1047440:      	adrp	x16, 0x10c6000
 1047444:      	ldr	x17, [x16, #0xf60]
 1047448:      	add	x16, x16, #0xf60
 104744c:      	br	x17

0000000001047450 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm@plt>:
 1047450:      	adrp	x16, 0x10c6000
 1047454:      	ldr	x17, [x16, #0xf68]
 1047458:      	add	x16, x16, #0xf68
 104745c:      	br	x17

0000000001047460 <_ZNSt6__ndk113random_deviceD1Ev@plt>:
 1047460:      	adrp	x16, 0x10c6000
 1047464:      	ldr	x17, [x16, #0xf70]
 1047468:      	add	x16, x16, #0xf70
 104746c:      	br	x17

0000000001047470 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5writeEPKwl@plt>:
 1047470:      	adrp	x16, 0x10c6000
 1047474:      	ldr	x17, [x16, #0xf78]
 1047478:      	add	x16, x16, #0xf78
 104747c:      	br	x17

0000000001047480 <_ZnwmRKSt9nothrow_t@plt>:
 1047480:      	adrp	x16, 0x10c6000
 1047484:      	ldr	x17, [x16, #0xf80]
 1047488:      	add	x16, x16, #0xf80
 104748c:      	br	x17

0000000001047490 <_ZNSt6__ndk14stofERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPm@plt>:
 1047490:      	adrp	x16, 0x10c6000
 1047494:      	ldr	x17, [x16, #0xf88]
 1047498:      	add	x16, x16, #0xf88
 104749c:      	br	x17

00000000010474a0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
 10474a0:      	adrp	x16, 0x10c6000
 10474a4:      	ldr	x17, [x16, #0xf90]
 10474a8:      	add	x16, x16, #0xf90
 10474ac:      	br	x17

00000000010474b0 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
 10474b0:      	adrp	x16, 0x10c6000
 10474b4:      	ldr	x17, [x16, #0xf98]
 10474b8:      	add	x16, x16, #0xf98
 10474bc:      	br	x17

00000000010474c0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
 10474c0:      	adrp	x16, 0x10c6000
 10474c4:      	ldr	x17, [x16, #0xfa0]
 10474c8:      	add	x16, x16, #0xfa0
 10474cc:      	br	x17

00000000010474d0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
 10474d0:      	adrp	x16, 0x10c6000
 10474d4:      	ldr	x17, [x16, #0xfa8]
 10474d8:      	add	x16, x16, #0xfa8
 10474dc:      	br	x17

00000000010474e0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
 10474e0:      	adrp	x16, 0x10c6000
 10474e4:      	ldr	x17, [x16, #0xfb0]
 10474e8:      	add	x16, x16, #0xfb0
 10474ec:      	br	x17

00000000010474f0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
 10474f0:      	adrp	x16, 0x10c6000
 10474f4:      	ldr	x17, [x16, #0xfb8]
 10474f8:      	add	x16, x16, #0xfb8
 10474fc:      	br	x17

0000000001047500 <_ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
 1047500:      	adrp	x16, 0x10c6000
 1047504:      	ldr	x17, [x16, #0xfc0]
 1047508:      	add	x16, x16, #0xfc0
 104750c:      	br	x17

0000000001047510 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE2atEm@plt>:
 1047510:      	adrp	x16, 0x10c6000
 1047514:      	ldr	x17, [x16, #0xfc8]
 1047518:      	add	x16, x16, #0xfc8
 104751c:      	br	x17

0000000001047520 <_ZNSt6__ndk16futureIvE3getEv@plt>:
 1047520:      	adrp	x16, 0x10c6000
 1047524:      	ldr	x17, [x16, #0xfd0]
 1047528:      	add	x16, x16, #0xfd0
 104752c:      	br	x17

0000000001047530 <_ZNSt6__ndk16__sortIRNS_6__lessIffEEPfEEvT0_S5_T_@plt>:
 1047530:      	adrp	x16, 0x10c6000
 1047534:      	ldr	x17, [x16, #0xfd8]
 1047538:      	add	x16, x16, #0xfd8
 104753c:      	br	x17

0000000001047540 <_ZNSt6__ndk17promiseIvEC1Ev@plt>:
 1047540:      	adrp	x16, 0x10c6000
 1047544:      	ldr	x17, [x16, #0xfe0]
 1047548:      	add	x16, x16, #0xfe0
 104754c:      	br	x17

0000000001047550 <_ZNSt11logic_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
 1047550:      	adrp	x16, 0x10c6000
 1047554:      	ldr	x17, [x16, #0xfe8]
 1047558:      	add	x16, x16, #0xfe8
 104755c:      	br	x17

0000000001047560 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
 1047560:      	adrp	x16, 0x10c6000
 1047564:      	ldr	x17, [x16, #0xff0]
 1047568:      	add	x16, x16, #0xff0
 104756c:      	br	x17

0000000001047570 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
 1047570:      	adrp	x16, 0x10c6000
 1047574:      	ldr	x17, [x16, #0xff8]
 1047578:      	add	x16, x16, #0xff8
 104757c:      	br	x17

0000000001047580 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
 1047580:      	adrp	x16, 0x10c7000
 1047584:      	ldr	x17, [x16]
 1047588:      	add	x16, x16, #0x0
 104758c:      	br	x17

0000000001047590 <_ZNSt6__ndk16futureIvED1Ev@plt>:
 1047590:      	adrp	x16, 0x10c7000
 1047594:      	ldr	x17, [x16, #0x8]
 1047598:      	add	x16, x16, #0x8
 104759c:      	br	x17

00000000010475a0 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
 10475a0:      	adrp	x16, 0x10c7000
 10475a4:      	ldr	x17, [x16, #0x10]
 10475a8:      	add	x16, x16, #0x10
 10475ac:      	br	x17

00000000010475b0 <_ZNSt6__ndk117__assoc_sub_state10__sub_waitERNS_11unique_lockINS_5mutexEEE@plt>:
 10475b0:      	adrp	x16, 0x10c7000
 10475b4:      	ldr	x17, [x16, #0x18]
 10475b8:      	add	x16, x16, #0x18
 10475bc:      	br	x17

00000000010475c0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
 10475c0:      	adrp	x16, 0x10c7000
 10475c4:      	ldr	x17, [x16, #0x20]
 10475c8:      	add	x16, x16, #0x20
 10475cc:      	br	x17

00000000010475d0 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
 10475d0:      	adrp	x16, 0x10c7000
 10475d4:      	ldr	x17, [x16, #0x28]
 10475d8:      	add	x16, x16, #0x28
 10475dc:      	br	x17

00000000010475e0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
 10475e0:      	adrp	x16, 0x10c7000
 10475e4:      	ldr	x17, [x16, #0x30]
 10475e8:      	add	x16, x16, #0x30
 10475ec:      	br	x17

00000000010475f0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEv@plt>:
 10475f0:      	adrp	x16, 0x10c7000
 10475f4:      	ldr	x17, [x16, #0x38]
 10475f8:      	add	x16, x16, #0x38
 10475fc:      	br	x17

0000000001047600 <_ZNSt13runtime_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
 1047600:      	adrp	x16, 0x10c7000
 1047604:      	ldr	x17, [x16, #0x40]
 1047608:      	add	x16, x16, #0x40
 104760c:      	br	x17

0000000001047610 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
 1047610:      	adrp	x16, 0x10c7000
 1047614:      	ldr	x17, [x16, #0x48]
 1047618:      	add	x16, x16, #0x48
 104761c:      	br	x17

0000000001047620 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl@plt>:
 1047620:      	adrp	x16, 0x10c7000
 1047624:      	ldr	x17, [x16, #0x50]
 1047628:      	add	x16, x16, #0x50
 104762c:      	br	x17

0000000001047630 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
 1047630:      	adrp	x16, 0x10c7000
 1047634:      	ldr	x17, [x16, #0x58]
 1047638:      	add	x16, x16, #0x58
 104763c:      	br	x17

0000000001047640 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
 1047640:      	adrp	x16, 0x10c7000
 1047644:      	ldr	x17, [x16, #0x60]
 1047648:      	add	x16, x16, #0x60
 104764c:      	br	x17

0000000001047650 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
 1047650:      	adrp	x16, 0x10c7000
 1047654:      	ldr	x17, [x16, #0x68]
 1047658:      	add	x16, x16, #0x68
 104765c:      	br	x17

0000000001047660 <_ZnamRKSt9nothrow_t@plt>:
 1047660:      	adrp	x16, 0x10c7000
 1047664:      	ldr	x17, [x16, #0x70]
 1047668:      	add	x16, x16, #0x70
 104766c:      	br	x17

0000000001047670 <__cxa_end_catch@plt>:
 1047670:      	adrp	x16, 0x10c7000
 1047674:      	ldr	x17, [x16, #0x78]
 1047678:      	add	x16, x16, #0x78
 104767c:      	br	x17

0000000001047680 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
 1047680:      	adrp	x16, 0x10c7000
 1047684:      	ldr	x17, [x16, #0x80]
 1047688:      	add	x16, x16, #0x80
 104768c:      	br	x17

0000000001047690 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
 1047690:      	adrp	x16, 0x10c7000
 1047694:      	ldr	x17, [x16, #0x88]
 1047698:      	add	x16, x16, #0x88
 104769c:      	br	x17

00000000010476a0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
 10476a0:      	adrp	x16, 0x10c7000
 10476a4:      	ldr	x17, [x16, #0x90]
 10476a8:      	add	x16, x16, #0x90
 10476ac:      	br	x17

00000000010476b0 <_ZNSt13runtime_errorC2EPKc@plt>:
 10476b0:      	adrp	x16, 0x10c7000
 10476b4:      	ldr	x17, [x16, #0x98]
 10476b8:      	add	x16, x16, #0x98
 10476bc:      	br	x17

00000000010476c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
 10476c0:      	adrp	x16, 0x10c7000
 10476c4:      	ldr	x17, [x16, #0xa0]
 10476c8:      	add	x16, x16, #0xa0
 10476cc:      	br	x17

00000000010476d0 <_ZNSt6__ndk16localeC1Ev@plt>:
 10476d0:      	adrp	x16, 0x10c7000
 10476d4:      	ldr	x17, [x16, #0xa8]
 10476d8:      	add	x16, x16, #0xa8
 10476dc:      	br	x17

00000000010476e0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
 10476e0:      	adrp	x16, 0x10c7000
 10476e4:      	ldr	x17, [x16, #0xb0]
 10476e8:      	add	x16, x16, #0xb0
 10476ec:      	br	x17

00000000010476f0 <_ZNSt6__ndk16thread20hardware_concurrencyEv@plt>:
 10476f0:      	adrp	x16, 0x10c7000
 10476f4:      	ldr	x17, [x16, #0xb8]
 10476f8:      	add	x16, x16, #0xb8
 10476fc:      	br	x17

0000000001047700 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
 1047700:      	adrp	x16, 0x10c7000
 1047704:      	ldr	x17, [x16, #0xc0]
 1047708:      	add	x16, x16, #0xc0
 104770c:      	br	x17

0000000001047710 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
 1047710:      	adrp	x16, 0x10c7000
 1047714:      	ldr	x17, [x16, #0xc8]
 1047718:      	add	x16, x16, #0xc8
 104771c:      	br	x17

0000000001047720 <_ZNSt6__ndk15mutex8try_lockEv@plt>:
 1047720:      	adrp	x16, 0x10c7000
 1047724:      	ldr	x17, [x16, #0xd0]
 1047728:      	add	x16, x16, #0xd0
 104772c:      	br	x17

0000000001047730 <_ZNSt6__ndk17promiseIvE9set_valueEv@plt>:
 1047730:      	adrp	x16, 0x10c7000
 1047734:      	ldr	x17, [x16, #0xd8]
 1047738:      	add	x16, x16, #0xd8
 104773c:      	br	x17

0000000001047740 <_ZNSt6__ndk114basic_ifstreamIcNS_11char_traitsIcEEE4openEPKcj@plt>:
 1047740:      	adrp	x16, 0x10c7000
 1047744:      	ldr	x17, [x16, #0xe0]
 1047748:      	add	x16, x16, #0xe0
 104774c:      	br	x17

0000000001047750 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendERKS5_mm@plt>:
 1047750:      	adrp	x16, 0x10c7000
 1047754:      	ldr	x17, [x16, #0xe8]
 1047758:      	add	x16, x16, #0xe8
 104775c:      	br	x17

0000000001047760 <_ZNSt9bad_allocC1Ev@plt>:
 1047760:      	adrp	x16, 0x10c7000
 1047764:      	ldr	x17, [x16, #0xf0]
 1047768:      	add	x16, x16, #0xf0
 104776c:      	br	x17

0000000001047770 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPclc@plt>:
 1047770:      	adrp	x16, 0x10c7000
 1047774:      	ldr	x17, [x16, #0xf8]
 1047778:      	add	x16, x16, #0xf8
 104777c:      	br	x17

0000000001047780 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
 1047780:      	adrp	x16, 0x10c7000
 1047784:      	ldr	x17, [x16, #0x100]
 1047788:      	add	x16, x16, #0x100
 104778c:      	br	x17

0000000001047790 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKc@plt>:
 1047790:      	adrp	x16, 0x10c7000
 1047794:      	ldr	x17, [x16, #0x108]
 1047798:      	add	x16, x16, #0x108
 104779c:      	br	x17

00000000010477a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
 10477a0:      	adrp	x16, 0x10c7000
 10477a4:      	ldr	x17, [x16, #0x110]
 10477a8:      	add	x16, x16, #0x110
 10477ac:      	br	x17

00000000010477b0 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
 10477b0:      	adrp	x16, 0x10c7000
 10477b4:      	ldr	x17, [x16, #0x118]
 10477b8:      	add	x16, x16, #0x118
 10477bc:      	br	x17

00000000010477c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
 10477c0:      	adrp	x16, 0x10c7000
 10477c4:      	ldr	x17, [x16, #0x120]
 10477c8:      	add	x16, x16, #0x120
 10477cc:      	br	x17

00000000010477d0 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
 10477d0:      	adrp	x16, 0x10c7000
 10477d4:      	ldr	x17, [x16, #0x128]
 10477d8:      	add	x16, x16, #0x128
 10477dc:      	br	x17

00000000010477e0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
 10477e0:      	adrp	x16, 0x10c7000
 10477e4:      	ldr	x17, [x16, #0x130]
 10477e8:      	add	x16, x16, #0x130
 10477ec:      	br	x17

00000000010477f0 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
 10477f0:      	adrp	x16, 0x10c7000
 10477f4:      	ldr	x17, [x16, #0x138]
 10477f8:      	add	x16, x16, #0x138
 10477fc:      	br	x17

0000000001047800 <_ZNSt6__ndk115__get_classnameEPKcb@plt>:
 1047800:      	adrp	x16, 0x10c7000
 1047804:      	ldr	x17, [x16, #0x140]
 1047808:      	add	x16, x16, #0x140
 104780c:      	br	x17

0000000001047810 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
 1047810:      	adrp	x16, 0x10c7000
 1047814:      	ldr	x17, [x16, #0x148]
 1047818:      	add	x16, x16, #0x148
 104781c:      	br	x17

0000000001047820 <_ZNSt13exception_ptrC1ERKS_@plt>:
 1047820:      	adrp	x16, 0x10c7000
 1047824:      	ldr	x17, [x16, #0x150]
 1047828:      	add	x16, x16, #0x150
 104782c:      	br	x17

0000000001047830 <_ZNSt6__ndk16localeaSERKS0_@plt>:
 1047830:      	adrp	x16, 0x10c7000
 1047834:      	ldr	x17, [x16, #0x158]
 1047838:      	add	x16, x16, #0x158
 104783c:      	br	x17

0000000001047840 <_ZNSt6__ndk16__sortIRNS_6__lessIllEEPlEEvT0_S5_T_@plt>:
 1047840:      	adrp	x16, 0x10c7000
 1047844:      	ldr	x17, [x16, #0x160]
 1047848:      	add	x16, x16, #0x160
 104784c:      	br	x17

0000000001047850 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERb@plt>:
 1047850:      	adrp	x16, 0x10c7000
 1047854:      	ldr	x17, [x16, #0x168]
 1047858:      	add	x16, x16, #0x168
 104785c:      	br	x17

0000000001047860 <_ZNSt6__ndk120__get_collation_nameEPKc@plt>:
 1047860:      	adrp	x16, 0x10c7000
 1047864:      	ldr	x17, [x16, #0x170]
 1047868:      	add	x16, x16, #0x170
 104786c:      	br	x17

0000000001047870 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf@plt>:
 1047870:      	adrp	x16, 0x10c7000
 1047874:      	ldr	x17, [x16, #0x178]
 1047878:      	add	x16, x16, #0x178
 104787c:      	br	x17

0000000001047880 <_ZNSt6__ndk114__shared_countD2Ev@plt>:
 1047880:      	adrp	x16, 0x10c7000
 1047884:      	ldr	x17, [x16, #0x180]
 1047888:      	add	x16, x16, #0x180
 104788c:      	br	x17

0000000001047890 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi@plt>:
 1047890:      	adrp	x16, 0x10c7000
 1047894:      	ldr	x17, [x16, #0x188]
 1047898:      	add	x16, x16, #0x188
 104789c:      	br	x17

00000000010478a0 <_ZdlPvRKSt9nothrow_t@plt>:
 10478a0:      	adrp	x16, 0x10c7000
 10478a4:      	ldr	x17, [x16, #0x190]
 10478a8:      	add	x16, x16, #0x190
 10478ac:      	br	x17

00000000010478b0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERt@plt>:
 10478b0:      	adrp	x16, 0x10c7000
 10478b4:      	ldr	x17, [x16, #0x198]
 10478b8:      	add	x16, x16, #0x198
 10478bc:      	br	x17

00000000010478c0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
 10478c0:      	adrp	x16, 0x10c7000
 10478c4:      	ldr	x17, [x16, #0x1a0]
 10478c8:      	add	x16, x16, #0x1a0
 10478cc:      	br	x17

00000000010478d0 <_ZNSt6__ndk16locale7classicEv@plt>:
 10478d0:      	adrp	x16, 0x10c7000
 10478d4:      	ldr	x17, [x16, #0x1a8]
 10478d8:      	add	x16, x16, #0x1a8
 10478dc:      	br	x17

00000000010478e0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
 10478e0:      	adrp	x16, 0x10c7000
 10478e4:      	ldr	x17, [x16, #0x1b0]
 10478e8:      	add	x16, x16, #0x1b0
 10478ec:      	br	x17

00000000010478f0 <_ZNSt6__ndk18ios_base5clearEj@plt>:
 10478f0:      	adrp	x16, 0x10c7000
 10478f4:      	ldr	x17, [x16, #0x1b8]
 10478f8:      	add	x16, x16, #0x1b8
 10478fc:      	br	x17

0000000001047900 <_ZNSt6__ndk18ios_base4initEPv@plt>:
 1047900:      	adrp	x16, 0x10c7000
 1047904:      	ldr	x17, [x16, #0x1c0]
 1047908:      	add	x16, x16, #0x1c0
 104790c:      	br	x17

0000000001047910 <_ZNSt6__ndk17promiseIvED1Ev@plt>:
 1047910:      	adrp	x16, 0x10c7000
 1047914:      	ldr	x17, [x16, #0x1c8]
 1047918:      	add	x16, x16, #0x1c8
 104791c:      	br	x17

0000000001047920 <_ZNSt13exception_ptrD1Ev@plt>:
 1047920:      	adrp	x16, 0x10c7000
 1047924:      	ldr	x17, [x16, #0x1d0]
 1047928:      	add	x16, x16, #0x1d0
 104792c:      	br	x17

0000000001047930 <_ZNSt6__ndk17promiseIvE10get_futureEv@plt>:
 1047930:      	adrp	x16, 0x10c7000
 1047934:      	ldr	x17, [x16, #0x1d8]
 1047938:      	add	x16, x16, #0x1d8
 104793c:      	br	x17

0000000001047940 <_ZNSt6__ndk18ios_base5imbueERKNS_6localeE@plt>:
 1047940:      	adrp	x16, 0x10c7000
 1047944:      	ldr	x17, [x16, #0x1e0]
 1047948:      	add	x16, x16, #0x1e0
 104794c:      	br	x17

0000000001047950 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb@plt>:
 1047950:      	adrp	x16, 0x10c7000
 1047954:      	ldr	x17, [x16, #0x1e8]
 1047958:      	add	x16, x16, #0x1e8
 104795c:      	br	x17

0000000001047960 <_ZNSt6__ndk16thread4joinEv@plt>:
 1047960:      	adrp	x16, 0x10c7000
 1047964:      	ldr	x17, [x16, #0x1f0]
 1047968:      	add	x16, x16, #0x1f0
 104796c:      	br	x17

0000000001047970 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEd@plt>:
 1047970:      	adrp	x16, 0x10c7000
 1047974:      	ldr	x17, [x16, #0x1f8]
 1047978:      	add	x16, x16, #0x1f8
 104797c:      	br	x17

0000000001047980 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv@plt>:
 1047980:      	adrp	x16, 0x10c7000
 1047984:      	ldr	x17, [x16, #0x200]
 1047988:      	add	x16, x16, #0x200
 104798c:      	br	x17

0000000001047990 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf@plt>:
 1047990:      	adrp	x16, 0x10c7000
 1047994:      	ldr	x17, [x16, #0x208]
 1047998:      	add	x16, x16, #0x208
 104799c:      	br	x17

00000000010479a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
 10479a0:      	adrp	x16, 0x10c7000
 10479a4:      	ldr	x17, [x16, #0x210]
 10479a8:      	add	x16, x16, #0x210
 10479ac:      	br	x17

00000000010479b0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
 10479b0:      	adrp	x16, 0x10c7000
 10479b4:      	ldr	x17, [x16, #0x218]
 10479b8:      	add	x16, x16, #0x218
 10479bc:      	br	x17

00000000010479c0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj@plt>:
 10479c0:      	adrp	x16, 0x10c7000
 10479c4:      	ldr	x17, [x16, #0x220]
 10479c8:      	add	x16, x16, #0x220
 10479cc:      	br	x17

00000000010479d0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
 10479d0:      	adrp	x16, 0x10c7000
 10479d4:      	ldr	x17, [x16, #0x228]
 10479d8:      	add	x16, x16, #0x228
 10479dc:      	br	x17

00000000010479e0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm@plt>:
 10479e0:      	adrp	x16, 0x10c7000
 10479e4:      	ldr	x17, [x16, #0x230]
 10479e8:      	add	x16, x16, #0x230
 10479ec:      	br	x17

00000000010479f0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEt@plt>:
 10479f0:      	adrp	x16, 0x10c7000
 10479f4:      	ldr	x17, [x16, #0x238]
 10479f8:      	add	x16, x16, #0x238
 10479fc:      	br	x17

0000000001047a00 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
 1047a00:      	adrp	x16, 0x10c7000
 1047a04:      	ldr	x17, [x16, #0x240]
 1047a08:      	add	x16, x16, #0x240
 1047a0c:      	br	x17

0000000001047a10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEx@plt>:
 1047a10:      	adrp	x16, 0x10c7000
 1047a14:      	ldr	x17, [x16, #0x248]
 1047a18:      	add	x16, x16, #0x248
 1047a1c:      	br	x17

0000000001047a20 <_ZNSt6__ndk16threadD1Ev@plt>:
 1047a20:      	adrp	x16, 0x10c7000
 1047a24:      	ldr	x17, [x16, #0x250]
 1047a28:      	add	x16, x16, #0x250
 1047a2c:      	br	x17

0000000001047a30 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
 1047a30:      	adrp	x16, 0x10c7000
 1047a34:      	ldr	x17, [x16, #0x258]
 1047a38:      	add	x16, x16, #0x258
 1047a3c:      	br	x17

0000000001047a40 <_ZNKSt6__ndk16locale4nameEv@plt>:
 1047a40:      	adrp	x16, 0x10c7000
 1047a44:      	ldr	x17, [x16, #0x260]
 1047a48:      	add	x16, x16, #0x260
 1047a4c:      	br	x17

0000000001047a50 <__cxa_rethrow@plt>:
 1047a50:      	adrp	x16, 0x10c7000
 1047a54:      	ldr	x17, [x16, #0x268]
 1047a58:      	add	x16, x16, #0x268
 1047a5c:      	br	x17

0000000001047a60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc@plt>:
 1047a60:      	adrp	x16, 0x10c7000
 1047a64:      	ldr	x17, [x16, #0x270]
 1047a68:      	add	x16, x16, #0x270
 1047a6c:      	br	x17

0000000001047a70 <_ZNSt6__ndk15mutex6unlockEv@plt>:
 1047a70:      	adrp	x16, 0x10c7000
 1047a74:      	ldr	x17, [x16, #0x278]
 1047a78:      	add	x16, x16, #0x278
 1047a7c:      	br	x17

0000000001047a80 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc@plt>:
 1047a80:      	adrp	x16, 0x10c7000
 1047a84:      	ldr	x17, [x16, #0x280]
 1047a88:      	add	x16, x16, #0x280
 1047a8c:      	br	x17

0000000001047a90 <_ZNSt6__ndk16__sortIRNS_6__lessIiiEEPiEEvT0_S5_T_@plt>:
 1047a90:      	adrp	x16, 0x10c7000
 1047a94:      	ldr	x17, [x16, #0x288]
 1047a98:      	add	x16, x16, #0x288
 1047a9c:      	br	x17

0000000001047aa0 <__emutls_get_address@plt>:
 1047aa0:      	adrp	x16, 0x10c7000
 1047aa4:      	ldr	x17, [x16, #0x290]
 1047aa8:      	add	x16, x16, #0x290
 1047aac:      	br	x17

0000000001047ab0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmmc@plt>:
 1047ab0:      	adrp	x16, 0x10c7000
 1047ab4:      	ldr	x17, [x16, #0x298]
 1047ab8:      	add	x16, x16, #0x298
 1047abc:      	br	x17

0000000001047ac0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE2atEm@plt>:
 1047ac0:      	adrp	x16, 0x10c7000
 1047ac4:      	ldr	x17, [x16, #0x2a0]
 1047ac8:      	add	x16, x16, #0x2a0
 1047acc:      	br	x17

0000000001047ad0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
 1047ad0:      	adrp	x16, 0x10c7000
 1047ad4:      	ldr	x17, [x16, #0x2a8]
 1047ad8:      	add	x16, x16, #0x2a8
 1047adc:      	br	x17

0000000001047ae0 <_ZNSt6__ndk112future_errorC1ENS_10error_codeE@plt>:
 1047ae0:      	adrp	x16, 0x10c7000
 1047ae4:      	ldr	x17, [x16, #0x2b0]
 1047ae8:      	add	x16, x16, #0x2b0
 1047aec:      	br	x17

0000000001047af0 <_ZNSt6__ndk112__next_primeEm@plt>:
 1047af0:      	adrp	x16, 0x10c7000
 1047af4:      	ldr	x17, [x16, #0x2b8]
 1047af8:      	add	x16, x16, #0x2b8
 1047afc:      	br	x17

0000000001047b00 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
 1047b00:      	adrp	x16, 0x10c7000
 1047b04:      	ldr	x17, [x16, #0x2c0]
 1047b08:      	add	x16, x16, #0x2c0
 1047b0c:      	br	x17

0000000001047b10 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
 1047b10:      	adrp	x16, 0x10c7000
 1047b14:      	ldr	x17, [x16, #0x2c8]
 1047b18:      	add	x16, x16, #0x2c8
 1047b1c:      	br	x17

0000000001047b20 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
 1047b20:      	adrp	x16, 0x10c7000
 1047b24:      	ldr	x17, [x16, #0x2d0]
 1047b28:      	add	x16, x16, #0x2d0
 1047b2c:      	br	x17

0000000001047b30 <_ZNSt6__ndk115future_categoryEv@plt>:
 1047b30:      	adrp	x16, 0x10c7000
 1047b34:      	ldr	x17, [x16, #0x2d8]
 1047b38:      	add	x16, x16, #0x2d8
 1047b3c:      	br	x17

0000000001047b40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm@plt>:
 1047b40:      	adrp	x16, 0x10c7000
 1047b44:      	ldr	x17, [x16, #0x2e0]
 1047b48:      	add	x16, x16, #0x2e0
 1047b4c:      	br	x17

0000000001047b50 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
 1047b50:      	adrp	x16, 0x10c7000
 1047b54:      	ldr	x17, [x16, #0x2e8]
 1047b58:      	add	x16, x16, #0x2e8
 1047b5c:      	br	x17

0000000001047b60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
 1047b60:      	adrp	x16, 0x10c7000
 1047b64:      	ldr	x17, [x16, #0x2f0]
 1047b68:      	add	x16, x16, #0x2f0
 1047b6c:      	br	x17

0000000001047b70 <_ZNSt6__ndk113random_deviceC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
 1047b70:      	adrp	x16, 0x10c7000
 1047b74:      	ldr	x17, [x16, #0x2f8]
 1047b78:      	add	x16, x16, #0x2f8
 1047b7c:      	br	x17

0000000001047b80 <_ZNSt6__ndk119__shared_weak_count4lockEv@plt>:
 1047b80:      	adrp	x16, 0x10c7000
 1047b84:      	ldr	x17, [x16, #0x300]
 1047b88:      	add	x16, x16, #0x300
 1047b8c:      	br	x17

0000000001047b90 <_ZNSt6__ndk16localeD1Ev@plt>:
 1047b90:      	adrp	x16, 0x10c7000
 1047b94:      	ldr	x17, [x16, #0x308]
 1047b98:      	add	x16, x16, #0x308
 1047b9c:      	br	x17

0000000001047ba0 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
 1047ba0:      	adrp	x16, 0x10c7000
 1047ba4:      	ldr	x17, [x16, #0x310]
 1047ba8:      	add	x16, x16, #0x310
 1047bac:      	br	x17

0000000001047bb0 <_ZSt17rethrow_exceptionSt13exception_ptr@plt>:
 1047bb0:      	adrp	x16, 0x10c7000
 1047bb4:      	ldr	x17, [x16, #0x318]
 1047bb8:      	add	x16, x16, #0x318
 1047bbc:      	br	x17

0000000001047bc0 <_ZNSt6__ndk15mutex4lockEv@plt>:
 1047bc0:      	adrp	x16, 0x10c7000
 1047bc4:      	ldr	x17, [x16, #0x320]
 1047bc8:      	add	x16, x16, #0x320
 1047bcc:      	br	x17

0000000001047bd0 <inflateReset@plt>:
 1047bd0:      	adrp	x16, 0x10c7000
 1047bd4:      	ldr	x17, [x16, #0x328]
 1047bd8:      	add	x16, x16, #0x328
 1047bdc:      	br	x17

0000000001047be0 <inflateEnd@plt>:
 1047be0:      	adrp	x16, 0x10c7000
 1047be4:      	ldr	x17, [x16, #0x330]
 1047be8:      	add	x16, x16, #0x330
 1047bec:      	br	x17

0000000001047bf0 <inflateInit_@plt>:
 1047bf0:      	adrp	x16, 0x10c7000
 1047bf4:      	ldr	x17, [x16, #0x338]
 1047bf8:      	add	x16, x16, #0x338
 1047bfc:      	br	x17

0000000001047c00 <inflate@plt>:
 1047c00:      	adrp	x16, 0x10c7000
 1047c04:      	ldr	x17, [x16, #0x340]
 1047c08:      	add	x16, x16, #0x340
 1047c0c:      	br	x17

0000000001047c10 <inflateInit2_@plt>:
 1047c10:      	adrp	x16, 0x10c7000
 1047c14:      	ldr	x17, [x16, #0x348]
 1047c18:      	add	x16, x16, #0x348
 1047c1c:      	br	x17

0000000001047c20 <_ZN11arkernelcpp24ARKernelARAiStateSetting9SetKernelEPN8arkernel6KernelE@plt>:
 1047c20:      	adrp	x16, 0x10c7000
 1047c24:      	ldr	x17, [x16, #0x350]
 1047c28:      	add	x16, x16, #0x350
 1047c2c:      	br	x17

0000000001047c30 <printf@plt>:
 1047c30:      	adrp	x16, 0x10c7000
 1047c34:      	ldr	x17, [x16, #0x358]
 1047c38:      	add	x16, x16, #0x358
 1047c3c:      	br	x17

0000000001047c40 <_ZN11arkernelcpp26ARKernelFaceLightInterface7ReleaseEv@plt>:
 1047c40:      	adrp	x16, 0x10c7000
 1047c44:      	ldr	x17, [x16, #0x360]
 1047c48:      	add	x16, x16, #0x360
 1047c4c:      	br	x17

0000000001047c50 <_ZN11arkernelcpp26ARKernelGroupDataInterface17UpdatePartControlEv@plt>:
 1047c50:      	adrp	x16, 0x10c7000
 1047c54:      	ldr	x17, [x16, #0x368]
 1047c58:      	add	x16, x16, #0x368
 1047c5c:      	br	x17

0000000001047c60 <_ZN11arkernelcpp28ARKernelPartControlInterfaceC2Ev@plt>:
 1047c60:      	adrp	x16, 0x10c7000
 1047c64:      	ldr	x17, [x16, #0x370]
 1047c68:      	add	x16, x16, #0x370
 1047c6c:      	br	x17

0000000001047c70 <_ZN11arkernelcpp28ARKernelPartControlInterfaceC1Ev@plt>:
 1047c70:      	adrp	x16, 0x10c7000
 1047c74:      	ldr	x17, [x16, #0x378]
 1047c78:      	add	x16, x16, #0x378
 1047c7c:      	br	x17

0000000001047c80 <_ZN11arkernelcpp28ARKernelPartControlInterface11SetInstanceEPv@plt>:
 1047c80:      	adrp	x16, 0x10c7000
 1047c84:      	ldr	x17, [x16, #0x380]
 1047c88:      	add	x16, x16, #0x380
 1047c8c:      	br	x17

0000000001047c90 <_ZN11arkernelcpp26ARKernelGroupDataInterface11SetInstanceEPv@plt>:
 1047c90:      	adrp	x16, 0x10c7000
 1047c94:      	ldr	x17, [x16, #0x388]
 1047c98:      	add	x16, x16, #0x388
 1047c9c:      	br	x17

0000000001047ca0 <_ZN11arkernelcpp26ARKernelGroupDataInterface11GetInstanceEv@plt>:
 1047ca0:      	adrp	x16, 0x10c7000
 1047ca4:      	ldr	x17, [x16, #0x390]
 1047ca8:      	add	x16, x16, #0x390
 1047cac:      	br	x17

0000000001047cb0 <_ZN11arkernelcpp26ARKernelGroupDataInterface18ConvertGroupStructEPNS_11stGroupDataERN8arkernel11stGroupDataE@plt>:
 1047cb0:      	adrp	x16, 0x10c7000
 1047cb4:      	ldr	x17, [x16, #0x398]
 1047cb8:      	add	x16, x16, #0x398
 1047cbc:      	br	x17

0000000001047cc0 <_ZN11arkernelcpp28ARKernelPartControlInterfaceD2Ev@plt>:
 1047cc0:      	adrp	x16, 0x10c7000
 1047cc4:      	ldr	x17, [x16, #0x3a0]
 1047cc8:      	add	x16, x16, #0x3a0
 1047ccc:      	br	x17

0000000001047cd0 <_ZN11arkernelcpp26ARKernelGroupDataInterfaceC1Ev@plt>:
 1047cd0:      	adrp	x16, 0x10c7000
 1047cd4:      	ldr	x17, [x16, #0x3a8]
 1047cd8:      	add	x16, x16, #0x3a8
 1047cdc:      	br	x17

0000000001047ce0 <_ZN11arkernelcpp26ARKernelGroupDataInterfaceD1Ev@plt>:
 1047ce0:      	adrp	x16, 0x10c7000
 1047ce4:      	ldr	x17, [x16, #0x3b0]
 1047ce8:      	add	x16, x16, #0x3b0
 1047cec:      	br	x17

0000000001047cf0 <_ZN11arkernelcpp16ARKernelInstance7ReleaseEv@plt>:
 1047cf0:      	adrp	x16, 0x10c7000
 1047cf4:      	ldr	x17, [x16, #0x3b8]
 1047cf8:      	add	x16, x16, #0x3b8
 1047cfc:      	br	x17

0000000001047d00 <_ZN11arkernelcpp17ARKernelInterfaceD1Ev@plt>:
 1047d00:      	adrp	x16, 0x10c7000
 1047d04:      	ldr	x17, [x16, #0x3c0]
 1047d08:      	add	x16, x16, #0x3c0
 1047d0c:      	br	x17

0000000001047d10 <_ZN11arkernelcpp17ARKernelInterface19DeleteConfigurationERPNS_26ARKernelPlistDataInterfaceE@plt>:
 1047d10:      	adrp	x16, 0x10c7000
 1047d14:      	ldr	x17, [x16, #0x3c8]
 1047d18:      	add	x16, x16, #0x3c8
 1047d1c:      	br	x17

0000000001047d20 <_ZN11arkernelcpp17ARKernelInterfaceC1Ev@plt>:
 1047d20:      	adrp	x16, 0x10c7000
 1047d24:      	ldr	x17, [x16, #0x3d0]
 1047d28:      	add	x16, x16, #0x3d0
 1047d2c:      	br	x17

0000000001047d30 <_ZN11arkernelcpp17ARKernelInterface10InitializeEPNS_32ARKernelPublicInteractionServiceEPKc@plt>:
 1047d30:      	adrp	x16, 0x10c7000
 1047d34:      	ldr	x17, [x16, #0x3d8]
 1047d38:      	add	x16, x16, #0x3d8
 1047d3c:      	br	x17

0000000001047d40 <_ZN11arkernelcpp16ARKernelInstance16parseGroupConfigEPKc@plt>:
 1047d40:      	adrp	x16, 0x10c7000
 1047d44:      	ldr	x17, [x16, #0x3e0]
 1047d48:      	add	x16, x16, #0x3e0
 1047d4c:      	br	x17

0000000001047d50 <malloc@plt>:
 1047d50:      	adrp	x16, 0x10c7000
 1047d54:      	ldr	x17, [x16, #0x3e8]
 1047d58:      	add	x16, x16, #0x3e8
 1047d5c:      	br	x17

0000000001047d60 <_ZN11arkernelcpp16ARKernelInstance11HasGroupKeyEPKc@plt>:
 1047d60:      	adrp	x16, 0x10c7000
 1047d64:      	ldr	x17, [x16, #0x3f0]
 1047d68:      	add	x16, x16, #0x3f0
 1047d6c:      	br	x17

0000000001047d70 <_ZN11arkernelcpp16ARKernelInstance14LayerOperationEv@plt>:
 1047d70:      	adrp	x16, 0x10c7000
 1047d74:      	ldr	x17, [x16, #0x3f8]
 1047d78:      	add	x16, x16, #0x3f8
 1047d7c:      	br	x17

0000000001047d80 <_ZN11arkernelcpp16ARKernelInstance17SetPlistDataLayerEPKci@plt>:
 1047d80:      	adrp	x16, 0x10c7000
 1047d84:      	ldr	x17, [x16, #0x400]
 1047d88:      	add	x16, x16, #0x400
 1047d8c:      	br	x17

0000000001047d90 <_ZN11arkernelcpp16ARKernelInstance12GetPlistDataEPKc@plt>:
 1047d90:      	adrp	x16, 0x10c7000
 1047d94:      	ldr	x17, [x16, #0x408]
 1047d98:      	add	x16, x16, #0x408
 1047d9c:      	br	x17

0000000001047da0 <_ZN11arkernelcpp26ARKernelPlistDataInterface8SetApplyEb@plt>:
 1047da0:      	adrp	x16, 0x10c7000
 1047da4:      	ldr	x17, [x16, #0x410]
 1047da8:      	add	x16, x16, #0x410
 1047dac:      	br	x17

0000000001047db0 <_ZN11arkernelcpp26ARKernelPlistDataInterface14GetPartControlEv@plt>:
 1047db0:      	adrp	x16, 0x10c7000
 1047db4:      	ldr	x17, [x16, #0x418]
 1047db8:      	add	x16, x16, #0x418
 1047dbc:      	br	x17

0000000001047dc0 <_ZN11arkernelcpp28ARKernelPartControlInterface19SetPartControlLayerEi@plt>:
 1047dc0:      	adrp	x16, 0x10c7000
 1047dc4:      	ldr	x17, [x16, #0x420]
 1047dc8:      	add	x16, x16, #0x420
 1047dcc:      	br	x17

0000000001047dd0 <_ZN11arkernelcpp16ARKernelInstance15DeletePlistDataEPKc@plt>:
 1047dd0:      	adrp	x16, 0x10c7000
 1047dd4:      	ldr	x17, [x16, #0x428]
 1047dd8:      	add	x16, x16, #0x428
 1047ddc:      	br	x17

0000000001047de0 <_ZN11arkernelcpp26ARKernelPlistDataInterface6HasBGMEv@plt>:
 1047de0:      	adrp	x16, 0x10c7000
 1047de4:      	ldr	x17, [x16, #0x430]
 1047de8:      	add	x16, x16, #0x430
 1047dec:      	br	x17

0000000001047df0 <_ZN11arkernelcpp26ARKernelPlistDataInterface7StopBGMEv@plt>:
 1047df0:      	adrp	x16, 0x10c7000
 1047df4:      	ldr	x17, [x16, #0x438]
 1047df8:      	add	x16, x16, #0x438
 1047dfc:      	br	x17

0000000001047e00 <_ZN11arkernelcpp16ARKernelInstance14applyPlistDataEPKcPNS_26ARKernelPlistDataInterfaceE@plt>:
 1047e00:      	adrp	x16, 0x10c7000
 1047e04:      	ldr	x17, [x16, #0x440]
 1047e08:      	add	x16, x16, #0x440
 1047e0c:      	br	x17

0000000001047e10 <_ZN11arkernelcpp17ARKernelInterface10UnloadPartEv@plt>:
 1047e10:      	adrp	x16, 0x10c7000
 1047e14:      	ldr	x17, [x16, #0x448]
 1047e18:      	add	x16, x16, #0x448
 1047e1c:      	br	x17

0000000001047e20 <_ZN11arkernelcpp26ARKernelPlistDataInterface7PlayBGMEv@plt>:
 1047e20:      	adrp	x16, 0x10c7000
 1047e24:      	ldr	x17, [x16, #0x450]
 1047e28:      	add	x16, x16, #0x450
 1047e2c:      	br	x17

0000000001047e30 <_ZN11arkernelcpp17ARKernelInterface17ReloadPartControlEv@plt>:
 1047e30:      	adrp	x16, 0x10c7000
 1047e34:      	ldr	x17, [x16, #0x458]
 1047e38:      	add	x16, x16, #0x458
 1047e3c:      	br	x17

0000000001047e40 <_ZN11arkernelcpp16ARKernelInstance8SetParamEv@plt>:
 1047e40:      	adrp	x16, 0x10c7000
 1047e44:      	ldr	x17, [x16, #0x460]
 1047e48:      	add	x16, x16, #0x460
 1047e4c:      	br	x17

0000000001047e50 <_ZNK11arkernelcpp16ARKernelInstance17GetHasConfigAlphaEPKc@plt>:
 1047e50:      	adrp	x16, 0x10c7000
 1047e54:      	ldr	x17, [x16, #0x468]
 1047e58:      	add	x16, x16, #0x468
 1047e5c:      	br	x17

0000000001047e60 <_ZNK11arkernelcpp16ARKernelInstance14GetConfigAlphaEPKc@plt>:
 1047e60:      	adrp	x16, 0x10c7000
 1047e64:      	ldr	x17, [x16, #0x470]
 1047e68:      	add	x16, x16, #0x470
 1047e6c:      	br	x17

0000000001047e70 <_ZN11arkernelcpp28ARKernelPartControlInterface15GetParamControlEv@plt>:
 1047e70:      	adrp	x16, 0x10c7000
 1047e74:      	ldr	x17, [x16, #0x478]
 1047e78:      	add	x16, x16, #0x478
 1047e7c:      	br	x17

0000000001047e80 <_ZN11arkernelcpp20ARKernelParamControl12GetParamTypeEv@plt>:
 1047e80:      	adrp	x16, 0x10c7000
 1047e84:      	ldr	x17, [x16, #0x480]
 1047e88:      	add	x16, x16, #0x480
 1047e8c:      	br	x17

0000000001047e90 <_ZN11arkernelcpp20ARKernelParamControl12GetParamFlagEv@plt>:
 1047e90:      	adrp	x16, 0x10c7000
 1047e94:      	ldr	x17, [x16, #0x488]
 1047e98:      	add	x16, x16, #0x488
 1047e9c:      	br	x17

0000000001047ea0 <_ZN11arkernelcpp26ARKernelParamSliderControl15SetCurrentValueEf@plt>:
 1047ea0:      	adrp	x16, 0x10c7000
 1047ea4:      	ldr	x17, [x16, #0x490]
 1047ea8:      	add	x16, x16, #0x490
 1047eac:      	br	x17

0000000001047eb0 <_ZN11arkernelcpp20ARKernelParamControl8DispatchEv@plt>:
 1047eb0:      	adrp	x16, 0x10c7000
 1047eb4:      	ldr	x17, [x16, #0x498]
 1047eb8:      	add	x16, x16, #0x498
 1047ebc:      	br	x17

0000000001047ec0 <_ZN11arkernelcpp17ARKernelInterface15UpdateCacheDataEv@plt>:
 1047ec0:      	adrp	x16, 0x10c7000
 1047ec4:      	ldr	x17, [x16, #0x4a0]
 1047ec8:      	add	x16, x16, #0x4a0
 1047ecc:      	br	x17

0000000001047ed0 <_ZN11arkernelcpp17ARKernelInterface11OnDrawFrameEjjiijj@plt>:
 1047ed0:      	adrp	x16, 0x10c7000
 1047ed4:      	ldr	x17, [x16, #0x4a8]
 1047ed8:      	add	x16, x16, #0x4a8
 1047edc:      	br	x17

0000000001047ee0 <_ZN11arkernelcpp17ARKernelInterface28LoadPublicParamConfigurationEPKc@plt>:
 1047ee0:      	adrp	x16, 0x10c7000
 1047ee4:      	ldr	x17, [x16, #0x4b0]
 1047ee8:      	add	x16, x16, #0x4b0
 1047eec:      	br	x17

0000000001047ef0 <_ZN11arkernelcpp17ARKernelInterface31SetDefaultFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
 1047ef0:      	adrp	x16, 0x10c7000
 1047ef4:      	ldr	x17, [x16, #0x4b8]
 1047ef8:      	add	x16, x16, #0x4b8
 1047efc:      	br	x17

0000000001047f00 <_ZN11arkernelcpp17ARKernelInterface19ParserConfigurationEPKcS2_S2_i@plt>:
 1047f00:      	adrp	x16, 0x10c7000
 1047f04:      	ldr	x17, [x16, #0x4c0]
 1047f08:      	add	x16, x16, #0x4c0
 1047f0c:      	br	x17

0000000001047f10 <_ZN11arkernelcpp26ARKernelPlistDataInterface7PrepareEv@plt>:
 1047f10:      	adrp	x16, 0x10c7000
 1047f14:      	ldr	x17, [x16, #0x4c8]
 1047f18:      	add	x16, x16, #0x4c8
 1047f1c:      	br	x17

0000000001047f20 <_ZN11arkernelcpp26ARKernelPlistDataInterface14IsParseSuccessEv@plt>:
 1047f20:      	adrp	x16, 0x10c7000
 1047f24:      	ldr	x17, [x16, #0x4d0]
 1047f28:      	add	x16, x16, #0x4d0
 1047f2c:      	br	x17

0000000001047f30 <_ZN11arkernelcpp17ARKernelInterface12OnTouchBeginEffj@plt>:
 1047f30:      	adrp	x16, 0x10c7000
 1047f34:      	ldr	x17, [x16, #0x4d8]
 1047f38:      	add	x16, x16, #0x4d8
 1047f3c:      	br	x17

0000000001047f40 <_ZN11arkernelcpp17ARKernelInterface11OnTouchMoveEffj@plt>:
 1047f40:      	adrp	x16, 0x10c7000
 1047f44:      	ldr	x17, [x16, #0x4e0]
 1047f48:      	add	x16, x16, #0x4e0
 1047f4c:      	br	x17

0000000001047f50 <_ZN11arkernelcpp17ARKernelInterface10OnTouchEndEffj@plt>:
 1047f50:      	adrp	x16, 0x10c7000
 1047f54:      	ldr	x17, [x16, #0x4e8]
 1047f58:      	add	x16, x16, #0x4e8
 1047f5c:      	br	x17

0000000001047f60 <_ZN11arkernelcpp17ARKernelInterface9SetOptionENS_10OptionTypeEb@plt>:
 1047f60:      	adrp	x16, 0x10c7000
 1047f64:      	ldr	x17, [x16, #0x4f0]
 1047f68:      	add	x16, x16, #0x4f0
 1047f6c:      	br	x17

0000000001047f70 <_ZN11arkernelcpp17ARKernelInterface14SetMusicVolumeEf@plt>:
 1047f70:      	adrp	x16, 0x10c7000
 1047f74:      	ldr	x17, [x16, #0x4f8]
 1047f78:      	add	x16, x16, #0x4f8
 1047f7c:      	br	x17

0000000001047f80 <_ZN11arkernelcpp17ARKernelInterface19NeedDataRequireTypeENS_15DataRequireTypeE@plt>:
 1047f80:      	adrp	x16, 0x10c7000
 1047f84:      	ldr	x17, [x16, #0x500]
 1047f88:      	add	x16, x16, #0x500
 1047f8c:      	br	x17

0000000001047f90 <_ZN11arkernelcpp17ARKernelInterface13SetNativeDataEPKNS_25ARKernelBaseDataInterfaceE@plt>:
 1047f90:      	adrp	x16, 0x10c7000
 1047f94:      	ldr	x17, [x16, #0x508]
 1047f98:      	add	x16, x16, #0x508
 1047f9c:      	br	x17

0000000001047fa0 <_ZN11arkernelcpp17ARKernelInterface16SetAllPartsAlphaEf@plt>:
 1047fa0:      	adrp	x16, 0x10c7000
 1047fa4:      	ldr	x17, [x16, #0x510]
 1047fa8:      	add	x16, x16, #0x510
 1047fac:      	br	x17

0000000001047fb0 <_ZN11arkernelcpp17ARKernelInterface34SetFace3DReconstructorCallbackFuncENSt6__ndk18functionIFviiibbPfEEE@plt>:
 1047fb0:      	adrp	x16, 0x10c7000
 1047fb4:      	ldr	x17, [x16, #0x518]
 1047fb8:      	add	x16, x16, #0x518
 1047fbc:      	br	x17

0000000001047fc0 <_ZN11arkernelcpp17ARKernelInterface45SetFace3DReconstructorGetMeanFaceCallbackFuncENSt6__ndk18functionIFPfvEEE@plt>:
 1047fc0:      	adrp	x16, 0x10c7000
 1047fc4:      	ldr	x17, [x16, #0x520]
 1047fc8:      	add	x16, x16, #0x520
 1047fcc:      	br	x17

0000000001047fd0 <_ZN11arkernelcpp17ARKernelInterface44SetFace3DReconstructorGetNeuFaceCallbackFuncENSt6__ndk18functionIFPfiEEE@plt>:
 1047fd0:      	adrp	x16, 0x10c7000
 1047fd4:      	ldr	x17, [x16, #0x528]
 1047fd8:      	add	x16, x16, #0x528
 1047fdc:      	br	x17

0000000001047fe0 <_ZN11arkernelcpp17ARKernelInterface48SetFace3DReconstructorGetPerspectMVPCallbackFuncENSt6__ndk18functionIFPfifibEEE@plt>:
 1047fe0:      	adrp	x16, 0x10c7000
 1047fe4:      	ldr	x17, [x16, #0x530]
 1047fe8:      	add	x16, x16, #0x530
 1047fec:      	br	x17

0000000001047ff0 <free@plt>:
 1047ff0:      	adrp	x16, 0x10c7000
 1047ff4:      	ldr	x17, [x16, #0x538]
 1047ff8:      	add	x16, x16, #0x538
 1047ffc:      	br	x17

0000000001048000 <realloc@plt>:
 1048000:      	adrp	x16, 0x10c7000
 1048004:      	ldr	x17, [x16, #0x540]
 1048008:      	add	x16, x16, #0x540
 104800c:      	br	x17

0000000001048010 <_ZN11arkernelcpp17ARKernelInterface7ReleaseEv@plt>:
 1048010:      	adrp	x16, 0x10c7000
 1048014:      	ldr	x17, [x16, #0x548]
 1048018:      	add	x16, x16, #0x548
 104801c:      	br	x17

0000000001048020 <_ZN11arkernelcpp26ARKernelPlistDataInterfaceC1Ev@plt>:
 1048020:      	adrp	x16, 0x10c7000
 1048024:      	ldr	x17, [x16, #0x550]
 1048028:      	add	x16, x16, #0x550
 104802c:      	br	x17

0000000001048030 <_ZN11arkernelcpp26ARKernelPlistDataInterface11SetInstanceEPv@plt>:
 1048030:      	adrp	x16, 0x10c7000
 1048034:      	ldr	x17, [x16, #0x558]
 1048038:      	add	x16, x16, #0x558
 104803c:      	br	x17

0000000001048040 <_ZN11arkernelcpp26ARKernelPlistDataInterface11GetInstanceEv@plt>:
 1048040:      	adrp	x16, 0x10c7000
 1048044:      	ldr	x17, [x16, #0x560]
 1048048:      	add	x16, x16, #0x560
 104804c:      	br	x17

0000000001048050 <_ZN11arkernelcpp26ARKernelPlistDataInterfaceD1Ev@plt>:
 1048050:      	adrp	x16, 0x10c7000
 1048054:      	ldr	x17, [x16, #0x568]
 1048058:      	add	x16, x16, #0x568
 104805c:      	br	x17

0000000001048060 <_ZN11arkernelcpp20ARKernelParamControlC2Ev@plt>:
 1048060:      	adrp	x16, 0x10c7000
 1048064:      	ldr	x17, [x16, #0x570]
 1048068:      	add	x16, x16, #0x570
 104806c:      	br	x17

0000000001048070 <_ZN11arkernelcpp20ARKernelParamControlD2Ev@plt>:
 1048070:      	adrp	x16, 0x10c7000
 1048074:      	ldr	x17, [x16, #0x578]
 1048078:      	add	x16, x16, #0x578
 104807c:      	br	x17

0000000001048080 <_ZN11arkernelcpp20ARKernelParamControlD1Ev@plt>:
 1048080:      	adrp	x16, 0x10c7000
 1048084:      	ldr	x17, [x16, #0x580]
 1048088:      	add	x16, x16, #0x580
 104808c:      	br	x17

0000000001048090 <_ZN11arkernelcpp20ARKernelParamControlC1Ev@plt>:
 1048090:      	adrp	x16, 0x10c7000
 1048094:      	ldr	x17, [x16, #0x588]
 1048098:      	add	x16, x16, #0x588
 104809c:      	br	x17

00000000010480a0 <_ZN11arkernelcpp28ARKernelPartControlInterface18UpdateParamControlEv@plt>:
 10480a0:      	adrp	x16, 0x10c7000
 10480a4:      	ldr	x17, [x16, #0x590]
 10480a8:      	add	x16, x16, #0x590
 10480ac:      	br	x17

00000000010480b0 <_ZN11arkernelcpp28ARKernelPartControlInterface24GetIsNeedDataRequireTypeENS_15DataRequireTypeE@plt>:
 10480b0:      	adrp	x16, 0x10c7000
 10480b4:      	ldr	x17, [x16, #0x598]
 10480b8:      	add	x16, x16, #0x598
 10480bc:      	br	x17

00000000010480c0 <_ZN11arkernelcpp22ARKernelParamTableDictD1Ev@plt>:
 10480c0:      	adrp	x16, 0x10c7000
 10480c4:      	ldr	x17, [x16, #0x5a0]
 10480c8:      	add	x16, x16, #0x5a0
 10480cc:      	br	x17

00000000010480d0 <_ZN11arkernelcpp22ARKernelParamTableDictC1Ev@plt>:
 10480d0:      	adrp	x16, 0x10c7000
 10480d4:      	ldr	x17, [x16, #0x5a8]
 10480d8:      	add	x16, x16, #0x5a8
 10480dc:      	br	x17

00000000010480e0 <_ZN11arkernelcpp22ARKernelParamTableDict11SetInstanceEPv@plt>:
 10480e0:      	adrp	x16, 0x10c7000
 10480e4:      	ldr	x17, [x16, #0x5b0]
 10480e8:      	add	x16, x16, #0x5b0
 10480ec:      	br	x17

00000000010480f0 <_ZN11arkernelcpp28ARKernelPartControlInterfaceD1Ev@plt>:
 10480f0:      	adrp	x16, 0x10c7000
 10480f4:      	ldr	x17, [x16, #0x5b8]
 10480f8:      	add	x16, x16, #0x5b8
 10480fc:      	br	x17

0000000001048100 <_ZN11arkernelcpp26ARKernelPlistDataInterface17UpdatePartControlEv@plt>:
 1048100:      	adrp	x16, 0x10c7000
 1048104:      	ldr	x17, [x16, #0x5c0]
 1048108:      	add	x16, x16, #0x5c0
 104810c:      	br	x17

0000000001048110 <_ZN11arkernelcpp17ARKernelParamBase11SetInstanceEPv@plt>:
 1048110:      	adrp	x16, 0x10c7000
 1048114:      	ldr	x17, [x16, #0x5c8]
 1048118:      	add	x16, x16, #0x5c8
 104811c:      	br	x17

0000000001048120 <_ZN11arkernelcpp17ARKernelParamBaseC2Ev@plt>:
 1048120:      	adrp	x16, 0x10c7000
 1048124:      	ldr	x17, [x16, #0x5d0]
 1048128:      	add	x16, x16, #0x5d0
 104812c:      	br	x17

0000000001048130 <_ZN11arkernelcpp17ARKernelParamBaseD2Ev@plt>:
 1048130:      	adrp	x16, 0x10c7000
 1048134:      	ldr	x17, [x16, #0x5d8]
 1048138:      	add	x16, x16, #0x5d8
 104813c:      	br	x17

0000000001048140 <_ZN11arkernelcpp17ARKernelParamBaseD1Ev@plt>:
 1048140:      	adrp	x16, 0x10c7000
 1048144:      	ldr	x17, [x16, #0x5e0]
 1048148:      	add	x16, x16, #0x5e0
 104814c:      	br	x17

0000000001048150 <_ZN11arkernelcpp18ARKernelParamTable11SetInstanceEPv@plt>:
 1048150:      	adrp	x16, 0x10c7000
 1048154:      	ldr	x17, [x16, #0x5e8]
 1048158:      	add	x16, x16, #0x5e8
 104815c:      	br	x17

0000000001048160 <_ZN11arkernelcpp18ARKernelParamTableC1Ev@plt>:
 1048160:      	adrp	x16, 0x10c7000
 1048164:      	ldr	x17, [x16, #0x5f0]
 1048168:      	add	x16, x16, #0x5f0
 104816c:      	br	x17

0000000001048170 <_ZN11arkernelcpp18ARKernelParamTableD1Ev@plt>:
 1048170:      	adrp	x16, 0x10c7000
 1048174:      	ldr	x17, [x16, #0x5f8]
 1048178:      	add	x16, x16, #0x5f8
 104817c:      	br	x17

0000000001048180 <tanf@plt>:
 1048180:      	adrp	x16, 0x10c7000
 1048184:      	ldr	x17, [x16, #0x600]
 1048188:      	add	x16, x16, #0x600
 104818c:      	br	x17

0000000001048190 <atanf@plt>:
 1048190:      	adrp	x16, 0x10c7000
 1048194:      	ldr	x17, [x16, #0x608]
 1048198:      	add	x16, x16, #0x608
 104819c:      	br	x17

00000000010481a0 <_ZN3SPD15SpeckleDetector4initEv@plt>:
 10481a0:      	adrp	x16, 0x10c7000
 10481a4:      	ldr	x17, [x16, #0x610]
 10481a8:      	add	x16, x16, #0x610
 10481ac:      	br	x17

00000000010481b0 <_ZN3SPD15SpeckleDetector6detectEPKhiiPiiiii@plt>:
 10481b0:      	adrp	x16, 0x10c7000
 10481b4:      	ldr	x17, [x16, #0x618]
 10481b8:      	add	x16, x16, #0x618
 10481bc:      	br	x17

00000000010481c0 <_ZN3SPD15SpeckleDetector9getPointsEPNS_5PointE@plt>:
 10481c0:      	adrp	x16, 0x10c7000
 10481c4:      	ldr	x17, [x16, #0x620]
 10481c8:      	add	x16, x16, #0x620
 10481cc:      	br	x17

00000000010481d0 <_ZN3SPD15SpeckleDetectorC1Ev@plt>:
 10481d0:      	adrp	x16, 0x10c7000
 10481d4:      	ldr	x17, [x16, #0x628]
 10481d8:      	add	x16, x16, #0x628
 10481dc:      	br	x17

00000000010481e0 <_ZN3SPD15SpeckleDetectorD1Ev@plt>:
 10481e0:      	adrp	x16, 0x10c7000
 10481e4:      	ldr	x17, [x16, #0x630]
 10481e8:      	add	x16, x16, #0x630
 10481ec:      	br	x17

00000000010481f0 <vsnprintf@plt>:
 10481f0:      	adrp	x16, 0x10c7000
 10481f4:      	ldr	x17, [x16, #0x638]
 10481f8:      	add	x16, x16, #0x638
 10481fc:      	br	x17

0000000001048200 <fileno@plt>:
 1048200:      	adrp	x16, 0x10c7000
 1048204:      	ldr	x17, [x16, #0x640]
 1048208:      	add	x16, x16, #0x640
 104820c:      	br	x17

0000000001048210 <fstat@plt>:
 1048210:      	adrp	x16, 0x10c7000
 1048214:      	ldr	x17, [x16, #0x648]
 1048218:      	add	x16, x16, #0x648
 104821c:      	br	x17

0000000001048220 <fseek@plt>:
 1048220:      	adrp	x16, 0x10c7000
 1048224:      	ldr	x17, [x16, #0x650]
 1048228:      	add	x16, x16, #0x650
 104822c:      	br	x17

0000000001048230 <ftell@plt>:
 1048230:      	adrp	x16, 0x10c7000
 1048234:      	ldr	x17, [x16, #0x658]
 1048238:      	add	x16, x16, #0x658
 104823c:      	br	x17

0000000001048240 <fread@plt>:
 1048240:      	adrp	x16, 0x10c7000
 1048244:      	ldr	x17, [x16, #0x660]
 1048248:      	add	x16, x16, #0x660
 104824c:      	br	x17

0000000001048250 <memchr@plt>:
 1048250:      	adrp	x16, 0x10c7000
 1048254:      	ldr	x17, [x16, #0x668]
 1048258:      	add	x16, x16, #0x668
 104825c:      	br	x17

0000000001048260 <access@plt>:
 1048260:      	adrp	x16, 0x10c7000
 1048264:      	ldr	x17, [x16, #0x670]
 1048268:      	add	x16, x16, #0x670
 104826c:      	br	x17

0000000001048270 <fopen@plt>:
 1048270:      	adrp	x16, 0x10c7000
 1048274:      	ldr	x17, [x16, #0x678]
 1048278:      	add	x16, x16, #0x678
 104827c:      	br	x17

0000000001048280 <fclose@plt>:
 1048280:      	adrp	x16, 0x10c7000
 1048284:      	ldr	x17, [x16, #0x680]
 1048288:      	add	x16, x16, #0x680
 104828c:      	br	x17

0000000001048290 <pthread_once@plt>:
 1048290:      	adrp	x16, 0x10c7000
 1048294:      	ldr	x17, [x16, #0x688]
 1048298:      	add	x16, x16, #0x688
 104829c:      	br	x17

00000000010482a0 <pthread_mutex_lock@plt>:
 10482a0:      	adrp	x16, 0x10c7000
 10482a4:      	ldr	x17, [x16, #0x690]
 10482a8:      	add	x16, x16, #0x690
 10482ac:      	br	x17

00000000010482b0 <pthread_mutex_unlock@plt>:
 10482b0:      	adrp	x16, 0x10c7000
 10482b4:      	ldr	x17, [x16, #0x698]
 10482b8:      	add	x16, x16, #0x698
 10482bc:      	br	x17

00000000010482c0 <strcmp@plt>:
 10482c0:      	adrp	x16, 0x10c7000
 10482c4:      	ldr	x17, [x16, #0x6a0]
 10482c8:      	add	x16, x16, #0x6a0
 10482cc:      	br	x17

00000000010482d0 <fgets@plt>:
 10482d0:      	adrp	x16, 0x10c7000
 10482d4:      	ldr	x17, [x16, #0x6a8]
 10482d8:      	add	x16, x16, #0x6a8
 10482dc:      	br	x17

00000000010482e0 <setlocale@plt>:
 10482e0:      	adrp	x16, 0x10c7000
 10482e4:      	ldr	x17, [x16, #0x6b0]
 10482e8:      	add	x16, x16, #0x6b0
 10482ec:      	br	x17

00000000010482f0 <vfscanf@plt>:
 10482f0:      	adrp	x16, 0x10c7000
 10482f4:      	ldr	x17, [x16, #0x6b8]
 10482f8:      	add	x16, x16, #0x6b8
 10482fc:      	br	x17

0000000001048300 <fputs@plt>:
 1048300:      	adrp	x16, 0x10c7000
 1048304:      	ldr	x17, [x16, #0x6c0]
 1048308:      	add	x16, x16, #0x6c0
 104830c:      	br	x17

0000000001048310 <vfprintf@plt>:
 1048310:      	adrp	x16, 0x10c7000
 1048314:      	ldr	x17, [x16, #0x6c8]
 1048318:      	add	x16, x16, #0x6c8
 104831c:      	br	x17

0000000001048320 <fflush@plt>:
 1048320:      	adrp	x16, 0x10c7000
 1048324:      	ldr	x17, [x16, #0x6d0]
 1048328:      	add	x16, x16, #0x6d0
 104832c:      	br	x17

0000000001048330 <fwrite@plt>:
 1048330:      	adrp	x16, 0x10c7000
 1048334:      	ldr	x17, [x16, #0x6d8]
 1048338:      	add	x16, x16, #0x6d8
 104833c:      	br	x17

0000000001048340 <perror@plt>:
 1048340:      	adrp	x16, 0x10c7000
 1048344:      	ldr	x17, [x16, #0x6e0]
 1048348:      	add	x16, x16, #0x6e0
 104834c:      	br	x17

0000000001048350 <stat@plt>:
 1048350:      	adrp	x16, 0x10c7000
 1048354:      	ldr	x17, [x16, #0x6e8]
 1048358:      	add	x16, x16, #0x6e8
 104835c:      	br	x17

0000000001048360 <strtod@plt>:
 1048360:      	adrp	x16, 0x10c7000
 1048364:      	ldr	x17, [x16, #0x6f0]
 1048368:      	add	x16, x16, #0x6f0
 104836c:      	br	x17

0000000001048370 <__strlen_chk@plt>:
 1048370:      	adrp	x16, 0x10c7000
 1048374:      	ldr	x17, [x16, #0x6f8]
 1048378:      	add	x16, x16, #0x6f8
 104837c:      	br	x17

0000000001048380 <ferror@plt>:
 1048380:      	adrp	x16, 0x10c7000
 1048384:      	ldr	x17, [x16, #0x700]
 1048388:      	add	x16, x16, #0x700
 104838c:      	br	x17

0000000001048390 <setjmp@plt>:
 1048390:      	adrp	x16, 0x10c7000
 1048394:      	ldr	x17, [x16, #0x708]
 1048398:      	add	x16, x16, #0x708
 104839c:      	br	x17

00000000010483a0 <longjmp@plt>:
 10483a0:      	adrp	x16, 0x10c7000
 10483a4:      	ldr	x17, [x16, #0x710]
 10483a8:      	add	x16, x16, #0x710
 10483ac:      	br	x17

00000000010483b0 <fmod@plt>:
 10483b0:      	adrp	x16, 0x10c7000
 10483b4:      	ldr	x17, [x16, #0x718]
 10483b8:      	add	x16, x16, #0x718
 10483bc:      	br	x17

00000000010483c0 <strchr@plt>:
 10483c0:      	adrp	x16, 0x10c7000
 10483c4:      	ldr	x17, [x16, #0x720]
 10483c8:      	add	x16, x16, #0x720
 10483cc:      	br	x17

00000000010483d0 <__strchr_chk@plt>:
 10483d0:      	adrp	x16, 0x10c7000
 10483d4:      	ldr	x17, [x16, #0x728]
 10483d8:      	add	x16, x16, #0x728
 10483dc:      	br	x17

00000000010483e0 <atoi@plt>:
 10483e0:      	adrp	x16, 0x10c7000
 10483e4:      	ldr	x17, [x16, #0x730]
 10483e8:      	add	x16, x16, #0x730
 10483ec:      	br	x17

00000000010483f0 <atoll@plt>:
 10483f0:      	adrp	x16, 0x10c7000
 10483f4:      	ldr	x17, [x16, #0x738]
 10483f8:      	add	x16, x16, #0x738
 10483fc:      	br	x17

0000000001048400 <atof@plt>:
 1048400:      	adrp	x16, 0x10c7000
 1048404:      	ldr	x17, [x16, #0x740]
 1048408:      	add	x16, x16, #0x740
 104840c:      	br	x17

0000000001048410 <fmodf@plt>:
 1048410:      	adrp	x16, 0x10c7000
 1048414:      	ldr	x17, [x16, #0x748]
 1048418:      	add	x16, x16, #0x748
 104841c:      	br	x17

0000000001048420 <gettimeofday@plt>:
 1048420:      	adrp	x16, 0x10c7000
 1048424:      	ldr	x17, [x16, #0x750]
 1048428:      	add	x16, x16, #0x750
 104842c:      	br	x17

0000000001048430 <ScalePlane_16@plt>:
 1048430:      	adrp	x16, 0x10c7000
 1048434:      	ldr	x17, [x16, #0x758]
 1048438:      	add	x16, x16, #0x758
 104843c:      	br	x17

0000000001048440 <pthread_create@plt>:
 1048440:      	adrp	x16, 0x10c7000
 1048444:      	ldr	x17, [x16, #0x760]
 1048448:      	add	x16, x16, #0x760
 104844c:      	br	x17

0000000001048450 <_ZN5manis12ManisVersionEv@plt>:
 1048450:      	adrp	x16, 0x10c7000
 1048454:      	ldr	x17, [x16, #0x768]
 1048458:      	add	x16, x16, #0x768
 104845c:      	br	x17

0000000001048460 <wmemchr@plt>:
 1048460:      	adrp	x16, 0x10c7000
 1048464:      	ldr	x17, [x16, #0x770]
 1048468:      	add	x16, x16, #0x770
 104846c:      	br	x17

0000000001048470 <pow@plt>:
 1048470:      	adrp	x16, 0x10c7000
 1048474:      	ldr	x17, [x16, #0x778]
 1048478:      	add	x16, x16, #0x778
 104847c:      	br	x17

0000000001048480 <acosf@plt>:
 1048480:      	adrp	x16, 0x10c7000
 1048484:      	ldr	x17, [x16, #0x780]
 1048488:      	add	x16, x16, #0x780
 104848c:      	br	x17

0000000001048490 <sincos@plt>:
 1048490:      	adrp	x16, 0x10c7000
 1048494:      	ldr	x17, [x16, #0x788]
 1048498:      	add	x16, x16, #0x788
 104849c:      	br	x17

00000000010484a0 <_Z16ARSPMDecodeImagePhmRiS0_PS_@plt>:
 10484a0:      	adrp	x16, 0x10c7000
 10484a4:      	ldr	x17, [x16, #0x790]
 10484a8:      	add	x16, x16, #0x790
 10484ac:      	br	x17

00000000010484b0 <_Z20ARSPMDecodeImageInfoPhmRiS0_@plt>:
 10484b0:      	adrp	x16, 0x10c7000
 10484b4:      	ldr	x17, [x16, #0x798]
 10484b8:      	add	x16, x16, #0x798
 10484bc:      	br	x17

00000000010484c0 <calloc@plt>:
 10484c0:      	adrp	x16, 0x10c7000
 10484c4:      	ldr	x17, [x16, #0x7a0]
 10484c8:      	add	x16, x16, #0x7a0
 10484cc:      	br	x17

00000000010484d0 <powf@plt>:
 10484d0:      	adrp	x16, 0x10c7000
 10484d4:      	ldr	x17, [x16, #0x7a8]
 10484d8:      	add	x16, x16, #0x7a8
 10484dc:      	br	x17

00000000010484e0 <fputc@plt>:
 10484e0:      	adrp	x16, 0x10c7000
 10484e4:      	ldr	x17, [x16, #0x7b0]
 10484e8:      	add	x16, x16, #0x7b0
 10484ec:      	br	x17

00000000010484f0 <ungetc@plt>:
 10484f0:      	adrp	x16, 0x10c7000
 10484f4:      	ldr	x17, [x16, #0x7b8]
 10484f8:      	add	x16, x16, #0x7b8
 10484fc:      	br	x17

0000000001048500 <feof@plt>:
 1048500:      	adrp	x16, 0x10c7000
 1048504:      	ldr	x17, [x16, #0x7c0]
 1048508:      	add	x16, x16, #0x7c0
 104850c:      	br	x17

0000000001048510 <strtol@plt>:
 1048510:      	adrp	x16, 0x10c7000
 1048514:      	ldr	x17, [x16, #0x7c8]
 1048518:      	add	x16, x16, #0x7c8
 104851c:      	br	x17

0000000001048520 <strncmp@plt>:
 1048520:      	adrp	x16, 0x10c7000
 1048524:      	ldr	x17, [x16, #0x7d0]
 1048528:      	add	x16, x16, #0x7d0
 104852c:      	br	x17

0000000001048530 <ldexpf@plt>:
 1048530:      	adrp	x16, 0x10c7000
 1048534:      	ldr	x17, [x16, #0x7d8]
 1048538:      	add	x16, x16, #0x7d8
 104853c:      	br	x17

0000000001048540 <_ZN5manis13ExtendOptionsC1Ev@plt>:
 1048540:      	adrp	x16, 0x10c7000
 1048544:      	ldr	x17, [x16, #0x7e0]
 1048548:      	add	x16, x16, #0x7e0
 104854c:      	br	x17

0000000001048550 <_ZN5manis9IsSupportENS_10DeviceTypeE@plt>:
 1048550:      	adrp	x16, 0x10c7000
 1048554:      	ldr	x17, [x16, #0x7e8]
 1048558:      	add	x16, x16, #0x7e8
 104855c:      	br	x17

0000000001048560 <_ZN5manis13ExtendOptions3AddENS_14ExtendOptionIDEi@plt>:
 1048560:      	adrp	x16, 0x10c7000
 1048564:      	ldr	x17, [x16, #0x7f0]
 1048568:      	add	x16, x16, #0x7f0
 104856c:      	br	x17

0000000001048570 <_ZN5manis3Net9CreateNetEPNS_13ExtendOptionsE@plt>:
 1048570:      	adrp	x16, 0x10c7000
 1048574:      	ldr	x17, [x16, #0x7f8]
 1048578:      	add	x16, x16, #0x7f8
 104857c:      	br	x17

0000000001048580 <_ZN5manis8Executor14CreateExecutorEPNS_3NetEPNS_13ExtendOptionsE@plt>:
 1048580:      	adrp	x16, 0x10c7000
 1048584:      	ldr	x17, [x16, #0x800]
 1048588:      	add	x16, x16, #0x800
 104858c:      	br	x17

0000000001048590 <_ZN5manis3Net10ReleaseNetEPS0_@plt>:
 1048590:      	adrp	x16, 0x10c7000
 1048594:      	ldr	x17, [x16, #0x808]
 1048598:      	add	x16, x16, #0x808
 104859c:      	br	x17

00000000010485a0 <_ZN5manis13ExtendOptionsD1Ev@plt>:
 10485a0:      	adrp	x16, 0x10c7000
 10485a4:      	ldr	x17, [x16, #0x810]
 10485a8:      	add	x16, x16, #0x810
 10485ac:      	br	x17

00000000010485b0 <_ZN5manis6TensorC1ERKNS_10DeviceTypeERKNS_10LayoutTypeERKNS_8DataTypeE@plt>:
 10485b0:      	adrp	x16, 0x10c7000
 10485b4:      	ldr	x17, [x16, #0x818]
 10485b8:      	add	x16, x16, #0x818
 10485bc:      	br	x17

00000000010485c0 <_ZN5manis12FromTexturesEiiPf@plt>:
 10485c0:      	adrp	x16, 0x10c7000
 10485c4:      	ldr	x17, [x16, #0x820]
 10485c8:      	add	x16, x16, #0x820
 10485cc:      	br	x17

00000000010485d0 <_ZN5manis12FromTexturesEiiifPf@plt>:
 10485d0:      	adrp	x16, 0x10c7000
 10485d4:      	ldr	x17, [x16, #0x828]
 10485d8:      	add	x16, x16, #0x828
 10485dc:      	br	x17

00000000010485e0 <_ZN5manis6TensoraSERKS0_@plt>:
 10485e0:      	adrp	x16, 0x10c7000
 10485e4:      	ldr	x17, [x16, #0x830]
 10485e8:      	add	x16, x16, #0x830
 10485ec:      	br	x17

00000000010485f0 <_ZN5manis6TensorD1Ev@plt>:
 10485f0:      	adrp	x16, 0x10c7000
 10485f4:      	ldr	x17, [x16, #0x838]
 10485f8:      	add	x16, x16, #0x838
 10485fc:      	br	x17

0000000001048600 <_ZN5manis4nchw16FromPixelsResizeENS_13PixelConvTypeEPKhjjjjNS_8DataTypeE@plt>:
 1048600:      	adrp	x16, 0x10c7000
 1048604:      	ldr	x17, [x16, #0x840]
 1048608:      	add	x16, x16, #0x840
 104860c:      	br	x17

0000000001048610 <_ZN5manis6Tensor11MutableDataEv@plt>:
 1048610:      	adrp	x16, 0x10c7000
 1048614:      	ldr	x17, [x16, #0x848]
 1048618:      	add	x16, x16, #0x848
 104861c:      	br	x17

0000000001048620 <_ZNK5manis6Tensor9GetDimNumEv@plt>:
 1048620:      	adrp	x16, 0x10c7000
 1048624:      	ldr	x17, [x16, #0x850]
 1048628:      	add	x16, x16, #0x850
 104862c:      	br	x17

0000000001048630 <_ZNK5manis6Tensor6GetDimEj@plt>:
 1048630:      	adrp	x16, 0x10c7000
 1048634:      	ldr	x17, [x16, #0x858]
 1048638:      	add	x16, x16, #0x858
 104863c:      	br	x17

0000000001048640 <_ZN5manis4nchw22SubstractMeanNormalizeERNS_6TensorEPKfS4_@plt>:
 1048640:      	adrp	x16, 0x10c7000
 1048644:      	ldr	x17, [x16, #0x860]
 1048648:      	add	x16, x16, #0x860
 104864c:      	br	x17

0000000001048650 <_ZN5manis8Executor15ReleaseExecutorEPS0_@plt>:
 1048650:      	adrp	x16, 0x10c7000
 1048654:      	ldr	x17, [x16, #0x868]
 1048658:      	add	x16, x16, #0x868
 104865c:      	br	x17

0000000001048660 <_ZNK5manis6Tensor4DataEv@plt>:
 1048660:      	adrp	x16, 0x10c7000
 1048664:      	ldr	x17, [x16, #0x870]
 1048668:      	add	x16, x16, #0x870
 104866c:      	br	x17

0000000001048670 <_ZN5manis6Tensor6AddDimEj@plt>:
 1048670:      	adrp	x16, 0x10c7000
 1048674:      	ldr	x17, [x16, #0x878]
 1048678:      	add	x16, x16, #0x878
 104867c:      	br	x17

0000000001048680 <_Z24ARSPMCreateSkottieHandlev@plt>:
 1048680:      	adrp	x16, 0x10c7000
 1048684:      	ldr	x17, [x16, #0x880]
 1048688:      	add	x16, x16, #0x880
 104868c:      	br	x17

0000000001048690 <_Z20ARSPMSkottieLoadDataRPvPKciS2_@plt>:
 1048690:      	adrp	x16, 0x10c7000
 1048694:      	ldr	x17, [x16, #0x888]
 1048698:      	add	x16, x16, #0x888
 104869c:      	br	x17

00000000010486a0 <_Z29ARSPMSkottieGetAnimationWidthRPv@plt>:
 10486a0:      	adrp	x16, 0x10c7000
 10486a4:      	ldr	x17, [x16, #0x890]
 10486a8:      	add	x16, x16, #0x890
 10486ac:      	br	x17

00000000010486b0 <_Z30ARSPMSkottieGetAnimationHeightRPv@plt>:
 10486b0:      	adrp	x16, 0x10c7000
 10486b4:      	ldr	x17, [x16, #0x898]
 10486b8:      	add	x16, x16, #0x898
 10486bc:      	br	x17

00000000010486c0 <_Z32ARSPMSkottieGetAnimationDurationRPv@plt>:
 10486c0:      	adrp	x16, 0x10c7000
 10486c4:      	ldr	x17, [x16, #0x8a0]
 10486c8:      	add	x16, x16, #0x8a0
 10486cc:      	br	x17

00000000010486d0 <_Z25ARSPMDestroySkottieHandleRPv@plt>:
 10486d0:      	adrp	x16, 0x10c7000
 10486d4:      	ldr	x17, [x16, #0x8a8]
 10486d8:      	add	x16, x16, #0x8a8
 10486dc:      	br	x17

00000000010486e0 <_Z19ARSPMImplementationv@plt>:
 10486e0:      	adrp	x16, 0x10c7000
 10486e4:      	ldr	x17, [x16, #0x8b0]
 10486e8:      	add	x16, x16, #0x8b0
 10486ec:      	br	x17

00000000010486f0 <_Z27ARSPMSkottieGetAnimationFPSRPv@plt>:
 10486f0:      	adrp	x16, 0x10c7000
 10486f4:      	ldr	x17, [x16, #0x8b8]
 10486f8:      	add	x16, x16, #0x8b8
 10486fc:      	br	x17

0000000001048700 <_Z24ARSPMSkottiAnimationDrawRPvfi@plt>:
 1048700:      	adrp	x16, 0x10c7000
 1048704:      	ldr	x17, [x16, #0x8c0]
 1048708:      	add	x16, x16, #0x8c0
 104870c:      	br	x17

0000000001048710 <sin@plt>:
 1048710:      	adrp	x16, 0x10c7000
 1048714:      	ldr	x17, [x16, #0x8c8]
 1048718:      	add	x16, x16, #0x8c8
 104871c:      	br	x17

0000000001048720 <sincosf@plt>:
 1048720:      	adrp	x16, 0x10c7000
 1048724:      	ldr	x17, [x16, #0x8d0]
 1048728:      	add	x16, x16, #0x8d0
 104872c:      	br	x17

0000000001048730 <atan2f@plt>:
 1048730:      	adrp	x16, 0x10c7000
 1048734:      	ldr	x17, [x16, #0x8d8]
 1048738:      	add	x16, x16, #0x8d8
 104873c:      	br	x17

0000000001048740 <opendir@plt>:
 1048740:      	adrp	x16, 0x10c7000
 1048744:      	ldr	x17, [x16, #0x8e0]
 1048748:      	add	x16, x16, #0x8e0
 104874c:      	br	x17

0000000001048750 <readdir@plt>:
 1048750:      	adrp	x16, 0x10c7000
 1048754:      	ldr	x17, [x16, #0x8e8]
 1048758:      	add	x16, x16, #0x8e8
 104875c:      	br	x17

0000000001048760 <closedir@plt>:
 1048760:      	adrp	x16, 0x10c7000
 1048764:      	ldr	x17, [x16, #0x8f0]
 1048768:      	add	x16, x16, #0x8f0
 104876c:      	br	x17

0000000001048770 <fprintf@plt>:
 1048770:      	adrp	x16, 0x10c7000
 1048774:      	ldr	x17, [x16, #0x8f8]
 1048778:      	add	x16, x16, #0x8f8
 104877c:      	br	x17

0000000001048780 <abort@plt>:
 1048780:      	adrp	x16, 0x10c7000
 1048784:      	ldr	x17, [x16, #0x900]
 1048788:      	add	x16, x16, #0x900
 104878c:      	br	x17

0000000001048790 <exp@plt>:
 1048790:      	adrp	x16, 0x10c7000
 1048794:      	ldr	x17, [x16, #0x908]
 1048798:      	add	x16, x16, #0x908
 104879c:      	br	x17

00000000010487a0 <FT_Stroker_Done@plt>:
 10487a0:      	adrp	x16, 0x10c7000
 10487a4:      	ldr	x17, [x16, #0x910]
 10487a8:      	add	x16, x16, #0x910
 10487ac:      	br	x17

00000000010487b0 <FT_Done_Face@plt>:
 10487b0:      	adrp	x16, 0x10c7000
 10487b4:      	ldr	x17, [x16, #0x918]
 10487b8:      	add	x16, x16, #0x918
 10487bc:      	br	x17

00000000010487c0 <FT_Open_Face@plt>:
 10487c0:      	adrp	x16, 0x10c7000
 10487c4:      	ldr	x17, [x16, #0x920]
 10487c8:      	add	x16, x16, #0x920
 10487cc:      	br	x17

00000000010487d0 <FT_New_Memory_Face@plt>:
 10487d0:      	adrp	x16, 0x10c7000
 10487d4:      	ldr	x17, [x16, #0x928]
 10487d8:      	add	x16, x16, #0x928
 10487dc:      	br	x17

00000000010487e0 <FT_Get_Postscript_Name@plt>:
 10487e0:      	adrp	x16, 0x10c7000
 10487e4:      	ldr	x17, [x16, #0x930]
 10487e8:      	add	x16, x16, #0x930
 10487ec:      	br	x17

00000000010487f0 <FT_Stroker_New@plt>:
 10487f0:      	adrp	x16, 0x10c7000
 10487f4:      	ldr	x17, [x16, #0x938]
 10487f8:      	add	x16, x16, #0x938
 10487fc:      	br	x17

0000000001048800 <FT_Select_Charmap@plt>:
 1048800:      	adrp	x16, 0x10c7000
 1048804:      	ldr	x17, [x16, #0x940]
 1048808:      	add	x16, x16, #0x940
 104880c:      	br	x17

0000000001048810 <FT_Set_Pixel_Sizes@plt>:
 1048810:      	adrp	x16, 0x10c7000
 1048814:      	ldr	x17, [x16, #0x948]
 1048818:      	add	x16, x16, #0x948
 104881c:      	br	x17

0000000001048820 <FT_Get_Char_Index@plt>:
 1048820:      	adrp	x16, 0x10c7000
 1048824:      	ldr	x17, [x16, #0x950]
 1048828:      	add	x16, x16, #0x950
 104882c:      	br	x17

0000000001048830 <FT_Load_Glyph@plt>:
 1048830:      	adrp	x16, 0x10c7000
 1048834:      	ldr	x17, [x16, #0x958]
 1048838:      	add	x16, x16, #0x958
 104883c:      	br	x17

0000000001048840 <FT_Get_Glyph@plt>:
 1048840:      	adrp	x16, 0x10c7000
 1048844:      	ldr	x17, [x16, #0x960]
 1048848:      	add	x16, x16, #0x960
 104884c:      	br	x17

0000000001048850 <FT_Glyph_Get_CBox@plt>:
 1048850:      	adrp	x16, 0x10c7000
 1048854:      	ldr	x17, [x16, #0x968]
 1048858:      	add	x16, x16, #0x968
 104885c:      	br	x17

0000000001048860 <FT_Init_FreeType@plt>:
 1048860:      	adrp	x16, 0x10c7000
 1048864:      	ldr	x17, [x16, #0x970]
 1048868:      	add	x16, x16, #0x970
 104886c:      	br	x17

0000000001048870 <clock@plt>:
 1048870:      	adrp	x16, 0x10c7000
 1048874:      	ldr	x17, [x16, #0x978]
 1048878:      	add	x16, x16, #0x978
 104887c:      	br	x17

0000000001048880 <FT_Stroker_Set@plt>:
 1048880:      	adrp	x16, 0x10c7000
 1048884:      	ldr	x17, [x16, #0x980]
 1048888:      	add	x16, x16, #0x980
 104888c:      	br	x17

0000000001048890 <FT_Glyph_StrokeBorder@plt>:
 1048890:      	adrp	x16, 0x10c7000
 1048894:      	ldr	x17, [x16, #0x988]
 1048898:      	add	x16, x16, #0x988
 104889c:      	br	x17

00000000010488a0 <FT_Glyph_To_Bitmap@plt>:
 10488a0:      	adrp	x16, 0x10c7000
 10488a4:      	ldr	x17, [x16, #0x990]
 10488a8:      	add	x16, x16, #0x990
 10488ac:      	br	x17

00000000010488b0 <FT_Done_Glyph@plt>:
 10488b0:      	adrp	x16, 0x10c7000
 10488b4:      	ldr	x17, [x16, #0x998]
 10488b8:      	add	x16, x16, #0x998
 10488bc:      	br	x17

00000000010488c0 <FT_Get_Kerning@plt>:
 10488c0:      	adrp	x16, 0x10c7000
 10488c4:      	ldr	x17, [x16, #0x9a0]
 10488c8:      	add	x16, x16, #0x9a0
 10488cc:      	br	x17

00000000010488d0 <_Z24ARSPMGetBidiVisualIndexsPKci@plt>:
 10488d0:      	adrp	x16, 0x10c7000
 10488d4:      	ldr	x17, [x16, #0x9a8]
 10488d8:      	add	x16, x16, #0x9a8
 10488dc:      	br	x17

00000000010488e0 <tan@plt>:
 10488e0:      	adrp	x16, 0x10c7000
 10488e4:      	ldr	x17, [x16, #0x9b0]
 10488e8:      	add	x16, x16, #0x9b0
 10488ec:      	br	x17

00000000010488f0 <FT_Done_FreeType@plt>:
 10488f0:      	adrp	x16, 0x10c7000
 10488f4:      	ldr	x17, [x16, #0x9b8]
 10488f8:      	add	x16, x16, #0x9b8
 10488fc:      	br	x17

0000000001048900 <_Z14ARSPMShapeTextPKciRNSt6__ndk16vectorINS2_IjNS1_9allocatorIjEEEENS3_IS5_EEEE@plt>:
 1048900:      	adrp	x16, 0x10c7000
 1048904:      	ldr	x17, [x16, #0x9c0]
 1048908:      	add	x16, x16, #0x9c0
 104890c:      	br	x17

0000000001048910 <_Z16ARSPMSkCreateSvgPKvmb@plt>:
 1048910:      	adrp	x16, 0x10c7000
 1048914:      	ldr	x17, [x16, #0x9c8]
 1048918:      	add	x16, x16, #0x9c8
 104891c:      	br	x17

0000000001048920 <_Z15ARSPMSkSvgScalePvff@plt>:
 1048920:      	adrp	x16, 0x10c7000
 1048924:      	ldr	x17, [x16, #0x9d0]
 1048928:      	add	x16, x16, #0x9d0
 104892c:      	br	x17

0000000001048930 <_Z16ARSPMSkSvgRenderPvR12SVG2RGBADataii@plt>:
 1048930:      	adrp	x16, 0x10c7000
 1048934:      	ldr	x17, [x16, #0x9d8]
 1048938:      	add	x16, x16, #0x9d8
 104893c:      	br	x17

0000000001048940 <_Z17ARSPMSkSvgDestroyPv@plt>:
 1048940:      	adrp	x16, 0x10c7000
 1048944:      	ldr	x17, [x16, #0x9e0]
 1048948:      	add	x16, x16, #0x9e0
 104894c:      	br	x17

0000000001048950 <arc4random@plt>:
 1048950:      	adrp	x16, 0x10c7000
 1048954:      	ldr	x17, [x16, #0x9e8]
 1048958:      	add	x16, x16, #0x9e8
 104895c:      	br	x17

0000000001048960 <rand@plt>:
 1048960:      	adrp	x16, 0x10c7000
 1048964:      	ldr	x17, [x16, #0x9f0]
 1048968:      	add	x16, x16, #0x9f0
 104896c:      	br	x17

0000000001048970 <time@plt>:
 1048970:      	adrp	x16, 0x10c7000
 1048974:      	ldr	x17, [x16, #0x9f8]
 1048978:      	add	x16, x16, #0x9f8
 104897c:      	br	x17

0000000001048980 <srand@plt>:
 1048980:      	adrp	x16, 0x10c7000
 1048984:      	ldr	x17, [x16, #0xa00]
 1048988:      	add	x16, x16, #0xa00
 104898c:      	br	x17

0000000001048990 <_Z21ARSPMSkSvgSegmentPathPvffbf@plt>:
 1048990:      	adrp	x16, 0x10c7000
 1048994:      	ldr	x17, [x16, #0xa08]
 1048998:      	add	x16, x16, #0xa08
 104899c:      	br	x17

00000000010489a0 <_Z14ARSPMSkSvgMovePvff@plt>:
 10489a0:      	adrp	x16, 0x10c7000
 10489a4:      	ldr	x17, [x16, #0xa10]
 10489a8:      	add	x16, x16, #0xa10
 10489ac:      	br	x17

00000000010489b0 <_Z23ARSPMSkSvgTransformPathPvfffff@plt>:
 10489b0:      	adrp	x16, 0x10c7000
 10489b4:      	ldr	x17, [x16, #0xa18]
 10489b8:      	add	x16, x16, #0xa18
 10489bc:      	br	x17

00000000010489c0 <_Z20ARSPMTaperStrokePathPvf@plt>:
 10489c0:      	adrp	x16, 0x10c7000
 10489c4:      	ldr	x17, [x16, #0xa20]
 10489c8:      	add	x16, x16, #0xa20
 10489cc:      	br	x17

00000000010489d0 <cosf@plt>:
 10489d0:      	adrp	x16, 0x10c7000
 10489d4:      	ldr	x17, [x16, #0xa28]
 10489d8:      	add	x16, x16, #0xa28
 10489dc:      	br	x17

00000000010489e0 <sinf@plt>:
 10489e0:      	adrp	x16, 0x10c7000
 10489e4:      	ldr	x17, [x16, #0xa30]
 10489e8:      	add	x16, x16, #0xa30
 10489ec:      	br	x17

00000000010489f0 <expf@plt>:
 10489f0:      	adrp	x16, 0x10c7000
 10489f4:      	ldr	x17, [x16, #0xa38]
 10489f8:      	add	x16, x16, #0xa38
 10489fc:      	br	x17

0000000001048a00 <strncpy@plt>:
 1048a00:      	adrp	x16, 0x10c7000
 1048a04:      	ldr	x17, [x16, #0xa40]
 1048a08:      	add	x16, x16, #0xa40
 1048a0c:      	br	x17

0000000001048a10 <__open_2@plt>:
 1048a10:      	adrp	x16, 0x10c7000
 1048a14:      	ldr	x17, [x16, #0xa48]
 1048a18:      	add	x16, x16, #0xa48
 1048a1c:      	br	x17

0000000001048a20 <mmap@plt>:
 1048a20:      	adrp	x16, 0x10c7000
 1048a24:      	ldr	x17, [x16, #0xa50]
 1048a28:      	add	x16, x16, #0xa50
 1048a2c:      	br	x17

0000000001048a30 <close@plt>:
 1048a30:      	adrp	x16, 0x10c7000
 1048a34:      	ldr	x17, [x16, #0xa58]
 1048a38:      	add	x16, x16, #0xa58
 1048a3c:      	br	x17

0000000001048a40 <munmap@plt>:
 1048a40:      	adrp	x16, 0x10c7000
 1048a44:      	ldr	x17, [x16, #0xa60]
 1048a48:      	add	x16, x16, #0xa60
 1048a4c:      	br	x17

0000000001048a50 <cos@plt>:
 1048a50:      	adrp	x16, 0x10c7000
 1048a54:      	ldr	x17, [x16, #0xa68]
 1048a58:      	add	x16, x16, #0xa68
 1048a5c:      	br	x17

0000000001048a60 <logf@plt>:
 1048a60:      	adrp	x16, 0x10c7000
 1048a64:      	ldr	x17, [x16, #0xa70]
 1048a68:      	add	x16, x16, #0xa70
 1048a6c:      	br	x17

0000000001048a70 <puts@plt>:
 1048a70:      	adrp	x16, 0x10c7000
 1048a74:      	ldr	x17, [x16, #0xa78]
 1048a78:      	add	x16, x16, #0xa78
 1048a7c:      	br	x17

0000000001048a80 <sched_yield@plt>:
 1048a80:      	adrp	x16, 0x10c7000
 1048a84:      	ldr	x17, [x16, #0xa80]
 1048a88:      	add	x16, x16, #0xa80
 1048a8c:      	br	x17

0000000001048a90 <asinf@plt>:
 1048a90:      	adrp	x16, 0x10c7000
 1048a94:      	ldr	x17, [x16, #0xa88]
 1048a98:      	add	x16, x16, #0xa88
 1048a9c:      	br	x17

0000000001048aa0 <FT_Set_Char_Size@plt>:
 1048aa0:      	adrp	x16, 0x10c7000
 1048aa4:      	ldr	x17, [x16, #0xa90]
 1048aa8:      	add	x16, x16, #0xa90
 1048aac:      	br	x17

0000000001048ab0 <sscanf@plt>:
 1048ab0:      	adrp	x16, 0x10c7000
 1048ab4:      	ldr	x17, [x16, #0xa98]
 1048ab8:      	add	x16, x16, #0xa98
 1048abc:      	br	x17

0000000001048ac0 <__vsnprintf_chk@plt>:
 1048ac0:      	adrp	x16, 0x10c7000
 1048ac4:      	ldr	x17, [x16, #0xaa0]
 1048ac8:      	add	x16, x16, #0xaa0
 1048acc:      	br	x17

0000000001048ad0 <__strncpy_chk2@plt>:
 1048ad0:      	adrp	x16, 0x10c7000
 1048ad4:      	ldr	x17, [x16, #0xaa8]
 1048ad8:      	add	x16, x16, #0xaa8
 1048adc:      	br	x17

0000000001048ae0 <ScalePlane@plt>:
 1048ae0:      	adrp	x16, 0x10c7000
 1048ae4:      	ldr	x17, [x16, #0xab0]
 1048ae8:      	add	x16, x16, #0xab0
 1048aec:      	br	x17

0000000001048af0 <I400Mirror@plt>:
 1048af0:      	adrp	x16, 0x10c7000
 1048af4:      	ldr	x17, [x16, #0xab8]
 1048af8:      	add	x16, x16, #0xab8
 1048afc:      	br	x17

0000000001048b00 <ARGBMirror@plt>:
 1048b00:      	adrp	x16, 0x10c7000
 1048b04:      	ldr	x17, [x16, #0xac0]
 1048b08:      	add	x16, x16, #0xac0
 1048b0c:      	br	x17

0000000001048b10 <RotatePlane270@plt>:
 1048b10:      	adrp	x16, 0x10c7000
 1048b14:      	ldr	x17, [x16, #0xac8]
 1048b18:      	add	x16, x16, #0xac8
 1048b1c:      	br	x17

0000000001048b20 <RotatePlane180@plt>:
 1048b20:      	adrp	x16, 0x10c7000
 1048b24:      	ldr	x17, [x16, #0xad0]
 1048b28:      	add	x16, x16, #0xad0
 1048b2c:      	br	x17

0000000001048b30 <RotatePlane90@plt>:
 1048b30:      	adrp	x16, 0x10c7000
 1048b34:      	ldr	x17, [x16, #0xad8]
 1048b38:      	add	x16, x16, #0xad8
 1048b3c:      	br	x17

0000000001048b40 <ARGBRotate@plt>:
 1048b40:      	adrp	x16, 0x10c7000
 1048b44:      	ldr	x17, [x16, #0xae0]
 1048b48:      	add	x16, x16, #0xae0
 1048b4c:      	br	x17

0000000001048b50 <fscanf@plt>:
 1048b50:      	adrp	x16, 0x10c7000
 1048b54:      	ldr	x17, [x16, #0xae8]
 1048b58:      	add	x16, x16, #0xae8
 1048b5c:      	br	x17

0000000001048b60 <log@plt>:
 1048b60:      	adrp	x16, 0x10c7000
 1048b64:      	ldr	x17, [x16, #0xaf0]
 1048b68:      	add	x16, x16, #0xaf0
 1048b6c:      	br	x17

0000000001048b70 <acos@plt>:
 1048b70:      	adrp	x16, 0x10c7000
 1048b74:      	ldr	x17, [x16, #0xaf8]
 1048b78:      	add	x16, x16, #0xaf8
 1048b7c:      	br	x17

0000000001048b80 <ARGBScale@plt>:
 1048b80:      	adrp	x16, 0x10c7000
 1048b84:      	ldr	x17, [x16, #0xb00]
 1048b88:      	add	x16, x16, #0xb00
 1048b8c:      	br	x17

0000000001048b90 <ABGRToI400@plt>:
 1048b90:      	adrp	x16, 0x10c7000
 1048b94:      	ldr	x17, [x16, #0xb08]
 1048b98:      	add	x16, x16, #0xb08
 1048b9c:      	br	x17

0000000001048ba0 <ARGBToI400@plt>:
 1048ba0:      	adrp	x16, 0x10c7000
 1048ba4:      	ldr	x17, [x16, #0xb10]
 1048ba8:      	add	x16, x16, #0xb10
 1048bac:      	br	x17

0000000001048bb0 <dlopen@plt>:
 1048bb0:      	adrp	x16, 0x10c7000
 1048bb4:      	ldr	x17, [x16, #0xb18]
 1048bb8:      	add	x16, x16, #0xb18
 1048bbc:      	br	x17

0000000001048bc0 <dlsym@plt>:
 1048bc0:      	adrp	x16, 0x10c7000
 1048bc4:      	ldr	x17, [x16, #0xb20]
 1048bc8:      	add	x16, x16, #0xb20
 1048bcc:      	br	x17

0000000001048bd0 <dlclose@plt>:
 1048bd0:      	adrp	x16, 0x10c7000
 1048bd4:      	ldr	x17, [x16, #0xb28]
 1048bd8:      	add	x16, x16, #0xb28
 1048bdc:      	br	x17

0000000001048be0 <_Z16MTARMPMSetJavaVMPv@plt>:
 1048be0:      	adrp	x16, 0x10c7000
 1048be4:      	ldr	x17, [x16, #0xb30]
 1048be8:      	add	x16, x16, #0xb30
 1048bec:      	br	x17

0000000001048bf0 <_Z19MTARMPMServiceStartv@plt>:
 1048bf0:      	adrp	x16, 0x10c7000
 1048bf4:      	ldr	x17, [x16, #0xb38]
 1048bf8:      	add	x16, x16, #0xb38
 1048bfc:      	br	x17

0000000001048c00 <_Z19MTARMPMServicePausei@plt>:
 1048c00:      	adrp	x16, 0x10c7000
 1048c04:      	ldr	x17, [x16, #0xb40]
 1048c08:      	add	x16, x16, #0xb40
 1048c0c:      	br	x17

0000000001048c10 <_Z18MTARMPMServiceStopv@plt>:
 1048c10:      	adrp	x16, 0x10c7000
 1048c14:      	ldr	x17, [x16, #0xb48]
 1048c18:      	add	x16, x16, #0xb48
 1048c1c:      	br	x17

0000000001048c20 <_Z23MTARMPMServiceIsStoppedv@plt>:
 1048c20:      	adrp	x16, 0x10c7000
 1048c24:      	ldr	x17, [x16, #0xb50]
 1048c28:      	add	x16, x16, #0xb50
 1048c2c:      	br	x17

0000000001048c30 <_Z24MTARMPMCreateMusicHandlev@plt>:
 1048c30:      	adrp	x16, 0x10c7000
 1048c34:      	ldr	x17, [x16, #0xb58]
 1048c38:      	add	x16, x16, #0xb58
 1048c3c:      	br	x17

0000000001048c40 <_Z16MTARMPMMusicLoadPvPKc@plt>:
 1048c40:      	adrp	x16, 0x10c7000
 1048c44:      	ldr	x17, [x16, #0xb60]
 1048c48:      	add	x16, x16, #0xb60
 1048c4c:      	br	x17

0000000001048c50 <_Z25MTARMPMMusicSetFuncStructPvS_@plt>:
 1048c50:      	adrp	x16, 0x10c7000
 1048c54:      	ldr	x17, [x16, #0xb68]
 1048c58:      	add	x16, x16, #0xb68
 1048c5c:      	br	x17

0000000001048c60 <_Z22MTARMPMMusicSetLoopingPvi@plt>:
 1048c60:      	adrp	x16, 0x10c7000
 1048c64:      	ldr	x17, [x16, #0xb70]
 1048c68:      	add	x16, x16, #0xb70
 1048c6c:      	br	x17

0000000001048c70 <_Z24MTARMPMMusicGetLoopCountPv@plt>:
 1048c70:      	adrp	x16, 0x10c7000
 1048c74:      	ldr	x17, [x16, #0xb78]
 1048c78:      	add	x16, x16, #0xb78
 1048c7c:      	br	x17

0000000001048c80 <_Z23MTARMPMMusicGetPositionPv@plt>:
 1048c80:      	adrp	x16, 0x10c7000
 1048c84:      	ldr	x17, [x16, #0xb80]
 1048c88:      	add	x16, x16, #0xb80
 1048c8c:      	br	x17

0000000001048c90 <_Z23MTARMPMMusicGetDurationPv@plt>:
 1048c90:      	adrp	x16, 0x10c7000
 1048c94:      	ldr	x17, [x16, #0xb88]
 1048c98:      	add	x16, x16, #0xb88
 1048c9c:      	br	x17

0000000001048ca0 <_Z19MTARMPMMusicDisposePv@plt>:
 1048ca0:      	adrp	x16, 0x10c7000
 1048ca4:      	ldr	x17, [x16, #0xb90]
 1048ca8:      	add	x16, x16, #0xb90
 1048cac:      	br	x17

0000000001048cb0 <_Z25MTARMPMDestroyMusicHandleRPv@plt>:
 1048cb0:      	adrp	x16, 0x10c7000
 1048cb4:      	ldr	x17, [x16, #0xb98]
 1048cb8:      	add	x16, x16, #0xb98
 1048cbc:      	br	x17

0000000001048cc0 <_Z16MTARMPMMusicPlayPv@plt>:
 1048cc0:      	adrp	x16, 0x10c7000
 1048cc4:      	ldr	x17, [x16, #0xba0]
 1048cc8:      	add	x16, x16, #0xba0
 1048ccc:      	br	x17

0000000001048cd0 <_Z17MTARMPMMusicPausePv@plt>:
 1048cd0:      	adrp	x16, 0x10c7000
 1048cd4:      	ldr	x17, [x16, #0xba8]
 1048cd8:      	add	x16, x16, #0xba8
 1048cdc:      	br	x17

0000000001048ce0 <_Z16MTARMPMMusicStopPv@plt>:
 1048ce0:      	adrp	x16, 0x10c7000
 1048ce4:      	ldr	x17, [x16, #0xbb0]
 1048ce8:      	add	x16, x16, #0xbb0
 1048cec:      	br	x17

0000000001048cf0 <_Z21MTARMPMMusicSetVolumePvf@plt>:
 1048cf0:      	adrp	x16, 0x10c7000
 1048cf4:      	ldr	x17, [x16, #0xbb8]
 1048cf8:      	add	x16, x16, #0xbb8
 1048cfc:      	br	x17

0000000001048d00 <_Z23MTARMPMMusicSetPositionPvf@plt>:
 1048d00:      	adrp	x16, 0x10c7000
 1048d04:      	ldr	x17, [x16, #0xbc0]
 1048d08:      	add	x16, x16, #0xbc0
 1048d0c:      	br	x17

0000000001048d10 <_Z20MTARMPMMusicSetSpeedPvf@plt>:
 1048d10:      	adrp	x16, 0x10c7000
 1048d14:      	ldr	x17, [x16, #0xbc8]
 1048d18:      	add	x16, x16, #0xbc8
 1048d1c:      	br	x17

0000000001048d20 <_Z20MTARMPMMusicGetSpeedPv@plt>:
 1048d20:      	adrp	x16, 0x10c7000
 1048d24:      	ldr	x17, [x16, #0xbd0]
 1048d28:      	add	x16, x16, #0xbd0
 1048d2c:      	br	x17

0000000001048d30 <atan2@plt>:
 1048d30:      	adrp	x16, 0x10c7000
 1048d34:      	ldr	x17, [x16, #0xbd8]
 1048d38:      	add	x16, x16, #0xbd8
 1048d3c:      	br	x17

0000000001048d40 <_ZN7MMCodec16mediaReaderCloseEPv@plt>:
 1048d40:      	adrp	x16, 0x10c7000
 1048d44:      	ldr	x17, [x16, #0xbe0]
 1048d48:      	add	x16, x16, #0xbe0
 1048d4c:      	br	x17

0000000001048d50 <_ZN7MMCodec18mediaReaderCleanupEPv@plt>:
 1048d50:      	adrp	x16, 0x10c7000
 1048d54:      	ldr	x17, [x16, #0xbe8]
 1048d58:      	add	x16, x16, #0xbe8
 1048d5c:      	br	x17

0000000001048d60 <_ZN7MMCodec24releaseMediaReaderHandleEPPv@plt>:
 1048d60:      	adrp	x16, 0x10c7000
 1048d64:      	ldr	x17, [x16, #0xbf0]
 1048d68:      	add	x16, x16, #0xbf0
 1048d6c:      	br	x17

0000000001048d70 <_ZN7MMCodec28releaseMediaReadOptionHandleEPPv@plt>:
 1048d70:      	adrp	x16, 0x10c7000
 1048d74:      	ldr	x17, [x16, #0xbf8]
 1048d78:      	add	x16, x16, #0xbf8
 1048d7c:      	br	x17

0000000001048d80 <_ZN7MMCodec28releaseMediaVideoFrameHandleEPPv@plt>:
 1048d80:      	adrp	x16, 0x10c7000
 1048d84:      	ldr	x17, [x16, #0xc00]
 1048d88:      	add	x16, x16, #0xc00
 1048d8c:      	br	x17

0000000001048d90 <_ZN7MMCodec27releaseMediaFrameInfoHandleEPPv@plt>:
 1048d90:      	adrp	x16, 0x10c7000
 1048d94:      	ldr	x17, [x16, #0xc08]
 1048d98:      	add	x16, x16, #0xc08
 1048d9c:      	br	x17

0000000001048da0 <_ZN7MMCodec21mediaReaderGlobalInitEv@plt>:
 1048da0:      	adrp	x16, 0x10c7000
 1048da4:      	ldr	x17, [x16, #0xc10]
 1048da8:      	add	x16, x16, #0xc10
 1048dac:      	br	x17

0000000001048db0 <_ZN7MMCodec23createMediaReaderHandleEPKc@plt>:
 1048db0:      	adrp	x16, 0x10c7000
 1048db4:      	ldr	x17, [x16, #0xc18]
 1048db8:      	add	x16, x16, #0xc18
 1048dbc:      	br	x17

0000000001048dc0 <_ZN7MMCodec26createMediaFrameInfoHandleEv@plt>:
 1048dc0:      	adrp	x16, 0x10c7000
 1048dc4:      	ldr	x17, [x16, #0xc20]
 1048dc8:      	add	x16, x16, #0xc20
 1048dcc:      	br	x17

0000000001048dd0 <_ZN7MMCodec27createMediaVideoFrameHandleEv@plt>:
 1048dd0:      	adrp	x16, 0x10c7000
 1048dd4:      	ldr	x17, [x16, #0xc28]
 1048dd8:      	add	x16, x16, #0xc28
 1048ddc:      	br	x17

0000000001048de0 <_ZN7MMCodec27createMediaReadOptionHandleEv@plt>:
 1048de0:      	adrp	x16, 0x10c7000
 1048de4:      	ldr	x17, [x16, #0xc30]
 1048de8:      	add	x16, x16, #0xc30
 1048dec:      	br	x17

0000000001048df0 <_ZN7MMCodec29mediaReaderSetSharedGLContextEPvS0_@plt>:
 1048df0:      	adrp	x16, 0x10c7000
 1048df4:      	ldr	x17, [x16, #0xc38]
 1048df8:      	add	x16, x16, #0xc38
 1048dfc:      	br	x17

0000000001048e00 <_ZN7MMCodec22mediaReaderEnableAudioEPvb@plt>:
 1048e00:      	adrp	x16, 0x10c7000
 1048e04:      	ldr	x17, [x16, #0xc40]
 1048e08:      	add	x16, x16, #0xc40
 1048e0c:      	br	x17

0000000001048e10 <_ZN7MMCodec25mediaReaderEnableHardWareEPvb@plt>:
 1048e10:      	adrp	x16, 0x10c7000
 1048e14:      	ldr	x17, [x16, #0xc48]
 1048e18:      	add	x16, x16, #0xc48
 1048e1c:      	br	x17

0000000001048e20 <_ZN7MMCodec15mediaReaderOpenEPv@plt>:
 1048e20:      	adrp	x16, 0x10c7000
 1048e24:      	ldr	x17, [x16, #0xc50]
 1048e28:      	add	x16, x16, #0xc50
 1048e2c:      	br	x17

0000000001048e30 <_ZN7MMCodec19mediaReaderGetWidthEPv@plt>:
 1048e30:      	adrp	x16, 0x10c7000
 1048e34:      	ldr	x17, [x16, #0xc58]
 1048e38:      	add	x16, x16, #0xc58
 1048e3c:      	br	x17

0000000001048e40 <_ZN7MMCodec20mediaReaderGetHeightEPv@plt>:
 1048e40:      	adrp	x16, 0x10c7000
 1048e44:      	ldr	x17, [x16, #0xc60]
 1048e48:      	add	x16, x16, #0xc60
 1048e4c:      	br	x17

0000000001048e50 <_ZN7MMCodec22mediaReaderGetDurationEPv@plt>:
 1048e50:      	adrp	x16, 0x10c7000
 1048e54:      	ldr	x17, [x16, #0xc68]
 1048e58:      	add	x16, x16, #0xc68
 1048e5c:      	br	x17

0000000001048e60 <_ZN7MMCodec17mediaReaderGetFpsEPv@plt>:
 1048e60:      	adrp	x16, 0x10c7000
 1048e64:      	ldr	x17, [x16, #0xc70]
 1048e68:      	add	x16, x16, #0xc70
 1048e6c:      	br	x17

0000000001048e70 <_ZN7MMCodec23mediaReaderStartDecoderEPvll@plt>:
 1048e70:      	adrp	x16, 0x10c7000
 1048e74:      	ldr	x17, [x16, #0xc78]
 1048e78:      	add	x16, x16, #0xc78
 1048e7c:      	br	x17

0000000001048e80 <_ZN7MMCodec17mediaReaderSeekToEPvli@plt>:
 1048e80:      	adrp	x16, 0x10c7000
 1048e84:      	ldr	x17, [x16, #0xc80]
 1048e88:      	add	x16, x16, #0xc80
 1048e8c:      	br	x17

0000000001048e90 <_ZN7MMCodec22mediaReaderStopDecoderEPv@plt>:
 1048e90:      	adrp	x16, 0x10c7000
 1048e94:      	ldr	x17, [x16, #0xc88]
 1048e98:      	add	x16, x16, #0xc88
 1048e9c:      	br	x17

0000000001048ea0 <_ZN7MMCodec25setMediaReadOptionTimeoutEPvi@plt>:
 1048ea0:      	adrp	x16, 0x10c7000
 1048ea4:      	ldr	x17, [x16, #0xc90]
 1048ea8:      	add	x16, x16, #0xc90
 1048eac:      	br	x17

0000000001048eb0 <_ZN7MMCodec24mediaReaderGetVideoFrameEPvlS0_S0_S0_@plt>:
 1048eb0:      	adrp	x16, 0x10c7000
 1048eb4:      	ldr	x17, [x16, #0xc98]
 1048eb8:      	add	x16, x16, #0xc98
 1048ebc:      	br	x17

0000000001048ec0 <_ZN7MMCodec33mediaReaderIsVideoHardwareDecoderEPv@plt>:
 1048ec0:      	adrp	x16, 0x10c7000
 1048ec4:      	ldr	x17, [x16, #0xca0]
 1048ec8:      	add	x16, x16, #0xca0
 1048ecc:      	br	x17

0000000001048ed0 <_ZN7MMCodec25getMediaVideoFrameTextureEPv@plt>:
 1048ed0:      	adrp	x16, 0x10c7000
 1048ed4:      	ldr	x17, [x16, #0xca8]
 1048ed8:      	add	x16, x16, #0xca8
 1048edc:      	br	x17

0000000001048ee0 <_ZN7MMCodec22getMediaVideoFrameDataEPv@plt>:
 1048ee0:      	adrp	x16, 0x10c7000
 1048ee4:      	ldr	x17, [x16, #0xcb0]
 1048ee8:      	add	x16, x16, #0xcb0
 1048eec:      	br	x17

0000000001048ef0 <_ZN7MMCodec22mediaReaderGetHasVideoEPv@plt>:
 1048ef0:      	adrp	x16, 0x10c7000
 1048ef4:      	ldr	x17, [x16, #0xcb8]
 1048ef8:      	add	x16, x16, #0xcb8
 1048efc:      	br	x17

0000000001048f00 <_ZN7MMCodec24mediaReaderGetVideoFrameEPvlS0_S0_@plt>:
 1048f00:      	adrp	x16, 0x10c7000
 1048f04:      	ldr	x17, [x16, #0xcc0]
 1048f08:      	add	x16, x16, #0xcc0
 1048f0c:      	br	x17

0000000001048f10 <strcasecmp@plt>:
 1048f10:      	adrp	x16, 0x10c7000
 1048f14:      	ldr	x17, [x16, #0xcc8]
 1048f18:      	add	x16, x16, #0xcc8
 1048f1c:      	br	x17

0000000001048f20 <realpath@plt>:
 1048f20:      	adrp	x16, 0x10c7000
 1048f24:      	ldr	x17, [x16, #0xcd0]
 1048f28:      	add	x16, x16, #0xcd0
 1048f2c:      	br	x17

0000000001048f30 <strncasecmp@plt>:
 1048f30:      	adrp	x16, 0x10c7000
 1048f34:      	ldr	x17, [x16, #0xcd8]
 1048f38:      	add	x16, x16, #0xcd8
 1048f3c:      	br	x17

0000000001048f40 <__strcpy_chk@plt>:
 1048f40:      	adrp	x16, 0x10c7000
 1048f44:      	ldr	x17, [x16, #0xce0]
 1048f48:      	add	x16, x16, #0xce0
 1048f4c:      	br	x17

0000000001048f50 <strtoul@plt>:
 1048f50:      	adrp	x16, 0x10c7000
 1048f54:      	ldr	x17, [x16, #0xce8]
 1048f58:      	add	x16, x16, #0xce8
 1048f5c:      	br	x17

0000000001048f60 <strrchr@plt>:
 1048f60:      	adrp	x16, 0x10c7000
 1048f64:      	ldr	x17, [x16, #0xcf0]
 1048f68:      	add	x16, x16, #0xcf0
 1048f6c:      	br	x17

0000000001048f70 <strtok@plt>:
 1048f70:      	adrp	x16, 0x10c7000
 1048f74:      	ldr	x17, [x16, #0xcf8]
 1048f78:      	add	x16, x16, #0xcf8
 1048f7c:      	br	x17

0000000001048f80 <mkdir@plt>:
 1048f80:      	adrp	x16, 0x10c7000
 1048f84:      	ldr	x17, [x16, #0xd00]
 1048f88:      	add	x16, x16, #0xd00
 1048f8c:      	br	x17

0000000001048f90 <dirname@plt>:
 1048f90:      	adrp	x16, 0x10c7000
 1048f94:      	ldr	x17, [x16, #0xd08]
 1048f98:      	add	x16, x16, #0xd08
 1048f9c:      	br	x17

0000000001048fa0 <rewind@plt>:
 1048fa0:      	adrp	x16, 0x10c7000
 1048fa4:      	ldr	x17, [x16, #0xd10]
 1048fa8:      	add	x16, x16, #0xd10
 1048fac:      	br	x17

0000000001048fb0 <strcspn@plt>:
 1048fb0:      	adrp	x16, 0x10c7000
 1048fb4:      	ldr	x17, [x16, #0xd18]
 1048fb8:      	add	x16, x16, #0xd18
 1048fbc:      	br	x17

0000000001048fc0 <exit@plt>:
 1048fc0:      	adrp	x16, 0x10c7000
 1048fc4:      	ldr	x17, [x16, #0xd20]
 1048fc8:      	add	x16, x16, #0xd20
 1048fcc:      	br	x17

0000000001048fd0 <modff@plt>:
 1048fd0:      	adrp	x16, 0x10c7000
 1048fd4:      	ldr	x17, [x16, #0xd28]
 1048fd8:      	add	x16, x16, #0xd28
 1048fdc:      	br	x17

0000000001048fe0 <clock_gettime@plt>:
 1048fe0:      	adrp	x16, 0x10c7000
 1048fe4:      	ldr	x17, [x16, #0xd30]
 1048fe8:      	add	x16, x16, #0xd30
 1048fec:      	br	x17

0000000001048ff0 <exp2@plt>:
 1048ff0:      	adrp	x16, 0x10c7000
 1048ff4:      	ldr	x17, [x16, #0xd38]
 1048ff8:      	add	x16, x16, #0xd38
 1048ffc:      	br	x17

0000000001049000 <FT_Get_Advance@plt>:
 1049000:      	adrp	x16, 0x10c7000
 1049004:      	ldr	x17, [x16, #0xd40]
 1049008:      	add	x16, x16, #0xd40
 104900c:      	br	x17

0000000001049010 <FT_Get_Advances@plt>:
 1049010:      	adrp	x16, 0x10c7000
 1049014:      	ldr	x17, [x16, #0xd48]
 1049018:      	add	x16, x16, #0xd48
 104901c:      	br	x17

0000000001049020 <FT_Outline_Check@plt>:
 1049020:      	adrp	x16, 0x10c7000
 1049024:      	ldr	x17, [x16, #0xd50]
 1049028:      	add	x16, x16, #0xd50
 104902c:      	br	x17

0000000001049030 <FT_Vector_Transform@plt>:
 1049030:      	adrp	x16, 0x10c7000
 1049034:      	ldr	x17, [x16, #0xd58]
 1049038:      	add	x16, x16, #0xd58
 104903c:      	br	x17

0000000001049040 <FT_RoundFix@plt>:
 1049040:      	adrp	x16, 0x10c7000
 1049044:      	ldr	x17, [x16, #0xd60]
 1049048:      	add	x16, x16, #0xd60
 104904c:      	br	x17

0000000001049050 <FT_Vector_Length@plt>:
 1049050:      	adrp	x16, 0x10c7000
 1049054:      	ldr	x17, [x16, #0xd68]
 1049058:      	add	x16, x16, #0xd68
 104905c:      	br	x17

0000000001049060 <FT_MulDiv@plt>:
 1049060:      	adrp	x16, 0x10c7000
 1049064:      	ldr	x17, [x16, #0xd70]
 1049068:      	add	x16, x16, #0xd70
 104906c:      	br	x17

0000000001049070 <FT_MulFix@plt>:
 1049070:      	adrp	x16, 0x10c7000
 1049074:      	ldr	x17, [x16, #0xd78]
 1049078:      	add	x16, x16, #0xd78
 104907c:      	br	x17

0000000001049080 <FT_DivFix@plt>:
 1049080:      	adrp	x16, 0x10c7000
 1049084:      	ldr	x17, [x16, #0xd80]
 1049088:      	add	x16, x16, #0xd80
 104908c:      	br	x17

0000000001049090 <FT_Matrix_Invert@plt>:
 1049090:      	adrp	x16, 0x10c7000
 1049094:      	ldr	x17, [x16, #0xd88]
 1049098:      	add	x16, x16, #0xd88
 104909c:      	br	x17

00000000010490a0 <FT_Outline_Get_CBox@plt>:
 10490a0:      	adrp	x16, 0x10c7000
 10490a4:      	ldr	x17, [x16, #0xd90]
 10490a8:      	add	x16, x16, #0xd90
 10490ac:      	br	x17

00000000010490b0 <FT_Outline_Transform@plt>:
 10490b0:      	adrp	x16, 0x10c7000
 10490b4:      	ldr	x17, [x16, #0xd98]
 10490b8:      	add	x16, x16, #0xd98
 10490bc:      	br	x17

00000000010490c0 <FT_Outline_Translate@plt>:
 10490c0:      	adrp	x16, 0x10c7000
 10490c4:      	ldr	x17, [x16, #0xda0]
 10490c8:      	add	x16, x16, #0xda0
 10490cc:      	br	x17

00000000010490d0 <FT_New_Size@plt>:
 10490d0:      	adrp	x16, 0x10c7000
 10490d4:      	ldr	x17, [x16, #0xda8]
 10490d8:      	add	x16, x16, #0xda8
 10490dc:      	br	x17

00000000010490e0 <FT_Attach_Stream@plt>:
 10490e0:      	adrp	x16, 0x10c7000
 10490e4:      	ldr	x17, [x16, #0xdb0]
 10490e8:      	add	x16, x16, #0xdb0
 10490ec:      	br	x17

00000000010490f0 <FT_List_Find@plt>:
 10490f0:      	adrp	x16, 0x10c7000
 10490f4:      	ldr	x17, [x16, #0xdb8]
 10490f8:      	add	x16, x16, #0xdb8
 10490fc:      	br	x17

0000000001049100 <FT_List_Add@plt>:
 1049100:      	adrp	x16, 0x10c7000
 1049104:      	ldr	x17, [x16, #0xdc0]
 1049108:      	add	x16, x16, #0xdc0
 104910c:      	br	x17

0000000001049110 <FT_Done_Size@plt>:
 1049110:      	adrp	x16, 0x10c7000
 1049114:      	ldr	x17, [x16, #0xdc8]
 1049118:      	add	x16, x16, #0xdc8
 104911c:      	br	x17

0000000001049120 <FT_Select_Size@plt>:
 1049120:      	adrp	x16, 0x10c7000
 1049124:      	ldr	x17, [x16, #0xdd0]
 1049128:      	add	x16, x16, #0xdd0
 104912c:      	br	x17

0000000001049130 <FT_Request_Size@plt>:
 1049130:      	adrp	x16, 0x10c7000
 1049134:      	ldr	x17, [x16, #0xdd8]
 1049138:      	add	x16, x16, #0xdd8
 104913c:      	br	x17

0000000001049140 <FT_Set_Charmap@plt>:
 1049140:      	adrp	x16, 0x10c7000
 1049144:      	ldr	x17, [x16, #0xde0]
 1049148:      	add	x16, x16, #0xde0
 104914c:      	br	x17

0000000001049150 <FT_Get_CMap_Format@plt>:
 1049150:      	adrp	x16, 0x10c7000
 1049154:      	ldr	x17, [x16, #0xde8]
 1049158:      	add	x16, x16, #0xde8
 104915c:      	br	x17

0000000001049160 <FT_Get_Next_Char@plt>:
 1049160:      	adrp	x16, 0x10c7000
 1049164:      	ldr	x17, [x16, #0xdf0]
 1049168:      	add	x16, x16, #0xdf0
 104916c:      	br	x17

0000000001049170 <FT_Get_Glyph_Name@plt>:
 1049170:      	adrp	x16, 0x10c7000
 1049174:      	ldr	x17, [x16, #0xdf8]
 1049178:      	add	x16, x16, #0xdf8
 104917c:      	br	x17

0000000001049180 <FT_Activate_Size@plt>:
 1049180:      	adrp	x16, 0x10c7000
 1049184:      	ldr	x17, [x16, #0xe00]
 1049188:      	add	x16, x16, #0xe00
 104918c:      	br	x17

0000000001049190 <FT_Add_Module@plt>:
 1049190:      	adrp	x16, 0x10c7000
 1049194:      	ldr	x17, [x16, #0xe08]
 1049198:      	add	x16, x16, #0xe08
 104919c:      	br	x17

00000000010491a0 <FT_Remove_Module@plt>:
 10491a0:      	adrp	x16, 0x10c7000
 10491a4:      	ldr	x17, [x16, #0xe10]
 10491a8:      	add	x16, x16, #0xe10
 10491ac:      	br	x17

00000000010491b0 <FT_Get_Module@plt>:
 10491b0:      	adrp	x16, 0x10c7000
 10491b4:      	ldr	x17, [x16, #0xe18]
 10491b8:      	add	x16, x16, #0xe18
 10491bc:      	br	x17

00000000010491c0 <FT_New_Library@plt>:
 10491c0:      	adrp	x16, 0x10c7000
 10491c4:      	ldr	x17, [x16, #0xe20]
 10491c8:      	add	x16, x16, #0xe20
 10491cc:      	br	x17

00000000010491d0 <FT_Done_Library@plt>:
 10491d0:      	adrp	x16, 0x10c7000
 10491d4:      	ldr	x17, [x16, #0xe28]
 10491d8:      	add	x16, x16, #0xe28
 10491dc:      	br	x17

00000000010491e0 <FT_Outline_Decompose@plt>:
 10491e0:      	adrp	x16, 0x10c7000
 10491e4:      	ldr	x17, [x16, #0xe30]
 10491e8:      	add	x16, x16, #0xe30
 10491ec:      	br	x17

00000000010491f0 <FT_Outline_New_Internal@plt>:
 10491f0:      	adrp	x16, 0x10c7000
 10491f4:      	ldr	x17, [x16, #0xe38]
 10491f8:      	add	x16, x16, #0xe38
 10491fc:      	br	x17

0000000001049200 <FT_Outline_Done_Internal@plt>:
 1049200:      	adrp	x16, 0x10c7000
 1049204:      	ldr	x17, [x16, #0xe40]
 1049208:      	add	x16, x16, #0xe40
 104920c:      	br	x17

0000000001049210 <FT_Outline_New@plt>:
 1049210:      	adrp	x16, 0x10c7000
 1049214:      	ldr	x17, [x16, #0xe48]
 1049218:      	add	x16, x16, #0xe48
 104921c:      	br	x17

0000000001049220 <FT_Outline_Copy@plt>:
 1049220:      	adrp	x16, 0x10c7000
 1049224:      	ldr	x17, [x16, #0xe50]
 1049228:      	add	x16, x16, #0xe50
 104922c:      	br	x17

0000000001049230 <FT_Outline_Done@plt>:
 1049230:      	adrp	x16, 0x10c7000
 1049234:      	ldr	x17, [x16, #0xe58]
 1049238:      	add	x16, x16, #0xe58
 104923c:      	br	x17

0000000001049240 <FT_Outline_Render@plt>:
 1049240:      	adrp	x16, 0x10c7000
 1049244:      	ldr	x17, [x16, #0xe60]
 1049248:      	add	x16, x16, #0xe60
 104924c:      	br	x17

0000000001049250 <FT_Outline_EmboldenXY@plt>:
 1049250:      	adrp	x16, 0x10c7000
 1049254:      	ldr	x17, [x16, #0xe68]
 1049258:      	add	x16, x16, #0xe68
 104925c:      	br	x17

0000000001049260 <FT_Outline_Get_Orientation@plt>:
 1049260:      	adrp	x16, 0x10c7000
 1049264:      	ldr	x17, [x16, #0xe70]
 1049268:      	add	x16, x16, #0xe70
 104926c:      	br	x17

0000000001049270 <qsort@plt>:
 1049270:      	adrp	x16, 0x10c7000
 1049274:      	ldr	x17, [x16, #0xe78]
 1049278:      	add	x16, x16, #0xe78
 104927c:      	br	x17

0000000001049280 <FT_Cos@plt>:
 1049280:      	adrp	x16, 0x10c7000
 1049284:      	ldr	x17, [x16, #0xe80]
 1049288:      	add	x16, x16, #0xe80
 104928c:      	br	x17

0000000001049290 <FT_Sin@plt>:
 1049290:      	adrp	x16, 0x10c7000
 1049294:      	ldr	x17, [x16, #0xe88]
 1049298:      	add	x16, x16, #0xe88
 104929c:      	br	x17

00000000010492a0 <FT_Tan@plt>:
 10492a0:      	adrp	x16, 0x10c7000
 10492a4:      	ldr	x17, [x16, #0xe90]
 10492a8:      	add	x16, x16, #0xe90
 10492ac:      	br	x17

00000000010492b0 <FT_Atan2@plt>:
 10492b0:      	adrp	x16, 0x10c7000
 10492b4:      	ldr	x17, [x16, #0xe98]
 10492b8:      	add	x16, x16, #0xe98
 10492bc:      	br	x17

00000000010492c0 <FT_Vector_Rotate@plt>:
 10492c0:      	adrp	x16, 0x10c7000
 10492c4:      	ldr	x17, [x16, #0xea0]
 10492c8:      	add	x16, x16, #0xea0
 10492cc:      	br	x17

00000000010492d0 <FT_Vector_From_Polar@plt>:
 10492d0:      	adrp	x16, 0x10c7000
 10492d4:      	ldr	x17, [x16, #0xea8]
 10492d8:      	add	x16, x16, #0xea8
 10492dc:      	br	x17

00000000010492e0 <FT_Angle_Diff@plt>:
 10492e0:      	adrp	x16, 0x10c7000
 10492e4:      	ldr	x17, [x16, #0xeb0]
 10492e8:      	add	x16, x16, #0xeb0
 10492ec:      	br	x17

00000000010492f0 <FT_List_Iterate@plt>:
 10492f0:      	adrp	x16, 0x10c7000
 10492f4:      	ldr	x17, [x16, #0xeb8]
 10492f8:      	add	x16, x16, #0xeb8
 10492fc:      	br	x17

0000000001049300 <FT_List_Finalize@plt>:
 1049300:      	adrp	x16, 0x10c7000
 1049304:      	ldr	x17, [x16, #0xec0]
 1049308:      	add	x16, x16, #0xec0
 104930c:      	br	x17

0000000001049310 <strcat@plt>:
 1049310:      	adrp	x16, 0x10c7000
 1049314:      	ldr	x17, [x16, #0xec8]
 1049318:      	add	x16, x16, #0xec8
 104931c:      	br	x17

0000000001049320 <FT_Bitmap_Init@plt>:
 1049320:      	adrp	x16, 0x10c7000
 1049324:      	ldr	x17, [x16, #0xed0]
 1049328:      	add	x16, x16, #0xed0
 104932c:      	br	x17

0000000001049330 <FT_Bitmap_Copy@plt>:
 1049330:      	adrp	x16, 0x10c7000
 1049334:      	ldr	x17, [x16, #0xed8]
 1049338:      	add	x16, x16, #0xed8
 104933c:      	br	x17

0000000001049340 <FT_Bitmap_Convert@plt>:
 1049340:      	adrp	x16, 0x10c7000
 1049344:      	ldr	x17, [x16, #0xee0]
 1049348:      	add	x16, x16, #0xee0
 104934c:      	br	x17

0000000001049350 <FT_Bitmap_Done@plt>:
 1049350:      	adrp	x16, 0x10c7000
 1049354:      	ldr	x17, [x16, #0xee8]
 1049358:      	add	x16, x16, #0xee8
 104935c:      	br	x17

0000000001049360 <FT_Glyph_Copy@plt>:
 1049360:      	adrp	x16, 0x10c7000
 1049364:      	ldr	x17, [x16, #0xef0]
 1049368:      	add	x16, x16, #0xef0
 104936c:      	br	x17

0000000001049370 <FT_Set_Default_Properties@plt>:
 1049370:      	adrp	x16, 0x10c7000
 1049374:      	ldr	x17, [x16, #0xef8]
 1049378:      	add	x16, x16, #0xef8
 104937c:      	br	x17

0000000001049380 <getenv@plt>:
 1049380:      	adrp	x16, 0x10c7000
 1049384:      	ldr	x17, [x16, #0xf00]
 1049388:      	add	x16, x16, #0xf00
 104938c:      	br	x17

0000000001049390 <FT_Stroker_LineTo@plt>:
 1049390:      	adrp	x16, 0x10c7000
 1049394:      	ldr	x17, [x16, #0xf08]
 1049398:      	add	x16, x16, #0xf08
 104939c:      	br	x17

00000000010493a0 <FT_Stroker_ConicTo@plt>:
 10493a0:      	adrp	x16, 0x10c7000
 10493a4:      	ldr	x17, [x16, #0xf10]
 10493a8:      	add	x16, x16, #0xf10
 10493ac:      	br	x17

00000000010493b0 <FT_Stroker_CubicTo@plt>:
 10493b0:      	adrp	x16, 0x10c7000
 10493b4:      	ldr	x17, [x16, #0xf18]
 10493b8:      	add	x16, x16, #0xf18
 10493bc:      	br	x17

00000000010493c0 <FT_Stroker_EndSubPath@plt>:
 10493c0:      	adrp	x16, 0x10c7000
 10493c4:      	ldr	x17, [x16, #0xf20]
 10493c8:      	add	x16, x16, #0xf20
 10493cc:      	br	x17

00000000010493d0 <FT_Stroker_GetBorderCounts@plt>:
 10493d0:      	adrp	x16, 0x10c7000
 10493d4:      	ldr	x17, [x16, #0xf28]
 10493d8:      	add	x16, x16, #0xf28
 10493dc:      	br	x17

00000000010493e0 <FT_Stroker_GetCounts@plt>:
 10493e0:      	adrp	x16, 0x10c7000
 10493e4:      	ldr	x17, [x16, #0xf30]
 10493e8:      	add	x16, x16, #0xf30
 10493ec:      	br	x17

00000000010493f0 <FT_Stroker_ExportBorder@plt>:
 10493f0:      	adrp	x16, 0x10c7000
 10493f4:      	ldr	x17, [x16, #0xf38]
 10493f8:      	add	x16, x16, #0xf38
 10493fc:      	br	x17

0000000001049400 <FT_Stroker_Export@plt>:
 1049400:      	adrp	x16, 0x10c7000
 1049404:      	ldr	x17, [x16, #0xf40]
 1049408:      	add	x16, x16, #0xf40
 104940c:      	br	x17

0000000001049410 <FT_Stroker_ParseOutline@plt>:
 1049410:      	adrp	x16, 0x10c7000
 1049414:      	ldr	x17, [x16, #0xf48]
 1049418:      	add	x16, x16, #0xf48
 104941c:      	br	x17

0000000001049420 <FT_Stream_OpenGzip@plt>:
 1049420:      	adrp	x16, 0x10c7000
 1049424:      	ldr	x17, [x16, #0xf50]
 1049428:      	add	x16, x16, #0xf50
 104942c:      	br	x17

0000000001049430 <FT_Gzip_Uncompress@plt>:
 1049430:      	adrp	x16, 0x10c7000
 1049434:      	ldr	x17, [x16, #0xf58]
 1049438:      	add	x16, x16, #0xf58
 104943c:      	br	x17

0000000001049440 <FT_Stream_OpenLZW@plt>:
 1049440:      	adrp	x16, 0x10c7000
 1049444:      	ldr	x17, [x16, #0xf60]
 1049448:      	add	x16, x16, #0xf60
 104944c:      	br	x17

0000000001049450 <TT_New_Context@plt>:
 1049450:      	adrp	x16, 0x10c7000
 1049454:      	ldr	x17, [x16, #0xf68]
 1049458:      	add	x16, x16, #0xf68
 104945c:      	br	x17

0000000001049460 <__errno@plt>:
 1049460:      	adrp	x16, 0x10c7000
 1049464:      	ldr	x17, [x16, #0xf70]
 1049468:      	add	x16, x16, #0xf70
 104946c:      	br	x17

0000000001049470 <strerror@plt>:
 1049470:      	adrp	x16, 0x10c7000
 1049474:      	ldr	x17, [x16, #0xf78]
 1049478:      	add	x16, x16, #0xf78
 104947c:      	br	x17

0000000001049480 <freopen@plt>:
 1049480:      	adrp	x16, 0x10c7000
 1049484:      	ldr	x17, [x16, #0xf80]
 1049488:      	add	x16, x16, #0xf80
 104948c:      	br	x17

0000000001049490 <getc@plt>:
 1049490:      	adrp	x16, 0x10c7000
 1049494:      	ldr	x17, [x16, #0xf88]
 1049498:      	add	x16, x16, #0xf88
 104949c:      	br	x17

00000000010494a0 <strspn@plt>:
 10494a0:      	adrp	x16, 0x10c7000
 10494a4:      	ldr	x17, [x16, #0xf90]
 10494a8:      	add	x16, x16, #0xf90
 10494ac:      	br	x17

00000000010494b0 <tmpfile@plt>:
 10494b0:      	adrp	x16, 0x10c7000
 10494b4:      	ldr	x17, [x16, #0xf98]
 10494b8:      	add	x16, x16, #0xf98
 10494bc:      	br	x17

00000000010494c0 <clearerr@plt>:
 10494c0:      	adrp	x16, 0x10c7000
 10494c4:      	ldr	x17, [x16, #0xfa0]
 10494c8:      	add	x16, x16, #0xfa0
 10494cc:      	br	x17

00000000010494d0 <setvbuf@plt>:
 10494d0:      	adrp	x16, 0x10c7000
 10494d4:      	ldr	x17, [x16, #0xfa8]
 10494d8:      	add	x16, x16, #0xfa8
 10494dc:      	br	x17

00000000010494e0 <asin@plt>:
 10494e0:      	adrp	x16, 0x10c7000
 10494e4:      	ldr	x17, [x16, #0xfb0]
 10494e8:      	add	x16, x16, #0xfb0
 10494ec:      	br	x17

00000000010494f0 <atan@plt>:
 10494f0:      	adrp	x16, 0x10c7000
 10494f4:      	ldr	x17, [x16, #0xfb8]
 10494f8:      	add	x16, x16, #0xfb8
 10494fc:      	br	x17

0000000001049500 <cosh@plt>:
 1049500:      	adrp	x16, 0x10c7000
 1049504:      	ldr	x17, [x16, #0xfc0]
 1049508:      	add	x16, x16, #0xfc0
 104950c:      	br	x17

0000000001049510 <frexp@plt>:
 1049510:      	adrp	x16, 0x10c7000
 1049514:      	ldr	x17, [x16, #0xfc8]
 1049518:      	add	x16, x16, #0xfc8
 104951c:      	br	x17

0000000001049520 <ldexp@plt>:
 1049520:      	adrp	x16, 0x10c7000
 1049524:      	ldr	x17, [x16, #0xfd0]
 1049528:      	add	x16, x16, #0xfd0
 104952c:      	br	x17

0000000001049530 <log10@plt>:
 1049530:      	adrp	x16, 0x10c7000
 1049534:      	ldr	x17, [x16, #0xfd8]
 1049538:      	add	x16, x16, #0xfd8
 104953c:      	br	x17

0000000001049540 <modf@plt>:
 1049540:      	adrp	x16, 0x10c7000
 1049544:      	ldr	x17, [x16, #0xfe0]
 1049548:      	add	x16, x16, #0xfe0
 104954c:      	br	x17

0000000001049550 <sinh@plt>:
 1049550:      	adrp	x16, 0x10c7000
 1049554:      	ldr	x17, [x16, #0xfe8]
 1049558:      	add	x16, x16, #0xfe8
 104955c:      	br	x17

0000000001049560 <tanh@plt>:
 1049560:      	adrp	x16, 0x10c7000
 1049564:      	ldr	x17, [x16, #0xff0]
 1049568:      	add	x16, x16, #0xff0
 104956c:      	br	x17

0000000001049570 <strpbrk@plt>:
 1049570:      	adrp	x16, 0x10c7000
 1049574:      	ldr	x17, [x16, #0xff8]
 1049578:      	add	x16, x16, #0xff8
 104957c:      	br	x17

0000000001049580 <gmtime@plt>:
 1049580:      	adrp	x16, 0x10c8000
 1049584:      	ldr	x17, [x16]
 1049588:      	add	x16, x16, #0x0
 104958c:      	br	x17

0000000001049590 <strftime@plt>:
 1049590:      	adrp	x16, 0x10c8000
 1049594:      	ldr	x17, [x16, #0x8]
 1049598:      	add	x16, x16, #0x8
 104959c:      	br	x17

00000000010495a0 <localtime@plt>:
 10495a0:      	adrp	x16, 0x10c8000
 10495a4:      	ldr	x17, [x16, #0x10]
 10495a8:      	add	x16, x16, #0x10
 10495ac:      	br	x17

00000000010495b0 <difftime@plt>:
 10495b0:      	adrp	x16, 0x10c8000
 10495b4:      	ldr	x17, [x16, #0x18]
 10495b8:      	add	x16, x16, #0x18
 10495bc:      	br	x17

00000000010495c0 <system@plt>:
 10495c0:      	adrp	x16, 0x10c8000
 10495c4:      	ldr	x17, [x16, #0x20]
 10495c8:      	add	x16, x16, #0x20
 10495cc:      	br	x17

00000000010495d0 <remove@plt>:
 10495d0:      	adrp	x16, 0x10c8000
 10495d4:      	ldr	x17, [x16, #0x28]
 10495d8:      	add	x16, x16, #0x28
 10495dc:      	br	x17

00000000010495e0 <rename@plt>:
 10495e0:      	adrp	x16, 0x10c8000
 10495e4:      	ldr	x17, [x16, #0x30]
 10495e8:      	add	x16, x16, #0x30
 10495ec:      	br	x17

00000000010495f0 <mktime@plt>:
 10495f0:      	adrp	x16, 0x10c8000
 10495f4:      	ldr	x17, [x16, #0x38]
 10495f8:      	add	x16, x16, #0x38
 10495fc:      	br	x17

0000000001049600 <tmpnam@plt>:
 1049600:      	adrp	x16, 0x10c8000
 1049604:      	ldr	x17, [x16, #0x40]
 1049608:      	add	x16, x16, #0x40
 104960c:      	br	x17

0000000001049610 <strcoll@plt>:
 1049610:      	adrp	x16, 0x10c8000
 1049614:      	ldr	x17, [x16, #0x48]
 1049618:      	add	x16, x16, #0x48
 104961c:      	br	x17

0000000001049620 <log10f@plt>:
 1049620:      	adrp	x16, 0x10c8000
 1049624:      	ldr	x17, [x16, #0x50]
 1049628:      	add	x16, x16, #0x50
 104962c:      	br	x17

0000000001049630 <pthread_join@plt>:
 1049630:      	adrp	x16, 0x10c8000
 1049634:      	ldr	x17, [x16, #0x58]
 1049638:      	add	x16, x16, #0x58
 104963c:      	br	x17

0000000001049640 <ABGRToJ400@plt>:
 1049640:      	adrp	x16, 0x10c8000
 1049644:      	ldr	x17, [x16, #0x60]
 1049648:      	add	x16, x16, #0x60
 104964c:      	br	x17

0000000001049650 <getauxval@plt>:
 1049650:      	adrp	x16, 0x10c8000
 1049654:      	ldr	x17, [x16, #0x68]
 1049658:      	add	x16, x16, #0x68
 104965c:      	br	x17

0000000001049660 <__system_property_get@plt>:
 1049660:      	adrp	x16, 0x10c8000
 1049664:      	ldr	x17, [x16, #0x70]
 1049668:      	add	x16, x16, #0x70
 104966c:      	br	x17

0000000001049670 <pthread_rwlock_wrlock@plt>:
 1049670:      	adrp	x16, 0x10c8000
 1049674:      	ldr	x17, [x16, #0x78]
 1049678:      	add	x16, x16, #0x78
 104967c:      	br	x17

0000000001049680 <pthread_rwlock_unlock@plt>:
 1049680:      	adrp	x16, 0x10c8000
 1049684:      	ldr	x17, [x16, #0x80]
 1049688:      	add	x16, x16, #0x80
 104968c:      	br	x17

0000000001049690 <dl_iterate_phdr@plt>:
 1049690:      	adrp	x16, 0x10c8000
 1049694:      	ldr	x17, [x16, #0x88]
 1049698:      	add	x16, x16, #0x88
 104969c:      	br	x17

00000000010496a0 <pthread_rwlock_rdlock@plt>:
 10496a0:      	adrp	x16, 0x10c8000
 10496a4:      	ldr	x17, [x16, #0x90]
 10496a8:      	add	x16, x16, #0x90
 10496ac:      	br	x17

00000000010496b0 <getpid@plt>:
 10496b0:      	adrp	x16, 0x10c8000
 10496b4:      	ldr	x17, [x16, #0x98]
 10496b8:      	add	x16, x16, #0x98
 10496bc:      	br	x17

00000000010496c0 <syscall@plt>:
 10496c0:      	adrp	x16, 0x10c8000
 10496c4:      	ldr	x17, [x16, #0xa0]
 10496c8:      	add	x16, x16, #0xa0
 10496cc:      	br	x17
