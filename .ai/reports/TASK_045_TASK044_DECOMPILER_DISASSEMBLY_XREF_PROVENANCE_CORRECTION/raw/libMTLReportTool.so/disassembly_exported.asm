// EXPORTED & PLT DISASSEMBLY FOR libMTLReportTool.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTLReportTool.so (SHA-256: C34587E543305B8E92FE3156A424F86251667C363D1758BE61917D1EF1F1152C)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 50, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTLReportTool.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000010710 <.plt>:
   10710:      	stp	x16, x30, [sp, #-0x10]!
   10714:      	adrp	x16, 0x15000
   10718:      	ldr	x17, [x16, #0x1f8]
   1071c:      	add	x16, x16, #0x1f8
   10720:      	br	x17
   10724:      	nop
   10728:      	nop
   1072c:      	nop

0000000000010730 <__cxa_finalize@plt>:
   10730:      	adrp	x16, 0x15000
   10734:      	ldr	x17, [x16, #0x200]
   10738:      	add	x16, x16, #0x200
   1073c:      	br	x17

0000000000010740 <__cxa_atexit@plt>:
   10740:      	adrp	x16, 0x15000
   10744:      	ldr	x17, [x16, #0x208]
   10748:      	add	x16, x16, #0x208
   1074c:      	br	x17

0000000000010750 <__register_atfork@plt>:
   10750:      	adrp	x16, 0x15000
   10754:      	ldr	x17, [x16, #0x210]
   10758:      	add	x16, x16, #0x210
   1075c:      	br	x17

0000000000010760 <strlen@plt>:
   10760:      	adrp	x16, 0x15000
   10764:      	ldr	x17, [x16, #0x218]
   10768:      	add	x16, x16, #0x218
   1076c:      	br	x17

0000000000010770 <_Znwm@plt>:
   10770:      	adrp	x16, 0x15000
   10774:      	ldr	x17, [x16, #0x220]
   10778:      	add	x16, x16, #0x220
   1077c:      	br	x17

0000000000010780 <memmove@plt>:
   10780:      	adrp	x16, 0x15000
   10784:      	ldr	x17, [x16, #0x228]
   10788:      	add	x16, x16, #0x228
   1078c:      	br	x17

0000000000010790 <_ZdlPv@plt>:
   10790:      	adrp	x16, 0x15000
   10794:      	ldr	x17, [x16, #0x230]
   10798:      	add	x16, x16, #0x230
   1079c:      	br	x17

00000000000107a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   107a0:      	adrp	x16, 0x15000
   107a4:      	ldr	x17, [x16, #0x238]
   107a8:      	add	x16, x16, #0x238
   107ac:      	br	x17

00000000000107b0 <__cxa_allocate_exception@plt>:
   107b0:      	adrp	x16, 0x15000
   107b4:      	ldr	x17, [x16, #0x240]
   107b8:      	add	x16, x16, #0x240
   107bc:      	br	x17

00000000000107c0 <__cxa_throw@plt>:
   107c0:      	adrp	x16, 0x15000
   107c4:      	ldr	x17, [x16, #0x248]
   107c8:      	add	x16, x16, #0x248
   107cc:      	br	x17

00000000000107d0 <__cxa_free_exception@plt>:
   107d0:      	adrp	x16, 0x15000
   107d4:      	ldr	x17, [x16, #0x250]
   107d8:      	add	x16, x16, #0x250
   107dc:      	br	x17

00000000000107e0 <_ZNSt11logic_errorC2EPKc@plt>:
   107e0:      	adrp	x16, 0x15000
   107e4:      	ldr	x17, [x16, #0x258]
   107e8:      	add	x16, x16, #0x258
   107ec:      	br	x17

00000000000107f0 <_ZN13MTLReportTool9Interface4ImplC1Ev@plt>:
   107f0:      	adrp	x16, 0x15000
   107f4:      	ldr	x17, [x16, #0x260]
   107f8:      	add	x16, x16, #0x260
   107fc:      	br	x17

0000000000010800 <_ZN13MTLReportTool9Interface4ImplD1Ev@plt>:
   10800:      	adrp	x16, 0x15000
   10804:      	ldr	x17, [x16, #0x268]
   10808:      	add	x16, x16, #0x268
   1080c:      	br	x17

0000000000010810 <_ZN13MTLReportTool9Interface7versionEv@plt>:
   10810:      	adrp	x16, 0x15000
   10814:      	ldr	x17, [x16, #0x270]
   10818:      	add	x16, x16, #0x270
   1081c:      	br	x17

0000000000010820 <_ZN13MTLReportTool9InterfaceC1Ev@plt>:
   10820:      	adrp	x16, 0x15000
   10824:      	ldr	x17, [x16, #0x278]
   10828:      	add	x16, x16, #0x278
   1082c:      	br	x17

0000000000010830 <_ZN13MTLReportTool9InterfaceD1Ev@plt>:
   10830:      	adrp	x16, 0x15000
   10834:      	ldr	x17, [x16, #0x280]
   10838:      	add	x16, x16, #0x280
   1083c:      	br	x17

0000000000010840 <__stack_chk_fail@plt>:
   10840:      	adrp	x16, 0x15000
   10844:      	ldr	x17, [x16, #0x288]
   10848:      	add	x16, x16, #0x288
   1084c:      	br	x17

0000000000010850 <malloc@plt>:
   10850:      	adrp	x16, 0x15000
   10854:      	ldr	x17, [x16, #0x290]
   10858:      	add	x16, x16, #0x290
   1085c:      	br	x17

0000000000010860 <__cxa_begin_catch@plt>:
   10860:      	adrp	x16, 0x15000
   10864:      	ldr	x17, [x16, #0x298]
   10868:      	add	x16, x16, #0x298
   1086c:      	br	x17

0000000000010870 <_ZSt9terminatev@plt>:
   10870:      	adrp	x16, 0x15000
   10874:      	ldr	x17, [x16, #0x2a0]
   10878:      	add	x16, x16, #0x2a0
   1087c:      	br	x17

0000000000010880 <free@plt>:
   10880:      	adrp	x16, 0x15000
   10884:      	ldr	x17, [x16, #0x2a8]
   10888:      	add	x16, x16, #0x2a8
   1088c:      	br	x17

0000000000010890 <memcpy@plt>:
   10890:      	adrp	x16, 0x15000
   10894:      	ldr	x17, [x16, #0x2b0]
   10898:      	add	x16, x16, #0x2b0
   1089c:      	br	x17

00000000000108a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
   108a0:      	adrp	x16, 0x15000
   108a4:      	ldr	x17, [x16, #0x2b8]
   108a8:      	add	x16, x16, #0x2b8
   108ac:      	br	x17

00000000000108b0 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   108b0:      	adrp	x16, 0x15000
   108b4:      	ldr	x17, [x16, #0x2c0]
   108b8:      	add	x16, x16, #0x2c0
   108bc:      	br	x17

00000000000108c0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   108c0:      	adrp	x16, 0x15000
   108c4:      	ldr	x17, [x16, #0x2c8]
   108c8:      	add	x16, x16, #0x2c8
   108cc:      	br	x17

00000000000108d0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   108d0:      	adrp	x16, 0x15000
   108d4:      	ldr	x17, [x16, #0x2d0]
   108d8:      	add	x16, x16, #0x2d0
   108dc:      	br	x17

00000000000108e0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   108e0:      	adrp	x16, 0x15000
   108e4:      	ldr	x17, [x16, #0x2d8]
   108e8:      	add	x16, x16, #0x2d8
   108ec:      	br	x17

00000000000108f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   108f0:      	adrp	x16, 0x15000
   108f4:      	ldr	x17, [x16, #0x2e0]
   108f8:      	add	x16, x16, #0x2e0
   108fc:      	br	x17

0000000000010900 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   10900:      	adrp	x16, 0x15000
   10904:      	ldr	x17, [x16, #0x2e8]
   10908:      	add	x16, x16, #0x2e8
   1090c:      	br	x17

0000000000010910 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   10910:      	adrp	x16, 0x15000
   10914:      	ldr	x17, [x16, #0x2f0]
   10918:      	add	x16, x16, #0x2f0
   1091c:      	br	x17

0000000000010920 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
   10920:      	adrp	x16, 0x15000
   10924:      	ldr	x17, [x16, #0x2f8]
   10928:      	add	x16, x16, #0x2f8
   1092c:      	br	x17

0000000000010930 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   10930:      	adrp	x16, 0x15000
   10934:      	ldr	x17, [x16, #0x300]
   10938:      	add	x16, x16, #0x300
   1093c:      	br	x17

0000000000010940 <_ZNSt6__ndk16localeD1Ev@plt>:
   10940:      	adrp	x16, 0x15000
   10944:      	ldr	x17, [x16, #0x308]
   10948:      	add	x16, x16, #0x308
   1094c:      	br	x17

0000000000010950 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
   10950:      	adrp	x16, 0x15000
   10954:      	ldr	x17, [x16, #0x310]
   10958:      	add	x16, x16, #0x310
   1095c:      	br	x17

0000000000010960 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   10960:      	adrp	x16, 0x15000
   10964:      	ldr	x17, [x16, #0x318]
   10968:      	add	x16, x16, #0x318
   1096c:      	br	x17

0000000000010970 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
   10970:      	adrp	x16, 0x15000
   10974:      	ldr	x17, [x16, #0x320]
   10978:      	add	x16, x16, #0x320
   1097c:      	br	x17

0000000000010980 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
   10980:      	adrp	x16, 0x15000
   10984:      	ldr	x17, [x16, #0x328]
   10988:      	add	x16, x16, #0x328
   1098c:      	br	x17

0000000000010990 <__cxa_end_catch@plt>:
   10990:      	adrp	x16, 0x15000
   10994:      	ldr	x17, [x16, #0x330]
   10998:      	add	x16, x16, #0x330
   1099c:      	br	x17

00000000000109a0 <memset@plt>:
   109a0:      	adrp	x16, 0x15000
   109a4:      	ldr	x17, [x16, #0x338]
   109a8:      	add	x16, x16, #0x338
   109ac:      	br	x17

00000000000109b0 <fclose@plt>:
   109b0:      	adrp	x16, 0x15000
   109b4:      	ldr	x17, [x16, #0x340]
   109b8:      	add	x16, x16, #0x340
   109bc:      	br	x17

00000000000109c0 <_Znam@plt>:
   109c0:      	adrp	x16, 0x15000
   109c4:      	ldr	x17, [x16, #0x348]
   109c8:      	add	x16, x16, #0x348
   109cc:      	br	x17

00000000000109d0 <fread@plt>:
   109d0:      	adrp	x16, 0x15000
   109d4:      	ldr	x17, [x16, #0x350]
   109d8:      	add	x16, x16, #0x350
   109dc:      	br	x17

00000000000109e0 <_ZdaPv@plt>:
   109e0:      	adrp	x16, 0x15000
   109e4:      	ldr	x17, [x16, #0x358]
   109e8:      	add	x16, x16, #0x358
   109ec:      	br	x17

00000000000109f0 <fseek@plt>:
   109f0:      	adrp	x16, 0x15000
   109f4:      	ldr	x17, [x16, #0x360]
   109f8:      	add	x16, x16, #0x360
   109fc:      	br	x17

0000000000010a00 <ftell@plt>:
   10a00:      	adrp	x16, 0x15000
   10a04:      	ldr	x17, [x16, #0x368]
   10a08:      	add	x16, x16, #0x368
   10a0c:      	br	x17

0000000000010a10 <fopen@plt>:
   10a10:      	adrp	x16, 0x15000
   10a14:      	ldr	x17, [x16, #0x370]
   10a18:      	add	x16, x16, #0x370
   10a1c:      	br	x17

0000000000010a20 <fwrite@plt>:
   10a20:      	adrp	x16, 0x15000
   10a24:      	ldr	x17, [x16, #0x378]
   10a28:      	add	x16, x16, #0x378
   10a2c:      	br	x17

0000000000010a30 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
   10a30:      	adrp	x16, 0x15000
   10a34:      	ldr	x17, [x16, #0x380]
   10a38:      	add	x16, x16, #0x380
   10a3c:      	br	x17

0000000000010a40 <access@plt>:
   10a40:      	adrp	x16, 0x15000
   10a44:      	ldr	x17, [x16, #0x388]
   10a48:      	add	x16, x16, #0x388
   10a4c:      	br	x17

0000000000010a50 <mkdir@plt>:
   10a50:      	adrp	x16, 0x15000
   10a54:      	ldr	x17, [x16, #0x390]
   10a58:      	add	x16, x16, #0x390
   10a5c:      	br	x17

0000000000010a60 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   10a60:      	adrp	x16, 0x15000
   10a64:      	ldr	x17, [x16, #0x398]
   10a68:      	add	x16, x16, #0x398
   10a6c:      	br	x17

0000000000010a70 <vsnprintf@plt>:
   10a70:      	adrp	x16, 0x15000
   10a74:      	ldr	x17, [x16, #0x3a0]
   10a78:      	add	x16, x16, #0x3a0
   10a7c:      	br	x17

0000000000010a80 <__vsnprintf_chk@plt>:
   10a80:      	adrp	x16, 0x15000
   10a84:      	ldr	x17, [x16, #0x3a8]
   10a88:      	add	x16, x16, #0x3a8
   10a8c:      	br	x17

0000000000010a90 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
   10a90:      	adrp	x16, 0x15000
   10a94:      	ldr	x17, [x16, #0x3b0]
   10a98:      	add	x16, x16, #0x3b0
   10a9c:      	br	x17

0000000000010aa0 <_ZN5utils8TimeCostC1Ev@plt>:
   10aa0:      	adrp	x16, 0x15000
   10aa4:      	ldr	x17, [x16, #0x3b8]
   10aa8:      	add	x16, x16, #0x3b8
   10aac:      	br	x17

0000000000010ab0 <_ZN5utils8TimeCostD1Ev@plt>:
   10ab0:      	adrp	x16, 0x15000
   10ab4:      	ldr	x17, [x16, #0x3c0]
   10ab8:      	add	x16, x16, #0x3c0
   10abc:      	br	x17

0000000000010ac0 <_ZNK5utils11LogTimeCost3logEPKcz@plt>:
   10ac0:      	adrp	x16, 0x15000
   10ac4:      	ldr	x17, [x16, #0x3c8]
   10ac8:      	add	x16, x16, #0x3c8
   10acc:      	br	x17

0000000000010ad0 <_ZN13VLLogMediator11getInstanceEv@plt>:
   10ad0:      	adrp	x16, 0x15000
   10ad4:      	ldr	x17, [x16, #0x3d0]
   10ad8:      	add	x16, x16, #0x3d0
   10adc:      	br	x17

0000000000010ae0 <__cxa_guard_acquire@plt>:
   10ae0:      	adrp	x16, 0x15000
   10ae4:      	ldr	x17, [x16, #0x3d8]
   10ae8:      	add	x16, x16, #0x3d8
   10aec:      	br	x17

0000000000010af0 <__cxa_guard_release@plt>:
   10af0:      	adrp	x16, 0x15000
   10af4:      	ldr	x17, [x16, #0x3e0]
   10af8:      	add	x16, x16, #0x3e0
   10afc:      	br	x17

0000000000010b00 <_ZN13VLLogMediator3endEv@plt>:
   10b00:      	adrp	x16, 0x15000
   10b04:      	ldr	x17, [x16, #0x3e8]
   10b08:      	add	x16, x16, #0x3e8
   10b0c:      	br	x17

0000000000010b10 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
   10b10:      	adrp	x16, 0x15000
   10b14:      	ldr	x17, [x16, #0x3f0]
   10b18:      	add	x16, x16, #0x3f0
   10b1c:      	br	x17

0000000000010b20 <_ZNSt6__ndk15mutexD1Ev@plt>:
   10b20:      	adrp	x16, 0x15000
   10b24:      	ldr	x17, [x16, #0x3f8]
   10b28:      	add	x16, x16, #0x3f8
   10b2c:      	br	x17

0000000000010b30 <_ZNSt6__ndk16threadD1Ev@plt>:
   10b30:      	adrp	x16, 0x15000
   10b34:      	ldr	x17, [x16, #0x400]
   10b38:      	add	x16, x16, #0x400
   10b3c:      	br	x17

0000000000010b40 <_ZNSt6__ndk15mutex4lockEv@plt>:
   10b40:      	adrp	x16, 0x15000
   10b44:      	ldr	x17, [x16, #0x408]
   10b48:      	add	x16, x16, #0x408
   10b4c:      	br	x17

0000000000010b50 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   10b50:      	adrp	x16, 0x15000
   10b54:      	ldr	x17, [x16, #0x410]
   10b58:      	add	x16, x16, #0x410
   10b5c:      	br	x17

0000000000010b60 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
   10b60:      	adrp	x16, 0x15000
   10b64:      	ldr	x17, [x16, #0x418]
   10b68:      	add	x16, x16, #0x418
   10b6c:      	br	x17

0000000000010b70 <_ZNSt6__ndk16thread4joinEv@plt>:
   10b70:      	adrp	x16, 0x15000
   10b74:      	ldr	x17, [x16, #0x420]
   10b78:      	add	x16, x16, #0x420
   10b7c:      	br	x17

0000000000010b80 <_Z15vlcollect_resetv@plt>:
   10b80:      	adrp	x16, 0x15000
   10b84:      	ldr	x17, [x16, #0x428]
   10b88:      	add	x16, x16, #0x428
   10b8c:      	br	x17

0000000000010b90 <_ZN13VLLogMediator4initERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   10b90:      	adrp	x16, 0x15000
   10b94:      	ldr	x17, [x16, #0x430]
   10b98:      	add	x16, x16, #0x430
   10b9c:      	br	x17

0000000000010ba0 <_Z14vlcollect_initPKc@plt>:
   10ba0:      	adrp	x16, 0x15000
   10ba4:      	ldr	x17, [x16, #0x438]
   10ba8:      	add	x16, x16, #0x438
   10bac:      	br	x17

0000000000010bb0 <_ZN13VLLogMediator15setConfigParamsERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   10bb0:      	adrp	x16, 0x15000
   10bb4:      	ldr	x17, [x16, #0x440]
   10bb8:      	add	x16, x16, #0x440
   10bbc:      	br	x17

0000000000010bc0 <_Z20vlcollect_set_configPKc@plt>:
   10bc0:      	adrp	x16, 0x15000
   10bc4:      	ldr	x17, [x16, #0x448]
   10bc8:      	add	x16, x16, #0x448
   10bcc:      	br	x17

0000000000010bd0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
   10bd0:      	adrp	x16, 0x15000
   10bd4:      	ldr	x17, [x16, #0x450]
   10bd8:      	add	x16, x16, #0x450
   10bdc:      	br	x17

0000000000010be0 <pthread_create@plt>:
   10be0:      	adrp	x16, 0x15000
   10be4:      	ldr	x17, [x16, #0x458]
   10be8:      	add	x16, x16, #0x458
   10bec:      	br	x17

0000000000010bf0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
   10bf0:      	adrp	x16, 0x15000
   10bf4:      	ldr	x17, [x16, #0x460]
   10bf8:      	add	x16, x16, #0x460
   10bfc:      	br	x17

0000000000010c00 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
   10c00:      	adrp	x16, 0x15000
   10c04:      	ldr	x17, [x16, #0x468]
   10c08:      	add	x16, x16, #0x468
   10c0c:      	br	x17

0000000000010c10 <__cxa_rethrow@plt>:
   10c10:      	adrp	x16, 0x15000
   10c14:      	ldr	x17, [x16, #0x470]
   10c18:      	add	x16, x16, #0x470
   10c1c:      	br	x17

0000000000010c20 <_ZN13VLLogMediator14setLogCallbackERKNSt6__ndk18functionIFvRKNS0_6vectorI11vllog_entryNS0_9allocatorIS3_EEEEEEE@plt>:
   10c20:      	adrp	x16, 0x15000
   10c24:      	ldr	x17, [x16, #0x478]
   10c28:      	add	x16, x16, #0x478
   10c2c:      	br	x17

0000000000010c30 <_ZN13VLLogMediator13setTagExcludeEPKci@plt>:
   10c30:      	adrp	x16, 0x15000
   10c34:      	ldr	x17, [x16, #0x480]
   10c38:      	add	x16, x16, #0x480
   10c3c:      	br	x17

0000000000010c40 <_Z26vlcollect_set_tag_excludedPKci@plt>:
   10c40:      	adrp	x16, 0x15000
   10c44:      	ldr	x17, [x16, #0x488]
   10c48:      	add	x16, x16, #0x488
   10c4c:      	br	x17

0000000000010c50 <_Z19vlcollect_get_stateP15vlcollect_state@plt>:
   10c50:      	adrp	x16, 0x15000
   10c54:      	ldr	x17, [x16, #0x490]
   10c58:      	add	x16, x16, #0x490
   10c5c:      	br	x17

0000000000010c60 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm@plt>:
   10c60:      	adrp	x16, 0x15000
   10c64:      	ldr	x17, [x16, #0x498]
   10c68:      	add	x16, x16, #0x498
   10c6c:      	br	x17

0000000000010c70 <_ZN13VLLogMediator17formatMessageSafeERK11vllog_entry@plt>:
   10c70:      	adrp	x16, 0x15000
   10c74:      	ldr	x17, [x16, #0x4a0]
   10c78:      	add	x16, x16, #0x4a0
   10c7c:      	br	x17

0000000000010c80 <_ZN13VLLogMediator15getVllogVersionEv@plt>:
   10c80:      	adrp	x16, 0x15000
   10c84:      	ldr	x17, [x16, #0x4a8]
   10c88:      	add	x16, x16, #0x4a8
   10c8c:      	br	x17

0000000000010c90 <_Z17vllog_get_versionv@plt>:
   10c90:      	adrp	x16, 0x15000
   10c94:      	ldr	x17, [x16, #0x4b0]
   10c98:      	add	x16, x16, #0x4b0
   10c9c:      	br	x17

0000000000010ca0 <_ZN13VLLogMediator7runLoopEv@plt>:
   10ca0:      	adrp	x16, 0x15000
   10ca4:      	ldr	x17, [x16, #0x4b8]
   10ca8:      	add	x16, x16, #0x4b8
   10cac:      	br	x17

0000000000010cb0 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
   10cb0:      	adrp	x16, 0x15000
   10cb4:      	ldr	x17, [x16, #0x4c0]
   10cb8:      	add	x16, x16, #0x4c0
   10cbc:      	br	x17

0000000000010cc0 <_ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE@plt>:
   10cc0:      	adrp	x16, 0x15000
   10cc4:      	ldr	x17, [x16, #0x4c8]
   10cc8:      	add	x16, x16, #0x4c8
   10ccc:      	br	x17

0000000000010cd0 <_Z19vlcollect_get_entryP11vllog_entry@plt>:
   10cd0:      	adrp	x16, 0x15000
   10cd4:      	ldr	x17, [x16, #0x4d0]
   10cd8:      	add	x16, x16, #0x4d0
   10cdc:      	br	x17

0000000000010ce0 <_Z20vlcollect_entry_freeP11vllog_entry@plt>:
   10ce0:      	adrp	x16, 0x15000
   10ce4:      	ldr	x17, [x16, #0x4d8]
   10ce8:      	add	x16, x16, #0x4d8
   10cec:      	br	x17

0000000000010cf0 <_ZN13VLLogMediator8testDataEv@plt>:
   10cf0:      	adrp	x16, 0x15000
   10cf4:      	ldr	x17, [x16, #0x4e0]
   10cf8:      	add	x16, x16, #0x4e0
   10cfc:      	br	x17

0000000000010d00 <_Z15vllog_tag_print13vllog_level_tPKcS1_S1_z@plt>:
   10d00:      	adrp	x16, 0x15000
   10d04:      	ldr	x17, [x16, #0x4e8]
   10d08:      	add	x16, x16, #0x4e8
   10d0c:      	br	x17

0000000000010d10 <_ZNSt6__ndk111this_thread9sleep_forERKNS_6chrono8durationIxNS_5ratioILl1ELl1000000000EEEEE@plt>:
   10d10:      	adrp	x16, 0x15000
   10d14:      	ldr	x17, [x16, #0x4f0]
   10d18:      	add	x16, x16, #0x4f0
   10d1c:      	br	x17

0000000000010d20 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
   10d20:      	adrp	x16, 0x15000
   10d24:      	ldr	x17, [x16, #0x4f8]
   10d28:      	add	x16, x16, #0x4f8
   10d2c:      	br	x17

0000000000010d30 <pthread_setspecific@plt>:
   10d30:      	adrp	x16, 0x15000
   10d34:      	ldr	x17, [x16, #0x500]
   10d38:      	add	x16, x16, #0x500
   10d3c:      	br	x17

0000000000010d40 <__android_log_print@plt>:
   10d40:      	adrp	x16, 0x15000
   10d44:      	ldr	x17, [x16, #0x508]
   10d48:      	add	x16, x16, #0x508
   10d4c:      	br	x17

0000000000010d50 <fprintf@plt>:
   10d50:      	adrp	x16, 0x15000
   10d54:      	ldr	x17, [x16, #0x510]
   10d58:      	add	x16, x16, #0x510
   10d5c:      	br	x17

0000000000010d60 <fflush@plt>:
   10d60:      	adrp	x16, 0x15000
   10d64:      	ldr	x17, [x16, #0x518]
   10d68:      	add	x16, x16, #0x518
   10d6c:      	br	x17

0000000000010d70 <abort@plt>:
   10d70:      	adrp	x16, 0x15000
   10d74:      	ldr	x17, [x16, #0x520]
   10d78:      	add	x16, x16, #0x520
   10d7c:      	br	x17

0000000000010d80 <pthread_rwlock_wrlock@plt>:
   10d80:      	adrp	x16, 0x15000
   10d84:      	ldr	x17, [x16, #0x528]
   10d88:      	add	x16, x16, #0x528
   10d8c:      	br	x17

0000000000010d90 <pthread_rwlock_unlock@plt>:
   10d90:      	adrp	x16, 0x15000
   10d94:      	ldr	x17, [x16, #0x530]
   10d98:      	add	x16, x16, #0x530
   10d9c:      	br	x17

0000000000010da0 <dl_iterate_phdr@plt>:
   10da0:      	adrp	x16, 0x15000
   10da4:      	ldr	x17, [x16, #0x538]
   10da8:      	add	x16, x16, #0x538
   10dac:      	br	x17

0000000000010db0 <pthread_rwlock_rdlock@plt>:
   10db0:      	adrp	x16, 0x15000
   10db4:      	ldr	x17, [x16, #0x540]
   10db8:      	add	x16, x16, #0x540
   10dbc:      	br	x17

0000000000010dc0 <getpid@plt>:
   10dc0:      	adrp	x16, 0x15000
   10dc4:      	ldr	x17, [x16, #0x548]
   10dc8:      	add	x16, x16, #0x548
   10dcc:      	br	x17

0000000000010dd0 <syscall@plt>:
   10dd0:      	adrp	x16, 0x15000
   10dd4:      	ldr	x17, [x16, #0x550]
   10dd8:      	add	x16, x16, #0x550
   10ddc:      	br	x17
