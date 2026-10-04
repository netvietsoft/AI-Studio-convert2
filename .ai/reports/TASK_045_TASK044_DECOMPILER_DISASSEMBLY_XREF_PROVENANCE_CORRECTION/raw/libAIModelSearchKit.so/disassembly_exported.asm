// EXPORTED & PLT DISASSEMBLY FOR libAIModelSearchKit.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libAIModelSearchKit.so (SHA-256: 20233F05B4B010280D16E728103A0995CA2580697B5F9C708FA333E9FF8D1899)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 2117, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libAIModelSearchKit.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000000efd60 <.plt>:
   efd60:      	stp	x16, x30, [sp, #-0x10]!
   efd64:      	adrp	x16, 0xfd000
   efd68:      	ldr	x17, [x16, #0x570]
   efd6c:      	add	x16, x16, #0x570
   efd70:      	br	x17
   efd74:      	nop
   efd78:      	nop
   efd7c:      	nop

00000000000efd80 <__cxa_finalize@plt>:
   efd80:      	adrp	x16, 0xfd000
   efd84:      	ldr	x17, [x16, #0x578]
   efd88:      	add	x16, x16, #0x578
   efd8c:      	br	x17

00000000000efd90 <__cxa_atexit@plt>:
   efd90:      	adrp	x16, 0xfd000
   efd94:      	ldr	x17, [x16, #0x580]
   efd98:      	add	x16, x16, #0x580
   efd9c:      	br	x17

00000000000efda0 <_ZN13aimodelsearch21initializeClassLoaderEP7_JNIEnv@plt>:
   efda0:      	adrp	x16, 0xfd000
   efda4:      	ldr	x17, [x16, #0x588]
   efda8:      	add	x16, x16, #0x588
   efdac:      	br	x17

00000000000efdb0 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz@plt>:
   efdb0:      	adrp	x16, 0xfd000
   efdb4:      	ldr	x17, [x16, #0x590]
   efdb8:      	add	x16, x16, #0x590
   efdbc:      	br	x17

00000000000efdc0 <_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz@plt>:
   efdc0:      	adrp	x16, 0xfd000
   efdc4:      	ldr	x17, [x16, #0x598]
   efdc8:      	add	x16, x16, #0x598
   efdcc:      	br	x17

00000000000efdd0 <__stack_chk_fail@plt>:
   efdd0:      	adrp	x16, 0xfd000
   efdd4:      	ldr	x17, [x16, #0x5a0]
   efdd8:      	add	x16, x16, #0x5a0
   efddc:      	br	x17

00000000000efde0 <_ZN13aimodelsearch27findMTAIMODELSEARCHKITClassEP7_JNIEnvPKc@plt>:
   efde0:      	adrp	x16, 0xfd000
   efde4:      	ldr	x17, [x16, #0x5a8]
   efde8:      	add	x16, x16, #0x5a8
   efdec:      	br	x17

00000000000efdf0 <__cxa_guard_acquire@plt>:
   efdf0:      	adrp	x16, 0xfd000
   efdf4:      	ldr	x17, [x16, #0x5b0]
   efdf8:      	add	x16, x16, #0x5b0
   efdfc:      	br	x17

00000000000efe00 <_ZN13aimodelsearch17ModelKitGlobalRefC2EP7_JavaVMP7_JNIEnv@plt>:
   efe00:      	adrp	x16, 0xfd000
   efe04:      	ldr	x17, [x16, #0x5b8]
   efe08:      	add	x16, x16, #0x5b8
   efe0c:      	br	x17

00000000000efe10 <__cxa_guard_release@plt>:
   efe10:      	adrp	x16, 0xfd000
   efe14:      	ldr	x17, [x16, #0x5c0]
   efe18:      	add	x16, x16, #0x5c0
   efe1c:      	br	x17

00000000000efe20 <__cxa_guard_abort@plt>:
   efe20:      	adrp	x16, 0xfd000
   efe24:      	ldr	x17, [x16, #0x5c8]
   efe28:      	add	x16, x16, #0x5c8
   efe2c:      	br	x17

00000000000efe30 <_ZdlPv@plt>:
   efe30:      	adrp	x16, 0xfd000
   efe34:      	ldr	x17, [x16, #0x5d0]
   efe38:      	add	x16, x16, #0x5d0
   efe3c:      	br	x17

00000000000efe40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   efe40:      	adrp	x16, 0xfd000
   efe44:      	ldr	x17, [x16, #0x5d8]
   efe48:      	add	x16, x16, #0x5d8
   efe4c:      	br	x17

00000000000efe50 <_ZN13aimodelsearch12StringUTFRefD2Ev@plt>:
   efe50:      	adrp	x16, 0xfd000
   efe54:      	ldr	x17, [x16, #0x5e0]
   efe58:      	add	x16, x16, #0x5e0
   efe5c:      	br	x17

00000000000efe60 <_ZN13aimodelsearch28GetAiDispatchModelInfoForKeyERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   efe60:      	adrp	x16, 0xfd000
   efe64:      	ldr	x17, [x16, #0x5e8]
   efe68:      	add	x16, x16, #0x5e8
   efe6c:      	br	x17

00000000000efe70 <__android_log_print@plt>:
   efe70:      	adrp	x16, 0xfd000
   efe74:      	ldr	x17, [x16, #0x5f0]
   efe78:      	add	x16, x16, #0x5f0
   efe7c:      	br	x17

00000000000efe80 <_ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz@plt>:
   efe80:      	adrp	x16, 0xfd000
   efe84:      	ldr	x17, [x16, #0x5f8]
   efe88:      	add	x16, x16, #0x5f8
   efe8c:      	br	x17

00000000000efe90 <strlen@plt>:
   efe90:      	adrp	x16, 0xfd000
   efe94:      	ldr	x17, [x16, #0x600]
   efe98:      	add	x16, x16, #0x600
   efe9c:      	br	x17

00000000000efea0 <_Znwm@plt>:
   efea0:      	adrp	x16, 0xfd000
   efea4:      	ldr	x17, [x16, #0x608]
   efea8:      	add	x16, x16, #0x608
   efeac:      	br	x17

00000000000efeb0 <memmove@plt>:
   efeb0:      	adrp	x16, 0xfd000
   efeb4:      	ldr	x17, [x16, #0x610]
   efeb8:      	add	x16, x16, #0x610
   efebc:      	br	x17

00000000000efec0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJOS7_EEENSJ_IJEEEEEENS_4pairINS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_@plt>:
   efec0:      	adrp	x16, 0xfd000
   efec4:      	ldr	x17, [x16, #0x618]
   efec8:      	add	x16, x16, #0x618
   efecc:      	br	x17

00000000000efed0 <vsnprintf@plt>:
   efed0:      	adrp	x16, 0xfd000
   efed4:      	ldr	x17, [x16, #0x620]
   efed8:      	add	x16, x16, #0x620
   efedc:      	br	x17

00000000000efee0 <_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEPS6_OT_@plt>:
   efee0:      	adrp	x16, 0xfd000
   efee4:      	ldr	x17, [x16, #0x628]
   efee8:      	add	x16, x16, #0x628
   efeec:      	br	x17

00000000000efef0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   efef0:      	adrp	x16, 0xfd000
   efef4:      	ldr	x17, [x16, #0x630]
   efef8:      	add	x16, x16, #0x630
   efefc:      	br	x17

00000000000eff00 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSJ_IJEEEEEENS_4pairINS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_@plt>:
   eff00:      	adrp	x16, 0xfd000
   eff04:      	ldr	x17, [x16, #0x638]
   eff08:      	add	x16, x16, #0x638
   eff0c:      	br	x17

00000000000eff10 <_ZN13aimodelsearch10MerakUtils15convert2JsonStrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   eff10:      	adrp	x16, 0xfd000
   eff14:      	ldr	x17, [x16, #0x640]
   eff18:      	add	x16, x16, #0x640
   eff1c:      	br	x17

00000000000eff20 <__cxa_begin_catch@plt>:
   eff20:      	adrp	x16, 0xfd000
   eff24:      	ldr	x17, [x16, #0x648]
   eff28:      	add	x16, x16, #0x648
   eff2c:      	br	x17

00000000000eff30 <_ZSt9terminatev@plt>:
   eff30:      	adrp	x16, 0xfd000
   eff34:      	ldr	x17, [x16, #0x650]
   eff38:      	add	x16, x16, #0x650
   eff3c:      	br	x17

00000000000eff40 <__cxa_allocate_exception@plt>:
   eff40:      	adrp	x16, 0xfd000
   eff44:      	ldr	x17, [x16, #0x658]
   eff48:      	add	x16, x16, #0x658
   eff4c:      	br	x17

00000000000eff50 <_ZNSt12length_errorD1Ev@plt>:
   eff50:      	adrp	x16, 0xfd000
   eff54:      	ldr	x17, [x16, #0x660]
   eff58:      	add	x16, x16, #0x660
   eff5c:      	br	x17

00000000000eff60 <__cxa_throw@plt>:
   eff60:      	adrp	x16, 0xfd000
   eff64:      	ldr	x17, [x16, #0x668]
   eff68:      	add	x16, x16, #0x668
   eff6c:      	br	x17

00000000000eff70 <__cxa_free_exception@plt>:
   eff70:      	adrp	x16, 0xfd000
   eff74:      	ldr	x17, [x16, #0x670]
   eff78:      	add	x16, x16, #0x670
   eff7c:      	br	x17

00000000000eff80 <_ZNSt11logic_errorC2EPKc@plt>:
   eff80:      	adrp	x16, 0xfd000
   eff84:      	ldr	x17, [x16, #0x678]
   eff88:      	add	x16, x16, #0x678
   eff8c:      	br	x17

00000000000eff90 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   eff90:      	adrp	x16, 0xfd000
   eff94:      	ldr	x17, [x16, #0x680]
   eff98:      	add	x16, x16, #0x680
   eff9c:      	br	x17

00000000000effa0 <_ZNSt20bad_array_new_lengthD1Ev@plt>:
   effa0:      	adrp	x16, 0xfd000
   effa4:      	ldr	x17, [x16, #0x688]
   effa8:      	add	x16, x16, #0x688
   effac:      	br	x17

00000000000effb0 <_ZNSt9exceptionD2Ev@plt>:
   effb0:      	adrp	x16, 0xfd000
   effb4:      	ldr	x17, [x16, #0x690]
   effb8:      	add	x16, x16, #0x690
   effbc:      	br	x17

00000000000effc0 <memcmp@plt>:
   effc0:      	adrp	x16, 0xfd000
   effc4:      	ldr	x17, [x16, #0x698]
   effc8:      	add	x16, x16, #0x698
   effcc:      	br	x17

00000000000effd0 <dlopen@plt>:
   effd0:      	adrp	x16, 0xfd000
   effd4:      	ldr	x17, [x16, #0x6a0]
   effd8:      	add	x16, x16, #0x6a0
   effdc:      	br	x17

00000000000effe0 <dlsym@plt>:
   effe0:      	adrp	x16, 0xfd000
   effe4:      	ldr	x17, [x16, #0x6a8]
   effe8:      	add	x16, x16, #0x6a8
   effec:      	br	x17

00000000000efff0 <dlerror@plt>:
   efff0:      	adrp	x16, 0xfd000
   efff4:      	ldr	x17, [x16, #0x6b0]
   efff8:      	add	x16, x16, #0x6b0
   efffc:      	br	x17

00000000000f0000 <dlclose@plt>:
   f0000:      	adrp	x16, 0xfd000
   f0004:      	ldr	x17, [x16, #0x6b8]
   f0008:      	add	x16, x16, #0x6b8
   f000c:      	br	x17

00000000000f0010 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
   f0010:      	adrp	x16, 0xfd000
   f0014:      	ldr	x17, [x16, #0x6c0]
   f0018:      	add	x16, x16, #0x6c0
   f001c:      	br	x17

00000000000f0020 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
   f0020:      	adrp	x16, 0xfd000
   f0024:      	ldr	x17, [x16, #0x6c8]
   f0028:      	add	x16, x16, #0x6c8
   f002c:      	br	x17

00000000000f0030 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   f0030:      	adrp	x16, 0xfd000
   f0034:      	ldr	x17, [x16, #0x6d0]
   f0038:      	add	x16, x16, #0x6d0
   f003c:      	br	x17

00000000000f0040 <_ZNSt6__ndk16localeD1Ev@plt>:
   f0040:      	adrp	x16, 0xfd000
   f0044:      	ldr	x17, [x16, #0x6d8]
   f0048:      	add	x16, x16, #0x6d8
   f004c:      	br	x17

00000000000f0050 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   f0050:      	adrp	x16, 0xfd000
   f0054:      	ldr	x17, [x16, #0x6e0]
   f0058:      	add	x16, x16, #0x6e0
   f005c:      	br	x17

00000000000f0060 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
   f0060:      	adrp	x16, 0xfd000
   f0064:      	ldr	x17, [x16, #0x6e8]
   f0068:      	add	x16, x16, #0x6e8
   f006c:      	br	x17

00000000000f0070 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
   f0070:      	adrp	x16, 0xfd000
   f0074:      	ldr	x17, [x16, #0x6f0]
   f0078:      	add	x16, x16, #0x6f0
   f007c:      	br	x17

00000000000f0080 <__cxa_end_catch@plt>:
   f0080:      	adrp	x16, 0xfd000
   f0084:      	ldr	x17, [x16, #0x6f8]
   f0088:      	add	x16, x16, #0x6f8
   f008c:      	br	x17

00000000000f0090 <memset@plt>:
   f0090:      	adrp	x16, 0xfd000
   f0094:      	ldr	x17, [x16, #0x700]
   f0098:      	add	x16, x16, #0x700
   f009c:      	br	x17

00000000000f00a0 <fopen@plt>:
   f00a0:      	adrp	x16, 0xfd000
   f00a4:      	ldr	x17, [x16, #0x708]
   f00a8:      	add	x16, x16, #0x708
   f00ac:      	br	x17

00000000000f00b0 <fseek@plt>:
   f00b0:      	adrp	x16, 0xfd000
   f00b4:      	ldr	x17, [x16, #0x710]
   f00b8:      	add	x16, x16, #0x710
   f00bc:      	br	x17

00000000000f00c0 <ftell@plt>:
   f00c0:      	adrp	x16, 0xfd000
   f00c4:      	ldr	x17, [x16, #0x718]
   f00c8:      	add	x16, x16, #0x718
   f00cc:      	br	x17

00000000000f00d0 <_Znam@plt>:
   f00d0:      	adrp	x16, 0xfd000
   f00d4:      	ldr	x17, [x16, #0x720]
   f00d8:      	add	x16, x16, #0x720
   f00dc:      	br	x17

00000000000f00e0 <fread@plt>:
   f00e0:      	adrp	x16, 0xfd000
   f00e4:      	ldr	x17, [x16, #0x728]
   f00e8:      	add	x16, x16, #0x728
   f00ec:      	br	x17

00000000000f00f0 <fclose@plt>:
   f00f0:      	adrp	x16, 0xfd000
   f00f4:      	ldr	x17, [x16, #0x730]
   f00f8:      	add	x16, x16, #0x730
   f00fc:      	br	x17

00000000000f0100 <_ZN13aimodelsearch10MerakUtils15convert2JsonStrEPKci@plt>:
   f0100:      	adrp	x16, 0xfd000
   f0104:      	ldr	x17, [x16, #0x738]
   f0108:      	add	x16, x16, #0x738
   f010c:      	br	x17

00000000000f0110 <_ZdaPv@plt>:
   f0110:      	adrp	x16, 0xfd000
   f0114:      	ldr	x17, [x16, #0x740]
   f0118:      	add	x16, x16, #0x740
   f011c:      	br	x17

00000000000f0120 <_ZN5merak8datatool6RevertEPKcmRNS0_9DtuHeaderE@plt>:
   f0120:      	adrp	x16, 0xfd000
   f0124:      	ldr	x17, [x16, #0x748]
   f0128:      	add	x16, x16, #0x748
   f012c:      	br	x17

00000000000f0130 <_ZN5merak8datatool8MetaUtil7GetMetaERNS0_9DtuHeaderENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEiRPhRi@plt>:
   f0130:      	adrp	x16, 0xfd000
   f0134:      	ldr	x17, [x16, #0x750]
   f0138:      	add	x16, x16, #0x750
   f013c:      	br	x17

00000000000f0140 <_ZN5merak8datatool9DtuHeaderD2Ev@plt>:
   f0140:      	adrp	x16, 0xfd000
   f0144:      	ldr	x17, [x16, #0x758]
   f0148:      	add	x16, x16, #0x758
   f014c:      	br	x17

00000000000f0150 <_ZN5merak8datatool12PacketHeaderD2Ev@plt>:
   f0150:      	adrp	x16, 0xfd000
   f0154:      	ldr	x17, [x16, #0x760]
   f0158:      	add	x16, x16, #0x760
   f015c:      	br	x17

00000000000f0160 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   f0160:      	adrp	x16, 0xfd000
   f0164:      	ldr	x17, [x16, #0x768]
   f0168:      	add	x16, x16, #0x768
   f016c:      	br	x17

00000000000f0170 <_ZN5utils10ColorUtils11fromRGBAStrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPKc@plt>:
   f0170:      	adrp	x16, 0xfd000
   f0174:      	ldr	x17, [x16, #0x770]
   f0178:      	add	x16, x16, #0x770
   f017c:      	br	x17

00000000000f0180 <_ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
   f0180:      	adrp	x16, 0xfd000
   f0184:      	ldr	x17, [x16, #0x778]
   f0188:      	add	x16, x16, #0x778
   f018c:      	br	x17

00000000000f0190 <_ZN5utils8StrUtils9startWithERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_b@plt>:
   f0190:      	adrp	x16, 0xfd000
   f0194:      	ldr	x17, [x16, #0x780]
   f0198:      	add	x16, x16, #0x780
   f019c:      	br	x17

00000000000f01a0 <__strlen_chk@plt>:
   f01a0:      	adrp	x16, 0xfd000
   f01a4:      	ldr	x17, [x16, #0x788]
   f01a8:      	add	x16, x16, #0x788
   f01ac:      	br	x17

00000000000f01b0 <memcpy@plt>:
   f01b0:      	adrp	x16, 0xfd000
   f01b4:      	ldr	x17, [x16, #0x790]
   f01b8:      	add	x16, x16, #0x790
   f01bc:      	br	x17

00000000000f01c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm@plt>:
   f01c0:      	adrp	x16, 0xfd000
   f01c4:      	ldr	x17, [x16, #0x798]
   f01c8:      	add	x16, x16, #0x798
   f01cc:      	br	x17

00000000000f01d0 <_ZN5utils8StrUtils5splitERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEcb@plt>:
   f01d0:      	adrp	x16, 0xfd000
   f01d4:      	ldr	x17, [x16, #0x7a0]
   f01d8:      	add	x16, x16, #0x7a0
   f01dc:      	br	x17

00000000000f01e0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   f01e0:      	adrp	x16, 0xfd000
   f01e4:      	ldr	x17, [x16, #0x7a8]
   f01e8:      	add	x16, x16, #0x7a8
   f01ec:      	br	x17

00000000000f01f0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   f01f0:      	adrp	x16, 0xfd000
   f01f4:      	ldr	x17, [x16, #0x7b0]
   f01f8:      	add	x16, x16, #0x7b0
   f01fc:      	br	x17

00000000000f0200 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   f0200:      	adrp	x16, 0xfd000
   f0204:      	ldr	x17, [x16, #0x7b8]
   f0208:      	add	x16, x16, #0x7b8
   f020c:      	br	x17

00000000000f0210 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
   f0210:      	adrp	x16, 0xfd000
   f0214:      	ldr	x17, [x16, #0x7c0]
   f0218:      	add	x16, x16, #0x7c0
   f021c:      	br	x17

00000000000f0220 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   f0220:      	adrp	x16, 0xfd000
   f0224:      	ldr	x17, [x16, #0x7c8]
   f0228:      	add	x16, x16, #0x7c8
   f022c:      	br	x17

00000000000f0230 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   f0230:      	adrp	x16, 0xfd000
   f0234:      	ldr	x17, [x16, #0x7d0]
   f0238:      	add	x16, x16, #0x7d0
   f023c:      	br	x17

00000000000f0240 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   f0240:      	adrp	x16, 0xfd000
   f0244:      	ldr	x17, [x16, #0x7d8]
   f0248:      	add	x16, x16, #0x7d8
   f024c:      	br	x17

00000000000f0250 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   f0250:      	adrp	x16, 0xfd000
   f0254:      	ldr	x17, [x16, #0x7e0]
   f0258:      	add	x16, x16, #0x7e0
   f025c:      	br	x17

00000000000f0260 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   f0260:      	adrp	x16, 0xfd000
   f0264:      	ldr	x17, [x16, #0x7e8]
   f0268:      	add	x16, x16, #0x7e8
   f026c:      	br	x17

00000000000f0270 <fwrite@plt>:
   f0270:      	adrp	x16, 0xfd000
   f0274:      	ldr	x17, [x16, #0x7f0]
   f0278:      	add	x16, x16, #0x7f0
   f027c:      	br	x17

00000000000f0280 <_ZN5utils9PathUtils7isExistERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f0280:      	adrp	x16, 0xfd000
   f0284:      	ldr	x17, [x16, #0x7f8]
   f0288:      	add	x16, x16, #0x7f8
   f028c:      	br	x17

00000000000f0290 <_ZN5utils9PathUtils10removeFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f0290:      	adrp	x16, 0xfd000
   f0294:      	ldr	x17, [x16, #0x800]
   f0298:      	add	x16, x16, #0x800
   f029c:      	br	x17

00000000000f02a0 <_ZN5utils9PathUtils8moveFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   f02a0:      	adrp	x16, 0xfd000
   f02a4:      	ldr	x17, [x16, #0x808]
   f02a8:      	add	x16, x16, #0x808
   f02ac:      	br	x17

00000000000f02b0 <_ZN5utils9PathUtils7dirPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f02b0:      	adrp	x16, 0xfd000
   f02b4:      	ldr	x17, [x16, #0x810]
   f02b8:      	add	x16, x16, #0x810
   f02bc:      	br	x17

00000000000f02c0 <_ZN5utils8StrUtils4file8fileNameERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEb@plt>:
   f02c0:      	adrp	x16, 0xfd000
   f02c4:      	ldr	x17, [x16, #0x818]
   f02c8:      	add	x16, x16, #0x818
   f02cc:      	br	x17

00000000000f02d0 <_ZN5utils9PathUtils8copyFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   f02d0:      	adrp	x16, 0xfd000
   f02d4:      	ldr	x17, [x16, #0x820]
   f02d8:      	add	x16, x16, #0x820
   f02dc:      	br	x17

00000000000f02e0 <_ZN5utils9PathUtils17checkAndCreateDirERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f02e0:      	adrp	x16, 0xfd000
   f02e4:      	ldr	x17, [x16, #0x828]
   f02e8:      	add	x16, x16, #0x828
   f02ec:      	br	x17

00000000000f02f0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
   f02f0:      	adrp	x16, 0xfd000
   f02f4:      	ldr	x17, [x16, #0x830]
   f02f8:      	add	x16, x16, #0x830
   f02fc:      	br	x17

00000000000f0300 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
   f0300:      	adrp	x16, 0xfd000
   f0304:      	ldr	x17, [x16, #0x838]
   f0308:      	add	x16, x16, #0x838
   f030c:      	br	x17

00000000000f0310 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
   f0310:      	adrp	x16, 0xfd000
   f0314:      	ldr	x17, [x16, #0x840]
   f0318:      	add	x16, x16, #0x840
   f031c:      	br	x17

00000000000f0320 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
   f0320:      	adrp	x16, 0xfd000
   f0324:      	ldr	x17, [x16, #0x848]
   f0328:      	add	x16, x16, #0x848
   f032c:      	br	x17

00000000000f0330 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
   f0330:      	adrp	x16, 0xfd000
   f0334:      	ldr	x17, [x16, #0x850]
   f0338:      	add	x16, x16, #0x850
   f033c:      	br	x17

00000000000f0340 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
   f0340:      	adrp	x16, 0xfd000
   f0344:      	ldr	x17, [x16, #0x858]
   f0348:      	add	x16, x16, #0x858
   f034c:      	br	x17

00000000000f0350 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
   f0350:      	adrp	x16, 0xfd000
   f0354:      	ldr	x17, [x16, #0x860]
   f0358:      	add	x16, x16, #0x860
   f035c:      	br	x17

00000000000f0360 <_ZN5utils4File12writeRawDataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   f0360:      	adrp	x16, 0xfd000
   f0364:      	ldr	x17, [x16, #0x868]
   f0368:      	add	x16, x16, #0x868
   f036c:      	br	x17

00000000000f0370 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl@plt>:
   f0370:      	adrp	x16, 0xfd000
   f0374:      	ldr	x17, [x16, #0x870]
   f0378:      	add	x16, x16, #0x870
   f037c:      	br	x17

00000000000f0380 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   f0380:      	adrp	x16, 0xfd000
   f0384:      	ldr	x17, [x16, #0x878]
   f0388:      	add	x16, x16, #0x878
   f038c:      	br	x17

00000000000f0390 <readlink@plt>:
   f0390:      	adrp	x16, 0xfd000
   f0394:      	ldr	x17, [x16, #0x880]
   f0398:      	add	x16, x16, #0x880
   f039c:      	br	x17

00000000000f03a0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
   f03a0:      	adrp	x16, 0xfd000
   f03a4:      	ldr	x17, [x16, #0x888]
   f03a8:      	add	x16, x16, #0x888
   f03ac:      	br	x17

00000000000f03b0 <access@plt>:
   f03b0:      	adrp	x16, 0xfd000
   f03b4:      	ldr	x17, [x16, #0x890]
   f03b8:      	add	x16, x16, #0x890
   f03bc:      	br	x17

00000000000f03c0 <mkdir@plt>:
   f03c0:      	adrp	x16, 0xfd000
   f03c4:      	ldr	x17, [x16, #0x898]
   f03c8:      	add	x16, x16, #0x898
   f03cc:      	br	x17

00000000000f03d0 <unlink@plt>:
   f03d0:      	adrp	x16, 0xfd000
   f03d4:      	ldr	x17, [x16, #0x8a0]
   f03d8:      	add	x16, x16, #0x8a0
   f03dc:      	br	x17

00000000000f03e0 <opendir@plt>:
   f03e0:      	adrp	x16, 0xfd000
   f03e4:      	ldr	x17, [x16, #0x8a8]
   f03e8:      	add	x16, x16, #0x8a8
   f03ec:      	br	x17

00000000000f03f0 <readdir@plt>:
   f03f0:      	adrp	x16, 0xfd000
   f03f4:      	ldr	x17, [x16, #0x8b0]
   f03f8:      	add	x16, x16, #0x8b0
   f03fc:      	br	x17

00000000000f0400 <strcmp@plt>:
   f0400:      	adrp	x16, 0xfd000
   f0404:      	ldr	x17, [x16, #0x8b8]
   f0408:      	add	x16, x16, #0x8b8
   f040c:      	br	x17

00000000000f0410 <closedir@plt>:
   f0410:      	adrp	x16, 0xfd000
   f0414:      	ldr	x17, [x16, #0x8c0]
   f0418:      	add	x16, x16, #0x8c0
   f041c:      	br	x17

00000000000f0420 <_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIRKS6_EEPS6_OT_@plt>:
   f0420:      	adrp	x16, 0xfd000
   f0424:      	ldr	x17, [x16, #0x8c8]
   f0428:      	add	x16, x16, #0x8c8
   f042c:      	br	x17

00000000000f0430 <rename@plt>:
   f0430:      	adrp	x16, 0xfd000
   f0434:      	ldr	x17, [x16, #0x8d0]
   f0438:      	add	x16, x16, #0x8d0
   f043c:      	br	x17

00000000000f0440 <_ZN5utils8StrUtils4file6suffixERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEb@plt>:
   f0440:      	adrp	x16, 0xfd000
   f0444:      	ldr	x17, [x16, #0x8d8]
   f0448:      	add	x16, x16, #0x8d8
   f044c:      	br	x17

00000000000f0450 <_ZN5utils8StrUtils4file7dirPathERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0450:      	adrp	x16, 0xfd000
   f0454:      	ldr	x17, [x16, #0x8e0]
   f0458:      	add	x16, x16, #0x8e0
   f045c:      	br	x17

00000000000f0460 <_ZN5utils8StrUtils13wcharToStringEPKw@plt>:
   f0460:      	adrp	x16, 0xfd000
   f0464:      	ldr	x17, [x16, #0x8e8]
   f0468:      	add	x16, x16, #0x8e8
   f046c:      	br	x17

00000000000f0470 <wcstombs@plt>:
   f0470:      	adrp	x16, 0xfd000
   f0474:      	ldr	x17, [x16, #0x8f0]
   f0478:      	add	x16, x16, #0x8f0
   f047c:      	br	x17

00000000000f0480 <_ZN5utils8StrUtils15stringToWstringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f0480:      	adrp	x16, 0xfd000
   f0484:      	ldr	x17, [x16, #0x8f8]
   f0488:      	add	x16, x16, #0x8f8
   f048c:      	br	x17

00000000000f0490 <mbstowcs@plt>:
   f0490:      	adrp	x16, 0xfd000
   f0494:      	ldr	x17, [x16, #0x900]
   f0498:      	add	x16, x16, #0x900
   f049c:      	br	x17

00000000000f04a0 <__vsnprintf_chk@plt>:
   f04a0:      	adrp	x16, 0xfd000
   f04a4:      	ldr	x17, [x16, #0x908]
   f04a8:      	add	x16, x16, #0x908
   f04ac:      	br	x17

00000000000f04b0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
   f04b0:      	adrp	x16, 0xfd000
   f04b4:      	ldr	x17, [x16, #0x910]
   f04b8:      	add	x16, x16, #0x910
   f04bc:      	br	x17

00000000000f04c0 <_ZNSt12out_of_rangeD1Ev@plt>:
   f04c0:      	adrp	x16, 0xfd000
   f04c4:      	ldr	x17, [x16, #0x918]
   f04c8:      	add	x16, x16, #0x918
   f04cc:      	br	x17

00000000000f04d0 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
   f04d0:      	adrp	x16, 0xfd000
   f04d4:      	ldr	x17, [x16, #0x920]
   f04d8:      	add	x16, x16, #0x920
   f04dc:      	br	x17

00000000000f04e0 <_ZN5utils8TimeCostC1Ev@plt>:
   f04e0:      	adrp	x16, 0xfd000
   f04e4:      	ldr	x17, [x16, #0x928]
   f04e8:      	add	x16, x16, #0x928
   f04ec:      	br	x17

00000000000f04f0 <_ZN5utils8TimeCostD1Ev@plt>:
   f04f0:      	adrp	x16, 0xfd000
   f04f4:      	ldr	x17, [x16, #0x930]
   f04f8:      	add	x16, x16, #0x930
   f04fc:      	br	x17

00000000000f0500 <_ZNK5utils11LogTimeCost3logEPKcz@plt>:
   f0500:      	adrp	x16, 0xfd000
   f0504:      	ldr	x17, [x16, #0x938]
   f0508:      	add	x16, x16, #0x938
   f050c:      	br	x17

00000000000f0510 <_ZN5merak8datatool12OperatorBindEv@plt>:
   f0510:      	adrp	x16, 0xfd000
   f0514:      	ldr	x17, [x16, #0x940]
   f0518:      	add	x16, x16, #0x940
   f051c:      	br	x17

00000000000f0520 <_ZN5merak8datatool20TypeOperatorRegisterINS0_21TypeOperatorAllocatorINS0_11OperatorXorEEEEC2ENSt6__ndk112basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f0520:      	adrp	x16, 0xfd000
   f0524:      	ldr	x17, [x16, #0x948]
   f0528:      	add	x16, x16, #0x948
   f052c:      	br	x17

00000000000f0530 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_10shared_ptrIN5merak8datatool17OperatorAllocatorEEEEENS_19__map_value_compareIS7_SD_NS_4lessIS7_EELb1EEENS5_ISD_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSO_IJEEEEEENS_4pairINS_15__tree_iteratorISD_PNS_11__tree_nodeISD_PvEElEEbEERKT_DpOT0_@plt>:
   f0530:      	adrp	x16, 0xfd000
   f0534:      	ldr	x17, [x16, #0x950]
   f0538:      	add	x16, x16, #0x950
   f053c:      	br	x17

00000000000f0540 <_ZN5merak8datatool23GetOperatorAllocatorMapEv@plt>:
   f0540:      	adrp	x16, 0xfd000
   f0544:      	ldr	x17, [x16, #0x958]
   f0548:      	add	x16, x16, #0x958
   f054c:      	br	x17

00000000000f0550 <_ZN5merak8datatool15OperatorFactory14CreateOperatorEPNS0_12OperatorInfoE@plt>:
   f0550:      	adrp	x16, 0xfd000
   f0554:      	ldr	x17, [x16, #0x960]
   f0558:      	add	x16, x16, #0x960
   f055c:      	br	x17

00000000000f0560 <_ZNSt6__ndk110shared_ptrIhE5resetB8ne180000IhNS_14default_deleteIA_hEEvEEvPT_T0_@plt>:
   f0560:      	adrp	x16, 0xfd000
   f0564:      	ldr	x17, [x16, #0x968]
   f0568:      	add	x16, x16, #0x968
   f056c:      	br	x17

00000000000f0570 <_ZN5merak8datatool6BufferC1EPhj@plt>:
   f0570:      	adrp	x16, 0xfd000
   f0574:      	ldr	x17, [x16, #0x970]
   f0578:      	add	x16, x16, #0x970
   f057c:      	br	x17

00000000000f0580 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_6vectorIPN5merak8datatool12PacketHeaderENS5_ISC_EEEEEENS_19__map_value_compareIS7_SF_NS_4lessIS7_EELb1EEENS5_ISF_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSQ_IJEEEEEENS_4pairINS_15__tree_iteratorISF_PNS_11__tree_nodeISF_PvEElEEbEERKT_DpOT0_@plt>:
   f0580:      	adrp	x16, 0xfd000
   f0584:      	ldr	x17, [x16, #0x978]
   f0588:      	add	x16, x16, #0x978
   f058c:      	br	x17

00000000000f0590 <_ZNSt6__ndk16vectorINS_10unique_ptrIN5merak8datatool12PacketHeaderENS_14default_deleteIS4_EEEENS_9allocatorIS7_EEE21__push_back_slow_pathIS7_EEPS7_OT_@plt>:
   f0590:      	adrp	x16, 0xfd000
   f0594:      	ldr	x17, [x16, #0x980]
   f0598:      	add	x16, x16, #0x980
   f059c:      	br	x17

00000000000f05a0 <__cxa_rethrow@plt>:
   f05a0:      	adrp	x16, 0xfd000
   f05a4:      	ldr	x17, [x16, #0x988]
   f05a8:      	add	x16, x16, #0x988
   f05ac:      	br	x17

00000000000f05b0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   f05b0:      	adrp	x16, 0xfd000
   f05b4:      	ldr	x17, [x16, #0x990]
   f05b8:      	add	x16, x16, #0x990
   f05bc:      	br	x17

00000000000f05c0 <_ZNSt6__ndk111__call_onceERVmPvPFvS2_E@plt>:
   f05c0:      	adrp	x16, 0xfd000
   f05c4:      	ldr	x17, [x16, #0x998]
   f05c8:      	add	x16, x16, #0x998
   f05cc:      	br	x17

00000000000f05d0 <fprintf@plt>:
   f05d0:      	adrp	x16, 0xfd000
   f05d4:      	ldr	x17, [x16, #0x9a0]
   f05d8:      	add	x16, x16, #0x9a0
   f05dc:      	br	x17

00000000000f05e0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   f05e0:      	adrp	x16, 0xfd000
   f05e4:      	ldr	x17, [x16, #0x9a8]
   f05e8:      	add	x16, x16, #0x9a8
   f05ec:      	br	x17

00000000000f05f0 <pthread_mutex_lock@plt>:
   f05f0:      	adrp	x16, 0xfd000
   f05f4:      	ldr	x17, [x16, #0x9b0]
   f05f8:      	add	x16, x16, #0x9b0
   f05fc:      	br	x17

00000000000f0600 <pthread_cond_wait@plt>:
   f0600:      	adrp	x16, 0xfd000
   f0604:      	ldr	x17, [x16, #0x9b8]
   f0608:      	add	x16, x16, #0x9b8
   f060c:      	br	x17

00000000000f0610 <pthread_mutex_unlock@plt>:
   f0610:      	adrp	x16, 0xfd000
   f0614:      	ldr	x17, [x16, #0x9c0]
   f0618:      	add	x16, x16, #0x9c0
   f061c:      	br	x17

00000000000f0620 <pthread_cond_broadcast@plt>:
   f0620:      	adrp	x16, 0xfd000
   f0624:      	ldr	x17, [x16, #0x9c8]
   f0628:      	add	x16, x16, #0x9c8
   f062c:      	br	x17

00000000000f0630 <clock_gettime@plt>:
   f0630:      	adrp	x16, 0xfd000
   f0634:      	ldr	x17, [x16, #0x9d0]
   f0638:      	add	x16, x16, #0x9d0
   f063c:      	br	x17

00000000000f0640 <__errno@plt>:
   f0640:      	adrp	x16, 0xfd000
   f0644:      	ldr	x17, [x16, #0x9d8]
   f0648:      	add	x16, x16, #0x9d8
   f064c:      	br	x17

00000000000f0650 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
   f0650:      	adrp	x16, 0xfd000
   f0654:      	ldr	x17, [x16, #0x9e0]
   f0658:      	add	x16, x16, #0x9e0
   f065c:      	br	x17

00000000000f0660 <_ZNSt6__ndk114error_categoryD2Ev@plt>:
   f0660:      	adrp	x16, 0xfd000
   f0664:      	ldr	x17, [x16, #0x9e8]
   f0668:      	add	x16, x16, #0x9e8
   f066c:      	br	x17

00000000000f0670 <_ZSt18uncaught_exceptionv@plt>:
   f0670:      	adrp	x16, 0xfd000
   f0674:      	ldr	x17, [x16, #0x9f0]
   f0678:      	add	x16, x16, #0x9f0
   f067c:      	br	x17

00000000000f0680 <_ZNSt13exception_ptrD1Ev@plt>:
   f0680:      	adrp	x16, 0xfd000
   f0684:      	ldr	x17, [x16, #0x9f8]
   f0688:      	add	x16, x16, #0x9f8
   f068c:      	br	x17

00000000000f0690 <_ZNSt16nested_exceptionD1Ev@plt>:
   f0690:      	adrp	x16, 0xfd000
   f0694:      	ldr	x17, [x16, #0xa00]
   f0698:      	add	x16, x16, #0xa00
   f069c:      	br	x17

00000000000f06a0 <_ZNSt13exception_ptrC1ERKS_@plt>:
   f06a0:      	adrp	x16, 0xfd000
   f06a4:      	ldr	x17, [x16, #0xa08]
   f06a8:      	add	x16, x16, #0xa08
   f06ac:      	br	x17

00000000000f06b0 <_ZSt17rethrow_exceptionSt13exception_ptr@plt>:
   f06b0:      	adrp	x16, 0xfd000
   f06b4:      	ldr	x17, [x16, #0xa10]
   f06b8:      	add	x16, x16, #0xa10
   f06bc:      	br	x17

00000000000f06c0 <_ZNSt6__ndk112bad_weak_ptrD1Ev@plt>:
   f06c0:      	adrp	x16, 0xfd000
   f06c4:      	ldr	x17, [x16, #0xa18]
   f06c8:      	add	x16, x16, #0xa18
   f06cc:      	br	x17

00000000000f06d0 <_ZNSt6__ndk114__shared_countD2Ev@plt>:
   f06d0:      	adrp	x16, 0xfd000
   f06d4:      	ldr	x17, [x16, #0xa20]
   f06d8:      	add	x16, x16, #0xa20
   f06dc:      	br	x17

00000000000f06e0 <_ZSt17__throw_bad_allocv@plt>:
   f06e0:      	adrp	x16, 0xfd000
   f06e4:      	ldr	x17, [x16, #0xa28]
   f06e8:      	add	x16, x16, #0xa28
   f06ec:      	br	x17

00000000000f06f0 <_ZNSt13runtime_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   f06f0:      	adrp	x16, 0xfd000
   f06f4:      	ldr	x17, [x16, #0xa30]
   f06f8:      	add	x16, x16, #0xa30
   f06fc:      	br	x17

00000000000f0700 <_ZNSt6__ndk121__throw_runtime_errorEPKc@plt>:
   f0700:      	adrp	x16, 0xfd000
   f0704:      	ldr	x17, [x16, #0xa38]
   f0708:      	add	x16, x16, #0xa38
   f070c:      	br	x17

00000000000f0710 <_ZNSt13runtime_errorC1EPKc@plt>:
   f0710:      	adrp	x16, 0xfd000
   f0714:      	ldr	x17, [x16, #0xa40]
   f0718:      	add	x16, x16, #0xa40
   f071c:      	br	x17

00000000000f0720 <_ZNSt13runtime_errorD1Ev@plt>:
   f0720:      	adrp	x16, 0xfd000
   f0724:      	ldr	x17, [x16, #0xa48]
   f0728:      	add	x16, x16, #0xa48
   f072c:      	br	x17

00000000000f0730 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
   f0730:      	adrp	x16, 0xfd000
   f0734:      	ldr	x17, [x16, #0xa50]
   f0738:      	add	x16, x16, #0xa50
   f073c:      	br	x17

00000000000f0740 <memchr@plt>:
   f0740:      	adrp	x16, 0xfd000
   f0744:      	ldr	x17, [x16, #0xa58]
   f0748:      	add	x16, x16, #0xa58
   f074c:      	br	x17

00000000000f0750 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmmc@plt>:
   f0750:      	adrp	x16, 0xfd000
   f0754:      	ldr	x17, [x16, #0xa60]
   f0758:      	add	x16, x16, #0xa60
   f075c:      	br	x17

00000000000f0760 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
   f0760:      	adrp	x16, 0xfd000
   f0764:      	ldr	x17, [x16, #0xa68]
   f0768:      	add	x16, x16, #0xa68
   f076c:      	br	x17

00000000000f0770 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
   f0770:      	adrp	x16, 0xfd000
   f0774:      	ldr	x17, [x16, #0xa70]
   f0778:      	add	x16, x16, #0xa70
   f077c:      	br	x17

00000000000f0780 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc@plt>:
   f0780:      	adrp	x16, 0xfd000
   f0784:      	ldr	x17, [x16, #0xa78]
   f0788:      	add	x16, x16, #0xa78
   f078c:      	br	x17

00000000000f0790 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmPKwm@plt>:
   f0790:      	adrp	x16, 0xfd000
   f0794:      	ldr	x17, [x16, #0xa80]
   f0798:      	add	x16, x16, #0xa80
   f079c:      	br	x17

00000000000f07a0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE21__grow_by_and_replaceEmmmmmmPKw@plt>:
   f07a0:      	adrp	x16, 0xfd000
   f07a4:      	ldr	x17, [x16, #0xa88]
   f07a8:      	add	x16, x16, #0xa88
   f07ac:      	br	x17

00000000000f07b0 <wcslen@plt>:
   f07b0:      	adrp	x16, 0xfd000
   f07b4:      	ldr	x17, [x16, #0xa90]
   f07b8:      	add	x16, x16, #0xa90
   f07bc:      	br	x17

00000000000f07c0 <wmemchr@plt>:
   f07c0:      	adrp	x16, 0xfd000
   f07c4:      	ldr	x17, [x16, #0xa98]
   f07c8:      	add	x16, x16, #0xa98
   f07cc:      	br	x17

00000000000f07d0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmmw@plt>:
   f07d0:      	adrp	x16, 0xfd000
   f07d4:      	ldr	x17, [x16, #0xaa0]
   f07d8:      	add	x16, x16, #0xaa0
   f07dc:      	br	x17

00000000000f07e0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmPKwm@plt>:
   f07e0:      	adrp	x16, 0xfd000
   f07e4:      	ldr	x17, [x16, #0xaa8]
   f07e8:      	add	x16, x16, #0xaa8
   f07ec:      	br	x17

00000000000f07f0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE9push_backEw@plt>:
   f07f0:      	adrp	x16, 0xfd000
   f07f4:      	ldr	x17, [x16, #0xab0]
   f07f8:      	add	x16, x16, #0xab0
   f07fc:      	br	x17

00000000000f0800 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEmw@plt>:
   f0800:      	adrp	x16, 0xfd000
   f0804:      	ldr	x17, [x16, #0xab8]
   f0808:      	add	x16, x16, #0xab8
   f080c:      	br	x17

00000000000f0810 <wmemcmp@plt>:
   f0810:      	adrp	x16, 0xfd000
   f0814:      	ldr	x17, [x16, #0xac0]
   f0818:      	add	x16, x16, #0xac0
   f081c:      	br	x17

00000000000f0820 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
   f0820:      	adrp	x16, 0xfd000
   f0824:      	ldr	x17, [x16, #0xac8]
   f0828:      	add	x16, x16, #0xac8
   f082c:      	br	x17

00000000000f0830 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   f0830:      	adrp	x16, 0xfd000
   f0834:      	ldr	x17, [x16, #0xad0]
   f0838:      	add	x16, x16, #0xad0
   f083c:      	br	x17

00000000000f0840 <strtoul@plt>:
   f0840:      	adrp	x16, 0xfd000
   f0844:      	ldr	x17, [x16, #0xad8]
   f0848:      	add	x16, x16, #0xad8
   f084c:      	br	x17

00000000000f0850 <strtoll@plt>:
   f0850:      	adrp	x16, 0xfd000
   f0854:      	ldr	x17, [x16, #0xae0]
   f0858:      	add	x16, x16, #0xae0
   f085c:      	br	x17

00000000000f0860 <strtoull@plt>:
   f0860:      	adrp	x16, 0xfd000
   f0864:      	ldr	x17, [x16, #0xae8]
   f0868:      	add	x16, x16, #0xae8
   f086c:      	br	x17

00000000000f0870 <strtof@plt>:
   f0870:      	adrp	x16, 0xfd000
   f0874:      	ldr	x17, [x16, #0xaf0]
   f0878:      	add	x16, x16, #0xaf0
   f087c:      	br	x17

00000000000f0880 <strtod@plt>:
   f0880:      	adrp	x16, 0xfd000
   f0884:      	ldr	x17, [x16, #0xaf8]
   f0888:      	add	x16, x16, #0xaf8
   f088c:      	br	x17

00000000000f0890 <strtold@plt>:
   f0890:      	adrp	x16, 0xfd000
   f0894:      	ldr	x17, [x16, #0xb00]
   f0898:      	add	x16, x16, #0xb00
   f089c:      	br	x17

00000000000f08a0 <wcstoul@plt>:
   f08a0:      	adrp	x16, 0xfd000
   f08a4:      	ldr	x17, [x16, #0xb08]
   f08a8:      	add	x16, x16, #0xb08
   f08ac:      	br	x17

00000000000f08b0 <wcstoll@plt>:
   f08b0:      	adrp	x16, 0xfd000
   f08b4:      	ldr	x17, [x16, #0xb10]
   f08b8:      	add	x16, x16, #0xb10
   f08bc:      	br	x17

00000000000f08c0 <wcstoull@plt>:
   f08c0:      	adrp	x16, 0xfd000
   f08c4:      	ldr	x17, [x16, #0xb18]
   f08c8:      	add	x16, x16, #0xb18
   f08cc:      	br	x17

00000000000f08d0 <wcstof@plt>:
   f08d0:      	adrp	x16, 0xfd000
   f08d4:      	ldr	x17, [x16, #0xb20]
   f08d8:      	add	x16, x16, #0xb20
   f08dc:      	br	x17

00000000000f08e0 <wcstod@plt>:
   f08e0:      	adrp	x16, 0xfd000
   f08e4:      	ldr	x17, [x16, #0xb28]
   f08e8:      	add	x16, x16, #0xb28
   f08ec:      	br	x17

00000000000f08f0 <wcstold@plt>:
   f08f0:      	adrp	x16, 0xfd000
   f08f4:      	ldr	x17, [x16, #0xb30]
   f08f8:      	add	x16, x16, #0xb30
   f08fc:      	br	x17

00000000000f0900 <snprintf@plt>:
   f0900:      	adrp	x16, 0xfd000
   f0904:      	ldr	x17, [x16, #0xb38]
   f0908:      	add	x16, x16, #0xb38
   f090c:      	br	x17

00000000000f0910 <swprintf@plt>:
   f0910:      	adrp	x16, 0xfd000
   f0914:      	ldr	x17, [x16, #0xb40]
   f0918:      	add	x16, x16, #0xb40
   f091c:      	br	x17

00000000000f0920 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEED1Ev@plt>:
   f0920:      	adrp	x16, 0xfd000
   f0924:      	ldr	x17, [x16, #0xb48]
   f0928:      	add	x16, x16, #0xb48
   f092c:      	br	x17

00000000000f0930 <strtol@plt>:
   f0930:      	adrp	x16, 0xfd000
   f0934:      	ldr	x17, [x16, #0xb50]
   f0938:      	add	x16, x16, #0xb50
   f093c:      	br	x17

00000000000f0940 <_ZNSt16invalid_argumentD1Ev@plt>:
   f0940:      	adrp	x16, 0xfd000
   f0944:      	ldr	x17, [x16, #0xb58]
   f0948:      	add	x16, x16, #0xb58
   f094c:      	br	x17

00000000000f0950 <wcstol@plt>:
   f0950:      	adrp	x16, 0xfd000
   f0954:      	ldr	x17, [x16, #0xb60]
   f0958:      	add	x16, x16, #0xb60
   f095c:      	br	x17

00000000000f0960 <_ZNSt6__ndk115system_categoryEv@plt>:
   f0960:      	adrp	x16, 0xfd000
   f0964:      	ldr	x17, [x16, #0xb68]
   f0968:      	add	x16, x16, #0xb68
   f096c:      	br	x17

00000000000f0970 <_ZNSt6__ndk112system_errorC2ENS_10error_codeERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
   f0970:      	adrp	x16, 0xfd000
   f0974:      	ldr	x17, [x16, #0xb70]
   f0978:      	add	x16, x16, #0xb70
   f097c:      	br	x17

00000000000f0980 <_ZNSt6__ndk112system_errorC2ENS_10error_codeEPKc@plt>:
   f0980:      	adrp	x16, 0xfd000
   f0984:      	ldr	x17, [x16, #0xb78]
   f0988:      	add	x16, x16, #0xb78
   f098c:      	br	x17

00000000000f0990 <_ZNSt6__ndk112system_errorD2Ev@plt>:
   f0990:      	adrp	x16, 0xfd000
   f0994:      	ldr	x17, [x16, #0xb80]
   f0998:      	add	x16, x16, #0xb80
   f099c:      	br	x17

00000000000f09a0 <_ZNSt6__ndk112system_errorD1Ev@plt>:
   f09a0:      	adrp	x16, 0xfd000
   f09a4:      	ldr	x17, [x16, #0xb88]
   f09a8:      	add	x16, x16, #0xb88
   f09ac:      	br	x17

00000000000f09b0 <strerror_r@plt>:
   f09b0:      	adrp	x16, 0xfd000
   f09b4:      	ldr	x17, [x16, #0xb90]
   f09b8:      	add	x16, x16, #0xb90
   f09bc:      	br	x17

00000000000f09c0 <abort@plt>:
   f09c0:      	adrp	x16, 0xfd000
   f09c4:      	ldr	x17, [x16, #0xb98]
   f09c8:      	add	x16, x16, #0xb98
   f09cc:      	br	x17

00000000000f09d0 <_ZNSt13runtime_errorD2Ev@plt>:
   f09d0:      	adrp	x16, 0xfd000
   f09d4:      	ldr	x17, [x16, #0xba0]
   f09d8:      	add	x16, x16, #0xba0
   f09dc:      	br	x17

00000000000f09e0 <_ZNSt6__ndk112system_errorC1ENS_10error_codeEPKc@plt>:
   f09e0:      	adrp	x16, 0xfd000
   f09e4:      	ldr	x17, [x16, #0xba8]
   f09e8:      	add	x16, x16, #0xba8
   f09ec:      	br	x17

00000000000f09f0 <_ZNSt6__ndk18ios_base7failureD1Ev@plt>:
   f09f0:      	adrp	x16, 0xfd000
   f09f4:      	ldr	x17, [x16, #0xbb0]
   f09f8:      	add	x16, x16, #0xbb0
   f09fc:      	br	x17

00000000000f0a00 <_ZNSt6__ndk18ios_base16__call_callbacksENS0_5eventE@plt>:
   f0a00:      	adrp	x16, 0xfd000
   f0a04:      	ldr	x17, [x16, #0xbb8]
   f0a08:      	add	x16, x16, #0xbb8
   f0a0c:      	br	x17

00000000000f0a10 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
   f0a10:      	adrp	x16, 0xfd000
   f0a14:      	ldr	x17, [x16, #0xbc0]
   f0a18:      	add	x16, x16, #0xbc0
   f0a1c:      	br	x17

00000000000f0a20 <_ZNSt6__ndk16localeaSERKS0_@plt>:
   f0a20:      	adrp	x16, 0xfd000
   f0a24:      	ldr	x17, [x16, #0xbc8]
   f0a28:      	add	x16, x16, #0xbc8
   f0a2c:      	br	x17

00000000000f0a30 <realloc@plt>:
   f0a30:      	adrp	x16, 0xfd000
   f0a34:      	ldr	x17, [x16, #0xbd0]
   f0a38:      	add	x16, x16, #0xbd0
   f0a3c:      	br	x17

00000000000f0a40 <_ZNSt6__ndk18ios_baseD2Ev@plt>:
   f0a40:      	adrp	x16, 0xfd000
   f0a44:      	ldr	x17, [x16, #0xbd8]
   f0a48:      	add	x16, x16, #0xbd8
   f0a4c:      	br	x17

00000000000f0a50 <free@plt>:
   f0a50:      	adrp	x16, 0xfd000
   f0a54:      	ldr	x17, [x16, #0xbe0]
   f0a58:      	add	x16, x16, #0xbe0
   f0a5c:      	br	x17

00000000000f0a60 <_ZNSt6__ndk18ios_baseD1Ev@plt>:
   f0a60:      	adrp	x16, 0xfd000
   f0a64:      	ldr	x17, [x16, #0xbe8]
   f0a68:      	add	x16, x16, #0xbe8
   f0a6c:      	br	x17

00000000000f0a70 <_ZNSt6__ndk18ios_base7failureC1EPKcRKNS_10error_codeE@plt>:
   f0a70:      	adrp	x16, 0xfd000
   f0a74:      	ldr	x17, [x16, #0xbf0]
   f0a78:      	add	x16, x16, #0xbf0
   f0a7c:      	br	x17

00000000000f0a80 <_ZNSt6__ndk16localeC1Ev@plt>:
   f0a80:      	adrp	x16, 0xfd000
   f0a84:      	ldr	x17, [x16, #0xbf8]
   f0a88:      	add	x16, x16, #0xbf8
   f0a8c:      	br	x17

00000000000f0a90 <_ZNSt6__ndk18ios_base7copyfmtERKS0_@plt>:
   f0a90:      	adrp	x16, 0xfd000
   f0a94:      	ldr	x17, [x16, #0xc00]
   f0a98:      	add	x16, x16, #0xc00
   f0a9c:      	br	x17

00000000000f0aa0 <malloc@plt>:
   f0aa0:      	adrp	x16, 0xfd000
   f0aa4:      	ldr	x17, [x16, #0xc08]
   f0aa8:      	add	x16, x16, #0xc08
   f0aac:      	br	x17

00000000000f0ab0 <_ZNSt6__ndk18ios_base4swapERS0_@plt>:
   f0ab0:      	adrp	x16, 0xfd000
   f0ab4:      	ldr	x17, [x16, #0xc10]
   f0ab8:      	add	x16, x16, #0xc10
   f0abc:      	br	x17

00000000000f0ac0 <_ZNSt6__ndk18ios_base34__set_failbit_and_consider_rethrowEv@plt>:
   f0ac0:      	adrp	x16, 0xfd000
   f0ac4:      	ldr	x17, [x16, #0xc18]
   f0ac8:      	add	x16, x16, #0xc18
   f0acc:      	br	x17

00000000000f0ad0 <_ZNSt9bad_allocC1Ev@plt>:
   f0ad0:      	adrp	x16, 0xfd000
   f0ad4:      	ldr	x17, [x16, #0xc20]
   f0ad8:      	add	x16, x16, #0xc20
   f0adc:      	br	x17

00000000000f0ae0 <_ZNSt9bad_allocD1Ev@plt>:
   f0ae0:      	adrp	x16, 0xfd000
   f0ae4:      	ldr	x17, [x16, #0xc28]
   f0ae8:      	add	x16, x16, #0xc28
   f0aec:      	br	x17

00000000000f0af0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED1Ev@plt>:
   f0af0:      	adrp	x16, 0xfd000
   f0af4:      	ldr	x17, [x16, #0xc30]
   f0af8:      	add	x16, x16, #0xc30
   f0afc:      	br	x17

00000000000f0b00 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED1Ev@plt>:
   f0b00:      	adrp	x16, 0xfd000
   f0b04:      	ldr	x17, [x16, #0xc38]
   f0b08:      	add	x16, x16, #0xc38
   f0b0c:      	br	x17

00000000000f0b10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
   f0b10:      	adrp	x16, 0xfd000
   f0b14:      	ldr	x17, [x16, #0xc40]
   f0b18:      	add	x16, x16, #0xc40
   f0b1c:      	br	x17

00000000000f0b20 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
   f0b20:      	adrp	x16, 0xfd000
   f0b24:      	ldr	x17, [x16, #0xc48]
   f0b28:      	add	x16, x16, #0xc48
   f0b2c:      	br	x17

00000000000f0b30 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEv@plt>:
   f0b30:      	adrp	x16, 0xfd000
   f0b34:      	ldr	x17, [x16, #0xc50]
   f0b38:      	add	x16, x16, #0xc50
   f0b3c:      	br	x17

00000000000f0b40 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEPclc@plt>:
   f0b40:      	adrp	x16, 0xfd000
   f0b44:      	ldr	x17, [x16, #0xc58]
   f0b48:      	add	x16, x16, #0xc58
   f0b4c:      	br	x17

00000000000f0b50 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERNS_15basic_streambufIcS2_EEc@plt>:
   f0b50:      	adrp	x16, 0xfd000
   f0b54:      	ldr	x17, [x16, #0xc60]
   f0b58:      	add	x16, x16, #0xc60
   f0b5c:      	br	x17

00000000000f0b60 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPclc@plt>:
   f0b60:      	adrp	x16, 0xfd000
   f0b64:      	ldr	x17, [x16, #0xc68]
   f0b68:      	add	x16, x16, #0xc68
   f0b6c:      	br	x17

00000000000f0b70 <_ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED2Ev@plt>:
   f0b70:      	adrp	x16, 0xfd000
   f0b74:      	ldr	x17, [x16, #0xc70]
   f0b78:      	add	x16, x16, #0xc70
   f0b7c:      	br	x17

00000000000f0b80 <_ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED1Ev@plt>:
   f0b80:      	adrp	x16, 0xfd000
   f0b84:      	ldr	x17, [x16, #0xc78]
   f0b88:      	add	x16, x16, #0xc78
   f0b8c:      	br	x17

00000000000f0b90 <_ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED2Ev@plt>:
   f0b90:      	adrp	x16, 0xfd000
   f0b94:      	ldr	x17, [x16, #0xc80]
   f0b98:      	add	x16, x16, #0xc80
   f0b9c:      	br	x17

00000000000f0ba0 <_ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED1Ev@plt>:
   f0ba0:      	adrp	x16, 0xfd000
   f0ba4:      	ldr	x17, [x16, #0xc88]
   f0ba8:      	add	x16, x16, #0xc88
   f0bac:      	br	x17

00000000000f0bb0 <_ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEC2Ev@plt>:
   f0bb0:      	adrp	x16, 0xfd000
   f0bb4:      	ldr	x17, [x16, #0xc90]
   f0bb8:      	add	x16, x16, #0xc90
   f0bbc:      	br	x17

00000000000f0bc0 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5flushEv@plt>:
   f0bc0:      	adrp	x16, 0xfd000
   f0bc4:      	ldr	x17, [x16, #0xc98]
   f0bc8:      	add	x16, x16, #0xc98
   f0bcc:      	br	x17

00000000000f0bd0 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryC1ERS3_@plt>:
   f0bd0:      	adrp	x16, 0xfd000
   f0bd4:      	ldr	x17, [x16, #0xca0]
   f0bd8:      	add	x16, x16, #0xca0
   f0bdc:      	br	x17

00000000000f0be0 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryD1Ev@plt>:
   f0be0:      	adrp	x16, 0xfd000
   f0be4:      	ldr	x17, [x16, #0xca8]
   f0be8:      	add	x16, x16, #0xca8
   f0bec:      	br	x17

00000000000f0bf0 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE6sentryC1ERS3_b@plt>:
   f0bf0:      	adrp	x16, 0xfd000
   f0bf4:      	ldr	x17, [x16, #0xcb0]
   f0bf8:      	add	x16, x16, #0xcb0
   f0bfc:      	br	x17

00000000000f0c00 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEv@plt>:
   f0c00:      	adrp	x16, 0xfd000
   f0c04:      	ldr	x17, [x16, #0xcb8]
   f0c08:      	add	x16, x16, #0xcb8
   f0c0c:      	br	x17

00000000000f0c10 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEPwlw@plt>:
   f0c10:      	adrp	x16, 0xfd000
   f0c14:      	ldr	x17, [x16, #0xcc0]
   f0c18:      	add	x16, x16, #0xcc0
   f0c1c:      	br	x17

00000000000f0c20 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERNS_15basic_streambufIwS2_EEw@plt>:
   f0c20:      	adrp	x16, 0xfd000
   f0c24:      	ldr	x17, [x16, #0xcc8]
   f0c28:      	add	x16, x16, #0xcc8
   f0c2c:      	br	x17

00000000000f0c30 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7getlineEPwlw@plt>:
   f0c30:      	adrp	x16, 0xfd000
   f0c34:      	ldr	x17, [x16, #0xcd0]
   f0c38:      	add	x16, x16, #0xcd0
   f0c3c:      	br	x17

00000000000f0c40 <_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEOS5_@plt>:
   f0c40:      	adrp	x16, 0xfd000
   f0c44:      	ldr	x17, [x16, #0xcd8]
   f0c48:      	add	x16, x16, #0xcd8
   f0c4c:      	br	x17

00000000000f0c50 <_ZNKSt6__ndk16locale9has_facetERNS0_2idE@plt>:
   f0c50:      	adrp	x16, 0xfd000
   f0c54:      	ldr	x17, [x16, #0xce0]
   f0c58:      	add	x16, x16, #0xce0
   f0c5c:      	br	x17

00000000000f0c60 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4syncEv@plt>:
   f0c60:      	adrp	x16, 0xfd000
   f0c64:      	ldr	x17, [x16, #0xce8]
   f0c68:      	add	x16, x16, #0xce8
   f0c6c:      	br	x17

00000000000f0c70 <_ZNSt8bad_castC1Ev@plt>:
   f0c70:      	adrp	x16, 0xfd000
   f0c74:      	ldr	x17, [x16, #0xcf0]
   f0c78:      	add	x16, x16, #0xcf0
   f0c7c:      	br	x17

00000000000f0c80 <_ZNSt8bad_castD1Ev@plt>:
   f0c80:      	adrp	x16, 0xfd000
   f0c84:      	ldr	x17, [x16, #0xcf8]
   f0c88:      	add	x16, x16, #0xcf8
   f0c8c:      	br	x17

00000000000f0c90 <fseeko@plt>:
   f0c90:      	adrp	x16, 0xfd000
   f0c94:      	ldr	x17, [x16, #0xd00]
   f0c98:      	add	x16, x16, #0xd00
   f0c9c:      	br	x17

00000000000f0ca0 <ftello@plt>:
   f0ca0:      	adrp	x16, 0xfd000
   f0ca4:      	ldr	x17, [x16, #0xd08]
   f0ca8:      	add	x16, x16, #0xd08
   f0cac:      	br	x17

00000000000f0cb0 <fflush@plt>:
   f0cb0:      	adrp	x16, 0xfd000
   f0cb4:      	ldr	x17, [x16, #0xd10]
   f0cb8:      	add	x16, x16, #0xd10
   f0cbc:      	br	x17

00000000000f0cc0 <__cxa_uncaught_exceptions@plt>:
   f0cc0:      	adrp	x16, 0xfd000
   f0cc4:      	ldr	x17, [x16, #0xd18]
   f0cc8:      	add	x16, x16, #0xd18
   f0ccc:      	br	x17

00000000000f0cd0 <__cxa_decrement_exception_refcount@plt>:
   f0cd0:      	adrp	x16, 0xfd000
   f0cd4:      	ldr	x17, [x16, #0xd20]
   f0cd8:      	add	x16, x16, #0xd20
   f0cdc:      	br	x17

00000000000f0ce0 <__cxa_increment_exception_refcount@plt>:
   f0ce0:      	adrp	x16, 0xfd000
   f0ce4:      	ldr	x17, [x16, #0xd28]
   f0ce8:      	add	x16, x16, #0xd28
   f0cec:      	br	x17

00000000000f0cf0 <__cxa_current_primary_exception@plt>:
   f0cf0:      	adrp	x16, 0xfd000
   f0cf4:      	ldr	x17, [x16, #0xd30]
   f0cf8:      	add	x16, x16, #0xd30
   f0cfc:      	br	x17

00000000000f0d00 <__cxa_rethrow_primary_exception@plt>:
   f0d00:      	adrp	x16, 0xfd000
   f0d04:      	ldr	x17, [x16, #0xd38]
   f0d08:      	add	x16, x16, #0xd38
   f0d0c:      	br	x17

00000000000f0d10 <ungetc@plt>:
   f0d10:      	adrp	x16, 0xfd000
   f0d14:      	ldr	x17, [x16, #0xd40]
   f0d18:      	add	x16, x16, #0xd40
   f0d1c:      	br	x17

00000000000f0d20 <getc@plt>:
   f0d20:      	adrp	x16, 0xfd000
   f0d24:      	ldr	x17, [x16, #0xd48]
   f0d28:      	add	x16, x16, #0xd48
   f0d2c:      	br	x17

00000000000f0d30 <ungetwc@plt>:
   f0d30:      	adrp	x16, 0xfd000
   f0d34:      	ldr	x17, [x16, #0xd50]
   f0d38:      	add	x16, x16, #0xd50
   f0d3c:      	br	x17

00000000000f0d40 <getwc@plt>:
   f0d40:      	adrp	x16, 0xfd000
   f0d44:      	ldr	x17, [x16, #0xd58]
   f0d48:      	add	x16, x16, #0xd58
   f0d4c:      	br	x17

00000000000f0d50 <fputwc@plt>:
   f0d50:      	adrp	x16, 0xfd000
   f0d54:      	ldr	x17, [x16, #0xd60]
   f0d58:      	add	x16, x16, #0xd60
   f0d5c:      	br	x17

00000000000f0d60 <_ZNSt6__ndk18ios_base4InitC1Ev@plt>:
   f0d60:      	adrp	x16, 0xfd000
   f0d64:      	ldr	x17, [x16, #0xd68]
   f0d68:      	add	x16, x16, #0xd68
   f0d6c:      	br	x17

00000000000f0d70 <_ZNSt6__ndk17collateIcED1Ev@plt>:
   f0d70:      	adrp	x16, 0xfd000
   f0d74:      	ldr	x17, [x16, #0xd70]
   f0d78:      	add	x16, x16, #0xd70
   f0d7c:      	br	x17

00000000000f0d80 <_ZNSt6__ndk17collateIwED1Ev@plt>:
   f0d80:      	adrp	x16, 0xfd000
   f0d84:      	ldr	x17, [x16, #0xd78]
   f0d88:      	add	x16, x16, #0xd78
   f0d8c:      	br	x17

00000000000f0d90 <_ZNSt6__ndk19__num_getIcE17__stage2_int_prepERNS_8ios_baseEPcRc@plt>:
   f0d90:      	adrp	x16, 0xfd000
   f0d94:      	ldr	x17, [x16, #0xd80]
   f0d98:      	add	x16, x16, #0xd80
   f0d9c:      	br	x17

00000000000f0da0 <_ZNSt6__ndk19__num_getIcE19__stage2_float_prepERNS_8ios_baseEPcRcS5_@plt>:
   f0da0:      	adrp	x16, 0xfd000
   f0da4:      	ldr	x17, [x16, #0xd88]
   f0da8:      	add	x16, x16, #0xd88
   f0dac:      	br	x17

00000000000f0db0 <_ZNSt6__ndk19__num_getIcE19__stage2_float_loopEcRbRcPcRS4_ccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjS4_@plt>:
   f0db0:      	adrp	x16, 0xfd000
   f0db4:      	ldr	x17, [x16, #0xd90]
   f0db8:      	add	x16, x16, #0xd90
   f0dbc:      	br	x17

00000000000f0dc0 <newlocale@plt>:
   f0dc0:      	adrp	x16, 0xfd000
   f0dc4:      	ldr	x17, [x16, #0xd98]
   f0dc8:      	add	x16, x16, #0xd98
   f0dcc:      	br	x17

00000000000f0dd0 <uselocale@plt>:
   f0dd0:      	adrp	x16, 0xfd000
   f0dd4:      	ldr	x17, [x16, #0xda0]
   f0dd8:      	add	x16, x16, #0xda0
   f0ddc:      	br	x17

00000000000f0de0 <vsscanf@plt>:
   f0de0:      	adrp	x16, 0xfd000
   f0de4:      	ldr	x17, [x16, #0xda8]
   f0de8:      	add	x16, x16, #0xda8
   f0dec:      	br	x17

00000000000f0df0 <_ZNSt6__ndk19__num_getIwE17__stage2_int_prepERNS_8ios_baseEPwRw@plt>:
   f0df0:      	adrp	x16, 0xfd000
   f0df4:      	ldr	x17, [x16, #0xdb0]
   f0df8:      	add	x16, x16, #0xdb0
   f0dfc:      	br	x17

00000000000f0e00 <_ZNSt6__ndk19__num_getIwE19__stage2_float_prepERNS_8ios_baseEPwRwS5_@plt>:
   f0e00:      	adrp	x16, 0xfd000
   f0e04:      	ldr	x17, [x16, #0xdb8]
   f0e08:      	add	x16, x16, #0xdb8
   f0e0c:      	br	x17

00000000000f0e10 <_ZNSt6__ndk19__num_getIwE19__stage2_float_loopEwRbRcPcRS4_wwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjPw@plt>:
   f0e10:      	adrp	x16, 0xfd000
   f0e14:      	ldr	x17, [x16, #0xdc0]
   f0e18:      	add	x16, x16, #0xdc0
   f0e1c:      	br	x17

00000000000f0e20 <_ZNSt6__ndk19__num_putIcE21__widen_and_group_intEPcS2_S2_S2_RS2_S3_RKNS_6localeE@plt>:
   f0e20:      	adrp	x16, 0xfd000
   f0e24:      	ldr	x17, [x16, #0xdc8]
   f0e28:      	add	x16, x16, #0xdc8
   f0e2c:      	br	x17

00000000000f0e30 <_ZNSt6__ndk19__num_putIcE23__widen_and_group_floatEPcS2_S2_S2_RS2_S3_RKNS_6localeE@plt>:
   f0e30:      	adrp	x16, 0xfd000
   f0e34:      	ldr	x17, [x16, #0xdd0]
   f0e38:      	add	x16, x16, #0xdd0
   f0e3c:      	br	x17

00000000000f0e40 <_ZNSt6__ndk19__num_putIwE21__widen_and_group_intEPcS2_S2_PwRS3_S4_RKNS_6localeE@plt>:
   f0e40:      	adrp	x16, 0xfd000
   f0e44:      	ldr	x17, [x16, #0xdd8]
   f0e48:      	add	x16, x16, #0xdd8
   f0e4c:      	br	x17

00000000000f0e50 <_ZNSt6__ndk19__num_putIwE23__widen_and_group_floatEPcS2_S2_PwRS3_S4_RKNS_6localeE@plt>:
   f0e50:      	adrp	x16, 0xfd000
   f0e54:      	ldr	x17, [x16, #0xde0]
   f0e58:      	add	x16, x16, #0xde0
   f0e5c:      	br	x17

00000000000f0e60 <_ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKcSC_@plt>:
   f0e60:      	adrp	x16, 0xfd000
   f0e64:      	ldr	x17, [x16, #0xde8]
   f0e68:      	add	x16, x16, #0xde8
   f0e6c:      	br	x17

00000000000f0e70 <_ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIcEE@plt>:
   f0e70:      	adrp	x16, 0xfd000
   f0e74:      	ldr	x17, [x16, #0xdf0]
   f0e78:      	add	x16, x16, #0xdf0
   f0e7c:      	br	x17

00000000000f0e80 <_ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIcEE@plt>:
   f0e80:      	adrp	x16, 0xfd000
   f0e84:      	ldr	x17, [x16, #0xdf8]
   f0e88:      	add	x16, x16, #0xdf8
   f0e8c:      	br	x17

00000000000f0e90 <_ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKwSC_@plt>:
   f0e90:      	adrp	x16, 0xfd000
   f0e94:      	ldr	x17, [x16, #0xe00]
   f0e98:      	add	x16, x16, #0xe00
   f0e9c:      	br	x17

00000000000f0ea0 <_ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIwEE@plt>:
   f0ea0:      	adrp	x16, 0xfd000
   f0ea4:      	ldr	x17, [x16, #0xe08]
   f0ea8:      	add	x16, x16, #0xe08
   f0eac:      	br	x17

00000000000f0eb0 <_ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIwEE@plt>:
   f0eb0:      	adrp	x16, 0xfd000
   f0eb4:      	ldr	x17, [x16, #0xe10]
   f0eb8:      	add	x16, x16, #0xe10
   f0ebc:      	br	x17

00000000000f0ec0 <strftime_l@plt>:
   f0ec0:      	adrp	x16, 0xfd000
   f0ec4:      	ldr	x17, [x16, #0xe18]
   f0ec8:      	add	x16, x16, #0xe18
   f0ecc:      	br	x17

00000000000f0ed0 <_ZNKSt6__ndk110__time_put8__do_putEPwRS1_PK2tmcc@plt>:
   f0ed0:      	adrp	x16, 0xfd000
   f0ed4:      	ldr	x17, [x16, #0xe20]
   f0ed8:      	add	x16, x16, #0xe20
   f0edc:      	br	x17

00000000000f0ee0 <mbsrtowcs@plt>:
   f0ee0:      	adrp	x16, 0xfd000
   f0ee4:      	ldr	x17, [x16, #0xe28]
   f0ee8:      	add	x16, x16, #0xe28
   f0eec:      	br	x17

00000000000f0ef0 <_ZNSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIcEERNS_10unique_ptrIcPFvPvEEERPcSM_@plt>:
   f0ef0:      	adrp	x16, 0xfd000
   f0ef4:      	ldr	x17, [x16, #0xe30]
   f0ef8:      	add	x16, x16, #0xe30
   f0efc:      	br	x17

00000000000f0f00 <sscanf@plt>:
   f0f00:      	adrp	x16, 0xfd000
   f0f04:      	ldr	x17, [x16, #0xe38]
   f0f08:      	add	x16, x16, #0xe38
   f0f0c:      	br	x17

00000000000f0f10 <_ZNSt6__ndk111__money_getIcE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_SF_Ri@plt>:
   f0f10:      	adrp	x16, 0xfd000
   f0f14:      	ldr	x17, [x16, #0xe40]
   f0f18:      	add	x16, x16, #0xe40
   f0f1c:      	br	x17

00000000000f0f20 <_ZNSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIwEERNS_10unique_ptrIwPFvPvEEERPwSM_@plt>:
   f0f20:      	adrp	x16, 0xfd000
   f0f24:      	ldr	x17, [x16, #0xe48]
   f0f28:      	add	x16, x16, #0xe48
   f0f2c:      	br	x17

00000000000f0f30 <_ZNSt6__ndk111__money_getIwE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_SJ_Ri@plt>:
   f0f30:      	adrp	x16, 0xfd000
   f0f34:      	ldr	x17, [x16, #0xe50]
   f0f38:      	add	x16, x16, #0xe50
   f0f3c:      	br	x17

00000000000f0f40 <_ZNSt6__ndk111__money_putIcE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_Ri@plt>:
   f0f40:      	adrp	x16, 0xfd000
   f0f44:      	ldr	x17, [x16, #0xe58]
   f0f48:      	add	x16, x16, #0xe58
   f0f4c:      	br	x17

00000000000f0f50 <_ZNSt6__ndk111__money_putIcE8__formatEPcRS2_S3_jPKcS5_RKNS_5ctypeIcEEbRKNS_10money_base7patternEccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESL_SL_i@plt>:
   f0f50:      	adrp	x16, 0xfd000
   f0f54:      	ldr	x17, [x16, #0xe60]
   f0f58:      	add	x16, x16, #0xe60
   f0f5c:      	br	x17

00000000000f0f60 <vasprintf@plt>:
   f0f60:      	adrp	x16, 0xfd000
   f0f64:      	ldr	x17, [x16, #0xe68]
   f0f68:      	add	x16, x16, #0xe68
   f0f6c:      	br	x17

00000000000f0f70 <_ZNSt6__ndk111__money_putIwE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_Ri@plt>:
   f0f70:      	adrp	x16, 0xfd000
   f0f74:      	ldr	x17, [x16, #0xe70]
   f0f78:      	add	x16, x16, #0xe70
   f0f7c:      	br	x17

00000000000f0f80 <_ZNSt6__ndk111__money_putIwE8__formatEPwRS2_S3_jPKwS5_RKNS_5ctypeIwEEbRKNS_10money_base7patternEwwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNSE_IwNSF_IwEENSH_IwEEEESQ_i@plt>:
   f0f80:      	adrp	x16, 0xfd000
   f0f84:      	ldr	x17, [x16, #0xe78]
   f0f88:      	add	x16, x16, #0xe78
   f0f8c:      	br	x17

00000000000f0f90 <_ZNSt6__ndk17codecvtIcc9mbstate_tED2Ev@plt>:
   f0f90:      	adrp	x16, 0xfd000
   f0f94:      	ldr	x17, [x16, #0xe80]
   f0f98:      	add	x16, x16, #0xe80
   f0f9c:      	br	x17

00000000000f0fa0 <_ZNSt6__ndk114codecvt_bynameIcc9mbstate_tED1Ev@plt>:
   f0fa0:      	adrp	x16, 0xfd000
   f0fa4:      	ldr	x17, [x16, #0xe88]
   f0fa8:      	add	x16, x16, #0xe88
   f0fac:      	br	x17

00000000000f0fb0 <_ZNSt6__ndk17codecvtIwc9mbstate_tED2Ev@plt>:
   f0fb0:      	adrp	x16, 0xfd000
   f0fb4:      	ldr	x17, [x16, #0xe90]
   f0fb8:      	add	x16, x16, #0xe90
   f0fbc:      	br	x17

00000000000f0fc0 <_ZNSt6__ndk114codecvt_bynameIwc9mbstate_tED1Ev@plt>:
   f0fc0:      	adrp	x16, 0xfd000
   f0fc4:      	ldr	x17, [x16, #0xe98]
   f0fc8:      	add	x16, x16, #0xe98
   f0fcc:      	br	x17

00000000000f0fd0 <_ZNSt6__ndk17codecvtIDsc9mbstate_tED2Ev@plt>:
   f0fd0:      	adrp	x16, 0xfd000
   f0fd4:      	ldr	x17, [x16, #0xea0]
   f0fd8:      	add	x16, x16, #0xea0
   f0fdc:      	br	x17

00000000000f0fe0 <_ZNSt6__ndk114codecvt_bynameIDsc9mbstate_tED1Ev@plt>:
   f0fe0:      	adrp	x16, 0xfd000
   f0fe4:      	ldr	x17, [x16, #0xea8]
   f0fe8:      	add	x16, x16, #0xea8
   f0fec:      	br	x17

00000000000f0ff0 <_ZNSt6__ndk17codecvtIDic9mbstate_tED2Ev@plt>:
   f0ff0:      	adrp	x16, 0xfd000
   f0ff4:      	ldr	x17, [x16, #0xeb0]
   f0ff8:      	add	x16, x16, #0xeb0
   f0ffc:      	br	x17

00000000000f1000 <_ZNSt6__ndk114codecvt_bynameIDic9mbstate_tED1Ev@plt>:
   f1000:      	adrp	x16, 0xfd000
   f1004:      	ldr	x17, [x16, #0xeb8]
   f1008:      	add	x16, x16, #0xeb8
   f100c:      	br	x17

00000000000f1010 <_ZNSt6__ndk17codecvtIDsDu9mbstate_tED2Ev@plt>:
   f1010:      	adrp	x16, 0xfd000
   f1014:      	ldr	x17, [x16, #0xec0]
   f1018:      	add	x16, x16, #0xec0
   f101c:      	br	x17

00000000000f1020 <_ZNSt6__ndk114codecvt_bynameIDsDu9mbstate_tED1Ev@plt>:
   f1020:      	adrp	x16, 0xfd000
   f1024:      	ldr	x17, [x16, #0xec8]
   f1028:      	add	x16, x16, #0xec8
   f102c:      	br	x17

00000000000f1030 <_ZNSt6__ndk17codecvtIDiDu9mbstate_tED2Ev@plt>:
   f1030:      	adrp	x16, 0xfd000
   f1034:      	ldr	x17, [x16, #0xed0]
   f1038:      	add	x16, x16, #0xed0
   f103c:      	br	x17

00000000000f1040 <_ZNSt6__ndk114codecvt_bynameIDiDu9mbstate_tED1Ev@plt>:
   f1040:      	adrp	x16, 0xfd000
   f1044:      	ldr	x17, [x16, #0xed8]
   f1048:      	add	x16, x16, #0xed8
   f104c:      	br	x17

00000000000f1050 <_ZNSt6__ndk15ctypeIcEC1EPKmbm@plt>:
   f1050:      	adrp	x16, 0xfd000
   f1054:      	ldr	x17, [x16, #0xee0]
   f1058:      	add	x16, x16, #0xee0
   f105c:      	br	x17

00000000000f1060 <_ZNSt6__ndk17codecvtIwc9mbstate_tEC1Em@plt>:
   f1060:      	adrp	x16, 0xfd000
   f1064:      	ldr	x17, [x16, #0xee8]
   f1068:      	add	x16, x16, #0xee8
   f106c:      	br	x17

00000000000f1070 <_ZNSt6__ndk18numpunctIcEC1Em@plt>:
   f1070:      	adrp	x16, 0xfd000
   f1074:      	ldr	x17, [x16, #0xef0]
   f1078:      	add	x16, x16, #0xef0
   f107c:      	br	x17

00000000000f1080 <_ZNSt6__ndk18numpunctIwEC1Em@plt>:
   f1080:      	adrp	x16, 0xfd000
   f1084:      	ldr	x17, [x16, #0xef8]
   f1088:      	add	x16, x16, #0xef8
   f108c:      	br	x17

00000000000f1090 <_ZNSt6__ndk114collate_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f1090:      	adrp	x16, 0xfd000
   f1094:      	ldr	x17, [x16, #0xf00]
   f1098:      	add	x16, x16, #0xf00
   f109c:      	br	x17

00000000000f10a0 <_ZNSt6__ndk114collate_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f10a0:      	adrp	x16, 0xfd000
   f10a4:      	ldr	x17, [x16, #0xf08]
   f10a8:      	add	x16, x16, #0xf08
   f10ac:      	br	x17

00000000000f10b0 <_ZNSt6__ndk112ctype_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f10b0:      	adrp	x16, 0xfd000
   f10b4:      	ldr	x17, [x16, #0xf10]
   f10b8:      	add	x16, x16, #0xf10
   f10bc:      	br	x17

00000000000f10c0 <_ZNSt6__ndk112ctype_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f10c0:      	adrp	x16, 0xfd000
   f10c4:      	ldr	x17, [x16, #0xf18]
   f10c8:      	add	x16, x16, #0xf18
   f10cc:      	br	x17

00000000000f10d0 <_ZNSt6__ndk17codecvtIwc9mbstate_tEC2EPKcm@plt>:
   f10d0:      	adrp	x16, 0xfd000
   f10d4:      	ldr	x17, [x16, #0xf20]
   f10d8:      	add	x16, x16, #0xf20
   f10dc:      	br	x17

00000000000f10e0 <_ZNSt6__ndk115numpunct_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f10e0:      	adrp	x16, 0xfd000
   f10e4:      	ldr	x17, [x16, #0xf28]
   f10e8:      	add	x16, x16, #0xf28
   f10ec:      	br	x17

00000000000f10f0 <_ZNSt6__ndk115numpunct_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f10f0:      	adrp	x16, 0xfd000
   f10f4:      	ldr	x17, [x16, #0xf30]
   f10f8:      	add	x16, x16, #0xf30
   f10fc:      	br	x17

00000000000f1100 <_ZNSt6__ndk118__time_get_storageIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
   f1100:      	adrp	x16, 0xfd000
   f1104:      	ldr	x17, [x16, #0xf38]
   f1108:      	add	x16, x16, #0xf38
   f110c:      	br	x17

00000000000f1110 <_ZNSt6__ndk118__time_get_storageIwEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
   f1110:      	adrp	x16, 0xfd000
   f1114:      	ldr	x17, [x16, #0xf40]
   f1118:      	add	x16, x16, #0xf40
   f111c:      	br	x17

00000000000f1120 <_ZNSt6__ndk16locale7classicEv@plt>:
   f1120:      	adrp	x16, 0xfd000
   f1124:      	ldr	x17, [x16, #0xf48]
   f1128:      	add	x16, x16, #0xf48
   f112c:      	br	x17

00000000000f1130 <_ZNSt6__ndk117moneypunct_bynameIcLb0EE4initEPKc@plt>:
   f1130:      	adrp	x16, 0xfd000
   f1134:      	ldr	x17, [x16, #0xf50]
   f1138:      	add	x16, x16, #0xf50
   f113c:      	br	x17

00000000000f1140 <_ZNSt6__ndk117moneypunct_bynameIcLb1EE4initEPKc@plt>:
   f1140:      	adrp	x16, 0xfd000
   f1144:      	ldr	x17, [x16, #0xf58]
   f1148:      	add	x16, x16, #0xf58
   f114c:      	br	x17

00000000000f1150 <_ZNSt6__ndk117moneypunct_bynameIwLb0EE4initEPKc@plt>:
   f1150:      	adrp	x16, 0xfd000
   f1154:      	ldr	x17, [x16, #0xf60]
   f1158:      	add	x16, x16, #0xf60
   f115c:      	br	x17

00000000000f1160 <_ZNSt6__ndk117moneypunct_bynameIwLb1EE4initEPKc@plt>:
   f1160:      	adrp	x16, 0xfd000
   f1164:      	ldr	x17, [x16, #0xf68]
   f1168:      	add	x16, x16, #0xf68
   f116c:      	br	x17

00000000000f1170 <setlocale@plt>:
   f1170:      	adrp	x16, 0xfd000
   f1174:      	ldr	x17, [x16, #0xf70]
   f1178:      	add	x16, x16, #0xf70
   f117c:      	br	x17

00000000000f1180 <_ZNSt6__ndk16locale5facetD1Ev@plt>:
   f1180:      	adrp	x16, 0xfd000
   f1184:      	ldr	x17, [x16, #0xf78]
   f1188:      	add	x16, x16, #0xf78
   f118c:      	br	x17

00000000000f1190 <freelocale@plt>:
   f1190:      	adrp	x16, 0xfd000
   f1194:      	ldr	x17, [x16, #0xf80]
   f1198:      	add	x16, x16, #0xf80
   f119c:      	br	x17

00000000000f11a0 <_ZNSt6__ndk114collate_bynameIcED1Ev@plt>:
   f11a0:      	adrp	x16, 0xfd000
   f11a4:      	ldr	x17, [x16, #0xf88]
   f11a8:      	add	x16, x16, #0xf88
   f11ac:      	br	x17

00000000000f11b0 <strcoll_l@plt>:
   f11b0:      	adrp	x16, 0xfd000
   f11b4:      	ldr	x17, [x16, #0xf90]
   f11b8:      	add	x16, x16, #0xf90
   f11bc:      	br	x17

00000000000f11c0 <strxfrm_l@plt>:
   f11c0:      	adrp	x16, 0xfd000
   f11c4:      	ldr	x17, [x16, #0xf98]
   f11c8:      	add	x16, x16, #0xf98
   f11cc:      	br	x17

00000000000f11d0 <_ZNSt6__ndk114collate_bynameIwED1Ev@plt>:
   f11d0:      	adrp	x16, 0xfd000
   f11d4:      	ldr	x17, [x16, #0xfa0]
   f11d8:      	add	x16, x16, #0xfa0
   f11dc:      	br	x17

00000000000f11e0 <wcscoll_l@plt>:
   f11e0:      	adrp	x16, 0xfd000
   f11e4:      	ldr	x17, [x16, #0xfa8]
   f11e8:      	add	x16, x16, #0xfa8
   f11ec:      	br	x17

00000000000f11f0 <wcsxfrm_l@plt>:
   f11f0:      	adrp	x16, 0xfd000
   f11f4:      	ldr	x17, [x16, #0xfb0]
   f11f8:      	add	x16, x16, #0xfb0
   f11fc:      	br	x17

00000000000f1200 <_ZNSt6__ndk15ctypeIwED1Ev@plt>:
   f1200:      	adrp	x16, 0xfd000
   f1204:      	ldr	x17, [x16, #0xfb8]
   f1208:      	add	x16, x16, #0xfb8
   f120c:      	br	x17

00000000000f1210 <iswlower_l@plt>:
   f1210:      	adrp	x16, 0xfd000
   f1214:      	ldr	x17, [x16, #0xfc0]
   f1218:      	add	x16, x16, #0xfc0
   f121c:      	br	x17

00000000000f1220 <_ZNSt6__ndk15ctypeIcED2Ev@plt>:
   f1220:      	adrp	x16, 0xfd000
   f1224:      	ldr	x17, [x16, #0xfc8]
   f1228:      	add	x16, x16, #0xfc8
   f122c:      	br	x17

00000000000f1230 <_ZNSt6__ndk15ctypeIcED1Ev@plt>:
   f1230:      	adrp	x16, 0xfd000
   f1234:      	ldr	x17, [x16, #0xfd0]
   f1238:      	add	x16, x16, #0xfd0
   f123c:      	br	x17

00000000000f1240 <_ZNSt6__ndk112ctype_bynameIcEC2EPKcm@plt>:
   f1240:      	adrp	x16, 0xfd000
   f1244:      	ldr	x17, [x16, #0xfd8]
   f1248:      	add	x16, x16, #0xfd8
   f124c:      	br	x17

00000000000f1250 <_ZNSt6__ndk112ctype_bynameIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f1250:      	adrp	x16, 0xfd000
   f1254:      	ldr	x17, [x16, #0xfe0]
   f1258:      	add	x16, x16, #0xfe0
   f125c:      	br	x17

00000000000f1260 <_ZNSt6__ndk112ctype_bynameIcED1Ev@plt>:
   f1260:      	adrp	x16, 0xfd000
   f1264:      	ldr	x17, [x16, #0xfe8]
   f1268:      	add	x16, x16, #0xfe8
   f126c:      	br	x17

00000000000f1270 <_ZNSt6__ndk112ctype_bynameIwEC2EPKcm@plt>:
   f1270:      	adrp	x16, 0xfd000
   f1274:      	ldr	x17, [x16, #0xff0]
   f1278:      	add	x16, x16, #0xff0
   f127c:      	br	x17

00000000000f1280 <_ZNSt6__ndk15ctypeIwED2Ev@plt>:
   f1280:      	adrp	x16, 0xfd000
   f1284:      	ldr	x17, [x16, #0xff8]
   f1288:      	add	x16, x16, #0xff8
   f128c:      	br	x17

00000000000f1290 <_ZNSt6__ndk112ctype_bynameIwEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
   f1290:      	adrp	x16, 0xfe000
   f1294:      	ldr	x17, [x16]
   f1298:      	add	x16, x16, #0x0
   f129c:      	br	x17

00000000000f12a0 <_ZNSt6__ndk112ctype_bynameIwED1Ev@plt>:
   f12a0:      	adrp	x16, 0xfe000
   f12a4:      	ldr	x17, [x16, #0x8]
   f12a8:      	add	x16, x16, #0x8
   f12ac:      	br	x17

00000000000f12b0 <iswspace_l@plt>:
   f12b0:      	adrp	x16, 0xfe000
   f12b4:      	ldr	x17, [x16, #0x10]
   f12b8:      	add	x16, x16, #0x10
   f12bc:      	br	x17

00000000000f12c0 <iswprint_l@plt>:
   f12c0:      	adrp	x16, 0xfe000
   f12c4:      	ldr	x17, [x16, #0x18]
   f12c8:      	add	x16, x16, #0x18
   f12cc:      	br	x17

00000000000f12d0 <iswcntrl_l@plt>:
   f12d0:      	adrp	x16, 0xfe000
   f12d4:      	ldr	x17, [x16, #0x20]
   f12d8:      	add	x16, x16, #0x20
   f12dc:      	br	x17

00000000000f12e0 <iswupper_l@plt>:
   f12e0:      	adrp	x16, 0xfe000
   f12e4:      	ldr	x17, [x16, #0x28]
   f12e8:      	add	x16, x16, #0x28
   f12ec:      	br	x17

00000000000f12f0 <iswalpha_l@plt>:
   f12f0:      	adrp	x16, 0xfe000
   f12f4:      	ldr	x17, [x16, #0x30]
   f12f8:      	add	x16, x16, #0x30
   f12fc:      	br	x17

00000000000f1300 <iswdigit_l@plt>:
   f1300:      	adrp	x16, 0xfe000
   f1304:      	ldr	x17, [x16, #0x38]
   f1308:      	add	x16, x16, #0x38
   f130c:      	br	x17

00000000000f1310 <iswpunct_l@plt>:
   f1310:      	adrp	x16, 0xfe000
   f1314:      	ldr	x17, [x16, #0x40]
   f1318:      	add	x16, x16, #0x40
   f131c:      	br	x17

00000000000f1320 <iswxdigit_l@plt>:
   f1320:      	adrp	x16, 0xfe000
   f1324:      	ldr	x17, [x16, #0x48]
   f1328:      	add	x16, x16, #0x48
   f132c:      	br	x17

00000000000f1330 <iswblank_l@plt>:
   f1330:      	adrp	x16, 0xfe000
   f1334:      	ldr	x17, [x16, #0x50]
   f1338:      	add	x16, x16, #0x50
   f133c:      	br	x17

00000000000f1340 <towupper_l@plt>:
   f1340:      	adrp	x16, 0xfe000
   f1344:      	ldr	x17, [x16, #0x58]
   f1348:      	add	x16, x16, #0x58
   f134c:      	br	x17

00000000000f1350 <towlower_l@plt>:
   f1350:      	adrp	x16, 0xfe000
   f1354:      	ldr	x17, [x16, #0x60]
   f1358:      	add	x16, x16, #0x60
   f135c:      	br	x17

00000000000f1360 <btowc@plt>:
   f1360:      	adrp	x16, 0xfe000
   f1364:      	ldr	x17, [x16, #0x68]
   f1368:      	add	x16, x16, #0x68
   f136c:      	br	x17

00000000000f1370 <wctob@plt>:
   f1370:      	adrp	x16, 0xfe000
   f1374:      	ldr	x17, [x16, #0x70]
   f1378:      	add	x16, x16, #0x70
   f137c:      	br	x17

00000000000f1380 <_ZNSt6__ndk17codecvtIcc9mbstate_tED1Ev@plt>:
   f1380:      	adrp	x16, 0xfe000
   f1384:      	ldr	x17, [x16, #0x78]
   f1388:      	add	x16, x16, #0x78
   f138c:      	br	x17

00000000000f1390 <_ZNSt6__ndk17codecvtIwc9mbstate_tED1Ev@plt>:
   f1390:      	adrp	x16, 0xfe000
   f1394:      	ldr	x17, [x16, #0x80]
   f1398:      	add	x16, x16, #0x80
   f139c:      	br	x17

00000000000f13a0 <wcsnrtombs@plt>:
   f13a0:      	adrp	x16, 0xfe000
   f13a4:      	ldr	x17, [x16, #0x88]
   f13a8:      	add	x16, x16, #0x88
   f13ac:      	br	x17

00000000000f13b0 <wcrtomb@plt>:
   f13b0:      	adrp	x16, 0xfe000
   f13b4:      	ldr	x17, [x16, #0x90]
   f13b8:      	add	x16, x16, #0x90
   f13bc:      	br	x17

00000000000f13c0 <mbsnrtowcs@plt>:
   f13c0:      	adrp	x16, 0xfe000
   f13c4:      	ldr	x17, [x16, #0x98]
   f13c8:      	add	x16, x16, #0x98
   f13cc:      	br	x17

00000000000f13d0 <mbrtowc@plt>:
   f13d0:      	adrp	x16, 0xfe000
   f13d4:      	ldr	x17, [x16, #0xa0]
   f13d8:      	add	x16, x16, #0xa0
   f13dc:      	br	x17

00000000000f13e0 <mbtowc@plt>:
   f13e0:      	adrp	x16, 0xfe000
   f13e4:      	ldr	x17, [x16, #0xa8]
   f13e8:      	add	x16, x16, #0xa8
   f13ec:      	br	x17

00000000000f13f0 <__ctype_get_mb_cur_max@plt>:
   f13f0:      	adrp	x16, 0xfe000
   f13f4:      	ldr	x17, [x16, #0xb0]
   f13f8:      	add	x16, x16, #0xb0
   f13fc:      	br	x17

00000000000f1400 <mbrlen@plt>:
   f1400:      	adrp	x16, 0xfe000
   f1404:      	ldr	x17, [x16, #0xb8]
   f1408:      	add	x16, x16, #0xb8
   f140c:      	br	x17

00000000000f1410 <_ZNSt6__ndk17codecvtIDsc9mbstate_tED1Ev@plt>:
   f1410:      	adrp	x16, 0xfe000
   f1414:      	ldr	x17, [x16, #0xc0]
   f1418:      	add	x16, x16, #0xc0
   f141c:      	br	x17

00000000000f1420 <_ZNSt6__ndk17codecvtIDsDu9mbstate_tED1Ev@plt>:
   f1420:      	adrp	x16, 0xfe000
   f1424:      	ldr	x17, [x16, #0xc8]
   f1428:      	add	x16, x16, #0xc8
   f142c:      	br	x17

00000000000f1430 <_ZNSt6__ndk17codecvtIDic9mbstate_tED1Ev@plt>:
   f1430:      	adrp	x16, 0xfe000
   f1434:      	ldr	x17, [x16, #0xd0]
   f1438:      	add	x16, x16, #0xd0
   f143c:      	br	x17

00000000000f1440 <_ZNSt6__ndk17codecvtIDiDu9mbstate_tED1Ev@plt>:
   f1440:      	adrp	x16, 0xfe000
   f1444:      	ldr	x17, [x16, #0xd8]
   f1448:      	add	x16, x16, #0xd8
   f144c:      	br	x17

00000000000f1450 <_ZNSt6__ndk116__narrow_to_utf8ILm16EED1Ev@plt>:
   f1450:      	adrp	x16, 0xfe000
   f1454:      	ldr	x17, [x16, #0xe0]
   f1458:      	add	x16, x16, #0xe0
   f145c:      	br	x17

00000000000f1460 <_ZNSt6__ndk116__narrow_to_utf8ILm32EED1Ev@plt>:
   f1460:      	adrp	x16, 0xfe000
   f1464:      	ldr	x17, [x16, #0xe8]
   f1468:      	add	x16, x16, #0xe8
   f146c:      	br	x17

00000000000f1470 <_ZNSt6__ndk117__widen_from_utf8ILm16EED1Ev@plt>:
   f1470:      	adrp	x16, 0xfe000
   f1474:      	ldr	x17, [x16, #0xf0]
   f1478:      	add	x16, x16, #0xf0
   f147c:      	br	x17

00000000000f1480 <_ZNSt6__ndk117__widen_from_utf8ILm32EED1Ev@plt>:
   f1480:      	adrp	x16, 0xfe000
   f1484:      	ldr	x17, [x16, #0xf8]
   f1488:      	add	x16, x16, #0xf8
   f148c:      	br	x17

00000000000f1490 <_ZNSt6__ndk18numpunctIcED2Ev@plt>:
   f1490:      	adrp	x16, 0xfe000
   f1494:      	ldr	x17, [x16, #0x100]
   f1498:      	add	x16, x16, #0x100
   f149c:      	br	x17

00000000000f14a0 <_ZNSt6__ndk18numpunctIcED1Ev@plt>:
   f14a0:      	adrp	x16, 0xfe000
   f14a4:      	ldr	x17, [x16, #0x108]
   f14a8:      	add	x16, x16, #0x108
   f14ac:      	br	x17

00000000000f14b0 <_ZNSt6__ndk18numpunctIwED2Ev@plt>:
   f14b0:      	adrp	x16, 0xfe000
   f14b4:      	ldr	x17, [x16, #0x110]
   f14b8:      	add	x16, x16, #0x110
   f14bc:      	br	x17

00000000000f14c0 <_ZNSt6__ndk18numpunctIwED1Ev@plt>:
   f14c0:      	adrp	x16, 0xfe000
   f14c4:      	ldr	x17, [x16, #0x118]
   f14c8:      	add	x16, x16, #0x118
   f14cc:      	br	x17

00000000000f14d0 <_ZNSt6__ndk115numpunct_bynameIcE6__initEPKc@plt>:
   f14d0:      	adrp	x16, 0xfe000
   f14d4:      	ldr	x17, [x16, #0x120]
   f14d8:      	add	x16, x16, #0x120
   f14dc:      	br	x17

00000000000f14e0 <localeconv@plt>:
   f14e0:      	adrp	x16, 0xfe000
   f14e4:      	ldr	x17, [x16, #0x128]
   f14e8:      	add	x16, x16, #0x128
   f14ec:      	br	x17

00000000000f14f0 <_ZNSt6__ndk115numpunct_bynameIcED1Ev@plt>:
   f14f0:      	adrp	x16, 0xfe000
   f14f4:      	ldr	x17, [x16, #0x130]
   f14f8:      	add	x16, x16, #0x130
   f14fc:      	br	x17

00000000000f1500 <_ZNSt6__ndk115numpunct_bynameIwE6__initEPKc@plt>:
   f1500:      	adrp	x16, 0xfe000
   f1504:      	ldr	x17, [x16, #0x138]
   f1508:      	add	x16, x16, #0x138
   f150c:      	br	x17

00000000000f1510 <_ZNSt6__ndk115numpunct_bynameIwED1Ev@plt>:
   f1510:      	adrp	x16, 0xfe000
   f1514:      	ldr	x17, [x16, #0x140]
   f1518:      	add	x16, x16, #0x140
   f151c:      	br	x17

00000000000f1520 <_ZNSt6__ndk110__time_getC2EPKc@plt>:
   f1520:      	adrp	x16, 0xfe000
   f1524:      	ldr	x17, [x16, #0x148]
   f1528:      	add	x16, x16, #0x148
   f152c:      	br	x17

00000000000f1530 <_ZNSt6__ndk110__time_getD2Ev@plt>:
   f1530:      	adrp	x16, 0xfe000
   f1534:      	ldr	x17, [x16, #0x150]
   f1538:      	add	x16, x16, #0x150
   f153c:      	br	x17

00000000000f1540 <_ZNSt6__ndk118__time_get_storageIcE9__analyzeEcRKNS_5ctypeIcEE@plt>:
   f1540:      	adrp	x16, 0xfe000
   f1544:      	ldr	x17, [x16, #0x158]
   f1548:      	add	x16, x16, #0x158
   f154c:      	br	x17

00000000000f1550 <_ZNSt6__ndk118__time_get_storageIwE9__analyzeEcRKNS_5ctypeIwEE@plt>:
   f1550:      	adrp	x16, 0xfe000
   f1554:      	ldr	x17, [x16, #0x160]
   f1558:      	add	x16, x16, #0x160
   f155c:      	br	x17

00000000000f1560 <_ZNSt6__ndk118__time_get_storageIcE4initERKNS_5ctypeIcEE@plt>:
   f1560:      	adrp	x16, 0xfe000
   f1564:      	ldr	x17, [x16, #0x168]
   f1568:      	add	x16, x16, #0x168
   f156c:      	br	x17

00000000000f1570 <_ZNSt6__ndk118__time_get_storageIwE4initERKNS_5ctypeIwEE@plt>:
   f1570:      	adrp	x16, 0xfe000
   f1574:      	ldr	x17, [x16, #0x170]
   f1578:      	add	x16, x16, #0x170
   f157c:      	br	x17

00000000000f1580 <_ZNSt6__ndk112ctype_bynameIcED2Ev@plt>:
   f1580:      	adrp	x16, 0xfe000
   f1584:      	ldr	x17, [x16, #0x178]
   f1588:      	add	x16, x16, #0x178
   f158c:      	br	x17

00000000000f1590 <_ZNSt6__ndk112ctype_bynameIwED2Ev@plt>:
   f1590:      	adrp	x16, 0xfe000
   f1594:      	ldr	x17, [x16, #0x180]
   f1598:      	add	x16, x16, #0x180
   f159c:      	br	x17

00000000000f15a0 <_ZNKSt6__ndk118__time_get_storageIcE15__do_date_orderEv@plt>:
   f15a0:      	adrp	x16, 0xfe000
   f15a4:      	ldr	x17, [x16, #0x188]
   f15a8:      	add	x16, x16, #0x188
   f15ac:      	br	x17

00000000000f15b0 <_ZNKSt6__ndk118__time_get_storageIwE15__do_date_orderEv@plt>:
   f15b0:      	adrp	x16, 0xfe000
   f15b4:      	ldr	x17, [x16, #0x190]
   f15b8:      	add	x16, x16, #0x190
   f15bc:      	br	x17

00000000000f15c0 <_ZNSt6__ndk110__time_putD2Ev@plt>:
   f15c0:      	adrp	x16, 0xfe000
   f15c4:      	ldr	x17, [x16, #0x198]
   f15c8:      	add	x16, x16, #0x198
   f15cc:      	br	x17

00000000000f15d0 <strtoll_l@plt>:
   f15d0:      	adrp	x16, 0xfe000
   f15d4:      	ldr	x17, [x16, #0x1a0]
   f15d8:      	add	x16, x16, #0x1a0
   f15dc:      	br	x17

00000000000f15e0 <strtoull_l@plt>:
   f15e0:      	adrp	x16, 0xfe000
   f15e4:      	ldr	x17, [x16, #0x1a8]
   f15e8:      	add	x16, x16, #0x1a8
   f15ec:      	br	x17

00000000000f15f0 <strtold_l@plt>:
   f15f0:      	adrp	x16, 0xfe000
   f15f4:      	ldr	x17, [x16, #0x1b0]
   f15f8:      	add	x16, x16, #0x1b0
   f15fc:      	br	x17

00000000000f1600 <__cxa_get_globals@plt>:
   f1600:      	adrp	x16, 0xfe000
   f1604:      	ldr	x17, [x16, #0x1b8]
   f1608:      	add	x16, x16, #0x1b8
   f160c:      	br	x17

00000000000f1610 <__cxa_get_globals_fast@plt>:
   f1610:      	adrp	x16, 0xfe000
   f1614:      	ldr	x17, [x16, #0x1c0]
   f1618:      	add	x16, x16, #0x1c0
   f161c:      	br	x17

00000000000f1620 <syscall@plt>:
   f1620:      	adrp	x16, 0xfe000
   f1624:      	ldr	x17, [x16, #0x1c8]
   f1628:      	add	x16, x16, #0x1c8
   f162c:      	br	x17

00000000000f1630 <_ZSt14get_unexpectedv@plt>:
   f1630:      	adrp	x16, 0xfe000
   f1634:      	ldr	x17, [x16, #0x1d0]
   f1638:      	add	x16, x16, #0x1d0
   f163c:      	br	x17

00000000000f1640 <_ZSt13get_terminatev@plt>:
   f1640:      	adrp	x16, 0xfe000
   f1644:      	ldr	x17, [x16, #0x1d8]
   f1648:      	add	x16, x16, #0x1d8
   f164c:      	br	x17

00000000000f1650 <_ZSt15get_new_handlerv@plt>:
   f1650:      	adrp	x16, 0xfe000
   f1654:      	ldr	x17, [x16, #0x1e0]
   f1658:      	add	x16, x16, #0x1e0
   f165c:      	br	x17

00000000000f1660 <__cxa_demangle@plt>:
   f1660:      	adrp	x16, 0xfe000
   f1664:      	ldr	x17, [x16, #0x1e8]
   f1668:      	add	x16, x16, #0x1e8
   f166c:      	br	x17

00000000000f1670 <__emutls_get_address@plt>:
   f1670:      	adrp	x16, 0xfe000
   f1674:      	ldr	x17, [x16, #0x1f0]
   f1678:      	add	x16, x16, #0x1f0
   f167c:      	br	x17

00000000000f1680 <_ZNSt9exceptionD1Ev@plt>:
   f1680:      	adrp	x16, 0xfe000
   f1684:      	ldr	x17, [x16, #0x1f8]
   f1688:      	add	x16, x16, #0x1f8
   f168c:      	br	x17

00000000000f1690 <_ZNSt13bad_exceptionD1Ev@plt>:
   f1690:      	adrp	x16, 0xfe000
   f1694:      	ldr	x17, [x16, #0x200]
   f1698:      	add	x16, x16, #0x200
   f169c:      	br	x17

00000000000f16a0 <_ZNSt11logic_errorD1Ev@plt>:
   f16a0:      	adrp	x16, 0xfe000
   f16a4:      	ldr	x17, [x16, #0x208]
   f16a8:      	add	x16, x16, #0x208
   f16ac:      	br	x17

00000000000f16b0 <_ZNSt12domain_errorD1Ev@plt>:
   f16b0:      	adrp	x16, 0xfe000
   f16b4:      	ldr	x17, [x16, #0x210]
   f16b8:      	add	x16, x16, #0x210
   f16bc:      	br	x17

00000000000f16c0 <_ZNSt11range_errorD1Ev@plt>:
   f16c0:      	adrp	x16, 0xfe000
   f16c4:      	ldr	x17, [x16, #0x218]
   f16c8:      	add	x16, x16, #0x218
   f16cc:      	br	x17

00000000000f16d0 <_ZNSt14overflow_errorD1Ev@plt>:
   f16d0:      	adrp	x16, 0xfe000
   f16d4:      	ldr	x17, [x16, #0x220]
   f16d8:      	add	x16, x16, #0x220
   f16dc:      	br	x17

00000000000f16e0 <_ZNSt15underflow_errorD1Ev@plt>:
   f16e0:      	adrp	x16, 0xfe000
   f16e4:      	ldr	x17, [x16, #0x228]
   f16e8:      	add	x16, x16, #0x228
   f16ec:      	br	x17

00000000000f16f0 <_ZNSt9type_infoD2Ev@plt>:
   f16f0:      	adrp	x16, 0xfe000
   f16f4:      	ldr	x17, [x16, #0x230]
   f16f8:      	add	x16, x16, #0x230
   f16fc:      	br	x17

00000000000f1700 <_ZNSt9type_infoD1Ev@plt>:
   f1700:      	adrp	x16, 0xfe000
   f1704:      	ldr	x17, [x16, #0x238]
   f1708:      	add	x16, x16, #0x238
   f170c:      	br	x17

00000000000f1710 <_ZNSt10bad_typeidD1Ev@plt>:
   f1710:      	adrp	x16, 0xfe000
   f1714:      	ldr	x17, [x16, #0x240]
   f1718:      	add	x16, x16, #0x240
   f171c:      	br	x17

00000000000f1720 <vfprintf@plt>:
   f1720:      	adrp	x16, 0xfe000
   f1724:      	ldr	x17, [x16, #0x248]
   f1728:      	add	x16, x16, #0x248
   f172c:      	br	x17

00000000000f1730 <fputc@plt>:
   f1730:      	adrp	x16, 0xfe000
   f1734:      	ldr	x17, [x16, #0x250]
   f1738:      	add	x16, x16, #0x250
   f173c:      	br	x17

00000000000f1740 <android_set_abort_message@plt>:
   f1740:      	adrp	x16, 0xfe000
   f1744:      	ldr	x17, [x16, #0x258]
   f1748:      	add	x16, x16, #0x258
   f174c:      	br	x17

00000000000f1750 <openlog@plt>:
   f1750:      	adrp	x16, 0xfe000
   f1754:      	ldr	x17, [x16, #0x260]
   f1758:      	add	x16, x16, #0x260
   f175c:      	br	x17

00000000000f1760 <syslog@plt>:
   f1760:      	adrp	x16, 0xfe000
   f1764:      	ldr	x17, [x16, #0x268]
   f1768:      	add	x16, x16, #0x268
   f176c:      	br	x17

00000000000f1770 <closelog@plt>:
   f1770:      	adrp	x16, 0xfe000
   f1774:      	ldr	x17, [x16, #0x270]
   f1778:      	add	x16, x16, #0x270
   f177c:      	br	x17

00000000000f1780 <__dynamic_cast@plt>:
   f1780:      	adrp	x16, 0xfe000
   f1784:      	ldr	x17, [x16, #0x278]
   f1788:      	add	x16, x16, #0x278
   f178c:      	br	x17

00000000000f1790 <_ZnwmSt11align_val_t@plt>:
   f1790:      	adrp	x16, 0xfe000
   f1794:      	ldr	x17, [x16, #0x280]
   f1798:      	add	x16, x16, #0x280
   f179c:      	br	x17

00000000000f17a0 <posix_memalign@plt>:
   f17a0:      	adrp	x16, 0xfe000
   f17a4:      	ldr	x17, [x16, #0x288]
   f17a8:      	add	x16, x16, #0x288
   f17ac:      	br	x17

00000000000f17b0 <_ZnamSt11align_val_t@plt>:
   f17b0:      	adrp	x16, 0xfe000
   f17b4:      	ldr	x17, [x16, #0x290]
   f17b8:      	add	x16, x16, #0x290
   f17bc:      	br	x17

00000000000f17c0 <_ZdlPvSt11align_val_t@plt>:
   f17c0:      	adrp	x16, 0xfe000
   f17c4:      	ldr	x17, [x16, #0x298]
   f17c8:      	add	x16, x16, #0x298
   f17cc:      	br	x17

00000000000f17d0 <_ZdaPvSt11align_val_t@plt>:
   f17d0:      	adrp	x16, 0xfe000
   f17d4:      	ldr	x17, [x16, #0x2a0]
   f17d8:      	add	x16, x16, #0x2a0
   f17dc:      	br	x17

00000000000f17e0 <__assert2@plt>:
   f17e0:      	adrp	x16, 0xfe000
   f17e4:      	ldr	x17, [x16, #0x2a8]
   f17e8:      	add	x16, x16, #0x2a8
   f17ec:      	br	x17

00000000000f17f0 <pthread_getspecific@plt>:
   f17f0:      	adrp	x16, 0xfe000
   f17f4:      	ldr	x17, [x16, #0x2b0]
   f17f8:      	add	x16, x16, #0x2b0
   f17fc:      	br	x17

00000000000f1800 <pthread_once@plt>:
   f1800:      	adrp	x16, 0xfe000
   f1804:      	ldr	x17, [x16, #0x2b8]
   f1808:      	add	x16, x16, #0x2b8
   f180c:      	br	x17

00000000000f1810 <pthread_setspecific@plt>:
   f1810:      	adrp	x16, 0xfe000
   f1814:      	ldr	x17, [x16, #0x2c0]
   f1818:      	add	x16, x16, #0x2c0
   f181c:      	br	x17

00000000000f1820 <pthread_key_delete@plt>:
   f1820:      	adrp	x16, 0xfe000
   f1824:      	ldr	x17, [x16, #0x2c8]
   f1828:      	add	x16, x16, #0x2c8
   f182c:      	br	x17

00000000000f1830 <pthread_key_create@plt>:
   f1830:      	adrp	x16, 0xfe000
   f1834:      	ldr	x17, [x16, #0x2d0]
   f1838:      	add	x16, x16, #0x2d0
   f183c:      	br	x17

00000000000f1840 <getauxval@plt>:
   f1840:      	adrp	x16, 0xfe000
   f1844:      	ldr	x17, [x16, #0x2d8]
   f1848:      	add	x16, x16, #0x2d8
   f184c:      	br	x17

00000000000f1850 <__system_property_get@plt>:
   f1850:      	adrp	x16, 0xfe000
   f1854:      	ldr	x17, [x16, #0x2e0]
   f1858:      	add	x16, x16, #0x2e0
   f185c:      	br	x17

00000000000f1860 <strncmp@plt>:
   f1860:      	adrp	x16, 0xfe000
   f1864:      	ldr	x17, [x16, #0x2e8]
   f1868:      	add	x16, x16, #0x2e8
   f186c:      	br	x17

00000000000f1870 <pthread_rwlock_wrlock@plt>:
   f1870:      	adrp	x16, 0xfe000
   f1874:      	ldr	x17, [x16, #0x2f0]
   f1878:      	add	x16, x16, #0x2f0
   f187c:      	br	x17

00000000000f1880 <pthread_rwlock_unlock@plt>:
   f1880:      	adrp	x16, 0xfe000
   f1884:      	ldr	x17, [x16, #0x2f8]
   f1888:      	add	x16, x16, #0x2f8
   f188c:      	br	x17

00000000000f1890 <dl_iterate_phdr@plt>:
   f1890:      	adrp	x16, 0xfe000
   f1894:      	ldr	x17, [x16, #0x300]
   f1898:      	add	x16, x16, #0x300
   f189c:      	br	x17

00000000000f18a0 <pthread_rwlock_rdlock@plt>:
   f18a0:      	adrp	x16, 0xfe000
   f18a4:      	ldr	x17, [x16, #0x308]
   f18a8:      	add	x16, x16, #0x308
   f18ac:      	br	x17

00000000000f18b0 <getpid@plt>:
   f18b0:      	adrp	x16, 0xfe000
   f18b4:      	ldr	x17, [x16, #0x310]
   f18b8:      	add	x16, x16, #0x310
   f18bc:      	br	x17
