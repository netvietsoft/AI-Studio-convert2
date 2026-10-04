// EXPORTED & PLT DISASSEMBLY FOR libarkernel3_c.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libarkernel3_c.so (SHA-256: 549ACE66FE1522B7E9596FCE23A3A254FBEC25442F177235A10173DFF8FDE339)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 1922, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libarkernel3_c.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000071490 <.plt>:
   71490:      	stp	x16, x30, [sp, #-0x10]!
   71494:      	adrp	x16, 0x7b000
   71498:      	ldr	x17, [x16, #0x220]
   7149c:      	add	x16, x16, #0x220
   714a0:      	br	x17
   714a4:      	nop
   714a8:      	nop
   714ac:      	nop

00000000000714b0 <__cxa_finalize@plt>:
   714b0:      	adrp	x16, 0x7b000
   714b4:      	ldr	x17, [x16, #0x228]
   714b8:      	add	x16, x16, #0x228
   714bc:      	br	x17

00000000000714c0 <__cxa_atexit@plt>:
   714c0:      	adrp	x16, 0x7b000
   714c4:      	ldr	x17, [x16, #0x230]
   714c8:      	add	x16, x16, #0x230
   714cc:      	br	x17

00000000000714d0 <__register_atfork@plt>:
   714d0:      	adrp	x16, 0x7b000
   714d4:      	ldr	x17, [x16, #0x238]
   714d8:      	add	x16, x16, #0x238
   714dc:      	br	x17

00000000000714e0 <memcpy@plt>:
   714e0:      	adrp	x16, 0x7b000
   714e4:      	ldr	x17, [x16, #0x240]
   714e8:      	add	x16, x16, #0x240
   714ec:      	br	x17

00000000000714f0 <strcmp@plt>:
   714f0:      	adrp	x16, 0x7b000
   714f4:      	ldr	x17, [x16, #0x248]
   714f8:      	add	x16, x16, #0x248
   714fc:      	br	x17

0000000000071500 <free@plt>:
   71500:      	adrp	x16, 0x7b000
   71504:      	ldr	x17, [x16, #0x250]
   71508:      	add	x16, x16, #0x250
   7150c:      	br	x17

0000000000071510 <strlen@plt>:
   71510:      	adrp	x16, 0x7b000
   71514:      	ldr	x17, [x16, #0x258]
   71518:      	add	x16, x16, #0x258
   7151c:      	br	x17

0000000000071520 <malloc@plt>:
   71520:      	adrp	x16, 0x7b000
   71524:      	ldr	x17, [x16, #0x260]
   71528:      	add	x16, x16, #0x260
   7152c:      	br	x17

0000000000071530 <strcpy@plt>:
   71530:      	adrp	x16, 0x7b000
   71534:      	ldr	x17, [x16, #0x268]
   71538:      	add	x16, x16, #0x268
   7153c:      	br	x17

0000000000071540 <longjmp@plt>:
   71540:      	adrp	x16, 0x7b000
   71544:      	ldr	x17, [x16, #0x270]
   71548:      	add	x16, x16, #0x270
   7154c:      	br	x17

0000000000071550 <setjmp@plt>:
   71550:      	adrp	x16, 0x7b000
   71554:      	ldr	x17, [x16, #0x278]
   71558:      	add	x16, x16, #0x278
   7155c:      	br	x17

0000000000071560 <exit@plt>:
   71560:      	adrp	x16, 0x7b000
   71564:      	ldr	x17, [x16, #0x280]
   71568:      	add	x16, x16, #0x280
   7156c:      	br	x17

0000000000071570 <memset@plt>:
   71570:      	adrp	x16, 0x7b000
   71574:      	ldr	x17, [x16, #0x288]
   71578:      	add	x16, x16, #0x288
   7157c:      	br	x17

0000000000071580 <_Znwm@plt>:
   71580:      	adrp	x16, 0x7b000
   71584:      	ldr	x17, [x16, #0x290]
   71588:      	add	x16, x16, #0x290
   7158c:      	br	x17

0000000000071590 <_ZdlPv@plt>:
   71590:      	adrp	x16, 0x7b000
   71594:      	ldr	x17, [x16, #0x298]
   71598:      	add	x16, x16, #0x298
   7159c:      	br	x17

00000000000715a0 <__stack_chk_fail@plt>:
   715a0:      	adrp	x16, 0x7b000
   715a4:      	ldr	x17, [x16, #0x2a0]
   715a8:      	add	x16, x16, #0x2a0
   715ac:      	br	x17

00000000000715b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   715b0:      	adrp	x16, 0x7b000
   715b4:      	ldr	x17, [x16, #0x2a8]
   715b8:      	add	x16, x16, #0x2a8
   715bc:      	br	x17

00000000000715c0 <memmove@plt>:
   715c0:      	adrp	x16, 0x7b000
   715c4:      	ldr	x17, [x16, #0x2b0]
   715c8:      	add	x16, x16, #0x2b0
   715cc:      	br	x17

00000000000715d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   715d0:      	adrp	x16, 0x7b000
   715d4:      	ldr	x17, [x16, #0x2b8]
   715d8:      	add	x16, x16, #0x2b8
   715dc:      	br	x17

00000000000715e0 <strncpy@plt>:
   715e0:      	adrp	x16, 0x7b000
   715e4:      	ldr	x17, [x16, #0x2c0]
   715e8:      	add	x16, x16, #0x2c0
   715ec:      	br	x17

00000000000715f0 <_ZNK8mtlabar317DetailEnumeration14getDisplayNameEv@plt>:
   715f0:      	adrp	x16, 0x7b000
   715f4:      	ldr	x17, [x16, #0x2c8]
   715f8:      	add	x16, x16, #0x2c8
   715fc:      	br	x17

0000000000071600 <_ZNK8mtlabar317DetailEnumeration15getElementCountEv@plt>:
   71600:      	adrp	x16, 0x7b000
   71604:      	ldr	x17, [x16, #0x2d0]
   71608:      	add	x16, x16, #0x2d0
   7160c:      	br	x17

0000000000071610 <_ZNK8mtlabar317DetailEnumeration15getElementValueEm@plt>:
   71610:      	adrp	x16, 0x7b000
   71614:      	ldr	x17, [x16, #0x2d8]
   71618:      	add	x16, x16, #0x2d8
   7161c:      	br	x17

0000000000071620 <_ZNK8mtlabar317DetailEnumeration21getElementDisplayNameEm@plt>:
   71620:      	adrp	x16, 0x7b000
   71624:      	ldr	x17, [x16, #0x2e0]
   71628:      	add	x16, x16, #0x2e0
   7162c:      	br	x17

0000000000071630 <_ZNK8mtlabar38Property14getDisplayNameEv@plt>:
   71630:      	adrp	x16, 0x7b000
   71634:      	ldr	x17, [x16, #0x2e8]
   71638:      	add	x16, x16, #0x2e8
   7163c:      	br	x17

0000000000071640 <_ZNK8mtlabar38Property7getTypeEv@plt>:
   71640:      	adrp	x16, 0x7b000
   71644:      	ldr	x17, [x16, #0x2f0]
   71648:      	add	x16, x16, #0x2f0
   7164c:      	br	x17

0000000000071650 <_ZNK8mtlabar38Property8isHideUIEv@plt>:
   71650:      	adrp	x16, 0x7b000
   71654:      	ldr	x17, [x16, #0x2f8]
   71658:      	add	x16, x16, #0x2f8
   7165c:      	br	x17

0000000000071660 <_ZNK8mtlabar38Property15getDefaultValueEv@plt>:
   71660:      	adrp	x16, 0x7b000
   71664:      	ldr	x17, [x16, #0x300]
   71668:      	add	x16, x16, #0x300
   7166c:      	br	x17

0000000000071670 <_ZNK8mtlabar38Property10getMaximumEv@plt>:
   71670:      	adrp	x16, 0x7b000
   71674:      	ldr	x17, [x16, #0x308]
   71678:      	add	x16, x16, #0x308
   7167c:      	br	x17

0000000000071680 <_ZNK8mtlabar38Property10getMinimumEv@plt>:
   71680:      	adrp	x16, 0x7b000
   71684:      	ldr	x17, [x16, #0x310]
   71688:      	add	x16, x16, #0x310
   7168c:      	br	x17

0000000000071690 <_ZNK8mtlabar314DetailCategory14getDisplayNameEv@plt>:
   71690:      	adrp	x16, 0x7b000
   71694:      	ldr	x17, [x16, #0x318]
   71698:      	add	x16, x16, #0x318
   7169c:      	br	x17

00000000000716a0 <_ZNK8mtlabar314DetailCategory21getBasicCategoryCountEv@plt>:
   716a0:      	adrp	x16, 0x7b000
   716a4:      	ldr	x17, [x16, #0x320]
   716a8:      	add	x16, x16, #0x320
   716ac:      	br	x17

00000000000716b0 <_ZNK8mtlabar314DetailCategory16getBasicCategoryEm@plt>:
   716b0:      	adrp	x16, 0x7b000
   716b4:      	ldr	x17, [x16, #0x328]
   716b8:      	add	x16, x16, #0x328
   716bc:      	br	x17

00000000000716c0 <_ZNK8mtlabar314DetailCategory16getPropertyCountEv@plt>:
   716c0:      	adrp	x16, 0x7b000
   716c4:      	ldr	x17, [x16, #0x330]
   716c8:      	add	x16, x16, #0x330
   716cc:      	br	x17

00000000000716d0 <_ZNK8mtlabar314DetailCategory11getPropertyEm@plt>:
   716d0:      	adrp	x16, 0x7b000
   716d4:      	ldr	x17, [x16, #0x338]
   716d8:      	add	x16, x16, #0x338
   716dc:      	br	x17

00000000000716e0 <_ZNK8mtlabar35Field7getTypeEv@plt>:
   716e0:      	adrp	x16, 0x7b000
   716e4:      	ldr	x17, [x16, #0x340]
   716e8:      	add	x16, x16, #0x340
   716ec:      	br	x17

00000000000716f0 <_ZNK8mtlabar35Field8getValueEv@plt>:
   716f0:      	adrp	x16, 0x7b000
   716f4:      	ldr	x17, [x16, #0x348]
   716f8:      	add	x16, x16, #0x348
   716fc:      	br	x17

0000000000071700 <_ZN8mtlabar35Field8setValueERKNS_14ParameterValueE@plt>:
   71700:      	adrp	x16, 0x7b000
   71704:      	ldr	x17, [x16, #0x350]
   71708:      	add	x16, x16, #0x350
   7170c:      	br	x17

0000000000071710 <_ZNK8mtlabar35Field13getChildCountEv@plt>:
   71710:      	adrp	x16, 0x7b000
   71714:      	ldr	x17, [x16, #0x358]
   71718:      	add	x16, x16, #0x358
   7171c:      	br	x17

0000000000071720 <_ZN8mtlabar35Field15getChildByIndexEm@plt>:
   71720:      	adrp	x16, 0x7b000
   71724:      	ldr	x17, [x16, #0x360]
   71728:      	add	x16, x16, #0x360
   7172c:      	br	x17

0000000000071730 <_ZN8mtlabar35Field14getChildByNameEPKc@plt>:
   71730:      	adrp	x16, 0x7b000
   71734:      	ldr	x17, [x16, #0x368]
   71738:      	add	x16, x16, #0x368
   7173c:      	br	x17

0000000000071740 <_ZN8mtlabar35Field11resizeChildEm@plt>:
   71740:      	adrp	x16, 0x7b000
   71744:      	ldr	x17, [x16, #0x370]
   71748:      	add	x16, x16, #0x370
   7174c:      	br	x17

0000000000071750 <_ZN8mtlabar35Field10eraseChildEm@plt>:
   71750:      	adrp	x16, 0x7b000
   71754:      	ldr	x17, [x16, #0x378]
   71758:      	add	x16, x16, #0x378
   7175c:      	br	x17

0000000000071760 <_ZNK8mtlabar35Field17getBaseClassCountEv@plt>:
   71760:      	adrp	x16, 0x7b000
   71764:      	ldr	x17, [x16, #0x380]
   71768:      	add	x16, x16, #0x380
   7176c:      	br	x17

0000000000071770 <_ZN8mtlabar35Field19getBaseClassByIndexEm@plt>:
   71770:      	adrp	x16, 0x7b000
   71774:      	ldr	x17, [x16, #0x388]
   71778:      	add	x16, x16, #0x388
   7177c:      	br	x17

0000000000071780 <_ZNK8mtlabar35Field17detailEnumerationEv@plt>:
   71780:      	adrp	x16, 0x7b000
   71784:      	ldr	x17, [x16, #0x390]
   71788:      	add	x16, x16, #0x390
   7178c:      	br	x17

0000000000071790 <_ZNK8mtlabar35Field14detailCategoryEv@plt>:
   71790:      	adrp	x16, 0x7b000
   71794:      	ldr	x17, [x16, #0x398]
   71798:      	add	x16, x16, #0x398
   7179c:      	br	x17

00000000000717a0 <_ZN8mtlabar313LayoutDetails15getCurrentFieldEv@plt>:
   717a0:      	adrp	x16, 0x7b000
   717a4:      	ldr	x17, [x16, #0x3a0]
   717a8:      	add	x16, x16, #0x3a0
   717ac:      	br	x17

00000000000717b0 <_ZNK8mtlabar313LayoutDetails11getCategoryERKPKc@plt>:
   717b0:      	adrp	x16, 0x7b000
   717b4:      	ldr	x17, [x16, #0x3a8]
   717b8:      	add	x16, x16, #0x3a8
   717bc:      	br	x17

00000000000717c0 <_ZNK8mtlabar313LayoutDetails14getEnumerationERKPKc@plt>:
   717c0:      	adrp	x16, 0x7b000
   717c4:      	ldr	x17, [x16, #0x3b0]
   717c8:      	add	x16, x16, #0x3b0
   717cc:      	br	x17

00000000000717d0 <_ZN8mtlabar327ChannelTextureDataInterface17setChannelTextureENS_21MultiInputChannelTypeEP15WGPUTextureImpl@plt>:
   717d0:      	adrp	x16, 0x7b000
   717d4:      	ldr	x17, [x16, #0x3b8]
   717d8:      	add	x16, x16, #0x3b8
   717dc:      	br	x17

00000000000717e0 <_ZNK8mtlabar327ChannelTextureDataInterface17getChannelTextureENS_21MultiInputChannelTypeE@plt>:
   717e0:      	adrp	x16, 0x7b000
   717e4:      	ldr	x17, [x16, #0x3c0]
   717e8:      	add	x16, x16, #0x3c0
   717ec:      	br	x17

00000000000717f0 <_ZN8mtlabar327ChannelTextureDataInterface22resetAllChannelTextureEv@plt>:
   717f0:      	adrp	x16, 0x7b000
   717f4:      	ldr	x17, [x16, #0x3c8]
   717f8:      	add	x16, x16, #0x3c8
   717fc:      	br	x17

0000000000071800 <_ZNK8mtlabar327ChannelTextureDataInterface22getChannelTextureWidthENS_21MultiInputChannelTypeE@plt>:
   71800:      	adrp	x16, 0x7b000
   71804:      	ldr	x17, [x16, #0x3d0]
   71808:      	add	x16, x16, #0x3d0
   7180c:      	br	x17

0000000000071810 <_ZNK8mtlabar327ChannelTextureDataInterface23getChannelTextureHeightENS_21MultiInputChannelTypeE@plt>:
   71810:      	adrp	x16, 0x7b000
   71814:      	ldr	x17, [x16, #0x3d8]
   71818:      	add	x16, x16, #0x3d8
   7181c:      	br	x17

0000000000071820 <_ZN8mtlabar324MainTextureDataInterface15setMainTextureAEP15WGPUTextureImpl@plt>:
   71820:      	adrp	x16, 0x7b000
   71824:      	ldr	x17, [x16, #0x3e0]
   71828:      	add	x16, x16, #0x3e0
   7182c:      	br	x17

0000000000071830 <_ZN8mtlabar324MainTextureDataInterface15setMainTextureBEP15WGPUTextureImpl@plt>:
   71830:      	adrp	x16, 0x7b000
   71834:      	ldr	x17, [x16, #0x3e8]
   71838:      	add	x16, x16, #0x3e8
   7183c:      	br	x17

0000000000071840 <_ZN8mtlabar324MainTextureDataInterface24setMainTextureColorSpaceENS_10ColorSpaceE@plt>:
   71840:      	adrp	x16, 0x7b000
   71844:      	ldr	x17, [x16, #0x3f0]
   71848:      	add	x16, x16, #0x3f0
   7184c:      	br	x17

0000000000071850 <_ZN8mtlabar324MainTextureDataInterface18releaseMainTextureEv@plt>:
   71850:      	adrp	x16, 0x7b000
   71854:      	ldr	x17, [x16, #0x3f8]
   71858:      	add	x16, x16, #0x3f8
   7185c:      	br	x17

0000000000071860 <_ZNK8mtlabar324MainTextureDataInterface15getMainTextureAEv@plt>:
   71860:      	adrp	x16, 0x7b000
   71864:      	ldr	x17, [x16, #0x400]
   71868:      	add	x16, x16, #0x400
   7186c:      	br	x17

0000000000071870 <_ZNK8mtlabar324MainTextureDataInterface15getMainTextureBEv@plt>:
   71870:      	adrp	x16, 0x7b000
   71874:      	ldr	x17, [x16, #0x408]
   71878:      	add	x16, x16, #0x408
   7187c:      	br	x17

0000000000071880 <_ZNK8mtlabar324MainTextureDataInterface15getTextureWidthEv@plt>:
   71880:      	adrp	x16, 0x7b000
   71884:      	ldr	x17, [x16, #0x410]
   71888:      	add	x16, x16, #0x410
   7188c:      	br	x17

0000000000071890 <_ZNK8mtlabar324MainTextureDataInterface16getTextureHeightEv@plt>:
   71890:      	adrp	x16, 0x7b000
   71894:      	ldr	x17, [x16, #0x418]
   71898:      	add	x16, x16, #0x418
   7189c:      	br	x17

00000000000718a0 <_ZN8mtlabar318FrameInfoInterface24setDeviceOrientationTypeE21DeviceOrientationType@plt>:
   718a0:      	adrp	x16, 0x7b000
   718a4:      	ldr	x17, [x16, #0x420]
   718a8:      	add	x16, x16, #0x420
   718ac:      	br	x17

00000000000718b0 <_ZNK8mtlabar318FrameInfoInterface24getDeviceOrientationTypeEv@plt>:
   718b0:      	adrp	x16, 0x7b000
   718b4:      	ldr	x17, [x16, #0x428]
   718b8:      	add	x16, x16, #0x428
   718bc:      	br	x17

00000000000718c0 <_ZN8mtlabar318FrameInfoInterface18setFrameInfoOptionE15FrameInfoOptionb@plt>:
   718c0:      	adrp	x16, 0x7b000
   718c4:      	ldr	x17, [x16, #0x430]
   718c8:      	add	x16, x16, #0x430
   718cc:      	br	x17

00000000000718d0 <_ZNK8mtlabar318FrameInfoInterface18getFrameInfoOptionE15FrameInfoOption@plt>:
   718d0:      	adrp	x16, 0x7b000
   718d4:      	ldr	x17, [x16, #0x438]
   718d8:      	add	x16, x16, #0x438
   718dc:      	br	x17

00000000000718e0 <_ZN8mtlabar318FrameDataInterface27getMainTextureDataInterfaceEv@plt>:
   718e0:      	adrp	x16, 0x7b000
   718e4:      	ldr	x17, [x16, #0x440]
   718e8:      	add	x16, x16, #0x440
   718ec:      	br	x17

00000000000718f0 <_ZN8mtlabar318FrameDataInterface30getChannelTextureDataInterfaceEv@plt>:
   718f0:      	adrp	x16, 0x7b000
   718f4:      	ldr	x17, [x16, #0x448]
   718f8:      	add	x16, x16, #0x448
   718fc:      	br	x17

0000000000071900 <_ZN8mtlabar318FrameDataInterface21getFrameInfoInterfaceEv@plt>:
   71900:      	adrp	x16, 0x7b000
   71904:      	ldr	x17, [x16, #0x450]
   71908:      	add	x16, x16, #0x450
   7190c:      	br	x17

0000000000071910 <_ZN8mtlabar318FrameDataInterface15setDataProtocolEP18vldp_data_protocol@plt>:
   71910:      	adrp	x16, 0x7b000
   71914:      	ldr	x17, [x16, #0x458]
   71918:      	add	x16, x16, #0x458
   7191c:      	br	x17

0000000000071920 <_ZNK8mtlabar318FrameDataInterface15getDataProtocolEv@plt>:
   71920:      	adrp	x16, 0x7b000
   71924:      	ldr	x17, [x16, #0x460]
   71928:      	add	x16, x16, #0x460
   7192c:      	br	x17

0000000000071930 <_ZNK8mtlabar38FaceData9hasFaceIDEv@plt>:
   71930:      	adrp	x16, 0x7b000
   71934:      	ldr	x17, [x16, #0x468]
   71938:      	add	x16, x16, #0x468
   7193c:      	br	x17

0000000000071940 <_ZNK8mtlabar38FaceData9getFaceIDEv@plt>:
   71940:      	adrp	x16, 0x7b000
   71944:      	ldr	x17, [x16, #0x470]
   71948:      	add	x16, x16, #0x470
   7194c:      	br	x17

0000000000071950 <_ZN8mtlabar38FaceData9setFaceIDEi@plt>:
   71950:      	adrp	x16, 0x7b000
   71954:      	ldr	x17, [x16, #0x478]
   71958:      	add	x16, x16, #0x478
   7195c:      	br	x17

0000000000071960 <_ZNK8mtlabar38FaceData11hasFaceRectEv@plt>:
   71960:      	adrp	x16, 0x7b000
   71964:      	ldr	x17, [x16, #0x480]
   71968:      	add	x16, x16, #0x480
   7196c:      	br	x17

0000000000071970 <_ZNK8mtlabar38FaceData11getFaceRectEv@plt>:
   71970:      	adrp	x16, 0x7b000
   71974:      	ldr	x17, [x16, #0x488]
   71978:      	add	x16, x16, #0x488
   7197c:      	br	x17

0000000000071980 <_ZN8mtlabar38FaceData11setFaceRectERKNS_6Rect2FE@plt>:
   71980:      	adrp	x16, 0x7b000
   71984:      	ldr	x17, [x16, #0x490]
   71988:      	add	x16, x16, #0x490
   7198c:      	br	x17

0000000000071990 <_ZNK8mtlabar38FaceData24getFacialLandmark2DCountEv@plt>:
   71990:      	adrp	x16, 0x7b000
   71994:      	ldr	x17, [x16, #0x498]
   71998:      	add	x16, x16, #0x498
   7199c:      	br	x17

00000000000719a0 <_ZNK8mtlabar38FaceData19getFacialLandmark2DEv@plt>:
   719a0:      	adrp	x16, 0x7b000
   719a4:      	ldr	x17, [x16, #0x4a0]
   719a8:      	add	x16, x16, #0x4a0
   719ac:      	br	x17

00000000000719b0 <_ZN8mtlabar38FaceData19setFacialLandmark2DEPKNS_6Float2Ei@plt>:
   719b0:      	adrp	x16, 0x7b000
   719b4:      	ldr	x17, [x16, #0x4a8]
   719b8:      	add	x16, x16, #0x4a8
   719bc:      	br	x17

00000000000719c0 <_ZNK8mtlabar38FaceData31getFacialLandmark2DVisibleCountEv@plt>:
   719c0:      	adrp	x16, 0x7b000
   719c4:      	ldr	x17, [x16, #0x4b0]
   719c8:      	add	x16, x16, #0x4b0
   719cc:      	br	x17

00000000000719d0 <_ZNK8mtlabar38FaceData26getFacialLandmark2DVisibleEv@plt>:
   719d0:      	adrp	x16, 0x7b000
   719d4:      	ldr	x17, [x16, #0x4b8]
   719d8:      	add	x16, x16, #0x4b8
   719dc:      	br	x17

00000000000719e0 <_ZN8mtlabar38FaceData26setFacialLandmark2DVisibleEPKfi@plt>:
   719e0:      	adrp	x16, 0x7b000
   719e4:      	ldr	x17, [x16, #0x4c0]
   719e8:      	add	x16, x16, #0x4c0
   719ec:      	br	x17

00000000000719f0 <_ZNK8mtlabar38FaceData17getHeadPointCountEv@plt>:
   719f0:      	adrp	x16, 0x7b000
   719f4:      	ldr	x17, [x16, #0x4c8]
   719f8:      	add	x16, x16, #0x4c8
   719fc:      	br	x17

0000000000071a00 <_ZNK8mtlabar38FaceData13getHeadPointsEv@plt>:
   71a00:      	adrp	x16, 0x7b000
   71a04:      	ldr	x17, [x16, #0x4d0]
   71a08:      	add	x16, x16, #0x4d0
   71a0c:      	br	x17

0000000000071a10 <_ZN8mtlabar38FaceData13setHeadPointsEPKNS_6Float2Ei@plt>:
   71a10:      	adrp	x16, 0x7b000
   71a14:      	ldr	x17, [x16, #0x4d8]
   71a18:      	add	x16, x16, #0x4d8
   71a1c:      	br	x17

0000000000071a20 <_ZNK8mtlabar38FaceData24getFacialInterPointCountEv@plt>:
   71a20:      	adrp	x16, 0x7b000
   71a24:      	ldr	x17, [x16, #0x4e0]
   71a28:      	add	x16, x16, #0x4e0
   71a2c:      	br	x17

0000000000071a30 <_ZNK8mtlabar38FaceData19getFacialInterPointEv@plt>:
   71a30:      	adrp	x16, 0x7b000
   71a34:      	ldr	x17, [x16, #0x4e8]
   71a38:      	add	x16, x16, #0x4e8
   71a3c:      	br	x17

0000000000071a40 <_ZN8mtlabar38FaceData19setFacialInterPointEPKNS_6Float2Ei@plt>:
   71a40:      	adrp	x16, 0x7b000
   71a44:      	ldr	x17, [x16, #0x4f0]
   71a48:      	add	x16, x16, #0x4f0
   71a4c:      	br	x17

0000000000071a50 <_ZNK8mtlabar38FaceData32getFacialInterPointNewModelCountEv@plt>:
   71a50:      	adrp	x16, 0x7b000
   71a54:      	ldr	x17, [x16, #0x4f8]
   71a58:      	add	x16, x16, #0x4f8
   71a5c:      	br	x17

0000000000071a60 <_ZNK8mtlabar38FaceData27getFacialInterPointNewModelEv@plt>:
   71a60:      	adrp	x16, 0x7b000
   71a64:      	ldr	x17, [x16, #0x500]
   71a68:      	add	x16, x16, #0x500
   71a6c:      	br	x17

0000000000071a70 <_ZN8mtlabar38FaceData27setFacialInterPointNewModelEPKNS_6Float2Ei@plt>:
   71a70:      	adrp	x16, 0x7b000
   71a74:      	ldr	x17, [x16, #0x508]
   71a78:      	add	x16, x16, #0x508
   71a7c:      	br	x17

0000000000071a80 <_ZNK8mtlabar317FaceDataInterface13getDetectSizeEv@plt>:
   71a80:      	adrp	x16, 0x7b000
   71a84:      	ldr	x17, [x16, #0x510]
   71a88:      	add	x16, x16, #0x510
   71a8c:      	br	x17

0000000000071a90 <_ZN8mtlabar317FaceDataInterface13setDetectSizeERKNS_5SizeFE@plt>:
   71a90:      	adrp	x16, 0x7b000
   71a94:      	ldr	x17, [x16, #0x518]
   71a98:      	add	x16, x16, #0x518
   71a9c:      	br	x17

0000000000071aa0 <_ZNK8mtlabar317FaceDataInterface12getFaceCountEv@plt>:
   71aa0:      	adrp	x16, 0x7b000
   71aa4:      	ldr	x17, [x16, #0x520]
   71aa8:      	add	x16, x16, #0x520
   71aac:      	br	x17

0000000000071ab0 <_ZNK8mtlabar317FaceDataInterface21getFaceDataArrayConstEv@plt>:
   71ab0:      	adrp	x16, 0x7b000
   71ab4:      	ldr	x17, [x16, #0x528]
   71ab8:      	add	x16, x16, #0x528
   71abc:      	br	x17

0000000000071ac0 <_ZN8mtlabar317FaceDataInterface16getFaceDataArrayEv@plt>:
   71ac0:      	adrp	x16, 0x7b000
   71ac4:      	ldr	x17, [x16, #0x530]
   71ac8:      	add	x16, x16, #0x530
   71acc:      	br	x17

0000000000071ad0 <_ZN8mtlabar317FaceDataInterface16setFaceDataArrayEPKNS_8FaceDataEi@plt>:
   71ad0:      	adrp	x16, 0x7b000
   71ad4:      	ldr	x17, [x16, #0x538]
   71ad8:      	add	x16, x16, #0x538
   71adc:      	br	x17

0000000000071ae0 <_ZdaPv@plt>:
   71ae0:      	adrp	x16, 0x7b000
   71ae4:      	ldr	x17, [x16, #0x540]
   71ae8:      	add	x16, x16, #0x540
   71aec:      	br	x17

0000000000071af0 <_Znam@plt>:
   71af0:      	adrp	x16, 0x7b000
   71af4:      	ldr	x17, [x16, #0x548]
   71af8:      	add	x16, x16, #0x548
   71afc:      	br	x17

0000000000071b00 <_ZN8mtlabar332TextBackgroundColorConfiguration6createEv@plt>:
   71b00:      	adrp	x16, 0x7b000
   71b04:      	ldr	x17, [x16, #0x550]
   71b08:      	add	x16, x16, #0x550
   71b0c:      	br	x17

0000000000071b10 <_ZN8mtlabar332TextBackgroundColorConfiguration7destroyEPS0_@plt>:
   71b10:      	adrp	x16, 0x7b000
   71b14:      	ldr	x17, [x16, #0x558]
   71b18:      	add	x16, x16, #0x558
   71b1c:      	br	x17

0000000000071b20 <_ZN8mtlabar332TextBackgroundColorConfiguration8deepCopyEPKS0_@plt>:
   71b20:      	adrp	x16, 0x7b000
   71b24:      	ldr	x17, [x16, #0x560]
   71b28:      	add	x16, x16, #0x560
   71b2c:      	br	x17

0000000000071b30 <_ZNK8mtlabar332TextBackgroundColorConfiguration9getEnableEv@plt>:
   71b30:      	adrp	x16, 0x7b000
   71b34:      	ldr	x17, [x16, #0x568]
   71b38:      	add	x16, x16, #0x568
   71b3c:      	br	x17

0000000000071b40 <_ZN8mtlabar332TextBackgroundColorConfiguration9setEnableEb@plt>:
   71b40:      	adrp	x16, 0x7b000
   71b44:      	ldr	x17, [x16, #0x570]
   71b48:      	add	x16, x16, #0x570
   71b4c:      	br	x17

0000000000071b50 <_ZNK8mtlabar332TextBackgroundColorConfiguration11getEditableEv@plt>:
   71b50:      	adrp	x16, 0x7b000
   71b54:      	ldr	x17, [x16, #0x578]
   71b58:      	add	x16, x16, #0x578
   71b5c:      	br	x17

0000000000071b60 <_ZN8mtlabar332TextBackgroundColorConfiguration11setEditableEb@plt>:
   71b60:      	adrp	x16, 0x7b000
   71b64:      	ldr	x17, [x16, #0x580]
   71b68:      	add	x16, x16, #0x580
   71b6c:      	br	x17

0000000000071b70 <_ZNK8mtlabar332TextBackgroundColorConfiguration9getColorAEv@plt>:
   71b70:      	adrp	x16, 0x7b000
   71b74:      	ldr	x17, [x16, #0x588]
   71b78:      	add	x16, x16, #0x588
   71b7c:      	br	x17

0000000000071b80 <_ZN8mtlabar332TextBackgroundColorConfiguration9setColorAERKNS_6ColorAE@plt>:
   71b80:      	adrp	x16, 0x7b000
   71b84:      	ldr	x17, [x16, #0x590]
   71b88:      	add	x16, x16, #0x590
   71b8c:      	br	x17

0000000000071b90 <_ZNK8mtlabar332TextBackgroundColorConfiguration12getColorWorkEv@plt>:
   71b90:      	adrp	x16, 0x7b000
   71b94:      	ldr	x17, [x16, #0x598]
   71b98:      	add	x16, x16, #0x598
   71b9c:      	br	x17

0000000000071ba0 <_ZN8mtlabar332TextBackgroundColorConfiguration12setColorWorkEb@plt>:
   71ba0:      	adrp	x16, 0x7b000
   71ba4:      	ldr	x17, [x16, #0x5a0]
   71ba8:      	add	x16, x16, #0x5a0
   71bac:      	br	x17

0000000000071bb0 <_ZNK8mtlabar332TextBackgroundColorConfiguration9getMarginEv@plt>:
   71bb0:      	adrp	x16, 0x7b000
   71bb4:      	ldr	x17, [x16, #0x5a8]
   71bb8:      	add	x16, x16, #0x5a8
   71bbc:      	br	x17

0000000000071bc0 <_ZN8mtlabar332TextBackgroundColorConfiguration9setMarginEi@plt>:
   71bc0:      	adrp	x16, 0x7b000
   71bc4:      	ldr	x17, [x16, #0x5b0]
   71bc8:      	add	x16, x16, #0x5b0
   71bcc:      	br	x17

0000000000071bd0 <_ZNK8mtlabar332TextBackgroundColorConfiguration14getRoundWeightEv@plt>:
   71bd0:      	adrp	x16, 0x7b000
   71bd4:      	ldr	x17, [x16, #0x5b8]
   71bd8:      	add	x16, x16, #0x5b8
   71bdc:      	br	x17

0000000000071be0 <_ZN8mtlabar332TextBackgroundColorConfiguration14setRoundWeightEf@plt>:
   71be0:      	adrp	x16, 0x7b000
   71be4:      	ldr	x17, [x16, #0x5c0]
   71be8:      	add	x16, x16, #0x5c0
   71bec:      	br	x17

0000000000071bf0 <_ZNK8mtlabar332TextBackgroundColorConfiguration19getMarginExtendCoefEv@plt>:
   71bf0:      	adrp	x16, 0x7b000
   71bf4:      	ldr	x17, [x16, #0x5c8]
   71bf8:      	add	x16, x16, #0x5c8
   71bfc:      	br	x17

0000000000071c00 <_ZN8mtlabar332TextBackgroundColorConfiguration19setMarginExtendCoefERKNS_5RectFE@plt>:
   71c00:      	adrp	x16, 0x7b000
   71c04:      	ldr	x17, [x16, #0x5d0]
   71c08:      	add	x16, x16, #0x5d0
   71c0c:      	br	x17

0000000000071c10 <_ZN8mtlabar332TextBackgroundColorConfiguration15setMarginShiftXEf@plt>:
   71c10:      	adrp	x16, 0x7b000
   71c14:      	ldr	x17, [x16, #0x5d8]
   71c18:      	add	x16, x16, #0x5d8
   71c1c:      	br	x17

0000000000071c20 <_ZNK8mtlabar332TextBackgroundColorConfiguration15getMarginShiftXEv@plt>:
   71c20:      	adrp	x16, 0x7b000
   71c24:      	ldr	x17, [x16, #0x5e0]
   71c28:      	add	x16, x16, #0x5e0
   71c2c:      	br	x17

0000000000071c30 <_ZN8mtlabar332TextBackgroundColorConfiguration15setMarginShiftYEf@plt>:
   71c30:      	adrp	x16, 0x7b000
   71c34:      	ldr	x17, [x16, #0x5e8]
   71c38:      	add	x16, x16, #0x5e8
   71c3c:      	br	x17

0000000000071c40 <_ZNK8mtlabar332TextBackgroundColorConfiguration15getMarginShiftYEv@plt>:
   71c40:      	adrp	x16, 0x7b000
   71c44:      	ldr	x17, [x16, #0x5f0]
   71c48:      	add	x16, x16, #0x5f0
   71c4c:      	br	x17

0000000000071c50 <_ZN8mtlabar332TextBackgroundColorConfiguration16setMarginExtendXEf@plt>:
   71c50:      	adrp	x16, 0x7b000
   71c54:      	ldr	x17, [x16, #0x5f8]
   71c58:      	add	x16, x16, #0x5f8
   71c5c:      	br	x17

0000000000071c60 <_ZNK8mtlabar332TextBackgroundColorConfiguration16getMarginExtendXEv@plt>:
   71c60:      	adrp	x16, 0x7b000
   71c64:      	ldr	x17, [x16, #0x600]
   71c68:      	add	x16, x16, #0x600
   71c6c:      	br	x17

0000000000071c70 <_ZN8mtlabar332TextBackgroundColorConfiguration16setMarginExtendYEf@plt>:
   71c70:      	adrp	x16, 0x7b000
   71c74:      	ldr	x17, [x16, #0x608]
   71c78:      	add	x16, x16, #0x608
   71c7c:      	br	x17

0000000000071c80 <_ZNK8mtlabar332TextBackgroundColorConfiguration16getMarginExtendYEv@plt>:
   71c80:      	adrp	x16, 0x7b000
   71c84:      	ldr	x17, [x16, #0x610]
   71c88:      	add	x16, x16, #0x610
   71c8c:      	br	x17

0000000000071c90 <_ZN8mtlabar332TextBackgroundColorConfiguration11setFillTypeENS_4text14TextBgFillTypeE@plt>:
   71c90:      	adrp	x16, 0x7b000
   71c94:      	ldr	x17, [x16, #0x618]
   71c98:      	add	x16, x16, #0x618
   71c9c:      	br	x17

0000000000071ca0 <_ZNK8mtlabar332TextBackgroundColorConfiguration11getFillTypeEv@plt>:
   71ca0:      	adrp	x16, 0x7b000
   71ca4:      	ldr	x17, [x16, #0x620]
   71ca8:      	add	x16, x16, #0x620
   71cac:      	br	x17

0000000000071cb0 <_ZN8mtlabar321TextGlowConfiguration6createEv@plt>:
   71cb0:      	adrp	x16, 0x7b000
   71cb4:      	ldr	x17, [x16, #0x628]
   71cb8:      	add	x16, x16, #0x628
   71cbc:      	br	x17

0000000000071cc0 <_ZN8mtlabar321TextGlowConfiguration7destroyEPS0_@plt>:
   71cc0:      	adrp	x16, 0x7b000
   71cc4:      	ldr	x17, [x16, #0x630]
   71cc8:      	add	x16, x16, #0x630
   71ccc:      	br	x17

0000000000071cd0 <_ZN8mtlabar321TextGlowConfiguration8deepCopyEPKS0_@plt>:
   71cd0:      	adrp	x16, 0x7b000
   71cd4:      	ldr	x17, [x16, #0x638]
   71cd8:      	add	x16, x16, #0x638
   71cdc:      	br	x17

0000000000071ce0 <_ZNK8mtlabar321TextGlowConfiguration9getEnableEv@plt>:
   71ce0:      	adrp	x16, 0x7b000
   71ce4:      	ldr	x17, [x16, #0x640]
   71ce8:      	add	x16, x16, #0x640
   71cec:      	br	x17

0000000000071cf0 <_ZN8mtlabar321TextGlowConfiguration9setEnableEb@plt>:
   71cf0:      	adrp	x16, 0x7b000
   71cf4:      	ldr	x17, [x16, #0x648]
   71cf8:      	add	x16, x16, #0x648
   71cfc:      	br	x17

0000000000071d00 <_ZNK8mtlabar321TextGlowConfiguration11getEditableEv@plt>:
   71d00:      	adrp	x16, 0x7b000
   71d04:      	ldr	x17, [x16, #0x650]
   71d08:      	add	x16, x16, #0x650
   71d0c:      	br	x17

0000000000071d10 <_ZN8mtlabar321TextGlowConfiguration11setEditableEb@plt>:
   71d10:      	adrp	x16, 0x7b000
   71d14:      	ldr	x17, [x16, #0x658]
   71d18:      	add	x16, x16, #0x658
   71d1c:      	br	x17

0000000000071d20 <_ZNK8mtlabar321TextGlowConfiguration9getColorAEv@plt>:
   71d20:      	adrp	x16, 0x7b000
   71d24:      	ldr	x17, [x16, #0x660]
   71d28:      	add	x16, x16, #0x660
   71d2c:      	br	x17

0000000000071d30 <_ZN8mtlabar321TextGlowConfiguration9setColorAERKNS_6ColorAE@plt>:
   71d30:      	adrp	x16, 0x7b000
   71d34:      	ldr	x17, [x16, #0x668]
   71d38:      	add	x16, x16, #0x668
   71d3c:      	br	x17

0000000000071d40 <_ZNK8mtlabar321TextGlowConfiguration12getColorWorkEv@plt>:
   71d40:      	adrp	x16, 0x7b000
   71d44:      	ldr	x17, [x16, #0x670]
   71d48:      	add	x16, x16, #0x670
   71d4c:      	br	x17

0000000000071d50 <_ZN8mtlabar321TextGlowConfiguration12setColorWorkEb@plt>:
   71d50:      	adrp	x16, 0x7b000
   71d54:      	ldr	x17, [x16, #0x678]
   71d58:      	add	x16, x16, #0x678
   71d5c:      	br	x17

0000000000071d60 <_ZNK8mtlabar321TextGlowConfiguration7getBlurEv@plt>:
   71d60:      	adrp	x16, 0x7b000
   71d64:      	ldr	x17, [x16, #0x680]
   71d68:      	add	x16, x16, #0x680
   71d6c:      	br	x17

0000000000071d70 <_ZN8mtlabar321TextGlowConfiguration7setBlurEf@plt>:
   71d70:      	adrp	x16, 0x7b000
   71d74:      	ldr	x17, [x16, #0x688]
   71d78:      	add	x16, x16, #0x688
   71d7c:      	br	x17

0000000000071d80 <_ZNK8mtlabar321TextGlowConfiguration14getStrokeWidthEv@plt>:
   71d80:      	adrp	x16, 0x7b000
   71d84:      	ldr	x17, [x16, #0x690]
   71d88:      	add	x16, x16, #0x690
   71d8c:      	br	x17

0000000000071d90 <_ZN8mtlabar321TextGlowConfiguration14setStrokeWidthEf@plt>:
   71d90:      	adrp	x16, 0x7b000
   71d94:      	ldr	x17, [x16, #0x698]
   71d98:      	add	x16, x16, #0x698
   71d9c:      	br	x17

0000000000071da0 <_ZN8mtlabar325TextGradientConfiguration6createEv@plt>:
   71da0:      	adrp	x16, 0x7b000
   71da4:      	ldr	x17, [x16, #0x6a0]
   71da8:      	add	x16, x16, #0x6a0
   71dac:      	br	x17

0000000000071db0 <_ZN8mtlabar325TextGradientConfiguration7destroyEPS0_@plt>:
   71db0:      	adrp	x16, 0x7b000
   71db4:      	ldr	x17, [x16, #0x6a8]
   71db8:      	add	x16, x16, #0x6a8
   71dbc:      	br	x17

0000000000071dc0 <_ZN8mtlabar325TextGradientConfiguration8deepCopyEPKS0_@plt>:
   71dc0:      	adrp	x16, 0x7b000
   71dc4:      	ldr	x17, [x16, #0x6b0]
   71dc8:      	add	x16, x16, #0x6b0
   71dcc:      	br	x17

0000000000071dd0 <_ZNK8mtlabar325TextGradientConfiguration9getPointsEv@plt>:
   71dd0:      	adrp	x16, 0x7b000
   71dd4:      	ldr	x17, [x16, #0x6b8]
   71dd8:      	add	x16, x16, #0x6b8
   71ddc:      	br	x17

0000000000071de0 <_ZN8mtlabar325TextGradientConfiguration9setPointsERKNSt6__ndk16vectorINS_6Float2ENS1_9allocatorIS3_EEEE@plt>:
   71de0:      	adrp	x16, 0x7b000
   71de4:      	ldr	x17, [x16, #0x6c0]
   71de8:      	add	x16, x16, #0x6c0
   71dec:      	br	x17

0000000000071df0 <_ZNK8mtlabar325TextGradientConfiguration9getColorsEv@plt>:
   71df0:      	adrp	x16, 0x7b000
   71df4:      	ldr	x17, [x16, #0x6c8]
   71df8:      	add	x16, x16, #0x6c8
   71dfc:      	br	x17

0000000000071e00 <_ZN8mtlabar325TextGradientConfiguration9setColorsERKNSt6__ndk16vectorINS_6ColorAENS1_9allocatorIS3_EEEE@plt>:
   71e00:      	adrp	x16, 0x7b000
   71e04:      	ldr	x17, [x16, #0x6d0]
   71e08:      	add	x16, x16, #0x6d0
   71e0c:      	br	x17

0000000000071e10 <_ZNK8mtlabar325TextGradientConfiguration8getAngleEv@plt>:
   71e10:      	adrp	x16, 0x7b000
   71e14:      	ldr	x17, [x16, #0x6d8]
   71e18:      	add	x16, x16, #0x6d8
   71e1c:      	br	x17

0000000000071e20 <_ZN8mtlabar325TextGradientConfiguration8setAngleEf@plt>:
   71e20:      	adrp	x16, 0x7b000
   71e24:      	ldr	x17, [x16, #0x6e0]
   71e28:      	add	x16, x16, #0x6e0
   71e2c:      	br	x17

0000000000071e30 <_ZNK8mtlabar325TextGradientConfiguration8getCountEv@plt>:
   71e30:      	adrp	x16, 0x7b000
   71e34:      	ldr	x17, [x16, #0x6e8]
   71e38:      	add	x16, x16, #0x6e8
   71e3c:      	br	x17

0000000000071e40 <_ZN8mtlabar325TextGradientConfiguration8setCountEi@plt>:
   71e40:      	adrp	x16, 0x7b000
   71e44:      	ldr	x17, [x16, #0x6f0]
   71e48:      	add	x16, x16, #0x6f0
   71e4c:      	br	x17

0000000000071e50 <_ZN8mtlabar323TextShadowConfiguration6createEv@plt>:
   71e50:      	adrp	x16, 0x7b000
   71e54:      	ldr	x17, [x16, #0x6f8]
   71e58:      	add	x16, x16, #0x6f8
   71e5c:      	br	x17

0000000000071e60 <_ZN8mtlabar323TextShadowConfiguration7destroyEPS0_@plt>:
   71e60:      	adrp	x16, 0x7b000
   71e64:      	ldr	x17, [x16, #0x700]
   71e68:      	add	x16, x16, #0x700
   71e6c:      	br	x17

0000000000071e70 <_ZN8mtlabar323TextShadowConfiguration8deepCopyEPKS0_@plt>:
   71e70:      	adrp	x16, 0x7b000
   71e74:      	ldr	x17, [x16, #0x708]
   71e78:      	add	x16, x16, #0x708
   71e7c:      	br	x17

0000000000071e80 <_ZNK8mtlabar323TextShadowConfiguration9getEnableEv@plt>:
   71e80:      	adrp	x16, 0x7b000
   71e84:      	ldr	x17, [x16, #0x710]
   71e88:      	add	x16, x16, #0x710
   71e8c:      	br	x17

0000000000071e90 <_ZN8mtlabar323TextShadowConfiguration9setEnableEb@plt>:
   71e90:      	adrp	x16, 0x7b000
   71e94:      	ldr	x17, [x16, #0x718]
   71e98:      	add	x16, x16, #0x718
   71e9c:      	br	x17

0000000000071ea0 <_ZNK8mtlabar323TextShadowConfiguration11getEditableEv@plt>:
   71ea0:      	adrp	x16, 0x7b000
   71ea4:      	ldr	x17, [x16, #0x720]
   71ea8:      	add	x16, x16, #0x720
   71eac:      	br	x17

0000000000071eb0 <_ZN8mtlabar323TextShadowConfiguration11setEditableEb@plt>:
   71eb0:      	adrp	x16, 0x7b000
   71eb4:      	ldr	x17, [x16, #0x728]
   71eb8:      	add	x16, x16, #0x728
   71ebc:      	br	x17

0000000000071ec0 <_ZNK8mtlabar323TextShadowConfiguration9getColorAEv@plt>:
   71ec0:      	adrp	x16, 0x7b000
   71ec4:      	ldr	x17, [x16, #0x730]
   71ec8:      	add	x16, x16, #0x730
   71ecc:      	br	x17

0000000000071ed0 <_ZN8mtlabar323TextShadowConfiguration9setColorAERKNS_6ColorAE@plt>:
   71ed0:      	adrp	x16, 0x7b000
   71ed4:      	ldr	x17, [x16, #0x738]
   71ed8:      	add	x16, x16, #0x738
   71edc:      	br	x17

0000000000071ee0 <_ZNK8mtlabar323TextShadowConfiguration12getColorWorkEv@plt>:
   71ee0:      	adrp	x16, 0x7b000
   71ee4:      	ldr	x17, [x16, #0x740]
   71ee8:      	add	x16, x16, #0x740
   71eec:      	br	x17

0000000000071ef0 <_ZN8mtlabar323TextShadowConfiguration12setColorWorkEb@plt>:
   71ef0:      	adrp	x16, 0x7b000
   71ef4:      	ldr	x17, [x16, #0x748]
   71ef8:      	add	x16, x16, #0x748
   71efc:      	br	x17

0000000000071f00 <_ZNK8mtlabar323TextShadowConfiguration9getOffsetEv@plt>:
   71f00:      	adrp	x16, 0x7b000
   71f04:      	ldr	x17, [x16, #0x750]
   71f08:      	add	x16, x16, #0x750
   71f0c:      	br	x17

0000000000071f10 <_ZN8mtlabar323TextShadowConfiguration9setOffsetERKNS_6Float2E@plt>:
   71f10:      	adrp	x16, 0x7b000
   71f14:      	ldr	x17, [x16, #0x758]
   71f18:      	add	x16, x16, #0x758
   71f1c:      	br	x17

0000000000071f20 <_ZNK8mtlabar323TextShadowConfiguration7getBlurEv@plt>:
   71f20:      	adrp	x16, 0x7b000
   71f24:      	ldr	x17, [x16, #0x760]
   71f28:      	add	x16, x16, #0x760
   71f2c:      	br	x17

0000000000071f30 <_ZN8mtlabar323TextShadowConfiguration7setBlurEf@plt>:
   71f30:      	adrp	x16, 0x7b000
   71f34:      	ldr	x17, [x16, #0x768]
   71f38:      	add	x16, x16, #0x768
   71f3c:      	br	x17

0000000000071f40 <_ZN8mtlabar323TextStrokeConfiguration6createEv@plt>:
   71f40:      	adrp	x16, 0x7b000
   71f44:      	ldr	x17, [x16, #0x770]
   71f48:      	add	x16, x16, #0x770
   71f4c:      	br	x17

0000000000071f50 <_ZN8mtlabar323TextStrokeConfiguration7destroyEPS0_@plt>:
   71f50:      	adrp	x16, 0x7b000
   71f54:      	ldr	x17, [x16, #0x778]
   71f58:      	add	x16, x16, #0x778
   71f5c:      	br	x17

0000000000071f60 <_ZN8mtlabar323TextStrokeConfiguration8deepCopyEPKS0_@plt>:
   71f60:      	adrp	x16, 0x7b000
   71f64:      	ldr	x17, [x16, #0x780]
   71f68:      	add	x16, x16, #0x780
   71f6c:      	br	x17

0000000000071f70 <_ZNK8mtlabar323TextStrokeConfiguration9getEnableEv@plt>:
   71f70:      	adrp	x16, 0x7b000
   71f74:      	ldr	x17, [x16, #0x788]
   71f78:      	add	x16, x16, #0x788
   71f7c:      	br	x17

0000000000071f80 <_ZN8mtlabar323TextStrokeConfiguration9setEnableEb@plt>:
   71f80:      	adrp	x16, 0x7b000
   71f84:      	ldr	x17, [x16, #0x790]
   71f88:      	add	x16, x16, #0x790
   71f8c:      	br	x17

0000000000071f90 <_ZNK8mtlabar323TextStrokeConfiguration11getEditableEv@plt>:
   71f90:      	adrp	x16, 0x7b000
   71f94:      	ldr	x17, [x16, #0x798]
   71f98:      	add	x16, x16, #0x798
   71f9c:      	br	x17

0000000000071fa0 <_ZN8mtlabar323TextStrokeConfiguration11setEditableEb@plt>:
   71fa0:      	adrp	x16, 0x7b000
   71fa4:      	ldr	x17, [x16, #0x7a0]
   71fa8:      	add	x16, x16, #0x7a0
   71fac:      	br	x17

0000000000071fb0 <_ZNK8mtlabar323TextStrokeConfiguration9getColorAEv@plt>:
   71fb0:      	adrp	x16, 0x7b000
   71fb4:      	ldr	x17, [x16, #0x7a8]
   71fb8:      	add	x16, x16, #0x7a8
   71fbc:      	br	x17

0000000000071fc0 <_ZN8mtlabar323TextStrokeConfiguration9setColorAERKNS_6ColorAE@plt>:
   71fc0:      	adrp	x16, 0x7b000
   71fc4:      	ldr	x17, [x16, #0x7b0]
   71fc8:      	add	x16, x16, #0x7b0
   71fcc:      	br	x17

0000000000071fd0 <_ZNK8mtlabar323TextStrokeConfiguration12getColorWorkEv@plt>:
   71fd0:      	adrp	x16, 0x7b000
   71fd4:      	ldr	x17, [x16, #0x7b8]
   71fd8:      	add	x16, x16, #0x7b8
   71fdc:      	br	x17

0000000000071fe0 <_ZN8mtlabar323TextStrokeConfiguration12setColorWorkEb@plt>:
   71fe0:      	adrp	x16, 0x7b000
   71fe4:      	ldr	x17, [x16, #0x7c0]
   71fe8:      	add	x16, x16, #0x7c0
   71fec:      	br	x17

0000000000071ff0 <_ZNK8mtlabar323TextStrokeConfiguration7getSizeEv@plt>:
   71ff0:      	adrp	x16, 0x7b000
   71ff4:      	ldr	x17, [x16, #0x7c8]
   71ff8:      	add	x16, x16, #0x7c8
   71ffc:      	br	x17

0000000000072000 <_ZN8mtlabar323TextStrokeConfiguration7setSizeEf@plt>:
   72000:      	adrp	x16, 0x7b000
   72004:      	ldr	x17, [x16, #0x7d0]
   72008:      	add	x16, x16, #0x7d0
   7200c:      	br	x17

0000000000072010 <_ZN8mtlabar323TextBubbleConfiguration6createEv@plt>:
   72010:      	adrp	x16, 0x7b000
   72014:      	ldr	x17, [x16, #0x7d8]
   72018:      	add	x16, x16, #0x7d8
   7201c:      	br	x17

0000000000072020 <_ZN8mtlabar323TextBubbleConfiguration7destroyEPS0_@plt>:
   72020:      	adrp	x16, 0x7b000
   72024:      	ldr	x17, [x16, #0x7e0]
   72028:      	add	x16, x16, #0x7e0
   7202c:      	br	x17

0000000000072030 <_ZN8mtlabar323TextBubbleConfiguration8deepCopyEPKS0_@plt>:
   72030:      	adrp	x16, 0x7b000
   72034:      	ldr	x17, [x16, #0x7e8]
   72038:      	add	x16, x16, #0x7e8
   7203c:      	br	x17

0000000000072040 <_ZNK8mtlabar323TextBubbleConfiguration9getEnableEv@plt>:
   72040:      	adrp	x16, 0x7b000
   72044:      	ldr	x17, [x16, #0x7f0]
   72048:      	add	x16, x16, #0x7f0
   7204c:      	br	x17

0000000000072050 <_ZN8mtlabar323TextBubbleConfiguration9setEnableEb@plt>:
   72050:      	adrp	x16, 0x7b000
   72054:      	ldr	x17, [x16, #0x7f8]
   72058:      	add	x16, x16, #0x7f8
   7205c:      	br	x17

0000000000072060 <_ZNK8mtlabar323TextBubbleConfiguration11getEditableEv@plt>:
   72060:      	adrp	x16, 0x7b000
   72064:      	ldr	x17, [x16, #0x800]
   72068:      	add	x16, x16, #0x800
   7206c:      	br	x17

0000000000072070 <_ZN8mtlabar323TextBubbleConfiguration11setEditableEb@plt>:
   72070:      	adrp	x16, 0x7b000
   72074:      	ldr	x17, [x16, #0x808]
   72078:      	add	x16, x16, #0x808
   7207c:      	br	x17

0000000000072080 <_ZNK8mtlabar323TextBubbleConfiguration10getPaddingEv@plt>:
   72080:      	adrp	x16, 0x7b000
   72084:      	ldr	x17, [x16, #0x810]
   72088:      	add	x16, x16, #0x810
   7208c:      	br	x17

0000000000072090 <_ZN8mtlabar323TextBubbleConfiguration10setPaddingERKNS_5RectFE@plt>:
   72090:      	adrp	x16, 0x7b000
   72094:      	ldr	x17, [x16, #0x818]
   72098:      	add	x16, x16, #0x818
   7209c:      	br	x17

00000000000720a0 <_ZNK8mtlabar323TextBubbleConfiguration12getScaleSizeEv@plt>:
   720a0:      	adrp	x16, 0x7b000
   720a4:      	ldr	x17, [x16, #0x820]
   720a8:      	add	x16, x16, #0x820
   720ac:      	br	x17

00000000000720b0 <_ZN8mtlabar323TextBubbleConfiguration12setScaleSizeERKNS_5RectFE@plt>:
   720b0:      	adrp	x16, 0x7b000
   720b4:      	ldr	x17, [x16, #0x828]
   720b8:      	add	x16, x16, #0x828
   720bc:      	br	x17

00000000000720c0 <_ZN8mtlabar325TextEditableConfiguration6createEv@plt>:
   720c0:      	adrp	x16, 0x7b000
   720c4:      	ldr	x17, [x16, #0x830]
   720c8:      	add	x16, x16, #0x830
   720cc:      	br	x17

00000000000720d0 <_ZN8mtlabar325TextEditableConfiguration7destroyEPS0_@plt>:
   720d0:      	adrp	x16, 0x7b000
   720d4:      	ldr	x17, [x16, #0x838]
   720d8:      	add	x16, x16, #0x838
   720dc:      	br	x17

00000000000720e0 <_ZN8mtlabar325TextEditableConfiguration8deepCopyEPKS0_@plt>:
   720e0:      	adrp	x16, 0x7b000
   720e4:      	ldr	x17, [x16, #0x840]
   720e8:      	add	x16, x16, #0x840
   720ec:      	br	x17

00000000000720f0 <_ZNK8mtlabar325TextEditableConfiguration11getEditableEv@plt>:
   720f0:      	adrp	x16, 0x7b000
   720f4:      	ldr	x17, [x16, #0x848]
   720f8:      	add	x16, x16, #0x848
   720fc:      	br	x17

0000000000072100 <_ZN8mtlabar325TextEditableConfiguration11setEditableEb@plt>:
   72100:      	adrp	x16, 0x7b000
   72104:      	ldr	x17, [x16, #0x850]
   72108:      	add	x16, x16, #0x850
   7210c:      	br	x17

0000000000072110 <_ZNK8mtlabar325TextEditableConfiguration18getSpacingEditableEv@plt>:
   72110:      	adrp	x16, 0x7b000
   72114:      	ldr	x17, [x16, #0x858]
   72118:      	add	x16, x16, #0x858
   7211c:      	br	x17

0000000000072120 <_ZN8mtlabar325TextEditableConfiguration18setSpacingEditableEb@plt>:
   72120:      	adrp	x16, 0x7b000
   72124:      	ldr	x17, [x16, #0x860]
   72128:      	add	x16, x16, #0x860
   7212c:      	br	x17

0000000000072130 <_ZNK8mtlabar325TextEditableConfiguration22getLineSpacingEditableEv@plt>:
   72130:      	adrp	x16, 0x7b000
   72134:      	ldr	x17, [x16, #0x868]
   72138:      	add	x16, x16, #0x868
   7213c:      	br	x17

0000000000072140 <_ZN8mtlabar325TextEditableConfiguration22setLineSpacingEditableEb@plt>:
   72140:      	adrp	x16, 0x7b000
   72144:      	ldr	x17, [x16, #0x870]
   72148:      	add	x16, x16, #0x870
   7214c:      	br	x17

0000000000072150 <_ZNK8mtlabar325TextEditableConfiguration21getHorizontalEditableEv@plt>:
   72150:      	adrp	x16, 0x7b000
   72154:      	ldr	x17, [x16, #0x878]
   72158:      	add	x16, x16, #0x878
   7215c:      	br	x17

0000000000072160 <_ZN8mtlabar325TextEditableConfiguration21setHorizontalEditableEb@plt>:
   72160:      	adrp	x16, 0x7b000
   72164:      	ldr	x17, [x16, #0x880]
   72168:      	add	x16, x16, #0x880
   7216c:      	br	x17

0000000000072170 <_ZNK8mtlabar325TextEditableConfiguration19getVerticalEditableEv@plt>:
   72170:      	adrp	x16, 0x7b000
   72174:      	ldr	x17, [x16, #0x888]
   72178:      	add	x16, x16, #0x888
   7217c:      	br	x17

0000000000072180 <_ZN8mtlabar325TextEditableConfiguration19setVerticalEditableEb@plt>:
   72180:      	adrp	x16, 0x7b000
   72184:      	ldr	x17, [x16, #0x890]
   72188:      	add	x16, x16, #0x890
   7218c:      	br	x17

0000000000072190 <_ZNK8mtlabar325TextEditableConfiguration17getPinyinEditableEv@plt>:
   72190:      	adrp	x16, 0x7b000
   72194:      	ldr	x17, [x16, #0x898]
   72198:      	add	x16, x16, #0x898
   7219c:      	br	x17

00000000000721a0 <_ZN8mtlabar325TextEditableConfiguration17setPinyinEditableEb@plt>:
   721a0:      	adrp	x16, 0x7b000
   721a4:      	ldr	x17, [x16, #0x8a0]
   721a8:      	add	x16, x16, #0x8a0
   721ac:      	br	x17

00000000000721b0 <_ZN8mtlabar321TextPathConfiguration6createEv@plt>:
   721b0:      	adrp	x16, 0x7b000
   721b4:      	ldr	x17, [x16, #0x8a8]
   721b8:      	add	x16, x16, #0x8a8
   721bc:      	br	x17

00000000000721c0 <_ZN8mtlabar321TextPathConfiguration7destroyEPS0_@plt>:
   721c0:      	adrp	x16, 0x7b000
   721c4:      	ldr	x17, [x16, #0x8b0]
   721c8:      	add	x16, x16, #0x8b0
   721cc:      	br	x17

00000000000721d0 <_ZN8mtlabar321TextPathConfiguration8deepCopyEPKS0_@plt>:
   721d0:      	adrp	x16, 0x7b000
   721d4:      	ldr	x17, [x16, #0x8b8]
   721d8:      	add	x16, x16, #0x8b8
   721dc:      	br	x17

00000000000721e0 <_ZNK8mtlabar321TextPathConfiguration9getEnableEv@plt>:
   721e0:      	adrp	x16, 0x7b000
   721e4:      	ldr	x17, [x16, #0x8c0]
   721e8:      	add	x16, x16, #0x8c0
   721ec:      	br	x17

00000000000721f0 <_ZN8mtlabar321TextPathConfiguration9setEnableEb@plt>:
   721f0:      	adrp	x16, 0x7b000
   721f4:      	ldr	x17, [x16, #0x8c8]
   721f8:      	add	x16, x16, #0x8c8
   721fc:      	br	x17

0000000000072200 <_ZNK8mtlabar321TextPathConfiguration11getJsonPathEv@plt>:
   72200:      	adrp	x16, 0x7b000
   72204:      	ldr	x17, [x16, #0x8d0]
   72208:      	add	x16, x16, #0x8d0
   7220c:      	br	x17

0000000000072210 <_ZN8mtlabar321TextPathConfiguration11setJsonPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72210:      	adrp	x16, 0x7b000
   72214:      	ldr	x17, [x16, #0x8d8]
   72218:      	add	x16, x16, #0x8d8
   7221c:      	br	x17

0000000000072220 <_ZNK8mtlabar321TextPathConfiguration16getPerpendicularEv@plt>:
   72220:      	adrp	x16, 0x7b000
   72224:      	ldr	x17, [x16, #0x8e0]
   72228:      	add	x16, x16, #0x8e0
   7222c:      	br	x17

0000000000072230 <_ZN8mtlabar321TextPathConfiguration16setPerpendicularEb@plt>:
   72230:      	adrp	x16, 0x7b000
   72234:      	ldr	x17, [x16, #0x8e8]
   72238:      	add	x16, x16, #0x8e8
   7223c:      	br	x17

0000000000072240 <_ZNK8mtlabar321TextPathConfiguration10getReverseEv@plt>:
   72240:      	adrp	x16, 0x7b000
   72244:      	ldr	x17, [x16, #0x8f0]
   72248:      	add	x16, x16, #0x8f0
   7224c:      	br	x17

0000000000072250 <_ZN8mtlabar321TextPathConfiguration10setReverseEb@plt>:
   72250:      	adrp	x16, 0x7b000
   72254:      	ldr	x17, [x16, #0x8f8]
   72258:      	add	x16, x16, #0x8f8
   7225c:      	br	x17

0000000000072260 <_ZNK8mtlabar321TextPathConfiguration9getScaleYEv@plt>:
   72260:      	adrp	x16, 0x7b000
   72264:      	ldr	x17, [x16, #0x900]
   72268:      	add	x16, x16, #0x900
   7226c:      	br	x17

0000000000072270 <_ZN8mtlabar321TextPathConfiguration9setScaleYEf@plt>:
   72270:      	adrp	x16, 0x7b000
   72274:      	ldr	x17, [x16, #0x908]
   72278:      	add	x16, x16, #0x908
   7227c:      	br	x17

0000000000072280 <_ZNK8mtlabar321TextPathConfiguration21getPathLengthUseRatioEv@plt>:
   72280:      	adrp	x16, 0x7b000
   72284:      	ldr	x17, [x16, #0x910]
   72288:      	add	x16, x16, #0x910
   7228c:      	br	x17

0000000000072290 <_ZN8mtlabar321TextPathConfiguration21setPathLengthUseRatioEf@plt>:
   72290:      	adrp	x16, 0x7b000
   72294:      	ldr	x17, [x16, #0x918]
   72298:      	add	x16, x16, #0x918
   7229c:      	br	x17

00000000000722a0 <_ZNK8mtlabar321TextPathConfiguration17getPositionOffsetEv@plt>:
   722a0:      	adrp	x16, 0x7b000
   722a4:      	ldr	x17, [x16, #0x920]
   722a8:      	add	x16, x16, #0x920
   722ac:      	br	x17

00000000000722b0 <_ZN8mtlabar321TextPathConfiguration17setPositionOffsetEf@plt>:
   722b0:      	adrp	x16, 0x7b000
   722b4:      	ldr	x17, [x16, #0x928]
   722b8:      	add	x16, x16, #0x928
   722bc:      	br	x17

00000000000722c0 <_ZNK8mtlabar321TextPathConfiguration12getTextBoundEv@plt>:
   722c0:      	adrp	x16, 0x7b000
   722c4:      	ldr	x17, [x16, #0x930]
   722c8:      	add	x16, x16, #0x930
   722cc:      	br	x17

00000000000722d0 <_ZN8mtlabar321TextPathConfiguration12setTextBoundEf@plt>:
   722d0:      	adrp	x16, 0x7b000
   722d4:      	ldr	x17, [x16, #0x938]
   722d8:      	add	x16, x16, #0x938
   722dc:      	br	x17

00000000000722e0 <_ZNK8mtlabar321TextPathConfiguration13getEnableBendEv@plt>:
   722e0:      	adrp	x16, 0x7b000
   722e4:      	ldr	x17, [x16, #0x940]
   722e8:      	add	x16, x16, #0x940
   722ec:      	br	x17

00000000000722f0 <_ZN8mtlabar321TextPathConfiguration13setEnableBendEb@plt>:
   722f0:      	adrp	x16, 0x7b000
   722f4:      	ldr	x17, [x16, #0x948]
   722f8:      	add	x16, x16, #0x948
   722fc:      	br	x17

0000000000072300 <_ZNK8mtlabar321TextPathConfiguration12getBendAngleEv@plt>:
   72300:      	adrp	x16, 0x7b000
   72304:      	ldr	x17, [x16, #0x950]
   72308:      	add	x16, x16, #0x950
   7230c:      	br	x17

0000000000072310 <_ZN8mtlabar321TextPathConfiguration12setBendAngleEf@plt>:
   72310:      	adrp	x16, 0x7b000
   72314:      	ldr	x17, [x16, #0x958]
   72318:      	add	x16, x16, #0x958
   7231c:      	br	x17

0000000000072320 <_ZNK8mtlabar321TextPathConfiguration11getProgressEv@plt>:
   72320:      	adrp	x16, 0x7b000
   72324:      	ldr	x17, [x16, #0x960]
   72328:      	add	x16, x16, #0x960
   7232c:      	br	x17

0000000000072330 <_ZN8mtlabar321TextPathConfiguration11setProgressEf@plt>:
   72330:      	adrp	x16, 0x7b000
   72334:      	ldr	x17, [x16, #0x968]
   72338:      	add	x16, x16, #0x968
   7233c:      	br	x17

0000000000072340 <_ZNK8mtlabar321TextPathConfiguration19getFirstMarginRatioEv@plt>:
   72340:      	adrp	x16, 0x7b000
   72344:      	ldr	x17, [x16, #0x970]
   72348:      	add	x16, x16, #0x970
   7234c:      	br	x17

0000000000072350 <_ZN8mtlabar321TextPathConfiguration19setFirstMarginRatioEf@plt>:
   72350:      	adrp	x16, 0x7b000
   72354:      	ldr	x17, [x16, #0x978]
   72358:      	add	x16, x16, #0x978
   7235c:      	br	x17

0000000000072360 <_ZNK8mtlabar321TextPathConfiguration18getLastMarginRatioEv@plt>:
   72360:      	adrp	x16, 0x7b000
   72364:      	ldr	x17, [x16, #0x980]
   72368:      	add	x16, x16, #0x980
   7236c:      	br	x17

0000000000072370 <_ZN8mtlabar321TextPathConfiguration18setLastMarginRatioEf@plt>:
   72370:      	adrp	x16, 0x7b000
   72374:      	ldr	x17, [x16, #0x988]
   72378:      	add	x16, x16, #0x988
   7237c:      	br	x17

0000000000072380 <_ZNK8mtlabar321TextPathConfiguration10getSpacingEv@plt>:
   72380:      	adrp	x16, 0x7b000
   72384:      	ldr	x17, [x16, #0x990]
   72388:      	add	x16, x16, #0x990
   7238c:      	br	x17

0000000000072390 <_ZN8mtlabar321TextPathConfiguration10setSpacingEf@plt>:
   72390:      	adrp	x16, 0x7b000
   72394:      	ldr	x17, [x16, #0x998]
   72398:      	add	x16, x16, #0x998
   7239c:      	br	x17

00000000000723a0 <_ZNK8mtlabar321TextPathConfiguration20getEnableAspectRatioEv@plt>:
   723a0:      	adrp	x16, 0x7b000
   723a4:      	ldr	x17, [x16, #0x9a0]
   723a8:      	add	x16, x16, #0x9a0
   723ac:      	br	x17

00000000000723b0 <_ZN8mtlabar321TextPathConfiguration20setEnableAspectRatioEb@plt>:
   723b0:      	adrp	x16, 0x7b000
   723b4:      	ldr	x17, [x16, #0x9a8]
   723b8:      	add	x16, x16, #0x9a8
   723bc:      	br	x17

00000000000723c0 <_ZNK8mtlabar321TextPathConfiguration14getAspectRatioEv@plt>:
   723c0:      	adrp	x16, 0x7b000
   723c4:      	ldr	x17, [x16, #0x9b0]
   723c8:      	add	x16, x16, #0x9b0
   723cc:      	br	x17

00000000000723d0 <_ZN8mtlabar321TextPathConfiguration14setAspectRatioEf@plt>:
   723d0:      	adrp	x16, 0x7b000
   723d4:      	ldr	x17, [x16, #0x9b8]
   723d8:      	add	x16, x16, #0x9b8
   723dc:      	br	x17

00000000000723e0 <_ZNK8mtlabar321TextPathConfiguration16getCurveTextTypeEv@plt>:
   723e0:      	adrp	x16, 0x7b000
   723e4:      	ldr	x17, [x16, #0x9c0]
   723e8:      	add	x16, x16, #0x9c0
   723ec:      	br	x17

00000000000723f0 <_ZN8mtlabar321TextPathConfiguration16setCurveTextTypeENS_4text13CurveTextTypeE@plt>:
   723f0:      	adrp	x16, 0x7b000
   723f4:      	ldr	x17, [x16, #0x9c8]
   723f8:      	add	x16, x16, #0x9c8
   723fc:      	br	x17

0000000000072400 <_ZN8mtlabar327SelectionHighlightInterface6createEv@plt>:
   72400:      	adrp	x16, 0x7b000
   72404:      	ldr	x17, [x16, #0x9d0]
   72408:      	add	x16, x16, #0x9d0
   7240c:      	br	x17

0000000000072410 <_ZN8mtlabar327SelectionHighlightInterface7destroyEPS0_@plt>:
   72410:      	adrp	x16, 0x7b000
   72414:      	ldr	x17, [x16, #0x9d8]
   72418:      	add	x16, x16, #0x9d8
   7241c:      	br	x17

0000000000072420 <_ZN8mtlabar327SelectionHighlightInterface8deepCopyEPKS0_@plt>:
   72420:      	adrp	x16, 0x7b000
   72424:      	ldr	x17, [x16, #0x9e0]
   72428:      	add	x16, x16, #0x9e0
   7242c:      	br	x17

0000000000072430 <_ZN8mtlabar327SelectionHighlightInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72430:      	adrp	x16, 0x7b000
   72434:      	ldr	x17, [x16, #0x9e8]
   72438:      	add	x16, x16, #0x9e8
   7243c:      	br	x17

0000000000072440 <_ZNK8mtlabar327SelectionHighlightInterface13getConfigPathEv@plt>:
   72440:      	adrp	x16, 0x7b000
   72444:      	ldr	x17, [x16, #0x9f0]
   72448:      	add	x16, x16, #0x9f0
   7244c:      	br	x17

0000000000072450 <_ZN8mtlabar327SelectionHighlightInterface8setIndexEi@plt>:
   72450:      	adrp	x16, 0x7b000
   72454:      	ldr	x17, [x16, #0x9f8]
   72458:      	add	x16, x16, #0x9f8
   7245c:      	br	x17

0000000000072460 <_ZNK8mtlabar327SelectionHighlightInterface8getIndexEv@plt>:
   72460:      	adrp	x16, 0x7b000
   72464:      	ldr	x17, [x16, #0xa00]
   72468:      	add	x16, x16, #0xa00
   7246c:      	br	x17

0000000000072470 <_ZN8mtlabar327SelectionHighlightInterface9setLengthEi@plt>:
   72470:      	adrp	x16, 0x7b000
   72474:      	ldr	x17, [x16, #0xa08]
   72478:      	add	x16, x16, #0xa08
   7247c:      	br	x17

0000000000072480 <_ZNK8mtlabar327SelectionHighlightInterface9getLengthEv@plt>:
   72480:      	adrp	x16, 0x7b000
   72484:      	ldr	x17, [x16, #0xa10]
   72488:      	add	x16, x16, #0xa10
   7248c:      	br	x17

0000000000072490 <_ZN8mtlabar327SelectionHighlightInterface11setFontSizeEf@plt>:
   72490:      	adrp	x16, 0x7b000
   72494:      	ldr	x17, [x16, #0xa18]
   72498:      	add	x16, x16, #0xa18
   7249c:      	br	x17

00000000000724a0 <_ZNK8mtlabar327SelectionHighlightInterface11getFontSizeEv@plt>:
   724a0:      	adrp	x16, 0x7b000
   724a4:      	ldr	x17, [x16, #0xa20]
   724a8:      	add	x16, x16, #0xa20
   724ac:      	br	x17

00000000000724b0 <_ZN8mtlabar327SelectionHighlightInterface19setDisplayInASRTimeEb@plt>:
   724b0:      	adrp	x16, 0x7b000
   724b4:      	ldr	x17, [x16, #0xa28]
   724b8:      	add	x16, x16, #0xa28
   724bc:      	br	x17

00000000000724c0 <_ZNK8mtlabar327SelectionHighlightInterface19getDisplayInASRTimeEv@plt>:
   724c0:      	adrp	x16, 0x7b000
   724c4:      	ldr	x17, [x16, #0xa30]
   724c8:      	add	x16, x16, #0xa30
   724cc:      	br	x17

00000000000724d0 <_ZN8mtlabar327SelectionHighlightInterface19setDisplayBeginTimeEf@plt>:
   724d0:      	adrp	x16, 0x7b000
   724d4:      	ldr	x17, [x16, #0xa38]
   724d8:      	add	x16, x16, #0xa38
   724dc:      	br	x17

00000000000724e0 <_ZNK8mtlabar327SelectionHighlightInterface19getDisplayBeginTimeEv@plt>:
   724e0:      	adrp	x16, 0x7b000
   724e4:      	ldr	x17, [x16, #0xa40]
   724e8:      	add	x16, x16, #0xa40
   724ec:      	br	x17

00000000000724f0 <_ZN8mtlabar327SelectionHighlightInterface17setDisplayEndTimeEf@plt>:
   724f0:      	adrp	x16, 0x7b000
   724f4:      	ldr	x17, [x16, #0xa48]
   724f8:      	add	x16, x16, #0xa48
   724fc:      	br	x17

0000000000072500 <_ZNK8mtlabar327SelectionHighlightInterface17getDisplayEndTimeEv@plt>:
   72500:      	adrp	x16, 0x7b000
   72504:      	ldr	x17, [x16, #0xa50]
   72508:      	add	x16, x16, #0xa50
   7250c:      	br	x17

0000000000072510 <_ZN8mtlabar327SelectionHighlightInterface28setHideNonHighlightUnderlineEb@plt>:
   72510:      	adrp	x16, 0x7b000
   72514:      	ldr	x17, [x16, #0xa58]
   72518:      	add	x16, x16, #0xa58
   7251c:      	br	x17

0000000000072520 <_ZNK8mtlabar327SelectionHighlightInterface28getHideNonHighlightUnderlineEv@plt>:
   72520:      	adrp	x16, 0x7b000
   72524:      	ldr	x17, [x16, #0xa60]
   72528:      	add	x16, x16, #0xa60
   7252c:      	br	x17

0000000000072530 <_ZN8mtlabar327SelectionHighlightInterface14setFontLibraryERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72530:      	adrp	x16, 0x7b000
   72534:      	ldr	x17, [x16, #0xa68]
   72538:      	add	x16, x16, #0xa68
   7253c:      	br	x17

0000000000072540 <_ZNK8mtlabar327SelectionHighlightInterface14getFontLibraryEv@plt>:
   72540:      	adrp	x16, 0x7b000
   72544:      	ldr	x17, [x16, #0xa70]
   72548:      	add	x16, x16, #0xa70
   7254c:      	br	x17

0000000000072550 <_ZN8mtlabar327SelectionHighlightInterface17setCustomizeStyleEb@plt>:
   72550:      	adrp	x16, 0x7b000
   72554:      	ldr	x17, [x16, #0xa78]
   72558:      	add	x16, x16, #0xa78
   7255c:      	br	x17

0000000000072560 <_ZNK8mtlabar327SelectionHighlightInterface17getCustomizeStyleEv@plt>:
   72560:      	adrp	x16, 0x7b000
   72564:      	ldr	x17, [x16, #0xa80]
   72568:      	add	x16, x16, #0xa80
   7256c:      	br	x17

0000000000072570 <_ZNK8mtlabar327SelectionHighlightInterface8getColorEv@plt>:
   72570:      	adrp	x16, 0x7b000
   72574:      	ldr	x17, [x16, #0xa88]
   72578:      	add	x16, x16, #0xa88
   7257c:      	br	x17

0000000000072580 <_ZN8mtlabar327SelectionHighlightInterface8setColorERKNS_6ColorAE@plt>:
   72580:      	adrp	x16, 0x7b000
   72584:      	ldr	x17, [x16, #0xa90]
   72588:      	add	x16, x16, #0xa90
   7258c:      	br	x17

0000000000072590 <_ZN8mtlabar327SelectionHighlightInterface24setFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   72590:      	adrp	x16, 0x7b000
   72594:      	ldr	x17, [x16, #0xa98]
   72598:      	add	x16, x16, #0xa98
   7259c:      	br	x17

00000000000725a0 <_ZNK8mtlabar327SelectionHighlightInterface24getFallbackFontLibrariesEv@plt>:
   725a0:      	adrp	x16, 0x7b000
   725a4:      	ldr	x17, [x16, #0xaa0]
   725a8:      	add	x16, x16, #0xaa0
   725ac:      	br	x17

00000000000725b0 <_ZN8mtlabar327SelectionHighlightInterface7setBoldEb@plt>:
   725b0:      	adrp	x16, 0x7b000
   725b4:      	ldr	x17, [x16, #0xaa8]
   725b8:      	add	x16, x16, #0xaa8
   725bc:      	br	x17

00000000000725c0 <_ZNK8mtlabar327SelectionHighlightInterface7getBoldEv@plt>:
   725c0:      	adrp	x16, 0x7b000
   725c4:      	ldr	x17, [x16, #0xab0]
   725c8:      	add	x16, x16, #0xab0
   725cc:      	br	x17

00000000000725d0 <_ZN8mtlabar327SelectionHighlightInterface9setItalicEb@plt>:
   725d0:      	adrp	x16, 0x7b000
   725d4:      	ldr	x17, [x16, #0xab8]
   725d8:      	add	x16, x16, #0xab8
   725dc:      	br	x17

00000000000725e0 <_ZNK8mtlabar327SelectionHighlightInterface9getItalicEv@plt>:
   725e0:      	adrp	x16, 0x7b000
   725e4:      	ldr	x17, [x16, #0xac0]
   725e8:      	add	x16, x16, #0xac0
   725ec:      	br	x17

00000000000725f0 <_ZN8mtlabar327SelectionHighlightInterface12setUnderlineEb@plt>:
   725f0:      	adrp	x16, 0x7b000
   725f4:      	ldr	x17, [x16, #0xac8]
   725f8:      	add	x16, x16, #0xac8
   725fc:      	br	x17

0000000000072600 <_ZNK8mtlabar327SelectionHighlightInterface12getUnderlineEv@plt>:
   72600:      	adrp	x16, 0x7b000
   72604:      	ldr	x17, [x16, #0xad0]
   72608:      	add	x16, x16, #0xad0
   7260c:      	br	x17

0000000000072610 <_ZN8mtlabar327SelectionHighlightInterface16setStrikeThroughEb@plt>:
   72610:      	adrp	x16, 0x7b000
   72614:      	ldr	x17, [x16, #0xad8]
   72618:      	add	x16, x16, #0xad8
   7261c:      	br	x17

0000000000072620 <_ZNK8mtlabar327SelectionHighlightInterface16getStrikeThroughEv@plt>:
   72620:      	adrp	x16, 0x7b000
   72624:      	ldr	x17, [x16, #0xae0]
   72628:      	add	x16, x16, #0xae0
   7262c:      	br	x17

0000000000072630 <_ZN8mtlabar327SelectionHighlightInterface21getMultiStrokeAtIndexEi@plt>:
   72630:      	adrp	x16, 0x7b000
   72634:      	ldr	x17, [x16, #0xae8]
   72638:      	add	x16, x16, #0xae8
   7263c:      	br	x17

0000000000072640 <_ZN8mtlabar327SelectionHighlightInterface18getMultiStrokeSizeEv@plt>:
   72640:      	adrp	x16, 0x7b000
   72644:      	ldr	x17, [x16, #0xaf0]
   72648:      	add	x16, x16, #0xaf0
   7264c:      	br	x17

0000000000072650 <_ZN8mtlabar327SelectionHighlightInterface17resizeMultiStrokeEi@plt>:
   72650:      	adrp	x16, 0x7b000
   72654:      	ldr	x17, [x16, #0xaf8]
   72658:      	add	x16, x16, #0xaf8
   7265c:      	br	x17

0000000000072660 <_ZN8mtlabar327SelectionHighlightInterface22getShadowConfigurationEv@plt>:
   72660:      	adrp	x16, 0x7b000
   72664:      	ldr	x17, [x16, #0xb00]
   72668:      	add	x16, x16, #0xb00
   7266c:      	br	x17

0000000000072670 <_ZN8mtlabar327SelectionHighlightInterface31getBackgroundColorConfigurationEv@plt>:
   72670:      	adrp	x16, 0x7b000
   72674:      	ldr	x17, [x16, #0xb08]
   72678:      	add	x16, x16, #0xb08
   7267c:      	br	x17

0000000000072680 <_ZN8mtlabar327SelectionHighlightInterface20getGlowConfigurationEv@plt>:
   72680:      	adrp	x16, 0x7b000
   72684:      	ldr	x17, [x16, #0xb10]
   72688:      	add	x16, x16, #0xb10
   7268c:      	br	x17

0000000000072690 <_ZN8mtlabar327SelectionHighlightInterface9setRotateEf@plt>:
   72690:      	adrp	x16, 0x7b000
   72694:      	ldr	x17, [x16, #0xb18]
   72698:      	add	x16, x16, #0xb18
   7269c:      	br	x17

00000000000726a0 <_ZNK8mtlabar327SelectionHighlightInterface9getRotateEv@plt>:
   726a0:      	adrp	x16, 0x7b000
   726a4:      	ldr	x17, [x16, #0xb20]
   726a8:      	add	x16, x16, #0xb20
   726ac:      	br	x17

00000000000726b0 <_ZN8mtlabar327SelectionHighlightInterface8setScaleEf@plt>:
   726b0:      	adrp	x16, 0x7b000
   726b4:      	ldr	x17, [x16, #0xb28]
   726b8:      	add	x16, x16, #0xb28
   726bc:      	br	x17

00000000000726c0 <_ZNK8mtlabar327SelectionHighlightInterface8getScaleEv@plt>:
   726c0:      	adrp	x16, 0x7b000
   726c4:      	ldr	x17, [x16, #0xb30]
   726c8:      	add	x16, x16, #0xb30
   726cc:      	br	x17

00000000000726d0 <_ZN8mtlabar327SelectionHighlightInterface9setOffsetERKNS_6Float2E@plt>:
   726d0:      	adrp	x16, 0x7b000
   726d4:      	ldr	x17, [x16, #0xb38]
   726d8:      	add	x16, x16, #0xb38
   726dc:      	br	x17

00000000000726e0 <_ZNK8mtlabar327SelectionHighlightInterface9getOffsetEv@plt>:
   726e0:      	adrp	x16, 0x7b000
   726e4:      	ldr	x17, [x16, #0xb40]
   726e8:      	add	x16, x16, #0xb40
   726ec:      	br	x17

00000000000726f0 <_ZN8mtlabar327SelectionAnimationInterface6createEv@plt>:
   726f0:      	adrp	x16, 0x7b000
   726f4:      	ldr	x17, [x16, #0xb48]
   726f8:      	add	x16, x16, #0xb48
   726fc:      	br	x17

0000000000072700 <_ZN8mtlabar327SelectionAnimationInterface7destroyEPS0_@plt>:
   72700:      	adrp	x16, 0x7b000
   72704:      	ldr	x17, [x16, #0xb50]
   72708:      	add	x16, x16, #0xb50
   7270c:      	br	x17

0000000000072710 <_ZN8mtlabar327SelectionAnimationInterface8deepCopyEPKS0_@plt>:
   72710:      	adrp	x16, 0x7b000
   72714:      	ldr	x17, [x16, #0xb58]
   72718:      	add	x16, x16, #0xb58
   7271c:      	br	x17

0000000000072720 <_ZN8mtlabar327SelectionAnimationInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72720:      	adrp	x16, 0x7b000
   72724:      	ldr	x17, [x16, #0xb60]
   72728:      	add	x16, x16, #0xb60
   7272c:      	br	x17

0000000000072730 <_ZNK8mtlabar327SelectionAnimationInterface13getConfigPathEv@plt>:
   72730:      	adrp	x16, 0x7b000
   72734:      	ldr	x17, [x16, #0xb68]
   72738:      	add	x16, x16, #0xb68
   7273c:      	br	x17

0000000000072740 <_ZN8mtlabar327SelectionAnimationInterface8setIndexEi@plt>:
   72740:      	adrp	x16, 0x7b000
   72744:      	ldr	x17, [x16, #0xb70]
   72748:      	add	x16, x16, #0xb70
   7274c:      	br	x17

0000000000072750 <_ZNK8mtlabar327SelectionAnimationInterface8getIndexEv@plt>:
   72750:      	adrp	x16, 0x7b000
   72754:      	ldr	x17, [x16, #0xb78]
   72758:      	add	x16, x16, #0xb78
   7275c:      	br	x17

0000000000072760 <_ZN8mtlabar327SelectionAnimationInterface9setLengthEi@plt>:
   72760:      	adrp	x16, 0x7b000
   72764:      	ldr	x17, [x16, #0xb80]
   72768:      	add	x16, x16, #0xb80
   7276c:      	br	x17

0000000000072770 <_ZNK8mtlabar327SelectionAnimationInterface9getLengthEv@plt>:
   72770:      	adrp	x16, 0x7b000
   72774:      	ldr	x17, [x16, #0xb88]
   72778:      	add	x16, x16, #0xb88
   7277c:      	br	x17

0000000000072780 <_ZN8mtlabar327SelectionAnimationInterface11setFontSizeEf@plt>:
   72780:      	adrp	x16, 0x7b000
   72784:      	ldr	x17, [x16, #0xb90]
   72788:      	add	x16, x16, #0xb90
   7278c:      	br	x17

0000000000072790 <_ZNK8mtlabar327SelectionAnimationInterface11getFontSizeEv@plt>:
   72790:      	adrp	x16, 0x7b000
   72794:      	ldr	x17, [x16, #0xb98]
   72798:      	add	x16, x16, #0xb98
   7279c:      	br	x17

00000000000727a0 <_ZN8mtlabar327SelectionAnimationInterface19setDisplayInASRTimeEb@plt>:
   727a0:      	adrp	x16, 0x7b000
   727a4:      	ldr	x17, [x16, #0xba0]
   727a8:      	add	x16, x16, #0xba0
   727ac:      	br	x17

00000000000727b0 <_ZNK8mtlabar327SelectionAnimationInterface19getDisplayInASRTimeEv@plt>:
   727b0:      	adrp	x16, 0x7b000
   727b4:      	ldr	x17, [x16, #0xba8]
   727b8:      	add	x16, x16, #0xba8
   727bc:      	br	x17

00000000000727c0 <_ZN8mtlabar327SelectionAnimationInterface19setDisplayBeginTimeEf@plt>:
   727c0:      	adrp	x16, 0x7b000
   727c4:      	ldr	x17, [x16, #0xbb0]
   727c8:      	add	x16, x16, #0xbb0
   727cc:      	br	x17

00000000000727d0 <_ZNK8mtlabar327SelectionAnimationInterface19getDisplayBeginTimeEv@plt>:
   727d0:      	adrp	x16, 0x7b000
   727d4:      	ldr	x17, [x16, #0xbb8]
   727d8:      	add	x16, x16, #0xbb8
   727dc:      	br	x17

00000000000727e0 <_ZN8mtlabar327SelectionAnimationInterface17setDisplayEndTimeEf@plt>:
   727e0:      	adrp	x16, 0x7b000
   727e4:      	ldr	x17, [x16, #0xbc0]
   727e8:      	add	x16, x16, #0xbc0
   727ec:      	br	x17

00000000000727f0 <_ZNK8mtlabar327SelectionAnimationInterface17getDisplayEndTimeEv@plt>:
   727f0:      	adrp	x16, 0x7b000
   727f4:      	ldr	x17, [x16, #0xbc8]
   727f8:      	add	x16, x16, #0xbc8
   727fc:      	br	x17

0000000000072800 <_ZN8mtlabar323TextNoteDetailInterface6createEv@plt>:
   72800:      	adrp	x16, 0x7b000
   72804:      	ldr	x17, [x16, #0xbd0]
   72808:      	add	x16, x16, #0xbd0
   7280c:      	br	x17

0000000000072810 <_ZN8mtlabar323TextNoteDetailInterface7destroyEPS0_@plt>:
   72810:      	adrp	x16, 0x7b000
   72814:      	ldr	x17, [x16, #0xbd8]
   72818:      	add	x16, x16, #0xbd8
   7281c:      	br	x17

0000000000072820 <_ZN8mtlabar323TextNoteDetailInterface8deepCopyEPKS0_@plt>:
   72820:      	adrp	x16, 0x7b000
   72824:      	ldr	x17, [x16, #0xbe0]
   72828:      	add	x16, x16, #0xbe0
   7282c:      	br	x17

0000000000072830 <_ZN8mtlabar323TextNoteDetailInterface10setSvgPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72830:      	adrp	x16, 0x7b000
   72834:      	ldr	x17, [x16, #0xbe8]
   72838:      	add	x16, x16, #0xbe8
   7283c:      	br	x17

0000000000072840 <_ZNK8mtlabar323TextNoteDetailInterface10getSvgPathEv@plt>:
   72840:      	adrp	x16, 0x7b000
   72844:      	ldr	x17, [x16, #0xbf0]
   72848:      	add	x16, x16, #0xbf0
   7284c:      	br	x17

0000000000072850 <_ZN8mtlabar323TextNoteDetailInterface11setFillTypeENS_4text11SVGFillTypeE@plt>:
   72850:      	adrp	x16, 0x7b000
   72854:      	ldr	x17, [x16, #0xbf8]
   72858:      	add	x16, x16, #0xbf8
   7285c:      	br	x17

0000000000072860 <_ZNK8mtlabar323TextNoteDetailInterface11getFillTypeEv@plt>:
   72860:      	adrp	x16, 0x7b000
   72864:      	ldr	x17, [x16, #0xc00]
   72868:      	add	x16, x16, #0xc00
   7286c:      	br	x17

0000000000072870 <_ZN8mtlabar323TextNoteDetailInterface11setWrapModeENS_4text11SVGWrapModeE@plt>:
   72870:      	adrp	x16, 0x7b000
   72874:      	ldr	x17, [x16, #0xc08]
   72878:      	add	x16, x16, #0xc08
   7287c:      	br	x17

0000000000072880 <_ZNK8mtlabar323TextNoteDetailInterface11getWrapModeEv@plt>:
   72880:      	adrp	x16, 0x7b000
   72884:      	ldr	x17, [x16, #0xc10]
   72888:      	add	x16, x16, #0xc10
   7288c:      	br	x17

0000000000072890 <_ZN8mtlabar323TextNoteDetailInterface14setStretchModeENS_4text14SVGStretchModeE@plt>:
   72890:      	adrp	x16, 0x7b000
   72894:      	ldr	x17, [x16, #0xc18]
   72898:      	add	x16, x16, #0xc18
   7289c:      	br	x17

00000000000728a0 <_ZNK8mtlabar323TextNoteDetailInterface14getStretchModeEv@plt>:
   728a0:      	adrp	x16, 0x7b000
   728a4:      	ldr	x17, [x16, #0xc20]
   728a8:      	add	x16, x16, #0xc20
   728ac:      	br	x17

00000000000728b0 <_ZN8mtlabar323TextNoteDetailInterface8setAlignENS_4text12SVGTextAlignE@plt>:
   728b0:      	adrp	x16, 0x7b000
   728b4:      	ldr	x17, [x16, #0xc28]
   728b8:      	add	x16, x16, #0xc28
   728bc:      	br	x17

00000000000728c0 <_ZNK8mtlabar323TextNoteDetailInterface8getAlignEv@plt>:
   728c0:      	adrp	x16, 0x7b000
   728c4:      	ldr	x17, [x16, #0xc30]
   728c8:      	add	x16, x16, #0xc30
   728cc:      	br	x17

00000000000728d0 <_ZN8mtlabar323TextNoteDetailInterface12setSvgAnchorENS_4text9SVGAnchorE@plt>:
   728d0:      	adrp	x16, 0x7b000
   728d4:      	ldr	x17, [x16, #0xc38]
   728d8:      	add	x16, x16, #0xc38
   728dc:      	br	x17

00000000000728e0 <_ZNK8mtlabar323TextNoteDetailInterface12getSvgAnchorEv@plt>:
   728e0:      	adrp	x16, 0x7b000
   728e4:      	ldr	x17, [x16, #0xc40]
   728e8:      	add	x16, x16, #0xc40
   728ec:      	br	x17

00000000000728f0 <_ZN8mtlabar323TextNoteDetailInterface10setSpacingERKNS_6Float2E@plt>:
   728f0:      	adrp	x16, 0x7b000
   728f4:      	ldr	x17, [x16, #0xc48]
   728f8:      	add	x16, x16, #0xc48
   728fc:      	br	x17

0000000000072900 <_ZNK8mtlabar323TextNoteDetailInterface10getSpacingEv@plt>:
   72900:      	adrp	x16, 0x7b000
   72904:      	ldr	x17, [x16, #0xc50]
   72908:      	add	x16, x16, #0xc50
   7290c:      	br	x17

0000000000072910 <_ZN8mtlabar323TextNoteDetailInterface14setStrokeWidthEf@plt>:
   72910:      	adrp	x16, 0x7b000
   72914:      	ldr	x17, [x16, #0xc58]
   72918:      	add	x16, x16, #0xc58
   7291c:      	br	x17

0000000000072920 <_ZNK8mtlabar323TextNoteDetailInterface14getStrokeWidthEv@plt>:
   72920:      	adrp	x16, 0x7b000
   72924:      	ldr	x17, [x16, #0xc60]
   72928:      	add	x16, x16, #0xc60
   7292c:      	br	x17

0000000000072930 <_ZN8mtlabar323TextNoteDetailInterface9setOffsetERKNS_6Float2E@plt>:
   72930:      	adrp	x16, 0x7b000
   72934:      	ldr	x17, [x16, #0xc68]
   72938:      	add	x16, x16, #0xc68
   7293c:      	br	x17

0000000000072940 <_ZNK8mtlabar323TextNoteDetailInterface9getOffsetEv@plt>:
   72940:      	adrp	x16, 0x7b000
   72944:      	ldr	x17, [x16, #0xc70]
   72948:      	add	x16, x16, #0xc70
   7294c:      	br	x17

0000000000072950 <_ZN8mtlabar323TextNoteDetailInterface8setScaleERKNS_6Float2E@plt>:
   72950:      	adrp	x16, 0x7b000
   72954:      	ldr	x17, [x16, #0xc78]
   72958:      	add	x16, x16, #0xc78
   7295c:      	br	x17

0000000000072960 <_ZNK8mtlabar323TextNoteDetailInterface8getScaleEv@plt>:
   72960:      	adrp	x16, 0x7b000
   72964:      	ldr	x17, [x16, #0xc80]
   72968:      	add	x16, x16, #0xc80
   7296c:      	br	x17

0000000000072970 <_ZN8mtlabar323TextNoteDetailInterface14setOnTopOfTextEb@plt>:
   72970:      	adrp	x16, 0x7b000
   72974:      	ldr	x17, [x16, #0xc88]
   72978:      	add	x16, x16, #0xc88
   7297c:      	br	x17

0000000000072980 <_ZNK8mtlabar323TextNoteDetailInterface14getOnTopOfTextEv@plt>:
   72980:      	adrp	x16, 0x7b000
   72984:      	ldr	x17, [x16, #0xc90]
   72988:      	add	x16, x16, #0xc90
   7298c:      	br	x17

0000000000072990 <_ZN8mtlabar323TextNoteDetailInterface10setAnimateEb@plt>:
   72990:      	adrp	x16, 0x7b000
   72994:      	ldr	x17, [x16, #0xc98]
   72998:      	add	x16, x16, #0xc98
   7299c:      	br	x17

00000000000729a0 <_ZNK8mtlabar323TextNoteDetailInterface10getAnimateEv@plt>:
   729a0:      	adrp	x16, 0x7b000
   729a4:      	ldr	x17, [x16, #0xca0]
   729a8:      	add	x16, x16, #0xca0
   729ac:      	br	x17

00000000000729b0 <_ZN8mtlabar323TextNoteDetailInterface11setOnceTimeEf@plt>:
   729b0:      	adrp	x16, 0x7b000
   729b4:      	ldr	x17, [x16, #0xca8]
   729b8:      	add	x16, x16, #0xca8
   729bc:      	br	x17

00000000000729c0 <_ZNK8mtlabar323TextNoteDetailInterface11getOnceTimeEv@plt>:
   729c0:      	adrp	x16, 0x7b000
   729c4:      	ldr	x17, [x16, #0xcb0]
   729c8:      	add	x16, x16, #0xcb0
   729cc:      	br	x17

00000000000729d0 <_ZN8mtlabar323TextNoteDetailInterface17setBeginTimestampEf@plt>:
   729d0:      	adrp	x16, 0x7b000
   729d4:      	ldr	x17, [x16, #0xcb8]
   729d8:      	add	x16, x16, #0xcb8
   729dc:      	br	x17

00000000000729e0 <_ZNK8mtlabar323TextNoteDetailInterface17getBeginTimestampEv@plt>:
   729e0:      	adrp	x16, 0x7b000
   729e4:      	ldr	x17, [x16, #0xcc0]
   729e8:      	add	x16, x16, #0xcc0
   729ec:      	br	x17

00000000000729f0 <_ZN8mtlabar323TextNoteDetailInterface15setEndTimestampEf@plt>:
   729f0:      	adrp	x16, 0x7b000
   729f4:      	ldr	x17, [x16, #0xcc8]
   729f8:      	add	x16, x16, #0xcc8
   729fc:      	br	x17

0000000000072a00 <_ZNK8mtlabar323TextNoteDetailInterface15getEndTimestampEv@plt>:
   72a00:      	adrp	x16, 0x7b000
   72a04:      	ldr	x17, [x16, #0xcd0]
   72a08:      	add	x16, x16, #0xcd0
   72a0c:      	br	x17

0000000000072a10 <_ZN8mtlabar323TextNoteDetailInterface14setRepeatCountEi@plt>:
   72a10:      	adrp	x16, 0x7b000
   72a14:      	ldr	x17, [x16, #0xcd8]
   72a18:      	add	x16, x16, #0xcd8
   72a1c:      	br	x17

0000000000072a20 <_ZNK8mtlabar323TextNoteDetailInterface14getRepeatCountEv@plt>:
   72a20:      	adrp	x16, 0x7b000
   72a24:      	ldr	x17, [x16, #0xce0]
   72a28:      	add	x16, x16, #0xce0
   72a2c:      	br	x17

0000000000072a30 <_ZN8mtlabar323TextNoteDetailInterface15setEnableStrokeEb@plt>:
   72a30:      	adrp	x16, 0x7b000
   72a34:      	ldr	x17, [x16, #0xce8]
   72a38:      	add	x16, x16, #0xce8
   72a3c:      	br	x17

0000000000072a40 <_ZNK8mtlabar323TextNoteDetailInterface15getEnableStrokeEv@plt>:
   72a40:      	adrp	x16, 0x7b000
   72a44:      	ldr	x17, [x16, #0xcf0]
   72a48:      	add	x16, x16, #0xcf0
   72a4c:      	br	x17

0000000000072a50 <_ZN8mtlabar323TextNoteDetailInterface8setColorERKNS_6ColorAE@plt>:
   72a50:      	adrp	x16, 0x7b000
   72a54:      	ldr	x17, [x16, #0xcf8]
   72a58:      	add	x16, x16, #0xcf8
   72a5c:      	br	x17

0000000000072a60 <_ZNK8mtlabar323TextNoteDetailInterface8getColorEv@plt>:
   72a60:      	adrp	x16, 0x7b000
   72a64:      	ldr	x17, [x16, #0xd00]
   72a68:      	add	x16, x16, #0xd00
   72a6c:      	br	x17

0000000000072a70 <_ZN8mtlabar323TextNoteDetailInterface14setEnableTaperEb@plt>:
   72a70:      	adrp	x16, 0x7b000
   72a74:      	ldr	x17, [x16, #0xd08]
   72a78:      	add	x16, x16, #0xd08
   72a7c:      	br	x17

0000000000072a80 <_ZNK8mtlabar323TextNoteDetailInterface14getEnableTaperEv@plt>:
   72a80:      	adrp	x16, 0x7b000
   72a84:      	ldr	x17, [x16, #0xd10]
   72a88:      	add	x16, x16, #0xd10
   72a8c:      	br	x17

0000000000072a90 <_ZN8mtlabar323TextNoteDetailInterface16setEnableOpacityEb@plt>:
   72a90:      	adrp	x16, 0x7b000
   72a94:      	ldr	x17, [x16, #0xd18]
   72a98:      	add	x16, x16, #0xd18
   72a9c:      	br	x17

0000000000072aa0 <_ZNK8mtlabar323TextNoteDetailInterface16getEnableOpacityEv@plt>:
   72aa0:      	adrp	x16, 0x7b000
   72aa4:      	ldr	x17, [x16, #0xd20]
   72aa8:      	add	x16, x16, #0xd20
   72aac:      	br	x17

0000000000072ab0 <_ZN8mtlabar323TextNoteDetailInterface12setSizeRangeERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
   72ab0:      	adrp	x16, 0x7b000
   72ab4:      	ldr	x17, [x16, #0xd28]
   72ab8:      	add	x16, x16, #0xd28
   72abc:      	br	x17

0000000000072ac0 <_ZNK8mtlabar323TextNoteDetailInterface12getSizeRangeEv@plt>:
   72ac0:      	adrp	x16, 0x7b000
   72ac4:      	ldr	x17, [x16, #0xd30]
   72ac8:      	add	x16, x16, #0xd30
   72acc:      	br	x17

0000000000072ad0 <_ZN8mtlabar323TextNoteDetailInterface10setPaddingERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   72ad0:      	adrp	x16, 0x7b000
   72ad4:      	ldr	x17, [x16, #0xd38]
   72ad8:      	add	x16, x16, #0xd38
   72adc:      	br	x17

0000000000072ae0 <_ZNK8mtlabar323TextNoteDetailInterface10getPaddingEv@plt>:
   72ae0:      	adrp	x16, 0x7b000
   72ae4:      	ldr	x17, [x16, #0xd40]
   72ae8:      	add	x16, x16, #0xd40
   72aec:      	br	x17

0000000000072af0 <_ZN8mtlabar322SelectionNoteInterface6createEv@plt>:
   72af0:      	adrp	x16, 0x7b000
   72af4:      	ldr	x17, [x16, #0xd48]
   72af8:      	add	x16, x16, #0xd48
   72afc:      	br	x17

0000000000072b00 <_ZN8mtlabar322SelectionNoteInterface7destroyEPS0_@plt>:
   72b00:      	adrp	x16, 0x7b000
   72b04:      	ldr	x17, [x16, #0xd50]
   72b08:      	add	x16, x16, #0xd50
   72b0c:      	br	x17

0000000000072b10 <_ZN8mtlabar322SelectionNoteInterface8deepCopyEPKS0_@plt>:
   72b10:      	adrp	x16, 0x7b000
   72b14:      	ldr	x17, [x16, #0xd58]
   72b18:      	add	x16, x16, #0xd58
   72b1c:      	br	x17

0000000000072b20 <_ZN8mtlabar322SelectionNoteInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72b20:      	adrp	x16, 0x7b000
   72b24:      	ldr	x17, [x16, #0xd60]
   72b28:      	add	x16, x16, #0xd60
   72b2c:      	br	x17

0000000000072b30 <_ZNK8mtlabar322SelectionNoteInterface13getConfigPathEv@plt>:
   72b30:      	adrp	x16, 0x7b000
   72b34:      	ldr	x17, [x16, #0xd68]
   72b38:      	add	x16, x16, #0xd68
   72b3c:      	br	x17

0000000000072b40 <_ZN8mtlabar322SelectionNoteInterface18setCustomizeDetailEb@plt>:
   72b40:      	adrp	x16, 0x7b000
   72b44:      	ldr	x17, [x16, #0xd70]
   72b48:      	add	x16, x16, #0xd70
   72b4c:      	br	x17

0000000000072b50 <_ZNK8mtlabar322SelectionNoteInterface18getCustomizeDetailEv@plt>:
   72b50:      	adrp	x16, 0x7b000
   72b54:      	ldr	x17, [x16, #0xd78]
   72b58:      	add	x16, x16, #0xd78
   72b5c:      	br	x17

0000000000072b60 <_ZN8mtlabar322SelectionNoteInterface13getNoteDetailEv@plt>:
   72b60:      	adrp	x16, 0x7b000
   72b64:      	ldr	x17, [x16, #0xd80]
   72b68:      	add	x16, x16, #0xd80
   72b6c:      	br	x17

0000000000072b70 <_ZN8mtlabar322SelectionNoteInterface8setIndexEi@plt>:
   72b70:      	adrp	x16, 0x7b000
   72b74:      	ldr	x17, [x16, #0xd88]
   72b78:      	add	x16, x16, #0xd88
   72b7c:      	br	x17

0000000000072b80 <_ZNK8mtlabar322SelectionNoteInterface8getIndexEv@plt>:
   72b80:      	adrp	x16, 0x7b000
   72b84:      	ldr	x17, [x16, #0xd90]
   72b88:      	add	x16, x16, #0xd90
   72b8c:      	br	x17

0000000000072b90 <_ZN8mtlabar322SelectionNoteInterface9setLengthEi@plt>:
   72b90:      	adrp	x16, 0x7b000
   72b94:      	ldr	x17, [x16, #0xd98]
   72b98:      	add	x16, x16, #0xd98
   72b9c:      	br	x17

0000000000072ba0 <_ZNK8mtlabar322SelectionNoteInterface9getLengthEv@plt>:
   72ba0:      	adrp	x16, 0x7b000
   72ba4:      	ldr	x17, [x16, #0xda0]
   72ba8:      	add	x16, x16, #0xda0
   72bac:      	br	x17

0000000000072bb0 <_ZN8mtlabar322SelectionNoteInterface11setFontSizeEf@plt>:
   72bb0:      	adrp	x16, 0x7b000
   72bb4:      	ldr	x17, [x16, #0xda8]
   72bb8:      	add	x16, x16, #0xda8
   72bbc:      	br	x17

0000000000072bc0 <_ZNK8mtlabar322SelectionNoteInterface11getFontSizeEv@plt>:
   72bc0:      	adrp	x16, 0x7b000
   72bc4:      	ldr	x17, [x16, #0xdb0]
   72bc8:      	add	x16, x16, #0xdb0
   72bcc:      	br	x17

0000000000072bd0 <_ZN8mtlabar322SelectionNoteInterface19setDisplayInASRTimeEb@plt>:
   72bd0:      	adrp	x16, 0x7b000
   72bd4:      	ldr	x17, [x16, #0xdb8]
   72bd8:      	add	x16, x16, #0xdb8
   72bdc:      	br	x17

0000000000072be0 <_ZNK8mtlabar322SelectionNoteInterface19getDisplayInASRTimeEv@plt>:
   72be0:      	adrp	x16, 0x7b000
   72be4:      	ldr	x17, [x16, #0xdc0]
   72be8:      	add	x16, x16, #0xdc0
   72bec:      	br	x17

0000000000072bf0 <_ZN8mtlabar322SelectionNoteInterface19setDisplayBeginTimeEf@plt>:
   72bf0:      	adrp	x16, 0x7b000
   72bf4:      	ldr	x17, [x16, #0xdc8]
   72bf8:      	add	x16, x16, #0xdc8
   72bfc:      	br	x17

0000000000072c00 <_ZNK8mtlabar322SelectionNoteInterface19getDisplayBeginTimeEv@plt>:
   72c00:      	adrp	x16, 0x7b000
   72c04:      	ldr	x17, [x16, #0xdd0]
   72c08:      	add	x16, x16, #0xdd0
   72c0c:      	br	x17

0000000000072c10 <_ZN8mtlabar322SelectionNoteInterface17setDisplayEndTimeEf@plt>:
   72c10:      	adrp	x16, 0x7b000
   72c14:      	ldr	x17, [x16, #0xdd8]
   72c18:      	add	x16, x16, #0xdd8
   72c1c:      	br	x17

0000000000072c20 <_ZNK8mtlabar322SelectionNoteInterface17getDisplayEndTimeEv@plt>:
   72c20:      	adrp	x16, 0x7b000
   72c24:      	ldr	x17, [x16, #0xde0]
   72c28:      	add	x16, x16, #0xde0
   72c2c:      	br	x17

0000000000072c30 <_ZN8mtlabar326IconSequenceColorInterface6createEv@plt>:
   72c30:      	adrp	x16, 0x7b000
   72c34:      	ldr	x17, [x16, #0xde8]
   72c38:      	add	x16, x16, #0xde8
   72c3c:      	br	x17

0000000000072c40 <_ZN8mtlabar326IconSequenceColorInterface7destroyEPS0_@plt>:
   72c40:      	adrp	x16, 0x7b000
   72c44:      	ldr	x17, [x16, #0xdf0]
   72c48:      	add	x16, x16, #0xdf0
   72c4c:      	br	x17

0000000000072c50 <_ZN8mtlabar326IconSequenceColorInterface8deepCopyEPKS0_@plt>:
   72c50:      	adrp	x16, 0x7b000
   72c54:      	ldr	x17, [x16, #0xdf8]
   72c58:      	add	x16, x16, #0xdf8
   72c5c:      	br	x17

0000000000072c60 <_ZN8mtlabar326IconSequenceColorInterface8getColorEv@plt>:
   72c60:      	adrp	x16, 0x7b000
   72c64:      	ldr	x17, [x16, #0xe00]
   72c68:      	add	x16, x16, #0xe00
   72c6c:      	br	x17

0000000000072c70 <_ZN8mtlabar326IconSequenceColorInterface8setColorERKNS_6ColorAE@plt>:
   72c70:      	adrp	x16, 0x7b000
   72c74:      	ldr	x17, [x16, #0xe08]
   72c78:      	add	x16, x16, #0xe08
   72c7c:      	br	x17

0000000000072c80 <_ZNK8mtlabar326IconSequenceColorInterface15getPlaceholdersEv@plt>:
   72c80:      	adrp	x16, 0x7b000
   72c84:      	ldr	x17, [x16, #0xe10]
   72c88:      	add	x16, x16, #0xe10
   72c8c:      	br	x17

0000000000072c90 <_ZN8mtlabar326IconSequenceColorInterface15setPlaceholdersERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   72c90:      	adrp	x16, 0x7b000
   72c94:      	ldr	x17, [x16, #0xe18]
   72c98:      	add	x16, x16, #0xe18
   72c9c:      	br	x17

0000000000072ca0 <_ZN8mtlabar326IconSequenceColorInterface11setEditableEb@plt>:
   72ca0:      	adrp	x16, 0x7b000
   72ca4:      	ldr	x17, [x16, #0xe20]
   72ca8:      	add	x16, x16, #0xe20
   72cac:      	br	x17

0000000000072cb0 <_ZNK8mtlabar326IconSequenceColorInterface10isEditableEv@plt>:
   72cb0:      	adrp	x16, 0x7b000
   72cb4:      	ldr	x17, [x16, #0xe28]
   72cb8:      	add	x16, x16, #0xe28
   72cbc:      	br	x17

0000000000072cc0 <_ZN8mtlabar326IconSequenceStyleInterface6createEv@plt>:
   72cc0:      	adrp	x16, 0x7b000
   72cc4:      	ldr	x17, [x16, #0xe30]
   72cc8:      	add	x16, x16, #0xe30
   72ccc:      	br	x17

0000000000072cd0 <_ZN8mtlabar326IconSequenceStyleInterface7destroyEPS0_@plt>:
   72cd0:      	adrp	x16, 0x7b000
   72cd4:      	ldr	x17, [x16, #0xe38]
   72cd8:      	add	x16, x16, #0xe38
   72cdc:      	br	x17

0000000000072ce0 <_ZN8mtlabar326IconSequenceStyleInterface8deepCopyEPKS0_@plt>:
   72ce0:      	adrp	x16, 0x7b000
   72ce4:      	ldr	x17, [x16, #0xe40]
   72ce8:      	add	x16, x16, #0xe40
   72cec:      	br	x17

0000000000072cf0 <_ZNK8mtlabar326IconSequenceStyleInterface12getImagePathEv@plt>:
   72cf0:      	adrp	x16, 0x7b000
   72cf4:      	ldr	x17, [x16, #0xe48]
   72cf8:      	add	x16, x16, #0xe48
   72cfc:      	br	x17

0000000000072d00 <_ZN8mtlabar326IconSequenceStyleInterface12setImagePathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72d00:      	adrp	x16, 0x7b000
   72d04:      	ldr	x17, [x16, #0xe50]
   72d08:      	add	x16, x16, #0xe50
   72d0c:      	br	x17

0000000000072d10 <_ZNK8mtlabar326IconSequenceStyleInterface8getScaleEv@plt>:
   72d10:      	adrp	x16, 0x7b000
   72d14:      	ldr	x17, [x16, #0xe58]
   72d18:      	add	x16, x16, #0xe58
   72d1c:      	br	x17

0000000000072d20 <_ZN8mtlabar326IconSequenceStyleInterface8setScaleEf@plt>:
   72d20:      	adrp	x16, 0x7b000
   72d24:      	ldr	x17, [x16, #0xe60]
   72d28:      	add	x16, x16, #0xe60
   72d2c:      	br	x17

0000000000072d30 <_ZNK8mtlabar326IconSequenceStyleInterface15getBaseTextSizeEv@plt>:
   72d30:      	adrp	x16, 0x7b000
   72d34:      	ldr	x17, [x16, #0xe68]
   72d38:      	add	x16, x16, #0xe68
   72d3c:      	br	x17

0000000000072d40 <_ZN8mtlabar326IconSequenceStyleInterface15setBaseTextSizeEf@plt>:
   72d40:      	adrp	x16, 0x7b000
   72d44:      	ldr	x17, [x16, #0xe70]
   72d48:      	add	x16, x16, #0xe70
   72d4c:      	br	x17

0000000000072d50 <_ZNK8mtlabar326IconSequenceStyleInterface11getFontSizeEv@plt>:
   72d50:      	adrp	x16, 0x7b000
   72d54:      	ldr	x17, [x16, #0xe78]
   72d58:      	add	x16, x16, #0xe78
   72d5c:      	br	x17

0000000000072d60 <_ZN8mtlabar326IconSequenceStyleInterface11setFontSizeEf@plt>:
   72d60:      	adrp	x16, 0x7b000
   72d64:      	ldr	x17, [x16, #0xe80]
   72d68:      	add	x16, x16, #0xe80
   72d6c:      	br	x17

0000000000072d70 <_ZNK8mtlabar326IconSequenceStyleInterface12getIconWidthEv@plt>:
   72d70:      	adrp	x16, 0x7b000
   72d74:      	ldr	x17, [x16, #0xe88]
   72d78:      	add	x16, x16, #0xe88
   72d7c:      	br	x17

0000000000072d80 <_ZN8mtlabar326IconSequenceStyleInterface12setIconWidthEf@plt>:
   72d80:      	adrp	x16, 0x7b000
   72d84:      	ldr	x17, [x16, #0xe90]
   72d88:      	add	x16, x16, #0xe90
   72d8c:      	br	x17

0000000000072d90 <_ZNK8mtlabar326IconSequenceStyleInterface13getIconHeightEv@plt>:
   72d90:      	adrp	x16, 0x7b000
   72d94:      	ldr	x17, [x16, #0xe98]
   72d98:      	add	x16, x16, #0xe98
   72d9c:      	br	x17

0000000000072da0 <_ZN8mtlabar326IconSequenceStyleInterface13setIconHeightEf@plt>:
   72da0:      	adrp	x16, 0x7b000
   72da4:      	ldr	x17, [x16, #0xea0]
   72da8:      	add	x16, x16, #0xea0
   72dac:      	br	x17

0000000000072db0 <_ZNK8mtlabar326IconSequenceStyleInterface19getReplaceColorSizeEv@plt>:
   72db0:      	adrp	x16, 0x7b000
   72db4:      	ldr	x17, [x16, #0xea8]
   72db8:      	add	x16, x16, #0xea8
   72dbc:      	br	x17

0000000000072dc0 <_ZN8mtlabar326IconSequenceStyleInterface15getReplaceColorEi@plt>:
   72dc0:      	adrp	x16, 0x7b000
   72dc4:      	ldr	x17, [x16, #0xeb0]
   72dc8:      	add	x16, x16, #0xeb0
   72dcc:      	br	x17

0000000000072dd0 <_ZN8mtlabar326IconSequenceStyleInterface19resizeReplaceColorsEm@plt>:
   72dd0:      	adrp	x16, 0x7b000
   72dd4:      	ldr	x17, [x16, #0xeb8]
   72dd8:      	add	x16, x16, #0xeb8
   72ddc:      	br	x17

0000000000072de0 <_ZNK8mtlabar326IconSequenceStyleInterface14getFontLibraryEv@plt>:
   72de0:      	adrp	x16, 0x7b000
   72de4:      	ldr	x17, [x16, #0xec0]
   72de8:      	add	x16, x16, #0xec0
   72dec:      	br	x17

0000000000072df0 <_ZN8mtlabar326IconSequenceStyleInterface14setFontLibraryERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   72df0:      	adrp	x16, 0x7b000
   72df4:      	ldr	x17, [x16, #0xec8]
   72df8:      	add	x16, x16, #0xec8
   72dfc:      	br	x17

0000000000072e00 <_ZNK8mtlabar326IconSequenceStyleInterface18isEnableTextOnIconEv@plt>:
   72e00:      	adrp	x16, 0x7b000
   72e04:      	ldr	x17, [x16, #0xed0]
   72e08:      	add	x16, x16, #0xed0
   72e0c:      	br	x17

0000000000072e10 <_ZN8mtlabar326IconSequenceStyleInterface19setEnableTextOnIconEb@plt>:
   72e10:      	adrp	x16, 0x7b000
   72e14:      	ldr	x17, [x16, #0xed8]
   72e18:      	add	x16, x16, #0xed8
   72e1c:      	br	x17

0000000000072e20 <_ZNK8mtlabar326IconSequenceStyleInterface13isPaddingZeroEv@plt>:
   72e20:      	adrp	x16, 0x7b000
   72e24:      	ldr	x17, [x16, #0xee0]
   72e28:      	add	x16, x16, #0xee0
   72e2c:      	br	x17

0000000000072e30 <_ZN8mtlabar326IconSequenceStyleInterface14setPaddingZeroEb@plt>:
   72e30:      	adrp	x16, 0x7b000
   72e34:      	ldr	x17, [x16, #0xee8]
   72e38:      	add	x16, x16, #0xee8
   72e3c:      	br	x17

0000000000072e40 <_ZN8mtlabar326IconSequenceStyleInterface8getColorEv@plt>:
   72e40:      	adrp	x16, 0x7b000
   72e44:      	ldr	x17, [x16, #0xef0]
   72e48:      	add	x16, x16, #0xef0
   72e4c:      	br	x17

0000000000072e50 <_ZN8mtlabar326IconSequenceStyleInterface8setColorERKNS_6ColorAE@plt>:
   72e50:      	adrp	x16, 0x7b000
   72e54:      	ldr	x17, [x16, #0xef8]
   72e58:      	add	x16, x16, #0xef8
   72e5c:      	br	x17

0000000000072e60 <_ZN8mtlabar320TextASRWordInterface6createEv@plt>:
   72e60:      	adrp	x16, 0x7b000
   72e64:      	ldr	x17, [x16, #0xf00]
   72e68:      	add	x16, x16, #0xf00
   72e6c:      	br	x17

0000000000072e70 <_ZN8mtlabar320TextASRWordInterface7destroyEPS0_@plt>:
   72e70:      	adrp	x16, 0x7b000
   72e74:      	ldr	x17, [x16, #0xf08]
   72e78:      	add	x16, x16, #0xf08
   72e7c:      	br	x17

0000000000072e80 <_ZN8mtlabar320TextASRWordInterface8deepCopyEPKS0_@plt>:
   72e80:      	adrp	x16, 0x7b000
   72e84:      	ldr	x17, [x16, #0xf10]
   72e88:      	add	x16, x16, #0xf10
   72e8c:      	br	x17

0000000000072e90 <_ZN8mtlabar320TextASRWordInterface16getWordTextIndexEv@plt>:
   72e90:      	adrp	x16, 0x7b000
   72e94:      	ldr	x17, [x16, #0xf18]
   72e98:      	add	x16, x16, #0xf18
   72e9c:      	br	x17

0000000000072ea0 <_ZN8mtlabar320TextASRWordInterface16setWordTextIndexEi@plt>:
   72ea0:      	adrp	x16, 0x7b000
   72ea4:      	ldr	x17, [x16, #0xf20]
   72ea8:      	add	x16, x16, #0xf20
   72eac:      	br	x17

0000000000072eb0 <_ZN8mtlabar320TextASRWordInterface17getWordTextLengthEv@plt>:
   72eb0:      	adrp	x16, 0x7b000
   72eb4:      	ldr	x17, [x16, #0xf28]
   72eb8:      	add	x16, x16, #0xf28
   72ebc:      	br	x17

0000000000072ec0 <_ZN8mtlabar320TextASRWordInterface17setWordTextLengthEi@plt>:
   72ec0:      	adrp	x16, 0x7b000
   72ec4:      	ldr	x17, [x16, #0xf30]
   72ec8:      	add	x16, x16, #0xf30
   72ecc:      	br	x17

0000000000072ed0 <_ZN8mtlabar320TextASRWordInterface21getWordBeginTimestampEv@plt>:
   72ed0:      	adrp	x16, 0x7b000
   72ed4:      	ldr	x17, [x16, #0xf38]
   72ed8:      	add	x16, x16, #0xf38
   72edc:      	br	x17

0000000000072ee0 <_ZN8mtlabar320TextASRWordInterface21setWordBeginTimestampEf@plt>:
   72ee0:      	adrp	x16, 0x7b000
   72ee4:      	ldr	x17, [x16, #0xf40]
   72ee8:      	add	x16, x16, #0xf40
   72eec:      	br	x17

0000000000072ef0 <_ZN8mtlabar320TextASRWordInterface19getWordEndTimestampEv@plt>:
   72ef0:      	adrp	x16, 0x7b000
   72ef4:      	ldr	x17, [x16, #0xf48]
   72ef8:      	add	x16, x16, #0xf48
   72efc:      	br	x17

0000000000072f00 <_ZN8mtlabar320TextASRWordInterface19setWordEndTimestampEf@plt>:
   72f00:      	adrp	x16, 0x7b000
   72f04:      	ldr	x17, [x16, #0xf50]
   72f08:      	add	x16, x16, #0xf50
   72f0c:      	br	x17

0000000000072f10 <_ZN8mtlabar316TextASRInterface6createEv@plt>:
   72f10:      	adrp	x16, 0x7b000
   72f14:      	ldr	x17, [x16, #0xf58]
   72f18:      	add	x16, x16, #0xf58
   72f1c:      	br	x17

0000000000072f20 <_ZN8mtlabar316TextASRInterface7destroyEPS0_@plt>:
   72f20:      	adrp	x16, 0x7b000
   72f24:      	ldr	x17, [x16, #0xf60]
   72f28:      	add	x16, x16, #0xf60
   72f2c:      	br	x17

0000000000072f30 <_ZN8mtlabar316TextASRInterface8deepCopyEPKS0_@plt>:
   72f30:      	adrp	x16, 0x7b000
   72f34:      	ldr	x17, [x16, #0xf68]
   72f38:      	add	x16, x16, #0xf68
   72f3c:      	br	x17

0000000000072f40 <_ZN8mtlabar316TextASRInterface16getASRWordsCountEv@plt>:
   72f40:      	adrp	x16, 0x7b000
   72f44:      	ldr	x17, [x16, #0xf70]
   72f48:      	add	x16, x16, #0xf70
   72f4c:      	br	x17

0000000000072f50 <_ZNK8mtlabar316TextASRInterface10getASRWordEi@plt>:
   72f50:      	adrp	x16, 0x7b000
   72f54:      	ldr	x17, [x16, #0xf78]
   72f58:      	add	x16, x16, #0xf78
   72f5c:      	br	x17

0000000000072f60 <_ZN8mtlabar316TextASRInterface10addASRWordEv@plt>:
   72f60:      	adrp	x16, 0x7b000
   72f64:      	ldr	x17, [x16, #0xf80]
   72f68:      	add	x16, x16, #0xf80
   72f6c:      	br	x17

0000000000072f70 <_ZN8mtlabar316TextASRInterface17removeTextASRWordEPNS_20TextASRWordInterfaceE@plt>:
   72f70:      	adrp	x16, 0x7b000
   72f74:      	ldr	x17, [x16, #0xf88]
   72f78:      	add	x16, x16, #0xf88
   72f7c:      	br	x17

0000000000072f80 <_ZN8mtlabar316TextASRInterface16resizeWordsCountEi@plt>:
   72f80:      	adrp	x16, 0x7b000
   72f84:      	ldr	x17, [x16, #0xf90]
   72f88:      	add	x16, x16, #0xf90
   72f8c:      	br	x17

0000000000072f90 <_ZN8mtlabar316TextASRInterface20getASRBeginTimestampEv@plt>:
   72f90:      	adrp	x16, 0x7b000
   72f94:      	ldr	x17, [x16, #0xf98]
   72f98:      	add	x16, x16, #0xf98
   72f9c:      	br	x17

0000000000072fa0 <_ZN8mtlabar316TextASRInterface20setASRBeginTimestampEf@plt>:
   72fa0:      	adrp	x16, 0x7b000
   72fa4:      	ldr	x17, [x16, #0xfa0]
   72fa8:      	add	x16, x16, #0xfa0
   72fac:      	br	x17

0000000000072fb0 <_ZN8mtlabar316TextASRInterface18getASREndTimestampEv@plt>:
   72fb0:      	adrp	x16, 0x7b000
   72fb4:      	ldr	x17, [x16, #0xfa8]
   72fb8:      	add	x16, x16, #0xfa8
   72fbc:      	br	x17

0000000000072fc0 <_ZN8mtlabar316TextASRInterface18setASREndTimestampEf@plt>:
   72fc0:      	adrp	x16, 0x7b000
   72fc4:      	ldr	x17, [x16, #0xfb0]
   72fc8:      	add	x16, x16, #0xfb0
   72fcc:      	br	x17

0000000000072fd0 <_ZN8mtlabar316TextASRInterface25getASRDisplayEndTimestampEv@plt>:
   72fd0:      	adrp	x16, 0x7b000
   72fd4:      	ldr	x17, [x16, #0xfb8]
   72fd8:      	add	x16, x16, #0xfb8
   72fdc:      	br	x17

0000000000072fe0 <_ZN8mtlabar316TextASRInterface25setASRDisplayEndTimestampEf@plt>:
   72fe0:      	adrp	x16, 0x7b000
   72fe4:      	ldr	x17, [x16, #0xfc0]
   72fe8:      	add	x16, x16, #0xfc0
   72fec:      	br	x17

0000000000072ff0 <_ZN8mtlabar316TextASRInterface16getASRGroupIndexEv@plt>:
   72ff0:      	adrp	x16, 0x7b000
   72ff4:      	ldr	x17, [x16, #0xfc8]
   72ff8:      	add	x16, x16, #0xfc8
   72ffc:      	br	x17

0000000000073000 <_ZN8mtlabar316TextASRInterface16setASRGroupIndexEi@plt>:
   73000:      	adrp	x16, 0x7b000
   73004:      	ldr	x17, [x16, #0xfd0]
   73008:      	add	x16, x16, #0xfd0
   7300c:      	br	x17

0000000000073010 <_ZN8mtlabar316TextASRInterface19getASRAnimationTimeEv@plt>:
   73010:      	adrp	x16, 0x7b000
   73014:      	ldr	x17, [x16, #0xfd8]
   73018:      	add	x16, x16, #0xfd8
   7301c:      	br	x17

0000000000073020 <_ZN8mtlabar316TextASRInterface19setASRAnimationTimeEf@plt>:
   73020:      	adrp	x16, 0x7b000
   73024:      	ldr	x17, [x16, #0xfe0]
   73028:      	add	x16, x16, #0xfe0
   7302c:      	br	x17

0000000000073030 <_ZN8mtlabar323TextWarpConfigInterface6createEv@plt>:
   73030:      	adrp	x16, 0x7b000
   73034:      	ldr	x17, [x16, #0xfe8]
   73038:      	add	x16, x16, #0xfe8
   7303c:      	br	x17

0000000000073040 <_ZN8mtlabar323TextWarpConfigInterface7destroyEPS0_@plt>:
   73040:      	adrp	x16, 0x7b000
   73044:      	ldr	x17, [x16, #0xff0]
   73048:      	add	x16, x16, #0xff0
   7304c:      	br	x17

0000000000073050 <_ZN8mtlabar323TextWarpConfigInterface8deepCopyEPKS0_@plt>:
   73050:      	adrp	x16, 0x7b000
   73054:      	ldr	x17, [x16, #0xff8]
   73058:      	add	x16, x16, #0xff8
   7305c:      	br	x17

0000000000073060 <_ZN8mtlabar323TextWarpConfigInterface11setWarpTypeENS_12WarpMeshTypeE@plt>:
   73060:      	adrp	x16, 0x7c000
   73064:      	ldr	x17, [x16]
   73068:      	add	x16, x16, #0x0
   7306c:      	br	x17

0000000000073070 <_ZNK8mtlabar323TextWarpConfigInterface11getWarpTypeEv@plt>:
   73070:      	adrp	x16, 0x7c000
   73074:      	ldr	x17, [x16, #0x8]
   73078:      	add	x16, x16, #0x8
   7307c:      	br	x17

0000000000073080 <_ZN8mtlabar323TextWarpConfigInterface17setWarpConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73080:      	adrp	x16, 0x7c000
   73084:      	ldr	x17, [x16, #0x10]
   73088:      	add	x16, x16, #0x10
   7308c:      	br	x17

0000000000073090 <_ZNK8mtlabar323TextWarpConfigInterface17getWarpConfigPathEv@plt>:
   73090:      	adrp	x16, 0x7c000
   73094:      	ldr	x17, [x16, #0x18]
   73098:      	add	x16, x16, #0x18
   7309c:      	br	x17

00000000000730a0 <_ZN8mtlabar323TextWarpConfigInterface15setWarpProgressEf@plt>:
   730a0:      	adrp	x16, 0x7c000
   730a4:      	ldr	x17, [x16, #0x20]
   730a8:      	add	x16, x16, #0x20
   730ac:      	br	x17

00000000000730b0 <_ZNK8mtlabar323TextWarpConfigInterface15getWarpProgressEv@plt>:
   730b0:      	adrp	x16, 0x7c000
   730b4:      	ldr	x17, [x16, #0x28]
   730b8:      	add	x16, x16, #0x28
   730bc:      	br	x17

00000000000730c0 <_ZN8mtlabar323TextWarpConfigInterface21setWarpRelativeHeightEf@plt>:
   730c0:      	adrp	x16, 0x7c000
   730c4:      	ldr	x17, [x16, #0x30]
   730c8:      	add	x16, x16, #0x30
   730cc:      	br	x17

00000000000730d0 <_ZNK8mtlabar323TextWarpConfigInterface21getWarpRelativeHeightEv@plt>:
   730d0:      	adrp	x16, 0x7c000
   730d4:      	ldr	x17, [x16, #0x38]
   730d8:      	add	x16, x16, #0x38
   730dc:      	br	x17

00000000000730e0 <_ZN8mtlabar326CharSVGBackgroundInterface6createEv@plt>:
   730e0:      	adrp	x16, 0x7c000
   730e4:      	ldr	x17, [x16, #0x40]
   730e8:      	add	x16, x16, #0x40
   730ec:      	br	x17

00000000000730f0 <_ZN8mtlabar326CharSVGBackgroundInterface7destroyEPS0_@plt>:
   730f0:      	adrp	x16, 0x7c000
   730f4:      	ldr	x17, [x16, #0x48]
   730f8:      	add	x16, x16, #0x48
   730fc:      	br	x17

0000000000073100 <_ZN8mtlabar326CharSVGBackgroundInterface8deepCopyEPKS0_@plt>:
   73100:      	adrp	x16, 0x7c000
   73104:      	ldr	x17, [x16, #0x50]
   73108:      	add	x16, x16, #0x50
   7310c:      	br	x17

0000000000073110 <_ZN8mtlabar326CharSVGBackgroundInterface9setEnableEb@plt>:
   73110:      	adrp	x16, 0x7c000
   73114:      	ldr	x17, [x16, #0x58]
   73118:      	add	x16, x16, #0x58
   7311c:      	br	x17

0000000000073120 <_ZNK8mtlabar326CharSVGBackgroundInterface9getEnableEv@plt>:
   73120:      	adrp	x16, 0x7c000
   73124:      	ldr	x17, [x16, #0x60]
   73128:      	add	x16, x16, #0x60
   7312c:      	br	x17

0000000000073130 <_ZN8mtlabar326CharSVGBackgroundInterface11setEditableEb@plt>:
   73130:      	adrp	x16, 0x7c000
   73134:      	ldr	x17, [x16, #0x68]
   73138:      	add	x16, x16, #0x68
   7313c:      	br	x17

0000000000073140 <_ZNK8mtlabar326CharSVGBackgroundInterface11getEditableEv@plt>:
   73140:      	adrp	x16, 0x7c000
   73144:      	ldr	x17, [x16, #0x70]
   73148:      	add	x16, x16, #0x70
   7314c:      	br	x17

0000000000073150 <_ZN8mtlabar326CharSVGBackgroundInterface7setSizeEf@plt>:
   73150:      	adrp	x16, 0x7c000
   73154:      	ldr	x17, [x16, #0x78]
   73158:      	add	x16, x16, #0x78
   7315c:      	br	x17

0000000000073160 <_ZNK8mtlabar326CharSVGBackgroundInterface7getSizeEv@plt>:
   73160:      	adrp	x16, 0x7c000
   73164:      	ldr	x17, [x16, #0x80]
   73168:      	add	x16, x16, #0x80
   7316c:      	br	x17

0000000000073170 <_ZN8mtlabar326CharSVGBackgroundInterface9setOffsetERKNS_6Float2E@plt>:
   73170:      	adrp	x16, 0x7c000
   73174:      	ldr	x17, [x16, #0x88]
   73178:      	add	x16, x16, #0x88
   7317c:      	br	x17

0000000000073180 <_ZNK8mtlabar326CharSVGBackgroundInterface9getOffsetEv@plt>:
   73180:      	adrp	x16, 0x7c000
   73184:      	ldr	x17, [x16, #0x90]
   73188:      	add	x16, x16, #0x90
   7318c:      	br	x17

0000000000073190 <_ZN8mtlabar326CharSVGBackgroundInterface10setPaddingERKNS_6Float2E@plt>:
   73190:      	adrp	x16, 0x7c000
   73194:      	ldr	x17, [x16, #0x98]
   73198:      	add	x16, x16, #0x98
   7319c:      	br	x17

00000000000731a0 <_ZNK8mtlabar326CharSVGBackgroundInterface10getPaddingEv@plt>:
   731a0:      	adrp	x16, 0x7c000
   731a4:      	ldr	x17, [x16, #0xa0]
   731a8:      	add	x16, x16, #0xa0
   731ac:      	br	x17

00000000000731b0 <_ZN8mtlabar326CharSVGBackgroundInterface11setUseCountEi@plt>:
   731b0:      	adrp	x16, 0x7c000
   731b4:      	ldr	x17, [x16, #0xa8]
   731b8:      	add	x16, x16, #0xa8
   731bc:      	br	x17

00000000000731c0 <_ZNK8mtlabar326CharSVGBackgroundInterface11getUseCountEv@plt>:
   731c0:      	adrp	x16, 0x7c000
   731c4:      	ldr	x17, [x16, #0xb0]
   731c8:      	add	x16, x16, #0xb0
   731cc:      	br	x17

00000000000731d0 <_ZN8mtlabar326CharSVGBackgroundInterface24setCharSVGBackgroundPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   731d0:      	adrp	x16, 0x7c000
   731d4:      	ldr	x17, [x16, #0xb8]
   731d8:      	add	x16, x16, #0xb8
   731dc:      	br	x17

00000000000731e0 <_ZNK8mtlabar326CharSVGBackgroundInterface24getCharSVGBackgroundPathEv@plt>:
   731e0:      	adrp	x16, 0x7c000
   731e4:      	ldr	x17, [x16, #0xc0]
   731e8:      	add	x16, x16, #0xc0
   731ec:      	br	x17

00000000000731f0 <_ZN8mtlabar331TextInactiveTextConfigInterface6createEv@plt>:
   731f0:      	adrp	x16, 0x7c000
   731f4:      	ldr	x17, [x16, #0xc8]
   731f8:      	add	x16, x16, #0xc8
   731fc:      	br	x17

0000000000073200 <_ZN8mtlabar331TextInactiveTextConfigInterface7destroyEPS0_@plt>:
   73200:      	adrp	x16, 0x7c000
   73204:      	ldr	x17, [x16, #0xd0]
   73208:      	add	x16, x16, #0xd0
   7320c:      	br	x17

0000000000073210 <_ZN8mtlabar331TextInactiveTextConfigInterface8deepCopyEPKS0_@plt>:
   73210:      	adrp	x16, 0x7c000
   73214:      	ldr	x17, [x16, #0xd8]
   73218:      	add	x16, x16, #0xd8
   7321c:      	br	x17

0000000000073220 <_ZN8mtlabar331TextInactiveTextConfigInterface9setEnableEb@plt>:
   73220:      	adrp	x16, 0x7c000
   73224:      	ldr	x17, [x16, #0xe0]
   73228:      	add	x16, x16, #0xe0
   7322c:      	br	x17

0000000000073230 <_ZNK8mtlabar331TextInactiveTextConfigInterface9getEnableEv@plt>:
   73230:      	adrp	x16, 0x7c000
   73234:      	ldr	x17, [x16, #0xe8]
   73238:      	add	x16, x16, #0xe8
   7323c:      	br	x17

0000000000073240 <_ZN8mtlabar331TextInactiveTextConfigInterface7setTextERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73240:      	adrp	x16, 0x7c000
   73244:      	ldr	x17, [x16, #0xf0]
   73248:      	add	x16, x16, #0xf0
   7324c:      	br	x17

0000000000073250 <_ZNK8mtlabar331TextInactiveTextConfigInterface7getTextEv@plt>:
   73250:      	adrp	x16, 0x7c000
   73254:      	ldr	x17, [x16, #0xf8]
   73258:      	add	x16, x16, #0xf8
   7325c:      	br	x17

0000000000073260 <_ZN8mtlabar331TextInactiveTextConfigInterface11setFontSizeEf@plt>:
   73260:      	adrp	x16, 0x7c000
   73264:      	ldr	x17, [x16, #0x100]
   73268:      	add	x16, x16, #0x100
   7326c:      	br	x17

0000000000073270 <_ZNK8mtlabar331TextInactiveTextConfigInterface11getFontSizeEv@plt>:
   73270:      	adrp	x16, 0x7c000
   73274:      	ldr	x17, [x16, #0x108]
   73278:      	add	x16, x16, #0x108
   7327c:      	br	x17

0000000000073280 <_ZN8mtlabar331TextInactiveTextConfigInterface6setPosENS_4text15InactiveTextPosE@plt>:
   73280:      	adrp	x16, 0x7c000
   73284:      	ldr	x17, [x16, #0x110]
   73288:      	add	x16, x16, #0x110
   7328c:      	br	x17

0000000000073290 <_ZNK8mtlabar331TextInactiveTextConfigInterface6getPosEv@plt>:
   73290:      	adrp	x16, 0x7c000
   73294:      	ldr	x17, [x16, #0x118]
   73298:      	add	x16, x16, #0x118
   7329c:      	br	x17

00000000000732a0 <_ZN8mtlabar331TextInactiveTextConfigInterface17setBeginTimestampEf@plt>:
   732a0:      	adrp	x16, 0x7c000
   732a4:      	ldr	x17, [x16, #0x120]
   732a8:      	add	x16, x16, #0x120
   732ac:      	br	x17

00000000000732b0 <_ZNK8mtlabar331TextInactiveTextConfigInterface17getBeginTimestampEv@plt>:
   732b0:      	adrp	x16, 0x7c000
   732b4:      	ldr	x17, [x16, #0x128]
   732b8:      	add	x16, x16, #0x128
   732bc:      	br	x17

00000000000732c0 <_ZN8mtlabar331TextInactiveTextConfigInterface15setEndTimestampEf@plt>:
   732c0:      	adrp	x16, 0x7c000
   732c4:      	ldr	x17, [x16, #0x130]
   732c8:      	add	x16, x16, #0x130
   732cc:      	br	x17

00000000000732d0 <_ZNK8mtlabar331TextInactiveTextConfigInterface15getEndTimestampEv@plt>:
   732d0:      	adrp	x16, 0x7c000
   732d4:      	ldr	x17, [x16, #0x138]
   732d8:      	add	x16, x16, #0x138
   732dc:      	br	x17

00000000000732e0 <_ZN8mtlabar331TextInactiveTextConfigInterface22setAnimationConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   732e0:      	adrp	x16, 0x7c000
   732e4:      	ldr	x17, [x16, #0x140]
   732e8:      	add	x16, x16, #0x140
   732ec:      	br	x17

00000000000732f0 <_ZNK8mtlabar331TextInactiveTextConfigInterface22getAnimationConfigPathEv@plt>:
   732f0:      	adrp	x16, 0x7c000
   732f4:      	ldr	x17, [x16, #0x148]
   732f8:      	add	x16, x16, #0x148
   732fc:      	br	x17

0000000000073300 <_ZN8mtlabar331TextInactiveTextConfigInterface10getTextASREv@plt>:
   73300:      	adrp	x16, 0x7c000
   73304:      	ldr	x17, [x16, #0x150]
   73308:      	add	x16, x16, #0x150
   7330c:      	br	x17

0000000000073310 <_ZN8mtlabar324CustomTransformInterface6createEv@plt>:
   73310:      	adrp	x16, 0x7c000
   73314:      	ldr	x17, [x16, #0x158]
   73318:      	add	x16, x16, #0x158
   7331c:      	br	x17

0000000000073320 <_ZN8mtlabar324CustomTransformInterface7destroyEPS0_@plt>:
   73320:      	adrp	x16, 0x7c000
   73324:      	ldr	x17, [x16, #0x160]
   73328:      	add	x16, x16, #0x160
   7332c:      	br	x17

0000000000073330 <_ZN8mtlabar324CustomTransformInterface8deepCopyEPKS0_@plt>:
   73330:      	adrp	x16, 0x7c000
   73334:      	ldr	x17, [x16, #0x168]
   73338:      	add	x16, x16, #0x168
   7333c:      	br	x17

0000000000073340 <_ZN8mtlabar324CustomTransformInterface17setEnablePositionEb@plt>:
   73340:      	adrp	x16, 0x7c000
   73344:      	ldr	x17, [x16, #0x170]
   73348:      	add	x16, x16, #0x170
   7334c:      	br	x17

0000000000073350 <_ZNK8mtlabar324CustomTransformInterface17getEnablePositionEv@plt>:
   73350:      	adrp	x16, 0x7c000
   73354:      	ldr	x17, [x16, #0x178]
   73358:      	add	x16, x16, #0x178
   7335c:      	br	x17

0000000000073360 <_ZN8mtlabar324CustomTransformInterface14setEnableScaleEb@plt>:
   73360:      	adrp	x16, 0x7c000
   73364:      	ldr	x17, [x16, #0x180]
   73368:      	add	x16, x16, #0x180
   7336c:      	br	x17

0000000000073370 <_ZNK8mtlabar324CustomTransformInterface14getEnableScaleEv@plt>:
   73370:      	adrp	x16, 0x7c000
   73374:      	ldr	x17, [x16, #0x188]
   73378:      	add	x16, x16, #0x188
   7337c:      	br	x17

0000000000073380 <_ZN8mtlabar324CustomTransformInterface15setEnableRotateEb@plt>:
   73380:      	adrp	x16, 0x7c000
   73384:      	ldr	x17, [x16, #0x190]
   73388:      	add	x16, x16, #0x190
   7338c:      	br	x17

0000000000073390 <_ZNK8mtlabar324CustomTransformInterface15getEnableRotateEv@plt>:
   73390:      	adrp	x16, 0x7c000
   73394:      	ldr	x17, [x16, #0x198]
   73398:      	add	x16, x16, #0x198
   7339c:      	br	x17

00000000000733a0 <_ZN8mtlabar324CustomTransformInterface11setPositionERKNS_6Float3E@plt>:
   733a0:      	adrp	x16, 0x7c000
   733a4:      	ldr	x17, [x16, #0x1a0]
   733a8:      	add	x16, x16, #0x1a0
   733ac:      	br	x17

00000000000733b0 <_ZNK8mtlabar324CustomTransformInterface11getPositionEv@plt>:
   733b0:      	adrp	x16, 0x7c000
   733b4:      	ldr	x17, [x16, #0x1a8]
   733b8:      	add	x16, x16, #0x1a8
   733bc:      	br	x17

00000000000733c0 <_ZN8mtlabar324CustomTransformInterface8setScaleERKNS_6Float3E@plt>:
   733c0:      	adrp	x16, 0x7c000
   733c4:      	ldr	x17, [x16, #0x1b0]
   733c8:      	add	x16, x16, #0x1b0
   733cc:      	br	x17

00000000000733d0 <_ZNK8mtlabar324CustomTransformInterface8getScaleEv@plt>:
   733d0:      	adrp	x16, 0x7c000
   733d4:      	ldr	x17, [x16, #0x1b8]
   733d8:      	add	x16, x16, #0x1b8
   733dc:      	br	x17

00000000000733e0 <_ZN8mtlabar324CustomTransformInterface16setPositionSpeedEf@plt>:
   733e0:      	adrp	x16, 0x7c000
   733e4:      	ldr	x17, [x16, #0x1c0]
   733e8:      	add	x16, x16, #0x1c0
   733ec:      	br	x17

00000000000733f0 <_ZNK8mtlabar324CustomTransformInterface16getPositionSpeedEv@plt>:
   733f0:      	adrp	x16, 0x7c000
   733f4:      	ldr	x17, [x16, #0x1c8]
   733f8:      	add	x16, x16, #0x1c8
   733fc:      	br	x17

0000000000073400 <_ZN8mtlabar324CustomTransformInterface13setScaleSpeedEf@plt>:
   73400:      	adrp	x16, 0x7c000
   73404:      	ldr	x17, [x16, #0x1d0]
   73408:      	add	x16, x16, #0x1d0
   7340c:      	br	x17

0000000000073410 <_ZNK8mtlabar324CustomTransformInterface13getScaleSpeedEv@plt>:
   73410:      	adrp	x16, 0x7c000
   73414:      	ldr	x17, [x16, #0x1d8]
   73418:      	add	x16, x16, #0x1d8
   7341c:      	br	x17

0000000000073420 <_ZN8mtlabar324CustomTransformInterface14setRotateAngleEf@plt>:
   73420:      	adrp	x16, 0x7c000
   73424:      	ldr	x17, [x16, #0x1e0]
   73428:      	add	x16, x16, #0x1e0
   7342c:      	br	x17

0000000000073430 <_ZNK8mtlabar324CustomTransformInterface14getRotateAngleEv@plt>:
   73430:      	adrp	x16, 0x7c000
   73434:      	ldr	x17, [x16, #0x1e8]
   73438:      	add	x16, x16, #0x1e8
   7343c:      	br	x17

0000000000073440 <_ZN8mtlabar324CustomTransformInterface14setElapsedTimeEf@plt>:
   73440:      	adrp	x16, 0x7c000
   73444:      	ldr	x17, [x16, #0x1f0]
   73448:      	add	x16, x16, #0x1f0
   7344c:      	br	x17

0000000000073450 <_ZNK8mtlabar324CustomTransformInterface14getElapsedTimeEv@plt>:
   73450:      	adrp	x16, 0x7c000
   73454:      	ldr	x17, [x16, #0x1f8]
   73458:      	add	x16, x16, #0x1f8
   7345c:      	br	x17

0000000000073460 <_ZN8mtlabar321ActiveWordBgInterface6createEv@plt>:
   73460:      	adrp	x16, 0x7c000
   73464:      	ldr	x17, [x16, #0x200]
   73468:      	add	x16, x16, #0x200
   7346c:      	br	x17

0000000000073470 <_ZN8mtlabar321ActiveWordBgInterface7destroyEPS0_@plt>:
   73470:      	adrp	x16, 0x7c000
   73474:      	ldr	x17, [x16, #0x208]
   73478:      	add	x16, x16, #0x208
   7347c:      	br	x17

0000000000073480 <_ZN8mtlabar321ActiveWordBgInterface8deepCopyEPKS0_@plt>:
   73480:      	adrp	x16, 0x7c000
   73484:      	ldr	x17, [x16, #0x210]
   73488:      	add	x16, x16, #0x210
   7348c:      	br	x17

0000000000073490 <_ZN8mtlabar321ActiveWordBgInterface9setEnableEb@plt>:
   73490:      	adrp	x16, 0x7c000
   73494:      	ldr	x17, [x16, #0x218]
   73498:      	add	x16, x16, #0x218
   7349c:      	br	x17

00000000000734a0 <_ZNK8mtlabar321ActiveWordBgInterface9getEnableEv@plt>:
   734a0:      	adrp	x16, 0x7c000
   734a4:      	ldr	x17, [x16, #0x220]
   734a8:      	add	x16, x16, #0x220
   734ac:      	br	x17

00000000000734b0 <_ZN8mtlabar321ActiveWordBgInterface8getColorEv@plt>:
   734b0:      	adrp	x16, 0x7c000
   734b4:      	ldr	x17, [x16, #0x228]
   734b8:      	add	x16, x16, #0x228
   734bc:      	br	x17

00000000000734c0 <_ZN8mtlabar321ActiveWordBgInterface8setColorERKNS_6ColorAE@plt>:
   734c0:      	adrp	x16, 0x7c000
   734c4:      	ldr	x17, [x16, #0x230]
   734c8:      	add	x16, x16, #0x230
   734cc:      	br	x17

00000000000734d0 <_ZN8mtlabar321ActiveWordBgInterface19setEnableGradientBGEb@plt>:
   734d0:      	adrp	x16, 0x7c000
   734d4:      	ldr	x17, [x16, #0x238]
   734d8:      	add	x16, x16, #0x238
   734dc:      	br	x17

00000000000734e0 <_ZNK8mtlabar321ActiveWordBgInterface19getEnableGradientBGEv@plt>:
   734e0:      	adrp	x16, 0x7c000
   734e4:      	ldr	x17, [x16, #0x240]
   734e8:      	add	x16, x16, #0x240
   734ec:      	br	x17

00000000000734f0 <_ZN8mtlabar321ActiveWordBgInterface14getSecondColorEv@plt>:
   734f0:      	adrp	x16, 0x7c000
   734f4:      	ldr	x17, [x16, #0x248]
   734f8:      	add	x16, x16, #0x248
   734fc:      	br	x17

0000000000073500 <_ZN8mtlabar321ActiveWordBgInterface14setSecondColorERKNS_6ColorAE@plt>:
   73500:      	adrp	x16, 0x7c000
   73504:      	ldr	x17, [x16, #0x250]
   73508:      	add	x16, x16, #0x250
   7350c:      	br	x17

0000000000073510 <_ZN8mtlabar321ActiveWordBgInterface9setRadiusEf@plt>:
   73510:      	adrp	x16, 0x7c000
   73514:      	ldr	x17, [x16, #0x258]
   73518:      	add	x16, x16, #0x258
   7351c:      	br	x17

0000000000073520 <_ZNK8mtlabar321ActiveWordBgInterface9getRadiusEv@plt>:
   73520:      	adrp	x16, 0x7c000
   73524:      	ldr	x17, [x16, #0x260]
   73528:      	add	x16, x16, #0x260
   7352c:      	br	x17

0000000000073530 <_ZN8mtlabar321ActiveWordBgInterface17setTransitionTypeENS_20WordBgTransitionTypeE@plt>:
   73530:      	adrp	x16, 0x7c000
   73534:      	ldr	x17, [x16, #0x268]
   73538:      	add	x16, x16, #0x268
   7353c:      	br	x17

0000000000073540 <_ZNK8mtlabar321ActiveWordBgInterface17getTransitionTypeEv@plt>:
   73540:      	adrp	x16, 0x7c000
   73544:      	ldr	x17, [x16, #0x270]
   73548:      	add	x16, x16, #0x270
   7354c:      	br	x17

0000000000073550 <_ZN8mtlabar326ActiveWordBGParamInterface6createEv@plt>:
   73550:      	adrp	x16, 0x7c000
   73554:      	ldr	x17, [x16, #0x278]
   73558:      	add	x16, x16, #0x278
   7355c:      	br	x17

0000000000073560 <_ZN8mtlabar326ActiveWordBGParamInterface7destroyEPS0_@plt>:
   73560:      	adrp	x16, 0x7c000
   73564:      	ldr	x17, [x16, #0x280]
   73568:      	add	x16, x16, #0x280
   7356c:      	br	x17

0000000000073570 <_ZN8mtlabar326ActiveWordBGParamInterface8deepCopyEPKS0_@plt>:
   73570:      	adrp	x16, 0x7c000
   73574:      	ldr	x17, [x16, #0x288]
   73578:      	add	x16, x16, #0x288
   7357c:      	br	x17

0000000000073580 <_ZN8mtlabar326ActiveWordBGParamInterface9setMarginEi@plt>:
   73580:      	adrp	x16, 0x7c000
   73584:      	ldr	x17, [x16, #0x290]
   73588:      	add	x16, x16, #0x290
   7358c:      	br	x17

0000000000073590 <_ZNK8mtlabar326ActiveWordBGParamInterface9getMarginEv@plt>:
   73590:      	adrp	x16, 0x7c000
   73594:      	ldr	x17, [x16, #0x298]
   73598:      	add	x16, x16, #0x298
   7359c:      	br	x17

00000000000735a0 <_ZN8mtlabar326ActiveWordBGParamInterface23setMarginExtendCoefLeftEf@plt>:
   735a0:      	adrp	x16, 0x7c000
   735a4:      	ldr	x17, [x16, #0x2a0]
   735a8:      	add	x16, x16, #0x2a0
   735ac:      	br	x17

00000000000735b0 <_ZNK8mtlabar326ActiveWordBGParamInterface23getMarginExtendCoefLeftEv@plt>:
   735b0:      	adrp	x16, 0x7c000
   735b4:      	ldr	x17, [x16, #0x2a8]
   735b8:      	add	x16, x16, #0x2a8
   735bc:      	br	x17

00000000000735c0 <_ZN8mtlabar326ActiveWordBGParamInterface22setMarginExtendCoefTopEf@plt>:
   735c0:      	adrp	x16, 0x7c000
   735c4:      	ldr	x17, [x16, #0x2b0]
   735c8:      	add	x16, x16, #0x2b0
   735cc:      	br	x17

00000000000735d0 <_ZNK8mtlabar326ActiveWordBGParamInterface22getMarginExtendCoefTopEv@plt>:
   735d0:      	adrp	x16, 0x7c000
   735d4:      	ldr	x17, [x16, #0x2b8]
   735d8:      	add	x16, x16, #0x2b8
   735dc:      	br	x17

00000000000735e0 <_ZN8mtlabar326ActiveWordBGParamInterface24setMarginExtendCoefRightEf@plt>:
   735e0:      	adrp	x16, 0x7c000
   735e4:      	ldr	x17, [x16, #0x2c0]
   735e8:      	add	x16, x16, #0x2c0
   735ec:      	br	x17

00000000000735f0 <_ZNK8mtlabar326ActiveWordBGParamInterface24getMarginExtendCoefRightEv@plt>:
   735f0:      	adrp	x16, 0x7c000
   735f4:      	ldr	x17, [x16, #0x2c8]
   735f8:      	add	x16, x16, #0x2c8
   735fc:      	br	x17

0000000000073600 <_ZN8mtlabar326ActiveWordBGParamInterface25setMarginExtendCoefBottomEf@plt>:
   73600:      	adrp	x16, 0x7c000
   73604:      	ldr	x17, [x16, #0x2d0]
   73608:      	add	x16, x16, #0x2d0
   7360c:      	br	x17

0000000000073610 <_ZNK8mtlabar326ActiveWordBGParamInterface25getMarginExtendCoefBottomEv@plt>:
   73610:      	adrp	x16, 0x7c000
   73614:      	ldr	x17, [x16, #0x2d8]
   73618:      	add	x16, x16, #0x2d8
   7361c:      	br	x17

0000000000073620 <_ZN8mtlabar326ActiveWordBGParamInterface16setAnimationTimeEf@plt>:
   73620:      	adrp	x16, 0x7c000
   73624:      	ldr	x17, [x16, #0x2e0]
   73628:      	add	x16, x16, #0x2e0
   7362c:      	br	x17

0000000000073630 <_ZNK8mtlabar326ActiveWordBGParamInterface16getAnimationTimeEv@plt>:
   73630:      	adrp	x16, 0x7c000
   73634:      	ldr	x17, [x16, #0x2e8]
   73638:      	add	x16, x16, #0x2e8
   7363c:      	br	x17

0000000000073640 <_ZN8mtlabar326ActiveWordBGParamInterface8getParamEv@plt>:
   73640:      	adrp	x16, 0x7c000
   73644:      	ldr	x17, [x16, #0x2f0]
   73648:      	add	x16, x16, #0x2f0
   7364c:      	br	x17

0000000000073650 <_ZN8mtlabar324ActiveWordColorInterface6createEv@plt>:
   73650:      	adrp	x16, 0x7c000
   73654:      	ldr	x17, [x16, #0x2f8]
   73658:      	add	x16, x16, #0x2f8
   7365c:      	br	x17

0000000000073660 <_ZN8mtlabar324ActiveWordColorInterface7destroyEPS0_@plt>:
   73660:      	adrp	x16, 0x7c000
   73664:      	ldr	x17, [x16, #0x300]
   73668:      	add	x16, x16, #0x300
   7366c:      	br	x17

0000000000073670 <_ZN8mtlabar324ActiveWordColorInterface8deepCopyEPKS0_@plt>:
   73670:      	adrp	x16, 0x7c000
   73674:      	ldr	x17, [x16, #0x308]
   73678:      	add	x16, x16, #0x308
   7367c:      	br	x17

0000000000073680 <_ZN8mtlabar324ActiveWordColorInterface9setEnableEb@plt>:
   73680:      	adrp	x16, 0x7c000
   73684:      	ldr	x17, [x16, #0x310]
   73688:      	add	x16, x16, #0x310
   7368c:      	br	x17

0000000000073690 <_ZNK8mtlabar324ActiveWordColorInterface9getEnableEv@plt>:
   73690:      	adrp	x16, 0x7c000
   73694:      	ldr	x17, [x16, #0x318]
   73698:      	add	x16, x16, #0x318
   7369c:      	br	x17

00000000000736a0 <_ZN8mtlabar324ActiveWordColorInterface8getColorEv@plt>:
   736a0:      	adrp	x16, 0x7c000
   736a4:      	ldr	x17, [x16, #0x320]
   736a8:      	add	x16, x16, #0x320
   736ac:      	br	x17

00000000000736b0 <_ZN8mtlabar324ActiveWordColorInterface8setColorERKNS_6ColorAE@plt>:
   736b0:      	adrp	x16, 0x7c000
   736b4:      	ldr	x17, [x16, #0x328]
   736b8:      	add	x16, x16, #0x328
   736bc:      	br	x17

00000000000736c0 <_ZN8mtlabar324ActiveWordStyleInterface6createEv@plt>:
   736c0:      	adrp	x16, 0x7c000
   736c4:      	ldr	x17, [x16, #0x330]
   736c8:      	add	x16, x16, #0x330
   736cc:      	br	x17

00000000000736d0 <_ZN8mtlabar324ActiveWordStyleInterface7destroyEPS0_@plt>:
   736d0:      	adrp	x16, 0x7c000
   736d4:      	ldr	x17, [x16, #0x338]
   736d8:      	add	x16, x16, #0x338
   736dc:      	br	x17

00000000000736e0 <_ZN8mtlabar324ActiveWordStyleInterface8deepCopyEPKS0_@plt>:
   736e0:      	adrp	x16, 0x7c000
   736e4:      	ldr	x17, [x16, #0x340]
   736e8:      	add	x16, x16, #0x340
   736ec:      	br	x17

00000000000736f0 <_ZN8mtlabar324ActiveWordStyleInterface9setEnableEb@plt>:
   736f0:      	adrp	x16, 0x7c000
   736f4:      	ldr	x17, [x16, #0x348]
   736f8:      	add	x16, x16, #0x348
   736fc:      	br	x17

0000000000073700 <_ZNK8mtlabar324ActiveWordStyleInterface9getEnableEv@plt>:
   73700:      	adrp	x16, 0x7c000
   73704:      	ldr	x17, [x16, #0x350]
   73708:      	add	x16, x16, #0x350
   7370c:      	br	x17

0000000000073710 <_ZN8mtlabar324ActiveWordStyleInterface13setConfigPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73710:      	adrp	x16, 0x7c000
   73714:      	ldr	x17, [x16, #0x358]
   73718:      	add	x16, x16, #0x358
   7371c:      	br	x17

0000000000073720 <_ZNK8mtlabar324ActiveWordStyleInterface13getConfigPathEv@plt>:
   73720:      	adrp	x16, 0x7c000
   73724:      	ldr	x17, [x16, #0x360]
   73728:      	add	x16, x16, #0x360
   7372c:      	br	x17

0000000000073730 <_ZN8mtlabar324ActiveWordStyleInterface14setFontLibraryERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73730:      	adrp	x16, 0x7c000
   73734:      	ldr	x17, [x16, #0x368]
   73738:      	add	x16, x16, #0x368
   7373c:      	br	x17

0000000000073740 <_ZNK8mtlabar324ActiveWordStyleInterface14getFontLibraryEv@plt>:
   73740:      	adrp	x16, 0x7c000
   73744:      	ldr	x17, [x16, #0x370]
   73748:      	add	x16, x16, #0x370
   7374c:      	br	x17

0000000000073750 <_ZN8mtlabar323CharBackgroundInterface6createEv@plt>:
   73750:      	adrp	x16, 0x7c000
   73754:      	ldr	x17, [x16, #0x378]
   73758:      	add	x16, x16, #0x378
   7375c:      	br	x17

0000000000073760 <_ZN8mtlabar323CharBackgroundInterface7destroyEPS0_@plt>:
   73760:      	adrp	x16, 0x7c000
   73764:      	ldr	x17, [x16, #0x380]
   73768:      	add	x16, x16, #0x380
   7376c:      	br	x17

0000000000073770 <_ZN8mtlabar323CharBackgroundInterface8deepCopyEPKS0_@plt>:
   73770:      	adrp	x16, 0x7c000
   73774:      	ldr	x17, [x16, #0x388]
   73778:      	add	x16, x16, #0x388
   7377c:      	br	x17

0000000000073780 <_ZN8mtlabar323CharBackgroundInterface9setEnableEb@plt>:
   73780:      	adrp	x16, 0x7c000
   73784:      	ldr	x17, [x16, #0x390]
   73788:      	add	x16, x16, #0x390
   7378c:      	br	x17

0000000000073790 <_ZNK8mtlabar323CharBackgroundInterface9getEnableEv@plt>:
   73790:      	adrp	x16, 0x7c000
   73794:      	ldr	x17, [x16, #0x398]
   73798:      	add	x16, x16, #0x398
   7379c:      	br	x17

00000000000737a0 <_ZN8mtlabar323CharBackgroundInterface11setEditableEb@plt>:
   737a0:      	adrp	x16, 0x7c000
   737a4:      	ldr	x17, [x16, #0x3a0]
   737a8:      	add	x16, x16, #0x3a0
   737ac:      	br	x17

00000000000737b0 <_ZNK8mtlabar323CharBackgroundInterface11getEditableEv@plt>:
   737b0:      	adrp	x16, 0x7c000
   737b4:      	ldr	x17, [x16, #0x3a8]
   737b8:      	add	x16, x16, #0x3a8
   737bc:      	br	x17

00000000000737c0 <_ZN8mtlabar323CharBackgroundInterface7setSizeEf@plt>:
   737c0:      	adrp	x16, 0x7c000
   737c4:      	ldr	x17, [x16, #0x3b0]
   737c8:      	add	x16, x16, #0x3b0
   737cc:      	br	x17

00000000000737d0 <_ZNK8mtlabar323CharBackgroundInterface7getSizeEv@plt>:
   737d0:      	adrp	x16, 0x7c000
   737d4:      	ldr	x17, [x16, #0x3b8]
   737d8:      	add	x16, x16, #0x3b8
   737dc:      	br	x17

00000000000737e0 <_ZN8mtlabar323CharBackgroundInterface9setOffsetERKNS_6Float2E@plt>:
   737e0:      	adrp	x16, 0x7c000
   737e4:      	ldr	x17, [x16, #0x3c0]
   737e8:      	add	x16, x16, #0x3c0
   737ec:      	br	x17

00000000000737f0 <_ZNK8mtlabar323CharBackgroundInterface9getOffsetEv@plt>:
   737f0:      	adrp	x16, 0x7c000
   737f4:      	ldr	x17, [x16, #0x3c8]
   737f8:      	add	x16, x16, #0x3c8
   737fc:      	br	x17

0000000000073800 <_ZN8mtlabar323CharBackgroundInterface8setScaleERKNS_6Float2E@plt>:
   73800:      	adrp	x16, 0x7c000
   73804:      	ldr	x17, [x16, #0x3d0]
   73808:      	add	x16, x16, #0x3d0
   7380c:      	br	x17

0000000000073810 <_ZNK8mtlabar323CharBackgroundInterface8getScaleEv@plt>:
   73810:      	adrp	x16, 0x7c000
   73814:      	ldr	x17, [x16, #0x3d8]
   73818:      	add	x16, x16, #0x3d8
   7381c:      	br	x17

0000000000073820 <_ZN8mtlabar323CharBackgroundInterface25setTextureOverlayGlyphNumEi@plt>:
   73820:      	adrp	x16, 0x7c000
   73824:      	ldr	x17, [x16, #0x3e0]
   73828:      	add	x16, x16, #0x3e0
   7382c:      	br	x17

0000000000073830 <_ZNK8mtlabar323CharBackgroundInterface25getTextureOverlayGlyphNumEv@plt>:
   73830:      	adrp	x16, 0x7c000
   73834:      	ldr	x17, [x16, #0x3e8]
   73838:      	add	x16, x16, #0x3e8
   7383c:      	br	x17

0000000000073840 <_ZN8mtlabar323CharBackgroundInterface23setEnableGlyphTransformEb@plt>:
   73840:      	adrp	x16, 0x7c000
   73844:      	ldr	x17, [x16, #0x3f0]
   73848:      	add	x16, x16, #0x3f0
   7384c:      	br	x17

0000000000073850 <_ZNK8mtlabar323CharBackgroundInterface23getEnableGlyphTransformEv@plt>:
   73850:      	adrp	x16, 0x7c000
   73854:      	ldr	x17, [x16, #0x3f8]
   73858:      	add	x16, x16, #0x3f8
   7385c:      	br	x17

0000000000073860 <_ZN8mtlabar323CharBackgroundInterface21setCharBackgroundPathERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73860:      	adrp	x16, 0x7c000
   73864:      	ldr	x17, [x16, #0x400]
   73868:      	add	x16, x16, #0x400
   7386c:      	br	x17

0000000000073870 <_ZNK8mtlabar323CharBackgroundInterface21getCharBackgroundPathEv@plt>:
   73870:      	adrp	x16, 0x7c000
   73874:      	ldr	x17, [x16, #0x408]
   73878:      	add	x16, x16, #0x408
   7387c:      	br	x17

0000000000073880 <_ZN8mtlabar325LineLayoutConfigInterface6createEv@plt>:
   73880:      	adrp	x16, 0x7c000
   73884:      	ldr	x17, [x16, #0x410]
   73888:      	add	x16, x16, #0x410
   7388c:      	br	x17

0000000000073890 <_ZN8mtlabar325LineLayoutConfigInterface7destroyEPS0_@plt>:
   73890:      	adrp	x16, 0x7c000
   73894:      	ldr	x17, [x16, #0x418]
   73898:      	add	x16, x16, #0x418
   7389c:      	br	x17

00000000000738a0 <_ZN8mtlabar325LineLayoutConfigInterface8deepCopyEPKS0_@plt>:
   738a0:      	adrp	x16, 0x7c000
   738a4:      	ldr	x17, [x16, #0x420]
   738a8:      	add	x16, x16, #0x420
   738ac:      	br	x17

00000000000738b0 <_ZNK8mtlabar325LineLayoutConfigInterface14getTransOriginEv@plt>:
   738b0:      	adrp	x16, 0x7c000
   738b4:      	ldr	x17, [x16, #0x428]
   738b8:      	add	x16, x16, #0x428
   738bc:      	br	x17

00000000000738c0 <_ZNK8mtlabar325LineLayoutConfigInterface18getTransxHeightRefEv@plt>:
   738c0:      	adrp	x16, 0x7c000
   738c4:      	ldr	x17, [x16, #0x430]
   738c8:      	add	x16, x16, #0x430
   738cc:      	br	x17

00000000000738d0 <_ZNK8mtlabar325LineLayoutConfigInterface21getTransxHeightCornerEv@plt>:
   738d0:      	adrp	x16, 0x7c000
   738d4:      	ldr	x17, [x16, #0x438]
   738d8:      	add	x16, x16, #0x438
   738dc:      	br	x17

00000000000738e0 <_ZNK8mtlabar325LineLayoutConfigInterface16getTransWidthRefEv@plt>:
   738e0:      	adrp	x16, 0x7c000
   738e4:      	ldr	x17, [x16, #0x440]
   738e8:      	add	x16, x16, #0x440
   738ec:      	br	x17

00000000000738f0 <_ZN8mtlabar323SubTextLayerInteraction11getTextEnumEv@plt>:
   738f0:      	adrp	x16, 0x7c000
   738f4:      	ldr	x17, [x16, #0x448]
   738f8:      	add	x16, x16, #0x448
   738fc:      	br	x17

0000000000073900 <_ZN8mtlabar323SubTextLayerInteraction12getInputFlagEv@plt>:
   73900:      	adrp	x16, 0x7c000
   73904:      	ldr	x17, [x16, #0x450]
   73908:      	add	x16, x16, #0x450
   7390c:      	br	x17

0000000000073910 <_ZN8mtlabar323SubTextLayerInteraction11getTextRectEv@plt>:
   73910:      	adrp	x16, 0x7c000
   73914:      	ldr	x17, [x16, #0x458]
   73918:      	add	x16, x16, #0x458
   7391c:      	br	x17

0000000000073920 <_ZN8mtlabar323SubTextLayerInteraction7getTextEv@plt>:
   73920:      	adrp	x16, 0x7c000
   73924:      	ldr	x17, [x16, #0x460]
   73928:      	add	x16, x16, #0x460
   7392c:      	br	x17

0000000000073930 <_ZN8mtlabar323SubTextLayerInteraction7setTextERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73930:      	adrp	x16, 0x7c000
   73934:      	ldr	x17, [x16, #0x468]
   73938:      	add	x16, x16, #0x468
   7393c:      	br	x17

0000000000073940 <_ZNK8mtlabar323SubTextLayerInteraction11getMissTextEv@plt>:
   73940:      	adrp	x16, 0x7c000
   73944:      	ldr	x17, [x16, #0x470]
   73948:      	add	x16, x16, #0x470
   7394c:      	br	x17

0000000000073950 <_ZN8mtlabar323SubTextLayerInteraction11setMissTextERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   73950:      	adrp	x16, 0x7c000
   73954:      	ldr	x17, [x16, #0x478]
   73958:      	add	x16, x16, #0x478
   7395c:      	br	x17

0000000000073960 <_ZN8mtlabar323SubTextLayerInteraction14getFontLibraryEv@plt>:
   73960:      	adrp	x16, 0x7c000
   73964:      	ldr	x17, [x16, #0x480]
   73968:      	add	x16, x16, #0x480
   7396c:      	br	x17

0000000000073970 <_ZN8mtlabar323SubTextLayerInteraction14setFontLibraryEPKc@plt>:
   73970:      	adrp	x16, 0x7c000
   73974:      	ldr	x17, [x16, #0x488]
   73978:      	add	x16, x16, #0x488
   7397c:      	br	x17

0000000000073980 <_ZN8mtlabar323SubTextLayerInteraction24getFallbackFontLibrariesEv@plt>:
   73980:      	adrp	x16, 0x7c000
   73984:      	ldr	x17, [x16, #0x490]
   73988:      	add	x16, x16, #0x490
   7398c:      	br	x17

0000000000073990 <_ZN8mtlabar323SubTextLayerInteraction24setFallbackFontLibrariesERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   73990:      	adrp	x16, 0x7c000
   73994:      	ldr	x17, [x16, #0x498]
   73998:      	add	x16, x16, #0x498
   7399c:      	br	x17

00000000000739a0 <_ZN8mtlabar323SubTextLayerInteraction11getFontSizeEv@plt>:
   739a0:      	adrp	x16, 0x7c000
   739a4:      	ldr	x17, [x16, #0x4a0]
   739a8:      	add	x16, x16, #0x4a0
   739ac:      	br	x17

00000000000739b0 <_ZN8mtlabar323SubTextLayerInteraction11setFontSizeEf@plt>:
   739b0:      	adrp	x16, 0x7c000
   739b4:      	ldr	x17, [x16, #0x4a8]
   739b8:      	add	x16, x16, #0x4a8
   739bc:      	br	x17

00000000000739c0 <_ZN8mtlabar323SubTextLayerInteraction23getActualRenderFontSizeEv@plt>:
   739c0:      	adrp	x16, 0x7c000
   739c4:      	ldr	x17, [x16, #0x4b0]
   739c8:      	add	x16, x16, #0x4b0
   739cc:      	br	x17

00000000000739d0 <_ZN8mtlabar323SubTextLayerInteraction10getOpacityEv@plt>:
   739d0:      	adrp	x16, 0x7c000
   739d4:      	ldr	x17, [x16, #0x4b8]
   739d8:      	add	x16, x16, #0x4b8
   739dc:      	br	x17

00000000000739e0 <_ZN8mtlabar323SubTextLayerInteraction10setOpacityEf@plt>:
   739e0:      	adrp	x16, 0x7c000
   739e4:      	ldr	x17, [x16, #0x4c0]
   739e8:      	add	x16, x16, #0x4c0
   739ec:      	br	x17

00000000000739f0 <_ZN8mtlabar323SubTextLayerInteraction9getColorAEv@plt>:
   739f0:      	adrp	x16, 0x7c000
   739f4:      	ldr	x17, [x16, #0x4c8]
   739f8:      	add	x16, x16, #0x4c8
   739fc:      	br	x17

0000000000073a00 <_ZN8mtlabar323SubTextLayerInteraction9setColorAERKNS_6ColorAE@plt>:
   73a00:      	adrp	x16, 0x7c000
   73a04:      	ldr	x17, [x16, #0x4d0]
   73a08:      	add	x16, x16, #0x4d0
   73a0c:      	br	x17

0000000000073a10 <_ZN8mtlabar323SubTextLayerInteraction19getIsColorORGBAWorkEv@plt>:
   73a10:      	adrp	x16, 0x7c000
   73a14:      	ldr	x17, [x16, #0x4d8]
   73a18:      	add	x16, x16, #0x4d8
   73a1c:      	br	x17

0000000000073a20 <_ZN8mtlabar323SubTextLayerInteraction19setIsColorORGBAWorkEb@plt>:
   73a20:      	adrp	x16, 0x7c000
   73a24:      	ldr	x17, [x16, #0x4e0]
   73a28:      	add	x16, x16, #0x4e0
   73a2c:      	br	x17

0000000000073a30 <_ZN8mtlabar323SubTextLayerInteraction15getIsStaticShowEv@plt>:
   73a30:      	adrp	x16, 0x7c000
   73a34:      	ldr	x17, [x16, #0x4e8]
   73a38:      	add	x16, x16, #0x4e8
   73a3c:      	br	x17

0000000000073a40 <_ZN8mtlabar323SubTextLayerInteraction15setIsStaticShowEb@plt>:
   73a40:      	adrp	x16, 0x7c000
   73a44:      	ldr	x17, [x16, #0x4f0]
   73a48:      	add	x16, x16, #0x4f0
   73a4c:      	br	x17

0000000000073a50 <_ZN8mtlabar323SubTextLayerInteraction17getIsMultiStrokesEv@plt>:
   73a50:      	adrp	x16, 0x7c000
   73a54:      	ldr	x17, [x16, #0x4f8]
   73a58:      	add	x16, x16, #0x4f8
   73a5c:      	br	x17

0000000000073a60 <_ZN8mtlabar323SubTextLayerInteraction17setIsMultiStrokesEb@plt>:
   73a60:      	adrp	x16, 0x7c000
   73a64:      	ldr	x17, [x16, #0x500]
   73a68:      	add	x16, x16, #0x500
   73a6c:      	br	x17

0000000000073a70 <_ZN8mtlabar323SubTextLayerInteraction9getIsBoldEv@plt>:
   73a70:      	adrp	x16, 0x7c000
   73a74:      	ldr	x17, [x16, #0x508]
   73a78:      	add	x16, x16, #0x508
   73a7c:      	br	x17

0000000000073a80 <_ZN8mtlabar323SubTextLayerInteraction9setIsBoldEb@plt>:
   73a80:      	adrp	x16, 0x7c000
   73a84:      	ldr	x17, [x16, #0x510]
   73a88:      	add	x16, x16, #0x510
   73a8c:      	br	x17

0000000000073a90 <_ZN8mtlabar323SubTextLayerInteraction11getIsItalicEv@plt>:
   73a90:      	adrp	x16, 0x7c000
   73a94:      	ldr	x17, [x16, #0x518]
   73a98:      	add	x16, x16, #0x518
   73a9c:      	br	x17

0000000000073aa0 <_ZN8mtlabar323SubTextLayerInteraction11setIsItalicEb@plt>:
   73aa0:      	adrp	x16, 0x7c000
   73aa4:      	ldr	x17, [x16, #0x520]
   73aa8:      	add	x16, x16, #0x520
   73aac:      	br	x17

0000000000073ab0 <_ZN8mtlabar323SubTextLayerInteraction14getIsUnderlineEv@plt>:
   73ab0:      	adrp	x16, 0x7c000
   73ab4:      	ldr	x17, [x16, #0x528]
   73ab8:      	add	x16, x16, #0x528
   73abc:      	br	x17

0000000000073ac0 <_ZN8mtlabar323SubTextLayerInteraction14setIsUnderlineEb@plt>:
   73ac0:      	adrp	x16, 0x7c000
   73ac4:      	ldr	x17, [x16, #0x530]
   73ac8:      	add	x16, x16, #0x530
   73acc:      	br	x17

0000000000073ad0 <_ZN8mtlabar323SubTextLayerInteraction18getIsStrikeThroughEv@plt>:
   73ad0:      	adrp	x16, 0x7c000
   73ad4:      	ldr	x17, [x16, #0x538]
   73ad8:      	add	x16, x16, #0x538
   73adc:      	br	x17

0000000000073ae0 <_ZN8mtlabar323SubTextLayerInteraction18setIsStrikeThroughEb@plt>:
   73ae0:      	adrp	x16, 0x7c000
   73ae4:      	ldr	x17, [x16, #0x540]
   73ae8:      	add	x16, x16, #0x540
   73aec:      	br	x17

0000000000073af0 <_ZN8mtlabar323SubTextLayerInteraction10getJustifyEv@plt>:
   73af0:      	adrp	x16, 0x7c000
   73af4:      	ldr	x17, [x16, #0x548]
   73af8:      	add	x16, x16, #0x548
   73afc:      	br	x17

0000000000073b00 <_ZN8mtlabar323SubTextLayerInteraction10setJustifyENS_4text11TextJustifyE@plt>:
   73b00:      	adrp	x16, 0x7c000
   73b04:      	ldr	x17, [x16, #0x550]
   73b08:      	add	x16, x16, #0x550
   73b0c:      	br	x17

0000000000073b10 <_ZN8mtlabar323SubTextLayerInteraction13getHorizontalEv@plt>:
   73b10:      	adrp	x16, 0x7c000
   73b14:      	ldr	x17, [x16, #0x558]
   73b18:      	add	x16, x16, #0x558
   73b1c:      	br	x17

0000000000073b20 <_ZN8mtlabar323SubTextLayerInteraction13setHorizontalEb@plt>:
   73b20:      	adrp	x16, 0x7c000
   73b24:      	ldr	x17, [x16, #0x560]
   73b28:      	add	x16, x16, #0x560
   73b2c:      	br	x17

0000000000073b30 <_ZN8mtlabar323SubTextLayerInteraction14getLeftToRightEv@plt>:
   73b30:      	adrp	x16, 0x7c000
   73b34:      	ldr	x17, [x16, #0x568]
   73b38:      	add	x16, x16, #0x568
   73b3c:      	br	x17

0000000000073b40 <_ZN8mtlabar323SubTextLayerInteraction14setLeftToRightEb@plt>:
   73b40:      	adrp	x16, 0x7c000
   73b44:      	ldr	x17, [x16, #0x570]
   73b48:      	add	x16, x16, #0x570
   73b4c:      	br	x17

0000000000073b50 <_ZN8mtlabar323SubTextLayerInteraction7getWrapEv@plt>:
   73b50:      	adrp	x16, 0x7c000
   73b54:      	ldr	x17, [x16, #0x578]
   73b58:      	add	x16, x16, #0x578
   73b5c:      	br	x17

0000000000073b60 <_ZN8mtlabar323SubTextLayerInteraction7setWrapEb@plt>:
   73b60:      	adrp	x16, 0x7c000
   73b64:      	ldr	x17, [x16, #0x580]
   73b68:      	add	x16, x16, #0x580
   73b6c:      	br	x17

0000000000073b70 <_ZN8mtlabar323SubTextLayerInteraction9getShrinkEv@plt>:
   73b70:      	adrp	x16, 0x7c000
   73b74:      	ldr	x17, [x16, #0x588]
   73b78:      	add	x16, x16, #0x588
   73b7c:      	br	x17

0000000000073b80 <_ZN8mtlabar323SubTextLayerInteraction9setShrinkEb@plt>:
   73b80:      	adrp	x16, 0x7c000
   73b84:      	ldr	x17, [x16, #0x590]
   73b88:      	add	x16, x16, #0x590
   73b8c:      	br	x17

0000000000073b90 <_ZN8mtlabar323SubTextLayerInteraction10getSpacingEv@plt>:
   73b90:      	adrp	x16, 0x7c000
   73b94:      	ldr	x17, [x16, #0x598]
   73b98:      	add	x16, x16, #0x598
   73b9c:      	br	x17

0000000000073ba0 <_ZN8mtlabar323SubTextLayerInteraction10setSpacingEf@plt>:
   73ba0:      	adrp	x16, 0x7c000
   73ba4:      	ldr	x17, [x16, #0x5a0]
   73ba8:      	add	x16, x16, #0x5a0
   73bac:      	br	x17

0000000000073bb0 <_ZN8mtlabar323SubTextLayerInteraction14getLineSpacingEv@plt>:
   73bb0:      	adrp	x16, 0x7c000
   73bb4:      	ldr	x17, [x16, #0x5a8]
   73bb8:      	add	x16, x16, #0x5a8
   73bbc:      	br	x17

0000000000073bc0 <_ZN8mtlabar323SubTextLayerInteraction14setLineSpacingEf@plt>:
   73bc0:      	adrp	x16, 0x7c000
   73bc4:      	ldr	x17, [x16, #0x5b0]
   73bc8:      	add	x16, x16, #0x5b0
   73bcc:      	br	x17

0000000000073bd0 <_ZN8mtlabar323SubTextLayerInteraction18getHardLineSpacingEv@plt>:
   73bd0:      	adrp	x16, 0x7c000
   73bd4:      	ldr	x17, [x16, #0x5b8]
   73bd8:      	add	x16, x16, #0x5b8
   73bdc:      	br	x17

0000000000073be0 <_ZN8mtlabar323SubTextLayerInteraction18setHardLineSpacingEf@plt>:
   73be0:      	adrp	x16, 0x7c000
   73be4:      	ldr	x17, [x16, #0x5c0]
   73be8:      	add	x16, x16, #0x5c0
   73bec:      	br	x17

0000000000073bf0 <_ZN8mtlabar323SubTextLayerInteraction13getTextLayoutEv@plt>:
   73bf0:      	adrp	x16, 0x7c000
   73bf4:      	ldr	x17, [x16, #0x5c8]
   73bf8:      	add	x16, x16, #0x5c8
   73bfc:      	br	x17

0000000000073c00 <_ZN8mtlabar323SubTextLayerInteraction13setTextLayoutENS_4text14TextLayoutEnumE@plt>:
   73c00:      	adrp	x16, 0x7c000
   73c04:      	ldr	x17, [x16, #0x5d0]
   73c08:      	add	x16, x16, #0x5d0
   73c0c:      	br	x17

0000000000073c10 <_ZN8mtlabar323SubTextLayerInteraction9getPinyinEv@plt>:
   73c10:      	adrp	x16, 0x7c000
   73c14:      	ldr	x17, [x16, #0x5d8]
   73c18:      	add	x16, x16, #0x5d8
   73c1c:      	br	x17

0000000000073c20 <_ZN8mtlabar323SubTextLayerInteraction9setPinyinEb@plt>:
   73c20:      	adrp	x16, 0x7c000
   73c24:      	ldr	x17, [x16, #0x5e0]
   73c28:      	add	x16, x16, #0x5e0
   73c2c:      	br	x17

0000000000073c30 <_ZN8mtlabar323SubTextLayerInteraction12getCustomTagEv@plt>:
   73c30:      	adrp	x16, 0x7c000
   73c34:      	ldr	x17, [x16, #0x5e8]
   73c38:      	add	x16, x16, #0x5e8
   73c3c:      	br	x17

0000000000073c40 <_ZN8mtlabar323SubTextLayerInteraction12flipTextRectEv@plt>:
   73c40:      	adrp	x16, 0x7c000
   73c44:      	ldr	x17, [x16, #0x5f0]
   73c48:      	add	x16, x16, #0x5f0
   73c4c:      	br	x17

0000000000073c50 <_ZN8mtlabar323SubTextLayerInteraction14getEditingTypeEv@plt>:
   73c50:      	adrp	x16, 0x7c000
   73c54:      	ldr	x17, [x16, #0x5f8]
   73c58:      	add	x16, x16, #0x5f8
   73c5c:      	br	x17

0000000000073c60 <_ZN8mtlabar323SubTextLayerInteraction14setEditingTypeENS_4text11EditingTypeE@plt>:
   73c60:      	adrp	x16, 0x7c000
   73c64:      	ldr	x17, [x16, #0x600]
   73c68:      	add	x16, x16, #0x600
   73c6c:      	br	x17

0000000000073c70 <_ZN8mtlabar323SubTextLayerInteraction17getSubLayerVertexENS_15LayerVertexEnumE@plt>:
   73c70:      	adrp	x16, 0x7c000
   73c74:      	ldr	x17, [x16, #0x608]
   73c78:      	add	x16, x16, #0x608
   73c7c:      	br	x17

0000000000073c80 <_ZN8mtlabar323SubTextLayerInteraction18getTextRectPaddingENS_13LayerEdgeEnumE@plt>:
   73c80:      	adrp	x16, 0x7c000
   73c84:      	ldr	x17, [x16, #0x610]
   73c88:      	add	x16, x16, #0x610
   73c8c:      	br	x17

0000000000073c90 <_ZN8mtlabar323SubTextLayerInteraction16getSequenceStyleEv@plt>:
   73c90:      	adrp	x16, 0x7c000
   73c94:      	ldr	x17, [x16, #0x618]
   73c98:      	add	x16, x16, #0x618
   73c9c:      	br	x17

0000000000073ca0 <_ZN8mtlabar323SubTextLayerInteraction16setSequenceStyleEi@plt>:
   73ca0:      	adrp	x16, 0x7c000
   73ca4:      	ldr	x17, [x16, #0x620]
   73ca8:      	add	x16, x16, #0x620
   73cac:      	br	x17

0000000000073cb0 <_ZN8mtlabar323SubTextLayerInteraction12getIsVisibleEv@plt>:
   73cb0:      	adrp	x16, 0x7c000
   73cb4:      	ldr	x17, [x16, #0x628]
   73cb8:      	add	x16, x16, #0x628
   73cbc:      	br	x17

0000000000073cc0 <_ZN8mtlabar323SubTextLayerInteraction12setIsVisibleEb@plt>:
   73cc0:      	adrp	x16, 0x7c000
   73cc4:      	ldr	x17, [x16, #0x630]
   73cc8:      	add	x16, x16, #0x630
   73ccc:      	br	x17

0000000000073cd0 <_ZN8mtlabar323SubTextLayerInteraction12getIsDisplayEv@plt>:
   73cd0:      	adrp	x16, 0x7c000
   73cd4:      	ldr	x17, [x16, #0x638]
   73cd8:      	add	x16, x16, #0x638
   73cdc:      	br	x17

0000000000073ce0 <_ZN8mtlabar323SubTextLayerInteraction21setTextPathConfigPathEPKc@plt>:
   73ce0:      	adrp	x16, 0x7c000
   73ce4:      	ldr	x17, [x16, #0x640]
   73ce8:      	add	x16, x16, #0x640
   73cec:      	br	x17

0000000000073cf0 <_ZN8mtlabar323SubTextLayerInteraction21getTextPathConfigPathEv@plt>:
   73cf0:      	adrp	x16, 0x7c000
   73cf4:      	ldr	x17, [x16, #0x648]
   73cf8:      	add	x16, x16, #0x648
   73cfc:      	br	x17

0000000000073d00 <_ZN8mtlabar323SubTextLayerInteraction18getLayerConfigPathEv@plt>:
   73d00:      	adrp	x16, 0x7c000
   73d04:      	ldr	x17, [x16, #0x650]
   73d08:      	add	x16, x16, #0x650
   73d0c:      	br	x17

0000000000073d10 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   73d10:      	adrp	x16, 0x7c000
   73d14:      	ldr	x17, [x16, #0x658]
   73d18:      	add	x16, x16, #0x658
   73d1c:      	br	x17

0000000000073d20 <_ZN8mtlabar323SubTextLayerInteraction18setLayerConfigPathENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   73d20:      	adrp	x16, 0x7c000
   73d24:      	ldr	x17, [x16, #0x660]
   73d28:      	add	x16, x16, #0x660
   73d2c:      	br	x17

0000000000073d30 <_ZN8mtlabar323SubTextLayerInteraction16getContainBgOrFgEv@plt>:
   73d30:      	adrp	x16, 0x7c000
   73d34:      	ldr	x17, [x16, #0x668]
   73d38:      	add	x16, x16, #0x668
   73d3c:      	br	x17

0000000000073d40 <_ZN8mtlabar323SubTextLayerInteraction14getContainMaskEv@plt>:
   73d40:      	adrp	x16, 0x7c000
   73d44:      	ldr	x17, [x16, #0x670]
   73d48:      	add	x16, x16, #0x670
   73d4c:      	br	x17

0000000000073d50 <_ZN8mtlabar323SubTextLayerInteraction24getTextImageLocateMethodEv@plt>:
   73d50:      	adrp	x16, 0x7c000
   73d54:      	ldr	x17, [x16, #0x678]
   73d58:      	add	x16, x16, #0x678
   73d5c:      	br	x17

0000000000073d60 <_ZN8mtlabar323SubTextLayerInteraction24setTextImageLocateMethodENS_4text21TextImageLocateMethodE@plt>:
   73d60:      	adrp	x16, 0x7c000
   73d64:      	ldr	x17, [x16, #0x680]
   73d68:      	add	x16, x16, #0x680
   73d6c:      	br	x17

0000000000073d70 <_ZN8mtlabar323SubTextLayerInteraction22getStrokeConfigurationEv@plt>:
   73d70:      	adrp	x16, 0x7c000
   73d74:      	ldr	x17, [x16, #0x688]
   73d78:      	add	x16, x16, #0x688
   73d7c:      	br	x17

0000000000073d80 <_ZN8mtlabar323SubTextLayerInteraction21getMultiStrokeAtIndexEi@plt>:
   73d80:      	adrp	x16, 0x7c000
   73d84:      	ldr	x17, [x16, #0x690]
   73d88:      	add	x16, x16, #0x690
   73d8c:      	br	x17

0000000000073d90 <_ZN8mtlabar323SubTextLayerInteraction18getMultiStrokeSizeEv@plt>:
   73d90:      	adrp	x16, 0x7c000
   73d94:      	ldr	x17, [x16, #0x698]
   73d98:      	add	x16, x16, #0x698
   73d9c:      	br	x17

0000000000073da0 <_ZN8mtlabar323SubTextLayerInteraction17resizeMultiStrokeEi@plt>:
   73da0:      	adrp	x16, 0x7c000
   73da4:      	ldr	x17, [x16, #0x6a0]
   73da8:      	add	x16, x16, #0x6a0
   73dac:      	br	x17

0000000000073db0 <_ZN8mtlabar323SubTextLayerInteraction22getShadowConfigurationEv@plt>:
   73db0:      	adrp	x16, 0x7c000
   73db4:      	ldr	x17, [x16, #0x6a8]
   73db8:      	add	x16, x16, #0x6a8
   73dbc:      	br	x17

0000000000073dc0 <_ZN8mtlabar323SubTextLayerInteraction31getBackgroundColorConfigurationEv@plt>:
   73dc0:      	adrp	x16, 0x7c000
   73dc4:      	ldr	x17, [x16, #0x6b0]
   73dc8:      	add	x16, x16, #0x6b0
   73dcc:      	br	x17

0000000000073dd0 <_ZN8mtlabar323SubTextLayerInteraction20getGlowConfigurationEv@plt>:
   73dd0:      	adrp	x16, 0x7c000
   73dd4:      	ldr	x17, [x16, #0x6b8]
   73dd8:      	add	x16, x16, #0x6b8
   73ddc:      	br	x17

0000000000073de0 <_ZN8mtlabar323SubTextLayerInteraction22getBubbleConfigurationEv@plt>:
   73de0:      	adrp	x16, 0x7c000
   73de4:      	ldr	x17, [x16, #0x6c0]
   73de8:      	add	x16, x16, #0x6c0
   73dec:      	br	x17

0000000000073df0 <_ZN8mtlabar323SubTextLayerInteraction20getCharSVGBackgroundEv@plt>:
   73df0:      	adrp	x16, 0x7c000
   73df4:      	ldr	x17, [x16, #0x6c8]
   73df8:      	add	x16, x16, #0x6c8
   73dfc:      	br	x17

0000000000073e00 <_ZN8mtlabar323SubTextLayerInteraction28getTextEditableConfigurationEv@plt>:
   73e00:      	adrp	x16, 0x7c000
   73e04:      	ldr	x17, [x16, #0x6d0]
   73e08:      	add	x16, x16, #0x6d0
   73e0c:      	br	x17

0000000000073e10 <_ZN8mtlabar323SubTextLayerInteraction28getTextGradientConfigurationEv@plt>:
   73e10:      	adrp	x16, 0x7c000
   73e14:      	ldr	x17, [x16, #0x6d8]
   73e18:      	add	x16, x16, #0x6d8
   73e1c:      	br	x17

0000000000073e20 <_ZN8mtlabar323SubTextLayerInteraction29getIconSequenceStyleInterfaceEv@plt>:
   73e20:      	adrp	x16, 0x7c000
   73e24:      	ldr	x17, [x16, #0x6e0]
   73e28:      	add	x16, x16, #0x6e0
   73e2c:      	br	x17

0000000000073e30 <_ZN8mtlabar323SubTextLayerInteraction24getTextPathConfigurationEv@plt>:
   73e30:      	adrp	x16, 0x7c000
   73e34:      	ldr	x17, [x16, #0x6e8]
   73e38:      	add	x16, x16, #0x6e8
   73e3c:      	br	x17

0000000000073e40 <_ZN8mtlabar323SubTextLayerInteraction30getSelectionHighlightInterfaceEm@plt>:
   73e40:      	adrp	x16, 0x7c000
   73e44:      	ldr	x17, [x16, #0x6f0]
   73e48:      	add	x16, x16, #0x6f0
   73e4c:      	br	x17

0000000000073e50 <_ZN8mtlabar323SubTextLayerInteraction25getSelectionHighlightSizeEv@plt>:
   73e50:      	adrp	x16, 0x7c000
   73e54:      	ldr	x17, [x16, #0x6f8]
   73e58:      	add	x16, x16, #0x6f8
   73e5c:      	br	x17

0000000000073e60 <_ZN8mtlabar323SubTextLayerInteraction25resizeSelectionHighlightsEm@plt>:
   73e60:      	adrp	x16, 0x7c000
   73e64:      	ldr	x17, [x16, #0x700]
   73e68:      	add	x16, x16, #0x700
   73e6c:      	br	x17

0000000000073e70 <_ZN8mtlabar323SubTextLayerInteraction30getSelectionAnimationInterfaceEm@plt>:
   73e70:      	adrp	x16, 0x7c000
   73e74:      	ldr	x17, [x16, #0x708]
   73e78:      	add	x16, x16, #0x708
   73e7c:      	br	x17

0000000000073e80 <_ZN8mtlabar323SubTextLayerInteraction25getSelectionAnimationSizeEv@plt>:
   73e80:      	adrp	x16, 0x7c000
   73e84:      	ldr	x17, [x16, #0x710]
   73e88:      	add	x16, x16, #0x710
   73e8c:      	br	x17

0000000000073e90 <_ZN8mtlabar323SubTextLayerInteraction25resizeSelectionAnimationsEm@plt>:
   73e90:      	adrp	x16, 0x7c000
   73e94:      	ldr	x17, [x16, #0x718]
   73e98:      	add	x16, x16, #0x718
   73e9c:      	br	x17

0000000000073ea0 <_ZN8mtlabar323SubTextLayerInteraction25getSelectionNoteInterfaceEm@plt>:
   73ea0:      	adrp	x16, 0x7c000
   73ea4:      	ldr	x17, [x16, #0x720]
   73ea8:      	add	x16, x16, #0x720
   73eac:      	br	x17

0000000000073eb0 <_ZN8mtlabar323SubTextLayerInteraction20getSelectionNoteSizeEv@plt>:
   73eb0:      	adrp	x16, 0x7c000
   73eb4:      	ldr	x17, [x16, #0x728]
   73eb8:      	add	x16, x16, #0x728
   73ebc:      	br	x17

0000000000073ec0 <_ZN8mtlabar323SubTextLayerInteraction20resizeSelectionNotesEm@plt>:
   73ec0:      	adrp	x16, 0x7c000
   73ec4:      	ldr	x17, [x16, #0x730]
   73ec8:      	add	x16, x16, #0x730
   73ecc:      	br	x17

0000000000073ed0 <_ZN8mtlabar323SubTextLayerInteraction10getTextASREv@plt>:
   73ed0:      	adrp	x16, 0x7c000
   73ed4:      	ldr	x17, [x16, #0x738]
   73ed8:      	add	x16, x16, #0x738
   73edc:      	br	x17

0000000000073ee0 <_ZN8mtlabar323SubTextLayerInteraction22getWarpConfigInterfaceEv@plt>:
   73ee0:      	adrp	x16, 0x7c000
   73ee4:      	ldr	x17, [x16, #0x740]
   73ee8:      	add	x16, x16, #0x740
   73eec:      	br	x17

0000000000073ef0 <_ZN8mtlabar323SubTextLayerInteraction26getCharBackgroundInterfaceEv@plt>:
   73ef0:      	adrp	x16, 0x7c000
   73ef4:      	ldr	x17, [x16, #0x748]
   73ef8:      	add	x16, x16, #0x748
   73efc:      	br	x17

0000000000073f00 <_ZN8mtlabar323SubTextLayerInteraction26getLineLayoutConfigAtIndexEm@plt>:
   73f00:      	adrp	x16, 0x7c000
   73f04:      	ldr	x17, [x16, #0x750]
   73f08:      	add	x16, x16, #0x750
   73f0c:      	br	x17

0000000000073f10 <_ZN8mtlabar323SubTextLayerInteraction24getLineLayoutConfigCountEv@plt>:
   73f10:      	adrp	x16, 0x7c000
   73f14:      	ldr	x17, [x16, #0x758]
   73f18:      	add	x16, x16, #0x758
   73f1c:      	br	x17

0000000000073f20 <_ZN8mtlabar320LayerTextInteraction19setGlobalColorValueERKNS_5ColorE@plt>:
   73f20:      	adrp	x16, 0x7c000
   73f24:      	ldr	x17, [x16, #0x760]
   73f28:      	add	x16, x16, #0x760
   73f2c:      	br	x17

0000000000073f30 <_ZN8mtlabar320LayerTextInteraction19getGlobalColorValueEv@plt>:
   73f30:      	adrp	x16, 0x7c000
   73f34:      	ldr	x17, [x16, #0x768]
   73f38:      	add	x16, x16, #0x768
   73f3c:      	br	x17

0000000000073f40 <_ZN8mtlabar320LayerTextInteraction20setEnableGlobalColorEb@plt>:
   73f40:      	adrp	x16, 0x7c000
   73f44:      	ldr	x17, [x16, #0x770]
   73f48:      	add	x16, x16, #0x770
   73f4c:      	br	x17

0000000000073f50 <_ZN8mtlabar320LayerTextInteraction20getEnableGlobalColorEv@plt>:
   73f50:      	adrp	x16, 0x7c000
   73f54:      	ldr	x17, [x16, #0x778]
   73f58:      	add	x16, x16, #0x778
   73f5c:      	br	x17

0000000000073f60 <_ZN8mtlabar320LayerTextInteraction18getTextInTimestampEv@plt>:
   73f60:      	adrp	x16, 0x7c000
   73f64:      	ldr	x17, [x16, #0x780]
   73f68:      	add	x16, x16, #0x780
   73f6c:      	br	x17

0000000000073f70 <_ZN8mtlabar320LayerTextInteraction13setEnableFlipEb@plt>:
   73f70:      	adrp	x16, 0x7c000
   73f74:      	ldr	x17, [x16, #0x788]
   73f78:      	add	x16, x16, #0x788
   73f7c:      	br	x17

0000000000073f80 <_ZN8mtlabar320LayerTextInteraction13getEnableFlipEv@plt>:
   73f80:      	adrp	x16, 0x7c000
   73f84:      	ldr	x17, [x16, #0x790]
   73f88:      	add	x16, x16, #0x790
   73f8c:      	br	x17

0000000000073f90 <_ZN8mtlabar320LayerTextInteraction15getSubTextLayerEm@plt>:
   73f90:      	adrp	x16, 0x7c000
   73f94:      	ldr	x17, [x16, #0x798]
   73f98:      	add	x16, x16, #0x798
   73f9c:      	br	x17

0000000000073fa0 <_ZN8mtlabar320LayerTextInteraction19getSubTextLayerSizeEv@plt>:
   73fa0:      	adrp	x16, 0x7c000
   73fa4:      	ldr	x17, [x16, #0x7a0]
   73fa8:      	add	x16, x16, #0x7a0
   73fac:      	br	x17

0000000000073fb0 <_ZN8mtlabar320LayerTextInteraction18getWatermarkConfigEv@plt>:
   73fb0:      	adrp	x16, 0x7c000
   73fb4:      	ldr	x17, [x16, #0x7a8]
   73fb8:      	add	x16, x16, #0x7a8
   73fbc:      	br	x17

0000000000073fc0 <_ZN8mtlabar320LayerTextInteraction18setWatermarkConfigERKNS_15WatermarkConfigE@plt>:
   73fc0:      	adrp	x16, 0x7c000
   73fc4:      	ldr	x17, [x16, #0x7b0]
   73fc8:      	add	x16, x16, #0x7b0
   73fcc:      	br	x17

0000000000073fd0 <_ZN8mtlabar320LayerTextInteraction13setEnableEditEb@plt>:
   73fd0:      	adrp	x16, 0x7c000
   73fd4:      	ldr	x17, [x16, #0x7b8]
   73fd8:      	add	x16, x16, #0x7b8
   73fdc:      	br	x17

0000000000073fe0 <_ZN8mtlabar320LayerTextInteraction13getEnableEditEv@plt>:
   73fe0:      	adrp	x16, 0x7c000
   73fe4:      	ldr	x17, [x16, #0x7c0]
   73fe8:      	add	x16, x16, #0x7c0
   73fec:      	br	x17

0000000000073ff0 <_ZN8mtlabar320LayerTextInteraction16setEditableIndexEi@plt>:
   73ff0:      	adrp	x16, 0x7c000
   73ff4:      	ldr	x17, [x16, #0x7c8]
   73ff8:      	add	x16, x16, #0x7c8
   73ffc:      	br	x17

0000000000074000 <_ZN8mtlabar320LayerTextInteraction16getEditableIndexEv@plt>:
   74000:      	adrp	x16, 0x7c000
   74004:      	ldr	x17, [x16, #0x7d0]
   74008:      	add	x16, x16, #0x7d0
   7400c:      	br	x17

0000000000074010 <_ZN8mtlabar320LayerTextInteraction25getTextInactiveTextConfigEv@plt>:
   74010:      	adrp	x16, 0x7c000
   74014:      	ldr	x17, [x16, #0x7d8]
   74018:      	add	x16, x16, #0x7d8
   7401c:      	br	x17

0000000000074020 <_ZN8mtlabar320LayerTextInteraction23setCompositionTextPathsERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   74020:      	adrp	x16, 0x7c000
   74024:      	ldr	x17, [x16, #0x7e0]
   74028:      	add	x16, x16, #0x7e0
   7402c:      	br	x17

0000000000074030 <_ZN8mtlabar320LayerTextInteraction18getCompositionTypeEv@plt>:
   74030:      	adrp	x16, 0x7c000
   74034:      	ldr	x17, [x16, #0x7e8]
   74038:      	add	x16, x16, #0x7e8
   7403c:      	br	x17

0000000000074040 <_ZN8mtlabar320LayerTextInteraction19setEnableTextMirrorEb@plt>:
   74040:      	adrp	x16, 0x7c000
   74044:      	ldr	x17, [x16, #0x7f0]
   74048:      	add	x16, x16, #0x7f0
   7404c:      	br	x17

0000000000074050 <_ZN8mtlabar320LayerTextInteraction19getEnableTextMirrorEv@plt>:
   74050:      	adrp	x16, 0x7c000
   74054:      	ldr	x17, [x16, #0x7f8]
   74058:      	add	x16, x16, #0x7f8
   7405c:      	br	x17

0000000000074060 <_ZN8mtlabar321LayerChartInteraction7setDataENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS1_6vectorIfNS5_IfEEEE@plt>:
   74060:      	adrp	x16, 0x7c000
   74064:      	ldr	x17, [x16, #0x800]
   74068:      	add	x16, x16, #0x800
   7406c:      	br	x17

0000000000074070 <_ZN8mtlabar321LayerChartInteraction7getDataENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   74070:      	adrp	x16, 0x7c000
   74074:      	ldr	x17, [x16, #0x808]
   74078:      	add	x16, x16, #0x808
   7407c:      	br	x17

0000000000074080 <_ZN8mtlabar321LayerChartInteraction10getKeyListEv@plt>:
   74080:      	adrp	x16, 0x7c000
   74084:      	ldr	x17, [x16, #0x810]
   74088:      	add	x16, x16, #0x810
   7408c:      	br	x17

0000000000074090 <_ZN8mtlabar321LayerChartInteraction15setAnimateSpeedEf@plt>:
   74090:      	adrp	x16, 0x7c000
   74094:      	ldr	x17, [x16, #0x818]
   74098:      	add	x16, x16, #0x818
   7409c:      	br	x17

00000000000740a0 <_ZN8mtlabar321LayerChartInteraction15getAnimateSpeedEv@plt>:
   740a0:      	adrp	x16, 0x7c000
   740a4:      	ldr	x17, [x16, #0x820]
   740a8:      	add	x16, x16, #0x820
   740ac:      	br	x17

00000000000740b0 <_ZN8mtlabar329LayerTextBGTextureInteraction14setEnableColorEb@plt>:
   740b0:      	adrp	x16, 0x7c000
   740b4:      	ldr	x17, [x16, #0x828]
   740b8:      	add	x16, x16, #0x828
   740bc:      	br	x17

00000000000740c0 <_ZN8mtlabar329LayerTextBGTextureInteraction14getEnableColorEv@plt>:
   740c0:      	adrp	x16, 0x7c000
   740c4:      	ldr	x17, [x16, #0x830]
   740c8:      	add	x16, x16, #0x830
   740cc:      	br	x17

00000000000740d0 <_ZN8mtlabar329LayerTextBGTextureInteraction8setColorERKNS_5ColorE@plt>:
   740d0:      	adrp	x16, 0x7c000
   740d4:      	ldr	x17, [x16, #0x838]
   740d8:      	add	x16, x16, #0x838
   740dc:      	br	x17

00000000000740e0 <_ZN8mtlabar329LayerTextBGTextureInteraction8getColorEv@plt>:
   740e0:      	adrp	x16, 0x7c000
   740e4:      	ldr	x17, [x16, #0x840]
   740e8:      	add	x16, x16, #0x840
   740ec:      	br	x17

00000000000740f0 <_ZN8mtlabar330LayerObjectTrackingInteraction23setEnableObjectTrackingEb@plt>:
   740f0:      	adrp	x16, 0x7c000
   740f4:      	ldr	x17, [x16, #0x848]
   740f8:      	add	x16, x16, #0x848
   740fc:      	br	x17

0000000000074100 <_ZN8mtlabar330LayerObjectTrackingInteraction23getEnableObjectTrackingEv@plt>:
   74100:      	adrp	x16, 0x7c000
   74104:      	ldr	x17, [x16, #0x850]
   74108:      	add	x16, x16, #0x850
   7410c:      	br	x17

0000000000074110 <_ZN8mtlabar330LayerObjectTrackingInteraction18initObjectTrackingERKNS_18ObjectTrackingDataE@plt>:
   74110:      	adrp	x16, 0x7c000
   74114:      	ldr	x17, [x16, #0x858]
   74118:      	add	x16, x16, #0x858
   7411c:      	br	x17

0000000000074120 <_ZN8mtlabar330LayerObjectTrackingInteraction25getInitObjectTrackingDataEv@plt>:
   74120:      	adrp	x16, 0x7c000
   74124:      	ldr	x17, [x16, #0x860]
   74128:      	add	x16, x16, #0x860
   7412c:      	br	x17

0000000000074130 <_ZN8mtlabar330LayerObjectTrackingInteraction21setObjectTrackingDataERKNS_18ObjectTrackingDataE@plt>:
   74130:      	adrp	x16, 0x7c000
   74134:      	ldr	x17, [x16, #0x868]
   74138:      	add	x16, x16, #0x868
   7413c:      	br	x17

0000000000074140 <_ZN8mtlabar330LayerObjectTrackingInteraction26getIsObjectTrackingRunningEv@plt>:
   74140:      	adrp	x16, 0x7c000
   74144:      	ldr	x17, [x16, #0x870]
   74148:      	add	x16, x16, #0x870
   7414c:      	br	x17

0000000000074150 <_ZN8mtlabar330LayerObjectTrackingInteraction29getIsObjectTrackingDataUsefulEv@plt>:
   74150:      	adrp	x16, 0x7c000
   74154:      	ldr	x17, [x16, #0x878]
   74158:      	add	x16, x16, #0x878
   7415c:      	br	x17

0000000000074160 <_ZN8mtlabar330LayerObjectTrackingInteraction27setObjectTrackingNeedHiddenEb@plt>:
   74160:      	adrp	x16, 0x7c000
   74164:      	ldr	x17, [x16, #0x880]
   74168:      	add	x16, x16, #0x880
   7416c:      	br	x17

0000000000074170 <_ZN8mtlabar330LayerObjectTrackingInteraction27getObjectTrackingNeedHiddenEv@plt>:
   74170:      	adrp	x16, 0x7c000
   74174:      	ldr	x17, [x16, #0x888]
   74178:      	add	x16, x16, #0x888
   7417c:      	br	x17

0000000000074180 <_ZN8mtlabar330LayerObjectTrackingInteraction26setFirstObjectTrackingDataERKNS_18ObjectTrackingDataE@plt>:
   74180:      	adrp	x16, 0x7c000
   74184:      	ldr	x17, [x16, #0x890]
   74188:      	add	x16, x16, #0x890
   7418c:      	br	x17

0000000000074190 <_ZN8mtlabar330LayerObjectTrackingInteraction25setLastObjectTrackingDataERKNS_18ObjectTrackingDataE@plt>:
   74190:      	adrp	x16, 0x7c000
   74194:      	ldr	x17, [x16, #0x898]
   74198:      	add	x16, x16, #0x898
   7419c:      	br	x17

00000000000741a0 <_ZN8mtlabar330LayerObjectTrackingInteraction23setCurrentTimeLineStateERKNS_27ObjectTrackingTimeLineStateE@plt>:
   741a0:      	adrp	x16, 0x7c000
   741a4:      	ldr	x17, [x16, #0x8a0]
   741a8:      	add	x16, x16, #0x8a0
   741ac:      	br	x17

00000000000741b0 <_ZN8mtlabar328LayerFaceTrackingInteraction21setEnableFaceTrackingEb@plt>:
   741b0:      	adrp	x16, 0x7c000
   741b4:      	ldr	x17, [x16, #0x8a8]
   741b8:      	add	x16, x16, #0x8a8
   741bc:      	br	x17

00000000000741c0 <_ZN8mtlabar328LayerFaceTrackingInteraction21getEnableFaceTrackingEv@plt>:
   741c0:      	adrp	x16, 0x7c000
   741c4:      	ldr	x17, [x16, #0x8b0]
   741c8:      	add	x16, x16, #0x8b0
   741cc:      	br	x17

00000000000741d0 <_ZN8mtlabar328LayerFaceTrackingInteraction21setFaceTrackingFaceFREl@plt>:
   741d0:      	adrp	x16, 0x7c000
   741d4:      	ldr	x17, [x16, #0x8b8]
   741d8:      	add	x16, x16, #0x8b8
   741dc:      	br	x17

00000000000741e0 <_ZN8mtlabar328LayerFaceTrackingInteraction21getFaceTrackingFaceFREv@plt>:
   741e0:      	adrp	x16, 0x7c000
   741e4:      	ldr	x17, [x16, #0x8c0]
   741e8:      	add	x16, x16, #0x8c0
   741ec:      	br	x17

00000000000741f0 <_ZN8mtlabar328LayerFaceTrackingInteraction24getIsFaceTrackingRunningEv@plt>:
   741f0:      	adrp	x16, 0x7c000
   741f4:      	ldr	x17, [x16, #0x8c8]
   741f8:      	add	x16, x16, #0x8c8
   741fc:      	br	x17

0000000000074200 <_ZN8mtlabar328LayerFaceTrackingInteraction23setFaceTrackingFaceDataEPv@plt>:
   74200:      	adrp	x16, 0x7c000
   74204:      	ldr	x17, [x16, #0x8d0]
   74208:      	add	x16, x16, #0x8d0
   7420c:      	br	x17

0000000000074210 <_ZN8mtlabar328LayerFaceTrackingInteraction25setFaceTrackingNeedHiddenEb@plt>:
   74210:      	adrp	x16, 0x7c000
   74214:      	ldr	x17, [x16, #0x8d8]
   74218:      	add	x16, x16, #0x8d8
   7421c:      	br	x17

0000000000074220 <_ZN8mtlabar328LayerFaceTrackingInteraction25getFaceTrackingNeedHiddenEv@plt>:
   74220:      	adrp	x16, 0x7c000
   74224:      	ldr	x17, [x16, #0x8e0]
   74228:      	add	x16, x16, #0x8e0
   7422c:      	br	x17

0000000000074230 <_ZN8mtlabar328LayerFaceTrackingInteraction31setFaceTrackingFaceDataWithVLDPEP18vldp_data_protocolii@plt>:
   74230:      	adrp	x16, 0x7c000
   74234:      	ldr	x17, [x16, #0x8e8]
   74238:      	add	x16, x16, #0x8e8
   7423c:      	br	x17

0000000000074240 <_ZN8mtlabar328LayerFaceTrackingInteraction23getFaceTrackingUseMouthEv@plt>:
   74240:      	adrp	x16, 0x7c000
   74244:      	ldr	x17, [x16, #0x8f0]
   74248:      	add	x16, x16, #0x8f0
   7424c:      	br	x17

0000000000074250 <_ZN8mtlabar328LayerFaceTrackingInteraction23setFaceTrackingUseMouthEb@plt>:
   74250:      	adrp	x16, 0x7c000
   74254:      	ldr	x17, [x16, #0x8f8]
   74258:      	add	x16, x16, #0x8f8
   7425c:      	br	x17

0000000000074260 <_ZN8mtlabar320LayerMaskInteraction5validEv@plt>:
   74260:      	adrp	x16, 0x7c000
   74264:      	ldr	x17, [x16, #0x900]
   74268:      	add	x16, x16, #0x900
   7426c:      	br	x17

0000000000074270 <_ZN8mtlabar320LayerMaskInteraction13setConfigPathEPKc@plt>:
   74270:      	adrp	x16, 0x7c000
   74274:      	ldr	x17, [x16, #0x908]
   74278:      	add	x16, x16, #0x908
   7427c:      	br	x17

0000000000074280 <_ZN8mtlabar320LayerMaskInteraction13getConfigPathEv@plt>:
   74280:      	adrp	x16, 0x7c000
   74284:      	ldr	x17, [x16, #0x910]
   74288:      	add	x16, x16, #0x910
   7428c:      	br	x17

0000000000074290 <_ZN8mtlabar320LayerMaskInteraction10setReverseEb@plt>:
   74290:      	adrp	x16, 0x7c000
   74294:      	ldr	x17, [x16, #0x918]
   74298:      	add	x16, x16, #0x918
   7429c:      	br	x17

00000000000742a0 <_ZN8mtlabar320LayerMaskInteraction10getReverseEv@plt>:
   742a0:      	adrp	x16, 0x7c000
   742a4:      	ldr	x17, [x16, #0x920]
   742a8:      	add	x16, x16, #0x920
   742ac:      	br	x17

00000000000742b0 <_ZN8mtlabar320LayerMaskInteraction13setBlurDegreeEf@plt>:
   742b0:      	adrp	x16, 0x7c000
   742b4:      	ldr	x17, [x16, #0x928]
   742b8:      	add	x16, x16, #0x928
   742bc:      	br	x17

00000000000742c0 <_ZN8mtlabar320LayerMaskInteraction13getBlurDegreeEv@plt>:
   742c0:      	adrp	x16, 0x7c000
   742c4:      	ldr	x17, [x16, #0x930]
   742c8:      	add	x16, x16, #0x930
   742cc:      	br	x17

00000000000742d0 <_ZN8mtlabar323LayerStickerInteraction20setImportStickerDataEPKNS_27MvImportStickerConfigStructE@plt>:
   742d0:      	adrp	x16, 0x7c000
   742d4:      	ldr	x17, [x16, #0x938]
   742d8:      	add	x16, x16, #0x938
   742dc:      	br	x17

00000000000742e0 <_ZNK8mtlabar323LayerStickerInteraction24getStickerPlayDurationMsEv@plt>:
   742e0:      	adrp	x16, 0x7c000
   742e4:      	ldr	x17, [x16, #0x940]
   742e8:      	add	x16, x16, #0x940
   742ec:      	br	x17

00000000000742f0 <_ZN8mtlabar323LayerStickerInteraction24setStickerPlayDurationMsEf@plt>:
   742f0:      	adrp	x16, 0x7c000
   742f4:      	ldr	x17, [x16, #0x948]
   742f8:      	add	x16, x16, #0x948
   742fc:      	br	x17

0000000000074300 <_ZN8mtlabar323LayerStickerInteraction13setStickerHSLEfff@plt>:
   74300:      	adrp	x16, 0x7c000
   74304:      	ldr	x17, [x16, #0x950]
   74308:      	add	x16, x16, #0x950
   7430c:      	br	x17

0000000000074310 <_ZNK8mtlabar323LayerStickerInteraction13getStickerHSLEPfS1_S1_@plt>:
   74310:      	adrp	x16, 0x7c000
   74314:      	ldr	x17, [x16, #0x958]
   74318:      	add	x16, x16, #0x958
   7431c:      	br	x17

0000000000074320 <_ZN8mtlabar323LayerStickerInteraction16enableStickerHSLEb@plt>:
   74320:      	adrp	x16, 0x7c000
   74324:      	ldr	x17, [x16, #0x960]
   74328:      	add	x16, x16, #0x960
   7432c:      	br	x17

0000000000074330 <_ZNK8mtlabar323LayerStickerInteraction19isStickerHSLEnabledEv@plt>:
   74330:      	adrp	x16, 0x7c000
   74334:      	ldr	x17, [x16, #0x968]
   74338:      	add	x16, x16, #0x968
   7433c:      	br	x17

0000000000074340 <_ZNK8mtlabar323LayerStickerInteraction19getStickerPlaySpeedEv@plt>:
   74340:      	adrp	x16, 0x7c000
   74344:      	ldr	x17, [x16, #0x970]
   74348:      	add	x16, x16, #0x970
   7434c:      	br	x17

0000000000074350 <_ZN8mtlabar323LayerStickerInteraction19setStickerPlaySpeedEf@plt>:
   74350:      	adrp	x16, 0x7c000
   74354:      	ldr	x17, [x16, #0x978]
   74358:      	add	x16, x16, #0x978
   7435c:      	br	x17

0000000000074360 <_ZN8mtlabar325LayerAnimationInteraction5validEv@plt>:
   74360:      	adrp	x16, 0x7c000
   74364:      	ldr	x17, [x16, #0x980]
   74368:      	add	x16, x16, #0x980
   7436c:      	br	x17

0000000000074370 <_ZN8mtlabar325LayerAnimationInteraction13setConfigPathEPKc@plt>:
   74370:      	adrp	x16, 0x7c000
   74374:      	ldr	x17, [x16, #0x988]
   74378:      	add	x16, x16, #0x988
   7437c:      	br	x17

0000000000074380 <_ZN8mtlabar325LayerAnimationInteraction13getConfigPathEv@plt>:
   74380:      	adrp	x16, 0x7c000
   74384:      	ldr	x17, [x16, #0x990]
   74388:      	add	x16, x16, #0x990
   7438c:      	br	x17

0000000000074390 <_ZN8mtlabar325LayerAnimationInteraction12setTotalTimeEf@plt>:
   74390:      	adrp	x16, 0x7c000
   74394:      	ldr	x17, [x16, #0x998]
   74398:      	add	x16, x16, #0x998
   7439c:      	br	x17

00000000000743a0 <_ZN8mtlabar325LayerAnimationInteraction12getTotalTimeEv@plt>:
   743a0:      	adrp	x16, 0x7c000
   743a4:      	ldr	x17, [x16, #0x9a0]
   743a8:      	add	x16, x16, #0x9a0
   743ac:      	br	x17

00000000000743b0 <_ZN8mtlabar325LayerAnimationInteraction11setOnceTimeEf@plt>:
   743b0:      	adrp	x16, 0x7c000
   743b4:      	ldr	x17, [x16, #0x9a8]
   743b8:      	add	x16, x16, #0x9a8
   743bc:      	br	x17

00000000000743c0 <_ZN8mtlabar325LayerAnimationInteraction11getOnceTimeEv@plt>:
   743c0:      	adrp	x16, 0x7c000
   743c4:      	ldr	x17, [x16, #0x9b0]
   743c8:      	add	x16, x16, #0x9b0
   743cc:      	br	x17

00000000000743d0 <_ZN8mtlabar325LayerAnimationInteraction8setSpeedEf@plt>:
   743d0:      	adrp	x16, 0x7c000
   743d4:      	ldr	x17, [x16, #0x9b8]
   743d8:      	add	x16, x16, #0x9b8
   743dc:      	br	x17

00000000000743e0 <_ZN8mtlabar325LayerAnimationInteraction8getSpeedEv@plt>:
   743e0:      	adrp	x16, 0x7c000
   743e4:      	ldr	x17, [x16, #0x9c0]
   743e8:      	add	x16, x16, #0x9c0
   743ec:      	br	x17

00000000000743f0 <_ZN8mtlabar325LayerAnimationInteraction17setBeginTimestampEf@plt>:
   743f0:      	adrp	x16, 0x7c000
   743f4:      	ldr	x17, [x16, #0x9c8]
   743f8:      	add	x16, x16, #0x9c8
   743fc:      	br	x17

0000000000074400 <_ZN8mtlabar325LayerAnimationInteraction17getBeginTimestampEv@plt>:
   74400:      	adrp	x16, 0x7c000
   74404:      	ldr	x17, [x16, #0x9d0]
   74408:      	add	x16, x16, #0x9d0
   7440c:      	br	x17

0000000000074410 <_ZN8mtlabar325LayerAnimationInteraction15setEndTimestampEf@plt>:
   74410:      	adrp	x16, 0x7c000
   74414:      	ldr	x17, [x16, #0x9d8]
   74418:      	add	x16, x16, #0x9d8
   7441c:      	br	x17

0000000000074420 <_ZN8mtlabar325LayerAnimationInteraction15getEndTimestampEv@plt>:
   74420:      	adrp	x16, 0x7c000
   74424:      	ldr	x17, [x16, #0x9e0]
   74428:      	add	x16, x16, #0x9e0
   7442c:      	br	x17

0000000000074430 <_ZN8mtlabar325LayerAnimationInteraction19disableEndTimestampEb@plt>:
   74430:      	adrp	x16, 0x7c000
   74434:      	ldr	x17, [x16, #0x9e8]
   74438:      	add	x16, x16, #0x9e8
   7443c:      	br	x17

0000000000074440 <_ZN8mtlabar325LayerAnimationInteraction22isEndTimestampDisabledEv@plt>:
   74440:      	adrp	x16, 0x7c000
   74444:      	ldr	x17, [x16, #0x9f0]
   74448:      	add	x16, x16, #0x9f0
   7444c:      	br	x17

0000000000074450 <_ZN8mtlabar325LayerAnimationInteraction11setJsonPathEPKc@plt>:
   74450:      	adrp	x16, 0x7c000
   74454:      	ldr	x17, [x16, #0x9f8]
   74458:      	add	x16, x16, #0x9f8
   7445c:      	br	x17

0000000000074460 <_ZN8mtlabar325LayerAnimationInteraction11getJsonPathEv@plt>:
   74460:      	adrp	x16, 0x7c000
   74464:      	ldr	x17, [x16, #0xa00]
   74468:      	add	x16, x16, #0xa00
   7446c:      	br	x17

0000000000074470 <_ZN8mtlabar325LayerAnimationInteraction14setRepeatCountEi@plt>:
   74470:      	adrp	x16, 0x7c000
   74474:      	ldr	x17, [x16, #0xa08]
   74478:      	add	x16, x16, #0xa08
   7447c:      	br	x17

0000000000074480 <_ZN8mtlabar325LayerAnimationInteraction14getRepeatCountEv@plt>:
   74480:      	adrp	x16, 0x7c000
   74484:      	ldr	x17, [x16, #0xa10]
   74488:      	add	x16, x16, #0xa10
   7448c:      	br	x17

0000000000074490 <_ZN8mtlabar325LayerAnimationInteraction16setImageWarpModeEi@plt>:
   74490:      	adrp	x16, 0x7c000
   74494:      	ldr	x17, [x16, #0xa18]
   74498:      	add	x16, x16, #0xa18
   7449c:      	br	x17

00000000000744a0 <_ZN8mtlabar325LayerAnimationInteraction16getImageWarpModeEv@plt>:
   744a0:      	adrp	x16, 0x7c000
   744a4:      	ldr	x17, [x16, #0xa20]
   744a8:      	add	x16, x16, #0xa20
   744ac:      	br	x17

00000000000744b0 <_ZN8mtlabar325LayerAnimationInteraction12setLoopStateEb@plt>:
   744b0:      	adrp	x16, 0x7c000
   744b4:      	ldr	x17, [x16, #0xa28]
   744b8:      	add	x16, x16, #0xa28
   744bc:      	br	x17

00000000000744c0 <_ZN8mtlabar325LayerAnimationInteraction12getLoopStateEv@plt>:
   744c0:      	adrp	x16, 0x7c000
   744c4:      	ldr	x17, [x16, #0xa30]
   744c8:      	add	x16, x16, #0xa30
   744cc:      	br	x17

00000000000744d0 <_ZN8mtlabar325LayerAnimationInteraction18setApplySubTextBoxEi@plt>:
   744d0:      	adrp	x16, 0x7c000
   744d4:      	ldr	x17, [x16, #0xa38]
   744d8:      	add	x16, x16, #0xa38
   744dc:      	br	x17

00000000000744e0 <_ZN8mtlabar325LayerAnimationInteraction21isFullScreenAnimationEv@plt>:
   744e0:      	adrp	x16, 0x7c000
   744e4:      	ldr	x17, [x16, #0xa40]
   744e8:      	add	x16, x16, #0xa40
   744ec:      	br	x17

00000000000744f0 <_ZN8mtlabar325LayerAnimationInteraction18setShowStaticFrameEb@plt>:
   744f0:      	adrp	x16, 0x7c000
   744f4:      	ldr	x17, [x16, #0xa48]
   744f8:      	add	x16, x16, #0xa48
   744fc:      	br	x17

0000000000074500 <_ZN8mtlabar325LayerAnimationInteraction18getShowStaticFrameEv@plt>:
   74500:      	adrp	x16, 0x7c000
   74504:      	ldr	x17, [x16, #0xa50]
   74508:      	add	x16, x16, #0xa50
   7450c:      	br	x17

0000000000074510 <_ZN8mtlabar325LayerAnimationInteraction24isHighlightTextAnimationEv@plt>:
   74510:      	adrp	x16, 0x7c000
   74514:      	ldr	x17, [x16, #0xa58]
   74518:      	add	x16, x16, #0xa58
   7451c:      	br	x17

0000000000074520 <_ZN8mtlabar325LayerAnimationInteraction19setPartialTextIndexEi@plt>:
   74520:      	adrp	x16, 0x7c000
   74524:      	ldr	x17, [x16, #0xa60]
   74528:      	add	x16, x16, #0xa60
   7452c:      	br	x17

0000000000074530 <_ZN8mtlabar325LayerAnimationInteraction20setPartialTextLengthEi@plt>:
   74530:      	adrp	x16, 0x7c000
   74534:      	ldr	x17, [x16, #0xa68]
   74538:      	add	x16, x16, #0xa68
   7453c:      	br	x17

0000000000074540 <_ZN8mtlabar325LayerAnimationInteraction22setPartialTextFontSizeEf@plt>:
   74540:      	adrp	x16, 0x7c000
   74544:      	ldr	x17, [x16, #0xa70]
   74548:      	add	x16, x16, #0xa70
   7454c:      	br	x17

0000000000074550 <_ZN8mtlabar325LayerAnimationInteraction18setFontLibraryListERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   74550:      	adrp	x16, 0x7c000
   74554:      	ldr	x17, [x16, #0xa78]
   74558:      	add	x16, x16, #0xa78
   7455c:      	br	x17

0000000000074560 <_ZN8mtlabar325LayerAnimationInteraction18getFontLibraryListEv@plt>:
   74560:      	adrp	x16, 0x7c000
   74564:      	ldr	x17, [x16, #0xa80]
   74568:      	add	x16, x16, #0xa80
   7456c:      	br	x17

0000000000074570 <_ZN8mtlabar325LayerAnimationInteraction16getStopLastFrameEv@plt>:
   74570:      	adrp	x16, 0x7c000
   74574:      	ldr	x17, [x16, #0xa88]
   74578:      	add	x16, x16, #0xa88
   7457c:      	br	x17

0000000000074580 <_ZN8mtlabar325LayerAnimationInteraction16setStopLastFrameEb@plt>:
   74580:      	adrp	x16, 0x7c000
   74584:      	ldr	x17, [x16, #0xa90]
   74588:      	add	x16, x16, #0xa90
   7458c:      	br	x17

0000000000074590 <_ZN8mtlabar325LayerAnimationInteraction16setAnimationTypeENS_17AnimationTimeTypeE@plt>:
   74590:      	adrp	x16, 0x7c000
   74594:      	ldr	x17, [x16, #0xa98]
   74598:      	add	x16, x16, #0xa98
   7459c:      	br	x17

00000000000745a0 <_ZN8mtlabar325LayerAnimationInteraction21setAnimationScopeTypeENS_18AnimationScopeTypeE@plt>:
   745a0:      	adrp	x16, 0x7c000
   745a4:      	ldr	x17, [x16, #0xaa0]
   745a8:      	add	x16, x16, #0xaa0
   745ac:      	br	x17

00000000000745b0 <_ZN8mtlabar325LayerAnimationInteraction21getAnimationScopeTypeEv@plt>:
   745b0:      	adrp	x16, 0x7c000
   745b4:      	ldr	x17, [x16, #0xaa8]
   745b8:      	add	x16, x16, #0xaa8
   745bc:      	br	x17

00000000000745c0 <_ZN8mtlabar325LayerAnimationInteraction19setAdvanceAnimationEb@plt>:
   745c0:      	adrp	x16, 0x7c000
   745c4:      	ldr	x17, [x16, #0xab0]
   745c8:      	add	x16, x16, #0xab0
   745cc:      	br	x17

00000000000745d0 <_ZN8mtlabar325LayerAnimationInteraction19getAdvanceAnimationEv@plt>:
   745d0:      	adrp	x16, 0x7c000
   745d4:      	ldr	x17, [x16, #0xab8]
   745d8:      	add	x16, x16, #0xab8
   745dc:      	br	x17

00000000000745e0 <_ZN8mtlabar325LayerAnimationInteraction18getCustomTransformEv@plt>:
   745e0:      	adrp	x16, 0x7c000
   745e4:      	ldr	x17, [x16, #0xac0]
   745e8:      	add	x16, x16, #0xac0
   745ec:      	br	x17

00000000000745f0 <_ZN8mtlabar325LayerAnimationInteraction15getActiveWordBgEv@plt>:
   745f0:      	adrp	x16, 0x7c000
   745f4:      	ldr	x17, [x16, #0xac8]
   745f8:      	add	x16, x16, #0xac8
   745fc:      	br	x17

0000000000074600 <_ZN8mtlabar325LayerAnimationInteraction18getActiveWordColorEv@plt>:
   74600:      	adrp	x16, 0x7c000
   74604:      	ldr	x17, [x16, #0xad0]
   74608:      	add	x16, x16, #0xad0
   7460c:      	br	x17

0000000000074610 <_ZN8mtlabar325LayerAnimationInteraction21getPreActiveWordColorEv@plt>:
   74610:      	adrp	x16, 0x7c000
   74614:      	ldr	x17, [x16, #0xad8]
   74618:      	add	x16, x16, #0xad8
   7461c:      	br	x17

0000000000074620 <_ZN8mtlabar325LayerAnimationInteraction18getActiveWordStyleEv@plt>:
   74620:      	adrp	x16, 0x7c000
   74624:      	ldr	x17, [x16, #0xae0]
   74628:      	add	x16, x16, #0xae0
   7462c:      	br	x17

0000000000074630 <_ZN8mtlabar321LayerAnimationManager15appendAnimationEv@plt>:
   74630:      	adrp	x16, 0x7c000
   74634:      	ldr	x17, [x16, #0xae8]
   74638:      	add	x16, x16, #0xae8
   7463c:      	br	x17

0000000000074640 <_ZN8mtlabar321LayerAnimationManager17subtractAnimationEPv@plt>:
   74640:      	adrp	x16, 0x7c000
   74644:      	ldr	x17, [x16, #0xaf0]
   74648:      	add	x16, x16, #0xaf0
   7464c:      	br	x17

0000000000074650 <_ZN8mtlabar321LayerAnimationManager20getAnimationListSizeEv@plt>:
   74650:      	adrp	x16, 0x7c000
   74654:      	ldr	x17, [x16, #0xaf8]
   74658:      	add	x16, x16, #0xaf8
   7465c:      	br	x17

0000000000074660 <_ZN8mtlabar321LayerAnimationManager23getAnimationListByIndexEi@plt>:
   74660:      	adrp	x16, 0x7c000
   74664:      	ldr	x17, [x16, #0xb00]
   74668:      	add	x16, x16, #0xb00
   7466c:      	br	x17

0000000000074670 <_ZN8mtlabar321LayerAnimationManager12getAnimationEPv@plt>:
   74670:      	adrp	x16, 0x7c000
   74674:      	ldr	x17, [x16, #0xb08]
   74678:      	add	x16, x16, #0xb08
   7467c:      	br	x17

0000000000074680 <_ZN8mtlabar321LayerAnimationManager27selectedFullScreenAnimationEPv@plt>:
   74680:      	adrp	x16, 0x7c000
   74684:      	ldr	x17, [x16, #0xb10]
   74688:      	add	x16, x16, #0xb10
   7468c:      	br	x17

0000000000074690 <_ZN8mtlabar321LayerAnimationManager20setAnimationPriorityERKNSt6__ndk16vectorINS_17AnimationTimeTypeENS1_9allocatorIS3_EEEE@plt>:
   74690:      	adrp	x16, 0x7c000
   74694:      	ldr	x17, [x16, #0xb18]
   74698:      	add	x16, x16, #0xb18
   7469c:      	br	x17

00000000000746a0 <_ZN8mtlabar325LayerTransformInteraction8setTransENS_6Float2E@plt>:
   746a0:      	adrp	x16, 0x7c000
   746a4:      	ldr	x17, [x16, #0xb20]
   746a8:      	add	x16, x16, #0xb20
   746ac:      	br	x17

00000000000746b0 <_ZN8mtlabar325LayerTransformInteraction8getTransEv@plt>:
   746b0:      	adrp	x16, 0x7c000
   746b4:      	ldr	x17, [x16, #0xb28]
   746b8:      	add	x16, x16, #0xb28
   746bc:      	br	x17

00000000000746c0 <_ZN8mtlabar325LayerTransformInteraction20getCurrentFinalTransEv@plt>:
   746c0:      	adrp	x16, 0x7c000
   746c4:      	ldr	x17, [x16, #0xb30]
   746c8:      	add	x16, x16, #0xb30
   746cc:      	br	x17

00000000000746d0 <_ZN8mtlabar325LayerTransformInteraction21getCurrentFinalRotateEv@plt>:
   746d0:      	adrp	x16, 0x7c000
   746d4:      	ldr	x17, [x16, #0xb38]
   746d8:      	add	x16, x16, #0xb38
   746dc:      	br	x17

00000000000746e0 <_ZN8mtlabar325LayerTransformInteraction18getTouchTransScaleEv@plt>:
   746e0:      	adrp	x16, 0x7c000
   746e4:      	ldr	x17, [x16, #0xb40]
   746e8:      	add	x16, x16, #0xb40
   746ec:      	br	x17

00000000000746f0 <_ZN8mtlabar325LayerTransformInteraction8setScaleEf@plt>:
   746f0:      	adrp	x16, 0x7c000
   746f4:      	ldr	x17, [x16, #0xb48]
   746f8:      	add	x16, x16, #0xb48
   746fc:      	br	x17

0000000000074700 <_ZN8mtlabar325LayerTransformInteraction8getScaleEv@plt>:
   74700:      	adrp	x16, 0x7c000
   74704:      	ldr	x17, [x16, #0xb50]
   74708:      	add	x16, x16, #0xb50
   7470c:      	br	x17

0000000000074710 <_ZN8mtlabar325LayerTransformInteraction10setScaleXYENS_6Float2E@plt>:
   74710:      	adrp	x16, 0x7c000
   74714:      	ldr	x17, [x16, #0xb58]
   74718:      	add	x16, x16, #0xb58
   7471c:      	br	x17

0000000000074720 <_ZN8mtlabar325LayerTransformInteraction10getScaleXYEv@plt>:
   74720:      	adrp	x16, 0x7c000
   74724:      	ldr	x17, [x16, #0xb60]
   74728:      	add	x16, x16, #0xb60
   7472c:      	br	x17

0000000000074730 <_ZN8mtlabar325LayerTransformInteraction15getFinalScaleXYEv@plt>:
   74730:      	adrp	x16, 0x7c000
   74734:      	ldr	x17, [x16, #0xb68]
   74738:      	add	x16, x16, #0xb68
   7473c:      	br	x17

0000000000074740 <_ZN8mtlabar325LayerTransformInteraction9setRotateEf@plt>:
   74740:      	adrp	x16, 0x7c000
   74744:      	ldr	x17, [x16, #0xb70]
   74748:      	add	x16, x16, #0xb70
   7474c:      	br	x17

0000000000074750 <_ZN8mtlabar325LayerTransformInteraction9getRotateEv@plt>:
   74750:      	adrp	x16, 0x7c000
   74754:      	ldr	x17, [x16, #0xb78]
   74758:      	add	x16, x16, #0xb78
   7475c:      	br	x17

0000000000074760 <_ZN8mtlabar325LayerTransformInteraction9setMirrorEb@plt>:
   74760:      	adrp	x16, 0x7c000
   74764:      	ldr	x17, [x16, #0xb80]
   74768:      	add	x16, x16, #0xb80
   7476c:      	br	x17

0000000000074770 <_ZN8mtlabar325LayerTransformInteraction9getMirrorEv@plt>:
   74770:      	adrp	x16, 0x7c000
   74774:      	ldr	x17, [x16, #0xb88]
   74778:      	add	x16, x16, #0xb88
   7477c:      	br	x17

0000000000074780 <_ZN8mtlabar322LayerBorderInteraction12setAreaLimitEb@plt>:
   74780:      	adrp	x16, 0x7c000
   74784:      	ldr	x17, [x16, #0xb90]
   74788:      	add	x16, x16, #0xb90
   7478c:      	br	x17

0000000000074790 <_ZN8mtlabar322LayerBorderInteraction12getAreaLimitEv@plt>:
   74790:      	adrp	x16, 0x7c000
   74794:      	ldr	x17, [x16, #0xb98]
   74798:      	add	x16, x16, #0xb98
   7479c:      	br	x17

00000000000747a0 <_ZN8mtlabar322LayerBorderInteraction23getBorderVertexPositionENS_15LayerVertexEnumE@plt>:
   747a0:      	adrp	x16, 0x7c000
   747a4:      	ldr	x17, [x16, #0xba0]
   747a8:      	add	x16, x16, #0xba0
   747ac:      	br	x17

00000000000747b0 <_ZN8mtlabar322LayerBorderInteraction24getBorderVertexPosition2ENS_15LayerVertexEnumE@plt>:
   747b0:      	adrp	x16, 0x7c000
   747b4:      	ldr	x17, [x16, #0xba8]
   747b8:      	add	x16, x16, #0xba8
   747bc:      	br	x17

00000000000747c0 <_ZN8mtlabar322LayerBorderInteraction16getBorderPaddingENS_13LayerEdgeEnumE@plt>:
   747c0:      	adrp	x16, 0x7c000
   747c4:      	ldr	x17, [x16, #0xbb0]
   747c8:      	add	x16, x16, #0xbb0
   747cc:      	br	x17

00000000000747d0 <_ZN8mtlabar322LayerBorderInteraction21getLayerBorderPaddingENS_13LayerEdgeEnumE@plt>:
   747d0:      	adrp	x16, 0x7c000
   747d4:      	ldr	x17, [x16, #0xbb8]
   747d8:      	add	x16, x16, #0xbb8
   747dc:      	br	x17

00000000000747e0 <_ZN8mtlabar322LayerBorderInteraction34setLocalLayerOutlineBorderMinValueEi@plt>:
   747e0:      	adrp	x16, 0x7c000
   747e4:      	ldr	x17, [x16, #0xbc0]
   747e8:      	add	x16, x16, #0xbc0
   747ec:      	br	x17

00000000000747f0 <_ZN8mtlabar322LayerBorderInteraction36setLocalLayerOutlineBorderMarginLeftEi@plt>:
   747f0:      	adrp	x16, 0x7c000
   747f4:      	ldr	x17, [x16, #0xbc8]
   747f8:      	add	x16, x16, #0xbc8
   747fc:      	br	x17

0000000000074800 <_ZN8mtlabar322LayerBorderInteraction37setLocalLayerOutlineBorderMarginRightEi@plt>:
   74800:      	adrp	x16, 0x7c000
   74804:      	ldr	x17, [x16, #0xbd0]
   74808:      	add	x16, x16, #0xbd0
   7480c:      	br	x17

0000000000074810 <_ZN8mtlabar322LayerBorderInteraction35setLocalLayerOutlineBorderMarginTopEi@plt>:
   74810:      	adrp	x16, 0x7c000
   74814:      	ldr	x17, [x16, #0xbd8]
   74818:      	add	x16, x16, #0xbd8
   7481c:      	br	x17

0000000000074820 <_ZN8mtlabar322LayerBorderInteraction38setLocalLayerOutlineBorderMarginBottomEi@plt>:
   74820:      	adrp	x16, 0x7c000
   74824:      	ldr	x17, [x16, #0xbe0]
   74828:      	add	x16, x16, #0xbe0
   7482c:      	br	x17

0000000000074830 <_ZN8mtlabar322LayerBorderInteraction24calcBorderVertexPositionENS_6Float2Eff@plt>:
   74830:      	adrp	x16, 0x7c000
   74834:      	ldr	x17, [x16, #0xbe8]
   74838:      	add	x16, x16, #0xbe8
   7483c:      	br	x17

0000000000074840 <_ZN8mtlabar322LayerBorderInteraction27getEnableTextBoxInteractionEv@plt>:
   74840:      	adrp	x16, 0x7c000
   74844:      	ldr	x17, [x16, #0xbf0]
   74848:      	add	x16, x16, #0xbf0
   7484c:      	br	x17

0000000000074850 <_ZN8mtlabar322LayerBorderInteraction27setEnableTextBoxInteractionEb@plt>:
   74850:      	adrp	x16, 0x7c000
   74854:      	ldr	x17, [x16, #0xbf8]
   74858:      	add	x16, x16, #0xbf8
   7485c:      	br	x17

0000000000074860 <_ZN8mtlabar316LayerInteraction24getLayerAnimationManagerEv@plt>:
   74860:      	adrp	x16, 0x7c000
   74864:      	ldr	x17, [x16, #0xc00]
   74868:      	add	x16, x16, #0xc00
   7486c:      	br	x17

0000000000074870 <_ZN8mtlabar316LayerInteraction25getLayerBorderInteractionEv@plt>:
   74870:      	adrp	x16, 0x7c000
   74874:      	ldr	x17, [x16, #0xc08]
   74878:      	add	x16, x16, #0xc08
   7487c:      	br	x17

0000000000074880 <_ZN8mtlabar316LayerInteraction28getLayerTransformInteractionEv@plt>:
   74880:      	adrp	x16, 0x7c000
   74884:      	ldr	x17, [x16, #0xc10]
   74888:      	add	x16, x16, #0xc10
   7488c:      	br	x17

0000000000074890 <_ZN8mtlabar316LayerInteraction20getLayerTrackingTypeEv@plt>:
   74890:      	adrp	x16, 0x7c000
   74894:      	ldr	x17, [x16, #0xc18]
   74898:      	add	x16, x16, #0xc18
   7489c:      	br	x17

00000000000748a0 <_ZN8mtlabar316LayerInteraction33getLayerObjectTrackingInteractionEv@plt>:
   748a0:      	adrp	x16, 0x7c000
   748a4:      	ldr	x17, [x16, #0xc20]
   748a8:      	add	x16, x16, #0xc20
   748ac:      	br	x17

00000000000748b0 <_ZN8mtlabar316LayerInteraction31getLayerFaceTrackingInteractionEv@plt>:
   748b0:      	adrp	x16, 0x7c000
   748b4:      	ldr	x17, [x16, #0xc28]
   748b8:      	add	x16, x16, #0xc28
   748bc:      	br	x17

00000000000748c0 <_ZN8mtlabar316LayerInteraction23getLayerTextInteractionEv@plt>:
   748c0:      	adrp	x16, 0x7c000
   748c4:      	ldr	x17, [x16, #0xc30]
   748c8:      	add	x16, x16, #0xc30
   748cc:      	br	x17

00000000000748d0 <_ZN8mtlabar316LayerInteraction23getLayerMaskInteractionEv@plt>:
   748d0:      	adrp	x16, 0x7c000
   748d4:      	ldr	x17, [x16, #0xc38]
   748d8:      	add	x16, x16, #0xc38
   748dc:      	br	x17

00000000000748e0 <_ZN8mtlabar316LayerInteraction26getLayerStickerInteractionEv@plt>:
   748e0:      	adrp	x16, 0x7c000
   748e4:      	ldr	x17, [x16, #0xc40]
   748e8:      	add	x16, x16, #0xc40
   748ec:      	br	x17

00000000000748f0 <_ZN8mtlabar316LayerInteraction24getLayerChartInteractionEv@plt>:
   748f0:      	adrp	x16, 0x7c000
   748f4:      	ldr	x17, [x16, #0xc48]
   748f8:      	add	x16, x16, #0xc48
   748fc:      	br	x17

0000000000074900 <_ZN8mtlabar316LayerInteraction32getLayerTextBGTextureInteractionEv@plt>:
   74900:      	adrp	x16, 0x7c000
   74904:      	ldr	x17, [x16, #0xc50]
   74908:      	add	x16, x16, #0xc50
   7490c:      	br	x17

0000000000074910 <_ZN8mtlabar316LayerInteraction6getTagEv@plt>:
   74910:      	adrp	x16, 0x7c000
   74914:      	ldr	x17, [x16, #0xc58]
   74918:      	add	x16, x16, #0xc58
   7491c:      	br	x17

0000000000074920 <_ZN8mtlabar316LayerInteraction15setOriginalSizeENS_5SizeFE@plt>:
   74920:      	adrp	x16, 0x7c000
   74924:      	ldr	x17, [x16, #0xc60]
   74928:      	add	x16, x16, #0xc60
   7492c:      	br	x17

0000000000074930 <_ZN8mtlabar316LayerInteraction15getOriginalSizeEv@plt>:
   74930:      	adrp	x16, 0x7c000
   74934:      	ldr	x17, [x16, #0xc68]
   74938:      	add	x16, x16, #0xc68
   7493c:      	br	x17

0000000000074940 <_ZN8mtlabar316LayerInteraction12getFinalSizeEv@plt>:
   74940:      	adrp	x16, 0x7c000
   74944:      	ldr	x17, [x16, #0xc70]
   74948:      	add	x16, x16, #0xc70
   7494c:      	br	x17

0000000000074950 <_ZN8mtlabar316LayerInteraction14getDefaultSizeEv@plt>:
   74950:      	adrp	x16, 0x7c000
   74954:      	ldr	x17, [x16, #0xc78]
   74958:      	add	x16, x16, #0xc78
   7495c:      	br	x17

0000000000074960 <_ZN8mtlabar316LayerInteraction12setTimestampEl@plt>:
   74960:      	adrp	x16, 0x7c000
   74964:      	ldr	x17, [x16, #0xc80]
   74968:      	add	x16, x16, #0xc80
   7496c:      	br	x17

0000000000074970 <_ZN8mtlabar316LayerInteraction12getTimestampEv@plt>:
   74970:      	adrp	x16, 0x7c000
   74974:      	ldr	x17, [x16, #0xc88]
   74978:      	add	x16, x16, #0xc88
   7497c:      	br	x17

0000000000074980 <_ZN8mtlabar316LayerInteraction13setVisibilityEb@plt>:
   74980:      	adrp	x16, 0x7c000
   74984:      	ldr	x17, [x16, #0xc90]
   74988:      	add	x16, x16, #0xc90
   7498c:      	br	x17

0000000000074990 <_ZN8mtlabar316LayerInteraction13getVisibilityEv@plt>:
   74990:      	adrp	x16, 0x7c000
   74994:      	ldr	x17, [x16, #0xc98]
   74998:      	add	x16, x16, #0xc98
   7499c:      	br	x17

00000000000749a0 <_ZN8mtlabar316LayerInteraction8setAlphaEf@plt>:
   749a0:      	adrp	x16, 0x7c000
   749a4:      	ldr	x17, [x16, #0xca0]
   749a8:      	add	x16, x16, #0xca0
   749ac:      	br	x17

00000000000749b0 <_ZN8mtlabar316LayerInteraction8getAlphaEv@plt>:
   749b0:      	adrp	x16, 0x7c000
   749b4:      	ldr	x17, [x16, #0xca8]
   749b8:      	add	x16, x16, #0xca8
   749bc:      	br	x17

00000000000749c0 <_ZN8mtlabar316LayerInteraction14setScissorRectENS_5RectIE@plt>:
   749c0:      	adrp	x16, 0x7c000
   749c4:      	ldr	x17, [x16, #0xcb0]
   749c8:      	add	x16, x16, #0xcb0
   749cc:      	br	x17

00000000000749d0 <_ZN8mtlabar316LayerInteraction14getScissorRectEv@plt>:
   749d0:      	adrp	x16, 0x7c000
   749d4:      	ldr	x17, [x16, #0xcb8]
   749d8:      	add	x16, x16, #0xcb8
   749dc:      	br	x17

00000000000749e0 <_ZN8mtlabar316LayerInteraction12setBlendModeENS_14LayerBlendModeE@plt>:
   749e0:      	adrp	x16, 0x7c000
   749e4:      	ldr	x17, [x16, #0xcc0]
   749e8:      	add	x16, x16, #0xcc0
   749ec:      	br	x17

00000000000749f0 <_ZN8mtlabar316LayerInteraction12getBlendModeEv@plt>:
   749f0:      	adrp	x16, 0x7c000
   749f4:      	ldr	x17, [x16, #0xcc8]
   749f8:      	add	x16, x16, #0xcc8
   749fc:      	br	x17

0000000000074a00 <_ZN8mtlabar316LayerInteraction17setEnableSelectedEb@plt>:
   74a00:      	adrp	x16, 0x7c000
   74a04:      	ldr	x17, [x16, #0xcd0]
   74a08:      	add	x16, x16, #0xcd0
   74a0c:      	br	x17

0000000000074a10 <_ZN8mtlabar316LayerInteraction17getEnableSelectedEv@plt>:
   74a10:      	adrp	x16, 0x7c000
   74a14:      	ldr	x17, [x16, #0xcd8]
   74a18:      	add	x16, x16, #0xcd8
   74a1c:      	br	x17

0000000000074a20 <_ZN8mtlabar316LayerInteraction13getLockScreenEv@plt>:
   74a20:      	adrp	x16, 0x7c000
   74a24:      	ldr	x17, [x16, #0xce0]
   74a28:      	add	x16, x16, #0xce0
   74a2c:      	br	x17

0000000000074a30 <_ZN8mtlabar316LayerInteraction20getDesignedDraggableEv@plt>:
   74a30:      	adrp	x16, 0x7c000
   74a34:      	ldr	x17, [x16, #0xce8]
   74a38:      	add	x16, x16, #0xce8
   74a3c:      	br	x17

0000000000074a40 <_ZN8mtlabar316LayerInteraction26getDesignedForceSelectableEv@plt>:
   74a40:      	adrp	x16, 0x7c000
   74a44:      	ldr	x17, [x16, #0xcf0]
   74a48:      	add	x16, x16, #0xcf0
   74a4c:      	br	x17

0000000000074a50 <_ZN8mtlabar316LayerInteraction16getIsEnableDepthEv@plt>:
   74a50:      	adrp	x16, 0x7c000
   74a54:      	ldr	x17, [x16, #0xcf8]
   74a58:      	add	x16, x16, #0xcf8
   74a5c:      	br	x17

0000000000074a60 <_ZN8mtlabar316LayerInteraction14setEnableDepthEb@plt>:
   74a60:      	adrp	x16, 0x7c000
   74a64:      	ldr	x17, [x16, #0xd00]
   74a68:      	add	x16, x16, #0xd00
   74a6c:      	br	x17

0000000000074a70 <_ZN8mtlabar316LayerInteraction27setIsCurrentRenderThumbnailEb@plt>:
   74a70:      	adrp	x16, 0x7c000
   74a74:      	ldr	x17, [x16, #0xd08]
   74a78:      	add	x16, x16, #0xd08
   74a7c:      	br	x17

0000000000074a80 <_ZN8mtlabar316LayerInteraction27getIsCurrentRenderThumbnailEv@plt>:
   74a80:      	adrp	x16, 0x7c000
   74a84:      	ldr	x17, [x16, #0xd10]
   74a88:      	add	x16, x16, #0xd10
   74a8c:      	br	x17

0000000000074a90 <_ZN8mtlabar325TextStructConfigInterface7destroyEPS0_@plt>:
   74a90:      	adrp	x16, 0x7c000
   74a94:      	ldr	x17, [x16, #0xd18]
   74a98:      	add	x16, x16, #0xd18
   74a9c:      	br	x17

0000000000074aa0 <_ZNK8mtlabar325TextStructConfigInterface14getDefaultSizeEv@plt>:
   74aa0:      	adrp	x16, 0x7c000
   74aa4:      	ldr	x17, [x16, #0xd20]
   74aa8:      	add	x16, x16, #0xd20
   74aac:      	br	x17

0000000000074ab0 <_ZN8mtlabar325TextStructConfigInterface15getSubTextLayerEm@plt>:
   74ab0:      	adrp	x16, 0x7c000
   74ab4:      	ldr	x17, [x16, #0xd28]
   74ab8:      	add	x16, x16, #0xd28
   74abc:      	br	x17

0000000000074ac0 <_ZN8mtlabar325TextStructConfigInterface19getSubTextLayerSizeEv@plt>:
   74ac0:      	adrp	x16, 0x7c000
   74ac4:      	ldr	x17, [x16, #0xd30]
   74ac8:      	add	x16, x16, #0xd30
   74acc:      	br	x17

0000000000074ad0 <_ZN8mtlabar320InteractionInterface12resizeCanvasERKNS_14CanvasPropertyE@plt>:
   74ad0:      	adrp	x16, 0x7c000
   74ad4:      	ldr	x17, [x16, #0xd38]
   74ad8:      	add	x16, x16, #0xd38
   74adc:      	br	x17

0000000000074ae0 <_ZN8mtlabar320InteractionInterface17getCanvasPropertyEv@plt>:
   74ae0:      	adrp	x16, 0x7c000
   74ae4:      	ldr	x17, [x16, #0xd40]
   74ae8:      	add	x16, x16, #0xd40
   74aec:      	br	x17

0000000000074af0 <_ZN8mtlabar320InteractionInterface8dispatchEv@plt>:
   74af0:      	adrp	x16, 0x7c000
   74af4:      	ldr	x17, [x16, #0xd48]
   74af8:      	add	x16, x16, #0xd48
   74afc:      	br	x17

0000000000074b00 <_ZN8mtlabar320InteractionInterface9sortLayerEv@plt>:
   74b00:      	adrp	x16, 0x7c000
   74b04:      	ldr	x17, [x16, #0xd50]
   74b08:      	add	x16, x16, #0xd50
   74b0c:      	br	x17

0000000000074b10 <_ZN8mtlabar320InteractionInterface9findLayerEPv@plt>:
   74b10:      	adrp	x16, 0x7c000
   74b14:      	ldr	x17, [x16, #0xd58]
   74b18:      	add	x16, x16, #0xd58
   74b1c:      	br	x17

0000000000074b20 <_ZN8mtlabar39TextUtils13graphemeSplitERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS1_6vectorIS7_NS5_IS7_EEEE@plt>:
   74b20:      	adrp	x16, 0x7c000
   74b24:      	ldr	x17, [x16, #0xd60]
   74b28:      	add	x16, x16, #0xd60
   74b2c:      	br	x17

0000000000074b30 <_ZN8mtlabar39TextUtils19parseTextPathConfigEPKc@plt>:
   74b30:      	adrp	x16, 0x7c000
   74b34:      	ldr	x17, [x16, #0xd68]
   74b38:      	add	x16, x16, #0xd68
   74b3c:      	br	x17

0000000000074b40 <_ZN8mtlabar39TextUtils20parseTextLayerConfigEPKc@plt>:
   74b40:      	adrp	x16, 0x7c000
   74b44:      	ldr	x17, [x16, #0xd70]
   74b48:      	add	x16, x16, #0xd70
   74b4c:      	br	x17

0000000000074b50 <_ZN8mtlabar39TextUtils19parseTextNoteDetailEPKc@plt>:
   74b50:      	adrp	x16, 0x7c000
   74b54:      	ldr	x17, [x16, #0xd78]
   74b58:      	add	x16, x16, #0xd78
   74b5c:      	br	x17

0000000000074b60 <_ZN8mtlabar39TextUtils19parseJsonNoteDetailEPKc@plt>:
   74b60:      	adrp	x16, 0x7c000
   74b64:      	ldr	x17, [x16, #0xd80]
   74b68:      	add	x16, x16, #0xd80
   74b6c:      	br	x17

0000000000074b70 <_ZN8mtlabar39TextUtils19parseTextWarpConfigEPKc@plt>:
   74b70:      	adrp	x16, 0x7c000
   74b74:      	ldr	x17, [x16, #0xd88]
   74b78:      	add	x16, x16, #0xd88
   74b7c:      	br	x17

0000000000074b80 <_ZN8mtlabar39TextUtils20parseAnimationConfigEPKc@plt>:
   74b80:      	adrp	x16, 0x7c000
   74b84:      	ldr	x17, [x16, #0xd90]
   74b88:      	add	x16, x16, #0xd90
   74b8c:      	br	x17

0000000000074b90 <_ZNK8mtlabar311DataRequire22requireSourceGrayImageEv@plt>:
   74b90:      	adrp	x16, 0x7c000
   74b94:      	ldr	x17, [x16, #0xd98]
   74b98:      	add	x16, x16, #0xd98
   74b9c:      	br	x17

0000000000074ba0 <_ZNK8mtlabar311DataRequire23requireSourceColorImageEv@plt>:
   74ba0:      	adrp	x16, 0x7c000
   74ba4:      	ldr	x17, [x16, #0xda0]
   74ba8:      	add	x16, x16, #0xda0
   74bac:      	br	x17

0000000000074bb0 <_ZNK8mtlabar311DataRequire21requireSourceImageGPUEv@plt>:
   74bb0:      	adrp	x16, 0x7c000
   74bb4:      	ldr	x17, [x16, #0xda8]
   74bb8:      	add	x16, x16, #0xda8
   74bbc:      	br	x17

0000000000074bc0 <_ZNK8mtlabar311DataRequire20requireTouchListenerEv@plt>:
   74bc0:      	adrp	x16, 0x7c000
   74bc4:      	ldr	x17, [x16, #0xdb0]
   74bc8:      	add	x16, x16, #0xdb0
   74bcc:      	br	x17

0000000000074bd0 <_ZNK8mtlabar311DataRequire17requireAnimalDataEv@plt>:
   74bd0:      	adrp	x16, 0x7c000
   74bd4:      	ldr	x17, [x16, #0xdb8]
   74bd8:      	add	x16, x16, #0xdb8
   74bdc:      	br	x17

0000000000074be0 <_ZNK8mtlabar311DataRequire15requireFoodDataEv@plt>:
   74be0:      	adrp	x16, 0x7c000
   74be4:      	ldr	x17, [x16, #0xdc0]
   74be8:      	add	x16, x16, #0xdc0
   74bec:      	br	x17

0000000000074bf0 <_ZNK8mtlabar311DataRequire15requireFaceDataEv@plt>:
   74bf0:      	adrp	x16, 0x7c000
   74bf4:      	ldr	x17, [x16, #0xdc8]
   74bf8:      	add	x16, x16, #0xdc8
   74bfc:      	br	x17

0000000000074c00 <_ZNK8mtlabar311DataRequire40requireFaceDataAdditionLimitMaxFaceCountEv@plt>:
   74c00:      	adrp	x16, 0x7c000
   74c04:      	ldr	x17, [x16, #0xdd0]
   74c08:      	add	x16, x16, #0xdd0
   74c0c:      	br	x17

0000000000074c10 <_ZNK8mtlabar311DataRequire27requireFaceDataAdditionHeadEv@plt>:
   74c10:      	adrp	x16, 0x7c000
   74c14:      	ldr	x17, [x16, #0xdd8]
   74c18:      	add	x16, x16, #0xdd8
   74c1c:      	br	x17

0000000000074c20 <_ZNK8mtlabar311DataRequire26requireFaceDataAdditionEarEv@plt>:
   74c20:      	adrp	x16, 0x7c000
   74c24:      	ldr	x17, [x16, #0xde0]
   74c28:      	add	x16, x16, #0xde0
   74c2c:      	br	x17

0000000000074c30 <_ZNK8mtlabar311DataRequire27requireFaceDataAdditionNeckEv@plt>:
   74c30:      	adrp	x16, 0x7c000
   74c34:      	ldr	x17, [x16, #0xde8]
   74c38:      	add	x16, x16, #0xde8
   74c3c:      	br	x17

0000000000074c40 <_ZNK8mtlabar311DataRequire32requireFaceDataAdditionMouthMaskEv@plt>:
   74c40:      	adrp	x16, 0x7c000
   74c44:      	ldr	x17, [x16, #0xdf0]
   74c48:      	add	x16, x16, #0xdf0
   74c4c:      	br	x17

0000000000074c50 <_ZNK8mtlabar311DataRequire31requireFaceDataAdditionFaceMaskEv@plt>:
   74c50:      	adrp	x16, 0x7c000
   74c54:      	ldr	x17, [x16, #0xdf8]
   74c58:      	add	x16, x16, #0xdf8
   74c5c:      	br	x17

0000000000074c60 <_ZNK8mtlabar311DataRequire35requireFaceDataAdditionPosEstimatorEv@plt>:
   74c60:      	adrp	x16, 0x7c000
   74c64:      	ldr	x17, [x16, #0xe00]
   74c68:      	add	x16, x16, #0xe00
   74c6c:      	br	x17

0000000000074c70 <_ZNK8mtlabar311DataRequire29requireFaceDataAdditionGenderEv@plt>:
   74c70:      	adrp	x16, 0x7c000
   74c74:      	ldr	x17, [x16, #0xe08]
   74c78:      	add	x16, x16, #0xe08
   74c7c:      	br	x17

0000000000074c80 <_ZNK8mtlabar311DataRequire26requireFaceDataAdditionAgeEv@plt>:
   74c80:      	adrp	x16, 0x7c000
   74c84:      	ldr	x17, [x16, #0xe10]
   74c88:      	add	x16, x16, #0xe10
   74c8c:      	br	x17

0000000000074c90 <_ZNK8mtlabar311DataRequire29requireFaceDataAdditionEyelidEv@plt>:
   74c90:      	adrp	x16, 0x7c000
   74c94:      	ldr	x17, [x16, #0xe18]
   74c98:      	add	x16, x16, #0xe18
   74c9c:      	br	x17

0000000000074ca0 <_ZNK8mtlabar311DataRequire30requireFaceDataAdditionEmotionEv@plt>:
   74ca0:      	adrp	x16, 0x7c000
   74ca4:      	ldr	x17, [x16, #0xe20]
   74ca8:      	add	x16, x16, #0xe20
   74cac:      	br	x17

0000000000074cb0 <_ZNK8mtlabar311DataRequire27requireFaceDataAddition3DFAEv@plt>:
   74cb0:      	adrp	x16, 0x7c000
   74cb4:      	ldr	x17, [x16, #0xe28]
   74cb8:      	add	x16, x16, #0xe28
   74cbc:      	br	x17

0000000000074cc0 <_ZNK8mtlabar311DataRequire31requireFaceDataAddition3DFAMeshEv@plt>:
   74cc0:      	adrp	x16, 0x7c000
   74cc4:      	ldr	x17, [x16, #0xe30]
   74cc8:      	add	x16, x16, #0xe30
   74ccc:      	br	x17

0000000000074cd0 <_ZNK8mtlabar311DataRequire34requireFaceDataAdditionMakeupAdaptEv@plt>:
   74cd0:      	adrp	x16, 0x7c000
   74cd4:      	ldr	x17, [x16, #0xe38]
   74cd8:      	add	x16, x16, #0xe38
   74cdc:      	br	x17

0000000000074ce0 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV1DataEv@plt>:
   74ce0:      	adrp	x16, 0x7c000
   74ce4:      	ldr	x17, [x16, #0xe40]
   74ce8:      	add	x16, x16, #0xe40
   74cec:      	br	x17

0000000000074cf0 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV2DataEv@plt>:
   74cf0:      	adrp	x16, 0x7c000
   74cf4:      	ldr	x17, [x16, #0xe48]
   74cf8:      	add	x16, x16, #0xe48
   74cfc:      	br	x17

0000000000074d00 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV3DataEv@plt>:
   74d00:      	adrp	x16, 0x7c000
   74d04:      	ldr	x17, [x16, #0xe50]
   74d08:      	add	x16, x16, #0xe50
   74d0c:      	br	x17

0000000000074d10 <_ZNK8mtlabar311DataRequire40requireFace2DBackgroundReconstructorDataEv@plt>:
   74d10:      	adrp	x16, 0x7c000
   74d14:      	ldr	x17, [x16, #0xe58]
   74d18:      	add	x16, x16, #0xe58
   74d1c:      	br	x17

0000000000074d20 <_ZNK8mtlabar311DataRequire30requireFace3DReconstructorDataEv@plt>:
   74d20:      	adrp	x16, 0x7c000
   74d24:      	ldr	x17, [x16, #0xe60]
   74d28:      	add	x16, x16, #0xe60
   74d2c:      	br	x17

0000000000074d30 <_ZNK8mtlabar311DataRequire46requireFace3DReconstructorDataAdditionFovAngleEv@plt>:
   74d30:      	adrp	x16, 0x7c000
   74d34:      	ldr	x17, [x16, #0xe68]
   74d38:      	add	x16, x16, #0xe68
   74d3c:      	br	x17

0000000000074d40 <_ZNK8mtlabar311DataRequire19requireFaceDL3DDataEv@plt>:
   74d40:      	adrp	x16, 0x7c000
   74d44:      	ldr	x17, [x16, #0xe70]
   74d48:      	add	x16, x16, #0xe70
   74d4c:      	br	x17

0000000000074d50 <_ZNK8mtlabar311DataRequire31requireFaceDL3DDataAdditionMeshEv@plt>:
   74d50:      	adrp	x16, 0x7c000
   74d54:      	ldr	x17, [x16, #0xe78]
   74d58:      	add	x16, x16, #0xe78
   74d5c:      	br	x17

0000000000074d60 <_ZNK8mtlabar311DataRequire39requireFaceDL3DDataAdditionPosEstimatorEv@plt>:
   74d60:      	adrp	x16, 0x7c000
   74d64:      	ldr	x17, [x16, #0xe80]
   74d68:      	add	x16, x16, #0xe80
   74d6c:      	br	x17

0000000000074d70 <_ZNK8mtlabar311DataRequire43requireFaceDL3DDataAdditionBlendShapeFactorEv@plt>:
   74d70:      	adrp	x16, 0x7c000
   74d74:      	ldr	x17, [x16, #0xe88]
   74d78:      	add	x16, x16, #0xe88
   74d7c:      	br	x17

0000000000074d80 <_ZNK8mtlabar311DataRequire34requireFaceDL3DDataAdditionRiggingEv@plt>:
   74d80:      	adrp	x16, 0x7c000
   74d84:      	ldr	x17, [x16, #0xe90]
   74d88:      	add	x16, x16, #0xe90
   74d8c:      	br	x17

0000000000074d90 <_ZNK8mtlabar311DataRequire19requireShoulderDataEv@plt>:
   74d90:      	adrp	x16, 0x7c000
   74d94:      	ldr	x17, [x16, #0xe98]
   74d98:      	add	x16, x16, #0xe98
   74d9c:      	br	x17

0000000000074da0 <_ZNK8mtlabar311DataRequire15requireHandDataEv@plt>:
   74da0:      	adrp	x16, 0x7c000
   74da4:      	ldr	x17, [x16, #0xea0]
   74da8:      	add	x16, x16, #0xea0
   74dac:      	br	x17

0000000000074db0 <_ZNK8mtlabar311DataRequire40requireHandDataAdditionLimitMaxHandCountEv@plt>:
   74db0:      	adrp	x16, 0x7c000
   74db4:      	ldr	x17, [x16, #0xea8]
   74db8:      	add	x16, x16, #0xea8
   74dbc:      	br	x17

0000000000074dc0 <_ZNK8mtlabar311DataRequire27requireHandDataAdditionPoseEv@plt>:
   74dc0:      	adrp	x16, 0x7c000
   74dc4:      	ldr	x17, [x16, #0xeb0]
   74dc8:      	add	x16, x16, #0xeb0
   74dcc:      	br	x17

0000000000074dd0 <_ZNK8mtlabar311DataRequire16requireNailsDataEv@plt>:
   74dd0:      	adrp	x16, 0x7c000
   74dd4:      	ldr	x17, [x16, #0xeb8]
   74dd8:      	add	x16, x16, #0xeb8
   74ddc:      	br	x17

0000000000074de0 <_ZNK8mtlabar311DataRequire15requireBodyMaskEv@plt>:
   74de0:      	adrp	x16, 0x7c000
   74de4:      	ldr	x17, [x16, #0xec0]
   74de8:      	add	x16, x16, #0xec0
   74dec:      	br	x17

0000000000074df0 <_ZNK8mtlabar311DataRequire26requireBodyMaskAdditionCPUEv@plt>:
   74df0:      	adrp	x16, 0x7c000
   74df4:      	ldr	x17, [x16, #0xec8]
   74df8:      	add	x16, x16, #0xec8
   74dfc:      	br	x17

0000000000074e00 <_ZNK8mtlabar311DataRequire26requireBodyMaskAdditionGPUEv@plt>:
   74e00:      	adrp	x16, 0x7c000
   74e04:      	ldr	x17, [x16, #0xed0]
   74e08:      	add	x16, x16, #0xed0
   74e0c:      	br	x17

0000000000074e10 <_ZNK8mtlabar311DataRequire15requireHairMaskEv@plt>:
   74e10:      	adrp	x16, 0x7c000
   74e14:      	ldr	x17, [x16, #0xed8]
   74e18:      	add	x16, x16, #0xed8
   74e1c:      	br	x17

0000000000074e20 <_ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv@plt>:
   74e20:      	adrp	x16, 0x7c000
   74e24:      	ldr	x17, [x16, #0xee0]
   74e28:      	add	x16, x16, #0xee0
   74e2c:      	br	x17

0000000000074e30 <_ZNK8mtlabar311DataRequire26requireHairMaskAdditionGPUEv@plt>:
   74e30:      	adrp	x16, 0x7c000
   74e34:      	ldr	x17, [x16, #0xee8]
   74e38:      	add	x16, x16, #0xee8
   74e3c:      	br	x17

0000000000074e40 <_ZNK8mtlabar311DataRequire14requireSkyMaskEv@plt>:
   74e40:      	adrp	x16, 0x7c000
   74e44:      	ldr	x17, [x16, #0xef0]
   74e48:      	add	x16, x16, #0xef0
   74e4c:      	br	x17

0000000000074e50 <_ZNK8mtlabar311DataRequire25requireSkyMaskAdditionCPUEv@plt>:
   74e50:      	adrp	x16, 0x7c000
   74e54:      	ldr	x17, [x16, #0xef8]
   74e58:      	add	x16, x16, #0xef8
   74e5c:      	br	x17

0000000000074e60 <_ZNK8mtlabar311DataRequire25requireSkyMaskAdditionGPUEv@plt>:
   74e60:      	adrp	x16, 0x7c000
   74e64:      	ldr	x17, [x16, #0xf00]
   74e68:      	add	x16, x16, #0xf00
   74e6c:      	br	x17

0000000000074e70 <_ZNK8mtlabar311DataRequire15requireSkinMaskEv@plt>:
   74e70:      	adrp	x16, 0x7c000
   74e74:      	ldr	x17, [x16, #0xf08]
   74e78:      	add	x16, x16, #0xf08
   74e7c:      	br	x17

0000000000074e80 <_ZNK8mtlabar311DataRequire26requireSkinMaskAdditionCPUEv@plt>:
   74e80:      	adrp	x16, 0x7c000
   74e84:      	ldr	x17, [x16, #0xf10]
   74e88:      	add	x16, x16, #0xf10
   74e8c:      	br	x17

0000000000074e90 <_ZNK8mtlabar311DataRequire26requireSkinMaskAdditionGPUEv@plt>:
   74e90:      	adrp	x16, 0x7c000
   74e94:      	ldr	x17, [x16, #0xf18]
   74e98:      	add	x16, x16, #0xf18
   74e9c:      	br	x17

0000000000074ea0 <_ZNK8mtlabar311DataRequire15requireHeadMaskEv@plt>:
   74ea0:      	adrp	x16, 0x7c000
   74ea4:      	ldr	x17, [x16, #0xf20]
   74ea8:      	add	x16, x16, #0xf20
   74eac:      	br	x17

0000000000074eb0 <_ZNK8mtlabar311DataRequire26requireHeadMaskAdditionCPUEv@plt>:
   74eb0:      	adrp	x16, 0x7c000
   74eb4:      	ldr	x17, [x16, #0xf28]
   74eb8:      	add	x16, x16, #0xf28
   74ebc:      	br	x17

0000000000074ec0 <_ZNK8mtlabar311DataRequire26requireHeadMaskAdditionGPUEv@plt>:
   74ec0:      	adrp	x16, 0x7c000
   74ec4:      	ldr	x17, [x16, #0xf30]
   74ec8:      	add	x16, x16, #0xf30
   74ecc:      	br	x17

0000000000074ed0 <_ZNK8mtlabar311DataRequire16requireNevusMaskEv@plt>:
   74ed0:      	adrp	x16, 0x7c000
   74ed4:      	ldr	x17, [x16, #0xf38]
   74ed8:      	add	x16, x16, #0xf38
   74edc:      	br	x17

0000000000074ee0 <_ZNK8mtlabar311DataRequire27requireNevusMaskAdditionCPUEv@plt>:
   74ee0:      	adrp	x16, 0x7c000
   74ee4:      	ldr	x17, [x16, #0xf40]
   74ee8:      	add	x16, x16, #0xf40
   74eec:      	br	x17

0000000000074ef0 <_ZNK8mtlabar311DataRequire27requireNevusMaskAdditionGPUEv@plt>:
   74ef0:      	adrp	x16, 0x7c000
   74ef4:      	ldr	x17, [x16, #0xf48]
   74ef8:      	add	x16, x16, #0xf48
   74efc:      	br	x17

0000000000074f00 <_ZNK8mtlabar311DataRequire22requireFaceContourMaskEv@plt>:
   74f00:      	adrp	x16, 0x7c000
   74f04:      	ldr	x17, [x16, #0xf50]
   74f08:      	add	x16, x16, #0xf50
   74f0c:      	br	x17

0000000000074f10 <_ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionCPUEv@plt>:
   74f10:      	adrp	x16, 0x7c000
   74f14:      	ldr	x17, [x16, #0xf58]
   74f18:      	add	x16, x16, #0xf58
   74f1c:      	br	x17

0000000000074f20 <_ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionGPUEv@plt>:
   74f20:      	adrp	x16, 0x7c000
   74f24:      	ldr	x17, [x16, #0xf60]
   74f28:      	add	x16, x16, #0xf60
   74f2c:      	br	x17

0000000000074f30 <_ZNK8mtlabar311DataRequire16requireClothMaskEv@plt>:
   74f30:      	adrp	x16, 0x7c000
   74f34:      	ldr	x17, [x16, #0xf68]
   74f38:      	add	x16, x16, #0xf68
   74f3c:      	br	x17

0000000000074f40 <_ZNK8mtlabar311DataRequire27requireClothMaskAdditionCPUEv@plt>:
   74f40:      	adrp	x16, 0x7c000
   74f44:      	ldr	x17, [x16, #0xf70]
   74f48:      	add	x16, x16, #0xf70
   74f4c:      	br	x17

0000000000074f50 <_ZNK8mtlabar311DataRequire27requireClothMaskAdditionGPUEv@plt>:
   74f50:      	adrp	x16, 0x7c000
   74f54:      	ldr	x17, [x16, #0xf78]
   74f58:      	add	x16, x16, #0xf78
   74f5c:      	br	x17

0000000000074f60 <_ZNK8mtlabar311DataRequire23requireFaceNeckLineMaskEv@plt>:
   74f60:      	adrp	x16, 0x7c000
   74f64:      	ldr	x17, [x16, #0xf80]
   74f68:      	add	x16, x16, #0xf80
   74f6c:      	br	x17

0000000000074f70 <_ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionCPUEv@plt>:
   74f70:      	adrp	x16, 0x7c000
   74f74:      	ldr	x17, [x16, #0xf88]
   74f78:      	add	x16, x16, #0xf88
   74f7c:      	br	x17

0000000000074f80 <_ZNK8mtlabar311DataRequire34requireFaceNeckLineMaskAdditionGPUEv@plt>:
   74f80:      	adrp	x16, 0x7c000
   74f84:      	ldr	x17, [x16, #0xf90]
   74f88:      	add	x16, x16, #0xf90
   74f8c:      	br	x17

0000000000074f90 <_ZNK8mtlabar311DataRequire14requireEyeMaskEv@plt>:
   74f90:      	adrp	x16, 0x7c000
   74f94:      	ldr	x17, [x16, #0xf98]
   74f98:      	add	x16, x16, #0xf98
   74f9c:      	br	x17

0000000000074fa0 <_ZNK8mtlabar311DataRequire11requireBodyEv@plt>:
   74fa0:      	adrp	x16, 0x7c000
   74fa4:      	ldr	x17, [x16, #0xfa0]
   74fa8:      	add	x16, x16, #0xfa0
   74fac:      	br	x17

0000000000074fb0 <_ZNK8mtlabar311DataRequire16requireBodyInOneEv@plt>:
   74fb0:      	adrp	x16, 0x7c000
   74fb4:      	ldr	x17, [x16, #0xfa8]
   74fb8:      	add	x16, x16, #0xfa8
   74fbc:      	br	x17

0000000000074fc0 <_ZNK8mtlabar311DataRequire24requireBodyAdditionHumanEv@plt>:
   74fc0:      	adrp	x16, 0x7c000
   74fc4:      	ldr	x17, [x16, #0xfb0]
   74fc8:      	add	x16, x16, #0xfb0
   74fcc:      	br	x17

0000000000074fd0 <_ZNK8mtlabar311DataRequire24requireBodyAdditionJointEv@plt>:
   74fd0:      	adrp	x16, 0x7c000
   74fd4:      	ldr	x17, [x16, #0xfb8]
   74fd8:      	add	x16, x16, #0xfb8
   74fdc:      	br	x17

0000000000074fe0 <_ZNK8mtlabar311DataRequire26requireBodyAdditionContourEv@plt>:
   74fe0:      	adrp	x16, 0x7c000
   74fe4:      	ldr	x17, [x16, #0xfc0]
   74fe8:      	add	x16, x16, #0xfc0
   74fec:      	br	x17

0000000000074ff0 <_ZNK8mtlabar311DataRequire28requireARGyroscopeQuaternionEv@plt>:
   74ff0:      	adrp	x16, 0x7c000
   74ff4:      	ldr	x17, [x16, #0xfc8]
   74ff8:      	add	x16, x16, #0xfc8
   74ffc:      	br	x17

0000000000075000 <_ZNK8mtlabar311DataRequire17requireARFaceMeshEv@plt>:
   75000:      	adrp	x16, 0x7c000
   75004:      	ldr	x17, [x16, #0xfd0]
   75008:      	add	x16, x16, #0xfd0
   7500c:      	br	x17

0000000000075010 <_ZNK8mtlabar311DataRequire19requireARPointCloudEv@plt>:
   75010:      	adrp	x16, 0x7c000
   75014:      	ldr	x17, [x16, #0xfd8]
   75018:      	add	x16, x16, #0xfd8
   7501c:      	br	x17

0000000000075020 <_ZNK8mtlabar311DataRequire22requireARWorldTrackingEv@plt>:
   75020:      	adrp	x16, 0x7c000
   75024:      	ldr	x17, [x16, #0xfe0]
   75028:      	add	x16, x16, #0xfe0
   7502c:      	br	x17

0000000000075030 <_ZNK8mtlabar311DataRequire20requireARPlaneAnchorEv@plt>:
   75030:      	adrp	x16, 0x7c000
   75034:      	ldr	x17, [x16, #0xfe8]
   75038:      	add	x16, x16, #0xfe8
   7503c:      	br	x17

0000000000075040 <_ZNK8mtlabar311DataRequire22requireARLightEstimateEv@plt>:
   75040:      	adrp	x16, 0x7c000
   75044:      	ldr	x17, [x16, #0xff0]
   75048:      	add	x16, x16, #0xff0
   7504c:      	br	x17

0000000000075050 <_ZNK8mtlabar311DataRequire25requireARInstantPlacementEv@plt>:
   75050:      	adrp	x16, 0x7c000
   75054:      	ldr	x17, [x16, #0xff8]
   75058:      	add	x16, x16, #0xff8
   7505c:      	br	x17

0000000000075060 <_ZNK8mtlabar311DataRequire17requireARSkeletonEv@plt>:
   75060:      	adrp	x16, 0x7d000
   75064:      	ldr	x17, [x16]
   75068:      	add	x16, x16, #0x0
   7506c:      	br	x17

0000000000075070 <_ZNK8mtlabar311DataRequire9requireCGEv@plt>:
   75070:      	adrp	x16, 0x7d000
   75074:      	ldr	x17, [x16, #0x8]
   75078:      	add	x16, x16, #0x8
   7507c:      	br	x17

0000000000075080 <_ZNK8mtlabar311DataRequire20requireCGAdditionCPUEv@plt>:
   75080:      	adrp	x16, 0x7d000
   75084:      	ldr	x17, [x16, #0x10]
   75088:      	add	x16, x16, #0x10
   7508c:      	br	x17

0000000000075090 <_ZNK8mtlabar311DataRequire20requireCGAdditionGPUEv@plt>:
   75090:      	adrp	x16, 0x7d000
   75094:      	ldr	x17, [x16, #0x18]
   75098:      	add	x16, x16, #0x18
   7509c:      	br	x17

00000000000750a0 <_ZNK8mtlabar311DataRequire24requireCompactBeautyDataEv@plt>:
   750a0:      	adrp	x16, 0x7d000
   750a4:      	ldr	x17, [x16, #0x20]
   750a8:      	add	x16, x16, #0x20
   750ac:      	br	x17

00000000000750b0 <_ZNK8mtlabar311DataRequire14requireHuman3DEv@plt>:
   750b0:      	adrp	x16, 0x7d000
   750b4:      	ldr	x17, [x16, #0x28]
   750b8:      	add	x16, x16, #0x28
   750bc:      	br	x17

00000000000750c0 <_ZNK8mtlabar311DataRequire17requireSpaceDepthEv@plt>:
   750c0:      	adrp	x16, 0x7d000
   750c4:      	ldr	x17, [x16, #0x30]
   750c8:      	add	x16, x16, #0x30
   750cc:      	br	x17

00000000000750d0 <_ZNK8mtlabar311DataRequire18requireSpaceNormalEv@plt>:
   750d0:      	adrp	x16, 0x7d000
   750d4:      	ldr	x17, [x16, #0x38]
   750d8:      	add	x16, x16, #0x38
   750dc:      	br	x17

00000000000750e0 <_ZNK8mtlabar311DataRequire22requireInteractiveMaskEv@plt>:
   750e0:      	adrp	x16, 0x7d000
   750e4:      	ldr	x17, [x16, #0x40]
   750e8:      	add	x16, x16, #0x40
   750ec:      	br	x17

00000000000750f0 <_ZNK8mtlabar311DataRequire22requireOutStandingMaskEv@plt>:
   750f0:      	adrp	x16, 0x7d000
   750f4:      	ldr	x17, [x16, #0x48]
   750f8:      	add	x16, x16, #0x48
   750fc:      	br	x17

0000000000075100 <_ZNK8mtlabar311DataRequire24requireMultiInstanceMaskEv@plt>:
   75100:      	adrp	x16, 0x7d000
   75104:      	ldr	x17, [x16, #0x50]
   75108:      	add	x16, x16, #0x50
   7510c:      	br	x17

0000000000075110 <_ZNK8mtlabar311DataRequire22requireUserDefinedMaskEv@plt>:
   75110:      	adrp	x16, 0x7d000
   75114:      	ldr	x17, [x16, #0x58]
   75118:      	add	x16, x16, #0x58
   7511c:      	br	x17

0000000000075120 <_ZNK8mtlabar311DataRequire33requireBodySlim3DAbundantButtocksEv@plt>:
   75120:      	adrp	x16, 0x7d000
   75124:      	ldr	x17, [x16, #0x60]
   75128:      	add	x16, x16, #0x60
   7512c:      	br	x17

0000000000075130 <_ZNK8mtlabar311DataRequire34requireBodySlim3DThinLowerAbdomensEv@plt>:
   75130:      	adrp	x16, 0x7d000
   75134:      	ldr	x17, [x16, #0x68]
   75138:      	add	x16, x16, #0x68
   7513c:      	br	x17

0000000000075140 <_ZNK8mtlabar311DataRequire30requireBodySlim3DShoulderBraceEv@plt>:
   75140:      	adrp	x16, 0x7d000
   75144:      	ldr	x17, [x16, #0x70]
   75148:      	add	x16, x16, #0x70
   7514c:      	br	x17

0000000000075150 <_ZNK8mtlabar311DataRequire27requireBodySlim3DBreastLiftEv@plt>:
   75150:      	adrp	x16, 0x7d000
   75154:      	ldr	x17, [x16, #0x78]
   75158:      	add	x16, x16, #0x78
   7515c:      	br	x17

0000000000075160 <_ZNK8mtlabar311DataRequire25requireBodySlim3DButtLiftEv@plt>:
   75160:      	adrp	x16, 0x7d000
   75164:      	ldr	x17, [x16, #0x80]
   75168:      	add	x16, x16, #0x80
   7516c:      	br	x17

0000000000075170 <_ZNK8mtlabar311DataRequire32requireBodySlim3DAbundantBreastsEv@plt>:
   75170:      	adrp	x16, 0x7d000
   75174:      	ldr	x17, [x16, #0x88]
   75178:      	add	x16, x16, #0x88
   7517c:      	br	x17

0000000000075180 <_ZNK8mtlabar311DataRequire32requireBodySlim3DBreastReductionEv@plt>:
   75180:      	adrp	x16, 0x7d000
   75184:      	ldr	x17, [x16, #0x90]
   75188:      	add	x16, x16, #0x90
   7518c:      	br	x17

0000000000075190 <_ZNK8mtlabar311DataRequire26requireBodySlim3DTrapeziusEv@plt>:
   75190:      	adrp	x16, 0x7d000
   75194:      	ldr	x17, [x16, #0x98]
   75198:      	add	x16, x16, #0x98
   7519c:      	br	x17

00000000000751a0 <_ZNK8mtlabar311DataRequire26requireBodyBeautyBGFillingEv@plt>:
   751a0:      	adrp	x16, 0x7d000
   751a4:      	ldr	x17, [x16, #0xa0]
   751a8:      	add	x16, x16, #0xa0
   751ac:      	br	x17

00000000000751b0 <_ZN8mtlabar312HumanControl13getGenderTypeEv@plt>:
   751b0:      	adrp	x16, 0x7d000
   751b4:      	ldr	x17, [x16, #0xa8]
   751b8:      	add	x16, x16, #0xa8
   751bc:      	br	x17

00000000000751c0 <_ZN8mtlabar312HumanControl13setGenderTypeENS_14FaceGenderTypeE@plt>:
   751c0:      	adrp	x16, 0x7d000
   751c4:      	ldr	x17, [x16, #0xb0]
   751c8:      	add	x16, x16, #0xb0
   751cc:      	br	x17

00000000000751d0 <_ZN8mtlabar312HumanControl10getFaceIDsEv@plt>:
   751d0:      	adrp	x16, 0x7d000
   751d4:      	ldr	x17, [x16, #0xb8]
   751d8:      	add	x16, x16, #0xb8
   751dc:      	br	x17

00000000000751e0 <_ZN8mtlabar312HumanControl10setFaceIDsERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
   751e0:      	adrp	x16, 0x7d000
   751e4:      	ldr	x17, [x16, #0xc0]
   751e8:      	add	x16, x16, #0xc0
   751ec:      	br	x17

00000000000751f0 <_ZN8mtlabar321MakeupControlInstance16getControlFaceIDEv@plt>:
   751f0:      	adrp	x16, 0x7d000
   751f4:      	ldr	x17, [x16, #0xc8]
   751f8:      	add	x16, x16, #0xc8
   751fc:      	br	x17

0000000000075200 <_ZN8mtlabar321MakeupControlInstance12setPartAlphaEf@plt>:
   75200:      	adrp	x16, 0x7d000
   75204:      	ldr	x17, [x16, #0xd0]
   75208:      	add	x16, x16, #0xd0
   7520c:      	br	x17

0000000000075210 <_ZN8mtlabar321MakeupControlInstance12getPartAlphaEv@plt>:
   75210:      	adrp	x16, 0x7d000
   75214:      	ldr	x17, [x16, #0xd8]
   75218:      	add	x16, x16, #0xd8
   7521c:      	br	x17

0000000000075220 <_ZN8mtlabar321MakeupControlInstance10setOpacityEf@plt>:
   75220:      	adrp	x16, 0x7d000
   75224:      	ldr	x17, [x16, #0xe0]
   75228:      	add	x16, x16, #0xe0
   7522c:      	br	x17

0000000000075230 <_ZN8mtlabar321MakeupControlInstance10getOpacityEv@plt>:
   75230:      	adrp	x16, 0x7d000
   75234:      	ldr	x17, [x16, #0xe8]
   75238:      	add	x16, x16, #0xe8
   7523c:      	br	x17

0000000000075240 <_ZN8mtlabar321MakeupControlInstance9setColorAERKNS_6ColorAE@plt>:
   75240:      	adrp	x16, 0x7d000
   75244:      	ldr	x17, [x16, #0xf0]
   75248:      	add	x16, x16, #0xf0
   7524c:      	br	x17

0000000000075250 <_ZNK8mtlabar321MakeupControlInstance9getColorAEv@plt>:
   75250:      	adrp	x16, 0x7d000
   75254:      	ldr	x17, [x16, #0xf8]
   75258:      	add	x16, x16, #0xf8
   7525c:      	br	x17

0000000000075260 <_ZN8mtlabar313MakeupControl20getMakeupControlTypeEv@plt>:
   75260:      	adrp	x16, 0x7d000
   75264:      	ldr	x17, [x16, #0x100]
   75268:      	add	x16, x16, #0x100
   7526c:      	br	x17

0000000000075270 <_ZN8mtlabar313MakeupControl25getMakeupControlTypeChildEv@plt>:
   75270:      	adrp	x16, 0x7d000
   75274:      	ldr	x17, [x16, #0x108]
   75278:      	add	x16, x16, #0x108
   7527c:      	br	x17

0000000000075280 <_ZN8mtlabar313MakeupControl24getMakeupControlInstanceEi@plt>:
   75280:      	adrp	x16, 0x7d000
   75284:      	ldr	x17, [x16, #0x110]
   75288:      	add	x16, x16, #0x110
   7528c:      	br	x17

0000000000075290 <_ZN8mtlabar313MakeupControl19getDefaultPartAlphaEv@plt>:
   75290:      	adrp	x16, 0x7d000
   75294:      	ldr	x17, [x16, #0x118]
   75298:      	add	x16, x16, #0x118
   7529c:      	br	x17

00000000000752a0 <_ZN8mtlabar313MakeupControl17getDefaultOpacityEv@plt>:
   752a0:      	adrp	x16, 0x7d000
   752a4:      	ldr	x17, [x16, #0x120]
   752a8:      	add	x16, x16, #0x120
   752ac:      	br	x17

00000000000752b0 <_ZNK8mtlabar313MakeupControl9getColorAEv@plt>:
   752b0:      	adrp	x16, 0x7d000
   752b4:      	ldr	x17, [x16, #0x128]
   752b8:      	add	x16, x16, #0x128
   752bc:      	br	x17

00000000000752c0 <_ZN8mtlabar313MakeupControl30getNoFaceMakeupControlInstanceEv@plt>:
   752c0:      	adrp	x16, 0x7d000
   752c4:      	ldr	x17, [x16, #0x130]
   752c8:      	add	x16, x16, #0x130
   752cc:      	br	x17

00000000000752d0 <_ZN8mtlabar313MakeupControl25getIsStaticOpacityControlEv@plt>:
   752d0:      	adrp	x16, 0x7d000
   752d4:      	ldr	x17, [x16, #0x138]
   752d8:      	add	x16, x16, #0x138
   752dc:      	br	x17

00000000000752e0 <_ZN8mtlabar322EyeSideControlInstance16getControlFaceIDEv@plt>:
   752e0:      	adrp	x16, 0x7d000
   752e4:      	ldr	x17, [x16, #0x140]
   752e8:      	add	x16, x16, #0x140
   752ec:      	br	x17

00000000000752f0 <_ZN8mtlabar322EyeSideControlInstance12setPartAlphaEf@plt>:
   752f0:      	adrp	x16, 0x7d000
   752f4:      	ldr	x17, [x16, #0x148]
   752f8:      	add	x16, x16, #0x148
   752fc:      	br	x17

0000000000075300 <_ZN8mtlabar322EyeSideControlInstance12getPartAlphaEv@plt>:
   75300:      	adrp	x16, 0x7d000
   75304:      	ldr	x17, [x16, #0x150]
   75308:      	add	x16, x16, #0x150
   7530c:      	br	x17

0000000000075310 <_ZN8mtlabar314EyeSideControl20getMakeupControlTypeEv@plt>:
   75310:      	adrp	x16, 0x7d000
   75314:      	ldr	x17, [x16, #0x158]
   75318:      	add	x16, x16, #0x158
   7531c:      	br	x17

0000000000075320 <_ZN8mtlabar314EyeSideControl17getMakeupSideTypeEv@plt>:
   75320:      	adrp	x16, 0x7d000
   75324:      	ldr	x17, [x16, #0x160]
   75328:      	add	x16, x16, #0x160
   7532c:      	br	x17

0000000000075330 <_ZN8mtlabar314EyeSideControl25getEyeSideControlInstanceEi@plt>:
   75330:      	adrp	x16, 0x7d000
   75334:      	ldr	x17, [x16, #0x168]
   75338:      	add	x16, x16, #0x168
   7533c:      	br	x17

0000000000075340 <_ZN8mtlabar314FaceliftSlider16getControlFaceIDEv@plt>:
   75340:      	adrp	x16, 0x7d000
   75344:      	ldr	x17, [x16, #0x170]
   75348:      	add	x16, x16, #0x170
   7534c:      	br	x17

0000000000075350 <_ZNK8mtlabar314FaceliftSlider17getControlKeyNameEv@plt>:
   75350:      	adrp	x16, 0x7d000
   75354:      	ldr	x17, [x16, #0x178]
   75358:      	add	x16, x16, #0x178
   7535c:      	br	x17

0000000000075360 <_ZNK8mtlabar314FaceliftSlider15getDefaultValueEv@plt>:
   75360:      	adrp	x16, 0x7d000
   75364:      	ldr	x17, [x16, #0x180]
   75368:      	add	x16, x16, #0x180
   7536c:      	br	x17

0000000000075370 <_ZNK8mtlabar314FaceliftSlider8getValueEv@plt>:
   75370:      	adrp	x16, 0x7d000
   75374:      	ldr	x17, [x16, #0x188]
   75378:      	add	x16, x16, #0x188
   7537c:      	br	x17

0000000000075380 <_ZNK8mtlabar314FaceliftSlider11getMinValueEv@plt>:
   75380:      	adrp	x16, 0x7d000
   75384:      	ldr	x17, [x16, #0x190]
   75388:      	add	x16, x16, #0x190
   7538c:      	br	x17

0000000000075390 <_ZNK8mtlabar314FaceliftSlider11getMaxValueEv@plt>:
   75390:      	adrp	x16, 0x7d000
   75394:      	ldr	x17, [x16, #0x198]
   75398:      	add	x16, x16, #0x198
   7539c:      	br	x17

00000000000753a0 <_ZN8mtlabar314FaceliftSlider8setValueEf@plt>:
   753a0:      	adrp	x16, 0x7d000
   753a4:      	ldr	x17, [x16, #0x1a0]
   753a8:      	add	x16, x16, #0x1a0
   753ac:      	br	x17

00000000000753b0 <_ZNK8mtlabar314FaceliftSlider27getNeutralizeTheEffectValueEv@plt>:
   753b0:      	adrp	x16, 0x7d000
   753b4:      	ldr	x17, [x16, #0x1a8]
   753b8:      	add	x16, x16, #0x1a8
   753bc:      	br	x17

00000000000753c0 <_ZNK8mtlabar323FaceliftControlInstance23getFaceliftControlCountEv@plt>:
   753c0:      	adrp	x16, 0x7d000
   753c4:      	ldr	x17, [x16, #0x1b0]
   753c8:      	add	x16, x16, #0x1b0
   753cc:      	br	x17

00000000000753d0 <_ZNK8mtlabar323FaceliftControlInstance25getFaceliftControlKeyNameEm@plt>:
   753d0:      	adrp	x16, 0x7d000
   753d4:      	ldr	x17, [x16, #0x1b8]
   753d8:      	add	x16, x16, #0x1b8
   753dc:      	br	x17

00000000000753e0 <_ZN8mtlabar323FaceliftControlInstance26getFaceliftSliderByKeyNameEPKc@plt>:
   753e0:      	adrp	x16, 0x7d000
   753e4:      	ldr	x17, [x16, #0x1c0]
   753e8:      	add	x16, x16, #0x1c0
   753ec:      	br	x17

00000000000753f0 <_ZN8mtlabar323FaceliftControlInstance24getFaceliftSliderByIndexEm@plt>:
   753f0:      	adrp	x16, 0x7d000
   753f4:      	ldr	x17, [x16, #0x1c8]
   753f8:      	add	x16, x16, #0x1c8
   753fc:      	br	x17

0000000000075400 <_ZNK8mtlabar315FaceliftControl23getFaceliftControlCountEv@plt>:
   75400:      	adrp	x16, 0x7d000
   75404:      	ldr	x17, [x16, #0x1d0]
   75408:      	add	x16, x16, #0x1d0
   7540c:      	br	x17

0000000000075410 <_ZNK8mtlabar315FaceliftControl25getFaceliftControlKeyNameEm@plt>:
   75410:      	adrp	x16, 0x7d000
   75414:      	ldr	x17, [x16, #0x1d8]
   75418:      	add	x16, x16, #0x1d8
   7541c:      	br	x17

0000000000075420 <_ZN8mtlabar315FaceliftControl26getFaceliftControlInstanceEi@plt>:
   75420:      	adrp	x16, 0x7d000
   75424:      	ldr	x17, [x16, #0x1e0]
   75428:      	add	x16, x16, #0x1e0
   7542c:      	br	x17

0000000000075430 <_ZN8mtlabar315FaceliftControl19clearAllSliderValueEi@plt>:
   75430:      	adrp	x16, 0x7d000
   75434:      	ldr	x17, [x16, #0x1e8]
   75438:      	add	x16, x16, #0x1e8
   7543c:      	br	x17

0000000000075440 <_ZN8mtlabar319BodySlimEffectState19getMaximumDataCountEv@plt>:
   75440:      	adrp	x16, 0x7d000
   75444:      	ldr	x17, [x16, #0x1f0]
   75448:      	add	x16, x16, #0x1f0
   7544c:      	br	x17

0000000000075450 <_ZN8mtlabar319BodySlimEffectState18getDistEffectStateENS_19BodySlimControlTypeEl@plt>:
   75450:      	adrp	x16, 0x7d000
   75454:      	ldr	x17, [x16, #0x1f8]
   75458:      	add	x16, x16, #0x1f8
   7545c:      	br	x17

0000000000075460 <_ZN8mtlabar332AutomaticBodySlimControlInstance28isSupportForMultiDataControlEv@plt>:
   75460:      	adrp	x16, 0x7d000
   75464:      	ldr	x17, [x16, #0x200]
   75468:      	add	x16, x16, #0x200
   7546c:      	br	x17

0000000000075470 <_ZN8mtlabar332AutomaticBodySlimControlInstance26getMaximumSupportDataCountEv@plt>:
   75470:      	adrp	x16, 0x7d000
   75474:      	ldr	x17, [x16, #0x208]
   75478:      	add	x16, x16, #0x208
   7547c:      	br	x17

0000000000075480 <_ZN8mtlabar332AutomaticBodySlimControlInstance12setValueByIdElf@plt>:
   75480:      	adrp	x16, 0x7d000
   75484:      	ldr	x17, [x16, #0x210]
   75488:      	add	x16, x16, #0x210
   7548c:      	br	x17

0000000000075490 <_ZNK8mtlabar332AutomaticBodySlimControlInstance12getValueByIdEl@plt>:
   75490:      	adrp	x16, 0x7d000
   75494:      	ldr	x17, [x16, #0x218]
   75498:      	add	x16, x16, #0x218
   7549c:      	br	x17

00000000000754a0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance15getDefaultValueEv@plt>:
   754a0:      	adrp	x16, 0x7d000
   754a4:      	ldr	x17, [x16, #0x220]
   754a8:      	add	x16, x16, #0x220
   754ac:      	br	x17

00000000000754b0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance11getMinValueEv@plt>:
   754b0:      	adrp	x16, 0x7d000
   754b4:      	ldr	x17, [x16, #0x228]
   754b8:      	add	x16, x16, #0x228
   754bc:      	br	x17

00000000000754c0 <_ZNK8mtlabar332AutomaticBodySlimControlInstance11getMaxValueEv@plt>:
   754c0:      	adrp	x16, 0x7d000
   754c4:      	ldr	x17, [x16, #0x230]
   754c8:      	add	x16, x16, #0x230
   754cc:      	br	x17

00000000000754d0 <_ZN8mtlabar332AutomaticBodySlimControlInstance13clearValueMapEv@plt>:
   754d0:      	adrp	x16, 0x7d000
   754d4:      	ldr	x17, [x16, #0x238]
   754d8:      	add	x16, x16, #0x238
   754dc:      	br	x17

00000000000754e0 <_ZN8mtlabar329ManualBodySlimControlInstance28isSupportForMultiDataControlEv@plt>:
   754e0:      	adrp	x16, 0x7d000
   754e4:      	ldr	x17, [x16, #0x240]
   754e8:      	add	x16, x16, #0x240
   754ec:      	br	x17

00000000000754f0 <_ZN8mtlabar329ManualBodySlimControlInstance12getParamTypeEv@plt>:
   754f0:      	adrp	x16, 0x7d000
   754f4:      	ldr	x17, [x16, #0x248]
   754f8:      	add	x16, x16, #0x248
   754fc:      	br	x17

0000000000075500 <_ZN8mtlabar329ManualBodySlimControlInstance23setManualRectangleParamEPNS_23BodySlimManualRectangleEi@plt>:
   75500:      	adrp	x16, 0x7d000
   75504:      	ldr	x17, [x16, #0x250]
   75508:      	add	x16, x16, #0x250
   7550c:      	br	x17

0000000000075510 <_ZN8mtlabar329ManualBodySlimControlInstance18setManualLineParamEPNS_18BodySlimManualLineEi@plt>:
   75510:      	adrp	x16, 0x7d000
   75514:      	ldr	x17, [x16, #0x258]
   75518:      	add	x16, x16, #0x258
   7551c:      	br	x17

0000000000075520 <_ZN8mtlabar329ManualBodySlimControlInstance19setManualRoundParamEPNS_19BodySlimManualRoundEi@plt>:
   75520:      	adrp	x16, 0x7d000
   75524:      	ldr	x17, [x16, #0x260]
   75528:      	add	x16, x16, #0x260
   7552c:      	br	x17

0000000000075530 <_ZN8mtlabar323BodySlimControlInstance20setEffectIsEffectiveEb@plt>:
   75530:      	adrp	x16, 0x7d000
   75534:      	ldr	x17, [x16, #0x268]
   75538:      	add	x16, x16, #0x268
   7553c:      	br	x17

0000000000075540 <_ZN8mtlabar323BodySlimControlInstance20getEffectIsEffectiveEv@plt>:
   75540:      	adrp	x16, 0x7d000
   75544:      	ldr	x17, [x16, #0x270]
   75548:      	add	x16, x16, #0x270
   7554c:      	br	x17

0000000000075550 <_ZN8mtlabar323BodySlimControlInstance14getControlTypeEv@plt>:
   75550:      	adrp	x16, 0x7d000
   75554:      	ldr	x17, [x16, #0x278]
   75558:      	add	x16, x16, #0x278
   7555c:      	br	x17

0000000000075560 <_ZN8mtlabar323BodySlimControlInstance12getParamTypeEv@plt>:
   75560:      	adrp	x16, 0x7d000
   75564:      	ldr	x17, [x16, #0x280]
   75568:      	add	x16, x16, #0x280
   7556c:      	br	x17

0000000000075570 <_ZN8mtlabar323BodySlimControlInstance32getManualBodySlimControlInstanceEv@plt>:
   75570:      	adrp	x16, 0x7d000
   75574:      	ldr	x17, [x16, #0x288]
   75578:      	add	x16, x16, #0x288
   7557c:      	br	x17

0000000000075580 <_ZN8mtlabar323BodySlimControlInstance35getAutomaticBodySlimControlInstanceEv@plt>:
   75580:      	adrp	x16, 0x7d000
   75584:      	ldr	x17, [x16, #0x290]
   75588:      	add	x16, x16, #0x290
   7558c:      	br	x17

0000000000075590 <_ZNK8mtlabar315BodySlimControl23getBodySlimControlCountEv@plt>:
   75590:      	adrp	x16, 0x7d000
   75594:      	ldr	x17, [x16, #0x298]
   75598:      	add	x16, x16, #0x298
   7559c:      	br	x17

00000000000755a0 <_ZN8mtlabar315BodySlimControl25getBodySlimControlByIndexEm@plt>:
   755a0:      	adrp	x16, 0x7d000
   755a4:      	ldr	x17, [x16, #0x2a0]
   755a8:      	add	x16, x16, #0x2a0
   755ac:      	br	x17

00000000000755b0 <_ZN8mtlabar315BodySlimControl24getBodySlimControlByTypeENS_19BodySlimControlTypeE@plt>:
   755b0:      	adrp	x16, 0x7d000
   755b4:      	ldr	x17, [x16, #0x2a8]
   755b8:      	add	x16, x16, #0x2a8
   755bc:      	br	x17

00000000000755c0 <_ZN8mtlabar315BodySlimControl24getBodySlimOperateSwitchEv@plt>:
   755c0:      	adrp	x16, 0x7d000
   755c4:      	ldr	x17, [x16, #0x2b0]
   755c8:      	add	x16, x16, #0x2b0
   755cc:      	br	x17

00000000000755d0 <_ZN8mtlabar315BodySlimControl24setBodySlimOperateSwitchEl@plt>:
   755d0:      	adrp	x16, 0x7d000
   755d4:      	ldr	x17, [x16, #0x2b8]
   755d8:      	add	x16, x16, #0x2b8
   755dc:      	br	x17

00000000000755e0 <_ZN8mtlabar315BodySlimControl22getTransformationPointEPfi@plt>:
   755e0:      	adrp	x16, 0x7d000
   755e4:      	ldr	x17, [x16, #0x2c0]
   755e8:      	add	x16, x16, #0x2c0
   755ec:      	br	x17

00000000000755f0 <_ZN8mtlabar315BodySlimControl22getBodySlimEffectStateEPNS_18FrameDataInterfaceE@plt>:
   755f0:      	adrp	x16, 0x7d000
   755f4:      	ldr	x17, [x16, #0x2c8]
   755f8:      	add	x16, x16, #0x2c8
   755fc:      	br	x17

0000000000075600 <_ZN8mtlabar315BodySlimControl32getMultiModelBodySlimEffectStateEPNS_18FrameDataInterfaceE@plt>:
   75600:      	adrp	x16, 0x7d000
   75604:      	ldr	x17, [x16, #0x2d0]
   75608:      	add	x16, x16, #0x2d0
   7560c:      	br	x17

0000000000075610 <_ZN8mtlabar315BodySlimControl20switchToSigModelDataEb@plt>:
   75610:      	adrp	x16, 0x7d000
   75614:      	ldr	x17, [x16, #0x2d8]
   75618:      	add	x16, x16, #0x2d8
   7561c:      	br	x17

0000000000075620 <_ZN8mtlabar315BodySlimControl19enforceSigModelDataEb@plt>:
   75620:      	adrp	x16, 0x7d000
   75624:      	ldr	x17, [x16, #0x2e0]
   75628:      	add	x16, x16, #0x2e0
   7562c:      	br	x17

0000000000075630 <_ZN8mtlabar315BodySlimControl25isSigModelIsNeckExistenceEPNS_18FrameDataInterfaceE@plt>:
   75630:      	adrp	x16, 0x7d000
   75634:      	ldr	x17, [x16, #0x2e8]
   75638:      	add	x16, x16, #0x2e8
   7563c:      	br	x17

0000000000075640 <_ZN8mtlabar315BodySlimControl27isMultiModelIsNeckExistenceEPNS_18FrameDataInterfaceE@plt>:
   75640:      	adrp	x16, 0x7d000
   75644:      	ldr	x17, [x16, #0x2f0]
   75648:      	add	x16, x16, #0x2f0
   7564c:      	br	x17

0000000000075650 <_ZN8mtlabar315BodySlimControl29isSigModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE@plt>:
   75650:      	adrp	x16, 0x7d000
   75654:      	ldr	x17, [x16, #0x2f8]
   75658:      	add	x16, x16, #0x2f8
   7565c:      	br	x17

0000000000075660 <_ZN8mtlabar315BodySlimControl31isMultiModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE@plt>:
   75660:      	adrp	x16, 0x7d000
   75664:      	ldr	x17, [x16, #0x300]
   75668:      	add	x16, x16, #0x300
   7566c:      	br	x17

0000000000075670 <_ZN8mtlabar315BodySlimControl32isSigModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE@plt>:
   75670:      	adrp	x16, 0x7d000
   75674:      	ldr	x17, [x16, #0x308]
   75678:      	add	x16, x16, #0x308
   7567c:      	br	x17

0000000000075680 <_ZN8mtlabar315BodySlimControl34isMultiModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE@plt>:
   75680:      	adrp	x16, 0x7d000
   75684:      	ldr	x17, [x16, #0x310]
   75688:      	add	x16, x16, #0x310
   7568c:      	br	x17

0000000000075690 <_ZN8mtlabar318ShoulderMLSControl8setValueEf@plt>:
   75690:      	adrp	x16, 0x7d000
   75694:      	ldr	x17, [x16, #0x318]
   75698:      	add	x16, x16, #0x318
   7569c:      	br	x17

00000000000756a0 <_ZNK8mtlabar318ShoulderMLSControl8getValueEv@plt>:
   756a0:      	adrp	x16, 0x7d000
   756a4:      	ldr	x17, [x16, #0x320]
   756a8:      	add	x16, x16, #0x320
   756ac:      	br	x17

00000000000756b0 <_ZNK8mtlabar318ShoulderMLSControl15getDefaultValueEv@plt>:
   756b0:      	adrp	x16, 0x7d000
   756b4:      	ldr	x17, [x16, #0x328]
   756b8:      	add	x16, x16, #0x328
   756bc:      	br	x17

00000000000756c0 <_ZN8mtlabar318ShoulderMLSControl25getShoulderMLSEffectStateEPNS_18FrameDataInterfaceE@plt>:
   756c0:      	adrp	x16, 0x7d000
   756c4:      	ldr	x17, [x16, #0x330]
   756c8:      	add	x16, x16, #0x330
   756cc:      	br	x17

00000000000756d0 <_ZN8mtlabar316HipDeformControl23getHipDeformEffectStateEPNS_18FrameDataInterfaceE@plt>:
   756d0:      	adrp	x16, 0x7d000
   756d4:      	ldr	x17, [x16, #0x338]
   756d8:      	add	x16, x16, #0x338
   756dc:      	br	x17

00000000000756e0 <_ZN8mtlabar315SwanNeckControl22getSwanNeckEffectStateEPNS_18FrameDataInterfaceE@plt>:
   756e0:      	adrp	x16, 0x7d000
   756e4:      	ldr	x17, [x16, #0x340]
   756e8:      	add	x16, x16, #0x340
   756ec:      	br	x17

00000000000756f0 <_ZN8mtlabar322BodyShapingPartControl22getUpperArmEffectStateEPNS_18FrameDataInterfaceE@plt>:
   756f0:      	adrp	x16, 0x7d000
   756f4:      	ldr	x17, [x16, #0x348]
   756f8:      	add	x16, x16, #0x348
   756fc:      	br	x17

0000000000075700 <_ZN8mtlabar322BodyShapingPartControl21getForearmEffectStateEPNS_18FrameDataInterfaceE@plt>:
   75700:      	adrp	x16, 0x7d000
   75704:      	ldr	x17, [x16, #0x350]
   75708:      	add	x16, x16, #0x350
   7570c:      	br	x17

0000000000075710 <_ZN8mtlabar322BodyShapingPartControl19getThighEffectStateEPNS_18FrameDataInterfaceE@plt>:
   75710:      	adrp	x16, 0x7d000
   75714:      	ldr	x17, [x16, #0x358]
   75718:      	add	x16, x16, #0x358
   7571c:      	br	x17

0000000000075720 <_ZN8mtlabar322BodyShapingPartControl18getCalfEffectStateEPNS_18FrameDataInterfaceE@plt>:
   75720:      	adrp	x16, 0x7d000
   75724:      	ldr	x17, [x16, #0x360]
   75728:      	add	x16, x16, #0x360
   7572c:      	br	x17

0000000000075730 <_ZN8mtlabar314StickerControl20setStickerAlphaValueEf@plt>:
   75730:      	adrp	x16, 0x7d000
   75734:      	ldr	x17, [x16, #0x368]
   75738:      	add	x16, x16, #0x368
   7573c:      	br	x17

0000000000075740 <_ZNK8mtlabar314StickerControl20getStickerAlphaValueEv@plt>:
   75740:      	adrp	x16, 0x7d000
   75744:      	ldr	x17, [x16, #0x370]
   75748:      	add	x16, x16, #0x370
   7574c:      	br	x17

0000000000075750 <_ZNK8mtlabar314StickerControl27getStickerDefaultAlphaValueEv@plt>:
   75750:      	adrp	x16, 0x7d000
   75754:      	ldr	x17, [x16, #0x378]
   75758:      	add	x16, x16, #0x378
   7575c:      	br	x17

0000000000075760 <_ZN8mtlabar314StickerControl13setStickerFPSEj@plt>:
   75760:      	adrp	x16, 0x7d000
   75764:      	ldr	x17, [x16, #0x380]
   75768:      	add	x16, x16, #0x380
   7576c:      	br	x17

0000000000075770 <_ZNK8mtlabar314StickerControl13getStickerFPSEv@plt>:
   75770:      	adrp	x16, 0x7d000
   75774:      	ldr	x17, [x16, #0x388]
   75778:      	add	x16, x16, #0x388
   7577c:      	br	x17

0000000000075780 <_ZN8mtlabar314StickerControl14setStickerSizeEf@plt>:
   75780:      	adrp	x16, 0x7d000
   75784:      	ldr	x17, [x16, #0x390]
   75788:      	add	x16, x16, #0x390
   7578c:      	br	x17

0000000000075790 <_ZNK8mtlabar314StickerControl14getStickerSizeEv@plt>:
   75790:      	adrp	x16, 0x7d000
   75794:      	ldr	x17, [x16, #0x398]
   75798:      	add	x16, x16, #0x398
   7579c:      	br	x17

00000000000757a0 <_ZN8mtlabar314StickerControl24setStickerVerticalOffsetEf@plt>:
   757a0:      	adrp	x16, 0x7d000
   757a4:      	ldr	x17, [x16, #0x3a0]
   757a8:      	add	x16, x16, #0x3a0
   757ac:      	br	x17

00000000000757b0 <_ZNK8mtlabar314StickerControl24getStickerVerticalOffsetEv@plt>:
   757b0:      	adrp	x16, 0x7d000
   757b4:      	ldr	x17, [x16, #0x3a8]
   757b8:      	add	x16, x16, #0x3a8
   757bc:      	br	x17

00000000000757c0 <_ZN8mtlabar314StickerControl26setStickerHorizontalOffsetEf@plt>:
   757c0:      	adrp	x16, 0x7d000
   757c4:      	ldr	x17, [x16, #0x3b0]
   757c8:      	add	x16, x16, #0x3b0
   757cc:      	br	x17

00000000000757d0 <_ZNK8mtlabar314StickerControl26getStickerHorizontalOffsetEv@plt>:
   757d0:      	adrp	x16, 0x7d000
   757d4:      	ldr	x17, [x16, #0x3b8]
   757d8:      	add	x16, x16, #0x3b8
   757dc:      	br	x17

00000000000757e0 <_ZN8mtlabar311ToneControl15setCurrentValueENS_8ToneTypeEf@plt>:
   757e0:      	adrp	x16, 0x7d000
   757e4:      	ldr	x17, [x16, #0x3c0]
   757e8:      	add	x16, x16, #0x3c0
   757ec:      	br	x17

00000000000757f0 <_ZNK8mtlabar311ToneControl15getCurrentValueENS_8ToneTypeE@plt>:
   757f0:      	adrp	x16, 0x7d000
   757f4:      	ldr	x17, [x16, #0x3c8]
   757f8:      	add	x16, x16, #0x3c8
   757fc:      	br	x17

0000000000075800 <_ZNK8mtlabar311ToneControl15getDefaultValueENS_8ToneTypeE@plt>:
   75800:      	adrp	x16, 0x7d000
   75804:      	ldr	x17, [x16, #0x3d0]
   75808:      	add	x16, x16, #0x3d0
   7580c:      	br	x17

0000000000075810 <_ZNK8mtlabar311ToneControl11getMaxValueENS_8ToneTypeE@plt>:
   75810:      	adrp	x16, 0x7d000
   75814:      	ldr	x17, [x16, #0x3d8]
   75818:      	add	x16, x16, #0x3d8
   7581c:      	br	x17

0000000000075820 <_ZNK8mtlabar311ToneControl11getMinValueENS_8ToneTypeE@plt>:
   75820:      	adrp	x16, 0x7d000
   75824:      	ldr	x17, [x16, #0x3e0]
   75828:      	add	x16, x16, #0x3e0
   7582c:      	br	x17

0000000000075830 <_ZN8mtlabar311ToneControl8resetAllEv@plt>:
   75830:      	adrp	x16, 0x7d000
   75834:      	ldr	x17, [x16, #0x3e8]
   75838:      	add	x16, x16, #0x3e8
   7583c:      	br	x17

0000000000075840 <_ZN8mtlabar310HSLControl15setCurrentValueENS_12HSLColorTypeEfff@plt>:
   75840:      	adrp	x16, 0x7d000
   75844:      	ldr	x17, [x16, #0x3f0]
   75848:      	add	x16, x16, #0x3f0
   7584c:      	br	x17

0000000000075850 <_ZNK8mtlabar310HSLControl15getCurrentValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   75850:      	adrp	x16, 0x7d000
   75854:      	ldr	x17, [x16, #0x3f8]
   75858:      	add	x16, x16, #0x3f8
   7585c:      	br	x17

0000000000075860 <_ZNK8mtlabar310HSLControl15getDefaultValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   75860:      	adrp	x16, 0x7d000
   75864:      	ldr	x17, [x16, #0x400]
   75868:      	add	x16, x16, #0x400
   7586c:      	br	x17

0000000000075870 <_ZNK8mtlabar310HSLControl11getMaxValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   75870:      	adrp	x16, 0x7d000
   75874:      	ldr	x17, [x16, #0x408]
   75878:      	add	x16, x16, #0x408
   7587c:      	br	x17

0000000000075880 <_ZNK8mtlabar310HSLControl11getMinValueENS_12HSLColorTypeEPfS2_S2_@plt>:
   75880:      	adrp	x16, 0x7d000
   75884:      	ldr	x17, [x16, #0x410]
   75888:      	add	x16, x16, #0x410
   7588c:      	br	x17

0000000000075890 <_ZN8mtlabar310HSLControl8resetAllEv@plt>:
   75890:      	adrp	x16, 0x7d000
   75894:      	ldr	x17, [x16, #0x418]
   75898:      	add	x16, x16, #0x418
   7589c:      	br	x17

00000000000758a0 <_ZN8mtlabar316PickColorControl8getIndexEfff@plt>:
   758a0:      	adrp	x16, 0x7d000
   758a4:      	ldr	x17, [x16, #0x420]
   758a8:      	add	x16, x16, #0x420
   758ac:      	br	x17

00000000000758b0 <_ZN8mtlabar316PickColorControl15setCurrentValueEmfff@plt>:
   758b0:      	adrp	x16, 0x7d000
   758b4:      	ldr	x17, [x16, #0x428]
   758b8:      	add	x16, x16, #0x428
   758bc:      	br	x17

00000000000758c0 <_ZNK8mtlabar316PickColorControl15getCurrentValueEmPfS1_S1_@plt>:
   758c0:      	adrp	x16, 0x7d000
   758c4:      	ldr	x17, [x16, #0x430]
   758c8:      	add	x16, x16, #0x430
   758cc:      	br	x17

00000000000758d0 <_ZNK8mtlabar316PickColorControl15getDefaultValueEPfS1_S1_@plt>:
   758d0:      	adrp	x16, 0x7d000
   758d4:      	ldr	x17, [x16, #0x438]
   758d8:      	add	x16, x16, #0x438
   758dc:      	br	x17

00000000000758e0 <_ZNK8mtlabar316PickColorControl11getMaxValueEPfS1_S1_@plt>:
   758e0:      	adrp	x16, 0x7d000
   758e4:      	ldr	x17, [x16, #0x440]
   758e8:      	add	x16, x16, #0x440
   758ec:      	br	x17

00000000000758f0 <_ZNK8mtlabar316PickColorControl11getMinValueEPfS1_S1_@plt>:
   758f0:      	adrp	x16, 0x7d000
   758f4:      	ldr	x17, [x16, #0x448]
   758f8:      	add	x16, x16, #0x448
   758fc:      	br	x17

0000000000075900 <_ZN8mtlabar316PickColorControl10removeItemEm@plt>:
   75900:      	adrp	x16, 0x7d000
   75904:      	ldr	x17, [x16, #0x450]
   75908:      	add	x16, x16, #0x450
   7590c:      	br	x17

0000000000075910 <_ZN8mtlabar316PickColorControl5clearEv@plt>:
   75910:      	adrp	x16, 0x7d000
   75914:      	ldr	x17, [x16, #0x458]
   75918:      	add	x16, x16, #0x458
   7591c:      	br	x17

0000000000075920 <_ZN8mtlabar313ToningControl14getToneControlEv@plt>:
   75920:      	adrp	x16, 0x7d000
   75924:      	ldr	x17, [x16, #0x460]
   75928:      	add	x16, x16, #0x460
   7592c:      	br	x17

0000000000075930 <_ZN8mtlabar313ToningControl13getHSLControlEv@plt>:
   75930:      	adrp	x16, 0x7d000
   75934:      	ldr	x17, [x16, #0x468]
   75938:      	add	x16, x16, #0x468
   7593c:      	br	x17

0000000000075940 <_ZN8mtlabar313ToningControl19getPickColorControlEv@plt>:
   75940:      	adrp	x16, 0x7d000
   75944:      	ldr	x17, [x16, #0x470]
   75948:      	add	x16, x16, #0x470
   7594c:      	br	x17

0000000000075950 <_ZN8mtlabar320MVBronzersPenControl20getSourceMaskTextureEl@plt>:
   75950:      	adrp	x16, 0x7d000
   75954:      	ldr	x17, [x16, #0x478]
   75958:      	add	x16, x16, #0x478
   7595c:      	br	x17

0000000000075960 <_ZN8mtlabar320MVBronzersPenControl23getStandFaceMaskTextureEl@plt>:
   75960:      	adrp	x16, 0x7d000
   75964:      	ldr	x17, [x16, #0x480]
   75968:      	add	x16, x16, #0x480
   7596c:      	br	x17

0000000000075970 <_ZN8mtlabar320MVBronzersPenControl25getStandFaceEffectTextureEl@plt>:
   75970:      	adrp	x16, 0x7d000
   75974:      	ldr	x17, [x16, #0x488]
   75978:      	add	x16, x16, #0x488
   7597c:      	br	x17

0000000000075980 <_ZN8mtlabar320MVBronzersPenControl20setBrushMaskWithFaceElP15WGPUTextureImplNS_17MVBronzersPenModeE@plt>:
   75980:      	adrp	x16, 0x7d000
   75984:      	ldr	x17, [x16, #0x490]
   75988:      	add	x16, x16, #0x490
   7598c:      	br	x17

0000000000075990 <_ZN8mtlabar320MVBronzersPenControl16setStandFaceMaskElP15WGPUTextureImpl@plt>:
   75990:      	adrp	x16, 0x7d000
   75994:      	ldr	x17, [x16, #0x498]
   75998:      	add	x16, x16, #0x498
   7599c:      	br	x17

00000000000759a0 <_ZN8mtlabar320MVBronzersPenControl25setStandFaceEffectTextureElP15WGPUTextureImpl@plt>:
   759a0:      	adrp	x16, 0x7d000
   759a4:      	ldr	x17, [x16, #0x4a0]
   759a8:      	add	x16, x16, #0x4a0
   759ac:      	br	x17

00000000000759b0 <_ZN8mtlabar320MVBronzersPenControl8setColorENS_10ColorSpaceEfff@plt>:
   759b0:      	adrp	x16, 0x7d000
   759b4:      	ldr	x17, [x16, #0x4a8]
   759b8:      	add	x16, x16, #0x4a8
   759bc:      	br	x17

00000000000759c0 <_ZN8mtlabar320MVBronzersPenControl15setCurrentPenIDEPKc@plt>:
   759c0:      	adrp	x16, 0x7d000
   759c4:      	ldr	x17, [x16, #0x4b0]
   759c8:      	add	x16, x16, #0x4b0
   759cc:      	br	x17

00000000000759d0 <_ZN8mtlabar320MVBronzersPenControl24isEnableFacialProtectionEb@plt>:
   759d0:      	adrp	x16, 0x7d000
   759d4:      	ldr	x17, [x16, #0x4b8]
   759d8:      	add	x16, x16, #0x4b8
   759dc:      	br	x17

00000000000759e0 <_ZN8mtlabar310BrushCache6createEv@plt>:
   759e0:      	adrp	x16, 0x7d000
   759e4:      	ldr	x17, [x16, #0x4c0]
   759e8:      	add	x16, x16, #0x4c0
   759ec:      	br	x17

00000000000759f0 <_ZN8mtlabar310BrushCache7destroyEPS0_@plt>:
   759f0:      	adrp	x16, 0x7d000
   759f4:      	ldr	x17, [x16, #0x4c8]
   759f8:      	add	x16, x16, #0x4c8
   759fc:      	br	x17

0000000000075a00 <_ZN8mtlabar310BrushCache8deepCopyEPKS0_@plt>:
   75a00:      	adrp	x16, 0x7d000
   75a04:      	ldr	x17, [x16, #0x4d0]
   75a08:      	add	x16, x16, #0x4d0
   75a0c:      	br	x17

0000000000075a10 <_ZN8mtlabar310BrushCache8getColorEv@plt>:
   75a10:      	adrp	x16, 0x7d000
   75a14:      	ldr	x17, [x16, #0x4d8]
   75a18:      	add	x16, x16, #0x4d8
   75a1c:      	br	x17

0000000000075a20 <_ZN8mtlabar310BrushCache8setColorERKNS_6Float3E@plt>:
   75a20:      	adrp	x16, 0x7d000
   75a24:      	ldr	x17, [x16, #0x4e0]
   75a28:      	add	x16, x16, #0x4e0
   75a2c:      	br	x17

0000000000075a30 <_ZNK8mtlabar310BrushCache10getPenModeEv@plt>:
   75a30:      	adrp	x16, 0x7d000
   75a34:      	ldr	x17, [x16, #0x4e8]
   75a38:      	add	x16, x16, #0x4e8
   75a3c:      	br	x17

0000000000075a40 <_ZN8mtlabar310BrushCache10setPenModeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   75a40:      	adrp	x16, 0x7d000
   75a44:      	ldr	x17, [x16, #0x4f0]
   75a48:      	add	x16, x16, #0x4f0
   75a4c:      	br	x17

0000000000075a50 <_ZNK8mtlabar310BrushCache7getSizeEv@plt>:
   75a50:      	adrp	x16, 0x7d000
   75a54:      	ldr	x17, [x16, #0x4f8]
   75a58:      	add	x16, x16, #0x4f8
   75a5c:      	br	x17

0000000000075a60 <_ZN8mtlabar310BrushCache7setSizeEf@plt>:
   75a60:      	adrp	x16, 0x7d000
   75a64:      	ldr	x17, [x16, #0x500]
   75a68:      	add	x16, x16, #0x500
   75a6c:      	br	x17

0000000000075a70 <_ZNK8mtlabar310BrushCache8getShapeEv@plt>:
   75a70:      	adrp	x16, 0x7d000
   75a74:      	ldr	x17, [x16, #0x508]
   75a78:      	add	x16, x16, #0x508
   75a7c:      	br	x17

0000000000075a80 <_ZN8mtlabar310BrushCache8setShapeEi@plt>:
   75a80:      	adrp	x16, 0x7d000
   75a84:      	ldr	x17, [x16, #0x510]
   75a88:      	add	x16, x16, #0x510
   75a8c:      	br	x17

0000000000075a90 <_ZNK8mtlabar310BrushCache11getIntervalEv@plt>:
   75a90:      	adrp	x16, 0x7d000
   75a94:      	ldr	x17, [x16, #0x518]
   75a98:      	add	x16, x16, #0x518
   75a9c:      	br	x17

0000000000075aa0 <_ZN8mtlabar310BrushCache11setIntervalEi@plt>:
   75aa0:      	adrp	x16, 0x7d000
   75aa4:      	ldr	x17, [x16, #0x520]
   75aa8:      	add	x16, x16, #0x520
   75aac:      	br	x17

0000000000075ab0 <_ZNK8mtlabar310BrushCache15getColorDirFlagEv@plt>:
   75ab0:      	adrp	x16, 0x7d000
   75ab4:      	ldr	x17, [x16, #0x528]
   75ab8:      	add	x16, x16, #0x528
   75abc:      	br	x17

0000000000075ac0 <_ZN8mtlabar310BrushCache15setColorDirFlagEi@plt>:
   75ac0:      	adrp	x16, 0x7d000
   75ac4:      	ldr	x17, [x16, #0x530]
   75ac8:      	add	x16, x16, #0x530
   75acc:      	br	x17

0000000000075ad0 <_ZNK8mtlabar310BrushCache14getVertexCountEv@plt>:
   75ad0:      	adrp	x16, 0x7d000
   75ad4:      	ldr	x17, [x16, #0x538]
   75ad8:      	add	x16, x16, #0x538
   75adc:      	br	x17

0000000000075ae0 <_ZN8mtlabar310BrushCache14setVertexCountEi@plt>:
   75ae0:      	adrp	x16, 0x7d000
   75ae4:      	ldr	x17, [x16, #0x540]
   75ae8:      	add	x16, x16, #0x540
   75aec:      	br	x17

0000000000075af0 <_ZNK8mtlabar310BrushCache13getPointCountEv@plt>:
   75af0:      	adrp	x16, 0x7d000
   75af4:      	ldr	x17, [x16, #0x548]
   75af8:      	add	x16, x16, #0x548
   75afc:      	br	x17

0000000000075b00 <_ZN8mtlabar310BrushCache13setPointCountEi@plt>:
   75b00:      	adrp	x16, 0x7d000
   75b04:      	ldr	x17, [x16, #0x550]
   75b08:      	add	x16, x16, #0x550
   75b0c:      	br	x17

0000000000075b10 <_ZNK8mtlabar310BrushCache10getInitDirEv@plt>:
   75b10:      	adrp	x16, 0x7d000
   75b14:      	ldr	x17, [x16, #0x558]
   75b18:      	add	x16, x16, #0x558
   75b1c:      	br	x17

0000000000075b20 <_ZN8mtlabar310BrushCache10setInitDirERKNS_6Float3E@plt>:
   75b20:      	adrp	x16, 0x7d000
   75b24:      	ldr	x17, [x16, #0x560]
   75b28:      	add	x16, x16, #0x560
   75b2c:      	br	x17

0000000000075b30 <_ZNK8mtlabar310BrushCache11getPrePointEv@plt>:
   75b30:      	adrp	x16, 0x7d000
   75b34:      	ldr	x17, [x16, #0x568]
   75b38:      	add	x16, x16, #0x568
   75b3c:      	br	x17

0000000000075b40 <_ZN8mtlabar310BrushCache11setPrePointERKNS_6Float3E@plt>:
   75b40:      	adrp	x16, 0x7d000
   75b44:      	ldr	x17, [x16, #0x570]
   75b48:      	add	x16, x16, #0x570
   75b4c:      	br	x17

0000000000075b50 <_ZNK8mtlabar310BrushCache11getCurPointEv@plt>:
   75b50:      	adrp	x16, 0x7d000
   75b54:      	ldr	x17, [x16, #0x578]
   75b58:      	add	x16, x16, #0x578
   75b5c:      	br	x17

0000000000075b60 <_ZN8mtlabar310BrushCache11setCurPointERKNS_6Float3E@plt>:
   75b60:      	adrp	x16, 0x7d000
   75b64:      	ldr	x17, [x16, #0x580]
   75b68:      	add	x16, x16, #0x580
   75b6c:      	br	x17

0000000000075b70 <_ZNK8mtlabar310BrushCache12getNextPointEv@plt>:
   75b70:      	adrp	x16, 0x7d000
   75b74:      	ldr	x17, [x16, #0x588]
   75b78:      	add	x16, x16, #0x588
   75b7c:      	br	x17

0000000000075b80 <_ZN8mtlabar310BrushCache12setNextPointERKNS_6Float3E@plt>:
   75b80:      	adrp	x16, 0x7d000
   75b84:      	ldr	x17, [x16, #0x590]
   75b88:      	add	x16, x16, #0x590
   75b8c:      	br	x17

0000000000075b90 <_ZNK8mtlabar310BrushCache12getLastPointEv@plt>:
   75b90:      	adrp	x16, 0x7d000
   75b94:      	ldr	x17, [x16, #0x598]
   75b98:      	add	x16, x16, #0x598
   75b9c:      	br	x17

0000000000075ba0 <_ZN8mtlabar310BrushCache12setLastPointERKNS_6Float3E@plt>:
   75ba0:      	adrp	x16, 0x7d000
   75ba4:      	ldr	x17, [x16, #0x5a0]
   75ba8:      	add	x16, x16, #0x5a0
   75bac:      	br	x17

0000000000075bb0 <_ZNK8mtlabar310BrushCache12getPositionsEv@plt>:
   75bb0:      	adrp	x16, 0x7d000
   75bb4:      	ldr	x17, [x16, #0x5a8]
   75bb8:      	add	x16, x16, #0x5a8
   75bbc:      	br	x17

0000000000075bc0 <_ZN8mtlabar310BrushCache12setPositionsERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   75bc0:      	adrp	x16, 0x7d000
   75bc4:      	ldr	x17, [x16, #0x5b0]
   75bc8:      	add	x16, x16, #0x5b0
   75bcc:      	br	x17

0000000000075bd0 <_ZNK8mtlabar310BrushCache13getTexCoords0Ev@plt>:
   75bd0:      	adrp	x16, 0x7d000
   75bd4:      	ldr	x17, [x16, #0x5b8]
   75bd8:      	add	x16, x16, #0x5b8
   75bdc:      	br	x17

0000000000075be0 <_ZN8mtlabar310BrushCache13setTexCoords0ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   75be0:      	adrp	x16, 0x7d000
   75be4:      	ldr	x17, [x16, #0x5c0]
   75be8:      	add	x16, x16, #0x5c0
   75bec:      	br	x17

0000000000075bf0 <_ZNK8mtlabar310BrushCache13getTexCoords1Ev@plt>:
   75bf0:      	adrp	x16, 0x7d000
   75bf4:      	ldr	x17, [x16, #0x5c8]
   75bf8:      	add	x16, x16, #0x5c8
   75bfc:      	br	x17

0000000000075c00 <_ZN8mtlabar310BrushCache13setTexCoords1ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   75c00:      	adrp	x16, 0x7d000
   75c04:      	ldr	x17, [x16, #0x5d0]
   75c08:      	add	x16, x16, #0x5d0
   75c0c:      	br	x17

0000000000075c10 <_ZNK8mtlabar310BrushCache13getTexCoords2Ev@plt>:
   75c10:      	adrp	x16, 0x7d000
   75c14:      	ldr	x17, [x16, #0x5d8]
   75c18:      	add	x16, x16, #0x5d8
   75c1c:      	br	x17

0000000000075c20 <_ZN8mtlabar310BrushCache13setTexCoords2ERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   75c20:      	adrp	x16, 0x7d000
   75c24:      	ldr	x17, [x16, #0x5e0]
   75c28:      	add	x16, x16, #0x5e0
   75c2c:      	br	x17

0000000000075c30 <_ZNK8mtlabar310BrushCache12getMixColorsEv@plt>:
   75c30:      	adrp	x16, 0x7d000
   75c34:      	ldr	x17, [x16, #0x5e8]
   75c38:      	add	x16, x16, #0x5e8
   75c3c:      	br	x17

0000000000075c40 <_ZN8mtlabar310BrushCache12setMixColorsERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   75c40:      	adrp	x16, 0x7d000
   75c44:      	ldr	x17, [x16, #0x5f0]
   75c48:      	add	x16, x16, #0x5f0
   75c4c:      	br	x17

0000000000075c50 <_ZNK8mtlabar310BrushCache15getUseArrowHeadEv@plt>:
   75c50:      	adrp	x16, 0x7d000
   75c54:      	ldr	x17, [x16, #0x5f8]
   75c58:      	add	x16, x16, #0x5f8
   75c5c:      	br	x17

0000000000075c60 <_ZN8mtlabar310BrushCache15setUseArrowHeadEb@plt>:
   75c60:      	adrp	x16, 0x7d000
   75c64:      	ldr	x17, [x16, #0x600]
   75c68:      	add	x16, x16, #0x600
   75c6c:      	br	x17

0000000000075c70 <_ZNK8mtlabar310BrushCache16getAnimationTypeEv@plt>:
   75c70:      	adrp	x16, 0x7d000
   75c74:      	ldr	x17, [x16, #0x608]
   75c78:      	add	x16, x16, #0x608
   75c7c:      	br	x17

0000000000075c80 <_ZN8mtlabar310BrushCache16setAnimationTypeENS_26MVGraffitiPenAnimationTypeE@plt>:
   75c80:      	adrp	x16, 0x7d000
   75c84:      	ldr	x17, [x16, #0x610]
   75c88:      	add	x16, x16, #0x610
   75c8c:      	br	x17

0000000000075c90 <_ZNK8mtlabar310BrushCache16getAnimationLeftEv@plt>:
   75c90:      	adrp	x16, 0x7d000
   75c94:      	ldr	x17, [x16, #0x618]
   75c98:      	add	x16, x16, #0x618
   75c9c:      	br	x17

0000000000075ca0 <_ZN8mtlabar310BrushCache16setAnimationLeftEf@plt>:
   75ca0:      	adrp	x16, 0x7d000
   75ca4:      	ldr	x17, [x16, #0x620]
   75ca8:      	add	x16, x16, #0x620
   75cac:      	br	x17

0000000000075cb0 <_ZNK8mtlabar310BrushCache15getAnimationTopEv@plt>:
   75cb0:      	adrp	x16, 0x7d000
   75cb4:      	ldr	x17, [x16, #0x628]
   75cb8:      	add	x16, x16, #0x628
   75cbc:      	br	x17

0000000000075cc0 <_ZN8mtlabar310BrushCache15setAnimationTopEf@plt>:
   75cc0:      	adrp	x16, 0x7d000
   75cc4:      	ldr	x17, [x16, #0x630]
   75cc8:      	add	x16, x16, #0x630
   75ccc:      	br	x17

0000000000075cd0 <_ZNK8mtlabar310BrushCache17getAnimationRightEv@plt>:
   75cd0:      	adrp	x16, 0x7d000
   75cd4:      	ldr	x17, [x16, #0x638]
   75cd8:      	add	x16, x16, #0x638
   75cdc:      	br	x17

0000000000075ce0 <_ZN8mtlabar310BrushCache17setAnimationRightEf@plt>:
   75ce0:      	adrp	x16, 0x7d000
   75ce4:      	ldr	x17, [x16, #0x640]
   75ce8:      	add	x16, x16, #0x640
   75cec:      	br	x17

0000000000075cf0 <_ZNK8mtlabar310BrushCache18getAnimationBottomEv@plt>:
   75cf0:      	adrp	x16, 0x7d000
   75cf4:      	ldr	x17, [x16, #0x648]
   75cf8:      	add	x16, x16, #0x648
   75cfc:      	br	x17

0000000000075d00 <_ZN8mtlabar310BrushCache18setAnimationBottomEf@plt>:
   75d00:      	adrp	x16, 0x7d000
   75d04:      	ldr	x17, [x16, #0x650]
   75d08:      	add	x16, x16, #0x650
   75d0c:      	br	x17

0000000000075d10 <_ZNK8mtlabar310BrushCache17getAnimationSpeedEv@plt>:
   75d10:      	adrp	x16, 0x7d000
   75d14:      	ldr	x17, [x16, #0x658]
   75d18:      	add	x16, x16, #0x658
   75d1c:      	br	x17

0000000000075d20 <_ZN8mtlabar310BrushCache17setAnimationSpeedEf@plt>:
   75d20:      	adrp	x16, 0x7d000
   75d24:      	ldr	x17, [x16, #0x660]
   75d28:      	add	x16, x16, #0x660
   75d2c:      	br	x17

0000000000075d30 <_ZNK8mtlabar310BrushCache14getTranslationEv@plt>:
   75d30:      	adrp	x16, 0x7d000
   75d34:      	ldr	x17, [x16, #0x668]
   75d38:      	add	x16, x16, #0x668
   75d3c:      	br	x17

0000000000075d40 <_ZN8mtlabar310BrushCache14setTranslationERKNS_6Float2E@plt>:
   75d40:      	adrp	x16, 0x7d000
   75d44:      	ldr	x17, [x16, #0x670]
   75d48:      	add	x16, x16, #0x670
   75d4c:      	br	x17

0000000000075d50 <_ZNK8mtlabar310BrushCache11getRotationEv@plt>:
   75d50:      	adrp	x16, 0x7d000
   75d54:      	ldr	x17, [x16, #0x678]
   75d58:      	add	x16, x16, #0x678
   75d5c:      	br	x17

0000000000075d60 <_ZN8mtlabar310BrushCache11setRotationEf@plt>:
   75d60:      	adrp	x16, 0x7d000
   75d64:      	ldr	x17, [x16, #0x680]
   75d68:      	add	x16, x16, #0x680
   75d6c:      	br	x17

0000000000075d70 <_ZNK8mtlabar310BrushCache8getScaleEv@plt>:
   75d70:      	adrp	x16, 0x7d000
   75d74:      	ldr	x17, [x16, #0x688]
   75d78:      	add	x16, x16, #0x688
   75d7c:      	br	x17

0000000000075d80 <_ZN8mtlabar310BrushCache8setScaleEf@plt>:
   75d80:      	adrp	x16, 0x7d000
   75d84:      	ldr	x17, [x16, #0x690]
   75d88:      	add	x16, x16, #0x690
   75d8c:      	br	x17

0000000000075d90 <_ZNK8mtlabar310BrushCache16getOriginalWidthEv@plt>:
   75d90:      	adrp	x16, 0x7d000
   75d94:      	ldr	x17, [x16, #0x698]
   75d98:      	add	x16, x16, #0x698
   75d9c:      	br	x17

0000000000075da0 <_ZN8mtlabar310BrushCache16setOriginalWidthEf@plt>:
   75da0:      	adrp	x16, 0x7d000
   75da4:      	ldr	x17, [x16, #0x6a0]
   75da8:      	add	x16, x16, #0x6a0
   75dac:      	br	x17

0000000000075db0 <_ZNK8mtlabar310BrushCache17getOriginalHeightEv@plt>:
   75db0:      	adrp	x16, 0x7d000
   75db4:      	ldr	x17, [x16, #0x6a8]
   75db8:      	add	x16, x16, #0x6a8
   75dbc:      	br	x17

0000000000075dc0 <_ZN8mtlabar310BrushCache17setOriginalHeightEf@plt>:
   75dc0:      	adrp	x16, 0x7d000
   75dc4:      	ldr	x17, [x16, #0x6b0]
   75dc8:      	add	x16, x16, #0x6b0
   75dcc:      	br	x17

0000000000075dd0 <_ZN8mtlabar320MVGraffitiPenControl19setIsInBrushDrawingEb@plt>:
   75dd0:      	adrp	x16, 0x7d000
   75dd4:      	ldr	x17, [x16, #0x6b8]
   75dd8:      	add	x16, x16, #0x6b8
   75ddc:      	br	x17

0000000000075de0 <_ZN8mtlabar320MVGraffitiPenControl14setSecondStateENS_17OnSecondEditStateE@plt>:
   75de0:      	adrp	x16, 0x7d000
   75de4:      	ldr	x17, [x16, #0x6c0]
   75de8:      	add	x16, x16, #0x6c0
   75dec:      	br	x17

0000000000075df0 <_ZN8mtlabar320MVGraffitiPenControl15setDrawingParamERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEffff@plt>:
   75df0:      	adrp	x16, 0x7d000
   75df4:      	ldr	x17, [x16, #0x6c8]
   75df8:      	add	x16, x16, #0x6c8
   75dfc:      	br	x17

0000000000075e00 <_ZN8mtlabar320MVGraffitiPenControl13setTouchParamEffNS_12OnTouchStateE@plt>:
   75e00:      	adrp	x16, 0x7d000
   75e04:      	ldr	x17, [x16, #0x6d0]
   75e08:      	add	x16, x16, #0x6d0
   75e0c:      	br	x17

0000000000075e10 <_ZNK8mtlabar320MVGraffitiPenControl13getBrushCacheEv@plt>:
   75e10:      	adrp	x16, 0x7d000
   75e14:      	ldr	x17, [x16, #0x6d8]
   75e18:      	add	x16, x16, #0x6d8
   75e1c:      	br	x17

0000000000075e20 <_ZN8mtlabar320MVGraffitiPenControl13setBrushCacheERKNSt6__ndk16vectorIPNS_10BrushCacheENS1_9allocatorIS4_EEEE@plt>:
   75e20:      	adrp	x16, 0x7d000
   75e24:      	ldr	x17, [x16, #0x6e0]
   75e28:      	add	x16, x16, #0x6e0
   75e2c:      	br	x17

0000000000075e30 <_ZNK8mtlabar320MVGraffitiPenControl23getSecondEditBrushCacheEv@plt>:
   75e30:      	adrp	x16, 0x7d000
   75e34:      	ldr	x17, [x16, #0x6e8]
   75e38:      	add	x16, x16, #0x6e8
   75e3c:      	br	x17

0000000000075e40 <_ZN8mtlabar320MVGraffitiPenControl23setSecondEditBrushCacheERKNSt6__ndk16vectorIPNS_10BrushCacheENS1_9allocatorIS4_EEEE@plt>:
   75e40:      	adrp	x16, 0x7d000
   75e44:      	ldr	x17, [x16, #0x6f0]
   75e48:      	add	x16, x16, #0x6f0
   75e4c:      	br	x17

0000000000075e50 <_ZN8mtlabar320MVGraffitiPenControl14addBrushConfigERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   75e50:      	adrp	x16, 0x7d000
   75e54:      	ldr	x17, [x16, #0x6f8]
   75e58:      	add	x16, x16, #0x6f8
   75e5c:      	br	x17

0000000000075e60 <_ZNK8mtlabar320MVGraffitiPenControl22getNullProgramBrushIdsEv@plt>:
   75e60:      	adrp	x16, 0x7d000
   75e64:      	ldr	x17, [x16, #0x700]
   75e68:      	add	x16, x16, #0x700
   75e6c:      	br	x17

0000000000075e70 <_ZNK8mtlabar312PaintControl12isInPaintingEv@plt>:
   75e70:      	adrp	x16, 0x7d000
   75e74:      	ldr	x17, [x16, #0x708]
   75e78:      	add	x16, x16, #0x708
   75e7c:      	br	x17

0000000000075e80 <_ZN8mtlabar312PaintControl8clearAllEv@plt>:
   75e80:      	adrp	x16, 0x7d000
   75e84:      	ldr	x17, [x16, #0x710]
   75e88:      	add	x16, x16, #0x710
   75e8c:      	br	x17

0000000000075e90 <_ZNK8mtlabar312PaintControl7canUndoEv@plt>:
   75e90:      	adrp	x16, 0x7d000
   75e94:      	ldr	x17, [x16, #0x718]
   75e98:      	add	x16, x16, #0x718
   75e9c:      	br	x17

0000000000075ea0 <_ZN8mtlabar312PaintControl8undoLastEv@plt>:
   75ea0:      	adrp	x16, 0x7d000
   75ea4:      	ldr	x17, [x16, #0x720]
   75ea8:      	add	x16, x16, #0x720
   75eac:      	br	x17

0000000000075eb0 <_ZN8mtlabar312PaintControl13clearUndoListEv@plt>:
   75eb0:      	adrp	x16, 0x7d000
   75eb4:      	ldr	x17, [x16, #0x728]
   75eb8:      	add	x16, x16, #0x728
   75ebc:      	br	x17

0000000000075ec0 <_ZNK8mtlabar312PaintControl7canRedoEv@plt>:
   75ec0:      	adrp	x16, 0x7d000
   75ec4:      	ldr	x17, [x16, #0x730]
   75ec8:      	add	x16, x16, #0x730
   75ecc:      	br	x17

0000000000075ed0 <_ZN8mtlabar312PaintControl8redoLastEv@plt>:
   75ed0:      	adrp	x16, 0x7d000
   75ed4:      	ldr	x17, [x16, #0x738]
   75ed8:      	add	x16, x16, #0x738
   75edc:      	br	x17

0000000000075ee0 <_ZN8mtlabar312PaintControl13clearRedoListEv@plt>:
   75ee0:      	adrp	x16, 0x7d000
   75ee4:      	ldr	x17, [x16, #0x740]
   75ee8:      	add	x16, x16, #0x740
   75eec:      	br	x17

0000000000075ef0 <_ZNK8mtlabar39ParamBase12getParamTypeEv@plt>:
   75ef0:      	adrp	x16, 0x7d000
   75ef4:      	ldr	x17, [x16, #0x748]
   75ef8:      	add	x16, x16, #0x748
   75efc:      	br	x17

0000000000075f00 <_ZNK8mtlabar39ParamBase15getParamKeyNameEv@plt>:
   75f00:      	adrp	x16, 0x7d000
   75f04:      	ldr	x17, [x16, #0x750]
   75f08:      	add	x16, x16, #0x750
   75f0c:      	br	x17

0000000000075f10 <_ZNK8mtlabar39ParamBase12getParamFlagEv@plt>:
   75f10:      	adrp	x16, 0x7d000
   75f14:      	ldr	x17, [x16, #0x758]
   75f18:      	add	x16, x16, #0x758
   75f1c:      	br	x17

0000000000075f20 <_ZNK8mtlabar39ParamBase14getChineseNameEv@plt>:
   75f20:      	adrp	x16, 0x7d000
   75f24:      	ldr	x17, [x16, #0x760]
   75f28:      	add	x16, x16, #0x760
   75f2c:      	br	x17

0000000000075f30 <_ZNK8mtlabar39ParamBase14getEnglishNameEv@plt>:
   75f30:      	adrp	x16, 0x7d000
   75f34:      	ldr	x17, [x16, #0x768]
   75f38:      	add	x16, x16, #0x768
   75f3c:      	br	x17

0000000000075f40 <_ZNK8mtlabar39ParamBase18getTraditionalNameEv@plt>:
   75f40:      	adrp	x16, 0x7d000
   75f44:      	ldr	x17, [x16, #0x770]
   75f48:      	add	x16, x16, #0x770
   75f4c:      	br	x17

0000000000075f50 <_ZNK8mtlabar39ParamBase6getKeyEv@plt>:
   75f50:      	adrp	x16, 0x7d000
   75f54:      	ldr	x17, [x16, #0x778]
   75f58:      	add	x16, x16, #0x778
   75f5c:      	br	x17

0000000000075f60 <_ZN8mtlabar310ParamColor12getColorTypeEv@plt>:
   75f60:      	adrp	x16, 0x7d000
   75f64:      	ldr	x17, [x16, #0x780]
   75f68:      	add	x16, x16, #0x780
   75f6c:      	br	x17

0000000000075f70 <_ZN8mtlabar310ParamColor8setColorENS_10ColorSpaceEfff@plt>:
   75f70:      	adrp	x16, 0x7d000
   75f74:      	ldr	x17, [x16, #0x788]
   75f78:      	add	x16, x16, #0x788
   75f7c:      	br	x17

0000000000075f80 <_ZN8mtlabar310ParamColor20setCurrentColorAlphaEf@plt>:
   75f80:      	adrp	x16, 0x7d000
   75f84:      	ldr	x17, [x16, #0x790]
   75f88:      	add	x16, x16, #0x790
   75f8c:      	br	x17

0000000000075f90 <_ZN8mtlabar310ParamColor22setCurrentColorOpacityEf@plt>:
   75f90:      	adrp	x16, 0x7d000
   75f94:      	ldr	x17, [x16, #0x798]
   75f98:      	add	x16, x16, #0x798
   75f9c:      	br	x17

0000000000075fa0 <_ZN8mtlabar310ParamColor8getColorENS_18ParamColorTypeEnumE@plt>:
   75fa0:      	adrp	x16, 0x7d000
   75fa4:      	ldr	x17, [x16, #0x7a0]
   75fa8:      	add	x16, x16, #0x7a0
   75fac:      	br	x17

0000000000075fb0 <_ZNK8mtlabar310ParamColor13getColorSpaceEv@plt>:
   75fb0:      	adrp	x16, 0x7d000
   75fb4:      	ldr	x17, [x16, #0x7a8]
   75fb8:      	add	x16, x16, #0x7a8
   75fbc:      	br	x17

0000000000075fc0 <_ZN8mtlabar310ParamColor15getCurrentAlphaEv@plt>:
   75fc0:      	adrp	x16, 0x7d000
   75fc4:      	ldr	x17, [x16, #0x7b0]
   75fc8:      	add	x16, x16, #0x7b0
   75fcc:      	br	x17

0000000000075fd0 <_ZN8mtlabar310ParamColor17getCurrentOpacityEv@plt>:
   75fd0:      	adrp	x16, 0x7d000
   75fd4:      	ldr	x17, [x16, #0x7b8]
   75fd8:      	add	x16, x16, #0x7b8
   75fdc:      	br	x17

0000000000075fe0 <_ZN8mtlabar310ParamColor20getDefaultColorValueENS_18ParamColorTypeEnumE@plt>:
   75fe0:      	adrp	x16, 0x7d000
   75fe4:      	ldr	x17, [x16, #0x7c0]
   75fe8:      	add	x16, x16, #0x7c0
   75fec:      	br	x17

0000000000075ff0 <_ZN8mtlabar310ParamColor15getDefaultAlphaEv@plt>:
   75ff0:      	adrp	x16, 0x7d000
   75ff4:      	ldr	x17, [x16, #0x7c8]
   75ff8:      	add	x16, x16, #0x7c8
   75ffc:      	br	x17

0000000000076000 <_ZN8mtlabar310ParamColor17getDefaultOpacityEv@plt>:
   76000:      	adrp	x16, 0x7d000
   76004:      	ldr	x17, [x16, #0x7d0]
   76008:      	add	x16, x16, #0x7d0
   7600c:      	br	x17

0000000000076010 <_ZN8mtlabar310ParamColor12getMaxHValueEv@plt>:
   76010:      	adrp	x16, 0x7d000
   76014:      	ldr	x17, [x16, #0x7d8]
   76018:      	add	x16, x16, #0x7d8
   7601c:      	br	x17

0000000000076020 <_ZN8mtlabar310ParamColor12getMinHValueEv@plt>:
   76020:      	adrp	x16, 0x7d000
   76024:      	ldr	x17, [x16, #0x7e0]
   76028:      	add	x16, x16, #0x7e0
   7602c:      	br	x17

0000000000076030 <_ZN8mtlabar310ParamColor8dispatchEv@plt>:
   76030:      	adrp	x16, 0x7d000
   76034:      	ldr	x17, [x16, #0x7e8]
   76038:      	add	x16, x16, #0x7e8
   7603c:      	br	x17

0000000000076040 <_ZN8mtlabar313ParamPosition17setCurrentValueXYEff@plt>:
   76040:      	adrp	x16, 0x7d000
   76044:      	ldr	x17, [x16, #0x7f0]
   76048:      	add	x16, x16, #0x7f0
   7604c:      	br	x17

0000000000076050 <_ZN8mtlabar313ParamPosition18setCurrentValueXYZEfff@plt>:
   76050:      	adrp	x16, 0x7d000
   76054:      	ldr	x17, [x16, #0x7f8]
   76058:      	add	x16, x16, #0x7f8
   7605c:      	br	x17

0000000000076060 <_ZN8mtlabar313ParamPosition19setCurrentValueXYZWEffff@plt>:
   76060:      	adrp	x16, 0x7d000
   76064:      	ldr	x17, [x16, #0x800]
   76068:      	add	x16, x16, #0x800
   7606c:      	br	x17

0000000000076070 <_ZNK8mtlabar313ParamPosition15getPositionTypeEv@plt>:
   76070:      	adrp	x16, 0x7d000
   76074:      	ldr	x17, [x16, #0x808]
   76078:      	add	x16, x16, #0x808
   7607c:      	br	x17

0000000000076080 <_ZNK8mtlabar313ParamPosition11getCurrentXEv@plt>:
   76080:      	adrp	x16, 0x7d000
   76084:      	ldr	x17, [x16, #0x810]
   76088:      	add	x16, x16, #0x810
   7608c:      	br	x17

0000000000076090 <_ZNK8mtlabar313ParamPosition11getCurrentYEv@plt>:
   76090:      	adrp	x16, 0x7d000
   76094:      	ldr	x17, [x16, #0x818]
   76098:      	add	x16, x16, #0x818
   7609c:      	br	x17

00000000000760a0 <_ZNK8mtlabar313ParamPosition11getCurrentZEv@plt>:
   760a0:      	adrp	x16, 0x7d000
   760a4:      	ldr	x17, [x16, #0x820]
   760a8:      	add	x16, x16, #0x820
   760ac:      	br	x17

00000000000760b0 <_ZNK8mtlabar313ParamPosition11getCurrentWEv@plt>:
   760b0:      	adrp	x16, 0x7d000
   760b4:      	ldr	x17, [x16, #0x828]
   760b8:      	add	x16, x16, #0x828
   760bc:      	br	x17

00000000000760c0 <_ZNK8mtlabar313ParamPosition11getDefaultXEv@plt>:
   760c0:      	adrp	x16, 0x7d000
   760c4:      	ldr	x17, [x16, #0x830]
   760c8:      	add	x16, x16, #0x830
   760cc:      	br	x17

00000000000760d0 <_ZNK8mtlabar313ParamPosition11getDefaultYEv@plt>:
   760d0:      	adrp	x16, 0x7d000
   760d4:      	ldr	x17, [x16, #0x838]
   760d8:      	add	x16, x16, #0x838
   760dc:      	br	x17

00000000000760e0 <_ZNK8mtlabar313ParamPosition11getDefaultZEv@plt>:
   760e0:      	adrp	x16, 0x7d000
   760e4:      	ldr	x17, [x16, #0x840]
   760e8:      	add	x16, x16, #0x840
   760ec:      	br	x17

00000000000760f0 <_ZNK8mtlabar313ParamPosition11getDefaultWEv@plt>:
   760f0:      	adrp	x16, 0x7d000
   760f4:      	ldr	x17, [x16, #0x848]
   760f8:      	add	x16, x16, #0x848
   760fc:      	br	x17

0000000000076100 <_ZNK8mtlabar313ParamPosition11getMaxValueEv@plt>:
   76100:      	adrp	x16, 0x7d000
   76104:      	ldr	x17, [x16, #0x850]
   76108:      	add	x16, x16, #0x850
   7610c:      	br	x17

0000000000076110 <_ZNK8mtlabar313ParamPosition11getMinValueEv@plt>:
   76110:      	adrp	x16, 0x7d000
   76114:      	ldr	x17, [x16, #0x858]
   76118:      	add	x16, x16, #0x858
   7611c:      	br	x17

0000000000076120 <_ZN8mtlabar313ParamPosition8dispatchEv@plt>:
   76120:      	adrp	x16, 0x7d000
   76124:      	ldr	x17, [x16, #0x860]
   76128:      	add	x16, x16, #0x860
   7612c:      	br	x17

0000000000076130 <_ZN8mtlabar311ParamSlider15setCurrentValueEf@plt>:
   76130:      	adrp	x16, 0x7d000
   76134:      	ldr	x17, [x16, #0x868]
   76138:      	add	x16, x16, #0x868
   7613c:      	br	x17

0000000000076140 <_ZNK8mtlabar311ParamSlider15getDefaultValueEv@plt>:
   76140:      	adrp	x16, 0x7d000
   76144:      	ldr	x17, [x16, #0x870]
   76148:      	add	x16, x16, #0x870
   7614c:      	br	x17

0000000000076150 <_ZNK8mtlabar311ParamSlider15getCurrentValueEv@plt>:
   76150:      	adrp	x16, 0x7d000
   76154:      	ldr	x17, [x16, #0x878]
   76158:      	add	x16, x16, #0x878
   7615c:      	br	x17

0000000000076160 <_ZNK8mtlabar311ParamSlider11getMaxValueEv@plt>:
   76160:      	adrp	x16, 0x7d000
   76164:      	ldr	x17, [x16, #0x880]
   76168:      	add	x16, x16, #0x880
   7616c:      	br	x17

0000000000076170 <_ZNK8mtlabar311ParamSlider11getMinValueEv@plt>:
   76170:      	adrp	x16, 0x7d000
   76174:      	ldr	x17, [x16, #0x888]
   76178:      	add	x16, x16, #0x888
   7617c:      	br	x17

0000000000076180 <_ZN8mtlabar311ParamSlider8dispatchEv@plt>:
   76180:      	adrp	x16, 0x7d000
   76184:      	ldr	x17, [x16, #0x890]
   76188:      	add	x16, x16, #0x890
   7618c:      	br	x17

0000000000076190 <_ZN8mtlabar316ParamSliderGroup15setCurrentValueEf@plt>:
   76190:      	adrp	x16, 0x7d000
   76194:      	ldr	x17, [x16, #0x898]
   76198:      	add	x16, x16, #0x898
   7619c:      	br	x17

00000000000761a0 <_ZN8mtlabar316ParamSliderGroup22setCurrentValueByIndexEif@plt>:
   761a0:      	adrp	x16, 0x7d000
   761a4:      	ldr	x17, [x16, #0x8a0]
   761a8:      	add	x16, x16, #0x8a0
   761ac:      	br	x17

00000000000761b0 <_ZNK8mtlabar316ParamSliderGroup12getGroupSizeEv@plt>:
   761b0:      	adrp	x16, 0x7d000
   761b4:      	ldr	x17, [x16, #0x8a8]
   761b8:      	add	x16, x16, #0x8a8
   761bc:      	br	x17

00000000000761c0 <_ZNK8mtlabar316ParamSliderGroup12getGroupTypeEv@plt>:
   761c0:      	adrp	x16, 0x7d000
   761c4:      	ldr	x17, [x16, #0x8b0]
   761c8:      	add	x16, x16, #0x8b0
   761cc:      	br	x17

00000000000761d0 <_ZNK8mtlabar316ParamSliderGroup15getDefaultValueEv@plt>:
   761d0:      	adrp	x16, 0x7d000
   761d4:      	ldr	x17, [x16, #0x8b8]
   761d8:      	add	x16, x16, #0x8b8
   761dc:      	br	x17

00000000000761e0 <_ZNK8mtlabar316ParamSliderGroup22getCurrentValueByIndexEi@plt>:
   761e0:      	adrp	x16, 0x7d000
   761e4:      	ldr	x17, [x16, #0x8c0]
   761e8:      	add	x16, x16, #0x8c0
   761ec:      	br	x17

00000000000761f0 <_ZNK8mtlabar316ParamSliderGroup20getCurrentValueByKeyEi@plt>:
   761f0:      	adrp	x16, 0x7d000
   761f4:      	ldr	x17, [x16, #0x8c8]
   761f8:      	add	x16, x16, #0x8c8
   761fc:      	br	x17

0000000000076200 <_ZNK8mtlabar316ParamSliderGroup11getMaxValueEv@plt>:
   76200:      	adrp	x16, 0x7d000
   76204:      	ldr	x17, [x16, #0x8d0]
   76208:      	add	x16, x16, #0x8d0
   7620c:      	br	x17

0000000000076210 <_ZNK8mtlabar316ParamSliderGroup11getMinValueEv@plt>:
   76210:      	adrp	x16, 0x7d000
   76214:      	ldr	x17, [x16, #0x8d8]
   76218:      	add	x16, x16, #0x8d8
   7621c:      	br	x17

0000000000076220 <_ZN8mtlabar316ParamSliderGroup8dispatchEv@plt>:
   76220:      	adrp	x16, 0x7d000
   76224:      	ldr	x17, [x16, #0x8e0]
   76228:      	add	x16, x16, #0x8e0
   7622c:      	br	x17

0000000000076230 <_ZN8mtlabar311ParamString15setCurrentValueERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   76230:      	adrp	x16, 0x7d000
   76234:      	ldr	x17, [x16, #0x8e8]
   76238:      	add	x16, x16, #0x8e8
   7623c:      	br	x17

0000000000076240 <_ZNK8mtlabar311ParamString15getCurrentValueEv@plt>:
   76240:      	adrp	x16, 0x7d000
   76244:      	ldr	x17, [x16, #0x8f0]
   76248:      	add	x16, x16, #0x8f0
   7624c:      	br	x17

0000000000076250 <_ZNK8mtlabar311ParamString15getDefaultValueEv@plt>:
   76250:      	adrp	x16, 0x7d000
   76254:      	ldr	x17, [x16, #0x8f8]
   76258:      	add	x16, x16, #0x8f8
   7625c:      	br	x17

0000000000076260 <_ZN8mtlabar311ParamString8dispatchEv@plt>:
   76260:      	adrp	x16, 0x7d000
   76264:      	ldr	x17, [x16, #0x900]
   76268:      	add	x16, x16, #0x900
   7626c:      	br	x17

0000000000076270 <_ZN8mtlabar311ParamSwitch15setCurrentValueEb@plt>:
   76270:      	adrp	x16, 0x7d000
   76274:      	ldr	x17, [x16, #0x908]
   76278:      	add	x16, x16, #0x908
   7627c:      	br	x17

0000000000076280 <_ZNK8mtlabar311ParamSwitch15getCurrentValueEv@plt>:
   76280:      	adrp	x16, 0x7d000
   76284:      	ldr	x17, [x16, #0x910]
   76288:      	add	x16, x16, #0x910
   7628c:      	br	x17

0000000000076290 <_ZNK8mtlabar311ParamSwitch15getDefaultValueEv@plt>:
   76290:      	adrp	x16, 0x7d000
   76294:      	ldr	x17, [x16, #0x918]
   76298:      	add	x16, x16, #0x918
   7629c:      	br	x17

00000000000762a0 <_ZN8mtlabar311ParamSwitch8dispatchEv@plt>:
   762a0:      	adrp	x16, 0x7d000
   762a4:      	ldr	x17, [x16, #0x920]
   762a8:      	add	x16, x16, #0x920
   762ac:      	br	x17

00000000000762b0 <_ZN8mtlabar310ParamTable8getParamEi@plt>:
   762b0:      	adrp	x16, 0x7d000
   762b4:      	ldr	x17, [x16, #0x928]
   762b8:      	add	x16, x16, #0x928
   762bc:      	br	x17

00000000000762c0 <_ZN8mtlabar310ParamTable13getParamByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   762c0:      	adrp	x16, 0x7d000
   762c4:      	ldr	x17, [x16, #0x930]
   762c8:      	add	x16, x16, #0x930
   762cc:      	br	x17

00000000000762d0 <_ZN8mtlabar310ParamTable14getParamByFlagENS_13ParamFlagEnumE@plt>:
   762d0:      	adrp	x16, 0x7d000
   762d4:      	ldr	x17, [x16, #0x938]
   762d8:      	add	x16, x16, #0x938
   762dc:      	br	x17

00000000000762e0 <_ZN8mtlabar310ParamTable13getParamColorEi@plt>:
   762e0:      	adrp	x16, 0x7d000
   762e4:      	ldr	x17, [x16, #0x940]
   762e8:      	add	x16, x16, #0x940
   762ec:      	br	x17

00000000000762f0 <_ZN8mtlabar310ParamTable18getParamColorByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   762f0:      	adrp	x16, 0x7d000
   762f4:      	ldr	x17, [x16, #0x948]
   762f8:      	add	x16, x16, #0x948
   762fc:      	br	x17

0000000000076300 <_ZN8mtlabar310ParamTable19getParamColorByFlagENS_13ParamFlagEnumE@plt>:
   76300:      	adrp	x16, 0x7d000
   76304:      	ldr	x17, [x16, #0x950]
   76308:      	add	x16, x16, #0x950
   7630c:      	br	x17

0000000000076310 <_ZN8mtlabar310ParamTable16getParamPositionEi@plt>:
   76310:      	adrp	x16, 0x7d000
   76314:      	ldr	x17, [x16, #0x958]
   76318:      	add	x16, x16, #0x958
   7631c:      	br	x17

0000000000076320 <_ZN8mtlabar310ParamTable21getParamPositionByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   76320:      	adrp	x16, 0x7d000
   76324:      	ldr	x17, [x16, #0x960]
   76328:      	add	x16, x16, #0x960
   7632c:      	br	x17

0000000000076330 <_ZN8mtlabar310ParamTable22getParamPositionByFlagENS_13ParamFlagEnumE@plt>:
   76330:      	adrp	x16, 0x7d000
   76334:      	ldr	x17, [x16, #0x968]
   76338:      	add	x16, x16, #0x968
   7633c:      	br	x17

0000000000076340 <_ZN8mtlabar310ParamTable14getParamSwitchEi@plt>:
   76340:      	adrp	x16, 0x7d000
   76344:      	ldr	x17, [x16, #0x970]
   76348:      	add	x16, x16, #0x970
   7634c:      	br	x17

0000000000076350 <_ZN8mtlabar310ParamTable19getParamSwitchByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   76350:      	adrp	x16, 0x7d000
   76354:      	ldr	x17, [x16, #0x978]
   76358:      	add	x16, x16, #0x978
   7635c:      	br	x17

0000000000076360 <_ZN8mtlabar310ParamTable20getParamSwitchByFlagENS_13ParamFlagEnumE@plt>:
   76360:      	adrp	x16, 0x7d000
   76364:      	ldr	x17, [x16, #0x980]
   76368:      	add	x16, x16, #0x980
   7636c:      	br	x17

0000000000076370 <_ZN8mtlabar310ParamTable14getParamStringEi@plt>:
   76370:      	adrp	x16, 0x7d000
   76374:      	ldr	x17, [x16, #0x988]
   76378:      	add	x16, x16, #0x988
   7637c:      	br	x17

0000000000076380 <_ZN8mtlabar310ParamTable19getParamStringByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   76380:      	adrp	x16, 0x7d000
   76384:      	ldr	x17, [x16, #0x990]
   76388:      	add	x16, x16, #0x990
   7638c:      	br	x17

0000000000076390 <_ZN8mtlabar310ParamTable20getParamStringByFlagENS_13ParamFlagEnumE@plt>:
   76390:      	adrp	x16, 0x7d000
   76394:      	ldr	x17, [x16, #0x998]
   76398:      	add	x16, x16, #0x998
   7639c:      	br	x17

00000000000763a0 <_ZN8mtlabar310ParamTable14getParamSliderEi@plt>:
   763a0:      	adrp	x16, 0x7d000
   763a4:      	ldr	x17, [x16, #0x9a0]
   763a8:      	add	x16, x16, #0x9a0
   763ac:      	br	x17

00000000000763b0 <_ZN8mtlabar310ParamTable19getParamSliderByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   763b0:      	adrp	x16, 0x7d000
   763b4:      	ldr	x17, [x16, #0x9a8]
   763b8:      	add	x16, x16, #0x9a8
   763bc:      	br	x17

00000000000763c0 <_ZN8mtlabar310ParamTable20getParamSliderByFlagENS_13ParamFlagEnumE@plt>:
   763c0:      	adrp	x16, 0x7d000
   763c4:      	ldr	x17, [x16, #0x9b0]
   763c8:      	add	x16, x16, #0x9b0
   763cc:      	br	x17

00000000000763d0 <_ZN8mtlabar310ParamTable19getParamSliderGroupEi@plt>:
   763d0:      	adrp	x16, 0x7d000
   763d4:      	ldr	x17, [x16, #0x9b8]
   763d8:      	add	x16, x16, #0x9b8
   763dc:      	br	x17

00000000000763e0 <_ZN8mtlabar310ParamTable24getParamSliderGroupByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   763e0:      	adrp	x16, 0x7d000
   763e4:      	ldr	x17, [x16, #0x9c0]
   763e8:      	add	x16, x16, #0x9c0
   763ec:      	br	x17

00000000000763f0 <_ZN8mtlabar310ParamTable25getParamSliderGroupByFlagENS_13ParamFlagEnumE@plt>:
   763f0:      	adrp	x16, 0x7d000
   763f4:      	ldr	x17, [x16, #0x9c8]
   763f8:      	add	x16, x16, #0x9c8
   763fc:      	br	x17

0000000000076400 <_ZN8mtlabar310ParamTable13getParamCountEv@plt>:
   76400:      	adrp	x16, 0x7d000
   76404:      	ldr	x17, [x16, #0x9d0]
   76408:      	add	x16, x16, #0x9d0
   7640c:      	br	x17

0000000000076410 <_ZN8mtlabar314ParamTableDict8getTableENS_14ParamTableEnumE@plt>:
   76410:      	adrp	x16, 0x7d000
   76414:      	ldr	x17, [x16, #0x9d8]
   76418:      	add	x16, x16, #0x9d8
   7641c:      	br	x17

0000000000076420 <_ZN8mtlabar311PartControl11getPartTypeEv@plt>:
   76420:      	adrp	x16, 0x7d000
   76424:      	ldr	x17, [x16, #0x9e0]
   76428:      	add	x16, x16, #0x9e0
   7642c:      	br	x17

0000000000076430 <_ZN8mtlabar311PartControl17getPartTypeStringEv@plt>:
   76430:      	adrp	x16, 0x7d000
   76434:      	ldr	x17, [x16, #0x9e8]
   76438:      	add	x16, x16, #0x9e8
   7643c:      	br	x17

0000000000076440 <_ZN8mtlabar311PartControl14getPartSummaryEv@plt>:
   76440:      	adrp	x16, 0x7d000
   76444:      	ldr	x17, [x16, #0x9f0]
   76448:      	add	x16, x16, #0x9f0
   7644c:      	br	x17

0000000000076450 <_ZNK8mtlabar311PartControl10getPartTagEv@plt>:
   76450:      	adrp	x16, 0x7d000
   76454:      	ldr	x17, [x16, #0x9f8]
   76458:      	add	x16, x16, #0x9f8
   7645c:      	br	x17

0000000000076460 <_ZN8mtlabar311PartControl7isErrorEv@plt>:
   76460:      	adrp	x16, 0x7d000
   76464:      	ldr	x17, [x16, #0xa00]
   76468:      	add	x16, x16, #0xa00
   7646c:      	br	x17

0000000000076470 <_ZN8mtlabar311PartControl9isAlreadyEv@plt>:
   76470:      	adrp	x16, 0x7d000
   76474:      	ldr	x17, [x16, #0xa08]
   76478:      	add	x16, x16, #0xa08
   7647c:      	br	x17

0000000000076480 <_ZN8mtlabar311PartControl12getPartLayerEv@plt>:
   76480:      	adrp	x16, 0x7d000
   76484:      	ldr	x17, [x16, #0xa10]
   76488:      	add	x16, x16, #0xa10
   7648c:      	br	x17

0000000000076490 <_ZN8mtlabar311PartControl19getPartControlLayerEv@plt>:
   76490:      	adrp	x16, 0x7d000
   76494:      	ldr	x17, [x16, #0xa18]
   76498:      	add	x16, x16, #0xa18
   7649c:      	br	x17

00000000000764a0 <_ZN8mtlabar311PartControl19setPartControlLayerEi@plt>:
   764a0:      	adrp	x16, 0x7d000
   764a4:      	ldr	x17, [x16, #0xa20]
   764a8:      	add	x16, x16, #0xa20
   764ac:      	br	x17

00000000000764b0 <_ZN8mtlabar311PartControl21getPartControlVisibleEv@plt>:
   764b0:      	adrp	x16, 0x7d000
   764b4:      	ldr	x17, [x16, #0xa28]
   764b8:      	add	x16, x16, #0xa28
   764bc:      	br	x17

00000000000764c0 <_ZN8mtlabar311PartControl21setPartControlVisibleEb@plt>:
   764c0:      	adrp	x16, 0x7d000
   764c4:      	ldr	x17, [x16, #0xa30]
   764c8:      	add	x16, x16, #0xa30
   764cc:      	br	x17

00000000000764d0 <_ZN8mtlabar311PartControl5resetEv@plt>:
   764d0:      	adrp	x16, 0x7d000
   764d4:      	ldr	x17, [x16, #0xa38]
   764d8:      	add	x16, x16, #0xa38
   764dc:      	br	x17

00000000000764e0 <_ZNK8mtlabar311PartControl7isApplyEv@plt>:
   764e0:      	adrp	x16, 0x7d000
   764e4:      	ldr	x17, [x16, #0xa40]
   764e8:      	add	x16, x16, #0xa40
   764ec:      	br	x17

00000000000764f0 <_ZN8mtlabar311PartControl8setApplyEb@plt>:
   764f0:      	adrp	x16, 0x7d000
   764f4:      	ldr	x17, [x16, #0xa48]
   764f8:      	add	x16, x16, #0xa48
   764fc:      	br	x17

0000000000076500 <_ZN8mtlabar311PartControl13getCustomNameEv@plt>:
   76500:      	adrp	x16, 0x7d000
   76504:      	ldr	x17, [x16, #0xa50]
   76508:      	add	x16, x16, #0xa50
   7650c:      	br	x17

0000000000076510 <_ZNK8mtlabar311PartControl19getCustomParamCountEv@plt>:
   76510:      	adrp	x16, 0x7d000
   76514:      	ldr	x17, [x16, #0xa58]
   76518:      	add	x16, x16, #0xa58
   7651c:      	br	x17

0000000000076520 <_ZNK8mtlabar311PartControl17getCustomParamKeyEm@plt>:
   76520:      	adrp	x16, 0x7d000
   76524:      	ldr	x17, [x16, #0xa60]
   76528:      	add	x16, x16, #0xa60
   7652c:      	br	x17

0000000000076530 <_ZNK8mtlabar311PartControl19getCustomParamValueEm@plt>:
   76530:      	adrp	x16, 0x7d000
   76534:      	ldr	x17, [x16, #0xa68]
   76538:      	add	x16, x16, #0xa68
   7653c:      	br	x17

0000000000076540 <_ZNK8mtlabar311PartControl26getCustomParamValueWithKeyEPKc@plt>:
   76540:      	adrp	x16, 0x7d000
   76544:      	ldr	x17, [x16, #0xa70]
   76548:      	add	x16, x16, #0xa70
   7654c:      	br	x17

0000000000076550 <_ZN8mtlabar311PartControl20insertCustomParamMapEPKcS2_@plt>:
   76550:      	adrp	x16, 0x7d000
   76554:      	ldr	x17, [x16, #0xa78]
   76558:      	add	x16, x16, #0xa78
   7655c:      	br	x17

0000000000076560 <_ZN8mtlabar311PartControl9getHandleEv@plt>:
   76560:      	adrp	x16, 0x7d000
   76564:      	ldr	x17, [x16, #0xa80]
   76568:      	add	x16, x16, #0xa80
   7656c:      	br	x17

0000000000076570 <_ZN8mtlabar311PartControl14getDataRequireEv@plt>:
   76570:      	adrp	x16, 0x7d000
   76574:      	ldr	x17, [x16, #0xa88]
   76578:      	add	x16, x16, #0xa88
   7657c:      	br	x17

0000000000076580 <_ZN8mtlabar311PartControl16getLayoutDetailsEv@plt>:
   76580:      	adrp	x16, 0x7d000
   76584:      	ldr	x17, [x16, #0xa90]
   76588:      	add	x16, x16, #0xa90
   7658c:      	br	x17

0000000000076590 <_ZN8mtlabar311PartControl18getMakeupControlAtEm@plt>:
   76590:      	adrp	x16, 0x7d000
   76594:      	ldr	x17, [x16, #0xa98]
   76598:      	add	x16, x16, #0xa98
   7659c:      	br	x17

00000000000765a0 <_ZN8mtlabar311PartControl20getMakeupControlSizeEv@plt>:
   765a0:      	adrp	x16, 0x7d000
   765a4:      	ldr	x17, [x16, #0xaa0]
   765a8:      	add	x16, x16, #0xaa0
   765ac:      	br	x17

00000000000765b0 <_ZN8mtlabar311PartControl19getEyeSideControlAtEm@plt>:
   765b0:      	adrp	x16, 0x7d000
   765b4:      	ldr	x17, [x16, #0xaa8]
   765b8:      	add	x16, x16, #0xaa8
   765bc:      	br	x17

00000000000765c0 <_ZN8mtlabar311PartControl21getEyeSideControlSizeEv@plt>:
   765c0:      	adrp	x16, 0x7d000
   765c4:      	ldr	x17, [x16, #0xab0]
   765c8:      	add	x16, x16, #0xab0
   765cc:      	br	x17

00000000000765d0 <_ZN8mtlabar311PartControl18getFaceliftControlEv@plt>:
   765d0:      	adrp	x16, 0x7d000
   765d4:      	ldr	x17, [x16, #0xab8]
   765d8:      	add	x16, x16, #0xab8
   765dc:      	br	x17

00000000000765e0 <_ZN8mtlabar311PartControl18getBodySlimControlEv@plt>:
   765e0:      	adrp	x16, 0x7d000
   765e4:      	ldr	x17, [x16, #0xac0]
   765e8:      	add	x16, x16, #0xac0
   765ec:      	br	x17

00000000000765f0 <_ZN8mtlabar311PartControl21getShoulderMLSControlEv@plt>:
   765f0:      	adrp	x16, 0x7d000
   765f4:      	ldr	x17, [x16, #0xac8]
   765f8:      	add	x16, x16, #0xac8
   765fc:      	br	x17

0000000000076600 <_ZN8mtlabar311PartControl19getHipDeformControlEv@plt>:
   76600:      	adrp	x16, 0x7d000
   76604:      	ldr	x17, [x16, #0xad0]
   76608:      	add	x16, x16, #0xad0
   7660c:      	br	x17

0000000000076610 <_ZN8mtlabar311PartControl18getSwanNeckControlEv@plt>:
   76610:      	adrp	x16, 0x7d000
   76614:      	ldr	x17, [x16, #0xad8]
   76618:      	add	x16, x16, #0xad8
   7661c:      	br	x17

0000000000076620 <_ZN8mtlabar311PartControl25getBodyShapingPartControlEv@plt>:
   76620:      	adrp	x16, 0x7d000
   76624:      	ldr	x17, [x16, #0xae0]
   76628:      	add	x16, x16, #0xae0
   7662c:      	br	x17

0000000000076630 <_ZN8mtlabar311PartControl16getToningControlEv@plt>:
   76630:      	adrp	x16, 0x7d000
   76634:      	ldr	x17, [x16, #0xae8]
   76638:      	add	x16, x16, #0xae8
   7663c:      	br	x17

0000000000076640 <_ZN8mtlabar311PartControl17getParamTableDictEv@plt>:
   76640:      	adrp	x16, 0x7d000
   76644:      	ldr	x17, [x16, #0xaf0]
   76648:      	add	x16, x16, #0xaf0
   7664c:      	br	x17

0000000000076650 <_ZN8mtlabar311PartControl15getHumanControlEv@plt>:
   76650:      	adrp	x16, 0x7d000
   76654:      	ldr	x17, [x16, #0xaf8]
   76658:      	add	x16, x16, #0xaf8
   7665c:      	br	x17

0000000000076660 <_ZN8mtlabar311PartControl17getStickerControlEv@plt>:
   76660:      	adrp	x16, 0x7d000
   76664:      	ldr	x17, [x16, #0xb00]
   76668:      	add	x16, x16, #0xb00
   7666c:      	br	x17

0000000000076670 <_ZN8mtlabar311PartControl23getMVBronzersPenControlEv@plt>:
   76670:      	adrp	x16, 0x7d000
   76674:      	ldr	x17, [x16, #0xb08]
   76678:      	add	x16, x16, #0xb08
   7667c:      	br	x17

0000000000076680 <_ZN8mtlabar311PartControl23getMVGraffitiPenControlEv@plt>:
   76680:      	adrp	x16, 0x7d000
   76684:      	ldr	x17, [x16, #0xb10]
   76688:      	add	x16, x16, #0xb10
   7668c:      	br	x17

0000000000076690 <_ZN8mtlabar311PartControl15getPaintControlEv@plt>:
   76690:      	adrp	x16, 0x7d000
   76694:      	ldr	x17, [x16, #0xb18]
   76698:      	add	x16, x16, #0xb18
   7669c:      	br	x17

00000000000766a0 <_ZN8mtlabar310EffectData17loadConfigurationEPKc@plt>:
   766a0:      	adrp	x16, 0x7d000
   766a4:      	ldr	x17, [x16, #0xb20]
   766a8:      	add	x16, x16, #0xb20
   766ac:      	br	x17

00000000000766b0 <_ZN8mtlabar310EffectData21loadConfigurationSyncEPKc@plt>:
   766b0:      	adrp	x16, 0x7d000
   766b4:      	ldr	x17, [x16, #0xb28]
   766b8:      	add	x16, x16, #0xb28
   766bc:      	br	x17

00000000000766c0 <_ZN8mtlabar310EffectData20parsingConfigurationEPKc@plt>:
   766c0:      	adrp	x16, 0x7d000
   766c4:      	ldr	x17, [x16, #0xb30]
   766c8:      	add	x16, x16, #0xb30
   766cc:      	br	x17

00000000000766d0 <_ZN8mtlabar310EffectData13serializationEv@plt>:
   766d0:      	adrp	x16, 0x7d000
   766d4:      	ldr	x17, [x16, #0xb38]
   766d8:      	add	x16, x16, #0xb38
   766dc:      	br	x17

00000000000766e0 <_ZNK8mtlabar310EffectData9isAlreadyEv@plt>:
   766e0:      	adrp	x16, 0x7d000
   766e4:      	ldr	x17, [x16, #0xb40]
   766e8:      	add	x16, x16, #0xb40
   766ec:      	br	x17

00000000000766f0 <_ZN8mtlabar310EffectData8setApplyEb@plt>:
   766f0:      	adrp	x16, 0x7d000
   766f4:      	ldr	x17, [x16, #0xb48]
   766f8:      	add	x16, x16, #0xb48
   766fc:      	br	x17

0000000000076700 <_ZNK8mtlabar310EffectData7isApplyEv@plt>:
   76700:      	adrp	x16, 0x7d000
   76704:      	ldr	x17, [x16, #0xb50]
   76708:      	add	x16, x16, #0xb50
   7670c:      	br	x17

0000000000076710 <_ZN8mtlabar310EffectData5resetEv@plt>:
   76710:      	adrp	x16, 0x7d000
   76714:      	ldr	x17, [x16, #0xb58]
   76718:      	add	x16, x16, #0xb58
   7671c:      	br	x17

0000000000076720 <_ZN8mtlabar310EffectData11getPlistTagEv@plt>:
   76720:      	adrp	x16, 0x7d000
   76724:      	ldr	x17, [x16, #0xb60]
   76728:      	add	x16, x16, #0xb60
   7672c:      	br	x17

0000000000076730 <_ZN8mtlabar310EffectData8setLayerEi@plt>:
   76730:      	adrp	x16, 0x7d000
   76734:      	ldr	x17, [x16, #0xb68]
   76738:      	add	x16, x16, #0xb68
   7673c:      	br	x17

0000000000076740 <_ZNK8mtlabar310EffectData8getLayerEv@plt>:
   76740:      	adrp	x16, 0x7d000
   76744:      	ldr	x17, [x16, #0xb70]
   76748:      	add	x16, x16, #0xb70
   7674c:      	br	x17

0000000000076750 <_ZNK8mtlabar310EffectData17isSpecialFaceliftEv@plt>:
   76750:      	adrp	x16, 0x7d000
   76754:      	ldr	x17, [x16, #0xb78]
   76758:      	add	x16, x16, #0xb78
   7675c:      	br	x17

0000000000076760 <_ZNK8mtlabar310EffectData15isSpecialMakeupEv@plt>:
   76760:      	adrp	x16, 0x7d000
   76764:      	ldr	x17, [x16, #0xb80]
   76768:      	add	x16, x16, #0xb80
   7676c:      	br	x17

0000000000076770 <_ZNK8mtlabar310EffectData19getCustomParamCountEv@plt>:
   76770:      	adrp	x16, 0x7d000
   76774:      	ldr	x17, [x16, #0xb88]
   76778:      	add	x16, x16, #0xb88
   7677c:      	br	x17

0000000000076780 <_ZNK8mtlabar310EffectData17getCustomParamKeyEm@plt>:
   76780:      	adrp	x16, 0x7d000
   76784:      	ldr	x17, [x16, #0xb90]
   76788:      	add	x16, x16, #0xb90
   7678c:      	br	x17

0000000000076790 <_ZNK8mtlabar310EffectData19getCustomParamValueEm@plt>:
   76790:      	adrp	x16, 0x7d000
   76794:      	ldr	x17, [x16, #0xb98]
   76798:      	add	x16, x16, #0xb98
   7679c:      	br	x17

00000000000767a0 <_ZN8mtlabar310EffectData17insertCustomParamEPKcS2_@plt>:
   767a0:      	adrp	x16, 0x7d000
   767a4:      	ldr	x17, [x16, #0xba0]
   767a8:      	add	x16, x16, #0xba0
   767ac:      	br	x17

00000000000767b0 <_ZN8mtlabar310EffectData6hasBGMEv@plt>:
   767b0:      	adrp	x16, 0x7d000
   767b4:      	ldr	x17, [x16, #0xba8]
   767b8:      	add	x16, x16, #0xba8
   767bc:      	br	x17

00000000000767c0 <_ZN8mtlabar310EffectData7playBGMEv@plt>:
   767c0:      	adrp	x16, 0x7d000
   767c4:      	ldr	x17, [x16, #0xbb0]
   767c8:      	add	x16, x16, #0xbb0
   767cc:      	br	x17

00000000000767d0 <_ZN8mtlabar310EffectData9replayBGMEv@plt>:
   767d0:      	adrp	x16, 0x7d000
   767d4:      	ldr	x17, [x16, #0xbb8]
   767d8:      	add	x16, x16, #0xbb8
   767dc:      	br	x17

00000000000767e0 <_ZN8mtlabar310EffectData8pauseBGMEv@plt>:
   767e0:      	adrp	x16, 0x7d000
   767e4:      	ldr	x17, [x16, #0xbc0]
   767e8:      	add	x16, x16, #0xbc0
   767ec:      	br	x17

00000000000767f0 <_ZN8mtlabar310EffectData7stopBGMEv@plt>:
   767f0:      	adrp	x16, 0x7d000
   767f4:      	ldr	x17, [x16, #0xbc8]
   767f8:      	add	x16, x16, #0xbc8
   767fc:      	br	x17

0000000000076800 <_ZN8mtlabar310EffectData7seekBGMEf@plt>:
   76800:      	adrp	x16, 0x7d000
   76804:      	ldr	x17, [x16, #0xbd0]
   76808:      	add	x16, x16, #0xbd0
   7680c:      	br	x17

0000000000076810 <_ZN8mtlabar310EffectData14getBGMPositionEv@plt>:
   76810:      	adrp	x16, 0x7d000
   76814:      	ldr	x17, [x16, #0xbd8]
   76818:      	add	x16, x16, #0xbd8
   7681c:      	br	x17

0000000000076820 <_ZN8mtlabar310EffectData10setBGMPathEPKc@plt>:
   76820:      	adrp	x16, 0x7d000
   76824:      	ldr	x17, [x16, #0xbe0]
   76828:      	add	x16, x16, #0xbe0
   7682c:      	br	x17

0000000000076830 <_ZN8mtlabar310EffectData10getBGMPathEv@plt>:
   76830:      	adrp	x16, 0x7d000
   76834:      	ldr	x17, [x16, #0xbe8]
   76838:      	add	x16, x16, #0xbe8
   7683c:      	br	x17

0000000000076840 <_ZN8mtlabar310EffectData16getConfigBGMPathEv@plt>:
   76840:      	adrp	x16, 0x7d000
   76844:      	ldr	x17, [x16, #0xbf0]
   76848:      	add	x16, x16, #0xbf0
   7684c:      	br	x17

0000000000076850 <_ZNK8mtlabar310EffectData16getAIConfigCountEv@plt>:
   76850:      	adrp	x16, 0x7d000
   76854:      	ldr	x17, [x16, #0xbf8]
   76858:      	add	x16, x16, #0xbf8
   7685c:      	br	x17

0000000000076860 <_ZNK8mtlabar310EffectData11getAIConfigEm@plt>:
   76860:      	adrp	x16, 0x7d000
   76864:      	ldr	x17, [x16, #0xc00]
   76868:      	add	x16, x16, #0xc00
   7686c:      	br	x17

0000000000076870 <_ZNK8mtlabar310EffectData19getPartControlCountEv@plt>:
   76870:      	adrp	x16, 0x7d000
   76874:      	ldr	x17, [x16, #0xc08]
   76878:      	add	x16, x16, #0xc08
   7687c:      	br	x17

0000000000076880 <_ZNK8mtlabar310EffectData14getPartControlEm@plt>:
   76880:      	adrp	x16, 0x7d000
   76884:      	ldr	x17, [x16, #0xc10]
   76888:      	add	x16, x16, #0xc10
   7688c:      	br	x17

0000000000076890 <_ZNK8mtlabar310EffectData29getReplaceSpecialFaceliftTypeEv@plt>:
   76890:      	adrp	x16, 0x7d000
   76894:      	ldr	x17, [x16, #0xc18]
   76898:      	add	x16, x16, #0xc18
   7689c:      	br	x17

00000000000768a0 <_ZN8mtlabar310EffectData15applyGlobalJsonEPKc@plt>:
   768a0:      	adrp	x16, 0x7d000
   768a4:      	ldr	x17, [x16, #0xc20]
   768a8:      	add	x16, x16, #0xc20
   768ac:      	br	x17

00000000000768b0 <_ZN8mtlabar313GlobalSetting10globalInitEv@plt>:
   768b0:      	adrp	x16, 0x7d000
   768b4:      	ldr	x17, [x16, #0xc28]
   768b8:      	add	x16, x16, #0xc28
   768bc:      	br	x17

00000000000768c0 <_ZN8mtlabar313GlobalSetting18setVisualAllocatorEPNS_15VisualAllocatorE@plt>:
   768c0:      	adrp	x16, 0x7d000
   768c4:      	ldr	x17, [x16, #0xc30]
   768c8:      	add	x16, x16, #0xc30
   768cc:      	br	x17

00000000000768d0 <_ZNK8mtlabar313GlobalSetting18getVisualAllocatorEv@plt>:
   768d0:      	adrp	x16, 0x7d000
   768d4:      	ldr	x17, [x16, #0xc38]
   768d8:      	add	x16, x16, #0xc38
   768dc:      	br	x17

00000000000768e0 <_ZN8mtlabar313GlobalSetting15mountFileSystemEPKcPNS_17VirtualFileSystemE@plt>:
   768e0:      	adrp	x16, 0x7d000
   768e4:      	ldr	x17, [x16, #0xc40]
   768e8:      	add	x16, x16, #0xc40
   768ec:      	br	x17

00000000000768f0 <_ZN8mtlabar313GlobalSetting17unmountFileSystemEPKc@plt>:
   768f0:      	adrp	x16, 0x7d000
   768f4:      	ldr	x17, [x16, #0xc48]
   768f8:      	add	x16, x16, #0xc48
   768fc:      	br	x17

0000000000076900 <_ZN8mtlabar313GlobalSetting12setDirectoryENS_13DirectoryTypeEPKc@plt>:
   76900:      	adrp	x16, 0x7d000
   76904:      	ldr	x17, [x16, #0xc50]
   76908:      	add	x16, x16, #0xc50
   7690c:      	br	x17

0000000000076910 <_ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE@plt>:
   76910:      	adrp	x16, 0x7d000
   76914:      	ldr	x17, [x16, #0xc58]
   76918:      	add	x16, x16, #0xc58
   7691c:      	br	x17

0000000000076920 <_ZN8mtlabar313GlobalSetting14setAIModelPathENS_11AIModelTypeEPKc@plt>:
   76920:      	adrp	x16, 0x7d000
   76924:      	ldr	x17, [x16, #0xc60]
   76928:      	add	x16, x16, #0xc60
   7692c:      	br	x17

0000000000076930 <_ZN8mtlabar313GlobalSetting14getAIModelPathENS_11AIModelTypeE@plt>:
   76930:      	adrp	x16, 0x7d000
   76934:      	ldr	x17, [x16, #0xc68]
   76938:      	add	x16, x16, #0xc68
   7693c:      	br	x17

0000000000076940 <_ZN8mtlabar313GlobalSetting14setRuntimeTypeENS_11RuntimeTypeE@plt>:
   76940:      	adrp	x16, 0x7d000
   76944:      	ldr	x17, [x16, #0xc70]
   76948:      	add	x16, x16, #0xc70
   7694c:      	br	x17

0000000000076950 <_ZN8mtlabar313GlobalSetting14getRuntimeTypeEv@plt>:
   76950:      	adrp	x16, 0x7d000
   76954:      	ldr	x17, [x16, #0xc78]
   76958:      	add	x16, x16, #0xc78
   7695c:      	br	x17

0000000000076960 <_ZN8mtlabar313GlobalSetting14setLogCallbackEPNS_11LogCallbackE@plt>:
   76960:      	adrp	x16, 0x7d000
   76964:      	ldr	x17, [x16, #0xc80]
   76968:      	add	x16, x16, #0xc80
   7696c:      	br	x17

0000000000076970 <_ZN8mtlabar313GlobalSetting9setJavaVMEP7_JavaVM@plt>:
   76970:      	adrp	x16, 0x7d000
   76974:      	ldr	x17, [x16, #0xc88]
   76978:      	add	x16, x16, #0xc88
   7697c:      	br	x17

0000000000076980 <_ZN8mtlabar313GlobalSetting17setAndroidContextEP8_jobject@plt>:
   76980:      	adrp	x16, 0x7d000
   76984:      	ldr	x17, [x16, #0xc90]
   76988:      	add	x16, x16, #0xc90
   7698c:      	br	x17

0000000000076990 <_ZN8mtlabar313GlobalSetting17startSoundServiceEv@plt>:
   76990:      	adrp	x16, 0x7d000
   76994:      	ldr	x17, [x16, #0xc98]
   76998:      	add	x16, x16, #0xc98
   7699c:      	br	x17

00000000000769a0 <_ZN8mtlabar313GlobalSetting17pauseSoundServiceEb@plt>:
   769a0:      	adrp	x16, 0x7d000
   769a4:      	ldr	x17, [x16, #0xca0]
   769a8:      	add	x16, x16, #0xca0
   769ac:      	br	x17

00000000000769b0 <_ZN8mtlabar313GlobalSetting16stopSoundServiceEv@plt>:
   769b0:      	adrp	x16, 0x7d000
   769b4:      	ldr	x17, [x16, #0xca8]
   769b8:      	add	x16, x16, #0xca8
   769bc:      	br	x17

00000000000769c0 <_ZN8mtlabar313GlobalSetting20isStopedSoundServiceEv@plt>:
   769c0:      	adrp	x16, 0x7d000
   769c4:      	ldr	x17, [x16, #0xcb0]
   769c8:      	add	x16, x16, #0xcb0
   769cc:      	br	x17

00000000000769d0 <_ZN8mtlabar313GlobalSetting12registerFontEPKcS2_@plt>:
   769d0:      	adrp	x16, 0x7d000
   769d4:      	ldr	x17, [x16, #0xcb8]
   769d8:      	add	x16, x16, #0xcb8
   769dc:      	br	x17

00000000000769e0 <_ZN8mtlabar313GlobalSetting14unregisterFontEPKc@plt>:
   769e0:      	adrp	x16, 0x7d000
   769e4:      	ldr	x17, [x16, #0xcc0]
   769e8:      	add	x16, x16, #0xcc0
   769ec:      	br	x17

00000000000769f0 <_ZN8mtlabar313GlobalSetting22registerBoldFontFamilyEPKcS2_@plt>:
   769f0:      	adrp	x16, 0x7d000
   769f4:      	ldr	x17, [x16, #0xcc8]
   769f8:      	add	x16, x16, #0xcc8
   769fc:      	br	x17

0000000000076a00 <_ZN8mtlabar313GlobalSetting13getFontFamilyEPKc@plt>:
   76a00:      	adrp	x16, 0x7d000
   76a04:      	ldr	x17, [x16, #0xcd0]
   76a08:      	add	x16, x16, #0xcd0
   76a0c:      	br	x17

0000000000076a10 <_ZN8mtlabar313GlobalSetting13getSDKVersionEv@plt>:
   76a10:      	adrp	x16, 0x7d000
   76a14:      	ldr	x17, [x16, #0xcd8]
   76a18:      	add	x16, x16, #0xcd8
   76a1c:      	br	x17

0000000000076a20 <_ZN8mtlabar313GlobalSetting20getSDKReleaseVersionEv@plt>:
   76a20:      	adrp	x16, 0x7d000
   76a24:      	ldr	x17, [x16, #0xce0]
   76a28:      	add	x16, x16, #0xce0
   76a2c:      	br	x17

0000000000076a30 <_ZN8mtlabar39Interface28loadPublicParamConfigurationEPKc@plt>:
   76a30:      	adrp	x16, 0x7d000
   76a34:      	ldr	x17, [x16, #0xce8]
   76a38:      	add	x16, x16, #0xce8
   76a3c:      	br	x17

0000000000076a40 <_ZN8mtlabar39Interface32loadPublicParamConfigurationSyncEPKc@plt>:
   76a40:      	adrp	x16, 0x7d000
   76a44:      	ldr	x17, [x16, #0xcf0]
   76a48:      	add	x16, x16, #0xcf0
   76a4c:      	br	x17

0000000000076a50 <_ZN8mtlabar39Interface11createEmptyEv@plt>:
   76a50:      	adrp	x16, 0x7d000
   76a54:      	ldr	x17, [x16, #0xcf8]
   76a58:      	add	x16, x16, #0xcf8
   76a5c:      	br	x17

0000000000076a60 <_ZN8mtlabar39Interface21createExternalFromPtrEPv@plt>:
   76a60:      	adrp	x16, 0x7d000
   76a64:      	ldr	x17, [x16, #0xd00]
   76a68:      	add	x16, x16, #0xd00
   76a6c:      	br	x17

0000000000076a70 <_ZN8mtlabar39Interface17loadConfigurationEPKc@plt>:
   76a70:      	adrp	x16, 0x7d000
   76a74:      	ldr	x17, [x16, #0xd08]
   76a78:      	add	x16, x16, #0xd08
   76a7c:      	br	x17

0000000000076a80 <_ZN8mtlabar39Interface21loadConfigurationSyncEPKc@plt>:
   76a80:      	adrp	x16, 0x7d000
   76a84:      	ldr	x17, [x16, #0xd10]
   76a88:      	add	x16, x16, #0xd10
   76a8c:      	br	x17

0000000000076a90 <_ZN8mtlabar39Interface20parsingConfigurationEPKc@plt>:
   76a90:      	adrp	x16, 0x7d000
   76a94:      	ldr	x17, [x16, #0xd18]
   76a98:      	add	x16, x16, #0xd18
   76a9c:      	br	x17

0000000000076aa0 <_ZN8mtlabar39Interface19deleteConfigurationEPNS_10EffectDataE@plt>:
   76aa0:      	adrp	x16, 0x7d000
   76aa4:      	ldr	x17, [x16, #0xd20]
   76aa8:      	add	x16, x16, #0xd20
   76aac:      	br	x17

0000000000076ab0 <_ZN8mtlabar39Interface21addEffectDataListenerEPNS_18EffectDataListenerE@plt>:
   76ab0:      	adrp	x16, 0x7d000
   76ab4:      	ldr	x17, [x16, #0xd28]
   76ab8:      	add	x16, x16, #0xd28
   76abc:      	br	x17

0000000000076ac0 <_ZN8mtlabar39Interface21delEffectDataListenerEPNS_18EffectDataListenerE@plt>:
   76ac0:      	adrp	x16, 0x7d000
   76ac4:      	ldr	x17, [x16, #0xd30]
   76ac8:      	add	x16, x16, #0xd30
   76acc:      	br	x17

0000000000076ad0 <_ZN8mtlabar39Interface25setExternalFunctionStructEPNS_24ExternalFunctionCallbackE@plt>:
   76ad0:      	adrp	x16, 0x7d000
   76ad4:      	ldr	x17, [x16, #0xd38]
   76ad8:      	add	x16, x16, #0xd38
   76adc:      	br	x17

0000000000076ae0 <_ZN8mtlabar39Interface21setDrawFunctionStructEPNS_20DrawFunctionCallbackE@plt>:
   76ae0:      	adrp	x16, 0x7d000
   76ae4:      	ldr	x17, [x16, #0xd40]
   76ae8:      	add	x16, x16, #0xd40
   76aec:      	br	x17

0000000000076af0 <_ZN8mtlabar39Interface11addListenerEPNS_17InterfaceListenerE@plt>:
   76af0:      	adrp	x16, 0x7d000
   76af4:      	ldr	x17, [x16, #0xd48]
   76af8:      	add	x16, x16, #0xd48
   76afc:      	br	x17

0000000000076b00 <_ZN8mtlabar39Interface11delListenerEPNS_17InterfaceListenerE@plt>:
   76b00:      	adrp	x16, 0x7d000
   76b04:      	ldr	x17, [x16, #0xd50]
   76b08:      	add	x16, x16, #0xd50
   76b0c:      	br	x17

0000000000076b10 <_ZN8mtlabar39Interface17getTotalFaceStateEv@plt>:
   76b10:      	adrp	x16, 0x7d000
   76b14:      	ldr	x17, [x16, #0xd58]
   76b18:      	add	x16, x16, #0xd58
   76b1c:      	br	x17

0000000000076b20 <_ZN8mtlabar39Interface30setNativeRuntimeModifyFaceDataEPKNS_17FaceDataInterfaceE@plt>:
   76b20:      	adrp	x16, 0x7d000
   76b24:      	ldr	x17, [x16, #0xd60]
   76b28:      	add	x16, x16, #0xd60
   76b2c:      	br	x17

0000000000076b30 <_ZN8mtlabar39Interface30getNativeRuntimeModifyFaceDataEv@plt>:
   76b30:      	adrp	x16, 0x7d000
   76b34:      	ldr	x17, [x16, #0xd68]
   76b38:      	add	x16, x16, #0xd68
   76b3c:      	br	x17

0000000000076b40 <_ZN8mtlabar39Interface27transferFaceliftOffsetPointEPKfPfjj@plt>:
   76b40:      	adrp	x16, 0x7d000
   76b44:      	ldr	x17, [x16, #0xd70]
   76b48:      	add	x16, x16, #0xd70
   76b4c:      	br	x17

0000000000076b50 <_ZNK8mtlabar39Interface14getMemoryUsageEv@plt>:
   76b50:      	adrp	x16, 0x7d000
   76b54:      	ldr	x17, [x16, #0xd78]
   76b58:      	add	x16, x16, #0xd78
   76b5c:      	br	x17

0000000000076b60 <_ZNK8mtlabar39Interface9debugDumpEv@plt>:
   76b60:      	adrp	x16, 0x7d000
   76b64:      	ldr	x17, [x16, #0xd80]
   76b68:      	add	x16, x16, #0xd80
   76b6c:      	br	x17

0000000000076b70 <_ZN8mtlabar39Interface13setRandomSeedEm@plt>:
   76b70:      	adrp	x16, 0x7d000
   76b74:      	ldr	x17, [x16, #0xd88]
   76b78:      	add	x16, x16, #0xd88
   76b7c:      	br	x17

0000000000076b80 <_ZN8mtlabar39Interface13voidOperationENS_17VoidOperationTypeE@plt>:
   76b80:      	adrp	x16, 0x7d000
   76b84:      	ldr	x17, [x16, #0xd90]
   76b88:      	add	x16, x16, #0xd90
   76b8c:      	br	x17

0000000000076b90 <_ZN8mtlabar39Interface9setOptionENS_10OptionTypeEb@plt>:
   76b90:      	adrp	x16, 0x7d000
   76b94:      	ldr	x17, [x16, #0xd98]
   76b98:      	add	x16, x16, #0xd98
   76b9c:      	br	x17

0000000000076ba0 <_ZN8mtlabar39Interface9getOptionENS_10OptionTypeE@plt>:
   76ba0:      	adrp	x16, 0x7d000
   76ba4:      	ldr	x17, [x16, #0xda0]
   76ba8:      	add	x16, x16, #0xda0
   76bac:      	br	x17

0000000000076bb0 <_ZN8mtlabar39Interface14setMusicVolumeEf@plt>:
   76bb0:      	adrp	x16, 0x7d000
   76bb4:      	ldr	x17, [x16, #0xda8]
   76bb8:      	add	x16, x16, #0xda8
   76bbc:      	br	x17

0000000000076bc0 <_ZN8mtlabar39Interface12onTouchBeginEffi@plt>:
   76bc0:      	adrp	x16, 0x7d000
   76bc4:      	ldr	x17, [x16, #0xdb0]
   76bc8:      	add	x16, x16, #0xdb0
   76bcc:      	br	x17

0000000000076bd0 <_ZN8mtlabar39Interface11onTouchMoveEffi@plt>:
   76bd0:      	adrp	x16, 0x7d000
   76bd4:      	ldr	x17, [x16, #0xdb8]
   76bd8:      	add	x16, x16, #0xdb8
   76bdc:      	br	x17

0000000000076be0 <_ZN8mtlabar39Interface10onTouchEndEffi@plt>:
   76be0:      	adrp	x16, 0x7d000
   76be4:      	ldr	x17, [x16, #0xdc0]
   76be8:      	add	x16, x16, #0xdc0
   76bec:      	br	x17

0000000000076bf0 <_ZN8mtlabar39Interface5onKeyEi@plt>:
   76bf0:      	adrp	x16, 0x7d000
   76bf4:      	ldr	x17, [x16, #0xdc8]
   76bf8:      	add	x16, x16, #0xdc8
   76bfc:      	br	x17

0000000000076c00 <_ZN8mtlabar39Interface16onUTF8CharactersEPKc@plt>:
   76c00:      	adrp	x16, 0x7d000
   76c04:      	ldr	x17, [x16, #0xdd0]
   76c08:      	add	x16, x16, #0xdd0
   76c0c:      	br	x17

0000000000076c10 <_ZN8mtlabar39Interface11postMessageEPKcS2_b@plt>:
   76c10:      	adrp	x16, 0x7d000
   76c14:      	ldr	x17, [x16, #0xdd8]
   76c18:      	add	x16, x16, #0xdd8
   76c1c:      	br	x17

0000000000076c20 <_ZN8mtlabar39Interface14getDataRequireEv@plt>:
   76c20:      	adrp	x16, 0x7d000
   76c24:      	ldr	x17, [x16, #0xde0]
   76c28:      	add	x16, x16, #0xde0
   76c2c:      	br	x17

0000000000076c30 <_ZN8mtlabar39Interface12setFrameDataEPNS_18FrameDataInterfaceE@plt>:
   76c30:      	adrp	x16, 0x7d000
   76c34:      	ldr	x17, [x16, #0xde8]
   76c38:      	add	x16, x16, #0xde8
   76c3c:      	br	x17

0000000000076c40 <_ZN8mtlabar39Interface24setTimeLineDataInterfaceEPNS_21TimeLineDataInterfaceE@plt>:
   76c40:      	adrp	x16, 0x7d000
   76c44:      	ldr	x17, [x16, #0xdf0]
   76c48:      	add	x16, x16, #0xdf0
   76c4c:      	br	x17

0000000000076c50 <_ZN8mtlabar39Interface8dispatchEv@plt>:
   76c50:      	adrp	x16, 0x7d000
   76c54:      	ldr	x17, [x16, #0xdf8]
   76c58:      	add	x16, x16, #0xdf8
   76c5c:      	br	x17

0000000000076c60 <_ZN8mtlabar39Interface6renderEv@plt>:
   76c60:      	adrp	x16, 0x7d000
   76c64:      	ldr	x17, [x16, #0xe00]
   76c68:      	add	x16, x16, #0xe00
   76c6c:      	br	x17

0000000000076c70 <_ZN8mtlabar39Interface10clearCacheEv@plt>:
   76c70:      	adrp	x16, 0x7d000
   76c74:      	ldr	x17, [x16, #0xe08]
   76c78:      	add	x16, x16, #0xe08
   76c7c:      	br	x17

0000000000076c80 <_ZN8mtlabar39Interface12isATheLatestEv@plt>:
   76c80:      	adrp	x16, 0x7d000
   76c84:      	ldr	x17, [x16, #0xe10]
   76c88:      	add	x16, x16, #0xe10
   76c8c:      	br	x17

0000000000076c90 <_ZNK8mtlabar39Interface24getLoadedPartControlSizeEv@plt>:
   76c90:      	adrp	x16, 0x7d000
   76c94:      	ldr	x17, [x16, #0xe18]
   76c98:      	add	x16, x16, #0xe18
   76c9c:      	br	x17

0000000000076ca0 <_ZNK8mtlabar39Interface20getLoadedPartControlEm@plt>:
   76ca0:      	adrp	x16, 0x7d000
   76ca4:      	ldr	x17, [x16, #0xe20]
   76ca8:      	add	x16, x16, #0xe20
   76cac:      	br	x17

0000000000076cb0 <_ZN8mtlabar313MainInterface6createEP14WGPUDeviceImplj@plt>:
   76cb0:      	adrp	x16, 0x7d000
   76cb4:      	ldr	x17, [x16, #0xe28]
   76cb8:      	add	x16, x16, #0xe28
   76cbc:      	br	x17

0000000000076cc0 <_ZN8mtlabar313MainInterface7destroyEPS0_@plt>:
   76cc0:      	adrp	x16, 0x7d000
   76cc4:      	ldr	x17, [x16, #0xe30]
   76cc8:      	add	x16, x16, #0xe30
   76ccc:      	br	x17

0000000000076cd0 <_ZN8mtlabar313MainInterface15createInterfaceEv@plt>:
   76cd0:      	adrp	x16, 0x7d000
   76cd4:      	ldr	x17, [x16, #0xe38]
   76cd8:      	add	x16, x16, #0xe38
   76cdc:      	br	x17

0000000000076ce0 <_ZN8mtlabar313MainInterface29createInterfaceWithColorSpaceENS_10ColorSpaceE@plt>:
   76ce0:      	adrp	x16, 0x7d000
   76ce4:      	ldr	x17, [x16, #0xe40]
   76ce8:      	add	x16, x16, #0xe40
   76cec:      	br	x17

0000000000076cf0 <_ZN8mtlabar313MainInterface16destroyInterfaceEPNS_9InterfaceE@plt>:
   76cf0:      	adrp	x16, 0x7d000
   76cf4:      	ldr	x17, [x16, #0xe48]
   76cf8:      	add	x16, x16, #0xe48
   76cfc:      	br	x17

0000000000076d00 <_ZN8mtlabar313MainInterface24createFrameDataInterfaceEv@plt>:
   76d00:      	adrp	x16, 0x7d000
   76d04:      	ldr	x17, [x16, #0xe50]
   76d08:      	add	x16, x16, #0xe50
   76d0c:      	br	x17

0000000000076d10 <_ZN8mtlabar313MainInterface25destroyFrameDataInterfaceEPNS_18FrameDataInterfaceE@plt>:
   76d10:      	adrp	x16, 0x7d000
   76d14:      	ldr	x17, [x16, #0xe58]
   76d18:      	add	x16, x16, #0xe58
   76d1c:      	br	x17

0000000000076d20 <_ZN8mtlabar313MainInterface23getInteractionInterfaceEv@plt>:
   76d20:      	adrp	x16, 0x7d000
   76d24:      	ldr	x17, [x16, #0xe60]
   76d28:      	add	x16, x16, #0xe60
   76d2c:      	br	x17

0000000000076d30 <_ZN8mtlabar313MainInterface10clearCacheEv@plt>:
   76d30:      	adrp	x16, 0x7d000
   76d34:      	ldr	x17, [x16, #0xe68]
   76d38:      	add	x16, x16, #0xe68
   76d3c:      	br	x17

0000000000076d40 <_ZN8mtlabar38Graphics16createWithOpenGLEv@plt>:
   76d40:      	adrp	x16, 0x7d000
   76d44:      	ldr	x17, [x16, #0xe70]
   76d48:      	add	x16, x16, #0xe70
   76d4c:      	br	x17

0000000000076d50 <_ZN8mtlabar38Graphics15createWithMetalEPv@plt>:
   76d50:      	adrp	x16, 0x7d000
   76d54:      	ldr	x17, [x16, #0xe78]
   76d58:      	add	x16, x16, #0xe78
   76d5c:      	br	x17

0000000000076d60 <_ZN8mtlabar38Graphics23createWithMetalAndQueueEPvS1_@plt>:
   76d60:      	adrp	x16, 0x7d000
   76d64:      	ldr	x17, [x16, #0xe80]
   76d68:      	add	x16, x16, #0xe80
   76d6c:      	br	x17

0000000000076d70 <_ZN8mtlabar38Graphics15createWithD3D11EPv@plt>:
   76d70:      	adrp	x16, 0x7d000
   76d74:      	ldr	x17, [x16, #0xe88]
   76d78:      	add	x16, x16, #0xe88
   76d7c:      	br	x17

0000000000076d80 <_ZN8mtlabar38Graphics7destroyEPS0_@plt>:
   76d80:      	adrp	x16, 0x7d000
   76d84:      	ldr	x17, [x16, #0xe90]
   76d88:      	add	x16, x16, #0xe90
   76d8c:      	br	x17

0000000000076d90 <_ZN8mtlabar38Graphics9getDeviceEv@plt>:
   76d90:      	adrp	x16, 0x7d000
   76d94:      	ldr	x17, [x16, #0xe98]
   76d98:      	add	x16, x16, #0xe98
   76d9c:      	br	x17

0000000000076da0 <_ZN8mtlabar38Graphics23createTextureWithOpenGLEmjj@plt>:
   76da0:      	adrp	x16, 0x7d000
   76da4:      	ldr	x17, [x16, #0xea0]
   76da8:      	add	x16, x16, #0xea0
   76dac:      	br	x17

0000000000076db0 <_ZN8mtlabar38Graphics15getOpenGLHandleEP15WGPUTextureImpl@plt>:
   76db0:      	adrp	x16, 0x7d000
   76db4:      	ldr	x17, [x16, #0xea8]
   76db8:      	add	x16, x16, #0xea8
   76dbc:      	br	x17

0000000000076dc0 <_ZN8mtlabar38Graphics22createTextureWithMetalEPvjj@plt>:
   76dc0:      	adrp	x16, 0x7d000
   76dc4:      	ldr	x17, [x16, #0xeb0]
   76dc8:      	add	x16, x16, #0xeb0
   76dcc:      	br	x17

0000000000076dd0 <_ZN8mtlabar38Graphics14getMetalHandleEP15WGPUTextureImpl@plt>:
   76dd0:      	adrp	x16, 0x7d000
   76dd4:      	ldr	x17, [x16, #0xeb8]
   76dd8:      	add	x16, x16, #0xeb8
   76ddc:      	br	x17

0000000000076de0 <_ZN8mtlabar38Graphics29createTextureWithOpenGLFormatEmjjj@plt>:
   76de0:      	adrp	x16, 0x7d000
   76de4:      	ldr	x17, [x16, #0xec0]
   76de8:      	add	x16, x16, #0xec0
   76dec:      	br	x17

0000000000076df0 <_ZN8mtlabar38Graphics14getD3D11HandleEP15WGPUTextureImpl@plt>:
   76df0:      	adrp	x16, 0x7d000
   76df4:      	ldr	x17, [x16, #0xec8]
   76df8:      	add	x16, x16, #0xec8
   76dfc:      	br	x17

0000000000076e00 <_ZN8mtlabar38Graphics22createTextureWithD3D11EPv@plt>:
   76e00:      	adrp	x16, 0x7d000
   76e04:      	ldr	x17, [x16, #0xed0]
   76e08:      	add	x16, x16, #0xed0
   76e0c:      	br	x17

0000000000076e10 <_ZN8mtlabar38Graphics24createWithDefaultBackendEv@plt>:
   76e10:      	adrp	x16, 0x7d000
   76e14:      	ldr	x17, [x16, #0xed8]
   76e18:      	add	x16, x16, #0xed8
   76e1c:      	br	x17

0000000000076e20 <fprintf@plt>:
   76e20:      	adrp	x16, 0x7d000
   76e24:      	ldr	x17, [x16, #0xee0]
   76e28:      	add	x16, x16, #0xee0
   76e2c:      	br	x17

0000000000076e30 <__cxa_begin_catch@plt>:
   76e30:      	adrp	x16, 0x7d000
   76e34:      	ldr	x17, [x16, #0xee8]
   76e38:      	add	x16, x16, #0xee8
   76e3c:      	br	x17

0000000000076e40 <_ZSt9terminatev@plt>:
   76e40:      	adrp	x16, 0x7d000
   76e44:      	ldr	x17, [x16, #0xef0]
   76e48:      	add	x16, x16, #0xef0
   76e4c:      	br	x17

0000000000076e50 <__cxa_allocate_exception@plt>:
   76e50:      	adrp	x16, 0x7d000
   76e54:      	ldr	x17, [x16, #0xef8]
   76e58:      	add	x16, x16, #0xef8
   76e5c:      	br	x17

0000000000076e60 <__cxa_throw@plt>:
   76e60:      	adrp	x16, 0x7d000
   76e64:      	ldr	x17, [x16, #0xf00]
   76e68:      	add	x16, x16, #0xf00
   76e6c:      	br	x17

0000000000076e70 <__cxa_free_exception@plt>:
   76e70:      	adrp	x16, 0x7d000
   76e74:      	ldr	x17, [x16, #0xf08]
   76e78:      	add	x16, x16, #0xf08
   76e7c:      	br	x17

0000000000076e80 <_ZNSt11logic_errorC2EPKc@plt>:
   76e80:      	adrp	x16, 0x7d000
   76e84:      	ldr	x17, [x16, #0xf10]
   76e88:      	add	x16, x16, #0xf10
   76e8c:      	br	x17

0000000000076e90 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   76e90:      	adrp	x16, 0x7d000
   76e94:      	ldr	x17, [x16, #0xf18]
   76e98:      	add	x16, x16, #0xf18
   76e9c:      	br	x17

0000000000076ea0 <fflush@plt>:
   76ea0:      	adrp	x16, 0x7d000
   76ea4:      	ldr	x17, [x16, #0xf20]
   76ea8:      	add	x16, x16, #0xf20
   76eac:      	br	x17

0000000000076eb0 <abort@plt>:
   76eb0:      	adrp	x16, 0x7d000
   76eb4:      	ldr	x17, [x16, #0xf28]
   76eb8:      	add	x16, x16, #0xf28
   76ebc:      	br	x17

0000000000076ec0 <pthread_rwlock_wrlock@plt>:
   76ec0:      	adrp	x16, 0x7d000
   76ec4:      	ldr	x17, [x16, #0xf30]
   76ec8:      	add	x16, x16, #0xf30
   76ecc:      	br	x17

0000000000076ed0 <pthread_rwlock_unlock@plt>:
   76ed0:      	adrp	x16, 0x7d000
   76ed4:      	ldr	x17, [x16, #0xf38]
   76ed8:      	add	x16, x16, #0xf38
   76edc:      	br	x17

0000000000076ee0 <dl_iterate_phdr@plt>:
   76ee0:      	adrp	x16, 0x7d000
   76ee4:      	ldr	x17, [x16, #0xf40]
   76ee8:      	add	x16, x16, #0xf40
   76eec:      	br	x17

0000000000076ef0 <pthread_rwlock_rdlock@plt>:
   76ef0:      	adrp	x16, 0x7d000
   76ef4:      	ldr	x17, [x16, #0xf48]
   76ef8:      	add	x16, x16, #0xf48
   76efc:      	br	x17

0000000000076f00 <getpid@plt>:
   76f00:      	adrp	x16, 0x7d000
   76f04:      	ldr	x17, [x16, #0xf50]
   76f08:      	add	x16, x16, #0xf50
   76f0c:      	br	x17

0000000000076f10 <syscall@plt>:
   76f10:      	adrp	x16, 0x7d000
   76f14:      	ldr	x17, [x16, #0xf58]
   76f18:      	add	x16, x16, #0xf58
   76f1c:      	br	x17

0000000000076f20 <fwrite@plt>:
   76f20:      	adrp	x16, 0x7d000
   76f24:      	ldr	x17, [x16, #0xf60]
   76f28:      	add	x16, x16, #0xf60
   76f2c:      	br	x17
