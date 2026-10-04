// EXPORTED & PLT DISASSEMBLY FOR libPVGLive.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGLive.so (SHA-256: E443F6A16CB8137D74A1583529666EB02BF4859B372175E2B4C226F6E188484C)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 43, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGLive.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000090490 <.plt>:
   90490:      	stp	x16, x30, [sp, #-0x10]!
   90494:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90498:      	ldr	x17, [x16, #0x460]
   9049c:      	add	x16, x16, #0x460
   904a0:      	br	x17
   904a4:      	nop
   904a8:      	nop
   904ac:      	nop

00000000000904b0 <__cxa_finalize@plt>:
   904b0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   904b4:      	ldr	x17, [x16, #0x468]
   904b8:      	add	x16, x16, #0x468
   904bc:      	br	x17

00000000000904c0 <__cxa_atexit@plt>:
   904c0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   904c4:      	ldr	x17, [x16, #0x470]
   904c8:      	add	x16, x16, #0x470
   904cc:      	br	x17

00000000000904d0 <__register_atfork@plt>:
   904d0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   904d4:      	ldr	x17, [x16, #0x478]
   904d8:      	add	x16, x16, #0x478
   904dc:      	br	x17

00000000000904e0 <_ZdlPv@plt>:
   904e0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   904e4:      	ldr	x17, [x16, #0x480]
   904e8:      	add	x16, x16, #0x480
   904ec:      	br	x17

00000000000904f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   904f0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   904f4:      	ldr	x17, [x16, #0x488]
   904f8:      	add	x16, x16, #0x488
   904fc:      	br	x17

0000000000090500 <memcpy@plt>:
   90500:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90504:      	ldr	x17, [x16, #0x490]
   90508:      	add	x16, x16, #0x490
   9050c:      	br	x17

0000000000090510 <pthread_self@plt>:
   90510:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90514:      	ldr	x17, [x16, #0x498]
   90518:      	add	x16, x16, #0x498
   9051c:      	br	x17

0000000000090520 <__android_log_print@plt>:
   90520:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90524:      	ldr	x17, [x16, #0x4a0]
   90528:      	add	x16, x16, #0x4a0
   9052c:      	br	x17

0000000000090530 <_Z15vllog_tag_print13vllog_level_tPKcS1_S1_z@plt>:
   90530:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90534:      	ldr	x17, [x16, #0x4a8]
   90538:      	add	x16, x16, #0x4a8
   9053c:      	br	x17

0000000000090540 <fopen@plt>:
   90540:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90544:      	ldr	x17, [x16, #0x4b0]
   90548:      	add	x16, x16, #0x4b0
   9054c:      	br	x17

0000000000090550 <_Znwm@plt>:
   90550:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90554:      	ldr	x17, [x16, #0x4b8]
   90558:      	add	x16, x16, #0x4b8
   9055c:      	br	x17

0000000000090560 <fclose@plt>:
   90560:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90564:      	ldr	x17, [x16, #0x4c0]
   90568:      	add	x16, x16, #0x4c0
   9056c:      	br	x17

0000000000090570 <fread@plt>:
   90570:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90574:      	ldr	x17, [x16, #0x4c8]
   90578:      	add	x16, x16, #0x4c8
   9057c:      	br	x17

0000000000090580 <fwrite@plt>:
   90580:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90584:      	ldr	x17, [x16, #0x4d0]
   90588:      	add	x16, x16, #0x4d0
   9058c:      	br	x17

0000000000090590 <fileno@plt>:
   90590:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90594:      	ldr	x17, [x16, #0x4d8]
   90598:      	add	x16, x16, #0x4d8
   9059c:      	br	x17

00000000000905a0 <ftell@plt>:
   905a0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   905a4:      	ldr	x17, [x16, #0x4e0]
   905a8:      	add	x16, x16, #0x4e0
   905ac:      	br	x17

00000000000905b0 <fseek@plt>:
   905b0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   905b4:      	ldr	x17, [x16, #0x4e8]
   905b8:      	add	x16, x16, #0x4e8
   905bc:      	br	x17

00000000000905c0 <__stack_chk_fail@plt>:
   905c0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   905c4:      	ldr	x17, [x16, #0x4f0]
   905c8:      	add	x16, x16, #0x4f0
   905cc:      	br	x17

00000000000905d0 <strlen@plt>:
   905d0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   905d4:      	ldr	x17, [x16, #0x4f8]
   905d8:      	add	x16, x16, #0x4f8
   905dc:      	br	x17

00000000000905e0 <memmove@plt>:
   905e0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   905e4:      	ldr	x17, [x16, #0x500]
   905e8:      	add	x16, x16, #0x500
   905ec:      	br	x17

00000000000905f0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
   905f0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   905f4:      	ldr	x17, [x16, #0x508]
   905f8:      	add	x16, x16, #0x508
   905fc:      	br	x17

0000000000090600 <malloc@plt>:
   90600:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90604:      	ldr	x17, [x16, #0x510]
   90608:      	add	x16, x16, #0x510
   9060c:      	br	x17

0000000000090610 <free@plt>:
   90610:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90614:      	ldr	x17, [x16, #0x518]
   90618:      	add	x16, x16, #0x518
   9061c:      	br	x17

0000000000090620 <__cxa_allocate_exception@plt>:
   90620:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90624:      	ldr	x17, [x16, #0x520]
   90628:      	add	x16, x16, #0x520
   9062c:      	br	x17

0000000000090630 <__cxa_throw@plt>:
   90630:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90634:      	ldr	x17, [x16, #0x528]
   90638:      	add	x16, x16, #0x528
   9063c:      	br	x17

0000000000090640 <__cxa_free_exception@plt>:
   90640:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90644:      	ldr	x17, [x16, #0x530]
   90648:      	add	x16, x16, #0x530
   9064c:      	br	x17

0000000000090650 <_ZNSt11logic_errorC2EPKc@plt>:
   90650:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90654:      	ldr	x17, [x16, #0x538]
   90658:      	add	x16, x16, #0x538
   9065c:      	br	x17

0000000000090660 <munmap@plt>:
   90660:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90664:      	ldr	x17, [x16, #0x540]
   90668:      	add	x16, x16, #0x540
   9066c:      	br	x17

0000000000090670 <__cxa_begin_catch@plt>:
   90670:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90674:      	ldr	x17, [x16, #0x548]
   90678:      	add	x16, x16, #0x548
   9067c:      	br	x17

0000000000090680 <_ZSt9terminatev@plt>:
   90680:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90684:      	ldr	x17, [x16, #0x550]
   90688:      	add	x16, x16, #0x550
   9068c:      	br	x17

0000000000090690 <strstr@plt>:
   90690:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90694:      	ldr	x17, [x16, #0x558]
   90698:      	add	x16, x16, #0x558
   9069c:      	br	x17

00000000000906a0 <mmap@plt>:
   906a0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   906a4:      	ldr	x17, [x16, #0x560]
   906a8:      	add	x16, x16, #0x560
   906ac:      	br	x17

00000000000906b0 <fstat@plt>:
   906b0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   906b4:      	ldr	x17, [x16, #0x568]
   906b8:      	add	x16, x16, #0x568
   906bc:      	br	x17

00000000000906c0 <lseek@plt>:
   906c0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   906c4:      	ldr	x17, [x16, #0x570]
   906c8:      	add	x16, x16, #0x570
   906cc:      	br	x17

00000000000906d0 <_ZNSt6__ndk113random_deviceclEv@plt>:
   906d0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   906d4:      	ldr	x17, [x16, #0x578]
   906d8:      	add	x16, x16, #0x578
   906dc:      	br	x17

00000000000906e0 <_ZNSt6__ndk113random_deviceD1Ev@plt>:
   906e0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   906e4:      	ldr	x17, [x16, #0x580]
   906e8:      	add	x16, x16, #0x580
   906ec:      	br	x17

00000000000906f0 <_ZNSt6__ndk113random_deviceC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
   906f0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   906f4:      	ldr	x17, [x16, #0x588]
   906f8:      	add	x16, x16, #0x588
   906fc:      	br	x17

0000000000090700 <vsnprintf@plt>:
   90700:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90704:      	ldr	x17, [x16, #0x590]
   90708:      	add	x16, x16, #0x590
   9070c:      	br	x17

0000000000090710 <memcmp@plt>:
   90710:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90714:      	ldr	x17, [x16, #0x598]
   90718:      	add	x16, x16, #0x598
   9071c:      	br	x17

0000000000090720 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm@plt>:
   90720:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90724:      	ldr	x17, [x16, #0x5a0]
   90728:      	add	x16, x16, #0x5a0
   9072c:      	br	x17

0000000000090730 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   90730:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90734:      	ldr	x17, [x16, #0x5a8]
   90738:      	add	x16, x16, #0x5a8
   9073c:      	br	x17

0000000000090740 <memset@plt>:
   90740:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90744:      	ldr	x17, [x16, #0x5b0]
   90748:      	add	x16, x16, #0x5b0
   9074c:      	br	x17

0000000000090750 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKc@plt>:
   90750:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90754:      	ldr	x17, [x16, #0x5b8]
   90758:      	add	x16, x16, #0x5b8
   9075c:      	br	x17

0000000000090760 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   90760:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90764:      	ldr	x17, [x16, #0x5c0]
   90768:      	add	x16, x16, #0x5c0
   9076c:      	br	x17

0000000000090770 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   90770:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90774:      	ldr	x17, [x16, #0x5c8]
   90778:      	add	x16, x16, #0x5c8
   9077c:      	br	x17

0000000000090780 <memchr@plt>:
   90780:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90784:      	ldr	x17, [x16, #0x5d0]
   90788:      	add	x16, x16, #0x5d0
   9078c:      	br	x17

0000000000090790 <_ZNSt6__ndk112__next_primeEm@plt>:
   90790:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90794:      	ldr	x17, [x16, #0x5d8]
   90798:      	add	x16, x16, #0x5d8
   9079c:      	br	x17

00000000000907a0 <__cxa_guard_acquire@plt>:
   907a0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   907a4:      	ldr	x17, [x16, #0x5e0]
   907a8:      	add	x16, x16, #0x5e0
   907ac:      	br	x17

00000000000907b0 <__cxa_guard_release@plt>:
   907b0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   907b4:      	ldr	x17, [x16, #0x5e8]
   907b8:      	add	x16, x16, #0x5e8
   907bc:      	br	x17

00000000000907c0 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
   907c0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   907c4:      	ldr	x17, [x16, #0x5f0]
   907c8:      	add	x16, x16, #0x5f0
   907cc:      	br	x17

00000000000907d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   907d0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   907d4:      	ldr	x17, [x16, #0x5f8]
   907d8:      	add	x16, x16, #0x5f8
   907dc:      	br	x17

00000000000907e0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm@plt>:
   907e0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   907e4:      	ldr	x17, [x16, #0x600]
   907e8:      	add	x16, x16, #0x600
   907ec:      	br	x17

00000000000907f0 <_ZNSt6__ndk19to_stringEl@plt>:
   907f0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   907f4:      	ldr	x17, [x16, #0x608]
   907f8:      	add	x16, x16, #0x608
   907fc:      	br	x17

0000000000090800 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
   90800:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90804:      	ldr	x17, [x16, #0x610]
   90808:      	add	x16, x16, #0x610
   9080c:      	br	x17

0000000000090810 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
   90810:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90814:      	ldr	x17, [x16, #0x618]
   90818:      	add	x16, x16, #0x618
   9081c:      	br	x17

0000000000090820 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
   90820:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90824:      	ldr	x17, [x16, #0x620]
   90828:      	add	x16, x16, #0x620
   9082c:      	br	x17

0000000000090830 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   90830:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90834:      	ldr	x17, [x16, #0x628]
   90838:      	add	x16, x16, #0x628
   9083c:      	br	x17

0000000000090840 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   90840:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90844:      	ldr	x17, [x16, #0x630]
   90848:      	add	x16, x16, #0x630
   9084c:      	br	x17

0000000000090850 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   90850:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90854:      	ldr	x17, [x16, #0x638]
   90858:      	add	x16, x16, #0x638
   9085c:      	br	x17

0000000000090860 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   90860:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90864:      	ldr	x17, [x16, #0x640]
   90868:      	add	x16, x16, #0x640
   9086c:      	br	x17

0000000000090870 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   90870:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90874:      	ldr	x17, [x16, #0x648]
   90878:      	add	x16, x16, #0x648
   9087c:      	br	x17

0000000000090880 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   90880:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90884:      	ldr	x17, [x16, #0x650]
   90888:      	add	x16, x16, #0x650
   9088c:      	br	x17

0000000000090890 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
   90890:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90894:      	ldr	x17, [x16, #0x658]
   90898:      	add	x16, x16, #0x658
   9089c:      	br	x17

00000000000908a0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
   908a0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   908a4:      	ldr	x17, [x16, #0x660]
   908a8:      	add	x16, x16, #0x660
   908ac:      	br	x17

00000000000908b0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   908b0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   908b4:      	ldr	x17, [x16, #0x668]
   908b8:      	add	x16, x16, #0x668
   908bc:      	br	x17

00000000000908c0 <_ZNSt6__ndk16localeD1Ev@plt>:
   908c0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   908c4:      	ldr	x17, [x16, #0x670]
   908c8:      	add	x16, x16, #0x670
   908cc:      	br	x17

00000000000908d0 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   908d0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   908d4:      	ldr	x17, [x16, #0x678]
   908d8:      	add	x16, x16, #0x678
   908dc:      	br	x17

00000000000908e0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
   908e0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   908e4:      	ldr	x17, [x16, #0x680]
   908e8:      	add	x16, x16, #0x680
   908ec:      	br	x17

00000000000908f0 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
   908f0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   908f4:      	ldr	x17, [x16, #0x688]
   908f8:      	add	x16, x16, #0x688
   908fc:      	br	x17

0000000000090900 <__cxa_end_catch@plt>:
   90900:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90904:      	ldr	x17, [x16, #0x690]
   90908:      	add	x16, x16, #0x690
   9090c:      	br	x17

0000000000090910 <strtoll@plt>:
   90910:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90914:      	ldr	x17, [x16, #0x698]
   90918:      	add	x16, x16, #0x698
   9091c:      	br	x17

0000000000090920 <strtol@plt>:
   90920:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90924:      	ldr	x17, [x16, #0x6a0]
   90928:      	add	x16, x16, #0x6a0
   9092c:      	br	x17

0000000000090930 <_ZNSt6__ndk19to_stringEi@plt>:
   90930:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90934:      	ldr	x17, [x16, #0x6a8]
   90938:      	add	x16, x16, #0x6a8
   9093c:      	br	x17

0000000000090940 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
   90940:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90944:      	ldr	x17, [x16, #0x6b0]
   90948:      	add	x16, x16, #0x6b0
   9094c:      	br	x17

0000000000090950 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   90950:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90954:      	ldr	x17, [x16, #0x6b8]
   90958:      	add	x16, x16, #0x6b8
   9095c:      	br	x17

0000000000090960 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj@plt>:
   90960:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90964:      	ldr	x17, [x16, #0x6c0]
   90968:      	add	x16, x16, #0x6c0
   9096c:      	br	x17

0000000000090970 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm@plt>:
   90970:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90974:      	ldr	x17, [x16, #0x6c8]
   90978:      	add	x16, x16, #0x6c8
   9097c:      	br	x17

0000000000090980 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
   90980:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90984:      	ldr	x17, [x16, #0x6d0]
   90988:      	add	x16, x16, #0x6d0
   9098c:      	br	x17

0000000000090990 <sscanf@plt>:
   90990:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90994:      	ldr	x17, [x16, #0x6d8]
   90998:      	add	x16, x16, #0x6d8
   9099c:      	br	x17

00000000000909a0 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
   909a0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   909a4:      	ldr	x17, [x16, #0x6e0]
   909a8:      	add	x16, x16, #0x6e0
   909ac:      	br	x17

00000000000909b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
   909b0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   909b4:      	ldr	x17, [x16, #0x6e8]
   909b8:      	add	x16, x16, #0x6e8
   909bc:      	br	x17

00000000000909c0 <__memcpy_chk@plt>:
   909c0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   909c4:      	ldr	x17, [x16, #0x6f0]
   909c8:      	add	x16, x16, #0x6f0
   909cc:      	br	x17

00000000000909d0 <_ZN7PVGLIVE9PVGGlobal11getInstanceEv@plt>:
   909d0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   909d4:      	ldr	x17, [x16, #0x6f8]
   909d8:      	add	x16, x16, #0x6f8
   909dc:      	br	x17

00000000000909e0 <_ZNSt6__ndk119__shared_mutex_baseC1Ev@plt>:
   909e0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   909e4:      	ldr	x17, [x16, #0x700]
   909e8:      	add	x16, x16, #0x700
   909ec:      	br	x17

00000000000909f0 <_ZN7PVGLIVE9PVGGlobalD1Ev@plt>:
   909f0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   909f4:      	ldr	x17, [x16, #0x708]
   909f8:      	add	x16, x16, #0x708
   909fc:      	br	x17

0000000000090a00 <__cxa_guard_abort@plt>:
   90a00:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a04:      	ldr	x17, [x16, #0x710]
   90a08:      	add	x16, x16, #0x710
   90a0c:      	br	x17

0000000000090a10 <_ZN7PVGLIVE9PVGGlobal11setLogLevelENS_11PVGLogLevelE@plt>:
   90a10:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a14:      	ldr	x17, [x16, #0x718]
   90a18:      	add	x16, x16, #0x718
   90a1c:      	br	x17

0000000000090a20 <_ZNSt6__ndk15mutex4lockEv@plt>:
   90a20:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a24:      	ldr	x17, [x16, #0x720]
   90a28:      	add	x16, x16, #0x720
   90a2c:      	br	x17

0000000000090a30 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   90a30:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a34:      	ldr	x17, [x16, #0x728]
   90a38:      	add	x16, x16, #0x728
   90a3c:      	br	x17

0000000000090a40 <_ZNSt6__ndk119__shared_mutex_base4lockEv@plt>:
   90a40:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a44:      	ldr	x17, [x16, #0x730]
   90a48:      	add	x16, x16, #0x730
   90a4c:      	br	x17

0000000000090a50 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
   90a50:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a54:      	ldr	x17, [x16, #0x738]
   90a58:      	add	x16, x16, #0x738
   90a5c:      	br	x17

0000000000090a60 <_ZNSt6__ndk15mutexD1Ev@plt>:
   90a60:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a64:      	ldr	x17, [x16, #0x740]
   90a68:      	add	x16, x16, #0x740
   90a6c:      	br	x17

0000000000090a70 <_ZNSt6__ndk119__shared_mutex_base6unlockEv@plt>:
   90a70:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a74:      	ldr	x17, [x16, #0x748]
   90a78:      	add	x16, x16, #0x748
   90a7c:      	br	x17

0000000000090a80 <_ZN7PVGLIVE9PVGGlobal7isDebugEv@plt>:
   90a80:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a84:      	ldr	x17, [x16, #0x750]
   90a88:      	add	x16, x16, #0x750
   90a8c:      	br	x17

0000000000090a90 <_ZN7PVGLIVE9PVGGlobal8setDebugEb@plt>:
   90a90:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90a94:      	ldr	x17, [x16, #0x758]
   90a98:      	add	x16, x16, #0x758
   90a9c:      	br	x17

0000000000090aa0 <_ZN7PVGLIVE9PVGGlobal17setAndroidContextEP8_jobject@plt>:
   90aa0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90aa4:      	ldr	x17, [x16, #0x760]
   90aa8:      	add	x16, x16, #0x760
   90aac:      	br	x17

0000000000090ab0 <_ZN7PVGLIVE9PVGGlobal17getAndroidContextEv@plt>:
   90ab0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ab4:      	ldr	x17, [x16, #0x768]
   90ab8:      	add	x16, x16, #0x768
   90abc:      	br	x17

0000000000090ac0 <_ZNSt6__ndk119__shared_mutex_base11lock_sharedEv@plt>:
   90ac0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ac4:      	ldr	x17, [x16, #0x770]
   90ac8:      	add	x16, x16, #0x770
   90acc:      	br	x17

0000000000090ad0 <_ZNSt6__ndk119__shared_mutex_base13unlock_sharedEv@plt>:
   90ad0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ad4:      	ldr	x17, [x16, #0x778]
   90ad8:      	add	x16, x16, #0x778
   90adc:      	br	x17

0000000000090ae0 <_ZN7PVGLIVE9PVGGlobal21releaseAndroidContextEv@plt>:
   90ae0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ae4:      	ldr	x17, [x16, #0x780]
   90ae8:      	add	x16, x16, #0x780
   90aec:      	br	x17

0000000000090af0 <_ZN7PVGLIVE7PVGLive6createENS_11PVGLiveTypeE@plt>:
   90af0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90af4:      	ldr	x17, [x16, #0x788]
   90af8:      	add	x16, x16, #0x788
   90afc:      	br	x17

0000000000090b00 <_ZN7PVGLIVE7PVGLive7destroyEPS0_@plt>:
   90b00:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b04:      	ldr	x17, [x16, #0x790]
   90b08:      	add	x16, x16, #0x790
   90b0c:      	br	x17

0000000000090b10 <_ZN7PVGLIVE7PVGLive7versionEv@plt>:
   90b10:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b14:      	ldr	x17, [x16, #0x798]
   90b18:      	add	x16, x16, #0x798
   90b1c:      	br	x17

0000000000090b20 <_ZN7PVGLIVE7PVGLive13isMotionPhotoERKNS_13PVGLiveSourceE@plt>:
   90b20:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b24:      	ldr	x17, [x16, #0x7a0]
   90b28:      	add	x16, x16, #0x7a0
   90b2c:      	br	x17

0000000000090b30 <_ZN7PVGLIVE7PVGLive21quickProbeMotionPhotoERKNS_13PVGLiveSourceE@plt>:
   90b30:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b34:      	ldr	x17, [x16, #0x7a8]
   90b38:      	add	x16, x16, #0x7a8
   90b3c:      	br	x17

0000000000090b40 <_ZN7PVGLIVE7PVGLive12detectVendorERKNS_13PVGLiveSourceE@plt>:
   90b40:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b44:      	ldr	x17, [x16, #0x7b0]
   90b48:      	add	x16, x16, #0x7b0
   90b4c:      	br	x17

0000000000090b50 <_ZN7PVGLIVE7PVGLive22stripLiveVideoMetadataERKNS_13PVGLiveSourceENS_13PVGLiveVendorERKNS_13PVGLiveOutputE@plt>:
   90b50:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b54:      	ldr	x17, [x16, #0x7b8]
   90b58:      	add	x16, x16, #0x7b8
   90b5c:      	br	x17

0000000000090b60 <strcmp@plt>:
   90b60:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b64:      	ldr	x17, [x16, #0x7c0]
   90b68:      	add	x16, x16, #0x7c0
   90b6c:      	br	x17

0000000000090b70 <_ZnwmRKSt9nothrow_t@plt>:
   90b70:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b74:      	ldr	x17, [x16, #0x7c8]
   90b78:      	add	x16, x16, #0x7c8
   90b7c:      	br	x17

0000000000090b80 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
   90b80:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b84:      	ldr	x17, [x16, #0x7d0]
   90b88:      	add	x16, x16, #0x7d0
   90b8c:      	br	x17

0000000000090b90 <_ZNSt6__ndk19to_stringEj@plt>:
   90b90:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90b94:      	ldr	x17, [x16, #0x7d8]
   90b98:      	add	x16, x16, #0x7d8
   90b9c:      	br	x17

0000000000090ba0 <_ZNSt6__ndk19to_stringEm@plt>:
   90ba0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ba4:      	ldr	x17, [x16, #0x7e0]
   90ba8:      	add	x16, x16, #0x7e0
   90bac:      	br	x17

0000000000090bb0 <_ZNSt9exceptionD2Ev@plt>:
   90bb0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90bb4:      	ldr	x17, [x16, #0x7e8]
   90bb8:      	add	x16, x16, #0x7e8
   90bbc:      	br	x17

0000000000090bc0 <__vsnprintf_chk@plt>:
   90bc0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90bc4:      	ldr	x17, [x16, #0x7f0]
   90bc8:      	add	x16, x16, #0x7f0
   90bcc:      	br	x17

0000000000090bd0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv@plt>:
   90bd0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90bd4:      	ldr	x17, [x16, #0x7f8]
   90bd8:      	add	x16, x16, #0x7f8
   90bdc:      	br	x17

0000000000090be0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
   90be0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90be4:      	ldr	x17, [x16, #0x800]
   90be8:      	add	x16, x16, #0x800
   90bec:      	br	x17

0000000000090bf0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
   90bf0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90bf4:      	ldr	x17, [x16, #0x808]
   90bf8:      	add	x16, x16, #0x808
   90bfc:      	br	x17

0000000000090c00 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
   90c00:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c04:      	ldr	x17, [x16, #0x810]
   90c08:      	add	x16, x16, #0x810
   90c0c:      	br	x17

0000000000090c10 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   90c10:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c14:      	ldr	x17, [x16, #0x818]
   90c18:      	add	x16, x16, #0x818
   90c1c:      	br	x17

0000000000090c20 <_ZNSt6__ndk19to_stringEf@plt>:
   90c20:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c24:      	ldr	x17, [x16, #0x820]
   90c28:      	add	x16, x16, #0x820
   90c2c:      	br	x17

0000000000090c30 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   90c30:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c34:      	ldr	x17, [x16, #0x828]
   90c38:      	add	x16, x16, #0x828
   90c3c:      	br	x17

0000000000090c40 <__read_chk@plt>:
   90c40:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c44:      	ldr	x17, [x16, #0x830]
   90c48:      	add	x16, x16, #0x830
   90c4c:      	br	x17

0000000000090c50 <__errno@plt>:
   90c50:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c54:      	ldr	x17, [x16, #0x838]
   90c58:      	add	x16, x16, #0x838
   90c5c:      	br	x17

0000000000090c60 <write@plt>:
   90c60:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c64:      	ldr	x17, [x16, #0x840]
   90c68:      	add	x16, x16, #0x840
   90c6c:      	br	x17

0000000000090c70 <pthread_getspecific@plt>:
   90c70:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c74:      	ldr	x17, [x16, #0x848]
   90c78:      	add	x16, x16, #0x848
   90c7c:      	br	x17

0000000000090c80 <pthread_key_create@plt>:
   90c80:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c84:      	ldr	x17, [x16, #0x850]
   90c88:      	add	x16, x16, #0x850
   90c8c:      	br	x17

0000000000090c90 <pthread_setspecific@plt>:
   90c90:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90c94:      	ldr	x17, [x16, #0x858]
   90c98:      	add	x16, x16, #0x858
   90c9c:      	br	x17

0000000000090ca0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
   90ca0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ca4:      	ldr	x17, [x16, #0x860]
   90ca8:      	add	x16, x16, #0x860
   90cac:      	br	x17

0000000000090cb0 <_ZNSt6__ndk111__call_onceERVmPvPFvS2_E@plt>:
   90cb0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90cb4:      	ldr	x17, [x16, #0x868]
   90cb8:      	add	x16, x16, #0x868
   90cbc:      	br	x17

0000000000090cc0 <getauxval@plt>:
   90cc0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90cc4:      	ldr	x17, [x16, #0x870]
   90cc8:      	add	x16, x16, #0x870
   90ccc:      	br	x17

0000000000090cd0 <__system_property_get@plt>:
   90cd0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90cd4:      	ldr	x17, [x16, #0x878]
   90cd8:      	add	x16, x16, #0x878
   90cdc:      	br	x17

0000000000090ce0 <strncmp@plt>:
   90ce0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90ce4:      	ldr	x17, [x16, #0x880]
   90ce8:      	add	x16, x16, #0x880
   90cec:      	br	x17

0000000000090cf0 <fprintf@plt>:
   90cf0:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90cf4:      	ldr	x17, [x16, #0x888]
   90cf8:      	add	x16, x16, #0x888
   90cfc:      	br	x17

0000000000090d00 <fflush@plt>:
   90d00:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d04:      	ldr	x17, [x16, #0x890]
   90d08:      	add	x16, x16, #0x890
   90d0c:      	br	x17

0000000000090d10 <abort@plt>:
   90d10:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d14:      	ldr	x17, [x16, #0x898]
   90d18:      	add	x16, x16, #0x898
   90d1c:      	br	x17

0000000000090d20 <pthread_rwlock_wrlock@plt>:
   90d20:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d24:      	ldr	x17, [x16, #0x8a0]
   90d28:      	add	x16, x16, #0x8a0
   90d2c:      	br	x17

0000000000090d30 <pthread_rwlock_unlock@plt>:
   90d30:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d34:      	ldr	x17, [x16, #0x8a8]
   90d38:      	add	x16, x16, #0x8a8
   90d3c:      	br	x17

0000000000090d40 <dl_iterate_phdr@plt>:
   90d40:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d44:      	ldr	x17, [x16, #0x8b0]
   90d48:      	add	x16, x16, #0x8b0
   90d4c:      	br	x17

0000000000090d50 <pthread_rwlock_rdlock@plt>:
   90d50:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d54:      	ldr	x17, [x16, #0x8b8]
   90d58:      	add	x16, x16, #0x8b8
   90d5c:      	br	x17

0000000000090d60 <getpid@plt>:
   90d60:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d64:      	ldr	x17, [x16, #0x8c0]
   90d68:      	add	x16, x16, #0x8c0
   90d6c:      	br	x17

0000000000090d70 <syscall@plt>:
   90d70:      	adrp	x16, 0x96000 <_ZTCNSt6__ndk113basic_fstreamIcNS_11char_traitsIcEEEE16_NS_13basic_ostreamIcS2_EE+0x2b0>
   90d74:      	ldr	x17, [x16, #0x8c8]
   90d78:      	add	x16, x16, #0x8c8
   90d7c:      	br	x17
