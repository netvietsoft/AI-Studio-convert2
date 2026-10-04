// EXPORTED & PLT DISASSEMBLY FOR libhiai.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhiai.so (SHA-256: 30A096C17346403D98A32A1A4D0762FA8E220F6C40E65AEC9460CDFD6C7418EE)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 425, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhiai.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000006bde0 <.plt>:
   6bde0:      	stp	x16, x30, [sp, #-0x10]!
   6bde4:      	adrp	x16, 0x73000
   6bde8:      	ldr	x17, [x16, #0x6f8]
   6bdec:      	add	x16, x16, #0x6f8
   6bdf0:      	br	x17
   6bdf4:      	nop
   6bdf8:      	nop
   6bdfc:      	nop

000000000006be00 <__cxa_finalize@plt>:
   6be00:      	adrp	x16, 0x73000
   6be04:      	ldr	x17, [x16, #0x700]
   6be08:      	add	x16, x16, #0x700
   6be0c:      	br	x17

000000000006be10 <__cxa_atexit@plt>:
   6be10:      	adrp	x16, 0x73000
   6be14:      	ldr	x17, [x16, #0x708]
   6be18:      	add	x16, x16, #0x708
   6be1c:      	br	x17

000000000006be20 <_ZdlPv@plt>:
   6be20:      	adrp	x16, 0x73000
   6be24:      	ldr	x17, [x16, #0x710]
   6be28:      	add	x16, x16, #0x710
   6be2c:      	br	x17

000000000006be30 <_Znwm@plt>:
   6be30:      	adrp	x16, 0x73000
   6be34:      	ldr	x17, [x16, #0x718]
   6be38:      	add	x16, x16, #0x718
   6be3c:      	br	x17

000000000006be40 <__stack_chk_fail@plt>:
   6be40:      	adrp	x16, 0x73000
   6be44:      	ldr	x17, [x16, #0x720]
   6be48:      	add	x16, x16, #0x720
   6be4c:      	br	x17

000000000006be50 <__cxa_guard_acquire@plt>:
   6be50:      	adrp	x16, 0x73000
   6be54:      	ldr	x17, [x16, #0x728]
   6be58:      	add	x16, x16, #0x728
   6be5c:      	br	x17

000000000006be60 <__cxa_guard_release@plt>:
   6be60:      	adrp	x16, 0x73000
   6be64:      	ldr	x17, [x16, #0x730]
   6be68:      	add	x16, x16, #0x730
   6be6c:      	br	x17

000000000006be70 <_ZnwmRKSt9nothrow_t@plt>:
   6be70:      	adrp	x16, 0x73000
   6be74:      	ldr	x17, [x16, #0x738]
   6be78:      	add	x16, x16, #0x738
   6be7c:      	br	x17

000000000006be80 <__strrchr_chk@plt>:
   6be80:      	adrp	x16, 0x73000
   6be84:      	ldr	x17, [x16, #0x740]
   6be88:      	add	x16, x16, #0x740
   6be8c:      	br	x17

000000000006be90 <AI_Log_Print@plt>:
   6be90:      	adrp	x16, 0x73000
   6be94:      	ldr	x17, [x16, #0x748]
   6be98:      	add	x16, x16, #0x748
   6be9c:      	br	x17

000000000006bea0 <strlen@plt>:
   6bea0:      	adrp	x16, 0x73000
   6bea4:      	ldr	x17, [x16, #0x750]
   6bea8:      	add	x16, x16, #0x750
   6beac:      	br	x17

000000000006beb0 <memmove@plt>:
   6beb0:      	adrp	x16, 0x73000
   6beb4:      	ldr	x17, [x16, #0x758]
   6beb8:      	add	x16, x16, #0x758
   6bebc:      	br	x17

000000000006bec0 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
   6bec0:      	adrp	x16, 0x73000
   6bec4:      	ldr	x17, [x16, #0x760]
   6bec8:      	add	x16, x16, #0x760
   6becc:      	br	x17

000000000006bed0 <HIAI_MR_ModelBuildOptions_GetFormatModeOption@plt>:
   6bed0:      	adrp	x16, 0x73000
   6bed4:      	ldr	x17, [x16, #0x768]
   6bed8:      	add	x16, x16, #0x768
   6bedc:      	br	x17

000000000006bee0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   6bee0:      	adrp	x16, 0x73000
   6bee4:      	ldr	x17, [x16, #0x770]
   6bee8:      	add	x16, x16, #0x770
   6beec:      	br	x17

000000000006bef0 <HIAI_MR_ModelBuildOptions_GetTuningConfig@plt>:
   6bef0:      	adrp	x16, 0x73000
   6bef4:      	ldr	x17, [x16, #0x778]
   6bef8:      	add	x16, x16, #0x778
   6befc:      	br	x17

000000000006bf00 <HIAI_MR_TuningConfig_GetTuningMode@plt>:
   6bf00:      	adrp	x16, 0x73000
   6bf04:      	ldr	x17, [x16, #0x780]
   6bf08:      	add	x16, x16, #0x780
   6bf0c:      	br	x17

000000000006bf10 <_ZnamRKSt9nothrow_t@plt>:
   6bf10:      	adrp	x16, 0x73000
   6bf14:      	ldr	x17, [x16, #0x788]
   6bf18:      	add	x16, x16, #0x788
   6bf1c:      	br	x17

000000000006bf20 <memset@plt>:
   6bf20:      	adrp	x16, 0x73000
   6bf24:      	ldr	x17, [x16, #0x790]
   6bf28:      	add	x16, x16, #0x790
   6bf2c:      	br	x17

000000000006bf30 <_ZN4hiai13ModelTypeUtil12GetModelTypeEPKvmRNS_9ModelTypeE@plt>:
   6bf30:      	adrp	x16, 0x73000
   6bf34:      	ldr	x17, [x16, #0x798]
   6bf38:      	add	x16, x16, #0x798
   6bf3c:      	br	x17

000000000006bf40 <HIAI_MR_ModelBuildOptions_GetEstimatedOutputSize@plt>:
   6bf40:      	adrp	x16, 0x73000
   6bf44:      	ldr	x17, [x16, #0x7a0]
   6bf48:      	add	x16, x16, #0x7a0
   6bf4c:      	br	x17

000000000006bf50 <malloc@plt>:
   6bf50:      	adrp	x16, 0x73000
   6bf54:      	ldr	x17, [x16, #0x7a8]
   6bf58:      	add	x16, x16, #0x7a8
   6bf5c:      	br	x17

000000000006bf60 <_ZN4hiai17CreateLocalBufferEPvmb@plt>:
   6bf60:      	adrp	x16, 0x73000
   6bf64:      	ldr	x17, [x16, #0x7b0]
   6bf68:      	add	x16, x16, #0x7b0
   6bf6c:      	br	x17

000000000006bf70 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   6bf70:      	adrp	x16, 0x73000
   6bf74:      	ldr	x17, [x16, #0x7b8]
   6bf78:      	add	x16, x16, #0x7b8
   6bf7c:      	br	x17

000000000006bf80 <_ZN4hiai10BaseBufferC1EPhmb@plt>:
   6bf80:      	adrp	x16, 0x73000
   6bf84:      	ldr	x17, [x16, #0x7c0]
   6bf88:      	add	x16, x16, #0x7c0
   6bf8c:      	br	x17

000000000006bf90 <HIAI_Foundation_GetSymbol@plt>:
   6bf90:      	adrp	x16, 0x73000
   6bf94:      	ldr	x17, [x16, #0x7c8]
   6bf98:      	add	x16, x16, #0x7c8
   6bf9c:      	br	x17

000000000006bfa0 <_ZNK4hiai10BaseBuffer7GetSizeEv@plt>:
   6bfa0:      	adrp	x16, 0x73000
   6bfa4:      	ldr	x17, [x16, #0x7d0]
   6bfa8:      	add	x16, x16, #0x7d0
   6bfac:      	br	x17

000000000006bfb0 <_ZNK4hiai10BaseBuffer7GetDataEv@plt>:
   6bfb0:      	adrp	x16, 0x73000
   6bfb4:      	ldr	x17, [x16, #0x7d8]
   6bfb8:      	add	x16, x16, #0x7d8
   6bfbc:      	br	x17

000000000006bfc0 <_ZdaPv@plt>:
   6bfc0:      	adrp	x16, 0x73000
   6bfc4:      	ldr	x17, [x16, #0x7e0]
   6bfc8:      	add	x16, x16, #0x7e0
   6bfcc:      	br	x17

000000000006bfd0 <_ZN4hiai10BaseBufferC1EPhmNSt6__ndk18functionIFvS1_EEE@plt>:
   6bfd0:      	adrp	x16, 0x73000
   6bfd4:      	ldr	x17, [x16, #0x7e8]
   6bfd8:      	add	x16, x16, #0x7e8
   6bfdc:      	br	x17

000000000006bfe0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   6bfe0:      	adrp	x16, 0x73000
   6bfe4:      	ldr	x17, [x16, #0x7f0]
   6bfe8:      	add	x16, x16, #0x7f0
   6bfec:      	br	x17

000000000006bff0 <_ZN4hiai10BaseBufferD1Ev@plt>:
   6bff0:      	adrp	x16, 0x73000
   6bff4:      	ldr	x17, [x16, #0x7f8]
   6bff8:      	add	x16, x16, #0x7f8
   6bffc:      	br	x17

000000000006c000 <free@plt>:
   6c000:      	adrp	x16, 0x73000
   6c004:      	ldr	x17, [x16, #0x800]
   6c008:      	add	x16, x16, #0x800
   6c00c:      	br	x17

000000000006c010 <_ZN4hiai10BaseBuffer11MutableDataEv@plt>:
   6c010:      	adrp	x16, 0x73000
   6c014:      	ldr	x17, [x16, #0x808]
   6c018:      	add	x16, x16, #0x808
   6c01c:      	br	x17

000000000006c020 <_ZN4hiai13ModelTypeUtil20GetModelTypeFromFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_9ModelTypeE@plt>:
   6c020:      	adrp	x16, 0x73000
   6c024:      	ldr	x17, [x16, #0x810]
   6c028:      	add	x16, x16, #0x810
   6c02c:      	br	x17

000000000006c030 <_ZN4hiai8FileUtil12LoadToBufferERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   6c030:      	adrp	x16, 0x73000
   6c034:      	ldr	x17, [x16, #0x818]
   6c038:      	add	x16, x16, #0x818
   6c03c:      	br	x17

000000000006c040 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
   6c040:      	adrp	x16, 0x73000
   6c044:      	ldr	x17, [x16, #0x820]
   6c048:      	add	x16, x16, #0x820
   6c04c:      	br	x17

000000000006c050 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
   6c050:      	adrp	x16, 0x73000
   6c054:      	ldr	x17, [x16, #0x828]
   6c058:      	add	x16, x16, #0x828
   6c05c:      	br	x17

000000000006c060 <HIAI_NDTensorDesc_Destroy@plt>:
   6c060:      	adrp	x16, 0x73000
   6c064:      	ldr	x17, [x16, #0x830]
   6c068:      	add	x16, x16, #0x830
   6c06c:      	br	x17

000000000006c070 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   6c070:      	adrp	x16, 0x73000
   6c074:      	ldr	x17, [x16, #0x838]
   6c078:      	add	x16, x16, #0x838
   6c07c:      	br	x17

000000000006c080 <HIAI_NDTensorDesc_Clone@plt>:
   6c080:      	adrp	x16, 0x73000
   6c084:      	ldr	x17, [x16, #0x840]
   6c088:      	add	x16, x16, #0x840
   6c08c:      	br	x17

000000000006c090 <_ZN4hiai8FileUtil17WriteBufferToFileEPKvjPKc@plt>:
   6c090:      	adrp	x16, 0x73000
   6c094:      	ldr	x17, [x16, #0x848]
   6c098:      	add	x16, x16, #0x848
   6c09c:      	br	x17

000000000006c0a0 <HIAI_NDTensorDesc_GetDataType@plt>:
   6c0a0:      	adrp	x16, 0x73000
   6c0a4:      	ldr	x17, [x16, #0x850]
   6c0a8:      	add	x16, x16, #0x850
   6c0ac:      	br	x17

000000000006c0b0 <HIAI_NDTensorDesc_GetDimNum@plt>:
   6c0b0:      	adrp	x16, 0x73000
   6c0b4:      	ldr	x17, [x16, #0x858]
   6c0b8:      	add	x16, x16, #0x858
   6c0bc:      	br	x17

000000000006c0c0 <HIAI_NDTensorDesc_GetDim@plt>:
   6c0c0:      	adrp	x16, 0x73000
   6c0c4:      	ldr	x17, [x16, #0x860]
   6c0c8:      	add	x16, x16, #0x860
   6c0cc:      	br	x17

000000000006c0d0 <HIAI_NDTensorDesc_GetFormat@plt>:
   6c0d0:      	adrp	x16, 0x73000
   6c0d4:      	ldr	x17, [x16, #0x868]
   6c0d8:      	add	x16, x16, #0x868
   6c0dc:      	br	x17

000000000006c0e0 <HIAI_NDTensorDesc_Create@plt>:
   6c0e0:      	adrp	x16, 0x73000
   6c0e4:      	ldr	x17, [x16, #0x870]
   6c0e8:      	add	x16, x16, #0x870
   6c0ec:      	br	x17

000000000006c0f0 <HIAI_MR_ModelBuildOptions_GetInputSize@plt>:
   6c0f0:      	adrp	x16, 0x73000
   6c0f4:      	ldr	x17, [x16, #0x878]
   6c0f8:      	add	x16, x16, #0x878
   6c0fc:      	br	x17

000000000006c100 <HIAI_MR_ModelBuildOptions_GetDynamicShapeConfig@plt>:
   6c100:      	adrp	x16, 0x73000
   6c104:      	ldr	x17, [x16, #0x880]
   6c108:      	add	x16, x16, #0x880
   6c10c:      	br	x17

000000000006c110 <HIAI_MR_DynamicShapeConfig_GetEnableMode@plt>:
   6c110:      	adrp	x16, 0x73000
   6c114:      	ldr	x17, [x16, #0x888]
   6c118:      	add	x16, x16, #0x888
   6c11c:      	br	x17

000000000006c120 <HIAI_MR_ModelBuildOptions_GetModelDeviceConfig@plt>:
   6c120:      	adrp	x16, 0x73000
   6c124:      	ldr	x17, [x16, #0x890]
   6c128:      	add	x16, x16, #0x890
   6c12c:      	br	x17

000000000006c130 <HIAI_MR_ModelDeviceConfig_GetDeviceConfigMode@plt>:
   6c130:      	adrp	x16, 0x73000
   6c134:      	ldr	x17, [x16, #0x898]
   6c138:      	add	x16, x16, #0x898
   6c13c:      	br	x17

000000000006c140 <HIAI_MR_ModelBuildOptions_GetTuningStrategy@plt>:
   6c140:      	adrp	x16, 0x73000
   6c144:      	ldr	x17, [x16, #0x8a0]
   6c148:      	add	x16, x16, #0x8a0
   6c14c:      	br	x17

000000000006c150 <HIAI_MR_ModelBuildOptions_GetQuantizeConfigData@plt>:
   6c150:      	adrp	x16, 0x73000
   6c154:      	ldr	x17, [x16, #0x8a8]
   6c158:      	add	x16, x16, #0x8a8
   6c15c:      	br	x17

000000000006c160 <_ZN4hiai11VersionUtil10GetVersionEv@plt>:
   6c160:      	adrp	x16, 0x73000
   6c164:      	ldr	x17, [x16, #0x8b0]
   6c168:      	add	x16, x16, #0x8b0
   6c16c:      	br	x17

000000000006c170 <strcmp@plt>:
   6c170:      	adrp	x16, 0x73000
   6c174:      	ldr	x17, [x16, #0x8b8]
   6c178:      	add	x16, x16, #0x8b8
   6c17c:      	br	x17

000000000006c180 <strncmp@plt>:
   6c180:      	adrp	x16, 0x73000
   6c184:      	ldr	x17, [x16, #0x8c0]
   6c188:      	add	x16, x16, #0x8c0
   6c18c:      	br	x17

000000000006c190 <_ZNSt6__ndk15mutex4lockEv@plt>:
   6c190:      	adrp	x16, 0x73000
   6c194:      	ldr	x17, [x16, #0x8c8]
   6c198:      	add	x16, x16, #0x8c8
   6c19c:      	br	x17

000000000006c1a0 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   6c1a0:      	adrp	x16, 0x73000
   6c1a4:      	ldr	x17, [x16, #0x8d0]
   6c1a8:      	add	x16, x16, #0x8d0
   6c1ac:      	br	x17

000000000006c1b0 <_ZNSt6__ndk15mutexD1Ev@plt>:
   6c1b0:      	adrp	x16, 0x73000
   6c1b4:      	ldr	x17, [x16, #0x8d8]
   6c1b8:      	add	x16, x16, #0x8d8
   6c1bc:      	br	x17

000000000006c1c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   6c1c0:      	adrp	x16, 0x73000
   6c1c4:      	ldr	x17, [x16, #0x8e0]
   6c1c8:      	add	x16, x16, #0x8e0
   6c1cc:      	br	x17

000000000006c1d0 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
   6c1d0:      	adrp	x16, 0x73000
   6c1d4:      	ldr	x17, [x16, #0x8e8]
   6c1d8:      	add	x16, x16, #0x8e8
   6c1dc:      	br	x17

000000000006c1e0 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
   6c1e0:      	adrp	x16, 0x73000
   6c1e4:      	ldr	x17, [x16, #0x8f0]
   6c1e8:      	add	x16, x16, #0x8f0
   6c1ec:      	br	x17

000000000006c1f0 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
   6c1f0:      	adrp	x16, 0x73000
   6c1f4:      	ldr	x17, [x16, #0x8f8]
   6c1f8:      	add	x16, x16, #0x8f8
   6c1fc:      	br	x17

000000000006c200 <_ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE@plt>:
   6c200:      	adrp	x16, 0x73000
   6c204:      	ldr	x17, [x16, #0x900]
   6c208:      	add	x16, x16, #0x900
   6c20c:      	br	x17

000000000006c210 <HIAI_MR_ModelInitOptions_GetBuildOptions@plt>:
   6c210:      	adrp	x16, 0x73000
   6c214:      	ldr	x17, [x16, #0x908]
   6c218:      	add	x16, x16, #0x908
   6c21c:      	br	x17

000000000006c220 <HIAI_MR_ModelInitOptions_GetPerfMode@plt>:
   6c220:      	adrp	x16, 0x73000
   6c224:      	ldr	x17, [x16, #0x910]
   6c228:      	add	x16, x16, #0x910
   6c22c:      	br	x17

000000000006c230 <HIAI_MR_ModelInitOptions_GetBandMode@plt>:
   6c230:      	adrp	x16, 0x73000
   6c234:      	ldr	x17, [x16, #0x918]
   6c238:      	add	x16, x16, #0x918
   6c23c:      	br	x17

000000000006c240 <HIAI_MR_NDTensorBuffer_GetNDTensorDesc@plt>:
   6c240:      	adrp	x16, 0x73000
   6c244:      	ldr	x17, [x16, #0x920]
   6c248:      	add	x16, x16, #0x920
   6c24c:      	br	x17

000000000006c250 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
   6c250:      	adrp	x16, 0x73000
   6c254:      	ldr	x17, [x16, #0x928]
   6c258:      	add	x16, x16, #0x928
   6c25c:      	br	x17

000000000006c260 <HIAI_MR_NDTensorBuffer_GetHandle@plt>:
   6c260:      	adrp	x16, 0x73000
   6c264:      	ldr	x17, [x16, #0x930]
   6c268:      	add	x16, x16, #0x930
   6c26c:      	br	x17

000000000006c270 <HIAI_MR_GetVersion@plt>:
   6c270:      	adrp	x16, 0x73000
   6c274:      	ldr	x17, [x16, #0x938]
   6c278:      	add	x16, x16, #0x938
   6c27c:      	br	x17

000000000006c280 <pthread_mutex_lock@plt>:
   6c280:      	adrp	x16, 0x73000
   6c284:      	ldr	x17, [x16, #0x940]
   6c288:      	add	x16, x16, #0x940
   6c28c:      	br	x17

000000000006c290 <pthread_mutex_unlock@plt>:
   6c290:      	adrp	x16, 0x73000
   6c294:      	ldr	x17, [x16, #0x948]
   6c298:      	add	x16, x16, #0x948
   6c29c:      	br	x17

000000000006c2a0 <dlopen@plt>:
   6c2a0:      	adrp	x16, 0x73000
   6c2a4:      	ldr	x17, [x16, #0x950]
   6c2a8:      	add	x16, x16, #0x950
   6c2ac:      	br	x17

000000000006c2b0 <dlsym@plt>:
   6c2b0:      	adrp	x16, 0x73000
   6c2b4:      	ldr	x17, [x16, #0x958]
   6c2b8:      	add	x16, x16, #0x958
   6c2bc:      	br	x17

000000000006c2c0 <dlerror@plt>:
   6c2c0:      	adrp	x16, 0x73000
   6c2c4:      	ldr	x17, [x16, #0x960]
   6c2c8:      	add	x16, x16, #0x960
   6c2cc:      	br	x17

000000000006c2d0 <dlclose@plt>:
   6c2d0:      	adrp	x16, 0x73000
   6c2d4:      	ldr	x17, [x16, #0x968]
   6c2d8:      	add	x16, x16, #0x968
   6c2dc:      	br	x17

000000000006c2e0 <_ZN4hiai10BaseBuffer4InitEmh@plt>:
   6c2e0:      	adrp	x16, 0x73000
   6c2e4:      	ldr	x17, [x16, #0x970]
   6c2e8:      	add	x16, x16, #0x970
   6c2ec:      	br	x17

000000000006c2f0 <_ZN4hiai10BaseBuffer7SetDataEPhmb@plt>:
   6c2f0:      	adrp	x16, 0x73000
   6c2f4:      	ldr	x17, [x16, #0x978]
   6c2f8:      	add	x16, x16, #0x978
   6c2fc:      	br	x17

000000000006c300 <_ZN4hiai17CreateLocalBufferEm@plt>:
   6c300:      	adrp	x16, 0x73000
   6c304:      	ldr	x17, [x16, #0x980]
   6c308:      	add	x16, x16, #0x980
   6c30c:      	br	x17

000000000006c310 <_ZN4hiai10BaseBufferC1Ev@plt>:
   6c310:      	adrp	x16, 0x73000
   6c314:      	ldr	x17, [x16, #0x988]
   6c318:      	add	x16, x16, #0x988
   6c31c:      	br	x17

000000000006c320 <_ZN4hiai10BaseBuffer8CopyFromEPKhm@plt>:
   6c320:      	adrp	x16, 0x73000
   6c324:      	ldr	x17, [x16, #0x990]
   6c328:      	add	x16, x16, #0x990
   6c32c:      	br	x17

000000000006c330 <_ZN4hiai10BaseBuffer5ClearEv@plt>:
   6c330:      	adrp	x16, 0x73000
   6c334:      	ldr	x17, [x16, #0x998]
   6c338:      	add	x16, x16, #0x998
   6c33c:      	br	x17

000000000006c340 <getpid@plt>:
   6c340:      	adrp	x16, 0x73000
   6c344:      	ldr	x17, [x16, #0x9a0]
   6c348:      	add	x16, x16, #0x9a0
   6c34c:      	br	x17

000000000006c350 <_ZNSt6__ndk19to_stringEi@plt>:
   6c350:      	adrp	x16, 0x73000
   6c354:      	ldr	x17, [x16, #0x9a8]
   6c358:      	add	x16, x16, #0x9a8
   6c35c:      	br	x17

000000000006c360 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   6c360:      	adrp	x16, 0x73000
   6c364:      	ldr	x17, [x16, #0x9b0]
   6c368:      	add	x16, x16, #0x9b0
   6c36c:      	br	x17

000000000006c370 <realpath@plt>:
   6c370:      	adrp	x16, 0x73000
   6c374:      	ldr	x17, [x16, #0x9b8]
   6c378:      	add	x16, x16, #0x9b8
   6c37c:      	br	x17

000000000006c380 <fopen@plt>:
   6c380:      	adrp	x16, 0x73000
   6c384:      	ldr	x17, [x16, #0x9c0]
   6c388:      	add	x16, x16, #0x9c0
   6c38c:      	br	x17

000000000006c390 <fgets@plt>:
   6c390:      	adrp	x16, 0x73000
   6c394:      	ldr	x17, [x16, #0x9c8]
   6c398:      	add	x16, x16, #0x9c8
   6c39c:      	br	x17

000000000006c3a0 <fclose@plt>:
   6c3a0:      	adrp	x16, 0x73000
   6c3a4:      	ldr	x17, [x16, #0x9d0]
   6c3a8:      	add	x16, x16, #0x9d0
   6c3ac:      	br	x17

000000000006c3b0 <_ZN4hiai17AiStatsLogBuilder5StatsEjNS_17AiStatsEngineTypeEPKcS3_i@plt>:
   6c3b0:      	adrp	x16, 0x73000
   6c3b4:      	ldr	x17, [x16, #0x9d8]
   6c3b8:      	add	x16, x16, #0x9d8
   6c3bc:      	br	x17

000000000006c3c0 <HIAI_Foundation_Init@plt>:
   6c3c0:      	adrp	x16, 0x73000
   6c3c4:      	ldr	x17, [x16, #0x9e0]
   6c3c8:      	add	x16, x16, #0x9e0
   6c3cc:      	br	x17

000000000006c3d0 <HIAI_ModelRuntimeRepo_DeInit@plt>:
   6c3d0:      	adrp	x16, 0x73000
   6c3d4:      	ldr	x17, [x16, #0x9e8]
   6c3d8:      	add	x16, x16, #0x9e8
   6c3dc:      	br	x17

000000000006c3e0 <_ZN4hiai8RealPathEPKc@plt>:
   6c3e0:      	adrp	x16, 0x73000
   6c3e4:      	ldr	x17, [x16, #0x9f0]
   6c3e8:      	add	x16, x16, #0x9f0
   6c3ec:      	br	x17

000000000006c3f0 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   6c3f0:      	adrp	x16, 0x73000
   6c3f4:      	ldr	x17, [x16, #0x9f8]
   6c3f8:      	add	x16, x16, #0x9f8
   6c3fc:      	br	x17

000000000006c400 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
   6c400:      	adrp	x16, 0x73000
   6c404:      	ldr	x17, [x16, #0xa00]
   6c408:      	add	x16, x16, #0xa00
   6c40c:      	br	x17

000000000006c410 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
   6c410:      	adrp	x16, 0x73000
   6c414:      	ldr	x17, [x16, #0xa08]
   6c418:      	add	x16, x16, #0xa08
   6c41c:      	br	x17

000000000006c420 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   6c420:      	adrp	x16, 0x73000
   6c424:      	ldr	x17, [x16, #0xa10]
   6c428:      	add	x16, x16, #0xa10
   6c42c:      	br	x17

000000000006c430 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
   6c430:      	adrp	x16, 0x73000
   6c434:      	ldr	x17, [x16, #0xa18]
   6c438:      	add	x16, x16, #0xa18
   6c43c:      	br	x17

000000000006c440 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
   6c440:      	adrp	x16, 0x73000
   6c444:      	ldr	x17, [x16, #0xa20]
   6c448:      	add	x16, x16, #0xa20
   6c44c:      	br	x17

000000000006c450 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv@plt>:
   6c450:      	adrp	x16, 0x73000
   6c454:      	ldr	x17, [x16, #0xa28]
   6c458:      	add	x16, x16, #0xa28
   6c45c:      	br	x17

000000000006c460 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
   6c460:      	adrp	x16, 0x73000
   6c464:      	ldr	x17, [x16, #0xa30]
   6c468:      	add	x16, x16, #0xa30
   6c46c:      	br	x17

000000000006c470 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
   6c470:      	adrp	x16, 0x73000
   6c474:      	ldr	x17, [x16, #0xa38]
   6c478:      	add	x16, x16, #0xa38
   6c47c:      	br	x17

000000000006c480 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
   6c480:      	adrp	x16, 0x73000
   6c484:      	ldr	x17, [x16, #0xa40]
   6c488:      	add	x16, x16, #0xa40
   6c48c:      	br	x17

000000000006c490 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   6c490:      	adrp	x16, 0x73000
   6c494:      	ldr	x17, [x16, #0xa48]
   6c498:      	add	x16, x16, #0xa48
   6c49c:      	br	x17

000000000006c4a0 <HIAI_NDTensorDesc_GetElementNum@plt>:
   6c4a0:      	adrp	x16, 0x73000
   6c4a4:      	ldr	x17, [x16, #0xa50]
   6c4a8:      	add	x16, x16, #0xa50
   6c4ac:      	br	x17

000000000006c4b0 <HIAI_MR_ModelManager_Deinit@plt>:
   6c4b0:      	adrp	x16, 0x73000
   6c4b4:      	ldr	x17, [x16, #0xa58]
   6c4b8:      	add	x16, x16, #0xa58
   6c4bc:      	br	x17

000000000006c4c0 <__dynamic_cast@plt>:
   6c4c0:      	adrp	x16, 0x73000
   6c4c4:      	ldr	x17, [x16, #0xa60]
   6c4c8:      	add	x16, x16, #0xa60
   6c4cc:      	br	x17

000000000006c4d0 <HIAI_MR_ModelManager_Create@plt>:
   6c4d0:      	adrp	x16, 0x73000
   6c4d4:      	ldr	x17, [x16, #0xa68]
   6c4d8:      	add	x16, x16, #0xa68
   6c4dc:      	br	x17

000000000006c4e0 <HIAI_MR_ModelInitOptions_Create@plt>:
   6c4e0:      	adrp	x16, 0x73000
   6c4e4:      	ldr	x17, [x16, #0xa70]
   6c4e8:      	add	x16, x16, #0xa70
   6c4ec:      	br	x17

000000000006c4f0 <HIAI_MR_ModelInitOptions_SetBandMode@plt>:
   6c4f0:      	adrp	x16, 0x73000
   6c4f4:      	ldr	x17, [x16, #0xa78]
   6c4f8:      	add	x16, x16, #0xa78
   6c4fc:      	br	x17

000000000006c500 <HIAI_MR_ModelInitOptions_SetPerfMode@plt>:
   6c500:      	adrp	x16, 0x73000
   6c504:      	ldr	x17, [x16, #0xa80]
   6c508:      	add	x16, x16, #0xa80
   6c50c:      	br	x17

000000000006c510 <HIAI_MR_ModelInitOptions_SetBuildOptions@plt>:
   6c510:      	adrp	x16, 0x73000
   6c514:      	ldr	x17, [x16, #0xa88]
   6c518:      	add	x16, x16, #0xa88
   6c51c:      	br	x17

000000000006c520 <HIAI_MR_ModelManager_InitWithSharedMem@plt>:
   6c520:      	adrp	x16, 0x73000
   6c524:      	ldr	x17, [x16, #0xa90]
   6c528:      	add	x16, x16, #0xa90
   6c52c:      	br	x17

000000000006c530 <HIAI_MR_ModelManager_Init@plt>:
   6c530:      	adrp	x16, 0x73000
   6c534:      	ldr	x17, [x16, #0xa98]
   6c538:      	add	x16, x16, #0xa98
   6c53c:      	br	x17

000000000006c540 <HIAI_MR_ModelInitOptions_Destroy@plt>:
   6c540:      	adrp	x16, 0x73000
   6c544:      	ldr	x17, [x16, #0xaa0]
   6c548:      	add	x16, x16, #0xaa0
   6c54c:      	br	x17

000000000006c550 <_ZN4hiai17AiStatsLogBuilderC2Ev@plt>:
   6c550:      	adrp	x16, 0x73000
   6c554:      	ldr	x17, [x16, #0xaa8]
   6c558:      	add	x16, x16, #0xaa8
   6c55c:      	br	x17

000000000006c560 <_ZN4hiai17AiStatsLogBuilderD2Ev@plt>:
   6c560:      	adrp	x16, 0x73000
   6c564:      	ldr	x17, [x16, #0xab0]
   6c568:      	add	x16, x16, #0xab0
   6c56c:      	br	x17

000000000006c570 <HIAI_MR_ModelManager_InitWeights@plt>:
   6c570:      	adrp	x16, 0x73000
   6c574:      	ldr	x17, [x16, #0xab8]
   6c578:      	add	x16, x16, #0xab8
   6c57c:      	br	x17

000000000006c580 <HIAI_MR_ModelManager_GetWeightBuffer@plt>:
   6c580:      	adrp	x16, 0x73000
   6c584:      	ldr	x17, [x16, #0xac0]
   6c588:      	add	x16, x16, #0xac0
   6c58c:      	br	x17

000000000006c590 <HIAI_MR_ModelManager_FlushWeight@plt>:
   6c590:      	adrp	x16, 0x73000
   6c594:      	ldr	x17, [x16, #0xac8]
   6c598:      	add	x16, x16, #0xac8
   6c59c:      	br	x17

000000000006c5a0 <HIAI_MR_ModelManager_SetPriority@plt>:
   6c5a0:      	adrp	x16, 0x73000
   6c5a4:      	ldr	x17, [x16, #0xad0]
   6c5a8:      	add	x16, x16, #0xad0
   6c5ac:      	br	x17

000000000006c5b0 <HIAI_MR_ModelManager_GetModelID@plt>:
   6c5b0:      	adrp	x16, 0x73000
   6c5b4:      	ldr	x17, [x16, #0xad8]
   6c5b8:      	add	x16, x16, #0xad8
   6c5bc:      	br	x17

000000000006c5c0 <HIAI_MR_ModelManager_Run@plt>:
   6c5c0:      	adrp	x16, 0x73000
   6c5c4:      	ldr	x17, [x16, #0xae0]
   6c5c8:      	add	x16, x16, #0xae0
   6c5cc:      	br	x17

000000000006c5d0 <HIAI_MR_ModelManager_RunAsync@plt>:
   6c5d0:      	adrp	x16, 0x73000
   6c5d4:      	ldr	x17, [x16, #0xae8]
   6c5d8:      	add	x16, x16, #0xae8
   6c5dc:      	br	x17

000000000006c5e0 <_ZN4hiai29GetTensorAippParaFromAippParaERKNSt6__ndk110shared_ptrINS_9IAIPPParaEEE@plt>:
   6c5e0:      	adrp	x16, 0x73000
   6c5e4:      	ldr	x17, [x16, #0xaf0]
   6c5e8:      	add	x16, x16, #0xaf0
   6c5ec:      	br	x17

000000000006c5f0 <HIAI_MR_ModelManager_runAippModelV2@plt>:
   6c5f0:      	adrp	x16, 0x73000
   6c5f4:      	ldr	x17, [x16, #0xaf8]
   6c5f8:      	add	x16, x16, #0xaf8
   6c5fc:      	br	x17

000000000006c600 <HIAI_MR_ModelManager_Cancel@plt>:
   6c600:      	adrp	x16, 0x73000
   6c604:      	ldr	x17, [x16, #0xb00]
   6c608:      	add	x16, x16, #0xb00
   6c60c:      	br	x17

000000000006c610 <_ZN4hiai18CreateModelManagerEv@plt>:
   6c610:      	adrp	x16, 0x73000
   6c614:      	ldr	x17, [x16, #0xb08]
   6c618:      	add	x16, x16, #0xb08
   6c61c:      	br	x17

000000000006c620 <memcmp@plt>:
   6c620:      	adrp	x16, 0x73000
   6c624:      	ldr	x17, [x16, #0xb10]
   6c628:      	add	x16, x16, #0xb10
   6c62c:      	br	x17

000000000006c630 <HIAI_MR_ModelManager_Destroy@plt>:
   6c630:      	adrp	x16, 0x73000
   6c634:      	ldr	x17, [x16, #0xb18]
   6c638:      	add	x16, x16, #0xb18
   6c63c:      	br	x17

000000000006c640 <_ZN4hiai9AiContextD1Ev@plt>:
   6c640:      	adrp	x16, 0x73000
   6c644:      	ldr	x17, [x16, #0xb20]
   6c648:      	add	x16, x16, #0xb20
   6c64c:      	br	x17

000000000006c650 <_ZNK4hiai9AiContext7GetParaERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   6c650:      	adrp	x16, 0x73000
   6c654:      	ldr	x17, [x16, #0xb28]
   6c658:      	add	x16, x16, #0xb28
   6c65c:      	br	x17

000000000006c660 <_ZN4hiai9AiContext7AddParaERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   6c660:      	adrp	x16, 0x73000
   6c664:      	ldr	x17, [x16, #0xb30]
   6c668:      	add	x16, x16, #0xb30
   6c66c:      	br	x17

000000000006c670 <_ZN4hiai9AiContext10GetAllKeysERNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   6c670:      	adrp	x16, 0x73000
   6c674:      	ldr	x17, [x16, #0xb38]
   6c678:      	add	x16, x16, #0xb38
   6c67c:      	br	x17

000000000006c680 <_ZN4hiai9AiContextC1Ev@plt>:
   6c680:      	adrp	x16, 0x73000
   6c684:      	ldr	x17, [x16, #0xb40]
   6c688:      	add	x16, x16, #0xb40
   6c68c:      	br	x17

000000000006c690 <_ZN4hiai14AiModelBuilderD1Ev@plt>:
   6c690:      	adrp	x16, 0x73000
   6c694:      	ldr	x17, [x16, #0xb48]
   6c698:      	add	x16, x16, #0xb48
   6c69c:      	br	x17

000000000006c6a0 <_ZN4hiai18AiModelDescriptionD1Ev@plt>:
   6c6a0:      	adrp	x16, 0x73000
   6c6a4:      	ldr	x17, [x16, #0xb50]
   6c6a8:      	add	x16, x16, #0xb50
   6c6ac:      	br	x17

000000000006c6b0 <_ZNK4hiai18AiModelDescription7GetNameEv@plt>:
   6c6b0:      	adrp	x16, 0x73000
   6c6b4:      	ldr	x17, [x16, #0xb58]
   6c6b8:      	add	x16, x16, #0xb58
   6c6bc:      	br	x17

000000000006c6c0 <_ZNK4hiai18AiModelDescription12GetFrequencyEv@plt>:
   6c6c0:      	adrp	x16, 0x73000
   6c6c4:      	ldr	x17, [x16, #0xb60]
   6c6c8:      	add	x16, x16, #0xb60
   6c6cc:      	br	x17

000000000006c6d0 <_ZNK4hiai18AiModelDescription21GetDynamicShapeConfigERNS_18DynamicShapeConfigE@plt>:
   6c6d0:      	adrp	x16, 0x73000
   6c6d4:      	ldr	x17, [x16, #0xb68]
   6c6d8:      	add	x16, x16, #0xb68
   6c6dc:      	br	x17

000000000006c6e0 <_ZNK4hiai18AiModelDescription12GetInputDimsERNSt6__ndk16vectorINS_15TensorDimensionENS1_9allocatorIS3_EEEE@plt>:
   6c6e0:      	adrp	x16, 0x73000
   6c6e4:      	ldr	x17, [x16, #0xb70]
   6c6e8:      	add	x16, x16, #0xb70
   6c6ec:      	br	x17

000000000006c6f0 <_ZNK4hiai18AiModelDescription14GetModelBufferEv@plt>:
   6c6f0:      	adrp	x16, 0x73000
   6c6f4:      	ldr	x17, [x16, #0xb78]
   6c6f8:      	add	x16, x16, #0xb78
   6c6fc:      	br	x17

000000000006c700 <_ZNK4hiai18AiModelDescription15GetModelNetSizeEv@plt>:
   6c700:      	adrp	x16, 0x73000
   6c704:      	ldr	x17, [x16, #0xb80]
   6c708:      	add	x16, x16, #0xb80
   6c70c:      	br	x17

000000000006c710 <_ZNK4hiai18AiModelDescription16GetPrecisionModeERNS_13PrecisionModeE@plt>:
   6c710:      	adrp	x16, 0x73000
   6c714:      	ldr	x17, [x16, #0xb88]
   6c718:      	add	x16, x16, #0xb88
   6c71c:      	br	x17

000000000006c720 <_ZNK4hiai18AiModelDescription17GetTuningStrategyEv@plt>:
   6c720:      	adrp	x16, 0x73000
   6c724:      	ldr	x17, [x16, #0xb90]
   6c728:      	add	x16, x16, #0xb90
   6c72c:      	br	x17

000000000006c730 <_ZN4hiai18AiModelMngerClientD1Ev@plt>:
   6c730:      	adrp	x16, 0x73000
   6c734:      	ldr	x17, [x16, #0xb98]
   6c738:      	add	x16, x16, #0xb98
   6c73c:      	br	x17

000000000006c740 <_ZN4hiai9MemBuffer16GetMemBufferDataEv@plt>:
   6c740:      	adrp	x16, 0x73000
   6c744:      	ldr	x17, [x16, #0xba0]
   6c748:      	add	x16, x16, #0xba0
   6c74c:      	br	x17

000000000006c750 <_ZN4hiai9MemBuffer16GetMemBufferSizeEv@plt>:
   6c750:      	adrp	x16, 0x73000
   6c754:      	ldr	x17, [x16, #0xba8]
   6c758:      	add	x16, x16, #0xba8
   6c75c:      	br	x17

000000000006c760 <_ZN4hiai9MemBufferC1Ev@plt>:
   6c760:      	adrp	x16, 0x73000
   6c764:      	ldr	x17, [x16, #0xbb0]
   6c768:      	add	x16, x16, #0xbb0
   6c76c:      	br	x17

000000000006c770 <fseek@plt>:
   6c770:      	adrp	x16, 0x73000
   6c774:      	ldr	x17, [x16, #0xbb8]
   6c778:      	add	x16, x16, #0xbb8
   6c77c:      	br	x17

000000000006c780 <ftell@plt>:
   6c780:      	adrp	x16, 0x73000
   6c784:      	ldr	x17, [x16, #0xbc0]
   6c788:      	add	x16, x16, #0xbc0
   6c78c:      	br	x17

000000000006c790 <fread@plt>:
   6c790:      	adrp	x16, 0x73000
   6c794:      	ldr	x17, [x16, #0xbc8]
   6c798:      	add	x16, x16, #0xbc8
   6c79c:      	br	x17

000000000006c7a0 <fwrite@plt>:
   6c7a0:      	adrp	x16, 0x73000
   6c7a4:      	ldr	x17, [x16, #0xbd0]
   6c7a8:      	add	x16, x16, #0xbd0
   6c7ac:      	br	x17

000000000006c7b0 <_ZN4hiai18CreateModelBuilderEv@plt>:
   6c7b0:      	adrp	x16, 0x73000
   6c7b4:      	ldr	x17, [x16, #0xbd8]
   6c7b8:      	add	x16, x16, #0xbd8
   6c7bc:      	br	x17

000000000006c7c0 <_ZNK4hiai15TensorDimension9GetNumberEv@plt>:
   6c7c0:      	adrp	x16, 0x73000
   6c7c4:      	ldr	x17, [x16, #0xbe0]
   6c7c8:      	add	x16, x16, #0xbe0
   6c7cc:      	br	x17

000000000006c7d0 <_ZNK4hiai15TensorDimension10GetChannelEv@plt>:
   6c7d0:      	adrp	x16, 0x73000
   6c7d4:      	ldr	x17, [x16, #0xbe8]
   6c7d8:      	add	x16, x16, #0xbe8
   6c7dc:      	br	x17

000000000006c7e0 <_ZNK4hiai15TensorDimension9GetHeightEv@plt>:
   6c7e0:      	adrp	x16, 0x73000
   6c7e4:      	ldr	x17, [x16, #0xbf0]
   6c7e8:      	add	x16, x16, #0xbf0
   6c7ec:      	br	x17

000000000006c7f0 <_ZNK4hiai15TensorDimension8GetWidthEv@plt>:
   6c7f0:      	adrp	x16, 0x73000
   6c7f4:      	ldr	x17, [x16, #0xbf8]
   6c7f8:      	add	x16, x16, #0xbf8
   6c7fc:      	br	x17

000000000006c800 <_ZN4hiai16CreateBuiltModelEv@plt>:
   6c800:      	adrp	x16, 0x73000
   6c804:      	ldr	x17, [x16, #0xc00]
   6c808:      	add	x16, x16, #0xc00
   6c80c:      	br	x17

000000000006c810 <_ZNK4hiai10AippTensor11GetAiTensorEv@plt>:
   6c810:      	adrp	x16, 0x73000
   6c814:      	ldr	x17, [x16, #0xc08]
   6c818:      	add	x16, x16, #0xc08
   6c81c:      	br	x17

000000000006c820 <_ZNK4hiai10AippTensor12GetAippParasEv@plt>:
   6c820:      	adrp	x16, 0x73000
   6c824:      	ldr	x17, [x16, #0xc10]
   6c828:      	add	x16, x16, #0xc10
   6c82c:      	br	x17

000000000006c830 <_ZN4hiai8AippPara11GetAIPPParaEv@plt>:
   6c830:      	adrp	x16, 0x73000
   6c834:      	ldr	x17, [x16, #0xc18]
   6c838:      	add	x16, x16, #0xc18
   6c83c:      	br	x17

000000000006c840 <_ZN4hiai15TensorDimensionC1Ev@plt>:
   6c840:      	adrp	x16, 0x73000
   6c844:      	ldr	x17, [x16, #0xc20]
   6c848:      	add	x16, x16, #0xc20
   6c84c:      	br	x17

000000000006c850 <_ZN4hiai15TensorDimension9SetNumberEj@plt>:
   6c850:      	adrp	x16, 0x73000
   6c854:      	ldr	x17, [x16, #0xc28]
   6c858:      	add	x16, x16, #0xc28
   6c85c:      	br	x17

000000000006c860 <_ZN4hiai15TensorDimension10SetChannelEj@plt>:
   6c860:      	adrp	x16, 0x73000
   6c864:      	ldr	x17, [x16, #0xc30]
   6c868:      	add	x16, x16, #0xc30
   6c86c:      	br	x17

000000000006c870 <_ZN4hiai15TensorDimension9SetHeightEj@plt>:
   6c870:      	adrp	x16, 0x73000
   6c874:      	ldr	x17, [x16, #0xc38]
   6c878:      	add	x16, x16, #0xc38
   6c87c:      	br	x17

000000000006c880 <_ZN4hiai15TensorDimension8SetWidthEj@plt>:
   6c880:      	adrp	x16, 0x73000
   6c884:      	ldr	x17, [x16, #0xc40]
   6c888:      	add	x16, x16, #0xc40
   6c88c:      	br	x17

000000000006c890 <_ZN4hiai15TensorDimensionD1Ev@plt>:
   6c890:      	adrp	x16, 0x73000
   6c894:      	ldr	x17, [x16, #0xc48]
   6c898:      	add	x16, x16, #0xc48
   6c89c:      	br	x17

000000000006c8a0 <_ZN4hiai8AippPara11SetAIPPParaERNSt6__ndk110shared_ptrINS_9IAIPPParaEEE@plt>:
   6c8a0:      	adrp	x16, 0x73000
   6c8a4:      	ldr	x17, [x16, #0xc50]
   6c8a8:      	add	x16, x16, #0xc50
   6c8ac:      	br	x17

000000000006c8b0 <_ZN4hiai8AippParaC1Ev@plt>:
   6c8b0:      	adrp	x16, 0x73000
   6c8b4:      	ldr	x17, [x16, #0xc58]
   6c8b8:      	add	x16, x16, #0xc58
   6c8bc:      	br	x17

000000000006c8c0 <_ZN4hiai8AippParaD1Ev@plt>:
   6c8c0:      	adrp	x16, 0x73000
   6c8c4:      	ldr	x17, [x16, #0xc60]
   6c8c8:      	add	x16, x16, #0xc60
   6c8cc:      	br	x17

000000000006c8d0 <_ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
   6c8d0:      	adrp	x16, 0x73000
   6c8d4:      	ldr	x17, [x16, #0xc68]
   6c8d8:      	add	x16, x16, #0xc68
   6c8dc:      	br	x17

000000000006c8e0 <_ZN4hiai8AiTensorC2Ev@plt>:
   6c8e0:      	adrp	x16, 0x73000
   6c8e4:      	ldr	x17, [x16, #0xc70]
   6c8e8:      	add	x16, x16, #0xc70
   6c8ec:      	br	x17

000000000006c8f0 <_ZN4hiai8AiTensorD2Ev@plt>:
   6c8f0:      	adrp	x16, 0x73000
   6c8f4:      	ldr	x17, [x16, #0xc78]
   6c8f8:      	add	x16, x16, #0xc78
   6c8fc:      	br	x17

000000000006c900 <HIAI_MR_ModelBuildOptions_Create@plt>:
   6c900:      	adrp	x16, 0x73000
   6c904:      	ldr	x17, [x16, #0xc80]
   6c908:      	add	x16, x16, #0xc80
   6c90c:      	br	x17

000000000006c910 <HIAI_MR_ModelBuildOptions_SetInputTensorDescs@plt>:
   6c910:      	adrp	x16, 0x73000
   6c914:      	ldr	x17, [x16, #0xc88]
   6c918:      	add	x16, x16, #0xc88
   6c91c:      	br	x17

000000000006c920 <HIAI_MR_ModelBuildOptions_SetFormatModeOption@plt>:
   6c920:      	adrp	x16, 0x73000
   6c924:      	ldr	x17, [x16, #0xc90]
   6c928:      	add	x16, x16, #0xc90
   6c92c:      	br	x17

000000000006c930 <HIAI_MR_ModelBuildOptions_SetPrecisionModeOption@plt>:
   6c930:      	adrp	x16, 0x73000
   6c934:      	ldr	x17, [x16, #0xc98]
   6c938:      	add	x16, x16, #0xc98
   6c93c:      	br	x17

000000000006c940 <HIAI_MR_DynamicShapeConfig_Create@plt>:
   6c940:      	adrp	x16, 0x73000
   6c944:      	ldr	x17, [x16, #0xca0]
   6c948:      	add	x16, x16, #0xca0
   6c94c:      	br	x17

000000000006c950 <HIAI_MR_DynamicShapeConfig_SetEnableMode@plt>:
   6c950:      	adrp	x16, 0x73000
   6c954:      	ldr	x17, [x16, #0xca8]
   6c958:      	add	x16, x16, #0xca8
   6c95c:      	br	x17

000000000006c960 <HIAI_MR_DynamicShapeConfig_SetMaxCacheNum@plt>:
   6c960:      	adrp	x16, 0x73000
   6c964:      	ldr	x17, [x16, #0xcb0]
   6c968:      	add	x16, x16, #0xcb0
   6c96c:      	br	x17

000000000006c970 <HIAI_MR_DynamicShapeConfig_SetCacheMode@plt>:
   6c970:      	adrp	x16, 0x73000
   6c974:      	ldr	x17, [x16, #0xcb8]
   6c978:      	add	x16, x16, #0xcb8
   6c97c:      	br	x17

000000000006c980 <HIAI_MR_ModelBuildOptions_SetDynamicShapeConfig@plt>:
   6c980:      	adrp	x16, 0x73000
   6c984:      	ldr	x17, [x16, #0xcc0]
   6c988:      	add	x16, x16, #0xcc0
   6c98c:      	br	x17

000000000006c990 <HIAI_MR_ModelDeviceConfig_Create@plt>:
   6c990:      	adrp	x16, 0x73000
   6c994:      	ldr	x17, [x16, #0xcc8]
   6c998:      	add	x16, x16, #0xcc8
   6c99c:      	br	x17

000000000006c9a0 <HIAI_MR_ModelDeviceConfig_SetDeviceConfigMode@plt>:
   6c9a0:      	adrp	x16, 0x73000
   6c9a4:      	ldr	x17, [x16, #0xcd0]
   6c9a8:      	add	x16, x16, #0xcd0
   6c9ac:      	br	x17

000000000006c9b0 <HIAI_MR_ModelDeviceConfig_SetFallBackMode@plt>:
   6c9b0:      	adrp	x16, 0x73000
   6c9b4:      	ldr	x17, [x16, #0xcd8]
   6c9b8:      	add	x16, x16, #0xcd8
   6c9bc:      	br	x17

000000000006c9c0 <memcpy@plt>:
   6c9c0:      	adrp	x16, 0x73000
   6c9c4:      	ldr	x17, [x16, #0xce0]
   6c9c8:      	add	x16, x16, #0xce0
   6c9cc:      	br	x17

000000000006c9d0 <HIAI_MR_ModelDeviceConfig_SetModelDeviceOrder@plt>:
   6c9d0:      	adrp	x16, 0x73000
   6c9d4:      	ldr	x17, [x16, #0xce8]
   6c9d8:      	add	x16, x16, #0xce8
   6c9dc:      	br	x17

000000000006c9e0 <HIAI_MR_OpDeviceOrder_Create@plt>:
   6c9e0:      	adrp	x16, 0x73000
   6c9e4:      	ldr	x17, [x16, #0xcf0]
   6c9e8:      	add	x16, x16, #0xcf0
   6c9ec:      	br	x17

000000000006c9f0 <HIAI_MR_OpDeviceOrder_SetOpName@plt>:
   6c9f0:      	adrp	x16, 0x73000
   6c9f4:      	ldr	x17, [x16, #0xcf8]
   6c9f8:      	add	x16, x16, #0xcf8
   6c9fc:      	br	x17

000000000006ca00 <HIAI_MR_OpDeviceOrder_SetDeviceOrder@plt>:
   6ca00:      	adrp	x16, 0x73000
   6ca04:      	ldr	x17, [x16, #0xd00]
   6ca08:      	add	x16, x16, #0xd00
   6ca0c:      	br	x17

000000000006ca10 <HIAI_MR_ModelDeviceConfig_SetOpDeviceOrder@plt>:
   6ca10:      	adrp	x16, 0x73000
   6ca14:      	ldr	x17, [x16, #0xd08]
   6ca18:      	add	x16, x16, #0xd08
   6ca1c:      	br	x17

000000000006ca20 <HIAI_MR_ModelDeviceConfig_SetDeviceMemoryReusePlan@plt>:
   6ca20:      	adrp	x16, 0x73000
   6ca24:      	ldr	x17, [x16, #0xd10]
   6ca28:      	add	x16, x16, #0xd10
   6ca2c:      	br	x17

000000000006ca30 <HIAI_MR_ModelBuildOptions_SetModelDeviceConfig@plt>:
   6ca30:      	adrp	x16, 0x73000
   6ca34:      	ldr	x17, [x16, #0xd18]
   6ca38:      	add	x16, x16, #0xd18
   6ca3c:      	br	x17

000000000006ca40 <HIAI_MR_ModelBuildOptions_SetTuningStrategy@plt>:
   6ca40:      	adrp	x16, 0x73000
   6ca44:      	ldr	x17, [x16, #0xd20]
   6ca48:      	add	x16, x16, #0xd20
   6ca4c:      	br	x17

000000000006ca50 <HIAI_MR_ModelBuildOptions_SetEstimatedOutputSize@plt>:
   6ca50:      	adrp	x16, 0x73000
   6ca54:      	ldr	x17, [x16, #0xd28]
   6ca58:      	add	x16, x16, #0xd28
   6ca5c:      	br	x17

000000000006ca60 <HIAI_MR_ModelBuildOptions_SetQuantizeConfig@plt>:
   6ca60:      	adrp	x16, 0x73000
   6ca64:      	ldr	x17, [x16, #0xd30]
   6ca68:      	add	x16, x16, #0xd30
   6ca6c:      	br	x17

000000000006ca70 <HIAI_MR_ModelBuildOptions_Destroy@plt>:
   6ca70:      	adrp	x16, 0x73000
   6ca74:      	ldr	x17, [x16, #0xd38]
   6ca78:      	add	x16, x16, #0xd38
   6ca7c:      	br	x17

000000000006ca80 <HIAI_MR_TuningConfig_Create@plt>:
   6ca80:      	adrp	x16, 0x73000
   6ca84:      	ldr	x17, [x16, #0xd40]
   6ca88:      	add	x16, x16, #0xd40
   6ca8c:      	br	x17

000000000006ca90 <HIAI_MR_TuningConfig_SetTuningMode@plt>:
   6ca90:      	adrp	x16, 0x73000
   6ca94:      	ldr	x17, [x16, #0xd48]
   6ca98:      	add	x16, x16, #0xd48
   6ca9c:      	br	x17

000000000006caa0 <HIAI_MR_TuningConfig_SetTuningObjective@plt>:
   6caa0:      	adrp	x16, 0x73000
   6caa4:      	ldr	x17, [x16, #0xd50]
   6caa8:      	add	x16, x16, #0xd50
   6caac:      	br	x17

000000000006cab0 <HIAI_MR_TuningConfig_SetCacheDir@plt>:
   6cab0:      	adrp	x16, 0x73000
   6cab4:      	ldr	x17, [x16, #0xd58]
   6cab8:      	add	x16, x16, #0xd58
   6cabc:      	br	x17

000000000006cac0 <HIAI_MR_OpDeviceOrder_Destroy@plt>:
   6cac0:      	adrp	x16, 0x73000
   6cac4:      	ldr	x17, [x16, #0xd60]
   6cac8:      	add	x16, x16, #0xd60
   6cacc:      	br	x17

000000000006cad0 <HIAI_MR_ModelDeviceConfig_Destroy@plt>:
   6cad0:      	adrp	x16, 0x73000
   6cad4:      	ldr	x17, [x16, #0xd68]
   6cad8:      	add	x16, x16, #0xd68
   6cadc:      	br	x17

000000000006cae0 <HIAI_MR_TuningConfig_SetDeviceMemoryReusePlan@plt>:
   6cae0:      	adrp	x16, 0x73000
   6cae4:      	ldr	x17, [x16, #0xd70]
   6cae8:      	add	x16, x16, #0xd70
   6caec:      	br	x17

000000000006caf0 <HIAI_MR_ModelBuildOptions_SetCustomOpPath@plt>:
   6caf0:      	adrp	x16, 0x73000
   6caf4:      	ldr	x17, [x16, #0xd78]
   6caf8:      	add	x16, x16, #0xd78
   6cafc:      	br	x17

000000000006cb00 <HIAI_MR_ModelBuildOptions_SetTuningConfig@plt>:
   6cb00:      	adrp	x16, 0x73000
   6cb04:      	ldr	x17, [x16, #0xd80]
   6cb08:      	add	x16, x16, #0xd80
   6cb0c:      	br	x17

000000000006cb10 <HIAI_MR_ModelBuilder_Build@plt>:
   6cb10:      	adrp	x16, 0x73000
   6cb14:      	ldr	x17, [x16, #0xd88]
   6cb18:      	add	x16, x16, #0xd88
   6cb1c:      	br	x17

000000000006cb20 <HIAI_MR_BuiltModel_Destroy@plt>:
   6cb20:      	adrp	x16, 0x73000
   6cb24:      	ldr	x17, [x16, #0xd90]
   6cb28:      	add	x16, x16, #0xd90
   6cb2c:      	br	x17

000000000006cb30 <HIAI_MR_BuiltModel_SaveToExternalBuffer@plt>:
   6cb30:      	adrp	x16, 0x73000
   6cb34:      	ldr	x17, [x16, #0xd98]
   6cb38:      	add	x16, x16, #0xd98
   6cb3c:      	br	x17

000000000006cb40 <HIAI_MR_BuiltModel_Save@plt>:
   6cb40:      	adrp	x16, 0x73000
   6cb44:      	ldr	x17, [x16, #0xda0]
   6cb48:      	add	x16, x16, #0xda0
   6cb4c:      	br	x17

000000000006cb50 <_ZN4hiai8FileUtil15CreateEmptyFileEPKc@plt>:
   6cb50:      	adrp	x16, 0x73000
   6cb54:      	ldr	x17, [x16, #0xda8]
   6cb58:      	add	x16, x16, #0xda8
   6cb5c:      	br	x17

000000000006cb60 <HIAI_MR_BuiltModel_SaveToFile@plt>:
   6cb60:      	adrp	x16, 0x73000
   6cb64:      	ldr	x17, [x16, #0xdb0]
   6cb68:      	add	x16, x16, #0xdb0
   6cb6c:      	br	x17

000000000006cb70 <HIAI_MR_BuiltModel_Restore@plt>:
   6cb70:      	adrp	x16, 0x73000
   6cb74:      	ldr	x17, [x16, #0xdb8]
   6cb78:      	add	x16, x16, #0xdb8
   6cb7c:      	br	x17

000000000006cb80 <HIAI_MR_BuiltModel_RestoreFromFile@plt>:
   6cb80:      	adrp	x16, 0x73000
   6cb84:      	ldr	x17, [x16, #0xdc0]
   6cb88:      	add	x16, x16, #0xdc0
   6cb8c:      	br	x17

000000000006cb90 <HIAI_MR_BuiltModel_CheckCompatibility@plt>:
   6cb90:      	adrp	x16, 0x73000
   6cb94:      	ldr	x17, [x16, #0xdc8]
   6cb98:      	add	x16, x16, #0xdc8
   6cb9c:      	br	x17

000000000006cba0 <HIAI_MR_BuiltModel_CheckUpdatability@plt>:
   6cba0:      	adrp	x16, 0x73000
   6cba4:      	ldr	x17, [x16, #0xdd0]
   6cba8:      	add	x16, x16, #0xdd0
   6cbac:      	br	x17

000000000006cbb0 <HIAI_MR_BuiltModel_GetLibraryTimestamp@plt>:
   6cbb0:      	adrp	x16, 0x73000
   6cbb4:      	ldr	x17, [x16, #0xdd8]
   6cbb8:      	add	x16, x16, #0xdd8
   6cbbc:      	br	x17

000000000006cbc0 <HIAI_MR_BuiltModel_GetInputTensorNum@plt>:
   6cbc0:      	adrp	x16, 0x73000
   6cbc4:      	ldr	x17, [x16, #0xde0]
   6cbc8:      	add	x16, x16, #0xde0
   6cbcc:      	br	x17

000000000006cbd0 <HIAI_MR_BuiltModel_GetName@plt>:
   6cbd0:      	adrp	x16, 0x73000
   6cbd4:      	ldr	x17, [x16, #0xde8]
   6cbd8:      	add	x16, x16, #0xde8
   6cbdc:      	br	x17

000000000006cbe0 <HIAI_MR_BuiltModel_SetName@plt>:
   6cbe0:      	adrp	x16, 0x73000
   6cbe4:      	ldr	x17, [x16, #0xdf0]
   6cbe8:      	add	x16, x16, #0xdf0
   6cbec:      	br	x17

000000000006cbf0 <HIAI_MR_BuiltModel_GetTensorAippInfo@plt>:
   6cbf0:      	adrp	x16, 0x73000
   6cbf4:      	ldr	x17, [x16, #0xdf8]
   6cbf8:      	add	x16, x16, #0xdf8
   6cbfc:      	br	x17

000000000006cc00 <HIAI_MR_BuiltModel_GetTensorAippPara@plt>:
   6cc00:      	adrp	x16, 0x73000
   6cc04:      	ldr	x17, [x16, #0xe00]
   6cc08:      	add	x16, x16, #0xe00
   6cc0c:      	br	x17

000000000006cc10 <HIAI_MR_BuiltModel_GetFmMemorySize@plt>:
   6cc10:      	adrp	x16, 0x73000
   6cc14:      	ldr	x17, [x16, #0xe08]
   6cc18:      	add	x16, x16, #0xe08
   6cc1c:      	br	x17

000000000006cc20 <HIAI_MR_BuiltModel_RestoreFromFileWithShapeIndex@plt>:
   6cc20:      	adrp	x16, 0x73000
   6cc24:      	ldr	x17, [x16, #0xe10]
   6cc28:      	add	x16, x16, #0xe10
   6cc2c:      	br	x17

000000000006cc30 <_ZN4hiai8FileUtil12LoadToBufferERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEm@plt>:
   6cc30:      	adrp	x16, 0x73000
   6cc34:      	ldr	x17, [x16, #0xe18]
   6cc38:      	add	x16, x16, #0xe18
   6cc3c:      	br	x17

000000000006cc40 <_ZN4hiai14CreateAIPPParaEj@plt>:
   6cc40:      	adrp	x16, 0x73000
   6cc44:      	ldr	x17, [x16, #0xe20]
   6cc48:      	add	x16, x16, #0xe20
   6cc4c:      	br	x17

000000000006cc50 <_ZN4hiai23CreateImageTensorBufferEiiiNS_11ImageFormatENS_15ImageColorSpaceEi@plt>:
   6cc50:      	adrp	x16, 0x73000
   6cc54:      	ldr	x17, [x16, #0xe28]
   6cc58:      	add	x16, x16, #0xe28
   6cc5c:      	br	x17

000000000006cc60 <_ZN4hiai20CreateNDTensorBufferERKNS_12NDTensorDescEPKvm@plt>:
   6cc60:      	adrp	x16, 0x73000
   6cc64:      	ldr	x17, [x16, #0xe30]
   6cc68:      	add	x16, x16, #0xe30
   6cc6c:      	br	x17

000000000006cc70 <_ZN4hiai8AiTensorD1Ev@plt>:
   6cc70:      	adrp	x16, 0x73000
   6cc74:      	ldr	x17, [x16, #0xe38]
   6cc78:      	add	x16, x16, #0xe38
   6cc7c:      	br	x17

000000000006cc80 <_ZN4hiai8AiTensor4InitERKNS_12NativeHandleEPKNS_15TensorDimensionENS_13HIAI_DataTypeE@plt>:
   6cc80:      	adrp	x16, 0x73000
   6cc84:      	ldr	x17, [x16, #0xe40]
   6cc88:      	add	x16, x16, #0xe40
   6cc8c:      	br	x17

000000000006cc90 <_ZN4hiai15TensorDimensionC1Ejjjj@plt>:
   6cc90:      	adrp	x16, 0x73000
   6cc94:      	ldr	x17, [x16, #0xe48]
   6cc98:      	add	x16, x16, #0xe48
   6cc9c:      	br	x17

000000000006cca0 <_ZN4hiai8AiTensorC1Ev@plt>:
   6cca0:      	adrp	x16, 0x73000
   6cca4:      	ldr	x17, [x16, #0xe50]
   6cca8:      	add	x16, x16, #0xe50
   6ccac:      	br	x17

000000000006ccb0 <_ZN4hiai20CreateNDTensorBufferERKNS_12NDTensorDescE@plt>:
   6ccb0:      	adrp	x16, 0x73000
   6ccb4:      	ldr	x17, [x16, #0xe58]
   6ccb8:      	add	x16, x16, #0xe58
   6ccbc:      	br	x17

000000000006ccc0 <_ZN4hiai26CreateNDTensorBufferNoCopyERKNS_12NDTensorDescEPKvm@plt>:
   6ccc0:      	adrp	x16, 0x73000
   6ccc4:      	ldr	x17, [x16, #0xe60]
   6ccc8:      	add	x16, x16, #0xe60
   6cccc:      	br	x17

000000000006ccd0 <_ZN4hiai20CreateNDTensorBufferERKNS_12NDTensorDescERKNS_12NativeHandleE@plt>:
   6ccd0:      	adrp	x16, 0x73000
   6ccd4:      	ldr	x17, [x16, #0xe68]
   6ccd8:      	add	x16, x16, #0xe68
   6ccdc:      	br	x17

000000000006cce0 <_ZN4hiai10AippTensorD1Ev@plt>:
   6cce0:      	adrp	x16, 0x73000
   6cce4:      	ldr	x17, [x16, #0xe70]
   6cce8:      	add	x16, x16, #0xe70
   6ccec:      	br	x17

000000000006ccf0 <_ZN4hiai8AippPara4InitEj@plt>:
   6ccf0:      	adrp	x16, 0x73000
   6ccf4:      	ldr	x17, [x16, #0xe78]
   6ccf8:      	add	x16, x16, #0xe78
   6ccfc:      	br	x17

000000000006cd00 <_ZN4hiai8AippPara14SetInputFormatENS_20AiTensorImage_FormatE@plt>:
   6cd00:      	adrp	x16, 0x73000
   6cd04:      	ldr	x17, [x16, #0xe80]
   6cd08:      	add	x16, x16, #0xe80
   6cd0c:      	br	x17

000000000006cd10 <_ZN4hiai8AippPara13SetInputShapeENS_14AippInputShapeE@plt>:
   6cd10:      	adrp	x16, 0x73000
   6cd14:      	ldr	x17, [x16, #0xe88]
   6cd18:      	add	x16, x16, #0xe88
   6cd1c:      	br	x17

000000000006cd20 <_ZN4hiai8AippPara11SetCropParaENS_12AippCropParaE@plt>:
   6cd20:      	adrp	x16, 0x73000
   6cd24:      	ldr	x17, [x16, #0xe90]
   6cd28:      	add	x16, x16, #0xe90
   6cd2c:      	br	x17

000000000006cd30 <_ZN4hiai10AippTensorC1ENSt6__ndk110shared_ptrINS_8AiTensorEEENS1_6vectorINS2_INS_8AippParaEEENS1_9allocatorIS7_EEEE@plt>:
   6cd30:      	adrp	x16, 0x73000
   6cd34:      	ldr	x17, [x16, #0xe98]
   6cd38:      	add	x16, x16, #0xe98
   6cd3c:      	br	x17

000000000006cd40 <HIAI_MR_NDTensorBuffer_Destroy@plt>:
   6cd40:      	adrp	x16, 0x73000
   6cd44:      	ldr	x17, [x16, #0xea0]
   6cd48:      	add	x16, x16, #0xea0
   6cd4c:      	br	x17

000000000006cd50 <HIAI_MR_NDTensorBuffer_SetCacheStatus@plt>:
   6cd50:      	adrp	x16, 0x73000
   6cd54:      	ldr	x17, [x16, #0xea8]
   6cd58:      	add	x16, x16, #0xea8
   6cd5c:      	br	x17

000000000006cd60 <HIAI_MR_NDTensorBuffer_GetCacheStatus@plt>:
   6cd60:      	adrp	x16, 0x73000
   6cd64:      	ldr	x17, [x16, #0xeb0]
   6cd68:      	add	x16, x16, #0xeb0
   6cd6c:      	br	x17

000000000006cd70 <HIAI_MR_NDTensorBuffer_GetData@plt>:
   6cd70:      	adrp	x16, 0x73000
   6cd74:      	ldr	x17, [x16, #0xeb8]
   6cd78:      	add	x16, x16, #0xeb8
   6cd7c:      	br	x17

000000000006cd80 <HIAI_MR_NDTensorBuffer_GetSize@plt>:
   6cd80:      	adrp	x16, 0x73000
   6cd84:      	ldr	x17, [x16, #0xec0]
   6cd88:      	add	x16, x16, #0xec0
   6cd8c:      	br	x17

000000000006cd90 <HIAI_MR_NDTensorBuffer_CreateFromNDTensorDesc@plt>:
   6cd90:      	adrp	x16, 0x73000
   6cd94:      	ldr	x17, [x16, #0xec8]
   6cd98:      	add	x16, x16, #0xec8
   6cd9c:      	br	x17

000000000006cda0 <HIAI_MR_NDTensorBuffer_CreateFromBuffer@plt>:
   6cda0:      	adrp	x16, 0x73000
   6cda4:      	ldr	x17, [x16, #0xed0]
   6cda8:      	add	x16, x16, #0xed0
   6cdac:      	br	x17

000000000006cdb0 <HIAI_MR_NDTensorBuffer_CreateNoCopy@plt>:
   6cdb0:      	adrp	x16, 0x73000
   6cdb4:      	ldr	x17, [x16, #0xed8]
   6cdb8:      	add	x16, x16, #0xed8
   6cdbc:      	br	x17

000000000006cdc0 <HIAI_MR_NDTensorBuffer_CreateFromSize@plt>:
   6cdc0:      	adrp	x16, 0x73000
   6cdc4:      	ldr	x17, [x16, #0xee0]
   6cdc8:      	add	x16, x16, #0xee0
   6cdcc:      	br	x17

000000000006cdd0 <memchr@plt>:
   6cdd0:      	adrp	x16, 0x73000
   6cdd4:      	ldr	x17, [x16, #0xee8]
   6cdd8:      	add	x16, x16, #0xee8
   6cddc:      	br	x17

000000000006cde0 <HIAI_Foundation_IsNpuSupport@plt>:
   6cde0:      	adrp	x16, 0x73000
   6cde4:      	ldr	x17, [x16, #0xef0]
   6cde8:      	add	x16, x16, #0xef0
   6cdec:      	br	x17

000000000006cdf0 <__android_log_vprint@plt>:
   6cdf0:      	adrp	x16, 0x73000
   6cdf4:      	ldr	x17, [x16, #0xef8]
   6cdf8:      	add	x16, x16, #0xef8
   6cdfc:      	br	x17

000000000006ce00 <_ZN4hiai8FileUtil8OpenFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   6ce00:      	adrp	x16, 0x73000
   6ce04:      	ldr	x17, [x16, #0xf00]
   6ce08:      	add	x16, x16, #0xf00
   6ce0c:      	br	x17

000000000006ce10 <_ZN4hiai8FileUtil11GetFileSizeEP7__sFILE@plt>:
   6ce10:      	adrp	x16, 0x73000
   6ce14:      	ldr	x17, [x16, #0xf08]
   6ce18:      	add	x16, x16, #0xf08
   6ce1c:      	br	x17

000000000006ce20 <stat@plt>:
   6ce20:      	adrp	x16, 0x73000
   6ce24:      	ldr	x17, [x16, #0xf10]
   6ce28:      	add	x16, x16, #0xf10
   6ce2c:      	br	x17

000000000006ce30 <_ZN4hiai9CreateDirERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   6ce30:      	adrp	x16, 0x73000
   6ce34:      	ldr	x17, [x16, #0xf18]
   6ce38:      	add	x16, x16, #0xf18
   6ce3c:      	br	x17

000000000006ce40 <access@plt>:
   6ce40:      	adrp	x16, 0x73000
   6ce44:      	ldr	x17, [x16, #0xf20]
   6ce48:      	add	x16, x16, #0xf20
   6ce4c:      	br	x17

000000000006ce50 <mkdir@plt>:
   6ce50:      	adrp	x16, 0x73000
   6ce54:      	ldr	x17, [x16, #0xf28]
   6ce58:      	add	x16, x16, #0xf28
   6ce5c:      	br	x17

000000000006ce60 <__errno@plt>:
   6ce60:      	adrp	x16, 0x73000
   6ce64:      	ldr	x17, [x16, #0xf30]
   6ce68:      	add	x16, x16, #0xf30
   6ce6c:      	br	x17

000000000006ce70 <_ZN4hiai11ValidateStrERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEES8_@plt>:
   6ce70:      	adrp	x16, 0x73000
   6ce74:      	ldr	x17, [x16, #0xf38]
   6ce78:      	add	x16, x16, #0xf38
   6ce7c:      	br	x17

000000000006ce80 <_ZNSt6__ndk16localeD1Ev@plt>:
   6ce80:      	adrp	x16, 0x73000
   6ce84:      	ldr	x17, [x16, #0xf40]
   6ce88:      	add	x16, x16, #0xf40
   6ce8c:      	br	x17

000000000006ce90 <__open_2@plt>:
   6ce90:      	adrp	x16, 0x73000
   6ce94:      	ldr	x17, [x16, #0xf48]
   6ce98:      	add	x16, x16, #0xf48
   6ce9c:      	br	x17

000000000006cea0 <lseek64@plt>:
   6cea0:      	adrp	x16, 0x73000
   6cea4:      	ldr	x17, [x16, #0xf50]
   6cea8:      	add	x16, x16, #0xf50
   6ceac:      	br	x17

000000000006ceb0 <mmap@plt>:
   6ceb0:      	adrp	x16, 0x73000
   6ceb4:      	ldr	x17, [x16, #0xf58]
   6ceb8:      	add	x16, x16, #0xf58
   6cebc:      	br	x17

000000000006cec0 <close@plt>:
   6cec0:      	adrp	x16, 0x73000
   6cec4:      	ldr	x17, [x16, #0xf60]
   6cec8:      	add	x16, x16, #0xf60
   6cecc:      	br	x17

000000000006ced0 <munmap@plt>:
   6ced0:      	adrp	x16, 0x73000
   6ced4:      	ldr	x17, [x16, #0xf68]
   6ced8:      	add	x16, x16, #0xf68
   6cedc:      	br	x17

000000000006cee0 <_ZNSt6__ndk16localeC1Ev@plt>:
   6cee0:      	adrp	x16, 0x73000
   6cee4:      	ldr	x17, [x16, #0xf70]
   6cee8:      	add	x16, x16, #0xf70
   6ceec:      	br	x17

000000000006cef0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   6cef0:      	adrp	x16, 0x73000
   6cef4:      	ldr	x17, [x16, #0xf78]
   6cef8:      	add	x16, x16, #0xf78
   6cefc:      	br	x17

000000000006cf00 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
   6cf00:      	adrp	x16, 0x73000
   6cf04:      	ldr	x17, [x16, #0xf80]
   6cf08:      	add	x16, x16, #0xf80
   6cf0c:      	br	x17

000000000006cf10 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc@plt>:
   6cf10:      	adrp	x16, 0x73000
   6cf14:      	ldr	x17, [x16, #0xf88]
   6cf18:      	add	x16, x16, #0xf88
   6cf1c:      	br	x17

000000000006cf20 <_ZNKSt6__ndk16locale4nameEv@plt>:
   6cf20:      	adrp	x16, 0x73000
   6cf24:      	ldr	x17, [x16, #0xf90]
   6cf28:      	add	x16, x16, #0xf90
   6cf2c:      	br	x17

000000000006cf30 <_ZNSt6__ndk120__get_collation_nameEPKc@plt>:
   6cf30:      	adrp	x16, 0x73000
   6cf34:      	ldr	x17, [x16, #0xf98]
   6cf38:      	add	x16, x16, #0xf98
   6cf3c:      	br	x17

000000000006cf40 <_ZNSt6__ndk115__get_classnameEPKcb@plt>:
   6cf40:      	adrp	x16, 0x73000
   6cf44:      	ldr	x17, [x16, #0xfa0]
   6cf48:      	add	x16, x16, #0xfa0
   6cf4c:      	br	x17

000000000006cf50 <strstr@plt>:
   6cf50:      	adrp	x16, 0x73000
   6cf54:      	ldr	x17, [x16, #0xfa8]
   6cf58:      	add	x16, x16, #0xfa8
   6cf5c:      	br	x17

000000000006cf60 <HIAI_MR_NDTensorBuffer_Create@plt>:
   6cf60:      	adrp	x16, 0x73000
   6cf64:      	ldr	x17, [x16, #0xfb0]
   6cf68:      	add	x16, x16, #0xfb0
   6cf6c:      	br	x17

000000000006cf70 <HIAI_NDTensorDesc_GetByteSize@plt>:
   6cf70:      	adrp	x16, 0x73000
   6cf74:      	ldr	x17, [x16, #0xfb8]
   6cf78:      	add	x16, x16, #0xfb8
   6cf7c:      	br	x17

000000000006cf80 <getauxval@plt>:
   6cf80:      	adrp	x16, 0x73000
   6cf84:      	ldr	x17, [x16, #0xfc0]
   6cf88:      	add	x16, x16, #0xfc0
   6cf8c:      	br	x17

000000000006cf90 <__system_property_get@plt>:
   6cf90:      	adrp	x16, 0x73000
   6cf94:      	ldr	x17, [x16, #0xfc8]
   6cf98:      	add	x16, x16, #0xfc8
   6cf9c:      	br	x17
