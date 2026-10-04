// EXPORTED & PLT DISASSEMBLY FOR libbmpKit.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libbmpKit.so (SHA-256: 550E87FBFD13B8DE0833789DF04038C659E0472606E6A161EAF775BA126CD168)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 609, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libbmpKit.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000074990 <.plt>:
   74990:      	stp	x16, x30, [sp, #-0x10]!
   74994:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74998:      	ldr	x17, [x16, #0x920]
   7499c:      	add	x16, x16, #0x920
   749a0:      	br	x17
   749a4:      	nop
   749a8:      	nop
   749ac:      	nop

00000000000749b0 <__cxa_finalize@plt>:
   749b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   749b4:      	ldr	x17, [x16, #0x928]
   749b8:      	add	x16, x16, #0x928
   749bc:      	br	x17

00000000000749c0 <__cxa_atexit@plt>:
   749c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   749c4:      	ldr	x17, [x16, #0x930]
   749c8:      	add	x16, x16, #0x930
   749cc:      	br	x17

00000000000749d0 <__register_atfork@plt>:
   749d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   749d4:      	ldr	x17, [x16, #0x938]
   749d8:      	add	x16, x16, #0x938
   749dc:      	br	x17

00000000000749e0 <_ZN7_JavaVM6GetEnvEPPvi@plt>:
   749e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   749e4:      	ldr	x17, [x16, #0x940]
   749e8:      	add	x16, x16, #0x940
   749ec:      	br	x17

00000000000749f0 <__android_log_print@plt>:
   749f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   749f4:      	ldr	x17, [x16, #0x948]
   749f8:      	add	x16, x16, #0x948
   749fc:      	br	x17

0000000000074a00 <_ZN11KitApi30NDK18registerJniMethodsEP7_JNIEnv@plt>:
   74a00:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a04:      	ldr	x17, [x16, #0x950]
   74a08:      	add	x16, x16, #0x950
   74a0c:      	br	x17

0000000000074a10 <__stack_chk_fail@plt>:
   74a10:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a14:      	ldr	x17, [x16, #0x958]
   74a18:      	add	x16, x16, #0x958
   74a1c:      	br	x17

0000000000074a20 <_ZN7_JNIEnv9FindClassEPKc@plt>:
   74a20:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a24:      	ldr	x17, [x16, #0x960]
   74a28:      	add	x16, x16, #0x960
   74a2c:      	br	x17

0000000000074a30 <_ZN7_JNIEnv15RegisterNativesEP7_jclassPK15JNINativeMethodi@plt>:
   74a30:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a34:      	ldr	x17, [x16, #0x968]
   74a38:      	add	x16, x16, #0x968
   74a3c:      	br	x17

0000000000074a40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc@plt>:
   74a40:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a44:      	ldr	x17, [x16, #0x970]
   74a48:      	add	x16, x16, #0x970
   74a4c:      	br	x17

0000000000074a50 <AndroidBitmap_getInfo@plt>:
   74a50:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a54:      	ldr	x17, [x16, #0x978]
   74a58:      	add	x16, x16, #0x978
   74a5c:      	br	x17

0000000000074a60 <_ZNSt6__ndk19to_stringEj@plt>:
   74a60:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a64:      	ldr	x17, [x16, #0x980]
   74a68:      	add	x16, x16, #0x980
   74a6c:      	br	x17

0000000000074a70 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   74a70:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a74:      	ldr	x17, [x16, #0x988]
   74a78:      	add	x16, x16, #0x988
   74a7c:      	br	x17

0000000000074a80 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   74a80:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a84:      	ldr	x17, [x16, #0x990]
   74a88:      	add	x16, x16, #0x990
   74a8c:      	br	x17

0000000000074a90 <_ZNSt6__ndk19to_stringEi@plt>:
   74a90:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74a94:      	ldr	x17, [x16, #0x998]
   74a98:      	add	x16, x16, #0x998
   74a9c:      	br	x17

0000000000074aa0 <_ZN4Util23androidBitmapFormatNameER19AndroidBitmapFormat@plt>:
   74aa0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74aa4:      	ldr	x17, [x16, #0x9a0]
   74aa8:      	add	x16, x16, #0x9a0
   74aac:      	br	x17

0000000000074ab0 <_ZN4Util23androidBitmapResultNameEi@plt>:
   74ab0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ab4:      	ldr	x17, [x16, #0x9a8]
   74ab8:      	add	x16, x16, #0x9a8
   74abc:      	br	x17

0000000000074ac0 <AndroidBitmap_getDataSpace@plt>:
   74ac0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ac4:      	ldr	x17, [x16, #0x9b0]
   74ac8:      	add	x16, x16, #0x9b0
   74acc:      	br	x17

0000000000074ad0 <_ZN4Util13dataSpaceNameEi@plt>:
   74ad0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ad4:      	ldr	x17, [x16, #0x9b8]
   74ad8:      	add	x16, x16, #0x9b8
   74adc:      	br	x17

0000000000074ae0 <_ZN7_JNIEnv12NewStringUTFEPKc@plt>:
   74ae0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ae4:      	ldr	x17, [x16, #0x9c0]
   74ae8:      	add	x16, x16, #0x9c0
   74aec:      	br	x17

0000000000074af0 <_ZNSt6__ndk117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2B8ne180000INS_18__default_init_tagESA_EEOT_OT0_@plt>:
   74af0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74af4:      	ldr	x17, [x16, #0x9c8]
   74af8:      	add	x16, x16, #0x9c8
   74afc:      	br	x17

0000000000074b00 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm@plt>:
   74b00:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b04:      	ldr	x17, [x16, #0x9d0]
   74b08:      	add	x16, x16, #0x9d0
   74b0c:      	br	x17

0000000000074b10 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   74b10:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b14:      	ldr	x17, [x16, #0x9d8]
   74b18:      	add	x16, x16, #0x9d8
   74b1c:      	br	x17

0000000000074b20 <_ZN11KitApi30NDK11imageDecodeEP7_JNIEnvRKNSt6__ndk18functionIFiPP13AImageDecoderEEER3ReqR7DstInfo@plt>:
   74b20:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b24:      	ldr	x17, [x16, #0x9e0]
   74b28:      	add	x16, x16, #0x9e0
   74b2c:      	br	x17

0000000000074b30 <_ZN4Util22imageDecoderResultNameEi@plt>:
   74b30:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b34:      	ldr	x17, [x16, #0x9e8]
   74b38:      	add	x16, x16, #0x9e8
   74b3c:      	br	x17

0000000000074b40 <_ZN4Util9newStringEPKcz@plt>:
   74b40:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b44:      	ldr	x17, [x16, #0x9f0]
   74b48:      	add	x16, x16, #0x9f0
   74b4c:      	br	x17

0000000000074b50 <_ZN3Req21logAImageDecoderErrorEiNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   74b50:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b54:      	ldr	x17, [x16, #0x9f8]
   74b58:      	add	x16, x16, #0x9f8
   74b5c:      	br	x17

0000000000074b60 <AImageDecoder_getHeaderInfo@plt>:
   74b60:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b64:      	ldr	x17, [x16, #0xa00]
   74b68:      	add	x16, x16, #0xa00
   74b6c:      	br	x17

0000000000074b70 <AImageDecoderHeaderInfo_getDataSpace@plt>:
   74b70:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b74:      	ldr	x17, [x16, #0xa08]
   74b78:      	add	x16, x16, #0xa08
   74b7c:      	br	x17

0000000000074b80 <AImageDecoderHeaderInfo_getAlphaFlags@plt>:
   74b80:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b84:      	ldr	x17, [x16, #0xa10]
   74b88:      	add	x16, x16, #0xa10
   74b8c:      	br	x17

0000000000074b90 <AImageDecoderHeaderInfo_getWidth@plt>:
   74b90:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74b94:      	ldr	x17, [x16, #0xa18]
   74b98:      	add	x16, x16, #0xa18
   74b9c:      	br	x17

0000000000074ba0 <AImageDecoderHeaderInfo_getHeight@plt>:
   74ba0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ba4:      	ldr	x17, [x16, #0xa20]
   74ba8:      	add	x16, x16, #0xa20
   74bac:      	br	x17

0000000000074bb0 <AImageDecoderHeaderInfo_getMimeType@plt>:
   74bb0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74bb4:      	ldr	x17, [x16, #0xa28]
   74bb8:      	add	x16, x16, #0xa28
   74bbc:      	br	x17

0000000000074bc0 <__cxa_begin_catch@plt>:
   74bc0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74bc4:      	ldr	x17, [x16, #0xa30]
   74bc8:      	add	x16, x16, #0xa30
   74bcc:      	br	x17

0000000000074bd0 <__cxa_end_catch@plt>:
   74bd0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74bd4:      	ldr	x17, [x16, #0xa38]
   74bd8:      	add	x16, x16, #0xa38
   74bdc:      	br	x17

0000000000074be0 <AImageDecoderHeaderInfo_getAndroidBitmapFormat@plt>:
   74be0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74be4:      	ldr	x17, [x16, #0xa40]
   74be8:      	add	x16, x16, #0xa40
   74bec:      	br	x17

0000000000074bf0 <_ZN7ImgInfo8printLogEv@plt>:
   74bf0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74bf4:      	ldr	x17, [x16, #0xa48]
   74bf8:      	add	x16, x16, #0xa48
   74bfc:      	br	x17

0000000000074c00 <_ZN3Req9calcDstWHEiiRiS0_@plt>:
   74c00:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c04:      	ldr	x17, [x16, #0xa50]
   74c08:      	add	x16, x16, #0xa50
   74c0c:      	br	x17

0000000000074c10 <AImageDecoder_setTargetSize@plt>:
   74c10:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c14:      	ldr	x17, [x16, #0xa58]
   74c18:      	add	x16, x16, #0xa58
   74c1c:      	br	x17

0000000000074c20 <AImageDecoder_setAndroidBitmapFormat@plt>:
   74c20:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c24:      	ldr	x17, [x16, #0xa60]
   74c28:      	add	x16, x16, #0xa60
   74c2c:      	br	x17

0000000000074c30 <AImageDecoder_setDataSpace@plt>:
   74c30:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c34:      	ldr	x17, [x16, #0xa68]
   74c38:      	add	x16, x16, #0xa68
   74c3c:      	br	x17

0000000000074c40 <AImageDecoder_setUnpremultipliedRequired@plt>:
   74c40:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c44:      	ldr	x17, [x16, #0xa70]
   74c48:      	add	x16, x16, #0xa70
   74c4c:      	br	x17

0000000000074c50 <AImageDecoder_getMinimumStride@plt>:
   74c50:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c54:      	ldr	x17, [x16, #0xa78]
   74c58:      	add	x16, x16, #0xa78
   74c5c:      	br	x17

0000000000074c60 <malloc@plt>:
   74c60:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c64:      	ldr	x17, [x16, #0xa80]
   74c68:      	add	x16, x16, #0xa80
   74c6c:      	br	x17

0000000000074c70 <AImageDecoder_decodeImage@plt>:
   74c70:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c74:      	ldr	x17, [x16, #0xa88]
   74c78:      	add	x16, x16, #0xa88
   74c7c:      	br	x17

0000000000074c80 <AImageDecoder_delete@plt>:
   74c80:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c84:      	ldr	x17, [x16, #0xa90]
   74c88:      	add	x16, x16, #0xa90
   74c8c:      	br	x17

0000000000074c90 <free@plt>:
   74c90:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74c94:      	ldr	x17, [x16, #0xa98]
   74c98:      	add	x16, x16, #0xa98
   74c9c:      	br	x17

0000000000074ca0 <_ZN4Util18canSkipDrawBgWhiteEPKc@plt>:
   74ca0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ca4:      	ldr	x17, [x16, #0xaa0]
   74ca8:      	add	x16, x16, #0xaa0
   74cac:      	br	x17

0000000000074cb0 <_ZN11KitApi30NDK18addWhiteBackgroundEPhiii@plt>:
   74cb0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74cb4:      	ldr	x17, [x16, #0xaa8]
   74cb8:      	add	x16, x16, #0xaa8
   74cbc:      	br	x17

0000000000074cc0 <_ZN3Req11logErrorMsgENSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   74cc0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74cc4:      	ldr	x17, [x16, #0xab0]
   74cc8:      	add	x16, x16, #0xab0
   74ccc:      	br	x17

0000000000074cd0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1ERKS5_@plt>:
   74cd0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74cd4:      	ldr	x17, [x16, #0xab8]
   74cd8:      	add	x16, x16, #0xab8
   74cdc:      	br	x17

0000000000074ce0 <_ZN7ImgInfo11logErrorMsgENSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   74ce0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ce4:      	ldr	x17, [x16, #0xac0]
   74ce8:      	add	x16, x16, #0xac0
   74cec:      	br	x17

0000000000074cf0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   74cf0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74cf4:      	ldr	x17, [x16, #0xac8]
   74cf8:      	add	x16, x16, #0xac8
   74cfc:      	br	x17

0000000000074d00 <_ZSt9terminatev@plt>:
   74d00:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d04:      	ldr	x17, [x16, #0xad0]
   74d08:      	add	x16, x16, #0xad0
   74d0c:      	br	x17

0000000000074d10 <_ZN4Util13alphaFlagNameEi@plt>:
   74d10:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d14:      	ldr	x17, [x16, #0xad8]
   74d18:      	add	x16, x16, #0xad8
   74d1c:      	br	x17

0000000000074d20 <_ZN6KitLog3logEiPKcz@plt>:
   74d20:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d24:      	ldr	x17, [x16, #0xae0]
   74d28:      	add	x16, x16, #0xae0
   74d2c:      	br	x17

0000000000074d30 <_Znam@plt>:
   74d30:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d34:      	ldr	x17, [x16, #0xae8]
   74d38:      	add	x16, x16, #0xae8
   74d3c:      	br	x17

0000000000074d40 <_ZdaPv@plt>:
   74d40:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d44:      	ldr	x17, [x16, #0xaf0]
   74d48:      	add	x16, x16, #0xaf0
   74d4c:      	br	x17

0000000000074d50 <_ZN11KitApi30NDK15jniCreateBitmapEP7_JNIEnviiii@plt>:
   74d50:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d54:      	ldr	x17, [x16, #0xaf8]
   74d58:      	add	x16, x16, #0xaf8
   74d5c:      	br	x17

0000000000074d60 <_ZN7_JNIEnv17GetStaticMethodIDEP7_jclassPKcS3_@plt>:
   74d60:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d64:      	ldr	x17, [x16, #0xb00]
   74d68:      	add	x16, x16, #0xb00
   74d6c:      	br	x17

0000000000074d70 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz@plt>:
   74d70:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d74:      	ldr	x17, [x16, #0xb08]
   74d78:      	add	x16, x16, #0xb08
   74d7c:      	br	x17

0000000000074d80 <_ZN4Util13dataSpace_c2jEP7_JNIEnvi@plt>:
   74d80:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d84:      	ldr	x17, [x16, #0xb10]
   74d88:      	add	x16, x16, #0xb10
   74d8c:      	br	x17

0000000000074d90 <_ZN11KitApi30NDK21jniCreateNativeBitmapEP7_JNIEnvPhii@plt>:
   74d90:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74d94:      	ldr	x17, [x16, #0xb18]
   74d98:      	add	x16, x16, #0xb18
   74d9c:      	br	x17

0000000000074da0 <_Znwm@plt>:
   74da0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74da4:      	ldr	x17, [x16, #0xb20]
   74da8:      	add	x16, x16, #0xb20
   74dac:      	br	x17

0000000000074db0 <_ZN12NativeBitmapC1Eii@plt>:
   74db0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74db4:      	ldr	x17, [x16, #0xb28]
   74db8:      	add	x16, x16, #0xb28
   74dbc:      	br	x17

0000000000074dc0 <_ZN12NativeBitmap9setPixelsEPhii@plt>:
   74dc0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74dc4:      	ldr	x17, [x16, #0xb30]
   74dc8:      	add	x16, x16, #0xb30
   74dcc:      	br	x17

0000000000074dd0 <_ZN7_JNIEnv14DeleteLocalRefEP8_jobject@plt>:
   74dd0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74dd4:      	ldr	x17, [x16, #0xb38]
   74dd8:      	add	x16, x16, #0xb38
   74ddc:      	br	x17

0000000000074de0 <_ZdlPv@plt>:
   74de0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74de4:      	ldr	x17, [x16, #0xb40]
   74de8:      	add	x16, x16, #0xb40
   74dec:      	br	x17

0000000000074df0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   74df0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74df4:      	ldr	x17, [x16, #0xb48]
   74df8:      	add	x16, x16, #0xb48
   74dfc:      	br	x17

0000000000074e00 <_ZN6KitLog5errorENSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   74e00:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e04:      	ldr	x17, [x16, #0xb50]
   74e08:      	add	x16, x16, #0xb50
   74e0c:      	br	x17

0000000000074e10 <strlen@plt>:
   74e10:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e14:      	ldr	x17, [x16, #0xb58]
   74e18:      	add	x16, x16, #0xb58
   74e1c:      	br	x17

0000000000074e20 <__cxa_allocate_exception@plt>:
   74e20:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e24:      	ldr	x17, [x16, #0xb60]
   74e28:      	add	x16, x16, #0xb60
   74e2c:      	br	x17

0000000000074e30 <__cxa_throw@plt>:
   74e30:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e34:      	ldr	x17, [x16, #0xb68]
   74e38:      	add	x16, x16, #0xb68
   74e3c:      	br	x17

0000000000074e40 <_ZNSt9exceptionD2Ev@plt>:
   74e40:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e44:      	ldr	x17, [x16, #0xb70]
   74e48:      	add	x16, x16, #0xb70
   74e4c:      	br	x17

0000000000074e50 <_Z4loadP7_JNIEnvP8_jstringP8_jobjectR3ReqR7DstInfo@plt>:
   74e50:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e54:      	ldr	x17, [x16, #0xb78]
   74e58:      	add	x16, x16, #0xb78
   74e5c:      	br	x17

0000000000074e60 <_ZN7_JNIEnv17GetStringUTFCharsEP8_jstringPh@plt>:
   74e60:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e64:      	ldr	x17, [x16, #0xb80]
   74e68:      	add	x16, x16, #0xb80
   74e6c:      	br	x17

0000000000074e70 <_ZN7_JNIEnv21ReleaseStringUTFCharsEP8_jstringPKc@plt>:
   74e70:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e74:      	ldr	x17, [x16, #0xb88]
   74e78:      	add	x16, x16, #0xb88
   74e7c:      	br	x17

0000000000074e80 <AAssetManager_fromJava@plt>:
   74e80:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e84:      	ldr	x17, [x16, #0xb90]
   74e88:      	add	x16, x16, #0xb90
   74e8c:      	br	x17

0000000000074e90 <AAssetManager_open@plt>:
   74e90:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74e94:      	ldr	x17, [x16, #0xb98]
   74e98:      	add	x16, x16, #0xb98
   74e9c:      	br	x17

0000000000074ea0 <AAsset_getLength@plt>:
   74ea0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ea4:      	ldr	x17, [x16, #0xba0]
   74ea8:      	add	x16, x16, #0xba0
   74eac:      	br	x17

0000000000074eb0 <AAsset_close@plt>:
   74eb0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74eb4:      	ldr	x17, [x16, #0xba8]
   74eb8:      	add	x16, x16, #0xba8
   74ebc:      	br	x17

0000000000074ec0 <_ZN7DstInfoC2Ev@plt>:
   74ec0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ec4:      	ldr	x17, [x16, #0xbb0]
   74ec8:      	add	x16, x16, #0xbb0
   74ecc:      	br	x17

0000000000074ed0 <_ZN4Util11imgInfo_c2jEP7_JNIEnvP8_jobjectR7ImgInfo@plt>:
   74ed0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ed4:      	ldr	x17, [x16, #0xbb8]
   74ed8:      	add	x16, x16, #0xbb8
   74edc:      	br	x17

0000000000074ee0 <_Z11BYTE2BitmapP7_JNIEnvP8_jobjectPhii@plt>:
   74ee0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ee4:      	ldr	x17, [x16, #0xbc0]
   74ee8:      	add	x16, x16, #0xbc0
   74eec:      	br	x17

0000000000074ef0 <_ZN3ReqD2Ev@plt>:
   74ef0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ef4:      	ldr	x17, [x16, #0xbc8]
   74ef8:      	add	x16, x16, #0xbc8
   74efc:      	br	x17

0000000000074f00 <_ZN7ImgInfoD2Ev@plt>:
   74f00:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f04:      	ldr	x17, [x16, #0xbd0]
   74f08:      	add	x16, x16, #0xbd0
   74f0c:      	br	x17

0000000000074f10 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   74f10:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f14:      	ldr	x17, [x16, #0xbd8]
   74f18:      	add	x16, x16, #0xbd8
   74f1c:      	br	x17

0000000000074f20 <_ZNSt20bad_array_new_lengthD1Ev@plt>:
   74f20:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f24:      	ldr	x17, [x16, #0xbe0]
   74f28:      	add	x16, x16, #0xbe0
   74f2c:      	br	x17

0000000000074f30 <_ZnwmSt11align_val_t@plt>:
   74f30:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f34:      	ldr	x17, [x16, #0xbe8]
   74f38:      	add	x16, x16, #0xbe8
   74f3c:      	br	x17

0000000000074f40 <_ZdlPvSt11align_val_t@plt>:
   74f40:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f44:      	ldr	x17, [x16, #0xbf0]
   74f48:      	add	x16, x16, #0xbf0
   74f4c:      	br	x17

0000000000074f50 <AImageDecoder_createFromAAsset@plt>:
   74f50:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f54:      	ldr	x17, [x16, #0xbf8]
   74f58:      	add	x16, x16, #0xbf8
   74f5c:      	br	x17

0000000000074f60 <_Z4loadP7_JNIEnvP11_jbyteArrayiR3ReqR7DstInfo@plt>:
   74f60:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f64:      	ldr	x17, [x16, #0xc00]
   74f68:      	add	x16, x16, #0xc00
   74f6c:      	br	x17

0000000000074f70 <_ZN7_JNIEnv20GetByteArrayElementsEP11_jbyteArrayPh@plt>:
   74f70:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f74:      	ldr	x17, [x16, #0xc08]
   74f78:      	add	x16, x16, #0xc08
   74f7c:      	br	x17

0000000000074f80 <_ZN7_JNIEnv14GetArrayLengthEP7_jarray@plt>:
   74f80:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f84:      	ldr	x17, [x16, #0xc10]
   74f88:      	add	x16, x16, #0xc10
   74f8c:      	br	x17

0000000000074f90 <__memset_chk@plt>:
   74f90:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74f94:      	ldr	x17, [x16, #0xc18]
   74f98:      	add	x16, x16, #0xc18
   74f9c:      	br	x17

0000000000074fa0 <__memcpy_chk@plt>:
   74fa0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74fa4:      	ldr	x17, [x16, #0xc20]
   74fa8:      	add	x16, x16, #0xc20
   74fac:      	br	x17

0000000000074fb0 <_ZN7_JNIEnv24ReleaseByteArrayElementsEP11_jbyteArrayPai@plt>:
   74fb0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74fb4:      	ldr	x17, [x16, #0xc28]
   74fb8:      	add	x16, x16, #0xc28
   74fbc:      	br	x17

0000000000074fc0 <AImageDecoder_createFromBuffer@plt>:
   74fc0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74fc4:      	ldr	x17, [x16, #0xc30]
   74fc8:      	add	x16, x16, #0xc30
   74fcc:      	br	x17

0000000000074fd0 <_Z4loadP7_JNIEnviR3ReqR7DstInfo@plt>:
   74fd0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74fd4:      	ldr	x17, [x16, #0xc38]
   74fd8:      	add	x16, x16, #0xc38
   74fdc:      	br	x17

0000000000074fe0 <fstat@plt>:
   74fe0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74fe4:      	ldr	x17, [x16, #0xc40]
   74fe8:      	add	x16, x16, #0xc40
   74fec:      	br	x17

0000000000074ff0 <AImageDecoder_createFromFd@plt>:
   74ff0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   74ff4:      	ldr	x17, [x16, #0xc48]
   74ff8:      	add	x16, x16, #0xc48
   74ffc:      	br	x17

0000000000075000 <_Z4loadP7_JNIEnvP8_jstringR3ReqR7DstInfo@plt>:
   75000:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75004:      	ldr	x17, [x16, #0xc50]
   75008:      	add	x16, x16, #0xc50
   7500c:      	br	x17

0000000000075010 <stat@plt>:
   75010:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75014:      	ldr	x17, [x16, #0xc58]
   75018:      	add	x16, x16, #0xc58
   7501c:      	br	x17

0000000000075020 <__open_2@plt>:
   75020:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75024:      	ldr	x17, [x16, #0xc60]
   75028:      	add	x16, x16, #0xc60
   7502c:      	br	x17

0000000000075030 <__errno@plt>:
   75030:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75034:      	ldr	x17, [x16, #0xc68]
   75038:      	add	x16, x16, #0xc68
   7503c:      	br	x17

0000000000075040 <strerror@plt>:
   75040:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75044:      	ldr	x17, [x16, #0xc70]
   75048:      	add	x16, x16, #0xc70
   7504c:      	br	x17

0000000000075050 <_ZN3Req11logErrorMsgEiNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   75050:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75054:      	ldr	x17, [x16, #0xc78]
   75058:      	add	x16, x16, #0xc78
   7505c:      	br	x17

0000000000075060 <close@plt>:
   75060:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75064:      	ldr	x17, [x16, #0xc80]
   75068:      	add	x16, x16, #0xc80
   7506c:      	br	x17

0000000000075070 <_Z4saveP7_JNIEnviiiR17AndroidBitmapInfoRiPv@plt>:
   75070:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75074:      	ldr	x17, [x16, #0xc88]
   75078:      	add	x16, x16, #0xc88
   7507c:      	br	x17

0000000000075080 <AndroidBitmap_compress@plt>:
   75080:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75084:      	ldr	x17, [x16, #0xc90]
   75088:      	add	x16, x16, #0xc90
   7508c:      	br	x17

0000000000075090 <_ZN12NativeBitmap8getWidthEv@plt>:
   75090:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75094:      	ldr	x17, [x16, #0xc98]
   75098:      	add	x16, x16, #0xc98
   7509c:      	br	x17

00000000000750a0 <_ZN12NativeBitmap9getHeightEv@plt>:
   750a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   750a4:      	ldr	x17, [x16, #0xca0]
   750a8:      	add	x16, x16, #0xca0
   750ac:      	br	x17

00000000000750b0 <_ZN12NativeBitmap9getPixelsEv@plt>:
   750b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   750b4:      	ldr	x17, [x16, #0xca8]
   750b8:      	add	x16, x16, #0xca8
   750bc:      	br	x17

00000000000750c0 <AndroidBitmap_lockPixels@plt>:
   750c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   750c4:      	ldr	x17, [x16, #0xcb0]
   750c8:      	add	x16, x16, #0xcb0
   750cc:      	br	x17

00000000000750d0 <AndroidBitmap_unlockPixels@plt>:
   750d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   750d4:      	ldr	x17, [x16, #0xcb8]
   750d8:      	add	x16, x16, #0xcb8
   750dc:      	br	x17

00000000000750e0 <__write_chk@plt>:
   750e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   750e4:      	ldr	x17, [x16, #0xcc0]
   750e8:      	add	x16, x16, #0xcc0
   750ec:      	br	x17

00000000000750f0 <_Z4saveP7_JNIEnvP8_jstringiiR17AndroidBitmapInfoRiPv@plt>:
   750f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   750f4:      	ldr	x17, [x16, #0xcc8]
   750f8:      	add	x16, x16, #0xcc8
   750fc:      	br	x17

0000000000075100 <open@plt>:
   75100:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75104:      	ldr	x17, [x16, #0xcd0]
   75108:      	add	x16, x16, #0xcd0
   7510c:      	br	x17

0000000000075110 <_Z4saveP7_JNIEnvP8_jobjectiiR17AndroidBitmapInfoRiPv@plt>:
   75110:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75114:      	ldr	x17, [x16, #0xcd8]
   75118:      	add	x16, x16, #0xcd8
   7511c:      	br	x17

0000000000075120 <_ZN15JniOutputStreamC1EP7_JNIEnvP8_jobject@plt>:
   75120:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75124:      	ldr	x17, [x16, #0xce0]
   75128:      	add	x16, x16, #0xce0
   7512c:      	br	x17

0000000000075130 <_ZN15JniOutputStream5flushEv@plt>:
   75130:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75134:      	ldr	x17, [x16, #0xce8]
   75138:      	add	x16, x16, #0xce8
   7513c:      	br	x17

0000000000075140 <_ZN15JniOutputStreamD1Ev@plt>:
   75140:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75144:      	ldr	x17, [x16, #0xcf0]
   75148:      	add	x16, x16, #0xcf0
   7514c:      	br	x17

0000000000075150 <_ZN15JniOutputStream5writeEPKvm@plt>:
   75150:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75154:      	ldr	x17, [x16, #0xcf8]
   75158:      	add	x16, x16, #0xcf8
   7515c:      	br	x17

0000000000075160 <_ZN7_JNIEnv12NewGlobalRefEP8_jobject@plt>:
   75160:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75164:      	ldr	x17, [x16, #0xd00]
   75168:      	add	x16, x16, #0xd00
   7516c:      	br	x17

0000000000075170 <_ZN7_JNIEnv12NewByteArrayEi@plt>:
   75170:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75174:      	ldr	x17, [x16, #0xd08]
   75178:      	add	x16, x16, #0xd08
   7517c:      	br	x17

0000000000075180 <_ZN7_JNIEnv14GetObjectClassEP8_jobject@plt>:
   75180:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75184:      	ldr	x17, [x16, #0xd10]
   75188:      	add	x16, x16, #0xd10
   7518c:      	br	x17

0000000000075190 <_ZN7_JNIEnv11GetMethodIDEP7_jclassPKcS3_@plt>:
   75190:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75194:      	ldr	x17, [x16, #0xd18]
   75198:      	add	x16, x16, #0xd18
   7519c:      	br	x17

00000000000751a0 <_ZN7_JNIEnv18SetByteArrayRegionEP11_jbyteArrayiiPKa@plt>:
   751a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   751a4:      	ldr	x17, [x16, #0xd20]
   751a8:      	add	x16, x16, #0xd20
   751ac:      	br	x17

00000000000751b0 <_ZN7_JNIEnv14ExceptionCheckEv@plt>:
   751b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   751b4:      	ldr	x17, [x16, #0xd28]
   751b8:      	add	x16, x16, #0xd28
   751bc:      	br	x17

00000000000751c0 <_ZN7_JNIEnv17ExceptionDescribeEv@plt>:
   751c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   751c4:      	ldr	x17, [x16, #0xd30]
   751c8:      	add	x16, x16, #0xd30
   751cc:      	br	x17

00000000000751d0 <_ZN7_JNIEnv14ExceptionClearEv@plt>:
   751d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   751d4:      	ldr	x17, [x16, #0xd38]
   751d8:      	add	x16, x16, #0xd38
   751dc:      	br	x17

00000000000751e0 <_ZN7_JNIEnv14CallVoidMethodEP8_jobjectP10_jmethodIDz@plt>:
   751e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   751e4:      	ldr	x17, [x16, #0xd40]
   751e8:      	add	x16, x16, #0xd40
   751ec:      	br	x17

00000000000751f0 <_ZN7_JNIEnv15DeleteGlobalRefEP8_jobject@plt>:
   751f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   751f4:      	ldr	x17, [x16, #0xd48]
   751f8:      	add	x16, x16, #0xd48
   751fc:      	br	x17

0000000000075200 <__vsnprintf_chk@plt>:
   75200:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75204:      	ldr	x17, [x16, #0xd50]
   75208:      	add	x16, x16, #0xd50
   7520c:      	br	x17

0000000000075210 <_ZN6KitLog6ndkLogEiNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES6_@plt>:
   75210:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75214:      	ldr	x17, [x16, #0xd58]
   75218:      	add	x16, x16, #0xd58
   7521c:      	br	x17

0000000000075220 <_ZN7_JNIEnv10GetFieldIDEP7_jclassPKcS3_@plt>:
   75220:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75224:      	ldr	x17, [x16, #0xd60]
   75228:      	add	x16, x16, #0xd60
   7522c:      	br	x17

0000000000075230 <_ZN7_JNIEnv11SetIntFieldEP8_jobjectP9_jfieldIDi@plt>:
   75230:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75234:      	ldr	x17, [x16, #0xd68]
   75238:      	add	x16, x16, #0xd68
   7523c:      	br	x17

0000000000075240 <_ZN7_JNIEnv12SetLongFieldEP8_jobjectP9_jfieldIDl@plt>:
   75240:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75244:      	ldr	x17, [x16, #0xd70]
   75248:      	add	x16, x16, #0xd70
   7524c:      	br	x17

0000000000075250 <_ZN7_JNIEnv14SetObjectFieldEP8_jobjectP9_jfieldIDS1_@plt>:
   75250:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75254:      	ldr	x17, [x16, #0xd78]
   75258:      	add	x16, x16, #0xd78
   7525c:      	br	x17

0000000000075260 <_ZN4Util16bitmapConfig_c2jEP7_JNIEnv19AndroidBitmapFormat@plt>:
   75260:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75264:      	ldr	x17, [x16, #0xd80]
   75268:      	add	x16, x16, #0xd80
   7526c:      	br	x17

0000000000075270 <_ZN4Util28androidBitmapFormat2javaNameER19AndroidBitmapFormat@plt>:
   75270:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75274:      	ldr	x17, [x16, #0xd88]
   75278:      	add	x16, x16, #0xd88
   7527c:      	br	x17

0000000000075280 <strcmp@plt>:
   75280:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75284:      	ldr	x17, [x16, #0xd90]
   75288:      	add	x16, x16, #0xd90
   7528c:      	br	x17

0000000000075290 <_ZN4Util18dataSpace2javaNameEi@plt>:
   75290:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75294:      	ldr	x17, [x16, #0xd98]
   75298:      	add	x16, x16, #0xd98
   7529c:      	br	x17

00000000000752a0 <_ZNSt11logic_errorC2EPKc@plt>:
   752a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   752a4:      	ldr	x17, [x16, #0xda0]
   752a8:      	add	x16, x16, #0xda0
   752ac:      	br	x17

00000000000752b0 <_ZNSt13runtime_errorC1EPKc@plt>:
   752b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   752b4:      	ldr	x17, [x16, #0xda8]
   752b8:      	add	x16, x16, #0xda8
   752bc:      	br	x17

00000000000752c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
   752c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   752c4:      	ldr	x17, [x16, #0xdb0]
   752c8:      	add	x16, x16, #0xdb0
   752cc:      	br	x17

00000000000752d0 <memmove@plt>:
   752d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   752d4:      	ldr	x17, [x16, #0xdb8]
   752d8:      	add	x16, x16, #0xdb8
   752dc:      	br	x17

00000000000752e0 <memcpy@plt>:
   752e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   752e4:      	ldr	x17, [x16, #0xdc0]
   752e8:      	add	x16, x16, #0xdc0
   752ec:      	br	x17

00000000000752f0 <memchr@plt>:
   752f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   752f4:      	ldr	x17, [x16, #0xdc8]
   752f8:      	add	x16, x16, #0xdc8
   752fc:      	br	x17

0000000000075300 <memset@plt>:
   75300:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75304:      	ldr	x17, [x16, #0xdd0]
   75308:      	add	x16, x16, #0xdd0
   7530c:      	br	x17

0000000000075310 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
   75310:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75314:      	ldr	x17, [x16, #0xdd8]
   75318:      	add	x16, x16, #0xdd8
   7531c:      	br	x17

0000000000075320 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc@plt>:
   75320:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75324:      	ldr	x17, [x16, #0xde0]
   75328:      	add	x16, x16, #0xde0
   7532c:      	br	x17

0000000000075330 <memcmp@plt>:
   75330:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75334:      	ldr	x17, [x16, #0xde8]
   75338:      	add	x16, x16, #0xde8
   7533c:      	br	x17

0000000000075340 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmPKwm@plt>:
   75340:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75344:      	ldr	x17, [x16, #0xdf0]
   75348:      	add	x16, x16, #0xdf0
   7534c:      	br	x17

0000000000075350 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE21__grow_by_and_replaceEmmmmmmPKw@plt>:
   75350:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75354:      	ldr	x17, [x16, #0xdf8]
   75358:      	add	x16, x16, #0xdf8
   7535c:      	br	x17

0000000000075360 <wcslen@plt>:
   75360:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75364:      	ldr	x17, [x16, #0xe00]
   75368:      	add	x16, x16, #0xe00
   7536c:      	br	x17

0000000000075370 <wmemchr@plt>:
   75370:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75374:      	ldr	x17, [x16, #0xe08]
   75378:      	add	x16, x16, #0xe08
   7537c:      	br	x17

0000000000075380 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmPKwm@plt>:
   75380:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75384:      	ldr	x17, [x16, #0xe10]
   75388:      	add	x16, x16, #0xe10
   7538c:      	br	x17

0000000000075390 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEmw@plt>:
   75390:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75394:      	ldr	x17, [x16, #0xe18]
   75398:      	add	x16, x16, #0xe18
   7539c:      	br	x17

00000000000753a0 <wmemcmp@plt>:
   753a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   753a4:      	ldr	x17, [x16, #0xe20]
   753a8:      	add	x16, x16, #0xe20
   753ac:      	br	x17

00000000000753b0 <_ZNSt12length_errorD1Ev@plt>:
   753b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   753b4:      	ldr	x17, [x16, #0xe28]
   753b8:      	add	x16, x16, #0xe28
   753bc:      	br	x17

00000000000753c0 <__cxa_free_exception@plt>:
   753c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   753c4:      	ldr	x17, [x16, #0xe30]
   753c8:      	add	x16, x16, #0xe30
   753cc:      	br	x17

00000000000753d0 <_ZNSt12out_of_rangeD1Ev@plt>:
   753d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   753d4:      	ldr	x17, [x16, #0xe38]
   753d8:      	add	x16, x16, #0xe38
   753dc:      	br	x17

00000000000753e0 <strtoul@plt>:
   753e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   753e4:      	ldr	x17, [x16, #0xe40]
   753e8:      	add	x16, x16, #0xe40
   753ec:      	br	x17

00000000000753f0 <strtoll@plt>:
   753f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   753f4:      	ldr	x17, [x16, #0xe48]
   753f8:      	add	x16, x16, #0xe48
   753fc:      	br	x17

0000000000075400 <strtoull@plt>:
   75400:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75404:      	ldr	x17, [x16, #0xe50]
   75408:      	add	x16, x16, #0xe50
   7540c:      	br	x17

0000000000075410 <strtof@plt>:
   75410:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75414:      	ldr	x17, [x16, #0xe58]
   75418:      	add	x16, x16, #0xe58
   7541c:      	br	x17

0000000000075420 <strtod@plt>:
   75420:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75424:      	ldr	x17, [x16, #0xe60]
   75428:      	add	x16, x16, #0xe60
   7542c:      	br	x17

0000000000075430 <strtold@plt>:
   75430:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75434:      	ldr	x17, [x16, #0xe68]
   75438:      	add	x16, x16, #0xe68
   7543c:      	br	x17

0000000000075440 <wcstoul@plt>:
   75440:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75444:      	ldr	x17, [x16, #0xe70]
   75448:      	add	x16, x16, #0xe70
   7544c:      	br	x17

0000000000075450 <wcstoll@plt>:
   75450:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75454:      	ldr	x17, [x16, #0xe78]
   75458:      	add	x16, x16, #0xe78
   7545c:      	br	x17

0000000000075460 <wcstoull@plt>:
   75460:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75464:      	ldr	x17, [x16, #0xe80]
   75468:      	add	x16, x16, #0xe80
   7546c:      	br	x17

0000000000075470 <wcstof@plt>:
   75470:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75474:      	ldr	x17, [x16, #0xe88]
   75478:      	add	x16, x16, #0xe88
   7547c:      	br	x17

0000000000075480 <wcstod@plt>:
   75480:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75484:      	ldr	x17, [x16, #0xe90]
   75488:      	add	x16, x16, #0xe90
   7548c:      	br	x17

0000000000075490 <wcstold@plt>:
   75490:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75494:      	ldr	x17, [x16, #0xe98]
   75498:      	add	x16, x16, #0xe98
   7549c:      	br	x17

00000000000754a0 <snprintf@plt>:
   754a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   754a4:      	ldr	x17, [x16, #0xea0]
   754a8:      	add	x16, x16, #0xea0
   754ac:      	br	x17

00000000000754b0 <swprintf@plt>:
   754b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   754b4:      	ldr	x17, [x16, #0xea8]
   754b8:      	add	x16, x16, #0xea8
   754bc:      	br	x17

00000000000754c0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEED1Ev@plt>:
   754c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   754c4:      	ldr	x17, [x16, #0xeb0]
   754c8:      	add	x16, x16, #0xeb0
   754cc:      	br	x17

00000000000754d0 <strtol@plt>:
   754d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   754d4:      	ldr	x17, [x16, #0xeb8]
   754d8:      	add	x16, x16, #0xeb8
   754dc:      	br	x17

00000000000754e0 <_ZNSt16invalid_argumentD1Ev@plt>:
   754e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   754e4:      	ldr	x17, [x16, #0xec0]
   754e8:      	add	x16, x16, #0xec0
   754ec:      	br	x17

00000000000754f0 <wcstol@plt>:
   754f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   754f4:      	ldr	x17, [x16, #0xec8]
   754f8:      	add	x16, x16, #0xec8
   754fc:      	br	x17

0000000000075500 <_ZNSt13runtime_errorD1Ev@plt>:
   75500:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75504:      	ldr	x17, [x16, #0xed0]
   75508:      	add	x16, x16, #0xed0
   7550c:      	br	x17

0000000000075510 <__cxa_get_globals@plt>:
   75510:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75514:      	ldr	x17, [x16, #0xed8]
   75518:      	add	x16, x16, #0xed8
   7551c:      	br	x17

0000000000075520 <__cxa_get_globals_fast@plt>:
   75520:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75524:      	ldr	x17, [x16, #0xee0]
   75528:      	add	x16, x16, #0xee0
   7552c:      	br	x17

0000000000075530 <_ZSt14get_unexpectedv@plt>:
   75530:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75534:      	ldr	x17, [x16, #0xee8]
   75538:      	add	x16, x16, #0xee8
   7553c:      	br	x17

0000000000075540 <_ZSt13get_terminatev@plt>:
   75540:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75544:      	ldr	x17, [x16, #0xef0]
   75548:      	add	x16, x16, #0xef0
   7554c:      	br	x17

0000000000075550 <_ZSt15get_new_handlerv@plt>:
   75550:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75554:      	ldr	x17, [x16, #0xef8]
   75558:      	add	x16, x16, #0xef8
   7555c:      	br	x17

0000000000075560 <__cxa_demangle@plt>:
   75560:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75564:      	ldr	x17, [x16, #0xf00]
   75568:      	add	x16, x16, #0xf00
   7556c:      	br	x17

0000000000075570 <__emutls_get_address@plt>:
   75570:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75574:      	ldr	x17, [x16, #0xf08]
   75578:      	add	x16, x16, #0xf08
   7557c:      	br	x17

0000000000075580 <_ZNSt9exceptionD1Ev@plt>:
   75580:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75584:      	ldr	x17, [x16, #0xf10]
   75588:      	add	x16, x16, #0xf10
   7558c:      	br	x17

0000000000075590 <_ZNSt13bad_exceptionD1Ev@plt>:
   75590:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75594:      	ldr	x17, [x16, #0xf18]
   75598:      	add	x16, x16, #0xf18
   7559c:      	br	x17

00000000000755a0 <_ZNSt9bad_allocD1Ev@plt>:
   755a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   755a4:      	ldr	x17, [x16, #0xf20]
   755a8:      	add	x16, x16, #0xf20
   755ac:      	br	x17

00000000000755b0 <_ZNSt9bad_allocC1Ev@plt>:
   755b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   755b4:      	ldr	x17, [x16, #0xf28]
   755b8:      	add	x16, x16, #0xf28
   755bc:      	br	x17

00000000000755c0 <_ZNSt11logic_errorD1Ev@plt>:
   755c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   755c4:      	ldr	x17, [x16, #0xf30]
   755c8:      	add	x16, x16, #0xf30
   755cc:      	br	x17

00000000000755d0 <_ZNSt12domain_errorD1Ev@plt>:
   755d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   755d4:      	ldr	x17, [x16, #0xf38]
   755d8:      	add	x16, x16, #0xf38
   755dc:      	br	x17

00000000000755e0 <_ZNSt11range_errorD1Ev@plt>:
   755e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   755e4:      	ldr	x17, [x16, #0xf40]
   755e8:      	add	x16, x16, #0xf40
   755ec:      	br	x17

00000000000755f0 <_ZNSt14overflow_errorD1Ev@plt>:
   755f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   755f4:      	ldr	x17, [x16, #0xf48]
   755f8:      	add	x16, x16, #0xf48
   755fc:      	br	x17

0000000000075600 <_ZNSt15underflow_errorD1Ev@plt>:
   75600:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75604:      	ldr	x17, [x16, #0xf50]
   75608:      	add	x16, x16, #0xf50
   7560c:      	br	x17

0000000000075610 <_ZNSt9type_infoD2Ev@plt>:
   75610:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75614:      	ldr	x17, [x16, #0xf58]
   75618:      	add	x16, x16, #0xf58
   7561c:      	br	x17

0000000000075620 <_ZNSt9type_infoD1Ev@plt>:
   75620:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75624:      	ldr	x17, [x16, #0xf60]
   75628:      	add	x16, x16, #0xf60
   7562c:      	br	x17

0000000000075630 <_ZNSt8bad_castD1Ev@plt>:
   75630:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75634:      	ldr	x17, [x16, #0xf68]
   75638:      	add	x16, x16, #0xf68
   7563c:      	br	x17

0000000000075640 <_ZNSt10bad_typeidD1Ev@plt>:
   75640:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75644:      	ldr	x17, [x16, #0xf70]
   75648:      	add	x16, x16, #0xf70
   7564c:      	br	x17

0000000000075650 <fwrite@plt>:
   75650:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75654:      	ldr	x17, [x16, #0xf78]
   75658:      	add	x16, x16, #0xf78
   7565c:      	br	x17

0000000000075660 <vfprintf@plt>:
   75660:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75664:      	ldr	x17, [x16, #0xf80]
   75668:      	add	x16, x16, #0xf80
   7566c:      	br	x17

0000000000075670 <fputc@plt>:
   75670:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75674:      	ldr	x17, [x16, #0xf88]
   75678:      	add	x16, x16, #0xf88
   7567c:      	br	x17

0000000000075680 <vasprintf@plt>:
   75680:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75684:      	ldr	x17, [x16, #0xf90]
   75688:      	add	x16, x16, #0xf90
   7568c:      	br	x17

0000000000075690 <android_set_abort_message@plt>:
   75690:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75694:      	ldr	x17, [x16, #0xf98]
   75698:      	add	x16, x16, #0xf98
   7569c:      	br	x17

00000000000756a0 <openlog@plt>:
   756a0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   756a4:      	ldr	x17, [x16, #0xfa0]
   756a8:      	add	x16, x16, #0xfa0
   756ac:      	br	x17

00000000000756b0 <syslog@plt>:
   756b0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   756b4:      	ldr	x17, [x16, #0xfa8]
   756b8:      	add	x16, x16, #0xfa8
   756bc:      	br	x17

00000000000756c0 <closelog@plt>:
   756c0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   756c4:      	ldr	x17, [x16, #0xfb0]
   756c8:      	add	x16, x16, #0xfb0
   756cc:      	br	x17

00000000000756d0 <abort@plt>:
   756d0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   756d4:      	ldr	x17, [x16, #0xfb8]
   756d8:      	add	x16, x16, #0xfb8
   756dc:      	br	x17

00000000000756e0 <__dynamic_cast@plt>:
   756e0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   756e4:      	ldr	x17, [x16, #0xfc0]
   756e8:      	add	x16, x16, #0xfc0
   756ec:      	br	x17

00000000000756f0 <realloc@plt>:
   756f0:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   756f4:      	ldr	x17, [x16, #0xfc8]
   756f8:      	add	x16, x16, #0xfc8
   756fc:      	br	x17

0000000000075700 <fprintf@plt>:
   75700:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75704:      	ldr	x17, [x16, #0xfd0]
   75708:      	add	x16, x16, #0xfd0
   7570c:      	br	x17

0000000000075710 <fputs@plt>:
   75710:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75714:      	ldr	x17, [x16, #0xfd8]
   75718:      	add	x16, x16, #0xfd8
   7571c:      	br	x17

0000000000075720 <posix_memalign@plt>:
   75720:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75724:      	ldr	x17, [x16, #0xfe0]
   75728:      	add	x16, x16, #0xfe0
   7572c:      	br	x17

0000000000075730 <_ZnamSt11align_val_t@plt>:
   75730:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75734:      	ldr	x17, [x16, #0xfe8]
   75738:      	add	x16, x16, #0xfe8
   7573c:      	br	x17

0000000000075740 <_ZdaPvSt11align_val_t@plt>:
   75740:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75744:      	ldr	x17, [x16, #0xff0]
   75748:      	add	x16, x16, #0xff0
   7574c:      	br	x17

0000000000075750 <__cxa_rethrow@plt>:
   75750:      	adrp	x16, 0x7d000 <_ZTISt10bad_typeid+0x2568>
   75754:      	ldr	x17, [x16, #0xff8]
   75758:      	add	x16, x16, #0xff8
   7575c:      	br	x17

0000000000075760 <pthread_mutex_lock@plt>:
   75760:      	adrp	x16, 0x7e000
   75764:      	ldr	x17, [x16]
   75768:      	add	x16, x16, #0x0
   7576c:      	br	x17

0000000000075770 <pthread_mutex_unlock@plt>:
   75770:      	adrp	x16, 0x7e000
   75774:      	ldr	x17, [x16, #0x8]
   75778:      	add	x16, x16, #0x8
   7577c:      	br	x17

0000000000075780 <calloc@plt>:
   75780:      	adrp	x16, 0x7e000
   75784:      	ldr	x17, [x16, #0x10]
   75788:      	add	x16, x16, #0x10
   7578c:      	br	x17

0000000000075790 <__assert2@plt>:
   75790:      	adrp	x16, 0x7e000
   75794:      	ldr	x17, [x16, #0x18]
   75798:      	add	x16, x16, #0x18
   7579c:      	br	x17

00000000000757a0 <pthread_getspecific@plt>:
   757a0:      	adrp	x16, 0x7e000
   757a4:      	ldr	x17, [x16, #0x20]
   757a8:      	add	x16, x16, #0x20
   757ac:      	br	x17

00000000000757b0 <pthread_once@plt>:
   757b0:      	adrp	x16, 0x7e000
   757b4:      	ldr	x17, [x16, #0x28]
   757b8:      	add	x16, x16, #0x28
   757bc:      	br	x17

00000000000757c0 <pthread_setspecific@plt>:
   757c0:      	adrp	x16, 0x7e000
   757c4:      	ldr	x17, [x16, #0x30]
   757c8:      	add	x16, x16, #0x30
   757cc:      	br	x17

00000000000757d0 <pthread_key_delete@plt>:
   757d0:      	adrp	x16, 0x7e000
   757d4:      	ldr	x17, [x16, #0x38]
   757d8:      	add	x16, x16, #0x38
   757dc:      	br	x17

00000000000757e0 <pthread_key_create@plt>:
   757e0:      	adrp	x16, 0x7e000
   757e4:      	ldr	x17, [x16, #0x40]
   757e8:      	add	x16, x16, #0x40
   757ec:      	br	x17

00000000000757f0 <getauxval@plt>:
   757f0:      	adrp	x16, 0x7e000
   757f4:      	ldr	x17, [x16, #0x48]
   757f8:      	add	x16, x16, #0x48
   757fc:      	br	x17

0000000000075800 <__system_property_get@plt>:
   75800:      	adrp	x16, 0x7e000
   75804:      	ldr	x17, [x16, #0x50]
   75808:      	add	x16, x16, #0x50
   7580c:      	br	x17

0000000000075810 <strncmp@plt>:
   75810:      	adrp	x16, 0x7e000
   75814:      	ldr	x17, [x16, #0x58]
   75818:      	add	x16, x16, #0x58
   7581c:      	br	x17

0000000000075820 <fflush@plt>:
   75820:      	adrp	x16, 0x7e000
   75824:      	ldr	x17, [x16, #0x60]
   75828:      	add	x16, x16, #0x60
   7582c:      	br	x17

0000000000075830 <pthread_rwlock_wrlock@plt>:
   75830:      	adrp	x16, 0x7e000
   75834:      	ldr	x17, [x16, #0x68]
   75838:      	add	x16, x16, #0x68
   7583c:      	br	x17

0000000000075840 <pthread_rwlock_unlock@plt>:
   75840:      	adrp	x16, 0x7e000
   75844:      	ldr	x17, [x16, #0x70]
   75848:      	add	x16, x16, #0x70
   7584c:      	br	x17

0000000000075850 <dl_iterate_phdr@plt>:
   75850:      	adrp	x16, 0x7e000
   75854:      	ldr	x17, [x16, #0x78]
   75858:      	add	x16, x16, #0x78
   7585c:      	br	x17

0000000000075860 <pthread_rwlock_rdlock@plt>:
   75860:      	adrp	x16, 0x7e000
   75864:      	ldr	x17, [x16, #0x80]
   75868:      	add	x16, x16, #0x80
   7586c:      	br	x17

0000000000075870 <getpid@plt>:
   75870:      	adrp	x16, 0x7e000
   75874:      	ldr	x17, [x16, #0x88]
   75878:      	add	x16, x16, #0x88
   7587c:      	br	x17

0000000000075880 <syscall@plt>:
   75880:      	adrp	x16, 0x7e000
   75884:      	ldr	x17, [x16, #0x90]
   75888:      	add	x16, x16, #0x90
   7588c:      	br	x17
