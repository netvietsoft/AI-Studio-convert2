// EXPORTED & PLT DISASSEMBLY FOR libarkernel3.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libarkernel3.so (SHA-256: E08C1D494EEF98759AA92594CA26420E097DF51965A4407CC639A97BBAF35442)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 1800, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libarkernel3.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000106f4f0 <.plt>:
 106f4f0:      	stp	x16, x30, [sp, #-0x10]!
 106f4f4:      	adrp	x16, 0x10ce000
 106f4f8:      	ldr	x17, [x16, #0x970]
 106f4fc:      	add	x16, x16, #0x970
 106f500:      	br	x17
 106f504:      	nop
 106f508:      	nop
 106f50c:      	nop

000000000106f510 <__cxa_finalize@plt>:
 106f510:      	adrp	x16, 0x10ce000
 106f514:      	ldr	x17, [x16, #0x978]
 106f518:      	add	x16, x16, #0x978
 106f51c:      	br	x17

000000000106f520 <__cxa_atexit@plt>:
 106f520:      	adrp	x16, 0x10ce000
 106f524:      	ldr	x17, [x16, #0x980]
 106f528:      	add	x16, x16, #0x980
 106f52c:      	br	x17

000000000106f530 <__register_atfork@plt>:
 106f530:      	adrp	x16, 0x10ce000
 106f534:      	ldr	x17, [x16, #0x988]
 106f538:      	add	x16, x16, #0x988
 106f53c:      	br	x17

000000000106f540 <_ZdlPv@plt>:
 106f540:      	adrp	x16, 0x10ce000
 106f544:      	ldr	x17, [x16, #0x990]
 106f548:      	add	x16, x16, #0x990
 106f54c:      	br	x17

000000000106f550 <memset@plt>:
 106f550:      	adrp	x16, 0x10ce000
 106f554:      	ldr	x17, [x16, #0x998]
 106f558:      	add	x16, x16, #0x998
 106f55c:      	br	x17

000000000106f560 <wgpuDeviceCreateRenderPipeline@plt>:
 106f560:      	adrp	x16, 0x10ce000
 106f564:      	ldr	x17, [x16, #0x9a0]
 106f568:      	add	x16, x16, #0x9a0
 106f56c:      	br	x17

000000000106f570 <wgpuRenderPassEncoderSetPipeline@plt>:
 106f570:      	adrp	x16, 0x10ce000
 106f574:      	ldr	x17, [x16, #0x9a8]
 106f578:      	add	x16, x16, #0x9a8
 106f57c:      	br	x17

000000000106f580 <wgpuRenderPassEncoderSetBlendConstant@plt>:
 106f580:      	adrp	x16, 0x10ce000
 106f584:      	ldr	x17, [x16, #0x9b0]
 106f588:      	add	x16, x16, #0x9b0
 106f58c:      	br	x17

000000000106f590 <wgpuRenderPassEncoderSetViewport@plt>:
 106f590:      	adrp	x16, 0x10ce000
 106f594:      	ldr	x17, [x16, #0x9b8]
 106f598:      	add	x16, x16, #0x9b8
 106f59c:      	br	x17

000000000106f5a0 <wgpuDeviceCreateSampler@plt>:
 106f5a0:      	adrp	x16, 0x10ce000
 106f5a4:      	ldr	x17, [x16, #0x9c0]
 106f5a8:      	add	x16, x16, #0x9c0
 106f5ac:      	br	x17

000000000106f5b0 <wgpuSamplerReference@plt>:
 106f5b0:      	adrp	x16, 0x10ce000
 106f5b4:      	ldr	x17, [x16, #0x9c8]
 106f5b8:      	add	x16, x16, #0x9c8
 106f5bc:      	br	x17

000000000106f5c0 <wgpuDeviceCreateBindGroup@plt>:
 106f5c0:      	adrp	x16, 0x10ce000
 106f5c4:      	ldr	x17, [x16, #0x9d0]
 106f5c8:      	add	x16, x16, #0x9d0
 106f5cc:      	br	x17

000000000106f5d0 <wgpuSamplerRelease@plt>:
 106f5d0:      	adrp	x16, 0x10ce000
 106f5d4:      	ldr	x17, [x16, #0x9d8]
 106f5d8:      	add	x16, x16, #0x9d8
 106f5dc:      	br	x17

000000000106f5e0 <wgpuRenderPassEncoderSetBindGroup@plt>:
 106f5e0:      	adrp	x16, 0x10ce000
 106f5e4:      	ldr	x17, [x16, #0x9e0]
 106f5e8:      	add	x16, x16, #0x9e0
 106f5ec:      	br	x17

000000000106f5f0 <wgpuBufferGetSize@plt>:
 106f5f0:      	adrp	x16, 0x10ce000
 106f5f4:      	ldr	x17, [x16, #0x9e8]
 106f5f8:      	add	x16, x16, #0x9e8
 106f5fc:      	br	x17

000000000106f600 <wgpuRenderPassEncoderSetVertexBuffer@plt>:
 106f600:      	adrp	x16, 0x10ce000
 106f604:      	ldr	x17, [x16, #0x9f0]
 106f608:      	add	x16, x16, #0x9f0
 106f60c:      	br	x17

000000000106f610 <wgpuRenderPassEncoderSetIndexBuffer@plt>:
 106f610:      	adrp	x16, 0x10ce000
 106f614:      	ldr	x17, [x16, #0x9f8]
 106f618:      	add	x16, x16, #0x9f8
 106f61c:      	br	x17

000000000106f620 <wgpuRenderPassEncoderDrawIndexed@plt>:
 106f620:      	adrp	x16, 0x10ce000
 106f624:      	ldr	x17, [x16, #0xa00]
 106f628:      	add	x16, x16, #0xa00
 106f62c:      	br	x17

000000000106f630 <wgpuRenderPassEncoderDraw@plt>:
 106f630:      	adrp	x16, 0x10ce000
 106f634:      	ldr	x17, [x16, #0xa08]
 106f638:      	add	x16, x16, #0xa08
 106f63c:      	br	x17

000000000106f640 <wgpuRenderPipelineRelease@plt>:
 106f640:      	adrp	x16, 0x10ce000
 106f644:      	ldr	x17, [x16, #0xa10]
 106f648:      	add	x16, x16, #0xa10
 106f64c:      	br	x17

000000000106f650 <wgpuBindGroupRelease@plt>:
 106f650:      	adrp	x16, 0x10ce000
 106f654:      	ldr	x17, [x16, #0xa18]
 106f658:      	add	x16, x16, #0xa18
 106f65c:      	br	x17

000000000106f660 <__stack_chk_fail@plt>:
 106f660:      	adrp	x16, 0x10ce000
 106f664:      	ldr	x17, [x16, #0xa20]
 106f668:      	add	x16, x16, #0xa20
 106f66c:      	br	x17

000000000106f670 <memmove@plt>:
 106f670:      	adrp	x16, 0x10ce000
 106f674:      	ldr	x17, [x16, #0xa28]
 106f678:      	add	x16, x16, #0xa28
 106f67c:      	br	x17

000000000106f680 <_ZNSt6__ndk19to_stringEi@plt>:
 106f680:      	adrp	x16, 0x10ce000
 106f684:      	ldr	x17, [x16, #0xa30]
 106f688:      	add	x16, x16, #0xa30
 106f68c:      	br	x17

000000000106f690 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
 106f690:      	adrp	x16, 0x10ce000
 106f694:      	ldr	x17, [x16, #0xa38]
 106f698:      	add	x16, x16, #0xa38
 106f69c:      	br	x17

000000000106f6a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
 106f6a0:      	adrp	x16, 0x10ce000
 106f6a4:      	ldr	x17, [x16, #0xa40]
 106f6a8:      	add	x16, x16, #0xa40
 106f6ac:      	br	x17

000000000106f6b0 <memcpy@plt>:
 106f6b0:      	adrp	x16, 0x10ce000
 106f6b4:      	ldr	x17, [x16, #0xa48]
 106f6b8:      	add	x16, x16, #0xa48
 106f6bc:      	br	x17

000000000106f6c0 <_Znwm@plt>:
 106f6c0:      	adrp	x16, 0x10ce000
 106f6c4:      	ldr	x17, [x16, #0xa50]
 106f6c8:      	add	x16, x16, #0xa50
 106f6cc:      	br	x17

000000000106f6d0 <__cxa_allocate_exception@plt>:
 106f6d0:      	adrp	x16, 0x10ce000
 106f6d4:      	ldr	x17, [x16, #0xa58]
 106f6d8:      	add	x16, x16, #0xa58
 106f6dc:      	br	x17

000000000106f6e0 <__cxa_throw@plt>:
 106f6e0:      	adrp	x16, 0x10ce000
 106f6e4:      	ldr	x17, [x16, #0xa60]
 106f6e8:      	add	x16, x16, #0xa60
 106f6ec:      	br	x17

000000000106f6f0 <__cxa_free_exception@plt>:
 106f6f0:      	adrp	x16, 0x10ce000
 106f6f4:      	ldr	x17, [x16, #0xa68]
 106f6f8:      	add	x16, x16, #0xa68
 106f6fc:      	br	x17

000000000106f700 <_ZNSt11logic_errorC2EPKc@plt>:
 106f700:      	adrp	x16, 0x10ce000
 106f704:      	ldr	x17, [x16, #0xa70]
 106f708:      	add	x16, x16, #0xa70
 106f70c:      	br	x17

000000000106f710 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
 106f710:      	adrp	x16, 0x10ce000
 106f714:      	ldr	x17, [x16, #0xa78]
 106f718:      	add	x16, x16, #0xa78
 106f71c:      	br	x17

000000000106f720 <strlen@plt>:
 106f720:      	adrp	x16, 0x10ce000
 106f724:      	ldr	x17, [x16, #0xa80]
 106f728:      	add	x16, x16, #0xa80
 106f72c:      	br	x17

000000000106f730 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
 106f730:      	adrp	x16, 0x10ce000
 106f734:      	ldr	x17, [x16, #0xa88]
 106f738:      	add	x16, x16, #0xa88
 106f73c:      	br	x17

000000000106f740 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
 106f740:      	adrp	x16, 0x10ce000
 106f744:      	ldr	x17, [x16, #0xa90]
 106f748:      	add	x16, x16, #0xa90
 106f74c:      	br	x17

000000000106f750 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
 106f750:      	adrp	x16, 0x10ce000
 106f754:      	ldr	x17, [x16, #0xa98]
 106f758:      	add	x16, x16, #0xa98
 106f75c:      	br	x17

000000000106f760 <__strlen_chk@plt>:
 106f760:      	adrp	x16, 0x10ce000
 106f764:      	ldr	x17, [x16, #0xaa0]
 106f768:      	add	x16, x16, #0xaa0
 106f76c:      	br	x17

000000000106f770 <strcmp@plt>:
 106f770:      	adrp	x16, 0x10ce000
 106f774:      	ldr	x17, [x16, #0xaa8]
 106f778:      	add	x16, x16, #0xaa8
 106f77c:      	br	x17

000000000106f780 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
 106f780:      	adrp	x16, 0x10ce000
 106f784:      	ldr	x17, [x16, #0xab0]
 106f788:      	add	x16, x16, #0xab0
 106f78c:      	br	x17

000000000106f790 <memcmp@plt>:
 106f790:      	adrp	x16, 0x10ce000
 106f794:      	ldr	x17, [x16, #0xab8]
 106f798:      	add	x16, x16, #0xab8
 106f79c:      	br	x17

000000000106f7a0 <__android_log_print@plt>:
 106f7a0:      	adrp	x16, 0x10ce000
 106f7a4:      	ldr	x17, [x16, #0xac0]
 106f7a8:      	add	x16, x16, #0xac0
 106f7ac:      	br	x17

000000000106f7b0 <_ZNSt6__ndk19to_stringEm@plt>:
 106f7b0:      	adrp	x16, 0x10ce000
 106f7b4:      	ldr	x17, [x16, #0xac8]
 106f7b8:      	add	x16, x16, #0xac8
 106f7bc:      	br	x17

000000000106f7c0 <__cxa_begin_catch@plt>:
 106f7c0:      	adrp	x16, 0x10ce000
 106f7c4:      	ldr	x17, [x16, #0xad0]
 106f7c8:      	add	x16, x16, #0xad0
 106f7cc:      	br	x17

000000000106f7d0 <_ZSt9terminatev@plt>:
 106f7d0:      	adrp	x16, 0x10ce000
 106f7d4:      	ldr	x17, [x16, #0xad8]
 106f7d8:      	add	x16, x16, #0xad8
 106f7dc:      	br	x17

000000000106f7e0 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
 106f7e0:      	adrp	x16, 0x10ce000
 106f7e4:      	ldr	x17, [x16, #0xae0]
 106f7e8:      	add	x16, x16, #0xae0
 106f7ec:      	br	x17

000000000106f7f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
 106f7f0:      	adrp	x16, 0x10ce000
 106f7f4:      	ldr	x17, [x16, #0xae8]
 106f7f8:      	add	x16, x16, #0xae8
 106f7fc:      	br	x17

000000000106f800 <_ZN5image16toConvertChannelIfEENS_11DetailImageIT_EEOS3_h@plt>:
 106f800:      	adrp	x16, 0x10ce000
 106f804:      	ldr	x17, [x16, #0xaf0]
 106f808:      	add	x16, x16, #0xaf0
 106f80c:      	br	x17

000000000106f810 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
 106f810:      	adrp	x16, 0x10ce000
 106f814:      	ldr	x17, [x16, #0xaf8]
 106f818:      	add	x16, x16, #0xaf8
 106f81c:      	br	x17

000000000106f820 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
 106f820:      	adrp	x16, 0x10ce000
 106f824:      	ldr	x17, [x16, #0xb00]
 106f828:      	add	x16, x16, #0xb00
 106f82c:      	br	x17

000000000106f830 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
 106f830:      	adrp	x16, 0x10ce000
 106f834:      	ldr	x17, [x16, #0xb08]
 106f838:      	add	x16, x16, #0xb08
 106f83c:      	br	x17

000000000106f840 <_ZNSt6__ndk18ios_base4initEPv@plt>:
 106f840:      	adrp	x16, 0x10ce000
 106f844:      	ldr	x17, [x16, #0xb10]
 106f848:      	add	x16, x16, #0xb10
 106f84c:      	br	x17

000000000106f850 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
 106f850:      	adrp	x16, 0x10ce000
 106f854:      	ldr	x17, [x16, #0xb18]
 106f858:      	add	x16, x16, #0xb18
 106f85c:      	br	x17

000000000106f860 <_ZN5image11DetailImageIfEC2Ejjj@plt>:
 106f860:      	adrp	x16, 0x10ce000
 106f864:      	ldr	x17, [x16, #0xb20]
 106f868:      	add	x16, x16, #0xb20
 106f86c:      	br	x17

000000000106f870 <malloc@plt>:
 106f870:      	adrp	x16, 0x10ce000
 106f874:      	ldr	x17, [x16, #0xb28]
 106f878:      	add	x16, x16, #0xb28
 106f87c:      	br	x17

000000000106f880 <free@plt>:
 106f880:      	adrp	x16, 0x10ce000
 106f884:      	ldr	x17, [x16, #0xb30]
 106f888:      	add	x16, x16, #0xb30
 106f88c:      	br	x17

000000000106f890 <_ZN5image16toConvertChannelIhEENS_11DetailImageIT_EEOS3_h@plt>:
 106f890:      	adrp	x16, 0x10ce000
 106f894:      	ldr	x17, [x16, #0xb38]
 106f898:      	add	x16, x16, #0xb38
 106f89c:      	br	x17

000000000106f8a0 <_ZN5image11DetailImageIhEC2Ejjj@plt>:
 106f8a0:      	adrp	x16, 0x10ce000
 106f8a4:      	ldr	x17, [x16, #0xb40]
 106f8a8:      	add	x16, x16, #0xb40
 106f8ac:      	br	x17

000000000106f8b0 <wgpuBufferRelease@plt>:
 106f8b0:      	adrp	x16, 0x10ce000
 106f8b4:      	ldr	x17, [x16, #0xb48]
 106f8b8:      	add	x16, x16, #0xb48
 106f8bc:      	br	x17

000000000106f8c0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
 106f8c0:      	adrp	x16, 0x10ce000
 106f8c4:      	ldr	x17, [x16, #0xb50]
 106f8c8:      	add	x16, x16, #0xb50
 106f8cc:      	br	x17

000000000106f8d0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
 106f8d0:      	adrp	x16, 0x10ce000
 106f8d4:      	ldr	x17, [x16, #0xb58]
 106f8d8:      	add	x16, x16, #0xb58
 106f8dc:      	br	x17

000000000106f8e0 <_ZNSt6__ndk16localeD1Ev@plt>:
 106f8e0:      	adrp	x16, 0x10ce000
 106f8e4:      	ldr	x17, [x16, #0xb60]
 106f8e8:      	add	x16, x16, #0xb60
 106f8ec:      	br	x17

000000000106f8f0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPclc@plt>:
 106f8f0:      	adrp	x16, 0x10ce000
 106f8f4:      	ldr	x17, [x16, #0xb68]
 106f8f8:      	add	x16, x16, #0xb68
 106f8fc:      	br	x17

000000000106f900 <strncmp@plt>:
 106f900:      	adrp	x16, 0x10ce000
 106f904:      	ldr	x17, [x16, #0xb70]
 106f908:      	add	x16, x16, #0xb70
 106f90c:      	br	x17

000000000106f910 <__strchr_chk@plt>:
 106f910:      	adrp	x16, 0x10ce000
 106f914:      	ldr	x17, [x16, #0xb78]
 106f918:      	add	x16, x16, #0xb78
 106f91c:      	br	x17

000000000106f920 <strtok_r@plt>:
 106f920:      	adrp	x16, 0x10ce000
 106f924:      	ldr	x17, [x16, #0xb80]
 106f928:      	add	x16, x16, #0xb80
 106f92c:      	br	x17

000000000106f930 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
 106f930:      	adrp	x16, 0x10ce000
 106f934:      	ldr	x17, [x16, #0xb88]
 106f938:      	add	x16, x16, #0xb88
 106f93c:      	br	x17

000000000106f940 <memchr@plt>:
 106f940:      	adrp	x16, 0x10ce000
 106f944:      	ldr	x17, [x16, #0xb90]
 106f948:      	add	x16, x16, #0xb90
 106f94c:      	br	x17

000000000106f950 <strncpy@plt>:
 106f950:      	adrp	x16, 0x10ce000
 106f954:      	ldr	x17, [x16, #0xb98]
 106f958:      	add	x16, x16, #0xb98
 106f95c:      	br	x17

000000000106f960 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
 106f960:      	adrp	x16, 0x10ce000
 106f964:      	ldr	x17, [x16, #0xba0]
 106f968:      	add	x16, x16, #0xba0
 106f96c:      	br	x17

000000000106f970 <sscanf@plt>:
 106f970:      	adrp	x16, 0x10ce000
 106f974:      	ldr	x17, [x16, #0xba8]
 106f978:      	add	x16, x16, #0xba8
 106f97c:      	br	x17

000000000106f980 <strchr@plt>:
 106f980:      	adrp	x16, 0x10ce000
 106f984:      	ldr	x17, [x16, #0xbb0]
 106f988:      	add	x16, x16, #0xbb0
 106f98c:      	br	x17

000000000106f990 <__cxa_rethrow@plt>:
 106f990:      	adrp	x16, 0x10ce000
 106f994:      	ldr	x17, [x16, #0xbb8]
 106f998:      	add	x16, x16, #0xbb8
 106f99c:      	br	x17

000000000106f9a0 <__cxa_end_catch@plt>:
 106f9a0:      	adrp	x16, 0x10ce000
 106f9a4:      	ldr	x17, [x16, #0xbc0]
 106f9a8:      	add	x16, x16, #0xbc0
 106f9ac:      	br	x17

000000000106f9b0 <__emutls_get_address@plt>:
 106f9b0:      	adrp	x16, 0x10ce000
 106f9b4:      	ldr	x17, [x16, #0xbc8]
 106f9b8:      	add	x16, x16, #0xbc8
 106f9bc:      	br	x17

000000000106f9c0 <wgpuTextureGetWidth@plt>:
 106f9c0:      	adrp	x16, 0x10ce000
 106f9c4:      	ldr	x17, [x16, #0xbd0]
 106f9c8:      	add	x16, x16, #0xbd0
 106f9cc:      	br	x17

000000000106f9d0 <wgpuTextureGetHeight@plt>:
 106f9d0:      	adrp	x16, 0x10ce000
 106f9d4:      	ldr	x17, [x16, #0xbd8]
 106f9d8:      	add	x16, x16, #0xbd8
 106f9dc:      	br	x17

000000000106f9e0 <wgpuTextureGetDimension@plt>:
 106f9e0:      	adrp	x16, 0x10ce000
 106f9e4:      	ldr	x17, [x16, #0xbe0]
 106f9e8:      	add	x16, x16, #0xbe0
 106f9ec:      	br	x17

000000000106f9f0 <wgpuTextureGetMipLevelCount@plt>:
 106f9f0:      	adrp	x16, 0x10ce000
 106f9f4:      	ldr	x17, [x16, #0xbe8]
 106f9f8:      	add	x16, x16, #0xbe8
 106f9fc:      	br	x17

000000000106fa00 <wgpuTextureGetFormat@plt>:
 106fa00:      	adrp	x16, 0x10ce000
 106fa04:      	ldr	x17, [x16, #0xbf0]
 106fa08:      	add	x16, x16, #0xbf0
 106fa0c:      	br	x17

000000000106fa10 <wgpuTextureRelease@plt>:
 106fa10:      	adrp	x16, 0x10ce000
 106fa14:      	ldr	x17, [x16, #0xbf8]
 106fa18:      	add	x16, x16, #0xbf8
 106fa1c:      	br	x17

000000000106fa20 <wgpuTextureViewRelease@plt>:
 106fa20:      	adrp	x16, 0x10ce000
 106fa24:      	ldr	x17, [x16, #0xc00]
 106fa28:      	add	x16, x16, #0xc00
 106fa2c:      	br	x17

000000000106fa30 <wgpuTextureReference@plt>:
 106fa30:      	adrp	x16, 0x10ce000
 106fa34:      	ldr	x17, [x16, #0xc08]
 106fa38:      	add	x16, x16, #0xc08
 106fa3c:      	br	x17

000000000106fa40 <wgpuTextureViewReference@plt>:
 106fa40:      	adrp	x16, 0x10ce000
 106fa44:      	ldr	x17, [x16, #0xc10]
 106fa48:      	add	x16, x16, #0xc10
 106fa4c:      	br	x17

000000000106fa50 <wgpuQueueWriteTexture@plt>:
 106fa50:      	adrp	x16, 0x10ce000
 106fa54:      	ldr	x17, [x16, #0xc18]
 106fa58:      	add	x16, x16, #0xc18
 106fa5c:      	br	x17

000000000106fa60 <vsnprintf@plt>:
 106fa60:      	adrp	x16, 0x10ce000
 106fa64:      	ldr	x17, [x16, #0xc20]
 106fa68:      	add	x16, x16, #0xc20
 106fa6c:      	br	x17

000000000106fa70 <_ZNK8mtlabar311DataRequire22requireSourceGrayImageEv@plt>:
 106fa70:      	adrp	x16, 0x10ce000
 106fa74:      	ldr	x17, [x16, #0xc28]
 106fa78:      	add	x16, x16, #0xc28
 106fa7c:      	br	x17

000000000106fa80 <_ZNK8mtlabar311DataRequire23requireSourceColorImageEv@plt>:
 106fa80:      	adrp	x16, 0x10ce000
 106fa84:      	ldr	x17, [x16, #0xc30]
 106fa88:      	add	x16, x16, #0xc30
 106fa8c:      	br	x17

000000000106fa90 <_ZNK8mtlabar311DataRequire21requireSourceImageGPUEv@plt>:
 106fa90:      	adrp	x16, 0x10ce000
 106fa94:      	ldr	x17, [x16, #0xc38]
 106fa98:      	add	x16, x16, #0xc38
 106fa9c:      	br	x17

000000000106faa0 <_ZNK8mtlabar311DataRequire20requireTouchListenerEv@plt>:
 106faa0:      	adrp	x16, 0x10ce000
 106faa4:      	ldr	x17, [x16, #0xc40]
 106faa8:      	add	x16, x16, #0xc40
 106faac:      	br	x17

000000000106fab0 <_ZNK8mtlabar311DataRequire17requireAnimalDataEv@plt>:
 106fab0:      	adrp	x16, 0x10ce000
 106fab4:      	ldr	x17, [x16, #0xc48]
 106fab8:      	add	x16, x16, #0xc48
 106fabc:      	br	x17

000000000106fac0 <_ZNK8mtlabar311DataRequire15requireFoodDataEv@plt>:
 106fac0:      	adrp	x16, 0x10ce000
 106fac4:      	ldr	x17, [x16, #0xc50]
 106fac8:      	add	x16, x16, #0xc50
 106facc:      	br	x17

000000000106fad0 <_ZNK8mtlabar311DataRequire15requireFaceDataEv@plt>:
 106fad0:      	adrp	x16, 0x10ce000
 106fad4:      	ldr	x17, [x16, #0xc58]
 106fad8:      	add	x16, x16, #0xc58
 106fadc:      	br	x17

000000000106fae0 <_ZNK8mtlabar311DataRequire27requireFaceDataAdditionHeadEv@plt>:
 106fae0:      	adrp	x16, 0x10ce000
 106fae4:      	ldr	x17, [x16, #0xc60]
 106fae8:      	add	x16, x16, #0xc60
 106faec:      	br	x17

000000000106faf0 <_ZNK8mtlabar311DataRequire26requireFaceDataAdditionEarEv@plt>:
 106faf0:      	adrp	x16, 0x10ce000
 106faf4:      	ldr	x17, [x16, #0xc68]
 106faf8:      	add	x16, x16, #0xc68
 106fafc:      	br	x17

000000000106fb00 <_ZNK8mtlabar311DataRequire27requireFaceDataAdditionNeckEv@plt>:
 106fb00:      	adrp	x16, 0x10ce000
 106fb04:      	ldr	x17, [x16, #0xc70]
 106fb08:      	add	x16, x16, #0xc70
 106fb0c:      	br	x17

000000000106fb10 <_ZNK8mtlabar311DataRequire32requireFaceDataAdditionMouthMaskEv@plt>:
 106fb10:      	adrp	x16, 0x10ce000
 106fb14:      	ldr	x17, [x16, #0xc78]
 106fb18:      	add	x16, x16, #0xc78
 106fb1c:      	br	x17

000000000106fb20 <_ZNK8mtlabar311DataRequire31requireFaceDataAdditionFaceMaskEv@plt>:
 106fb20:      	adrp	x16, 0x10ce000
 106fb24:      	ldr	x17, [x16, #0xc80]
 106fb28:      	add	x16, x16, #0xc80
 106fb2c:      	br	x17

000000000106fb30 <_ZNK8mtlabar311DataRequire35requireFaceDataAdditionPosEstimatorEv@plt>:
 106fb30:      	adrp	x16, 0x10ce000
 106fb34:      	ldr	x17, [x16, #0xc88]
 106fb38:      	add	x16, x16, #0xc88
 106fb3c:      	br	x17

000000000106fb40 <_ZNK8mtlabar311DataRequire29requireFaceDataAdditionGenderEv@plt>:
 106fb40:      	adrp	x16, 0x10ce000
 106fb44:      	ldr	x17, [x16, #0xc90]
 106fb48:      	add	x16, x16, #0xc90
 106fb4c:      	br	x17

000000000106fb50 <_ZNK8mtlabar311DataRequire26requireFaceDataAdditionAgeEv@plt>:
 106fb50:      	adrp	x16, 0x10ce000
 106fb54:      	ldr	x17, [x16, #0xc98]
 106fb58:      	add	x16, x16, #0xc98
 106fb5c:      	br	x17

000000000106fb60 <_ZNK8mtlabar311DataRequire29requireFaceDataAdditionEyelidEv@plt>:
 106fb60:      	adrp	x16, 0x10ce000
 106fb64:      	ldr	x17, [x16, #0xca0]
 106fb68:      	add	x16, x16, #0xca0
 106fb6c:      	br	x17

000000000106fb70 <_ZNK8mtlabar311DataRequire30requireFaceDataAdditionEmotionEv@plt>:
 106fb70:      	adrp	x16, 0x10ce000
 106fb74:      	ldr	x17, [x16, #0xca8]
 106fb78:      	add	x16, x16, #0xca8
 106fb7c:      	br	x17

000000000106fb80 <_ZNK8mtlabar311DataRequire27requireFaceDataAddition3DFAEv@plt>:
 106fb80:      	adrp	x16, 0x10ce000
 106fb84:      	ldr	x17, [x16, #0xcb0]
 106fb88:      	add	x16, x16, #0xcb0
 106fb8c:      	br	x17

000000000106fb90 <_ZNK8mtlabar311DataRequire31requireFaceDataAddition3DFAMeshEv@plt>:
 106fb90:      	adrp	x16, 0x10ce000
 106fb94:      	ldr	x17, [x16, #0xcb8]
 106fb98:      	add	x16, x16, #0xcb8
 106fb9c:      	br	x17

000000000106fba0 <_ZNK8mtlabar311DataRequire34requireFaceDataAdditionMakeupAdaptEv@plt>:
 106fba0:      	adrp	x16, 0x10ce000
 106fba4:      	ldr	x17, [x16, #0xcc0]
 106fba8:      	add	x16, x16, #0xcc0
 106fbac:      	br	x17

000000000106fbb0 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV1DataEv@plt>:
 106fbb0:      	adrp	x16, 0x10ce000
 106fbb4:      	ldr	x17, [x16, #0xcc8]
 106fbb8:      	add	x16, x16, #0xcc8
 106fbbc:      	br	x17

000000000106fbc0 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV2DataEv@plt>:
 106fbc0:      	adrp	x16, 0x10ce000
 106fbc4:      	ldr	x17, [x16, #0xcd0]
 106fbc8:      	add	x16, x16, #0xcd0
 106fbcc:      	br	x17

000000000106fbd0 <_ZNK8mtlabar311DataRequire32requireFace2DReconstructorV3DataEv@plt>:
 106fbd0:      	adrp	x16, 0x10ce000
 106fbd4:      	ldr	x17, [x16, #0xcd8]
 106fbd8:      	add	x16, x16, #0xcd8
 106fbdc:      	br	x17

000000000106fbe0 <_ZNK8mtlabar311DataRequire40requireFace2DBackgroundReconstructorDataEv@plt>:
 106fbe0:      	adrp	x16, 0x10ce000
 106fbe4:      	ldr	x17, [x16, #0xce0]
 106fbe8:      	add	x16, x16, #0xce0
 106fbec:      	br	x17

000000000106fbf0 <_ZNK8mtlabar311DataRequire30requireFace3DReconstructorDataEv@plt>:
 106fbf0:      	adrp	x16, 0x10ce000
 106fbf4:      	ldr	x17, [x16, #0xce8]
 106fbf8:      	add	x16, x16, #0xce8
 106fbfc:      	br	x17

000000000106fc00 <_ZNK8mtlabar311DataRequire19requireFaceDL3DDataEv@plt>:
 106fc00:      	adrp	x16, 0x10ce000
 106fc04:      	ldr	x17, [x16, #0xcf0]
 106fc08:      	add	x16, x16, #0xcf0
 106fc0c:      	br	x17

000000000106fc10 <_ZNK8mtlabar311DataRequire31requireFaceDL3DDataAdditionMeshEv@plt>:
 106fc10:      	adrp	x16, 0x10ce000
 106fc14:      	ldr	x17, [x16, #0xcf8]
 106fc18:      	add	x16, x16, #0xcf8
 106fc1c:      	br	x17

000000000106fc20 <_ZNK8mtlabar311DataRequire34requireFaceDL3DDataAdditionRiggingEv@plt>:
 106fc20:      	adrp	x16, 0x10ce000
 106fc24:      	ldr	x17, [x16, #0xd00]
 106fc28:      	add	x16, x16, #0xd00
 106fc2c:      	br	x17

000000000106fc30 <_ZNK8mtlabar311DataRequire19requireShoulderDataEv@plt>:
 106fc30:      	adrp	x16, 0x10ce000
 106fc34:      	ldr	x17, [x16, #0xd08]
 106fc38:      	add	x16, x16, #0xd08
 106fc3c:      	br	x17

000000000106fc40 <_ZNK8mtlabar311DataRequire15requireHandDataEv@plt>:
 106fc40:      	adrp	x16, 0x10ce000
 106fc44:      	ldr	x17, [x16, #0xd10]
 106fc48:      	add	x16, x16, #0xd10
 106fc4c:      	br	x17

000000000106fc50 <_ZNK8mtlabar311DataRequire27requireHandDataAdditionPoseEv@plt>:
 106fc50:      	adrp	x16, 0x10ce000
 106fc54:      	ldr	x17, [x16, #0xd18]
 106fc58:      	add	x16, x16, #0xd18
 106fc5c:      	br	x17

000000000106fc60 <_ZNK8mtlabar311DataRequire16requireNailsDataEv@plt>:
 106fc60:      	adrp	x16, 0x10ce000
 106fc64:      	ldr	x17, [x16, #0xd20]
 106fc68:      	add	x16, x16, #0xd20
 106fc6c:      	br	x17

000000000106fc70 <_ZNK8mtlabar311DataRequire15requireBodyMaskEv@plt>:
 106fc70:      	adrp	x16, 0x10ce000
 106fc74:      	ldr	x17, [x16, #0xd28]
 106fc78:      	add	x16, x16, #0xd28
 106fc7c:      	br	x17

000000000106fc80 <_ZNK8mtlabar311DataRequire26requireBodyMaskAdditionCPUEv@plt>:
 106fc80:      	adrp	x16, 0x10ce000
 106fc84:      	ldr	x17, [x16, #0xd30]
 106fc88:      	add	x16, x16, #0xd30
 106fc8c:      	br	x17

000000000106fc90 <_ZNK8mtlabar311DataRequire26requireBodyMaskAdditionGPUEv@plt>:
 106fc90:      	adrp	x16, 0x10ce000
 106fc94:      	ldr	x17, [x16, #0xd38]
 106fc98:      	add	x16, x16, #0xd38
 106fc9c:      	br	x17

000000000106fca0 <_ZNK8mtlabar311DataRequire15requireHairMaskEv@plt>:
 106fca0:      	adrp	x16, 0x10ce000
 106fca4:      	ldr	x17, [x16, #0xd40]
 106fca8:      	add	x16, x16, #0xd40
 106fcac:      	br	x17

000000000106fcb0 <_ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv@plt>:
 106fcb0:      	adrp	x16, 0x10ce000
 106fcb4:      	ldr	x17, [x16, #0xd48]
 106fcb8:      	add	x16, x16, #0xd48
 106fcbc:      	br	x17

000000000106fcc0 <_ZNK8mtlabar311DataRequire26requireHairMaskAdditionGPUEv@plt>:
 106fcc0:      	adrp	x16, 0x10ce000
 106fcc4:      	ldr	x17, [x16, #0xd50]
 106fcc8:      	add	x16, x16, #0xd50
 106fccc:      	br	x17

000000000106fcd0 <_ZNK8mtlabar311DataRequire14requireSkyMaskEv@plt>:
 106fcd0:      	adrp	x16, 0x10ce000
 106fcd4:      	ldr	x17, [x16, #0xd58]
 106fcd8:      	add	x16, x16, #0xd58
 106fcdc:      	br	x17

000000000106fce0 <_ZNK8mtlabar311DataRequire25requireSkyMaskAdditionCPUEv@plt>:
 106fce0:      	adrp	x16, 0x10ce000
 106fce4:      	ldr	x17, [x16, #0xd60]
 106fce8:      	add	x16, x16, #0xd60
 106fcec:      	br	x17

000000000106fcf0 <_ZNK8mtlabar311DataRequire25requireSkyMaskAdditionGPUEv@plt>:
 106fcf0:      	adrp	x16, 0x10ce000
 106fcf4:      	ldr	x17, [x16, #0xd68]
 106fcf8:      	add	x16, x16, #0xd68
 106fcfc:      	br	x17

000000000106fd00 <_ZNK8mtlabar311DataRequire15requireSkinMaskEv@plt>:
 106fd00:      	adrp	x16, 0x10ce000
 106fd04:      	ldr	x17, [x16, #0xd70]
 106fd08:      	add	x16, x16, #0xd70
 106fd0c:      	br	x17

000000000106fd10 <_ZNK8mtlabar311DataRequire26requireSkinMaskAdditionCPUEv@plt>:
 106fd10:      	adrp	x16, 0x10ce000
 106fd14:      	ldr	x17, [x16, #0xd78]
 106fd18:      	add	x16, x16, #0xd78
 106fd1c:      	br	x17

000000000106fd20 <_ZNK8mtlabar311DataRequire26requireSkinMaskAdditionGPUEv@plt>:
 106fd20:      	adrp	x16, 0x10ce000
 106fd24:      	ldr	x17, [x16, #0xd80]
 106fd28:      	add	x16, x16, #0xd80
 106fd2c:      	br	x17

000000000106fd30 <_ZNK8mtlabar311DataRequire15requireHeadMaskEv@plt>:
 106fd30:      	adrp	x16, 0x10ce000
 106fd34:      	ldr	x17, [x16, #0xd88]
 106fd38:      	add	x16, x16, #0xd88
 106fd3c:      	br	x17

000000000106fd40 <_ZNK8mtlabar311DataRequire26requireHeadMaskAdditionCPUEv@plt>:
 106fd40:      	adrp	x16, 0x10ce000
 106fd44:      	ldr	x17, [x16, #0xd90]
 106fd48:      	add	x16, x16, #0xd90
 106fd4c:      	br	x17

000000000106fd50 <_ZNK8mtlabar311DataRequire26requireHeadMaskAdditionGPUEv@plt>:
 106fd50:      	adrp	x16, 0x10ce000
 106fd54:      	ldr	x17, [x16, #0xd98]
 106fd58:      	add	x16, x16, #0xd98
 106fd5c:      	br	x17

000000000106fd60 <_ZNK8mtlabar311DataRequire22requireFaceContourMaskEv@plt>:
 106fd60:      	adrp	x16, 0x10ce000
 106fd64:      	ldr	x17, [x16, #0xda0]
 106fd68:      	add	x16, x16, #0xda0
 106fd6c:      	br	x17

000000000106fd70 <_ZNK8mtlabar311DataRequire16requireClothMaskEv@plt>:
 106fd70:      	adrp	x16, 0x10ce000
 106fd74:      	ldr	x17, [x16, #0xda8]
 106fd78:      	add	x16, x16, #0xda8
 106fd7c:      	br	x17

000000000106fd80 <_ZNK8mtlabar311DataRequire27requireClothMaskAdditionCPUEv@plt>:
 106fd80:      	adrp	x16, 0x10ce000
 106fd84:      	ldr	x17, [x16, #0xdb0]
 106fd88:      	add	x16, x16, #0xdb0
 106fd8c:      	br	x17

000000000106fd90 <_ZNK8mtlabar311DataRequire27requireClothMaskAdditionGPUEv@plt>:
 106fd90:      	adrp	x16, 0x10ce000
 106fd94:      	ldr	x17, [x16, #0xdb8]
 106fd98:      	add	x16, x16, #0xdb8
 106fd9c:      	br	x17

000000000106fda0 <_ZNK8mtlabar311DataRequire14requireEyeMaskEv@plt>:
 106fda0:      	adrp	x16, 0x10ce000
 106fda4:      	ldr	x17, [x16, #0xdc0]
 106fda8:      	add	x16, x16, #0xdc0
 106fdac:      	br	x17

000000000106fdb0 <_ZNK8mtlabar311DataRequire16requireBodyInOneEv@plt>:
 106fdb0:      	adrp	x16, 0x10ce000
 106fdb4:      	ldr	x17, [x16, #0xdc8]
 106fdb8:      	add	x16, x16, #0xdc8
 106fdbc:      	br	x17

000000000106fdc0 <_ZNK8mtlabar311DataRequire24requireBodyAdditionJointEv@plt>:
 106fdc0:      	adrp	x16, 0x10ce000
 106fdc4:      	ldr	x17, [x16, #0xdd0]
 106fdc8:      	add	x16, x16, #0xdd0
 106fdcc:      	br	x17

000000000106fdd0 <_ZNK8mtlabar311DataRequire26requireBodyAdditionContourEv@plt>:
 106fdd0:      	adrp	x16, 0x10ce000
 106fdd4:      	ldr	x17, [x16, #0xdd8]
 106fdd8:      	add	x16, x16, #0xdd8
 106fddc:      	br	x17

000000000106fde0 <_ZNK8mtlabar311DataRequire28requireARGyroscopeQuaternionEv@plt>:
 106fde0:      	adrp	x16, 0x10ce000
 106fde4:      	ldr	x17, [x16, #0xde0]
 106fde8:      	add	x16, x16, #0xde0
 106fdec:      	br	x17

000000000106fdf0 <_ZNK8mtlabar311DataRequire17requireARFaceMeshEv@plt>:
 106fdf0:      	adrp	x16, 0x10ce000
 106fdf4:      	ldr	x17, [x16, #0xde8]
 106fdf8:      	add	x16, x16, #0xde8
 106fdfc:      	br	x17

000000000106fe00 <_ZNK8mtlabar311DataRequire19requireARPointCloudEv@plt>:
 106fe00:      	adrp	x16, 0x10ce000
 106fe04:      	ldr	x17, [x16, #0xdf0]
 106fe08:      	add	x16, x16, #0xdf0
 106fe0c:      	br	x17

000000000106fe10 <_ZNK8mtlabar311DataRequire22requireARWorldTrackingEv@plt>:
 106fe10:      	adrp	x16, 0x10ce000
 106fe14:      	ldr	x17, [x16, #0xdf8]
 106fe18:      	add	x16, x16, #0xdf8
 106fe1c:      	br	x17

000000000106fe20 <_ZNK8mtlabar311DataRequire20requireARPlaneAnchorEv@plt>:
 106fe20:      	adrp	x16, 0x10ce000
 106fe24:      	ldr	x17, [x16, #0xe00]
 106fe28:      	add	x16, x16, #0xe00
 106fe2c:      	br	x17

000000000106fe30 <_ZNK8mtlabar311DataRequire22requireARLightEstimateEv@plt>:
 106fe30:      	adrp	x16, 0x10ce000
 106fe34:      	ldr	x17, [x16, #0xe08]
 106fe38:      	add	x16, x16, #0xe08
 106fe3c:      	br	x17

000000000106fe40 <_ZNK8mtlabar311DataRequire25requireARInstantPlacementEv@plt>:
 106fe40:      	adrp	x16, 0x10ce000
 106fe44:      	ldr	x17, [x16, #0xe10]
 106fe48:      	add	x16, x16, #0xe10
 106fe4c:      	br	x17

000000000106fe50 <_ZNK8mtlabar311DataRequire17requireARSkeletonEv@plt>:
 106fe50:      	adrp	x16, 0x10ce000
 106fe54:      	ldr	x17, [x16, #0xe18]
 106fe58:      	add	x16, x16, #0xe18
 106fe5c:      	br	x17

000000000106fe60 <_ZNK8mtlabar311DataRequire9requireCGEv@plt>:
 106fe60:      	adrp	x16, 0x10ce000
 106fe64:      	ldr	x17, [x16, #0xe20]
 106fe68:      	add	x16, x16, #0xe20
 106fe6c:      	br	x17

000000000106fe70 <_ZNK8mtlabar311DataRequire14requireHuman3DEv@plt>:
 106fe70:      	adrp	x16, 0x10ce000
 106fe74:      	ldr	x17, [x16, #0xe28]
 106fe78:      	add	x16, x16, #0xe28
 106fe7c:      	br	x17

000000000106fe80 <_ZNK8mtlabar311DataRequire17requireSpaceDepthEv@plt>:
 106fe80:      	adrp	x16, 0x10ce000
 106fe84:      	ldr	x17, [x16, #0xe30]
 106fe88:      	add	x16, x16, #0xe30
 106fe8c:      	br	x17

000000000106fe90 <_ZNK8mtlabar311DataRequire18requireSpaceNormalEv@plt>:
 106fe90:      	adrp	x16, 0x10ce000
 106fe94:      	ldr	x17, [x16, #0xe38]
 106fe98:      	add	x16, x16, #0xe38
 106fe9c:      	br	x17

000000000106fea0 <_ZNK8mtlabar311DataRequire26requireBodyBeautyBGFillingEv@plt>:
 106fea0:      	adrp	x16, 0x10ce000
 106fea4:      	ldr	x17, [x16, #0xe40]
 106fea8:      	add	x16, x16, #0xe40
 106feac:      	br	x17

000000000106feb0 <_ZNSt6__ndk112__next_primeEm@plt>:
 106feb0:      	adrp	x16, 0x10ce000
 106feb4:      	ldr	x17, [x16, #0xe48]
 106feb8:      	add	x16, x16, #0xe48
 106febc:      	br	x17

000000000106fec0 <acosf@plt>:
 106fec0:      	adrp	x16, 0x10ce000
 106fec4:      	ldr	x17, [x16, #0xe50]
 106fec8:      	add	x16, x16, #0xe50
 106fecc:      	br	x17

000000000106fed0 <sincosf@plt>:
 106fed0:      	adrp	x16, 0x10ce000
 106fed4:      	ldr	x17, [x16, #0xe58]
 106fed8:      	add	x16, x16, #0xe58
 106fedc:      	br	x17

000000000106fee0 <dlopen@plt>:
 106fee0:      	adrp	x16, 0x10ce000
 106fee4:      	ldr	x17, [x16, #0xe60]
 106fee8:      	add	x16, x16, #0xe60
 106feec:      	br	x17

000000000106fef0 <dlsym@plt>:
 106fef0:      	adrp	x16, 0x10ce000
 106fef4:      	ldr	x17, [x16, #0xe68]
 106fef8:      	add	x16, x16, #0xe68
 106fefc:      	br	x17

000000000106ff00 <dlclose@plt>:
 106ff00:      	adrp	x16, 0x10ce000
 106ff04:      	ldr	x17, [x16, #0xe70]
 106ff08:      	add	x16, x16, #0xe70
 106ff0c:      	br	x17

000000000106ff10 <_Znam@plt>:
 106ff10:      	adrp	x16, 0x10ce000
 106ff14:      	ldr	x17, [x16, #0xe78]
 106ff18:      	add	x16, x16, #0xe78
 106ff1c:      	br	x17

000000000106ff20 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf@plt>:
 106ff20:      	adrp	x16, 0x10ce000
 106ff24:      	ldr	x17, [x16, #0xe80]
 106ff28:      	add	x16, x16, #0xe80
 106ff2c:      	br	x17

000000000106ff30 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
 106ff30:      	adrp	x16, 0x10ce000
 106ff34:      	ldr	x17, [x16, #0xe88]
 106ff38:      	add	x16, x16, #0xe88
 106ff3c:      	br	x17

000000000106ff40 <_ZdaPv@plt>:
 106ff40:      	adrp	x16, 0x10ce000
 106ff44:      	ldr	x17, [x16, #0xe90]
 106ff48:      	add	x16, x16, #0xe90
 106ff4c:      	br	x17

000000000106ff50 <atan2f@plt>:
 106ff50:      	adrp	x16, 0x10ce000
 106ff54:      	ldr	x17, [x16, #0xe98]
 106ff58:      	add	x16, x16, #0xe98
 106ff5c:      	br	x17

000000000106ff60 <fmodf@plt>:
 106ff60:      	adrp	x16, 0x10ce000
 106ff64:      	ldr	x17, [x16, #0xea0]
 106ff68:      	add	x16, x16, #0xea0
 106ff6c:      	br	x17

000000000106ff70 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
 106ff70:      	adrp	x16, 0x10ce000
 106ff74:      	ldr	x17, [x16, #0xea8]
 106ff78:      	add	x16, x16, #0xea8
 106ff7c:      	br	x17

000000000106ff80 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
 106ff80:      	adrp	x16, 0x10ce000
 106ff84:      	ldr	x17, [x16, #0xeb0]
 106ff88:      	add	x16, x16, #0xeb0
 106ff8c:      	br	x17

000000000106ff90 <strtoul@plt>:
 106ff90:      	adrp	x16, 0x10ce000
 106ff94:      	ldr	x17, [x16, #0xeb8]
 106ff98:      	add	x16, x16, #0xeb8
 106ff9c:      	br	x17

000000000106ffa0 <atof@plt>:
 106ffa0:      	adrp	x16, 0x10ce000
 106ffa4:      	ldr	x17, [x16, #0xec0]
 106ffa8:      	add	x16, x16, #0xec0
 106ffac:      	br	x17

000000000106ffb0 <expf@plt>:
 106ffb0:      	adrp	x16, 0x10ce000
 106ffb4:      	ldr	x17, [x16, #0xec8]
 106ffb8:      	add	x16, x16, #0xec8
 106ffbc:      	br	x17

000000000106ffc0 <sinf@plt>:
 106ffc0:      	adrp	x16, 0x10ce000
 106ffc4:      	ldr	x17, [x16, #0xed0]
 106ffc8:      	add	x16, x16, #0xed0
 106ffcc:      	br	x17

000000000106ffd0 <cosf@plt>:
 106ffd0:      	adrp	x16, 0x10ce000
 106ffd4:      	ldr	x17, [x16, #0xed8]
 106ffd8:      	add	x16, x16, #0xed8
 106ffdc:      	br	x17

000000000106ffe0 <__cxa_guard_acquire@plt>:
 106ffe0:      	adrp	x16, 0x10ce000
 106ffe4:      	ldr	x17, [x16, #0xee0]
 106ffe8:      	add	x16, x16, #0xee0
 106ffec:      	br	x17

000000000106fff0 <__cxa_guard_release@plt>:
 106fff0:      	adrp	x16, 0x10ce000
 106fff4:      	ldr	x17, [x16, #0xee8]
 106fff8:      	add	x16, x16, #0xee8
 106fffc:      	br	x17

0000000001070000 <tanf@plt>:
 1070000:      	adrp	x16, 0x10ce000
 1070004:      	ldr	x17, [x16, #0xef0]
 1070008:      	add	x16, x16, #0xef0
 107000c:      	br	x17

0000000001070010 <asinf@plt>:
 1070010:      	adrp	x16, 0x10ce000
 1070014:      	ldr	x17, [x16, #0xef8]
 1070018:      	add	x16, x16, #0xef8
 107001c:      	br	x17

0000000001070020 <__dynamic_cast@plt>:
 1070020:      	adrp	x16, 0x10ce000
 1070024:      	ldr	x17, [x16, #0xf00]
 1070028:      	add	x16, x16, #0xf00
 107002c:      	br	x17

0000000001070030 <wgpuDeviceCreateTexture@plt>:
 1070030:      	adrp	x16, 0x10ce000
 1070034:      	ldr	x17, [x16, #0xf08]
 1070038:      	add	x16, x16, #0xf08
 107003c:      	br	x17

0000000001070040 <wgpuTextureCreateView@plt>:
 1070040:      	adrp	x16, 0x10ce000
 1070044:      	ldr	x17, [x16, #0xf10]
 1070048:      	add	x16, x16, #0xf10
 107004c:      	br	x17

0000000001070050 <_ZN8mtlabar326ActiveWordBGParamInterfaceC2Ev@plt>:
 1070050:      	adrp	x16, 0x10ce000
 1070054:      	ldr	x17, [x16, #0xf18]
 1070058:      	add	x16, x16, #0xf18
 107005c:      	br	x17

0000000001070060 <_ZN8mtlabar326ActiveWordBGParamInterfaceD2Ev@plt>:
 1070060:      	adrp	x16, 0x10ce000
 1070064:      	ldr	x17, [x16, #0xf20]
 1070068:      	add	x16, x16, #0xf20
 107006c:      	br	x17

0000000001070070 <_ZN8mtlabar313GlobalSetting12getDirectoryENS_13DirectoryTypeE@plt>:
 1070070:      	adrp	x16, 0x10ce000
 1070074:      	ldr	x17, [x16, #0xf28]
 1070078:      	add	x16, x16, #0xf28
 107007c:      	br	x17

0000000001070080 <_ZN8mtlabar321ActiveWordBgInterfaceC2Ev@plt>:
 1070080:      	adrp	x16, 0x10ce000
 1070084:      	ldr	x17, [x16, #0xf30]
 1070088:      	add	x16, x16, #0xf30
 107008c:      	br	x17

0000000001070090 <_ZN8mtlabar321ActiveWordBgInterfaceD2Ev@plt>:
 1070090:      	adrp	x16, 0x10ce000
 1070094:      	ldr	x17, [x16, #0xf38]
 1070098:      	add	x16, x16, #0xf38
 107009c:      	br	x17

00000000010700a0 <pow@plt>:
 10700a0:      	adrp	x16, 0x10ce000
 10700a4:      	ldr	x17, [x16, #0xf40]
 10700a8:      	add	x16, x16, #0xf40
 10700ac:      	br	x17

00000000010700b0 <fmod@plt>:
 10700b0:      	adrp	x16, 0x10ce000
 10700b4:      	ldr	x17, [x16, #0xf48]
 10700b8:      	add	x16, x16, #0xf48
 10700bc:      	br	x17

00000000010700c0 <powf@plt>:
 10700c0:      	adrp	x16, 0x10ce000
 10700c4:      	ldr	x17, [x16, #0xf50]
 10700c8:      	add	x16, x16, #0xf50
 10700cc:      	br	x17

00000000010700d0 <_ZN8mtlabar324CustomTransformInterfaceD2Ev@plt>:
 10700d0:      	adrp	x16, 0x10ce000
 10700d4:      	ldr	x17, [x16, #0xf58]
 10700d8:      	add	x16, x16, #0xf58
 10700dc:      	br	x17

00000000010700e0 <_ZN8mtlabar323TextWarpConfigInterfaceD2Ev@plt>:
 10700e0:      	adrp	x16, 0x10ce000
 10700e4:      	ldr	x17, [x16, #0xf60]
 10700e8:      	add	x16, x16, #0xf60
 10700ec:      	br	x17

00000000010700f0 <_ZN8mtlabar324ActiveWordStyleInterfaceD2Ev@plt>:
 10700f0:      	adrp	x16, 0x10ce000
 10700f4:      	ldr	x17, [x16, #0xf68]
 10700f8:      	add	x16, x16, #0xf68
 10700fc:      	br	x17

0000000001070100 <_ZN8mtlabar324ActiveWordColorInterfaceD2Ev@plt>:
 1070100:      	adrp	x16, 0x10ce000
 1070104:      	ldr	x17, [x16, #0xf70]
 1070108:      	add	x16, x16, #0xf70
 107010c:      	br	x17

0000000001070110 <wgpuTextureSetLabel@plt>:
 1070110:      	adrp	x16, 0x10ce000
 1070114:      	ldr	x17, [x16, #0xf78]
 1070118:      	add	x16, x16, #0xf78
 107011c:      	br	x17

0000000001070120 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm@plt>:
 1070120:      	adrp	x16, 0x10ce000
 1070124:      	ldr	x17, [x16, #0xf80]
 1070128:      	add	x16, x16, #0xf80
 107012c:      	br	x17

0000000001070130 <_ZNSt6__ndk19to_stringEf@plt>:
 1070130:      	adrp	x16, 0x10ce000
 1070134:      	ldr	x17, [x16, #0xf88]
 1070138:      	add	x16, x16, #0xf88
 107013c:      	br	x17

0000000001070140 <_ZN8mtlabar324CustomTransformInterfaceC2Ev@plt>:
 1070140:      	adrp	x16, 0x10ce000
 1070144:      	ldr	x17, [x16, #0xf90]
 1070148:      	add	x16, x16, #0xf90
 107014c:      	br	x17

0000000001070150 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
 1070150:      	adrp	x16, 0x10ce000
 1070154:      	ldr	x17, [x16, #0xf98]
 1070158:      	add	x16, x16, #0xf98
 107015c:      	br	x17

0000000001070160 <_ZNSt6__ndk113random_deviceD1Ev@plt>:
 1070160:      	adrp	x16, 0x10ce000
 1070164:      	ldr	x17, [x16, #0xfa0]
 1070168:      	add	x16, x16, #0xfa0
 107016c:      	br	x17

0000000001070170 <_ZNSt6__ndk113random_deviceC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
 1070170:      	adrp	x16, 0x10ce000
 1070174:      	ldr	x17, [x16, #0xfa8]
 1070178:      	add	x16, x16, #0xfa8
 107017c:      	br	x17

0000000001070180 <_ZNSt9bad_allocC1Ev@plt>:
 1070180:      	adrp	x16, 0x10ce000
 1070184:      	ldr	x17, [x16, #0xfb0]
 1070188:      	add	x16, x16, #0xfb0
 107018c:      	br	x17

0000000001070190 <fwrite@plt>:
 1070190:      	adrp	x16, 0x10ce000
 1070194:      	ldr	x17, [x16, #0xfb8]
 1070198:      	add	x16, x16, #0xfb8
 107019c:      	br	x17

00000000010701a0 <_ZNSt9exceptionD2Ev@plt>:
 10701a0:      	adrp	x16, 0x10ce000
 10701a4:      	ldr	x17, [x16, #0xfc0]
 10701a8:      	add	x16, x16, #0xfc0
 10701ac:      	br	x17

00000000010701b0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
 10701b0:      	adrp	x16, 0x10ce000
 10701b4:      	ldr	x17, [x16, #0xfc8]
 10701b8:      	add	x16, x16, #0xfc8
 10701bc:      	br	x17

00000000010701c0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
 10701c0:      	adrp	x16, 0x10ce000
 10701c4:      	ldr	x17, [x16, #0xfd0]
 10701c8:      	add	x16, x16, #0xfd0
 10701cc:      	br	x17

00000000010701d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
 10701d0:      	adrp	x16, 0x10ce000
 10701d4:      	ldr	x17, [x16, #0xfd8]
 10701d8:      	add	x16, x16, #0xfd8
 10701dc:      	br	x17

00000000010701e0 <_ZNSt6__ndk18ios_base5clearEj@plt>:
 10701e0:      	adrp	x16, 0x10ce000
 10701e4:      	ldr	x17, [x16, #0xfe0]
 10701e8:      	add	x16, x16, #0xfe0
 10701ec:      	br	x17

00000000010701f0 <__memcpy_chk@plt>:
 10701f0:      	adrp	x16, 0x10ce000
 10701f4:      	ldr	x17, [x16, #0xfe8]
 10701f8:      	add	x16, x16, #0xfe8
 10701fc:      	br	x17

0000000001070200 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
 1070200:      	adrp	x16, 0x10ce000
 1070204:      	ldr	x17, [x16, #0xff0]
 1070208:      	add	x16, x16, #0xff0
 107020c:      	br	x17

0000000001070210 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl@plt>:
 1070210:      	adrp	x16, 0x10ce000
 1070214:      	ldr	x17, [x16, #0xff8]
 1070218:      	add	x16, x16, #0xff8
 107021c:      	br	x17

0000000001070220 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
 1070220:      	adrp	x16, 0x10cf000
 1070224:      	ldr	x17, [x16]
 1070228:      	add	x16, x16, #0x0
 107022c:      	br	x17

0000000001070230 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgENS_4fposI9mbstate_tEE@plt>:
 1070230:      	adrp	x16, 0x10cf000
 1070234:      	ldr	x17, [x16, #0x8]
 1070238:      	add	x16, x16, #0x8
 107023c:      	br	x17

0000000001070240 <_ZN5image11DetailImageIhEC2EPKhjjjjPFvPvmS4_ES4_@plt>:
 1070240:      	adrp	x16, 0x10cf000
 1070244:      	ldr	x17, [x16, #0x10]
 1070248:      	add	x16, x16, #0x10
 107024c:      	br	x17

0000000001070250 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
 1070250:      	adrp	x16, 0x10cf000
 1070254:      	ldr	x17, [x16, #0x18]
 1070258:      	add	x16, x16, #0x18
 107025c:      	br	x17

0000000001070260 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
 1070260:      	adrp	x16, 0x10cf000
 1070264:      	ldr	x17, [x16, #0x20]
 1070268:      	add	x16, x16, #0x20
 107026c:      	br	x17

0000000001070270 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
 1070270:      	adrp	x16, 0x10cf000
 1070274:      	ldr	x17, [x16, #0x28]
 1070278:      	add	x16, x16, #0x28
 107027c:      	br	x17

0000000001070280 <_ZN5image11DetailImageIhEC2Ejjjj@plt>:
 1070280:      	adrp	x16, 0x10cf000
 1070284:      	ldr	x17, [x16, #0x30]
 1070288:      	add	x16, x16, #0x30
 107028c:      	br	x17

0000000001070290 <_ZN5image11toGrayscaleIhEENS_11DetailImageIT_EERKS3_@plt>:
 1070290:      	adrp	x16, 0x10cf000
 1070294:      	ldr	x17, [x16, #0x38]
 1070298:      	add	x16, x16, #0x38
 107029c:      	br	x17

00000000010702a0 <_ZN5image7foreachIhEEvRNS_11DetailImageIT_EERKNSt6__ndk18functionIFvjjPS2_EEE@plt>:
 10702a0:      	adrp	x16, 0x10cf000
 10702a4:      	ldr	x17, [x16, #0x40]
 10702a8:      	add	x16, x16, #0x40
 10702ac:      	br	x17

00000000010702b0 <_ZN5image7foreachIhEEvRKNS_11DetailImageIT_EERKNSt6__ndk18functionIFvjjPKS2_EEE@plt>:
 10702b0:      	adrp	x16, 0x10cf000
 10702b4:      	ldr	x17, [x16, #0x48]
 10702b8:      	add	x16, x16, #0x48
 10702bc:      	br	x17

00000000010702c0 <_ZN8mtlabar311PartControl13getCustomNameEv@plt>:
 10702c0:      	adrp	x16, 0x10cf000
 10702c4:      	ldr	x17, [x16, #0x50]
 10702c8:      	add	x16, x16, #0x50
 10702cc:      	br	x17

00000000010702d0 <_ZNK8mtlabar311PartControl26getCustomParamValueWithKeyEPKc@plt>:
 10702d0:      	adrp	x16, 0x10cf000
 10702d4:      	ldr	x17, [x16, #0x58]
 10702d8:      	add	x16, x16, #0x58
 10702dc:      	br	x17

00000000010702e0 <_ZN8mtlabar311PartControl17getStickerControlEv@plt>:
 10702e0:      	adrp	x16, 0x10cf000
 10702e4:      	ldr	x17, [x16, #0x60]
 10702e8:      	add	x16, x16, #0x60
 10702ec:      	br	x17

00000000010702f0 <_ZNK8mtlabar314StickerControl20getStickerAlphaValueEv@plt>:
 10702f0:      	adrp	x16, 0x10cf000
 10702f4:      	ldr	x17, [x16, #0x68]
 10702f8:      	add	x16, x16, #0x68
 10702fc:      	br	x17

0000000001070300 <_ZNK8mtlabar314StickerControl13getStickerFPSEv@plt>:
 1070300:      	adrp	x16, 0x10cf000
 1070304:      	ldr	x17, [x16, #0x70]
 1070308:      	add	x16, x16, #0x70
 107030c:      	br	x17

0000000001070310 <_ZNK8mtlabar314StickerControl14getStickerSizeEv@plt>:
 1070310:      	adrp	x16, 0x10cf000
 1070314:      	ldr	x17, [x16, #0x78]
 1070318:      	add	x16, x16, #0x78
 107031c:      	br	x17

0000000001070320 <_ZNK8mtlabar314StickerControl24getStickerVerticalOffsetEv@plt>:
 1070320:      	adrp	x16, 0x10cf000
 1070324:      	ldr	x17, [x16, #0x80]
 1070328:      	add	x16, x16, #0x80
 107032c:      	br	x17

0000000001070330 <_ZNK8mtlabar314StickerControl26getStickerHorizontalOffsetEv@plt>:
 1070330:      	adrp	x16, 0x10cf000
 1070334:      	ldr	x17, [x16, #0x88]
 1070338:      	add	x16, x16, #0x88
 107033c:      	br	x17

0000000001070340 <_ZN8mtlabar311PartControl17getParamTableDictEv@plt>:
 1070340:      	adrp	x16, 0x10cf000
 1070344:      	ldr	x17, [x16, #0x90]
 1070348:      	add	x16, x16, #0x90
 107034c:      	br	x17

0000000001070350 <_ZN8mtlabar314ParamTableDict8getTableENS_14ParamTableEnumE@plt>:
 1070350:      	adrp	x16, 0x10cf000
 1070354:      	ldr	x17, [x16, #0x98]
 1070358:      	add	x16, x16, #0x98
 107035c:      	br	x17

0000000001070360 <_ZN8mtlabar310ParamTable13getParamByKeyENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
 1070360:      	adrp	x16, 0x10cf000
 1070364:      	ldr	x17, [x16, #0xa0]
 1070368:      	add	x16, x16, #0xa0
 107036c:      	br	x17

0000000001070370 <_ZN8mtlabar314StickerControl20setStickerAlphaValueEf@plt>:
 1070370:      	adrp	x16, 0x10cf000
 1070374:      	ldr	x17, [x16, #0xa8]
 1070378:      	add	x16, x16, #0xa8
 107037c:      	br	x17

0000000001070380 <_ZN8mtlabar314StickerControl13setStickerFPSEj@plt>:
 1070380:      	adrp	x16, 0x10cf000
 1070384:      	ldr	x17, [x16, #0xb0]
 1070388:      	add	x16, x16, #0xb0
 107038c:      	br	x17

0000000001070390 <_ZN8mtlabar314StickerControl14setStickerSizeEf@plt>:
 1070390:      	adrp	x16, 0x10cf000
 1070394:      	ldr	x17, [x16, #0xb8]
 1070398:      	add	x16, x16, #0xb8
 107039c:      	br	x17

00000000010703a0 <_ZN8mtlabar314StickerControl24setStickerVerticalOffsetEf@plt>:
 10703a0:      	adrp	x16, 0x10cf000
 10703a4:      	ldr	x17, [x16, #0xc0]
 10703a8:      	add	x16, x16, #0xc0
 10703ac:      	br	x17

00000000010703b0 <_ZN8mtlabar314StickerControl26setStickerHorizontalOffsetEf@plt>:
 10703b0:      	adrp	x16, 0x10cf000
 10703b4:      	ldr	x17, [x16, #0xc8]
 10703b8:      	add	x16, x16, #0xc8
 10703bc:      	br	x17

00000000010703c0 <_ZN8mtlabar311PartControl11getPartTypeEv@plt>:
 10703c0:      	adrp	x16, 0x10cf000
 10703c4:      	ldr	x17, [x16, #0xd0]
 10703c8:      	add	x16, x16, #0xd0
 10703cc:      	br	x17

00000000010703d0 <_ZN8mtlabar311PartControl5resetEv@plt>:
 10703d0:      	adrp	x16, 0x10cf000
 10703d4:      	ldr	x17, [x16, #0xd8]
 10703d8:      	add	x16, x16, #0xd8
 10703dc:      	br	x17

00000000010703e0 <_ZNK8mtlabar311PartControl7isApplyEv@plt>:
 10703e0:      	adrp	x16, 0x10cf000
 10703e4:      	ldr	x17, [x16, #0xe0]
 10703e8:      	add	x16, x16, #0xe0
 10703ec:      	br	x17

00000000010703f0 <_ZN8mtlabar311PartControl8setApplyEb@plt>:
 10703f0:      	adrp	x16, 0x10cf000
 10703f4:      	ldr	x17, [x16, #0xe8]
 10703f8:      	add	x16, x16, #0xe8
 10703fc:      	br	x17

0000000001070400 <_ZN8mtlabar311PartControl15getHumanControlEv@plt>:
 1070400:      	adrp	x16, 0x10cf000
 1070404:      	ldr	x17, [x16, #0xf0]
 1070408:      	add	x16, x16, #0xf0
 107040c:      	br	x17

0000000001070410 <_ZN8mtlabar312HumanControl13getGenderTypeEv@plt>:
 1070410:      	adrp	x16, 0x10cf000
 1070414:      	ldr	x17, [x16, #0xf8]
 1070418:      	add	x16, x16, #0xf8
 107041c:      	br	x17

0000000001070420 <_ZN8mtlabar312HumanControl13setGenderTypeENS_14FaceGenderTypeE@plt>:
 1070420:      	adrp	x16, 0x10cf000
 1070424:      	ldr	x17, [x16, #0x100]
 1070428:      	add	x16, x16, #0x100
 107042c:      	br	x17

0000000001070430 <_ZN8mtlabar311PartControl21getPartControlVisibleEv@plt>:
 1070430:      	adrp	x16, 0x10cf000
 1070434:      	ldr	x17, [x16, #0x108]
 1070438:      	add	x16, x16, #0x108
 107043c:      	br	x17

0000000001070440 <_ZN8mtlabar311PartControl21setPartControlVisibleEb@plt>:
 1070440:      	adrp	x16, 0x10cf000
 1070444:      	ldr	x17, [x16, #0x110]
 1070448:      	add	x16, x16, #0x110
 107044c:      	br	x17

0000000001070450 <_ZN8mtlabar312HumanControl10setFaceIDsERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE@plt>:
 1070450:      	adrp	x16, 0x10cf000
 1070454:      	ldr	x17, [x16, #0x118]
 1070458:      	add	x16, x16, #0x118
 107045c:      	br	x17

0000000001070460 <_ZN8mtlabar312HumanControl10getFaceIDsEv@plt>:
 1070460:      	adrp	x16, 0x10cf000
 1070464:      	ldr	x17, [x16, #0x120]
 1070468:      	add	x16, x16, #0x120
 107046c:      	br	x17

0000000001070470 <_ZN8mtlabar311PartControl20getMakeupControlSizeEv@plt>:
 1070470:      	adrp	x16, 0x10cf000
 1070474:      	ldr	x17, [x16, #0x128]
 1070478:      	add	x16, x16, #0x128
 107047c:      	br	x17

0000000001070480 <_ZN8mtlabar311PartControl18getMakeupControlAtEm@plt>:
 1070480:      	adrp	x16, 0x10cf000
 1070484:      	ldr	x17, [x16, #0x130]
 1070488:      	add	x16, x16, #0x130
 107048c:      	br	x17

0000000001070490 <_ZN8mtlabar313MakeupControl24getMakeupControlInstanceEi@plt>:
 1070490:      	adrp	x16, 0x10cf000
 1070494:      	ldr	x17, [x16, #0x138]
 1070498:      	add	x16, x16, #0x138
 107049c:      	br	x17

00000000010704a0 <_ZN8mtlabar321MakeupControlInstance12setPartAlphaEf@plt>:
 10704a0:      	adrp	x16, 0x10cf000
 10704a4:      	ldr	x17, [x16, #0x140]
 10704a8:      	add	x16, x16, #0x140
 10704ac:      	br	x17

00000000010704b0 <_ZN8mtlabar321MakeupControlInstance12getPartAlphaEv@plt>:
 10704b0:      	adrp	x16, 0x10cf000
 10704b4:      	ldr	x17, [x16, #0x148]
 10704b8:      	add	x16, x16, #0x148
 10704bc:      	br	x17

00000000010704c0 <_ZN8mtlabar311PartControl14getDataRequireEv@plt>:
 10704c0:      	adrp	x16, 0x10cf000
 10704c4:      	ldr	x17, [x16, #0x150]
 10704c8:      	add	x16, x16, #0x150
 10704cc:      	br	x17

00000000010704d0 <_ZN8mtlabar310EffectData8setApplyEb@plt>:
 10704d0:      	adrp	x16, 0x10cf000
 10704d4:      	ldr	x17, [x16, #0x158]
 10704d8:      	add	x16, x16, #0x158
 10704dc:      	br	x17

00000000010704e0 <sched_yield@plt>:
 10704e0:      	adrp	x16, 0x10cf000
 10704e4:      	ldr	x17, [x16, #0x160]
 10704e8:      	add	x16, x16, #0x160
 10704ec:      	br	x17

00000000010704f0 <__cxa_guard_abort@plt>:
 10704f0:      	adrp	x16, 0x10cf000
 10704f4:      	ldr	x17, [x16, #0x168]
 10704f8:      	add	x16, x16, #0x168
 10704fc:      	br	x17

0000000001070500 <_ZN8mtlabar310ParamTable13getParamCountEv@plt>:
 1070500:      	adrp	x16, 0x10cf000
 1070504:      	ldr	x17, [x16, #0x170]
 1070508:      	add	x16, x16, #0x170
 107050c:      	br	x17

0000000001070510 <_ZN8mtlabar310ParamTable8getParamEi@plt>:
 1070510:      	adrp	x16, 0x10cf000
 1070514:      	ldr	x17, [x16, #0x178]
 1070518:      	add	x16, x16, #0x178
 107051c:      	br	x17

0000000001070520 <_ZNK8mtlabar39ParamBase12getParamTypeEv@plt>:
 1070520:      	adrp	x16, 0x10cf000
 1070524:      	ldr	x17, [x16, #0x180]
 1070528:      	add	x16, x16, #0x180
 107052c:      	br	x17

0000000001070530 <_ZN8mtlabar310ParamTable14getParamSwitchEi@plt>:
 1070530:      	adrp	x16, 0x10cf000
 1070534:      	ldr	x17, [x16, #0x188]
 1070538:      	add	x16, x16, #0x188
 107053c:      	br	x17

0000000001070540 <_ZNK8mtlabar39ParamBase6getKeyEv@plt>:
 1070540:      	adrp	x16, 0x10cf000
 1070544:      	ldr	x17, [x16, #0x190]
 1070548:      	add	x16, x16, #0x190
 107054c:      	br	x17

0000000001070550 <_ZNK8mtlabar39ParamBase12getParamFlagEv@plt>:
 1070550:      	adrp	x16, 0x10cf000
 1070554:      	ldr	x17, [x16, #0x198]
 1070558:      	add	x16, x16, #0x198
 107055c:      	br	x17

0000000001070560 <_ZNK8mtlabar311ParamSwitch15getCurrentValueEv@plt>:
 1070560:      	adrp	x16, 0x10cf000
 1070564:      	ldr	x17, [x16, #0x1a0]
 1070568:      	add	x16, x16, #0x1a0
 107056c:      	br	x17

0000000001070570 <_ZN8mtlabar310ParamTable19getParamSliderGroupEi@plt>:
 1070570:      	adrp	x16, 0x10cf000
 1070574:      	ldr	x17, [x16, #0x1a8]
 1070578:      	add	x16, x16, #0x1a8
 107057c:      	br	x17

0000000001070580 <_ZNK8mtlabar316ParamSliderGroup12getGroupSizeEv@plt>:
 1070580:      	adrp	x16, 0x10cf000
 1070584:      	ldr	x17, [x16, #0x1b0]
 1070588:      	add	x16, x16, #0x1b0
 107058c:      	br	x17

0000000001070590 <_ZNK8mtlabar316ParamSliderGroup22getCurrentValueByIndexEi@plt>:
 1070590:      	adrp	x16, 0x10cf000
 1070594:      	ldr	x17, [x16, #0x1b8]
 1070598:      	add	x16, x16, #0x1b8
 107059c:      	br	x17

00000000010705a0 <_ZN8mtlabar310ParamTable14getParamSliderEi@plt>:
 10705a0:      	adrp	x16, 0x10cf000
 10705a4:      	ldr	x17, [x16, #0x1c0]
 10705a8:      	add	x16, x16, #0x1c0
 10705ac:      	br	x17

00000000010705b0 <_ZNK8mtlabar311ParamSlider15getCurrentValueEv@plt>:
 10705b0:      	adrp	x16, 0x10cf000
 10705b4:      	ldr	x17, [x16, #0x1c8]
 10705b8:      	add	x16, x16, #0x1c8
 10705bc:      	br	x17

00000000010705c0 <_ZN8mtlabar310ParamTable14getParamStringEi@plt>:
 10705c0:      	adrp	x16, 0x10cf000
 10705c4:      	ldr	x17, [x16, #0x1d0]
 10705c8:      	add	x16, x16, #0x1d0
 10705cc:      	br	x17

00000000010705d0 <_ZNK8mtlabar311ParamString15getCurrentValueEv@plt>:
 10705d0:      	adrp	x16, 0x10cf000
 10705d4:      	ldr	x17, [x16, #0x1d8]
 10705d8:      	add	x16, x16, #0x1d8
 10705dc:      	br	x17

00000000010705e0 <_ZN8mtlabar310ParamTable13getParamColorEi@plt>:
 10705e0:      	adrp	x16, 0x10cf000
 10705e4:      	ldr	x17, [x16, #0x1e0]
 10705e8:      	add	x16, x16, #0x1e0
 10705ec:      	br	x17

00000000010705f0 <_ZN8mtlabar310ParamColor8getColorENS_18ParamColorTypeEnumE@plt>:
 10705f0:      	adrp	x16, 0x10cf000
 10705f4:      	ldr	x17, [x16, #0x1e8]
 10705f8:      	add	x16, x16, #0x1e8
 10705fc:      	br	x17

0000000001070600 <_ZN8mtlabar310ParamColor15getCurrentAlphaEv@plt>:
 1070600:      	adrp	x16, 0x10cf000
 1070604:      	ldr	x17, [x16, #0x1f0]
 1070608:      	add	x16, x16, #0x1f0
 107060c:      	br	x17

0000000001070610 <_ZN8mtlabar310ParamColor17getCurrentOpacityEv@plt>:
 1070610:      	adrp	x16, 0x10cf000
 1070614:      	ldr	x17, [x16, #0x1f8]
 1070618:      	add	x16, x16, #0x1f8
 107061c:      	br	x17

0000000001070620 <_ZN8mtlabar310ParamTable16getParamPositionEi@plt>:
 1070620:      	adrp	x16, 0x10cf000
 1070624:      	ldr	x17, [x16, #0x200]
 1070628:      	add	x16, x16, #0x200
 107062c:      	br	x17

0000000001070630 <_ZNK8mtlabar313ParamPosition11getCurrentXEv@plt>:
 1070630:      	adrp	x16, 0x10cf000
 1070634:      	ldr	x17, [x16, #0x208]
 1070638:      	add	x16, x16, #0x208
 107063c:      	br	x17

0000000001070640 <_ZNK8mtlabar313ParamPosition11getCurrentYEv@plt>:
 1070640:      	adrp	x16, 0x10cf000
 1070644:      	ldr	x17, [x16, #0x210]
 1070648:      	add	x16, x16, #0x210
 107064c:      	br	x17

0000000001070650 <_ZNK8mtlabar313ParamPosition11getCurrentZEv@plt>:
 1070650:      	adrp	x16, 0x10cf000
 1070654:      	ldr	x17, [x16, #0x218]
 1070658:      	add	x16, x16, #0x218
 107065c:      	br	x17

0000000001070660 <_ZNK8mtlabar313ParamPosition11getCurrentWEv@plt>:
 1070660:      	adrp	x16, 0x10cf000
 1070664:      	ldr	x17, [x16, #0x220]
 1070668:      	add	x16, x16, #0x220
 107066c:      	br	x17

0000000001070670 <__vsnprintf_chk@plt>:
 1070670:      	adrp	x16, 0x10cf000
 1070674:      	ldr	x17, [x16, #0x228]
 1070678:      	add	x16, x16, #0x228
 107067c:      	br	x17

0000000001070680 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
 1070680:      	adrp	x16, 0x10cf000
 1070684:      	ldr	x17, [x16, #0x230]
 1070688:      	add	x16, x16, #0x230
 107068c:      	br	x17

0000000001070690 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf@plt>:
 1070690:      	adrp	x16, 0x10cf000
 1070694:      	ldr	x17, [x16, #0x238]
 1070698:      	add	x16, x16, #0x238
 107069c:      	br	x17

00000000010706a0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
 10706a0:      	adrp	x16, 0x10cf000
 10706a4:      	ldr	x17, [x16, #0x240]
 10706a8:      	add	x16, x16, #0x240
 10706ac:      	br	x17

00000000010706b0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
 10706b0:      	adrp	x16, 0x10cf000
 10706b4:      	ldr	x17, [x16, #0x248]
 10706b8:      	add	x16, x16, #0x248
 10706bc:      	br	x17

00000000010706c0 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
 10706c0:      	adrp	x16, 0x10cf000
 10706c4:      	ldr	x17, [x16, #0x250]
 10706c8:      	add	x16, x16, #0x250
 10706cc:      	br	x17

00000000010706d0 <_ZNK8mtlabar318FrameDataInterface15getDataProtocolEv@plt>:
 10706d0:      	adrp	x16, 0x10cf000
 10706d4:      	ldr	x17, [x16, #0x258]
 10706d8:      	add	x16, x16, #0x258
 10706dc:      	br	x17

00000000010706e0 <_ZN8mtlabar318FrameDataInterface27getMainTextureDataInterfaceEv@plt>:
 10706e0:      	adrp	x16, 0x10cf000
 10706e4:      	ldr	x17, [x16, #0x260]
 10706e8:      	add	x16, x16, #0x260
 10706ec:      	br	x17

00000000010706f0 <_ZNK8mtlabar324MainTextureDataInterface15getTextureWidthEv@plt>:
 10706f0:      	adrp	x16, 0x10cf000
 10706f4:      	ldr	x17, [x16, #0x268]
 10706f8:      	add	x16, x16, #0x268
 10706fc:      	br	x17

0000000001070700 <_ZNK8mtlabar324MainTextureDataInterface16getTextureHeightEv@plt>:
 1070700:      	adrp	x16, 0x10cf000
 1070704:      	ldr	x17, [x16, #0x270]
 1070708:      	add	x16, x16, #0x270
 107070c:      	br	x17

0000000001070710 <vldp_get_data_protocol_body_result@plt>:
 1070710:      	adrp	x16, 0x10cf000
 1070714:      	ldr	x17, [x16, #0x278]
 1070718:      	add	x16, x16, #0x278
 107071c:      	br	x17

0000000001070720 <vldp_get_data_protocol_body_in_one_result@plt>:
 1070720:      	adrp	x16, 0x10cf000
 1070724:      	ldr	x17, [x16, #0x280]
 1070728:      	add	x16, x16, #0x280
 107072c:      	br	x17

0000000001070730 <vldp_get_body_result_pointer_ref@plt>:
 1070730:      	adrp	x16, 0x10cf000
 1070734:      	ldr	x17, [x16, #0x288]
 1070738:      	add	x16, x16, #0x288
 107073c:      	br	x17

0000000001070740 <vldp_get_body_in_one_result_pointer_ref@plt>:
 1070740:      	adrp	x16, 0x10cf000
 1070744:      	ldr	x17, [x16, #0x290]
 1070748:      	add	x16, x16, #0x290
 107074c:      	br	x17

0000000001070750 <_ZNK8mtlabar332AutomaticBodySlimControlInstance12getValueByIdEl@plt>:
 1070750:      	adrp	x16, 0x10cf000
 1070754:      	ldr	x17, [x16, #0x298]
 1070758:      	add	x16, x16, #0x298
 107075c:      	br	x17

0000000001070760 <_ZNK8mtlabar332AutomaticBodySlimControlInstance11getMinValueEv@plt>:
 1070760:      	adrp	x16, 0x10cf000
 1070764:      	ldr	x17, [x16, #0x2a0]
 1070768:      	add	x16, x16, #0x2a0
 107076c:      	br	x17

0000000001070770 <_ZNK8mtlabar332AutomaticBodySlimControlInstance11getMaxValueEv@plt>:
 1070770:      	adrp	x16, 0x10cf000
 1070774:      	ldr	x17, [x16, #0x2a8]
 1070778:      	add	x16, x16, #0x2a8
 107077c:      	br	x17

0000000001070780 <_ZN8mtlabar329ManualBodySlimControlInstance12getParamTypeEv@plt>:
 1070780:      	adrp	x16, 0x10cf000
 1070784:      	ldr	x17, [x16, #0x2b0]
 1070788:      	add	x16, x16, #0x2b0
 107078c:      	br	x17

0000000001070790 <_ZN8mtlabar323BodySlimControlInstance20getEffectIsEffectiveEv@plt>:
 1070790:      	adrp	x16, 0x10cf000
 1070794:      	ldr	x17, [x16, #0x2b8]
 1070798:      	add	x16, x16, #0x2b8
 107079c:      	br	x17

00000000010707a0 <_ZN8mtlabar323BodySlimControlInstance32getManualBodySlimControlInstanceEv@plt>:
 10707a0:      	adrp	x16, 0x10cf000
 10707a4:      	ldr	x17, [x16, #0x2c0]
 10707a8:      	add	x16, x16, #0x2c0
 10707ac:      	br	x17

00000000010707b0 <_ZN8mtlabar323BodySlimControlInstance35getAutomaticBodySlimControlInstanceEv@plt>:
 10707b0:      	adrp	x16, 0x10cf000
 10707b4:      	ldr	x17, [x16, #0x2c8]
 10707b8:      	add	x16, x16, #0x2c8
 10707bc:      	br	x17

00000000010707c0 <vldp_get_data_protocol_frame_data@plt>:
 10707c0:      	adrp	x16, 0x10cf000
 10707c4:      	ldr	x17, [x16, #0x2d0]
 10707c8:      	add	x16, x16, #0x2d0
 10707cc:      	br	x17

00000000010707d0 <vldp_get_frame_data_pointer_ref@plt>:
 10707d0:      	adrp	x16, 0x10cf000
 10707d4:      	ldr	x17, [x16, #0x2d8]
 10707d8:      	add	x16, x16, #0x2d8
 10707dc:      	br	x17

00000000010707e0 <vldp_get_frame_data_has_frame_size@plt>:
 10707e0:      	adrp	x16, 0x10cf000
 10707e4:      	ldr	x17, [x16, #0x2e0]
 10707e8:      	add	x16, x16, #0x2e0
 10707ec:      	br	x17

00000000010707f0 <vldp_get_frame_data_frame_size@plt>:
 10707f0:      	adrp	x16, 0x10cf000
 10707f4:      	ldr	x17, [x16, #0x2e8]
 10707f8:      	add	x16, x16, #0x2e8
 10707fc:      	br	x17

0000000001070800 <vldp_get_data_protocol_multi_body_in_one_result@plt>:
 1070800:      	adrp	x16, 0x10cf000
 1070804:      	ldr	x17, [x16, #0x2f0]
 1070808:      	add	x16, x16, #0x2f0
 107080c:      	br	x17

0000000001070810 <vldp_get_data_protocol_face_result@plt>:
 1070810:      	adrp	x16, 0x10cf000
 1070814:      	ldr	x17, [x16, #0x2f8]
 1070818:      	add	x16, x16, #0x2f8
 107081c:      	br	x17

0000000001070820 <vldp_get_face_result_pointer_ref@plt>:
 1070820:      	adrp	x16, 0x10cf000
 1070824:      	ldr	x17, [x16, #0x300]
 1070828:      	add	x16, x16, #0x300
 107082c:      	br	x17

0000000001070830 <_ZNSt6__ndk111this_thread9sleep_forERKNS_6chrono8durationIxNS_5ratioILl1ELl1000000000EEEEE@plt>:
 1070830:      	adrp	x16, 0x10cf000
 1070834:      	ldr	x17, [x16, #0x308]
 1070838:      	add	x16, x16, #0x308
 107083c:      	br	x17

0000000001070840 <_ZN8mtlabar310EffectData6hasBGMEv@plt>:
 1070840:      	adrp	x16, 0x10cf000
 1070844:      	ldr	x17, [x16, #0x310]
 1070848:      	add	x16, x16, #0x310
 107084c:      	br	x17

0000000001070850 <_ZN8mtlabar310EffectData7playBGMEv@plt>:
 1070850:      	adrp	x16, 0x10cf000
 1070854:      	ldr	x17, [x16, #0x318]
 1070858:      	add	x16, x16, #0x318
 107085c:      	br	x17

0000000001070860 <_ZNK8mtlabar314FaceliftSlider17getControlKeyNameEv@plt>:
 1070860:      	adrp	x16, 0x10cf000
 1070864:      	ldr	x17, [x16, #0x320]
 1070868:      	add	x16, x16, #0x320
 107086c:      	br	x17

0000000001070870 <_ZNK8mtlabar314FaceliftSlider15getDefaultValueEv@plt>:
 1070870:      	adrp	x16, 0x10cf000
 1070874:      	ldr	x17, [x16, #0x328]
 1070878:      	add	x16, x16, #0x328
 107087c:      	br	x17

0000000001070880 <_ZNK8mtlabar314FaceliftSlider8getValueEv@plt>:
 1070880:      	adrp	x16, 0x10cf000
 1070884:      	ldr	x17, [x16, #0x330]
 1070888:      	add	x16, x16, #0x330
 107088c:      	br	x17

0000000001070890 <_ZNK8mtlabar314FaceliftSlider27getNeutralizeTheEffectValueEv@plt>:
 1070890:      	adrp	x16, 0x10cf000
 1070894:      	ldr	x17, [x16, #0x338]
 1070898:      	add	x16, x16, #0x338
 107089c:      	br	x17

00000000010708a0 <_ZNK8mtlabar323FaceliftControlInstance23getFaceliftControlCountEv@plt>:
 10708a0:      	adrp	x16, 0x10cf000
 10708a4:      	ldr	x17, [x16, #0x340]
 10708a8:      	add	x16, x16, #0x340
 10708ac:      	br	x17

00000000010708b0 <_ZnwmRKSt9nothrow_t@plt>:
 10708b0:      	adrp	x16, 0x10cf000
 10708b4:      	ldr	x17, [x16, #0x348]
 10708b8:      	add	x16, x16, #0x348
 10708bc:      	br	x17

00000000010708c0 <_ZN8mtlabar310BrushCacheC2Ev@plt>:
 10708c0:      	adrp	x16, 0x10cf000
 10708c4:      	ldr	x17, [x16, #0x350]
 10708c8:      	add	x16, x16, #0x350
 10708cc:      	br	x17

00000000010708d0 <_ZN8mtlabar310BrushCacheD2Ev@plt>:
 10708d0:      	adrp	x16, 0x10cf000
 10708d4:      	ldr	x17, [x16, #0x358]
 10708d8:      	add	x16, x16, #0x358
 10708dc:      	br	x17

00000000010708e0 <_ZN8mtlabar313GlobalSetting14getRuntimeTypeEv@plt>:
 10708e0:      	adrp	x16, 0x10cf000
 10708e4:      	ldr	x17, [x16, #0x360]
 10708e8:      	add	x16, x16, #0x360
 10708ec:      	br	x17

00000000010708f0 <vldp_get_face_result_faces@plt>:
 10708f0:      	adrp	x16, 0x10cf000
 10708f4:      	ldr	x17, [x16, #0x368]
 10708f8:      	add	x16, x16, #0x368
 10708fc:      	br	x17

0000000001070900 <vldp_get_face_array_pointer_size@plt>:
 1070900:      	adrp	x16, 0x10cf000
 1070904:      	ldr	x17, [x16, #0x370]
 1070908:      	add	x16, x16, #0x370
 107090c:      	br	x17

0000000001070910 <pthread_self@plt>:
 1070910:      	adrp	x16, 0x10cf000
 1070914:      	ldr	x17, [x16, #0x378]
 1070918:      	add	x16, x16, #0x378
 107091c:      	br	x17

0000000001070920 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc@plt>:
 1070920:      	adrp	x16, 0x10cf000
 1070924:      	ldr	x17, [x16, #0x380]
 1070928:      	add	x16, x16, #0x380
 107092c:      	br	x17

0000000001070930 <_ZNSt6__ndk16locale7classicEv@plt>:
 1070930:      	adrp	x16, 0x10cf000
 1070934:      	ldr	x17, [x16, #0x388]
 1070938:      	add	x16, x16, #0x388
 107093c:      	br	x17

0000000001070940 <_ZNSt6__ndk18ios_base5imbueERKNS_6localeE@plt>:
 1070940:      	adrp	x16, 0x10cf000
 1070944:      	ldr	x17, [x16, #0x390]
 1070948:      	add	x16, x16, #0x390
 107094c:      	br	x17

0000000001070950 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
 1070950:      	adrp	x16, 0x10cf000
 1070954:      	ldr	x17, [x16, #0x398]
 1070958:      	add	x16, x16, #0x398
 107095c:      	br	x17

0000000001070960 <_ZNSt6__ndk16localeaSERKS0_@plt>:
 1070960:      	adrp	x16, 0x10cf000
 1070964:      	ldr	x17, [x16, #0x3a0]
 1070968:      	add	x16, x16, #0x3a0
 107096c:      	br	x17

0000000001070970 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
 1070970:      	adrp	x16, 0x10cf000
 1070974:      	ldr	x17, [x16, #0x3a8]
 1070978:      	add	x16, x16, #0x3a8
 107097c:      	br	x17

0000000001070980 <wgpuTextureGetOpenGLHandle_MEITU@plt>:
 1070980:      	adrp	x16, 0x10cf000
 1070984:      	ldr	x17, [x16, #0x3b0]
 1070988:      	add	x16, x16, #0x3b0
 107098c:      	br	x17

0000000001070990 <wgpuTextureGetMetalHandle_MEITU@plt>:
 1070990:      	adrp	x16, 0x10cf000
 1070994:      	ldr	x17, [x16, #0x3b8]
 1070998:      	add	x16, x16, #0x3b8
 107099c:      	br	x17

00000000010709a0 <wgpuTextureGetD3D11Handle_MEITU@plt>:
 10709a0:      	adrp	x16, 0x10cf000
 10709a4:      	ldr	x17, [x16, #0x3c0]
 10709a8:      	add	x16, x16, #0x3c0
 10709ac:      	br	x17

00000000010709b0 <wgpuDeviceDestroy@plt>:
 10709b0:      	adrp	x16, 0x10cf000
 10709b4:      	ldr	x17, [x16, #0x3c8]
 10709b8:      	add	x16, x16, #0x3c8
 10709bc:      	br	x17

00000000010709c0 <wgpuDeviceRelease@plt>:
 10709c0:      	adrp	x16, 0x10cf000
 10709c4:      	ldr	x17, [x16, #0x3d0]
 10709c8:      	add	x16, x16, #0x3d0
 10709cc:      	br	x17

00000000010709d0 <wgpuAdapterRelease@plt>:
 10709d0:      	adrp	x16, 0x10cf000
 10709d4:      	ldr	x17, [x16, #0x3d8]
 10709d8:      	add	x16, x16, #0x3d8
 10709dc:      	br	x17

00000000010709e0 <wgpuAdapterHasFeature@plt>:
 10709e0:      	adrp	x16, 0x10cf000
 10709e4:      	ldr	x17, [x16, #0x3e0]
 10709e8:      	add	x16, x16, #0x3e0
 10709ec:      	br	x17

00000000010709f0 <wgpuCreateInstance@plt>:
 10709f0:      	adrp	x16, 0x10cf000
 10709f4:      	ldr	x17, [x16, #0x3e8]
 10709f8:      	add	x16, x16, #0x3e8
 10709fc:      	br	x17

0000000001070a00 <wgpuInstanceRequestAdapter@plt>:
 1070a00:      	adrp	x16, 0x10cf000
 1070a04:      	ldr	x17, [x16, #0x3f0]
 1070a08:      	add	x16, x16, #0x3f0
 1070a0c:      	br	x17

0000000001070a10 <wgpuAdapterRequestDevice@plt>:
 1070a10:      	adrp	x16, 0x10cf000
 1070a14:      	ldr	x17, [x16, #0x3f8]
 1070a18:      	add	x16, x16, #0x3f8
 1070a1c:      	br	x17

0000000001070a20 <wgpuAdapterGetProperties@plt>:
 1070a20:      	adrp	x16, 0x10cf000
 1070a24:      	ldr	x17, [x16, #0x400]
 1070a28:      	add	x16, x16, #0x400
 1070a2c:      	br	x17

0000000001070a30 <wgpuDeviceSetUncapturedErrorCallback@plt>:
 1070a30:      	adrp	x16, 0x10cf000
 1070a34:      	ldr	x17, [x16, #0x408]
 1070a38:      	add	x16, x16, #0x408
 1070a3c:      	br	x17

0000000001070a40 <wgpuQueueOnSubmittedWorkDone@plt>:
 1070a40:      	adrp	x16, 0x10cf000
 1070a44:      	ldr	x17, [x16, #0x410]
 1070a48:      	add	x16, x16, #0x410
 1070a4c:      	br	x17

0000000001070a50 <_ZN8mtlabar317FaceDataInterface13setDetectSizeERKNS_5SizeFE@plt>:
 1070a50:      	adrp	x16, 0x10cf000
 1070a54:      	ldr	x17, [x16, #0x418]
 1070a58:      	add	x16, x16, #0x418
 1070a5c:      	br	x17

0000000001070a60 <_ZN8mtlabar38FaceData9setFaceIDEi@plt>:
 1070a60:      	adrp	x16, 0x10cf000
 1070a64:      	ldr	x17, [x16, #0x420]
 1070a68:      	add	x16, x16, #0x420
 1070a6c:      	br	x17

0000000001070a70 <_ZN8mtlabar38FaceData11setFaceRectERKNS_6Rect2FE@plt>:
 1070a70:      	adrp	x16, 0x10cf000
 1070a74:      	ldr	x17, [x16, #0x428]
 1070a78:      	add	x16, x16, #0x428
 1070a7c:      	br	x17

0000000001070a80 <_ZN8mtlabar38FaceData19setFacialLandmark2DEPKNS_6Float2Ei@plt>:
 1070a80:      	adrp	x16, 0x10cf000
 1070a84:      	ldr	x17, [x16, #0x430]
 1070a88:      	add	x16, x16, #0x430
 1070a8c:      	br	x17

0000000001070a90 <_ZN8mtlabar38FaceData26setFacialLandmark2DVisibleEPKfi@plt>:
 1070a90:      	adrp	x16, 0x10cf000
 1070a94:      	ldr	x17, [x16, #0x438]
 1070a98:      	add	x16, x16, #0x438
 1070a9c:      	br	x17

0000000001070aa0 <_ZN8mtlabar38FaceData19setFacialInterPointEPKNS_6Float2Ei@plt>:
 1070aa0:      	adrp	x16, 0x10cf000
 1070aa4:      	ldr	x17, [x16, #0x440]
 1070aa8:      	add	x16, x16, #0x440
 1070aac:      	br	x17

0000000001070ab0 <_ZN8mtlabar38FaceData27setFacialInterPointNewModelEPKNS_6Float2Ei@plt>:
 1070ab0:      	adrp	x16, 0x10cf000
 1070ab4:      	ldr	x17, [x16, #0x448]
 1070ab8:      	add	x16, x16, #0x448
 1070abc:      	br	x17

0000000001070ac0 <_ZNK8mtlabar317FaceDataInterface13getDetectSizeEv@plt>:
 1070ac0:      	adrp	x16, 0x10cf000
 1070ac4:      	ldr	x17, [x16, #0x450]
 1070ac8:      	add	x16, x16, #0x450
 1070acc:      	br	x17

0000000001070ad0 <_ZNK8mtlabar317FaceDataInterface12getFaceCountEv@plt>:
 1070ad0:      	adrp	x16, 0x10cf000
 1070ad4:      	ldr	x17, [x16, #0x458]
 1070ad8:      	add	x16, x16, #0x458
 1070adc:      	br	x17

0000000001070ae0 <_ZN8mtlabar317FaceDataInterface16getFaceDataArrayEv@plt>:
 1070ae0:      	adrp	x16, 0x10cf000
 1070ae4:      	ldr	x17, [x16, #0x460]
 1070ae8:      	add	x16, x16, #0x460
 1070aec:      	br	x17

0000000001070af0 <_ZNK8mtlabar38FaceData24getFacialLandmark2DCountEv@plt>:
 1070af0:      	adrp	x16, 0x10cf000
 1070af4:      	ldr	x17, [x16, #0x468]
 1070af8:      	add	x16, x16, #0x468
 1070afc:      	br	x17

0000000001070b00 <_ZNK8mtlabar38FaceData19getFacialLandmark2DEv@plt>:
 1070b00:      	adrp	x16, 0x10cf000
 1070b04:      	ldr	x17, [x16, #0x470]
 1070b08:      	add	x16, x16, #0x470
 1070b0c:      	br	x17

0000000001070b10 <_ZNK8mtlabar38FaceData17getHeadPointCountEv@plt>:
 1070b10:      	adrp	x16, 0x10cf000
 1070b14:      	ldr	x17, [x16, #0x478]
 1070b18:      	add	x16, x16, #0x478
 1070b1c:      	br	x17

0000000001070b20 <_ZNK8mtlabar38FaceData13getHeadPointsEv@plt>:
 1070b20:      	adrp	x16, 0x10cf000
 1070b24:      	ldr	x17, [x16, #0x480]
 1070b28:      	add	x16, x16, #0x480
 1070b2c:      	br	x17

0000000001070b30 <_ZNSt6__ndk15mutexD1Ev@plt>:
 1070b30:      	adrp	x16, 0x10cf000
 1070b34:      	ldr	x17, [x16, #0x488]
 1070b38:      	add	x16, x16, #0x488
 1070b3c:      	br	x17

0000000001070b40 <_ZNSt6__ndk15mutex4lockEv@plt>:
 1070b40:      	adrp	x16, 0x10cf000
 1070b44:      	ldr	x17, [x16, #0x490]
 1070b48:      	add	x16, x16, #0x490
 1070b4c:      	br	x17

0000000001070b50 <_ZNSt6__ndk15mutex6unlockEv@plt>:
 1070b50:      	adrp	x16, 0x10cf000
 1070b54:      	ldr	x17, [x16, #0x498]
 1070b58:      	add	x16, x16, #0x498
 1070b5c:      	br	x17

0000000001070b60 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi@plt>:
 1070b60:      	adrp	x16, 0x10cf000
 1070b64:      	ldr	x17, [x16, #0x4a0]
 1070b68:      	add	x16, x16, #0x4a0
 1070b6c:      	br	x17

0000000001070b70 <wgpuRenderPassEncoderSetScissorRect@plt>:
 1070b70:      	adrp	x16, 0x10cf000
 1070b74:      	ldr	x17, [x16, #0x4a8]
 1070b78:      	add	x16, x16, #0x4a8
 1070b7c:      	br	x17

0000000001070b80 <wgpuCommandEncoderCopyTextureToTexture@plt>:
 1070b80:      	adrp	x16, 0x10cf000
 1070b84:      	ldr	x17, [x16, #0x4b0]
 1070b88:      	add	x16, x16, #0x4b0
 1070b8c:      	br	x17

0000000001070b90 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
 1070b90:      	adrp	x16, 0x10cf000
 1070b94:      	ldr	x17, [x16, #0x4b8]
 1070b98:      	add	x16, x16, #0x4b8
 1070b9c:      	br	x17

0000000001070ba0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
 1070ba0:      	adrp	x16, 0x10cf000
 1070ba4:      	ldr	x17, [x16, #0x4c0]
 1070ba8:      	add	x16, x16, #0x4c0
 1070bac:      	br	x17

0000000001070bb0 <_ZN5image8subImageIhEENS_11DetailImageIT_EERKS3_jjjj@plt>:
 1070bb0:      	adrp	x16, 0x10cf000
 1070bb4:      	ldr	x17, [x16, #0x4c8]
 1070bb8:      	add	x16, x16, #0x4c8
 1070bbc:      	br	x17

0000000001070bc0 <wgpuQueueWriteBuffer@plt>:
 1070bc0:      	adrp	x16, 0x10cf000
 1070bc4:      	ldr	x17, [x16, #0x4d0]
 1070bc8:      	add	x16, x16, #0x4d0
 1070bcc:      	br	x17

0000000001070bd0 <sincos@plt>:
 1070bd0:      	adrp	x16, 0x10cf000
 1070bd4:      	ldr	x17, [x16, #0x4d8]
 1070bd8:      	add	x16, x16, #0x4d8
 1070bdc:      	br	x17

0000000001070be0 <wgpuDeviceCreateBuffer@plt>:
 1070be0:      	adrp	x16, 0x10cf000
 1070be4:      	ldr	x17, [x16, #0x4e0]
 1070be8:      	add	x16, x16, #0x4e0
 1070bec:      	br	x17

0000000001070bf0 <wgpuBufferGetMappedRange@plt>:
 1070bf0:      	adrp	x16, 0x10cf000
 1070bf4:      	ldr	x17, [x16, #0x4e8]
 1070bf8:      	add	x16, x16, #0x4e8
 1070bfc:      	br	x17

0000000001070c00 <wgpuBufferUnmap@plt>:
 1070c00:      	adrp	x16, 0x10cf000
 1070c04:      	ldr	x17, [x16, #0x4f0]
 1070c08:      	add	x16, x16, #0x4f0
 1070c0c:      	br	x17

0000000001070c10 <wgpuCommandEncoderCopyTextureToBuffer@plt>:
 1070c10:      	adrp	x16, 0x10cf000
 1070c14:      	ldr	x17, [x16, #0x4f8]
 1070c18:      	add	x16, x16, #0x4f8
 1070c1c:      	br	x17

0000000001070c20 <wgpuQueueSubmit@plt>:
 1070c20:      	adrp	x16, 0x10cf000
 1070c24:      	ldr	x17, [x16, #0x500]
 1070c28:      	add	x16, x16, #0x500
 1070c2c:      	br	x17

0000000001070c30 <_ZNSt6__ndk17promiseIvEC1Ev@plt>:
 1070c30:      	adrp	x16, 0x10cf000
 1070c34:      	ldr	x17, [x16, #0x508]
 1070c38:      	add	x16, x16, #0x508
 1070c3c:      	br	x17

0000000001070c40 <wgpuBufferMapAsync@plt>:
 1070c40:      	adrp	x16, 0x10cf000
 1070c44:      	ldr	x17, [x16, #0x510]
 1070c48:      	add	x16, x16, #0x510
 1070c4c:      	br	x17

0000000001070c50 <_ZNSt6__ndk17promiseIvE10get_futureEv@plt>:
 1070c50:      	adrp	x16, 0x10cf000
 1070c54:      	ldr	x17, [x16, #0x518]
 1070c58:      	add	x16, x16, #0x518
 1070c5c:      	br	x17

0000000001070c60 <_ZNSt6__ndk117__assoc_sub_state4waitEv@plt>:
 1070c60:      	adrp	x16, 0x10cf000
 1070c64:      	ldr	x17, [x16, #0x520]
 1070c68:      	add	x16, x16, #0x520
 1070c6c:      	br	x17

0000000001070c70 <_ZNSt6__ndk16futureIvED1Ev@plt>:
 1070c70:      	adrp	x16, 0x10cf000
 1070c74:      	ldr	x17, [x16, #0x528]
 1070c78:      	add	x16, x16, #0x528
 1070c7c:      	br	x17

0000000001070c80 <_ZNSt6__ndk17promiseIvED1Ev@plt>:
 1070c80:      	adrp	x16, 0x10cf000
 1070c84:      	ldr	x17, [x16, #0x530]
 1070c88:      	add	x16, x16, #0x530
 1070c8c:      	br	x17

0000000001070c90 <wgpuBufferGetConstMappedRange@plt>:
 1070c90:      	adrp	x16, 0x10cf000
 1070c94:      	ldr	x17, [x16, #0x538]
 1070c98:      	add	x16, x16, #0x538
 1070c9c:      	br	x17

0000000001070ca0 <_ZNSt6__ndk17promiseIvE9set_valueEv@plt>:
 1070ca0:      	adrp	x16, 0x10cf000
 1070ca4:      	ldr	x17, [x16, #0x540]
 1070ca8:      	add	x16, x16, #0x540
 1070cac:      	br	x17

0000000001070cb0 <wgpuBufferDestroy@plt>:
 1070cb0:      	adrp	x16, 0x10cf000
 1070cb4:      	ldr	x17, [x16, #0x548]
 1070cb8:      	add	x16, x16, #0x548
 1070cbc:      	br	x17

0000000001070cc0 <wgpuDeviceCreateCommandEncoder@plt>:
 1070cc0:      	adrp	x16, 0x10cf000
 1070cc4:      	ldr	x17, [x16, #0x550]
 1070cc8:      	add	x16, x16, #0x550
 1070ccc:      	br	x17

0000000001070cd0 <wgpuCommandEncoderBeginRenderPass@plt>:
 1070cd0:      	adrp	x16, 0x10cf000
 1070cd4:      	ldr	x17, [x16, #0x558]
 1070cd8:      	add	x16, x16, #0x558
 1070cdc:      	br	x17

0000000001070ce0 <wgpuRenderPassEncoderEnd@plt>:
 1070ce0:      	adrp	x16, 0x10cf000
 1070ce4:      	ldr	x17, [x16, #0x560]
 1070ce8:      	add	x16, x16, #0x560
 1070cec:      	br	x17

0000000001070cf0 <wgpuCommandEncoderFinish@plt>:
 1070cf0:      	adrp	x16, 0x10cf000
 1070cf4:      	ldr	x17, [x16, #0x568]
 1070cf8:      	add	x16, x16, #0x568
 1070cfc:      	br	x17

0000000001070d00 <wgpuCommandEncoderRelease@plt>:
 1070d00:      	adrp	x16, 0x10cf000
 1070d04:      	ldr	x17, [x16, #0x570]
 1070d08:      	add	x16, x16, #0x570
 1070d0c:      	br	x17

0000000001070d10 <wgpuCommandBufferRelease@plt>:
 1070d10:      	adrp	x16, 0x10cf000
 1070d14:      	ldr	x17, [x16, #0x578]
 1070d18:      	add	x16, x16, #0x578
 1070d1c:      	br	x17

0000000001070d20 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKcm@plt>:
 1070d20:      	adrp	x16, 0x10cf000
 1070d24:      	ldr	x17, [x16, #0x580]
 1070d28:      	add	x16, x16, #0x580
 1070d2c:      	br	x17

0000000001070d30 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
 1070d30:      	adrp	x16, 0x10cf000
 1070d34:      	ldr	x17, [x16, #0x588]
 1070d38:      	add	x16, x16, #0x588
 1070d3c:      	br	x17

0000000001070d40 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
 1070d40:      	adrp	x16, 0x10cf000
 1070d44:      	ldr	x17, [x16, #0x590]
 1070d48:      	add	x16, x16, #0x590
 1070d4c:      	br	x17

0000000001070d50 <wmemchr@plt>:
 1070d50:      	adrp	x16, 0x10cf000
 1070d54:      	ldr	x17, [x16, #0x598]
 1070d58:      	add	x16, x16, #0x598
 1070d5c:      	br	x17

0000000001070d60 <__vsprintf_chk@plt>:
 1070d60:      	adrp	x16, 0x10cf000
 1070d64:      	ldr	x17, [x16, #0x5a0]
 1070d68:      	add	x16, x16, #0x5a0
 1070d6c:      	br	x17

0000000001070d70 <puts@plt>:
 1070d70:      	adrp	x16, 0x10cf000
 1070d74:      	ldr	x17, [x16, #0x5a8]
 1070d78:      	add	x16, x16, #0x5a8
 1070d7c:      	br	x17

0000000001070d80 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERb@plt>:
 1070d80:      	adrp	x16, 0x10cf000
 1070d84:      	ldr	x17, [x16, #0x5b0]
 1070d88:      	add	x16, x16, #0x5b0
 1070d8c:      	br	x17

0000000001070d90 <_ZNSt6__ndk16__sortIRNS_6__lessIiiEEPiEEvT0_S5_T_@plt>:
 1070d90:      	adrp	x16, 0x10cf000
 1070d94:      	ldr	x17, [x16, #0x5b8]
 1070d98:      	add	x16, x16, #0x5b8
 1070d9c:      	br	x17

0000000001070da0 <cos@plt>:
 1070da0:      	adrp	x16, 0x10cf000
 1070da4:      	ldr	x17, [x16, #0x5c0]
 1070da8:      	add	x16, x16, #0x5c0
 1070dac:      	br	x17

0000000001070db0 <atanf@plt>:
 1070db0:      	adrp	x16, 0x10cf000
 1070db4:      	ldr	x17, [x16, #0x5c8]
 1070db8:      	add	x16, x16, #0x5c8
 1070dbc:      	br	x17

0000000001070dc0 <_ZN5image11typeConvertIfDhEENS_11DetailImageIT0_EERKNS1_IT_EE@plt>:
 1070dc0:      	adrp	x16, 0x10cf000
 1070dc4:      	ldr	x17, [x16, #0x5d0]
 1070dc8:      	add	x16, x16, #0x5d0
 1070dcc:      	br	x17

0000000001070dd0 <_ZN5image11DetailImageIDhEC2Ejjj@plt>:
 1070dd0:      	adrp	x16, 0x10cf000
 1070dd4:      	ldr	x17, [x16, #0x5d8]
 1070dd8:      	add	x16, x16, #0x5d8
 1070ddc:      	br	x17

0000000001070de0 <cbrtf@plt>:
 1070de0:      	adrp	x16, 0x10cf000
 1070de4:      	ldr	x17, [x16, #0x5e0]
 1070de8:      	add	x16, x16, #0x5e0
 1070dec:      	br	x17

0000000001070df0 <cbrt@plt>:
 1070df0:      	adrp	x16, 0x10cf000
 1070df4:      	ldr	x17, [x16, #0x5e8]
 1070df8:      	add	x16, x16, #0x5e8
 1070dfc:      	br	x17

0000000001070e00 <_ZNSt6__ndk119__shared_weak_count4lockEv@plt>:
 1070e00:      	adrp	x16, 0x10cf000
 1070e04:      	ldr	x17, [x16, #0x5f0]
 1070e08:      	add	x16, x16, #0x5f0
 1070e0c:      	br	x17

0000000001070e10 <wgpuRenderPassEncoderInsertDebugMarker@plt>:
 1070e10:      	adrp	x16, 0x10cf000
 1070e14:      	ldr	x17, [x16, #0x5f8]
 1070e18:      	add	x16, x16, #0x5f8
 1070e1c:      	br	x17

0000000001070e20 <ScalePlane@plt>:
 1070e20:      	adrp	x16, 0x10cf000
 1070e24:      	ldr	x17, [x16, #0x600]
 1070e28:      	add	x16, x16, #0x600
 1070e2c:      	br	x17

0000000001070e30 <_ZN8mtlabar324ActiveWordColorInterfaceC2Ev@plt>:
 1070e30:      	adrp	x16, 0x10cf000
 1070e34:      	ldr	x17, [x16, #0x608]
 1070e38:      	add	x16, x16, #0x608
 1070e3c:      	br	x17

0000000001070e40 <_ZN8mtlabar324ActiveWordStyleInterfaceC2Ev@plt>:
 1070e40:      	adrp	x16, 0x10cf000
 1070e44:      	ldr	x17, [x16, #0x610]
 1070e48:      	add	x16, x16, #0x610
 1070e4c:      	br	x17

0000000001070e50 <_ZN8mtlabar323TextWarpConfigInterfaceC2Ev@plt>:
 1070e50:      	adrp	x16, 0x10cf000
 1070e54:      	ldr	x17, [x16, #0x618]
 1070e58:      	add	x16, x16, #0x618
 1070e5c:      	br	x17

0000000001070e60 <_ZN8mtlabar325LayerAnimationInteraction13getConfigPathEv@plt>:
 1070e60:      	adrp	x16, 0x10cf000
 1070e64:      	ldr	x17, [x16, #0x620]
 1070e68:      	add	x16, x16, #0x620
 1070e6c:      	br	x17

0000000001070e70 <_ZN8mtlabar325LayerAnimationInteraction13setConfigPathEPKc@plt>:
 1070e70:      	adrp	x16, 0x10cf000
 1070e74:      	ldr	x17, [x16, #0x628]
 1070e78:      	add	x16, x16, #0x628
 1070e7c:      	br	x17

0000000001070e80 <logf@plt>:
 1070e80:      	adrp	x16, 0x10cf000
 1070e84:      	ldr	x17, [x16, #0x630]
 1070e88:      	add	x16, x16, #0x630
 1070e8c:      	br	x17

0000000001070e90 <_ZN8mtlabar316LayerInteraction14getDefaultSizeEv@plt>:
 1070e90:      	adrp	x16, 0x10cf000
 1070e94:      	ldr	x17, [x16, #0x638]
 1070e98:      	add	x16, x16, #0x638
 1070e9c:      	br	x17

0000000001070ea0 <_ZNSt6__ndk15mutex8try_lockEv@plt>:
 1070ea0:      	adrp	x16, 0x10cf000
 1070ea4:      	ldr	x17, [x16, #0x640]
 1070ea8:      	add	x16, x16, #0x640
 1070eac:      	br	x17

0000000001070eb0 <_ZN8mtlabar316LayerInteraction24getLayerAnimationManagerEv@plt>:
 1070eb0:      	adrp	x16, 0x10cf000
 1070eb4:      	ldr	x17, [x16, #0x648]
 1070eb8:      	add	x16, x16, #0x648
 1070ebc:      	br	x17

0000000001070ec0 <_ZN8mtlabar321LayerAnimationManager20getAnimationListSizeEv@plt>:
 1070ec0:      	adrp	x16, 0x10cf000
 1070ec4:      	ldr	x17, [x16, #0x650]
 1070ec8:      	add	x16, x16, #0x650
 1070ecc:      	br	x17

0000000001070ed0 <_ZN8mtlabar321LayerAnimationManager23getAnimationListByIndexEi@plt>:
 1070ed0:      	adrp	x16, 0x10cf000
 1070ed4:      	ldr	x17, [x16, #0x658]
 1070ed8:      	add	x16, x16, #0x658
 1070edc:      	br	x17

0000000001070ee0 <_ZN8mtlabar321LayerAnimationManager17subtractAnimationEPv@plt>:
 1070ee0:      	adrp	x16, 0x10cf000
 1070ee4:      	ldr	x17, [x16, #0x660]
 1070ee8:      	add	x16, x16, #0x660
 1070eec:      	br	x17

0000000001070ef0 <_ZNSt6__ndk16__sortIRNS_6__lessIffEEPfEEvT0_S5_T_@plt>:
 1070ef0:      	adrp	x16, 0x10cf000
 1070ef4:      	ldr	x17, [x16, #0x668]
 1070ef8:      	add	x16, x16, #0x668
 1070efc:      	br	x17

0000000001070f00 <_ZN8mtlabar325LayerTransformInteraction10getScaleXYEv@plt>:
 1070f00:      	adrp	x16, 0x10cf000
 1070f04:      	ldr	x17, [x16, #0x670]
 1070f08:      	add	x16, x16, #0x670
 1070f0c:      	br	x17

0000000001070f10 <_ZN8mtlabar325LineLayoutConfigInterfaceD2Ev@plt>:
 1070f10:      	adrp	x16, 0x10cf000
 1070f14:      	ldr	x17, [x16, #0x678]
 1070f18:      	add	x16, x16, #0x678
 1070f1c:      	br	x17

0000000001070f20 <_ZN8mtlabar325LineLayoutConfigInterfaceC2Ev@plt>:
 1070f20:      	adrp	x16, 0x10cf000
 1070f24:      	ldr	x17, [x16, #0x680]
 1070f28:      	add	x16, x16, #0x680
 1070f2c:      	br	x17

0000000001070f30 <_ZNK8mtlabar35Field7getTypeEv@plt>:
 1070f30:      	adrp	x16, 0x10cf000
 1070f34:      	ldr	x17, [x16, #0x688]
 1070f38:      	add	x16, x16, #0x688
 1070f3c:      	br	x17

0000000001070f40 <_ZN8mtlabar35Field8setValueERKNS_14ParameterValueE@plt>:
 1070f40:      	adrp	x16, 0x10cf000
 1070f44:      	ldr	x17, [x16, #0x690]
 1070f48:      	add	x16, x16, #0x690
 1070f4c:      	br	x17

0000000001070f50 <_ZNK8mtlabar35Field17detailEnumerationEv@plt>:
 1070f50:      	adrp	x16, 0x10cf000
 1070f54:      	ldr	x17, [x16, #0x698]
 1070f58:      	add	x16, x16, #0x698
 1070f5c:      	br	x17

0000000001070f60 <_ZN8mtlabar35Field11resizeChildEm@plt>:
 1070f60:      	adrp	x16, 0x10cf000
 1070f64:      	ldr	x17, [x16, #0x6a0]
 1070f68:      	add	x16, x16, #0x6a0
 1070f6c:      	br	x17

0000000001070f70 <_ZNK8mtlabar35Field13getChildCountEv@plt>:
 1070f70:      	adrp	x16, 0x10cf000
 1070f74:      	ldr	x17, [x16, #0x6a8]
 1070f78:      	add	x16, x16, #0x6a8
 1070f7c:      	br	x17

0000000001070f80 <_ZN8mtlabar35Field15getChildByIndexEm@plt>:
 1070f80:      	adrp	x16, 0x10cf000
 1070f84:      	ldr	x17, [x16, #0x6b0]
 1070f88:      	add	x16, x16, #0x6b0
 1070f8c:      	br	x17

0000000001070f90 <_ZNK8mtlabar35Field17getBaseClassCountEv@plt>:
 1070f90:      	adrp	x16, 0x10cf000
 1070f94:      	ldr	x17, [x16, #0x6b8]
 1070f98:      	add	x16, x16, #0x6b8
 1070f9c:      	br	x17

0000000001070fa0 <_ZN8mtlabar35Field19getBaseClassByIndexEm@plt>:
 1070fa0:      	adrp	x16, 0x10cf000
 1070fa4:      	ldr	x17, [x16, #0x6c0]
 1070fa8:      	add	x16, x16, #0x6c0
 1070fac:      	br	x17

0000000001070fb0 <_ZNK8mtlabar35Field14detailCategoryEv@plt>:
 1070fb0:      	adrp	x16, 0x10cf000
 1070fb4:      	ldr	x17, [x16, #0x6c8]
 1070fb8:      	add	x16, x16, #0x6c8
 1070fbc:      	br	x17

0000000001070fc0 <_ZN8mtlabar35Field14getChildByNameEPKc@plt>:
 1070fc0:      	adrp	x16, 0x10cf000
 1070fc4:      	ldr	x17, [x16, #0x6d0]
 1070fc8:      	add	x16, x16, #0x6d0
 1070fcc:      	br	x17

0000000001070fd0 <_ZNK8mtlabar35Field8getValueEv@plt>:
 1070fd0:      	adrp	x16, 0x10cf000
 1070fd4:      	ldr	x17, [x16, #0x6d8]
 1070fd8:      	add	x16, x16, #0x6d8
 1070fdc:      	br	x17

0000000001070fe0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPKv@plt>:
 1070fe0:      	adrp	x16, 0x10cf000
 1070fe4:      	ldr	x17, [x16, #0x6e0]
 1070fe8:      	add	x16, x16, #0x6e0
 1070fec:      	br	x17

0000000001070ff0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERl@plt>:
 1070ff0:      	adrp	x16, 0x10cf000
 1070ff4:      	ldr	x17, [x16, #0x6e8]
 1070ff8:      	add	x16, x16, #0x6e8
 1070ffc:      	br	x17

0000000001071000 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERd@plt>:
 1071000:      	adrp	x16, 0x10cf000
 1071004:      	ldr	x17, [x16, #0x6f0]
 1071008:      	add	x16, x16, #0x6f0
 107100c:      	br	x17

0000000001071010 <_Z25ARSPMDestroySkottieHandleRPv@plt>:
 1071010:      	adrp	x16, 0x10cf000
 1071014:      	ldr	x17, [x16, #0x6f8]
 1071018:      	add	x16, x16, #0x6f8
 107101c:      	br	x17

0000000001071020 <_Z24ARSPMCreateSkottieHandlev@plt>:
 1071020:      	adrp	x16, 0x10cf000
 1071024:      	ldr	x17, [x16, #0x700]
 1071028:      	add	x16, x16, #0x700
 107102c:      	br	x17

0000000001071030 <_Z20ARSPMSkottieLoadDataRPvPKciS2_@plt>:
 1071030:      	adrp	x16, 0x10cf000
 1071034:      	ldr	x17, [x16, #0x708]
 1071038:      	add	x16, x16, #0x708
 107103c:      	br	x17

0000000001071040 <_Z29ARSPMSkottieGetAnimationWidthRPv@plt>:
 1071040:      	adrp	x16, 0x10cf000
 1071044:      	ldr	x17, [x16, #0x710]
 1071048:      	add	x16, x16, #0x710
 107104c:      	br	x17

0000000001071050 <_Z30ARSPMSkottieGetAnimationHeightRPv@plt>:
 1071050:      	adrp	x16, 0x10cf000
 1071054:      	ldr	x17, [x16, #0x718]
 1071058:      	add	x16, x16, #0x718
 107105c:      	br	x17

0000000001071060 <_Z32ARSPMSkottieGetAnimationDurationRPv@plt>:
 1071060:      	adrp	x16, 0x10cf000
 1071064:      	ldr	x17, [x16, #0x720]
 1071068:      	add	x16, x16, #0x720
 107106c:      	br	x17

0000000001071070 <_Z27ARSPMSkottieGetAnimationFPSRPv@plt>:
 1071070:      	adrp	x16, 0x10cf000
 1071074:      	ldr	x17, [x16, #0x728]
 1071078:      	add	x16, x16, #0x728
 107107c:      	br	x17

0000000001071080 <_Z30ARSPMSkottiAnimationDrawPixelsRPvfiiS_m@plt>:
 1071080:      	adrp	x16, 0x10cf000
 1071084:      	ldr	x17, [x16, #0x730]
 1071088:      	add	x16, x16, #0x730
 107108c:      	br	x17

0000000001071090 <_ZNSt6__ndk19to_stringEj@plt>:
 1071090:      	adrp	x16, 0x10cf000
 1071094:      	ldr	x17, [x16, #0x738]
 1071098:      	add	x16, x16, #0x738
 107109c:      	br	x17

00000000010710a0 <wgpuDeviceCreateBindGroupLayout@plt>:
 10710a0:      	adrp	x16, 0x10cf000
 10710a4:      	ldr	x17, [x16, #0x740]
 10710a8:      	add	x16, x16, #0x740
 10710ac:      	br	x17

00000000010710b0 <wgpuDeviceCreatePipelineLayout@plt>:
 10710b0:      	adrp	x16, 0x10cf000
 10710b4:      	ldr	x17, [x16, #0x748]
 10710b8:      	add	x16, x16, #0x748
 10710bc:      	br	x17

00000000010710c0 <wgpuBindGroupLayoutRelease@plt>:
 10710c0:      	adrp	x16, 0x10cf000
 10710c4:      	ldr	x17, [x16, #0x750]
 10710c8:      	add	x16, x16, #0x750
 10710cc:      	br	x17

00000000010710d0 <wgpuPipelineLayoutRelease@plt>:
 10710d0:      	adrp	x16, 0x10cf000
 10710d4:      	ldr	x17, [x16, #0x758]
 10710d8:      	add	x16, x16, #0x758
 10710dc:      	br	x17

00000000010710e0 <wgpuCommandEncoderPushDebugGroup@plt>:
 10710e0:      	adrp	x16, 0x10cf000
 10710e4:      	ldr	x17, [x16, #0x760]
 10710e8:      	add	x16, x16, #0x760
 10710ec:      	br	x17

00000000010710f0 <wgpuCommandEncoderPopDebugGroup@plt>:
 10710f0:      	adrp	x16, 0x10cf000
 10710f4:      	ldr	x17, [x16, #0x768]
 10710f8:      	add	x16, x16, #0x768
 10710fc:      	br	x17

0000000001071100 <wgpuDeviceGetQueue@plt>:
 1071100:      	adrp	x16, 0x10cf000
 1071104:      	ldr	x17, [x16, #0x770]
 1071108:      	add	x16, x16, #0x770
 107110c:      	br	x17

0000000001071110 <wgpuQueueRelease@plt>:
 1071110:      	adrp	x16, 0x10cf000
 1071114:      	ldr	x17, [x16, #0x778]
 1071118:      	add	x16, x16, #0x778
 107111c:      	br	x17

0000000001071120 <_ZNSt6__ndk115recursive_mutex4lockEv@plt>:
 1071120:      	adrp	x16, 0x10cf000
 1071124:      	ldr	x17, [x16, #0x780]
 1071128:      	add	x16, x16, #0x780
 107112c:      	br	x17

0000000001071130 <_ZNSt6__ndk115recursive_mutex6unlockEv@plt>:
 1071130:      	adrp	x16, 0x10cf000
 1071134:      	ldr	x17, [x16, #0x788]
 1071138:      	add	x16, x16, #0x788
 107113c:      	br	x17

0000000001071140 <_ZN8mtlabar323CharBackgroundInterfaceC2Ev@plt>:
 1071140:      	adrp	x16, 0x10cf000
 1071144:      	ldr	x17, [x16, #0x790]
 1071148:      	add	x16, x16, #0x790
 107114c:      	br	x17

0000000001071150 <_ZN8mtlabar323CharBackgroundInterfaceD2Ev@plt>:
 1071150:      	adrp	x16, 0x10cf000
 1071154:      	ldr	x17, [x16, #0x798]
 1071158:      	add	x16, x16, #0x798
 107115c:      	br	x17

0000000001071160 <_ZN8mtlabar326CharSVGBackgroundInterfaceC2Ev@plt>:
 1071160:      	adrp	x16, 0x10cf000
 1071164:      	ldr	x17, [x16, #0x7a0]
 1071168:      	add	x16, x16, #0x7a0
 107116c:      	br	x17

0000000001071170 <_ZN8mtlabar326CharSVGBackgroundInterfaceD2Ev@plt>:
 1071170:      	adrp	x16, 0x10cf000
 1071174:      	ldr	x17, [x16, #0x7a8]
 1071178:      	add	x16, x16, #0x7a8
 107117c:      	br	x17

0000000001071180 <_ZN8mtlabar331TextInactiveTextConfigInterfaceC2Ev@plt>:
 1071180:      	adrp	x16, 0x10cf000
 1071184:      	ldr	x17, [x16, #0x7b0]
 1071188:      	add	x16, x16, #0x7b0
 107118c:      	br	x17

0000000001071190 <_ZN8mtlabar331TextInactiveTextConfigInterfaceD2Ev@plt>:
 1071190:      	adrp	x16, 0x10cf000
 1071194:      	ldr	x17, [x16, #0x7b8]
 1071198:      	add	x16, x16, #0x7b8
 107119c:      	br	x17

00000000010711a0 <_ZN8mtlabar316TextASRInterfaceC2Ev@plt>:
 10711a0:      	adrp	x16, 0x10cf000
 10711a4:      	ldr	x17, [x16, #0x7c0]
 10711a8:      	add	x16, x16, #0x7c0
 10711ac:      	br	x17

00000000010711b0 <_ZNSt6__ndk115recursive_mutexC1Ev@plt>:
 10711b0:      	adrp	x16, 0x10cf000
 10711b4:      	ldr	x17, [x16, #0x7c8]
 10711b8:      	add	x16, x16, #0x7c8
 10711bc:      	br	x17

00000000010711c0 <_ZNSt6__ndk115recursive_mutexD1Ev@plt>:
 10711c0:      	adrp	x16, 0x10cf000
 10711c4:      	ldr	x17, [x16, #0x7d0]
 10711c8:      	add	x16, x16, #0x7d0
 10711cc:      	br	x17

00000000010711d0 <_ZN8mtlabar327SelectionAnimationInterfaceC2Ev@plt>:
 10711d0:      	adrp	x16, 0x10cf000
 10711d4:      	ldr	x17, [x16, #0x7d8]
 10711d8:      	add	x16, x16, #0x7d8
 10711dc:      	br	x17

00000000010711e0 <_ZN8mtlabar327SelectionAnimationInterfaceD2Ev@plt>:
 10711e0:      	adrp	x16, 0x10cf000
 10711e4:      	ldr	x17, [x16, #0x7e0]
 10711e8:      	add	x16, x16, #0x7e0
 10711ec:      	br	x17

00000000010711f0 <_ZN8mtlabar323TextShadowConfigurationC2ERKS0_@plt>:
 10711f0:      	adrp	x16, 0x10cf000
 10711f4:      	ldr	x17, [x16, #0x7e8]
 10711f8:      	add	x16, x16, #0x7e8
 10711fc:      	br	x17

0000000001071200 <_ZN8mtlabar332TextBackgroundColorConfigurationC2ERKS0_@plt>:
 1071200:      	adrp	x16, 0x10cf000
 1071204:      	ldr	x17, [x16, #0x7f0]
 1071208:      	add	x16, x16, #0x7f0
 107120c:      	br	x17

0000000001071210 <_ZN8mtlabar321TextGlowConfigurationC2ERKS0_@plt>:
 1071210:      	adrp	x16, 0x10cf000
 1071214:      	ldr	x17, [x16, #0x7f8]
 1071218:      	add	x16, x16, #0x7f8
 107121c:      	br	x17

0000000001071220 <_ZN8mtlabar323TextStrokeConfigurationC2ERKS0_@plt>:
 1071220:      	adrp	x16, 0x10cf000
 1071224:      	ldr	x17, [x16, #0x800]
 1071228:      	add	x16, x16, #0x800
 107122c:      	br	x17

0000000001071230 <__cxa_thread_atexit@plt>:
 1071230:      	adrp	x16, 0x10cf000
 1071234:      	ldr	x17, [x16, #0x808]
 1071238:      	add	x16, x16, #0x808
 107123c:      	br	x17

0000000001071240 <_ZN8mtlabar326IconSequenceStyleInterfaceC2Ev@plt>:
 1071240:      	adrp	x16, 0x10cf000
 1071244:      	ldr	x17, [x16, #0x810]
 1071248:      	add	x16, x16, #0x810
 107124c:      	br	x17

0000000001071250 <_ZN8mtlabar326IconSequenceStyleInterfaceD2Ev@plt>:
 1071250:      	adrp	x16, 0x10cf000
 1071254:      	ldr	x17, [x16, #0x818]
 1071258:      	add	x16, x16, #0x818
 107125c:      	br	x17

0000000001071260 <_ZN8mtlabar326IconSequenceColorInterfaceD2Ev@plt>:
 1071260:      	adrp	x16, 0x10cf000
 1071264:      	ldr	x17, [x16, #0x820]
 1071268:      	add	x16, x16, #0x820
 107126c:      	br	x17

0000000001071270 <_ZN8mtlabar323TextBubbleConfigurationC2Ev@plt>:
 1071270:      	adrp	x16, 0x10cf000
 1071274:      	ldr	x17, [x16, #0x828]
 1071278:      	add	x16, x16, #0x828
 107127c:      	br	x17

0000000001071280 <_ZN8mtlabar325TextEditableConfigurationC2Ev@plt>:
 1071280:      	adrp	x16, 0x10cf000
 1071284:      	ldr	x17, [x16, #0x830]
 1071288:      	add	x16, x16, #0x830
 107128c:      	br	x17

0000000001071290 <_ZN8mtlabar321TextPathConfigurationC2Ev@plt>:
 1071290:      	adrp	x16, 0x10cf000
 1071294:      	ldr	x17, [x16, #0x838]
 1071298:      	add	x16, x16, #0x838
 107129c:      	br	x17

00000000010712a0 <_ZN8mtlabar325TextEditableConfigurationD2Ev@plt>:
 10712a0:      	adrp	x16, 0x10cf000
 10712a4:      	ldr	x17, [x16, #0x840]
 10712a8:      	add	x16, x16, #0x840
 10712ac:      	br	x17

00000000010712b0 <_ZN8mtlabar323TextBubbleConfigurationD2Ev@plt>:
 10712b0:      	adrp	x16, 0x10cf000
 10712b4:      	ldr	x17, [x16, #0x848]
 10712b8:      	add	x16, x16, #0x848
 10712bc:      	br	x17

00000000010712c0 <_ZN8mtlabar321TextPathConfigurationD2Ev@plt>:
 10712c0:      	adrp	x16, 0x10cf000
 10712c4:      	ldr	x17, [x16, #0x850]
 10712c8:      	add	x16, x16, #0x850
 10712cc:      	br	x17

00000000010712d0 <_ZN8mtlabar322FTextPathConfigurationaSERKS0_@plt>:
 10712d0:      	adrp	x16, 0x10cf000
 10712d4:      	ldr	x17, [x16, #0x858]
 10712d8:      	add	x16, x16, #0x858
 10712dc:      	br	x17

00000000010712e0 <_ZN8mtlabar320TextASRWordInterfaceC2Ev@plt>:
 10712e0:      	adrp	x16, 0x10cf000
 10712e4:      	ldr	x17, [x16, #0x860]
 10712e8:      	add	x16, x16, #0x860
 10712ec:      	br	x17

00000000010712f0 <_ZN8mtlabar320TextASRWordInterfaceD2Ev@plt>:
 10712f0:      	adrp	x16, 0x10cf000
 10712f4:      	ldr	x17, [x16, #0x868]
 10712f8:      	add	x16, x16, #0x868
 10712fc:      	br	x17

0000000001071300 <_ZN8mtlabar322FTextPathConfiguration14loadFromConfigERN3vfs3VFSERKN5utils4PathE@plt>:
 1071300:      	adrp	x16, 0x10cf000
 1071304:      	ldr	x17, [x16, #0x870]
 1071308:      	add	x16, x16, #0x870
 107130c:      	br	x17

0000000001071310 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
 1071310:      	adrp	x16, 0x10cf000
 1071314:      	ldr	x17, [x16, #0x878]
 1071318:      	add	x16, x16, #0x878
 107131c:      	br	x17

0000000001071320 <wgpuRenderPassEncoderPushDebugGroup@plt>:
 1071320:      	adrp	x16, 0x10cf000
 1071324:      	ldr	x17, [x16, #0x880]
 1071328:      	add	x16, x16, #0x880
 107132c:      	br	x17

0000000001071330 <wgpuRenderPassEncoderPopDebugGroup@plt>:
 1071330:      	adrp	x16, 0x10cf000
 1071334:      	ldr	x17, [x16, #0x888]
 1071338:      	add	x16, x16, #0x888
 107133c:      	br	x17

0000000001071340 <wgpuBufferSetLabel@plt>:
 1071340:      	adrp	x16, 0x10cf000
 1071344:      	ldr	x17, [x16, #0x890]
 1071348:      	add	x16, x16, #0x890
 107134c:      	br	x17

0000000001071350 <vldp_get_data_protocol_animal_result@plt>:
 1071350:      	adrp	x16, 0x10cf000
 1071354:      	ldr	x17, [x16, #0x898]
 1071358:      	add	x16, x16, #0x898
 107135c:      	br	x17

0000000001071360 <vldp_get_animal_result_pointer_ref@plt>:
 1071360:      	adrp	x16, 0x10cf000
 1071364:      	ldr	x17, [x16, #0x8a0]
 1071368:      	add	x16, x16, #0x8a0
 107136c:      	br	x17

0000000001071370 <vldp_get_animal_result_animals@plt>:
 1071370:      	adrp	x16, 0x10cf000
 1071374:      	ldr	x17, [x16, #0x8a8]
 1071378:      	add	x16, x16, #0x8a8
 107137c:      	br	x17

0000000001071380 <vldp_get_animal_array_pointer_size@plt>:
 1071380:      	adrp	x16, 0x10cf000
 1071384:      	ldr	x17, [x16, #0x8b0]
 1071388:      	add	x16, x16, #0x8b0
 107138c:      	br	x17

0000000001071390 <vldp_get_animal_array_pointer_at@plt>:
 1071390:      	adrp	x16, 0x10cf000
 1071394:      	ldr	x17, [x16, #0x8b8]
 1071398:      	add	x16, x16, #0x8b8
 107139c:      	br	x17

00000000010713a0 <vldp_get_animal_id@plt>:
 10713a0:      	adrp	x16, 0x10cf000
 10713a4:      	ldr	x17, [x16, #0x8c0]
 10713a8:      	add	x16, x16, #0x8c0
 10713ac:      	br	x17

00000000010713b0 <vldp_get_animal_animal_points@plt>:
 10713b0:      	adrp	x16, 0x10cf000
 10713b4:      	ldr	x17, [x16, #0x8c8]
 10713b8:      	add	x16, x16, #0x8c8
 10713bc:      	br	x17

00000000010713c0 <vldp_get_point2f_array_pointer_ref@plt>:
 10713c0:      	adrp	x16, 0x10cf000
 10713c4:      	ldr	x17, [x16, #0x8d0]
 10713c8:      	add	x16, x16, #0x8d0
 10713cc:      	br	x17

00000000010713d0 <vldp_get_point2f_array_pointer_size@plt>:
 10713d0:      	adrp	x16, 0x10cf000
 10713d4:      	ldr	x17, [x16, #0x8d8]
 10713d8:      	add	x16, x16, #0x8d8
 10713dc:      	br	x17

00000000010713e0 <vldp_get_animal_score@plt>:
 10713e0:      	adrp	x16, 0x10cf000
 10713e4:      	ldr	x17, [x16, #0x8e0]
 10713e8:      	add	x16, x16, #0x8e0
 10713ec:      	br	x17

00000000010713f0 <vldp_get_animal_label@plt>:
 10713f0:      	adrp	x16, 0x10cf000
 10713f4:      	ldr	x17, [x16, #0x8e8]
 10713f8:      	add	x16, x16, #0x8e8
 10713fc:      	br	x17

0000000001071400 <vldp_get_data_protocol_ar_device_data@plt>:
 1071400:      	adrp	x16, 0x10cf000
 1071404:      	ldr	x17, [x16, #0x8f0]
 1071408:      	add	x16, x16, #0x8f0
 107140c:      	br	x17

0000000001071410 <vldp_get_ardevice_data_pointer_ref@plt>:
 1071410:      	adrp	x16, 0x10cf000
 1071414:      	ldr	x17, [x16, #0x8f8]
 1071418:      	add	x16, x16, #0x8f8
 107141c:      	br	x17

0000000001071420 <vldp_get_ardevice_data_data_source_type@plt>:
 1071420:      	adrp	x16, 0x10cf000
 1071424:      	ldr	x17, [x16, #0x900]
 1071428:      	add	x16, x16, #0x900
 107142c:      	br	x17

0000000001071430 <vldp_get_ardevice_data_augmented_reality_projection_matrix@plt>:
 1071430:      	adrp	x16, 0x10cf000
 1071434:      	ldr	x17, [x16, #0x908]
 1071438:      	add	x16, x16, #0x908
 107143c:      	br	x17

0000000001071440 <vldp_get_ardevice_data_augmented_reality_view_matrix@plt>:
 1071440:      	adrp	x16, 0x10cf000
 1071444:      	ldr	x17, [x16, #0x910]
 1071448:      	add	x16, x16, #0x910
 107144c:      	br	x17

0000000001071450 <vldp_get_body_slim3d_has_intrinsic_matrix@plt>:
 1071450:      	adrp	x16, 0x10cf000
 1071454:      	ldr	x17, [x16, #0x918]
 1071458:      	add	x16, x16, #0x918
 107145c:      	br	x17

0000000001071460 <vldp_get_body_slim3d_intrinsic_matrix@plt>:
 1071460:      	adrp	x16, 0x10cf000
 1071464:      	ldr	x17, [x16, #0x920]
 1071468:      	add	x16, x16, #0x920
 107146c:      	br	x17

0000000001071470 <vldp_get_body_slim3d_has_transform_matrix@plt>:
 1071470:      	adrp	x16, 0x10cf000
 1071474:      	ldr	x17, [x16, #0x928]
 1071478:      	add	x16, x16, #0x928
 107147c:      	br	x17

0000000001071480 <vldp_get_body_slim3d_transform_matrix@plt>:
 1071480:      	adrp	x16, 0x10cf000
 1071484:      	ldr	x17, [x16, #0x930]
 1071488:      	add	x16, x16, #0x930
 107148c:      	br	x17

0000000001071490 <vldp_get_body_slim3d_position@plt>:
 1071490:      	adrp	x16, 0x10cf000
 1071494:      	ldr	x17, [x16, #0x938]
 1071498:      	add	x16, x16, #0x938
 107149c:      	br	x17

00000000010714a0 <vldp_get_point3f_array_pointer_ref@plt>:
 10714a0:      	adrp	x16, 0x10cf000
 10714a4:      	ldr	x17, [x16, #0x940]
 10714a8:      	add	x16, x16, #0x940
 10714ac:      	br	x17

00000000010714b0 <vldp_get_point3f_array_pointer_size@plt>:
 10714b0:      	adrp	x16, 0x10cf000
 10714b4:      	ldr	x17, [x16, #0x948]
 10714b8:      	add	x16, x16, #0x948
 10714bc:      	br	x17

00000000010714c0 <vldp_get_body_slim3d_direction@plt>:
 10714c0:      	adrp	x16, 0x10cf000
 10714c4:      	ldr	x17, [x16, #0x950]
 10714c8:      	add	x16, x16, #0x950
 10714cc:      	br	x17

00000000010714d0 <vldp_get_portrait_inpainting_result_inpainting_texture@plt>:
 10714d0:      	adrp	x16, 0x10cf000
 10714d4:      	ldr	x17, [x16, #0x958]
 10714d8:      	add	x16, x16, #0x958
 10714dc:      	br	x17

00000000010714e0 <vldp_get_portrait_inpainting_result_inpainting_image@plt>:
 10714e0:      	adrp	x16, 0x10cf000
 10714e4:      	ldr	x17, [x16, #0x960]
 10714e8:      	add	x16, x16, #0x960
 10714ec:      	br	x17

00000000010714f0 <vldp_texture_valid@plt>:
 10714f0:      	adrp	x16, 0x10cf000
 10714f4:      	ldr	x17, [x16, #0x968]
 10714f8:      	add	x16, x16, #0x968
 10714fc:      	br	x17

0000000001071500 <vldp_image_valid@plt>:
 1071500:      	adrp	x16, 0x10cf000
 1071504:      	ldr	x17, [x16, #0x970]
 1071508:      	add	x16, x16, #0x970
 107150c:      	br	x17

0000000001071510 <vldp_get_portrait_inpainting_result_inpainting_mask_texture@plt>:
 1071510:      	adrp	x16, 0x10cf000
 1071514:      	ldr	x17, [x16, #0x978]
 1071518:      	add	x16, x16, #0x978
 107151c:      	br	x17

0000000001071520 <vldp_get_portrait_inpainting_result_inpainting_mask@plt>:
 1071520:      	adrp	x16, 0x10cf000
 1071524:      	ldr	x17, [x16, #0x980]
 1071528:      	add	x16, x16, #0x980
 107152c:      	br	x17

0000000001071530 <vldp_get_body_result_contour_bodys@plt>:
 1071530:      	adrp	x16, 0x10cf000
 1071534:      	ldr	x17, [x16, #0x988]
 1071538:      	add	x16, x16, #0x988
 107153c:      	br	x17

0000000001071540 <vldp_get_body_array_pointer_size@plt>:
 1071540:      	adrp	x16, 0x10cf000
 1071544:      	ldr	x17, [x16, #0x990]
 1071548:      	add	x16, x16, #0x990
 107154c:      	br	x17

0000000001071550 <vldp_get_body_result_pose_bodys@plt>:
 1071550:      	adrp	x16, 0x10cf000
 1071554:      	ldr	x17, [x16, #0x998]
 1071558:      	add	x16, x16, #0x998
 107155c:      	br	x17

0000000001071560 <vldp_get_body_result_human_bodys@plt>:
 1071560:      	adrp	x16, 0x10cf000
 1071564:      	ldr	x17, [x16, #0x9a0]
 1071568:      	add	x16, x16, #0x9a0
 107156c:      	br	x17

0000000001071570 <vldp_get_body_array_pointer_at@plt>:
 1071570:      	adrp	x16, 0x10cf000
 1071574:      	ldr	x17, [x16, #0x9a8]
 1071578:      	add	x16, x16, #0x9a8
 107157c:      	br	x17

0000000001071580 <vldp_get_body_body_rect_score@plt>:
 1071580:      	adrp	x16, 0x10cf000
 1071584:      	ldr	x17, [x16, #0x9b0]
 1071588:      	add	x16, x16, #0x9b0
 107158c:      	br	x17

0000000001071590 <vldp_get_body_body_rect@plt>:
 1071590:      	adrp	x16, 0x10cf000
 1071594:      	ldr	x17, [x16, #0x9b8]
 1071598:      	add	x16, x16, #0x9b8
 107159c:      	br	x17

00000000010715a0 <vldp_get_body_body_points@plt>:
 10715a0:      	adrp	x16, 0x10cf000
 10715a4:      	ldr	x17, [x16, #0x9c0]
 10715a8:      	add	x16, x16, #0x9c0
 10715ac:      	br	x17

00000000010715b0 <vldp_get_body_body_scores@plt>:
 10715b0:      	adrp	x16, 0x10cf000
 10715b4:      	ldr	x17, [x16, #0x9c8]
 10715b8:      	add	x16, x16, #0x9c8
 10715bc:      	br	x17

00000000010715c0 <vldp_get_float_array_pointer_ref@plt>:
 10715c0:      	adrp	x16, 0x10cf000
 10715c4:      	ldr	x17, [x16, #0x9d0]
 10715c8:      	add	x16, x16, #0x9d0
 10715cc:      	br	x17

00000000010715d0 <vldp_get_data_protocol_body_slim3d_result@plt>:
 10715d0:      	adrp	x16, 0x10cf000
 10715d4:      	ldr	x17, [x16, #0x9d8]
 10715d8:      	add	x16, x16, #0x9d8
 10715dc:      	br	x17

00000000010715e0 <vldp_get_body_slim3d_result_pointer_ref@plt>:
 10715e0:      	adrp	x16, 0x10cf000
 10715e4:      	ldr	x17, [x16, #0x9e0]
 10715e8:      	add	x16, x16, #0x9e0
 10715ec:      	br	x17

00000000010715f0 <vldp_get_body_slim3d_result_has_size@plt>:
 10715f0:      	adrp	x16, 0x10cf000
 10715f4:      	ldr	x17, [x16, #0x9e8]
 10715f8:      	add	x16, x16, #0x9e8
 10715fc:      	br	x17

0000000001071600 <vldp_get_body_slim3d_result_size@plt>:
 1071600:      	adrp	x16, 0x10cf000
 1071604:      	ldr	x17, [x16, #0x9f0]
 1071608:      	add	x16, x16, #0x9f0
 107160c:      	br	x17

0000000001071610 <vldp_get_body_slim3d_result_abundant_buttocks@plt>:
 1071610:      	adrp	x16, 0x10cf000
 1071614:      	ldr	x17, [x16, #0x9f8]
 1071618:      	add	x16, x16, #0x9f8
 107161c:      	br	x17

0000000001071620 <vldp_get_body_slim3d_array_pointer_size@plt>:
 1071620:      	adrp	x16, 0x10cf000
 1071624:      	ldr	x17, [x16, #0xa00]
 1071628:      	add	x16, x16, #0xa00
 107162c:      	br	x17

0000000001071630 <vldp_get_body_slim3d_result_thin_lower_abdomens@plt>:
 1071630:      	adrp	x16, 0x10cf000
 1071634:      	ldr	x17, [x16, #0xa08]
 1071638:      	add	x16, x16, #0xa08
 107163c:      	br	x17

0000000001071640 <vldp_get_body_slim3d_result_shoulder_brace@plt>:
 1071640:      	adrp	x16, 0x10cf000
 1071644:      	ldr	x17, [x16, #0xa10]
 1071648:      	add	x16, x16, #0xa10
 107164c:      	br	x17

0000000001071650 <vldp_get_body_slim3d_result_lift_breast@plt>:
 1071650:      	adrp	x16, 0x10cf000
 1071654:      	ldr	x17, [x16, #0xa18]
 1071658:      	add	x16, x16, #0xa18
 107165c:      	br	x17

0000000001071660 <vldp_get_body_slim3d_result_butt_lift@plt>:
 1071660:      	adrp	x16, 0x10cf000
 1071664:      	ldr	x17, [x16, #0xa20]
 1071668:      	add	x16, x16, #0xa20
 107166c:      	br	x17

0000000001071670 <vldp_get_body_slim3d_result_abundant_breast@plt>:
 1071670:      	adrp	x16, 0x10cf000
 1071674:      	ldr	x17, [x16, #0xa28]
 1071678:      	add	x16, x16, #0xa28
 107167c:      	br	x17

0000000001071680 <vldp_get_body_slim3d_result_reduction_breast@plt>:
 1071680:      	adrp	x16, 0x10cf000
 1071684:      	ldr	x17, [x16, #0xa30]
 1071688:      	add	x16, x16, #0xa30
 107168c:      	br	x17

0000000001071690 <vldp_get_body_slim3d_result_trapezius@plt>:
 1071690:      	adrp	x16, 0x10cf000
 1071694:      	ldr	x17, [x16, #0xa38]
 1071698:      	add	x16, x16, #0xa38
 107169c:      	br	x17

00000000010716a0 <vldp_get_body_slim3d_array_pointer_at@plt>:
 10716a0:      	adrp	x16, 0x10cf000
 10716a4:      	ldr	x17, [x16, #0xa40]
 10716a8:      	add	x16, x16, #0xa40
 10716ac:      	br	x17

00000000010716b0 <vldp_get_body_in_one_result_body@plt>:
 10716b0:      	adrp	x16, 0x10cf000
 10716b4:      	ldr	x17, [x16, #0xa48]
 10716b8:      	add	x16, x16, #0xa48
 10716bc:      	br	x17

00000000010716c0 <vldp_get_body_in_one_array_pointer_size@plt>:
 10716c0:      	adrp	x16, 0x10cf000
 10716c4:      	ldr	x17, [x16, #0xa50]
 10716c8:      	add	x16, x16, #0xa50
 10716cc:      	br	x17

00000000010716d0 <vldp_get_body_in_one_array_pointer_at@plt>:
 10716d0:      	adrp	x16, 0x10cf000
 10716d4:      	ldr	x17, [x16, #0xa58]
 10716d8:      	add	x16, x16, #0xa58
 10716dc:      	br	x17

00000000010716e0 <vldp_get_body_in_one_body_rect_score@plt>:
 10716e0:      	adrp	x16, 0x10cf000
 10716e4:      	ldr	x17, [x16, #0xa60]
 10716e8:      	add	x16, x16, #0xa60
 10716ec:      	br	x17

00000000010716f0 <vldp_get_body_in_one_body_rect@plt>:
 10716f0:      	adrp	x16, 0x10cf000
 10716f4:      	ldr	x17, [x16, #0xa68]
 10716f8:      	add	x16, x16, #0xa68
 10716fc:      	br	x17

0000000001071700 <vldp_get_body_in_one_pose@plt>:
 1071700:      	adrp	x16, 0x10cf000
 1071704:      	ldr	x17, [x16, #0xa70]
 1071708:      	add	x16, x16, #0xa70
 107170c:      	br	x17

0000000001071710 <vldp_get_body_point_array_pointer_size@plt>:
 1071710:      	adrp	x16, 0x10cf000
 1071714:      	ldr	x17, [x16, #0xa78]
 1071718:      	add	x16, x16, #0xa78
 107171c:      	br	x17

0000000001071720 <vldp_get_body_point_array_pointer_at@plt>:
 1071720:      	adrp	x16, 0x10cf000
 1071724:      	ldr	x17, [x16, #0xa80]
 1071728:      	add	x16, x16, #0xa80
 107172c:      	br	x17

0000000001071730 <vldp_get_body_point_point@plt>:
 1071730:      	adrp	x16, 0x10cf000
 1071734:      	ldr	x17, [x16, #0xa88]
 1071738:      	add	x16, x16, #0xa88
 107173c:      	br	x17

0000000001071740 <vldp_get_body_point_score@plt>:
 1071740:      	adrp	x16, 0x10cf000
 1071744:      	ldr	x17, [x16, #0xa90]
 1071748:      	add	x16, x16, #0xa90
 107174c:      	br	x17

0000000001071750 <vldp_get_body_point_visible@plt>:
 1071750:      	adrp	x16, 0x10cf000
 1071754:      	ldr	x17, [x16, #0xa98]
 1071758:      	add	x16, x16, #0xa98
 107175c:      	br	x17

0000000001071760 <vldp_get_body_in_one_contour@plt>:
 1071760:      	adrp	x16, 0x10cf000
 1071764:      	ldr	x17, [x16, #0xaa0]
 1071768:      	add	x16, x16, #0xaa0
 107176c:      	br	x17

0000000001071770 <vldp_get_body_in_one_neck@plt>:
 1071770:      	adrp	x16, 0x10cf000
 1071774:      	ldr	x17, [x16, #0xaa8]
 1071778:      	add	x16, x16, #0xaa8
 107177c:      	br	x17

0000000001071780 <vldp_get_body_in_one_breast@plt>:
 1071780:      	adrp	x16, 0x10cf000
 1071784:      	ldr	x17, [x16, #0xab0]
 1071788:      	add	x16, x16, #0xab0
 107178c:      	br	x17

0000000001071790 <vldp_get_body_in_one_shoulder@plt>:
 1071790:      	adrp	x16, 0x10cf000
 1071794:      	ldr	x17, [x16, #0xab8]
 1071798:      	add	x16, x16, #0xab8
 107179c:      	br	x17

00000000010717a0 <vldp_get_body_in_one_has_shoulder_rect@plt>:
 10717a0:      	adrp	x16, 0x10cf000
 10717a4:      	ldr	x17, [x16, #0xac0]
 10717a8:      	add	x16, x16, #0xac0
 10717ac:      	br	x17

00000000010717b0 <vldp_get_body_in_one_shoulder_rect@plt>:
 10717b0:      	adrp	x16, 0x10cf000
 10717b4:      	ldr	x17, [x16, #0xac8]
 10717b8:      	add	x16, x16, #0xac8
 10717bc:      	br	x17

00000000010717c0 <vldp_get_body_in_one_has_shoulder_rect_score@plt>:
 10717c0:      	adrp	x16, 0x10cf000
 10717c4:      	ldr	x17, [x16, #0xad0]
 10717c8:      	add	x16, x16, #0xad0
 10717cc:      	br	x17

00000000010717d0 <vldp_get_body_in_one_shoulder_rect_score@plt>:
 10717d0:      	adrp	x16, 0x10cf000
 10717d4:      	ldr	x17, [x16, #0xad8]
 10717d8:      	add	x16, x16, #0xad8
 10717dc:      	br	x17

00000000010717e0 <vldp_get_body_in_one_has_re_id@plt>:
 10717e0:      	adrp	x16, 0x10cf000
 10717e4:      	ldr	x17, [x16, #0xae0]
 10717e8:      	add	x16, x16, #0xae0
 10717ec:      	br	x17

00000000010717f0 <vldp_get_body_in_one_re_id@plt>:
 10717f0:      	adrp	x16, 0x10cf000
 10717f4:      	ldr	x17, [x16, #0xae8]
 10717f8:      	add	x16, x16, #0xae8
 10717fc:      	br	x17

0000000001071800 <vldp_get_body_in_one_has_name_id@plt>:
 1071800:      	adrp	x16, 0x10cf000
 1071804:      	ldr	x17, [x16, #0xaf0]
 1071808:      	add	x16, x16, #0xaf0
 107180c:      	br	x17

0000000001071810 <vldp_get_body_in_one_name_id@plt>:
 1071810:      	adrp	x16, 0x10cf000
 1071814:      	ldr	x17, [x16, #0xaf8]
 1071818:      	add	x16, x16, #0xaf8
 107181c:      	br	x17

0000000001071820 <vldp_get_body_in_one_has_face_id@plt>:
 1071820:      	adrp	x16, 0x10cf000
 1071824:      	ldr	x17, [x16, #0xb00]
 1071828:      	add	x16, x16, #0xb00
 107182c:      	br	x17

0000000001071830 <vldp_get_body_in_one_face_id@plt>:
 1071830:      	adrp	x16, 0x10cf000
 1071834:      	ldr	x17, [x16, #0xb08]
 1071838:      	add	x16, x16, #0xb08
 107183c:      	br	x17

0000000001071840 <vldp_get_data_protocol_portrait_inpainting_result@plt>:
 1071840:      	adrp	x16, 0x10cf000
 1071844:      	ldr	x17, [x16, #0xb10]
 1071848:      	add	x16, x16, #0xb10
 107184c:      	br	x17

0000000001071850 <vldp_get_portrait_inpainting_result_pointer_ref@plt>:
 1071850:      	adrp	x16, 0x10cf000
 1071854:      	ldr	x17, [x16, #0xb18]
 1071858:      	add	x16, x16, #0xb18
 107185c:      	br	x17

0000000001071860 <vldp_get_data_protocol_shoulder_result@plt>:
 1071860:      	adrp	x16, 0x10cf000
 1071864:      	ldr	x17, [x16, #0xb20]
 1071868:      	add	x16, x16, #0xb20
 107186c:      	br	x17

0000000001071870 <vldp_get_shoulder_result_pointer_ref@plt>:
 1071870:      	adrp	x16, 0x10cf000
 1071874:      	ldr	x17, [x16, #0xb28]
 1071878:      	add	x16, x16, #0xb28
 107187c:      	br	x17

0000000001071880 <vldp_get_shoulder_result_shoulders@plt>:
 1071880:      	adrp	x16, 0x10cf000
 1071884:      	ldr	x17, [x16, #0xb30]
 1071888:      	add	x16, x16, #0xb30
 107188c:      	br	x17

0000000001071890 <vldp_get_shoulder_array_pointer_size@plt>:
 1071890:      	adrp	x16, 0x10cf000
 1071894:      	ldr	x17, [x16, #0xb38]
 1071898:      	add	x16, x16, #0xb38
 107189c:      	br	x17

00000000010718a0 <vldp_get_shoulder_array_pointer_at@plt>:
 10718a0:      	adrp	x16, 0x10cf000
 10718a4:      	ldr	x17, [x16, #0xb40]
 10718a8:      	add	x16, x16, #0xb40
 10718ac:      	br	x17

00000000010718b0 <vldp_get_shoulder_has_shoulder_rect@plt>:
 10718b0:      	adrp	x16, 0x10cf000
 10718b4:      	ldr	x17, [x16, #0xb48]
 10718b8:      	add	x16, x16, #0xb48
 10718bc:      	br	x17

00000000010718c0 <vldp_get_shoulder_shoulder_rect@plt>:
 10718c0:      	adrp	x16, 0x10cf000
 10718c4:      	ldr	x17, [x16, #0xb50]
 10718c8:      	add	x16, x16, #0xb50
 10718cc:      	br	x17

00000000010718d0 <vldp_get_shoulder_has_rect_score@plt>:
 10718d0:      	adrp	x16, 0x10cf000
 10718d4:      	ldr	x17, [x16, #0xb58]
 10718d8:      	add	x16, x16, #0xb58
 10718dc:      	br	x17

00000000010718e0 <vldp_get_shoulder_rect_score@plt>:
 10718e0:      	adrp	x16, 0x10cf000
 10718e4:      	ldr	x17, [x16, #0xb60]
 10718e8:      	add	x16, x16, #0xb60
 10718ec:      	br	x17

00000000010718f0 <vldp_get_shoulder_shoulder_points@plt>:
 10718f0:      	adrp	x16, 0x10cf000
 10718f4:      	ldr	x17, [x16, #0xb68]
 10718f8:      	add	x16, x16, #0xb68
 10718fc:      	br	x17

0000000001071900 <vldp_get_shoulder_point_scores@plt>:
 1071900:      	adrp	x16, 0x10cf000
 1071904:      	ldr	x17, [x16, #0xb70]
 1071908:      	add	x16, x16, #0xb70
 107190c:      	br	x17

0000000001071910 <vldp_get_float_array_pointer_size@plt>:
 1071910:      	adrp	x16, 0x10cf000
 1071914:      	ldr	x17, [x16, #0xb78]
 1071918:      	add	x16, x16, #0xb78
 107191c:      	br	x17

0000000001071920 <vldp_get_uint16_array_pointer_ref@plt>:
 1071920:      	adrp	x16, 0x10cf000
 1071924:      	ldr	x17, [x16, #0xb80]
 1071928:      	add	x16, x16, #0xb80
 107192c:      	br	x17

0000000001071930 <vldp_get_uint16_array_pointer_size@plt>:
 1071930:      	adrp	x16, 0x10cf000
 1071934:      	ldr	x17, [x16, #0xb88]
 1071938:      	add	x16, x16, #0xb88
 107193c:      	br	x17

0000000001071940 <vldp_get_data_protocol_image_data@plt>:
 1071940:      	adrp	x16, 0x10cf000
 1071944:      	ldr	x17, [x16, #0xb90]
 1071948:      	add	x16, x16, #0xb90
 107194c:      	br	x17

0000000001071950 <vldp_get_data_protocol_face3d_result@plt>:
 1071950:      	adrp	x16, 0x10cf000
 1071954:      	ldr	x17, [x16, #0xb98]
 1071958:      	add	x16, x16, #0xb98
 107195c:      	br	x17

0000000001071960 <vldp_get_data_protocol_dl3d_result@plt>:
 1071960:      	adrp	x16, 0x10cf000
 1071964:      	ldr	x17, [x16, #0xba0]
 1071968:      	add	x16, x16, #0xba0
 107196c:      	br	x17

0000000001071970 <vldp_get_data_protocol_hand_result@plt>:
 1071970:      	adrp	x16, 0x10cf000
 1071974:      	ldr	x17, [x16, #0xba8]
 1071978:      	add	x16, x16, #0xba8
 107197c:      	br	x17

0000000001071980 <vldp_get_hand_result_pointer_ref@plt>:
 1071980:      	adrp	x16, 0x10cf000
 1071984:      	ldr	x17, [x16, #0xbb0]
 1071988:      	add	x16, x16, #0xbb0
 107198c:      	br	x17

0000000001071990 <vldp_get_image_data_pointer_ref@plt>:
 1071990:      	adrp	x16, 0x10cf000
 1071994:      	ldr	x17, [x16, #0xbb8]
 1071998:      	add	x16, x16, #0xbb8
 107199c:      	br	x17

00000000010719a0 <vldp_get_face3d_result_pointer_ref@plt>:
 10719a0:      	adrp	x16, 0x10cf000
 10719a4:      	ldr	x17, [x16, #0xbc0]
 10719a8:      	add	x16, x16, #0xbc0
 10719ac:      	br	x17

00000000010719b0 <vldp_get_dl3d_result_pointer_ref@plt>:
 10719b0:      	adrp	x16, 0x10cf000
 10719b4:      	ldr	x17, [x16, #0xbc8]
 10719b8:      	add	x16, x16, #0xbc8
 10719bc:      	br	x17

00000000010719c0 <vldp_get_face_array_pointer_at@plt>:
 10719c0:      	adrp	x16, 0x10cf000
 10719c4:      	ldr	x17, [x16, #0xbd0]
 10719c8:      	add	x16, x16, #0xbd0
 10719cc:      	br	x17

00000000010719d0 <vldp_get_face_id@plt>:
 10719d0:      	adrp	x16, 0x10cf000
 10719d4:      	ldr	x17, [x16, #0xbd8]
 10719d8:      	add	x16, x16, #0xbd8
 10719dc:      	br	x17

00000000010719e0 <vldp_get_face_face_points@plt>:
 10719e0:      	adrp	x16, 0x10cf000
 10719e4:      	ldr	x17, [x16, #0xbe0]
 10719e8:      	add	x16, x16, #0xbe0
 10719ec:      	br	x17

00000000010719f0 <vldp_get_face_visibility@plt>:
 10719f0:      	adrp	x16, 0x10cf000
 10719f4:      	ldr	x17, [x16, #0xbe8]
 10719f8:      	add	x16, x16, #0xbe8
 10719fc:      	br	x17

0000000001071a00 <vldp_get_face_head_points@plt>:
 1071a00:      	adrp	x16, 0x10cf000
 1071a04:      	ldr	x17, [x16, #0xbf0]
 1071a08:      	add	x16, x16, #0xbf0
 1071a0c:      	br	x17

0000000001071a10 <vldp_get_face_has_face_dl3d@plt>:
 1071a10:      	adrp	x16, 0x10cf000
 1071a14:      	ldr	x17, [x16, #0xbf8]
 1071a18:      	add	x16, x16, #0xbf8
 1071a1c:      	br	x17

0000000001071a20 <vldp_get_face_neck_points@plt>:
 1071a20:      	adrp	x16, 0x10cf000
 1071a24:      	ldr	x17, [x16, #0xc00]
 1071a28:      	add	x16, x16, #0xc00
 1071a2c:      	br	x17

0000000001071a30 <vldp_get_face_left_ear_points@plt>:
 1071a30:      	adrp	x16, 0x10cf000
 1071a34:      	ldr	x17, [x16, #0xc08]
 1071a38:      	add	x16, x16, #0xc08
 1071a3c:      	br	x17

0000000001071a40 <vldp_get_face_right_ear_points@plt>:
 1071a40:      	adrp	x16, 0x10cf000
 1071a44:      	ldr	x17, [x16, #0xc10]
 1071a48:      	add	x16, x16, #0xc10
 1071a4c:      	br	x17

0000000001071a50 <vldp_get_face_has_fr_id@plt>:
 1071a50:      	adrp	x16, 0x10cf000
 1071a54:      	ldr	x17, [x16, #0xc18]
 1071a58:      	add	x16, x16, #0xc18
 1071a5c:      	br	x17

0000000001071a60 <vldp_get_face_fr_id@plt>:
 1071a60:      	adrp	x16, 0x10cf000
 1071a64:      	ldr	x17, [x16, #0xc20]
 1071a68:      	add	x16, x16, #0xc20
 1071a6c:      	br	x17

0000000001071a70 <vldp_get_face_has_roll_angle@plt>:
 1071a70:      	adrp	x16, 0x10cf000
 1071a74:      	ldr	x17, [x16, #0xc28]
 1071a78:      	add	x16, x16, #0xc28
 1071a7c:      	br	x17

0000000001071a80 <vldp_get_face_has_yaw_angle@plt>:
 1071a80:      	adrp	x16, 0x10cf000
 1071a84:      	ldr	x17, [x16, #0xc30]
 1071a88:      	add	x16, x16, #0xc30
 1071a8c:      	br	x17

0000000001071a90 <vldp_get_face_has_pitch_angle@plt>:
 1071a90:      	adrp	x16, 0x10cf000
 1071a94:      	ldr	x17, [x16, #0xc38]
 1071a98:      	add	x16, x16, #0xc38
 1071a9c:      	br	x17

0000000001071aa0 <vldp_get_face_has_translate_x@plt>:
 1071aa0:      	adrp	x16, 0x10cf000
 1071aa4:      	ldr	x17, [x16, #0xc40]
 1071aa8:      	add	x16, x16, #0xc40
 1071aac:      	br	x17

0000000001071ab0 <vldp_get_face_has_translate_y@plt>:
 1071ab0:      	adrp	x16, 0x10cf000
 1071ab4:      	ldr	x17, [x16, #0xc48]
 1071ab8:      	add	x16, x16, #0xc48
 1071abc:      	br	x17

0000000001071ac0 <vldp_get_face_has_translate_z@plt>:
 1071ac0:      	adrp	x16, 0x10cf000
 1071ac4:      	ldr	x17, [x16, #0xc50]
 1071ac8:      	add	x16, x16, #0xc50
 1071acc:      	br	x17

0000000001071ad0 <vldp_get_face_roll_angle@plt>:
 1071ad0:      	adrp	x16, 0x10cf000
 1071ad4:      	ldr	x17, [x16, #0xc58]
 1071ad8:      	add	x16, x16, #0xc58
 1071adc:      	br	x17

0000000001071ae0 <vldp_get_face_yaw_angle@plt>:
 1071ae0:      	adrp	x16, 0x10cf000
 1071ae4:      	ldr	x17, [x16, #0xc60]
 1071ae8:      	add	x16, x16, #0xc60
 1071aec:      	br	x17

0000000001071af0 <vldp_get_face_pitch_angle@plt>:
 1071af0:      	adrp	x16, 0x10cf000
 1071af4:      	ldr	x17, [x16, #0xc68]
 1071af8:      	add	x16, x16, #0xc68
 1071afc:      	br	x17

0000000001071b00 <vldp_get_face_translate_x@plt>:
 1071b00:      	adrp	x16, 0x10cf000
 1071b04:      	ldr	x17, [x16, #0xc70]
 1071b08:      	add	x16, x16, #0xc70
 1071b0c:      	br	x17

0000000001071b10 <vldp_get_face_translate_y@plt>:
 1071b10:      	adrp	x16, 0x10cf000
 1071b14:      	ldr	x17, [x16, #0xc78]
 1071b18:      	add	x16, x16, #0xc78
 1071b1c:      	br	x17

0000000001071b20 <vldp_get_face_translate_z@plt>:
 1071b20:      	adrp	x16, 0x10cf000
 1071b24:      	ldr	x17, [x16, #0xc80]
 1071b28:      	add	x16, x16, #0xc80
 1071b2c:      	br	x17

0000000001071b30 <vldp_get_face_face_dl3d@plt>:
 1071b30:      	adrp	x16, 0x10cf000
 1071b34:      	ldr	x17, [x16, #0xc88]
 1071b38:      	add	x16, x16, #0xc88
 1071b3c:      	br	x17

0000000001071b40 <vldp_get_dl3d_face_has_euler@plt>:
 1071b40:      	adrp	x16, 0x10cf000
 1071b44:      	ldr	x17, [x16, #0xc90]
 1071b48:      	add	x16, x16, #0xc90
 1071b4c:      	br	x17

0000000001071b50 <vldp_get_dl3d_face_has_translation@plt>:
 1071b50:      	adrp	x16, 0x10cf000
 1071b54:      	ldr	x17, [x16, #0xc98]
 1071b58:      	add	x16, x16, #0xc98
 1071b5c:      	br	x17

0000000001071b60 <vldp_get_dl3d_face_has_scale@plt>:
 1071b60:      	adrp	x16, 0x10cf000
 1071b64:      	ldr	x17, [x16, #0xca0]
 1071b68:      	add	x16, x16, #0xca0
 1071b6c:      	br	x17

0000000001071b70 <vldp_get_dl3d_face_translation@plt>:
 1071b70:      	adrp	x16, 0x10cf000
 1071b74:      	ldr	x17, [x16, #0xca8]
 1071b78:      	add	x16, x16, #0xca8
 1071b7c:      	br	x17

0000000001071b80 <vldp_get_dl3d_face_euler@plt>:
 1071b80:      	adrp	x16, 0x10cf000
 1071b84:      	ldr	x17, [x16, #0xcb0]
 1071b88:      	add	x16, x16, #0xcb0
 1071b8c:      	br	x17

0000000001071b90 <vldp_get_dl3d_face_scale@plt>:
 1071b90:      	adrp	x16, 0x10cf000
 1071b94:      	ldr	x17, [x16, #0xcb8]
 1071b98:      	add	x16, x16, #0xcb8
 1071b9c:      	br	x17

0000000001071ba0 <vldp_get_dl3d_face_has_mvp_matrix@plt>:
 1071ba0:      	adrp	x16, 0x10cf000
 1071ba4:      	ldr	x17, [x16, #0xcc0]
 1071ba8:      	add	x16, x16, #0xcc0
 1071bac:      	br	x17

0000000001071bb0 <vldp_get_dl3d_face_has_model_matrix@plt>:
 1071bb0:      	adrp	x16, 0x10cf000
 1071bb4:      	ldr	x17, [x16, #0xcc8]
 1071bb8:      	add	x16, x16, #0xcc8
 1071bbc:      	br	x17

0000000001071bc0 <vldp_get_dl3d_face_has_view_matrix@plt>:
 1071bc0:      	adrp	x16, 0x10cf000
 1071bc4:      	ldr	x17, [x16, #0xcd0]
 1071bc8:      	add	x16, x16, #0xcd0
 1071bcc:      	br	x17

0000000001071bd0 <vldp_get_dl3d_face_has_projection_matrix@plt>:
 1071bd0:      	adrp	x16, 0x10cf000
 1071bd4:      	ldr	x17, [x16, #0xcd8]
 1071bd8:      	add	x16, x16, #0xcd8
 1071bdc:      	br	x17

0000000001071be0 <vldp_get_dl3d_face_model_matrix@plt>:
 1071be0:      	adrp	x16, 0x10cf000
 1071be4:      	ldr	x17, [x16, #0xce0]
 1071be8:      	add	x16, x16, #0xce0
 1071bec:      	br	x17

0000000001071bf0 <vldp_get_dl3d_face_view_matrix@plt>:
 1071bf0:      	adrp	x16, 0x10cf000
 1071bf4:      	ldr	x17, [x16, #0xce8]
 1071bf8:      	add	x16, x16, #0xce8
 1071bfc:      	br	x17

0000000001071c00 <vldp_get_dl3d_face_projection_matrix@plt>:
 1071c00:      	adrp	x16, 0x10cf000
 1071c04:      	ldr	x17, [x16, #0xcf0]
 1071c08:      	add	x16, x16, #0xcf0
 1071c0c:      	br	x17

0000000001071c10 <vldp_get_dl3d_face_vertex@plt>:
 1071c10:      	adrp	x16, 0x10cf000
 1071c14:      	ldr	x17, [x16, #0xcf8]
 1071c18:      	add	x16, x16, #0xcf8
 1071c1c:      	br	x17

0000000001071c20 <vldp_get_dl3d_face_vertices_normal@plt>:
 1071c20:      	adrp	x16, 0x10cf000
 1071c24:      	ldr	x17, [x16, #0xd00]
 1071c28:      	add	x16, x16, #0xd00
 1071c2c:      	br	x17

0000000001071c30 <vldp_get_dl3d_face_tangent@plt>:
 1071c30:      	adrp	x16, 0x10cf000
 1071c34:      	ldr	x17, [x16, #0xd08]
 1071c38:      	add	x16, x16, #0xd08
 1071c3c:      	br	x17

0000000001071c40 <vldp_get_dl3d_face_binormal@plt>:
 1071c40:      	adrp	x16, 0x10cf000
 1071c44:      	ldr	x17, [x16, #0xd10]
 1071c48:      	add	x16, x16, #0xd10
 1071c4c:      	br	x17

0000000001071c50 <vldp_get_face_result_texture_coordinates@plt>:
 1071c50:      	adrp	x16, 0x10cf000
 1071c54:      	ldr	x17, [x16, #0xd18]
 1071c58:      	add	x16, x16, #0xd18
 1071c5c:      	br	x17

0000000001071c60 <vldp_get_face_result_triangle_indexs@plt>:
 1071c60:      	adrp	x16, 0x10cf000
 1071c64:      	ldr	x17, [x16, #0xd20]
 1071c68:      	add	x16, x16, #0xd20
 1071c6c:      	br	x17

0000000001071c70 <vldp_get_face_has_gender@plt>:
 1071c70:      	adrp	x16, 0x10cf000
 1071c74:      	ldr	x17, [x16, #0xd28]
 1071c78:      	add	x16, x16, #0xd28
 1071c7c:      	br	x17

0000000001071c80 <vldp_get_face_gender@plt>:
 1071c80:      	adrp	x16, 0x10cf000
 1071c84:      	ldr	x17, [x16, #0xd30]
 1071c88:      	add	x16, x16, #0xd30
 1071c8c:      	br	x17

0000000001071c90 <vldp_get_face_has_age@plt>:
 1071c90:      	adrp	x16, 0x10cf000
 1071c94:      	ldr	x17, [x16, #0xd38]
 1071c98:      	add	x16, x16, #0xd38
 1071c9c:      	br	x17

0000000001071ca0 <vldp_get_face_age@plt>:
 1071ca0:      	adrp	x16, 0x10cf000
 1071ca4:      	ldr	x17, [x16, #0xd40]
 1071ca8:      	add	x16, x16, #0xd40
 1071cac:      	br	x17

0000000001071cb0 <vldp_get_face_has_eyelid@plt>:
 1071cb0:      	adrp	x16, 0x10cf000
 1071cb4:      	ldr	x17, [x16, #0xd48]
 1071cb8:      	add	x16, x16, #0xd48
 1071cbc:      	br	x17

0000000001071cc0 <vldp_get_face_eyelid@plt>:
 1071cc0:      	adrp	x16, 0x10cf000
 1071cc4:      	ldr	x17, [x16, #0xd50]
 1071cc8:      	add	x16, x16, #0xd50
 1071ccc:      	br	x17

0000000001071cd0 <vldp_get_face_eyelid_has_left@plt>:
 1071cd0:      	adrp	x16, 0x10cf000
 1071cd4:      	ldr	x17, [x16, #0xd58]
 1071cd8:      	add	x16, x16, #0xd58
 1071cdc:      	br	x17

0000000001071ce0 <vldp_get_face_eyelid_left@plt>:
 1071ce0:      	adrp	x16, 0x10cf000
 1071ce4:      	ldr	x17, [x16, #0xd60]
 1071ce8:      	add	x16, x16, #0xd60
 1071cec:      	br	x17

0000000001071cf0 <vldp_get_face_eyelid_has_right@plt>:
 1071cf0:      	adrp	x16, 0x10cf000
 1071cf4:      	ldr	x17, [x16, #0xd68]
 1071cf8:      	add	x16, x16, #0xd68
 1071cfc:      	br	x17

0000000001071d00 <vldp_get_face_eyelid_right@plt>:
 1071d00:      	adrp	x16, 0x10cf000
 1071d04:      	ldr	x17, [x16, #0xd70]
 1071d08:      	add	x16, x16, #0xd70
 1071d0c:      	br	x17

0000000001071d10 <vldp_get_face_lip_mask_image@plt>:
 1071d10:      	adrp	x16, 0x10cf000
 1071d14:      	ldr	x17, [x16, #0xd78]
 1071d18:      	add	x16, x16, #0xd78
 1071d1c:      	br	x17

0000000001071d20 <vldp_get_image_exif@plt>:
 1071d20:      	adrp	x16, 0x10cf000
 1071d24:      	ldr	x17, [x16, #0xd80]
 1071d28:      	add	x16, x16, #0xd80
 1071d2c:      	br	x17

0000000001071d30 <vldp_get_face_lip_matrix@plt>:
 1071d30:      	adrp	x16, 0x10cf000
 1071d34:      	ldr	x17, [x16, #0xd88]
 1071d38:      	add	x16, x16, #0xd88
 1071d3c:      	br	x17

0000000001071d40 <vldp_get_face_result_size@plt>:
 1071d40:      	adrp	x16, 0x10cf000
 1071d44:      	ldr	x17, [x16, #0xd90]
 1071d48:      	add	x16, x16, #0xd90
 1071d4c:      	br	x17

0000000001071d50 <vldp_get_face_face_parsing_mask_image@plt>:
 1071d50:      	adrp	x16, 0x10cf000
 1071d54:      	ldr	x17, [x16, #0xd98]
 1071d58:      	add	x16, x16, #0xd98
 1071d5c:      	br	x17

0000000001071d60 <vldp_get_face_face_parsing_matrix@plt>:
 1071d60:      	adrp	x16, 0x10cf000
 1071d64:      	ldr	x17, [x16, #0xda0]
 1071d68:      	add	x16, x16, #0xda0
 1071d6c:      	br	x17

0000000001071d70 <vldp_get_data_protocol_eye_segment_result@plt>:
 1071d70:      	adrp	x16, 0x10cf000
 1071d74:      	ldr	x17, [x16, #0xda8]
 1071d78:      	add	x16, x16, #0xda8
 1071d7c:      	br	x17

0000000001071d80 <vldp_get_eye_segment_result_pointer_ref@plt>:
 1071d80:      	adrp	x16, 0x10cf000
 1071d84:      	ldr	x17, [x16, #0xdb0]
 1071d88:      	add	x16, x16, #0xdb0
 1071d8c:      	br	x17

0000000001071d90 <vldp_get_eye_segment_result_eye_segments@plt>:
 1071d90:      	adrp	x16, 0x10cf000
 1071d94:      	ldr	x17, [x16, #0xdb8]
 1071d98:      	add	x16, x16, #0xdb8
 1071d9c:      	br	x17

0000000001071da0 <vldp_get_eye_segment_array_pointer_at@plt>:
 1071da0:      	adrp	x16, 0x10cf000
 1071da4:      	ldr	x17, [x16, #0xdc0]
 1071da8:      	add	x16, x16, #0xdc0
 1071dac:      	br	x17

0000000001071db0 <vldp_get_eye_segment_has_left_eye_rect@plt>:
 1071db0:      	adrp	x16, 0x10cf000
 1071db4:      	ldr	x17, [x16, #0xdc8]
 1071db8:      	add	x16, x16, #0xdc8
 1071dbc:      	br	x17

0000000001071dc0 <vldp_get_eye_segment_left_eye_rect@plt>:
 1071dc0:      	adrp	x16, 0x10cf000
 1071dc4:      	ldr	x17, [x16, #0xdd0]
 1071dc8:      	add	x16, x16, #0xdd0
 1071dcc:      	br	x17

0000000001071dd0 <vldp_get_eye_segment_left_eye_sclera_mask@plt>:
 1071dd0:      	adrp	x16, 0x10cf000
 1071dd4:      	ldr	x17, [x16, #0xdd8]
 1071dd8:      	add	x16, x16, #0xdd8
 1071ddc:      	br	x17

0000000001071de0 <vldp_get_eye_segment_left_eye_iris_mask@plt>:
 1071de0:      	adrp	x16, 0x10cf000
 1071de4:      	ldr	x17, [x16, #0xde0]
 1071de8:      	add	x16, x16, #0xde0
 1071dec:      	br	x17

0000000001071df0 <vldp_get_eye_segment_left_eye_pupil_mask@plt>:
 1071df0:      	adrp	x16, 0x10cf000
 1071df4:      	ldr	x17, [x16, #0xde8]
 1071df8:      	add	x16, x16, #0xde8
 1071dfc:      	br	x17

0000000001071e00 <vldp_get_eye_segment_has_right_eye_rect@plt>:
 1071e00:      	adrp	x16, 0x10cf000
 1071e04:      	ldr	x17, [x16, #0xdf0]
 1071e08:      	add	x16, x16, #0xdf0
 1071e0c:      	br	x17

0000000001071e10 <vldp_get_eye_segment_right_eye_rect@plt>:
 1071e10:      	adrp	x16, 0x10cf000
 1071e14:      	ldr	x17, [x16, #0xdf8]
 1071e18:      	add	x16, x16, #0xdf8
 1071e1c:      	br	x17

0000000001071e20 <vldp_get_eye_segment_right_eye_sclera_mask@plt>:
 1071e20:      	adrp	x16, 0x10cf000
 1071e24:      	ldr	x17, [x16, #0xe00]
 1071e28:      	add	x16, x16, #0xe00
 1071e2c:      	br	x17

0000000001071e30 <vldp_get_eye_segment_right_eye_iris_mask@plt>:
 1071e30:      	adrp	x16, 0x10cf000
 1071e34:      	ldr	x17, [x16, #0xe08]
 1071e38:      	add	x16, x16, #0xe08
 1071e3c:      	br	x17

0000000001071e40 <vldp_get_eye_segment_right_eye_pupil_mask@plt>:
 1071e40:      	adrp	x16, 0x10cf000
 1071e44:      	ldr	x17, [x16, #0xe10]
 1071e48:      	add	x16, x16, #0xe10
 1071e4c:      	br	x17

0000000001071e50 <_ZN5image9coverExifIhEENS_11DetailImageIT_EEOS3_NS_9ImageExifE@plt>:
 1071e50:      	adrp	x16, 0x10cf000
 1071e54:      	ldr	x17, [x16, #0xe18]
 1071e58:      	add	x16, x16, #0xe18
 1071e5c:      	br	x17

0000000001071e60 <_ZN5image10rotation90IhEENS_11DetailImageIT_EERKS3_@plt>:
 1071e60:      	adrp	x16, 0x10cf000
 1071e64:      	ldr	x17, [x16, #0xe20]
 1071e68:      	add	x16, x16, #0xe20
 1071e6c:      	br	x17

0000000001071e70 <_ZN5image11rotation270IhEENS_11DetailImageIT_EERKS3_@plt>:
 1071e70:      	adrp	x16, 0x10cf000
 1071e74:      	ldr	x17, [x16, #0xe28]
 1071e78:      	add	x16, x16, #0xe28
 1071e7c:      	br	x17

0000000001071e80 <_ZN5image14horizontalFlipIhEEvRNS_11DetailImageIT_EE@plt>:
 1071e80:      	adrp	x16, 0x10cf000
 1071e84:      	ldr	x17, [x16, #0xe30]
 1071e88:      	add	x16, x16, #0xe30
 1071e8c:      	br	x17

0000000001071e90 <_ZNK8mtlabar317FaceDataInterface21getFaceDataArrayConstEv@plt>:
 1071e90:      	adrp	x16, 0x10cf000
 1071e94:      	ldr	x17, [x16, #0xe38]
 1071e98:      	add	x16, x16, #0xe38
 1071e9c:      	br	x17

0000000001071ea0 <_ZNK8mtlabar38FaceData9getFaceIDEv@plt>:
 1071ea0:      	adrp	x16, 0x10cf000
 1071ea4:      	ldr	x17, [x16, #0xe40]
 1071ea8:      	add	x16, x16, #0xe40
 1071eac:      	br	x17

0000000001071eb0 <_ZNK8mtlabar38FaceData11getFaceRectEv@plt>:
 1071eb0:      	adrp	x16, 0x10cf000
 1071eb4:      	ldr	x17, [x16, #0xe48]
 1071eb8:      	add	x16, x16, #0xe48
 1071ebc:      	br	x17

0000000001071ec0 <_ZNK8mtlabar38FaceData19getFacialInterPointEv@plt>:
 1071ec0:      	adrp	x16, 0x10cf000
 1071ec4:      	ldr	x17, [x16, #0xe50]
 1071ec8:      	add	x16, x16, #0xe50
 1071ecc:      	br	x17

0000000001071ed0 <_ZNK8mtlabar38FaceData27getFacialInterPointNewModelEv@plt>:
 1071ed0:      	adrp	x16, 0x10cf000
 1071ed4:      	ldr	x17, [x16, #0xe58]
 1071ed8:      	add	x16, x16, #0xe58
 1071edc:      	br	x17

0000000001071ee0 <vldp_get_face2d_mesh_vertexs@plt>:
 1071ee0:      	adrp	x16, 0x10cf000
 1071ee4:      	ldr	x17, [x16, #0xe60]
 1071ee8:      	add	x16, x16, #0xe60
 1071eec:      	br	x17

0000000001071ef0 <vldp_get_face2d_mesh_texture_coordinates@plt>:
 1071ef0:      	adrp	x16, 0x10cf000
 1071ef4:      	ldr	x17, [x16, #0xe68]
 1071ef8:      	add	x16, x16, #0xe68
 1071efc:      	br	x17

0000000001071f00 <vldp_get_face3d_part2d_stand_vertexs@plt>:
 1071f00:      	adrp	x16, 0x10cf000
 1071f04:      	ldr	x17, [x16, #0xe70]
 1071f08:      	add	x16, x16, #0xe70
 1071f0c:      	br	x17

0000000001071f10 <vldp_get_face2d_mesh_triangle_indexs@plt>:
 1071f10:      	adrp	x16, 0x10cf000
 1071f14:      	ldr	x17, [x16, #0xe78]
 1071f18:      	add	x16, x16, #0xe78
 1071f1c:      	br	x17

0000000001071f20 <vldp_get_face3d_result_face2dv1s@plt>:
 1071f20:      	adrp	x16, 0x10cf000
 1071f24:      	ldr	x17, [x16, #0xe80]
 1071f28:      	add	x16, x16, #0xe80
 1071f2c:      	br	x17

0000000001071f30 <vldp_get_face3d_part2d_array_pointer_size@plt>:
 1071f30:      	adrp	x16, 0x10cf000
 1071f34:      	ldr	x17, [x16, #0xe88]
 1071f38:      	add	x16, x16, #0xe88
 1071f3c:      	br	x17

0000000001071f40 <vldp_get_face3d_part2d_array_pointer_at@plt>:
 1071f40:      	adrp	x16, 0x10cf000
 1071f44:      	ldr	x17, [x16, #0xe90]
 1071f48:      	add	x16, x16, #0xe90
 1071f4c:      	br	x17

0000000001071f50 <vldp_get_face3d_part2d_face_id@plt>:
 1071f50:      	adrp	x16, 0x10cf000
 1071f54:      	ldr	x17, [x16, #0xe98]
 1071f58:      	add	x16, x16, #0xe98
 1071f5c:      	br	x17

0000000001071f60 <vldp_get_face3d_part2d_has_face2d_mesh@plt>:
 1071f60:      	adrp	x16, 0x10cf000
 1071f64:      	ldr	x17, [x16, #0xea0]
 1071f68:      	add	x16, x16, #0xea0
 1071f6c:      	br	x17

0000000001071f70 <vldp_get_face3d_part2d_face2d_mesh@plt>:
 1071f70:      	adrp	x16, 0x10cf000
 1071f74:      	ldr	x17, [x16, #0xea8]
 1071f78:      	add	x16, x16, #0xea8
 1071f7c:      	br	x17

0000000001071f80 <vldp_get_face3d_result_face2dv2s@plt>:
 1071f80:      	adrp	x16, 0x10cf000
 1071f84:      	ldr	x17, [x16, #0xeb0]
 1071f88:      	add	x16, x16, #0xeb0
 1071f8c:      	br	x17

0000000001071f90 <vldp_get_face3d_result_face2dv3s@plt>:
 1071f90:      	adrp	x16, 0x10cf000
 1071f94:      	ldr	x17, [x16, #0xeb8]
 1071f98:      	add	x16, x16, #0xeb8
 1071f9c:      	br	x17

0000000001071fa0 <vldp_get_face3d_result_face2d_back_grounds@plt>:
 1071fa0:      	adrp	x16, 0x10cf000
 1071fa4:      	ldr	x17, [x16, #0xec0]
 1071fa8:      	add	x16, x16, #0xec0
 1071fac:      	br	x17

0000000001071fb0 <vldp_get_face3d_result_face3ds@plt>:
 1071fb0:      	adrp	x16, 0x10cf000
 1071fb4:      	ldr	x17, [x16, #0xec8]
 1071fb8:      	add	x16, x16, #0xec8
 1071fbc:      	br	x17

0000000001071fc0 <vldp_get_face3d_part3d_array_pointer_size@plt>:
 1071fc0:      	adrp	x16, 0x10cf000
 1071fc4:      	ldr	x17, [x16, #0xed0]
 1071fc8:      	add	x16, x16, #0xed0
 1071fcc:      	br	x17

0000000001071fd0 <vldp_get_face3d_part3d_array_pointer_at@plt>:
 1071fd0:      	adrp	x16, 0x10cf000
 1071fd4:      	ldr	x17, [x16, #0xed8]
 1071fd8:      	add	x16, x16, #0xed8
 1071fdc:      	br	x17

0000000001071fe0 <vldp_get_face3d_part3d_face_id@plt>:
 1071fe0:      	adrp	x16, 0x10cf000
 1071fe4:      	ldr	x17, [x16, #0xee0]
 1071fe8:      	add	x16, x16, #0xee0
 1071fec:      	br	x17

0000000001071ff0 <vldp_get_face3d_part3d_has_perspect_mvp_matrix@plt>:
 1071ff0:      	adrp	x16, 0x10cf000
 1071ff4:      	ldr	x17, [x16, #0xee8]
 1071ff8:      	add	x16, x16, #0xee8
 1071ffc:      	br	x17

0000000001072000 <vldp_get_face3d_part3d_perspect_mvp_matrix@plt>:
 1072000:      	adrp	x16, 0x10cf000
 1072004:      	ldr	x17, [x16, #0xef0]
 1072008:      	add	x16, x16, #0xef0
 107200c:      	br	x17

0000000001072010 <vldp_get_face3d_part3d_perspect_euler@plt>:
 1072010:      	adrp	x16, 0x10cf000
 1072014:      	ldr	x17, [x16, #0xef8]
 1072018:      	add	x16, x16, #0xef8
 107201c:      	br	x17

0000000001072020 <vldp_get_face3d_part3d_perspect_translate@plt>:
 1072020:      	adrp	x16, 0x10cf000
 1072024:      	ldr	x17, [x16, #0xf00]
 1072028:      	add	x16, x16, #0xf00
 107202c:      	br	x17

0000000001072030 <vldp_get_face3d_part3d_face3d_reconstruct_data@plt>:
 1072030:      	adrp	x16, 0x10cf000
 1072034:      	ldr	x17, [x16, #0xf08]
 1072038:      	add	x16, x16, #0xf08
 107203c:      	br	x17

0000000001072040 <vldp_get_face3d_reconstruct_data_posture@plt>:
 1072040:      	adrp	x16, 0x10cf000
 1072044:      	ldr	x17, [x16, #0xf10]
 1072048:      	add	x16, x16, #0xf10
 107204c:      	br	x17

0000000001072050 <vldp_get_face3d_posture_euler@plt>:
 1072050:      	adrp	x16, 0x10cf000
 1072054:      	ldr	x17, [x16, #0xf18]
 1072058:      	add	x16, x16, #0xf18
 107205c:      	br	x17

0000000001072060 <vldp_get_face3d_posture_translate@plt>:
 1072060:      	adrp	x16, 0x10cf000
 1072064:      	ldr	x17, [x16, #0xf20]
 1072068:      	add	x16, x16, #0xf20
 107206c:      	br	x17

0000000001072070 <vldp_get_face3d_posture_to_ndc_matrix@plt>:
 1072070:      	adrp	x16, 0x10cf000
 1072074:      	ldr	x17, [x16, #0xf28]
 1072078:      	add	x16, x16, #0xf28
 107207c:      	br	x17

0000000001072080 <vldp_get_face3d_reconstruct_data_mesh3d@plt>:
 1072080:      	adrp	x16, 0x10cf000
 1072084:      	ldr	x17, [x16, #0xf30]
 1072088:      	add	x16, x16, #0xf30
 107208c:      	br	x17

0000000001072090 <vldp_get_face3d_mesh_reconstruct_vertexs@plt>:
 1072090:      	adrp	x16, 0x10cf000
 1072094:      	ldr	x17, [x16, #0xf38]
 1072098:      	add	x16, x16, #0xf38
 107209c:      	br	x17

00000000010720a0 <vldp_get_face3d_mesh_texture_coordinates@plt>:
 10720a0:      	adrp	x16, 0x10cf000
 10720a4:      	ldr	x17, [x16, #0xf40]
 10720a8:      	add	x16, x16, #0xf40
 10720ac:      	br	x17

00000000010720b0 <vldp_get_face3d_mesh_texture_coordinates_v1@plt>:
 10720b0:      	adrp	x16, 0x10cf000
 10720b4:      	ldr	x17, [x16, #0xf48]
 10720b8:      	add	x16, x16, #0xf48
 10720bc:      	br	x17

00000000010720c0 <vldp_get_face3d_mesh_normals@plt>:
 10720c0:      	adrp	x16, 0x10cf000
 10720c4:      	ldr	x17, [x16, #0xf50]
 10720c8:      	add	x16, x16, #0xf50
 10720cc:      	br	x17

00000000010720d0 <vldp_get_face3d_mesh_triangle_indexs@plt>:
 10720d0:      	adrp	x16, 0x10cf000
 10720d4:      	ldr	x17, [x16, #0xf58]
 10720d8:      	add	x16, x16, #0xf58
 10720dc:      	br	x17

00000000010720e0 <vldp_get_face3d_mesh_indices_no_lips_count@plt>:
 10720e0:      	adrp	x16, 0x10cf000
 10720e4:      	ldr	x17, [x16, #0xf60]
 10720e8:      	add	x16, x16, #0xf60
 10720ec:      	br	x17

00000000010720f0 <vldp_get_dl3d_result_dl3ds@plt>:
 10720f0:      	adrp	x16, 0x10cf000
 10720f4:      	ldr	x17, [x16, #0xf68]
 10720f8:      	add	x16, x16, #0xf68
 10720fc:      	br	x17

0000000001072100 <vldp_get_dl3d_array_pointer_size@plt>:
 1072100:      	adrp	x16, 0x10cf000
 1072104:      	ldr	x17, [x16, #0xf70]
 1072108:      	add	x16, x16, #0xf70
 107210c:      	br	x17

0000000001072110 <vldp_get_dl3d_array_pointer_at@plt>:
 1072110:      	adrp	x16, 0x10cf000
 1072114:      	ldr	x17, [x16, #0xf78]
 1072118:      	add	x16, x16, #0xf78
 107211c:      	br	x17

0000000001072120 <vldp_get_dl3d_face_id@plt>:
 1072120:      	adrp	x16, 0x10cf000
 1072124:      	ldr	x17, [x16, #0xf80]
 1072128:      	add	x16, x16, #0xf80
 107212c:      	br	x17

0000000001072130 <vldp_get_dl3d_dl3d_net_result@plt>:
 1072130:      	adrp	x16, 0x10cf000
 1072134:      	ldr	x17, [x16, #0xf88]
 1072138:      	add	x16, x16, #0xf88
 107213c:      	br	x17

0000000001072140 <vldp_get_dl3d_net_euler@plt>:
 1072140:      	adrp	x16, 0x10cf000
 1072144:      	ldr	x17, [x16, #0xf90]
 1072148:      	add	x16, x16, #0xf90
 107214c:      	br	x17

0000000001072150 <vldp_get_dl3d_net_translation@plt>:
 1072150:      	adrp	x16, 0x10cf000
 1072154:      	ldr	x17, [x16, #0xf98]
 1072158:      	add	x16, x16, #0xf98
 107215c:      	br	x17

0000000001072160 <vldp_get_dl3d_net_gl_mvp_matrix@plt>:
 1072160:      	adrp	x16, 0x10cf000
 1072164:      	ldr	x17, [x16, #0xfa0]
 1072168:      	add	x16, x16, #0xfa0
 107216c:      	br	x17

0000000001072170 <vldp_get_dl3d_net_projection_matrix@plt>:
 1072170:      	adrp	x16, 0x10cf000
 1072174:      	ldr	x17, [x16, #0xfa8]
 1072178:      	add	x16, x16, #0xfa8
 107217c:      	br	x17

0000000001072180 <vldp_get_dl3d_dl3d_mesh_result@plt>:
 1072180:      	adrp	x16, 0x10cf000
 1072184:      	ldr	x17, [x16, #0xfb0]
 1072188:      	add	x16, x16, #0xfb0
 107218c:      	br	x17

0000000001072190 <vldp_get_dl3d_mesh_vertices@plt>:
 1072190:      	adrp	x16, 0x10cf000
 1072194:      	ldr	x17, [x16, #0xfb8]
 1072198:      	add	x16, x16, #0xfb8
 107219c:      	br	x17

00000000010721a0 <vldp_get_dl3d_mesh_texcoords@plt>:
 10721a0:      	adrp	x16, 0x10cf000
 10721a4:      	ldr	x17, [x16, #0xfc0]
 10721a8:      	add	x16, x16, #0xfc0
 10721ac:      	br	x17

00000000010721b0 <vldp_get_dl3d_mesh_normals@plt>:
 10721b0:      	adrp	x16, 0x10cf000
 10721b4:      	ldr	x17, [x16, #0xfc8]
 10721b8:      	add	x16, x16, #0xfc8
 10721bc:      	br	x17

00000000010721c0 <vldp_get_dl3d_mesh_triangles@plt>:
 10721c0:      	adrp	x16, 0x10cf000
 10721c4:      	ldr	x17, [x16, #0xfd0]
 10721c8:      	add	x16, x16, #0xfd0
 10721cc:      	br	x17

00000000010721d0 <vldp_get_data_protocol_food_result@plt>:
 10721d0:      	adrp	x16, 0x10cf000
 10721d4:      	ldr	x17, [x16, #0xfd8]
 10721d8:      	add	x16, x16, #0xfd8
 10721dc:      	br	x17

00000000010721e0 <vldp_get_food_result_pointer_ref@plt>:
 10721e0:      	adrp	x16, 0x10cf000
 10721e4:      	ldr	x17, [x16, #0xfe0]
 10721e8:      	add	x16, x16, #0xfe0
 10721ec:      	br	x17

00000000010721f0 <vldp_get_food_result_has_size@plt>:
 10721f0:      	adrp	x16, 0x10cf000
 10721f4:      	ldr	x17, [x16, #0xfe8]
 10721f8:      	add	x16, x16, #0xfe8
 10721fc:      	br	x17

0000000001072200 <vldp_get_food_result_size@plt>:
 1072200:      	adrp	x16, 0x10cf000
 1072204:      	ldr	x17, [x16, #0xff0]
 1072208:      	add	x16, x16, #0xff0
 107220c:      	br	x17

0000000001072210 <vldp_get_food_result_foods@plt>:
 1072210:      	adrp	x16, 0x10cf000
 1072214:      	ldr	x17, [x16, #0xff8]
 1072218:      	add	x16, x16, #0xff8
 107221c:      	br	x17

0000000001072220 <vldp_get_food_array_pointer_size@plt>:
 1072220:      	adrp	x16, 0x10d0000
 1072224:      	ldr	x17, [x16]
 1072228:      	add	x16, x16, #0x0
 107222c:      	br	x17

0000000001072230 <vldp_get_food_array_pointer_at@plt>:
 1072230:      	adrp	x16, 0x10d0000
 1072234:      	ldr	x17, [x16, #0x8]
 1072238:      	add	x16, x16, #0x8
 107223c:      	br	x17

0000000001072240 <vldp_get_food_has_foodtype@plt>:
 1072240:      	adrp	x16, 0x10d0000
 1072244:      	ldr	x17, [x16, #0x10]
 1072248:      	add	x16, x16, #0x10
 107224c:      	br	x17

0000000001072250 <vldp_get_food_foodtype@plt>:
 1072250:      	adrp	x16, 0x10d0000
 1072254:      	ldr	x17, [x16, #0x18]
 1072258:      	add	x16, x16, #0x18
 107225c:      	br	x17

0000000001072260 <vldp_get_food_has_score@plt>:
 1072260:      	adrp	x16, 0x10d0000
 1072264:      	ldr	x17, [x16, #0x20]
 1072268:      	add	x16, x16, #0x20
 107226c:      	br	x17

0000000001072270 <vldp_get_food_has_food_rect@plt>:
 1072270:      	adrp	x16, 0x10d0000
 1072274:      	ldr	x17, [x16, #0x28]
 1072278:      	add	x16, x16, #0x28
 107227c:      	br	x17

0000000001072280 <vldp_get_food_food_rect@plt>:
 1072280:      	adrp	x16, 0x10d0000
 1072284:      	ldr	x17, [x16, #0x30]
 1072288:      	add	x16, x16, #0x30
 107228c:      	br	x17

0000000001072290 <vldp_get_hand_result_hands@plt>:
 1072290:      	adrp	x16, 0x10d0000
 1072294:      	ldr	x17, [x16, #0x38]
 1072298:      	add	x16, x16, #0x38
 107229c:      	br	x17

00000000010722a0 <vldp_get_hand_array_pointer_size@plt>:
 10722a0:      	adrp	x16, 0x10d0000
 10722a4:      	ldr	x17, [x16, #0x40]
 10722a8:      	add	x16, x16, #0x40
 10722ac:      	br	x17

00000000010722b0 <vldp_get_hand_array_pointer_at@plt>:
 10722b0:      	adrp	x16, 0x10d0000
 10722b4:      	ldr	x17, [x16, #0x48]
 10722b8:      	add	x16, x16, #0x48
 10722bc:      	br	x17

00000000010722c0 <vldp_get_hand_score@plt>:
 10722c0:      	adrp	x16, 0x10d0000
 10722c4:      	ldr	x17, [x16, #0x50]
 10722c8:      	add	x16, x16, #0x50
 10722cc:      	br	x17

00000000010722d0 <vldp_get_hand_hand_points@plt>:
 10722d0:      	adrp	x16, 0x10d0000
 10722d4:      	ldr	x17, [x16, #0x58]
 10722d8:      	add	x16, x16, #0x58
 10722dc:      	br	x17

00000000010722e0 <vldp_get_hand_hand_pose_points@plt>:
 10722e0:      	adrp	x16, 0x10d0000
 10722e4:      	ldr	x17, [x16, #0x60]
 10722e8:      	add	x16, x16, #0x60
 10722ec:      	br	x17

00000000010722f0 <vldp_get_hand_has_gesture@plt>:
 10722f0:      	adrp	x16, 0x10d0000
 10722f4:      	ldr	x17, [x16, #0x68]
 10722f8:      	add	x16, x16, #0x68
 10722fc:      	br	x17

0000000001072300 <vldp_get_hand_gesture@plt>:
 1072300:      	adrp	x16, 0x10d0000
 1072304:      	ldr	x17, [x16, #0x70]
 1072308:      	add	x16, x16, #0x70
 107230c:      	br	x17

0000000001072310 <vldp_get_hand_result_nails@plt>:
 1072310:      	adrp	x16, 0x10d0000
 1072314:      	ldr	x17, [x16, #0x78]
 1072318:      	add	x16, x16, #0x78
 107231c:      	br	x17

0000000001072320 <vldp_get_nail_array_pointer_size@plt>:
 1072320:      	adrp	x16, 0x10d0000
 1072324:      	ldr	x17, [x16, #0x80]
 1072328:      	add	x16, x16, #0x80
 107232c:      	br	x17

0000000001072330 <vldp_get_nail_array_pointer_at@plt>:
 1072330:      	adrp	x16, 0x10d0000
 1072334:      	ldr	x17, [x16, #0x88]
 1072338:      	add	x16, x16, #0x88
 107233c:      	br	x17

0000000001072340 <vldp_get_nail_has_idx@plt>:
 1072340:      	adrp	x16, 0x10d0000
 1072344:      	ldr	x17, [x16, #0x90]
 1072348:      	add	x16, x16, #0x90
 107234c:      	br	x17

0000000001072350 <vldp_get_nail_idx@plt>:
 1072350:      	adrp	x16, 0x10d0000
 1072354:      	ldr	x17, [x16, #0x98]
 1072358:      	add	x16, x16, #0x98
 107235c:      	br	x17

0000000001072360 <vldp_get_nail_has_box_score@plt>:
 1072360:      	adrp	x16, 0x10d0000
 1072364:      	ldr	x17, [x16, #0xa0]
 1072368:      	add	x16, x16, #0xa0
 107236c:      	br	x17

0000000001072370 <vldp_get_nail_box_score@plt>:
 1072370:      	adrp	x16, 0x10d0000
 1072374:      	ldr	x17, [x16, #0xa8]
 1072378:      	add	x16, x16, #0xa8
 107237c:      	br	x17

0000000001072380 <vldp_get_nail_key_points@plt>:
 1072380:      	adrp	x16, 0x10d0000
 1072384:      	ldr	x17, [x16, #0xb0]
 1072388:      	add	x16, x16, #0xb0
 107238c:      	br	x17

0000000001072390 <vldp_get_data_protocol_device_hardware_data@plt>:
 1072390:      	adrp	x16, 0x10d0000
 1072394:      	ldr	x17, [x16, #0xb8]
 1072398:      	add	x16, x16, #0xb8
 107239c:      	br	x17

00000000010723a0 <vldp_get_device_hardware_data_pointer_ref@plt>:
 10723a0:      	adrp	x16, 0x10d0000
 10723a4:      	ldr	x17, [x16, #0xc0]
 10723a8:      	add	x16, x16, #0xc0
 10723ac:      	br	x17

00000000010723b0 <vldp_get_device_hardware_data_has_device_orientation_type@plt>:
 10723b0:      	adrp	x16, 0x10d0000
 10723b4:      	ldr	x17, [x16, #0xc8]
 10723b8:      	add	x16, x16, #0xc8
 10723bc:      	br	x17

00000000010723c0 <vldp_get_device_hardware_data_camera_mode@plt>:
 10723c0:      	adrp	x16, 0x10d0000
 10723c4:      	ldr	x17, [x16, #0xd0]
 10723c8:      	add	x16, x16, #0xd0
 10723cc:      	br	x17

00000000010723d0 <vldp_get_device_hardware_data_device_orientation_type@plt>:
 10723d0:      	adrp	x16, 0x10d0000
 10723d4:      	ldr	x17, [x16, #0xd8]
 10723d8:      	add	x16, x16, #0xd8
 10723dc:      	br	x17

00000000010723e0 <vldp_get_device_hardware_data_has_gyroscope_quaternion@plt>:
 10723e0:      	adrp	x16, 0x10d0000
 10723e4:      	ldr	x17, [x16, #0xe0]
 10723e8:      	add	x16, x16, #0xe0
 10723ec:      	br	x17

00000000010723f0 <vldp_get_device_hardware_data_gyroscope_quaternion@plt>:
 10723f0:      	adrp	x16, 0x10d0000
 10723f4:      	ldr	x17, [x16, #0xe8]
 10723f8:      	add	x16, x16, #0xe8
 10723fc:      	br	x17

0000000001072400 <vldp_get_data_protocol_human3d_result@plt>:
 1072400:      	adrp	x16, 0x10d0000
 1072404:      	ldr	x17, [x16, #0xf0]
 1072408:      	add	x16, x16, #0xf0
 107240c:      	br	x17

0000000001072410 <vldp_get_human3d_result_pointer_ref@plt>:
 1072410:      	adrp	x16, 0x10d0000
 1072414:      	ldr	x17, [x16, #0xf8]
 1072418:      	add	x16, x16, #0xf8
 107241c:      	br	x17

0000000001072420 <vldp_get_human3d_result_human3d_bodys@plt>:
 1072420:      	adrp	x16, 0x10d0000
 1072424:      	ldr	x17, [x16, #0x100]
 1072428:      	add	x16, x16, #0x100
 107242c:      	br	x17

0000000001072430 <vldp_get_human3d_body_array_pointer_size@plt>:
 1072430:      	adrp	x16, 0x10d0000
 1072434:      	ldr	x17, [x16, #0x108]
 1072438:      	add	x16, x16, #0x108
 107243c:      	br	x17

0000000001072440 <vldp_get_human3d_result_human3d_smpls@plt>:
 1072440:      	adrp	x16, 0x10d0000
 1072444:      	ldr	x17, [x16, #0x110]
 1072448:      	add	x16, x16, #0x110
 107244c:      	br	x17

0000000001072450 <vldp_get_human3d_smpl_array_pointer_size@plt>:
 1072450:      	adrp	x16, 0x10d0000
 1072454:      	ldr	x17, [x16, #0x118]
 1072458:      	add	x16, x16, #0x118
 107245c:      	br	x17

0000000001072460 <vldp_get_human3d_result_has_size@plt>:
 1072460:      	adrp	x16, 0x10d0000
 1072464:      	ldr	x17, [x16, #0x120]
 1072468:      	add	x16, x16, #0x120
 107246c:      	br	x17

0000000001072470 <vldp_get_human3d_result_size@plt>:
 1072470:      	adrp	x16, 0x10d0000
 1072474:      	ldr	x17, [x16, #0x128]
 1072478:      	add	x16, x16, #0x128
 107247c:      	br	x17

0000000001072480 <vldp_get_human3d_body_array_pointer_at@plt>:
 1072480:      	adrp	x16, 0x10d0000
 1072484:      	ldr	x17, [x16, #0x130]
 1072488:      	add	x16, x16, #0x130
 107248c:      	br	x17

0000000001072490 <vldp_get_human3d_body_has_human_id@plt>:
 1072490:      	adrp	x16, 0x10d0000
 1072494:      	ldr	x17, [x16, #0x138]
 1072498:      	add	x16, x16, #0x138
 107249c:      	br	x17

00000000010724a0 <vldp_get_human3d_body_human_id@plt>:
 10724a0:      	adrp	x16, 0x10d0000
 10724a4:      	ldr	x17, [x16, #0x140]
 10724a8:      	add	x16, x16, #0x140
 10724ac:      	br	x17

00000000010724b0 <vldp_get_human3d_body_has_transform@plt>:
 10724b0:      	adrp	x16, 0x10d0000
 10724b4:      	ldr	x17, [x16, #0x148]
 10724b8:      	add	x16, x16, #0x148
 10724bc:      	br	x17

00000000010724c0 <vldp_get_human3d_body_transform@plt>:
 10724c0:      	adrp	x16, 0x10d0000
 10724c4:      	ldr	x17, [x16, #0x150]
 10724c8:      	add	x16, x16, #0x150
 10724cc:      	br	x17

00000000010724d0 <vldp_get_human3d_body_has_intrinsic_matrix@plt>:
 10724d0:      	adrp	x16, 0x10d0000
 10724d4:      	ldr	x17, [x16, #0x158]
 10724d8:      	add	x16, x16, #0x158
 10724dc:      	br	x17

00000000010724e0 <vldp_get_human3d_body_intrinsic_matrix@plt>:
 10724e0:      	adrp	x16, 0x10d0000
 10724e4:      	ldr	x17, [x16, #0x160]
 10724e8:      	add	x16, x16, #0x160
 10724ec:      	br	x17

00000000010724f0 <vldp_get_human3d_body_has_joints@plt>:
 10724f0:      	adrp	x16, 0x10d0000
 10724f4:      	ldr	x17, [x16, #0x168]
 10724f8:      	add	x16, x16, #0x168
 10724fc:      	br	x17

0000000001072500 <vldp_get_human3d_body_joints@plt>:
 1072500:      	adrp	x16, 0x10d0000
 1072504:      	ldr	x17, [x16, #0x170]
 1072508:      	add	x16, x16, #0x170
 107250c:      	br	x17

0000000001072510 <vldp_get_human3d_smpl_array_pointer_at@plt>:
 1072510:      	adrp	x16, 0x10d0000
 1072514:      	ldr	x17, [x16, #0x178]
 1072518:      	add	x16, x16, #0x178
 107251c:      	br	x17

0000000001072520 <vldp_get_human3d_smpl_has_betas@plt>:
 1072520:      	adrp	x16, 0x10d0000
 1072524:      	ldr	x17, [x16, #0x180]
 1072528:      	add	x16, x16, #0x180
 107252c:      	br	x17

0000000001072530 <vldp_get_human3d_smpl_betas@plt>:
 1072530:      	adrp	x16, 0x10d0000
 1072534:      	ldr	x17, [x16, #0x188]
 1072538:      	add	x16, x16, #0x188
 107253c:      	br	x17

0000000001072540 <vldp_get_human3d_smpl_has_blend_thetas@plt>:
 1072540:      	adrp	x16, 0x10d0000
 1072544:      	ldr	x17, [x16, #0x190]
 1072548:      	add	x16, x16, #0x190
 107254c:      	br	x17

0000000001072550 <vldp_get_human3d_smpl_blend_thetas@plt>:
 1072550:      	adrp	x16, 0x10d0000
 1072554:      	ldr	x17, [x16, #0x198]
 1072558:      	add	x16, x16, #0x198
 107255c:      	br	x17

0000000001072560 <vldp_get_image_data_has_source_color_image@plt>:
 1072560:      	adrp	x16, 0x10d0000
 1072564:      	ldr	x17, [x16, #0x1a0]
 1072568:      	add	x16, x16, #0x1a0
 107256c:      	br	x17

0000000001072570 <vldp_get_image_data_source_color_image@plt>:
 1072570:      	adrp	x16, 0x10d0000
 1072574:      	ldr	x17, [x16, #0x1a8]
 1072578:      	add	x16, x16, #0x1a8
 107257c:      	br	x17

0000000001072580 <vldp_get_media_data_image@plt>:
 1072580:      	adrp	x16, 0x10d0000
 1072584:      	ldr	x17, [x16, #0x1b0]
 1072588:      	add	x16, x16, #0x1b0
 107258c:      	br	x17

0000000001072590 <vldp_get_image_width@plt>:
 1072590:      	adrp	x16, 0x10d0000
 1072594:      	ldr	x17, [x16, #0x1b8]
 1072598:      	add	x16, x16, #0x1b8
 107259c:      	br	x17

00000000010725a0 <vldp_get_image_height@plt>:
 10725a0:      	adrp	x16, 0x10d0000
 10725a4:      	ldr	x17, [x16, #0x1c0]
 10725a8:      	add	x16, x16, #0x1c0
 10725ac:      	br	x17

00000000010725b0 <vldp_get_image_stride@plt>:
 10725b0:      	adrp	x16, 0x10d0000
 10725b4:      	ldr	x17, [x16, #0x1c8]
 10725b8:      	add	x16, x16, #0x1c8
 10725bc:      	br	x17

00000000010725c0 <vldp_get_image_data@plt>:
 10725c0:      	adrp	x16, 0x10d0000
 10725c4:      	ldr	x17, [x16, #0x1d0]
 10725c8:      	add	x16, x16, #0x1d0
 10725cc:      	br	x17

00000000010725d0 <vldp_get_image_data_has_source_gray_image@plt>:
 10725d0:      	adrp	x16, 0x10d0000
 10725d4:      	ldr	x17, [x16, #0x1d8]
 10725d8:      	add	x16, x16, #0x1d8
 10725dc:      	br	x17

00000000010725e0 <vldp_get_image_data_source_gray_image@plt>:
 10725e0:      	adrp	x16, 0x10d0000
 10725e4:      	ldr	x17, [x16, #0x1e0]
 10725e8:      	add	x16, x16, #0x1e0
 10725ec:      	br	x17

00000000010725f0 <vldp_get_data_protocol_instance_segment_result@plt>:
 10725f0:      	adrp	x16, 0x10d0000
 10725f4:      	ldr	x17, [x16, #0x1e8]
 10725f8:      	add	x16, x16, #0x1e8
 10725fc:      	br	x17

0000000001072600 <vldp_get_instance_segment_result_pointer_ref@plt>:
 1072600:      	adrp	x16, 0x10d0000
 1072604:      	ldr	x17, [x16, #0x1f0]
 1072608:      	add	x16, x16, #0x1f0
 107260c:      	br	x17

0000000001072610 <vldp_get_instance_segment_result_has_size@plt>:
 1072610:      	adrp	x16, 0x10d0000
 1072614:      	ldr	x17, [x16, #0x1f8]
 1072618:      	add	x16, x16, #0x1f8
 107261c:      	br	x17

0000000001072620 <vldp_get_instance_segment_result_size@plt>:
 1072620:      	adrp	x16, 0x10d0000
 1072624:      	ldr	x17, [x16, #0x200]
 1072628:      	add	x16, x16, #0x200
 107262c:      	br	x17

0000000001072630 <vldp_get_instance_segment_result_has_merge_instance_segment@plt>:
 1072630:      	adrp	x16, 0x10d0000
 1072634:      	ldr	x17, [x16, #0x208]
 1072638:      	add	x16, x16, #0x208
 107263c:      	br	x17

0000000001072640 <vldp_get_instance_segment_result_merge_instance_segment@plt>:
 1072640:      	adrp	x16, 0x10d0000
 1072644:      	ldr	x17, [x16, #0x210]
 1072648:      	add	x16, x16, #0x210
 107264c:      	br	x17

0000000001072650 <vldp_get_instance_segment_result_segments@plt>:
 1072650:      	adrp	x16, 0x10d0000
 1072654:      	ldr	x17, [x16, #0x218]
 1072658:      	add	x16, x16, #0x218
 107265c:      	br	x17

0000000001072660 <vldp_get_instance_seg_array_pointer_size@plt>:
 1072660:      	adrp	x16, 0x10d0000
 1072664:      	ldr	x17, [x16, #0x220]
 1072668:      	add	x16, x16, #0x220
 107266c:      	br	x17

0000000001072670 <vldp_get_instance_seg_array_pointer_at@plt>:
 1072670:      	adrp	x16, 0x10d0000
 1072674:      	ldr	x17, [x16, #0x228]
 1072678:      	add	x16, x16, #0x228
 107267c:      	br	x17

0000000001072680 <vldp_get_instance_seg_has_seg_rect@plt>:
 1072680:      	adrp	x16, 0x10d0000
 1072684:      	ldr	x17, [x16, #0x230]
 1072688:      	add	x16, x16, #0x230
 107268c:      	br	x17

0000000001072690 <vldp_get_instance_seg_seg_rect@plt>:
 1072690:      	adrp	x16, 0x10d0000
 1072694:      	ldr	x17, [x16, #0x238]
 1072698:      	add	x16, x16, #0x238
 107269c:      	br	x17

00000000010726a0 <vldp_get_instance_seg_has_seg_rect_score@plt>:
 10726a0:      	adrp	x16, 0x10d0000
 10726a4:      	ldr	x17, [x16, #0x240]
 10726a8:      	add	x16, x16, #0x240
 10726ac:      	br	x17

00000000010726b0 <vldp_get_instance_seg_seg_rect_score@plt>:
 10726b0:      	adrp	x16, 0x10d0000
 10726b4:      	ldr	x17, [x16, #0x248]
 10726b8:      	add	x16, x16, #0x248
 10726bc:      	br	x17

00000000010726c0 <vldp_get_instance_seg_has_seg_tag@plt>:
 10726c0:      	adrp	x16, 0x10d0000
 10726c4:      	ldr	x17, [x16, #0x250]
 10726c8:      	add	x16, x16, #0x250
 10726cc:      	br	x17

00000000010726d0 <vldp_get_instance_seg_seg_tag@plt>:
 10726d0:      	adrp	x16, 0x10d0000
 10726d4:      	ldr	x17, [x16, #0x258]
 10726d8:      	add	x16, x16, #0x258
 10726dc:      	br	x17

00000000010726e0 <vldp_get_instance_seg_seg_mask_texture@plt>:
 10726e0:      	adrp	x16, 0x10d0000
 10726e4:      	ldr	x17, [x16, #0x260]
 10726e8:      	add	x16, x16, #0x260
 10726ec:      	br	x17

00000000010726f0 <vldp_get_instance_seg_seg_mask_image@plt>:
 10726f0:      	adrp	x16, 0x10d0000
 10726f4:      	ldr	x17, [x16, #0x268]
 10726f8:      	add	x16, x16, #0x268
 10726fc:      	br	x17

0000000001072700 <vldp_get_data_protocol_segment_result@plt>:
 1072700:      	adrp	x16, 0x10d0000
 1072704:      	ldr	x17, [x16, #0x270]
 1072708:      	add	x16, x16, #0x270
 107270c:      	br	x17

0000000001072710 <vldp_get_segment_result_pointer_ref@plt>:
 1072710:      	adrp	x16, 0x10d0000
 1072714:      	ldr	x17, [x16, #0x278]
 1072718:      	add	x16, x16, #0x278
 107271c:      	br	x17

0000000001072720 <vldp_get_data_protocol_custom_media_result@plt>:
 1072720:      	adrp	x16, 0x10d0000
 1072724:      	ldr	x17, [x16, #0x280]
 1072728:      	add	x16, x16, #0x280
 107272c:      	br	x17

0000000001072730 <vldp_get_custom_media_result_pointer_ref@plt>:
 1072730:      	adrp	x16, 0x10d0000
 1072734:      	ldr	x17, [x16, #0x288]
 1072738:      	add	x16, x16, #0x288
 107273c:      	br	x17

0000000001072740 <vldp_get_segment_result_has_hair_segment@plt>:
 1072740:      	adrp	x16, 0x10d0000
 1072744:      	ldr	x17, [x16, #0x290]
 1072748:      	add	x16, x16, #0x290
 107274c:      	br	x17

0000000001072750 <vldp_get_segment_result_hair_segment@plt>:
 1072750:      	adrp	x16, 0x10d0000
 1072754:      	ldr	x17, [x16, #0x298]
 1072758:      	add	x16, x16, #0x298
 107275c:      	br	x17

0000000001072760 <vldp_get_segment_out_texture@plt>:
 1072760:      	adrp	x16, 0x10d0000
 1072764:      	ldr	x17, [x16, #0x2a0]
 1072768:      	add	x16, x16, #0x2a0
 107276c:      	br	x17

0000000001072770 <vldp_get_segment_out_mask_image@plt>:
 1072770:      	adrp	x16, 0x10d0000
 1072774:      	ldr	x17, [x16, #0x2a8]
 1072778:      	add	x16, x16, #0x2a8
 107277c:      	br	x17

0000000001072780 <vldp_get_segment_result_has_skin_segment@plt>:
 1072780:      	adrp	x16, 0x10d0000
 1072784:      	ldr	x17, [x16, #0x2b0]
 1072788:      	add	x16, x16, #0x2b0
 107278c:      	br	x17

0000000001072790 <vldp_get_segment_result_skin_segment@plt>:
 1072790:      	adrp	x16, 0x10d0000
 1072794:      	ldr	x17, [x16, #0x2b8]
 1072798:      	add	x16, x16, #0x2b8
 107279c:      	br	x17

00000000010727a0 <vldp_get_segment_result_has_sky_segment@plt>:
 10727a0:      	adrp	x16, 0x10d0000
 10727a4:      	ldr	x17, [x16, #0x2c0]
 10727a8:      	add	x16, x16, #0x2c0
 10727ac:      	br	x17

00000000010727b0 <vldp_get_segment_result_sky_segment@plt>:
 10727b0:      	adrp	x16, 0x10d0000
 10727b4:      	ldr	x17, [x16, #0x2c8]
 10727b8:      	add	x16, x16, #0x2c8
 10727bc:      	br	x17

00000000010727c0 <vldp_get_segment_result_has_cloth_segment@plt>:
 10727c0:      	adrp	x16, 0x10d0000
 10727c4:      	ldr	x17, [x16, #0x2d0]
 10727c8:      	add	x16, x16, #0x2d0
 10727cc:      	br	x17

00000000010727d0 <vldp_get_segment_result_cloth_segment@plt>:
 10727d0:      	adrp	x16, 0x10d0000
 10727d4:      	ldr	x17, [x16, #0x2d8]
 10727d8:      	add	x16, x16, #0x2d8
 10727dc:      	br	x17

00000000010727e0 <vldp_get_segment_result_has_midas_segment@plt>:
 10727e0:      	adrp	x16, 0x10d0000
 10727e4:      	ldr	x17, [x16, #0x2e0]
 10727e8:      	add	x16, x16, #0x2e0
 10727ec:      	br	x17

00000000010727f0 <vldp_get_segment_result_midas_segment@plt>:
 10727f0:      	adrp	x16, 0x10d0000
 10727f4:      	ldr	x17, [x16, #0x2e8]
 10727f8:      	add	x16, x16, #0x2e8
 10727fc:      	br	x17

0000000001072800 <vldp_get_segment_result_has_depth_anything_segment@plt>:
 1072800:      	adrp	x16, 0x10d0000
 1072804:      	ldr	x17, [x16, #0x2f0]
 1072808:      	add	x16, x16, #0x2f0
 107280c:      	br	x17

0000000001072810 <vldp_get_segment_result_depth_anything_segment@plt>:
 1072810:      	adrp	x16, 0x10d0000
 1072814:      	ldr	x17, [x16, #0x2f8]
 1072818:      	add	x16, x16, #0x2f8
 107281c:      	br	x17

0000000001072820 <vldp_get_segment_result_has_matting_segment@plt>:
 1072820:      	adrp	x16, 0x10d0000
 1072824:      	ldr	x17, [x16, #0x300]
 1072828:      	add	x16, x16, #0x300
 107282c:      	br	x17

0000000001072830 <vldp_get_segment_result_matting_segment@plt>:
 1072830:      	adrp	x16, 0x10d0000
 1072834:      	ldr	x17, [x16, #0x308]
 1072838:      	add	x16, x16, #0x308
 107283c:      	br	x17

0000000001072840 <vldp_get_matting_out_texture@plt>:
 1072840:      	adrp	x16, 0x10d0000
 1072844:      	ldr	x17, [x16, #0x310]
 1072848:      	add	x16, x16, #0x310
 107284c:      	br	x17

0000000001072850 <vldp_get_matting_out_image@plt>:
 1072850:      	adrp	x16, 0x10d0000
 1072854:      	ldr	x17, [x16, #0x318]
 1072858:      	add	x16, x16, #0x318
 107285c:      	br	x17

0000000001072860 <vldp_get_segment_result_has_segmentation_segment@plt>:
 1072860:      	adrp	x16, 0x10d0000
 1072864:      	ldr	x17, [x16, #0x320]
 1072868:      	add	x16, x16, #0x320
 107286c:      	br	x17

0000000001072870 <vldp_get_segment_result_segmentation_segment@plt>:
 1072870:      	adrp	x16, 0x10d0000
 1072874:      	ldr	x17, [x16, #0x328]
 1072878:      	add	x16, x16, #0x328
 107287c:      	br	x17

0000000001072880 <vldp_get_segment_result_has_blur_portrait_segment@plt>:
 1072880:      	adrp	x16, 0x10d0000
 1072884:      	ldr	x17, [x16, #0x330]
 1072888:      	add	x16, x16, #0x330
 107288c:      	br	x17

0000000001072890 <vldp_get_segment_result_blur_portrait_segment@plt>:
 1072890:      	adrp	x16, 0x10d0000
 1072894:      	ldr	x17, [x16, #0x338]
 1072898:      	add	x16, x16, #0x338
 107289c:      	br	x17

00000000010728a0 <vldp_get_custom_media_result_has_body_segment@plt>:
 10728a0:      	adrp	x16, 0x10d0000
 10728a4:      	ldr	x17, [x16, #0x340]
 10728a8:      	add	x16, x16, #0x340
 10728ac:      	br	x17

00000000010728b0 <vldp_get_custom_media_result_body_segment@plt>:
 10728b0:      	adrp	x16, 0x10d0000
 10728b4:      	ldr	x17, [x16, #0x348]
 10728b8:      	add	x16, x16, #0x348
 10728bc:      	br	x17

00000000010728c0 <vldp_get_media_data_has_user_defined_flag@plt>:
 10728c0:      	adrp	x16, 0x10d0000
 10728c4:      	ldr	x17, [x16, #0x350]
 10728c8:      	add	x16, x16, #0x350
 10728cc:      	br	x17

00000000010728d0 <vldp_get_media_data_user_defined_flag@plt>:
 10728d0:      	adrp	x16, 0x10d0000
 10728d4:      	ldr	x17, [x16, #0x358]
 10728d8:      	add	x16, x16, #0x358
 10728dc:      	br	x17

00000000010728e0 <vldp_get_media_data_texture@plt>:
 10728e0:      	adrp	x16, 0x10d0000
 10728e4:      	ldr	x17, [x16, #0x360]
 10728e8:      	add	x16, x16, #0x360
 10728ec:      	br	x17

00000000010728f0 <vldp_get_segment_result_has_half_body_segment@plt>:
 10728f0:      	adrp	x16, 0x10d0000
 10728f4:      	ldr	x17, [x16, #0x368]
 10728f8:      	add	x16, x16, #0x368
 10728fc:      	br	x17

0000000001072900 <vldp_get_segment_result_half_body_segment@plt>:
 1072900:      	adrp	x16, 0x10d0000
 1072904:      	ldr	x17, [x16, #0x370]
 1072908:      	add	x16, x16, #0x370
 107290c:      	br	x17

0000000001072910 <vldp_get_segment_result_has_whole_body_segment@plt>:
 1072910:      	adrp	x16, 0x10d0000
 1072914:      	ldr	x17, [x16, #0x378]
 1072918:      	add	x16, x16, #0x378
 107291c:      	br	x17

0000000001072920 <vldp_get_segment_result_whole_body_segment@plt>:
 1072920:      	adrp	x16, 0x10d0000
 1072924:      	ldr	x17, [x16, #0x380]
 1072928:      	add	x16, x16, #0x380
 107292c:      	br	x17

0000000001072930 <vldp_get_custom_media_result_user_defined@plt>:
 1072930:      	adrp	x16, 0x10d0000
 1072934:      	ldr	x17, [x16, #0x388]
 1072938:      	add	x16, x16, #0x388
 107293c:      	br	x17

0000000001072940 <vldp_get_media_data_array_pointer_size@plt>:
 1072940:      	adrp	x16, 0x10d0000
 1072944:      	ldr	x17, [x16, #0x390]
 1072948:      	add	x16, x16, #0x390
 107294c:      	br	x17

0000000001072950 <vldp_get_media_data_array_pointer_at@plt>:
 1072950:      	adrp	x16, 0x10d0000
 1072954:      	ldr	x17, [x16, #0x398]
 1072958:      	add	x16, x16, #0x398
 107295c:      	br	x17

0000000001072960 <vldp_get_segment_result_has_space_depth_segment@plt>:
 1072960:      	adrp	x16, 0x10d0000
 1072964:      	ldr	x17, [x16, #0x3a0]
 1072968:      	add	x16, x16, #0x3a0
 107296c:      	br	x17

0000000001072970 <vldp_get_segment_result_space_depth_segment@plt>:
 1072970:      	adrp	x16, 0x10d0000
 1072974:      	ldr	x17, [x16, #0x3a8]
 1072978:      	add	x16, x16, #0x3a8
 107297c:      	br	x17

0000000001072980 <vldp_get_segment_result_has_space_depth_normal_segment@plt>:
 1072980:      	adrp	x16, 0x10d0000
 1072984:      	ldr	x17, [x16, #0x3b0]
 1072988:      	add	x16, x16, #0x3b0
 107298c:      	br	x17

0000000001072990 <vldp_get_segment_result_space_depth_normal_segment@plt>:
 1072990:      	adrp	x16, 0x10d0000
 1072994:      	ldr	x17, [x16, #0x3b8]
 1072998:      	add	x16, x16, #0x3b8
 107299c:      	br	x17

00000000010729a0 <vldp_get_segment_result_has_video_skin_segment@plt>:
 10729a0:      	adrp	x16, 0x10d0000
 10729a4:      	ldr	x17, [x16, #0x3c0]
 10729a8:      	add	x16, x16, #0x3c0
 10729ac:      	br	x17

00000000010729b0 <vldp_get_segment_result_video_skin_segment@plt>:
 10729b0:      	adrp	x16, 0x10d0000
 10729b4:      	ldr	x17, [x16, #0x3c8]
 10729b8:      	add	x16, x16, #0x3c8
 10729bc:      	br	x17

00000000010729c0 <vldp_get_segment_result_has_interactive_segment@plt>:
 10729c0:      	adrp	x16, 0x10d0000
 10729c4:      	ldr	x17, [x16, #0x3d0]
 10729c8:      	add	x16, x16, #0x3d0
 10729cc:      	br	x17

00000000010729d0 <vldp_get_segment_result_interactive_segment@plt>:
 10729d0:      	adrp	x16, 0x10d0000
 10729d4:      	ldr	x17, [x16, #0x3d8]
 10729d8:      	add	x16, x16, #0x3d8
 10729dc:      	br	x17

00000000010729e0 <vldp_get_segment_result_has_salient_object_detection_segment@plt>:
 10729e0:      	adrp	x16, 0x10d0000
 10729e4:      	ldr	x17, [x16, #0x3e0]
 10729e8:      	add	x16, x16, #0x3e0
 10729ec:      	br	x17

00000000010729f0 <vldp_get_segment_result_salient_object_detection_segment@plt>:
 10729f0:      	adrp	x16, 0x10d0000
 10729f4:      	ldr	x17, [x16, #0x3e8]
 10729f8:      	add	x16, x16, #0x3e8
 10729fc:      	br	x17

0000000001072a00 <vldp_get_segment_result_has_deep_blur_segment@plt>:
 1072a00:      	adrp	x16, 0x10d0000
 1072a04:      	ldr	x17, [x16, #0x3f0]
 1072a08:      	add	x16, x16, #0x3f0
 1072a0c:      	br	x17

0000000001072a10 <vldp_get_segment_result_deep_blur_segment@plt>:
 1072a10:      	adrp	x16, 0x10d0000
 1072a14:      	ldr	x17, [x16, #0x3f8]
 1072a18:      	add	x16, x16, #0x3f8
 1072a1c:      	br	x17

0000000001072a20 <vldp_get_segment_result_has_deep_blur_light_segment@plt>:
 1072a20:      	adrp	x16, 0x10d0000
 1072a24:      	ldr	x17, [x16, #0x400]
 1072a28:      	add	x16, x16, #0x400
 1072a2c:      	br	x17

0000000001072a30 <vldp_get_segment_result_deep_blur_light_segment@plt>:
 1072a30:      	adrp	x16, 0x10d0000
 1072a34:      	ldr	x17, [x16, #0x408]
 1072a38:      	add	x16, x16, #0x408
 1072a3c:      	br	x17

0000000001072a40 <vldp_get_segment_result_has_muti_segment@plt>:
 1072a40:      	adrp	x16, 0x10d0000
 1072a44:      	ldr	x17, [x16, #0x410]
 1072a48:      	add	x16, x16, #0x410
 1072a4c:      	br	x17

0000000001072a50 <vldp_get_segment_result_muti_segment@plt>:
 1072a50:      	adrp	x16, 0x10d0000
 1072a54:      	ldr	x17, [x16, #0x418]
 1072a58:      	add	x16, x16, #0x418
 1072a5c:      	br	x17

0000000001072a60 <vldp_get_muti_segment_has_muti_body_segment@plt>:
 1072a60:      	adrp	x16, 0x10d0000
 1072a64:      	ldr	x17, [x16, #0x420]
 1072a68:      	add	x16, x16, #0x420
 1072a6c:      	br	x17

0000000001072a70 <vldp_get_muti_segment_muti_body_segment@plt>:
 1072a70:      	adrp	x16, 0x10d0000
 1072a74:      	ldr	x17, [x16, #0x428]
 1072a78:      	add	x16, x16, #0x428
 1072a7c:      	br	x17

0000000001072a80 <vldp_get_muti_segment_has_muti_skin_segment@plt>:
 1072a80:      	adrp	x16, 0x10d0000
 1072a84:      	ldr	x17, [x16, #0x430]
 1072a88:      	add	x16, x16, #0x430
 1072a8c:      	br	x17

0000000001072a90 <vldp_get_muti_segment_muti_skin_segment@plt>:
 1072a90:      	adrp	x16, 0x10d0000
 1072a94:      	ldr	x17, [x16, #0x438]
 1072a98:      	add	x16, x16, #0x438
 1072a9c:      	br	x17

0000000001072aa0 <vldp_get_muti_segment_has_muti_hair_segment@plt>:
 1072aa0:      	adrp	x16, 0x10d0000
 1072aa4:      	ldr	x17, [x16, #0x440]
 1072aa8:      	add	x16, x16, #0x440
 1072aac:      	br	x17

0000000001072ab0 <vldp_get_muti_segment_muti_hair_segment@plt>:
 1072ab0:      	adrp	x16, 0x10d0000
 1072ab4:      	ldr	x17, [x16, #0x448]
 1072ab8:      	add	x16, x16, #0x448
 1072abc:      	br	x17

0000000001072ac0 <vldp_get_muti_segment_has_muti_cloth_segment@plt>:
 1072ac0:      	adrp	x16, 0x10d0000
 1072ac4:      	ldr	x17, [x16, #0x450]
 1072ac8:      	add	x16, x16, #0x450
 1072acc:      	br	x17

0000000001072ad0 <vldp_get_muti_segment_muti_cloth_segment@plt>:
 1072ad0:      	adrp	x16, 0x10d0000
 1072ad4:      	ldr	x17, [x16, #0x458]
 1072ad8:      	add	x16, x16, #0x458
 1072adc:      	br	x17

0000000001072ae0 <vldp_get_data_protocol_cg_style_result@plt>:
 1072ae0:      	adrp	x16, 0x10d0000
 1072ae4:      	ldr	x17, [x16, #0x460]
 1072ae8:      	add	x16, x16, #0x460
 1072aec:      	br	x17

0000000001072af0 <vldp_get_cg_style_result_pointer_ref@plt>:
 1072af0:      	adrp	x16, 0x10d0000
 1072af4:      	ldr	x17, [x16, #0x468]
 1072af8:      	add	x16, x16, #0x468
 1072afc:      	br	x17

0000000001072b00 <vldp_get_cg_style_result_cg_texture@plt>:
 1072b00:      	adrp	x16, 0x10d0000
 1072b04:      	ldr	x17, [x16, #0x470]
 1072b08:      	add	x16, x16, #0x470
 1072b0c:      	br	x17

0000000001072b10 <vldp_get_cg_style_result_has_cg_matrix@plt>:
 1072b10:      	adrp	x16, 0x10d0000
 1072b14:      	ldr	x17, [x16, #0x478]
 1072b18:      	add	x16, x16, #0x478
 1072b1c:      	br	x17

0000000001072b20 <vldp_get_cg_style_result_cg_matrix@plt>:
 1072b20:      	adrp	x16, 0x10d0000
 1072b24:      	ldr	x17, [x16, #0x480]
 1072b28:      	add	x16, x16, #0x480
 1072b2c:      	br	x17

0000000001072b30 <vldp_get_segment_result_face_contour_segments@plt>:
 1072b30:      	adrp	x16, 0x10d0000
 1072b34:      	ldr	x17, [x16, #0x488]
 1072b38:      	add	x16, x16, #0x488
 1072b3c:      	br	x17

0000000001072b40 <vldp_get_face_contour_segment_array_pointer_size@plt>:
 1072b40:      	adrp	x16, 0x10d0000
 1072b44:      	ldr	x17, [x16, #0x490]
 1072b48:      	add	x16, x16, #0x490
 1072b4c:      	br	x17

0000000001072b50 <vldp_get_face_contour_segment_array_pointer_at@plt>:
 1072b50:      	adrp	x16, 0x10d0000
 1072b54:      	ldr	x17, [x16, #0x498]
 1072b58:      	add	x16, x16, #0x498
 1072b5c:      	br	x17

0000000001072b60 <vldp_get_face_contour_segment_has_face_contour_backgroud_segment@plt>:
 1072b60:      	adrp	x16, 0x10d0000
 1072b64:      	ldr	x17, [x16, #0x4a0]
 1072b68:      	add	x16, x16, #0x4a0
 1072b6c:      	br	x17

0000000001072b70 <vldp_get_face_contour_segment_face_contour_backgroud_segment@plt>:
 1072b70:      	adrp	x16, 0x10d0000
 1072b74:      	ldr	x17, [x16, #0x4a8]
 1072b78:      	add	x16, x16, #0x4a8
 1072b7c:      	br	x17

0000000001072b80 <vldp_get_face_contour_segment_has_face_contour_skin_segment@plt>:
 1072b80:      	adrp	x16, 0x10d0000
 1072b84:      	ldr	x17, [x16, #0x4b0]
 1072b88:      	add	x16, x16, #0x4b0
 1072b8c:      	br	x17

0000000001072b90 <vldp_get_face_contour_segment_face_contour_skin_segment@plt>:
 1072b90:      	adrp	x16, 0x10d0000
 1072b94:      	ldr	x17, [x16, #0x4b8]
 1072b98:      	add	x16, x16, #0x4b8
 1072b9c:      	br	x17

0000000001072ba0 <vldp_get_segment_result_facial_segments@plt>:
 1072ba0:      	adrp	x16, 0x10d0000
 1072ba4:      	ldr	x17, [x16, #0x4c0]
 1072ba8:      	add	x16, x16, #0x4c0
 1072bac:      	br	x17

0000000001072bb0 <vldp_get_facial_segment_array_pointer_size@plt>:
 1072bb0:      	adrp	x16, 0x10d0000
 1072bb4:      	ldr	x17, [x16, #0x4c8]
 1072bb8:      	add	x16, x16, #0x4c8
 1072bbc:      	br	x17

0000000001072bc0 <vldp_get_facial_segment_array_pointer_at@plt>:
 1072bc0:      	adrp	x16, 0x10d0000
 1072bc4:      	ldr	x17, [x16, #0x4d0]
 1072bc8:      	add	x16, x16, #0x4d0
 1072bcc:      	br	x17

0000000001072bd0 <vldp_get_facial_segment_has_facial_background_segment@plt>:
 1072bd0:      	adrp	x16, 0x10d0000
 1072bd4:      	ldr	x17, [x16, #0x4d8]
 1072bd8:      	add	x16, x16, #0x4d8
 1072bdc:      	br	x17

0000000001072be0 <vldp_get_facial_segment_facial_background_segment@plt>:
 1072be0:      	adrp	x16, 0x10d0000
 1072be4:      	ldr	x17, [x16, #0x4e0]
 1072be8:      	add	x16, x16, #0x4e0
 1072bec:      	br	x17

0000000001072bf0 <vldp_get_facial_segment_has_facial_face_skin_segment@plt>:
 1072bf0:      	adrp	x16, 0x10d0000
 1072bf4:      	ldr	x17, [x16, #0x4e8]
 1072bf8:      	add	x16, x16, #0x4e8
 1072bfc:      	br	x17

0000000001072c00 <vldp_get_facial_segment_facial_face_skin_segment@plt>:
 1072c00:      	adrp	x16, 0x10d0000
 1072c04:      	ldr	x17, [x16, #0x4f0]
 1072c08:      	add	x16, x16, #0x4f0
 1072c0c:      	br	x17

0000000001072c10 <vldp_get_facial_segment_has_facial_brow_segment@plt>:
 1072c10:      	adrp	x16, 0x10d0000
 1072c14:      	ldr	x17, [x16, #0x4f8]
 1072c18:      	add	x16, x16, #0x4f8
 1072c1c:      	br	x17

0000000001072c20 <vldp_get_facial_segment_facial_brow_segment@plt>:
 1072c20:      	adrp	x16, 0x10d0000
 1072c24:      	ldr	x17, [x16, #0x500]
 1072c28:      	add	x16, x16, #0x500
 1072c2c:      	br	x17

0000000001072c30 <vldp_get_facial_segment_has_facial_eye_segment@plt>:
 1072c30:      	adrp	x16, 0x10d0000
 1072c34:      	ldr	x17, [x16, #0x508]
 1072c38:      	add	x16, x16, #0x508
 1072c3c:      	br	x17

0000000001072c40 <vldp_get_facial_segment_facial_eye_segment@plt>:
 1072c40:      	adrp	x16, 0x10d0000
 1072c44:      	ldr	x17, [x16, #0x510]
 1072c48:      	add	x16, x16, #0x510
 1072c4c:      	br	x17

0000000001072c50 <vldp_get_facial_segment_has_facial_nose_segment@plt>:
 1072c50:      	adrp	x16, 0x10d0000
 1072c54:      	ldr	x17, [x16, #0x518]
 1072c58:      	add	x16, x16, #0x518
 1072c5c:      	br	x17

0000000001072c60 <vldp_get_facial_segment_facial_nose_segment@plt>:
 1072c60:      	adrp	x16, 0x10d0000
 1072c64:      	ldr	x17, [x16, #0x520]
 1072c68:      	add	x16, x16, #0x520
 1072c6c:      	br	x17

0000000001072c70 <vldp_get_facial_segment_has_facial_lip_segment@plt>:
 1072c70:      	adrp	x16, 0x10d0000
 1072c74:      	ldr	x17, [x16, #0x528]
 1072c78:      	add	x16, x16, #0x528
 1072c7c:      	br	x17

0000000001072c80 <vldp_get_facial_segment_facial_lip_segment@plt>:
 1072c80:      	adrp	x16, 0x10d0000
 1072c84:      	ldr	x17, [x16, #0x530]
 1072c88:      	add	x16, x16, #0x530
 1072c8c:      	br	x17

0000000001072c90 <vldp_get_facial_segment_has_facial_teeth_segment@plt>:
 1072c90:      	adrp	x16, 0x10d0000
 1072c94:      	ldr	x17, [x16, #0x538]
 1072c98:      	add	x16, x16, #0x538
 1072c9c:      	br	x17

0000000001072ca0 <vldp_get_facial_segment_facial_teeth_segment@plt>:
 1072ca0:      	adrp	x16, 0x10d0000
 1072ca4:      	ldr	x17, [x16, #0x540]
 1072ca8:      	add	x16, x16, #0x540
 1072cac:      	br	x17

0000000001072cb0 <vldp_get_facial_segment_has_facial_pupilla_segment@plt>:
 1072cb0:      	adrp	x16, 0x10d0000
 1072cb4:      	ldr	x17, [x16, #0x548]
 1072cb8:      	add	x16, x16, #0x548
 1072cbc:      	br	x17

0000000001072cc0 <vldp_get_facial_segment_facial_pupilla_segment@plt>:
 1072cc0:      	adrp	x16, 0x10d0000
 1072cc4:      	ldr	x17, [x16, #0x550]
 1072cc8:      	add	x16, x16, #0x550
 1072ccc:      	br	x17

0000000001072cd0 <vldp_get_facial_segment_has_facial_glasses_segment@plt>:
 1072cd0:      	adrp	x16, 0x10d0000
 1072cd4:      	ldr	x17, [x16, #0x558]
 1072cd8:      	add	x16, x16, #0x558
 1072cdc:      	br	x17

0000000001072ce0 <vldp_get_facial_segment_facial_glasses_segment@plt>:
 1072ce0:      	adrp	x16, 0x10d0000
 1072ce4:      	ldr	x17, [x16, #0x560]
 1072ce8:      	add	x16, x16, #0x560
 1072cec:      	br	x17

0000000001072cf0 <vldp_get_facial_segment_has_facial_beard_segment@plt>:
 1072cf0:      	adrp	x16, 0x10d0000
 1072cf4:      	ldr	x17, [x16, #0x568]
 1072cf8:      	add	x16, x16, #0x568
 1072cfc:      	br	x17

0000000001072d00 <vldp_get_facial_segment_facial_beard_segment@plt>:
 1072d00:      	adrp	x16, 0x10d0000
 1072d04:      	ldr	x17, [x16, #0x570]
 1072d08:      	add	x16, x16, #0x570
 1072d0c:      	br	x17

0000000001072d10 <vldp_get_segment_result_head_segments@plt>:
 1072d10:      	adrp	x16, 0x10d0000
 1072d14:      	ldr	x17, [x16, #0x578]
 1072d18:      	add	x16, x16, #0x578
 1072d1c:      	br	x17

0000000001072d20 <vldp_get_segment_array_pointer_size@plt>:
 1072d20:      	adrp	x16, 0x10d0000
 1072d24:      	ldr	x17, [x16, #0x580]
 1072d28:      	add	x16, x16, #0x580
 1072d2c:      	br	x17

0000000001072d30 <vldp_get_segment_array_pointer_at@plt>:
 1072d30:      	adrp	x16, 0x10d0000
 1072d34:      	ldr	x17, [x16, #0x588]
 1072d38:      	add	x16, x16, #0x588
 1072d3c:      	br	x17

0000000001072d40 <vldp_get_texture_width@plt>:
 1072d40:      	adrp	x16, 0x10d0000
 1072d44:      	ldr	x17, [x16, #0x590]
 1072d48:      	add	x16, x16, #0x590
 1072d4c:      	br	x17

0000000001072d50 <vldp_get_texture_height@plt>:
 1072d50:      	adrp	x16, 0x10d0000
 1072d54:      	ldr	x17, [x16, #0x598]
 1072d58:      	add	x16, x16, #0x598
 1072d5c:      	br	x17

0000000001072d60 <vldp_get_texture_format@plt>:
 1072d60:      	adrp	x16, 0x10d0000
 1072d64:      	ldr	x17, [x16, #0x5a0]
 1072d68:      	add	x16, x16, #0x5a0
 1072d6c:      	br	x17

0000000001072d70 <vldp_get_texture_metal_handle@plt>:
 1072d70:      	adrp	x16, 0x10d0000
 1072d74:      	ldr	x17, [x16, #0x5a8]
 1072d78:      	add	x16, x16, #0x5a8
 1072d7c:      	br	x17

0000000001072d80 <vldp_get_texture_opengl_handle@plt>:
 1072d80:      	adrp	x16, 0x10d0000
 1072d84:      	ldr	x17, [x16, #0x5b0]
 1072d88:      	add	x16, x16, #0x5b0
 1072d8c:      	br	x17

0000000001072d90 <vldp_get_texture_d3d11_handle@plt>:
 1072d90:      	adrp	x16, 0x10d0000
 1072d94:      	ldr	x17, [x16, #0x5b8]
 1072d98:      	add	x16, x16, #0x5b8
 1072d9c:      	br	x17

0000000001072da0 <vldp_get_image_format@plt>:
 1072da0:      	adrp	x16, 0x10d0000
 1072da4:      	ldr	x17, [x16, #0x5c0]
 1072da8:      	add	x16, x16, #0x5c0
 1072dac:      	br	x17

0000000001072db0 <wgpuTextureGetUsage@plt>:
 1072db0:      	adrp	x16, 0x10d0000
 1072db4:      	ldr	x17, [x16, #0x5c8]
 1072db8:      	add	x16, x16, #0x5c8
 1072dbc:      	br	x17

0000000001072dc0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED1Ev@plt>:
 1072dc0:      	adrp	x16, 0x10d0000
 1072dc4:      	ldr	x17, [x16, #0x5d0]
 1072dc8:      	add	x16, x16, #0x5d0
 1072dcc:      	br	x17

0000000001072dd0 <_ZN5image11typeConvertIfhEENS_11DetailImageIT0_EERKNS1_IT_EE@plt>:
 1072dd0:      	adrp	x16, 0x10d0000
 1072dd4:      	ldr	x17, [x16, #0x5d8]
 1072dd8:      	add	x16, x16, #0x5d8
 1072ddc:      	br	x17

0000000001072de0 <atoi@plt>:
 1072de0:      	adrp	x16, 0x10d0000
 1072de4:      	ldr	x17, [x16, #0x5e0]
 1072de8:      	add	x16, x16, #0x5e0
 1072dec:      	br	x17

0000000001072df0 <wgpuShaderModuleRelease@plt>:
 1072df0:      	adrp	x16, 0x10d0000
 1072df4:      	ldr	x17, [x16, #0x5e8]
 1072df8:      	add	x16, x16, #0x5e8
 1072dfc:      	br	x17

0000000001072e00 <wgpuDeviceCreateShaderModule@plt>:
 1072e00:      	adrp	x16, 0x10d0000
 1072e04:      	ldr	x17, [x16, #0x5f0]
 1072e08:      	add	x16, x16, #0x5f0
 1072e0c:      	br	x17

0000000001072e10 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKc@plt>:
 1072e10:      	adrp	x16, 0x10d0000
 1072e14:      	ldr	x17, [x16, #0x5f8]
 1072e18:      	add	x16, x16, #0x5f8
 1072e1c:      	br	x17

0000000001072e20 <wgpuDeviceHasFeature@plt>:
 1072e20:      	adrp	x16, 0x10d0000
 1072e24:      	ldr	x17, [x16, #0x600]
 1072e28:      	add	x16, x16, #0x600
 1072e2c:      	br	x17

0000000001072e30 <av_frame_unref@plt>:
 1072e30:      	adrp	x16, 0x10d0000
 1072e34:      	ldr	x17, [x16, #0x608]
 1072e38:      	add	x16, x16, #0x608
 1072e3c:      	br	x17

0000000001072e40 <_ZNSt6__ndk16thread4joinEv@plt>:
 1072e40:      	adrp	x16, 0x10d0000
 1072e44:      	ldr	x17, [x16, #0x610]
 1072e48:      	add	x16, x16, #0x610
 1072e4c:      	br	x17

0000000001072e50 <avcodec_free_context@plt>:
 1072e50:      	adrp	x16, 0x10d0000
 1072e54:      	ldr	x17, [x16, #0x618]
 1072e58:      	add	x16, x16, #0x618
 1072e5c:      	br	x17

0000000001072e60 <avformat_close_input@plt>:
 1072e60:      	adrp	x16, 0x10d0000
 1072e64:      	ldr	x17, [x16, #0x620]
 1072e68:      	add	x16, x16, #0x620
 1072e6c:      	br	x17

0000000001072e70 <av_free@plt>:
 1072e70:      	adrp	x16, 0x10d0000
 1072e74:      	ldr	x17, [x16, #0x628]
 1072e78:      	add	x16, x16, #0x628
 1072e7c:      	br	x17

0000000001072e80 <avio_context_free@plt>:
 1072e80:      	adrp	x16, 0x10d0000
 1072e84:      	ldr	x17, [x16, #0x630]
 1072e88:      	add	x16, x16, #0x630
 1072e8c:      	br	x17

0000000001072e90 <_ZNSt6__ndk16threadD1Ev@plt>:
 1072e90:      	adrp	x16, 0x10d0000
 1072e94:      	ldr	x17, [x16, #0x638]
 1072e98:      	add	x16, x16, #0x638
 1072e9c:      	br	x17

0000000001072ea0 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
 1072ea0:      	adrp	x16, 0x10d0000
 1072ea4:      	ldr	x17, [x16, #0x640]
 1072ea8:      	add	x16, x16, #0x640
 1072eac:      	br	x17

0000000001072eb0 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
 1072eb0:      	adrp	x16, 0x10d0000
 1072eb4:      	ldr	x17, [x16, #0x648]
 1072eb8:      	add	x16, x16, #0x648
 1072ebc:      	br	x17

0000000001072ec0 <av_frame_alloc@plt>:
 1072ec0:      	adrp	x16, 0x10d0000
 1072ec4:      	ldr	x17, [x16, #0x650]
 1072ec8:      	add	x16, x16, #0x650
 1072ecc:      	br	x17

0000000001072ed0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
 1072ed0:      	adrp	x16, 0x10d0000
 1072ed4:      	ldr	x17, [x16, #0x658]
 1072ed8:      	add	x16, x16, #0x658
 1072edc:      	br	x17

0000000001072ee0 <av_malloc@plt>:
 1072ee0:      	adrp	x16, 0x10d0000
 1072ee4:      	ldr	x17, [x16, #0x660]
 1072ee8:      	add	x16, x16, #0x660
 1072eec:      	br	x17

0000000001072ef0 <avio_alloc_context@plt>:
 1072ef0:      	adrp	x16, 0x10d0000
 1072ef4:      	ldr	x17, [x16, #0x668]
 1072ef8:      	add	x16, x16, #0x668
 1072efc:      	br	x17

0000000001072f00 <avformat_alloc_context@plt>:
 1072f00:      	adrp	x16, 0x10d0000
 1072f04:      	ldr	x17, [x16, #0x670]
 1072f08:      	add	x16, x16, #0x670
 1072f0c:      	br	x17

0000000001072f10 <av_dict_set@plt>:
 1072f10:      	adrp	x16, 0x10d0000
 1072f14:      	ldr	x17, [x16, #0x678]
 1072f18:      	add	x16, x16, #0x678
 1072f1c:      	br	x17

0000000001072f20 <avformat_open_input@plt>:
 1072f20:      	adrp	x16, 0x10d0000
 1072f24:      	ldr	x17, [x16, #0x680]
 1072f28:      	add	x16, x16, #0x680
 1072f2c:      	br	x17

0000000001072f30 <av_dict_free@plt>:
 1072f30:      	adrp	x16, 0x10d0000
 1072f34:      	ldr	x17, [x16, #0x688]
 1072f38:      	add	x16, x16, #0x688
 1072f3c:      	br	x17

0000000001072f40 <avformat_find_stream_info@plt>:
 1072f40:      	adrp	x16, 0x10d0000
 1072f44:      	ldr	x17, [x16, #0x690]
 1072f48:      	add	x16, x16, #0x690
 1072f4c:      	br	x17

0000000001072f50 <avcodec_find_decoder_by_name@plt>:
 1072f50:      	adrp	x16, 0x10d0000
 1072f54:      	ldr	x17, [x16, #0x698]
 1072f58:      	add	x16, x16, #0x698
 1072f5c:      	br	x17

0000000001072f60 <avcodec_find_decoder@plt>:
 1072f60:      	adrp	x16, 0x10d0000
 1072f64:      	ldr	x17, [x16, #0x6a0]
 1072f68:      	add	x16, x16, #0x6a0
 1072f6c:      	br	x17

0000000001072f70 <avcodec_alloc_context3@plt>:
 1072f70:      	adrp	x16, 0x10d0000
 1072f74:      	ldr	x17, [x16, #0x6a8]
 1072f78:      	add	x16, x16, #0x6a8
 1072f7c:      	br	x17

0000000001072f80 <avcodec_parameters_to_context@plt>:
 1072f80:      	adrp	x16, 0x10d0000
 1072f84:      	ldr	x17, [x16, #0x6b0]
 1072f88:      	add	x16, x16, #0x6b0
 1072f8c:      	br	x17

0000000001072f90 <avcodec_open2@plt>:
 1072f90:      	adrp	x16, 0x10d0000
 1072f94:      	ldr	x17, [x16, #0x6b8]
 1072f98:      	add	x16, x16, #0x6b8
 1072f9c:      	br	x17

0000000001072fa0 <av_packet_alloc@plt>:
 1072fa0:      	adrp	x16, 0x10d0000
 1072fa4:      	ldr	x17, [x16, #0x6c0]
 1072fa8:      	add	x16, x16, #0x6c0
 1072fac:      	br	x17

0000000001072fb0 <av_rescale_q_rnd@plt>:
 1072fb0:      	adrp	x16, 0x10d0000
 1072fb4:      	ldr	x17, [x16, #0x6c8]
 1072fb8:      	add	x16, x16, #0x6c8
 1072fbc:      	br	x17

0000000001072fc0 <av_seek_frame@plt>:
 1072fc0:      	adrp	x16, 0x10d0000
 1072fc4:      	ldr	x17, [x16, #0x6d0]
 1072fc8:      	add	x16, x16, #0x6d0
 1072fcc:      	br	x17

0000000001072fd0 <avcodec_flush_buffers@plt>:
 1072fd0:      	adrp	x16, 0x10d0000
 1072fd4:      	ldr	x17, [x16, #0x6d8]
 1072fd8:      	add	x16, x16, #0x6d8
 1072fdc:      	br	x17

0000000001072fe0 <av_packet_unref@plt>:
 1072fe0:      	adrp	x16, 0x10d0000
 1072fe4:      	ldr	x17, [x16, #0x6e0]
 1072fe8:      	add	x16, x16, #0x6e0
 1072fec:      	br	x17

0000000001072ff0 <av_read_frame@plt>:
 1072ff0:      	adrp	x16, 0x10d0000
 1072ff4:      	ldr	x17, [x16, #0x6e8]
 1072ff8:      	add	x16, x16, #0x6e8
 1072ffc:      	br	x17

0000000001073000 <avcodec_send_packet@plt>:
 1073000:      	adrp	x16, 0x10d0000
 1073004:      	ldr	x17, [x16, #0x6f0]
 1073008:      	add	x16, x16, #0x6f0
 107300c:      	br	x17

0000000001073010 <av_strerror@plt>:
 1073010:      	adrp	x16, 0x10d0000
 1073014:      	ldr	x17, [x16, #0x6f8]
 1073018:      	add	x16, x16, #0x6f8
 107301c:      	br	x17

0000000001073020 <avcodec_receive_frame@plt>:
 1073020:      	adrp	x16, 0x10d0000
 1073024:      	ldr	x17, [x16, #0x700]
 1073028:      	add	x16, x16, #0x700
 107302c:      	br	x17

0000000001073030 <av_frame_move_ref@plt>:
 1073030:      	adrp	x16, 0x10d0000
 1073034:      	ldr	x17, [x16, #0x708]
 1073038:      	add	x16, x16, #0x708
 107303c:      	br	x17

0000000001073040 <av_frame_free@plt>:
 1073040:      	adrp	x16, 0x10d0000
 1073044:      	ldr	x17, [x16, #0x710]
 1073048:      	add	x16, x16, #0x710
 107304c:      	br	x17

0000000001073050 <av_packet_free@plt>:
 1073050:      	adrp	x16, 0x10d0000
 1073054:      	ldr	x17, [x16, #0x718]
 1073058:      	add	x16, x16, #0x718
 107305c:      	br	x17

0000000001073060 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
 1073060:      	adrp	x16, 0x10d0000
 1073064:      	ldr	x17, [x16, #0x720]
 1073068:      	add	x16, x16, #0x720
 107306c:      	br	x17

0000000001073070 <pthread_create@plt>:
 1073070:      	adrp	x16, 0x10d0000
 1073074:      	ldr	x17, [x16, #0x728]
 1073078:      	add	x16, x16, #0x728
 107307c:      	br	x17

0000000001073080 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
 1073080:      	adrp	x16, 0x10d0000
 1073084:      	ldr	x17, [x16, #0x730]
 1073088:      	add	x16, x16, #0x730
 107308c:      	br	x17

0000000001073090 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
 1073090:      	adrp	x16, 0x10d0000
 1073094:      	ldr	x17, [x16, #0x738]
 1073098:      	add	x16, x16, #0x738
 107309c:      	br	x17

00000000010730a0 <av_rescale_q@plt>:
 10730a0:      	adrp	x16, 0x10d0000
 10730a4:      	ldr	x17, [x16, #0x740]
 10730a8:      	add	x16, x16, #0x740
 10730ac:      	br	x17

00000000010730b0 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
 10730b0:      	adrp	x16, 0x10d0000
 10730b4:      	ldr	x17, [x16, #0x748]
 10730b8:      	add	x16, x16, #0x748
 10730bc:      	br	x17

00000000010730c0 <pthread_setspecific@plt>:
 10730c0:      	adrp	x16, 0x10d0000
 10730c4:      	ldr	x17, [x16, #0x750]
 10730c8:      	add	x16, x16, #0x750
 10730cc:      	br	x17

00000000010730d0 <wgpuTextureGetSampleCount@plt>:
 10730d0:      	adrp	x16, 0x10d0000
 10730d4:      	ldr	x17, [x16, #0x758]
 10730d8:      	add	x16, x16, #0x758
 10730dc:      	br	x17

00000000010730e0 <_ZNSt6__ndk16thread20hardware_concurrencyEv@plt>:
 10730e0:      	adrp	x16, 0x10d0000
 10730e4:      	ldr	x17, [x16, #0x760]
 10730e8:      	add	x16, x16, #0x760
 10730ec:      	br	x17

00000000010730f0 <wgpuDevicePushErrorScope@plt>:
 10730f0:      	adrp	x16, 0x10d0000
 10730f4:      	ldr	x17, [x16, #0x768]
 10730f8:      	add	x16, x16, #0x768
 10730fc:      	br	x17

0000000001073100 <wgpuDevicePopErrorScope@plt>:
 1073100:      	adrp	x16, 0x10d0000
 1073104:      	ldr	x17, [x16, #0x770]
 1073108:      	add	x16, x16, #0x770
 107310c:      	br	x17

0000000001073110 <_Z16MTARMPMSetJavaVMPv@plt>:
 1073110:      	adrp	x16, 0x10d0000
 1073114:      	ldr	x17, [x16, #0x778]
 1073118:      	add	x16, x16, #0x778
 107311c:      	br	x17

0000000001073120 <_Z19MTARMPMServiceStartv@plt>:
 1073120:      	adrp	x16, 0x10d0000
 1073124:      	ldr	x17, [x16, #0x780]
 1073128:      	add	x16, x16, #0x780
 107312c:      	br	x17

0000000001073130 <_Z19MTARMPMServicePausei@plt>:
 1073130:      	adrp	x16, 0x10d0000
 1073134:      	ldr	x17, [x16, #0x788]
 1073138:      	add	x16, x16, #0x788
 107313c:      	br	x17

0000000001073140 <_Z18MTARMPMServiceStopv@plt>:
 1073140:      	adrp	x16, 0x10d0000
 1073144:      	ldr	x17, [x16, #0x790]
 1073148:      	add	x16, x16, #0x790
 107314c:      	br	x17

0000000001073150 <_Z23MTARMPMServiceIsStoppedv@plt>:
 1073150:      	adrp	x16, 0x10d0000
 1073154:      	ldr	x17, [x16, #0x798]
 1073158:      	add	x16, x16, #0x798
 107315c:      	br	x17

0000000001073160 <_Z24MTARMPMCreateMusicHandlev@plt>:
 1073160:      	adrp	x16, 0x10d0000
 1073164:      	ldr	x17, [x16, #0x7a0]
 1073168:      	add	x16, x16, #0x7a0
 107316c:      	br	x17

0000000001073170 <_Z16MTARMPMMusicLoadPvPKc@plt>:
 1073170:      	adrp	x16, 0x10d0000
 1073174:      	ldr	x17, [x16, #0x7a8]
 1073178:      	add	x16, x16, #0x7a8
 107317c:      	br	x17

0000000001073180 <_Z25MTARMPMMusicSetFuncStructPvS_@plt>:
 1073180:      	adrp	x16, 0x10d0000
 1073184:      	ldr	x17, [x16, #0x7b0]
 1073188:      	add	x16, x16, #0x7b0
 107318c:      	br	x17

0000000001073190 <_Z22MTARMPMMusicSetLoopingPvi@plt>:
 1073190:      	adrp	x16, 0x10d0000
 1073194:      	ldr	x17, [x16, #0x7b8]
 1073198:      	add	x16, x16, #0x7b8
 107319c:      	br	x17

00000000010731a0 <_Z24MTARMPMMusicGetLoopCountPv@plt>:
 10731a0:      	adrp	x16, 0x10d0000
 10731a4:      	ldr	x17, [x16, #0x7c0]
 10731a8:      	add	x16, x16, #0x7c0
 10731ac:      	br	x17

00000000010731b0 <_Z23MTARMPMMusicGetPositionPv@plt>:
 10731b0:      	adrp	x16, 0x10d0000
 10731b4:      	ldr	x17, [x16, #0x7c8]
 10731b8:      	add	x16, x16, #0x7c8
 10731bc:      	br	x17

00000000010731c0 <_Z23MTARMPMMusicGetDurationPv@plt>:
 10731c0:      	adrp	x16, 0x10d0000
 10731c4:      	ldr	x17, [x16, #0x7d0]
 10731c8:      	add	x16, x16, #0x7d0
 10731cc:      	br	x17

00000000010731d0 <_Z19MTARMPMMusicDisposePv@plt>:
 10731d0:      	adrp	x16, 0x10d0000
 10731d4:      	ldr	x17, [x16, #0x7d8]
 10731d8:      	add	x16, x16, #0x7d8
 10731dc:      	br	x17

00000000010731e0 <_Z25MTARMPMDestroyMusicHandleRPv@plt>:
 10731e0:      	adrp	x16, 0x10d0000
 10731e4:      	ldr	x17, [x16, #0x7e0]
 10731e8:      	add	x16, x16, #0x7e0
 10731ec:      	br	x17

00000000010731f0 <_Z16MTARMPMMusicPlayPv@plt>:
 10731f0:      	adrp	x16, 0x10d0000
 10731f4:      	ldr	x17, [x16, #0x7e8]
 10731f8:      	add	x16, x16, #0x7e8
 10731fc:      	br	x17

0000000001073200 <_Z17MTARMPMMusicPausePv@plt>:
 1073200:      	adrp	x16, 0x10d0000
 1073204:      	ldr	x17, [x16, #0x7f0]
 1073208:      	add	x16, x16, #0x7f0
 107320c:      	br	x17

0000000001073210 <_Z16MTARMPMMusicStopPv@plt>:
 1073210:      	adrp	x16, 0x10d0000
 1073214:      	ldr	x17, [x16, #0x7f8]
 1073218:      	add	x16, x16, #0x7f8
 107321c:      	br	x17

0000000001073220 <_Z21MTARMPMMusicSetVolumePvf@plt>:
 1073220:      	adrp	x16, 0x10d0000
 1073224:      	ldr	x17, [x16, #0x800]
 1073228:      	add	x16, x16, #0x800
 107322c:      	br	x17

0000000001073230 <_Z23MTARMPMMusicSetPositionPvf@plt>:
 1073230:      	adrp	x16, 0x10d0000
 1073234:      	ldr	x17, [x16, #0x808]
 1073238:      	add	x16, x16, #0x808
 107323c:      	br	x17

0000000001073240 <_Z20MTARMPMMusicSetSpeedPvf@plt>:
 1073240:      	adrp	x16, 0x10d0000
 1073244:      	ldr	x17, [x16, #0x810]
 1073248:      	add	x16, x16, #0x810
 107324c:      	br	x17

0000000001073250 <_Z20MTARMPMMusicGetSpeedPv@plt>:
 1073250:      	adrp	x16, 0x10d0000
 1073254:      	ldr	x17, [x16, #0x818]
 1073258:      	add	x16, x16, #0x818
 107325c:      	br	x17

0000000001073260 <_ZNSt6__ndk113random_deviceclEv@plt>:
 1073260:      	adrp	x16, 0x10d0000
 1073264:      	ldr	x17, [x16, #0x820]
 1073268:      	add	x16, x16, #0x820
 107326c:      	br	x17

0000000001073270 <exp@plt>:
 1073270:      	adrp	x16, 0x10d0000
 1073274:      	ldr	x17, [x16, #0x828]
 1073278:      	add	x16, x16, #0x828
 107327c:      	br	x17

0000000001073280 <realloc@plt>:
 1073280:      	adrp	x16, 0x10d0000
 1073284:      	ldr	x17, [x16, #0x830]
 1073288:      	add	x16, x16, #0x830
 107328c:      	br	x17

0000000001073290 <wgpuDeviceGetLimits@plt>:
 1073290:      	adrp	x16, 0x10d0000
 1073294:      	ldr	x17, [x16, #0x838]
 1073298:      	add	x16, x16, #0x838
 107329c:      	br	x17

00000000010732a0 <_Z17ARSPMSkSvgDestroyPv@plt>:
 10732a0:      	adrp	x16, 0x10d0000
 10732a4:      	ldr	x17, [x16, #0x840]
 10732a8:      	add	x16, x16, #0x840
 10732ac:      	br	x17

00000000010732b0 <_Z16ARSPMSkCreateSvgPKvmb@plt>:
 10732b0:      	adrp	x16, 0x10d0000
 10732b4:      	ldr	x17, [x16, #0x848]
 10732b8:      	add	x16, x16, #0x848
 10732bc:      	br	x17

00000000010732c0 <_Z15ARSPMSkSvgScalePvff@plt>:
 10732c0:      	adrp	x16, 0x10d0000
 10732c4:      	ldr	x17, [x16, #0x850]
 10732c8:      	add	x16, x16, #0x850
 10732cc:      	br	x17

00000000010732d0 <_Z16ARSPMSkSvgRenderPvR12SVG2RGBADataii@plt>:
 10732d0:      	adrp	x16, 0x10d0000
 10732d4:      	ldr	x17, [x16, #0x858]
 10732d8:      	add	x16, x16, #0x858
 10732dc:      	br	x17

00000000010732e0 <_Z9ARSPMFreePv@plt>:
 10732e0:      	adrp	x16, 0x10d0000
 10732e4:      	ldr	x17, [x16, #0x860]
 10732e8:      	add	x16, x16, #0x860
 10732ec:      	br	x17

00000000010732f0 <_ZNSt6__ndk16localeC1Ev@plt>:
 10732f0:      	adrp	x16, 0x10d0000
 10732f4:      	ldr	x17, [x16, #0x868]
 10732f8:      	add	x16, x16, #0x868
 10732fc:      	br	x17

0000000001073300 <_ZNSt6__ndk111regex_errorC1ENS_15regex_constants10error_typeE@plt>:
 1073300:      	adrp	x16, 0x10d0000
 1073304:      	ldr	x17, [x16, #0x870]
 1073308:      	add	x16, x16, #0x870
 107330c:      	br	x17

0000000001073310 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc@plt>:
 1073310:      	adrp	x16, 0x10d0000
 1073314:      	ldr	x17, [x16, #0x878]
 1073318:      	add	x16, x16, #0x878
 107331c:      	br	x17

0000000001073320 <_ZNKSt6__ndk16locale4nameEv@plt>:
 1073320:      	adrp	x16, 0x10d0000
 1073324:      	ldr	x17, [x16, #0x880]
 1073328:      	add	x16, x16, #0x880
 107332c:      	br	x17

0000000001073330 <_ZNSt6__ndk120__get_collation_nameEPKc@plt>:
 1073330:      	adrp	x16, 0x10d0000
 1073334:      	ldr	x17, [x16, #0x888]
 1073338:      	add	x16, x16, #0x888
 107333c:      	br	x17

0000000001073340 <_ZNSt6__ndk115__get_classnameEPKcb@plt>:
 1073340:      	adrp	x16, 0x10d0000
 1073344:      	ldr	x17, [x16, #0x890]
 1073348:      	add	x16, x16, #0x890
 107334c:      	br	x17

0000000001073350 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEv@plt>:
 1073350:      	adrp	x16, 0x10d0000
 1073354:      	ldr	x17, [x16, #0x898]
 1073358:      	add	x16, x16, #0x898
 107335c:      	br	x17

0000000001073360 <_ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
 1073360:      	adrp	x16, 0x10d0000
 1073364:      	ldr	x17, [x16, #0x8a0]
 1073368:      	add	x16, x16, #0x8a0
 107336c:      	br	x17

0000000001073370 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm@plt>:
 1073370:      	adrp	x16, 0x10d0000
 1073374:      	ldr	x17, [x16, #0x8a8]
 1073378:      	add	x16, x16, #0x8a8
 107337c:      	br	x17

0000000001073380 <_ZNSt6__ndk14stofERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPm@plt>:
 1073380:      	adrp	x16, 0x10d0000
 1073384:      	ldr	x17, [x16, #0x8b0]
 1073388:      	add	x16, x16, #0x8b0
 107338c:      	br	x17

0000000001073390 <_Z23ARSPMSkSvgTransformPathPvfffff@plt>:
 1073390:      	adrp	x16, 0x10d0000
 1073394:      	ldr	x17, [x16, #0x8b8]
 1073398:      	add	x16, x16, #0x8b8
 107339c:      	br	x17

00000000010733a0 <_Z21ARSPMSkSvgSegmentPathPvffbf@plt>:
 10733a0:      	adrp	x16, 0x10d0000
 10733a4:      	ldr	x17, [x16, #0x8c0]
 10733a8:      	add	x16, x16, #0x8c0
 10733ac:      	br	x17

00000000010733b0 <_Z20ARSPMTaperStrokePathPvf@plt>:
 10733b0:      	adrp	x16, 0x10d0000
 10733b4:      	ldr	x17, [x16, #0x8c8]
 10733b8:      	add	x16, x16, #0x8c8
 10733bc:      	br	x17

00000000010733c0 <_Z14ARSPMSkSvgMovePvff@plt>:
 10733c0:      	adrp	x16, 0x10d0000
 10733c4:      	ldr	x17, [x16, #0x8d0]
 10733c8:      	add	x16, x16, #0x8d0
 10733cc:      	br	x17

00000000010733d0 <strcpy@plt>:
 10733d0:      	adrp	x16, 0x10d0000
 10733d4:      	ldr	x17, [x16, #0x8d8]
 10733d8:      	add	x16, x16, #0x8d8
 10733dc:      	br	x17

00000000010733e0 <_Z21ARSPMLoadPlatformFontRK14ARSPMTextParamR13ARSPMTextData@plt>:
 10733e0:      	adrp	x16, 0x10d0000
 10733e4:      	ldr	x17, [x16, #0x8e0]
 10733e8:      	add	x16, x16, #0x8e0
 10733ec:      	br	x17

00000000010733f0 <_ZN8mtlabar39JniHelper19getStaticMethodInfoERNS_14JniMethodInfo_EPKcS4_S4_@plt>:
 10733f0:      	adrp	x16, 0x10d0000
 10733f4:      	ldr	x17, [x16, #0x8e8]
 10733f8:      	add	x16, x16, #0x8e8
 10733fc:      	br	x17

0000000001073400 <calloc@plt>:
 1073400:      	adrp	x16, 0x10d0000
 1073404:      	ldr	x17, [x16, #0x8f0]
 1073408:      	add	x16, x16, #0x8f0
 107340c:      	br	x17

0000000001073410 <abort@plt>:
 1073410:      	adrp	x16, 0x10d0000
 1073414:      	ldr	x17, [x16, #0x8f8]
 1073418:      	add	x16, x16, #0x8f8
 107341c:      	br	x17

0000000001073420 <fopen@plt>:
 1073420:      	adrp	x16, 0x10d0000
 1073424:      	ldr	x17, [x16, #0x900]
 1073428:      	add	x16, x16, #0x900
 107342c:      	br	x17

0000000001073430 <ftell@plt>:
 1073430:      	adrp	x16, 0x10d0000
 1073434:      	ldr	x17, [x16, #0x908]
 1073438:      	add	x16, x16, #0x908
 107343c:      	br	x17

0000000001073440 <fseek@plt>:
 1073440:      	adrp	x16, 0x10d0000
 1073444:      	ldr	x17, [x16, #0x910]
 1073448:      	add	x16, x16, #0x910
 107344c:      	br	x17

0000000001073450 <fflush@plt>:
 1073450:      	adrp	x16, 0x10d0000
 1073454:      	ldr	x17, [x16, #0x918]
 1073458:      	add	x16, x16, #0x918
 107345c:      	br	x17

0000000001073460 <fclose@plt>:
 1073460:      	adrp	x16, 0x10d0000
 1073464:      	ldr	x17, [x16, #0x920]
 1073468:      	add	x16, x16, #0x920
 107346c:      	br	x17

0000000001073470 <stat@plt>:
 1073470:      	adrp	x16, 0x10d0000
 1073474:      	ldr	x17, [x16, #0x928]
 1073478:      	add	x16, x16, #0x928
 107347c:      	br	x17

0000000001073480 <mkdir@plt>:
 1073480:      	adrp	x16, 0x10d0000
 1073484:      	ldr	x17, [x16, #0x930]
 1073488:      	add	x16, x16, #0x930
 107348c:      	br	x17

0000000001073490 <fprintf@plt>:
 1073490:      	adrp	x16, 0x10d0000
 1073494:      	ldr	x17, [x16, #0x938]
 1073498:      	add	x16, x16, #0x938
 107349c:      	br	x17

00000000010734a0 <fileno@plt>:
 10734a0:      	adrp	x16, 0x10d0000
 10734a4:      	ldr	x17, [x16, #0x940]
 10734a8:      	add	x16, x16, #0x940
 10734ac:      	br	x17

00000000010734b0 <fstat@plt>:
 10734b0:      	adrp	x16, 0x10d0000
 10734b4:      	ldr	x17, [x16, #0x948]
 10734b8:      	add	x16, x16, #0x948
 10734bc:      	br	x17

00000000010734c0 <munmap@plt>:
 10734c0:      	adrp	x16, 0x10d0000
 10734c4:      	ldr	x17, [x16, #0x950]
 10734c8:      	add	x16, x16, #0x950
 10734cc:      	br	x17

00000000010734d0 <mmap@plt>:
 10734d0:      	adrp	x16, 0x10d0000
 10734d4:      	ldr	x17, [x16, #0x958]
 10734d8:      	add	x16, x16, #0x958
 10734dc:      	br	x17

00000000010734e0 <__pread_chk@plt>:
 10734e0:      	adrp	x16, 0x10d0000
 10734e4:      	ldr	x17, [x16, #0x960]
 10734e8:      	add	x16, x16, #0x960
 10734ec:      	br	x17

00000000010734f0 <sem_destroy@plt>:
 10734f0:      	adrp	x16, 0x10d0000
 10734f4:      	ldr	x17, [x16, #0x968]
 10734f8:      	add	x16, x16, #0x968
 10734fc:      	br	x17

0000000001073500 <sem_init@plt>:
 1073500:      	adrp	x16, 0x10d0000
 1073504:      	ldr	x17, [x16, #0x970]
 1073508:      	add	x16, x16, #0x970
 107350c:      	br	x17

0000000001073510 <sem_post@plt>:
 1073510:      	adrp	x16, 0x10d0000
 1073514:      	ldr	x17, [x16, #0x978]
 1073518:      	add	x16, x16, #0x978
 107351c:      	br	x17

0000000001073520 <sem_wait@plt>:
 1073520:      	adrp	x16, 0x10d0000
 1073524:      	ldr	x17, [x16, #0x980]
 1073528:      	add	x16, x16, #0x980
 107352c:      	br	x17

0000000001073530 <__errno@plt>:
 1073530:      	adrp	x16, 0x10d0000
 1073534:      	ldr	x17, [x16, #0x988]
 1073538:      	add	x16, x16, #0x988
 107353c:      	br	x17

0000000001073540 <hypotf@plt>:
 1073540:      	adrp	x16, 0x10d0000
 1073544:      	ldr	x17, [x16, #0x990]
 1073548:      	add	x16, x16, #0x990
 107354c:      	br	x17

0000000001073550 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
 1073550:      	adrp	x16, 0x10d0000
 1073554:      	ldr	x17, [x16, #0x998]
 1073558:      	add	x16, x16, #0x998
 107355c:      	br	x17

0000000001073560 <wgpuTextureViewSetLabel@plt>:
 1073560:      	adrp	x16, 0x10d0000
 1073564:      	ldr	x17, [x16, #0x9a0]
 1073568:      	add	x16, x16, #0x9a0
 107356c:      	br	x17

0000000001073570 <tan@plt>:
 1073570:      	adrp	x16, 0x10d0000
 1073574:      	ldr	x17, [x16, #0x9a8]
 1073578:      	add	x16, x16, #0x9a8
 107357c:      	br	x17

0000000001073580 <_ZN8mtlabar39JniHelper6getEnvEv@plt>:
 1073580:      	adrp	x16, 0x10d0000
 1073584:      	ldr	x17, [x16, #0x9b0]
 1073588:      	add	x16, x16, #0x9b0
 107358c:      	br	x17

0000000001073590 <pthread_getspecific@plt>:
 1073590:      	adrp	x16, 0x10d0000
 1073594:      	ldr	x17, [x16, #0x9b8]
 1073598:      	add	x16, x16, #0x9b8
 107359c:      	br	x17

00000000010735a0 <_ZN8mtlabar39JniHelper8cacheEnvEP7_JavaVM@plt>:
 10735a0:      	adrp	x16, 0x10d0000
 10735a4:      	ldr	x17, [x16, #0x9c0]
 10735a8:      	add	x16, x16, #0x9c0
 10735ac:      	br	x17

00000000010735b0 <_ZN8mtlabar39JniHelper19getGLXBitmapClassIDEv@plt>:
 10735b0:      	adrp	x16, 0x10d0000
 10735b4:      	ldr	x17, [x16, #0x9c8]
 10735b8:      	add	x16, x16, #0x9c8
 10735bc:      	br	x17

00000000010735c0 <pthread_key_create@plt>:
 10735c0:      	adrp	x16, 0x10d0000
 10735c4:      	ldr	x17, [x16, #0x9d0]
 10735c8:      	add	x16, x16, #0x9d0
 10735cc:      	br	x17

00000000010735d0 <_ZN8mtlabar39JniHelper19cacheGLXBitmapClassEv@plt>:
 10735d0:      	adrp	x16, 0x10d0000
 10735d4:      	ldr	x17, [x16, #0x9d8]
 10735d8:      	add	x16, x16, #0x9d8
 10735dc:      	br	x17

00000000010735e0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERj@plt>:
 10735e0:      	adrp	x16, 0x10d0000
 10735e4:      	ldr	x17, [x16, #0x9e0]
 10735e8:      	add	x16, x16, #0x9e0
 10735ec:      	br	x17

00000000010735f0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEj@plt>:
 10735f0:      	adrp	x16, 0x10d0000
 10735f4:      	ldr	x17, [x16, #0x9e8]
 10735f8:      	add	x16, x16, #0x9e8
 10735fc:      	br	x17

0000000001073600 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm@plt>:
 1073600:      	adrp	x16, 0x10d0000
 1073604:      	ldr	x17, [x16, #0x9f0]
 1073608:      	add	x16, x16, #0x9f0
 107360c:      	br	x17

0000000001073610 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb@plt>:
 1073610:      	adrp	x16, 0x10d0000
 1073614:      	ldr	x17, [x16, #0x9f8]
 1073618:      	add	x16, x16, #0x9f8
 107361c:      	br	x17

0000000001073620 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEd@plt>:
 1073620:      	adrp	x16, 0x10d0000
 1073624:      	ldr	x17, [x16, #0xa00]
 1073628:      	add	x16, x16, #0xa00
 107362c:      	br	x17

0000000001073630 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5writeEPKwl@plt>:
 1073630:      	adrp	x16, 0x10d0000
 1073634:      	ldr	x17, [x16, #0xa08]
 1073638:      	add	x16, x16, #0xa08
 107363c:      	br	x17

0000000001073640 <strtod@plt>:
 1073640:      	adrp	x16, 0x10d0000
 1073644:      	ldr	x17, [x16, #0xa10]
 1073648:      	add	x16, x16, #0xa10
 107364c:      	br	x17

0000000001073650 <fread@plt>:
 1073650:      	adrp	x16, 0x10d0000
 1073654:      	ldr	x17, [x16, #0xa18]
 1073658:      	add	x16, x16, #0xa18
 107365c:      	br	x17

0000000001073660 <ferror@plt>:
 1073660:      	adrp	x16, 0x10d0000
 1073664:      	ldr	x17, [x16, #0xa20]
 1073668:      	add	x16, x16, #0xa20
 107366c:      	br	x17

0000000001073670 <strstr@plt>:
 1073670:      	adrp	x16, 0x10d0000
 1073674:      	ldr	x17, [x16, #0xa28]
 1073678:      	add	x16, x16, #0xa28
 107367c:      	br	x17

0000000001073680 <setlocale@plt>:
 1073680:      	adrp	x16, 0x10d0000
 1073684:      	ldr	x17, [x16, #0xa30]
 1073688:      	add	x16, x16, #0xa30
 107368c:      	br	x17

0000000001073690 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
 1073690:      	adrp	x16, 0x10d0000
 1073694:      	ldr	x17, [x16, #0xa38]
 1073698:      	add	x16, x16, #0xa38
 107369c:      	br	x17

00000000010736a0 <localtime@plt>:
 10736a0:      	adrp	x16, 0x10d0000
 10736a4:      	ldr	x17, [x16, #0xa40]
 10736a8:      	add	x16, x16, #0xa40
 10736ac:      	br	x17

00000000010736b0 <inflateReset@plt>:
 10736b0:      	adrp	x16, 0x10d0000
 10736b4:      	ldr	x17, [x16, #0xa48]
 10736b8:      	add	x16, x16, #0xa48
 10736bc:      	br	x17

00000000010736c0 <adler32@plt>:
 10736c0:      	adrp	x16, 0x10d0000
 10736c4:      	ldr	x17, [x16, #0xa50]
 10736c8:      	add	x16, x16, #0xa50
 10736cc:      	br	x17

00000000010736d0 <inflateEnd@plt>:
 10736d0:      	adrp	x16, 0x10d0000
 10736d4:      	ldr	x17, [x16, #0xa58]
 10736d8:      	add	x16, x16, #0xa58
 10736dc:      	br	x17

00000000010736e0 <crc32@plt>:
 10736e0:      	adrp	x16, 0x10d0000
 10736e4:      	ldr	x17, [x16, #0xa60]
 10736e8:      	add	x16, x16, #0xa60
 10736ec:      	br	x17

00000000010736f0 <inflateInit_@plt>:
 10736f0:      	adrp	x16, 0x10d0000
 10736f4:      	ldr	x17, [x16, #0xa68]
 10736f8:      	add	x16, x16, #0xa68
 10736fc:      	br	x17

0000000001073700 <inflateReset2@plt>:
 1073700:      	adrp	x16, 0x10d0000
 1073704:      	ldr	x17, [x16, #0xa70]
 1073708:      	add	x16, x16, #0xa70
 107370c:      	br	x17

0000000001073710 <inflate@plt>:
 1073710:      	adrp	x16, 0x10d0000
 1073714:      	ldr	x17, [x16, #0xa78]
 1073718:      	add	x16, x16, #0xa78
 107371c:      	br	x17

0000000001073720 <inflateInit2_@plt>:
 1073720:      	adrp	x16, 0x10d0000
 1073724:      	ldr	x17, [x16, #0xa80]
 1073728:      	add	x16, x16, #0xa80
 107372c:      	br	x17

0000000001073730 <RotatePlane270@plt>:
 1073730:      	adrp	x16, 0x10d0000
 1073734:      	ldr	x17, [x16, #0xa88]
 1073738:      	add	x16, x16, #0xa88
 107373c:      	br	x17

0000000001073740 <RotatePlane90@plt>:
 1073740:      	adrp	x16, 0x10d0000
 1073744:      	ldr	x17, [x16, #0xa90]
 1073748:      	add	x16, x16, #0xa90
 107374c:      	br	x17

0000000001073750 <ARGBRotate@plt>:
 1073750:      	adrp	x16, 0x10d0000
 1073754:      	ldr	x17, [x16, #0xa98]
 1073758:      	add	x16, x16, #0xa98
 107375c:      	br	x17

0000000001073760 <ARGBMirror@plt>:
 1073760:      	adrp	x16, 0x10d0000
 1073764:      	ldr	x17, [x16, #0xaa0]
 1073768:      	add	x16, x16, #0xaa0
 107376c:      	br	x17

0000000001073770 <I400Mirror@plt>:
 1073770:      	adrp	x16, 0x10d0000
 1073774:      	ldr	x17, [x16, #0xaa8]
 1073778:      	add	x16, x16, #0xaa8
 107377c:      	br	x17

0000000001073780 <RotatePlane180@plt>:
 1073780:      	adrp	x16, 0x10d0000
 1073784:      	ldr	x17, [x16, #0xab0]
 1073788:      	add	x16, x16, #0xab0
 107378c:      	br	x17

0000000001073790 <ARGBScale@plt>:
 1073790:      	adrp	x16, 0x10d0000
 1073794:      	ldr	x17, [x16, #0xab8]
 1073798:      	add	x16, x16, #0xab8
 107379c:      	br	x17

00000000010737a0 <strerror@plt>:
 10737a0:      	adrp	x16, 0x10d0000
 10737a4:      	ldr	x17, [x16, #0xac0]
 10737a8:      	add	x16, x16, #0xac0
 10737ac:      	br	x17

00000000010737b0 <freopen@plt>:
 10737b0:      	adrp	x16, 0x10d0000
 10737b4:      	ldr	x17, [x16, #0xac8]
 10737b8:      	add	x16, x16, #0xac8
 10737bc:      	br	x17

00000000010737c0 <getc@plt>:
 10737c0:      	adrp	x16, 0x10d0000
 10737c4:      	ldr	x17, [x16, #0xad0]
 10737c8:      	add	x16, x16, #0xad0
 10737cc:      	br	x17

00000000010737d0 <feof@plt>:
 10737d0:      	adrp	x16, 0x10d0000
 10737d4:      	ldr	x17, [x16, #0xad8]
 10737d8:      	add	x16, x16, #0xad8
 10737dc:      	br	x17

00000000010737e0 <longjmp@plt>:
 10737e0:      	adrp	x16, 0x10d0000
 10737e4:      	ldr	x17, [x16, #0xae0]
 10737e8:      	add	x16, x16, #0xae0
 10737ec:      	br	x17

00000000010737f0 <setjmp@plt>:
 10737f0:      	adrp	x16, 0x10d0000
 10737f4:      	ldr	x17, [x16, #0xae8]
 10737f8:      	add	x16, x16, #0xae8
 10737fc:      	br	x17

0000000001073800 <strpbrk@plt>:
 1073800:      	adrp	x16, 0x10d0000
 1073804:      	ldr	x17, [x16, #0xaf0]
 1073808:      	add	x16, x16, #0xaf0
 107380c:      	br	x17

0000000001073810 <ldexp@plt>:
 1073810:      	adrp	x16, 0x10d0000
 1073814:      	ldr	x17, [x16, #0xaf8]
 1073818:      	add	x16, x16, #0xaf8
 107381c:      	br	x17

0000000001073820 <time@plt>:
 1073820:      	adrp	x16, 0x10d0000
 1073824:      	ldr	x17, [x16, #0xb00]
 1073828:      	add	x16, x16, #0xb00
 107382c:      	br	x17

0000000001073830 <strcoll@plt>:
 1073830:      	adrp	x16, 0x10d0000
 1073834:      	ldr	x17, [x16, #0xb08]
 1073838:      	add	x16, x16, #0xb08
 107383c:      	br	x17

0000000001073840 <pthread_join@plt>:
 1073840:      	adrp	x16, 0x10d0000
 1073844:      	ldr	x17, [x16, #0xb10]
 1073848:      	add	x16, x16, #0xb10
 107384c:      	br	x17

0000000001073850 <sysconf@plt>:
 1073850:      	adrp	x16, 0x10d0000
 1073854:      	ldr	x17, [x16, #0xb18]
 1073858:      	add	x16, x16, #0xb18
 107385c:      	br	x17

0000000001073860 <AMediaFormat_setString@plt>:
 1073860:      	adrp	x16, 0x10d0000
 1073864:      	ldr	x17, [x16, #0xb20]
 1073868:      	add	x16, x16, #0xb20
 107386c:      	br	x17

0000000001073870 <AMediaCodec_configure@plt>:
 1073870:      	adrp	x16, 0x10d0000
 1073874:      	ldr	x17, [x16, #0xb28]
 1073878:      	add	x16, x16, #0xb28
 107387c:      	br	x17

0000000001073880 <AMediaCodec_start@plt>:
 1073880:      	adrp	x16, 0x10d0000
 1073884:      	ldr	x17, [x16, #0xb30]
 1073888:      	add	x16, x16, #0xb30
 107388c:      	br	x17

0000000001073890 <AMediaFormat_delete@plt>:
 1073890:      	adrp	x16, 0x10d0000
 1073894:      	ldr	x17, [x16, #0xb38]
 1073898:      	add	x16, x16, #0xb38
 107389c:      	br	x17

00000000010738a0 <AMediaCodec_stop@plt>:
 10738a0:      	adrp	x16, 0x10d0000
 10738a4:      	ldr	x17, [x16, #0xb40]
 10738a8:      	add	x16, x16, #0xb40
 10738ac:      	br	x17

00000000010738b0 <AMediaCodec_createDecoderByType@plt>:
 10738b0:      	adrp	x16, 0x10d0000
 10738b4:      	ldr	x17, [x16, #0xb48]
 10738b8:      	add	x16, x16, #0xb48
 10738bc:      	br	x17

00000000010738c0 <AMediaCodec_delete@plt>:
 10738c0:      	adrp	x16, 0x10d0000
 10738c4:      	ldr	x17, [x16, #0xb50]
 10738c8:      	add	x16, x16, #0xb50
 10738cc:      	br	x17

00000000010738d0 <AMediaFormat_setInt32@plt>:
 10738d0:      	adrp	x16, 0x10d0000
 10738d4:      	ldr	x17, [x16, #0xb58]
 10738d8:      	add	x16, x16, #0xb58
 10738dc:      	br	x17

00000000010738e0 <AMediaFormat_new@plt>:
 10738e0:      	adrp	x16, 0x10d0000
 10738e4:      	ldr	x17, [x16, #0xb60]
 10738e8:      	add	x16, x16, #0xb60
 10738ec:      	br	x17

00000000010738f0 <av_display_rotation_get@plt>:
 10738f0:      	adrp	x16, 0x10d0000
 10738f4:      	ldr	x17, [x16, #0xb68]
 10738f8:      	add	x16, x16, #0xb68
 10738fc:      	br	x17

0000000001073900 <av_mediacodec_release_buffer@plt>:
 1073900:      	adrp	x16, 0x10d0000
 1073904:      	ldr	x17, [x16, #0xb70]
 1073908:      	add	x16, x16, #0xb70
 107390c:      	br	x17

0000000001073910 <av_packet_side_data_get@plt>:
 1073910:      	adrp	x16, 0x10d0000
 1073914:      	ldr	x17, [x16, #0xb78]
 1073918:      	add	x16, x16, #0xb78
 107391c:      	br	x17

0000000001073920 <avcodec_get_hw_config@plt>:
 1073920:      	adrp	x16, 0x10d0000
 1073924:      	ldr	x17, [x16, #0xb80]
 1073928:      	add	x16, x16, #0xb80
 107392c:      	br	x17

0000000001073930 <av_get_pix_fmt_name@plt>:
 1073930:      	adrp	x16, 0x10d0000
 1073934:      	ldr	x17, [x16, #0xb88]
 1073938:      	add	x16, x16, #0xb88
 107393c:      	br	x17

0000000001073940 <av_hwframe_transfer_data@plt>:
 1073940:      	adrp	x16, 0x10d0000
 1073944:      	ldr	x17, [x16, #0xb90]
 1073948:      	add	x16, x16, #0xb90
 107394c:      	br	x17

0000000001073950 <av_hwdevice_ctx_create@plt>:
 1073950:      	adrp	x16, 0x10d0000
 1073954:      	ldr	x17, [x16, #0xb98]
 1073958:      	add	x16, x16, #0xb98
 107395c:      	br	x17

0000000001073960 <av_jni_set_java_vm@plt>:
 1073960:      	adrp	x16, 0x10d0000
 1073964:      	ldr	x17, [x16, #0xba0]
 1073968:      	add	x16, x16, #0xba0
 107396c:      	br	x17

0000000001073970 <av_hwdevice_get_type_name@plt>:
 1073970:      	adrp	x16, 0x10d0000
 1073974:      	ldr	x17, [x16, #0xba8]
 1073978:      	add	x16, x16, #0xba8
 107397c:      	br	x17

0000000001073980 <av_hwdevice_ctx_alloc@plt>:
 1073980:      	adrp	x16, 0x10d0000
 1073984:      	ldr	x17, [x16, #0xbb0]
 1073988:      	add	x16, x16, #0xbb0
 107398c:      	br	x17

0000000001073990 <av_buffer_unref@plt>:
 1073990:      	adrp	x16, 0x10d0000
 1073994:      	ldr	x17, [x16, #0xbb8]
 1073998:      	add	x16, x16, #0xbb8
 107399c:      	br	x17

00000000010739a0 <av_hwdevice_ctx_init@plt>:
 10739a0:      	adrp	x16, 0x10d0000
 10739a4:      	ldr	x17, [x16, #0xbc0]
 10739a8:      	add	x16, x16, #0xbc0
 10739ac:      	br	x17

00000000010739b0 <av_hwframe_map@plt>:
 10739b0:      	adrp	x16, 0x10d0000
 10739b4:      	ldr	x17, [x16, #0xbc8]
 10739b8:      	add	x16, x16, #0xbc8
 10739bc:      	br	x17

00000000010739c0 <_ZNKSt6__ndk16locale9has_facetERNS0_2idE@plt>:
 10739c0:      	adrp	x16, 0x10d0000
 10739c4:      	ldr	x17, [x16, #0xbd0]
 10739c8:      	add	x16, x16, #0xbd0
 10739cc:      	br	x17

00000000010739d0 <_ZNSt6__ndk16locale5facetD2Ev@plt>:
 10739d0:      	adrp	x16, 0x10d0000
 10739d4:      	ldr	x17, [x16, #0xbd8]
 10739d8:      	add	x16, x16, #0xbd8
 10739dc:      	br	x17

00000000010739e0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEmc@plt>:
 10739e0:      	adrp	x16, 0x10d0000
 10739e4:      	ldr	x17, [x16, #0xbe0]
 10739e8:      	add	x16, x16, #0xbe0
 10739ec:      	br	x17

00000000010739f0 <_ZNSt13runtime_errorD2Ev@plt>:
 10739f0:      	adrp	x16, 0x10d0000
 10739f4:      	ldr	x17, [x16, #0xbe8]
 10739f8:      	add	x16, x16, #0xbe8
 10739fc:      	br	x17

0000000001073a00 <_ZNSt13runtime_errorC2EPKc@plt>:
 1073a00:      	adrp	x16, 0x10d0000
 1073a04:      	ldr	x17, [x16, #0xbf0]
 1073a08:      	add	x16, x16, #0xbf0
 1073a0c:      	br	x17

0000000001073a10 <glGenTextures@plt>:
 1073a10:      	adrp	x16, 0x10d0000
 1073a14:      	ldr	x17, [x16, #0xbf8]
 1073a18:      	add	x16, x16, #0xbf8
 1073a1c:      	br	x17

0000000001073a20 <glBindTexture@plt>:
 1073a20:      	adrp	x16, 0x10d0000
 1073a24:      	ldr	x17, [x16, #0xc00]
 1073a28:      	add	x16, x16, #0xc00
 1073a2c:      	br	x17

0000000001073a30 <glTexParameteri@plt>:
 1073a30:      	adrp	x16, 0x10d0000
 1073a34:      	ldr	x17, [x16, #0xc08]
 1073a38:      	add	x16, x16, #0xc08
 1073a3c:      	br	x17

0000000001073a40 <glGetError@plt>:
 1073a40:      	adrp	x16, 0x10d0000
 1073a44:      	ldr	x17, [x16, #0xc10]
 1073a48:      	add	x16, x16, #0xc10
 1073a4c:      	br	x17

0000000001073a50 <glDeleteTextures@plt>:
 1073a50:      	adrp	x16, 0x10d0000
 1073a54:      	ldr	x17, [x16, #0xc18]
 1073a58:      	add	x16, x16, #0xc18
 1073a5c:      	br	x17

0000000001073a60 <wgpuDeviceReference@plt>:
 1073a60:      	adrp	x16, 0x10d0000
 1073a64:      	ldr	x17, [x16, #0xc20]
 1073a68:      	add	x16, x16, #0xc20
 1073a6c:      	br	x17

0000000001073a70 <wgpuDeviceGetAdapterProperties@plt>:
 1073a70:      	adrp	x16, 0x10d0000
 1073a74:      	ldr	x17, [x16, #0xc28]
 1073a78:      	add	x16, x16, #0xc28
 1073a7c:      	br	x17

0000000001073a80 <wgpuCommandEncoderSetLabel@plt>:
 1073a80:      	adrp	x16, 0x10d0000
 1073a84:      	ldr	x17, [x16, #0xc30]
 1073a88:      	add	x16, x16, #0xc30
 1073a8c:      	br	x17

0000000001073a90 <wgpuTextureDestroy@plt>:
 1073a90:      	adrp	x16, 0x10d0000
 1073a94:      	ldr	x17, [x16, #0xc38]
 1073a98:      	add	x16, x16, #0xc38
 1073a9c:      	br	x17

0000000001073aa0 <wgpuBufferGetMapState@plt>:
 1073aa0:      	adrp	x16, 0x10d0000
 1073aa4:      	ldr	x17, [x16, #0xc40]
 1073aa8:      	add	x16, x16, #0xc40
 1073aac:      	br	x17

0000000001073ab0 <wgpuCommandEncoderCopyBufferToTexture@plt>:
 1073ab0:      	adrp	x16, 0x10d0000
 1073ab4:      	ldr	x17, [x16, #0xc48]
 1073ab8:      	add	x16, x16, #0xc48
 1073abc:      	br	x17

0000000001073ac0 <glCreateProgram@plt>:
 1073ac0:      	adrp	x16, 0x10d0000
 1073ac4:      	ldr	x17, [x16, #0xc50]
 1073ac8:      	add	x16, x16, #0xc50
 1073acc:      	br	x17

0000000001073ad0 <glAttachShader@plt>:
 1073ad0:      	adrp	x16, 0x10d0000
 1073ad4:      	ldr	x17, [x16, #0xc58]
 1073ad8:      	add	x16, x16, #0xc58
 1073adc:      	br	x17

0000000001073ae0 <glLinkProgram@plt>:
 1073ae0:      	adrp	x16, 0x10d0000
 1073ae4:      	ldr	x17, [x16, #0xc60]
 1073ae8:      	add	x16, x16, #0xc60
 1073aec:      	br	x17

0000000001073af0 <glGetProgramiv@plt>:
 1073af0:      	adrp	x16, 0x10d0000
 1073af4:      	ldr	x17, [x16, #0xc68]
 1073af8:      	add	x16, x16, #0xc68
 1073afc:      	br	x17

0000000001073b00 <glDeleteShader@plt>:
 1073b00:      	adrp	x16, 0x10d0000
 1073b04:      	ldr	x17, [x16, #0xc70]
 1073b08:      	add	x16, x16, #0xc70
 1073b0c:      	br	x17

0000000001073b10 <glGetUniformLocation@plt>:
 1073b10:      	adrp	x16, 0x10d0000
 1073b14:      	ldr	x17, [x16, #0xc78]
 1073b18:      	add	x16, x16, #0xc78
 1073b1c:      	br	x17

0000000001073b20 <glGetProgramInfoLog@plt>:
 1073b20:      	adrp	x16, 0x10d0000
 1073b24:      	ldr	x17, [x16, #0xc80]
 1073b28:      	add	x16, x16, #0xc80
 1073b2c:      	br	x17

0000000001073b30 <glDeleteProgram@plt>:
 1073b30:      	adrp	x16, 0x10d0000
 1073b34:      	ldr	x17, [x16, #0xc88]
 1073b38:      	add	x16, x16, #0xc88
 1073b3c:      	br	x17

0000000001073b40 <glCreateShader@plt>:
 1073b40:      	adrp	x16, 0x10d0000
 1073b44:      	ldr	x17, [x16, #0xc90]
 1073b48:      	add	x16, x16, #0xc90
 1073b4c:      	br	x17

0000000001073b50 <glShaderSource@plt>:
 1073b50:      	adrp	x16, 0x10d0000
 1073b54:      	ldr	x17, [x16, #0xc98]
 1073b58:      	add	x16, x16, #0xc98
 1073b5c:      	br	x17

0000000001073b60 <glCompileShader@plt>:
 1073b60:      	adrp	x16, 0x10d0000
 1073b64:      	ldr	x17, [x16, #0xca0]
 1073b68:      	add	x16, x16, #0xca0
 1073b6c:      	br	x17

0000000001073b70 <glGetShaderiv@plt>:
 1073b70:      	adrp	x16, 0x10d0000
 1073b74:      	ldr	x17, [x16, #0xca8]
 1073b78:      	add	x16, x16, #0xca8
 1073b7c:      	br	x17

0000000001073b80 <glGetShaderInfoLog@plt>:
 1073b80:      	adrp	x16, 0x10d0000
 1073b84:      	ldr	x17, [x16, #0xcb0]
 1073b88:      	add	x16, x16, #0xcb0
 1073b8c:      	br	x17

0000000001073b90 <glGenVertexArrays@plt>:
 1073b90:      	adrp	x16, 0x10d0000
 1073b94:      	ldr	x17, [x16, #0xcb8]
 1073b98:      	add	x16, x16, #0xcb8
 1073b9c:      	br	x17

0000000001073ba0 <glBindVertexArray@plt>:
 1073ba0:      	adrp	x16, 0x10d0000
 1073ba4:      	ldr	x17, [x16, #0xcc0]
 1073ba8:      	add	x16, x16, #0xcc0
 1073bac:      	br	x17

0000000001073bb0 <glGenBuffers@plt>:
 1073bb0:      	adrp	x16, 0x10d0000
 1073bb4:      	ldr	x17, [x16, #0xcc8]
 1073bb8:      	add	x16, x16, #0xcc8
 1073bbc:      	br	x17

0000000001073bc0 <glBindBuffer@plt>:
 1073bc0:      	adrp	x16, 0x10d0000
 1073bc4:      	ldr	x17, [x16, #0xcd0]
 1073bc8:      	add	x16, x16, #0xcd0
 1073bcc:      	br	x17

0000000001073bd0 <glBufferData@plt>:
 1073bd0:      	adrp	x16, 0x10d0000
 1073bd4:      	ldr	x17, [x16, #0xcd8]
 1073bd8:      	add	x16, x16, #0xcd8
 1073bdc:      	br	x17

0000000001073be0 <glVertexAttribPointer@plt>:
 1073be0:      	adrp	x16, 0x10d0000
 1073be4:      	ldr	x17, [x16, #0xce0]
 1073be8:      	add	x16, x16, #0xce0
 1073bec:      	br	x17

0000000001073bf0 <glEnableVertexAttribArray@plt>:
 1073bf0:      	adrp	x16, 0x10d0000
 1073bf4:      	ldr	x17, [x16, #0xce8]
 1073bf8:      	add	x16, x16, #0xce8
 1073bfc:      	br	x17

0000000001073c00 <glBindFramebuffer@plt>:
 1073c00:      	adrp	x16, 0x10d0000
 1073c04:      	ldr	x17, [x16, #0xcf0]
 1073c08:      	add	x16, x16, #0xcf0
 1073c0c:      	br	x17

0000000001073c10 <glFramebufferTexture2D@plt>:
 1073c10:      	adrp	x16, 0x10d0000
 1073c14:      	ldr	x17, [x16, #0xcf8]
 1073c18:      	add	x16, x16, #0xcf8
 1073c1c:      	br	x17

0000000001073c20 <glCheckFramebufferStatus@plt>:
 1073c20:      	adrp	x16, 0x10d0000
 1073c24:      	ldr	x17, [x16, #0xd00]
 1073c28:      	add	x16, x16, #0xd00
 1073c2c:      	br	x17

0000000001073c30 <glGenFramebuffers@plt>:
 1073c30:      	adrp	x16, 0x10d0000
 1073c34:      	ldr	x17, [x16, #0xd08]
 1073c38:      	add	x16, x16, #0xd08
 1073c3c:      	br	x17

0000000001073c40 <glFlush@plt>:
 1073c40:      	adrp	x16, 0x10d0000
 1073c44:      	ldr	x17, [x16, #0xd10]
 1073c48:      	add	x16, x16, #0xd10
 1073c4c:      	br	x17

0000000001073c50 <glDeleteFramebuffers@plt>:
 1073c50:      	adrp	x16, 0x10d0000
 1073c54:      	ldr	x17, [x16, #0xd18]
 1073c58:      	add	x16, x16, #0xd18
 1073c5c:      	br	x17

0000000001073c60 <glDeleteVertexArrays@plt>:
 1073c60:      	adrp	x16, 0x10d0000
 1073c64:      	ldr	x17, [x16, #0xd20]
 1073c68:      	add	x16, x16, #0xd20
 1073c6c:      	br	x17

0000000001073c70 <glDeleteBuffers@plt>:
 1073c70:      	adrp	x16, 0x10d0000
 1073c74:      	ldr	x17, [x16, #0xd28]
 1073c78:      	add	x16, x16, #0xd28
 1073c7c:      	br	x17

0000000001073c80 <glViewport@plt>:
 1073c80:      	adrp	x16, 0x10d0000
 1073c84:      	ldr	x17, [x16, #0xd30]
 1073c88:      	add	x16, x16, #0xd30
 1073c8c:      	br	x17

0000000001073c90 <glClearColor@plt>:
 1073c90:      	adrp	x16, 0x10d0000
 1073c94:      	ldr	x17, [x16, #0xd38]
 1073c98:      	add	x16, x16, #0xd38
 1073c9c:      	br	x17

0000000001073ca0 <glClear@plt>:
 1073ca0:      	adrp	x16, 0x10d0000
 1073ca4:      	ldr	x17, [x16, #0xd40]
 1073ca8:      	add	x16, x16, #0xd40
 1073cac:      	br	x17

0000000001073cb0 <glDisable@plt>:
 1073cb0:      	adrp	x16, 0x10d0000
 1073cb4:      	ldr	x17, [x16, #0xd48]
 1073cb8:      	add	x16, x16, #0xd48
 1073cbc:      	br	x17

0000000001073cc0 <glColorMask@plt>:
 1073cc0:      	adrp	x16, 0x10d0000
 1073cc4:      	ldr	x17, [x16, #0xd50]
 1073cc8:      	add	x16, x16, #0xd50
 1073ccc:      	br	x17

0000000001073cd0 <glUseProgram@plt>:
 1073cd0:      	adrp	x16, 0x10d0000
 1073cd4:      	ldr	x17, [x16, #0xd58]
 1073cd8:      	add	x16, x16, #0xd58
 1073cdc:      	br	x17

0000000001073ce0 <glUniformMatrix4fv@plt>:
 1073ce0:      	adrp	x16, 0x10d0000
 1073ce4:      	ldr	x17, [x16, #0xd60]
 1073ce8:      	add	x16, x16, #0xd60
 1073cec:      	br	x17

0000000001073cf0 <glActiveTexture@plt>:
 1073cf0:      	adrp	x16, 0x10d0000
 1073cf4:      	ldr	x17, [x16, #0xd68]
 1073cf8:      	add	x16, x16, #0xd68
 1073cfc:      	br	x17

0000000001073d00 <glBindSampler@plt>:
 1073d00:      	adrp	x16, 0x10d0000
 1073d04:      	ldr	x17, [x16, #0xd70]
 1073d08:      	add	x16, x16, #0xd70
 1073d0c:      	br	x17

0000000001073d10 <glUniform1i@plt>:
 1073d10:      	adrp	x16, 0x10d0000
 1073d14:      	ldr	x17, [x16, #0xd78]
 1073d18:      	add	x16, x16, #0xd78
 1073d1c:      	br	x17

0000000001073d20 <glDrawArrays@plt>:
 1073d20:      	adrp	x16, 0x10d0000
 1073d24:      	ldr	x17, [x16, #0xd80]
 1073d28:      	add	x16, x16, #0xd80
 1073d2c:      	br	x17

0000000001073d30 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
 1073d30:      	adrp	x16, 0x10d0000
 1073d34:      	ldr	x17, [x16, #0xd88]
 1073d38:      	add	x16, x16, #0xd88
 1073d3c:      	br	x17

0000000001073d40 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
 1073d40:      	adrp	x16, 0x10d0000
 1073d44:      	ldr	x17, [x16, #0xd90]
 1073d48:      	add	x16, x16, #0xd90
 1073d4c:      	br	x17

0000000001073d50 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEmmPKc@plt>:
 1073d50:      	adrp	x16, 0x10d0000
 1073d54:      	ldr	x17, [x16, #0xd98]
 1073d58:      	add	x16, x16, #0xd98
 1073d5c:      	br	x17

0000000001073d60 <wgpuDeviceCreateComputePipeline@plt>:
 1073d60:      	adrp	x16, 0x10d0000
 1073d64:      	ldr	x17, [x16, #0xda0]
 1073d68:      	add	x16, x16, #0xda0
 1073d6c:      	br	x17

0000000001073d70 <wgpuComputePipelineRelease@plt>:
 1073d70:      	adrp	x16, 0x10d0000
 1073d74:      	ldr	x17, [x16, #0xda8]
 1073d78:      	add	x16, x16, #0xda8
 1073d7c:      	br	x17

0000000001073d80 <wgpuComputePassEncoderSetBindGroup@plt>:
 1073d80:      	adrp	x16, 0x10d0000
 1073d84:      	ldr	x17, [x16, #0xdb0]
 1073d88:      	add	x16, x16, #0xdb0
 1073d8c:      	br	x17

0000000001073d90 <wgpuComputePassEncoderEnd@plt>:
 1073d90:      	adrp	x16, 0x10d0000
 1073d94:      	ldr	x17, [x16, #0xdb8]
 1073d98:      	add	x16, x16, #0xdb8
 1073d9c:      	br	x17

0000000001073da0 <wgpuCommandEncoderBeginComputePass@plt>:
 1073da0:      	adrp	x16, 0x10d0000
 1073da4:      	ldr	x17, [x16, #0xdc0]
 1073da8:      	add	x16, x16, #0xdc0
 1073dac:      	br	x17

0000000001073db0 <wgpuComputePassEncoderDispatchWorkgroups@plt>:
 1073db0:      	adrp	x16, 0x10d0000
 1073db4:      	ldr	x17, [x16, #0xdc8]
 1073db8:      	add	x16, x16, #0xdc8
 1073dbc:      	br	x17

0000000001073dc0 <wgpuComputePassEncoderSetPipeline@plt>:
 1073dc0:      	adrp	x16, 0x10d0000
 1073dc4:      	ldr	x17, [x16, #0xdd0]
 1073dc8:      	add	x16, x16, #0xdd0
 1073dcc:      	br	x17

0000000001073dd0 <wgpuCommandEncoderCopyBufferToBuffer@plt>:
 1073dd0:      	adrp	x16, 0x10d0000
 1073dd4:      	ldr	x17, [x16, #0xdd8]
 1073dd8:      	add	x16, x16, #0xdd8
 1073ddc:      	br	x17

0000000001073de0 <printf@plt>:
 1073de0:      	adrp	x16, 0x10d0000
 1073de4:      	ldr	x17, [x16, #0xde0]
 1073de8:      	add	x16, x16, #0xde0
 1073dec:      	br	x17

0000000001073df0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv@plt>:
 1073df0:      	adrp	x16, 0x10d0000
 1073df4:      	ldr	x17, [x16, #0xde8]
 1073df8:      	add	x16, x16, #0xde8
 1073dfc:      	br	x17

0000000001073e00 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertENS_11__wrap_iterIPKcEEc@plt>:
 1073e00:      	adrp	x16, 0x10d0000
 1073e04:      	ldr	x17, [x16, #0xdf0]
 1073e08:      	add	x16, x16, #0xdf0
 1073e0c:      	br	x17

0000000001073e10 <fputs@plt>:
 1073e10:      	adrp	x16, 0x10d0000
 1073e14:      	ldr	x17, [x16, #0xdf8]
 1073e18:      	add	x16, x16, #0xdf8
 1073e1c:      	br	x17

0000000001073e20 <fputc@plt>:
 1073e20:      	adrp	x16, 0x10d0000
 1073e24:      	ldr	x17, [x16, #0xe00]
 1073e28:      	add	x16, x16, #0xe00
 1073e2c:      	br	x17

0000000001073e30 <_ZNSt6__ndk19to_stringEx@plt>:
 1073e30:      	adrp	x16, 0x10d0000
 1073e34:      	ldr	x17, [x16, #0xe08]
 1073e38:      	add	x16, x16, #0xe08
 1073e3c:      	br	x17

0000000001073e40 <atan@plt>:
 1073e40:      	adrp	x16, 0x10d0000
 1073e44:      	ldr	x17, [x16, #0xe10]
 1073e48:      	add	x16, x16, #0xe10
 1073e4c:      	br	x17

0000000001073e50 <asin@plt>:
 1073e50:      	adrp	x16, 0x10d0000
 1073e54:      	ldr	x17, [x16, #0xe18]
 1073e58:      	add	x16, x16, #0xe18
 1073e5c:      	br	x17

0000000001073e60 <acos@plt>:
 1073e60:      	adrp	x16, 0x10d0000
 1073e64:      	ldr	x17, [x16, #0xe20]
 1073e68:      	add	x16, x16, #0xe20
 1073e6c:      	br	x17

0000000001073e70 <sin@plt>:
 1073e70:      	adrp	x16, 0x10d0000
 1073e74:      	ldr	x17, [x16, #0xe28]
 1073e78:      	add	x16, x16, #0xe28
 1073e7c:      	br	x17

0000000001073e80 <exp2@plt>:
 1073e80:      	adrp	x16, 0x10d0000
 1073e84:      	ldr	x17, [x16, #0xe30]
 1073e88:      	add	x16, x16, #0xe30
 1073e8c:      	br	x17

0000000001073e90 <log2@plt>:
 1073e90:      	adrp	x16, 0x10d0000
 1073e94:      	ldr	x17, [x16, #0xe38]
 1073e98:      	add	x16, x16, #0xe38
 1073e9c:      	br	x17

0000000001073ea0 <log@plt>:
 1073ea0:      	adrp	x16, 0x10d0000
 1073ea4:      	ldr	x17, [x16, #0xe40]
 1073ea8:      	add	x16, x16, #0xe40
 1073eac:      	br	x17

0000000001073eb0 <atan2@plt>:
 1073eb0:      	adrp	x16, 0x10d0000
 1073eb4:      	ldr	x17, [x16, #0xe48]
 1073eb8:      	add	x16, x16, #0xe48
 1073ebc:      	br	x17

0000000001073ec0 <_ZNSt6__ndk18ios_base4moveERS0_@plt>:
 1073ec0:      	adrp	x16, 0x10d0000
 1073ec4:      	ldr	x17, [x16, #0xe50]
 1073ec8:      	add	x16, x16, #0xe50
 1073ecc:      	br	x17

0000000001073ed0 <_ZNSt6__ndk18ios_base4swapERS0_@plt>:
 1073ed0:      	adrp	x16, 0x10d0000
 1073ed4:      	ldr	x17, [x16, #0xe58]
 1073ed8:      	add	x16, x16, #0xe58
 1073edc:      	br	x17

0000000001073ee0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC2Ev@plt>:
 1073ee0:      	adrp	x16, 0x10d0000
 1073ee4:      	ldr	x17, [x16, #0xe60]
 1073ee8:      	add	x16, x16, #0xe60
 1073eec:      	br	x17

0000000001073ef0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED2Ev@plt>:
 1073ef0:      	adrp	x16, 0x10d0000
 1073ef4:      	ldr	x17, [x16, #0xe68]
 1073ef8:      	add	x16, x16, #0xe68
 1073efc:      	br	x17

0000000001073f00 <AAssetManager_fromJava@plt>:
 1073f00:      	adrp	x16, 0x10d0000
 1073f04:      	ldr	x17, [x16, #0xe70]
 1073f08:      	add	x16, x16, #0xe70
 1073f0c:      	br	x17

0000000001073f10 <AAssetManager_openDir@plt>:
 1073f10:      	adrp	x16, 0x10d0000
 1073f14:      	ldr	x17, [x16, #0xe78]
 1073f18:      	add	x16, x16, #0xe78
 1073f1c:      	br	x17

0000000001073f20 <AAssetDir_close@plt>:
 1073f20:      	adrp	x16, 0x10d0000
 1073f24:      	ldr	x17, [x16, #0xe80]
 1073f28:      	add	x16, x16, #0xe80
 1073f2c:      	br	x17

0000000001073f30 <AAssetManager_open@plt>:
 1073f30:      	adrp	x16, 0x10d0000
 1073f34:      	ldr	x17, [x16, #0xe88]
 1073f38:      	add	x16, x16, #0xe88
 1073f3c:      	br	x17

0000000001073f40 <AAsset_getLength@plt>:
 1073f40:      	adrp	x16, 0x10d0000
 1073f44:      	ldr	x17, [x16, #0xe90]
 1073f48:      	add	x16, x16, #0xe90
 1073f4c:      	br	x17

0000000001073f50 <AAsset_close@plt>:
 1073f50:      	adrp	x16, 0x10d0000
 1073f54:      	ldr	x17, [x16, #0xe98]
 1073f58:      	add	x16, x16, #0xe98
 1073f5c:      	br	x17

0000000001073f60 <AAsset_seek64@plt>:
 1073f60:      	adrp	x16, 0x10d0000
 1073f64:      	ldr	x17, [x16, #0xea0]
 1073f68:      	add	x16, x16, #0xea0
 1073f6c:      	br	x17

0000000001073f70 <AAsset_read@plt>:
 1073f70:      	adrp	x16, 0x10d0000
 1073f74:      	ldr	x17, [x16, #0xea8]
 1073f78:      	add	x16, x16, #0xea8
 1073f7c:      	br	x17

0000000001073f80 <log2f@plt>:
 1073f80:      	adrp	x16, 0x10d0000
 1073f84:      	ldr	x17, [x16, #0xeb0]
 1073f88:      	add	x16, x16, #0xeb0
 1073f8c:      	br	x17

0000000001073f90 <posix_memalign@plt>:
 1073f90:      	adrp	x16, 0x10d0000
 1073f94:      	ldr	x17, [x16, #0xeb8]
 1073f98:      	add	x16, x16, #0xeb8
 1073f9c:      	br	x17

0000000001073fa0 <pthread_setname_np@plt>:
 1073fa0:      	adrp	x16, 0x10d0000
 1073fa4:      	ldr	x17, [x16, #0xec0]
 1073fa8:      	add	x16, x16, #0xec0
 1073fac:      	br	x17

0000000001073fb0 <setpriority@plt>:
 1073fb0:      	adrp	x16, 0x10d0000
 1073fb4:      	ldr	x17, [x16, #0xec8]
 1073fb8:      	add	x16, x16, #0xec8
 1073fbc:      	br	x17

0000000001073fc0 <syscall@plt>:
 1073fc0:      	adrp	x16, 0x10d0000
 1073fc4:      	ldr	x17, [x16, #0xed0]
 1073fc8:      	add	x16, x16, #0xed0
 1073fcc:      	br	x17

0000000001073fd0 <sched_setaffinity@plt>:
 1073fd0:      	adrp	x16, 0x10d0000
 1073fd4:      	ldr	x17, [x16, #0xed8]
 1073fd8:      	add	x16, x16, #0xed8
 1073fdc:      	br	x17

0000000001073fe0 <__android_log_vprint@plt>:
 1073fe0:      	adrp	x16, 0x10d0000
 1073fe4:      	ldr	x17, [x16, #0xee0]
 1073fe8:      	add	x16, x16, #0xee0
 1073fec:      	br	x17

0000000001073ff0 <__open_2@plt>:
 1073ff0:      	adrp	x16, 0x10d0000
 1073ff4:      	ldr	x17, [x16, #0xee8]
 1073ff8:      	add	x16, x16, #0xee8
 1073ffc:      	br	x17

0000000001074000 <pthread_once@plt>:
 1074000:      	adrp	x16, 0x10d0000
 1074004:      	ldr	x17, [x16, #0xef0]
 1074008:      	add	x16, x16, #0xef0
 107400c:      	br	x17

0000000001074010 <getpid@plt>:
 1074010:      	adrp	x16, 0x10d0000
 1074014:      	ldr	x17, [x16, #0xef8]
 1074018:      	add	x16, x16, #0xef8
 107401c:      	br	x17

0000000001074020 <write@plt>:
 1074020:      	adrp	x16, 0x10d0000
 1074024:      	ldr	x17, [x16, #0xf00]
 1074028:      	add	x16, x16, #0xf00
 107402c:      	br	x17

0000000001074030 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6ignoreEli@plt>:
 1074030:      	adrp	x16, 0x10d0000
 1074034:      	ldr	x17, [x16, #0xf08]
 1074038:      	add	x16, x16, #0xf08
 107403c:      	br	x17

0000000001074040 <strtol@plt>:
 1074040:      	adrp	x16, 0x10d0000
 1074044:      	ldr	x17, [x16, #0xf10]
 1074048:      	add	x16, x16, #0xf10
 107404c:      	br	x17

0000000001074050 <ldexpf@plt>:
 1074050:      	adrp	x16, 0x10d0000
 1074054:      	ldr	x17, [x16, #0xf18]
 1074058:      	add	x16, x16, #0xf18
 107405c:      	br	x17

0000000001074060 <__assert2@plt>:
 1074060:      	adrp	x16, 0x10d0000
 1074064:      	ldr	x17, [x16, #0xf20]
 1074068:      	add	x16, x16, #0xf20
 107406c:      	br	x17

0000000001074070 <__memset_chk@plt>:
 1074070:      	adrp	x16, 0x10d0000
 1074074:      	ldr	x17, [x16, #0xf28]
 1074078:      	add	x16, x16, #0xf28
 107407c:      	br	x17

0000000001074080 <pthread_mutex_lock@plt>:
 1074080:      	adrp	x16, 0x10d0000
 1074084:      	ldr	x17, [x16, #0xf30]
 1074088:      	add	x16, x16, #0xf30
 107408c:      	br	x17

0000000001074090 <pthread_mutex_unlock@plt>:
 1074090:      	adrp	x16, 0x10d0000
 1074094:      	ldr	x17, [x16, #0xf38]
 1074098:      	add	x16, x16, #0xf38
 107409c:      	br	x17

00000000010740a0 <pthread_mutex_init@plt>:
 10740a0:      	adrp	x16, 0x10d0000
 10740a4:      	ldr	x17, [x16, #0xf40]
 10740a8:      	add	x16, x16, #0xf40
 10740ac:      	br	x17

00000000010740b0 <pthread_cond_init@plt>:
 10740b0:      	adrp	x16, 0x10d0000
 10740b4:      	ldr	x17, [x16, #0xf48]
 10740b8:      	add	x16, x16, #0xf48
 10740bc:      	br	x17

00000000010740c0 <pthread_mutex_destroy@plt>:
 10740c0:      	adrp	x16, 0x10d0000
 10740c4:      	ldr	x17, [x16, #0xf50]
 10740c8:      	add	x16, x16, #0xf50
 10740cc:      	br	x17

00000000010740d0 <pthread_cond_destroy@plt>:
 10740d0:      	adrp	x16, 0x10d0000
 10740d4:      	ldr	x17, [x16, #0xf58]
 10740d8:      	add	x16, x16, #0xf58
 10740dc:      	br	x17

00000000010740e0 <pthread_cond_wait@plt>:
 10740e0:      	adrp	x16, 0x10d0000
 10740e4:      	ldr	x17, [x16, #0xf60]
 10740e8:      	add	x16, x16, #0xf60
 10740ec:      	br	x17

00000000010740f0 <pthread_cond_signal@plt>:
 10740f0:      	adrp	x16, 0x10d0000
 10740f4:      	ldr	x17, [x16, #0xf68]
 10740f8:      	add	x16, x16, #0xf68
 10740fc:      	br	x17

0000000001074100 <__memmove_chk@plt>:
 1074100:      	adrp	x16, 0x10d0000
 1074104:      	ldr	x17, [x16, #0xf70]
 1074108:      	add	x16, x16, #0xf70
 107410c:      	br	x17

0000000001074110 <strspn@plt>:
 1074110:      	adrp	x16, 0x10d0000
 1074114:      	ldr	x17, [x16, #0xf78]
 1074118:      	add	x16, x16, #0xf78
 107411c:      	br	x17

0000000001074120 <getenv@plt>:
 1074120:      	adrp	x16, 0x10d0000
 1074124:      	ldr	x17, [x16, #0xf80]
 1074128:      	add	x16, x16, #0xf80
 107412c:      	br	x17

0000000001074130 <strrchr@plt>:
 1074130:      	adrp	x16, 0x10d0000
 1074134:      	ldr	x17, [x16, #0xf88]
 1074138:      	add	x16, x16, #0xf88
 107413c:      	br	x17

0000000001074140 <tmpfile@plt>:
 1074140:      	adrp	x16, 0x10d0000
 1074144:      	ldr	x17, [x16, #0xf90]
 1074148:      	add	x16, x16, #0xf90
 107414c:      	br	x17

0000000001074150 <clearerr@plt>:
 1074150:      	adrp	x16, 0x10d0000
 1074154:      	ldr	x17, [x16, #0xf98]
 1074158:      	add	x16, x16, #0xf98
 107415c:      	br	x17

0000000001074160 <fscanf@plt>:
 1074160:      	adrp	x16, 0x10d0000
 1074164:      	ldr	x17, [x16, #0xfa0]
 1074168:      	add	x16, x16, #0xfa0
 107416c:      	br	x17

0000000001074170 <ungetc@plt>:
 1074170:      	adrp	x16, 0x10d0000
 1074174:      	ldr	x17, [x16, #0xfa8]
 1074178:      	add	x16, x16, #0xfa8
 107417c:      	br	x17

0000000001074180 <fgets@plt>:
 1074180:      	adrp	x16, 0x10d0000
 1074184:      	ldr	x17, [x16, #0xfb0]
 1074188:      	add	x16, x16, #0xfb0
 107418c:      	br	x17

0000000001074190 <setvbuf@plt>:
 1074190:      	adrp	x16, 0x10d0000
 1074194:      	ldr	x17, [x16, #0xfb8]
 1074198:      	add	x16, x16, #0xfb8
 107419c:      	br	x17

00000000010741a0 <clock@plt>:
 10741a0:      	adrp	x16, 0x10d0000
 10741a4:      	ldr	x17, [x16, #0xfc0]
 10741a8:      	add	x16, x16, #0xfc0
 10741ac:      	br	x17

00000000010741b0 <gmtime@plt>:
 10741b0:      	adrp	x16, 0x10d0000
 10741b4:      	ldr	x17, [x16, #0xfc8]
 10741b8:      	add	x16, x16, #0xfc8
 10741bc:      	br	x17

00000000010741c0 <strftime@plt>:
 10741c0:      	adrp	x16, 0x10d0000
 10741c4:      	ldr	x17, [x16, #0xfd0]
 10741c8:      	add	x16, x16, #0xfd0
 10741cc:      	br	x17

00000000010741d0 <difftime@plt>:
 10741d0:      	adrp	x16, 0x10d0000
 10741d4:      	ldr	x17, [x16, #0xfd8]
 10741d8:      	add	x16, x16, #0xfd8
 10741dc:      	br	x17

00000000010741e0 <system@plt>:
 10741e0:      	adrp	x16, 0x10d0000
 10741e4:      	ldr	x17, [x16, #0xfe0]
 10741e8:      	add	x16, x16, #0xfe0
 10741ec:      	br	x17

00000000010741f0 <exit@plt>:
 10741f0:      	adrp	x16, 0x10d0000
 10741f4:      	ldr	x17, [x16, #0xfe8]
 10741f8:      	add	x16, x16, #0xfe8
 10741fc:      	br	x17

0000000001074200 <remove@plt>:
 1074200:      	adrp	x16, 0x10d0000
 1074204:      	ldr	x17, [x16, #0xff0]
 1074208:      	add	x16, x16, #0xff0
 107420c:      	br	x17

0000000001074210 <rename@plt>:
 1074210:      	adrp	x16, 0x10d0000
 1074214:      	ldr	x17, [x16, #0xff8]
 1074218:      	add	x16, x16, #0xff8
 107421c:      	br	x17

0000000001074220 <mktime@plt>:
 1074220:      	adrp	x16, 0x10d1000
 1074224:      	ldr	x17, [x16]
 1074228:      	add	x16, x16, #0x0
 107422c:      	br	x17

0000000001074230 <tmpnam@plt>:
 1074230:      	adrp	x16, 0x10d1000
 1074234:      	ldr	x17, [x16, #0x8]
 1074238:      	add	x16, x16, #0x8
 107423c:      	br	x17

0000000001074240 <cosh@plt>:
 1074240:      	adrp	x16, 0x10d1000
 1074244:      	ldr	x17, [x16, #0x10]
 1074248:      	add	x16, x16, #0x10
 107424c:      	br	x17

0000000001074250 <frexp@plt>:
 1074250:      	adrp	x16, 0x10d1000
 1074254:      	ldr	x17, [x16, #0x18]
 1074258:      	add	x16, x16, #0x18
 107425c:      	br	x17

0000000001074260 <log10@plt>:
 1074260:      	adrp	x16, 0x10d1000
 1074264:      	ldr	x17, [x16, #0x20]
 1074268:      	add	x16, x16, #0x20
 107426c:      	br	x17

0000000001074270 <modf@plt>:
 1074270:      	adrp	x16, 0x10d1000
 1074274:      	ldr	x17, [x16, #0x28]
 1074278:      	add	x16, x16, #0x28
 107427c:      	br	x17

0000000001074280 <rand@plt>:
 1074280:      	adrp	x16, 0x10d1000
 1074284:      	ldr	x17, [x16, #0x30]
 1074288:      	add	x16, x16, #0x30
 107428c:      	br	x17

0000000001074290 <srand@plt>:
 1074290:      	adrp	x16, 0x10d1000
 1074294:      	ldr	x17, [x16, #0x38]
 1074298:      	add	x16, x16, #0x38
 107429c:      	br	x17

00000000010742a0 <sinh@plt>:
 10742a0:      	adrp	x16, 0x10d1000
 10742a4:      	ldr	x17, [x16, #0x40]
 10742a8:      	add	x16, x16, #0x40
 10742ac:      	br	x17

00000000010742b0 <tanh@plt>:
 10742b0:      	adrp	x16, 0x10d1000
 10742b4:      	ldr	x17, [x16, #0x48]
 10742b8:      	add	x16, x16, #0x48
 10742bc:      	br	x17

00000000010742c0 <_ZdlPvRKSt9nothrow_t@plt>:
 10742c0:      	adrp	x16, 0x10d1000
 10742c4:      	ldr	x17, [x16, #0x50]
 10742c8:      	add	x16, x16, #0x50
 10742cc:      	br	x17

00000000010742d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendERKS5_mm@plt>:
 10742d0:      	adrp	x16, 0x10d1000
 10742d4:      	ldr	x17, [x16, #0x58]
 10742d8:      	add	x16, x16, #0x58
 10742dc:      	br	x17

00000000010742e0 <AAsset_getBuffer@plt>:
 10742e0:      	adrp	x16, 0x10d1000
 10742e4:      	ldr	x17, [x16, #0x60]
 10742e8:      	add	x16, x16, #0x60
 10742ec:      	br	x17

00000000010742f0 <rewind@plt>:
 10742f0:      	adrp	x16, 0x10d1000
 10742f4:      	ldr	x17, [x16, #0x68]
 10742f8:      	add	x16, x16, #0x68
 10742fc:      	br	x17

0000000001074300 <AAsset_getRemainingLength@plt>:
 1074300:      	adrp	x16, 0x10d1000
 1074304:      	ldr	x17, [x16, #0x70]
 1074308:      	add	x16, x16, #0x70
 107430c:      	br	x17

0000000001074310 <AAsset_seek@plt>:
 1074310:      	adrp	x16, 0x10d1000
 1074314:      	ldr	x17, [x16, #0x78]
 1074318:      	add	x16, x16, #0x78
 107431c:      	br	x17

0000000001074320 <strcspn@plt>:
 1074320:      	adrp	x16, 0x10d1000
 1074324:      	ldr	x17, [x16, #0x80]
 1074328:      	add	x16, x16, #0x80
 107432c:      	br	x17

0000000001074330 <modff@plt>:
 1074330:      	adrp	x16, 0x10d1000
 1074334:      	ldr	x17, [x16, #0x88]
 1074338:      	add	x16, x16, #0x88
 107433c:      	br	x17

0000000001074340 <vfprintf@plt>:
 1074340:      	adrp	x16, 0x10d1000
 1074344:      	ldr	x17, [x16, #0x90]
 1074348:      	add	x16, x16, #0x90
 107434c:      	br	x17

0000000001074350 <strcasecmp@plt>:
 1074350:      	adrp	x16, 0x10d1000
 1074354:      	ldr	x17, [x16, #0x98]
 1074358:      	add	x16, x16, #0x98
 107435c:      	br	x17

0000000001074360 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE2atEm@plt>:
 1074360:      	adrp	x16, 0x10d1000
 1074364:      	ldr	x17, [x16, #0xa0]
 1074368:      	add	x16, x16, #0xa0
 107436c:      	br	x17

0000000001074370 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmmc@plt>:
 1074370:      	adrp	x16, 0x10d1000
 1074374:      	ldr	x17, [x16, #0xa8]
 1074378:      	add	x16, x16, #0xa8
 107437c:      	br	x17

0000000001074380 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE2atEm@plt>:
 1074380:      	adrp	x16, 0x10d1000
 1074384:      	ldr	x17, [x16, #0xb0]
 1074388:      	add	x16, x16, #0xb0
 107438c:      	br	x17

0000000001074390 <strtoull@plt>:
 1074390:      	adrp	x16, 0x10d1000
 1074394:      	ldr	x17, [x16, #0xb8]
 1074398:      	add	x16, x16, #0xb8
 107439c:      	br	x17

00000000010743a0 <_ZNSt13runtime_errorC1EPKc@plt>:
 10743a0:      	adrp	x16, 0x10d1000
 10743a4:      	ldr	x17, [x16, #0xc0]
 10743a8:      	add	x16, x16, #0xc0
 10743ac:      	br	x17

00000000010743b0 <realpath@plt>:
 10743b0:      	adrp	x16, 0x10d1000
 10743b4:      	ldr	x17, [x16, #0xc8]
 10743b8:      	add	x16, x16, #0xc8
 10743bc:      	br	x17

00000000010743c0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEx@plt>:
 10743c0:      	adrp	x16, 0x10d1000
 10743c4:      	ldr	x17, [x16, #0xd0]
 10743c8:      	add	x16, x16, #0xd0
 10743cc:      	br	x17

00000000010743d0 <_ZNSt13runtime_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
 10743d0:      	adrp	x16, 0x10d1000
 10743d4:      	ldr	x17, [x16, #0xd8]
 10743d8:      	add	x16, x16, #0xd8
 10743dc:      	br	x17

00000000010743e0 <strncasecmp@plt>:
 10743e0:      	adrp	x16, 0x10d1000
 10743e4:      	ldr	x17, [x16, #0xe0]
 10743e8:      	add	x16, x16, #0xe0
 10743ec:      	br	x17

00000000010743f0 <__strcpy_chk@plt>:
 10743f0:      	adrp	x16, 0x10d1000
 10743f4:      	ldr	x17, [x16, #0xe8]
 10743f8:      	add	x16, x16, #0xe8
 10743fc:      	br	x17

0000000001074400 <_ZNSt11logic_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
 1074400:      	adrp	x16, 0x10d1000
 1074404:      	ldr	x17, [x16, #0xf0]
 1074408:      	add	x16, x16, #0xf0
 107440c:      	br	x17

0000000001074410 <qsort@plt>:
 1074410:      	adrp	x16, 0x10d1000
 1074414:      	ldr	x17, [x16, #0xf8]
 1074418:      	add	x16, x16, #0xf8
 107441c:      	br	x17

0000000001074420 <strcat@plt>:
 1074420:      	adrp	x16, 0x10d1000
 1074424:      	ldr	x17, [x16, #0x100]
 1074428:      	add	x16, x16, #0x100
 107442c:      	br	x17

0000000001074430 <getauxval@plt>:
 1074430:      	adrp	x16, 0x10d1000
 1074434:      	ldr	x17, [x16, #0x108]
 1074438:      	add	x16, x16, #0x108
 107443c:      	br	x17

0000000001074440 <__system_property_get@plt>:
 1074440:      	adrp	x16, 0x10d1000
 1074444:      	ldr	x17, [x16, #0x110]
 1074448:      	add	x16, x16, #0x110
 107444c:      	br	x17

0000000001074450 <pthread_rwlock_wrlock@plt>:
 1074450:      	adrp	x16, 0x10d1000
 1074454:      	ldr	x17, [x16, #0x118]
 1074458:      	add	x16, x16, #0x118
 107445c:      	br	x17

0000000001074460 <pthread_rwlock_unlock@plt>:
 1074460:      	adrp	x16, 0x10d1000
 1074464:      	ldr	x17, [x16, #0x120]
 1074468:      	add	x16, x16, #0x120
 107446c:      	br	x17

0000000001074470 <dl_iterate_phdr@plt>:
 1074470:      	adrp	x16, 0x10d1000
 1074474:      	ldr	x17, [x16, #0x128]
 1074478:      	add	x16, x16, #0x128
 107447c:      	br	x17

0000000001074480 <pthread_rwlock_rdlock@plt>:
 1074480:      	adrp	x16, 0x10d1000
 1074484:      	ldr	x17, [x16, #0x130]
 1074488:      	add	x16, x16, #0x130
 107448c:      	br	x17
