// EXPORTED & PLT DISASSEMBLY FOR libMtlabSign.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMtlabSign.so (SHA-256: 6901812E71F57BD62614000AD735CAFDF0DAC5282DBEB766B818DD1F1D333CAB)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 19, JNI Methods: 1


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMtlabSign.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000004830 <.plt>:
    4830:      	stp	x16, x30, [sp, #-0x10]!
    4834:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4838:      	ldr	x17, [x16, #0xcf0]
    483c:      	add	x16, x16, #0xcf0
    4840:      	br	x17
    4844:      	nop
    4848:      	nop
    484c:      	nop

0000000000004850 <__cxa_finalize@plt>:
    4850:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4854:      	ldr	x17, [x16, #0xcf8]
    4858:      	add	x16, x16, #0xcf8
    485c:      	br	x17

0000000000004860 <__cxa_atexit@plt>:
    4860:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4864:      	ldr	x17, [x16, #0xd00]
    4868:      	add	x16, x16, #0xd00
    486c:      	br	x17

0000000000004870 <_Z11jstring2strP7_JNIEnvP8_jstring@plt>:
    4870:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4874:      	ldr	x17, [x16, #0xd08]
    4878:      	add	x16, x16, #0xd08
    487c:      	br	x17

0000000000004880 <_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz@plt>:
    4880:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4884:      	ldr	x17, [x16, #0xd10]
    4888:      	add	x16, x16, #0xd10
    488c:      	br	x17

0000000000004890 <malloc@plt>:
    4890:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4894:      	ldr	x17, [x16, #0xd18]
    4898:      	add	x16, x16, #0xd18
    489c:      	br	x17

00000000000048a0 <memcpy@plt>:
    48a0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    48a4:      	ldr	x17, [x16, #0xd20]
    48a8:      	add	x16, x16, #0xd20
    48ac:      	br	x17

00000000000048b0 <strlen@plt>:
    48b0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    48b4:      	ldr	x17, [x16, #0xd28]
    48b8:      	add	x16, x16, #0xd28
    48bc:      	br	x17

00000000000048c0 <_Znwm@plt>:
    48c0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    48c4:      	ldr	x17, [x16, #0xd30]
    48c8:      	add	x16, x16, #0xd30
    48cc:      	br	x17

00000000000048d0 <free@plt>:
    48d0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    48d4:      	ldr	x17, [x16, #0xd38]
    48d8:      	add	x16, x16, #0xd38
    48dc:      	br	x17

00000000000048e0 <__stack_chk_fail@plt>:
    48e0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    48e4:      	ldr	x17, [x16, #0xd40]
    48e8:      	add	x16, x16, #0xd40
    48ec:      	br	x17

00000000000048f0 <_Z10getSignKeyP7_JNIEnvP8_jstringS2_S2_@plt>:
    48f0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    48f4:      	ldr	x17, [x16, #0xd48]
    48f8:      	add	x16, x16, #0xd48
    48fc:      	br	x17

0000000000004900 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
    4900:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4904:      	ldr	x17, [x16, #0xd50]
    4908:      	add	x16, x16, #0xd50
    490c:      	br	x17

0000000000004910 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
    4910:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4914:      	ldr	x17, [x16, #0xd58]
    4918:      	add	x16, x16, #0xd58
    491c:      	br	x17

0000000000004920 <_ZdlPv@plt>:
    4920:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4924:      	ldr	x17, [x16, #0xd60]
    4928:      	add	x16, x16, #0xd60
    492c:      	br	x17

0000000000004930 <_ZNSt6__ndk18ios_base4initEPv@plt>:
    4930:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4934:      	ldr	x17, [x16, #0xd68]
    4938:      	add	x16, x16, #0xd68
    493c:      	br	x17

0000000000004940 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
    4940:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4944:      	ldr	x17, [x16, #0xd70]
    4948:      	add	x16, x16, #0xd70
    494c:      	br	x17

0000000000004950 <rand@plt>:
    4950:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4954:      	ldr	x17, [x16, #0xd78]
    4958:      	add	x16, x16, #0xd78
    495c:      	br	x17

0000000000004960 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
    4960:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4964:      	ldr	x17, [x16, #0xd80]
    4968:      	add	x16, x16, #0xd80
    496c:      	br	x17

0000000000004970 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
    4970:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4974:      	ldr	x17, [x16, #0xd88]
    4978:      	add	x16, x16, #0xd88
    497c:      	br	x17

0000000000004980 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
    4980:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4984:      	ldr	x17, [x16, #0xd90]
    4988:      	add	x16, x16, #0xd90
    498c:      	br	x17

0000000000004990 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
    4990:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4994:      	ldr	x17, [x16, #0xd98]
    4998:      	add	x16, x16, #0xd98
    499c:      	br	x17

00000000000049a0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
    49a0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    49a4:      	ldr	x17, [x16, #0xda0]
    49a8:      	add	x16, x16, #0xda0
    49ac:      	br	x17

00000000000049b0 <_ZN5CSHA1C2Ev@plt>:
    49b0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    49b4:      	ldr	x17, [x16, #0xda8]
    49b8:      	add	x16, x16, #0xda8
    49bc:      	br	x17

00000000000049c0 <_Znam@plt>:
    49c0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    49c4:      	ldr	x17, [x16, #0xdb0]
    49c8:      	add	x16, x16, #0xdb0
    49cc:      	br	x17

00000000000049d0 <_ZN10CHMAC_SHA19HMAC_SHA1EPhiS0_iS0_@plt>:
    49d0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    49d4:      	ldr	x17, [x16, #0xdb8]
    49d8:      	add	x16, x16, #0xdb8
    49dc:      	br	x17

00000000000049e0 <_ZN7ZBase646EncodeEPKhi@plt>:
    49e0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    49e4:      	ldr	x17, [x16, #0xdc0]
    49e8:      	add	x16, x16, #0xdc0
    49ec:      	br	x17

00000000000049f0 <_ZdaPv@plt>:
    49f0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    49f4:      	ldr	x17, [x16, #0xdc8]
    49f8:      	add	x16, x16, #0xdc8
    49fc:      	br	x17

0000000000004a00 <_ZN5CSHA1D2Ev@plt>:
    4a00:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a04:      	ldr	x17, [x16, #0xdd0]
    4a08:      	add	x16, x16, #0xdd0
    4a0c:      	br	x17

0000000000004a10 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
    4a10:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a14:      	ldr	x17, [x16, #0xdd8]
    4a18:      	add	x16, x16, #0xdd8
    4a1c:      	br	x17

0000000000004a20 <_ZN5CSHA15ResetEv@plt>:
    4a20:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a24:      	ldr	x17, [x16, #0xde0]
    4a28:      	add	x16, x16, #0xde0
    4a2c:      	br	x17

0000000000004a30 <_ZN5CSHA19TransformEPjPh@plt>:
    4a30:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a34:      	ldr	x17, [x16, #0xde8]
    4a38:      	add	x16, x16, #0xde8
    4a3c:      	br	x17

0000000000004a40 <_ZN5CSHA16UpdateEPhj@plt>:
    4a40:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a44:      	ldr	x17, [x16, #0xdf0]
    4a48:      	add	x16, x16, #0xdf0
    4a4c:      	br	x17

0000000000004a50 <fopen@plt>:
    4a50:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a54:      	ldr	x17, [x16, #0xdf8]
    4a58:      	add	x16, x16, #0xdf8
    4a5c:      	br	x17

0000000000004a60 <fseek@plt>:
    4a60:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a64:      	ldr	x17, [x16, #0xe00]
    4a68:      	add	x16, x16, #0xe00
    4a6c:      	br	x17

0000000000004a70 <ftell@plt>:
    4a70:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a74:      	ldr	x17, [x16, #0xe08]
    4a78:      	add	x16, x16, #0xe08
    4a7c:      	br	x17

0000000000004a80 <fread@plt>:
    4a80:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a84:      	ldr	x17, [x16, #0xe10]
    4a88:      	add	x16, x16, #0xe10
    4a8c:      	br	x17

0000000000004a90 <fclose@plt>:
    4a90:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4a94:      	ldr	x17, [x16, #0xe18]
    4a98:      	add	x16, x16, #0xe18
    4a9c:      	br	x17

0000000000004aa0 <_ZN5CSHA15FinalEv@plt>:
    4aa0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4aa4:      	ldr	x17, [x16, #0xe20]
    4aa8:      	add	x16, x16, #0xe20
    4aac:      	br	x17

0000000000004ab0 <strcat@plt>:
    4ab0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4ab4:      	ldr	x17, [x16, #0xe28]
    4ab8:      	add	x16, x16, #0xe28
    4abc:      	br	x17

0000000000004ac0 <_ZN5CSHA17GetHashEPh@plt>:
    4ac0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4ac4:      	ldr	x17, [x16, #0xe30]
    4ac8:      	add	x16, x16, #0xe30
    4acc:      	br	x17

0000000000004ad0 <memmove@plt>:
    4ad0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4ad4:      	ldr	x17, [x16, #0xe38]
    4ad8:      	add	x16, x16, #0xe38
    4adc:      	br	x17

0000000000004ae0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
    4ae0:      	adrp	x16, 0x8000 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt+0x3520>
    4ae4:      	ldr	x17, [x16, #0xe40]
    4ae8:      	add	x16, x16, #0xe40
    4aec:      	br	x17
