// EXPORTED & PLT DISASSEMBLY FOR libKKMusicFX.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libKKMusicFX.so (SHA-256: CD876A2E49A129B1BCEFDC4ACA42047FAA4AAF954C6C1286EDB80209AC38031D)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 112, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libKKMusicFX.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000007a830 <.plt>:
   7a830:      	stp	x16, x30, [sp, #-0x10]!
   7a834:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a838:      	ldr	x17, [x16, #0xde8]
   7a83c:      	add	x16, x16, #0xde8
   7a840:      	br	x17
   7a844:      	nop
   7a848:      	nop
   7a84c:      	nop

000000000007a850 <__cxa_finalize@plt>:
   7a850:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a854:      	ldr	x17, [x16, #0xdf0]
   7a858:      	add	x16, x16, #0xdf0
   7a85c:      	br	x17

000000000007a860 <__cxa_atexit@plt>:
   7a860:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a864:      	ldr	x17, [x16, #0xdf8]
   7a868:      	add	x16, x16, #0xdf8
   7a86c:      	br	x17

000000000007a870 <_ZdlPv@plt>:
   7a870:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a874:      	ldr	x17, [x16, #0xe00]
   7a878:      	add	x16, x16, #0xe00
   7a87c:      	br	x17

000000000007a880 <_Znwm@plt>:
   7a880:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a884:      	ldr	x17, [x16, #0xe08]
   7a888:      	add	x16, x16, #0xe08
   7a88c:      	br	x17

000000000007a890 <memset@plt>:
   7a890:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a894:      	ldr	x17, [x16, #0xe10]
   7a898:      	add	x16, x16, #0xe10
   7a89c:      	br	x17

000000000007a8a0 <memcpy@plt>:
   7a8a0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a8a4:      	ldr	x17, [x16, #0xe18]
   7a8a8:      	add	x16, x16, #0xe18
   7a8ac:      	br	x17

000000000007a8b0 <free@plt>:
   7a8b0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a8b4:      	ldr	x17, [x16, #0xe20]
   7a8b8:      	add	x16, x16, #0xe20
   7a8bc:      	br	x17

000000000007a8c0 <__stack_chk_fail@plt>:
   7a8c0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a8c4:      	ldr	x17, [x16, #0xe28]
   7a8c8:      	add	x16, x16, #0xe28
   7a8cc:      	br	x17

000000000007a8d0 <_ZN3MFX12analyzeAudioERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
   7a8d0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a8d4:      	ldr	x17, [x16, #0xe30]
   7a8d8:      	add	x16, x16, #0xe30
   7a8dc:      	br	x17

000000000007a8e0 <_ZN3MFX10MFXManager38getAudioParameterSupportedByProcessingEv@plt>:
   7a8e0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a8e4:      	ldr	x17, [x16, #0xe38]
   7a8e8:      	add	x16, x16, #0xe38
   7a8ec:      	br	x17

000000000007a8f0 <_ZN3MFX21transformSampleFormatENS_13FormatLibTypeEiS0_@plt>:
   7a8f0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a8f4:      	ldr	x17, [x16, #0xe40]
   7a8f8:      	add	x16, x16, #0xe40
   7a8fc:      	br	x17

000000000007a900 <_ZN3MFX10MFXManager26getMaximumNbSamplePerBlockEv@plt>:
   7a900:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a904:      	ldr	x17, [x16, #0xe48]
   7a908:      	add	x16, x16, #0xe48
   7a90c:      	br	x17

000000000007a910 <_ZN3MFX25AudioSourceAnalyzedResultC1Ev@plt>:
   7a910:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a914:      	ldr	x17, [x16, #0xe50]
   7a918:      	add	x16, x16, #0xe50
   7a91c:      	br	x17

000000000007a920 <_ZN3MFX3RefD2Ev@plt>:
   7a920:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a924:      	ldr	x17, [x16, #0xe58]
   7a928:      	add	x16, x16, #0xe58
   7a92c:      	br	x17

000000000007a930 <__cxa_allocate_exception@plt>:
   7a930:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a934:      	ldr	x17, [x16, #0xe60]
   7a938:      	add	x16, x16, #0xe60
   7a93c:      	br	x17

000000000007a940 <__cxa_throw@plt>:
   7a940:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a944:      	ldr	x17, [x16, #0xe68]
   7a948:      	add	x16, x16, #0xe68
   7a94c:      	br	x17

000000000007a950 <__cxa_free_exception@plt>:
   7a950:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a954:      	ldr	x17, [x16, #0xe70]
   7a958:      	add	x16, x16, #0xe70
   7a95c:      	br	x17

000000000007a960 <_ZNSt11logic_errorC2EPKc@plt>:
   7a960:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a964:      	ldr	x17, [x16, #0xe78]
   7a968:      	add	x16, x16, #0xe78
   7a96c:      	br	x17

000000000007a970 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   7a970:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a974:      	ldr	x17, [x16, #0xe80]
   7a978:      	add	x16, x16, #0xe80
   7a97c:      	br	x17

000000000007a980 <memmove@plt>:
   7a980:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a984:      	ldr	x17, [x16, #0xe88]
   7a988:      	add	x16, x16, #0xe88
   7a98c:      	br	x17

000000000007a990 <_ZN3MFX6GainFXC2Ev@plt>:
   7a990:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a994:      	ldr	x17, [x16, #0xe90]
   7a998:      	add	x16, x16, #0xe90
   7a99c:      	br	x17

000000000007a9a0 <_ZN3MFX8IMusicFXC2ENS_7MFXTypeE@plt>:
   7a9a0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a9a4:      	ldr	x17, [x16, #0xe98]
   7a9a8:      	add	x16, x16, #0xe98
   7a9ac:      	br	x17

000000000007a9b0 <_ZN3MFX8IMusicFXD2Ev@plt>:
   7a9b0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a9b4:      	ldr	x17, [x16, #0xea0]
   7a9b8:      	add	x16, x16, #0xea0
   7a9bc:      	br	x17

000000000007a9c0 <_ZN3MFX6GainFXD2Ev@plt>:
   7a9c0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a9c4:      	ldr	x17, [x16, #0xea8]
   7a9c8:      	add	x16, x16, #0xea8
   7a9cc:      	br	x17

000000000007a9d0 <_ZN3MFX6GainFXD1Ev@plt>:
   7a9d0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a9d4:      	ldr	x17, [x16, #0xeb0]
   7a9d8:      	add	x16, x16, #0xeb0
   7a9dc:      	br	x17

000000000007a9e0 <_ZN3MFX6GainFX13setParametersERKNS0_10ParametersE@plt>:
   7a9e0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a9e4:      	ldr	x17, [x16, #0xeb8]
   7a9e8:      	add	x16, x16, #0xeb8
   7a9ec:      	br	x17

000000000007a9f0 <_ZNK3MFX6GainFX13getParametersEv@plt>:
   7a9f0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7a9f4:      	ldr	x17, [x16, #0xec0]
   7a9f8:      	add	x16, x16, #0xec0
   7a9fc:      	br	x17

000000000007aa00 <_ZN3MFX6GainFX12processBlockEPv@plt>:
   7aa00:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa04:      	ldr	x17, [x16, #0xec8]
   7aa08:      	add	x16, x16, #0xec8
   7aa0c:      	br	x17

000000000007aa10 <_ZN3MFX6GainFX5resetEv@plt>:
   7aa10:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa14:      	ldr	x17, [x16, #0xed0]
   7aa18:      	add	x16, x16, #0xed0
   7aa1c:      	br	x17

000000000007aa20 <_ZN3MFX6GainFXC1Ev@plt>:
   7aa20:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa24:      	ldr	x17, [x16, #0xed8]
   7aa28:      	add	x16, x16, #0xed8
   7aa2c:      	br	x17

000000000007aa30 <_ZN3MFX11EqualizerFXD1Ev@plt>:
   7aa30:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa34:      	ldr	x17, [x16, #0xee0]
   7aa38:      	add	x16, x16, #0xee0
   7aa3c:      	br	x17

000000000007aa40 <_ZN3MFX11EqualizerFX13setParametersERKNS0_10ParametersE@plt>:
   7aa40:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa44:      	ldr	x17, [x16, #0xee8]
   7aa48:      	add	x16, x16, #0xee8
   7aa4c:      	br	x17

000000000007aa50 <_ZNK3MFX11EqualizerFX13getParametersEv@plt>:
   7aa50:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa54:      	ldr	x17, [x16, #0xef0]
   7aa58:      	add	x16, x16, #0xef0
   7aa5c:      	br	x17

000000000007aa60 <powf@plt>:
   7aa60:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa64:      	ldr	x17, [x16, #0xef8]
   7aa68:      	add	x16, x16, #0xef8
   7aa6c:      	br	x17

000000000007aa70 <__cxa_begin_catch@plt>:
   7aa70:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa74:      	ldr	x17, [x16, #0xf00]
   7aa78:      	add	x16, x16, #0xf00
   7aa7c:      	br	x17

000000000007aa80 <_ZSt9terminatev@plt>:
   7aa80:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa84:      	ldr	x17, [x16, #0xf08]
   7aa88:      	add	x16, x16, #0xf08
   7aa8c:      	br	x17

000000000007aa90 <malloc@plt>:
   7aa90:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aa94:      	ldr	x17, [x16, #0xf10]
   7aa98:      	add	x16, x16, #0xf10
   7aa9c:      	br	x17

000000000007aaa0 <realloc@plt>:
   7aaa0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aaa4:      	ldr	x17, [x16, #0xf18]
   7aaa8:      	add	x16, x16, #0xf18
   7aaac:      	br	x17

000000000007aab0 <_ZN3MFX11EqualizerFXC1Ev@plt>:
   7aab0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aab4:      	ldr	x17, [x16, #0xf20]
   7aab8:      	add	x16, x16, #0xf20
   7aabc:      	br	x17

000000000007aac0 <_ZN3MFX8ReverbFXD1Ev@plt>:
   7aac0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aac4:      	ldr	x17, [x16, #0xf28]
   7aac8:      	add	x16, x16, #0xf28
   7aacc:      	br	x17

000000000007aad0 <_ZN3MFX8ReverbFX13setParametersERKNS0_10ParametersE@plt>:
   7aad0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aad4:      	ldr	x17, [x16, #0xf30]
   7aad8:      	add	x16, x16, #0xf30
   7aadc:      	br	x17

000000000007aae0 <_ZNK3MFX8ReverbFX13getParametersEv@plt>:
   7aae0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aae4:      	ldr	x17, [x16, #0xf38]
   7aae8:      	add	x16, x16, #0xf38
   7aaec:      	br	x17

000000000007aaf0 <_ZN3MFX8ReverbFXC1Ev@plt>:
   7aaf0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aaf4:      	ldr	x17, [x16, #0xf40]
   7aaf8:      	add	x16, x16, #0xf40
   7aafc:      	br	x17

000000000007ab00 <_ZN3MFX10SurroundFXD1Ev@plt>:
   7ab00:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab04:      	ldr	x17, [x16, #0xf48]
   7ab08:      	add	x16, x16, #0xf48
   7ab0c:      	br	x17

000000000007ab10 <_ZN3MFX10SurroundFX13setParametersERKNS0_10ParametersE@plt>:
   7ab10:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab14:      	ldr	x17, [x16, #0xf50]
   7ab18:      	add	x16, x16, #0xf50
   7ab1c:      	br	x17

000000000007ab20 <_ZNK3MFX10SurroundFX13getParametersEv@plt>:
   7ab20:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab24:      	ldr	x17, [x16, #0xf58]
   7ab28:      	add	x16, x16, #0xf58
   7ab2c:      	br	x17

000000000007ab30 <sinf@plt>:
   7ab30:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab34:      	ldr	x17, [x16, #0xf60]
   7ab38:      	add	x16, x16, #0xf60
   7ab3c:      	br	x17

000000000007ab40 <_ZN3MFX10SurroundFXC1Ev@plt>:
   7ab40:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab44:      	ldr	x17, [x16, #0xf68]
   7ab48:      	add	x16, x16, #0xf68
   7ab4c:      	br	x17

000000000007ab50 <_ZN3MFX7DelayFXD1Ev@plt>:
   7ab50:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab54:      	ldr	x17, [x16, #0xf70]
   7ab58:      	add	x16, x16, #0xf70
   7ab5c:      	br	x17

000000000007ab60 <_ZN3MFX7DelayFX13setParametersERKNS0_10ParametersE@plt>:
   7ab60:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab64:      	ldr	x17, [x16, #0xf78]
   7ab68:      	add	x16, x16, #0xf78
   7ab6c:      	br	x17

000000000007ab70 <_ZNK3MFX7DelayFX13getParametersEv@plt>:
   7ab70:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab74:      	ldr	x17, [x16, #0xf80]
   7ab78:      	add	x16, x16, #0xf80
   7ab7c:      	br	x17

000000000007ab80 <_ZN3MFX7DelayFXC1Ev@plt>:
   7ab80:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab84:      	ldr	x17, [x16, #0xf88]
   7ab88:      	add	x16, x16, #0xf88
   7ab8c:      	br	x17

000000000007ab90 <_ZN3MFX10BandpassFXD1Ev@plt>:
   7ab90:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ab94:      	ldr	x17, [x16, #0xf90]
   7ab98:      	add	x16, x16, #0xf90
   7ab9c:      	br	x17

000000000007aba0 <_ZN3MFX10BandpassFX13setParametersERKNS0_10ParametersE@plt>:
   7aba0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7aba4:      	ldr	x17, [x16, #0xf98]
   7aba8:      	add	x16, x16, #0xf98
   7abac:      	br	x17

000000000007abb0 <_ZNK3MFX10BandpassFX13getParametersEv@plt>:
   7abb0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7abb4:      	ldr	x17, [x16, #0xfa0]
   7abb8:      	add	x16, x16, #0xfa0
   7abbc:      	br	x17

000000000007abc0 <_ZN3MFX10BandpassFXC1Ev@plt>:
   7abc0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7abc4:      	ldr	x17, [x16, #0xfa8]
   7abc8:      	add	x16, x16, #0xfa8
   7abcc:      	br	x17

000000000007abd0 <_ZN8PVGVIDEO13PVGVideoCodec6createENS_12PVGCodecTypeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   7abd0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7abd4:      	ldr	x17, [x16, #0xfb0]
   7abd8:      	add	x16, x16, #0xfb0
   7abdc:      	br	x17

000000000007abe0 <_ZN8PVGVIDEO10PVGContextC1Ev@plt>:
   7abe0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7abe4:      	ldr	x17, [x16, #0xfb8]
   7abe8:      	add	x16, x16, #0xfb8
   7abec:      	br	x17

000000000007abf0 <_ZN8PVGVIDEO10PVGContext14setCodecParamsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   7abf0:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7abf4:      	ldr	x17, [x16, #0xfc0]
   7abf8:      	add	x16, x16, #0xfc0
   7abfc:      	br	x17

000000000007ac00 <__android_log_print@plt>:
   7ac00:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac04:      	ldr	x17, [x16, #0xfc8]
   7ac08:      	add	x16, x16, #0xfc8
   7ac0c:      	br	x17

000000000007ac10 <_Znam@plt>:
   7ac10:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac14:      	ldr	x17, [x16, #0xfd0]
   7ac18:      	add	x16, x16, #0xfd0
   7ac1c:      	br	x17

000000000007ac20 <_ZN8PVGVIDEO14PVGPCMTransferC1Ev@plt>:
   7ac20:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac24:      	ldr	x17, [x16, #0xfd8]
   7ac28:      	add	x16, x16, #0xfd8
   7ac2c:      	br	x17

000000000007ac30 <_ZN8PVGVIDEO14PVGPCMTransfer4initENS_9PVGFormatEiiS1_ii@plt>:
   7ac30:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac34:      	ldr	x17, [x16, #0xfe0]
   7ac38:      	add	x16, x16, #0xfe0
   7ac3c:      	br	x17

000000000007ac40 <_ZNK8PVGVIDEO13PVGAudioFrame12getSamplesNbEv@plt>:
   7ac40:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac44:      	ldr	x17, [x16, #0xfe8]
   7ac48:      	add	x16, x16, #0xfe8
   7ac4c:      	br	x17

000000000007ac50 <_ZN8PVGVIDEO14PVGPCMTransfer5writeEPPhi@plt>:
   7ac50:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac54:      	ldr	x17, [x16, #0xff0]
   7ac58:      	add	x16, x16, #0xff0
   7ac5c:      	br	x17

000000000007ac60 <_ZN8PVGVIDEO14PVGPCMTransfer4readEPPhPii@plt>:
   7ac60:      	adrp	x16, 0x81000 <_ZTIN3MFX11KKLoudMeterE+0x1740>
   7ac64:      	ldr	x17, [x16, #0xff8]
   7ac68:      	add	x16, x16, #0xff8
   7ac6c:      	br	x17

000000000007ac70 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   7ac70:      	adrp	x16, 0x82000
   7ac74:      	ldr	x17, [x16]
   7ac78:      	add	x16, x16, #0x0
   7ac7c:      	br	x17

000000000007ac80 <_ZdaPv@plt>:
   7ac80:      	adrp	x16, 0x82000
   7ac84:      	ldr	x17, [x16, #0x8]
   7ac88:      	add	x16, x16, #0x8
   7ac8c:      	br	x17

000000000007ac90 <__cxa_rethrow@plt>:
   7ac90:      	adrp	x16, 0x82000
   7ac94:      	ldr	x17, [x16, #0x10]
   7ac98:      	add	x16, x16, #0x10
   7ac9c:      	br	x17

000000000007aca0 <__cxa_end_catch@plt>:
   7aca0:      	adrp	x16, 0x82000
   7aca4:      	ldr	x17, [x16, #0x18]
   7aca8:      	add	x16, x16, #0x18
   7acac:      	br	x17

000000000007acb0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   7acb0:      	adrp	x16, 0x82000
   7acb4:      	ldr	x17, [x16, #0x20]
   7acb8:      	add	x16, x16, #0x20
   7acbc:      	br	x17

000000000007acc0 <_ZNSt9exceptionD2Ev@plt>:
   7acc0:      	adrp	x16, 0x82000
   7acc4:      	ldr	x17, [x16, #0x28]
   7acc8:      	add	x16, x16, #0x28
   7accc:      	br	x17

000000000007acd0 <memchr@plt>:
   7acd0:      	adrp	x16, 0x82000
   7acd4:      	ldr	x17, [x16, #0x30]
   7acd8:      	add	x16, x16, #0x30
   7acdc:      	br	x17

000000000007ace0 <memcmp@plt>:
   7ace0:      	adrp	x16, 0x82000
   7ace4:      	ldr	x17, [x16, #0x38]
   7ace8:      	add	x16, x16, #0x38
   7acec:      	br	x17

000000000007acf0 <strlen@plt>:
   7acf0:      	adrp	x16, 0x82000
   7acf4:      	ldr	x17, [x16, #0x40]
   7acf8:      	add	x16, x16, #0x40
   7acfc:      	br	x17

000000000007ad00 <_ZN3MFX10MFXFormula9toFormulaEPNS_10MFXManagerE@plt>:
   7ad00:      	adrp	x16, 0x82000
   7ad04:      	ldr	x17, [x16, #0x48]
   7ad08:      	add	x16, x16, #0x48
   7ad0c:      	br	x17

000000000007ad10 <_ZNK3MFX10MFXManager21getMaximumSampleLevelEv@plt>:
   7ad10:      	adrp	x16, 0x82000
   7ad14:      	ldr	x17, [x16, #0x50]
   7ad18:      	add	x16, x16, #0x50
   7ad1c:      	br	x17

000000000007ad20 <_ZNK3MFX10MFXManager6getFXsEv@plt>:
   7ad20:      	adrp	x16, 0x82000
   7ad24:      	ldr	x17, [x16, #0x58]
   7ad28:      	add	x16, x16, #0x58
   7ad2c:      	br	x17

000000000007ad30 <_ZN3MFX8IMusicFX11getTypeNameEv@plt>:
   7ad30:      	adrp	x16, 0x82000
   7ad34:      	ldr	x17, [x16, #0x60]
   7ad38:      	add	x16, x16, #0x60
   7ad3c:      	br	x17

000000000007ad40 <_ZN3MFX8IMusicFX7getTypeEv@plt>:
   7ad40:      	adrp	x16, 0x82000
   7ad44:      	ldr	x17, [x16, #0x68]
   7ad48:      	add	x16, x16, #0x68
   7ad4c:      	br	x17

000000000007ad50 <_ZN3MFX10MFXFormula11fromFormulaERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7ad50:      	adrp	x16, 0x82000
   7ad54:      	ldr	x17, [x16, #0x70]
   7ad58:      	add	x16, x16, #0x70
   7ad5c:      	br	x17

000000000007ad60 <_ZN3MFX10MFXManagerC1Ev@plt>:
   7ad60:      	adrp	x16, 0x82000
   7ad64:      	ldr	x17, [x16, #0x78]
   7ad68:      	add	x16, x16, #0x78
   7ad6c:      	br	x17

000000000007ad70 <__strlen_chk@plt>:
   7ad70:      	adrp	x16, 0x82000
   7ad74:      	ldr	x17, [x16, #0x80]
   7ad78:      	add	x16, x16, #0x80
   7ad7c:      	br	x17

000000000007ad80 <_ZN3MFX10MFXFormula14adjustStrengthERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_10MFXManagerEf@plt>:
   7ad80:      	adrp	x16, 0x82000
   7ad84:      	ldr	x17, [x16, #0x88]
   7ad88:      	add	x16, x16, #0x88
   7ad8c:      	br	x17

000000000007ad90 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   7ad90:      	adrp	x16, 0x82000
   7ad94:      	ldr	x17, [x16, #0x90]
   7ad98:      	add	x16, x16, #0x90
   7ad9c:      	br	x17

000000000007ada0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi@plt>:
   7ada0:      	adrp	x16, 0x82000
   7ada4:      	ldr	x17, [x16, #0x98]
   7ada8:      	add	x16, x16, #0x98
   7adac:      	br	x17

000000000007adb0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   7adb0:      	adrp	x16, 0x82000
   7adb4:      	ldr	x17, [x16, #0xa0]
   7adb8:      	add	x16, x16, #0xa0
   7adbc:      	br	x17

000000000007adc0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
   7adc0:      	adrp	x16, 0x82000
   7adc4:      	ldr	x17, [x16, #0xa8]
   7adc8:      	add	x16, x16, #0xa8
   7adcc:      	br	x17

000000000007add0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   7add0:      	adrp	x16, 0x82000
   7add4:      	ldr	x17, [x16, #0xb0]
   7add8:      	add	x16, x16, #0xb0
   7addc:      	br	x17

000000000007ade0 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   7ade0:      	adrp	x16, 0x82000
   7ade4:      	ldr	x17, [x16, #0xb8]
   7ade8:      	add	x16, x16, #0xb8
   7adec:      	br	x17

000000000007adf0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   7adf0:      	adrp	x16, 0x82000
   7adf4:      	ldr	x17, [x16, #0xc0]
   7adf8:      	add	x16, x16, #0xc0
   7adfc:      	br	x17

000000000007ae00 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   7ae00:      	adrp	x16, 0x82000
   7ae04:      	ldr	x17, [x16, #0xc8]
   7ae08:      	add	x16, x16, #0xc8
   7ae0c:      	br	x17

000000000007ae10 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   7ae10:      	adrp	x16, 0x82000
   7ae14:      	ldr	x17, [x16, #0xd0]
   7ae18:      	add	x16, x16, #0xd0
   7ae1c:      	br	x17

000000000007ae20 <_ZN3MFX22getNbSamplesPerChannelEiNS_12SampleFormatEi@plt>:
   7ae20:      	adrp	x16, 0x82000
   7ae24:      	ldr	x17, [x16, #0xd8]
   7ae28:      	add	x16, x16, #0xd8
   7ae2c:      	br	x17

000000000007ae30 <_ZNSt6__ndk15mutex4lockEv@plt>:
   7ae30:      	adrp	x16, 0x82000
   7ae34:      	ldr	x17, [x16, #0xe0]
   7ae38:      	add	x16, x16, #0xe0
   7ae3c:      	br	x17

000000000007ae40 <_ZN3MFX8IMusicFX11registerMFXERKNS0_21RegisterMFXParametersE@plt>:
   7ae40:      	adrp	x16, 0x82000
   7ae44:      	ldr	x17, [x16, #0xe8]
   7ae48:      	add	x16, x16, #0xe8
   7ae4c:      	br	x17

000000000007ae50 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   7ae50:      	adrp	x16, 0x82000
   7ae54:      	ldr	x17, [x16, #0xf0]
   7ae58:      	add	x16, x16, #0xf0
   7ae5c:      	br	x17

000000000007ae60 <__cxa_guard_acquire@plt>:
   7ae60:      	adrp	x16, 0x82000
   7ae64:      	ldr	x17, [x16, #0xf8]
   7ae68:      	add	x16, x16, #0xf8
   7ae6c:      	br	x17

000000000007ae70 <__cxa_guard_release@plt>:
   7ae70:      	adrp	x16, 0x82000
   7ae74:      	ldr	x17, [x16, #0x100]
   7ae78:      	add	x16, x16, #0x100
   7ae7c:      	br	x17

000000000007ae80 <_ZNSt9bad_allocC1Ev@plt>:
   7ae80:      	adrp	x16, 0x82000
   7ae84:      	ldr	x17, [x16, #0x108]
   7ae88:      	add	x16, x16, #0x108
   7ae8c:      	br	x17

000000000007ae90 <pow@plt>:
   7ae90:      	adrp	x16, 0x82000
   7ae94:      	ldr	x17, [x16, #0x110]
   7ae98:      	add	x16, x16, #0x110
   7ae9c:      	br	x17

000000000007aea0 <cosf@plt>:
   7aea0:      	adrp	x16, 0x82000
   7aea4:      	ldr	x17, [x16, #0x118]
   7aea8:      	add	x16, x16, #0x118
   7aeac:      	br	x17

000000000007aeb0 <tan@plt>:
   7aeb0:      	adrp	x16, 0x82000
   7aeb4:      	ldr	x17, [x16, #0x120]
   7aeb8:      	add	x16, x16, #0x120
   7aebc:      	br	x17

000000000007aec0 <_ZN3MFX11KKLoudMeter6createERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7aec0:      	adrp	x16, 0x82000
   7aec4:      	ldr	x17, [x16, #0x128]
   7aec8:      	add	x16, x16, #0x128
   7aecc:      	br	x17

000000000007aed0 <_ZN3MFX11KKLoudMeterC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   7aed0:      	adrp	x16, 0x82000
   7aed4:      	ldr	x17, [x16, #0x130]
   7aed8:      	add	x16, x16, #0x130
   7aedc:      	br	x17

000000000007aee0 <_ZN8PVGVIDEO12PVGAudioInfo5validEv@plt>:
   7aee0:      	adrp	x16, 0x82000
   7aee4:      	ldr	x17, [x16, #0x138]
   7aee8:      	add	x16, x16, #0x138
   7aeec:      	br	x17

000000000007aef0 <_ZN3MFX11KKLoudMeterD1Ev@plt>:
   7aef0:      	adrp	x16, 0x82000
   7aef4:      	ldr	x17, [x16, #0x140]
   7aef8:      	add	x16, x16, #0x140
   7aefc:      	br	x17

000000000007af00 <_ZN3MFX11KKLoudMeter12setTimeRangeEll@plt>:
   7af00:      	adrp	x16, 0x82000
   7af04:      	ldr	x17, [x16, #0x148]
   7af08:      	add	x16, x16, #0x148
   7af0c:      	br	x17

000000000007af10 <_ZN3MFX11KKLoudMeter20calculateAndWaitLUFSEv@plt>:
   7af10:      	adrp	x16, 0x82000
   7af14:      	ldr	x17, [x16, #0x150]
   7af18:      	add	x16, x16, #0x150
   7af1c:      	br	x17

000000000007af20 <_ZN8PVGVIDEO10PVGContext16setCodecStrategyENS_16PVGCodecStrategyE@plt>:
   7af20:      	adrp	x16, 0x82000
   7af24:      	ldr	x17, [x16, #0x158]
   7af28:      	add	x16, x16, #0x158
   7af2c:      	br	x17

000000000007af30 <_ZNSt6__ndk19to_stringEd@plt>:
   7af30:      	adrp	x16, 0x82000
   7af34:      	ldr	x17, [x16, #0x160]
   7af38:      	add	x16, x16, #0x160
   7af3c:      	br	x17

000000000007af40 <_ZN8PVGVIDEO6PVGRef7releaseEv@plt>:
   7af40:      	adrp	x16, 0x82000
   7af44:      	ldr	x17, [x16, #0x168]
   7af48:      	add	x16, x16, #0x168
   7af4c:      	br	x17

000000000007af50 <log10f@plt>:
   7af50:      	adrp	x16, 0x82000
   7af54:      	ldr	x17, [x16, #0x170]
   7af58:      	add	x16, x16, #0x170
   7af5c:      	br	x17

000000000007af60 <pthread_getspecific@plt>:
   7af60:      	adrp	x16, 0x82000
   7af64:      	ldr	x17, [x16, #0x178]
   7af68:      	add	x16, x16, #0x178
   7af6c:      	br	x17

000000000007af70 <pthread_self@plt>:
   7af70:      	adrp	x16, 0x82000
   7af74:      	ldr	x17, [x16, #0x180]
   7af78:      	add	x16, x16, #0x180
   7af7c:      	br	x17

000000000007af80 <pthread_key_create@plt>:
   7af80:      	adrp	x16, 0x82000
   7af84:      	ldr	x17, [x16, #0x188]
   7af88:      	add	x16, x16, #0x188
   7af8c:      	br	x17

000000000007af90 <pthread_setspecific@plt>:
   7af90:      	adrp	x16, 0x82000
   7af94:      	ldr	x17, [x16, #0x190]
   7af98:      	add	x16, x16, #0x190
   7af9c:      	br	x17

000000000007afa0 <JUCE_JNI_OnLoad@plt>:
   7afa0:      	adrp	x16, 0x82000
   7afa4:      	ldr	x17, [x16, #0x198]
   7afa8:      	add	x16, x16, #0x198
   7afac:      	br	x17

000000000007afb0 <_ZNK3MFX25AudioSourceAnalyzedResult7isValidEv@plt>:
   7afb0:      	adrp	x16, 0x82000
   7afb4:      	ldr	x17, [x16, #0x1a0]
   7afb8:      	add	x16, x16, #0x1a0
   7afbc:      	br	x17

000000000007afc0 <_ZN3MFX25AudioSourceAnalyzedResultC1ERKS0_@plt>:
   7afc0:      	adrp	x16, 0x82000
   7afc4:      	ldr	x17, [x16, #0x1a8]
   7afc8:      	add	x16, x16, #0x1a8
   7afcc:      	br	x17

000000000007afd0 <towupper@plt>:
   7afd0:      	adrp	x16, 0x82000
   7afd4:      	ldr	x17, [x16, #0x1b0]
   7afd8:      	add	x16, x16, #0x1b0
   7afdc:      	br	x17

000000000007afe0 <opendir@plt>:
   7afe0:      	adrp	x16, 0x82000
   7afe4:      	ldr	x17, [x16, #0x1b8]
   7afe8:      	add	x16, x16, #0x1b8
   7afec:      	br	x17

000000000007aff0 <getpwnam@plt>:
   7aff0:      	adrp	x16, 0x82000
   7aff4:      	ldr	x17, [x16, #0x1c0]
   7aff8:      	add	x16, x16, #0x1c0
   7affc:      	br	x17

000000000007b000 <__cxa_guard_abort@plt>:
   7b000:      	adrp	x16, 0x82000
   7b004:      	ldr	x17, [x16, #0x1c8]
   7b008:      	add	x16, x16, #0x1c8
   7b00c:      	br	x17

000000000007b010 <getcwd@plt>:
   7b010:      	adrp	x16, 0x82000
   7b014:      	ldr	x17, [x16, #0x1d0]
   7b018:      	add	x16, x16, #0x1d0
   7b01c:      	br	x17

000000000007b020 <__errno@plt>:
   7b020:      	adrp	x16, 0x82000
   7b024:      	ldr	x17, [x16, #0x1d8]
   7b028:      	add	x16, x16, #0x1d8
   7b02c:      	br	x17

000000000007b030 <stat@plt>:
   7b030:      	adrp	x16, 0x82000
   7b034:      	ldr	x17, [x16, #0x1e0]
   7b038:      	add	x16, x16, #0x1e0
   7b03c:      	br	x17

000000000007b040 <remove@plt>:
   7b040:      	adrp	x16, 0x82000
   7b044:      	ldr	x17, [x16, #0x1e8]
   7b048:      	add	x16, x16, #0x1e8
   7b04c:      	br	x17

000000000007b050 <access@plt>:
   7b050:      	adrp	x16, 0x82000
   7b054:      	ldr	x17, [x16, #0x1f0]
   7b058:      	add	x16, x16, #0x1f0
   7b05c:      	br	x17

000000000007b060 <rmdir@plt>:
   7b060:      	adrp	x16, 0x82000
   7b064:      	ldr	x17, [x16, #0x1f8]
   7b068:      	add	x16, x16, #0x1f8
   7b06c:      	br	x17

000000000007b070 <rename@plt>:
   7b070:      	adrp	x16, 0x82000
   7b074:      	ldr	x17, [x16, #0x200]
   7b078:      	add	x16, x16, #0x200
   7b07c:      	br	x17

000000000007b080 <close@plt>:
   7b080:      	adrp	x16, 0x82000
   7b084:      	ldr	x17, [x16, #0x208]
   7b088:      	add	x16, x16, #0x208
   7b08c:      	br	x17

000000000007b090 <mkdir@plt>:
   7b090:      	adrp	x16, 0x82000
   7b094:      	ldr	x17, [x16, #0x210]
   7b098:      	add	x16, x16, #0x210
   7b09c:      	br	x17

000000000007b0a0 <atoi@plt>:
   7b0a0:      	adrp	x16, 0x82000
   7b0a4:      	ldr	x17, [x16, #0x218]
   7b0a8:      	add	x16, x16, #0x218
   7b0ac:      	br	x17

000000000007b0b0 <iswdigit@plt>:
   7b0b0:      	adrp	x16, 0x82000
   7b0b4:      	ldr	x17, [x16, #0x220]
   7b0b8:      	add	x16, x16, #0x220
   7b0bc:      	br	x17

000000000007b0c0 <towlower@plt>:
   7b0c0:      	adrp	x16, 0x82000
   7b0c4:      	ldr	x17, [x16, #0x228]
   7b0c8:      	add	x16, x16, #0x228
   7b0cc:      	br	x17

000000000007b0d0 <write@plt>:
   7b0d0:      	adrp	x16, 0x82000
   7b0d4:      	ldr	x17, [x16, #0x230]
   7b0d8:      	add	x16, x16, #0x230
   7b0dc:      	br	x17

000000000007b0e0 <nanosleep@plt>:
   7b0e0:      	adrp	x16, 0x82000
   7b0e4:      	ldr	x17, [x16, #0x238]
   7b0e8:      	add	x16, x16, #0x238
   7b0ec:      	br	x17

000000000007b0f0 <__read_chk@plt>:
   7b0f0:      	adrp	x16, 0x82000
   7b0f4:      	ldr	x17, [x16, #0x240]
   7b0f8:      	add	x16, x16, #0x240
   7b0fc:      	br	x17

000000000007b100 <readlink@plt>:
   7b100:      	adrp	x16, 0x82000
   7b104:      	ldr	x17, [x16, #0x248]
   7b108:      	add	x16, x16, #0x248
   7b10c:      	br	x17

000000000007b110 <open@plt>:
   7b110:      	adrp	x16, 0x82000
   7b114:      	ldr	x17, [x16, #0x250]
   7b118:      	add	x16, x16, #0x250
   7b11c:      	br	x17

000000000007b120 <__open_2@plt>:
   7b120:      	adrp	x16, 0x82000
   7b124:      	ldr	x17, [x16, #0x258]
   7b128:      	add	x16, x16, #0x258
   7b12c:      	br	x17

000000000007b130 <lseek@plt>:
   7b130:      	adrp	x16, 0x82000
   7b134:      	ldr	x17, [x16, #0x260]
   7b138:      	add	x16, x16, #0x260
   7b13c:      	br	x17

000000000007b140 <fsync@plt>:
   7b140:      	adrp	x16, 0x82000
   7b144:      	ldr	x17, [x16, #0x268]
   7b148:      	add	x16, x16, #0x268
   7b14c:      	br	x17

000000000007b150 <pthread_mutex_destroy@plt>:
   7b150:      	adrp	x16, 0x82000
   7b154:      	ldr	x17, [x16, #0x270]
   7b158:      	add	x16, x16, #0x270
   7b15c:      	br	x17

000000000007b160 <pthread_mutex_lock@plt>:
   7b160:      	adrp	x16, 0x82000
   7b164:      	ldr	x17, [x16, #0x278]
   7b168:      	add	x16, x16, #0x278
   7b16c:      	br	x17

000000000007b170 <pthread_mutex_unlock@plt>:
   7b170:      	adrp	x16, 0x82000
   7b174:      	ldr	x17, [x16, #0x280]
   7b178:      	add	x16, x16, #0x280
   7b17c:      	br	x17

000000000007b180 <calloc@plt>:
   7b180:      	adrp	x16, 0x82000
   7b184:      	ldr	x17, [x16, #0x288]
   7b188:      	add	x16, x16, #0x288
   7b18c:      	br	x17

000000000007b190 <clock_gettime@plt>:
   7b190:      	adrp	x16, 0x82000
   7b194:      	ldr	x17, [x16, #0x290]
   7b198:      	add	x16, x16, #0x290
   7b19c:      	br	x17

000000000007b1a0 <gettimeofday@plt>:
   7b1a0:      	adrp	x16, 0x82000
   7b1a4:      	ldr	x17, [x16, #0x298]
   7b1a8:      	add	x16, x16, #0x298
   7b1ac:      	br	x17

000000000007b1b0 <getpid@plt>:
   7b1b0:      	adrp	x16, 0x82000
   7b1b4:      	ldr	x17, [x16, #0x2a0]
   7b1b8:      	add	x16, x16, #0x2a0
   7b1bc:      	br	x17

000000000007b1c0 <iswspace@plt>:
   7b1c0:      	adrp	x16, 0x82000
   7b1c4:      	ldr	x17, [x16, #0x2a8]
   7b1c8:      	add	x16, x16, #0x2a8
   7b1cc:      	br	x17

000000000007b1d0 <pthread_mutexattr_init@plt>:
   7b1d0:      	adrp	x16, 0x82000
   7b1d4:      	ldr	x17, [x16, #0x2b0]
   7b1d8:      	add	x16, x16, #0x2b0
   7b1dc:      	br	x17

000000000007b1e0 <pthread_mutexattr_settype@plt>:
   7b1e0:      	adrp	x16, 0x82000
   7b1e4:      	ldr	x17, [x16, #0x2b8]
   7b1e8:      	add	x16, x16, #0x2b8
   7b1ec:      	br	x17

000000000007b1f0 <pthread_mutex_init@plt>:
   7b1f0:      	adrp	x16, 0x82000
   7b1f4:      	ldr	x17, [x16, #0x2c0]
   7b1f8:      	add	x16, x16, #0x2c0
   7b1fc:      	br	x17

000000000007b200 <pthread_mutexattr_destroy@plt>:
   7b200:      	adrp	x16, 0x82000
   7b204:      	ldr	x17, [x16, #0x2c8]
   7b208:      	add	x16, x16, #0x2c8
   7b20c:      	br	x17

000000000007b210 <sched_yield@plt>:
   7b210:      	adrp	x16, 0x82000
   7b214:      	ldr	x17, [x16, #0x2d0]
   7b218:      	add	x16, x16, #0x2d0
   7b21c:      	br	x17

000000000007b220 <strerror@plt>:
   7b220:      	adrp	x16, 0x82000
   7b224:      	ldr	x17, [x16, #0x2d8]
   7b228:      	add	x16, x16, #0x2d8
   7b22c:      	br	x17

000000000007b230 <closedir@plt>:
   7b230:      	adrp	x16, 0x82000
   7b234:      	ldr	x17, [x16, #0x2e0]
   7b238:      	add	x16, x16, #0x2e0
   7b23c:      	br	x17

000000000007b240 <readdir@plt>:
   7b240:      	adrp	x16, 0x82000
   7b244:      	ldr	x17, [x16, #0x2e8]
   7b248:      	add	x16, x16, #0x2e8
   7b24c:      	br	x17

000000000007b250 <fnmatch@plt>:
   7b250:      	adrp	x16, 0x82000
   7b254:      	ldr	x17, [x16, #0x2f0]
   7b258:      	add	x16, x16, #0x2f0
   7b25c:      	br	x17

000000000007b260 <strcmp@plt>:
   7b260:      	adrp	x16, 0x82000
   7b264:      	ldr	x17, [x16, #0x2f8]
   7b268:      	add	x16, x16, #0x2f8
   7b26c:      	br	x17

000000000007b270 <tanf@plt>:
   7b270:      	adrp	x16, 0x82000
   7b274:      	ldr	x17, [x16, #0x300]
   7b278:      	add	x16, x16, #0x300
   7b27c:      	br	x17

000000000007b280 <sincosf@plt>:
   7b280:      	adrp	x16, 0x82000
   7b284:      	ldr	x17, [x16, #0x308]
   7b288:      	add	x16, x16, #0x308
   7b28c:      	br	x17

000000000007b290 <sincos@plt>:
   7b290:      	adrp	x16, 0x82000
   7b294:      	ldr	x17, [x16, #0x310]
   7b298:      	add	x16, x16, #0x310
   7b29c:      	br	x17

000000000007b2a0 <exp@plt>:
   7b2a0:      	adrp	x16, 0x82000
   7b2a4:      	ldr	x17, [x16, #0x318]
   7b2a8:      	add	x16, x16, #0x318
   7b2ac:      	br	x17

000000000007b2b0 <getauxval@plt>:
   7b2b0:      	adrp	x16, 0x82000
   7b2b4:      	ldr	x17, [x16, #0x320]
   7b2b8:      	add	x16, x16, #0x320
   7b2bc:      	br	x17

000000000007b2c0 <__system_property_get@plt>:
   7b2c0:      	adrp	x16, 0x82000
   7b2c4:      	ldr	x17, [x16, #0x328]
   7b2c8:      	add	x16, x16, #0x328
   7b2cc:      	br	x17

000000000007b2d0 <strncmp@plt>:
   7b2d0:      	adrp	x16, 0x82000
   7b2d4:      	ldr	x17, [x16, #0x330]
   7b2d8:      	add	x16, x16, #0x330
   7b2dc:      	br	x17

000000000007b2e0 <fprintf@plt>:
   7b2e0:      	adrp	x16, 0x82000
   7b2e4:      	ldr	x17, [x16, #0x338]
   7b2e8:      	add	x16, x16, #0x338
   7b2ec:      	br	x17

000000000007b2f0 <fflush@plt>:
   7b2f0:      	adrp	x16, 0x82000
   7b2f4:      	ldr	x17, [x16, #0x340]
   7b2f8:      	add	x16, x16, #0x340
   7b2fc:      	br	x17

000000000007b300 <abort@plt>:
   7b300:      	adrp	x16, 0x82000
   7b304:      	ldr	x17, [x16, #0x348]
   7b308:      	add	x16, x16, #0x348
   7b30c:      	br	x17

000000000007b310 <pthread_rwlock_wrlock@plt>:
   7b310:      	adrp	x16, 0x82000
   7b314:      	ldr	x17, [x16, #0x350]
   7b318:      	add	x16, x16, #0x350
   7b31c:      	br	x17

000000000007b320 <pthread_rwlock_unlock@plt>:
   7b320:      	adrp	x16, 0x82000
   7b324:      	ldr	x17, [x16, #0x358]
   7b328:      	add	x16, x16, #0x358
   7b32c:      	br	x17

000000000007b330 <dl_iterate_phdr@plt>:
   7b330:      	adrp	x16, 0x82000
   7b334:      	ldr	x17, [x16, #0x360]
   7b338:      	add	x16, x16, #0x360
   7b33c:      	br	x17

000000000007b340 <pthread_rwlock_rdlock@plt>:
   7b340:      	adrp	x16, 0x82000
   7b344:      	ldr	x17, [x16, #0x368]
   7b348:      	add	x16, x16, #0x368
   7b34c:      	br	x17

000000000007b350 <syscall@plt>:
   7b350:      	adrp	x16, 0x82000
   7b354:      	ldr	x17, [x16, #0x370]
   7b358:      	add	x16, x16, #0x370
   7b35c:      	br	x17

000000000007b360 <fwrite@plt>:
   7b360:      	adrp	x16, 0x82000
   7b364:      	ldr	x17, [x16, #0x378]
   7b368:      	add	x16, x16, #0x378
   7b36c:      	br	x17
