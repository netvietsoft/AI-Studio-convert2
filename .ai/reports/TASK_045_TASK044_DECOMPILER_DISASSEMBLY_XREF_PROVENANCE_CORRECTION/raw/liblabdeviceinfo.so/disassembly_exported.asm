// EXPORTED & PLT DISASSEMBLY FOR liblabdeviceinfo.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\liblabdeviceinfo.so (SHA-256: 68EE1BC7A413742159A9375FF3DCC2D78C31F4259AB697E252ACB4F2DFE90E5E)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 3, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\liblabdeviceinfo.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000001d460 <.plt>:
   1d460:      	stp	x16, x30, [sp, #-0x10]!
   1d464:      	adrp	x16, 0x22000
   1d468:      	ldr	x17, [x16, #0x128]
   1d46c:      	add	x16, x16, #0x128
   1d470:      	br	x17
   1d474:      	nop
   1d478:      	nop
   1d47c:      	nop

000000000001d480 <__cxa_finalize@plt>:
   1d480:      	adrp	x16, 0x22000
   1d484:      	ldr	x17, [x16, #0x130]
   1d488:      	add	x16, x16, #0x130
   1d48c:      	br	x17

000000000001d490 <__cxa_atexit@plt>:
   1d490:      	adrp	x16, 0x22000
   1d494:      	ldr	x17, [x16, #0x138]
   1d498:      	add	x16, x16, #0x138
   1d49c:      	br	x17

000000000001d4a0 <__stack_chk_fail@plt>:
   1d4a0:      	adrp	x16, 0x22000
   1d4a4:      	ldr	x17, [x16, #0x140]
   1d4a8:      	add	x16, x16, #0x140
   1d4ac:      	br	x17

000000000001d4b0 <_ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz@plt>:
   1d4b0:      	adrp	x16, 0x22000
   1d4b4:      	ldr	x17, [x16, #0x148]
   1d4b8:      	add	x16, x16, #0x148
   1d4bc:      	br	x17

000000000001d4c0 <__android_log_print@plt>:
   1d4c0:      	adrp	x16, 0x22000
   1d4c4:      	ldr	x17, [x16, #0x150]
   1d4c8:      	add	x16, x16, #0x150
   1d4cc:      	br	x17

000000000001d4d0 <abort@plt>:
   1d4d0:      	adrp	x16, 0x22000
   1d4d4:      	ldr	x17, [x16, #0x158]
   1d4d8:      	add	x16, x16, #0x158
   1d4dc:      	br	x17

000000000001d4e0 <syscall@plt>:
   1d4e0:      	adrp	x16, 0x22000
   1d4e4:      	ldr	x17, [x16, #0x160]
   1d4e8:      	add	x16, x16, #0x160
   1d4ec:      	br	x17

000000000001d4f0 <strstr@plt>:
   1d4f0:      	adrp	x16, 0x22000
   1d4f4:      	ldr	x17, [x16, #0x168]
   1d4f8:      	add	x16, x16, #0x168
   1d4fc:      	br	x17

000000000001d500 <__strlen_chk@plt>:
   1d500:      	adrp	x16, 0x22000
   1d504:      	ldr	x17, [x16, #0x170]
   1d508:      	add	x16, x16, #0x170
   1d50c:      	br	x17

000000000001d510 <strlen@plt>:
   1d510:      	adrp	x16, 0x22000
   1d514:      	ldr	x17, [x16, #0x178]
   1d518:      	add	x16, x16, #0x178
   1d51c:      	br	x17

000000000001d520 <__vsnprintf_chk@plt>:
   1d520:      	adrp	x16, 0x22000
   1d524:      	ldr	x17, [x16, #0x180]
   1d528:      	add	x16, x16, #0x180
   1d52c:      	br	x17

000000000001d530 <_Znwm@plt>:
   1d530:      	adrp	x16, 0x22000
   1d534:      	ldr	x17, [x16, #0x188]
   1d538:      	add	x16, x16, #0x188
   1d53c:      	br	x17

000000000001d540 <memcpy@plt>:
   1d540:      	adrp	x16, 0x22000
   1d544:      	ldr	x17, [x16, #0x190]
   1d548:      	add	x16, x16, #0x190
   1d54c:      	br	x17

000000000001d550 <_ZdlPv@plt>:
   1d550:      	adrp	x16, 0x22000
   1d554:      	ldr	x17, [x16, #0x198]
   1d558:      	add	x16, x16, #0x198
   1d55c:      	br	x17

000000000001d560 <printf@plt>:
   1d560:      	adrp	x16, 0x22000
   1d564:      	ldr	x17, [x16, #0x1a0]
   1d568:      	add	x16, x16, #0x1a0
   1d56c:      	br	x17

000000000001d570 <regcomp@plt>:
   1d570:      	adrp	x16, 0x22000
   1d574:      	ldr	x17, [x16, #0x1a8]
   1d578:      	add	x16, x16, #0x1a8
   1d57c:      	br	x17

000000000001d580 <regerror@plt>:
   1d580:      	adrp	x16, 0x22000
   1d584:      	ldr	x17, [x16, #0x1b0]
   1d588:      	add	x16, x16, #0x1b0
   1d58c:      	br	x17

000000000001d590 <regexec@plt>:
   1d590:      	adrp	x16, 0x22000
   1d594:      	ldr	x17, [x16, #0x1b8]
   1d598:      	add	x16, x16, #0x1b8
   1d59c:      	br	x17

000000000001d5a0 <fprintf@plt>:
   1d5a0:      	adrp	x16, 0x22000
   1d5a4:      	ldr	x17, [x16, #0x1c0]
   1d5a8:      	add	x16, x16, #0x1c0
   1d5ac:      	br	x17

000000000001d5b0 <memset@plt>:
   1d5b0:      	adrp	x16, 0x22000
   1d5b4:      	ldr	x17, [x16, #0x1c8]
   1d5b8:      	add	x16, x16, #0x1c8
   1d5bc:      	br	x17

000000000001d5c0 <fwrite@plt>:
   1d5c0:      	adrp	x16, 0x22000
   1d5c4:      	ldr	x17, [x16, #0x1d0]
   1d5c8:      	add	x16, x16, #0x1d0
   1d5cc:      	br	x17

000000000001d5d0 <strncpy@plt>:
   1d5d0:      	adrp	x16, 0x22000
   1d5d4:      	ldr	x17, [x16, #0x1d8]
   1d5d8:      	add	x16, x16, #0x1d8
   1d5dc:      	br	x17

000000000001d5e0 <__strncpy_chk2@plt>:
   1d5e0:      	adrp	x16, 0x22000
   1d5e4:      	ldr	x17, [x16, #0x1e0]
   1d5e8:      	add	x16, x16, #0x1e0
   1d5ec:      	br	x17

000000000001d5f0 <_ZNSt6__ndk15mutex4lockEv@plt>:
   1d5f0:      	adrp	x16, 0x22000
   1d5f4:      	ldr	x17, [x16, #0x1e8]
   1d5f8:      	add	x16, x16, #0x1e8
   1d5fc:      	br	x17

000000000001d600 <dlopen@plt>:
   1d600:      	adrp	x16, 0x22000
   1d604:      	ldr	x17, [x16, #0x1f0]
   1d608:      	add	x16, x16, #0x1f0
   1d60c:      	br	x17

000000000001d610 <eglGetError@plt>:
   1d610:      	adrp	x16, 0x22000
   1d614:      	ldr	x17, [x16, #0x1f8]
   1d618:      	add	x16, x16, #0x1f8
   1d61c:      	br	x17

000000000001d620 <eglGetDisplay@plt>:
   1d620:      	adrp	x16, 0x22000
   1d624:      	ldr	x17, [x16, #0x200]
   1d628:      	add	x16, x16, #0x200
   1d62c:      	br	x17

000000000001d630 <eglInitialize@plt>:
   1d630:      	adrp	x16, 0x22000
   1d634:      	ldr	x17, [x16, #0x208]
   1d638:      	add	x16, x16, #0x208
   1d63c:      	br	x17

000000000001d640 <eglChooseConfig@plt>:
   1d640:      	adrp	x16, 0x22000
   1d644:      	ldr	x17, [x16, #0x210]
   1d648:      	add	x16, x16, #0x210
   1d64c:      	br	x17

000000000001d650 <eglCreatePbufferSurface@plt>:
   1d650:      	adrp	x16, 0x22000
   1d654:      	ldr	x17, [x16, #0x218]
   1d658:      	add	x16, x16, #0x218
   1d65c:      	br	x17

000000000001d660 <eglCreateContext@plt>:
   1d660:      	adrp	x16, 0x22000
   1d664:      	ldr	x17, [x16, #0x220]
   1d668:      	add	x16, x16, #0x220
   1d66c:      	br	x17

000000000001d670 <eglMakeCurrent@plt>:
   1d670:      	adrp	x16, 0x22000
   1d674:      	ldr	x17, [x16, #0x228]
   1d678:      	add	x16, x16, #0x228
   1d67c:      	br	x17

000000000001d680 <glGetString@plt>:
   1d680:      	adrp	x16, 0x22000
   1d684:      	ldr	x17, [x16, #0x230]
   1d688:      	add	x16, x16, #0x230
   1d68c:      	br	x17

000000000001d690 <eglDestroySurface@plt>:
   1d690:      	adrp	x16, 0x22000
   1d694:      	ldr	x17, [x16, #0x238]
   1d698:      	add	x16, x16, #0x238
   1d69c:      	br	x17

000000000001d6a0 <eglDestroyContext@plt>:
   1d6a0:      	adrp	x16, 0x22000
   1d6a4:      	ldr	x17, [x16, #0x240]
   1d6a8:      	add	x16, x16, #0x240
   1d6ac:      	br	x17

000000000001d6b0 <dlclose@plt>:
   1d6b0:      	adrp	x16, 0x22000
   1d6b4:      	ldr	x17, [x16, #0x248]
   1d6b8:      	add	x16, x16, #0x248
   1d6bc:      	br	x17

000000000001d6c0 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   1d6c0:      	adrp	x16, 0x22000
   1d6c4:      	ldr	x17, [x16, #0x250]
   1d6c8:      	add	x16, x16, #0x250
   1d6cc:      	br	x17

000000000001d6d0 <eglGetCurrentContext@plt>:
   1d6d0:      	adrp	x16, 0x22000
   1d6d4:      	ldr	x17, [x16, #0x258]
   1d6d8:      	add	x16, x16, #0x258
   1d6dc:      	br	x17

000000000001d6e0 <glGetError@plt>:
   1d6e0:      	adrp	x16, 0x22000
   1d6e4:      	ldr	x17, [x16, #0x260]
   1d6e8:      	add	x16, x16, #0x260
   1d6ec:      	br	x17

000000000001d6f0 <dlsym@plt>:
   1d6f0:      	adrp	x16, 0x22000
   1d6f4:      	ldr	x17, [x16, #0x268]
   1d6f8:      	add	x16, x16, #0x268
   1d6fc:      	br	x17

000000000001d700 <_Znam@plt>:
   1d700:      	adrp	x16, 0x22000
   1d704:      	ldr	x17, [x16, #0x270]
   1d708:      	add	x16, x16, #0x270
   1d70c:      	br	x17

000000000001d710 <_ZdaPv@plt>:
   1d710:      	adrp	x16, 0x22000
   1d714:      	ldr	x17, [x16, #0x278]
   1d718:      	add	x16, x16, #0x278
   1d71c:      	br	x17

000000000001d720 <memchr@plt>:
   1d720:      	adrp	x16, 0x22000
   1d724:      	ldr	x17, [x16, #0x280]
   1d728:      	add	x16, x16, #0x280
   1d72c:      	br	x17

000000000001d730 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
   1d730:      	adrp	x16, 0x22000
   1d734:      	ldr	x17, [x16, #0x288]
   1d738:      	add	x16, x16, #0x288
   1d73c:      	br	x17

000000000001d740 <memmove@plt>:
   1d740:      	adrp	x16, 0x22000
   1d744:      	ldr	x17, [x16, #0x290]
   1d748:      	add	x16, x16, #0x290
   1d74c:      	br	x17

000000000001d750 <__vsprintf_chk@plt>:
   1d750:      	adrp	x16, 0x22000
   1d754:      	ldr	x17, [x16, #0x298]
   1d758:      	add	x16, x16, #0x298
   1d75c:      	br	x17

000000000001d760 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   1d760:      	adrp	x16, 0x22000
   1d764:      	ldr	x17, [x16, #0x2a0]
   1d768:      	add	x16, x16, #0x2a0
   1d76c:      	br	x17

000000000001d770 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
   1d770:      	adrp	x16, 0x22000
   1d774:      	ldr	x17, [x16, #0x2a8]
   1d778:      	add	x16, x16, #0x2a8
   1d77c:      	br	x17

000000000001d780 <pthread_once@plt>:
   1d780:      	adrp	x16, 0x22000
   1d784:      	ldr	x17, [x16, #0x2b0]
   1d788:      	add	x16, x16, #0x2b0
   1d78c:      	br	x17

000000000001d790 <strchr@plt>:
   1d790:      	adrp	x16, 0x22000
   1d794:      	ldr	x17, [x16, #0x2b8]
   1d798:      	add	x16, x16, #0x2b8
   1d79c:      	br	x17

000000000001d7a0 <atoi@plt>:
   1d7a0:      	adrp	x16, 0x22000
   1d7a4:      	ldr	x17, [x16, #0x2c0]
   1d7a8:      	add	x16, x16, #0x2c0
   1d7ac:      	br	x17

000000000001d7b0 <__strchr_chk@plt>:
   1d7b0:      	adrp	x16, 0x22000
   1d7b4:      	ldr	x17, [x16, #0x2c8]
   1d7b8:      	add	x16, x16, #0x2c8
   1d7bc:      	br	x17

000000000001d7c0 <__open_2@plt>:
   1d7c0:      	adrp	x16, 0x22000
   1d7c4:      	ldr	x17, [x16, #0x2d0]
   1d7c8:      	add	x16, x16, #0x2d0
   1d7cc:      	br	x17

000000000001d7d0 <__read_chk@plt>:
   1d7d0:      	adrp	x16, 0x22000
   1d7d4:      	ldr	x17, [x16, #0x2d8]
   1d7d8:      	add	x16, x16, #0x2d8
   1d7dc:      	br	x17

000000000001d7e0 <close@plt>:
   1d7e0:      	adrp	x16, 0x22000
   1d7e4:      	ldr	x17, [x16, #0x2e0]
   1d7e8:      	add	x16, x16, #0x2e0
   1d7ec:      	br	x17

000000000001d7f0 <__system_property_get@plt>:
   1d7f0:      	adrp	x16, 0x22000
   1d7f4:      	ldr	x17, [x16, #0x2e8]
   1d7f8:      	add	x16, x16, #0x2e8
   1d7fc:      	br	x17

000000000001d800 <getauxval@plt>:
   1d800:      	adrp	x16, 0x22000
   1d804:      	ldr	x17, [x16, #0x2f0]
   1d808:      	add	x16, x16, #0x2f0
   1d80c:      	br	x17

000000000001d810 <strnlen@plt>:
   1d810:      	adrp	x16, 0x22000
   1d814:      	ldr	x17, [x16, #0x2f8]
   1d818:      	add	x16, x16, #0x2f8
   1d81c:      	br	x17

000000000001d820 <fopen@plt>:
   1d820:      	adrp	x16, 0x22000
   1d824:      	ldr	x17, [x16, #0x300]
   1d828:      	add	x16, x16, #0x300
   1d82c:      	br	x17

000000000001d830 <feof@plt>:
   1d830:      	adrp	x16, 0x22000
   1d834:      	ldr	x17, [x16, #0x308]
   1d838:      	add	x16, x16, #0x308
   1d83c:      	br	x17

000000000001d840 <fgets@plt>:
   1d840:      	adrp	x16, 0x22000
   1d844:      	ldr	x17, [x16, #0x310]
   1d848:      	add	x16, x16, #0x310
   1d84c:      	br	x17

000000000001d850 <fclose@plt>:
   1d850:      	adrp	x16, 0x22000
   1d854:      	ldr	x17, [x16, #0x318]
   1d858:      	add	x16, x16, #0x318
   1d85c:      	br	x17

000000000001d860 <calloc@plt>:
   1d860:      	adrp	x16, 0x22000
   1d864:      	ldr	x17, [x16, #0x320]
   1d868:      	add	x16, x16, #0x320
   1d86c:      	br	x17

000000000001d870 <malloc@plt>:
   1d870:      	adrp	x16, 0x22000
   1d874:      	ldr	x17, [x16, #0x328]
   1d878:      	add	x16, x16, #0x328
   1d87c:      	br	x17

000000000001d880 <free@plt>:
   1d880:      	adrp	x16, 0x22000
   1d884:      	ldr	x17, [x16, #0x330]
   1d888:      	add	x16, x16, #0x330
   1d88c:      	br	x17

000000000001d890 <__android_log_vprint@plt>:
   1d890:      	adrp	x16, 0x22000
   1d894:      	ldr	x17, [x16, #0x338]
   1d898:      	add	x16, x16, #0x338
   1d89c:      	br	x17

000000000001d8a0 <qsort@plt>:
   1d8a0:      	adrp	x16, 0x22000
   1d8a4:      	ldr	x17, [x16, #0x340]
   1d8a8:      	add	x16, x16, #0x340
   1d8ac:      	br	x17

000000000001d8b0 <strcmp@plt>:
   1d8b0:      	adrp	x16, 0x22000
   1d8b4:      	ldr	x17, [x16, #0x348]
   1d8b8:      	add	x16, x16, #0x348
   1d8bc:      	br	x17

000000000001d8c0 <strncmp@plt>:
   1d8c0:      	adrp	x16, 0x22000
   1d8c4:      	ldr	x17, [x16, #0x350]
   1d8c8:      	add	x16, x16, #0x350
   1d8cc:      	br	x17

000000000001d8d0 <memcmp@plt>:
   1d8d0:      	adrp	x16, 0x22000
   1d8d4:      	ldr	x17, [x16, #0x358]
   1d8d8:      	add	x16, x16, #0x358
   1d8dc:      	br	x17

000000000001d8e0 <__errno@plt>:
   1d8e0:      	adrp	x16, 0x22000
   1d8e4:      	ldr	x17, [x16, #0x360]
   1d8e8:      	add	x16, x16, #0x360
   1d8ec:      	br	x17

000000000001d8f0 <strerror@plt>:
   1d8f0:      	adrp	x16, 0x22000
   1d8f4:      	ldr	x17, [x16, #0x368]
   1d8f8:      	add	x16, x16, #0x368
   1d8fc:      	br	x17

000000000001d900 <strtoul@plt>:
   1d900:      	adrp	x16, 0x22000
   1d904:      	ldr	x17, [x16, #0x370]
   1d908:      	add	x16, x16, #0x370
   1d90c:      	br	x17

000000000001d910 <__memmove_chk@plt>:
   1d910:      	adrp	x16, 0x22000
   1d914:      	ldr	x17, [x16, #0x378]
   1d918:      	add	x16, x16, #0x378
   1d91c:      	br	x17

000000000001d920 <fflush@plt>:
   1d920:      	adrp	x16, 0x22000
   1d924:      	ldr	x17, [x16, #0x380]
   1d928:      	add	x16, x16, #0x380
   1d92c:      	br	x17

000000000001d930 <pthread_rwlock_wrlock@plt>:
   1d930:      	adrp	x16, 0x22000
   1d934:      	ldr	x17, [x16, #0x388]
   1d938:      	add	x16, x16, #0x388
   1d93c:      	br	x17

000000000001d940 <pthread_rwlock_unlock@plt>:
   1d940:      	adrp	x16, 0x22000
   1d944:      	ldr	x17, [x16, #0x390]
   1d948:      	add	x16, x16, #0x390
   1d94c:      	br	x17

000000000001d950 <dl_iterate_phdr@plt>:
   1d950:      	adrp	x16, 0x22000
   1d954:      	ldr	x17, [x16, #0x398]
   1d958:      	add	x16, x16, #0x398
   1d95c:      	br	x17

000000000001d960 <pthread_rwlock_rdlock@plt>:
   1d960:      	adrp	x16, 0x22000
   1d964:      	ldr	x17, [x16, #0x3a0]
   1d968:      	add	x16, x16, #0x3a0
   1d96c:      	br	x17

000000000001d970 <getpid@plt>:
   1d970:      	adrp	x16, 0x22000
   1d974:      	ldr	x17, [x16, #0x3a8]
   1d978:      	add	x16, x16, #0x3a8
   1d97c:      	br	x17
