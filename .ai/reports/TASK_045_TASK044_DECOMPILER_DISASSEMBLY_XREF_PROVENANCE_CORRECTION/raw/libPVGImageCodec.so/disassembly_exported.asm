// EXPORTED & PLT DISASSEMBLY FOR libPVGImageCodec.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGImageCodec.so (SHA-256: 7745F3A95EC533332C96AFF8D8D8C11D18E3011109741562BF3B319D3842FB1B)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 3870, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGImageCodec.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000004c2ca0 <.plt>:
  4c2ca0:      	stp	x16, x30, [sp, #-0x10]!
  4c2ca4:      	adrp	x16, 0x4e6000
  4c2ca8:      	ldr	x17, [x16, #0x390]
  4c2cac:      	add	x16, x16, #0x390
  4c2cb0:      	br	x17
  4c2cb4:      	nop
  4c2cb8:      	nop
  4c2cbc:      	nop

00000000004c2cc0 <__cxa_finalize@plt>:
  4c2cc0:      	adrp	x16, 0x4e6000
  4c2cc4:      	ldr	x17, [x16, #0x398]
  4c2cc8:      	add	x16, x16, #0x398
  4c2ccc:      	br	x17

00000000004c2cd0 <__cxa_atexit@plt>:
  4c2cd0:      	adrp	x16, 0x4e6000
  4c2cd4:      	ldr	x17, [x16, #0x3a0]
  4c2cd8:      	add	x16, x16, #0x3a0
  4c2cdc:      	br	x17

00000000004c2ce0 <_ZdlPv@plt>:
  4c2ce0:      	adrp	x16, 0x4e6000
  4c2ce4:      	ldr	x17, [x16, #0x3a8]
  4c2ce8:      	add	x16, x16, #0x3a8
  4c2cec:      	br	x17

00000000004c2cf0 <_ZNSt6__ndk15mutex4lockEv@plt>:
  4c2cf0:      	adrp	x16, 0x4e6000
  4c2cf4:      	ldr	x17, [x16, #0x3b0]
  4c2cf8:      	add	x16, x16, #0x3b0
  4c2cfc:      	br	x17

00000000004c2d00 <_ZNSt6__ndk15mutex6unlockEv@plt>:
  4c2d00:      	adrp	x16, 0x4e6000
  4c2d04:      	ldr	x17, [x16, #0x3b8]
  4c2d08:      	add	x16, x16, #0x3b8
  4c2d0c:      	br	x17

00000000004c2d10 <_ZNSt6__ndk15mutexD1Ev@plt>:
  4c2d10:      	adrp	x16, 0x4e6000
  4c2d14:      	ldr	x17, [x16, #0x3c0]
  4c2d18:      	add	x16, x16, #0x3c0
  4c2d1c:      	br	x17

00000000004c2d20 <fopen@plt>:
  4c2d20:      	adrp	x16, 0x4e6000
  4c2d24:      	ldr	x17, [x16, #0x3c8]
  4c2d28:      	add	x16, x16, #0x3c8
  4c2d2c:      	br	x17

00000000004c2d30 <fclose@plt>:
  4c2d30:      	adrp	x16, 0x4e6000
  4c2d34:      	ldr	x17, [x16, #0x3d0]
  4c2d38:      	add	x16, x16, #0x3d0
  4c2d3c:      	br	x17

00000000004c2d40 <_ZN8PVGIMAGE16getPVGIccProfileENS_14ColorSpaceTypeE@plt>:
  4c2d40:      	adrp	x16, 0x4e6000
  4c2d44:      	ldr	x17, [x16, #0x3d8]
  4c2d48:      	add	x16, x16, #0x3d8
  4c2d4c:      	br	x17

00000000004c2d50 <_ZN8PVGIMAGE22getPVGIccProfileLengthENS_14ColorSpaceTypeE@plt>:
  4c2d50:      	adrp	x16, 0x4e6000
  4c2d54:      	ldr	x17, [x16, #0x3e0]
  4c2d58:      	add	x16, x16, #0x3e0
  4c2d5c:      	br	x17

00000000004c2d60 <malloc@plt>:
  4c2d60:      	adrp	x16, 0x4e6000
  4c2d64:      	ldr	x17, [x16, #0x3e8]
  4c2d68:      	add	x16, x16, #0x3e8
  4c2d6c:      	br	x17

00000000004c2d70 <inflateInit2_@plt>:
  4c2d70:      	adrp	x16, 0x4e6000
  4c2d74:      	ldr	x17, [x16, #0x3f0]
  4c2d78:      	add	x16, x16, #0x3f0
  4c2d7c:      	br	x17

00000000004c2d80 <realloc@plt>:
  4c2d80:      	adrp	x16, 0x4e6000
  4c2d84:      	ldr	x17, [x16, #0x3f8]
  4c2d88:      	add	x16, x16, #0x3f8
  4c2d8c:      	br	x17

00000000004c2d90 <inflate@plt>:
  4c2d90:      	adrp	x16, 0x4e6000
  4c2d94:      	ldr	x17, [x16, #0x400]
  4c2d98:      	add	x16, x16, #0x400
  4c2d9c:      	br	x17

00000000004c2da0 <inflateEnd@plt>:
  4c2da0:      	adrp	x16, 0x4e6000
  4c2da4:      	ldr	x17, [x16, #0x408]
  4c2da8:      	add	x16, x16, #0x408
  4c2dac:      	br	x17

00000000004c2db0 <pthread_self@plt>:
  4c2db0:      	adrp	x16, 0x4e6000
  4c2db4:      	ldr	x17, [x16, #0x410]
  4c2db8:      	add	x16, x16, #0x410
  4c2dbc:      	br	x17

00000000004c2dc0 <__android_log_print@plt>:
  4c2dc0:      	adrp	x16, 0x4e6000
  4c2dc4:      	ldr	x17, [x16, #0x418]
  4c2dc8:      	add	x16, x16, #0x418
  4c2dcc:      	br	x17

00000000004c2dd0 <__stack_chk_fail@plt>:
  4c2dd0:      	adrp	x16, 0x4e6000
  4c2dd4:      	ldr	x17, [x16, #0x420]
  4c2dd8:      	add	x16, x16, #0x420
  4c2ddc:      	br	x17

00000000004c2de0 <free@plt>:
  4c2de0:      	adrp	x16, 0x4e6000
  4c2de4:      	ldr	x17, [x16, #0x428]
  4c2de8:      	add	x16, x16, #0x428
  4c2dec:      	br	x17

00000000004c2df0 <pthread_getspecific@plt>:
  4c2df0:      	adrp	x16, 0x4e6000
  4c2df4:      	ldr	x17, [x16, #0x430]
  4c2df8:      	add	x16, x16, #0x430
  4c2dfc:      	br	x17

00000000004c2e00 <pthread_setspecific@plt>:
  4c2e00:      	adrp	x16, 0x4e6000
  4c2e04:      	ldr	x17, [x16, #0x438]
  4c2e08:      	add	x16, x16, #0x438
  4c2e0c:      	br	x17

00000000004c2e10 <strlen@plt>:
  4c2e10:      	adrp	x16, 0x4e6000
  4c2e14:      	ldr	x17, [x16, #0x440]
  4c2e18:      	add	x16, x16, #0x440
  4c2e1c:      	br	x17

00000000004c2e20 <_Znwm@plt>:
  4c2e20:      	adrp	x16, 0x4e6000
  4c2e24:      	ldr	x17, [x16, #0x448]
  4c2e28:      	add	x16, x16, #0x448
  4c2e2c:      	br	x17

00000000004c2e30 <memmove@plt>:
  4c2e30:      	adrp	x16, 0x4e6000
  4c2e34:      	ldr	x17, [x16, #0x450]
  4c2e38:      	add	x16, x16, #0x450
  4c2e3c:      	br	x17

00000000004c2e40 <__cxa_allocate_exception@plt>:
  4c2e40:      	adrp	x16, 0x4e6000
  4c2e44:      	ldr	x17, [x16, #0x458]
  4c2e48:      	add	x16, x16, #0x458
  4c2e4c:      	br	x17

00000000004c2e50 <__cxa_throw@plt>:
  4c2e50:      	adrp	x16, 0x4e6000
  4c2e54:      	ldr	x17, [x16, #0x460]
  4c2e58:      	add	x16, x16, #0x460
  4c2e5c:      	br	x17

00000000004c2e60 <__cxa_free_exception@plt>:
  4c2e60:      	adrp	x16, 0x4e6000
  4c2e64:      	ldr	x17, [x16, #0x468]
  4c2e68:      	add	x16, x16, #0x468
  4c2e6c:      	br	x17

00000000004c2e70 <_ZNSt11logic_errorC2EPKc@plt>:
  4c2e70:      	adrp	x16, 0x4e6000
  4c2e74:      	ldr	x17, [x16, #0x470]
  4c2e78:      	add	x16, x16, #0x470
  4c2e7c:      	br	x17

00000000004c2e80 <_ZN8PVGIMAGE9PVGGlobal11getInstanceEv@plt>:
  4c2e80:      	adrp	x16, 0x4e6000
  4c2e84:      	ldr	x17, [x16, #0x478]
  4c2e88:      	add	x16, x16, #0x478
  4c2e8c:      	br	x17

00000000004c2e90 <_ZN8PVGIMAGE9PVGGlobalC1Ev@plt>:
  4c2e90:      	adrp	x16, 0x4e6000
  4c2e94:      	ldr	x17, [x16, #0x480]
  4c2e98:      	add	x16, x16, #0x480
  4c2e9c:      	br	x17

00000000004c2ea0 <_ZN8PVGIMAGE9PVGGlobal10getHDRListEv@plt>:
  4c2ea0:      	adrp	x16, 0x4e6000
  4c2ea4:      	ldr	x17, [x16, #0x488]
  4c2ea8:      	add	x16, x16, #0x488
  4c2eac:      	br	x17

00000000004c2eb0 <__cxa_begin_catch@plt>:
  4c2eb0:      	adrp	x16, 0x4e6000
  4c2eb4:      	ldr	x17, [x16, #0x490]
  4c2eb8:      	add	x16, x16, #0x490
  4c2ebc:      	br	x17

00000000004c2ec0 <_ZSt9terminatev@plt>:
  4c2ec0:      	adrp	x16, 0x4e6000
  4c2ec4:      	ldr	x17, [x16, #0x498]
  4c2ec8:      	add	x16, x16, #0x498
  4c2ecc:      	br	x17

00000000004c2ed0 <memcmp@plt>:
  4c2ed0:      	adrp	x16, 0x4e6000
  4c2ed4:      	ldr	x17, [x16, #0x4a0]
  4c2ed8:      	add	x16, x16, #0x4a0
  4c2edc:      	br	x17

00000000004c2ee0 <_ZNSt6__ndk112__next_primeEm@plt>:
  4c2ee0:      	adrp	x16, 0x4e6000
  4c2ee4:      	ldr	x17, [x16, #0x4a8]
  4c2ee8:      	add	x16, x16, #0x4a8
  4c2eec:      	br	x17

00000000004c2ef0 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  4c2ef0:      	adrp	x16, 0x4e6000
  4c2ef4:      	ldr	x17, [x16, #0x4b0]
  4c2ef8:      	add	x16, x16, #0x4b0
  4c2efc:      	br	x17

00000000004c2f00 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  4c2f00:      	adrp	x16, 0x4e6000
  4c2f04:      	ldr	x17, [x16, #0x4b8]
  4c2f08:      	add	x16, x16, #0x4b8
  4c2f0c:      	br	x17

00000000004c2f10 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  4c2f10:      	adrp	x16, 0x4e6000
  4c2f14:      	ldr	x17, [x16, #0x4c0]
  4c2f18:      	add	x16, x16, #0x4c0
  4c2f1c:      	br	x17

00000000004c2f20 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
  4c2f20:      	adrp	x16, 0x4e6000
  4c2f24:      	ldr	x17, [x16, #0x4c8]
  4c2f28:      	add	x16, x16, #0x4c8
  4c2f2c:      	br	x17

00000000004c2f30 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
  4c2f30:      	adrp	x16, 0x4e6000
  4c2f34:      	ldr	x17, [x16, #0x4d0]
  4c2f38:      	add	x16, x16, #0x4d0
  4c2f3c:      	br	x17

00000000004c2f40 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
  4c2f40:      	adrp	x16, 0x4e6000
  4c2f44:      	ldr	x17, [x16, #0x4d8]
  4c2f48:      	add	x16, x16, #0x4d8
  4c2f4c:      	br	x17

00000000004c2f50 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  4c2f50:      	adrp	x16, 0x4e6000
  4c2f54:      	ldr	x17, [x16, #0x4e0]
  4c2f58:      	add	x16, x16, #0x4e0
  4c2f5c:      	br	x17

00000000004c2f60 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  4c2f60:      	adrp	x16, 0x4e6000
  4c2f64:      	ldr	x17, [x16, #0x4e8]
  4c2f68:      	add	x16, x16, #0x4e8
  4c2f6c:      	br	x17

00000000004c2f70 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
  4c2f70:      	adrp	x16, 0x4e6000
  4c2f74:      	ldr	x17, [x16, #0x4f0]
  4c2f78:      	add	x16, x16, #0x4f0
  4c2f7c:      	br	x17

00000000004c2f80 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  4c2f80:      	adrp	x16, 0x4e6000
  4c2f84:      	ldr	x17, [x16, #0x4f8]
  4c2f88:      	add	x16, x16, #0x4f8
  4c2f8c:      	br	x17

00000000004c2f90 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  4c2f90:      	adrp	x16, 0x4e6000
  4c2f94:      	ldr	x17, [x16, #0x500]
  4c2f98:      	add	x16, x16, #0x500
  4c2f9c:      	br	x17

00000000004c2fa0 <_ZNSt6__ndk16localeD1Ev@plt>:
  4c2fa0:      	adrp	x16, 0x4e6000
  4c2fa4:      	ldr	x17, [x16, #0x508]
  4c2fa8:      	add	x16, x16, #0x508
  4c2fac:      	br	x17

00000000004c2fb0 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  4c2fb0:      	adrp	x16, 0x4e6000
  4c2fb4:      	ldr	x17, [x16, #0x510]
  4c2fb8:      	add	x16, x16, #0x510
  4c2fbc:      	br	x17

00000000004c2fc0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
  4c2fc0:      	adrp	x16, 0x4e6000
  4c2fc4:      	ldr	x17, [x16, #0x518]
  4c2fc8:      	add	x16, x16, #0x518
  4c2fcc:      	br	x17

00000000004c2fd0 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
  4c2fd0:      	adrp	x16, 0x4e6000
  4c2fd4:      	ldr	x17, [x16, #0x520]
  4c2fd8:      	add	x16, x16, #0x520
  4c2fdc:      	br	x17

00000000004c2fe0 <__cxa_end_catch@plt>:
  4c2fe0:      	adrp	x16, 0x4e6000
  4c2fe4:      	ldr	x17, [x16, #0x528]
  4c2fe8:      	add	x16, x16, #0x528
  4c2fec:      	br	x17

00000000004c2ff0 <memset@plt>:
  4c2ff0:      	adrp	x16, 0x4e6000
  4c2ff4:      	ldr	x17, [x16, #0x530]
  4c2ff8:      	add	x16, x16, #0x530
  4c2ffc:      	br	x17

00000000004c3000 <_ZNK8PVGIMAGE8PVGFrame24getPresentationTimestampEv@plt>:
  4c3000:      	adrp	x16, 0x4e6000
  4c3004:      	ldr	x17, [x16, #0x538]
  4c3008:      	add	x16, x16, #0x538
  4c300c:      	br	x17

00000000004c3010 <_ZNK8PVGIMAGE8PVGFrame9getFormatEv@plt>:
  4c3010:      	adrp	x16, 0x4e6000
  4c3014:      	ldr	x17, [x16, #0x540]
  4c3018:      	add	x16, x16, #0x540
  4c301c:      	br	x17

00000000004c3020 <_ZNK8PVGIMAGE8PVGFrame8getWidthEv@plt>:
  4c3020:      	adrp	x16, 0x4e6000
  4c3024:      	ldr	x17, [x16, #0x548]
  4c3028:      	add	x16, x16, #0x548
  4c302c:      	br	x17

00000000004c3030 <_ZNK8PVGIMAGE8PVGFrame9getHeightEv@plt>:
  4c3030:      	adrp	x16, 0x4e6000
  4c3034:      	ldr	x17, [x16, #0x550]
  4c3038:      	add	x16, x16, #0x550
  4c303c:      	br	x17

00000000004c3040 <_ZNK8PVGIMAGE8PVGFrame12getPlaneDataEi@plt>:
  4c3040:      	adrp	x16, 0x4e6000
  4c3044:      	ldr	x17, [x16, #0x558]
  4c3048:      	add	x16, x16, #0x558
  4c304c:      	br	x17

00000000004c3050 <_ZNK8PVGIMAGE10PVGContext17getImageCodecTypeEv@plt>:
  4c3050:      	adrp	x16, 0x4e6000
  4c3054:      	ldr	x17, [x16, #0x560]
  4c3058:      	add	x16, x16, #0x560
  4c305c:      	br	x17

00000000004c3060 <_ZNK8PVGIMAGE10PVGContext8getCodecEv@plt>:
  4c3060:      	adrp	x16, 0x4e6000
  4c3064:      	ldr	x17, [x16, #0x568]
  4c3068:      	add	x16, x16, #0x568
  4c306c:      	br	x17

00000000004c3070 <strcmp@plt>:
  4c3070:      	adrp	x16, 0x4e6000
  4c3074:      	ldr	x17, [x16, #0x570]
  4c3078:      	add	x16, x16, #0x570
  4c307c:      	br	x17

00000000004c3080 <_ZNK8PVGIMAGE10PVGContext13getDimensionXEv@plt>:
  4c3080:      	adrp	x16, 0x4e6000
  4c3084:      	ldr	x17, [x16, #0x578]
  4c3088:      	add	x16, x16, #0x578
  4c308c:      	br	x17

00000000004c3090 <_ZNK8PVGIMAGE10PVGContext13getDimensionYEv@plt>:
  4c3090:      	adrp	x16, 0x4e6000
  4c3094:      	ldr	x17, [x16, #0x580]
  4c3098:      	add	x16, x16, #0x580
  4c309c:      	br	x17

00000000004c30a0 <_ZN8PVGIMAGE10PVGContext18getImageOutQualityEv@plt>:
  4c30a0:      	adrp	x16, 0x4e6000
  4c30a4:      	ldr	x17, [x16, #0x588]
  4c30a8:      	add	x16, x16, #0x588
  4c30ac:      	br	x17

00000000004c30b0 <_ZNK8PVGIMAGE10PVGContext18getImageOutputPathEv@plt>:
  4c30b0:      	adrp	x16, 0x4e6000
  4c30b4:      	ldr	x17, [x16, #0x590]
  4c30b8:      	add	x16, x16, #0x590
  4c30bc:      	br	x17

00000000004c30c0 <_ZN8PVGIMAGE3RefC2Ev@plt>:
  4c30c0:      	adrp	x16, 0x4e6000
  4c30c4:      	ldr	x17, [x16, #0x598]
  4c30c8:      	add	x16, x16, #0x598
  4c30cc:      	br	x17

00000000004c30d0 <_ZN8PVGIMAGE3RefD2Ev@plt>:
  4c30d0:      	adrp	x16, 0x4e6000
  4c30d4:      	ldr	x17, [x16, #0x5a0]
  4c30d8:      	add	x16, x16, #0x5a0
  4c30dc:      	br	x17

00000000004c30e0 <_ZN8PVGIMAGE8PVGFrame9setFormatENS_9PVGFormatE@plt>:
  4c30e0:      	adrp	x16, 0x4e6000
  4c30e4:      	ldr	x17, [x16, #0x5a8]
  4c30e8:      	add	x16, x16, #0x5a8
  4c30ec:      	br	x17

00000000004c30f0 <_ZNK8PVGIMAGE8PVGFrame21getPremultipliedAlphaEv@plt>:
  4c30f0:      	adrp	x16, 0x4e6000
  4c30f4:      	ldr	x17, [x16, #0x5b0]
  4c30f8:      	add	x16, x16, #0x5b0
  4c30fc:      	br	x17

00000000004c3100 <_ZN8PVGIMAGE8PVGFrame21setPremultipliedAlphaEb@plt>:
  4c3100:      	adrp	x16, 0x4e6000
  4c3104:      	ldr	x17, [x16, #0x5b8]
  4c3108:      	add	x16, x16, #0x5b8
  4c310c:      	br	x17

00000000004c3110 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  4c3110:      	adrp	x16, 0x4e6000
  4c3114:      	ldr	x17, [x16, #0x5c0]
  4c3118:      	add	x16, x16, #0x5c0
  4c311c:      	br	x17

00000000004c3120 <memchr@plt>:
  4c3120:      	adrp	x16, 0x4e6000
  4c3124:      	ldr	x17, [x16, #0x5c8]
  4c3128:      	add	x16, x16, #0x5c8
  4c312c:      	br	x17

00000000004c3130 <setjmp@plt>:
  4c3130:      	adrp	x16, 0x4e6000
  4c3134:      	ldr	x17, [x16, #0x5d0]
  4c3138:      	add	x16, x16, #0x5d0
  4c313c:      	br	x17

00000000004c3140 <_ZN8PVGIMAGE10ColorSpace10ColorSpace21makeRGBFromICCProfileEPKhmRKNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE@plt>:
  4c3140:      	adrp	x16, 0x4e6000
  4c3144:      	ldr	x17, [x16, #0x5d8]
  4c3148:      	add	x16, x16, #0x5d8
  4c314c:      	br	x17

00000000004c3150 <longjmp@plt>:
  4c3150:      	adrp	x16, 0x4e6000
  4c3154:      	ldr	x17, [x16, #0x5e0]
  4c3158:      	add	x16, x16, #0x5e0
  4c315c:      	br	x17

00000000004c3160 <_ZN8PVGIMAGE8PVGFrame6createEv@plt>:
  4c3160:      	adrp	x16, 0x4e6000
  4c3164:      	ldr	x17, [x16, #0x5e8]
  4c3168:      	add	x16, x16, #0x5e8
  4c316c:      	br	x17

00000000004c3170 <_ZN8PVGIMAGE8PVGFrame12setDimensionEii@plt>:
  4c3170:      	adrp	x16, 0x4e6000
  4c3174:      	ldr	x17, [x16, #0x5f0]
  4c3178:      	add	x16, x16, #0x5f0
  4c317c:      	br	x17

00000000004c3180 <_ZN8PVGIMAGE8PVGFrame11allocBufferEv@plt>:
  4c3180:      	adrp	x16, 0x4e6000
  4c3184:      	ldr	x17, [x16, #0x5f8]
  4c3188:      	add	x16, x16, #0x5f8
  4c318c:      	br	x17

00000000004c3190 <_ZNK8PVGIMAGE8PVGFrame11getHardwareEv@plt>:
  4c3190:      	adrp	x16, 0x4e6000
  4c3194:      	ldr	x17, [x16, #0x600]
  4c3198:      	add	x16, x16, #0x600
  4c319c:      	br	x17

00000000004c31a0 <_ZN8PVGIMAGE10PVGContext11getFileInfoEv@plt>:
  4c31a0:      	adrp	x16, 0x4e6000
  4c31a4:      	ldr	x17, [x16, #0x608]
  4c31a8:      	add	x16, x16, #0x608
  4c31ac:      	br	x17

00000000004c31b0 <_ZN8PVGIMAGE10PVGContext16getImageScaleNumEv@plt>:
  4c31b0:      	adrp	x16, 0x4e6000
  4c31b4:      	ldr	x17, [x16, #0x610]
  4c31b8:      	add	x16, x16, #0x610
  4c31bc:      	br	x17

00000000004c31c0 <_ZN8PVGIMAGE10PVGContext18getImageScaleDenomEv@plt>:
  4c31c0:      	adrp	x16, 0x4e6000
  4c31c4:      	ldr	x17, [x16, #0x618]
  4c31c8:      	add	x16, x16, #0x618
  4c31cc:      	br	x17

00000000004c31d0 <_ZN8PVGIMAGE10PVGContext19getEncodeBufferModeEv@plt>:
  4c31d0:      	adrp	x16, 0x4e6000
  4c31d4:      	ldr	x17, [x16, #0x620]
  4c31d8:      	add	x16, x16, #0x620
  4c31dc:      	br	x17

00000000004c31e0 <_ZN8PVGIMAGE10PVGContext13getBufferInfoEv@plt>:
  4c31e0:      	adrp	x16, 0x4e6000
  4c31e4:      	ldr	x17, [x16, #0x628]
  4c31e8:      	add	x16, x16, #0x628
  4c31ec:      	br	x17

00000000004c31f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  4c31f0:      	adrp	x16, 0x4e6000
  4c31f4:      	ldr	x17, [x16, #0x630]
  4c31f8:      	add	x16, x16, #0x630
  4c31fc:      	br	x17

00000000004c3200 <_ZN8PVGIMAGE10PVGContext16getIccBufferInfoEv@plt>:
  4c3200:      	adrp	x16, 0x4e6000
  4c3204:      	ldr	x17, [x16, #0x638]
  4c3208:      	add	x16, x16, #0x638
  4c320c:      	br	x17

00000000004c3210 <_ZN8PVGIMAGE10PVGContext13getParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  4c3210:      	adrp	x16, 0x4e6000
  4c3214:      	ldr	x17, [x16, #0x640]
  4c3218:      	add	x16, x16, #0x640
  4c321c:      	br	x17

00000000004c3220 <atoi@plt>:
  4c3220:      	adrp	x16, 0x4e6000
  4c3224:      	ldr	x17, [x16, #0x648]
  4c3228:      	add	x16, x16, #0x648
  4c322c:      	br	x17

00000000004c3230 <_ZNK8PVGIMAGE10PVGContext18getImageColorSpaceEv@plt>:
  4c3230:      	adrp	x16, 0x4e6000
  4c3234:      	ldr	x17, [x16, #0x650]
  4c3238:      	add	x16, x16, #0x650
  4c323c:      	br	x17

00000000004c3240 <__strlen_chk@plt>:
  4c3240:      	adrp	x16, 0x4e6000
  4c3244:      	ldr	x17, [x16, #0x658]
  4c3248:      	add	x16, x16, #0x658
  4c324c:      	br	x17

00000000004c3250 <memcpy@plt>:
  4c3250:      	adrp	x16, 0x4e6000
  4c3254:      	ldr	x17, [x16, #0x660]
  4c3258:      	add	x16, x16, #0x660
  4c325c:      	br	x17

00000000004c3260 <_ZNK8PVGIMAGE8PVGFrame16getPlaneLinesizeEi@plt>:
  4c3260:      	adrp	x16, 0x4e6000
  4c3264:      	ldr	x17, [x16, #0x668]
  4c3268:      	add	x16, x16, #0x668
  4c326c:      	br	x17

00000000004c3270 <_ZN8PVGIMAGE13PVGImageCodecD1Ev@plt>:
  4c3270:      	adrp	x16, 0x4e6000
  4c3274:      	ldr	x17, [x16, #0x670]
  4c3278:      	add	x16, x16, #0x670
  4c327c:      	br	x17

00000000004c3280 <_ZnwmRKSt9nothrow_t@plt>:
  4c3280:      	adrp	x16, 0x4e6000
  4c3284:      	ldr	x17, [x16, #0x678]
  4c3288:      	add	x16, x16, #0x678
  4c328c:      	br	x17

00000000004c3290 <_ZN8PVGIMAGE13PVGImageCodecC1Ev@plt>:
  4c3290:      	adrp	x16, 0x4e6000
  4c3294:      	ldr	x17, [x16, #0x680]
  4c3298:      	add	x16, x16, #0x680
  4c329c:      	br	x17

00000000004c32a0 <ftell@plt>:
  4c32a0:      	adrp	x16, 0x4e6000
  4c32a4:      	ldr	x17, [x16, #0x688]
  4c32a8:      	add	x16, x16, #0x688
  4c32ac:      	br	x17

00000000004c32b0 <fseek@plt>:
  4c32b0:      	adrp	x16, 0x4e6000
  4c32b4:      	ldr	x17, [x16, #0x690]
  4c32b8:      	add	x16, x16, #0x690
  4c32bc:      	br	x17

00000000004c32c0 <fread@plt>:
  4c32c0:      	adrp	x16, 0x4e6000
  4c32c4:      	ldr	x17, [x16, #0x698]
  4c32c8:      	add	x16, x16, #0x698
  4c32cc:      	br	x17

00000000004c32d0 <_ZdlPvRKSt9nothrow_t@plt>:
  4c32d0:      	adrp	x16, 0x4e6000
  4c32d4:      	ldr	x17, [x16, #0x6a0]
  4c32d8:      	add	x16, x16, #0x6a0
  4c32dc:      	br	x17

00000000004c32e0 <__vsprintf_chk@plt>:
  4c32e0:      	adrp	x16, 0x4e6000
  4c32e4:      	ldr	x17, [x16, #0x6a8]
  4c32e8:      	add	x16, x16, #0x6a8
  4c32ec:      	br	x17

00000000004c32f0 <__errno@plt>:
  4c32f0:      	adrp	x16, 0x4e6000
  4c32f4:      	ldr	x17, [x16, #0x6b0]
  4c32f8:      	add	x16, x16, #0x6b0
  4c32fc:      	br	x17

00000000004c3300 <__strcpy_chk@plt>:
  4c3300:      	adrp	x16, 0x4e6000
  4c3304:      	ldr	x17, [x16, #0x6b8]
  4c3308:      	add	x16, x16, #0x6b8
  4c330c:      	br	x17

00000000004c3310 <_ZN8PVGIMAGE8PVGFrameC1Ev@plt>:
  4c3310:      	adrp	x16, 0x4e6000
  4c3314:      	ldr	x17, [x16, #0x6c0]
  4c3318:      	add	x16, x16, #0x6c0
  4c331c:      	br	x17

00000000004c3320 <_ZN8PVGIMAGE10PVGContextD1Ev@plt>:
  4c3320:      	adrp	x16, 0x4e6000
  4c3324:      	ldr	x17, [x16, #0x6c8]
  4c3328:      	add	x16, x16, #0x6c8
  4c332c:      	br	x17

00000000004c3330 <_ZN8PVGIMAGE8PVGFrameD1Ev@plt>:
  4c3330:      	adrp	x16, 0x4e6000
  4c3334:      	ldr	x17, [x16, #0x6d0]
  4c3338:      	add	x16, x16, #0x6d0
  4c333c:      	br	x17

00000000004c3340 <_ZNK8PVGIMAGE8PVGFrame14getFrameStrideEv@plt>:
  4c3340:      	adrp	x16, 0x4e6000
  4c3344:      	ldr	x17, [x16, #0x6d8]
  4c3348:      	add	x16, x16, #0x6d8
  4c334c:      	br	x17

00000000004c3350 <_ZN8PVGIMAGE15PVGExiv2ManagerC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  4c3350:      	adrp	x16, 0x4e6000
  4c3354:      	ldr	x17, [x16, #0x6e0]
  4c3358:      	add	x16, x16, #0x6e0
  4c335c:      	br	x17

00000000004c3360 <_ZN8PVGIMAGE15PVGExiv2ManagerC1EPKhl@plt>:
  4c3360:      	adrp	x16, 0x4e6000
  4c3364:      	ldr	x17, [x16, #0x6e8]
  4c3368:      	add	x16, x16, #0x6e8
  4c336c:      	br	x17

00000000004c3370 <_ZN8PVGIMAGE15PVGExiv2ManagerD1Ev@plt>:
  4c3370:      	adrp	x16, 0x4e6000
  4c3374:      	ldr	x17, [x16, #0x6f0]
  4c3378:      	add	x16, x16, #0x6f0
  4c337c:      	br	x17

00000000004c3380 <_ZN8PVGIMAGE3RefD1Ev@plt>:
  4c3380:      	adrp	x16, 0x4e6000
  4c3384:      	ldr	x17, [x16, #0x6f8]
  4c3388:      	add	x16, x16, #0x6f8
  4c338c:      	br	x17

00000000004c3390 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
  4c3390:      	adrp	x16, 0x4e6000
  4c3394:      	ldr	x17, [x16, #0x700]
  4c3398:      	add	x16, x16, #0x700
  4c339c:      	br	x17

00000000004c33a0 <__memcpy_chk@plt>:
  4c33a0:      	adrp	x16, 0x4e6000
  4c33a4:      	ldr	x17, [x16, #0x708]
  4c33a8:      	add	x16, x16, #0x708
  4c33ac:      	br	x17

00000000004c33b0 <powf@plt>:
  4c33b0:      	adrp	x16, 0x4e6000
  4c33b4:      	ldr	x17, [x16, #0x710]
  4c33b8:      	add	x16, x16, #0x710
  4c33bc:      	br	x17

00000000004c33c0 <strtol@plt>:
  4c33c0:      	adrp	x16, 0x4e6000
  4c33c4:      	ldr	x17, [x16, #0x718]
  4c33c8:      	add	x16, x16, #0x718
  4c33cc:      	br	x17

00000000004c33d0 <strncmp@plt>:
  4c33d0:      	adrp	x16, 0x4e6000
  4c33d4:      	ldr	x17, [x16, #0x720]
  4c33d8:      	add	x16, x16, #0x720
  4c33dc:      	br	x17

00000000004c33e0 <ldexpf@plt>:
  4c33e0:      	adrp	x16, 0x4e6000
  4c33e4:      	ldr	x17, [x16, #0x728]
  4c33e8:      	add	x16, x16, #0x728
  4c33ec:      	br	x17

00000000004c33f0 <pow@plt>:
  4c33f0:      	adrp	x16, 0x4e6000
  4c33f4:      	ldr	x17, [x16, #0x730]
  4c33f8:      	add	x16, x16, #0x730
  4c33fc:      	br	x17

00000000004c3400 <log10@plt>:
  4c3400:      	adrp	x16, 0x4e6000
  4c3404:      	ldr	x17, [x16, #0x738]
  4c3408:      	add	x16, x16, #0x738
  4c340c:      	br	x17

00000000004c3410 <exp@plt>:
  4c3410:      	adrp	x16, 0x4e6000
  4c3414:      	ldr	x17, [x16, #0x740]
  4c3418:      	add	x16, x16, #0x740
  4c341c:      	br	x17

00000000004c3420 <atof@plt>:
  4c3420:      	adrp	x16, 0x4e6000
  4c3424:      	ldr	x17, [x16, #0x748]
  4c3428:      	add	x16, x16, #0x748
  4c342c:      	br	x17

00000000004c3430 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
  4c3430:      	adrp	x16, 0x4e6000
  4c3434:      	ldr	x17, [x16, #0x750]
  4c3438:      	add	x16, x16, #0x750
  4c343c:      	br	x17

00000000004c3440 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
  4c3440:      	adrp	x16, 0x4e6000
  4c3444:      	ldr	x17, [x16, #0x758]
  4c3448:      	add	x16, x16, #0x758
  4c344c:      	br	x17

00000000004c3450 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
  4c3450:      	adrp	x16, 0x4e6000
  4c3454:      	ldr	x17, [x16, #0x760]
  4c3458:      	add	x16, x16, #0x760
  4c345c:      	br	x17

00000000004c3460 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
  4c3460:      	adrp	x16, 0x4e6000
  4c3464:      	ldr	x17, [x16, #0x768]
  4c3468:      	add	x16, x16, #0x768
  4c346c:      	br	x17

00000000004c3470 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
  4c3470:      	adrp	x16, 0x4e6000
  4c3474:      	ldr	x17, [x16, #0x770]
  4c3478:      	add	x16, x16, #0x770
  4c347c:      	br	x17

00000000004c3480 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
  4c3480:      	adrp	x16, 0x4e6000
  4c3484:      	ldr	x17, [x16, #0x778]
  4c3488:      	add	x16, x16, #0x778
  4c348c:      	br	x17

00000000004c3490 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
  4c3490:      	adrp	x16, 0x4e6000
  4c3494:      	ldr	x17, [x16, #0x780]
  4c3498:      	add	x16, x16, #0x780
  4c349c:      	br	x17

00000000004c34a0 <WebPInitDecoderConfigInternal@plt>:
  4c34a0:      	adrp	x16, 0x4e6000
  4c34a4:      	ldr	x17, [x16, #0x788]
  4c34a8:      	add	x16, x16, #0x788
  4c34ac:      	br	x17

00000000004c34b0 <WebPGetFeaturesInternal@plt>:
  4c34b0:      	adrp	x16, 0x4e6000
  4c34b4:      	ldr	x17, [x16, #0x790]
  4c34b8:      	add	x16, x16, #0x790
  4c34bc:      	br	x17

00000000004c34c0 <WebPDemuxInternal@plt>:
  4c34c0:      	adrp	x16, 0x4e6000
  4c34c4:      	ldr	x17, [x16, #0x798]
  4c34c8:      	add	x16, x16, #0x798
  4c34cc:      	br	x17

00000000004c34d0 <WebPDemuxGetFrame@plt>:
  4c34d0:      	adrp	x16, 0x4e6000
  4c34d4:      	ldr	x17, [x16, #0x7a0]
  4c34d8:      	add	x16, x16, #0x7a0
  4c34dc:      	br	x17

00000000004c34e0 <WebPDemuxDelete@plt>:
  4c34e0:      	adrp	x16, 0x4e6000
  4c34e4:      	ldr	x17, [x16, #0x7a8]
  4c34e8:      	add	x16, x16, #0x7a8
  4c34ec:      	br	x17

00000000004c34f0 <WebPFree@plt>:
  4c34f0:      	adrp	x16, 0x4e6000
  4c34f4:      	ldr	x17, [x16, #0x7b0]
  4c34f8:      	add	x16, x16, #0x7b0
  4c34fc:      	br	x17

00000000004c3500 <WebPDecodeRGBA@plt>:
  4c3500:      	adrp	x16, 0x4e6000
  4c3504:      	ldr	x17, [x16, #0x7b8]
  4c3508:      	add	x16, x16, #0x7b8
  4c350c:      	br	x17

00000000004c3510 <WebPDecodeRGB@plt>:
  4c3510:      	adrp	x16, 0x4e6000
  4c3514:      	ldr	x17, [x16, #0x7c0]
  4c3518:      	add	x16, x16, #0x7c0
  4c351c:      	br	x17

00000000004c3520 <WebPAnimEncoderOptionsInitInternal@plt>:
  4c3520:      	adrp	x16, 0x4e6000
  4c3524:      	ldr	x17, [x16, #0x7c8]
  4c3528:      	add	x16, x16, #0x7c8
  4c352c:      	br	x17

00000000004c3530 <WebPAnimEncoderNewInternal@plt>:
  4c3530:      	adrp	x16, 0x4e6000
  4c3534:      	ldr	x17, [x16, #0x7d0]
  4c3538:      	add	x16, x16, #0x7d0
  4c353c:      	br	x17

00000000004c3540 <WebPPictureInitInternal@plt>:
  4c3540:      	adrp	x16, 0x4e6000
  4c3544:      	ldr	x17, [x16, #0x7d8]
  4c3548:      	add	x16, x16, #0x7d8
  4c354c:      	br	x17

00000000004c3550 <WebPPictureImportRGB@plt>:
  4c3550:      	adrp	x16, 0x4e6000
  4c3554:      	ldr	x17, [x16, #0x7e0]
  4c3558:      	add	x16, x16, #0x7e0
  4c355c:      	br	x17

00000000004c3560 <WebPPictureImportRGBA@plt>:
  4c3560:      	adrp	x16, 0x4e6000
  4c3564:      	ldr	x17, [x16, #0x7e8]
  4c3568:      	add	x16, x16, #0x7e8
  4c356c:      	br	x17

00000000004c3570 <WebPConfigInitInternal@plt>:
  4c3570:      	adrp	x16, 0x4e6000
  4c3574:      	ldr	x17, [x16, #0x7f0]
  4c3578:      	add	x16, x16, #0x7f0
  4c357c:      	br	x17

00000000004c3580 <WebPAnimEncoderAdd@plt>:
  4c3580:      	adrp	x16, 0x4e6000
  4c3584:      	ldr	x17, [x16, #0x7f8]
  4c3588:      	add	x16, x16, #0x7f8
  4c358c:      	br	x17

00000000004c3590 <WebPPictureFree@plt>:
  4c3590:      	adrp	x16, 0x4e6000
  4c3594:      	ldr	x17, [x16, #0x800]
  4c3598:      	add	x16, x16, #0x800
  4c359c:      	br	x17

00000000004c35a0 <WebPAnimEncoderAssemble@plt>:
  4c35a0:      	adrp	x16, 0x4e6000
  4c35a4:      	ldr	x17, [x16, #0x808]
  4c35a8:      	add	x16, x16, #0x808
  4c35ac:      	br	x17

00000000004c35b0 <fwrite@plt>:
  4c35b0:      	adrp	x16, 0x4e6000
  4c35b4:      	ldr	x17, [x16, #0x810]
  4c35b8:      	add	x16, x16, #0x810
  4c35bc:      	br	x17

00000000004c35c0 <WebPAnimEncoderDelete@plt>:
  4c35c0:      	adrp	x16, 0x4e6000
  4c35c4:      	ldr	x17, [x16, #0x818]
  4c35c8:      	add	x16, x16, #0x818
  4c35cc:      	br	x17

00000000004c35d0 <_ZNK8PVGIMAGE10ColorSpace10ColorSpace8toLinearERKNS0_7details5TVec3IfEE@plt>:
  4c35d0:      	adrp	x16, 0x4e6000
  4c35d4:      	ldr	x17, [x16, #0x820]
  4c35d8:      	add	x16, x16, #0x820
  4c35dc:      	br	x17

00000000004c35e0 <log@plt>:
  4c35e0:      	adrp	x16, 0x4e6000
  4c35e4:      	ldr	x17, [x16, #0x828]
  4c35e8:      	add	x16, x16, #0x828
  4c35ec:      	br	x17

00000000004c35f0 <_Znam@plt>:
  4c35f0:      	adrp	x16, 0x4e6000
  4c35f4:      	ldr	x17, [x16, #0x830]
  4c35f8:      	add	x16, x16, #0x830
  4c35fc:      	br	x17

00000000004c3600 <_ZN8PVGIMAGE10ColorSpace19ColorSpaceConnectorC1ERKNS0_10ColorSpaceES4_@plt>:
  4c3600:      	adrp	x16, 0x4e6000
  4c3604:      	ldr	x17, [x16, #0x838]
  4c3608:      	add	x16, x16, #0x838
  4c360c:      	br	x17

00000000004c3610 <_ZN8PVGIMAGE10ColorSpace10ColorSpace7makeRGBERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS0_7details6TMat33IfEENS1_18TransferParametersENS2_8functionIFffEEE@plt>:
  4c3610:      	adrp	x16, 0x4e6000
  4c3614:      	ldr	x17, [x16, #0x840]
  4c3618:      	add	x16, x16, #0x840
  4c361c:      	br	x17

00000000004c3620 <_ZN8PVGIMAGE10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS0_7details6TMat33IfEENS1_18TransferParametersENS_14ColorSpaceTypeENS2_8functionIFffEEE@plt>:
  4c3620:      	adrp	x16, 0x4e6000
  4c3624:      	ldr	x17, [x16, #0x848]
  4c3628:      	add	x16, x16, #0x848
  4c362c:      	br	x17

00000000004c3630 <_ZNSt9exceptionD2Ev@plt>:
  4c3630:      	adrp	x16, 0x4e6000
  4c3634:      	ldr	x17, [x16, #0x850]
  4c3638:      	add	x16, x16, #0x850
  4c363c:      	br	x17

00000000004c3640 <_ZN8PVGIMAGE10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_NS1_18TransferParametersENS_14ColorSpaceTypeENS2_8functionIFffEEE@plt>:
  4c3640:      	adrp	x16, 0x4e6000
  4c3644:      	ldr	x17, [x16, #0x858]
  4c3648:      	add	x16, x16, #0x858
  4c364c:      	br	x17

00000000004c3650 <_ZN8PVGIMAGE10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_NS2_8functionIFffEEESM_NS_14ColorSpaceTypeESM_@plt>:
  4c3650:      	adrp	x16, 0x4e6000
  4c3654:      	ldr	x17, [x16, #0x860]
  4c3658:      	add	x16, x16, #0x860
  4c365c:      	br	x17

00000000004c3660 <_ZN8PVGIMAGE10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_fNS_14ColorSpaceTypeENS2_8functionIFffEEE@plt>:
  4c3660:      	adrp	x16, 0x4e6000
  4c3664:      	ldr	x17, [x16, #0x868]
  4c3668:      	add	x16, x16, #0x868
  4c366c:      	br	x17

00000000004c3670 <_ZN8PVGIMAGE10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_NS2_8functionIFffEEENSK_IFfffffEEEbNS_14ColorSpaceTypeESM_@plt>:
  4c3670:      	adrp	x16, 0x4e6000
  4c3674:      	ldr	x17, [x16, #0x870]
  4c3678:      	add	x16, x16, #0x870
  4c367c:      	br	x17

00000000004c3680 <fflush@plt>:
  4c3680:      	adrp	x16, 0x4e6000
  4c3684:      	ldr	x17, [x16, #0x878]
  4c3688:      	add	x16, x16, #0x878
  4c368c:      	br	x17

00000000004c3690 <ferror@plt>:
  4c3690:      	adrp	x16, 0x4e6000
  4c3694:      	ldr	x17, [x16, #0x880]
  4c3698:      	add	x16, x16, #0x880
  4c369c:      	br	x17

00000000004c36a0 <__strncpy_chk2@plt>:
  4c36a0:      	adrp	x16, 0x4e6000
  4c36a4:      	ldr	x17, [x16, #0x888]
  4c36a8:      	add	x16, x16, #0x888
  4c36ac:      	br	x17

00000000004c36b0 <exit@plt>:
  4c36b0:      	adrp	x16, 0x4e6000
  4c36b4:      	ldr	x17, [x16, #0x890]
  4c36b8:      	add	x16, x16, #0x890
  4c36bc:      	br	x17

00000000004c36c0 <fprintf@plt>:
  4c36c0:      	adrp	x16, 0x4e6000
  4c36c4:      	ldr	x17, [x16, #0x898]
  4c36c8:      	add	x16, x16, #0x898
  4c36cc:      	br	x17

00000000004c36d0 <getenv@plt>:
  4c36d0:      	adrp	x16, 0x4e6000
  4c36d4:      	ldr	x17, [x16, #0x8a0]
  4c36d8:      	add	x16, x16, #0x8a0
  4c36dc:      	br	x17

00000000004c36e0 <sscanf@plt>:
  4c36e0:      	adrp	x16, 0x4e6000
  4c36e4:      	ldr	x17, [x16, #0x8a8]
  4c36e8:      	add	x16, x16, #0x8a8
  4c36ec:      	br	x17

00000000004c36f0 <gifski_new@plt>:
  4c36f0:      	adrp	x16, 0x4e6000
  4c36f4:      	ldr	x17, [x16, #0x8b0]
  4c36f8:      	add	x16, x16, #0x8b0
  4c36fc:      	br	x17

00000000004c3700 <gifski_set_file_output@plt>:
  4c3700:      	adrp	x16, 0x4e6000
  4c3704:      	ldr	x17, [x16, #0x8b8]
  4c3708:      	add	x16, x16, #0x8b8
  4c370c:      	br	x17

00000000004c3710 <gifski_add_frame_rgba@plt>:
  4c3710:      	adrp	x16, 0x4e6000
  4c3714:      	ldr	x17, [x16, #0x8c0]
  4c3718:      	add	x16, x16, #0x8c0
  4c371c:      	br	x17

00000000004c3720 <gifski_finish@plt>:
  4c3720:      	adrp	x16, 0x4e6000
  4c3724:      	ldr	x17, [x16, #0x8c8]
  4c3728:      	add	x16, x16, #0x8c8
  4c372c:      	br	x17

00000000004c3730 <gifski_set_progress_callback@plt>:
  4c3730:      	adrp	x16, 0x4e6000
  4c3734:      	ldr	x17, [x16, #0x8d0]
  4c3738:      	add	x16, x16, #0x8d0
  4c373c:      	br	x17

00000000004c3740 <_ZN90_$LT$gifski..c_api..c_api_error..GifskiError$u20$as$u20$core..convert..From$LT$i32$GT$$GT$4from17h6b556ad0bb38b56bE@plt>:
  4c3740:      	adrp	x16, 0x4e6000
  4c3744:      	ldr	x17, [x16, #0x8d8]
  4c3748:      	add	x16, x16, #0x8d8
  4c374c:      	br	x17

00000000004c3750 <_ZN146_$LT$gifski..c_api..c_api_error..GifskiError$u20$as$u20$core..convert..From$LT$core..result..Result$LT$$LP$$RP$$C$gifski..error..Error$GT$$GT$$GT$4from17h2c5dc39ffab4d274E@plt>:
  4c3750:      	adrp	x16, 0x4e6000
  4c3754:      	ldr	x17, [x16, #0x8e0]
  4c3758:      	add	x16, x16, #0x8e0
  4c375c:      	br	x17

00000000004c3760 <_ZN112_$LT$gifski..c_api..c_api_error..GifskiError$u20$as$u20$core..convert..From$LT$std..io..error..ErrorKind$GT$$GT$4from17heb97d7bbe61515cdE@plt>:
  4c3760:      	adrp	x16, 0x4e6000
  4c3764:      	ldr	x17, [x16, #0x8e8]
  4c3768:      	add	x16, x16, #0x8e8
  4c376c:      	br	x17

00000000004c3770 <_ZN76_$LT$gifski..c_api..c_api_error..GifskiError$u20$as$u20$core..fmt..Debug$GT$3fmt17h14888a80bfa70b49E@plt>:
  4c3770:      	adrp	x16, 0x4e6000
  4c3774:      	ldr	x17, [x16, #0x8f0]
  4c3778:      	add	x16, x16, #0x8f0
  4c377c:      	br	x17

00000000004c3780 <_ZN6gifski5c_api11c_api_error118_$LT$impl$u20$core..convert..From$LT$gifski..c_api..c_api_error..GifskiError$GT$$u20$for$u20$std..io..error..Error$GT$4from17h293b94d25b6e6cafE@plt>:
  4c3780:      	adrp	x16, 0x4e6000
  4c3784:      	ldr	x17, [x16, #0x8f8]
  4c3788:      	add	x16, x16, #0x8f8
  4c378c:      	br	x17

00000000004c3790 <__rust_dealloc@plt>:
  4c3790:      	adrp	x16, 0x4e6000
  4c3794:      	ldr	x17, [x16, #0x900]
  4c3798:      	add	x16, x16, #0x900
  4c379c:      	br	x17

00000000004c37a0 <_ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E@plt>:
  4c37a0:      	adrp	x16, 0x4e6000
  4c37a4:      	ldr	x17, [x16, #0x908]
  4c37a8:      	add	x16, x16, #0x908
  4c37ac:      	br	x17

00000000004c37b0 <_ZN4core5slice5index26slice_start_index_len_fail17hd5d9e7bbf6d4ec6dE@plt>:
  4c37b0:      	adrp	x16, 0x4e6000
  4c37b4:      	ldr	x17, [x16, #0x910]
  4c37b8:      	add	x16, x16, #0x910
  4c37bc:      	br	x17

00000000004c37c0 <_ZN4core9panicking9panic_fmt17h86163c13bfcb8e07E@plt>:
  4c37c0:      	adrp	x16, 0x4e6000
  4c37c4:      	ldr	x17, [x16, #0x918]
  4c37c8:      	add	x16, x16, #0x918
  4c37cc:      	br	x17

00000000004c37d0 <_ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE@plt>:
  4c37d0:      	adrp	x16, 0x4e6000
  4c37d4:      	ldr	x17, [x16, #0x920]
  4c37d8:      	add	x16, x16, #0x920
  4c37dc:      	br	x17

00000000004c37e0 <_ZN4core3fmt5write17hb933ccd8ea0acc59E@plt>:
  4c37e0:      	adrp	x16, 0x4e6000
  4c37e4:      	ldr	x17, [x16, #0x928]
  4c37e8:      	add	x16, x16, #0x928
  4c37ec:      	br	x17

00000000004c37f0 <_ZN4core5slice5index24slice_end_index_len_fail17h231d3b63e7d6bd2fE@plt>:
  4c37f0:      	adrp	x16, 0x4e6000
  4c37f4:      	ldr	x17, [x16, #0x930]
  4c37f8:      	add	x16, x16, #0x930
  4c37fc:      	br	x17

00000000004c3800 <_ZN72_$LT$std..sys..unix..thread..Thread$u20$as$u20$core..ops..drop..Drop$GT$4drop17h3d411216341dc2a9E@plt>:
  4c3800:      	adrp	x16, 0x4e6000
  4c3804:      	ldr	x17, [x16, #0x938]
  4c3808:      	add	x16, x16, #0x938
  4c380c:      	br	x17

00000000004c3810 <_ZN3std3sys4unix5locks11futex_mutex5Mutex4wake17hfb9e1997a40c73cdE@plt>:
  4c3810:      	adrp	x16, 0x4e6000
  4c3814:      	ldr	x17, [x16, #0x940]
  4c3818:      	add	x16, x16, #0x940
  4c381c:      	br	x17

00000000004c3820 <_ZN3std9panicking11panic_count17is_zero_slow_path17had639ca7e151444dE@plt>:
  4c3820:      	adrp	x16, 0x4e6000
  4c3824:      	ldr	x17, [x16, #0x948]
  4c3828:      	add	x16, x16, #0x948
  4c382c:      	br	x17

00000000004c3830 <close@plt>:
  4c3830:      	adrp	x16, 0x4e6000
  4c3834:      	ldr	x17, [x16, #0x950]
  4c3838:      	add	x16, x16, #0x950
  4c383c:      	br	x17

00000000004c3840 <__rust_alloc@plt>:
  4c3840:      	adrp	x16, 0x4e6000
  4c3844:      	ldr	x17, [x16, #0x958]
  4c3848:      	add	x16, x16, #0x958
  4c384c:      	br	x17

00000000004c3850 <_ZN3std6thread21available_parallelism17h4a0c21a5755c7fd7E@plt>:
  4c3850:      	adrp	x16, 0x4e6000
  4c3854:      	ldr	x17, [x16, #0x960]
  4c3858:      	add	x16, x16, #0x960
  4c385c:      	br	x17

00000000004c3860 <_ZN5alloc5alloc18handle_alloc_error17hd86fdb6187878245E@plt>:
  4c3860:      	adrp	x16, 0x4e6000
  4c3864:      	ldr	x17, [x16, #0x968]
  4c3868:      	add	x16, x16, #0x968
  4c386c:      	br	x17

00000000004c3870 <_ZN3std3sys4unix5locks11futex_mutex5Mutex14lock_contended17hecdef02271eb1c4dE@plt>:
  4c3870:      	adrp	x16, 0x4e6000
  4c3874:      	ldr	x17, [x16, #0x970]
  4c3878:      	add	x16, x16, #0x970
  4c387c:      	br	x17

00000000004c3880 <_ZN4core3ffi5c_str4CStr8from_ptr9strlen_rt17h9cee62c6ed2abfb1E@plt>:
  4c3880:      	adrp	x16, 0x4e6000
  4c3884:      	ldr	x17, [x16, #0x978]
  4c3888:      	add	x16, x16, #0x978
  4c388c:      	br	x17

00000000004c3890 <_ZN4core3ffi5c_str4CStr6to_str17h1f0464428e964c8dE@plt>:
  4c3890:      	adrp	x16, 0x4e6000
  4c3894:      	ldr	x17, [x16, #0x980]
  4c3898:      	add	x16, x16, #0x980
  4c389c:      	br	x17

00000000004c38a0 <_ZN3std3sys4unix6os_str5Slice8to_owned17h42c526eef338d7ddE@plt>:
  4c38a0:      	adrp	x16, 0x4e6000
  4c38a4:      	ldr	x17, [x16, #0x988]
  4c38a8:      	add	x16, x16, #0x988
  4c38ac:      	br	x17

00000000004c38b0 <_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$u32$GT$3fmt17hdd8ceeb868019cefE@plt>:
  4c38b0:      	adrp	x16, 0x4e6000
  4c38b4:      	ldr	x17, [x16, #0x990]
  4c38b8:      	add	x16, x16, #0x990
  4c38bc:      	br	x17

00000000004c38c0 <_ZN5alloc3fmt6format12format_inner17h2d937a3812b96f0eE@plt>:
  4c38c0:      	adrp	x16, 0x4e6000
  4c38c4:      	ldr	x17, [x16, #0x998]
  4c38c8:      	add	x16, x16, #0x998
  4c38cc:      	br	x17

00000000004c38d0 <_ZN4core9panicking5panic17haac685927c8c1edbE@plt>:
  4c38d0:      	adrp	x16, 0x4e6000
  4c38d4:      	ldr	x17, [x16, #0x9a0]
  4c38d8:      	add	x16, x16, #0x9a0
  4c38dc:      	br	x17

00000000004c38e0 <_ZN5alloc7raw_vec17capacity_overflow17h9f5446d30f3db70aE@plt>:
  4c38e0:      	adrp	x16, 0x4e6000
  4c38e4:      	ldr	x17, [x16, #0x9a8]
  4c38e8:      	add	x16, x16, #0x9a8
  4c38ec:      	br	x17

00000000004c38f0 <_ZN5alloc3ffi5c_str7CString17from_vec_with_nul17hdc492c26ad9b7ce8E@plt>:
  4c38f0:      	adrp	x16, 0x4e6000
  4c38f4:      	ldr	x17, [x16, #0x9b0]
  4c38f8:      	add	x16, x16, #0x9b0
  4c38fc:      	br	x17

00000000004c3900 <_ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E@plt>:
  4c3900:      	adrp	x16, 0x4e6000
  4c3904:      	ldr	x17, [x16, #0x9b8]
  4c3908:      	add	x16, x16, #0x9b8
  4c390c:      	br	x17

00000000004c3910 <_ZN3std9panicking3try7cleanup17h8c569baa2145594dE@plt>:
  4c3910:      	adrp	x16, 0x4e6000
  4c3914:      	ldr	x17, [x16, #0x9c0]
  4c3918:      	add	x16, x16, #0x9c0
  4c391c:      	br	x17

00000000004c3920 <_ZN3std2fs11OpenOptions3new17hf144d216ca11b607E@plt>:
  4c3920:      	adrp	x16, 0x4e6000
  4c3924:      	ldr	x17, [x16, #0x9c8]
  4c3928:      	add	x16, x16, #0x9c8
  4c392c:      	br	x17

00000000004c3930 <_ZN3std2fs11OpenOptions5write17h9a154b4dad8cdc58E@plt>:
  4c3930:      	adrp	x16, 0x4e6000
  4c3934:      	ldr	x17, [x16, #0x9d0]
  4c3938:      	add	x16, x16, #0x9d0
  4c393c:      	br	x17

00000000004c3940 <_ZN3std2fs11OpenOptions6create17hff55f4cf6afde689E@plt>:
  4c3940:      	adrp	x16, 0x4e6000
  4c3944:      	ldr	x17, [x16, #0x9d8]
  4c3948:      	add	x16, x16, #0x9d8
  4c394c:      	br	x17

00000000004c3950 <_ZN3std2fs11OpenOptions8truncate17hb8015d47ce9a932cE@plt>:
  4c3950:      	adrp	x16, 0x4e6000
  4c3954:      	ldr	x17, [x16, #0x9e0]
  4c3958:      	add	x16, x16, #0x9e0
  4c395c:      	br	x17

00000000004c3960 <_ZN3std2fs11OpenOptions5_open17hbf3c2ab49e8f58c6E@plt>:
  4c3960:      	adrp	x16, 0x4e6000
  4c3964:      	ldr	x17, [x16, #0x9e8]
  4c3968:      	add	x16, x16, #0x9e8
  4c396c:      	br	x17

00000000004c3970 <_ZN3std6thread7Builder3new17h208d8d3938d5d097E@plt>:
  4c3970:      	adrp	x16, 0x4e6000
  4c3974:      	ldr	x17, [x16, #0x9f0]
  4c3978:      	add	x16, x16, #0x9f0
  4c397c:      	br	x17

00000000004c3980 <_ZN3std6thread7Builder4name17ha0d0ee6a9f30d572E@plt>:
  4c3980:      	adrp	x16, 0x4e6000
  4c3984:      	ldr	x17, [x16, #0x9f8]
  4c3988:      	add	x16, x16, #0x9f8
  4c398c:      	br	x17

00000000004c3990 <_ZN3std2io5stdio6stderr17h79bfaa1eabbac6f2E@plt>:
  4c3990:      	adrp	x16, 0x4e6000
  4c3994:      	ldr	x17, [x16, #0xa00]
  4c3998:      	add	x16, x16, #0xa00
  4c399c:      	br	x17

00000000004c39a0 <_ZN57_$LT$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$9write_all17hb3faf9ab8ec06589E@plt>:
  4c39a0:      	adrp	x16, 0x4e6000
  4c39a4:      	ldr	x17, [x16, #0xa08]
  4c39a8:      	add	x16, x16, #0xa08
  4c39ac:      	br	x17

00000000004c39b0 <_ZN3std6thread7current17hedcbf4f61b4b5c7aE@plt>:
  4c39b0:      	adrp	x16, 0x4e6000
  4c39b4:      	ldr	x17, [x16, #0xa10]
  4c39b8:      	add	x16, x16, #0xa10
  4c39bc:      	br	x17

00000000004c39c0 <_ZN3std6thread4park17h32c5a3bc49199d18E@plt>:
  4c39c0:      	adrp	x16, 0x4e6000
  4c39c4:      	ldr	x17, [x16, #0xa18]
  4c39c8:      	add	x16, x16, #0xa18
  4c39cc:      	br	x17

00000000004c39d0 <_ZN3std5panic13resume_unwind17h10f5f653e906ae36E@plt>:
  4c39d0:      	adrp	x16, 0x4e6000
  4c39d4:      	ldr	x17, [x16, #0xa20]
  4c39d8:      	add	x16, x16, #0xa20
  4c39dc:      	br	x17

00000000004c39e0 <_ZN4core3fmt9Formatter26debug_struct_field3_finish17h754642d57d06dce9E@plt>:
  4c39e0:      	adrp	x16, 0x4e6000
  4c39e4:      	ldr	x17, [x16, #0xa28]
  4c39e8:      	add	x16, x16, #0xa28
  4c39ec:      	br	x17

00000000004c39f0 <_ZN4core3fmt9Formatter26debug_struct_field4_finish17hc66e7c12e1549609E@plt>:
  4c39f0:      	adrp	x16, 0x4e6000
  4c39f4:      	ldr	x17, [x16, #0xa30]
  4c39f8:      	add	x16, x16, #0xa30
  4c39fc:      	br	x17

00000000004c3a00 <_ZN4core3fmt9Formatter10debug_list17he7fb9d2d8b163048E@plt>:
  4c3a00:      	adrp	x16, 0x4e6000
  4c3a04:      	ldr	x17, [x16, #0xa38]
  4c3a08:      	add	x16, x16, #0xa38
  4c3a0c:      	br	x17

00000000004c3a10 <_ZN4core3fmt8builders9DebugList5entry17h81b82d80fcd5a31fE@plt>:
  4c3a10:      	adrp	x16, 0x4e6000
  4c3a14:      	ldr	x17, [x16, #0xa40]
  4c3a18:      	add	x16, x16, #0xa40
  4c3a1c:      	br	x17

00000000004c3a20 <_ZN4core3fmt8builders9DebugList6finish17h0046f31d629c2cd8E@plt>:
  4c3a20:      	adrp	x16, 0x4e6000
  4c3a24:      	ldr	x17, [x16, #0xa48]
  4c3a28:      	add	x16, x16, #0xa48
  4c3a2c:      	br	x17

00000000004c3a30 <_ZN4core5slice5index22slice_index_order_fail17h486cd0d11c936c0dE@plt>:
  4c3a30:      	adrp	x16, 0x4e6000
  4c3a34:      	ldr	x17, [x16, #0xa50]
  4c3a38:      	add	x16, x16, #0xa50
  4c3a3c:      	br	x17

00000000004c3a40 <_ZN3std7process5abort17hca6b65708ed86b54E@plt>:
  4c3a40:      	adrp	x16, 0x4e6000
  4c3a44:      	ldr	x17, [x16, #0xa58]
  4c3a48:      	add	x16, x16, #0xa58
  4c3a4c:      	br	x17

00000000004c3a50 <_ZN4core3fmt9Formatter9write_str17h1c5c93915ba5f2c6E@plt>:
  4c3a50:      	adrp	x16, 0x4e6000
  4c3a54:      	ldr	x17, [x16, #0xa60]
  4c3a58:      	add	x16, x16, #0xa60
  4c3a5c:      	br	x17

00000000004c3a60 <_ZN3std3sys4unix6thread6Thread4join17h044f15d41e2d0caeE@plt>:
  4c3a60:      	adrp	x16, 0x4e6000
  4c3a64:      	ldr	x17, [x16, #0xa68]
  4c3a68:      	add	x16, x16, #0xa68
  4c3a6c:      	br	x17

00000000004c3a70 <_ZN3std10sys_common6thread9min_stack17h8dd5885491b1104fE@plt>:
  4c3a70:      	adrp	x16, 0x4e6000
  4c3a74:      	ldr	x17, [x16, #0xa70]
  4c3a78:      	add	x16, x16, #0xa70
  4c3a7c:      	br	x17

00000000004c3a80 <_ZN3std6thread6Thread3new17h7a588126987117edE@plt>:
  4c3a80:      	adrp	x16, 0x4e6000
  4c3a84:      	ldr	x17, [x16, #0xa78]
  4c3a88:      	add	x16, x16, #0xa78
  4c3a8c:      	br	x17

00000000004c3a90 <_ZN3std2io5stdio18set_output_capture17hab2f2c6db82ac078E@plt>:
  4c3a90:      	adrp	x16, 0x4e6000
  4c3a94:      	ldr	x17, [x16, #0xa80]
  4c3a98:      	add	x16, x16, #0xa80
  4c3a9c:      	br	x17

00000000004c3aa0 <_ZN3std6thread6scoped9ScopeData29increment_num_running_threads17hc15d08274d111bafE@plt>:
  4c3aa0:      	adrp	x16, 0x4e6000
  4c3aa4:      	ldr	x17, [x16, #0xa88]
  4c3aa8:      	add	x16, x16, #0xa88
  4c3aac:      	br	x17

00000000004c3ab0 <_ZN3std3sys4unix6thread6Thread3new17h88b260337134200cE@plt>:
  4c3ab0:      	adrp	x16, 0x4e6000
  4c3ab4:      	ldr	x17, [x16, #0xa90]
  4c3ab8:      	add	x16, x16, #0xa90
  4c3abc:      	br	x17

00000000004c3ac0 <_ZN3std6thread6Thread5cname17hda64b6a06f996e42E@plt>:
  4c3ac0:      	adrp	x16, 0x4e6000
  4c3ac4:      	ldr	x17, [x16, #0xa98]
  4c3ac8:      	add	x16, x16, #0xa98
  4c3acc:      	br	x17

00000000004c3ad0 <_ZN3std3sys4unix6thread6Thread8set_name17hf7c43513c31ed408E@plt>:
  4c3ad0:      	adrp	x16, 0x4e6000
  4c3ad4:      	ldr	x17, [x16, #0xaa0]
  4c3ad8:      	add	x16, x16, #0xaa0
  4c3adc:      	br	x17

00000000004c3ae0 <_ZN3std3sys4unix6thread5guard7current17he6ffb47e9fe483e5E@plt>:
  4c3ae0:      	adrp	x16, 0x4e6000
  4c3ae4:      	ldr	x17, [x16, #0xaa8]
  4c3ae8:      	add	x16, x16, #0xaa8
  4c3aec:      	br	x17

00000000004c3af0 <_ZN3std10sys_common11thread_info3set17hbdbc4a3b499cdd98E@plt>:
  4c3af0:      	adrp	x16, 0x4e6000
  4c3af4:      	ldr	x17, [x16, #0xab0]
  4c3af8:      	add	x16, x16, #0xab0
  4c3afc:      	br	x17

00000000004c3b00 <_ZN3std6thread6scoped9ScopeData29decrement_num_running_threads17h9841a4d4b41f0514E@plt>:
  4c3b00:      	adrp	x16, 0x4e6000
  4c3b04:      	ldr	x17, [x16, #0xab8]
  4c3b08:      	add	x16, x16, #0xab8
  4c3b0c:      	br	x17

00000000004c3b10 <_ZN3std3sys4unix5stdio12panic_output17h11fd8dd47f1e3a74E@plt>:
  4c3b10:      	adrp	x16, 0x4e6000
  4c3b14:      	ldr	x17, [x16, #0xac0]
  4c3b18:      	add	x16, x16, #0xac0
  4c3b1c:      	br	x17

00000000004c3b20 <_ZN3std3sys4unix14abort_internal17h0da7964cfecd09ddE@plt>:
  4c3b20:      	adrp	x16, 0x4e6000
  4c3b24:      	ldr	x17, [x16, #0xac8]
  4c3b28:      	add	x16, x16, #0xac8
  4c3b2c:      	br	x17

00000000004c3b30 <_ZN64_$LT$alloc..ffi..c_str..NulError$u20$as$u20$core..fmt..Debug$GT$3fmt17hcbec4ae051f76a33E@plt>:
  4c3b30:      	adrp	x16, 0x4e6000
  4c3b34:      	ldr	x17, [x16, #0xad0]
  4c3b38:      	add	x16, x16, #0xad0
  4c3b3c:      	br	x17

00000000004c3b40 <_ZN64_$LT$std..sys..unix..stdio..Stderr$u20$as$u20$std..io..Write$GT$5write17h09569f5370099d8aE@plt>:
  4c3b40:      	adrp	x16, 0x4e6000
  4c3b44:      	ldr	x17, [x16, #0xad8]
  4c3b48:      	add	x16, x16, #0xad8
  4c3b4c:      	br	x17

00000000004c3b50 <Gif_DeleteImage@plt>:
  4c3b50:      	adrp	x16, 0x4e6000
  4c3b54:      	ldr	x17, [x16, #0xae0]
  4c3b58:      	add	x16, x16, #0xae0
  4c3b5c:      	br	x17

00000000004c3b60 <Gif_WriterCleanup@plt>:
  4c3b60:      	adrp	x16, 0x4e6000
  4c3b64:      	ldr	x17, [x16, #0xae8]
  4c3b68:      	add	x16, x16, #0xae8
  4c3b6c:      	br	x17

00000000004c3b70 <_ZN4core9panicking19assert_failed_inner17h1deeaebe75ffe3baE@plt>:
  4c3b70:      	adrp	x16, 0x4e6000
  4c3b74:      	ldr	x17, [x16, #0xaf0]
  4c3b78:      	add	x16, x16, #0xaf0
  4c3b7c:      	br	x17

00000000004c3b80 <_ZN70_$LT$imagequant..attr..Attributes$u20$as$u20$core..ops..drop..Drop$GT$4drop17hd9394061b2196e42E@plt>:
  4c3b80:      	adrp	x16, 0x4e6000
  4c3b84:      	ldr	x17, [x16, #0xaf8]
  4c3b88:      	add	x16, x16, #0xaf8
  4c3b8c:      	br	x17

00000000004c3b90 <Gif_NewImage@plt>:
  4c3b90:      	adrp	x16, 0x4e6000
  4c3b94:      	ldr	x17, [x16, #0xb00]
  4c3b98:      	add	x16, x16, #0xb00
  4c3b9c:      	br	x17

00000000004c3ba0 <Gif_NewFullColormap@plt>:
  4c3ba0:      	adrp	x16, 0x4e6000
  4c3ba4:      	ldr	x17, [x16, #0xb08]
  4c3ba8:      	add	x16, x16, #0xb08
  4c3bac:      	br	x17

00000000004c3bb0 <Gif_AddColor@plt>:
  4c3bb0:      	adrp	x16, 0x4e6000
  4c3bb4:      	ldr	x17, [x16, #0xb10]
  4c3bb8:      	add	x16, x16, #0xb10
  4c3bbc:      	br	x17

00000000004c3bc0 <Gif_WriterInit@plt>:
  4c3bc0:      	adrp	x16, 0x4e6000
  4c3bc4:      	ldr	x17, [x16, #0xb18]
  4c3bc8:      	add	x16, x16, #0xb18
  4c3bcc:      	br	x17

00000000004c3bd0 <Gif_SetUncompressedImage@plt>:
  4c3bd0:      	adrp	x16, 0x4e6000
  4c3bd4:      	ldr	x17, [x16, #0xb20]
  4c3bd8:      	add	x16, x16, #0xb20
  4c3bdc:      	br	x17

00000000004c3be0 <Gif_WriteCompressedData@plt>:
  4c3be0:      	adrp	x16, 0x4e6000
  4c3be4:      	ldr	x17, [x16, #0xb28]
  4c3be8:      	add	x16, x16, #0xb28
  4c3bec:      	br	x17

00000000004c3bf0 <_ZN3gif7encoder36_$LT$impl$u20$gif..common..Frame$GT$20make_lzw_pre_encoded17h1676af9378f61e97E@plt>:
  4c3bf0:      	adrp	x16, 0x4e6000
  4c3bf4:      	ldr	x17, [x16, #0xb30]
  4c3bf8:      	add	x16, x16, #0xb30
  4c3bfc:      	br	x17

00000000004c3c00 <_ZN95_$LT$gif..common..AnyExtension$u20$as$u20$core..convert..From$LT$gif..common..Extension$GT$$GT$4from17he92b93c317a134a3E@plt>:
  4c3c00:      	adrp	x16, 0x4e6000
  4c3c04:      	ldr	x17, [x16, #0xb38]
  4c3c08:      	add	x16, x16, #0xb38
  4c3c0c:      	br	x17

00000000004c3c10 <_ZN4core3fmt9Formatter25debug_tuple_field1_finish17hf523376776bbc2b7E@plt>:
  4c3c10:      	adrp	x16, 0x4e6000
  4c3c14:      	ldr	x17, [x16, #0xb40]
  4c3c18:      	add	x16, x16, #0xb40
  4c3c1c:      	br	x17

00000000004c3c20 <_ZN4core3fmt9Formatter9write_fmt17h5ba4060b42626c9fE@plt>:
  4c3c20:      	adrp	x16, 0x4e6000
  4c3c24:      	ldr	x17, [x16, #0xb48]
  4c3c28:      	add	x16, x16, #0xb48
  4c3c2c:      	br	x17

00000000004c3c30 <_ZN4core3fmt9Formatter3new17hb76c7997cae81d2bE@plt>:
  4c3c30:      	adrp	x16, 0x4e6000
  4c3c34:      	ldr	x17, [x16, #0xb50]
  4c3c38:      	add	x16, x16, #0xb50
  4c3c3c:      	br	x17

00000000004c3c40 <_ZN72_$LT$core..num..error..TryFromIntError$u20$as$u20$core..fmt..Display$GT$3fmt17hac4182b3f1275dcdE@plt>:
  4c3c40:      	adrp	x16, 0x4e6000
  4c3c44:      	ldr	x17, [x16, #0xb58]
  4c3c48:      	add	x16, x16, #0xb58
  4c3c4c:      	br	x17

00000000004c3c50 <_ZN52_$LT$resize..Error$u20$as$u20$core..fmt..Display$GT$3fmt17hbf3cc14f3833e72aE@plt>:
  4c3c50:      	adrp	x16, 0x4e6000
  4c3c54:      	ldr	x17, [x16, #0xb60]
  4c3c58:      	add	x16, x16, #0xb60
  4c3c5c:      	br	x17

00000000004c3c60 <__rust_realloc@plt>:
  4c3c60:      	adrp	x16, 0x4e6000
  4c3c64:      	ldr	x17, [x16, #0xb68]
  4c3c68:      	add	x16, x16, #0xb68
  4c3c6c:      	br	x17

00000000004c3c70 <__rust_alloc_zeroed@plt>:
  4c3c70:      	adrp	x16, 0x4e6000
  4c3c74:      	ldr	x17, [x16, #0xb70]
  4c3c78:      	add	x16, x16, #0xb70
  4c3c7c:      	br	x17

00000000004c3c80 <_ZN4core3fmt3num3imp54_$LT$impl$u20$core..fmt..Display$u20$for$u20$usize$GT$3fmt17hfa4bc4030e86e4a5E@plt>:
  4c3c80:      	adrp	x16, 0x4e6000
  4c3c84:      	ldr	x17, [x16, #0xb78]
  4c3c88:      	add	x16, x16, #0xb78
  4c3c8c:      	br	x17

00000000004c3c90 <_ZN3std3sys4unix2fs6unlink17hf62e19c98e680d2fE@plt>:
  4c3c90:      	adrp	x16, 0x4e6000
  4c3c94:      	ldr	x17, [x16, #0xb80]
  4c3c98:      	add	x16, x16, #0xb80
  4c3c9c:      	br	x17

00000000004c3ca0 <_ZN3std2fs4read5inner17h42bc50a7a9f937bbE@plt>:
  4c3ca0:      	adrp	x16, 0x4e6000
  4c3ca4:      	ldr	x17, [x16, #0xb88]
  4c3ca8:      	add	x16, x16, #0xb88
  4c3cac:      	br	x17

00000000004c3cb0 <_ZN48_$LT$std..fs..File$u20$as$u20$std..io..Write$GT$14write_vectored17h7e18d74d2cb83ffcE@plt>:
  4c3cb0:      	adrp	x16, 0x4e6000
  4c3cb4:      	ldr	x17, [x16, #0xb90]
  4c3cb8:      	add	x16, x16, #0xb90
  4c3cbc:      	br	x17

00000000004c3cc0 <_ZN48_$LT$std..fs..File$u20$as$u20$std..io..Write$GT$5write17hc233855bb1e5cd58E@plt>:
  4c3cc0:      	adrp	x16, 0x4e6000
  4c3cc4:      	ldr	x17, [x16, #0xb98]
  4c3cc8:      	add	x16, x16, #0xb98
  4c3ccc:      	br	x17

00000000004c3cd0 <_ZN40_$LT$str$u20$as$u20$core..fmt..Debug$GT$3fmt17hf6ef12c3930f87faE@plt>:
  4c3cd0:      	adrp	x16, 0x4e6000
  4c3cd4:      	ldr	x17, [x16, #0xba0]
  4c3cd8:      	add	x16, x16, #0xba0
  4c3cdc:      	br	x17

00000000004c3ce0 <_ZN58_$LT$std..io..error..Error$u20$as$u20$core..fmt..Debug$GT$3fmt17h550636ed79c7fe46E@plt>:
  4c3ce0:      	adrp	x16, 0x4e6000
  4c3ce4:      	ldr	x17, [x16, #0xba8]
  4c3ce8:      	add	x16, x16, #0xba8
  4c3cec:      	br	x17

00000000004c3cf0 <_ZN60_$LT$std..io..error..Error$u20$as$u20$core..fmt..Display$GT$3fmt17hfd5bfeca8ae5bcb7E@plt>:
  4c3cf0:      	adrp	x16, 0x4e6000
  4c3cf4:      	ldr	x17, [x16, #0xbb0]
  4c3cf8:      	add	x16, x16, #0xbb0
  4c3cfc:      	br	x17

00000000004c3d00 <_ZN42_$LT$str$u20$as$u20$core..fmt..Display$GT$3fmt17hfbe0c69e8a31cf3bE@plt>:
  4c3d00:      	adrp	x16, 0x4e6000
  4c3d04:      	ldr	x17, [x16, #0xbb8]
  4c3d08:      	add	x16, x16, #0xbb8
  4c3d0c:      	br	x17

00000000004c3d10 <_ZN96_$LT$gif..encoder..EncodingError$u20$as$u20$core..convert..From$LT$std..io..error..Error$GT$$GT$4from17h83fdccafe33db6a3E@plt>:
  4c3d10:      	adrp	x16, 0x4e6000
  4c3d14:      	ldr	x17, [x16, #0xbc0]
  4c3d18:      	add	x16, x16, #0xbc0
  4c3d1c:      	br	x17

00000000004c3d20 <_ZN5alloc6string104_$LT$impl$u20$core..convert..From$LT$alloc..string..String$GT$$u20$for$u20$alloc..vec..Vec$LT$u8$GT$$GT$4from17h0825c50e3d0f479aE@plt>:
  4c3d20:      	adrp	x16, 0x4e6000
  4c3d24:      	ldr	x17, [x16, #0xbc8]
  4c3d28:      	add	x16, x16, #0xbc8
  4c3d2c:      	br	x17

00000000004c3d30 <_ZN4core5slice6memchr14memchr_aligned17hee6d2b83911f8d8eE@plt>:
  4c3d30:      	adrp	x16, 0x4e6000
  4c3d34:      	ldr	x17, [x16, #0xbd0]
  4c3d38:      	add	x16, x16, #0xbd0
  4c3d3c:      	br	x17

00000000004c3d40 <_ZN5alloc3ffi5c_str7CString19_from_vec_unchecked17h81c0ee3f357d1c2cE@plt>:
  4c3d40:      	adrp	x16, 0x4e6000
  4c3d44:      	ldr	x17, [x16, #0xbd8]
  4c3d48:      	add	x16, x16, #0xbd8
  4c3d4c:      	br	x17

00000000004c3d50 <_ZN20fallible_collections22make_try_reserve_error17hd85c9a4b6ca4eeadE@plt>:
  4c3d50:      	adrp	x16, 0x4e6000
  4c3d54:      	ldr	x17, [x16, #0xbe0]
  4c3d58:      	add	x16, x16, #0xbe0
  4c3d5c:      	br	x17

00000000004c3d60 <_ZN4core9panicking18panic_bounds_check17h7254dc10391e5a1aE@plt>:
  4c3d60:      	adrp	x16, 0x4e6000
  4c3d64:      	ldr	x17, [x16, #0xbe8]
  4c3d68:      	add	x16, x16, #0xbe8
  4c3d6c:      	br	x17

00000000004c3d70 <_ZN3std2io5error5Error4_new17h08837567920b90c4E@plt>:
  4c3d70:      	adrp	x16, 0x4e6000
  4c3d74:      	ldr	x17, [x16, #0xbf0]
  4c3d78:      	add	x16, x16, #0xbf0
  4c3d7c:      	br	x17

00000000004c3d80 <_ZN4core6option13expect_failed17h773922ac044cf95cE@plt>:
  4c3d80:      	adrp	x16, 0x4e6000
  4c3d84:      	ldr	x17, [x16, #0xbf8]
  4c3d88:      	add	x16, x16, #0xbf8
  4c3d8c:      	br	x17

00000000004c3d90 <_ZN4core3fmt9Formatter26debug_struct_fields_finish17hd7d71307540724a6E@plt>:
  4c3d90:      	adrp	x16, 0x4e6000
  4c3d94:      	ldr	x17, [x16, #0xc00]
  4c3d98:      	add	x16, x16, #0xc00
  4c3d9c:      	br	x17

00000000004c3da0 <_ZN3std6thread5Inner6parker17h11b7b7aa80ca9130E@plt>:
  4c3da0:      	adrp	x16, 0x4e6000
  4c3da4:      	ldr	x17, [x16, #0xc08]
  4c3da8:      	add	x16, x16, #0xc08
  4c3dac:      	br	x17

00000000004c3db0 <_ZN3std3sys4unix5futex10futex_wake17hd77498b02733a47eE@plt>:
  4c3db0:      	adrp	x16, 0x4e6000
  4c3db4:      	ldr	x17, [x16, #0xc10]
  4c3db8:      	add	x16, x16, #0xc10
  4c3dbc:      	br	x17

00000000004c3dc0 <_ZN5alloc3vec16Vec$LT$T$C$A$GT$6remove13assert_failed17h1f418c79637cfce9E@plt>:
  4c3dc0:      	adrp	x16, 0x4e6000
  4c3dc4:      	ldr	x17, [x16, #0xc18]
  4c3dc8:      	add	x16, x16, #0xc18
  4c3dcc:      	br	x17

00000000004c3dd0 <_ZN3std6thread6Thread2id17h1770e378cedeeacfE@plt>:
  4c3dd0:      	adrp	x16, 0x4e6000
  4c3dd4:      	ldr	x17, [x16, #0xc20]
  4c3dd8:      	add	x16, x16, #0xc20
  4c3ddc:      	br	x17

00000000004c3de0 <_ZN3std6thread9yield_now17h6038fa8308f8e862E@plt>:
  4c3de0:      	adrp	x16, 0x4e6000
  4c3de4:      	ldr	x17, [x16, #0xc28]
  4c3de8:      	add	x16, x16, #0xc28
  4c3dec:      	br	x17

00000000004c3df0 <_ZN3std4time7Instant3now17h30daf09a07128b83E@plt>:
  4c3df0:      	adrp	x16, 0x4e6000
  4c3df4:      	ldr	x17, [x16, #0xc30]
  4c3df8:      	add	x16, x16, #0xc30
  4c3dfc:      	br	x17

00000000004c3e00 <_ZN60_$LT$std..time..Instant$u20$as$u20$core..ops..arith..Sub$GT$3sub17h4e525474e3b3c9d0E@plt>:
  4c3e00:      	adrp	x16, 0x4e6000
  4c3e04:      	ldr	x17, [x16, #0xc38]
  4c3e08:      	add	x16, x16, #0xc38
  4c3e0c:      	br	x17

00000000004c3e10 <_ZN3std6thread12park_timeout17ha7da7e454f267faeE@plt>:
  4c3e10:      	adrp	x16, 0x4e6000
  4c3e14:      	ldr	x17, [x16, #0xc40]
  4c3e18:      	add	x16, x16, #0xc40
  4c3e1c:      	br	x17

00000000004c3e20 <_ZN86_$LT$crossbeam_channel..flavors..zero..ZeroToken$u20$as$u20$core..default..Default$GT$7default17h71796a9bedc77620E@plt>:
  4c3e20:      	adrp	x16, 0x4e6000
  4c3e24:      	ldr	x17, [x16, #0xc48]
  4c3e28:      	add	x16, x16, #0xc48
  4c3e2c:      	br	x17

00000000004c3e30 <_ZN17crossbeam_channel7context7Context3new17hb7e3a0a8d582c6aaE@plt>:
  4c3e30:      	adrp	x16, 0x4e6000
  4c3e34:      	ldr	x17, [x16, #0xc50]
  4c3e38:      	add	x16, x16, #0xc50
  4c3e3c:      	br	x17

00000000004c3e40 <_ZN17crossbeam_channel5utils11sleep_until17h5a09e91e4ea046abE@plt>:
  4c3e40:      	adrp	x16, 0x4e6000
  4c3e44:      	ldr	x17, [x16, #0xc58]
  4c3e48:      	add	x16, x16, #0xc58
  4c3e4c:      	br	x17

00000000004c3e50 <_ZN88_$LT$std..time..Instant$u20$as$u20$core..ops..arith..Add$LT$core..time..Duration$GT$$GT$3add17hd9e20473fd75ff8dE@plt>:
  4c3e50:      	adrp	x16, 0x4e6000
  4c3e54:      	ldr	x17, [x16, #0xc60]
  4c3e58:      	add	x16, x16, #0xc60
  4c3e5c:      	br	x17

00000000004c3e60 <_ZN3std6thread5sleep17h34758b2da46b959dE@plt>:
  4c3e60:      	adrp	x16, 0x4e6000
  4c3e64:      	ldr	x17, [x16, #0xc68]
  4c3e68:      	add	x16, x16, #0xc68
  4c3e6c:      	br	x17

00000000004c3e70 <_ZN3gif7encoder9flag_size17h99d7b61bc255f8ebE@plt>:
  4c3e70:      	adrp	x16, 0x4e6000
  4c3e74:      	ldr	x17, [x16, #0xc70]
  4c3e78:      	add	x16, x16, #0xc70
  4c3e7c:      	br	x17

00000000004c3e80 <_ZN3gif7encoder13ExtensionData15new_control_ext17h5eabcfc83983c2f3E@plt>:
  4c3e80:      	adrp	x16, 0x4e6000
  4c3e84:      	ldr	x17, [x16, #0xc78]
  4c3e88:      	add	x16, x16, #0xc78
  4c3e8c:      	br	x17

00000000004c3e90 <_ZN104_$LT$gif..encoder..EncodingError$u20$as$u20$core..convert..From$LT$gif..encoder..FormatErrorKind$GT$$GT$4from17h5b1c839f9cbcd7fdE@plt>:
  4c3e90:      	adrp	x16, 0x4e6000
  4c3e94:      	ldr	x17, [x16, #0xc80]
  4c3e98:      	add	x16, x16, #0xc80
  4c3e9c:      	br	x17

00000000004c3ea0 <_ZN64_$LT$gif..encoder..EncodingError$u20$as$u20$core..fmt..Debug$GT$3fmt17ha5f00d5566bb2f80E@plt>:
  4c3ea0:      	adrp	x16, 0x4e6000
  4c3ea4:      	ldr	x17, [x16, #0xc88]
  4c3ea8:      	add	x16, x16, #0xc88
  4c3eac:      	br	x17

00000000004c3eb0 <_ZN66_$LT$gif..encoder..EncodingError$u20$as$u20$core..fmt..Display$GT$3fmt17h61e0025254cfa927E@plt>:
  4c3eb0:      	adrp	x16, 0x4e6000
  4c3eb4:      	ldr	x17, [x16, #0xc90]
  4c3eb8:      	add	x16, x16, #0xc90
  4c3ebc:      	br	x17

00000000004c3ec0 <_ZN3std10sys_common16thread_local_key9StaticKey9lazy_init17ha54f7bbe76cafa80E@plt>:
  4c3ec0:      	adrp	x16, 0x4e6000
  4c3ec4:      	ldr	x17, [x16, #0xc98]
  4c3ec8:      	add	x16, x16, #0xc98
  4c3ecc:      	br	x17

00000000004c3ed0 <_ZN61_$LT$imagequant..error..Error$u20$as$u20$core..fmt..Debug$GT$3fmt17hdeb9a9a9dbee6d1cE@plt>:
  4c3ed0:      	adrp	x16, 0x4e6000
  4c3ed4:      	ldr	x17, [x16, #0xca0]
  4c3ed8:      	add	x16, x16, #0xca0
  4c3edc:      	br	x17

00000000004c3ee0 <_ZN55_$LT$gif_dispose..Error$u20$as$u20$core..fmt..Debug$GT$3fmt17h121812d017065669E@plt>:
  4c3ee0:      	adrp	x16, 0x4e6000
  4c3ee4:      	ldr	x17, [x16, #0xca8]
  4c3ee8:      	add	x16, x16, #0xca8
  4c3eec:      	br	x17

00000000004c3ef0 <_ZN63_$LT$imagequant..error..Error$u20$as$u20$core..fmt..Display$GT$3fmt17hf88f73b0f18ccd58E@plt>:
  4c3ef0:      	adrp	x16, 0x4e6000
  4c3ef4:      	ldr	x17, [x16, #0xcb0]
  4c3ef8:      	add	x16, x16, #0xcb0
  4c3efc:      	br	x17

00000000004c3f00 <_ZN57_$LT$gif_dispose..Error$u20$as$u20$core..fmt..Display$GT$3fmt17he0ce2d90035f8782E@plt>:
  4c3f00:      	adrp	x16, 0x4e6000
  4c3f04:      	ldr	x17, [x16, #0xcb8]
  4c3f08:      	add	x16, x16, #0xcb8
  4c3f0c:      	br	x17

00000000004c3f10 <_ZN4core3fmt9Formatter12debug_struct17h7e02d6ba6095e7fcE@plt>:
  4c3f10:      	adrp	x16, 0x4e6000
  4c3f14:      	ldr	x17, [x16, #0xcc0]
  4c3f18:      	add	x16, x16, #0xcc0
  4c3f1c:      	br	x17

00000000004c3f20 <_ZN4core3fmt8builders11DebugStruct21finish_non_exhaustive17h9bd8091a982b5577E@plt>:
  4c3f20:      	adrp	x16, 0x4e6000
  4c3f24:      	ldr	x17, [x16, #0xcc8]
  4c3f28:      	add	x16, x16, #0xcc8
  4c3f2c:      	br	x17

00000000004c3f30 <_ZN6gifski6Writer11write_inner17h50e6ff3bdcf925fbE@plt>:
  4c3f30:      	adrp	x16, 0x4e6000
  4c3f34:      	ldr	x17, [x16, #0xcd0]
  4c3f38:      	add	x16, x16, #0xcd0
  4c3f3c:      	br	x17

00000000004c3f40 <_ZN3std2io5stdio7_eprint17h4077c58b07e39883E@plt>:
  4c3f40:      	adrp	x16, 0x4e6000
  4c3f44:      	ldr	x17, [x16, #0xcd8]
  4c3f48:      	add	x16, x16, #0xcd8
  4c3f4c:      	br	x17

00000000004c3f50 <_ZN3std9panicking20rust_panic_with_hook17h9f7b5c3bc5693641E@plt>:
  4c3f50:      	adrp	x16, 0x4e6000
  4c3f54:      	ldr	x17, [x16, #0xce0]
  4c3f58:      	add	x16, x16, #0xce0
  4c3f5c:      	br	x17

00000000004c3f60 <_ZN7lodepng72_$LT$impl$u20$core..default..Default$u20$for$u20$lodepng..ffi..State$GT$7default17h1fc6b39536ad1444E@plt>:
  4c3f60:      	adrp	x16, 0x4e6000
  4c3f64:      	ldr	x17, [x16, #0xce8]
  4c3f68:      	add	x16, x16, #0xce8
  4c3f6c:      	br	x17

00000000004c3f70 <_ZN7lodepng8rustimpl14lodepng_decode17h00e833a8100e0bbdE@plt>:
  4c3f70:      	adrp	x16, 0x4e6000
  4c3f74:      	ldr	x17, [x16, #0xcf0]
  4c3f78:      	add	x16, x16, #0xcf0
  4c3f7c:      	br	x17

00000000004c3f80 <_ZN7lodepng10new_bitmap17hb4036e934f89c4e8E@plt>:
  4c3f80:      	adrp	x16, 0x4e6000
  4c3f84:      	ldr	x17, [x16, #0xcf8]
  4c3f88:      	add	x16, x16, #0xcf8
  4c3f8c:      	br	x17

00000000004c3f90 <_ZN90_$LT$lodepng..error..Error$u20$as$u20$core..convert..From$LT$std..io..error..Error$GT$$GT$4from17h79235284b8bb5f87E@plt>:
  4c3f90:      	adrp	x16, 0x4e6000
  4c3f94:      	ldr	x17, [x16, #0xd00]
  4c3f98:      	add	x16, x16, #0xd00
  4c3f9c:      	br	x17

00000000004c3fa0 <_ZN7lodepng5error5Error3new17h8b879976674f8680E@plt>:
  4c3fa0:      	adrp	x16, 0x4e6000
  4c3fa4:      	ldr	x17, [x16, #0xd08]
  4c3fa8:      	add	x16, x16, #0xd08
  4c3fac:      	br	x17

00000000004c3fb0 <_ZN4core3fmt9Formatter15debug_lower_hex17h100dbb1d2cd149a1E@plt>:
  4c3fb0:      	adrp	x16, 0x4e6000
  4c3fb4:      	ldr	x17, [x16, #0xd10]
  4c3fb8:      	add	x16, x16, #0xd10
  4c3fbc:      	br	x17

00000000004c3fc0 <_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$u8$GT$3fmt17hb97233245b17ca73E@plt>:
  4c3fc0:      	adrp	x16, 0x4e6000
  4c3fc4:      	ldr	x17, [x16, #0xd18]
  4c3fc8:      	add	x16, x16, #0xd18
  4c3fcc:      	br	x17

00000000004c3fd0 <_ZN4core3fmt9Formatter15debug_upper_hex17hfd02c31fdba8e80bE@plt>:
  4c3fd0:      	adrp	x16, 0x4e6000
  4c3fd4:      	ldr	x17, [x16, #0xd20]
  4c3fd8:      	add	x16, x16, #0xd20
  4c3fdc:      	br	x17

00000000004c3fe0 <_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$u8$GT$3fmt17hef628c4c0440c5b0E@plt>:
  4c3fe0:      	adrp	x16, 0x4e6000
  4c3fe4:      	ldr	x17, [x16, #0xd28]
  4c3fe8:      	add	x16, x16, #0xd28
  4c3fec:      	br	x17

00000000004c3ff0 <_ZN4core3fmt3num3imp51_$LT$impl$u20$core..fmt..Display$u20$for$u20$u8$GT$3fmt17hd70ce71cff9d551eE@plt>:
  4c3ff0:      	adrp	x16, 0x4e6000
  4c3ff4:      	ldr	x17, [x16, #0xd30]
  4c3ff8:      	add	x16, x16, #0xd30
  4c3ffc:      	br	x17

00000000004c4000 <_ZN4core3fmt3num55_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$usize$GT$3fmt17h4ae83a494fc9ba45E@plt>:
  4c4000:      	adrp	x16, 0x4e6000
  4c4004:      	ldr	x17, [x16, #0xd38]
  4c4008:      	add	x16, x16, #0xd38
  4c400c:      	br	x17

00000000004c4010 <_ZN4core3fmt3num55_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$usize$GT$3fmt17h75de3fef315762bdE@plt>:
  4c4010:      	adrp	x16, 0x4e6000
  4c4014:      	ldr	x17, [x16, #0xd40]
  4c4018:      	add	x16, x16, #0xd40
  4c401c:      	br	x17

00000000004c4020 <_ZN6resize5Scale3new17hc0926abf77cf8d8bE@plt>:
  4c4020:      	adrp	x16, 0x4e6000
  4c4024:      	ldr	x17, [x16, #0xd48]
  4c4028:      	add	x16, x16, #0xd48
  4c402c:      	br	x17

00000000004c4030 <_ZN10imagequant4attr10Attributes11set_quality17h86c01618e0839f53E@plt>:
  4c4030:      	adrp	x16, 0x4e6000
  4c4034:      	ldr	x17, [x16, #0xd50]
  4c4038:      	add	x16, x16, #0xd50
  4c403c:      	br	x17

00000000004c4040 <_ZN10imagequant5image5Image19new_stride_internal17h89f126b7e6aa9a6fE@plt>:
  4c4040:      	adrp	x16, 0x4e6000
  4c4044:      	ldr	x17, [x16, #0xd58]
  4c4048:      	add	x16, x16, #0xd58
  4c404c:      	br	x17

00000000004c4050 <_ZN10imagequant5image5Image15add_fixed_color17h6504fb5aeb5b4919E@plt>:
  4c4050:      	adrp	x16, 0x4e6000
  4c4054:      	ldr	x17, [x16, #0xd60]
  4c4058:      	add	x16, x16, #0xd60
  4c405c:      	br	x17

00000000004c4060 <_ZN10imagequant4attr10Attributes8quantize17h5d1e2438bd29f28dE@plt>:
  4c4060:      	adrp	x16, 0x4e6000
  4c4064:      	ldr	x17, [x16, #0xd68]
  4c4068:      	add	x16, x16, #0xd68
  4c406c:      	br	x17

00000000004c4070 <_ZN10imagequant5quant18QuantizationResult19set_dithering_level17h8238cb97ba8e68dcE@plt>:
  4c4070:      	adrp	x16, 0x4e6000
  4c4074:      	ldr	x17, [x16, #0xd70]
  4c4078:      	add	x16, x16, #0xd70
  4c407c:      	br	x17

00000000004c4080 <_ZN107_$LT$imagequant..error..Error$u20$as$u20$core..convert..From$LT$alloc..collections..TryReserveError$GT$$GT$4from17hdac329fe32d25804E@plt>:
  4c4080:      	adrp	x16, 0x4e6000
  4c4084:      	ldr	x17, [x16, #0xd78]
  4c4088:      	add	x16, x16, #0xd78
  4c408c:      	br	x17

00000000004c4090 <_ZN10imagequant5quant18QuantizationResult52optionally_prepare_for_dithering_with_background_set17h1946cfde45836ae3E@plt>:
  4c4090:      	adrp	x16, 0x4e6000
  4c4094:      	ldr	x17, [x16, #0xd80]
  4c4098:      	add	x16, x16, #0xd80
  4c409c:      	br	x17

00000000004c40a0 <_ZN10imagequant5image5Image14set_background17h904dca6742cf21ffE@plt>:
  4c40a0:      	adrp	x16, 0x4e6000
  4c40a4:      	ldr	x17, [x16, #0xd88]
  4c40a8:      	add	x16, x16, #0xd88
  4c40ac:      	br	x17

00000000004c40b0 <_ZN10imagequant5quant18QuantizationResult34write_remapped_image_rows_internal17h8fe5cddcdf23f387E@plt>:
  4c40b0:      	adrp	x16, 0x4e6000
  4c40b4:      	ldr	x17, [x16, #0xd90]
  4c40b8:      	add	x16, x16, #0xd90
  4c40bc:      	br	x17

00000000004c40c0 <_ZN10imagequant5quant18QuantizationResult11palette_vec17h19f3e4bbcabb33dfE@plt>:
  4c40c0:      	adrp	x16, 0x4e6000
  4c40c4:      	ldr	x17, [x16, #0xd98]
  4c40c8:      	add	x16, x16, #0xd98
  4c40cc:      	br	x17

00000000004c40d0 <__rust_alloc_error_handler@plt>:
  4c40d0:      	adrp	x16, 0x4e6000
  4c40d4:      	ldr	x17, [x16, #0xda0]
  4c40d8:      	add	x16, x16, #0xda0
  4c40dc:      	br	x17

00000000004c40e0 <_ZN7lodepng8rustimpl12ChunkBuilder6finish17h33f225491479db91E@plt>:
  4c40e0:      	adrp	x16, 0x4e6000
  4c40e4:      	ldr	x17, [x16, #0xda8]
  4c40e8:      	add	x16, x16, #0xda8
  4c40ec:      	br	x17

00000000004c40f0 <_ZN7lodepng8rustimpl26lodepng_chunk_generate_crc17hba09aabb1f8a93adE@plt>:
  4c40f0:      	adrp	x16, 0x4e6000
  4c40f4:      	ldr	x17, [x16, #0xdb0]
  4c40f8:      	add	x16, x16, #0xdb0
  4c40fc:      	br	x17

00000000004c4100 <_ZN7lodepng8rustimpl15lodepng_inspect17h01da86b5bfd39b4eE@plt>:
  4c4100:      	adrp	x16, 0x4e6000
  4c4104:      	ldr	x17, [x16, #0xdb8]
  4c4108:      	add	x16, x16, #0xdb8
  4c410c:      	br	x17

00000000004c4110 <_ZN4core5slice29_$LT$impl$u20$$u5b$T$u5d$$GT$15copy_from_slice17len_mismatch_fail17hd503e84eb2d135bcE@plt>:
  4c4110:      	adrp	x16, 0x4e6000
  4c4114:      	ldr	x17, [x16, #0xdc0]
  4c4118:      	add	x16, x16, #0xdc0
  4c411c:      	br	x17

00000000004c4120 <_ZN3std3sys4unix7android7log2f3217h2347818455d1f412E@plt>:
  4c4120:      	adrp	x16, 0x4e6000
  4c4124:      	ldr	x17, [x16, #0xdc8]
  4c4128:      	add	x16, x16, #0xdc8
  4c412c:      	br	x17

00000000004c4130 <_ZN6flate211Compression3new17h155a8f24be39f35cE@plt>:
  4c4130:      	adrp	x16, 0x4e6000
  4c4134:      	ldr	x17, [x16, #0xdd0]
  4c4138:      	add	x16, x16, #0xdd0
  4c413c:      	br	x17

00000000004c4140 <_ZN6flate23mem8Compress3new17h8db6a476a95003e7E@plt>:
  4c4140:      	adrp	x16, 0x4e6000
  4c4144:      	ldr	x17, [x16, #0xdd8]
  4c4148:      	add	x16, x16, #0xdd8
  4c414c:      	br	x17

00000000004c4150 <_ZN9crc32fast6Hasher3new17h170e62db2a1c40b8E@plt>:
  4c4150:      	adrp	x16, 0x4e6000
  4c4154:      	ldr	x17, [x16, #0xde0]
  4c4158:      	add	x16, x16, #0xde0
  4c415c:      	br	x17

00000000004c4160 <_ZN9crc32fast6Hasher6update17h6df013e960b83634E@plt>:
  4c4160:      	adrp	x16, 0x4e6000
  4c4164:      	ldr	x17, [x16, #0xde8]
  4c4168:      	add	x16, x16, #0xde8
  4c416c:      	br	x17

00000000004c4170 <_ZN6flate211Compression4none17h5d16fc01e1cb66ebE@plt>:
  4c4170:      	adrp	x16, 0x4e6000
  4c4174:      	ldr	x17, [x16, #0xdf0]
  4c4178:      	add	x16, x16, #0xdf0
  4c417c:      	br	x17

00000000004c4180 <_ZN9crc32fast6Hasher8finalize17h508d8559f2b1c942E@plt>:
  4c4180:      	adrp	x16, 0x4e6000
  4c4184:      	ldr	x17, [x16, #0xdf8]
  4c4188:      	add	x16, x16, #0xdf8
  4c418c:      	br	x17

00000000004c4190 <_ZN9crc32fast4hash17h4ae232e3a367edb8E@plt>:
  4c4190:      	adrp	x16, 0x4e6000
  4c4194:      	ldr	x17, [x16, #0xe00]
  4c4198:      	add	x16, x16, #0xe00
  4c419c:      	br	x17

00000000004c41a0 <_ZN6flate23mem10Decompress3new17h6d616d1a74df532dE@plt>:
  4c41a0:      	adrp	x16, 0x4e6000
  4c41a4:      	ldr	x17, [x16, #0xe08]
  4c41a8:      	add	x16, x16, #0xe08
  4c41ac:      	br	x17

00000000004c41b0 <_ZN7lodepng8ChunkRef9check_crc17h3a36af91159987beE@plt>:
  4c41b0:      	adrp	x16, 0x4e6000
  4c41b4:      	ldr	x17, [x16, #0xe10]
  4c41b8:      	add	x16, x16, #0xe10
  4c41bc:      	br	x17

00000000004c41c0 <_ZN7lodepng8rustimpl36_$LT$impl$u20$lodepng..ffi..Info$GT$9push_text17hf3f22449b23525a2E@plt>:
  4c41c0:      	adrp	x16, 0x4e6000
  4c41c4:      	ldr	x17, [x16, #0xe18]
  4c41c8:      	add	x16, x16, #0xe18
  4c41cc:      	br	x17

00000000004c41d0 <_ZN7lodepng41_$LT$impl$u20$lodepng..ffi..ColorMode$GT$12raw_size_opt17hf03ff9794a483283E@plt>:
  4c41d0:      	adrp	x16, 0x4e6000
  4c41d4:      	ldr	x17, [x16, #0xe20]
  4c41d8:      	add	x16, x16, #0xe20
  4c41dc:      	br	x17

00000000004c41e0 <_ZN3std2fs5write5inner17h3383bb0d753d112dE@plt>:
  4c41e0:      	adrp	x16, 0x4e6000
  4c41e4:      	ldr	x17, [x16, #0xe28]
  4c41e8:      	add	x16, x16, #0xe28
  4c41ec:      	br	x17

00000000004c41f0 <_ZN7lodepng8rustimpl14lodepng_encode17hb4e92ae2417b0f7fE@plt>:
  4c41f0:      	adrp	x16, 0x4e6000
  4c41f4:      	ldr	x17, [x16, #0xe30]
  4c41f8:      	add	x16, x16, #0xe30
  4c41fc:      	br	x17

00000000004c4200 <_ZN60_$LT$lodepng..ffi..ColorType$u20$as$u20$core..fmt..Debug$GT$3fmt17h6e6fec86d9196299E@plt>:
  4c4200:      	adrp	x16, 0x4e6000
  4c4204:      	ldr	x17, [x16, #0xe38]
  4c4208:      	add	x16, x16, #0xe38
  4c420c:      	br	x17

00000000004c4210 <_ZN69_$LT$lodepng..ffi..DecompressSettings$u20$as$u20$core..fmt..Debug$GT$3fmt17hbb08164e0dab07fcE@plt>:
  4c4210:      	adrp	x16, 0x4e6000
  4c4214:      	ldr	x17, [x16, #0xe40]
  4c4218:      	add	x16, x16, #0xe40
  4c421c:      	br	x17

00000000004c4220 <_ZN7lodepng5error70_$LT$impl$u20$core..fmt..Debug$u20$for$u20$lodepng..ffi..ErrorCode$GT$3fmt17he06243056ba97878E@plt>:
  4c4220:      	adrp	x16, 0x4e6000
  4c4224:      	ldr	x17, [x16, #0xe48]
  4c4228:      	add	x16, x16, #0xe48
  4c422c:      	br	x17

00000000004c4230 <_ZN67_$LT$lodepng..ffi..CompressSettings$u20$as$u20$core..fmt..Debug$GT$3fmt17hc5b0fba1667ce229E@plt>:
  4c4230:      	adrp	x16, 0x4e6000
  4c4234:      	ldr	x17, [x16, #0xe50]
  4c4238:      	add	x16, x16, #0xe50
  4c423c:      	br	x17

00000000004c4240 <_ZN7lodepng5error41_$LT$impl$u20$lodepng..ffi..ErrorCode$GT$13c_description17h7f10092a8292ffcaE@plt>:
  4c4240:      	adrp	x16, 0x4e6000
  4c4244:      	ldr	x17, [x16, #0xe58]
  4c4248:      	add	x16, x16, #0xe58
  4c424c:      	br	x17

00000000004c4250 <_ZN43_$LT$bool$u20$as$u20$core..fmt..Display$GT$3fmt17h0d0aa8234700c608E@plt>:
  4c4250:      	adrp	x16, 0x4e6000
  4c4254:      	ldr	x17, [x16, #0xe60]
  4c4258:      	add	x16, x16, #0xe60
  4c425c:      	br	x17

00000000004c4260 <_ZN4core3fmt9Formatter26debug_struct_field5_finish17hf67eaff68f75f8e8E@plt>:
  4c4260:      	adrp	x16, 0x4e6000
  4c4264:      	ldr	x17, [x16, #0xe68]
  4c4268:      	add	x16, x16, #0xe68
  4c426c:      	br	x17

00000000004c4270 <_ZN4core3fmt9Formatter26debug_struct_field2_finish17h6c96ab3aa5e6fe85E@plt>:
  4c4270:      	adrp	x16, 0x4e6000
  4c4274:      	ldr	x17, [x16, #0xe70]
  4c4278:      	add	x16, x16, #0xe70
  4c427c:      	br	x17

00000000004c4280 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$u16$GT$3fmt17hb33d23cab7e2b23eE@plt>:
  4c4280:      	adrp	x16, 0x4e6000
  4c4284:      	ldr	x17, [x16, #0xe78]
  4c4288:      	add	x16, x16, #0xe78
  4c428c:      	br	x17

00000000004c4290 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$u16$GT$3fmt17h9f732404b26f51c3E@plt>:
  4c4290:      	adrp	x16, 0x4e6000
  4c4294:      	ldr	x17, [x16, #0xe80]
  4c4298:      	add	x16, x16, #0xe80
  4c429c:      	br	x17

00000000004c42a0 <_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$u16$GT$3fmt17h3275d2200b92e20eE@plt>:
  4c42a0:      	adrp	x16, 0x4e6000
  4c42a4:      	ldr	x17, [x16, #0xe88]
  4c42a8:      	add	x16, x16, #0xe88
  4c42ac:      	br	x17

00000000004c42b0 <_ZN4core3fmt8builders11DebugStruct5field17h5dadcfb0f2b5759fE@plt>:
  4c42b0:      	adrp	x16, 0x4e6000
  4c42b4:      	ldr	x17, [x16, #0xe90]
  4c42b8:      	add	x16, x16, #0xe90
  4c42bc:      	br	x17

00000000004c42c0 <_ZN4core3fmt8builders11DebugStruct6finish17h3def4826ec2c6ebeE@plt>:
  4c42c0:      	adrp	x16, 0x4e6000
  4c42c4:      	ldr	x17, [x16, #0xe98]
  4c42c8:      	add	x16, x16, #0xe98
  4c42cc:      	br	x17

00000000004c42d0 <lodepng_decode_file@plt>:
  4c42d0:      	adrp	x16, 0x4e6000
  4c42d4:      	ldr	x17, [x16, #0xea0]
  4c42d8:      	add	x16, x16, #0xea0
  4c42dc:      	br	x17

00000000004c42e0 <_ZN3std2fs11OpenOptions4read17hb247bb08a49532a5E@plt>:
  4c42e0:      	adrp	x16, 0x4e6000
  4c42e4:      	ldr	x17, [x16, #0xea8]
  4c42e8:      	add	x16, x16, #0xea8
  4c42ec:      	br	x17

00000000004c42f0 <_ZN3std3sys4unix2fs4stat17he850e8d5a8a5c740E@plt>:
  4c42f0:      	adrp	x16, 0x4e6000
  4c42f4:      	ldr	x17, [x16, #0xeb0]
  4c42f8:      	add	x16, x16, #0xeb0
  4c42fc:      	br	x17

00000000004c4300 <_ZN3std2fs8Metadata3len17he2aef1641a6a60cbE@plt>:
  4c4300:      	adrp	x16, 0x4e6000
  4c4304:      	ldr	x17, [x16, #0xeb8]
  4c4308:      	add	x16, x16, #0xeb8
  4c430c:      	br	x17

00000000004c4310 <_ZN5alloc6string6String15from_utf8_lossy17hcc68a4a1e943558dE@plt>:
  4c4310:      	adrp	x16, 0x4e6000
  4c4314:      	ldr	x17, [x16, #0xec0]
  4c4318:      	add	x16, x16, #0xec0
  4c431c:      	br	x17

00000000004c4320 <_ZN5alloc6string107_$LT$impl$u20$core..convert..From$LT$alloc..string..String$GT$$u20$for$u20$alloc..boxed..Box$LT$str$GT$$GT$4from17h011b9932c976202bE@plt>:
  4c4320:      	adrp	x16, 0x4e6000
  4c4324:      	ldr	x17, [x16, #0xec8]
  4c4328:      	add	x16, x16, #0xec8
  4c432c:      	br	x17

00000000004c4330 <_ZN4core3str8converts9from_utf817h1c861e7fb8a1d145E@plt>:
  4c4330:      	adrp	x16, 0x4e6000
  4c4334:      	ldr	x17, [x16, #0xed0]
  4c4338:      	add	x16, x16, #0xed0
  4c433c:      	br	x17

00000000004c4340 <_ZN3std3sys4unix4rand19hashmap_random_keys17hf44bd262b7a88b5dE@plt>:
  4c4340:      	adrp	x16, 0x4e6000
  4c4344:      	ldr	x17, [x16, #0xed8]
  4c4348:      	add	x16, x16, #0xed8
  4c434c:      	br	x17

00000000004c4350 <_ZN47_$LT$std..fs..File$u20$as$u20$std..io..Read$GT$4read17h68c908a1d978ca57E@plt>:
  4c4350:      	adrp	x16, 0x4e6000
  4c4354:      	ldr	x17, [x16, #0xee0]
  4c4358:      	add	x16, x16, #0xee0
  4c435c:      	br	x17

00000000004c4360 <_ZN4core3fmt17pointer_fmt_inner17h0b83a04d65d05000E@plt>:
  4c4360:      	adrp	x16, 0x4e6000
  4c4364:      	ldr	x17, [x16, #0xee8]
  4c4368:      	add	x16, x16, #0xee8
  4c436c:      	br	x17

00000000004c4370 <_ZN4core3fmt9Formatter26debug_struct_field1_finish17h3ce2c041f21a85bbE@plt>:
  4c4370:      	adrp	x16, 0x4e6000
  4c4374:      	ldr	x17, [x16, #0xef0]
  4c4378:      	add	x16, x16, #0xef0
  4c437c:      	br	x17

00000000004c4380 <_ZN67_$LT$alloc..boxed..Box$LT$str$GT$$u20$as$u20$core..clone..Clone$GT$5clone17h71ebb827de5434dfE@plt>:
  4c4380:      	adrp	x16, 0x4e6000
  4c4384:      	ldr	x17, [x16, #0xef8]
  4c4388:      	add	x16, x16, #0xef8
  4c438c:      	br	x17

00000000004c4390 <_ZN65_$LT$flate2..mem..FlushCompress$u20$as$u20$flate2..zio..Flush$GT$4sync17h2f76b32585ee9ca1E@plt>:
  4c4390:      	adrp	x16, 0x4e6000
  4c4394:      	ldr	x17, [x16, #0xf00]
  4c4398:      	add	x16, x16, #0xf00
  4c439c:      	br	x17

00000000004c43a0 <_ZN58_$LT$flate2..mem..Compress$u20$as$u20$flate2..zio..Ops$GT$7run_vec17h6299cf84b96d64cfE@plt>:
  4c43a0:      	adrp	x16, 0x4e6000
  4c43a4:      	ldr	x17, [x16, #0xf08]
  4c43a8:      	add	x16, x16, #0xf08
  4c43ac:      	br	x17

00000000004c43b0 <_ZN58_$LT$flate2..mem..Compress$u20$as$u20$flate2..zio..Ops$GT$9total_out17ha2069bf9f68e9dfdE@plt>:
  4c43b0:      	adrp	x16, 0x4e6000
  4c43b4:      	ldr	x17, [x16, #0xf10]
  4c43b8:      	add	x16, x16, #0xf10
  4c43bc:      	br	x17

00000000004c43c0 <_ZN65_$LT$flate2..mem..FlushCompress$u20$as$u20$flate2..zio..Flush$GT$4none17h1e9b2c7d34befb51E@plt>:
  4c43c0:      	adrp	x16, 0x4e6000
  4c43c4:      	ldr	x17, [x16, #0xf18]
  4c43c8:      	add	x16, x16, #0xf18
  4c43cc:      	br	x17

00000000004c43d0 <_ZN58_$LT$flate2..mem..Compress$u20$as$u20$flate2..zio..Ops$GT$8total_in17h8705cf3724924aebE@plt>:
  4c43d0:      	adrp	x16, 0x4e6000
  4c43d4:      	ldr	x17, [x16, #0xf20]
  4c43d8:      	add	x16, x16, #0xf20
  4c43dc:      	br	x17

00000000004c43e0 <_ZN60_$LT$flate2..mem..Decompress$u20$as$u20$flate2..zio..Ops$GT$9total_out17hfd118964600b5d4dE@plt>:
  4c43e0:      	adrp	x16, 0x4e6000
  4c43e4:      	ldr	x17, [x16, #0xf28]
  4c43e8:      	add	x16, x16, #0xf28
  4c43ec:      	br	x17

00000000004c43f0 <_ZN60_$LT$flate2..mem..Decompress$u20$as$u20$flate2..zio..Ops$GT$8total_in17hfbf6a4271dce1be9E@plt>:
  4c43f0:      	adrp	x16, 0x4e6000
  4c43f4:      	ldr	x17, [x16, #0xf30]
  4c43f8:      	add	x16, x16, #0xf30
  4c43fc:      	br	x17

00000000004c4400 <_ZN67_$LT$flate2..mem..FlushDecompress$u20$as$u20$flate2..zio..Flush$GT$6finish17h1ba7ce0f752356ccE@plt>:
  4c4400:      	adrp	x16, 0x4e6000
  4c4404:      	ldr	x17, [x16, #0xf38]
  4c4408:      	add	x16, x16, #0xf38
  4c440c:      	br	x17

00000000004c4410 <_ZN67_$LT$flate2..mem..FlushDecompress$u20$as$u20$flate2..zio..Flush$GT$4none17h5ad1c0f26d434ee1E@plt>:
  4c4410:      	adrp	x16, 0x4e6000
  4c4414:      	ldr	x17, [x16, #0xf40]
  4c4418:      	add	x16, x16, #0xf40
  4c441c:      	br	x17

00000000004c4420 <_ZN60_$LT$flate2..mem..Decompress$u20$as$u20$flate2..zio..Ops$GT$3run17h90e83fefc92b055dE@plt>:
  4c4420:      	adrp	x16, 0x4e6000
  4c4424:      	ldr	x17, [x16, #0xf48]
  4c4428:      	add	x16, x16, #0xf48
  4c442c:      	br	x17

00000000004c4430 <_ZN65_$LT$flate2..mem..FlushCompress$u20$as$u20$flate2..zio..Flush$GT$6finish17haa1c791a2d193a4aE@plt>:
  4c4430:      	adrp	x16, 0x4e6000
  4c4434:      	ldr	x17, [x16, #0xf50]
  4c4438:      	add	x16, x16, #0xf50
  4c443c:      	br	x17

00000000004c4440 <_ZN6flate23mem107_$LT$impl$u20$core..convert..From$LT$flate2..mem..DecompressError$GT$$u20$for$u20$std..io..error..Error$GT$4from17h951203329b4b223dE@plt>:
  4c4440:      	adrp	x16, 0x4e6000
  4c4444:      	ldr	x17, [x16, #0xf58]
  4c4448:      	add	x16, x16, #0xf58
  4c444c:      	br	x17

00000000004c4450 <_ZN9hashbrown3raw11Fallibility17capacity_overflow17hee7ae6d42535e4b6E@plt>:
  4c4450:      	adrp	x16, 0x4e6000
  4c4454:      	ldr	x17, [x16, #0xf60]
  4c4458:      	add	x16, x16, #0xf60
  4c445c:      	br	x17

00000000004c4460 <_ZN9hashbrown3raw11Fallibility9alloc_err17h230e65c2f06240aaE@plt>:
  4c4460:      	adrp	x16, 0x4e6000
  4c4464:      	ldr	x17, [x16, #0xf68]
  4c4468:      	add	x16, x16, #0xf68
  4c446c:      	br	x17

00000000004c4470 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$u32$GT$3fmt17ha40dd5058366274dE@plt>:
  4c4470:      	adrp	x16, 0x4e6000
  4c4474:      	ldr	x17, [x16, #0xf70]
  4c4478:      	add	x16, x16, #0xf70
  4c447c:      	br	x17

00000000004c4480 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$u32$GT$3fmt17hff7e59328ca492fcE@plt>:
  4c4480:      	adrp	x16, 0x4e6000
  4c4484:      	ldr	x17, [x16, #0xf78]
  4c4488:      	add	x16, x16, #0xf78
  4c448c:      	br	x17

00000000004c4490 <_ZN74_$LT$flate2..ffi..rust..Deflate$u20$as$u20$flate2..ffi..DeflateBackend$GT$4make17hc4aab1f7ac4bb899E@plt>:
  4c4490:      	adrp	x16, 0x4e6000
  4c4494:      	ldr	x17, [x16, #0xf80]
  4c4498:      	add	x16, x16, #0xf80
  4c449c:      	br	x17

00000000004c44a0 <_ZN11miniz_oxide7deflate4core15CompressorOxide5reset17h989a332a8c51eac0E@plt>:
  4c44a0:      	adrp	x16, 0x4e6000
  4c44a4:      	ldr	x17, [x16, #0xf88]
  4c44a8:      	add	x16, x16, #0xf88
  4c44ac:      	br	x17

00000000004c44b0 <_ZN11miniz_oxide7MZFlush3new17hbd2ed8bb52cca2b9E@plt>:
  4c44b0:      	adrp	x16, 0x4e6000
  4c44b4:      	ldr	x17, [x16, #0xf90]
  4c44b8:      	add	x16, x16, #0xf90
  4c44bc:      	br	x17

00000000004c44c0 <_ZN11miniz_oxide7deflate6stream7deflate17hfd03128d22ec8497E@plt>:
  4c44c0:      	adrp	x16, 0x4e6000
  4c44c4:      	ldr	x17, [x16, #0xf98]
  4c44c8:      	add	x16, x16, #0xf98
  4c44cc:      	br	x17

00000000004c44d0 <_ZN11miniz_oxide7inflate6stream12InflateState9new_boxed17h815e55312609ab33E@plt>:
  4c44d0:      	adrp	x16, 0x4e6000
  4c44d4:      	ldr	x17, [x16, #0xfa0]
  4c44d8:      	add	x16, x16, #0xfa0
  4c44dc:      	br	x17

00000000004c44e0 <_ZN74_$LT$flate2..ffi..rust..Inflate$u20$as$u20$flate2..ffi..InflateBackend$GT$10decompress17hebe0ef29fe026a33E@plt>:
  4c44e0:      	adrp	x16, 0x4e6000
  4c44e4:      	ldr	x17, [x16, #0xfa8]
  4c44e8:      	add	x16, x16, #0xfa8
  4c44ec:      	br	x17

00000000004c44f0 <_ZN100_$LT$miniz_oxide..inflate..stream..MinReset$u20$as$u20$miniz_oxide..inflate..stream..ResetPolicy$GT$5reset17h180ea3dec0afadf5E@plt>:
  4c44f0:      	adrp	x16, 0x4e6000
  4c44f4:      	ldr	x17, [x16, #0xfb0]
  4c44f8:      	add	x16, x16, #0xfb0
  4c44fc:      	br	x17

00000000004c4500 <_ZN63_$LT$alloc..ffi..c_str..CString$u20$as$u20$core..fmt..Debug$GT$3fmt17hb240a3931f488ab6E@plt>:
  4c4500:      	adrp	x16, 0x4e6000
  4c4504:      	ldr	x17, [x16, #0xfb8]
  4c4508:      	add	x16, x16, #0xfb8
  4c450c:      	br	x17

00000000004c4510 <_ZN86_$LT$miniz_oxide..deflate..core..CompressorOxide$u20$as$u20$core..default..Default$GT$7default17hf75bb7581ba9cb7bE@plt>:
  4c4510:      	adrp	x16, 0x4e6000
  4c4514:      	ldr	x17, [x16, #0xfc0]
  4c4518:      	add	x16, x16, #0xfc0
  4c451c:      	br	x17

00000000004c4520 <_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$u64$GT$3fmt17hb66ffda77378fcb9E@plt>:
  4c4520:      	adrp	x16, 0x4e6000
  4c4524:      	ldr	x17, [x16, #0xfc8]
  4c4528:      	add	x16, x16, #0xfc8
  4c452c:      	br	x17

00000000004c4530 <_ZN11miniz_oxide7inflate6stream7inflate17h1e565bd6ca7af2b4E@plt>:
  4c4530:      	adrp	x16, 0x4e6000
  4c4534:      	ldr	x17, [x16, #0xfd0]
  4c4538:      	add	x16, x16, #0xfd0
  4c453c:      	br	x17

00000000004c4540 <_ZN11miniz_oxide7inflate6stream12InflateState12decompressor17ha1aff0f5ab9c62f4E@plt>:
  4c4540:      	adrp	x16, 0x4e6000
  4c4544:      	ldr	x17, [x16, #0xfd8]
  4c4548:      	add	x16, x16, #0xfd8
  4c454c:      	br	x17

00000000004c4550 <_ZN11miniz_oxide7inflate4core5State10is_failure17hd12eab01aa3ed535E@plt>:
  4c4550:      	adrp	x16, 0x4e6000
  4c4554:      	ldr	x17, [x16, #0xfe0]
  4c4558:      	add	x16, x16, #0xfe0
  4c455c:      	br	x17

00000000004c4560 <_ZN11miniz_oxide7deflate4core15CompressorOxide20set_format_and_level17hf0fcf53f65819009E@plt>:
  4c4560:      	adrp	x16, 0x4e6000
  4c4564:      	ldr	x17, [x16, #0xfe8]
  4c4568:      	add	x16, x16, #0xfe8
  4c456c:      	br	x17

00000000004c4570 <_ZN57_$LT$miniz_oxide..MZError$u20$as$u20$core..fmt..Debug$GT$3fmt17h9584e86d4cf68c4aE@plt>:
  4c4570:      	adrp	x16, 0x4e6000
  4c4574:      	ldr	x17, [x16, #0xff0]
  4c4578:      	add	x16, x16, #0xff0
  4c457c:      	br	x17

00000000004c4580 <_ZN11miniz_oxide7deflate4core14compress_inner17ha20e8e0b2c6dc00bE@plt>:
  4c4580:      	adrp	x16, 0x4e6000
  4c4584:      	ldr	x17, [x16, #0xff8]
  4c4588:      	add	x16, x16, #0xff8
  4c458c:      	br	x17

00000000004c4590 <_ZN5adler7Adler3211write_slice17hb34b9e07fa817ecaE@plt>:
  4c4590:      	adrp	x16, 0x4e7000
  4c4594:      	ldr	x17, [x16]
  4c4598:      	add	x16, x16, #0x0
  4c459c:      	br	x17

00000000004c45a0 <_ZN4core5slice5index29slice_end_index_overflow_fail17h01c836f6380c9334E@plt>:
  4c45a0:      	adrp	x16, 0x4e7000
  4c45a4:      	ldr	x17, [x16, #0x8]
  4c45a8:      	add	x16, x16, #0x8
  4c45ac:      	br	x17

00000000004c45b0 <_ZN11miniz_oxide7inflate4core10decompress17h083a674792ff8a71E@plt>:
  4c45b0:      	adrp	x16, 0x4e7000
  4c45b4:      	ldr	x17, [x16, #0x10]
  4c45b8:      	add	x16, x16, #0x10
  4c45bc:      	br	x17

00000000004c45c0 <sinf@plt>:
  4c45c0:      	adrp	x16, 0x4e7000
  4c45c4:      	ldr	x17, [x16, #0x18]
  4c45c8:      	add	x16, x16, #0x18
  4c45cc:      	br	x17

00000000004c45d0 <_ZN5alloc4sync32arcinner_layout_for_value_layout17hea0ee392d48401cbE@plt>:
  4c45d0:      	adrp	x16, 0x4e7000
  4c45d4:      	ldr	x17, [x16, #0x20]
  4c45d8:      	add	x16, x16, #0x20
  4c45dc:      	br	x17

00000000004c45e0 <_ZN4core3fmt5float50_$LT$impl$u20$core..fmt..Debug$u20$for$u20$f32$GT$3fmt17he485c8a368f72c8aE@plt>:
  4c45e0:      	adrp	x16, 0x4e7000
  4c45e4:      	ldr	x17, [x16, #0x28]
  4c45e8:      	add	x16, x16, #0x28
  4c45ec:      	br	x17

00000000004c45f0 <Clp_NewParser@plt>:
  4c45f0:      	adrp	x16, 0x4e7000
  4c45f4:      	ldr	x17, [x16, #0x30]
  4c45f8:      	add	x16, x16, #0x30
  4c45fc:      	br	x17

00000000004c4600 <Clp_AddType@plt>:
  4c4600:      	adrp	x16, 0x4e7000
  4c4604:      	ldr	x17, [x16, #0x38]
  4c4608:      	add	x16, x16, #0x38
  4c460c:      	br	x17

00000000004c4610 <Clp_SetOptions@plt>:
  4c4610:      	adrp	x16, 0x4e7000
  4c4614:      	ldr	x17, [x16, #0x40]
  4c4618:      	add	x16, x16, #0x40
  4c461c:      	br	x17

00000000004c4620 <Clp_OptionError@plt>:
  4c4620:      	adrp	x16, 0x4e7000
  4c4624:      	ldr	x17, [x16, #0x48]
  4c4628:      	add	x16, x16, #0x48
  4c462c:      	br	x17

00000000004c4630 <Clp_DeleteParser@plt>:
  4c4630:      	adrp	x16, 0x4e7000
  4c4634:      	ldr	x17, [x16, #0x50]
  4c4638:      	add	x16, x16, #0x50
  4c463c:      	br	x17

00000000004c4640 <Clp_SetErrorHandler@plt>:
  4c4640:      	adrp	x16, 0x4e7000
  4c4644:      	ldr	x17, [x16, #0x58]
  4c4648:      	add	x16, x16, #0x58
  4c464c:      	br	x17

00000000004c4650 <Clp_SetOptionChar@plt>:
  4c4650:      	adrp	x16, 0x4e7000
  4c4654:      	ldr	x17, [x16, #0x60]
  4c4658:      	add	x16, x16, #0x60
  4c465c:      	br	x17

00000000004c4660 <Clp_AddStringListType@plt>:
  4c4660:      	adrp	x16, 0x4e7000
  4c4664:      	ldr	x17, [x16, #0x68]
  4c4668:      	add	x16, x16, #0x68
  4c466c:      	br	x17

00000000004c4670 <Clp_ProgramName@plt>:
  4c4670:      	adrp	x16, 0x4e7000
  4c4674:      	ldr	x17, [x16, #0x70]
  4c4678:      	add	x16, x16, #0x70
  4c467c:      	br	x17

00000000004c4680 <Clp_Next@plt>:
  4c4680:      	adrp	x16, 0x4e7000
  4c4684:      	ldr	x17, [x16, #0x78]
  4c4688:      	add	x16, x16, #0x78
  4c468c:      	br	x17

00000000004c4690 <Clp_Shift@plt>:
  4c4690:      	adrp	x16, 0x4e7000
  4c4694:      	ldr	x17, [x16, #0x80]
  4c4698:      	add	x16, x16, #0x80
  4c469c:      	br	x17

00000000004c46a0 <Clp_vsnprintf@plt>:
  4c46a0:      	adrp	x16, 0x4e7000
  4c46a4:      	ldr	x17, [x16, #0x88]
  4c46a8:      	add	x16, x16, #0x88
  4c46ac:      	br	x17

00000000004c46b0 <Clp_CurOptionNameBuf@plt>:
  4c46b0:      	adrp	x16, 0x4e7000
  4c46b4:      	ldr	x17, [x16, #0x90]
  4c46b8:      	add	x16, x16, #0x90
  4c46bc:      	br	x17

00000000004c46c0 <Clp_CurOptionName@plt>:
  4c46c0:      	adrp	x16, 0x4e7000
  4c46c4:      	ldr	x17, [x16, #0x98]
  4c46c8:      	add	x16, x16, #0x98
  4c46cc:      	br	x17

00000000004c46d0 <Gif_Realloc@plt>:
  4c46d0:      	adrp	x16, 0x4e7000
  4c46d4:      	ldr	x17, [x16, #0xa0]
  4c46d8:      	add	x16, x16, #0xa0
  4c46dc:      	br	x17

00000000004c46e0 <Gif_Free@plt>:
  4c46e0:      	adrp	x16, 0x4e7000
  4c46e4:      	ldr	x17, [x16, #0xa8]
  4c46e8:      	add	x16, x16, #0xa8
  4c46ec:      	br	x17

00000000004c46f0 <Gif_NewStream@plt>:
  4c46f0:      	adrp	x16, 0x4e7000
  4c46f4:      	ldr	x17, [x16, #0xb0]
  4c46f8:      	add	x16, x16, #0xb0
  4c46fc:      	br	x17

00000000004c4700 <Gif_NewComment@plt>:
  4c4700:      	adrp	x16, 0x4e7000
  4c4704:      	ldr	x17, [x16, #0xb8]
  4c4708:      	add	x16, x16, #0xb8
  4c470c:      	br	x17

00000000004c4710 <Gif_NewExtension@plt>:
  4c4710:      	adrp	x16, 0x4e7000
  4c4714:      	ldr	x17, [x16, #0xc0]
  4c4718:      	add	x16, x16, #0xc0
  4c471c:      	br	x17

00000000004c4720 <Gif_CopyExtension@plt>:
  4c4720:      	adrp	x16, 0x4e7000
  4c4724:      	ldr	x17, [x16, #0xc8]
  4c4728:      	add	x16, x16, #0xc8
  4c472c:      	br	x17

00000000004c4730 <Gif_CopyString@plt>:
  4c4730:      	adrp	x16, 0x4e7000
  4c4734:      	ldr	x17, [x16, #0xd0]
  4c4738:      	add	x16, x16, #0xd0
  4c473c:      	br	x17

00000000004c4740 <Gif_AddImage@plt>:
  4c4740:      	adrp	x16, 0x4e7000
  4c4744:      	ldr	x17, [x16, #0xd8]
  4c4748:      	add	x16, x16, #0xd8
  4c474c:      	br	x17

00000000004c4750 <Gif_RemoveImage@plt>:
  4c4750:      	adrp	x16, 0x4e7000
  4c4754:      	ldr	x17, [x16, #0xe0]
  4c4758:      	add	x16, x16, #0xe0
  4c475c:      	br	x17

00000000004c4760 <Gif_ImageColorBound@plt>:
  4c4760:      	adrp	x16, 0x4e7000
  4c4764:      	ldr	x17, [x16, #0xe8]
  4c4768:      	add	x16, x16, #0xe8
  4c476c:      	br	x17

00000000004c4770 <Gif_AddCommentTake@plt>:
  4c4770:      	adrp	x16, 0x4e7000
  4c4774:      	ldr	x17, [x16, #0xf0]
  4c4778:      	add	x16, x16, #0xf0
  4c477c:      	br	x17

00000000004c4780 <Gif_AddComment@plt>:
  4c4780:      	adrp	x16, 0x4e7000
  4c4784:      	ldr	x17, [x16, #0xf8]
  4c4788:      	add	x16, x16, #0xf8
  4c478c:      	br	x17

00000000004c4790 <Gif_AddExtension@plt>:
  4c4790:      	adrp	x16, 0x4e7000
  4c4794:      	ldr	x17, [x16, #0x100]
  4c4798:      	add	x16, x16, #0x100
  4c479c:      	br	x17

00000000004c47a0 <Gif_ImageNumber@plt>:
  4c47a0:      	adrp	x16, 0x4e7000
  4c47a4:      	ldr	x17, [x16, #0x108]
  4c47a8:      	add	x16, x16, #0x108
  4c47ac:      	br	x17

00000000004c47b0 <Gif_CalculateScreenSize@plt>:
  4c47b0:      	adrp	x16, 0x4e7000
  4c47b4:      	ldr	x17, [x16, #0x110]
  4c47b8:      	add	x16, x16, #0x110
  4c47bc:      	br	x17

00000000004c47c0 <Gif_CopyColormap@plt>:
  4c47c0:      	adrp	x16, 0x4e7000
  4c47c4:      	ldr	x17, [x16, #0x118]
  4c47c8:      	add	x16, x16, #0x118
  4c47cc:      	br	x17

00000000004c47d0 <Gif_DeleteStream@plt>:
  4c47d0:      	adrp	x16, 0x4e7000
  4c47d4:      	ldr	x17, [x16, #0x120]
  4c47d8:      	add	x16, x16, #0x120
  4c47dc:      	br	x17

00000000004c47e0 <Gif_CopyImage@plt>:
  4c47e0:      	adrp	x16, 0x4e7000
  4c47e4:      	ldr	x17, [x16, #0x128]
  4c47e8:      	add	x16, x16, #0x128
  4c47ec:      	br	x17

00000000004c47f0 <Gif_MakeImageEmpty@plt>:
  4c47f0:      	adrp	x16, 0x4e7000
  4c47f4:      	ldr	x17, [x16, #0x130]
  4c47f8:      	add	x16, x16, #0x130
  4c47fc:      	br	x17

00000000004c4800 <Gif_ReleaseUncompressedImage@plt>:
  4c4800:      	adrp	x16, 0x4e7000
  4c4804:      	ldr	x17, [x16, #0x138]
  4c4808:      	add	x16, x16, #0x138
  4c480c:      	br	x17

00000000004c4810 <Gif_ReleaseCompressedImage@plt>:
  4c4810:      	adrp	x16, 0x4e7000
  4c4814:      	ldr	x17, [x16, #0x140]
  4c4818:      	add	x16, x16, #0x140
  4c481c:      	br	x17

00000000004c4820 <Gif_CreateUncompressedImage@plt>:
  4c4820:      	adrp	x16, 0x4e7000
  4c4824:      	ldr	x17, [x16, #0x148]
  4c4828:      	add	x16, x16, #0x148
  4c482c:      	br	x17

00000000004c4830 <Gif_DeleteColormap@plt>:
  4c4830:      	adrp	x16, 0x4e7000
  4c4834:      	ldr	x17, [x16, #0x150]
  4c4838:      	add	x16, x16, #0x150
  4c483c:      	br	x17

00000000004c4840 <Gif_DeleteComment@plt>:
  4c4840:      	adrp	x16, 0x4e7000
  4c4844:      	ldr	x17, [x16, #0x158]
  4c4848:      	add	x16, x16, #0x158
  4c484c:      	br	x17

00000000004c4850 <Gif_FindColor@plt>:
  4c4850:      	adrp	x16, 0x4e7000
  4c4854:      	ldr	x17, [x16, #0x160]
  4c4858:      	add	x16, x16, #0x160
  4c485c:      	br	x17

00000000004c4860 <Gif_GetImage@plt>:
  4c4860:      	adrp	x16, 0x4e7000
  4c4864:      	ldr	x17, [x16, #0x168]
  4c4868:      	add	x16, x16, #0x168
  4c486c:      	br	x17

00000000004c4870 <Gif_GetNamedImage@plt>:
  4c4870:      	adrp	x16, 0x4e7000
  4c4874:      	ldr	x17, [x16, #0x170]
  4c4878:      	add	x16, x16, #0x170
  4c487c:      	br	x17

00000000004c4880 <Gif_ClipImage@plt>:
  4c4880:      	adrp	x16, 0x4e7000
  4c4884:      	ldr	x17, [x16, #0x178]
  4c4888:      	add	x16, x16, #0x178
  4c488c:      	br	x17

00000000004c4890 <Gif_InterlaceLine@plt>:
  4c4890:      	adrp	x16, 0x4e7000
  4c4894:      	ldr	x17, [x16, #0x180]
  4c4898:      	add	x16, x16, #0x180
  4c489c:      	br	x17

00000000004c48a0 <Gif_InitCompressInfo@plt>:
  4c48a0:      	adrp	x16, 0x4e7000
  4c48a4:      	ldr	x17, [x16, #0x188]
  4c48a8:      	add	x16, x16, #0x188
  4c48ac:      	br	x17

00000000004c48b0 <vfprintf@plt>:
  4c48b0:      	adrp	x16, 0x4e7000
  4c48b4:      	ldr	x17, [x16, #0x190]
  4c48b8:      	add	x16, x16, #0x190
  4c48bc:      	br	x17

00000000004c48c0 <Gif_FullUncompressImage@plt>:
  4c48c0:      	adrp	x16, 0x4e7000
  4c48c4:      	ldr	x17, [x16, #0x198]
  4c48c8:      	add	x16, x16, #0x198
  4c48cc:      	br	x17

00000000004c48d0 <Gif_FullReadFile@plt>:
  4c48d0:      	adrp	x16, 0x4e7000
  4c48d4:      	ldr	x17, [x16, #0x1a0]
  4c48d8:      	add	x16, x16, #0x1a0
  4c48dc:      	br	x17

00000000004c48e0 <Gif_SetErrorHandler@plt>:
  4c48e0:      	adrp	x16, 0x4e7000
  4c48e4:      	ldr	x17, [x16, #0x1a8]
  4c48e8:      	add	x16, x16, #0x1a8
  4c48ec:      	br	x17

00000000004c48f0 <Gif_FullUnoptimize@plt>:
  4c48f0:      	adrp	x16, 0x4e7000
  4c48f4:      	ldr	x17, [x16, #0x1b0]
  4c48f8:      	add	x16, x16, #0x1b0
  4c48fc:      	br	x17

00000000004c4900 <unmark_colors@plt>:
  4c4900:      	adrp	x16, 0x4e7000
  4c4904:      	ldr	x17, [x16, #0x1b8]
  4c4908:      	add	x16, x16, #0x1b8
  4c490c:      	br	x17

00000000004c4910 <unmark_colors_2@plt>:
  4c4910:      	adrp	x16, 0x4e7000
  4c4914:      	ldr	x17, [x16, #0x1c0]
  4c4918:      	add	x16, x16, #0x1c0
  4c491c:      	br	x17

00000000004c4920 <mark_used_colors@plt>:
  4c4920:      	adrp	x16, 0x4e7000
  4c4924:      	ldr	x17, [x16, #0x1c8]
  4c4928:      	add	x16, x16, #0x1c8
  4c492c:      	br	x17

00000000004c4930 <merge_colormap_if_possible@plt>:
  4c4930:      	adrp	x16, 0x4e7000
  4c4934:      	ldr	x17, [x16, #0x1d0]
  4c4938:      	add	x16, x16, #0x1d0
  4c493c:      	br	x17

00000000004c4940 <merge_stream@plt>:
  4c4940:      	adrp	x16, 0x4e7000
  4c4944:      	ldr	x17, [x16, #0x1d8]
  4c4948:      	add	x16, x16, #0x1d8
  4c494c:      	br	x17

00000000004c4950 <merge_comments@plt>:
  4c4950:      	adrp	x16, 0x4e7000
  4c4954:      	ldr	x17, [x16, #0x1e0]
  4c4958:      	add	x16, x16, #0x1e0
  4c495c:      	br	x17

00000000004c4960 <merge_image@plt>:
  4c4960:      	adrp	x16, 0x4e7000
  4c4964:      	ldr	x17, [x16, #0x1e8]
  4c4968:      	add	x16, x16, #0x1e8
  4c496c:      	br	x17

00000000004c4970 <optimize_fragments@plt>:
  4c4970:      	adrp	x16, 0x4e7000
  4c4974:      	ldr	x17, [x16, #0x1f0]
  4c4978:      	add	x16, x16, #0x1f0
  4c497c:      	br	x17

00000000004c4980 <kc_revgamma_transform@plt>:
  4c4980:      	adrp	x16, 0x4e7000
  4c4984:      	ldr	x17, [x16, #0x1f8]
  4c4988:      	add	x16, x16, #0x1f8
  4c498c:      	br	x17

00000000004c4990 <kc_set_gamma@plt>:
  4c4990:      	adrp	x16, 0x4e7000
  4c4994:      	ldr	x17, [x16, #0x200]
  4c4998:      	add	x16, x16, #0x200
  4c499c:      	br	x17

00000000004c49a0 <kchist_init@plt>:
  4c49a0:      	adrp	x16, 0x4e7000
  4c49a4:      	ldr	x17, [x16, #0x208]
  4c49a8:      	add	x16, x16, #0x208
  4c49ac:      	br	x17

00000000004c49b0 <kchist_cleanup@plt>:
  4c49b0:      	adrp	x16, 0x4e7000
  4c49b4:      	ldr	x17, [x16, #0x210]
  4c49b8:      	add	x16, x16, #0x210
  4c49bc:      	br	x17

00000000004c49c0 <kchist_add@plt>:
  4c49c0:      	adrp	x16, 0x4e7000
  4c49c4:      	ldr	x17, [x16, #0x218]
  4c49c8:      	add	x16, x16, #0x218
  4c49cc:      	br	x17

00000000004c49d0 <kchist_compress@plt>:
  4c49d0:      	adrp	x16, 0x4e7000
  4c49d4:      	ldr	x17, [x16, #0x220]
  4c49d8:      	add	x16, x16, #0x220
  4c49dc:      	br	x17

00000000004c49e0 <kchist_make@plt>:
  4c49e0:      	adrp	x16, 0x4e7000
  4c49e4:      	ldr	x17, [x16, #0x228]
  4c49e8:      	add	x16, x16, #0x228
  4c49ec:      	br	x17

00000000004c49f0 <kcdiversity_init@plt>:
  4c49f0:      	adrp	x16, 0x4e7000
  4c49f4:      	ldr	x17, [x16, #0x230]
  4c49f8:      	add	x16, x16, #0x230
  4c49fc:      	br	x17

00000000004c4a00 <kcdiversity_cleanup@plt>:
  4c4a00:      	adrp	x16, 0x4e7000
  4c4a04:      	ldr	x17, [x16, #0x238]
  4c4a08:      	add	x16, x16, #0x238
  4c4a0c:      	br	x17

00000000004c4a10 <kcdiversity_find_diverse@plt>:
  4c4a10:      	adrp	x16, 0x4e7000
  4c4a14:      	ldr	x17, [x16, #0x240]
  4c4a18:      	add	x16, x16, #0x240
  4c4a1c:      	br	x17

00000000004c4a20 <kcdiversity_choose@plt>:
  4c4a20:      	adrp	x16, 0x4e7000
  4c4a24:      	ldr	x17, [x16, #0x248]
  4c4a28:      	add	x16, x16, #0x248
  4c4a2c:      	br	x17

00000000004c4a30 <kd3_init@plt>:
  4c4a30:      	adrp	x16, 0x4e7000
  4c4a34:      	ldr	x17, [x16, #0x250]
  4c4a38:      	add	x16, x16, #0x250
  4c4a3c:      	br	x17

00000000004c4a40 <kd3_cleanup@plt>:
  4c4a40:      	adrp	x16, 0x4e7000
  4c4a44:      	ldr	x17, [x16, #0x258]
  4c4a48:      	add	x16, x16, #0x258
  4c4a4c:      	br	x17

00000000004c4a50 <kd3_add8g@plt>:
  4c4a50:      	adrp	x16, 0x4e7000
  4c4a54:      	ldr	x17, [x16, #0x260]
  4c4a58:      	add	x16, x16, #0x260
  4c4a5c:      	br	x17

00000000004c4a60 <kd3_build_xradius@plt>:
  4c4a60:      	adrp	x16, 0x4e7000
  4c4a64:      	ldr	x17, [x16, #0x268]
  4c4a68:      	add	x16, x16, #0x268
  4c4a6c:      	br	x17

00000000004c4a70 <kd3_build@plt>:
  4c4a70:      	adrp	x16, 0x4e7000
  4c4a74:      	ldr	x17, [x16, #0x270]
  4c4a78:      	add	x16, x16, #0x270
  4c4a7c:      	br	x17

00000000004c4a80 <kd3_init_build@plt>:
  4c4a80:      	adrp	x16, 0x4e7000
  4c4a84:      	ldr	x17, [x16, #0x278]
  4c4a88:      	add	x16, x16, #0x278
  4c4a8c:      	br	x17

00000000004c4a90 <kd3_closest_transformed@plt>:
  4c4a90:      	adrp	x16, 0x4e7000
  4c4a94:      	ldr	x17, [x16, #0x280]
  4c4a98:      	add	x16, x16, #0x280
  4c4a9c:      	br	x17

00000000004c4aa0 <colormap_image_floyd_steinberg@plt>:
  4c4aa0:      	adrp	x16, 0x4e7000
  4c4aa4:      	ldr	x17, [x16, #0x288]
  4c4aa8:      	add	x16, x16, #0x288
  4c4aac:      	br	x17

00000000004c4ab0 <colormap_stream@plt>:
  4c4ab0:      	adrp	x16, 0x4e7000
  4c4ab4:      	ldr	x17, [x16, #0x290]
  4c4ab8:      	add	x16, x16, #0x290
  4c4abc:      	br	x17

00000000004c4ac0 <set_dither_type@plt>:
  4c4ac0:      	adrp	x16, 0x4e7000
  4c4ac4:      	ldr	x17, [x16, #0x298]
  4c4ac8:      	add	x16, x16, #0x298
  4c4acc:      	br	x17

00000000004c4ad0 <fatal_error@plt>:
  4c4ad0:      	adrp	x16, 0x4e7000
  4c4ad4:      	ldr	x17, [x16, #0x2a0]
  4c4ad8:      	add	x16, x16, #0x2a0
  4c4adc:      	br	x17

00000000004c4ae0 <snprintf@plt>:
  4c4ae0:      	adrp	x16, 0x4e7000
  4c4ae4:      	ldr	x17, [x16, #0x2a8]
  4c4ae8:      	add	x16, x16, #0x2a8
  4c4aec:      	br	x17

00000000004c4af0 <fputc@plt>:
  4c4af0:      	adrp	x16, 0x4e7000
  4c4af4:      	ldr	x17, [x16, #0x2b0]
  4c4af8:      	add	x16, x16, #0x2b0
  4c4afc:      	br	x17

00000000004c4b00 <lerror@plt>:
  4c4b00:      	adrp	x16, 0x4e7000
  4c4b04:      	ldr	x17, [x16, #0x2b8]
  4c4b08:      	add	x16, x16, #0x2b8
  4c4b0c:      	br	x17

00000000004c4b10 <error@plt>:
  4c4b10:      	adrp	x16, 0x4e7000
  4c4b14:      	ldr	x17, [x16, #0x2c0]
  4c4b18:      	add	x16, x16, #0x2c0
  4c4b1c:      	br	x17

00000000004c4b20 <lwarning@plt>:
  4c4b20:      	adrp	x16, 0x4e7000
  4c4b24:      	ldr	x17, [x16, #0x2c8]
  4c4b28:      	add	x16, x16, #0x2c8
  4c4b2c:      	br	x17

00000000004c4b30 <warning@plt>:
  4c4b30:      	adrp	x16, 0x4e7000
  4c4b34:      	ldr	x17, [x16, #0x2d0]
  4c4b38:      	add	x16, x16, #0x2d0
  4c4b3c:      	br	x17

00000000004c4b40 <fputs@plt>:
  4c4b40:      	adrp	x16, 0x4e7000
  4c4b44:      	ldr	x17, [x16, #0x2d8]
  4c4b48:      	add	x16, x16, #0x2d8
  4c4b4c:      	br	x17

00000000004c4b50 <verbose_endline@plt>:
  4c4b50:      	adrp	x16, 0x4e7000
  4c4b54:      	ldr	x17, [x16, #0x2e0]
  4c4b58:      	add	x16, x16, #0x2e0
  4c4b5c:      	br	x17

00000000004c4b60 <short_usage@plt>:
  4c4b60:      	adrp	x16, 0x4e7000
  4c4b64:      	ldr	x17, [x16, #0x2e8]
  4c4b68:      	add	x16, x16, #0x2e8
  4c4b6c:      	br	x17

00000000004c4b70 <usage@plt>:
  4c4b70:      	adrp	x16, 0x4e7000
  4c4b74:      	ldr	x17, [x16, #0x2f0]
  4c4b78:      	add	x16, x16, #0x2f0
  4c4b7c:      	br	x17

00000000004c4b80 <printf@plt>:
  4c4b80:      	adrp	x16, 0x4e7000
  4c4b84:      	ldr	x17, [x16, #0x2f8]
  4c4b88:      	add	x16, x16, #0x2f8
  4c4b8c:      	br	x17

00000000004c4b90 <puts@plt>:
  4c4b90:      	adrp	x16, 0x4e7000
  4c4b94:      	ldr	x17, [x16, #0x300]
  4c4b98:      	add	x16, x16, #0x300
  4c4b9c:      	br	x17

00000000004c4ba0 <verbose_open@plt>:
  4c4ba0:      	adrp	x16, 0x4e7000
  4c4ba4:      	ldr	x17, [x16, #0x308]
  4c4ba8:      	add	x16, x16, #0x308
  4c4bac:      	br	x17

00000000004c4bb0 <verbose_close@plt>:
  4c4bb0:      	adrp	x16, 0x4e7000
  4c4bb4:      	ldr	x17, [x16, #0x310]
  4c4bb8:      	add	x16, x16, #0x310
  4c4bbc:      	br	x17

00000000004c4bc0 <sprintf@plt>:
  4c4bc0:      	adrp	x16, 0x4e7000
  4c4bc4:      	ldr	x17, [x16, #0x318]
  4c4bc8:      	add	x16, x16, #0x318
  4c4bcc:      	br	x17

00000000004c4bd0 <stream_info@plt>:
  4c4bd0:      	adrp	x16, 0x4e7000
  4c4bd4:      	ldr	x17, [x16, #0x320]
  4c4bd8:      	add	x16, x16, #0x320
  4c4bdc:      	br	x17

00000000004c4be0 <putc@plt>:
  4c4be0:      	adrp	x16, 0x4e7000
  4c4be4:      	ldr	x17, [x16, #0x328]
  4c4be8:      	add	x16, x16, #0x328
  4c4bec:      	br	x17

00000000004c4bf0 <image_info@plt>:
  4c4bf0:      	adrp	x16, 0x4e7000
  4c4bf4:      	ldr	x17, [x16, #0x330]
  4c4bf8:      	add	x16, x16, #0x330
  4c4bfc:      	br	x17

00000000004c4c00 <explode_filename@plt>:
  4c4c00:      	adrp	x16, 0x4e7000
  4c4c04:      	ldr	x17, [x16, #0x338]
  4c4c08:      	add	x16, x16, #0x338
  4c4c0c:      	br	x17

00000000004c4c10 <parse_frame_spec@plt>:
  4c4c10:      	adrp	x16, 0x4e7000
  4c4c14:      	ldr	x17, [x16, #0x340]
  4c4c18:      	add	x16, x16, #0x340
  4c4c1c:      	br	x17

00000000004c4c20 <input_stream@plt>:
  4c4c20:      	adrp	x16, 0x4e7000
  4c4c24:      	ldr	x17, [x16, #0x348]
  4c4c28:      	add	x16, x16, #0x348
  4c4c2c:      	br	x17

00000000004c4c30 <strtod@plt>:
  4c4c30:      	adrp	x16, 0x4e7000
  4c4c34:      	ldr	x17, [x16, #0x350]
  4c4c38:      	add	x16, x16, #0x350
  4c4c3c:      	br	x17

00000000004c4c40 <parse_color@plt>:
  4c4c40:      	adrp	x16, 0x4e7000
  4c4c44:      	ldr	x17, [x16, #0x358]
  4c4c48:      	add	x16, x16, #0x358
  4c4c4c:      	br	x17

00000000004c4c50 <strspn@plt>:
  4c4c50:      	adrp	x16, 0x4e7000
  4c4c54:      	ldr	x17, [x16, #0x360]
  4c4c58:      	add	x16, x16, #0x360
  4c4c5c:      	br	x17

00000000004c4c60 <read_colormap_file@plt>:
  4c4c60:      	adrp	x16, 0x4e7000
  4c4c64:      	ldr	x17, [x16, #0x368]
  4c4c68:      	add	x16, x16, #0x368
  4c4c6c:      	br	x17

00000000004c4c70 <getc@plt>:
  4c4c70:      	adrp	x16, 0x4e7000
  4c4c74:      	ldr	x17, [x16, #0x370]
  4c4c78:      	add	x16, x16, #0x370
  4c4c7c:      	br	x17

00000000004c4c80 <ungetc@plt>:
  4c4c80:      	adrp	x16, 0x4e7000
  4c4c84:      	ldr	x17, [x16, #0x378]
  4c4c88:      	add	x16, x16, #0x378
  4c4c8c:      	br	x17

00000000004c4c90 <fgets@plt>:
  4c4c90:      	adrp	x16, 0x4e7000
  4c4c94:      	ldr	x17, [x16, #0x380]
  4c4c98:      	add	x16, x16, #0x380
  4c4c9c:      	br	x17

00000000004c4ca0 <strchr@plt>:
  4c4ca0:      	adrp	x16, 0x4e7000
  4c4ca4:      	ldr	x17, [x16, #0x388]
  4c4ca8:      	add	x16, x16, #0x388
  4c4cac:      	br	x17

00000000004c4cb0 <strerror@plt>:
  4c4cb0:      	adrp	x16, 0x4e7000
  4c4cb4:      	ldr	x17, [x16, #0x390]
  4c4cb8:      	add	x16, x16, #0x390
  4c4cbc:      	br	x17

00000000004c4cc0 <new_frameset@plt>:
  4c4cc0:      	adrp	x16, 0x4e7000
  4c4cc4:      	ldr	x17, [x16, #0x398]
  4c4cc8:      	add	x16, x16, #0x398
  4c4ccc:      	br	x17

00000000004c4cd0 <add_frame@plt>:
  4c4cd0:      	adrp	x16, 0x4e7000
  4c4cd4:      	ldr	x17, [x16, #0x3a0]
  4c4cd8:      	add	x16, x16, #0x3a0
  4c4cdc:      	br	x17

00000000004c4ce0 <merge_frame_interval@plt>:
  4c4ce0:      	adrp	x16, 0x4e7000
  4c4ce4:      	ldr	x17, [x16, #0x3a8]
  4c4ce8:      	add	x16, x16, #0x3a8
  4c4cec:      	br	x17

00000000004c4cf0 <crop_image@plt>:
  4c4cf0:      	adrp	x16, 0x4e7000
  4c4cf4:      	ldr	x17, [x16, #0x3b0]
  4c4cf8:      	add	x16, x16, #0x3b0
  4c4cfc:      	br	x17

00000000004c4d00 <flip_image@plt>:
  4c4d00:      	adrp	x16, 0x4e7000
  4c4d04:      	ldr	x17, [x16, #0x3b8]
  4c4d08:      	add	x16, x16, #0x3b8
  4c4d0c:      	br	x17

00000000004c4d10 <rotate_image@plt>:
  4c4d10:      	adrp	x16, 0x4e7000
  4c4d14:      	ldr	x17, [x16, #0x3c0]
  4c4d18:      	add	x16, x16, #0x3c0
  4c4d1c:      	br	x17

00000000004c4d20 <Gif_FullCompressImage@plt>:
  4c4d20:      	adrp	x16, 0x4e7000
  4c4d24:      	ldr	x17, [x16, #0x3c8]
  4c4d28:      	add	x16, x16, #0x3c8
  4c4d2c:      	br	x17

00000000004c4d30 <__assert2@plt>:
  4c4d30:      	adrp	x16, 0x4e7000
  4c4d34:      	ldr	x17, [x16, #0x3d0]
  4c4d38:      	add	x16, x16, #0x3d0
  4c4d3c:      	br	x17

00000000004c4d40 <blank_frameset@plt>:
  4c4d40:      	adrp	x16, 0x4e7000
  4c4d44:      	ldr	x17, [x16, #0x3d8]
  4c4d48:      	add	x16, x16, #0x3d8
  4c4d4c:      	br	x17

00000000004c4d50 <clear_frameset@plt>:
  4c4d50:      	adrp	x16, 0x4e7000
  4c4d54:      	ldr	x17, [x16, #0x3e0]
  4c4d58:      	add	x16, x16, #0x3e0
  4c4d5c:      	br	x17

00000000004c4d60 <strrchr@plt>:
  4c4d60:      	adrp	x16, 0x4e7000
  4c4d64:      	ldr	x17, [x16, #0x3e8]
  4c4d68:      	add	x16, x16, #0x3e8
  4c4d6c:      	br	x17

00000000004c4d70 <strstr@plt>:
  4c4d70:      	adrp	x16, 0x4e7000
  4c4d74:      	ldr	x17, [x16, #0x3f0]
  4c4d78:      	add	x16, x16, #0x3f0
  4c4d7c:      	br	x17

00000000004c4d80 <strtoul@plt>:
  4c4d80:      	adrp	x16, 0x4e7000
  4c4d84:      	ldr	x17, [x16, #0x3f8]
  4c4d88:      	add	x16, x16, #0x3f8
  4c4d8c:      	br	x17

00000000004c4d90 <combine_crop@plt>:
  4c4d90:      	adrp	x16, 0x4e7000
  4c4d94:      	ldr	x17, [x16, #0x400]
  4c4d98:      	add	x16, x16, #0x400
  4c4d9c:      	br	x17

00000000004c4da0 <append_color_transform@plt>:
  4c4da0:      	adrp	x16, 0x4e7000
  4c4da4:      	ldr	x17, [x16, #0x408]
  4c4da8:      	add	x16, x16, #0x408
  4c4dac:      	br	x17

00000000004c4db0 <delete_color_transforms@plt>:
  4c4db0:      	adrp	x16, 0x4e7000
  4c4db4:      	ldr	x17, [x16, #0x410]
  4c4db8:      	add	x16, x16, #0x410
  4c4dbc:      	br	x17

00000000004c4dc0 <apply_color_transforms@plt>:
  4c4dc0:      	adrp	x16, 0x4e7000
  4c4dc4:      	ldr	x17, [x16, #0x418]
  4c4dc8:      	add	x16, x16, #0x418
  4c4dcc:      	br	x17

00000000004c4dd0 <append_color_change@plt>:
  4c4dd0:      	adrp	x16, 0x4e7000
  4c4dd4:      	ldr	x17, [x16, #0x420]
  4c4dd8:      	add	x16, x16, #0x420
  4c4ddc:      	br	x17

00000000004c4de0 <abort@plt>:
  4c4de0:      	adrp	x16, 0x4e7000
  4c4de4:      	ldr	x17, [x16, #0x428]
  4c4de8:      	add	x16, x16, #0x428
  4c4dec:      	br	x17

00000000004c4df0 <resize_dimensions@plt>:
  4c4df0:      	adrp	x16, 0x4e7000
  4c4df4:      	ldr	x17, [x16, #0x430]
  4c4df8:      	add	x16, x16, #0x430
  4c4dfc:      	br	x17

00000000004c4e00 <resize_stream@plt>:
  4c4e00:      	adrp	x16, 0x4e7000
  4c4e04:      	ldr	x17, [x16, #0x438]
  4c4e08:      	add	x16, x16, #0x438
  4c4e0c:      	br	x17

00000000004c4e10 <sin@plt>:
  4c4e10:      	adrp	x16, 0x4e7000
  4c4e14:      	ldr	x17, [x16, #0x440]
  4c4e18:      	add	x16, x16, #0x440
  4c4e1c:      	br	x17

00000000004c4e20 <qsort@plt>:
  4c4e20:      	adrp	x16, 0x4e7000
  4c4e24:      	ldr	x17, [x16, #0x448]
  4c4e28:      	add	x16, x16, #0x448
  4c4e2c:      	br	x17

00000000004c4e30 <exp2@plt>:
  4c4e30:      	adrp	x16, 0x4e7000
  4c4e34:      	ldr	x17, [x16, #0x450]
  4c4e38:      	add	x16, x16, #0x450
  4c4e3c:      	br	x17

00000000004c4e40 <rand@plt>:
  4c4e40:      	adrp	x16, 0x4e7000
  4c4e44:      	ldr	x17, [x16, #0x458]
  4c4e48:      	add	x16, x16, #0x458
  4c4e4c:      	br	x17

00000000004c4e50 <atan2@plt>:
  4c4e50:      	adrp	x16, 0x4e7000
  4c4e54:      	ldr	x17, [x16, #0x460]
  4c4e58:      	add	x16, x16, #0x460
  4c4e5c:      	br	x17

00000000004c4e60 <set_frame_change@plt>:
  4c4e60:      	adrp	x16, 0x4e7000
  4c4e64:      	ldr	x17, [x16, #0x468]
  4c4e68:      	add	x16, x16, #0x468
  4c4e6c:      	br	x17

00000000004c4e70 <strcpy@plt>:
  4c4e70:      	adrp	x16, 0x4e7000
  4c4e74:      	ldr	x17, [x16, #0x470]
  4c4e78:      	add	x16, x16, #0x470
  4c4e7c:      	br	x17

00000000004c4e80 <output_frames@plt>:
  4c4e80:      	adrp	x16, 0x4e7000
  4c4e84:      	ldr	x17, [x16, #0x478]
  4c4e88:      	add	x16, x16, #0x478
  4c4e8c:      	br	x17

00000000004c4e90 <strncpy@plt>:
  4c4e90:      	adrp	x16, 0x4e7000
  4c4e94:      	ldr	x17, [x16, #0x480]
  4c4e98:      	add	x16, x16, #0x480
  4c4e9c:      	br	x17

00000000004c4ea0 <Gif_FullWriteFile@plt>:
  4c4ea0:      	adrp	x16, 0x4e7000
  4c4ea4:      	ldr	x17, [x16, #0x488]
  4c4ea8:      	add	x16, x16, #0x488
  4c4eac:      	br	x17

00000000004c4eb0 <frame_argument@plt>:
  4c4eb0:      	adrp	x16, 0x4e7000
  4c4eb4:      	ldr	x17, [x16, #0x490]
  4c4eb8:      	add	x16, x16, #0x490
  4c4ebc:      	br	x17

00000000004c4ec0 <Gif_IncrementalWriteImage@plt>:
  4c4ec0:      	adrp	x16, 0x4e7000
  4c4ec4:      	ldr	x17, [x16, #0x498]
  4c4ec8:      	add	x16, x16, #0x498
  4c4ecc:      	br	x17

00000000004c4ed0 <_ZN10imagequant6kmeans6Kmeans9iteration17h0e53a33a766390c7E@plt>:
  4c4ed0:      	adrp	x16, 0x4e7000
  4c4ed4:      	ldr	x17, [x16, #0x4a0]
  4c4ed8:      	add	x16, x16, #0x4a0
  4c4edc:      	br	x17

00000000004c4ee0 <_ZN10imagequant5image5Image12new_internal17h5b3be37badff2ee5E@plt>:
  4c4ee0:      	adrp	x16, 0x4e7000
  4c4ee4:      	ldr	x17, [x16, #0x4a8]
  4c4ee8:      	add	x16, x16, #0x4a8
  4c4eec:      	br	x17

00000000004c4ef0 <_ZN15crossbeam_epoch7default9collector17h029d8536dcc8a16cE@plt>:
  4c4ef0:      	adrp	x16, 0x4e7000
  4c4ef4:      	ldr	x17, [x16, #0x4b0]
  4c4ef8:      	add	x16, x16, #0x4b0
  4c4efc:      	br	x17

00000000004c4f00 <_ZN15crossbeam_epoch9collector9Collector8register17h2e762442c9fda30fE@plt>:
  4c4f00:      	adrp	x16, 0x4e7000
  4c4f04:      	ldr	x17, [x16, #0x4b8]
  4c4f08:      	add	x16, x16, #0x4b8
  4c4f0c:      	br	x17

00000000004c4f10 <_ZN15crossbeam_epoch8internal5Local8finalize17h12073ce96cb4acb7E@plt>:
  4c4f10:      	adrp	x16, 0x4e7000
  4c4f14:      	ldr	x17, [x16, #0x4c0]
  4c4f18:      	add	x16, x16, #0x4c0
  4c4f1c:      	br	x17

00000000004c4f20 <_ZN10rayon_core8registry15global_registry17hb8ccd6e04785f957E@plt>:
  4c4f20:      	adrp	x16, 0x4e7000
  4c4f24:      	ldr	x17, [x16, #0x4c8]
  4c4f28:      	add	x16, x16, #0x4c8
  4c4f2c:      	br	x17

00000000004c4f30 <_ZN10rayon_core8registry8Registry2id17h256b1bc765f7a7bbE@plt>:
  4c4f30:      	adrp	x16, 0x4e7000
  4c4f34:      	ldr	x17, [x16, #0x4d0]
  4c4f38:      	add	x16, x16, #0x4d0
  4c4f3c:      	br	x17

00000000004c4f40 <_ZN10rayon_core5sleep5Sleep16wake_any_threads17h7ed821ea459cb241E@plt>:
  4c4f40:      	adrp	x16, 0x4e7000
  4c4f44:      	ldr	x17, [x16, #0x4d8]
  4c4f48:      	add	x16, x16, #0x4d8
  4c4f4c:      	br	x17

00000000004c4f50 <_ZN10rayon_core8registry12WorkerThread15wait_until_cold17h8f731c77ba1a123bE@plt>:
  4c4f50:      	adrp	x16, 0x4e7000
  4c4f54:      	ldr	x17, [x16, #0x4e0]
  4c4f58:      	add	x16, x16, #0x4e0
  4c4f5c:      	br	x17

00000000004c4f60 <_ZN10rayon_core6unwind16resume_unwinding17h0fa3928a7abb9b36E@plt>:
  4c4f60:      	adrp	x16, 0x4e7000
  4c4f64:      	ldr	x17, [x16, #0x4e8]
  4c4f68:      	add	x16, x16, #0x4e8
  4c4f6c:      	br	x17

00000000004c4f70 <_ZN10rayon_core4join23join_recover_from_panic17h409715e6bae4d884E@plt>:
  4c4f70:      	adrp	x16, 0x4e7000
  4c4f74:      	ldr	x17, [x16, #0x4f0]
  4c4f78:      	add	x16, x16, #0x4f0
  4c4f7c:      	br	x17

00000000004c4f80 <_ZN10rayon_core5scope9ScopeBase9increment17h8bb488d13ed73415E@plt>:
  4c4f80:      	adrp	x16, 0x4e7000
  4c4f84:      	ldr	x17, [x16, #0x4f8]
  4c4f88:      	add	x16, x16, #0x4f8
  4c4f8c:      	br	x17

00000000004c4f90 <_ZN10rayon_core8registry8Registry14inject_or_push17ha7490a77b49b161dE@plt>:
  4c4f90:      	adrp	x16, 0x4e7000
  4c4f94:      	ldr	x17, [x16, #0x500]
  4c4f98:      	add	x16, x16, #0x500
  4c4f9c:      	br	x17

00000000004c4fa0 <_ZN10rayon_core5scope5Scope3new17hb81866d19389779eE@plt>:
  4c4fa0:      	adrp	x16, 0x4e7000
  4c4fa4:      	ldr	x17, [x16, #0x508]
  4c4fa8:      	add	x16, x16, #0x508
  4c4fac:      	br	x17

00000000004c4fb0 <_ZN74_$LT$rayon_core..scope..ScopeLatch$u20$as$u20$rayon_core..latch..Latch$GT$3set17he9728ff90090ef60E@plt>:
  4c4fb0:      	adrp	x16, 0x4e7000
  4c4fb4:      	ldr	x17, [x16, #0x510]
  4c4fb8:      	add	x16, x16, #0x510
  4c4fbc:      	br	x17

00000000004c4fc0 <_ZN10rayon_core5scope10ScopeLatch4wait17h7cb6b5e35a65ab65E@plt>:
  4c4fc0:      	adrp	x16, 0x4e7000
  4c4fc4:      	ldr	x17, [x16, #0x518]
  4c4fc8:      	add	x16, x16, #0x518
  4c4fcc:      	br	x17

00000000004c4fd0 <_ZN10rayon_core5scope9ScopeBase21maybe_propagate_panic17h1946b2811be0a07cE@plt>:
  4c4fd0:      	adrp	x16, 0x4e7000
  4c4fd4:      	ldr	x17, [x16, #0x520]
  4c4fd8:      	add	x16, x16, #0x520
  4c4fdc:      	br	x17

00000000004c4fe0 <_ZN10rayon_core5scope9ScopeBase12job_panicked17h98ddd5194460a12cE@plt>:
  4c4fe0:      	adrp	x16, 0x4e7000
  4c4fe4:      	ldr	x17, [x16, #0x528]
  4c4fe8:      	add	x16, x16, #0x528
  4c4fec:      	br	x17

00000000004c4ff0 <_ZN10rayon_core8registry8Registry6inject17h1dfc600f72c1fa54E@plt>:
  4c4ff0:      	adrp	x16, 0x4e7000
  4c4ff4:      	ldr	x17, [x16, #0x530]
  4c4ff8:      	add	x16, x16, #0x530
  4c4ffc:      	br	x17

00000000004c5000 <_ZN15crossbeam_epoch8internal5Local5defer17h5b749291ad7e1782E@plt>:
  4c5000:      	adrp	x16, 0x4e7000
  4c5004:      	ldr	x17, [x16, #0x538]
  4c5008:      	add	x16, x16, #0x538
  4c500c:      	br	x17

00000000004c5010 <_ZN10rayon_core19current_num_threads17h650aefbb84434260E@plt>:
  4c5010:      	adrp	x16, 0x4e7000
  4c5014:      	ldr	x17, [x16, #0x540]
  4c5018:      	add	x16, x16, #0x540
  4c501c:      	br	x17

00000000004c5020 <_ZN74_$LT$rayon_core..unwind..AbortIfPanic$u20$as$u20$core..ops..drop..Drop$GT$4drop17hefec52e72fc35e78E@plt>:
  4c5020:      	adrp	x16, 0x4e7000
  4c5024:      	ldr	x17, [x16, #0x548]
  4c5028:      	add	x16, x16, #0x548
  4c502c:      	br	x17

00000000004c5030 <_ZN3std4sync7condvar7Condvar10notify_all17h03fffde6c6d65f26E@plt>:
  4c5030:      	adrp	x16, 0x4e7000
  4c5034:      	ldr	x17, [x16, #0x550]
  4c5038:      	add	x16, x16, #0x550
  4c503c:      	br	x17

00000000004c5040 <_ZN10rayon_core8registry8Registry26notify_worker_latch_is_set17h1d40d5f9658ef587E@plt>:
  4c5040:      	adrp	x16, 0x4e7000
  4c5044:      	ldr	x17, [x16, #0x558]
  4c5048:      	add	x16, x16, #0x558
  4c504c:      	br	x17

00000000004c5050 <_ZN15crossbeam_epoch5guard5Guard5flush17h5aca22759ccc758aE@plt>:
  4c5050:      	adrp	x16, 0x4e7000
  4c5054:      	ldr	x17, [x16, #0x560]
  4c5058:      	add	x16, x16, #0x560
  4c505c:      	br	x17

00000000004c5060 <_ZN15crossbeam_epoch8internal6Global7collect17h82865d0f2d3b423eE@plt>:
  4c5060:      	adrp	x16, 0x4e7000
  4c5064:      	ldr	x17, [x16, #0x568]
  4c5068:      	add	x16, x16, #0x568
  4c506c:      	br	x17

00000000004c5070 <_ZN10imagequant4hist9Histogram9add_image17h5436f414270a60acE@plt>:
  4c5070:      	adrp	x16, 0x4e7000
  4c5074:      	ldr	x17, [x16, #0x570]
  4c5078:      	add	x16, x16, #0x570
  4c507c:      	br	x17

00000000004c5080 <_ZN10imagequant4hist9Histogram10add_colors17hbfbb6eb282d45a6cE@plt>:
  4c5080:      	adrp	x16, 0x4e7000
  4c5084:      	ldr	x17, [x16, #0x578]
  4c5088:      	add	x16, x16, #0x578
  4c508c:      	br	x17

00000000004c5090 <_ZN10imagequant4hist9Histogram17quantize_internal17h1d8e0e33550274dfE@plt>:
  4c5090:      	adrp	x16, 0x4e7000
  4c5094:      	ldr	x17, [x16, #0x580]
  4c5098:      	add	x16, x16, #0x580
  4c509c:      	br	x17

00000000004c50a0 <_ZN8arrayvec8arrayvec12extend_panic17ha5d9f5746571b7a4E@plt>:
  4c50a0:      	adrp	x16, 0x4e7000
  4c50a4:      	ldr	x17, [x16, #0x588]
  4c50a8:      	add	x16, x16, #0x588
  4c50ac:      	br	x17

00000000004c50b0 <_ZN10rayon_core5latch9LockLatch14wait_and_reset17h074e021dd8768677E@plt>:
  4c50b0:      	adrp	x16, 0x4e7000
  4c50b4:      	ldr	x17, [x16, #0x590]
  4c50b8:      	add	x16, x16, #0x590
  4c50bc:      	br	x17

00000000004c50c0 <_ZN12thread_local9thread_id8get_slow17ha4b95b2607df8ed0E@plt>:
  4c50c0:      	adrp	x16, 0x4e7000
  4c50c4:      	ldr	x17, [x16, #0x598]
  4c50c8:      	add	x16, x16, #0x598
  4c50cc:      	br	x17

00000000004c50d0 <_ZN8num_cpus12get_num_cpus17h81200b0a8d2b1563E@plt>:
  4c50d0:      	adrp	x16, 0x4e7000
  4c50d4:      	ldr	x17, [x16, #0x5a0]
  4c50d8:      	add	x16, x16, #0x5a0
  4c50dc:      	br	x17

00000000004c50e0 <_ZN5alloc3vec16Vec$LT$T$C$A$GT$11swap_remove13assert_failed17hd6b315a7bd0b4492E@plt>:
  4c50e0:      	adrp	x16, 0x4e7000
  4c50e4:      	ldr	x17, [x16, #0x5a8]
  4c50e8:      	add	x16, x16, #0x5a8
  4c50ec:      	br	x17

00000000004c50f0 <_ZN97_$LT$rayon..iter..noop..NoopReducer$u20$as$u20$rayon..iter..plumbing..Reducer$LT$$LP$$RP$$GT$$GT$6reduce17he453bf45cc105debE@plt>:
  4c50f0:      	adrp	x16, 0x4e7000
  4c50f4:      	ldr	x17, [x16, #0x5b0]
  4c50f8:      	add	x16, x16, #0x5b0
  4c50fc:      	br	x17

00000000004c5100 <_ZN78_$LT$thread_local..thread_id..ThreadGuard$u20$as$u20$core..ops..drop..Drop$GT$4drop17hfdd49dc6c36d856fE@plt>:
  4c5100:      	adrp	x16, 0x4e7000
  4c5104:      	ldr	x17, [x16, #0x5b8]
  4c5108:      	add	x16, x16, #0x5b8
  4c510c:      	br	x17

00000000004c5110 <_ZN9once_cell3imp18initialize_or_wait17hf007b5045eb9c55aE@plt>:
  4c5110:      	adrp	x16, 0x4e7000
  4c5114:      	ldr	x17, [x16, #0x5c0]
  4c5118:      	add	x16, x16, #0x5c0
  4c511c:      	br	x17

00000000004c5120 <_ZN63_$LT$once_cell..imp..Guard$u20$as$u20$core..ops..drop..Drop$GT$4drop17hdd3ef9bbd1421869E@plt>:
  4c5120:      	adrp	x16, 0x4e7000
  4c5124:      	ldr	x17, [x16, #0x5c8]
  4c5128:      	add	x16, x16, #0x5c8
  4c512c:      	br	x17

00000000004c5130 <_ZN4core3fmt9Formatter11debug_tuple17h49b8194b28ae429cE@plt>:
  4c5130:      	adrp	x16, 0x4e7000
  4c5134:      	ldr	x17, [x16, #0x5d0]
  4c5138:      	add	x16, x16, #0x5d0
  4c513c:      	br	x17

00000000004c5140 <_ZN4core3fmt8builders10DebugTuple5field17hb1b44b47290b7667E@plt>:
  4c5140:      	adrp	x16, 0x4e7000
  4c5144:      	ldr	x17, [x16, #0x5d8]
  4c5148:      	add	x16, x16, #0x5d8
  4c514c:      	br	x17

00000000004c5150 <_ZN4core3fmt8builders10DebugTuple6finish17hd6b1b5314a0c9badE@plt>:
  4c5150:      	adrp	x16, 0x4e7000
  4c5154:      	ldr	x17, [x16, #0x5e0]
  4c5158:      	add	x16, x16, #0x5e0
  4c515c:      	br	x17

00000000004c5160 <_ZN10rayon_core8registry13ThreadBuilder3run17h897d95c58bd70c91E@plt>:
  4c5160:      	adrp	x16, 0x4e7000
  4c5164:      	ldr	x17, [x16, #0x5e8]
  4c5168:      	add	x16, x16, #0x5e8
  4c516c:      	br	x17

00000000004c5170 <_ZN117_$LT$rayon_core..registry..WorkerThread$u20$as$u20$core..convert..From$LT$rayon_core..registry..ThreadBuilder$GT$$GT$4from17h8d1b6db4aac2cccdE@plt>:
  4c5170:      	adrp	x16, 0x4e7000
  4c5174:      	ldr	x17, [x16, #0x5f0]
  4c5178:      	add	x16, x16, #0x5f0
  4c517c:      	br	x17

00000000004c5180 <_ZN88_$LT$rayon_core..registry..DefaultSpawn$u20$as$u20$rayon_core..registry..ThreadSpawn$GT$5spawn17h896b68d4fb80b767E@plt>:
  4c5180:      	adrp	x16, 0x4e7000
  4c5184:      	ldr	x17, [x16, #0x5f8]
  4c5188:      	add	x16, x16, #0x5f8
  4c518c:      	br	x17

00000000004c5190 <_ZN3std6thread7Builder10stack_size17h15efaa87ad22afc9E@plt>:
  4c5190:      	adrp	x16, 0x4e7000
  4c5194:      	ldr	x17, [x16, #0x600]
  4c5198:      	add	x16, x16, #0x600
  4c519c:      	br	x17

00000000004c51a0 <_ZN70_$LT$std..sync..condvar..Condvar$u20$as$u20$core..default..Default$GT$7default17hd768bd6d5694d96aE@plt>:
  4c51a0:      	adrp	x16, 0x4e7000
  4c51a4:      	ldr	x17, [x16, #0x608]
  4c51a8:      	add	x16, x16, #0x608
  4c51ac:      	br	x17

00000000004c51b0 <_ZN3std3env4_var17h065765ee9f27e36dE@plt>:
  4c51b0:      	adrp	x16, 0x4e7000
  4c51b4:      	ldr	x17, [x16, #0x610]
  4c51b8:      	add	x16, x16, #0x610
  4c51bc:      	br	x17

00000000004c51c0 <_ZN3std3sys4unix5locks13futex_condvar7Condvar4wait17hab5d0709d8fbadf8E@plt>:
  4c51c0:      	adrp	x16, 0x4e7000
  4c51c4:      	ldr	x17, [x16, #0x618]
  4c51c8:      	add	x16, x16, #0x618
  4c51cc:      	br	x17

00000000004c51d0 <_ZN64_$LT$std..sync..condvar..Condvar$u20$as$u20$core..fmt..Debug$GT$3fmt17hc387ae8fa083c0c0E@plt>:
  4c51d0:      	adrp	x16, 0x4e7000
  4c51d4:      	ldr	x17, [x16, #0x620]
  4c51d8:      	add	x16, x16, #0x620
  4c51dc:      	br	x17

00000000004c51e0 <_ZN68_$LT$core..sync..atomic..AtomicUsize$u20$as$u20$core..fmt..Debug$GT$3fmt17h4adb3ef05d9068c5E@plt>:
  4c51e0:      	adrp	x16, 0x4e7000
  4c51e4:      	ldr	x17, [x16, #0x628]
  4c51e8:      	add	x16, x16, #0x628
  4c51ec:      	br	x17

00000000004c51f0 <_ZN3std4sync7condvar7Condvar10notify_one17h635c62bb2822fff5E@plt>:
  4c51f0:      	adrp	x16, 0x4e7000
  4c51f4:      	ldr	x17, [x16, #0x630]
  4c51f8:      	add	x16, x16, #0x630
  4c51fc:      	br	x17

00000000004c5200 <_ZN3std3sys4unix5futex10futex_wait17h71ecf667fb9977b5E@plt>:
  4c5200:      	adrp	x16, 0x4e7000
  4c5204:      	ldr	x17, [x16, #0x638]
  4c5208:      	add	x16, x16, #0x638
  4c520c:      	br	x17

00000000004c5210 <_ZN87_$LT$std..sys_common..once..futex..CompletionGuard$u20$as$u20$core..ops..drop..Drop$GT$4drop17ha57635bb60e23c1eE@plt>:
  4c5210:      	adrp	x16, 0x4e7000
  4c5214:      	ldr	x17, [x16, #0x640]
  4c5218:      	add	x16, x16, #0x640
  4c521c:      	br	x17

00000000004c5220 <_ZN4core3num62_$LT$impl$u20$core..str..traits..FromStr$u20$for$u20$usize$GT$8from_str17hb4b7e1f9e0c93729E@plt>:
  4c5220:      	adrp	x16, 0x4e7000
  4c5224:      	ldr	x17, [x16, #0x648]
  4c5228:      	add	x16, x16, #0x648
  4c522c:      	br	x17

00000000004c5230 <_ZN60_$LT$std..io..error..Error$u20$as$u20$core..error..Error$GT$11description17hc503cfcaf2f67d99E@plt>:
  4c5230:      	adrp	x16, 0x4e7000
  4c5234:      	ldr	x17, [x16, #0x650]
  4c5238:      	add	x16, x16, #0x650
  4c523c:      	br	x17

00000000004c5240 <_ZN80_$LT$crossbeam_epoch..collector..Collector$u20$as$u20$core..default..Default$GT$7default17h7c48851458a8036aE@plt>:
  4c5240:      	adrp	x16, 0x4e7000
  4c5244:      	ldr	x17, [x16, #0x658]
  4c5248:      	add	x16, x16, #0x658
  4c524c:      	br	x17

00000000004c5250 <_ZN4core3fmt9Formatter3pad17h5ceb99f646c48047E@plt>:
  4c5250:      	adrp	x16, 0x4e7000
  4c5254:      	ldr	x17, [x16, #0x660]
  4c5258:      	add	x16, x16, #0x660
  4c525c:      	br	x17

00000000004c5260 <_ZN58_$LT$std..thread..ThreadId$u20$as$u20$core..fmt..Debug$GT$3fmt17h329f508660d789ccE@plt>:
  4c5260:      	adrp	x16, 0x4e7000
  4c5264:      	ldr	x17, [x16, #0x668]
  4c5268:      	add	x16, x16, #0x668
  4c526c:      	br	x17

00000000004c5270 <_ZN56_$LT$std..thread..Thread$u20$as$u20$core..fmt..Debug$GT$3fmt17h175e447a4308374fE@plt>:
  4c5270:      	adrp	x16, 0x4e7000
  4c5274:      	ldr	x17, [x16, #0x670]
  4c5278:      	add	x16, x16, #0x670
  4c527c:      	br	x17

00000000004c5280 <_ZN57_$LT$std..thread..Builder$u20$as$u20$core..fmt..Debug$GT$3fmt17h023b2e0289e4dc87E@plt>:
  4c5280:      	adrp	x16, 0x4e7000
  4c5284:      	ldr	x17, [x16, #0x678]
  4c5288:      	add	x16, x16, #0x678
  4c528c:      	br	x17

00000000004c5290 <_ZN91_$LT$crossbeam_utils..sync..sharded_lock..Registration$u20$as$u20$core..ops..drop..Drop$GT$4drop17h63ef4a3ca478478bE@plt>:
  4c5290:      	adrp	x16, 0x4e7000
  4c5294:      	ldr	x17, [x16, #0x680]
  4c5298:      	add	x16, x16, #0x680
  4c529c:      	br	x17

00000000004c52a0 <sysconf@plt>:
  4c52a0:      	adrp	x16, 0x4e7000
  4c52a4:      	ldr	x17, [x16, #0x688]
  4c52a8:      	add	x16, x16, #0x688
  4c52ac:      	br	x17

00000000004c52b0 <_ZN3gif6common5Frame15from_rgba_speed17h547b7a4ecfd09bfcE@plt>:
  4c52b0:      	adrp	x16, 0x4e7000
  4c52b4:      	ldr	x17, [x16, #0x690]
  4c52b8:      	add	x16, x16, #0x690
  4c52bc:      	br	x17

00000000004c52c0 <_ZN11color_quant8NeuQuant3new17h31197c503d0e5770E@plt>:
  4c52c0:      	adrp	x16, 0x4e7000
  4c52c4:      	ldr	x17, [x16, #0x698]
  4c52c8:      	add	x16, x16, #0x698
  4c52cc:      	br	x17

00000000004c52d0 <_ZN11color_quant8NeuQuant13color_map_rgb17h639fef04e474465bE@plt>:
  4c52d0:      	adrp	x16, 0x4e7000
  4c52d4:      	ldr	x17, [x16, #0x6a0]
  4c52d8:      	add	x16, x16, #0x6a0
  4c52dc:      	br	x17

00000000004c52e0 <_ZN11color_quant8NeuQuant15search_netindex17h43124c4a82ce4e2cE@plt>:
  4c52e0:      	adrp	x16, 0x4e7000
  4c52e4:      	ldr	x17, [x16, #0x6a8]
  4c52e8:      	add	x16, x16, #0x6a8
  4c52ec:      	br	x17

00000000004c52f0 <_ZN3gif6common5Frame14from_rgb_speed17hcc8a502a97dfb4e6E@plt>:
  4c52f0:      	adrp	x16, 0x4e7000
  4c52f4:      	ldr	x17, [x16, #0x6b0]
  4c52f8:      	add	x16, x16, #0x6b0
  4c52fc:      	br	x17

00000000004c5300 <_ZN3gif7encoder10lzw_encode17h923ffd745be987c3E@plt>:
  4c5300:      	adrp	x16, 0x4e7000
  4c5304:      	ldr	x17, [x16, #0x6b8]
  4c5308:      	add	x16, x16, #0x6b8
  4c530c:      	br	x17

00000000004c5310 <_ZN5weezl6encode7Encoder3new17h8b7bf550aaefb327E@plt>:
  4c5310:      	adrp	x16, 0x4e7000
  4c5314:      	ldr	x17, [x16, #0x6c0]
  4c5318:      	add	x16, x16, #0x6c0
  4c531c:      	br	x17

00000000004c5320 <_ZN5weezl6encode7Encoder8into_vec17h3f81fd6e47376613E@plt>:
  4c5320:      	adrp	x16, 0x4e7000
  4c5324:      	ldr	x17, [x16, #0x6c8]
  4c5328:      	add	x16, x16, #0x6c8
  4c532c:      	br	x17

00000000004c5330 <_ZN5weezl6encode7IntoVec10encode_all17hc3574334ab71b34aE@plt>:
  4c5330:      	adrp	x16, 0x4e7000
  4c5334:      	ldr	x17, [x16, #0x6d0]
  4c5338:      	add	x16, x16, #0x6d0
  4c533c:      	br	x17

00000000004c5340 <_ZN11color_quant8NeuQuant4init17h077150514dcf4206E@plt>:
  4c5340:      	adrp	x16, 0x4e7000
  4c5344:      	ldr	x17, [x16, #0x6d8]
  4c5348:      	add	x16, x16, #0x6d8
  4c534c:      	br	x17

00000000004c5350 <_ZN5weezl6decode5Table4init17h976ce44a9b8ff90eE@plt>:
  4c5350:      	adrp	x16, 0x4e7000
  4c5354:      	ldr	x17, [x16, #0x6e0]
  4c5358:      	add	x16, x16, #0x6e0
  4c535c:      	br	x17

00000000004c5360 <_ZN5weezl6decode6Buffer16fill_reconstruct17h275dfbbb5712fa19E@plt>:
  4c5360:      	adrp	x16, 0x4e7000
  4c5364:      	ldr	x17, [x16, #0x6e8]
  4c5368:      	add	x16, x16, #0x6e8
  4c536c:      	br	x17

00000000004c5370 <_ZN5weezl6encode4Tree7iterate17h43ec07f3ed006127E@plt>:
  4c5370:      	adrp	x16, 0x4e7000
  4c5374:      	ldr	x17, [x16, #0x6f0]
  4c5378:      	add	x16, x16, #0x6f0
  4c537c:      	br	x17

00000000004c5380 <_ZN54_$LT$std..path..Prefix$u20$as$u20$core..fmt..Debug$GT$3fmt17hafad9a4d80a92176E@plt>:
  4c5380:      	adrp	x16, 0x4e7000
  4c5384:      	ldr	x17, [x16, #0x6f8]
  4c5388:      	add	x16, x16, #0x6f8
  4c538c:      	br	x17

00000000004c5390 <_ZN3std3env11current_dir17hc5692c932385e577E@plt>:
  4c5390:      	adrp	x16, 0x4e7000
  4c5394:      	ldr	x17, [x16, #0x700]
  4c5398:      	add	x16, x16, #0x700
  4c539c:      	br	x17

00000000004c53a0 <_ZN70_$LT$std..sys_common..net..TcpListener$u20$as$u20$core..fmt..Debug$GT$3fmt17h78a1eeba411afd93E@plt>:
  4c53a0:      	adrp	x16, 0x4e7000
  4c53a4:      	ldr	x17, [x16, #0x708]
  4c53a8:      	add	x16, x16, #0x708
  4c53ac:      	br	x17

00000000004c53b0 <_ZN72_$LT$std..backtrace_rs..backtrace..Frame$u20$as$u20$core..fmt..Debug$GT$3fmt17h56dd41542f4bd2d1E@plt>:
  4c53b0:      	adrp	x16, 0x4e7000
  4c53b4:      	ldr	x17, [x16, #0x710]
  4c53b8:      	add	x16, x16, #0x710
  4c53bc:      	br	x17

00000000004c53c0 <_ZN64_$LT$std..sys_common..wtf8..Wtf8$u20$as$u20$core..fmt..Debug$GT$3fmt17hfc0b000d5a2f12aeE@plt>:
  4c53c0:      	adrp	x16, 0x4e7000
  4c53c4:      	ldr	x17, [x16, #0x718]
  4c53c8:      	add	x16, x16, #0x718
  4c53cc:      	br	x17

00000000004c53d0 <_ZN68_$LT$std..backtrace..BacktraceSymbol$u20$as$u20$core..fmt..Debug$GT$3fmt17h9b9e45d218a05027E@plt>:
  4c53d0:      	adrp	x16, 0x4e7000
  4c53d4:      	ldr	x17, [x16, #0x720]
  4c53d8:      	add	x16, x16, #0x720
  4c53dc:      	br	x17

00000000004c53e0 <_ZN3std2io5error83_$LT$impl$u20$core..fmt..Debug$u20$for$u20$std..io..error..repr_bitpacked..Repr$GT$3fmt17h2023fe3650e946ecE@plt>:
  4c53e0:      	adrp	x16, 0x4e7000
  4c53e4:      	ldr	x17, [x16, #0x728]
  4c53e8:      	add	x16, x16, #0x728
  4c53ec:      	br	x17

00000000004c53f0 <_ZN62_$LT$std..io..error..ErrorKind$u20$as$u20$core..fmt..Debug$GT$3fmt17he44e6efbeb239213E@plt>:
  4c53f0:      	adrp	x16, 0x4e7000
  4c53f4:      	ldr	x17, [x16, #0x730]
  4c53f8:      	add	x16, x16, #0x730
  4c53fc:      	br	x17

00000000004c5400 <_ZN79_$LT$std..os..unix..net..listener..UnixListener$u20$as$u20$core..fmt..Debug$GT$3fmt17h78c0aa76aaf0c0d5E@plt>:
  4c5400:      	adrp	x16, 0x4e7000
  4c5404:      	ldr	x17, [x16, #0x738]
  4c5408:      	add	x16, x16, #0x738
  4c540c:      	br	x17

00000000004c5410 <_ZN63_$LT$std..net..parser..AddrKind$u20$as$u20$core..fmt..Debug$GT$3fmt17h1bde11c61742430cE@plt>:
  4c5410:      	adrp	x16, 0x4e7000
  4c5414:      	ldr	x17, [x16, #0x740]
  4c5418:      	add	x16, x16, #0x740
  4c541c:      	br	x17

00000000004c5420 <_ZN66_$LT$std..net..ip_addr..Ipv4Addr$u20$as$u20$core..fmt..Display$GT$3fmt17h5026e6c6aebc9428E@plt>:
  4c5420:      	adrp	x16, 0x4e7000
  4c5424:      	ldr	x17, [x16, #0x748]
  4c5428:      	add	x16, x16, #0x748
  4c542c:      	br	x17

00000000004c5430 <_ZN66_$LT$std..net..ip_addr..Ipv6Addr$u20$as$u20$core..fmt..Display$GT$3fmt17h536a24f7528ec626E@plt>:
  4c5430:      	adrp	x16, 0x4e7000
  4c5434:      	ldr	x17, [x16, #0x750]
  4c5438:      	add	x16, x16, #0x750
  4c543c:      	br	x17

00000000004c5440 <_ZN3std9panicking12default_hook17h9cc1581920ab50d3E@plt>:
  4c5440:      	adrp	x16, 0x4e7000
  4c5444:      	ldr	x17, [x16, #0x758]
  4c5448:      	add	x16, x16, #0x758
  4c544c:      	br	x17

00000000004c5450 <_ZN4core3str5lossy10Utf8Chunks3new17h8e952432297149d1E@plt>:
  4c5450:      	adrp	x16, 0x4e7000
  4c5454:      	ldr	x17, [x16, #0x760]
  4c5458:      	add	x16, x16, #0x760
  4c545c:      	br	x17

00000000004c5460 <_ZN4core3str5lossy10Utf8Chunks5debug17h9e9c8aeb5acf3c7cE@plt>:
  4c5460:      	adrp	x16, 0x4e7000
  4c5464:      	ldr	x17, [x16, #0x768]
  4c5468:      	add	x16, x16, #0x768
  4c546c:      	br	x17

00000000004c5470 <_ZN60_$LT$core..str..lossy..Debug$u20$as$u20$core..fmt..Debug$GT$3fmt17he24e7b46f5268b82E@plt>:
  4c5470:      	adrp	x16, 0x4e7000
  4c5474:      	ldr	x17, [x16, #0x770]
  4c5478:      	add	x16, x16, #0x770
  4c547c:      	br	x17

00000000004c5480 <_ZN65_$LT$core..hash..sip..SipHasher13$u20$as$u20$core..fmt..Debug$GT$3fmt17ha01f78adc503f82dE@plt>:
  4c5480:      	adrp	x16, 0x4e7000
  4c5484:      	ldr	x17, [x16, #0x778]
  4c5488:      	add	x16, x16, #0x778
  4c548c:      	br	x17

00000000004c5490 <_ZN4core3fmt9Formatter9debug_map17had1f953f3ac7b9a5E@plt>:
  4c5490:      	adrp	x16, 0x4e7000
  4c5494:      	ldr	x17, [x16, #0x780]
  4c5498:      	add	x16, x16, #0x780
  4c549c:      	br	x17

00000000004c54a0 <_ZN4core3fmt8builders8DebugMap5entry17h4e98a4957a66a30dE@plt>:
  4c54a0:      	adrp	x16, 0x4e7000
  4c54a4:      	ldr	x17, [x16, #0x788]
  4c54a8:      	add	x16, x16, #0x788
  4c54ac:      	br	x17

00000000004c54b0 <_ZN4core3fmt8builders8DebugMap6finish17h2b934229a3610ba9E@plt>:
  4c54b0:      	adrp	x16, 0x4e7000
  4c54b4:      	ldr	x17, [x16, #0x790]
  4c54b8:      	add	x16, x16, #0x790
  4c54bc:      	br	x17

00000000004c54c0 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$u64$GT$3fmt17h37799cfe7221c374E@plt>:
  4c54c0:      	adrp	x16, 0x4e7000
  4c54c4:      	ldr	x17, [x16, #0x798]
  4c54c8:      	add	x16, x16, #0x798
  4c54cc:      	br	x17

00000000004c54d0 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$u64$GT$3fmt17h94d2c01a5019afcdE@plt>:
  4c54d0:      	adrp	x16, 0x4e7000
  4c54d4:      	ldr	x17, [x16, #0x7a0]
  4c54d8:      	add	x16, x16, #0x7a0
  4c54dc:      	br	x17

00000000004c54e0 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$i32$GT$3fmt17h15195fba127aee9bE@plt>:
  4c54e0:      	adrp	x16, 0x4e7000
  4c54e4:      	ldr	x17, [x16, #0x7a8]
  4c54e8:      	add	x16, x16, #0x7a8
  4c54ec:      	br	x17

00000000004c54f0 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$i32$GT$3fmt17hbedfd0f94f564859E@plt>:
  4c54f0:      	adrp	x16, 0x4e7000
  4c54f4:      	ldr	x17, [x16, #0x7b0]
  4c54f8:      	add	x16, x16, #0x7b0
  4c54fc:      	br	x17

00000000004c5500 <_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$i32$GT$3fmt17h385ede902fba092bE@plt>:
  4c5500:      	adrp	x16, 0x4e7000
  4c5504:      	ldr	x17, [x16, #0x7b8]
  4c5508:      	add	x16, x16, #0x7b8
  4c550c:      	br	x17

00000000004c5510 <_ZN57_$LT$core..time..Duration$u20$as$u20$core..fmt..Debug$GT$3fmt17h7195ff02b361072eE@plt>:
  4c5510:      	adrp	x16, 0x4e7000
  4c5514:      	ldr	x17, [x16, #0x7c0]
  4c5518:      	add	x16, x16, #0x7c0
  4c551c:      	br	x17

00000000004c5520 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$i64$GT$3fmt17h0408e03c16c6945fE@plt>:
  4c5520:      	adrp	x16, 0x4e7000
  4c5524:      	ldr	x17, [x16, #0x7c8]
  4c5528:      	add	x16, x16, #0x7c8
  4c552c:      	br	x17

00000000004c5530 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$i64$GT$3fmt17h7277af80e58af239E@plt>:
  4c5530:      	adrp	x16, 0x4e7000
  4c5534:      	ldr	x17, [x16, #0x7d0]
  4c5538:      	add	x16, x16, #0x7d0
  4c553c:      	br	x17

00000000004c5540 <_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$i64$GT$3fmt17h453f700809bcf3bfE@plt>:
  4c5540:      	adrp	x16, 0x4e7000
  4c5544:      	ldr	x17, [x16, #0x7d8]
  4c5548:      	add	x16, x16, #0x7d8
  4c554c:      	br	x17

00000000004c5550 <_ZN70_$LT$core..panic..location..Location$u20$as$u20$core..fmt..Display$GT$3fmt17hcc247f67885c4b3dE@plt>:
  4c5550:      	adrp	x16, 0x4e7000
  4c5554:      	ldr	x17, [x16, #0x7e0]
  4c5558:      	add	x16, x16, #0x7e0
  4c555c:      	br	x17

00000000004c5560 <syscall@plt>:
  4c5560:      	adrp	x16, 0x4e7000
  4c5564:      	ldr	x17, [x16, #0x7e8]
  4c5568:      	add	x16, x16, #0x7e8
  4c556c:      	br	x17

00000000004c5570 <freeaddrinfo@plt>:
  4c5570:      	adrp	x16, 0x4e7000
  4c5574:      	ldr	x17, [x16, #0x7f0]
  4c5578:      	add	x16, x16, #0x7f0
  4c557c:      	br	x17

00000000004c5580 <munmap@plt>:
  4c5580:      	adrp	x16, 0x4e7000
  4c5584:      	ldr	x17, [x16, #0x7f8]
  4c5588:      	add	x16, x16, #0x7f8
  4c558c:      	br	x17

00000000004c5590 <_ZN3std3sys4unix5locks12futex_rwlock6RwLock22wake_writer_or_readers17hddf8791ad0e6056bE@plt>:
  4c5590:      	adrp	x16, 0x4e7000
  4c5594:      	ldr	x17, [x16, #0x800]
  4c5598:      	add	x16, x16, #0x800
  4c559c:      	br	x17

00000000004c55a0 <_ZN93_$LT$alloc..collections..btree..mem..replace..PanicGuard$u20$as$u20$core..ops..drop..Drop$GT$4drop17hfed218f26669ae72E@plt>:
  4c55a0:      	adrp	x16, 0x4e7000
  4c55a4:      	ldr	x17, [x16, #0x808]
  4c55a8:      	add	x16, x16, #0x808
  4c55ac:      	br	x17

00000000004c55b0 <_ZN65_$LT$std..sys..unix..fs..Dir$u20$as$u20$core..ops..drop..Drop$GT$4drop17h7981615b659d0cbcE@plt>:
  4c55b0:      	adrp	x16, 0x4e7000
  4c55b4:      	ldr	x17, [x16, #0x810]
  4c55b8:      	add	x16, x16, #0x810
  4c55bc:      	br	x17

00000000004c55c0 <_ZN4core3str7pattern11StrSearcher3new17h8a7b66bf1fe47a0bE@plt>:
  4c55c0:      	adrp	x16, 0x4e7000
  4c55c4:      	ldr	x17, [x16, #0x818]
  4c55c8:      	add	x16, x16, #0x818
  4c55cc:      	br	x17

00000000004c55d0 <_ZN4core3str16slice_error_fail17h535eec674fef65a4E@plt>:
  4c55d0:      	adrp	x16, 0x4e7000
  4c55d4:      	ldr	x17, [x16, #0x820]
  4c55d8:      	add	x16, x16, #0x820
  4c55dc:      	br	x17

00000000004c55e0 <_ZN5alloc11collections5btree4node10splitpoint17hfc51b3c526fea6baE@plt>:
  4c55e0:      	adrp	x16, 0x4e7000
  4c55e4:      	ldr	x17, [x16, #0x828]
  4c55e8:      	add	x16, x16, #0x828
  4c55ec:      	br	x17

00000000004c55f0 <_ZN5gimli4read4unit20allow_section_offset17hbf65e30aa002940eE@plt>:
  4c55f0:      	adrp	x16, 0x4e7000
  4c55f4:      	ldr	x17, [x16, #0x830]
  4c55f8:      	add	x16, x16, #0x830
  4c55fc:      	br	x17

00000000004c5600 <_ZN5gimli6common9SectionId4name17h705992df43a865f7E@plt>:
  4c5600:      	adrp	x16, 0x4e7000
  4c5604:      	ldr	x17, [x16, #0x838]
  4c5608:      	add	x16, x16, #0x838
  4c560c:      	br	x17

00000000004c5610 <_ZN4core5slice6memchr7memrchr17h9336446924560fa5E@plt>:
  4c5610:      	adrp	x16, 0x4e7000
  4c5614:      	ldr	x17, [x16, #0x840]
  4c5618:      	add	x16, x16, #0x840
  4c561c:      	br	x17

00000000004c5620 <_ZN5gimli4read4line7LineRow18apply_line_advance17ha99c0a69c706c99dE@plt>:
  4c5620:      	adrp	x16, 0x4e7000
  4c5624:      	ldr	x17, [x16, #0x848]
  4c5628:      	add	x16, x16, #0x848
  4c562c:      	br	x17

00000000004c5630 <_ZN9addr2line9path_push17h565208e46d4f0a71E@plt>:
  4c5630:      	adrp	x16, 0x4e7000
  4c5634:      	ldr	x17, [x16, #0x850]
  4c5638:      	add	x16, x16, #0x850
  4c563c:      	br	x17

00000000004c5640 <_ZN5gimli4read6abbrev13Abbreviations5empty17h26c657cac3186606E@plt>:
  4c5640:      	adrp	x16, 0x4e7000
  4c5644:      	ldr	x17, [x16, #0x858]
  4c5648:      	add	x16, x16, #0x858
  4c564c:      	br	x17

00000000004c5650 <_ZN5gimli4read6abbrev10Attributes3new17h6179f629eeb21390E@plt>:
  4c5650:      	adrp	x16, 0x4e7000
  4c5654:      	ldr	x17, [x16, #0x860]
  4c5658:      	add	x16, x16, #0x860
  4c565c:      	br	x17

00000000004c5660 <_ZN5gimli4read6abbrev10Attributes4push17h9149ae13b7c35d68E@plt>:
  4c5660:      	adrp	x16, 0x4e7000
  4c5664:      	ldr	x17, [x16, #0x868]
  4c5668:      	add	x16, x16, #0x868
  4c566c:      	br	x17

00000000004c5670 <_ZN5gimli4read6abbrev12Abbreviation3new17h97e341bd23791373E@plt>:
  4c5670:      	adrp	x16, 0x4e7000
  4c5674:      	ldr	x17, [x16, #0x870]
  4c5678:      	add	x16, x16, #0x870
  4c567c:      	br	x17

00000000004c5680 <_ZN5gimli4read6abbrev13Abbreviations6insert17h46ba8c4f095ff5d2E@plt>:
  4c5680:      	adrp	x16, 0x4e7000
  4c5684:      	ldr	x17, [x16, #0x878]
  4c5688:      	add	x16, x16, #0x878
  4c568c:      	br	x17

00000000004c5690 <_ZN75_$LT$gimli..read..abbrev..Attributes$u20$as$u20$core..ops..deref..Deref$GT$5deref17hacd52cc15818022eE@plt>:
  4c5690:      	adrp	x16, 0x4e7000
  4c5694:      	ldr	x17, [x16, #0x880]
  4c5698:      	add	x16, x16, #0x880
  4c569c:      	br	x17

00000000004c56a0 <poll@plt>:
  4c56a0:      	adrp	x16, 0x4e7000
  4c56a4:      	ldr	x17, [x16, #0x888]
  4c56a8:      	add	x16, x16, #0x888
  4c56ac:      	br	x17

00000000004c56b0 <fcntl@plt>:
  4c56b0:      	adrp	x16, 0x4e7000
  4c56b4:      	ldr	x17, [x16, #0x890]
  4c56b8:      	add	x16, x16, #0x890
  4c56bc:      	br	x17

00000000004c56c0 <open@plt>:
  4c56c0:      	adrp	x16, 0x4e7000
  4c56c4:      	ldr	x17, [x16, #0x898]
  4c56c8:      	add	x16, x16, #0x898
  4c56cc:      	br	x17

00000000004c56d0 <_ZN72_$LT$$RF$str$u20$as$u20$alloc..ffi..c_str..CString..new..SpecNewImpl$GT$13spec_new_impl17h702a79ae301a7cb2E@plt>:
  4c56d0:      	adrp	x16, 0x4e7000
  4c56d4:      	ldr	x17, [x16, #0x8a0]
  4c56d8:      	add	x16, x16, #0x8a0
  4c56dc:      	br	x17

00000000004c56e0 <sched_yield@plt>:
  4c56e0:      	adrp	x16, 0x4e7000
  4c56e4:      	ldr	x17, [x16, #0x8a8]
  4c56e8:      	add	x16, x16, #0x8a8
  4c56ec:      	br	x17

00000000004c56f0 <nanosleep@plt>:
  4c56f0:      	adrp	x16, 0x4e7000
  4c56f4:      	ldr	x17, [x16, #0x8b0]
  4c56f8:      	add	x16, x16, #0x8b0
  4c56fc:      	br	x17

00000000004c5700 <_ZN4core3ffi5c_str4CStr19from_bytes_with_nul17h82c31c91b2dddbffE@plt>:
  4c5700:      	adrp	x16, 0x4e7000
  4c5704:      	ldr	x17, [x16, #0x8b8]
  4c5708:      	add	x16, x16, #0x8b8
  4c570c:      	br	x17

00000000004c5710 <sched_getaffinity@plt>:
  4c5710:      	adrp	x16, 0x4e7000
  4c5714:      	ldr	x17, [x16, #0x8c0]
  4c5718:      	add	x16, x16, #0x8c0
  4c571c:      	br	x17

00000000004c5720 <_ZN47_$LT$std..fs..File$u20$as$u20$std..io..Read$GT$11read_to_end17he942060424311d0dE@plt>:
  4c5720:      	adrp	x16, 0x4e7000
  4c5724:      	ldr	x17, [x16, #0x8c8]
  4c5728:      	add	x16, x16, #0x8c8
  4c572c:      	br	x17

00000000004c5730 <_ZN3std10sys_common2fs10try_exists17h22977e6e62f30cbaE@plt>:
  4c5730:      	adrp	x16, 0x4e7000
  4c5734:      	ldr	x17, [x16, #0x8d0]
  4c5738:      	add	x16, x16, #0x8d0
  4c573c:      	br	x17

00000000004c5740 <_ZN95_$LT$std..path..Components$u20$as$u20$core..iter..traits..double_ended..DoubleEndedIterator$GT$9next_back17h5f3c28a68bc80a6bE@plt>:
  4c5740:      	adrp	x16, 0x4e7000
  4c5744:      	ldr	x17, [x16, #0x8d8]
  4c5748:      	add	x16, x16, #0x8d8
  4c574c:      	br	x17

00000000004c5750 <_ZN3std4path10Components7as_path17h660e19a4ef7f585bE@plt>:
  4c5750:      	adrp	x16, 0x4e7000
  4c5754:      	ldr	x17, [x16, #0x8e0]
  4c5758:      	add	x16, x16, #0x8e0
  4c575c:      	br	x17

00000000004c5760 <_ZN3std4path4Path12_starts_with17h1a556a73d46f2fd9E@plt>:
  4c5760:      	adrp	x16, 0x4e7000
  4c5764:      	ldr	x17, [x16, #0x8e8]
  4c5768:      	add	x16, x16, #0x8e8
  4c576c:      	br	x17

00000000004c5770 <_ZN47_$LT$std..fs..File$u20$as$u20$std..io..Read$GT$14read_to_string17h7a5019b4e696c284E@plt>:
  4c5770:      	adrp	x16, 0x4e7000
  4c5774:      	ldr	x17, [x16, #0x8f0]
  4c5778:      	add	x16, x16, #0x8f0
  4c577c:      	br	x17

00000000004c5780 <_ZN14rustc_demangle12try_demangle17he5bbb81108c7dbd2E@plt>:
  4c5780:      	adrp	x16, 0x4e7000
  4c5784:      	ldr	x17, [x16, #0x8f8]
  4c5788:      	add	x16, x16, #0x8f8
  4c578c:      	br	x17

00000000004c5790 <_ZN3std3env7_var_os17h5a126f969672563eE@plt>:
  4c5790:      	adrp	x16, 0x4e7000
  4c5794:      	ldr	x17, [x16, #0x900]
  4c5798:      	add	x16, x16, #0x900
  4c579c:      	br	x17

00000000004c57a0 <_ZN3std3sys4unix6os_str3Buf11into_string17h6472d7b0b6a10097E@plt>:
  4c57a0:      	adrp	x16, 0x4e7000
  4c57a4:      	ldr	x17, [x16, #0x908]
  4c57a8:      	add	x16, x16, #0x908
  4c57ac:      	br	x17

00000000004c57b0 <_ZN4core3fmt9Formatter9alternate17h9f6259ebc948f8ceE@plt>:
  4c57b0:      	adrp	x16, 0x4e7000
  4c57b4:      	ldr	x17, [x16, #0x910]
  4c57b8:      	add	x16, x16, #0x910
  4c57bc:      	br	x17

00000000004c57c0 <getcwd@plt>:
  4c57c0:      	adrp	x16, 0x4e7000
  4c57c4:      	ldr	x17, [x16, #0x918]
  4c57c8:      	add	x16, x16, #0x918
  4c57cc:      	br	x17

00000000004c57d0 <_ZN3std3env7vars_os17he89014115f5a5f7dE@plt>:
  4c57d0:      	adrp	x16, 0x4e7000
  4c57d4:      	ldr	x17, [x16, #0x920]
  4c57d8:      	add	x16, x16, #0x920
  4c57dc:      	br	x17

00000000004c57e0 <_ZN3std3sys4unix5locks12futex_rwlock6RwLock14read_contended17h044aa4e73f8d1872E@plt>:
  4c57e0:      	adrp	x16, 0x4e7000
  4c57e4:      	ldr	x17, [x16, #0x928]
  4c57e8:      	add	x16, x16, #0x928
  4c57ec:      	br	x17

00000000004c57f0 <_ZN43_$LT$char$u20$as$u20$core..fmt..Display$GT$3fmt17h1f27881c1f89bddaE@plt>:
  4c57f0:      	adrp	x16, 0x4e7000
  4c57f4:      	ldr	x17, [x16, #0x930]
  4c57f8:      	add	x16, x16, #0x930
  4c57fc:      	br	x17

00000000004c5800 <_ZN3std3env7args_os17h649f7e471c0eb9d0E@plt>:
  4c5800:      	adrp	x16, 0x4e7000
  4c5804:      	ldr	x17, [x16, #0x938]
  4c5808:      	add	x16, x16, #0x938
  4c580c:      	br	x17

00000000004c5810 <write@plt>:
  4c5810:      	adrp	x16, 0x4e7000
  4c5814:      	ldr	x17, [x16, #0x940]
  4c5818:      	add	x16, x16, #0x940
  4c581c:      	br	x17

00000000004c5820 <fsync@plt>:
  4c5820:      	adrp	x16, 0x4e7000
  4c5824:      	ldr	x17, [x16, #0x948]
  4c5828:      	add	x16, x16, #0x948
  4c582c:      	br	x17

00000000004c5830 <fdatasync@plt>:
  4c5830:      	adrp	x16, 0x4e7000
  4c5834:      	ldr	x17, [x16, #0x950]
  4c5838:      	add	x16, x16, #0x950
  4c583c:      	br	x17

00000000004c5840 <ftruncate64@plt>:
  4c5840:      	adrp	x16, 0x4e7000
  4c5844:      	ldr	x17, [x16, #0x958]
  4c5848:      	add	x16, x16, #0x958
  4c584c:      	br	x17

00000000004c5850 <fstat@plt>:
  4c5850:      	adrp	x16, 0x4e7000
  4c5854:      	ldr	x17, [x16, #0x960]
  4c5858:      	add	x16, x16, #0x960
  4c585c:      	br	x17

00000000004c5860 <fchmod@plt>:
  4c5860:      	adrp	x16, 0x4e7000
  4c5864:      	ldr	x17, [x16, #0x968]
  4c5868:      	add	x16, x16, #0x968
  4c586c:      	br	x17

00000000004c5870 <futimens@plt>:
  4c5870:      	adrp	x16, 0x4e7000
  4c5874:      	ldr	x17, [x16, #0x970]
  4c5878:      	add	x16, x16, #0x970
  4c587c:      	br	x17

00000000004c5880 <read@plt>:
  4c5880:      	adrp	x16, 0x4e7000
  4c5884:      	ldr	x17, [x16, #0x978]
  4c5888:      	add	x16, x16, #0x978
  4c588c:      	br	x17

00000000004c5890 <readv@plt>:
  4c5890:      	adrp	x16, 0x4e7000
  4c5894:      	ldr	x17, [x16, #0x980]
  4c5898:      	add	x16, x16, #0x980
  4c589c:      	br	x17

00000000004c58a0 <lseek64@plt>:
  4c58a0:      	adrp	x16, 0x4e7000
  4c58a4:      	ldr	x17, [x16, #0x988]
  4c58a8:      	add	x16, x16, #0x988
  4c58ac:      	br	x17

00000000004c58b0 <writev@plt>:
  4c58b0:      	adrp	x16, 0x4e7000
  4c58b4:      	ldr	x17, [x16, #0x990]
  4c58b8:      	add	x16, x16, #0x990
  4c58bc:      	br	x17

00000000004c58c0 <_ZN86_$LT$std..sys..unix..fs..ReadDir$u20$as$u20$core..iter..traits..iterator..Iterator$GT$4next17h91a5d4b49477b300E@plt>:
  4c58c0:      	adrp	x16, 0x4e7000
  4c58c4:      	ldr	x17, [x16, #0x998]
  4c58c8:      	add	x16, x16, #0x998
  4c58cc:      	br	x17

00000000004c58d0 <_ZN3std4path4Path5_join17ha04adeb472b3b76dE@plt>:
  4c58d0:      	adrp	x16, 0x4e7000
  4c58d4:      	ldr	x17, [x16, #0x9a0]
  4c58d8:      	add	x16, x16, #0x9a0
  4c58dc:      	br	x17

00000000004c58e0 <dirfd@plt>:
  4c58e0:      	adrp	x16, 0x4e7000
  4c58e4:      	ldr	x17, [x16, #0x9a8]
  4c58e8:      	add	x16, x16, #0x9a8
  4c58ec:      	br	x17

00000000004c58f0 <fstatat@plt>:
  4c58f0:      	adrp	x16, 0x4e7000
  4c58f4:      	ldr	x17, [x16, #0x9b0]
  4c58f8:      	add	x16, x16, #0x9b0
  4c58fc:      	br	x17

00000000004c5900 <stat@plt>:
  4c5900:      	adrp	x16, 0x4e7000
  4c5904:      	ldr	x17, [x16, #0x9b8]
  4c5908:      	add	x16, x16, #0x9b8
  4c590c:      	br	x17

00000000004c5910 <mkdir@plt>:
  4c5910:      	adrp	x16, 0x4e7000
  4c5914:      	ldr	x17, [x16, #0x9c0]
  4c5918:      	add	x16, x16, #0x9c0
  4c591c:      	br	x17

00000000004c5920 <_ZN3std4path4Path6is_dir17hc2fa6ec00c90648bE@plt>:
  4c5920:      	adrp	x16, 0x4e7000
  4c5924:      	ldr	x17, [x16, #0x9c8]
  4c5928:      	add	x16, x16, #0x9c8
  4c592c:      	br	x17

00000000004c5930 <strerror_r@plt>:
  4c5930:      	adrp	x16, 0x4e7000
  4c5934:      	ldr	x17, [x16, #0x9d0]
  4c5938:      	add	x16, x16, #0x9d0
  4c593c:      	br	x17

00000000004c5940 <_ZN98_$LT$alloc..string..String$u20$as$u20$core..convert..From$LT$alloc..borrow..Cow$LT$str$GT$$GT$$GT$4from17hffe041f4bcefce32E@plt>:
  4c5940:      	adrp	x16, 0x4e7000
  4c5944:      	ldr	x17, [x16, #0x9d8]
  4c5948:      	add	x16, x16, #0x9d8
  4c594c:      	br	x17

00000000004c5950 <_ZN58_$LT$std..io..stdio..StdinRaw$u20$as$u20$std..io..Read$GT$11read_to_end17h6917fda7aa158c02E@plt>:
  4c5950:      	adrp	x16, 0x4e7000
  4c5954:      	ldr	x17, [x16, #0x9e0]
  4c5958:      	add	x16, x16, #0x9e0
  4c595c:      	br	x17

00000000004c5960 <_ZN62_$LT$std..io..stdio..StdinLock$u20$as$u20$std..io..BufRead$GT$9read_line17hd9ce679fd9bfb9a9E@plt>:
  4c5960:      	adrp	x16, 0x4e7000
  4c5964:      	ldr	x17, [x16, #0x9e8]
  4c5968:      	add	x16, x16, #0x9e8
  4c596c:      	br	x17

00000000004c5970 <_ZN59_$LT$std..io..stdio..StdinLock$u20$as$u20$std..io..Read$GT$13read_vectored17h4118e7b9da1ca3d6E@plt>:
  4c5970:      	adrp	x16, 0x4e7000
  4c5974:      	ldr	x17, [x16, #0x9f0]
  4c5978:      	add	x16, x16, #0x9f0
  4c597c:      	br	x17

00000000004c5980 <_ZN59_$LT$std..io..stdio..StdinLock$u20$as$u20$std..io..Read$GT$14read_to_string17ha713793bbc5bb687E@plt>:
  4c5980:      	adrp	x16, 0x4e7000
  4c5984:      	ldr	x17, [x16, #0x9f8]
  4c5988:      	add	x16, x16, #0x9f8
  4c598c:      	br	x17

00000000004c5990 <_ZN59_$LT$std..io..stdio..StdinLock$u20$as$u20$std..io..Read$GT$10read_exact17h0ffd9004ce44bbeaE@plt>:
  4c5990:      	adrp	x16, 0x4e7000
  4c5994:      	ldr	x17, [x16, #0xa00]
  4c5998:      	add	x16, x16, #0xa00
  4c599c:      	br	x17

00000000004c59a0 <_ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$5write17h2a5ccbb9e21de3cfE@plt>:
  4c59a0:      	adrp	x16, 0x4e7000
  4c59a4:      	ldr	x17, [x16, #0xa08]
  4c59a8:      	add	x16, x16, #0xa08
  4c59ac:      	br	x17

00000000004c59b0 <_ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$14write_vectored17h82c067181a2401adE@plt>:
  4c59b0:      	adrp	x16, 0x4e7000
  4c59b4:      	ldr	x17, [x16, #0xa10]
  4c59b8:      	add	x16, x16, #0xa10
  4c59bc:      	br	x17

00000000004c59c0 <_ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$5flush17hd24c7af68803f0adE@plt>:
  4c59c0:      	adrp	x16, 0x4e7000
  4c59c4:      	ldr	x17, [x16, #0xa18]
  4c59c8:      	add	x16, x16, #0xa18
  4c59cc:      	br	x17

00000000004c59d0 <_ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$9write_all17h14fcf3116880ba21E@plt>:
  4c59d0:      	adrp	x16, 0x4e7000
  4c59d4:      	ldr	x17, [x16, #0xa20]
  4c59d8:      	add	x16, x16, #0xa20
  4c59dc:      	br	x17

00000000004c59e0 <_ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$18write_all_vectored17h264a9984108a7a7dE@plt>:
  4c59e0:      	adrp	x16, 0x4e7000
  4c59e4:      	ldr	x17, [x16, #0xa28]
  4c59e8:      	add	x16, x16, #0xa28
  4c59ec:      	br	x17

00000000004c59f0 <_ZN61_$LT$$RF$std..io..stdio..Stdout$u20$as$u20$std..io..Write$GT$9write_fmt17h990685ccf1dab392E@plt>:
  4c59f0:      	adrp	x16, 0x4e7000
  4c59f4:      	ldr	x17, [x16, #0xa30]
  4c59f8:      	add	x16, x16, #0xa30
  4c59fc:      	br	x17

00000000004c5a00 <_ZN61_$LT$std..io..stdio..StdoutLock$u20$as$u20$std..io..Write$GT$5write17h8725ecd89f5db4fcE@plt>:
  4c5a00:      	adrp	x16, 0x4e7000
  4c5a04:      	ldr	x17, [x16, #0xa38]
  4c5a08:      	add	x16, x16, #0xa38
  4c5a0c:      	br	x17

00000000004c5a10 <_ZN61_$LT$std..io..stdio..StdoutLock$u20$as$u20$std..io..Write$GT$9write_all17hdbfd79f8421a8d44E@plt>:
  4c5a10:      	adrp	x16, 0x4e7000
  4c5a14:      	ldr	x17, [x16, #0xa40]
  4c5a18:      	add	x16, x16, #0xa40
  4c5a1c:      	br	x17

00000000004c5a20 <_ZN61_$LT$std..io..stdio..StdoutLock$u20$as$u20$std..io..Write$GT$18write_all_vectored17ha5e0de8fbd6215b2E@plt>:
  4c5a20:      	adrp	x16, 0x4e7000
  4c5a24:      	ldr	x17, [x16, #0xa48]
  4c5a28:      	add	x16, x16, #0xa48
  4c5a2c:      	br	x17

00000000004c5a30 <_ZN61_$LT$$RF$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$5write17h1b180de539bb082bE@plt>:
  4c5a30:      	adrp	x16, 0x4e7000
  4c5a34:      	ldr	x17, [x16, #0xa50]
  4c5a38:      	add	x16, x16, #0xa50
  4c5a3c:      	br	x17

00000000004c5a40 <_ZN61_$LT$$RF$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$14write_vectored17h7020704d21378649E@plt>:
  4c5a40:      	adrp	x16, 0x4e7000
  4c5a44:      	ldr	x17, [x16, #0xa58]
  4c5a48:      	add	x16, x16, #0xa58
  4c5a4c:      	br	x17

00000000004c5a50 <_ZN61_$LT$$RF$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$5flush17h012425abc4b5716dE@plt>:
  4c5a50:      	adrp	x16, 0x4e7000
  4c5a54:      	ldr	x17, [x16, #0xa60]
  4c5a58:      	add	x16, x16, #0xa60
  4c5a5c:      	br	x17

00000000004c5a60 <_ZN61_$LT$$RF$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$9write_all17haa0248e9ac1fd86fE@plt>:
  4c5a60:      	adrp	x16, 0x4e7000
  4c5a64:      	ldr	x17, [x16, #0xa68]
  4c5a68:      	add	x16, x16, #0xa68
  4c5a6c:      	br	x17

00000000004c5a70 <_ZN61_$LT$$RF$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$18write_all_vectored17hb279ff6f3cfabfe1E@plt>:
  4c5a70:      	adrp	x16, 0x4e7000
  4c5a74:      	ldr	x17, [x16, #0xa70]
  4c5a78:      	add	x16, x16, #0xa70
  4c5a7c:      	br	x17

00000000004c5a80 <_ZN61_$LT$$RF$std..io..stdio..Stderr$u20$as$u20$std..io..Write$GT$9write_fmt17h4fb051b99f6799e5E@plt>:
  4c5a80:      	adrp	x16, 0x4e7000
  4c5a84:      	ldr	x17, [x16, #0xa78]
  4c5a88:      	add	x16, x16, #0xa78
  4c5a8c:      	br	x17

00000000004c5a90 <_ZN61_$LT$std..io..stdio..StderrLock$u20$as$u20$std..io..Write$GT$9write_all17hbf707a939d268342E@plt>:
  4c5a90:      	adrp	x16, 0x4e7000
  4c5a94:      	ldr	x17, [x16, #0xa80]
  4c5a98:      	add	x16, x16, #0xa80
  4c5a9c:      	br	x17

00000000004c5aa0 <_ZN4core3fmt9Formatter9precision17h89be8f6327d8c759E@plt>:
  4c5aa0:      	adrp	x16, 0x4e7000
  4c5aa4:      	ldr	x17, [x16, #0xa88]
  4c5aa8:      	add	x16, x16, #0xa88
  4c5aac:      	br	x17

00000000004c5ab0 <_ZN4core3fmt9Formatter5width17ha82307ee94a3b3a0E@plt>:
  4c5ab0:      	adrp	x16, 0x4e7000
  4c5ab4:      	ldr	x17, [x16, #0xa90]
  4c5ab8:      	add	x16, x16, #0xa90
  4c5abc:      	br	x17

00000000004c5ac0 <_ZN57_$LT$core..fmt..Formatter$u20$as$u20$core..fmt..Write$GT$10write_char17h333d0f1660f12600E@plt>:
  4c5ac0:      	adrp	x16, 0x4e7000
  4c5ac4:      	ldr	x17, [x16, #0xa98]
  4c5ac8:      	add	x16, x16, #0xa98
  4c5acc:      	br	x17

00000000004c5ad0 <_ZN3std3net6parser51_$LT$impl$u20$std..net..socket_addr..SocketAddr$GT$11parse_ascii17h91f27b3c69f48c43E@plt>:
  4c5ad0:      	adrp	x16, 0x4e7000
  4c5ad4:      	ldr	x17, [x16, #0xaa0]
  4c5ad8:      	add	x16, x16, #0xaa0
  4c5adc:      	br	x17

00000000004c5ae0 <_ZN74_$LT$std..net..socket_addr..SocketAddrV6$u20$as$u20$core..fmt..Display$GT$3fmt17h4b44c41d1cc84327E@plt>:
  4c5ae0:      	adrp	x16, 0x4e7000
  4c5ae4:      	ldr	x17, [x16, #0xaa8]
  4c5ae8:      	add	x16, x16, #0xaa8
  4c5aec:      	br	x17

00000000004c5af0 <_ZN74_$LT$std..net..socket_addr..SocketAddrV4$u20$as$u20$core..fmt..Display$GT$3fmt17h4d9d4f8ed6cffa62E@plt>:
  4c5af0:      	adrp	x16, 0x4e7000
  4c5af4:      	ldr	x17, [x16, #0xab0]
  4c5af8:      	add	x16, x16, #0xab0
  4c5afc:      	br	x17

00000000004c5b00 <_ZN70_$LT$std..net..socket_addr..SocketAddrV6$u20$as$u20$core..cmp..Ord$GT$3cmp17h643d9153ed2616b8E@plt>:
  4c5b00:      	adrp	x16, 0x4e7000
  4c5b04:      	ldr	x17, [x16, #0xab8]
  4c5b08:      	add	x16, x16, #0xab8
  4c5b0c:      	br	x17

00000000004c5b10 <_ZN78_$LT$$LP$$RF$str$C$u16$RP$$u20$as$u20$std..net..socket_addr..ToSocketAddrs$GT$15to_socket_addrs17h3d98f57ae77822c4E@plt>:
  4c5b10:      	adrp	x16, 0x4e7000
  4c5b14:      	ldr	x17, [x16, #0xac0]
  4c5b18:      	add	x16, x16, #0xac0
  4c5b1c:      	br	x17

00000000004c5b20 <_ZN60_$LT$str$u20$as$u20$std..net..socket_addr..ToSocketAddrs$GT$15to_socket_addrs17h48e0d6240f11158eE@plt>:
  4c5b20:      	adrp	x16, 0x4e7000
  4c5b24:      	ldr	x17, [x16, #0xac8]
  4c5b28:      	add	x16, x16, #0xac8
  4c5b2c:      	br	x17

00000000004c5b30 <_ZN90_$LT$std..sys_common..net..LookupHost$u20$as$u20$core..convert..TryFrom$LT$$RF$str$GT$$GT$8try_from17hb86d3d63e21befceE@plt>:
  4c5b30:      	adrp	x16, 0x4e7000
  4c5b34:      	ldr	x17, [x16, #0xad0]
  4c5b38:      	add	x16, x16, #0xad0
  4c5b3c:      	br	x17

00000000004c5b40 <socket@plt>:
  4c5b40:      	adrp	x16, 0x4e7000
  4c5b44:      	ldr	x17, [x16, #0xad8]
  4c5b48:      	add	x16, x16, #0xad8
  4c5b4c:      	br	x17

00000000004c5b50 <ioctl@plt>:
  4c5b50:      	adrp	x16, 0x4e7000
  4c5b54:      	ldr	x17, [x16, #0xae0]
  4c5b58:      	add	x16, x16, #0xae0
  4c5b5c:      	br	x17

00000000004c5b60 <connect@plt>:
  4c5b60:      	adrp	x16, 0x4e7000
  4c5b64:      	ldr	x17, [x16, #0xae8]
  4c5b68:      	add	x16, x16, #0xae8
  4c5b6c:      	br	x17

00000000004c5b70 <_ZN62_$LT$core..time..Duration$u20$as$u20$core..ops..arith..Sub$GT$3sub17h6b477a1d0189f5edE@plt>:
  4c5b70:      	adrp	x16, 0x4e7000
  4c5b74:      	ldr	x17, [x16, #0xaf0]
  4c5b78:      	add	x16, x16, #0xaf0
  4c5b7c:      	br	x17

00000000004c5b80 <getsockopt@plt>:
  4c5b80:      	adrp	x16, 0x4e7000
  4c5b84:      	ldr	x17, [x16, #0xaf8]
  4c5b88:      	add	x16, x16, #0xaf8
  4c5b8c:      	br	x17

00000000004c5b90 <recv@plt>:
  4c5b90:      	adrp	x16, 0x4e7000
  4c5b94:      	ldr	x17, [x16, #0xb00]
  4c5b98:      	add	x16, x16, #0xb00
  4c5b9c:      	br	x17

00000000004c5ba0 <setsockopt@plt>:
  4c5ba0:      	adrp	x16, 0x4e7000
  4c5ba4:      	ldr	x17, [x16, #0xb08]
  4c5ba8:      	add	x16, x16, #0xb08
  4c5bac:      	br	x17

00000000004c5bb0 <send@plt>:
  4c5bb0:      	adrp	x16, 0x4e7000
  4c5bb4:      	ldr	x17, [x16, #0xb10]
  4c5bb8:      	add	x16, x16, #0xb10
  4c5bbc:      	br	x17

00000000004c5bc0 <_ZN68_$LT$std..sys_common..net..TcpStream$u20$as$u20$core..fmt..Debug$GT$3fmt17h3b0f329739ceb690E@plt>:
  4c5bc0:      	adrp	x16, 0x4e7000
  4c5bc4:      	ldr	x17, [x16, #0xb18]
  4c5bc8:      	add	x16, x16, #0xb18
  4c5bcc:      	br	x17

00000000004c5bd0 <_ZN3std3net3tcp11TcpListener6accept17h7bc9749e81c4589eE@plt>:
  4c5bd0:      	adrp	x16, 0x4e7000
  4c5bd4:      	ldr	x17, [x16, #0xb20]
  4c5bd8:      	add	x16, x16, #0xb20
  4c5bdc:      	br	x17

00000000004c5be0 <getpeername@plt>:
  4c5be0:      	adrp	x16, 0x4e7000
  4c5be4:      	ldr	x17, [x16, #0xb28]
  4c5be8:      	add	x16, x16, #0xb28
  4c5bec:      	br	x17

00000000004c5bf0 <_ZN68_$LT$std..sys_common..net..UdpSocket$u20$as$u20$core..fmt..Debug$GT$3fmt17h597337dcd80b1a17E@plt>:
  4c5bf0:      	adrp	x16, 0x4e7000
  4c5bf4:      	ldr	x17, [x16, #0xb30]
  4c5bf8:      	add	x16, x16, #0xb30
  4c5bfc:      	br	x17

00000000004c5c00 <pread64@plt>:
  4c5c00:      	adrp	x16, 0x4e7000
  4c5c04:      	ldr	x17, [x16, #0xb38]
  4c5c08:      	add	x16, x16, #0xb38
  4c5c0c:      	br	x17

00000000004c5c10 <pwrite64@plt>:
  4c5c10:      	adrp	x16, 0x4e7000
  4c5c14:      	ldr	x17, [x16, #0xb40]
  4c5c18:      	add	x16, x16, #0xb40
  4c5c1c:      	br	x17

00000000004c5c20 <_ZN4core5slice5ascii30_$LT$impl$u20$$u5b$u8$u5d$$GT$12escape_ascii17h386b8f6ec95953d0E@plt>:
  4c5c20:      	adrp	x16, 0x4e7000
  4c5c24:      	ldr	x17, [x16, #0xb48]
  4c5c28:      	add	x16, x16, #0xb48
  4c5c2c:      	br	x17

00000000004c5c30 <sendmsg@plt>:
  4c5c30:      	adrp	x16, 0x4e7000
  4c5c34:      	ldr	x17, [x16, #0xb50]
  4c5c38:      	add	x16, x16, #0xb50
  4c5c3c:      	br	x17

00000000004c5c40 <getsockname@plt>:
  4c5c40:      	adrp	x16, 0x4e7000
  4c5c44:      	ldr	x17, [x16, #0xb58]
  4c5c48:      	add	x16, x16, #0xb58
  4c5c4c:      	br	x17

00000000004c5c50 <bind@plt>:
  4c5c50:      	adrp	x16, 0x4e7000
  4c5c54:      	ldr	x17, [x16, #0xb60]
  4c5c58:      	add	x16, x16, #0xb60
  4c5c5c:      	br	x17

00000000004c5c60 <recvfrom@plt>:
  4c5c60:      	adrp	x16, 0x4e7000
  4c5c64:      	ldr	x17, [x16, #0xb68]
  4c5c68:      	add	x16, x16, #0xb68
  4c5c6c:      	br	x17

00000000004c5c70 <recvmsg@plt>:
  4c5c70:      	adrp	x16, 0x4e7000
  4c5c74:      	ldr	x17, [x16, #0xb70]
  4c5c78:      	add	x16, x16, #0xb70
  4c5c7c:      	br	x17

00000000004c5c80 <sendto@plt>:
  4c5c80:      	adrp	x16, 0x4e7000
  4c5c84:      	ldr	x17, [x16, #0xb78]
  4c5c88:      	add	x16, x16, #0xb78
  4c5c8c:      	br	x17

00000000004c5c90 <listen@plt>:
  4c5c90:      	adrp	x16, 0x4e7000
  4c5c94:      	ldr	x17, [x16, #0xb80]
  4c5c98:      	add	x16, x16, #0xb80
  4c5c9c:      	br	x17

00000000004c5ca0 <shutdown@plt>:
  4c5ca0:      	adrp	x16, 0x4e7000
  4c5ca4:      	ldr	x17, [x16, #0xb88]
  4c5ca8:      	add	x16, x16, #0xb88
  4c5cac:      	br	x17

00000000004c5cb0 <getppid@plt>:
  4c5cb0:      	adrp	x16, 0x4e7000
  4c5cb4:      	ldr	x17, [x16, #0xb90]
  4c5cb8:      	add	x16, x16, #0xb90
  4c5cbc:      	br	x17

00000000004c5cc0 <_ZN3std5panic19get_backtrace_style17hc9e21435f71ff2feE@plt>:
  4c5cc0:      	adrp	x16, 0x4e7000
  4c5cc4:      	ldr	x17, [x16, #0xb98]
  4c5cc8:      	add	x16, x16, #0xb98
  4c5ccc:      	br	x17

00000000004c5cd0 <_ZN80_$LT$std..path..Components$u20$as$u20$core..iter..traits..iterator..Iterator$GT$4next17hcc928a070c4679a1E@plt>:
  4c5cd0:      	adrp	x16, 0x4e7000
  4c5cd4:      	ldr	x17, [x16, #0xba0]
  4c5cd8:      	add	x16, x16, #0xba0
  4c5cdc:      	br	x17

00000000004c5ce0 <_ZN3std4path7PathBuf14_set_file_name17h04506c6b25d1afbdE@plt>:
  4c5ce0:      	adrp	x16, 0x4e7000
  4c5ce4:      	ldr	x17, [x16, #0xba8]
  4c5ce8:      	add	x16, x16, #0xba8
  4c5cec:      	br	x17

00000000004c5cf0 <_ZN3std4path7PathBuf14_set_extension17h1750b6383b94f2d0E@plt>:
  4c5cf0:      	adrp	x16, 0x4e7000
  4c5cf4:      	ldr	x17, [x16, #0xbb0]
  4c5cf8:      	add	x16, x16, #0xbb0
  4c5cfc:      	br	x17

00000000004c5d00 <_ZN3std4path4Path9file_stem17ha7cee1c6f55ed7bdE@plt>:
  4c5d00:      	adrp	x16, 0x4e7000
  4c5d04:      	ldr	x17, [x16, #0xbb8]
  4c5d08:      	add	x16, x16, #0xbb8
  4c5d0c:      	br	x17

00000000004c5d10 <_ZN3std4path4Path13_strip_prefix17h7b953370eaa2cb25E@plt>:
  4c5d10:      	adrp	x16, 0x4e7000
  4c5d14:      	ldr	x17, [x16, #0xbc0]
  4c5d18:      	add	x16, x16, #0xbc0
  4c5d1c:      	br	x17

00000000004c5d20 <_ZN3std4path4Path7is_file17hd40d421218d2d73bE@plt>:
  4c5d20:      	adrp	x16, 0x4e7000
  4c5d24:      	ldr	x17, [x16, #0xbc8]
  4c5d28:      	add	x16, x16, #0xbc8
  4c5d2c:      	br	x17

00000000004c5d30 <lstat@plt>:
  4c5d30:      	adrp	x16, 0x4e7000
  4c5d34:      	ldr	x17, [x16, #0xbd0]
  4c5d38:      	add	x16, x16, #0xbd0
  4c5d3c:      	br	x17

00000000004c5d40 <_ZN68_$LT$std..sys..unix..os_str..Slice$u20$as$u20$core..fmt..Display$GT$3fmt17hf1402fa01b18ba3aE@plt>:
  4c5d40:      	adrp	x16, 0x4e7000
  4c5d44:      	ldr	x17, [x16, #0xbd8]
  4c5d48:      	add	x16, x16, #0xbd8
  4c5d4c:      	br	x17

00000000004c5d50 <_ZN3std7process5Child16wait_with_output17h8da0ac6a82b955b0E@plt>:
  4c5d50:      	adrp	x16, 0x4e7000
  4c5d54:      	ldr	x17, [x16, #0xbe0]
  4c5d58:      	add	x16, x16, #0xbe0
  4c5d5c:      	br	x17

00000000004c5d60 <waitpid@plt>:
  4c5d60:      	adrp	x16, 0x4e7000
  4c5d64:      	ldr	x17, [x16, #0xbe8]
  4c5d68:      	add	x16, x16, #0xbe8
  4c5d6c:      	br	x17

00000000004c5d70 <_ZN85_$LT$std..sys..unix..process..process_common..Command$u20$as$u20$core..fmt..Debug$GT$3fmt17hc1ab6bdce2c1e521E@plt>:
  4c5d70:      	adrp	x16, 0x4e7000
  4c5d74:      	ldr	x17, [x16, #0xbf0]
  4c5d78:      	add	x16, x16, #0xbf0
  4c5d7c:      	br	x17

00000000004c5d80 <_ZN89_$LT$std..sys..unix..process..process_inner..ExitStatus$u20$as$u20$core..fmt..Display$GT$3fmt17h8e483c7837951d37E@plt>:
  4c5d80:      	adrp	x16, 0x4e7000
  4c5d84:      	ldr	x17, [x16, #0xbf8]
  4c5d88:      	add	x16, x16, #0xbf8
  4c5d8c:      	br	x17

00000000004c5d90 <_ZN3std7process4exit17h44e80bd67bd3b988E@plt>:
  4c5d90:      	adrp	x16, 0x4e7000
  4c5d94:      	ldr	x17, [x16, #0xc00]
  4c5d98:      	add	x16, x16, #0xc00
  4c5d9c:      	br	x17

00000000004c5da0 <kill@plt>:
  4c5da0:      	adrp	x16, 0x4e7000
  4c5da4:      	ldr	x17, [x16, #0xc08]
  4c5da8:      	add	x16, x16, #0xc08
  4c5dac:      	br	x17

00000000004c5db0 <_ZN3std7process5Child4wait17h78ec646f37931683E@plt>:
  4c5db0:      	adrp	x16, 0x4e7000
  4c5db4:      	ldr	x17, [x16, #0xc10]
  4c5db8:      	add	x16, x16, #0xc10
  4c5dbc:      	br	x17

00000000004c5dc0 <_ZN3std3sys4unix2fd8FileDesc11read_to_end17hf8f4db7732a32ad5E@plt>:
  4c5dc0:      	adrp	x16, 0x4e7000
  4c5dc4:      	ldr	x17, [x16, #0xc18]
  4c5dc8:      	add	x16, x16, #0xc18
  4c5dcc:      	br	x17

00000000004c5dd0 <getpid@plt>:
  4c5dd0:      	adrp	x16, 0x4e7000
  4c5dd4:      	ldr	x17, [x16, #0xc20]
  4c5dd8:      	add	x16, x16, #0xc20
  4c5ddc:      	br	x17

00000000004c5de0 <memalign@plt>:
  4c5de0:      	adrp	x16, 0x4e7000
  4c5de4:      	ldr	x17, [x16, #0xc28]
  4c5de8:      	add	x16, x16, #0xc28
  4c5dec:      	br	x17

00000000004c5df0 <_ZN81_$LT$$RF$$u5b$u8$u5d$$u20$as$u20$alloc..ffi..c_str..CString..new..SpecNewImpl$GT$13spec_new_impl17hd49a1e43b28fc069E@plt>:
  4c5df0:      	adrp	x16, 0x4e7000
  4c5df4:      	ldr	x17, [x16, #0xc30]
  4c5df8:      	add	x16, x16, #0xc30
  4c5dfc:      	br	x17

00000000004c5e00 <rmdir@plt>:
  4c5e00:      	adrp	x16, 0x4e7000
  4c5e04:      	ldr	x17, [x16, #0xc38]
  4c5e08:      	add	x16, x16, #0xc38
  4c5e0c:      	br	x17

00000000004c5e10 <lchown@plt>:
  4c5e10:      	adrp	x16, 0x4e7000
  4c5e14:      	ldr	x17, [x16, #0xc40]
  4c5e18:      	add	x16, x16, #0xc40
  4c5e1c:      	br	x17

00000000004c5e20 <chown@plt>:
  4c5e20:      	adrp	x16, 0x4e7000
  4c5e24:      	ldr	x17, [x16, #0xc48]
  4c5e28:      	add	x16, x16, #0xc48
  4c5e2c:      	br	x17

00000000004c5e30 <realpath@plt>:
  4c5e30:      	adrp	x16, 0x4e7000
  4c5e34:      	ldr	x17, [x16, #0xc50]
  4c5e38:      	add	x16, x16, #0xc50
  4c5e3c:      	br	x17

00000000004c5e40 <rename@plt>:
  4c5e40:      	adrp	x16, 0x4e7000
  4c5e44:      	ldr	x17, [x16, #0xc58]
  4c5e48:      	add	x16, x16, #0xc58
  4c5e4c:      	br	x17

00000000004c5e50 <link@plt>:
  4c5e50:      	adrp	x16, 0x4e7000
  4c5e54:      	ldr	x17, [x16, #0xc60]
  4c5e58:      	add	x16, x16, #0xc60
  4c5e5c:      	br	x17

00000000004c5e60 <symlink@plt>:
  4c5e60:      	adrp	x16, 0x4e7000
  4c5e64:      	ldr	x17, [x16, #0xc68]
  4c5e68:      	add	x16, x16, #0xc68
  4c5e6c:      	br	x17

00000000004c5e70 <chmod@plt>:
  4c5e70:      	adrp	x16, 0x4e7000
  4c5e74:      	ldr	x17, [x16, #0xc70]
  4c5e78:      	add	x16, x16, #0xc70
  4c5e7c:      	br	x17

00000000004c5e80 <chroot@plt>:
  4c5e80:      	adrp	x16, 0x4e7000
  4c5e84:      	ldr	x17, [x16, #0xc78]
  4c5e88:      	add	x16, x16, #0xc78
  4c5e8c:      	br	x17

00000000004c5e90 <opendir@plt>:
  4c5e90:      	adrp	x16, 0x4e7000
  4c5e94:      	ldr	x17, [x16, #0xc80]
  4c5e98:      	add	x16, x16, #0xc80
  4c5e9c:      	br	x17

00000000004c5ea0 <unlink@plt>:
  4c5ea0:      	adrp	x16, 0x4e7000
  4c5ea4:      	ldr	x17, [x16, #0xc88]
  4c5ea8:      	add	x16, x16, #0xc88
  4c5eac:      	br	x17

00000000004c5eb0 <chdir@plt>:
  4c5eb0:      	adrp	x16, 0x4e7000
  4c5eb4:      	ldr	x17, [x16, #0xc90]
  4c5eb8:      	add	x16, x16, #0xc90
  4c5ebc:      	br	x17

00000000004c5ec0 <_ZN14rustc_demangle8Demangle6as_str17h45e5cc3589cc1da3E@plt>:
  4c5ec0:      	adrp	x16, 0x4e7000
  4c5ec4:      	ldr	x17, [x16, #0xc98]
  4c5ec8:      	add	x16, x16, #0xc98
  4c5ecc:      	br	x17

00000000004c5ed0 <_ZN82_$LT$core..char..EscapeDebug$u20$as$u20$core..iter..traits..iterator..Iterator$GT$4next17hdcf412ae720c2272E@plt>:
  4c5ed0:      	adrp	x16, 0x4e7000
  4c5ed4:      	ldr	x17, [x16, #0xca0]
  4c5ed8:      	add	x16, x16, #0xca0
  4c5edc:      	br	x17

00000000004c5ee0 <_ZN4core7unicode12unicode_data15grapheme_extend6lookup17h05751b6256b34f8dE@plt>:
  4c5ee0:      	adrp	x16, 0x4e7000
  4c5ee4:      	ldr	x17, [x16, #0xca8]
  4c5ee8:      	add	x16, x16, #0xca8
  4c5eec:      	br	x17

00000000004c5ef0 <_ZN4core7unicode9printable12is_printable17h2453b3ea9d8bd33fE@plt>:
  4c5ef0:      	adrp	x16, 0x4e7000
  4c5ef4:      	ldr	x17, [x16, #0xcb0]
  4c5ef8:      	add	x16, x16, #0xcb0
  4c5efc:      	br	x17

00000000004c5f00 <calloc@plt>:
  4c5f00:      	adrp	x16, 0x4e7000
  4c5f04:      	ldr	x17, [x16, #0xcb8]
  4c5f08:      	add	x16, x16, #0xcb8
  4c5f0c:      	br	x17

00000000004c5f10 <__rust_drop_panic@plt>:
  4c5f10:      	adrp	x16, 0x4e7000
  4c5f14:      	ldr	x17, [x16, #0xcc0]
  4c5f18:      	add	x16, x16, #0xcc0
  4c5f1c:      	br	x17

00000000004c5f20 <__rust_foreign_exception@plt>:
  4c5f20:      	adrp	x16, 0x4e7000
  4c5f24:      	ldr	x17, [x16, #0xcc8]
  4c5f28:      	add	x16, x16, #0xcc8
  4c5f2c:      	br	x17

00000000004c5f30 <_ZN3std3sys4unix5locks12futex_rwlock6RwLock15write_contended17h34c36710701e57aaE@plt>:
  4c5f30:      	adrp	x16, 0x4e7000
  4c5f34:      	ldr	x17, [x16, #0xcd0]
  4c5f38:      	add	x16, x16, #0xcd0
  4c5f3c:      	br	x17

00000000004c5f40 <_ZN4core5panic10panic_info9PanicInfo8location17h3ac7e1ca3f506ffcE@plt>:
  4c5f40:      	adrp	x16, 0x4e7000
  4c5f44:      	ldr	x17, [x16, #0xcd8]
  4c5f48:      	add	x16, x16, #0xcd8
  4c5f4c:      	br	x17

00000000004c5f50 <_ZN4core5panic10panic_info9PanicInfo7payload17hb0d74c41f9a24edcE@plt>:
  4c5f50:      	adrp	x16, 0x4e7000
  4c5f54:      	ldr	x17, [x16, #0xce0]
  4c5f58:      	add	x16, x16, #0xce0
  4c5f5c:      	br	x17

00000000004c5f60 <__rust_panic_cleanup@plt>:
  4c5f60:      	adrp	x16, 0x4e7000
  4c5f64:      	ldr	x17, [x16, #0xce8]
  4c5f68:      	add	x16, x16, #0xce8
  4c5f6c:      	br	x17

00000000004c5f70 <rust_begin_unwind@plt>:
  4c5f70:      	adrp	x16, 0x4e7000
  4c5f74:      	ldr	x17, [x16, #0xcf0]
  4c5f78:      	add	x16, x16, #0xcf0
  4c5f7c:      	br	x17

00000000004c5f80 <_ZN4core5panic10panic_info9PanicInfo7message17h39d1e2ab2447e665E@plt>:
  4c5f80:      	adrp	x16, 0x4e7000
  4c5f84:      	ldr	x17, [x16, #0xcf8]
  4c5f88:      	add	x16, x16, #0xcf8
  4c5f8c:      	br	x17

00000000004c5f90 <_ZN4core5panic10panic_info9PanicInfo10can_unwind17hf85cdc39e4dfb7a6E@plt>:
  4c5f90:      	adrp	x16, 0x4e7000
  4c5f94:      	ldr	x17, [x16, #0xd00]
  4c5f98:      	add	x16, x16, #0xd00
  4c5f9c:      	br	x17

00000000004c5fa0 <rust_panic@plt>:
  4c5fa0:      	adrp	x16, 0x4e7000
  4c5fa4:      	ldr	x17, [x16, #0xd08]
  4c5fa8:      	add	x16, x16, #0xd08
  4c5fac:      	br	x17

00000000004c5fb0 <__rust_start_panic@plt>:
  4c5fb0:      	adrp	x16, 0x4e7000
  4c5fb4:      	ldr	x17, [x16, #0xd10]
  4c5fb8:      	add	x16, x16, #0xd10
  4c5fbc:      	br	x17

00000000004c5fc0 <_ZN4core3fmt10ArgumentV110from_usize17hb54f1c93af397a90E@plt>:
  4c5fc0:      	adrp	x16, 0x4e7000
  4c5fc4:      	ldr	x17, [x16, #0xd18]
  4c5fc8:      	add	x16, x16, #0xd18
  4c5fcc:      	br	x17

00000000004c5fd0 <_ZN4core3fmt9Formatter25debug_tuple_field2_finish17h2e5c69eb5125c052E@plt>:
  4c5fd0:      	adrp	x16, 0x4e7000
  4c5fd4:      	ldr	x17, [x16, #0xd20]
  4c5fd8:      	add	x16, x16, #0xd20
  4c5fdc:      	br	x17

00000000004c5fe0 <logf@plt>:
  4c5fe0:      	adrp	x16, 0x4e7000
  4c5fe4:      	ldr	x17, [x16, #0xd28]
  4c5fe8:      	add	x16, x16, #0xd28
  4c5fec:      	br	x17

00000000004c5ff0 <readdir@plt>:
  4c5ff0:      	adrp	x16, 0x4e7000
  4c5ff4:      	ldr	x17, [x16, #0xd30]
  4c5ff8:      	add	x16, x16, #0xd30
  4c5ffc:      	br	x17

00000000004c6000 <_ZN5alloc3ffi5c_str75_$LT$impl$u20$alloc..borrow..ToOwned$u20$for$u20$core..ffi..c_str..CStr$GT$8to_owned17h637e889d0a64ff5bE@plt>:
  4c6000:      	adrp	x16, 0x4e7000
  4c6004:      	ldr	x17, [x16, #0xd38]
  4c6008:      	add	x16, x16, #0xd38
  4c600c:      	br	x17

00000000004c6010 <closedir@plt>:
  4c6010:      	adrp	x16, 0x4e7000
  4c6014:      	ldr	x17, [x16, #0xd40]
  4c6018:      	add	x16, x16, #0xd40
  4c601c:      	br	x17

00000000004c6020 <readlink@plt>:
  4c6020:      	adrp	x16, 0x4e7000
  4c6024:      	ldr	x17, [x16, #0xd48]
  4c6028:      	add	x16, x16, #0xd48
  4c602c:      	br	x17

00000000004c6030 <_ZN3std3sys4unix2fs12canonicalize17h3533f2a2f0e294ffE@plt>:
  4c6030:      	adrp	x16, 0x4e7000
  4c6034:      	ldr	x17, [x16, #0xd50]
  4c6038:      	add	x16, x16, #0xd50
  4c603c:      	br	x17

00000000004c6040 <_ZN3std3sys4unix11kernel_copy18copy_regular_files17h3cbabfdda6a1d360E@plt>:
  4c6040:      	adrp	x16, 0x4e7000
  4c6044:      	ldr	x17, [x16, #0xd58]
  4c6048:      	add	x16, x16, #0xd58
  4c604c:      	br	x17

00000000004c6050 <fchown@plt>:
  4c6050:      	adrp	x16, 0x4e7000
  4c6054:      	ldr	x17, [x16, #0xd60]
  4c6058:      	add	x16, x16, #0xd60
  4c605c:      	br	x17

00000000004c6060 <openat@plt>:
  4c6060:      	adrp	x16, 0x4e7000
  4c6064:      	ldr	x17, [x16, #0xd68]
  4c6068:      	add	x16, x16, #0xd68
  4c606c:      	br	x17

00000000004c6070 <unlinkat@plt>:
  4c6070:      	adrp	x16, 0x4e7000
  4c6074:      	ldr	x17, [x16, #0xd70]
  4c6078:      	add	x16, x16, #0xd70
  4c607c:      	br	x17

00000000004c6080 <fdopendir@plt>:
  4c6080:      	adrp	x16, 0x4e7000
  4c6084:      	ldr	x17, [x16, #0xd78]
  4c6088:      	add	x16, x16, #0xd78
  4c608c:      	br	x17

00000000004c6090 <copy_file_range@plt>:
  4c6090:      	adrp	x16, 0x4e7000
  4c6094:      	ldr	x17, [x16, #0xd80]
  4c6098:      	add	x16, x16, #0xd80
  4c609c:      	br	x17

00000000004c60a0 <splice@plt>:
  4c60a0:      	adrp	x16, 0x4e7000
  4c60a4:      	ldr	x17, [x16, #0xd88]
  4c60a8:      	add	x16, x16, #0xd88
  4c60ac:      	br	x17

00000000004c60b0 <sendfile@plt>:
  4c60b0:      	adrp	x16, 0x4e7000
  4c60b4:      	ldr	x17, [x16, #0xd90]
  4c60b8:      	add	x16, x16, #0xd90
  4c60bc:      	br	x17

00000000004c60c0 <socketpair@plt>:
  4c60c0:      	adrp	x16, 0x4e7000
  4c60c4:      	ldr	x17, [x16, #0xd98]
  4c60c8:      	add	x16, x16, #0xd98
  4c60cc:      	br	x17

00000000004c60d0 <setenv@plt>:
  4c60d0:      	adrp	x16, 0x4e7000
  4c60d4:      	ldr	x17, [x16, #0xda0]
  4c60d8:      	add	x16, x16, #0xda0
  4c60dc:      	br	x17

00000000004c60e0 <unsetenv@plt>:
  4c60e0:      	adrp	x16, 0x4e7000
  4c60e4:      	ldr	x17, [x16, #0xda8]
  4c60e8:      	add	x16, x16, #0xda8
  4c60ec:      	br	x17

00000000004c60f0 <_ZN87_$LT$core..str..lossy..Utf8Chunks$u20$as$u20$core..iter..traits..iterator..Iterator$GT$4next17h588ed195962d6c23E@plt>:
  4c60f0:      	adrp	x16, 0x4e7000
  4c60f4:      	ldr	x17, [x16, #0xdb0]
  4c60f8:      	add	x16, x16, #0xdb0
  4c60fc:      	br	x17

00000000004c6100 <_ZN4core3str5lossy9Utf8Chunk5valid17h2425cde6da434bf6E@plt>:
  4c6100:      	adrp	x16, 0x4e7000
  4c6104:      	ldr	x17, [x16, #0xdb8]
  4c6108:      	add	x16, x16, #0xdb8
  4c610c:      	br	x17

00000000004c6110 <_ZN4core3str5lossy9Utf8Chunk7invalid17hdc339f370f94bb6fE@plt>:
  4c6110:      	adrp	x16, 0x4e7000
  4c6114:      	ldr	x17, [x16, #0xdc0]
  4c6118:      	add	x16, x16, #0xdc0
  4c611c:      	br	x17

00000000004c6120 <_ZN5alloc6string13FromUtf8Error10into_bytes17h01e0d6d1a74db123E@plt>:
  4c6120:      	adrp	x16, 0x4e7000
  4c6124:      	ldr	x17, [x16, #0xdc8]
  4c6128:      	add	x16, x16, #0xdc8
  4c612c:      	br	x17

00000000004c6130 <pipe@plt>:
  4c6130:      	adrp	x16, 0x4e7000
  4c6134:      	ldr	x17, [x16, #0xdd0]
  4c6138:      	add	x16, x16, #0xdd0
  4c613c:      	br	x17

00000000004c6140 <getrandom@plt>:
  4c6140:      	adrp	x16, 0x4e7000
  4c6144:      	ldr	x17, [x16, #0xdd8]
  4c6148:      	add	x16, x16, #0xdd8
  4c614c:      	br	x17

00000000004c6150 <pthread_attr_init@plt>:
  4c6150:      	adrp	x16, 0x4e7000
  4c6154:      	ldr	x17, [x16, #0xde0]
  4c6158:      	add	x16, x16, #0xde0
  4c615c:      	br	x17

00000000004c6160 <pthread_attr_setstacksize@plt>:
  4c6160:      	adrp	x16, 0x4e7000
  4c6164:      	ldr	x17, [x16, #0xde8]
  4c6168:      	add	x16, x16, #0xde8
  4c616c:      	br	x17

00000000004c6170 <pthread_create@plt>:
  4c6170:      	adrp	x16, 0x4e7000
  4c6174:      	ldr	x17, [x16, #0xdf0]
  4c6178:      	add	x16, x16, #0xdf0
  4c617c:      	br	x17

00000000004c6180 <pthread_attr_destroy@plt>:
  4c6180:      	adrp	x16, 0x4e7000
  4c6184:      	ldr	x17, [x16, #0xdf8]
  4c6188:      	add	x16, x16, #0xdf8
  4c618c:      	br	x17

00000000004c6190 <prctl@plt>:
  4c6190:      	adrp	x16, 0x4e7000
  4c6194:      	ldr	x17, [x16, #0xe00]
  4c6198:      	add	x16, x16, #0xe00
  4c619c:      	br	x17

00000000004c61a0 <pthread_join@plt>:
  4c61a0:      	adrp	x16, 0x4e7000
  4c61a4:      	ldr	x17, [x16, #0xe08]
  4c61a8:      	add	x16, x16, #0xe08
  4c61ac:      	br	x17

00000000004c61b0 <pthread_detach@plt>:
  4c61b0:      	adrp	x16, 0x4e7000
  4c61b4:      	ldr	x17, [x16, #0xe10]
  4c61b8:      	add	x16, x16, #0xe10
  4c61bc:      	br	x17

00000000004c61c0 <clock_gettime@plt>:
  4c61c0:      	adrp	x16, 0x4e7000
  4c61c4:      	ldr	x17, [x16, #0xe18]
  4c61c8:      	add	x16, x16, #0xe18
  4c61cc:      	br	x17

00000000004c61d0 <fork@plt>:
  4c61d0:      	adrp	x16, 0x4e7000
  4c61d4:      	ldr	x17, [x16, #0xe20]
  4c61d8:      	add	x16, x16, #0xe20
  4c61dc:      	br	x17

00000000004c61e0 <_exit@plt>:
  4c61e0:      	adrp	x16, 0x4e7000
  4c61e4:      	ldr	x17, [x16, #0xe28]
  4c61e8:      	add	x16, x16, #0xe28
  4c61ec:      	br	x17

00000000004c61f0 <dup2@plt>:
  4c61f0:      	adrp	x16, 0x4e7000
  4c61f4:      	ldr	x17, [x16, #0xe30]
  4c61f8:      	add	x16, x16, #0xe30
  4c61fc:      	br	x17

00000000004c6200 <setgroups@plt>:
  4c6200:      	adrp	x16, 0x4e7000
  4c6204:      	ldr	x17, [x16, #0xe38]
  4c6208:      	add	x16, x16, #0xe38
  4c620c:      	br	x17

00000000004c6210 <setgid@plt>:
  4c6210:      	adrp	x16, 0x4e7000
  4c6214:      	ldr	x17, [x16, #0xe40]
  4c6218:      	add	x16, x16, #0xe40
  4c621c:      	br	x17

00000000004c6220 <getuid@plt>:
  4c6220:      	adrp	x16, 0x4e7000
  4c6224:      	ldr	x17, [x16, #0xe48]
  4c6228:      	add	x16, x16, #0xe48
  4c622c:      	br	x17

00000000004c6230 <setuid@plt>:
  4c6230:      	adrp	x16, 0x4e7000
  4c6234:      	ldr	x17, [x16, #0xe50]
  4c6238:      	add	x16, x16, #0xe50
  4c623c:      	br	x17

00000000004c6240 <setpgid@plt>:
  4c6240:      	adrp	x16, 0x4e7000
  4c6244:      	ldr	x17, [x16, #0xe58]
  4c6248:      	add	x16, x16, #0xe58
  4c624c:      	br	x17

00000000004c6250 <sigaction@plt>:
  4c6250:      	adrp	x16, 0x4e7000
  4c6254:      	ldr	x17, [x16, #0xe60]
  4c6258:      	add	x16, x16, #0xe60
  4c625c:      	br	x17

00000000004c6260 <execvp@plt>:
  4c6260:      	adrp	x16, 0x4e7000
  4c6264:      	ldr	x17, [x16, #0xe68]
  4c6268:      	add	x16, x16, #0xe68
  4c626c:      	br	x17

00000000004c6270 <pthread_key_create@plt>:
  4c6270:      	adrp	x16, 0x4e7000
  4c6274:      	ldr	x17, [x16, #0xe70]
  4c6278:      	add	x16, x16, #0xe70
  4c627c:      	br	x17

00000000004c6280 <pthread_key_delete@plt>:
  4c6280:      	adrp	x16, 0x4e7000
  4c6284:      	ldr	x17, [x16, #0xe78]
  4c6288:      	add	x16, x16, #0xe78
  4c628c:      	br	x17

00000000004c6290 <_ZN4core3num60_$LT$impl$u20$core..str..traits..FromStr$u20$for$u20$u16$GT$8from_str17h1c28bf4a567aa75aE@plt>:
  4c6290:      	adrp	x16, 0x4e7000
  4c6294:      	ldr	x17, [x16, #0xe80]
  4c6298:      	add	x16, x16, #0xe80
  4c629c:      	br	x17

00000000004c62a0 <getaddrinfo@plt>:
  4c62a0:      	adrp	x16, 0x4e7000
  4c62a4:      	ldr	x17, [x16, #0xe88]
  4c62a8:      	add	x16, x16, #0xe88
  4c62ac:      	br	x17

00000000004c62b0 <gai_strerror@plt>:
  4c62b0:      	adrp	x16, 0x4e7000
  4c62b4:      	ldr	x17, [x16, #0xe90]
  4c62b8:      	add	x16, x16, #0xe90
  4c62bc:      	br	x17

00000000004c62c0 <_ZN3std5alloc8rust_oom17h0ac631ca4dd05121E@plt>:
  4c62c0:      	adrp	x16, 0x4e7000
  4c62c4:      	ldr	x17, [x16, #0xe98]
  4c62c8:      	add	x16, x16, #0xe98
  4c62cc:      	br	x17

00000000004c62d0 <_ZN63_$LT$rustc_demangle..Demangle$u20$as$u20$core..fmt..Display$GT$3fmt17he117db2bc6512c0cE@plt>:
  4c62d0:      	adrp	x16, 0x4e7000
  4c62d4:      	ldr	x17, [x16, #0xea0]
  4c62d8:      	add	x16, x16, #0xea0
  4c62dc:      	br	x17

00000000004c62e0 <_ZN61_$LT$rustc_demangle..Demangle$u20$as$u20$core..fmt..Debug$GT$3fmt17h2e598913c7033143E@plt>:
  4c62e0:      	adrp	x16, 0x4e7000
  4c62e4:      	ldr	x17, [x16, #0xea8]
  4c62e8:      	add	x16, x16, #0xea8
  4c62ec:      	br	x17

00000000004c62f0 <mmap@plt>:
  4c62f0:      	adrp	x16, 0x4e7000
  4c62f4:      	ldr	x17, [x16, #0xeb0]
  4c62f8:      	add	x16, x16, #0xeb0
  4c62fc:      	br	x17

00000000004c6300 <_ZN68_$LT$$RF$$u5b$u8$u5d$$u20$as$u20$object..read..read_ref..ReadRef$GT$19read_bytes_at_until17h6377a0bc615911ddE@plt>:
  4c6300:      	adrp	x16, 0x4e7000
  4c6304:      	ldr	x17, [x16, #0xeb8]
  4c6308:      	add	x16, x16, #0xeb8
  4c630c:      	br	x17

00000000004c6310 <_ZN68_$LT$$RF$$u5b$u8$u5d$$u20$as$u20$object..read..read_ref..ReadRef$GT$13read_bytes_at17h26f10df32e11cb9bE@plt>:
  4c6310:      	adrp	x16, 0x4e7000
  4c6314:      	ldr	x17, [x16, #0xec0]
  4c6318:      	add	x16, x16, #0xec0
  4c631c:      	br	x17

00000000004c6320 <_ZN91_$LT$addr2line..LocationRangeUnitIter$u20$as$u20$core..iter..traits..iterator..Iterator$GT$4next17hba85bc82334c52a0E@plt>:
  4c6320:      	adrp	x16, 0x4e7000
  4c6324:      	ldr	x17, [x16, #0xec8]
  4c6328:      	add	x16, x16, #0xec8
  4c632c:      	br	x17

00000000004c6330 <_ZN11miniz_oxide7inflate4core17DecompressorOxide3new17h49afd1da6603e504E@plt>:
  4c6330:      	adrp	x16, 0x4e7000
  4c6334:      	ldr	x17, [x16, #0xed0]
  4c6338:      	add	x16, x16, #0xed0
  4c633c:      	br	x17

00000000004c6340 <_ZN11miniz_oxide7inflate4core10decompress17h3cc8efd3834d1f2bE@plt>:
  4c6340:      	adrp	x16, 0x4e7000
  4c6344:      	ldr	x17, [x16, #0xed8]
  4c6348:      	add	x16, x16, #0xed8
  4c634c:      	br	x17

00000000004c6350 <_ZN64_$LT$core..str..error..Utf8Error$u20$as$u20$core..fmt..Debug$GT$3fmt17hf5e5687a211e8f00E@plt>:
  4c6350:      	adrp	x16, 0x4e7000
  4c6354:      	ldr	x17, [x16, #0xee0]
  4c6358:      	add	x16, x16, #0xee0
  4c635c:      	br	x17

00000000004c6360 <_ZN67_$LT$object..common..RelocationKind$u20$as$u20$core..fmt..Debug$GT$3fmt17h0727831e4b8c13beE@plt>:
  4c6360:      	adrp	x16, 0x4e7000
  4c6364:      	ldr	x17, [x16, #0xee8]
  4c6368:      	add	x16, x16, #0xee8
  4c636c:      	br	x17

00000000004c6370 <_ZN70_$LT$object..pe..ImageOptionalHeader64$u20$as$u20$core..fmt..Debug$GT$3fmt17h02b892d1e3578947E@plt>:
  4c6370:      	adrp	x16, 0x4e7000
  4c6374:      	ldr	x17, [x16, #0xef0]
  4c6378:      	add	x16, x16, #0xef0
  4c637c:      	br	x17

00000000004c6380 <_ZN62_$LT$object..read..util..Bytes$u20$as$u20$core..fmt..Debug$GT$3fmt17h31e22e7d71dfadcdE@plt>:
  4c6380:      	adrp	x16, 0x4e7000
  4c6384:      	ldr	x17, [x16, #0xef8]
  4c6388:      	add	x16, x16, #0xef8
  4c638c:      	br	x17

00000000004c6390 <_ZN71_$LT$object..common..RelocationEncoding$u20$as$u20$core..fmt..Debug$GT$3fmt17h664348cb5d87f4baE@plt>:
  4c6390:      	adrp	x16, 0x4e7000
  4c6394:      	ldr	x17, [x16, #0xf00]
  4c6398:      	add	x16, x16, #0xf00
  4c639c:      	br	x17

00000000004c63a0 <_ZN70_$LT$object..pe..ImageOptionalHeader32$u20$as$u20$core..fmt..Debug$GT$3fmt17haada5d8ef0540b69E@plt>:
  4c63a0:      	adrp	x16, 0x4e7000
  4c63a4:      	ldr	x17, [x16, #0xf08]
  4c63a8:      	add	x16, x16, #0xf08
  4c63ac:      	br	x17

00000000004c63b0 <_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$i8$GT$3fmt17hdd208df63ea22be7E@plt>:
  4c63b0:      	adrp	x16, 0x4e7000
  4c63b4:      	ldr	x17, [x16, #0xf10]
  4c63b8:      	add	x16, x16, #0xf10
  4c63bc:      	br	x17

00000000004c63c0 <_ZN4core3fmt3num52_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$i8$GT$3fmt17h0fcc34ccad3ebe27E@plt>:
  4c63c0:      	adrp	x16, 0x4e7000
  4c63c4:      	ldr	x17, [x16, #0xf18]
  4c63c8:      	add	x16, x16, #0xf18
  4c63cc:      	br	x17

00000000004c63d0 <_ZN4core3fmt3num3imp51_$LT$impl$u20$core..fmt..Display$u20$for$u20$i8$GT$3fmt17h4fdd068831eb734eE@plt>:
  4c63d0:      	adrp	x16, 0x4e7000
  4c63d4:      	ldr	x17, [x16, #0xf20]
  4c63d8:      	add	x16, x16, #0xf20
  4c63dc:      	br	x17

00000000004c63e0 <_ZN6memchr6memchr8fallback6memchr17h16680ccfeaba2a23E@plt>:
  4c63e0:      	adrp	x16, 0x4e7000
  4c63e4:      	ldr	x17, [x16, #0xf28]
  4c63e8:      	add	x16, x16, #0xf28
  4c63ec:      	br	x17

00000000004c63f0 <_ZN6memchr6memchr8fallback7memchr217hec4768c9ca9d7b7bE@plt>:
  4c63f0:      	adrp	x16, 0x4e7000
  4c63f4:      	ldr	x17, [x16, #0xf30]
  4c63f8:      	add	x16, x16, #0xf30
  4c63fc:      	br	x17

00000000004c6400 <_ZN6object4read2pe6export11ExportTable19target_from_address17h9d167dfdbf573205E@plt>:
  4c6400:      	adrp	x16, 0x4e7000
  4c6404:      	ldr	x17, [x16, #0xf38]
  4c6408:      	add	x16, x16, #0xf38
  4c640c:      	br	x17

00000000004c6410 <_ZN61_$LT$gimli..common..SectionId$u20$as$u20$core..fmt..Debug$GT$3fmt17hbc6b5373ccc6a299E@plt>:
  4c6410:      	adrp	x16, 0x4e7000
  4c6414:      	ldr	x17, [x16, #0xf40]
  4c6418:      	add	x16, x16, #0xf40
  4c641c:      	br	x17

00000000004c6420 <_ZN4core3fmt5float50_$LT$impl$u20$core..fmt..Debug$u20$for$u20$f64$GT$3fmt17h5fd5f1fb6dd02716E@plt>:
  4c6420:      	adrp	x16, 0x4e7000
  4c6424:      	ldr	x17, [x16, #0xf48]
  4c6428:      	add	x16, x16, #0xf48
  4c642c:      	br	x17

00000000004c6430 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..LowerHex$u20$for$u20$i16$GT$3fmt17h4baa003fb882e755E@plt>:
  4c6430:      	adrp	x16, 0x4e7000
  4c6434:      	ldr	x17, [x16, #0xf50]
  4c6438:      	add	x16, x16, #0xf50
  4c643c:      	br	x17

00000000004c6440 <_ZN4core3fmt3num53_$LT$impl$u20$core..fmt..UpperHex$u20$for$u20$i16$GT$3fmt17hbaef6f9256a43323E@plt>:
  4c6440:      	adrp	x16, 0x4e7000
  4c6444:      	ldr	x17, [x16, #0xf58]
  4c6448:      	add	x16, x16, #0xf58
  4c644c:      	br	x17

00000000004c6450 <_ZN4core3fmt3num3imp52_$LT$impl$u20$core..fmt..Display$u20$for$u20$i16$GT$3fmt17h43dbd30149a68294E@plt>:
  4c6450:      	adrp	x16, 0x4e7000
  4c6454:      	ldr	x17, [x16, #0xf60]
  4c6458:      	add	x16, x16, #0xf60
  4c645c:      	br	x17

00000000004c6460 <_ZN5gimli9constants5DwCfa13static_string17h0c1d377536a1b540E@plt>:
  4c6460:      	adrp	x16, 0x4e7000
  4c6464:      	ldr	x17, [x16, #0xf68]
  4c6468:      	add	x16, x16, #0xf68
  4c646c:      	br	x17

00000000004c6470 <_ZN5gimli9constants5DwTag13static_string17h158a527ad73d2b45E@plt>:
  4c6470:      	adrp	x16, 0x4e7000
  4c6474:      	ldr	x17, [x16, #0xf70]
  4c6478:      	add	x16, x16, #0xf70
  4c647c:      	br	x17

00000000004c6480 <_ZN5gimli9constants4DwAt13static_string17h2f0ad2b699c3c942E@plt>:
  4c6480:      	adrp	x16, 0x4e7000
  4c6484:      	ldr	x17, [x16, #0xf78]
  4c6488:      	add	x16, x16, #0xf78
  4c648c:      	br	x17

00000000004c6490 <_ZN5gimli9constants6DwForm13static_string17hff55cb7cf4b846d2E@plt>:
  4c6490:      	adrp	x16, 0x4e7000
  4c6494:      	ldr	x17, [x16, #0xf80]
  4c6498:      	add	x16, x16, #0xf80
  4c649c:      	br	x17

00000000004c64a0 <_ZN5gimli9constants5DwAte13static_string17hbf1e2b876367eb8bE@plt>:
  4c64a0:      	adrp	x16, 0x4e7000
  4c64a4:      	ldr	x17, [x16, #0xf88]
  4c64a8:      	add	x16, x16, #0xf88
  4c64ac:      	br	x17

00000000004c64b0 <_ZN5gimli9constants6DwLang13static_string17hb12c73463b6ee100E@plt>:
  4c64b0:      	adrp	x16, 0x4e7000
  4c64b4:      	ldr	x17, [x16, #0xf90]
  4c64b8:      	add	x16, x16, #0xf90
  4c64bc:      	br	x17

00000000004c64c0 <_ZN5gimli9constants4DwCc13static_string17h0eeb17d7706b1091E@plt>:
  4c64c0:      	adrp	x16, 0x4e7000
  4c64c4:      	ldr	x17, [x16, #0xf98]
  4c64c8:      	add	x16, x16, #0xf98
  4c64cc:      	br	x17

00000000004c64d0 <_ZN5gimli9constants4DwOp13static_string17hc0d62206837ac6d8E@plt>:
  4c64d0:      	adrp	x16, 0x4e7000
  4c64d4:      	ldr	x17, [x16, #0xfa0]
  4c64d8:      	add	x16, x16, #0xfa0
  4c64dc:      	br	x17

00000000004c64e0 <_ZN71_$LT$rustc_demangle..legacy..Demangle$u20$as$u20$core..fmt..Display$GT$3fmt17h5a876b53e173df04E@plt>:
  4c64e0:      	adrp	x16, 0x4e7000
  4c64e4:      	ldr	x17, [x16, #0xfa8]
  4c64e8:      	add	x16, x16, #0xfa8
  4c64ec:      	br	x17

00000000004c64f0 <_ZN64_$LT$rustc_demangle..v0..Ident$u20$as$u20$core..fmt..Display$GT$3fmt17h534475810a18f496E@plt>:
  4c64f0:      	adrp	x16, 0x4e7000
  4c64f4:      	ldr	x17, [x16, #0xfb0]
  4c64f8:      	add	x16, x16, #0xfb0
  4c64fc:      	br	x17

00000000004c6500 <_ZN14rustc_demangle8demangle17hdcedba21df9f51c7E@plt>:
  4c6500:      	adrp	x16, 0x4e7000
  4c6504:      	ldr	x17, [x16, #0xfb8]
  4c6508:      	add	x16, x16, #0xfb8
  4c650c:      	br	x17

00000000004c6510 <_ZN4core3str5count23char_count_general_case17hdffc92bf39435cefE@plt>:
  4c6510:      	adrp	x16, 0x4e7000
  4c6514:      	ldr	x17, [x16, #0xfc0]
  4c6518:      	add	x16, x16, #0xfc0
  4c651c:      	br	x17

00000000004c6520 <_ZN4core3str5count14do_count_chars17h707065edef91c3a9E@plt>:
  4c6520:      	adrp	x16, 0x4e7000
  4c6524:      	ldr	x17, [x16, #0xfc8]
  4c6528:      	add	x16, x16, #0xfc8
  4c652c:      	br	x17

00000000004c6530 <_ZN57_$LT$core..fmt..Formatter$u20$as$u20$core..fmt..Write$GT$9write_str17haf32efaf5e69e9cfE@plt>:
  4c6530:      	adrp	x16, 0x4e7000
  4c6534:      	ldr	x17, [x16, #0xfd0]
  4c6538:      	add	x16, x16, #0xfd0
  4c653c:      	br	x17

00000000004c6540 <_ZN4core3num21_$LT$impl$u20$u32$GT$14from_str_radix17hee79f6b306c33e25E@plt>:
  4c6540:      	adrp	x16, 0x4e7000
  4c6544:      	ldr	x17, [x16, #0xfd8]
  4c6548:      	add	x16, x16, #0xfd8
  4c654c:      	br	x17

00000000004c6550 <_ZN4core7unicode12unicode_data2cc6lookup17hb2d43133d5fdb2a5E@plt>:
  4c6550:      	adrp	x16, 0x4e7000
  4c6554:      	ldr	x17, [x16, #0xfe0]
  4c6558:      	add	x16, x16, #0xfe0
  4c655c:      	br	x17

00000000004c6560 <_ZN4core3str6traits23str_index_overflow_fail17hc2b9589d037fbf97E@plt>:
  4c6560:      	adrp	x16, 0x4e7000
  4c6564:      	ldr	x17, [x16, #0xfe8]
  4c6568:      	add	x16, x16, #0xfe8
  4c656c:      	br	x17

00000000004c6570 <_ZN64_$LT$core..alloc..layout..Layout$u20$as$u20$core..fmt..Debug$GT$3fmt17h45d6496c466873f9E@plt>:
  4c6570:      	adrp	x16, 0x4e7000
  4c6574:      	ldr	x17, [x16, #0xff0]
  4c6578:      	add	x16, x16, #0xff0
  4c657c:      	br	x17

00000000004c6580 <_ZN57_$LT$miniz_oxide..MZError$u20$as$u20$core..fmt..Debug$GT$3fmt17h71b0fcf39b987573E@plt>:
  4c6580:      	adrp	x16, 0x4e7000
  4c6584:      	ldr	x17, [x16, #0xff8]
  4c6588:      	add	x16, x16, #0xff8
  4c658c:      	br	x17

00000000004c6590 <_ZN11miniz_oxide7deflate4core15CompressorOxide3new17he8fc7051fc917988E@plt>:
  4c6590:      	adrp	x16, 0x4e8000
  4c6594:      	ldr	x17, [x16]
  4c6598:      	add	x16, x16, #0x0
  4c659c:      	br	x17

00000000004c65a0 <_ZN11miniz_oxide7deflate4core14compress_inner17h999e7d2a0a0d0934E@plt>:
  4c65a0:      	adrp	x16, 0x4e8000
  4c65a4:      	ldr	x17, [x16, #0x8]
  4c65a8:      	add	x16, x16, #0x8
  4c65ac:      	br	x17

00000000004c65b0 <_ZN5adler7Adler3211write_slice17h702eb7fb5f0e1f2dE@plt>:
  4c65b0:      	adrp	x16, 0x4e8000
  4c65b4:      	ldr	x17, [x16, #0x10]
  4c65b8:      	add	x16, x16, #0x10
  4c65bc:      	br	x17

00000000004c65c0 <_ZN59_$LT$core..ffi..c_str..CStr$u20$as$u20$core..fmt..Debug$GT$3fmt17h651ba119fd0edac9E@plt>:
  4c65c0:      	adrp	x16, 0x4e8000
  4c65c4:      	ldr	x17, [x16, #0x18]
  4c65c8:      	add	x16, x16, #0x18
  4c65cc:      	br	x17

00000000004c65d0 <_ZN5alloc5alloc18handle_alloc_error8rt_error17h50363b63a18732a1E@plt>:
  4c65d0:      	adrp	x16, 0x4e8000
  4c65d4:      	ldr	x17, [x16, #0x20]
  4c65d8:      	add	x16, x16, #0x20
  4c65dc:      	br	x17

00000000004c65e0 <_ZN69_$LT$$RF$core..ffi..c_str..CStr$u20$as$u20$core..default..Default$GT$7default17hc38d9cd5781f35b6E@plt>:
  4c65e0:      	adrp	x16, 0x4e8000
  4c65e4:      	ldr	x17, [x16, #0x28]
  4c65e8:      	add	x16, x16, #0x28
  4c65ec:      	br	x17

00000000004c65f0 <_ZN4core7unicode12unicode_data11conversions8to_lower17hab1e4c0bf31f0b29E@plt>:
  4c65f0:      	adrp	x16, 0x4e8000
  4c65f4:      	ldr	x17, [x16, #0x30]
  4c65f8:      	add	x16, x16, #0x30
  4c65fc:      	br	x17

00000000004c6600 <_ZN4core7unicode12unicode_data14case_ignorable6lookup17h918d0cf6701e833aE@plt>:
  4c6600:      	adrp	x16, 0x4e8000
  4c6604:      	ldr	x17, [x16, #0x38]
  4c6608:      	add	x16, x16, #0x38
  4c660c:      	br	x17

00000000004c6610 <_ZN4core7unicode12unicode_data5cased6lookup17hfc43e6de0863b0e5E@plt>:
  4c6610:      	adrp	x16, 0x4e8000
  4c6614:      	ldr	x17, [x16, #0x40]
  4c6618:      	add	x16, x16, #0x40
  4c661c:      	br	x17

00000000004c6620 <_ZN4core7unicode12unicode_data11conversions8to_upper17hefe164f405aecea5E@plt>:
  4c6620:      	adrp	x16, 0x4e8000
  4c6624:      	ldr	x17, [x16, #0x48]
  4c6628:      	add	x16, x16, #0x48
  4c662c:      	br	x17

00000000004c6630 <_ZN66_$LT$core..str..error..Utf8Error$u20$as$u20$core..fmt..Display$GT$3fmt17h3e278f2c363df2f3E@plt>:
  4c6630:      	adrp	x16, 0x4e8000
  4c6634:      	ldr	x17, [x16, #0x50]
  4c6638:      	add	x16, x16, #0x50
  4c663c:      	br	x17

00000000004c6640 <_ZN4core3num7flt2dec8strategy6dragon9mul_pow1017h050373d9d222f313E@plt>:
  4c6640:      	adrp	x16, 0x4e8000
  4c6644:      	ldr	x17, [x16, #0x58]
  4c6648:      	add	x16, x16, #0x58
  4c664c:      	br	x17

00000000004c6650 <_ZN4core3num6bignum8Big32x4010mul_digits17hb6a4f02a21572d64E@plt>:
  4c6650:      	adrp	x16, 0x4e8000
  4c6654:      	ldr	x17, [x16, #0x60]
  4c6658:      	add	x16, x16, #0x60
  4c665c:      	br	x17

00000000004c6660 <_ZN4core3num7flt2dec8strategy6dragon15format_shortest17h327d907e097dba61E@plt>:
  4c6660:      	adrp	x16, 0x4e8000
  4c6664:      	ldr	x17, [x16, #0x68]
  4c6668:      	add	x16, x16, #0x68
  4c666c:      	br	x17

00000000004c6670 <_ZN4core3num6bignum8Big32x408mul_pow217h1a75e0079cf08bd3E@plt>:
  4c6670:      	adrp	x16, 0x4e8000
  4c6674:      	ldr	x17, [x16, #0x70]
  4c6678:      	add	x16, x16, #0x70
  4c667c:      	br	x17

00000000004c6680 <_ZN4core3num7flt2dec8strategy6dragon12format_exact17h32a52201df5bb6a9E@plt>:
  4c6680:      	adrp	x16, 0x4e8000
  4c6684:      	ldr	x17, [x16, #0x78]
  4c6688:      	add	x16, x16, #0x78
  4c668c:      	br	x17

00000000004c6690 <_ZN4core3num7flt2dec8strategy5grisu19format_shortest_opt17h10af15eb115e4669E@plt>:
  4c6690:      	adrp	x16, 0x4e8000
  4c6694:      	ldr	x17, [x16, #0x80]
  4c6698:      	add	x16, x16, #0x80
  4c669c:      	br	x17

00000000004c66a0 <_ZN4core3num7flt2dec8strategy5grisu16format_exact_opt17h3132b67bdd649365E@plt>:
  4c66a0:      	adrp	x16, 0x4e8000
  4c66a4:      	ldr	x17, [x16, #0x88]
  4c66a8:      	add	x16, x16, #0x88
  4c66ac:      	br	x17

00000000004c66b0 <_ZN4core3num7flt2dec17digits_to_dec_str17hd571d043668d16ddE@plt>:
  4c66b0:      	adrp	x16, 0x4e8000
  4c66b4:      	ldr	x17, [x16, #0x90]
  4c66b8:      	add	x16, x16, #0x90
  4c66bc:      	br	x17

00000000004c66c0 <_ZN4core3num7flt2dec17digits_to_exp_str17hecff5f943cb39be4E@plt>:
  4c66c0:      	adrp	x16, 0x4e8000
  4c66c4:      	ldr	x17, [x16, #0x98]
  4c66c8:      	add	x16, x16, #0x98
  4c66cc:      	br	x17

00000000004c66d0 <_ZN4core3num3fmt4Part5write17hd01d560d1272d1b0E@plt>:
  4c66d0:      	adrp	x16, 0x4e8000
  4c66d4:      	ldr	x17, [x16, #0xa0]
  4c66d8:      	add	x16, x16, #0xa0
  4c66dc:      	br	x17

00000000004c66e0 <_ZN64_$LT$core..char..EscapeDefault$u20$as$u20$core..fmt..Display$GT$3fmt17h14ca8e7ff3b60ae1E@plt>:
  4c66e0:      	adrp	x16, 0x4e8000
  4c66e4:      	ldr	x17, [x16, #0xa8]
  4c66e8:      	add	x16, x16, #0xa8
  4c66ec:      	br	x17

00000000004c66f0 <_ZN4core9panicking18panic_str_nounwind17hb85deef6761b0f8cE@plt>:
  4c66f0:      	adrp	x16, 0x4e8000
  4c66f4:      	ldr	x17, [x16, #0xb0]
  4c66f8:      	add	x16, x16, #0xb0
  4c66fc:      	br	x17

00000000004c6700 <_ZN68_$LT$core..fmt..builders..PadAdapter$u20$as$u20$core..fmt..Write$GT$9write_str17h195c9645e7493462E@plt>:
  4c6700:      	adrp	x16, 0x4e8000
  4c6704:      	ldr	x17, [x16, #0xb8]
  4c6708:      	add	x16, x16, #0xb8
  4c670c:      	br	x17

00000000004c6710 <_ZN4core3fmt8builders8DebugMap3key17h9bad380c8d792c66E@plt>:
  4c6710:      	adrp	x16, 0x4e8000
  4c6714:      	ldr	x17, [x16, #0xc0]
  4c6718:      	add	x16, x16, #0xc0
  4c671c:      	br	x17

00000000004c6720 <_ZN4core3fmt8builders8DebugMap5value17hf30794c38fa5bc23E@plt>:
  4c6720:      	adrp	x16, 0x4e8000
  4c6724:      	ldr	x17, [x16, #0xc8]
  4c6728:      	add	x16, x16, #0xc8
  4c672c:      	br	x17

00000000004c6730 <_ZN4core3fmt9Formatter12pad_integral17he2c1829333b339ebE@plt>:
  4c6730:      	adrp	x16, 0x4e8000
  4c6734:      	ldr	x17, [x16, #0xd0]
  4c6738:      	add	x16, x16, #0xd0
  4c673c:      	br	x17

00000000004c6740 <_ZN4core3fmt9Formatter25debug_tuple_field3_finish17h0637a8ecfc608d42E@plt>:
  4c6740:      	adrp	x16, 0x4e8000
  4c6744:      	ldr	x17, [x16, #0xd8]
  4c6748:      	add	x16, x16, #0xd8
  4c674c:      	br	x17

00000000004c6750 <_ZN4core3fmt9Formatter25debug_tuple_field4_finish17h201ae8ead98aaa54E@plt>:
  4c6750:      	adrp	x16, 0x4e8000
  4c6754:      	ldr	x17, [x16, #0xe0]
  4c6758:      	add	x16, x16, #0xe0
  4c675c:      	br	x17

00000000004c6760 <_ZN41_$LT$char$u20$as$u20$core..fmt..Debug$GT$3fmt17hc90d440d9ce0ec4aE@plt>:
  4c6760:      	adrp	x16, 0x4e8000
  4c6764:      	ldr	x17, [x16, #0xe8]
  4c6768:      	add	x16, x16, #0xe8
  4c676c:      	br	x17

00000000004c6770 <_ZN4core5slice5index31slice_start_index_overflow_fail17ha7036f034f03dda6E@plt>:
  4c6770:      	adrp	x16, 0x4e8000
  4c6774:      	ldr	x17, [x16, #0xf0]
  4c6778:      	add	x16, x16, #0xf0
  4c677c:      	br	x17

00000000004c6780 <_ZN59_$LT$core..str..iter..Chars$u20$as$u20$core..fmt..Debug$GT$3fmt17h0fa114063362796aE@plt>:
  4c6780:      	adrp	x16, 0x4e8000
  4c6784:      	ldr	x17, [x16, #0xf8]
  4c6788:      	add	x16, x16, #0xf8
  4c678c:      	br	x17

00000000004c6790 <_ZN4core3str19slice_error_fail_rt17hbd9f5b185979c4e7E@plt>:
  4c6790:      	adrp	x16, 0x4e8000
  4c6794:      	ldr	x17, [x16, #0x100]
  4c6798:      	add	x16, x16, #0x100
  4c679c:      	br	x17

00000000004c67a0 <_ZN60_$LT$core..task..wake..Waker$u20$as$u20$core..fmt..Debug$GT$3fmt17h4f4962af2c477819E@plt>:
  4c67a0:      	adrp	x16, 0x4e8000
  4c67a4:      	ldr	x17, [x16, #0x108]
  4c67a8:      	add	x16, x16, #0x108
  4c67ac:      	br	x17

00000000004c67b0 <_ZN4core3num6bignum5tests6Big8x38mul_pow217h3d8eb774c76aa3bbE@plt>:
  4c67b0:      	adrp	x16, 0x4e8000
  4c67b4:      	ldr	x17, [x16, #0x110]
  4c67b8:      	add	x16, x16, #0x110
  4c67bc:      	br	x17

00000000004c67c0 <_ZN67_$LT$core..char..EscapeDefaultState$u20$as$u20$core..fmt..Debug$GT$3fmt17ha152c7ff5a2834f3E@plt>:
  4c67c0:      	adrp	x16, 0x4e8000
  4c67c4:      	ldr	x17, [x16, #0x118]
  4c67c8:      	add	x16, x16, #0x118
  4c67cc:      	br	x17

00000000004c67d0 <_ZN64_$LT$core..char..CaseMappingIter$u20$as$u20$core..fmt..Debug$GT$3fmt17h7047278cfbc2e10fE@plt>:
  4c67d0:      	adrp	x16, 0x4e8000
  4c67d4:      	ldr	x17, [x16, #0x120]
  4c67d8:      	add	x16, x16, #0x120
  4c67dc:      	br	x17

00000000004c67e0 <_ZN80_$LT$core..ffi..c_str..FromBytesWithNulErrorKind$u20$as$u20$core..fmt..Debug$GT$3fmt17hb03e2e44dd073bfdE@plt>:
  4c67e0:      	adrp	x16, 0x4e8000
  4c67e4:      	ldr	x17, [x16, #0x128]
  4c67e8:      	add	x16, x16, #0x128
  4c67ec:      	br	x17

00000000004c67f0 <_ZN58_$LT$core..ffi..VaListImpl$u20$as$u20$core..fmt..Debug$GT$3fmt17h54aed527d6ff3e02E@plt>:
  4c67f0:      	adrp	x16, 0x4e8000
  4c67f4:      	ldr	x17, [x16, #0x130]
  4c67f8:      	add	x16, x16, #0x130
  4c67fc:      	br	x17

00000000004c6800 <_ZN65_$LT$core..str..iter..CharIndices$u20$as$u20$core..fmt..Debug$GT$3fmt17hc239689fb526f224E@plt>:
  4c6800:      	adrp	x16, 0x4e8000
  4c6804:      	ldr	x17, [x16, #0x138]
  4c6808:      	add	x16, x16, #0x138
  4c680c:      	br	x17

00000000004c6810 <_ZN82_$LT$core..core_arch..arm_shared..neon..uint8x16_t$u20$as$u20$core..fmt..Debug$GT$3fmt17h9323261477df99bdE@plt>:
  4c6810:      	adrp	x16, 0x4e8000
  4c6814:      	ldr	x17, [x16, #0x140]
  4c6818:      	add	x16, x16, #0x140
  4c681c:      	br	x17

00000000004c6820 <_ZN71_$LT$core..str..pattern..TwoWaySearcher$u20$as$u20$core..fmt..Debug$GT$3fmt17h6e8fda3c0e25c735E@plt>:
  4c6820:      	adrp	x16, 0x4e8000
  4c6824:      	ldr	x17, [x16, #0x148]
  4c6828:      	add	x16, x16, #0x148
  4c682c:      	br	x17

00000000004c6830 <_ZN81_$LT$core..core_arch..arm_shared..neon..int8x16_t$u20$as$u20$core..fmt..Debug$GT$3fmt17ha9896ae7342e8311E@plt>:
  4c6830:      	adrp	x16, 0x4e8000
  4c6834:      	ldr	x17, [x16, #0x150]
  4c6838:      	add	x16, x16, #0x150
  4c683c:      	br	x17

00000000004c6840 <_ZN82_$LT$core..core_arch..arm_shared..neon..poly16x8_t$u20$as$u20$core..fmt..Debug$GT$3fmt17h769b7475791ca476E@plt>:
  4c6840:      	adrp	x16, 0x4e8000
  4c6844:      	ldr	x17, [x16, #0x158]
  4c6848:      	add	x16, x16, #0x158
  4c684c:      	br	x17

00000000004c6850 <_ZN82_$LT$core..core_arch..arm_shared..neon..poly8x16_t$u20$as$u20$core..fmt..Debug$GT$3fmt17ha6dd5de55b659e93E@plt>:
  4c6850:      	adrp	x16, 0x4e8000
  4c6854:      	ldr	x17, [x16, #0x160]
  4c6858:      	add	x16, x16, #0x160
  4c685c:      	br	x17

00000000004c6860 <_ZN72_$LT$core..str..pattern..StrSearcherImpl$u20$as$u20$core..fmt..Debug$GT$3fmt17h71ca289556673ebcE@plt>:
  4c6860:      	adrp	x16, 0x4e8000
  4c6864:      	ldr	x17, [x16, #0x168]
  4c6868:      	add	x16, x16, #0x168
  4c686c:      	br	x17

00000000004c6870 <_ZN80_$LT$core..core_arch..arm_shared..neon..int8x8_t$u20$as$u20$core..fmt..Debug$GT$3fmt17he9a5736b57215577E@plt>:
  4c6870:      	adrp	x16, 0x4e8000
  4c6874:      	ldr	x17, [x16, #0x170]
  4c6878:      	add	x16, x16, #0x170
  4c687c:      	br	x17

00000000004c6880 <_ZN82_$LT$core..core_arch..arm_shared..neon..uint16x8_t$u20$as$u20$core..fmt..Debug$GT$3fmt17h81f44f6236899310E@plt>:
  4c6880:      	adrp	x16, 0x4e8000
  4c6884:      	ldr	x17, [x16, #0x178]
  4c6888:      	add	x16, x16, #0x178
  4c688c:      	br	x17

00000000004c6890 <_ZN81_$LT$core..core_arch..arm_shared..neon..int16x8_t$u20$as$u20$core..fmt..Debug$GT$3fmt17h6c2805c7bda3bc20E@plt>:
  4c6890:      	adrp	x16, 0x4e8000
  4c6894:      	ldr	x17, [x16, #0x180]
  4c6898:      	add	x16, x16, #0x180
  4c689c:      	br	x17

00000000004c68a0 <_ZN81_$LT$core..core_arch..arm_shared..neon..poly8x8_t$u20$as$u20$core..fmt..Debug$GT$3fmt17h2748de3dfe6115caE@plt>:
  4c68a0:      	adrp	x16, 0x4e8000
  4c68a4:      	ldr	x17, [x16, #0x188]
  4c68a8:      	add	x16, x16, #0x188
  4c68ac:      	br	x17

00000000004c68b0 <_ZN81_$LT$core..core_arch..arm_shared..neon..uint8x8_t$u20$as$u20$core..fmt..Debug$GT$3fmt17h5202d2e49b5fe841E@plt>:
  4c68b0:      	adrp	x16, 0x4e8000
  4c68b4:      	ldr	x17, [x16, #0x190]
  4c68b8:      	add	x16, x16, #0x190
  4c68bc:      	br	x17

00000000004c68c0 <crc32@plt>:
  4c68c0:      	adrp	x16, 0x4e8000
  4c68c4:      	ldr	x17, [x16, #0x198]
  4c68c8:      	add	x16, x16, #0x198
  4c68cc:      	br	x17

00000000004c68d0 <__memset_chk@plt>:
  4c68d0:      	adrp	x16, 0x4e8000
  4c68d4:      	ldr	x17, [x16, #0x1a0]
  4c68d8:      	add	x16, x16, #0x1a0
  4c68dc:      	br	x17

00000000004c68e0 <inflateReset@plt>:
  4c68e0:      	adrp	x16, 0x4e8000
  4c68e4:      	ldr	x17, [x16, #0x1a8]
  4c68e8:      	add	x16, x16, #0x1a8
  4c68ec:      	br	x17

00000000004c68f0 <adler32@plt>:
  4c68f0:      	adrp	x16, 0x4e8000
  4c68f4:      	ldr	x17, [x16, #0x1b0]
  4c68f8:      	add	x16, x16, #0x1b0
  4c68fc:      	br	x17

00000000004c6900 <inflateInit_@plt>:
  4c6900:      	adrp	x16, 0x4e8000
  4c6904:      	ldr	x17, [x16, #0x1b8]
  4c6908:      	add	x16, x16, #0x1b8
  4c690c:      	br	x17

00000000004c6910 <deflateEnd@plt>:
  4c6910:      	adrp	x16, 0x4e8000
  4c6914:      	ldr	x17, [x16, #0x1c0]
  4c6918:      	add	x16, x16, #0x1c0
  4c691c:      	br	x17

00000000004c6920 <deflate@plt>:
  4c6920:      	adrp	x16, 0x4e8000
  4c6924:      	ldr	x17, [x16, #0x1c8]
  4c6928:      	add	x16, x16, #0x1c8
  4c692c:      	br	x17

00000000004c6930 <deflateReset@plt>:
  4c6930:      	adrp	x16, 0x4e8000
  4c6934:      	ldr	x17, [x16, #0x1d0]
  4c6938:      	add	x16, x16, #0x1d0
  4c693c:      	br	x17

00000000004c6940 <deflateInit2_@plt>:
  4c6940:      	adrp	x16, 0x4e8000
  4c6944:      	ldr	x17, [x16, #0x1d8]
  4c6948:      	add	x16, x16, #0x1d8
  4c694c:      	br	x17

00000000004c6950 <__vsnprintf_chk@plt>:
  4c6950:      	adrp	x16, 0x4e8000
  4c6954:      	ldr	x17, [x16, #0x1e0]
  4c6958:      	add	x16, x16, #0x1e0
  4c695c:      	br	x17

00000000004c6960 <bsearch@plt>:
  4c6960:      	adrp	x16, 0x4e8000
  4c6964:      	ldr	x17, [x16, #0x1e8]
  4c6968:      	add	x16, x16, #0x1e8
  4c696c:      	br	x17

00000000004c6970 <__memmove_chk@plt>:
  4c6970:      	adrp	x16, 0x4e8000
  4c6974:      	ldr	x17, [x16, #0x1f0]
  4c6978:      	add	x16, x16, #0x1f0
  4c697c:      	br	x17

00000000004c6980 <deflateInit_@plt>:
  4c6980:      	adrp	x16, 0x4e8000
  4c6984:      	ldr	x17, [x16, #0x1f8]
  4c6988:      	add	x16, x16, #0x1f8
  4c698c:      	br	x17

00000000004c6990 <deflateParams@plt>:
  4c6990:      	adrp	x16, 0x4e8000
  4c6994:      	ldr	x17, [x16, #0x200]
  4c6998:      	add	x16, x16, #0x200
  4c699c:      	br	x17

00000000004c69a0 <__read_chk@plt>:
  4c69a0:      	adrp	x16, 0x4e8000
  4c69a4:      	ldr	x17, [x16, #0x208]
  4c69a8:      	add	x16, x16, #0x208
  4c69ac:      	br	x17

00000000004c69b0 <lseek@plt>:
  4c69b0:      	adrp	x16, 0x4e8000
  4c69b4:      	ldr	x17, [x16, #0x210]
  4c69b8:      	add	x16, x16, #0x210
  4c69bc:      	br	x17

00000000004c69c0 <WebPInitDecBufferInternal@plt>:
  4c69c0:      	adrp	x16, 0x4e8000
  4c69c4:      	ldr	x17, [x16, #0x218]
  4c69c8:      	add	x16, x16, #0x218
  4c69cc:      	br	x17

00000000004c69d0 <WebPFreeDecBuffer@plt>:
  4c69d0:      	adrp	x16, 0x4e8000
  4c69d4:      	ldr	x17, [x16, #0x220]
  4c69d8:      	add	x16, x16, #0x220
  4c69dc:      	br	x17

00000000004c69e0 <VP8CheckSignature@plt>:
  4c69e0:      	adrp	x16, 0x4e8000
  4c69e4:      	ldr	x17, [x16, #0x228]
  4c69e8:      	add	x16, x16, #0x228
  4c69ec:      	br	x17

00000000004c69f0 <VP8GetInfo@plt>:
  4c69f0:      	adrp	x16, 0x4e8000
  4c69f4:      	ldr	x17, [x16, #0x230]
  4c69f8:      	add	x16, x16, #0x230
  4c69fc:      	br	x17

00000000004c6a00 <VP8LCheckSignature@plt>:
  4c6a00:      	adrp	x16, 0x4e8000
  4c6a04:      	ldr	x17, [x16, #0x238]
  4c6a08:      	add	x16, x16, #0x238
  4c6a0c:      	br	x17

00000000004c6a10 <VP8LGetInfo@plt>:
  4c6a10:      	adrp	x16, 0x4e8000
  4c6a14:      	ldr	x17, [x16, #0x240]
  4c6a18:      	add	x16, x16, #0x240
  4c6a1c:      	br	x17

00000000004c6a20 <WebPGetInfo@plt>:
  4c6a20:      	adrp	x16, 0x4e8000
  4c6a24:      	ldr	x17, [x16, #0x248]
  4c6a28:      	add	x16, x16, #0x248
  4c6a2c:      	br	x17

00000000004c6a30 <WebPDecode@plt>:
  4c6a30:      	adrp	x16, 0x4e8000
  4c6a34:      	ldr	x17, [x16, #0x250]
  4c6a38:      	add	x16, x16, #0x250
  4c6a3c:      	br	x17

00000000004c6a40 <WebPSafeCalloc@plt>:
  4c6a40:      	adrp	x16, 0x4e8000
  4c6a44:      	ldr	x17, [x16, #0x258]
  4c6a48:      	add	x16, x16, #0x258
  4c6a4c:      	br	x17

00000000004c6a50 <WebPGetWorkerInterface@plt>:
  4c6a50:      	adrp	x16, 0x4e8000
  4c6a54:      	ldr	x17, [x16, #0x260]
  4c6a58:      	add	x16, x16, #0x260
  4c6a5c:      	br	x17

00000000004c6a60 <pthread_mutex_lock@plt>:
  4c6a60:      	adrp	x16, 0x4e8000
  4c6a64:      	ldr	x17, [x16, #0x268]
  4c6a68:      	add	x16, x16, #0x268
  4c6a6c:      	br	x17

00000000004c6a70 <pthread_mutex_unlock@plt>:
  4c6a70:      	adrp	x16, 0x4e8000
  4c6a74:      	ldr	x17, [x16, #0x270]
  4c6a78:      	add	x16, x16, #0x270
  4c6a7c:      	br	x17

00000000004c6a80 <WebPSafeFree@plt>:
  4c6a80:      	adrp	x16, 0x4e8000
  4c6a84:      	ldr	x17, [x16, #0x278]
  4c6a88:      	add	x16, x16, #0x278
  4c6a8c:      	br	x17

00000000004c6a90 <WebPSafeMalloc@plt>:
  4c6a90:      	adrp	x16, 0x4e8000
  4c6a94:      	ldr	x17, [x16, #0x280]
  4c6a98:      	add	x16, x16, #0x280
  4c6a9c:      	br	x17

00000000004c6aa0 <WebPCopyPlane@plt>:
  4c6aa0:      	adrp	x16, 0x4e8000
  4c6aa4:      	ldr	x17, [x16, #0x288]
  4c6aa8:      	add	x16, x16, #0x288
  4c6aac:      	br	x17

00000000004c6ab0 <WebPValidateConfig@plt>:
  4c6ab0:      	adrp	x16, 0x4e8000
  4c6ab4:      	ldr	x17, [x16, #0x290]
  4c6ab8:      	add	x16, x16, #0x290
  4c6abc:      	br	x17

00000000004c6ac0 <WebPPictureAlloc@plt>:
  4c6ac0:      	adrp	x16, 0x4e8000
  4c6ac4:      	ldr	x17, [x16, #0x298]
  4c6ac8:      	add	x16, x16, #0x298
  4c6acc:      	br	x17

00000000004c6ad0 <WebPMemoryWriterInit@plt>:
  4c6ad0:      	adrp	x16, 0x4e8000
  4c6ad4:      	ldr	x17, [x16, #0x2a0]
  4c6ad8:      	add	x16, x16, #0x2a0
  4c6adc:      	br	x17

00000000004c6ae0 <WebPMemoryWriterClear@plt>:
  4c6ae0:      	adrp	x16, 0x4e8000
  4c6ae4:      	ldr	x17, [x16, #0x2a8]
  4c6ae8:      	add	x16, x16, #0x2a8
  4c6aec:      	br	x17

00000000004c6af0 <WebPEncode@plt>:
  4c6af0:      	adrp	x16, 0x4e8000
  4c6af4:      	ldr	x17, [x16, #0x2b0]
  4c6af8:      	add	x16, x16, #0x2b0
  4c6afc:      	br	x17

00000000004c6b00 <WebPPictureHasTransparency@plt>:
  4c6b00:      	adrp	x16, 0x4e8000
  4c6b04:      	ldr	x17, [x16, #0x2b8]
  4c6b08:      	add	x16, x16, #0x2b8
  4c6b0c:      	br	x17

00000000004c6b10 <WebPPictureARGBToYUVADithered@plt>:
  4c6b10:      	adrp	x16, 0x4e8000
  4c6b14:      	ldr	x17, [x16, #0x2c0]
  4c6b18:      	add	x16, x16, #0x2c0
  4c6b1c:      	br	x17

00000000004c6b20 <WebPPictureSharpARGBToYUVA@plt>:
  4c6b20:      	adrp	x16, 0x4e8000
  4c6b24:      	ldr	x17, [x16, #0x2c8]
  4c6b28:      	add	x16, x16, #0x2c8
  4c6b2c:      	br	x17

00000000004c6b30 <WebPPictureYUVAToARGB@plt>:
  4c6b30:      	adrp	x16, 0x4e8000
  4c6b34:      	ldr	x17, [x16, #0x2d0]
  4c6b38:      	add	x16, x16, #0x2d0
  4c6b3c:      	br	x17

00000000004c6b40 <SharpYuvInit@plt>:
  4c6b40:      	adrp	x16, 0x4e8000
  4c6b44:      	ldr	x17, [x16, #0x2d8]
  4c6b48:      	add	x16, x16, #0x2d8
  4c6b4c:      	br	x17

00000000004c6b50 <SharpYuvGetConversionMatrix@plt>:
  4c6b50:      	adrp	x16, 0x4e8000
  4c6b54:      	ldr	x17, [x16, #0x2e0]
  4c6b58:      	add	x16, x16, #0x2e0
  4c6b5c:      	br	x17

00000000004c6b60 <SharpYuvConvert@plt>:
  4c6b60:      	adrp	x16, 0x4e8000
  4c6b64:      	ldr	x17, [x16, #0x2e8]
  4c6b68:      	add	x16, x16, #0x2e8
  4c6b6c:      	br	x17

00000000004c6b70 <WebPPictureCopy@plt>:
  4c6b70:      	adrp	x16, 0x4e8000
  4c6b74:      	ldr	x17, [x16, #0x2f0]
  4c6b78:      	add	x16, x16, #0x2f0
  4c6b7c:      	br	x17

00000000004c6b80 <WebPPictureView@plt>:
  4c6b80:      	adrp	x16, 0x4e8000
  4c6b84:      	ldr	x17, [x16, #0x2f8]
  4c6b88:      	add	x16, x16, #0x2f8
  4c6b8c:      	br	x17

00000000004c6b90 <WebPCleanupTransparentArea@plt>:
  4c6b90:      	adrp	x16, 0x4e8000
  4c6b94:      	ldr	x17, [x16, #0x300]
  4c6b98:      	add	x16, x16, #0x300
  4c6b9c:      	br	x17

00000000004c6ba0 <WebPGetColorPalette@plt>:
  4c6ba0:      	adrp	x16, 0x4e8000
  4c6ba4:      	ldr	x17, [x16, #0x308]
  4c6ba8:      	add	x16, x16, #0x308
  4c6bac:      	br	x17

00000000004c6bb0 <pthread_mutex_init@plt>:
  4c6bb0:      	adrp	x16, 0x4e8000
  4c6bb4:      	ldr	x17, [x16, #0x310]
  4c6bb8:      	add	x16, x16, #0x310
  4c6bbc:      	br	x17

00000000004c6bc0 <pthread_cond_init@plt>:
  4c6bc0:      	adrp	x16, 0x4e8000
  4c6bc4:      	ldr	x17, [x16, #0x318]
  4c6bc8:      	add	x16, x16, #0x318
  4c6bcc:      	br	x17

00000000004c6bd0 <pthread_mutex_destroy@plt>:
  4c6bd0:      	adrp	x16, 0x4e8000
  4c6bd4:      	ldr	x17, [x16, #0x320]
  4c6bd8:      	add	x16, x16, #0x320
  4c6bdc:      	br	x17

00000000004c6be0 <pthread_cond_destroy@plt>:
  4c6be0:      	adrp	x16, 0x4e8000
  4c6be4:      	ldr	x17, [x16, #0x328]
  4c6be8:      	add	x16, x16, #0x328
  4c6bec:      	br	x17

00000000004c6bf0 <pthread_cond_wait@plt>:
  4c6bf0:      	adrp	x16, 0x4e8000
  4c6bf4:      	ldr	x17, [x16, #0x330]
  4c6bf8:      	add	x16, x16, #0x330
  4c6bfc:      	br	x17

00000000004c6c00 <pthread_cond_signal@plt>:
  4c6c00:      	adrp	x16, 0x4e8000
  4c6c04:      	ldr	x17, [x16, #0x338]
  4c6c08:      	add	x16, x16, #0x338
  4c6c0c:      	br	x17

00000000004c6c10 <WebPMalloc@plt>:
  4c6c10:      	adrp	x16, 0x4e8000
  4c6c14:      	ldr	x17, [x16, #0x340]
  4c6c18:      	add	x16, x16, #0x340
  4c6c1c:      	br	x17

00000000004c6c20 <WebPCopyPixels@plt>:
  4c6c20:      	adrp	x16, 0x4e8000
  4c6c24:      	ldr	x17, [x16, #0x348]
  4c6c28:      	add	x16, x16, #0x348
  4c6c2c:      	br	x17

00000000004c6c30 <WebPNewInternal@plt>:
  4c6c30:      	adrp	x16, 0x4e8000
  4c6c34:      	ldr	x17, [x16, #0x350]
  4c6c38:      	add	x16, x16, #0x350
  4c6c3c:      	br	x17

00000000004c6c40 <WebPMuxDelete@plt>:
  4c6c40:      	adrp	x16, 0x4e8000
  4c6c44:      	ldr	x17, [x16, #0x358]
  4c6c48:      	add	x16, x16, #0x358
  4c6c4c:      	br	x17

00000000004c6c50 <WebPMuxPushFrame@plt>:
  4c6c50:      	adrp	x16, 0x4e8000
  4c6c54:      	ldr	x17, [x16, #0x360]
  4c6c58:      	add	x16, x16, #0x360
  4c6c5c:      	br	x17

00000000004c6c60 <WebPMuxSetCanvasSize@plt>:
  4c6c60:      	adrp	x16, 0x4e8000
  4c6c64:      	ldr	x17, [x16, #0x368]
  4c6c68:      	add	x16, x16, #0x368
  4c6c6c:      	br	x17

00000000004c6c70 <WebPMuxSetAnimationParams@plt>:
  4c6c70:      	adrp	x16, 0x4e8000
  4c6c74:      	ldr	x17, [x16, #0x370]
  4c6c78:      	add	x16, x16, #0x370
  4c6c7c:      	br	x17

00000000004c6c80 <WebPMuxAssemble@plt>:
  4c6c80:      	adrp	x16, 0x4e8000
  4c6c84:      	ldr	x17, [x16, #0x378]
  4c6c88:      	add	x16, x16, #0x378
  4c6c8c:      	br	x17

00000000004c6c90 <WebPMuxGetFrame@plt>:
  4c6c90:      	adrp	x16, 0x4e8000
  4c6c94:      	ldr	x17, [x16, #0x380]
  4c6c98:      	add	x16, x16, #0x380
  4c6c9c:      	br	x17

00000000004c6ca0 <WebPMuxGetCanvasSize@plt>:
  4c6ca0:      	adrp	x16, 0x4e8000
  4c6ca4:      	ldr	x17, [x16, #0x388]
  4c6ca8:      	add	x16, x16, #0x388
  4c6cac:      	br	x17

00000000004c6cb0 <WebPMuxSetImage@plt>:
  4c6cb0:      	adrp	x16, 0x4e8000
  4c6cb4:      	ldr	x17, [x16, #0x390]
  4c6cb8:      	add	x16, x16, #0x390
  4c6cbc:      	br	x17

00000000004c6cc0 <WebPMuxCreateInternal@plt>:
  4c6cc0:      	adrp	x16, 0x4e8000
  4c6cc4:      	ldr	x17, [x16, #0x398]
  4c6cc8:      	add	x16, x16, #0x398
  4c6ccc:      	br	x17

00000000004c6cd0 <WebPMuxNumChunks@plt>:
  4c6cd0:      	adrp	x16, 0x4e8000
  4c6cd4:      	ldr	x17, [x16, #0x3a0]
  4c6cd8:      	add	x16, x16, #0x3a0
  4c6cdc:      	br	x17

00000000004c6ce0 <WebPMuxGetFeatures@plt>:
  4c6ce0:      	adrp	x16, 0x4e8000
  4c6ce4:      	ldr	x17, [x16, #0x3a8]
  4c6ce8:      	add	x16, x16, #0x3a8
  4c6cec:      	br	x17

00000000004c6cf0 <_ZdaPv@plt>:
  4c6cf0:      	adrp	x16, 0x4e8000
  4c6cf4:      	ldr	x17, [x16, #0x3b0]
  4c6cf8:      	add	x16, x16, #0x3b0
  4c6cfc:      	br	x17

00000000004c6d00 <__dynamic_cast@plt>:
  4c6d00:      	adrp	x16, 0x4e8000
  4c6d04:      	ldr	x17, [x16, #0x3b8]
  4c6d08:      	add	x16, x16, #0x3b8
  4c6d0c:      	br	x17

00000000004c6d10 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  4c6d10:      	adrp	x16, 0x4e8000
  4c6d14:      	ldr	x17, [x16, #0x3c0]
  4c6d18:      	add	x16, x16, #0x3c0
  4c6d1c:      	br	x17

00000000004c6d20 <vsnprintf@plt>:
  4c6d20:      	adrp	x16, 0x4e8000
  4c6d24:      	ldr	x17, [x16, #0x3c8]
  4c6d28:      	add	x16, x16, #0x3c8
  4c6d2c:      	br	x17

00000000004c6d30 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  4c6d30:      	adrp	x16, 0x4e8000
  4c6d34:      	ldr	x17, [x16, #0x3d0]
  4c6d38:      	add	x16, x16, #0x3d0
  4c6d3c:      	br	x17

00000000004c6d40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  4c6d40:      	adrp	x16, 0x4e8000
  4c6d44:      	ldr	x17, [x16, #0x3d8]
  4c6d48:      	add	x16, x16, #0x3d8
  4c6d4c:      	br	x17

00000000004c6d50 <__cxa_guard_acquire@plt>:
  4c6d50:      	adrp	x16, 0x4e8000
  4c6d54:      	ldr	x17, [x16, #0x3e0]
  4c6d58:      	add	x16, x16, #0x3e0
  4c6d5c:      	br	x17

00000000004c6d60 <__cxa_guard_release@plt>:
  4c6d60:      	adrp	x16, 0x4e8000
  4c6d64:      	ldr	x17, [x16, #0x3e8]
  4c6d68:      	add	x16, x16, #0x3e8
  4c6d6c:      	br	x17

00000000004c6d70 <__cxa_guard_abort@plt>:
  4c6d70:      	adrp	x16, 0x4e8000
  4c6d74:      	ldr	x17, [x16, #0x3f0]
  4c6d78:      	add	x16, x16, #0x3f0
  4c6d7c:      	br	x17

00000000004c6d80 <log2f@plt>:
  4c6d80:      	adrp	x16, 0x4e8000
  4c6d84:      	ldr	x17, [x16, #0x3f8]
  4c6d88:      	add	x16, x16, #0x3f8
  4c6d8c:      	br	x17

00000000004c6d90 <exp2f@plt>:
  4c6d90:      	adrp	x16, 0x4e8000
  4c6d94:      	ldr	x17, [x16, #0x400]
  4c6d98:      	add	x16, x16, #0x400
  4c6d9c:      	br	x17

00000000004c6da0 <__cxa_rethrow@plt>:
  4c6da0:      	adrp	x16, 0x4e8000
  4c6da4:      	ldr	x17, [x16, #0x408]
  4c6da8:      	add	x16, x16, #0x408
  4c6dac:      	br	x17

00000000004c6db0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  4c6db0:      	adrp	x16, 0x4e8000
  4c6db4:      	ldr	x17, [x16, #0x410]
  4c6db8:      	add	x16, x16, #0x410
  4c6dbc:      	br	x17

00000000004c6dc0 <__system_property_get@plt>:
  4c6dc0:      	adrp	x16, 0x4e8000
  4c6dc4:      	ldr	x17, [x16, #0x418]
  4c6dc8:      	add	x16, x16, #0x418
  4c6dcc:      	br	x17

00000000004c6dd0 <getauxval@plt>:
  4c6dd0:      	adrp	x16, 0x4e8000
  4c6dd4:      	ldr	x17, [x16, #0x420]
  4c6dd8:      	add	x16, x16, #0x420
  4c6ddc:      	br	x17

00000000004c6de0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  4c6de0:      	adrp	x16, 0x4e8000
  4c6de4:      	ldr	x17, [x16, #0x428]
  4c6de8:      	add	x16, x16, #0x428
  4c6dec:      	br	x17

00000000004c6df0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  4c6df0:      	adrp	x16, 0x4e8000
  4c6df4:      	ldr	x17, [x16, #0x430]
  4c6df8:      	add	x16, x16, #0x430
  4c6dfc:      	br	x17

00000000004c6e00 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm@plt>:
  4c6e00:      	adrp	x16, 0x4e8000
  4c6e04:      	ldr	x17, [x16, #0x438]
  4c6e08:      	add	x16, x16, #0x438
  4c6e0c:      	br	x17

00000000004c6e10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc@plt>:
  4c6e10:      	adrp	x16, 0x4e8000
  4c6e14:      	ldr	x17, [x16, #0x440]
  4c6e18:      	add	x16, x16, #0x440
  4c6e1c:      	br	x17

00000000004c6e20 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
  4c6e20:      	adrp	x16, 0x4e8000
  4c6e24:      	ldr	x17, [x16, #0x448]
  4c6e28:      	add	x16, x16, #0x448
  4c6e2c:      	br	x17

00000000004c6e30 <_ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE@plt>:
  4c6e30:      	adrp	x16, 0x4e8000
  4c6e34:      	ldr	x17, [x16, #0x450]
  4c6e38:      	add	x16, x16, #0x450
  4c6e3c:      	br	x17

00000000004c6e40 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
  4c6e40:      	adrp	x16, 0x4e8000
  4c6e44:      	ldr	x17, [x16, #0x458]
  4c6e48:      	add	x16, x16, #0x458
  4c6e4c:      	br	x17

00000000004c6e50 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
  4c6e50:      	adrp	x16, 0x4e8000
  4c6e54:      	ldr	x17, [x16, #0x460]
  4c6e58:      	add	x16, x16, #0x460
  4c6e5c:      	br	x17

00000000004c6e60 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
  4c6e60:      	adrp	x16, 0x4e8000
  4c6e64:      	ldr	x17, [x16, #0x468]
  4c6e68:      	add	x16, x16, #0x468
  4c6e6c:      	br	x17

00000000004c6e70 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
  4c6e70:      	adrp	x16, 0x4e8000
  4c6e74:      	ldr	x17, [x16, #0x470]
  4c6e78:      	add	x16, x16, #0x470
  4c6e7c:      	br	x17

00000000004c6e80 <_ZNSt6__ndk16thread20hardware_concurrencyEv@plt>:
  4c6e80:      	adrp	x16, 0x4e8000
  4c6e84:      	ldr	x17, [x16, #0x478]
  4c6e88:      	add	x16, x16, #0x478
  4c6e8c:      	br	x17

00000000004c6e90 <_ZNSt6__ndk16threadD1Ev@plt>:
  4c6e90:      	adrp	x16, 0x4e8000
  4c6e94:      	ldr	x17, [x16, #0x480]
  4c6e98:      	add	x16, x16, #0x480
  4c6e9c:      	br	x17

00000000004c6ea0 <_ZNSt6__ndk16thread4joinEv@plt>:
  4c6ea0:      	adrp	x16, 0x4e8000
  4c6ea4:      	ldr	x17, [x16, #0x488]
  4c6ea8:      	add	x16, x16, #0x488
  4c6eac:      	br	x17

00000000004c6eb0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
  4c6eb0:      	adrp	x16, 0x4e8000
  4c6eb4:      	ldr	x17, [x16, #0x490]
  4c6eb8:      	add	x16, x16, #0x490
  4c6ebc:      	br	x17

00000000004c6ec0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
  4c6ec0:      	adrp	x16, 0x4e8000
  4c6ec4:      	ldr	x17, [x16, #0x498]
  4c6ec8:      	add	x16, x16, #0x498
  4c6ecc:      	br	x17

00000000004c6ed0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
  4c6ed0:      	adrp	x16, 0x4e8000
  4c6ed4:      	ldr	x17, [x16, #0x4a0]
  4c6ed8:      	add	x16, x16, #0x4a0
  4c6edc:      	br	x17

00000000004c6ee0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
  4c6ee0:      	adrp	x16, 0x4e8000
  4c6ee4:      	ldr	x17, [x16, #0x4a8]
  4c6ee8:      	add	x16, x16, #0x4a8
  4c6eec:      	br	x17

00000000004c6ef0 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
  4c6ef0:      	adrp	x16, 0x4e8000
  4c6ef4:      	ldr	x17, [x16, #0x4b0]
  4c6ef8:      	add	x16, x16, #0x4b0
  4c6efc:      	br	x17

00000000004c6f00 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
  4c6f00:      	adrp	x16, 0x4e8000
  4c6f04:      	ldr	x17, [x16, #0x4b8]
  4c6f08:      	add	x16, x16, #0x4b8
  4c6f0c:      	br	x17

00000000004c6f10 <_ZnamSt11align_val_t@plt>:
  4c6f10:      	adrp	x16, 0x4e8000
  4c6f14:      	ldr	x17, [x16, #0x4c0]
  4c6f18:      	add	x16, x16, #0x4c0
  4c6f1c:      	br	x17

00000000004c6f20 <_ZdaPvSt11align_val_t@plt>:
  4c6f20:      	adrp	x16, 0x4e8000
  4c6f24:      	ldr	x17, [x16, #0x4c8]
  4c6f28:      	add	x16, x16, #0x4c8
  4c6f2c:      	br	x17

00000000004c6f30 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf@plt>:
  4c6f30:      	adrp	x16, 0x4e8000
  4c6f34:      	ldr	x17, [x16, #0x4d0]
  4c6f38:      	add	x16, x16, #0x4d0
  4c6f3c:      	br	x17

00000000004c6f40 <pthread_rwlock_wrlock@plt>:
  4c6f40:      	adrp	x16, 0x4e8000
  4c6f44:      	ldr	x17, [x16, #0x4d8]
  4c6f48:      	add	x16, x16, #0x4d8
  4c6f4c:      	br	x17

00000000004c6f50 <pthread_rwlock_unlock@plt>:
  4c6f50:      	adrp	x16, 0x4e8000
  4c6f54:      	ldr	x17, [x16, #0x4e0]
  4c6f58:      	add	x16, x16, #0x4e0
  4c6f5c:      	br	x17

00000000004c6f60 <dl_iterate_phdr@plt>:
  4c6f60:      	adrp	x16, 0x4e8000
  4c6f64:      	ldr	x17, [x16, #0x4e8]
  4c6f68:      	add	x16, x16, #0x4e8
  4c6f6c:      	br	x17

00000000004c6f70 <pthread_rwlock_rdlock@plt>:
  4c6f70:      	adrp	x16, 0x4e8000
  4c6f74:      	ldr	x17, [x16, #0x4f0]
  4c6f78:      	add	x16, x16, #0x4f0
  4c6f7c:      	br	x17
