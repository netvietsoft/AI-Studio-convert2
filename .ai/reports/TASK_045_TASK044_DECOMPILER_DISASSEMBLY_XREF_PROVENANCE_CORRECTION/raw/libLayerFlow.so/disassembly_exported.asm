// EXPORTED & PLT DISASSEMBLY FOR libLayerFlow.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libLayerFlow.so (SHA-256: EF8D1581038778B72ABCA3CA8FD5046E49FD44E0465871B023647FE42A582262)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 6503, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libLayerFlow.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000052a210 <.plt>:
  52a210:      	stp	x16, x30, [sp, #-0x10]!
  52a214:      	adrp	x16, 0x54b000
  52a218:      	ldr	x17, [x16, #0x778]
  52a21c:      	add	x16, x16, #0x778
  52a220:      	br	x17
  52a224:      	nop
  52a228:      	nop
  52a22c:      	nop

000000000052a230 <__cxa_finalize@plt>:
  52a230:      	adrp	x16, 0x54b000
  52a234:      	ldr	x17, [x16, #0x780]
  52a238:      	add	x16, x16, #0x780
  52a23c:      	br	x17

000000000052a240 <__cxa_atexit@plt>:
  52a240:      	adrp	x16, 0x54b000
  52a244:      	ldr	x17, [x16, #0x788]
  52a248:      	add	x16, x16, #0x788
  52a24c:      	br	x17

000000000052a250 <__android_log_print@plt>:
  52a250:      	adrp	x16, 0x54b000
  52a254:      	ldr	x17, [x16, #0x790]
  52a258:      	add	x16, x16, #0x790
  52a25c:      	br	x17

000000000052a260 <__stack_chk_fail@plt>:
  52a260:      	adrp	x16, 0x54b000
  52a264:      	ldr	x17, [x16, #0x798]
  52a268:      	add	x16, x16, #0x798
  52a26c:      	br	x17

000000000052a270 <_Znwm@plt>:
  52a270:      	adrp	x16, 0x54b000
  52a274:      	ldr	x17, [x16, #0x7a0]
  52a278:      	add	x16, x16, #0x7a0
  52a27c:      	br	x17

000000000052a280 <_ZdlPv@plt>:
  52a280:      	adrp	x16, 0x54b000
  52a284:      	ldr	x17, [x16, #0x7a8]
  52a288:      	add	x16, x16, #0x7a8
  52a28c:      	br	x17

000000000052a290 <_ZN12MTImageKitNS8JniUtils15cString2jStringEP7_JNIEnvRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
  52a290:      	adrp	x16, 0x54b000
  52a294:      	ldr	x17, [x16, #0x7b0]
  52a298:      	add	x16, x16, #0x7b0
  52a29c:      	br	x17

000000000052a2a0 <_ZN12MTImageKitNS8JniUtils15jString2cStringEP7_JNIEnvP8_jstringb@plt>:
  52a2a0:      	adrp	x16, 0x54b000
  52a2a4:      	ldr	x17, [x16, #0x7b8]
  52a2a8:      	add	x16, x16, #0x7b8
  52a2ac:      	br	x17

000000000052a2b0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  52a2b0:      	adrp	x16, 0x54b000
  52a2b4:      	ldr	x17, [x16, #0x7c0]
  52a2b8:      	add	x16, x16, #0x7c0
  52a2bc:      	br	x17

000000000052a2c0 <_ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z@plt>:
  52a2c0:      	adrp	x16, 0x54b000
  52a2c4:      	ldr	x17, [x16, #0x7c8]
  52a2c8:      	add	x16, x16, #0x7c8
  52a2cc:      	br	x17

000000000052a2d0 <_ZN12MTImageKitNS8JniUtils9cMap2jMapEP7_JNIEnvNSt6__ndk13mapIP8_jobjectS6_NS3_4lessIS6_EENS3_9allocatorINS3_4pairIKS6_S6_EEEEEE@plt>:
  52a2d0:      	adrp	x16, 0x54b000
  52a2d4:      	ldr	x17, [x16, #0x7d0]
  52a2d8:      	add	x16, x16, #0x7d0
  52a2dc:      	br	x17

000000000052a2e0 <_ZN12MTImageKitNS8JniUtils13jInteger2cIntEP7_JNIEnvP8_jobject@plt>:
  52a2e0:      	adrp	x16, 0x54b000
  52a2e4:      	ldr	x17, [x16, #0x7d8]
  52a2e8:      	add	x16, x16, #0x7d8
  52a2ec:      	br	x17

000000000052a2f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  52a2f0:      	adrp	x16, 0x54b000
  52a2f4:      	ldr	x17, [x16, #0x7e0]
  52a2f8:      	add	x16, x16, #0x7e0
  52a2fc:      	br	x17

000000000052a300 <_ZN12MTImageKitNS8JniUtils9jMap2cMapEP7_JNIEnvP8_jobject@plt>:
  52a300:      	adrp	x16, 0x54b000
  52a304:      	ldr	x17, [x16, #0x7e8]
  52a308:      	add	x16, x16, #0x7e8
  52a30c:      	br	x17

000000000052a310 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  52a310:      	adrp	x16, 0x54b000
  52a314:      	ldr	x17, [x16, #0x7f0]
  52a318:      	add	x16, x16, #0x7f0
  52a31c:      	br	x17

000000000052a320 <memcpy@plt>:
  52a320:      	adrp	x16, 0x54b000
  52a324:      	ldr	x17, [x16, #0x7f8]
  52a328:      	add	x16, x16, #0x7f8
  52a32c:      	br	x17

000000000052a330 <__cxa_allocate_exception@plt>:
  52a330:      	adrp	x16, 0x54b000
  52a334:      	ldr	x17, [x16, #0x800]
  52a338:      	add	x16, x16, #0x800
  52a33c:      	br	x17

000000000052a340 <__cxa_throw@plt>:
  52a340:      	adrp	x16, 0x54b000
  52a344:      	ldr	x17, [x16, #0x808]
  52a348:      	add	x16, x16, #0x808
  52a34c:      	br	x17

000000000052a350 <__cxa_free_exception@plt>:
  52a350:      	adrp	x16, 0x54b000
  52a354:      	ldr	x17, [x16, #0x810]
  52a358:      	add	x16, x16, #0x810
  52a35c:      	br	x17

000000000052a360 <_ZNSt11logic_errorC2EPKc@plt>:
  52a360:      	adrp	x16, 0x54b000
  52a364:      	ldr	x17, [x16, #0x818]
  52a368:      	add	x16, x16, #0x818
  52a36c:      	br	x17

000000000052a370 <memmove@plt>:
  52a370:      	adrp	x16, 0x54b000
  52a374:      	ldr	x17, [x16, #0x820]
  52a378:      	add	x16, x16, #0x820
  52a37c:      	br	x17

000000000052a380 <_ZNSt9exceptionD2Ev@plt>:
  52a380:      	adrp	x16, 0x54b000
  52a384:      	ldr	x17, [x16, #0x828]
  52a388:      	add	x16, x16, #0x828
  52a38c:      	br	x17

000000000052a390 <_ZNKSt9exception4whatEv@plt>:
  52a390:      	adrp	x16, 0x54b000
  52a394:      	ldr	x17, [x16, #0x830]
  52a398:      	add	x16, x16, #0x830
  52a39c:      	br	x17

000000000052a3a0 <_ZN12MTImageKitNS8JniUtils13cVector2jListEP7_JNIEnvNSt6__ndk16vectorIP8_jobjectNS3_9allocatorIS6_EEEE@plt>:
  52a3a0:      	adrp	x16, 0x54b000
  52a3a4:      	ldr	x17, [x16, #0x838]
  52a3a8:      	add	x16, x16, #0x838
  52a3ac:      	br	x17

000000000052a3b0 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  52a3b0:      	adrp	x16, 0x54b000
  52a3b4:      	ldr	x17, [x16, #0x840]
  52a3b8:      	add	x16, x16, #0x840
  52a3bc:      	br	x17

000000000052a3c0 <__cxa_begin_catch@plt>:
  52a3c0:      	adrp	x16, 0x54b000
  52a3c4:      	ldr	x17, [x16, #0x848]
  52a3c8:      	add	x16, x16, #0x848
  52a3cc:      	br	x17

000000000052a3d0 <_ZSt9terminatev@plt>:
  52a3d0:      	adrp	x16, 0x54b000
  52a3d4:      	ldr	x17, [x16, #0x850]
  52a3d8:      	add	x16, x16, #0x850
  52a3dc:      	br	x17

000000000052a3e0 <strlen@plt>:
  52a3e0:      	adrp	x16, 0x54b000
  52a3e4:      	ldr	x17, [x16, #0x858]
  52a3e8:      	add	x16, x16, #0x858
  52a3ec:      	br	x17

000000000052a3f0 <memset@plt>:
  52a3f0:      	adrp	x16, 0x54b000
  52a3f4:      	ldr	x17, [x16, #0x860]
  52a3f8:      	add	x16, x16, #0x860
  52a3fc:      	br	x17

000000000052a400 <memcmp@plt>:
  52a400:      	adrp	x16, 0x54b000
  52a404:      	ldr	x17, [x16, #0x868]
  52a408:      	add	x16, x16, #0x868
  52a40c:      	br	x17

000000000052a410 <_ZN12MTImageKitNS24CMTIKFaceResultJniDecode11cModelToObjEP7_JNIEnvRKNS_15CMTIKFaceResultE@plt>:
  52a410:      	adrp	x16, 0x54b000
  52a414:      	ldr	x17, [x16, #0x870]
  52a418:      	add	x16, x16, #0x870
  52a41c:      	br	x17

000000000052a420 <_ZN12MTImageKitNS5Image9getHeightEv@plt>:
  52a420:      	adrp	x16, 0x54b000
  52a424:      	ldr	x17, [x16, #0x878]
  52a428:      	add	x16, x16, #0x878
  52a42c:      	br	x17

000000000052a430 <_ZN12MTImageKitNS5Image8getWidthEv@plt>:
  52a430:      	adrp	x16, 0x54b000
  52a434:      	ldr	x17, [x16, #0x880]
  52a438:      	add	x16, x16, #0x880
  52a43c:      	br	x17

000000000052a440 <_ZN12MTImageKitNS12BitmapCreateEP7_JNIEnviiRKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
  52a440:      	adrp	x16, 0x54b000
  52a444:      	ldr	x17, [x16, #0x888]
  52a448:      	add	x16, x16, #0x888
  52a44c:      	br	x17

000000000052a450 <_ZNK12MTImageKitNS5Image9imageDataEv@plt>:
  52a450:      	adrp	x16, 0x54b000
  52a454:      	ldr	x17, [x16, #0x890]
  52a458:      	add	x16, x16, #0x890
  52a45c:      	br	x17

000000000052a460 <_ZN12MTImageKitNS11BYTE2BitmapEP7_JNIEnvP8_jobjectPhiib@plt>:
  52a460:      	adrp	x16, 0x54b000
  52a464:      	ldr	x17, [x16, #0x898]
  52a468:      	add	x16, x16, #0x898
  52a46c:      	br	x17

000000000052a470 <_ZN12MTImageKitNS8JniUtils13jList2cVectorEP7_JNIEnvP8_jobject@plt>:
  52a470:      	adrp	x16, 0x54b000
  52a474:      	ldr	x17, [x16, #0x8a0]
  52a478:      	add	x16, x16, #0x8a0
  52a47c:      	br	x17

000000000052a480 <_Znam@plt>:
  52a480:      	adrp	x16, 0x54b000
  52a484:      	ldr	x17, [x16, #0x8a8]
  52a488:      	add	x16, x16, #0x8a8
  52a48c:      	br	x17

000000000052a490 <_ZN12MTImageKitNS12Bitmap2ImageEP7_JNIEnvP8_jobjectb@plt>:
  52a490:      	adrp	x16, 0x54b000
  52a494:      	ldr	x17, [x16, #0x8b0]
  52a498:      	add	x16, x16, #0x8b0
  52a49c:      	br	x17

000000000052a4a0 <__cxa_guard_acquire@plt>:
  52a4a0:      	adrp	x16, 0x54b000
  52a4a4:      	ldr	x17, [x16, #0x8b8]
  52a4a8:      	add	x16, x16, #0x8b8
  52a4ac:      	br	x17

000000000052a4b0 <__cxa_guard_release@plt>:
  52a4b0:      	adrp	x16, 0x54b000
  52a4b4:      	ldr	x17, [x16, #0x8c0]
  52a4b8:      	add	x16, x16, #0x8c0
  52a4bc:      	br	x17

000000000052a4c0 <_ZN12MTImageKitNS19MTIKParamConvertJni19getMTIKMaterialInfoEP7_JNIEnvP8_jobjectRNS_17CMTIKMaterialInfoE@plt>:
  52a4c0:      	adrp	x16, 0x54b000
  52a4c4:      	ldr	x17, [x16, #0x8c8]
  52a4c8:      	add	x16, x16, #0x8c8
  52a4cc:      	br	x17

000000000052a4d0 <_ZNSt6__ndk19to_stringEi@plt>:
  52a4d0:      	adrp	x16, 0x54b000
  52a4d4:      	ldr	x17, [x16, #0x8d0]
  52a4d8:      	add	x16, x16, #0x8d0
  52a4dc:      	br	x17

000000000052a4e0 <_ZN12MTImageKitNS8CMTIKLog3logEiPKcz@plt>:
  52a4e0:      	adrp	x16, 0x54b000
  52a4e4:      	ldr	x17, [x16, #0x8d8]
  52a4e8:      	add	x16, x16, #0x8d8
  52a4ec:      	br	x17

000000000052a4f0 <_ZN12MTImageKitNS15CMTIKCacheImage8getImageEPhii@plt>:
  52a4f0:      	adrp	x16, 0x54b000
  52a4f4:      	ldr	x17, [x16, #0x8e0]
  52a4f8:      	add	x16, x16, #0x8e0
  52a4fc:      	br	x17

000000000052a500 <_ZN12MTImageKitNS15CMTIKCacheImage7getPathEv@plt>:
  52a500:      	adrp	x16, 0x54b000
  52a504:      	ldr	x17, [x16, #0x8e8]
  52a508:      	add	x16, x16, #0x8e8
  52a50c:      	br	x17

000000000052a510 <_ZN12MTImageKitNS13CMTIKFileTool6getDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52a510:      	adrp	x16, 0x54b000
  52a514:      	ldr	x17, [x16, #0x8f0]
  52a518:      	add	x16, x16, #0x8f0
  52a51c:      	br	x17

000000000052a520 <_ZN12MTImageKitNS13CMTIKFileTool11dirIsExistsENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52a520:      	adrp	x16, 0x54b000
  52a524:      	ldr	x17, [x16, #0x8f8]
  52a528:      	add	x16, x16, #0x8f8
  52a52c:      	br	x17

000000000052a530 <_ZN12MTImageKitNS13CMTIKFileTool6mkdirsENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52a530:      	adrp	x16, 0x54b000
  52a534:      	ldr	x17, [x16, #0x900]
  52a538:      	add	x16, x16, #0x900
  52a53c:      	br	x17

000000000052a540 <_ZN12MTImageKitNS9CMTIKUuid6createEv@plt>:
  52a540:      	adrp	x16, 0x54b000
  52a544:      	ldr	x17, [x16, #0x908]
  52a548:      	add	x16, x16, #0x908
  52a54c:      	br	x17

000000000052a550 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  52a550:      	adrp	x16, 0x54b000
  52a554:      	ldr	x17, [x16, #0x910]
  52a558:      	add	x16, x16, #0x910
  52a55c:      	br	x17

000000000052a560 <_ZN12MTImageKitNS15CMTIKCacheImageC1ENSt6__ndk110shared_ptrINS_5ImageEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52a560:      	adrp	x16, 0x54b000
  52a564:      	ldr	x17, [x16, #0x918]
  52a568:      	add	x16, x16, #0x918
  52a56c:      	br	x17

000000000052a570 <_ZN12MTImageKitNS15CMTIKCacheImageD1Ev@plt>:
  52a570:      	adrp	x16, 0x54b000
  52a574:      	ldr	x17, [x16, #0x920]
  52a578:      	add	x16, x16, #0x920
  52a57c:      	br	x17

000000000052a580 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
  52a580:      	adrp	x16, 0x54b000
  52a584:      	ldr	x17, [x16, #0x928]
  52a588:      	add	x16, x16, #0x928
  52a58c:      	br	x17

000000000052a590 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  52a590:      	adrp	x16, 0x54b000
  52a594:      	ldr	x17, [x16, #0x930]
  52a598:      	add	x16, x16, #0x930
  52a59c:      	br	x17

000000000052a5a0 <_ZNSt13runtime_errorC1EPKc@plt>:
  52a5a0:      	adrp	x16, 0x54b000
  52a5a4:      	ldr	x17, [x16, #0x938]
  52a5a8:      	add	x16, x16, #0x938
  52a5ac:      	br	x17

000000000052a5b0 <__strlen_chk@plt>:
  52a5b0:      	adrp	x16, 0x54b000
  52a5b4:      	ldr	x17, [x16, #0x940]
  52a5b8:      	add	x16, x16, #0x940
  52a5bc:      	br	x17

000000000052a5c0 <_ZNSt13runtime_errorD1Ev@plt>:
  52a5c0:      	adrp	x16, 0x54b000
  52a5c4:      	ldr	x17, [x16, #0x948]
  52a5c8:      	add	x16, x16, #0x948
  52a5cc:      	br	x17

000000000052a5d0 <_ZNKSt13runtime_error4whatEv@plt>:
  52a5d0:      	adrp	x16, 0x54b000
  52a5d4:      	ldr	x17, [x16, #0x950]
  52a5d8:      	add	x16, x16, #0x950
  52a5dc:      	br	x17

000000000052a5e0 <_ZN12MTImageKitNS12MTStringUtil12string2ColorERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_5_Vec4IfEEf@plt>:
  52a5e0:      	adrp	x16, 0x54b000
  52a5e4:      	ldr	x17, [x16, #0x958]
  52a5e8:      	add	x16, x16, #0x958
  52a5ec:      	br	x17

000000000052a5f0 <sincos@plt>:
  52a5f0:      	adrp	x16, 0x54b000
  52a5f4:      	ldr	x17, [x16, #0x960]
  52a5f8:      	add	x16, x16, #0x960
  52a5fc:      	br	x17

000000000052a600 <_ZNSt6__ndk15mutexD1Ev@plt>:
  52a600:      	adrp	x16, 0x54b000
  52a604:      	ldr	x17, [x16, #0x968]
  52a608:      	add	x16, x16, #0x968
  52a60c:      	br	x17

000000000052a610 <__emutls_get_address@plt>:
  52a610:      	adrp	x16, 0x54b000
  52a614:      	ldr	x17, [x16, #0x970]
  52a618:      	add	x16, x16, #0x970
  52a61c:      	br	x17

000000000052a620 <__cxa_end_catch@plt>:
  52a620:      	adrp	x16, 0x54b000
  52a624:      	ldr	x17, [x16, #0x978]
  52a628:      	add	x16, x16, #0x978
  52a62c:      	br	x17

000000000052a630 <_ZNSt6__ndk115recursive_mutexC1Ev@plt>:
  52a630:      	adrp	x16, 0x54b000
  52a634:      	ldr	x17, [x16, #0x980]
  52a638:      	add	x16, x16, #0x980
  52a63c:      	br	x17

000000000052a640 <_ZNSt6__ndk115recursive_mutexD1Ev@plt>:
  52a640:      	adrp	x16, 0x54b000
  52a644:      	ldr	x17, [x16, #0x988]
  52a648:      	add	x16, x16, #0x988
  52a64c:      	br	x17

000000000052a650 <_ZNSt6__ndk115recursive_mutex4lockEv@plt>:
  52a650:      	adrp	x16, 0x54b000
  52a654:      	ldr	x17, [x16, #0x990]
  52a658:      	add	x16, x16, #0x990
  52a65c:      	br	x17

000000000052a660 <_ZN12MTImageKitNS7Context23sharedProcessingContextEv@plt>:
  52a660:      	adrp	x16, 0x54b000
  52a664:      	ldr	x17, [x16, #0x998]
  52a668:      	add	x16, x16, #0x998
  52a66c:      	br	x17

000000000052a670 <_ZN12MTImageKitNS7ContextD1Ev@plt>:
  52a670:      	adrp	x16, 0x54b000
  52a674:      	ldr	x17, [x16, #0x9a0]
  52a678:      	add	x16, x16, #0x9a0
  52a67c:      	br	x17

000000000052a680 <_ZNSt6__ndk115recursive_mutex6unlockEv@plt>:
  52a680:      	adrp	x16, 0x54b000
  52a684:      	ldr	x17, [x16, #0x9a8]
  52a688:      	add	x16, x16, #0x9a8
  52a68c:      	br	x17

000000000052a690 <_ZN12MTImageKitNS12CMTIKManager17getPrivateContextEv@plt>:
  52a690:      	adrp	x16, 0x54b000
  52a694:      	ldr	x17, [x16, #0x9b0]
  52a698:      	add	x16, x16, #0x9b0
  52a69c:      	br	x17

000000000052a6a0 <_ZN12MTImageKitNS12CMTIKManager10getFiltersEv@plt>:
  52a6a0:      	adrp	x16, 0x54b000
  52a6a4:      	ldr	x17, [x16, #0x9b8]
  52a6a8:      	add	x16, x16, #0x9b8
  52a6ac:      	br	x17

000000000052a6b0 <_ZN12MTImageKitNS7Context14hasExistFilterEPNS_11CMTIKFilterE@plt>:
  52a6b0:      	adrp	x16, 0x54b000
  52a6b4:      	ldr	x17, [x16, #0x9c0]
  52a6b8:      	add	x16, x16, #0x9c0
  52a6bc:      	br	x17

000000000052a6c0 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
  52a6c0:      	adrp	x16, 0x54b000
  52a6c4:      	ldr	x17, [x16, #0x9c8]
  52a6c8:      	add	x16, x16, #0x9c8
  52a6cc:      	br	x17

000000000052a6d0 <__dynamic_cast@plt>:
  52a6d0:      	adrp	x16, 0x54b000
  52a6d4:      	ldr	x17, [x16, #0x9d0]
  52a6d8:      	add	x16, x16, #0x9d0
  52a6dc:      	br	x17

000000000052a6e0 <_ZNSt6__ndk112__next_primeEm@plt>:
  52a6e0:      	adrp	x16, 0x54b000
  52a6e4:      	ldr	x17, [x16, #0x9d8]
  52a6e8:      	add	x16, x16, #0x9d8
  52a6ec:      	br	x17

000000000052a6f0 <_ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
  52a6f0:      	adrp	x16, 0x54b000
  52a6f4:      	ldr	x17, [x16, #0x9e0]
  52a6f8:      	add	x16, x16, #0x9e0
  52a6fc:      	br	x17

000000000052a700 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  52a700:      	adrp	x16, 0x54b000
  52a704:      	ldr	x17, [x16, #0x9e8]
  52a708:      	add	x16, x16, #0x9e8
  52a70c:      	br	x17

000000000052a710 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  52a710:      	adrp	x16, 0x54b000
  52a714:      	ldr	x17, [x16, #0x9f0]
  52a718:      	add	x16, x16, #0x9f0
  52a71c:      	br	x17

000000000052a720 <_ZNSt6__ndk16localeD1Ev@plt>:
  52a720:      	adrp	x16, 0x54b000
  52a724:      	ldr	x17, [x16, #0x9f8]
  52a728:      	add	x16, x16, #0x9f8
  52a72c:      	br	x17

000000000052a730 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
  52a730:      	adrp	x16, 0x54b000
  52a734:      	ldr	x17, [x16, #0xa00]
  52a738:      	add	x16, x16, #0xa00
  52a73c:      	br	x17

000000000052a740 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  52a740:      	adrp	x16, 0x54b000
  52a744:      	ldr	x17, [x16, #0xa08]
  52a748:      	add	x16, x16, #0xa08
  52a74c:      	br	x17

000000000052a750 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  52a750:      	adrp	x16, 0x54b000
  52a754:      	ldr	x17, [x16, #0xa10]
  52a758:      	add	x16, x16, #0xa10
  52a75c:      	br	x17

000000000052a760 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  52a760:      	adrp	x16, 0x54b000
  52a764:      	ldr	x17, [x16, #0xa18]
  52a768:      	add	x16, x16, #0xa18
  52a76c:      	br	x17

000000000052a770 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
  52a770:      	adrp	x16, 0x54b000
  52a774:      	ldr	x17, [x16, #0xa20]
  52a778:      	add	x16, x16, #0xa20
  52a77c:      	br	x17

000000000052a780 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  52a780:      	adrp	x16, 0x54b000
  52a784:      	ldr	x17, [x16, #0xa28]
  52a788:      	add	x16, x16, #0xa28
  52a78c:      	br	x17

000000000052a790 <__cxa_rethrow@plt>:
  52a790:      	adrp	x16, 0x54b000
  52a794:      	ldr	x17, [x16, #0xa30]
  52a798:      	add	x16, x16, #0xa30
  52a79c:      	br	x17

000000000052a7a0 <__cxa_guard_abort@plt>:
  52a7a0:      	adrp	x16, 0x54b000
  52a7a4:      	ldr	x17, [x16, #0xa38]
  52a7a8:      	add	x16, x16, #0xa38
  52a7ac:      	br	x17

000000000052a7b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  52a7b0:      	adrp	x16, 0x54b000
  52a7b4:      	ldr	x17, [x16, #0xa40]
  52a7b8:      	add	x16, x16, #0xa40
  52a7bc:      	br	x17

000000000052a7c0 <_ZN12MTImageKitNS6FileIO14CheckFileExistEPKc@plt>:
  52a7c0:      	adrp	x16, 0x54b000
  52a7c4:      	ldr	x17, [x16, #0xa48]
  52a7c8:      	add	x16, x16, #0xa48
  52a7cc:      	br	x17

000000000052a7d0 <opendir@plt>:
  52a7d0:      	adrp	x16, 0x54b000
  52a7d4:      	ldr	x17, [x16, #0xa50]
  52a7d8:      	add	x16, x16, #0xa50
  52a7dc:      	br	x17

000000000052a7e0 <readdir@plt>:
  52a7e0:      	adrp	x16, 0x54b000
  52a7e4:      	ldr	x17, [x16, #0xa58]
  52a7e8:      	add	x16, x16, #0xa58
  52a7ec:      	br	x17

000000000052a7f0 <_ZNSt6__ndk15stollERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
  52a7f0:      	adrp	x16, 0x54b000
  52a7f4:      	ldr	x17, [x16, #0xa60]
  52a7f8:      	add	x16, x16, #0xa60
  52a7fc:      	br	x17

000000000052a800 <closedir@plt>:
  52a800:      	adrp	x16, 0x54b000
  52a804:      	ldr	x17, [x16, #0xa68]
  52a808:      	add	x16, x16, #0xa68
  52a80c:      	br	x17

000000000052a810 <localeconv@plt>:
  52a810:      	adrp	x16, 0x54b000
  52a814:      	ldr	x17, [x16, #0xa70]
  52a818:      	add	x16, x16, #0xa70
  52a81c:      	br	x17

000000000052a820 <_ZNSt6__ndk19to_stringEm@plt>:
  52a820:      	adrp	x16, 0x54b000
  52a824:      	ldr	x17, [x16, #0xa78]
  52a828:      	add	x16, x16, #0xa78
  52a82c:      	br	x17

000000000052a830 <__vsnprintf_chk@plt>:
  52a830:      	adrp	x16, 0x54b000
  52a834:      	ldr	x17, [x16, #0xa80]
  52a838:      	add	x16, x16, #0xa80
  52a83c:      	br	x17

000000000052a840 <_ZNSt13runtime_errorC1ERKS_@plt>:
  52a840:      	adrp	x16, 0x54b000
  52a844:      	ldr	x17, [x16, #0xa88]
  52a848:      	add	x16, x16, #0xa88
  52a84c:      	br	x17

000000000052a850 <__errno@plt>:
  52a850:      	adrp	x16, 0x54b000
  52a854:      	ldr	x17, [x16, #0xa90]
  52a858:      	add	x16, x16, #0xa90
  52a85c:      	br	x17

000000000052a860 <strtoull@plt>:
  52a860:      	adrp	x16, 0x54b000
  52a864:      	ldr	x17, [x16, #0xa98]
  52a868:      	add	x16, x16, #0xa98
  52a86c:      	br	x17

000000000052a870 <strtoll@plt>:
  52a870:      	adrp	x16, 0x54b000
  52a874:      	ldr	x17, [x16, #0xaa0]
  52a878:      	add	x16, x16, #0xaa0
  52a87c:      	br	x17

000000000052a880 <strtod@plt>:
  52a880:      	adrp	x16, 0x54b000
  52a884:      	ldr	x17, [x16, #0xaa8]
  52a888:      	add	x16, x16, #0xaa8
  52a88c:      	br	x17

000000000052a890 <_ZNK12MTImageKitNS4pugi8xml_node5childEPKc@plt>:
  52a890:      	adrp	x16, 0x54b000
  52a894:      	ldr	x17, [x16, #0xab0]
  52a898:      	add	x16, x16, #0xab0
  52a89c:      	br	x17

000000000052a8a0 <_ZNK12MTImageKitNS4pugi8xml_node4textEv@plt>:
  52a8a0:      	adrp	x16, 0x54b000
  52a8a4:      	ldr	x17, [x16, #0xab8]
  52a8a8:      	add	x16, x16, #0xab8
  52a8ac:      	br	x17

000000000052a8b0 <_ZNK12MTImageKitNS4pugi8xml_textcvPFvPPPS1_EEv@plt>:
  52a8b0:      	adrp	x16, 0x54b000
  52a8b4:      	ldr	x17, [x16, #0xac0]
  52a8b8:      	add	x16, x16, #0xac0
  52a8bc:      	br	x17

000000000052a8c0 <_ZNK12MTImageKitNS4pugi8xml_text7as_boolEb@plt>:
  52a8c0:      	adrp	x16, 0x54b000
  52a8c4:      	ldr	x17, [x16, #0xac8]
  52a8c8:      	add	x16, x16, #0xac8
  52a8cc:      	br	x17

000000000052a8d0 <_ZN12MTImageKitNS6FileIO15ReadFile2StringEPKcRmb@plt>:
  52a8d0:      	adrp	x16, 0x54b000
  52a8d4:      	ldr	x17, [x16, #0xad0]
  52a8d8:      	add	x16, x16, #0xad0
  52a8dc:      	br	x17

000000000052a8e0 <_ZN12MTImageKitNS4pugi12xml_documentC1Ev@plt>:
  52a8e0:      	adrp	x16, 0x54b000
  52a8e4:      	ldr	x17, [x16, #0xad8]
  52a8e8:      	add	x16, x16, #0xad8
  52a8ec:      	br	x17

000000000052a8f0 <_ZN12MTImageKitNS4pugi12xml_document4loadEPKcj@plt>:
  52a8f0:      	adrp	x16, 0x54b000
  52a8f4:      	ldr	x17, [x16, #0xae0]
  52a8f8:      	add	x16, x16, #0xae0
  52a8fc:      	br	x17

000000000052a900 <_ZdaPv@plt>:
  52a900:      	adrp	x16, 0x54b000
  52a904:      	ldr	x17, [x16, #0xae8]
  52a908:      	add	x16, x16, #0xae8
  52a90c:      	br	x17

000000000052a910 <_ZNK12MTImageKitNS4pugi16xml_parse_resultcvbEv@plt>:
  52a910:      	adrp	x16, 0x54b000
  52a914:      	ldr	x17, [x16, #0xaf0]
  52a918:      	add	x16, x16, #0xaf0
  52a91c:      	br	x17

000000000052a920 <_ZNK12MTImageKitNS4pugi12xml_document16document_elementEv@plt>:
  52a920:      	adrp	x16, 0x54b000
  52a924:      	ldr	x17, [x16, #0xaf8]
  52a928:      	add	x16, x16, #0xaf8
  52a92c:      	br	x17

000000000052a930 <_ZNK12MTImageKitNS4pugi16xml_parse_result11descriptionEv@plt>:
  52a930:      	adrp	x16, 0x54b000
  52a934:      	ldr	x17, [x16, #0xb00]
  52a938:      	add	x16, x16, #0xb00
  52a93c:      	br	x17

000000000052a940 <_ZNK12MTImageKitNS4pugi8xml_text9as_stringEPKc@plt>:
  52a940:      	adrp	x16, 0x54b000
  52a944:      	ldr	x17, [x16, #0xb08]
  52a948:      	add	x16, x16, #0xb08
  52a94c:      	br	x17

000000000052a950 <_ZN12MTImageKitNS4pugi12xml_documentD1Ev@plt>:
  52a950:      	adrp	x16, 0x54b000
  52a954:      	ldr	x17, [x16, #0xb10]
  52a958:      	add	x16, x16, #0xb10
  52a95c:      	br	x17

000000000052a960 <_ZNSt6__ndk19to_stringEl@plt>:
  52a960:      	adrp	x16, 0x54b000
  52a964:      	ldr	x17, [x16, #0xb18]
  52a968:      	add	x16, x16, #0xb18
  52a96c:      	br	x17

000000000052a970 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
  52a970:      	adrp	x16, 0x54b000
  52a974:      	ldr	x17, [x16, #0xb20]
  52a978:      	add	x16, x16, #0xb20
  52a97c:      	br	x17

000000000052a980 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
  52a980:      	adrp	x16, 0x54b000
  52a984:      	ldr	x17, [x16, #0xb28]
  52a988:      	add	x16, x16, #0xb28
  52a98c:      	br	x17

000000000052a990 <_ZNSt6__ndk15mutex4lockEv@plt>:
  52a990:      	adrp	x16, 0x54b000
  52a994:      	ldr	x17, [x16, #0xb30]
  52a998:      	add	x16, x16, #0xb30
  52a99c:      	br	x17

000000000052a9a0 <_ZNSt6__ndk15mutex6unlockEv@plt>:
  52a9a0:      	adrp	x16, 0x54b000
  52a9a4:      	ldr	x17, [x16, #0xb38]
  52a9a8:      	add	x16, x16, #0xb38
  52a9ac:      	br	x17

000000000052a9b0 <_ZN12MTImageKitNS23CMTIKGlobalCommonConfig11setAutotestEb@plt>:
  52a9b0:      	adrp	x16, 0x54b000
  52a9b4:      	ldr	x17, [x16, #0xb40]
  52a9b8:      	add	x16, x16, #0xb40
  52a9bc:      	br	x17

000000000052a9c0 <_ZN12MTImageKitNS13CMTIKFaceDataC1Ev@plt>:
  52a9c0:      	adrp	x16, 0x54b000
  52a9c4:      	ldr	x17, [x16, #0xb48]
  52a9c8:      	add	x16, x16, #0xb48
  52a9cc:      	br	x17

000000000052a9d0 <_ZN12MTImageKitNS12Image2BitmapEP7_JNIEnvNSt6__ndk110shared_ptrINS_5ImageEEEb@plt>:
  52a9d0:      	adrp	x16, 0x54b000
  52a9d4:      	ldr	x17, [x16, #0xb50]
  52a9d8:      	add	x16, x16, #0xb50
  52a9dc:      	br	x17

000000000052a9e0 <_ZN12MTImageKitNS8JniUtils18jintArrayTocIntVecEP7_JNIEnvP10_jintArray@plt>:
  52a9e0:      	adrp	x16, 0x54b000
  52a9e4:      	ldr	x17, [x16, #0xb58]
  52a9e8:      	add	x16, x16, #0xb58
  52a9ec:      	br	x17

000000000052a9f0 <_ZN12NativeBitmapC1Ev@plt>:
  52a9f0:      	adrp	x16, 0x54b000
  52a9f4:      	ldr	x17, [x16, #0xb60]
  52a9f8:      	add	x16, x16, #0xb60
  52a9fc:      	br	x17

000000000052aa00 <_ZN12NativeBitmap9setPixelsEPhii@plt>:
  52aa00:      	adrp	x16, 0x54b000
  52aa04:      	ldr	x17, [x16, #0xb68]
  52aa08:      	add	x16, x16, #0xb68
  52aa0c:      	br	x17

000000000052aa10 <_ZN12MTImageKitNS12CMTIKManager10releaseResEv@plt>:
  52aa10:      	adrp	x16, 0x54b000
  52aa14:      	ldr	x17, [x16, #0xb70]
  52aa18:      	add	x16, x16, #0xb70
  52aa1c:      	br	x17

000000000052aa20 <_ZN12MTImageKitNS7Context13removeContextEPS0_@plt>:
  52aa20:      	adrp	x16, 0x54b000
  52aa24:      	ldr	x17, [x16, #0xb78]
  52aa28:      	add	x16, x16, #0xb78
  52aa2c:      	br	x17

000000000052aa30 <_ZN12MTImageKitNS8cRunSyncERKNSt6__ndk18functionIFvvEEEPNS_7ContextENS0_12basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
  52aa30:      	adrp	x16, 0x54b000
  52aa34:      	ldr	x17, [x16, #0xb80]
  52aa38:      	add	x16, x16, #0xb80
  52aa3c:      	br	x17

000000000052aa40 <_ZN12MTImageKitNS20CMTIKAiEngineManager16releaseDetectResEb@plt>:
  52aa40:      	adrp	x16, 0x54b000
  52aa44:      	ldr	x17, [x16, #0xb88]
  52aa48:      	add	x16, x16, #0xb88
  52aa4c:      	br	x17

000000000052aa50 <_ZN12MTImageKitNS20CMTIKAiEngineManager13getNativeFaceEv@plt>:
  52aa50:      	adrp	x16, 0x54b000
  52aa54:      	ldr	x17, [x16, #0xb90]
  52aa58:      	add	x16, x16, #0xb90
  52aa5c:      	br	x17

000000000052aa60 <_ZN12MTImageKitNS15CMTIKFaceResult16updateFaceResultEPS0_b@plt>:
  52aa60:      	adrp	x16, 0x54b000
  52aa64:      	ldr	x17, [x16, #0xb98]
  52aa68:      	add	x16, x16, #0xb98
  52aa6c:      	br	x17

000000000052aa70 <_ZN12MTImageKitNS15CMTIKFaceResultD1Ev@plt>:
  52aa70:      	adrp	x16, 0x54b000
  52aa74:      	ldr	x17, [x16, #0xba0]
  52aa78:      	add	x16, x16, #0xba0
  52aa7c:      	br	x17

000000000052aa80 <_ZN12MTImageKitNS5ImageC1EPS0_@plt>:
  52aa80:      	adrp	x16, 0x54b000
  52aa84:      	ldr	x17, [x16, #0xba8]
  52aa88:      	add	x16, x16, #0xba8
  52aa8c:      	br	x17

000000000052aa90 <_ZN12MTImageKitNS5Image11limitLengthEiNS_15CMTIKFilterModeE@plt>:
  52aa90:      	adrp	x16, 0x54b000
  52aa94:      	ldr	x17, [x16, #0xbb0]
  52aa98:      	add	x16, x16, #0xbb0
  52aa9c:      	br	x17

000000000052aaa0 <_ZN12MTImageKitNS19CMTIKVLAIFaceDetect11imageDetectENSt6__ndk110shared_ptrINS_5ImageEEENS_21CMTIKFaceDetectSwitchENS2_INS_15CMTIKFaceResultEEENS_15CMTIKFaceParamsEi@plt>:
  52aaa0:      	adrp	x16, 0x54b000
  52aaa4:      	ldr	x17, [x16, #0xbb8]
  52aaa8:      	add	x16, x16, #0xbb8
  52aaac:      	br	x17

000000000052aab0 <_ZN12MTImageKitNS20CMTIKAiEngineManager13setNativeFaceENS_15CMTIKFaceResultE@plt>:
  52aab0:      	adrp	x16, 0x54b000
  52aab4:      	ldr	x17, [x16, #0xbc0]
  52aab8:      	add	x16, x16, #0xbc0
  52aabc:      	br	x17

000000000052aac0 <_ZN12MTImageKitNS12CMTIKManager13processRenderEb@plt>:
  52aac0:      	adrp	x16, 0x54b000
  52aac4:      	ldr	x17, [x16, #0xbc8]
  52aac8:      	add	x16, x16, #0xbc8
  52aacc:      	br	x17

000000000052aad0 <_ZN12MTImageKitNS12CMTIKManager21setSrcImageWithResultEv@plt>:
  52aad0:      	adrp	x16, 0x54b000
  52aad4:      	ldr	x17, [x16, #0xbd0]
  52aad8:      	add	x16, x16, #0xbd0
  52aadc:      	br	x17

000000000052aae0 <_ZN12MTImageKitNS12CMTIKManager8dumpDataENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52aae0:      	adrp	x16, 0x54b000
  52aae4:      	ldr	x17, [x16, #0xbd8]
  52aae8:      	add	x16, x16, #0xbd8
  52aaec:      	br	x17

000000000052aaf0 <_ZN12MTImageKitNS17CMTIKVideoManager10existVideoEv@plt>:
  52aaf0:      	adrp	x16, 0x54b000
  52aaf4:      	ldr	x17, [x16, #0xbe0]
  52aaf8:      	add	x16, x16, #0xbe0
  52aafc:      	br	x17

000000000052ab00 <_ZN12MTImageKitNS12CMTIKManager12removeFilterElbbb@plt>:
  52ab00:      	adrp	x16, 0x54b000
  52ab04:      	ldr	x17, [x16, #0xbe8]
  52ab08:      	add	x16, x16, #0xbe8
  52ab0c:      	br	x17

000000000052ab10 <_ZN12MTImageKitNS12CMTIKManager9getFilterEl@plt>:
  52ab10:      	adrp	x16, 0x54b000
  52ab14:      	ldr	x17, [x16, #0xbf0]
  52ab18:      	add	x16, x16, #0xbf0
  52ab1c:      	br	x17

000000000052ab20 <_ZN12MTImageKitNS18CMTIKAIGCNetStatus16setInterruptAIGCEb@plt>:
  52ab20:      	adrp	x16, 0x54b000
  52ab24:      	ldr	x17, [x16, #0xbf8]
  52ab28:      	add	x16, x16, #0xbf8
  52ab2c:      	br	x17

000000000052ab30 <_ZN12MTImageKitNS5ImageD1Ev@plt>:
  52ab30:      	adrp	x16, 0x54b000
  52ab34:      	ldr	x17, [x16, #0xc00]
  52ab38:      	add	x16, x16, #0xc00
  52ab3c:      	br	x17

000000000052ab40 <_ZN12MTImageKitNS7Context14setProjectTypeENS_18CMTIKProjectType_TE@plt>:
  52ab40:      	adrp	x16, 0x54b000
  52ab44:      	ldr	x17, [x16, #0xc08]
  52ab48:      	add	x16, x16, #0xc08
  52ab4c:      	br	x17

000000000052ab50 <_ZN12MTImageKitNS12CMTIKManager11setSrcImageEPhiib@plt>:
  52ab50:      	adrp	x16, 0x54b000
  52ab54:      	ldr	x17, [x16, #0xc10]
  52ab58:      	add	x16, x16, #0xc10
  52ab5c:      	br	x17

000000000052ab60 <_ZN12MTImageKitNS12CMTIKManager9setFEModeENS_12FEModeType_TE@plt>:
  52ab60:      	adrp	x16, 0x54b000
  52ab64:      	ldr	x17, [x16, #0xc18]
  52ab68:      	add	x16, x16, #0xc18
  52ab6c:      	br	x17

000000000052ab70 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilterC1Ev@plt>:
  52ab70:      	adrp	x16, 0x54b000
  52ab74:      	ldr	x17, [x16, #0xc20]
  52ab78:      	add	x16, x16, #0xc20
  52ab7c:      	br	x17

000000000052ab80 <_ZN12MTImageKitNS12CMTIKManager9addFilterEPNS_11CMTIKFilterElb@plt>:
  52ab80:      	adrp	x16, 0x54b000
  52ab84:      	ldr	x17, [x16, #0xc28]
  52ab88:      	add	x16, x16, #0xc28
  52ab8c:      	br	x17

000000000052ab90 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter12isLowMachineEv@plt>:
  52ab90:      	adrp	x16, 0x54b000
  52ab94:      	ldr	x17, [x16, #0xc30]
  52ab98:      	add	x16, x16, #0xc30
  52ab9c:      	br	x17

000000000052aba0 <_ZN12MTImageKitNS11CMTIKFilter12setNetHeaderENSt6__ndk110shared_ptrINS_14CMTIKNetHeaderEEE@plt>:
  52aba0:      	adrp	x16, 0x54b000
  52aba4:      	ldr	x17, [x16, #0xc38]
  52aba8:      	add	x16, x16, #0xc38
  52abac:      	br	x17

000000000052abb0 <_ZN12MTImageKitNS21CMTIKRemoveSpotsModelC1Ev@plt>:
  52abb0:      	adrp	x16, 0x54b000
  52abb4:      	ldr	x17, [x16, #0xc40]
  52abb8:      	add	x16, x16, #0xc40
  52abbc:      	br	x17

000000000052abc0 <_ZN12MTImageKitNS20CMTIKRemoveSpotsStepC1Ev@plt>:
  52abc0:      	adrp	x16, 0x54b000
  52abc4:      	ldr	x17, [x16, #0xc48]
  52abc8:      	add	x16, x16, #0xc48
  52abcc:      	br	x17

000000000052abd0 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter18setAutoRemoveSpotsEbib@plt>:
  52abd0:      	adrp	x16, 0x54b000
  52abd4:      	ldr	x17, [x16, #0xc50]
  52abd8:      	add	x16, x16, #0xc50
  52abdc:      	br	x17

000000000052abe0 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter12setCurFaceIDEi@plt>:
  52abe0:      	adrp	x16, 0x54b000
  52abe4:      	ldr	x17, [x16, #0xc58]
  52abe8:      	add	x16, x16, #0xc58
  52abec:      	br	x17

000000000052abf0 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter7setModeEb@plt>:
  52abf0:      	adrp	x16, 0x54b000
  52abf4:      	ldr	x17, [x16, #0xc60]
  52abf8:      	add	x16, x16, #0xc60
  52abfc:      	br	x17

000000000052ac00 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter18getAutoRemoveSpotsEi@plt>:
  52ac00:      	adrp	x16, 0x54b000
  52ac04:      	ldr	x17, [x16, #0xc68]
  52ac08:      	add	x16, x16, #0xc68
  52ac0c:      	br	x17

000000000052ac10 <_ZN12MTImageKitNS11CMTIKFilter14setFormulaModeEb@plt>:
  52ac10:      	adrp	x16, 0x54b000
  52ac14:      	ldr	x17, [x16, #0xc70]
  52ac18:      	add	x16, x16, #0xc70
  52ac1c:      	br	x17

000000000052ac20 <_ZN12MTImageKitNS14CMTIKNetHeader7isVaildEv@plt>:
  52ac20:      	adrp	x16, 0x54b000
  52ac24:      	ldr	x17, [x16, #0xc78]
  52ac28:      	add	x16, x16, #0xc78
  52ac2c:      	br	x17

000000000052ac30 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter22isRemoveSpotExperimentEv@plt>:
  52ac30:      	adrp	x16, 0x54b000
  52ac34:      	ldr	x17, [x16, #0xc80]
  52ac38:      	add	x16, x16, #0xc80
  52ac3c:      	br	x17

000000000052ac40 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter19applyCommonAiEffectEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEb@plt>:
  52ac40:      	adrp	x16, 0x54b000
  52ac44:      	ldr	x17, [x16, #0xc88]
  52ac48:      	add	x16, x16, #0xc88
  52ac4c:      	br	x17

000000000052ac50 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter26getRemoveSpotsRequestParamEbi@plt>:
  52ac50:      	adrp	x16, 0x54b000
  52ac54:      	ldr	x17, [x16, #0xc90]
  52ac58:      	add	x16, x16, #0xc90
  52ac5c:      	br	x17

000000000052ac60 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter25applyFleckFlawClearRenderEbbib@plt>:
  52ac60:      	adrp	x16, 0x54b000
  52ac64:      	ldr	x17, [x16, #0xc98]
  52ac68:      	add	x16, x16, #0xc98
  52ac6c:      	br	x17

000000000052ac70 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter17removeSpotRequestEiNS_26CMTIKRemoveSpotRequestDataENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
  52ac70:      	adrp	x16, 0x54b000
  52ac74:      	ldr	x17, [x16, #0xca0]
  52ac78:      	add	x16, x16, #0xca0
  52ac7c:      	br	x17

000000000052ac80 <_ZN12MTImageKitNS22CMTIKRemoveSpotsFilter17applyAiRemoveSpotEbbiNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52ac80:      	adrp	x16, 0x54b000
  52ac84:      	ldr	x17, [x16, #0xca8]
  52ac88:      	add	x16, x16, #0xca8
  52ac8c:      	br	x17

000000000052ac90 <_ZN12MTImageKitNS12CMTIKManager11setSrcImageENSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52ac90:      	adrp	x16, 0x54b000
  52ac94:      	ldr	x17, [x16, #0xcb0]
  52ac98:      	add	x16, x16, #0xcb0
  52ac9c:      	br	x17

000000000052aca0 <_ZN12MTImageKitNS24CMTIKSmartOptimizeFilterC1Ev@plt>:
  52aca0:      	adrp	x16, 0x54b000
  52aca4:      	ldr	x17, [x16, #0xcb8]
  52aca8:      	add	x16, x16, #0xcb8
  52acac:      	br	x17

000000000052acb0 <_ZN12MTImageKitNS24CMTIKSmartOptimizeFilter22setSmartOptimizeParamsENSt6__ndk16vectorINS_26CMTIKSmartOptimizeParams_TENS1_9allocatorIS3_EEEE@plt>:
  52acb0:      	adrp	x16, 0x54b000
  52acb4:      	ldr	x17, [x16, #0xcc0]
  52acb8:      	add	x16, x16, #0xcc0
  52acbc:      	br	x17

000000000052acc0 <_ZN12MTImageKitNS19CMTIKMagicPenFilterC1Ev@plt>:
  52acc0:      	adrp	x16, 0x54b000
  52acc4:      	ldr	x17, [x16, #0xcc8]
  52acc8:      	add	x16, x16, #0xcc8
  52accc:      	br	x17

000000000052acd0 <_ZN12MTImageKitNS19CMTIKMagicPenFilter21enterAutoMagicPenModeEv@plt>:
  52acd0:      	adrp	x16, 0x54b000
  52acd4:      	ldr	x17, [x16, #0xcd0]
  52acd8:      	add	x16, x16, #0xcd0
  52acdc:      	br	x17

000000000052ace0 <_ZN12MTImageKitNS19CMTIKMagicPenFilter10setDensityEf@plt>:
  52ace0:      	adrp	x16, 0x54b000
  52ace4:      	ldr	x17, [x16, #0xcd8]
  52ace8:      	add	x16, x16, #0xcd8
  52acec:      	br	x17

000000000052acf0 <_ZN12MTImageKitNS19CMTIKMagicPenFilter23setStaticEffectViewSizeENS_5_Vec2IfEEN5mtlab7Vector4E@plt>:
  52acf0:      	adrp	x16, 0x54b000
  52acf4:      	ldr	x17, [x16, #0xce0]
  52acf8:      	add	x16, x16, #0xce0
  52acfc:      	br	x17

000000000052ad00 <_ZN12MTImageKitNS19CMTIKMagicPenFilter24loadAutoMagicPenMaterialENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52ad00:      	adrp	x16, 0x54b000
  52ad04:      	ldr	x17, [x16, #0xce8]
  52ad08:      	add	x16, x16, #0xce8
  52ad0c:      	br	x17

000000000052ad10 <_ZN12MTImageKitNS19CMTIKMagicPenFilter30setAutoMagicPenSubMaterialPathENSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS2_IS8_bNS1_4lessIS8_EENS6_INS1_4pairIKS8_bEEEEEESA_NS6_INSB_ISC_SF_EEEEEE@plt>:
  52ad10:      	adrp	x16, 0x54b000
  52ad14:      	ldr	x17, [x16, #0xcf0]
  52ad18:      	add	x16, x16, #0xcf0
  52ad1c:      	br	x17

000000000052ad20 <_ZN12MTImageKitNS19CMTIKMagicPenFilter23setAutoMagicPenMaskDataENSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
  52ad20:      	adrp	x16, 0x54b000
  52ad24:      	ldr	x17, [x16, #0xcf8]
  52ad28:      	add	x16, x16, #0xcf8
  52ad2c:      	br	x17

000000000052ad30 <_ZN12MTImageKitNS19CMTIKMagicPenFilter23applyAutoMagicPenEffectEb@plt>:
  52ad30:      	adrp	x16, 0x54b000
  52ad34:      	ldr	x17, [x16, #0xd00]
  52ad38:      	add	x16, x16, #0xd00
  52ad3c:      	br	x17

000000000052ad40 <_ZN12MTImageKitNS21CMTIKSkinSoftenFilterC1Ev@plt>:
  52ad40:      	adrp	x16, 0x54b000
  52ad44:      	ldr	x17, [x16, #0xd08]
  52ad48:      	add	x16, x16, #0xd08
  52ad4c:      	br	x17

000000000052ad50 <_ZN12MTImageKitNS19CMTIKSkinSoftenStepC1ENS_19CMTIKSkinSoftenTypeENS_19CMTIKSkinSoftenModeEff@plt>:
  52ad50:      	adrp	x16, 0x54b000
  52ad54:      	ldr	x17, [x16, #0xd10]
  52ad58:      	add	x16, x16, #0xd10
  52ad5c:      	br	x17

000000000052ad60 <_ZN12MTImageKitNS20CMTIKSkinSoftenModel18setSkinSoftenStepsERKNSt6__ndk16vectorINS_19CMTIKSkinSoftenStepENS1_9allocatorIS3_EEEE@plt>:
  52ad60:      	adrp	x16, 0x54b000
  52ad64:      	ldr	x17, [x16, #0xd18]
  52ad68:      	add	x16, x16, #0xd18
  52ad6c:      	br	x17

000000000052ad70 <_ZN12MTImageKitNS21CMTIKSkinSoftenFilter13prepareEffectEv@plt>:
  52ad70:      	adrp	x16, 0x54b000
  52ad74:      	ldr	x17, [x16, #0xd20]
  52ad78:      	add	x16, x16, #0xd20
  52ad7c:      	br	x17

000000000052ad80 <_ZN12MTImageKitNS21CMTIKSkinSoftenFilter17setSkinSoftenModeENS_19CMTIKSkinSoftenModeE@plt>:
  52ad80:      	adrp	x16, 0x54b000
  52ad84:      	ldr	x17, [x16, #0xd28]
  52ad88:      	add	x16, x16, #0xd28
  52ad8c:      	br	x17

000000000052ad90 <_ZN12MTImageKitNS21CMTIKSkinSoftenFilter17setSkinSoftenTypeENS_19CMTIKSkinSoftenTypeE@plt>:
  52ad90:      	adrp	x16, 0x54b000
  52ad94:      	ldr	x17, [x16, #0xd30]
  52ad98:      	add	x16, x16, #0xd30
  52ad9c:      	br	x17

000000000052ada0 <_ZN12MTImageKitNS21CMTIKSkinSoftenFilter21applySkinSoftenEffectEff@plt>:
  52ada0:      	adrp	x16, 0x54b000
  52ada4:      	ldr	x17, [x16, #0xd38]
  52ada8:      	add	x16, x16, #0xd38
  52adac:      	br	x17

000000000052adb0 <_ZN12MTImageKitNS20CMTIKSkinSoftenModelC1Ev@plt>:
  52adb0:      	adrp	x16, 0x54b000
  52adb4:      	ldr	x17, [x16, #0xd40]
  52adb8:      	add	x16, x16, #0xd40
  52adbc:      	br	x17

000000000052adc0 <_ZN12MTImageKitNS22CMTIKAIGCEffectRequest15setRequestParamENSt6__ndk16vectorINS1_10shared_ptrINS_5ImageEEENS1_9allocatorIS5_EEEERKNS_17CMTIKAIGCSDKParamEx@plt>:
  52adc0:      	adrp	x16, 0x54b000
  52adc4:      	ldr	x17, [x16, #0xd48]
  52adc8:      	add	x16, x16, #0xd48
  52adcc:      	br	x17

000000000052add0 <_ZN12MTImageKitNS17CMTIKAIGCSDKParamD1Ev@plt>:
  52add0:      	adrp	x16, 0x54b000
  52add4:      	ldr	x17, [x16, #0xd50]
  52add8:      	add	x16, x16, #0xd50
  52addc:      	br	x17

000000000052ade0 <_ZN12MTImageKitNS21CMTIKAIGCEffectResult14AigcResultInfo7getImgsEv@plt>:
  52ade0:      	adrp	x16, 0x54b000
  52ade4:      	ldr	x17, [x16, #0xd58]
  52ade8:      	add	x16, x16, #0xd58
  52adec:      	br	x17

000000000052adf0 <_ZN12MTImageKitNS21CMTIKAIGCEffectResult14AigcResultInfo13getParametersEv@plt>:
  52adf0:      	adrp	x16, 0x54b000
  52adf4:      	ldr	x17, [x16, #0xd60]
  52adf8:      	add	x16, x16, #0xd60
  52adfc:      	br	x17

000000000052ae00 <_ZN12MTImageKitNS5Image13convertToGreyEv@plt>:
  52ae00:      	adrp	x16, 0x54b000
  52ae04:      	ldr	x17, [x16, #0xd68]
  52ae08:      	add	x16, x16, #0xd68
  52ae0c:      	br	x17

000000000052ae10 <cJSON_GetObjectItem@plt>:
  52ae10:      	adrp	x16, 0x54b000
  52ae14:      	ldr	x17, [x16, #0xd70]
  52ae18:      	add	x16, x16, #0xd70
  52ae1c:      	br	x17

000000000052ae20 <cJSON_IsArray@plt>:
  52ae20:      	adrp	x16, 0x54b000
  52ae24:      	ldr	x17, [x16, #0xd78]
  52ae28:      	add	x16, x16, #0xd78
  52ae2c:      	br	x17

000000000052ae30 <cJSON_GetArraySize@plt>:
  52ae30:      	adrp	x16, 0x54b000
  52ae34:      	ldr	x17, [x16, #0xd80]
  52ae38:      	add	x16, x16, #0xd80
  52ae3c:      	br	x17

000000000052ae40 <cJSON_GetArrayItem@plt>:
  52ae40:      	adrp	x16, 0x54b000
  52ae44:      	ldr	x17, [x16, #0xd88]
  52ae48:      	add	x16, x16, #0xd88
  52ae4c:      	br	x17

000000000052ae50 <_ZN12MTImageKitNS5Image13convertToRGBAEb@plt>:
  52ae50:      	adrp	x16, 0x54b000
  52ae54:      	ldr	x17, [x16, #0xd90]
  52ae58:      	add	x16, x16, #0xd90
  52ae5c:      	br	x17

000000000052ae60 <_ZN12MTImageKitNS12CMTIKManager25getResultImageFramebufferEv@plt>:
  52ae60:      	adrp	x16, 0x54b000
  52ae64:      	ldr	x17, [x16, #0xd98]
  52ae68:      	add	x16, x16, #0xd98
  52ae6c:      	br	x17

000000000052ae70 <_ZN12MTImageKitNS11Framebuffer20imageFromTexContentsEPNS_5ImageENSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
  52ae70:      	adrp	x16, 0x54b000
  52ae74:      	ldr	x17, [x16, #0xda0]
  52ae78:      	add	x16, x16, #0xda0
  52ae7c:      	br	x17

000000000052ae80 <_ZN12MTImageKitNS11FramebufferD1Ev@plt>:
  52ae80:      	adrp	x16, 0x54b000
  52ae84:      	ldr	x17, [x16, #0xda8]
  52ae88:      	add	x16, x16, #0xda8
  52ae8c:      	br	x17

000000000052ae90 <_ZN12MTImageKitNS23CMTIKAIGCNetRequestBaseC2ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52ae90:      	adrp	x16, 0x54b000
  52ae94:      	ldr	x17, [x16, #0xdb0]
  52ae98:      	add	x16, x16, #0xdb0
  52ae9c:      	br	x17

000000000052aea0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilterC1Ev@plt>:
  52aea0:      	adrp	x16, 0x54b000
  52aea4:      	ldr	x17, [x16, #0xdb8]
  52aea8:      	add	x16, x16, #0xdb8
  52aeac:      	br	x17

000000000052aeb0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter17setFormulaVersionENS_27CMTIKSlimFaceFormulaVersionE@plt>:
  52aeb0:      	adrp	x16, 0x54b000
  52aeb4:      	ldr	x17, [x16, #0xdc0]
  52aeb8:      	add	x16, x16, #0xdc0
  52aebc:      	br	x17

000000000052aec0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter12initFaceDataEv@plt>:
  52aec0:      	adrp	x16, 0x54b000
  52aec4:      	ldr	x17, [x16, #0xdc8]
  52aec8:      	add	x16, x16, #0xdc8
  52aecc:      	br	x17

000000000052aed0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter16getValidFaceDataEv@plt>:
  52aed0:      	adrp	x16, 0x54b000
  52aed4:      	ldr	x17, [x16, #0xdd0]
  52aed8:      	add	x16, x16, #0xdd0
  52aedc:      	br	x17

000000000052aee0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter7setModeENS_13OperationTypeE@plt>:
  52aee0:      	adrp	x16, 0x54b000
  52aee4:      	ldr	x17, [x16, #0xdd8]
  52aee8:      	add	x16, x16, #0xdd8
  52aeec:      	br	x17

000000000052aef0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter9setFaceIDEi@plt>:
  52aef0:      	adrp	x16, 0x54b000
  52aef4:      	ldr	x17, [x16, #0xde0]
  52aef8:      	add	x16, x16, #0xde0
  52aefc:      	br	x17

000000000052af00 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter13setAutoEffectENS_19CMTIKSlimShapeParamE@plt>:
  52af00:      	adrp	x16, 0x54b000
  52af04:      	ldr	x17, [x16, #0xde8]
  52af08:      	add	x16, x16, #0xde8
  52af0c:      	br	x17

000000000052af10 <_ZN12MTImageKitNS20CMTIKSlimFilterModelC1Ev@plt>:
  52af10:      	adrp	x16, 0x54b000
  52af14:      	ldr	x17, [x16, #0xdf0]
  52af18:      	add	x16, x16, #0xdf0
  52af1c:      	br	x17

000000000052af20 <_ZN12MTImageKitNS15CMTIKFaceResultC1Ev@plt>:
  52af20:      	adrp	x16, 0x54b000
  52af24:      	ldr	x17, [x16, #0xdf8]
  52af28:      	add	x16, x16, #0xdf8
  52af2c:      	br	x17

000000000052af30 <_ZN12MTImageKitNS26CMTIKWrinkleCleanNewFilterC1Ev@plt>:
  52af30:      	adrp	x16, 0x54b000
  52af34:      	ldr	x17, [x16, #0xe00]
  52af38:      	add	x16, x16, #0xe00
  52af3c:      	br	x17

000000000052af40 <_ZN12MTImageKitNS22CMTIKWrinkleCleanModelC1Ev@plt>:
  52af40:      	adrp	x16, 0x54b000
  52af44:      	ldr	x17, [x16, #0xe08]
  52af48:      	add	x16, x16, #0xe08
  52af4c:      	br	x17

000000000052af50 <_ZN12MTImageKitNS11Framebuffer23getImageFromTexContentsEPNS_5ImageE@plt>:
  52af50:      	adrp	x16, 0x54b000
  52af54:      	ldr	x17, [x16, #0xe10]
  52af58:      	add	x16, x16, #0xe10
  52af5c:      	br	x17

000000000052af60 <_ZN12MTImageKitNS11CMTIKFilter21setABExperimentEnableENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEb@plt>:
  52af60:      	adrp	x16, 0x54b000
  52af64:      	ldr	x17, [x16, #0xe18]
  52af68:      	add	x16, x16, #0xe18
  52af6c:      	br	x17

000000000052af70 <_ZN12MTImageKitNS21CMTIKBgBeautifyFilterC1Ev@plt>:
  52af70:      	adrp	x16, 0x54b000
  52af74:      	ldr	x17, [x16, #0xe20]
  52af78:      	add	x16, x16, #0xe20
  52af7c:      	br	x17

000000000052af80 <_ZN12MTImageKitNS27CMTIKStaticImageInfoExtract28ImageProcessWithExtractColorEPhiiiRNSt6__ndk16vectorIiNS2_9allocatorIiEEEEiiiiiibbb@plt>:
  52af80:      	adrp	x16, 0x54b000
  52af84:      	ldr	x17, [x16, #0xe28]
  52af88:      	add	x16, x16, #0xe28
  52af8c:      	br	x17

000000000052af90 <_ZN12MTImageKitNS21CMTIKBgBeautifyFilter18setDisplayViewSizeEii@plt>:
  52af90:      	adrp	x16, 0x54b000
  52af94:      	ldr	x17, [x16, #0xe30]
  52af98:      	add	x16, x16, #0xe30
  52af9c:      	br	x17

000000000052afa0 <_ZN12MTImageKitNS21CMTIKBgBeautifyFilter17setBgBeautifyInfoERKNS_21CMTIKBGBeautifyInfo_TE@plt>:
  52afa0:      	adrp	x16, 0x54b000
  52afa4:      	ldr	x17, [x16, #0xe38]
  52afa8:      	add	x16, x16, #0xe38
  52afac:      	br	x17

000000000052afb0 <_ZN12MTImageKitNS21CMTIKBgBeautifyFilter22setFormulaLocateStatusENS_19StickerLocateStatusE@plt>:
  52afb0:      	adrp	x16, 0x54b000
  52afb4:      	ldr	x17, [x16, #0xe40]
  52afb8:      	add	x16, x16, #0xe40
  52afbc:      	br	x17

000000000052afc0 <_ZN12MTImageKitNS19CMTIKVLAIBodyDetect11ImageDetectENSt6__ndk110shared_ptrINS_5ImageEEEbibbbbb@plt>:
  52afc0:      	adrp	x16, 0x54b000
  52afc4:      	ldr	x17, [x16, #0xe48]
  52afc8:      	add	x16, x16, #0xe48
  52afcc:      	br	x17

000000000052afd0 <_ZN12MTImageKitNS7Context16isCurrentContextEv@plt>:
  52afd0:      	adrp	x16, 0x54b000
  52afd4:      	ldr	x17, [x16, #0xe50]
  52afd8:      	add	x16, x16, #0xe50
  52afdc:      	br	x17

000000000052afe0 <_ZN12MTImageKitNS7Context19useAsCurrentContextEv@plt>:
  52afe0:      	adrp	x16, 0x54b000
  52afe4:      	ldr	x17, [x16, #0xe58]
  52afe8:      	add	x16, x16, #0xe58
  52afec:      	br	x17

000000000052aff0 <_ZN12MTImageKitNS5Image6resizeENS_5_Vec2IiEE@plt>:
  52aff0:      	adrp	x16, 0x54b000
  52aff4:      	ldr	x17, [x16, #0xe60]
  52aff8:      	add	x16, x16, #0xe60
  52affc:      	br	x17

000000000052b000 <_ZN12MTImageKitNS22CMTIKVLAISegmentDetect11ImageDetectENSt6__ndk110shared_ptrINS_5ImageEEENS_12CMTIKSegmentENS_5_Vec2IiEEiPb@plt>:
  52b000:      	adrp	x16, 0x54b000
  52b004:      	ldr	x17, [x16, #0xe68]
  52b008:      	add	x16, x16, #0xe68
  52b00c:      	br	x17

000000000052b010 <_ZN12MTImageKitNS20CMTIKBgVirtualFilterC1Ev@plt>:
  52b010:      	adrp	x16, 0x54b000
  52b014:      	ldr	x17, [x16, #0xe70]
  52b018:      	add	x16, x16, #0xe70
  52b01c:      	br	x17

000000000052b020 <_ZN12MTImageKitNS20CMTIKBgVirtualFilter16setOldEffectPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  52b020:      	adrp	x16, 0x54b000
  52b024:      	ldr	x17, [x16, #0xe78]
  52b028:      	add	x16, x16, #0xe78
  52b02c:      	br	x17

000000000052b030 <_ZN12MTImageKitNS20CMTIKBgVirtualFilter15setARConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b030:      	adrp	x16, 0x54b000
  52b034:      	ldr	x17, [x16, #0xe80]
  52b038:      	add	x16, x16, #0xe80
  52b03c:      	br	x17

000000000052b040 <_ZN12MTImageKitNS20CMTIKBgVirtualFilter19setBodySegmentImageEPhii@plt>:
  52b040:      	adrp	x16, 0x54b000
  52b044:      	ldr	x17, [x16, #0xe88]
  52b048:      	add	x16, x16, #0xe88
  52b04c:      	br	x17

000000000052b050 <_ZN12MTImageKitNS20CMTIKBgVirtualFilter12setMaskImageEPhii@plt>:
  52b050:      	adrp	x16, 0x54b000
  52b054:      	ldr	x17, [x16, #0xe90]
  52b058:      	add	x16, x16, #0xe90
  52b05c:      	br	x17

000000000052b060 <_ZN12MTImageKitNS20CMTIKBgVirtualFilter9setParamsEPNS_22CMTIKBgVirtualParams_TE@plt>:
  52b060:      	adrp	x16, 0x54b000
  52b064:      	ldr	x17, [x16, #0xe98]
  52b068:      	add	x16, x16, #0xe98
  52b06c:      	br	x17

000000000052b070 <_ZN12MTImageKitNS5ImageC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEibb@plt>:
  52b070:      	adrp	x16, 0x54b000
  52b074:      	ldr	x17, [x16, #0xea0]
  52b078:      	add	x16, x16, #0xea0
  52b07c:      	br	x17

000000000052b080 <_ZNK12MTImageKitNS20CMTIKBodyShapeFilter21getAigcThinBellyCacheEv@plt>:
  52b080:      	adrp	x16, 0x54b000
  52b084:      	ldr	x17, [x16, #0xea8]
  52b088:      	add	x16, x16, #0xea8
  52b08c:      	br	x17

000000000052b090 <_ZN12MTImageKitNS20CMTIKBodyShapeFilterC1Ev@plt>:
  52b090:      	adrp	x16, 0x54b000
  52b094:      	ldr	x17, [x16, #0xeb0]
  52b098:      	add	x16, x16, #0xeb0
  52b09c:      	br	x17

000000000052b0a0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter15getBodyInOneExpEv@plt>:
  52b0a0:      	adrp	x16, 0x54b000
  52b0a4:      	ldr	x17, [x16, #0xeb8]
  52b0a8:      	add	x16, x16, #0xeb8
  52b0ac:      	br	x17

000000000052b0b0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter15setBodyInOneExpEb@plt>:
  52b0b0:      	adrp	x16, 0x54b000
  52b0b4:      	ldr	x17, [x16, #0xec0]
  52b0b8:      	add	x16, x16, #0xec0
  52b0bc:      	br	x17

000000000052b0c0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter12setCachePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b0c0:      	adrp	x16, 0x54b000
  52b0c4:      	ldr	x17, [x16, #0xec8]
  52b0c8:      	add	x16, x16, #0xec8
  52b0cc:      	br	x17

000000000052b0d0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter16setLiquifyEffectEb@plt>:
  52b0d0:      	adrp	x16, 0x54b000
  52b0d4:      	ldr	x17, [x16, #0xed0]
  52b0d8:      	add	x16, x16, #0xed0
  52b0dc:      	br	x17

000000000052b0e0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter19bodyShapeDataDetectEv@plt>:
  52b0e0:      	adrp	x16, 0x54b000
  52b0e4:      	ldr	x17, [x16, #0xed8]
  52b0e8:      	add	x16, x16, #0xed8
  52b0ec:      	br	x17

000000000052b0f0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter22setBodyShapeManualTypeENS_26CMTIKBodyShapeManualType_TE@plt>:
  52b0f0:      	adrp	x16, 0x54b000
  52b0f4:      	ldr	x17, [x16, #0xee0]
  52b0f8:      	add	x16, x16, #0xee0
  52b0fc:      	br	x17

000000000052b100 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter15setProtectAlphaEf@plt>:
  52b100:      	adrp	x16, 0x54b000
  52b104:      	ldr	x17, [x16, #0xee8]
  52b108:      	add	x16, x16, #0xee8
  52b10c:      	br	x17

000000000052b110 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter15getFaceIDStatusEv@plt>:
  52b110:      	adrp	x16, 0x54b000
  52b114:      	ldr	x17, [x16, #0xef0]
  52b118:      	add	x16, x16, #0xef0
  52b11c:      	br	x17

000000000052b120 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter9setFaceIDEi@plt>:
  52b120:      	adrp	x16, 0x54b000
  52b124:      	ldr	x17, [x16, #0xef8]
  52b128:      	add	x16, x16, #0xef8
  52b12c:      	br	x17

000000000052b130 <_ZNK12MTImageKitNS20CMTIKBodyShapeFilter22getOneKeyBodyAigcCacheEv@plt>:
  52b130:      	adrp	x16, 0x54b000
  52b134:      	ldr	x17, [x16, #0xf00]
  52b138:      	add	x16, x16, #0xf00
  52b13c:      	br	x17

000000000052b140 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter20setCommonEffectAlphaEf@plt>:
  52b140:      	adrp	x16, 0x54b000
  52b144:      	ldr	x17, [x16, #0xf08]
  52b148:      	add	x16, x16, #0xf08
  52b14c:      	br	x17

000000000052b150 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter20applyBodyShapeEffectENS_18CMTIKBodyShapeTypeEfNS_15CMTIKBodyLRTypeE@plt>:
  52b150:      	adrp	x16, 0x54b000
  52b154:      	ldr	x17, [x16, #0xf10]
  52b158:      	add	x16, x16, #0xf10
  52b15c:      	br	x17

000000000052b160 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter26getDefaultBodyHeightenAreaEv@plt>:
  52b160:      	adrp	x16, 0x54b000
  52b164:      	ldr	x17, [x16, #0xf18]
  52b168:      	add	x16, x16, #0xf18
  52b16c:      	br	x17

000000000052b170 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter21applyBodyHeightenAreaENS_21CMTIKBodyHeightenAreaE@plt>:
  52b170:      	adrp	x16, 0x54b000
  52b174:      	ldr	x17, [x16, #0xf20]
  52b178:      	add	x16, x16, #0xf20
  52b17c:      	br	x17

000000000052b180 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter21enableBackGroudRepairEb@plt>:
  52b180:      	adrp	x16, 0x54b000
  52b184:      	ldr	x17, [x16, #0xf28]
  52b188:      	add	x16, x16, #0xf28
  52b18c:      	br	x17

000000000052b190 <_ZN12MTImageKitNS12CMTIKManager23setDoubleBufferReRenderEb@plt>:
  52b190:      	adrp	x16, 0x54b000
  52b194:      	ldr	x17, [x16, #0xf30]
  52b198:      	add	x16, x16, #0xf30
  52b19c:      	br	x17

000000000052b1a0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter21setAigcThinBellyCacheENSt6__ndk110shared_ptrINS_15CMTIKCacheImageEEElfi@plt>:
  52b1a0:      	adrp	x16, 0x54b000
  52b1a4:      	ldr	x17, [x16, #0xf38]
  52b1a8:      	add	x16, x16, #0xf38
  52b1ac:      	br	x17

000000000052b1b0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter22setOneKeyBodyAigcCacheENSt6__ndk110shared_ptrINS_15CMTIKCacheImageEEElfi@plt>:
  52b1b0:      	adrp	x16, 0x54b000
  52b1b4:      	ldr	x17, [x16, #0xf40]
  52b1b8:      	add	x16, x16, #0xf40
  52b1bc:      	br	x17

000000000052b1c0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter20resetInterruptStatueEv@plt>:
  52b1c0:      	adrp	x16, 0x54b000
  52b1c4:      	ldr	x17, [x16, #0xf48]
  52b1c8:      	add	x16, x16, #0xf48
  52b1cc:      	br	x17

000000000052b1d0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter18applyCommonRequestEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEElfb@plt>:
  52b1d0:      	adrp	x16, 0x54b000
  52b1d4:      	ldr	x17, [x16, #0xf50]
  52b1d8:      	add	x16, x16, #0xf50
  52b1dc:      	br	x17

000000000052b1e0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter35applyCommonRequestBackgroundRequestEf@plt>:
  52b1e0:      	adrp	x16, 0x54b000
  52b1e4:      	ldr	x17, [x16, #0xf58]
  52b1e8:      	add	x16, x16, #0xf58
  52b1ec:      	br	x17

000000000052b1f0 <_ZN12MTImageKitNS19CMTIKBodyShapeModelC1Ev@plt>:
  52b1f0:      	adrp	x16, 0x54b000
  52b1f4:      	ldr	x17, [x16, #0xf60]
  52b1f8:      	add	x16, x16, #0xf60
  52b1fc:      	br	x17

000000000052b200 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter17getBGRequestParamEPNS_11FramebufferE@plt>:
  52b200:      	adrp	x16, 0x54b000
  52b204:      	ldr	x17, [x16, #0xf68]
  52b208:      	add	x16, x16, #0xf68
  52b20c:      	br	x17

000000000052b210 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter17backgroundRequestENS_21CMTIKBodyRequestParamE@plt>:
  52b210:      	adrp	x16, 0x54b000
  52b214:      	ldr	x17, [x16, #0xf70]
  52b218:      	add	x16, x16, #0xf70
  52b21c:      	br	x17

000000000052b220 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter17backgroundPrepareENSt6__ndk110shared_ptrINS_5ImageEEENS1_6vectorIS4_NS1_9allocatorIS4_EEEE@plt>:
  52b220:      	adrp	x16, 0x54b000
  52b224:      	ldr	x17, [x16, #0xf78]
  52b228:      	add	x16, x16, #0xf78
  52b22c:      	br	x17

000000000052b230 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter24setStraightLegsAigcCacheENSt6__ndk110shared_ptrINS_34CMTIKStraightLegsAIGCRequestResultEEE@plt>:
  52b230:      	adrp	x16, 0x54b000
  52b234:      	ldr	x17, [x16, #0xf80]
  52b238:      	add	x16, x16, #0xf80
  52b23c:      	br	x17

000000000052b240 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter23hasAIStraightLegsEffectEi@plt>:
  52b240:      	adrp	x16, 0x54b000
  52b244:      	ldr	x17, [x16, #0xf88]
  52b248:      	add	x16, x16, #0xf88
  52b24c:      	br	x17

000000000052b250 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter23setAIStraightLegsEffectEi@plt>:
  52b250:      	adrp	x16, 0x54b000
  52b254:      	ldr	x17, [x16, #0xf90]
  52b258:      	add	x16, x16, #0xf90
  52b25c:      	br	x17

000000000052b260 <_ZN12MTImageKitNS6FileIO13CheckDirExistEPKc@plt>:
  52b260:      	adrp	x16, 0x54b000
  52b264:      	ldr	x17, [x16, #0xf98]
  52b268:      	add	x16, x16, #0xf98
  52b26c:      	br	x17

000000000052b270 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter26applyAIStraightLegsRequestENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b270:      	adrp	x16, 0x54b000
  52b274:      	ldr	x17, [x16, #0xfa0]
  52b278:      	add	x16, x16, #0xfa0
  52b27c:      	br	x17

000000000052b280 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter24getStraightLegsAigcCacheEv@plt>:
  52b280:      	adrp	x16, 0x54b000
  52b284:      	ldr	x17, [x16, #0xfa8]
  52b288:      	add	x16, x16, #0xfa8
  52b28c:      	br	x17

000000000052b290 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter20hasPrepareEffectDataENS_18CMTIKBodyShapeTypeE@plt>:
  52b290:      	adrp	x16, 0x54b000
  52b294:      	ldr	x17, [x16, #0xfb0]
  52b298:      	add	x16, x16, #0xfb0
  52b29c:      	br	x17

000000000052b2a0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter24setBody3DEffectAigcCacheENS_18CMTIKBodyShapeTypeENSt6__ndk110shared_ptrINS_30CMTIKBody3DEffectRequestResultEEE@plt>:
  52b2a0:      	adrp	x16, 0x54b000
  52b2a4:      	ldr	x17, [x16, #0xfb8]
  52b2a8:      	add	x16, x16, #0xfb8
  52b2ac:      	br	x17

000000000052b2b0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter19prepare3DEffectDataENSt6__ndk16vectorINS_18CMTIKBodyShapeTypeENS1_9allocatorIS3_EEEEPNS_11FramebufferENS1_12basic_stringIcNS1_11char_traitsIcEENS4_IcEEEESD_@plt>:
  52b2b0:      	adrp	x16, 0x54b000
  52b2b4:      	ldr	x17, [x16, #0xfc0]
  52b2b8:      	add	x16, x16, #0xfc0
  52b2bc:      	br	x17

000000000052b2c0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  52b2c0:      	adrp	x16, 0x54b000
  52b2c4:      	ldr	x17, [x16, #0xfc8]
  52b2c8:      	add	x16, x16, #0xfc8
  52b2cc:      	br	x17

000000000052b2d0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter24getBody3DEffectAigcCacheENS_18CMTIKBodyShapeTypeE@plt>:
  52b2d0:      	adrp	x16, 0x54b000
  52b2d4:      	ldr	x17, [x16, #0xfd0]
  52b2d8:      	add	x16, x16, #0xfd0
  52b2dc:      	br	x17

000000000052b2e0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter20applyBodyShapeEffectENS_18CMTIKBodyShapeTypeEfi@plt>:
  52b2e0:      	adrp	x16, 0x54b000
  52b2e4:      	ldr	x17, [x16, #0xfd8]
  52b2e8:      	add	x16, x16, #0xfd8
  52b2ec:      	br	x17

000000000052b2f0 <cJSON_Parse@plt>:
  52b2f0:      	adrp	x16, 0x54b000
  52b2f4:      	ldr	x17, [x16, #0xfe0]
  52b2f8:      	add	x16, x16, #0xfe0
  52b2fc:      	br	x17

000000000052b300 <cJSON_IsObject@plt>:
  52b300:      	adrp	x16, 0x54b000
  52b304:      	ldr	x17, [x16, #0xfe8]
  52b308:      	add	x16, x16, #0xfe8
  52b30c:      	br	x17

000000000052b310 <cJSON_Delete@plt>:
  52b310:      	adrp	x16, 0x54b000
  52b314:      	ldr	x17, [x16, #0xff0]
  52b318:      	add	x16, x16, #0xff0
  52b31c:      	br	x17

000000000052b320 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter19applyAutoBodyEffectERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEfi@plt>:
  52b320:      	adrp	x16, 0x54b000
  52b324:      	ldr	x17, [x16, #0xff8]
  52b328:      	add	x16, x16, #0xff8
  52b32c:      	br	x17

000000000052b330 <_ZN12MTImageKitNS5Image7isValidEv@plt>:
  52b330:      	adrp	x16, 0x54c000
  52b334:      	ldr	x17, [x16]
  52b338:      	add	x16, x16, #0x0
  52b33c:      	br	x17

000000000052b340 <_ZN12MTImageKitNS15CMTIKCacheImageC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b340:      	adrp	x16, 0x54c000
  52b344:      	ldr	x17, [x16, #0x8]
  52b348:      	add	x16, x16, #0x8
  52b34c:      	br	x17

000000000052b350 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
  52b350:      	adrp	x16, 0x54c000
  52b354:      	ldr	x17, [x16, #0x10]
  52b358:      	add	x16, x16, #0x10
  52b35c:      	br	x17

000000000052b360 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
  52b360:      	adrp	x16, 0x54c000
  52b364:      	ldr	x17, [x16, #0x18]
  52b368:      	add	x16, x16, #0x18
  52b36c:      	br	x17

000000000052b370 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
  52b370:      	adrp	x16, 0x54c000
  52b374:      	ldr	x17, [x16, #0x20]
  52b378:      	add	x16, x16, #0x20
  52b37c:      	br	x17

000000000052b380 <_ZNSt6__ndk19to_stringEf@plt>:
  52b380:      	adrp	x16, 0x54c000
  52b384:      	ldr	x17, [x16, #0x28]
  52b388:      	add	x16, x16, #0x28
  52b38c:      	br	x17

000000000052b390 <_ZN12MTImageKitNS22CMTIKAIGCEffectRequest15setRequestParamERNSt6__ndk16vectorINS_21CMTIKAIGCEfffectParam9MediaInfoENS1_9allocatorIS4_EEEERKNS_17CMTIKAIGCSDKParamEx@plt>:
  52b390:      	adrp	x16, 0x54c000
  52b394:      	ldr	x17, [x16, #0x30]
  52b398:      	add	x16, x16, #0x30
  52b39c:      	br	x17

000000000052b3a0 <_ZN12MTImageKitNS18CMTIKEnhanceFilterC1Ev@plt>:
  52b3a0:      	adrp	x16, 0x54c000
  52b3a4:      	ldr	x17, [x16, #0x38]
  52b3a8:      	add	x16, x16, #0x38
  52b3ac:      	br	x17

000000000052b3b0 <_ZN12MTImageKitNS18CMTIKEnhanceFilter16materialPathInitEv@plt>:
  52b3b0:      	adrp	x16, 0x54c000
  52b3b4:      	ldr	x17, [x16, #0x40]
  52b3b8:      	add	x16, x16, #0x40
  52b3bc:      	br	x17

000000000052b3c0 <_ZN12MTImageKitNS18CMTIKEnhanceFilter9setParamsEPNS_20CMTIKEnhanceParams_TE@plt>:
  52b3c0:      	adrp	x16, 0x54c000
  52b3c4:      	ldr	x17, [x16, #0x48]
  52b3c8:      	add	x16, x16, #0x48
  52b3cc:      	br	x17

000000000052b3d0 <_ZN12MTImageKitNS18CMTIKStickerFilter11setFullRectENS_5_Vec4IfEE@plt>:
  52b3d0:      	adrp	x16, 0x54c000
  52b3d4:      	ldr	x17, [x16, #0x50]
  52b3d8:      	add	x16, x16, #0x50
  52b3dc:      	br	x17

000000000052b3e0 <_ZNK12MTImageKitNS5Image15imageDataLengthEv@plt>:
  52b3e0:      	adrp	x16, 0x54c000
  52b3e4:      	ldr	x17, [x16, #0x58]
  52b3e8:      	add	x16, x16, #0x58
  52b3ec:      	br	x17

000000000052b3f0 <_ZN12MTImageKitNS18CMTIKStickerFilter10setStickerEPhiiS1_iib@plt>:
  52b3f0:      	adrp	x16, 0x54c000
  52b3f4:      	ldr	x17, [x16, #0x60]
  52b3f8:      	add	x16, x16, #0x60
  52b3fc:      	br	x17

000000000052b400 <_ZN12MTImageKitNS18CMTIKStickerFilter12setShapeMaskENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEb@plt>:
  52b400:      	adrp	x16, 0x54c000
  52b404:      	ldr	x17, [x16, #0x68]
  52b408:      	add	x16, x16, #0x68
  52b40c:      	br	x17

000000000052b410 <_ZN12MTImageKitNS18CMTIKStickerFilter19setStickerBlendModeENS_23CMTIKStickerBlendMode_TE@plt>:
  52b410:      	adrp	x16, 0x54c000
  52b414:      	ldr	x17, [x16, #0x70]
  52b418:      	add	x16, x16, #0x70
  52b41c:      	br	x17

000000000052b420 <_ZN12NativeBitmapD1Ev@plt>:
  52b420:      	adrp	x16, 0x54c000
  52b424:      	ldr	x17, [x16, #0x78]
  52b428:      	add	x16, x16, #0x78
  52b42c:      	br	x17

000000000052b430 <_ZN12MTImageKitNS19CMTIKRealtimeFilterC1Ev@plt>:
  52b430:      	adrp	x16, 0x54c000
  52b434:      	ldr	x17, [x16, #0x80]
  52b438:      	add	x16, x16, #0x80
  52b43c:      	br	x17

000000000052b440 <_ZN12MTImageKitNS13CMTIKFaceDataD1Ev@plt>:
  52b440:      	adrp	x16, 0x54c000
  52b444:      	ldr	x17, [x16, #0x88]
  52b448:      	add	x16, x16, #0x88
  52b44c:      	br	x17

000000000052b450 <_ZN12MTImageKitNS19CMTIKRealtimeFilter20setFilterRandomIndexEi@plt>:
  52b450:      	adrp	x16, 0x54c000
  52b454:      	ldr	x17, [x16, #0x90]
  52b458:      	add	x16, x16, #0x90
  52b45c:      	br	x17

000000000052b460 <_ZN12MTImageKitNS19CMTIKRealtimeFilter16loadClientConfigENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b460:      	adrp	x16, 0x54c000
  52b464:      	ldr	x17, [x16, #0x98]
  52b468:      	add	x16, x16, #0x98
  52b46c:      	br	x17

000000000052b470 <_ZN12MTImageKitNS19CMTIKRealtimeFilter18set3DFaceModelPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b470:      	adrp	x16, 0x54c000
  52b474:      	ldr	x17, [x16, #0xa0]
  52b478:      	add	x16, x16, #0xa0
  52b47c:      	br	x17

000000000052b480 <_ZN12MTImageKitNS19CMTIKRealtimeFilter9setMakeupEb@plt>:
  52b480:      	adrp	x16, 0x54c000
  52b484:      	ldr	x17, [x16, #0xa8]
  52b488:      	add	x16, x16, #0xa8
  52b48c:      	br	x17

000000000052b490 <_ZN12MTImageKitNS11CMTIKFilter19setMaterialFeaturesEi@plt>:
  52b490:      	adrp	x16, 0x54c000
  52b494:      	ldr	x17, [x16, #0xb0]
  52b498:      	add	x16, x16, #0xb0
  52b49c:      	br	x17

000000000052b4a0 <_ZN12MTImageKitNS19CMTIKRealtimeFilter20updateMcpSliderParamEfi@plt>:
  52b4a0:      	adrp	x16, 0x54c000
  52b4a4:      	ldr	x17, [x16, #0xb8]
  52b4a8:      	add	x16, x16, #0xb8
  52b4ac:      	br	x17

000000000052b4b0 <_ZN12MTImageKitNS19CMTIKRealtimeFilter10setPlistIDENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b4b0:      	adrp	x16, 0x54c000
  52b4b4:      	ldr	x17, [x16, #0xc0]
  52b4b8:      	add	x16, x16, #0xc0
  52b4bc:      	br	x17

000000000052b4c0 <_ZN12MTImageKitNS19CMTIKRealtimeFilter17setAlphaSmearMaskERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b4c0:      	adrp	x16, 0x54c000
  52b4c4:      	ldr	x17, [x16, #0xc8]
  52b4c8:      	add	x16, x16, #0xc8
  52b4cc:      	br	x17

000000000052b4d0 <_ZN12MTImageKitNS19CMTIKRealtimeFilter19clearAlphaSmearMaskEv@plt>:
  52b4d0:      	adrp	x16, 0x54c000
  52b4d4:      	ldr	x17, [x16, #0xd0]
  52b4d8:      	add	x16, x16, #0xd0
  52b4dc:      	br	x17

000000000052b4e0 <_ZN12MTImageKitNS19CMTIKRealtimeFilter16setPreEffectPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b4e0:      	adrp	x16, 0x54c000
  52b4e4:      	ldr	x17, [x16, #0xd8]
  52b4e8:      	add	x16, x16, #0xd8
  52b4ec:      	br	x17

000000000052b4f0 <_ZN12MTImageKitNS18CMTIKStickerFilterC1Ev@plt>:
  52b4f0:      	adrp	x16, 0x54c000
  52b4f4:      	ldr	x17, [x16, #0xe0]
  52b4f8:      	add	x16, x16, #0xe0
  52b4fc:      	br	x17

000000000052b500 <_ZN12MTImageKitNS15CMTIKHairFilterC1Ev@plt>:
  52b500:      	adrp	x16, 0x54c000
  52b504:      	ldr	x17, [x16, #0xe8]
  52b508:      	add	x16, x16, #0xe8
  52b50c:      	br	x17

000000000052b510 <_ZN12MTImageKitNS15CMTIKHairFilter12initFaceDataEv@plt>:
  52b510:      	adrp	x16, 0x54c000
  52b514:      	ldr	x17, [x16, #0xf0]
  52b518:      	add	x16, x16, #0xf0
  52b51c:      	br	x17

000000000052b520 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo16setRepairingHairEf@plt>:
  52b520:      	adrp	x16, 0x54c000
  52b524:      	ldr	x17, [x16, #0xf8]
  52b528:      	add	x16, x16, #0xf8
  52b52c:      	br	x17

000000000052b530 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo20setCustomEffectParamEmf@plt>:
  52b530:      	adrp	x16, 0x54c000
  52b534:      	ldr	x17, [x16, #0x100]
  52b538:      	add	x16, x16, #0x100
  52b53c:      	br	x17

000000000052b540 <_ZN12MTImageKitNS22CMTIKHairVolumeManager24registerHairVolumeEffectERKNS_21CMTIKHairCustomEffectE@plt>:
  52b540:      	adrp	x16, 0x54c000
  52b544:      	ldr	x17, [x16, #0x108]
  52b548:      	add	x16, x16, #0x108
  52b54c:      	br	x17

000000000052b550 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo11setHairLineEf@plt>:
  52b550:      	adrp	x16, 0x54c000
  52b554:      	ldr	x17, [x16, #0x110]
  52b558:      	add	x16, x16, #0x110
  52b55c:      	br	x17

000000000052b560 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo13setFluffyHairEi@plt>:
  52b560:      	adrp	x16, 0x54c000
  52b564:      	ldr	x17, [x16, #0x118]
  52b568:      	add	x16, x16, #0x118
  52b56c:      	br	x17

000000000052b570 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo12setCalvariumEf@plt>:
  52b570:      	adrp	x16, 0x54c000
  52b574:      	ldr	x17, [x16, #0x120]
  52b578:      	add	x16, x16, #0x120
  52b57c:      	br	x17

000000000052b580 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo16setFluffyHairProEi@plt>:
  52b580:      	adrp	x16, 0x54c000
  52b584:      	ldr	x17, [x16, #0x128]
  52b588:      	add	x16, x16, #0x128
  52b58c:      	br	x17

000000000052b590 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo24setRepairHairMaterialDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b590:      	adrp	x16, 0x54c000
  52b594:      	ldr	x17, [x16, #0x130]
  52b598:      	add	x16, x16, #0x130
  52b59c:      	br	x17

000000000052b5a0 <_ZN12MTImageKitNS19CMTIKHairVolumeInfo24setFluffyHairMaterialDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b5a0:      	adrp	x16, 0x54c000
  52b5a4:      	ldr	x17, [x16, #0x138]
  52b5a8:      	add	x16, x16, #0x138
  52b5ac:      	br	x17

000000000052b5b0 <_ZN12MTImageKitNS15CMTIKHairFilter15setFunctionTypeENS_13CMTIKHairTypeE@plt>:
  52b5b0:      	adrp	x16, 0x54c000
  52b5b4:      	ldr	x17, [x16, #0x140]
  52b5b8:      	add	x16, x16, #0x140
  52b5bc:      	br	x17

000000000052b5c0 <_ZN12MTImageKitNS15CMTIKHairFilter21applyVolumeInfoEffectEiNS_19CMTIKHairVolumeInfoE@plt>:
  52b5c0:      	adrp	x16, 0x54c000
  52b5c4:      	ldr	x17, [x16, #0x148]
  52b5c8:      	add	x16, x16, #0x148
  52b5cc:      	br	x17

000000000052b5d0 <_ZN12MTImageKitNS19CMTIKHairVolumeInfoD1Ev@plt>:
  52b5d0:      	adrp	x16, 0x54c000
  52b5d4:      	ldr	x17, [x16, #0x150]
  52b5d8:      	add	x16, x16, #0x150
  52b5dc:      	br	x17

000000000052b5e0 <_ZN12MTImageKitNS15CMTIKHairFilter20applyCurlyHairEffectEiNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52b5e0:      	adrp	x16, 0x54c000
  52b5e4:      	ldr	x17, [x16, #0x158]
  52b5e8:      	add	x16, x16, #0x158
  52b5ec:      	br	x17

000000000052b5f0 <_ZN12MTImageKitNS15CMTIKHairFilter23applyStraightHairEffectEiiNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52b5f0:      	adrp	x16, 0x54c000
  52b5f4:      	ldr	x17, [x16, #0x160]
  52b5f8:      	add	x16, x16, #0x160
  52b5fc:      	br	x17

000000000052b600 <_ZN12MTImageKitNS15CMTIKHairFilter20applyShinyHairEffectEif@plt>:
  52b600:      	adrp	x16, 0x54c000
  52b604:      	ldr	x17, [x16, #0x168]
  52b608:      	add	x16, x16, #0x168
  52b60c:      	br	x17

000000000052b610 <_ZN12MTImageKitNS15CMTIKHairFilter21applySmoothHairEffectEif@plt>:
  52b610:      	adrp	x16, 0x54c000
  52b614:      	ldr	x17, [x16, #0x170]
  52b618:      	add	x16, x16, #0x170
  52b61c:      	br	x17

000000000052b620 <_ZN12MTImageKitNS15CMTIKHairFilter11getSrcImageEv@plt>:
  52b620:      	adrp	x16, 0x54c000
  52b624:      	ldr	x17, [x16, #0x178]
  52b628:      	add	x16, x16, #0x178
  52b62c:      	br	x17

000000000052b630 <_ZN12MTImageKitNS24CMTIKHairFlowAIGCRequest16requestWithImageENSt6__ndk110shared_ptrINS_5ImageEEENS2_INS_14CMTIKNetHeaderEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_8functionIFviiEEENSF_IFvS4_S4_S4_EEE@plt>:
  52b630:      	adrp	x16, 0x54c000
  52b634:      	ldr	x17, [x16, #0x180]
  52b638:      	add	x16, x16, #0x180
  52b63c:      	br	x17

000000000052b640 <_ZN12MTImageKitNS15CMTIKHairFilter15applyHairEffectEiNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52b640:      	adrp	x16, 0x54c000
  52b644:      	ldr	x17, [x16, #0x188]
  52b648:      	add	x16, x16, #0x188
  52b64c:      	br	x17

000000000052b650 <_ZN12MTImageKitNS15CMTIKHairFilter20applyHairStyleEffectEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEf@plt>:
  52b650:      	adrp	x16, 0x54c000
  52b654:      	ldr	x17, [x16, #0x190]
  52b658:      	add	x16, x16, #0x190
  52b65c:      	br	x17

000000000052b660 <free@plt>:
  52b660:      	adrp	x16, 0x54c000
  52b664:      	ldr	x17, [x16, #0x198]
  52b668:      	add	x16, x16, #0x198
  52b66c:      	br	x17

000000000052b670 <_ZN12MTImageKitNS15CMTIKHairFilter18hairColorAIRequestEiNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b670:      	adrp	x16, 0x54c000
  52b674:      	ldr	x17, [x16, #0x1a0]
  52b678:      	add	x16, x16, #0x1a0
  52b67c:      	br	x17

000000000052b680 <_ZN12MTImageKitNS15CMTIKHairFilter21setDyeHairRenderAlphaEf@plt>:
  52b680:      	adrp	x16, 0x54c000
  52b684:      	ldr	x17, [x16, #0x1a8]
  52b688:      	add	x16, x16, #0x1a8
  52b68c:      	br	x17

000000000052b690 <_ZN12MTImageKitNS15CMTIKHairFilter16setMaskCachePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b690:      	adrp	x16, 0x54c000
  52b694:      	ldr	x17, [x16, #0x1b0]
  52b698:      	add	x16, x16, #0x1b0
  52b69c:      	br	x17

000000000052b6a0 <_ZNSt6__ndk14stofERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPm@plt>:
  52b6a0:      	adrp	x16, 0x54c000
  52b6a4:      	ldr	x17, [x16, #0x1b8]
  52b6a8:      	add	x16, x16, #0x1b8
  52b6ac:      	br	x17

000000000052b6b0 <_ZN12MTImageKitNS15CMTIKHairFilter16setHairMaskImageENSt6__ndk110shared_ptrINS_5ImageEEEb@plt>:
  52b6b0:      	adrp	x16, 0x54c000
  52b6b4:      	ldr	x17, [x16, #0x1c0]
  52b6b8:      	add	x16, x16, #0x1c0
  52b6bc:      	br	x17

000000000052b6c0 <_ZN12MTImageKitNS15CMTIKHairFilter18setWhitenHairImageENSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52b6c0:      	adrp	x16, 0x54c000
  52b6c4:      	ldr	x17, [x16, #0x1c8]
  52b6c8:      	add	x16, x16, #0x1c8
  52b6cc:      	br	x17

000000000052b6d0 <_ZN12MTImageKitNS15CMTIKHairFilter22setDyeHairMaterialInfoENS_11DyeHairInfoEb@plt>:
  52b6d0:      	adrp	x16, 0x54c000
  52b6d4:      	ldr	x17, [x16, #0x1d0]
  52b6d8:      	add	x16, x16, #0x1d0
  52b6dc:      	br	x17

000000000052b6e0 <_ZN12MTImageKitNS19CMTIKHairVolumeInfoC1Ev@plt>:
  52b6e0:      	adrp	x16, 0x54c000
  52b6e4:      	ldr	x17, [x16, #0x1d8]
  52b6e8:      	add	x16, x16, #0x1d8
  52b6ec:      	br	x17

000000000052b6f0 <_ZN12MTImageKitNS25CMTIKWhiteHairAIGCRequestC1ENSt6__ndk110shared_ptrINS_5ImageEEExNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52b6f0:      	adrp	x16, 0x54c000
  52b6f4:      	ldr	x17, [x16, #0x1e0]
  52b6f8:      	add	x16, x16, #0x1e0
  52b6fc:      	br	x17

000000000052b700 <_ZN12MTImageKitNS20CMTIKSmoothSkinModelC1Ev@plt>:
  52b700:      	adrp	x16, 0x54c000
  52b704:      	ldr	x17, [x16, #0x1e8]
  52b708:      	add	x16, x16, #0x1e8
  52b70c:      	br	x17

000000000052b710 <_ZN12MTImageKitNS21CMTIKSmoothSkinFilterC1Ev@plt>:
  52b710:      	adrp	x16, 0x54c000
  52b714:      	ldr	x17, [x16, #0x1f0]
  52b718:      	add	x16, x16, #0x1f0
  52b71c:      	br	x17

000000000052b720 <_ZN12MTImageKitNS21CMTIKSmoothSkinFilter18initBeautyFaceDataEv@plt>:
  52b720:      	adrp	x16, 0x54c000
  52b724:      	ldr	x17, [x16, #0x1f8]
  52b728:      	add	x16, x16, #0x1f8
  52b72c:      	br	x17

000000000052b730 <_ZN12MTImageKitNS21CMTIKSmoothSkinFilter14setEffectParamENS_20CMTIKSmoothSkinModelE@plt>:
  52b730:      	adrp	x16, 0x54c000
  52b734:      	ldr	x17, [x16, #0x200]
  52b738:      	add	x16, x16, #0x200
  52b73c:      	br	x17

000000000052b740 <_ZN12MTImageKitNS20CMTIKSmoothSkinModelD1Ev@plt>:
  52b740:      	adrp	x16, 0x54c000
  52b744:      	ldr	x17, [x16, #0x208]
  52b748:      	add	x16, x16, #0x208
  52b74c:      	br	x17

000000000052b750 <_ZN12MTImageKitNS20CMTIKFilterDataModelD2Ev@plt>:
  52b750:      	adrp	x16, 0x54c000
  52b754:      	ldr	x17, [x16, #0x210]
  52b758:      	add	x16, x16, #0x210
  52b75c:      	br	x17

000000000052b760 <_ZN12MTImageKitNS15CMTIKEditFilterC1Ev@plt>:
  52b760:      	adrp	x16, 0x54c000
  52b764:      	ldr	x17, [x16, #0x218]
  52b768:      	add	x16, x16, #0x218
  52b76c:      	br	x17

000000000052b770 <_ZN12MTImageKitNS15CMTIKEditFilter9setParamsEPNS_17CMTIKEditParams_TE@plt>:
  52b770:      	adrp	x16, 0x54c000
  52b774:      	ldr	x17, [x16, #0x220]
  52b778:      	add	x16, x16, #0x220
  52b77c:      	br	x17

000000000052b780 <_ZN12MTImageKitNS19CMTIKRealtimeFilter16parseParamTablesERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERbi@plt>:
  52b780:      	adrp	x16, 0x54c000
  52b784:      	ldr	x17, [x16, #0x228]
  52b788:      	add	x16, x16, #0x228
  52b78c:      	br	x17

000000000052b790 <_ZN12MTImageKitNS18CMTIKEnhanceFilter17getPartParamsSizeEv@plt>:
  52b790:      	adrp	x16, 0x54c000
  52b794:      	ldr	x17, [x16, #0x230]
  52b798:      	add	x16, x16, #0x230
  52b79c:      	br	x17

000000000052b7a0 <_ZN12MTImageKitNS18CMTIKEnhanceFilter16deletePartParamsEi@plt>:
  52b7a0:      	adrp	x16, 0x54c000
  52b7a4:      	ldr	x17, [x16, #0x238]
  52b7a8:      	add	x16, x16, #0x238
  52b7ac:      	br	x17

000000000052b7b0 <_ZN12MTImageKitNS18CMTIKEnhanceFilter13setPartParamsEPNS_20CMTIKEnhanceParams_TEi@plt>:
  52b7b0:      	adrp	x16, 0x54c000
  52b7b4:      	ldr	x17, [x16, #0x240]
  52b7b8:      	add	x16, x16, #0x240
  52b7bc:      	br	x17

000000000052b7c0 <__cxa_get_exception_ptr@plt>:
  52b7c0:      	adrp	x16, 0x54c000
  52b7c4:      	ldr	x17, [x16, #0x248]
  52b7c8:      	add	x16, x16, #0x248
  52b7cc:      	br	x17

000000000052b7d0 <_ZNSt9exceptionD1Ev@plt>:
  52b7d0:      	adrp	x16, 0x54c000
  52b7d4:      	ldr	x17, [x16, #0x250]
  52b7d8:      	add	x16, x16, #0x250
  52b7dc:      	br	x17

000000000052b7e0 <_ZN12MTImageKitNS14CMTIKEyeFilter23setUseGLBrightEyeEffectEb@plt>:
  52b7e0:      	adrp	x16, 0x54c000
  52b7e4:      	ldr	x17, [x16, #0x258]
  52b7e8:      	add	x16, x16, #0x258
  52b7ec:      	br	x17

000000000052b7f0 <_ZN12MTImageKitNS14CMTIKEyeFilterC1Ev@plt>:
  52b7f0:      	adrp	x16, 0x54c000
  52b7f4:      	ldr	x17, [x16, #0x260]
  52b7f8:      	add	x16, x16, #0x260
  52b7fc:      	br	x17

000000000052b800 <_ZN12MTImageKitNS14CMTIKEyeFilter14initARFaceDataEv@plt>:
  52b800:      	adrp	x16, 0x54c000
  52b804:      	ldr	x17, [x16, #0x268]
  52b808:      	add	x16, x16, #0x268
  52b80c:      	br	x17

000000000052b810 <_ZN12MTImageKitNS14CMTIKEyeFilter24applyEyeCollectionEffectE18CEyeCollectionDatai@plt>:
  52b810:      	adrp	x16, 0x54c000
  52b814:      	ldr	x17, [x16, #0x270]
  52b818:      	add	x16, x16, #0x270
  52b81c:      	br	x17

000000000052b820 <_ZN12MTImageKitNS14CMTIKEyeFilter23setGazeCorrectAigcCacheEiNSt6__ndk110shared_ptrINS_20GazeCorrectCacheDataEEE@plt>:
  52b820:      	adrp	x16, 0x54c000
  52b824:      	ldr	x17, [x16, #0x278]
  52b828:      	add	x16, x16, #0x278
  52b82c:      	br	x17

000000000052b830 <_ZN12MTImageKitNS14CMTIKEyeFilter23setFaceReshapeAigcCacheEiNSt6__ndk110shared_ptrINS_13ImageCropInfoEEE@plt>:
  52b830:      	adrp	x16, 0x54c000
  52b834:      	ldr	x17, [x16, #0x280]
  52b838:      	add	x16, x16, #0x280
  52b83c:      	br	x17

000000000052b840 <_ZN12MTImageKitNS14CMTIKEyeFilter20setEyeEffectTypeInUIENS_13EyeEffectModeE@plt>:
  52b840:      	adrp	x16, 0x54c000
  52b844:      	ldr	x17, [x16, #0x288]
  52b848:      	add	x16, x16, #0x288
  52b84c:      	br	x17

000000000052b850 <_ZN12MTImageKitNS14CMTIKEyeFilter15setARConfigPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEl@plt>:
  52b850:      	adrp	x16, 0x54c000
  52b854:      	ldr	x17, [x16, #0x290]
  52b858:      	add	x16, x16, #0x290
  52b85c:      	br	x17

000000000052b860 <_ZN12MTImageKitNS14CMTIKEyeFilter16catchLightEffectE15CatchLightParami@plt>:
  52b860:      	adrp	x16, 0x54c000
  52b864:      	ldr	x17, [x16, #0x298]
  52b868:      	add	x16, x16, #0x298
  52b86c:      	br	x17

000000000052b870 <_ZN12MTImageKitNS14CMTIKEyeFilter20doDoubleEyelidEffectE18HighDofEyelidParam@plt>:
  52b870:      	adrp	x16, 0x54c000
  52b874:      	ldr	x17, [x16, #0x2a0]
  52b878:      	add	x16, x16, #0x2a0
  52b87c:      	br	x17

000000000052b880 <_ZN12MTImageKitNS14CMTIKEyeFilter17applyMakeupEffectENSt6__ndk110shared_ptrINS_12CMakeupParamEEEi@plt>:
  52b880:      	adrp	x16, 0x54c000
  52b884:      	ldr	x17, [x16, #0x2a8]
  52b888:      	add	x16, x16, #0x2a8
  52b88c:      	br	x17

000000000052b890 <_ZN12MTImageKitNS14CMTIKEyeFilter23getGazeCorrectAigcCacheEi@plt>:
  52b890:      	adrp	x16, 0x54c000
  52b894:      	ldr	x17, [x16, #0x2b0]
  52b898:      	add	x16, x16, #0x2b0
  52b89c:      	br	x17

000000000052b8a0 <_ZN12MTImageKitNS14CMTIKEyeFilter23getFaceReshapeAigcCacheEi@plt>:
  52b8a0:      	adrp	x16, 0x54c000
  52b8a4:      	ldr	x17, [x16, #0x2b8]
  52b8a8:      	add	x16, x16, #0x2b8
  52b8ac:      	br	x17

000000000052b8b0 <_ZN12MTImageKitNS15CMTIKFaceResult12getAllFaceIDEv@plt>:
  52b8b0:      	adrp	x16, 0x54c000
  52b8b4:      	ldr	x17, [x16, #0x2c0]
  52b8b8:      	add	x16, x16, #0x2c0
  52b8bc:      	br	x17

000000000052b8c0 <_ZN12MTImageKitNS18CMTIKFaceFullModelC1Ev@plt>:
  52b8c0:      	adrp	x16, 0x54c000
  52b8c4:      	ldr	x17, [x16, #0x2c8]
  52b8c8:      	add	x16, x16, #0x2c8
  52b8cc:      	br	x17

000000000052b8d0 <_ZN12MTImageKitNS16CMTIKCheekFilterC1Ev@plt>:
  52b8d0:      	adrp	x16, 0x54c000
  52b8d4:      	ldr	x17, [x16, #0x2d0]
  52b8d8:      	add	x16, x16, #0x2d0
  52b8dc:      	br	x17

000000000052b8e0 <_ZN12MTImageKitNS11CMTIKFilter17getLayersDurationEv@plt>:
  52b8e0:      	adrp	x16, 0x54c000
  52b8e4:      	ldr	x17, [x16, #0x2d8]
  52b8e8:      	add	x16, x16, #0x2d8
  52b8ec:      	br	x17

000000000052b8f0 <_ZN12MTImageKitNS21CMTIKFaceRemodelModelC1Ev@plt>:
  52b8f0:      	adrp	x16, 0x54c000
  52b8f4:      	ldr	x17, [x16, #0x2e0]
  52b8f8:      	add	x16, x16, #0x2e0
  52b8fc:      	br	x17

000000000052b900 <_ZN12MTImageKitNS9MTuneInfo15setEffectValuesEiRNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
  52b900:      	adrp	x16, 0x54c000
  52b904:      	ldr	x17, [x16, #0x2e8]
  52b908:      	add	x16, x16, #0x2e8
  52b90c:      	br	x17

000000000052b910 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter16getVisibleEyeNumERKNS_15CMTIKFaceResultEi@plt>:
  52b910:      	adrp	x16, 0x54c000
  52b914:      	ldr	x17, [x16, #0x2f0]
  52b918:      	add	x16, x16, #0x2f0
  52b91c:      	br	x17

000000000052b920 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilterC1Ev@plt>:
  52b920:      	adrp	x16, 0x54c000
  52b924:      	ldr	x17, [x16, #0x2f8]
  52b928:      	add	x16, x16, #0x2f8
  52b92c:      	br	x17

000000000052b930 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter12initFaceDataEb@plt>:
  52b930:      	adrp	x16, 0x54c000
  52b934:      	ldr	x17, [x16, #0x300]
  52b938:      	add	x16, x16, #0x300
  52b93c:      	br	x17

000000000052b940 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter17preProcessTextureEibPNS_11FramebufferES2_@plt>:
  52b940:      	adrp	x16, 0x54c000
  52b944:      	ldr	x17, [x16, #0x308]
  52b948:      	add	x16, x16, #0x308
  52b94c:      	br	x17

000000000052b950 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter13setCacaheDataENS_17CSmileCahceData_TE@plt>:
  52b950:      	adrp	x16, 0x54c000
  52b954:      	ldr	x17, [x16, #0x310]
  52b958:      	add	x16, x16, #0x310
  52b95c:      	br	x17

000000000052b960 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter16doAllSmileEffectEb@plt>:
  52b960:      	adrp	x16, 0x54c000
  52b964:      	ldr	x17, [x16, #0x318]
  52b968:      	add	x16, x16, #0x318
  52b96c:      	br	x17

000000000052b970 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter18getEffectErrorCodeEv@plt>:
  52b970:      	adrp	x16, 0x54c000
  52b974:      	ldr	x17, [x16, #0x320]
  52b978:      	add	x16, x16, #0x320
  52b97c:      	br	x17

000000000052b980 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter20resetInterruptStatueEb@plt>:
  52b980:      	adrp	x16, 0x54c000
  52b984:      	ldr	x17, [x16, #0x328]
  52b988:      	add	x16, x16, #0x328
  52b98c:      	br	x17

000000000052b990 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter18setAIGCCommonAlphaEf@plt>:
  52b990:      	adrp	x16, 0x54c000
  52b994:      	ldr	x17, [x16, #0x330]
  52b998:      	add	x16, x16, #0x330
  52b99c:      	br	x17

000000000052b9a0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter24getCurrentNoProcessValueERb@plt>:
  52b9a0:      	adrp	x16, 0x54c000
  52b9a4:      	ldr	x17, [x16, #0x338]
  52b9a8:      	add	x16, x16, #0x338
  52b9ac:      	br	x17

000000000052b9b0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter13hasSmileCacheENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiNS_17CMTIKOpenEyesModeEbb@plt>:
  52b9b0:      	adrp	x16, 0x54c000
  52b9b4:      	ldr	x17, [x16, #0x340]
  52b9b8:      	add	x16, x16, #0x340
  52b9bc:      	br	x17

000000000052b9c0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter14fixSmileEffectEv@plt>:
  52b9c0:      	adrp	x16, 0x54c000
  52b9c4:      	ldr	x17, [x16, #0x348]
  52b9c8:      	add	x16, x16, #0x348
  52b9cc:      	br	x17

000000000052b9d0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter13setEffectPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiNS_17CMTIKOpenEyesModeEbS7_@plt>:
  52b9d0:      	adrp	x16, 0x54c000
  52b9d4:      	ldr	x17, [x16, #0x350]
  52b9d8:      	add	x16, x16, #0x350
  52b9dc:      	br	x17

000000000052b9e0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter7doSmileEb@plt>:
  52b9e0:      	adrp	x16, 0x54c000
  52b9e4:      	ldr	x17, [x16, #0x358]
  52b9e8:      	add	x16, x16, #0x358
  52b9ec:      	br	x17

000000000052b9f0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter10preProcessEv@plt>:
  52b9f0:      	adrp	x16, 0x54c000
  52b9f4:      	ldr	x17, [x16, #0x360]
  52b9f8:      	add	x16, x16, #0x360
  52b9fc:      	br	x17

000000000052ba00 <_ZN12MTImageKitNS9MTuneInfo13getParamCountEv@plt>:
  52ba00:      	adrp	x16, 0x54c000
  52ba04:      	ldr	x17, [x16, #0x368]
  52ba08:      	add	x16, x16, #0x368
  52ba0c:      	br	x17

000000000052ba10 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter15SetEffectFaceIdEi@plt>:
  52ba10:      	adrp	x16, 0x54c000
  52ba14:      	ldr	x17, [x16, #0x370]
  52ba18:      	add	x16, x16, #0x370
  52ba1c:      	br	x17

000000000052ba20 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter13setEffectInfoE15MTuneEffectTypeRNSt6__ndk16vectorIfNS2_9allocatorIfEEEE@plt>:
  52ba20:      	adrp	x16, 0x54c000
  52ba24:      	ldr	x17, [x16, #0x378]
  52ba28:      	add	x16, x16, #0x378
  52ba2c:      	br	x17

000000000052ba30 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter17getBGRequestParamEv@plt>:
  52ba30:      	adrp	x16, 0x54c000
  52ba34:      	ldr	x17, [x16, #0x380]
  52ba38:      	add	x16, x16, #0x380
  52ba3c:      	br	x17

000000000052ba40 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter21enableBackGroudRepairEb@plt>:
  52ba40:      	adrp	x16, 0x54c000
  52ba44:      	ldr	x17, [x16, #0x388]
  52ba48:      	add	x16, x16, #0x388
  52ba4c:      	br	x17

000000000052ba50 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter17backgroundRequestENS_21CMTIKBodyRequestParamE@plt>:
  52ba50:      	adrp	x16, 0x54c000
  52ba54:      	ldr	x17, [x16, #0x390]
  52ba58:      	add	x16, x16, #0x390
  52ba5c:      	br	x17

000000000052ba60 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter17backgroundPrepareENSt6__ndk110shared_ptrINS_5ImageEEENS1_6vectorIS4_NS1_9allocatorIS4_EEEE@plt>:
  52ba60:      	adrp	x16, 0x54c000
  52ba64:      	ldr	x17, [x16, #0x398]
  52ba68:      	add	x16, x16, #0x398
  52ba6c:      	br	x17

000000000052ba70 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter12getCacheDataEv@plt>:
  52ba70:      	adrp	x16, 0x54c000
  52ba74:      	ldr	x17, [x16, #0x3a0]
  52ba78:      	add	x16, x16, #0x3a0
  52ba7c:      	br	x17

000000000052ba80 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter18getBackGroundImageEv@plt>:
  52ba80:      	adrp	x16, 0x54c000
  52ba84:      	ldr	x17, [x16, #0x3a8]
  52ba88:      	add	x16, x16, #0x3a8
  52ba8c:      	br	x17

000000000052ba90 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter17getBackGroundMaskEv@plt>:
  52ba90:      	adrp	x16, 0x54c000
  52ba94:      	ldr	x17, [x16, #0x3b0]
  52ba98:      	add	x16, x16, #0x3b0
  52ba9c:      	br	x17

000000000052baa0 <_ZN12MTImageKitNS16CMTIKTeethFilterC1Ev@plt>:
  52baa0:      	adrp	x16, 0x54c000
  52baa4:      	ldr	x17, [x16, #0x3b8]
  52baa8:      	add	x16, x16, #0x3b8
  52baac:      	br	x17

000000000052bab0 <_ZN12MTImageKitNS16CMTIKTeethFilter15setTeethOptModeENS_17CMTIKTeethOptModeE@plt>:
  52bab0:      	adrp	x16, 0x54c000
  52bab4:      	ldr	x17, [x16, #0x3c0]
  52bab8:      	add	x16, x16, #0x3c0
  52babc:      	br	x17

000000000052bac0 <_ZN12MTImageKitNS16CMTIKTeethFilter12setTidyTeethEiNS_15TeethBeautyModeE@plt>:
  52bac0:      	adrp	x16, 0x54c000
  52bac4:      	ldr	x17, [x16, #0x3c8]
  52bac8:      	add	x16, x16, #0x3c8
  52bacc:      	br	x17

000000000052bad0 <_ZN12MTImageKitNS16CMTIKTeethFilter17useNewTeethEffectEb@plt>:
  52bad0:      	adrp	x16, 0x54c000
  52bad4:      	ldr	x17, [x16, #0x3d0]
  52bad8:      	add	x16, x16, #0x3d0
  52badc:      	br	x17

000000000052bae0 <_ZN12MTImageKitNS16CMTIKTeethFilter11setCacheDirENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bae0:      	adrp	x16, 0x54c000
  52bae4:      	ldr	x17, [x16, #0x3d8]
  52bae8:      	add	x16, x16, #0x3d8
  52baec:      	br	x17

000000000052baf0 <_ZN12MTImageKitNS16CMTIKTeethFilter16applyTeethRepairEiNS_17CMTIKTeethOptModeEbbbNS_15TeethBeautyModeEfb@plt>:
  52baf0:      	adrp	x16, 0x54c000
  52baf4:      	ldr	x17, [x16, #0x3e0]
  52baf8:      	add	x16, x16, #0x3e0
  52bafc:      	br	x17

000000000052bb00 <_ZN12MTImageKitNS16CMTIKTeethFilter12setAutoTeethEif@plt>:
  52bb00:      	adrp	x16, 0x54c000
  52bb04:      	ldr	x17, [x16, #0x3e8]
  52bb08:      	add	x16, x16, #0x3e8
  52bb0c:      	br	x17

000000000052bb10 <_ZN12MTImageKitNS17CMTIKPuzzleFilter17parsePosterConfigERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_9PuzzleXmlE@plt>:
  52bb10:      	adrp	x16, 0x54c000
  52bb14:      	ldr	x17, [x16, #0x3f0]
  52bb18:      	add	x16, x16, #0x3f0
  52bb1c:      	br	x17

000000000052bb20 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc@plt>:
  52bb20:      	adrp	x16, 0x54c000
  52bb24:      	ldr	x17, [x16, #0x3f8]
  52bb28:      	add	x16, x16, #0x3f8
  52bb2c:      	br	x17

000000000052bb30 <_ZN12MTImageKitNS17CMTIKPuzzleFilter15setPuzzleConfigENS_15CMTIKPuzzleModeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS_26CMTIKPuzzleIntelligentModeEbPKNS_17CMTIKPuzzleBgInfoEPKNS_9PuzzleXmlE@plt>:
  52bb30:      	adrp	x16, 0x54c000
  52bb34:      	ldr	x17, [x16, #0x400]
  52bb38:      	add	x16, x16, #0x400
  52bb3c:      	br	x17

000000000052bb40 <_ZN12MTImageKitNS17CMTIKPuzzleFilter21preParseSpecialConfigERNS_15CMTIKPuzzleModeERNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
  52bb40:      	adrp	x16, 0x54c000
  52bb44:      	ldr	x17, [x16, #0x408]
  52bb48:      	add	x16, x16, #0x408
  52bb4c:      	br	x17

000000000052bb50 <_ZN12MTImageKitNS17CMTIKPuzzleFilterC1Ev@plt>:
  52bb50:      	adrp	x16, 0x54c000
  52bb54:      	ldr	x17, [x16, #0x410]
  52bb58:      	add	x16, x16, #0x410
  52bb5c:      	br	x17

000000000052bb60 <_ZN12MTImageKitNS20CMTIKHeadScaleFilterC1Ev@plt>:
  52bb60:      	adrp	x16, 0x54c000
  52bb64:      	ldr	x17, [x16, #0x418]
  52bb68:      	add	x16, x16, #0x418
  52bb6c:      	br	x17

000000000052bb70 <_ZN12MTImageKitNS19CMTIKHeadScaleModelC1Ev@plt>:
  52bb70:      	adrp	x16, 0x54c000
  52bb74:      	ldr	x17, [x16, #0x420]
  52bb78:      	add	x16, x16, #0x420
  52bb7c:      	br	x17

000000000052bb80 <_ZN12MTImageKitNS24CMTIKIdentityPhotoFilterC1Ev@plt>:
  52bb80:      	adrp	x16, 0x54c000
  52bb84:      	ldr	x17, [x16, #0x428]
  52bb88:      	add	x16, x16, #0x428
  52bb8c:      	br	x17

000000000052bb90 <_ZN12MTImageKitNS24CMTIKIdentityPhotoFilter22applyIdentityPhotoDataENS_22CMTIKIdentityPhotoDataE@plt>:
  52bb90:      	adrp	x16, 0x54c000
  52bb94:      	ldr	x17, [x16, #0x430]
  52bb98:      	add	x16, x16, #0x430
  52bb9c:      	br	x17

000000000052bba0 <_ZN12MTImageKitNS25CMTIKFrameAnimationFilterC1Ev@plt>:
  52bba0:      	adrp	x16, 0x54c000
  52bba4:      	ldr	x17, [x16, #0x438]
  52bba8:      	add	x16, x16, #0x438
  52bbac:      	br	x17

000000000052bbb0 <_ZN12MTImageKitNS25CMTIKFrameAnimationFilter21loadDynamicStrokePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bbb0:      	adrp	x16, 0x54c000
  52bbb4:      	ldr	x17, [x16, #0x440]
  52bbb8:      	add	x16, x16, #0x440
  52bbbc:      	br	x17

000000000052bbc0 <_ZN12MTImageKitNS25CMTIKFrameAnimationFilter20setDynamicStrokeMaskERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bbc0:      	adrp	x16, 0x54c000
  52bbc4:      	ldr	x17, [x16, #0x448]
  52bbc8:      	add	x16, x16, #0x448
  52bbcc:      	br	x17

000000000052bbd0 <_ZN12MTImageKitNS25CMTIKFrameAnimationFilter21setDynamicStrokeColorERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
  52bbd0:      	adrp	x16, 0x54c000
  52bbd4:      	ldr	x17, [x16, #0x450]
  52bbd8:      	add	x16, x16, #0x450
  52bbdc:      	br	x17

000000000052bbe0 <_ZN12MTImageKitNS25CMTIKFrameAnimationFilter24setDynamicStrokeDistanceEf@plt>:
  52bbe0:      	adrp	x16, 0x54c000
  52bbe4:      	ldr	x17, [x16, #0x458]
  52bbe8:      	add	x16, x16, #0x458
  52bbec:      	br	x17

000000000052bbf0 <_ZN12MTImageKitNS25CMTIKFrameAnimationFilter25setDynamicStrokeThicknessEf@plt>:
  52bbf0:      	adrp	x16, 0x54c000
  52bbf4:      	ldr	x17, [x16, #0x460]
  52bbf8:      	add	x16, x16, #0x460
  52bbfc:      	br	x17

000000000052bc00 <_ZN12MTImageKitNS11CMTIKFilter19getFullscreenEnableEv@plt>:
  52bc00:      	adrp	x16, 0x54c000
  52bc04:      	ldr	x17, [x16, #0x468]
  52bc08:      	add	x16, x16, #0x468
  52bc0c:      	br	x17

000000000052bc10 <_ZN12MTImageKitNS11CMTIKFilter17setFullscreenMaskERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bc10:      	adrp	x16, 0x54c000
  52bc14:      	ldr	x17, [x16, #0x470]
  52bc18:      	add	x16, x16, #0x470
  52bc1c:      	br	x17

000000000052bc20 <_ZN12MTImageKitNS11CMTIKFilter24setFullscreenMaskChannelEi@plt>:
  52bc20:      	adrp	x16, 0x54c000
  52bc24:      	ldr	x17, [x16, #0x478]
  52bc28:      	add	x16, x16, #0x478
  52bc2c:      	br	x17

000000000052bc30 <_ZN12MTImageKitNS16CMTIKVideoFilter19setLiveCoverEnabledEb@plt>:
  52bc30:      	adrp	x16, 0x54c000
  52bc34:      	ldr	x17, [x16, #0x480]
  52bc38:      	add	x16, x16, #0x480
  52bc3c:      	br	x17

000000000052bc40 <_ZN12MTImageKitNS16CMTIKMakeupModelC1Ev@plt>:
  52bc40:      	adrp	x16, 0x54c000
  52bc44:      	ldr	x17, [x16, #0x488]
  52bc48:      	add	x16, x16, #0x488
  52bc4c:      	br	x17

000000000052bc50 <_ZNSt6__ndk14stolERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
  52bc50:      	adrp	x16, 0x54c000
  52bc54:      	ldr	x17, [x16, #0x490]
  52bc58:      	add	x16, x16, #0x490
  52bc5c:      	br	x17

000000000052bc60 <_ZN12MTImageKitNS11Framebuffer18imageToFrameBufferEPKNS_5ImageENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEE@plt>:
  52bc60:      	adrp	x16, 0x54c000
  52bc64:      	ldr	x17, [x16, #0x498]
  52bc68:      	add	x16, x16, #0x498
  52bc6c:      	br	x17

000000000052bc70 <_ZN12MTImageKitNS17CMTIKMakeupFilterC1Ev@plt>:
  52bc70:      	adrp	x16, 0x54c000
  52bc74:      	ldr	x17, [x16, #0x4a0]
  52bc78:      	add	x16, x16, #0x4a0
  52bc7c:      	br	x17

000000000052bc80 <_ZN12MTImageKitNS17CMTIKMakeupFilter12removeFilterEl@plt>:
  52bc80:      	adrp	x16, 0x54c000
  52bc84:      	ldr	x17, [x16, #0x4a8]
  52bc88:      	add	x16, x16, #0x4a8
  52bc8c:      	br	x17

000000000052bc90 <_ZN12MTImageKitNS17CMTIKMakeupFilter14clearAllEffectEv@plt>:
  52bc90:      	adrp	x16, 0x54c000
  52bc94:      	ldr	x17, [x16, #0x4b0]
  52bc98:      	add	x16, x16, #0x4b0
  52bc9c:      	br	x17

000000000052bca0 <_ZN12MTImageKitNS17CMTIKMakeupFilter17applyMakeupEffectENSt6__ndk13mapINS_11CMakeupTypeENS_12CMakeupParamENS1_4lessIS3_EENS1_9allocatorINS1_4pairIKS3_S4_EEEEEEib@plt>:
  52bca0:      	adrp	x16, 0x54c000
  52bca4:      	ldr	x17, [x16, #0x4b8]
  52bca8:      	add	x16, x16, #0x4b8
  52bcac:      	br	x17

000000000052bcb0 <_ZN12MTImageKitNS17CMTIKMakeupFilter19setBestRemoveMakeupEb@plt>:
  52bcb0:      	adrp	x16, 0x54c000
  52bcb4:      	ldr	x17, [x16, #0x4c0]
  52bcb8:      	add	x16, x16, #0x4c0
  52bcbc:      	br	x17

000000000052bcc0 <_ZN12MTImageKitNS17CMTIKMakeupFilter12removeMakeupENSt6__ndk13mapIiNS2_INS_11CMakeupTypeEfNS1_4lessIS3_EENS1_9allocatorINS1_4pairIKS3_fEEEEEENS4_IiEENS6_INS7_IKiSB_EEEEEEb@plt>:
  52bcc0:      	adrp	x16, 0x54c000
  52bcc4:      	ldr	x17, [x16, #0x4c8]
  52bcc8:      	add	x16, x16, #0x4c8
  52bccc:      	br	x17

000000000052bcd0 <_ZN12MTImageKitNS18CMTIKStickerFilter18loadARMaterialPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bcd0:      	adrp	x16, 0x54c000
  52bcd4:      	ldr	x17, [x16, #0x4d0]
  52bcd8:      	add	x16, x16, #0x4d0
  52bcdc:      	br	x17

000000000052bce0 <_ZN12MTImageKitNS17CMTIKMakeupFilter9addFilterEPNS_11CMTIKFilterEib@plt>:
  52bce0:      	adrp	x16, 0x54c000
  52bce4:      	ldr	x17, [x16, #0x4d8]
  52bce8:      	add	x16, x16, #0x4d8
  52bcec:      	br	x17

000000000052bcf0 <_ZN12MTImageKitNS17CMTIKMakeupFilter14setEyeBrowRGBAENSt6__ndk16vectorIfNS1_9allocatorIfEEEEi@plt>:
  52bcf0:      	adrp	x16, 0x54c000
  52bcf4:      	ldr	x17, [x16, #0x4e0]
  52bcf8:      	add	x16, x16, #0x4e0
  52bcfc:      	br	x17

000000000052bd00 <_ZN12MTImageKitNS17CMTIKMakeupFilter17doDoubleEyelidPreEb@plt>:
  52bd00:      	adrp	x16, 0x54c000
  52bd04:      	ldr	x17, [x16, #0x4e8]
  52bd08:      	add	x16, x16, #0x4e8
  52bd0c:      	br	x17

000000000052bd10 <_ZN12MTImageKitNS17CMTIKMakeupFilter21getDefaultEyeBrowRGBAEv@plt>:
  52bd10:      	adrp	x16, 0x54c000
  52bd14:      	ldr	x17, [x16, #0x4f0]
  52bd18:      	add	x16, x16, #0x4f0
  52bd1c:      	br	x17

000000000052bd20 <_ZN12MTImageKitNS15CMTIKMarkFilterC1Ev@plt>:
  52bd20:      	adrp	x16, 0x54c000
  52bd24:      	ldr	x17, [x16, #0x4f8]
  52bd28:      	add	x16, x16, #0x4f8
  52bd2c:      	br	x17

000000000052bd30 <_ZN12MTImageKitNS15CMTIKMarkFilter12setMarkParamEPNS_17CMTIKMarkParams_TE@plt>:
  52bd30:      	adrp	x16, 0x54c000
  52bd34:      	ldr	x17, [x16, #0x500]
  52bd38:      	add	x16, x16, #0x500
  52bd3c:      	br	x17

000000000052bd40 <_ZN12MTImageKitNS21CMTIKShinyCleanFilterC1Ev@plt>:
  52bd40:      	adrp	x16, 0x54c000
  52bd44:      	ldr	x17, [x16, #0x508]
  52bd48:      	add	x16, x16, #0x508
  52bd4c:      	br	x17

000000000052bd50 <_ZN12MTImageKitNS21CMTIKShinyCleanFilter18setAutoRtPlistPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bd50:      	adrp	x16, 0x54c000
  52bd54:      	ldr	x17, [x16, #0x510]
  52bd58:      	add	x16, x16, #0x510
  52bd5c:      	br	x17

000000000052bd60 <_ZN12MTImageKitNS21CMTIKShinyCleanFilter17setShinyCleanTypeENS_17CShinyCleanType_TE@plt>:
  52bd60:      	adrp	x16, 0x54c000
  52bd64:      	ldr	x17, [x16, #0x518]
  52bd68:      	add	x16, x16, #0x518
  52bd6c:      	br	x17

000000000052bd70 <_ZN12MTImageKitNS21CMTIKShinyCleanFilter24applyAutoShinyCleanParamENS_18CShinyCleanParam_TE@plt>:
  52bd70:      	adrp	x16, 0x54c000
  52bd74:      	ldr	x17, [x16, #0x520]
  52bd78:      	add	x16, x16, #0x520
  52bd7c:      	br	x17

000000000052bd80 <_ZN12MTImageKitNS22CMTIKOneKeyBeautyModelC1Ev@plt>:
  52bd80:      	adrp	x16, 0x54c000
  52bd84:      	ldr	x17, [x16, #0x528]
  52bd88:      	add	x16, x16, #0x528
  52bd8c:      	br	x17

000000000052bd90 <_ZN12MTImageKitNS22CMTIKEntityGroupFilterC1Ev@plt>:
  52bd90:      	adrp	x16, 0x54c000
  52bd94:      	ldr	x17, [x16, #0x530]
  52bd98:      	add	x16, x16, #0x530
  52bd9c:      	br	x17

000000000052bda0 <_ZN12MTImageKitNS22CMTIKEntityGroupFilter21setNeedRenderControlsEb@plt>:
  52bda0:      	adrp	x16, 0x54c000
  52bda4:      	ldr	x17, [x16, #0x538]
  52bda8:      	add	x16, x16, #0x538
  52bdac:      	br	x17

000000000052bdb0 <_ZNK12MTImageKitNS15CMTIKFaceResult12getFaceIndexEi@plt>:
  52bdb0:      	adrp	x16, 0x54c000
  52bdb4:      	ldr	x17, [x16, #0x540]
  52bdb8:      	add	x16, x16, #0x540
  52bdbc:      	br	x17

000000000052bdc0 <_ZN12MTImageKitNS21CMTIKAutoBeautyFilter21getDefaultFemaleParamENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bdc0:      	adrp	x16, 0x54c000
  52bdc4:      	ldr	x17, [x16, #0x548]
  52bdc8:      	add	x16, x16, #0x548
  52bdcc:      	br	x17

000000000052bdd0 <_ZN12MTImageKitNS21CMTIKAutoBeautyFilterC1Ev@plt>:
  52bdd0:      	adrp	x16, 0x54c000
  52bdd4:      	ldr	x17, [x16, #0x550]
  52bdd8:      	add	x16, x16, #0x550
  52bddc:      	br	x17

000000000052bde0 <_ZN12MTImageKitNS21CMTIKAutoBeautyFilter13setEffectPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52bde0:      	adrp	x16, 0x54c000
  52bde4:      	ldr	x17, [x16, #0x558]
  52bde8:      	add	x16, x16, #0x558
  52bdec:      	br	x17

000000000052bdf0 <_ZN12MTImageKitNS21CMTIKAutoBeautyFilter9setFaceIDENSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
  52bdf0:      	adrp	x16, 0x54c000
  52bdf4:      	ldr	x17, [x16, #0x560]
  52bdf8:      	add	x16, x16, #0x560
  52bdfc:      	br	x17

000000000052be00 <_ZN12MTImageKitNS21CMTIKAutoBeautyFilter20applyAutoBeautyParamENS_18CAutoBeautyParam_TE@plt>:
  52be00:      	adrp	x16, 0x54c000
  52be04:      	ldr	x17, [x16, #0x568]
  52be08:      	add	x16, x16, #0x568
  52be0c:      	br	x17

000000000052be10 <_ZN12MTImageKitNS21CMTIKAutoBeautyFilter19getDefaultMaleParamENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52be10:      	adrp	x16, 0x54c000
  52be14:      	ldr	x17, [x16, #0x570]
  52be18:      	add	x16, x16, #0x570
  52be1c:      	br	x17

000000000052be20 <_ZN12MTImageKitNS19CMTIKRealtimeFilter13setInterImageENSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52be20:      	adrp	x16, 0x54c000
  52be24:      	ldr	x17, [x16, #0x578]
  52be28:      	add	x16, x16, #0x578
  52be2c:      	br	x17

000000000052be30 <_ZN12MTImageKitNS22CMTIKSkinBeautyMFModelC1Ev@plt>:
  52be30:      	adrp	x16, 0x54c000
  52be34:      	ldr	x17, [x16, #0x580]
  52be38:      	add	x16, x16, #0x580
  52be3c:      	br	x17

000000000052be40 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilterC1Ev@plt>:
  52be40:      	adrp	x16, 0x54c000
  52be44:      	ldr	x17, [x16, #0x588]
  52be48:      	add	x16, x16, #0x588
  52be4c:      	br	x17

000000000052be50 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter30setMakeupRepairAigcResultImageERKNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52be50:      	adrp	x16, 0x54c000
  52be54:      	ldr	x17, [x16, #0x590]
  52be58:      	add	x16, x16, #0x590
  52be5c:      	br	x17

000000000052be60 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter27setFleckFlawAigcResultImageERKNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52be60:      	adrp	x16, 0x54c000
  52be64:      	ldr	x17, [x16, #0x598]
  52be68:      	add	x16, x16, #0x598
  52be6c:      	br	x17

000000000052be70 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter13prepareEffectEv@plt>:
  52be70:      	adrp	x16, 0x54c000
  52be74:      	ldr	x17, [x16, #0x5a0]
  52be78:      	add	x16, x16, #0x5a0
  52be7c:      	br	x17

000000000052be80 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter27prepareFaceEffectPreprocessEi@plt>:
  52be80:      	adrp	x16, 0x54c000
  52be84:      	ldr	x17, [x16, #0x5a8]
  52be88:      	add	x16, x16, #0x5a8
  52be8c:      	br	x17

000000000052be90 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter26applyBodyAigcEffectRequestENSt6__ndk16vectorINS_27CMTIKWakeSkinBodyEffectTypeENS1_9allocatorIS3_EEEEf@plt>:
  52be90:      	adrp	x16, 0x54c000
  52be94:      	ldr	x17, [x16, #0x5b0]
  52be98:      	add	x16, x16, #0x5b0
  52be9c:      	br	x17

000000000052bea0 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter28applyMakeupRepairAigcRequestEv@plt>:
  52bea0:      	adrp	x16, 0x54c000
  52bea4:      	ldr	x17, [x16, #0x5b8]
  52bea8:      	add	x16, x16, #0x5b8
  52beac:      	br	x17

000000000052beb0 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter21setMakeupRepairEffectEf@plt>:
  52beb0:      	adrp	x16, 0x54c000
  52beb4:      	ldr	x17, [x16, #0x5c0]
  52beb8:      	add	x16, x16, #0x5c0
  52bebc:      	br	x17

000000000052bec0 <_ZN12MTImageKitNS20CMTIKVLAIImageDetect12isLowMachineEv@plt>:
  52bec0:      	adrp	x16, 0x54c000
  52bec4:      	ldr	x17, [x16, #0x5c8]
  52bec8:      	add	x16, x16, #0x5c8
  52becc:      	br	x17

000000000052bed0 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter25applyFleckFlawAigcRequestEv@plt>:
  52bed0:      	adrp	x16, 0x54c000
  52bed4:      	ldr	x17, [x16, #0x5d0]
  52bed8:      	add	x16, x16, #0x5d0
  52bedc:      	br	x17

000000000052bee0 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter17setSkinWhitenTypeENS_16CMTIKSkinLutTypeEl@plt>:
  52bee0:      	adrp	x16, 0x54c000
  52bee4:      	ldr	x17, [x16, #0x5d8]
  52bee8:      	add	x16, x16, #0x5d8
  52beec:      	br	x17

000000000052bef0 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter21applySkinWhitenEffectEff@plt>:
  52bef0:      	adrp	x16, 0x54c000
  52bef4:      	ldr	x17, [x16, #0x5e0]
  52bef8:      	add	x16, x16, #0x5e0
  52befc:      	br	x17

000000000052bf00 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter19applySkinEvenEffectEf@plt>:
  52bf00:      	adrp	x16, 0x54c000
  52bf04:      	ldr	x17, [x16, #0x5e8]
  52bf08:      	add	x16, x16, #0x5e8
  52bf0c:      	br	x17

000000000052bf10 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter23applyBodySkinEvenEffectEf@plt>:
  52bf10:      	adrp	x16, 0x54c000
  52bf14:      	ldr	x17, [x16, #0x5f0]
  52bf18:      	add	x16, x16, #0x5f0
  52bf1c:      	br	x17

000000000052bf20 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter19setBodySkinEvenTypeENS_23CMTIKBodySkinEvenTypeMFE@plt>:
  52bf20:      	adrp	x16, 0x54c000
  52bf24:      	ldr	x17, [x16, #0x5f8]
  52bf28:      	add	x16, x16, #0x5f8
  52bf2c:      	br	x17

000000000052bf30 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter26setBodySkinEvenCustomColorENS_5_Vec4IfEE@plt>:
  52bf30:      	adrp	x16, 0x54c000
  52bf34:      	ldr	x17, [x16, #0x600]
  52bf38:      	add	x16, x16, #0x600
  52bf3c:      	br	x17

000000000052bf40 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter16setWakeSkinModelENS_18CMTIKWakeSkinParamEb@plt>:
  52bf40:      	adrp	x16, 0x54c000
  52bf44:      	ldr	x17, [x16, #0x608]
  52bf48:      	add	x16, x16, #0x608
  52bf4c:      	br	x17

000000000052bf50 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter20applyFleckFlawEffectEb@plt>:
  52bf50:      	adrp	x16, 0x54c000
  52bf54:      	ldr	x17, [x16, #0x610]
  52bf58:      	add	x16, x16, #0x610
  52bf5c:      	br	x17

000000000052bf60 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter20setCustomWhitenColorENS_5_Vec4IfEE@plt>:
  52bf60:      	adrp	x16, 0x54c000
  52bf64:      	ldr	x17, [x16, #0x618]
  52bf68:      	add	x16, x16, #0x618
  52bf6c:      	br	x17

000000000052bf70 <_ZN12MTImageKitNS20CMTIKSkinBeautyModelC1Ev@plt>:
  52bf70:      	adrp	x16, 0x54c000
  52bf74:      	ldr	x17, [x16, #0x620]
  52bf78:      	add	x16, x16, #0x620
  52bf7c:      	br	x17

000000000052bf80 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilterC1Ev@plt>:
  52bf80:      	adrp	x16, 0x54c000
  52bf84:      	ldr	x17, [x16, #0x628]
  52bf88:      	add	x16, x16, #0x628
  52bf8c:      	br	x17

000000000052bf90 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter30setMakeupRepairAigcResultImageERKNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52bf90:      	adrp	x16, 0x54c000
  52bf94:      	ldr	x17, [x16, #0x630]
  52bf98:      	add	x16, x16, #0x630
  52bf9c:      	br	x17

000000000052bfa0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter27setFleckFlawAigcResultImageERKNSt6__ndk110shared_ptrINS_5ImageEEE@plt>:
  52bfa0:      	adrp	x16, 0x54c000
  52bfa4:      	ldr	x17, [x16, #0x638]
  52bfa8:      	add	x16, x16, #0x638
  52bfac:      	br	x17

000000000052bfb0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter13prepareEffectEv@plt>:
  52bfb0:      	adrp	x16, 0x54c000
  52bfb4:      	ldr	x17, [x16, #0x640]
  52bfb8:      	add	x16, x16, #0x640
  52bfbc:      	br	x17

000000000052bfc0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter26applyBodyAigcEffectRequestENSt6__ndk16vectorINS_27CMTIKWakeSkinBodyEffectTypeENS1_9allocatorIS3_EEEEf@plt>:
  52bfc0:      	adrp	x16, 0x54c000
  52bfc4:      	ldr	x17, [x16, #0x648]
  52bfc8:      	add	x16, x16, #0x648
  52bfcc:      	br	x17

000000000052bfd0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter20setCustomWhitenColorENS_5_Vec4IfEE@plt>:
  52bfd0:      	adrp	x16, 0x54c000
  52bfd4:      	ldr	x17, [x16, #0x650]
  52bfd8:      	add	x16, x16, #0x650
  52bfdc:      	br	x17

000000000052bfe0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter28applyMakeupRepairAigcRequestEv@plt>:
  52bfe0:      	adrp	x16, 0x54c000
  52bfe4:      	ldr	x17, [x16, #0x658]
  52bfe8:      	add	x16, x16, #0x658
  52bfec:      	br	x17

000000000052bff0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter21setMakeupRepairEffectEf@plt>:
  52bff0:      	adrp	x16, 0x54c000
  52bff4:      	ldr	x17, [x16, #0x660]
  52bff8:      	add	x16, x16, #0x660
  52bffc:      	br	x17

000000000052c000 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter25applyFleckFlawAigcRequestEv@plt>:
  52c000:      	adrp	x16, 0x54c000
  52c004:      	ldr	x17, [x16, #0x668]
  52c008:      	add	x16, x16, #0x668
  52c00c:      	br	x17

000000000052c010 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter17setSkinWhitenTypeENS_16CMTIKSkinLutTypeE@plt>:
  52c010:      	adrp	x16, 0x54c000
  52c014:      	ldr	x17, [x16, #0x670]
  52c018:      	add	x16, x16, #0x670
  52c01c:      	br	x17

000000000052c020 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter21applySkinWhitenEffectEff@plt>:
  52c020:      	adrp	x16, 0x54c000
  52c024:      	ldr	x17, [x16, #0x678]
  52c028:      	add	x16, x16, #0x678
  52c02c:      	br	x17

000000000052c030 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter19applySkinEvenEffectEf@plt>:
  52c030:      	adrp	x16, 0x54c000
  52c034:      	ldr	x17, [x16, #0x680]
  52c038:      	add	x16, x16, #0x680
  52c03c:      	br	x17

000000000052c040 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter23applyBodySkinEvenEffectEf@plt>:
  52c040:      	adrp	x16, 0x54c000
  52c044:      	ldr	x17, [x16, #0x688]
  52c048:      	add	x16, x16, #0x688
  52c04c:      	br	x17

000000000052c050 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter19setBodySkinEvenTypeENS_21CMTIKBodySkinEvenTypeE@plt>:
  52c050:      	adrp	x16, 0x54c000
  52c054:      	ldr	x17, [x16, #0x690]
  52c058:      	add	x16, x16, #0x690
  52c05c:      	br	x17

000000000052c060 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter16setWakeSkinModelENS_18CMTIKWakeSkinParamEb@plt>:
  52c060:      	adrp	x16, 0x54c000
  52c064:      	ldr	x17, [x16, #0x698]
  52c068:      	add	x16, x16, #0x698
  52c06c:      	br	x17

000000000052c070 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter20applyFleckFlawEffectEb@plt>:
  52c070:      	adrp	x16, 0x54c000
  52c074:      	ldr	x17, [x16, #0x6a0]
  52c078:      	add	x16, x16, #0x6a0
  52c07c:      	br	x17

000000000052c080 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter26getBodyEffectCacheImageMapEv@plt>:
  52c080:      	adrp	x16, 0x54c000
  52c084:      	ldr	x17, [x16, #0x6a8]
  52c088:      	add	x16, x16, #0x6a8
  52c08c:      	br	x17

000000000052c090 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter30getMakeupRepairAigcResultImageEv@plt>:
  52c090:      	adrp	x16, 0x54c000
  52c094:      	ldr	x17, [x16, #0x6b0]
  52c098:      	add	x16, x16, #0x6b0
  52c09c:      	br	x17

000000000052c0a0 <_ZN12MTImageKitNS23CMTIKSkinBeautyMFFilter27getFleckFlawAigcResultImageEv@plt>:
  52c0a0:      	adrp	x16, 0x54c000
  52c0a4:      	ldr	x17, [x16, #0x6b8]
  52c0a8:      	add	x16, x16, #0x6b8
  52c0ac:      	br	x17

000000000052c0b0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter26getBodyEffectCacheImageMapEv@plt>:
  52c0b0:      	adrp	x16, 0x54c000
  52c0b4:      	ldr	x17, [x16, #0x6c0]
  52c0b8:      	add	x16, x16, #0x6c0
  52c0bc:      	br	x17

000000000052c0c0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter30getMakeupRepairAigcResultImageEv@plt>:
  52c0c0:      	adrp	x16, 0x54c000
  52c0c4:      	ldr	x17, [x16, #0x6c8]
  52c0c8:      	add	x16, x16, #0x6c8
  52c0cc:      	br	x17

000000000052c0d0 <_ZN12MTImageKitNS21CMTIKSkinBeautyFilter27getFleckFlawAigcResultImageEv@plt>:
  52c0d0:      	adrp	x16, 0x54c000
  52c0d4:      	ldr	x17, [x16, #0x6d0]
  52c0d8:      	add	x16, x16, #0x6d0
  52c0dc:      	br	x17

000000000052c0e0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter15enableBgProtectEb@plt>:
  52c0e0:      	adrp	x16, 0x54c000
  52c0e4:      	ldr	x17, [x16, #0x6d8]
  52c0e8:      	add	x16, x16, #0x6d8
  52c0ec:      	br	x17

000000000052c0f0 <_ZN12MTImageKitNS19CMTIKRealtimeFilter22setEnableSpecialEffectEb@plt>:
  52c0f0:      	adrp	x16, 0x54c000
  52c0f4:      	ldr	x17, [x16, #0x6e0]
  52c0f8:      	add	x16, x16, #0x6e0
  52c0fc:      	br	x17

000000000052c100 <_ZN12MTImageKitNS18CMTIKStickerFilter15getMaterialPathEv@plt>:
  52c100:      	adrp	x16, 0x54c000
  52c104:      	ldr	x17, [x16, #0x6e8]
  52c108:      	add	x16, x16, #0x6e8
  52c10c:      	br	x17

000000000052c110 <_ZN12MTImageKitNS12CMTIKManager21getSrcImageWithOptionENS_26CMTIKFilterGetResultOptionE@plt>:
  52c110:      	adrp	x16, 0x54c000
  52c114:      	ldr	x17, [x16, #0x6f0]
  52c118:      	add	x16, x16, #0x6f0
  52c11c:      	br	x17

000000000052c120 <_ZN12MTImageKitNS18CMTIKStickerFilter15getShowMaskPathEv@plt>:
  52c120:      	adrp	x16, 0x54c000
  52c124:      	ldr	x17, [x16, #0x6f8]
  52c128:      	add	x16, x16, #0x6f8
  52c12c:      	br	x17

000000000052c130 <_ZN12MTImageKitNS18CMTIKStickerFilter10setStickerERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_6vectorIiNS5_IiEEEES9_@plt>:
  52c130:      	adrp	x16, 0x54c000
  52c134:      	ldr	x17, [x16, #0x700]
  52c138:      	add	x16, x16, #0x700
  52c13c:      	br	x17

000000000052c140 <_ZN12MTImageKitNS18CMTIKStickerFilter10setStickerENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_NS_20CMTIKMaskChannelTypeEbb@plt>:
  52c140:      	adrp	x16, 0x54c000
  52c144:      	ldr	x17, [x16, #0x708]
  52c148:      	add	x16, x16, #0x708
  52c14c:      	br	x17

000000000052c150 <_ZN12MTImageKitNS15CMTIKTextFilterC1Ev@plt>:
  52c150:      	adrp	x16, 0x54c000
  52c154:      	ldr	x17, [x16, #0x710]
  52c158:      	add	x16, x16, #0x710
  52c15c:      	br	x17

000000000052c160 <_ZN12MTImageKitNS15CMTIKTextFilter15setMaterialPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52c160:      	adrp	x16, 0x54c000
  52c164:      	ldr	x17, [x16, #0x718]
  52c168:      	add	x16, x16, #0x718
  52c16c:      	br	x17

000000000052c170 <_ZN12MTImageKitNS15CMTIKTextFilter11setBgMirrorEb@plt>:
  52c170:      	adrp	x16, 0x54c000
  52c174:      	ldr	x17, [x16, #0x720]
  52c178:      	add	x16, x16, #0x720
  52c17c:      	br	x17

000000000052c180 <_ZN12MTImageKitNS15CMTIKTextFilter12getTextPlistEv@plt>:
  52c180:      	adrp	x16, 0x54c000
  52c184:      	ldr	x17, [x16, #0x728]
  52c188:      	add	x16, x16, #0x728
  52c18c:      	br	x17

000000000052c190 <_ZN12MTImageKitNS15CMTIKTextFilter17setTextPathConfigEiRNS_21CMTIKARTextPathConfigE@plt>:
  52c190:      	adrp	x16, 0x54c000
  52c194:      	ldr	x17, [x16, #0x730]
  52c198:      	add	x16, x16, #0x730
  52c19c:      	br	x17

000000000052c1a0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
  52c1a0:      	adrp	x16, 0x54c000
  52c1a4:      	ldr	x17, [x16, #0x738]
  52c1a8:      	add	x16, x16, #0x738
  52c1ac:      	br	x17

000000000052c1b0 <_ZN12MTImageKitNS15CMTIKTextFilter13setTextStringEiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52c1b0:      	adrp	x16, 0x54c000
  52c1b4:      	ldr	x17, [x16, #0x740]
  52c1b8:      	add	x16, x16, #0x740
  52c1bc:      	br	x17

000000000052c1c0 <_ZN12MTImageKitNS15CMTIKTextFilter11setTextFontEiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEb@plt>:
  52c1c0:      	adrp	x16, 0x54c000
  52c1c4:      	ldr	x17, [x16, #0x748]
  52c1c8:      	add	x16, x16, #0x748
  52c1cc:      	br	x17

000000000052c1d0 <_ZN12MTImageKitNS15CMTIKTextFilter24setFallbackFontLibrariesEiRKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
  52c1d0:      	adrp	x16, 0x54c000
  52c1d4:      	ldr	x17, [x16, #0x750]
  52c1d8:      	add	x16, x16, #0x750
  52c1dc:      	br	x17

000000000052c1e0 <_ZN12MTImageKitNS15CMTIKTextFilter12setTextORGBAEiRKNS_16CMTIKARTextORGBAEb@plt>:
  52c1e0:      	adrp	x16, 0x54c000
  52c1e4:      	ldr	x17, [x16, #0x758]
  52c1e8:      	add	x16, x16, #0x758
  52c1ec:      	br	x17

000000000052c1f0 <_ZN12MTImageKitNS15CMTIKTextFilter13setTextStrokeEibb@plt>:
  52c1f0:      	adrp	x16, 0x54c000
  52c1f4:      	ldr	x17, [x16, #0x760]
  52c1f8:      	add	x16, x16, #0x760
  52c1fc:      	br	x17

000000000052c200 <_ZN12MTImageKitNS15CMTIKTextFilter17setTextStrokeRGBAEiRN5mtlab7Color4fEb@plt>:
  52c200:      	adrp	x16, 0x54c000
  52c204:      	ldr	x17, [x16, #0x768]
  52c208:      	add	x16, x16, #0x768
  52c20c:      	br	x17

000000000052c210 <_ZN12MTImageKitNS15CMTIKTextFilter17setTextStrokeSizeEifb@plt>:
  52c210:      	adrp	x16, 0x54c000
  52c214:      	ldr	x17, [x16, #0x770]
  52c218:      	add	x16, x16, #0x770
  52c21c:      	br	x17

000000000052c220 <_ZN12MTImageKitNS15CMTIKTextFilter13setTextShadowEibb@plt>:
  52c220:      	adrp	x16, 0x54c000
  52c224:      	ldr	x17, [x16, #0x778]
  52c228:      	add	x16, x16, #0x778
  52c22c:      	br	x17

000000000052c230 <_ZN12MTImageKitNS15CMTIKTextFilter17setTextShadowRGBAEiRN5mtlab7Color4fEb@plt>:
  52c230:      	adrp	x16, 0x54c000
  52c234:      	ldr	x17, [x16, #0x780]
  52c238:      	add	x16, x16, #0x780
  52c23c:      	br	x17

000000000052c240 <_ZN12MTImageKitNS15CMTIKTextFilter19setTextShadowOffsetEiRN5mtlab8Vector2fEb@plt>:
  52c240:      	adrp	x16, 0x54c000
  52c244:      	ldr	x17, [x16, #0x788]
  52c248:      	add	x16, x16, #0x788
  52c24c:      	br	x17

000000000052c250 <_ZN12MTImageKitNS15CMTIKTextFilter17setTextShadowBlurEifb@plt>:
  52c250:      	adrp	x16, 0x54c000
  52c254:      	ldr	x17, [x16, #0x790]
  52c258:      	add	x16, x16, #0x790
  52c25c:      	br	x17

000000000052c260 <_ZN12MTImageKitNS15CMTIKTextFilter22setTextBackgroundColorEibb@plt>:
  52c260:      	adrp	x16, 0x54c000
  52c264:      	ldr	x17, [x16, #0x798]
  52c268:      	add	x16, x16, #0x798
  52c26c:      	br	x17

000000000052c270 <_ZN12MTImageKitNS15CMTIKTextFilter26setTextBackgroundColorRGBAEiRN5mtlab7Color4fEb@plt>:
  52c270:      	adrp	x16, 0x54c000
  52c274:      	ldr	x17, [x16, #0x7a0]
  52c278:      	add	x16, x16, #0x7a0
  52c27c:      	br	x17

000000000052c280 <_ZN12MTImageKitNS15CMTIKTextFilter28setTextBackgroundColorMarginEiib@plt>:
  52c280:      	adrp	x16, 0x54c000
  52c284:      	ldr	x17, [x16, #0x7a8]
  52c288:      	add	x16, x16, #0x7a8
  52c28c:      	br	x17

000000000052c290 <_ZN12MTImageKitNS15CMTIKTextFilter35setTextBackgroundColorMarginExtendsEiPfb@plt>:
  52c290:      	adrp	x16, 0x54c000
  52c294:      	ldr	x17, [x16, #0x7b0]
  52c298:      	add	x16, x16, #0x7b0
  52c29c:      	br	x17

000000000052c2a0 <_ZN12MTImageKitNS15CMTIKTextFilter33setTextBackgroundColorRoundWeightEifb@plt>:
  52c2a0:      	adrp	x16, 0x54c000
  52c2a4:      	ldr	x17, [x16, #0x7b8]
  52c2a8:      	add	x16, x16, #0x7b8
  52c2ac:      	br	x17

000000000052c2b0 <_ZN12MTImageKitNS15CMTIKTextFilter11setTextGlowEibb@plt>:
  52c2b0:      	adrp	x16, 0x54c000
  52c2b4:      	ldr	x17, [x16, #0x7c0]
  52c2b8:      	add	x16, x16, #0x7c0
  52c2bc:      	br	x17

000000000052c2c0 <_ZN12MTImageKitNS15CMTIKTextFilter15setTextGlowRGBAEiRN5mtlab7Color4fEb@plt>:
  52c2c0:      	adrp	x16, 0x54c000
  52c2c4:      	ldr	x17, [x16, #0x7c8]
  52c2c8:      	add	x16, x16, #0x7c8
  52c2cc:      	br	x17

000000000052c2d0 <_ZN12MTImageKitNS15CMTIKTextFilter15setTextGlowBlurEifb@plt>:
  52c2d0:      	adrp	x16, 0x54c000
  52c2d4:      	ldr	x17, [x16, #0x7d0]
  52c2d8:      	add	x16, x16, #0x7d0
  52c2dc:      	br	x17

000000000052c2e0 <_ZN12MTImageKitNS15CMTIKTextFilter22setTextGlowStrokeWidthEifb@plt>:
  52c2e0:      	adrp	x16, 0x54c000
  52c2e4:      	ldr	x17, [x16, #0x7d8]
  52c2e8:      	add	x16, x16, #0x7d8
  52c2ec:      	br	x17

000000000052c2f0 <_ZN12MTImageKitNS15CMTIKTextFilter11setTextBoldEibb@plt>:
  52c2f0:      	adrp	x16, 0x54c000
  52c2f4:      	ldr	x17, [x16, #0x7e0]
  52c2f8:      	add	x16, x16, #0x7e0
  52c2fc:      	br	x17

000000000052c300 <_ZN12MTImageKitNS15CMTIKTextFilter13setTextItalicEibb@plt>:
  52c300:      	adrp	x16, 0x54c000
  52c304:      	ldr	x17, [x16, #0x7e8]
  52c308:      	add	x16, x16, #0x7e8
  52c30c:      	br	x17

000000000052c310 <_ZN12MTImageKitNS15CMTIKTextFilter16setTextUnderlineEibb@plt>:
  52c310:      	adrp	x16, 0x54c000
  52c314:      	ldr	x17, [x16, #0x7f0]
  52c318:      	add	x16, x16, #0x7f0
  52c31c:      	br	x17

000000000052c320 <_ZN12MTImageKitNS15CMTIKTextFilter20setTextStrikeThroughEibb@plt>:
  52c320:      	adrp	x16, 0x54c000
  52c324:      	ldr	x17, [x16, #0x7f8]
  52c328:      	add	x16, x16, #0x7f8
  52c32c:      	br	x17

000000000052c330 <_ZN12MTImageKitNS15CMTIKTextFilter14setTextJustifyEii@plt>:
  52c330:      	adrp	x16, 0x54c000
  52c334:      	ldr	x17, [x16, #0x800]
  52c338:      	add	x16, x16, #0x800
  52c33c:      	br	x17

000000000052c340 <_ZN12MTImageKitNS15CMTIKTextFilter20setTextSequenceStyleEii@plt>:
  52c340:      	adrp	x16, 0x54c000
  52c344:      	ldr	x17, [x16, #0x808]
  52c348:      	add	x16, x16, #0x808
  52c34c:      	br	x17

000000000052c350 <_ZN12MTImageKitNS15CMTIKTextFilter17setTextHorizontalEib@plt>:
  52c350:      	adrp	x16, 0x54c000
  52c354:      	ldr	x17, [x16, #0x810]
  52c358:      	add	x16, x16, #0x810
  52c35c:      	br	x17

000000000052c360 <_ZN12MTImageKitNS15CMTIKTextFilter18setTextLeftToRightEib@plt>:
  52c360:      	adrp	x16, 0x54c000
  52c364:      	ldr	x17, [x16, #0x818]
  52c368:      	add	x16, x16, #0x818
  52c36c:      	br	x17

000000000052c370 <_ZN12MTImageKitNS15CMTIKTextFilter11setTextWrapEib@plt>:
  52c370:      	adrp	x16, 0x54c000
  52c374:      	ldr	x17, [x16, #0x820]
  52c378:      	add	x16, x16, #0x820
  52c37c:      	br	x17

000000000052c380 <_ZN12MTImageKitNS15CMTIKTextFilter13setTextShrinkEib@plt>:
  52c380:      	adrp	x16, 0x54c000
  52c384:      	ldr	x17, [x16, #0x828]
  52c388:      	add	x16, x16, #0x828
  52c38c:      	br	x17

000000000052c390 <_ZN12MTImageKitNS15CMTIKTextFilter14setTextSpacingEif@plt>:
  52c390:      	adrp	x16, 0x54c000
  52c394:      	ldr	x17, [x16, #0x830]
  52c398:      	add	x16, x16, #0x830
  52c39c:      	br	x17

000000000052c3a0 <_ZN12MTImageKitNS15CMTIKTextFilter18setTextLineSpacingEif@plt>:
  52c3a0:      	adrp	x16, 0x54c000
  52c3a4:      	ldr	x17, [x16, #0x838]
  52c3a8:      	add	x16, x16, #0x838
  52c3ac:      	br	x17

000000000052c3b0 <_ZN12MTImageKitNS15CMTIKTextFilter21setTextGradientConfigEiRNS_25CMTIKARTextGradientConfigE@plt>:
  52c3b0:      	adrp	x16, 0x54c000
  52c3b4:      	ldr	x17, [x16, #0x840]
  52c3b8:      	add	x16, x16, #0x840
  52c3bc:      	br	x17

000000000052c3c0 <_ZN12MTImageKitNS15CMTIKTextFilter17setAnimationInfosERKNSt6__ndk16vectorINS_18CMTIKAnimationInfoENS1_9allocatorIS3_EEEE@plt>:
  52c3c0:      	adrp	x16, 0x54c000
  52c3c4:      	ldr	x17, [x16, #0x848]
  52c3c8:      	add	x16, x16, #0x848
  52c3cc:      	br	x17

000000000052c3d0 <_ZN12MTImageKitNS15CMTIKTextFilter17getAnimationInfosEv@plt>:
  52c3d0:      	adrp	x16, 0x54c000
  52c3d4:      	ldr	x17, [x16, #0x850]
  52c3d8:      	add	x16, x16, #0x850
  52c3dc:      	br	x17

000000000052c3e0 <_ZN12MTImageKitNS15CMTIKTextFilter19setLiveCoverEnabledEb@plt>:
  52c3e0:      	adrp	x16, 0x54c000
  52c3e4:      	ldr	x17, [x16, #0x858]
  52c3e8:      	add	x16, x16, #0x858
  52c3ec:      	br	x17

000000000052c3f0 <_ZN12MTImageKitNS15CMTIKTextFilter24setSelectHighlightConfigEiNSt6__ndk16vectorINS_32CMTIKARTextSelectHighlightConfigENS1_9allocatorIS3_EEEE@plt>:
  52c3f0:      	adrp	x16, 0x54c000
  52c3f4:      	ldr	x17, [x16, #0x860]
  52c3f8:      	add	x16, x16, #0x860
  52c3fc:      	br	x17

000000000052c400 <_ZN12MTImageKitNS15CMTIKTextFilter19setLoadAndSetLocateEb@plt>:
  52c400:      	adrp	x16, 0x54c000
  52c404:      	ldr	x17, [x16, #0x868]
  52c408:      	add	x16, x16, #0x868
  52c40c:      	br	x17

000000000052c410 <_ZN12MTImageKitNS15CMTIKTextFilter26getFullscreenWatermarkDataEv@plt>:
  52c410:      	adrp	x16, 0x54c000
  52c414:      	ldr	x17, [x16, #0x870]
  52c418:      	add	x16, x16, #0x870
  52c41c:      	br	x17

000000000052c420 <_ZN12MTImageKitNS15CMTIKTextFilter26setFullscreenWatermarkDataERKNS_22CMTIKWatermarkInfoDataEb@plt>:
  52c420:      	adrp	x16, 0x54c000
  52c424:      	ldr	x17, [x16, #0x878]
  52c428:      	add	x16, x16, #0x878
  52c42c:      	br	x17

000000000052c430 <_ZNSt6__ndk16localeC1Ev@plt>:
  52c430:      	adrp	x16, 0x54c000
  52c434:      	ldr	x17, [x16, #0x880]
  52c438:      	add	x16, x16, #0x880
  52c43c:      	br	x17

000000000052c440 <_ZNSt6__ndk111regex_errorC1ENS_15regex_constants10error_typeE@plt>:
  52c440:      	adrp	x16, 0x54c000
  52c444:      	ldr	x17, [x16, #0x888]
  52c448:      	add	x16, x16, #0x888
  52c44c:      	br	x17

000000000052c450 <memchr@plt>:
  52c450:      	adrp	x16, 0x54c000
  52c454:      	ldr	x17, [x16, #0x890]
  52c458:      	add	x16, x16, #0x890
  52c45c:      	br	x17

000000000052c460 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
  52c460:      	adrp	x16, 0x54c000
  52c464:      	ldr	x17, [x16, #0x898]
  52c468:      	add	x16, x16, #0x898
  52c46c:      	br	x17

000000000052c470 <_ZNKSt6__ndk16locale4nameEv@plt>:
  52c470:      	adrp	x16, 0x54c000
  52c474:      	ldr	x17, [x16, #0x8a0]
  52c478:      	add	x16, x16, #0x8a0
  52c47c:      	br	x17

000000000052c480 <_ZNSt6__ndk120__get_collation_nameEPKc@plt>:
  52c480:      	adrp	x16, 0x54c000
  52c484:      	ldr	x17, [x16, #0x8a8]
  52c488:      	add	x16, x16, #0x8a8
  52c48c:      	br	x17

000000000052c490 <_ZNSt6__ndk115__get_classnameEPKcb@plt>:
  52c490:      	adrp	x16, 0x54c000
  52c494:      	ldr	x17, [x16, #0x8b0]
  52c498:      	add	x16, x16, #0x8b0
  52c49c:      	br	x17

000000000052c4a0 <_ZN12MTImageKitNS19CMTIKWakeSkinFilter24processAiEliminateEffectENSt6__ndk110shared_ptrINS_5ImageEEENS2_INS_15CMTIKFaceResultEEEi@plt>:
  52c4a0:      	adrp	x16, 0x54c000
  52c4a4:      	ldr	x17, [x16, #0x8b8]
  52c4a8:      	add	x16, x16, #0x8b8
  52c4ac:      	br	x17

000000000052c4b0 <_ZN12MTImageKitNS19CMTIKWakeSkinFilterC1Ev@plt>:
  52c4b0:      	adrp	x16, 0x54c000
  52c4b4:      	ldr	x17, [x16, #0x8c0]
  52c4b8:      	add	x16, x16, #0x8c0
  52c4bc:      	br	x17

000000000052c4c0 <_ZN12MTImageKitNS19CMTIKWakeSkinFilter23getBodyEffectCacheImageEbb@plt>:
  52c4c0:      	adrp	x16, 0x54c000
  52c4c4:      	ldr	x17, [x16, #0x8c8]
  52c4c8:      	add	x16, x16, #0x8c8
  52c4cc:      	br	x17

000000000052c4d0 <_ZN12NativeBitmap12removePixelsERiS0_@plt>:
  52c4d0:      	adrp	x16, 0x54c000
  52c4d4:      	ldr	x17, [x16, #0x8d0]
  52c4d8:      	add	x16, x16, #0x8d0
  52c4dc:      	br	x17

000000000052c4e0 <_ZN12MTImageKitNS5ImageC1EPhiiimbbNS_11ImageFormatE@plt>:
  52c4e0:      	adrp	x16, 0x54c000
  52c4e4:      	ldr	x17, [x16, #0x8d8]
  52c4e8:      	add	x16, x16, #0x8d8
  52c4ec:      	br	x17

000000000052c4f0 <fopen@plt>:
  52c4f0:      	adrp	x16, 0x54c000
  52c4f4:      	ldr	x17, [x16, #0x8e0]
  52c4f8:      	add	x16, x16, #0x8e0
  52c4fc:      	br	x17

000000000052c500 <fread@plt>:
  52c500:      	adrp	x16, 0x54c000
  52c504:      	ldr	x17, [x16, #0x8e8]
  52c508:      	add	x16, x16, #0x8e8
  52c50c:      	br	x17

000000000052c510 <malloc@plt>:
  52c510:      	adrp	x16, 0x54c000
  52c514:      	ldr	x17, [x16, #0x8f0]
  52c518:      	add	x16, x16, #0x8f0
  52c51c:      	br	x17

000000000052c520 <fclose@plt>:
  52c520:      	adrp	x16, 0x54c000
  52c524:      	ldr	x17, [x16, #0x8f8]
  52c528:      	add	x16, x16, #0x8f8
  52c52c:      	br	x17

000000000052c530 <_ZN12NativeBitmap9setPixelsEPhii14MTColorChannel@plt>:
  52c530:      	adrp	x16, 0x54c000
  52c534:      	ldr	x17, [x16, #0x900]
  52c538:      	add	x16, x16, #0x900
  52c53c:      	br	x17

000000000052c540 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
  52c540:      	adrp	x16, 0x54c000
  52c544:      	ldr	x17, [x16, #0x908]
  52c548:      	add	x16, x16, #0x908
  52c54c:      	br	x17

000000000052c550 <fmodf@plt>:
  52c550:      	adrp	x16, 0x54c000
  52c554:      	ldr	x17, [x16, #0x910]
  52c558:      	add	x16, x16, #0x910
  52c55c:      	br	x17

000000000052c560 <AndroidBitmap_getInfo@plt>:
  52c560:      	adrp	x16, 0x54c000
  52c564:      	ldr	x17, [x16, #0x918]
  52c568:      	add	x16, x16, #0x918
  52c56c:      	br	x17

000000000052c570 <_ZN12MTImageKitNS11Bitmap2BYTEEP7_JNIEnvP8_jobjectRiS4_bb@plt>:
  52c570:      	adrp	x16, 0x54c000
  52c574:      	ldr	x17, [x16, #0x920]
  52c578:      	add	x16, x16, #0x920
  52c57c:      	br	x17

000000000052c580 <_ZN12MTImageKitNS14ImageDiskCache13saveImageDataEPhiiNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEENS_16MTIKColorChannelE@plt>:
  52c580:      	adrp	x16, 0x54c000
  52c584:      	ldr	x17, [x16, #0x928]
  52c588:      	add	x16, x16, #0x928
  52c58c:      	br	x17

000000000052c590 <_ZN12MTImageKitNS15MTIKManagerTime15GetSystemTimeMSEv@plt>:
  52c590:      	adrp	x16, 0x54c000
  52c594:      	ldr	x17, [x16, #0x930]
  52c598:      	add	x16, x16, #0x930
  52c59c:      	br	x17

000000000052c5a0 <_ZN12MTImageKitNS14ImageDiskCache13imageFromPathERiS1_RKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERNS_16MTIKColorChannelEPhii@plt>:
  52c5a0:      	adrp	x16, 0x54c000
  52c5a4:      	ldr	x17, [x16, #0x938]
  52c5a8:      	add	x16, x16, #0x938
  52c5ac:      	br	x17

000000000052c5b0 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
  52c5b0:      	adrp	x16, 0x54c000
  52c5b4:      	ldr	x17, [x16, #0x940]
  52c5b8:      	add	x16, x16, #0x940
  52c5bc:      	br	x17

000000000052c5c0 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
  52c5c0:      	adrp	x16, 0x54c000
  52c5c4:      	ldr	x17, [x16, #0x948]
  52c5c8:      	add	x16, x16, #0x948
  52c5cc:      	br	x17

000000000052c5d0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
  52c5d0:      	adrp	x16, 0x54c000
  52c5d4:      	ldr	x17, [x16, #0x950]
  52c5d8:      	add	x16, x16, #0x950
  52c5dc:      	br	x17

000000000052c5e0 <vlai_check_package_name@plt>:
  52c5e0:      	adrp	x16, 0x54c000
  52c5e4:      	ldr	x17, [x16, #0x958]
  52c5e8:      	add	x16, x16, #0x958
  52c5ec:      	br	x17

000000000052c5f0 <_ZN12MTImageKitNS7Context9glContextEv@plt>:
  52c5f0:      	adrp	x16, 0x54c000
  52c5f4:      	ldr	x17, [x16, #0x960]
  52c5f8:      	add	x16, x16, #0x960
  52c5fc:      	br	x17

000000000052c600 <_ZNK12MTImageKitNS9GLContext9renderAPIEv@plt>:
  52c600:      	adrp	x16, 0x54c000
  52c604:      	ldr	x17, [x16, #0x968]
  52c608:      	add	x16, x16, #0x968
  52c60c:      	br	x17

000000000052c610 <_ZNK12MTImageKitNS17GLContext_Android10eglContextEv@plt>:
  52c610:      	adrp	x16, 0x54c000
  52c614:      	ldr	x17, [x16, #0x970]
  52c618:      	add	x16, x16, #0x970
  52c61c:      	br	x17

000000000052c620 <_ZN12MTImageKitNS7ContextC1EP7_JNIEnv@plt>:
  52c620:      	adrp	x16, 0x54c000
  52c624:      	ldr	x17, [x16, #0x978]
  52c628:      	add	x16, x16, #0x978
  52c62c:      	br	x17

000000000052c630 <_ZN12MTImageKitNS7Context14useShareObjectEPKv@plt>:
  52c630:      	adrp	x16, 0x54c000
  52c634:      	ldr	x17, [x16, #0x980]
  52c638:      	add	x16, x16, #0x980
  52c63c:      	br	x17

000000000052c640 <_ZN12MTImageKitNS7Context14setGLRenderAPIENS_11GLRenderAPIE@plt>:
  52c640:      	adrp	x16, 0x54c000
  52c644:      	ldr	x17, [x16, #0x988]
  52c648:      	add	x16, x16, #0x988
  52c64c:      	br	x17

000000000052c650 <_ZN12MTImageKitNS12CMTIKManagerC1Ev@plt>:
  52c650:      	adrp	x16, 0x54c000
  52c654:      	ldr	x17, [x16, #0x990]
  52c658:      	add	x16, x16, #0x990
  52c65c:      	br	x17

000000000052c660 <_ZN12MTImageKitNS12CMTIKManager17setPrivateContextEPNS_7ContextE@plt>:
  52c660:      	adrp	x16, 0x54c000
  52c664:      	ldr	x17, [x16, #0x998]
  52c668:      	add	x16, x16, #0x998
  52c66c:      	br	x17

000000000052c670 <_ZN12MTImageKitNS7Context11SetNoWindowEii@plt>:
  52c670:      	adrp	x16, 0x54c000
  52c674:      	ldr	x17, [x16, #0x9a0]
  52c678:      	add	x16, x16, #0x9a0
  52c67c:      	br	x17

000000000052c680 <_ZN12MTImageKitNS12CMTIKManagerD1Ev@plt>:
  52c680:      	adrp	x16, 0x54c000
  52c684:      	ldr	x17, [x16, #0x9a8]
  52c688:      	add	x16, x16, #0x9a8
  52c68c:      	br	x17

000000000052c690 <_ZN12MTImageKitNS12CMTIKManager10initializeEv@plt>:
  52c690:      	adrp	x16, 0x54c000
  52c694:      	ldr	x17, [x16, #0x9b0]
  52c698:      	add	x16, x16, #0x9b0
  52c69c:      	br	x17

000000000052c6a0 <_ZN12MTImageKitNS12CMTIKManager14initMTAiEngineEPKc@plt>:
  52c6a0:      	adrp	x16, 0x54c000
  52c6a4:      	ldr	x17, [x16, #0x9b8]
  52c6a8:      	add	x16, x16, #0x9b8
  52c6ac:      	br	x17

000000000052c6b0 <_ZN12MTImageKitNS12CMTIKManager22setArPublicParamsPlistENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52c6b0:      	adrp	x16, 0x54c000
  52c6b4:      	ldr	x17, [x16, #0x9c0]
  52c6b8:      	add	x16, x16, #0x9c0
  52c6bc:      	br	x17

000000000052c6c0 <_ZN12MTImageKitNS7Context20judgeInWhichContextsEb@plt>:
  52c6c0:      	adrp	x16, 0x54c000
  52c6c4:      	ldr	x17, [x16, #0x9c8]
  52c6c8:      	add	x16, x16, #0x9c8
  52c6cc:      	br	x17

000000000052c6d0 <_ZN12MTImageKitNS17CMTIKVideoManager23getLiveCoverFrameResultEv@plt>:
  52c6d0:      	adrp	x16, 0x54c000
  52c6d4:      	ldr	x17, [x16, #0x9d0]
  52c6d8:      	add	x16, x16, #0x9d0
  52c6dc:      	br	x17

000000000052c6e0 <_ZN12MTImageKitNS12CMTIKManager16getResultImageWHERiS1_@plt>:
  52c6e0:      	adrp	x16, 0x54c000
  52c6e4:      	ldr	x17, [x16, #0x9d8]
  52c6e8:      	add	x16, x16, #0x9d8
  52c6ec:      	br	x17

000000000052c6f0 <_ZN12MTImageKitNS12CMTIKManager25saveResultWithPixelBufferEiiPNS_5_Vec4IfEENS_5_Vec2IiEE@plt>:
  52c6f0:      	adrp	x16, 0x54c000
  52c6f4:      	ldr	x17, [x16, #0x9e0]
  52c6f8:      	add	x16, x16, #0x9e0
  52c6fc:      	br	x17

000000000052c700 <_ZN12MTImageKitNS12MTIKFileHelp18getSaveNameFromURLERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52c700:      	adrp	x16, 0x54c000
  52c704:      	ldr	x17, [x16, #0x9e8]
  52c708:      	add	x16, x16, #0x9e8
  52c70c:      	br	x17

000000000052c710 <_ZN12MTImageKitNS12MTIKFileHelp18getLastNameFromURLERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52c710:      	adrp	x16, 0x54c000
  52c714:      	ldr	x17, [x16, #0x9f0]
  52c718:      	add	x16, x16, #0x9f0
  52c71c:      	br	x17

000000000052c720 <strncmp@plt>:
  52c720:      	adrp	x16, 0x54c000
  52c724:      	ldr	x17, [x16, #0x9f8]
  52c728:      	add	x16, x16, #0x9f8
  52c72c:      	br	x17

000000000052c730 <_ZN12MTImageKitNS12MTIKFileHelp19findFirstSuffixFileERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_S8_@plt>:
  52c730:      	adrp	x16, 0x54c000
  52c734:      	ldr	x17, [x16, #0xa00]
  52c738:      	add	x16, x16, #0xa00
  52c73c:      	br	x17

000000000052c740 <_ZNSt6__ndk111this_thread9sleep_forERKNS_6chrono8durationIxNS_5ratioILl1ELl1000000000EEEEE@plt>:
  52c740:      	adrp	x16, 0x54c000
  52c744:      	ldr	x17, [x16, #0xa08]
  52c748:      	add	x16, x16, #0xa08
  52c74c:      	br	x17

000000000052c750 <_ZN12MTImageKitNS16CMTIKCurlProcess16downLoadMaterialEPKcS2_@plt>:
  52c750:      	adrp	x16, 0x54c000
  52c754:      	ldr	x17, [x16, #0xa10]
  52c758:      	add	x16, x16, #0xa10
  52c75c:      	br	x17

000000000052c760 <_ZN12MTImageKitNS12MTIKFileHelp9isZipFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  52c760:      	adrp	x16, 0x54c000
  52c764:      	ldr	x17, [x16, #0xa18]
  52c768:      	add	x16, x16, #0xa18
  52c76c:      	br	x17

000000000052c770 <_ZN12MTImageKitNS12CMTIKZipHelp9unzipFileEPKcS2_@plt>:
  52c770:      	adrp	x16, 0x54c000
  52c774:      	ldr	x17, [x16, #0xa20]
  52c778:      	add	x16, x16, #0xa20
  52c77c:      	br	x17

000000000052c780 <_ZNSt6__ndk14__fs10filesystem6__copyERKNS1_4pathES4_NS1_12copy_optionsEPNS_10error_codeE@plt>:
  52c780:      	adrp	x16, 0x54c000
  52c784:      	ldr	x17, [x16, #0xa28]
  52c788:      	add	x16, x16, #0xa28
  52c78c:      	br	x17

000000000052c790 <_ZNSt6__ndk14__fs10filesystem8__removeERKNS1_4pathEPNS_10error_codeE@plt>:
  52c790:      	adrp	x16, 0x54c000
  52c794:      	ldr	x17, [x16, #0xa30]
  52c798:      	add	x16, x16, #0xa30
  52c79c:      	br	x17

000000000052c7a0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKc@plt>:
  52c7a0:      	adrp	x16, 0x54c000
  52c7a4:      	ldr	x17, [x16, #0xa38]
  52c7a8:      	add	x16, x16, #0xa38
  52c7ac:      	br	x17

000000000052c7b0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter21cancelBackGroudRepairEb@plt>:
  52c7b0:      	adrp	x16, 0x54c000
  52c7b4:      	ldr	x17, [x16, #0xa40]
  52c7b8:      	add	x16, x16, #0xa40
  52c7bc:      	br	x17

000000000052c7c0 <_ZN12MTImageKitNS20CMTIKBodyShapeFilter16cancelBackGroundEv@plt>:
  52c7c0:      	adrp	x16, 0x54c000
  52c7c4:      	ldr	x17, [x16, #0xa48]
  52c7c8:      	add	x16, x16, #0xa48
  52c7cc:      	br	x17

000000000052c7d0 <_ZN12MTImageKitNS19CMTIKSlimFaceFilter22cancelBgProtectRequestEv@plt>:
  52c7d0:      	adrp	x16, 0x54c000
  52c7d4:      	ldr	x17, [x16, #0xa50]
  52c7d8:      	add	x16, x16, #0xa50
  52c7dc:      	br	x17

000000000052c7e0 <_ZN12MTImageKitNS22CMTIKFaceRemodelFilter20curingProcessTextureEi@plt>:
  52c7e0:      	adrp	x16, 0x54c000
  52c7e4:      	ldr	x17, [x16, #0xa58]
  52c7e8:      	add	x16, x16, #0xa58
  52c7ec:      	br	x17

000000000052c7f0 <AndroidBitmap_lockPixels@plt>:
  52c7f0:      	adrp	x16, 0x54c000
  52c7f4:      	ldr	x17, [x16, #0xa60]
  52c7f8:      	add	x16, x16, #0xa60
  52c7fc:      	br	x17

000000000052c800 <AndroidBitmap_unlockPixels@plt>:
  52c800:      	adrp	x16, 0x54c000
  52c804:      	ldr	x17, [x16, #0xa68]
  52c808:      	add	x16, x16, #0xa68
  52c80c:      	br	x17

000000000052c810 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
  52c810:      	adrp	x16, 0x54c000
  52c814:      	ldr	x17, [x16, #0xa70]
  52c818:      	add	x16, x16, #0xa70
  52c81c:      	br	x17

000000000052c820 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
  52c820:      	adrp	x16, 0x54c000
  52c824:      	ldr	x17, [x16, #0xa78]
  52c828:      	add	x16, x16, #0xa78
  52c82c:      	br	x17

000000000052c830 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
  52c830:      	adrp	x16, 0x54c000
  52c834:      	ldr	x17, [x16, #0xa80]
  52c838:      	add	x16, x16, #0xa80
  52c83c:      	br	x17

000000000052c840 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv@plt>:
  52c840:      	adrp	x16, 0x54c000
  52c844:      	ldr	x17, [x16, #0xa88]
  52c848:      	add	x16, x16, #0xa88
  52c84c:      	br	x17

000000000052c850 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
  52c850:      	adrp	x16, 0x54c000
  52c854:      	ldr	x17, [x16, #0xa90]
  52c858:      	add	x16, x16, #0xa90
  52c85c:      	br	x17

000000000052c860 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
  52c860:      	adrp	x16, 0x54c000
  52c864:      	ldr	x17, [x16, #0xa98]
  52c868:      	add	x16, x16, #0xa98
  52c86c:      	br	x17

000000000052c870 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
  52c870:      	adrp	x16, 0x54c000
  52c874:      	ldr	x17, [x16, #0xaa0]
  52c878:      	add	x16, x16, #0xaa0
  52c87c:      	br	x17

000000000052c880 <_ZN12MTImageKitNS8EXIFInfo9parseFromEPKhj@plt>:
  52c880:      	adrp	x16, 0x54c000
  52c884:      	ldr	x17, [x16, #0xaa8]
  52c888:      	add	x16, x16, #0xaa8
  52c88c:      	br	x17

000000000052c890 <_ZN12MTImageKitNS8EXIFInfo5clearEv@plt>:
  52c890:      	adrp	x16, 0x54c000
  52c894:      	ldr	x17, [x16, #0xab0]
  52c898:      	add	x16, x16, #0xab0
  52c89c:      	br	x17

000000000052c8a0 <vlai_engine_uninit@plt>:
  52c8a0:      	adrp	x16, 0x54c000
  52c8a4:      	ldr	x17, [x16, #0xab8]
  52c8a8:      	add	x16, x16, #0xab8
  52c8ac:      	br	x17

000000000052c8b0 <vlai_engine_destroy@plt>:
  52c8b0:      	adrp	x16, 0x54c000
  52c8b4:      	ldr	x17, [x16, #0xac0]
  52c8b8:      	add	x16, x16, #0xac0
  52c8bc:      	br	x17

000000000052c8c0 <vlai_setting_patch_destroy@plt>:
  52c8c0:      	adrp	x16, 0x54c000
  52c8c4:      	ldr	x17, [x16, #0xac8]
  52c8c8:      	add	x16, x16, #0xac8
  52c8cc:      	br	x17

000000000052c8d0 <vlai_engine_create@plt>:
  52c8d0:      	adrp	x16, 0x54c000
  52c8d4:      	ldr	x17, [x16, #0xad0]
  52c8d8:      	add	x16, x16, #0xad0
  52c8dc:      	br	x17

000000000052c8e0 <vlai_setting_patch_create@plt>:
  52c8e0:      	adrp	x16, 0x54c000
  52c8e4:      	ldr	x17, [x16, #0xad8]
  52c8e8:      	add	x16, x16, #0xad8
  52c8ec:      	br	x17

000000000052c8f0 <vlai_setting_patch_base_setting_patch@plt>:
  52c8f0:      	adrp	x16, 0x54c000
  52c8f4:      	ldr	x17, [x16, #0xae0]
  52c8f8:      	add	x16, x16, #0xae0
  52c8fc:      	br	x17

000000000052c900 <vlai_base_setting_patch_set_thread_mode@plt>:
  52c900:      	adrp	x16, 0x54c000
  52c904:      	ldr	x17, [x16, #0xae8]
  52c908:      	add	x16, x16, #0xae8
  52c90c:      	br	x17

000000000052c910 <vlai_base_setting_patch_set_thread_max@plt>:
  52c910:      	adrp	x16, 0x54c000
  52c914:      	ldr	x17, [x16, #0xaf0]
  52c918:      	add	x16, x16, #0xaf0
  52c91c:      	br	x17

000000000052c920 <vlai_base_setting_patch_set_run_mode@plt>:
  52c920:      	adrp	x16, 0x54c000
  52c924:      	ldr	x17, [x16, #0xaf8]
  52c928:      	add	x16, x16, #0xaf8
  52c92c:      	br	x17

000000000052c930 <stat@plt>:
  52c930:      	adrp	x16, 0x54c000
  52c934:      	ldr	x17, [x16, #0xb00]
  52c938:      	add	x16, x16, #0xb00
  52c93c:      	br	x17

000000000052c940 <vlai_setting_patch_model_setting_patch@plt>:
  52c940:      	adrp	x16, 0x54c000
  52c944:      	ldr	x17, [x16, #0xb08]
  52c948:      	add	x16, x16, #0xb08
  52c94c:      	br	x17

000000000052c950 <vlai_model_setting_patch_set_directory@plt>:
  52c950:      	adrp	x16, 0x54c000
  52c954:      	ldr	x17, [x16, #0xb10]
  52c958:      	add	x16, x16, #0xb10
  52c95c:      	br	x17

000000000052c960 <vlai_engine_init@plt>:
  52c960:      	adrp	x16, 0x54c000
  52c964:      	ldr	x17, [x16, #0xb18]
  52c968:      	add	x16, x16, #0xb18
  52c96c:      	br	x17

000000000052c970 <vlai_require_set_create@plt>:
  52c970:      	adrp	x16, 0x54c000
  52c974:      	ldr	x17, [x16, #0xb20]
  52c978:      	add	x16, x16, #0xb20
  52c97c:      	br	x17

000000000052c980 <vlai_require_set_push@plt>:
  52c980:      	adrp	x16, 0x54c000
  52c984:      	ldr	x17, [x16, #0xb28]
  52c988:      	add	x16, x16, #0xb28
  52c98c:      	br	x17

000000000052c990 <vlai_run_result_make_null@plt>:
  52c990:      	adrp	x16, 0x54c000
  52c994:      	ldr	x17, [x16, #0xb30]
  52c998:      	add	x16, x16, #0xb30
  52c99c:      	br	x17

000000000052c9a0 <vlai_engine_preload_with_setting@plt>:
  52c9a0:      	adrp	x16, 0x54c000
  52c9a4:      	ldr	x17, [x16, #0xb38]
  52c9a8:      	add	x16, x16, #0xb38
  52c9ac:      	br	x17

000000000052c9b0 <vlai_require_set_destroy@plt>:
  52c9b0:      	adrp	x16, 0x54c000
  52c9b4:      	ldr	x17, [x16, #0xb40]
  52c9b8:      	add	x16, x16, #0xb40
  52c9bc:      	br	x17

000000000052c9c0 <vldp_create_image_ref@plt>:
  52c9c0:      	adrp	x16, 0x54c000
  52c9c4:      	ldr	x17, [x16, #0xb48]
  52c9c8:      	add	x16, x16, #0xb48
  52c9cc:      	br	x17

000000000052c9d0 <vldp_image_valid@plt>:
  52c9d0:      	adrp	x16, 0x54c000
  52c9d4:      	ldr	x17, [x16, #0xb50]
  52c9d8:      	add	x16, x16, #0xb50
  52c9dc:      	br	x17

000000000052c9e0 <vlai_frame_create@plt>:
  52c9e0:      	adrp	x16, 0x54c000
  52c9e4:      	ldr	x17, [x16, #0xb58]
  52c9e8:      	add	x16, x16, #0xb58
  52c9ec:      	br	x17

000000000052c9f0 <vlai_frame_ref_color_image@plt>:
  52c9f0:      	adrp	x16, 0x54c000
  52c9f4:      	ldr	x17, [x16, #0xb60]
  52c9f8:      	add	x16, x16, #0xb60
  52c9fc:      	br	x17

000000000052ca00 <vlai_frame_set_first_frame@plt>:
  52ca00:      	adrp	x16, 0x54c000
  52ca04:      	ldr	x17, [x16, #0xb68]
  52ca08:      	add	x16, x16, #0xb68
  52ca0c:      	br	x17

000000000052ca10 <vlai_run_result_create@plt>:
  52ca10:      	adrp	x16, 0x54c000
  52ca14:      	ldr	x17, [x16, #0xb70]
  52ca18:      	add	x16, x16, #0xb70
  52ca1c:      	br	x17

000000000052ca20 <vlai_engine_runtime_setting@plt>:
  52ca20:      	adrp	x16, 0x54c000
  52ca24:      	ldr	x17, [x16, #0xb78]
  52ca28:      	add	x16, x16, #0xb78
  52ca2c:      	br	x17

000000000052ca30 <vlai_engine_apply_runtime_setting@plt>:
  52ca30:      	adrp	x16, 0x54c000
  52ca34:      	ldr	x17, [x16, #0xb80]
  52ca38:      	add	x16, x16, #0xb80
  52ca3c:      	br	x17

000000000052ca40 <vlai_engine_run@plt>:
  52ca40:      	adrp	x16, 0x54c000
  52ca44:      	ldr	x17, [x16, #0xb88]
  52ca48:      	add	x16, x16, #0xb88
  52ca4c:      	br	x17

000000000052ca50 <vlai_run_result_destroy@plt>:
  52ca50:      	adrp	x16, 0x54c000
  52ca54:      	ldr	x17, [x16, #0xb90]
  52ca58:      	add	x16, x16, #0xb90
  52ca5c:      	br	x17

000000000052ca60 <vlai_setting_patch_face_setting_patch@plt>:
  52ca60:      	adrp	x16, 0x54c000
  52ca64:      	ldr	x17, [x16, #0xb98]
  52ca68:      	add	x16, x16, #0xb98
  52ca6c:      	br	x17

000000000052ca70 <vlai_face_setting_patch_set_enable_fd@plt>:
  52ca70:      	adrp	x16, 0x54c000
  52ca74:      	ldr	x17, [x16, #0xba0]
  52ca78:      	add	x16, x16, #0xba0
  52ca7c:      	br	x17

000000000052ca80 <vlai_face_setting_patch_set_enable_fa@plt>:
  52ca80:      	adrp	x16, 0x54c000
  52ca84:      	ldr	x17, [x16, #0xba8]
  52ca88:      	add	x16, x16, #0xba8
  52ca8c:      	br	x17

000000000052ca90 <vlai_face_setting_patch_set_fd_quality@plt>:
  52ca90:      	adrp	x16, 0x54c000
  52ca94:      	ldr	x17, [x16, #0xbb0]
  52ca98:      	add	x16, x16, #0xbb0
  52ca9c:      	br	x17

000000000052caa0 <vlai_face_setting_patch_set_fa_quality@plt>:
  52caa0:      	adrp	x16, 0x54c000
  52caa4:      	ldr	x17, [x16, #0xbb8]
  52caa8:      	add	x16, x16, #0xbb8
  52caac:      	br	x17

000000000052cab0 <vldp_release_image@plt>:
  52cab0:      	adrp	x16, 0x54c000
  52cab4:      	ldr	x17, [x16, #0xbc0]
  52cab8:      	add	x16, x16, #0xbc0
  52cabc:      	br	x17

000000000052cac0 <vlai_run_result_get_data_protocol@plt>:
  52cac0:      	adrp	x16, 0x54c000
  52cac4:      	ldr	x17, [x16, #0xbc8]
  52cac8:      	add	x16, x16, #0xbc8
  52cacc:      	br	x17

000000000052cad0 <vldp_get_data_protocol_image_recognition_result@plt>:
  52cad0:      	adrp	x16, 0x54c000
  52cad4:      	ldr	x17, [x16, #0xbd0]
  52cad8:      	add	x16, x16, #0xbd0
  52cadc:      	br	x17

000000000052cae0 <vldp_get_image_recognition_result_pointer_ref@plt>:
  52cae0:      	adrp	x16, 0x54c000
  52cae4:      	ldr	x17, [x16, #0xbd8]
  52cae8:      	add	x16, x16, #0xbd8
  52caec:      	br	x17

000000000052caf0 <vldp_get_image_recognition_result_second_level_recognitions@plt>:
  52caf0:      	adrp	x16, 0x54c000
  52caf4:      	ldr	x17, [x16, #0xbe0]
  52caf8:      	add	x16, x16, #0xbe0
  52cafc:      	br	x17

000000000052cb00 <vldp_get_image_recognition_array_pointer_size@plt>:
  52cb00:      	adrp	x16, 0x54c000
  52cb04:      	ldr	x17, [x16, #0xbe8]
  52cb08:      	add	x16, x16, #0xbe8
  52cb0c:      	br	x17

000000000052cb10 <vldp_get_image_recognition_array_pointer_at@plt>:
  52cb10:      	adrp	x16, 0x54c000
  52cb14:      	ldr	x17, [x16, #0xbf0]
  52cb18:      	add	x16, x16, #0xbf0
  52cb1c:      	br	x17

000000000052cb20 <vldp_get_image_recognition_has_category@plt>:
  52cb20:      	adrp	x16, 0x54c000
  52cb24:      	ldr	x17, [x16, #0xbf8]
  52cb28:      	add	x16, x16, #0xbf8
  52cb2c:      	br	x17

000000000052cb30 <vldp_get_image_recognition_category@plt>:
  52cb30:      	adrp	x16, 0x54c000
  52cb34:      	ldr	x17, [x16, #0xc00]
  52cb38:      	add	x16, x16, #0xc00
  52cb3c:      	br	x17

000000000052cb40 <vldp_get_image_recognition_score@plt>:
  52cb40:      	adrp	x16, 0x54c000
  52cb44:      	ldr	x17, [x16, #0xc08]
  52cb48:      	add	x16, x16, #0xc08
  52cb4c:      	br	x17

000000000052cb50 <vlai_runtime_setting_face_runtime_setting@plt>:
  52cb50:      	adrp	x16, 0x54c000
  52cb54:      	ldr	x17, [x16, #0xc10]
  52cb58:      	add	x16, x16, #0xc10
  52cb5c:      	br	x17

000000000052cb60 <vlai_face_runtime_setting_set_face_max_num@plt>:
  52cb60:      	adrp	x16, 0x54c000
  52cb64:      	ldr	x17, [x16, #0xc18]
  52cb68:      	add	x16, x16, #0xc18
  52cb6c:      	br	x17

000000000052cb70 <vlai_face_runtime_setting_set_minimal_face@plt>:
  52cb70:      	adrp	x16, 0x54c000
  52cb74:      	ldr	x17, [x16, #0xc20]
  52cb78:      	add	x16, x16, #0xc20
  52cb7c:      	br	x17

000000000052cb80 <vlai_face_runtime_setting_set_enable_force_require@plt>:
  52cb80:      	adrp	x16, 0x54c000
  52cb84:      	ldr	x17, [x16, #0xc28]
  52cb88:      	add	x16, x16, #0xc28
  52cb8c:      	br	x17

000000000052cb90 <vlai_engine_unload_require@plt>:
  52cb90:      	adrp	x16, 0x54c000
  52cb94:      	ldr	x17, [x16, #0xc30]
  52cb98:      	add	x16, x16, #0xc30
  52cb9c:      	br	x17

000000000052cba0 <vldp_get_image_recognition_result_third_level_recognitions@plt>:
  52cba0:      	adrp	x16, 0x54c000
  52cba4:      	ldr	x17, [x16, #0xc38]
  52cba8:      	add	x16, x16, #0xc38
  52cbac:      	br	x17

000000000052cbb0 <vlai_recognition_get_first_level@plt>:
  52cbb0:      	adrp	x16, 0x54c000
  52cbb4:      	ldr	x17, [x16, #0xc40]
  52cbb8:      	add	x16, x16, #0xc40
  52cbbc:      	br	x17

000000000052cbc0 <vlai_recognition_get_second_level@plt>:
  52cbc0:      	adrp	x16, 0x54c000
  52cbc4:      	ldr	x17, [x16, #0xc48]
  52cbc8:      	add	x16, x16, #0xc48
  52cbcc:      	br	x17

000000000052cbd0 <vlai_recognition_get_label@plt>:
  52cbd0:      	adrp	x16, 0x54c000
  52cbd4:      	ldr	x17, [x16, #0xc50]
  52cbd8:      	add	x16, x16, #0xc50
  52cbdc:      	br	x17

000000000052cbe0 <vldp_get_image_recognition_result_embeding@plt>:
  52cbe0:      	adrp	x16, 0x54c000
  52cbe4:      	ldr	x17, [x16, #0xc58]
  52cbe8:      	add	x16, x16, #0xc58
  52cbec:      	br	x17

000000000052cbf0 <vldp_get_float_array_pointer_ref@plt>:
  52cbf0:      	adrp	x16, 0x54c000
  52cbf4:      	ldr	x17, [x16, #0xc60]
  52cbf8:      	add	x16, x16, #0xc60
  52cbfc:      	br	x17

000000000052cc00 <vldp_get_float_array_pointer_size@plt>:
  52cc00:      	adrp	x16, 0x54c000
  52cc04:      	ldr	x17, [x16, #0xc68]
  52cc08:      	add	x16, x16, #0xc68
  52cc0c:      	br	x17

000000000052cc10 <vldp_get_image_recognition_result_pregnant_woman@plt>:
  52cc10:      	adrp	x16, 0x54c000
  52cc14:      	ldr	x17, [x16, #0xc70]
  52cc18:      	add	x16, x16, #0xc70
  52cc1c:      	br	x17

000000000052cc20 <vldp_get_data_protocol_face_result@plt>:
  52cc20:      	adrp	x16, 0x54c000
  52cc24:      	ldr	x17, [x16, #0xc78]
  52cc28:      	add	x16, x16, #0xc78
  52cc2c:      	br	x17

000000000052cc30 <vldp_get_face_result_pointer_ref@plt>:
  52cc30:      	adrp	x16, 0x54c000
  52cc34:      	ldr	x17, [x16, #0xc80]
  52cc38:      	add	x16, x16, #0xc80
  52cc3c:      	br	x17

000000000052cc40 <vldp_get_face_result_faces@plt>:
  52cc40:      	adrp	x16, 0x54c000
  52cc44:      	ldr	x17, [x16, #0xc88]
  52cc48:      	add	x16, x16, #0xc88
  52cc4c:      	br	x17

000000000052cc50 <vldp_get_face_array_pointer_size@plt>:
  52cc50:      	adrp	x16, 0x54c000
  52cc54:      	ldr	x17, [x16, #0xc90]
  52cc58:      	add	x16, x16, #0xc90
  52cc5c:      	br	x17

000000000052cc60 <vldp_get_face_array_pointer_at@plt>:
  52cc60:      	adrp	x16, 0x54c000
  52cc64:      	ldr	x17, [x16, #0xc98]
  52cc68:      	add	x16, x16, #0xc98
  52cc6c:      	br	x17

000000000052cc70 <vldp_get_face_has_id@plt>:
  52cc70:      	adrp	x16, 0x54c000
  52cc74:      	ldr	x17, [x16, #0xca0]
  52cc78:      	add	x16, x16, #0xca0
  52cc7c:      	br	x17

000000000052cc80 <vldp_get_face_id@plt>:
  52cc80:      	adrp	x16, 0x54c000
  52cc84:      	ldr	x17, [x16, #0xca8]
  52cc88:      	add	x16, x16, #0xca8
  52cc8c:      	br	x17

000000000052cc90 <vldp_get_face_has_age@plt>:
  52cc90:      	adrp	x16, 0x54c000
  52cc94:      	ldr	x17, [x16, #0xcb0]
  52cc98:      	add	x16, x16, #0xcb0
  52cc9c:      	br	x17

000000000052cca0 <vldp_get_face_age@plt>:
  52cca0:      	adrp	x16, 0x54c000
  52cca4:      	ldr	x17, [x16, #0xcb8]
  52cca8:      	add	x16, x16, #0xcb8
  52ccac:      	br	x17

000000000052ccb0 <vldp_get_face_has_gender@plt>:
  52ccb0:      	adrp	x16, 0x54c000
  52ccb4:      	ldr	x17, [x16, #0xcc0]
  52ccb8:      	add	x16, x16, #0xcc0
  52ccbc:      	br	x17

000000000052ccc0 <vldp_get_face_gender@plt>:
  52ccc0:      	adrp	x16, 0x54c000
  52ccc4:      	ldr	x17, [x16, #0xcc8]
  52ccc8:      	add	x16, x16, #0xcc8
  52cccc:      	br	x17

000000000052ccd0 <vldp_get_face_has_race@plt>:
  52ccd0:      	adrp	x16, 0x54c000
  52ccd4:      	ldr	x17, [x16, #0xcd0]
  52ccd8:      	add	x16, x16, #0xcd0
  52ccdc:      	br	x17

000000000052cce0 <vldp_get_face_race@plt>:
  52cce0:      	adrp	x16, 0x54c000
  52cce4:      	ldr	x17, [x16, #0xcd8]
  52cce8:      	add	x16, x16, #0xcd8
  52ccec:      	br	x17

000000000052ccf0 <vldp_get_face_has_face_rect@plt>:
  52ccf0:      	adrp	x16, 0x54c000
  52ccf4:      	ldr	x17, [x16, #0xce0]
  52ccf8:      	add	x16, x16, #0xce0
  52ccfc:      	br	x17

000000000052cd00 <vldp_get_face_face_rect@plt>:
  52cd00:      	adrp	x16, 0x54c000
  52cd04:      	ldr	x17, [x16, #0xce8]
  52cd08:      	add	x16, x16, #0xce8
  52cd0c:      	br	x17

000000000052cd10 <vlai_frame_destroy@plt>:
  52cd10:      	adrp	x16, 0x54c000
  52cd14:      	ldr	x17, [x16, #0xcf0]
  52cd18:      	add	x16, x16, #0xcf0
  52cd1c:      	br	x17

000000000052cd20 <_ZNK12MTImageKitNS5Image11bytesPerRowEv@plt>:
  52cd20:      	adrp	x16, 0x54c000
  52cd24:      	ldr	x17, [x16, #0xcf8]
  52cd28:      	add	x16, x16, #0xcf8
  52cd2c:      	br	x17

000000000052cd30 <_ZNSt6__ndk17promiseIvED1Ev@plt>:
  52cd30:      	adrp	x16, 0x54c000
  52cd34:      	ldr	x17, [x16, #0xd00]
  52cd38:      	add	x16, x16, #0xd00
  52cd3c:      	br	x17

000000000052cd40 <_ZNSt13exception_ptrD1Ev@plt>:
  52cd40:      	adrp	x16, 0x54c000
  52cd44:      	ldr	x17, [x16, #0xd08]
  52cd48:      	add	x16, x16, #0xd08
  52cd4c:      	br	x17

000000000052cd50 <_ZNSt6__ndk112future_errorC1ENS_10error_codeE@plt>:
  52cd50:      	adrp	x16, 0x54c000
  52cd54:      	ldr	x17, [x16, #0xd10]
  52cd58:      	add	x16, x16, #0xd10
  52cd5c:      	br	x17

000000000052cd60 <_ZNSt6__ndk115future_categoryEv@plt>:
  52cd60:      	adrp	x16, 0x54c000
  52cd64:      	ldr	x17, [x16, #0xd18]
  52cd68:      	add	x16, x16, #0xd18
  52cd6c:      	br	x17

000000000052cd70 <_ZNSt6__ndk18ios_baseD2Ev@plt>:
  52cd70:      	adrp	x16, 0x54c000
  52cd74:      	ldr	x17, [x16, #0xd20]
  52cd78:      	add	x16, x16, #0xd20
  52cd7c:      	br	x17

000000000052cd80 <_ZSt18uncaught_exceptionv@plt>:
  52cd80:      	adrp	x16, 0x54c000
  52cd84:      	ldr	x17, [x16, #0xd28]
  52cd88:      	add	x16, x16, #0xd28
  52cd8c:      	br	x17

000000000052cd90 <fflush@plt>:
  52cd90:      	adrp	x16, 0x54c000
  52cd94:      	ldr	x17, [x16, #0xd30]
  52cd98:      	add	x16, x16, #0xd30
  52cd9c:      	br	x17

000000000052cda0 <strcmp@plt>:
  52cda0:      	adrp	x16, 0x54c000
  52cda4:      	ldr	x17, [x16, #0xd38]
  52cda8:      	add	x16, x16, #0xd38
  52cdac:      	br	x17

000000000052cdb0 <posix_memalign@plt>:
  52cdb0:      	adrp	x16, 0x54c000
  52cdb4:      	ldr	x17, [x16, #0xd40]
  52cdb8:      	add	x16, x16, #0xd40
  52cdbc:      	br	x17

000000000052cdc0 <__vsprintf_chk@plt>:
  52cdc0:      	adrp	x16, 0x54c000
  52cdc4:      	ldr	x17, [x16, #0xd48]
  52cdc8:      	add	x16, x16, #0xd48
  52cdcc:      	br	x17

000000000052cdd0 <strstr@plt>:
  52cdd0:      	adrp	x16, 0x54c000
  52cdd4:      	ldr	x17, [x16, #0xd50]
  52cdd8:      	add	x16, x16, #0xd50
  52cddc:      	br	x17

000000000052cde0 <__memset_chk@plt>:
  52cde0:      	adrp	x16, 0x54c000
  52cde4:      	ldr	x17, [x16, #0xd58]
  52cde8:      	add	x16, x16, #0xd58
  52cdec:      	br	x17

000000000052cdf0 <__strchr_chk@plt>:
  52cdf0:      	adrp	x16, 0x54c000
  52cdf4:      	ldr	x17, [x16, #0xd60]
  52cdf8:      	add	x16, x16, #0xd60
  52cdfc:      	br	x17

000000000052ce00 <fputs@plt>:
  52ce00:      	adrp	x16, 0x54c000
  52ce04:      	ldr	x17, [x16, #0xd68]
  52ce08:      	add	x16, x16, #0xd68
  52ce0c:      	br	x17

000000000052ce10 <gzputs@plt>:
  52ce10:      	adrp	x16, 0x54c000
  52ce14:      	ldr	x17, [x16, #0xd70]
  52ce18:      	add	x16, x16, #0xd70
  52ce1c:      	br	x17

000000000052ce20 <strcpy@plt>:
  52ce20:      	adrp	x16, 0x54c000
  52ce24:      	ldr	x17, [x16, #0xd78]
  52ce28:      	add	x16, x16, #0xd78
  52ce2c:      	br	x17

000000000052ce30 <strtol@plt>:
  52ce30:      	adrp	x16, 0x54c000
  52ce34:      	ldr	x17, [x16, #0xd80]
  52ce38:      	add	x16, x16, #0xd80
  52ce3c:      	br	x17

000000000052ce40 <__strcat_chk@plt>:
  52ce40:      	adrp	x16, 0x54c000
  52ce44:      	ldr	x17, [x16, #0xd88]
  52ce48:      	add	x16, x16, #0xd88
  52ce4c:      	br	x17

000000000052ce50 <isxdigit@plt>:
  52ce50:      	adrp	x16, 0x54c000
  52ce54:      	ldr	x17, [x16, #0xd90]
  52ce58:      	add	x16, x16, #0xd90
  52ce5c:      	br	x17

000000000052ce60 <atoi@plt>:
  52ce60:      	adrp	x16, 0x54c000
  52ce64:      	ldr	x17, [x16, #0xd98]
  52ce68:      	add	x16, x16, #0xd98
  52ce6c:      	br	x17

000000000052ce70 <fprintf@plt>:
  52ce70:      	adrp	x16, 0x54c000
  52ce74:      	ldr	x17, [x16, #0xda0]
  52ce78:      	add	x16, x16, #0xda0
  52ce7c:      	br	x17

000000000052ce80 <getenv@plt>:
  52ce80:      	adrp	x16, 0x54c000
  52ce84:      	ldr	x17, [x16, #0xda8]
  52ce88:      	add	x16, x16, #0xda8
  52ce8c:      	br	x17

000000000052ce90 <pthread_getspecific@plt>:
  52ce90:      	adrp	x16, 0x54c000
  52ce94:      	ldr	x17, [x16, #0xdb0]
  52ce98:      	add	x16, x16, #0xdb0
  52ce9c:      	br	x17

000000000052cea0 <pthread_key_create@plt>:
  52cea0:      	adrp	x16, 0x54c000
  52cea4:      	ldr	x17, [x16, #0xdb8]
  52cea8:      	add	x16, x16, #0xdb8
  52ceac:      	br	x17

000000000052ceb0 <pthread_key_delete@plt>:
  52ceb0:      	adrp	x16, 0x54c000
  52ceb4:      	ldr	x17, [x16, #0xdc0]
  52ceb8:      	add	x16, x16, #0xdc0
  52cebc:      	br	x17

000000000052cec0 <pthread_mutex_destroy@plt>:
  52cec0:      	adrp	x16, 0x54c000
  52cec4:      	ldr	x17, [x16, #0xdc8]
  52cec8:      	add	x16, x16, #0xdc8
  52cecc:      	br	x17

000000000052ced0 <pthread_mutex_init@plt>:
  52ced0:      	adrp	x16, 0x54c000
  52ced4:      	ldr	x17, [x16, #0xdd0]
  52ced8:      	add	x16, x16, #0xdd0
  52cedc:      	br	x17

000000000052cee0 <pthread_mutex_lock@plt>:
  52cee0:      	adrp	x16, 0x54c000
  52cee4:      	ldr	x17, [x16, #0xdd8]
  52cee8:      	add	x16, x16, #0xdd8
  52ceec:      	br	x17

000000000052cef0 <pthread_mutex_unlock@plt>:
  52cef0:      	adrp	x16, 0x54c000
  52cef4:      	ldr	x17, [x16, #0xde0]
  52cef8:      	add	x16, x16, #0xde0
  52cefc:      	br	x17

000000000052cf00 <pthread_mutexattr_destroy@plt>:
  52cf00:      	adrp	x16, 0x54c000
  52cf04:      	ldr	x17, [x16, #0xde8]
  52cf08:      	add	x16, x16, #0xde8
  52cf0c:      	br	x17

000000000052cf10 <pthread_mutexattr_init@plt>:
  52cf10:      	adrp	x16, 0x54c000
  52cf14:      	ldr	x17, [x16, #0xdf0]
  52cf18:      	add	x16, x16, #0xdf0
  52cf1c:      	br	x17

000000000052cf20 <pthread_mutexattr_settype@plt>:
  52cf20:      	adrp	x16, 0x54c000
  52cf24:      	ldr	x17, [x16, #0xdf8]
  52cf28:      	add	x16, x16, #0xdf8
  52cf2c:      	br	x17

000000000052cf30 <pthread_setspecific@plt>:
  52cf30:      	adrp	x16, 0x54c000
  52cf34:      	ldr	x17, [x16, #0xe00]
  52cf38:      	add	x16, x16, #0xe00
  52cf3c:      	br	x17

000000000052cf40 <vsnprintf@plt>:
  52cf40:      	adrp	x16, 0x54c000
  52cf44:      	ldr	x17, [x16, #0xe08]
  52cf48:      	add	x16, x16, #0xe08
  52cf4c:      	br	x17

000000000052cf50 <_ZNSt11logic_errorC2ERKS_@plt>:
  52cf50:      	adrp	x16, 0x54c000
  52cf54:      	ldr	x17, [x16, #0xe10]
  52cf58:      	add	x16, x16, #0xe10
  52cf5c:      	br	x17

000000000052cf60 <_ZNSt6__ndk112future_errorD1Ev@plt>:
  52cf60:      	adrp	x16, 0x54c000
  52cf64:      	ldr	x17, [x16, #0xe18]
  52cf68:      	add	x16, x16, #0xe18
  52cf6c:      	br	x17

000000000052cf70 <_ZSt17current_exceptionv@plt>:
  52cf70:      	adrp	x16, 0x54c000
  52cf74:      	ldr	x17, [x16, #0xe20]
  52cf78:      	add	x16, x16, #0xe20
  52cf7c:      	br	x17

000000000052cf80 <_ZNSt6__ndk117__assoc_sub_state13set_exceptionESt13exception_ptr@plt>:
  52cf80:      	adrp	x16, 0x54c000
  52cf84:      	ldr	x17, [x16, #0xe28]
  52cf88:      	add	x16, x16, #0xe28
  52cf8c:      	br	x17

000000000052cf90 <fwrite@plt>:
  52cf90:      	adrp	x16, 0x54c000
  52cf94:      	ldr	x17, [x16, #0xe30]
  52cf98:      	add	x16, x16, #0xe30
  52cf9c:      	br	x17

000000000052cfa0 <gettimeofday@plt>:
  52cfa0:      	adrp	x16, 0x54c000
  52cfa4:      	ldr	x17, [x16, #0xe38]
  52cfa8:      	add	x16, x16, #0xe38
  52cfac:      	br	x17

000000000052cfb0 <getauxval@plt>:
  52cfb0:      	adrp	x16, 0x54c000
  52cfb4:      	ldr	x17, [x16, #0xe40]
  52cfb8:      	add	x16, x16, #0xe40
  52cfbc:      	br	x17

000000000052cfc0 <__system_property_get@plt>:
  52cfc0:      	adrp	x16, 0x54c000
  52cfc4:      	ldr	x17, [x16, #0xe48]
  52cfc8:      	add	x16, x16, #0xe48
  52cfcc:      	br	x17

000000000052cfd0 <abort@plt>:
  52cfd0:      	adrp	x16, 0x54c000
  52cfd4:      	ldr	x17, [x16, #0xe50]
  52cfd8:      	add	x16, x16, #0xe50
  52cfdc:      	br	x17

000000000052cfe0 <pthread_rwlock_wrlock@plt>:
  52cfe0:      	adrp	x16, 0x54c000
  52cfe4:      	ldr	x17, [x16, #0xe58]
  52cfe8:      	add	x16, x16, #0xe58
  52cfec:      	br	x17

000000000052cff0 <pthread_rwlock_unlock@plt>:
  52cff0:      	adrp	x16, 0x54c000
  52cff4:      	ldr	x17, [x16, #0xe60]
  52cff8:      	add	x16, x16, #0xe60
  52cffc:      	br	x17

000000000052d000 <dl_iterate_phdr@plt>:
  52d000:      	adrp	x16, 0x54c000
  52d004:      	ldr	x17, [x16, #0xe68]
  52d008:      	add	x16, x16, #0xe68
  52d00c:      	br	x17

000000000052d010 <pthread_rwlock_rdlock@plt>:
  52d010:      	adrp	x16, 0x54c000
  52d014:      	ldr	x17, [x16, #0xe70]
  52d018:      	add	x16, x16, #0xe70
  52d01c:      	br	x17

000000000052d020 <getpid@plt>:
  52d020:      	adrp	x16, 0x54c000
  52d024:      	ldr	x17, [x16, #0xe78]
  52d028:      	add	x16, x16, #0xe78
  52d02c:      	br	x17

000000000052d030 <syscall@plt>:
  52d030:      	adrp	x16, 0x54c000
  52d034:      	ldr	x17, [x16, #0xe80]
  52d038:      	add	x16, x16, #0xe80
  52d03c:      	br	x17
