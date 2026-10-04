// EXPORTED & PLT DISASSEMBLY FOR libaidetectionplugin.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libaidetectionplugin.so (SHA-256: 910EF898F457CAC694080829B8F7B219AE6CC696F5ADEBE90BECA9A70C0DEDA8)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 622, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libaidetectionplugin.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000000798e0 <.plt>:
   798e0:      	stp	x16, x30, [sp, #-0x10]!
   798e4:      	adrp	x16, 0x83000
   798e8:      	ldr	x17, [x16, #0xb0]
   798ec:      	add	x16, x16, #0xb0
   798f0:      	br	x17
   798f4:      	nop
   798f8:      	nop
   798fc:      	nop

0000000000079900 <__cxa_finalize@plt>:
   79900:      	adrp	x16, 0x83000
   79904:      	ldr	x17, [x16, #0xb8]
   79908:      	add	x16, x16, #0xb8
   7990c:      	br	x17

0000000000079910 <__cxa_atexit@plt>:
   79910:      	adrp	x16, 0x83000
   79914:      	ldr	x17, [x16, #0xc0]
   79918:      	add	x16, x16, #0xc0
   7991c:      	br	x17

0000000000079920 <__android_log_print@plt>:
   79920:      	adrp	x16, 0x83000
   79924:      	ldr	x17, [x16, #0xc8]
   79928:      	add	x16, x16, #0xc8
   7992c:      	br	x17

0000000000079930 <__stack_chk_fail@plt>:
   79930:      	adrp	x16, 0x83000
   79934:      	ldr	x17, [x16, #0xd0]
   79938:      	add	x16, x16, #0xd0
   7993c:      	br	x17

0000000000079940 <strcmp@plt>:
   79940:      	adrp	x16, 0x83000
   79944:      	ldr	x17, [x16, #0xd8]
   79948:      	add	x16, x16, #0xd8
   7994c:      	br	x17

0000000000079950 <_ZNSt6__ndk15mutex4lockEv@plt>:
   79950:      	adrp	x16, 0x83000
   79954:      	ldr	x17, [x16, #0xe0]
   79958:      	add	x16, x16, #0xe0
   7995c:      	br	x17

0000000000079960 <vlai_init@plt>:
   79960:      	adrp	x16, 0x83000
   79964:      	ldr	x17, [x16, #0xe8]
   79968:      	add	x16, x16, #0xe8
   7996c:      	br	x17

0000000000079970 <_Znwm@plt>:
   79970:      	adrp	x16, 0x83000
   79974:      	ldr	x17, [x16, #0xf0]
   79978:      	add	x16, x16, #0xf0
   7997c:      	br	x17

0000000000079980 <_ZN17MMDetectionPlugin10AIDetectorC1Ev@plt>:
   79980:      	adrp	x16, 0x83000
   79984:      	ldr	x17, [x16, #0xf8]
   79988:      	add	x16, x16, #0xf8
   7998c:      	br	x17

0000000000079990 <pthread_self@plt>:
   79990:      	adrp	x16, 0x83000
   79994:      	ldr	x17, [x16, #0x100]
   79998:      	add	x16, x16, #0x100
   7999c:      	br	x17

00000000000799a0 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   799a0:      	adrp	x16, 0x83000
   799a4:      	ldr	x17, [x16, #0x108]
   799a8:      	add	x16, x16, #0x108
   799ac:      	br	x17

00000000000799b0 <_ZdlPv@plt>:
   799b0:      	adrp	x16, 0x83000
   799b4:      	ldr	x17, [x16, #0x110]
   799b8:      	add	x16, x16, #0x110
   799bc:      	br	x17

00000000000799c0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   799c0:      	adrp	x16, 0x83000
   799c4:      	ldr	x17, [x16, #0x118]
   799c8:      	add	x16, x16, #0x118
   799cc:      	br	x17

00000000000799d0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   799d0:      	adrp	x16, 0x83000
   799d4:      	ldr	x17, [x16, #0x120]
   799d8:      	add	x16, x16, #0x120
   799dc:      	br	x17

00000000000799e0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   799e0:      	adrp	x16, 0x83000
   799e4:      	ldr	x17, [x16, #0x128]
   799e8:      	add	x16, x16, #0x128
   799ec:      	br	x17

00000000000799f0 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   799f0:      	adrp	x16, 0x83000
   799f4:      	ldr	x17, [x16, #0x130]
   799f8:      	add	x16, x16, #0x130
   799fc:      	br	x17

0000000000079a00 <_ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   79a00:      	adrp	x16, 0x83000
   79a04:      	ldr	x17, [x16, #0x138]
   79a08:      	add	x16, x16, #0x138
   79a0c:      	br	x17

0000000000079a10 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   79a10:      	adrp	x16, 0x83000
   79a14:      	ldr	x17, [x16, #0x140]
   79a18:      	add	x16, x16, #0x140
   79a1c:      	br	x17

0000000000079a20 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   79a20:      	adrp	x16, 0x83000
   79a24:      	ldr	x17, [x16, #0x148]
   79a28:      	add	x16, x16, #0x148
   79a2c:      	br	x17

0000000000079a30 <_ZNSt6__ndk16locale7classicEv@plt>:
   79a30:      	adrp	x16, 0x83000
   79a34:      	ldr	x17, [x16, #0x150]
   79a38:      	add	x16, x16, #0x150
   79a3c:      	br	x17

0000000000079a40 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
   79a40:      	adrp	x16, 0x83000
   79a44:      	ldr	x17, [x16, #0x158]
   79a48:      	add	x16, x16, #0x158
   79a4c:      	br	x17

0000000000079a50 <_ZNSt6__ndk18ios_base5imbueERKNS_6localeE@plt>:
   79a50:      	adrp	x16, 0x83000
   79a54:      	ldr	x17, [x16, #0x160]
   79a58:      	add	x16, x16, #0x160
   79a5c:      	br	x17

0000000000079a60 <_ZNSt6__ndk16localeD1Ev@plt>:
   79a60:      	adrp	x16, 0x83000
   79a64:      	ldr	x17, [x16, #0x168]
   79a68:      	add	x16, x16, #0x168
   79a6c:      	br	x17

0000000000079a70 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
   79a70:      	adrp	x16, 0x83000
   79a74:      	ldr	x17, [x16, #0x170]
   79a78:      	add	x16, x16, #0x170
   79a7c:      	br	x17

0000000000079a80 <_ZNSt6__ndk16localeaSERKS0_@plt>:
   79a80:      	adrp	x16, 0x83000
   79a84:      	ldr	x17, [x16, #0x178]
   79a88:      	add	x16, x16, #0x178
   79a8c:      	br	x17

0000000000079a90 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
   79a90:      	adrp	x16, 0x83000
   79a94:      	ldr	x17, [x16, #0x180]
   79a98:      	add	x16, x16, #0x180
   79a9c:      	br	x17

0000000000079aa0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   79aa0:      	adrp	x16, 0x83000
   79aa4:      	ldr	x17, [x16, #0x188]
   79aa8:      	add	x16, x16, #0x188
   79aac:      	br	x17

0000000000079ab0 <_ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   79ab0:      	adrp	x16, 0x83000
   79ab4:      	ldr	x17, [x16, #0x190]
   79ab8:      	add	x16, x16, #0x190
   79abc:      	br	x17

0000000000079ac0 <__cxa_begin_catch@plt>:
   79ac0:      	adrp	x16, 0x83000
   79ac4:      	ldr	x17, [x16, #0x198]
   79ac8:      	add	x16, x16, #0x198
   79acc:      	br	x17

0000000000079ad0 <_ZSt9terminatev@plt>:
   79ad0:      	adrp	x16, 0x83000
   79ad4:      	ldr	x17, [x16, #0x1a0]
   79ad8:      	add	x16, x16, #0x1a0
   79adc:      	br	x17

0000000000079ae0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
   79ae0:      	adrp	x16, 0x83000
   79ae4:      	ldr	x17, [x16, #0x1a8]
   79ae8:      	add	x16, x16, #0x1a8
   79aec:      	br	x17

0000000000079af0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   79af0:      	adrp	x16, 0x83000
   79af4:      	ldr	x17, [x16, #0x1b0]
   79af8:      	add	x16, x16, #0x1b0
   79afc:      	br	x17

0000000000079b00 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   79b00:      	adrp	x16, 0x83000
   79b04:      	ldr	x17, [x16, #0x1b8]
   79b08:      	add	x16, x16, #0x1b8
   79b0c:      	br	x17

0000000000079b10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
   79b10:      	adrp	x16, 0x83000
   79b14:      	ldr	x17, [x16, #0x1c0]
   79b18:      	add	x16, x16, #0x1c0
   79b1c:      	br	x17

0000000000079b20 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
   79b20:      	adrp	x16, 0x83000
   79b24:      	ldr	x17, [x16, #0x1c8]
   79b28:      	add	x16, x16, #0x1c8
   79b2c:      	br	x17

0000000000079b30 <__cxa_end_catch@plt>:
   79b30:      	adrp	x16, 0x83000
   79b34:      	ldr	x17, [x16, #0x1d0]
   79b38:      	add	x16, x16, #0x1d0
   79b3c:      	br	x17

0000000000079b40 <memset@plt>:
   79b40:      	adrp	x16, 0x83000
   79b44:      	ldr	x17, [x16, #0x1d8]
   79b48:      	add	x16, x16, #0x1d8
   79b4c:      	br	x17

0000000000079b50 <_ZNSt6__ndk15mutexD1Ev@plt>:
   79b50:      	adrp	x16, 0x83000
   79b54:      	ldr	x17, [x16, #0x1e0]
   79b58:      	add	x16, x16, #0x1e0
   79b5c:      	br	x17

0000000000079b60 <pthread_getspecific@plt>:
   79b60:      	adrp	x16, 0x83000
   79b64:      	ldr	x17, [x16, #0x1e8]
   79b68:      	add	x16, x16, #0x1e8
   79b6c:      	br	x17

0000000000079b70 <_ZN17MMDetectionPlugin9JniHelper8cacheEnvEP7_JavaVM@plt>:
   79b70:      	adrp	x16, 0x83000
   79b74:      	ldr	x17, [x16, #0x1f0]
   79b78:      	add	x16, x16, #0x1f0
   79b7c:      	br	x17

0000000000079b80 <_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz@plt>:
   79b80:      	adrp	x16, 0x83000
   79b84:      	ldr	x17, [x16, #0x1f8]
   79b88:      	add	x16, x16, #0x1f8
   79b8c:      	br	x17

0000000000079b90 <_ZN17MMDetectionPlugin9JniHelper6getEnvEv@plt>:
   79b90:      	adrp	x16, 0x83000
   79b94:      	ldr	x17, [x16, #0x200]
   79b98:      	add	x16, x16, #0x200
   79b9c:      	br	x17

0000000000079ba0 <_ZN17MMDetectionPlugin9JniHelper9setJavaVMEP7_JavaVM@plt>:
   79ba0:      	adrp	x16, 0x83000
   79ba4:      	ldr	x17, [x16, #0x208]
   79ba8:      	add	x16, x16, #0x208
   79bac:      	br	x17

0000000000079bb0 <pthread_key_create@plt>:
   79bb0:      	adrp	x16, 0x83000
   79bb4:      	ldr	x17, [x16, #0x210]
   79bb8:      	add	x16, x16, #0x210
   79bbc:      	br	x17

0000000000079bc0 <pthread_setspecific@plt>:
   79bc0:      	adrp	x16, 0x83000
   79bc4:      	ldr	x17, [x16, #0x218]
   79bc8:      	add	x16, x16, #0x218
   79bcc:      	br	x17

0000000000079bd0 <_ZN17MMDetectionPlugin9JniHelper14jstring2stringEP8_jstring@plt>:
   79bd0:      	adrp	x16, 0x83000
   79bd4:      	ldr	x17, [x16, #0x220]
   79bd8:      	add	x16, x16, #0x220
   79bdc:      	br	x17

0000000000079be0 <strlen@plt>:
   79be0:      	adrp	x16, 0x83000
   79be4:      	ldr	x17, [x16, #0x228]
   79be8:      	add	x16, x16, #0x228
   79bec:      	br	x17

0000000000079bf0 <memmove@plt>:
   79bf0:      	adrp	x16, 0x83000
   79bf4:      	ldr	x17, [x16, #0x230]
   79bf8:      	add	x16, x16, #0x230
   79bfc:      	br	x17

0000000000079c00 <memcpy@plt>:
   79c00:      	adrp	x16, 0x83000
   79c04:      	ldr	x17, [x16, #0x238]
   79c08:      	add	x16, x16, #0x238
   79c0c:      	br	x17

0000000000079c10 <__cxa_allocate_exception@plt>:
   79c10:      	adrp	x16, 0x83000
   79c14:      	ldr	x17, [x16, #0x240]
   79c18:      	add	x16, x16, #0x240
   79c1c:      	br	x17

0000000000079c20 <__cxa_throw@plt>:
   79c20:      	adrp	x16, 0x83000
   79c24:      	ldr	x17, [x16, #0x248]
   79c28:      	add	x16, x16, #0x248
   79c2c:      	br	x17

0000000000079c30 <__cxa_free_exception@plt>:
   79c30:      	adrp	x16, 0x83000
   79c34:      	ldr	x17, [x16, #0x250]
   79c38:      	add	x16, x16, #0x250
   79c3c:      	br	x17

0000000000079c40 <_ZNSt11logic_errorC2EPKc@plt>:
   79c40:      	adrp	x16, 0x83000
   79c44:      	ldr	x17, [x16, #0x258]
   79c48:      	add	x16, x16, #0x258
   79c4c:      	br	x17

0000000000079c50 <_Z27ai_detection_plugin_set_jvmP7_JavaVM@plt>:
   79c50:      	adrp	x16, 0x83000
   79c54:      	ldr	x17, [x16, #0x260]
   79c58:      	add	x16, x16, #0x260
   79c5c:      	br	x17

0000000000079c60 <_Z43register_ai_detection_plugin_native_methodsP7_JNIEnv@plt>:
   79c60:      	adrp	x16, 0x83000
   79c64:      	ldr	x17, [x16, #0x268]
   79c68:      	add	x16, x16, #0x268
   79c6c:      	br	x17

0000000000079c70 <_Z62register_com_meitu_aidetectionplugin_MTAIDetectionPluginConfigP7_JNIEnv@plt>:
   79c70:      	adrp	x16, 0x83000
   79c74:      	ldr	x17, [x16, #0x270]
   79c78:      	add	x16, x16, #0x270
   79c7c:      	br	x17

0000000000079c80 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig13setAILogLevelENS_12AI_LOG_LEVELE@plt>:
   79c80:      	adrp	x16, 0x83000
   79c84:      	ldr	x17, [x16, #0x278]
   79c88:      	add	x16, x16, #0x278
   79c8c:      	br	x17

0000000000079c90 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig22setEnableParamsCaptureEb@plt>:
   79c90:      	adrp	x16, 0x83000
   79c94:      	ldr	x17, [x16, #0x280]
   79c98:      	add	x16, x16, #0x280
   79c9c:      	br	x17

0000000000079ca0 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig18setSingleModelPathEPKcS2_@plt>:
   79ca0:      	adrp	x16, 0x83000
   79ca4:      	ldr	x17, [x16, #0x288]
   79ca8:      	add	x16, x16, #0x288
   79cac:      	br	x17

0000000000079cb0 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig15setDetectParamsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   79cb0:      	adrp	x16, 0x83000
   79cb4:      	ldr	x17, [x16, #0x290]
   79cb8:      	add	x16, x16, #0x290
   79cbc:      	br	x17

0000000000079cc0 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig15getDetectParamsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   79cc0:      	adrp	x16, 0x83000
   79cc4:      	ldr	x17, [x16, #0x298]
   79cc8:      	add	x16, x16, #0x298
   79ccc:      	br	x17

0000000000079cd0 <PF_registerPlugin@plt>:
   79cd0:      	adrp	x16, 0x83000
   79cd4:      	ldr	x17, [x16, #0x2a0]
   79cd8:      	add	x16, x16, #0x2a0
   79cdc:      	br	x17

0000000000079ce0 <_ZN17MMDetectionPlugin10AIDetector11copyTextureEPN10verenderer16MTTextureBackendES3_PNS1_22MTRenderCommandEncoderEiii@plt>:
   79ce0:      	adrp	x16, 0x83000
   79ce4:      	ldr	x17, [x16, #0x2a8]
   79ce8:      	add	x16, x16, #0x2a8
   79cec:      	br	x17

0000000000079cf0 <_ZN10verenderer4Vec4C1Effff@plt>:
   79cf0:      	adrp	x16, 0x83000
   79cf4:      	ldr	x17, [x16, #0x2b0]
   79cf8:      	add	x16, x16, #0x2b0
   79cfc:      	br	x17

0000000000079d00 <_ZN10verenderer12UniformValueC1EPNS_16MTTextureBackendEi@plt>:
   79d00:      	adrp	x16, 0x83000
   79d04:      	ldr	x17, [x16, #0x2b8]
   79d08:      	add	x16, x16, #0x2b8
   79d0c:      	br	x17

0000000000079d10 <_ZN10verenderer12UniformValueD1Ev@plt>:
   79d10:      	adrp	x16, 0x83000
   79d14:      	ldr	x17, [x16, #0x2c0]
   79d18:      	add	x16, x16, #0x2c0
   79d1c:      	br	x17

0000000000079d20 <_ZN5media4Mat4C1Ev@plt>:
   79d20:      	adrp	x16, 0x83000
   79d24:      	ldr	x17, [x16, #0x2c8]
   79d28:      	add	x16, x16, #0x2c8
   79d2c:      	br	x17

0000000000079d30 <_ZN5media4Mat410createExifEiPS0_@plt>:
   79d30:      	adrp	x16, 0x83000
   79d34:      	ldr	x17, [x16, #0x2d0]
   79d38:      	add	x16, x16, #0x2d0
   79d3c:      	br	x17

0000000000079d40 <_ZN10verenderer12UniformValueC1EPfi@plt>:
   79d40:      	adrp	x16, 0x83000
   79d44:      	ldr	x17, [x16, #0x2d8]
   79d48:      	add	x16, x16, #0x2d8
   79d4c:      	br	x17

0000000000079d50 <_ZN5media4Mat4D1Ev@plt>:
   79d50:      	adrp	x16, 0x83000
   79d54:      	ldr	x17, [x16, #0x2e0]
   79d58:      	add	x16, x16, #0x2e0
   79d5c:      	br	x17

0000000000079d60 <_ZN10verenderer4Vec4D1Ev@plt>:
   79d60:      	adrp	x16, 0x83000
   79d64:      	ldr	x17, [x16, #0x2e8]
   79d68:      	add	x16, x16, #0x2e8
   79d6c:      	br	x17

0000000000079d70 <vlai_engine_unload_require_all@plt>:
   79d70:      	adrp	x16, 0x83000
   79d74:      	ldr	x17, [x16, #0x2f0]
   79d78:      	add	x16, x16, #0x2f0
   79d7c:      	br	x17

0000000000079d80 <_ZN17MMDetectionPlugin16_DetectionOptionD2Ev@plt>:
   79d80:      	adrp	x16, 0x83000
   79d84:      	ldr	x17, [x16, #0x2f8]
   79d88:      	add	x16, x16, #0x2f8
   79d8c:      	br	x17

0000000000079d90 <vlai_setting_patch_destroy@plt>:
   79d90:      	adrp	x16, 0x83000
   79d94:      	ldr	x17, [x16, #0x300]
   79d98:      	add	x16, x16, #0x300
   79d9c:      	br	x17

0000000000079da0 <vlai_require_set_destroy@plt>:
   79da0:      	adrp	x16, 0x83000
   79da4:      	ldr	x17, [x16, #0x308]
   79da8:      	add	x16, x16, #0x308
   79dac:      	br	x17

0000000000079db0 <vlai_run_result_destroy@plt>:
   79db0:      	adrp	x16, 0x83000
   79db4:      	ldr	x17, [x16, #0x310]
   79db8:      	add	x16, x16, #0x310
   79dbc:      	br	x17

0000000000079dc0 <vlai_engine_release_session@plt>:
   79dc0:      	adrp	x16, 0x83000
   79dc4:      	ldr	x17, [x16, #0x318]
   79dc8:      	add	x16, x16, #0x318
   79dcc:      	br	x17

0000000000079dd0 <vlai_engine_destroy@plt>:
   79dd0:      	adrp	x16, 0x83000
   79dd4:      	ldr	x17, [x16, #0x320]
   79dd8:      	add	x16, x16, #0x320
   79ddc:      	br	x17

0000000000079de0 <vlai_destroy_graphics_env@plt>:
   79de0:      	adrp	x16, 0x83000
   79de4:      	ldr	x17, [x16, #0x328]
   79de8:      	add	x16, x16, #0x328
   79dec:      	br	x17

0000000000079df0 <_ZN17MMDetectionPlugin20_CropDetectionOptionD1Ev@plt>:
   79df0:      	adrp	x16, 0x83000
   79df4:      	ldr	x17, [x16, #0x330]
   79df8:      	add	x16, x16, #0x330
   79dfc:      	br	x17

0000000000079e00 <_ZN17MMDetectionPlugin19FaceDetectionResult4FaceD2Ev@plt>:
   79e00:      	adrp	x16, 0x83000
   79e04:      	ldr	x17, [x16, #0x338]
   79e08:      	add	x16, x16, #0x338
   79e0c:      	br	x17

0000000000079e10 <_ZN5media4Vec2D1Ev@plt>:
   79e10:      	adrp	x16, 0x83000
   79e14:      	ldr	x17, [x16, #0x340]
   79e18:      	add	x16, x16, #0x340
   79e1c:      	br	x17

0000000000079e20 <_ZN17MMDetectionPlugin14_Face25DOptionD1Ev@plt>:
   79e20:      	adrp	x16, 0x83000
   79e24:      	ldr	x17, [x16, #0x348]
   79e28:      	add	x16, x16, #0x348
   79e2c:      	br	x17

0000000000079e30 <_ZN17MMDetectionPlugin10AIDetectorD1Ev@plt>:
   79e30:      	adrp	x16, 0x83000
   79e34:      	ldr	x17, [x16, #0x350]
   79e38:      	add	x16, x16, #0x350
   79e3c:      	br	x17

0000000000079e40 <vlai_engine_create@plt>:
   79e40:      	adrp	x16, 0x83000
   79e44:      	ldr	x17, [x16, #0x358]
   79e48:      	add	x16, x16, #0x358
   79e4c:      	br	x17

0000000000079e50 <vlai_setting_patch_create@plt>:
   79e50:      	adrp	x16, 0x83000
   79e54:      	ldr	x17, [x16, #0x360]
   79e58:      	add	x16, x16, #0x360
   79e5c:      	br	x17

0000000000079e60 <vlai_require_set_create@plt>:
   79e60:      	adrp	x16, 0x83000
   79e64:      	ldr	x17, [x16, #0x368]
   79e68:      	add	x16, x16, #0x368
   79e6c:      	br	x17

0000000000079e70 <vlai_run_result_create@plt>:
   79e70:      	adrp	x16, 0x83000
   79e74:      	ldr	x17, [x16, #0x370]
   79e78:      	add	x16, x16, #0x370
   79e7c:      	br	x17

0000000000079e80 <vlai_engine_create_session@plt>:
   79e80:      	adrp	x16, 0x83000
   79e84:      	ldr	x17, [x16, #0x378]
   79e88:      	add	x16, x16, #0x378
   79e8c:      	br	x17

0000000000079e90 <vlai_engine_session_open@plt>:
   79e90:      	adrp	x16, 0x83000
   79e94:      	ldr	x17, [x16, #0x380]
   79e98:      	add	x16, x16, #0x380
   79e9c:      	br	x17

0000000000079ea0 <_Z15vllog_set_level13vllog_level_t@plt>:
   79ea0:      	adrp	x16, 0x83000
   79ea4:      	ldr	x17, [x16, #0x388]
   79ea8:      	add	x16, x16, #0x388
   79eac:      	br	x17

0000000000079eb0 <vlai_setting_patch_base_setting_patch@plt>:
   79eb0:      	adrp	x16, 0x83000
   79eb4:      	ldr	x17, [x16, #0x390]
   79eb8:      	add	x16, x16, #0x390
   79ebc:      	br	x17

0000000000079ec0 <vlai_base_setting_patch_set_run_mode@plt>:
   79ec0:      	adrp	x16, 0x83000
   79ec4:      	ldr	x17, [x16, #0x398]
   79ec8:      	add	x16, x16, #0x398
   79ecc:      	br	x17

0000000000079ed0 <vlai_setting_patch_model_setting_patch@plt>:
   79ed0:      	adrp	x16, 0x83000
   79ed4:      	ldr	x17, [x16, #0x3a0]
   79ed8:      	add	x16, x16, #0x3a0
   79edc:      	br	x17

0000000000079ee0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   79ee0:      	adrp	x16, 0x83000
   79ee4:      	ldr	x17, [x16, #0x3a8]
   79ee8:      	add	x16, x16, #0x3a8
   79eec:      	br	x17

0000000000079ef0 <vlai_model_setting_patch_set_directory@plt>:
   79ef0:      	adrp	x16, 0x83000
   79ef4:      	ldr	x17, [x16, #0x3b0]
   79ef8:      	add	x16, x16, #0x3b0
   79efc:      	br	x17

0000000000079f00 <vlai_engine_apply_setting@plt>:
   79f00:      	adrp	x16, 0x83000
   79f04:      	ldr	x17, [x16, #0x3b8]
   79f08:      	add	x16, x16, #0x3b8
   79f0c:      	br	x17

0000000000079f10 <vlai_set_context@plt>:
   79f10:      	adrp	x16, 0x83000
   79f14:      	ldr	x17, [x16, #0x3c0]
   79f18:      	add	x16, x16, #0x3c0
   79f1c:      	br	x17

0000000000079f20 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig18setSingleModelPathEPv@plt>:
   79f20:      	adrp	x16, 0x83000
   79f24:      	ldr	x17, [x16, #0x3c8]
   79f28:      	add	x16, x16, #0x3c8
   79f2c:      	br	x17

0000000000079f30 <_ZN17MMDetectionPlugin10FaceModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f30:      	adrp	x16, 0x83000
   79f34:      	ldr	x17, [x16, #0x3d0]
   79f38:      	add	x16, x16, #0x3d0
   79f3c:      	br	x17

0000000000079f40 <_ZN17MMDetectionPlugin22MaterialTrackingModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f40:      	adrp	x16, 0x83000
   79f44:      	ldr	x17, [x16, #0x3d8]
   79f48:      	add	x16, x16, #0x3d8
   79f4c:      	br	x17

0000000000079f50 <_ZN17MMDetectionPlugin13SegmentModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f50:      	adrp	x16, 0x83000
   79f54:      	ldr	x17, [x16, #0x3e0]
   79f58:      	add	x16, x16, #0x3e0
   79f5c:      	br	x17

0000000000079f60 <_ZN17MMDetectionPlugin10BodyModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f60:      	adrp	x16, 0x83000
   79f64:      	ldr	x17, [x16, #0x3e8]
   79f68:      	add	x16, x16, #0x3e8
   79f6c:      	br	x17

0000000000079f70 <_ZN17MMDetectionPlugin10DL3DModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f70:      	adrp	x16, 0x83000
   79f74:      	ldr	x17, [x16, #0x3f0]
   79f78:      	add	x16, x16, #0x3f0
   79f7c:      	br	x17

0000000000079f80 <_ZN17MMDetectionPlugin13Face25DModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f80:      	adrp	x16, 0x83000
   79f84:      	ldr	x17, [x16, #0x3f8]
   79f88:      	add	x16, x16, #0x3f8
   79f8c:      	br	x17

0000000000079f90 <_ZN17MMDetectionPlugin15VideoStabModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79f90:      	adrp	x16, 0x83000
   79f94:      	ldr	x17, [x16, #0x400]
   79f98:      	add	x16, x16, #0x400
   79f9c:      	br	x17

0000000000079fa0 <_ZN17MMDetectionPlugin15BodyInOneModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79fa0:      	adrp	x16, 0x83000
   79fa4:      	ldr	x17, [x16, #0x408]
   79fa8:      	add	x16, x16, #0x408
   79fac:      	br	x17

0000000000079fb0 <_ZN17MMDetectionPlugin18RtTeethTouchModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79fb0:      	adrp	x16, 0x83000
   79fb4:      	ldr	x17, [x16, #0x410]
   79fb8:      	add	x16, x16, #0x410
   79fbc:      	br	x17

0000000000079fc0 <_ZN17MMDetectionPlugin12AnimalModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79fc0:      	adrp	x16, 0x83000
   79fc4:      	ldr	x17, [x16, #0x418]
   79fc8:      	add	x16, x16, #0x418
   79fcc:      	br	x17

0000000000079fd0 <_ZN17MMDetectionPlugin13WrinkleModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79fd0:      	adrp	x16, 0x83000
   79fd4:      	ldr	x17, [x16, #0x420]
   79fd8:      	add	x16, x16, #0x420
   79fdc:      	br	x17

0000000000079fe0 <_ZN17MMDetectionPlugin10HandModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79fe0:      	adrp	x16, 0x83000
   79fe4:      	ldr	x17, [x16, #0x428]
   79fe8:      	add	x16, x16, #0x428
   79fec:      	br	x17

0000000000079ff0 <_ZN17MMDetectionPlugin10CropModuleC1ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   79ff0:      	adrp	x16, 0x83000
   79ff4:      	ldr	x17, [x16, #0x430]
   79ff8:      	add	x16, x16, #0x430
   79ffc:      	br	x17

000000000007a000 <_ZN17MMDetectionPlugin17ExDenseHairModuleC1ER18vlai_engine_handleR26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE@plt>:
   7a000:      	adrp	x16, 0x83000
   7a004:      	ldr	x17, [x16, #0x438]
   7a008:      	add	x16, x16, #0x438
   7a00c:      	br	x17

000000000007a010 <_ZN17MMDetectionPlugin21ExColorTransferModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7a010:      	adrp	x16, 0x83000
   7a014:      	ldr	x17, [x16, #0x440]
   7a018:      	add	x16, x16, #0x440
   7a01c:      	br	x17

000000000007a020 <_ZN17MMDetectionPlugin18ExAnySegmentModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7a020:      	adrp	x16, 0x83000
   7a024:      	ldr	x17, [x16, #0x448]
   7a028:      	add	x16, x16, #0x448
   7a02c:      	br	x17

000000000007a030 <_ZN17MMDetectionPlugin22PixarAnimateFaceModuleC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7a030:      	adrp	x16, 0x83000
   7a034:      	ldr	x17, [x16, #0x450]
   7a038:      	add	x16, x16, #0x450
   7a03c:      	br	x17

000000000007a040 <_ZNK17MMDetectionPlugin16_DetectionOptionneERKS0_@plt>:
   7a040:      	adrp	x16, 0x83000
   7a044:      	ldr	x17, [x16, #0x458]
   7a048:      	add	x16, x16, #0x458
   7a04c:      	br	x17

000000000007a050 <vlai_require_set_clear@plt>:
   7a050:      	adrp	x16, 0x83000
   7a054:      	ldr	x17, [x16, #0x460]
   7a058:      	add	x16, x16, #0x460
   7a05c:      	br	x17

000000000007a060 <vlai_engine_setting@plt>:
   7a060:      	adrp	x16, 0x83000
   7a064:      	ldr	x17, [x16, #0x468]
   7a068:      	add	x16, x16, #0x468
   7a06c:      	br	x17

000000000007a070 <vlai_setting_module_reset@plt>:
   7a070:      	adrp	x16, 0x83000
   7a074:      	ldr	x17, [x16, #0x470]
   7a078:      	add	x16, x16, #0x470
   7a07c:      	br	x17

000000000007a080 <_ZN17MMDetectionPlugin16_DetectionOptionC1ERKS0_@plt>:
   7a080:      	adrp	x16, 0x83000
   7a084:      	ldr	x17, [x16, #0x478]
   7a088:      	add	x16, x16, #0x478
   7a08c:      	br	x17

000000000007a090 <vlai_engine_session_module_unload@plt>:
   7a090:      	adrp	x16, 0x83000
   7a094:      	ldr	x17, [x16, #0x480]
   7a098:      	add	x16, x16, #0x480
   7a09c:      	br	x17

000000000007a0a0 <vlai_base_setting_patch_set_thread_max@plt>:
   7a0a0:      	adrp	x16, 0x83000
   7a0a4:      	ldr	x17, [x16, #0x488]
   7a0a8:      	add	x16, x16, #0x488
   7a0ac:      	br	x17

000000000007a0b0 <vlai_base_setting_patch_set_thread_mode@plt>:
   7a0b0:      	adrp	x16, 0x83000
   7a0b4:      	ldr	x17, [x16, #0x490]
   7a0b8:      	add	x16, x16, #0x490
   7a0bc:      	br	x17

000000000007a0c0 <_ZN10verenderer15MTRenderContext14currentContextEv@plt>:
   7a0c0:      	adrp	x16, 0x83000
   7a0c4:      	ldr	x17, [x16, #0x498]
   7a0c8:      	add	x16, x16, #0x498
   7a0cc:      	br	x17

000000000007a0d0 <vlai_create_graphics_env@plt>:
   7a0d0:      	adrp	x16, 0x83000
   7a0d4:      	ldr	x17, [x16, #0x4a0]
   7a0d8:      	add	x16, x16, #0x4a0
   7a0dc:      	br	x17

000000000007a0e0 <_ZN10verenderer15MTRenderContext13getRenderTypeEv@plt>:
   7a0e0:      	adrp	x16, 0x83000
   7a0e4:      	ldr	x17, [x16, #0x4a8]
   7a0e8:      	add	x16, x16, #0x4a8
   7a0ec:      	br	x17

000000000007a0f0 <_ZN10verenderer15MTRenderContext19getContextImplementEv@plt>:
   7a0f0:      	adrp	x16, 0x83000
   7a0f4:      	ldr	x17, [x16, #0x4b0]
   7a0f8:      	add	x16, x16, #0x4b0
   7a0fc:      	br	x17

000000000007a100 <_ZN10verenderer15MTRenderContext11queryDeviceERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7a100:      	adrp	x16, 0x83000
   7a104:      	ldr	x17, [x16, #0x4b8]
   7a108:      	add	x16, x16, #0x4b8
   7a10c:      	br	x17

000000000007a110 <vlai_graphics_env_initialize@plt>:
   7a110:      	adrp	x16, 0x83000
   7a114:      	ldr	x17, [x16, #0x4c0]
   7a118:      	add	x16, x16, #0x4c0
   7a11c:      	br	x17

000000000007a120 <vlai_engine_init@plt>:
   7a120:      	adrp	x16, 0x83000
   7a124:      	ldr	x17, [x16, #0x4c8]
   7a128:      	add	x16, x16, #0x4c8
   7a12c:      	br	x17

000000000007a130 <vldp_create_data_protocol_pointer@plt>:
   7a130:      	adrp	x16, 0x83000
   7a134:      	ldr	x17, [x16, #0x4d0]
   7a138:      	add	x16, x16, #0x4d0
   7a13c:      	br	x17

000000000007a140 <vldp_get_data_protocol_pointer_ref@plt>:
   7a140:      	adrp	x16, 0x83000
   7a144:      	ldr	x17, [x16, #0x4d8]
   7a148:      	add	x16, x16, #0x4d8
   7a14c:      	br	x17

000000000007a150 <vlai_frame_create@plt>:
   7a150:      	adrp	x16, 0x83000
   7a154:      	ldr	x17, [x16, #0x4e0]
   7a158:      	add	x16, x16, #0x4e0
   7a15c:      	br	x17

000000000007a160 <vlai_engine_runtime_setting@plt>:
   7a160:      	adrp	x16, 0x83000
   7a164:      	ldr	x17, [x16, #0x4e8]
   7a168:      	add	x16, x16, #0x4e8
   7a16c:      	br	x17

000000000007a170 <vldp_create_image_ref@plt>:
   7a170:      	adrp	x16, 0x83000
   7a174:      	ldr	x17, [x16, #0x4f0]
   7a178:      	add	x16, x16, #0x4f0
   7a17c:      	br	x17

000000000007a180 <vlai_frame_ref_color_image@plt>:
   7a180:      	adrp	x16, 0x83000
   7a184:      	ldr	x17, [x16, #0x4f8]
   7a188:      	add	x16, x16, #0x4f8
   7a18c:      	br	x17

000000000007a190 <vldp_release_image@plt>:
   7a190:      	adrp	x16, 0x83000
   7a194:      	ldr	x17, [x16, #0x500]
   7a198:      	add	x16, x16, #0x500
   7a19c:      	br	x17

000000000007a1a0 <vlai_frame_set_first_frame@plt>:
   7a1a0:      	adrp	x16, 0x83000
   7a1a4:      	ldr	x17, [x16, #0x508]
   7a1a8:      	add	x16, x16, #0x508
   7a1ac:      	br	x17

000000000007a1b0 <vlai_frame_set_capture_frame@plt>:
   7a1b0:      	adrp	x16, 0x83000
   7a1b4:      	ldr	x17, [x16, #0x510]
   7a1b8:      	add	x16, x16, #0x510
   7a1bc:      	br	x17

000000000007a1c0 <vldp_create_texture_ref@plt>:
   7a1c0:      	adrp	x16, 0x83000
   7a1c4:      	ldr	x17, [x16, #0x518]
   7a1c8:      	add	x16, x16, #0x518
   7a1cc:      	br	x17

000000000007a1d0 <vlai_texture_ref_texture@plt>:
   7a1d0:      	adrp	x16, 0x83000
   7a1d4:      	ldr	x17, [x16, #0x520]
   7a1d8:      	add	x16, x16, #0x520
   7a1dc:      	br	x17

000000000007a1e0 <vlai_frame_ref_texture@plt>:
   7a1e0:      	adrp	x16, 0x83000
   7a1e4:      	ldr	x17, [x16, #0x528]
   7a1e8:      	add	x16, x16, #0x528
   7a1ec:      	br	x17

000000000007a1f0 <vlai_texture_release@plt>:
   7a1f0:      	adrp	x16, 0x83000
   7a1f4:      	ldr	x17, [x16, #0x530]
   7a1f8:      	add	x16, x16, #0x530
   7a1fc:      	br	x17

000000000007a200 <vldp_release_texture@plt>:
   7a200:      	adrp	x16, 0x83000
   7a204:      	ldr	x17, [x16, #0x538]
   7a208:      	add	x16, x16, #0x538
   7a20c:      	br	x17

000000000007a210 <vlai_graphics_env_get_context@plt>:
   7a210:      	adrp	x16, 0x83000
   7a214:      	ldr	x17, [x16, #0x540]
   7a218:      	add	x16, x16, #0x540
   7a21c:      	br	x17

000000000007a220 <vldp_create_texture_ref_metal_with_context@plt>:
   7a220:      	adrp	x16, 0x83000
   7a224:      	ldr	x17, [x16, #0x548]
   7a228:      	add	x16, x16, #0x548
   7a22c:      	br	x17

000000000007a230 <vlai_run_result_reset@plt>:
   7a230:      	adrp	x16, 0x83000
   7a234:      	ldr	x17, [x16, #0x550]
   7a238:      	add	x16, x16, #0x550
   7a23c:      	br	x17

000000000007a240 <vlai_run_result_bind_input_data_protocol@plt>:
   7a240:      	adrp	x16, 0x83000
   7a244:      	ldr	x17, [x16, #0x558]
   7a248:      	add	x16, x16, #0x558
   7a24c:      	br	x17

000000000007a250 <_ZN10verenderer15MTRenderContext5flushEv@plt>:
   7a250:      	adrp	x16, 0x83000
   7a254:      	ldr	x17, [x16, #0x560]
   7a258:      	add	x16, x16, #0x560
   7a25c:      	br	x17

000000000007a260 <vlai_engine_session_run@plt>:
   7a260:      	adrp	x16, 0x83000
   7a264:      	ldr	x17, [x16, #0x568]
   7a268:      	add	x16, x16, #0x568
   7a26c:      	br	x17

000000000007a270 <vlai_graphics_env_wait_result@plt>:
   7a270:      	adrp	x16, 0x83000
   7a274:      	ldr	x17, [x16, #0x570]
   7a278:      	add	x16, x16, #0x570
   7a27c:      	br	x17

000000000007a280 <vlai_run_result_get_data_protocol@plt>:
   7a280:      	adrp	x16, 0x83000
   7a284:      	ldr	x17, [x16, #0x578]
   7a288:      	add	x16, x16, #0x578
   7a28c:      	br	x17

000000000007a290 <vldp_release_data_protocol_pointer@plt>:
   7a290:      	adrp	x16, 0x83000
   7a294:      	ldr	x17, [x16, #0x580]
   7a298:      	add	x16, x16, #0x580
   7a29c:      	br	x17

000000000007a2a0 <vlai_frame_destroy@plt>:
   7a2a0:      	adrp	x16, 0x83000
   7a2a4:      	ldr	x17, [x16, #0x588]
   7a2a8:      	add	x16, x16, #0x588
   7a2ac:      	br	x17

000000000007a2b0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   7a2b0:      	adrp	x16, 0x83000
   7a2b4:      	ldr	x17, [x16, #0x590]
   7a2b8:      	add	x16, x16, #0x590
   7a2bc:      	br	x17

000000000007a2c0 <_ZN17MMDetectionPlugin10FaceModule13getDetectDataEPKNS_14DetectionFrameEPKNS_16_DetectionOptionENSt6__ndk110shared_ptrINS_15DetectionResultEEER24vlai_graphics_env_handle@plt>:
   7a2c0:      	adrp	x16, 0x83000
   7a2c4:      	ldr	x17, [x16, #0x598]
   7a2c8:      	add	x16, x16, #0x598
   7a2cc:      	br	x17

000000000007a2d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm@plt>:
   7a2d0:      	adrp	x16, 0x83000
   7a2d4:      	ldr	x17, [x16, #0x5a0]
   7a2d8:      	add	x16, x16, #0x5a0
   7a2dc:      	br	x17

000000000007a2e0 <_ZN17MMDetectionPlugin10FaceModule17getOnceDetectDataEPKNS_14DetectionFrameEPKNS_16_DetectionOptionENSt6__ndk110shared_ptrINS_15DetectionResultEEENS7_12basic_stringIcNS7_11char_traitsIcEENS7_9allocatorIcEEEER25vlai_setting_patch_handleR27vlai_runtime_setting_handleR24vlai_graphics_env_handlePvb@plt>:
   7a2e0:      	adrp	x16, 0x83000
   7a2e4:      	ldr	x17, [x16, #0x5a8]
   7a2e8:      	add	x16, x16, #0x5a8
   7a2ec:      	br	x17

000000000007a2f0 <_ZN17MMDetectionPlugin21ExColorTransferModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEER24vlai_graphics_env_handlePv@plt>:
   7a2f0:      	adrp	x16, 0x83000
   7a2f4:      	ldr	x17, [x16, #0x5b0]
   7a2f8:      	add	x16, x16, #0x5b0
   7a2fc:      	br	x17

000000000007a300 <_ZN17MMDetectionPlugin17ExDenseHairModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionE@plt>:
   7a300:      	adrp	x16, 0x83000
   7a304:      	ldr	x17, [x16, #0x5b8]
   7a308:      	add	x16, x16, #0x5b8
   7a30c:      	br	x17

000000000007a310 <_ZN17MMDetectionPlugin22PixarAnimateFaceModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEER24vlai_graphics_env_handlePv@plt>:
   7a310:      	adrp	x16, 0x83000
   7a314:      	ldr	x17, [x16, #0x5c0]
   7a318:      	add	x16, x16, #0x5c0
   7a31c:      	br	x17

000000000007a320 <_ZN17MMDetectionPlugin18ExAnySegmentModule19registerExtraModuleEPKNS_21_ExtraDetectionOptionENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEER24vlai_graphics_env_handlePv@plt>:
   7a320:      	adrp	x16, 0x83000
   7a324:      	ldr	x17, [x16, #0x5c8]
   7a328:      	add	x16, x16, #0x5c8
   7a32c:      	br	x17

000000000007a330 <_ZN17MMDetectionPlugin21ExColorTransferModule14runExtraDetectEPKNS_21_ExtraDetectionOptionEPKNS_14DetectionFrameER24vlai_graphics_env_handleNSt6__ndk16vectorINS9_10shared_ptrINS_15DetectionResultEEENS9_9allocatorISD_EEEERSG_@plt>:
   7a330:      	adrp	x16, 0x83000
   7a334:      	ldr	x17, [x16, #0x5d0]
   7a338:      	add	x16, x16, #0x5d0
   7a33c:      	br	x17

000000000007a340 <_ZN17MMDetectionPlugin17ExDenseHairModule14runExtraDetectEPKNS_21_ExtraDetectionOptionEPKNS_14DetectionFrameER24vlai_graphics_env_handleNSt6__ndk16vectorINS9_10shared_ptrINS_15DetectionResultEEENS9_9allocatorISD_EEEERSG_@plt>:
   7a340:      	adrp	x16, 0x83000
   7a344:      	ldr	x17, [x16, #0x5d8]
   7a348:      	add	x16, x16, #0x5d8
   7a34c:      	br	x17

000000000007a350 <_ZN17MMDetectionPlugin22PixarAnimateFaceModule14runExtraDetectEPKNS_21_ExtraDetectionOptionEPKNS_14DetectionFrameER24vlai_graphics_env_handleNSt6__ndk16vectorINS9_10shared_ptrINS_15DetectionResultEEENS9_9allocatorISD_EEEERSG_@plt>:
   7a350:      	adrp	x16, 0x83000
   7a354:      	ldr	x17, [x16, #0x5e0]
   7a358:      	add	x16, x16, #0x5e0
   7a35c:      	br	x17

000000000007a360 <_ZN17MMDetectionPlugin18ExAnySegmentModule14runExtraDetectEPKNS_21_ExtraDetectionOptionEPKNS_14DetectionFrameER24vlai_graphics_env_handleNSt6__ndk16vectorINS9_10shared_ptrINS_15DetectionResultEEENS9_9allocatorISD_EEEERSG_@plt>:
   7a360:      	adrp	x16, 0x83000
   7a364:      	ldr	x17, [x16, #0x5e8]
   7a368:      	add	x16, x16, #0x5e8
   7a36c:      	br	x17

000000000007a370 <_ZNSt6__ndk16vectorIlNS_9allocatorIlEEE18__assign_with_sizeB8ne180000IPlS5_EEvT_T0_l@plt>:
   7a370:      	adrp	x16, 0x83000
   7a374:      	ldr	x17, [x16, #0x5f0]
   7a378:      	add	x16, x16, #0x5f0
   7a37c:      	br	x17

000000000007a380 <_ZN17MMDetectionPlugin17ExDenseHairModule16setEnableFaceIdsERNSt6__ndk16vectorIlNS1_9allocatorIlEEEEb@plt>:
   7a380:      	adrp	x16, 0x83000
   7a384:      	ldr	x17, [x16, #0x5f8]
   7a388:      	add	x16, x16, #0x5f8
   7a38c:      	br	x17

000000000007a390 <_ZN17MMDetectionPlugin10FaceModule21currentTrackDetectEndEPKNS_16_DetectionOptionE@plt>:
   7a390:      	adrp	x16, 0x83000
   7a394:      	ldr	x17, [x16, #0x600]
   7a398:      	add	x16, x16, #0x600
   7a39c:      	br	x17

000000000007a3a0 <_ZN17MMDetectionPlugin15BodyInOneModule21currentTrackDetectEndEPKN5media10PixelImageEPKNS_16_DetectionOptionENS1_15MTDetectionTypeER25vlai_setting_patch_handleR27vlai_runtime_setting_handleR24vlai_graphics_env_handle@plt>:
   7a3a0:      	adrp	x16, 0x83000
   7a3a4:      	ldr	x17, [x16, #0x608]
   7a3a8:      	add	x16, x16, #0x608
   7a3ac:      	br	x17

000000000007a3b0 <_ZN17MMDetectionPlugin10BaseModule14setDetectCahceEPN5media16MTDetectionCacheE@plt>:
   7a3b0:      	adrp	x16, 0x83000
   7a3b4:      	ldr	x17, [x16, #0x610]
   7a3b8:      	add	x16, x16, #0x610
   7a3bc:      	br	x17

000000000007a3c0 <_ZN17MMDetectionPlugin10BaseModule19setCurrentTrackUuidERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7a3c0:      	adrp	x16, 0x83000
   7a3c4:      	ldr	x17, [x16, #0x618]
   7a3c8:      	add	x16, x16, #0x618
   7a3cc:      	br	x17

000000000007a3d0 <_ZN17MMDetectionPlugin10FaceModule26refreshFaceRecognitionDataERNSt6__ndk13mapIlNS2_IlN5media15FaceImageStructENS1_4lessIlEENS1_9allocatorINS1_4pairIKlS4_EEEEEES6_NS7_INS8_IS9_SC_EEEEEENS1_12basic_stringIcNS1_11char_traitsIcEENS7_IcEEEEPv@plt>:
   7a3d0:      	adrp	x16, 0x83000
   7a3d4:      	ldr	x17, [x16, #0x620]
   7a3d8:      	add	x16, x16, #0x620
   7a3dc:      	br	x17

000000000007a3e0 <_ZN17MMDetectionPlugin10FaceModule21faceRecognitionSearchERKNS_19FaceDetectionResult17MTFaceRecognitionERKNSt6__ndk16vectorIS2_NS5_9allocatorIS2_EEEE@plt>:
   7a3e0:      	adrp	x16, 0x83000
   7a3e4:      	ldr	x17, [x16, #0x628]
   7a3e8:      	add	x16, x16, #0x628
   7a3ec:      	br	x17

000000000007a3f0 <_ZN17MMDetectionPlugin10FaceModule23generateFaceRecognitionEPN5media16MTDetectionCacheERKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEElRNS1_15FaceImageStructESA_Pv@plt>:
   7a3f0:      	adrp	x16, 0x83000
   7a3f4:      	ldr	x17, [x16, #0x630]
   7a3f8:      	add	x16, x16, #0x630
   7a3fc:      	br	x17

000000000007a400 <_ZN17MMDetectionPlugin10FaceModule17loadFaceBlockDataEv@plt>:
   7a400:      	adrp	x16, 0x83000
   7a404:      	ldr	x17, [x16, #0x638]
   7a408:      	add	x16, x16, #0x638
   7a40c:      	br	x17

000000000007a410 <_ZN17MMDetectionPlugin15BodyInOneModule22loadBodyInOneBlockDataEv@plt>:
   7a410:      	adrp	x16, 0x83000
   7a414:      	ldr	x17, [x16, #0x640]
   7a418:      	add	x16, x16, #0x640
   7a41c:      	br	x17

000000000007a420 <_ZN17MMDetectionPlugin19FaceDetectionResult10MTDL3DFaceD1Ev@plt>:
   7a420:      	adrp	x16, 0x83000
   7a424:      	ldr	x17, [x16, #0x648]
   7a428:      	add	x16, x16, #0x648
   7a42c:      	br	x17

000000000007a430 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   7a430:      	adrp	x16, 0x83000
   7a434:      	ldr	x17, [x16, #0x650]
   7a438:      	add	x16, x16, #0x650
   7a43c:      	br	x17

000000000007a440 <_ZNSt6__ndk16__treeINS_12__value_typeIiiEENS_19__map_value_compareIiS2_NS_4lessIiEELb1EEENS_9allocatorIS2_EEE12__find_equalIiEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS2_PNS_11__tree_nodeIS2_SC_EElEERPNS_15__tree_end_nodeISE_EESF_RKT_@plt>:
   7a440:      	adrp	x16, 0x83000
   7a444:      	ldr	x17, [x16, #0x658]
   7a448:      	add	x16, x16, #0x658
   7a44c:      	br	x17

000000000007a450 <_ZN17MMDetectionPlugin13FaceConverter26initFDResultFaceFromMTFaceEPNS_19FaceDetectionResult4FaceEPK16vldp_face_handlel@plt>:
   7a450:      	adrp	x16, 0x83000
   7a454:      	ldr	x17, [x16, #0x660]
   7a458:      	add	x16, x16, #0x660
   7a45c:      	br	x17

000000000007a460 <vldp_get_face_id@plt>:
   7a460:      	adrp	x16, 0x83000
   7a464:      	ldr	x17, [x16, #0x668]
   7a468:      	add	x16, x16, #0x668
   7a46c:      	br	x17

000000000007a470 <vldp_get_face_score@plt>:
   7a470:      	adrp	x16, 0x83000
   7a474:      	ldr	x17, [x16, #0x670]
   7a478:      	add	x16, x16, #0x670
   7a47c:      	br	x17

000000000007a480 <vldp_get_face_org_id@plt>:
   7a480:      	adrp	x16, 0x83000
   7a484:      	ldr	x17, [x16, #0x678]
   7a488:      	add	x16, x16, #0x678
   7a48c:      	br	x17

000000000007a490 <vldp_get_face_face_rect@plt>:
   7a490:      	adrp	x16, 0x83000
   7a494:      	ldr	x17, [x16, #0x680]
   7a498:      	add	x16, x16, #0x680
   7a49c:      	br	x17

000000000007a4a0 <vldp_get_face_has_face_occlusion@plt>:
   7a4a0:      	adrp	x16, 0x83000
   7a4a4:      	ldr	x17, [x16, #0x688]
   7a4a8:      	add	x16, x16, #0x688
   7a4ac:      	br	x17

000000000007a4b0 <vldp_get_face_face_occlusion@plt>:
   7a4b0:      	adrp	x16, 0x83000
   7a4b4:      	ldr	x17, [x16, #0x690]
   7a4b8:      	add	x16, x16, #0x690
   7a4bc:      	br	x17

000000000007a4c0 <vldp_get_face_face_points@plt>:
   7a4c0:      	adrp	x16, 0x83000
   7a4c4:      	ldr	x17, [x16, #0x698]
   7a4c8:      	add	x16, x16, #0x698
   7a4cc:      	br	x17

000000000007a4d0 <vldp_get_point2f_array_pointer_ref@plt>:
   7a4d0:      	adrp	x16, 0x83000
   7a4d4:      	ldr	x17, [x16, #0x6a0]
   7a4d8:      	add	x16, x16, #0x6a0
   7a4dc:      	br	x17

000000000007a4e0 <vldp_get_point2f_array_pointer_size@plt>:
   7a4e0:      	adrp	x16, 0x83000
   7a4e4:      	ldr	x17, [x16, #0x6a8]
   7a4e8:      	add	x16, x16, #0x6a8
   7a4ec:      	br	x17

000000000007a4f0 <vldp_get_face_head_points@plt>:
   7a4f0:      	adrp	x16, 0x83000
   7a4f4:      	ldr	x17, [x16, #0x6b0]
   7a4f8:      	add	x16, x16, #0x6b0
   7a4fc:      	br	x17

000000000007a500 <vldp_get_face_visibility@plt>:
   7a500:      	adrp	x16, 0x83000
   7a504:      	ldr	x17, [x16, #0x6b8]
   7a508:      	add	x16, x16, #0x6b8
   7a50c:      	br	x17

000000000007a510 <vldp_get_float_array_pointer_ref@plt>:
   7a510:      	adrp	x16, 0x83000
   7a514:      	ldr	x17, [x16, #0x6c0]
   7a518:      	add	x16, x16, #0x6c0
   7a51c:      	br	x17

000000000007a520 <vldp_get_float_array_pointer_size@plt>:
   7a520:      	adrp	x16, 0x83000
   7a524:      	ldr	x17, [x16, #0x6c8]
   7a528:      	add	x16, x16, #0x6c8
   7a52c:      	br	x17

000000000007a530 <vldp_get_face_neck_rect@plt>:
   7a530:      	adrp	x16, 0x83000
   7a534:      	ldr	x17, [x16, #0x6d0]
   7a538:      	add	x16, x16, #0x6d0
   7a53c:      	br	x17

000000000007a540 <vldp_get_face_neck_points@plt>:
   7a540:      	adrp	x16, 0x83000
   7a544:      	ldr	x17, [x16, #0x6d8]
   7a548:      	add	x16, x16, #0x6d8
   7a54c:      	br	x17

000000000007a550 <vldp_get_face_left_ear_points@plt>:
   7a550:      	adrp	x16, 0x83000
   7a554:      	ldr	x17, [x16, #0x6e0]
   7a558:      	add	x16, x16, #0x6e0
   7a55c:      	br	x17

000000000007a560 <vldp_get_face_right_ear_points@plt>:
   7a560:      	adrp	x16, 0x83000
   7a564:      	ldr	x17, [x16, #0x6e8]
   7a568:      	add	x16, x16, #0x6e8
   7a56c:      	br	x17

000000000007a570 <vldp_get_face_roll_angle@plt>:
   7a570:      	adrp	x16, 0x83000
   7a574:      	ldr	x17, [x16, #0x6f0]
   7a578:      	add	x16, x16, #0x6f0
   7a57c:      	br	x17

000000000007a580 <vldp_get_face_yaw_angle@plt>:
   7a580:      	adrp	x16, 0x83000
   7a584:      	ldr	x17, [x16, #0x6f8]
   7a588:      	add	x16, x16, #0x6f8
   7a58c:      	br	x17

000000000007a590 <vldp_get_face_pitch_angle@plt>:
   7a590:      	adrp	x16, 0x83000
   7a594:      	ldr	x17, [x16, #0x700]
   7a598:      	add	x16, x16, #0x700
   7a59c:      	br	x17

000000000007a5a0 <vldp_get_face_translate_x@plt>:
   7a5a0:      	adrp	x16, 0x83000
   7a5a4:      	ldr	x17, [x16, #0x708]
   7a5a8:      	add	x16, x16, #0x708
   7a5ac:      	br	x17

000000000007a5b0 <vldp_get_face_translate_y@plt>:
   7a5b0:      	adrp	x16, 0x83000
   7a5b4:      	ldr	x17, [x16, #0x710]
   7a5b8:      	add	x16, x16, #0x710
   7a5bc:      	br	x17

000000000007a5c0 <vldp_get_face_translate_z@plt>:
   7a5c0:      	adrp	x16, 0x83000
   7a5c4:      	ldr	x17, [x16, #0x718]
   7a5c8:      	add	x16, x16, #0x718
   7a5cc:      	br	x17

000000000007a5d0 <vldp_get_face_age@plt>:
   7a5d0:      	adrp	x16, 0x83000
   7a5d4:      	ldr	x17, [x16, #0x720]
   7a5d8:      	add	x16, x16, #0x720
   7a5dc:      	br	x17

000000000007a5e0 <vldp_get_face_gender@plt>:
   7a5e0:      	adrp	x16, 0x83000
   7a5e4:      	ldr	x17, [x16, #0x728]
   7a5e8:      	add	x16, x16, #0x728
   7a5ec:      	br	x17

000000000007a5f0 <vldp_get_face_race@plt>:
   7a5f0:      	adrp	x16, 0x83000
   7a5f4:      	ldr	x17, [x16, #0x730]
   7a5f8:      	add	x16, x16, #0x730
   7a5fc:      	br	x17

000000000007a600 <vldp_get_face_emotion@plt>:
   7a600:      	adrp	x16, 0x83000
   7a604:      	ldr	x17, [x16, #0x738]
   7a608:      	add	x16, x16, #0x738
   7a60c:      	br	x17

000000000007a610 <vldp_get_face_glasses@plt>:
   7a610:      	adrp	x16, 0x83000
   7a614:      	ldr	x17, [x16, #0x740]
   7a618:      	add	x16, x16, #0x740
   7a61c:      	br	x17

000000000007a620 <vldp_get_glasses_type@plt>:
   7a620:      	adrp	x16, 0x83000
   7a624:      	ldr	x17, [x16, #0x748]
   7a628:      	add	x16, x16, #0x748
   7a62c:      	br	x17

000000000007a630 <vldp_get_glasses_shape@plt>:
   7a630:      	adrp	x16, 0x83000
   7a634:      	ldr	x17, [x16, #0x750]
   7a638:      	add	x16, x16, #0x750
   7a63c:      	br	x17

000000000007a640 <vldp_get_glasses_frame@plt>:
   7a640:      	adrp	x16, 0x83000
   7a644:      	ldr	x17, [x16, #0x758]
   7a648:      	add	x16, x16, #0x758
   7a64c:      	br	x17

000000000007a650 <vldp_get_glasses_thickness@plt>:
   7a650:      	adrp	x16, 0x83000
   7a654:      	ldr	x17, [x16, #0x760]
   7a658:      	add	x16, x16, #0x760
   7a65c:      	br	x17

000000000007a660 <vldp_get_glasses_size@plt>:
   7a660:      	adrp	x16, 0x83000
   7a664:      	ldr	x17, [x16, #0x768]
   7a668:      	add	x16, x16, #0x768
   7a66c:      	br	x17

000000000007a670 <vldp_get_face_beauty@plt>:
   7a670:      	adrp	x16, 0x83000
   7a674:      	ldr	x17, [x16, #0x770]
   7a678:      	add	x16, x16, #0x770
   7a67c:      	br	x17

000000000007a680 <vldp_get_face_eyelid@plt>:
   7a680:      	adrp	x16, 0x83000
   7a684:      	ldr	x17, [x16, #0x778]
   7a688:      	add	x16, x16, #0x778
   7a68c:      	br	x17

000000000007a690 <vldp_get_face_eyelid_right@plt>:
   7a690:      	adrp	x16, 0x83000
   7a694:      	ldr	x17, [x16, #0x780]
   7a698:      	add	x16, x16, #0x780
   7a69c:      	br	x17

000000000007a6a0 <vldp_get_face_eyelid_left@plt>:
   7a6a0:      	adrp	x16, 0x83000
   7a6a4:      	ldr	x17, [x16, #0x788]
   7a6a8:      	add	x16, x16, #0x788
   7a6ac:      	br	x17

000000000007a6b0 <vldp_get_face_mustache@plt>:
   7a6b0:      	adrp	x16, 0x83000
   7a6b4:      	ldr	x17, [x16, #0x790]
   7a6b8:      	add	x16, x16, #0x790
   7a6bc:      	br	x17

000000000007a6c0 <vldp_get_mustache_type@plt>:
   7a6c0:      	adrp	x16, 0x83000
   7a6c4:      	ldr	x17, [x16, #0x798]
   7a6c8:      	add	x16, x16, #0x798
   7a6cc:      	br	x17

000000000007a6d0 <vldp_get_mustache_length@plt>:
   7a6d0:      	adrp	x16, 0x83000
   7a6d4:      	ldr	x17, [x16, #0x7a0]
   7a6d8:      	add	x16, x16, #0x7a0
   7a6dc:      	br	x17

000000000007a6e0 <vldp_get_mustache_shape@plt>:
   7a6e0:      	adrp	x16, 0x83000
   7a6e4:      	ldr	x17, [x16, #0x7a8]
   7a6e8:      	add	x16, x16, #0x7a8
   7a6ec:      	br	x17

000000000007a6f0 <vldp_get_mustache_thickness@plt>:
   7a6f0:      	adrp	x16, 0x83000
   7a6f4:      	ldr	x17, [x16, #0x7b0]
   7a6f8:      	add	x16, x16, #0x7b0
   7a6fc:      	br	x17

000000000007a700 <vldp_get_face_cheek@plt>:
   7a700:      	adrp	x16, 0x83000
   7a704:      	ldr	x17, [x16, #0x7b8]
   7a708:      	add	x16, x16, #0x7b8
   7a70c:      	br	x17

000000000007a710 <vldp_get_face_jaw@plt>:
   7a710:      	adrp	x16, 0x83000
   7a714:      	ldr	x17, [x16, #0x7c0]
   7a718:      	add	x16, x16, #0x7c0
   7a71c:      	br	x17

000000000007a720 <vldp_get_face_fr_id@plt>:
   7a720:      	adrp	x16, 0x83000
   7a724:      	ldr	x17, [x16, #0x7c8]
   7a728:      	add	x16, x16, #0x7c8
   7a72c:      	br	x17

000000000007a730 <vldp_get_face_fr_version@plt>:
   7a730:      	adrp	x16, 0x83000
   7a734:      	ldr	x17, [x16, #0x7d0]
   7a738:      	add	x16, x16, #0x7d0
   7a73c:      	br	x17

000000000007a740 <vldp_get_face_fr_norm@plt>:
   7a740:      	adrp	x16, 0x83000
   7a744:      	ldr	x17, [x16, #0x7d8]
   7a748:      	add	x16, x16, #0x7d8
   7a74c:      	br	x17

000000000007a750 <vldp_get_face_lip_mask_image@plt>:
   7a750:      	adrp	x16, 0x83000
   7a754:      	ldr	x17, [x16, #0x7e0]
   7a758:      	add	x16, x16, #0x7e0
   7a75c:      	br	x17

000000000007a760 <vldp_get_image_format@plt>:
   7a760:      	adrp	x16, 0x83000
   7a764:      	ldr	x17, [x16, #0x7e8]
   7a768:      	add	x16, x16, #0x7e8
   7a76c:      	br	x17

000000000007a770 <vldp_get_image_data@plt>:
   7a770:      	adrp	x16, 0x83000
   7a774:      	ldr	x17, [x16, #0x7f0]
   7a778:      	add	x16, x16, #0x7f0
   7a77c:      	br	x17

000000000007a780 <vldp_get_face_lip_matrix@plt>:
   7a780:      	adrp	x16, 0x83000
   7a784:      	ldr	x17, [x16, #0x7f8]
   7a788:      	add	x16, x16, #0x7f8
   7a78c:      	br	x17

000000000007a790 <vldp_get_image_width@plt>:
   7a790:      	adrp	x16, 0x83000
   7a794:      	ldr	x17, [x16, #0x800]
   7a798:      	add	x16, x16, #0x800
   7a79c:      	br	x17

000000000007a7a0 <vldp_get_image_height@plt>:
   7a7a0:      	adrp	x16, 0x83000
   7a7a4:      	ldr	x17, [x16, #0x808]
   7a7a8:      	add	x16, x16, #0x808
   7a7ac:      	br	x17

000000000007a7b0 <vldp_get_image_stride@plt>:
   7a7b0:      	adrp	x16, 0x83000
   7a7b4:      	ldr	x17, [x16, #0x810]
   7a7b8:      	add	x16, x16, #0x810
   7a7bc:      	br	x17

000000000007a7c0 <_ZN5media10PixelImage18newImageWithMemoryEjjjNS0_11PixelFormatEm@plt>:
   7a7c0:      	adrp	x16, 0x83000
   7a7c4:      	ldr	x17, [x16, #0x818]
   7a7c8:      	add	x16, x16, #0x818
   7a7cc:      	br	x17

000000000007a7d0 <vldp_get_face_face_parsing_mask_image@plt>:
   7a7d0:      	adrp	x16, 0x83000
   7a7d4:      	ldr	x17, [x16, #0x820]
   7a7d8:      	add	x16, x16, #0x820
   7a7dc:      	br	x17

000000000007a7e0 <vldp_get_face_face_parsing_matrix@plt>:
   7a7e0:      	adrp	x16, 0x83000
   7a7e4:      	ldr	x17, [x16, #0x828]
   7a7e8:      	add	x16, x16, #0x828
   7a7ec:      	br	x17

000000000007a7f0 <vldp_get_face_face_parsing_vertexs@plt>:
   7a7f0:      	adrp	x16, 0x83000
   7a7f4:      	ldr	x17, [x16, #0x830]
   7a7f8:      	add	x16, x16, #0x830
   7a7fc:      	br	x17

000000000007a800 <vldp_get_face_face_action@plt>:
   7a800:      	adrp	x16, 0x83000
   7a804:      	ldr	x17, [x16, #0x838]
   7a808:      	add	x16, x16, #0x838
   7a80c:      	br	x17

000000000007a810 <vldp_get_face_action_is_eye_blink@plt>:
   7a810:      	adrp	x16, 0x83000
   7a814:      	ldr	x17, [x16, #0x840]
   7a818:      	add	x16, x16, #0x840
   7a81c:      	br	x17

000000000007a820 <vldp_get_face_action_is_left_eye_close@plt>:
   7a820:      	adrp	x16, 0x83000
   7a824:      	ldr	x17, [x16, #0x848]
   7a828:      	add	x16, x16, #0x848
   7a82c:      	br	x17

000000000007a830 <vldp_get_face_action_is_right_eye_close@plt>:
   7a830:      	adrp	x16, 0x83000
   7a834:      	ldr	x17, [x16, #0x850]
   7a838:      	add	x16, x16, #0x850
   7a83c:      	br	x17

000000000007a840 <vldp_get_face_action_is_eye_brow_up@plt>:
   7a840:      	adrp	x16, 0x83000
   7a844:      	ldr	x17, [x16, #0x858]
   7a848:      	add	x16, x16, #0x858
   7a84c:      	br	x17

000000000007a850 <vldp_get_face_action_is_mouth_open@plt>:
   7a850:      	adrp	x16, 0x83000
   7a854:      	ldr	x17, [x16, #0x860]
   7a858:      	add	x16, x16, #0x860
   7a85c:      	br	x17

000000000007a860 <vldp_get_face_action_is_kiss@plt>:
   7a860:      	adrp	x16, 0x83000
   7a864:      	ldr	x17, [x16, #0x868]
   7a868:      	add	x16, x16, #0x868
   7a86c:      	br	x17

000000000007a870 <vldp_get_face_action_is_nod@plt>:
   7a870:      	adrp	x16, 0x83000
   7a874:      	ldr	x17, [x16, #0x870]
   7a878:      	add	x16, x16, #0x870
   7a87c:      	br	x17

000000000007a880 <vldp_get_face_action_is_head_turn_left@plt>:
   7a880:      	adrp	x16, 0x83000
   7a884:      	ldr	x17, [x16, #0x878]
   7a888:      	add	x16, x16, #0x878
   7a88c:      	br	x17

000000000007a890 <vldp_get_face_action_is_head_turn_right@plt>:
   7a890:      	adrp	x16, 0x83000
   7a894:      	ldr	x17, [x16, #0x880]
   7a898:      	add	x16, x16, #0x880
   7a89c:      	br	x17

000000000007a8a0 <vldp_get_face_action_is_head_raise_up@plt>:
   7a8a0:      	adrp	x16, 0x83000
   7a8a4:      	ldr	x17, [x16, #0x888]
   7a8a8:      	add	x16, x16, #0x888
   7a8ac:      	br	x17

000000000007a8b0 <vldp_get_face_action_is_head_fall_down@plt>:
   7a8b0:      	adrp	x16, 0x83000
   7a8b4:      	ldr	x17, [x16, #0x890]
   7a8b8:      	add	x16, x16, #0x890
   7a8bc:      	br	x17

000000000007a8c0 <vldp_get_face_facial_features@plt>:
   7a8c0:      	adrp	x16, 0x83000
   7a8c4:      	ldr	x17, [x16, #0x898]
   7a8c8:      	add	x16, x16, #0x898
   7a8cc:      	br	x17

000000000007a8d0 <vldp_get_facial_feature_eyebrow@plt>:
   7a8d0:      	adrp	x16, 0x83000
   7a8d4:      	ldr	x17, [x16, #0x8a0]
   7a8d8:      	add	x16, x16, #0x8a0
   7a8dc:      	br	x17

000000000007a8e0 <vldp_get_eyebrow_type_code@plt>:
   7a8e0:      	adrp	x16, 0x83000
   7a8e4:      	ldr	x17, [x16, #0x8a8]
   7a8e8:      	add	x16, x16, #0x8a8
   7a8ec:      	br	x17

000000000007a8f0 <vldp_get_string_ref@plt>:
   7a8f0:      	adrp	x16, 0x83000
   7a8f4:      	ldr	x17, [x16, #0x8b0]
   7a8f8:      	add	x16, x16, #0x8b0
   7a8fc:      	br	x17

000000000007a900 <vldp_get_eyebrow_thick_code@plt>:
   7a900:      	adrp	x16, 0x83000
   7a904:      	ldr	x17, [x16, #0x8b8]
   7a908:      	add	x16, x16, #0x8b8
   7a90c:      	br	x17

000000000007a910 <vldp_get_eyebrow_distribute_code@plt>:
   7a910:      	adrp	x16, 0x83000
   7a914:      	ldr	x17, [x16, #0x8c0]
   7a918:      	add	x16, x16, #0x8c0
   7a91c:      	br	x17

000000000007a920 <vldp_get_eyebrow_spacing_code@plt>:
   7a920:      	adrp	x16, 0x83000
   7a924:      	ldr	x17, [x16, #0x8c8]
   7a928:      	add	x16, x16, #0x8c8
   7a92c:      	br	x17

000000000007a930 <vldp_get_eyebrow_type@plt>:
   7a930:      	adrp	x16, 0x83000
   7a934:      	ldr	x17, [x16, #0x8d0]
   7a938:      	add	x16, x16, #0x8d0
   7a93c:      	br	x17

000000000007a940 <vldp_get_eyebrow_thick@plt>:
   7a940:      	adrp	x16, 0x83000
   7a944:      	ldr	x17, [x16, #0x8d8]
   7a948:      	add	x16, x16, #0x8d8
   7a94c:      	br	x17

000000000007a950 <vldp_get_eyebrow_distribute@plt>:
   7a950:      	adrp	x16, 0x83000
   7a954:      	ldr	x17, [x16, #0x8e0]
   7a958:      	add	x16, x16, #0x8e0
   7a95c:      	br	x17

000000000007a960 <vldp_get_eyebrow_spacing@plt>:
   7a960:      	adrp	x16, 0x83000
   7a964:      	ldr	x17, [x16, #0x8e8]
   7a968:      	add	x16, x16, #0x8e8
   7a96c:      	br	x17

000000000007a970 <vldp_get_string_size@plt>:
   7a970:      	adrp	x16, 0x83000
   7a974:      	ldr	x17, [x16, #0x8f0]
   7a978:      	add	x16, x16, #0x8f0
   7a97c:      	br	x17

000000000007a980 <vldp_get_facial_feature_eye@plt>:
   7a980:      	adrp	x16, 0x83000
   7a984:      	ldr	x17, [x16, #0x8f8]
   7a988:      	add	x16, x16, #0x8f8
   7a98c:      	br	x17

000000000007a990 <vldp_get_eye_spacing_code@plt>:
   7a990:      	adrp	x16, 0x83000
   7a994:      	ldr	x17, [x16, #0x900]
   7a998:      	add	x16, x16, #0x900
   7a99c:      	br	x17

000000000007a9a0 <vldp_get_eye_area_code@plt>:
   7a9a0:      	adrp	x16, 0x83000
   7a9a4:      	ldr	x17, [x16, #0x908]
   7a9a8:      	add	x16, x16, #0x908
   7a9ac:      	br	x17

000000000007a9b0 <vldp_get_eye_spacing@plt>:
   7a9b0:      	adrp	x16, 0x83000
   7a9b4:      	ldr	x17, [x16, #0x910]
   7a9b8:      	add	x16, x16, #0x910
   7a9bc:      	br	x17

000000000007a9c0 <vldp_get_eye_area@plt>:
   7a9c0:      	adrp	x16, 0x83000
   7a9c4:      	ldr	x17, [x16, #0x918]
   7a9c8:      	add	x16, x16, #0x918
   7a9cc:      	br	x17

000000000007a9d0 <vldp_get_facial_feature_nose_wing@plt>:
   7a9d0:      	adrp	x16, 0x83000
   7a9d4:      	ldr	x17, [x16, #0x920]
   7a9d8:      	add	x16, x16, #0x920
   7a9dc:      	br	x17

000000000007a9e0 <vldp_get_facial_feature_nose_wing_code@plt>:
   7a9e0:      	adrp	x16, 0x83000
   7a9e4:      	ldr	x17, [x16, #0x928]
   7a9e8:      	add	x16, x16, #0x928
   7a9ec:      	br	x17

000000000007a9f0 <vldp_get_facial_feature_lip@plt>:
   7a9f0:      	adrp	x16, 0x83000
   7a9f4:      	ldr	x17, [x16, #0x930]
   7a9f8:      	add	x16, x16, #0x930
   7a9fc:      	br	x17

000000000007aa00 <vldp_get_lip_thick_code@plt>:
   7aa00:      	adrp	x16, 0x83000
   7aa04:      	ldr	x17, [x16, #0x938]
   7aa08:      	add	x16, x16, #0x938
   7aa0c:      	br	x17

000000000007aa10 <vldp_get_lip_peak_code@plt>:
   7aa10:      	adrp	x16, 0x83000
   7aa14:      	ldr	x17, [x16, #0x940]
   7aa18:      	add	x16, x16, #0x940
   7aa1c:      	br	x17

000000000007aa20 <vldp_get_lip_thick@plt>:
   7aa20:      	adrp	x16, 0x83000
   7aa24:      	ldr	x17, [x16, #0x948]
   7aa28:      	add	x16, x16, #0x948
   7aa2c:      	br	x17

000000000007aa30 <vldp_get_lip_peak@plt>:
   7aa30:      	adrp	x16, 0x83000
   7aa34:      	ldr	x17, [x16, #0x950]
   7aa38:      	add	x16, x16, #0x950
   7aa3c:      	br	x17

000000000007aa40 <vldp_get_facial_feature_face_type@plt>:
   7aa40:      	adrp	x16, 0x83000
   7aa44:      	ldr	x17, [x16, #0x958]
   7aa48:      	add	x16, x16, #0x958
   7aa4c:      	br	x17

000000000007aa50 <vldp_get_facial_feature_face_type_code@plt>:
   7aa50:      	adrp	x16, 0x83000
   7aa54:      	ldr	x17, [x16, #0x960]
   7aa58:      	add	x16, x16, #0x960
   7aa5c:      	br	x17

000000000007aa60 <vldp_get_face_gender_score@plt>:
   7aa60:      	adrp	x16, 0x83000
   7aa64:      	ldr	x17, [x16, #0x968]
   7aa68:      	add	x16, x16, #0x968
   7aa6c:      	br	x17

000000000007aa70 <vldp_get_face_race_score@plt>:
   7aa70:      	adrp	x16, 0x83000
   7aa74:      	ldr	x17, [x16, #0x970]
   7aa78:      	add	x16, x16, #0x970
   7aa7c:      	br	x17

000000000007aa80 <vldp_get_face_emotion_score@plt>:
   7aa80:      	adrp	x16, 0x83000
   7aa84:      	ldr	x17, [x16, #0x978]
   7aa88:      	add	x16, x16, #0x978
   7aa8c:      	br	x17

000000000007aa90 <vldp_get_glasses_glass_score@plt>:
   7aa90:      	adrp	x16, 0x83000
   7aa94:      	ldr	x17, [x16, #0x980]
   7aa98:      	add	x16, x16, #0x980
   7aa9c:      	br	x17

000000000007aaa0 <vldp_get_face_eyelid_left_score@plt>:
   7aaa0:      	adrp	x16, 0x83000
   7aaa4:      	ldr	x17, [x16, #0x988]
   7aaa8:      	add	x16, x16, #0x988
   7aaac:      	br	x17

000000000007aab0 <vldp_get_face_eyelid_right_score@plt>:
   7aab0:      	adrp	x16, 0x83000
   7aab4:      	ldr	x17, [x16, #0x990]
   7aab8:      	add	x16, x16, #0x990
   7aabc:      	br	x17

000000000007aac0 <vldp_get_mustache_mustache_score@plt>:
   7aac0:      	adrp	x16, 0x83000
   7aac4:      	ldr	x17, [x16, #0x998]
   7aac8:      	add	x16, x16, #0x998
   7aacc:      	br	x17

000000000007aad0 <vldp_get_face_cheek_score@plt>:
   7aad0:      	adrp	x16, 0x83000
   7aad4:      	ldr	x17, [x16, #0x9a0]
   7aad8:      	add	x16, x16, #0x9a0
   7aadc:      	br	x17

000000000007aae0 <vldp_get_face_jaw_score@plt>:
   7aae0:      	adrp	x16, 0x83000
   7aae4:      	ldr	x17, [x16, #0x9a8]
   7aae8:      	add	x16, x16, #0x9a8
   7aaec:      	br	x17

000000000007aaf0 <vldp_get_facial_feature_nose_wing_score@plt>:
   7aaf0:      	adrp	x16, 0x83000
   7aaf4:      	ldr	x17, [x16, #0x9b0]
   7aaf8:      	add	x16, x16, #0x9b0
   7aafc:      	br	x17

000000000007ab00 <vldp_get_facial_feature_eyebrow_score@plt>:
   7ab00:      	adrp	x16, 0x83000
   7ab04:      	ldr	x17, [x16, #0x9b8]
   7ab08:      	add	x16, x16, #0x9b8
   7ab0c:      	br	x17

000000000007ab10 <vldp_get_facial_feature_eye_score@plt>:
   7ab10:      	adrp	x16, 0x83000
   7ab14:      	ldr	x17, [x16, #0x9c0]
   7ab18:      	add	x16, x16, #0x9c0
   7ab1c:      	br	x17

000000000007ab20 <vldp_get_facial_feature_lip_score@plt>:
   7ab20:      	adrp	x16, 0x83000
   7ab24:      	ldr	x17, [x16, #0x9c8]
   7ab28:      	add	x16, x16, #0x9c8
   7ab2c:      	br	x17

000000000007ab30 <vldp_get_facial_feature_face_type_score@plt>:
   7ab30:      	adrp	x16, 0x83000
   7ab34:      	ldr	x17, [x16, #0x9d0]
   7ab38:      	add	x16, x16, #0x9d0
   7ab3c:      	br	x17

000000000007ab40 <vldp_get_face_face_dl3d@plt>:
   7ab40:      	adrp	x16, 0x83000
   7ab44:      	ldr	x17, [x16, #0x9d8]
   7ab48:      	add	x16, x16, #0x9d8
   7ab4c:      	br	x17

000000000007ab50 <vldp_get_dl3d_face_id_coef@plt>:
   7ab50:      	adrp	x16, 0x83000
   7ab54:      	ldr	x17, [x16, #0x9e0]
   7ab58:      	add	x16, x16, #0x9e0
   7ab5c:      	br	x17

000000000007ab60 <vldp_get_dl3d_face_exp_coef@plt>:
   7ab60:      	adrp	x16, 0x83000
   7ab64:      	ldr	x17, [x16, #0x9e8]
   7ab68:      	add	x16, x16, #0x9e8
   7ab6c:      	br	x17

000000000007ab70 <free@plt>:
   7ab70:      	adrp	x16, 0x83000
   7ab74:      	ldr	x17, [x16, #0x9f0]
   7ab78:      	add	x16, x16, #0x9f0
   7ab7c:      	br	x17

000000000007ab80 <malloc@plt>:
   7ab80:      	adrp	x16, 0x83000
   7ab84:      	ldr	x17, [x16, #0x9f8]
   7ab88:      	add	x16, x16, #0x9f8
   7ab8c:      	br	x17

000000000007ab90 <vldp_get_dl3d_face_mvp_matrix@plt>:
   7ab90:      	adrp	x16, 0x83000
   7ab94:      	ldr	x17, [x16, #0xa00]
   7ab98:      	add	x16, x16, #0xa00
   7ab9c:      	br	x17

000000000007aba0 <vldp_get_dl3d_face_euler@plt>:
   7aba0:      	adrp	x16, 0x83000
   7aba4:      	ldr	x17, [x16, #0xa08]
   7aba8:      	add	x16, x16, #0xa08
   7abac:      	br	x17

000000000007abb0 <vldp_get_dl3d_face_translation@plt>:
   7abb0:      	adrp	x16, 0x83000
   7abb4:      	ldr	x17, [x16, #0xa10]
   7abb8:      	add	x16, x16, #0xa10
   7abbc:      	br	x17

000000000007abc0 <vldp_get_dl3d_face_rotation_matrix@plt>:
   7abc0:      	adrp	x16, 0x83000
   7abc4:      	ldr	x17, [x16, #0xa18]
   7abc8:      	add	x16, x16, #0xa18
   7abcc:      	br	x17

000000000007abd0 <vldp_get_dl3d_face_projection_matrix@plt>:
   7abd0:      	adrp	x16, 0x83000
   7abd4:      	ldr	x17, [x16, #0xa20]
   7abd8:      	add	x16, x16, #0xa20
   7abdc:      	br	x17

000000000007abe0 <vldp_get_dl3d_face_model_matrix@plt>:
   7abe0:      	adrp	x16, 0x83000
   7abe4:      	ldr	x17, [x16, #0xa28]
   7abe8:      	add	x16, x16, #0xa28
   7abec:      	br	x17

000000000007abf0 <vldp_get_dl3d_face_view_matrix@plt>:
   7abf0:      	adrp	x16, 0x83000
   7abf4:      	ldr	x17, [x16, #0xa30]
   7abf8:      	add	x16, x16, #0xa30
   7abfc:      	br	x17

000000000007ac00 <vldp_get_dl3d_face_scale@plt>:
   7ac00:      	adrp	x16, 0x83000
   7ac04:      	ldr	x17, [x16, #0xa38]
   7ac08:      	add	x16, x16, #0xa38
   7ac0c:      	br	x17

000000000007ac10 <_ZN17MMDetectionPlugin13FaceConverter34initFDResultPartFaceFromMTPartFaceEPNS_19FaceDetectionResult8PartFaceEPK21vldp_part_face_handle@plt>:
   7ac10:      	adrp	x16, 0x83000
   7ac14:      	ldr	x17, [x16, #0xa40]
   7ac18:      	add	x16, x16, #0xa40
   7ac1c:      	br	x17

000000000007ac20 <vldp_get_part_face_face_id@plt>:
   7ac20:      	adrp	x16, 0x83000
   7ac24:      	ldr	x17, [x16, #0xa48]
   7ac28:      	add	x16, x16, #0xa48
   7ac2c:      	br	x17

000000000007ac30 <vldp_get_part_face_face_rect@plt>:
   7ac30:      	adrp	x16, 0x83000
   7ac34:      	ldr	x17, [x16, #0xa50]
   7ac38:      	add	x16, x16, #0xa50
   7ac3c:      	br	x17

000000000007ac40 <vldp_get_part_face_face_points@plt>:
   7ac40:      	adrp	x16, 0x83000
   7ac44:      	ldr	x17, [x16, #0xa58]
   7ac48:      	add	x16, x16, #0xa58
   7ac4c:      	br	x17

000000000007ac50 <_ZN17MMDetectionPlugin13FaceConverter24initCustomFaceFromMTFaceEPNS_19FaceDetectionResult4FaceEPK16vldp_face_handle@plt>:
   7ac50:      	adrp	x16, 0x83000
   7ac54:      	ldr	x17, [x16, #0xa60]
   7ac58:      	add	x16, x16, #0xa60
   7ac5c:      	br	x17

000000000007ac60 <_ZN17MMDetectionPlugin13FaceConverter18init3DFAFromMTFaceEPNS_19FaceDetectionResult4FaceEPK16vldp_face_handlePK23vldp_face_result_handle@plt>:
   7ac60:      	adrp	x16, 0x83000
   7ac64:      	ldr	x17, [x16, #0xa68]
   7ac68:      	add	x16, x16, #0xa68
   7ac6c:      	br	x17

000000000007ac70 <vldp_get_dl3d_face_vertex@plt>:
   7ac70:      	adrp	x16, 0x83000
   7ac74:      	ldr	x17, [x16, #0xa70]
   7ac78:      	add	x16, x16, #0xa70
   7ac7c:      	br	x17

000000000007ac80 <vldp_get_point3f_array_pointer_size@plt>:
   7ac80:      	adrp	x16, 0x83000
   7ac84:      	ldr	x17, [x16, #0xa78]
   7ac88:      	add	x16, x16, #0xa78
   7ac8c:      	br	x17

000000000007ac90 <vldp_get_point3f_array_pointer_ref@plt>:
   7ac90:      	adrp	x16, 0x83000
   7ac94:      	ldr	x17, [x16, #0xa80]
   7ac98:      	add	x16, x16, #0xa80
   7ac9c:      	br	x17

000000000007aca0 <vldp_get_dl3d_face_neutral_points@plt>:
   7aca0:      	adrp	x16, 0x83000
   7aca4:      	ldr	x17, [x16, #0xa88]
   7aca8:      	add	x16, x16, #0xa88
   7acac:      	br	x17

000000000007acb0 <vldp_get_dl3d_face_normal@plt>:
   7acb0:      	adrp	x16, 0x83000
   7acb4:      	ldr	x17, [x16, #0xa90]
   7acb8:      	add	x16, x16, #0xa90
   7acbc:      	br	x17

000000000007acc0 <vldp_get_dl3d_face_vertices_normal@plt>:
   7acc0:      	adrp	x16, 0x83000
   7acc4:      	ldr	x17, [x16, #0xa98]
   7acc8:      	add	x16, x16, #0xa98
   7accc:      	br	x17

000000000007acd0 <vldp_get_dl3d_face_tangent@plt>:
   7acd0:      	adrp	x16, 0x83000
   7acd4:      	ldr	x17, [x16, #0xaa0]
   7acd8:      	add	x16, x16, #0xaa0
   7acdc:      	br	x17

000000000007ace0 <vldp_get_dl3d_face_binormal@plt>:
   7ace0:      	adrp	x16, 0x83000
   7ace4:      	ldr	x17, [x16, #0xaa8]
   7ace8:      	add	x16, x16, #0xaa8
   7acec:      	br	x17

000000000007acf0 <vldp_get_face_result_texture_coordinates@plt>:
   7acf0:      	adrp	x16, 0x83000
   7acf4:      	ldr	x17, [x16, #0xab0]
   7acf8:      	add	x16, x16, #0xab0
   7acfc:      	br	x17

000000000007ad00 <vldp_get_face_result_triangle_indexs@plt>:
   7ad00:      	adrp	x16, 0x83000
   7ad04:      	ldr	x17, [x16, #0xab8]
   7ad08:      	add	x16, x16, #0xab8
   7ad0c:      	br	x17

000000000007ad10 <vldp_get_uint16_array_pointer_size@plt>:
   7ad10:      	adrp	x16, 0x83000
   7ad14:      	ldr	x17, [x16, #0xac0]
   7ad18:      	add	x16, x16, #0xac0
   7ad1c:      	br	x17

000000000007ad20 <vldp_get_uint16_array_pointer_ref@plt>:
   7ad20:      	adrp	x16, 0x83000
   7ad24:      	ldr	x17, [x16, #0xac8]
   7ad28:      	add	x16, x16, #0xac8
   7ad2c:      	br	x17

000000000007ad30 <_ZN17MMDetectionPlugin13FaceConverter32initResultFaceBodyFromMTFaceBodyEPNS_19FaceDetectionResult8FaceBodyEPK21vldp_face_body_handlel@plt>:
   7ad30:      	adrp	x16, 0x83000
   7ad34:      	ldr	x17, [x16, #0xad0]
   7ad38:      	add	x16, x16, #0xad0
   7ad3c:      	br	x17

000000000007ad40 <vldp_get_face_body_body_score@plt>:
   7ad40:      	adrp	x16, 0x83000
   7ad44:      	ldr	x17, [x16, #0xad8]
   7ad48:      	add	x16, x16, #0xad8
   7ad4c:      	br	x17

000000000007ad50 <vldp_get_face_body_body_id@plt>:
   7ad50:      	adrp	x16, 0x83000
   7ad54:      	ldr	x17, [x16, #0xae0]
   7ad58:      	add	x16, x16, #0xae0
   7ad5c:      	br	x17

000000000007ad60 <vldp_get_face_body_body_rect_roll@plt>:
   7ad60:      	adrp	x16, 0x83000
   7ad64:      	ldr	x17, [x16, #0xae8]
   7ad68:      	add	x16, x16, #0xae8
   7ad6c:      	br	x17

000000000007ad70 <vldp_get_face_body_body_rect@plt>:
   7ad70:      	adrp	x16, 0x83000
   7ad74:      	ldr	x17, [x16, #0xaf0]
   7ad78:      	add	x16, x16, #0xaf0
   7ad7c:      	br	x17

000000000007ad80 <vldp_get_face_body_body_point_score@plt>:
   7ad80:      	adrp	x16, 0x83000
   7ad84:      	ldr	x17, [x16, #0xaf8]
   7ad88:      	add	x16, x16, #0xaf8
   7ad8c:      	br	x17

000000000007ad90 <vldp_get_face_body_body_points@plt>:
   7ad90:      	adrp	x16, 0x83000
   7ad94:      	ldr	x17, [x16, #0xb00]
   7ad98:      	add	x16, x16, #0xb00
   7ad9c:      	br	x17

000000000007ada0 <_ZN17MMDetectionPlugin13FaceConverter32initResultMTFaceBodyFromFaceBodyEP21vldp_face_body_handlePKNS_19FaceDetectionResult8FaceBodyE@plt>:
   7ada0:      	adrp	x16, 0x83000
   7ada4:      	ldr	x17, [x16, #0xb08]
   7ada8:      	add	x16, x16, #0xb08
   7adac:      	br	x17

000000000007adb0 <vldp_set_face_body_has_body_id@plt>:
   7adb0:      	adrp	x16, 0x83000
   7adb4:      	ldr	x17, [x16, #0xb10]
   7adb8:      	add	x16, x16, #0xb10
   7adbc:      	br	x17

000000000007adc0 <vldp_set_face_body_body_id@plt>:
   7adc0:      	adrp	x16, 0x83000
   7adc4:      	ldr	x17, [x16, #0xb18]
   7adc8:      	add	x16, x16, #0xb18
   7adcc:      	br	x17

000000000007add0 <vldp_set_face_body_has_body_score@plt>:
   7add0:      	adrp	x16, 0x83000
   7add4:      	ldr	x17, [x16, #0xb20]
   7add8:      	add	x16, x16, #0xb20
   7addc:      	br	x17

000000000007ade0 <vldp_set_face_body_body_score@plt>:
   7ade0:      	adrp	x16, 0x83000
   7ade4:      	ldr	x17, [x16, #0xb28]
   7ade8:      	add	x16, x16, #0xb28
   7adec:      	br	x17

000000000007adf0 <vldp_set_face_body_has_body_rect_roll@plt>:
   7adf0:      	adrp	x16, 0x83000
   7adf4:      	ldr	x17, [x16, #0xb30]
   7adf8:      	add	x16, x16, #0xb30
   7adfc:      	br	x17

000000000007ae00 <vldp_set_face_body_body_rect_roll@plt>:
   7ae00:      	adrp	x16, 0x83000
   7ae04:      	ldr	x17, [x16, #0xb38]
   7ae08:      	add	x16, x16, #0xb38
   7ae0c:      	br	x17

000000000007ae10 <vldp_set_face_body_has_body_rect@plt>:
   7ae10:      	adrp	x16, 0x83000
   7ae14:      	ldr	x17, [x16, #0xb40]
   7ae18:      	add	x16, x16, #0xb40
   7ae1c:      	br	x17

000000000007ae20 <vldp_set_face_body_body_rect@plt>:
   7ae20:      	adrp	x16, 0x83000
   7ae24:      	ldr	x17, [x16, #0xb48]
   7ae28:      	add	x16, x16, #0xb48
   7ae2c:      	br	x17

000000000007ae30 <vldp_create_point2f_array_pointer@plt>:
   7ae30:      	adrp	x16, 0x83000
   7ae34:      	ldr	x17, [x16, #0xb50]
   7ae38:      	add	x16, x16, #0xb50
   7ae3c:      	br	x17

000000000007ae40 <vldp_set_point2f_array_pointer_hold@plt>:
   7ae40:      	adrp	x16, 0x83000
   7ae44:      	ldr	x17, [x16, #0xb58]
   7ae48:      	add	x16, x16, #0xb58
   7ae4c:      	br	x17

000000000007ae50 <vldp_release_point2f_array_pointer@plt>:
   7ae50:      	adrp	x16, 0x83000
   7ae54:      	ldr	x17, [x16, #0xb60]
   7ae58:      	add	x16, x16, #0xb60
   7ae5c:      	br	x17

000000000007ae60 <vldp_create_float_array_pointer@plt>:
   7ae60:      	adrp	x16, 0x83000
   7ae64:      	ldr	x17, [x16, #0xb68]
   7ae68:      	add	x16, x16, #0xb68
   7ae6c:      	br	x17

000000000007ae70 <vldp_set_float_array_pointer_hold@plt>:
   7ae70:      	adrp	x16, 0x83000
   7ae74:      	ldr	x17, [x16, #0xb70]
   7ae78:      	add	x16, x16, #0xb70
   7ae7c:      	br	x17

000000000007ae80 <vldp_release_float_array_pointer@plt>:
   7ae80:      	adrp	x16, 0x83000
   7ae84:      	ldr	x17, [x16, #0xb78]
   7ae88:      	add	x16, x16, #0xb78
   7ae8c:      	br	x17

000000000007ae90 <_ZN17MMDetectionPlugin13BodyConverter32initBodyResultBodyInfoFromMTBodyEPNS_19BodyDetectionResult8BodyInfoERK16vldp_body_handle@plt>:
   7ae90:      	adrp	x16, 0x83000
   7ae94:      	ldr	x17, [x16, #0xb80]
   7ae98:      	add	x16, x16, #0xb80
   7ae9c:      	br	x17

000000000007aea0 <vldp_get_body_has_body_rect@plt>:
   7aea0:      	adrp	x16, 0x83000
   7aea4:      	ldr	x17, [x16, #0xb88]
   7aea8:      	add	x16, x16, #0xb88
   7aeac:      	br	x17

000000000007aeb0 <vldp_get_body_body_rect_score@plt>:
   7aeb0:      	adrp	x16, 0x83000
   7aeb4:      	ldr	x17, [x16, #0xb90]
   7aeb8:      	add	x16, x16, #0xb90
   7aebc:      	br	x17

000000000007aec0 <vldp_get_body_body_rect@plt>:
   7aec0:      	adrp	x16, 0x83000
   7aec4:      	ldr	x17, [x16, #0xb98]
   7aec8:      	add	x16, x16, #0xb98
   7aecc:      	br	x17

000000000007aed0 <vldp_get_body_body_points@plt>:
   7aed0:      	adrp	x16, 0x83000
   7aed4:      	ldr	x17, [x16, #0xba0]
   7aed8:      	add	x16, x16, #0xba0
   7aedc:      	br	x17

000000000007aee0 <vldp_get_body_body_scores@plt>:
   7aee0:      	adrp	x16, 0x83000
   7aee4:      	ldr	x17, [x16, #0xba8]
   7aee8:      	add	x16, x16, #0xba8
   7aeec:      	br	x17

000000000007aef0 <_ZN17MMDetectionPlugin13BodyConverter47initBodyInOneResultBodyInOneInfoFromMTBodyInOneEPNS_24BodyInOneDetectionResult13BodyInOneInfoERK23vldp_body_in_one_handleRb@plt>:
   7aef0:      	adrp	x16, 0x83000
   7aef4:      	ldr	x17, [x16, #0xbb0]
   7aef8:      	add	x16, x16, #0xbb0
   7aefc:      	br	x17

000000000007af00 <vldp_get_body_in_one_body_rect@plt>:
   7af00:      	adrp	x16, 0x83000
   7af04:      	ldr	x17, [x16, #0xbb8]
   7af08:      	add	x16, x16, #0xbb8
   7af0c:      	br	x17

000000000007af10 <vldp_get_body_in_one_shoulder_rect@plt>:
   7af10:      	adrp	x16, 0x83000
   7af14:      	ldr	x17, [x16, #0xbc0]
   7af18:      	add	x16, x16, #0xbc0
   7af1c:      	br	x17

000000000007af20 <vldp_get_body_in_one_re_id@plt>:
   7af20:      	adrp	x16, 0x83000
   7af24:      	ldr	x17, [x16, #0xbc8]
   7af28:      	add	x16, x16, #0xbc8
   7af2c:      	br	x17

000000000007af30 <vldp_get_body_in_one_body_rect_score@plt>:
   7af30:      	adrp	x16, 0x83000
   7af34:      	ldr	x17, [x16, #0xbd0]
   7af38:      	add	x16, x16, #0xbd0
   7af3c:      	br	x17

000000000007af40 <vldp_get_body_in_one_shoulder_rect_score@plt>:
   7af40:      	adrp	x16, 0x83000
   7af44:      	ldr	x17, [x16, #0xbd8]
   7af48:      	add	x16, x16, #0xbd8
   7af4c:      	br	x17

000000000007af50 <vldp_get_body_in_one_pose@plt>:
   7af50:      	adrp	x16, 0x83000
   7af54:      	ldr	x17, [x16, #0xbe0]
   7af58:      	add	x16, x16, #0xbe0
   7af5c:      	br	x17

000000000007af60 <vldp_get_body_point_array_pointer_size@plt>:
   7af60:      	adrp	x16, 0x83000
   7af64:      	ldr	x17, [x16, #0xbe8]
   7af68:      	add	x16, x16, #0xbe8
   7af6c:      	br	x17

000000000007af70 <vldp_get_body_point_score@plt>:
   7af70:      	adrp	x16, 0x83000
   7af74:      	ldr	x17, [x16, #0xbf0]
   7af78:      	add	x16, x16, #0xbf0
   7af7c:      	br	x17

000000000007af80 <vldp_get_body_point_array_pointer_at@plt>:
   7af80:      	adrp	x16, 0x83000
   7af84:      	ldr	x17, [x16, #0xbf8]
   7af88:      	add	x16, x16, #0xbf8
   7af8c:      	br	x17

000000000007af90 <vldp_get_body_point_point@plt>:
   7af90:      	adrp	x16, 0x83000
   7af94:      	ldr	x17, [x16, #0xc00]
   7af98:      	add	x16, x16, #0xc00
   7af9c:      	br	x17

000000000007afa0 <vldp_get_body_point_occlu_score@plt>:
   7afa0:      	adrp	x16, 0x83000
   7afa4:      	ldr	x17, [x16, #0xc08]
   7afa8:      	add	x16, x16, #0xc08
   7afac:      	br	x17

000000000007afb0 <vldp_get_body_in_one_contour@plt>:
   7afb0:      	adrp	x16, 0x83000
   7afb4:      	ldr	x17, [x16, #0xc10]
   7afb8:      	add	x16, x16, #0xc10
   7afbc:      	br	x17

000000000007afc0 <vldp_get_body_in_one_shoulder@plt>:
   7afc0:      	adrp	x16, 0x83000
   7afc4:      	ldr	x17, [x16, #0xc18]
   7afc8:      	add	x16, x16, #0xc18
   7afcc:      	br	x17

000000000007afd0 <vldp_get_body_in_one_neck@plt>:
   7afd0:      	adrp	x16, 0x83000
   7afd4:      	ldr	x17, [x16, #0xc20]
   7afd8:      	add	x16, x16, #0xc20
   7afdc:      	br	x17

000000000007afe0 <vldp_get_body_in_one_breast@plt>:
   7afe0:      	adrp	x16, 0x83000
   7afe4:      	ldr	x17, [x16, #0xc28]
   7afe8:      	add	x16, x16, #0xc28
   7afec:      	br	x17

000000000007aff0 <_ZN17MMDetectionPlugin13BodyConverter32initCropResultCropInfoFromMTCropEPNS_19CropDetectionResult8CropInfoERK23vldp_body_in_one_handlePNSt6__ndk14pairIffEE@plt>:
   7aff0:      	adrp	x16, 0x83000
   7aff4:      	ldr	x17, [x16, #0xc30]
   7aff8:      	add	x16, x16, #0xc30
   7affc:      	br	x17

000000000007b000 <_ZN17MMDetectionPlugin13DL3DConverter30initDL3DNetResultFromMTDL3DNetEPNS_10DL3DResult4DL3DERK16vldp_dl3d_handle@plt>:
   7b000:      	adrp	x16, 0x83000
   7b004:      	ldr	x17, [x16, #0xc38]
   7b008:      	add	x16, x16, #0xc38
   7b00c:      	br	x17

000000000007b010 <vldp_get_dl3d_face_id@plt>:
   7b010:      	adrp	x16, 0x83000
   7b014:      	ldr	x17, [x16, #0xc40]
   7b018:      	add	x16, x16, #0xc40
   7b01c:      	br	x17

000000000007b020 <vldp_get_dl3d_dl3d_net_result@plt>:
   7b020:      	adrp	x16, 0x83000
   7b024:      	ldr	x17, [x16, #0xc48]
   7b028:      	add	x16, x16, #0xc48
   7b02c:      	br	x17

000000000007b030 <vldp_get_dl3d_net_indentity@plt>:
   7b030:      	adrp	x16, 0x83000
   7b034:      	ldr	x17, [x16, #0xc50]
   7b038:      	add	x16, x16, #0xc50
   7b03c:      	br	x17

000000000007b040 <vldp_get_dl3d_net_expression@plt>:
   7b040:      	adrp	x16, 0x83000
   7b044:      	ldr	x17, [x16, #0xc58]
   7b048:      	add	x16, x16, #0xc58
   7b04c:      	br	x17

000000000007b050 <vldp_get_dl3d_net_euler@plt>:
   7b050:      	adrp	x16, 0x83000
   7b054:      	ldr	x17, [x16, #0xc60]
   7b058:      	add	x16, x16, #0xc60
   7b05c:      	br	x17

000000000007b060 <vldp_get_dl3d_net_gl_mvp_matrix@plt>:
   7b060:      	adrp	x16, 0x83000
   7b064:      	ldr	x17, [x16, #0xc68]
   7b068:      	add	x16, x16, #0xc68
   7b06c:      	br	x17

000000000007b070 <vldp_get_dl3d_net_n_width@plt>:
   7b070:      	adrp	x16, 0x83000
   7b074:      	ldr	x17, [x16, #0xc70]
   7b078:      	add	x16, x16, #0xc70
   7b07c:      	br	x17

000000000007b080 <vldp_get_dl3d_net_n_height@plt>:
   7b080:      	adrp	x16, 0x83000
   7b084:      	ldr	x17, [x16, #0xc78]
   7b088:      	add	x16, x16, #0xc78
   7b08c:      	br	x17

000000000007b090 <vldp_get_dl3d_net_expression_flag@plt>:
   7b090:      	adrp	x16, 0x83000
   7b094:      	ldr	x17, [x16, #0xc80]
   7b098:      	add	x16, x16, #0xc80
   7b09c:      	br	x17

000000000007b0a0 <vldp_get_dl3d_net_expression_blendshape@plt>:
   7b0a0:      	adrp	x16, 0x83000
   7b0a4:      	ldr	x17, [x16, #0xc88]
   7b0a8:      	add	x16, x16, #0xc88
   7b0ac:      	br	x17

000000000007b0b0 <vldp_get_dl3d_net_rotation_matrix@plt>:
   7b0b0:      	adrp	x16, 0x83000
   7b0b4:      	ldr	x17, [x16, #0xc90]
   7b0b8:      	add	x16, x16, #0xc90
   7b0bc:      	br	x17

000000000007b0c0 <vldp_get_dl3d_net_translation@plt>:
   7b0c0:      	adrp	x16, 0x83000
   7b0c4:      	ldr	x17, [x16, #0xc98]
   7b0c8:      	add	x16, x16, #0xc98
   7b0cc:      	br	x17

000000000007b0d0 <vldp_get_dl3d_net_projection_matrix@plt>:
   7b0d0:      	adrp	x16, 0x83000
   7b0d4:      	ldr	x17, [x16, #0xca0]
   7b0d8:      	add	x16, x16, #0xca0
   7b0dc:      	br	x17

000000000007b0e0 <_ZN17MMDetectionPlugin13DL3DConverter32initDL3DMeshResultFromMTDL3DMeshEPNS_10DL3DResult4DL3DERK16vldp_dl3d_handle@plt>:
   7b0e0:      	adrp	x16, 0x83000
   7b0e4:      	ldr	x17, [x16, #0xca8]
   7b0e8:      	add	x16, x16, #0xca8
   7b0ec:      	br	x17

000000000007b0f0 <vldp_get_dl3d_dl3d_mesh_result@plt>:
   7b0f0:      	adrp	x16, 0x83000
   7b0f4:      	ldr	x17, [x16, #0xcb0]
   7b0f8:      	add	x16, x16, #0xcb0
   7b0fc:      	br	x17

000000000007b100 <vldp_get_dl3d_mesh_vertices@plt>:
   7b100:      	adrp	x16, 0x83000
   7b104:      	ldr	x17, [x16, #0xcb8]
   7b108:      	add	x16, x16, #0xcb8
   7b10c:      	br	x17

000000000007b110 <vldp_get_dl3d_mesh_texcoords@plt>:
   7b110:      	adrp	x16, 0x83000
   7b114:      	ldr	x17, [x16, #0xcc0]
   7b118:      	add	x16, x16, #0xcc0
   7b11c:      	br	x17

000000000007b120 <vldp_get_dl3d_mesh_triangles@plt>:
   7b120:      	adrp	x16, 0x83000
   7b124:      	ldr	x17, [x16, #0xcc8]
   7b128:      	add	x16, x16, #0xcc8
   7b12c:      	br	x17

000000000007b130 <_ZN17MMDetectionPlugin23AIDetectionPluginConfigC1Ev@plt>:
   7b130:      	adrp	x16, 0x83000
   7b134:      	ldr	x17, [x16, #0xcd0]
   7b138:      	add	x16, x16, #0xcd0
   7b13c:      	br	x17

000000000007b140 <_ZN17MMDetectionPlugin23AIDetectionPluginConfigD1Ev@plt>:
   7b140:      	adrp	x16, 0x83000
   7b144:      	ldr	x17, [x16, #0xcd8]
   7b148:      	add	x16, x16, #0xcd8
   7b14c:      	br	x17

000000000007b150 <vlai_get_version@plt>:
   7b150:      	adrp	x16, 0x83000
   7b154:      	ldr	x17, [x16, #0xce0]
   7b158:      	add	x16, x16, #0xce0
   7b15c:      	br	x17

000000000007b160 <vlai_model_setting_patch_set_model_path@plt>:
   7b160:      	adrp	x16, 0x83000
   7b164:      	ldr	x17, [x16, #0xce8]
   7b168:      	add	x16, x16, #0xce8
   7b16c:      	br	x17

000000000007b170 <_ZNSt6__ndk13mapIllNS_4lessIlEENS_9allocatorINS_4pairIKllEEEEE6insertB8ne180000INS_20__map_const_iteratorINS_21__tree_const_iteratorINS_12__value_typeIllEEPNS_11__tree_nodeISD_PvEElEEEEEEvT_SK_@plt>:
   7b170:      	adrp	x16, 0x83000
   7b174:      	ldr	x17, [x16, #0xcf0]
   7b178:      	add	x16, x16, #0xcf0
   7b17c:      	br	x17

000000000007b180 <_ZN5media18MTDetectionService15setDetectionEnvENSt6__ndk13mapIllNS1_4lessIlEENS1_9allocatorINS1_4pairIKllEEEEEENS1_12basic_stringIcNS1_11char_traitsIcEENS5_IcEEEE@plt>:
   7b180:      	adrp	x16, 0x83000
   7b184:      	ldr	x17, [x16, #0xcf8]
   7b188:      	add	x16, x16, #0xcf8
   7b18c:      	br	x17

000000000007b190 <_ZnwmRKSt9nothrow_t@plt>:
   7b190:      	adrp	x16, 0x83000
   7b194:      	ldr	x17, [x16, #0xd00]
   7b198:      	add	x16, x16, #0xd00
   7b19c:      	br	x17

000000000007b1a0 <_ZdlPvRKSt9nothrow_t@plt>:
   7b1a0:      	adrp	x16, 0x83000
   7b1a4:      	ldr	x17, [x16, #0xd08]
   7b1a8:      	add	x16, x16, #0xd08
   7b1ac:      	br	x17

000000000007b1b0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
   7b1b0:      	adrp	x16, 0x83000
   7b1b4:      	ldr	x17, [x16, #0xd10]
   7b1b8:      	add	x16, x16, #0xd10
   7b1bc:      	br	x17

000000000007b1c0 <_ZNSt6__ndk112__tuple_implINS_15__tuple_indicesIJLm0ELm1ELm2ELm3ELm4ELm5ELm6EEEEJNS_10unique_ptrINS_15__thread_structENS_14default_deleteIS4_EEEEPFvNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESD_SD_NS_8functionIFviEEEbEPKcSD_SD_SG_bEEC2B8ne180000IJLm0ELm1ELm2ELm3ELm4ELm5ELm6EEJS7_SI_SK_SD_SD_SG_bETpTnmJEJEJS7_SI_RA1_SJ_RSD_SP_RSG_RbEEENS1_IJXspT_EEEENS_13__tuple_typesIJDpT0_EEENS1_IJXspT1_EEEENST_IJDpT2_EEEDpOT3_@plt>:
   7b1c0:      	adrp	x16, 0x83000
   7b1c4:      	ldr	x17, [x16, #0xd18]
   7b1c8:      	add	x16, x16, #0xd18
   7b1cc:      	br	x17

000000000007b1d0 <pthread_create@plt>:
   7b1d0:      	adrp	x16, 0x83000
   7b1d4:      	ldr	x17, [x16, #0xd20]
   7b1d8:      	add	x16, x16, #0xd20
   7b1dc:      	br	x17

000000000007b1e0 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
   7b1e0:      	adrp	x16, 0x83000
   7b1e4:      	ldr	x17, [x16, #0xd28]
   7b1e8:      	add	x16, x16, #0xd28
   7b1ec:      	br	x17

000000000007b1f0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
   7b1f0:      	adrp	x16, 0x83000
   7b1f4:      	ldr	x17, [x16, #0xd30]
   7b1f8:      	add	x16, x16, #0xd30
   7b1fc:      	br	x17

000000000007b200 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   7b200:      	adrp	x16, 0x83000
   7b204:      	ldr	x17, [x16, #0xd38]
   7b208:      	add	x16, x16, #0xd38
   7b20c:      	br	x17

000000000007b210 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSJ_IJEEEEEENS_4pairINS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_@plt>:
   7b210:      	adrp	x16, 0x83000
   7b214:      	ldr	x17, [x16, #0xd40]
   7b218:      	add	x16, x16, #0xd40
   7b21c:      	br	x17

000000000007b220 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig15getDetectParamsEv@plt>:
   7b220:      	adrp	x16, 0x83000
   7b224:      	ldr	x17, [x16, #0xd48]
   7b228:      	add	x16, x16, #0xd48
   7b22c:      	br	x17

000000000007b230 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_@plt>:
   7b230:      	adrp	x16, 0x83000
   7b234:      	ldr	x17, [x16, #0xd50]
   7b238:      	add	x16, x16, #0xd50
   7b23c:      	br	x17

000000000007b240 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig13getMaxFaceNumEv@plt>:
   7b240:      	adrp	x16, 0x83000
   7b244:      	ldr	x17, [x16, #0xd58]
   7b248:      	add	x16, x16, #0xd58
   7b24c:      	br	x17

000000000007b250 <_ZN17MMDetectionPlugin23AIDetectionPluginConfig14getMinimalFaceEv@plt>:
   7b250:      	adrp	x16, 0x83000
   7b254:      	ldr	x17, [x16, #0xd60]
   7b258:      	add	x16, x16, #0xd60
   7b25c:      	br	x17

000000000007b260 <_ZNSt6__ndk16thread4joinEv@plt>:
   7b260:      	adrp	x16, 0x83000
   7b264:      	ldr	x17, [x16, #0xd68]
   7b268:      	add	x16, x16, #0xd68
   7b26c:      	br	x17

000000000007b270 <_ZNSt6__ndk16threadD1Ev@plt>:
   7b270:      	adrp	x16, 0x83000
   7b274:      	ldr	x17, [x16, #0xd70]
   7b278:      	add	x16, x16, #0xd70
   7b27c:      	br	x17

000000000007b280 <_ZNSt6__ndk16__treeINS_12__value_typeIllEENS_19__map_value_compareIlS2_NS_4lessIlEELb1EEENS_9allocatorIS2_EEE12__find_equalIlEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS2_PNS_11__tree_nodeIS2_SC_EElEERPNS_15__tree_end_nodeISE_EESF_RKT_@plt>:
   7b280:      	adrp	x16, 0x83000
   7b284:      	ldr	x17, [x16, #0xd78]
   7b288:      	add	x16, x16, #0xd78
   7b28c:      	br	x17

000000000007b290 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
   7b290:      	adrp	x16, 0x83000
   7b294:      	ldr	x17, [x16, #0xd80]
   7b298:      	add	x16, x16, #0xd80
   7b29c:      	br	x17

000000000007b2a0 <_ZNSt6__ndk112__tuple_leafILm0ENS_10unique_ptrINS_15__thread_structENS_14default_deleteIS2_EEEELb0EED2Ev@plt>:
   7b2a0:      	adrp	x16, 0x83000
   7b2a4:      	ldr	x17, [x16, #0xd88]
   7b2a8:      	add	x16, x16, #0xd88
   7b2ac:      	br	x17

000000000007b2b0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISJ_EERKT_@plt>:
   7b2b0:      	adrp	x16, 0x83000
   7b2b4:      	ldr	x17, [x16, #0xd90]
   7b2b8:      	add	x16, x16, #0xd90
   7b2bc:      	br	x17

000000000007b2c0 <memcmp@plt>:
   7b2c0:      	adrp	x16, 0x83000
   7b2c4:      	ldr	x17, [x16, #0xd98]
   7b2c8:      	add	x16, x16, #0xd98
   7b2cc:      	br	x17

000000000007b2d0 <vlai_video_recognition_codec_create@plt>:
   7b2d0:      	adrp	x16, 0x83000
   7b2d4:      	ldr	x17, [x16, #0xda0]
   7b2d8:      	add	x16, x16, #0xda0
   7b2dc:      	br	x17

000000000007b2e0 <vlai_video_recognition_codec_destory@plt>:
   7b2e0:      	adrp	x16, 0x83000
   7b2e4:      	ldr	x17, [x16, #0xda8]
   7b2e8:      	add	x16, x16, #0xda8
   7b2ec:      	br	x17

000000000007b2f0 <vlai_video_recognition_codec_set_start_time@plt>:
   7b2f0:      	adrp	x16, 0x83000
   7b2f4:      	ldr	x17, [x16, #0xdb0]
   7b2f8:      	add	x16, x16, #0xdb0
   7b2fc:      	br	x17

000000000007b300 <vlai_video_recognition_codec_set_duration_time@plt>:
   7b300:      	adrp	x16, 0x83000
   7b304:      	ldr	x17, [x16, #0xdb8]
   7b308:      	add	x16, x16, #0xdb8
   7b30c:      	br	x17

000000000007b310 <vlai_video_recognition_codec_set_skip_frame@plt>:
   7b310:      	adrp	x16, 0x83000
   7b314:      	ldr	x17, [x16, #0xdc0]
   7b318:      	add	x16, x16, #0xdc0
   7b31c:      	br	x17

000000000007b320 <vlai_video_recognition_codec_set_scale@plt>:
   7b320:      	adrp	x16, 0x83000
   7b324:      	ldr	x17, [x16, #0xdc8]
   7b328:      	add	x16, x16, #0xdc8
   7b32c:      	br	x17

000000000007b330 <vlai_video_recognition_codec_set_enable_key_frame_only@plt>:
   7b330:      	adrp	x16, 0x83000
   7b334:      	ldr	x17, [x16, #0xdd0]
   7b338:      	add	x16, x16, #0xdd0
   7b33c:      	br	x17

000000000007b340 <vlai_video_recognition_codec_init@plt>:
   7b340:      	adrp	x16, 0x83000
   7b344:      	ldr	x17, [x16, #0xdd8]
   7b348:      	add	x16, x16, #0xdd8
   7b34c:      	br	x17

000000000007b350 <vlai_video_recognition_codec_get_key_frame_number@plt>:
   7b350:      	adrp	x16, 0x83000
   7b354:      	ldr	x17, [x16, #0xde0]
   7b358:      	add	x16, x16, #0xde0
   7b35c:      	br	x17

000000000007b360 <vlai_video_recognition_codec_run@plt>:
   7b360:      	adrp	x16, 0x83000
   7b364:      	ldr	x17, [x16, #0xde8]
   7b368:      	add	x16, x16, #0xde8
   7b36c:      	br	x17

000000000007b370 <vlai_video_recognition_codec_get_result@plt>:
   7b370:      	adrp	x16, 0x83000
   7b374:      	ldr	x17, [x16, #0xdf0]
   7b378:      	add	x16, x16, #0xdf0
   7b37c:      	br	x17

000000000007b380 <vldp_get_video_recognition_result_pointer_ref@plt>:
   7b380:      	adrp	x16, 0x83000
   7b384:      	ldr	x17, [x16, #0xdf8]
   7b388:      	add	x16, x16, #0xdf8
   7b38c:      	br	x17

000000000007b390 <vldp_get_video_recognition_result_recognition@plt>:
   7b390:      	adrp	x16, 0x83000
   7b394:      	ldr	x17, [x16, #0xe00]
   7b398:      	add	x16, x16, #0xe00
   7b39c:      	br	x17

000000000007b3a0 <vldp_get_video_recognition_array_pointer_size@plt>:
   7b3a0:      	adrp	x16, 0x83000
   7b3a4:      	ldr	x17, [x16, #0xe08]
   7b3a8:      	add	x16, x16, #0xe08
   7b3ac:      	br	x17

000000000007b3b0 <vldp_get_video_recognition_array_pointer_at@plt>:
   7b3b0:      	adrp	x16, 0x83000
   7b3b4:      	ldr	x17, [x16, #0xe10]
   7b3b8:      	add	x16, x16, #0xe10
   7b3bc:      	br	x17

000000000007b3c0 <vldp_get_video_recognition_start_frame@plt>:
   7b3c0:      	adrp	x16, 0x83000
   7b3c4:      	ldr	x17, [x16, #0xe18]
   7b3c8:      	add	x16, x16, #0xe18
   7b3cc:      	br	x17

000000000007b3d0 <vldp_get_video_recognition_end_frame@plt>:
   7b3d0:      	adrp	x16, 0x83000
   7b3d4:      	ldr	x17, [x16, #0xe20]
   7b3d8:      	add	x16, x16, #0xe20
   7b3dc:      	br	x17

000000000007b3e0 <vldp_get_video_recognition_embeding@plt>:
   7b3e0:      	adrp	x16, 0x83000
   7b3e4:      	ldr	x17, [x16, #0xe28]
   7b3e8:      	add	x16, x16, #0xe28
   7b3ec:      	br	x17

000000000007b3f0 <vldp_get_video_recognition_base_data_results@plt>:
   7b3f0:      	adrp	x16, 0x83000
   7b3f4:      	ldr	x17, [x16, #0xe30]
   7b3f8:      	add	x16, x16, #0xe30
   7b3fc:      	br	x17

000000000007b400 <vldp_get_video_recognition_data_array_pointer_size@plt>:
   7b400:      	adrp	x16, 0x83000
   7b404:      	ldr	x17, [x16, #0xe38]
   7b408:      	add	x16, x16, #0xe38
   7b40c:      	br	x17

000000000007b410 <vldp_get_video_recognition_data_array_pointer_at@plt>:
   7b410:      	adrp	x16, 0x83000
   7b414:      	ldr	x17, [x16, #0xe40]
   7b418:      	add	x16, x16, #0xe40
   7b41c:      	br	x17

000000000007b420 <vldp_get_video_recognition_data_category@plt>:
   7b420:      	adrp	x16, 0x83000
   7b424:      	ldr	x17, [x16, #0xe48]
   7b428:      	add	x16, x16, #0xe48
   7b42c:      	br	x17

000000000007b430 <vldp_get_video_recognition_data_score@plt>:
   7b430:      	adrp	x16, 0x83000
   7b434:      	ldr	x17, [x16, #0xe50]
   7b438:      	add	x16, x16, #0xe50
   7b43c:      	br	x17

000000000007b440 <vldp_get_video_recognition_data_count_time@plt>:
   7b440:      	adrp	x16, 0x83000
   7b444:      	ldr	x17, [x16, #0xe58]
   7b448:      	add	x16, x16, #0xe58
   7b44c:      	br	x17

000000000007b450 <_ZN17MMDetectionPlugin26AIVideoRecognitionResult_SC2ERKS0_@plt>:
   7b450:      	adrp	x16, 0x83000
   7b454:      	ldr	x17, [x16, #0xe60]
   7b458:      	add	x16, x16, #0xe60
   7b45c:      	br	x17

000000000007b460 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin26AIVideoRecognitionResult_SENS_9allocatorIS2_EEE21__push_back_slow_pathIRKS2_EEPS2_OT_@plt>:
   7b460:      	adrp	x16, 0x83000
   7b464:      	ldr	x17, [x16, #0xe68]
   7b468:      	add	x16, x16, #0xe68
   7b46c:      	br	x17

000000000007b470 <_ZN17MMDetectionPlugin26AIVideoRecognitionResult_SD2Ev@plt>:
   7b470:      	adrp	x16, 0x83000
   7b474:      	ldr	x17, [x16, #0xe70]
   7b478:      	add	x16, x16, #0xe70
   7b47c:      	br	x17

000000000007b480 <vlai_recognition_get_first_level@plt>:
   7b480:      	adrp	x16, 0x83000
   7b484:      	ldr	x17, [x16, #0xe78]
   7b488:      	add	x16, x16, #0xe78
   7b48c:      	br	x17

000000000007b490 <vlai_recognition_get_second_level@plt>:
   7b490:      	adrp	x16, 0x83000
   7b494:      	ldr	x17, [x16, #0xe80]
   7b498:      	add	x16, x16, #0xe80
   7b49c:      	br	x17

000000000007b4a0 <vlai_recognition_get_label@plt>:
   7b4a0:      	adrp	x16, 0x83000
   7b4a4:      	ldr	x17, [x16, #0xe88]
   7b4a8:      	add	x16, x16, #0xe88
   7b4ac:      	br	x17

000000000007b4b0 <vlai_video_recognition_codec_stop@plt>:
   7b4b0:      	adrp	x16, 0x83000
   7b4b4:      	ldr	x17, [x16, #0xe90]
   7b4b8:      	add	x16, x16, #0xe90
   7b4bc:      	br	x17

000000000007b4c0 <_ZN17MMDetectionPlugin10BaseModuleC2ER26vlai_engine_session_handleNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   7b4c0:      	adrp	x16, 0x83000
   7b4c4:      	ldr	x17, [x16, #0xe98]
   7b4c8:      	add	x16, x16, #0xe98
   7b4cc:      	br	x17

000000000007b4d0 <_ZN17MMDetectionPlugin10BaseModuleD2Ev@plt>:
   7b4d0:      	adrp	x16, 0x83000
   7b4d4:      	ldr	x17, [x16, #0xea0]
   7b4d8:      	add	x16, x16, #0xea0
   7b4dc:      	br	x17

000000000007b4e0 <_ZN5media3Ref7releaseEv@plt>:
   7b4e0:      	adrp	x16, 0x83000
   7b4e4:      	ldr	x17, [x16, #0xea8]
   7b4e8:      	add	x16, x16, #0xea8
   7b4ec:      	br	x17

000000000007b4f0 <_ZN17MMDetectionPlugin10BaseModule12getTimeStampEv@plt>:
   7b4f0:      	adrp	x16, 0x83000
   7b4f4:      	ldr	x17, [x16, #0xeb0]
   7b4f8:      	add	x16, x16, #0xeb0
   7b4fc:      	br	x17

000000000007b500 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
   7b500:      	adrp	x16, 0x83000
   7b504:      	ldr	x17, [x16, #0xeb8]
   7b508:      	add	x16, x16, #0xeb8
   7b50c:      	br	x17

000000000007b510 <_ZN17MMDetectionPlugin10BaseModule28ConvertToVldpFloatArrayArrayERKNSt6__ndk16vectorINS2_IfNS1_9allocatorIfEEEENS3_IS5_EEEE@plt>:
   7b510:      	adrp	x16, 0x83000
   7b514:      	ldr	x17, [x16, #0xec0]
   7b518:      	add	x16, x16, #0xec0
   7b51c:      	br	x17

000000000007b520 <vldp_create_float_array_pointer_array_pointer@plt>:
   7b520:      	adrp	x16, 0x83000
   7b524:      	ldr	x17, [x16, #0xec8]
   7b528:      	add	x16, x16, #0xec8
   7b52c:      	br	x17

000000000007b530 <vldp_set_float_array_pointer_array_pointer_at@plt>:
   7b530:      	adrp	x16, 0x83000
   7b534:      	ldr	x17, [x16, #0xed0]
   7b538:      	add	x16, x16, #0xed0
   7b53c:      	br	x17

000000000007b540 <_ZN17MMDetectionPlugin10BaseModule29ConvertToStdVectorVectorFloatE45vldp_float_array_pointer_array_pointer_handle@plt>:
   7b540:      	adrp	x16, 0x83000
   7b544:      	ldr	x17, [x16, #0xed8]
   7b548:      	add	x16, x16, #0xed8
   7b54c:      	br	x17

000000000007b550 <vldp_get_float_array_pointer_array_pointer_size@plt>:
   7b550:      	adrp	x16, 0x83000
   7b554:      	ldr	x17, [x16, #0xee0]
   7b558:      	add	x16, x16, #0xee0
   7b55c:      	br	x17

000000000007b560 <_ZNSt6__ndk16vectorINS0_IfNS_9allocatorIfEEEENS1_IS3_EEE24__emplace_back_slow_pathIJRPfS7_EEEPS3_DpOT_@plt>:
   7b560:      	adrp	x16, 0x83000
   7b564:      	ldr	x17, [x16, #0xee8]
   7b568:      	add	x16, x16, #0xee8
   7b56c:      	br	x17

000000000007b570 <vldp_get_float_array_pointer_array_pointer_at@plt>:
   7b570:      	adrp	x16, 0x83000
   7b574:      	ldr	x17, [x16, #0xef0]
   7b578:      	add	x16, x16, #0xef0
   7b57c:      	br	x17

000000000007b580 <vldp_create_int_array_pointer_array_pointer@plt>:
   7b580:      	adrp	x16, 0x83000
   7b584:      	ldr	x17, [x16, #0xef8]
   7b588:      	add	x16, x16, #0xef8
   7b58c:      	br	x17

000000000007b590 <vldp_create_int_array_pointer@plt>:
   7b590:      	adrp	x16, 0x83000
   7b594:      	ldr	x17, [x16, #0xf00]
   7b598:      	add	x16, x16, #0xf00
   7b59c:      	br	x17

000000000007b5a0 <vldp_get_int_array_pointer_ref@plt>:
   7b5a0:      	adrp	x16, 0x83000
   7b5a4:      	ldr	x17, [x16, #0xf08]
   7b5a8:      	add	x16, x16, #0xf08
   7b5ac:      	br	x17

000000000007b5b0 <vldp_set_int_array_pointer_array_pointer_at@plt>:
   7b5b0:      	adrp	x16, 0x83000
   7b5b4:      	ldr	x17, [x16, #0xf10]
   7b5b8:      	add	x16, x16, #0xf10
   7b5bc:      	br	x17

000000000007b5c0 <vldp_release_int_array_pointer@plt>:
   7b5c0:      	adrp	x16, 0x83000
   7b5c4:      	ldr	x17, [x16, #0xf18]
   7b5c8:      	add	x16, x16, #0xf18
   7b5cc:      	br	x17

000000000007b5d0 <_ZN17MMDetectionPlugin10BaseModule27ConvertToStdVectorVectorIntE43vldp_int_array_pointer_array_pointer_handle@plt>:
   7b5d0:      	adrp	x16, 0x83000
   7b5d4:      	ldr	x17, [x16, #0xf20]
   7b5d8:      	add	x16, x16, #0xf20
   7b5dc:      	br	x17

000000000007b5e0 <vldp_get_int_array_pointer_array_pointer_size@plt>:
   7b5e0:      	adrp	x16, 0x83000
   7b5e4:      	ldr	x17, [x16, #0xf28]
   7b5e8:      	add	x16, x16, #0xf28
   7b5ec:      	br	x17

000000000007b5f0 <_ZNSt6__ndk16vectorINS0_IiNS_9allocatorIiEEEENS1_IS3_EEE24__emplace_back_slow_pathIJRPiS7_EEEPS3_DpOT_@plt>:
   7b5f0:      	adrp	x16, 0x83000
   7b5f4:      	ldr	x17, [x16, #0xf30]
   7b5f8:      	add	x16, x16, #0xf30
   7b5fc:      	br	x17

000000000007b600 <vldp_get_int_array_pointer_array_pointer_at@plt>:
   7b600:      	adrp	x16, 0x83000
   7b604:      	ldr	x17, [x16, #0xf38]
   7b608:      	add	x16, x16, #0xf38
   7b60c:      	br	x17

000000000007b610 <vldp_get_int_array_pointer_size@plt>:
   7b610:      	adrp	x16, 0x83000
   7b614:      	ldr	x17, [x16, #0xf40]
   7b618:      	add	x16, x16, #0xf40
   7b61c:      	br	x17

000000000007b620 <_ZN5media3Ref6retainEv@plt>:
   7b620:      	adrp	x16, 0x83000
   7b624:      	ldr	x17, [x16, #0xf48]
   7b628:      	add	x16, x16, #0xf48
   7b62c:      	br	x17

000000000007b630 <_ZN17MMDetectionPlugin13vector_subsetERKNSt6__ndk16vectorIiNS0_9allocatorIiEEEES6_@plt>:
   7b630:      	adrp	x16, 0x83000
   7b634:      	ldr	x17, [x16, #0xf50]
   7b638:      	add	x16, x16, #0xf50
   7b63c:      	br	x17

000000000007b640 <_ZNSt6__ndk13setIiNS_4lessIiEENS_9allocatorIiEEEC2B8ne180000INS_11__wrap_iterIPKiEEEET_SB_RKS2_@plt>:
   7b640:      	adrp	x16, 0x83000
   7b644:      	ldr	x17, [x16, #0xf58]
   7b648:      	add	x16, x16, #0xf58
   7b64c:      	br	x17

000000000007b650 <_ZNSt6__ndk16__treeIiNS_4lessIiEENS_9allocatorIiEEE12__find_equalIiEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIiPNS_11__tree_nodeIiS8_EElEERPNS_15__tree_end_nodeISA_EESB_RKT_@plt>:
   7b650:      	adrp	x16, 0x83000
   7b654:      	ldr	x17, [x16, #0xf60]
   7b658:      	add	x16, x16, #0xf60
   7b65c:      	br	x17

000000000007b660 <wmemchr@plt>:
   7b660:      	adrp	x16, 0x83000
   7b664:      	ldr	x17, [x16, #0xf68]
   7b668:      	add	x16, x16, #0xf68
   7b66c:      	br	x17

000000000007b670 <_ZN17MMDetectionPlugin21setAiFaceDetectorModeENS_18_FaceDetectionModeER30vlai_face_setting_patch_handle@plt>:
   7b670:      	adrp	x16, 0x83000
   7b674:      	ldr	x17, [x16, #0xf70]
   7b678:      	add	x16, x16, #0xf70
   7b67c:      	br	x17

000000000007b680 <vlai_face_setting_patch_set_enable_fd@plt>:
   7b680:      	adrp	x16, 0x83000
   7b684:      	ldr	x17, [x16, #0xf78]
   7b688:      	add	x16, x16, #0xf78
   7b68c:      	br	x17

000000000007b690 <vlai_face_setting_patch_set_enable_fa@plt>:
   7b690:      	adrp	x16, 0x83000
   7b694:      	ldr	x17, [x16, #0xf80]
   7b698:      	add	x16, x16, #0xf80
   7b69c:      	br	x17

000000000007b6a0 <vlai_face_setting_patch_set_fa_quality@plt>:
   7b6a0:      	adrp	x16, 0x83000
   7b6a4:      	ldr	x17, [x16, #0xf88]
   7b6a8:      	add	x16, x16, #0xf88
   7b6ac:      	br	x17

000000000007b6b0 <vlai_face_setting_patch_set_fd_quality@plt>:
   7b6b0:      	adrp	x16, 0x83000
   7b6b4:      	ldr	x17, [x16, #0xf90]
   7b6b8:      	add	x16, x16, #0xf90
   7b6bc:      	br	x17

000000000007b6c0 <_ZN17MMDetectionPlugin23setAiFaceDetectorOptionENS_20_FaceDetectionSwitchER30vlai_face_setting_patch_handleR23vlai_require_set_handle@plt>:
   7b6c0:      	adrp	x16, 0x83000
   7b6c4:      	ldr	x17, [x16, #0xf98]
   7b6c8:      	add	x16, x16, #0xf98
   7b6cc:      	br	x17

000000000007b6d0 <vlai_face_setting_patch_set_enable_refine_contour@plt>:
   7b6d0:      	adrp	x16, 0x83000
   7b6d4:      	ldr	x17, [x16, #0xfa0]
   7b6d8:      	add	x16, x16, #0xfa0
   7b6dc:      	br	x17

000000000007b6e0 <vlai_face_setting_patch_set_enable_video_track_mode@plt>:
   7b6e0:      	adrp	x16, 0x83000
   7b6e4:      	ldr	x17, [x16, #0xfa8]
   7b6e8:      	add	x16, x16, #0xfa8
   7b6ec:      	br	x17

000000000007b6f0 <vlai_require_set_push@plt>:
   7b6f0:      	adrp	x16, 0x83000
   7b6f4:      	ldr	x17, [x16, #0xfb0]
   7b6f8:      	add	x16, x16, #0xfb0
   7b6fc:      	br	x17

000000000007b700 <vlai_face_setting_patch_set_enable_face_part@plt>:
   7b700:      	adrp	x16, 0x83000
   7b704:      	ldr	x17, [x16, #0xfb8]
   7b708:      	add	x16, x16, #0xfb8
   7b70c:      	br	x17

000000000007b710 <vlai_face_setting_patch_set_enable_refine_eye@plt>:
   7b710:      	adrp	x16, 0x83000
   7b714:      	ldr	x17, [x16, #0xfc0]
   7b718:      	add	x16, x16, #0xfc0
   7b71c:      	br	x17

000000000007b720 <vlai_face_setting_patch_set_enable_refine_mouth@plt>:
   7b720:      	adrp	x16, 0x83000
   7b724:      	ldr	x17, [x16, #0xfc8]
   7b728:      	add	x16, x16, #0xfc8
   7b72c:      	br	x17

000000000007b730 <vlai_face_setting_patch_set_face_3dfa_type@plt>:
   7b730:      	adrp	x16, 0x83000
   7b734:      	ldr	x17, [x16, #0xfd0]
   7b738:      	add	x16, x16, #0xfd0
   7b73c:      	br	x17

000000000007b740 <vlai_face_setting_patch_set_enable_refine_nose@plt>:
   7b740:      	adrp	x16, 0x83000
   7b744:      	ldr	x17, [x16, #0xfd8]
   7b748:      	add	x16, x16, #0xfd8
   7b74c:      	br	x17

000000000007b750 <_ZN17MMDetectionPlugin15setAiFaceOptionERKNS_20_FaceDetectionOptionER30vlai_face_setting_patch_handleR23vlai_require_set_handle@plt>:
   7b750:      	adrp	x16, 0x83000
   7b754:      	ldr	x17, [x16, #0xfe0]
   7b758:      	add	x16, x16, #0xfe0
   7b75c:      	br	x17

000000000007b760 <vlai_face_setting_patch_set_open_vino_thread_num@plt>:
   7b760:      	adrp	x16, 0x83000
   7b764:      	ldr	x17, [x16, #0xfe8]
   7b768:      	add	x16, x16, #0xfe8
   7b76c:      	br	x17

000000000007b770 <_ZN17MMDetectionPlugin21setFaceRuntimeSettingER32vlai_face_runtime_setting_handlePKNS_14DetectionFrameEPKNS_16_DetectionOptionE@plt>:
   7b770:      	adrp	x16, 0x83000
   7b774:      	ldr	x17, [x16, #0xff0]
   7b778:      	add	x16, x16, #0xff0
   7b77c:      	br	x17

000000000007b780 <vlai_face_runtime_setting_set_face_max_num@plt>:
   7b780:      	adrp	x16, 0x83000
   7b784:      	ldr	x17, [x16, #0xff8]
   7b788:      	add	x16, x16, #0xff8
   7b78c:      	br	x17

000000000007b790 <vlai_face_runtime_setting_set_enable_min_fr_norm@plt>:
   7b790:      	adrp	x16, 0x84000
   7b794:      	ldr	x17, [x16]
   7b798:      	add	x16, x16, #0x0
   7b79c:      	br	x17

000000000007b7a0 <vlai_face_runtime_setting_set_enable_pose_estimation@plt>:
   7b7a0:      	adrp	x16, 0x84000
   7b7a4:      	ldr	x17, [x16, #0x8]
   7b7a8:      	add	x16, x16, #0x8
   7b7ac:      	br	x17

000000000007b7b0 <vlai_face_runtime_setting_set_async_fd@plt>:
   7b7b0:      	adrp	x16, 0x84000
   7b7b4:      	ldr	x17, [x16, #0x10]
   7b7b8:      	add	x16, x16, #0x10
   7b7bc:      	br	x17

000000000007b7c0 <vlai_face_runtime_setting_set_async_fr@plt>:
   7b7c0:      	adrp	x16, 0x84000
   7b7c4:      	ldr	x17, [x16, #0x18]
   7b7c8:      	add	x16, x16, #0x18
   7b7cc:      	br	x17

000000000007b7d0 <vlai_face_runtime_setting_set_enable_visibility@plt>:
   7b7d0:      	adrp	x16, 0x84000
   7b7d4:      	ldr	x17, [x16, #0x20]
   7b7d8:      	add	x16, x16, #0x20
   7b7dc:      	br	x17

000000000007b7e0 <vlai_face_runtime_setting_set_minimal_face@plt>:
   7b7e0:      	adrp	x16, 0x84000
   7b7e4:      	ldr	x17, [x16, #0x28]
   7b7e8:      	add	x16, x16, #0x28
   7b7ec:      	br	x17

000000000007b7f0 <vlai_face_runtime_setting_set_fr_interval_frame@plt>:
   7b7f0:      	adrp	x16, 0x84000
   7b7f4:      	ldr	x17, [x16, #0x30]
   7b7f8:      	add	x16, x16, #0x30
   7b7fc:      	br	x17

000000000007b800 <vlai_face_runtime_setting_set_fd_interval_frame@plt>:
   7b800:      	adrp	x16, 0x84000
   7b804:      	ldr	x17, [x16, #0x38]
   7b808:      	add	x16, x16, #0x38
   7b80c:      	br	x17

000000000007b810 <vlai_face_runtime_setting_set_smooth_weight@plt>:
   7b810:      	adrp	x16, 0x84000
   7b814:      	ldr	x17, [x16, #0x40]
   7b818:      	add	x16, x16, #0x40
   7b81c:      	br	x17

000000000007b820 <vlai_face_runtime_setting_set_half_parsing@plt>:
   7b820:      	adrp	x16, 0x84000
   7b824:      	ldr	x17, [x16, #0x48]
   7b828:      	add	x16, x16, #0x48
   7b82c:      	br	x17

000000000007b830 <vlai_face_runtime_setting_set_fast_fdinterval@plt>:
   7b830:      	adrp	x16, 0x84000
   7b834:      	ldr	x17, [x16, #0x50]
   7b838:      	add	x16, x16, #0x50
   7b83c:      	br	x17

000000000007b840 <vlai_face_runtime_setting_set_fast_minimal_face@plt>:
   7b840:      	adrp	x16, 0x84000
   7b844:      	ldr	x17, [x16, #0x58]
   7b848:      	add	x16, x16, #0x58
   7b84c:      	br	x17

000000000007b850 <vlai_face_runtime_setting_set_parsing_smooth@plt>:
   7b850:      	adrp	x16, 0x84000
   7b854:      	ldr	x17, [x16, #0x60]
   7b858:      	add	x16, x16, #0x60
   7b85c:      	br	x17

000000000007b860 <vlai_face_runtime_setting_set_coef_generation@plt>:
   7b860:      	adrp	x16, 0x84000
   7b864:      	ldr	x17, [x16, #0x68]
   7b868:      	add	x16, x16, #0x68
   7b86c:      	br	x17

000000000007b870 <vlai_face_runtime_setting_set_enable_switch_refine_detect@plt>:
   7b870:      	adrp	x16, 0x84000
   7b874:      	ldr	x17, [x16, #0x70]
   7b878:      	add	x16, x16, #0x70
   7b87c:      	br	x17

000000000007b880 <vlai_face_runtime_setting_set_enable_force_track_loop@plt>:
   7b880:      	adrp	x16, 0x84000
   7b884:      	ldr	x17, [x16, #0x78]
   7b888:      	add	x16, x16, #0x78
   7b88c:      	br	x17

000000000007b890 <vlai_face_runtime_setting_set_quality_filter_mode@plt>:
   7b890:      	adrp	x16, 0x84000
   7b894:      	ldr	x17, [x16, #0x80]
   7b898:      	add	x16, x16, #0x80
   7b89c:      	br	x17

000000000007b8a0 <vlai_face_runtime_setting_set_min_fr_norm@plt>:
   7b8a0:      	adrp	x16, 0x84000
   7b8a4:      	ldr	x17, [x16, #0x88]
   7b8a8:      	add	x16, x16, #0x88
   7b8ac:      	br	x17

000000000007b8b0 <vlai_face_runtime_setting_set_kill_threshold@plt>:
   7b8b0:      	adrp	x16, 0x84000
   7b8b4:      	ldr	x17, [x16, #0x90]
   7b8b8:      	add	x16, x16, #0x90
   7b8bc:      	br	x17

000000000007b8c0 <vlai_face_runtime_setting_set_enable_fr_filter_reset@plt>:
   7b8c0:      	adrp	x16, 0x84000
   7b8c4:      	ldr	x17, [x16, #0x98]
   7b8c8:      	add	x16, x16, #0x98
   7b8cc:      	br	x17

000000000007b8d0 <vlai_face_runtime_setting_set_tracker_type@plt>:
   7b8d0:      	adrp	x16, 0x84000
   7b8d4:      	ldr	x17, [x16, #0xa0]
   7b8d8:      	add	x16, x16, #0xa0
   7b8dc:      	br	x17

000000000007b8e0 <vlai_face_fr_utils_destroy@plt>:
   7b8e0:      	adrp	x16, 0x84000
   7b8e4:      	ldr	x17, [x16, #0xa8]
   7b8e8:      	add	x16, x16, #0xa8
   7b8ec:      	br	x17

000000000007b8f0 <_ZN17MMDetectionPlugin9BlockData9ClearDataEv@plt>:
   7b8f0:      	adrp	x16, 0x84000
   7b8f4:      	ldr	x17, [x16, #0xb0]
   7b8f8:      	add	x16, x16, #0xb0
   7b8fc:      	br	x17

000000000007b900 <_ZN17MMDetectionPlugin10FaceModuleD1Ev@plt>:
   7b900:      	adrp	x16, 0x84000
   7b904:      	ldr	x17, [x16, #0xb8]
   7b908:      	add	x16, x16, #0xb8
   7b90c:      	br	x17

000000000007b910 <vlai_setting_patch_face_setting_patch@plt>:
   7b910:      	adrp	x16, 0x84000
   7b914:      	ldr	x17, [x16, #0xc0]
   7b918:      	add	x16, x16, #0xc0
   7b91c:      	br	x17

000000000007b920 <vlai_engine_session_preload_with_setting@plt>:
   7b920:      	adrp	x16, 0x84000
   7b924:      	ldr	x17, [x16, #0xc8]
   7b928:      	add	x16, x16, #0xc8
   7b92c:      	br	x17

000000000007b930 <vlai_runtime_setting_face_runtime_setting@plt>:
   7b930:      	adrp	x16, 0x84000
   7b934:      	ldr	x17, [x16, #0xd0]
   7b938:      	add	x16, x16, #0xd0
   7b93c:      	br	x17

000000000007b940 <vldp_get_data_protocol_face_result@plt>:
   7b940:      	adrp	x16, 0x84000
   7b944:      	ldr	x17, [x16, #0xd8]
   7b948:      	add	x16, x16, #0xd8
   7b94c:      	br	x17

000000000007b950 <vldp_get_face_result_pointer_ref@plt>:
   7b950:      	adrp	x16, 0x84000
   7b954:      	ldr	x17, [x16, #0xe0]
   7b958:      	add	x16, x16, #0xe0
   7b95c:      	br	x17

000000000007b960 <vldp_get_face_result_face_bodys@plt>:
   7b960:      	adrp	x16, 0x84000
   7b964:      	ldr	x17, [x16, #0xe8]
   7b968:      	add	x16, x16, #0xe8
   7b96c:      	br	x17

000000000007b970 <vldp_get_face_body_array_pointer_size@plt>:
   7b970:      	adrp	x16, 0x84000
   7b974:      	ldr	x17, [x16, #0xf0]
   7b978:      	add	x16, x16, #0xf0
   7b97c:      	br	x17

000000000007b980 <vldp_get_face_result_size@plt>:
   7b980:      	adrp	x16, 0x84000
   7b984:      	ldr	x17, [x16, #0xf8]
   7b988:      	add	x16, x16, #0xf8
   7b98c:      	br	x17

000000000007b990 <_ZN17MMDetectionPlugin19FaceDetectionResultC1Ejji@plt>:
   7b990:      	adrp	x16, 0x84000
   7b994:      	ldr	x17, [x16, #0x100]
   7b998:      	add	x16, x16, #0x100
   7b99c:      	br	x17

000000000007b9a0 <vldp_get_face_body_array_pointer_at@plt>:
   7b9a0:      	adrp	x16, 0x84000
   7b9a4:      	ldr	x17, [x16, #0x108]
   7b9a8:      	add	x16, x16, #0x108
   7b9ac:      	br	x17

000000000007b9b0 <_ZN17MMDetectionPlugin19FaceDetectionResult8FaceBodyC2ERKS1_@plt>:
   7b9b0:      	adrp	x16, 0x84000
   7b9b4:      	ldr	x17, [x16, #0x110]
   7b9b8:      	add	x16, x16, #0x110
   7b9bc:      	br	x17

000000000007b9c0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19FaceDetectionResult8FaceBodyENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7b9c0:      	adrp	x16, 0x84000
   7b9c4:      	ldr	x17, [x16, #0x118]
   7b9c8:      	add	x16, x16, #0x118
   7b9cc:      	br	x17

000000000007b9d0 <vldp_get_face_result_faces@plt>:
   7b9d0:      	adrp	x16, 0x84000
   7b9d4:      	ldr	x17, [x16, #0x120]
   7b9d8:      	add	x16, x16, #0x120
   7b9dc:      	br	x17

000000000007b9e0 <vldp_get_face_array_pointer_size@plt>:
   7b9e0:      	adrp	x16, 0x84000
   7b9e4:      	ldr	x17, [x16, #0x128]
   7b9e8:      	add	x16, x16, #0x128
   7b9ec:      	br	x17

000000000007b9f0 <vldp_get_face_result_left_eyes@plt>:
   7b9f0:      	adrp	x16, 0x84000
   7b9f4:      	ldr	x17, [x16, #0x130]
   7b9f8:      	add	x16, x16, #0x130
   7b9fc:      	br	x17

000000000007ba00 <vldp_get_face_result_right_eyes@plt>:
   7ba00:      	adrp	x16, 0x84000
   7ba04:      	ldr	x17, [x16, #0x138]
   7ba08:      	add	x16, x16, #0x138
   7ba0c:      	br	x17

000000000007ba10 <vldp_get_face_result_mouths@plt>:
   7ba10:      	adrp	x16, 0x84000
   7ba14:      	ldr	x17, [x16, #0x140]
   7ba18:      	add	x16, x16, #0x140
   7ba1c:      	br	x17

000000000007ba20 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19FaceDetectionResult4FaceENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7ba20:      	adrp	x16, 0x84000
   7ba24:      	ldr	x17, [x16, #0x148]
   7ba28:      	add	x16, x16, #0x148
   7ba2c:      	br	x17

000000000007ba30 <vldp_get_face_array_pointer_at@plt>:
   7ba30:      	adrp	x16, 0x84000
   7ba34:      	ldr	x17, [x16, #0x150]
   7ba38:      	add	x16, x16, #0x150
   7ba3c:      	br	x17

000000000007ba40 <_ZN17MMDetectionPlugin19FaceDetectionResult4FaceC2Ev@plt>:
   7ba40:      	adrp	x16, 0x84000
   7ba44:      	ldr	x17, [x16, #0x158]
   7ba48:      	add	x16, x16, #0x158
   7ba4c:      	br	x17

000000000007ba50 <_ZN17MMDetectionPlugin19FaceDetectionResult4FaceC2ERKS1_@plt>:
   7ba50:      	adrp	x16, 0x84000
   7ba54:      	ldr	x17, [x16, #0x160]
   7ba58:      	add	x16, x16, #0x160
   7ba5c:      	br	x17

000000000007ba60 <vldp_get_part_face_array_pointer_size@plt>:
   7ba60:      	adrp	x16, 0x84000
   7ba64:      	ldr	x17, [x16, #0x168]
   7ba68:      	add	x16, x16, #0x168
   7ba6c:      	br	x17

000000000007ba70 <vldp_get_part_face_array_pointer_at@plt>:
   7ba70:      	adrp	x16, 0x84000
   7ba74:      	ldr	x17, [x16, #0x170]
   7ba78:      	add	x16, x16, #0x170
   7ba7c:      	br	x17

000000000007ba80 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19FaceDetectionResult8PartFaceENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7ba80:      	adrp	x16, 0x84000
   7ba84:      	ldr	x17, [x16, #0x178]
   7ba88:      	add	x16, x16, #0x178
   7ba8c:      	br	x17

000000000007ba90 <_ZNSt6__ndk16vectorINS_10shared_ptrIN17MMDetectionPlugin15DetectionResultEEENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEPS4_OT_@plt>:
   7ba90:      	adrp	x16, 0x84000
   7ba94:      	ldr	x17, [x16, #0x180]
   7ba98:      	add	x16, x16, #0x180
   7ba9c:      	br	x17

000000000007baa0 <_ZN17MMDetectionPlugin10FaceModule21updateFaceRecognitionER31vldp_face_result_pointer_handleNSt6__ndk110shared_ptrINS_19FaceDetectionResultEEEbbPN5media5ImageEb@plt>:
   7baa0:      	adrp	x16, 0x84000
   7baa4:      	ldr	x17, [x16, #0x188]
   7baa8:      	add	x16, x16, #0x188
   7baac:      	br	x17

000000000007bab0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   7bab0:      	adrp	x16, 0x84000
   7bab4:      	ldr	x17, [x16, #0x190]
   7bab8:      	add	x16, x16, #0x190
   7babc:      	br	x17

000000000007bac0 <_ZN17MMDetectionPlugin19FaceDetectionResult8FaceBodyD2Ev@plt>:
   7bac0:      	adrp	x16, 0x84000
   7bac4:      	ldr	x17, [x16, #0x198]
   7bac8:      	add	x16, x16, #0x198
   7bacc:      	br	x17

000000000007bad0 <_ZN17MMDetectionPlugin19FaceDetectionResult10MTDL3DFaceC1Ev@plt>:
   7bad0:      	adrp	x16, 0x84000
   7bad4:      	ldr	x17, [x16, #0x1a0]
   7bad8:      	add	x16, x16, #0x1a0
   7badc:      	br	x17

000000000007bae0 <vldp_get_face_fr_data@plt>:
   7bae0:      	adrp	x16, 0x84000
   7bae4:      	ldr	x17, [x16, #0x1a8]
   7bae8:      	add	x16, x16, #0x1a8
   7baec:      	br	x17

000000000007baf0 <_ZNSt6__ndk16__treeINS_12__value_typeIiN17MMDetectionPlugin9BlockDataEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJNS_4pairIiS3_EEEEENSD_INS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_@plt>:
   7baf0:      	adrp	x16, 0x84000
   7baf4:      	ldr	x17, [x16, #0x1b0]
   7baf8:      	add	x16, x16, #0x1b0
   7bafc:      	br	x17

000000000007bb00 <_ZN17MMDetectionPlugin10FaceModule19createFaceDataImageEPvPN5media5ImageE@plt>:
   7bb00:      	adrp	x16, 0x84000
   7bb04:      	ldr	x17, [x16, #0x1b8]
   7bb08:      	add	x16, x16, #0x1b8
   7bb0c:      	br	x17

000000000007bb10 <_ZNK5media5Image17getColorPrimariesEv@plt>:
   7bb10:      	adrp	x16, 0x84000
   7bb14:      	ldr	x17, [x16, #0x1c0]
   7bb18:      	add	x16, x16, #0x1c0
   7bb1c:      	br	x17

000000000007bb20 <_ZNK5media5Image16getColorTransferEv@plt>:
   7bb20:      	adrp	x16, 0x84000
   7bb24:      	ldr	x17, [x16, #0x1c8]
   7bb28:      	add	x16, x16, #0x1c8
   7bb2c:      	br	x17

000000000007bb30 <_ZN5media16MTColorFunctions17convertColorSpaceEPNS_5ImageENS_16MTColorPrimariesENS_15MTColorTransferES3_S4_@plt>:
   7bb30:      	adrp	x16, 0x84000
   7bb34:      	ldr	x17, [x16, #0x1d0]
   7bb38:      	add	x16, x16, #0x1d0
   7bb3c:      	br	x17

000000000007bb40 <_ZNSt6__ndk16vectorIiNS_9allocatorIiEEE18__assign_with_sizeB8ne180000IPiS5_EEvT_T0_l@plt>:
   7bb40:      	adrp	x16, 0x84000
   7bb44:      	ldr	x17, [x16, #0x1d8]
   7bb48:      	add	x16, x16, #0x1d8
   7bb4c:      	br	x17

000000000007bb50 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin13OrgIdFlagDataENS_9allocatorIS2_EEE21__push_back_slow_pathIRKS2_EEPS2_OT_@plt>:
   7bb50:      	adrp	x16, 0x84000
   7bb54:      	ldr	x17, [x16, #0x1e0]
   7bb58:      	add	x16, x16, #0x1e0
   7bb5c:      	br	x17

000000000007bb60 <_ZNSt6__ndk16__treeINS_12__value_typeIiN17MMDetectionPlugin9BlockDataEEENS_19__map_value_compareIiS4_NS_4lessIiEELb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSG_IJEEEEEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_@plt>:
   7bb60:      	adrp	x16, 0x84000
   7bb64:      	ldr	x17, [x16, #0x1e8]
   7bb68:      	add	x16, x16, #0x1e8
   7bb6c:      	br	x17

000000000007bb70 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin9BlockDataENS_9allocatorIS2_EEE21__push_back_slow_pathIRKS2_EEPS2_OT_@plt>:
   7bb70:      	adrp	x16, 0x84000
   7bb74:      	ldr	x17, [x16, #0x1f0]
   7bb78:      	add	x16, x16, #0x1f0
   7bb7c:      	br	x17

000000000007bb80 <vlai_face_multiple_recognition_search@plt>:
   7bb80:      	adrp	x16, 0x84000
   7bb84:      	ldr	x17, [x16, #0x1f8]
   7bb88:      	add	x16, x16, #0x1f8
   7bb8c:      	br	x17

000000000007bb90 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19FaceDetectionResult4FaceENS_9allocatorIS3_EEE24__emplace_back_slow_pathIJRS3_EEEPS3_DpOT_@plt>:
   7bb90:      	adrp	x16, 0x84000
   7bb94:      	ldr	x17, [x16, #0x200]
   7bb98:      	add	x16, x16, #0x200
   7bb9c:      	br	x17

000000000007bba0 <vldp_release_float_array_pointer_array_pointer@plt>:
   7bba0:      	adrp	x16, 0x84000
   7bba4:      	ldr	x17, [x16, #0x208]
   7bba8:      	add	x16, x16, #0x208
   7bbac:      	br	x17

000000000007bbb0 <_ZNSt6__ndk14pairIiN17MMDetectionPlugin9BlockDataEED2Ev@plt>:
   7bbb0:      	adrp	x16, 0x84000
   7bbb4:      	ldr	x17, [x16, #0x210]
   7bbb8:      	add	x16, x16, #0x210
   7bbbc:      	br	x17

000000000007bbc0 <_ZNSt6__ndk14pairIKiN17MMDetectionPlugin9BlockDataEED2Ev@plt>:
   7bbc0:      	adrp	x16, 0x84000
   7bbc4:      	ldr	x17, [x16, #0x218]
   7bbc8:      	add	x16, x16, #0x218
   7bbcc:      	br	x17

000000000007bbd0 <_ZN17MMDetectionPlugin9BlockDataD2Ev@plt>:
   7bbd0:      	adrp	x16, 0x84000
   7bbd4:      	ldr	x17, [x16, #0x220]
   7bbd8:      	add	x16, x16, #0x220
   7bbdc:      	br	x17

000000000007bbe0 <_ZN17MMDetectionPlugin10FaceModule23updateCurrentFaceNameIdEv@plt>:
   7bbe0:      	adrp	x16, 0x84000
   7bbe4:      	ldr	x17, [x16, #0x228]
   7bbe8:      	add	x16, x16, #0x228
   7bbec:      	br	x17

000000000007bbf0 <_ZN5media16MTDetectionCache21getDetectionCachePathEv@plt>:
   7bbf0:      	adrp	x16, 0x84000
   7bbf4:      	ldr	x17, [x16, #0x230]
   7bbf8:      	add	x16, x16, #0x230
   7bbfc:      	br	x17

000000000007bc00 <_ZN17MMDetectionPlugin10FaceModule28updateFaceBodyPostProcessingEv@plt>:
   7bc00:      	adrp	x16, 0x84000
   7bc04:      	ldr	x17, [x16, #0x238]
   7bc08:      	add	x16, x16, #0x238
   7bc0c:      	br	x17

000000000007bc10 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   7bc10:      	adrp	x16, 0x84000
   7bc14:      	ldr	x17, [x16, #0x240]
   7bc18:      	add	x16, x16, #0x240
   7bc1c:      	br	x17

000000000007bc20 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   7bc20:      	adrp	x16, 0x84000
   7bc24:      	ldr	x17, [x16, #0x248]
   7bc28:      	add	x16, x16, #0x248
   7bc2c:      	br	x17

000000000007bc30 <_ZN5media16MTDetectionCache26writeFaceRecognitionToFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIN17MMDetectionPlugin19FaceDetectionResult4FaceENS5_ISD_EEEEb@plt>:
   7bc30:      	adrp	x16, 0x84000
   7bc34:      	ldr	x17, [x16, #0x250]
   7bc38:      	add	x16, x16, #0x250
   7bc3c:      	br	x17

000000000007bc40 <_ZN5media16MTDetectionCache15insertFaceImageERNSt6__ndk13mapIlPNS_5ImageENS1_4lessIlEENS1_9allocatorINS1_4pairIKlS4_EEEEEE@plt>:
   7bc40:      	adrp	x16, 0x84000
   7bc44:      	ldr	x17, [x16, #0x258]
   7bc48:      	add	x16, x16, #0x258
   7bc4c:      	br	x17

000000000007bc50 <_ZN17MMDetectionPlugin24DetectionRecognitionUtil11getInstanceEv@plt>:
   7bc50:      	adrp	x16, 0x84000
   7bc54:      	ldr	x17, [x16, #0x260]
   7bc58:      	add	x16, x16, #0x260
   7bc5c:      	br	x17

000000000007bc60 <_ZN17MMDetectionPlugin24DetectionRecognitionUtil10getFrCodesEv@plt>:
   7bc60:      	adrp	x16, 0x84000
   7bc64:      	ldr	x17, [x16, #0x268]
   7bc68:      	add	x16, x16, #0x268
   7bc6c:      	br	x17

000000000007bc70 <_ZNSt6__ndk16vectorIfNS_9allocatorIfEEE18__assign_with_sizeB8ne180000IPfS5_EEvT_T0_l@plt>:
   7bc70:      	adrp	x16, 0x84000
   7bc74:      	ldr	x17, [x16, #0x270]
   7bc78:      	add	x16, x16, #0x270
   7bc7c:      	br	x17

000000000007bc80 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19FaceDetectionResult17MTFaceRecognitionENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7bc80:      	adrp	x16, 0x84000
   7bc84:      	ldr	x17, [x16, #0x278]
   7bc88:      	add	x16, x16, #0x278
   7bc8c:      	br	x17

000000000007bc90 <_ZN5media16MTDetectionCache13lockCacheDataEv@plt>:
   7bc90:      	adrp	x16, 0x84000
   7bc94:      	ldr	x17, [x16, #0x280]
   7bc98:      	add	x16, x16, #0x280
   7bc9c:      	br	x17

000000000007bca0 <_ZN5media16MTDetectionCache18getFaceBodyResultsEv@plt>:
   7bca0:      	adrp	x16, 0x84000
   7bca4:      	ldr	x17, [x16, #0x288]
   7bca8:      	add	x16, x16, #0x288
   7bcac:      	br	x17

000000000007bcb0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_3mapIlNS_4pairINS_6vectorINS_10shared_ptrIN17MMDetectionPlugin19FaceDetectionResultEEENS5_ISE_EEEEiEENS_4lessIlEENS5_INS9_IKlSH_EEEEEEEENS_19__map_value_compareIS7_SO_NSI_IS7_EELb1EEENS5_ISO_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSY_IJEEEEEENS9_INS_15__tree_iteratorISO_PNS_11__tree_nodeISO_PvEElEEbEERKT_DpOT0_@plt>:
   7bcb0:      	adrp	x16, 0x84000
   7bcb4:      	ldr	x17, [x16, #0x290]
   7bcb8:      	add	x16, x16, #0x290
   7bcbc:      	br	x17

000000000007bcc0 <vldp_create_face_body_array_pointer_array_pointer@plt>:
   7bcc0:      	adrp	x16, 0x84000
   7bcc4:      	ldr	x17, [x16, #0x298]
   7bcc8:      	add	x16, x16, #0x298
   7bccc:      	br	x17

000000000007bcd0 <vldp_create_face_body_array_pointer@plt>:
   7bcd0:      	adrp	x16, 0x84000
   7bcd4:      	ldr	x17, [x16, #0x2a0]
   7bcd8:      	add	x16, x16, #0x2a0
   7bcdc:      	br	x17

000000000007bce0 <vldp_set_face_body_array_pointer_array_pointer_at@plt>:
   7bce0:      	adrp	x16, 0x84000
   7bce4:      	ldr	x17, [x16, #0x2a8]
   7bce8:      	add	x16, x16, #0x2a8
   7bcec:      	br	x17

000000000007bcf0 <vldp_release_face_body_array_pointer@plt>:
   7bcf0:      	adrp	x16, 0x84000
   7bcf4:      	ldr	x17, [x16, #0x2b0]
   7bcf8:      	add	x16, x16, #0x2b0
   7bcfc:      	br	x17

000000000007bd00 <vlai_face_update_face_body_process@plt>:
   7bd00:      	adrp	x16, 0x84000
   7bd04:      	ldr	x17, [x16, #0x2b8]
   7bd08:      	add	x16, x16, #0x2b8
   7bd0c:      	br	x17

000000000007bd10 <vldp_get_face_body_array_pointer_array_pointer_size@plt>:
   7bd10:      	adrp	x16, 0x84000
   7bd14:      	ldr	x17, [x16, #0x2c0]
   7bd18:      	add	x16, x16, #0x2c0
   7bd1c:      	br	x17

000000000007bd20 <vldp_get_face_body_array_pointer_array_pointer_at@plt>:
   7bd20:      	adrp	x16, 0x84000
   7bd24:      	ldr	x17, [x16, #0x2c8]
   7bd28:      	add	x16, x16, #0x2c8
   7bd2c:      	br	x17

000000000007bd30 <_ZN5media16MTDetectionCache23updateFaceBodyOrgIdDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_4pairINS1_6vectorINS1_10shared_ptrIN17MMDetectionPlugin19FaceDetectionResultEEENS5_ISF_EEEEiEEl@plt>:
   7bd30:      	adrp	x16, 0x84000
   7bd34:      	ldr	x17, [x16, #0x2d0]
   7bd38:      	add	x16, x16, #0x2d0
   7bd3c:      	br	x17

000000000007bd40 <vldp_release_face_body_array_pointer_array_pointer@plt>:
   7bd40:      	adrp	x16, 0x84000
   7bd44:      	ldr	x17, [x16, #0x2d8]
   7bd48:      	add	x16, x16, #0x2d8
   7bd4c:      	br	x17

000000000007bd50 <_ZN5media16MTDetectionCache15unlockCacheDataEv@plt>:
   7bd50:      	adrp	x16, 0x84000
   7bd54:      	ldr	x17, [x16, #0x2e0]
   7bd58:      	add	x16, x16, #0x2e0
   7bd5c:      	br	x17

000000000007bd60 <_ZN5media16MTDetectionCache14getFaceResultsEv@plt>:
   7bd60:      	adrp	x16, 0x84000
   7bd64:      	ldr	x17, [x16, #0x2e8]
   7bd68:      	add	x16, x16, #0x2e8
   7bd6c:      	br	x17

000000000007bd70 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_3mapIlNS_4pairINS_6vectorINS_10shared_ptrIN17MMDetectionPlugin19FaceDetectionResultEEENS5_ISE_EEEEiEENS_4lessIlEENS5_INS9_IKlSH_EEEEEEEENS_19__map_value_compareIS7_SO_NSI_IS7_EELb1EEENS5_ISO_EEE4findIS7_EENS_15__tree_iteratorISO_PNS_11__tree_nodeISO_PvEElEERKT_@plt>:
   7bd70:      	adrp	x16, 0x84000
   7bd74:      	ldr	x17, [x16, #0x2f0]
   7bd78:      	add	x16, x16, #0x2f0
   7bd7c:      	br	x17

000000000007bd80 <_ZN5media16MTDetectionCache18updateFaceNameDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_4pairINS1_6vectorINS1_10shared_ptrIN17MMDetectionPlugin19FaceDetectionResultEEENS5_ISF_EEEEiEEl@plt>:
   7bd80:      	adrp	x16, 0x84000
   7bd84:      	ldr	x17, [x16, #0x2f8]
   7bd88:      	add	x16, x16, #0x2f8
   7bd8c:      	br	x17

000000000007bd90 <_ZN5media16MTDetectionCache27writeFaceDataToPtsFileAsyncERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorINS1_10shared_ptrIN17MMDetectionPlugin19FaceDetectionResultEEENS5_ISE_EEEEl@plt>:
   7bd90:      	adrp	x16, 0x84000
   7bd94:      	ldr	x17, [x16, #0x300]
   7bd98:      	add	x16, x16, #0x300
   7bd9c:      	br	x17

000000000007bda0 <_ZN10verenderer22MTRenderCommandEncoder20createWithByteArraysERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   7bda0:      	adrp	x16, 0x84000
   7bda4:      	ldr	x17, [x16, #0x308]
   7bda8:      	add	x16, x16, #0x308
   7bdac:      	br	x17

000000000007bdb0 <_ZN10verenderer18MTTexture2DBackend30createColorAttachmentTexture2DEiiNS_11PixelFormatE@plt>:
   7bdb0:      	adrp	x16, 0x84000
   7bdb4:      	ldr	x17, [x16, #0x310]
   7bdb8:      	add	x16, x16, #0x310
   7bdbc:      	br	x17

000000000007bdc0 <_ZN5media19MTDetectionInstance14convertTextureEPN10verenderer16MTTextureBackendES3_PNS1_22MTRenderCommandEncoderEiii@plt>:
   7bdc0:      	adrp	x16, 0x84000
   7bdc4:      	ldr	x17, [x16, #0x318]
   7bdc8:      	add	x16, x16, #0x318
   7bdcc:      	br	x17

000000000007bdd0 <vldp_init_face_result_pointer_if_null@plt>:
   7bdd0:      	adrp	x16, 0x84000
   7bdd4:      	ldr	x17, [x16, #0x320]
   7bdd8:      	add	x16, x16, #0x320
   7bddc:      	br	x17

000000000007bde0 <vldp_create_face_array_pointer@plt>:
   7bde0:      	adrp	x16, 0x84000
   7bde4:      	ldr	x17, [x16, #0x328]
   7bde8:      	add	x16, x16, #0x328
   7bdec:      	br	x17

000000000007bdf0 <vldp_set_face_array_pointer_hold@plt>:
   7bdf0:      	adrp	x16, 0x84000
   7bdf4:      	ldr	x17, [x16, #0x330]
   7bdf8:      	add	x16, x16, #0x330
   7bdfc:      	br	x17

000000000007be00 <vldp_release_face_array_pointer@plt>:
   7be00:      	adrp	x16, 0x84000
   7be04:      	ldr	x17, [x16, #0x338]
   7be08:      	add	x16, x16, #0x338
   7be0c:      	br	x17

000000000007be10 <vldp_set_face_has_face_rect@plt>:
   7be10:      	adrp	x16, 0x84000
   7be14:      	ldr	x17, [x16, #0x340]
   7be18:      	add	x16, x16, #0x340
   7be1c:      	br	x17

000000000007be20 <vldp_set_face_face_rect@plt>:
   7be20:      	adrp	x16, 0x84000
   7be24:      	ldr	x17, [x16, #0x348]
   7be28:      	add	x16, x16, #0x348
   7be2c:      	br	x17

000000000007be30 <vldp_set_face_has_roll_angle@plt>:
   7be30:      	adrp	x16, 0x84000
   7be34:      	ldr	x17, [x16, #0x350]
   7be38:      	add	x16, x16, #0x350
   7be3c:      	br	x17

000000000007be40 <vldp_set_face_roll_angle@plt>:
   7be40:      	adrp	x16, 0x84000
   7be44:      	ldr	x17, [x16, #0x358]
   7be48:      	add	x16, x16, #0x358
   7be4c:      	br	x17

000000000007be50 <vldp_set_face_has_id@plt>:
   7be50:      	adrp	x16, 0x84000
   7be54:      	ldr	x17, [x16, #0x360]
   7be58:      	add	x16, x16, #0x360
   7be5c:      	br	x17

000000000007be60 <vldp_set_face_id@plt>:
   7be60:      	adrp	x16, 0x84000
   7be64:      	ldr	x17, [x16, #0x368]
   7be68:      	add	x16, x16, #0x368
   7be6c:      	br	x17

000000000007be70 <vldp_set_face_has_org_id@plt>:
   7be70:      	adrp	x16, 0x84000
   7be74:      	ldr	x17, [x16, #0x370]
   7be78:      	add	x16, x16, #0x370
   7be7c:      	br	x17

000000000007be80 <vldp_set_face_org_id@plt>:
   7be80:      	adrp	x16, 0x84000
   7be84:      	ldr	x17, [x16, #0x378]
   7be88:      	add	x16, x16, #0x378
   7be8c:      	br	x17

000000000007be90 <_ZN17MMDetectionPlugin20_FaceDetectionOptionC1Ev@plt>:
   7be90:      	adrp	x16, 0x84000
   7be94:      	ldr	x17, [x16, #0x380]
   7be98:      	add	x16, x16, #0x380
   7be9c:      	br	x17

000000000007bea0 <vlai_face_runtime_setting_set_face_normal_generation@plt>:
   7bea0:      	adrp	x16, 0x84000
   7bea4:      	ldr	x17, [x16, #0x388]
   7bea8:      	add	x16, x16, #0x388
   7beac:      	br	x17

000000000007beb0 <vlai_face_runtime_setting_set_vertice_normal_generation@plt>:
   7beb0:      	adrp	x16, 0x84000
   7beb4:      	ldr	x17, [x16, #0x390]
   7beb8:      	add	x16, x16, #0x390
   7bebc:      	br	x17

000000000007bec0 <vlai_face_runtime_setting_set_face_tangent_generation@plt>:
   7bec0:      	adrp	x16, 0x84000
   7bec4:      	ldr	x17, [x16, #0x398]
   7bec8:      	add	x16, x16, #0x398
   7becc:      	br	x17

000000000007bed0 <vlai_face_runtime_setting_set_vertice_tangent_generation@plt>:
   7bed0:      	adrp	x16, 0x84000
   7bed4:      	ldr	x17, [x16, #0x3a0]
   7bed8:      	add	x16, x16, #0x3a0
   7bedc:      	br	x17

000000000007bee0 <vlai_face_runtime_setting_set_mesh_generation@plt>:
   7bee0:      	adrp	x16, 0x84000
   7bee4:      	ldr	x17, [x16, #0x3a8]
   7bee8:      	add	x16, x16, #0x3a8
   7beec:      	br	x17

000000000007bef0 <vldp_set_face_has_pitch_angle@plt>:
   7bef0:      	adrp	x16, 0x84000
   7bef4:      	ldr	x17, [x16, #0x3b0]
   7bef8:      	add	x16, x16, #0x3b0
   7befc:      	br	x17

000000000007bf00 <vldp_set_face_pitch_angle@plt>:
   7bf00:      	adrp	x16, 0x84000
   7bf04:      	ldr	x17, [x16, #0x3b8]
   7bf08:      	add	x16, x16, #0x3b8
   7bf0c:      	br	x17

000000000007bf10 <vldp_set_face_has_yaw_angle@plt>:
   7bf10:      	adrp	x16, 0x84000
   7bf14:      	ldr	x17, [x16, #0x3c0]
   7bf18:      	add	x16, x16, #0x3c0
   7bf1c:      	br	x17

000000000007bf20 <vldp_set_face_yaw_angle@plt>:
   7bf20:      	adrp	x16, 0x84000
   7bf24:      	ldr	x17, [x16, #0x3c8]
   7bf28:      	add	x16, x16, #0x3c8
   7bf2c:      	br	x17

000000000007bf30 <vldp_set_face_has_score@plt>:
   7bf30:      	adrp	x16, 0x84000
   7bf34:      	ldr	x17, [x16, #0x3d0]
   7bf38:      	add	x16, x16, #0x3d0
   7bf3c:      	br	x17

000000000007bf40 <vldp_set_face_score@plt>:
   7bf40:      	adrp	x16, 0x84000
   7bf44:      	ldr	x17, [x16, #0x3d8]
   7bf48:      	add	x16, x16, #0x3d8
   7bf4c:      	br	x17

000000000007bf50 <vlai_face_fr_utils_create@plt>:
   7bf50:      	adrp	x16, 0x84000
   7bf54:      	ldr	x17, [x16, #0x3e0]
   7bf58:      	add	x16, x16, #0x3e0
   7bf5c:      	br	x17

000000000007bf60 <vlai_face_fr_utils_register_feature@plt>:
   7bf60:      	adrp	x16, 0x84000
   7bf64:      	ldr	x17, [x16, #0x3e8]
   7bf68:      	add	x16, x16, #0x3e8
   7bf6c:      	br	x17

000000000007bf70 <vldp_create_image_array_pointer@plt>:
   7bf70:      	adrp	x16, 0x84000
   7bf74:      	ldr	x17, [x16, #0x3f0]
   7bf78:      	add	x16, x16, #0x3f0
   7bf7c:      	br	x17

000000000007bf80 <vldp_create_point2f_array_pointer_array_pointer@plt>:
   7bf80:      	adrp	x16, 0x84000
   7bf84:      	ldr	x17, [x16, #0x3f8]
   7bf88:      	add	x16, x16, #0x3f8
   7bf8c:      	br	x17

000000000007bf90 <_Znam@plt>:
   7bf90:      	adrp	x16, 0x84000
   7bf94:      	ldr	x17, [x16, #0x400]
   7bf98:      	add	x16, x16, #0x400
   7bf9c:      	br	x17

000000000007bfa0 <vlai_face_fr_utils_get_data@plt>:
   7bfa0:      	adrp	x16, 0x84000
   7bfa4:      	ldr	x17, [x16, #0x408]
   7bfa8:      	add	x16, x16, #0x408
   7bfac:      	br	x17

000000000007bfb0 <vldp_set_point2f_array_pointer_array_pointer_at@plt>:
   7bfb0:      	adrp	x16, 0x84000
   7bfb4:      	ldr	x17, [x16, #0x410]
   7bfb8:      	add	x16, x16, #0x410
   7bfbc:      	br	x17

000000000007bfc0 <_ZN5media10PixelImageC1Ev@plt>:
   7bfc0:      	adrp	x16, 0x84000
   7bfc4:      	ldr	x17, [x16, #0x418]
   7bfc8:      	add	x16, x16, #0x418
   7bfcc:      	br	x17

000000000007bfd0 <_ZN5media16MTDetectionCache24convertImageToPixelImageERNS_10PixelImageEPNS_5ImageE@plt>:
   7bfd0:      	adrp	x16, 0x84000
   7bfd4:      	ldr	x17, [x16, #0x420]
   7bfd8:      	add	x16, x16, #0x420
   7bfdc:      	br	x17

000000000007bfe0 <_ZNK5media5Image7getExifEv@plt>:
   7bfe0:      	adrp	x16, 0x84000
   7bfe4:      	ldr	x17, [x16, #0x428]
   7bfe8:      	add	x16, x16, #0x428
   7bfec:      	br	x17

000000000007bff0 <vldp_set_image_array_pointer_at@plt>:
   7bff0:      	adrp	x16, 0x84000
   7bff4:      	ldr	x17, [x16, #0x430]
   7bff8:      	add	x16, x16, #0x430
   7bffc:      	br	x17

000000000007c000 <_ZN5media10PixelImageD1Ev@plt>:
   7c000:      	adrp	x16, 0x84000
   7c004:      	ldr	x17, [x16, #0x438]
   7c008:      	add	x16, x16, #0x438
   7c00c:      	br	x17

000000000007c010 <vldp_release_image_array_pointer@plt>:
   7c010:      	adrp	x16, 0x84000
   7c014:      	ldr	x17, [x16, #0x440]
   7c018:      	add	x16, x16, #0x440
   7c01c:      	br	x17

000000000007c020 <vldp_release_point2f_array_pointer_array_pointer@plt>:
   7c020:      	adrp	x16, 0x84000
   7c024:      	ldr	x17, [x16, #0x448]
   7c028:      	add	x16, x16, #0x448
   7c02c:      	br	x17

000000000007c030 <_ZN5media5Files16removeItemAtPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7c030:      	adrp	x16, 0x84000
   7c034:      	ldr	x17, [x16, #0x450]
   7c038:      	add	x16, x16, #0x450
   7c03c:      	br	x17

000000000007c040 <vlai_face_recognition_search@plt>:
   7c040:      	adrp	x16, 0x84000
   7c044:      	ldr	x17, [x16, #0x458]
   7c048:      	add	x16, x16, #0x458
   7c04c:      	br	x17

000000000007c050 <_ZN5media5Image21covert8BitIfNecessaryEPS0_i@plt>:
   7c050:      	adrp	x16, 0x84000
   7c054:      	ldr	x17, [x16, #0x460]
   7c058:      	add	x16, x16, #0x460
   7c05c:      	br	x17

000000000007c060 <_ZNK5media5Image10getDataLenEv@plt>:
   7c060:      	adrp	x16, 0x84000
   7c064:      	ldr	x17, [x16, #0x468]
   7c068:      	add	x16, x16, #0x468
   7c06c:      	br	x17

000000000007c070 <_ZNK5media5Image8getWidthEv@plt>:
   7c070:      	adrp	x16, 0x84000
   7c074:      	ldr	x17, [x16, #0x470]
   7c078:      	add	x16, x16, #0x470
   7c07c:      	br	x17

000000000007c080 <_ZNK5media5Image9getHeightEv@plt>:
   7c080:      	adrp	x16, 0x84000
   7c084:      	ldr	x17, [x16, #0x478]
   7c088:      	add	x16, x16, #0x478
   7c08c:      	br	x17

000000000007c090 <_ZNK5media5Image13getComponentsEv@plt>:
   7c090:      	adrp	x16, 0x84000
   7c094:      	ldr	x17, [x16, #0x480]
   7c098:      	add	x16, x16, #0x480
   7c09c:      	br	x17

000000000007c0a0 <_ZNK5media5Image11getLineSizeEv@plt>:
   7c0a0:      	adrp	x16, 0x84000
   7c0a4:      	ldr	x17, [x16, #0x488]
   7c0a8:      	add	x16, x16, #0x488
   7c0ac:      	br	x17

000000000007c0b0 <_ZN5media5Image12correctImageEPKhliiiii@plt>:
   7c0b0:      	adrp	x16, 0x84000
   7c0b4:      	ldr	x17, [x16, #0x490]
   7c0b8:      	add	x16, x16, #0x490
   7c0bc:      	br	x17

000000000007c0c0 <_ZN5media4RectC1Effff@plt>:
   7c0c0:      	adrp	x16, 0x84000
   7c0c4:      	ldr	x17, [x16, #0x498]
   7c0c8:      	add	x16, x16, #0x498
   7c0cc:      	br	x17

000000000007c0d0 <_ZNK5media5Image9getFormatEv@plt>:
   7c0d0:      	adrp	x16, 0x84000
   7c0d4:      	ldr	x17, [x16, #0x4a0]
   7c0d8:      	add	x16, x16, #0x4a0
   7c0dc:      	br	x17

000000000007c0e0 <_ZN5media5Image12cutBGRAImageEPKhliiiiRKNS_4RectE@plt>:
   7c0e0:      	adrp	x16, 0x84000
   7c0e4:      	ldr	x17, [x16, #0x4a8]
   7c0e8:      	add	x16, x16, #0x4a8
   7c0ec:      	br	x17

000000000007c0f0 <_ZN5media5Image8cutImageEPKhliiiiRKNS_4RectE@plt>:
   7c0f0:      	adrp	x16, 0x84000
   7c0f4:      	ldr	x17, [x16, #0x4b0]
   7c0f8:      	add	x16, x16, #0x4b0
   7c0fc:      	br	x17

000000000007c100 <_ZN5media5Image13setColorSpaceENS_16MTColorPrimariesENS_15MTColorTransferE@plt>:
   7c100:      	adrp	x16, 0x84000
   7c104:      	ldr	x17, [x16, #0x4b8]
   7c108:      	add	x16, x16, #0x4b8
   7c10c:      	br	x17

000000000007c110 <_ZN17MMDetectionPlugin16getCompressScaleEii@plt>:
   7c110:      	adrp	x16, 0x84000
   7c114:      	ldr	x17, [x16, #0x4c0]
   7c118:      	add	x16, x16, #0x4c0
   7c11c:      	br	x17

000000000007c120 <_ZN5media5Image14yuvRGB24ToARGBEPKhiPhiii@plt>:
   7c120:      	adrp	x16, 0x84000
   7c124:      	ldr	x17, [x16, #0x4c8]
   7c128:      	add	x16, x16, #0x4c8
   7c12c:      	br	x17

000000000007c130 <_ZN5media5Image14scaleARGBImageEPKhiiiPhiii@plt>:
   7c130:      	adrp	x16, 0x84000
   7c134:      	ldr	x17, [x16, #0x4d0]
   7c138:      	add	x16, x16, #0x4d0
   7c13c:      	br	x17

000000000007c140 <_ZN5media5ImageC1Ev@plt>:
   7c140:      	adrp	x16, 0x84000
   7c144:      	ldr	x17, [x16, #0x4d8]
   7c148:      	add	x16, x16, #0x4d8
   7c14c:      	br	x17

000000000007c150 <_ZN17MMDetectionPlugin19FaceDetectionResultD1Ev@plt>:
   7c150:      	adrp	x16, 0x84000
   7c154:      	ldr	x17, [x16, #0x4e0]
   7c158:      	add	x16, x16, #0x4e0
   7c15c:      	br	x17

000000000007c160 <_ZNSt6__ndk13mapIibNS_4lessIiEENS_9allocatorINS_4pairIKibEEEEE6insertB8ne180000INS_20__map_const_iteratorINS_21__tree_const_iteratorINS_12__value_typeIibEEPNS_11__tree_nodeISD_PvEElEEEEEEvT_SK_@plt>:
   7c160:      	adrp	x16, 0x84000
   7c164:      	ldr	x17, [x16, #0x4e8]
   7c168:      	add	x16, x16, #0x4e8
   7c16c:      	br	x17

000000000007c170 <_ZNSt6__ndk13mapIifNS_4lessIiEENS_9allocatorINS_4pairIKifEEEEE6insertB8ne180000INS_20__map_const_iteratorINS_21__tree_const_iteratorINS_12__value_typeIifEEPNS_11__tree_nodeISD_PvEElEEEEEEvT_SK_@plt>:
   7c170:      	adrp	x16, 0x84000
   7c174:      	ldr	x17, [x16, #0x4f0]
   7c178:      	add	x16, x16, #0x4f0
   7c17c:      	br	x17

000000000007c180 <_ZN17MMDetectionPlugin19FaceDetectionResult10MTDL3DFaceC1ERKS1_@plt>:
   7c180:      	adrp	x16, 0x84000
   7c184:      	ldr	x17, [x16, #0x4f8]
   7c188:      	add	x16, x16, #0x4f8
   7c18c:      	br	x17

000000000007c190 <_ZNSt6__ndk16__treeINS_12__value_typeIibEENS_19__map_value_compareIiS2_NS_4lessIiEELb1EEENS_9allocatorIS2_EEE12__find_equalIiEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS2_PNS_11__tree_nodeIS2_SC_EElEERPNS_15__tree_end_nodeISE_EESF_RKT_@plt>:
   7c190:      	adrp	x16, 0x84000
   7c194:      	ldr	x17, [x16, #0x500]
   7c198:      	add	x16, x16, #0x500
   7c19c:      	br	x17

000000000007c1a0 <_ZNSt6__ndk16__treeINS_12__value_typeIifEENS_19__map_value_compareIiS2_NS_4lessIiEELb1EEENS_9allocatorIS2_EEE12__find_equalIiEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS2_PNS_11__tree_nodeIS2_SC_EElEERPNS_15__tree_end_nodeISE_EESF_RKT_@plt>:
   7c1a0:      	adrp	x16, 0x84000
   7c1a4:      	ldr	x17, [x16, #0x508]
   7c1a8:      	add	x16, x16, #0x508
   7c1ac:      	br	x17

000000000007c1b0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_3mapIlNS_4pairINS_6vectorINS_10shared_ptrIN17MMDetectionPlugin19FaceDetectionResultEEENS5_ISE_EEEEiEENS_4lessIlEENS5_INS9_IKlSH_EEEEEEEENS_19__map_value_compareIS7_SO_NSI_IS7_EELb1EEENS5_ISO_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISY_EERKT_@plt>:
   7c1b0:      	adrp	x16, 0x84000
   7c1b4:      	ldr	x17, [x16, #0x510]
   7c1b8:      	add	x16, x16, #0x510
   7c1bc:      	br	x17

000000000007c1c0 <_ZN17MMDetectionPlugin27setAiMaterialTrackingConfigERKNS_20_MaterialTrackConfigER43vlai_material_tracking_setting_patch_handle@plt>:
   7c1c0:      	adrp	x16, 0x84000
   7c1c4:      	ldr	x17, [x16, #0x518]
   7c1c8:      	add	x16, x16, #0x518
   7c1cc:      	br	x17

000000000007c1d0 <vlai_material_tracking_setting_patch_set_score_size@plt>:
   7c1d0:      	adrp	x16, 0x84000
   7c1d4:      	ldr	x17, [x16, #0x520]
   7c1d8:      	add	x16, x16, #0x520
   7c1dc:      	br	x17

000000000007c1e0 <vlai_material_tracking_setting_patch_set_score_kill_box@plt>:
   7c1e0:      	adrp	x16, 0x84000
   7c1e4:      	ldr	x17, [x16, #0x528]
   7c1e8:      	add	x16, x16, #0x528
   7c1ec:      	br	x17

000000000007c1f0 <vlai_material_tracking_setting_patch_set_score_recover@plt>:
   7c1f0:      	adrp	x16, 0x84000
   7c1f4:      	ldr	x17, [x16, #0x530]
   7c1f8:      	add	x16, x16, #0x530
   7c1fc:      	br	x17

000000000007c200 <vlai_material_tracking_setting_patch_set_smooth_size@plt>:
   7c200:      	adrp	x16, 0x84000
   7c204:      	ldr	x17, [x16, #0x538]
   7c208:      	add	x16, x16, #0x538
   7c20c:      	br	x17

000000000007c210 <vlai_material_tracking_setting_patch_set_smooth_threshold_min@plt>:
   7c210:      	adrp	x16, 0x84000
   7c214:      	ldr	x17, [x16, #0x540]
   7c218:      	add	x16, x16, #0x540
   7c21c:      	br	x17

000000000007c220 <vlai_material_tracking_setting_patch_set_smooth_threshold_max@plt>:
   7c220:      	adrp	x16, 0x84000
   7c224:      	ldr	x17, [x16, #0x548]
   7c228:      	add	x16, x16, #0x548
   7c22c:      	br	x17

000000000007c230 <vlai_material_tracking_setting_patch_set_interval@plt>:
   7c230:      	adrp	x16, 0x84000
   7c234:      	ldr	x17, [x16, #0x550]
   7c238:      	add	x16, x16, #0x550
   7c23c:      	br	x17

000000000007c240 <vlai_material_tracking_setting_patch_set_box_orientation@plt>:
   7c240:      	adrp	x16, 0x84000
   7c244:      	ldr	x17, [x16, #0x558]
   7c248:      	add	x16, x16, #0x558
   7c24c:      	br	x17

000000000007c250 <vlai_material_tracking_setting_patch_set_object_box@plt>:
   7c250:      	adrp	x16, 0x84000
   7c254:      	ldr	x17, [x16, #0x560]
   7c258:      	add	x16, x16, #0x560
   7c25c:      	br	x17

000000000007c260 <vlai_material_tracking_setting_patch_set_scale_smooth_size@plt>:
   7c260:      	adrp	x16, 0x84000
   7c264:      	ldr	x17, [x16, #0x568]
   7c268:      	add	x16, x16, #0x568
   7c26c:      	br	x17

000000000007c270 <vlai_material_tracking_setting_patch_set_do_homography@plt>:
   7c270:      	adrp	x16, 0x84000
   7c274:      	ldr	x17, [x16, #0x570]
   7c278:      	add	x16, x16, #0x570
   7c27c:      	br	x17

000000000007c280 <_ZN17MMDetectionPlugin33setMaterialTrackingRuntimeSettingER45vlai_material_tracking_runtime_setting_handlePKNS_16_DetectionOptionE@plt>:
   7c280:      	adrp	x16, 0x84000
   7c284:      	ldr	x17, [x16, #0x578]
   7c288:      	add	x16, x16, #0x578
   7c28c:      	br	x17

000000000007c290 <vlai_material_tracking_runtime_setting_set_reset_flag@plt>:
   7c290:      	adrp	x16, 0x84000
   7c294:      	ldr	x17, [x16, #0x580]
   7c298:      	add	x16, x16, #0x580
   7c29c:      	br	x17

000000000007c2a0 <vlai_material_tracking_runtime_setting_set_score_size@plt>:
   7c2a0:      	adrp	x16, 0x84000
   7c2a4:      	ldr	x17, [x16, #0x588]
   7c2a8:      	add	x16, x16, #0x588
   7c2ac:      	br	x17

000000000007c2b0 <vlai_material_tracking_runtime_setting_set_score_kill_box@plt>:
   7c2b0:      	adrp	x16, 0x84000
   7c2b4:      	ldr	x17, [x16, #0x590]
   7c2b8:      	add	x16, x16, #0x590
   7c2bc:      	br	x17

000000000007c2c0 <vlai_material_tracking_runtime_setting_set_score_recover@plt>:
   7c2c0:      	adrp	x16, 0x84000
   7c2c4:      	ldr	x17, [x16, #0x598]
   7c2c8:      	add	x16, x16, #0x598
   7c2cc:      	br	x17

000000000007c2d0 <vlai_material_tracking_runtime_setting_set_smooth_size@plt>:
   7c2d0:      	adrp	x16, 0x84000
   7c2d4:      	ldr	x17, [x16, #0x5a0]
   7c2d8:      	add	x16, x16, #0x5a0
   7c2dc:      	br	x17

000000000007c2e0 <vlai_material_tracking_runtime_setting_set_smooth_threshold_min@plt>:
   7c2e0:      	adrp	x16, 0x84000
   7c2e4:      	ldr	x17, [x16, #0x5a8]
   7c2e8:      	add	x16, x16, #0x5a8
   7c2ec:      	br	x17

000000000007c2f0 <vlai_material_tracking_runtime_setting_set_smooth_threshold_max@plt>:
   7c2f0:      	adrp	x16, 0x84000
   7c2f4:      	ldr	x17, [x16, #0x5b0]
   7c2f8:      	add	x16, x16, #0x5b0
   7c2fc:      	br	x17

000000000007c300 <vlai_material_tracking_runtime_setting_set_interval@plt>:
   7c300:      	adrp	x16, 0x84000
   7c304:      	ldr	x17, [x16, #0x5b8]
   7c308:      	add	x16, x16, #0x5b8
   7c30c:      	br	x17

000000000007c310 <vlai_material_tracking_runtime_setting_set_box_orientation@plt>:
   7c310:      	adrp	x16, 0x84000
   7c314:      	ldr	x17, [x16, #0x5c0]
   7c318:      	add	x16, x16, #0x5c0
   7c31c:      	br	x17

000000000007c320 <vlai_material_tracking_runtime_setting_set_object_box@plt>:
   7c320:      	adrp	x16, 0x84000
   7c324:      	ldr	x17, [x16, #0x5c8]
   7c328:      	add	x16, x16, #0x5c8
   7c32c:      	br	x17

000000000007c330 <vlai_material_tracking_runtime_setting_set_scale_smooth_size@plt>:
   7c330:      	adrp	x16, 0x84000
   7c334:      	ldr	x17, [x16, #0x5d0]
   7c338:      	add	x16, x16, #0x5d0
   7c33c:      	br	x17

000000000007c340 <vlai_material_tracking_runtime_setting_set_do_homography@plt>:
   7c340:      	adrp	x16, 0x84000
   7c344:      	ldr	x17, [x16, #0x5d8]
   7c348:      	add	x16, x16, #0x5d8
   7c34c:      	br	x17

000000000007c350 <_ZN17MMDetectionPlugin22MaterialTrackingModuleD1Ev@plt>:
   7c350:      	adrp	x16, 0x84000
   7c354:      	ldr	x17, [x16, #0x5e0]
   7c358:      	add	x16, x16, #0x5e0
   7c35c:      	br	x17

000000000007c360 <vlai_setting_patch_material_tracking_setting_patch@plt>:
   7c360:      	adrp	x16, 0x84000
   7c364:      	ldr	x17, [x16, #0x5e8]
   7c368:      	add	x16, x16, #0x5e8
   7c36c:      	br	x17

000000000007c370 <vlai_runtime_setting_material_tracking_runtime_setting@plt>:
   7c370:      	adrp	x16, 0x84000
   7c374:      	ldr	x17, [x16, #0x5f0]
   7c378:      	add	x16, x16, #0x5f0
   7c37c:      	br	x17

000000000007c380 <vldp_get_data_protocol_material_tracking_result@plt>:
   7c380:      	adrp	x16, 0x84000
   7c384:      	ldr	x17, [x16, #0x5f8]
   7c388:      	add	x16, x16, #0x5f8
   7c38c:      	br	x17

000000000007c390 <vldp_get_material_tracking_result_pointer_ref@plt>:
   7c390:      	adrp	x16, 0x84000
   7c394:      	ldr	x17, [x16, #0x600]
   7c398:      	add	x16, x16, #0x600
   7c39c:      	br	x17

000000000007c3a0 <vldp_get_material_tracking_result_size@plt>:
   7c3a0:      	adrp	x16, 0x84000
   7c3a4:      	ldr	x17, [x16, #0x608]
   7c3a8:      	add	x16, x16, #0x608
   7c3ac:      	br	x17

000000000007c3b0 <vldp_get_material_tracking_result_features@plt>:
   7c3b0:      	adrp	x16, 0x84000
   7c3b4:      	ldr	x17, [x16, #0x610]
   7c3b8:      	add	x16, x16, #0x610
   7c3bc:      	br	x17

000000000007c3c0 <_ZN17MMDetectionPlugin19MaterialTrackResultC1Ev@plt>:
   7c3c0:      	adrp	x16, 0x84000
   7c3c4:      	ldr	x17, [x16, #0x618]
   7c3c8:      	add	x16, x16, #0x618
   7c3cc:      	br	x17

000000000007c3d0 <vldp_get_material_tracking_result_orientation@plt>:
   7c3d0:      	adrp	x16, 0x84000
   7c3d4:      	ldr	x17, [x16, #0x620]
   7c3d8:      	add	x16, x16, #0x620
   7c3dc:      	br	x17

000000000007c3e0 <vldp_get_material_tracking_feature_array_pointer_size@plt>:
   7c3e0:      	adrp	x16, 0x84000
   7c3e4:      	ldr	x17, [x16, #0x628]
   7c3e8:      	add	x16, x16, #0x628
   7c3ec:      	br	x17

000000000007c3f0 <vldp_get_material_tracking_feature_array_pointer_at@plt>:
   7c3f0:      	adrp	x16, 0x84000
   7c3f4:      	ldr	x17, [x16, #0x630]
   7c3f8:      	add	x16, x16, #0x630
   7c3fc:      	br	x17

000000000007c400 <vldp_get_material_tracking_feature_frames@plt>:
   7c400:      	adrp	x16, 0x84000
   7c404:      	ldr	x17, [x16, #0x638]
   7c408:      	add	x16, x16, #0x638
   7c40c:      	br	x17

000000000007c410 <vldp_get_material_tracking_feature_score@plt>:
   7c410:      	adrp	x16, 0x84000
   7c414:      	ldr	x17, [x16, #0x640]
   7c418:      	add	x16, x16, #0x640
   7c41c:      	br	x17

000000000007c420 <vldp_get_material_tracking_feature_loss@plt>:
   7c420:      	adrp	x16, 0x84000
   7c424:      	ldr	x17, [x16, #0x648]
   7c428:      	add	x16, x16, #0x648
   7c42c:      	br	x17

000000000007c430 <vldp_get_material_tracking_feature_object_rect@plt>:
   7c430:      	adrp	x16, 0x84000
   7c434:      	ldr	x17, [x16, #0x650]
   7c438:      	add	x16, x16, #0x650
   7c43c:      	br	x17

000000000007c440 <vldp_get_material_tracking_feature_fail_homography@plt>:
   7c440:      	adrp	x16, 0x84000
   7c444:      	ldr	x17, [x16, #0x658]
   7c448:      	add	x16, x16, #0x658
   7c44c:      	br	x17

000000000007c450 <vldp_get_material_tracking_feature_scale@plt>:
   7c450:      	adrp	x16, 0x84000
   7c454:      	ldr	x17, [x16, #0x660]
   7c458:      	add	x16, x16, #0x660
   7c45c:      	br	x17

000000000007c460 <vldp_get_material_tracking_feature_homography_matrix@plt>:
   7c460:      	adrp	x16, 0x84000
   7c464:      	ldr	x17, [x16, #0x668]
   7c468:      	add	x16, x16, #0x668
   7c46c:      	br	x17

000000000007c470 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin12MaterialInfoENS_9allocatorIS2_EEE21__push_back_slow_pathIS2_EEPS2_OT_@plt>:
   7c470:      	adrp	x16, 0x84000
   7c474:      	ldr	x17, [x16, #0x670]
   7c478:      	add	x16, x16, #0x670
   7c47c:      	br	x17

000000000007c480 <_ZN17MMDetectionPlugin18setAiMTSegmentModeERKNS_14_SegmentOptionER33vlai_segment_setting_patch_handle@plt>:
   7c480:      	adrp	x16, 0x84000
   7c484:      	ldr	x17, [x16, #0x678]
   7c488:      	add	x16, x16, #0x678
   7c48c:      	br	x17

000000000007c490 <vlai_segment_setting_patch_set_segment_device_mode_type@plt>:
   7c490:      	adrp	x16, 0x84000
   7c494:      	ldr	x17, [x16, #0x680]
   7c498:      	add	x16, x16, #0x680
   7c49c:      	br	x17

000000000007c4a0 <_ZN17MMDetectionPlugin22getAiSegmentEnableEnumENS_14_SegmentSwitchER33vlai_segment_setting_patch_handleR23vlai_require_set_handle@plt>:
   7c4a0:      	adrp	x16, 0x84000
   7c4a4:      	ldr	x17, [x16, #0x688]
   7c4a8:      	add	x16, x16, #0x688
   7c4ac:      	br	x17

000000000007c4b0 <vlai_segment_setting_patch_set_is_just_init@plt>:
   7c4b0:      	adrp	x16, 0x84000
   7c4b4:      	ldr	x17, [x16, #0x690]
   7c4b8:      	add	x16, x16, #0x690
   7c4bc:      	br	x17

000000000007c4c0 <vlai_segment_setting_patch_set_force_image_mode@plt>:
   7c4c0:      	adrp	x16, 0x84000
   7c4c4:      	ldr	x17, [x16, #0x698]
   7c4c8:      	add	x16, x16, #0x698
   7c4cc:      	br	x17

000000000007c4d0 <_ZN17MMDetectionPlugin24setSegmentRuntimeSettingER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionE@plt>:
   7c4d0:      	adrp	x16, 0x84000
   7c4d4:      	ldr	x17, [x16, #0x6a0]
   7c4d8:      	add	x16, x16, #0x6a0
   7c4dc:      	br	x17

000000000007c4e0 <vlai_segment_runtime_setting_set_merge_by_alpha@plt>:
   7c4e0:      	adrp	x16, 0x84000
   7c4e4:      	ldr	x17, [x16, #0x6a8]
   7c4e8:      	add	x16, x16, #0x6a8
   7c4ec:      	br	x17

000000000007c4f0 <vlai_segment_runtime_setting_set_enable_first_frame@plt>:
   7c4f0:      	adrp	x16, 0x84000
   7c4f4:      	ldr	x17, [x16, #0x6b0]
   7c4f8:      	add	x16, x16, #0x6b0
   7c4fc:      	br	x17

000000000007c500 <vlai_segment_runtime_setting_set_opt_flow@plt>:
   7c500:      	adrp	x16, 0x84000
   7c504:      	ldr	x17, [x16, #0x6b8]
   7c508:      	add	x16, x16, #0x6b8
   7c50c:      	br	x17

000000000007c510 <vlai_segment_runtime_setting_set_opt_flow_dis@plt>:
   7c510:      	adrp	x16, 0x84000
   7c514:      	ldr	x17, [x16, #0x6c0]
   7c518:      	add	x16, x16, #0x6c0
   7c51c:      	br	x17

000000000007c520 <vlai_segment_runtime_setting_set_rt_need_cpu_data@plt>:
   7c520:      	adrp	x16, 0x84000
   7c524:      	ldr	x17, [x16, #0x6c8]
   7c528:      	add	x16, x16, #0x6c8
   7c52c:      	br	x17

000000000007c530 <vlai_segment_runtime_setting_set_enable_space_depth_cache@plt>:
   7c530:      	adrp	x16, 0x84000
   7c534:      	ldr	x17, [x16, #0x6d0]
   7c538:      	add	x16, x16, #0x6d0
   7c53c:      	br	x17

000000000007c540 <vlai_segment_runtime_setting_set_is_process_multi_face@plt>:
   7c540:      	adrp	x16, 0x84000
   7c544:      	ldr	x17, [x16, #0x6d8]
   7c548:      	add	x16, x16, #0x6d8
   7c54c:      	br	x17

000000000007c550 <vlai_segment_runtime_setting_set_enable_face_crop@plt>:
   7c550:      	adrp	x16, 0x84000
   7c554:      	ldr	x17, [x16, #0x6e0]
   7c558:      	add	x16, x16, #0x6e0
   7c55c:      	br	x17

000000000007c560 <vlai_segment_runtime_setting_set_facial_accumulate_mask@plt>:
   7c560:      	adrp	x16, 0x84000
   7c564:      	ldr	x17, [x16, #0x6e8]
   7c568:      	add	x16, x16, #0x6e8
   7c56c:      	br	x17

000000000007c570 <_ZN17MMDetectionPlugin13SegmentModuleD1Ev@plt>:
   7c570:      	adrp	x16, 0x84000
   7c574:      	ldr	x17, [x16, #0x6f0]
   7c578:      	add	x16, x16, #0x6f0
   7c57c:      	br	x17

000000000007c580 <vlai_setting_patch_segment_setting_patch@plt>:
   7c580:      	adrp	x16, 0x84000
   7c584:      	ldr	x17, [x16, #0x6f8]
   7c588:      	add	x16, x16, #0x6f8
   7c58c:      	br	x17

000000000007c590 <vlai_runtime_setting_segment_runtime_setting@plt>:
   7c590:      	adrp	x16, 0x84000
   7c594:      	ldr	x17, [x16, #0x700]
   7c598:      	add	x16, x16, #0x700
   7c59c:      	br	x17

000000000007c5a0 <_ZN17MMDetectionPlugin13SegmentModule35setInteractiveSegmentRuntimeSettingER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionEPKNS_14DetectionFrameER23vlai_require_set_handleR24vlai_graphics_env_handle@plt>:
   7c5a0:      	adrp	x16, 0x84000
   7c5a4:      	ldr	x17, [x16, #0x708]
   7c5a8:      	add	x16, x16, #0x708
   7c5ac:      	br	x17

000000000007c5b0 <_ZN17MMDetectionPlugin13SegmentModule26setEverythingSegmentOptionER35vlai_segment_runtime_setting_handlePKNS_16_DetectionOptionEPKNS_14DetectionFrameE@plt>:
   7c5b0:      	adrp	x16, 0x84000
   7c5b4:      	ldr	x17, [x16, #0x710]
   7c5b8:      	add	x16, x16, #0x710
   7c5bc:      	br	x17

000000000007c5c0 <_ZN5media10ImageUtils6resizeEPKhiiPhiii@plt>:
   7c5c0:      	adrp	x16, 0x84000
   7c5c4:      	ldr	x17, [x16, #0x718]
   7c5c8:      	add	x16, x16, #0x718
   7c5cc:      	br	x17

000000000007c5d0 <vlai_segment_runtime_setting_set_interactive_pre_mask@plt>:
   7c5d0:      	adrp	x16, 0x84000
   7c5d4:      	ldr	x17, [x16, #0x720]
   7c5d8:      	add	x16, x16, #0x720
   7c5dc:      	br	x17

000000000007c5e0 <vlai_segment_runtime_setting_set_segmentation_pre_mask@plt>:
   7c5e0:      	adrp	x16, 0x84000
   7c5e4:      	ldr	x17, [x16, #0x728]
   7c5e8:      	add	x16, x16, #0x728
   7c5ec:      	br	x17

000000000007c5f0 <vlai_segment_runtime_setting_set_segmentation_points@plt>:
   7c5f0:      	adrp	x16, 0x84000
   7c5f4:      	ldr	x17, [x16, #0x730]
   7c5f8:      	add	x16, x16, #0x730
   7c5fc:      	br	x17

000000000007c600 <vldp_get_data_protocol_segment_result@plt>:
   7c600:      	adrp	x16, 0x84000
   7c604:      	ldr	x17, [x16, #0x738]
   7c608:      	add	x16, x16, #0x738
   7c60c:      	br	x17

000000000007c610 <vldp_get_segment_result_pointer_ref@plt>:
   7c610:      	adrp	x16, 0x84000
   7c614:      	ldr	x17, [x16, #0x740]
   7c618:      	add	x16, x16, #0x740
   7c61c:      	br	x17

000000000007c620 <_ZN17MMDetectionPlugin13SegmentResultC1Ev@plt>:
   7c620:      	adrp	x16, 0x84000
   7c624:      	ldr	x17, [x16, #0x748]
   7c628:      	add	x16, x16, #0x748
   7c62c:      	br	x17

000000000007c630 <vldp_get_segment_result_half_body_segment@plt>:
   7c630:      	adrp	x16, 0x84000
   7c634:      	ldr	x17, [x16, #0x750]
   7c638:      	add	x16, x16, #0x750
   7c63c:      	br	x17

000000000007c640 <vldp_get_segment_out_mask_image@plt>:
   7c640:      	adrp	x16, 0x84000
   7c644:      	ldr	x17, [x16, #0x758]
   7c648:      	add	x16, x16, #0x758
   7c64c:      	br	x17

000000000007c650 <vldp_image_valid@plt>:
   7c650:      	adrp	x16, 0x84000
   7c654:      	ldr	x17, [x16, #0x760]
   7c658:      	add	x16, x16, #0x760
   7c65c:      	br	x17

000000000007c660 <_ZN17MMDetectionPlugin13SegmentModule17pushSegmentResultERK17vldp_image_handleNS_14_SegmentSwitchERNSt6__ndk110shared_ptrINS_13SegmentResultEEERKNS5_12basic_stringIcNS5_11char_traitsIcEENS5_9allocatorIcEEEE@plt>:
   7c660:      	adrp	x16, 0x84000
   7c664:      	ldr	x17, [x16, #0x768]
   7c668:      	add	x16, x16, #0x768
   7c66c:      	br	x17

000000000007c670 <vldp_get_segment_out_texture@plt>:
   7c670:      	adrp	x16, 0x84000
   7c674:      	ldr	x17, [x16, #0x770]
   7c678:      	add	x16, x16, #0x770
   7c67c:      	br	x17

000000000007c680 <_ZN17MMDetectionPlugin13SegmentModule17pushSegmentResultERK19vldp_texture_handleiNS_14_SegmentSwitchERNSt6__ndk110shared_ptrINS_13SegmentResultEEE@plt>:
   7c680:      	adrp	x16, 0x84000
   7c684:      	ldr	x17, [x16, #0x778]
   7c688:      	add	x16, x16, #0x778
   7c68c:      	br	x17

000000000007c690 <vldp_get_segment_result_whole_body_segment@plt>:
   7c690:      	adrp	x16, 0x84000
   7c694:      	ldr	x17, [x16, #0x780]
   7c698:      	add	x16, x16, #0x780
   7c69c:      	br	x17

000000000007c6a0 <vldp_get_segment_result_hair_segment@plt>:
   7c6a0:      	adrp	x16, 0x84000
   7c6a4:      	ldr	x17, [x16, #0x788]
   7c6a8:      	add	x16, x16, #0x788
   7c6ac:      	br	x17

000000000007c6b0 <vldp_get_segment_result_skin_segment@plt>:
   7c6b0:      	adrp	x16, 0x84000
   7c6b4:      	ldr	x17, [x16, #0x790]
   7c6b8:      	add	x16, x16, #0x790
   7c6bc:      	br	x17

000000000007c6c0 <vldp_get_segment_result_sky_segment@plt>:
   7c6c0:      	adrp	x16, 0x84000
   7c6c4:      	ldr	x17, [x16, #0x798]
   7c6c8:      	add	x16, x16, #0x798
   7c6cc:      	br	x17

000000000007c6d0 <vldp_get_segment_result_cw_segment@plt>:
   7c6d0:      	adrp	x16, 0x84000
   7c6d4:      	ldr	x17, [x16, #0x7a0]
   7c6d8:      	add	x16, x16, #0x7a0
   7c6dc:      	br	x17

000000000007c6e0 <vldp_get_segment_result_facial_segments@plt>:
   7c6e0:      	adrp	x16, 0x84000
   7c6e4:      	ldr	x17, [x16, #0x7a8]
   7c6e8:      	add	x16, x16, #0x7a8
   7c6ec:      	br	x17

000000000007c6f0 <vldp_get_facial_segment_array_pointer_size@plt>:
   7c6f0:      	adrp	x16, 0x84000
   7c6f4:      	ldr	x17, [x16, #0x7b0]
   7c6f8:      	add	x16, x16, #0x7b0
   7c6fc:      	br	x17

000000000007c700 <vldp_get_facial_segment_array_pointer_at@plt>:
   7c700:      	adrp	x16, 0x84000
   7c704:      	ldr	x17, [x16, #0x7b8]
   7c708:      	add	x16, x16, #0x7b8
   7c70c:      	br	x17

000000000007c710 <vldp_get_facial_segment_facial_glasses_segment@plt>:
   7c710:      	adrp	x16, 0x84000
   7c714:      	ldr	x17, [x16, #0x7c0]
   7c718:      	add	x16, x16, #0x7c0
   7c71c:      	br	x17

000000000007c720 <vldp_get_segment_result_video_body_segment@plt>:
   7c720:      	adrp	x16, 0x84000
   7c724:      	ldr	x17, [x16, #0x7c8]
   7c728:      	add	x16, x16, #0x7c8
   7c72c:      	br	x17

000000000007c730 <vldp_get_segment_result_face_contour_segments@plt>:
   7c730:      	adrp	x16, 0x84000
   7c734:      	ldr	x17, [x16, #0x7d0]
   7c738:      	add	x16, x16, #0x7d0
   7c73c:      	br	x17

000000000007c740 <vldp_get_face_contour_segment_array_pointer_size@plt>:
   7c740:      	adrp	x16, 0x84000
   7c744:      	ldr	x17, [x16, #0x7d8]
   7c748:      	add	x16, x16, #0x7d8
   7c74c:      	br	x17

000000000007c750 <vldp_get_face_contour_segment_array_pointer_at@plt>:
   7c750:      	adrp	x16, 0x84000
   7c754:      	ldr	x17, [x16, #0x7e0]
   7c758:      	add	x16, x16, #0x7e0
   7c75c:      	br	x17

000000000007c760 <vldp_get_face_contour_segment_face_contour_skin_segment@plt>:
   7c760:      	adrp	x16, 0x84000
   7c764:      	ldr	x17, [x16, #0x7e8]
   7c768:      	add	x16, x16, #0x7e8
   7c76c:      	br	x17

000000000007c770 <vldp_get_face_contour_segment_face_contour_backgroud_segment@plt>:
   7c770:      	adrp	x16, 0x84000
   7c774:      	ldr	x17, [x16, #0x7f0]
   7c778:      	add	x16, x16, #0x7f0
   7c77c:      	br	x17

000000000007c780 <vldp_get_facial_segment_facial_background_segment@plt>:
   7c780:      	adrp	x16, 0x84000
   7c784:      	ldr	x17, [x16, #0x7f8]
   7c788:      	add	x16, x16, #0x7f8
   7c78c:      	br	x17

000000000007c790 <vldp_get_facial_segment_facial_face_skin_segment@plt>:
   7c790:      	adrp	x16, 0x84000
   7c794:      	ldr	x17, [x16, #0x800]
   7c798:      	add	x16, x16, #0x800
   7c79c:      	br	x17

000000000007c7a0 <vldp_get_facial_segment_facial_brow_segment@plt>:
   7c7a0:      	adrp	x16, 0x84000
   7c7a4:      	ldr	x17, [x16, #0x808]
   7c7a8:      	add	x16, x16, #0x808
   7c7ac:      	br	x17

000000000007c7b0 <vldp_get_facial_segment_facial_eye_segment@plt>:
   7c7b0:      	adrp	x16, 0x84000
   7c7b4:      	ldr	x17, [x16, #0x810]
   7c7b8:      	add	x16, x16, #0x810
   7c7bc:      	br	x17

000000000007c7c0 <vldp_get_facial_segment_facial_nose_segment@plt>:
   7c7c0:      	adrp	x16, 0x84000
   7c7c4:      	ldr	x17, [x16, #0x818]
   7c7c8:      	add	x16, x16, #0x818
   7c7cc:      	br	x17

000000000007c7d0 <vldp_get_facial_segment_facial_lip_segment@plt>:
   7c7d0:      	adrp	x16, 0x84000
   7c7d4:      	ldr	x17, [x16, #0x820]
   7c7d8:      	add	x16, x16, #0x820
   7c7dc:      	br	x17

000000000007c7e0 <vldp_get_facial_segment_facial_teeth_segment@plt>:
   7c7e0:      	adrp	x16, 0x84000
   7c7e4:      	ldr	x17, [x16, #0x828]
   7c7e8:      	add	x16, x16, #0x828
   7c7ec:      	br	x17

000000000007c7f0 <vldp_get_facial_segment_facial_pupilla_segment@plt>:
   7c7f0:      	adrp	x16, 0x84000
   7c7f4:      	ldr	x17, [x16, #0x830]
   7c7f8:      	add	x16, x16, #0x830
   7c7fc:      	br	x17

000000000007c800 <vldp_get_facial_segment_facial_beard_segment@plt>:
   7c800:      	adrp	x16, 0x84000
   7c804:      	ldr	x17, [x16, #0x838]
   7c808:      	add	x16, x16, #0x838
   7c80c:      	br	x17

000000000007c810 <vldp_get_segment_result_head_segments@plt>:
   7c810:      	adrp	x16, 0x84000
   7c814:      	ldr	x17, [x16, #0x840]
   7c818:      	add	x16, x16, #0x840
   7c81c:      	br	x17

000000000007c820 <vldp_get_segment_array_pointer_size@plt>:
   7c820:      	adrp	x16, 0x84000
   7c824:      	ldr	x17, [x16, #0x848]
   7c828:      	add	x16, x16, #0x848
   7c82c:      	br	x17

000000000007c830 <vldp_get_segment_array_pointer_at@plt>:
   7c830:      	adrp	x16, 0x84000
   7c834:      	ldr	x17, [x16, #0x850]
   7c838:      	add	x16, x16, #0x850
   7c83c:      	br	x17

000000000007c840 <vldp_get_segment_result_blur_portrait_segment@plt>:
   7c840:      	adrp	x16, 0x84000
   7c844:      	ldr	x17, [x16, #0x858]
   7c848:      	add	x16, x16, #0x858
   7c84c:      	br	x17

000000000007c850 <vldp_get_segment_result_cloth_segment@plt>:
   7c850:      	adrp	x16, 0x84000
   7c854:      	ldr	x17, [x16, #0x860]
   7c858:      	add	x16, x16, #0x860
   7c85c:      	br	x17

000000000007c860 <vldp_get_segment_result_video_skin_segment@plt>:
   7c860:      	adrp	x16, 0x84000
   7c864:      	ldr	x17, [x16, #0x868]
   7c868:      	add	x16, x16, #0x868
   7c86c:      	br	x17

000000000007c870 <vldp_get_segment_result_salient_object_detection_segment@plt>:
   7c870:      	adrp	x16, 0x84000
   7c874:      	ldr	x17, [x16, #0x870]
   7c878:      	add	x16, x16, #0x870
   7c87c:      	br	x17

000000000007c880 <vldp_get_segment_result_interactive_segment@plt>:
   7c880:      	adrp	x16, 0x84000
   7c884:      	ldr	x17, [x16, #0x878]
   7c888:      	add	x16, x16, #0x878
   7c88c:      	br	x17

000000000007c890 <vldp_get_segment_result_segmentation_segment@plt>:
   7c890:      	adrp	x16, 0x84000
   7c894:      	ldr	x17, [x16, #0x880]
   7c898:      	add	x16, x16, #0x880
   7c89c:      	br	x17

000000000007c8a0 <vldp_get_segment_result_space_depth_segment@plt>:
   7c8a0:      	adrp	x16, 0x84000
   7c8a4:      	ldr	x17, [x16, #0x888]
   7c8a8:      	add	x16, x16, #0x888
   7c8ac:      	br	x17

000000000007c8b0 <vldp_get_segment_result_space_depth_normal_segment@plt>:
   7c8b0:      	adrp	x16, 0x84000
   7c8b4:      	ldr	x17, [x16, #0x890]
   7c8b8:      	add	x16, x16, #0x890
   7c8bc:      	br	x17

000000000007c8c0 <_ZN5media5Image6createEv@plt>:
   7c8c0:      	adrp	x16, 0x84000
   7c8c4:      	ldr	x17, [x16, #0x898]
   7c8c8:      	add	x16, x16, #0x898
   7c8cc:      	br	x17

000000000007c8d0 <vldp_get_image_exif@plt>:
   7c8d0:      	adrp	x16, 0x84000
   7c8d4:      	ldr	x17, [x16, #0x8a0]
   7c8d8:      	add	x16, x16, #0x8a0
   7c8dc:      	br	x17

000000000007c8e0 <_ZN5media5Image7setExifEi@plt>:
   7c8e0:      	adrp	x16, 0x84000
   7c8e4:      	ldr	x17, [x16, #0x8a8]
   7c8e8:      	add	x16, x16, #0x8a8
   7c8ec:      	br	x17

000000000007c8f0 <_ZN17MMDetectionPlugin12SegmentBlockC1EPN5media5ImageENS_14_SegmentSwitchE@plt>:
   7c8f0:      	adrp	x16, 0x84000
   7c8f4:      	ldr	x17, [x16, #0x8b0]
   7c8f8:      	add	x16, x16, #0x8b0
   7c8fc:      	br	x17

000000000007c900 <_ZN17MMDetectionPlugin12SegmentBlock14setSegmentNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7c900:      	adrp	x16, 0x84000
   7c904:      	ldr	x17, [x16, #0x8b8]
   7c908:      	add	x16, x16, #0x8b8
   7c90c:      	br	x17

000000000007c910 <_ZN17MMDetectionPlugin12SegmentBlockC1ERKS0_@plt>:
   7c910:      	adrp	x16, 0x84000
   7c914:      	ldr	x17, [x16, #0x8c0]
   7c918:      	add	x16, x16, #0x8c0
   7c91c:      	br	x17

000000000007c920 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE12emplace_backIJRS2_EEEvDpOT_@plt>:
   7c920:      	adrp	x16, 0x84000
   7c924:      	ldr	x17, [x16, #0x8c8]
   7c928:      	add	x16, x16, #0x8c8
   7c92c:      	br	x17

000000000007c930 <_ZN5media5Image19convertDataToFormatEPKhlN10verenderer11PixelFormatES4_PPhPl@plt>:
   7c930:      	adrp	x16, 0x84000
   7c934:      	ldr	x17, [x16, #0x8d0]
   7c938:      	add	x16, x16, #0x8d0
   7c93c:      	br	x17

000000000007c940 <_ZN17MMDetectionPlugin12SegmentBlockD1Ev@plt>:
   7c940:      	adrp	x16, 0x84000
   7c944:      	ldr	x17, [x16, #0x8d8]
   7c948:      	add	x16, x16, #0x8d8
   7c94c:      	br	x17

000000000007c950 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin12SegmentBlockENS_9allocatorIS2_EEE24__emplace_back_slow_pathIJRS2_EEEPS2_DpOT_@plt>:
   7c950:      	adrp	x16, 0x84000
   7c954:      	ldr	x17, [x16, #0x8e0]
   7c958:      	add	x16, x16, #0x8e0
   7c95c:      	br	x17

000000000007c960 <vldp_get_texture_width@plt>:
   7c960:      	adrp	x16, 0x84000
   7c964:      	ldr	x17, [x16, #0x8e8]
   7c968:      	add	x16, x16, #0x8e8
   7c96c:      	br	x17

000000000007c970 <vldp_get_texture_height@plt>:
   7c970:      	adrp	x16, 0x84000
   7c974:      	ldr	x17, [x16, #0x8f0]
   7c978:      	add	x16, x16, #0x8f0
   7c97c:      	br	x17

000000000007c980 <vldp_get_texture_metal_handle@plt>:
   7c980:      	adrp	x16, 0x84000
   7c984:      	ldr	x17, [x16, #0x8f8]
   7c988:      	add	x16, x16, #0x8f8
   7c98c:      	br	x17

000000000007c990 <vldp_get_texture_opengl_handle@plt>:
   7c990:      	adrp	x16, 0x84000
   7c994:      	ldr	x17, [x16, #0x900]
   7c998:      	add	x16, x16, #0x900
   7c99c:      	br	x17

000000000007c9a0 <_ZN10verenderer18MTTexture2DBackend29createWithBackendTextureValueERKNS_15BackendTexValueE@plt>:
   7c9a0:      	adrp	x16, 0x84000
   7c9a4:      	ldr	x17, [x16, #0x908]
   7c9a8:      	add	x16, x16, #0x908
   7c9ac:      	br	x17

000000000007c9b0 <_ZN10verenderer3Ref7releaseEv@plt>:
   7c9b0:      	adrp	x16, 0x84000
   7c9b4:      	ldr	x17, [x16, #0x910]
   7c9b8:      	add	x16, x16, #0x910
   7c9bc:      	br	x17

000000000007c9c0 <_ZN17MMDetectionPlugin13SegmentResultD1Ev@plt>:
   7c9c0:      	adrp	x16, 0x84000
   7c9c4:      	ldr	x17, [x16, #0x918]
   7c9c8:      	add	x16, x16, #0x918
   7c9cc:      	br	x17

000000000007c9d0 <vlai_body_setting_patch_set_detect_per_frame@plt>:
   7c9d0:      	adrp	x16, 0x84000
   7c9d4:      	ldr	x17, [x16, #0x920]
   7c9d8:      	add	x16, x16, #0x920
   7c9dc:      	br	x17

000000000007c9e0 <vlai_body_runtime_setting_set_contour_threshold_bound_score@plt>:
   7c9e0:      	adrp	x16, 0x84000
   7c9e4:      	ldr	x17, [x16, #0x928]
   7c9e8:      	add	x16, x16, #0x928
   7c9ec:      	br	x17

000000000007c9f0 <vlai_body_runtime_setting_set_contour_threshold_points_score@plt>:
   7c9f0:      	adrp	x16, 0x84000
   7c9f4:      	ldr	x17, [x16, #0x930]
   7c9f8:      	add	x16, x16, #0x930
   7c9fc:      	br	x17

000000000007ca00 <vlai_body_runtime_setting_set_contour_threshold_points_num@plt>:
   7ca00:      	adrp	x16, 0x84000
   7ca04:      	ldr	x17, [x16, #0x938]
   7ca08:      	add	x16, x16, #0x938
   7ca0c:      	br	x17

000000000007ca10 <_ZN17MMDetectionPlugin10BodyModuleD1Ev@plt>:
   7ca10:      	adrp	x16, 0x84000
   7ca14:      	ldr	x17, [x16, #0x940]
   7ca18:      	add	x16, x16, #0x940
   7ca1c:      	br	x17

000000000007ca20 <vlai_setting_patch_body_setting_patch@plt>:
   7ca20:      	adrp	x16, 0x84000
   7ca24:      	ldr	x17, [x16, #0x948]
   7ca28:      	add	x16, x16, #0x948
   7ca2c:      	br	x17

000000000007ca30 <vlai_runtime_setting_body_runtime_setting@plt>:
   7ca30:      	adrp	x16, 0x84000
   7ca34:      	ldr	x17, [x16, #0x950]
   7ca38:      	add	x16, x16, #0x950
   7ca3c:      	br	x17

000000000007ca40 <vldp_get_data_protocol_body_result@plt>:
   7ca40:      	adrp	x16, 0x84000
   7ca44:      	ldr	x17, [x16, #0x958]
   7ca48:      	add	x16, x16, #0x958
   7ca4c:      	br	x17

000000000007ca50 <vldp_get_body_result_pointer_ref@plt>:
   7ca50:      	adrp	x16, 0x84000
   7ca54:      	ldr	x17, [x16, #0x960]
   7ca58:      	add	x16, x16, #0x960
   7ca5c:      	br	x17

000000000007ca60 <_ZN17MMDetectionPlugin19BodyDetectionResultC1Ev@plt>:
   7ca60:      	adrp	x16, 0x84000
   7ca64:      	ldr	x17, [x16, #0x968]
   7ca68:      	add	x16, x16, #0x968
   7ca6c:      	br	x17

000000000007ca70 <vldp_get_body_result_is_multy@plt>:
   7ca70:      	adrp	x16, 0x84000
   7ca74:      	ldr	x17, [x16, #0x970]
   7ca78:      	add	x16, x16, #0x970
   7ca7c:      	br	x17

000000000007ca80 <vldp_get_body_result_pose_bodys@plt>:
   7ca80:      	adrp	x16, 0x84000
   7ca84:      	ldr	x17, [x16, #0x978]
   7ca88:      	add	x16, x16, #0x978
   7ca8c:      	br	x17

000000000007ca90 <vldp_get_body_result_contour_bodys@plt>:
   7ca90:      	adrp	x16, 0x84000
   7ca94:      	ldr	x17, [x16, #0x980]
   7ca98:      	add	x16, x16, #0x980
   7ca9c:      	br	x17

000000000007caa0 <vldp_get_body_result_human_bodys@plt>:
   7caa0:      	adrp	x16, 0x84000
   7caa4:      	ldr	x17, [x16, #0x988]
   7caa8:      	add	x16, x16, #0x988
   7caac:      	br	x17

000000000007cab0 <vldp_get_body_array_pointer_size@plt>:
   7cab0:      	adrp	x16, 0x84000
   7cab4:      	ldr	x17, [x16, #0x990]
   7cab8:      	add	x16, x16, #0x990
   7cabc:      	br	x17

000000000007cac0 <vldp_get_body_array_pointer_at@plt>:
   7cac0:      	adrp	x16, 0x84000
   7cac4:      	ldr	x17, [x16, #0x998]
   7cac8:      	add	x16, x16, #0x998
   7cacc:      	br	x17

000000000007cad0 <_ZN17MMDetectionPlugin19BodyDetectionResult8BodyInfoC2ERKS1_@plt>:
   7cad0:      	adrp	x16, 0x84000
   7cad4:      	ldr	x17, [x16, #0x9a0]
   7cad8:      	add	x16, x16, #0x9a0
   7cadc:      	br	x17

000000000007cae0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19BodyDetectionResult8BodyInfoENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7cae0:      	adrp	x16, 0x84000
   7cae4:      	ldr	x17, [x16, #0x9a8]
   7cae8:      	add	x16, x16, #0x9a8
   7caec:      	br	x17

000000000007caf0 <_ZN17MMDetectionPlugin19BodyDetectionResult8BodyInfoD2Ev@plt>:
   7caf0:      	adrp	x16, 0x84000
   7caf4:      	ldr	x17, [x16, #0x9b0]
   7caf8:      	add	x16, x16, #0x9b0
   7cafc:      	br	x17

000000000007cb00 <_ZN17MMDetectionPlugin21setDL3DRuntimeSettingER34vlai_face3d_runtime_setting_handlePKNS_16_DetectionOptionE@plt>:
   7cb00:      	adrp	x16, 0x84000
   7cb04:      	ldr	x17, [x16, #0x9b8]
   7cb08:      	add	x16, x16, #0x9b8
   7cb0c:      	br	x17

000000000007cb10 <vlai_face3d_runtime_setting_set_dl3d_speed@plt>:
   7cb10:      	adrp	x16, 0x84000
   7cb14:      	ldr	x17, [x16, #0x9c0]
   7cb18:      	add	x16, x16, #0x9c0
   7cb1c:      	br	x17

000000000007cb20 <vlai_face3d_runtime_setting_set_use_image_video_only@plt>:
   7cb20:      	adrp	x16, 0x84000
   7cb24:      	ldr	x17, [x16, #0x9c8]
   7cb28:      	add	x16, x16, #0x9c8
   7cb2c:      	br	x17

000000000007cb30 <_ZN17MMDetectionPlugin10DL3DModuleD1Ev@plt>:
   7cb30:      	adrp	x16, 0x84000
   7cb34:      	ldr	x17, [x16, #0x9d0]
   7cb38:      	add	x16, x16, #0x9d0
   7cb3c:      	br	x17

000000000007cb40 <vlai_runtime_setting_face3d_runtime_setting@plt>:
   7cb40:      	adrp	x16, 0x84000
   7cb44:      	ldr	x17, [x16, #0x9d8]
   7cb48:      	add	x16, x16, #0x9d8
   7cb4c:      	br	x17

000000000007cb50 <vldp_get_data_protocol_dl3d_result@plt>:
   7cb50:      	adrp	x16, 0x84000
   7cb54:      	ldr	x17, [x16, #0x9e0]
   7cb58:      	add	x16, x16, #0x9e0
   7cb5c:      	br	x17

000000000007cb60 <vldp_get_dl3d_result_pointer_ref@plt>:
   7cb60:      	adrp	x16, 0x84000
   7cb64:      	ldr	x17, [x16, #0x9e8]
   7cb68:      	add	x16, x16, #0x9e8
   7cb6c:      	br	x17

000000000007cb70 <_ZN17MMDetectionPlugin10DL3DResultC1Ev@plt>:
   7cb70:      	adrp	x16, 0x84000
   7cb74:      	ldr	x17, [x16, #0x9f0]
   7cb78:      	add	x16, x16, #0x9f0
   7cb7c:      	br	x17

000000000007cb80 <vldp_get_dl3d_result_dl3ds@plt>:
   7cb80:      	adrp	x16, 0x84000
   7cb84:      	ldr	x17, [x16, #0x9f8]
   7cb88:      	add	x16, x16, #0x9f8
   7cb8c:      	br	x17

000000000007cb90 <vldp_get_dl3d_array_pointer_size@plt>:
   7cb90:      	adrp	x16, 0x84000
   7cb94:      	ldr	x17, [x16, #0xa00]
   7cb98:      	add	x16, x16, #0xa00
   7cb9c:      	br	x17

000000000007cba0 <vldp_get_dl3d_array_pointer_at@plt>:
   7cba0:      	adrp	x16, 0x84000
   7cba4:      	ldr	x17, [x16, #0xa08]
   7cba8:      	add	x16, x16, #0xa08
   7cbac:      	br	x17

000000000007cbb0 <_ZN17MMDetectionPlugin10DL3DResultD1Ev@plt>:
   7cbb0:      	adrp	x16, 0x84000
   7cbb4:      	ldr	x17, [x16, #0xa10]
   7cbb8:      	add	x16, x16, #0xa10
   7cbbc:      	br	x17

000000000007cbc0 <vlai_face3d_runtime_setting_set_max_face_count_for2_d@plt>:
   7cbc0:      	adrp	x16, 0x84000
   7cbc4:      	ldr	x17, [x16, #0xa18]
   7cbc8:      	add	x16, x16, #0xa18
   7cbcc:      	br	x17

000000000007cbd0 <_ZN17MMDetectionPlugin35setFace25DRuntimeSettingOutsizeFaceER25vldp_data_protocol_handlePKNS_16_DetectionOptionE@plt>:
   7cbd0:      	adrp	x16, 0x84000
   7cbd4:      	ldr	x17, [x16, #0xa20]
   7cbd8:      	add	x16, x16, #0xa20
   7cbdc:      	br	x17

000000000007cbe0 <_ZN17MMDetectionPlugin13Face25DModuleD1Ev@plt>:
   7cbe0:      	adrp	x16, 0x84000
   7cbe4:      	ldr	x17, [x16, #0xa28]
   7cbe8:      	add	x16, x16, #0xa28
   7cbec:      	br	x17

000000000007cbf0 <vldp_get_data_protocol_face3d_result@plt>:
   7cbf0:      	adrp	x16, 0x84000
   7cbf4:      	ldr	x17, [x16, #0xa30]
   7cbf8:      	add	x16, x16, #0xa30
   7cbfc:      	br	x17

000000000007cc00 <vldp_get_face3d_result_pointer_ref@plt>:
   7cc00:      	adrp	x16, 0x84000
   7cc04:      	ldr	x17, [x16, #0xa38]
   7cc08:      	add	x16, x16, #0xa38
   7cc0c:      	br	x17

000000000007cc10 <_ZN17MMDetectionPlugin13Face25DResultC1Ev@plt>:
   7cc10:      	adrp	x16, 0x84000
   7cc14:      	ldr	x17, [x16, #0xa40]
   7cc18:      	add	x16, x16, #0xa40
   7cc1c:      	br	x17

000000000007cc20 <vldp_get_face3d_result_face2dv1s@plt>:
   7cc20:      	adrp	x16, 0x84000
   7cc24:      	ldr	x17, [x16, #0xa48]
   7cc28:      	add	x16, x16, #0xa48
   7cc2c:      	br	x17

000000000007cc30 <vldp_get_face3d_part2d_array_pointer_size@plt>:
   7cc30:      	adrp	x16, 0x84000
   7cc34:      	ldr	x17, [x16, #0xa50]
   7cc38:      	add	x16, x16, #0xa50
   7cc3c:      	br	x17

000000000007cc40 <vldp_get_face3d_part2d_array_pointer_at@plt>:
   7cc40:      	adrp	x16, 0x84000
   7cc44:      	ldr	x17, [x16, #0xa58]
   7cc48:      	add	x16, x16, #0xa58
   7cc4c:      	br	x17

000000000007cc50 <vldp_get_face3d_part2d_face_id@plt>:
   7cc50:      	adrp	x16, 0x84000
   7cc54:      	ldr	x17, [x16, #0xa60]
   7cc58:      	add	x16, x16, #0xa60
   7cc5c:      	br	x17

000000000007cc60 <vldp_get_face3d_part2d_stand_vertexs@plt>:
   7cc60:      	adrp	x16, 0x84000
   7cc64:      	ldr	x17, [x16, #0xa68]
   7cc68:      	add	x16, x16, #0xa68
   7cc6c:      	br	x17

000000000007cc70 <vldp_get_face3d_part2d_face2d_mesh@plt>:
   7cc70:      	adrp	x16, 0x84000
   7cc74:      	ldr	x17, [x16, #0xa70]
   7cc78:      	add	x16, x16, #0xa70
   7cc7c:      	br	x17

000000000007cc80 <vldp_get_face2d_mesh_vertexs@plt>:
   7cc80:      	adrp	x16, 0x84000
   7cc84:      	ldr	x17, [x16, #0xa78]
   7cc88:      	add	x16, x16, #0xa78
   7cc8c:      	br	x17

000000000007cc90 <vldp_get_face2d_mesh_triangle_indexs@plt>:
   7cc90:      	adrp	x16, 0x84000
   7cc94:      	ldr	x17, [x16, #0xa80]
   7cc98:      	add	x16, x16, #0xa80
   7cc9c:      	br	x17

000000000007cca0 <vldp_get_face2d_mesh_texture_coordinates@plt>:
   7cca0:      	adrp	x16, 0x84000
   7cca4:      	ldr	x17, [x16, #0xa88]
   7cca8:      	add	x16, x16, #0xa88
   7ccac:      	br	x17

000000000007ccb0 <_ZNSt6__ndk19allocatorIN17MMDetectionPlugin13Face25DResult7Face25DEE9constructB8ne180000IS3_JRKS3_EEEvPT_DpOT0_@plt>:
   7ccb0:      	adrp	x16, 0x84000
   7ccb4:      	ldr	x17, [x16, #0xa90]
   7ccb8:      	add	x16, x16, #0xa90
   7ccbc:      	br	x17

000000000007ccc0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin13Face25DResult7Face25DENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7ccc0:      	adrp	x16, 0x84000
   7ccc4:      	ldr	x17, [x16, #0xa98]
   7ccc8:      	add	x16, x16, #0xa98
   7cccc:      	br	x17

000000000007ccd0 <vldp_get_face3d_result_face2d_back_grounds@plt>:
   7ccd0:      	adrp	x16, 0x84000
   7ccd4:      	ldr	x17, [x16, #0xaa0]
   7ccd8:      	add	x16, x16, #0xaa0
   7ccdc:      	br	x17

000000000007cce0 <vldp_get_face3d_result_face2dv3s@plt>:
   7cce0:      	adrp	x16, 0x84000
   7cce4:      	ldr	x17, [x16, #0xaa8]
   7cce8:      	add	x16, x16, #0xaa8
   7ccec:      	br	x17

000000000007ccf0 <vldp_get_face3d_result_face2dv2s@plt>:
   7ccf0:      	adrp	x16, 0x84000
   7ccf4:      	ldr	x17, [x16, #0xab0]
   7ccf8:      	add	x16, x16, #0xab0
   7ccfc:      	br	x17

000000000007cd00 <vldp_get_face3d_result_face2d_muiti_back_grounds@plt>:
   7cd00:      	adrp	x16, 0x84000
   7cd04:      	ldr	x17, [x16, #0xab8]
   7cd08:      	add	x16, x16, #0xab8
   7cd0c:      	br	x17

000000000007cd10 <_ZN17MMDetectionPlugin13Face25DResult7Face25DD2Ev@plt>:
   7cd10:      	adrp	x16, 0x84000
   7cd14:      	ldr	x17, [x16, #0xac0]
   7cd18:      	add	x16, x16, #0xac0
   7cd1c:      	br	x17

000000000007cd20 <_ZN17MMDetectionPlugin13Face25DResult10Face2DMeshD2Ev@plt>:
   7cd20:      	adrp	x16, 0x84000
   7cd24:      	ldr	x17, [x16, #0xac8]
   7cd28:      	add	x16, x16, #0xac8
   7cd2c:      	br	x17

000000000007cd30 <_ZN17MMDetectionPlugin13Face25DResultD1Ev@plt>:
   7cd30:      	adrp	x16, 0x84000
   7cd34:      	ldr	x17, [x16, #0xad0]
   7cd38:      	add	x16, x16, #0xad0
   7cd3c:      	br	x17

000000000007cd40 <_ZN17MMDetectionPlugin13Face25DResult10Face2DMeshC2ERKS1_@plt>:
   7cd40:      	adrp	x16, 0x84000
   7cd44:      	ldr	x17, [x16, #0xad8]
   7cd48:      	add	x16, x16, #0xad8
   7cd4c:      	br	x17

000000000007cd50 <_ZN17MMDetectionPlugin36setAiVideoStabilizationRuntimeOptionERKNS_25_VideoStabilizationOptionER47vlai_video_stabilization_runtime_setting_handleR23vlai_require_set_handle@plt>:
   7cd50:      	adrp	x16, 0x84000
   7cd54:      	ldr	x17, [x16, #0xae0]
   7cd58:      	add	x16, x16, #0xae0
   7cd5c:      	br	x17

000000000007cd60 <vlai_video_stabilization_runtime_setting_set_frame_num@plt>:
   7cd60:      	adrp	x16, 0x84000
   7cd64:      	ldr	x17, [x16, #0xae8]
   7cd68:      	add	x16, x16, #0xae8
   7cd6c:      	br	x17

000000000007cd70 <vlai_video_stabilization_runtime_setting_set_frame_time@plt>:
   7cd70:      	adrp	x16, 0x84000
   7cd74:      	ldr	x17, [x16, #0xaf0]
   7cd78:      	add	x16, x16, #0xaf0
   7cd7c:      	br	x17

000000000007cd80 <vlai_video_stabilization_runtime_setting_set_width@plt>:
   7cd80:      	adrp	x16, 0x84000
   7cd84:      	ldr	x17, [x16, #0xaf8]
   7cd88:      	add	x16, x16, #0xaf8
   7cd8c:      	br	x17

000000000007cd90 <vlai_video_stabilization_runtime_setting_set_height@plt>:
   7cd90:      	adrp	x16, 0x84000
   7cd94:      	ldr	x17, [x16, #0xb00]
   7cd98:      	add	x16, x16, #0xb00
   7cd9c:      	br	x17

000000000007cda0 <vlai_video_stabilization_runtime_setting_set_thumb_width@plt>:
   7cda0:      	adrp	x16, 0x84000
   7cda4:      	ldr	x17, [x16, #0xb08]
   7cda8:      	add	x16, x16, #0xb08
   7cdac:      	br	x17

000000000007cdb0 <vlai_video_stabilization_runtime_setting_set_thumb_height@plt>:
   7cdb0:      	adrp	x16, 0x84000
   7cdb4:      	ldr	x17, [x16, #0xb10]
   7cdb8:      	add	x16, x16, #0xb10
   7cdbc:      	br	x17

000000000007cdc0 <vlai_video_stabilization_runtime_setting_set_have_face@plt>:
   7cdc0:      	adrp	x16, 0x84000
   7cdc4:      	ldr	x17, [x16, #0xb18]
   7cdc8:      	add	x16, x16, #0xb18
   7cdcc:      	br	x17

000000000007cdd0 <vlai_video_stabilization_runtime_setting_set_index@plt>:
   7cdd0:      	adrp	x16, 0x84000
   7cdd4:      	ldr	x17, [x16, #0xb20]
   7cdd8:      	add	x16, x16, #0xb20
   7cddc:      	br	x17

000000000007cde0 <vlai_video_stabilization_runtime_setting_set_is_init@plt>:
   7cde0:      	adrp	x16, 0x84000
   7cde4:      	ldr	x17, [x16, #0xb28]
   7cde8:      	add	x16, x16, #0xb28
   7cdec:      	br	x17

000000000007cdf0 <_ZN17MMDetectionPlugin15VideoStabModuleD1Ev@plt>:
   7cdf0:      	adrp	x16, 0x84000
   7cdf4:      	ldr	x17, [x16, #0xb30]
   7cdf8:      	add	x16, x16, #0xb30
   7cdfc:      	br	x17

000000000007ce00 <vlai_setting_patch_video_stabilization_setting_patch@plt>:
   7ce00:      	adrp	x16, 0x84000
   7ce04:      	ldr	x17, [x16, #0xb38]
   7ce08:      	add	x16, x16, #0xb38
   7ce0c:      	br	x17

000000000007ce10 <vlai_runtime_setting_video_stabilization_runtime_setting@plt>:
   7ce10:      	adrp	x16, 0x84000
   7ce14:      	ldr	x17, [x16, #0xb40]
   7ce18:      	add	x16, x16, #0xb40
   7ce1c:      	br	x17

000000000007ce20 <vldp_get_data_protocol_video_stabilization_result@plt>:
   7ce20:      	adrp	x16, 0x84000
   7ce24:      	ldr	x17, [x16, #0xb48]
   7ce28:      	add	x16, x16, #0xb48
   7ce2c:      	br	x17

000000000007ce30 <vldp_get_video_stabilization_result_pointer_ref@plt>:
   7ce30:      	adrp	x16, 0x84000
   7ce34:      	ldr	x17, [x16, #0xb50]
   7ce38:      	add	x16, x16, #0xb50
   7ce3c:      	br	x17

000000000007ce40 <vldp_get_video_stabilization_result_matrixes_low@plt>:
   7ce40:      	adrp	x16, 0x84000
   7ce44:      	ldr	x17, [x16, #0xb58]
   7ce48:      	add	x16, x16, #0xb58
   7ce4c:      	br	x17

000000000007ce50 <vldp_get_video_stabilization_result_matrixes_medium@plt>:
   7ce50:      	adrp	x16, 0x84000
   7ce54:      	ldr	x17, [x16, #0xb60]
   7ce58:      	add	x16, x16, #0xb60
   7ce5c:      	br	x17

000000000007ce60 <vldp_get_video_stabilization_result_matrixes_high@plt>:
   7ce60:      	adrp	x16, 0x84000
   7ce64:      	ldr	x17, [x16, #0xb68]
   7ce68:      	add	x16, x16, #0xb68
   7ce6c:      	br	x17

000000000007ce70 <vldp_get_video_stabilization_matrix_array_pointer_size@plt>:
   7ce70:      	adrp	x16, 0x84000
   7ce74:      	ldr	x17, [x16, #0xb70]
   7ce78:      	add	x16, x16, #0xb70
   7ce7c:      	br	x17

000000000007ce80 <_ZN17MMDetectionPlugin24VideoStabilizationResultC1Ev@plt>:
   7ce80:      	adrp	x16, 0x84000
   7ce84:      	ldr	x17, [x16, #0xb78]
   7ce88:      	add	x16, x16, #0xb78
   7ce8c:      	br	x17

000000000007ce90 <vldp_get_video_stabilization_matrix_array_pointer_at@plt>:
   7ce90:      	adrp	x16, 0x84000
   7ce94:      	ldr	x17, [x16, #0xb80]
   7ce98:      	add	x16, x16, #0xb80
   7ce9c:      	br	x17

000000000007cea0 <vldp_get_video_stabilization_matrix_frame_time@plt>:
   7cea0:      	adrp	x16, 0x84000
   7cea4:      	ldr	x17, [x16, #0xb88]
   7cea8:      	add	x16, x16, #0xb88
   7ceac:      	br	x17

000000000007ceb0 <vldp_get_video_stabilization_result_orientation@plt>:
   7ceb0:      	adrp	x16, 0x84000
   7ceb4:      	ldr	x17, [x16, #0xb90]
   7ceb8:      	add	x16, x16, #0xb90
   7cebc:      	br	x17

000000000007cec0 <vldp_get_video_stabilization_matrix_matrix@plt>:
   7cec0:      	adrp	x16, 0x84000
   7cec4:      	ldr	x17, [x16, #0xb98]
   7cec8:      	add	x16, x16, #0xb98
   7cecc:      	br	x17

000000000007ced0 <_ZN17MMDetectionPlugin24setAiBodyInOneEnableEnumENS_20_BodyInOneOptionTypeER23vlai_require_set_handle@plt>:
   7ced0:      	adrp	x16, 0x84000
   7ced4:      	ldr	x17, [x16, #0xba0]
   7ced8:      	add	x16, x16, #0xba0
   7cedc:      	br	x17

000000000007cee0 <_ZN17MMDetectionPlugin20setAiBodyInOneOptionERKNS_25_BodyInOneDetectionOptionER37vlai_body_in_one_setting_patch_handlebR23vlai_require_set_handle@plt>:
   7cee0:      	adrp	x16, 0x84000
   7cee4:      	ldr	x17, [x16, #0xba8]
   7cee8:      	add	x16, x16, #0xba8
   7ceec:      	br	x17

000000000007cef0 <vlai_body_in_one_setting_patch_set_detect_period@plt>:
   7cef0:      	adrp	x16, 0x84000
   7cef4:      	ldr	x17, [x16, #0xbb0]
   7cef8:      	add	x16, x16, #0xbb0
   7cefc:      	br	x17

000000000007cf00 <vlai_body_in_one_setting_patch_set_camera_mode@plt>:
   7cf00:      	adrp	x16, 0x84000
   7cf04:      	ldr	x17, [x16, #0xbb8]
   7cf08:      	add	x16, x16, #0xbb8
   7cf0c:      	br	x17

000000000007cf10 <vlai_body_in_one_setting_patch_set_pose_model_type@plt>:
   7cf10:      	adrp	x16, 0x84000
   7cf14:      	ldr	x17, [x16, #0xbc0]
   7cf18:      	add	x16, x16, #0xbc0
   7cf1c:      	br	x17

000000000007cf20 <vlai_body_in_one_setting_patch_set_model_mode@plt>:
   7cf20:      	adrp	x16, 0x84000
   7cf24:      	ldr	x17, [x16, #0xbc8]
   7cf28:      	add	x16, x16, #0xbc8
   7cf2c:      	br	x17

000000000007cf30 <vlai_body_in_one_setting_patch_set_pose_model_mode@plt>:
   7cf30:      	adrp	x16, 0x84000
   7cf34:      	ldr	x17, [x16, #0xbd0]
   7cf38:      	add	x16, x16, #0xbd0
   7cf3c:      	br	x17

000000000007cf40 <vlai_body_in_one_setting_patch_set_app_scene@plt>:
   7cf40:      	adrp	x16, 0x84000
   7cf44:      	ldr	x17, [x16, #0xbd8]
   7cf48:      	add	x16, x16, #0xbd8
   7cf4c:      	br	x17

000000000007cf50 <vlai_body_in_one_setting_patch_set_neck_model_type@plt>:
   7cf50:      	adrp	x16, 0x84000
   7cf54:      	ldr	x17, [x16, #0xbe0]
   7cf58:      	add	x16, x16, #0xbe0
   7cf5c:      	br	x17

000000000007cf60 <vlai_body_in_one_setting_patch_set_breast_model_type@plt>:
   7cf60:      	adrp	x16, 0x84000
   7cf64:      	ldr	x17, [x16, #0xbe8]
   7cf68:      	add	x16, x16, #0xbe8
   7cf6c:      	br	x17

000000000007cf70 <vlai_body_in_one_setting_patch_set_rt_multi_mode@plt>:
   7cf70:      	adrp	x16, 0x84000
   7cf74:      	ldr	x17, [x16, #0xbf0]
   7cf78:      	add	x16, x16, #0xbf0
   7cf7c:      	br	x17

000000000007cf80 <vlai_body_in_one_setting_patch_set_rt_multi_max_num@plt>:
   7cf80:      	adrp	x16, 0x84000
   7cf84:      	ldr	x17, [x16, #0xbf8]
   7cf88:      	add	x16, x16, #0xbf8
   7cf8c:      	br	x17

000000000007cf90 <vlai_body_in_one_setting_patch_set_rt_reid_interval@plt>:
   7cf90:      	adrp	x16, 0x84000
   7cf94:      	ldr	x17, [x16, #0xc00]
   7cf98:      	add	x16, x16, #0xc00
   7cf9c:      	br	x17

000000000007cfa0 <_ZN17MMDetectionPlugin26setBodyInOneRuntimeSettingER39vlai_body_in_one_runtime_setting_handlebbRKNS_25_BodyInOneDetectionOptionE@plt>:
   7cfa0:      	adrp	x16, 0x84000
   7cfa4:      	ldr	x17, [x16, #0xc08]
   7cfa8:      	add	x16, x16, #0xc08
   7cfac:      	br	x17

000000000007cfb0 <vlai_body_in_one_runtime_setting_set_neck_smooth_sigma@plt>:
   7cfb0:      	adrp	x16, 0x84000
   7cfb4:      	ldr	x17, [x16, #0xc10]
   7cfb8:      	add	x16, x16, #0xc10
   7cfbc:      	br	x17

000000000007cfc0 <vlai_body_in_one_runtime_setting_set_neck_smooth_normalizer@plt>:
   7cfc0:      	adrp	x16, 0x84000
   7cfc4:      	ldr	x17, [x16, #0xc18]
   7cfc8:      	add	x16, x16, #0xc18
   7cfcc:      	br	x17

000000000007cfd0 <vlai_body_in_one_runtime_setting_set_box_instance_mode@plt>:
   7cfd0:      	adrp	x16, 0x84000
   7cfd4:      	ldr	x17, [x16, #0xc20]
   7cfd8:      	add	x16, x16, #0xc20
   7cfdc:      	br	x17

000000000007cfe0 <vlai_body_in_one_runtime_setting_set_rt_multi_track_reset@plt>:
   7cfe0:      	adrp	x16, 0x84000
   7cfe4:      	ldr	x17, [x16, #0xc28]
   7cfe8:      	add	x16, x16, #0xc28
   7cfec:      	br	x17

000000000007cff0 <vlai_body_in_one_runtime_setting_set_rt_reid_merge@plt>:
   7cff0:      	adrp	x16, 0x84000
   7cff4:      	ldr	x17, [x16, #0xc30]
   7cff8:      	add	x16, x16, #0xc30
   7cffc:      	br	x17

000000000007d000 <vlai_body_in_one_runtime_setting_set_rt_multifinal_merge@plt>:
   7d000:      	adrp	x16, 0x84000
   7d004:      	ldr	x17, [x16, #0xc38]
   7d008:      	add	x16, x16, #0xc38
   7d00c:      	br	x17

000000000007d010 <_ZN17MMDetectionPlugin15BodyInOneModuleD1Ev@plt>:
   7d010:      	adrp	x16, 0x84000
   7d014:      	ldr	x17, [x16, #0xc40]
   7d018:      	add	x16, x16, #0xc40
   7d01c:      	br	x17

000000000007d020 <vlai_setting_patch_body_in_one_setting_patch@plt>:
   7d020:      	adrp	x16, 0x84000
   7d024:      	ldr	x17, [x16, #0xc48]
   7d028:      	add	x16, x16, #0xc48
   7d02c:      	br	x17

000000000007d030 <vlai_runtime_setting_body_in_one_runtime_setting@plt>:
   7d030:      	adrp	x16, 0x84000
   7d034:      	ldr	x17, [x16, #0xc50]
   7d038:      	add	x16, x16, #0xc50
   7d03c:      	br	x17

000000000007d040 <vlai_body_in_one_runtime_setting_set_frame_time_stamp@plt>:
   7d040:      	adrp	x16, 0x84000
   7d044:      	ldr	x17, [x16, #0xc58]
   7d048:      	add	x16, x16, #0xc58
   7d04c:      	br	x17

000000000007d050 <vldp_get_data_protocol_body_in_one_result@plt>:
   7d050:      	adrp	x16, 0x84000
   7d054:      	ldr	x17, [x16, #0xc60]
   7d058:      	add	x16, x16, #0xc60
   7d05c:      	br	x17

000000000007d060 <vldp_get_body_in_one_result_pointer_ref@plt>:
   7d060:      	adrp	x16, 0x84000
   7d064:      	ldr	x17, [x16, #0xc68]
   7d068:      	add	x16, x16, #0xc68
   7d06c:      	br	x17

000000000007d070 <_ZN17MMDetectionPlugin24BodyInOneDetectionResultC1Ev@plt>:
   7d070:      	adrp	x16, 0x84000
   7d074:      	ldr	x17, [x16, #0xc70]
   7d078:      	add	x16, x16, #0xc70
   7d07c:      	br	x17

000000000007d080 <vldp_get_body_in_one_result_size@plt>:
   7d080:      	adrp	x16, 0x84000
   7d084:      	ldr	x17, [x16, #0xc78]
   7d088:      	add	x16, x16, #0xc78
   7d08c:      	br	x17

000000000007d090 <vldp_get_body_in_one_result_orientation@plt>:
   7d090:      	adrp	x16, 0x84000
   7d094:      	ldr	x17, [x16, #0xc80]
   7d098:      	add	x16, x16, #0xc80
   7d09c:      	br	x17

000000000007d0a0 <vldp_get_body_in_one_result_body@plt>:
   7d0a0:      	adrp	x16, 0x84000
   7d0a4:      	ldr	x17, [x16, #0xc88]
   7d0a8:      	add	x16, x16, #0xc88
   7d0ac:      	br	x17

000000000007d0b0 <vldp_get_body_in_one_array_pointer_size@plt>:
   7d0b0:      	adrp	x16, 0x84000
   7d0b4:      	ldr	x17, [x16, #0xc90]
   7d0b8:      	add	x16, x16, #0xc90
   7d0bc:      	br	x17

000000000007d0c0 <vldp_get_body_in_one_array_pointer_at@plt>:
   7d0c0:      	adrp	x16, 0x84000
   7d0c4:      	ldr	x17, [x16, #0xc98]
   7d0c8:      	add	x16, x16, #0xc98
   7d0cc:      	br	x17

000000000007d0d0 <vldp_get_body_in_one_result_video_aio@plt>:
   7d0d0:      	adrp	x16, 0x84000
   7d0d4:      	ldr	x17, [x16, #0xca0]
   7d0d8:      	add	x16, x16, #0xca0
   7d0dc:      	br	x17

000000000007d0e0 <vldp_get_body_in_one_frame_time_stamp@plt>:
   7d0e0:      	adrp	x16, 0x84000
   7d0e4:      	ldr	x17, [x16, #0xca8]
   7d0e8:      	add	x16, x16, #0xca8
   7d0ec:      	br	x17

000000000007d0f0 <_ZN5media16MTDetectionCache10updateDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEElN17MMDetectionPlugin19DetectionResultTypeERKNS1_6vectorINS1_10shared_ptrINSA_15DetectionResultEEENS5_ISF_EEEENS_15MTDetectionFlagEb@plt>:
   7d0f0:      	adrp	x16, 0x84000
   7d0f4:      	ldr	x17, [x16, #0xcb0]
   7d0f8:      	add	x16, x16, #0xcb0
   7d0fc:      	br	x17

000000000007d100 <_ZN17MMDetectionPlugin24BodyInOneDetectionResult13BodyInOneInfoD2Ev@plt>:
   7d100:      	adrp	x16, 0x84000
   7d104:      	ldr	x17, [x16, #0xcb8]
   7d108:      	add	x16, x16, #0xcb8
   7d10c:      	br	x17

000000000007d110 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin24BodyInOneDetectionResult13BodyInOneInfoENS_9allocatorIS3_EEE21__push_back_slow_pathIS3_EEPS3_OT_@plt>:
   7d110:      	adrp	x16, 0x84000
   7d114:      	ldr	x17, [x16, #0xcc0]
   7d118:      	add	x16, x16, #0xcc0
   7d11c:      	br	x17

000000000007d120 <_ZN17MMDetectionPlugin15BodyInOneModule21retrieveBodyInOneDataEPKN5media10PixelImageEPKNS_16_DetectionOptionENS1_15MTDetectionTypeER25vlai_setting_patch_handleR27vlai_runtime_setting_handleR24vlai_graphics_env_handle@plt>:
   7d120:      	adrp	x16, 0x84000
   7d124:      	ldr	x17, [x16, #0xcc8]
   7d128:      	add	x16, x16, #0xcc8
   7d12c:      	br	x17

000000000007d130 <_ZN17MMDetectionPlugin15BodyInOneModule26updateBodyInOneRecognitionEv@plt>:
   7d130:      	adrp	x16, 0x84000
   7d134:      	ldr	x17, [x16, #0xcd0]
   7d138:      	add	x16, x16, #0xcd0
   7d13c:      	br	x17

000000000007d140 <_ZN17MMDetectionPlugin15BodyInOneModule28updateCurrentBodyInOneNameIdEv@plt>:
   7d140:      	adrp	x16, 0x84000
   7d144:      	ldr	x17, [x16, #0xcd8]
   7d148:      	add	x16, x16, #0xcd8
   7d14c:      	br	x17

000000000007d150 <vldp_get_body_in_one_result_merged_id@plt>:
   7d150:      	adrp	x16, 0x84000
   7d154:      	ldr	x17, [x16, #0xce0]
   7d158:      	add	x16, x16, #0xce0
   7d15c:      	br	x17

000000000007d160 <vldp_get_body_in_one_result_reid_embeddings@plt>:
   7d160:      	adrp	x16, 0x84000
   7d164:      	ldr	x17, [x16, #0xce8]
   7d168:      	add	x16, x16, #0xce8
   7d16c:      	br	x17

000000000007d170 <vldp_get_body_in_one_re_idembedding_array_pointer_size@plt>:
   7d170:      	adrp	x16, 0x84000
   7d174:      	ldr	x17, [x16, #0xcf0]
   7d178:      	add	x16, x16, #0xcf0
   7d17c:      	br	x17

000000000007d180 <vldp_get_body_in_one_re_idembedding_array_pointer_at@plt>:
   7d180:      	adrp	x16, 0x84000
   7d184:      	ldr	x17, [x16, #0xcf8]
   7d188:      	add	x16, x16, #0xcf8
   7d18c:      	br	x17

000000000007d190 <vldp_get_body_in_one_re_idembedding_has_re_idindex@plt>:
   7d190:      	adrp	x16, 0x84000
   7d194:      	ldr	x17, [x16, #0xd00]
   7d198:      	add	x16, x16, #0xd00
   7d19c:      	br	x17

000000000007d1a0 <vldp_get_body_in_one_re_idembedding_re_idindex@plt>:
   7d1a0:      	adrp	x16, 0x84000
   7d1a4:      	ldr	x17, [x16, #0xd08]
   7d1a8:      	add	x16, x16, #0xd08
   7d1ac:      	br	x17

000000000007d1b0 <vldp_get_body_in_one_re_idembedding_re_idembedding@plt>:
   7d1b0:      	adrp	x16, 0x84000
   7d1b4:      	ldr	x17, [x16, #0xd10]
   7d1b8:      	add	x16, x16, #0xd10
   7d1bc:      	br	x17

000000000007d1c0 <_ZNSt6__ndk16vectorINS0_IiNS_9allocatorIiEEEENS1_IS3_EEE24__emplace_back_slow_pathIJS3_EEEPS3_DpOT_@plt>:
   7d1c0:      	adrp	x16, 0x84000
   7d1c4:      	ldr	x17, [x16, #0xd18]
   7d1c8:      	add	x16, x16, #0xd18
   7d1cc:      	br	x17

000000000007d1d0 <_ZNSt6__ndk16vectorINS0_IfNS_9allocatorIfEEEENS1_IS3_EEE18__assign_with_sizeB8ne180000IPS3_S7_EEvT_T0_l@plt>:
   7d1d0:      	adrp	x16, 0x84000
   7d1d4:      	ldr	x17, [x16, #0xd20]
   7d1d8:      	add	x16, x16, #0xd20
   7d1dc:      	br	x17

000000000007d1e0 <vldp_create_body_in_one_re_idembedding_array_pointer@plt>:
   7d1e0:      	adrp	x16, 0x84000
   7d1e4:      	ldr	x17, [x16, #0xd28]
   7d1e8:      	add	x16, x16, #0xd28
   7d1ec:      	br	x17

000000000007d1f0 <vldp_set_body_in_one_re_idembedding_has_re_idindex@plt>:
   7d1f0:      	adrp	x16, 0x84000
   7d1f4:      	ldr	x17, [x16, #0xd30]
   7d1f8:      	add	x16, x16, #0xd30
   7d1fc:      	br	x17

000000000007d200 <vldp_set_body_in_one_re_idembedding_re_idindex@plt>:
   7d200:      	adrp	x16, 0x84000
   7d204:      	ldr	x17, [x16, #0xd38]
   7d208:      	add	x16, x16, #0xd38
   7d20c:      	br	x17

000000000007d210 <vldp_set_float_array_pointer_array_pointer_hold@plt>:
   7d210:      	adrp	x16, 0x84000
   7d214:      	ldr	x17, [x16, #0xd40]
   7d218:      	add	x16, x16, #0xd40
   7d21c:      	br	x17

000000000007d220 <vlai_body_in_one_match_reid_embeddings@plt>:
   7d220:      	adrp	x16, 0x84000
   7d224:      	ldr	x17, [x16, #0xd48]
   7d228:      	add	x16, x16, #0xd48
   7d22c:      	br	x17

000000000007d230 <vlai_body_in_one_simplify_reid_embedding@plt>:
   7d230:      	adrp	x16, 0x84000
   7d234:      	ldr	x17, [x16, #0xd50]
   7d238:      	add	x16, x16, #0xd50
   7d23c:      	br	x17

000000000007d240 <vldp_set_body_in_one_re_idembedding_array_pointer_at@plt>:
   7d240:      	adrp	x16, 0x84000
   7d244:      	ldr	x17, [x16, #0xd58]
   7d248:      	add	x16, x16, #0xd58
   7d24c:      	br	x17

000000000007d250 <vldp_set_body_in_one_re_idembedding_array_pointer_hold@plt>:
   7d250:      	adrp	x16, 0x84000
   7d254:      	ldr	x17, [x16, #0xd60]
   7d258:      	add	x16, x16, #0xd60
   7d25c:      	br	x17

000000000007d260 <vldp_release_body_in_one_re_idembedding_array_pointer@plt>:
   7d260:      	adrp	x16, 0x84000
   7d264:      	ldr	x17, [x16, #0xd68]
   7d268:      	add	x16, x16, #0xd68
   7d26c:      	br	x17

000000000007d270 <vldp_release_int_array_pointer_array_pointer@plt>:
   7d270:      	adrp	x16, 0x84000
   7d274:      	ldr	x17, [x16, #0xd70]
   7d278:      	add	x16, x16, #0xd70
   7d27c:      	br	x17

000000000007d280 <_ZN5media16MTDetectionCache31writeBodyInOneRecognitionToFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_3mapIlNS1_6vectorINSB_IfNS5_IfEEEENS5_ISD_EEEENS1_4lessIlEENS5_INS1_4pairIKlSF_EEEEEE@plt>:
   7d280:      	adrp	x16, 0x84000
   7d284:      	ldr	x17, [x16, #0xd78]
   7d288:      	add	x16, x16, #0xd78
   7d28c:      	br	x17

000000000007d290 <_ZN17MMDetectionPlugin24DetectionRecognitionUtil21getBodyInOneBlockDataEv@plt>:
   7d290:      	adrp	x16, 0x84000
   7d294:      	ldr	x17, [x16, #0xd80]
   7d298:      	add	x16, x16, #0xd80
   7d29c:      	br	x17

000000000007d2a0 <_ZNSt6__ndk16__treeINS_12__value_typeIlNS_6vectorINS2_IfNS_9allocatorIfEEEENS3_IS5_EEEEEENS_19__map_value_compareIlS8_NS_4lessIlEELb1EEENS3_IS8_EEE14__assign_multiINS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEEEvT_SM_@plt>:
   7d2a0:      	adrp	x16, 0x84000
   7d2a4:      	ldr	x17, [x16, #0xd88]
   7d2a8:      	add	x16, x16, #0xd88
   7d2ac:      	br	x17

000000000007d2b0 <_ZNSt6__ndk19allocatorIN17MMDetectionPlugin24BodyInOneDetectionResult22MTBodyInOneRecognitionEE9constructB8ne180000IS3_JRKS3_EEEvPT_DpOT0_@plt>:
   7d2b0:      	adrp	x16, 0x84000
   7d2b4:      	ldr	x17, [x16, #0xd90]
   7d2b8:      	add	x16, x16, #0xd90
   7d2bc:      	br	x17

000000000007d2c0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin24BodyInOneDetectionResult22MTBodyInOneRecognitionENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7d2c0:      	adrp	x16, 0x84000
   7d2c4:      	ldr	x17, [x16, #0xd98]
   7d2c8:      	add	x16, x16, #0xd98
   7d2cc:      	br	x17

000000000007d2d0 <_ZN17MMDetectionPlugin24BodyInOneDetectionResult22MTBodyInOneRecognitionD2Ev@plt>:
   7d2d0:      	adrp	x16, 0x84000
   7d2d4:      	ldr	x17, [x16, #0xda0]
   7d2d8:      	add	x16, x16, #0xda0
   7d2dc:      	br	x17

000000000007d2e0 <_ZN5media16MTDetectionCache19getBodyInOneResultsEi@plt>:
   7d2e0:      	adrp	x16, 0x84000
   7d2e4:      	ldr	x17, [x16, #0xda8]
   7d2e8:      	add	x16, x16, #0xda8
   7d2ec:      	br	x17

000000000007d2f0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_3mapIlNS_4pairINS_6vectorINS_10shared_ptrIN17MMDetectionPlugin24BodyInOneDetectionResultEEENS5_ISE_EEEEiEENS_4lessIlEENS5_INS9_IKlSH_EEEEEEEENS_19__map_value_compareIS7_SO_NSI_IS7_EELb1EEENS5_ISO_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSY_IJEEEEEENS9_INS_15__tree_iteratorISO_PNS_11__tree_nodeISO_PvEElEEbEERKT_DpOT0_@plt>:
   7d2f0:      	adrp	x16, 0x84000
   7d2f4:      	ldr	x17, [x16, #0xdb0]
   7d2f8:      	add	x16, x16, #0xdb0
   7d2fc:      	br	x17

000000000007d300 <_ZN17MMDetectionPlugin24BodyInOneDetectionResult13BodyInOneInfoaSEOS1_@plt>:
   7d300:      	adrp	x16, 0x84000
   7d304:      	ldr	x17, [x16, #0xdb8]
   7d308:      	add	x16, x16, #0xdb8
   7d30c:      	br	x17

000000000007d310 <_ZN5media16MTDetectionCache19updateBodyInOneDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEElRKNS1_6vectorINS1_10shared_ptrIN17MMDetectionPlugin24BodyInOneDetectionResultEEENS5_ISE_EEEENSC_19DetectionResultTypeE@plt>:
   7d310:      	adrp	x16, 0x84000
   7d314:      	ldr	x17, [x16, #0xdc0]
   7d318:      	add	x16, x16, #0xdc0
   7d31c:      	br	x17

000000000007d320 <_ZN5media16MTDetectionCache33getBodyInOneOrgNameIdDstNameIdMapEv@plt>:
   7d320:      	adrp	x16, 0x84000
   7d324:      	ldr	x17, [x16, #0xdc8]
   7d328:      	add	x16, x16, #0xdc8
   7d32c:      	br	x17

000000000007d330 <_ZN17MMDetectionPlugin24BodyInOneDetectionResult13BodyInOneInfoC2ERKS1_@plt>:
   7d330:      	adrp	x16, 0x84000
   7d334:      	ldr	x17, [x16, #0xdd0]
   7d338:      	add	x16, x16, #0xdd0
   7d33c:      	br	x17

000000000007d340 <_ZNSt6__ndk16__treeINS_12__value_typeIlNS_6vectorINS2_IfNS_9allocatorIfEEEENS3_IS5_EEEEEENS_19__map_value_compareIlS8_NS_4lessIlEELb1EEENS3_IS8_EEE15__emplace_multiIJRKNS_4pairIKlS7_EEEEENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEDpOT_@plt>:
   7d340:      	adrp	x16, 0x84000
   7d344:      	ldr	x17, [x16, #0xdd8]
   7d348:      	add	x16, x16, #0xdd8
   7d34c:      	br	x17

000000000007d350 <_ZNSt6__ndk16__treeINS_12__value_typeIlNS_6vectorINS2_IfNS_9allocatorIfEEEENS3_IS5_EEEEEENS_19__map_value_compareIlS8_NS_4lessIlEELb1EEENS3_IS8_EEE30__emplace_hint_unique_key_argsIlJRKNS_4pairIKlS7_EEEEENSG_INS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEENS_21__tree_const_iteratorIS8_SP_lEERKT_DpOT0_@plt>:
   7d350:      	adrp	x16, 0x84000
   7d354:      	ldr	x17, [x16, #0xde0]
   7d358:      	add	x16, x16, #0xde0
   7d35c:      	br	x17

000000000007d360 <_ZNSt6__ndk16__treeINS_12__value_typeIlNS_6vectorINS2_IfNS_9allocatorIfEEEENS3_IS5_EEEEEENS_19__map_value_compareIlS8_NS_4lessIlEELb1EEENS3_IS8_EEE12__find_equalIlEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_SH_EElEERPNS_15__tree_end_nodeISJ_EESK_RKT_@plt>:
   7d360:      	adrp	x16, 0x84000
   7d364:      	ldr	x17, [x16, #0xde8]
   7d368:      	add	x16, x16, #0xde8
   7d36c:      	br	x17

000000000007d370 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_3mapIlNS_4pairINS_6vectorINS_10shared_ptrIN17MMDetectionPlugin24BodyInOneDetectionResultEEENS5_ISE_EEEEiEENS_4lessIlEENS5_INS9_IKlSH_EEEEEEEENS_19__map_value_compareIS7_SO_NSI_IS7_EELb1EEENS5_ISO_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISY_EERKT_@plt>:
   7d370:      	adrp	x16, 0x84000
   7d374:      	ldr	x17, [x16, #0xdf0]
   7d378:      	add	x16, x16, #0xdf0
   7d37c:      	br	x17

000000000007d380 <vlai_require_set_erase@plt>:
   7d380:      	adrp	x16, 0x84000
   7d384:      	ldr	x17, [x16, #0xdf8]
   7d388:      	add	x16, x16, #0xdf8
   7d38c:      	br	x17

000000000007d390 <vlai_video_teeth_retouch_setting_patch_set_run_gpu@plt>:
   7d390:      	adrp	x16, 0x84000
   7d394:      	ldr	x17, [x16, #0xe00]
   7d398:      	add	x16, x16, #0xe00
   7d39c:      	br	x17

000000000007d3a0 <vlai_video_teeth_retouch_setting_patch_set_max_retouch_face@plt>:
   7d3a0:      	adrp	x16, 0x84000
   7d3a4:      	ldr	x17, [x16, #0xe08]
   7d3a8:      	add	x16, x16, #0xe08
   7d3ac:      	br	x17

000000000007d3b0 <_ZN17MMDetectionPlugin31setRtTeethRetouchRuntimeSettingER25vldp_data_protocol_handlePKNS_16_DetectionOptionEPN10verenderer22MTRenderCommandEncoderEPNS5_16MTTextureBackendEPKNS_14DetectionFrameER24vlai_graphics_env_handleR17vlai_frame_handle@plt>:
   7d3b0:      	adrp	x16, 0x84000
   7d3b4:      	ldr	x17, [x16, #0xe10]
   7d3b8:      	add	x16, x16, #0xe10
   7d3bc:      	br	x17

000000000007d3c0 <_ZN17MMDetectionPlugin18RtTeethTouchModuleD1Ev@plt>:
   7d3c0:      	adrp	x16, 0x84000
   7d3c4:      	ldr	x17, [x16, #0xe18]
   7d3c8:      	add	x16, x16, #0xe18
   7d3cc:      	br	x17

000000000007d3d0 <vlai_setting_patch_video_teeth_retouch_setting_patch@plt>:
   7d3d0:      	adrp	x16, 0x84000
   7d3d4:      	ldr	x17, [x16, #0xe20]
   7d3d8:      	add	x16, x16, #0xe20
   7d3dc:      	br	x17

000000000007d3e0 <vldp_get_data_protocol_video_teeth_retouch_result@plt>:
   7d3e0:      	adrp	x16, 0x84000
   7d3e4:      	ldr	x17, [x16, #0xe28]
   7d3e8:      	add	x16, x16, #0xe28
   7d3ec:      	br	x17

000000000007d3f0 <vldp_get_video_teeth_retouch_result_pointer_ref@plt>:
   7d3f0:      	adrp	x16, 0x84000
   7d3f4:      	ldr	x17, [x16, #0xe30]
   7d3f8:      	add	x16, x16, #0xe30
   7d3fc:      	br	x17

000000000007d400 <_ZN17MMDetectionPlugin29RTTeethRetouchDetectionResultC1Ev@plt>:
   7d400:      	adrp	x16, 0x84000
   7d404:      	ldr	x17, [x16, #0xe38]
   7d408:      	add	x16, x16, #0xe38
   7d40c:      	br	x17

000000000007d410 <vldp_get_video_teeth_retouch_result_size@plt>:
   7d410:      	adrp	x16, 0x84000
   7d414:      	ldr	x17, [x16, #0xe40]
   7d418:      	add	x16, x16, #0xe40
   7d41c:      	br	x17

000000000007d420 <vldp_get_video_teeth_retouch_result_video_teeth_retouches@plt>:
   7d420:      	adrp	x16, 0x84000
   7d424:      	ldr	x17, [x16, #0xe48]
   7d428:      	add	x16, x16, #0xe48
   7d42c:      	br	x17

000000000007d430 <vldp_get_video_teeth_retouch_array_pointer_size@plt>:
   7d430:      	adrp	x16, 0x84000
   7d434:      	ldr	x17, [x16, #0xe50]
   7d438:      	add	x16, x16, #0xe50
   7d43c:      	br	x17

000000000007d440 <vldp_get_video_teeth_retouch_array_pointer_at@plt>:
   7d440:      	adrp	x16, 0x84000
   7d444:      	ldr	x17, [x16, #0xe58]
   7d448:      	add	x16, x16, #0xe58
   7d44c:      	br	x17

000000000007d450 <vldp_get_video_teeth_retouch_vex_coord@plt>:
   7d450:      	adrp	x16, 0x84000
   7d454:      	ldr	x17, [x16, #0xe60]
   7d458:      	add	x16, x16, #0xe60
   7d45c:      	br	x17

000000000007d460 <vldp_get_video_teeth_retouch_tex_coord@plt>:
   7d460:      	adrp	x16, 0x84000
   7d464:      	ldr	x17, [x16, #0xe68]
   7d468:      	add	x16, x16, #0xe68
   7d46c:      	br	x17

000000000007d470 <vldp_get_video_teeth_retouch_out_texture@plt>:
   7d470:      	adrp	x16, 0x84000
   7d474:      	ldr	x17, [x16, #0xe70]
   7d478:      	add	x16, x16, #0xe70
   7d47c:      	br	x17

000000000007d480 <vldp_get_texture_format@plt>:
   7d480:      	adrp	x16, 0x84000
   7d484:      	ldr	x17, [x16, #0xe78]
   7d488:      	add	x16, x16, #0xe78
   7d48c:      	br	x17

000000000007d490 <_ZN17MMDetectionPlugin19RTTeethRetouchBlockC1EPN5media5ImageE@plt>:
   7d490:      	adrp	x16, 0x84000
   7d494:      	ldr	x17, [x16, #0xe80]
   7d498:      	add	x16, x16, #0xe80
   7d49c:      	br	x17

000000000007d4a0 <vldp_get_video_teeth_retouch_face_id@plt>:
   7d4a0:      	adrp	x16, 0x84000
   7d4a4:      	ldr	x17, [x16, #0xe88]
   7d4a8:      	add	x16, x16, #0xe88
   7d4ac:      	br	x17

000000000007d4b0 <_ZN17MMDetectionPlugin19RTTeethRetouchBlockC1ERKS0_@plt>:
   7d4b0:      	adrp	x16, 0x84000
   7d4b4:      	ldr	x17, [x16, #0xe90]
   7d4b8:      	add	x16, x16, #0xe90
   7d4bc:      	br	x17

000000000007d4c0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19RTTeethRetouchBlockENS_9allocatorIS2_EEE21__push_back_slow_pathIS2_EEPS2_OT_@plt>:
   7d4c0:      	adrp	x16, 0x84000
   7d4c4:      	ldr	x17, [x16, #0xe98]
   7d4c8:      	add	x16, x16, #0xe98
   7d4cc:      	br	x17

000000000007d4d0 <_ZN17MMDetectionPlugin19RTTeethRetouchBlockD1Ev@plt>:
   7d4d0:      	adrp	x16, 0x84000
   7d4d4:      	ldr	x17, [x16, #0xea0]
   7d4d8:      	add	x16, x16, #0xea0
   7d4dc:      	br	x17

000000000007d4e0 <_ZN17MMDetectionPlugin29RTTeethRetouchDetectionResultD1Ev@plt>:
   7d4e0:      	adrp	x16, 0x84000
   7d4e4:      	ldr	x17, [x16, #0xea8]
   7d4e8:      	add	x16, x16, #0xea8
   7d4ec:      	br	x17

000000000007d4f0 <_ZN17MMDetectionPlugin12AnimalModuleD1Ev@plt>:
   7d4f0:      	adrp	x16, 0x84000
   7d4f4:      	ldr	x17, [x16, #0xeb0]
   7d4f8:      	add	x16, x16, #0xeb0
   7d4fc:      	br	x17

000000000007d500 <vldp_get_data_protocol_animal_result@plt>:
   7d500:      	adrp	x16, 0x84000
   7d504:      	ldr	x17, [x16, #0xeb8]
   7d508:      	add	x16, x16, #0xeb8
   7d50c:      	br	x17

000000000007d510 <vldp_get_animal_result_pointer_ref@plt>:
   7d510:      	adrp	x16, 0x84000
   7d514:      	ldr	x17, [x16, #0xec0]
   7d518:      	add	x16, x16, #0xec0
   7d51c:      	br	x17

000000000007d520 <_ZN17MMDetectionPlugin12AnimalResultC1Ev@plt>:
   7d520:      	adrp	x16, 0x84000
   7d524:      	ldr	x17, [x16, #0xec8]
   7d528:      	add	x16, x16, #0xec8
   7d52c:      	br	x17

000000000007d530 <vldp_get_animal_result_orientation@plt>:
   7d530:      	adrp	x16, 0x84000
   7d534:      	ldr	x17, [x16, #0xed0]
   7d538:      	add	x16, x16, #0xed0
   7d53c:      	br	x17

000000000007d540 <vldp_get_animal_result_size@plt>:
   7d540:      	adrp	x16, 0x84000
   7d544:      	ldr	x17, [x16, #0xed8]
   7d548:      	add	x16, x16, #0xed8
   7d54c:      	br	x17

000000000007d550 <vldp_get_animal_result_animals@plt>:
   7d550:      	adrp	x16, 0x84000
   7d554:      	ldr	x17, [x16, #0xee0]
   7d558:      	add	x16, x16, #0xee0
   7d55c:      	br	x17

000000000007d560 <vldp_get_animal_array_pointer_size@plt>:
   7d560:      	adrp	x16, 0x84000
   7d564:      	ldr	x17, [x16, #0xee8]
   7d568:      	add	x16, x16, #0xee8
   7d56c:      	br	x17

000000000007d570 <vldp_get_animal_array_pointer_at@plt>:
   7d570:      	adrp	x16, 0x84000
   7d574:      	ldr	x17, [x16, #0xef0]
   7d578:      	add	x16, x16, #0xef0
   7d57c:      	br	x17

000000000007d580 <vldp_get_animal_id@plt>:
   7d580:      	adrp	x16, 0x84000
   7d584:      	ldr	x17, [x16, #0xef8]
   7d588:      	add	x16, x16, #0xef8
   7d58c:      	br	x17

000000000007d590 <vldp_get_animal_label@plt>:
   7d590:      	adrp	x16, 0x84000
   7d594:      	ldr	x17, [x16, #0xf00]
   7d598:      	add	x16, x16, #0xf00
   7d59c:      	br	x17

000000000007d5a0 <vldp_get_animal_score@plt>:
   7d5a0:      	adrp	x16, 0x84000
   7d5a4:      	ldr	x17, [x16, #0xf08]
   7d5a8:      	add	x16, x16, #0xf08
   7d5ac:      	br	x17

000000000007d5b0 <vldp_get_animal_animal_rect@plt>:
   7d5b0:      	adrp	x16, 0x84000
   7d5b4:      	ldr	x17, [x16, #0xf10]
   7d5b8:      	add	x16, x16, #0xf10
   7d5bc:      	br	x17

000000000007d5c0 <vldp_get_animal_animal_points@plt>:
   7d5c0:      	adrp	x16, 0x84000
   7d5c4:      	ldr	x17, [x16, #0xf18]
   7d5c8:      	add	x16, x16, #0xf18
   7d5cc:      	br	x17

000000000007d5d0 <_ZNSt6__ndk16vectorIN5media4Vec2ENS_9allocatorIS2_EEE21__push_back_slow_pathIRKS2_EEPS2_OT_@plt>:
   7d5d0:      	adrp	x16, 0x84000
   7d5d4:      	ldr	x17, [x16, #0xf20]
   7d5d8:      	add	x16, x16, #0xf20
   7d5dc:      	br	x17

000000000007d5e0 <_ZN5media4Vec2C1Eff@plt>:
   7d5e0:      	adrp	x16, 0x84000
   7d5e4:      	ldr	x17, [x16, #0xf28]
   7d5e8:      	add	x16, x16, #0xf28
   7d5ec:      	br	x17

000000000007d5f0 <_ZN5media4Vec2C1ERKS0_@plt>:
   7d5f0:      	adrp	x16, 0x84000
   7d5f4:      	ldr	x17, [x16, #0xf30]
   7d5f8:      	add	x16, x16, #0xf30
   7d5fc:      	br	x17

000000000007d600 <_ZNSt6__ndk16vectorIN5media4Vec2ENS_9allocatorIS2_EEE16__init_with_sizeB8ne180000IPS2_S7_EEvT_T0_m@plt>:
   7d600:      	adrp	x16, 0x84000
   7d604:      	ldr	x17, [x16, #0xf38]
   7d608:      	add	x16, x16, #0xf38
   7d60c:      	br	x17

000000000007d610 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin12AnimalResult6AnimalENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7d610:      	adrp	x16, 0x84000
   7d614:      	ldr	x17, [x16, #0xf40]
   7d618:      	add	x16, x16, #0xf40
   7d61c:      	br	x17

000000000007d620 <_ZN17MMDetectionPlugin12AnimalResult6AnimalD2Ev@plt>:
   7d620:      	adrp	x16, 0x84000
   7d624:      	ldr	x17, [x16, #0xf48]
   7d628:      	add	x16, x16, #0xf48
   7d62c:      	br	x17

000000000007d630 <_ZN17MMDetectionPlugin12AnimalResultD1Ev@plt>:
   7d630:      	adrp	x16, 0x84000
   7d634:      	ldr	x17, [x16, #0xf50]
   7d638:      	add	x16, x16, #0xf50
   7d63c:      	br	x17

000000000007d640 <_ZN17MMDetectionPlugin17ExDenseHairModuleD1Ev@plt>:
   7d640:      	adrp	x16, 0x84000
   7d644:      	ldr	x17, [x16, #0xf58]
   7d648:      	add	x16, x16, #0xf58
   7d64c:      	br	x17

000000000007d650 <vldp_get_data_protocol_video_dense_hair_result@plt>:
   7d650:      	adrp	x16, 0x84000
   7d654:      	ldr	x17, [x16, #0xf60]
   7d658:      	add	x16, x16, #0xf60
   7d65c:      	br	x17

000000000007d660 <vldp_get_video_dense_hair_result_pointer_ref@plt>:
   7d660:      	adrp	x16, 0x84000
   7d664:      	ldr	x17, [x16, #0xf68]
   7d668:      	add	x16, x16, #0xf68
   7d66c:      	br	x17

000000000007d670 <vldp_get_video_dense_hair_result_video_dense_hairs@plt>:
   7d670:      	adrp	x16, 0x84000
   7d674:      	ldr	x17, [x16, #0xf70]
   7d678:      	add	x16, x16, #0xf70
   7d67c:      	br	x17

000000000007d680 <vldp_get_video_dense_hair_array_pointer_ref@plt>:
   7d680:      	adrp	x16, 0x84000
   7d684:      	ldr	x17, [x16, #0xf78]
   7d688:      	add	x16, x16, #0xf78
   7d68c:      	br	x17

000000000007d690 <vldp_get_video_dense_hair_out_texture@plt>:
   7d690:      	adrp	x16, 0x84000
   7d694:      	ldr	x17, [x16, #0xf80]
   7d698:      	add	x16, x16, #0xf80
   7d69c:      	br	x17

000000000007d6a0 <_ZN17MMDetectionPlugin20ExtraDetectionResultC1Ev@plt>:
   7d6a0:      	adrp	x16, 0x84000
   7d6a4:      	ldr	x17, [x16, #0xf88]
   7d6a8:      	add	x16, x16, #0xf88
   7d6ac:      	br	x17

000000000007d6b0 <vldp_get_texture_handle@plt>:
   7d6b0:      	adrp	x16, 0x84000
   7d6b4:      	ldr	x17, [x16, #0xf90]
   7d6b8:      	add	x16, x16, #0xf90
   7d6bc:      	br	x17

000000000007d6c0 <_ZN17MMDetectionPlugin20ExtraDetectionResultD1Ev@plt>:
   7d6c0:      	adrp	x16, 0x84000
   7d6c4:      	ldr	x17, [x16, #0xf98]
   7d6c8:      	add	x16, x16, #0xf98
   7d6cc:      	br	x17

000000000007d6d0 <vlai_graphics_env_make_context@plt>:
   7d6d0:      	adrp	x16, 0x84000
   7d6d4:      	ldr	x17, [x16, #0xfa0]
   7d6d8:      	add	x16, x16, #0xfa0
   7d6dc:      	br	x17

000000000007d6e0 <vlai_color_transfer_exit_GL@plt>:
   7d6e0:      	adrp	x16, 0x84000
   7d6e4:      	ldr	x17, [x16, #0xfa8]
   7d6e8:      	add	x16, x16, #0xfa8
   7d6ec:      	br	x17

000000000007d6f0 <vlai_color_transfer_destroy@plt>:
   7d6f0:      	adrp	x16, 0x84000
   7d6f4:      	ldr	x17, [x16, #0xfb0]
   7d6f8:      	add	x16, x16, #0xfb0
   7d6fc:      	br	x17

000000000007d700 <vlai_color_ac_gl_exitGL@plt>:
   7d700:      	adrp	x16, 0x84000
   7d704:      	ldr	x17, [x16, #0xfb8]
   7d708:      	add	x16, x16, #0xfb8
   7d70c:      	br	x17

000000000007d710 <vlai_color_ac_gl_destroy@plt>:
   7d710:      	adrp	x16, 0x84000
   7d714:      	ldr	x17, [x16, #0xfc0]
   7d718:      	add	x16, x16, #0xfc0
   7d71c:      	br	x17

000000000007d720 <vlai_color_toning_ew_exitGL@plt>:
   7d720:      	adrp	x16, 0x84000
   7d724:      	ldr	x17, [x16, #0xfc8]
   7d728:      	add	x16, x16, #0xfc8
   7d72c:      	br	x17

000000000007d730 <vlai_color_toning_ew_destroy@plt>:
   7d730:      	adrp	x16, 0x84000
   7d734:      	ldr	x17, [x16, #0xfd0]
   7d738:      	add	x16, x16, #0xfd0
   7d73c:      	br	x17

000000000007d740 <_ZN17MMDetectionPlugin21ExColorTransferModuleD1Ev@plt>:
   7d740:      	adrp	x16, 0x84000
   7d744:      	ldr	x17, [x16, #0xfd8]
   7d748:      	add	x16, x16, #0xfd8
   7d74c:      	br	x17

000000000007d750 <vlai_create_initialize_graphics_env@plt>:
   7d750:      	adrp	x16, 0x84000
   7d754:      	ldr	x17, [x16, #0xfe0]
   7d758:      	add	x16, x16, #0xfe0
   7d75c:      	br	x17

000000000007d760 <vlai_color_transfer_create@plt>:
   7d760:      	adrp	x16, 0x84000
   7d764:      	ldr	x17, [x16, #0xfe8]
   7d768:      	add	x16, x16, #0xfe8
   7d76c:      	br	x17

000000000007d770 <vlai_color_transfer_init@plt>:
   7d770:      	adrp	x16, 0x84000
   7d774:      	ldr	x17, [x16, #0xff0]
   7d778:      	add	x16, x16, #0xff0
   7d77c:      	br	x17

000000000007d780 <vlai_color_transfer_load_models@plt>:
   7d780:      	adrp	x16, 0x84000
   7d784:      	ldr	x17, [x16, #0xff8]
   7d788:      	add	x16, x16, #0xff8
   7d78c:      	br	x17

000000000007d790 <vlai_color_transfer_init_GL@plt>:
   7d790:      	adrp	x16, 0x85000
   7d794:      	ldr	x17, [x16]
   7d798:      	add	x16, x16, #0x0
   7d79c:      	br	x17

000000000007d7a0 <vlai_color_transfer_set_ref_data@plt>:
   7d7a0:      	adrp	x16, 0x85000
   7d7a4:      	ldr	x17, [x16, #0x8]
   7d7a8:      	add	x16, x16, #0x8
   7d7ac:      	br	x17

000000000007d7b0 <vlai_create_interop_texture@plt>:
   7d7b0:      	adrp	x16, 0x85000
   7d7b4:      	ldr	x17, [x16, #0x10]
   7d7b8:      	add	x16, x16, #0x10
   7d7bc:      	br	x17

000000000007d7c0 <vlai_interop_texture_get_metal_texture@plt>:
   7d7c0:      	adrp	x16, 0x85000
   7d7c4:      	ldr	x17, [x16, #0x18]
   7d7c8:      	add	x16, x16, #0x18
   7d7cc:      	br	x17

000000000007d7d0 <vlai_texture_draw_convert_texture@plt>:
   7d7d0:      	adrp	x16, 0x85000
   7d7d4:      	ldr	x17, [x16, #0x20]
   7d7d8:      	add	x16, x16, #0x20
   7d7dc:      	br	x17

000000000007d7e0 <vlai_interop_texture_get_opengl_texture@plt>:
   7d7e0:      	adrp	x16, 0x85000
   7d7e4:      	ldr	x17, [x16, #0x28]
   7d7e8:      	add	x16, x16, #0x28
   7d7ec:      	br	x17

000000000007d7f0 <vlai_destroy_interop_texture@plt>:
   7d7f0:      	adrp	x16, 0x85000
   7d7f4:      	ldr	x17, [x16, #0x30]
   7d7f8:      	add	x16, x16, #0x30
   7d7fc:      	br	x17

000000000007d800 <vlai_color_ac_gl_create@plt>:
   7d800:      	adrp	x16, 0x85000
   7d804:      	ldr	x17, [x16, #0x38]
   7d808:      	add	x16, x16, #0x38
   7d80c:      	br	x17

000000000007d810 <vlai_color_ac_gl_init@plt>:
   7d810:      	adrp	x16, 0x85000
   7d814:      	ldr	x17, [x16, #0x40]
   7d818:      	add	x16, x16, #0x40
   7d81c:      	br	x17

000000000007d820 <vlai_color_ac_gl_initGL@plt>:
   7d820:      	adrp	x16, 0x85000
   7d824:      	ldr	x17, [x16, #0x48]
   7d828:      	add	x16, x16, #0x48
   7d82c:      	br	x17

000000000007d830 <vlai_graphics_env_done_context@plt>:
   7d830:      	adrp	x16, 0x85000
   7d834:      	ldr	x17, [x16, #0x50]
   7d838:      	add	x16, x16, #0x50
   7d83c:      	br	x17

000000000007d840 <vlai_color_toning_ew_create@plt>:
   7d840:      	adrp	x16, 0x85000
   7d844:      	ldr	x17, [x16, #0x58]
   7d848:      	add	x16, x16, #0x58
   7d84c:      	br	x17

000000000007d850 <vlai_color_toning_ew_init@plt>:
   7d850:      	adrp	x16, 0x85000
   7d854:      	ldr	x17, [x16, #0x60]
   7d858:      	add	x16, x16, #0x60
   7d85c:      	br	x17

000000000007d860 <vlai_color_toning_ew_load_model@plt>:
   7d860:      	adrp	x16, 0x85000
   7d864:      	ldr	x17, [x16, #0x68]
   7d868:      	add	x16, x16, #0x68
   7d86c:      	br	x17

000000000007d870 <vlai_color_toning_ew_initGL@plt>:
   7d870:      	adrp	x16, 0x85000
   7d874:      	ldr	x17, [x16, #0x70]
   7d878:      	add	x16, x16, #0x70
   7d87c:      	br	x17

000000000007d880 <vlai_color_transfer_run_GL_output@plt>:
   7d880:      	adrp	x16, 0x85000
   7d884:      	ldr	x17, [x16, #0x78]
   7d888:      	add	x16, x16, #0x78
   7d88c:      	br	x17

000000000007d890 <vlai_interop_texture_flush_opengl@plt>:
   7d890:      	adrp	x16, 0x85000
   7d894:      	ldr	x17, [x16, #0x80]
   7d898:      	add	x16, x16, #0x80
   7d89c:      	br	x17

000000000007d8a0 <vlai_color_ac_gl_runGL_output@plt>:
   7d8a0:      	adrp	x16, 0x85000
   7d8a4:      	ldr	x17, [x16, #0x88]
   7d8a8:      	add	x16, x16, #0x88
   7d8ac:      	br	x17

000000000007d8b0 <vlai_color_toning_ew_set_ew_param@plt>:
   7d8b0:      	adrp	x16, 0x85000
   7d8b4:      	ldr	x17, [x16, #0x90]
   7d8b8:      	add	x16, x16, #0x90
   7d8bc:      	br	x17

000000000007d8c0 <vlai_color_toning_ew_runGL_Out@plt>:
   7d8c0:      	adrp	x16, 0x85000
   7d8c4:      	ldr	x17, [x16, #0x98]
   7d8c8:      	add	x16, x16, #0x98
   7d8cc:      	br	x17

000000000007d8d0 <_ZN17MMDetectionPlugin22setAiWrinkleEnableEnumEmR23vlai_require_set_handle@plt>:
   7d8d0:      	adrp	x16, 0x85000
   7d8d4:      	ldr	x17, [x16, #0xa0]
   7d8d8:      	add	x16, x16, #0xa0
   7d8dc:      	br	x17

000000000007d8e0 <vlai_wrinkle_setting_patch_set_force_image_mode@plt>:
   7d8e0:      	adrp	x16, 0x85000
   7d8e4:      	ldr	x17, [x16, #0xa8]
   7d8e8:      	add	x16, x16, #0xa8
   7d8ec:      	br	x17

000000000007d8f0 <_ZN17MMDetectionPlugin24setWrinkleRuntimeSettingER35vlai_wrinkle_runtime_setting_handlePKNS_16_DetectionOptionE@plt>:
   7d8f0:      	adrp	x16, 0x85000
   7d8f4:      	ldr	x17, [x16, #0xb0]
   7d8f8:      	add	x16, x16, #0xb0
   7d8fc:      	br	x17

000000000007d900 <vlai_wrinkle_runtime_setting_set_independent_mask@plt>:
   7d900:      	adrp	x16, 0x85000
   7d904:      	ldr	x17, [x16, #0xb8]
   7d908:      	add	x16, x16, #0xb8
   7d90c:      	br	x17

000000000007d910 <_ZNSt6__ndk13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_NS_4lessIS6_EENS4_INS_4pairIKS6_S6_EEEEE6insertB8ne180000INS_20__map_const_iteratorINS_21__tree_const_iteratorINS_12__value_typeIS6_S6_EEPNS_11__tree_nodeISI_PvEElEEEEEEvT_SP_@plt>:
   7d910:      	adrp	x16, 0x85000
   7d914:      	ldr	x17, [x16, #0xc0]
   7d918:      	add	x16, x16, #0xc0
   7d91c:      	br	x17

000000000007d920 <atoi@plt>:
   7d920:      	adrp	x16, 0x85000
   7d924:      	ldr	x17, [x16, #0xc8]
   7d928:      	add	x16, x16, #0xc8
   7d92c:      	br	x17

000000000007d930 <vlai_wrinkle_runtime_setting_set_feathered_silkworm@plt>:
   7d930:      	adrp	x16, 0x85000
   7d934:      	ldr	x17, [x16, #0xd0]
   7d938:      	add	x16, x16, #0xd0
   7d93c:      	br	x17

000000000007d940 <vlai_wrinkle_runtime_setting_set_dilation_silkworm_left@plt>:
   7d940:      	adrp	x16, 0x85000
   7d944:      	ldr	x17, [x16, #0xd8]
   7d948:      	add	x16, x16, #0xd8
   7d94c:      	br	x17

000000000007d950 <vlai_wrinkle_runtime_setting_set_dilation_silkworm_right@plt>:
   7d950:      	adrp	x16, 0x85000
   7d954:      	ldr	x17, [x16, #0xe0]
   7d958:      	add	x16, x16, #0xe0
   7d95c:      	br	x17

000000000007d960 <_ZN17MMDetectionPlugin13WrinkleModuleD1Ev@plt>:
   7d960:      	adrp	x16, 0x85000
   7d964:      	ldr	x17, [x16, #0xe8]
   7d968:      	add	x16, x16, #0xe8
   7d96c:      	br	x17

000000000007d970 <vlai_setting_patch_wrinkle_setting_patch@plt>:
   7d970:      	adrp	x16, 0x85000
   7d974:      	ldr	x17, [x16, #0xf0]
   7d978:      	add	x16, x16, #0xf0
   7d97c:      	br	x17

000000000007d980 <vlai_runtime_setting_wrinkle_runtime_setting@plt>:
   7d980:      	adrp	x16, 0x85000
   7d984:      	ldr	x17, [x16, #0xf8]
   7d988:      	add	x16, x16, #0xf8
   7d98c:      	br	x17

000000000007d990 <vldp_get_data_protocol_wrinkle_result@plt>:
   7d990:      	adrp	x16, 0x85000
   7d994:      	ldr	x17, [x16, #0x100]
   7d998:      	add	x16, x16, #0x100
   7d99c:      	br	x17

000000000007d9a0 <vldp_get_wrinkle_result_pointer_ref@plt>:
   7d9a0:      	adrp	x16, 0x85000
   7d9a4:      	ldr	x17, [x16, #0x108]
   7d9a8:      	add	x16, x16, #0x108
   7d9ac:      	br	x17

000000000007d9b0 <_ZN17MMDetectionPlugin22WrinkleDetectionResultC1Ev@plt>:
   7d9b0:      	adrp	x16, 0x85000
   7d9b4:      	ldr	x17, [x16, #0x110]
   7d9b8:      	add	x16, x16, #0x110
   7d9bc:      	br	x17

000000000007d9c0 <vldp_get_wrinkle_result_independent_wrinkles@plt>:
   7d9c0:      	adrp	x16, 0x85000
   7d9c4:      	ldr	x17, [x16, #0x118]
   7d9c8:      	add	x16, x16, #0x118
   7d9cc:      	br	x17

000000000007d9d0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin22WrinkleDetectionResult11WrinkleMaskENS_9allocatorIS3_EEE21__push_back_slow_pathIS3_EEPS3_OT_@plt>:
   7d9d0:      	adrp	x16, 0x85000
   7d9d4:      	ldr	x17, [x16, #0x120]
   7d9d8:      	add	x16, x16, #0x120
   7d9dc:      	br	x17

000000000007d9e0 <_ZN17MMDetectionPlugin22WrinkleDetectionResult11WrinkleMaskD1Ev@plt>:
   7d9e0:      	adrp	x16, 0x85000
   7d9e4:      	ldr	x17, [x16, #0x128]
   7d9e8:      	add	x16, x16, #0x128
   7d9ec:      	br	x17

000000000007d9f0 <vldp_get_independent_wrinkle_array_pointer_size@plt>:
   7d9f0:      	adrp	x16, 0x85000
   7d9f4:      	ldr	x17, [x16, #0x130]
   7d9f8:      	add	x16, x16, #0x130
   7d9fc:      	br	x17

000000000007da00 <vldp_get_independent_wrinkle_array_pointer_at@plt>:
   7da00:      	adrp	x16, 0x85000
   7da04:      	ldr	x17, [x16, #0x138]
   7da08:      	add	x16, x16, #0x138
   7da0c:      	br	x17

000000000007da10 <vldp_get_independent_wrinkle_detection_img@plt>:
   7da10:      	adrp	x16, 0x85000
   7da14:      	ldr	x17, [x16, #0x140]
   7da18:      	add	x16, x16, #0x140
   7da1c:      	br	x17

000000000007da20 <_ZN17MMDetectionPlugin22WrinkleDetectionResult11WrinkleMaskC1Ev@plt>:
   7da20:      	adrp	x16, 0x85000
   7da24:      	ldr	x17, [x16, #0x148]
   7da28:      	add	x16, x16, #0x148
   7da2c:      	br	x17

000000000007da30 <vldp_get_wrinkle_result_size@plt>:
   7da30:      	adrp	x16, 0x85000
   7da34:      	ldr	x17, [x16, #0x150]
   7da38:      	add	x16, x16, #0x150
   7da3c:      	br	x17

000000000007da40 <vldp_get_wrinkle_result_orientation@plt>:
   7da40:      	adrp	x16, 0x85000
   7da44:      	ldr	x17, [x16, #0x158]
   7da48:      	add	x16, x16, #0x158
   7da4c:      	br	x17

000000000007da50 <vldp_get_independent_wrinkle_face_id@plt>:
   7da50:      	adrp	x16, 0x85000
   7da54:      	ldr	x17, [x16, #0x160]
   7da58:      	add	x16, x16, #0x160
   7da5c:      	br	x17

000000000007da60 <vldp_get_independent_wrinkle_detection_type@plt>:
   7da60:      	adrp	x16, 0x85000
   7da64:      	ldr	x17, [x16, #0x168]
   7da68:      	add	x16, x16, #0x168
   7da6c:      	br	x17

000000000007da70 <vldp_get_independent_wrinkle_detectin_rect@plt>:
   7da70:      	adrp	x16, 0x85000
   7da74:      	ldr	x17, [x16, #0x170]
   7da78:      	add	x16, x16, #0x170
   7da7c:      	br	x17

000000000007da80 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_SH_EElEERPNS_15__tree_end_nodeISJ_EESK_RKT_@plt>:
   7da80:      	adrp	x16, 0x85000
   7da84:      	ldr	x17, [x16, #0x178]
   7da88:      	add	x16, x16, #0x178
   7da8c:      	br	x17

000000000007da90 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE16__construct_nodeIJRKNS_4pairIKS7_S7_EEEEENS_10unique_ptrINS_11__tree_nodeIS8_PvEENS_22__tree_node_destructorINS5_ISO_EEEEEEDpOT_@plt>:
   7da90:      	adrp	x16, 0x85000
   7da94:      	ldr	x17, [x16, #0x180]
   7da98:      	add	x16, x16, #0x180
   7da9c:      	br	x17

000000000007daa0 <_ZN17MMDetectionPlugin22WrinkleDetectionResultD1Ev@plt>:
   7daa0:      	adrp	x16, 0x85000
   7daa4:      	ldr	x17, [x16, #0x188]
   7daa8:      	add	x16, x16, #0x188
   7daac:      	br	x17

000000000007dab0 <vlai_hand_setting_patch_set_multi_thread@plt>:
   7dab0:      	adrp	x16, 0x85000
   7dab4:      	ldr	x17, [x16, #0x190]
   7dab8:      	add	x16, x16, #0x190
   7dabc:      	br	x17

000000000007dac0 <_ZN17MMDetectionPlugin10HandModuleD1Ev@plt>:
   7dac0:      	adrp	x16, 0x85000
   7dac4:      	ldr	x17, [x16, #0x198]
   7dac8:      	add	x16, x16, #0x198
   7dacc:      	br	x17

000000000007dad0 <vlai_setting_patch_hand_setting_patch@plt>:
   7dad0:      	adrp	x16, 0x85000
   7dad4:      	ldr	x17, [x16, #0x1a0]
   7dad8:      	add	x16, x16, #0x1a0
   7dadc:      	br	x17

000000000007dae0 <vlai_runtime_setting_hand_runtime_setting@plt>:
   7dae0:      	adrp	x16, 0x85000
   7dae4:      	ldr	x17, [x16, #0x1a8]
   7dae8:      	add	x16, x16, #0x1a8
   7daec:      	br	x17

000000000007daf0 <vlai_hand_runtime_setting_set_hand_max_num@plt>:
   7daf0:      	adrp	x16, 0x85000
   7daf4:      	ldr	x17, [x16, #0x1b0]
   7daf8:      	add	x16, x16, #0x1b0
   7dafc:      	br	x17

000000000007db00 <vldp_get_data_protocol_hand_result@plt>:
   7db00:      	adrp	x16, 0x85000
   7db04:      	ldr	x17, [x16, #0x1b8]
   7db08:      	add	x16, x16, #0x1b8
   7db0c:      	br	x17

000000000007db10 <vldp_get_hand_result_pointer_ref@plt>:
   7db10:      	adrp	x16, 0x85000
   7db14:      	ldr	x17, [x16, #0x1c0]
   7db18:      	add	x16, x16, #0x1c0
   7db1c:      	br	x17

000000000007db20 <_ZN17MMDetectionPlugin19HandDetectionResultC1Ev@plt>:
   7db20:      	adrp	x16, 0x85000
   7db24:      	ldr	x17, [x16, #0x1c8]
   7db28:      	add	x16, x16, #0x1c8
   7db2c:      	br	x17

000000000007db30 <vldp_get_hand_result_hands@plt>:
   7db30:      	adrp	x16, 0x85000
   7db34:      	ldr	x17, [x16, #0x1d0]
   7db38:      	add	x16, x16, #0x1d0
   7db3c:      	br	x17

000000000007db40 <vldp_get_hand_array_pointer_size@plt>:
   7db40:      	adrp	x16, 0x85000
   7db44:      	ldr	x17, [x16, #0x1d8]
   7db48:      	add	x16, x16, #0x1d8
   7db4c:      	br	x17

000000000007db50 <vldp_get_hand_array_pointer_at@plt>:
   7db50:      	adrp	x16, 0x85000
   7db54:      	ldr	x17, [x16, #0x1e0]
   7db58:      	add	x16, x16, #0x1e0
   7db5c:      	br	x17

000000000007db60 <vldp_get_hand_score@plt>:
   7db60:      	adrp	x16, 0x85000
   7db64:      	ldr	x17, [x16, #0x1e8]
   7db68:      	add	x16, x16, #0x1e8
   7db6c:      	br	x17

000000000007db70 <vldp_get_hand_gesture@plt>:
   7db70:      	adrp	x16, 0x85000
   7db74:      	ldr	x17, [x16, #0x1f0]
   7db78:      	add	x16, x16, #0x1f0
   7db7c:      	br	x17

000000000007db80 <vldp_get_hand_hand_rect@plt>:
   7db80:      	adrp	x16, 0x85000
   7db84:      	ldr	x17, [x16, #0x1f8]
   7db88:      	add	x16, x16, #0x1f8
   7db8c:      	br	x17

000000000007db90 <vldp_get_hand_hand_points@plt>:
   7db90:      	adrp	x16, 0x85000
   7db94:      	ldr	x17, [x16, #0x200]
   7db98:      	add	x16, x16, #0x200
   7db9c:      	br	x17

000000000007dba0 <vldp_get_hand_hand_pose_points@plt>:
   7dba0:      	adrp	x16, 0x85000
   7dba4:      	ldr	x17, [x16, #0x208]
   7dba8:      	add	x16, x16, #0x208
   7dbac:      	br	x17

000000000007dbb0 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19HandDetectionResult8MTMVHandENS_9allocatorIS3_EEE21__push_back_slow_pathIS3_EEPS3_OT_@plt>:
   7dbb0:      	adrp	x16, 0x85000
   7dbb4:      	ldr	x17, [x16, #0x210]
   7dbb8:      	add	x16, x16, #0x210
   7dbbc:      	br	x17

000000000007dbc0 <_ZN17MMDetectionPlugin19HandDetectionResultD1Ev@plt>:
   7dbc0:      	adrp	x16, 0x85000
   7dbc4:      	ldr	x17, [x16, #0x218]
   7dbc8:      	add	x16, x16, #0x218
   7dbcc:      	br	x17

000000000007dbd0 <vlai_pixar_animate_face_release_handle@plt>:
   7dbd0:      	adrp	x16, 0x85000
   7dbd4:      	ldr	x17, [x16, #0x220]
   7dbd8:      	add	x16, x16, #0x220
   7dbdc:      	br	x17

000000000007dbe0 <_ZN17MMDetectionPlugin22PixarAnimateFaceModuleD1Ev@plt>:
   7dbe0:      	adrp	x16, 0x85000
   7dbe4:      	ldr	x17, [x16, #0x228]
   7dbe8:      	add	x16, x16, #0x228
   7dbec:      	br	x17

000000000007dbf0 <vlai_pixar_animate_face_create_handle@plt>:
   7dbf0:      	adrp	x16, 0x85000
   7dbf4:      	ldr	x17, [x16, #0x230]
   7dbf8:      	add	x16, x16, #0x230
   7dbfc:      	br	x17

000000000007dc00 <vlai_pixar_animate_face_init@plt>:
   7dc00:      	adrp	x16, 0x85000
   7dc04:      	ldr	x17, [x16, #0x238]
   7dc08:      	add	x16, x16, #0x238
   7dc0c:      	br	x17

000000000007dc10 <vlai_pixar_animate_face_process_with_facesInfo_gl@plt>:
   7dc10:      	adrp	x16, 0x85000
   7dc14:      	ldr	x17, [x16, #0x240]
   7dc18:      	add	x16, x16, #0x240
   7dc1c:      	br	x17

000000000007dc20 <_ZN17MMDetectionPlugin24setAiCropDetectionOptionERKNS_20_CropDetectionOptionER37vlai_body_in_one_setting_patch_handleR23vlai_require_set_handle@plt>:
   7dc20:      	adrp	x16, 0x85000
   7dc24:      	ldr	x17, [x16, #0x248]
   7dc28:      	add	x16, x16, #0x248
   7dc2c:      	br	x17

000000000007dc30 <_ZN17MMDetectionPlugin10CropModuleD1Ev@plt>:
   7dc30:      	adrp	x16, 0x85000
   7dc34:      	ldr	x17, [x16, #0x250]
   7dc38:      	add	x16, x16, #0x250
   7dc3c:      	br	x17

000000000007dc40 <_ZN17MMDetectionPlugin19CropDetectionResultC1Ev@plt>:
   7dc40:      	adrp	x16, 0x85000
   7dc44:      	ldr	x17, [x16, #0x258]
   7dc48:      	add	x16, x16, #0x258
   7dc4c:      	br	x17

000000000007dc50 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19CropDetectionResult8CropInfoENS_9allocatorIS3_EEE21__push_back_slow_pathIRKS3_EEPS3_OT_@plt>:
   7dc50:      	adrp	x16, 0x85000
   7dc54:      	ldr	x17, [x16, #0x260]
   7dc58:      	add	x16, x16, #0x260
   7dc5c:      	br	x17

000000000007dc60 <_ZNSt6__ndk16vectorIN17MMDetectionPlugin19CropDetectionResult7Point2fENS_9allocatorIS3_EEE18__assign_with_sizeB8ne180000IPS3_S8_EEvT_T0_l@plt>:
   7dc60:      	adrp	x16, 0x85000
   7dc64:      	ldr	x17, [x16, #0x268]
   7dc68:      	add	x16, x16, #0x268
   7dc6c:      	br	x17

000000000007dc70 <_ZN17MMDetectionPlugin19CropDetectionResultD1Ev@plt>:
   7dc70:      	adrp	x16, 0x85000
   7dc74:      	ldr	x17, [x16, #0x270]
   7dc78:      	add	x16, x16, #0x270
   7dc7c:      	br	x17

000000000007dc80 <vlai_segment_any_destroy_handle@plt>:
   7dc80:      	adrp	x16, 0x85000
   7dc84:      	ldr	x17, [x16, #0x278]
   7dc88:      	add	x16, x16, #0x278
   7dc8c:      	br	x17

000000000007dc90 <_ZN17MMDetectionPlugin18ExAnySegmentModuleD1Ev@plt>:
   7dc90:      	adrp	x16, 0x85000
   7dc94:      	ldr	x17, [x16, #0x280]
   7dc98:      	add	x16, x16, #0x280
   7dc9c:      	br	x17

000000000007dca0 <vlai_segment_any_create_handle@plt>:
   7dca0:      	adrp	x16, 0x85000
   7dca4:      	ldr	x17, [x16, #0x288]
   7dca8:      	add	x16, x16, #0x288
   7dcac:      	br	x17

000000000007dcb0 <vlai_segment_any_init@plt>:
   7dcb0:      	adrp	x16, 0x85000
   7dcb4:      	ldr	x17, [x16, #0x290]
   7dcb8:      	add	x16, x16, #0x290
   7dcbc:      	br	x17

000000000007dcc0 <vldp_create_image@plt>:
   7dcc0:      	adrp	x16, 0x85000
   7dcc4:      	ldr	x17, [x16, #0x298]
   7dcc8:      	add	x16, x16, #0x298
   7dccc:      	br	x17

000000000007dcd0 <vlai_segment_any_encode_process@plt>:
   7dcd0:      	adrp	x16, 0x85000
   7dcd4:      	ldr	x17, [x16, #0x2a0]
   7dcd8:      	add	x16, x16, #0x2a0
   7dcdc:      	br	x17

000000000007dce0 <vlai_segment_any_decode_process@plt>:
   7dce0:      	adrp	x16, 0x85000
   7dce4:      	ldr	x17, [x16, #0x2a8]
   7dce8:      	add	x16, x16, #0x2a8
   7dcec:      	br	x17

000000000007dcf0 <getauxval@plt>:
   7dcf0:      	adrp	x16, 0x85000
   7dcf4:      	ldr	x17, [x16, #0x2b0]
   7dcf8:      	add	x16, x16, #0x2b0
   7dcfc:      	br	x17

000000000007dd00 <__system_property_get@plt>:
   7dd00:      	adrp	x16, 0x85000
   7dd04:      	ldr	x17, [x16, #0x2b8]
   7dd08:      	add	x16, x16, #0x2b8
   7dd0c:      	br	x17

000000000007dd10 <strncmp@plt>:
   7dd10:      	adrp	x16, 0x85000
   7dd14:      	ldr	x17, [x16, #0x2c0]
   7dd18:      	add	x16, x16, #0x2c0
   7dd1c:      	br	x17

000000000007dd20 <fprintf@plt>:
   7dd20:      	adrp	x16, 0x85000
   7dd24:      	ldr	x17, [x16, #0x2c8]
   7dd28:      	add	x16, x16, #0x2c8
   7dd2c:      	br	x17

000000000007dd30 <fflush@plt>:
   7dd30:      	adrp	x16, 0x85000
   7dd34:      	ldr	x17, [x16, #0x2d0]
   7dd38:      	add	x16, x16, #0x2d0
   7dd3c:      	br	x17

000000000007dd40 <abort@plt>:
   7dd40:      	adrp	x16, 0x85000
   7dd44:      	ldr	x17, [x16, #0x2d8]
   7dd48:      	add	x16, x16, #0x2d8
   7dd4c:      	br	x17

000000000007dd50 <pthread_rwlock_wrlock@plt>:
   7dd50:      	adrp	x16, 0x85000
   7dd54:      	ldr	x17, [x16, #0x2e0]
   7dd58:      	add	x16, x16, #0x2e0
   7dd5c:      	br	x17

000000000007dd60 <pthread_rwlock_unlock@plt>:
   7dd60:      	adrp	x16, 0x85000
   7dd64:      	ldr	x17, [x16, #0x2e8]
   7dd68:      	add	x16, x16, #0x2e8
   7dd6c:      	br	x17

000000000007dd70 <dl_iterate_phdr@plt>:
   7dd70:      	adrp	x16, 0x85000
   7dd74:      	ldr	x17, [x16, #0x2f0]
   7dd78:      	add	x16, x16, #0x2f0
   7dd7c:      	br	x17

000000000007dd80 <pthread_rwlock_rdlock@plt>:
   7dd80:      	adrp	x16, 0x85000
   7dd84:      	ldr	x17, [x16, #0x2f8]
   7dd88:      	add	x16, x16, #0x2f8
   7dd8c:      	br	x17

000000000007dd90 <getpid@plt>:
   7dd90:      	adrp	x16, 0x85000
   7dd94:      	ldr	x17, [x16, #0x300]
   7dd98:      	add	x16, x16, #0x300
   7dd9c:      	br	x17

000000000007dda0 <syscall@plt>:
   7dda0:      	adrp	x16, 0x85000
   7dda4:      	ldr	x17, [x16, #0x308]
   7dda8:      	add	x16, x16, #0x308
   7ddac:      	br	x17

000000000007ddb0 <fwrite@plt>:
   7ddb0:      	adrp	x16, 0x85000
   7ddb4:      	ldr	x17, [x16, #0x310]
   7ddb8:      	add	x16, x16, #0x310
   7ddbc:      	br	x17
