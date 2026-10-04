// EXPORTED & PLT DISASSEMBLY FOR libarkernel3_android.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libarkernel3_android.so (SHA-256: 81AAC3F4CDF285C4E71D0514EA985C60C5A88AC7C5CA9F1A95F812E3368799DA)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 2607, JNI Methods: 2605


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libarkernel3_android.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000000a0290 <.plt>:
   a0290:      	stp	x16, x30, [sp, #-0x10]!
   a0294:      	adrp	x16, 0xaa000
   a0298:      	ldr	x17, [x16, #0x98]
   a029c:      	add	x16, x16, #0x98
   a02a0:      	br	x17
   a02a4:      	nop
   a02a8:      	nop
   a02ac:      	nop

00000000000a02b0 <__cxa_finalize@plt>:
   a02b0:      	adrp	x16, 0xaa000
   a02b4:      	ldr	x17, [x16, #0xa0]
   a02b8:      	add	x16, x16, #0xa0
   a02bc:      	br	x17

00000000000a02c0 <__cxa_atexit@plt>:
   a02c0:      	adrp	x16, 0xaa000
   a02c4:      	ldr	x17, [x16, #0xa8]
   a02c8:      	add	x16, x16, #0xa8
   a02cc:      	br	x17

00000000000a02d0 <__register_atfork@plt>:
   a02d0:      	adrp	x16, 0xaa000
   a02d4:      	ldr	x17, [x16, #0xb0]
   a02d8:      	add	x16, x16, #0xb0
   a02dc:      	br	x17

00000000000a02e0 <_ZN8mtlabar34text53register_com_meitu_mtlab_arkernel3_freetype_GLXBitmapEP7_JNIEnv@plt>:
   a02e0:      	adrp	x16, 0xaa000
   a02e4:      	ldr	x17, [x16, #0xb8]
   a02e8:      	add	x16, x16, #0xb8
   a02ec:      	br	x17

00000000000a02f0 <__android_log_print@plt>:
   a02f0:      	adrp	x16, 0xaa000
   a02f4:      	ldr	x17, [x16, #0xc0]
   a02f8:      	add	x16, x16, #0xc0
   a02fc:      	br	x17

00000000000a0300 <__stack_chk_fail@plt>:
   a0300:      	adrp	x16, 0xaa000
   a0304:      	ldr	x17, [x16, #0xc8]
   a0308:      	add	x16, x16, #0xc8
   a030c:      	br	x17

00000000000a0310 <_ZdlPv@plt>:
   a0310:      	adrp	x16, 0xaa000
   a0314:      	ldr	x17, [x16, #0xd0]
   a0318:      	add	x16, x16, #0xd0
   a031c:      	br	x17

00000000000a0320 <strlen@plt>:
   a0320:      	adrp	x16, 0xaa000
   a0324:      	ldr	x17, [x16, #0xd8]
   a0328:      	add	x16, x16, #0xd8
   a032c:      	br	x17

00000000000a0330 <_Znwm@plt>:
   a0330:      	adrp	x16, 0xaa000
   a0334:      	ldr	x17, [x16, #0xe0]
   a0338:      	add	x16, x16, #0xe0
   a033c:      	br	x17

00000000000a0340 <memmove@plt>:
   a0340:      	adrp	x16, 0xaa000
   a0344:      	ldr	x17, [x16, #0xe8]
   a0348:      	add	x16, x16, #0xe8
   a034c:      	br	x17

00000000000a0350 <__cxa_allocate_exception@plt>:
   a0350:      	adrp	x16, 0xaa000
   a0354:      	ldr	x17, [x16, #0xf0]
   a0358:      	add	x16, x16, #0xf0
   a035c:      	br	x17

00000000000a0360 <__cxa_throw@plt>:
   a0360:      	adrp	x16, 0xaa000
   a0364:      	ldr	x17, [x16, #0xf8]
   a0368:      	add	x16, x16, #0xf8
   a036c:      	br	x17

00000000000a0370 <__cxa_free_exception@plt>:
   a0370:      	adrp	x16, 0xaa000
   a0374:      	ldr	x17, [x16, #0x100]
   a0378:      	add	x16, x16, #0x100
   a037c:      	br	x17

00000000000a0380 <_ZNSt11logic_errorC2EPKc@plt>:
   a0380:      	adrp	x16, 0xaa000
   a0384:      	ldr	x17, [x16, #0x108]
   a0388:      	add	x16, x16, #0x108
   a038c:      	br	x17

00000000000a0390 <__cxa_begin_catch@plt>:
   a0390:      	adrp	x16, 0xaa000
   a0394:      	ldr	x17, [x16, #0x110]
   a0398:      	add	x16, x16, #0x110
   a039c:      	br	x17

00000000000a03a0 <__cxa_end_catch@plt>:
   a03a0:      	adrp	x16, 0xaa000
   a03a4:      	ldr	x17, [x16, #0x118]
   a03a8:      	add	x16, x16, #0x118
   a03ac:      	br	x17

00000000000a03b0 <_ZSt9terminatev@plt>:
   a03b0:      	adrp	x16, 0xaa000
   a03b4:      	ldr	x17, [x16, #0x120]
   a03b8:      	add	x16, x16, #0x120
   a03bc:      	br	x17

00000000000a03c0 <memset@plt>:
   a03c0:      	adrp	x16, 0xaa000
   a03c4:      	ldr	x17, [x16, #0x128]
   a03c8:      	add	x16, x16, #0x128
   a03cc:      	br	x17

00000000000a03d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   a03d0:      	adrp	x16, 0xaa000
   a03d4:      	ldr	x17, [x16, #0x130]
   a03d8:      	add	x16, x16, #0x130
   a03dc:      	br	x17

00000000000a03e0 <strncpy@plt>:
   a03e0:      	adrp	x16, 0xaa000
   a03e4:      	ldr	x17, [x16, #0x138]
   a03e8:      	add	x16, x16, #0x138
   a03ec:      	br	x17

00000000000a03f0 <_ZNK8mtlabar317DetailEnumeration14getDisplayNameEv@plt>:
   a03f0:      	adrp	x16, 0xaa000
   a03f4:      	ldr	x17, [x16, #0x140]
   a03f8:      	add	x16, x16, #0x140
   a03fc:      	br	x17

00000000000a0400 <_ZNK8mtlabar317DetailEnumeration15getElementCountEv@plt>:
   a0400:      	adrp	x16, 0xaa000
   a0404:      	ldr	x17, [x16, #0x148]
   a0408:      	add	x16, x16, #0x148
   a040c:      	br	x17

00000000000a0410 <_ZNK8mtlabar317DetailEnumeration15getElementValueEm@plt>:
   a0410:      	adrp	x16, 0xaa000
   a0414:      	ldr	x17, [x16, #0x150]
   a0418:      	add	x16, x16, #0x150
   a041c:      	br	x17

00000000000a0420 <_ZNK8mtlabar317DetailEnumeration21getElementDisplayNameEm@plt>:
   a0420:      	adrp	x16, 0xaa000
   a0424:      	ldr	x17, [x16, #0x158]
   a0428:      	add	x16, x16, #0x158
   a042c:      	br	x17

00000000000a0430 <_ZNK8mtlabar38Property14getDisplayNameEv@plt>:
   a0430:      	adrp	x16, 0xaa000
   a0434:      	ldr	x17, [x16, #0x160]
   a0438:      	add	x16, x16, #0x160
   a043c:      	br	x17

00000000000a0440 <_ZNK8mtlabar38Property7getTypeEv@plt>:
   a0440:      	adrp	x16, 0xaa000
   a0444:      	ldr	x17, [x16, #0x168]
   a0448:      	add	x16, x16, #0x168
   a044c:      	br	x17

00000000000a0450 <_ZNK8mtlabar38Property8isHideUIEv@plt>:
   a0450:      	adrp	x16, 0xaa000
   a0454:      	ldr	x17, [x16, #0x170]
   a0458:      	add	x16, x16, #0x170
   a045c:      	br	x17

00000000000a0460 <_ZNK8mtlabar38Property15getDefaultValueEv@plt>:
   a0460:      	adrp	x16, 0xaa000
   a0464:      	ldr	x17, [x16, #0x178]
   a0468:      	add	x16, x16, #0x178
   a046c:      	br	x17

00000000000a0470 <_ZNK8mtlabar38Property10getMaximumEv@plt>:
   a0470:      	adrp	x16, 0xaa000
   a0474:      	ldr	x17, [x16, #0x180]
   a0478:      	add	x16, x16, #0x180
   a047c:      	br	x17

00000000000a0480 <_ZNK8mtlabar38Property10getMinimumEv@plt>:
   a0480:      	adrp	x16, 0xaa000
   a0484:      	ldr	x17, [x16, #0x188]
   a0488:      	add	x16, x16, #0x188
   a048c:      	br	x17

00000000000a0490 <_ZNK8mtlabar314DetailCategory14getDisplayNameEv@plt>:
   a0490:      	adrp	x16, 0xaa000
   a0494:      	ldr	x17, [x16, #0x190]
   a0498:      	add	x16, x16, #0x190
   a049c:      	br	x17

00000000000a04a0 <_ZNK8mtlabar314DetailCategory21getBasicCategoryCountEv@plt>:
   a04a0:      	adrp	x16, 0xaa000
   a04a4:      	ldr	x17, [x16, #0x198]
   a04a8:      	add	x16, x16, #0x198
   a04ac:      	br	x17

00000000000a04b0 <_ZNK8mtlabar314DetailCategory16getBasicCategoryEm@plt>:
   a04b0:      	adrp	x16, 0xaa000
   a04b4:      	ldr	x17, [x16, #0x1a0]
   a04b8:      	add	x16, x16, #0x1a0
   a04bc:      	br	x17

00000000000a04c0 <_ZNK8mtlabar314DetailCategory16getPropertyCountEv@plt>:
   a04c0:      	adrp	x16, 0xaa000
   a04c4:      	ldr	x17, [x16, #0x1a8]
   a04c8:      	add	x16, x16, #0x1a8
   a04cc:      	br	x17

00000000000a04d0 <_ZNK8mtlabar314DetailCategory11getPropertyEm@plt>:
   a04d0:      	adrp	x16, 0xaa000
   a04d4:      	ldr	x17, [x16, #0x1b0]
   a04d8:      	add	x16, x16, #0x1b0
   a04dc:      	br	x17

00000000000a04e0 <_ZNK8mtlabar35Field7getTypeEv@plt>:
   a04e0:      	adrp	x16, 0xaa000
   a04e4:      	ldr	x17, [x16, #0x1b8]
   a04e8:      	add	x16, x16, #0x1b8
   a04ec:      	br	x17

00000000000a04f0 <_ZNK8mtlabar35Field8getValueEv@plt>:
   a04f0:      	adrp	x16, 0xaa000
   a04f4:      	ldr	x17, [x16, #0x1c0]
   a04f8:      	add	x16, x16, #0x1c0
   a04fc:      	br	x17

00000000000a0500 <memcpy@plt>:
   a0500:      	adrp	x16, 0xaa000
   a0504:      	ldr	x17, [x16, #0x1c8]
   a0508:      	add	x16, x16, #0x1c8
   a050c:      	br	x17

00000000000a0510 <_ZN8mtlabar35Field8setValueERKNS_14ParameterValueE@plt>:
   a0510:      	adrp	x16, 0xaa000
   a0514:      	ldr	x17, [x16, #0x1d0]
   a0518:      	add	x16, x16, #0x1d0
   a051c:      	br	x17

00000000000a0520 <_ZNK8mtlabar35Field13getChildCountEv@plt>:
   a0520:      	adrp	x16, 0xaa000
   a0524:      	ldr	x17, [x16, #0x1d8]
   a0528:      	add	x16, x16, #0x1d8
   a052c:      	br	x17

00000000000a0530 <_ZN8mtlabar35Field15getChildByIndexEm@plt>:
   a0530:      	adrp	x16, 0xaa000
   a0534:      	ldr	x17, [x16, #0x1e0]
   a0538:      	add	x16, x16, #0x1e0
   a053c:      	br	x17

00000000000a0540 <_ZN8mtlabar35Field14getChildByNameEPKc@plt>:
   a0540:      	adrp	x16, 0xaa000
   a0544:      	ldr	x17, [x16, #0x1e8]
   a0548:      	add	x16, x16, #0x1e8
   a054c:      	br	x17

00000000000a0550 <_ZN8mtlabar35Field11resizeChildEm@plt>:
   a0550:      	adrp	x16, 0xaa000
   a0554:      	ldr	x17, [x16, #0x1f0]
   a0558:      	add	x16, x16, #0x1f0
   a055c:      	br	x17

00000000000a0560 <_ZN8mtlabar35Field10eraseChildEm@plt>:
   a0560:      	adrp	x16, 0xaa000
   a0564:      	ldr	x17, [x16, #0x1f8]
   a0568:      	add	x16, x16, #0x1f8
   a056c:      	br	x17

00000000000a0570 <_ZNK8mtlabar35Field17getBaseClassCountEv@plt>:
   a0570:      	adrp	x16, 0xaa000
   a0574:      	ldr	x17, [x16, #0x200]
   a0578:      	add	x16, x16, #0x200
   a057c:      	br	x17

00000000000a0580 <_ZN8mtlabar35Field19getBaseClassByIndexEm@plt>:
   a0580:      	adrp	x16, 0xaa000
   a0584:      	ldr	x17, [x16, #0x208]
   a0588:      	add	x16, x16, #0x208
   a058c:      	br	x17

00000000000a0590 <_ZNK8mtlabar35Field17detailEnumerationEv@plt>:
   a0590:      	adrp	x16, 0xaa000
   a0594:      	ldr	x17, [x16, #0x210]
   a0598:      	add	x16, x16, #0x210
   a059c:      	br	x17

00000000000a05a0 <_ZNK8mtlabar35Field14detailCategoryEv@plt>:
   a05a0:      	adrp	x16, 0xaa000
   a05a4:      	ldr	x17, [x16, #0x218]
   a05a8:      	add	x16, x16, #0x218
   a05ac:      	br	x17

00000000000a05b0 <_ZN8mtlabar313LayoutDetails15getCurrentFieldEv@plt>:
   a05b0:      	adrp	x16, 0xaa000
   a05b4:      	ldr	x17, [x16, #0x220]
   a05b8:      	add	x16, x16, #0x220
   a05bc:      	br	x17

00000000000a05c0 <_ZNK8mtlabar313LayoutDetails11getCategoryERKPKc@plt>:
   a05c0:      	adrp	x16, 0xaa000
   a05c4:      	ldr	x17, [x16, #0x228]
   a05c8:      	add	x16, x16, #0x228
   a05cc:      	br	x17

00000000000a05d0 <_ZNK8mtlabar313LayoutDetails14getEnumerationERKPKc@plt>:
   a05d0:      	adrp	x16, 0xaa000
   a05d4:      	ldr	x17, [x16, #0x230]
   a05d8:      	add	x16, x16, #0x230
   a05dc:      	br	x17

00000000000a05e0 <_ZN8mtlabar327ChannelTextureDataInterface17setChannelTextureENS_21MultiInputChannelTypeEP15WGPUTextureImpl@plt>:
   a05e0:      	adrp	x16, 0xaa000
   a05e4:      	ldr	x17, [x16, #0x238]
   a05e8:      	add	x16, x16, #0x238
   a05ec:      	br	x17

00000000000a05f0 <_ZNK8mtlabar327ChannelTextureDataInterface17getChannelTextureENS_21MultiInputChannelTypeE@plt>:
   a05f0:      	adrp	x16, 0xaa000
   a05f4:      	ldr	x17, [x16, #0x240]
   a05f8:      	add	x16, x16, #0x240
   a05fc:      	br	x17

00000000000a0600 <_ZN8mtlabar327ChannelTextureDataInterface22resetAllChannelTextureEv@plt>:
   a0600:      	adrp	x16, 0xaa000
   a0604:      	ldr	x17, [x16, #0x248]
   a0608:      	add	x16, x16, #0x248
   a060c:      	br	x17

00000000000a0610 <_ZNK8mtlabar327ChannelTextureDataInterface22getChannelTextureWidthENS_21MultiInputChannelTypeE@plt>:
   a0610:      	adrp	x16, 0xaa000
   a0614:      	ldr	x17, [x16, #0x250]
   a0618:      	add	x16, x16, #0x250
   a061c:      	br	x17

00000000000a0620 <_ZNK8mtlabar327ChannelTextureDataInterface23getChannelTextureHeightENS_21MultiInputChannelTypeE@plt>:
   a0620:      	adrp	x16, 0xaa000
   a0624:      	ldr	x17, [x16, #0x258]
   a0628:      	add	x16, x16, #0x258
   a062c:      	br	x17

00000000000a0630 <_ZN8mtlabar324MainTextureDataInterface15setMainTextureAEP15WGPUTextureImpl@plt>:
   a0630:      	adrp	x16, 0xaa000
   a0634:      	ldr	x17, [x16, #0x260]
   a0638:      	add	x16, x16, #0x260
   a063c:      	br	x17

00000000000a0640 <_ZN8mtlabar324MainTextureDataInterface15setMainTextureBEP15WGPUTextureImpl@plt>:
   a0640:      	adrp	x16, 0xaa000
   a0644:      	ldr	x17, [x16, #0x268]
   a0648:      	add	x16, x16, #0x268
   a064c:      	br	x17

00000000000a0650 <_ZN8mtlabar324MainTextureDataInterface24setMainTextureColorSpaceENS_10ColorSpaceE@plt>:
   a0650:      	adrp	x16, 0xaa000
   a0654:      	ldr	x17, [x16, #0x270]
   a0658:      	add	x16, x16, #0x270
   a065c:      	br	x17

00000000000a0660 <_ZN8mtlabar324MainTextureDataInterface18releaseMainTextureEv@plt>:
   a0660:      	adrp	x16, 0xaa000
   a0664:      	ldr	x17, [x16, #0x278]
   a0668:      	add	x16, x16, #0x278
   a066c:      	br	x17

00000000000a0670 <_ZNK8mtlabar324MainTextureDataInterface15getMainTextureAEv@plt>:
   a0670:      	adrp	x16, 0xaa000
   a0674:      	ldr	x17, [x16, #0x280]
   a0678:      	add	x16, x16, #0x280
   a067c:      	br	x17

00000000000a0680 <_ZNK8mtlabar324MainTextureDataInterface15getMainTextureBEv@plt>:
   a0680:      	adrp	x16, 0xaa000
   a0684:      	ldr	x17, [x16, #0x288]
   a0688:      	add	x16, x16, #0x288
   a068c:      	br	x17

00000000000a0690 <_ZNK8mtlabar324MainTextureDataInterface15getTextureWidthEv@plt>:
   a0690:      	adrp	x16, 0xaa000
   a0694:      	ldr	x17, [x16, #0x290]
   a0698:      	add	x16, x16, #0x290
   a069c:      	br	x17

00000000000a06a0 <_ZNK8mtlabar324MainTextureDataInterface16getTextureHeightEv@plt>:
   a06a0:      	adrp	x16, 0xaa000
   a06a4:      	ldr	x17, [x16, #0x298]
   a06a8:      	add	x16, x16, #0x298
   a06ac:      	br	x17

00000000000a06b0 <_ZN8mtlabar318FrameInfoInterface24setDeviceOrientationTypeE21DeviceOrientationType@plt>:
   a06b0:      	adrp	x16, 0xaa000
   a06b4:      	ldr	x17, [x16, #0x2a0]
   a06b8:      	add	x16, x16, #0x2a0
   a06bc:      	br	x17

00000000000a06c0 <_ZNK8mtlabar318FrameInfoInterface24getDeviceOrientationTypeEv@plt>:
   a06c0:      	adrp	x16, 0xaa000
   a06c4:      	ldr	x17, [x16, #0x2a8]
   a06c8:      	add	x16, x16, #0x2a8
   a06cc:      	br	x17

00000000000a06d0 <_ZN8mtlabar318FrameInfoInterface18setFrameInfoOptionE15FrameInfoOptionb@plt>:
   a06d0:      	adrp	x16, 0xaa000
   a06d4:      	ldr	x17, [x16, #0x2b0]
   a06d8:      	add	x16, x16, #0x2b0
   a06dc:      	br	x17

00000000000a06e0 <_ZNK8mtlabar318FrameInfoInterface18getFrameInfoOptionE15FrameInfoOption@plt>:
   a06e0:      	adrp	x16, 0xaa000
   a06e4:      	ldr	x17, [x16, #0x2b8]
   a06e8:      	add	x16, x16, #0x2b8
   a06ec:      	br	x17

00000000000a06f0 <_ZN8mtlabar318FrameDataInterface27getMainTextureDataInterfaceEv@plt>:
   a06f0:      	adrp	x16, 0xaa000
   a06f4:      	ldr	x17, [x16, #0x2c0]
   a06f8:      	add	x16, x16, #0x2c0
   a06fc:      	br	x17

00000000000a0700 <_ZN8mtlabar318FrameDataInterface30getChannelTextureDataInterfaceEv@plt>:
   a0700:      	adrp	x16, 0xaa000
   a0704:      	ldr	x17, [x16, #0x2c8]
   a0708:      	add	x16, x16, #0x2c8
   a070c:      	br	x17

00000000000a0710 <_ZN8mtlabar318FrameDataInterface21getFrameInfoInterfaceEv@plt>:
   a0710:      	adrp	x16, 0xaa000
   a0714:      	ldr	x17, [x16, #0x2d0]
   a0718:      	add	x16, x16, #0x2d0
   a071c:      	br	x17

00000000000a0720 <_ZN8mtlabar318FrameDataInterface15setDataProtocolEP18vldp_data_protocol@plt>:
   a0720:      	adrp	x16, 0xaa000
   a0724:      	ldr	x17, [x16, #0x2d8]
   a0728:      	add	x16, x16, #0x2d8
   a072c:      	br	x17

00000000000a0730 <_ZNK8mtlabar318FrameDataInterface15getDataProtocolEv@plt>:
   a0730:      	adrp	x16, 0xaa000
   a0734:      	ldr	x17, [x16, #0x2e0]
   a0738:      	add	x16, x16, #0x2e0
   a073c:      	br	x17

00000000000a0740 <_ZNK8mtlabar38FaceData9hasFaceIDEv@plt>:
   a0740:      	adrp	x16, 0xaa000
   a0744:      	ldr	x17, [x16, #0x2e8]
   a0748:      	add	x16, x16, #0x2e8
   a074c:      	br	x17

00000000000a0750 <_ZNK8mtlabar38FaceData9getFaceIDEv@plt>:
   a0750:      	adrp	x16, 0xaa000
   a0754:      	ldr	x17, [x16, #0x2f0]
   a0758:      	add	x16, x16, #0x2f0
   a075c:      	br	x17

00000000000a0760 <_ZN8mtlabar38FaceData9setFaceIDEi@plt>:
   a0760:      	adrp	x16, 0xaa000
   a0764:      	ldr	x17, [x16, #0x2f8]
   a0768:      	add	x16, x16, #0x2f8
   a076c:      	br	x17

00000000000a0770 <_ZNK8mtlabar38FaceData11hasFaceRectEv@plt>:
   a0770:      	adrp	x16, 0xaa000
   a0774:      	ldr	x17, [x16, #0x300]
   a0778:      	add	x16, x16, #0x300
   a077c:      	br	x17

00000000000a0780 <_ZNK8mtlabar38FaceData11getFaceRectEv@plt>:
   a0780:      	adrp	x16, 0xaa000
   a0784:      	ldr	x17, [x16, #0x308]
   a0788:      	add	x16, x16, #0x308
   a078c:      	br	x17

00000000000a0790 <_ZN8mtlabar38FaceData11setFaceRectERKNS_6Rect2FE@plt>:
   a0790:      	adrp	x16, 0xaa000
   a0794:      	ldr	x17, [x16, #0x310]
   a0798:      	add	x16, x16, #0x310
   a079c:      	br	x17

00000000000a07a0 <_ZNK8mtlabar38FaceData24getFacialLandmark2DCountEv@plt>:
   a07a0:      	adrp	x16, 0xaa000
   a07a4:      	ldr	x17, [x16, #0x318]
   a07a8:      	add	x16, x16, #0x318
   a07ac:      	br	x17

00000000000a07b0 <_ZNK8mtlabar38FaceData19getFacialLandmark2DEv@plt>:
   a07b0:      	adrp	x16, 0xaa000
   a07b4:      	ldr	x17, [x16, #0x320]
   a07b8:      	add	x16, x16, #0x320
   a07bc:      	br	x17

00000000000a07c0 <_ZN8mtlabar38FaceData19setFacialLandmark2DEPKNS_6Float2Ei@plt>:
   a07c0:      	adrp	x16, 0xaa000
   a07c4:      	ldr	x17, [x16, #0x328]
   a07c8:      	add	x16, x16, #0x328
   a07cc:      	br	x17

00000000000a07d0 <_ZNK8mtlabar38FaceData31getFacialLandmark2DVisibleCountEv@plt>:
   a07d0:      	adrp	x16, 0xaa000
   a07d4:      	ldr	x17, [x16, #0x330]
   a07d8:      	add	x16, x16, #0x330
   a07dc:      	br	x17

00000000000a07e0 <_ZNK8mtlabar38FaceData26getFacialLandmark2DVisibleEv@plt>:
   a07e0:      	adrp	x16, 0xaa000
   a07e4:      	ldr	x17, [x16, #0x338]
   a07e8:      	add	x16, x16, #0x338
   a07ec:      	br	x17

00000000000a07f0 <_ZN8mtlabar38FaceData26setFacialLandmark2DVisibleEPKfi@plt>:
   a07f0:      	adrp	x16, 0xaa000
   a07f4:      	ldr	x17, [x16, #0x340]
   a07f8:      	add	x16, x16, #0x340
   a07fc:      	br	x17

00000000000a0800 <_ZNK8mtlabar38FaceData17getHeadPointCountEv@plt>:
   a0800:      	adrp	x16, 0xaa000
   a0804:      	ldr	x17, [x16, #0x348]
   a0808:      	add	x16, x16, #0x348
   a080c:      	br	x17

00000000000a0810 <_ZNK8mtlabar38FaceData13getHeadPointsEv@plt>:
   a0810:      	adrp	x16, 0xaa000
   a0814:      	ldr	x17, [x16, #0x350]
   a0818:      	add	x16, x16, #0x350
   a081c:      	br	x17

00000000000a0820 <_ZN8mtlabar38FaceData13setHeadPointsEPKNS_6Float2Ei@plt>:
   a0820:      	adrp	x16, 0xaa000
   a0824:      	ldr	x17, [x16, #0x358]
   a0828:      	add	x16, x16, #0x358
   a082c:      	br	x17

00000000000a0830 <_ZNK8mtlabar38FaceData24getFacialInterPointCountEv@plt>:
   a0830:      	adrp	x16, 0xaa000
   a0834:      	ldr	x17, [x16, #0x360]
   a0838:      	add	x16, x16, #0x360
   a083c:      	br	x17

00000000000a0840 <_ZNK8mtlabar38FaceData19getFacialInterPointEv@plt>:
   a0840:      	adrp	x16, 0xaa000
   a0844:      	ldr	x17, [x16, #0x368]
   a0848:      	add	x16, x16, #0x368
   a084c:      	br	x17

00000000000a0850 <_ZN8mtlabar38FaceData19setFacialInterPointEPKNS_6Float2Ei@plt>:
   a0850:      	adrp	x16, 0xaa000
   a0854:      	ldr	x17, [x16, #0x370]
   a0858:      	add	x16, x16, #0x370
   a085c:      	br	x17

00000000000a0860 <_ZNK8mtlabar38FaceData32getFacialInterPointNewModelCountEv@plt>:
   a0860:      	adrp	x16, 0xaa000
   a0864:      	ldr	x17, [x16, #0x378]
   a0868:      	add	x16, x16, #0x378
   a086c:      	br	x17

00000000000a0870 <_ZNK8mtlabar38FaceData27getFacialInterPointNewModelEv@plt>:
   a0870:      	adrp	x16, 0xaa000
   a0874:      	ldr	x17, [x16, #0x380]
   a0878:      	add	x16, x16, #0x380
   a087c:      	br	x17

00000000000a0880 <_ZN8mtlabar38FaceData27setFacialInterPointNewModelEPKNS_6Float2Ei@plt>:
   a0880:      	adrp	x16, 0xaa000
   a0884:      	ldr	x17, [x16, #0x388]
   a0888:      	add	x16, x16, #0x388
   a088c:      	br	x17

00000000000a0890 <_ZNK8mtlabar317FaceDataInterface13getDetectSizeEv@plt>:
   a0890:      	adrp	x16, 0xaa000
   a0894:      	ldr	x17, [x16, #0x390]
   a0898:      	add	x16, x16, #0x390
   a089c:      	br	x17

00000000000a08a0 <_ZN8mtlabar317FaceDataInterface13setDetectSizeERKNS_5SizeFE@plt>:
   a08a0:      	adrp	x16, 0xaa000
   a08a4:      	ldr	x17, [x16, #0x398]
   a08a8:      	add	x16, x16, #0x398
   a08ac:      	br	x17

00000000000a08b0 <_ZNK8mtlabar317FaceDataInterface12getFaceCountEv@plt>:
   a08b0:      	adrp	x16, 0xaa000
   a08b4:      	ldr	x17, [x16, #0x3a0]
   a08b8:      	add	x16, x16, #0x3a0
   a08bc:      	br	x17

00000000000a08c0 <_ZNK8mtlabar317FaceDataInterface21getFaceDataArrayConstEv@plt>:
   a08c0:      	adrp	x16, 0xaa000
   a08c4:      	ldr	x17, [x16, #0x3a8]
   a08c8:      	add	x16, x16, #0x3a8
   a08cc:      	br	x17

00000000000a08d0 <_ZN8mtlabar317FaceDataInterface16getFaceDataArrayEv@plt>:
   a08d0:      	adrp	x16, 0xaa000
   a08d4:      	ldr	x17, [x16, #0x3b0]
   a08d8:      	add	x16, x16, #0x3b0
   a08dc:      	br	x17

00000000000a08e0 <_ZN8mtlabar317FaceDataInterface16setFaceDataArrayEPKNS_8FaceDataEi@plt>:
   a08e0:      	adrp	x16, 0xaa000
   a08e4:      	ldr	x17, [x16, #0x3b8]
   a08e8:      	add	x16, x16, #0x3b8
   a08ec:      	br	x17

00000000000a08f0 <_ZdaPv@plt>:
   a08f0:      	adrp	x16, 0xaa000
   a08f4:      	ldr	x17, [x16, #0x3c0]
   a08f8:      	add	x16, x16, #0x3c0
   a08fc:      	br	x17

00000000000a0900 <_Znam@plt>:
   a0900:      	adrp	x16, 0xaa000
   a0904:      	ldr	x17, [x16, #0x3c8]
   a0908:      	add	x16, x16, #0x3c8
   a090c:      	br	x17

00000000000a0910 <strcpy@plt>:
   a0910:      	adrp	x16, 0xaa000
   a0914:      	ldr	x17, [x16, #0x3d0]
   a0918:      	add	x16, x16, #0x3d0
   a091c:      	br	x17

00000000000a0920 <_ZN8mtlabar332TextBackgroundColorConfiguration6createEv@plt>:
   a0920:      	adrp	x16, 0xaa000
   a0924:      	ldr	x17, [x16, #0x3d8]
   a0928:      	add	x16, x16, #0x3d8
   a092c:      	br	x17

00000000000a0930 <_ZN8mtlabar332TextBackgroundColorConfiguration7destroyEPS0_@plt>:
   a0930:      	adrp	x16, 0xaa000
   a0934:      	ldr	x17, [x16, #0x3e0]
   a0938:      	add	x16, x16, #0x3e0
   a093c:      	br	x17

00000000000a0940 <_ZN8mtlabar332TextBackgroundColorConfiguration8deepCopyEPKS0_@plt>:
   a0940:      	adrp	x16, 0xaa000
   a0944:      	ldr	x17, [x16, #0x3e8]
   a0948:      	add	x16, x16, #0x3e8
   a094c:      	br	x17

00000000000a0950 <_ZNK8mtlabar332TextBackgroundColorConfiguration9getEnableEv@plt>:
   a0950:      	adrp	x16, 0xaa000
   a0954:      	ldr	x17, [x16, #0x3f0]
   a0958:      	add	x16, x16, #0x3f0
   a095c:      	br	x17

00000000000a0960 <_ZN8mtlabar332TextBackgroundColorConfiguration9setEnableEb@plt>:
   a0960:      	adrp	x16, 0xaa000
   a0964:      	ldr	x17, [x16, #0x3f8]
   a0968:      	add	x16, x16, #0x3f8
   a096c:      	br	x17

00000000000a0970 <_ZNK8mtlabar332TextBackgroundColorConfiguration11getEditableEv@plt>:
   a0970:      	adrp	x16, 0xaa000
   a0974:      	ldr	x17, [x16, #0x400]
   a0978:      	add	x16, x16, #0x400
   a097c:      	br	x17

00000000000a0980 <_ZN8mtlabar332TextBackgroundColorConfiguration11setEditableEb@plt>:
   a0980:      	adrp	x16, 0xaa000
   a0984:      	ldr	x17, [x16, #0x408]
   a0988:      	add	x16, x16, #0x408
   a098c:      	br	x17

00000000000a0990 <_ZNK8mtlabar332TextBackgroundColorConfiguration9getColorAEv@plt>:
   a0990:      	adrp	x16, 0xaa000
   a0994:      	ldr	x17, [x16, #0x410]
   a0998:      	add	x16, x16, #0x410
   a099c:      	br	x17

00000000000a09a0 <_ZN8mtlabar332TextBackgroundColorConfiguration9setColorAERKNS_6ColorAE@plt>:
   a09a0:      	adrp	x16, 0xaa000
   a09a4:      	ldr	x17, [x16, #0x418]
   a09a8:      	add	x16, x16, #0x418
   a09ac:      	br	x17

00000000000a09b0 <_ZNK8mtlabar332TextBackgroundColorConfiguration12getColorWorkEv@plt>:
   a09b0:      	adrp	x16, 0xaa000
   a09b4:      	ldr	x17, [x16, #0x420]
   a09b8:      	add	x16, x16, #0x420
   a09bc:      	br	x17

00000000000a09c0 <_ZN8mtlabar332TextBackgroundColorConfiguration12setColorWorkEb@plt>:
   a09c0:      	adrp	x16, 0xaa000
   a09c4:      	ldr	x17, [x16, #0x428]
   a09c8:      	add	x16, x16, #0x428
   a09cc:      	br	x17

00000000000a09d0 <_ZNK8mtlabar332TextBackgroundColorConfiguration9getMarginEv@plt>:
   a09d0:      	adrp	x16, 0xaa000
   a09d4:      	ldr	x17, [x16, #0x430]
   a09d8:      	add	x16, x16, #0x430
   a09dc:      	br	x17

00000000000a09e0 <_ZN8mtlabar332TextBackgroundColorConfiguration9setMarginEi@plt>:
   a09e0:      	adrp	x16, 0xaa000
   a09e4:      	ldr	x17, [x16, #0x438]
   a09e8:      	add	x16, x16, #0x438
   a09ec:      	br	x17

00000000000a09f0 <_ZNK8mtlabar332TextBackgroundColorConfiguration14getRoundWeightEv@plt>:
   a09f0:      	adrp	x16, 0xaa000
   a09f4:      	ldr	x17, [x16, #0x440]
   a09f8:      	add	x16, x16, #0x440
   a09fc:      	br	x17

00000000000a0a00 <_ZN8mtlabar332TextBackgroundColorConfiguration14setRoundWeightEf@plt>:
   a0a00:      	adrp	x16, 0xaa000
   a0a04:      	ldr	x17, [x16, #0x448]
   a0a08:      	add	x16, x16, #0x448
   a0a0c:      	br	x17

00000000000a0a10 <_ZNK8mtlabar332TextBackgroundColorConfiguration19getMarginExtendCoefEv@plt>:
   a0a10:      	adrp	x16, 0xaa000
   a0a14:      	ldr	x17, [x16, #0x450]
   a0a18:      	add	x16, x16, #0x450
   a0a1c:      	br	x17

00000000000a0a20 <_ZN8mtlabar332TextBackgroundColorConfiguration19setMarginExtendCoefERKNS_5RectFE@plt>:
   a0a20:      	adrp	x16, 0xaa000
   a0a24:      	ldr	x17, [x16, #0x458]
   a0a28:      	add	x16, x16, #0x458
   a0a2c:      	br	x17

00000000000a0a30 <_ZN8mtlabar332TextBackgroundColorConfiguration15setMarginShiftXEf@plt>:
   a0a30:      	adrp	x16, 0xaa000
   a0a34:      	ldr	x17, [x16, #0x460]
   a0a38:      	add	x16, x16, #0x460
   a0a3c:      	br	x17

00000000000a0a40 <_ZNK8mtlabar332TextBackgroundColorConfiguration15getMarginShiftXEv@plt>:
   a0a40:      	adrp	x16, 0xaa000
   a0a44:      	ldr	x17, [x16, #0x468]
   a0a48:      	add	x16, x16, #0x468
   a0a4c:      	br	x17

00000000000a0a50 <_ZN8mtlabar332TextBackgroundColorConfiguration15setMarginShiftYEf@plt>:
   a0a50:      	adrp	x16, 0xaa000
   a0a54:      	ldr	x17, [x16, #0x470]
   a0a58:      	add	x16, x16, #0x470
   a0a5c:      	br	x17

00000000000a0a60 <_ZNK8mtlabar332TextBackgroundColorConfiguration15getMarginShiftYEv@plt>:
   a0a60:      	adrp	x16, 0xaa000
   a0a64:      	ldr	x17, [x16, #0x478]
   a0a68:      	add	x16, x16, #0x478
   a0a6c:      	br	x17

00000000000a0a70 <_ZN8mtlabar332TextBackgroundColorConfiguration16setMarginExtendXEf@plt>:
   a0a70:      	adrp	x16, 0xaa000
   a0a74:      	ldr	x17, [x16, #0x480]
   a0a78:      	add	x16, x16, #0x480
   a0a7c:      	br	x17

00000000000a0a80 <_ZNK8mtlabar332TextBackgroundColorConfiguration16getMarginExtendXEv@plt>:
   a0a80:      	adrp	x16, 0xaa000
   a0a84:      	ldr	x17, [x16, #0x488]
   a0a88:      	add	x16, x16, #0x488
   a0a8c:      	br	x17

00000000000a0a90 <_ZN8mtlabar332TextBackgroundColorConfiguration16setMarginExtendYEf@plt>:
   a0a90:      	adrp	x16, 0xaa000
   a0a94:      	ldr	x17, [x16, #0x490]
   a0a98:      	add	x16, x16, #0x490
   a0a9c:      	br	x17

00000000000a0aa0 <_ZNK8mtlabar332TextBackgroundColorConfiguration16getMarginExtendYEv@plt>:
   a0aa0:      	adrp	x16, 0xaa000
   a0aa4:      	ldr	x17, [x16, #0x498]
   a0aa8:      	add	x16, x16, #0x498
   a0aac:      	br	x17

00000000000a0ab0 <_ZN8mtlabar332TextBackgroundColorConfiguration11setFillTypeENS_4text14TextBgFillTypeE@plt>:
   a0ab0:      	adrp	x16, 0xaa000
   a0ab4:      	ldr	x17, [x16, #0x4a0]
   a0ab8:      	add	x16, x16, #0x4a0
   a0abc:      	br	x17

00000000000a0ac0 <_ZNK8mtlabar332TextBackgroundColorConfiguration11getFillTypeEv@plt>:
   a0ac0:      	adrp	x16, 0xaa000
   a0ac4:      	ldr	x17, [x16, #0x4a8]
   a0ac8:      	add	x16, x16, #0x4a8
   a0acc:      	br	x17

00000000000a0ad0 <_ZN8mtlabar321TextGlowConfiguration6createEv@plt>:
   a0ad0:      	adrp	x16, 0xaa000
   a0ad4:      	ldr	x17, [x16, #0x4b0]
   a0ad8:      	add	x16, x16, #0x4b0
   a0adc:      	br	x17

00000000000a0ae0 <_ZN8mtlabar321TextGlowConfiguration7destroyEPS0_@plt>:
   a0ae0:      	adrp	x16, 0xaa000
   a0ae4:      	ldr	x17, [x16, #0x4b8]
   a0ae8:      	add	x16, x16, #0x4b8
   a0aec:      	br	x17

00000000000a0af0 <_ZN8mtlabar321TextGlowConfiguration8deepCopyEPKS0_@plt>:
   a0af0:      	adrp	x16, 0xaa000
   a0af4:      	ldr	x17, [x16, #0x4c0]
   a0af8:      	add	x16, x16, #0x4c0
   a0afc:      	br	x17

00000000000a0b00 <_ZNK8mtlabar321TextGlowConfiguration9getEnableEv@plt>:
   a0b00:      	adrp	x16, 0xaa000
   a0b04:      	ldr	x17, [x16, #0x4c8]
   a0b08:      	add	x16, x16, #0x4c8
   a0b0c:      	br	x17

00000000000a0b10 <_ZN8mtlabar321TextGlowConfiguration9setEnableEb@plt>:
   a0b10:      	adrp	x16, 0xaa000
   a0b14:      	ldr	x17, [x16, #0x4d0]
   a0b18:      	add	x16, x16, #0x4d0
   a0b1c:      	br	x17

00000000000a0b20 <_ZNK8mtlabar321TextGlowConfiguration11getEditableEv@plt>:
   a0b20:      	adrp	x16, 0xaa000
   a0b24:      	ldr	x17, [x16, #0x4d8]
   a0b28:      	add	x16, x16, #0x4d8
   a0b2c:      	br	x17

00000000000a0b30 <_ZN8mtlabar321TextGlowConfiguration11setEditableEb@plt>:
   a0b30:      	adrp	x16, 0xaa000
   a0b34:      	ldr	x17, [x16, #0x4e0]
   a0b38:      	add	x16, x16, #0x4e0
   a0b3c:      	br	x17

00000000000a0b40 <_ZNK8mtlabar321TextGlowConfiguration9getColorAEv@plt>:
   a0b40:      	adrp	x16, 0xaa000
   a0b44:      	ldr	x17, [x16, #0x4e8]
   a0b48:      	add	x16, x16, #0x4e8
   a0b4c:      	br	x17

00000000000a0b50 <_ZN8mtlabar321TextGlowConfiguration9setColorAERKNS_6ColorAE@plt>:
   a0b50:      	adrp	x16, 0xaa000
   a0b54:      	ldr	x17, [x16, #0x4f0]
   a0b58:      	add	x16, x16, #0x4f0
   a0b5c:      	br	x17

00000000000a0b60 <_ZNK8mtlabar321TextGlowConfiguration12getColorWorkEv@plt>:
   a0b60:      	adrp	x16, 0xaa000
   a0b64:      	ldr	x17, [x16, #0x4f8]
   a0b68:      	add	x16, x16, #0x4f8
   a0b6c:      	br	x17

00000000000a0b70 <_ZN8mtlabar321TextGlowConfiguration12setColorWorkEb@plt>:
   a0b70:      	adrp	x16, 0xaa000
   a0b74:      	ldr	x17, [x16, #0x500]
   a0b78:      	add	x16, x16, #0x500
   a0b7c:      	br	x17

00000000000a0b80 <_ZNK8mtlabar321TextGlowConfiguration7getBlurEv@plt>:
   a0b80:      	adrp	x16, 0xaa000
   a0b84:      	ldr	x17, [x16, #0x508]
   a0b88:      	add	x16, x16, #0x508
   a0b8c:      	br	x17

00000000000a0b90 <_ZN8mtlabar321TextGlowConfiguration7setBlurEf@plt>:
   a0b90:      	adrp	x16, 0xaa000
   a0b94:      	ldr	x17, [x16, #0x510]
   a0b98:      	add	x16, x16, #0x510
   a0b9c:      	br	x17

00000000000a0ba0 <_ZNK8mtlabar321TextGlowConfiguration14getStrokeWidthEv@plt>:
   a0ba0:      	adrp	x16, 0xaa000
   a0ba4:      	ldr	x17, [x16, #0x518]
   a0ba8:      	add	x16, x16, #0x518
   a0bac:      	br	x17

00000000000a0bb0 <_ZN8mtlabar321TextGlowConfiguration14setStrokeWidthEf@plt>:
   a0bb0:      	adrp	x16, 0xaa000
   a0bb4:      	ldr	x17, [x16, #0x520]
   a0bb8:      	add	x16, x16, #0x520
   a0bbc:      	br	x17

00000000000a0bc0 <_ZN8mtlabar325TextGradientConfiguration6createEv@plt>:
   a0bc0:      	adrp	x16, 0xaa000
   a0bc4:      	ldr	x17, [x16, #0x528]
   a0bc8:      	add	x16, x16, #0x528
   a0bcc:      	br	x17

00000000000a0bd0 <_ZN8mtlabar325TextGradientConfiguration7destroyEPS0_@plt>:
   a0bd0:      	adrp	x16, 0xaa000
   a0bd4:      	ldr	x17, [x16, #0x530]
   a0bd8:      	add	x16, x16, #0x530
   a0bdc:      	br	x17

00000000000a0be0 <_ZN8mtlabar325TextGradientConfiguration8deepCopyEPKS0_@plt>:
   a0be0:      	adrp	x16, 0xaa000
   a0be4:      	ldr	x17, [x16, #0x538]
   a0be8:      	add	x16, x16, #0x538
   a0bec:      	br	x17

00000000000a0bf0 <_ZNK8mtlabar325TextGradientConfiguration9getPointsEv@plt>:
   a0bf0:      	adrp	x16, 0xaa000
   a0bf4:      	ldr	x17, [x16, #0x540]
   a0bf8:      	add	x16, x16, #0x540
   a0bfc:      	br	x17

00000000000a0c00 <_ZN8mtlabar325TextGradientConfiguration9setPointsERKNSt6__ndk16vectorINS_6Float2ENS1_9allocatorIS3_EEEE@plt>:
   a0c00:      	adrp	x16, 0xaa000
   a0c04:      	ldr	x17, [x16, #0x548]
   a0c08:      	add	x16, x16, #0x548
   a0c0c:      	br	x17

00000000000a0c10 <_ZNK8mtlabar325TextGradientConfiguration9getColorsEv@plt>:
   a0c10:      	adrp	x16, 0xaa000
   a0c14:      	ldr	x17, [x16, #0x550]
   a0c18:      	add	x16, x16, #0x550
   a0c1c:      	br	x17

00000000000a0c20 <_ZN8mtlabar325TextGradientConfiguration9setColorsERKNSt6__ndk16vectorINS_6ColorAENS1_9allocatorIS3_EEEE@plt>:
   a0c20:      	adrp	x16, 0xaa000
   a0c24:      	ldr	x17, [x16, #0x558]
   a0c28:      	add	x16, x16, #0x558
   a0c2c:      	br	x17

00000000000a0c30 <_ZNK8mtlabar325TextGradientConfiguration8getAngleEv@plt>:
   a0c30:      	adrp	x16, 0xaa000
   a0c34:      	ldr	x17, [x16, #0x560]
   a0c38:      	add	x16, x16, #0x560
   a0c3c:      	br	x17

00000000000a0c40 <_ZN8mtlabar325TextGradientConfiguration8setAngleEf@plt>:
   a0c40:      	adrp	x16, 0xaa000
   a0c44:      	ldr	x17, [x16, #0x568]
   a0c48:      	add	x16, x16, #0x568
   a0c4c:      	br	x17

00000000000a0c50 <_ZNK8mtlabar325TextGradientConfiguration8getCountEv@plt>:
   a0c50:      	adrp	x16, 0xaa000
   a0c54:      	ldr	x17, [x16, #0x570]
   a0c58:      	add	x16, x16, #0x570
   a0c5c:      	br	x17

00000000000a0c60 <_ZN8mtlabar325TextGradientConfiguration8setCountEi@plt>:
   a0c60:      	adrp	x16, 0xaa000
   a0c64:      	ldr	x17, [x16, #0x578]
   a0c68:      	add	x16, x16, #0x578
   a0c6c:      	br	x17

00000000000a0c70 <_ZN8mtlabar323TextShadowConfiguration6createEv@plt>:
   a0c70:      	adrp	x16, 0xaa000
   a0c74:      	ldr	x17, [x16, #0x580]
   a0c78:      	add	x16, x16, #0x580
   a0c7c:      	br	x17

00000000000a0c80 <_ZN8mtlabar323TextShadowConfiguration7destroyEPS0_@plt>:
   a0c80:      	adrp	x16, 0xaa000
   a0c84:      	ldr	x17, [x16, #0x588]
   a0c88:      	add	x16, x16, #0x588
   a0c8c:      	br	x17

00000000000a0c90 <_ZN8mtlabar323TextShadowConfiguration8deepCopyEPKS0_@plt>:
   a0c90:      	adrp	x16, 0xaa000
   a0c94:      	ldr	x17, [x16, #0x590]
   a0c98:      	add	x16, x16, #0x590
   a0c9c:      	br	x17

00000000000a0ca0 <_ZNK8mtlabar323TextShadowConfiguration9getEnableEv@plt>:
   a0ca0:      	adrp	x16, 0xaa000
   a0ca4:      	ldr	x17, [x16, #0x598]
   a0ca8:      	add	x16, x16, #0x598
   a0cac:      	br	x17

00000000000a0cb0 <_ZN8mtlabar323TextShadowConfiguration9setEnableEb@plt>:
   a0cb0:      	adrp	x16, 0xaa000
   a0cb4:      	ldr	x17, [x16, #0x5a0]
   a0cb8:      	add	x16, x16, #0x5a0
   a0cbc:      	br	x17

00000000000a0cc0 <_ZNK8mtlabar323TextShadowConfiguration11getEditableEv@plt>:
   a0cc0:      	adrp	x16, 0xaa000
   a0cc4:      	ldr	x17, [x16, #0x5a8]
   a0cc8:      	add	x16, x16, #0x5a8
   a0ccc:      	br	x17

00000000000a0cd0 <_ZN8mtlabar323TextShadowConfiguration11setEditableEb@plt>:
   a0cd0:      	adrp	x16, 0xaa000
   a0cd4:      	ldr	x17, [x16, #0x5b0]
   a0cd8:      	add	x16, x16, #0x5b0
   a0cdc:      	br	x17

00000000000a0ce0 <_ZNK8mtlabar323TextShadowConfiguration9getColorAEv@plt>:
   a0ce0:      	adrp	x16, 0xaa000
   a0ce4:      	ldr	x17, [x16, #0x5b8]
   a0ce8:      	add	x16, x16, #0x5b8
   a0cec:      	br	x17

00000000000a0cf0 <_ZN8mtlabar323TextShadowConfiguration9setColorAERKNS_6ColorAE@plt>:
   a0cf0:      	adrp	x16, 0xaa000
   a0cf4:      	ldr	x17, [x16, #0x5c0]
   a0cf8:      	add	x16, x16, #0x5c0
   a0cfc:      	br	x17

00000000000a0d00 <_ZNK8mtlabar323TextShadowConfiguration12getColorWorkEv@plt>:
   a0d00:      	adrp	x16, 0xaa000
   a0d04:      	ldr	x17, [x16, #0x5c8]
   a0d08:      	add	x16, x16, #0x5c8
   a0d0c:      	br	x17

00000000000a0d10 <_ZN8mtlabar323TextShadowConfiguration12setColorWorkEb@plt>:
   a0d10:      	adrp	x16, 0xaa000
   a0d14:      	ldr	x17, [x16, #0x5d0]
   a0d18:      	add	x16, x16, #0x5d0
   a0d1c:      	br	x17

00000000000a0d20 <_ZNK8mtlabar323TextShadowConfiguration9getOffsetEv@plt>:
   a0d20:      	adrp	x16, 0xaa000
   a0d24:      	ldr	x17, [x16, #0x5d8]
   a0d28:      	add	x16, x16, #0x5d8
   a0d2c:      	br	x17

00000000000a0d30 <_ZN8mtlabar323TextShadowConfiguration9setOffsetERKNS_6Float2E@plt>:
   a0d30:      	adrp	x16, 0xaa000
   a0d34:      	ldr	x17, [x16, #0x5e0]
   a0d38:      	add	x16, x16, #0x5e0
   a0d3c:      	br	x17

00000000000a0d40 <_ZNK8mtlabar323TextShadowConfiguration7getBlurEv@plt>:
   a0d40:      	adrp	x16, 0xaa000
   a0d44:      	ldr	x17, [x16, #0x5e8]
   a0d48:      	add	x16, x16, #0x5e8
   a0d4c:      	br	x17

00000000000a0d50 <_ZN8mtlabar323TextShadowConfiguration7setBlurEf@plt>:
   a0d50:      	adrp	x16, 0xaa000
   a0d54:      	ldr	x17, [x16, #0x5f0]
   a0d58:      	add	x16, x16, #0x5f0
   a0d5c:      	br	x17

00000000000a0d60 <_ZN8mtlabar323TextStrokeConfiguration6createEv@plt>:
   a0d60:      	adrp	x16, 0xaa000
   a0d64:      	ldr	x17, [x16, #0x5f8]
   a0d68:      	add	x16, x16, #0x5f8
   a0d6c:      	br	x17

00000000000a0d70 <_ZN8mtlabar323TextStrokeConfiguration7destroyEPS0_@plt>:
   a0d70:      	adrp	x16, 0xaa000
   a0d74:      	ldr	x17, [x16, #0x600]
   a0d78:      	add	x16, x16, #0x600
   a0d7c:      	br	x17

00000000000a0d80 <_ZN8mtlabar323TextStrokeConfiguration8deepCopyEPKS0_@plt>:
   a0d80:      	adrp	x16, 0xaa000
   a0d84:      	ldr	x17, [x16, #0x608]
   a0d88:      	add	x16, x16, #0x608
   a0d8c:      	br	x17

00000000000a0d90 <_ZNK8mtlabar323TextStrokeConfiguration9getEnableEv@plt>:
   a0d90:      	adrp	x16, 0xaa000
   a0d94:      	ldr	x17, [x16, #0x610]
   a0d98:      	add	x16, x16, #0x610
   a0d9c:      	br	x17

00000000000a0da0 <_ZN8mtlabar323TextStrokeConfiguration9setEnableEb@plt>:
   a0da0:      	adrp	x16, 0xaa000
   a0da4:      	ldr	x17, [x16, #0x618]
   a0da8:      	add	x16, x16, #0x618
   a0dac:      	br	x17

00000000000a0db0 <_ZNK8mtlabar323TextStrokeConfiguration11getEditableEv@plt>:
   a0db0:      	adrp	x16, 0xaa000
   a0db4:      	ldr	x17, [x16, #0x620]
   a0db8:      	add	x16, x16, #0x620
   a0dbc:      	br	x17

00000000000a0dc0 <_ZN8mtlabar323TextStrokeConfiguration11setEditableEb@plt>:
   a0dc0:      	adrp	x16, 0xaa000
   a0dc4:      	ldr	x17, [x16, #0x628]
   a0dc8:      	add	x16, x16, #0x628
   a0dcc:      	br	x17

00000000000a0dd0 <_ZNK8mtlabar323TextStrokeConfiguration9getColorAEv@plt>:
   a0dd0:      	adrp	x16, 0xaa000
   a0dd4:      	ldr	x17, [x16, #0x630]
   a0dd8:      	add	x16, x16, #0x630
   a0ddc:      	br	x17

00000000000a0de0 <_ZN8mtlabar323TextStrokeConfiguration9setColorAERKNS_6ColorAE@plt>:
   a0de0:      	adrp	x16, 0xaa000
   a0de4:      	ldr	x17, [x16, #0x638]
   a0de8:      	add	x16, x16, #0x638
   a0dec:      	br	x17

00000000000a0df0 <_ZNK8mtlabar323TextStrokeConfiguration12getColorWorkEv@plt>:
   a0df0:      	adrp	x16, 0xaa000
   a0df4:      	ldr	x17, [x16, #0x640]
   a0df8:      	add	x16, x16, #0x640
   a0dfc:      	br	x17

00000000000a0e00 <_ZN8mtlabar323TextStrokeConfiguration12setColorWorkEb@plt>:
   a0e00:      	adrp	x16, 0xaa000
   a0e04:      	ldr	x17, [x16, #0x648]
   a0e08:      	add	x16, x16, #0x648
   a0e0c:      	br	x17

00000000000a0e10 <_ZNK8mtlabar323TextStrokeConfiguration7getSizeEv@plt>:
   a0e10:      	adrp	x16, 0xaa000
   a0e14:      	ldr	x17, [x16, #0x650]
   a0e18:      	add	x16, x16, #0x650
   a0e1c:      	br	x17

00000000000a0e20 <_ZN8mtlabar323TextStrokeConfiguration7setSizeEf@plt>:
   a0e20:      	adrp	x16, 0xaa000
   a0e24:      	ldr	x17, [x16, #0x658]
   a0e28:      	add	x16, x16, #0x658
   a0e2c:      	br	x17

00000000000a0e30 <_ZN8mtlabar323TextBubbleConfiguration6createEv@plt>:
   a0e30:      	adrp	x16, 0xaa000
   a0e34:      	ldr	x17, [x16, #0x660]
   a0e38:      	add	x16, x16, #0x660
   a0e3c:      	br	x17

00000000000a0e40 <_ZN8mtlabar323TextBubbleConfiguration7destroyEPS0_@plt>:
   a0e40:      	adrp	x16, 0xaa000
   a0e44:      	ldr	x17, [x16, #0x668]
   a0e48:      	add	x16, x16, #0x668
   a0e4c:      	br	x17

00000000000a0e50 <_ZN8mtlabar323TextBubbleConfiguration8deepCopyEPKS0_@plt>:
   a0e50:      	adrp	x16, 0xaa000
   a0e54:      	ldr	x17, [x16, #0x670]
   a0e58:      	add	x16, x16, #0x670
   a0e5c:      	br	x17

00000000000a0e60 <_ZNK8mtlabar323TextBubbleConfiguration9getEnableEv@plt>:
   a0e60:      	adrp	x16, 0xaa000
   a0e64:      	ldr	x17, [x16, #0x678]
   a0e68:      	add	x16, x16, #0x678
   a0e6c:      	br	x17

00000000000a0e70 <_ZN8mtlabar323TextBubbleConfiguration9setEnableEb@plt>:
   a0e70:      	adrp	x16, 0xaa000
   a0e74:      	ldr	x17, [x16, #0x680]
   a0e78:      	add	x16, x16, #0x680
   a0e7c:      	br	x17

00000000000a0e80 <_ZNK8mtlabar323TextBubbleConfiguration11getEditableEv@plt>:
   a0e80:      	adrp	x16, 0xaa000
   a0e84:      	ldr	x17, [x16, #0x688]
   a0e88:      	add	x16, x16, #0x688
   a0e8c:      	br	x17

00000000000a0e90 <_ZN8mtlabar323TextBubbleConfiguration11setEditableEb@plt>:
   a0e90:      	adrp	x16, 0xaa000
   a0e94:      	ldr	x17, [x16, #0x690]
   a0e98:      	add	x16, x16, #0x690
   a0e9c:      	br	x17

00000000000a0ea0 <_ZNK8mtlabar323TextBubbleConfiguration10getPaddingEv@plt>:
   a0ea0:      	adrp	x16, 0xaa000
   a0ea4:      	ldr	x17, [x16, #0x698]
   a0ea8:      	add	x16, x16, #0x698
   a0eac:      	br	x17

00000000000a0eb0 <_ZN8mtlabar323TextBubbleConfiguration10setPaddingERKNS_5RectFE@plt>:
   a0eb0:      	adrp	x16, 0xaa000
   a0eb4:      	ldr	x17, [x16, #0x6a0]
   a0eb8:      	add	x16, x16, #0x6a0
   a0ebc:      	br	x17

00000000000a0ec0 <_ZNK8mtlabar323TextBubbleConfiguration12getScaleSizeEv@plt>:
   a0ec0:      	adrp	x16, 0xaa000
   a0ec4:      	ldr	x17, [x16, #0x6a8]
   a0ec8:      	add	x16, x16, #0x6a8
   a0ecc:      	br	x17

00000000000a0ed0 <_ZN8mtlabar323TextBubbleConfiguration12setScaleSizeERKNS_5RectFE@plt>:
   a0ed0:      	adrp	x16, 0xaa000
   a0ed4:      	ldr	x17, [x16, #0x6b0]
   a0ed8:      	add	x16, x16, #0x6b0
   a0edc:      	br	x17

00000000000a0ee0 <_ZN8mtlabar325TextEditableConfiguration6createEv@plt>:
   a0ee0:      	adrp	x16, 0xaa000
   a0ee4:      	ldr	x17, [x16, #0x6b8]
   a0ee8:      	add	x16, x16, #0x6b8
   a0eec:      	br	x17

00000000000a0ef0 <_ZN8mtlabar325TextEditableConfiguration7destroyEPS0_@plt>:
   a0ef0:      	adrp	x16, 0xaa000
   a0ef4:      	ldr	x17, [x16, #0x6c0]
   a0ef8:      	add	x16, x16, #0x6c0
   a0efc:      	br	x17

00000000000a0f00 <_ZN8mtlabar325TextEditableConfiguration8deepCopyEPKS0_@plt>:
   a0f00:      	adrp	x16, 0xaa000
   a0f04:      	ldr	x17, [x16, #0x6c8]
   a0f08:      	add	x16, x16, #0x6c8
   a0f0c:      	br	x17

00000000000a0f10 <_ZNK8mtlabar325TextEditableConfiguration11getEditableEv@plt>:
   a0f10:      	adrp	x16, 0xaa000
   a0f14:      	ldr	x17, [x16, #0x6d0]
   a0f18:      	add	x16, x16, #0x6d0
   a0f1c:      	br	x17

00000000000a0f20 <_ZN8mtlabar325TextEditableConfiguration11setEditableEb@plt>:
   a0f20:      	adrp	x16, 0xaa000
   a0f24:      	ldr	x17, [x16, #0x6d8]
   a0f28:      	add	x16, x16, #0x6d8
   a0f2c:      	br	x17

00000000000a0f30 <_ZNK8mtlabar325TextEditableConfiguration18getSpacingEditableEv@plt>:
   a0f30:      	adrp	x16, 0xaa000
   a0f34:      	ldr	x17, [x16, #0x6e0]
   a0f38:      	add	x16, x16, #0x6e0
   a0f3c:      	br	x17

00000000000a0f40 <_ZN8mtlabar325TextEditableConfiguration18setSpacingEditableEb@plt>:
   a0f40:      	adrp	x16, 0xaa000
   a0f44:      	ldr	x17, [x16, #0x6e8]
   a0f48:      	add	x16, x16, #0x6e8
   a0f4c:      	br	x17

00000000000a0f50 <_ZNK8mtlabar325TextEditableConfiguration22getLineSpacingEditableEv@plt>:
   a0f50:      	adrp	x16, 0xaa000
   a0f54:      	ldr	x17, [x16, #0x6f0]
   a0f58:      	add	x16, x16, #0x6f0
   a0f5c:      	br	x17

00000000000a0f60 <_ZN8mtlabar325TextEditableConfiguration22setLineSpacingEditableEb@plt>:
   a0f60:      	adrp	x16, 0xaa000
   a0f64:      	ldr	x17, [x16, #0x6f8]
   a0f68:      	add	x16, x16, #0x6f8
   a0f6c:      	br	x17

00000000000a0f70 <_ZNK8mtlabar325TextEditableConfiguration21getHorizontalEditableEv@plt>:
   a0f70:      	adrp	x16, 0xaa000
   a0f74:      	ldr	x17, [x16, #0x700]
   a0f78:      	add	x16, x16, #0x700
   a0f7c:      	br	x17

00000000000a0f80 <_ZN8mtlabar325TextEditableConfiguration21setHorizontalEditableEb@plt>:
   a0f80:      	adrp	x16, 0xaa000
   a0f84:      	ldr	x17, [x16, #0x708]
   a0f88:      	add	x16, x16, #0x708
   a0f8c:      	br	x17

00000000000a0f90 <_ZNK8mtlabar325TextEditableConfiguration19getVerticalEditableEv@plt>:
   a0f90:      	adrp	x16, 0xaa000
   a0f94:      	ldr	x17, [x16, #0x710]
   a0f98:      	add	x16, x16, #0x710
   a0f9c:      	br	x17

00000000000a0fa0 <_ZN8mtlabar325TextEditableConfiguration19setVerticalEditableEb@plt>:
   a0fa0:      	adrp	x16, 0xaa000
   a0fa4:      	ldr	x17, [x16, #0x718]
   a0fa8:      	add	x16, x16, #0x718
   a0fac:      	br	x17

00000000000a0fb0 <_ZNK8mtlabar325TextEditableConfiguration17getPinyinEditableEv@plt>:
   a0fb0:      	adrp	x16, 0xaa000
   a0fb4:      	ldr	x17, [x16, #0x720]
   a0fb8:      	add	x16, x16, #0x720
   a0fbc:      	br	x17

00000000000a0fc0 <_ZN8mtlabar325TextEditableConfiguration17setPinyinEditableEb@plt>:
   a0fc0:      	adrp	x16, 0xaa000
   a0fc4:      	ldr	x17, [x16, #0x728]
   a0fc8:      	add	x16, x16, #0x728
   a0fcc:      	br	x17

00000000000a0fd0 <_ZN8mtlabar321TextPathConfiguration6createEv@plt>:
   a0fd0:      	adrp	x16, 0xaa000
   a0fd4:      	ldr	x17, [x16, #0x730]
   a0fd8:      	add	x16, x16, #0x730
   a0fdc:      	br	x17

00000000000a0fe0 <_ZN8mtlabar321TextPathConfiguration7destroyEPS0_@plt>:
   a0fe0:      	adrp	x16, 0xaa000
   a0fe4:      	ldr	x17, [x16, #0x738]
   a0fe8:      	add	x16, x16, #0x738
   a0fec:      	br	x17

00000000000a0ff0 <_ZN8mtlabar321TextPathConfiguration8deepCopyEPKS0_@plt>:
   a0ff0:      	adrp	x16, 0xaa000
   a0ff4:      	ldr	x17, [x16, #0x740]
   a0ff8:      	add	x16, x16, #0x740
   a0ffc:      	br	x17

00000000000a1000 <_ZNK8mtlabar321TextPathConfiguration9getEnableEv@plt>:
   a1000:      	adrp	x16, 0xaa000
   a1004:      	ldr	x17, [x16, #0x748]
   a1008:      	add	x16, x16, #0x748
   a100c:      	br	x17

00000000000a1010 <_ZN8mtlabar321TextPathConfiguration9setEnableEb@plt>:
   a1010:      	adrp	x16, 0xaa000
   a1014:      	ldr	x17, [x16, #0x750]
   a1018:      	add	x16, x16, #0x750
   a101c:      	br	x17

00000000000a1020 <_ZNK8mtlabar321TextPathConfiguration11getJsonPathEv@plt>:
   a1020:      	adrp	x16, 0xaa000
   a1024:      	ldr	x17, [x16, #0x758]
   a1028:      	add	x16, x16, #0x758
   a102c:      	br	x17

00000000000a1030 <_ZN8mtlabar321TextPathConfiguration11setJsonPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1030:      	adrp	x16, 0xaa000
   a1034:      	ldr	x17, [x16, #0x760]
   a1038:      	add	x16, x16, #0x760
   a103c:      	br	x17

00000000000a1040 <_ZNK8mtlabar321TextPathConfiguration16getPerpendicularEv@plt>:
   a1040:      	adrp	x16, 0xaa000
   a1044:      	ldr	x17, [x16, #0x768]
   a1048:      	add	x16, x16, #0x768
   a104c:      	br	x17

00000000000a1050 <_ZN8mtlabar321TextPathConfiguration16setPerpendicularEb@plt>:
   a1050:      	adrp	x16, 0xaa000
   a1054:      	ldr	x17, [x16, #0x770]
   a1058:      	add	x16, x16, #0x770
   a105c:      	br	x17

00000000000a1060 <_ZNK8mtlabar321TextPathConfiguration10getReverseEv@plt>:
   a1060:      	adrp	x16, 0xaa000
   a1064:      	ldr	x17, [x16, #0x778]
   a1068:      	add	x16, x16, #0x778
   a106c:      	br	x17

00000000000a1070 <_ZN8mtlabar321TextPathConfiguration10setReverseEb@plt>:
   a1070:      	adrp	x16, 0xaa000
   a1074:      	ldr	x17, [x16, #0x780]
   a1078:      	add	x16, x16, #0x780
   a107c:      	br	x17

00000000000a1080 <_ZNK8mtlabar321TextPathConfiguration9getScaleYEv@plt>:
   a1080:      	adrp	x16, 0xaa000
   a1084:      	ldr	x17, [x16, #0x788]
   a1088:      	add	x16, x16, #0x788
   a108c:      	br	x17

00000000000a1090 <_ZN8mtlabar321TextPathConfiguration9setScaleYEf@plt>:
   a1090:      	adrp	x16, 0xaa000
   a1094:      	ldr	x17, [x16, #0x790]
   a1098:      	add	x16, x16, #0x790
   a109c:      	br	x17

00000000000a10a0 <_ZNK8mtlabar321TextPathConfiguration21getPathLengthUseRatioEv@plt>:
   a10a0:      	adrp	x16, 0xaa000
   a10a4:      	ldr	x17, [x16, #0x798]
   a10a8:      	add	x16, x16, #0x798
   a10ac:      	br	x17

00000000000a10b0 <_ZN8mtlabar321TextPathConfiguration21setPathLengthUseRatioEf@plt>:
   a10b0:      	adrp	x16, 0xaa000
   a10b4:      	ldr	x17, [x16, #0x7a0]
   a10b8:      	add	x16, x16, #0x7a0
   a10bc:      	br	x17

00000000000a10c0 <_ZNK8mtlabar321TextPathConfiguration17getPositionOffsetEv@plt>:
   a10c0:      	adrp	x16, 0xaa000
   a10c4:      	ldr	x17, [x16, #0x7a8]
   a10c8:      	add	x16, x16, #0x7a8
   a10cc:      	br	x17

00000000000a10d0 <_ZN8mtlabar321TextPathConfiguration17setPositionOffsetEf@plt>:
   a10d0:      	adrp	x16, 0xaa000
   a10d4:      	ldr	x17, [x16, #0x7b0]
   a10d8:      	add	x16, x16, #0x7b0
   a10dc:      	br	x17

00000000000a10e0 <_ZNK8mtlabar321TextPathConfiguration12getTextBoundEv@plt>:
   a10e0:      	adrp	x16, 0xaa000
   a10e4:      	ldr	x17, [x16, #0x7b8]
   a10e8:      	add	x16, x16, #0x7b8
   a10ec:      	br	x17

00000000000a10f0 <_ZN8mtlabar321TextPathConfiguration12setTextBoundEf@plt>:
   a10f0:      	adrp	x16, 0xaa000
   a10f4:      	ldr	x17, [x16, #0x7c0]
   a10f8:      	add	x16, x16, #0x7c0
   a10fc:      	br	x17

00000000000a1100 <_ZNK8mtlabar321TextPathConfiguration13getEnableBendEv@plt>:
   a1100:      	adrp	x16, 0xaa000
   a1104:      	ldr	x17, [x16, #0x7c8]
   a1108:      	add	x16, x16, #0x7c8
   a110c:      	br	x17

00000000000a1110 <_ZN8mtlabar321TextPathConfiguration13setEnableBendEb@plt>:
   a1110:      	adrp	x16, 0xaa000
   a1114:      	ldr	x17, [x16, #0x7d0]
   a1118:      	add	x16, x16, #0x7d0
   a111c:      	br	x17

00000000000a1120 <_ZNK8mtlabar321TextPathConfiguration12getBendAngleEv@plt>:
   a1120:      	adrp	x16, 0xaa000
   a1124:      	ldr	x17, [x16, #0x7d8]
   a1128:      	add	x16, x16, #0x7d8
   a112c:      	br	x17

00000000000a1130 <_ZN8mtlabar321TextPathConfiguration12setBendAngleEf@plt>:
   a1130:      	adrp	x16, 0xaa000
   a1134:      	ldr	x17, [x16, #0x7e0]
   a1138:      	add	x16, x16, #0x7e0
   a113c:      	br	x17

00000000000a1140 <_ZNK8mtlabar321TextPathConfiguration11getProgressEv@plt>:
   a1140:      	adrp	x16, 0xaa000
   a1144:      	ldr	x17, [x16, #0x7e8]
   a1148:      	add	x16, x16, #0x7e8
   a114c:      	br	x17

00000000000a1150 <_ZN8mtlabar321TextPathConfiguration11setProgressEf@plt>:
   a1150:      	adrp	x16, 0xaa000
   a1154:      	ldr	x17, [x16, #0x7f0]
   a1158:      	add	x16, x16, #0x7f0
   a115c:      	br	x17

00000000000a1160 <_ZNK8mtlabar321TextPathConfiguration19getFirstMarginRatioEv@plt>:
   a1160:      	adrp	x16, 0xaa000
   a1164:      	ldr	x17, [x16, #0x7f8]
   a1168:      	add	x16, x16, #0x7f8
   a116c:      	br	x17

00000000000a1170 <_ZN8mtlabar321TextPathConfiguration19setFirstMarginRatioEf@plt>:
   a1170:      	adrp	x16, 0xaa000
   a1174:      	ldr	x17, [x16, #0x800]
   a1178:      	add	x16, x16, #0x800
   a117c:      	br	x17

00000000000a1180 <_ZNK8mtlabar321TextPathConfiguration18getLastMarginRatioEv@plt>:
   a1180:      	adrp	x16, 0xaa000
   a1184:      	ldr	x17, [x16, #0x808]
   a1188:      	add	x16, x16, #0x808
   a118c:      	br	x17

00000000000a1190 <_ZN8mtlabar321TextPathConfiguration18setLastMarginRatioEf@plt>:
   a1190:      	adrp	x16, 0xaa000
   a1194:      	ldr	x17, [x16, #0x810]
   a1198:      	add	x16, x16, #0x810
   a119c:      	br	x17

00000000000a11a0 <_ZNK8mtlabar321TextPathConfiguration10getSpacingEv@plt>:
   a11a0:      	adrp	x16, 0xaa000
   a11a4:      	ldr	x17, [x16, #0x818]
   a11a8:      	add	x16, x16, #0x818
   a11ac:      	br	x17

00000000000a11b0 <_ZN8mtlabar321TextPathConfiguration10setSpacingEf@plt>:
   a11b0:      	adrp	x16, 0xaa000
   a11b4:      	ldr	x17, [x16, #0x820]
   a11b8:      	add	x16, x16, #0x820
   a11bc:      	br	x17

00000000000a11c0 <_ZNK8mtlabar321TextPathConfiguration20getEnableAspectRatioEv@plt>:
   a11c0:      	adrp	x16, 0xaa000
   a11c4:      	ldr	x17, [x16, #0x828]
   a11c8:      	add	x16, x16, #0x828
   a11cc:      	br	x17

00000000000a11d0 <_ZN8mtlabar321TextPathConfiguration20setEnableAspectRatioEb@plt>:
   a11d0:      	adrp	x16, 0xaa000
   a11d4:      	ldr	x17, [x16, #0x830]
   a11d8:      	add	x16, x16, #0x830
   a11dc:      	br	x17

00000000000a11e0 <_ZNK8mtlabar321TextPathConfiguration14getAspectRatioEv@plt>:
   a11e0:      	adrp	x16, 0xaa000
   a11e4:      	ldr	x17, [x16, #0x838]
   a11e8:      	add	x16, x16, #0x838
   a11ec:      	br	x17

00000000000a11f0 <_ZN8mtlabar321TextPathConfiguration14setAspectRatioEf@plt>:
   a11f0:      	adrp	x16, 0xaa000
   a11f4:      	ldr	x17, [x16, #0x840]
   a11f8:      	add	x16, x16, #0x840
   a11fc:      	br	x17

00000000000a1200 <_ZNK8mtlabar321TextPathConfiguration16getCurveTextTypeEv@plt>:
   a1200:      	adrp	x16, 0xaa000
   a1204:      	ldr	x17, [x16, #0x848]
   a1208:      	add	x16, x16, #0x848
   a120c:      	br	x17

00000000000a1210 <_ZN8mtlabar321TextPathConfiguration16setCurveTextTypeENS_4text13CurveTextTypeE@plt>:
   a1210:      	adrp	x16, 0xaa000
   a1214:      	ldr	x17, [x16, #0x850]
   a1218:      	add	x16, x16, #0x850
   a121c:      	br	x17

00000000000a1220 <_ZN8mtlabar327SelectionHighlightInterface6createEv@plt>:
   a1220:      	adrp	x16, 0xaa000
   a1224:      	ldr	x17, [x16, #0x858]
   a1228:      	add	x16, x16, #0x858
   a122c:      	br	x17

00000000000a1230 <_ZN8mtlabar327SelectionHighlightInterface7destroyEPS0_@plt>:
   a1230:      	adrp	x16, 0xaa000
   a1234:      	ldr	x17, [x16, #0x860]
   a1238:      	add	x16, x16, #0x860
   a123c:      	br	x17

00000000000a1240 <_ZN8mtlabar327SelectionHighlightInterface8deepCopyEPKS0_@plt>:
   a1240:      	adrp	x16, 0xaa000
   a1244:      	ldr	x17, [x16, #0x868]
   a1248:      	add	x16, x16, #0x868
   a124c:      	br	x17

00000000000a1250 <_ZN8mtlabar327SelectionHighlightInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1250:      	adrp	x16, 0xaa000
   a1254:      	ldr	x17, [x16, #0x870]
   a1258:      	add	x16, x16, #0x870
   a125c:      	br	x17

00000000000a1260 <_ZNK8mtlabar327SelectionHighlightInterface13getConfigPathEv@plt>:
   a1260:      	adrp	x16, 0xaa000
   a1264:      	ldr	x17, [x16, #0x878]
   a1268:      	add	x16, x16, #0x878
   a126c:      	br	x17

00000000000a1270 <_ZN8mtlabar327SelectionHighlightInterface8setIndexEi@plt>:
   a1270:      	adrp	x16, 0xaa000
   a1274:      	ldr	x17, [x16, #0x880]
   a1278:      	add	x16, x16, #0x880
   a127c:      	br	x17

00000000000a1280 <_ZNK8mtlabar327SelectionHighlightInterface8getIndexEv@plt>:
   a1280:      	adrp	x16, 0xaa000
   a1284:      	ldr	x17, [x16, #0x888]
   a1288:      	add	x16, x16, #0x888
   a128c:      	br	x17

00000000000a1290 <_ZN8mtlabar327SelectionHighlightInterface9setLengthEi@plt>:
   a1290:      	adrp	x16, 0xaa000
   a1294:      	ldr	x17, [x16, #0x890]
   a1298:      	add	x16, x16, #0x890
   a129c:      	br	x17

00000000000a12a0 <_ZNK8mtlabar327SelectionHighlightInterface9getLengthEv@plt>:
   a12a0:      	adrp	x16, 0xaa000
   a12a4:      	ldr	x17, [x16, #0x898]
   a12a8:      	add	x16, x16, #0x898
   a12ac:      	br	x17

00000000000a12b0 <_ZN8mtlabar327SelectionHighlightInterface11setFontSizeEf@plt>:
   a12b0:      	adrp	x16, 0xaa000
   a12b4:      	ldr	x17, [x16, #0x8a0]
   a12b8:      	add	x16, x16, #0x8a0
   a12bc:      	br	x17

00000000000a12c0 <_ZNK8mtlabar327SelectionHighlightInterface11getFontSizeEv@plt>:
   a12c0:      	adrp	x16, 0xaa000
   a12c4:      	ldr	x17, [x16, #0x8a8]
   a12c8:      	add	x16, x16, #0x8a8
   a12cc:      	br	x17

00000000000a12d0 <_ZN8mtlabar327SelectionHighlightInterface19setDisplayInASRTimeEb@plt>:
   a12d0:      	adrp	x16, 0xaa000
   a12d4:      	ldr	x17, [x16, #0x8b0]
   a12d8:      	add	x16, x16, #0x8b0
   a12dc:      	br	x17

00000000000a12e0 <_ZNK8mtlabar327SelectionHighlightInterface19getDisplayInASRTimeEv@plt>:
   a12e0:      	adrp	x16, 0xaa000
   a12e4:      	ldr	x17, [x16, #0x8b8]
   a12e8:      	add	x16, x16, #0x8b8
   a12ec:      	br	x17

00000000000a12f0 <_ZN8mtlabar327SelectionHighlightInterface19setDisplayBeginTimeEf@plt>:
   a12f0:      	adrp	x16, 0xaa000
   a12f4:      	ldr	x17, [x16, #0x8c0]
   a12f8:      	add	x16, x16, #0x8c0
   a12fc:      	br	x17

00000000000a1300 <_ZNK8mtlabar327SelectionHighlightInterface19getDisplayBeginTimeEv@plt>:
   a1300:      	adrp	x16, 0xaa000
   a1304:      	ldr	x17, [x16, #0x8c8]
   a1308:      	add	x16, x16, #0x8c8
   a130c:      	br	x17

00000000000a1310 <_ZN8mtlabar327SelectionHighlightInterface17setDisplayEndTimeEf@plt>:
   a1310:      	adrp	x16, 0xaa000
   a1314:      	ldr	x17, [x16, #0x8d0]
   a1318:      	add	x16, x16, #0x8d0
   a131c:      	br	x17

00000000000a1320 <_ZNK8mtlabar327SelectionHighlightInterface17getDisplayEndTimeEv@plt>:
   a1320:      	adrp	x16, 0xaa000
   a1324:      	ldr	x17, [x16, #0x8d8]
   a1328:      	add	x16, x16, #0x8d8
   a132c:      	br	x17

00000000000a1330 <_ZN8mtlabar327SelectionHighlightInterface28setHideNonHighlightUnderlineEb@plt>:
   a1330:      	adrp	x16, 0xaa000
   a1334:      	ldr	x17, [x16, #0x8e0]
   a1338:      	add	x16, x16, #0x8e0
   a133c:      	br	x17

00000000000a1340 <_ZNK8mtlabar327SelectionHighlightInterface28getHideNonHighlightUnderlineEv@plt>:
   a1340:      	adrp	x16, 0xaa000
   a1344:      	ldr	x17, [x16, #0x8e8]
   a1348:      	add	x16, x16, #0x8e8
   a134c:      	br	x17

00000000000a1350 <_ZN8mtlabar327SelectionHighlightInterface14setFontLibraryERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1350:      	adrp	x16, 0xaa000
   a1354:      	ldr	x17, [x16, #0x8f0]
   a1358:      	add	x16, x16, #0x8f0
   a135c:      	br	x17

00000000000a1360 <_ZNK8mtlabar327SelectionHighlightInterface14getFontLibraryEv@plt>:
   a1360:      	adrp	x16, 0xaa000
   a1364:      	ldr	x17, [x16, #0x8f8]
   a1368:      	add	x16, x16, #0x8f8
   a136c:      	br	x17

00000000000a1370 <_ZN8mtlabar327SelectionHighlightInterface17setCustomizeStyleEb@plt>:
   a1370:      	adrp	x16, 0xaa000
   a1374:      	ldr	x17, [x16, #0x900]
   a1378:      	add	x16, x16, #0x900
   a137c:      	br	x17

00000000000a1380 <_ZNK8mtlabar327SelectionHighlightInterface17getCustomizeStyleEv@plt>:
   a1380:      	adrp	x16, 0xaa000
   a1384:      	ldr	x17, [x16, #0x908]
   a1388:      	add	x16, x16, #0x908
   a138c:      	br	x17

00000000000a1390 <_ZNK8mtlabar327SelectionHighlightInterface8getColorEv@plt>:
   a1390:      	adrp	x16, 0xaa000
   a1394:      	ldr	x17, [x16, #0x910]
   a1398:      	add	x16, x16, #0x910
   a139c:      	br	x17

00000000000a13a0 <_ZN8mtlabar327SelectionHighlightInterface8setColorERKNS_6ColorAE@plt>:
   a13a0:      	adrp	x16, 0xaa000
   a13a4:      	ldr	x17, [x16, #0x918]
   a13a8:      	add	x16, x16, #0x918
   a13ac:      	br	x17

00000000000a13b0 <_ZN8mtlabar327SelectionHighlightInterface24setFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a13b0:      	adrp	x16, 0xaa000
   a13b4:      	ldr	x17, [x16, #0x920]
   a13b8:      	add	x16, x16, #0x920
   a13bc:      	br	x17

00000000000a13c0 <_ZNK8mtlabar327SelectionHighlightInterface24getFallbackFontLibrariesEv@plt>:
   a13c0:      	adrp	x16, 0xaa000
   a13c4:      	ldr	x17, [x16, #0x928]
   a13c8:      	add	x16, x16, #0x928
   a13cc:      	br	x17

00000000000a13d0 <_ZN8mtlabar327SelectionHighlightInterface7setBoldEb@plt>:
   a13d0:      	adrp	x16, 0xaa000
   a13d4:      	ldr	x17, [x16, #0x930]
   a13d8:      	add	x16, x16, #0x930
   a13dc:      	br	x17

00000000000a13e0 <_ZNK8mtlabar327SelectionHighlightInterface7getBoldEv@plt>:
   a13e0:      	adrp	x16, 0xaa000
   a13e4:      	ldr	x17, [x16, #0x938]
   a13e8:      	add	x16, x16, #0x938
   a13ec:      	br	x17

00000000000a13f0 <_ZN8mtlabar327SelectionHighlightInterface9setItalicEb@plt>:
   a13f0:      	adrp	x16, 0xaa000
   a13f4:      	ldr	x17, [x16, #0x940]
   a13f8:      	add	x16, x16, #0x940
   a13fc:      	br	x17

00000000000a1400 <_ZNK8mtlabar327SelectionHighlightInterface9getItalicEv@plt>:
   a1400:      	adrp	x16, 0xaa000
   a1404:      	ldr	x17, [x16, #0x948]
   a1408:      	add	x16, x16, #0x948
   a140c:      	br	x17

00000000000a1410 <_ZN8mtlabar327SelectionHighlightInterface12setUnderlineEb@plt>:
   a1410:      	adrp	x16, 0xaa000
   a1414:      	ldr	x17, [x16, #0x950]
   a1418:      	add	x16, x16, #0x950
   a141c:      	br	x17

00000000000a1420 <_ZNK8mtlabar327SelectionHighlightInterface12getUnderlineEv@plt>:
   a1420:      	adrp	x16, 0xaa000
   a1424:      	ldr	x17, [x16, #0x958]
   a1428:      	add	x16, x16, #0x958
   a142c:      	br	x17

00000000000a1430 <_ZN8mtlabar327SelectionHighlightInterface16setStrikeThroughEb@plt>:
   a1430:      	adrp	x16, 0xaa000
   a1434:      	ldr	x17, [x16, #0x960]
   a1438:      	add	x16, x16, #0x960
   a143c:      	br	x17

00000000000a1440 <_ZNK8mtlabar327SelectionHighlightInterface16getStrikeThroughEv@plt>:
   a1440:      	adrp	x16, 0xaa000
   a1444:      	ldr	x17, [x16, #0x968]
   a1448:      	add	x16, x16, #0x968
   a144c:      	br	x17

00000000000a1450 <_ZN8mtlabar327SelectionHighlightInterface21getMultiStrokeAtIndexEi@plt>:
   a1450:      	adrp	x16, 0xaa000
   a1454:      	ldr	x17, [x16, #0x970]
   a1458:      	add	x16, x16, #0x970
   a145c:      	br	x17

00000000000a1460 <_ZN8mtlabar327SelectionHighlightInterface18getMultiStrokeSizeEv@plt>:
   a1460:      	adrp	x16, 0xaa000
   a1464:      	ldr	x17, [x16, #0x978]
   a1468:      	add	x16, x16, #0x978
   a146c:      	br	x17

00000000000a1470 <_ZN8mtlabar327SelectionHighlightInterface17resizeMultiStrokeEi@plt>:
   a1470:      	adrp	x16, 0xaa000
   a1474:      	ldr	x17, [x16, #0x980]
   a1478:      	add	x16, x16, #0x980
   a147c:      	br	x17

00000000000a1480 <_ZN8mtlabar327SelectionHighlightInterface22getShadowConfigurationEv@plt>:
   a1480:      	adrp	x16, 0xaa000
   a1484:      	ldr	x17, [x16, #0x988]
   a1488:      	add	x16, x16, #0x988
   a148c:      	br	x17

00000000000a1490 <_ZN8mtlabar327SelectionHighlightInterface31getBackgroundColorConfigurationEv@plt>:
   a1490:      	adrp	x16, 0xaa000
   a1494:      	ldr	x17, [x16, #0x990]
   a1498:      	add	x16, x16, #0x990
   a149c:      	br	x17

00000000000a14a0 <_ZN8mtlabar327SelectionHighlightInterface20getGlowConfigurationEv@plt>:
   a14a0:      	adrp	x16, 0xaa000
   a14a4:      	ldr	x17, [x16, #0x998]
   a14a8:      	add	x16, x16, #0x998
   a14ac:      	br	x17

00000000000a14b0 <_ZN8mtlabar327SelectionHighlightInterface9setRotateEf@plt>:
   a14b0:      	adrp	x16, 0xaa000
   a14b4:      	ldr	x17, [x16, #0x9a0]
   a14b8:      	add	x16, x16, #0x9a0
   a14bc:      	br	x17

00000000000a14c0 <_ZNK8mtlabar327SelectionHighlightInterface9getRotateEv@plt>:
   a14c0:      	adrp	x16, 0xaa000
   a14c4:      	ldr	x17, [x16, #0x9a8]
   a14c8:      	add	x16, x16, #0x9a8
   a14cc:      	br	x17

00000000000a14d0 <_ZN8mtlabar327SelectionHighlightInterface8setScaleEf@plt>:
   a14d0:      	adrp	x16, 0xaa000
   a14d4:      	ldr	x17, [x16, #0x9b0]
   a14d8:      	add	x16, x16, #0x9b0
   a14dc:      	br	x17

00000000000a14e0 <_ZNK8mtlabar327SelectionHighlightInterface8getScaleEv@plt>:
   a14e0:      	adrp	x16, 0xaa000
   a14e4:      	ldr	x17, [x16, #0x9b8]
   a14e8:      	add	x16, x16, #0x9b8
   a14ec:      	br	x17

00000000000a14f0 <_ZN8mtlabar327SelectionHighlightInterface9setOffsetERKNS_6Float2E@plt>:
   a14f0:      	adrp	x16, 0xaa000
   a14f4:      	ldr	x17, [x16, #0x9c0]
   a14f8:      	add	x16, x16, #0x9c0
   a14fc:      	br	x17

00000000000a1500 <_ZNK8mtlabar327SelectionHighlightInterface9getOffsetEv@plt>:
   a1500:      	adrp	x16, 0xaa000
   a1504:      	ldr	x17, [x16, #0x9c8]
   a1508:      	add	x16, x16, #0x9c8
   a150c:      	br	x17

00000000000a1510 <_ZN8mtlabar327SelectionAnimationInterface6createEv@plt>:
   a1510:      	adrp	x16, 0xaa000
   a1514:      	ldr	x17, [x16, #0x9d0]
   a1518:      	add	x16, x16, #0x9d0
   a151c:      	br	x17

00000000000a1520 <_ZN8mtlabar327SelectionAnimationInterface7destroyEPS0_@plt>:
   a1520:      	adrp	x16, 0xaa000
   a1524:      	ldr	x17, [x16, #0x9d8]
   a1528:      	add	x16, x16, #0x9d8
   a152c:      	br	x17

00000000000a1530 <_ZN8mtlabar327SelectionAnimationInterface8deepCopyEPKS0_@plt>:
   a1530:      	adrp	x16, 0xaa000
   a1534:      	ldr	x17, [x16, #0x9e0]
   a1538:      	add	x16, x16, #0x9e0
   a153c:      	br	x17

00000000000a1540 <_ZN8mtlabar327SelectionAnimationInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1540:      	adrp	x16, 0xaa000
   a1544:      	ldr	x17, [x16, #0x9e8]
   a1548:      	add	x16, x16, #0x9e8
   a154c:      	br	x17

00000000000a1550 <_ZNK8mtlabar327SelectionAnimationInterface13getConfigPathEv@plt>:
   a1550:      	adrp	x16, 0xaa000
   a1554:      	ldr	x17, [x16, #0x9f0]
   a1558:      	add	x16, x16, #0x9f0
   a155c:      	br	x17

00000000000a1560 <_ZN8mtlabar327SelectionAnimationInterface8setIndexEi@plt>:
   a1560:      	adrp	x16, 0xaa000
   a1564:      	ldr	x17, [x16, #0x9f8]
   a1568:      	add	x16, x16, #0x9f8
   a156c:      	br	x17

00000000000a1570 <_ZNK8mtlabar327SelectionAnimationInterface8getIndexEv@plt>:
   a1570:      	adrp	x16, 0xaa000
   a1574:      	ldr	x17, [x16, #0xa00]
   a1578:      	add	x16, x16, #0xa00
   a157c:      	br	x17

00000000000a1580 <_ZN8mtlabar327SelectionAnimationInterface9setLengthEi@plt>:
   a1580:      	adrp	x16, 0xaa000
   a1584:      	ldr	x17, [x16, #0xa08]
   a1588:      	add	x16, x16, #0xa08
   a158c:      	br	x17

00000000000a1590 <_ZNK8mtlabar327SelectionAnimationInterface9getLengthEv@plt>:
   a1590:      	adrp	x16, 0xaa000
   a1594:      	ldr	x17, [x16, #0xa10]
   a1598:      	add	x16, x16, #0xa10
   a159c:      	br	x17

00000000000a15a0 <_ZN8mtlabar327SelectionAnimationInterface11setFontSizeEf@plt>:
   a15a0:      	adrp	x16, 0xaa000
   a15a4:      	ldr	x17, [x16, #0xa18]
   a15a8:      	add	x16, x16, #0xa18
   a15ac:      	br	x17

00000000000a15b0 <_ZNK8mtlabar327SelectionAnimationInterface11getFontSizeEv@plt>:
   a15b0:      	adrp	x16, 0xaa000
   a15b4:      	ldr	x17, [x16, #0xa20]
   a15b8:      	add	x16, x16, #0xa20
   a15bc:      	br	x17

00000000000a15c0 <_ZN8mtlabar327SelectionAnimationInterface19setDisplayInASRTimeEb@plt>:
   a15c0:      	adrp	x16, 0xaa000
   a15c4:      	ldr	x17, [x16, #0xa28]
   a15c8:      	add	x16, x16, #0xa28
   a15cc:      	br	x17

00000000000a15d0 <_ZNK8mtlabar327SelectionAnimationInterface19getDisplayInASRTimeEv@plt>:
   a15d0:      	adrp	x16, 0xaa000
   a15d4:      	ldr	x17, [x16, #0xa30]
   a15d8:      	add	x16, x16, #0xa30
   a15dc:      	br	x17

00000000000a15e0 <_ZN8mtlabar327SelectionAnimationInterface19setDisplayBeginTimeEf@plt>:
   a15e0:      	adrp	x16, 0xaa000
   a15e4:      	ldr	x17, [x16, #0xa38]
   a15e8:      	add	x16, x16, #0xa38
   a15ec:      	br	x17

00000000000a15f0 <_ZNK8mtlabar327SelectionAnimationInterface19getDisplayBeginTimeEv@plt>:
   a15f0:      	adrp	x16, 0xaa000
   a15f4:      	ldr	x17, [x16, #0xa40]
   a15f8:      	add	x16, x16, #0xa40
   a15fc:      	br	x17

00000000000a1600 <_ZN8mtlabar327SelectionAnimationInterface17setDisplayEndTimeEf@plt>:
   a1600:      	adrp	x16, 0xaa000
   a1604:      	ldr	x17, [x16, #0xa48]
   a1608:      	add	x16, x16, #0xa48
   a160c:      	br	x17

00000000000a1610 <_ZNK8mtlabar327SelectionAnimationInterface17getDisplayEndTimeEv@plt>:
   a1610:      	adrp	x16, 0xaa000
   a1614:      	ldr	x17, [x16, #0xa50]
   a1618:      	add	x16, x16, #0xa50
   a161c:      	br	x17

00000000000a1620 <_ZN8mtlabar323TextNoteDetailInterface6createEv@plt>:
   a1620:      	adrp	x16, 0xaa000
   a1624:      	ldr	x17, [x16, #0xa58]
   a1628:      	add	x16, x16, #0xa58
   a162c:      	br	x17

00000000000a1630 <_ZN8mtlabar323TextNoteDetailInterface7destroyEPS0_@plt>:
   a1630:      	adrp	x16, 0xaa000
   a1634:      	ldr	x17, [x16, #0xa60]
   a1638:      	add	x16, x16, #0xa60
   a163c:      	br	x17

00000000000a1640 <_ZN8mtlabar323TextNoteDetailInterface8deepCopyEPKS0_@plt>:
   a1640:      	adrp	x16, 0xaa000
   a1644:      	ldr	x17, [x16, #0xa68]
   a1648:      	add	x16, x16, #0xa68
   a164c:      	br	x17

00000000000a1650 <_ZN8mtlabar323TextNoteDetailInterface10setSvgPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1650:      	adrp	x16, 0xaa000
   a1654:      	ldr	x17, [x16, #0xa70]
   a1658:      	add	x16, x16, #0xa70
   a165c:      	br	x17

00000000000a1660 <_ZNK8mtlabar323TextNoteDetailInterface10getSvgPathEv@plt>:
   a1660:      	adrp	x16, 0xaa000
   a1664:      	ldr	x17, [x16, #0xa78]
   a1668:      	add	x16, x16, #0xa78
   a166c:      	br	x17

00000000000a1670 <_ZN8mtlabar323TextNoteDetailInterface11setFillTypeENS_4text11SVGFillTypeE@plt>:
   a1670:      	adrp	x16, 0xaa000
   a1674:      	ldr	x17, [x16, #0xa80]
   a1678:      	add	x16, x16, #0xa80
   a167c:      	br	x17

00000000000a1680 <_ZNK8mtlabar323TextNoteDetailInterface11getFillTypeEv@plt>:
   a1680:      	adrp	x16, 0xaa000
   a1684:      	ldr	x17, [x16, #0xa88]
   a1688:      	add	x16, x16, #0xa88
   a168c:      	br	x17

00000000000a1690 <_ZN8mtlabar323TextNoteDetailInterface11setWrapModeENS_4text11SVGWrapModeE@plt>:
   a1690:      	adrp	x16, 0xaa000
   a1694:      	ldr	x17, [x16, #0xa90]
   a1698:      	add	x16, x16, #0xa90
   a169c:      	br	x17

00000000000a16a0 <_ZNK8mtlabar323TextNoteDetailInterface11getWrapModeEv@plt>:
   a16a0:      	adrp	x16, 0xaa000
   a16a4:      	ldr	x17, [x16, #0xa98]
   a16a8:      	add	x16, x16, #0xa98
   a16ac:      	br	x17

00000000000a16b0 <_ZN8mtlabar323TextNoteDetailInterface14setStretchModeENS_4text14SVGStretchModeE@plt>:
   a16b0:      	adrp	x16, 0xaa000
   a16b4:      	ldr	x17, [x16, #0xaa0]
   a16b8:      	add	x16, x16, #0xaa0
   a16bc:      	br	x17

00000000000a16c0 <_ZNK8mtlabar323TextNoteDetailInterface14getStretchModeEv@plt>:
   a16c0:      	adrp	x16, 0xaa000
   a16c4:      	ldr	x17, [x16, #0xaa8]
   a16c8:      	add	x16, x16, #0xaa8
   a16cc:      	br	x17

00000000000a16d0 <_ZN8mtlabar323TextNoteDetailInterface8setAlignENS_4text12SVGTextAlignE@plt>:
   a16d0:      	adrp	x16, 0xaa000
   a16d4:      	ldr	x17, [x16, #0xab0]
   a16d8:      	add	x16, x16, #0xab0
   a16dc:      	br	x17

00000000000a16e0 <_ZNK8mtlabar323TextNoteDetailInterface8getAlignEv@plt>:
   a16e0:      	adrp	x16, 0xaa000
   a16e4:      	ldr	x17, [x16, #0xab8]
   a16e8:      	add	x16, x16, #0xab8
   a16ec:      	br	x17

00000000000a16f0 <_ZN8mtlabar323TextNoteDetailInterface12setSvgAnchorENS_4text9SVGAnchorE@plt>:
   a16f0:      	adrp	x16, 0xaa000
   a16f4:      	ldr	x17, [x16, #0xac0]
   a16f8:      	add	x16, x16, #0xac0
   a16fc:      	br	x17

00000000000a1700 <_ZNK8mtlabar323TextNoteDetailInterface12getSvgAnchorEv@plt>:
   a1700:      	adrp	x16, 0xaa000
   a1704:      	ldr	x17, [x16, #0xac8]
   a1708:      	add	x16, x16, #0xac8
   a170c:      	br	x17

00000000000a1710 <_ZN8mtlabar323TextNoteDetailInterface10setSpacingERKNS_6Float2E@plt>:
   a1710:      	adrp	x16, 0xaa000
   a1714:      	ldr	x17, [x16, #0xad0]
   a1718:      	add	x16, x16, #0xad0
   a171c:      	br	x17

00000000000a1720 <_ZNK8mtlabar323TextNoteDetailInterface10getSpacingEv@plt>:
   a1720:      	adrp	x16, 0xaa000
   a1724:      	ldr	x17, [x16, #0xad8]
   a1728:      	add	x16, x16, #0xad8
   a172c:      	br	x17

00000000000a1730 <_ZN8mtlabar323TextNoteDetailInterface14setStrokeWidthEf@plt>:
   a1730:      	adrp	x16, 0xaa000
   a1734:      	ldr	x17, [x16, #0xae0]
   a1738:      	add	x16, x16, #0xae0
   a173c:      	br	x17

00000000000a1740 <_ZNK8mtlabar323TextNoteDetailInterface14getStrokeWidthEv@plt>:
   a1740:      	adrp	x16, 0xaa000
   a1744:      	ldr	x17, [x16, #0xae8]
   a1748:      	add	x16, x16, #0xae8
   a174c:      	br	x17

00000000000a1750 <_ZN8mtlabar323TextNoteDetailInterface9setOffsetERKNS_6Float2E@plt>:
   a1750:      	adrp	x16, 0xaa000
   a1754:      	ldr	x17, [x16, #0xaf0]
   a1758:      	add	x16, x16, #0xaf0
   a175c:      	br	x17

00000000000a1760 <_ZNK8mtlabar323TextNoteDetailInterface9getOffsetEv@plt>:
   a1760:      	adrp	x16, 0xaa000
   a1764:      	ldr	x17, [x16, #0xaf8]
   a1768:      	add	x16, x16, #0xaf8
   a176c:      	br	x17

00000000000a1770 <_ZN8mtlabar323TextNoteDetailInterface8setScaleERKNS_6Float2E@plt>:
   a1770:      	adrp	x16, 0xaa000
   a1774:      	ldr	x17, [x16, #0xb00]
   a1778:      	add	x16, x16, #0xb00
   a177c:      	br	x17

00000000000a1780 <_ZNK8mtlabar323TextNoteDetailInterface8getScaleEv@plt>:
   a1780:      	adrp	x16, 0xaa000
   a1784:      	ldr	x17, [x16, #0xb08]
   a1788:      	add	x16, x16, #0xb08
   a178c:      	br	x17

00000000000a1790 <_ZN8mtlabar323TextNoteDetailInterface14setOnTopOfTextEb@plt>:
   a1790:      	adrp	x16, 0xaa000
   a1794:      	ldr	x17, [x16, #0xb10]
   a1798:      	add	x16, x16, #0xb10
   a179c:      	br	x17

00000000000a17a0 <_ZNK8mtlabar323TextNoteDetailInterface14getOnTopOfTextEv@plt>:
   a17a0:      	adrp	x16, 0xaa000
   a17a4:      	ldr	x17, [x16, #0xb18]
   a17a8:      	add	x16, x16, #0xb18
   a17ac:      	br	x17

00000000000a17b0 <_ZN8mtlabar323TextNoteDetailInterface10setAnimateEb@plt>:
   a17b0:      	adrp	x16, 0xaa000
   a17b4:      	ldr	x17, [x16, #0xb20]
   a17b8:      	add	x16, x16, #0xb20
   a17bc:      	br	x17

00000000000a17c0 <_ZNK8mtlabar323TextNoteDetailInterface10getAnimateEv@plt>:
   a17c0:      	adrp	x16, 0xaa000
   a17c4:      	ldr	x17, [x16, #0xb28]
   a17c8:      	add	x16, x16, #0xb28
   a17cc:      	br	x17

00000000000a17d0 <_ZN8mtlabar323TextNoteDetailInterface11setOnceTimeEf@plt>:
   a17d0:      	adrp	x16, 0xaa000
   a17d4:      	ldr	x17, [x16, #0xb30]
   a17d8:      	add	x16, x16, #0xb30
   a17dc:      	br	x17

00000000000a17e0 <_ZNK8mtlabar323TextNoteDetailInterface11getOnceTimeEv@plt>:
   a17e0:      	adrp	x16, 0xaa000
   a17e4:      	ldr	x17, [x16, #0xb38]
   a17e8:      	add	x16, x16, #0xb38
   a17ec:      	br	x17

00000000000a17f0 <_ZN8mtlabar323TextNoteDetailInterface17setBeginTimestampEf@plt>:
   a17f0:      	adrp	x16, 0xaa000
   a17f4:      	ldr	x17, [x16, #0xb40]
   a17f8:      	add	x16, x16, #0xb40
   a17fc:      	br	x17

00000000000a1800 <_ZNK8mtlabar323TextNoteDetailInterface17getBeginTimestampEv@plt>:
   a1800:      	adrp	x16, 0xaa000
   a1804:      	ldr	x17, [x16, #0xb48]
   a1808:      	add	x16, x16, #0xb48
   a180c:      	br	x17

00000000000a1810 <_ZN8mtlabar323TextNoteDetailInterface15setEndTimestampEf@plt>:
   a1810:      	adrp	x16, 0xaa000
   a1814:      	ldr	x17, [x16, #0xb50]
   a1818:      	add	x16, x16, #0xb50
   a181c:      	br	x17

00000000000a1820 <_ZNK8mtlabar323TextNoteDetailInterface15getEndTimestampEv@plt>:
   a1820:      	adrp	x16, 0xaa000
   a1824:      	ldr	x17, [x16, #0xb58]
   a1828:      	add	x16, x16, #0xb58
   a182c:      	br	x17

00000000000a1830 <_ZN8mtlabar323TextNoteDetailInterface14setRepeatCountEi@plt>:
   a1830:      	adrp	x16, 0xaa000
   a1834:      	ldr	x17, [x16, #0xb60]
   a1838:      	add	x16, x16, #0xb60
   a183c:      	br	x17

00000000000a1840 <_ZNK8mtlabar323TextNoteDetailInterface14getRepeatCountEv@plt>:
   a1840:      	adrp	x16, 0xaa000
   a1844:      	ldr	x17, [x16, #0xb68]
   a1848:      	add	x16, x16, #0xb68
   a184c:      	br	x17

00000000000a1850 <_ZN8mtlabar323TextNoteDetailInterface15setEnableStrokeEb@plt>:
   a1850:      	adrp	x16, 0xaa000
   a1854:      	ldr	x17, [x16, #0xb70]
   a1858:      	add	x16, x16, #0xb70
   a185c:      	br	x17

00000000000a1860 <_ZNK8mtlabar323TextNoteDetailInterface15getEnableStrokeEv@plt>:
   a1860:      	adrp	x16, 0xaa000
   a1864:      	ldr	x17, [x16, #0xb78]
   a1868:      	add	x16, x16, #0xb78
   a186c:      	br	x17

00000000000a1870 <_ZN8mtlabar323TextNoteDetailInterface8setColorERKNS_6ColorAE@plt>:
   a1870:      	adrp	x16, 0xaa000
   a1874:      	ldr	x17, [x16, #0xb80]
   a1878:      	add	x16, x16, #0xb80
   a187c:      	br	x17

00000000000a1880 <_ZNK8mtlabar323TextNoteDetailInterface8getColorEv@plt>:
   a1880:      	adrp	x16, 0xaa000
   a1884:      	ldr	x17, [x16, #0xb88]
   a1888:      	add	x16, x16, #0xb88
   a188c:      	br	x17

00000000000a1890 <_ZN8mtlabar323TextNoteDetailInterface14setEnableTaperEb@plt>:
   a1890:      	adrp	x16, 0xaa000
   a1894:      	ldr	x17, [x16, #0xb90]
   a1898:      	add	x16, x16, #0xb90
   a189c:      	br	x17

00000000000a18a0 <_ZNK8mtlabar323TextNoteDetailInterface14getEnableTaperEv@plt>:
   a18a0:      	adrp	x16, 0xaa000
   a18a4:      	ldr	x17, [x16, #0xb98]
   a18a8:      	add	x16, x16, #0xb98
   a18ac:      	br	x17

00000000000a18b0 <_ZN8mtlabar323TextNoteDetailInterface16setEnableOpacityEb@plt>:
   a18b0:      	adrp	x16, 0xaa000
   a18b4:      	ldr	x17, [x16, #0xba0]
   a18b8:      	add	x16, x16, #0xba0
   a18bc:      	br	x17

00000000000a18c0 <_ZNK8mtlabar323TextNoteDetailInterface16getEnableOpacityEv@plt>:
   a18c0:      	adrp	x16, 0xaa000
   a18c4:      	ldr	x17, [x16, #0xba8]
   a18c8:      	add	x16, x16, #0xba8
   a18cc:      	br	x17

00000000000a18d0 <_ZN8mtlabar323TextNoteDetailInterface12setSizeRangeERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
   a18d0:      	adrp	x16, 0xaa000
   a18d4:      	ldr	x17, [x16, #0xbb0]
   a18d8:      	add	x16, x16, #0xbb0
   a18dc:      	br	x17

00000000000a18e0 <_ZNK8mtlabar323TextNoteDetailInterface12getSizeRangeEv@plt>:
   a18e0:      	adrp	x16, 0xaa000
   a18e4:      	ldr	x17, [x16, #0xbb8]
   a18e8:      	add	x16, x16, #0xbb8
   a18ec:      	br	x17

00000000000a18f0 <_ZN8mtlabar323TextNoteDetailInterface10setPaddingERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   a18f0:      	adrp	x16, 0xaa000
   a18f4:      	ldr	x17, [x16, #0xbc0]
   a18f8:      	add	x16, x16, #0xbc0
   a18fc:      	br	x17

00000000000a1900 <_ZNK8mtlabar323TextNoteDetailInterface10getPaddingEv@plt>:
   a1900:      	adrp	x16, 0xaa000
   a1904:      	ldr	x17, [x16, #0xbc8]
   a1908:      	add	x16, x16, #0xbc8
   a190c:      	br	x17

00000000000a1910 <_ZN8mtlabar322SelectionNoteInterface6createEv@plt>:
   a1910:      	adrp	x16, 0xaa000
   a1914:      	ldr	x17, [x16, #0xbd0]
   a1918:      	add	x16, x16, #0xbd0
   a191c:      	br	x17

00000000000a1920 <_ZN8mtlabar322SelectionNoteInterface7destroyEPS0_@plt>:
   a1920:      	adrp	x16, 0xaa000
   a1924:      	ldr	x17, [x16, #0xbd8]
   a1928:      	add	x16, x16, #0xbd8
   a192c:      	br	x17

00000000000a1930 <_ZN8mtlabar322SelectionNoteInterface8deepCopyEPKS0_@plt>:
   a1930:      	adrp	x16, 0xaa000
   a1934:      	ldr	x17, [x16, #0xbe0]
   a1938:      	add	x16, x16, #0xbe0
   a193c:      	br	x17

00000000000a1940 <_ZN8mtlabar322SelectionNoteInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1940:      	adrp	x16, 0xaa000
   a1944:      	ldr	x17, [x16, #0xbe8]
   a1948:      	add	x16, x16, #0xbe8
   a194c:      	br	x17

00000000000a1950 <_ZNK8mtlabar322SelectionNoteInterface13getConfigPathEv@plt>:
   a1950:      	adrp	x16, 0xaa000
   a1954:      	ldr	x17, [x16, #0xbf0]
   a1958:      	add	x16, x16, #0xbf0
   a195c:      	br	x17

00000000000a1960 <_ZN8mtlabar322SelectionNoteInterface18setCustomizeDetailEb@plt>:
   a1960:      	adrp	x16, 0xaa000
   a1964:      	ldr	x17, [x16, #0xbf8]
   a1968:      	add	x16, x16, #0xbf8
   a196c:      	br	x17

00000000000a1970 <_ZNK8mtlabar322SelectionNoteInterface18getCustomizeDetailEv@plt>:
   a1970:      	adrp	x16, 0xaa000
   a1974:      	ldr	x17, [x16, #0xc00]
   a1978:      	add	x16, x16, #0xc00
   a197c:      	br	x17

00000000000a1980 <_ZN8mtlabar322SelectionNoteInterface13getNoteDetailEv@plt>:
   a1980:      	adrp	x16, 0xaa000
   a1984:      	ldr	x17, [x16, #0xc08]
   a1988:      	add	x16, x16, #0xc08
   a198c:      	br	x17

00000000000a1990 <_ZN8mtlabar322SelectionNoteInterface8setIndexEi@plt>:
   a1990:      	adrp	x16, 0xaa000
   a1994:      	ldr	x17, [x16, #0xc10]
   a1998:      	add	x16, x16, #0xc10
   a199c:      	br	x17

00000000000a19a0 <_ZNK8mtlabar322SelectionNoteInterface8getIndexEv@plt>:
   a19a0:      	adrp	x16, 0xaa000
   a19a4:      	ldr	x17, [x16, #0xc18]
   a19a8:      	add	x16, x16, #0xc18
   a19ac:      	br	x17

00000000000a19b0 <_ZN8mtlabar322SelectionNoteInterface9setLengthEi@plt>:
   a19b0:      	adrp	x16, 0xaa000
   a19b4:      	ldr	x17, [x16, #0xc20]
   a19b8:      	add	x16, x16, #0xc20
   a19bc:      	br	x17

00000000000a19c0 <_ZNK8mtlabar322SelectionNoteInterface9getLengthEv@plt>:
   a19c0:      	adrp	x16, 0xaa000
   a19c4:      	ldr	x17, [x16, #0xc28]
   a19c8:      	add	x16, x16, #0xc28
   a19cc:      	br	x17

00000000000a19d0 <_ZN8mtlabar322SelectionNoteInterface11setFontSizeEf@plt>:
   a19d0:      	adrp	x16, 0xaa000
   a19d4:      	ldr	x17, [x16, #0xc30]
   a19d8:      	add	x16, x16, #0xc30
   a19dc:      	br	x17

00000000000a19e0 <_ZNK8mtlabar322SelectionNoteInterface11getFontSizeEv@plt>:
   a19e0:      	adrp	x16, 0xaa000
   a19e4:      	ldr	x17, [x16, #0xc38]
   a19e8:      	add	x16, x16, #0xc38
   a19ec:      	br	x17

00000000000a19f0 <_ZN8mtlabar322SelectionNoteInterface19setDisplayInASRTimeEb@plt>:
   a19f0:      	adrp	x16, 0xaa000
   a19f4:      	ldr	x17, [x16, #0xc40]
   a19f8:      	add	x16, x16, #0xc40
   a19fc:      	br	x17

00000000000a1a00 <_ZNK8mtlabar322SelectionNoteInterface19getDisplayInASRTimeEv@plt>:
   a1a00:      	adrp	x16, 0xaa000
   a1a04:      	ldr	x17, [x16, #0xc48]
   a1a08:      	add	x16, x16, #0xc48
   a1a0c:      	br	x17

00000000000a1a10 <_ZN8mtlabar322SelectionNoteInterface19setDisplayBeginTimeEf@plt>:
   a1a10:      	adrp	x16, 0xaa000
   a1a14:      	ldr	x17, [x16, #0xc50]
   a1a18:      	add	x16, x16, #0xc50
   a1a1c:      	br	x17

00000000000a1a20 <_ZNK8mtlabar322SelectionNoteInterface19getDisplayBeginTimeEv@plt>:
   a1a20:      	adrp	x16, 0xaa000
   a1a24:      	ldr	x17, [x16, #0xc58]
   a1a28:      	add	x16, x16, #0xc58
   a1a2c:      	br	x17

00000000000a1a30 <_ZN8mtlabar322SelectionNoteInterface17setDisplayEndTimeEf@plt>:
   a1a30:      	adrp	x16, 0xaa000
   a1a34:      	ldr	x17, [x16, #0xc60]
   a1a38:      	add	x16, x16, #0xc60
   a1a3c:      	br	x17

00000000000a1a40 <_ZNK8mtlabar322SelectionNoteInterface17getDisplayEndTimeEv@plt>:
   a1a40:      	adrp	x16, 0xaa000
   a1a44:      	ldr	x17, [x16, #0xc68]
   a1a48:      	add	x16, x16, #0xc68
   a1a4c:      	br	x17

00000000000a1a50 <_ZN8mtlabar326IconSequenceColorInterface6createEv@plt>:
   a1a50:      	adrp	x16, 0xaa000
   a1a54:      	ldr	x17, [x16, #0xc70]
   a1a58:      	add	x16, x16, #0xc70
   a1a5c:      	br	x17

00000000000a1a60 <_ZN8mtlabar326IconSequenceColorInterface7destroyEPS0_@plt>:
   a1a60:      	adrp	x16, 0xaa000
   a1a64:      	ldr	x17, [x16, #0xc78]
   a1a68:      	add	x16, x16, #0xc78
   a1a6c:      	br	x17

00000000000a1a70 <_ZN8mtlabar326IconSequenceColorInterface8deepCopyEPKS0_@plt>:
   a1a70:      	adrp	x16, 0xaa000
   a1a74:      	ldr	x17, [x16, #0xc80]
   a1a78:      	add	x16, x16, #0xc80
   a1a7c:      	br	x17

00000000000a1a80 <_ZN8mtlabar326IconSequenceColorInterface8getColorEv@plt>:
   a1a80:      	adrp	x16, 0xaa000
   a1a84:      	ldr	x17, [x16, #0xc88]
   a1a88:      	add	x16, x16, #0xc88
   a1a8c:      	br	x17

00000000000a1a90 <_ZN8mtlabar326IconSequenceColorInterface8setColorERKNS_6ColorAE@plt>:
   a1a90:      	adrp	x16, 0xaa000
   a1a94:      	ldr	x17, [x16, #0xc90]
   a1a98:      	add	x16, x16, #0xc90
   a1a9c:      	br	x17

00000000000a1aa0 <_ZNK8mtlabar326IconSequenceColorInterface15getPlaceholdersEv@plt>:
   a1aa0:      	adrp	x16, 0xaa000
   a1aa4:      	ldr	x17, [x16, #0xc98]
   a1aa8:      	add	x16, x16, #0xc98
   a1aac:      	br	x17

00000000000a1ab0 <_ZN8mtlabar326IconSequenceColorInterface15setPlaceholdersERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a1ab0:      	adrp	x16, 0xaa000
   a1ab4:      	ldr	x17, [x16, #0xca0]
   a1ab8:      	add	x16, x16, #0xca0
   a1abc:      	br	x17

00000000000a1ac0 <_ZN8mtlabar326IconSequenceColorInterface11setEditableEb@plt>:
   a1ac0:      	adrp	x16, 0xaa000
   a1ac4:      	ldr	x17, [x16, #0xca8]
   a1ac8:      	add	x16, x16, #0xca8
   a1acc:      	br	x17

00000000000a1ad0 <_ZNK8mtlabar326IconSequenceColorInterface10isEditableEv@plt>:
   a1ad0:      	adrp	x16, 0xaa000
   a1ad4:      	ldr	x17, [x16, #0xcb0]
   a1ad8:      	add	x16, x16, #0xcb0
   a1adc:      	br	x17

00000000000a1ae0 <_ZN8mtlabar326IconSequenceStyleInterface6createEv@plt>:
   a1ae0:      	adrp	x16, 0xaa000
   a1ae4:      	ldr	x17, [x16, #0xcb8]
   a1ae8:      	add	x16, x16, #0xcb8
   a1aec:      	br	x17

00000000000a1af0 <_ZN8mtlabar326IconSequenceStyleInterface7destroyEPS0_@plt>:
   a1af0:      	adrp	x16, 0xaa000
   a1af4:      	ldr	x17, [x16, #0xcc0]
   a1af8:      	add	x16, x16, #0xcc0
   a1afc:      	br	x17

00000000000a1b00 <_ZN8mtlabar326IconSequenceStyleInterface8deepCopyEPKS0_@plt>:
   a1b00:      	adrp	x16, 0xaa000
   a1b04:      	ldr	x17, [x16, #0xcc8]
   a1b08:      	add	x16, x16, #0xcc8
   a1b0c:      	br	x17

00000000000a1b10 <_ZNK8mtlabar326IconSequenceStyleInterface12getImagePathEv@plt>:
   a1b10:      	adrp	x16, 0xaa000
   a1b14:      	ldr	x17, [x16, #0xcd0]
   a1b18:      	add	x16, x16, #0xcd0
   a1b1c:      	br	x17

00000000000a1b20 <_ZN8mtlabar326IconSequenceStyleInterface12setImagePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1b20:      	adrp	x16, 0xaa000
   a1b24:      	ldr	x17, [x16, #0xcd8]
   a1b28:      	add	x16, x16, #0xcd8
   a1b2c:      	br	x17

00000000000a1b30 <_ZNK8mtlabar326IconSequenceStyleInterface8getScaleEv@plt>:
   a1b30:      	adrp	x16, 0xaa000
   a1b34:      	ldr	x17, [x16, #0xce0]
   a1b38:      	add	x16, x16, #0xce0
   a1b3c:      	br	x17

00000000000a1b40 <_ZN8mtlabar326IconSequenceStyleInterface8setScaleEf@plt>:
   a1b40:      	adrp	x16, 0xaa000
   a1b44:      	ldr	x17, [x16, #0xce8]
   a1b48:      	add	x16, x16, #0xce8
   a1b4c:      	br	x17

00000000000a1b50 <_ZNK8mtlabar326IconSequenceStyleInterface15getBaseTextSizeEv@plt>:
   a1b50:      	adrp	x16, 0xaa000
   a1b54:      	ldr	x17, [x16, #0xcf0]
   a1b58:      	add	x16, x16, #0xcf0
   a1b5c:      	br	x17

00000000000a1b60 <_ZN8mtlabar326IconSequenceStyleInterface15setBaseTextSizeEf@plt>:
   a1b60:      	adrp	x16, 0xaa000
   a1b64:      	ldr	x17, [x16, #0xcf8]
   a1b68:      	add	x16, x16, #0xcf8
   a1b6c:      	br	x17

00000000000a1b70 <_ZNK8mtlabar326IconSequenceStyleInterface11getFontSizeEv@plt>:
   a1b70:      	adrp	x16, 0xaa000
   a1b74:      	ldr	x17, [x16, #0xd00]
   a1b78:      	add	x16, x16, #0xd00
   a1b7c:      	br	x17

00000000000a1b80 <_ZN8mtlabar326IconSequenceStyleInterface11setFontSizeEf@plt>:
   a1b80:      	adrp	x16, 0xaa000
   a1b84:      	ldr	x17, [x16, #0xd08]
   a1b88:      	add	x16, x16, #0xd08
   a1b8c:      	br	x17

00000000000a1b90 <_ZNK8mtlabar326IconSequenceStyleInterface12getIconWidthEv@plt>:
   a1b90:      	adrp	x16, 0xaa000
   a1b94:      	ldr	x17, [x16, #0xd10]
   a1b98:      	add	x16, x16, #0xd10
   a1b9c:      	br	x17

00000000000a1ba0 <_ZN8mtlabar326IconSequenceStyleInterface12setIconWidthEf@plt>:
   a1ba0:      	adrp	x16, 0xaa000
   a1ba4:      	ldr	x17, [x16, #0xd18]
   a1ba8:      	add	x16, x16, #0xd18
   a1bac:      	br	x17

00000000000a1bb0 <_ZNK8mtlabar326IconSequenceStyleInterface13getIconHeightEv@plt>:
   a1bb0:      	adrp	x16, 0xaa000
   a1bb4:      	ldr	x17, [x16, #0xd20]
   a1bb8:      	add	x16, x16, #0xd20
   a1bbc:      	br	x17

00000000000a1bc0 <_ZN8mtlabar326IconSequenceStyleInterface13setIconHeightEf@plt>:
   a1bc0:      	adrp	x16, 0xaa000
   a1bc4:      	ldr	x17, [x16, #0xd28]
   a1bc8:      	add	x16, x16, #0xd28
   a1bcc:      	br	x17

00000000000a1bd0 <_ZNK8mtlabar326IconSequenceStyleInterface19getReplaceColorSizeEv@plt>:
   a1bd0:      	adrp	x16, 0xaa000
   a1bd4:      	ldr	x17, [x16, #0xd30]
   a1bd8:      	add	x16, x16, #0xd30
   a1bdc:      	br	x17

00000000000a1be0 <_ZN8mtlabar326IconSequenceStyleInterface15getReplaceColorEi@plt>:
   a1be0:      	adrp	x16, 0xaa000
   a1be4:      	ldr	x17, [x16, #0xd38]
   a1be8:      	add	x16, x16, #0xd38
   a1bec:      	br	x17

00000000000a1bf0 <_ZN8mtlabar326IconSequenceStyleInterface19resizeReplaceColorsEm@plt>:
   a1bf0:      	adrp	x16, 0xaa000
   a1bf4:      	ldr	x17, [x16, #0xd40]
   a1bf8:      	add	x16, x16, #0xd40
   a1bfc:      	br	x17

00000000000a1c00 <_ZNK8mtlabar326IconSequenceStyleInterface14getFontLibraryEv@plt>:
   a1c00:      	adrp	x16, 0xaa000
   a1c04:      	ldr	x17, [x16, #0xd48]
   a1c08:      	add	x16, x16, #0xd48
   a1c0c:      	br	x17

00000000000a1c10 <_ZN8mtlabar326IconSequenceStyleInterface14setFontLibraryERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1c10:      	adrp	x16, 0xaa000
   a1c14:      	ldr	x17, [x16, #0xd50]
   a1c18:      	add	x16, x16, #0xd50
   a1c1c:      	br	x17

00000000000a1c20 <_ZNK8mtlabar326IconSequenceStyleInterface18isEnableTextOnIconEv@plt>:
   a1c20:      	adrp	x16, 0xaa000
   a1c24:      	ldr	x17, [x16, #0xd58]
   a1c28:      	add	x16, x16, #0xd58
   a1c2c:      	br	x17

00000000000a1c30 <_ZN8mtlabar326IconSequenceStyleInterface19setEnableTextOnIconEb@plt>:
   a1c30:      	adrp	x16, 0xaa000
   a1c34:      	ldr	x17, [x16, #0xd60]
   a1c38:      	add	x16, x16, #0xd60
   a1c3c:      	br	x17

00000000000a1c40 <_ZNK8mtlabar326IconSequenceStyleInterface13isPaddingZeroEv@plt>:
   a1c40:      	adrp	x16, 0xaa000
   a1c44:      	ldr	x17, [x16, #0xd68]
   a1c48:      	add	x16, x16, #0xd68
   a1c4c:      	br	x17

00000000000a1c50 <_ZN8mtlabar326IconSequenceStyleInterface14setPaddingZeroEb@plt>:
   a1c50:      	adrp	x16, 0xaa000
   a1c54:      	ldr	x17, [x16, #0xd70]
   a1c58:      	add	x16, x16, #0xd70
   a1c5c:      	br	x17

00000000000a1c60 <_ZN8mtlabar326IconSequenceStyleInterface8getColorEv@plt>:
   a1c60:      	adrp	x16, 0xaa000
   a1c64:      	ldr	x17, [x16, #0xd78]
   a1c68:      	add	x16, x16, #0xd78
   a1c6c:      	br	x17

00000000000a1c70 <_ZN8mtlabar326IconSequenceStyleInterface8setColorERKNS_6ColorAE@plt>:
   a1c70:      	adrp	x16, 0xaa000
   a1c74:      	ldr	x17, [x16, #0xd80]
   a1c78:      	add	x16, x16, #0xd80
   a1c7c:      	br	x17

00000000000a1c80 <_ZN8mtlabar320TextASRWordInterface6createEv@plt>:
   a1c80:      	adrp	x16, 0xaa000
   a1c84:      	ldr	x17, [x16, #0xd88]
   a1c88:      	add	x16, x16, #0xd88
   a1c8c:      	br	x17

00000000000a1c90 <_ZN8mtlabar320TextASRWordInterface7destroyEPS0_@plt>:
   a1c90:      	adrp	x16, 0xaa000
   a1c94:      	ldr	x17, [x16, #0xd90]
   a1c98:      	add	x16, x16, #0xd90
   a1c9c:      	br	x17

00000000000a1ca0 <_ZN8mtlabar320TextASRWordInterface8deepCopyEPKS0_@plt>:
   a1ca0:      	adrp	x16, 0xaa000
   a1ca4:      	ldr	x17, [x16, #0xd98]
   a1ca8:      	add	x16, x16, #0xd98
   a1cac:      	br	x17

00000000000a1cb0 <_ZN8mtlabar320TextASRWordInterface16getWordTextIndexEv@plt>:
   a1cb0:      	adrp	x16, 0xaa000
   a1cb4:      	ldr	x17, [x16, #0xda0]
   a1cb8:      	add	x16, x16, #0xda0
   a1cbc:      	br	x17

00000000000a1cc0 <_ZN8mtlabar320TextASRWordInterface16setWordTextIndexEi@plt>:
   a1cc0:      	adrp	x16, 0xaa000
   a1cc4:      	ldr	x17, [x16, #0xda8]
   a1cc8:      	add	x16, x16, #0xda8
   a1ccc:      	br	x17

00000000000a1cd0 <_ZN8mtlabar320TextASRWordInterface17getWordTextLengthEv@plt>:
   a1cd0:      	adrp	x16, 0xaa000
   a1cd4:      	ldr	x17, [x16, #0xdb0]
   a1cd8:      	add	x16, x16, #0xdb0
   a1cdc:      	br	x17

00000000000a1ce0 <_ZN8mtlabar320TextASRWordInterface17setWordTextLengthEi@plt>:
   a1ce0:      	adrp	x16, 0xaa000
   a1ce4:      	ldr	x17, [x16, #0xdb8]
   a1ce8:      	add	x16, x16, #0xdb8
   a1cec:      	br	x17

00000000000a1cf0 <_ZN8mtlabar320TextASRWordInterface21getWordBeginTimestampEv@plt>:
   a1cf0:      	adrp	x16, 0xaa000
   a1cf4:      	ldr	x17, [x16, #0xdc0]
   a1cf8:      	add	x16, x16, #0xdc0
   a1cfc:      	br	x17

00000000000a1d00 <_ZN8mtlabar320TextASRWordInterface21setWordBeginTimestampEf@plt>:
   a1d00:      	adrp	x16, 0xaa000
   a1d04:      	ldr	x17, [x16, #0xdc8]
   a1d08:      	add	x16, x16, #0xdc8
   a1d0c:      	br	x17

00000000000a1d10 <_ZN8mtlabar320TextASRWordInterface19getWordEndTimestampEv@plt>:
   a1d10:      	adrp	x16, 0xaa000
   a1d14:      	ldr	x17, [x16, #0xdd0]
   a1d18:      	add	x16, x16, #0xdd0
   a1d1c:      	br	x17

00000000000a1d20 <_ZN8mtlabar320TextASRWordInterface19setWordEndTimestampEf@plt>:
   a1d20:      	adrp	x16, 0xaa000
   a1d24:      	ldr	x17, [x16, #0xdd8]
   a1d28:      	add	x16, x16, #0xdd8
   a1d2c:      	br	x17

00000000000a1d30 <_ZN8mtlabar316TextASRInterface6createEv@plt>:
   a1d30:      	adrp	x16, 0xaa000
   a1d34:      	ldr	x17, [x16, #0xde0]
   a1d38:      	add	x16, x16, #0xde0
   a1d3c:      	br	x17

00000000000a1d40 <_ZN8mtlabar316TextASRInterface7destroyEPS0_@plt>:
   a1d40:      	adrp	x16, 0xaa000
   a1d44:      	ldr	x17, [x16, #0xde8]
   a1d48:      	add	x16, x16, #0xde8
   a1d4c:      	br	x17

00000000000a1d50 <_ZN8mtlabar316TextASRInterface8deepCopyEPKS0_@plt>:
   a1d50:      	adrp	x16, 0xaa000
   a1d54:      	ldr	x17, [x16, #0xdf0]
   a1d58:      	add	x16, x16, #0xdf0
   a1d5c:      	br	x17

00000000000a1d60 <_ZN8mtlabar316TextASRInterface16getASRWordsCountEv@plt>:
   a1d60:      	adrp	x16, 0xaa000
   a1d64:      	ldr	x17, [x16, #0xdf8]
   a1d68:      	add	x16, x16, #0xdf8
   a1d6c:      	br	x17

00000000000a1d70 <_ZNK8mtlabar316TextASRInterface10getASRWordEi@plt>:
   a1d70:      	adrp	x16, 0xaa000
   a1d74:      	ldr	x17, [x16, #0xe00]
   a1d78:      	add	x16, x16, #0xe00
   a1d7c:      	br	x17

00000000000a1d80 <_ZN8mtlabar316TextASRInterface10addASRWordEv@plt>:
   a1d80:      	adrp	x16, 0xaa000
   a1d84:      	ldr	x17, [x16, #0xe08]
   a1d88:      	add	x16, x16, #0xe08
   a1d8c:      	br	x17

00000000000a1d90 <_ZN8mtlabar316TextASRInterface17removeTextASRWordEPNS_20TextASRWordInterfaceE@plt>:
   a1d90:      	adrp	x16, 0xaa000
   a1d94:      	ldr	x17, [x16, #0xe10]
   a1d98:      	add	x16, x16, #0xe10
   a1d9c:      	br	x17

00000000000a1da0 <_ZN8mtlabar316TextASRInterface16resizeWordsCountEi@plt>:
   a1da0:      	adrp	x16, 0xaa000
   a1da4:      	ldr	x17, [x16, #0xe18]
   a1da8:      	add	x16, x16, #0xe18
   a1dac:      	br	x17

00000000000a1db0 <_ZN8mtlabar316TextASRInterface20getASRBeginTimestampEv@plt>:
   a1db0:      	adrp	x16, 0xaa000
   a1db4:      	ldr	x17, [x16, #0xe20]
   a1db8:      	add	x16, x16, #0xe20
   a1dbc:      	br	x17

00000000000a1dc0 <_ZN8mtlabar316TextASRInterface20setASRBeginTimestampEf@plt>:
   a1dc0:      	adrp	x16, 0xaa000
   a1dc4:      	ldr	x17, [x16, #0xe28]
   a1dc8:      	add	x16, x16, #0xe28
   a1dcc:      	br	x17

00000000000a1dd0 <_ZN8mtlabar316TextASRInterface18getASREndTimestampEv@plt>:
   a1dd0:      	adrp	x16, 0xaa000
   a1dd4:      	ldr	x17, [x16, #0xe30]
   a1dd8:      	add	x16, x16, #0xe30
   a1ddc:      	br	x17

00000000000a1de0 <_ZN8mtlabar316TextASRInterface18setASREndTimestampEf@plt>:
   a1de0:      	adrp	x16, 0xaa000
   a1de4:      	ldr	x17, [x16, #0xe38]
   a1de8:      	add	x16, x16, #0xe38
   a1dec:      	br	x17

00000000000a1df0 <_ZN8mtlabar316TextASRInterface25getASRDisplayEndTimestampEv@plt>:
   a1df0:      	adrp	x16, 0xaa000
   a1df4:      	ldr	x17, [x16, #0xe40]
   a1df8:      	add	x16, x16, #0xe40
   a1dfc:      	br	x17

00000000000a1e00 <_ZN8mtlabar316TextASRInterface25setASRDisplayEndTimestampEf@plt>:
   a1e00:      	adrp	x16, 0xaa000
   a1e04:      	ldr	x17, [x16, #0xe48]
   a1e08:      	add	x16, x16, #0xe48
   a1e0c:      	br	x17

00000000000a1e10 <_ZN8mtlabar316TextASRInterface16getASRGroupIndexEv@plt>:
   a1e10:      	adrp	x16, 0xaa000
   a1e14:      	ldr	x17, [x16, #0xe50]
   a1e18:      	add	x16, x16, #0xe50
   a1e1c:      	br	x17

00000000000a1e20 <_ZN8mtlabar316TextASRInterface16setASRGroupIndexEi@plt>:
   a1e20:      	adrp	x16, 0xaa000
   a1e24:      	ldr	x17, [x16, #0xe58]
   a1e28:      	add	x16, x16, #0xe58
   a1e2c:      	br	x17

00000000000a1e30 <_ZN8mtlabar316TextASRInterface19getASRAnimationTimeEv@plt>:
   a1e30:      	adrp	x16, 0xaa000
   a1e34:      	ldr	x17, [x16, #0xe60]
   a1e38:      	add	x16, x16, #0xe60
   a1e3c:      	br	x17

00000000000a1e40 <_ZN8mtlabar316TextASRInterface19setASRAnimationTimeEf@plt>:
   a1e40:      	adrp	x16, 0xaa000
   a1e44:      	ldr	x17, [x16, #0xe68]
   a1e48:      	add	x16, x16, #0xe68
   a1e4c:      	br	x17

00000000000a1e50 <_ZN8mtlabar323TextWarpConfigInterface6createEv@plt>:
   a1e50:      	adrp	x16, 0xaa000
   a1e54:      	ldr	x17, [x16, #0xe70]
   a1e58:      	add	x16, x16, #0xe70
   a1e5c:      	br	x17

00000000000a1e60 <_ZN8mtlabar323TextWarpConfigInterface7destroyEPS0_@plt>:
   a1e60:      	adrp	x16, 0xaa000
   a1e64:      	ldr	x17, [x16, #0xe78]
   a1e68:      	add	x16, x16, #0xe78
   a1e6c:      	br	x17

00000000000a1e70 <_ZN8mtlabar323TextWarpConfigInterface8deepCopyEPKS0_@plt>:
   a1e70:      	adrp	x16, 0xaa000
   a1e74:      	ldr	x17, [x16, #0xe80]
   a1e78:      	add	x16, x16, #0xe80
   a1e7c:      	br	x17

00000000000a1e80 <_ZN8mtlabar323TextWarpConfigInterface11setWarpTypeENS_12WarpMeshTypeE@plt>:
   a1e80:      	adrp	x16, 0xaa000
   a1e84:      	ldr	x17, [x16, #0xe88]
   a1e88:      	add	x16, x16, #0xe88
   a1e8c:      	br	x17

00000000000a1e90 <_ZNK8mtlabar323TextWarpConfigInterface11getWarpTypeEv@plt>:
   a1e90:      	adrp	x16, 0xaa000
   a1e94:      	ldr	x17, [x16, #0xe90]
   a1e98:      	add	x16, x16, #0xe90
   a1e9c:      	br	x17

00000000000a1ea0 <_ZN8mtlabar323TextWarpConfigInterface17setWarpConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1ea0:      	adrp	x16, 0xaa000
   a1ea4:      	ldr	x17, [x16, #0xe98]
   a1ea8:      	add	x16, x16, #0xe98
   a1eac:      	br	x17

00000000000a1eb0 <_ZNK8mtlabar323TextWarpConfigInterface17getWarpConfigPathEv@plt>:
   a1eb0:      	adrp	x16, 0xaa000
   a1eb4:      	ldr	x17, [x16, #0xea0]
   a1eb8:      	add	x16, x16, #0xea0
   a1ebc:      	br	x17

00000000000a1ec0 <_ZN8mtlabar323TextWarpConfigInterface15setWarpProgressEf@plt>:
   a1ec0:      	adrp	x16, 0xaa000
   a1ec4:      	ldr	x17, [x16, #0xea8]
   a1ec8:      	add	x16, x16, #0xea8
   a1ecc:      	br	x17

00000000000a1ed0 <_ZNK8mtlabar323TextWarpConfigInterface15getWarpProgressEv@plt>:
   a1ed0:      	adrp	x16, 0xaa000
   a1ed4:      	ldr	x17, [x16, #0xeb0]
   a1ed8:      	add	x16, x16, #0xeb0
   a1edc:      	br	x17

00000000000a1ee0 <_ZN8mtlabar323TextWarpConfigInterface21setWarpRelativeHeightEf@plt>:
   a1ee0:      	adrp	x16, 0xaa000
   a1ee4:      	ldr	x17, [x16, #0xeb8]
   a1ee8:      	add	x16, x16, #0xeb8
   a1eec:      	br	x17

00000000000a1ef0 <_ZNK8mtlabar323TextWarpConfigInterface21getWarpRelativeHeightEv@plt>:
   a1ef0:      	adrp	x16, 0xaa000
   a1ef4:      	ldr	x17, [x16, #0xec0]
   a1ef8:      	add	x16, x16, #0xec0
   a1efc:      	br	x17

00000000000a1f00 <_ZN8mtlabar326CharSVGBackgroundInterface6createEv@plt>:
   a1f00:      	adrp	x16, 0xaa000
   a1f04:      	ldr	x17, [x16, #0xec8]
   a1f08:      	add	x16, x16, #0xec8
   a1f0c:      	br	x17

00000000000a1f10 <_ZN8mtlabar326CharSVGBackgroundInterface7destroyEPS0_@plt>:
   a1f10:      	adrp	x16, 0xaa000
   a1f14:      	ldr	x17, [x16, #0xed0]
   a1f18:      	add	x16, x16, #0xed0
   a1f1c:      	br	x17

00000000000a1f20 <_ZN8mtlabar326CharSVGBackgroundInterface8deepCopyEPKS0_@plt>:
   a1f20:      	adrp	x16, 0xaa000
   a1f24:      	ldr	x17, [x16, #0xed8]
   a1f28:      	add	x16, x16, #0xed8
   a1f2c:      	br	x17

00000000000a1f30 <_ZN8mtlabar326CharSVGBackgroundInterface9setEnableEb@plt>:
   a1f30:      	adrp	x16, 0xaa000
   a1f34:      	ldr	x17, [x16, #0xee0]
   a1f38:      	add	x16, x16, #0xee0
   a1f3c:      	br	x17

00000000000a1f40 <_ZNK8mtlabar326CharSVGBackgroundInterface9getEnableEv@plt>:
   a1f40:      	adrp	x16, 0xaa000
   a1f44:      	ldr	x17, [x16, #0xee8]
   a1f48:      	add	x16, x16, #0xee8
   a1f4c:      	br	x17

00000000000a1f50 <_ZN8mtlabar326CharSVGBackgroundInterface11setEditableEb@plt>:
   a1f50:      	adrp	x16, 0xaa000
   a1f54:      	ldr	x17, [x16, #0xef0]
   a1f58:      	add	x16, x16, #0xef0
   a1f5c:      	br	x17

00000000000a1f60 <_ZNK8mtlabar326CharSVGBackgroundInterface11getEditableEv@plt>:
   a1f60:      	adrp	x16, 0xaa000
   a1f64:      	ldr	x17, [x16, #0xef8]
   a1f68:      	add	x16, x16, #0xef8
   a1f6c:      	br	x17

00000000000a1f70 <_ZN8mtlabar326CharSVGBackgroundInterface7setSizeEf@plt>:
   a1f70:      	adrp	x16, 0xaa000
   a1f74:      	ldr	x17, [x16, #0xf00]
   a1f78:      	add	x16, x16, #0xf00
   a1f7c:      	br	x17

00000000000a1f80 <_ZNK8mtlabar326CharSVGBackgroundInterface7getSizeEv@plt>:
   a1f80:      	adrp	x16, 0xaa000
   a1f84:      	ldr	x17, [x16, #0xf08]
   a1f88:      	add	x16, x16, #0xf08
   a1f8c:      	br	x17

00000000000a1f90 <_ZN8mtlabar326CharSVGBackgroundInterface9setOffsetERKNS_6Float2E@plt>:
   a1f90:      	adrp	x16, 0xaa000
   a1f94:      	ldr	x17, [x16, #0xf10]
   a1f98:      	add	x16, x16, #0xf10
   a1f9c:      	br	x17

00000000000a1fa0 <_ZNK8mtlabar326CharSVGBackgroundInterface9getOffsetEv@plt>:
   a1fa0:      	adrp	x16, 0xaa000
   a1fa4:      	ldr	x17, [x16, #0xf18]
   a1fa8:      	add	x16, x16, #0xf18
   a1fac:      	br	x17

00000000000a1fb0 <_ZN8mtlabar326CharSVGBackgroundInterface10setPaddingERKNS_6Float2E@plt>:
   a1fb0:      	adrp	x16, 0xaa000
   a1fb4:      	ldr	x17, [x16, #0xf20]
   a1fb8:      	add	x16, x16, #0xf20
   a1fbc:      	br	x17

00000000000a1fc0 <_ZNK8mtlabar326CharSVGBackgroundInterface10getPaddingEv@plt>:
   a1fc0:      	adrp	x16, 0xaa000
   a1fc4:      	ldr	x17, [x16, #0xf28]
   a1fc8:      	add	x16, x16, #0xf28
   a1fcc:      	br	x17

00000000000a1fd0 <_ZN8mtlabar326CharSVGBackgroundInterface11setUseCountEi@plt>:
   a1fd0:      	adrp	x16, 0xaa000
   a1fd4:      	ldr	x17, [x16, #0xf30]
   a1fd8:      	add	x16, x16, #0xf30
   a1fdc:      	br	x17

00000000000a1fe0 <_ZNK8mtlabar326CharSVGBackgroundInterface11getUseCountEv@plt>:
   a1fe0:      	adrp	x16, 0xaa000
   a1fe4:      	ldr	x17, [x16, #0xf38]
   a1fe8:      	add	x16, x16, #0xf38
   a1fec:      	br	x17

00000000000a1ff0 <_ZN8mtlabar326CharSVGBackgroundInterface24setCharSVGBackgroundPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a1ff0:      	adrp	x16, 0xaa000
   a1ff4:      	ldr	x17, [x16, #0xf40]
   a1ff8:      	add	x16, x16, #0xf40
   a1ffc:      	br	x17

00000000000a2000 <_ZNK8mtlabar326CharSVGBackgroundInterface24getCharSVGBackgroundPathEv@plt>:
   a2000:      	adrp	x16, 0xaa000
   a2004:      	ldr	x17, [x16, #0xf48]
   a2008:      	add	x16, x16, #0xf48
   a200c:      	br	x17

00000000000a2010 <_ZN8mtlabar331TextInactiveTextConfigInterface6createEv@plt>:
   a2010:      	adrp	x16, 0xaa000
   a2014:      	ldr	x17, [x16, #0xf50]
   a2018:      	add	x16, x16, #0xf50
   a201c:      	br	x17

00000000000a2020 <_ZN8mtlabar331TextInactiveTextConfigInterface7destroyEPS0_@plt>:
   a2020:      	adrp	x16, 0xaa000
   a2024:      	ldr	x17, [x16, #0xf58]
   a2028:      	add	x16, x16, #0xf58
   a202c:      	br	x17

00000000000a2030 <_ZN8mtlabar331TextInactiveTextConfigInterface8deepCopyEPKS0_@plt>:
   a2030:      	adrp	x16, 0xaa000
   a2034:      	ldr	x17, [x16, #0xf60]
   a2038:      	add	x16, x16, #0xf60
   a203c:      	br	x17

00000000000a2040 <_ZN8mtlabar331TextInactiveTextConfigInterface9setEnableEb@plt>:
   a2040:      	adrp	x16, 0xaa000
   a2044:      	ldr	x17, [x16, #0xf68]
   a2048:      	add	x16, x16, #0xf68
   a204c:      	br	x17

00000000000a2050 <_ZNK8mtlabar331TextInactiveTextConfigInterface9getEnableEv@plt>:
   a2050:      	adrp	x16, 0xaa000
   a2054:      	ldr	x17, [x16, #0xf70]
   a2058:      	add	x16, x16, #0xf70
   a205c:      	br	x17

00000000000a2060 <_ZN8mtlabar331TextInactiveTextConfigInterface7setTextERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2060:      	adrp	x16, 0xaa000
   a2064:      	ldr	x17, [x16, #0xf78]
   a2068:      	add	x16, x16, #0xf78
   a206c:      	br	x17

00000000000a2070 <_ZNK8mtlabar331TextInactiveTextConfigInterface7getTextEv@plt>:
   a2070:      	adrp	x16, 0xaa000
   a2074:      	ldr	x17, [x16, #0xf80]
   a2078:      	add	x16, x16, #0xf80
   a207c:      	br	x17

00000000000a2080 <_ZN8mtlabar331TextInactiveTextConfigInterface11setFontSizeEf@plt>:
   a2080:      	adrp	x16, 0xaa000
   a2084:      	ldr	x17, [x16, #0xf88]
   a2088:      	add	x16, x16, #0xf88
   a208c:      	br	x17

00000000000a2090 <_ZNK8mtlabar331TextInactiveTextConfigInterface11getFontSizeEv@plt>:
   a2090:      	adrp	x16, 0xaa000
   a2094:      	ldr	x17, [x16, #0xf90]
   a2098:      	add	x16, x16, #0xf90
   a209c:      	br	x17

00000000000a20a0 <_ZN8mtlabar331TextInactiveTextConfigInterface6setPosENS_4text15InactiveTextPosE@plt>:
   a20a0:      	adrp	x16, 0xaa000
   a20a4:      	ldr	x17, [x16, #0xf98]
   a20a8:      	add	x16, x16, #0xf98
   a20ac:      	br	x17

00000000000a20b0 <_ZNK8mtlabar331TextInactiveTextConfigInterface6getPosEv@plt>:
   a20b0:      	adrp	x16, 0xaa000
   a20b4:      	ldr	x17, [x16, #0xfa0]
   a20b8:      	add	x16, x16, #0xfa0
   a20bc:      	br	x17

00000000000a20c0 <_ZN8mtlabar331TextInactiveTextConfigInterface17setBeginTimestampEf@plt>:
   a20c0:      	adrp	x16, 0xaa000
   a20c4:      	ldr	x17, [x16, #0xfa8]
   a20c8:      	add	x16, x16, #0xfa8
   a20cc:      	br	x17

00000000000a20d0 <_ZNK8mtlabar331TextInactiveTextConfigInterface17getBeginTimestampEv@plt>:
   a20d0:      	adrp	x16, 0xaa000
   a20d4:      	ldr	x17, [x16, #0xfb0]
   a20d8:      	add	x16, x16, #0xfb0
   a20dc:      	br	x17

00000000000a20e0 <_ZN8mtlabar331TextInactiveTextConfigInterface15setEndTimestampEf@plt>:
   a20e0:      	adrp	x16, 0xaa000
   a20e4:      	ldr	x17, [x16, #0xfb8]
   a20e8:      	add	x16, x16, #0xfb8
   a20ec:      	br	x17

00000000000a20f0 <_ZNK8mtlabar331TextInactiveTextConfigInterface15getEndTimestampEv@plt>:
   a20f0:      	adrp	x16, 0xaa000
   a20f4:      	ldr	x17, [x16, #0xfc0]
   a20f8:      	add	x16, x16, #0xfc0
   a20fc:      	br	x17

00000000000a2100 <_ZN8mtlabar331TextInactiveTextConfigInterface22setAnimationConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2100:      	adrp	x16, 0xaa000
   a2104:      	ldr	x17, [x16, #0xfc8]
   a2108:      	add	x16, x16, #0xfc8
   a210c:      	br	x17

00000000000a2110 <_ZNK8mtlabar331TextInactiveTextConfigInterface22getAnimationConfigPathEv@plt>:
   a2110:      	adrp	x16, 0xaa000
   a2114:      	ldr	x17, [x16, #0xfd0]
   a2118:      	add	x16, x16, #0xfd0
   a211c:      	br	x17

00000000000a2120 <_ZN8mtlabar331TextInactiveTextConfigInterface10getTextASREv@plt>:
   a2120:      	adrp	x16, 0xaa000
   a2124:      	ldr	x17, [x16, #0xfd8]
   a2128:      	add	x16, x16, #0xfd8
   a212c:      	br	x17

00000000000a2130 <_ZN8mtlabar324CustomTransformInterface6createEv@plt>:
   a2130:      	adrp	x16, 0xaa000
   a2134:      	ldr	x17, [x16, #0xfe0]
   a2138:      	add	x16, x16, #0xfe0
   a213c:      	br	x17

00000000000a2140 <_ZN8mtlabar324CustomTransformInterface7destroyEPS0_@plt>:
   a2140:      	adrp	x16, 0xaa000
   a2144:      	ldr	x17, [x16, #0xfe8]
   a2148:      	add	x16, x16, #0xfe8
   a214c:      	br	x17

00000000000a2150 <_ZN8mtlabar324CustomTransformInterface8deepCopyEPKS0_@plt>:
   a2150:      	adrp	x16, 0xaa000
   a2154:      	ldr	x17, [x16, #0xff0]
   a2158:      	add	x16, x16, #0xff0
   a215c:      	br	x17

00000000000a2160 <_ZN8mtlabar324CustomTransformInterface17setEnablePositionEb@plt>:
   a2160:      	adrp	x16, 0xaa000
   a2164:      	ldr	x17, [x16, #0xff8]
   a2168:      	add	x16, x16, #0xff8
   a216c:      	br	x17

00000000000a2170 <_ZNK8mtlabar324CustomTransformInterface17getEnablePositionEv@plt>:
   a2170:      	adrp	x16, 0xab000
   a2174:      	ldr	x17, [x16]
   a2178:      	add	x16, x16, #0x0
   a217c:      	br	x17

00000000000a2180 <_ZN8mtlabar324CustomTransformInterface14setEnableScaleEb@plt>:
   a2180:      	adrp	x16, 0xab000
   a2184:      	ldr	x17, [x16, #0x8]
   a2188:      	add	x16, x16, #0x8
   a218c:      	br	x17

00000000000a2190 <_ZNK8mtlabar324CustomTransformInterface14getEnableScaleEv@plt>:
   a2190:      	adrp	x16, 0xab000
   a2194:      	ldr	x17, [x16, #0x10]
   a2198:      	add	x16, x16, #0x10
   a219c:      	br	x17

00000000000a21a0 <_ZN8mtlabar324CustomTransformInterface15setEnableRotateEb@plt>:
   a21a0:      	adrp	x16, 0xab000
   a21a4:      	ldr	x17, [x16, #0x18]
   a21a8:      	add	x16, x16, #0x18
   a21ac:      	br	x17

00000000000a21b0 <_ZNK8mtlabar324CustomTransformInterface15getEnableRotateEv@plt>:
   a21b0:      	adrp	x16, 0xab000
   a21b4:      	ldr	x17, [x16, #0x20]
   a21b8:      	add	x16, x16, #0x20
   a21bc:      	br	x17

00000000000a21c0 <_ZN8mtlabar324CustomTransformInterface11setPositionERKNS_6Float3E@plt>:
   a21c0:      	adrp	x16, 0xab000
   a21c4:      	ldr	x17, [x16, #0x28]
   a21c8:      	add	x16, x16, #0x28
   a21cc:      	br	x17

00000000000a21d0 <_ZNK8mtlabar324CustomTransformInterface11getPositionEv@plt>:
   a21d0:      	adrp	x16, 0xab000
   a21d4:      	ldr	x17, [x16, #0x30]
   a21d8:      	add	x16, x16, #0x30
   a21dc:      	br	x17

00000000000a21e0 <_ZN8mtlabar324CustomTransformInterface8setScaleERKNS_6Float3E@plt>:
   a21e0:      	adrp	x16, 0xab000
   a21e4:      	ldr	x17, [x16, #0x38]
   a21e8:      	add	x16, x16, #0x38
   a21ec:      	br	x17

00000000000a21f0 <_ZNK8mtlabar324CustomTransformInterface8getScaleEv@plt>:
   a21f0:      	adrp	x16, 0xab000
   a21f4:      	ldr	x17, [x16, #0x40]
   a21f8:      	add	x16, x16, #0x40
   a21fc:      	br	x17

00000000000a2200 <_ZN8mtlabar324CustomTransformInterface16setPositionSpeedEf@plt>:
   a2200:      	adrp	x16, 0xab000
   a2204:      	ldr	x17, [x16, #0x48]
   a2208:      	add	x16, x16, #0x48
   a220c:      	br	x17

00000000000a2210 <_ZNK8mtlabar324CustomTransformInterface16getPositionSpeedEv@plt>:
   a2210:      	adrp	x16, 0xab000
   a2214:      	ldr	x17, [x16, #0x50]
   a2218:      	add	x16, x16, #0x50
   a221c:      	br	x17

00000000000a2220 <_ZN8mtlabar324CustomTransformInterface13setScaleSpeedEf@plt>:
   a2220:      	adrp	x16, 0xab000
   a2224:      	ldr	x17, [x16, #0x58]
   a2228:      	add	x16, x16, #0x58
   a222c:      	br	x17

00000000000a2230 <_ZNK8mtlabar324CustomTransformInterface13getScaleSpeedEv@plt>:
   a2230:      	adrp	x16, 0xab000
   a2234:      	ldr	x17, [x16, #0x60]
   a2238:      	add	x16, x16, #0x60
   a223c:      	br	x17

00000000000a2240 <_ZN8mtlabar324CustomTransformInterface14setRotateAngleEf@plt>:
   a2240:      	adrp	x16, 0xab000
   a2244:      	ldr	x17, [x16, #0x68]
   a2248:      	add	x16, x16, #0x68
   a224c:      	br	x17

00000000000a2250 <_ZNK8mtlabar324CustomTransformInterface14getRotateAngleEv@plt>:
   a2250:      	adrp	x16, 0xab000
   a2254:      	ldr	x17, [x16, #0x70]
   a2258:      	add	x16, x16, #0x70
   a225c:      	br	x17

00000000000a2260 <_ZN8mtlabar324CustomTransformInterface14setElapsedTimeEf@plt>:
   a2260:      	adrp	x16, 0xab000
   a2264:      	ldr	x17, [x16, #0x78]
   a2268:      	add	x16, x16, #0x78
   a226c:      	br	x17

00000000000a2270 <_ZNK8mtlabar324CustomTransformInterface14getElapsedTimeEv@plt>:
   a2270:      	adrp	x16, 0xab000
   a2274:      	ldr	x17, [x16, #0x80]
   a2278:      	add	x16, x16, #0x80
   a227c:      	br	x17

00000000000a2280 <_ZN8mtlabar321ActiveWordBgInterface6createEv@plt>:
   a2280:      	adrp	x16, 0xab000
   a2284:      	ldr	x17, [x16, #0x88]
   a2288:      	add	x16, x16, #0x88
   a228c:      	br	x17

00000000000a2290 <_ZN8mtlabar321ActiveWordBgInterface7destroyEPS0_@plt>:
   a2290:      	adrp	x16, 0xab000
   a2294:      	ldr	x17, [x16, #0x90]
   a2298:      	add	x16, x16, #0x90
   a229c:      	br	x17

00000000000a22a0 <_ZN8mtlabar321ActiveWordBgInterface8deepCopyEPKS0_@plt>:
   a22a0:      	adrp	x16, 0xab000
   a22a4:      	ldr	x17, [x16, #0x98]
   a22a8:      	add	x16, x16, #0x98
   a22ac:      	br	x17

00000000000a22b0 <_ZN8mtlabar321ActiveWordBgInterface9setEnableEb@plt>:
   a22b0:      	adrp	x16, 0xab000
   a22b4:      	ldr	x17, [x16, #0xa0]
   a22b8:      	add	x16, x16, #0xa0
   a22bc:      	br	x17

00000000000a22c0 <_ZNK8mtlabar321ActiveWordBgInterface9getEnableEv@plt>:
   a22c0:      	adrp	x16, 0xab000
   a22c4:      	ldr	x17, [x16, #0xa8]
   a22c8:      	add	x16, x16, #0xa8
   a22cc:      	br	x17

00000000000a22d0 <_ZN8mtlabar321ActiveWordBgInterface8getColorEv@plt>:
   a22d0:      	adrp	x16, 0xab000
   a22d4:      	ldr	x17, [x16, #0xb0]
   a22d8:      	add	x16, x16, #0xb0
   a22dc:      	br	x17

00000000000a22e0 <_ZN8mtlabar321ActiveWordBgInterface8setColorERKNS_6ColorAE@plt>:
   a22e0:      	adrp	x16, 0xab000
   a22e4:      	ldr	x17, [x16, #0xb8]
   a22e8:      	add	x16, x16, #0xb8
   a22ec:      	br	x17

00000000000a22f0 <_ZN8mtlabar321ActiveWordBgInterface19setEnableGradientBGEb@plt>:
   a22f0:      	adrp	x16, 0xab000
   a22f4:      	ldr	x17, [x16, #0xc0]
   a22f8:      	add	x16, x16, #0xc0
   a22fc:      	br	x17

00000000000a2300 <_ZNK8mtlabar321ActiveWordBgInterface19getEnableGradientBGEv@plt>:
   a2300:      	adrp	x16, 0xab000
   a2304:      	ldr	x17, [x16, #0xc8]
   a2308:      	add	x16, x16, #0xc8
   a230c:      	br	x17

00000000000a2310 <_ZN8mtlabar321ActiveWordBgInterface14getSecondColorEv@plt>:
   a2310:      	adrp	x16, 0xab000
   a2314:      	ldr	x17, [x16, #0xd0]
   a2318:      	add	x16, x16, #0xd0
   a231c:      	br	x17

00000000000a2320 <_ZN8mtlabar321ActiveWordBgInterface14setSecondColorERKNS_6ColorAE@plt>:
   a2320:      	adrp	x16, 0xab000
   a2324:      	ldr	x17, [x16, #0xd8]
   a2328:      	add	x16, x16, #0xd8
   a232c:      	br	x17

00000000000a2330 <_ZN8mtlabar321ActiveWordBgInterface9setRadiusEf@plt>:
   a2330:      	adrp	x16, 0xab000
   a2334:      	ldr	x17, [x16, #0xe0]
   a2338:      	add	x16, x16, #0xe0
   a233c:      	br	x17

00000000000a2340 <_ZNK8mtlabar321ActiveWordBgInterface9getRadiusEv@plt>:
   a2340:      	adrp	x16, 0xab000
   a2344:      	ldr	x17, [x16, #0xe8]
   a2348:      	add	x16, x16, #0xe8
   a234c:      	br	x17

00000000000a2350 <_ZN8mtlabar321ActiveWordBgInterface17setTransitionTypeENS_20WordBgTransitionTypeE@plt>:
   a2350:      	adrp	x16, 0xab000
   a2354:      	ldr	x17, [x16, #0xf0]
   a2358:      	add	x16, x16, #0xf0
   a235c:      	br	x17

00000000000a2360 <_ZNK8mtlabar321ActiveWordBgInterface17getTransitionTypeEv@plt>:
   a2360:      	adrp	x16, 0xab000
   a2364:      	ldr	x17, [x16, #0xf8]
   a2368:      	add	x16, x16, #0xf8
   a236c:      	br	x17

00000000000a2370 <_ZN8mtlabar326ActiveWordBGParamInterface6createEv@plt>:
   a2370:      	adrp	x16, 0xab000
   a2374:      	ldr	x17, [x16, #0x100]
   a2378:      	add	x16, x16, #0x100
   a237c:      	br	x17

00000000000a2380 <_ZN8mtlabar326ActiveWordBGParamInterface7destroyEPS0_@plt>:
   a2380:      	adrp	x16, 0xab000
   a2384:      	ldr	x17, [x16, #0x108]
   a2388:      	add	x16, x16, #0x108
   a238c:      	br	x17

00000000000a2390 <_ZN8mtlabar326ActiveWordBGParamInterface8deepCopyEPKS0_@plt>:
   a2390:      	adrp	x16, 0xab000
   a2394:      	ldr	x17, [x16, #0x110]
   a2398:      	add	x16, x16, #0x110
   a239c:      	br	x17

00000000000a23a0 <_ZN8mtlabar326ActiveWordBGParamInterface9setMarginEi@plt>:
   a23a0:      	adrp	x16, 0xab000
   a23a4:      	ldr	x17, [x16, #0x118]
   a23a8:      	add	x16, x16, #0x118
   a23ac:      	br	x17

00000000000a23b0 <_ZNK8mtlabar326ActiveWordBGParamInterface9getMarginEv@plt>:
   a23b0:      	adrp	x16, 0xab000
   a23b4:      	ldr	x17, [x16, #0x120]
   a23b8:      	add	x16, x16, #0x120
   a23bc:      	br	x17

00000000000a23c0 <_ZN8mtlabar326ActiveWordBGParamInterface23setMarginExtendCoefLeftEf@plt>:
   a23c0:      	adrp	x16, 0xab000
   a23c4:      	ldr	x17, [x16, #0x128]
   a23c8:      	add	x16, x16, #0x128
   a23cc:      	br	x17

00000000000a23d0 <_ZNK8mtlabar326ActiveWordBGParamInterface23getMarginExtendCoefLeftEv@plt>:
   a23d0:      	adrp	x16, 0xab000
   a23d4:      	ldr	x17, [x16, #0x130]
   a23d8:      	add	x16, x16, #0x130
   a23dc:      	br	x17

00000000000a23e0 <_ZN8mtlabar326ActiveWordBGParamInterface22setMarginExtendCoefTopEf@plt>:
   a23e0:      	adrp	x16, 0xab000
   a23e4:      	ldr	x17, [x16, #0x138]
   a23e8:      	add	x16, x16, #0x138
   a23ec:      	br	x17

00000000000a23f0 <_ZNK8mtlabar326ActiveWordBGParamInterface22getMarginExtendCoefTopEv@plt>:
   a23f0:      	adrp	x16, 0xab000
   a23f4:      	ldr	x17, [x16, #0x140]
   a23f8:      	add	x16, x16, #0x140
   a23fc:      	br	x17

00000000000a2400 <_ZN8mtlabar326ActiveWordBGParamInterface24setMarginExtendCoefRightEf@plt>:
   a2400:      	adrp	x16, 0xab000
   a2404:      	ldr	x17, [x16, #0x148]
   a2408:      	add	x16, x16, #0x148
   a240c:      	br	x17

00000000000a2410 <_ZNK8mtlabar326ActiveWordBGParamInterface24getMarginExtendCoefRightEv@plt>:
   a2410:      	adrp	x16, 0xab000
   a2414:      	ldr	x17, [x16, #0x150]
   a2418:      	add	x16, x16, #0x150
   a241c:      	br	x17

00000000000a2420 <_ZN8mtlabar326ActiveWordBGParamInterface25setMarginExtendCoefBottomEf@plt>:
   a2420:      	adrp	x16, 0xab000
   a2424:      	ldr	x17, [x16, #0x158]
   a2428:      	add	x16, x16, #0x158
   a242c:      	br	x17

00000000000a2430 <_ZNK8mtlabar326ActiveWordBGParamInterface25getMarginExtendCoefBottomEv@plt>:
   a2430:      	adrp	x16, 0xab000
   a2434:      	ldr	x17, [x16, #0x160]
   a2438:      	add	x16, x16, #0x160
   a243c:      	br	x17

00000000000a2440 <_ZN8mtlabar326ActiveWordBGParamInterface16setAnimationTimeEf@plt>:
   a2440:      	adrp	x16, 0xab000
   a2444:      	ldr	x17, [x16, #0x168]
   a2448:      	add	x16, x16, #0x168
   a244c:      	br	x17

00000000000a2450 <_ZNK8mtlabar326ActiveWordBGParamInterface16getAnimationTimeEv@plt>:
   a2450:      	adrp	x16, 0xab000
   a2454:      	ldr	x17, [x16, #0x170]
   a2458:      	add	x16, x16, #0x170
   a245c:      	br	x17

00000000000a2460 <_ZN8mtlabar326ActiveWordBGParamInterface8getParamEv@plt>:
   a2460:      	adrp	x16, 0xab000
   a2464:      	ldr	x17, [x16, #0x178]
   a2468:      	add	x16, x16, #0x178
   a246c:      	br	x17

00000000000a2470 <_ZN8mtlabar324ActiveWordColorInterface6createEv@plt>:
   a2470:      	adrp	x16, 0xab000
   a2474:      	ldr	x17, [x16, #0x180]
   a2478:      	add	x16, x16, #0x180
   a247c:      	br	x17

00000000000a2480 <_ZN8mtlabar324ActiveWordColorInterface7destroyEPS0_@plt>:
   a2480:      	adrp	x16, 0xab000
   a2484:      	ldr	x17, [x16, #0x188]
   a2488:      	add	x16, x16, #0x188
   a248c:      	br	x17

00000000000a2490 <_ZN8mtlabar324ActiveWordColorInterface8deepCopyEPKS0_@plt>:
   a2490:      	adrp	x16, 0xab000
   a2494:      	ldr	x17, [x16, #0x190]
   a2498:      	add	x16, x16, #0x190
   a249c:      	br	x17

00000000000a24a0 <_ZN8mtlabar324ActiveWordColorInterface9setEnableEb@plt>:
   a24a0:      	adrp	x16, 0xab000
   a24a4:      	ldr	x17, [x16, #0x198]
   a24a8:      	add	x16, x16, #0x198
   a24ac:      	br	x17

00000000000a24b0 <_ZNK8mtlabar324ActiveWordColorInterface9getEnableEv@plt>:
   a24b0:      	adrp	x16, 0xab000
   a24b4:      	ldr	x17, [x16, #0x1a0]
   a24b8:      	add	x16, x16, #0x1a0
   a24bc:      	br	x17

00000000000a24c0 <_ZN8mtlabar324ActiveWordColorInterface8getColorEv@plt>:
   a24c0:      	adrp	x16, 0xab000
   a24c4:      	ldr	x17, [x16, #0x1a8]
   a24c8:      	add	x16, x16, #0x1a8
   a24cc:      	br	x17

00000000000a24d0 <_ZN8mtlabar324ActiveWordColorInterface8setColorERKNS_6ColorAE@plt>:
   a24d0:      	adrp	x16, 0xab000
   a24d4:      	ldr	x17, [x16, #0x1b0]
   a24d8:      	add	x16, x16, #0x1b0
   a24dc:      	br	x17

00000000000a24e0 <_ZN8mtlabar324ActiveWordStyleInterface6createEv@plt>:
   a24e0:      	adrp	x16, 0xab000
   a24e4:      	ldr	x17, [x16, #0x1b8]
   a24e8:      	add	x16, x16, #0x1b8
   a24ec:      	br	x17

00000000000a24f0 <_ZN8mtlabar324ActiveWordStyleInterface7destroyEPS0_@plt>:
   a24f0:      	adrp	x16, 0xab000
   a24f4:      	ldr	x17, [x16, #0x1c0]
   a24f8:      	add	x16, x16, #0x1c0
   a24fc:      	br	x17

00000000000a2500 <_ZN8mtlabar324ActiveWordStyleInterface8deepCopyEPKS0_@plt>:
   a2500:      	adrp	x16, 0xab000
   a2504:      	ldr	x17, [x16, #0x1c8]
   a2508:      	add	x16, x16, #0x1c8
   a250c:      	br	x17

00000000000a2510 <_ZN8mtlabar324ActiveWordStyleInterface9setEnableEb@plt>:
   a2510:      	adrp	x16, 0xab000
   a2514:      	ldr	x17, [x16, #0x1d0]
   a2518:      	add	x16, x16, #0x1d0
   a251c:      	br	x17

00000000000a2520 <_ZNK8mtlabar324ActiveWordStyleInterface9getEnableEv@plt>:
   a2520:      	adrp	x16, 0xab000
   a2524:      	ldr	x17, [x16, #0x1d8]
   a2528:      	add	x16, x16, #0x1d8
   a252c:      	br	x17

00000000000a2530 <_ZN8mtlabar324ActiveWordStyleInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2530:      	adrp	x16, 0xab000
   a2534:      	ldr	x17, [x16, #0x1e0]
   a2538:      	add	x16, x16, #0x1e0
   a253c:      	br	x17

00000000000a2540 <_ZNK8mtlabar324ActiveWordStyleInterface13getConfigPathEv@plt>:
   a2540:      	adrp	x16, 0xab000
   a2544:      	ldr	x17, [x16, #0x1e8]
   a2548:      	add	x16, x16, #0x1e8
   a254c:      	br	x17

00000000000a2550 <_ZN8mtlabar324ActiveWordStyleInterface14setFontLibraryERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2550:      	adrp	x16, 0xab000
   a2554:      	ldr	x17, [x16, #0x1f0]
   a2558:      	add	x16, x16, #0x1f0
   a255c:      	br	x17

00000000000a2560 <_ZNK8mtlabar324ActiveWordStyleInterface14getFontLibraryEv@plt>:
   a2560:      	adrp	x16, 0xab000
   a2564:      	ldr	x17, [x16, #0x1f8]
   a2568:      	add	x16, x16, #0x1f8
   a256c:      	br	x17

00000000000a2570 <_ZN8mtlabar323CharBackgroundInterface6createEv@plt>:
   a2570:      	adrp	x16, 0xab000
   a2574:      	ldr	x17, [x16, #0x200]
   a2578:      	add	x16, x16, #0x200
   a257c:      	br	x17

00000000000a2580 <_ZN8mtlabar323CharBackgroundInterface7destroyEPS0_@plt>:
   a2580:      	adrp	x16, 0xab000
   a2584:      	ldr	x17, [x16, #0x208]
   a2588:      	add	x16, x16, #0x208
   a258c:      	br	x17

00000000000a2590 <_ZN8mtlabar323CharBackgroundInterface8deepCopyEPKS0_@plt>:
   a2590:      	adrp	x16, 0xab000
   a2594:      	ldr	x17, [x16, #0x210]
   a2598:      	add	x16, x16, #0x210
   a259c:      	br	x17

00000000000a25a0 <_ZN8mtlabar323CharBackgroundInterface9setEnableEb@plt>:
   a25a0:      	adrp	x16, 0xab000
   a25a4:      	ldr	x17, [x16, #0x218]
   a25a8:      	add	x16, x16, #0x218
   a25ac:      	br	x17

00000000000a25b0 <_ZNK8mtlabar323CharBackgroundInterface9getEnableEv@plt>:
   a25b0:      	adrp	x16, 0xab000
   a25b4:      	ldr	x17, [x16, #0x220]
   a25b8:      	add	x16, x16, #0x220
   a25bc:      	br	x17

00000000000a25c0 <_ZN8mtlabar323CharBackgroundInterface11setEditableEb@plt>:
   a25c0:      	adrp	x16, 0xab000
   a25c4:      	ldr	x17, [x16, #0x228]
   a25c8:      	add	x16, x16, #0x228
   a25cc:      	br	x17

00000000000a25d0 <_ZNK8mtlabar323CharBackgroundInterface11getEditableEv@plt>:
   a25d0:      	adrp	x16, 0xab000
   a25d4:      	ldr	x17, [x16, #0x230]
   a25d8:      	add	x16, x16, #0x230
   a25dc:      	br	x17

00000000000a25e0 <_ZN8mtlabar323CharBackgroundInterface7setSizeEf@plt>:
   a25e0:      	adrp	x16, 0xab000
   a25e4:      	ldr	x17, [x16, #0x238]
   a25e8:      	add	x16, x16, #0x238
   a25ec:      	br	x17

00000000000a25f0 <_ZNK8mtlabar323CharBackgroundInterface7getSizeEv@plt>:
   a25f0:      	adrp	x16, 0xab000
   a25f4:      	ldr	x17, [x16, #0x240]
   a25f8:      	add	x16, x16, #0x240
   a25fc:      	br	x17

00000000000a2600 <_ZN8mtlabar323CharBackgroundInterface9setOffsetERKNS_6Float2E@plt>:
   a2600:      	adrp	x16, 0xab000
   a2604:      	ldr	x17, [x16, #0x248]
   a2608:      	add	x16, x16, #0x248
   a260c:      	br	x17

00000000000a2610 <_ZNK8mtlabar323CharBackgroundInterface9getOffsetEv@plt>:
   a2610:      	adrp	x16, 0xab000
   a2614:      	ldr	x17, [x16, #0x250]
   a2618:      	add	x16, x16, #0x250
   a261c:      	br	x17

00000000000a2620 <_ZN8mtlabar323CharBackgroundInterface8setScaleERKNS_6Float2E@plt>:
   a2620:      	adrp	x16, 0xab000
   a2624:      	ldr	x17, [x16, #0x258]
   a2628:      	add	x16, x16, #0x258
   a262c:      	br	x17

00000000000a2630 <_ZNK8mtlabar323CharBackgroundInterface8getScaleEv@plt>:
   a2630:      	adrp	x16, 0xab000
   a2634:      	ldr	x17, [x16, #0x260]
   a2638:      	add	x16, x16, #0x260
   a263c:      	br	x17

00000000000a2640 <_ZN8mtlabar323CharBackgroundInterface25setTextureOverlayGlyphNumEi@plt>:
   a2640:      	adrp	x16, 0xab000
   a2644:      	ldr	x17, [x16, #0x268]
   a2648:      	add	x16, x16, #0x268
   a264c:      	br	x17

00000000000a2650 <_ZNK8mtlabar323CharBackgroundInterface25getTextureOverlayGlyphNumEv@plt>:
   a2650:      	adrp	x16, 0xab000
   a2654:      	ldr	x17, [x16, #0x270]
   a2658:      	add	x16, x16, #0x270
   a265c:      	br	x17

00000000000a2660 <_ZN8mtlabar323CharBackgroundInterface23setEnableGlyphTransformEb@plt>:
   a2660:      	adrp	x16, 0xab000
   a2664:      	ldr	x17, [x16, #0x278]
   a2668:      	add	x16, x16, #0x278
   a266c:      	br	x17

00000000000a2670 <_ZNK8mtlabar323CharBackgroundInterface23getEnableGlyphTransformEv@plt>:
   a2670:      	adrp	x16, 0xab000
   a2674:      	ldr	x17, [x16, #0x280]
   a2678:      	add	x16, x16, #0x280
   a267c:      	br	x17

00000000000a2680 <_ZN8mtlabar323CharBackgroundInterface21setCharBackgroundPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2680:      	adrp	x16, 0xab000
   a2684:      	ldr	x17, [x16, #0x288]
   a2688:      	add	x16, x16, #0x288
   a268c:      	br	x17

00000000000a2690 <_ZNK8mtlabar323CharBackgroundInterface21getCharBackgroundPathEv@plt>:
   a2690:      	adrp	x16, 0xab000
   a2694:      	ldr	x17, [x16, #0x290]
   a2698:      	add	x16, x16, #0x290
   a269c:      	br	x17

00000000000a26a0 <_ZN8mtlabar325LineLayoutConfigInterface6createEv@plt>:
   a26a0:      	adrp	x16, 0xab000
   a26a4:      	ldr	x17, [x16, #0x298]
   a26a8:      	add	x16, x16, #0x298
   a26ac:      	br	x17

00000000000a26b0 <_ZN8mtlabar325LineLayoutConfigInterface7destroyEPS0_@plt>:
   a26b0:      	adrp	x16, 0xab000
   a26b4:      	ldr	x17, [x16, #0x2a0]
   a26b8:      	add	x16, x16, #0x2a0
   a26bc:      	br	x17

00000000000a26c0 <_ZN8mtlabar325LineLayoutConfigInterface8deepCopyEPKS0_@plt>:
   a26c0:      	adrp	x16, 0xab000
   a26c4:      	ldr	x17, [x16, #0x2a8]
   a26c8:      	add	x16, x16, #0x2a8
   a26cc:      	br	x17

00000000000a26d0 <_ZNK8mtlabar325LineLayoutConfigInterface14getTransOriginEv@plt>:
   a26d0:      	adrp	x16, 0xab000
   a26d4:      	ldr	x17, [x16, #0x2b0]
   a26d8:      	add	x16, x16, #0x2b0
   a26dc:      	br	x17

00000000000a26e0 <_ZNK8mtlabar325LineLayoutConfigInterface18getTransxHeightRefEv@plt>:
   a26e0:      	adrp	x16, 0xab000
   a26e4:      	ldr	x17, [x16, #0x2b8]
   a26e8:      	add	x16, x16, #0x2b8
   a26ec:      	br	x17

00000000000a26f0 <_ZNK8mtlabar325LineLayoutConfigInterface21getTransxHeightCornerEv@plt>:
   a26f0:      	adrp	x16, 0xab000
   a26f4:      	ldr	x17, [x16, #0x2c0]
   a26f8:      	add	x16, x16, #0x2c0
   a26fc:      	br	x17

00000000000a2700 <_ZNK8mtlabar325LineLayoutConfigInterface16getTransWidthRefEv@plt>:
   a2700:      	adrp	x16, 0xab000
   a2704:      	ldr	x17, [x16, #0x2c8]
   a2708:      	add	x16, x16, #0x2c8
   a270c:      	br	x17

00000000000a2710 <_ZN8mtlabar323SubTextLayerInteraction11getTextEnumEv@plt>:
   a2710:      	adrp	x16, 0xab000
   a2714:      	ldr	x17, [x16, #0x2d0]
   a2718:      	add	x16, x16, #0x2d0
   a271c:      	br	x17

00000000000a2720 <_ZN8mtlabar323SubTextLayerInteraction12getInputFlagEv@plt>:
   a2720:      	adrp	x16, 0xab000
   a2724:      	ldr	x17, [x16, #0x2d8]
   a2728:      	add	x16, x16, #0x2d8
   a272c:      	br	x17

00000000000a2730 <_ZN8mtlabar323SubTextLayerInteraction11getTextRectEv@plt>:
   a2730:      	adrp	x16, 0xab000
   a2734:      	ldr	x17, [x16, #0x2e0]
   a2738:      	add	x16, x16, #0x2e0
   a273c:      	br	x17

00000000000a2740 <_ZN8mtlabar323SubTextLayerInteraction7getTextEv@plt>:
   a2740:      	adrp	x16, 0xab000
   a2744:      	ldr	x17, [x16, #0x2e8]
   a2748:      	add	x16, x16, #0x2e8
   a274c:      	br	x17

00000000000a2750 <_ZN8mtlabar323SubTextLayerInteraction7setTextERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2750:      	adrp	x16, 0xab000
   a2754:      	ldr	x17, [x16, #0x2f0]
   a2758:      	add	x16, x16, #0x2f0
   a275c:      	br	x17

00000000000a2760 <_ZNK8mtlabar323SubTextLayerInteraction11getMissTextEv@plt>:
   a2760:      	adrp	x16, 0xab000
   a2764:      	ldr	x17, [x16, #0x2f8]
   a2768:      	add	x16, x16, #0x2f8
   a276c:      	br	x17

00000000000a2770 <_ZN8mtlabar323SubTextLayerInteraction11setMissTextERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a2770:      	adrp	x16, 0xab000
   a2774:      	ldr	x17, [x16, #0x300]
   a2778:      	add	x16, x16, #0x300
   a277c:      	br	x17

00000000000a2780 <_ZN8mtlabar323SubTextLayerInteraction14getFontLibraryEv@plt>:
   a2780:      	adrp	x16, 0xab000
   a2784:      	ldr	x17, [x16, #0x308]
   a2788:      	add	x16, x16, #0x308
   a278c:      	br	x17

00000000000a2790 <_ZN8mtlabar323SubTextLayerInteraction14setFontLibraryEPKc@plt>:
   a2790:      	adrp	x16, 0xab000
   a2794:      	ldr	x17, [x16, #0x310]
   a2798:      	add	x16, x16, #0x310
   a279c:      	br	x17

00000000000a27a0 <_ZN8mtlabar323SubTextLayerInteraction24getFallbackFontLibrariesEv@plt>:
   a27a0:      	adrp	x16, 0xab000
   a27a4:      	ldr	x17, [x16, #0x318]
   a27a8:      	add	x16, x16, #0x318
   a27ac:      	br	x17

00000000000a27b0 <_ZN8mtlabar323SubTextLayerInteraction24setFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a27b0:      	adrp	x16, 0xab000
   a27b4:      	ldr	x17, [x16, #0x320]
   a27b8:      	add	x16, x16, #0x320
   a27bc:      	br	x17

00000000000a27c0 <_ZN8mtlabar323SubTextLayerInteraction11getFontSizeEv@plt>:
   a27c0:      	adrp	x16, 0xab000
   a27c4:      	ldr	x17, [x16, #0x328]
   a27c8:      	add	x16, x16, #0x328
   a27cc:      	br	x17

00000000000a27d0 <_ZN8mtlabar323SubTextLayerInteraction11setFontSizeEf@plt>:
   a27d0:      	adrp	x16, 0xab000
   a27d4:      	ldr	x17, [x16, #0x330]
   a27d8:      	add	x16, x16, #0x330
   a27dc:      	br	x17

00000000000a27e0 <_ZN8mtlabar323SubTextLayerInteraction23getActualRenderFontSizeEv@plt>:
   a27e0:      	adrp	x16, 0xab000
   a27e4:      	ldr	x17, [x16, #0x338]
   a27e8:      	add	x16, x16, #0x338
   a27ec:      	br	x17

00000000000a27f0 <_ZN8mtlabar323SubTextLayerInteraction10getOpacityEv@plt>:
   a27f0:      	adrp	x16, 0xab000
   a27f4:      	ldr	x17, [x16, #0x340]
   a27f8:      	add	x16, x16, #0x340
   a27fc:      	br	x17

00000000000a2800 <_ZN8mtlabar323SubTextLayerInteraction10setOpacityEf@plt>:
   a2800:      	adrp	x16, 0xab000
   a2804:      	ldr	x17, [x16, #0x348]
   a2808:      	add	x16, x16, #0x348
   a280c:      	br	x17

00000000000a2810 <_ZN8mtlabar323SubTextLayerInteraction9getColorAEv@plt>:
   a2810:      	adrp	x16, 0xab000
   a2814:      	ldr	x17, [x16, #0x350]
   a2818:      	add	x16, x16, #0x350
   a281c:      	br	x17

00000000000a2820 <_ZN8mtlabar323SubTextLayerInteraction9setColorAERKNS_6ColorAE@plt>:
   a2820:      	adrp	x16, 0xab000
   a2824:      	ldr	x17, [x16, #0x358]
   a2828:      	add	x16, x16, #0x358
   a282c:      	br	x17

00000000000a2830 <_ZN8mtlabar323SubTextLayerInteraction19getIsColorORGBAWorkEv@plt>:
   a2830:      	adrp	x16, 0xab000
   a2834:      	ldr	x17, [x16, #0x360]
   a2838:      	add	x16, x16, #0x360
   a283c:      	br	x17

00000000000a2840 <_ZN8mtlabar323SubTextLayerInteraction19setIsColorORGBAWorkEb@plt>:
   a2840:      	adrp	x16, 0xab000
   a2844:      	ldr	x17, [x16, #0x368]
   a2848:      	add	x16, x16, #0x368
   a284c:      	br	x17

00000000000a2850 <_ZN8mtlabar323SubTextLayerInteraction15getIsStaticShowEv@plt>:
   a2850:      	adrp	x16, 0xab000
   a2854:      	ldr	x17, [x16, #0x370]
   a2858:      	add	x16, x16, #0x370
   a285c:      	br	x17

00000000000a2860 <_ZN8mtlabar323SubTextLayerInteraction15setIsStaticShowEb@plt>:
   a2860:      	adrp	x16, 0xab000
   a2864:      	ldr	x17, [x16, #0x378]
   a2868:      	add	x16, x16, #0x378
   a286c:      	br	x17

00000000000a2870 <_ZN8mtlabar323SubTextLayerInteraction17getIsMultiStrokesEv@plt>:
   a2870:      	adrp	x16, 0xab000
   a2874:      	ldr	x17, [x16, #0x380]
   a2878:      	add	x16, x16, #0x380
   a287c:      	br	x17

00000000000a2880 <_ZN8mtlabar323SubTextLayerInteraction17setIsMultiStrokesEb@plt>:
   a2880:      	adrp	x16, 0xab000
   a2884:      	ldr	x17, [x16, #0x388]
   a2888:      	add	x16, x16, #0x388
   a288c:      	br	x17

00000000000a2890 <_ZN8mtlabar323SubTextLayerInteraction9getIsBoldEv@plt>:
   a2890:      	adrp	x16, 0xab000
   a2894:      	ldr	x17, [x16, #0x390]
   a2898:      	add	x16, x16, #0x390
   a289c:      	br	x17

00000000000a28a0 <_ZN8mtlabar323SubTextLayerInteraction9setIsBoldEb@plt>:
   a28a0:      	adrp	x16, 0xab000
   a28a4:      	ldr	x17, [x16, #0x398]
   a28a8:      	add	x16, x16, #0x398
   a28ac:      	br	x17

00000000000a28b0 <_ZN8mtlabar323SubTextLayerInteraction11getIsItalicEv@plt>:
   a28b0:      	adrp	x16, 0xab000
   a28b4:      	ldr	x17, [x16, #0x3a0]
   a28b8:      	add	x16, x16, #0x3a0
   a28bc:      	br	x17

00000000000a28c0 <_ZN8mtlabar323SubTextLayerInteraction11setIsItalicEb@plt>:
   a28c0:      	adrp	x16, 0xab000
   a28c4:      	ldr	x17, [x16, #0x3a8]
   a28c8:      	add	x16, x16, #0x3a8
   a28cc:      	br	x17

00000000000a28d0 <_ZN8mtlabar323SubTextLayerInteraction14getIsUnderlineEv@plt>:
   a28d0:      	adrp	x16, 0xab000
   a28d4:      	ldr	x17, [x16, #0x3b0]
   a28d8:      	add	x16, x16, #0x3b0
   a28dc:      	br	x17

00000000000a28e0 <_ZN8mtlabar323SubTextLayerInteraction14setIsUnderlineEb@plt>:
   a28e0:      	adrp	x16, 0xab000
   a28e4:      	ldr	x17, [x16, #0x3b8]
   a28e8:      	add	x16, x16, #0x3b8
   a28ec:      	br	x17

00000000000a28f0 <_ZN8mtlabar323SubTextLayerInteraction18getIsStrikeThroughEv@plt>:
   a28f0:      	adrp	x16, 0xab000
   a28f4:      	ldr	x17, [x16, #0x3c0]
   a28f8:      	add	x16, x16, #0x3c0
   a28fc:      	br	x17

00000000000a2900 <_ZN8mtlabar323SubTextLayerInteraction18setIsStrikeThroughEb@plt>:
   a2900:      	adrp	x16, 0xab000
   a2904:      	ldr	x17, [x16, #0x3c8]
   a2908:      	add	x16, x16, #0x3c8
   a290c:      	br	x17

00000000000a2910 <_ZN8mtlabar323SubTextLayerInteraction10getJustifyEv@plt>:
   a2910:      	adrp	x16, 0xab000
   a2914:      	ldr	x17, [x16, #0x3d0]
   a2918:      	add	x16, x16, #0x3d0
   a291c:      	br	x17

00000000000a2920 <_ZN8mtlabar323SubTextLayerInteraction10setJustifyENS_4text11TextJustifyE@plt>:
   a2920:      	adrp	x16, 0xab000
   a2924:      	ldr	x17, [x16, #0x3d8]
   a2928:      	add	x16, x16, #0x3d8
   a292c:      	br	x17

00000000000a2930 <_ZN8mtlabar323SubTextLayerInteraction13getHorizontalEv@plt>:
   a2930:      	adrp	x16, 0xab000
   a2934:      	ldr	x17, [x16, #0x3e0]
   a2938:      	add	x16, x16, #0x3e0
   a293c:      	br	x17

00000000000a2940 <_ZN8mtlabar323SubTextLayerInteraction13setHorizontalEb@plt>:
   a2940:      	adrp	x16, 0xab000
   a2944:      	ldr	x17, [x16, #0x3e8]
   a2948:      	add	x16, x16, #0x3e8
   a294c:      	br	x17

00000000000a2950 <_ZN8mtlabar323SubTextLayerInteraction14getLeftToRightEv@plt>:
   a2950:      	adrp	x16, 0xab000
   a2954:      	ldr	x17, [x16, #0x3f0]
   a2958:      	add	x16, x16, #0x3f0
   a295c:      	br	x17

00000000000a2960 <_ZN8mtlabar323SubTextLayerInteraction14setLeftToRightEb@plt>:
   a2960:      	adrp	x16, 0xab000
   a2964:      	ldr	x17, [x16, #0x3f8]
   a2968:      	add	x16, x16, #0x3f8
   a296c:      	br	x17

00000000000a2970 <_ZN8mtlabar323SubTextLayerInteraction7getWrapEv@plt>:
   a2970:      	adrp	x16, 0xab000
   a2974:      	ldr	x17, [x16, #0x400]
   a2978:      	add	x16, x16, #0x400
   a297c:      	br	x17

00000000000a2980 <_ZN8mtlabar323SubTextLayerInteraction7setWrapEb@plt>:
   a2980:      	adrp	x16, 0xab000
   a2984:      	ldr	x17, [x16, #0x408]
   a2988:      	add	x16, x16, #0x408
   a298c:      	br	x17

00000000000a2990 <_ZN8mtlabar323SubTextLayerInteraction9getShrinkEv@plt>:
   a2990:      	adrp	x16, 0xab000
   a2994:      	ldr	x17, [x16, #0x410]
   a2998:      	add	x16, x16, #0x410
   a299c:      	br	x17

00000000000a29a0 <_ZN8mtlabar323SubTextLayerInteraction9setShrinkEb@plt>:
   a29a0:      	adrp	x16, 0xab000
   a29a4:      	ldr	x17, [x16, #0x418]
   a29a8:      	add	x16, x16, #0x418
   a29ac:      	br	x17

00000000000a29b0 <_ZN8mtlabar323SubTextLayerInteraction10getSpacingEv@plt>:
   a29b0:      	adrp	x16, 0xab000
   a29b4:      	ldr	x17, [x16, #0x420]
   a29b8:      	add	x16, x16, #0x420
   a29bc:      	br	x17

00000000000a29c0 <_ZN8mtlabar323SubTextLayerInteraction10setSpacingEf@plt>:
   a29c0:      	adrp	x16, 0xab000
   a29c4:      	ldr	x17, [x16, #0x428]
   a29c8:      	add	x16, x16, #0x428
   a29cc:      	br	x17

00000000000a29d0 <_ZN8mtlabar323SubTextLayerInteraction14getLineSpacingEv@plt>:
   a29d0:      	adrp	x16, 0xab000
   a29d4:      	ldr	x17, [x16, #0x430]
   a29d8:      	add	x16, x16, #0x430
   a29dc:      	br	x17

00000000000a29e0 <_ZN8mtlabar323SubTextLayerInteraction14setLineSpacingEf@plt>:
   a29e0:      	adrp	x16, 0xab000
   a29e4:      	ldr	x17, [x16, #0x438]
   a29e8:      	add	x16, x16, #0x438
   a29ec:      	br	x17

00000000000a29f0 <_ZN8mtlabar323SubTextLayerInteraction18getHardLineSpacingEv@plt>:
   a29f0:      	adrp	x16, 0xab000
   a29f4:      	ldr	x17, [x16, #0x440]
   a29f8:      	add	x16, x16, #0x440
   a29fc:      	br	x17

00000000000a2a00 <_ZN8mtlabar323SubTextLayerInteraction18setHardLineSpacingEf@plt>:
   a2a00:      	adrp	x16, 0xab000
   a2a04:      	ldr	x17, [x16, #0x448]
   a2a08:      	add	x16, x16, #0x448
   a2a0c:      	br	x17

00000000000a2a10 <_ZN8mtlabar323SubTextLayerInteraction13getTextLayoutEv@plt>:
   a2a10:      	adrp	x16, 0xab000
   a2a14:      	ldr	x17, [x16, #0x450]
   a2a18:      	add	x16, x16, #0x450
   a2a1c:      	br	x17

00000000000a2a20 <_ZN8mtlabar323SubTextLayerInteraction13setTextLayoutENS_4text14TextLayoutEnumE@plt>:
   a2a20:      	adrp	x16, 0xab000
   a2a24:      	ldr	x17, [x16, #0x458]
   a2a28:      	add	x16, x16, #0x458
   a2a2c:      	br	x17

00000000000a2a30 <_ZN8mtlabar323SubTextLayerInteraction9getPinyinEv@plt>:
   a2a30:      	adrp	x16, 0xab000
   a2a34:      	ldr	x17, [x16, #0x460]
   a2a38:      	add	x16, x16, #0x460
   a2a3c:      	br	x17

00000000000a2a40 <_ZN8mtlabar323SubTextLayerInteraction9setPinyinEb@plt>:
   a2a40:      	adrp	x16, 0xab000
   a2a44:      	ldr	x17, [x16, #0x468]
   a2a48:      	add	x16, x16, #0x468
   a2a4c:      	br	x17

00000000000a2a50 <_ZN8mtlabar323SubTextLayerInteraction12getCustomTagEv@plt>:
   a2a50:      	adrp	x16, 0xab000
   a2a54:      	ldr	x17, [x16, #0x470]
   a2a58:      	add	x16, x16, #0x470
   a2a5c:      	br	x17

00000000000a2a60 <_ZN8mtlabar323SubTextLayerInteraction12flipTextRectEv@plt>:
   a2a60:      	adrp	x16, 0xab000
   a2a64:      	ldr	x17, [x16, #0x478]
   a2a68:      	add	x16, x16, #0x478
   a2a6c:      	br	x17

00000000000a2a70 <_ZN8mtlabar323SubTextLayerInteraction14getEditingTypeEv@plt>:
   a2a70:      	adrp	x16, 0xab000
   a2a74:      	ldr	x17, [x16, #0x480]
   a2a78:      	add	x16, x16, #0x480
   a2a7c:      	br	x17

00000000000a2a80 <_ZN8mtlabar323SubTextLayerInteraction14setEditingTypeENS_4text11EditingTypeE@plt>:
   a2a80:      	adrp	x16, 0xab000
   a2a84:      	ldr	x17, [x16, #0x488]
   a2a88:      	add	x16, x16, #0x488
   a2a8c:      	br	x17

00000000000a2a90 <_ZN8mtlabar323SubTextLayerInteraction17getSubLayerVertexENS_15LayerVertexEnumE@plt>:
   a2a90:      	adrp	x16, 0xab000
   a2a94:      	ldr	x17, [x16, #0x490]
   a2a98:      	add	x16, x16, #0x490
   a2a9c:      	br	x17

00000000000a2aa0 <_ZN8mtlabar323SubTextLayerInteraction18getTextRectPaddingENS_13LayerEdgeEnumE@plt>:
   a2aa0:      	adrp	x16, 0xab000
   a2aa4:      	ldr	x17, [x16, #0x498]
   a2aa8:      	add	x16, x16, #0x498
   a2aac:      	br	x17

00000000000a2ab0 <_ZN8mtlabar323SubTextLayerInteraction16getSequenceStyleEv@plt>:
   a2ab0:      	adrp	x16, 0xab000
   a2ab4:      	ldr	x17, [x16, #0x4a0]
   a2ab8:      	add	x16, x16, #0x4a0
   a2abc:      	br	x17

00000000000a2ac0 <_ZN8mtlabar323SubTextLayerInteraction16setSequenceStyleEi@plt>:
   a2ac0:      	adrp	x16, 0xab000
   a2ac4:      	ldr	x17, [x16, #0x4a8]
   a2ac8:      	add	x16, x16, #0x4a8
   a2acc:      	br	x17

00000000000a2ad0 <_ZN8mtlabar323SubTextLayerInteraction12getIsVisibleEv@plt>:
   a2ad0:      	adrp	x16, 0xab000
   a2ad4:      	ldr	x17, [x16, #0x4b0]
   a2ad8:      	add	x16, x16, #0x4b0
   a2adc:      	br	x17

00000000000a2ae0 <_ZN8mtlabar323SubTextLayerInteraction12setIsVisibleEb@plt>:
   a2ae0:      	adrp	x16, 0xab000
   a2ae4:      	ldr	x17, [x16, #0x4b8]
   a2ae8:      	add	x16, x16, #0x4b8
   a2aec:      	br	x17

00000000000a2af0 <_ZN8mtlabar323SubTextLayerInteraction12getIsDisplayEv@plt>:
   a2af0:      	adrp	x16, 0xab000
   a2af4:      	ldr	x17, [x16, #0x4c0]
   a2af8:      	add	x16, x16, #0x4c0
   a2afc:      	br	x17

00000000000a2b00 <_ZN8mtlabar323SubTextLayerInteraction21setTextPathConfigPathEPKc@plt>:
   a2b00:      	adrp	x16, 0xab000
   a2b04:      	ldr	x17, [x16, #0x4c8]
   a2b08:      	add	x16, x16, #0x4c8
   a2b0c:      	br	x17

00000000000a2b10 <_ZN8mtlabar323SubTextLayerInteraction21getTextPathConfigPathEv@plt>:
   a2b10:      	adrp	x16, 0xab000
   a2b14:      	ldr	x17, [x16, #0x4d0]
   a2b18:      	add	x16, x16, #0x4d0
   a2b1c:      	br	x17

00000000000a2b20 <_ZN8mtlabar323SubTextLayerInteraction18getLayerConfigPathEv@plt>:
   a2b20:      	adrp	x16, 0xab000
   a2b24:      	ldr	x17, [x16, #0x4d8]
   a2b28:      	add	x16, x16, #0x4d8
   a2b2c:      	br	x17

00000000000a2b30 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   a2b30:      	adrp	x16, 0xab000
   a2b34:      	ldr	x17, [x16, #0x4e0]
   a2b38:      	add	x16, x16, #0x4e0
   a2b3c:      	br	x17

00000000000a2b40 <_ZN8mtlabar323SubTextLayerInteraction18setLayerConfigPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2b40:      	adrp	x16, 0xab000
   a2b44:      	ldr	x17, [x16, #0x4e8]
   a2b48:      	add	x16, x16, #0x4e8
   a2b4c:      	br	x17

00000000000a2b50 <_ZN8mtlabar323SubTextLayerInteraction16getContainBgOrFgEv@plt>:
   a2b50:      	adrp	x16, 0xab000
   a2b54:      	ldr	x17, [x16, #0x4f0]
   a2b58:      	add	x16, x16, #0x4f0
   a2b5c:      	br	x17

00000000000a2b60 <_ZN8mtlabar323SubTextLayerInteraction14getContainMaskEv@plt>:
   a2b60:      	adrp	x16, 0xab000
   a2b64:      	ldr	x17, [x16, #0x4f8]
   a2b68:      	add	x16, x16, #0x4f8
   a2b6c:      	br	x17

00000000000a2b70 <_ZN8mtlabar323SubTextLayerInteraction24getTextImageLocateMethodEv@plt>:
   a2b70:      	adrp	x16, 0xab000
   a2b74:      	ldr	x17, [x16, #0x500]
   a2b78:      	add	x16, x16, #0x500
   a2b7c:      	br	x17

00000000000a2b80 <_ZN8mtlabar323SubTextLayerInteraction24setTextImageLocateMethodENS_4text21TextImageLocateMethodE@plt>:
   a2b80:      	adrp	x16, 0xab000
   a2b84:      	ldr	x17, [x16, #0x508]
   a2b88:      	add	x16, x16, #0x508
   a2b8c:      	br	x17

00000000000a2b90 <_ZN8mtlabar323SubTextLayerInteraction22getStrokeConfigurationEv@plt>:
   a2b90:      	adrp	x16, 0xab000
   a2b94:      	ldr	x17, [x16, #0x510]
   a2b98:      	add	x16, x16, #0x510
   a2b9c:      	br	x17

00000000000a2ba0 <_ZN8mtlabar323SubTextLayerInteraction21getMultiStrokeAtIndexEi@plt>:
   a2ba0:      	adrp	x16, 0xab000
   a2ba4:      	ldr	x17, [x16, #0x518]
   a2ba8:      	add	x16, x16, #0x518
   a2bac:      	br	x17

00000000000a2bb0 <_ZN8mtlabar323SubTextLayerInteraction18getMultiStrokeSizeEv@plt>:
   a2bb0:      	adrp	x16, 0xab000
   a2bb4:      	ldr	x17, [x16, #0x520]
   a2bb8:      	add	x16, x16, #0x520
   a2bbc:      	br	x17

00000000000a2bc0 <_ZN8mtlabar323SubTextLayerInteraction17resizeMultiStrokeEi@plt>:
   a2bc0:      	adrp	x16, 0xab000
   a2bc4:      	ldr	x17, [x16, #0x528]
   a2bc8:      	add	x16, x16, #0x528
   a2bcc:      	br	x17

00000000000a2bd0 <_ZN8mtlabar323SubTextLayerInteraction22getShadowConfigurationEv@plt>:
   a2bd0:      	adrp	x16, 0xab000
   a2bd4:      	ldr	x17, [x16, #0x530]
   a2bd8:      	add	x16, x16, #0x530
   a2bdc:      	br	x17

00000000000a2be0 <_ZN8mtlabar323SubTextLayerInteraction31getBackgroundColorConfigurationEv@plt>:
   a2be0:      	adrp	x16, 0xab000
   a2be4:      	ldr	x17, [x16, #0x538]
   a2be8:      	add	x16, x16, #0x538
   a2bec:      	br	x17

00000000000a2bf0 <_ZN8mtlabar323SubTextLayerInteraction20getGlowConfigurationEv@plt>:
   a2bf0:      	adrp	x16, 0xab000
   a2bf4:      	ldr	x17, [x16, #0x540]
   a2bf8:      	add	x16, x16, #0x540
   a2bfc:      	br	x17

00000000000a2c00 <_ZN8mtlabar323SubTextLayerInteraction22getBubbleConfigurationEv@plt>:
   a2c00:      	adrp	x16, 0xab000
   a2c04:      	ldr	x17, [x16, #0x548]
   a2c08:      	add	x16, x16, #0x548
   a2c0c:      	br	x17

00000000000a2c10 <_ZN8mtlabar323SubTextLayerInteraction20getCharSVGBackgroundEv@plt>:
   a2c10:      	adrp	x16, 0xab000
   a2c14:      	ldr	x17, [x16, #0x550]
   a2c18:      	add	x16, x16, #0x550
   a2c1c:      	br	x17

00000000000a2c20 <_ZN8mtlabar323SubTextLayerInteraction28getTextEditableConfigurationEv@plt>:
   a2c20:      	adrp	x16, 0xab000
   a2c24:      	ldr	x17, [x16, #0x558]
   a2c28:      	add	x16, x16, #0x558
   a2c2c:      	br	x17

00000000000a2c30 <_ZN8mtlabar323SubTextLayerInteraction28getTextGradientConfigurationEv@plt>:
   a2c30:      	adrp	x16, 0xab000
   a2c34:      	ldr	x17, [x16, #0x560]
   a2c38:      	add	x16, x16, #0x560
   a2c3c:      	br	x17

00000000000a2c40 <_ZN8mtlabar323SubTextLayerInteraction29getIconSequenceStyleInterfaceEv@plt>:
   a2c40:      	adrp	x16, 0xab000
   a2c44:      	ldr	x17, [x16, #0x568]
   a2c48:      	add	x16, x16, #0x568
   a2c4c:      	br	x17

00000000000a2c50 <_ZN8mtlabar323SubTextLayerInteraction24getTextPathConfigurationEv@plt>:
   a2c50:      	adrp	x16, 0xab000
   a2c54:      	ldr	x17, [x16, #0x570]
   a2c58:      	add	x16, x16, #0x570
   a2c5c:      	br	x17

00000000000a2c60 <_ZN8mtlabar323SubTextLayerInteraction30getSelectionHighlightInterfaceEm@plt>:
   a2c60:      	adrp	x16, 0xab000
   a2c64:      	ldr	x17, [x16, #0x578]
   a2c68:      	add	x16, x16, #0x578
   a2c6c:      	br	x17

00000000000a2c70 <_ZN8mtlabar323SubTextLayerInteraction25getSelectionHighlightSizeEv@plt>:
   a2c70:      	adrp	x16, 0xab000
   a2c74:      	ldr	x17, [x16, #0x580]
   a2c78:      	add	x16, x16, #0x580
   a2c7c:      	br	x17

00000000000a2c80 <_ZN8mtlabar323SubTextLayerInteraction25resizeSelectionHighlightsEm@plt>:
   a2c80:      	adrp	x16, 0xab000
   a2c84:      	ldr	x17, [x16, #0x588]
   a2c88:      	add	x16, x16, #0x588
   a2c8c:      	br	x17

00000000000a2c90 <_ZN8mtlabar323SubTextLayerInteraction30getSelectionAnimationInterfaceEm@plt>:
   a2c90:      	adrp	x16, 0xab000
   a2c94:      	ldr	x17, [x16, #0x590]
   a2c98:      	add	x16, x16, #0x590
   a2c9c:      	br	x17

00000000000a2ca0 <_ZN8mtlabar323SubTextLayerInteraction25getSelectionAnimationSizeEv@plt>:
   a2ca0:      	adrp	x16, 0xab000
   a2ca4:      	ldr	x17, [x16, #0x598]
   a2ca8:      	add	x16, x16, #0x598
   a2cac:      	br	x17

00000000000a2cb0 <_ZN8mtlabar323SubTextLayerInteraction25resizeSelectionAnimationsEm@plt>:
   a2cb0:      	adrp	x16, 0xab000
   a2cb4:      	ldr	x17, [x16, #0x5a0]
   a2cb8:      	add	x16, x16, #0x5a0
   a2cbc:      	br	x17

00000000000a2cc0 <_ZN8mtlabar323SubTextLayerInteraction25getSelectionNoteInterfaceEm@plt>:
   a2cc0:      	adrp	x16, 0xab000
   a2cc4:      	ldr	x17, [x16, #0x5a8]
   a2cc8:      	add	x16, x16, #0x5a8
   a2ccc:      	br	x17

00000000000a2cd0 <_ZN8mtlabar323SubTextLayerInteraction20getSelectionNoteSizeEv@plt>:
   a2cd0:      	adrp	x16, 0xab000
   a2cd4:      	ldr	x17, [x16, #0x5b0]
   a2cd8:      	add	x16, x16, #0x5b0
   a2cdc:      	br	x17

00000000000a2ce0 <_ZN8mtlabar323SubTextLayerInteraction20resizeSelectionNotesEm@plt>:
   a2ce0:      	adrp	x16, 0xab000
   a2ce4:      	ldr	x17, [x16, #0x5b8]
   a2ce8:      	add	x16, x16, #0x5b8
   a2cec:      	br	x17

00000000000a2cf0 <_ZN8mtlabar323SubTextLayerInteraction10getTextASREv@plt>:
   a2cf0:      	adrp	x16, 0xab000
   a2cf4:      	ldr	x17, [x16, #0x5c0]
   a2cf8:      	add	x16, x16, #0x5c0
   a2cfc:      	br	x17

00000000000a2d00 <_ZN8mtlabar323SubTextLayerInteraction22getWarpConfigInterfaceEv@plt>:
   a2d00:      	adrp	x16, 0xab000
   a2d04:      	ldr	x17, [x16, #0x5c8]
   a2d08:      	add	x16, x16, #0x5c8
   a2d0c:      	br	x17

00000000000a2d10 <_ZN8mtlabar323SubTextLayerInteraction26getCharBackgroundInterfaceEv@plt>:
   a2d10:      	adrp	x16, 0xab000
   a2d14:      	ldr	x17, [x16, #0x5d0]
   a2d18:      	add	x16, x16, #0x5d0
   a2d1c:      	br	x17

00000000000a2d20 <_ZN8mtlabar323SubTextLayerInteraction26getLineLayoutConfigAtIndexEm@plt>:
   a2d20:      	adrp	x16, 0xab000
   a2d24:      	ldr	x17, [x16, #0x5d8]
   a2d28:      	add	x16, x16, #0x5d8
   a2d2c:      	br	x17

00000000000a2d30 <_ZN8mtlabar323SubTextLayerInteraction24getLineLayoutConfigCountEv@plt>:
   a2d30:      	adrp	x16, 0xab000
   a2d34:      	ldr	x17, [x16, #0x5e0]
   a2d38:      	add	x16, x16, #0x5e0
   a2d3c:      	br	x17

00000000000a2d40 <_ZN8mtlabar320LayerTextInteraction19setGlobalColorValueERKNS_5ColorE@plt>:
   a2d40:      	adrp	x16, 0xab000
   a2d44:      	ldr	x17, [x16, #0x5e8]
   a2d48:      	add	x16, x16, #0x5e8
   a2d4c:      	br	x17

00000000000a2d50 <_ZN8mtlabar320LayerTextInteraction19getGlobalColorValueEv@plt>:
   a2d50:      	adrp	x16, 0xab000
   a2d54:      	ldr	x17, [x16, #0x5f0]
   a2d58:      	add	x16, x16, #0x5f0
   a2d5c:      	br	x17

00000000000a2d60 <_ZN8mtlabar320LayerTextInteraction20setEnableGlobalColorEb@plt>:
   a2d60:      	adrp	x16, 0xab000
   a2d64:      	ldr	x17, [x16, #0x5f8]
   a2d68:      	add	x16, x16, #0x5f8
   a2d6c:      	br	x17

00000000000a2d70 <_ZN8mtlabar320LayerTextInteraction20getEnableGlobalColorEv@plt>:
   a2d70:      	adrp	x16, 0xab000
   a2d74:      	ldr	x17, [x16, #0x600]
   a2d78:      	add	x16, x16, #0x600
   a2d7c:      	br	x17

00000000000a2d80 <_ZN8mtlabar320LayerTextInteraction18getTextInTimestampEv@plt>:
   a2d80:      	adrp	x16, 0xab000
   a2d84:      	ldr	x17, [x16, #0x608]
   a2d88:      	add	x16, x16, #0x608
   a2d8c:      	br	x17

00000000000a2d90 <_ZN8mtlabar320LayerTextInteraction13setEnableFlipEb@plt>:
   a2d90:      	adrp	x16, 0xab000
   a2d94:      	ldr	x17, [x16, #0x610]
   a2d98:      	add	x16, x16, #0x610
   a2d9c:      	br	x17

00000000000a2da0 <_ZN8mtlabar320LayerTextInteraction13getEnableFlipEv@plt>:
   a2da0:      	adrp	x16, 0xab000
   a2da4:      	ldr	x17, [x16, #0x618]
   a2da8:      	add	x16, x16, #0x618
   a2dac:      	br	x17

00000000000a2db0 <_ZN8mtlabar320LayerTextInteraction15getSubTextLayerEm@plt>:
   a2db0:      	adrp	x16, 0xab000
   a2db4:      	ldr	x17, [x16, #0x620]
   a2db8:      	add	x16, x16, #0x620
   a2dbc:      	br	x17

00000000000a2dc0 <_ZN8mtlabar320LayerTextInteraction19getSubTextLayerSizeEv@plt>:
   a2dc0:      	adrp	x16, 0xab000
   a2dc4:      	ldr	x17, [x16, #0x628]
   a2dc8:      	add	x16, x16, #0x628
   a2dcc:      	br	x17

00000000000a2dd0 <_ZN8mtlabar320LayerTextInteraction18getWatermarkConfigEv@plt>:
   a2dd0:      	adrp	x16, 0xab000
   a2dd4:      	ldr	x17, [x16, #0x630]
   a2dd8:      	add	x16, x16, #0x630
   a2ddc:      	br	x17

00000000000a2de0 <_ZN8mtlabar320LayerTextInteraction18setWatermarkConfigERKNS_15WatermarkConfigE@plt>:
   a2de0:      	adrp	x16, 0xab000
   a2de4:      	ldr	x17, [x16, #0x638]
   a2de8:      	add	x16, x16, #0x638
   a2dec:      	br	x17

00000000000a2df0 <_ZN8mtlabar320LayerTextInteraction13setEnableEditEb@plt>:
   a2df0:      	adrp	x16, 0xab000
   a2df4:      	ldr	x17, [x16, #0x640]
   a2df8:      	add	x16, x16, #0x640
   a2dfc:      	br	x17

00000000000a2e00 <_ZN8mtlabar320LayerTextInteraction13getEnableEditEv@plt>:
   a2e00:      	adrp	x16, 0xab000
   a2e04:      	ldr	x17, [x16, #0x648]
   a2e08:      	add	x16, x16, #0x648
   a2e0c:      	br	x17

00000000000a2e10 <_ZN8mtlabar320LayerTextInteraction16setEditableIndexEi@plt>:
   a2e10:      	adrp	x16, 0xab000
   a2e14:      	ldr	x17, [x16, #0x650]
   a2e18:      	add	x16, x16, #0x650
   a2e1c:      	br	x17

00000000000a2e20 <_ZN8mtlabar320LayerTextInteraction16getEditableIndexEv@plt>:
   a2e20:      	adrp	x16, 0xab000
   a2e24:      	ldr	x17, [x16, #0x658]
   a2e28:      	add	x16, x16, #0x658
   a2e2c:      	br	x17

00000000000a2e30 <_ZN8mtlabar320LayerTextInteraction25getTextInactiveTextConfigEv@plt>:
   a2e30:      	adrp	x16, 0xab000
   a2e34:      	ldr	x17, [x16, #0x660]
   a2e38:      	add	x16, x16, #0x660
   a2e3c:      	br	x17

00000000000a2e40 <_ZN8mtlabar320LayerTextInteraction23setCompositionTextPathsERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a2e40:      	adrp	x16, 0xab000
   a2e44:      	ldr	x17, [x16, #0x668]
   a2e48:      	add	x16, x16, #0x668
   a2e4c:      	br	x17

00000000000a2e50 <_ZN8mtlabar320LayerTextInteraction18getCompositionTypeEv@plt>:
   a2e50:      	adrp	x16, 0xab000
   a2e54:      	ldr	x17, [x16, #0x670]
   a2e58:      	add	x16, x16, #0x670
   a2e5c:      	br	x17

00000000000a2e60 <_ZN8mtlabar320LayerTextInteraction19setEnableTextMirrorEb@plt>:
   a2e60:      	adrp	x16, 0xab000
   a2e64:      	ldr	x17, [x16, #0x678]
   a2e68:      	add	x16, x16, #0x678
   a2e6c:      	br	x17

00000000000a2e70 <_ZN8mtlabar320LayerTextInteraction19getEnableTextMirrorEv@plt>:
   a2e70:      	adrp	x16, 0xab000
   a2e74:      	ldr	x17, [x16, #0x680]
   a2e78:      	add	x16, x16, #0x680
   a2e7c:      	br	x17

00000000000a2e80 <_ZN8mtlabar321LayerChartInteraction7setDataENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_6vectorIfNS5_IfEEEE@plt>:
   a2e80:      	adrp	x16, 0xab000
   a2e84:      	ldr	x17, [x16, #0x688]
   a2e88:      	add	x16, x16, #0x688
   a2e8c:      	br	x17

00000000000a2e90 <_ZN8mtlabar321LayerChartInteraction7getDataENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a2e90:      	adrp	x16, 0xab000
   a2e94:      	ldr	x17, [x16, #0x690]
   a2e98:      	add	x16, x16, #0x690
   a2e9c:      	br	x17

00000000000a2ea0 <_ZN8mtlabar321LayerChartInteraction10getKeyListEv@plt>:
   a2ea0:      	adrp	x16, 0xab000
   a2ea4:      	ldr	x17, [x16, #0x698]
   a2ea8:      	add	x16, x16, #0x698
   a2eac:      	br	x17

00000000000a2eb0 <_ZN8mtlabar321LayerChartInteraction15setAnimateSpeedEf@plt>:
   a2eb0:      	adrp	x16, 0xab000
   a2eb4:      	ldr	x17, [x16, #0x6a0]
   a2eb8:      	add	x16, x16, #0x6a0
   a2ebc:      	br	x17

00000000000a2ec0 <_ZN8mtlabar321LayerChartInteraction15getAnimateSpeedEv@plt>:
   a2ec0:      	adrp	x16, 0xab000
   a2ec4:      	ldr	x17, [x16, #0x6a8]
   a2ec8:      	add	x16, x16, #0x6a8
   a2ecc:      	br	x17

00000000000a2ed0 <_ZN8mtlabar329LayerTextBGTextureInteraction14setEnableColorEb@plt>:
   a2ed0:      	adrp	x16, 0xab000
   a2ed4:      	ldr	x17, [x16, #0x6b0]
   a2ed8:      	add	x16, x16, #0x6b0
   a2edc:      	br	x17

00000000000a2ee0 <_ZN8mtlabar329LayerTextBGTextureInteraction14getEnableColorEv@plt>:
   a2ee0:      	adrp	x16, 0xab000
   a2ee4:      	ldr	x17, [x16, #0x6b8]
   a2ee8:      	add	x16, x16, #0x6b8
   a2eec:      	br	x17

00000000000a2ef0 <_ZN8mtlabar329LayerTextBGTextureInteraction8setColorERKNS_5ColorE@plt>:
   a2ef0:      	adrp	x16, 0xab000
   a2ef4:      	ldr	x17, [x16, #0x6c0]
   a2ef8:      	add	x16, x16, #0x6c0
   a2efc:      	br	x17

00000000000a2f00 <_ZN8mtlabar329LayerTextBGTextureInteraction8getColorEv@plt>:
   a2f00:      	adrp	x16, 0xab000
   a2f04:      	ldr	x17, [x16, #0x6c8]
   a2f08:      	add	x16, x16, #0x6c8
   a2f0c:      	br	x17

00000000000a2f10 <_ZN8mtlabar330LayerObjectTrackingInteraction23setEnableObjectTrackingEb@plt>:
   a2f10:      	adrp	x16, 0xab000
   a2f14:      	ldr	x17, [x16, #0x6d0]
   a2f18:      	add	x16, x16, #0x6d0
   a2f1c:      	br	x17

00000000000a2f20 <_ZN8mtlabar330LayerObjectTrackingInteraction23getEnableObjectTrackingEv@plt>:
   a2f20:      	adrp	x16, 0xab000
   a2f24:      	ldr	x17, [x16, #0x6d8]
   a2f28:      	add	x16, x16, #0x6d8
   a2f2c:      	br	x17

00000000000a2f30 <_ZN8mtlabar330LayerObjectTrackingInteraction18initObjectTrackingERKNS_18ObjectTrackingDataE@plt>:
   a2f30:      	adrp	x16, 0xab000
   a2f34:      	ldr	x17, [x16, #0x6e0]
   a2f38:      	add	x16, x16, #0x6e0
   a2f3c:      	br	x17

00000000000a2f40 <_ZN8mtlabar330LayerObjectTrackingInteraction25getInitObjectTrackingDataEv@plt>:
   a2f40:      	adrp	x16, 0xab000
   a2f44:      	ldr	x17, [x16, #0x6e8]
   a2f48:      	add	x16, x16, #0x6e8
   a2f4c:      	br	x17

00000000000a2f50 <_ZN8mtlabar330LayerObjectTrackingInteraction21setObjectTrackingDataERKNS_18ObjectTrackingDataE@plt>:
   a2f50:      	adrp	x16, 0xab000
   a2f54:      	ldr	x17, [x16, #0x6f0]
   a2f58:      	add	x16, x16, #0x6f0
   a2f5c:      	br	x17

00000000000a2f60 <_ZN8mtlabar330LayerObjectTrackingInteraction26getIsObjectTrackingRunningEv@plt>:
   a2f60:      	adrp	x16, 0xab000
   a2f64:      	ldr	x17, [x16, #0x6f8]
   a2f68:      	add	x16, x16, #0x6f8
   a2f6c:      	br	x17

00000000000a2f70 <_ZN8mtlabar330LayerObjectTrackingInteraction29getIsObjectTrackingDataUsefulEv@plt>:
   a2f70:      	adrp	x16, 0xab000
   a2f74:      	ldr	x17, [x16, #0x700]
   a2f78:      	add	x16, x16, #0x700
   a2f7c:      	br	x17

00000000000a2f80 <_ZN8mtlabar330LayerObjectTrackingInteraction27setObjectTrackingNeedHiddenEb@plt>:
   a2f80:      	adrp	x16, 0xab000
   a2f84:      	ldr	x17, [x16, #0x708]
   a2f88:      	add	x16, x16, #0x708
   a2f8c:      	br	x17

00000000000a2f90 <_ZN8mtlabar330LayerObjectTrackingInteraction27getObjectTrackingNeedHiddenEv@plt>:
   a2f90:      	adrp	x16, 0xab000
   a2f94:      	ldr	x17, [x16, #0x710]
   a2f98:      	add	x16, x16, #0x710
   a2f9c:      	br	x17

00000000000a2fa0 <_ZN8mtlabar330LayerObjectTrackingInteraction26setFirstObjectTrackingDataERKNS_18ObjectTrackingDataE@plt>:
   a2fa0:      	adrp	x16, 0xab000
   a2fa4:      	ldr	x17, [x16, #0x718]
   a2fa8:      	add	x16, x16, #0x718
   a2fac:      	br	x17

00000000000a2fb0 <_ZN8mtlabar330LayerObjectTrackingInteraction25setLastObjectTrackingDataERKNS_18ObjectTrackingDataE@plt>:
   a2fb0:      	adrp	x16, 0xab000
   a2fb4:      	ldr	x17, [x16, #0x720]
   a2fb8:      	add	x16, x16, #0x720
   a2fbc:      	br	x17

00000000000a2fc0 <_ZN8mtlabar330LayerObjectTrackingInteraction23setCurrentTimeLineStateERKNS_27ObjectTrackingTimeLineStateE@plt>:
   a2fc0:      	adrp	x16, 0xab000
   a2fc4:      	ldr	x17, [x16, #0x728]
   a2fc8:      	add	x16, x16, #0x728
   a2fcc:      	br	x17

00000000000a2fd0 <_ZN8mtlabar328LayerFaceTrackingInteraction21setEnableFaceTrackingEb@plt>:
   a2fd0:      	adrp	x16, 0xab000
   a2fd4:      	ldr	x17, [x16, #0x730]
   a2fd8:      	add	x16, x16, #0x730
   a2fdc:      	br	x17

00000000000a2fe0 <_ZN8mtlabar328LayerFaceTrackingInteraction21getEnableFaceTrackingEv@plt>:
   a2fe0:      	adrp	x16, 0xab000
   a2fe4:      	ldr	x17, [x16, #0x738]
   a2fe8:      	add	x16, x16, #0x738
   a2fec:      	br	x17

00000000000a2ff0 <_ZN8mtlabar328LayerFaceTrackingInteraction21setFaceTrackingFaceFREl@plt>:
   a2ff0:      	adrp	x16, 0xab000
   a2ff4:      	ldr	x17, [x16, #0x740]
   a2ff8:      	add	x16, x16, #0x740
   a2ffc:      	br	x17

00000000000a3000 <_ZN8mtlabar328LayerFaceTrackingInteraction21getFaceTrackingFaceFREv@plt>:
   a3000:      	adrp	x16, 0xab000
   a3004:      	ldr	x17, [x16, #0x748]
   a3008:      	add	x16, x16, #0x748
   a300c:      	br	x17

00000000000a3010 <_ZN8mtlabar328LayerFaceTrackingInteraction24getIsFaceTrackingRunningEv@plt>:
   a3010:      	adrp	x16, 0xab000
   a3014:      	ldr	x17, [x16, #0x750]
   a3018:      	add	x16, x16, #0x750
   a301c:      	br	x17

00000000000a3020 <_ZN8mtlabar328LayerFaceTrackingInteraction23setFaceTrackingFaceDataEPv@plt>:
   a3020:      	adrp	x16, 0xab000
   a3024:      	ldr	x17, [x16, #0x758]
   a3028:      	add	x16, x16, #0x758
   a302c:      	br	x17

00000000000a3030 <_ZN8mtlabar328LayerFaceTrackingInteraction25setFaceTrackingNeedHiddenEb@plt>:
   a3030:      	adrp	x16, 0xab000
   a3034:      	ldr	x17, [x16, #0x760]
   a3038:      	add	x16, x16, #0x760
   a303c:      	br	x17

00000000000a3040 <_ZN8mtlabar328LayerFaceTrackingInteraction25getFaceTrackingNeedHiddenEv@plt>:
   a3040:      	adrp	x16, 0xab000
   a3044:      	ldr	x17, [x16, #0x768]
   a3048:      	add	x16, x16, #0x768
   a304c:      	br	x17

00000000000a3050 <_ZN8mtlabar328LayerFaceTrackingInteraction31setFaceTrackingFaceDataWithVLDPEP18vldp_data_protocolii@plt>:
   a3050:      	adrp	x16, 0xab000
   a3054:      	ldr	x17, [x16, #0x770]
   a3058:      	add	x16, x16, #0x770
   a305c:      	br	x17

00000000000a3060 <_ZN8mtlabar328LayerFaceTrackingInteraction23getFaceTrackingUseMouthEv@plt>:
   a3060:      	adrp	x16, 0xab000
   a3064:      	ldr	x17, [x16, #0x778]
   a3068:      	add	x16, x16, #0x778
   a306c:      	br	x17

00000000000a3070 <_ZN8mtlabar328LayerFaceTrackingInteraction23setFaceTrackingUseMouthEb@plt>:
   a3070:      	adrp	x16, 0xab000
   a3074:      	ldr	x17, [x16, #0x780]
   a3078:      	add	x16, x16, #0x780
   a307c:      	br	x17

00000000000a3080 <_ZN8mtlabar320LayerMaskInteraction5validEv@plt>:
   a3080:      	adrp	x16, 0xab000
   a3084:      	ldr	x17, [x16, #0x788]
   a3088:      	add	x16, x16, #0x788
   a308c:      	br	x17

00000000000a3090 <_ZN8mtlabar320LayerMaskInteraction13setConfigPathEPKc@plt>:
   a3090:      	adrp	x16, 0xab000
   a3094:      	ldr	x17, [x16, #0x790]
   a3098:      	add	x16, x16, #0x790
   a309c:      	br	x17

00000000000a30a0 <_ZN8mtlabar320LayerMaskInteraction13getConfigPathEv@plt>:
   a30a0:      	adrp	x16, 0xab000
   a30a4:      	ldr	x17, [x16, #0x798]
   a30a8:      	add	x16, x16, #0x798
   a30ac:      	br	x17

00000000000a30b0 <_ZN8mtlabar320LayerMaskInteraction10setReverseEb@plt>:
   a30b0:      	adrp	x16, 0xab000
   a30b4:      	ldr	x17, [x16, #0x7a0]
   a30b8:      	add	x16, x16, #0x7a0
   a30bc:      	br	x17

00000000000a30c0 <_ZN8mtlabar320LayerMaskInteraction10getReverseEv@plt>:
   a30c0:      	adrp	x16, 0xab000
   a30c4:      	ldr	x17, [x16, #0x7a8]
   a30c8:      	add	x16, x16, #0x7a8
   a30cc:      	br	x17

00000000000a30d0 <_ZN8mtlabar320LayerMaskInteraction13setBlurDegreeEf@plt>:
   a30d0:      	adrp	x16, 0xab000
   a30d4:      	ldr	x17, [x16, #0x7b0]
   a30d8:      	add	x16, x16, #0x7b0
   a30dc:      	br	x17

00000000000a30e0 <_ZN8mtlabar320LayerMaskInteraction13getBlurDegreeEv@plt>:
   a30e0:      	adrp	x16, 0xab000
   a30e4:      	ldr	x17, [x16, #0x7b8]
   a30e8:      	add	x16, x16, #0x7b8
   a30ec:      	br	x17

00000000000a30f0 <_ZN8mtlabar323LayerStickerInteraction20setImportStickerDataEPKNS_27MvImportStickerConfigStructE@plt>:
   a30f0:      	adrp	x16, 0xab000
   a30f4:      	ldr	x17, [x16, #0x7c0]
   a30f8:      	add	x16, x16, #0x7c0
   a30fc:      	br	x17

00000000000a3100 <_ZNK8mtlabar323LayerStickerInteraction24getStickerPlayDurationMsEv@plt>:
   a3100:      	adrp	x16, 0xab000
   a3104:      	ldr	x17, [x16, #0x7c8]
   a3108:      	add	x16, x16, #0x7c8
   a310c:      	br	x17

00000000000a3110 <_ZN8mtlabar323LayerStickerInteraction24setStickerPlayDurationMsEf@plt>:
   a3110:      	adrp	x16, 0xab000
   a3114:      	ldr	x17, [x16, #0x7d0]
   a3118:      	add	x16, x16, #0x7d0
   a311c:      	br	x17

00000000000a3120 <_ZN8mtlabar323LayerStickerInteraction13setStickerHSLEfff@plt>:
   a3120:      	adrp	x16, 0xab000
   a3124:      	ldr	x17, [x16, #0x7d8]
   a3128:      	add	x16, x16, #0x7d8
   a312c:      	br	x17

00000000000a3130 <_ZNK8mtlabar323LayerStickerInteraction13getStickerHSLEPfS1_S1_@plt>:
   a3130:      	adrp	x16, 0xab000
   a3134:      	ldr	x17, [x16, #0x7e0]
   a3138:      	add	x16, x16, #0x7e0
   a313c:      	br	x17

00000000000a3140 <_ZN8mtlabar323LayerStickerInteraction16enableStickerHSLEb@plt>:
   a3140:      	adrp	x16, 0xab000
   a3144:      	ldr	x17, [x16, #0x7e8]
   a3148:      	add	x16, x16, #0x7e8
   a314c:      	br	x17

00000000000a3150 <_ZNK8mtlabar323LayerStickerInteraction19isStickerHSLEnabledEv@plt>:
   a3150:      	adrp	x16, 0xab000
   a3154:      	ldr	x17, [x16, #0x7f0]
   a3158:      	add	x16, x16, #0x7f0
   a315c:      	br	x17

00000000000a3160 <_ZNK8mtlabar323LayerStickerInteraction19getStickerPlaySpeedEv@plt>:
   a3160:      	adrp	x16, 0xab000
   a3164:      	ldr	x17, [x16, #0x7f8]
   a3168:      	add	x16, x16, #0x7f8
   a316c:      	br	x17

00000000000a3170 <_ZN8mtlabar323LayerStickerInteraction19setStickerPlaySpeedEf@plt>:
   a3170:      	adrp	x16, 0xab000
   a3174:      	ldr	x17, [x16, #0x800]
   a3178:      	add	x16, x16, #0x800
   a317c:      	br	x17

00000000000a3180 <_ZN8mtlabar325LayerAnimationInteraction5validEv@plt>:
   a3180:      	adrp	x16, 0xab000
   a3184:      	ldr	x17, [x16, #0x808]
   a3188:      	add	x16, x16, #0x808
   a318c:      	br	x17

00000000000a3190 <_ZN8mtlabar325LayerAnimationInteraction13setConfigPathEPKc@plt>:
   a3190:      	adrp	x16, 0xab000
   a3194:      	ldr	x17, [x16, #0x810]
   a3198:      	add	x16, x16, #0x810
   a319c:      	br	x17

00000000000a31a0 <_ZN8mtlabar325LayerAnimationInteraction13getConfigPathEv@plt>:
   a31a0:      	adrp	x16, 0xab000
   a31a4:      	ldr	x17, [x16, #0x818]
   a31a8:      	add	x16, x16, #0x818
   a31ac:      	br	x17

00000000000a31b0 <_ZN8mtlabar325LayerAnimationInteraction12setTotalTimeEf@plt>:
   a31b0:      	adrp	x16, 0xab000
   a31b4:      	ldr	x17, [x16, #0x820]
   a31b8:      	add	x16, x16, #0x820
   a31bc:      	br	x17

00000000000a31c0 <_ZN8mtlabar325LayerAnimationInteraction12getTotalTimeEv@plt>:
   a31c0:      	adrp	x16, 0xab000
   a31c4:      	ldr	x17, [x16, #0x828]
   a31c8:      	add	x16, x16, #0x828
   a31cc:      	br	x17

00000000000a31d0 <_ZN8mtlabar325LayerAnimationInteraction11setOnceTimeEf@plt>:
   a31d0:      	adrp	x16, 0xab000
   a31d4:      	ldr	x17, [x16, #0x830]
   a31d8:      	add	x16, x16, #0x830
   a31dc:      	br	x17

00000000000a31e0 <_ZN8mtlabar325LayerAnimationInteraction11getOnceTimeEv@plt>:
   a31e0:      	adrp	x16, 0xab000
   a31e4:      	ldr	x17, [x16, #0x838]
   a31e8:      	add	x16, x16, #0x838
   a31ec:      	br	x17

00000000000a31f0 <_ZN8mtlabar325LayerAnimationInteraction8setSpeedEf@plt>:
   a31f0:      	adrp	x16, 0xab000
   a31f4:      	ldr	x17, [x16, #0x840]
   a31f8:      	add	x16, x16, #0x840
   a31fc:      	br	x17

00000000000a3200 <_ZN8mtlabar325LayerAnimationInteraction8getSpeedEv@plt>:
   a3200:      	adrp	x16, 0xab000
   a3204:      	ldr	x17, [x16, #0x848]
   a3208:      	add	x16, x16, #0x848
   a320c:      	br	x17

00000000000a3210 <_ZN8mtlabar325LayerAnimationInteraction17setBeginTimestampEf@plt>:
   a3210:      	adrp	x16, 0xab000
   a3214:      	ldr	x17, [x16, #0x850]
   a3218:      	add	x16, x16, #0x850
   a321c:      	br	x17

00000000000a3220 <_ZN8mtlabar325LayerAnimationInteraction17getBeginTimestampEv@plt>:
   a3220:      	adrp	x16, 0xab000
   a3224:      	ldr	x17, [x16, #0x858]
   a3228:      	add	x16, x16, #0x858
   a322c:      	br	x17

00000000000a3230 <_ZN8mtlabar325LayerAnimationInteraction15setEndTimestampEf@plt>:
   a3230:      	adrp	x16, 0xab000
   a3234:      	ldr	x17, [x16, #0x860]
   a3238:      	add	x16, x16, #0x860
   a323c:      	br	x17

00000000000a3240 <_ZN8mtlabar325LayerAnimationInteraction15getEndTimestampEv@plt>:
   a3240:      	adrp	x16, 0xab000
   a3244:      	ldr	x17, [x16, #0x868]
   a3248:      	add	x16, x16, #0x868
   a324c:      	br	x17

00000000000a3250 <_ZN8mtlabar325LayerAnimationInteraction19disableEndTimestampEb@plt>:
   a3250:      	adrp	x16, 0xab000
   a3254:      	ldr	x17, [x16, #0x870]
   a3258:      	add	x16, x16, #0x870
   a325c:      	br	x17

00000000000a3260 <_ZN8mtlabar325LayerAnimationInteraction22isEndTimestampDisabledEv@plt>:
   a3260:      	adrp	x16, 0xab000
   a3264:      	ldr	x17, [x16, #0x878]
   a3268:      	add	x16, x16, #0x878
   a326c:      	br	x17

00000000000a3270 <_ZN8mtlabar325LayerAnimationInteraction11setJsonPathEPKc@plt>:
   a3270:      	adrp	x16, 0xab000
   a3274:      	ldr	x17, [x16, #0x880]
   a3278:      	add	x16, x16, #0x880
   a327c:      	br	x17

00000000000a3280 <_ZN8mtlabar325LayerAnimationInteraction11getJsonPathEv@plt>:
   a3280:      	adrp	x16, 0xab000
   a3284:      	ldr	x17, [x16, #0x888]
   a3288:      	add	x16, x16, #0x888
   a328c:      	br	x17

00000000000a3290 <_ZN8mtlabar325LayerAnimationInteraction14setRepeatCountEi@plt>:
   a3290:      	adrp	x16, 0xab000
   a3294:      	ldr	x17, [x16, #0x890]
   a3298:      	add	x16, x16, #0x890
   a329c:      	br	x17

00000000000a32a0 <_ZN8mtlabar325LayerAnimationInteraction14getRepeatCountEv@plt>:
   a32a0:      	adrp	x16, 0xab000
   a32a4:      	ldr	x17, [x16, #0x898]
   a32a8:      	add	x16, x16, #0x898
   a32ac:      	br	x17

00000000000a32b0 <_ZN8mtlabar325LayerAnimationInteraction16setImageWarpModeEi@plt>:
   a32b0:      	adrp	x16, 0xab000
   a32b4:      	ldr	x17, [x16, #0x8a0]
   a32b8:      	add	x16, x16, #0x8a0
   a32bc:      	br	x17

00000000000a32c0 <_ZN8mtlabar325LayerAnimationInteraction16getImageWarpModeEv@plt>:
   a32c0:      	adrp	x16, 0xab000
   a32c4:      	ldr	x17, [x16, #0x8a8]
   a32c8:      	add	x16, x16, #0x8a8
   a32cc:      	br	x17

00000000000a32d0 <_ZN8mtlabar325LayerAnimationInteraction12setLoopStateEb@plt>:
   a32d0:      	adrp	x16, 0xab000
   a32d4:      	ldr	x17, [x16, #0x8b0]
   a32d8:      	add	x16, x16, #0x8b0
   a32dc:      	br	x17

00000000000a32e0 <_ZN8mtlabar325LayerAnimationInteraction12getLoopStateEv@plt>:
   a32e0:      	adrp	x16, 0xab000
   a32e4:      	ldr	x17, [x16, #0x8b8]
   a32e8:      	add	x16, x16, #0x8b8
   a32ec:      	br	x17

00000000000a32f0 <_ZN8mtlabar325LayerAnimationInteraction18setApplySubTextBoxEi@plt>:
   a32f0:      	adrp	x16, 0xab000
   a32f4:      	ldr	x17, [x16, #0x8c0]
   a32f8:      	add	x16, x16, #0x8c0
   a32fc:      	br	x17

00000000000a3300 <_ZN8mtlabar325LayerAnimationInteraction21isFullScreenAnimationEv@plt>:
   a3300:      	adrp	x16, 0xab000
   a3304:      	ldr	x17, [x16, #0x8c8]
   a3308:      	add	x16, x16, #0x8c8
   a330c:      	br	x17

00000000000a3310 <_ZN8mtlabar325LayerAnimationInteraction18setShowStaticFrameEb@plt>:
   a3310:      	adrp	x16, 0xab000
   a3314:      	ldr	x17, [x16, #0x8d0]
   a3318:      	add	x16, x16, #0x8d0
   a331c:      	br	x17

00000000000a3320 <_ZN8mtlabar325LayerAnimationInteraction18getShowStaticFrameEv@plt>:
   a3320:      	adrp	x16, 0xab000
   a3324:      	ldr	x17, [x16, #0x8d8]
   a3328:      	add	x16, x16, #0x8d8
   a332c:      	br	x17

00000000000a3330 <_ZN8mtlabar325LayerAnimationInteraction24isHighlightTextAnimationEv@plt>:
   a3330:      	adrp	x16, 0xab000
   a3334:      	ldr	x17, [x16, #0x8e0]
   a3338:      	add	x16, x16, #0x8e0
   a333c:      	br	x17

00000000000a3340 <_ZN8mtlabar325LayerAnimationInteraction19setPartialTextIndexEi@plt>:
   a3340:      	adrp	x16, 0xab000
   a3344:      	ldr	x17, [x16, #0x8e8]
   a3348:      	add	x16, x16, #0x8e8
   a334c:      	br	x17

00000000000a3350 <_ZN8mtlabar325LayerAnimationInteraction20setPartialTextLengthEi@plt>:
   a3350:      	adrp	x16, 0xab000
   a3354:      	ldr	x17, [x16, #0x8f0]
   a3358:      	add	x16, x16, #0x8f0
   a335c:      	br	x17

00000000000a3360 <_ZN8mtlabar325LayerAnimationInteraction22setPartialTextFontSizeEf@plt>:
   a3360:      	adrp	x16, 0xab000
   a3364:      	ldr	x17, [x16, #0x8f8]
   a3368:      	add	x16, x16, #0x8f8
   a336c:      	br	x17

00000000000a3370 <_ZN8mtlabar325LayerAnimationInteraction18setFontLibraryListERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a3370:      	adrp	x16, 0xab000
   a3374:      	ldr	x17, [x16, #0x900]
   a3378:      	add	x16, x16, #0x900
   a337c:      	br	x17

00000000000a3380 <_ZN8mtlabar325LayerAnimationInteraction18getFontLibraryListEv@plt>:
   a3380:      	adrp	x16, 0xab000
   a3384:      	ldr	x17, [x16, #0x908]
   a3388:      	add	x16, x16, #0x908
   a338c:      	br	x17

00000000000a3390 <_ZN8mtlabar325LayerAnimationInteraction16getStopLastFrameEv@plt>:
   a3390:      	adrp	x16, 0xab000
   a3394:      	ldr	x17, [x16, #0x910]
   a3398:      	add	x16, x16, #0x910
   a339c:      	br	x17

00000000000a33a0 <_ZN8mtlabar325LayerAnimationInteraction16setStopLastFrameEb@plt>:
   a33a0:      	adrp	x16, 0xab000
   a33a4:      	ldr	x17, [x16, #0x918]
   a33a8:      	add	x16, x16, #0x918
   a33ac:      	br	x17

00000000000a33b0 <_ZN8mtlabar325LayerAnimationInteraction16setAnimationTypeENS_17AnimationTimeTypeE@plt>:
   a33b0:      	adrp	x16, 0xab000
   a33b4:      	ldr	x17, [x16, #0x920]
   a33b8:      	add	x16, x16, #0x920
   a33bc:      	br	x17

00000000000a33c0 <_ZN8mtlabar325LayerAnimationInteraction21setAnimationScopeTypeENS_18AnimationScopeTypeE@plt>:
   a33c0:      	adrp	x16, 0xab000
   a33c4:      	ldr	x17, [x16, #0x928]
   a33c8:      	add	x16, x16, #0x928
   a33cc:      	br	x17

00000000000a33d0 <_ZN8mtlabar325LayerAnimationInteraction21getAnimationScopeTypeEv@plt>:
   a33d0:      	adrp	x16, 0xab000
   a33d4:      	ldr	x17, [x16, #0x930]
   a33d8:      	add	x16, x16, #0x930
   a33dc:      	br	x17

00000000000a33e0 <_ZN8mtlabar325LayerAnimationInteraction19setAdvanceAnimationEb@plt>:
   a33e0:      	adrp	x16, 0xab000
   a33e4:      	ldr	x17, [x16, #0x938]
   a33e8:      	add	x16, x16, #0x938
   a33ec:      	br	x17

00000000000a33f0 <_ZN8mtlabar325LayerAnimationInteraction19getAdvanceAnimationEv@plt>:
   a33f0:      	adrp	x16, 0xab000
   a33f4:      	ldr	x17, [x16, #0x940]
   a33f8:      	add	x16, x16, #0x940
   a33fc:      	br	x17

00000000000a3400 <_ZN8mtlabar325LayerAnimationInteraction18getCustomTransformEv@plt>:
   a3400:      	adrp	x16, 0xab000
   a3404:      	ldr	x17, [x16, #0x948]
   a3408:      	add	x16, x16, #0x948
   a340c:      	br	x17

00000000000a3410 <_ZN8mtlabar325LayerAnimationInteraction15getActiveWordBgEv@plt>:
   a3410:      	adrp	x16, 0xab000
   a3414:      	ldr	x17, [x16, #0x950]
   a3418:      	add	x16, x16, #0x950
   a341c:      	br	x17

00000000000a3420 <_ZN8mtlabar325LayerAnimationInteraction18getActiveWordColorEv@plt>:
   a3420:      	adrp	x16, 0xab000
   a3424:      	ldr	x17, [x16, #0x958]
   a3428:      	add	x16, x16, #0x958
   a342c:      	br	x17

00000000000a3430 <_ZN8mtlabar325LayerAnimationInteraction21getPreActiveWordColorEv@plt>:
   a3430:      	adrp	x16, 0xab000
   a3434:      	ldr	x17, [x16, #0x960]
   a3438:      	add	x16, x16, #0x960
   a343c:      	br	x17

00000000000a3440 <_ZN8mtlabar325LayerAnimationInteraction18getActiveWordStyleEv@plt>:
   a3440:      	adrp	x16, 0xab000
   a3444:      	ldr	x17, [x16, #0x968]
   a3448:      	add	x16, x16, #0x968
   a344c:      	br	x17

00000000000a3450 <_ZN8mtlabar321LayerAnimationManager15appendAnimationEv@plt>:
   a3450:      	adrp	x16, 0xab000
   a3454:      	ldr	x17, [x16, #0x970]
   a3458:      	add	x16, x16, #0x970
   a345c:      	br	x17

00000000000a3460 <_ZN8mtlabar321LayerAnimationManager17subtractAnimationEPv@plt>:
   a3460:      	adrp	x16, 0xab000
   a3464:      	ldr	x17, [x16, #0x978]
   a3468:      	add	x16, x16, #0x978
   a346c:      	br	x17

00000000000a3470 <_ZN8mtlabar321LayerAnimationManager20getAnimationListSizeEv@plt>:
   a3470:      	adrp	x16, 0xab000
   a3474:      	ldr	x17, [x16, #0x980]
   a3478:      	add	x16, x16, #0x980
   a347c:      	br	x17

00000000000a3480 <_ZN8mtlabar321LayerAnimationManager23getAnimationListByIndexEi@plt>:
   a3480:      	adrp	x16, 0xab000
   a3484:      	ldr	x17, [x16, #0x988]
   a3488:      	add	x16, x16, #0x988
   a348c:      	br	x17

00000000000a3490 <_ZN8mtlabar321LayerAnimationManager12getAnimationEPv@plt>:
   a3490:      	adrp	x16, 0xab000
   a3494:      	ldr	x17, [x16, #0x990]
   a3498:      	add	x16, x16, #0x990
   a349c:      	br	x17

00000000000a34a0 <_ZN8mtlabar321LayerAnimationManager27selectedFullScreenAnimationEPv@plt>:
   a34a0:      	adrp	x16, 0xab000
   a34a4:      	ldr	x17, [x16, #0x998]
   a34a8:      	add	x16, x16, #0x998
   a34ac:      	br	x17

00000000000a34b0 <_ZN8mtlabar321LayerAnimationManager20setAnimationPriorityERKNSt6__ndk16vectorINS_17AnimationTimeTypeENS1_9allocatorIS3_EEEE@plt>:
   a34b0:      	adrp	x16, 0xab000
   a34b4:      	ldr	x17, [x16, #0x9a0]
   a34b8:      	add	x16, x16, #0x9a0
   a34bc:      	br	x17

00000000000a34c0 <_ZN8mtlabar325LayerTransformInteraction8setTransENS_6Float2E@plt>:
   a34c0:      	adrp	x16, 0xab000
   a34c4:      	ldr	x17, [x16, #0x9a8]
   a34c8:      	add	x16, x16, #0x9a8
   a34cc:      	br	x17

00000000000a34d0 <_ZN8mtlabar325LayerTransformInteraction8getTransEv@plt>:
   a34d0:      	adrp	x16, 0xab000
   a34d4:      	ldr	x17, [x16, #0x9b0]
   a34d8:      	add	x16, x16, #0x9b0
   a34dc:      	br	x17

00000000000a34e0 <_ZN8mtlabar325LayerTransformInteraction20getCurrentFinalTransEv@plt>:
   a34e0:      	adrp	x16, 0xab000
   a34e4:      	ldr	x17, [x16, #0x9b8]
   a34e8:      	add	x16, x16, #0x9b8
   a34ec:      	br	x17

00000000000a34f0 <_ZN8mtlabar325LayerTransformInteraction21getCurrentFinalRotateEv@plt>:
   a34f0:      	adrp	x16, 0xab000
   a34f4:      	ldr	x17, [x16, #0x9c0]
   a34f8:      	add	x16, x16, #0x9c0
   a34fc:      	br	x17

00000000000a3500 <_ZN8mtlabar325LayerTransformInteraction18getTouchTransScaleEv@plt>:
   a3500:      	adrp	x16, 0xab000
   a3504:      	ldr	x17, [x16, #0x9c8]
   a3508:      	add	x16, x16, #0x9c8
   a350c:      	br	x17

00000000000a3510 <_ZN8mtlabar325LayerTransformInteraction8setScaleEf@plt>:
   a3510:      	adrp	x16, 0xab000
   a3514:      	ldr	x17, [x16, #0x9d0]
   a3518:      	add	x16, x16, #0x9d0
   a351c:      	br	x17

00000000000a3520 <_ZN8mtlabar325LayerTransformInteraction8getScaleEv@plt>:
   a3520:      	adrp	x16, 0xab000
   a3524:      	ldr	x17, [x16, #0x9d8]
   a3528:      	add	x16, x16, #0x9d8
   a352c:      	br	x17

00000000000a3530 <_ZN8mtlabar325LayerTransformInteraction10setScaleXYENS_6Float2E@plt>:
   a3530:      	adrp	x16, 0xab000
   a3534:      	ldr	x17, [x16, #0x9e0]
   a3538:      	add	x16, x16, #0x9e0
   a353c:      	br	x17

00000000000a3540 <_ZN8mtlabar325LayerTransformInteraction10getScaleXYEv@plt>:
   a3540:      	adrp	x16, 0xab000
   a3544:      	ldr	x17, [x16, #0x9e8]
   a3548:      	add	x16, x16, #0x9e8
   a354c:      	br	x17

00000000000a3550 <_ZN8mtlabar325LayerTransformInteraction15getFinalScaleXYEv@plt>:
   a3550:      	adrp	x16, 0xab000
   a3554:      	ldr	x17, [x16, #0x9f0]
   a3558:      	add	x16, x16, #0x9f0
   a355c:      	br	x17

00000000000a3560 <_ZN8mtlabar325LayerTransformInteraction9setRotateEf@plt>:
   a3560:      	adrp	x16, 0xab000
   a3564:      	ldr	x17, [x16, #0x9f8]
   a3568:      	add	x16, x16, #0x9f8
   a356c:      	br	x17

00000000000a3570 <_ZN8mtlabar325LayerTransformInteraction9getRotateEv@plt>:
   a3570:      	adrp	x16, 0xab000
   a3574:      	ldr	x17, [x16, #0xa00]
   a3578:      	add	x16, x16, #0xa00
   a357c:      	br	x17

00000000000a3580 <_ZN8mtlabar325LayerTransformInteraction9setMirrorEb@plt>:
   a3580:      	adrp	x16, 0xab000
   a3584:      	ldr	x17, [x16, #0xa08]
   a3588:      	add	x16, x16, #0xa08
   a358c:      	br	x17

00000000000a3590 <_ZN8mtlabar325LayerTransformInteraction9getMirrorEv@plt>:
   a3590:      	adrp	x16, 0xab000
   a3594:      	ldr	x17, [x16, #0xa10]
   a3598:      	add	x16, x16, #0xa10
   a359c:      	br	x17

00000000000a35a0 <_ZN8mtlabar322LayerBorderInteraction12setAreaLimitEb@plt>:
   a35a0:      	adrp	x16, 0xab000
   a35a4:      	ldr	x17, [x16, #0xa18]
   a35a8:      	add	x16, x16, #0xa18
   a35ac:      	br	x17

00000000000a35b0 <_ZN8mtlabar322LayerBorderInteraction12getAreaLimitEv@plt>:
   a35b0:      	adrp	x16, 0xab000
   a35b4:      	ldr	x17, [x16, #0xa20]
   a35b8:      	add	x16, x16, #0xa20
   a35bc:      	br	x17

00000000000a35c0 <_ZN8mtlabar322LayerBorderInteraction23getBorderVertexPositionENS_15LayerVertexEnumE@plt>:
   a35c0:      	adrp	x16, 0xab000
   a35c4:      	ldr	x17, [x16, #0xa28]
   a35c8:      	add	x16, x16, #0xa28
   a35cc:      	br	x17

00000000000a35d0 <_ZN8mtlabar322LayerBorderInteraction24getBorderVertexPosition2ENS_15LayerVertexEnumE@plt>:
   a35d0:      	adrp	x16, 0xab000
   a35d4:      	ldr	x17, [x16, #0xa30]
   a35d8:      	add	x16, x16, #0xa30
   a35dc:      	br	x17

00000000000a35e0 <_ZN8mtlabar322LayerBorderInteraction16getBorderPaddingENS_13LayerEdgeEnumE@plt>:
   a35e0:      	adrp	x16, 0xab000
   a35e4:      	ldr	x17, [x16, #0xa38]
   a35e8:      	add	x16, x16, #0xa38
   a35ec:      	br	x17

00000000000a35f0 <_ZN8mtlabar322LayerBorderInteraction21getLayerBorderPaddingENS_13LayerEdgeEnumE@plt>:
   a35f0:      	adrp	x16, 0xab000
   a35f4:      	ldr	x17, [x16, #0xa40]
   a35f8:      	add	x16, x16, #0xa40
   a35fc:      	br	x17

00000000000a3600 <_ZN8mtlabar322LayerBorderInteraction34setLocalLayerOutlineBorderMinValueEi@plt>:
   a3600:      	adrp	x16, 0xab000
   a3604:      	ldr	x17, [x16, #0xa48]
   a3608:      	add	x16, x16, #0xa48
   a360c:      	br	x17

00000000000a3610 <_ZN8mtlabar322LayerBorderInteraction36setLocalLayerOutlineBorderMarginLeftEi@plt>:
   a3610:      	adrp	x16, 0xab000
   a3614:      	ldr	x17, [x16, #0xa50]
   a3618:      	add	x16, x16, #0xa50
   a361c:      	br	x17

00000000000a3620 <_ZN8mtlabar322LayerBorderInteraction37setLocalLayerOutlineBorderMarginRightEi@plt>:
   a3620:      	adrp	x16, 0xab000
   a3624:      	ldr	x17, [x16, #0xa58]
   a3628:      	add	x16, x16, #0xa58
   a362c:      	br	x17

00000000000a3630 <_ZN8mtlabar322LayerBorderInteraction35setLocalLayerOutlineBorderMarginTopEi@plt>:
   a3630:      	adrp	x16, 0xab000
   a3634:      	ldr	x17, [x16, #0xa60]
   a3638:      	add	x16, x16, #0xa60
   a363c:      	br	x17

00000000000a3640 <_ZN8mtlabar322LayerBorderInteraction38setLocalLayerOutlineBorderMarginBottomEi@plt>:
   a3640:      	adrp	x16, 0xab000
   a3644:      	ldr	x17, [x16, #0xa68]
   a3648:      	add	x16, x16, #0xa68
   a364c:      	br	x17

00000000000a3650 <_ZN8mtlabar322LayerBorderInteraction24calcBorderVertexPositionENS_6Float2Eff@plt>:
   a3650:      	adrp	x16, 0xab000
   a3654:      	ldr	x17, [x16, #0xa70]
   a3658:      	add	x16, x16, #0xa70
   a365c:      	br	x17

00000000000a3660 <_ZN8mtlabar322LayerBorderInteraction27getEnableTextBoxInteractionEv@plt>:
   a3660:      	adrp	x16, 0xab000
   a3664:      	ldr	x17, [x16, #0xa78]
   a3668:      	add	x16, x16, #0xa78
   a366c:      	br	x17

00000000000a3670 <_ZN8mtlabar322LayerBorderInteraction27setEnableTextBoxInteractionEb@plt>:
   a3670:      	adrp	x16, 0xab000
   a3674:      	ldr	x17, [x16, #0xa80]
   a3678:      	add	x16, x16, #0xa80
   a367c:      	br	x17

00000000000a3680 <_ZN8mtlabar316LayerInteraction24getLayerAnimationManagerEv@plt>:
   a3680:      	adrp	x16, 0xab000
   a3684:      	ldr	x17, [x16, #0xa88]
   a3688:      	add	x16, x16, #0xa88
   a368c:      	br	x17

00000000000a3690 <_ZN8mtlabar316LayerInteraction25getLayerBorderInteractionEv@plt>:
   a3690:      	adrp	x16, 0xab000
   a3694:      	ldr	x17, [x16, #0xa90]
   a3698:      	add	x16, x16, #0xa90
   a369c:      	br	x17

00000000000a36a0 <_ZN8mtlabar316LayerInteraction28getLayerTransformInteractionEv@plt>:
   a36a0:      	adrp	x16, 0xab000
   a36a4:      	ldr	x17, [x16, #0xa98]
   a36a8:      	add	x16, x16, #0xa98
   a36ac:      	br	x17

00000000000a36b0 <_ZN8mtlabar316LayerInteraction20getLayerTrackingTypeEv@plt>:
   a36b0:      	adrp	x16, 0xab000
   a36b4:      	ldr	x17, [x16, #0xaa0]
   a36b8:      	add	x16, x16, #0xaa0
   a36bc:      	br	x17

00000000000a36c0 <_ZN8mtlabar316LayerInteraction33getLayerObjectTrackingInteractionEv@plt>:
   a36c0:      	adrp	x16, 0xab000
   a36c4:      	ldr	x17, [x16, #0xaa8]
   a36c8:      	add	x16, x16, #0xaa8
   a36cc:      	br	x17

00000000000a36d0 <_ZN8mtlabar316LayerInteraction31getLayerFaceTrackingInteractionEv@plt>:
   a36d0:      	adrp	x16, 0xab000
   a36d4:      	ldr	x17, [x16, #0xab0]
   a36d8:      	add	x16, x16, #0xab0
   a36dc:      	br	x17

00000000000a36e0 <_ZN8mtlabar316LayerInteraction23getLayerTextInteractionEv@plt>:
   a36e0:      	adrp	x16, 0xab000
   a36e4:      	ldr	x17, [x16, #0xab8]
   a36e8:      	add	x16, x16, #0xab8
   a36ec:      	br	x17

00000000000a36f0 <_ZN8mtlabar316LayerInteraction23getLayerMaskInteractionEv@plt>:
   a36f0:      	adrp	x16, 0xab000
   a36f4:      	ldr	x17, [x16, #0xac0]
   a36f8:      	add	x16, x16, #0xac0
   a36fc:      	br	x17

00000000000a3700 <_ZN8mtlabar316LayerInteraction26getLayerStickerInteractionEv@plt>:
   a3700:      	adrp	x16, 0xab000
   a3704:      	ldr	x17, [x16, #0xac8]
   a3708:      	add	x16, x16, #0xac8
   a370c:      	br	x17

00000000000a3710 <_ZN8mtlabar316LayerInteraction24getLayerChartInteractionEv@plt>:
   a3710:      	adrp	x16, 0xab000
   a3714:      	ldr	x17, [x16, #0xad0]
   a3718:      	add	x16, x16, #0xad0
   a371c:      	br	x17

00000000000a3720 <_ZN8mtlabar316LayerInteraction32getLayerTextBGTextureInteractionEv@plt>:
   a3720:      	adrp	x16, 0xab000
   a3724:      	ldr	x17, [x16, #0xad8]
   a3728:      	add	x16, x16, #0xad8
   a372c:      	br	x17

00000000000a3730 <_ZN8mtlabar316LayerInteraction6getTagEv@plt>:
   a3730:      	adrp	x16, 0xab000
   a3734:      	ldr	x17, [x16, #0xae0]
   a3738:      	add	x16, x16, #0xae0
   a373c:      	br	x17

00000000000a3740 <_ZN8mtlabar316LayerInteraction15setOriginalSizeENS_5SizeFE@plt>:
   a3740:      	adrp	x16, 0xab000
   a3744:      	ldr	x17, [x16, #0xae8]
   a3748:      	add	x16, x16, #0xae8
   a374c:      	br	x17

00000000000a3750 <_ZN8mtlabar316LayerInteraction15getOriginalSizeEv@plt>:
   a3750:      	adrp	x16, 0xab000
   a3754:      	ldr	x17, [x16, #0xaf0]
   a3758:      	add	x16, x16, #0xaf0
   a375c:      	br	x17

00000000000a3760 <_ZN8mtlabar316LayerInteraction12getFinalSizeEv@plt>:
   a3760:      	adrp	x16, 0xab000
   a3764:      	ldr	x17, [x16, #0xaf8]
   a3768:      	add	x16, x16, #0xaf8
   a376c:      	br	x17

00000000000a3770 <_ZN8mtlabar316LayerInteraction14getDefaultSizeEv@plt>:
   a3770:      	adrp	x16, 0xab000
   a3774:      	ldr	x17, [x16, #0xb00]
   a3778:      	add	x16, x16, #0xb00
   a377c:      	br	x17

00000000000a3780 <_ZN8mtlabar316LayerInteraction12setTimestampEl@plt>:
   a3780:      	adrp	x16, 0xab000
   a3784:      	ldr	x17, [x16, #0xb08]
   a3788:      	add	x16, x16, #0xb08
   a378c:      	br	x17

00000000000a3790 <_ZN8mtlabar316LayerInteraction12getTimestampEv@plt>:
   a3790:      	adrp	x16, 0xab000
   a3794:      	ldr	x17, [x16, #0xb10]
   a3798:      	add	x16, x16, #0xb10
   a379c:      	br	x17

00000000000a37a0 <_ZN8mtlabar316LayerInteraction13setVisibilityEb@plt>:
   a37a0:      	adrp	x16, 0xab000
   a37a4:      	ldr	x17, [x16, #0xb18]
   a37a8:      	add	x16, x16, #0xb18
   a37ac:      	br	x17

00000000000a37b0 <_ZN8mtlabar316LayerInteraction13getVisibilityEv@plt>:
   a37b0:      	adrp	x16, 0xab000
   a37b4:      	ldr	x17, [x16, #0xb20]
   a37b8:      	add	x16, x16, #0xb20
   a37bc:      	br	x17

00000000000a37c0 <_ZN8mtlabar316LayerInteraction8setAlphaEf@plt>:
   a37c0:      	adrp	x16, 0xab000
   a37c4:      	ldr	x17, [x16, #0xb28]
   a37c8:      	add	x16, x16, #0xb28
   a37cc:      	br	x17

00000000000a37d0 <_ZN8mtlabar316LayerInteraction8getAlphaEv@plt>:
   a37d0:      	adrp	x16, 0xab000
   a37d4:      	ldr	x17, [x16, #0xb30]
   a37d8:      	add	x16, x16, #0xb30
   a37dc:      	br	x17

00000000000a37e0 <_ZN8mtlabar316LayerInteraction14setScissorRectENS_5RectIE@plt>:
   a37e0:      	adrp	x16, 0xab000
   a37e4:      	ldr	x17, [x16, #0xb38]
   a37e8:      	add	x16, x16, #0xb38
   a37ec:      	br	x17

00000000000a37f0 <_ZN8mtlabar316LayerInteraction14getScissorRectEv@plt>:
   a37f0:      	adrp	x16, 0xab000
   a37f4:      	ldr	x17, [x16, #0xb40]
   a37f8:      	add	x16, x16, #0xb40
   a37fc:      	br	x17

00000000000a3800 <_ZN8mtlabar316LayerInteraction12setBlendModeENS_14LayerBlendModeE@plt>:
   a3800:      	adrp	x16, 0xab000
   a3804:      	ldr	x17, [x16, #0xb48]
   a3808:      	add	x16, x16, #0xb48
   a380c:      	br	x17

00000000000a3810 <_ZN8mtlabar316LayerInteraction12getBlendModeEv@plt>:
   a3810:      	adrp	x16, 0xab000
   a3814:      	ldr	x17, [x16, #0xb50]
   a3818:      	add	x16, x16, #0xb50
   a381c:      	br	x17

00000000000a3820 <_ZN8mtlabar316LayerInteraction17setEnableSelectedEb@plt>:
   a3820:      	adrp	x16, 0xab000
   a3824:      	ldr	x17, [x16, #0xb58]
   a3828:      	add	x16, x16, #0xb58
   a382c:      	br	x17

00000000000a3830 <_ZN8mtlabar316LayerInteraction17getEnableSelectedEv@plt>:
   a3830:      	adrp	x16, 0xab000
   a3834:      	ldr	x17, [x16, #0xb60]
   a3838:      	add	x16, x16, #0xb60
   a383c:      	br	x17

00000000000a3840 <_ZN8mtlabar316LayerInteraction13getLockScreenEv@plt>:
   a3840:      	adrp	x16, 0xab000
   a3844:      	ldr	x17, [x16, #0xb68]
   a3848:      	add	x16, x16, #0xb68
   a384c:      	br	x17

00000000000a3850 <_ZN8mtlabar316LayerInteraction20getDesignedDraggableEv@plt>:
   a3850:      	adrp	x16, 0xab000
   a3854:      	ldr	x17, [x16, #0xb70]
   a3858:      	add	x16, x16, #0xb70
   a385c:      	br	x17

00000000000a3860 <_ZN8mtlabar316LayerInteraction26getDesignedForceSelectableEv@plt>:
   a3860:      	adrp	x16, 0xab000
   a3864:      	ldr	x17, [x16, #0xb78]
   a3868:      	add	x16, x16, #0xb78
   a386c:      	br	x17

00000000000a3870 <_ZN8mtlabar316LayerInteraction16getIsEnableDepthEv@plt>:
   a3870:      	adrp	x16, 0xab000
   a3874:      	ldr	x17, [x16, #0xb80]
   a3878:      	add	x16, x16, #0xb80
   a387c:      	br	x17

00000000000a3880 <_ZN8mtlabar316LayerInteraction14setEnableDepthEb@plt>:
   a3880:      	adrp	x16, 0xab000
   a3884:      	ldr	x17, [x16, #0xb88]
   a3888:      	add	x16, x16, #0xb88
   a388c:      	br	x17

00000000000a3890 <_ZN8mtlabar316LayerInteraction27setIsCurrentRenderThumbnailEb@plt>:
   a3890:      	adrp	x16, 0xab000
   a3894:      	ldr	x17, [x16, #0xb90]
   a3898:      	add	x16, x16, #0xb90
   a389c:      	br	x17

00000000000a38a0 <_ZN8mtlabar316LayerInteraction27getIsCurrentRenderThumbnailEv@plt>:
   a38a0:      	adrp	x16, 0xab000
   a38a4:      	ldr	x17, [x16, #0xb98]
   a38a8:      	add	x16, x16, #0xb98
   a38ac:      	br	x17

00000000000a38b0 <_ZN8mtlabar325TextStructConfigInterface7destroyEPS0_@plt>:
   a38b0:      	adrp	x16, 0xab000
   a38b4:      	ldr	x17, [x16, #0xba0]
   a38b8:      	add	x16, x16, #0xba0
   a38bc:      	br	x17

00000000000a38c0 <_ZNK8mtlabar325TextStructConfigInterface14getDefaultSizeEv@plt>:
   a38c0:      	adrp	x16, 0xab000
   a38c4:      	ldr	x17, [x16, #0xba8]
   a38c8:      	add	x16, x16, #0xba8
   a38cc:      	br	x17

00000000000a38d0 <_ZN8mtlabar325TextStructConfigInterface15getSubTextLayerEm@plt>:
   a38d0:      	adrp	x16, 0xab000
   a38d4:      	ldr	x17, [x16, #0xbb0]
   a38d8:      	add	x16, x16, #0xbb0
   a38dc:      	br	x17

00000000000a38e0 <_ZN8mtlabar325TextStructConfigInterface19getSubTextLayerSizeEv@plt>:
   a38e0:      	adrp	x16, 0xab000
   a38e4:      	ldr	x17, [x16, #0xbb8]
   a38e8:      	add	x16, x16, #0xbb8
   a38ec:      	br	x17

00000000000a38f0 <_ZN8mtlabar320InteractionInterface12resizeCanvasERKNS_14CanvasPropertyE@plt>:
   a38f0:      	adrp	x16, 0xab000
   a38f4:      	ldr	x17, [x16, #0xbc0]
   a38f8:      	add	x16, x16, #0xbc0
   a38fc:      	br	x17

00000000000a3900 <_ZN8mtlabar320InteractionInterface17getCanvasPropertyEv@plt>:
   a3900:      	adrp	x16, 0xab000
   a3904:      	ldr	x17, [x16, #0xbc8]
   a3908:      	add	x16, x16, #0xbc8
   a390c:      	br	x17

00000000000a3910 <_ZN8mtlabar320InteractionInterface8dispatchEv@plt>:
   a3910:      	adrp	x16, 0xab000
   a3914:      	ldr	x17, [x16, #0xbd0]
   a3918:      	add	x16, x16, #0xbd0
   a391c:      	br	x17

00000000000a3920 <_ZN8mtlabar320InteractionInterface9sortLayerEv@plt>:
   a3920:      	adrp	x16, 0xab000
   a3924:      	ldr	x17, [x16, #0xbd8]
   a3928:      	add	x16, x16, #0xbd8
   a392c:      	br	x17

00000000000a3930 <_ZN8mtlabar320InteractionInterface9findLayerEPv@plt>:
   a3930:      	adrp	x16, 0xab000
   a3934:      	ldr	x17, [x16, #0xbe0]
   a3938:      	add	x16, x16, #0xbe0
   a393c:      	br	x17

00000000000a3940 <_ZN8mtlabar39TextUtils13graphemeSplitERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS1_6vectorIS7_NS5_IS7_EEEE@plt>:
   a3940:      	adrp	x16, 0xab000
   a3944:      	ldr	x17, [x16, #0xbe8]
   a3948:      	add	x16, x16, #0xbe8
   a394c:      	br	x17

00000000000a3950 <_ZN8mtlabar39TextUtils19parseTextPathConfigEPKc@plt>:
   a3950:      	adrp	x16, 0xab000
   a3954:      	ldr	x17, [x16, #0xbf0]
   a3958:      	add	x16, x16, #0xbf0
   a395c:      	br	x17

00000000000a3960 <_ZN8mtlabar39TextUtils20parseTextLayerConfigEPKc@plt>:
   a3960:      	adrp	x16, 0xab000
   a3964:      	ldr	x17, [x16, #0xbf8]
   a3968:      	add	x16, x16, #0xbf8
   a396c:      	br	x17

00000000000a3970 <_ZN8mtlabar39TextUtils19parseTextNoteDetailEPKc@plt>:
   a3970:      	adrp	x16, 0xab000
   a3974:      	ldr	x17, [x16, #0xc00]
   a3978:      	add	x16, x16, #0xc00
   a397c:      	br	x17

00000000000a3980 <_ZN8mtlabar39TextUtils19parseJsonNoteDetailEPKc@plt>:
   a3980:      	adrp	x16, 0xab000
   a3984:      	ldr	x17, [x16, #0xc08]
   a3988:      	add	x16, x16, #0xc08
   a398c:      	br	x17

00000000000a3990 <_ZN8mtlabar39TextUtils19parseTextWarpConfigEPKc@plt>:
   a3990:      	adrp	x16, 0xab000
   a3994:      	ldr	x17, [x16, #0xc10]
   a3998:      	add	x16, x16, #0xc10
   a399c:      	br	x17

00000000000a39a0 <_ZN8mtlabar39TextUtils20parseAnimationConfigEPKc@plt>:
   a39a0:      	adrp	x16, 0xab000
   a39a4:      	ldr	x17, [x16, #0xc18]
   a39a8:      	add	x16, x16, #0xc18
   a39ac:      	br	x17

00000000000a39b0 <_ZNK8mtlabar311DataRequire22requireSourceGrayImageEv@plt>:
   a39b0:      	adrp	x16, 0xab000
   a39b4:      	ldr	x17, [x16, #0xc20]
   a39b8:      	add	x16, x16, #0xc20
   a39bc:      	br	x17

00000000000a39c0 <_ZNK8mtlabar311DataRequire23requireSourceColorImageEv@plt>:
   a39c0:      	adrp	x16, 0xab000
   a39c4:      	ldr	x17, [x16, #0xc28]
   a39c8:      	add	x16, x16, #0xc28
   a39cc:      	br	x17

00000000000a39d0 <_ZNK8mtlabar311DataRequire21requireSourceImageGPUEv@plt>:
   a39d0:      	adrp	x16, 0xab000
   a39d4:      	ldr	x17, [x16, #0xc30]
   a39d8:      	add	x16, x16, #0xc30
   a39dc:      	br	x17

00000000000a39e0 <_ZNK8mtlabar311DataRequire20requireTouchListenerEv@plt>:
   a39e0:      	adrp	x16, 0xab000
   a39e4:      	ldr	x17, [x16, #0xc38]
   a39e8:      	add	x16, x16, #0xc38
   a39ec:      	br	x17

00000000000a39f0 <_ZNK8mtlabar311DataRequire17requireAnimalDataEv@plt>:
   a39f0:      	adrp	x16, 0xab000
   a39f4:      	ldr	x17, [x16, #0xc40]
   a39f8:      	add	x16, x16, #0xc40
   a39fc:      	br	x17

00000000000a3a00 <_ZNK8mtlabar311DataRequire15requireFoodDataEv@plt>:
   a3a00:      	adrp	x16, 0xab000
   a3a04:      	ldr	x17, [x16, #0xc48]
   a3a08:      	add	x16, x16, #0xc48
   a3a0c:      	br	x17

00000000000a3a10 <_ZNK8mtlabar311DataRequire15requireFaceDataEv@plt>:
   a3a10:      	adrp	x16, 0xab000
   a3a14:      	ldr	x17, [x16, #0xc50]
   a3a18:      	add	x16, x16, #0xc50
   a3a1c:      	br	x17

00000000000a3a20 <_ZNK8mtlabar311DataRequire40requireFaceDataAdditionLimitMaxFaceCountEv@plt>:
   a3a20:      	adrp	x16, 0xab000
   a3a24:      	ldr	x17, [x16, #0xc58]
   a3a28:      	add	x16, x16, #0xc58
   a3a2c:      	br	x17

00000000000a3a30 <_ZNK8mtlabar311DataRequire27requireFaceDataAdditionHeadEv@plt>:
   a3a30:      	adrp	x16, 0xab000
   a3a34:      	ldr	x17, [x16, #0xc60]
   a3a38:      	add	x16, x16, #0xc60
   a3a3c:      	br	x17

00000000000a3a40 <_ZNK8mtlabar311DataRequire26requireFaceDataAdditionEarEv@plt>:
   a3a40:      	adrp	x16, 0xab000
   a3a44:      	ldr	x17, [x16, #0xc68]
   a3a48:      	add	x16, x16, #0xc68
   a3a4c:      	br	x17

00000000000a3a50 <_ZNK8mtlabar311DataRequire27requireFaceDataAdditionNeckEv@plt>:
   a3a50:      	adrp	x16, 0xab000
   a3a54:      	ldr	x17, [x16, #0xc70]
   a3a58:      	add	x16, x16, #0xc70
   a3a5c:      	br	x17

00000000000a3a60 <_ZNK8mtlabar311DataRequire32requireFaceDataAdditionMouthMaskEv@plt>:
   a3a60:      	adrp	x16, 0xab000
   a3a64:      	ldr	x17, [x16, #0xc78]
   a3a68:      	add	x16, x16, #0xc78
   a3a6c:      	br	x17

00000000000a3a70 <_ZNK8mtlabar311DataRequire31requireFaceDataAdditionFaceMaskEv@plt>:
   a3a70:      	adrp	x16, 0xab000
   a3a74:      	ldr	x17, [x16, #0xc80]
   a3a78:      	add	x16, x16, #0xc80
   a3a7c:      	br	x17

00000000000a3a80 <_ZNK8mtlabar311DataRequire35requireFaceDataAdditionPosEstimatorEv@plt>:
   a3a80:      	adrp	x16, 0xab000
   a3a84:      	ldr	x17, [x16, #0xc88]
   a3a88:      	add	x16, x16, #0xc88
   a3a8c:      	br	x17

00000000000a3a90 <_ZNK8mtlabar311DataRequire29requireFaceDataAdditionGenderEv@plt>:
   a3a90:      	adrp	x16, 0xab000
   a3a94:      	ldr	x17, [x16, #0xc90]
   a3a98:      	add	x16, x16, #0xc90
   a3a9c:      	br	x17

00000000000a3aa0 <_ZNK8mtlabar311DataRequire26requireFaceDataAdditionAgeEv@plt>:
   a3aa0:      	adrp	x16, 0xab000
   a3aa4:      	ldr	x17, [x16, #0xc98]
   a3aa8:      	add	x16, x16, #0xc98
   a3aac:      	br	x17

00000000000a3ab0 <_ZNK8mtlabar311DataRequire29requireFaceDataAdditionEyelidEv@plt>:
   a3ab0:      	adrp	x16, 0xab000
   a3ab4:      	ldr	x17, [x16, #0xca0]
   a3ab8:      	add	x16, x16, #0xca0
   a3abc:      	br	x17

00000000000a3ac0 <_ZNK8mtlabar311DataRequire30requireFaceDataAdditionEmotionEv@plt>:
   a3ac0:      	adrp	x16, 0xab000
   a3ac4:      	ldr	x17, [x16, #0xca8]
   a3ac8:      	add	x16, x16, #0xca8
   a3acc:      	br	x17

00000000000a3ad0 <_ZNK8mtlabar311DataRequire27requireFaceDataAddition3DFAEv@plt>:
   a3ad0:      	adrp	x16, 0xab000
   a3ad4:      	ldr	x17, [x16, #0xcb0]
   a3ad8:      	add	x16, x16, #0xcb0
   a3adc:      	br	x17

00000000000a3ae0 <_ZNK8mtlabar311DataRequire31requireFaceDataAddition3DFAMeshEv@plt>:
   a3ae0:      	adrp	x16, 0xab000
   a3ae4:      	ldr	x17, [x16, #0xcb8]
   a3ae8:      	add	x16, x16, #0xcb8
   a3aec:      	br	x17

00000000000a3af0 <_ZNK8mtlabar311DataRequire34requireFaceDataAdditionMakeupAdaptEv@plt>:
   a3af0:      	adrp	x16, 0xab000
   a3af4:      	ldr	x17, [x16, #0xcc0]
   a3af8:      	add	x16, x16, #0xcc0
   a3afc:      	br	x17

00000000000a3b00 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV1DataEv@plt>:
   a3b00:      	adrp	x16, 0xab000
   a3b04:      	ldr	x17, [x16, #0xcc8]
   a3b08:      	add	x16, x16, #0xcc8
   a3b0c:      	br	x17

00000000000a3b10 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV2DataEv@plt>:
   a3b10:      	adrp	x16, 0xab000
   a3b14:      	ldr	x17, [x16, #0xcd0]
   a3b18:      	add	x16, x16, #0xcd0
   a3b1c:      	br	x17

00000000000a3b20 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV3DataEv@plt>:
   a3b20:      	adrp	x16, 0xab000
   a3b24:      	ldr	x17, [x16, #0xcd8]
   a3b28:      	add	x16, x16, #0xcd8
   a3b2c:      	br	x17

00000000000a3b30 <_ZNK8mtlabar311DataRequire40requireFace2DBackgroundReconstructorDataEv@plt>:
   a3b30:      	adrp	x16, 0xab000
   a3b34:      	ldr	x17, [x16, #0xce0]
   a3b38:      	add	x16, x16, #0xce0
   a3b3c:      	br	x17

00000000000a3b40 <_ZNK8mtlabar311DataRequire30requireFace3DReconstructorDataEv@plt>:
   a3b40:      	adrp	x16, 0xab000
   a3b44:      	ldr	x17, [x16, #0xce8]
   a3b48:      	add	x16, x16, #0xce8
   a3b4c:      	br	x17

00000000000a3b50 <_ZNK8mtlabar311DataRequire46requireFace3DReconstructorDataAdditionFovAngleEv@plt>:
   a3b50:      	adrp	x16, 0xab000
   a3b54:      	ldr	x17, [x16, #0xcf0]
   a3b58:      	add	x16, x16, #0xcf0
   a3b5c:      	br	x17

00000000000a3b60 <_ZNK8mtlabar311DataRequire19requireFaceDL3DDataEv@plt>:
   a3b60:      	adrp	x16, 0xab000
   a3b64:      	ldr	x17, [x16, #0xcf8]
   a3b68:      	add	x16, x16, #0xcf8
   a3b6c:      	br	x17

00000000000a3b70 <_ZNK8mtlabar311DataRequire31requireFaceDL3DDataAdditionMeshEv@plt>:
   a3b70:      	adrp	x16, 0xab000
   a3b74:      	ldr	x17, [x16, #0xd00]
   a3b78:      	add	x16, x16, #0xd00
   a3b7c:      	br	x17

00000000000a3b80 <_ZNK8mtlabar311DataRequire39requireFaceDL3DDataAdditionPosEstimatorEv@plt>:
   a3b80:      	adrp	x16, 0xab000
   a3b84:      	ldr	x17, [x16, #0xd08]
   a3b88:      	add	x16, x16, #0xd08
   a3b8c:      	br	x17

00000000000a3b90 <_ZNK8mtlabar311DataRequire43requireFaceDL3DDataAdditionBlendShapeFactorEv@plt>:
   a3b90:      	adrp	x16, 0xab000
   a3b94:      	ldr	x17, [x16, #0xd10]
   a3b98:      	add	x16, x16, #0xd10
   a3b9c:      	br	x17

00000000000a3ba0 <_ZNK8mtlabar311DataRequire34requireFaceDL3DDataAdditionRiggingEv@plt>:
   a3ba0:      	adrp	x16, 0xab000
   a3ba4:      	ldr	x17, [x16, #0xd18]
   a3ba8:      	add	x16, x16, #0xd18
   a3bac:      	br	x17

00000000000a3bb0 <_ZNK8mtlabar311DataRequire19requireShoulderDataEv@plt>:
   a3bb0:      	adrp	x16, 0xab000
   a3bb4:      	ldr	x17, [x16, #0xd20]
   a3bb8:      	add	x16, x16, #0xd20
   a3bbc:      	br	x17

00000000000a3bc0 <_ZNK8mtlabar311DataRequire15requireHandDataEv@plt>:
   a3bc0:      	adrp	x16, 0xab000
   a3bc4:      	ldr	x17, [x16, #0xd28]
   a3bc8:      	add	x16, x16, #0xd28
   a3bcc:      	br	x17

00000000000a3bd0 <_ZNK8mtlabar311DataRequire40requireHandDataAdditionLimitMaxHandCountEv@plt>:
   a3bd0:      	adrp	x16, 0xab000
   a3bd4:      	ldr	x17, [x16, #0xd30]
   a3bd8:      	add	x16, x16, #0xd30
   a3bdc:      	br	x17

00000000000a3be0 <_ZNK8mtlabar311DataRequire27requireHandDataAdditionPoseEv@plt>:
   a3be0:      	adrp	x16, 0xab000
   a3be4:      	ldr	x17, [x16, #0xd38]
   a3be8:      	add	x16, x16, #0xd38
   a3bec:      	br	x17

00000000000a3bf0 <_ZNK8mtlabar311DataRequire16requireNailsDataEv@plt>:
   a3bf0:      	adrp	x16, 0xab000
   a3bf4:      	ldr	x17, [x16, #0xd40]
   a3bf8:      	add	x16, x16, #0xd40
   a3bfc:      	br	x17

00000000000a3c00 <_ZNK8mtlabar311DataRequire15requireBodyMaskEv@plt>:
   a3c00:      	adrp	x16, 0xab000
   a3c04:      	ldr	x17, [x16, #0xd48]
   a3c08:      	add	x16, x16, #0xd48
   a3c0c:      	br	x17

00000000000a3c10 <_ZNK8mtlabar311DataRequire26requireBodyMaskAdditionCPUEv@plt>:
   a3c10:      	adrp	x16, 0xab000
   a3c14:      	ldr	x17, [x16, #0xd50]
   a3c18:      	add	x16, x16, #0xd50
   a3c1c:      	br	x17

00000000000a3c20 <_ZNK8mtlabar311DataRequire26requireBodyMaskAdditionGPUEv@plt>:
   a3c20:      	adrp	x16, 0xab000
   a3c24:      	ldr	x17, [x16, #0xd58]
   a3c28:      	add	x16, x16, #0xd58
   a3c2c:      	br	x17

00000000000a3c30 <_ZNK8mtlabar311DataRequire15requireHairMaskEv@plt>:
   a3c30:      	adrp	x16, 0xab000
   a3c34:      	ldr	x17, [x16, #0xd60]
   a3c38:      	add	x16, x16, #0xd60
   a3c3c:      	br	x17

00000000000a3c40 <_ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv@plt>:
   a3c40:      	adrp	x16, 0xab000
   a3c44:      	ldr	x17, [x16, #0xd68]
   a3c48:      	add	x16, x16, #0xd68
   a3c4c:      	br	x17

00000000000a3c50 <_ZNK8mtlabar311DataRequire26requireHairMaskAdditionGPUEv@plt>:
   a3c50:      	adrp	x16, 0xab000
   a3c54:      	ldr	x17, [x16, #0xd70]
   a3c58:      	add	x16, x16, #0xd70
   a3c5c:      	br	x17

00000000000a3c60 <_ZNK8mtlabar311DataRequire14requireSkyMaskEv@plt>:
   a3c60:      	adrp	x16, 0xab000
   a3c64:      	ldr	x17, [x16, #0xd78]
   a3c68:      	add	x16, x16, #0xd78
   a3c6c:      	br	x17

00000000000a3c70 <_ZNK8mtlabar311DataRequire25requireSkyMaskAdditionCPUEv@plt>:
   a3c70:      	adrp	x16, 0xab000
   a3c74:      	ldr	x17, [x16, #0xd80]
   a3c78:      	add	x16, x16, #0xd80
   a3c7c:      	br	x17

00000000000a3c80 <_ZNK8mtlabar311DataRequire25requireSkyMaskAdditionGPUEv@plt>:
   a3c80:      	adrp	x16, 0xab000
   a3c84:      	ldr	x17, [x16, #0xd88]
   a3c88:      	add	x16, x16, #0xd88
   a3c8c:      	br	x17

00000000000a3c90 <_ZNK8mtlabar311DataRequire15requireSkinMaskEv@plt>:
   a3c90:      	adrp	x16, 0xab000
   a3c94:      	ldr	x17, [x16, #0xd90]
   a3c98:      	add	x16, x16, #0xd90
   a3c9c:      	br	x17

00000000000a3ca0 <_ZNK8mtlabar311DataRequire26requireSkinMaskAdditionCPUEv@plt>:
   a3ca0:      	adrp	x16, 0xab000
   a3ca4:      	ldr	x17, [x16, #0xd98]
   a3ca8:      	add	x16, x16, #0xd98
   a3cac:      	br	x17

00000000000a3cb0 <_ZNK8mtlabar311DataRequire26requireSkinMaskAdditionGPUEv@plt>:
   a3cb0:      	adrp	x16, 0xab000
   a3cb4:      	ldr	x17, [x16, #0xda0]
   a3cb8:      	add	x16, x16, #0xda0
   a3cbc:      	br	x17

00000000000a3cc0 <_ZNK8mtlabar311DataRequire15requireHeadMaskEv@plt>:
   a3cc0:      	adrp	x16, 0xab000
   a3cc4:      	ldr	x17, [x16, #0xda8]
   a3cc8:      	add	x16, x16, #0xda8
   a3ccc:      	br	x17

00000000000a3cd0 <_ZNK8mtlabar311DataRequire26requireHeadMaskAdditionCPUEv@plt>:
   a3cd0:      	adrp	x16, 0xab000
   a3cd4:      	ldr	x17, [x16, #0xdb0]
   a3cd8:      	add	x16, x16, #0xdb0
   a3cdc:      	br	x17

00000000000a3ce0 <_ZNK8mtlabar311DataRequire26requireHeadMaskAdditionGPUEv@plt>:
   a3ce0:      	adrp	x16, 0xab000
   a3ce4:      	ldr	x17, [x16, #0xdb8]
   a3ce8:      	add	x16, x16, #0xdb8
   a3cec:      	br	x17

00000000000a3cf0 <_ZNK8mtlabar311DataRequire16requireNevusMaskEv@plt>:
   a3cf0:      	adrp	x16, 0xab000
   a3cf4:      	ldr	x17, [x16, #0xdc0]
   a3cf8:      	add	x16, x16, #0xdc0
   a3cfc:      	br	x17

00000000000a3d00 <_ZNK8mtlabar311DataRequire27requireNevusMaskAdditionCPUEv@plt>:
   a3d00:      	adrp	x16, 0xab000
   a3d04:      	ldr	x17, [x16, #0xdc8]
   a3d08:      	add	x16, x16, #0xdc8
   a3d0c:      	br	x17

00000000000a3d10 <_ZNK8mtlabar311DataRequire27requireNevusMaskAdditionGPUEv@plt>:
   a3d10:      	adrp	x16, 0xab000
   a3d14:      	ldr	x17, [x16, #0xdd0]
   a3d18:      	add	x16, x16, #0xdd0
   a3d1c:      	br	x17

00000000000a3d20 <_ZNK8mtlabar311DataRequire22requireFaceContourMaskEv@plt>:
   a3d20:      	adrp	x16, 0xab000
   a3d24:      	ldr	x17, [x16, #0xdd8]
   a3d28:      	add	x16, x16, #0xdd8
   a3d2c:      	br	x17

00000000000a3d30 <_ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionCPUEv@plt>:
   a3d30:      	adrp	x16, 0xab000
   a3d34:      	ldr	x17, [x16, #0xde0]
   a3d38:      	add	x16, x16, #0xde0
   a3d3c:      	br	x17

00000000000a3d40 <_ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionGPUEv@plt>:
   a3d40:      	adrp	x16, 0xab000
   a3d44:      	ldr	x17, [x16, #0xde8]
   a3d48:      	add	x16, x16, #0xde8
   a3d4c:      	br	x17

00000000000a3d50 <_ZNK8mtlabar311DataRequire16requireClothMaskEv@plt>:
   a3d50:      	adrp	x16, 0xab000
   a3d54:      	ldr	x17, [x16, #0xdf0]
   a3d58:      	add	x16, x16, #0xdf0
   a3d5c:      	br	x17

00000000000a3d60 <_ZNK8mtlabar311DataRequire27requireClothMaskAdditionCPUEv@plt>:
   a3d60:      	adrp	x16, 0xab000
   a3d64:      	ldr	x17, [x16, #0xdf8]
   a3d68:      	add	x16, x16, #0xdf8
   a3d6c:      	br	x17

00000000000a3d70 <_ZNK8mtlabar311DataRequire27requireClothMaskAdditionGPUEv@plt>:
   a3d70:      	adrp	x16, 0xab000
   a3d74:      	ldr	x17, [x16, #0xe00]
   a3d78:      	add	x16, x16, #0xe00
   a3d7c:      	br	x17

00000000000a3d80 <_ZNK8mtlabar311DataRequire23requireFaceNeckLineMaskEv@plt>:
   a3d80:      	adrp	x16, 0xab000
   a3d84:      	ldr	x17, [x16, #0xe08]
   a3d88:      	add	x16, x16, #0xe08
   a3d8c:      	br	x17

00000000000a3d90 <_ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionCPUEv@plt>:
   a3d90:      	adrp	x16, 0xab000
   a3d94:      	ldr	x17, [x16, #0xe10]
   a3d98:      	add	x16, x16, #0xe10
   a3d9c:      	br	x17

00000000000a3da0 <_ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionGPUEv@plt>:
   a3da0:      	adrp	x16, 0xab000
   a3da4:      	ldr	x17, [x16, #0xe18]
   a3da8:      	add	x16, x16, #0xe18
   a3dac:      	br	x17

00000000000a3db0 <_ZNK8mtlabar311DataRequire14requireEyeMaskEv@plt>:
   a3db0:      	adrp	x16, 0xab000
   a3db4:      	ldr	x17, [x16, #0xe20]
   a3db8:      	add	x16, x16, #0xe20
   a3dbc:      	br	x17

00000000000a3dc0 <_ZNK8mtlabar311DataRequire11requireBodyEv@plt>:
   a3dc0:      	adrp	x16, 0xab000
   a3dc4:      	ldr	x17, [x16, #0xe28]
   a3dc8:      	add	x16, x16, #0xe28
   a3dcc:      	br	x17

00000000000a3dd0 <_ZNK8mtlabar311DataRequire16requireBodyInOneEv@plt>:
   a3dd0:      	adrp	x16, 0xab000
   a3dd4:      	ldr	x17, [x16, #0xe30]
   a3dd8:      	add	x16, x16, #0xe30
   a3ddc:      	br	x17

00000000000a3de0 <_ZNK8mtlabar311DataRequire24requireBodyAdditionHumanEv@plt>:
   a3de0:      	adrp	x16, 0xab000
   a3de4:      	ldr	x17, [x16, #0xe38]
   a3de8:      	add	x16, x16, #0xe38
   a3dec:      	br	x17

00000000000a3df0 <_ZNK8mtlabar311DataRequire24requireBodyAdditionJointEv@plt>:
   a3df0:      	adrp	x16, 0xab000
   a3df4:      	ldr	x17, [x16, #0xe40]
   a3df8:      	add	x16, x16, #0xe40
   a3dfc:      	br	x17

00000000000a3e00 <_ZNK8mtlabar311DataRequire26requireBodyAdditionContourEv@plt>:
   a3e00:      	adrp	x16, 0xab000
   a3e04:      	ldr	x17, [x16, #0xe48]
   a3e08:      	add	x16, x16, #0xe48
   a3e0c:      	br	x17

00000000000a3e10 <_ZNK8mtlabar311DataRequire28requireARGyroscopeQuaternionEv@plt>:
   a3e10:      	adrp	x16, 0xab000
   a3e14:      	ldr	x17, [x16, #0xe50]
   a3e18:      	add	x16, x16, #0xe50
   a3e1c:      	br	x17

00000000000a3e20 <_ZNK8mtlabar311DataRequire17requireARFaceMeshEv@plt>:
   a3e20:      	adrp	x16, 0xab000
   a3e24:      	ldr	x17, [x16, #0xe58]
   a3e28:      	add	x16, x16, #0xe58
   a3e2c:      	br	x17

00000000000a3e30 <_ZNK8mtlabar311DataRequire19requireARPointCloudEv@plt>:
   a3e30:      	adrp	x16, 0xab000
   a3e34:      	ldr	x17, [x16, #0xe60]
   a3e38:      	add	x16, x16, #0xe60
   a3e3c:      	br	x17

00000000000a3e40 <_ZNK8mtlabar311DataRequire22requireARWorldTrackingEv@plt>:
   a3e40:      	adrp	x16, 0xab000
   a3e44:      	ldr	x17, [x16, #0xe68]
   a3e48:      	add	x16, x16, #0xe68
   a3e4c:      	br	x17

00000000000a3e50 <_ZNK8mtlabar311DataRequire20requireARPlaneAnchorEv@plt>:
   a3e50:      	adrp	x16, 0xab000
   a3e54:      	ldr	x17, [x16, #0xe70]
   a3e58:      	add	x16, x16, #0xe70
   a3e5c:      	br	x17

00000000000a3e60 <_ZNK8mtlabar311DataRequire22requireARLightEstimateEv@plt>:
   a3e60:      	adrp	x16, 0xab000
   a3e64:      	ldr	x17, [x16, #0xe78]
   a3e68:      	add	x16, x16, #0xe78
   a3e6c:      	br	x17

00000000000a3e70 <_ZNK8mtlabar311DataRequire25requireARInstantPlacementEv@plt>:
   a3e70:      	adrp	x16, 0xab000
   a3e74:      	ldr	x17, [x16, #0xe80]
   a3e78:      	add	x16, x16, #0xe80
   a3e7c:      	br	x17

00000000000a3e80 <_ZNK8mtlabar311DataRequire17requireARSkeletonEv@plt>:
   a3e80:      	adrp	x16, 0xab000
   a3e84:      	ldr	x17, [x16, #0xe88]
   a3e88:      	add	x16, x16, #0xe88
   a3e8c:      	br	x17

00000000000a3e90 <_ZNK8mtlabar311DataRequire9requireCGEv@plt>:
   a3e90:      	adrp	x16, 0xab000
   a3e94:      	ldr	x17, [x16, #0xe90]
   a3e98:      	add	x16, x16, #0xe90
   a3e9c:      	br	x17

00000000000a3ea0 <_ZNK8mtlabar311DataRequire20requireCGAdditionCPUEv@plt>:
   a3ea0:      	adrp	x16, 0xab000
   a3ea4:      	ldr	x17, [x16, #0xe98]
   a3ea8:      	add	x16, x16, #0xe98
   a3eac:      	br	x17

00000000000a3eb0 <_ZNK8mtlabar311DataRequire20requireCGAdditionGPUEv@plt>:
   a3eb0:      	adrp	x16, 0xab000
   a3eb4:      	ldr	x17, [x16, #0xea0]
   a3eb8:      	add	x16, x16, #0xea0
   a3ebc:      	br	x17

00000000000a3ec0 <_ZNK8mtlabar311DataRequire24requireCompactBeautyDataEv@plt>:
   a3ec0:      	adrp	x16, 0xab000
   a3ec4:      	ldr	x17, [x16, #0xea8]
   a3ec8:      	add	x16, x16, #0xea8
   a3ecc:      	br	x17

00000000000a3ed0 <_ZNK8mtlabar311DataRequire14requireHuman3DEv@plt>:
   a3ed0:      	adrp	x16, 0xab000
   a3ed4:      	ldr	x17, [x16, #0xeb0]
   a3ed8:      	add	x16, x16, #0xeb0
   a3edc:      	br	x17

00000000000a3ee0 <_ZNK8mtlabar311DataRequire17requireSpaceDepthEv@plt>:
   a3ee0:      	adrp	x16, 0xab000
   a3ee4:      	ldr	x17, [x16, #0xeb8]
   a3ee8:      	add	x16, x16, #0xeb8
   a3eec:      	br	x17

00000000000a3ef0 <_ZNK8mtlabar311DataRequire18requireSpaceNormalEv@plt>:
   a3ef0:      	adrp	x16, 0xab000
   a3ef4:      	ldr	x17, [x16, #0xec0]
   a3ef8:      	add	x16, x16, #0xec0
   a3efc:      	br	x17

00000000000a3f00 <_ZNK8mtlabar311DataRequire22requireInteractiveMaskEv@plt>:
   a3f00:      	adrp	x16, 0xab000
   a3f04:      	ldr	x17, [x16, #0xec8]
   a3f08:      	add	x16, x16, #0xec8
   a3f0c:      	br	x17

00000000000a3f10 <_ZNK8mtlabar311DataRequire22requireOutStandingMaskEv@plt>:
   a3f10:      	adrp	x16, 0xab000
   a3f14:      	ldr	x17, [x16, #0xed0]
   a3f18:      	add	x16, x16, #0xed0
   a3f1c:      	br	x17

00000000000a3f20 <_ZNK8mtlabar311DataRequire24requireMultiInstanceMaskEv@plt>:
   a3f20:      	adrp	x16, 0xab000
   a3f24:      	ldr	x17, [x16, #0xed8]
   a3f28:      	add	x16, x16, #0xed8
   a3f2c:      	br	x17

00000000000a3f30 <_ZNK8mtlabar311DataRequire22requireUserDefinedMaskEv@plt>:
   a3f30:      	adrp	x16, 0xab000
   a3f34:      	ldr	x17, [x16, #0xee0]
   a3f38:      	add	x16, x16, #0xee0
   a3f3c:      	br	x17

00000000000a3f40 <_ZNK8mtlabar311DataRequire33requireBodySlim3DAbundantButtocksEv@plt>:
   a3f40:      	adrp	x16, 0xab000
   a3f44:      	ldr	x17, [x16, #0xee8]
   a3f48:      	add	x16, x16, #0xee8
   a3f4c:      	br	x17

00000000000a3f50 <_ZNK8mtlabar311DataRequire34requireBodySlim3DThinLowerAbdomensEv@plt>:
   a3f50:      	adrp	x16, 0xab000
   a3f54:      	ldr	x17, [x16, #0xef0]
   a3f58:      	add	x16, x16, #0xef0
   a3f5c:      	br	x17

00000000000a3f60 <_ZNK8mtlabar311DataRequire30requireBodySlim3DShoulderBraceEv@plt>:
   a3f60:      	adrp	x16, 0xab000
   a3f64:      	ldr	x17, [x16, #0xef8]
   a3f68:      	add	x16, x16, #0xef8
   a3f6c:      	br	x17

00000000000a3f70 <_ZNK8mtlabar311DataRequire27requireBodySlim3DBreastLiftEv@plt>:
   a3f70:      	adrp	x16, 0xab000
   a3f74:      	ldr	x17, [x16, #0xf00]
   a3f78:      	add	x16, x16, #0xf00
   a3f7c:      	br	x17

00000000000a3f80 <_ZNK8mtlabar311DataRequire25requireBodySlim3DButtLiftEv@plt>:
   a3f80:      	adrp	x16, 0xab000
   a3f84:      	ldr	x17, [x16, #0xf08]
   a3f88:      	add	x16, x16, #0xf08
   a3f8c:      	br	x17

00000000000a3f90 <_ZNK8mtlabar311DataRequire32requireBodySlim3DAbundantBreastsEv@plt>:
   a3f90:      	adrp	x16, 0xab000
   a3f94:      	ldr	x17, [x16, #0xf10]
   a3f98:      	add	x16, x16, #0xf10
   a3f9c:      	br	x17

00000000000a3fa0 <_ZNK8mtlabar311DataRequire32requireBodySlim3DBreastReductionEv@plt>:
   a3fa0:      	adrp	x16, 0xab000
   a3fa4:      	ldr	x17, [x16, #0xf18]
   a3fa8:      	add	x16, x16, #0xf18
   a3fac:      	br	x17

00000000000a3fb0 <_ZNK8mtlabar311DataRequire26requireBodySlim3DTrapeziusEv@plt>:
   a3fb0:      	adrp	x16, 0xab000
   a3fb4:      	ldr	x17, [x16, #0xf20]
   a3fb8:      	add	x16, x16, #0xf20
   a3fbc:      	br	x17

00000000000a3fc0 <_ZNK8mtlabar311DataRequire26requireBodyBeautyBGFillingEv@plt>:
   a3fc0:      	adrp	x16, 0xab000
   a3fc4:      	ldr	x17, [x16, #0xf28]
   a3fc8:      	add	x16, x16, #0xf28
   a3fcc:      	br	x17

00000000000a3fd0 <_ZN8mtlabar312HumanControl13getGenderTypeEv@plt>:
   a3fd0:      	adrp	x16, 0xab000
   a3fd4:      	ldr	x17, [x16, #0xf30]
   a3fd8:      	add	x16, x16, #0xf30
   a3fdc:      	br	x17

00000000000a3fe0 <_ZN8mtlabar312HumanControl13setGenderTypeENS_14FaceGenderTypeE@plt>:
   a3fe0:      	adrp	x16, 0xab000
   a3fe4:      	ldr	x17, [x16, #0xf38]
   a3fe8:      	add	x16, x16, #0xf38
   a3fec:      	br	x17

00000000000a3ff0 <_ZN8mtlabar312HumanControl10getFaceIDsEv@plt>:
   a3ff0:      	adrp	x16, 0xab000
   a3ff4:      	ldr	x17, [x16, #0xf40]
   a3ff8:      	add	x16, x16, #0xf40
   a3ffc:      	br	x17

00000000000a4000 <_ZN8mtlabar312HumanControl10setFaceIDsERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
   a4000:      	adrp	x16, 0xab000
   a4004:      	ldr	x17, [x16, #0xf48]
   a4008:      	add	x16, x16, #0xf48
   a400c:      	br	x17

00000000000a4010 <_ZN8mtlabar321MakeupControlInstance16getControlFaceIDEv@plt>:
   a4010:      	adrp	x16, 0xab000
   a4014:      	ldr	x17, [x16, #0xf50]
   a4018:      	add	x16, x16, #0xf50
   a401c:      	br	x17

00000000000a4020 <_ZN8mtlabar321MakeupControlInstance12setPartAlphaEf@plt>:
   a4020:      	adrp	x16, 0xab000
   a4024:      	ldr	x17, [x16, #0xf58]
   a4028:      	add	x16, x16, #0xf58
   a402c:      	br	x17

00000000000a4030 <_ZN8mtlabar321MakeupControlInstance12getPartAlphaEv@plt>:
   a4030:      	adrp	x16, 0xab000
   a4034:      	ldr	x17, [x16, #0xf60]
   a4038:      	add	x16, x16, #0xf60
   a403c:      	br	x17

00000000000a4040 <_ZN8mtlabar321MakeupControlInstance10setOpacityEf@plt>:
   a4040:      	adrp	x16, 0xab000
   a4044:      	ldr	x17, [x16, #0xf68]
   a4048:      	add	x16, x16, #0xf68
   a404c:      	br	x17

00000000000a4050 <_ZN8mtlabar321MakeupControlInstance10getOpacityEv@plt>:
   a4050:      	adrp	x16, 0xab000
   a4054:      	ldr	x17, [x16, #0xf70]
   a4058:      	add	x16, x16, #0xf70
   a405c:      	br	x17

00000000000a4060 <_ZN8mtlabar321MakeupControlInstance9setColorAERKNS_6ColorAE@plt>:
   a4060:      	adrp	x16, 0xab000
   a4064:      	ldr	x17, [x16, #0xf78]
   a4068:      	add	x16, x16, #0xf78
   a406c:      	br	x17

00000000000a4070 <_ZNK8mtlabar321MakeupControlInstance9getColorAEv@plt>:
   a4070:      	adrp	x16, 0xab000
   a4074:      	ldr	x17, [x16, #0xf80]
   a4078:      	add	x16, x16, #0xf80
   a407c:      	br	x17

00000000000a4080 <_ZN8mtlabar313MakeupControl20getMakeupControlTypeEv@plt>:
   a4080:      	adrp	x16, 0xab000
   a4084:      	ldr	x17, [x16, #0xf88]
   a4088:      	add	x16, x16, #0xf88
   a408c:      	br	x17

00000000000a4090 <_ZN8mtlabar313MakeupControl25getMakeupControlTypeChildEv@plt>:
   a4090:      	adrp	x16, 0xab000
   a4094:      	ldr	x17, [x16, #0xf90]
   a4098:      	add	x16, x16, #0xf90
   a409c:      	br	x17

00000000000a40a0 <_ZN8mtlabar313MakeupControl24getMakeupControlInstanceEi@plt>:
   a40a0:      	adrp	x16, 0xab000
   a40a4:      	ldr	x17, [x16, #0xf98]
   a40a8:      	add	x16, x16, #0xf98
   a40ac:      	br	x17

00000000000a40b0 <_ZN8mtlabar313MakeupControl19getDefaultPartAlphaEv@plt>:
   a40b0:      	adrp	x16, 0xab000
   a40b4:      	ldr	x17, [x16, #0xfa0]
   a40b8:      	add	x16, x16, #0xfa0
   a40bc:      	br	x17

00000000000a40c0 <_ZN8mtlabar313MakeupControl17getDefaultOpacityEv@plt>:
   a40c0:      	adrp	x16, 0xab000
   a40c4:      	ldr	x17, [x16, #0xfa8]
   a40c8:      	add	x16, x16, #0xfa8
   a40cc:      	br	x17

00000000000a40d0 <_ZNK8mtlabar313MakeupControl9getColorAEv@plt>:
   a40d0:      	adrp	x16, 0xab000
   a40d4:      	ldr	x17, [x16, #0xfb0]
   a40d8:      	add	x16, x16, #0xfb0
   a40dc:      	br	x17

00000000000a40e0 <_ZN8mtlabar313MakeupControl30getNoFaceMakeupControlInstanceEv@plt>:
   a40e0:      	adrp	x16, 0xab000
   a40e4:      	ldr	x17, [x16, #0xfb8]
   a40e8:      	add	x16, x16, #0xfb8
   a40ec:      	br	x17

00000000000a40f0 <_ZN8mtlabar313MakeupControl25getIsStaticOpacityControlEv@plt>:
   a40f0:      	adrp	x16, 0xab000
   a40f4:      	ldr	x17, [x16, #0xfc0]
   a40f8:      	add	x16, x16, #0xfc0
   a40fc:      	br	x17

00000000000a4100 <_ZN8mtlabar322EyeSideControlInstance16getControlFaceIDEv@plt>:
   a4100:      	adrp	x16, 0xab000
   a4104:      	ldr	x17, [x16, #0xfc8]
   a4108:      	add	x16, x16, #0xfc8
   a410c:      	br	x17

00000000000a4110 <_ZN8mtlabar322EyeSideControlInstance12setPartAlphaEf@plt>:
   a4110:      	adrp	x16, 0xab000
   a4114:      	ldr	x17, [x16, #0xfd0]
   a4118:      	add	x16, x16, #0xfd0
   a411c:      	br	x17

00000000000a4120 <_ZN8mtlabar322EyeSideControlInstance12getPartAlphaEv@plt>:
   a4120:      	adrp	x16, 0xab000
   a4124:      	ldr	x17, [x16, #0xfd8]
   a4128:      	add	x16, x16, #0xfd8
   a412c:      	br	x17

00000000000a4130 <_ZN8mtlabar314EyeSideControl20getMakeupControlTypeEv@plt>:
   a4130:      	adrp	x16, 0xab000
   a4134:      	ldr	x17, [x16, #0xfe0]
   a4138:      	add	x16, x16, #0xfe0
   a413c:      	br	x17

00000000000a4140 <_ZN8mtlabar314EyeSideControl17getMakeupSideTypeEv@plt>:
   a4140:      	adrp	x16, 0xab000
   a4144:      	ldr	x17, [x16, #0xfe8]
   a4148:      	add	x16, x16, #0xfe8
   a414c:      	br	x17

00000000000a4150 <_ZN8mtlabar314EyeSideControl25getEyeSideControlInstanceEi@plt>:
   a4150:      	adrp	x16, 0xab000
   a4154:      	ldr	x17, [x16, #0xff0]
   a4158:      	add	x16, x16, #0xff0
   a415c:      	br	x17

00000000000a4160 <_ZN8mtlabar314FaceliftSlider16getControlFaceIDEv@plt>:
   a4160:      	adrp	x16, 0xab000
   a4164:      	ldr	x17, [x16, #0xff8]
   a4168:      	add	x16, x16, #0xff8
   a416c:      	br	x17

00000000000a4170 <_ZNK8mtlabar314FaceliftSlider17getControlKeyNameEv@plt>:
   a4170:      	adrp	x16, 0xac000
   a4174:      	ldr	x17, [x16]
   a4178:      	add	x16, x16, #0x0
   a417c:      	br	x17

00000000000a4180 <_ZNK8mtlabar314FaceliftSlider15getDefaultValueEv@plt>:
   a4180:      	adrp	x16, 0xac000
   a4184:      	ldr	x17, [x16, #0x8]
   a4188:      	add	x16, x16, #0x8
   a418c:      	br	x17

00000000000a4190 <_ZNK8mtlabar314FaceliftSlider8getValueEv@plt>:
   a4190:      	adrp	x16, 0xac000
   a4194:      	ldr	x17, [x16, #0x10]
   a4198:      	add	x16, x16, #0x10
   a419c:      	br	x17

00000000000a41a0 <_ZNK8mtlabar314FaceliftSlider11getMinValueEv@plt>:
   a41a0:      	adrp	x16, 0xac000
   a41a4:      	ldr	x17, [x16, #0x18]
   a41a8:      	add	x16, x16, #0x18
   a41ac:      	br	x17

00000000000a41b0 <_ZNK8mtlabar314FaceliftSlider11getMaxValueEv@plt>:
   a41b0:      	adrp	x16, 0xac000
   a41b4:      	ldr	x17, [x16, #0x20]
   a41b8:      	add	x16, x16, #0x20
   a41bc:      	br	x17

00000000000a41c0 <_ZN8mtlabar314FaceliftSlider8setValueEf@plt>:
   a41c0:      	adrp	x16, 0xac000
   a41c4:      	ldr	x17, [x16, #0x28]
   a41c8:      	add	x16, x16, #0x28
   a41cc:      	br	x17

00000000000a41d0 <_ZNK8mtlabar314FaceliftSlider27getNeutralizeTheEffectValueEv@plt>:
   a41d0:      	adrp	x16, 0xac000
   a41d4:      	ldr	x17, [x16, #0x30]
   a41d8:      	add	x16, x16, #0x30
   a41dc:      	br	x17

00000000000a41e0 <_ZNK8mtlabar323FaceliftControlInstance23getFaceliftControlCountEv@plt>:
   a41e0:      	adrp	x16, 0xac000
   a41e4:      	ldr	x17, [x16, #0x38]
   a41e8:      	add	x16, x16, #0x38
   a41ec:      	br	x17

00000000000a41f0 <_ZNK8mtlabar323FaceliftControlInstance25getFaceliftControlKeyNameEm@plt>:
   a41f0:      	adrp	x16, 0xac000
   a41f4:      	ldr	x17, [x16, #0x40]
   a41f8:      	add	x16, x16, #0x40
   a41fc:      	br	x17

00000000000a4200 <_ZN8mtlabar323FaceliftControlInstance26getFaceliftSliderByKeyNameEPKc@plt>:
   a4200:      	adrp	x16, 0xac000
   a4204:      	ldr	x17, [x16, #0x48]
   a4208:      	add	x16, x16, #0x48
   a420c:      	br	x17

00000000000a4210 <_ZN8mtlabar323FaceliftControlInstance24getFaceliftSliderByIndexEm@plt>:
   a4210:      	adrp	x16, 0xac000
   a4214:      	ldr	x17, [x16, #0x50]
   a4218:      	add	x16, x16, #0x50
   a421c:      	br	x17

00000000000a4220 <_ZNK8mtlabar315FaceliftControl23getFaceliftControlCountEv@plt>:
   a4220:      	adrp	x16, 0xac000
   a4224:      	ldr	x17, [x16, #0x58]
   a4228:      	add	x16, x16, #0x58
   a422c:      	br	x17

00000000000a4230 <_ZNK8mtlabar315FaceliftControl25getFaceliftControlKeyNameEm@plt>:
   a4230:      	adrp	x16, 0xac000
   a4234:      	ldr	x17, [x16, #0x60]
   a4238:      	add	x16, x16, #0x60
   a423c:      	br	x17

00000000000a4240 <_ZN8mtlabar315FaceliftControl26getFaceliftControlInstanceEi@plt>:
   a4240:      	adrp	x16, 0xac000
   a4244:      	ldr	x17, [x16, #0x68]
   a4248:      	add	x16, x16, #0x68
   a424c:      	br	x17

00000000000a4250 <_ZN8mtlabar315FaceliftControl19clearAllSliderValueEi@plt>:
   a4250:      	adrp	x16, 0xac000
   a4254:      	ldr	x17, [x16, #0x70]
   a4258:      	add	x16, x16, #0x70
   a425c:      	br	x17

00000000000a4260 <_ZN8mtlabar319BodySlimEffectState19getMaximumDataCountEv@plt>:
   a4260:      	adrp	x16, 0xac000
   a4264:      	ldr	x17, [x16, #0x78]
   a4268:      	add	x16, x16, #0x78
   a426c:      	br	x17

00000000000a4270 <_ZN8mtlabar319BodySlimEffectState18getDistEffectStateENS_19BodySlimControlTypeEl@plt>:
   a4270:      	adrp	x16, 0xac000
   a4274:      	ldr	x17, [x16, #0x80]
   a4278:      	add	x16, x16, #0x80
   a427c:      	br	x17

00000000000a4280 <_ZN8mtlabar332AutomaticBodySlimControlInstance28isSupportForMultiDataControlEv@plt>:
   a4280:      	adrp	x16, 0xac000
   a4284:      	ldr	x17, [x16, #0x88]
   a4288:      	add	x16, x16, #0x88
   a428c:      	br	x17

00000000000a4290 <_ZN8mtlabar332AutomaticBodySlimControlInstance26getMaximumSupportDataCountEv@plt>:
   a4290:      	adrp	x16, 0xac000
   a4294:      	ldr	x17, [x16, #0x90]
   a4298:      	add	x16, x16, #0x90
   a429c:      	br	x17

00000000000a42a0 <_ZN8mtlabar332AutomaticBodySlimControlInstance12setValueByIdElf@plt>:
   a42a0:      	adrp	x16, 0xac000
   a42a4:      	ldr	x17, [x16, #0x98]
   a42a8:      	add	x16, x16, #0x98
   a42ac:      	br	x17

00000000000a42b0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance12getValueByIdEl@plt>:
   a42b0:      	adrp	x16, 0xac000
   a42b4:      	ldr	x17, [x16, #0xa0]
   a42b8:      	add	x16, x16, #0xa0
   a42bc:      	br	x17

00000000000a42c0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance15getDefaultValueEv@plt>:
   a42c0:      	adrp	x16, 0xac000
   a42c4:      	ldr	x17, [x16, #0xa8]
   a42c8:      	add	x16, x16, #0xa8
   a42cc:      	br	x17

00000000000a42d0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance11getMinValueEv@plt>:
   a42d0:      	adrp	x16, 0xac000
   a42d4:      	ldr	x17, [x16, #0xb0]
   a42d8:      	add	x16, x16, #0xb0
   a42dc:      	br	x17

00000000000a42e0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance11getMaxValueEv@plt>:
   a42e0:      	adrp	x16, 0xac000
   a42e4:      	ldr	x17, [x16, #0xb8]
   a42e8:      	add	x16, x16, #0xb8
   a42ec:      	br	x17

00000000000a42f0 <_ZN8mtlabar332AutomaticBodySlimControlInstance13clearValueMapEv@plt>:
   a42f0:      	adrp	x16, 0xac000
   a42f4:      	ldr	x17, [x16, #0xc0]
   a42f8:      	add	x16, x16, #0xc0
   a42fc:      	br	x17

00000000000a4300 <_ZN8mtlabar329ManualBodySlimControlInstance28isSupportForMultiDataControlEv@plt>:
   a4300:      	adrp	x16, 0xac000
   a4304:      	ldr	x17, [x16, #0xc8]
   a4308:      	add	x16, x16, #0xc8
   a430c:      	br	x17

00000000000a4310 <_ZN8mtlabar329ManualBodySlimControlInstance12getParamTypeEv@plt>:
   a4310:      	adrp	x16, 0xac000
   a4314:      	ldr	x17, [x16, #0xd0]
   a4318:      	add	x16, x16, #0xd0
   a431c:      	br	x17

00000000000a4320 <_ZN8mtlabar329ManualBodySlimControlInstance23setManualRectangleParamEPNS_23BodySlimManualRectangleEi@plt>:
   a4320:      	adrp	x16, 0xac000
   a4324:      	ldr	x17, [x16, #0xd8]
   a4328:      	add	x16, x16, #0xd8
   a432c:      	br	x17

00000000000a4330 <_ZN8mtlabar329ManualBodySlimControlInstance18setManualLineParamEPNS_18BodySlimManualLineEi@plt>:
   a4330:      	adrp	x16, 0xac000
   a4334:      	ldr	x17, [x16, #0xe0]
   a4338:      	add	x16, x16, #0xe0
   a433c:      	br	x17

00000000000a4340 <_ZN8mtlabar329ManualBodySlimControlInstance19setManualRoundParamEPNS_19BodySlimManualRoundEi@plt>:
   a4340:      	adrp	x16, 0xac000
   a4344:      	ldr	x17, [x16, #0xe8]
   a4348:      	add	x16, x16, #0xe8
   a434c:      	br	x17

00000000000a4350 <_ZN8mtlabar323BodySlimControlInstance20setEffectIsEffectiveEb@plt>:
   a4350:      	adrp	x16, 0xac000
   a4354:      	ldr	x17, [x16, #0xf0]
   a4358:      	add	x16, x16, #0xf0
   a435c:      	br	x17

00000000000a4360 <_ZN8mtlabar323BodySlimControlInstance20getEffectIsEffectiveEv@plt>:
   a4360:      	adrp	x16, 0xac000
   a4364:      	ldr	x17, [x16, #0xf8]
   a4368:      	add	x16, x16, #0xf8
   a436c:      	br	x17

00000000000a4370 <_ZN8mtlabar323BodySlimControlInstance14getControlTypeEv@plt>:
   a4370:      	adrp	x16, 0xac000
   a4374:      	ldr	x17, [x16, #0x100]
   a4378:      	add	x16, x16, #0x100
   a437c:      	br	x17

00000000000a4380 <_ZN8mtlabar323BodySlimControlInstance12getParamTypeEv@plt>:
   a4380:      	adrp	x16, 0xac000
   a4384:      	ldr	x17, [x16, #0x108]
   a4388:      	add	x16, x16, #0x108
   a438c:      	br	x17

00000000000a4390 <_ZN8mtlabar323BodySlimControlInstance32getManualBodySlimControlInstanceEv@plt>:
   a4390:      	adrp	x16, 0xac000
   a4394:      	ldr	x17, [x16, #0x110]
   a4398:      	add	x16, x16, #0x110
   a439c:      	br	x17

00000000000a43a0 <_ZN8mtlabar323BodySlimControlInstance35getAutomaticBodySlimControlInstanceEv@plt>:
   a43a0:      	adrp	x16, 0xac000
   a43a4:      	ldr	x17, [x16, #0x118]
   a43a8:      	add	x16, x16, #0x118
   a43ac:      	br	x17

00000000000a43b0 <_ZNK8mtlabar315BodySlimControl23getBodySlimControlCountEv@plt>:
   a43b0:      	adrp	x16, 0xac000
   a43b4:      	ldr	x17, [x16, #0x120]
   a43b8:      	add	x16, x16, #0x120
   a43bc:      	br	x17

00000000000a43c0 <_ZN8mtlabar315BodySlimControl25getBodySlimControlByIndexEm@plt>:
   a43c0:      	adrp	x16, 0xac000
   a43c4:      	ldr	x17, [x16, #0x128]
   a43c8:      	add	x16, x16, #0x128
   a43cc:      	br	x17

00000000000a43d0 <_ZN8mtlabar315BodySlimControl24getBodySlimControlByTypeENS_19BodySlimControlTypeE@plt>:
   a43d0:      	adrp	x16, 0xac000
   a43d4:      	ldr	x17, [x16, #0x130]
   a43d8:      	add	x16, x16, #0x130
   a43dc:      	br	x17

00000000000a43e0 <_ZN8mtlabar315BodySlimControl24getBodySlimOperateSwitchEv@plt>:
   a43e0:      	adrp	x16, 0xac000
   a43e4:      	ldr	x17, [x16, #0x138]
   a43e8:      	add	x16, x16, #0x138
   a43ec:      	br	x17

00000000000a43f0 <_ZN8mtlabar315BodySlimControl24setBodySlimOperateSwitchEl@plt>:
   a43f0:      	adrp	x16, 0xac000
   a43f4:      	ldr	x17, [x16, #0x140]
   a43f8:      	add	x16, x16, #0x140
   a43fc:      	br	x17

00000000000a4400 <_ZN8mtlabar315BodySlimControl22getTransformationPointEPfi@plt>:
   a4400:      	adrp	x16, 0xac000
   a4404:      	ldr	x17, [x16, #0x148]
   a4408:      	add	x16, x16, #0x148
   a440c:      	br	x17

00000000000a4410 <_ZN8mtlabar315BodySlimControl22getBodySlimEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4410:      	adrp	x16, 0xac000
   a4414:      	ldr	x17, [x16, #0x150]
   a4418:      	add	x16, x16, #0x150
   a441c:      	br	x17

00000000000a4420 <_ZN8mtlabar315BodySlimControl32getMultiModelBodySlimEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4420:      	adrp	x16, 0xac000
   a4424:      	ldr	x17, [x16, #0x158]
   a4428:      	add	x16, x16, #0x158
   a442c:      	br	x17

00000000000a4430 <_ZN8mtlabar315BodySlimControl20switchToSigModelDataEb@plt>:
   a4430:      	adrp	x16, 0xac000
   a4434:      	ldr	x17, [x16, #0x160]
   a4438:      	add	x16, x16, #0x160
   a443c:      	br	x17

00000000000a4440 <_ZN8mtlabar315BodySlimControl19enforceSigModelDataEb@plt>:
   a4440:      	adrp	x16, 0xac000
   a4444:      	ldr	x17, [x16, #0x168]
   a4448:      	add	x16, x16, #0x168
   a444c:      	br	x17

00000000000a4450 <_ZN8mtlabar315BodySlimControl25isSigModelIsNeckExistenceEPNS_18FrameDataInterfaceE@plt>:
   a4450:      	adrp	x16, 0xac000
   a4454:      	ldr	x17, [x16, #0x170]
   a4458:      	add	x16, x16, #0x170
   a445c:      	br	x17

00000000000a4460 <_ZN8mtlabar315BodySlimControl27isMultiModelIsNeckExistenceEPNS_18FrameDataInterfaceE@plt>:
   a4460:      	adrp	x16, 0xac000
   a4464:      	ldr	x17, [x16, #0x178]
   a4468:      	add	x16, x16, #0x178
   a446c:      	br	x17

00000000000a4470 <_ZN8mtlabar315BodySlimControl29isSigModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE@plt>:
   a4470:      	adrp	x16, 0xac000
   a4474:      	ldr	x17, [x16, #0x180]
   a4478:      	add	x16, x16, #0x180
   a447c:      	br	x17

00000000000a4480 <_ZN8mtlabar315BodySlimControl31isMultiModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE@plt>:
   a4480:      	adrp	x16, 0xac000
   a4484:      	ldr	x17, [x16, #0x188]
   a4488:      	add	x16, x16, #0x188
   a448c:      	br	x17

00000000000a4490 <_ZN8mtlabar315BodySlimControl32isSigModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE@plt>:
   a4490:      	adrp	x16, 0xac000
   a4494:      	ldr	x17, [x16, #0x190]
   a4498:      	add	x16, x16, #0x190
   a449c:      	br	x17

00000000000a44a0 <_ZN8mtlabar315BodySlimControl34isMultiModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE@plt>:
   a44a0:      	adrp	x16, 0xac000
   a44a4:      	ldr	x17, [x16, #0x198]
   a44a8:      	add	x16, x16, #0x198
   a44ac:      	br	x17

00000000000a44b0 <_ZN8mtlabar318ShoulderMLSControl8setValueEf@plt>:
   a44b0:      	adrp	x16, 0xac000
   a44b4:      	ldr	x17, [x16, #0x1a0]
   a44b8:      	add	x16, x16, #0x1a0
   a44bc:      	br	x17

00000000000a44c0 <_ZNK8mtlabar318ShoulderMLSControl8getValueEv@plt>:
   a44c0:      	adrp	x16, 0xac000
   a44c4:      	ldr	x17, [x16, #0x1a8]
   a44c8:      	add	x16, x16, #0x1a8
   a44cc:      	br	x17

00000000000a44d0 <_ZNK8mtlabar318ShoulderMLSControl15getDefaultValueEv@plt>:
   a44d0:      	adrp	x16, 0xac000
   a44d4:      	ldr	x17, [x16, #0x1b0]
   a44d8:      	add	x16, x16, #0x1b0
   a44dc:      	br	x17

00000000000a44e0 <_ZN8mtlabar318ShoulderMLSControl25getShoulderMLSEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a44e0:      	adrp	x16, 0xac000
   a44e4:      	ldr	x17, [x16, #0x1b8]
   a44e8:      	add	x16, x16, #0x1b8
   a44ec:      	br	x17

00000000000a44f0 <_ZN8mtlabar316HipDeformControl23getHipDeformEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a44f0:      	adrp	x16, 0xac000
   a44f4:      	ldr	x17, [x16, #0x1c0]
   a44f8:      	add	x16, x16, #0x1c0
   a44fc:      	br	x17

00000000000a4500 <_ZN8mtlabar315SwanNeckControl22getSwanNeckEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4500:      	adrp	x16, 0xac000
   a4504:      	ldr	x17, [x16, #0x1c8]
   a4508:      	add	x16, x16, #0x1c8
   a450c:      	br	x17

00000000000a4510 <_ZN8mtlabar322BodyShapingPartControl22getUpperArmEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4510:      	adrp	x16, 0xac000
   a4514:      	ldr	x17, [x16, #0x1d0]
   a4518:      	add	x16, x16, #0x1d0
   a451c:      	br	x17

00000000000a4520 <_ZN8mtlabar322BodyShapingPartControl21getForearmEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4520:      	adrp	x16, 0xac000
   a4524:      	ldr	x17, [x16, #0x1d8]
   a4528:      	add	x16, x16, #0x1d8
   a452c:      	br	x17

00000000000a4530 <_ZN8mtlabar322BodyShapingPartControl19getThighEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4530:      	adrp	x16, 0xac000
   a4534:      	ldr	x17, [x16, #0x1e0]
   a4538:      	add	x16, x16, #0x1e0
   a453c:      	br	x17

00000000000a4540 <_ZN8mtlabar322BodyShapingPartControl18getCalfEffectStateEPNS_18FrameDataInterfaceE@plt>:
   a4540:      	adrp	x16, 0xac000
   a4544:      	ldr	x17, [x16, #0x1e8]
   a4548:      	add	x16, x16, #0x1e8
   a454c:      	br	x17

00000000000a4550 <_ZN8mtlabar314StickerControl20setStickerAlphaValueEf@plt>:
   a4550:      	adrp	x16, 0xac000
   a4554:      	ldr	x17, [x16, #0x1f0]
   a4558:      	add	x16, x16, #0x1f0
   a455c:      	br	x17

00000000000a4560 <_ZNK8mtlabar314StickerControl20getStickerAlphaValueEv@plt>:
   a4560:      	adrp	x16, 0xac000
   a4564:      	ldr	x17, [x16, #0x1f8]
   a4568:      	add	x16, x16, #0x1f8
   a456c:      	br	x17

00000000000a4570 <_ZNK8mtlabar314StickerControl27getStickerDefaultAlphaValueEv@plt>:
   a4570:      	adrp	x16, 0xac000
   a4574:      	ldr	x17, [x16, #0x200]
   a4578:      	add	x16, x16, #0x200
   a457c:      	br	x17

00000000000a4580 <_ZN8mtlabar314StickerControl13setStickerFPSEj@plt>:
   a4580:      	adrp	x16, 0xac000
   a4584:      	ldr	x17, [x16, #0x208]
   a4588:      	add	x16, x16, #0x208
   a458c:      	br	x17

00000000000a4590 <_ZNK8mtlabar314StickerControl13getStickerFPSEv@plt>:
   a4590:      	adrp	x16, 0xac000
   a4594:      	ldr	x17, [x16, #0x210]
   a4598:      	add	x16, x16, #0x210
   a459c:      	br	x17

00000000000a45a0 <_ZN8mtlabar314StickerControl14setStickerSizeEf@plt>:
   a45a0:      	adrp	x16, 0xac000
   a45a4:      	ldr	x17, [x16, #0x218]
   a45a8:      	add	x16, x16, #0x218
   a45ac:      	br	x17

00000000000a45b0 <_ZNK8mtlabar314StickerControl14getStickerSizeEv@plt>:
   a45b0:      	adrp	x16, 0xac000
   a45b4:      	ldr	x17, [x16, #0x220]
   a45b8:      	add	x16, x16, #0x220
   a45bc:      	br	x17

00000000000a45c0 <_ZN8mtlabar314StickerControl24setStickerVerticalOffsetEf@plt>:
   a45c0:      	adrp	x16, 0xac000
   a45c4:      	ldr	x17, [x16, #0x228]
   a45c8:      	add	x16, x16, #0x228
   a45cc:      	br	x17

00000000000a45d0 <_ZNK8mtlabar314StickerControl24getStickerVerticalOffsetEv@plt>:
   a45d0:      	adrp	x16, 0xac000
   a45d4:      	ldr	x17, [x16, #0x230]
   a45d8:      	add	x16, x16, #0x230
   a45dc:      	br	x17

00000000000a45e0 <_ZN8mtlabar314StickerControl26setStickerHorizontalOffsetEf@plt>:
   a45e0:      	adrp	x16, 0xac000
   a45e4:      	ldr	x17, [x16, #0x238]
   a45e8:      	add	x16, x16, #0x238
   a45ec:      	br	x17

00000000000a45f0 <_ZNK8mtlabar314StickerControl26getStickerHorizontalOffsetEv@plt>:
   a45f0:      	adrp	x16, 0xac000
   a45f4:      	ldr	x17, [x16, #0x240]
   a45f8:      	add	x16, x16, #0x240
   a45fc:      	br	x17

00000000000a4600 <_ZN8mtlabar311ToneControl15setCurrentValueENS_8ToneTypeEf@plt>:
   a4600:      	adrp	x16, 0xac000
   a4604:      	ldr	x17, [x16, #0x248]
   a4608:      	add	x16, x16, #0x248
   a460c:      	br	x17

00000000000a4610 <_ZNK8mtlabar311ToneControl15getCurrentValueENS_8ToneTypeE@plt>:
   a4610:      	adrp	x16, 0xac000
   a4614:      	ldr	x17, [x16, #0x250]
   a4618:      	add	x16, x16, #0x250
   a461c:      	br	x17

00000000000a4620 <_ZNK8mtlabar311ToneControl15getDefaultValueENS_8ToneTypeE@plt>:
   a4620:      	adrp	x16, 0xac000
   a4624:      	ldr	x17, [x16, #0x258]
   a4628:      	add	x16, x16, #0x258
   a462c:      	br	x17

00000000000a4630 <_ZNK8mtlabar311ToneControl11getMaxValueENS_8ToneTypeE@plt>:
   a4630:      	adrp	x16, 0xac000
   a4634:      	ldr	x17, [x16, #0x260]
   a4638:      	add	x16, x16, #0x260
   a463c:      	br	x17

00000000000a4640 <_ZNK8mtlabar311ToneControl11getMinValueENS_8ToneTypeE@plt>:
   a4640:      	adrp	x16, 0xac000
   a4644:      	ldr	x17, [x16, #0x268]
   a4648:      	add	x16, x16, #0x268
   a464c:      	br	x17

00000000000a4650 <_ZN8mtlabar311ToneControl8resetAllEv@plt>:
   a4650:      	adrp	x16, 0xac000
   a4654:      	ldr	x17, [x16, #0x270]
   a4658:      	add	x16, x16, #0x270
   a465c:      	br	x17

00000000000a4660 <_ZN8mtlabar310HSLControl15setCurrentValueENS_12HSLColorTypeEfff@plt>:
   a4660:      	adrp	x16, 0xac000
   a4664:      	ldr	x17, [x16, #0x278]
   a4668:      	add	x16, x16, #0x278
   a466c:      	br	x17

00000000000a4670 <_ZNK8mtlabar310HSLControl15getCurrentValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   a4670:      	adrp	x16, 0xac000
   a4674:      	ldr	x17, [x16, #0x280]
   a4678:      	add	x16, x16, #0x280
   a467c:      	br	x17

00000000000a4680 <_ZNK8mtlabar310HSLControl15getDefaultValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   a4680:      	adrp	x16, 0xac000
   a4684:      	ldr	x17, [x16, #0x288]
   a4688:      	add	x16, x16, #0x288
   a468c:      	br	x17

00000000000a4690 <_ZNK8mtlabar310HSLControl11getMaxValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   a4690:      	adrp	x16, 0xac000
   a4694:      	ldr	x17, [x16, #0x290]
   a4698:      	add	x16, x16, #0x290
   a469c:      	br	x17

00000000000a46a0 <_ZNK8mtlabar310HSLControl11getMinValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   a46a0:      	adrp	x16, 0xac000
   a46a4:      	ldr	x17, [x16, #0x298]
   a46a8:      	add	x16, x16, #0x298
   a46ac:      	br	x17

00000000000a46b0 <_ZN8mtlabar310HSLControl8resetAllEv@plt>:
   a46b0:      	adrp	x16, 0xac000
   a46b4:      	ldr	x17, [x16, #0x2a0]
   a46b8:      	add	x16, x16, #0x2a0
   a46bc:      	br	x17

00000000000a46c0 <_ZN8mtlabar316PickColorControl8getIndexEfff@plt>:
   a46c0:      	adrp	x16, 0xac000
   a46c4:      	ldr	x17, [x16, #0x2a8]
   a46c8:      	add	x16, x16, #0x2a8
   a46cc:      	br	x17

00000000000a46d0 <_ZN8mtlabar316PickColorControl15setCurrentValueEmfff@plt>:
   a46d0:      	adrp	x16, 0xac000
   a46d4:      	ldr	x17, [x16, #0x2b0]
   a46d8:      	add	x16, x16, #0x2b0
   a46dc:      	br	x17

00000000000a46e0 <_ZNK8mtlabar316PickColorControl15getCurrentValueEmPfS1_S1_@plt>:
   a46e0:      	adrp	x16, 0xac000
   a46e4:      	ldr	x17, [x16, #0x2b8]
   a46e8:      	add	x16, x16, #0x2b8
   a46ec:      	br	x17

00000000000a46f0 <_ZNK8mtlabar316PickColorControl15getDefaultValueEPfS1_S1_@plt>:
   a46f0:      	adrp	x16, 0xac000
   a46f4:      	ldr	x17, [x16, #0x2c0]
   a46f8:      	add	x16, x16, #0x2c0
   a46fc:      	br	x17

00000000000a4700 <_ZNK8mtlabar316PickColorControl11getMaxValueEPfS1_S1_@plt>:
   a4700:      	adrp	x16, 0xac000
   a4704:      	ldr	x17, [x16, #0x2c8]
   a4708:      	add	x16, x16, #0x2c8
   a470c:      	br	x17

00000000000a4710 <_ZNK8mtlabar316PickColorControl11getMinValueEPfS1_S1_@plt>:
   a4710:      	adrp	x16, 0xac000
   a4714:      	ldr	x17, [x16, #0x2d0]
   a4718:      	add	x16, x16, #0x2d0
   a471c:      	br	x17

00000000000a4720 <_ZN8mtlabar316PickColorControl10removeItemEm@plt>:
   a4720:      	adrp	x16, 0xac000
   a4724:      	ldr	x17, [x16, #0x2d8]
   a4728:      	add	x16, x16, #0x2d8
   a472c:      	br	x17

00000000000a4730 <_ZN8mtlabar316PickColorControl5clearEv@plt>:
   a4730:      	adrp	x16, 0xac000
   a4734:      	ldr	x17, [x16, #0x2e0]
   a4738:      	add	x16, x16, #0x2e0
   a473c:      	br	x17

00000000000a4740 <_ZN8mtlabar313ToningControl14getToneControlEv@plt>:
   a4740:      	adrp	x16, 0xac000
   a4744:      	ldr	x17, [x16, #0x2e8]
   a4748:      	add	x16, x16, #0x2e8
   a474c:      	br	x17

00000000000a4750 <_ZN8mtlabar313ToningControl13getHSLControlEv@plt>:
   a4750:      	adrp	x16, 0xac000
   a4754:      	ldr	x17, [x16, #0x2f0]
   a4758:      	add	x16, x16, #0x2f0
   a475c:      	br	x17

00000000000a4760 <_ZN8mtlabar313ToningControl19getPickColorControlEv@plt>:
   a4760:      	adrp	x16, 0xac000
   a4764:      	ldr	x17, [x16, #0x2f8]
   a4768:      	add	x16, x16, #0x2f8
   a476c:      	br	x17

00000000000a4770 <_ZN8mtlabar320MVBronzersPenControl20getSourceMaskTextureEl@plt>:
   a4770:      	adrp	x16, 0xac000
   a4774:      	ldr	x17, [x16, #0x300]
   a4778:      	add	x16, x16, #0x300
   a477c:      	br	x17

00000000000a4780 <_ZN8mtlabar320MVBronzersPenControl23getStandFaceMaskTextureEl@plt>:
   a4780:      	adrp	x16, 0xac000
   a4784:      	ldr	x17, [x16, #0x308]
   a4788:      	add	x16, x16, #0x308
   a478c:      	br	x17

00000000000a4790 <_ZN8mtlabar320MVBronzersPenControl25getStandFaceEffectTextureEl@plt>:
   a4790:      	adrp	x16, 0xac000
   a4794:      	ldr	x17, [x16, #0x310]
   a4798:      	add	x16, x16, #0x310
   a479c:      	br	x17

00000000000a47a0 <_ZN8mtlabar320MVBronzersPenControl20setBrushMaskWithFaceElP15WGPUTextureImplNS_17MVBronzersPenModeE@plt>:
   a47a0:      	adrp	x16, 0xac000
   a47a4:      	ldr	x17, [x16, #0x318]
   a47a8:      	add	x16, x16, #0x318
   a47ac:      	br	x17

00000000000a47b0 <_ZN8mtlabar320MVBronzersPenControl16setStandFaceMaskElP15WGPUTextureImpl@plt>:
   a47b0:      	adrp	x16, 0xac000
   a47b4:      	ldr	x17, [x16, #0x320]
   a47b8:      	add	x16, x16, #0x320
   a47bc:      	br	x17

00000000000a47c0 <_ZN8mtlabar320MVBronzersPenControl25setStandFaceEffectTextureElP15WGPUTextureImpl@plt>:
   a47c0:      	adrp	x16, 0xac000
   a47c4:      	ldr	x17, [x16, #0x328]
   a47c8:      	add	x16, x16, #0x328
   a47cc:      	br	x17

00000000000a47d0 <_ZN8mtlabar320MVBronzersPenControl8setColorENS_10ColorSpaceEfff@plt>:
   a47d0:      	adrp	x16, 0xac000
   a47d4:      	ldr	x17, [x16, #0x330]
   a47d8:      	add	x16, x16, #0x330
   a47dc:      	br	x17

00000000000a47e0 <_ZN8mtlabar320MVBronzersPenControl15setCurrentPenIDEPKc@plt>:
   a47e0:      	adrp	x16, 0xac000
   a47e4:      	ldr	x17, [x16, #0x338]
   a47e8:      	add	x16, x16, #0x338
   a47ec:      	br	x17

00000000000a47f0 <_ZN8mtlabar320MVBronzersPenControl24isEnableFacialProtectionEb@plt>:
   a47f0:      	adrp	x16, 0xac000
   a47f4:      	ldr	x17, [x16, #0x340]
   a47f8:      	add	x16, x16, #0x340
   a47fc:      	br	x17

00000000000a4800 <_ZN8mtlabar310BrushCache6createEv@plt>:
   a4800:      	adrp	x16, 0xac000
   a4804:      	ldr	x17, [x16, #0x348]
   a4808:      	add	x16, x16, #0x348
   a480c:      	br	x17

00000000000a4810 <_ZN8mtlabar310BrushCache7destroyEPS0_@plt>:
   a4810:      	adrp	x16, 0xac000
   a4814:      	ldr	x17, [x16, #0x350]
   a4818:      	add	x16, x16, #0x350
   a481c:      	br	x17

00000000000a4820 <_ZN8mtlabar310BrushCache8deepCopyEPKS0_@plt>:
   a4820:      	adrp	x16, 0xac000
   a4824:      	ldr	x17, [x16, #0x358]
   a4828:      	add	x16, x16, #0x358
   a482c:      	br	x17

00000000000a4830 <_ZN8mtlabar310BrushCache8getColorEv@plt>:
   a4830:      	adrp	x16, 0xac000
   a4834:      	ldr	x17, [x16, #0x360]
   a4838:      	add	x16, x16, #0x360
   a483c:      	br	x17

00000000000a4840 <_ZN8mtlabar310BrushCache8setColorERKNS_6Float3E@plt>:
   a4840:      	adrp	x16, 0xac000
   a4844:      	ldr	x17, [x16, #0x368]
   a4848:      	add	x16, x16, #0x368
   a484c:      	br	x17

00000000000a4850 <_ZNK8mtlabar310BrushCache10getPenModeEv@plt>:
   a4850:      	adrp	x16, 0xac000
   a4854:      	ldr	x17, [x16, #0x370]
   a4858:      	add	x16, x16, #0x370
   a485c:      	br	x17

00000000000a4860 <_ZN8mtlabar310BrushCache10setPenModeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a4860:      	adrp	x16, 0xac000
   a4864:      	ldr	x17, [x16, #0x378]
   a4868:      	add	x16, x16, #0x378
   a486c:      	br	x17

00000000000a4870 <_ZNK8mtlabar310BrushCache7getSizeEv@plt>:
   a4870:      	adrp	x16, 0xac000
   a4874:      	ldr	x17, [x16, #0x380]
   a4878:      	add	x16, x16, #0x380
   a487c:      	br	x17

00000000000a4880 <_ZN8mtlabar310BrushCache7setSizeEf@plt>:
   a4880:      	adrp	x16, 0xac000
   a4884:      	ldr	x17, [x16, #0x388]
   a4888:      	add	x16, x16, #0x388
   a488c:      	br	x17

00000000000a4890 <_ZNK8mtlabar310BrushCache8getShapeEv@plt>:
   a4890:      	adrp	x16, 0xac000
   a4894:      	ldr	x17, [x16, #0x390]
   a4898:      	add	x16, x16, #0x390
   a489c:      	br	x17

00000000000a48a0 <_ZN8mtlabar310BrushCache8setShapeEi@plt>:
   a48a0:      	adrp	x16, 0xac000
   a48a4:      	ldr	x17, [x16, #0x398]
   a48a8:      	add	x16, x16, #0x398
   a48ac:      	br	x17

00000000000a48b0 <_ZNK8mtlabar310BrushCache11getIntervalEv@plt>:
   a48b0:      	adrp	x16, 0xac000
   a48b4:      	ldr	x17, [x16, #0x3a0]
   a48b8:      	add	x16, x16, #0x3a0
   a48bc:      	br	x17

00000000000a48c0 <_ZN8mtlabar310BrushCache11setIntervalEi@plt>:
   a48c0:      	adrp	x16, 0xac000
   a48c4:      	ldr	x17, [x16, #0x3a8]
   a48c8:      	add	x16, x16, #0x3a8
   a48cc:      	br	x17

00000000000a48d0 <_ZNK8mtlabar310BrushCache15getColorDirFlagEv@plt>:
   a48d0:      	adrp	x16, 0xac000
   a48d4:      	ldr	x17, [x16, #0x3b0]
   a48d8:      	add	x16, x16, #0x3b0
   a48dc:      	br	x17

00000000000a48e0 <_ZN8mtlabar310BrushCache15setColorDirFlagEi@plt>:
   a48e0:      	adrp	x16, 0xac000
   a48e4:      	ldr	x17, [x16, #0x3b8]
   a48e8:      	add	x16, x16, #0x3b8
   a48ec:      	br	x17

00000000000a48f0 <_ZNK8mtlabar310BrushCache14getVertexCountEv@plt>:
   a48f0:      	adrp	x16, 0xac000
   a48f4:      	ldr	x17, [x16, #0x3c0]
   a48f8:      	add	x16, x16, #0x3c0
   a48fc:      	br	x17

00000000000a4900 <_ZN8mtlabar310BrushCache14setVertexCountEi@plt>:
   a4900:      	adrp	x16, 0xac000
   a4904:      	ldr	x17, [x16, #0x3c8]
   a4908:      	add	x16, x16, #0x3c8
   a490c:      	br	x17

00000000000a4910 <_ZNK8mtlabar310BrushCache13getPointCountEv@plt>:
   a4910:      	adrp	x16, 0xac000
   a4914:      	ldr	x17, [x16, #0x3d0]
   a4918:      	add	x16, x16, #0x3d0
   a491c:      	br	x17

00000000000a4920 <_ZN8mtlabar310BrushCache13setPointCountEi@plt>:
   a4920:      	adrp	x16, 0xac000
   a4924:      	ldr	x17, [x16, #0x3d8]
   a4928:      	add	x16, x16, #0x3d8
   a492c:      	br	x17

00000000000a4930 <_ZNK8mtlabar310BrushCache10getInitDirEv@plt>:
   a4930:      	adrp	x16, 0xac000
   a4934:      	ldr	x17, [x16, #0x3e0]
   a4938:      	add	x16, x16, #0x3e0
   a493c:      	br	x17

00000000000a4940 <_ZN8mtlabar310BrushCache10setInitDirERKNS_6Float3E@plt>:
   a4940:      	adrp	x16, 0xac000
   a4944:      	ldr	x17, [x16, #0x3e8]
   a4948:      	add	x16, x16, #0x3e8
   a494c:      	br	x17

00000000000a4950 <_ZNK8mtlabar310BrushCache11getPrePointEv@plt>:
   a4950:      	adrp	x16, 0xac000
   a4954:      	ldr	x17, [x16, #0x3f0]
   a4958:      	add	x16, x16, #0x3f0
   a495c:      	br	x17

00000000000a4960 <_ZN8mtlabar310BrushCache11setPrePointERKNS_6Float3E@plt>:
   a4960:      	adrp	x16, 0xac000
   a4964:      	ldr	x17, [x16, #0x3f8]
   a4968:      	add	x16, x16, #0x3f8
   a496c:      	br	x17

00000000000a4970 <_ZNK8mtlabar310BrushCache11getCurPointEv@plt>:
   a4970:      	adrp	x16, 0xac000
   a4974:      	ldr	x17, [x16, #0x400]
   a4978:      	add	x16, x16, #0x400
   a497c:      	br	x17

00000000000a4980 <_ZN8mtlabar310BrushCache11setCurPointERKNS_6Float3E@plt>:
   a4980:      	adrp	x16, 0xac000
   a4984:      	ldr	x17, [x16, #0x408]
   a4988:      	add	x16, x16, #0x408
   a498c:      	br	x17

00000000000a4990 <_ZNK8mtlabar310BrushCache12getNextPointEv@plt>:
   a4990:      	adrp	x16, 0xac000
   a4994:      	ldr	x17, [x16, #0x410]
   a4998:      	add	x16, x16, #0x410
   a499c:      	br	x17

00000000000a49a0 <_ZN8mtlabar310BrushCache12setNextPointERKNS_6Float3E@plt>:
   a49a0:      	adrp	x16, 0xac000
   a49a4:      	ldr	x17, [x16, #0x418]
   a49a8:      	add	x16, x16, #0x418
   a49ac:      	br	x17

00000000000a49b0 <_ZNK8mtlabar310BrushCache12getLastPointEv@plt>:
   a49b0:      	adrp	x16, 0xac000
   a49b4:      	ldr	x17, [x16, #0x420]
   a49b8:      	add	x16, x16, #0x420
   a49bc:      	br	x17

00000000000a49c0 <_ZN8mtlabar310BrushCache12setLastPointERKNS_6Float3E@plt>:
   a49c0:      	adrp	x16, 0xac000
   a49c4:      	ldr	x17, [x16, #0x428]
   a49c8:      	add	x16, x16, #0x428
   a49cc:      	br	x17

00000000000a49d0 <_ZNK8mtlabar310BrushCache12getPositionsEv@plt>:
   a49d0:      	adrp	x16, 0xac000
   a49d4:      	ldr	x17, [x16, #0x430]
   a49d8:      	add	x16, x16, #0x430
   a49dc:      	br	x17

00000000000a49e0 <_ZN8mtlabar310BrushCache12setPositionsERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   a49e0:      	adrp	x16, 0xac000
   a49e4:      	ldr	x17, [x16, #0x438]
   a49e8:      	add	x16, x16, #0x438
   a49ec:      	br	x17

00000000000a49f0 <_ZNK8mtlabar310BrushCache13getTexCoords0Ev@plt>:
   a49f0:      	adrp	x16, 0xac000
   a49f4:      	ldr	x17, [x16, #0x440]
   a49f8:      	add	x16, x16, #0x440
   a49fc:      	br	x17

00000000000a4a00 <_ZN8mtlabar310BrushCache13setTexCoords0ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   a4a00:      	adrp	x16, 0xac000
   a4a04:      	ldr	x17, [x16, #0x448]
   a4a08:      	add	x16, x16, #0x448
   a4a0c:      	br	x17

00000000000a4a10 <_ZNK8mtlabar310BrushCache13getTexCoords1Ev@plt>:
   a4a10:      	adrp	x16, 0xac000
   a4a14:      	ldr	x17, [x16, #0x450]
   a4a18:      	add	x16, x16, #0x450
   a4a1c:      	br	x17

00000000000a4a20 <_ZN8mtlabar310BrushCache13setTexCoords1ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   a4a20:      	adrp	x16, 0xac000
   a4a24:      	ldr	x17, [x16, #0x458]
   a4a28:      	add	x16, x16, #0x458
   a4a2c:      	br	x17

00000000000a4a30 <_ZNK8mtlabar310BrushCache13getTexCoords2Ev@plt>:
   a4a30:      	adrp	x16, 0xac000
   a4a34:      	ldr	x17, [x16, #0x460]
   a4a38:      	add	x16, x16, #0x460
   a4a3c:      	br	x17

00000000000a4a40 <_ZN8mtlabar310BrushCache13setTexCoords2ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   a4a40:      	adrp	x16, 0xac000
   a4a44:      	ldr	x17, [x16, #0x468]
   a4a48:      	add	x16, x16, #0x468
   a4a4c:      	br	x17

00000000000a4a50 <_ZNK8mtlabar310BrushCache12getMixColorsEv@plt>:
   a4a50:      	adrp	x16, 0xac000
   a4a54:      	ldr	x17, [x16, #0x470]
   a4a58:      	add	x16, x16, #0x470
   a4a5c:      	br	x17

00000000000a4a60 <_ZN8mtlabar310BrushCache12setMixColorsERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   a4a60:      	adrp	x16, 0xac000
   a4a64:      	ldr	x17, [x16, #0x478]
   a4a68:      	add	x16, x16, #0x478
   a4a6c:      	br	x17

00000000000a4a70 <_ZNK8mtlabar310BrushCache15getUseArrowHeadEv@plt>:
   a4a70:      	adrp	x16, 0xac000
   a4a74:      	ldr	x17, [x16, #0x480]
   a4a78:      	add	x16, x16, #0x480
   a4a7c:      	br	x17

00000000000a4a80 <_ZN8mtlabar310BrushCache15setUseArrowHeadEb@plt>:
   a4a80:      	adrp	x16, 0xac000
   a4a84:      	ldr	x17, [x16, #0x488]
   a4a88:      	add	x16, x16, #0x488
   a4a8c:      	br	x17

00000000000a4a90 <_ZNK8mtlabar310BrushCache16getAnimationTypeEv@plt>:
   a4a90:      	adrp	x16, 0xac000
   a4a94:      	ldr	x17, [x16, #0x490]
   a4a98:      	add	x16, x16, #0x490
   a4a9c:      	br	x17

00000000000a4aa0 <_ZN8mtlabar310BrushCache16setAnimationTypeENS_26MVGraffitiPenAnimationTypeE@plt>:
   a4aa0:      	adrp	x16, 0xac000
   a4aa4:      	ldr	x17, [x16, #0x498]
   a4aa8:      	add	x16, x16, #0x498
   a4aac:      	br	x17

00000000000a4ab0 <_ZNK8mtlabar310BrushCache16getAnimationLeftEv@plt>:
   a4ab0:      	adrp	x16, 0xac000
   a4ab4:      	ldr	x17, [x16, #0x4a0]
   a4ab8:      	add	x16, x16, #0x4a0
   a4abc:      	br	x17

00000000000a4ac0 <_ZN8mtlabar310BrushCache16setAnimationLeftEf@plt>:
   a4ac0:      	adrp	x16, 0xac000
   a4ac4:      	ldr	x17, [x16, #0x4a8]
   a4ac8:      	add	x16, x16, #0x4a8
   a4acc:      	br	x17

00000000000a4ad0 <_ZNK8mtlabar310BrushCache15getAnimationTopEv@plt>:
   a4ad0:      	adrp	x16, 0xac000
   a4ad4:      	ldr	x17, [x16, #0x4b0]
   a4ad8:      	add	x16, x16, #0x4b0
   a4adc:      	br	x17

00000000000a4ae0 <_ZN8mtlabar310BrushCache15setAnimationTopEf@plt>:
   a4ae0:      	adrp	x16, 0xac000
   a4ae4:      	ldr	x17, [x16, #0x4b8]
   a4ae8:      	add	x16, x16, #0x4b8
   a4aec:      	br	x17

00000000000a4af0 <_ZNK8mtlabar310BrushCache17getAnimationRightEv@plt>:
   a4af0:      	adrp	x16, 0xac000
   a4af4:      	ldr	x17, [x16, #0x4c0]
   a4af8:      	add	x16, x16, #0x4c0
   a4afc:      	br	x17

00000000000a4b00 <_ZN8mtlabar310BrushCache17setAnimationRightEf@plt>:
   a4b00:      	adrp	x16, 0xac000
   a4b04:      	ldr	x17, [x16, #0x4c8]
   a4b08:      	add	x16, x16, #0x4c8
   a4b0c:      	br	x17

00000000000a4b10 <_ZNK8mtlabar310BrushCache18getAnimationBottomEv@plt>:
   a4b10:      	adrp	x16, 0xac000
   a4b14:      	ldr	x17, [x16, #0x4d0]
   a4b18:      	add	x16, x16, #0x4d0
   a4b1c:      	br	x17

00000000000a4b20 <_ZN8mtlabar310BrushCache18setAnimationBottomEf@plt>:
   a4b20:      	adrp	x16, 0xac000
   a4b24:      	ldr	x17, [x16, #0x4d8]
   a4b28:      	add	x16, x16, #0x4d8
   a4b2c:      	br	x17

00000000000a4b30 <_ZNK8mtlabar310BrushCache17getAnimationSpeedEv@plt>:
   a4b30:      	adrp	x16, 0xac000
   a4b34:      	ldr	x17, [x16, #0x4e0]
   a4b38:      	add	x16, x16, #0x4e0
   a4b3c:      	br	x17

00000000000a4b40 <_ZN8mtlabar310BrushCache17setAnimationSpeedEf@plt>:
   a4b40:      	adrp	x16, 0xac000
   a4b44:      	ldr	x17, [x16, #0x4e8]
   a4b48:      	add	x16, x16, #0x4e8
   a4b4c:      	br	x17

00000000000a4b50 <_ZNK8mtlabar310BrushCache14getTranslationEv@plt>:
   a4b50:      	adrp	x16, 0xac000
   a4b54:      	ldr	x17, [x16, #0x4f0]
   a4b58:      	add	x16, x16, #0x4f0
   a4b5c:      	br	x17

00000000000a4b60 <_ZN8mtlabar310BrushCache14setTranslationERKNS_6Float2E@plt>:
   a4b60:      	adrp	x16, 0xac000
   a4b64:      	ldr	x17, [x16, #0x4f8]
   a4b68:      	add	x16, x16, #0x4f8
   a4b6c:      	br	x17

00000000000a4b70 <_ZNK8mtlabar310BrushCache11getRotationEv@plt>:
   a4b70:      	adrp	x16, 0xac000
   a4b74:      	ldr	x17, [x16, #0x500]
   a4b78:      	add	x16, x16, #0x500
   a4b7c:      	br	x17

00000000000a4b80 <_ZN8mtlabar310BrushCache11setRotationEf@plt>:
   a4b80:      	adrp	x16, 0xac000
   a4b84:      	ldr	x17, [x16, #0x508]
   a4b88:      	add	x16, x16, #0x508
   a4b8c:      	br	x17

00000000000a4b90 <_ZNK8mtlabar310BrushCache8getScaleEv@plt>:
   a4b90:      	adrp	x16, 0xac000
   a4b94:      	ldr	x17, [x16, #0x510]
   a4b98:      	add	x16, x16, #0x510
   a4b9c:      	br	x17

00000000000a4ba0 <_ZN8mtlabar310BrushCache8setScaleEf@plt>:
   a4ba0:      	adrp	x16, 0xac000
   a4ba4:      	ldr	x17, [x16, #0x518]
   a4ba8:      	add	x16, x16, #0x518
   a4bac:      	br	x17

00000000000a4bb0 <_ZNK8mtlabar310BrushCache16getOriginalWidthEv@plt>:
   a4bb0:      	adrp	x16, 0xac000
   a4bb4:      	ldr	x17, [x16, #0x520]
   a4bb8:      	add	x16, x16, #0x520
   a4bbc:      	br	x17

00000000000a4bc0 <_ZN8mtlabar310BrushCache16setOriginalWidthEf@plt>:
   a4bc0:      	adrp	x16, 0xac000
   a4bc4:      	ldr	x17, [x16, #0x528]
   a4bc8:      	add	x16, x16, #0x528
   a4bcc:      	br	x17

00000000000a4bd0 <_ZNK8mtlabar310BrushCache17getOriginalHeightEv@plt>:
   a4bd0:      	adrp	x16, 0xac000
   a4bd4:      	ldr	x17, [x16, #0x530]
   a4bd8:      	add	x16, x16, #0x530
   a4bdc:      	br	x17

00000000000a4be0 <_ZN8mtlabar310BrushCache17setOriginalHeightEf@plt>:
   a4be0:      	adrp	x16, 0xac000
   a4be4:      	ldr	x17, [x16, #0x538]
   a4be8:      	add	x16, x16, #0x538
   a4bec:      	br	x17

00000000000a4bf0 <_ZN8mtlabar320MVGraffitiPenControl19setIsInBrushDrawingEb@plt>:
   a4bf0:      	adrp	x16, 0xac000
   a4bf4:      	ldr	x17, [x16, #0x540]
   a4bf8:      	add	x16, x16, #0x540
   a4bfc:      	br	x17

00000000000a4c00 <_ZN8mtlabar320MVGraffitiPenControl14setSecondStateENS_17OnSecondEditStateE@plt>:
   a4c00:      	adrp	x16, 0xac000
   a4c04:      	ldr	x17, [x16, #0x548]
   a4c08:      	add	x16, x16, #0x548
   a4c0c:      	br	x17

00000000000a4c10 <_ZN8mtlabar320MVGraffitiPenControl15setDrawingParamERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEffff@plt>:
   a4c10:      	adrp	x16, 0xac000
   a4c14:      	ldr	x17, [x16, #0x550]
   a4c18:      	add	x16, x16, #0x550
   a4c1c:      	br	x17

00000000000a4c20 <_ZN8mtlabar320MVGraffitiPenControl13setTouchParamEffNS_12OnTouchStateE@plt>:
   a4c20:      	adrp	x16, 0xac000
   a4c24:      	ldr	x17, [x16, #0x558]
   a4c28:      	add	x16, x16, #0x558
   a4c2c:      	br	x17

00000000000a4c30 <_ZNK8mtlabar320MVGraffitiPenControl13getBrushCacheEv@plt>:
   a4c30:      	adrp	x16, 0xac000
   a4c34:      	ldr	x17, [x16, #0x560]
   a4c38:      	add	x16, x16, #0x560
   a4c3c:      	br	x17

00000000000a4c40 <_ZN8mtlabar320MVGraffitiPenControl13setBrushCacheERKNSt6__ndk16vectorIPNS_10BrushCacheENS1_9allocatorIS4_EEEE@plt>:
   a4c40:      	adrp	x16, 0xac000
   a4c44:      	ldr	x17, [x16, #0x568]
   a4c48:      	add	x16, x16, #0x568
   a4c4c:      	br	x17

00000000000a4c50 <_ZNK8mtlabar320MVGraffitiPenControl23getSecondEditBrushCacheEv@plt>:
   a4c50:      	adrp	x16, 0xac000
   a4c54:      	ldr	x17, [x16, #0x570]
   a4c58:      	add	x16, x16, #0x570
   a4c5c:      	br	x17

00000000000a4c60 <_ZN8mtlabar320MVGraffitiPenControl23setSecondEditBrushCacheERKNSt6__ndk16vectorIPNS_10BrushCacheENS1_9allocatorIS4_EEEE@plt>:
   a4c60:      	adrp	x16, 0xac000
   a4c64:      	ldr	x17, [x16, #0x578]
   a4c68:      	add	x16, x16, #0x578
   a4c6c:      	br	x17

00000000000a4c70 <_ZN8mtlabar320MVGraffitiPenControl14addBrushConfigERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   a4c70:      	adrp	x16, 0xac000
   a4c74:      	ldr	x17, [x16, #0x580]
   a4c78:      	add	x16, x16, #0x580
   a4c7c:      	br	x17

00000000000a4c80 <_ZNK8mtlabar320MVGraffitiPenControl22getNullProgramBrushIdsEv@plt>:
   a4c80:      	adrp	x16, 0xac000
   a4c84:      	ldr	x17, [x16, #0x588]
   a4c88:      	add	x16, x16, #0x588
   a4c8c:      	br	x17

00000000000a4c90 <_ZNK8mtlabar312PaintControl12isInPaintingEv@plt>:
   a4c90:      	adrp	x16, 0xac000
   a4c94:      	ldr	x17, [x16, #0x590]
   a4c98:      	add	x16, x16, #0x590
   a4c9c:      	br	x17

00000000000a4ca0 <_ZN8mtlabar312PaintControl8clearAllEv@plt>:
   a4ca0:      	adrp	x16, 0xac000
   a4ca4:      	ldr	x17, [x16, #0x598]
   a4ca8:      	add	x16, x16, #0x598
   a4cac:      	br	x17

00000000000a4cb0 <_ZNK8mtlabar312PaintControl7canUndoEv@plt>:
   a4cb0:      	adrp	x16, 0xac000
   a4cb4:      	ldr	x17, [x16, #0x5a0]
   a4cb8:      	add	x16, x16, #0x5a0
   a4cbc:      	br	x17

00000000000a4cc0 <_ZN8mtlabar312PaintControl8undoLastEv@plt>:
   a4cc0:      	adrp	x16, 0xac000
   a4cc4:      	ldr	x17, [x16, #0x5a8]
   a4cc8:      	add	x16, x16, #0x5a8
   a4ccc:      	br	x17

00000000000a4cd0 <_ZN8mtlabar312PaintControl13clearUndoListEv@plt>:
   a4cd0:      	adrp	x16, 0xac000
   a4cd4:      	ldr	x17, [x16, #0x5b0]
   a4cd8:      	add	x16, x16, #0x5b0
   a4cdc:      	br	x17

00000000000a4ce0 <_ZNK8mtlabar312PaintControl7canRedoEv@plt>:
   a4ce0:      	adrp	x16, 0xac000
   a4ce4:      	ldr	x17, [x16, #0x5b8]
   a4ce8:      	add	x16, x16, #0x5b8
   a4cec:      	br	x17

00000000000a4cf0 <_ZN8mtlabar312PaintControl8redoLastEv@plt>:
   a4cf0:      	adrp	x16, 0xac000
   a4cf4:      	ldr	x17, [x16, #0x5c0]
   a4cf8:      	add	x16, x16, #0x5c0
   a4cfc:      	br	x17

00000000000a4d00 <_ZN8mtlabar312PaintControl13clearRedoListEv@plt>:
   a4d00:      	adrp	x16, 0xac000
   a4d04:      	ldr	x17, [x16, #0x5c8]
   a4d08:      	add	x16, x16, #0x5c8
   a4d0c:      	br	x17

00000000000a4d10 <_ZNK8mtlabar39ParamBase12getParamTypeEv@plt>:
   a4d10:      	adrp	x16, 0xac000
   a4d14:      	ldr	x17, [x16, #0x5d0]
   a4d18:      	add	x16, x16, #0x5d0
   a4d1c:      	br	x17

00000000000a4d20 <_ZNK8mtlabar39ParamBase15getParamKeyNameEv@plt>:
   a4d20:      	adrp	x16, 0xac000
   a4d24:      	ldr	x17, [x16, #0x5d8]
   a4d28:      	add	x16, x16, #0x5d8
   a4d2c:      	br	x17

00000000000a4d30 <_ZNK8mtlabar39ParamBase12getParamFlagEv@plt>:
   a4d30:      	adrp	x16, 0xac000
   a4d34:      	ldr	x17, [x16, #0x5e0]
   a4d38:      	add	x16, x16, #0x5e0
   a4d3c:      	br	x17

00000000000a4d40 <_ZNK8mtlabar39ParamBase14getChineseNameEv@plt>:
   a4d40:      	adrp	x16, 0xac000
   a4d44:      	ldr	x17, [x16, #0x5e8]
   a4d48:      	add	x16, x16, #0x5e8
   a4d4c:      	br	x17

00000000000a4d50 <_ZNK8mtlabar39ParamBase14getEnglishNameEv@plt>:
   a4d50:      	adrp	x16, 0xac000
   a4d54:      	ldr	x17, [x16, #0x5f0]
   a4d58:      	add	x16, x16, #0x5f0
   a4d5c:      	br	x17

00000000000a4d60 <_ZNK8mtlabar39ParamBase18getTraditionalNameEv@plt>:
   a4d60:      	adrp	x16, 0xac000
   a4d64:      	ldr	x17, [x16, #0x5f8]
   a4d68:      	add	x16, x16, #0x5f8
   a4d6c:      	br	x17

00000000000a4d70 <_ZNK8mtlabar39ParamBase6getKeyEv@plt>:
   a4d70:      	adrp	x16, 0xac000
   a4d74:      	ldr	x17, [x16, #0x600]
   a4d78:      	add	x16, x16, #0x600
   a4d7c:      	br	x17

00000000000a4d80 <_ZN8mtlabar310ParamColor12getColorTypeEv@plt>:
   a4d80:      	adrp	x16, 0xac000
   a4d84:      	ldr	x17, [x16, #0x608]
   a4d88:      	add	x16, x16, #0x608
   a4d8c:      	br	x17

00000000000a4d90 <_ZN8mtlabar310ParamColor8setColorENS_10ColorSpaceEfff@plt>:
   a4d90:      	adrp	x16, 0xac000
   a4d94:      	ldr	x17, [x16, #0x610]
   a4d98:      	add	x16, x16, #0x610
   a4d9c:      	br	x17

00000000000a4da0 <_ZN8mtlabar310ParamColor20setCurrentColorAlphaEf@plt>:
   a4da0:      	adrp	x16, 0xac000
   a4da4:      	ldr	x17, [x16, #0x618]
   a4da8:      	add	x16, x16, #0x618
   a4dac:      	br	x17

00000000000a4db0 <_ZN8mtlabar310ParamColor22setCurrentColorOpacityEf@plt>:
   a4db0:      	adrp	x16, 0xac000
   a4db4:      	ldr	x17, [x16, #0x620]
   a4db8:      	add	x16, x16, #0x620
   a4dbc:      	br	x17

00000000000a4dc0 <_ZN8mtlabar310ParamColor8getColorENS_18ParamColorTypeEnumE@plt>:
   a4dc0:      	adrp	x16, 0xac000
   a4dc4:      	ldr	x17, [x16, #0x628]
   a4dc8:      	add	x16, x16, #0x628
   a4dcc:      	br	x17

00000000000a4dd0 <_ZNK8mtlabar310ParamColor13getColorSpaceEv@plt>:
   a4dd0:      	adrp	x16, 0xac000
   a4dd4:      	ldr	x17, [x16, #0x630]
   a4dd8:      	add	x16, x16, #0x630
   a4ddc:      	br	x17

00000000000a4de0 <_ZN8mtlabar310ParamColor15getCurrentAlphaEv@plt>:
   a4de0:      	adrp	x16, 0xac000
   a4de4:      	ldr	x17, [x16, #0x638]
   a4de8:      	add	x16, x16, #0x638
   a4dec:      	br	x17

00000000000a4df0 <_ZN8mtlabar310ParamColor17getCurrentOpacityEv@plt>:
   a4df0:      	adrp	x16, 0xac000
   a4df4:      	ldr	x17, [x16, #0x640]
   a4df8:      	add	x16, x16, #0x640
   a4dfc:      	br	x17

00000000000a4e00 <_ZN8mtlabar310ParamColor20getDefaultColorValueENS_18ParamColorTypeEnumE@plt>:
   a4e00:      	adrp	x16, 0xac000
   a4e04:      	ldr	x17, [x16, #0x648]
   a4e08:      	add	x16, x16, #0x648
   a4e0c:      	br	x17

00000000000a4e10 <_ZN8mtlabar310ParamColor15getDefaultAlphaEv@plt>:
   a4e10:      	adrp	x16, 0xac000
   a4e14:      	ldr	x17, [x16, #0x650]
   a4e18:      	add	x16, x16, #0x650
   a4e1c:      	br	x17

00000000000a4e20 <_ZN8mtlabar310ParamColor17getDefaultOpacityEv@plt>:
   a4e20:      	adrp	x16, 0xac000
   a4e24:      	ldr	x17, [x16, #0x658]
   a4e28:      	add	x16, x16, #0x658
   a4e2c:      	br	x17

00000000000a4e30 <_ZN8mtlabar310ParamColor12getMaxHValueEv@plt>:
   a4e30:      	adrp	x16, 0xac000
   a4e34:      	ldr	x17, [x16, #0x660]
   a4e38:      	add	x16, x16, #0x660
   a4e3c:      	br	x17

00000000000a4e40 <_ZN8mtlabar310ParamColor12getMinHValueEv@plt>:
   a4e40:      	adrp	x16, 0xac000
   a4e44:      	ldr	x17, [x16, #0x668]
   a4e48:      	add	x16, x16, #0x668
   a4e4c:      	br	x17

00000000000a4e50 <_ZN8mtlabar310ParamColor8dispatchEv@plt>:
   a4e50:      	adrp	x16, 0xac000
   a4e54:      	ldr	x17, [x16, #0x670]
   a4e58:      	add	x16, x16, #0x670
   a4e5c:      	br	x17

00000000000a4e60 <_ZN8mtlabar313ParamPosition17setCurrentValueXYEff@plt>:
   a4e60:      	adrp	x16, 0xac000
   a4e64:      	ldr	x17, [x16, #0x678]
   a4e68:      	add	x16, x16, #0x678
   a4e6c:      	br	x17

00000000000a4e70 <_ZN8mtlabar313ParamPosition18setCurrentValueXYZEfff@plt>:
   a4e70:      	adrp	x16, 0xac000
   a4e74:      	ldr	x17, [x16, #0x680]
   a4e78:      	add	x16, x16, #0x680
   a4e7c:      	br	x17

00000000000a4e80 <_ZN8mtlabar313ParamPosition19setCurrentValueXYZWEffff@plt>:
   a4e80:      	adrp	x16, 0xac000
   a4e84:      	ldr	x17, [x16, #0x688]
   a4e88:      	add	x16, x16, #0x688
   a4e8c:      	br	x17

00000000000a4e90 <_ZNK8mtlabar313ParamPosition15getPositionTypeEv@plt>:
   a4e90:      	adrp	x16, 0xac000
   a4e94:      	ldr	x17, [x16, #0x690]
   a4e98:      	add	x16, x16, #0x690
   a4e9c:      	br	x17

00000000000a4ea0 <_ZNK8mtlabar313ParamPosition11getCurrentXEv@plt>:
   a4ea0:      	adrp	x16, 0xac000
   a4ea4:      	ldr	x17, [x16, #0x698]
   a4ea8:      	add	x16, x16, #0x698
   a4eac:      	br	x17

00000000000a4eb0 <_ZNK8mtlabar313ParamPosition11getCurrentYEv@plt>:
   a4eb0:      	adrp	x16, 0xac000
   a4eb4:      	ldr	x17, [x16, #0x6a0]
   a4eb8:      	add	x16, x16, #0x6a0
   a4ebc:      	br	x17

00000000000a4ec0 <_ZNK8mtlabar313ParamPosition11getCurrentZEv@plt>:
   a4ec0:      	adrp	x16, 0xac000
   a4ec4:      	ldr	x17, [x16, #0x6a8]
   a4ec8:      	add	x16, x16, #0x6a8
   a4ecc:      	br	x17

00000000000a4ed0 <_ZNK8mtlabar313ParamPosition11getCurrentWEv@plt>:
   a4ed0:      	adrp	x16, 0xac000
   a4ed4:      	ldr	x17, [x16, #0x6b0]
   a4ed8:      	add	x16, x16, #0x6b0
   a4edc:      	br	x17

00000000000a4ee0 <_ZNK8mtlabar313ParamPosition11getDefaultXEv@plt>:
   a4ee0:      	adrp	x16, 0xac000
   a4ee4:      	ldr	x17, [x16, #0x6b8]
   a4ee8:      	add	x16, x16, #0x6b8
   a4eec:      	br	x17

00000000000a4ef0 <_ZNK8mtlabar313ParamPosition11getDefaultYEv@plt>:
   a4ef0:      	adrp	x16, 0xac000
   a4ef4:      	ldr	x17, [x16, #0x6c0]
   a4ef8:      	add	x16, x16, #0x6c0
   a4efc:      	br	x17

00000000000a4f00 <_ZNK8mtlabar313ParamPosition11getDefaultZEv@plt>:
   a4f00:      	adrp	x16, 0xac000
   a4f04:      	ldr	x17, [x16, #0x6c8]
   a4f08:      	add	x16, x16, #0x6c8
   a4f0c:      	br	x17

00000000000a4f10 <_ZNK8mtlabar313ParamPosition11getDefaultWEv@plt>:
   a4f10:      	adrp	x16, 0xac000
   a4f14:      	ldr	x17, [x16, #0x6d0]
   a4f18:      	add	x16, x16, #0x6d0
   a4f1c:      	br	x17

00000000000a4f20 <_ZNK8mtlabar313ParamPosition11getMaxValueEv@plt>:
   a4f20:      	adrp	x16, 0xac000
   a4f24:      	ldr	x17, [x16, #0x6d8]
   a4f28:      	add	x16, x16, #0x6d8
   a4f2c:      	br	x17

00000000000a4f30 <_ZNK8mtlabar313ParamPosition11getMinValueEv@plt>:
   a4f30:      	adrp	x16, 0xac000
   a4f34:      	ldr	x17, [x16, #0x6e0]
   a4f38:      	add	x16, x16, #0x6e0
   a4f3c:      	br	x17

00000000000a4f40 <_ZN8mtlabar313ParamPosition8dispatchEv@plt>:
   a4f40:      	adrp	x16, 0xac000
   a4f44:      	ldr	x17, [x16, #0x6e8]
   a4f48:      	add	x16, x16, #0x6e8
   a4f4c:      	br	x17

00000000000a4f50 <_ZN8mtlabar311ParamSlider15setCurrentValueEf@plt>:
   a4f50:      	adrp	x16, 0xac000
   a4f54:      	ldr	x17, [x16, #0x6f0]
   a4f58:      	add	x16, x16, #0x6f0
   a4f5c:      	br	x17

00000000000a4f60 <_ZNK8mtlabar311ParamSlider15getDefaultValueEv@plt>:
   a4f60:      	adrp	x16, 0xac000
   a4f64:      	ldr	x17, [x16, #0x6f8]
   a4f68:      	add	x16, x16, #0x6f8
   a4f6c:      	br	x17

00000000000a4f70 <_ZNK8mtlabar311ParamSlider15getCurrentValueEv@plt>:
   a4f70:      	adrp	x16, 0xac000
   a4f74:      	ldr	x17, [x16, #0x700]
   a4f78:      	add	x16, x16, #0x700
   a4f7c:      	br	x17

00000000000a4f80 <_ZNK8mtlabar311ParamSlider11getMaxValueEv@plt>:
   a4f80:      	adrp	x16, 0xac000
   a4f84:      	ldr	x17, [x16, #0x708]
   a4f88:      	add	x16, x16, #0x708
   a4f8c:      	br	x17

00000000000a4f90 <_ZNK8mtlabar311ParamSlider11getMinValueEv@plt>:
   a4f90:      	adrp	x16, 0xac000
   a4f94:      	ldr	x17, [x16, #0x710]
   a4f98:      	add	x16, x16, #0x710
   a4f9c:      	br	x17

00000000000a4fa0 <_ZN8mtlabar311ParamSlider8dispatchEv@plt>:
   a4fa0:      	adrp	x16, 0xac000
   a4fa4:      	ldr	x17, [x16, #0x718]
   a4fa8:      	add	x16, x16, #0x718
   a4fac:      	br	x17

00000000000a4fb0 <_ZN8mtlabar316ParamSliderGroup15setCurrentValueEf@plt>:
   a4fb0:      	adrp	x16, 0xac000
   a4fb4:      	ldr	x17, [x16, #0x720]
   a4fb8:      	add	x16, x16, #0x720
   a4fbc:      	br	x17

00000000000a4fc0 <_ZN8mtlabar316ParamSliderGroup22setCurrentValueByIndexEif@plt>:
   a4fc0:      	adrp	x16, 0xac000
   a4fc4:      	ldr	x17, [x16, #0x728]
   a4fc8:      	add	x16, x16, #0x728
   a4fcc:      	br	x17

00000000000a4fd0 <_ZNK8mtlabar316ParamSliderGroup12getGroupSizeEv@plt>:
   a4fd0:      	adrp	x16, 0xac000
   a4fd4:      	ldr	x17, [x16, #0x730]
   a4fd8:      	add	x16, x16, #0x730
   a4fdc:      	br	x17

00000000000a4fe0 <_ZNK8mtlabar316ParamSliderGroup12getGroupTypeEv@plt>:
   a4fe0:      	adrp	x16, 0xac000
   a4fe4:      	ldr	x17, [x16, #0x738]
   a4fe8:      	add	x16, x16, #0x738
   a4fec:      	br	x17

00000000000a4ff0 <_ZNK8mtlabar316ParamSliderGroup15getDefaultValueEv@plt>:
   a4ff0:      	adrp	x16, 0xac000
   a4ff4:      	ldr	x17, [x16, #0x740]
   a4ff8:      	add	x16, x16, #0x740
   a4ffc:      	br	x17

00000000000a5000 <_ZNK8mtlabar316ParamSliderGroup22getCurrentValueByIndexEi@plt>:
   a5000:      	adrp	x16, 0xac000
   a5004:      	ldr	x17, [x16, #0x748]
   a5008:      	add	x16, x16, #0x748
   a500c:      	br	x17

00000000000a5010 <_ZNK8mtlabar316ParamSliderGroup20getCurrentValueByKeyEi@plt>:
   a5010:      	adrp	x16, 0xac000
   a5014:      	ldr	x17, [x16, #0x750]
   a5018:      	add	x16, x16, #0x750
   a501c:      	br	x17

00000000000a5020 <_ZNK8mtlabar316ParamSliderGroup11getMaxValueEv@plt>:
   a5020:      	adrp	x16, 0xac000
   a5024:      	ldr	x17, [x16, #0x758]
   a5028:      	add	x16, x16, #0x758
   a502c:      	br	x17

00000000000a5030 <_ZNK8mtlabar316ParamSliderGroup11getMinValueEv@plt>:
   a5030:      	adrp	x16, 0xac000
   a5034:      	ldr	x17, [x16, #0x760]
   a5038:      	add	x16, x16, #0x760
   a503c:      	br	x17

00000000000a5040 <_ZN8mtlabar316ParamSliderGroup8dispatchEv@plt>:
   a5040:      	adrp	x16, 0xac000
   a5044:      	ldr	x17, [x16, #0x768]
   a5048:      	add	x16, x16, #0x768
   a504c:      	br	x17

00000000000a5050 <_ZN8mtlabar311ParamString15setCurrentValueERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a5050:      	adrp	x16, 0xac000
   a5054:      	ldr	x17, [x16, #0x770]
   a5058:      	add	x16, x16, #0x770
   a505c:      	br	x17

00000000000a5060 <_ZNK8mtlabar311ParamString15getCurrentValueEv@plt>:
   a5060:      	adrp	x16, 0xac000
   a5064:      	ldr	x17, [x16, #0x778]
   a5068:      	add	x16, x16, #0x778
   a506c:      	br	x17

00000000000a5070 <_ZNK8mtlabar311ParamString15getDefaultValueEv@plt>:
   a5070:      	adrp	x16, 0xac000
   a5074:      	ldr	x17, [x16, #0x780]
   a5078:      	add	x16, x16, #0x780
   a507c:      	br	x17

00000000000a5080 <_ZN8mtlabar311ParamString8dispatchEv@plt>:
   a5080:      	adrp	x16, 0xac000
   a5084:      	ldr	x17, [x16, #0x788]
   a5088:      	add	x16, x16, #0x788
   a508c:      	br	x17

00000000000a5090 <_ZN8mtlabar311ParamSwitch15setCurrentValueEb@plt>:
   a5090:      	adrp	x16, 0xac000
   a5094:      	ldr	x17, [x16, #0x790]
   a5098:      	add	x16, x16, #0x790
   a509c:      	br	x17

00000000000a50a0 <_ZNK8mtlabar311ParamSwitch15getCurrentValueEv@plt>:
   a50a0:      	adrp	x16, 0xac000
   a50a4:      	ldr	x17, [x16, #0x798]
   a50a8:      	add	x16, x16, #0x798
   a50ac:      	br	x17

00000000000a50b0 <_ZNK8mtlabar311ParamSwitch15getDefaultValueEv@plt>:
   a50b0:      	adrp	x16, 0xac000
   a50b4:      	ldr	x17, [x16, #0x7a0]
   a50b8:      	add	x16, x16, #0x7a0
   a50bc:      	br	x17

00000000000a50c0 <_ZN8mtlabar311ParamSwitch8dispatchEv@plt>:
   a50c0:      	adrp	x16, 0xac000
   a50c4:      	ldr	x17, [x16, #0x7a8]
   a50c8:      	add	x16, x16, #0x7a8
   a50cc:      	br	x17

00000000000a50d0 <_ZN8mtlabar310ParamTable8getParamEi@plt>:
   a50d0:      	adrp	x16, 0xac000
   a50d4:      	ldr	x17, [x16, #0x7b0]
   a50d8:      	add	x16, x16, #0x7b0
   a50dc:      	br	x17

00000000000a50e0 <_ZN8mtlabar310ParamTable13getParamByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a50e0:      	adrp	x16, 0xac000
   a50e4:      	ldr	x17, [x16, #0x7b8]
   a50e8:      	add	x16, x16, #0x7b8
   a50ec:      	br	x17

00000000000a50f0 <_ZN8mtlabar310ParamTable14getParamByFlagENS_13ParamFlagEnumE@plt>:
   a50f0:      	adrp	x16, 0xac000
   a50f4:      	ldr	x17, [x16, #0x7c0]
   a50f8:      	add	x16, x16, #0x7c0
   a50fc:      	br	x17

00000000000a5100 <_ZN8mtlabar310ParamTable13getParamColorEi@plt>:
   a5100:      	adrp	x16, 0xac000
   a5104:      	ldr	x17, [x16, #0x7c8]
   a5108:      	add	x16, x16, #0x7c8
   a510c:      	br	x17

00000000000a5110 <_ZN8mtlabar310ParamTable18getParamColorByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a5110:      	adrp	x16, 0xac000
   a5114:      	ldr	x17, [x16, #0x7d0]
   a5118:      	add	x16, x16, #0x7d0
   a511c:      	br	x17

00000000000a5120 <_ZN8mtlabar310ParamTable19getParamColorByFlagENS_13ParamFlagEnumE@plt>:
   a5120:      	adrp	x16, 0xac000
   a5124:      	ldr	x17, [x16, #0x7d8]
   a5128:      	add	x16, x16, #0x7d8
   a512c:      	br	x17

00000000000a5130 <_ZN8mtlabar310ParamTable16getParamPositionEi@plt>:
   a5130:      	adrp	x16, 0xac000
   a5134:      	ldr	x17, [x16, #0x7e0]
   a5138:      	add	x16, x16, #0x7e0
   a513c:      	br	x17

00000000000a5140 <_ZN8mtlabar310ParamTable21getParamPositionByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a5140:      	adrp	x16, 0xac000
   a5144:      	ldr	x17, [x16, #0x7e8]
   a5148:      	add	x16, x16, #0x7e8
   a514c:      	br	x17

00000000000a5150 <_ZN8mtlabar310ParamTable22getParamPositionByFlagENS_13ParamFlagEnumE@plt>:
   a5150:      	adrp	x16, 0xac000
   a5154:      	ldr	x17, [x16, #0x7f0]
   a5158:      	add	x16, x16, #0x7f0
   a515c:      	br	x17

00000000000a5160 <_ZN8mtlabar310ParamTable14getParamSwitchEi@plt>:
   a5160:      	adrp	x16, 0xac000
   a5164:      	ldr	x17, [x16, #0x7f8]
   a5168:      	add	x16, x16, #0x7f8
   a516c:      	br	x17

00000000000a5170 <_ZN8mtlabar310ParamTable19getParamSwitchByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a5170:      	adrp	x16, 0xac000
   a5174:      	ldr	x17, [x16, #0x800]
   a5178:      	add	x16, x16, #0x800
   a517c:      	br	x17

00000000000a5180 <_ZN8mtlabar310ParamTable20getParamSwitchByFlagENS_13ParamFlagEnumE@plt>:
   a5180:      	adrp	x16, 0xac000
   a5184:      	ldr	x17, [x16, #0x808]
   a5188:      	add	x16, x16, #0x808
   a518c:      	br	x17

00000000000a5190 <_ZN8mtlabar310ParamTable14getParamStringEi@plt>:
   a5190:      	adrp	x16, 0xac000
   a5194:      	ldr	x17, [x16, #0x810]
   a5198:      	add	x16, x16, #0x810
   a519c:      	br	x17

00000000000a51a0 <_ZN8mtlabar310ParamTable19getParamStringByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a51a0:      	adrp	x16, 0xac000
   a51a4:      	ldr	x17, [x16, #0x818]
   a51a8:      	add	x16, x16, #0x818
   a51ac:      	br	x17

00000000000a51b0 <_ZN8mtlabar310ParamTable20getParamStringByFlagENS_13ParamFlagEnumE@plt>:
   a51b0:      	adrp	x16, 0xac000
   a51b4:      	ldr	x17, [x16, #0x820]
   a51b8:      	add	x16, x16, #0x820
   a51bc:      	br	x17

00000000000a51c0 <_ZN8mtlabar310ParamTable14getParamSliderEi@plt>:
   a51c0:      	adrp	x16, 0xac000
   a51c4:      	ldr	x17, [x16, #0x828]
   a51c8:      	add	x16, x16, #0x828
   a51cc:      	br	x17

00000000000a51d0 <_ZN8mtlabar310ParamTable19getParamSliderByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a51d0:      	adrp	x16, 0xac000
   a51d4:      	ldr	x17, [x16, #0x830]
   a51d8:      	add	x16, x16, #0x830
   a51dc:      	br	x17

00000000000a51e0 <_ZN8mtlabar310ParamTable20getParamSliderByFlagENS_13ParamFlagEnumE@plt>:
   a51e0:      	adrp	x16, 0xac000
   a51e4:      	ldr	x17, [x16, #0x838]
   a51e8:      	add	x16, x16, #0x838
   a51ec:      	br	x17

00000000000a51f0 <_ZN8mtlabar310ParamTable19getParamSliderGroupEi@plt>:
   a51f0:      	adrp	x16, 0xac000
   a51f4:      	ldr	x17, [x16, #0x840]
   a51f8:      	add	x16, x16, #0x840
   a51fc:      	br	x17

00000000000a5200 <_ZN8mtlabar310ParamTable24getParamSliderGroupByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   a5200:      	adrp	x16, 0xac000
   a5204:      	ldr	x17, [x16, #0x848]
   a5208:      	add	x16, x16, #0x848
   a520c:      	br	x17

00000000000a5210 <_ZN8mtlabar310ParamTable25getParamSliderGroupByFlagENS_13ParamFlagEnumE@plt>:
   a5210:      	adrp	x16, 0xac000
   a5214:      	ldr	x17, [x16, #0x850]
   a5218:      	add	x16, x16, #0x850
   a521c:      	br	x17

00000000000a5220 <_ZN8mtlabar310ParamTable13getParamCountEv@plt>:
   a5220:      	adrp	x16, 0xac000
   a5224:      	ldr	x17, [x16, #0x858]
   a5228:      	add	x16, x16, #0x858
   a522c:      	br	x17

00000000000a5230 <_ZN8mtlabar314ParamTableDict8getTableENS_14ParamTableEnumE@plt>:
   a5230:      	adrp	x16, 0xac000
   a5234:      	ldr	x17, [x16, #0x860]
   a5238:      	add	x16, x16, #0x860
   a523c:      	br	x17

00000000000a5240 <_ZN8mtlabar311PartControl11getPartTypeEv@plt>:
   a5240:      	adrp	x16, 0xac000
   a5244:      	ldr	x17, [x16, #0x868]
   a5248:      	add	x16, x16, #0x868
   a524c:      	br	x17

00000000000a5250 <_ZN8mtlabar311PartControl17getPartTypeStringEv@plt>:
   a5250:      	adrp	x16, 0xac000
   a5254:      	ldr	x17, [x16, #0x870]
   a5258:      	add	x16, x16, #0x870
   a525c:      	br	x17

00000000000a5260 <_ZN8mtlabar311PartControl14getPartSummaryEv@plt>:
   a5260:      	adrp	x16, 0xac000
   a5264:      	ldr	x17, [x16, #0x878]
   a5268:      	add	x16, x16, #0x878
   a526c:      	br	x17

00000000000a5270 <_ZNK8mtlabar311PartControl10getPartTagEv@plt>:
   a5270:      	adrp	x16, 0xac000
   a5274:      	ldr	x17, [x16, #0x880]
   a5278:      	add	x16, x16, #0x880
   a527c:      	br	x17

00000000000a5280 <_ZN8mtlabar311PartControl7isErrorEv@plt>:
   a5280:      	adrp	x16, 0xac000
   a5284:      	ldr	x17, [x16, #0x888]
   a5288:      	add	x16, x16, #0x888
   a528c:      	br	x17

00000000000a5290 <_ZN8mtlabar311PartControl9isAlreadyEv@plt>:
   a5290:      	adrp	x16, 0xac000
   a5294:      	ldr	x17, [x16, #0x890]
   a5298:      	add	x16, x16, #0x890
   a529c:      	br	x17

00000000000a52a0 <_ZN8mtlabar311PartControl12getPartLayerEv@plt>:
   a52a0:      	adrp	x16, 0xac000
   a52a4:      	ldr	x17, [x16, #0x898]
   a52a8:      	add	x16, x16, #0x898
   a52ac:      	br	x17

00000000000a52b0 <_ZN8mtlabar311PartControl19getPartControlLayerEv@plt>:
   a52b0:      	adrp	x16, 0xac000
   a52b4:      	ldr	x17, [x16, #0x8a0]
   a52b8:      	add	x16, x16, #0x8a0
   a52bc:      	br	x17

00000000000a52c0 <_ZN8mtlabar311PartControl19setPartControlLayerEi@plt>:
   a52c0:      	adrp	x16, 0xac000
   a52c4:      	ldr	x17, [x16, #0x8a8]
   a52c8:      	add	x16, x16, #0x8a8
   a52cc:      	br	x17

00000000000a52d0 <_ZN8mtlabar311PartControl21getPartControlVisibleEv@plt>:
   a52d0:      	adrp	x16, 0xac000
   a52d4:      	ldr	x17, [x16, #0x8b0]
   a52d8:      	add	x16, x16, #0x8b0
   a52dc:      	br	x17

00000000000a52e0 <_ZN8mtlabar311PartControl21setPartControlVisibleEb@plt>:
   a52e0:      	adrp	x16, 0xac000
   a52e4:      	ldr	x17, [x16, #0x8b8]
   a52e8:      	add	x16, x16, #0x8b8
   a52ec:      	br	x17

00000000000a52f0 <_ZN8mtlabar311PartControl5resetEv@plt>:
   a52f0:      	adrp	x16, 0xac000
   a52f4:      	ldr	x17, [x16, #0x8c0]
   a52f8:      	add	x16, x16, #0x8c0
   a52fc:      	br	x17

00000000000a5300 <_ZNK8mtlabar311PartControl7isApplyEv@plt>:
   a5300:      	adrp	x16, 0xac000
   a5304:      	ldr	x17, [x16, #0x8c8]
   a5308:      	add	x16, x16, #0x8c8
   a530c:      	br	x17

00000000000a5310 <_ZN8mtlabar311PartControl8setApplyEb@plt>:
   a5310:      	adrp	x16, 0xac000
   a5314:      	ldr	x17, [x16, #0x8d0]
   a5318:      	add	x16, x16, #0x8d0
   a531c:      	br	x17

00000000000a5320 <_ZN8mtlabar311PartControl13getCustomNameEv@plt>:
   a5320:      	adrp	x16, 0xac000
   a5324:      	ldr	x17, [x16, #0x8d8]
   a5328:      	add	x16, x16, #0x8d8
   a532c:      	br	x17

00000000000a5330 <_ZNK8mtlabar311PartControl19getCustomParamCountEv@plt>:
   a5330:      	adrp	x16, 0xac000
   a5334:      	ldr	x17, [x16, #0x8e0]
   a5338:      	add	x16, x16, #0x8e0
   a533c:      	br	x17

00000000000a5340 <_ZNK8mtlabar311PartControl17getCustomParamKeyEm@plt>:
   a5340:      	adrp	x16, 0xac000
   a5344:      	ldr	x17, [x16, #0x8e8]
   a5348:      	add	x16, x16, #0x8e8
   a534c:      	br	x17

00000000000a5350 <_ZNK8mtlabar311PartControl19getCustomParamValueEm@plt>:
   a5350:      	adrp	x16, 0xac000
   a5354:      	ldr	x17, [x16, #0x8f0]
   a5358:      	add	x16, x16, #0x8f0
   a535c:      	br	x17

00000000000a5360 <_ZNK8mtlabar311PartControl26getCustomParamValueWithKeyEPKc@plt>:
   a5360:      	adrp	x16, 0xac000
   a5364:      	ldr	x17, [x16, #0x8f8]
   a5368:      	add	x16, x16, #0x8f8
   a536c:      	br	x17

00000000000a5370 <_ZN8mtlabar311PartControl20insertCustomParamMapEPKcS2_@plt>:
   a5370:      	adrp	x16, 0xac000
   a5374:      	ldr	x17, [x16, #0x900]
   a5378:      	add	x16, x16, #0x900
   a537c:      	br	x17

00000000000a5380 <_ZN8mtlabar311PartControl9getHandleEv@plt>:
   a5380:      	adrp	x16, 0xac000
   a5384:      	ldr	x17, [x16, #0x908]
   a5388:      	add	x16, x16, #0x908
   a538c:      	br	x17

00000000000a5390 <_ZN8mtlabar311PartControl14getDataRequireEv@plt>:
   a5390:      	adrp	x16, 0xac000
   a5394:      	ldr	x17, [x16, #0x910]
   a5398:      	add	x16, x16, #0x910
   a539c:      	br	x17

00000000000a53a0 <_ZN8mtlabar311PartControl16getLayoutDetailsEv@plt>:
   a53a0:      	adrp	x16, 0xac000
   a53a4:      	ldr	x17, [x16, #0x918]
   a53a8:      	add	x16, x16, #0x918
   a53ac:      	br	x17

00000000000a53b0 <_ZN8mtlabar311PartControl18getMakeupControlAtEm@plt>:
   a53b0:      	adrp	x16, 0xac000
   a53b4:      	ldr	x17, [x16, #0x920]
   a53b8:      	add	x16, x16, #0x920
   a53bc:      	br	x17

00000000000a53c0 <_ZN8mtlabar311PartControl20getMakeupControlSizeEv@plt>:
   a53c0:      	adrp	x16, 0xac000
   a53c4:      	ldr	x17, [x16, #0x928]
   a53c8:      	add	x16, x16, #0x928
   a53cc:      	br	x17

00000000000a53d0 <_ZN8mtlabar311PartControl19getEyeSideControlAtEm@plt>:
   a53d0:      	adrp	x16, 0xac000
   a53d4:      	ldr	x17, [x16, #0x930]
   a53d8:      	add	x16, x16, #0x930
   a53dc:      	br	x17

00000000000a53e0 <_ZN8mtlabar311PartControl21getEyeSideControlSizeEv@plt>:
   a53e0:      	adrp	x16, 0xac000
   a53e4:      	ldr	x17, [x16, #0x938]
   a53e8:      	add	x16, x16, #0x938
   a53ec:      	br	x17

00000000000a53f0 <_ZN8mtlabar311PartControl18getFaceliftControlEv@plt>:
   a53f0:      	adrp	x16, 0xac000
   a53f4:      	ldr	x17, [x16, #0x940]
   a53f8:      	add	x16, x16, #0x940
   a53fc:      	br	x17

00000000000a5400 <_ZN8mtlabar311PartControl18getBodySlimControlEv@plt>:
   a5400:      	adrp	x16, 0xac000
   a5404:      	ldr	x17, [x16, #0x948]
   a5408:      	add	x16, x16, #0x948
   a540c:      	br	x17

00000000000a5410 <_ZN8mtlabar311PartControl21getShoulderMLSControlEv@plt>:
   a5410:      	adrp	x16, 0xac000
   a5414:      	ldr	x17, [x16, #0x950]
   a5418:      	add	x16, x16, #0x950
   a541c:      	br	x17

00000000000a5420 <_ZN8mtlabar311PartControl19getHipDeformControlEv@plt>:
   a5420:      	adrp	x16, 0xac000
   a5424:      	ldr	x17, [x16, #0x958]
   a5428:      	add	x16, x16, #0x958
   a542c:      	br	x17

00000000000a5430 <_ZN8mtlabar311PartControl18getSwanNeckControlEv@plt>:
   a5430:      	adrp	x16, 0xac000
   a5434:      	ldr	x17, [x16, #0x960]
   a5438:      	add	x16, x16, #0x960
   a543c:      	br	x17

00000000000a5440 <_ZN8mtlabar311PartControl25getBodyShapingPartControlEv@plt>:
   a5440:      	adrp	x16, 0xac000
   a5444:      	ldr	x17, [x16, #0x968]
   a5448:      	add	x16, x16, #0x968
   a544c:      	br	x17

00000000000a5450 <_ZN8mtlabar311PartControl16getToningControlEv@plt>:
   a5450:      	adrp	x16, 0xac000
   a5454:      	ldr	x17, [x16, #0x970]
   a5458:      	add	x16, x16, #0x970
   a545c:      	br	x17

00000000000a5460 <_ZN8mtlabar311PartControl17getParamTableDictEv@plt>:
   a5460:      	adrp	x16, 0xac000
   a5464:      	ldr	x17, [x16, #0x978]
   a5468:      	add	x16, x16, #0x978
   a546c:      	br	x17

00000000000a5470 <_ZN8mtlabar311PartControl15getHumanControlEv@plt>:
   a5470:      	adrp	x16, 0xac000
   a5474:      	ldr	x17, [x16, #0x980]
   a5478:      	add	x16, x16, #0x980
   a547c:      	br	x17

00000000000a5480 <_ZN8mtlabar311PartControl17getStickerControlEv@plt>:
   a5480:      	adrp	x16, 0xac000
   a5484:      	ldr	x17, [x16, #0x988]
   a5488:      	add	x16, x16, #0x988
   a548c:      	br	x17

00000000000a5490 <_ZN8mtlabar311PartControl23getMVBronzersPenControlEv@plt>:
   a5490:      	adrp	x16, 0xac000
   a5494:      	ldr	x17, [x16, #0x990]
   a5498:      	add	x16, x16, #0x990
   a549c:      	br	x17

00000000000a54a0 <_ZN8mtlabar311PartControl23getMVGraffitiPenControlEv@plt>:
   a54a0:      	adrp	x16, 0xac000
   a54a4:      	ldr	x17, [x16, #0x998]
   a54a8:      	add	x16, x16, #0x998
   a54ac:      	br	x17

00000000000a54b0 <_ZN8mtlabar311PartControl15getPaintControlEv@plt>:
   a54b0:      	adrp	x16, 0xac000
   a54b4:      	ldr	x17, [x16, #0x9a0]
   a54b8:      	add	x16, x16, #0x9a0
   a54bc:      	br	x17

00000000000a54c0 <_ZN8mtlabar310EffectData17loadConfigurationEPKc@plt>:
   a54c0:      	adrp	x16, 0xac000
   a54c4:      	ldr	x17, [x16, #0x9a8]
   a54c8:      	add	x16, x16, #0x9a8
   a54cc:      	br	x17

00000000000a54d0 <_ZN8mtlabar310EffectData21loadConfigurationSyncEPKc@plt>:
   a54d0:      	adrp	x16, 0xac000
   a54d4:      	ldr	x17, [x16, #0x9b0]
   a54d8:      	add	x16, x16, #0x9b0
   a54dc:      	br	x17

00000000000a54e0 <_ZN8mtlabar310EffectData20parsingConfigurationEPKc@plt>:
   a54e0:      	adrp	x16, 0xac000
   a54e4:      	ldr	x17, [x16, #0x9b8]
   a54e8:      	add	x16, x16, #0x9b8
   a54ec:      	br	x17

00000000000a54f0 <_ZN8mtlabar310EffectData13serializationEv@plt>:
   a54f0:      	adrp	x16, 0xac000
   a54f4:      	ldr	x17, [x16, #0x9c0]
   a54f8:      	add	x16, x16, #0x9c0
   a54fc:      	br	x17

00000000000a5500 <_ZNK8mtlabar310EffectData9isAlreadyEv@plt>:
   a5500:      	adrp	x16, 0xac000
   a5504:      	ldr	x17, [x16, #0x9c8]
   a5508:      	add	x16, x16, #0x9c8
   a550c:      	br	x17

00000000000a5510 <_ZN8mtlabar310EffectData8setApplyEb@plt>:
   a5510:      	adrp	x16, 0xac000
   a5514:      	ldr	x17, [x16, #0x9d0]
   a5518:      	add	x16, x16, #0x9d0
   a551c:      	br	x17

00000000000a5520 <_ZNK8mtlabar310EffectData7isApplyEv@plt>:
   a5520:      	adrp	x16, 0xac000
   a5524:      	ldr	x17, [x16, #0x9d8]
   a5528:      	add	x16, x16, #0x9d8
   a552c:      	br	x17

00000000000a5530 <_ZN8mtlabar310EffectData5resetEv@plt>:
   a5530:      	adrp	x16, 0xac000
   a5534:      	ldr	x17, [x16, #0x9e0]
   a5538:      	add	x16, x16, #0x9e0
   a553c:      	br	x17

00000000000a5540 <_ZN8mtlabar310EffectData11getPlistTagEv@plt>:
   a5540:      	adrp	x16, 0xac000
   a5544:      	ldr	x17, [x16, #0x9e8]
   a5548:      	add	x16, x16, #0x9e8
   a554c:      	br	x17

00000000000a5550 <_ZN8mtlabar310EffectData8setLayerEi@plt>:
   a5550:      	adrp	x16, 0xac000
   a5554:      	ldr	x17, [x16, #0x9f0]
   a5558:      	add	x16, x16, #0x9f0
   a555c:      	br	x17

00000000000a5560 <_ZNK8mtlabar310EffectData8getLayerEv@plt>:
   a5560:      	adrp	x16, 0xac000
   a5564:      	ldr	x17, [x16, #0x9f8]
   a5568:      	add	x16, x16, #0x9f8
   a556c:      	br	x17

00000000000a5570 <_ZNK8mtlabar310EffectData17isSpecialFaceliftEv@plt>:
   a5570:      	adrp	x16, 0xac000
   a5574:      	ldr	x17, [x16, #0xa00]
   a5578:      	add	x16, x16, #0xa00
   a557c:      	br	x17

00000000000a5580 <_ZNK8mtlabar310EffectData15isSpecialMakeupEv@plt>:
   a5580:      	adrp	x16, 0xac000
   a5584:      	ldr	x17, [x16, #0xa08]
   a5588:      	add	x16, x16, #0xa08
   a558c:      	br	x17

00000000000a5590 <_ZNK8mtlabar310EffectData19getCustomParamCountEv@plt>:
   a5590:      	adrp	x16, 0xac000
   a5594:      	ldr	x17, [x16, #0xa10]
   a5598:      	add	x16, x16, #0xa10
   a559c:      	br	x17

00000000000a55a0 <_ZNK8mtlabar310EffectData17getCustomParamKeyEm@plt>:
   a55a0:      	adrp	x16, 0xac000
   a55a4:      	ldr	x17, [x16, #0xa18]
   a55a8:      	add	x16, x16, #0xa18
   a55ac:      	br	x17

00000000000a55b0 <_ZNK8mtlabar310EffectData19getCustomParamValueEm@plt>:
   a55b0:      	adrp	x16, 0xac000
   a55b4:      	ldr	x17, [x16, #0xa20]
   a55b8:      	add	x16, x16, #0xa20
   a55bc:      	br	x17

00000000000a55c0 <_ZN8mtlabar310EffectData17insertCustomParamEPKcS2_@plt>:
   a55c0:      	adrp	x16, 0xac000
   a55c4:      	ldr	x17, [x16, #0xa28]
   a55c8:      	add	x16, x16, #0xa28
   a55cc:      	br	x17

00000000000a55d0 <_ZN8mtlabar310EffectData6hasBGMEv@plt>:
   a55d0:      	adrp	x16, 0xac000
   a55d4:      	ldr	x17, [x16, #0xa30]
   a55d8:      	add	x16, x16, #0xa30
   a55dc:      	br	x17

00000000000a55e0 <_ZN8mtlabar310EffectData7playBGMEv@plt>:
   a55e0:      	adrp	x16, 0xac000
   a55e4:      	ldr	x17, [x16, #0xa38]
   a55e8:      	add	x16, x16, #0xa38
   a55ec:      	br	x17

00000000000a55f0 <_ZN8mtlabar310EffectData9replayBGMEv@plt>:
   a55f0:      	adrp	x16, 0xac000
   a55f4:      	ldr	x17, [x16, #0xa40]
   a55f8:      	add	x16, x16, #0xa40
   a55fc:      	br	x17

00000000000a5600 <_ZN8mtlabar310EffectData8pauseBGMEv@plt>:
   a5600:      	adrp	x16, 0xac000
   a5604:      	ldr	x17, [x16, #0xa48]
   a5608:      	add	x16, x16, #0xa48
   a560c:      	br	x17

00000000000a5610 <_ZN8mtlabar310EffectData7stopBGMEv@plt>:
   a5610:      	adrp	x16, 0xac000
   a5614:      	ldr	x17, [x16, #0xa50]
   a5618:      	add	x16, x16, #0xa50
   a561c:      	br	x17

00000000000a5620 <_ZN8mtlabar310EffectData7seekBGMEf@plt>:
   a5620:      	adrp	x16, 0xac000
   a5624:      	ldr	x17, [x16, #0xa58]
   a5628:      	add	x16, x16, #0xa58
   a562c:      	br	x17

00000000000a5630 <_ZN8mtlabar310EffectData14getBGMPositionEv@plt>:
   a5630:      	adrp	x16, 0xac000
   a5634:      	ldr	x17, [x16, #0xa60]
   a5638:      	add	x16, x16, #0xa60
   a563c:      	br	x17

00000000000a5640 <_ZN8mtlabar310EffectData10setBGMPathEPKc@plt>:
   a5640:      	adrp	x16, 0xac000
   a5644:      	ldr	x17, [x16, #0xa68]
   a5648:      	add	x16, x16, #0xa68
   a564c:      	br	x17

00000000000a5650 <_ZN8mtlabar310EffectData10getBGMPathEv@plt>:
   a5650:      	adrp	x16, 0xac000
   a5654:      	ldr	x17, [x16, #0xa70]
   a5658:      	add	x16, x16, #0xa70
   a565c:      	br	x17

00000000000a5660 <_ZN8mtlabar310EffectData16getConfigBGMPathEv@plt>:
   a5660:      	adrp	x16, 0xac000
   a5664:      	ldr	x17, [x16, #0xa78]
   a5668:      	add	x16, x16, #0xa78
   a566c:      	br	x17

00000000000a5670 <_ZNK8mtlabar310EffectData16getAIConfigCountEv@plt>:
   a5670:      	adrp	x16, 0xac000
   a5674:      	ldr	x17, [x16, #0xa80]
   a5678:      	add	x16, x16, #0xa80
   a567c:      	br	x17

00000000000a5680 <_ZNK8mtlabar310EffectData11getAIConfigEm@plt>:
   a5680:      	adrp	x16, 0xac000
   a5684:      	ldr	x17, [x16, #0xa88]
   a5688:      	add	x16, x16, #0xa88
   a568c:      	br	x17

00000000000a5690 <_ZNK8mtlabar310EffectData19getPartControlCountEv@plt>:
   a5690:      	adrp	x16, 0xac000
   a5694:      	ldr	x17, [x16, #0xa90]
   a5698:      	add	x16, x16, #0xa90
   a569c:      	br	x17

00000000000a56a0 <_ZNK8mtlabar310EffectData14getPartControlEm@plt>:
   a56a0:      	adrp	x16, 0xac000
   a56a4:      	ldr	x17, [x16, #0xa98]
   a56a8:      	add	x16, x16, #0xa98
   a56ac:      	br	x17

00000000000a56b0 <_ZNK8mtlabar310EffectData29getReplaceSpecialFaceliftTypeEv@plt>:
   a56b0:      	adrp	x16, 0xac000
   a56b4:      	ldr	x17, [x16, #0xaa0]
   a56b8:      	add	x16, x16, #0xaa0
   a56bc:      	br	x17

00000000000a56c0 <_ZN8mtlabar310EffectData15applyGlobalJsonEPKc@plt>:
   a56c0:      	adrp	x16, 0xac000
   a56c4:      	ldr	x17, [x16, #0xaa8]
   a56c8:      	add	x16, x16, #0xaa8
   a56cc:      	br	x17

00000000000a56d0 <_ZN8mtlabar313GlobalSetting10globalInitEv@plt>:
   a56d0:      	adrp	x16, 0xac000
   a56d4:      	ldr	x17, [x16, #0xab0]
   a56d8:      	add	x16, x16, #0xab0
   a56dc:      	br	x17

00000000000a56e0 <_ZN8mtlabar313GlobalSetting18setVisualAllocatorEPNS_15VisualAllocatorE@plt>:
   a56e0:      	adrp	x16, 0xac000
   a56e4:      	ldr	x17, [x16, #0xab8]
   a56e8:      	add	x16, x16, #0xab8
   a56ec:      	br	x17

00000000000a56f0 <_ZNK8mtlabar313GlobalSetting18getVisualAllocatorEv@plt>:
   a56f0:      	adrp	x16, 0xac000
   a56f4:      	ldr	x17, [x16, #0xac0]
   a56f8:      	add	x16, x16, #0xac0
   a56fc:      	br	x17

00000000000a5700 <_ZN8mtlabar313GlobalSetting15mountFileSystemEPKcPNS_17VirtualFileSystemE@plt>:
   a5700:      	adrp	x16, 0xac000
   a5704:      	ldr	x17, [x16, #0xac8]
   a5708:      	add	x16, x16, #0xac8
   a570c:      	br	x17

00000000000a5710 <_ZN8mtlabar313GlobalSetting17unmountFileSystemEPKc@plt>:
   a5710:      	adrp	x16, 0xac000
   a5714:      	ldr	x17, [x16, #0xad0]
   a5718:      	add	x16, x16, #0xad0
   a571c:      	br	x17

00000000000a5720 <_ZN8mtlabar313GlobalSetting12setDirectoryENS_13DirectoryTypeEPKc@plt>:
   a5720:      	adrp	x16, 0xac000
   a5724:      	ldr	x17, [x16, #0xad8]
   a5728:      	add	x16, x16, #0xad8
   a572c:      	br	x17

00000000000a5730 <_ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE@plt>:
   a5730:      	adrp	x16, 0xac000
   a5734:      	ldr	x17, [x16, #0xae0]
   a5738:      	add	x16, x16, #0xae0
   a573c:      	br	x17

00000000000a5740 <_ZN8mtlabar313GlobalSetting14setAIModelPathENS_11AIModelTypeEPKc@plt>:
   a5740:      	adrp	x16, 0xac000
   a5744:      	ldr	x17, [x16, #0xae8]
   a5748:      	add	x16, x16, #0xae8
   a574c:      	br	x17

00000000000a5750 <_ZN8mtlabar313GlobalSetting14getAIModelPathENS_11AIModelTypeE@plt>:
   a5750:      	adrp	x16, 0xac000
   a5754:      	ldr	x17, [x16, #0xaf0]
   a5758:      	add	x16, x16, #0xaf0
   a575c:      	br	x17

00000000000a5760 <_ZN8mtlabar313GlobalSetting14setRuntimeTypeENS_11RuntimeTypeE@plt>:
   a5760:      	adrp	x16, 0xac000
   a5764:      	ldr	x17, [x16, #0xaf8]
   a5768:      	add	x16, x16, #0xaf8
   a576c:      	br	x17

00000000000a5770 <_ZN8mtlabar313GlobalSetting14getRuntimeTypeEv@plt>:
   a5770:      	adrp	x16, 0xac000
   a5774:      	ldr	x17, [x16, #0xb00]
   a5778:      	add	x16, x16, #0xb00
   a577c:      	br	x17

00000000000a5780 <_ZN8mtlabar313GlobalSetting14setLogCallbackEPNS_11LogCallbackE@plt>:
   a5780:      	adrp	x16, 0xac000
   a5784:      	ldr	x17, [x16, #0xb08]
   a5788:      	add	x16, x16, #0xb08
   a578c:      	br	x17

00000000000a5790 <_ZN8mtlabar313GlobalSetting9setJavaVMEP7_JavaVM@plt>:
   a5790:      	adrp	x16, 0xac000
   a5794:      	ldr	x17, [x16, #0xb10]
   a5798:      	add	x16, x16, #0xb10
   a579c:      	br	x17

00000000000a57a0 <_ZN8mtlabar313GlobalSetting17setAndroidContextEP8_jobject@plt>:
   a57a0:      	adrp	x16, 0xac000
   a57a4:      	ldr	x17, [x16, #0xb18]
   a57a8:      	add	x16, x16, #0xb18
   a57ac:      	br	x17

00000000000a57b0 <_ZN8mtlabar313GlobalSetting17startSoundServiceEv@plt>:
   a57b0:      	adrp	x16, 0xac000
   a57b4:      	ldr	x17, [x16, #0xb20]
   a57b8:      	add	x16, x16, #0xb20
   a57bc:      	br	x17

00000000000a57c0 <_ZN8mtlabar313GlobalSetting17pauseSoundServiceEb@plt>:
   a57c0:      	adrp	x16, 0xac000
   a57c4:      	ldr	x17, [x16, #0xb28]
   a57c8:      	add	x16, x16, #0xb28
   a57cc:      	br	x17

00000000000a57d0 <_ZN8mtlabar313GlobalSetting16stopSoundServiceEv@plt>:
   a57d0:      	adrp	x16, 0xac000
   a57d4:      	ldr	x17, [x16, #0xb30]
   a57d8:      	add	x16, x16, #0xb30
   a57dc:      	br	x17

00000000000a57e0 <_ZN8mtlabar313GlobalSetting20isStopedSoundServiceEv@plt>:
   a57e0:      	adrp	x16, 0xac000
   a57e4:      	ldr	x17, [x16, #0xb38]
   a57e8:      	add	x16, x16, #0xb38
   a57ec:      	br	x17

00000000000a57f0 <_ZN8mtlabar313GlobalSetting12registerFontEPKcS2_@plt>:
   a57f0:      	adrp	x16, 0xac000
   a57f4:      	ldr	x17, [x16, #0xb40]
   a57f8:      	add	x16, x16, #0xb40
   a57fc:      	br	x17

00000000000a5800 <_ZN8mtlabar313GlobalSetting14unregisterFontEPKc@plt>:
   a5800:      	adrp	x16, 0xac000
   a5804:      	ldr	x17, [x16, #0xb48]
   a5808:      	add	x16, x16, #0xb48
   a580c:      	br	x17

00000000000a5810 <_ZN8mtlabar313GlobalSetting22registerBoldFontFamilyEPKcS2_@plt>:
   a5810:      	adrp	x16, 0xac000
   a5814:      	ldr	x17, [x16, #0xb50]
   a5818:      	add	x16, x16, #0xb50
   a581c:      	br	x17

00000000000a5820 <_ZN8mtlabar313GlobalSetting13getFontFamilyEPKc@plt>:
   a5820:      	adrp	x16, 0xac000
   a5824:      	ldr	x17, [x16, #0xb58]
   a5828:      	add	x16, x16, #0xb58
   a582c:      	br	x17

00000000000a5830 <_ZN8mtlabar313GlobalSetting13getSDKVersionEv@plt>:
   a5830:      	adrp	x16, 0xac000
   a5834:      	ldr	x17, [x16, #0xb60]
   a5838:      	add	x16, x16, #0xb60
   a583c:      	br	x17

00000000000a5840 <_ZN8mtlabar313GlobalSetting20getSDKReleaseVersionEv@plt>:
   a5840:      	adrp	x16, 0xac000
   a5844:      	ldr	x17, [x16, #0xb68]
   a5848:      	add	x16, x16, #0xb68
   a584c:      	br	x17

00000000000a5850 <_ZN8mtlabar39Interface28loadPublicParamConfigurationEPKc@plt>:
   a5850:      	adrp	x16, 0xac000
   a5854:      	ldr	x17, [x16, #0xb70]
   a5858:      	add	x16, x16, #0xb70
   a585c:      	br	x17

00000000000a5860 <_ZN8mtlabar39Interface32loadPublicParamConfigurationSyncEPKc@plt>:
   a5860:      	adrp	x16, 0xac000
   a5864:      	ldr	x17, [x16, #0xb78]
   a5868:      	add	x16, x16, #0xb78
   a586c:      	br	x17

00000000000a5870 <_ZN8mtlabar39Interface11createEmptyEv@plt>:
   a5870:      	adrp	x16, 0xac000
   a5874:      	ldr	x17, [x16, #0xb80]
   a5878:      	add	x16, x16, #0xb80
   a587c:      	br	x17

00000000000a5880 <_ZN8mtlabar39Interface21createExternalFromPtrEPv@plt>:
   a5880:      	adrp	x16, 0xac000
   a5884:      	ldr	x17, [x16, #0xb88]
   a5888:      	add	x16, x16, #0xb88
   a588c:      	br	x17

00000000000a5890 <_ZN8mtlabar39Interface17loadConfigurationEPKc@plt>:
   a5890:      	adrp	x16, 0xac000
   a5894:      	ldr	x17, [x16, #0xb90]
   a5898:      	add	x16, x16, #0xb90
   a589c:      	br	x17

00000000000a58a0 <_ZN8mtlabar39Interface21loadConfigurationSyncEPKc@plt>:
   a58a0:      	adrp	x16, 0xac000
   a58a4:      	ldr	x17, [x16, #0xb98]
   a58a8:      	add	x16, x16, #0xb98
   a58ac:      	br	x17

00000000000a58b0 <_ZN8mtlabar39Interface20parsingConfigurationEPKc@plt>:
   a58b0:      	adrp	x16, 0xac000
   a58b4:      	ldr	x17, [x16, #0xba0]
   a58b8:      	add	x16, x16, #0xba0
   a58bc:      	br	x17

00000000000a58c0 <_ZN8mtlabar39Interface19deleteConfigurationEPNS_10EffectDataE@plt>:
   a58c0:      	adrp	x16, 0xac000
   a58c4:      	ldr	x17, [x16, #0xba8]
   a58c8:      	add	x16, x16, #0xba8
   a58cc:      	br	x17

00000000000a58d0 <_ZN8mtlabar39Interface21addEffectDataListenerEPNS_18EffectDataListenerE@plt>:
   a58d0:      	adrp	x16, 0xac000
   a58d4:      	ldr	x17, [x16, #0xbb0]
   a58d8:      	add	x16, x16, #0xbb0
   a58dc:      	br	x17

00000000000a58e0 <_ZN8mtlabar39Interface21delEffectDataListenerEPNS_18EffectDataListenerE@plt>:
   a58e0:      	adrp	x16, 0xac000
   a58e4:      	ldr	x17, [x16, #0xbb8]
   a58e8:      	add	x16, x16, #0xbb8
   a58ec:      	br	x17

00000000000a58f0 <_ZN8mtlabar39Interface25setExternalFunctionStructEPNS_24ExternalFunctionCallbackE@plt>:
   a58f0:      	adrp	x16, 0xac000
   a58f4:      	ldr	x17, [x16, #0xbc0]
   a58f8:      	add	x16, x16, #0xbc0
   a58fc:      	br	x17

00000000000a5900 <_ZN8mtlabar39Interface21setDrawFunctionStructEPNS_20DrawFunctionCallbackE@plt>:
   a5900:      	adrp	x16, 0xac000
   a5904:      	ldr	x17, [x16, #0xbc8]
   a5908:      	add	x16, x16, #0xbc8
   a590c:      	br	x17

00000000000a5910 <_ZN8mtlabar39Interface11addListenerEPNS_17InterfaceListenerE@plt>:
   a5910:      	adrp	x16, 0xac000
   a5914:      	ldr	x17, [x16, #0xbd0]
   a5918:      	add	x16, x16, #0xbd0
   a591c:      	br	x17

00000000000a5920 <_ZN8mtlabar39Interface11delListenerEPNS_17InterfaceListenerE@plt>:
   a5920:      	adrp	x16, 0xac000
   a5924:      	ldr	x17, [x16, #0xbd8]
   a5928:      	add	x16, x16, #0xbd8
   a592c:      	br	x17

00000000000a5930 <_ZN8mtlabar39Interface17getTotalFaceStateEv@plt>:
   a5930:      	adrp	x16, 0xac000
   a5934:      	ldr	x17, [x16, #0xbe0]
   a5938:      	add	x16, x16, #0xbe0
   a593c:      	br	x17

00000000000a5940 <_ZN8mtlabar39Interface30setNativeRuntimeModifyFaceDataEPKNS_17FaceDataInterfaceE@plt>:
   a5940:      	adrp	x16, 0xac000
   a5944:      	ldr	x17, [x16, #0xbe8]
   a5948:      	add	x16, x16, #0xbe8
   a594c:      	br	x17

00000000000a5950 <_ZN8mtlabar39Interface30getNativeRuntimeModifyFaceDataEv@plt>:
   a5950:      	adrp	x16, 0xac000
   a5954:      	ldr	x17, [x16, #0xbf0]
   a5958:      	add	x16, x16, #0xbf0
   a595c:      	br	x17

00000000000a5960 <_ZN8mtlabar39Interface27transferFaceliftOffsetPointEPKfPfjj@plt>:
   a5960:      	adrp	x16, 0xac000
   a5964:      	ldr	x17, [x16, #0xbf8]
   a5968:      	add	x16, x16, #0xbf8
   a596c:      	br	x17

00000000000a5970 <_ZNK8mtlabar39Interface14getMemoryUsageEv@plt>:
   a5970:      	adrp	x16, 0xac000
   a5974:      	ldr	x17, [x16, #0xc00]
   a5978:      	add	x16, x16, #0xc00
   a597c:      	br	x17

00000000000a5980 <_ZNK8mtlabar39Interface9debugDumpEv@plt>:
   a5980:      	adrp	x16, 0xac000
   a5984:      	ldr	x17, [x16, #0xc08]
   a5988:      	add	x16, x16, #0xc08
   a598c:      	br	x17

00000000000a5990 <_ZN8mtlabar39Interface13setRandomSeedEm@plt>:
   a5990:      	adrp	x16, 0xac000
   a5994:      	ldr	x17, [x16, #0xc10]
   a5998:      	add	x16, x16, #0xc10
   a599c:      	br	x17

00000000000a59a0 <_ZN8mtlabar39Interface13voidOperationENS_17VoidOperationTypeE@plt>:
   a59a0:      	adrp	x16, 0xac000
   a59a4:      	ldr	x17, [x16, #0xc18]
   a59a8:      	add	x16, x16, #0xc18
   a59ac:      	br	x17

00000000000a59b0 <_ZN8mtlabar39Interface9setOptionENS_10OptionTypeEb@plt>:
   a59b0:      	adrp	x16, 0xac000
   a59b4:      	ldr	x17, [x16, #0xc20]
   a59b8:      	add	x16, x16, #0xc20
   a59bc:      	br	x17

00000000000a59c0 <_ZN8mtlabar39Interface9getOptionENS_10OptionTypeE@plt>:
   a59c0:      	adrp	x16, 0xac000
   a59c4:      	ldr	x17, [x16, #0xc28]
   a59c8:      	add	x16, x16, #0xc28
   a59cc:      	br	x17

00000000000a59d0 <_ZN8mtlabar39Interface14setMusicVolumeEf@plt>:
   a59d0:      	adrp	x16, 0xac000
   a59d4:      	ldr	x17, [x16, #0xc30]
   a59d8:      	add	x16, x16, #0xc30
   a59dc:      	br	x17

00000000000a59e0 <_ZN8mtlabar39Interface12onTouchBeginEffi@plt>:
   a59e0:      	adrp	x16, 0xac000
   a59e4:      	ldr	x17, [x16, #0xc38]
   a59e8:      	add	x16, x16, #0xc38
   a59ec:      	br	x17

00000000000a59f0 <_ZN8mtlabar39Interface11onTouchMoveEffi@plt>:
   a59f0:      	adrp	x16, 0xac000
   a59f4:      	ldr	x17, [x16, #0xc40]
   a59f8:      	add	x16, x16, #0xc40
   a59fc:      	br	x17

00000000000a5a00 <_ZN8mtlabar39Interface10onTouchEndEffi@plt>:
   a5a00:      	adrp	x16, 0xac000
   a5a04:      	ldr	x17, [x16, #0xc48]
   a5a08:      	add	x16, x16, #0xc48
   a5a0c:      	br	x17

00000000000a5a10 <_ZN8mtlabar39Interface5onKeyEi@plt>:
   a5a10:      	adrp	x16, 0xac000
   a5a14:      	ldr	x17, [x16, #0xc50]
   a5a18:      	add	x16, x16, #0xc50
   a5a1c:      	br	x17

00000000000a5a20 <_ZN8mtlabar39Interface16onUTF8CharactersEPKc@plt>:
   a5a20:      	adrp	x16, 0xac000
   a5a24:      	ldr	x17, [x16, #0xc58]
   a5a28:      	add	x16, x16, #0xc58
   a5a2c:      	br	x17

00000000000a5a30 <_ZN8mtlabar39Interface11postMessageEPKcS2_b@plt>:
   a5a30:      	adrp	x16, 0xac000
   a5a34:      	ldr	x17, [x16, #0xc60]
   a5a38:      	add	x16, x16, #0xc60
   a5a3c:      	br	x17

00000000000a5a40 <_ZN8mtlabar39Interface14getDataRequireEv@plt>:
   a5a40:      	adrp	x16, 0xac000
   a5a44:      	ldr	x17, [x16, #0xc68]
   a5a48:      	add	x16, x16, #0xc68
   a5a4c:      	br	x17

00000000000a5a50 <_ZN8mtlabar39Interface12setFrameDataEPNS_18FrameDataInterfaceE@plt>:
   a5a50:      	adrp	x16, 0xac000
   a5a54:      	ldr	x17, [x16, #0xc70]
   a5a58:      	add	x16, x16, #0xc70
   a5a5c:      	br	x17

00000000000a5a60 <_ZN8mtlabar39Interface24setTimeLineDataInterfaceEPNS_21TimeLineDataInterfaceE@plt>:
   a5a60:      	adrp	x16, 0xac000
   a5a64:      	ldr	x17, [x16, #0xc78]
   a5a68:      	add	x16, x16, #0xc78
   a5a6c:      	br	x17

00000000000a5a70 <_ZN8mtlabar39Interface8dispatchEv@plt>:
   a5a70:      	adrp	x16, 0xac000
   a5a74:      	ldr	x17, [x16, #0xc80]
   a5a78:      	add	x16, x16, #0xc80
   a5a7c:      	br	x17

00000000000a5a80 <_ZN8mtlabar39Interface6renderEv@plt>:
   a5a80:      	adrp	x16, 0xac000
   a5a84:      	ldr	x17, [x16, #0xc88]
   a5a88:      	add	x16, x16, #0xc88
   a5a8c:      	br	x17

00000000000a5a90 <_ZN8mtlabar39Interface10clearCacheEv@plt>:
   a5a90:      	adrp	x16, 0xac000
   a5a94:      	ldr	x17, [x16, #0xc90]
   a5a98:      	add	x16, x16, #0xc90
   a5a9c:      	br	x17

00000000000a5aa0 <_ZN8mtlabar39Interface12isATheLatestEv@plt>:
   a5aa0:      	adrp	x16, 0xac000
   a5aa4:      	ldr	x17, [x16, #0xc98]
   a5aa8:      	add	x16, x16, #0xc98
   a5aac:      	br	x17

00000000000a5ab0 <_ZNK8mtlabar39Interface24getLoadedPartControlSizeEv@plt>:
   a5ab0:      	adrp	x16, 0xac000
   a5ab4:      	ldr	x17, [x16, #0xca0]
   a5ab8:      	add	x16, x16, #0xca0
   a5abc:      	br	x17

00000000000a5ac0 <_ZNK8mtlabar39Interface20getLoadedPartControlEm@plt>:
   a5ac0:      	adrp	x16, 0xac000
   a5ac4:      	ldr	x17, [x16, #0xca8]
   a5ac8:      	add	x16, x16, #0xca8
   a5acc:      	br	x17

00000000000a5ad0 <_ZN8mtlabar313MainInterface6createEP14WGPUDeviceImplj@plt>:
   a5ad0:      	adrp	x16, 0xac000
   a5ad4:      	ldr	x17, [x16, #0xcb0]
   a5ad8:      	add	x16, x16, #0xcb0
   a5adc:      	br	x17

00000000000a5ae0 <_ZN8mtlabar313MainInterface7destroyEPS0_@plt>:
   a5ae0:      	adrp	x16, 0xac000
   a5ae4:      	ldr	x17, [x16, #0xcb8]
   a5ae8:      	add	x16, x16, #0xcb8
   a5aec:      	br	x17

00000000000a5af0 <_ZN8mtlabar313MainInterface15createInterfaceEv@plt>:
   a5af0:      	adrp	x16, 0xac000
   a5af4:      	ldr	x17, [x16, #0xcc0]
   a5af8:      	add	x16, x16, #0xcc0
   a5afc:      	br	x17

00000000000a5b00 <_ZN8mtlabar313MainInterface29createInterfaceWithColorSpaceENS_10ColorSpaceE@plt>:
   a5b00:      	adrp	x16, 0xac000
   a5b04:      	ldr	x17, [x16, #0xcc8]
   a5b08:      	add	x16, x16, #0xcc8
   a5b0c:      	br	x17

00000000000a5b10 <_ZN8mtlabar313MainInterface16destroyInterfaceEPNS_9InterfaceE@plt>:
   a5b10:      	adrp	x16, 0xac000
   a5b14:      	ldr	x17, [x16, #0xcd0]
   a5b18:      	add	x16, x16, #0xcd0
   a5b1c:      	br	x17

00000000000a5b20 <_ZN8mtlabar313MainInterface24createFrameDataInterfaceEv@plt>:
   a5b20:      	adrp	x16, 0xac000
   a5b24:      	ldr	x17, [x16, #0xcd8]
   a5b28:      	add	x16, x16, #0xcd8
   a5b2c:      	br	x17

00000000000a5b30 <_ZN8mtlabar313MainInterface25destroyFrameDataInterfaceEPNS_18FrameDataInterfaceE@plt>:
   a5b30:      	adrp	x16, 0xac000
   a5b34:      	ldr	x17, [x16, #0xce0]
   a5b38:      	add	x16, x16, #0xce0
   a5b3c:      	br	x17

00000000000a5b40 <_ZN8mtlabar313MainInterface23getInteractionInterfaceEv@plt>:
   a5b40:      	adrp	x16, 0xac000
   a5b44:      	ldr	x17, [x16, #0xce8]
   a5b48:      	add	x16, x16, #0xce8
   a5b4c:      	br	x17

00000000000a5b50 <_ZN8mtlabar313MainInterface10clearCacheEv@plt>:
   a5b50:      	adrp	x16, 0xac000
   a5b54:      	ldr	x17, [x16, #0xcf0]
   a5b58:      	add	x16, x16, #0xcf0
   a5b5c:      	br	x17

00000000000a5b60 <_ZN8mtlabar38Graphics16createWithOpenGLEv@plt>:
   a5b60:      	adrp	x16, 0xac000
   a5b64:      	ldr	x17, [x16, #0xcf8]
   a5b68:      	add	x16, x16, #0xcf8
   a5b6c:      	br	x17

00000000000a5b70 <_ZN8mtlabar38Graphics15createWithMetalEPv@plt>:
   a5b70:      	adrp	x16, 0xac000
   a5b74:      	ldr	x17, [x16, #0xd00]
   a5b78:      	add	x16, x16, #0xd00
   a5b7c:      	br	x17

00000000000a5b80 <_ZN8mtlabar38Graphics23createWithMetalAndQueueEPvS1_@plt>:
   a5b80:      	adrp	x16, 0xac000
   a5b84:      	ldr	x17, [x16, #0xd08]
   a5b88:      	add	x16, x16, #0xd08
   a5b8c:      	br	x17

00000000000a5b90 <_ZN8mtlabar38Graphics15createWithD3D11EPv@plt>:
   a5b90:      	adrp	x16, 0xac000
   a5b94:      	ldr	x17, [x16, #0xd10]
   a5b98:      	add	x16, x16, #0xd10
   a5b9c:      	br	x17

00000000000a5ba0 <_ZN8mtlabar38Graphics7destroyEPS0_@plt>:
   a5ba0:      	adrp	x16, 0xac000
   a5ba4:      	ldr	x17, [x16, #0xd18]
   a5ba8:      	add	x16, x16, #0xd18
   a5bac:      	br	x17

00000000000a5bb0 <_ZN8mtlabar38Graphics9getDeviceEv@plt>:
   a5bb0:      	adrp	x16, 0xac000
   a5bb4:      	ldr	x17, [x16, #0xd20]
   a5bb8:      	add	x16, x16, #0xd20
   a5bbc:      	br	x17

00000000000a5bc0 <_ZN8mtlabar38Graphics23createTextureWithOpenGLEmjj@plt>:
   a5bc0:      	adrp	x16, 0xac000
   a5bc4:      	ldr	x17, [x16, #0xd28]
   a5bc8:      	add	x16, x16, #0xd28
   a5bcc:      	br	x17

00000000000a5bd0 <_ZN8mtlabar38Graphics15getOpenGLHandleEP15WGPUTextureImpl@plt>:
   a5bd0:      	adrp	x16, 0xac000
   a5bd4:      	ldr	x17, [x16, #0xd30]
   a5bd8:      	add	x16, x16, #0xd30
   a5bdc:      	br	x17

00000000000a5be0 <_ZN8mtlabar38Graphics22createTextureWithMetalEPvjj@plt>:
   a5be0:      	adrp	x16, 0xac000
   a5be4:      	ldr	x17, [x16, #0xd38]
   a5be8:      	add	x16, x16, #0xd38
   a5bec:      	br	x17

00000000000a5bf0 <_ZN8mtlabar38Graphics14getMetalHandleEP15WGPUTextureImpl@plt>:
   a5bf0:      	adrp	x16, 0xac000
   a5bf4:      	ldr	x17, [x16, #0xd40]
   a5bf8:      	add	x16, x16, #0xd40
   a5bfc:      	br	x17

00000000000a5c00 <_ZN8mtlabar38Graphics29createTextureWithOpenGLFormatEmjjj@plt>:
   a5c00:      	adrp	x16, 0xac000
   a5c04:      	ldr	x17, [x16, #0xd48]
   a5c08:      	add	x16, x16, #0xd48
   a5c0c:      	br	x17

00000000000a5c10 <_ZN8mtlabar38Graphics14getD3D11HandleEP15WGPUTextureImpl@plt>:
   a5c10:      	adrp	x16, 0xac000
   a5c14:      	ldr	x17, [x16, #0xd50]
   a5c18:      	add	x16, x16, #0xd50
   a5c1c:      	br	x17

00000000000a5c20 <_ZN8mtlabar38Graphics22createTextureWithD3D11EPv@plt>:
   a5c20:      	adrp	x16, 0xac000
   a5c24:      	ldr	x17, [x16, #0xd58]
   a5c28:      	add	x16, x16, #0xd58
   a5c2c:      	br	x17

00000000000a5c30 <_ZN8mtlabar38Graphics24createWithDefaultBackendEv@plt>:
   a5c30:      	adrp	x16, 0xac000
   a5c34:      	ldr	x17, [x16, #0xd60]
   a5c38:      	add	x16, x16, #0xd60
   a5c3c:      	br	x17

00000000000a5c40 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   a5c40:      	adrp	x16, 0xac000
   a5c44:      	ldr	x17, [x16, #0xd68]
   a5c48:      	add	x16, x16, #0xd68
   a5c4c:      	br	x17

00000000000a5c50 <_ZN8mtlabar39JniHelper9setJavaVMEP7_JavaVM@plt>:
   a5c50:      	adrp	x16, 0xac000
   a5c54:      	ldr	x17, [x16, #0xd70]
   a5c58:      	add	x16, x16, #0xd70
   a5c5c:      	br	x17

00000000000a5c60 <_ZN8mtlabar39JniHelper26releaseCacheGLXBitmapClassEv@plt>:
   a5c60:      	adrp	x16, 0xac000
   a5c64:      	ldr	x17, [x16, #0xd78]
   a5c68:      	add	x16, x16, #0xd78
   a5c6c:      	br	x17

00000000000a5c70 <fprintf@plt>:
   a5c70:      	adrp	x16, 0xac000
   a5c74:      	ldr	x17, [x16, #0xd80]
   a5c78:      	add	x16, x16, #0xd80
   a5c7c:      	br	x17

00000000000a5c80 <fflush@plt>:
   a5c80:      	adrp	x16, 0xac000
   a5c84:      	ldr	x17, [x16, #0xd88]
   a5c88:      	add	x16, x16, #0xd88
   a5c8c:      	br	x17

00000000000a5c90 <abort@plt>:
   a5c90:      	adrp	x16, 0xac000
   a5c94:      	ldr	x17, [x16, #0xd90]
   a5c98:      	add	x16, x16, #0xd90
   a5c9c:      	br	x17

00000000000a5ca0 <pthread_rwlock_wrlock@plt>:
   a5ca0:      	adrp	x16, 0xac000
   a5ca4:      	ldr	x17, [x16, #0xd98]
   a5ca8:      	add	x16, x16, #0xd98
   a5cac:      	br	x17

00000000000a5cb0 <pthread_rwlock_unlock@plt>:
   a5cb0:      	adrp	x16, 0xac000
   a5cb4:      	ldr	x17, [x16, #0xda0]
   a5cb8:      	add	x16, x16, #0xda0
   a5cbc:      	br	x17

00000000000a5cc0 <malloc@plt>:
   a5cc0:      	adrp	x16, 0xac000
   a5cc4:      	ldr	x17, [x16, #0xda8]
   a5cc8:      	add	x16, x16, #0xda8
   a5ccc:      	br	x17

00000000000a5cd0 <free@plt>:
   a5cd0:      	adrp	x16, 0xac000
   a5cd4:      	ldr	x17, [x16, #0xdb0]
   a5cd8:      	add	x16, x16, #0xdb0
   a5cdc:      	br	x17

00000000000a5ce0 <dl_iterate_phdr@plt>:
   a5ce0:      	adrp	x16, 0xac000
   a5ce4:      	ldr	x17, [x16, #0xdb8]
   a5ce8:      	add	x16, x16, #0xdb8
   a5cec:      	br	x17

00000000000a5cf0 <pthread_rwlock_rdlock@plt>:
   a5cf0:      	adrp	x16, 0xac000
   a5cf4:      	ldr	x17, [x16, #0xdc0]
   a5cf8:      	add	x16, x16, #0xdc0
   a5cfc:      	br	x17

00000000000a5d00 <getpid@plt>:
   a5d00:      	adrp	x16, 0xac000
   a5d04:      	ldr	x17, [x16, #0xdc8]
   a5d08:      	add	x16, x16, #0xdc8
   a5d0c:      	br	x17

00000000000a5d10 <syscall@plt>:
   a5d10:      	adrp	x16, 0xac000
   a5d14:      	ldr	x17, [x16, #0xdd0]
   a5d18:      	add	x16, x16, #0xdd0
   a5d1c:      	br	x17

00000000000a5d20 <fwrite@plt>:
   a5d20:      	adrp	x16, 0xac000
   a5d24:      	ldr	x17, [x16, #0xdd8]
   a5d28:      	add	x16, x16, #0xdd8
   a5d2c:      	br	x17
