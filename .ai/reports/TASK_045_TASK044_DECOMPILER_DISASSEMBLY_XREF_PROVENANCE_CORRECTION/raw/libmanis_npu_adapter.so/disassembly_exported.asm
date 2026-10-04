// EXPORTED & PLT DISASSEMBLY FOR libmanis_npu_adapter.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libmanis_npu_adapter.so (SHA-256: 99A9A4B161B9797D7CF621E93A51A7DF408F80C84E652BBC6724EEF7E71CA6F3)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 1891, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libmanis_npu_adapter.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000000ef130 <.plt>:
   ef130:      	stp	x16, x30, [sp, #-0x10]!
   ef134:      	adrp	x16, 0xfb000
   ef138:      	ldr	x17, [x16, #0xc28]
   ef13c:      	add	x16, x16, #0xc28
   ef140:      	br	x17
   ef144:      	nop
   ef148:      	nop
   ef14c:      	nop

00000000000ef150 <__cxa_finalize@plt>:
   ef150:      	adrp	x16, 0xfb000
   ef154:      	ldr	x17, [x16, #0xc30]
   ef158:      	add	x16, x16, #0xc30
   ef15c:      	br	x17

00000000000ef160 <__cxa_atexit@plt>:
   ef160:      	adrp	x16, 0xfb000
   ef164:      	ldr	x17, [x16, #0xc38]
   ef168:      	add	x16, x16, #0xc38
   ef16c:      	br	x17

00000000000ef170 <_Znwm@plt>:
   ef170:      	adrp	x16, 0xfb000
   ef174:      	ldr	x17, [x16, #0xc40]
   ef178:      	add	x16, x16, #0xc40
   ef17c:      	br	x17

00000000000ef180 <memmove@plt>:
   ef180:      	adrp	x16, 0xfb000
   ef184:      	ldr	x17, [x16, #0xc48]
   ef188:      	add	x16, x16, #0xc48
   ef18c:      	br	x17

00000000000ef190 <_ZN4hiai2op5ConstC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef190:      	adrp	x16, 0xfb000
   ef194:      	ldr	x17, [x16, #0xc50]
   ef198:      	add	x16, x16, #0xc50
   ef19c:      	br	x17

00000000000ef1a0 <_ZdlPv@plt>:
   ef1a0:      	adrp	x16, 0xfb000
   ef1a4:      	ldr	x17, [x16, #0xc58]
   ef1a8:      	add	x16, x16, #0xc58
   ef1ac:      	br	x17

00000000000ef1b0 <_ZN5mizar8NpuUtils12SetAttrValueIiEEvRNSt6__ndk110shared_ptrIN4hiai2op5ConstEEENS2_6vectorIT_NS2_9allocatorISA_EEEEN2ge6FormatENSE_8DataTypeEb@plt>:
   ef1b0:      	adrp	x16, 0xfb000
   ef1b4:      	ldr	x17, [x16, #0xc60]
   ef1b8:      	add	x16, x16, #0xc60
   ef1bc:      	br	x17

00000000000ef1c0 <_ZNSt6__ndk16vectorINS_10shared_ptrIN2ge8OperatorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIS4_EEPS4_OT_@plt>:
   ef1c0:      	adrp	x16, 0xfb000
   ef1c4:      	ldr	x17, [x16, #0xc68]
   ef1c8:      	add	x16, x16, #0xc68
   ef1cc:      	br	x17

00000000000ef1d0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   ef1d0:      	adrp	x16, 0xfb000
   ef1d4:      	ldr	x17, [x16, #0xc70]
   ef1d8:      	add	x16, x16, #0xc70
   ef1dc:      	br	x17

00000000000ef1e0 <_ZN4hiai2op10ArgMaxExt2C2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef1e0:      	adrp	x16, 0xfb000
   ef1e4:      	ldr	x17, [x16, #0xc78]
   ef1e8:      	add	x16, x16, #0xc78
   ef1ec:      	br	x17

00000000000ef1f0 <_ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_@plt>:
   ef1f0:      	adrp	x16, 0xfb000
   ef1f4:      	ldr	x17, [x16, #0xc80]
   ef1f8:      	add	x16, x16, #0xc80
   ef1fc:      	br	x17

00000000000ef200 <_ZN4hiai2op10ArgMaxExt218set_attr_keep_dimsEb@plt>:
   ef200:      	adrp	x16, 0xfb000
   ef204:      	ldr	x17, [x16, #0xc88]
   ef208:      	add	x16, x16, #0xc88
   ef20c:      	br	x17

00000000000ef210 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5CastTENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   ef210:      	adrp	x16, 0xfb000
   ef214:      	ldr	x17, [x16, #0xc90]
   ef218:      	add	x16, x16, #0xc90
   ef21c:      	br	x17

00000000000ef220 <_ZN4hiai2op5CastT18set_attr_src_dtypeEl@plt>:
   ef220:      	adrp	x16, 0xfb000
   ef224:      	ldr	x17, [x16, #0xc98]
   ef228:      	add	x16, x16, #0xc98
   ef22c:      	br	x17

00000000000ef230 <_ZN4hiai2op5CastT18set_attr_dst_dtypeEl@plt>:
   ef230:      	adrp	x16, 0xfb000
   ef234:      	ldr	x17, [x16, #0xca0]
   ef238:      	add	x16, x16, #0xca0
   ef23c:      	br	x17

00000000000ef240 <_ZN5mizar6StatusC1Ev@plt>:
   ef240:      	adrp	x16, 0xfb000
   ef244:      	ldr	x17, [x16, #0xca8]
   ef248:      	add	x16, x16, #0xca8
   ef24c:      	br	x17

00000000000ef250 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   ef250:      	adrp	x16, 0xfb000
   ef254:      	ldr	x17, [x16, #0xcb0]
   ef258:      	add	x16, x16, #0xcb0
   ef25c:      	br	x17

00000000000ef260 <__stack_chk_fail@plt>:
   ef260:      	adrp	x16, 0xfb000
   ef264:      	ldr	x17, [x16, #0xcb8]
   ef268:      	add	x16, x16, #0xcb8
   ef26c:      	br	x17

00000000000ef270 <_ZN2ge5ShapeC1ENSt6__ndk16vectorIlNS1_9allocatorIlEEEE@plt>:
   ef270:      	adrp	x16, 0xfb000
   ef274:      	ldr	x17, [x16, #0xcc0]
   ef278:      	add	x16, x16, #0xcc0
   ef27c:      	br	x17

00000000000ef280 <_ZN2ge5ShapeC1Ev@plt>:
   ef280:      	adrp	x16, 0xfb000
   ef284:      	ldr	x17, [x16, #0xcc8]
   ef288:      	add	x16, x16, #0xcc8
   ef28c:      	br	x17

00000000000ef290 <_ZN2ge5ShapeaSERKS0_@plt>:
   ef290:      	adrp	x16, 0xfb000
   ef294:      	ldr	x17, [x16, #0xcd0]
   ef298:      	add	x16, x16, #0xcd0
   ef29c:      	br	x17

00000000000ef2a0 <_ZN2ge5ShapeD1Ev@plt>:
   ef2a0:      	adrp	x16, 0xfb000
   ef2a4:      	ldr	x17, [x16, #0xcd8]
   ef2a8:      	add	x16, x16, #0xcd8
   ef2ac:      	br	x17

00000000000ef2b0 <_ZN2ge5ShapeC1ERKS0_@plt>:
   ef2b0:      	adrp	x16, 0xfb000
   ef2b4:      	ldr	x17, [x16, #0xce0]
   ef2b8:      	add	x16, x16, #0xce0
   ef2bc:      	br	x17

00000000000ef2c0 <_ZN5mizar8NpuUtils12SetAttrValueERNSt6__ndk110shared_ptrIN4hiai2op5ConstEEEN2ge5ShapeEPKhmNS8_6FormatENS8_8DataTypeE@plt>:
   ef2c0:      	adrp	x16, 0xfb000
   ef2c4:      	ldr	x17, [x16, #0xce8]
   ef2c8:      	add	x16, x16, #0xce8
   ef2cc:      	br	x17

00000000000ef2d0 <_ZN2ge9AttrValue10CreateFromEb@plt>:
   ef2d0:      	adrp	x16, 0xfb000
   ef2d4:      	ldr	x17, [x16, #0xcf0]
   ef2d8:      	add	x16, x16, #0xcf0
   ef2dc:      	br	x17

00000000000ef2e0 <_ZN2ge8Operator7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE@plt>:
   ef2e0:      	adrp	x16, 0xfb000
   ef2e4:      	ldr	x17, [x16, #0xcf8]
   ef2e8:      	add	x16, x16, #0xcf8
   ef2ec:      	br	x17

00000000000ef2f0 <_ZN2ge9AttrValueD1Ev@plt>:
   ef2f0:      	adrp	x16, 0xfb000
   ef2f4:      	ldr	x17, [x16, #0xd00]
   ef2f8:      	add	x16, x16, #0xd00
   ef2fc:      	br	x17

00000000000ef300 <_ZN2ge9AttrValue10CreateFromEl@plt>:
   ef300:      	adrp	x16, 0xfb000
   ef304:      	ldr	x17, [x16, #0xd08]
   ef308:      	add	x16, x16, #0xd08
   ef30c:      	br	x17

00000000000ef310 <_ZN5mizar25__register__Npu__ArgMax__Ev@plt>:
   ef310:      	adrp	x16, 0xfb000
   ef314:      	ldr	x17, [x16, #0xd10]
   ef318:      	add	x16, x16, #0xd10
   ef31c:      	br	x17

00000000000ef320 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuArgMaxEJEEC2ES3_@plt>:
   ef320:      	adrp	x16, 0xfb000
   ef324:      	ldr	x17, [x16, #0xd18]
   ef328:      	add	x16, x16, #0xd18
   ef32c:      	br	x17

00000000000ef330 <__cxa_guard_acquire@plt>:
   ef330:      	adrp	x16, 0xfb000
   ef334:      	ldr	x17, [x16, #0xd20]
   ef338:      	add	x16, x16, #0xd20
   ef33c:      	br	x17

00000000000ef340 <__cxa_guard_release@plt>:
   ef340:      	adrp	x16, 0xfb000
   ef344:      	ldr	x17, [x16, #0xd28]
   ef348:      	add	x16, x16, #0xd28
   ef34c:      	br	x17

00000000000ef350 <_ZN5mizar12NpuOpBuilderD2Ev@plt>:
   ef350:      	adrp	x16, 0xfb000
   ef354:      	ldr	x17, [x16, #0xd30]
   ef358:      	add	x16, x16, #0xd30
   ef35c:      	br	x17

00000000000ef360 <__cxa_allocate_exception@plt>:
   ef360:      	adrp	x16, 0xfb000
   ef364:      	ldr	x17, [x16, #0xd38]
   ef368:      	add	x16, x16, #0xd38
   ef36c:      	br	x17

00000000000ef370 <__cxa_throw@plt>:
   ef370:      	adrp	x16, 0xfb000
   ef374:      	ldr	x17, [x16, #0xd40]
   ef378:      	add	x16, x16, #0xd40
   ef37c:      	br	x17

00000000000ef380 <__cxa_free_exception@plt>:
   ef380:      	adrp	x16, 0xfb000
   ef384:      	ldr	x17, [x16, #0xd48]
   ef388:      	add	x16, x16, #0xd48
   ef38c:      	br	x17

00000000000ef390 <_ZNSt11logic_errorC2EPKc@plt>:
   ef390:      	adrp	x16, 0xfb000
   ef394:      	ldr	x17, [x16, #0xd50]
   ef398:      	add	x16, x16, #0xd50
   ef39c:      	br	x17

00000000000ef3a0 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   ef3a0:      	adrp	x16, 0xfb000
   ef3a4:      	ldr	x17, [x16, #0xd58]
   ef3a8:      	add	x16, x16, #0xd58
   ef3ac:      	br	x17

00000000000ef3b0 <__cxa_begin_catch@plt>:
   ef3b0:      	adrp	x16, 0xfb000
   ef3b4:      	ldr	x17, [x16, #0xd60]
   ef3b8:      	add	x16, x16, #0xd60
   ef3bc:      	br	x17

00000000000ef3c0 <_ZSt9terminatev@plt>:
   ef3c0:      	adrp	x16, 0xfb000
   ef3c4:      	ldr	x17, [x16, #0xd68]
   ef3c8:      	add	x16, x16, #0xd68
   ef3cc:      	br	x17

00000000000ef3d0 <_ZN2ge8OperatorC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_i@plt>:
   ef3d0:      	adrp	x16, 0xfb000
   ef3d4:      	ldr	x17, [x16, #0xd70]
   ef3d8:      	add	x16, x16, #0xd70
   ef3dc:      	br	x17

00000000000ef3e0 <_ZN2ge8Operator14OutputRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   ef3e0:      	adrp	x16, 0xfb000
   ef3e4:      	ldr	x17, [x16, #0xd78]
   ef3e8:      	add	x16, x16, #0xd78
   ef3ec:      	br	x17

00000000000ef3f0 <_ZN4hiai2op5Const12__attr_valueEv@plt>:
   ef3f0:      	adrp	x16, 0xfb000
   ef3f4:      	ldr	x17, [x16, #0xd80]
   ef3f8:      	add	x16, x16, #0xd80
   ef3fc:      	br	x17

00000000000ef400 <_ZN2ge8OperatorD2Ev@plt>:
   ef400:      	adrp	x16, 0xfb000
   ef404:      	ldr	x17, [x16, #0xd88]
   ef408:      	add	x16, x16, #0xd88
   ef40c:      	br	x17

00000000000ef410 <_ZnwmRKSt9nothrow_t@plt>:
   ef410:      	adrp	x16, 0xfb000
   ef414:      	ldr	x17, [x16, #0xd90]
   ef418:      	add	x16, x16, #0xd90
   ef41c:      	br	x17

00000000000ef420 <_ZN2ge10TensorDescC1Ev@plt>:
   ef420:      	adrp	x16, 0xfb000
   ef424:      	ldr	x17, [x16, #0xd98]
   ef428:      	add	x16, x16, #0xd98
   ef42c:      	br	x17

00000000000ef430 <_ZN2ge6TensorC1ERKNS_10TensorDescE@plt>:
   ef430:      	adrp	x16, 0xfb000
   ef434:      	ldr	x17, [x16, #0xda0]
   ef438:      	add	x16, x16, #0xda0
   ef43c:      	br	x17

00000000000ef440 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk110shared_ptrINS_6TensorEEE@plt>:
   ef440:      	adrp	x16, 0xfb000
   ef444:      	ldr	x17, [x16, #0xda8]
   ef448:      	add	x16, x16, #0xda8
   ef44c:      	br	x17

00000000000ef450 <_ZN2ge10TensorDescD1Ev@plt>:
   ef450:      	adrp	x16, 0xfb000
   ef454:      	ldr	x17, [x16, #0xdb0]
   ef458:      	add	x16, x16, #0xdb0
   ef45c:      	br	x17

00000000000ef460 <_ZN2ge8Operator20OptionalAttrRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE@plt>:
   ef460:      	adrp	x16, 0xfb000
   ef464:      	ldr	x17, [x16, #0xdb8]
   ef468:      	add	x16, x16, #0xdb8
   ef46c:      	br	x17

00000000000ef470 <_ZdlPvRKSt9nothrow_t@plt>:
   ef470:      	adrp	x16, 0xfb000
   ef474:      	ldr	x17, [x16, #0xdc0]
   ef478:      	add	x16, x16, #0xdc0
   ef47c:      	br	x17

00000000000ef480 <_ZN2ge8Operator13InputRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   ef480:      	adrp	x16, 0xfb000
   ef484:      	ldr	x17, [x16, #0xdc8]
   ef488:      	add	x16, x16, #0xdc8
   ef48c:      	br	x17

00000000000ef490 <_ZN4hiai2op10ArgMaxExt212__input_axisEv@plt>:
   ef490:      	adrp	x16, 0xfb000
   ef494:      	ldr	x17, [x16, #0xdd0]
   ef498:      	add	x16, x16, #0xdd0
   ef49c:      	br	x17

00000000000ef4a0 <_ZN4hiai2op10ArgMaxExt218__attr_output_typeEv@plt>:
   ef4a0:      	adrp	x16, 0xfb000
   ef4a4:      	ldr	x17, [x16, #0xdd8]
   ef4a8:      	add	x16, x16, #0xdd8
   ef4ac:      	br	x17

00000000000ef4b0 <_ZN4hiai2op10ArgMaxExt216__attr_keep_dimsEv@plt>:
   ef4b0:      	adrp	x16, 0xfb000
   ef4b4:      	ldr	x17, [x16, #0xde0]
   ef4b8:      	add	x16, x16, #0xde0
   ef4bc:      	br	x17

00000000000ef4c0 <_ZN4hiai2op10ArgMaxExt216__attr_outmaxvalEv@plt>:
   ef4c0:      	adrp	x16, 0xfb000
   ef4c4:      	ldr	x17, [x16, #0xde8]
   ef4c8:      	add	x16, x16, #0xde8
   ef4cc:      	br	x17

00000000000ef4d0 <_ZN4hiai2op10ArgMaxExt211__attr_topkEv@plt>:
   ef4d0:      	adrp	x16, 0xfb000
   ef4d4:      	ldr	x17, [x16, #0xdf0]
   ef4d8:      	add	x16, x16, #0xdf0
   ef4dc:      	br	x17

00000000000ef4e0 <_ZN4hiai2op5CastT9__input_xEv@plt>:
   ef4e0:      	adrp	x16, 0xfb000
   ef4e4:      	ldr	x17, [x16, #0xdf8]
   ef4e8:      	add	x16, x16, #0xdf8
   ef4ec:      	br	x17

00000000000ef4f0 <_ZN4hiai2op5CastT25__required_attr_src_dtypeEv@plt>:
   ef4f0:      	adrp	x16, 0xfb000
   ef4f4:      	ldr	x17, [x16, #0xe00]
   ef4f8:      	add	x16, x16, #0xe00
   ef4fc:      	br	x17

00000000000ef500 <_ZNK2ge9AttrValue12GetValueTypeEv@plt>:
   ef500:      	adrp	x16, 0xfb000
   ef504:      	ldr	x17, [x16, #0xe08]
   ef508:      	add	x16, x16, #0xe08
   ef50c:      	br	x17

00000000000ef510 <_ZN2ge8Operator12AttrRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS_9AttrValue9ValueTypeE@plt>:
   ef510:      	adrp	x16, 0xfb000
   ef514:      	ldr	x17, [x16, #0xe10]
   ef518:      	add	x16, x16, #0xe10
   ef51c:      	br	x17

00000000000ef520 <_ZN4hiai2op5CastT25__required_attr_dst_dtypeEv@plt>:
   ef520:      	adrp	x16, 0xfb000
   ef524:      	ldr	x17, [x16, #0xe18]
   ef528:      	add	x16, x16, #0xe18
   ef52c:      	br	x17

00000000000ef530 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op8FloorDivEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef530:      	adrp	x16, 0xfb000
   ef534:      	ldr	x17, [x16, #0xe20]
   ef538:      	add	x16, x16, #0xe20
   ef53c:      	br	x17

00000000000ef540 <__android_log_print@plt>:
   ef540:      	adrp	x16, 0xfb000
   ef544:      	ldr	x17, [x16, #0xe28]
   ef548:      	add	x16, x16, #0xe28
   ef54c:      	br	x17

00000000000ef550 <fprintf@plt>:
   ef550:      	adrp	x16, 0xfb000
   ef554:      	ldr	x17, [x16, #0xe30]
   ef558:      	add	x16, x16, #0xe30
   ef55c:      	br	x17

00000000000ef560 <_ZN5mizar6StatusC1EiRKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   ef560:      	adrp	x16, 0xfb000
   ef564:      	ldr	x17, [x16, #0xe38]
   ef568:      	add	x16, x16, #0xe38
   ef56c:      	br	x17

00000000000ef570 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op3PowEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef570:      	adrp	x16, 0xfb000
   ef574:      	ldr	x17, [x16, #0xe40]
   ef578:      	add	x16, x16, #0xe40
   ef57c:      	br	x17

00000000000ef580 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op7MinimumEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef580:      	adrp	x16, 0xfb000
   ef584:      	ldr	x17, [x16, #0xe48]
   ef588:      	add	x16, x16, #0xe48
   ef58c:      	br	x17

00000000000ef590 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op3SubEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef590:      	adrp	x16, 0xfb000
   ef594:      	ldr	x17, [x16, #0xe50]
   ef598:      	add	x16, x16, #0xe50
   ef59c:      	br	x17

00000000000ef5a0 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op3AddEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef5a0:      	adrp	x16, 0xfb000
   ef5a4:      	ldr	x17, [x16, #0xe58]
   ef5a8:      	add	x16, x16, #0xe58
   ef5ac:      	br	x17

00000000000ef5b0 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op3MulEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef5b0:      	adrp	x16, 0xfb000
   ef5b4:      	ldr	x17, [x16, #0xe60]
   ef5b8:      	add	x16, x16, #0xe60
   ef5bc:      	br	x17

00000000000ef5c0 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op7MaximumEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef5c0:      	adrp	x16, 0xfb000
   ef5c4:      	ldr	x17, [x16, #0xe68]
   ef5c8:      	add	x16, x16, #0xe68
   ef5cc:      	br	x17

00000000000ef5d0 <_ZN5mizar9NpuBinary13BinaryConvertIN4hiai2op7RealDivEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEESC_RKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   ef5d0:      	adrp	x16, 0xfb000
   ef5d4:      	ldr	x17, [x16, #0xe70]
   ef5d8:      	add	x16, x16, #0xe70
   ef5dc:      	br	x17

00000000000ef5e0 <_ZN5mizar6detail14MakeStringImplIJPKciEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   ef5e0:      	adrp	x16, 0xfb000
   ef5e4:      	ldr	x17, [x16, #0xe78]
   ef5e8:      	add	x16, x16, #0xe78
   ef5ec:      	br	x17

00000000000ef5f0 <_ZN4hiai2op3AddC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef5f0:      	adrp	x16, 0xfb000
   ef5f4:      	ldr	x17, [x16, #0xe80]
   ef5f8:      	add	x16, x16, #0xe80
   ef5fc:      	br	x17

00000000000ef600 <_ZN4hiai2op8FloorDivC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef600:      	adrp	x16, 0xfb000
   ef604:      	ldr	x17, [x16, #0xe88]
   ef608:      	add	x16, x16, #0xe88
   ef60c:      	br	x17

00000000000ef610 <_ZN4hiai2op7MaximumC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef610:      	adrp	x16, 0xfb000
   ef614:      	ldr	x17, [x16, #0xe90]
   ef618:      	add	x16, x16, #0xe90
   ef61c:      	br	x17

00000000000ef620 <_ZN4hiai2op7MinimumC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef620:      	adrp	x16, 0xfb000
   ef624:      	ldr	x17, [x16, #0xe98]
   ef628:      	add	x16, x16, #0xe98
   ef62c:      	br	x17

00000000000ef630 <_ZN4hiai2op3MulC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef630:      	adrp	x16, 0xfb000
   ef634:      	ldr	x17, [x16, #0xea0]
   ef638:      	add	x16, x16, #0xea0
   ef63c:      	br	x17

00000000000ef640 <_ZN4hiai2op3PowC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef640:      	adrp	x16, 0xfb000
   ef644:      	ldr	x17, [x16, #0xea8]
   ef648:      	add	x16, x16, #0xea8
   ef64c:      	br	x17

00000000000ef650 <_ZN4hiai2op7RealDivC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef650:      	adrp	x16, 0xfb000
   ef654:      	ldr	x17, [x16, #0xeb0]
   ef658:      	add	x16, x16, #0xeb0
   ef65c:      	br	x17

00000000000ef660 <_ZN4hiai2op3SubC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef660:      	adrp	x16, 0xfb000
   ef664:      	ldr	x17, [x16, #0xeb8]
   ef668:      	add	x16, x16, #0xeb8
   ef66c:      	br	x17

00000000000ef670 <_ZN5mizar25__register__Npu__Binary__Ev@plt>:
   ef670:      	adrp	x16, 0xfb000
   ef674:      	ldr	x17, [x16, #0xec0]
   ef678:      	add	x16, x16, #0xec0
   ef67c:      	br	x17

00000000000ef680 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuBinaryEJEEC2ES3_@plt>:
   ef680:      	adrp	x16, 0xfb000
   ef684:      	ldr	x17, [x16, #0xec8]
   ef688:      	add	x16, x16, #0xec8
   ef68c:      	br	x17

00000000000ef690 <_ZN4hiai2op3Add10__input_x2Ev@plt>:
   ef690:      	adrp	x16, 0xfb000
   ef694:      	ldr	x17, [x16, #0xed0]
   ef698:      	add	x16, x16, #0xed0
   ef69c:      	br	x17

00000000000ef6a0 <_ZN4hiai2op8FloorDiv10__input_x2Ev@plt>:
   ef6a0:      	adrp	x16, 0xfb000
   ef6a4:      	ldr	x17, [x16, #0xed8]
   ef6a8:      	add	x16, x16, #0xed8
   ef6ac:      	br	x17

00000000000ef6b0 <_ZN4hiai2op7Maximum10__input_x2Ev@plt>:
   ef6b0:      	adrp	x16, 0xfb000
   ef6b4:      	ldr	x17, [x16, #0xee0]
   ef6b8:      	add	x16, x16, #0xee0
   ef6bc:      	br	x17

00000000000ef6c0 <_ZN4hiai2op7Minimum10__input_x2Ev@plt>:
   ef6c0:      	adrp	x16, 0xfb000
   ef6c4:      	ldr	x17, [x16, #0xee8]
   ef6c8:      	add	x16, x16, #0xee8
   ef6cc:      	br	x17

00000000000ef6d0 <_ZN4hiai2op3Mul10__input_x2Ev@plt>:
   ef6d0:      	adrp	x16, 0xfb000
   ef6d4:      	ldr	x17, [x16, #0xef0]
   ef6d8:      	add	x16, x16, #0xef0
   ef6dc:      	br	x17

00000000000ef6e0 <_ZN4hiai2op3Pow10__input_x2Ev@plt>:
   ef6e0:      	adrp	x16, 0xfb000
   ef6e4:      	ldr	x17, [x16, #0xef8]
   ef6e8:      	add	x16, x16, #0xef8
   ef6ec:      	br	x17

00000000000ef6f0 <_ZN4hiai2op7RealDiv10__input_x2Ev@plt>:
   ef6f0:      	adrp	x16, 0xfb000
   ef6f4:      	ldr	x17, [x16, #0xf00]
   ef6f8:      	add	x16, x16, #0xf00
   ef6fc:      	br	x17

00000000000ef700 <_ZN4hiai2op3Sub10__input_x2Ev@plt>:
   ef700:      	adrp	x16, 0xfb000
   ef704:      	ldr	x17, [x16, #0xf08]
   ef708:      	add	x16, x16, #0xf08
   ef70c:      	br	x17

00000000000ef710 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   ef710:      	adrp	x16, 0xfb000
   ef714:      	ldr	x17, [x16, #0xf10]
   ef718:      	add	x16, x16, #0xf10
   ef71c:      	br	x17

00000000000ef720 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   ef720:      	adrp	x16, 0xfb000
   ef724:      	ldr	x17, [x16, #0xf18]
   ef728:      	add	x16, x16, #0xf18
   ef72c:      	br	x17

00000000000ef730 <strlen@plt>:
   ef730:      	adrp	x16, 0xfb000
   ef734:      	ldr	x17, [x16, #0xf20]
   ef738:      	add	x16, x16, #0xf20
   ef73c:      	br	x17

00000000000ef740 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
   ef740:      	adrp	x16, 0xfb000
   ef744:      	ldr	x17, [x16, #0xf28]
   ef748:      	add	x16, x16, #0xf28
   ef74c:      	br	x17

00000000000ef750 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   ef750:      	adrp	x16, 0xfb000
   ef754:      	ldr	x17, [x16, #0xf30]
   ef758:      	add	x16, x16, #0xf30
   ef75c:      	br	x17

00000000000ef760 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   ef760:      	adrp	x16, 0xfb000
   ef764:      	ldr	x17, [x16, #0xf38]
   ef768:      	add	x16, x16, #0xf38
   ef76c:      	br	x17

00000000000ef770 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   ef770:      	adrp	x16, 0xfb000
   ef774:      	ldr	x17, [x16, #0xf40]
   ef778:      	add	x16, x16, #0xf40
   ef77c:      	br	x17

00000000000ef780 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   ef780:      	adrp	x16, 0xfb000
   ef784:      	ldr	x17, [x16, #0xf48]
   ef788:      	add	x16, x16, #0xf48
   ef78c:      	br	x17

00000000000ef790 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
   ef790:      	adrp	x16, 0xfb000
   ef794:      	ldr	x17, [x16, #0xf50]
   ef798:      	add	x16, x16, #0xf50
   ef79c:      	br	x17

00000000000ef7a0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
   ef7a0:      	adrp	x16, 0xfb000
   ef7a4:      	ldr	x17, [x16, #0xf58]
   ef7a8:      	add	x16, x16, #0xf58
   ef7ac:      	br	x17

00000000000ef7b0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   ef7b0:      	adrp	x16, 0xfb000
   ef7b4:      	ldr	x17, [x16, #0xf60]
   ef7b8:      	add	x16, x16, #0xf60
   ef7bc:      	br	x17

00000000000ef7c0 <_ZNSt6__ndk16localeD1Ev@plt>:
   ef7c0:      	adrp	x16, 0xfb000
   ef7c4:      	ldr	x17, [x16, #0xf68]
   ef7c8:      	add	x16, x16, #0xf68
   ef7cc:      	br	x17

00000000000ef7d0 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   ef7d0:      	adrp	x16, 0xfb000
   ef7d4:      	ldr	x17, [x16, #0xf70]
   ef7d8:      	add	x16, x16, #0xf70
   ef7dc:      	br	x17

00000000000ef7e0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
   ef7e0:      	adrp	x16, 0xfb000
   ef7e4:      	ldr	x17, [x16, #0xf78]
   ef7e8:      	add	x16, x16, #0xf78
   ef7ec:      	br	x17

00000000000ef7f0 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
   ef7f0:      	adrp	x16, 0xfb000
   ef7f4:      	ldr	x17, [x16, #0xf80]
   ef7f8:      	add	x16, x16, #0xf80
   ef7fc:      	br	x17

00000000000ef800 <__cxa_end_catch@plt>:
   ef800:      	adrp	x16, 0xfb000
   ef804:      	ldr	x17, [x16, #0xf88]
   ef808:      	add	x16, x16, #0xf88
   ef80c:      	br	x17

00000000000ef810 <memset@plt>:
   ef810:      	adrp	x16, 0xfb000
   ef814:      	ldr	x17, [x16, #0xf90]
   ef818:      	add	x16, x16, #0xf90
   ef81c:      	br	x17

00000000000ef820 <_ZN5mizar8NpuUtils12SetAttrValueIfEEvRNSt6__ndk110shared_ptrIN4hiai2op5ConstEEENS2_6vectorIT_NS2_9allocatorISA_EEEEN2ge6FormatENSE_8DataTypeEb@plt>:
   ef820:      	adrp	x16, 0xfb000
   ef824:      	ldr	x17, [x16, #0xf98]
   ef828:      	add	x16, x16, #0xf98
   ef82c:      	br	x17

00000000000ef830 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op11ClipByValueENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   ef830:      	adrp	x16, 0xfb000
   ef834:      	ldr	x17, [x16, #0xfa0]
   ef838:      	add	x16, x16, #0xfa0
   ef83c:      	br	x17

00000000000ef840 <_ZN5mizar23__register__Npu__Clip__Ev@plt>:
   ef840:      	adrp	x16, 0xfb000
   ef844:      	ldr	x17, [x16, #0xfa8]
   ef848:      	add	x16, x16, #0xfa8
   ef84c:      	br	x17

00000000000ef850 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_7NpuClipEJEEC2ES3_@plt>:
   ef850:      	adrp	x16, 0xfb000
   ef854:      	ldr	x17, [x16, #0xfb0]
   ef858:      	add	x16, x16, #0xfb0
   ef85c:      	br	x17

00000000000ef860 <_ZN4hiai2op11ClipByValue9__input_xEv@plt>:
   ef860:      	adrp	x16, 0xfb000
   ef864:      	ldr	x17, [x16, #0xfb8]
   ef868:      	add	x16, x16, #0xfb8
   ef86c:      	br	x17

00000000000ef870 <_ZN4hiai2op11ClipByValue22__input_clip_value_maxEv@plt>:
   ef870:      	adrp	x16, 0xfb000
   ef874:      	ldr	x17, [x16, #0xfc0]
   ef878:      	add	x16, x16, #0xfc0
   ef87c:      	br	x17

00000000000ef880 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op7ConcatDENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   ef880:      	adrp	x16, 0xfb000
   ef884:      	ldr	x17, [x16, #0xfc8]
   ef888:      	add	x16, x16, #0xfc8
   ef88c:      	br	x17

00000000000ef890 <_ZN2ge8Operator20DynamicInputRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEj@plt>:
   ef890:      	adrp	x16, 0xfb000
   ef894:      	ldr	x17, [x16, #0xfd0]
   ef898:      	add	x16, x16, #0xfd0
   ef89c:      	br	x17

00000000000ef8a0 <_ZN2ge8Operator15SetDynamicInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiRKS0_@plt>:
   ef8a0:      	adrp	x16, 0xfb000
   ef8a4:      	ldr	x17, [x16, #0xfd8]
   ef8a8:      	add	x16, x16, #0xfd8
   ef8ac:      	br	x17

00000000000ef8b0 <_ZN4hiai2op7ConcatD19set_attr_concat_dimEl@plt>:
   ef8b0:      	adrp	x16, 0xfb000
   ef8b4:      	ldr	x17, [x16, #0xfe0]
   ef8b8:      	add	x16, x16, #0xfe0
   ef8bc:      	br	x17

00000000000ef8c0 <_ZN4hiai2op7ConcatD10set_attr_NEl@plt>:
   ef8c0:      	adrp	x16, 0xfb000
   ef8c4:      	ldr	x17, [x16, #0xfe8]
   ef8c8:      	add	x16, x16, #0xfe8
   ef8cc:      	br	x17

00000000000ef8d0 <_ZN5mizar25__register__Npu__Concat__Ev@plt>:
   ef8d0:      	adrp	x16, 0xfb000
   ef8d4:      	ldr	x17, [x16, #0xff0]
   ef8d8:      	add	x16, x16, #0xff0
   ef8dc:      	br	x17

00000000000ef8e0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuConcatEJEEC2ES3_@plt>:
   ef8e0:      	adrp	x16, 0xfb000
   ef8e4:      	ldr	x17, [x16, #0xff8]
   ef8e8:      	add	x16, x16, #0xff8
   ef8ec:      	br	x17

00000000000ef8f0 <_ZN4hiai2op7ConcatD12__dy_input_xEv@plt>:
   ef8f0:      	adrp	x16, 0xfc000
   ef8f4:      	ldr	x17, [x16]
   ef8f8:      	add	x16, x16, #0x0
   ef8fc:      	br	x17

00000000000ef900 <_ZN4hiai2op7ConcatD26__required_attr_concat_dimEv@plt>:
   ef900:      	adrp	x16, 0xfc000
   ef904:      	ldr	x17, [x16, #0x8]
   ef908:      	add	x16, x16, #0x8
   ef90c:      	br	x17

00000000000ef910 <_ZN4hiai2op7ConcatD8__attr_NEv@plt>:
   ef910:      	adrp	x16, 0xfc000
   ef914:      	ldr	x17, [x16, #0x10]
   ef918:      	add	x16, x16, #0x10
   ef91c:      	br	x17

00000000000ef920 <_ZN4hiai2op11ConvolutionC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ef920:      	adrp	x16, 0xfc000
   ef924:      	ldr	x17, [x16, #0x18]
   ef928:      	add	x16, x16, #0x18
   ef92c:      	br	x17

00000000000ef930 <_ZN5mizar8NpuUtils12SetAttrValueERNSt6__ndk110shared_ptrIN4hiai2op5ConstEEERKNS_15NpuTensorBufferE@plt>:
   ef930:      	adrp	x16, 0xfc000
   ef934:      	ldr	x17, [x16, #0x20]
   ef938:      	add	x16, x16, #0x20
   ef93c:      	br	x17

00000000000ef940 <_ZNK5mizar6Status7IsErrorEv@plt>:
   ef940:      	adrp	x16, 0xfc000
   ef944:      	ldr	x17, [x16, #0x28]
   ef948:      	add	x16, x16, #0x28
   ef94c:      	br	x17

00000000000ef950 <_ZN5mizar6StatusneEi@plt>:
   ef950:      	adrp	x16, 0xfc000
   ef954:      	ldr	x17, [x16, #0x30]
   ef958:      	add	x16, x16, #0x30
   ef95c:      	br	x17

00000000000ef960 <_ZNK5mizar6Status11DescriptionEv@plt>:
   ef960:      	adrp	x16, 0xfc000
   ef964:      	ldr	x17, [x16, #0x38]
   ef968:      	add	x16, x16, #0x38
   ef96c:      	br	x17

00000000000ef970 <_ZN5mizar8NpuUtils12SetAttrValueERNSt6__ndk110shared_ptrIN4hiai2op5ConstEEEN2ge5ShapeERKNS_15NpuTensorBufferE@plt>:
   ef970:      	adrp	x16, 0xfc000
   ef974:      	ldr	x17, [x16, #0x40]
   ef978:      	add	x16, x16, #0x40
   ef97c:      	br	x17

00000000000ef980 <_ZN4hiai2op11Convolution16set_attr_stridesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   ef980:      	adrp	x16, 0xfc000
   ef984:      	ldr	x17, [x16, #0x48]
   ef988:      	add	x16, x16, #0x48
   ef98c:      	br	x17

00000000000ef990 <_ZN4hiai2op11Convolution18set_attr_dilationsENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   ef990:      	adrp	x16, 0xfc000
   ef994:      	ldr	x17, [x16, #0x50]
   ef998:      	add	x16, x16, #0x50
   ef99c:      	br	x17

00000000000ef9a0 <_ZN4hiai2op11Convolution13set_attr_padsENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   ef9a0:      	adrp	x16, 0xfc000
   ef9a4:      	ldr	x17, [x16, #0x58]
   ef9a8:      	add	x16, x16, #0x58
   ef9ac:      	br	x17

00000000000ef9b0 <_ZN4hiai2op11Convolution15set_attr_groupsEl@plt>:
   ef9b0:      	adrp	x16, 0xfc000
   ef9b4:      	ldr	x17, [x16, #0x60]
   ef9b8:      	add	x16, x16, #0x60
   ef9bc:      	br	x17

00000000000ef9c0 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorIlNS1_9allocatorIlEEEE@plt>:
   ef9c0:      	adrp	x16, 0xfc000
   ef9c4:      	ldr	x17, [x16, #0x68]
   ef9c8:      	add	x16, x16, #0x68
   ef9cc:      	br	x17

00000000000ef9d0 <_ZN5mizar23__register__Npu__Conv__Ev@plt>:
   ef9d0:      	adrp	x16, 0xfc000
   ef9d4:      	ldr	x17, [x16, #0x70]
   ef9d8:      	add	x16, x16, #0x70
   ef9dc:      	br	x17

00000000000ef9e0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_7NpuConvEJEEC2ES3_@plt>:
   ef9e0:      	adrp	x16, 0xfc000
   ef9e4:      	ldr	x17, [x16, #0x78]
   ef9e8:      	add	x16, x16, #0x78
   ef9ec:      	br	x17

00000000000ef9f0 <_ZN4hiai2op11Convolution14__input_filterEv@plt>:
   ef9f0:      	adrp	x16, 0xfc000
   ef9f4:      	ldr	x17, [x16, #0x80]
   ef9f8:      	add	x16, x16, #0x80
   ef9fc:      	br	x17

00000000000efa00 <_ZN2ge8Operator21OptionalInputRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   efa00:      	adrp	x16, 0xfc000
   efa04:      	ldr	x17, [x16, #0x88]
   efa08:      	add	x16, x16, #0x88
   efa0c:      	br	x17

00000000000efa10 <_ZN4hiai2op11Convolution25__optional_input_offset_wEv@plt>:
   efa10:      	adrp	x16, 0xfc000
   efa14:      	ldr	x17, [x16, #0x90]
   efa18:      	add	x16, x16, #0x90
   efa1c:      	br	x17

00000000000efa20 <_ZN4hiai2op11Convolution23__required_attr_stridesEv@plt>:
   efa20:      	adrp	x16, 0xfc000
   efa24:      	ldr	x17, [x16, #0x98]
   efa28:      	add	x16, x16, #0x98
   efa2c:      	br	x17

00000000000efa30 <_ZN4hiai2op11Convolution16__attr_dilationsEv@plt>:
   efa30:      	adrp	x16, 0xfc000
   efa34:      	ldr	x17, [x16, #0xa0]
   efa38:      	add	x16, x16, #0xa0
   efa3c:      	br	x17

00000000000efa40 <_ZN4hiai2op11Convolution11__attr_padsEv@plt>:
   efa40:      	adrp	x16, 0xfc000
   efa44:      	ldr	x17, [x16, #0xa8]
   efa48:      	add	x16, x16, #0xa8
   efa4c:      	br	x17

00000000000efa50 <_ZN4hiai2op11Convolution15__attr_pad_modeEv@plt>:
   efa50:      	adrp	x16, 0xfc000
   efa54:      	ldr	x17, [x16, #0xb0]
   efa58:      	add	x16, x16, #0xb0
   efa5c:      	br	x17

00000000000efa60 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   efa60:      	adrp	x16, 0xfc000
   efa64:      	ldr	x17, [x16, #0xb8]
   efa68:      	add	x16, x16, #0xb8
   efa6c:      	br	x17

00000000000efa70 <_ZN4hiai2op11Convolution13__attr_groupsEv@plt>:
   efa70:      	adrp	x16, 0xfc000
   efa74:      	ldr	x17, [x16, #0xc0]
   efa78:      	add	x16, x16, #0xc0
   efa7c:      	br	x17

00000000000efa80 <_ZN4hiai2op11Convolution18__attr_data_formatEv@plt>:
   efa80:      	adrp	x16, 0xfc000
   efa84:      	ldr	x17, [x16, #0xc8]
   efa88:      	add	x16, x16, #0xc8
   efa8c:      	br	x17

00000000000efa90 <_ZN4hiai2op11Convolution15__attr_offset_xEv@plt>:
   efa90:      	adrp	x16, 0xfc000
   efa94:      	ldr	x17, [x16, #0xd0]
   efa98:      	add	x16, x16, #0xd0
   efa9c:      	br	x17

00000000000efaa0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op13ConvTransposeENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   efaa0:      	adrp	x16, 0xfc000
   efaa4:      	ldr	x17, [x16, #0xd8]
   efaa8:      	add	x16, x16, #0xd8
   efaac:      	br	x17

00000000000efab0 <_ZN4hiai2op13ConvTranspose16set_attr_stridesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   efab0:      	adrp	x16, 0xfc000
   efab4:      	ldr	x17, [x16, #0xe0]
   efab8:      	add	x16, x16, #0xe0
   efabc:      	br	x17

00000000000efac0 <_ZN4hiai2op13ConvTranspose18set_attr_dilationsENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   efac0:      	adrp	x16, 0xfc000
   efac4:      	ldr	x17, [x16, #0xe8]
   efac8:      	add	x16, x16, #0xe8
   efacc:      	br	x17

00000000000efad0 <_ZN4hiai2op13ConvTranspose13set_attr_padsENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   efad0:      	adrp	x16, 0xfc000
   efad4:      	ldr	x17, [x16, #0xf0]
   efad8:      	add	x16, x16, #0xf0
   efadc:      	br	x17

00000000000efae0 <_ZN4hiai2op13ConvTranspose15set_attr_groupsEl@plt>:
   efae0:      	adrp	x16, 0xfc000
   efae4:      	ldr	x17, [x16, #0xf8]
   efae8:      	add	x16, x16, #0xf8
   efaec:      	br	x17

00000000000efaf0 <_ZN5mizar32__register__Npu__ConvTranspose__Ev@plt>:
   efaf0:      	adrp	x16, 0xfc000
   efaf4:      	ldr	x17, [x16, #0x100]
   efaf8:      	add	x16, x16, #0x100
   efafc:      	br	x17

00000000000efb00 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_16NpuConvTransposeEJEEC2ES3_@plt>:
   efb00:      	adrp	x16, 0xfc000
   efb04:      	ldr	x17, [x16, #0x108]
   efb08:      	add	x16, x16, #0x108
   efb0c:      	br	x17

00000000000efb10 <_ZN4hiai2op13ConvTranspose29__optional_input_output_shapeEv@plt>:
   efb10:      	adrp	x16, 0xfc000
   efb14:      	ldr	x17, [x16, #0x110]
   efb18:      	add	x16, x16, #0x110
   efb1c:      	br	x17

00000000000efb20 <_ZN4hiai2op13ConvTranspose9__input_xEv@plt>:
   efb20:      	adrp	x16, 0xfc000
   efb24:      	ldr	x17, [x16, #0x118]
   efb28:      	add	x16, x16, #0x118
   efb2c:      	br	x17

00000000000efb30 <_ZN4hiai2op13ConvTranspose25__optional_input_offset_wEv@plt>:
   efb30:      	adrp	x16, 0xfc000
   efb34:      	ldr	x17, [x16, #0x120]
   efb38:      	add	x16, x16, #0x120
   efb3c:      	br	x17

00000000000efb40 <_ZN4hiai2op13ConvTranspose23__required_attr_stridesEv@plt>:
   efb40:      	adrp	x16, 0xfc000
   efb44:      	ldr	x17, [x16, #0x128]
   efb48:      	add	x16, x16, #0x128
   efb4c:      	br	x17

00000000000efb50 <_ZN4hiai2op13ConvTranspose11__attr_padsEv@plt>:
   efb50:      	adrp	x16, 0xfc000
   efb54:      	ldr	x17, [x16, #0x130]
   efb58:      	add	x16, x16, #0x130
   efb5c:      	br	x17

00000000000efb60 <_ZN4hiai2op13ConvTranspose15__attr_pad_modeEv@plt>:
   efb60:      	adrp	x16, 0xfc000
   efb64:      	ldr	x17, [x16, #0x138]
   efb68:      	add	x16, x16, #0x138
   efb6c:      	br	x17

00000000000efb70 <_ZN4hiai2op13ConvTranspose16__attr_dilationsEv@plt>:
   efb70:      	adrp	x16, 0xfc000
   efb74:      	ldr	x17, [x16, #0x140]
   efb78:      	add	x16, x16, #0x140
   efb7c:      	br	x17

00000000000efb80 <_ZN4hiai2op13ConvTranspose13__attr_groupsEv@plt>:
   efb80:      	adrp	x16, 0xfc000
   efb84:      	ldr	x17, [x16, #0x148]
   efb88:      	add	x16, x16, #0x148
   efb8c:      	br	x17

00000000000efb90 <_ZN4hiai2op13ConvTranspose18__attr_data_formatEv@plt>:
   efb90:      	adrp	x16, 0xfc000
   efb94:      	ldr	x17, [x16, #0x150]
   efb98:      	add	x16, x16, #0x150
   efb9c:      	br	x17

00000000000efba0 <_ZN4hiai2op13ConvTranspose15__attr_offset_xEv@plt>:
   efba0:      	adrp	x16, 0xfc000
   efba4:      	ldr	x17, [x16, #0x158]
   efba8:      	add	x16, x16, #0x158
   efbac:      	br	x17

00000000000efbb0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op10ActivationENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   efbb0:      	adrp	x16, 0xfc000
   efbb4:      	ldr	x17, [x16, #0x160]
   efbb8:      	add	x16, x16, #0x160
   efbbc:      	br	x17

00000000000efbc0 <_ZN4hiai2op10Activation13set_attr_modeEl@plt>:
   efbc0:      	adrp	x16, 0xfc000
   efbc4:      	ldr	x17, [x16, #0x168]
   efbc8:      	add	x16, x16, #0x168
   efbcc:      	br	x17

00000000000efbd0 <_ZN4hiai2op10Activation13set_attr_coefEf@plt>:
   efbd0:      	adrp	x16, 0xfc000
   efbd4:      	ldr	x17, [x16, #0x170]
   efbd8:      	add	x16, x16, #0x170
   efbdc:      	br	x17

00000000000efbe0 <_ZN2ge9AttrValue10CreateFromEf@plt>:
   efbe0:      	adrp	x16, 0xfc000
   efbe4:      	ldr	x17, [x16, #0x178]
   efbe8:      	add	x16, x16, #0x178
   efbec:      	br	x17

00000000000efbf0 <_ZN5mizar22__register__Npu__Elu__Ev@plt>:
   efbf0:      	adrp	x16, 0xfc000
   efbf4:      	ldr	x17, [x16, #0x180]
   efbf8:      	add	x16, x16, #0x180
   efbfc:      	br	x17

00000000000efc00 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_6NpuEluEJEEC2ES3_@plt>:
   efc00:      	adrp	x16, 0xfc000
   efc04:      	ldr	x17, [x16, #0x188]
   efc08:      	add	x16, x16, #0x188
   efc0c:      	br	x17

00000000000efc10 <_ZN4hiai2op10Activation9__input_xEv@plt>:
   efc10:      	adrp	x16, 0xfc000
   efc14:      	ldr	x17, [x16, #0x190]
   efc18:      	add	x16, x16, #0x190
   efc1c:      	br	x17

00000000000efc20 <_ZN4hiai2op10Activation11__attr_modeEv@plt>:
   efc20:      	adrp	x16, 0xfc000
   efc24:      	ldr	x17, [x16, #0x198]
   efc28:      	add	x16, x16, #0x198
   efc2c:      	br	x17

00000000000efc30 <_ZN4hiai2op10Activation11__attr_coefEv@plt>:
   efc30:      	adrp	x16, 0xfc000
   efc34:      	ldr	x17, [x16, #0x1a0]
   efc38:      	add	x16, x16, #0x1a0
   efc3c:      	br	x17

00000000000efc40 <_ZN4hiai2op10Activation21__attr_negative_slopeEv@plt>:
   efc40:      	adrp	x16, 0xfc000
   efc44:      	ldr	x17, [x16, #0x1a8]
   efc48:      	add	x16, x16, #0x1a8
   efc4c:      	br	x17

00000000000efc50 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op7FlattenENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   efc50:      	adrp	x16, 0xfc000
   efc54:      	ldr	x17, [x16, #0x1b0]
   efc58:      	add	x16, x16, #0x1b0
   efc5c:      	br	x17

00000000000efc60 <_ZN5mizar26__register__Npu__Flatten__Ev@plt>:
   efc60:      	adrp	x16, 0xfc000
   efc64:      	ldr	x17, [x16, #0x1b8]
   efc68:      	add	x16, x16, #0x1b8
   efc6c:      	br	x17

00000000000efc70 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuFlattenEJEEC2ES3_@plt>:
   efc70:      	adrp	x16, 0xfc000
   efc74:      	ldr	x17, [x16, #0x1c0]
   efc78:      	add	x16, x16, #0x1c0
   efc7c:      	br	x17

00000000000efc80 <_ZN4hiai2op7Flatten9__input_xEv@plt>:
   efc80:      	adrp	x16, 0xfc000
   efc84:      	ldr	x17, [x16, #0x1c8]
   efc88:      	add	x16, x16, #0x1c8
   efc8c:      	br	x17

00000000000efc90 <memcpy@plt>:
   efc90:      	adrp	x16, 0xfc000
   efc94:      	ldr	x17, [x16, #0x1d0]
   efc98:      	add	x16, x16, #0x1d0
   efc9c:      	br	x17

00000000000efca0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm@plt>:
   efca0:      	adrp	x16, 0xfc000
   efca4:      	ldr	x17, [x16, #0x1d8]
   efca8:      	add	x16, x16, #0x1d8
   efcac:      	br	x17

00000000000efcb0 <_ZN4hiai2op9GatherV2DC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   efcb0:      	adrp	x16, 0xfc000
   efcb4:      	ldr	x17, [x16, #0x1e0]
   efcb8:      	add	x16, x16, #0x1e0
   efcbc:      	br	x17

00000000000efcc0 <_ZN5mizar8NpuUtils16CopyInputRawDataIiEENS_6StatusERNSt6__ndk16vectorIT_NS3_9allocatorIS5_EEEERKNS_15NpuTensorBufferE@plt>:
   efcc0:      	adrp	x16, 0xfc000
   efcc4:      	ldr	x17, [x16, #0x1e8]
   efcc8:      	add	x16, x16, #0x1e8
   efccc:      	br	x17

00000000000efcd0 <_ZN4hiai2op9GatherV2D13set_attr_axisEl@plt>:
   efcd0:      	adrp	x16, 0xfc000
   efcd4:      	ldr	x17, [x16, #0x1f0]
   efcd8:      	add	x16, x16, #0x1f0
   efcdc:      	br	x17

00000000000efce0 <_ZN4hiai2op7ReshapeC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   efce0:      	adrp	x16, 0xfc000
   efce4:      	ldr	x17, [x16, #0x1f8]
   efce8:      	add	x16, x16, #0x1f8
   efcec:      	br	x17

00000000000efcf0 <_ZN5mizar25__register__Npu__Gather__Ev@plt>:
   efcf0:      	adrp	x16, 0xfc000
   efcf4:      	ldr	x17, [x16, #0x200]
   efcf8:      	add	x16, x16, #0x200
   efcfc:      	br	x17

00000000000efd00 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuGatherEJEEC2ES3_@plt>:
   efd00:      	adrp	x16, 0xfc000
   efd04:      	ldr	x17, [x16, #0x208]
   efd08:      	add	x16, x16, #0x208
   efd0c:      	br	x17

00000000000efd10 <_ZN4hiai2op9GatherV2D15__input_indicesEv@plt>:
   efd10:      	adrp	x16, 0xfc000
   efd14:      	ldr	x17, [x16, #0x210]
   efd18:      	add	x16, x16, #0x210
   efd1c:      	br	x17

00000000000efd20 <_ZN4hiai2op9GatherV2D20__required_attr_axisEv@plt>:
   efd20:      	adrp	x16, 0xfc000
   efd24:      	ldr	x17, [x16, #0x218]
   efd28:      	add	x16, x16, #0x218
   efd2c:      	br	x17

00000000000efd30 <_ZN4hiai2op7Reshape13__input_shapeEv@plt>:
   efd30:      	adrp	x16, 0xfc000
   efd34:      	ldr	x17, [x16, #0x220]
   efd38:      	add	x16, x16, #0x220
   efd3c:      	br	x17

00000000000efd40 <_ZN4hiai2op7Reshape11__attr_axisEv@plt>:
   efd40:      	adrp	x16, 0xfc000
   efd44:      	ldr	x17, [x16, #0x228]
   efd48:      	add	x16, x16, #0x228
   efd4c:      	br	x17

00000000000efd50 <_ZN4hiai2op7Reshape15__attr_num_axesEv@plt>:
   efd50:      	adrp	x16, 0xfc000
   efd54:      	ldr	x17, [x16, #0x230]
   efd58:      	add	x16, x16, #0x230
   efd5c:      	br	x17

00000000000efd60 <_ZN5mizar6detail14MakeStringImplIJPKcfEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   efd60:      	adrp	x16, 0xfc000
   efd64:      	ldr	x17, [x16, #0x238]
   efd68:      	add	x16, x16, #0x238
   efd6c:      	br	x17

00000000000efd70 <_ZN4hiai2op15FullyConnection11set_input_xERKN2ge8OperatorE@plt>:
   efd70:      	adrp	x16, 0xfc000
   efd74:      	ldr	x17, [x16, #0x240]
   efd78:      	add	x16, x16, #0x240
   efd7c:      	br	x17

00000000000efd80 <_ZN4hiai2op7Reshape11set_input_xERKN2ge8OperatorE@plt>:
   efd80:      	adrp	x16, 0xfc000
   efd84:      	ldr	x17, [x16, #0x248]
   efd88:      	add	x16, x16, #0x248
   efd8c:      	br	x17

00000000000efd90 <_ZN4hiai2op7Reshape15set_input_shapeERKN2ge8OperatorE@plt>:
   efd90:      	adrp	x16, 0xfc000
   efd94:      	ldr	x17, [x16, #0x250]
   efd98:      	add	x16, x16, #0x250
   efd9c:      	br	x17

00000000000efda0 <_ZN4hiai2op15FullyConnection11set_input_wERKN2ge8OperatorE@plt>:
   efda0:      	adrp	x16, 0xfc000
   efda4:      	ldr	x17, [x16, #0x258]
   efda8:      	add	x16, x16, #0x258
   efdac:      	br	x17

00000000000efdb0 <_ZN4hiai2op15FullyConnection19set_attr_num_outputEl@plt>:
   efdb0:      	adrp	x16, 0xfc000
   efdb4:      	ldr	x17, [x16, #0x260]
   efdb8:      	add	x16, x16, #0x260
   efdbc:      	br	x17

00000000000efdc0 <_ZN4hiai2op15FullyConnection11set_input_bERKN2ge8OperatorE@plt>:
   efdc0:      	adrp	x16, 0xfc000
   efdc4:      	ldr	x17, [x16, #0x268]
   efdc8:      	add	x16, x16, #0x268
   efdcc:      	br	x17

00000000000efdd0 <_ZN4hiai2op15FullyConnectionC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   efdd0:      	adrp	x16, 0xfc000
   efdd4:      	ldr	x17, [x16, #0x270]
   efdd8:      	add	x16, x16, #0x270
   efddc:      	br	x17

00000000000efde0 <_ZN5mizar23__register__Npu__Gemm__Ev@plt>:
   efde0:      	adrp	x16, 0xfc000
   efde4:      	ldr	x17, [x16, #0x278]
   efde8:      	add	x16, x16, #0x278
   efdec:      	br	x17

00000000000efdf0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_7NpuGemmEJEEC2ES3_@plt>:
   efdf0:      	adrp	x16, 0xfc000
   efdf4:      	ldr	x17, [x16, #0x280]
   efdf8:      	add	x16, x16, #0x280
   efdfc:      	br	x17

00000000000efe00 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf@plt>:
   efe00:      	adrp	x16, 0xfc000
   efe04:      	ldr	x17, [x16, #0x288]
   efe08:      	add	x16, x16, #0x288
   efe0c:      	br	x17

00000000000efe10 <_ZN4hiai2op15FullyConnection9__input_wEv@plt>:
   efe10:      	adrp	x16, 0xfc000
   efe14:      	ldr	x17, [x16, #0x290]
   efe18:      	add	x16, x16, #0x290
   efe1c:      	br	x17

00000000000efe20 <_ZN4hiai2op15FullyConnection25__optional_input_offset_wEv@plt>:
   efe20:      	adrp	x16, 0xfc000
   efe24:      	ldr	x17, [x16, #0x298]
   efe28:      	add	x16, x16, #0x298
   efe2c:      	br	x17

00000000000efe30 <_ZN4hiai2op15FullyConnection26__required_attr_num_outputEv@plt>:
   efe30:      	adrp	x16, 0xfc000
   efe34:      	ldr	x17, [x16, #0x2a0]
   efe38:      	add	x16, x16, #0x2a0
   efe3c:      	br	x17

00000000000efe40 <_ZN4hiai2op15FullyConnection16__attr_transposeEv@plt>:
   efe40:      	adrp	x16, 0xfc000
   efe44:      	ldr	x17, [x16, #0x2a8]
   efe48:      	add	x16, x16, #0x2a8
   efe4c:      	br	x17

00000000000efe50 <_ZN4hiai2op15FullyConnection11__attr_axisEv@plt>:
   efe50:      	adrp	x16, 0xfc000
   efe54:      	ldr	x17, [x16, #0x2b0]
   efe58:      	add	x16, x16, #0x2b0
   efe5c:      	br	x17

00000000000efe60 <_ZN4hiai2op15FullyConnection15__attr_offset_xEv@plt>:
   efe60:      	adrp	x16, 0xfc000
   efe64:      	ldr	x17, [x16, #0x2b8]
   efe68:      	add	x16, x16, #0x2b8
   efe6c:      	br	x17

00000000000efe70 <_ZN5mizar30__register__Npu__HardSigmoid__Ev@plt>:
   efe70:      	adrp	x16, 0xfc000
   efe74:      	ldr	x17, [x16, #0x2c0]
   efe78:      	add	x16, x16, #0x2c0
   efe7c:      	br	x17

00000000000efe80 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_14NpuHardSigmoidEJEEC2ES3_@plt>:
   efe80:      	adrp	x16, 0xfc000
   efe84:      	ldr	x17, [x16, #0x2c8]
   efe88:      	add	x16, x16, #0x2c8
   efe8c:      	br	x17

00000000000efe90 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op9HardSwishENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   efe90:      	adrp	x16, 0xfc000
   efe94:      	ldr	x17, [x16, #0x2d0]
   efe98:      	add	x16, x16, #0x2d0
   efe9c:      	br	x17

00000000000efea0 <_ZN5mizar28__register__Npu__HardSwish__Ev@plt>:
   efea0:      	adrp	x16, 0xfc000
   efea4:      	ldr	x17, [x16, #0x2d8]
   efea8:      	add	x16, x16, #0x2d8
   efeac:      	br	x17

00000000000efeb0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuHardSwishEJEEC2ES3_@plt>:
   efeb0:      	adrp	x16, 0xfc000
   efeb4:      	ldr	x17, [x16, #0x2e0]
   efeb8:      	add	x16, x16, #0x2e0
   efebc:      	br	x17

00000000000efec0 <_ZN4hiai2op9HardSwish9__input_xEv@plt>:
   efec0:      	adrp	x16, 0xfc000
   efec4:      	ldr	x17, [x16, #0x2e8]
   efec8:      	add	x16, x16, #0x2e8
   efecc:      	br	x17

00000000000efed0 <_ZN5mizar6detail14MakeStringImplIJPKclllEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   efed0:      	adrp	x16, 0xfc000
   efed4:      	ldr	x17, [x16, #0x2f0]
   efed8:      	add	x16, x16, #0x2f0
   efedc:      	br	x17

00000000000efee0 <_ZN4hiai2op12InstanceNorm11set_input_xERKN2ge8OperatorE@plt>:
   efee0:      	adrp	x16, 0xfc000
   efee4:      	ldr	x17, [x16, #0x2f8]
   efee8:      	add	x16, x16, #0x2f8
   efeec:      	br	x17

00000000000efef0 <_ZN4hiai2op12InstanceNorm15set_input_gammaERKN2ge8OperatorE@plt>:
   efef0:      	adrp	x16, 0xfc000
   efef4:      	ldr	x17, [x16, #0x300]
   efef8:      	add	x16, x16, #0x300
   efefc:      	br	x17

00000000000eff00 <_ZN4hiai2op12InstanceNorm14set_input_betaERKN2ge8OperatorE@plt>:
   eff00:      	adrp	x16, 0xfc000
   eff04:      	ldr	x17, [x16, #0x308]
   eff08:      	add	x16, x16, #0x308
   eff0c:      	br	x17

00000000000eff10 <_ZN4hiai2op12InstanceNorm16set_attr_epsilonEf@plt>:
   eff10:      	adrp	x16, 0xfc000
   eff14:      	ldr	x17, [x16, #0x310]
   eff18:      	add	x16, x16, #0x310
   eff1c:      	br	x17

00000000000eff20 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op12InstanceNormENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   eff20:      	adrp	x16, 0xfc000
   eff24:      	ldr	x17, [x16, #0x318]
   eff28:      	add	x16, x16, #0x318
   eff2c:      	br	x17

00000000000eff30 <_ZN5mizar31__register__Npu__InstanceNorm__Ev@plt>:
   eff30:      	adrp	x16, 0xfc000
   eff34:      	ldr	x17, [x16, #0x320]
   eff38:      	add	x16, x16, #0x320
   eff3c:      	br	x17

00000000000eff40 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_15NpuInstanceNormEJEEC2ES3_@plt>:
   eff40:      	adrp	x16, 0xfc000
   eff44:      	ldr	x17, [x16, #0x328]
   eff48:      	add	x16, x16, #0x328
   eff4c:      	br	x17

00000000000eff50 <_ZN5mizar6detail14MakeStringImplIPKcJlllEEEvRNSt6__ndk119basic_ostringstreamIcNS4_11char_traitsIcEENS4_9allocatorIcEEEERKT_DpRKT0_@plt>:
   eff50:      	adrp	x16, 0xfc000
   eff54:      	ldr	x17, [x16, #0x330]
   eff58:      	add	x16, x16, #0x330
   eff5c:      	br	x17

00000000000eff60 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
   eff60:      	adrp	x16, 0xfc000
   eff64:      	ldr	x17, [x16, #0x338]
   eff68:      	add	x16, x16, #0x338
   eff6c:      	br	x17

00000000000eff70 <_ZN4hiai2op12InstanceNorm9__input_xEv@plt>:
   eff70:      	adrp	x16, 0xfc000
   eff74:      	ldr	x17, [x16, #0x340]
   eff78:      	add	x16, x16, #0x340
   eff7c:      	br	x17

00000000000eff80 <_ZN4hiai2op12InstanceNorm12__input_betaEv@plt>:
   eff80:      	adrp	x16, 0xfc000
   eff84:      	ldr	x17, [x16, #0x348]
   eff88:      	add	x16, x16, #0x348
   eff8c:      	br	x17

00000000000eff90 <_ZN4hiai2op12InstanceNorm18__attr_data_formatEv@plt>:
   eff90:      	adrp	x16, 0xfc000
   eff94:      	ldr	x17, [x16, #0x350]
   eff98:      	add	x16, x16, #0x350
   eff9c:      	br	x17

00000000000effa0 <_ZN4hiai2op12InstanceNorm14__attr_epsilonEv@plt>:
   effa0:      	adrp	x16, 0xfc000
   effa4:      	ldr	x17, [x16, #0x358]
   effa8:      	add	x16, x16, #0x358
   effac:      	br	x17

00000000000effb0 <_ZN4hiai2op10Activation23set_attr_negative_slopeEf@plt>:
   effb0:      	adrp	x16, 0xfc000
   effb4:      	ldr	x17, [x16, #0x360]
   effb8:      	add	x16, x16, #0x360
   effbc:      	br	x17

00000000000effc0 <_ZN5mizar28__register__Npu__LeakyRelu__Ev@plt>:
   effc0:      	adrp	x16, 0xfc000
   effc4:      	ldr	x17, [x16, #0x368]
   effc8:      	add	x16, x16, #0x368
   effcc:      	br	x17

00000000000effd0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuLeakyReluEJEEC2ES3_@plt>:
   effd0:      	adrp	x16, 0xfc000
   effd4:      	ldr	x17, [x16, #0x370]
   effd8:      	add	x16, x16, #0x370
   effdc:      	br	x17

00000000000effe0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op6MatMulENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   effe0:      	adrp	x16, 0xfc000
   effe4:      	ldr	x17, [x16, #0x378]
   effe8:      	add	x16, x16, #0x378
   effec:      	br	x17

00000000000efff0 <_ZN4hiai2op6MatMul21set_attr_transpose_x1Eb@plt>:
   efff0:      	adrp	x16, 0xfc000
   efff4:      	ldr	x17, [x16, #0x380]
   efff8:      	add	x16, x16, #0x380
   efffc:      	br	x17

00000000000f0000 <_ZN4hiai2op6MatMul21set_attr_transpose_x2Eb@plt>:
   f0000:      	adrp	x16, 0xfc000
   f0004:      	ldr	x17, [x16, #0x388]
   f0008:      	add	x16, x16, #0x388
   f000c:      	br	x17

00000000000f0010 <_ZN5mizar15DimsVectorUtils8ToStringIlvEENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_6vectorIT_NS6_ISA_EEEE@plt>:
   f0010:      	adrp	x16, 0xfc000
   f0014:      	ldr	x17, [x16, #0x390]
   f0018:      	add	x16, x16, #0x390
   f001c:      	br	x17

00000000000f0020 <_ZN5mizar6detail14MakeStringImplIJPKcS3_S3_S3_EEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   f0020:      	adrp	x16, 0xfc000
   f0024:      	ldr	x17, [x16, #0x398]
   f0028:      	add	x16, x16, #0x398
   f002c:      	br	x17

00000000000f0030 <_ZN4hiai2op4TileC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0030:      	adrp	x16, 0xfc000
   f0034:      	ldr	x17, [x16, #0x3a0]
   f0038:      	add	x16, x16, #0x3a0
   f003c:      	br	x17

00000000000f0040 <_ZN4hiai2op11BatchMatMulC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0040:      	adrp	x16, 0xfc000
   f0044:      	ldr	x17, [x16, #0x3a8]
   f0048:      	add	x16, x16, #0x3a8
   f004c:      	br	x17

00000000000f0050 <_ZN4hiai2op11BatchMatMul15set_attr_adj_x1Eb@plt>:
   f0050:      	adrp	x16, 0xfc000
   f0054:      	ldr	x17, [x16, #0x3b0]
   f0058:      	add	x16, x16, #0x3b0
   f005c:      	br	x17

00000000000f0060 <_ZN4hiai2op11BatchMatMul15set_attr_adj_x2Eb@plt>:
   f0060:      	adrp	x16, 0xfc000
   f0064:      	ldr	x17, [x16, #0x3b8]
   f0068:      	add	x16, x16, #0x3b8
   f006c:      	br	x17

00000000000f0070 <_ZNSt6__ndk19to_stringEl@plt>:
   f0070:      	adrp	x16, 0xfc000
   f0074:      	ldr	x17, [x16, #0x3c0]
   f0078:      	add	x16, x16, #0x3c0
   f007c:      	br	x17

00000000000f0080 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   f0080:      	adrp	x16, 0xfc000
   f0084:      	ldr	x17, [x16, #0x3c8]
   f0088:      	add	x16, x16, #0x3c8
   f008c:      	br	x17

00000000000f0090 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   f0090:      	adrp	x16, 0xfc000
   f0094:      	ldr	x17, [x16, #0x3d0]
   f0098:      	add	x16, x16, #0x3d0
   f009c:      	br	x17

00000000000f00a0 <_ZN5mizar25__register__Npu__MatMul__Ev@plt>:
   f00a0:      	adrp	x16, 0xfc000
   f00a4:      	ldr	x17, [x16, #0x3d8]
   f00a8:      	add	x16, x16, #0x3d8
   f00ac:      	br	x17

00000000000f00b0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuMatMulEJEEC2ES3_@plt>:
   f00b0:      	adrp	x16, 0xfc000
   f00b4:      	ldr	x17, [x16, #0x3e0]
   f00b8:      	add	x16, x16, #0x3e0
   f00bc:      	br	x17

00000000000f00c0 <_ZN4hiai2op6MatMul10__input_x1Ev@plt>:
   f00c0:      	adrp	x16, 0xfc000
   f00c4:      	ldr	x17, [x16, #0x3e8]
   f00c8:      	add	x16, x16, #0x3e8
   f00cc:      	br	x17

00000000000f00d0 <_ZN4hiai2op6MatMul21__optional_input_biasEv@plt>:
   f00d0:      	adrp	x16, 0xfc000
   f00d4:      	ldr	x17, [x16, #0x3f0]
   f00d8:      	add	x16, x16, #0x3f0
   f00dc:      	br	x17

00000000000f00e0 <_ZN4hiai2op6MatMul19__attr_transpose_x1Ev@plt>:
   f00e0:      	adrp	x16, 0xfc000
   f00e4:      	ldr	x17, [x16, #0x3f8]
   f00e8:      	add	x16, x16, #0x3f8
   f00ec:      	br	x17

00000000000f00f0 <_ZN4hiai2op6MatMul19__attr_transpose_x2Ev@plt>:
   f00f0:      	adrp	x16, 0xfc000
   f00f4:      	ldr	x17, [x16, #0x400]
   f00f8:      	add	x16, x16, #0x400
   f00fc:      	br	x17

00000000000f0100 <_ZN5mizar6detail14MakeStringImplIPKcJS3_S3_EEEvRNSt6__ndk119basic_ostringstreamIcNS4_11char_traitsIcEENS4_9allocatorIcEEEERKT_DpRKT0_@plt>:
   f0100:      	adrp	x16, 0xfc000
   f0104:      	ldr	x17, [x16, #0x408]
   f0108:      	add	x16, x16, #0x408
   f010c:      	br	x17

00000000000f0110 <_ZN4hiai2op4Tile17__input_multiplesEv@plt>:
   f0110:      	adrp	x16, 0xfc000
   f0114:      	ldr	x17, [x16, #0x410]
   f0118:      	add	x16, x16, #0x410
   f011c:      	br	x17

00000000000f0120 <_ZN4hiai2op11BatchMatMul10__input_x2Ev@plt>:
   f0120:      	adrp	x16, 0xfc000
   f0124:      	ldr	x17, [x16, #0x418]
   f0128:      	add	x16, x16, #0x418
   f012c:      	br	x17

00000000000f0130 <_ZN4hiai2op11BatchMatMul13__attr_adj_x1Ev@plt>:
   f0130:      	adrp	x16, 0xfc000
   f0134:      	ldr	x17, [x16, #0x420]
   f0138:      	add	x16, x16, #0x420
   f013c:      	br	x17

00000000000f0140 <_ZN4hiai2op11BatchMatMul13__attr_adj_x2Ev@plt>:
   f0140:      	adrp	x16, 0xfc000
   f0144:      	ldr	x17, [x16, #0x428]
   f0148:      	add	x16, x16, #0x428
   f014c:      	br	x17

00000000000f0150 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op7EltwiseENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0150:      	adrp	x16, 0xfc000
   f0154:      	ldr	x17, [x16, #0x430]
   f0158:      	add	x16, x16, #0x430
   f015c:      	br	x17

00000000000f0160 <_ZN4hiai2op7Eltwise10set_attr_NEl@plt>:
   f0160:      	adrp	x16, 0xfc000
   f0164:      	ldr	x17, [x16, #0x438]
   f0168:      	add	x16, x16, #0x438
   f016c:      	br	x17

00000000000f0170 <_ZN4hiai2op7Eltwise13set_attr_modeEl@plt>:
   f0170:      	adrp	x16, 0xfc000
   f0174:      	ldr	x17, [x16, #0x440]
   f0178:      	add	x16, x16, #0x440
   f017c:      	br	x17

00000000000f0180 <_ZN4hiai2op7Eltwise14set_attr_coeffENSt6__ndk16vectorIfNS2_9allocatorIfEEEE@plt>:
   f0180:      	adrp	x16, 0xfc000
   f0184:      	ldr	x17, [x16, #0x448]
   f0188:      	add	x16, x16, #0x448
   f018c:      	br	x17

00000000000f0190 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   f0190:      	adrp	x16, 0xfc000
   f0194:      	ldr	x17, [x16, #0x450]
   f0198:      	add	x16, x16, #0x450
   f019c:      	br	x17

00000000000f01a0 <_ZN5mizar30__register__Npu__OrigEltwise__Ev@plt>:
   f01a0:      	adrp	x16, 0xfc000
   f01a4:      	ldr	x17, [x16, #0x458]
   f01a8:      	add	x16, x16, #0x458
   f01ac:      	br	x17

00000000000f01b0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_14NpuOrigEltwiseEJEEC2ES3_@plt>:
   f01b0:      	adrp	x16, 0xfc000
   f01b4:      	ldr	x17, [x16, #0x460]
   f01b8:      	add	x16, x16, #0x460
   f01bc:      	br	x17

00000000000f01c0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIN5mizar3fbs24OrigEltwiseOperationTypeENS2_14NpuEltwiseModeEEENS_22__unordered_map_hasherIS4_S6_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE25__emplace_unique_key_argsIS4_JRKNS_4pairIKS4_S5_EEEEENSJ_INS_15__hash_iteratorIPNS_11__hash_nodeIS6_PvEEEEbEERKT_DpOT0_@plt>:
   f01c0:      	adrp	x16, 0xfc000
   f01c4:      	ldr	x17, [x16, #0x468]
   f01c8:      	add	x16, x16, #0x468
   f01cc:      	br	x17

00000000000f01d0 <_ZNSt6__ndk112__next_primeEm@plt>:
   f01d0:      	adrp	x16, 0xfc000
   f01d4:      	ldr	x17, [x16, #0x470]
   f01d8:      	add	x16, x16, #0x470
   f01dc:      	br	x17

00000000000f01e0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIN5mizar3fbs24OrigEltwiseOperationTypeENS2_14NpuEltwiseModeEEENS_22__unordered_map_hasherIS4_S6_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE11__do_rehashILb1EEEvm@plt>:
   f01e0:      	adrp	x16, 0xfc000
   f01e4:      	ldr	x17, [x16, #0x478]
   f01e8:      	add	x16, x16, #0x478
   f01ec:      	br	x17

00000000000f01f0 <_ZN4hiai2op7Eltwise12__dy_input_xEv@plt>:
   f01f0:      	adrp	x16, 0xfc000
   f01f4:      	ldr	x17, [x16, #0x480]
   f01f8:      	add	x16, x16, #0x480
   f01fc:      	br	x17

00000000000f0200 <_ZN4hiai2op7Eltwise17__required_attr_NEv@plt>:
   f0200:      	adrp	x16, 0xfc000
   f0204:      	ldr	x17, [x16, #0x488]
   f0208:      	add	x16, x16, #0x488
   f020c:      	br	x17

00000000000f0210 <_ZN4hiai2op7Eltwise11__attr_modeEv@plt>:
   f0210:      	adrp	x16, 0xfc000
   f0214:      	ldr	x17, [x16, #0x490]
   f0218:      	add	x16, x16, #0x490
   f021c:      	br	x17

00000000000f0220 <_ZN4hiai2op7Eltwise12__attr_coeffEv@plt>:
   f0220:      	adrp	x16, 0xfc000
   f0224:      	ldr	x17, [x16, #0x498]
   f0228:      	add	x16, x16, #0x498
   f022c:      	br	x17

00000000000f0230 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3ExpENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0230:      	adrp	x16, 0xfc000
   f0234:      	ldr	x17, [x16, #0x4a0]
   f0238:      	add	x16, x16, #0x4a0
   f023c:      	br	x17

00000000000f0240 <_ZN4hiai2op3Exp13set_attr_baseEf@plt>:
   f0240:      	adrp	x16, 0xfc000
   f0244:      	ldr	x17, [x16, #0x4a8]
   f0248:      	add	x16, x16, #0x4a8
   f024c:      	br	x17

00000000000f0250 <_ZN4hiai2op3Exp14set_attr_scaleEf@plt>:
   f0250:      	adrp	x16, 0xfc000
   f0254:      	ldr	x17, [x16, #0x4b0]
   f0258:      	add	x16, x16, #0x4b0
   f025c:      	br	x17

00000000000f0260 <_ZN4hiai2op3Exp14set_attr_shiftEf@plt>:
   f0260:      	adrp	x16, 0xfc000
   f0264:      	ldr	x17, [x16, #0x4b8]
   f0268:      	add	x16, x16, #0x4b8
   f026c:      	br	x17

00000000000f0270 <_ZN5mizar26__register__Npu__OrigExp__Ev@plt>:
   f0270:      	adrp	x16, 0xfc000
   f0274:      	ldr	x17, [x16, #0x4c0]
   f0278:      	add	x16, x16, #0x4c0
   f027c:      	br	x17

00000000000f0280 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuOrigExpEJEEC2ES3_@plt>:
   f0280:      	adrp	x16, 0xfc000
   f0284:      	ldr	x17, [x16, #0x4c8]
   f0288:      	add	x16, x16, #0x4c8
   f028c:      	br	x17

00000000000f0290 <_ZN4hiai2op3Exp9__input_xEv@plt>:
   f0290:      	adrp	x16, 0xfc000
   f0294:      	ldr	x17, [x16, #0x4d0]
   f0298:      	add	x16, x16, #0x4d0
   f029c:      	br	x17

00000000000f02a0 <_ZN4hiai2op3Exp11__attr_baseEv@plt>:
   f02a0:      	adrp	x16, 0xfc000
   f02a4:      	ldr	x17, [x16, #0x4d8]
   f02a8:      	add	x16, x16, #0x4d8
   f02ac:      	br	x17

00000000000f02b0 <_ZN4hiai2op3Exp12__attr_scaleEv@plt>:
   f02b0:      	adrp	x16, 0xfc000
   f02b4:      	ldr	x17, [x16, #0x4e0]
   f02b8:      	add	x16, x16, #0x4e0
   f02bc:      	br	x17

00000000000f02c0 <_ZN4hiai2op3Exp12__attr_shiftEv@plt>:
   f02c0:      	adrp	x16, 0xfc000
   f02c4:      	ldr	x17, [x16, #0x4e8]
   f02c8:      	add	x16, x16, #0x4e8
   f02cc:      	br	x17

00000000000f02d0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3LogENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f02d0:      	adrp	x16, 0xfc000
   f02d4:      	ldr	x17, [x16, #0x4f0]
   f02d8:      	add	x16, x16, #0x4f0
   f02dc:      	br	x17

00000000000f02e0 <_ZN4hiai2op3Log13set_attr_baseEf@plt>:
   f02e0:      	adrp	x16, 0xfc000
   f02e4:      	ldr	x17, [x16, #0x4f8]
   f02e8:      	add	x16, x16, #0x4f8
   f02ec:      	br	x17

00000000000f02f0 <_ZN4hiai2op3Log14set_attr_scaleEf@plt>:
   f02f0:      	adrp	x16, 0xfc000
   f02f4:      	ldr	x17, [x16, #0x500]
   f02f8:      	add	x16, x16, #0x500
   f02fc:      	br	x17

00000000000f0300 <_ZN4hiai2op3Log14set_attr_shiftEf@plt>:
   f0300:      	adrp	x16, 0xfc000
   f0304:      	ldr	x17, [x16, #0x508]
   f0308:      	add	x16, x16, #0x508
   f030c:      	br	x17

00000000000f0310 <_ZN5mizar26__register__Npu__OrigLog__Ev@plt>:
   f0310:      	adrp	x16, 0xfc000
   f0314:      	ldr	x17, [x16, #0x510]
   f0318:      	add	x16, x16, #0x510
   f031c:      	br	x17

00000000000f0320 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuOrigLogEJEEC2ES3_@plt>:
   f0320:      	adrp	x16, 0xfc000
   f0324:      	ldr	x17, [x16, #0x518]
   f0328:      	add	x16, x16, #0x518
   f032c:      	br	x17

00000000000f0330 <_ZN4hiai2op3Log9__input_xEv@plt>:
   f0330:      	adrp	x16, 0xfc000
   f0334:      	ldr	x17, [x16, #0x520]
   f0338:      	add	x16, x16, #0x520
   f033c:      	br	x17

00000000000f0340 <_ZN4hiai2op3Log11__attr_baseEv@plt>:
   f0340:      	adrp	x16, 0xfc000
   f0344:      	ldr	x17, [x16, #0x528]
   f0348:      	add	x16, x16, #0x528
   f034c:      	br	x17

00000000000f0350 <_ZN4hiai2op3Log12__attr_scaleEv@plt>:
   f0350:      	adrp	x16, 0xfc000
   f0354:      	ldr	x17, [x16, #0x530]
   f0358:      	add	x16, x16, #0x530
   f035c:      	br	x17

00000000000f0360 <_ZN4hiai2op3Log12__attr_shiftEv@plt>:
   f0360:      	adrp	x16, 0xfc000
   f0364:      	ldr	x17, [x16, #0x538]
   f0368:      	add	x16, x16, #0x538
   f036c:      	br	x17

00000000000f0370 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_10shared_ptrIN2ge8OperatorEEEEENS_22__unordered_map_hasherIS7_SC_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SC_SH_SF_Lb1EEENS5_ISC_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSR_IJEEEEEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeISC_PvEEEEbEERKT_DpOT0_@plt>:
   f0370:      	adrp	x16, 0xfc000
   f0374:      	ldr	x17, [x16, #0x540]
   f0378:      	add	x16, x16, #0x540
   f037c:      	br	x17

00000000000f0380 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op7PermuteENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0380:      	adrp	x16, 0xfc000
   f0384:      	ldr	x17, [x16, #0x548]
   f0388:      	add	x16, x16, #0x548
   f038c:      	br	x17

00000000000f0390 <_ZN4hiai2op7Permute14set_attr_orderENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0390:      	adrp	x16, 0xfc000
   f0394:      	ldr	x17, [x16, #0x550]
   f0398:      	add	x16, x16, #0x550
   f039c:      	br	x17

00000000000f03a0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op7PermuteENS_9allocatorIS3_EEEC2B8ne180000IJNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f03a0:      	adrp	x16, 0xfc000
   f03a4:      	ldr	x17, [x16, #0x558]
   f03a8:      	add	x16, x16, #0x558
   f03ac:      	br	x17

00000000000f03b0 <_ZN5mizar30__register__Npu__OrigPermute__Ev@plt>:
   f03b0:      	adrp	x16, 0xfc000
   f03b4:      	ldr	x17, [x16, #0x560]
   f03b8:      	add	x16, x16, #0x560
   f03bc:      	br	x17

00000000000f03c0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_14NpuOrigPermuteEJEEC2ES3_@plt>:
   f03c0:      	adrp	x16, 0xfc000
   f03c4:      	ldr	x17, [x16, #0x568]
   f03c8:      	add	x16, x16, #0x568
   f03cc:      	br	x17

00000000000f03d0 <memcmp@plt>:
   f03d0:      	adrp	x16, 0xfc000
   f03d4:      	ldr	x17, [x16, #0x570]
   f03d8:      	add	x16, x16, #0x570
   f03dc:      	br	x17

00000000000f03e0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_10shared_ptrIN2ge8OperatorEEEEENS_22__unordered_map_hasherIS7_SC_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SC_SH_SF_Lb1EEENS5_ISC_EEE11__do_rehashILb1EEEvm@plt>:
   f03e0:      	adrp	x16, 0xfc000
   f03e4:      	ldr	x17, [x16, #0x578]
   f03e8:      	add	x16, x16, #0x578
   f03ec:      	br	x17

00000000000f03f0 <_ZN4hiai2op7Permute9__input_xEv@plt>:
   f03f0:      	adrp	x16, 0xfc000
   f03f4:      	ldr	x17, [x16, #0x580]
   f03f8:      	add	x16, x16, #0x580
   f03fc:      	br	x17

00000000000f0400 <_ZN4hiai2op7Permute12__attr_orderEv@plt>:
   f0400:      	adrp	x16, 0xfc000
   f0404:      	ldr	x17, [x16, #0x588]
   f0408:      	add	x16, x16, #0x588
   f040c:      	br	x17

00000000000f0410 <_ZN5mizar18GetRealWeightShapeERKNSt6__ndk16vectorIlNS0_9allocatorIlEEEES6_@plt>:
   f0410:      	adrp	x16, 0xfc000
   f0414:      	ldr	x17, [x16, #0x590]
   f0418:      	add	x16, x16, #0x590
   f041c:      	br	x17

00000000000f0420 <_ZNSt6__ndk16vectorIlNS_9allocatorIlEEE18__assign_with_sizeB8ne180000IPlS5_EEvT_T0_l@plt>:
   f0420:      	adrp	x16, 0xfc000
   f0424:      	ldr	x17, [x16, #0x598]
   f0428:      	add	x16, x16, #0x598
   f042c:      	br	x17

00000000000f0430 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5ScaleENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0430:      	adrp	x16, 0xfc000
   f0434:      	ldr	x17, [x16, #0x5a0]
   f0438:      	add	x16, x16, #0x5a0
   f043c:      	br	x17

00000000000f0440 <_ZN5mizar28__register__Npu__OrigScale__Ev@plt>:
   f0440:      	adrp	x16, 0xfc000
   f0444:      	ldr	x17, [x16, #0x5a8]
   f0448:      	add	x16, x16, #0x5a8
   f044c:      	br	x17

00000000000f0450 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuOrigScaleEJEEC2ES3_@plt>:
   f0450:      	adrp	x16, 0xfc000
   f0454:      	ldr	x17, [x16, #0x5b0]
   f0458:      	add	x16, x16, #0x5b0
   f045c:      	br	x17

00000000000f0460 <_ZN4hiai2op5Scale9__input_xEv@plt>:
   f0460:      	adrp	x16, 0xfc000
   f0464:      	ldr	x17, [x16, #0x5b8]
   f0468:      	add	x16, x16, #0x5b8
   f046c:      	br	x17

00000000000f0470 <_ZN4hiai2op5Scale21__optional_input_biasEv@plt>:
   f0470:      	adrp	x16, 0xfc000
   f0474:      	ldr	x17, [x16, #0x5c0]
   f0478:      	add	x16, x16, #0x5c0
   f047c:      	br	x17

00000000000f0480 <_ZN4hiai2op5Scale11__attr_axisEv@plt>:
   f0480:      	adrp	x16, 0xfc000
   f0484:      	ldr	x17, [x16, #0x5c8]
   f0488:      	add	x16, x16, #0x5c8
   f048c:      	br	x17

00000000000f0490 <_ZN4hiai2op5Scale15__attr_num_axesEv@plt>:
   f0490:      	adrp	x16, 0xfc000
   f0494:      	ldr	x17, [x16, #0x5d0]
   f0498:      	add	x16, x16, #0x5d0
   f049c:      	br	x17

00000000000f04a0 <_ZN4hiai2op5Scale22__attr_scale_from_blobEv@plt>:
   f04a0:      	adrp	x16, 0xfc000
   f04a4:      	ldr	x17, [x16, #0x5d8]
   f04a8:      	add	x16, x16, #0x5d8
   f04ac:      	br	x17

00000000000f04b0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5SliceENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f04b0:      	adrp	x16, 0xfc000
   f04b4:      	ldr	x17, [x16, #0x5e0]
   f04b8:      	add	x16, x16, #0x5e0
   f04bc:      	br	x17

00000000000f04c0 <_ZN5mizar28__register__Npu__OrigSlice__Ev@plt>:
   f04c0:      	adrp	x16, 0xfc000
   f04c4:      	ldr	x17, [x16, #0x5e8]
   f04c8:      	add	x16, x16, #0x5e8
   f04cc:      	br	x17

00000000000f04d0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuOrigSliceEJEEC2ES3_@plt>:
   f04d0:      	adrp	x16, 0xfc000
   f04d4:      	ldr	x17, [x16, #0x5f0]
   f04d8:      	add	x16, x16, #0x5f0
   f04dc:      	br	x17

00000000000f04e0 <_ZN4hiai2op5Slice9__input_xEv@plt>:
   f04e0:      	adrp	x16, 0xfc000
   f04e4:      	ldr	x17, [x16, #0x5f8]
   f04e8:      	add	x16, x16, #0x5f8
   f04ec:      	br	x17

00000000000f04f0 <_ZN4hiai2op5Slice12__input_sizeEv@plt>:
   f04f0:      	adrp	x16, 0xfc000
   f04f4:      	ldr	x17, [x16, #0x600]
   f04f8:      	add	x16, x16, #0x600
   f04fc:      	br	x17

00000000000f0500 <_ZN4hiai2op9MirrorPadC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0500:      	adrp	x16, 0xfc000
   f0504:      	ldr	x17, [x16, #0x608]
   f0508:      	add	x16, x16, #0x608
   f050c:      	br	x17

00000000000f0510 <_ZN4hiai2op9MirrorPad13set_attr_modeENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0510:      	adrp	x16, 0xfc000
   f0514:      	ldr	x17, [x16, #0x610]
   f0518:      	add	x16, x16, #0x610
   f051c:      	br	x17

00000000000f0520 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5PadV2ENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0520:      	adrp	x16, 0xfc000
   f0524:      	ldr	x17, [x16, #0x618]
   f0528:      	add	x16, x16, #0x618
   f052c:      	br	x17

00000000000f0530 <_ZN5mizar22__register__Npu__Pad__Ev@plt>:
   f0530:      	adrp	x16, 0xfc000
   f0534:      	ldr	x17, [x16, #0x620]
   f0538:      	add	x16, x16, #0x620
   f053c:      	br	x17

00000000000f0540 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_6NpuPadEJEEC2ES3_@plt>:
   f0540:      	adrp	x16, 0xfc000
   f0544:      	ldr	x17, [x16, #0x628]
   f0548:      	add	x16, x16, #0x628
   f054c:      	br	x17

00000000000f0550 <_ZN4hiai2op5PadV29__input_xEv@plt>:
   f0550:      	adrp	x16, 0xfc000
   f0554:      	ldr	x17, [x16, #0x630]
   f0558:      	add	x16, x16, #0x630
   f055c:      	br	x17

00000000000f0560 <_ZN4hiai2op5PadV223__input_constant_valuesEv@plt>:
   f0560:      	adrp	x16, 0xfc000
   f0564:      	ldr	x17, [x16, #0x638]
   f0568:      	add	x16, x16, #0x638
   f056c:      	br	x17

00000000000f0570 <_ZN4hiai2op9MirrorPad16__input_paddingsEv@plt>:
   f0570:      	adrp	x16, 0xfc000
   f0574:      	ldr	x17, [x16, #0x640]
   f0578:      	add	x16, x16, #0x640
   f057c:      	br	x17

00000000000f0580 <_ZN4hiai2op9MirrorPad20__required_attr_modeEv@plt>:
   f0580:      	adrp	x16, 0xfc000
   f0584:      	ldr	x17, [x16, #0x648]
   f0588:      	add	x16, x16, #0x648
   f058c:      	br	x17

00000000000f0590 <_ZNKSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN5mizar18NpuPoolingDPadModeEEENS_22__unordered_map_hasherIS7_SA_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SA_SF_SD_Lb1EEENS5_ISA_EEE4findIS7_EENS_21__hash_const_iteratorIPNS_11__hash_nodeISA_PvEEEERKT_@plt>:
   f0590:      	adrp	x16, 0xfc000
   f0594:      	ldr	x17, [x16, #0x650]
   f0598:      	add	x16, x16, #0x650
   f059c:      	br	x17

00000000000f05a0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op8PoolingDENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f05a0:      	adrp	x16, 0xfc000
   f05a4:      	ldr	x17, [x16, #0x658]
   f05a8:      	add	x16, x16, #0x658
   f05ac:      	br	x17

00000000000f05b0 <_ZN4hiai2op8PoolingD13set_attr_modeEl@plt>:
   f05b0:      	adrp	x16, 0xfc000
   f05b4:      	ldr	x17, [x16, #0x660]
   f05b8:      	add	x16, x16, #0x660
   f05bc:      	br	x17

00000000000f05c0 <_ZN4hiai2op8PoolingD17set_attr_pad_modeEl@plt>:
   f05c0:      	adrp	x16, 0xfc000
   f05c4:      	ldr	x17, [x16, #0x668]
   f05c8:      	add	x16, x16, #0x668
   f05cc:      	br	x17

00000000000f05d0 <_ZN4hiai2op8PoolingD18set_attr_ceil_modeEl@plt>:
   f05d0:      	adrp	x16, 0xfc000
   f05d4:      	ldr	x17, [x16, #0x670]
   f05d8:      	add	x16, x16, #0x670
   f05dc:      	br	x17

00000000000f05e0 <_ZN4hiai2op8PoolingD23set_attr_global_poolingEb@plt>:
   f05e0:      	adrp	x16, 0xfc000
   f05e4:      	ldr	x17, [x16, #0x678]
   f05e8:      	add	x16, x16, #0x678
   f05ec:      	br	x17

00000000000f05f0 <_ZN4hiai2op8PoolingD15set_attr_windowENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f05f0:      	adrp	x16, 0xfc000
   f05f4:      	ldr	x17, [x16, #0x680]
   f05f8:      	add	x16, x16, #0x680
   f05fc:      	br	x17

00000000000f0600 <_ZN4hiai2op8PoolingD15set_attr_strideENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0600:      	adrp	x16, 0xfc000
   f0604:      	ldr	x17, [x16, #0x688]
   f0608:      	add	x16, x16, #0x688
   f060c:      	br	x17

00000000000f0610 <_ZN4hiai2op8PoolingD12set_attr_padENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0610:      	adrp	x16, 0xfc000
   f0614:      	ldr	x17, [x16, #0x690]
   f0618:      	add	x16, x16, #0x690
   f061c:      	br	x17

00000000000f0620 <_ZN4hiai2op8PoolingD18set_attr_data_modeEl@plt>:
   f0620:      	adrp	x16, 0xfc000
   f0624:      	ldr	x17, [x16, #0x698]
   f0628:      	add	x16, x16, #0x698
   f062c:      	br	x17

00000000000f0630 <_ZN4hiai2op10ReduceMeanC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0630:      	adrp	x16, 0xfc000
   f0634:      	ldr	x17, [x16, #0x6a0]
   f0638:      	add	x16, x16, #0x6a0
   f063c:      	br	x17

00000000000f0640 <_ZN4hiai2op10ReduceMean18set_attr_keep_dimsEb@plt>:
   f0640:      	adrp	x16, 0xfc000
   f0644:      	ldr	x17, [x16, #0x6a8]
   f0648:      	add	x16, x16, #0x6a8
   f064c:      	br	x17

00000000000f0650 <_ZN5mizar6detail14MakeStringImplIJPKcS3_S3_EEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   f0650:      	adrp	x16, 0xfc000
   f0654:      	ldr	x17, [x16, #0x6b0]
   f0658:      	add	x16, x16, #0x6b0
   f065c:      	br	x17

00000000000f0660 <_ZN5mizar28__register__Npu__PoolAvg2d__Ev@plt>:
   f0660:      	adrp	x16, 0xfc000
   f0664:      	ldr	x17, [x16, #0x6b8]
   f0668:      	add	x16, x16, #0x6b8
   f066c:      	br	x17

00000000000f0670 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuPoolAvg2dEJEEC2ES3_@plt>:
   f0670:      	adrp	x16, 0xfc000
   f0674:      	ldr	x17, [x16, #0x6c0]
   f0678:      	add	x16, x16, #0x6c0
   f067c:      	br	x17

00000000000f0680 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN5mizar18NpuPoolingDPadModeEEENS_22__unordered_map_hasherIS7_SA_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SA_SF_SD_Lb1EEENS5_ISA_EEE25__emplace_unique_key_argsIS7_JRKNS_4pairIKS7_S9_EEEEENSM_INS_15__hash_iteratorIPNS_11__hash_nodeISA_PvEEEEbEERKT_DpOT0_@plt>:
   f0680:      	adrp	x16, 0xfc000
   f0684:      	ldr	x17, [x16, #0x6c8]
   f0688:      	add	x16, x16, #0x6c8
   f068c:      	br	x17

00000000000f0690 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN5mizar18NpuPoolingDPadModeEEENS_22__unordered_map_hasherIS7_SA_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SA_SF_SD_Lb1EEENS5_ISA_EEE11__do_rehashILb1EEEvm@plt>:
   f0690:      	adrp	x16, 0xfc000
   f0694:      	ldr	x17, [x16, #0x6d0]
   f0698:      	add	x16, x16, #0x6d0
   f069c:      	br	x17

00000000000f06a0 <_ZN4hiai2op10ReduceMean12__input_axesEv@plt>:
   f06a0:      	adrp	x16, 0xfc000
   f06a4:      	ldr	x17, [x16, #0x6d8]
   f06a8:      	add	x16, x16, #0x6d8
   f06ac:      	br	x17

00000000000f06b0 <_ZN4hiai2op10ReduceMean16__attr_keep_dimsEv@plt>:
   f06b0:      	adrp	x16, 0xfc000
   f06b4:      	ldr	x17, [x16, #0x6e0]
   f06b8:      	add	x16, x16, #0x6e0
   f06bc:      	br	x17

00000000000f06c0 <_ZN4hiai2op8PoolingD9__input_xEv@plt>:
   f06c0:      	adrp	x16, 0xfc000
   f06c4:      	ldr	x17, [x16, #0x6e8]
   f06c8:      	add	x16, x16, #0x6e8
   f06cc:      	br	x17

00000000000f06d0 <_ZN4hiai2op8PoolingD11__attr_modeEv@plt>:
   f06d0:      	adrp	x16, 0xfc000
   f06d4:      	ldr	x17, [x16, #0x6f0]
   f06d8:      	add	x16, x16, #0x6f0
   f06dc:      	br	x17

00000000000f06e0 <_ZN4hiai2op8PoolingD15__attr_pad_modeEv@plt>:
   f06e0:      	adrp	x16, 0xfc000
   f06e4:      	ldr	x17, [x16, #0x6f8]
   f06e8:      	add	x16, x16, #0x6f8
   f06ec:      	br	x17

00000000000f06f0 <_ZN4hiai2op8PoolingD21__attr_global_poolingEv@plt>:
   f06f0:      	adrp	x16, 0xfc000
   f06f4:      	ldr	x17, [x16, #0x700]
   f06f8:      	add	x16, x16, #0x700
   f06fc:      	br	x17

00000000000f0700 <_ZN4hiai2op8PoolingD13__attr_windowEv@plt>:
   f0700:      	adrp	x16, 0xfc000
   f0704:      	ldr	x17, [x16, #0x708]
   f0708:      	add	x16, x16, #0x708
   f070c:      	br	x17

00000000000f0710 <_ZN4hiai2op8PoolingD10__attr_padEv@plt>:
   f0710:      	adrp	x16, 0xfc000
   f0714:      	ldr	x17, [x16, #0x710]
   f0718:      	add	x16, x16, #0x710
   f071c:      	br	x17

00000000000f0720 <_ZN4hiai2op8PoolingD13__attr_strideEv@plt>:
   f0720:      	adrp	x16, 0xfc000
   f0724:      	ldr	x17, [x16, #0x718]
   f0728:      	add	x16, x16, #0x718
   f072c:      	br	x17

00000000000f0730 <_ZN4hiai2op8PoolingD16__attr_ceil_modeEv@plt>:
   f0730:      	adrp	x16, 0xfc000
   f0734:      	ldr	x17, [x16, #0x720]
   f0738:      	add	x16, x16, #0x720
   f073c:      	br	x17

00000000000f0740 <_ZN4hiai2op8PoolingD16__attr_data_modeEv@plt>:
   f0740:      	adrp	x16, 0xfc000
   f0744:      	ldr	x17, [x16, #0x728]
   f0748:      	add	x16, x16, #0x728
   f074c:      	br	x17

00000000000f0750 <_ZN4hiai2op19MaxPoolWithArgmaxV2C2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0750:      	adrp	x16, 0xfc000
   f0754:      	ldr	x17, [x16, #0x730]
   f0758:      	add	x16, x16, #0x730
   f075c:      	br	x17

00000000000f0760 <_ZN4hiai2op19MaxPoolWithArgmaxV214set_attr_ksizeENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0760:      	adrp	x16, 0xfc000
   f0764:      	ldr	x17, [x16, #0x738]
   f0768:      	add	x16, x16, #0x738
   f076c:      	br	x17

00000000000f0770 <_ZN4hiai2op19MaxPoolWithArgmaxV216set_attr_stridesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0770:      	adrp	x16, 0xfc000
   f0774:      	ldr	x17, [x16, #0x740]
   f0778:      	add	x16, x16, #0x740
   f077c:      	br	x17

00000000000f0780 <_ZN4hiai2op19MaxPoolWithArgmaxV213set_attr_padsENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0780:      	adrp	x16, 0xfc000
   f0784:      	ldr	x17, [x16, #0x748]
   f0788:      	add	x16, x16, #0x748
   f078c:      	br	x17

00000000000f0790 <_ZN4hiai2op19MaxPoolWithArgmaxV218set_attr_ceil_modeEb@plt>:
   f0790:      	adrp	x16, 0xfc000
   f0794:      	ldr	x17, [x16, #0x750]
   f0798:      	add	x16, x16, #0x750
   f079c:      	br	x17

00000000000f07a0 <_ZN4hiai2op9ReduceMaxC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f07a0:      	adrp	x16, 0xfc000
   f07a4:      	ldr	x17, [x16, #0x758]
   f07a8:      	add	x16, x16, #0x758
   f07ac:      	br	x17

00000000000f07b0 <_ZN4hiai2op9ReduceMax18set_attr_keep_dimsEb@plt>:
   f07b0:      	adrp	x16, 0xfc000
   f07b4:      	ldr	x17, [x16, #0x760]
   f07b8:      	add	x16, x16, #0x760
   f07bc:      	br	x17

00000000000f07c0 <_ZN5mizar28__register__Npu__PoolMax2d__Ev@plt>:
   f07c0:      	adrp	x16, 0xfc000
   f07c4:      	ldr	x17, [x16, #0x768]
   f07c8:      	add	x16, x16, #0x768
   f07cc:      	br	x17

00000000000f07d0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuPoolMax2dEJEEC2ES3_@plt>:
   f07d0:      	adrp	x16, 0xfc000
   f07d4:      	ldr	x17, [x16, #0x770]
   f07d8:      	add	x16, x16, #0x770
   f07dc:      	br	x17

00000000000f07e0 <_ZN4hiai2op9ReduceMax12__input_axesEv@plt>:
   f07e0:      	adrp	x16, 0xfc000
   f07e4:      	ldr	x17, [x16, #0x778]
   f07e8:      	add	x16, x16, #0x778
   f07ec:      	br	x17

00000000000f07f0 <_ZN4hiai2op9ReduceMax16__attr_keep_dimsEv@plt>:
   f07f0:      	adrp	x16, 0xfc000
   f07f4:      	ldr	x17, [x16, #0x780]
   f07f8:      	add	x16, x16, #0x780
   f07fc:      	br	x17

00000000000f0800 <_ZN4hiai2op19MaxPoolWithArgmaxV27__out_yEv@plt>:
   f0800:      	adrp	x16, 0xfc000
   f0804:      	ldr	x17, [x16, #0x788]
   f0808:      	add	x16, x16, #0x788
   f080c:      	br	x17

00000000000f0810 <_ZN4hiai2op19MaxPoolWithArgmaxV221__required_attr_ksizeEv@plt>:
   f0810:      	adrp	x16, 0xfc000
   f0814:      	ldr	x17, [x16, #0x790]
   f0818:      	add	x16, x16, #0x790
   f081c:      	br	x17

00000000000f0820 <_ZN4hiai2op19MaxPoolWithArgmaxV223__required_attr_stridesEv@plt>:
   f0820:      	adrp	x16, 0xfc000
   f0824:      	ldr	x17, [x16, #0x798]
   f0828:      	add	x16, x16, #0x798
   f082c:      	br	x17

00000000000f0830 <_ZN4hiai2op19MaxPoolWithArgmaxV220__required_attr_padsEv@plt>:
   f0830:      	adrp	x16, 0xfc000
   f0834:      	ldr	x17, [x16, #0x7a0]
   f0838:      	add	x16, x16, #0x7a0
   f083c:      	br	x17

00000000000f0840 <_ZN4hiai2op19MaxPoolWithArgmaxV212__attr_dtypeEv@plt>:
   f0840:      	adrp	x16, 0xfc000
   f0844:      	ldr	x17, [x16, #0x7a8]
   f0848:      	add	x16, x16, #0x7a8
   f084c:      	br	x17

00000000000f0850 <_ZN4hiai2op19MaxPoolWithArgmaxV215__attr_dilationEv@plt>:
   f0850:      	adrp	x16, 0xfc000
   f0854:      	ldr	x17, [x16, #0x7b0]
   f0858:      	add	x16, x16, #0x7b0
   f085c:      	br	x17

00000000000f0860 <_ZN4hiai2op19MaxPoolWithArgmaxV216__attr_ceil_modeEv@plt>:
   f0860:      	adrp	x16, 0xfc000
   f0864:      	ldr	x17, [x16, #0x7b8]
   f0868:      	add	x16, x16, #0x7b8
   f086c:      	br	x17

00000000000f0870 <_ZN4hiai2op5PReluC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0870:      	adrp	x16, 0xfc000
   f0874:      	ldr	x17, [x16, #0x7c0]
   f0878:      	add	x16, x16, #0x7c0
   f087c:      	br	x17

00000000000f0880 <_ZN5mizar24__register__Npu__PReLU__Ev@plt>:
   f0880:      	adrp	x16, 0xfc000
   f0884:      	ldr	x17, [x16, #0x7c8]
   f0888:      	add	x16, x16, #0x7c8
   f088c:      	br	x17

00000000000f0890 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_8NpuPReLUEJEEC2ES3_@plt>:
   f0890:      	adrp	x16, 0xfc000
   f0894:      	ldr	x17, [x16, #0x7d0]
   f0898:      	add	x16, x16, #0x7d0
   f089c:      	br	x17

00000000000f08a0 <_ZN4hiai2op5PRelu14__input_weightEv@plt>:
   f08a0:      	adrp	x16, 0xfc000
   f08a4:      	ldr	x17, [x16, #0x7d8]
   f08a8:      	add	x16, x16, #0x7d8
   f08ac:      	br	x17

00000000000f08b0 <_ZN4hiai2op5PRelu18__attr_data_formatEv@plt>:
   f08b0:      	adrp	x16, 0xfc000
   f08b4:      	ldr	x17, [x16, #0x7e0]
   f08b8:      	add	x16, x16, #0x7e0
   f08bc:      	br	x17

00000000000f08c0 <_ZN5mizar9NpuReduce12AddReduceSumERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS2_IN4hiai2op5ConstEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIlNSH_IlEEEERKNSM_IiNSH_IiEEEEbRS5_@plt>:
   f08c0:      	adrp	x16, 0xfc000
   f08c4:      	ldr	x17, [x16, #0x7e8]
   f08c8:      	add	x16, x16, #0x7e8
   f08cc:      	br	x17

00000000000f08d0 <_ZN5mizar9NpuReduce11AddReduceL1ERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS2_IN4hiai2op5ConstEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIlNSH_IlEEEERKNSM_IiNSH_IiEEEEb@plt>:
   f08d0:      	adrp	x16, 0xfc000
   f08d4:      	ldr	x17, [x16, #0x7f0]
   f08d8:      	add	x16, x16, #0x7f0
   f08dc:      	br	x17

00000000000f08e0 <_ZN5mizar9NpuReduce13ReduceConvertIN4hiai2op9ReduceMaxEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS7_INS3_5ConstEEEbRKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f08e0:      	adrp	x16, 0xfc000
   f08e4:      	ldr	x17, [x16, #0x7f8]
   f08e8:      	add	x16, x16, #0x7f8
   f08ec:      	br	x17

00000000000f08f0 <_ZN5mizar9NpuReduce18AddReduceSumSquareERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS2_IN4hiai2op5ConstEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIlNSH_IlEEEERKNSM_IiNSH_IiEEEEb@plt>:
   f08f0:      	adrp	x16, 0xfc000
   f08f4:      	ldr	x17, [x16, #0x800]
   f08f8:      	add	x16, x16, #0x800
   f08fc:      	br	x17

00000000000f0900 <_ZN5mizar9NpuReduce13ReduceConvertIN4hiai2op10ReduceMeanEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS7_INS3_5ConstEEEbRKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f0900:      	adrp	x16, 0xfc000
   f0904:      	ldr	x17, [x16, #0x808]
   f0908:      	add	x16, x16, #0x808
   f090c:      	br	x17

00000000000f0910 <_ZN5mizar9NpuReduce13ReduceConvertIN4hiai2op9ReduceL2DEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_6vectorIiNS6_9allocatorIiEEEEbRKNS6_12basic_stringIcNS6_11char_traitsIcEENSE_IcEEEE@plt>:
   f0910:      	adrp	x16, 0xfc000
   f0914:      	ldr	x17, [x16, #0x810]
   f0918:      	add	x16, x16, #0x810
   f091c:      	br	x17

00000000000f0920 <_ZN5mizar9NpuReduce13ReduceConvertIN4hiai2op9ReduceMinEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS7_INS3_5ConstEEEbRKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f0920:      	adrp	x16, 0xfc000
   f0924:      	ldr	x17, [x16, #0x818]
   f0928:      	add	x16, x16, #0x818
   f092c:      	br	x17

00000000000f0930 <_ZN5mizar9NpuReduce15AddReduceLogSumERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS2_IN4hiai2op5ConstEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_6vectorIlNSH_IlEEEERKNSM_IiNSH_IiEEEEb@plt>:
   f0930:      	adrp	x16, 0xfc000
   f0934:      	ldr	x17, [x16, #0x820]
   f0938:      	add	x16, x16, #0x820
   f093c:      	br	x17

00000000000f0940 <_ZN5mizar9NpuReduce13ReduceConvertIN4hiai2op11ReduceProdDEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_6vectorIiNS6_9allocatorIiEEEEbRKNS6_12basic_stringIcNS6_11char_traitsIcEENSE_IcEEEE@plt>:
   f0940:      	adrp	x16, 0xfc000
   f0944:      	ldr	x17, [x16, #0x828]
   f0948:      	add	x16, x16, #0x828
   f094c:      	br	x17

00000000000f0950 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op15ReduceLogSumExpENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0950:      	adrp	x16, 0xfc000
   f0954:      	ldr	x17, [x16, #0x830]
   f0958:      	add	x16, x16, #0x830
   f095c:      	br	x17

00000000000f0960 <_ZN4hiai2op15ReduceLogSumExp13set_attr_axesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0960:      	adrp	x16, 0xfc000
   f0964:      	ldr	x17, [x16, #0x838]
   f0968:      	add	x16, x16, #0x838
   f096c:      	br	x17

00000000000f0970 <_ZN4hiai2op15ReduceLogSumExp17set_attr_keepdimsEb@plt>:
   f0970:      	adrp	x16, 0xfc000
   f0974:      	ldr	x17, [x16, #0x840]
   f0978:      	add	x16, x16, #0x840
   f097c:      	br	x17

00000000000f0980 <_ZN5mizar9NpuReduce13ReduceConvertIN4hiai2op9ReduceSumEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS7_INS3_5ConstEEEbRKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f0980:      	adrp	x16, 0xfc000
   f0984:      	ldr	x17, [x16, #0x848]
   f0988:      	add	x16, x16, #0x848
   f098c:      	br	x17

00000000000f0990 <_ZN4hiai2op9ReduceSumC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0990:      	adrp	x16, 0xfc000
   f0994:      	ldr	x17, [x16, #0x850]
   f0998:      	add	x16, x16, #0x850
   f099c:      	br	x17

00000000000f09a0 <_ZN4hiai2op9ReduceSum18set_attr_keep_dimsEb@plt>:
   f09a0:      	adrp	x16, 0xfc000
   f09a4:      	ldr	x17, [x16, #0x858]
   f09a8:      	add	x16, x16, #0x858
   f09ac:      	br	x17

00000000000f09b0 <_ZN4hiai2op9ReduceMinC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f09b0:      	adrp	x16, 0xfc000
   f09b4:      	ldr	x17, [x16, #0x860]
   f09b8:      	add	x16, x16, #0x860
   f09bc:      	br	x17

00000000000f09c0 <_ZN4hiai2op9ReduceMin18set_attr_keep_dimsEb@plt>:
   f09c0:      	adrp	x16, 0xfc000
   f09c4:      	ldr	x17, [x16, #0x868]
   f09c8:      	add	x16, x16, #0x868
   f09cc:      	br	x17

00000000000f09d0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op11ReduceProdDENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f09d0:      	adrp	x16, 0xfc000
   f09d4:      	ldr	x17, [x16, #0x870]
   f09d8:      	add	x16, x16, #0x870
   f09dc:      	br	x17

00000000000f09e0 <_ZN4hiai2op11ReduceProdD13set_attr_axesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f09e0:      	adrp	x16, 0xfc000
   f09e4:      	ldr	x17, [x16, #0x878]
   f09e8:      	add	x16, x16, #0x878
   f09ec:      	br	x17

00000000000f09f0 <_ZN4hiai2op11ReduceProdD18set_attr_keep_dimsEb@plt>:
   f09f0:      	adrp	x16, 0xfc000
   f09f4:      	ldr	x17, [x16, #0x880]
   f09f8:      	add	x16, x16, #0x880
   f09fc:      	br	x17

00000000000f0a00 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op9ReduceL2DENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0a00:      	adrp	x16, 0xfc000
   f0a04:      	ldr	x17, [x16, #0x888]
   f0a08:      	add	x16, x16, #0x888
   f0a0c:      	br	x17

00000000000f0a10 <_ZN4hiai2op9ReduceL2D13set_attr_axesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0a10:      	adrp	x16, 0xfc000
   f0a14:      	ldr	x17, [x16, #0x890]
   f0a18:      	add	x16, x16, #0x890
   f0a1c:      	br	x17

00000000000f0a20 <_ZN4hiai2op9ReduceL2D18set_attr_keep_dimsEb@plt>:
   f0a20:      	adrp	x16, 0xfc000
   f0a24:      	ldr	x17, [x16, #0x898]
   f0a28:      	add	x16, x16, #0x898
   f0a2c:      	br	x17

00000000000f0a30 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op6SquareENS_9allocatorIS3_EEEC2B8ne180000IJNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0a30:      	adrp	x16, 0xfc000
   f0a34:      	ldr	x17, [x16, #0x8a0]
   f0a38:      	add	x16, x16, #0x8a0
   f0a3c:      	br	x17

00000000000f0a40 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op10ActivationENS_9allocatorIS3_EEEC2B8ne180000IJNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0a40:      	adrp	x16, 0xfc000
   f0a44:      	ldr	x17, [x16, #0x8a8]
   f0a48:      	add	x16, x16, #0x8a8
   f0a4c:      	br	x17

00000000000f0a50 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4SqrtENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0a50:      	adrp	x16, 0xfc000
   f0a54:      	ldr	x17, [x16, #0x8b0]
   f0a58:      	add	x16, x16, #0x8b0
   f0a5c:      	br	x17

00000000000f0a60 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3ExpENS_9allocatorIS3_EEEC2B8ne180000IJNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0a60:      	adrp	x16, 0xfc000
   f0a64:      	ldr	x17, [x16, #0x8b8]
   f0a68:      	add	x16, x16, #0x8b8
   f0a6c:      	br	x17

00000000000f0a70 <_ZN5mizar25__register__Npu__Reduce__Ev@plt>:
   f0a70:      	adrp	x16, 0xfc000
   f0a74:      	ldr	x17, [x16, #0x8c0]
   f0a78:      	add	x16, x16, #0x8c0
   f0a7c:      	br	x17

00000000000f0a80 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuReduceEJEEC2ES3_@plt>:
   f0a80:      	adrp	x16, 0xfc000
   f0a84:      	ldr	x17, [x16, #0x8c8]
   f0a88:      	add	x16, x16, #0x8c8
   f0a8c:      	br	x17

00000000000f0a90 <_ZN4hiai2op9ReduceMin12__input_axesEv@plt>:
   f0a90:      	adrp	x16, 0xfc000
   f0a94:      	ldr	x17, [x16, #0x8d0]
   f0a98:      	add	x16, x16, #0x8d0
   f0a9c:      	br	x17

00000000000f0aa0 <_ZN4hiai2op9ReduceMin16__attr_keep_dimsEv@plt>:
   f0aa0:      	adrp	x16, 0xfc000
   f0aa4:      	ldr	x17, [x16, #0x8d8]
   f0aa8:      	add	x16, x16, #0x8d8
   f0aac:      	br	x17

00000000000f0ab0 <_ZN4hiai2op11ReduceProdD9__input_xEv@plt>:
   f0ab0:      	adrp	x16, 0xfc000
   f0ab4:      	ldr	x17, [x16, #0x8e0]
   f0ab8:      	add	x16, x16, #0x8e0
   f0abc:      	br	x17

00000000000f0ac0 <_ZN4hiai2op11ReduceProdD20__required_attr_axesEv@plt>:
   f0ac0:      	adrp	x16, 0xfc000
   f0ac4:      	ldr	x17, [x16, #0x8e8]
   f0ac8:      	add	x16, x16, #0x8e8
   f0acc:      	br	x17

00000000000f0ad0 <_ZN4hiai2op11ReduceProdD16__attr_keep_dimsEv@plt>:
   f0ad0:      	adrp	x16, 0xfc000
   f0ad4:      	ldr	x17, [x16, #0x8f0]
   f0ad8:      	add	x16, x16, #0x8f0
   f0adc:      	br	x17

00000000000f0ae0 <_ZN4hiai2op9ReduceL2D9__input_xEv@plt>:
   f0ae0:      	adrp	x16, 0xfc000
   f0ae4:      	ldr	x17, [x16, #0x8f8]
   f0ae8:      	add	x16, x16, #0x8f8
   f0aec:      	br	x17

00000000000f0af0 <_ZN4hiai2op9ReduceL2D20__required_attr_axesEv@plt>:
   f0af0:      	adrp	x16, 0xfc000
   f0af4:      	ldr	x17, [x16, #0x900]
   f0af8:      	add	x16, x16, #0x900
   f0afc:      	br	x17

00000000000f0b00 <_ZN4hiai2op9ReduceL2D16__attr_keep_dimsEv@plt>:
   f0b00:      	adrp	x16, 0xfc000
   f0b04:      	ldr	x17, [x16, #0x908]
   f0b08:      	add	x16, x16, #0x908
   f0b0c:      	br	x17

00000000000f0b10 <_ZN4hiai2op15ReduceLogSumExp9__input_xEv@plt>:
   f0b10:      	adrp	x16, 0xfc000
   f0b14:      	ldr	x17, [x16, #0x910]
   f0b18:      	add	x16, x16, #0x910
   f0b1c:      	br	x17

00000000000f0b20 <_ZN4hiai2op15ReduceLogSumExp20__required_attr_axesEv@plt>:
   f0b20:      	adrp	x16, 0xfc000
   f0b24:      	ldr	x17, [x16, #0x918]
   f0b28:      	add	x16, x16, #0x918
   f0b2c:      	br	x17

00000000000f0b30 <_ZN4hiai2op15ReduceLogSumExp15__attr_keepdimsEv@plt>:
   f0b30:      	adrp	x16, 0xfc000
   f0b34:      	ldr	x17, [x16, #0x920]
   f0b38:      	add	x16, x16, #0x920
   f0b3c:      	br	x17

00000000000f0b40 <_ZN4hiai2op9ReduceSum12__input_axesEv@plt>:
   f0b40:      	adrp	x16, 0xfc000
   f0b44:      	ldr	x17, [x16, #0x928]
   f0b48:      	add	x16, x16, #0x928
   f0b4c:      	br	x17

00000000000f0b50 <_ZN4hiai2op9ReduceSum16__attr_keep_dimsEv@plt>:
   f0b50:      	adrp	x16, 0xfc000
   f0b54:      	ldr	x17, [x16, #0x930]
   f0b58:      	add	x16, x16, #0x930
   f0b5c:      	br	x17

00000000000f0b60 <_ZN4hiai2op6Square9__input_xEv@plt>:
   f0b60:      	adrp	x16, 0xfc000
   f0b64:      	ldr	x17, [x16, #0x938]
   f0b68:      	add	x16, x16, #0x938
   f0b6c:      	br	x17

00000000000f0b70 <_ZN4hiai2op4Sqrt9__input_xEv@plt>:
   f0b70:      	adrp	x16, 0xfc000
   f0b74:      	ldr	x17, [x16, #0x940]
   f0b78:      	add	x16, x16, #0x940
   f0b7c:      	br	x17

00000000000f0b80 <_ZN5mizar23__register__Npu__Relu__Ev@plt>:
   f0b80:      	adrp	x16, 0xfc000
   f0b84:      	ldr	x17, [x16, #0x948]
   f0b88:      	add	x16, x16, #0x948
   f0b8c:      	br	x17

00000000000f0b90 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_7NpuReluEJEEC2ES3_@plt>:
   f0b90:      	adrp	x16, 0xfc000
   f0b94:      	ldr	x17, [x16, #0x950]
   f0b98:      	add	x16, x16, #0x950
   f0b9c:      	br	x17

00000000000f0ba0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op12DepthToSpaceENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0ba0:      	adrp	x16, 0xfc000
   f0ba4:      	ldr	x17, [x16, #0x958]
   f0ba8:      	add	x16, x16, #0x958
   f0bac:      	br	x17

00000000000f0bb0 <_ZN4hiai2op12DepthToSpace19set_attr_block_sizeEl@plt>:
   f0bb0:      	adrp	x16, 0xfc000
   f0bb4:      	ldr	x17, [x16, #0x960]
   f0bb8:      	add	x16, x16, #0x960
   f0bbc:      	br	x17

00000000000f0bc0 <_ZN4hiai2op12DepthToSpace13set_attr_modeENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0bc0:      	adrp	x16, 0xfc000
   f0bc4:      	ldr	x17, [x16, #0x968]
   f0bc8:      	add	x16, x16, #0x968
   f0bcc:      	br	x17

00000000000f0bd0 <_ZN4hiai2op12DepthToSpace20set_attr_data_formatENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0bd0:      	adrp	x16, 0xfc000
   f0bd4:      	ldr	x17, [x16, #0x970]
   f0bd8:      	add	x16, x16, #0x970
   f0bdc:      	br	x17

00000000000f0be0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op12SpaceToDepthENS_9allocatorIS3_EEEC2B8ne180000IJNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0be0:      	adrp	x16, 0xfc000
   f0be4:      	ldr	x17, [x16, #0x978]
   f0be8:      	add	x16, x16, #0x978
   f0bec:      	br	x17

00000000000f0bf0 <_ZN4hiai2op12SpaceToDepth19set_attr_block_sizeEl@plt>:
   f0bf0:      	adrp	x16, 0xfc000
   f0bf4:      	ldr	x17, [x16, #0x980]
   f0bf8:      	add	x16, x16, #0x980
   f0bfc:      	br	x17

00000000000f0c00 <_ZN4hiai2op12SpaceToDepth20set_attr_data_formatENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0c00:      	adrp	x16, 0xfc000
   f0c04:      	ldr	x17, [x16, #0x988]
   f0c08:      	add	x16, x16, #0x988
   f0c0c:      	br	x17

00000000000f0c10 <_ZN5mizar28__register__Npu__OrigReorg__Ev@plt>:
   f0c10:      	adrp	x16, 0xfc000
   f0c14:      	ldr	x17, [x16, #0x990]
   f0c18:      	add	x16, x16, #0x990
   f0c1c:      	br	x17

00000000000f0c20 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuOrigReorgEJEEC2ES3_@plt>:
   f0c20:      	adrp	x16, 0xfc000
   f0c24:      	ldr	x17, [x16, #0x998]
   f0c28:      	add	x16, x16, #0x998
   f0c2c:      	br	x17

00000000000f0c30 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIN5mizar3fbs9ReorgModeENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_22__unordered_map_hasherIS4_SB_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_SB_SG_SE_Lb1EEENS8_ISB_EEE25__emplace_unique_key_argsIS4_JRKNS_4pairIKS4_SA_EEEEENSN_INS_15__hash_iteratorIPNS_11__hash_nodeISB_PvEEEEbEERKT_DpOT0_@plt>:
   f0c30:      	adrp	x16, 0xfc000
   f0c34:      	ldr	x17, [x16, #0x9a0]
   f0c38:      	add	x16, x16, #0x9a0
   f0c3c:      	br	x17

00000000000f0c40 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIN5mizar3fbs9ReorgModeENS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_22__unordered_map_hasherIS4_SB_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_SB_SG_SE_Lb1EEENS8_ISB_EEE11__do_rehashILb1EEEvm@plt>:
   f0c40:      	adrp	x16, 0xfc000
   f0c44:      	ldr	x17, [x16, #0x9a8]
   f0c48:      	add	x16, x16, #0x9a8
   f0c4c:      	br	x17

00000000000f0c50 <_ZN4hiai2op12DepthToSpace9__input_xEv@plt>:
   f0c50:      	adrp	x16, 0xfc000
   f0c54:      	ldr	x17, [x16, #0x9b0]
   f0c58:      	add	x16, x16, #0x9b0
   f0c5c:      	br	x17

00000000000f0c60 <_ZN4hiai2op12DepthToSpace26__required_attr_block_sizeEv@plt>:
   f0c60:      	adrp	x16, 0xfc000
   f0c64:      	ldr	x17, [x16, #0x9b8]
   f0c68:      	add	x16, x16, #0x9b8
   f0c6c:      	br	x17

00000000000f0c70 <_ZN4hiai2op12DepthToSpace11__attr_modeEv@plt>:
   f0c70:      	adrp	x16, 0xfc000
   f0c74:      	ldr	x17, [x16, #0x9c0]
   f0c78:      	add	x16, x16, #0x9c0
   f0c7c:      	br	x17

00000000000f0c80 <_ZN4hiai2op12DepthToSpace18__attr_data_formatEv@plt>:
   f0c80:      	adrp	x16, 0xfc000
   f0c84:      	ldr	x17, [x16, #0x9c8]
   f0c88:      	add	x16, x16, #0x9c8
   f0c8c:      	br	x17

00000000000f0c90 <_ZN4hiai2op12SpaceToDepth9__input_xEv@plt>:
   f0c90:      	adrp	x16, 0xfc000
   f0c94:      	ldr	x17, [x16, #0x9d0]
   f0c98:      	add	x16, x16, #0x9d0
   f0c9c:      	br	x17

00000000000f0ca0 <_ZN4hiai2op12SpaceToDepth26__required_attr_block_sizeEv@plt>:
   f0ca0:      	adrp	x16, 0xfc000
   f0ca4:      	ldr	x17, [x16, #0x9d8]
   f0ca8:      	add	x16, x16, #0x9d8
   f0cac:      	br	x17

00000000000f0cb0 <_ZN4hiai2op12SpaceToDepth18__attr_data_formatEv@plt>:
   f0cb0:      	adrp	x16, 0xfc000
   f0cb4:      	ldr	x17, [x16, #0x9e0]
   f0cb8:      	add	x16, x16, #0x9e0
   f0cbc:      	br	x17

00000000000f0cc0 <_ZN5mizar26__register__Npu__Reshape__Ev@plt>:
   f0cc0:      	adrp	x16, 0xfc000
   f0cc4:      	ldr	x17, [x16, #0x9e8]
   f0cc8:      	add	x16, x16, #0x9e8
   f0ccc:      	br	x17

00000000000f0cd0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuReshapeEJEEC2ES3_@plt>:
   f0cd0:      	adrp	x16, 0xfc000
   f0cd4:      	ldr	x17, [x16, #0x9f0]
   f0cd8:      	add	x16, x16, #0x9f0
   f0cdc:      	br	x17

00000000000f0ce0 <_ZNKSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN5mizar13NpuResizeModeEEENS_22__unordered_map_hasherIS7_SA_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SA_SF_SD_Lb1EEENS5_ISA_EEE4findIS7_EENS_21__hash_const_iteratorIPNS_11__hash_nodeISA_PvEEEERKT_@plt>:
   f0ce0:      	adrp	x16, 0xfc000
   f0ce4:      	ldr	x17, [x16, #0x9f8]
   f0ce8:      	add	x16, x16, #0x9f8
   f0cec:      	br	x17

00000000000f0cf0 <_ZN5mizar6detail14MakeStringImplIJPKcNSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEEEESA_DpRKT_@plt>:
   f0cf0:      	adrp	x16, 0xfc000
   f0cf4:      	ldr	x17, [x16, #0xa00]
   f0cf8:      	add	x16, x16, #0xa00
   f0cfc:      	br	x17

00000000000f0d00 <_ZN4hiai2op23ResizeNearestNeighborV2C2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0d00:      	adrp	x16, 0xfc000
   f0d04:      	ldr	x17, [x16, #0xa08]
   f0d08:      	add	x16, x16, #0xa08
   f0d0c:      	br	x17

00000000000f0d10 <_ZN4hiai2op23ResizeNearestNeighborV222set_attr_align_cornersEb@plt>:
   f0d10:      	adrp	x16, 0xfc000
   f0d14:      	ldr	x17, [x16, #0xa10]
   f0d18:      	add	x16, x16, #0xa10
   f0d1c:      	br	x17

00000000000f0d20 <_ZN4hiai2op16ResizeBilinearV2C2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f0d20:      	adrp	x16, 0xfc000
   f0d24:      	ldr	x17, [x16, #0xa18]
   f0d28:      	add	x16, x16, #0xa18
   f0d2c:      	br	x17

00000000000f0d30 <_ZN4hiai2op16ResizeBilinearV222set_attr_align_cornersEb@plt>:
   f0d30:      	adrp	x16, 0xfc000
   f0d34:      	ldr	x17, [x16, #0xa20]
   f0d38:      	add	x16, x16, #0xa20
   f0d3c:      	br	x17

00000000000f0d40 <_ZN4hiai2op16ResizeBilinearV227set_attr_half_pixel_centersEb@plt>:
   f0d40:      	adrp	x16, 0xfc000
   f0d44:      	ldr	x17, [x16, #0xa28]
   f0d48:      	add	x16, x16, #0xa28
   f0d4c:      	br	x17

00000000000f0d50 <_ZN5mizar25__register__Npu__Resize__Ev@plt>:
   f0d50:      	adrp	x16, 0xfc000
   f0d54:      	ldr	x17, [x16, #0xa30]
   f0d58:      	add	x16, x16, #0xa30
   f0d5c:      	br	x17

00000000000f0d60 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_9NpuResizeEJEEC2ES3_@plt>:
   f0d60:      	adrp	x16, 0xfc000
   f0d64:      	ldr	x17, [x16, #0xa38]
   f0d68:      	add	x16, x16, #0xa38
   f0d6c:      	br	x17

00000000000f0d70 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN5mizar13NpuResizeModeEEENS_22__unordered_map_hasherIS7_SA_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SA_SF_SD_Lb1EEENS5_ISA_EEE25__emplace_unique_key_argsIS7_JRKNS_4pairIKS7_S9_EEEEENSM_INS_15__hash_iteratorIPNS_11__hash_nodeISA_PvEEEEbEERKT_DpOT0_@plt>:
   f0d70:      	adrp	x16, 0xfc000
   f0d74:      	ldr	x17, [x16, #0xa40]
   f0d78:      	add	x16, x16, #0xa40
   f0d7c:      	br	x17

00000000000f0d80 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN5mizar13NpuResizeModeEEENS_22__unordered_map_hasherIS7_SA_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SA_SF_SD_Lb1EEENS5_ISA_EEE11__do_rehashILb1EEEvm@plt>:
   f0d80:      	adrp	x16, 0xfc000
   f0d84:      	ldr	x17, [x16, #0xa48]
   f0d88:      	add	x16, x16, #0xa48
   f0d8c:      	br	x17

00000000000f0d90 <_ZN4hiai2op23ResizeNearestNeighborV212__input_sizeEv@plt>:
   f0d90:      	adrp	x16, 0xfc000
   f0d94:      	ldr	x17, [x16, #0xa50]
   f0d98:      	add	x16, x16, #0xa50
   f0d9c:      	br	x17

00000000000f0da0 <_ZN4hiai2op23ResizeNearestNeighborV220__attr_align_cornersEv@plt>:
   f0da0:      	adrp	x16, 0xfc000
   f0da4:      	ldr	x17, [x16, #0xa58]
   f0da8:      	add	x16, x16, #0xa58
   f0dac:      	br	x17

00000000000f0db0 <_ZN4hiai2op23ResizeNearestNeighborV225__attr_half_pixel_centersEv@plt>:
   f0db0:      	adrp	x16, 0xfc000
   f0db4:      	ldr	x17, [x16, #0xa60]
   f0db8:      	add	x16, x16, #0xa60
   f0dbc:      	br	x17

00000000000f0dc0 <_ZN4hiai2op16ResizeBilinearV212__input_sizeEv@plt>:
   f0dc0:      	adrp	x16, 0xfc000
   f0dc4:      	ldr	x17, [x16, #0xa68]
   f0dc8:      	add	x16, x16, #0xa68
   f0dcc:      	br	x17

00000000000f0dd0 <_ZN4hiai2op16ResizeBilinearV220__attr_align_cornersEv@plt>:
   f0dd0:      	adrp	x16, 0xfc000
   f0dd4:      	ldr	x17, [x16, #0xa70]
   f0dd8:      	add	x16, x16, #0xa70
   f0ddc:      	br	x17

00000000000f0de0 <_ZN4hiai2op16ResizeBilinearV225__attr_half_pixel_centersEv@plt>:
   f0de0:      	adrp	x16, 0xfc000
   f0de4:      	ldr	x17, [x16, #0xa78]
   f0de8:      	add	x16, x16, #0xa78
   f0dec:      	br	x17

00000000000f0df0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op14ShuffleChannelENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0df0:      	adrp	x16, 0xfc000
   f0df4:      	ldr	x17, [x16, #0xa80]
   f0df8:      	add	x16, x16, #0xa80
   f0dfc:      	br	x17

00000000000f0e00 <_ZN4hiai2op14ShuffleChannel14set_attr_groupEl@plt>:
   f0e00:      	adrp	x16, 0xfc000
   f0e04:      	ldr	x17, [x16, #0xa88]
   f0e08:      	add	x16, x16, #0xa88
   f0e0c:      	br	x17

00000000000f0e10 <_ZN5mizar37__register__Npu__OrigShuffleChannel__Ev@plt>:
   f0e10:      	adrp	x16, 0xfc000
   f0e14:      	ldr	x17, [x16, #0xa90]
   f0e18:      	add	x16, x16, #0xa90
   f0e1c:      	br	x17

00000000000f0e20 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_21NpuOrigShuffleChannelEJEEC2ES3_@plt>:
   f0e20:      	adrp	x16, 0xfc000
   f0e24:      	ldr	x17, [x16, #0xa98]
   f0e28:      	add	x16, x16, #0xa98
   f0e2c:      	br	x17

00000000000f0e30 <_ZN4hiai2op14ShuffleChannel9__input_xEv@plt>:
   f0e30:      	adrp	x16, 0xfc000
   f0e34:      	ldr	x17, [x16, #0xaa0]
   f0e38:      	add	x16, x16, #0xaa0
   f0e3c:      	br	x17

00000000000f0e40 <_ZN4hiai2op14ShuffleChannel12__attr_groupEv@plt>:
   f0e40:      	adrp	x16, 0xfc000
   f0e44:      	ldr	x17, [x16, #0xaa8]
   f0e48:      	add	x16, x16, #0xaa8
   f0e4c:      	br	x17

00000000000f0e50 <_ZN5mizar26__register__Npu__Sigmoid__Ev@plt>:
   f0e50:      	adrp	x16, 0xfc000
   f0e54:      	ldr	x17, [x16, #0xab0]
   f0e58:      	add	x16, x16, #0xab0
   f0e5c:      	br	x17

00000000000f0e60 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuSigmoidEJEEC2ES3_@plt>:
   f0e60:      	adrp	x16, 0xfc000
   f0e64:      	ldr	x17, [x16, #0xab8]
   f0e68:      	add	x16, x16, #0xab8
   f0e6c:      	br	x17

00000000000f0e70 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op14StridedSliceV2ENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0e70:      	adrp	x16, 0xfc000
   f0e74:      	ldr	x17, [x16, #0xac0]
   f0e78:      	add	x16, x16, #0xac0
   f0e7c:      	br	x17

00000000000f0e80 <_ZN5mizar24__register__Npu__Slice__Ev@plt>:
   f0e80:      	adrp	x16, 0xfc000
   f0e84:      	ldr	x17, [x16, #0xac8]
   f0e88:      	add	x16, x16, #0xac8
   f0e8c:      	br	x17

00000000000f0e90 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_8NpuSliceEJEEC2ES3_@plt>:
   f0e90:      	adrp	x16, 0xfc000
   f0e94:      	ldr	x17, [x16, #0xad0]
   f0e98:      	add	x16, x16, #0xad0
   f0e9c:      	br	x17

00000000000f0ea0 <_ZN4hiai2op14StridedSliceV29__input_xEv@plt>:
   f0ea0:      	adrp	x16, 0xfc000
   f0ea4:      	ldr	x17, [x16, #0xad8]
   f0ea8:      	add	x16, x16, #0xad8
   f0eac:      	br	x17

00000000000f0eb0 <_ZN4hiai2op14StridedSliceV211__input_endEv@plt>:
   f0eb0:      	adrp	x16, 0xfc000
   f0eb4:      	ldr	x17, [x16, #0xae0]
   f0eb8:      	add	x16, x16, #0xae0
   f0ebc:      	br	x17

00000000000f0ec0 <_ZN4hiai2op14StridedSliceV224__optional_input_stridesEv@plt>:
   f0ec0:      	adrp	x16, 0xfc000
   f0ec4:      	ldr	x17, [x16, #0xae8]
   f0ec8:      	add	x16, x16, #0xae8
   f0ecc:      	br	x17

00000000000f0ed0 <_ZN4hiai2op14StridedSliceV217__attr_begin_maskEv@plt>:
   f0ed0:      	adrp	x16, 0xfc000
   f0ed4:      	ldr	x17, [x16, #0xaf0]
   f0ed8:      	add	x16, x16, #0xaf0
   f0edc:      	br	x17

00000000000f0ee0 <_ZN4hiai2op14StridedSliceV215__attr_end_maskEv@plt>:
   f0ee0:      	adrp	x16, 0xfc000
   f0ee4:      	ldr	x17, [x16, #0xaf8]
   f0ee8:      	add	x16, x16, #0xaf8
   f0eec:      	br	x17

00000000000f0ef0 <_ZN4hiai2op14StridedSliceV220__attr_ellipsis_maskEv@plt>:
   f0ef0:      	adrp	x16, 0xfc000
   f0ef4:      	ldr	x17, [x16, #0xb00]
   f0ef8:      	add	x16, x16, #0xb00
   f0efc:      	br	x17

00000000000f0f00 <_ZN4hiai2op14StridedSliceV220__attr_new_axis_maskEv@plt>:
   f0f00:      	adrp	x16, 0xfc000
   f0f04:      	ldr	x17, [x16, #0xb08]
   f0f08:      	add	x16, x16, #0xb08
   f0f0c:      	br	x17

00000000000f0f10 <_ZN4hiai2op14StridedSliceV223__attr_shrink_axis_maskEv@plt>:
   f0f10:      	adrp	x16, 0xfc000
   f0f14:      	ldr	x17, [x16, #0xb10]
   f0f18:      	add	x16, x16, #0xb10
   f0f1c:      	br	x17

00000000000f0f20 <_ZN5mizar26__register__Npu__Softmax__Ev@plt>:
   f0f20:      	adrp	x16, 0xfc000
   f0f24:      	ldr	x17, [x16, #0xb18]
   f0f28:      	add	x16, x16, #0xb18
   f0f2c:      	br	x17

00000000000f0f30 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuSoftmaxEJEEC2ES3_@plt>:
   f0f30:      	adrp	x16, 0xfc000
   f0f34:      	ldr	x17, [x16, #0xb20]
   f0f38:      	add	x16, x16, #0xb20
   f0f3c:      	br	x17

00000000000f0f40 <_ZN5mizar24__register__Npu__Split__Ev@plt>:
   f0f40:      	adrp	x16, 0xfc000
   f0f44:      	ldr	x17, [x16, #0xb28]
   f0f48:      	add	x16, x16, #0xb28
   f0f4c:      	br	x17

00000000000f0f50 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_8NpuSplitEJEEC2ES3_@plt>:
   f0f50:      	adrp	x16, 0xfc000
   f0f54:      	ldr	x17, [x16, #0xb30]
   f0f58:      	add	x16, x16, #0xb30
   f0f5c:      	br	x17

00000000000f0f60 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op7SqueezeENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0f60:      	adrp	x16, 0xfc000
   f0f64:      	ldr	x17, [x16, #0xb38]
   f0f68:      	add	x16, x16, #0xb38
   f0f6c:      	br	x17

00000000000f0f70 <_ZN4hiai2op7Squeeze13set_attr_axisENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f0f70:      	adrp	x16, 0xfc000
   f0f74:      	ldr	x17, [x16, #0xb40]
   f0f78:      	add	x16, x16, #0xb40
   f0f7c:      	br	x17

00000000000f0f80 <_ZN5mizar26__register__Npu__Squeeze__Ev@plt>:
   f0f80:      	adrp	x16, 0xfc000
   f0f84:      	ldr	x17, [x16, #0xb48]
   f0f88:      	add	x16, x16, #0xb48
   f0f8c:      	br	x17

00000000000f0f90 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_10NpuSqueezeEJEEC2ES3_@plt>:
   f0f90:      	adrp	x16, 0xfc000
   f0f94:      	ldr	x17, [x16, #0xb50]
   f0f98:      	add	x16, x16, #0xb50
   f0f9c:      	br	x17

00000000000f0fa0 <_ZN4hiai2op7Squeeze9__input_xEv@plt>:
   f0fa0:      	adrp	x16, 0xfc000
   f0fa4:      	ldr	x17, [x16, #0xb58]
   f0fa8:      	add	x16, x16, #0xb58
   f0fac:      	br	x17

00000000000f0fb0 <_ZN4hiai2op7Squeeze11__attr_axisEv@plt>:
   f0fb0:      	adrp	x16, 0xfc000
   f0fb4:      	ldr	x17, [x16, #0xb60]
   f0fb8:      	add	x16, x16, #0xb60
   f0fbc:      	br	x17

00000000000f0fc0 <_ZN5mizar23__register__Npu__Tile__Ev@plt>:
   f0fc0:      	adrp	x16, 0xfc000
   f0fc4:      	ldr	x17, [x16, #0xb68]
   f0fc8:      	add	x16, x16, #0xb68
   f0fcc:      	br	x17

00000000000f0fd0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_7NpuTileEJEEC2ES3_@plt>:
   f0fd0:      	adrp	x16, 0xfc000
   f0fd4:      	ldr	x17, [x16, #0xb70]
   f0fd8:      	add	x16, x16, #0xb70
   f0fdc:      	br	x17

00000000000f0fe0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4TopKENS_9allocatorIS3_EEEC2B8ne180000IJNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f0fe0:      	adrp	x16, 0xfc000
   f0fe4:      	ldr	x17, [x16, #0xb78]
   f0fe8:      	add	x16, x16, #0xb78
   f0fec:      	br	x17

00000000000f0ff0 <_ZN4hiai2op4TopK15set_attr_sortedEb@plt>:
   f0ff0:      	adrp	x16, 0xfc000
   f0ff4:      	ldr	x17, [x16, #0xb80]
   f0ff8:      	add	x16, x16, #0xb80
   f0ffc:      	br	x17

00000000000f1000 <_ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_S9_@plt>:
   f1000:      	adrp	x16, 0xfc000
   f1004:      	ldr	x17, [x16, #0xb88]
   f1008:      	add	x16, x16, #0xb88
   f100c:      	br	x17

00000000000f1010 <_ZN5mizar23__register__Npu__TopK__Ev@plt>:
   f1010:      	adrp	x16, 0xfc000
   f1014:      	ldr	x17, [x16, #0xb90]
   f1018:      	add	x16, x16, #0xb90
   f101c:      	br	x17

00000000000f1020 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_7NpuTopKEJEEC2ES3_@plt>:
   f1020:      	adrp	x16, 0xfc000
   f1024:      	ldr	x17, [x16, #0xb98]
   f1028:      	add	x16, x16, #0xb98
   f102c:      	br	x17

00000000000f1030 <_ZN4hiai2op4TopK9__input_xEv@plt>:
   f1030:      	adrp	x16, 0xfc000
   f1034:      	ldr	x17, [x16, #0xba0]
   f1038:      	add	x16, x16, #0xba0
   f103c:      	br	x17

00000000000f1040 <_ZN4hiai2op4TopK12__out_valuesEv@plt>:
   f1040:      	adrp	x16, 0xfc000
   f1044:      	ldr	x17, [x16, #0xba8]
   f1048:      	add	x16, x16, #0xba8
   f104c:      	br	x17

00000000000f1050 <_ZN4hiai2op4TopK13__attr_sortedEv@plt>:
   f1050:      	adrp	x16, 0xfc000
   f1054:      	ldr	x17, [x16, #0xbb0]
   f1058:      	add	x16, x16, #0xbb0
   f105c:      	br	x17

00000000000f1060 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op4AcosEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1060:      	adrp	x16, 0xfc000
   f1064:      	ldr	x17, [x16, #0xbb8]
   f1068:      	add	x16, x16, #0xbb8
   f106c:      	br	x17

00000000000f1070 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op5RsqrtEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1070:      	adrp	x16, 0xfc000
   f1074:      	ldr	x17, [x16, #0xbc0]
   f1078:      	add	x16, x16, #0xbc0
   f107c:      	br	x17

00000000000f1080 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3LogEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1080:      	adrp	x16, 0xfc000
   f1084:      	ldr	x17, [x16, #0xbc8]
   f1088:      	add	x16, x16, #0xbc8
   f108c:      	br	x17

00000000000f1090 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op5FloorEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1090:      	adrp	x16, 0xfc000
   f1094:      	ldr	x17, [x16, #0xbd0]
   f1098:      	add	x16, x16, #0xbd0
   f109c:      	br	x17

00000000000f10a0 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3ErfEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f10a0:      	adrp	x16, 0xfc000
   f10a4:      	ldr	x17, [x16, #0xbd8]
   f10a8:      	add	x16, x16, #0xbd8
   f10ac:      	br	x17

00000000000f10b0 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3NegEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f10b0:      	adrp	x16, 0xfc000
   f10b4:      	ldr	x17, [x16, #0xbe0]
   f10b8:      	add	x16, x16, #0xbe0
   f10bc:      	br	x17

00000000000f10c0 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3TanEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f10c0:      	adrp	x16, 0xfc000
   f10c4:      	ldr	x17, [x16, #0xbe8]
   f10c8:      	add	x16, x16, #0xbe8
   f10cc:      	br	x17

00000000000f10d0 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op4CeilEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f10d0:      	adrp	x16, 0xfc000
   f10d4:      	ldr	x17, [x16, #0xbf0]
   f10d8:      	add	x16, x16, #0xbf0
   f10dc:      	br	x17

00000000000f10e0 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op4AtanEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f10e0:      	adrp	x16, 0xfc000
   f10e4:      	ldr	x17, [x16, #0xbf8]
   f10e8:      	add	x16, x16, #0xbf8
   f10ec:      	br	x17

00000000000f10f0 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op4AsinEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f10f0:      	adrp	x16, 0xfc000
   f10f4:      	ldr	x17, [x16, #0xc00]
   f10f8:      	add	x16, x16, #0xc00
   f10fc:      	br	x17

00000000000f1100 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3ExpEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1100:      	adrp	x16, 0xfc000
   f1104:      	ldr	x17, [x16, #0xc08]
   f1108:      	add	x16, x16, #0xc08
   f110c:      	br	x17

00000000000f1110 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3CosEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1110:      	adrp	x16, 0xfc000
   f1114:      	ldr	x17, [x16, #0xc10]
   f1118:      	add	x16, x16, #0xc10
   f111c:      	br	x17

00000000000f1120 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op4SqrtEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1120:      	adrp	x16, 0xfc000
   f1124:      	ldr	x17, [x16, #0xc18]
   f1128:      	add	x16, x16, #0xc18
   f112c:      	br	x17

00000000000f1130 <_ZN5mizar8NpuUnary12UnaryConvertIN4hiai2op3SinEEENS_6StatusERKNSt6__ndk110shared_ptrIN2ge8OperatorEEERKNS6_12basic_stringIcNS6_11char_traitsIcEENS6_9allocatorIcEEEE@plt>:
   f1130:      	adrp	x16, 0xfc000
   f1134:      	ldr	x17, [x16, #0xc20]
   f1138:      	add	x16, x16, #0xc20
   f113c:      	br	x17

00000000000f1140 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4AcosENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f1140:      	adrp	x16, 0xfc000
   f1144:      	ldr	x17, [x16, #0xc28]
   f1148:      	add	x16, x16, #0xc28
   f114c:      	br	x17

00000000000f1150 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4AsinENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f1150:      	adrp	x16, 0xfc000
   f1154:      	ldr	x17, [x16, #0xc30]
   f1158:      	add	x16, x16, #0xc30
   f115c:      	br	x17

00000000000f1160 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4AtanENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f1160:      	adrp	x16, 0xfc000
   f1164:      	ldr	x17, [x16, #0xc38]
   f1168:      	add	x16, x16, #0xc38
   f116c:      	br	x17

00000000000f1170 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4CeilENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f1170:      	adrp	x16, 0xfc000
   f1174:      	ldr	x17, [x16, #0xc40]
   f1178:      	add	x16, x16, #0xc40
   f117c:      	br	x17

00000000000f1180 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5FloorENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f1180:      	adrp	x16, 0xfc000
   f1184:      	ldr	x17, [x16, #0xc48]
   f1188:      	add	x16, x16, #0xc48
   f118c:      	br	x17

00000000000f1190 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3NegENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f1190:      	adrp	x16, 0xfc000
   f1194:      	ldr	x17, [x16, #0xc50]
   f1198:      	add	x16, x16, #0xc50
   f119c:      	br	x17

00000000000f11a0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3CosENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f11a0:      	adrp	x16, 0xfc000
   f11a4:      	ldr	x17, [x16, #0xc58]
   f11a8:      	add	x16, x16, #0xc58
   f11ac:      	br	x17

00000000000f11b0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3SinENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f11b0:      	adrp	x16, 0xfc000
   f11b4:      	ldr	x17, [x16, #0xc60]
   f11b8:      	add	x16, x16, #0xc60
   f11bc:      	br	x17

00000000000f11c0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3TanENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f11c0:      	adrp	x16, 0xfc000
   f11c4:      	ldr	x17, [x16, #0xc68]
   f11c8:      	add	x16, x16, #0xc68
   f11cc:      	br	x17

00000000000f11d0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op3ErfENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f11d0:      	adrp	x16, 0xfc000
   f11d4:      	ldr	x17, [x16, #0xc70]
   f11d8:      	add	x16, x16, #0xc70
   f11dc:      	br	x17

00000000000f11e0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op5RsqrtENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f11e0:      	adrp	x16, 0xfc000
   f11e4:      	ldr	x17, [x16, #0xc78]
   f11e8:      	add	x16, x16, #0xc78
   f11ec:      	br	x17

00000000000f11f0 <_ZN5mizar24__register__Npu__Unary__Ev@plt>:
   f11f0:      	adrp	x16, 0xfc000
   f11f4:      	ldr	x17, [x16, #0xc80]
   f11f8:      	add	x16, x16, #0xc80
   f11fc:      	br	x17

00000000000f1200 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_8NpuUnaryEJEEC2ES3_@plt>:
   f1200:      	adrp	x16, 0xfc000
   f1204:      	ldr	x17, [x16, #0xc88]
   f1208:      	add	x16, x16, #0xc88
   f120c:      	br	x17

00000000000f1210 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIN5mizar3fbs18UnaryOperationTypeENS2_17NpuActivationModeEEENS_22__unordered_map_hasherIS4_S6_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE25__emplace_unique_key_argsIS4_JRKNS_4pairIKS4_S5_EEEEENSJ_INS_15__hash_iteratorIPNS_11__hash_nodeIS6_PvEEEEbEERKT_DpOT0_@plt>:
   f1210:      	adrp	x16, 0xfc000
   f1214:      	ldr	x17, [x16, #0xc90]
   f1218:      	add	x16, x16, #0xc90
   f121c:      	br	x17

00000000000f1220 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIN5mizar3fbs18UnaryOperationTypeENS2_17NpuActivationModeEEENS_22__unordered_map_hasherIS4_S6_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE11__do_rehashILb1EEEvm@plt>:
   f1220:      	adrp	x16, 0xfc000
   f1224:      	ldr	x17, [x16, #0xc98]
   f1228:      	add	x16, x16, #0xc98
   f122c:      	br	x17

00000000000f1230 <_ZN4hiai2op4Acos9__input_xEv@plt>:
   f1230:      	adrp	x16, 0xfc000
   f1234:      	ldr	x17, [x16, #0xca0]
   f1238:      	add	x16, x16, #0xca0
   f123c:      	br	x17

00000000000f1240 <_ZN4hiai2op4Asin9__input_xEv@plt>:
   f1240:      	adrp	x16, 0xfc000
   f1244:      	ldr	x17, [x16, #0xca8]
   f1248:      	add	x16, x16, #0xca8
   f124c:      	br	x17

00000000000f1250 <_ZN4hiai2op4Atan9__input_xEv@plt>:
   f1250:      	adrp	x16, 0xfc000
   f1254:      	ldr	x17, [x16, #0xcb0]
   f1258:      	add	x16, x16, #0xcb0
   f125c:      	br	x17

00000000000f1260 <_ZN4hiai2op4Ceil9__input_xEv@plt>:
   f1260:      	adrp	x16, 0xfc000
   f1264:      	ldr	x17, [x16, #0xcb8]
   f1268:      	add	x16, x16, #0xcb8
   f126c:      	br	x17

00000000000f1270 <_ZN4hiai2op5Floor9__input_xEv@plt>:
   f1270:      	adrp	x16, 0xfc000
   f1274:      	ldr	x17, [x16, #0xcc0]
   f1278:      	add	x16, x16, #0xcc0
   f127c:      	br	x17

00000000000f1280 <_ZN4hiai2op3Neg9__input_xEv@plt>:
   f1280:      	adrp	x16, 0xfc000
   f1284:      	ldr	x17, [x16, #0xcc8]
   f1288:      	add	x16, x16, #0xcc8
   f128c:      	br	x17

00000000000f1290 <_ZN4hiai2op3Cos9__input_xEv@plt>:
   f1290:      	adrp	x16, 0xfc000
   f1294:      	ldr	x17, [x16, #0xcd0]
   f1298:      	add	x16, x16, #0xcd0
   f129c:      	br	x17

00000000000f12a0 <_ZN4hiai2op3Sin9__input_xEv@plt>:
   f12a0:      	adrp	x16, 0xfc000
   f12a4:      	ldr	x17, [x16, #0xcd8]
   f12a8:      	add	x16, x16, #0xcd8
   f12ac:      	br	x17

00000000000f12b0 <_ZN4hiai2op3Tan9__input_xEv@plt>:
   f12b0:      	adrp	x16, 0xfc000
   f12b4:      	ldr	x17, [x16, #0xce0]
   f12b8:      	add	x16, x16, #0xce0
   f12bc:      	br	x17

00000000000f12c0 <_ZN4hiai2op3Erf9__input_xEv@plt>:
   f12c0:      	adrp	x16, 0xfc000
   f12c4:      	ldr	x17, [x16, #0xce8]
   f12c8:      	add	x16, x16, #0xce8
   f12cc:      	br	x17

00000000000f12d0 <_ZN4hiai2op5Rsqrt9__input_xEv@plt>:
   f12d0:      	adrp	x16, 0xfc000
   f12d4:      	ldr	x17, [x16, #0xcf0]
   f12d8:      	add	x16, x16, #0xcf0
   f12dc:      	br	x17

00000000000f12e0 <_ZN4hiai2op11MaxUnpool2DC2ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   f12e0:      	adrp	x16, 0xfc000
   f12e4:      	ldr	x17, [x16, #0xcf8]
   f12e8:      	add	x16, x16, #0xcf8
   f12ec:      	br	x17

00000000000f12f0 <_ZN4hiai2op11MaxUnpool2D14set_attr_ksizeENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f12f0:      	adrp	x16, 0xfc000
   f12f4:      	ldr	x17, [x16, #0xd00]
   f12f8:      	add	x16, x16, #0xd00
   f12fc:      	br	x17

00000000000f1300 <_ZN4hiai2op11MaxUnpool2D16set_attr_stridesENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f1300:      	adrp	x16, 0xfc000
   f1304:      	ldr	x17, [x16, #0xd08]
   f1308:      	add	x16, x16, #0xd08
   f130c:      	br	x17

00000000000f1310 <_ZN4hiai2op11MaxUnpool2D13set_attr_padsENSt6__ndk16vectorIlNS2_9allocatorIlEEEE@plt>:
   f1310:      	adrp	x16, 0xfc000
   f1314:      	ldr	x17, [x16, #0xd10]
   f1318:      	add	x16, x16, #0xd10
   f131c:      	br	x17

00000000000f1320 <_ZN5mizar32__register__Npu__OrigUnpooling__Ev@plt>:
   f1320:      	adrp	x16, 0xfc000
   f1324:      	ldr	x17, [x16, #0xd18]
   f1328:      	add	x16, x16, #0xd18
   f132c:      	br	x17

00000000000f1330 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_16NpuOrigUnpoolingEJEEC2ES3_@plt>:
   f1330:      	adrp	x16, 0xfc000
   f1334:      	ldr	x17, [x16, #0xd20]
   f1338:      	add	x16, x16, #0xd20
   f133c:      	br	x17

00000000000f1340 <_ZN4hiai2op11MaxUnpool2D14__input_argmaxEv@plt>:
   f1340:      	adrp	x16, 0xfc000
   f1344:      	ldr	x17, [x16, #0xd28]
   f1348:      	add	x16, x16, #0xd28
   f134c:      	br	x17

00000000000f1350 <_ZN4hiai2op11MaxUnpool2D21__required_attr_ksizeEv@plt>:
   f1350:      	adrp	x16, 0xfc000
   f1354:      	ldr	x17, [x16, #0xd30]
   f1358:      	add	x16, x16, #0xd30
   f135c:      	br	x17

00000000000f1360 <_ZN4hiai2op11MaxUnpool2D23__required_attr_stridesEv@plt>:
   f1360:      	adrp	x16, 0xfc000
   f1364:      	ldr	x17, [x16, #0xd38]
   f1368:      	add	x16, x16, #0xd38
   f136c:      	br	x17

00000000000f1370 <_ZN4hiai2op11MaxUnpool2D20__required_attr_padsEv@plt>:
   f1370:      	adrp	x16, 0xfc000
   f1374:      	ldr	x17, [x16, #0xd40]
   f1378:      	add	x16, x16, #0xd40
   f137c:      	br	x17

00000000000f1380 <_ZN4hiai2op11MaxUnpool2D19__attr_output_shapeEv@plt>:
   f1380:      	adrp	x16, 0xfc000
   f1384:      	ldr	x17, [x16, #0xd48]
   f1388:      	add	x16, x16, #0xd48
   f138c:      	br	x17

00000000000f1390 <_ZN4hiai2op11MaxUnpool2D18__attr_data_formatEv@plt>:
   f1390:      	adrp	x16, 0xfc000
   f1394:      	ldr	x17, [x16, #0xd50]
   f1398:      	add	x16, x16, #0xd50
   f139c:      	br	x17

00000000000f13a0 <_ZN5mizar28__register__Npu__Unsqueeze__Ev@plt>:
   f13a0:      	adrp	x16, 0xfc000
   f13a4:      	ldr	x17, [x16, #0xd58]
   f13a8:      	add	x16, x16, #0xd58
   f13ac:      	br	x17

00000000000f13b0 <_ZN5mizar12TypeRegisterINS_12NpuOpBuilderENS_3fbs6OpTypeENS_12NpuUnsqueezeEJEEC2ES3_@plt>:
   f13b0:      	adrp	x16, 0xfc000
   f13b4:      	ldr	x17, [x16, #0xd60]
   f13b8:      	add	x16, x16, #0xd60
   f13bc:      	br	x17

00000000000f13c0 <_ZN5mizar15NpuModelBuilder7CompileERKNSt6__ndk16vectorINS_15NpuTensorBufferENS1_9allocatorIS3_EEEES8_RKNS2_INS_9NpuOpInfoENS4_IS9_EEEERN2ge5ModelE@plt>:
   f13c0:      	adrp	x16, 0xfc000
   f13c4:      	ldr	x17, [x16, #0xd68]
   f13c8:      	add	x16, x16, #0xd68
   f13cc:      	br	x17

00000000000f13d0 <_ZN2ge10TensorDescC1ENS_5ShapeENS_6FormatENS_8DataTypeE@plt>:
   f13d0:      	adrp	x16, 0xfc000
   f13d4:      	ldr	x17, [x16, #0xd70]
   f13d8:      	add	x16, x16, #0xd70
   f13dc:      	br	x17

00000000000f13e0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4hiai2op4DataENS_9allocatorIS3_EEEC2B8ne180000IJRKNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   f13e0:      	adrp	x16, 0xfc000
   f13e4:      	ldr	x17, [x16, #0xd78]
   f13e8:      	add	x16, x16, #0xd78
   f13ec:      	br	x17

00000000000f13f0 <_ZN2ge8Operator15UpdateInputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_10TensorDescE@plt>:
   f13f0:      	adrp	x16, 0xfc000
   f13f4:      	ldr	x17, [x16, #0xd80]
   f13f8:      	add	x16, x16, #0xd80
   f13fc:      	br	x17

00000000000f1400 <_ZN5mizar13CommonFactoryINS_12NpuOpBuilderENS_3fbs6OpTypeEJEE6CreateES3_@plt>:
   f1400:      	adrp	x16, 0xfc000
   f1404:      	ldr	x17, [x16, #0xd88]
   f1408:      	add	x16, x16, #0xd88
   f140c:      	br	x17

00000000000f1410 <_ZNSt6__ndk16vectorINS_10shared_ptrIN2ge8OperatorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIRKS4_EEPS4_OT_@plt>:
   f1410:      	adrp	x16, 0xfc000
   f1414:      	ldr	x17, [x16, #0xd90]
   f1418:      	add	x16, x16, #0xd90
   f141c:      	br	x17

00000000000f1420 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_10shared_ptrIN2ge8OperatorEEEEENS_22__unordered_map_hasherIS7_SC_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SC_SH_SF_Lb1EEENS5_ISC_EEE4findIS7_EENS_15__hash_iteratorIPNS_11__hash_nodeISC_PvEEEERKT_@plt>:
   f1420:      	adrp	x16, 0xfc000
   f1424:      	ldr	x17, [x16, #0xd98]
   f1428:      	add	x16, x16, #0xd98
   f142c:      	br	x17

00000000000f1430 <_ZN5mizar6StatuscvbEv@plt>:
   f1430:      	adrp	x16, 0xfc000
   f1434:      	ldr	x17, [x16, #0xda0]
   f1438:      	add	x16, x16, #0xda0
   f143c:      	br	x17

00000000000f1440 <_ZN5mizar6detail14MakeStringImplIJPKciS3_S3_EEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   f1440:      	adrp	x16, 0xfc000
   f1444:      	ldr	x17, [x16, #0xda8]
   f1448:      	add	x16, x16, #0xda8
   f144c:      	br	x17

00000000000f1450 <_ZN5mizar6detail14MakeStringImplIJPKciS3_S3_S3_EEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   f1450:      	adrp	x16, 0xfc000
   f1454:      	ldr	x17, [x16, #0xdb0]
   f1458:      	add	x16, x16, #0xdb0
   f145c:      	br	x17

00000000000f1460 <_ZNK2ge8Operator7GetNameEv@plt>:
   f1460:      	adrp	x16, 0xfc000
   f1464:      	ldr	x17, [x16, #0xdb8]
   f1468:      	add	x16, x16, #0xdb8
   f146c:      	br	x17

00000000000f1470 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_10shared_ptrIN2ge8OperatorEEEEENS_22__unordered_map_hasherIS7_SC_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_SC_SH_SF_Lb1EEENS5_ISC_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJOS7_EEENSR_IJEEEEEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeISC_PvEEEEbEERKT_DpOT0_@plt>:
   f1470:      	adrp	x16, 0xfc000
   f1474:      	ldr	x17, [x16, #0xdc0]
   f1478:      	add	x16, x16, #0xdc0
   f147c:      	br	x17

00000000000f1480 <_ZNSt6__ndk16vectorIN2ge8OperatorENS_9allocatorIS2_EEE21__push_back_slow_pathIRKS2_EEPS2_OT_@plt>:
   f1480:      	adrp	x16, 0xfc000
   f1484:      	ldr	x17, [x16, #0xdc8]
   f1488:      	add	x16, x16, #0xdc8
   f148c:      	br	x17

00000000000f1490 <_ZN2ge5GraphC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f1490:      	adrp	x16, 0xfc000
   f1494:      	ldr	x17, [x16, #0xdd0]
   f1498:      	add	x16, x16, #0xdd0
   f149c:      	br	x17

00000000000f14a0 <_ZN2ge5Graph9SetInputsERNSt6__ndk16vectorINS_8OperatorENS1_9allocatorIS3_EEEE@plt>:
   f14a0:      	adrp	x16, 0xfc000
   f14a4:      	ldr	x17, [x16, #0xdd8]
   f14a8:      	add	x16, x16, #0xdd8
   f14ac:      	br	x17

00000000000f14b0 <_ZN2ge5Graph10SetOutputsERNSt6__ndk16vectorINS_8OperatorENS1_9allocatorIS3_EEEE@plt>:
   f14b0:      	adrp	x16, 0xfc000
   f14b4:      	ldr	x17, [x16, #0xde0]
   f14b8:      	add	x16, x16, #0xde0
   f14bc:      	br	x17

00000000000f14c0 <_ZN2ge5Model8SetGraphERKNS_5GraphE@plt>:
   f14c0:      	adrp	x16, 0xfc000
   f14c4:      	ldr	x17, [x16, #0xde8]
   f14c8:      	add	x16, x16, #0xde8
   f14cc:      	br	x17

00000000000f14d0 <_ZN2ge5GraphD2Ev@plt>:
   f14d0:      	adrp	x16, 0xfc000
   f14d4:      	ldr	x17, [x16, #0xdf0]
   f14d8:      	add	x16, x16, #0xdf0
   f14dc:      	br	x17

00000000000f14e0 <_ZNSt6__ndk111__call_onceERVmPvPFvS2_E@plt>:
   f14e0:      	adrp	x16, 0xfc000
   f14e4:      	ldr	x17, [x16, #0xdf8]
   f14e8:      	add	x16, x16, #0xdf8
   f14ec:      	br	x17

00000000000f14f0 <_ZN5mizar21RegisterNpuOpBuildersEv@plt>:
   f14f0:      	adrp	x16, 0xfc000
   f14f4:      	ldr	x17, [x16, #0xe00]
   f14f8:      	add	x16, x16, #0xe00
   f14fc:      	br	x17

00000000000f1500 <_ZNSt9exceptionD2Ev@plt>:
   f1500:      	adrp	x16, 0xfc000
   f1504:      	ldr	x17, [x16, #0xe08]
   f1508:      	add	x16, x16, #0xe08
   f150c:      	br	x17

00000000000f1510 <_ZN4hiai2op4Data9__input_xEv@plt>:
   f1510:      	adrp	x16, 0xfc000
   f1514:      	ldr	x17, [x16, #0xe10]
   f1518:      	add	x16, x16, #0xe10
   f151c:      	br	x17

00000000000f1520 <_ZN4hiai2op4Data12__attr_indexEv@plt>:
   f1520:      	adrp	x16, 0xfc000
   f1524:      	ldr	x17, [x16, #0xe18]
   f1528:      	add	x16, x16, #0xe18
   f152c:      	br	x17

00000000000f1530 <_ZN5mizar6detail14MakeStringImplIPKcJiS3_S3_EEEvRNSt6__ndk119basic_ostringstreamIcNS4_11char_traitsIcEENS4_9allocatorIcEEEERKT_DpRKT0_@plt>:
   f1530:      	adrp	x16, 0xfc000
   f1534:      	ldr	x17, [x16, #0xe20]
   f1538:      	add	x16, x16, #0xe20
   f153c:      	br	x17

00000000000f1540 <_ZN4hiai11HiaiIrBuild16ReleaseModelBuffERNS_15ModelBufferDataE@plt>:
   f1540:      	adrp	x16, 0xfc000
   f1544:      	ldr	x17, [x16, #0xe28]
   f1548:      	add	x16, x16, #0xe28
   f154c:      	br	x17

00000000000f1550 <_ZN5mizar14NpuCompilation12BuildIRModelERN2ge5ModelE@plt>:
   f1550:      	adrp	x16, 0xfc000
   f1554:      	ldr	x17, [x16, #0xe30]
   f1558:      	add	x16, x16, #0xe30
   f155c:      	br	x17

00000000000f1560 <_ZN4hiai11HiaiIrBuild15CreateModelBuffERN2ge5ModelERNS_15ModelBufferDataEj@plt>:
   f1560:      	adrp	x16, 0xfc000
   f1564:      	ldr	x17, [x16, #0xe38]
   f1568:      	add	x16, x16, #0xe38
   f156c:      	br	x17

00000000000f1570 <_ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataE@plt>:
   f1570:      	adrp	x16, 0xfc000
   f1574:      	ldr	x17, [x16, #0xe40]
   f1578:      	add	x16, x16, #0xe40
   f157c:      	br	x17

00000000000f1580 <__system_property_get@plt>:
   f1580:      	adrp	x16, 0xfc000
   f1584:      	ldr	x17, [x16, #0xe48]
   f1588:      	add	x16, x16, #0xe48
   f158c:      	br	x17

00000000000f1590 <memchr@plt>:
   f1590:      	adrp	x16, 0xfc000
   f1594:      	ldr	x17, [x16, #0xe50]
   f1598:      	add	x16, x16, #0xe50
   f159c:      	br	x17

00000000000f15a0 <_ZN4hiai18AiModelMngerClientC1Ev@plt>:
   f15a0:      	adrp	x16, 0xfc000
   f15a4:      	ldr	x17, [x16, #0xe58]
   f15a8:      	add	x16, x16, #0xe58
   f15ac:      	br	x17

00000000000f15b0 <_ZN4hiai18AiModelMngerClient4InitENSt6__ndk110shared_ptrINS_28AiModelManagerClientListenerEEE@plt>:
   f15b0:      	adrp	x16, 0xfc000
   f15b4:      	ldr	x17, [x16, #0xe60]
   f15b8:      	add	x16, x16, #0xe60
   f15bc:      	br	x17

00000000000f15c0 <_ZN5mizar6detail14MakeStringImplIJNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPKciEEES8_DpRKT_@plt>:
   f15c0:      	adrp	x16, 0xfc000
   f15c4:      	ldr	x17, [x16, #0xe68]
   f15c8:      	add	x16, x16, #0xe68
   f15cc:      	br	x17

00000000000f15d0 <_ZN4hiai18AiModelMngerClient10GetVersionEv@plt>:
   f15d0:      	adrp	x16, 0xfc000
   f15d4:      	ldr	x17, [x16, #0xe70]
   f15d8:      	add	x16, x16, #0xe70
   f15dc:      	br	x17

00000000000f15e0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   f15e0:      	adrp	x16, 0xfc000
   f15e4:      	ldr	x17, [x16, #0xe78]
   f15e8:      	add	x16, x16, #0xe78
   f15ec:      	br	x17

00000000000f15f0 <_ZN5mizar8NpuUtils14VersionCompareENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_NS_18VersionCompareTypeE@plt>:
   f15f0:      	adrp	x16, 0xfc000
   f15f4:      	ldr	x17, [x16, #0xe80]
   f15f8:      	add	x16, x16, #0xe80
   f15fc:      	br	x17

00000000000f1600 <_ZN5mizar8NpuUtils13GetApiVersionENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERi@plt>:
   f1600:      	adrp	x16, 0xfc000
   f1604:      	ldr	x17, [x16, #0xe88]
   f1608:      	add	x16, x16, #0xe88
   f160c:      	br	x17

00000000000f1610 <_ZN2ge5ModelC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   f1610:      	adrp	x16, 0xfc000
   f1614:      	ldr	x17, [x16, #0xe90]
   f1618:      	add	x16, x16, #0xe90
   f161c:      	br	x17

00000000000f1620 <_ZN5mizar14NpuCompilationD1Ev@plt>:
   f1620:      	adrp	x16, 0xfc000
   f1624:      	ldr	x17, [x16, #0xe98]
   f1628:      	add	x16, x16, #0xe98
   f162c:      	br	x17

00000000000f1630 <_ZN2ge5ModelD1Ev@plt>:
   f1630:      	adrp	x16, 0xfc000
   f1634:      	ldr	x17, [x16, #0xea0]
   f1638:      	add	x16, x16, #0xea0
   f163c:      	br	x17

00000000000f1640 <_ZN5mizar15NpuModelBuilderD2Ev@plt>:
   f1640:      	adrp	x16, 0xfc000
   f1644:      	ldr	x17, [x16, #0xea8]
   f1648:      	add	x16, x16, #0xea8
   f164c:      	br	x17

00000000000f1650 <_ZN4hiai18AiModelDescriptionC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiiii@plt>:
   f1650:      	adrp	x16, 0xfc000
   f1654:      	ldr	x17, [x16, #0xeb0]
   f1658:      	add	x16, x16, #0xeb0
   f165c:      	br	x17

00000000000f1660 <_ZN4hiai18AiModelDescription14SetModelBufferEPKvj@plt>:
   f1660:      	adrp	x16, 0xfc000
   f1664:      	ldr	x17, [x16, #0xeb8]
   f1668:      	add	x16, x16, #0xeb8
   f166c:      	br	x17

00000000000f1670 <_ZNSt6__ndk16vectorINS_10shared_ptrIN4hiai18AiModelDescriptionEEENS_9allocatorIS4_EEE21__push_back_slow_pathIRKS4_EEPS4_OT_@plt>:
   f1670:      	adrp	x16, 0xfc000
   f1674:      	ldr	x17, [x16, #0xec0]
   f1678:      	add	x16, x16, #0xec0
   f167c:      	br	x17

00000000000f1680 <_ZN4hiai18AiModelMngerClient23CheckModelCompatibilityERNS_18AiModelDescriptionERb@plt>:
   f1680:      	adrp	x16, 0xfc000
   f1684:      	ldr	x17, [x16, #0xec8]
   f1688:      	add	x16, x16, #0xec8
   f168c:      	br	x17

00000000000f1690 <_ZN4hiai18AiModelMngerClient4LoadERNSt6__ndk16vectorINS1_10shared_ptrINS_18AiModelDescriptionEEENS1_9allocatorIS5_EEEE@plt>:
   f1690:      	adrp	x16, 0xfc000
   f1694:      	ldr	x17, [x16, #0xed0]
   f1698:      	add	x16, x16, #0xed0
   f169c:      	br	x17

00000000000f16a0 <_ZN5mizar14NpuAdapterImpl18AllocModelIOTensorEv@plt>:
   f16a0:      	adrp	x16, 0xfc000
   f16a4:      	ldr	x17, [x16, #0xed8]
   f16a8:      	add	x16, x16, #0xed8
   f16ac:      	br	x17

00000000000f16b0 <_ZN4hiai9AiContext7AddParaERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   f16b0:      	adrp	x16, 0xfc000
   f16b4:      	ldr	x17, [x16, #0xee0]
   f16b8:      	add	x16, x16, #0xee0
   f16bc:      	br	x17

00000000000f16c0 <_ZN4hiai18AiModelMngerClient19GetModelIOTensorDimERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS1_6vectorINS_15TensorDimensionENS5_ISB_EEEESE_@plt>:
   f16c0:      	adrp	x16, 0xfc000
   f16c4:      	ldr	x17, [x16, #0xee8]
   f16c8:      	add	x16, x16, #0xee8
   f16cc:      	br	x17

00000000000f16d0 <_ZN4hiai8AiTensorC1Ev@plt>:
   f16d0:      	adrp	x16, 0xfc000
   f16d4:      	ldr	x17, [x16, #0xef0]
   f16d8:      	add	x16, x16, #0xef0
   f16dc:      	br	x17

00000000000f16e0 <_ZN4hiai8AiTensor4InitEPKNS_15TensorDimensionE@plt>:
   f16e0:      	adrp	x16, 0xfc000
   f16e4:      	ldr	x17, [x16, #0xef8]
   f16e8:      	add	x16, x16, #0xef8
   f16ec:      	br	x17

00000000000f16f0 <_ZNSt6__ndk16vectorINS_10shared_ptrIN4hiai8AiTensorEEENS_9allocatorIS4_EEE21__push_back_slow_pathIRKS4_EEPS4_OT_@plt>:
   f16f0:      	adrp	x16, 0xfc000
   f16f4:      	ldr	x17, [x16, #0xf00]
   f16f8:      	add	x16, x16, #0xf00
   f16fc:      	br	x17

00000000000f1700 <_ZN4hiai18AiModelMngerClient7ProcessERNS_9AiContextERNSt6__ndk16vectorINS3_10shared_ptrINS_8AiTensorEEENS3_9allocatorIS7_EEEESB_jRi@plt>:
   f1700:      	adrp	x16, 0xfc000
   f1704:      	ldr	x17, [x16, #0xf08]
   f1708:      	add	x16, x16, #0xf08
   f170c:      	br	x17

00000000000f1710 <_ZN5mizar6detail14MakeStringImplIJPKciS3_iEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   f1710:      	adrp	x16, 0xfc000
   f1714:      	ldr	x17, [x16, #0xf10]
   f1718:      	add	x16, x16, #0xf10
   f171c:      	br	x17

00000000000f1720 <_ZN5mizar6detail14MakeStringImplIJPKcjS3_jEEENSt6__ndk112basic_stringIcNS4_11char_traitsIcEENS4_9allocatorIcEEEEDpRKT_@plt>:
   f1720:      	adrp	x16, 0xfc000
   f1724:      	ldr	x17, [x16, #0xf18]
   f1728:      	add	x16, x16, #0xf18
   f172c:      	br	x17

00000000000f1730 <_ZN5mizar14NpuAdapterImplC2Ev@plt>:
   f1730:      	adrp	x16, 0xfc000
   f1734:      	ldr	x17, [x16, #0xf20]
   f1738:      	add	x16, x16, #0xf20
   f173c:      	br	x17

00000000000f1740 <_ZN4hiai9AiContextC1Ev@plt>:
   f1740:      	adrp	x16, 0xfc000
   f1744:      	ldr	x17, [x16, #0xf28]
   f1748:      	add	x16, x16, #0xf28
   f174c:      	br	x17

00000000000f1750 <_ZNSt6__ndk119__shared_mutex_baseC1Ev@plt>:
   f1750:      	adrp	x16, 0xfc000
   f1754:      	ldr	x17, [x16, #0xf30]
   f1758:      	add	x16, x16, #0xf30
   f175c:      	br	x17

00000000000f1760 <_ZN4hiai9AiContextD1Ev@plt>:
   f1760:      	adrp	x16, 0xfc000
   f1764:      	ldr	x17, [x16, #0xf38]
   f1768:      	add	x16, x16, #0xf38
   f176c:      	br	x17

00000000000f1770 <__dynamic_cast@plt>:
   f1770:      	adrp	x16, 0xfc000
   f1774:      	ldr	x17, [x16, #0xf40]
   f1778:      	add	x16, x16, #0xf40
   f177c:      	br	x17

00000000000f1780 <_ZN5mizar14NpuAdapterImplD2Ev@plt>:
   f1780:      	adrp	x16, 0xfc000
   f1784:      	ldr	x17, [x16, #0xf48]
   f1788:      	add	x16, x16, #0xf48
   f178c:      	br	x17

00000000000f1790 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
   f1790:      	adrp	x16, 0xfc000
   f1794:      	ldr	x17, [x16, #0xf50]
   f1798:      	add	x16, x16, #0xf50
   f179c:      	br	x17

00000000000f17a0 <_ZNSt6__ndk15mutexD1Ev@plt>:
   f17a0:      	adrp	x16, 0xfc000
   f17a4:      	ldr	x17, [x16, #0xf58]
   f17a8:      	add	x16, x16, #0xf58
   f17ac:      	br	x17

00000000000f17b0 <_ZN5mizar6detail14MakeStringImplIPKcJiS3_iEEEvRNSt6__ndk119basic_ostringstreamIcNS4_11char_traitsIcEENS4_9allocatorIcEEEERKT_DpRKT0_@plt>:
   f17b0:      	adrp	x16, 0xfc000
   f17b4:      	ldr	x17, [x16, #0xf60]
   f17b8:      	add	x16, x16, #0xf60
   f17bc:      	br	x17

00000000000f17c0 <_ZN5mizar6detail14MakeStringImplIPKcJjS3_jEEEvRNSt6__ndk119basic_ostringstreamIcNS4_11char_traitsIcEENS4_9allocatorIcEEEERKT_DpRKT0_@plt>:
   f17c0:      	adrp	x16, 0xfc000
   f17c4:      	ldr	x17, [x16, #0xf68]
   f17c8:      	add	x16, x16, #0xf68
   f17cc:      	br	x17

00000000000f17d0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj@plt>:
   f17d0:      	adrp	x16, 0xfc000
   f17d4:      	ldr	x17, [x16, #0xf70]
   f17d8:      	add	x16, x16, #0xf70
   f17dc:      	br	x17

00000000000f17e0 <_ZN2ge6TensorC1Ev@plt>:
   f17e0:      	adrp	x16, 0xfc000
   f17e4:      	ldr	x17, [x16, #0xf78]
   f17e8:      	add	x16, x16, #0xf78
   f17ec:      	br	x17

00000000000f17f0 <_ZN2ge6Tensor13SetTensorDescERKNS_10TensorDescE@plt>:
   f17f0:      	adrp	x16, 0xfc000
   f17f4:      	ldr	x17, [x16, #0xf80]
   f17f8:      	add	x16, x16, #0xf80
   f17fc:      	br	x17

00000000000f1800 <_ZN2ge6Tensor7SetDataEPKhm@plt>:
   f1800:      	adrp	x16, 0xfc000
   f1804:      	ldr	x17, [x16, #0xf88]
   f1808:      	add	x16, x16, #0xf88
   f180c:      	br	x17

00000000000f1810 <_ZN4hiai2op5Const14set_attr_valueENSt6__ndk110shared_ptrIN2ge6TensorEEE@plt>:
   f1810:      	adrp	x16, 0xfc000
   f1814:      	ldr	x17, [x16, #0xf90]
   f1818:      	add	x16, x16, #0xf90
   f181c:      	br	x17

00000000000f1820 <_ZN5mizar8NpuUtils14IsVersionValidENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   f1820:      	adrp	x16, 0xfc000
   f1824:      	ldr	x17, [x16, #0xf98]
   f1828:      	add	x16, x16, #0xf98
   f182c:      	br	x17

00000000000f1830 <_ZNSt6__ndk16vectorINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS4_IS6_EEE21__push_back_slow_pathIS6_EEPS6_OT_@plt>:
   f1830:      	adrp	x16, 0xfc000
   f1834:      	ldr	x17, [x16, #0xfa0]
   f1838:      	add	x16, x16, #0xfa0
   f183c:      	br	x17

00000000000f1840 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   f1840:      	adrp	x16, 0xfc000
   f1844:      	ldr	x17, [x16, #0xfa8]
   f1848:      	add	x16, x16, #0xfa8
   f184c:      	br	x17

00000000000f1850 <_ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   f1850:      	adrp	x16, 0xfc000
   f1854:      	ldr	x17, [x16, #0xfb0]
   f1858:      	add	x16, x16, #0xfb0
   f185c:      	br	x17

00000000000f1860 <atoi@plt>:
   f1860:      	adrp	x16, 0xfc000
   f1864:      	ldr	x17, [x16, #0xfb8]
   f1868:      	add	x16, x16, #0xfb8
   f186c:      	br	x17

00000000000f1870 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   f1870:      	adrp	x16, 0xfc000
   f1874:      	ldr	x17, [x16, #0xfc0]
   f1878:      	add	x16, x16, #0xfc0
   f187c:      	br	x17

00000000000f1880 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
   f1880:      	adrp	x16, 0xfc000
   f1884:      	ldr	x17, [x16, #0xfc8]
   f1888:      	add	x16, x16, #0xfc8
   f188c:      	br	x17

00000000000f1890 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
   f1890:      	adrp	x16, 0xfc000
   f1894:      	ldr	x17, [x16, #0xfd0]
   f1898:      	add	x16, x16, #0xfd0
   f189c:      	br	x17

00000000000f18a0 <__cxa_rethrow@plt>:
   f18a0:      	adrp	x16, 0xfc000
   f18a4:      	ldr	x17, [x16, #0xfd8]
   f18a8:      	add	x16, x16, #0xfd8
   f18ac:      	br	x17

00000000000f18b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   f18b0:      	adrp	x16, 0xfc000
   f18b4:      	ldr	x17, [x16, #0xfe0]
   f18b8:      	add	x16, x16, #0xfe0
   f18bc:      	br	x17

00000000000f18c0 <__emutls_get_address@plt>:
   f18c0:      	adrp	x16, 0xfc000
   f18c4:      	ldr	x17, [x16, #0xfe8]
   f18c8:      	add	x16, x16, #0xfe8
   f18cc:      	br	x17

00000000000f18d0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4copyEPcmm@plt>:
   f18d0:      	adrp	x16, 0xfc000
   f18d4:      	ldr	x17, [x16, #0xff0]
   f18d8:      	add	x16, x16, #0xff0
   f18dc:      	br	x17

00000000000f18e0 <_ZN5mizar8CodeNameEi@plt>:
   f18e0:      	adrp	x16, 0xfc000
   f18e4:      	ldr	x17, [x16, #0xff8]
   f18e8:      	add	x16, x16, #0xff8
   f18ec:      	br	x17

00000000000f18f0 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
   f18f0:      	adrp	x16, 0xfd000
   f18f4:      	ldr	x17, [x16]
   f18f8:      	add	x16, x16, #0x0
   f18fc:      	br	x17

00000000000f1900 <_ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   f1900:      	adrp	x16, 0xfd000
   f1904:      	ldr	x17, [x16, #0x8]
   f1908:      	add	x16, x16, #0x8
   f190c:      	br	x17

00000000000f1910 <getauxval@plt>:
   f1910:      	adrp	x16, 0xfd000
   f1914:      	ldr	x17, [x16, #0x10]
   f1918:      	add	x16, x16, #0x10
   f191c:      	br	x17

00000000000f1920 <strncmp@plt>:
   f1920:      	adrp	x16, 0xfd000
   f1924:      	ldr	x17, [x16, #0x18]
   f1928:      	add	x16, x16, #0x18
   f192c:      	br	x17

00000000000f1930 <fflush@plt>:
   f1930:      	adrp	x16, 0xfd000
   f1934:      	ldr	x17, [x16, #0x20]
   f1938:      	add	x16, x16, #0x20
   f193c:      	br	x17

00000000000f1940 <abort@plt>:
   f1940:      	adrp	x16, 0xfd000
   f1944:      	ldr	x17, [x16, #0x28]
   f1948:      	add	x16, x16, #0x28
   f194c:      	br	x17

00000000000f1950 <pthread_rwlock_wrlock@plt>:
   f1950:      	adrp	x16, 0xfd000
   f1954:      	ldr	x17, [x16, #0x30]
   f1958:      	add	x16, x16, #0x30
   f195c:      	br	x17

00000000000f1960 <pthread_rwlock_unlock@plt>:
   f1960:      	adrp	x16, 0xfd000
   f1964:      	ldr	x17, [x16, #0x38]
   f1968:      	add	x16, x16, #0x38
   f196c:      	br	x17

00000000000f1970 <malloc@plt>:
   f1970:      	adrp	x16, 0xfd000
   f1974:      	ldr	x17, [x16, #0x40]
   f1978:      	add	x16, x16, #0x40
   f197c:      	br	x17

00000000000f1980 <free@plt>:
   f1980:      	adrp	x16, 0xfd000
   f1984:      	ldr	x17, [x16, #0x48]
   f1988:      	add	x16, x16, #0x48
   f198c:      	br	x17

00000000000f1990 <dl_iterate_phdr@plt>:
   f1990:      	adrp	x16, 0xfd000
   f1994:      	ldr	x17, [x16, #0x50]
   f1998:      	add	x16, x16, #0x50
   f199c:      	br	x17

00000000000f19a0 <pthread_rwlock_rdlock@plt>:
   f19a0:      	adrp	x16, 0xfd000
   f19a4:      	ldr	x17, [x16, #0x58]
   f19a8:      	add	x16, x16, #0x58
   f19ac:      	br	x17

00000000000f19b0 <getpid@plt>:
   f19b0:      	adrp	x16, 0xfd000
   f19b4:      	ldr	x17, [x16, #0x60]
   f19b8:      	add	x16, x16, #0x60
   f19bc:      	br	x17

00000000000f19c0 <syscall@plt>:
   f19c0:      	adrp	x16, 0xfd000
   f19c4:      	ldr	x17, [x16, #0x68]
   f19c8:      	add	x16, x16, #0x68
   f19cc:      	br	x17

00000000000f19d0 <fwrite@plt>:
   f19d0:      	adrp	x16, 0xfd000
   f19d4:      	ldr	x17, [x16, #0x70]
   f19d8:      	add	x16, x16, #0x70
   f19dc:      	br	x17
