// EXPORTED & PLT DISASSEMBLY FOR libCtaApiLib.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libCtaApiLib.so (SHA-256: 4A91CCAC45408DAA30E8DD60F7C6EEE68AEFFBDD66E1E9B6E435B1AA3377FCD5)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 217, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libCtaApiLib.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000000be20 <.plt>:
    be20:      	stp	x16, x30, [sp, #-0x10]!
    be24:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be28:      	ldr	x17, [x16, #0x740]
    be2c:      	add	x16, x16, #0x740
    be30:      	br	x17
    be34:      	nop
    be38:      	nop
    be3c:      	nop

000000000000be40 <strerror@plt>:
    be40:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be44:      	ldr	x17, [x16, #0x748]
    be48:      	add	x16, x16, #0x748
    be4c:      	br	x17

000000000000be50 <memcpy@plt>:
    be50:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be54:      	ldr	x17, [x16, #0x750]
    be58:      	add	x16, x16, #0x750
    be5c:      	br	x17

000000000000be60 <gettimeofday@plt>:
    be60:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be64:      	ldr	x17, [x16, #0x758]
    be68:      	add	x16, x16, #0x758
    be6c:      	br	x17

000000000000be70 <_Unwind_GetRegionStart@plt>:
    be70:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be74:      	ldr	x17, [x16, #0x760]
    be78:      	add	x16, x16, #0x760
    be7c:      	br	x17

000000000000be80 <memchr@plt>:
    be80:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be84:      	ldr	x17, [x16, #0x768]
    be88:      	add	x16, x16, #0x768
    be8c:      	br	x17

000000000000be90 <_ZSt14get_unexpectedv@plt>:
    be90:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    be94:      	ldr	x17, [x16, #0x770]
    be98:      	add	x16, x16, #0x770
    be9c:      	br	x17

000000000000bea0 <__ctype_get_mb_cur_max@plt>:
    bea0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bea4:      	ldr	x17, [x16, #0x778]
    bea8:      	add	x16, x16, #0x778
    beac:      	br	x17

000000000000beb0 <_ZNSt15__exception_ptr13exception_ptr4swapERS0_@plt>:
    beb0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    beb4:      	ldr	x17, [x16, #0x780]
    beb8:      	add	x16, x16, #0x780
    bebc:      	br	x17

000000000000bec0 <_Unwind_RaiseException@plt>:
    bec0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bec4:      	ldr	x17, [x16, #0x788]
    bec8:      	add	x16, x16, #0x788
    becc:      	br	x17

000000000000bed0 <towlower@plt>:
    bed0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bed4:      	ldr	x17, [x16, #0x790]
    bed8:      	add	x16, x16, #0x790
    bedc:      	br	x17

000000000000bee0 <mbrtowc@plt>:
    bee0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bee4:      	ldr	x17, [x16, #0x798]
    bee8:      	add	x16, x16, #0x798
    beec:      	br	x17

000000000000bef0 <_Unwind_SetIP@plt>:
    bef0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bef4:      	ldr	x17, [x16, #0x7a0]
    bef8:      	add	x16, x16, #0x7a0
    befc:      	br	x17

000000000000bf00 <_ZdlPv@plt>:
    bf00:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf04:      	ldr	x17, [x16, #0x7a8]
    bf08:      	add	x16, x16, #0x7a8
    bf0c:      	br	x17

000000000000bf10 <btowc@plt>:
    bf10:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf14:      	ldr	x17, [x16, #0x7b0]
    bf18:      	add	x16, x16, #0x7b0
    bf1c:      	br	x17

000000000000bf20 <_Unwind_GetLanguageSpecificData@plt>:
    bf20:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf24:      	ldr	x17, [x16, #0x7b8]
    bf28:      	add	x16, x16, #0x7b8
    bf2c:      	br	x17

000000000000bf30 <_Znam@plt>:
    bf30:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf34:      	ldr	x17, [x16, #0x7c0]
    bf38:      	add	x16, x16, #0x7c0
    bf3c:      	br	x17

000000000000bf40 <wmemmove@plt>:
    bf40:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf44:      	ldr	x17, [x16, #0x7c8]
    bf48:      	add	x16, x16, #0x7c8
    bf4c:      	br	x17

000000000000bf50 <strftime@plt>:
    bf50:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf54:      	ldr	x17, [x16, #0x7d0]
    bf58:      	add	x16, x16, #0x7d0
    bf5c:      	br	x17

000000000000bf60 <__cxa_end_catch@plt>:
    bf60:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf64:      	ldr	x17, [x16, #0x7d8]
    bf68:      	add	x16, x16, #0x7d8
    bf6c:      	br	x17

000000000000bf70 <__cxa_allocate_exception@plt>:
    bf70:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf74:      	ldr	x17, [x16, #0x7e0]
    bf78:      	add	x16, x16, #0x7e0
    bf7c:      	br	x17

000000000000bf80 <_ZNSt15__exception_ptr13exception_ptrC1EPv@plt>:
    bf80:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf84:      	ldr	x17, [x16, #0x7e8]
    bf88:      	add	x16, x16, #0x7e8
    bf8c:      	br	x17

000000000000bf90 <wcslen@plt>:
    bf90:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bf94:      	ldr	x17, [x16, #0x7f0]
    bf98:      	add	x16, x16, #0x7f0
    bf9c:      	br	x17

000000000000bfa0 <_ZSt15get_new_handlerv@plt>:
    bfa0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bfa4:      	ldr	x17, [x16, #0x7f8]
    bfa8:      	add	x16, x16, #0x7f8
    bfac:      	br	x17

000000000000bfb0 <_ZNSt15__exception_ptreqERKNS_13exception_ptrES2_@plt>:
    bfb0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bfb4:      	ldr	x17, [x16, #0x800]
    bfb8:      	add	x16, x16, #0x800
    bfbc:      	br	x17

000000000000bfc0 <_ZNSt9bad_allocD1Ev@plt>:
    bfc0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bfc4:      	ldr	x17, [x16, #0x808]
    bfc8:      	add	x16, x16, #0x808
    bfcc:      	br	x17

000000000000bfd0 <free@plt>:
    bfd0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bfd4:      	ldr	x17, [x16, #0x810]
    bfd8:      	add	x16, x16, #0x810
    bfdc:      	br	x17

000000000000bfe0 <strtold@plt>:
    bfe0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bfe4:      	ldr	x17, [x16, #0x818]
    bfe8:      	add	x16, x16, #0x818
    bfec:      	br	x17

000000000000bff0 <pthread_key_delete@plt>:
    bff0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    bff4:      	ldr	x17, [x16, #0x820]
    bff8:      	add	x16, x16, #0x820
    bffc:      	br	x17

000000000000c000 <strcmp@plt>:
    c000:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c004:      	ldr	x17, [x16, #0x828]
    c008:      	add	x16, x16, #0x828
    c00c:      	br	x17

000000000000c010 <malloc@plt>:
    c010:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c014:      	ldr	x17, [x16, #0x830]
    c018:      	add	x16, x16, #0x830
    c01c:      	br	x17

000000000000c020 <_ZNSt3mapISsSsSt4lessISsESaISt4pairIKSsSsEEEixERS3_@plt>:
    c020:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c024:      	ldr	x17, [x16, #0x838]
    c028:      	add	x16, x16, #0x838
    c02c:      	br	x17

000000000000c030 <strxfrm@plt>:
    c030:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c034:      	ldr	x17, [x16, #0x840]
    c038:      	add	x16, x16, #0x840
    c03c:      	br	x17

000000000000c040 <wmemset@plt>:
    c040:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c044:      	ldr	x17, [x16, #0x848]
    c048:      	add	x16, x16, #0x848
    c04c:      	br	x17

000000000000c050 <_Unwind_GetTextRelBase@plt>:
    c050:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c054:      	ldr	x17, [x16, #0x850]
    c058:      	add	x16, x16, #0x850
    c05c:      	br	x17

000000000000c060 <_ZNKSt15__exception_ptr13exception_ptr6_M_getEv@plt>:
    c060:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c064:      	ldr	x17, [x16, #0x858]
    c068:      	add	x16, x16, #0x858
    c06c:      	br	x17

000000000000c070 <sprintf@plt>:
    c070:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c074:      	ldr	x17, [x16, #0x860]
    c078:      	add	x16, x16, #0x860
    c07c:      	br	x17

000000000000c080 <_ZNSt13bad_exceptionD1Ev@plt>:
    c080:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c084:      	ldr	x17, [x16, #0x868]
    c088:      	add	x16, x16, #0x868
    c08c:      	br	x17

000000000000c090 <rand@plt>:
    c090:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c094:      	ldr	x17, [x16, #0x870]
    c098:      	add	x16, x16, #0x870
    c09c:      	br	x17

000000000000c0a0 <__deregister_frame_info_bases@plt>:
    c0a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c0a4:      	ldr	x17, [x16, #0x878]
    c0a8:      	add	x16, x16, #0x878
    c0ac:      	br	x17

000000000000c0b0 <_Unwind_Resume_or_Rethrow@plt>:
    c0b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c0b4:      	ldr	x17, [x16, #0x880]
    c0b8:      	add	x16, x16, #0x880
    c0bc:      	br	x17

000000000000c0c0 <pthread_setspecific@plt>:
    c0c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c0c4:      	ldr	x17, [x16, #0x888]
    c0c8:      	add	x16, x16, #0x888
    c0cc:      	br	x17

000000000000c0d0 <_ZN10__cxxabiv119__foreign_exceptionD1Ev@plt>:
    c0d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c0d4:      	ldr	x17, [x16, #0x890]
    c0d8:      	add	x16, x16, #0x890
    c0dc:      	br	x17

000000000000c0e0 <__cxa_get_globals_fast@plt>:
    c0e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c0e4:      	ldr	x17, [x16, #0x898]
    c0e8:      	add	x16, x16, #0x898
    c0ec:      	br	x17

000000000000c0f0 <__cxa_guard_release@plt>:
    c0f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c0f4:      	ldr	x17, [x16, #0x8a0]
    c0f8:      	add	x16, x16, #0x8a0
    c0fc:      	br	x17

000000000000c100 <memmove@plt>:
    c100:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c104:      	ldr	x17, [x16, #0x8a8]
    c108:      	add	x16, x16, #0x8a8
    c10c:      	br	x17

000000000000c110 <_ZSt13get_terminatev@plt>:
    c110:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c114:      	ldr	x17, [x16, #0x8b0]
    c118:      	add	x16, x16, #0x8b0
    c11c:      	br	x17

000000000000c120 <pthread_once@plt>:
    c120:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c124:      	ldr	x17, [x16, #0x8b8]
    c128:      	add	x16, x16, #0x8b8
    c12c:      	br	x17

000000000000c130 <__google_potentially_blocking_region_end@plt>:
    c130:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c134:      	ldr	x17, [x16, #0x8c0]
    c138:      	add	x16, x16, #0x8c0
    c13c:      	br	x17

000000000000c140 <_ZNSt16bad_array_lengthD1Ev@plt>:
    c140:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c144:      	ldr	x17, [x16, #0x8c8]
    c148:      	add	x16, x16, #0x8c8
    c14c:      	br	x17

000000000000c150 <_ZNSt15__exception_ptr13exception_ptrC1ERKS0_@plt>:
    c150:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c154:      	ldr	x17, [x16, #0x8d0]
    c158:      	add	x16, x16, #0x8d0
    c15c:      	br	x17

000000000000c160 <_ZNSt10bad_typeidD1Ev@plt>:
    c160:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c164:      	ldr	x17, [x16, #0x8d8]
    c168:      	add	x16, x16, #0x8d8
    c16c:      	br	x17

000000000000c170 <strlen@plt>:
    c170:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c174:      	ldr	x17, [x16, #0x8e0]
    c178:      	add	x16, x16, #0x8e0
    c17c:      	br	x17

000000000000c180 <wcscoll@plt>:
    c180:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c184:      	ldr	x17, [x16, #0x8e8]
    c188:      	add	x16, x16, #0x8e8
    c18c:      	br	x17

000000000000c190 <_ZNSt15__exception_ptr13exception_ptr9_M_addrefEv@plt>:
    c190:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c194:      	ldr	x17, [x16, #0x8f0]
    c198:      	add	x16, x16, #0x8f0
    c19c:      	br	x17

000000000000c1a0 <_Unwind_GetCFA@plt>:
    c1a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c1a4:      	ldr	x17, [x16, #0x8f8]
    c1a8:      	add	x16, x16, #0x8f8
    c1ac:      	br	x17

000000000000c1b0 <_ZNSt8bad_castD1Ev@plt>:
    c1b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c1b4:      	ldr	x17, [x16, #0x900]
    c1b8:      	add	x16, x16, #0x900
    c1bc:      	br	x17

000000000000c1c0 <realloc@plt>:
    c1c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c1c4:      	ldr	x17, [x16, #0x908]
    c1c8:      	add	x16, x16, #0x908
    c1cc:      	br	x17

000000000000c1d0 <iswctype@plt>:
    c1d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c1d4:      	ldr	x17, [x16, #0x910]
    c1d8:      	add	x16, x16, #0x910
    c1dc:      	br	x17

000000000000c1e0 <strtod@plt>:
    c1e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c1e4:      	ldr	x17, [x16, #0x918]
    c1e8:      	add	x16, x16, #0x918
    c1ec:      	br	x17

000000000000c1f0 <wcsftime@plt>:
    c1f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c1f4:      	ldr	x17, [x16, #0x920]
    c1f8:      	add	x16, x16, #0x920
    c1fc:      	br	x17

000000000000c200 <__register_frame_info_table_bases@plt>:
    c200:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c204:      	ldr	x17, [x16, #0x928]
    c208:      	add	x16, x16, #0x928
    c20c:      	br	x17

000000000000c210 <__cxa_free_dependent_exception@plt>:
    c210:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c214:      	ldr	x17, [x16, #0x930]
    c218:      	add	x16, x16, #0x930
    c21c:      	br	x17

000000000000c220 <wctype@plt>:
    c220:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c224:      	ldr	x17, [x16, #0x938]
    c228:      	add	x16, x16, #0x938
    c22c:      	br	x17

000000000000c230 <__sfp_handle_exceptions@plt>:
    c230:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c234:      	ldr	x17, [x16, #0x940]
    c238:      	add	x16, x16, #0x940
    c23c:      	br	x17

000000000000c240 <strncmp@plt>:
    c240:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c244:      	ldr	x17, [x16, #0x948]
    c248:      	add	x16, x16, #0x948
    c24c:      	br	x17

000000000000c250 <srand@plt>:
    c250:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c254:      	ldr	x17, [x16, #0x950]
    c258:      	add	x16, x16, #0x950
    c25c:      	br	x17

000000000000c260 <fputc@plt>:
    c260:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c264:      	ldr	x17, [x16, #0x958]
    c268:      	add	x16, x16, #0x958
    c26c:      	br	x17

000000000000c270 <__gttf2@plt>:
    c270:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c274:      	ldr	x17, [x16, #0x960]
    c278:      	add	x16, x16, #0x960
    c27c:      	br	x17

000000000000c280 <wmemcpy@plt>:
    c280:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c284:      	ldr	x17, [x16, #0x968]
    c288:      	add	x16, x16, #0x968
    c28c:      	br	x17

000000000000c290 <__cxa_bad_cast@plt>:
    c290:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c294:      	ldr	x17, [x16, #0x970]
    c298:      	add	x16, x16, #0x970
    c29c:      	br	x17

000000000000c2a0 <_Unwind_GetIPInfo@plt>:
    c2a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c2a4:      	ldr	x17, [x16, #0x978]
    c2a8:      	add	x16, x16, #0x978
    c2ac:      	br	x17

000000000000c2b0 <_ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE14_M_create_nodeIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEEPSt13_Rb_tree_nodeIS2_EDpOT_@plt>:
    c2b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c2b4:      	ldr	x17, [x16, #0x980]
    c2b8:      	add	x16, x16, #0x980
    c2bc:      	br	x17

000000000000c2c0 <_ZN10__cxxabiv121__vmi_class_type_infoD1Ev@plt>:
    c2c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c2c4:      	ldr	x17, [x16, #0x988]
    c2c8:      	add	x16, x16, #0x988
    c2cc:      	br	x17

000000000000c2d0 <_ZNSt9bad_allocD2Ev@plt>:
    c2d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c2d4:      	ldr	x17, [x16, #0x990]
    c2d8:      	add	x16, x16, #0x990
    c2dc:      	br	x17

000000000000c2e0 <_ZN10__cxxabiv117__class_type_infoD2Ev@plt>:
    c2e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c2e4:      	ldr	x17, [x16, #0x998]
    c2e8:      	add	x16, x16, #0x998
    c2ec:      	br	x17

000000000000c2f0 <__android_log_print@plt>:
    c2f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c2f4:      	ldr	x17, [x16, #0x9a0]
    c2f8:      	add	x16, x16, #0x9a0
    c2fc:      	br	x17

000000000000c300 <towupper@plt>:
    c300:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c304:      	ldr	x17, [x16, #0x9a8]
    c308:      	add	x16, x16, #0x9a8
    c30c:      	br	x17

000000000000c310 <pthread_mutex_unlock@plt>:
    c310:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c314:      	ldr	x17, [x16, #0x9b0]
    c318:      	add	x16, x16, #0x9b0
    c31c:      	br	x17

000000000000c320 <__dynamic_cast@plt>:
    c320:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c324:      	ldr	x17, [x16, #0x9b8]
    c328:      	add	x16, x16, #0x9b8
    c32c:      	br	x17

000000000000c330 <strcoll@plt>:
    c330:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c334:      	ldr	x17, [x16, #0x9c0]
    c338:      	add	x16, x16, #0x9c0
    c33c:      	br	x17

000000000000c340 <__cxa_get_globals@plt>:
    c340:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c344:      	ldr	x17, [x16, #0x9c8]
    c348:      	add	x16, x16, #0x9c8
    c34c:      	br	x17

000000000000c350 <wctob@plt>:
    c350:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c354:      	ldr	x17, [x16, #0x9d0]
    c358:      	add	x16, x16, #0x9d0
    c35c:      	br	x17

000000000000c360 <fwrite@plt>:
    c360:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c364:      	ldr	x17, [x16, #0x9d8]
    c368:      	add	x16, x16, #0x9d8
    c36c:      	br	x17

000000000000c370 <_ZdaPv@plt>:
    c370:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c374:      	ldr	x17, [x16, #0x9e0]
    c378:      	add	x16, x16, #0x9e0
    c37c:      	br	x17

000000000000c380 <_Unwind_Find_FDE@plt>:
    c380:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c384:      	ldr	x17, [x16, #0x9e8]
    c388:      	add	x16, x16, #0x9e8
    c38c:      	br	x17

000000000000c390 <syscall@plt>:
    c390:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c394:      	ldr	x17, [x16, #0x9f0]
    c398:      	add	x16, x16, #0x9f0
    c39c:      	br	x17

000000000000c3a0 <memset@plt>:
    c3a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c3a4:      	ldr	x17, [x16, #0x9f8]
    c3a8:      	add	x16, x16, #0x9f8
    c3ac:      	br	x17

000000000000c3b0 <__register_frame_info_table@plt>:
    c3b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c3b4:      	ldr	x17, [x16, #0xa00]
    c3b8:      	add	x16, x16, #0xa00
    c3bc:      	br	x17

000000000000c3c0 <_ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE8_M_eraseEPSt13_Rb_tree_nodeIS2_E@plt>:
    c3c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c3c4:      	ldr	x17, [x16, #0xa08]
    c3c8:      	add	x16, x16, #0xa08
    c3cc:      	br	x17

000000000000c3d0 <__google_potentially_blocking_region_begin@plt>:
    c3d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c3d4:      	ldr	x17, [x16, #0xa10]
    c3d8:      	add	x16, x16, #0xa10
    c3dc:      	br	x17

000000000000c3e0 <__deregister_frame_info@plt>:
    c3e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c3e4:      	ldr	x17, [x16, #0xa18]
    c3e8:      	add	x16, x16, #0xa18
    c3ec:      	br	x17

000000000000c3f0 <__lttf2@plt>:
    c3f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c3f4:      	ldr	x17, [x16, #0xa20]
    c3f8:      	add	x16, x16, #0xa20
    c3fc:      	br	x17

000000000000c400 <pthread_getspecific@plt>:
    c400:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c404:      	ldr	x17, [x16, #0xa28]
    c408:      	add	x16, x16, #0xa28
    c40c:      	br	x17

000000000000c410 <wmemchr@plt>:
    c410:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c414:      	ldr	x17, [x16, #0xa30]
    c418:      	add	x16, x16, #0xa30
    c41c:      	br	x17

000000000000c420 <__register_frame_info@plt>:
    c420:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c424:      	ldr	x17, [x16, #0xa38]
    c428:      	add	x16, x16, #0xa38
    c42c:      	br	x17

000000000000c430 <_ZNSt15__exception_ptr13exception_ptrC1Ev@plt>:
    c430:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c434:      	ldr	x17, [x16, #0xa40]
    c438:      	add	x16, x16, #0xa40
    c43c:      	br	x17

000000000000c440 <_ZNSt20bad_array_new_lengthD1Ev@plt>:
    c440:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c444:      	ldr	x17, [x16, #0xa48]
    c448:      	add	x16, x16, #0xa48
    c44c:      	br	x17

000000000000c450 <__cxa_begin_catch@plt>:
    c450:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c454:      	ldr	x17, [x16, #0xa50]
    c458:      	add	x16, x16, #0xa50
    c45c:      	br	x17

000000000000c460 <__cxa_rethrow@plt>:
    c460:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c464:      	ldr	x17, [x16, #0xa58]
    c468:      	add	x16, x16, #0xa58
    c46c:      	br	x17

000000000000c470 <abort@plt>:
    c470:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c474:      	ldr	x17, [x16, #0xa60]
    c478:      	add	x16, x16, #0xa60
    c47c:      	br	x17

000000000000c480 <__cxa_throw@plt>:
    c480:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c484:      	ldr	x17, [x16, #0xa68]
    c488:      	add	x16, x16, #0xa68
    c48c:      	br	x17

000000000000c490 <__cxa_atexit@plt>:
    c490:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c494:      	ldr	x17, [x16, #0xa70]
    c498:      	add	x16, x16, #0xa70
    c49c:      	br	x17

000000000000c4a0 <__register_frame_info_bases@plt>:
    c4a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c4a4:      	ldr	x17, [x16, #0xa78]
    c4a8:      	add	x16, x16, #0xa78
    c4ac:      	br	x17

000000000000c4b0 <_ZN10__cxxabiv120__si_class_type_infoD1Ev@plt>:
    c4b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c4b4:      	ldr	x17, [x16, #0xa80]
    c4b8:      	add	x16, x16, #0xa80
    c4bc:      	br	x17

000000000000c4c0 <_ZNSt15__exception_ptr13exception_ptr10_M_releaseEv@plt>:
    c4c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c4c4:      	ldr	x17, [x16, #0xa88]
    c4c8:      	add	x16, x16, #0xa88
    c4cc:      	br	x17

000000000000c4d0 <_ZN10__cxxabiv111__terminateEPFvvE@plt>:
    c4d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c4d4:      	ldr	x17, [x16, #0xa90]
    c4d8:      	add	x16, x16, #0xa90
    c4dc:      	br	x17

000000000000c4e0 <_Unwind_Resume@plt>:
    c4e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c4e4:      	ldr	x17, [x16, #0xa98]
    c4e8:      	add	x16, x16, #0xa98
    c4ec:      	br	x17

000000000000c4f0 <__cxa_current_exception_type@plt>:
    c4f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c4f4:      	ldr	x17, [x16, #0xaa0]
    c4f8:      	add	x16, x16, #0xaa0
    c4fc:      	br	x17

000000000000c500 <_ZSt14__convert_to_vIdEvPKcRT_RSt12_Ios_IostateRKPi@plt>:
    c500:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c504:      	ldr	x17, [x16, #0xaa8]
    c508:      	add	x16, x16, #0xaa8
    c50c:      	br	x17

000000000000c510 <_ZN10__cxxabiv115__forced_unwindD1Ev@plt>:
    c510:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c514:      	ldr	x17, [x16, #0xab0]
    c518:      	add	x16, x16, #0xab0
    c51c:      	br	x17

000000000000c520 <memcmp@plt>:
    c520:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c524:      	ldr	x17, [x16, #0xab8]
    c528:      	add	x16, x16, #0xab8
    c52c:      	br	x17

000000000000c530 <write@plt>:
    c530:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c534:      	ldr	x17, [x16, #0xac0]
    c538:      	add	x16, x16, #0xac0
    c53c:      	br	x17

000000000000c540 <_ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE29_M_get_insert_hint_unique_posESt23_Rb_tree_const_iteratorIS2_ERS1_@plt>:
    c540:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c544:      	ldr	x17, [x16, #0xac8]
    c548:      	add	x16, x16, #0xac8
    c54c:      	br	x17

000000000000c550 <_ZNSt9exceptionD2Ev@plt>:
    c550:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c554:      	ldr	x17, [x16, #0xad0]
    c558:      	add	x16, x16, #0xad0
    c55c:      	br	x17

000000000000c560 <wcrtomb@plt>:
    c560:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c564:      	ldr	x17, [x16, #0xad8]
    c568:      	add	x16, x16, #0xad8
    c56c:      	br	x17

000000000000c570 <_ZN9__gnu_cxx20recursive_init_errorD1Ev@plt>:
    c570:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c574:      	ldr	x17, [x16, #0xae0]
    c578:      	add	x16, x16, #0xae0
    c57c:      	br	x17

000000000000c580 <pthread_mutex_lock@plt>:
    c580:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c584:      	ldr	x17, [x16, #0xae8]
    c588:      	add	x16, x16, #0xae8
    c58c:      	br	x17

000000000000c590 <_ZNK10__cxxabiv117__class_type_info11__do_upcastEPKS0_PKvRNS0_15__upcast_resultE@plt>:
    c590:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c594:      	ldr	x17, [x16, #0xaf0]
    c598:      	add	x16, x16, #0xaf0
    c59c:      	br	x17

000000000000c5a0 <_Znwm@plt>:
    c5a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c5a4:      	ldr	x17, [x16, #0xaf8]
    c5a8:      	add	x16, x16, #0xaf8
    c5ac:      	br	x17

000000000000c5b0 <_Unwind_SetGR@plt>:
    c5b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c5b4:      	ldr	x17, [x16, #0xb00]
    c5b8:      	add	x16, x16, #0xb00
    c5bc:      	br	x17

000000000000c5c0 <_ZNSt15__exception_ptr13exception_ptrD1Ev@plt>:
    c5c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c5c4:      	ldr	x17, [x16, #0xb08]
    c5c8:      	add	x16, x16, #0xb08
    c5cc:      	br	x17

000000000000c5d0 <__cxa_finalize@plt>:
    c5d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c5d4:      	ldr	x17, [x16, #0xb10]
    c5d8:      	add	x16, x16, #0xb10
    c5dc:      	br	x17

000000000000c5e0 <_ZN10__cxxabiv112__unexpectedEPFvvE@plt>:
    c5e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c5e4:      	ldr	x17, [x16, #0xb18]
    c5e8:      	add	x16, x16, #0xb18
    c5ec:      	br	x17

000000000000c5f0 <__cxa_allocate_dependent_exception@plt>:
    c5f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c5f4:      	ldr	x17, [x16, #0xb20]
    c5f8:      	add	x16, x16, #0xb20
    c5fc:      	br	x17

000000000000c600 <_ZNSt9exceptionD1Ev@plt>:
    c600:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c604:      	ldr	x17, [x16, #0xb28]
    c608:      	add	x16, x16, #0xb28
    c60c:      	br	x17

000000000000c610 <pthread_key_create@plt>:
    c610:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c614:      	ldr	x17, [x16, #0xb30]
    c618:      	add	x16, x16, #0xb30
    c61c:      	br	x17

000000000000c620 <time@plt>:
    c620:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c624:      	ldr	x17, [x16, #0xb38]
    c628:      	add	x16, x16, #0xb38
    c62c:      	br	x17

000000000000c630 <__stack_chk_fail@plt>:
    c630:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c634:      	ldr	x17, [x16, #0xb40]
    c638:      	add	x16, x16, #0xb40
    c63c:      	br	x17

000000000000c640 <wcsxfrm@plt>:
    c640:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c644:      	ldr	x17, [x16, #0xb48]
    c648:      	add	x16, x16, #0xb48
    c64c:      	br	x17

000000000000c650 <_ZSt10unexpectedv@plt>:
    c650:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c654:      	ldr	x17, [x16, #0xb50]
    c658:      	add	x16, x16, #0xb50
    c65c:      	br	x17

000000000000c660 <strtof@plt>:
    c660:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c664:      	ldr	x17, [x16, #0xb58]
    c668:      	add	x16, x16, #0xb58
    c66c:      	br	x17

000000000000c670 <fputs@plt>:
    c670:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c674:      	ldr	x17, [x16, #0xb60]
    c678:      	add	x16, x16, #0xb60
    c67c:      	br	x17

000000000000c680 <__cxa_demangle@plt>:
    c680:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c684:      	ldr	x17, [x16, #0xb68]
    c688:      	add	x16, x16, #0xb68
    c68c:      	br	x17

000000000000c690 <_ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESD_IJEEEEESt17_Rb_tree_iteratorIS2_ESt23_Rb_tree_const_iteratorIS2_EDpOT_@plt>:
    c690:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c694:      	ldr	x17, [x16, #0xb70]
    c698:      	add	x16, x16, #0xb70
    c69c:      	br	x17

000000000000c6a0 <_ZSt9terminatev@plt>:
    c6a0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c6a4:      	ldr	x17, [x16, #0xb78]
    c6a8:      	add	x16, x16, #0xb78
    c6ac:      	br	x17

000000000000c6b0 <setlocale@plt>:
    c6b0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c6b4:      	ldr	x17, [x16, #0xb80]
    c6b8:      	add	x16, x16, #0xb80
    c6bc:      	br	x17

000000000000c6c0 <_ZN10__cxxabiv117__class_type_infoD1Ev@plt>:
    c6c0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c6c4:      	ldr	x17, [x16, #0xb88]
    c6c8:      	add	x16, x16, #0xb88
    c6cc:      	br	x17

000000000000c6d0 <_ZSt14__convert_to_vIfEvPKcRT_RSt12_Ios_IostateRKPi@plt>:
    c6d0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c6d4:      	ldr	x17, [x16, #0xb90]
    c6d8:      	add	x16, x16, #0xb90
    c6dc:      	br	x17

000000000000c6e0 <dl_iterate_phdr@plt>:
    c6e0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c6e4:      	ldr	x17, [x16, #0xb98]
    c6e8:      	add	x16, x16, #0xb98
    c6ec:      	br	x17

000000000000c6f0 <_ZSt18uncaught_exceptionv@plt>:
    c6f0:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c6f4:      	ldr	x17, [x16, #0xba0]
    c6f8:      	add	x16, x16, #0xba0
    c6fc:      	br	x17

000000000000c700 <__cxa_call_unexpected@plt>:
    c700:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c704:      	ldr	x17, [x16, #0xba8]
    c708:      	add	x16, x16, #0xba8
    c70c:      	br	x17

000000000000c710 <vsprintf@plt>:
    c710:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c714:      	ldr	x17, [x16, #0xbb0]
    c718:      	add	x16, x16, #0xbb0
    c71c:      	br	x17

000000000000c720 <_ZSt14__convert_to_vIeEvPKcRT_RSt12_Ios_IostateRKPi@plt>:
    c720:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c724:      	ldr	x17, [x16, #0xbb8]
    c728:      	add	x16, x16, #0xbb8
    c72c:      	br	x17

000000000000c730 <__cxa_free_exception@plt>:
    c730:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c734:      	ldr	x17, [x16, #0xbc0]
    c738:      	add	x16, x16, #0xbc0
    c73c:      	br	x17

000000000000c740 <_Unwind_DeleteException@plt>:
    c740:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c744:      	ldr	x17, [x16, #0xbc8]
    c748:      	add	x16, x16, #0xbc8
    c74c:      	br	x17

000000000000c750 <__cxa_guard_acquire@plt>:
    c750:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c754:      	ldr	x17, [x16, #0xbd0]
    c758:      	add	x16, x16, #0xbd0
    c75c:      	br	x17

000000000000c760 <_Unwind_GetDataRelBase@plt>:
    c760:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c764:      	ldr	x17, [x16, #0xbd8]
    c768:      	add	x16, x16, #0xbd8
    c76c:      	br	x17

000000000000c770 <_ZNSt8_Rb_treeISsSt4pairIKSsSsESt10_Select1stIS2_ESt4lessISsESaIS2_EE24_M_get_insert_unique_posERS1_@plt>:
    c770:      	adrp	x16, 0x87000 <_ZTVN10__cxxabiv121__vmi_class_type_infoE+0x7d0>
    c774:      	ldr	x17, [x16, #0xbe0]
    c778:      	add	x16, x16, #0xbe0
    c77c:      	br	x17
