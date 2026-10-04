// EXPORTED & PLT DISASSEMBLY FOR libc++_shared.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libc++_shared.so (SHA-256: 4397241B4BD20A8E579BFB41D21107857E12985F6A01CA0C2A5F83380D1270B4)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 2336, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libc++_shared.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000001326c0 <.plt>:
  1326c0:      	bti	c
  1326c4:      	stp	x16, x30, [sp, #-0x10]!
  1326c8:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1326cc:      	ldr	x17, [x16, #0xf88]
  1326d0:      	add	x16, x16, #0xf88
  1326d4:      	br	x17
  1326d8:      	nop
  1326dc:      	nop

00000000001326e0 <__cxa_finalize@plt>:
  1326e0:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1326e4:      	ldr	x17, [x16, #0xf90]
  1326e8:      	add	x16, x16, #0xf90
  1326ec:      	br	x17
  1326f0:      	nop
  1326f4:      	nop

00000000001326f8 <__cxa_atexit@plt>:
  1326f8:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1326fc:      	ldr	x17, [x16, #0xf98]
  132700:      	add	x16, x16, #0xf98
  132704:      	br	x17
  132708:      	nop
  13270c:      	nop

0000000000132710 <__cxa_allocate_exception@plt>:
  132710:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  132714:      	ldr	x17, [x16, #0xfa0]
  132718:      	add	x16, x16, #0xfa0
  13271c:      	br	x17
  132720:      	nop
  132724:      	nop

0000000000132728 <_ZNSt8bad_castC1Ev@plt>:
  132728:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  13272c:      	ldr	x17, [x16, #0xfa8]
  132730:      	add	x16, x16, #0xfa8
  132734:      	br	x17
  132738:      	nop
  13273c:      	nop

0000000000132740 <_ZNSt8bad_castD1Ev@plt>:
  132740:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  132744:      	ldr	x17, [x16, #0xfb0]
  132748:      	add	x16, x16, #0xfb0
  13274c:      	br	x17
  132750:      	nop
  132754:      	nop

0000000000132758 <__cxa_throw@plt>:
  132758:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  13275c:      	ldr	x17, [x16, #0xfb8]
  132760:      	add	x16, x16, #0xfb8
  132764:      	br	x17
  132768:      	nop
  13276c:      	nop

0000000000132770 <_ZNSt10bad_typeidC1Ev@plt>:
  132770:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  132774:      	ldr	x17, [x16, #0xfc0]
  132778:      	add	x16, x16, #0xfc0
  13277c:      	br	x17
  132780:      	nop
  132784:      	nop

0000000000132788 <_ZNSt10bad_typeidD1Ev@plt>:
  132788:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  13278c:      	ldr	x17, [x16, #0xfc8]
  132790:      	add	x16, x16, #0xfc8
  132794:      	br	x17
  132798:      	nop
  13279c:      	nop

00000000001327a0 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  1327a0:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1327a4:      	ldr	x17, [x16, #0xfd0]
  1327a8:      	add	x16, x16, #0xfd0
  1327ac:      	br	x17
  1327b0:      	nop
  1327b4:      	nop

00000000001327b8 <_ZNSt20bad_array_new_lengthD1Ev@plt>:
  1327b8:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1327bc:      	ldr	x17, [x16, #0xfd8]
  1327c0:      	add	x16, x16, #0xfd8
  1327c4:      	br	x17
  1327c8:      	nop
  1327cc:      	nop

00000000001327d0 <__cxa_get_globals_fast@plt>:
  1327d0:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1327d4:      	ldr	x17, [x16, #0xfe0]
  1327d8:      	add	x16, x16, #0xfe0
  1327dc:      	br	x17
  1327e0:      	nop
  1327e4:      	nop

00000000001327e8 <__cxa_demangle@plt>:
  1327e8:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  1327ec:      	ldr	x17, [x16, #0xfe8]
  1327f0:      	add	x16, x16, #0xfe8
  1327f4:      	br	x17
  1327f8:      	nop
  1327fc:      	nop

0000000000132800 <_ZSt9terminatev@plt>:
  132800:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  132804:      	ldr	x17, [x16, #0xff0]
  132808:      	add	x16, x16, #0xff0
  13280c:      	br	x17
  132810:      	nop
  132814:      	nop

0000000000132818 <__cxa_begin_catch@plt>:
  132818:      	adrp	x16, 0x141000 <_ZTVNSt6__ndk111regex_errorE+0x640>
  13281c:      	ldr	x17, [x16, #0xff8]
  132820:      	add	x16, x16, #0xff8
  132824:      	br	x17
  132828:      	nop
  13282c:      	nop

0000000000132830 <free@plt>:
  132830:      	adrp	x16, 0x142000
  132834:      	ldr	x17, [x16]
  132838:      	add	x16, x16, #0x0
  13283c:      	br	x17
  132840:      	nop
  132844:      	nop

0000000000132848 <__cxa_get_globals@plt>:
  132848:      	adrp	x16, 0x142000
  13284c:      	ldr	x17, [x16, #0x8]
  132850:      	add	x16, x16, #0x8
  132854:      	br	x17
  132858:      	nop
  13285c:      	nop

0000000000132860 <__emutls_get_address@plt>:
  132860:      	adrp	x16, 0x142000
  132864:      	ldr	x17, [x16, #0x10]
  132868:      	add	x16, x16, #0x10
  13286c:      	br	x17
  132870:      	nop
  132874:      	nop

0000000000132878 <__cxa_guard_acquire@plt>:
  132878:      	adrp	x16, 0x142000
  13287c:      	ldr	x17, [x16, #0x18]
  132880:      	add	x16, x16, #0x18
  132884:      	br	x17
  132888:      	nop
  13288c:      	nop

0000000000132890 <pthread_mutex_lock@plt>:
  132890:      	adrp	x16, 0x142000
  132894:      	ldr	x17, [x16, #0x20]
  132898:      	add	x16, x16, #0x20
  13289c:      	br	x17
  1328a0:      	nop
  1328a4:      	nop

00000000001328a8 <syscall@plt>:
  1328a8:      	adrp	x16, 0x142000
  1328ac:      	ldr	x17, [x16, #0x28]
  1328b0:      	add	x16, x16, #0x28
  1328b4:      	br	x17
  1328b8:      	nop
  1328bc:      	nop

00000000001328c0 <pthread_cond_wait@plt>:
  1328c0:      	adrp	x16, 0x142000
  1328c4:      	ldr	x17, [x16, #0x30]
  1328c8:      	add	x16, x16, #0x30
  1328cc:      	br	x17
  1328d0:      	nop
  1328d4:      	nop

00000000001328d8 <pthread_mutex_unlock@plt>:
  1328d8:      	adrp	x16, 0x142000
  1328dc:      	ldr	x17, [x16, #0x38]
  1328e0:      	add	x16, x16, #0x38
  1328e4:      	br	x17
  1328e8:      	nop
  1328ec:      	nop

00000000001328f0 <__cxa_guard_release@plt>:
  1328f0:      	adrp	x16, 0x142000
  1328f4:      	ldr	x17, [x16, #0x40]
  1328f8:      	add	x16, x16, #0x40
  1328fc:      	br	x17
  132900:      	nop
  132904:      	nop

0000000000132908 <pthread_cond_broadcast@plt>:
  132908:      	adrp	x16, 0x142000
  13290c:      	ldr	x17, [x16, #0x48]
  132910:      	add	x16, x16, #0x48
  132914:      	br	x17
  132918:      	nop
  13291c:      	nop

0000000000132920 <__cxa_guard_abort@plt>:
  132920:      	adrp	x16, 0x142000
  132924:      	ldr	x17, [x16, #0x50]
  132928:      	add	x16, x16, #0x50
  13292c:      	br	x17
  132930:      	nop
  132934:      	nop

0000000000132938 <_ZSt14get_unexpectedv@plt>:
  132938:      	adrp	x16, 0x142000
  13293c:      	ldr	x17, [x16, #0x58]
  132940:      	add	x16, x16, #0x58
  132944:      	br	x17
  132948:      	nop
  13294c:      	nop

0000000000132950 <_ZSt13get_terminatev@plt>:
  132950:      	adrp	x16, 0x142000
  132954:      	ldr	x17, [x16, #0x60]
  132958:      	add	x16, x16, #0x60
  13295c:      	br	x17
  132960:      	nop
  132964:      	nop

0000000000132968 <_ZSt15get_new_handlerv@plt>:
  132968:      	adrp	x16, 0x142000
  13296c:      	ldr	x17, [x16, #0x68]
  132970:      	add	x16, x16, #0x68
  132974:      	br	x17
  132978:      	nop
  13297c:      	nop

0000000000132980 <_Znam@plt>:
  132980:      	adrp	x16, 0x142000
  132984:      	ldr	x17, [x16, #0x70]
  132988:      	add	x16, x16, #0x70
  13298c:      	br	x17
  132990:      	nop
  132994:      	nop

0000000000132998 <_ZdaPv@plt>:
  132998:      	adrp	x16, 0x142000
  13299c:      	ldr	x17, [x16, #0x78]
  1329a0:      	add	x16, x16, #0x78
  1329a4:      	br	x17
  1329a8:      	nop
  1329ac:      	nop

00000000001329b0 <__cxa_uncaught_exception@plt>:
  1329b0:      	adrp	x16, 0x142000
  1329b4:      	ldr	x17, [x16, #0x80]
  1329b8:      	add	x16, x16, #0x80
  1329bc:      	br	x17
  1329c0:      	nop
  1329c4:      	nop

00000000001329c8 <_ZNSt9exceptionD2Ev@plt>:
  1329c8:      	adrp	x16, 0x142000
  1329cc:      	ldr	x17, [x16, #0x88]
  1329d0:      	add	x16, x16, #0x88
  1329d4:      	br	x17
  1329d8:      	nop
  1329dc:      	nop

00000000001329e0 <_ZNSt9exceptionD1Ev@plt>:
  1329e0:      	adrp	x16, 0x142000
  1329e4:      	ldr	x17, [x16, #0x90]
  1329e8:      	add	x16, x16, #0x90
  1329ec:      	br	x17
  1329f0:      	nop
  1329f4:      	nop

00000000001329f8 <_ZdlPv@plt>:
  1329f8:      	adrp	x16, 0x142000
  1329fc:      	ldr	x17, [x16, #0x98]
  132a00:      	add	x16, x16, #0x98
  132a04:      	br	x17
  132a08:      	nop
  132a0c:      	nop

0000000000132a10 <_ZNSt13bad_exceptionD1Ev@plt>:
  132a10:      	adrp	x16, 0x142000
  132a14:      	ldr	x17, [x16, #0xa0]
  132a18:      	add	x16, x16, #0xa0
  132a1c:      	br	x17
  132a20:      	nop
  132a24:      	nop

0000000000132a28 <_ZNSt9bad_allocD1Ev@plt>:
  132a28:      	adrp	x16, 0x142000
  132a2c:      	ldr	x17, [x16, #0xa8]
  132a30:      	add	x16, x16, #0xa8
  132a34:      	br	x17
  132a38:      	nop
  132a3c:      	nop

0000000000132a40 <_ZNSt9bad_allocC1Ev@plt>:
  132a40:      	adrp	x16, 0x142000
  132a44:      	ldr	x17, [x16, #0xb0]
  132a48:      	add	x16, x16, #0xb0
  132a4c:      	br	x17
  132a50:      	nop
  132a54:      	nop

0000000000132a58 <_ZNSt11logic_errorD2Ev@plt>:
  132a58:      	adrp	x16, 0x142000
  132a5c:      	ldr	x17, [x16, #0xb8]
  132a60:      	add	x16, x16, #0xb8
  132a64:      	br	x17
  132a68:      	nop
  132a6c:      	nop

0000000000132a70 <_ZNSt11logic_errorD1Ev@plt>:
  132a70:      	adrp	x16, 0x142000
  132a74:      	ldr	x17, [x16, #0xc0]
  132a78:      	add	x16, x16, #0xc0
  132a7c:      	br	x17
  132a80:      	nop
  132a84:      	nop

0000000000132a88 <_ZNSt13runtime_errorD2Ev@plt>:
  132a88:      	adrp	x16, 0x142000
  132a8c:      	ldr	x17, [x16, #0xc8]
  132a90:      	add	x16, x16, #0xc8
  132a94:      	br	x17
  132a98:      	nop
  132a9c:      	nop

0000000000132aa0 <_ZNSt13runtime_errorD1Ev@plt>:
  132aa0:      	adrp	x16, 0x142000
  132aa4:      	ldr	x17, [x16, #0xd0]
  132aa8:      	add	x16, x16, #0xd0
  132aac:      	br	x17
  132ab0:      	nop
  132ab4:      	nop

0000000000132ab8 <_ZNKSt13runtime_error4whatEv@plt>:
  132ab8:      	adrp	x16, 0x142000
  132abc:      	ldr	x17, [x16, #0xd8]
  132ac0:      	add	x16, x16, #0xd8
  132ac4:      	br	x17
  132ac8:      	nop
  132acc:      	nop

0000000000132ad0 <_ZNSt12domain_errorD1Ev@plt>:
  132ad0:      	adrp	x16, 0x142000
  132ad4:      	ldr	x17, [x16, #0xe0]
  132ad8:      	add	x16, x16, #0xe0
  132adc:      	br	x17
  132ae0:      	nop
  132ae4:      	nop

0000000000132ae8 <_ZNSt16invalid_argumentD1Ev@plt>:
  132ae8:      	adrp	x16, 0x142000
  132aec:      	ldr	x17, [x16, #0xe8]
  132af0:      	add	x16, x16, #0xe8
  132af4:      	br	x17
  132af8:      	nop
  132afc:      	nop

0000000000132b00 <_ZNSt12length_errorD1Ev@plt>:
  132b00:      	adrp	x16, 0x142000
  132b04:      	ldr	x17, [x16, #0xf0]
  132b08:      	add	x16, x16, #0xf0
  132b0c:      	br	x17
  132b10:      	nop
  132b14:      	nop

0000000000132b18 <_ZNSt12out_of_rangeD1Ev@plt>:
  132b18:      	adrp	x16, 0x142000
  132b1c:      	ldr	x17, [x16, #0xf8]
  132b20:      	add	x16, x16, #0xf8
  132b24:      	br	x17
  132b28:      	nop
  132b2c:      	nop

0000000000132b30 <_ZNSt11range_errorD1Ev@plt>:
  132b30:      	adrp	x16, 0x142000
  132b34:      	ldr	x17, [x16, #0x100]
  132b38:      	add	x16, x16, #0x100
  132b3c:      	br	x17
  132b40:      	nop
  132b44:      	nop

0000000000132b48 <_ZNSt14overflow_errorD1Ev@plt>:
  132b48:      	adrp	x16, 0x142000
  132b4c:      	ldr	x17, [x16, #0x108]
  132b50:      	add	x16, x16, #0x108
  132b54:      	br	x17
  132b58:      	nop
  132b5c:      	nop

0000000000132b60 <_ZNSt15underflow_errorD1Ev@plt>:
  132b60:      	adrp	x16, 0x142000
  132b64:      	ldr	x17, [x16, #0x110]
  132b68:      	add	x16, x16, #0x110
  132b6c:      	br	x17
  132b70:      	nop
  132b74:      	nop

0000000000132b78 <_ZNSt9type_infoD2Ev@plt>:
  132b78:      	adrp	x16, 0x142000
  132b7c:      	ldr	x17, [x16, #0x118]
  132b80:      	add	x16, x16, #0x118
  132b84:      	br	x17
  132b88:      	nop
  132b8c:      	nop

0000000000132b90 <_ZNSt9type_infoD1Ev@plt>:
  132b90:      	adrp	x16, 0x142000
  132b94:      	ldr	x17, [x16, #0x120]
  132b98:      	add	x16, x16, #0x120
  132b9c:      	br	x17
  132ba0:      	nop
  132ba4:      	nop

0000000000132ba8 <_ZNSt8bad_castD2Ev@plt>:
  132ba8:      	adrp	x16, 0x142000
  132bac:      	ldr	x17, [x16, #0x128]
  132bb0:      	add	x16, x16, #0x128
  132bb4:      	br	x17
  132bb8:      	nop
  132bbc:      	nop

0000000000132bc0 <fwrite@plt>:
  132bc0:      	adrp	x16, 0x142000
  132bc4:      	ldr	x17, [x16, #0x130]
  132bc8:      	add	x16, x16, #0x130
  132bcc:      	br	x17
  132bd0:      	nop
  132bd4:      	nop

0000000000132bd8 <vfprintf@plt>:
  132bd8:      	adrp	x16, 0x142000
  132bdc:      	ldr	x17, [x16, #0x138]
  132be0:      	add	x16, x16, #0x138
  132be4:      	br	x17
  132be8:      	nop
  132bec:      	nop

0000000000132bf0 <fputc@plt>:
  132bf0:      	adrp	x16, 0x142000
  132bf4:      	ldr	x17, [x16, #0x140]
  132bf8:      	add	x16, x16, #0x140
  132bfc:      	br	x17
  132c00:      	nop
  132c04:      	nop

0000000000132c08 <vasprintf@plt>:
  132c08:      	adrp	x16, 0x142000
  132c0c:      	ldr	x17, [x16, #0x148]
  132c10:      	add	x16, x16, #0x148
  132c14:      	br	x17
  132c18:      	nop
  132c1c:      	nop

0000000000132c20 <android_set_abort_message@plt>:
  132c20:      	adrp	x16, 0x142000
  132c24:      	ldr	x17, [x16, #0x150]
  132c28:      	add	x16, x16, #0x150
  132c2c:      	br	x17
  132c30:      	nop
  132c34:      	nop

0000000000132c38 <openlog@plt>:
  132c38:      	adrp	x16, 0x142000
  132c3c:      	ldr	x17, [x16, #0x158]
  132c40:      	add	x16, x16, #0x158
  132c44:      	br	x17
  132c48:      	nop
  132c4c:      	nop

0000000000132c50 <syslog@plt>:
  132c50:      	adrp	x16, 0x142000
  132c54:      	ldr	x17, [x16, #0x160]
  132c58:      	add	x16, x16, #0x160
  132c5c:      	br	x17
  132c60:      	nop
  132c64:      	nop

0000000000132c68 <closelog@plt>:
  132c68:      	adrp	x16, 0x142000
  132c6c:      	ldr	x17, [x16, #0x168]
  132c70:      	add	x16, x16, #0x168
  132c74:      	br	x17
  132c78:      	nop
  132c7c:      	nop

0000000000132c80 <abort@plt>:
  132c80:      	adrp	x16, 0x142000
  132c84:      	ldr	x17, [x16, #0x170]
  132c88:      	add	x16, x16, #0x170
  132c8c:      	br	x17
  132c90:      	nop
  132c94:      	nop

0000000000132c98 <posix_memalign@plt>:
  132c98:      	adrp	x16, 0x142000
  132c9c:      	ldr	x17, [x16, #0x178]
  132ca0:      	add	x16, x16, #0x178
  132ca4:      	br	x17
  132ca8:      	nop
  132cac:      	nop

0000000000132cb0 <memset@plt>:
  132cb0:      	adrp	x16, 0x142000
  132cb4:      	ldr	x17, [x16, #0x180]
  132cb8:      	add	x16, x16, #0x180
  132cbc:      	br	x17
  132cc0:      	nop
  132cc4:      	nop

0000000000132cc8 <__dynamic_cast@plt>:
  132cc8:      	adrp	x16, 0x142000
  132ccc:      	ldr	x17, [x16, #0x188]
  132cd0:      	add	x16, x16, #0x188
  132cd4:      	br	x17
  132cd8:      	nop
  132cdc:      	nop

0000000000132ce0 <strcmp@plt>:
  132ce0:      	adrp	x16, 0x142000
  132ce4:      	ldr	x17, [x16, #0x190]
  132ce8:      	add	x16, x16, #0x190
  132cec:      	br	x17
  132cf0:      	nop
  132cf4:      	nop

0000000000132cf8 <strlen@plt>:
  132cf8:      	adrp	x16, 0x142000
  132cfc:      	ldr	x17, [x16, #0x198]
  132d00:      	add	x16, x16, #0x198
  132d04:      	br	x17
  132d08:      	nop
  132d0c:      	nop

0000000000132d10 <malloc@plt>:
  132d10:      	adrp	x16, 0x142000
  132d14:      	ldr	x17, [x16, #0x1a0]
  132d18:      	add	x16, x16, #0x1a0
  132d1c:      	br	x17
  132d20:      	nop
  132d24:      	nop

0000000000132d28 <realloc@plt>:
  132d28:      	adrp	x16, 0x142000
  132d2c:      	ldr	x17, [x16, #0x1a8]
  132d30:      	add	x16, x16, #0x1a8
  132d34:      	br	x17
  132d38:      	nop
  132d3c:      	nop

0000000000132d40 <fprintf@plt>:
  132d40:      	adrp	x16, 0x142000
  132d44:      	ldr	x17, [x16, #0x1b0]
  132d48:      	add	x16, x16, #0x1b0
  132d4c:      	br	x17
  132d50:      	nop
  132d54:      	nop

0000000000132d58 <memcmp@plt>:
  132d58:      	adrp	x16, 0x142000
  132d5c:      	ldr	x17, [x16, #0x1b8]
  132d60:      	add	x16, x16, #0x1b8
  132d64:      	br	x17
  132d68:      	nop
  132d6c:      	nop

0000000000132d70 <memcpy@plt>:
  132d70:      	adrp	x16, 0x142000
  132d74:      	ldr	x17, [x16, #0x1c0]
  132d78:      	add	x16, x16, #0x1c0
  132d7c:      	br	x17
  132d80:      	nop
  132d84:      	nop

0000000000132d88 <memmove@plt>:
  132d88:      	adrp	x16, 0x142000
  132d8c:      	ldr	x17, [x16, #0x1c8]
  132d90:      	add	x16, x16, #0x1c8
  132d94:      	br	x17
  132d98:      	nop
  132d9c:      	nop

0000000000132da0 <memchr@plt>:
  132da0:      	adrp	x16, 0x142000
  132da4:      	ldr	x17, [x16, #0x1d0]
  132da8:      	add	x16, x16, #0x1d0
  132dac:      	br	x17
  132db0:      	nop
  132db4:      	nop

0000000000132db8 <snprintf@plt>:
  132db8:      	adrp	x16, 0x142000
  132dbc:      	ldr	x17, [x16, #0x1d8]
  132dc0:      	add	x16, x16, #0x1d8
  132dc4:      	br	x17
  132dc8:      	nop
  132dcc:      	nop

0000000000132dd0 <_Znwm@plt>:
  132dd0:      	adrp	x16, 0x142000
  132dd4:      	ldr	x17, [x16, #0x1e0]
  132dd8:      	add	x16, x16, #0x1e0
  132ddc:      	br	x17
  132de0:      	nop
  132de4:      	nop

0000000000132de8 <__cxa_end_catch@plt>:
  132de8:      	adrp	x16, 0x142000
  132dec:      	ldr	x17, [x16, #0x1e8]
  132df0:      	add	x16, x16, #0x1e8
  132df4:      	br	x17
  132df8:      	nop
  132dfc:      	nop

0000000000132e00 <_ZnwmSt11align_val_t@plt>:
  132e00:      	adrp	x16, 0x142000
  132e04:      	ldr	x17, [x16, #0x1f0]
  132e08:      	add	x16, x16, #0x1f0
  132e0c:      	br	x17
  132e10:      	nop
  132e14:      	nop

0000000000132e18 <_ZnamSt11align_val_t@plt>:
  132e18:      	adrp	x16, 0x142000
  132e1c:      	ldr	x17, [x16, #0x1f8]
  132e20:      	add	x16, x16, #0x1f8
  132e24:      	br	x17
  132e28:      	nop
  132e2c:      	nop

0000000000132e30 <_ZdlPvSt11align_val_t@plt>:
  132e30:      	adrp	x16, 0x142000
  132e34:      	ldr	x17, [x16, #0x200]
  132e38:      	add	x16, x16, #0x200
  132e3c:      	br	x17
  132e40:      	nop
  132e44:      	nop

0000000000132e48 <_ZdaPvSt11align_val_t@plt>:
  132e48:      	adrp	x16, 0x142000
  132e4c:      	ldr	x17, [x16, #0x208]
  132e50:      	add	x16, x16, #0x208
  132e54:      	br	x17
  132e58:      	nop
  132e5c:      	nop

0000000000132e60 <__cxa_free_exception@plt>:
  132e60:      	adrp	x16, 0x142000
  132e64:      	ldr	x17, [x16, #0x210]
  132e68:      	add	x16, x16, #0x210
  132e6c:      	br	x17
  132e70:      	nop
  132e74:      	nop

0000000000132e78 <__cxa_decrement_exception_refcount@plt>:
  132e78:      	adrp	x16, 0x142000
  132e7c:      	ldr	x17, [x16, #0x218]
  132e80:      	add	x16, x16, #0x218
  132e84:      	br	x17
  132e88:      	nop
  132e8c:      	nop

0000000000132e90 <__cxa_rethrow@plt>:
  132e90:      	adrp	x16, 0x142000
  132e94:      	ldr	x17, [x16, #0x220]
  132e98:      	add	x16, x16, #0x220
  132e9c:      	br	x17
  132ea0:      	nop
  132ea4:      	nop

0000000000132ea8 <__cxa_increment_exception_refcount@plt>:
  132ea8:      	adrp	x16, 0x142000
  132eac:      	ldr	x17, [x16, #0x228]
  132eb0:      	add	x16, x16, #0x228
  132eb4:      	br	x17
  132eb8:      	nop
  132ebc:      	nop

0000000000132ec0 <__cxa_current_primary_exception@plt>:
  132ec0:      	adrp	x16, 0x142000
  132ec4:      	ldr	x17, [x16, #0x230]
  132ec8:      	add	x16, x16, #0x230
  132ecc:      	br	x17
  132ed0:      	nop
  132ed4:      	nop

0000000000132ed8 <__cxa_rethrow_primary_exception@plt>:
  132ed8:      	adrp	x16, 0x142000
  132edc:      	ldr	x17, [x16, #0x238]
  132ee0:      	add	x16, x16, #0x238
  132ee4:      	br	x17
  132ee8:      	nop
  132eec:      	nop

0000000000132ef0 <__cxa_uncaught_exceptions@plt>:
  132ef0:      	adrp	x16, 0x142000
  132ef4:      	ldr	x17, [x16, #0x240]
  132ef8:      	add	x16, x16, #0x240
  132efc:      	br	x17
  132f00:      	nop
  132f04:      	nop

0000000000132f08 <__assert2@plt>:
  132f08:      	adrp	x16, 0x142000
  132f0c:      	ldr	x17, [x16, #0x248]
  132f10:      	add	x16, x16, #0x248
  132f14:      	br	x17
  132f18:      	nop
  132f1c:      	nop

0000000000132f20 <__cxa_thread_atexit_impl@plt>:
  132f20:      	adrp	x16, 0x142000
  132f24:      	ldr	x17, [x16, #0x250]
  132f28:      	add	x16, x16, #0x250
  132f2c:      	br	x17
  132f30:      	nop
  132f34:      	nop

0000000000132f38 <pthread_setspecific@plt>:
  132f38:      	adrp	x16, 0x142000
  132f3c:      	ldr	x17, [x16, #0x258]
  132f40:      	add	x16, x16, #0x258
  132f44:      	br	x17
  132f48:      	nop
  132f4c:      	nop

0000000000132f50 <pthread_key_create@plt>:
  132f50:      	adrp	x16, 0x142000
  132f54:      	ldr	x17, [x16, #0x260]
  132f58:      	add	x16, x16, #0x260
  132f5c:      	br	x17
  132f60:      	nop
  132f64:      	nop

0000000000132f68 <_ZNSt6__ndk111__call_onceERVmPvPFvS2_E@plt>:
  132f68:      	adrp	x16, 0x142000
  132f6c:      	ldr	x17, [x16, #0x268]
  132f70:      	add	x16, x16, #0x268
  132f74:      	br	x17
  132f78:      	nop
  132f7c:      	nop

0000000000132f80 <clock_gettime@plt>:
  132f80:      	adrp	x16, 0x142000
  132f84:      	ldr	x17, [x16, #0x270]
  132f88:      	add	x16, x16, #0x270
  132f8c:      	br	x17
  132f90:      	nop
  132f94:      	nop

0000000000132f98 <__errno@plt>:
  132f98:      	adrp	x16, 0x142000
  132f9c:      	ldr	x17, [x16, #0x278]
  132fa0:      	add	x16, x16, #0x278
  132fa4:      	br	x17
  132fa8:      	nop
  132fac:      	nop

0000000000132fb0 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
  132fb0:      	adrp	x16, 0x142000
  132fb4:      	ldr	x17, [x16, #0x280]
  132fb8:      	add	x16, x16, #0x280
  132fbc:      	br	x17
  132fc0:      	nop
  132fc4:      	nop

0000000000132fc8 <_ZNSt6__ndk114error_categoryD2Ev@plt>:
  132fc8:      	adrp	x16, 0x142000
  132fcc:      	ldr	x17, [x16, #0x288]
  132fd0:      	add	x16, x16, #0x288
  132fd4:      	br	x17
  132fd8:      	nop
  132fdc:      	nop

0000000000132fe0 <_ZSt18uncaught_exceptionv@plt>:
  132fe0:      	adrp	x16, 0x142000
  132fe4:      	ldr	x17, [x16, #0x290]
  132fe8:      	add	x16, x16, #0x290
  132fec:      	br	x17
  132ff0:      	nop
  132ff4:      	nop

0000000000132ff8 <_ZNSt13exception_ptraSERKS_@plt>:
  132ff8:      	adrp	x16, 0x142000
  132ffc:      	ldr	x17, [x16, #0x298]
  133000:      	add	x16, x16, #0x298
  133004:      	br	x17
  133008:      	nop
  13300c:      	nop

0000000000133010 <_ZSt17current_exceptionv@plt>:
  133010:      	adrp	x16, 0x142000
  133014:      	ldr	x17, [x16, #0x2a0]
  133018:      	add	x16, x16, #0x2a0
  13301c:      	br	x17
  133020:      	nop
  133024:      	nop

0000000000133028 <_ZNSt13exception_ptrD1Ev@plt>:
  133028:      	adrp	x16, 0x142000
  13302c:      	ldr	x17, [x16, #0x2a8]
  133030:      	add	x16, x16, #0x2a8
  133034:      	br	x17
  133038:      	nop
  13303c:      	nop

0000000000133040 <_ZNSt16nested_exceptionD1Ev@plt>:
  133040:      	adrp	x16, 0x142000
  133044:      	ldr	x17, [x16, #0x2b0]
  133048:      	add	x16, x16, #0x2b0
  13304c:      	br	x17
  133050:      	nop
  133054:      	nop

0000000000133058 <_ZNSt13exception_ptrC1ERKS_@plt>:
  133058:      	adrp	x16, 0x142000
  13305c:      	ldr	x17, [x16, #0x2b8]
  133060:      	add	x16, x16, #0x2b8
  133064:      	br	x17
  133068:      	nop
  13306c:      	nop

0000000000133070 <_ZSt17rethrow_exceptionSt13exception_ptr@plt>:
  133070:      	adrp	x16, 0x142000
  133074:      	ldr	x17, [x16, #0x2c0]
  133078:      	add	x16, x16, #0x2c0
  13307c:      	br	x17
  133080:      	nop
  133084:      	nop

0000000000133088 <_ZNSt6__ndk112system_errorD2Ev@plt>:
  133088:      	adrp	x16, 0x142000
  13308c:      	ldr	x17, [x16, #0x2c8]
  133090:      	add	x16, x16, #0x2c8
  133094:      	br	x17
  133098:      	nop
  13309c:      	nop

00000000001330a0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  1330a0:      	adrp	x16, 0x142000
  1330a4:      	ldr	x17, [x16, #0x2d0]
  1330a8:      	add	x16, x16, #0x2d0
  1330ac:      	br	x17
  1330b0:      	nop
  1330b4:      	nop

00000000001330b8 <_ZNSt6__ndk14__fs10filesystem16filesystem_errorD1Ev@plt>:
  1330b8:      	adrp	x16, 0x142000
  1330bc:      	ldr	x17, [x16, #0x2d8]
  1330c0:      	add	x16, x16, #0x2d8
  1330c4:      	br	x17
  1330c8:      	nop
  1330cc:      	nop

00000000001330d0 <_ZNSt6__ndk14__fs10filesystem16filesystem_error13__create_whatEi@plt>:
  1330d0:      	adrp	x16, 0x142000
  1330d4:      	ldr	x17, [x16, #0x2e0]
  1330d8:      	add	x16, x16, #0x2e0
  1330dc:      	br	x17
  1330e0:      	nop
  1330e4:      	nop

00000000001330e8 <vsnprintf@plt>:
  1330e8:      	adrp	x16, 0x142000
  1330ec:      	ldr	x17, [x16, #0x2e8]
  1330f0:      	add	x16, x16, #0x2e8
  1330f4:      	br	x17
  1330f8:      	nop
  1330fc:      	nop

0000000000133100 <_ZNSt11logic_errorC2EPKc@plt>:
  133100:      	adrp	x16, 0x142000
  133104:      	ldr	x17, [x16, #0x2f0]
  133108:      	add	x16, x16, #0x2f0
  13310c:      	br	x17
  133110:      	nop
  133114:      	nop

0000000000133118 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  133118:      	adrp	x16, 0x142000
  13311c:      	ldr	x17, [x16, #0x2f8]
  133120:      	add	x16, x16, #0x2f8
  133124:      	br	x17
  133128:      	nop
  13312c:      	nop

0000000000133130 <_ZNKSt6__ndk14__fs10filesystem4path10__filenameEv@plt>:
  133130:      	adrp	x16, 0x142000
  133134:      	ldr	x17, [x16, #0x300]
  133138:      	add	x16, x16, #0x300
  13313c:      	br	x17
  133140:      	nop
  133144:      	nop

0000000000133148 <_ZNKSt6__ndk14__fs10filesystem4path16__root_directoryEv@plt>:
  133148:      	adrp	x16, 0x142000
  13314c:      	ldr	x17, [x16, #0x308]
  133150:      	add	x16, x16, #0x308
  133154:      	br	x17
  133158:      	nop
  13315c:      	nop

0000000000133160 <_ZNKSt6__ndk14__fs10filesystem4path13__parent_pathEv@plt>:
  133160:      	adrp	x16, 0x142000
  133164:      	ldr	x17, [x16, #0x310]
  133168:      	add	x16, x16, #0x310
  13316c:      	br	x17
  133170:      	nop
  133174:      	nop

0000000000133178 <_ZNKSt6__ndk14__fs10filesystem4path16lexically_normalEv@plt>:
  133178:      	adrp	x16, 0x142000
  13317c:      	ldr	x17, [x16, #0x318]
  133180:      	add	x16, x16, #0x318
  133184:      	br	x17
  133188:      	nop
  13318c:      	nop

0000000000133190 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm@plt>:
  133190:      	adrp	x16, 0x142000
  133194:      	ldr	x17, [x16, #0x320]
  133198:      	add	x16, x16, #0x320
  13319c:      	br	x17
  1331a0:      	nop
  1331a4:      	nop

00000000001331a8 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  1331a8:      	adrp	x16, 0x142000
  1331ac:      	ldr	x17, [x16, #0x328]
  1331b0:      	add	x16, x16, #0x328
  1331b4:      	br	x17
  1331b8:      	nop
  1331bc:      	nop

00000000001331c0 <_ZNKSt6__ndk14__fs10filesystem4path9__compareENS_17basic_string_viewIcNS_11char_traitsIcEEEE@plt>:
  1331c0:      	adrp	x16, 0x142000
  1331c4:      	ldr	x17, [x16, #0x330]
  1331c8:      	add	x16, x16, #0x330
  1331cc:      	br	x17
  1331d0:      	nop
  1331d4:      	nop

00000000001331d8 <_ZNSt6__ndk117bad_function_callD1Ev@plt>:
  1331d8:      	adrp	x16, 0x142000
  1331dc:      	ldr	x17, [x16, #0x338]
  1331e0:      	add	x16, x16, #0x338
  1331e4:      	br	x17
  1331e8:      	nop
  1331ec:      	nop

00000000001331f0 <_ZNSt13runtime_errorC2EPKc@plt>:
  1331f0:      	adrp	x16, 0x142000
  1331f4:      	ldr	x17, [x16, #0x340]
  1331f8:      	add	x16, x16, #0x340
  1331fc:      	br	x17
  133200:      	nop
  133204:      	nop

0000000000133208 <_ZNSt6__ndk112bad_weak_ptrD1Ev@plt>:
  133208:      	adrp	x16, 0x142000
  13320c:      	ldr	x17, [x16, #0x348]
  133210:      	add	x16, x16, #0x348
  133214:      	br	x17
  133218:      	nop
  13321c:      	nop

0000000000133220 <_ZNSt6__ndk114__shared_countD2Ev@plt>:
  133220:      	adrp	x16, 0x142000
  133224:      	ldr	x17, [x16, #0x350]
  133228:      	add	x16, x16, #0x350
  13322c:      	br	x17
  133230:      	nop
  133234:      	nop

0000000000133238 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  133238:      	adrp	x16, 0x142000
  13323c:      	ldr	x17, [x16, #0x358]
  133240:      	add	x16, x16, #0x358
  133244:      	br	x17
  133248:      	nop
  13324c:      	nop

0000000000133250 <_ZNSt6__ndk13pmr28unsynchronized_pool_resource7releaseEv@plt>:
  133250:      	adrp	x16, 0x142000
  133254:      	ldr	x17, [x16, #0x360]
  133258:      	add	x16, x16, #0x360
  13325c:      	br	x17
  133260:      	nop
  133264:      	nop

0000000000133268 <_ZNSt6__ndk15mutexD1Ev@plt>:
  133268:      	adrp	x16, 0x142000
  13326c:      	ldr	x17, [x16, #0x368]
  133270:      	add	x16, x16, #0x368
  133274:      	br	x17
  133278:      	nop
  13327c:      	nop

0000000000133280 <_ZNSt6__ndk15mutex4lockEv@plt>:
  133280:      	adrp	x16, 0x142000
  133284:      	ldr	x17, [x16, #0x370]
  133288:      	add	x16, x16, #0x370
  13328c:      	br	x17
  133290:      	nop
  133294:      	nop

0000000000133298 <_ZNSt6__ndk15mutex6unlockEv@plt>:
  133298:      	adrp	x16, 0x142000
  13329c:      	ldr	x17, [x16, #0x378]
  1332a0:      	add	x16, x16, #0x378
  1332a4:      	br	x17
  1332a8:      	nop
  1332ac:      	nop

00000000001332b0 <_ZSt17__throw_bad_allocv@plt>:
  1332b0:      	adrp	x16, 0x142000
  1332b4:      	ldr	x17, [x16, #0x380]
  1332b8:      	add	x16, x16, #0x380
  1332bc:      	br	x17
  1332c0:      	nop
  1332c4:      	nop

00000000001332c8 <_ZNSt19bad_optional_accessD1Ev@plt>:
  1332c8:      	adrp	x16, 0x142000
  1332cc:      	ldr	x17, [x16, #0x388]
  1332d0:      	add	x16, x16, #0x388
  1332d4:      	br	x17
  1332d8:      	nop
  1332dc:      	nop

00000000001332e0 <_ZNSt12experimental19bad_optional_accessD1Ev@plt>:
  1332e0:      	adrp	x16, 0x142000
  1332e4:      	ldr	x17, [x16, #0x390]
  1332e8:      	add	x16, x16, #0x390
  1332ec:      	br	x17
  1332f0:      	nop
  1332f4:      	nop

00000000001332f8 <_ZNSt6__ndk112__rs_defaultC1Ev@plt>:
  1332f8:      	adrp	x16, 0x142000
  1332fc:      	ldr	x17, [x16, #0x398]
  133300:      	add	x16, x16, #0x398
  133304:      	br	x17
  133308:      	nop
  13330c:      	nop

0000000000133310 <_ZNSt11logic_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
  133310:      	adrp	x16, 0x142000
  133314:      	ldr	x17, [x16, #0x3a0]
  133318:      	add	x16, x16, #0x3a0
  13331c:      	br	x17
  133320:      	nop
  133324:      	nop

0000000000133328 <_ZNSt11logic_errorC2ERKS_@plt>:
  133328:      	adrp	x16, 0x142000
  13332c:      	ldr	x17, [x16, #0x3a8]
  133330:      	add	x16, x16, #0x3a8
  133334:      	br	x17
  133338:      	nop
  13333c:      	nop

0000000000133340 <_ZNSt13runtime_errorC2ERKNSt6__ndk112basic_stringIcNS0_11char_traitsIcEENS0_9allocatorIcEEEE@plt>:
  133340:      	adrp	x16, 0x142000
  133344:      	ldr	x17, [x16, #0x3b0]
  133348:      	add	x16, x16, #0x3b0
  13334c:      	br	x17
  133350:      	nop
  133354:      	nop

0000000000133358 <_ZNSt6__ndk121__throw_runtime_errorEPKc@plt>:
  133358:      	adrp	x16, 0x142000
  13335c:      	ldr	x17, [x16, #0x3b8]
  133360:      	add	x16, x16, #0x3b8
  133364:      	br	x17
  133368:      	nop
  13336c:      	nop

0000000000133370 <_ZNSt13runtime_errorC1EPKc@plt>:
  133370:      	adrp	x16, 0x142000
  133374:      	ldr	x17, [x16, #0x3c0]
  133378:      	add	x16, x16, #0x3c0
  13337c:      	br	x17
  133380:      	nop
  133384:      	nop

0000000000133388 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
  133388:      	adrp	x16, 0x142000
  13338c:      	ldr	x17, [x16, #0x3c8]
  133390:      	add	x16, x16, #0x3c8
  133394:      	br	x17
  133398:      	nop
  13339c:      	nop

00000000001333a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmmc@plt>:
  1333a0:      	adrp	x16, 0x142000
  1333a4:      	ldr	x17, [x16, #0x3d0]
  1333a8:      	add	x16, x16, #0x3d0
  1333ac:      	br	x17
  1333b0:      	nop
  1333b4:      	nop

00000000001333b8 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
  1333b8:      	adrp	x16, 0x142000
  1333bc:      	ldr	x17, [x16, #0x3d8]
  1333c0:      	add	x16, x16, #0x3d8
  1333c4:      	br	x17
  1333c8:      	nop
  1333cc:      	nop

00000000001333d0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc@plt>:
  1333d0:      	adrp	x16, 0x142000
  1333d4:      	ldr	x17, [x16, #0x3e0]
  1333d8:      	add	x16, x16, #0x3e0
  1333dc:      	br	x17
  1333e0:      	nop
  1333e4:      	nop

00000000001333e8 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmPKwm@plt>:
  1333e8:      	adrp	x16, 0x142000
  1333ec:      	ldr	x17, [x16, #0x3e8]
  1333f0:      	add	x16, x16, #0x3e8
  1333f4:      	br	x17
  1333f8:      	nop
  1333fc:      	nop

0000000000133400 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE21__grow_by_and_replaceEmmmmmmPKw@plt>:
  133400:      	adrp	x16, 0x142000
  133404:      	ldr	x17, [x16, #0x3f0]
  133408:      	add	x16, x16, #0x3f0
  13340c:      	br	x17
  133410:      	nop
  133414:      	nop

0000000000133418 <wcslen@plt>:
  133418:      	adrp	x16, 0x142000
  13341c:      	ldr	x17, [x16, #0x3f8]
  133420:      	add	x16, x16, #0x3f8
  133424:      	br	x17
  133428:      	nop
  13342c:      	nop

0000000000133430 <wmemchr@plt>:
  133430:      	adrp	x16, 0x142000
  133434:      	ldr	x17, [x16, #0x400]
  133438:      	add	x16, x16, #0x400
  13343c:      	br	x17
  133440:      	nop
  133444:      	nop

0000000000133448 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmmw@plt>:
  133448:      	adrp	x16, 0x142000
  13344c:      	ldr	x17, [x16, #0x408]
  133450:      	add	x16, x16, #0x408
  133454:      	br	x17
  133458:      	nop
  13345c:      	nop

0000000000133460 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmPKwm@plt>:
  133460:      	adrp	x16, 0x142000
  133464:      	ldr	x17, [x16, #0x410]
  133468:      	add	x16, x16, #0x410
  13346c:      	br	x17
  133470:      	nop
  133474:      	nop

0000000000133478 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE9push_backEw@plt>:
  133478:      	adrp	x16, 0x142000
  13347c:      	ldr	x17, [x16, #0x418]
  133480:      	add	x16, x16, #0x418
  133484:      	br	x17
  133488:      	nop
  13348c:      	nop

0000000000133490 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEmw@plt>:
  133490:      	adrp	x16, 0x142000
  133494:      	ldr	x17, [x16, #0x420]
  133498:      	add	x16, x16, #0x420
  13349c:      	br	x17
  1334a0:      	nop
  1334a4:      	nop

00000000001334a8 <wmemcmp@plt>:
  1334a8:      	adrp	x16, 0x142000
  1334ac:      	ldr	x17, [x16, #0x428]
  1334b0:      	add	x16, x16, #0x428
  1334b4:      	br	x17
  1334b8:      	nop
  1334bc:      	nop

00000000001334c0 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
  1334c0:      	adrp	x16, 0x142000
  1334c4:      	ldr	x17, [x16, #0x430]
  1334c8:      	add	x16, x16, #0x430
  1334cc:      	br	x17
  1334d0:      	nop
  1334d4:      	nop

00000000001334d8 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
  1334d8:      	adrp	x16, 0x142000
  1334dc:      	ldr	x17, [x16, #0x438]
  1334e0:      	add	x16, x16, #0x438
  1334e4:      	br	x17
  1334e8:      	nop
  1334ec:      	nop

00000000001334f0 <strtoul@plt>:
  1334f0:      	adrp	x16, 0x142000
  1334f4:      	ldr	x17, [x16, #0x440]
  1334f8:      	add	x16, x16, #0x440
  1334fc:      	br	x17
  133500:      	nop
  133504:      	nop

0000000000133508 <strtoll@plt>:
  133508:      	adrp	x16, 0x142000
  13350c:      	ldr	x17, [x16, #0x448]
  133510:      	add	x16, x16, #0x448
  133514:      	br	x17
  133518:      	nop
  13351c:      	nop

0000000000133520 <strtoull@plt>:
  133520:      	adrp	x16, 0x142000
  133524:      	ldr	x17, [x16, #0x450]
  133528:      	add	x16, x16, #0x450
  13352c:      	br	x17
  133530:      	nop
  133534:      	nop

0000000000133538 <strtof@plt>:
  133538:      	adrp	x16, 0x142000
  13353c:      	ldr	x17, [x16, #0x458]
  133540:      	add	x16, x16, #0x458
  133544:      	br	x17
  133548:      	nop
  13354c:      	nop

0000000000133550 <strtod@plt>:
  133550:      	adrp	x16, 0x142000
  133554:      	ldr	x17, [x16, #0x460]
  133558:      	add	x16, x16, #0x460
  13355c:      	br	x17
  133560:      	nop
  133564:      	nop

0000000000133568 <strtold@plt>:
  133568:      	adrp	x16, 0x142000
  13356c:      	ldr	x17, [x16, #0x468]
  133570:      	add	x16, x16, #0x468
  133574:      	br	x17
  133578:      	nop
  13357c:      	nop

0000000000133580 <wcstoul@plt>:
  133580:      	adrp	x16, 0x142000
  133584:      	ldr	x17, [x16, #0x470]
  133588:      	add	x16, x16, #0x470
  13358c:      	br	x17
  133590:      	nop
  133594:      	nop

0000000000133598 <wcstoll@plt>:
  133598:      	adrp	x16, 0x142000
  13359c:      	ldr	x17, [x16, #0x478]
  1335a0:      	add	x16, x16, #0x478
  1335a4:      	br	x17
  1335a8:      	nop
  1335ac:      	nop

00000000001335b0 <wcstoull@plt>:
  1335b0:      	adrp	x16, 0x142000
  1335b4:      	ldr	x17, [x16, #0x480]
  1335b8:      	add	x16, x16, #0x480
  1335bc:      	br	x17
  1335c0:      	nop
  1335c4:      	nop

00000000001335c8 <wcstof@plt>:
  1335c8:      	adrp	x16, 0x142000
  1335cc:      	ldr	x17, [x16, #0x488]
  1335d0:      	add	x16, x16, #0x488
  1335d4:      	br	x17
  1335d8:      	nop
  1335dc:      	nop

00000000001335e0 <wcstod@plt>:
  1335e0:      	adrp	x16, 0x142000
  1335e4:      	ldr	x17, [x16, #0x490]
  1335e8:      	add	x16, x16, #0x490
  1335ec:      	br	x17
  1335f0:      	nop
  1335f4:      	nop

00000000001335f8 <wcstold@plt>:
  1335f8:      	adrp	x16, 0x142000
  1335fc:      	ldr	x17, [x16, #0x498]
  133600:      	add	x16, x16, #0x498
  133604:      	br	x17
  133608:      	nop
  13360c:      	nop

0000000000133610 <swprintf@plt>:
  133610:      	adrp	x16, 0x142000
  133614:      	ldr	x17, [x16, #0x4a0]
  133618:      	add	x16, x16, #0x4a0
  13361c:      	br	x17
  133620:      	nop
  133624:      	nop

0000000000133628 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEED1Ev@plt>:
  133628:      	adrp	x16, 0x142000
  13362c:      	ldr	x17, [x16, #0x4a8]
  133630:      	add	x16, x16, #0x4a8
  133634:      	br	x17
  133638:      	nop
  13363c:      	nop

0000000000133640 <strtol@plt>:
  133640:      	adrp	x16, 0x142000
  133644:      	ldr	x17, [x16, #0x4b0]
  133648:      	add	x16, x16, #0x4b0
  13364c:      	br	x17
  133650:      	nop
  133654:      	nop

0000000000133658 <wcstol@plt>:
  133658:      	adrp	x16, 0x142000
  13365c:      	ldr	x17, [x16, #0x4b8]
  133660:      	add	x16, x16, #0x4b8
  133664:      	br	x17
  133668:      	nop
  13366c:      	nop

0000000000133670 <strerror_r@plt>:
  133670:      	adrp	x16, 0x142000
  133674:      	ldr	x17, [x16, #0x4c0]
  133678:      	add	x16, x16, #0x4c0
  13367c:      	br	x17
  133680:      	nop
  133684:      	nop

0000000000133688 <_ZNSt6__ndk116generic_categoryEv@plt>:
  133688:      	adrp	x16, 0x142000
  13368c:      	ldr	x17, [x16, #0x4c8]
  133690:      	add	x16, x16, #0x4c8
  133694:      	br	x17
  133698:      	nop
  13369c:      	nop

00000000001336a0 <_ZNSt6__ndk115system_categoryEv@plt>:
  1336a0:      	adrp	x16, 0x142000
  1336a4:      	ldr	x17, [x16, #0x4d0]
  1336a8:      	add	x16, x16, #0x4d0
  1336ac:      	br	x17
  1336b0:      	nop
  1336b4:      	nop

00000000001336b8 <_ZNKSt6__ndk110error_code7messageEv@plt>:
  1336b8:      	adrp	x16, 0x142000
  1336bc:      	ldr	x17, [x16, #0x4d8]
  1336c0:      	add	x16, x16, #0x4d8
  1336c4:      	br	x17
  1336c8:      	nop
  1336cc:      	nop

00000000001336d0 <_ZNSt6__ndk112system_errorC2ENS_10error_codeERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
  1336d0:      	adrp	x16, 0x142000
  1336d4:      	ldr	x17, [x16, #0x4e0]
  1336d8:      	add	x16, x16, #0x4e0
  1336dc:      	br	x17
  1336e0:      	nop
  1336e4:      	nop

00000000001336e8 <_ZNSt6__ndk112system_errorC2ENS_10error_codeEPKc@plt>:
  1336e8:      	adrp	x16, 0x142000
  1336ec:      	ldr	x17, [x16, #0x4e8]
  1336f0:      	add	x16, x16, #0x4e8
  1336f4:      	br	x17
  1336f8:      	nop
  1336fc:      	nop

0000000000133700 <_ZNSt6__ndk112system_errorD1Ev@plt>:
  133700:      	adrp	x16, 0x142000
  133704:      	ldr	x17, [x16, #0x4f0]
  133708:      	add	x16, x16, #0x4f0
  13370c:      	br	x17
  133710:      	nop
  133714:      	nop

0000000000133718 <_ZNSt6__ndk112system_errorC1ENS_10error_codeEPKc@plt>:
  133718:      	adrp	x16, 0x142000
  13371c:      	ldr	x17, [x16, #0x4f8]
  133720:      	add	x16, x16, #0x4f8
  133724:      	br	x17
  133728:      	nop
  13372c:      	nop

0000000000133730 <_ZNSt6__ndk18valarrayImEC1Em@plt>:
  133730:      	adrp	x16, 0x142000
  133734:      	ldr	x17, [x16, #0x500]
  133738:      	add	x16, x16, #0x500
  13373c:      	br	x17
  133740:      	nop
  133744:      	nop

0000000000133748 <_ZNSt6__ndk18valarrayImED1Ev@plt>:
  133748:      	adrp	x16, 0x142000
  13374c:      	ldr	x17, [x16, #0x508]
  133750:      	add	x16, x16, #0x508
  133754:      	br	x17
  133758:      	nop
  13375c:      	nop

0000000000133760 <pthread_self@plt>:
  133760:      	adrp	x16, 0x142000
  133764:      	ldr	x17, [x16, #0x510]
  133768:      	add	x16, x16, #0x510
  13376c:      	br	x17
  133770:      	nop
  133774:      	nop

0000000000133778 <pthread_cond_destroy@plt>:
  133778:      	adrp	x16, 0x142000
  13377c:      	ldr	x17, [x16, #0x518]
  133780:      	add	x16, x16, #0x518
  133784:      	br	x17
  133788:      	nop
  13378c:      	nop

0000000000133790 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
  133790:      	adrp	x16, 0x142000
  133794:      	ldr	x17, [x16, #0x520]
  133798:      	add	x16, x16, #0x520
  13379c:      	br	x17
  1337a0:      	nop
  1337a4:      	nop

00000000001337a8 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
  1337a8:      	adrp	x16, 0x142000
  1337ac:      	ldr	x17, [x16, #0x528]
  1337b0:      	add	x16, x16, #0x528
  1337b4:      	br	x17
  1337b8:      	nop
  1337bc:      	nop

00000000001337c0 <pthread_cond_signal@plt>:
  1337c0:      	adrp	x16, 0x142000
  1337c4:      	ldr	x17, [x16, #0x530]
  1337c8:      	add	x16, x16, #0x530
  1337cc:      	br	x17
  1337d0:      	nop
  1337d4:      	nop

00000000001337d8 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
  1337d8:      	adrp	x16, 0x142000
  1337dc:      	ldr	x17, [x16, #0x538]
  1337e0:      	add	x16, x16, #0x538
  1337e4:      	br	x17
  1337e8:      	nop
  1337ec:      	nop

00000000001337f0 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
  1337f0:      	adrp	x16, 0x142000
  1337f4:      	ldr	x17, [x16, #0x540]
  1337f8:      	add	x16, x16, #0x540
  1337fc:      	br	x17
  133800:      	nop
  133804:      	nop

0000000000133808 <pthread_cond_timedwait@plt>:
  133808:      	adrp	x16, 0x142000
  13380c:      	ldr	x17, [x16, #0x548]
  133810:      	add	x16, x16, #0x548
  133814:      	br	x17
  133818:      	nop
  13381c:      	nop

0000000000133820 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
  133820:      	adrp	x16, 0x142000
  133824:      	ldr	x17, [x16, #0x550]
  133828:      	add	x16, x16, #0x550
  13382c:      	br	x17
  133830:      	nop
  133834:      	nop

0000000000133838 <pthread_getspecific@plt>:
  133838:      	adrp	x16, 0x142000
  13383c:      	ldr	x17, [x16, #0x558]
  133840:      	add	x16, x16, #0x558
  133844:      	br	x17
  133848:      	nop
  13384c:      	nop

0000000000133850 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
  133850:      	adrp	x16, 0x142000
  133854:      	ldr	x17, [x16, #0x560]
  133858:      	add	x16, x16, #0x560
  13385c:      	br	x17
  133860:      	nop
  133864:      	nop

0000000000133868 <_ZNSt6__ndk115__thread_struct25notify_all_at_thread_exitEPNS_18condition_variableEPNS_5mutexE@plt>:
  133868:      	adrp	x16, 0x142000
  13386c:      	ldr	x17, [x16, #0x568]
  133870:      	add	x16, x16, #0x568
  133874:      	br	x17
  133878:      	nop
  13387c:      	nop

0000000000133880 <_ZNSt6__ndk112future_errorD1Ev@plt>:
  133880:      	adrp	x16, 0x142000
  133884:      	ldr	x17, [x16, #0x570]
  133888:      	add	x16, x16, #0x570
  13388c:      	br	x17
  133890:      	nop
  133894:      	nop

0000000000133898 <_ZNSt6__ndk112future_errorC1ENS_10error_codeE@plt>:
  133898:      	adrp	x16, 0x142000
  13389c:      	ldr	x17, [x16, #0x578]
  1338a0:      	add	x16, x16, #0x578
  1338a4:      	br	x17
  1338a8:      	nop
  1338ac:      	nop

00000000001338b0 <_ZNSt6__ndk117__assoc_sub_state24set_value_at_thread_exitEv@plt>:
  1338b0:      	adrp	x16, 0x142000
  1338b4:      	ldr	x17, [x16, #0x580]
  1338b8:      	add	x16, x16, #0x580
  1338bc:      	br	x17
  1338c0:      	nop
  1338c4:      	nop

00000000001338c8 <_ZNSt6__ndk115__thread_struct27__make_ready_at_thread_exitEPNS_17__assoc_sub_stateE@plt>:
  1338c8:      	adrp	x16, 0x142000
  1338cc:      	ldr	x17, [x16, #0x588]
  1338d0:      	add	x16, x16, #0x588
  1338d4:      	br	x17
  1338d8:      	nop
  1338dc:      	nop

00000000001338e0 <_ZNSt6__ndk117__assoc_sub_state13set_exceptionESt13exception_ptr@plt>:
  1338e0:      	adrp	x16, 0x142000
  1338e4:      	ldr	x17, [x16, #0x590]
  1338e8:      	add	x16, x16, #0x590
  1338ec:      	br	x17
  1338f0:      	nop
  1338f4:      	nop

00000000001338f8 <_ZNSt6__ndk117__assoc_sub_state28set_exception_at_thread_exitESt13exception_ptr@plt>:
  1338f8:      	adrp	x16, 0x142000
  1338fc:      	ldr	x17, [x16, #0x598]
  133900:      	add	x16, x16, #0x598
  133904:      	br	x17
  133908:      	nop
  13390c:      	nop

0000000000133910 <_ZNSt6__ndk117__assoc_sub_state12__make_readyEv@plt>:
  133910:      	adrp	x16, 0x142000
  133914:      	ldr	x17, [x16, #0x5a0]
  133918:      	add	x16, x16, #0x5a0
  13391c:      	br	x17
  133920:      	nop
  133924:      	nop

0000000000133928 <_ZNSt6__ndk117__assoc_sub_state4copyEv@plt>:
  133928:      	adrp	x16, 0x142000
  13392c:      	ldr	x17, [x16, #0x5a8]
  133930:      	add	x16, x16, #0x5a8
  133934:      	br	x17
  133938:      	nop
  13393c:      	nop

0000000000133940 <_ZNSt6__ndk16futureIvEC1EPNS_17__assoc_sub_stateE@plt>:
  133940:      	adrp	x16, 0x142000
  133944:      	ldr	x17, [x16, #0x5b0]
  133948:      	add	x16, x16, #0x5b0
  13394c:      	br	x17
  133950:      	nop
  133954:      	nop

0000000000133958 <pthread_mutex_destroy@plt>:
  133958:      	adrp	x16, 0x142000
  13395c:      	ldr	x17, [x16, #0x5b8]
  133960:      	add	x16, x16, #0x5b8
  133964:      	br	x17
  133968:      	nop
  13396c:      	nop

0000000000133970 <pthread_mutex_trylock@plt>:
  133970:      	adrp	x16, 0x142000
  133974:      	ldr	x17, [x16, #0x5c0]
  133978:      	add	x16, x16, #0x5c0
  13397c:      	br	x17
  133980:      	nop
  133984:      	nop

0000000000133988 <pthread_mutexattr_init@plt>:
  133988:      	adrp	x16, 0x142000
  13398c:      	ldr	x17, [x16, #0x5c8]
  133990:      	add	x16, x16, #0x5c8
  133994:      	br	x17
  133998:      	nop
  13399c:      	nop

00000000001339a0 <pthread_mutexattr_settype@plt>:
  1339a0:      	adrp	x16, 0x142000
  1339a4:      	ldr	x17, [x16, #0x5d0]
  1339a8:      	add	x16, x16, #0x5d0
  1339ac:      	br	x17
  1339b0:      	nop
  1339b4:      	nop

00000000001339b8 <pthread_mutex_init@plt>:
  1339b8:      	adrp	x16, 0x142000
  1339bc:      	ldr	x17, [x16, #0x5d8]
  1339c0:      	add	x16, x16, #0x5d8
  1339c4:      	br	x17
  1339c8:      	nop
  1339cc:      	nop

00000000001339d0 <pthread_mutexattr_destroy@plt>:
  1339d0:      	adrp	x16, 0x142000
  1339d4:      	ldr	x17, [x16, #0x5e0]
  1339d8:      	add	x16, x16, #0x5e0
  1339dc:      	br	x17
  1339e0:      	nop
  1339e4:      	nop

00000000001339e8 <_ZNSt6__ndk119__shared_mutex_baseC1Ev@plt>:
  1339e8:      	adrp	x16, 0x142000
  1339ec:      	ldr	x17, [x16, #0x5e8]
  1339f0:      	add	x16, x16, #0x5e8
  1339f4:      	br	x17
  1339f8:      	nop
  1339fc:      	nop

0000000000133a00 <pthread_join@plt>:
  133a00:      	adrp	x16, 0x142000
  133a04:      	ldr	x17, [x16, #0x5f0]
  133a08:      	add	x16, x16, #0x5f0
  133a0c:      	br	x17
  133a10:      	nop
  133a14:      	nop

0000000000133a18 <pthread_detach@plt>:
  133a18:      	adrp	x16, 0x142000
  133a1c:      	ldr	x17, [x16, #0x5f8]
  133a20:      	add	x16, x16, #0x5f8
  133a24:      	br	x17
  133a28:      	nop
  133a2c:      	nop

0000000000133a30 <sysconf@plt>:
  133a30:      	adrp	x16, 0x142000
  133a34:      	ldr	x17, [x16, #0x600]
  133a38:      	add	x16, x16, #0x600
  133a3c:      	br	x17
  133a40:      	nop
  133a44:      	nop

0000000000133a48 <nanosleep@plt>:
  133a48:      	adrp	x16, 0x142000
  133a4c:      	ldr	x17, [x16, #0x608]
  133a50:      	add	x16, x16, #0x608
  133a54:      	br	x17
  133a58:      	nop
  133a5c:      	nop

0000000000133a60 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
  133a60:      	adrp	x16, 0x142000
  133a64:      	ldr	x17, [x16, #0x610]
  133a68:      	add	x16, x16, #0x610
  133a6c:      	br	x17
  133a70:      	nop
  133a74:      	nop

0000000000133a78 <open@plt>:
  133a78:      	adrp	x16, 0x142000
  133a7c:      	ldr	x17, [x16, #0x618]
  133a80:      	add	x16, x16, #0x618
  133a84:      	br	x17
  133a88:      	nop
  133a8c:      	nop

0000000000133a90 <close@plt>:
  133a90:      	adrp	x16, 0x142000
  133a94:      	ldr	x17, [x16, #0x620]
  133a98:      	add	x16, x16, #0x620
  133a9c:      	br	x17
  133aa0:      	nop
  133aa4:      	nop

0000000000133aa8 <read@plt>:
  133aa8:      	adrp	x16, 0x142000
  133aac:      	ldr	x17, [x16, #0x628]
  133ab0:      	add	x16, x16, #0x628
  133ab4:      	br	x17
  133ab8:      	nop
  133abc:      	nop

0000000000133ac0 <ioctl@plt>:
  133ac0:      	adrp	x16, 0x142000
  133ac4:      	ldr	x17, [x16, #0x630]
  133ac8:      	add	x16, x16, #0x630
  133acc:      	br	x17
  133ad0:      	nop
  133ad4:      	nop

0000000000133ad8 <_ZNSt6__ndk18ios_base7failureD1Ev@plt>:
  133ad8:      	adrp	x16, 0x142000
  133adc:      	ldr	x17, [x16, #0x638]
  133ae0:      	add	x16, x16, #0x638
  133ae4:      	br	x17
  133ae8:      	nop
  133aec:      	nop

0000000000133af0 <_ZNSt6__ndk18ios_base16__call_callbacksENS0_5eventE@plt>:
  133af0:      	adrp	x16, 0x142000
  133af4:      	ldr	x17, [x16, #0x640]
  133af8:      	add	x16, x16, #0x640
  133afc:      	br	x17
  133b00:      	nop
  133b04:      	nop

0000000000133b08 <_ZNSt6__ndk16localeC1ERKS0_@plt>:
  133b08:      	adrp	x16, 0x142000
  133b0c:      	ldr	x17, [x16, #0x648]
  133b10:      	add	x16, x16, #0x648
  133b14:      	br	x17
  133b18:      	nop
  133b1c:      	nop

0000000000133b20 <_ZNSt6__ndk16localeaSERKS0_@plt>:
  133b20:      	adrp	x16, 0x142000
  133b24:      	ldr	x17, [x16, #0x650]
  133b28:      	add	x16, x16, #0x650
  133b2c:      	br	x17
  133b30:      	nop
  133b34:      	nop

0000000000133b38 <_ZNSt6__ndk16localeD1Ev@plt>:
  133b38:      	adrp	x16, 0x142000
  133b3c:      	ldr	x17, [x16, #0x658]
  133b40:      	add	x16, x16, #0x658
  133b44:      	br	x17
  133b48:      	nop
  133b4c:      	nop

0000000000133b50 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  133b50:      	adrp	x16, 0x142000
  133b54:      	ldr	x17, [x16, #0x660]
  133b58:      	add	x16, x16, #0x660
  133b5c:      	br	x17
  133b60:      	nop
  133b64:      	nop

0000000000133b68 <_ZNSt6__ndk18ios_baseD2Ev@plt>:
  133b68:      	adrp	x16, 0x142000
  133b6c:      	ldr	x17, [x16, #0x668]
  133b70:      	add	x16, x16, #0x668
  133b74:      	br	x17
  133b78:      	nop
  133b7c:      	nop

0000000000133b80 <_ZNSt6__ndk18ios_baseD1Ev@plt>:
  133b80:      	adrp	x16, 0x142000
  133b84:      	ldr	x17, [x16, #0x670]
  133b88:      	add	x16, x16, #0x670
  133b8c:      	br	x17
  133b90:      	nop
  133b94:      	nop

0000000000133b98 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  133b98:      	adrp	x16, 0x142000
  133b9c:      	ldr	x17, [x16, #0x678]
  133ba0:      	add	x16, x16, #0x678
  133ba4:      	br	x17
  133ba8:      	nop
  133bac:      	nop

0000000000133bb0 <_ZNSt6__ndk18ios_base7failureC1EPKcRKNS_10error_codeE@plt>:
  133bb0:      	adrp	x16, 0x142000
  133bb4:      	ldr	x17, [x16, #0x680]
  133bb8:      	add	x16, x16, #0x680
  133bbc:      	br	x17
  133bc0:      	nop
  133bc4:      	nop

0000000000133bc8 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  133bc8:      	adrp	x16, 0x142000
  133bcc:      	ldr	x17, [x16, #0x688]
  133bd0:      	add	x16, x16, #0x688
  133bd4:      	br	x17
  133bd8:      	nop
  133bdc:      	nop

0000000000133be0 <_ZNSt6__ndk16localeC1Ev@plt>:
  133be0:      	adrp	x16, 0x142000
  133be4:      	ldr	x17, [x16, #0x690]
  133be8:      	add	x16, x16, #0x690
  133bec:      	br	x17
  133bf0:      	nop
  133bf4:      	nop

0000000000133bf8 <_ZNSt6__ndk18ios_base7copyfmtERKS0_@plt>:
  133bf8:      	adrp	x16, 0x142000
  133bfc:      	ldr	x17, [x16, #0x698]
  133c00:      	add	x16, x16, #0x698
  133c04:      	br	x17
  133c08:      	nop
  133c0c:      	nop

0000000000133c10 <_ZNSt6__ndk18ios_base4swapERS0_@plt>:
  133c10:      	adrp	x16, 0x142000
  133c14:      	ldr	x17, [x16, #0x6a0]
  133c18:      	add	x16, x16, #0x6a0
  133c1c:      	br	x17
  133c20:      	nop
  133c24:      	nop

0000000000133c28 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
  133c28:      	adrp	x16, 0x142000
  133c2c:      	ldr	x17, [x16, #0x6a8]
  133c30:      	add	x16, x16, #0x6a8
  133c34:      	br	x17
  133c38:      	nop
  133c3c:      	nop

0000000000133c40 <_ZNSt6__ndk18ios_base34__set_failbit_and_consider_rethrowEv@plt>:
  133c40:      	adrp	x16, 0x142000
  133c44:      	ldr	x17, [x16, #0x6b0]
  133c48:      	add	x16, x16, #0x6b0
  133c4c:      	br	x17
  133c50:      	nop
  133c54:      	nop

0000000000133c58 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  133c58:      	adrp	x16, 0x142000
  133c5c:      	ldr	x17, [x16, #0x6b8]
  133c60:      	add	x16, x16, #0x6b8
  133c64:      	br	x17
  133c68:      	nop
  133c6c:      	nop

0000000000133c70 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED1Ev@plt>:
  133c70:      	adrp	x16, 0x142000
  133c74:      	ldr	x17, [x16, #0x6c0]
  133c78:      	add	x16, x16, #0x6c0
  133c7c:      	br	x17
  133c80:      	nop
  133c84:      	nop

0000000000133c88 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
  133c88:      	adrp	x16, 0x142000
  133c8c:      	ldr	x17, [x16, #0x6c8]
  133c90:      	add	x16, x16, #0x6c8
  133c94:      	br	x17
  133c98:      	nop
  133c9c:      	nop

0000000000133ca0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED1Ev@plt>:
  133ca0:      	adrp	x16, 0x142000
  133ca4:      	ldr	x17, [x16, #0x6d0]
  133ca8:      	add	x16, x16, #0x6d0
  133cac:      	br	x17
  133cb0:      	nop
  133cb4:      	nop

0000000000133cb8 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  133cb8:      	adrp	x16, 0x142000
  133cbc:      	ldr	x17, [x16, #0x6d8]
  133cc0:      	add	x16, x16, #0x6d8
  133cc4:      	br	x17
  133cc8:      	nop
  133ccc:      	nop

0000000000133cd0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEE4swapERS3_@plt>:
  133cd0:      	adrp	x16, 0x142000
  133cd4:      	ldr	x17, [x16, #0x6e0]
  133cd8:      	add	x16, x16, #0x6e0
  133cdc:      	br	x17
  133ce0:      	nop
  133ce4:      	nop

0000000000133ce8 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
  133ce8:      	adrp	x16, 0x142000
  133cec:      	ldr	x17, [x16, #0x6e8]
  133cf0:      	add	x16, x16, #0x6e8
  133cf4:      	br	x17
  133cf8:      	nop
  133cfc:      	nop

0000000000133d00 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
  133d00:      	adrp	x16, 0x142000
  133d04:      	ldr	x17, [x16, #0x6f0]
  133d08:      	add	x16, x16, #0x6f0
  133d0c:      	br	x17
  133d10:      	nop
  133d14:      	nop

0000000000133d18 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  133d18:      	adrp	x16, 0x142000
  133d1c:      	ldr	x17, [x16, #0x6f8]
  133d20:      	add	x16, x16, #0x6f8
  133d24:      	br	x17
  133d28:      	nop
  133d2c:      	nop

0000000000133d30 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
  133d30:      	adrp	x16, 0x142000
  133d34:      	ldr	x17, [x16, #0x700]
  133d38:      	add	x16, x16, #0x700
  133d3c:      	br	x17
  133d40:      	nop
  133d44:      	nop

0000000000133d48 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
  133d48:      	adrp	x16, 0x142000
  133d4c:      	ldr	x17, [x16, #0x708]
  133d50:      	add	x16, x16, #0x708
  133d54:      	br	x17
  133d58:      	nop
  133d5c:      	nop

0000000000133d60 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
  133d60:      	adrp	x16, 0x142000
  133d64:      	ldr	x17, [x16, #0x710]
  133d68:      	add	x16, x16, #0x710
  133d6c:      	br	x17
  133d70:      	nop
  133d74:      	nop

0000000000133d78 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEv@plt>:
  133d78:      	adrp	x16, 0x142000
  133d7c:      	ldr	x17, [x16, #0x718]
  133d80:      	add	x16, x16, #0x718
  133d84:      	br	x17
  133d88:      	nop
  133d8c:      	nop

0000000000133d90 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getEPclc@plt>:
  133d90:      	adrp	x16, 0x142000
  133d94:      	ldr	x17, [x16, #0x720]
  133d98:      	add	x16, x16, #0x720
  133d9c:      	br	x17
  133da0:      	nop
  133da4:      	nop

0000000000133da8 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE3getERNS_15basic_streambufIcS2_EEc@plt>:
  133da8:      	adrp	x16, 0x142000
  133dac:      	ldr	x17, [x16, #0x728]
  133db0:      	add	x16, x16, #0x728
  133db4:      	br	x17
  133db8:      	nop
  133dbc:      	nop

0000000000133dc0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE7getlineEPclc@plt>:
  133dc0:      	adrp	x16, 0x142000
  133dc4:      	ldr	x17, [x16, #0x730]
  133dc8:      	add	x16, x16, #0x730
  133dcc:      	br	x17
  133dd0:      	nop
  133dd4:      	nop

0000000000133dd8 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  133dd8:      	adrp	x16, 0x142000
  133ddc:      	ldr	x17, [x16, #0x738]
  133de0:      	add	x16, x16, #0x738
  133de4:      	br	x17
  133de8:      	nop
  133dec:      	nop

0000000000133df0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  133df0:      	adrp	x16, 0x142000
  133df4:      	ldr	x17, [x16, #0x740]
  133df8:      	add	x16, x16, #0x740
  133dfc:      	br	x17
  133e00:      	nop
  133e04:      	nop

0000000000133e08 <_ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED2Ev@plt>:
  133e08:      	adrp	x16, 0x142000
  133e0c:      	ldr	x17, [x16, #0x748]
  133e10:      	add	x16, x16, #0x748
  133e14:      	br	x17
  133e18:      	nop
  133e1c:      	nop

0000000000133e20 <_ZNSt6__ndk19basic_iosIwNS_11char_traitsIwEEED1Ev@plt>:
  133e20:      	adrp	x16, 0x142000
  133e24:      	ldr	x17, [x16, #0x750]
  133e28:      	add	x16, x16, #0x750
  133e2c:      	br	x17
  133e30:      	nop
  133e34:      	nop

0000000000133e38 <_ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED2Ev@plt>:
  133e38:      	adrp	x16, 0x142000
  133e3c:      	ldr	x17, [x16, #0x758]
  133e40:      	add	x16, x16, #0x758
  133e44:      	br	x17
  133e48:      	nop
  133e4c:      	nop

0000000000133e50 <_ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEED1Ev@plt>:
  133e50:      	adrp	x16, 0x142000
  133e54:      	ldr	x17, [x16, #0x760]
  133e58:      	add	x16, x16, #0x760
  133e5c:      	br	x17
  133e60:      	nop
  133e64:      	nop

0000000000133e68 <_ZNSt6__ndk115basic_streambufIwNS_11char_traitsIwEEEC2Ev@plt>:
  133e68:      	adrp	x16, 0x142000
  133e6c:      	ldr	x17, [x16, #0x768]
  133e70:      	add	x16, x16, #0x768
  133e74:      	br	x17
  133e78:      	nop
  133e7c:      	nop

0000000000133e80 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5flushEv@plt>:
  133e80:      	adrp	x16, 0x142000
  133e84:      	ldr	x17, [x16, #0x770]
  133e88:      	add	x16, x16, #0x770
  133e8c:      	br	x17
  133e90:      	nop
  133e94:      	nop

0000000000133e98 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryC1ERS3_@plt>:
  133e98:      	adrp	x16, 0x142000
  133e9c:      	ldr	x17, [x16, #0x778]
  133ea0:      	add	x16, x16, #0x778
  133ea4:      	br	x17
  133ea8:      	nop
  133eac:      	nop

0000000000133eb0 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE6sentryD1Ev@plt>:
  133eb0:      	adrp	x16, 0x142000
  133eb4:      	ldr	x17, [x16, #0x780]
  133eb8:      	add	x16, x16, #0x780
  133ebc:      	br	x17
  133ec0:      	nop
  133ec4:      	nop

0000000000133ec8 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE6sentryC1ERS3_b@plt>:
  133ec8:      	adrp	x16, 0x142000
  133ecc:      	ldr	x17, [x16, #0x788]
  133ed0:      	add	x16, x16, #0x788
  133ed4:      	br	x17
  133ed8:      	nop
  133edc:      	nop

0000000000133ee0 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEv@plt>:
  133ee0:      	adrp	x16, 0x142000
  133ee4:      	ldr	x17, [x16, #0x790]
  133ee8:      	add	x16, x16, #0x790
  133eec:      	br	x17
  133ef0:      	nop
  133ef4:      	nop

0000000000133ef8 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getEPwlw@plt>:
  133ef8:      	adrp	x16, 0x142000
  133efc:      	ldr	x17, [x16, #0x798]
  133f00:      	add	x16, x16, #0x798
  133f04:      	br	x17
  133f08:      	nop
  133f0c:      	nop

0000000000133f10 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE3getERNS_15basic_streambufIwS2_EEw@plt>:
  133f10:      	adrp	x16, 0x142000
  133f14:      	ldr	x17, [x16, #0x7a0]
  133f18:      	add	x16, x16, #0x7a0
  133f1c:      	br	x17
  133f20:      	nop
  133f24:      	nop

0000000000133f28 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE7getlineEPwlw@plt>:
  133f28:      	adrp	x16, 0x142000
  133f2c:      	ldr	x17, [x16, #0x7a8]
  133f30:      	add	x16, x16, #0x7a8
  133f34:      	br	x17
  133f38:      	nop
  133f3c:      	nop

0000000000133f40 <_ZNSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEOS5_@plt>:
  133f40:      	adrp	x16, 0x142000
  133f44:      	ldr	x17, [x16, #0x7b0]
  133f48:      	add	x16, x16, #0x7b0
  133f4c:      	br	x17
  133f50:      	nop
  133f54:      	nop

0000000000133f58 <fopen@plt>:
  133f58:      	adrp	x16, 0x142000
  133f5c:      	ldr	x17, [x16, #0x7b8]
  133f60:      	add	x16, x16, #0x7b8
  133f64:      	br	x17
  133f68:      	nop
  133f6c:      	nop

0000000000133f70 <fseek@plt>:
  133f70:      	adrp	x16, 0x142000
  133f74:      	ldr	x17, [x16, #0x7c0]
  133f78:      	add	x16, x16, #0x7c0
  133f7c:      	br	x17
  133f80:      	nop
  133f84:      	nop

0000000000133f88 <fclose@plt>:
  133f88:      	adrp	x16, 0x142000
  133f8c:      	ldr	x17, [x16, #0x7c8]
  133f90:      	add	x16, x16, #0x7c8
  133f94:      	br	x17
  133f98:      	nop
  133f9c:      	nop

0000000000133fa0 <_ZNKSt6__ndk16locale9has_facetERNS0_2idE@plt>:
  133fa0:      	adrp	x16, 0x142000
  133fa4:      	ldr	x17, [x16, #0x7d0]
  133fa8:      	add	x16, x16, #0x7d0
  133fac:      	br	x17
  133fb0:      	nop
  133fb4:      	nop

0000000000133fb8 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4syncEv@plt>:
  133fb8:      	adrp	x16, 0x142000
  133fbc:      	ldr	x17, [x16, #0x7d8]
  133fc0:      	add	x16, x16, #0x7d8
  133fc4:      	br	x17
  133fc8:      	nop
  133fcc:      	nop

0000000000133fd0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
  133fd0:      	adrp	x16, 0x142000
  133fd4:      	ldr	x17, [x16, #0x7e0]
  133fd8:      	add	x16, x16, #0x7e0
  133fdc:      	br	x17
  133fe0:      	nop
  133fe4:      	nop

0000000000133fe8 <fread@plt>:
  133fe8:      	adrp	x16, 0x142000
  133fec:      	ldr	x17, [x16, #0x7e8]
  133ff0:      	add	x16, x16, #0x7e8
  133ff4:      	br	x17
  133ff8:      	nop
  133ffc:      	nop

0000000000134000 <fseeko@plt>:
  134000:      	adrp	x16, 0x142000
  134004:      	ldr	x17, [x16, #0x7f0]
  134008:      	add	x16, x16, #0x7f0
  13400c:      	br	x17
  134010:      	nop
  134014:      	nop

0000000000134018 <ftello@plt>:
  134018:      	adrp	x16, 0x142000
  13401c:      	ldr	x17, [x16, #0x7f8]
  134020:      	add	x16, x16, #0x7f8
  134024:      	br	x17
  134028:      	nop
  13402c:      	nop

0000000000134030 <fflush@plt>:
  134030:      	adrp	x16, 0x142000
  134034:      	ldr	x17, [x16, #0x800]
  134038:      	add	x16, x16, #0x800
  13403c:      	br	x17
  134040:      	nop
  134044:      	nop

0000000000134048 <ungetc@plt>:
  134048:      	adrp	x16, 0x142000
  13404c:      	ldr	x17, [x16, #0x808]
  134050:      	add	x16, x16, #0x808
  134054:      	br	x17
  134058:      	nop
  13405c:      	nop

0000000000134060 <getc@plt>:
  134060:      	adrp	x16, 0x142000
  134064:      	ldr	x17, [x16, #0x810]
  134068:      	add	x16, x16, #0x810
  13406c:      	br	x17
  134070:      	nop
  134074:      	nop

0000000000134078 <ungetwc@plt>:
  134078:      	adrp	x16, 0x142000
  13407c:      	ldr	x17, [x16, #0x818]
  134080:      	add	x16, x16, #0x818
  134084:      	br	x17
  134088:      	nop
  13408c:      	nop

0000000000134090 <getwc@plt>:
  134090:      	adrp	x16, 0x142000
  134094:      	ldr	x17, [x16, #0x820]
  134098:      	add	x16, x16, #0x820
  13409c:      	br	x17
  1340a0:      	nop
  1340a4:      	nop

00000000001340a8 <fputwc@plt>:
  1340a8:      	adrp	x16, 0x142000
  1340ac:      	ldr	x17, [x16, #0x828]
  1340b0:      	add	x16, x16, #0x828
  1340b4:      	br	x17
  1340b8:      	nop
  1340bc:      	nop

00000000001340c0 <_ZNSt6__ndk18ios_base4InitC1Ev@plt>:
  1340c0:      	adrp	x16, 0x142000
  1340c4:      	ldr	x17, [x16, #0x830]
  1340c8:      	add	x16, x16, #0x830
  1340cc:      	br	x17
  1340d0:      	nop
  1340d4:      	nop

00000000001340d8 <_ZNSt6__ndk17collateIcED1Ev@plt>:
  1340d8:      	adrp	x16, 0x142000
  1340dc:      	ldr	x17, [x16, #0x838]
  1340e0:      	add	x16, x16, #0x838
  1340e4:      	br	x17
  1340e8:      	nop
  1340ec:      	nop

00000000001340f0 <_ZNSt6__ndk17collateIwED1Ev@plt>:
  1340f0:      	adrp	x16, 0x142000
  1340f4:      	ldr	x17, [x16, #0x840]
  1340f8:      	add	x16, x16, #0x840
  1340fc:      	br	x17
  134100:      	nop
  134104:      	nop

0000000000134108 <_ZNSt6__ndk19__num_getIcE17__stage2_int_prepERNS_8ios_baseEPcRc@plt>:
  134108:      	adrp	x16, 0x142000
  13410c:      	ldr	x17, [x16, #0x848]
  134110:      	add	x16, x16, #0x848
  134114:      	br	x17
  134118:      	nop
  13411c:      	nop

0000000000134120 <_ZNSt6__ndk19__num_getIcE19__stage2_float_prepERNS_8ios_baseEPcRcS5_@plt>:
  134120:      	adrp	x16, 0x142000
  134124:      	ldr	x17, [x16, #0x850]
  134128:      	add	x16, x16, #0x850
  13412c:      	br	x17
  134130:      	nop
  134134:      	nop

0000000000134138 <_ZNSt6__ndk19__num_getIcE19__stage2_float_loopEcRbRcPcRS4_ccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjS4_@plt>:
  134138:      	adrp	x16, 0x142000
  13413c:      	ldr	x17, [x16, #0x858]
  134140:      	add	x16, x16, #0x858
  134144:      	br	x17
  134148:      	nop
  13414c:      	nop

0000000000134150 <newlocale@plt>:
  134150:      	adrp	x16, 0x142000
  134154:      	ldr	x17, [x16, #0x860]
  134158:      	add	x16, x16, #0x860
  13415c:      	br	x17
  134160:      	nop
  134164:      	nop

0000000000134168 <uselocale@plt>:
  134168:      	adrp	x16, 0x142000
  13416c:      	ldr	x17, [x16, #0x868]
  134170:      	add	x16, x16, #0x868
  134174:      	br	x17
  134178:      	nop
  13417c:      	nop

0000000000134180 <vsscanf@plt>:
  134180:      	adrp	x16, 0x142000
  134184:      	ldr	x17, [x16, #0x870]
  134188:      	add	x16, x16, #0x870
  13418c:      	br	x17
  134190:      	nop
  134194:      	nop

0000000000134198 <_ZNSt6__ndk19__num_getIwE17__stage2_int_prepERNS_8ios_baseEPwRw@plt>:
  134198:      	adrp	x16, 0x142000
  13419c:      	ldr	x17, [x16, #0x878]
  1341a0:      	add	x16, x16, #0x878
  1341a4:      	br	x17
  1341a8:      	nop
  1341ac:      	nop

00000000001341b0 <_ZNSt6__ndk19__num_getIwE19__stage2_float_prepERNS_8ios_baseEPwRwS5_@plt>:
  1341b0:      	adrp	x16, 0x142000
  1341b4:      	ldr	x17, [x16, #0x880]
  1341b8:      	add	x16, x16, #0x880
  1341bc:      	br	x17
  1341c0:      	nop
  1341c4:      	nop

00000000001341c8 <_ZNSt6__ndk19__num_getIwE19__stage2_float_loopEwRbRcPcRS4_wwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPjRSE_RjPw@plt>:
  1341c8:      	adrp	x16, 0x142000
  1341cc:      	ldr	x17, [x16, #0x888]
  1341d0:      	add	x16, x16, #0x888
  1341d4:      	br	x17
  1341d8:      	nop
  1341dc:      	nop

00000000001341e0 <_ZNSt6__ndk19__num_putIcE21__widen_and_group_intEPcS2_S2_S2_RS2_S3_RKNS_6localeE@plt>:
  1341e0:      	adrp	x16, 0x142000
  1341e4:      	ldr	x17, [x16, #0x890]
  1341e8:      	add	x16, x16, #0x890
  1341ec:      	br	x17
  1341f0:      	nop
  1341f4:      	nop

00000000001341f8 <_ZNSt6__ndk19__num_putIcE23__widen_and_group_floatEPcS2_S2_S2_RS2_S3_RKNS_6localeE@plt>:
  1341f8:      	adrp	x16, 0x142000
  1341fc:      	ldr	x17, [x16, #0x898]
  134200:      	add	x16, x16, #0x898
  134204:      	br	x17
  134208:      	nop
  13420c:      	nop

0000000000134210 <_ZNSt6__ndk19__num_putIwE21__widen_and_group_intEPcS2_S2_PwRS3_S4_RKNS_6localeE@plt>:
  134210:      	adrp	x16, 0x142000
  134214:      	ldr	x17, [x16, #0x8a0]
  134218:      	add	x16, x16, #0x8a0
  13421c:      	br	x17
  134220:      	nop
  134224:      	nop

0000000000134228 <_ZNSt6__ndk19__num_putIwE23__widen_and_group_floatEPcS2_S2_PwRS3_S4_RKNS_6localeE@plt>:
  134228:      	adrp	x16, 0x142000
  13422c:      	ldr	x17, [x16, #0x8a8]
  134230:      	add	x16, x16, #0x8a8
  134234:      	br	x17
  134238:      	nop
  13423c:      	nop

0000000000134240 <_ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKcSC_@plt>:
  134240:      	adrp	x16, 0x142000
  134244:      	ldr	x17, [x16, #0x8b0]
  134248:      	add	x16, x16, #0x8b0
  13424c:      	br	x17
  134250:      	nop
  134254:      	nop

0000000000134258 <_ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIcEE@plt>:
  134258:      	adrp	x16, 0x142000
  13425c:      	ldr	x17, [x16, #0x8b8]
  134260:      	add	x16, x16, #0x8b8
  134264:      	br	x17
  134268:      	nop
  13426c:      	nop

0000000000134270 <_ZNKSt6__ndk18time_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIcEE@plt>:
  134270:      	adrp	x16, 0x142000
  134274:      	ldr	x17, [x16, #0x8c0]
  134278:      	add	x16, x16, #0x8c0
  13427c:      	br	x17
  134280:      	nop
  134284:      	nop

0000000000134288 <_ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE3getES4_S4_RNS_8ios_baseERjP2tmPKwSC_@plt>:
  134288:      	adrp	x16, 0x142000
  13428c:      	ldr	x17, [x16, #0x8c8]
  134290:      	add	x16, x16, #0x8c8
  134294:      	br	x17
  134298:      	nop
  13429c:      	nop

00000000001342a0 <_ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE17__get_white_spaceERS4_S4_RjRKNS_5ctypeIwEE@plt>:
  1342a0:      	adrp	x16, 0x142000
  1342a4:      	ldr	x17, [x16, #0x8d0]
  1342a8:      	add	x16, x16, #0x8d0
  1342ac:      	br	x17
  1342b0:      	nop
  1342b4:      	nop

00000000001342b8 <_ZNKSt6__ndk18time_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE13__get_percentERS4_S4_RjRKNS_5ctypeIwEE@plt>:
  1342b8:      	adrp	x16, 0x142000
  1342bc:      	ldr	x17, [x16, #0x8d8]
  1342c0:      	add	x16, x16, #0x8d8
  1342c4:      	br	x17
  1342c8:      	nop
  1342cc:      	nop

00000000001342d0 <strftime_l@plt>:
  1342d0:      	adrp	x16, 0x142000
  1342d4:      	ldr	x17, [x16, #0x8e0]
  1342d8:      	add	x16, x16, #0x8e0
  1342dc:      	br	x17
  1342e0:      	nop
  1342e4:      	nop

00000000001342e8 <_ZNKSt6__ndk110__time_put8__do_putEPwRS1_PK2tmcc@plt>:
  1342e8:      	adrp	x16, 0x142000
  1342ec:      	ldr	x17, [x16, #0x8e8]
  1342f0:      	add	x16, x16, #0x8e8
  1342f4:      	br	x17
  1342f8:      	nop
  1342fc:      	nop

0000000000134300 <mbsrtowcs@plt>:
  134300:      	adrp	x16, 0x142000
  134304:      	ldr	x17, [x16, #0x8f0]
  134308:      	add	x16, x16, #0x8f0
  13430c:      	br	x17
  134310:      	nop
  134314:      	nop

0000000000134318 <_ZNSt6__ndk19money_getIcNS_19istreambuf_iteratorIcNS_11char_traitsIcEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIcEERNS_10unique_ptrIcPFvPvEEERPcSM_@plt>:
  134318:      	adrp	x16, 0x142000
  13431c:      	ldr	x17, [x16, #0x8f8]
  134320:      	add	x16, x16, #0x8f8
  134324:      	br	x17
  134328:      	nop
  13432c:      	nop

0000000000134330 <sscanf@plt>:
  134330:      	adrp	x16, 0x142000
  134334:      	ldr	x17, [x16, #0x900]
  134338:      	add	x16, x16, #0x900
  13433c:      	br	x17
  134340:      	nop
  134344:      	nop

0000000000134348 <_ZNSt6__ndk111__money_getIcE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_SF_Ri@plt>:
  134348:      	adrp	x16, 0x142000
  13434c:      	ldr	x17, [x16, #0x908]
  134350:      	add	x16, x16, #0x908
  134354:      	br	x17
  134358:      	nop
  13435c:      	nop

0000000000134360 <_ZNSt6__ndk19money_getIwNS_19istreambuf_iteratorIwNS_11char_traitsIwEEEEE8__do_getERS4_S4_bRKNS_6localeEjRjRbRKNS_5ctypeIwEERNS_10unique_ptrIwPFvPvEEERPwSM_@plt>:
  134360:      	adrp	x16, 0x142000
  134364:      	ldr	x17, [x16, #0x910]
  134368:      	add	x16, x16, #0x910
  13436c:      	br	x17
  134370:      	nop
  134374:      	nop

0000000000134378 <_ZNSt6__ndk111__money_getIwE13__gather_infoEbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_SJ_Ri@plt>:
  134378:      	adrp	x16, 0x142000
  13437c:      	ldr	x17, [x16, #0x918]
  134380:      	add	x16, x16, #0x918
  134384:      	br	x17
  134388:      	nop
  13438c:      	nop

0000000000134390 <_ZNSt6__ndk111__money_putIcE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERcS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESF_SF_Ri@plt>:
  134390:      	adrp	x16, 0x142000
  134394:      	ldr	x17, [x16, #0x920]
  134398:      	add	x16, x16, #0x920
  13439c:      	br	x17
  1343a0:      	nop
  1343a4:      	nop

00000000001343a8 <_ZNSt6__ndk111__money_putIcE8__formatEPcRS2_S3_jPKcS5_RKNS_5ctypeIcEEbRKNS_10money_base7patternEccRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEESL_SL_i@plt>:
  1343a8:      	adrp	x16, 0x142000
  1343ac:      	ldr	x17, [x16, #0x928]
  1343b0:      	add	x16, x16, #0x928
  1343b4:      	br	x17
  1343b8:      	nop
  1343bc:      	nop

00000000001343c0 <_ZNSt6__ndk111__money_putIwE13__gather_infoEbbRKNS_6localeERNS_10money_base7patternERwS8_RNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERNS9_IwNSA_IwEENSC_IwEEEESJ_Ri@plt>:
  1343c0:      	adrp	x16, 0x142000
  1343c4:      	ldr	x17, [x16, #0x930]
  1343c8:      	add	x16, x16, #0x930
  1343cc:      	br	x17
  1343d0:      	nop
  1343d4:      	nop

00000000001343d8 <_ZNSt6__ndk111__money_putIwE8__formatEPwRS2_S3_jPKwS5_RKNS_5ctypeIwEEbRKNS_10money_base7patternEwwRKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEERKNSE_IwNSF_IwEENSH_IwEEEESQ_i@plt>:
  1343d8:      	adrp	x16, 0x142000
  1343dc:      	ldr	x17, [x16, #0x938]
  1343e0:      	add	x16, x16, #0x938
  1343e4:      	br	x17
  1343e8:      	nop
  1343ec:      	nop

00000000001343f0 <_ZNSt6__ndk17codecvtIcc9mbstate_tED2Ev@plt>:
  1343f0:      	adrp	x16, 0x142000
  1343f4:      	ldr	x17, [x16, #0x940]
  1343f8:      	add	x16, x16, #0x940
  1343fc:      	br	x17
  134400:      	nop
  134404:      	nop

0000000000134408 <_ZNSt6__ndk114codecvt_bynameIcc9mbstate_tED1Ev@plt>:
  134408:      	adrp	x16, 0x142000
  13440c:      	ldr	x17, [x16, #0x948]
  134410:      	add	x16, x16, #0x948
  134414:      	br	x17
  134418:      	nop
  13441c:      	nop

0000000000134420 <_ZNSt6__ndk17codecvtIwc9mbstate_tED2Ev@plt>:
  134420:      	adrp	x16, 0x142000
  134424:      	ldr	x17, [x16, #0x950]
  134428:      	add	x16, x16, #0x950
  13442c:      	br	x17
  134430:      	nop
  134434:      	nop

0000000000134438 <_ZNSt6__ndk114codecvt_bynameIwc9mbstate_tED1Ev@plt>:
  134438:      	adrp	x16, 0x142000
  13443c:      	ldr	x17, [x16, #0x958]
  134440:      	add	x16, x16, #0x958
  134444:      	br	x17
  134448:      	nop
  13444c:      	nop

0000000000134450 <_ZNSt6__ndk17codecvtIDsc9mbstate_tED2Ev@plt>:
  134450:      	adrp	x16, 0x142000
  134454:      	ldr	x17, [x16, #0x960]
  134458:      	add	x16, x16, #0x960
  13445c:      	br	x17
  134460:      	nop
  134464:      	nop

0000000000134468 <_ZNSt6__ndk114codecvt_bynameIDsc9mbstate_tED1Ev@plt>:
  134468:      	adrp	x16, 0x142000
  13446c:      	ldr	x17, [x16, #0x968]
  134470:      	add	x16, x16, #0x968
  134474:      	br	x17
  134478:      	nop
  13447c:      	nop

0000000000134480 <_ZNSt6__ndk17codecvtIDic9mbstate_tED2Ev@plt>:
  134480:      	adrp	x16, 0x142000
  134484:      	ldr	x17, [x16, #0x970]
  134488:      	add	x16, x16, #0x970
  13448c:      	br	x17
  134490:      	nop
  134494:      	nop

0000000000134498 <_ZNSt6__ndk114codecvt_bynameIDic9mbstate_tED1Ev@plt>:
  134498:      	adrp	x16, 0x142000
  13449c:      	ldr	x17, [x16, #0x978]
  1344a0:      	add	x16, x16, #0x978
  1344a4:      	br	x17
  1344a8:      	nop
  1344ac:      	nop

00000000001344b0 <_ZNSt6__ndk17codecvtIDsDu9mbstate_tED2Ev@plt>:
  1344b0:      	adrp	x16, 0x142000
  1344b4:      	ldr	x17, [x16, #0x980]
  1344b8:      	add	x16, x16, #0x980
  1344bc:      	br	x17
  1344c0:      	nop
  1344c4:      	nop

00000000001344c8 <_ZNSt6__ndk114codecvt_bynameIDsDu9mbstate_tED1Ev@plt>:
  1344c8:      	adrp	x16, 0x142000
  1344cc:      	ldr	x17, [x16, #0x988]
  1344d0:      	add	x16, x16, #0x988
  1344d4:      	br	x17
  1344d8:      	nop
  1344dc:      	nop

00000000001344e0 <_ZNSt6__ndk17codecvtIDiDu9mbstate_tED2Ev@plt>:
  1344e0:      	adrp	x16, 0x142000
  1344e4:      	ldr	x17, [x16, #0x990]
  1344e8:      	add	x16, x16, #0x990
  1344ec:      	br	x17
  1344f0:      	nop
  1344f4:      	nop

00000000001344f8 <_ZNSt6__ndk114codecvt_bynameIDiDu9mbstate_tED1Ev@plt>:
  1344f8:      	adrp	x16, 0x142000
  1344fc:      	ldr	x17, [x16, #0x998]
  134500:      	add	x16, x16, #0x998
  134504:      	br	x17
  134508:      	nop
  13450c:      	nop

0000000000134510 <_ZNSt6__ndk15ctypeIcEC1EPKmbm@plt>:
  134510:      	adrp	x16, 0x142000
  134514:      	ldr	x17, [x16, #0x9a0]
  134518:      	add	x16, x16, #0x9a0
  13451c:      	br	x17
  134520:      	nop
  134524:      	nop

0000000000134528 <_ZNSt6__ndk17codecvtIwc9mbstate_tEC1Em@plt>:
  134528:      	adrp	x16, 0x142000
  13452c:      	ldr	x17, [x16, #0x9a8]
  134530:      	add	x16, x16, #0x9a8
  134534:      	br	x17
  134538:      	nop
  13453c:      	nop

0000000000134540 <_ZNSt6__ndk18numpunctIcEC1Em@plt>:
  134540:      	adrp	x16, 0x142000
  134544:      	ldr	x17, [x16, #0x9b0]
  134548:      	add	x16, x16, #0x9b0
  13454c:      	br	x17
  134550:      	nop
  134554:      	nop

0000000000134558 <_ZNSt6__ndk18numpunctIwEC1Em@plt>:
  134558:      	adrp	x16, 0x142000
  13455c:      	ldr	x17, [x16, #0x9b8]
  134560:      	add	x16, x16, #0x9b8
  134564:      	br	x17
  134568:      	nop
  13456c:      	nop

0000000000134570 <_ZNSt6__ndk114collate_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  134570:      	adrp	x16, 0x142000
  134574:      	ldr	x17, [x16, #0x9c0]
  134578:      	add	x16, x16, #0x9c0
  13457c:      	br	x17
  134580:      	nop
  134584:      	nop

0000000000134588 <_ZNSt6__ndk114collate_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  134588:      	adrp	x16, 0x142000
  13458c:      	ldr	x17, [x16, #0x9c8]
  134590:      	add	x16, x16, #0x9c8
  134594:      	br	x17
  134598:      	nop
  13459c:      	nop

00000000001345a0 <_ZNSt6__ndk112ctype_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  1345a0:      	adrp	x16, 0x142000
  1345a4:      	ldr	x17, [x16, #0x9d0]
  1345a8:      	add	x16, x16, #0x9d0
  1345ac:      	br	x17
  1345b0:      	nop
  1345b4:      	nop

00000000001345b8 <_ZNSt6__ndk112ctype_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  1345b8:      	adrp	x16, 0x142000
  1345bc:      	ldr	x17, [x16, #0x9d8]
  1345c0:      	add	x16, x16, #0x9d8
  1345c4:      	br	x17
  1345c8:      	nop
  1345cc:      	nop

00000000001345d0 <_ZNSt6__ndk17codecvtIwc9mbstate_tEC2EPKcm@plt>:
  1345d0:      	adrp	x16, 0x142000
  1345d4:      	ldr	x17, [x16, #0x9e0]
  1345d8:      	add	x16, x16, #0x9e0
  1345dc:      	br	x17
  1345e0:      	nop
  1345e4:      	nop

00000000001345e8 <_ZNSt6__ndk115numpunct_bynameIcEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  1345e8:      	adrp	x16, 0x142000
  1345ec:      	ldr	x17, [x16, #0x9e8]
  1345f0:      	add	x16, x16, #0x9e8
  1345f4:      	br	x17
  1345f8:      	nop
  1345fc:      	nop

0000000000134600 <_ZNSt6__ndk115numpunct_bynameIwEC1ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  134600:      	adrp	x16, 0x142000
  134604:      	ldr	x17, [x16, #0x9f0]
  134608:      	add	x16, x16, #0x9f0
  13460c:      	br	x17
  134610:      	nop
  134614:      	nop

0000000000134618 <_ZNSt6__ndk118__time_get_storageIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
  134618:      	adrp	x16, 0x142000
  13461c:      	ldr	x17, [x16, #0x9f8]
  134620:      	add	x16, x16, #0x9f8
  134624:      	br	x17
  134628:      	nop
  13462c:      	nop

0000000000134630 <_ZNSt6__ndk118__time_get_storageIwEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE@plt>:
  134630:      	adrp	x16, 0x142000
  134634:      	ldr	x17, [x16, #0xa00]
  134638:      	add	x16, x16, #0xa00
  13463c:      	br	x17
  134640:      	nop
  134644:      	nop

0000000000134648 <_ZNSt6__ndk16locale7classicEv@plt>:
  134648:      	adrp	x16, 0x142000
  13464c:      	ldr	x17, [x16, #0xa08]
  134650:      	add	x16, x16, #0xa08
  134654:      	br	x17
  134658:      	nop
  13465c:      	nop

0000000000134660 <_ZNSt6__ndk117moneypunct_bynameIcLb0EE4initEPKc@plt>:
  134660:      	adrp	x16, 0x142000
  134664:      	ldr	x17, [x16, #0xa10]
  134668:      	add	x16, x16, #0xa10
  13466c:      	br	x17
  134670:      	nop
  134674:      	nop

0000000000134678 <_ZNSt6__ndk117moneypunct_bynameIcLb1EE4initEPKc@plt>:
  134678:      	adrp	x16, 0x142000
  13467c:      	ldr	x17, [x16, #0xa18]
  134680:      	add	x16, x16, #0xa18
  134684:      	br	x17
  134688:      	nop
  13468c:      	nop

0000000000134690 <_ZNSt6__ndk117moneypunct_bynameIwLb0EE4initEPKc@plt>:
  134690:      	adrp	x16, 0x142000
  134694:      	ldr	x17, [x16, #0xa20]
  134698:      	add	x16, x16, #0xa20
  13469c:      	br	x17
  1346a0:      	nop
  1346a4:      	nop

00000000001346a8 <_ZNSt6__ndk117moneypunct_bynameIwLb1EE4initEPKc@plt>:
  1346a8:      	adrp	x16, 0x142000
  1346ac:      	ldr	x17, [x16, #0xa28]
  1346b0:      	add	x16, x16, #0xa28
  1346b4:      	br	x17
  1346b8:      	nop
  1346bc:      	nop

00000000001346c0 <setlocale@plt>:
  1346c0:      	adrp	x16, 0x142000
  1346c4:      	ldr	x17, [x16, #0xa30]
  1346c8:      	add	x16, x16, #0xa30
  1346cc:      	br	x17
  1346d0:      	nop
  1346d4:      	nop

00000000001346d8 <_ZNSt6__ndk16locale5facetD1Ev@plt>:
  1346d8:      	adrp	x16, 0x142000
  1346dc:      	ldr	x17, [x16, #0xa38]
  1346e0:      	add	x16, x16, #0xa38
  1346e4:      	br	x17
  1346e8:      	nop
  1346ec:      	nop

00000000001346f0 <freelocale@plt>:
  1346f0:      	adrp	x16, 0x142000
  1346f4:      	ldr	x17, [x16, #0xa40]
  1346f8:      	add	x16, x16, #0xa40
  1346fc:      	br	x17
  134700:      	nop
  134704:      	nop

0000000000134708 <_ZNSt6__ndk114collate_bynameIcED1Ev@plt>:
  134708:      	adrp	x16, 0x142000
  13470c:      	ldr	x17, [x16, #0xa48]
  134710:      	add	x16, x16, #0xa48
  134714:      	br	x17
  134718:      	nop
  13471c:      	nop

0000000000134720 <strcoll_l@plt>:
  134720:      	adrp	x16, 0x142000
  134724:      	ldr	x17, [x16, #0xa50]
  134728:      	add	x16, x16, #0xa50
  13472c:      	br	x17
  134730:      	nop
  134734:      	nop

0000000000134738 <strxfrm_l@plt>:
  134738:      	adrp	x16, 0x142000
  13473c:      	ldr	x17, [x16, #0xa58]
  134740:      	add	x16, x16, #0xa58
  134744:      	br	x17
  134748:      	nop
  13474c:      	nop

0000000000134750 <_ZNSt6__ndk114collate_bynameIwED1Ev@plt>:
  134750:      	adrp	x16, 0x142000
  134754:      	ldr	x17, [x16, #0xa60]
  134758:      	add	x16, x16, #0xa60
  13475c:      	br	x17
  134760:      	nop
  134764:      	nop

0000000000134768 <wcscoll_l@plt>:
  134768:      	adrp	x16, 0x142000
  13476c:      	ldr	x17, [x16, #0xa68]
  134770:      	add	x16, x16, #0xa68
  134774:      	br	x17
  134778:      	nop
  13477c:      	nop

0000000000134780 <wcsxfrm_l@plt>:
  134780:      	adrp	x16, 0x142000
  134784:      	ldr	x17, [x16, #0xa70]
  134788:      	add	x16, x16, #0xa70
  13478c:      	br	x17
  134790:      	nop
  134794:      	nop

0000000000134798 <_ZNSt6__ndk15ctypeIwED1Ev@plt>:
  134798:      	adrp	x16, 0x142000
  13479c:      	ldr	x17, [x16, #0xa78]
  1347a0:      	add	x16, x16, #0xa78
  1347a4:      	br	x17
  1347a8:      	nop
  1347ac:      	nop

00000000001347b0 <iswlower_l@plt>:
  1347b0:      	adrp	x16, 0x142000
  1347b4:      	ldr	x17, [x16, #0xa80]
  1347b8:      	add	x16, x16, #0xa80
  1347bc:      	br	x17
  1347c0:      	nop
  1347c4:      	nop

00000000001347c8 <_ZNSt6__ndk15ctypeIcED2Ev@plt>:
  1347c8:      	adrp	x16, 0x142000
  1347cc:      	ldr	x17, [x16, #0xa88]
  1347d0:      	add	x16, x16, #0xa88
  1347d4:      	br	x17
  1347d8:      	nop
  1347dc:      	nop

00000000001347e0 <_ZNSt6__ndk15ctypeIcED1Ev@plt>:
  1347e0:      	adrp	x16, 0x142000
  1347e4:      	ldr	x17, [x16, #0xa90]
  1347e8:      	add	x16, x16, #0xa90
  1347ec:      	br	x17
  1347f0:      	nop
  1347f4:      	nop

00000000001347f8 <_ZNSt6__ndk112ctype_bynameIcEC2EPKcm@plt>:
  1347f8:      	adrp	x16, 0x142000
  1347fc:      	ldr	x17, [x16, #0xa98]
  134800:      	add	x16, x16, #0xa98
  134804:      	br	x17
  134808:      	nop
  13480c:      	nop

0000000000134810 <_ZNSt6__ndk112ctype_bynameIcEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  134810:      	adrp	x16, 0x142000
  134814:      	ldr	x17, [x16, #0xaa0]
  134818:      	add	x16, x16, #0xaa0
  13481c:      	br	x17
  134820:      	nop
  134824:      	nop

0000000000134828 <_ZNSt6__ndk112ctype_bynameIcED1Ev@plt>:
  134828:      	adrp	x16, 0x142000
  13482c:      	ldr	x17, [x16, #0xaa8]
  134830:      	add	x16, x16, #0xaa8
  134834:      	br	x17
  134838:      	nop
  13483c:      	nop

0000000000134840 <_ZNSt6__ndk112ctype_bynameIwEC2EPKcm@plt>:
  134840:      	adrp	x16, 0x142000
  134844:      	ldr	x17, [x16, #0xab0]
  134848:      	add	x16, x16, #0xab0
  13484c:      	br	x17
  134850:      	nop
  134854:      	nop

0000000000134858 <_ZNSt6__ndk15ctypeIwED2Ev@plt>:
  134858:      	adrp	x16, 0x142000
  13485c:      	ldr	x17, [x16, #0xab8]
  134860:      	add	x16, x16, #0xab8
  134864:      	br	x17
  134868:      	nop
  13486c:      	nop

0000000000134870 <_ZNSt6__ndk112ctype_bynameIwEC2ERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEm@plt>:
  134870:      	adrp	x16, 0x142000
  134874:      	ldr	x17, [x16, #0xac0]
  134878:      	add	x16, x16, #0xac0
  13487c:      	br	x17
  134880:      	nop
  134884:      	nop

0000000000134888 <_ZNSt6__ndk112ctype_bynameIwED1Ev@plt>:
  134888:      	adrp	x16, 0x142000
  13488c:      	ldr	x17, [x16, #0xac8]
  134890:      	add	x16, x16, #0xac8
  134894:      	br	x17
  134898:      	nop
  13489c:      	nop

00000000001348a0 <iswspace_l@plt>:
  1348a0:      	adrp	x16, 0x142000
  1348a4:      	ldr	x17, [x16, #0xad0]
  1348a8:      	add	x16, x16, #0xad0
  1348ac:      	br	x17
  1348b0:      	nop
  1348b4:      	nop

00000000001348b8 <iswprint_l@plt>:
  1348b8:      	adrp	x16, 0x142000
  1348bc:      	ldr	x17, [x16, #0xad8]
  1348c0:      	add	x16, x16, #0xad8
  1348c4:      	br	x17
  1348c8:      	nop
  1348cc:      	nop

00000000001348d0 <iswcntrl_l@plt>:
  1348d0:      	adrp	x16, 0x142000
  1348d4:      	ldr	x17, [x16, #0xae0]
  1348d8:      	add	x16, x16, #0xae0
  1348dc:      	br	x17
  1348e0:      	nop
  1348e4:      	nop

00000000001348e8 <iswupper_l@plt>:
  1348e8:      	adrp	x16, 0x142000
  1348ec:      	ldr	x17, [x16, #0xae8]
  1348f0:      	add	x16, x16, #0xae8
  1348f4:      	br	x17
  1348f8:      	nop
  1348fc:      	nop

0000000000134900 <iswalpha_l@plt>:
  134900:      	adrp	x16, 0x142000
  134904:      	ldr	x17, [x16, #0xaf0]
  134908:      	add	x16, x16, #0xaf0
  13490c:      	br	x17
  134910:      	nop
  134914:      	nop

0000000000134918 <iswdigit_l@plt>:
  134918:      	adrp	x16, 0x142000
  13491c:      	ldr	x17, [x16, #0xaf8]
  134920:      	add	x16, x16, #0xaf8
  134924:      	br	x17
  134928:      	nop
  13492c:      	nop

0000000000134930 <iswpunct_l@plt>:
  134930:      	adrp	x16, 0x142000
  134934:      	ldr	x17, [x16, #0xb00]
  134938:      	add	x16, x16, #0xb00
  13493c:      	br	x17
  134940:      	nop
  134944:      	nop

0000000000134948 <iswxdigit_l@plt>:
  134948:      	adrp	x16, 0x142000
  13494c:      	ldr	x17, [x16, #0xb08]
  134950:      	add	x16, x16, #0xb08
  134954:      	br	x17
  134958:      	nop
  13495c:      	nop

0000000000134960 <iswblank_l@plt>:
  134960:      	adrp	x16, 0x142000
  134964:      	ldr	x17, [x16, #0xb10]
  134968:      	add	x16, x16, #0xb10
  13496c:      	br	x17
  134970:      	nop
  134974:      	nop

0000000000134978 <towupper_l@plt>:
  134978:      	adrp	x16, 0x142000
  13497c:      	ldr	x17, [x16, #0xb18]
  134980:      	add	x16, x16, #0xb18
  134984:      	br	x17
  134988:      	nop
  13498c:      	nop

0000000000134990 <towlower_l@plt>:
  134990:      	adrp	x16, 0x142000
  134994:      	ldr	x17, [x16, #0xb20]
  134998:      	add	x16, x16, #0xb20
  13499c:      	br	x17
  1349a0:      	nop
  1349a4:      	nop

00000000001349a8 <btowc@plt>:
  1349a8:      	adrp	x16, 0x142000
  1349ac:      	ldr	x17, [x16, #0xb28]
  1349b0:      	add	x16, x16, #0xb28
  1349b4:      	br	x17
  1349b8:      	nop
  1349bc:      	nop

00000000001349c0 <wctob@plt>:
  1349c0:      	adrp	x16, 0x142000
  1349c4:      	ldr	x17, [x16, #0xb30]
  1349c8:      	add	x16, x16, #0xb30
  1349cc:      	br	x17
  1349d0:      	nop
  1349d4:      	nop

00000000001349d8 <_ZNSt6__ndk17codecvtIcc9mbstate_tED1Ev@plt>:
  1349d8:      	adrp	x16, 0x142000
  1349dc:      	ldr	x17, [x16, #0xb38]
  1349e0:      	add	x16, x16, #0xb38
  1349e4:      	br	x17
  1349e8:      	nop
  1349ec:      	nop

00000000001349f0 <_ZNSt6__ndk17codecvtIwc9mbstate_tED1Ev@plt>:
  1349f0:      	adrp	x16, 0x142000
  1349f4:      	ldr	x17, [x16, #0xb40]
  1349f8:      	add	x16, x16, #0xb40
  1349fc:      	br	x17
  134a00:      	nop
  134a04:      	nop

0000000000134a08 <wcsnrtombs@plt>:
  134a08:      	adrp	x16, 0x142000
  134a0c:      	ldr	x17, [x16, #0xb48]
  134a10:      	add	x16, x16, #0xb48
  134a14:      	br	x17
  134a18:      	nop
  134a1c:      	nop

0000000000134a20 <wcrtomb@plt>:
  134a20:      	adrp	x16, 0x142000
  134a24:      	ldr	x17, [x16, #0xb50]
  134a28:      	add	x16, x16, #0xb50
  134a2c:      	br	x17
  134a30:      	nop
  134a34:      	nop

0000000000134a38 <mbsnrtowcs@plt>:
  134a38:      	adrp	x16, 0x142000
  134a3c:      	ldr	x17, [x16, #0xb58]
  134a40:      	add	x16, x16, #0xb58
  134a44:      	br	x17
  134a48:      	nop
  134a4c:      	nop

0000000000134a50 <mbrtowc@plt>:
  134a50:      	adrp	x16, 0x142000
  134a54:      	ldr	x17, [x16, #0xb60]
  134a58:      	add	x16, x16, #0xb60
  134a5c:      	br	x17
  134a60:      	nop
  134a64:      	nop

0000000000134a68 <mbtowc@plt>:
  134a68:      	adrp	x16, 0x142000
  134a6c:      	ldr	x17, [x16, #0xb68]
  134a70:      	add	x16, x16, #0xb68
  134a74:      	br	x17
  134a78:      	nop
  134a7c:      	nop

0000000000134a80 <__ctype_get_mb_cur_max@plt>:
  134a80:      	adrp	x16, 0x142000
  134a84:      	ldr	x17, [x16, #0xb70]
  134a88:      	add	x16, x16, #0xb70
  134a8c:      	br	x17
  134a90:      	nop
  134a94:      	nop

0000000000134a98 <mbrlen@plt>:
  134a98:      	adrp	x16, 0x142000
  134a9c:      	ldr	x17, [x16, #0xb78]
  134aa0:      	add	x16, x16, #0xb78
  134aa4:      	br	x17
  134aa8:      	nop
  134aac:      	nop

0000000000134ab0 <_ZNSt6__ndk17codecvtIDsc9mbstate_tED1Ev@plt>:
  134ab0:      	adrp	x16, 0x142000
  134ab4:      	ldr	x17, [x16, #0xb80]
  134ab8:      	add	x16, x16, #0xb80
  134abc:      	br	x17
  134ac0:      	nop
  134ac4:      	nop

0000000000134ac8 <_ZNSt6__ndk17codecvtIDsDu9mbstate_tED1Ev@plt>:
  134ac8:      	adrp	x16, 0x142000
  134acc:      	ldr	x17, [x16, #0xb88]
  134ad0:      	add	x16, x16, #0xb88
  134ad4:      	br	x17
  134ad8:      	nop
  134adc:      	nop

0000000000134ae0 <_ZNSt6__ndk17codecvtIDic9mbstate_tED1Ev@plt>:
  134ae0:      	adrp	x16, 0x142000
  134ae4:      	ldr	x17, [x16, #0xb90]
  134ae8:      	add	x16, x16, #0xb90
  134aec:      	br	x17
  134af0:      	nop
  134af4:      	nop

0000000000134af8 <_ZNSt6__ndk17codecvtIDiDu9mbstate_tED1Ev@plt>:
  134af8:      	adrp	x16, 0x142000
  134afc:      	ldr	x17, [x16, #0xb98]
  134b00:      	add	x16, x16, #0xb98
  134b04:      	br	x17
  134b08:      	nop
  134b0c:      	nop

0000000000134b10 <_ZNSt6__ndk116__narrow_to_utf8ILm16EED1Ev@plt>:
  134b10:      	adrp	x16, 0x142000
  134b14:      	ldr	x17, [x16, #0xba0]
  134b18:      	add	x16, x16, #0xba0
  134b1c:      	br	x17
  134b20:      	nop
  134b24:      	nop

0000000000134b28 <_ZNSt6__ndk116__narrow_to_utf8ILm32EED1Ev@plt>:
  134b28:      	adrp	x16, 0x142000
  134b2c:      	ldr	x17, [x16, #0xba8]
  134b30:      	add	x16, x16, #0xba8
  134b34:      	br	x17
  134b38:      	nop
  134b3c:      	nop

0000000000134b40 <_ZNSt6__ndk117__widen_from_utf8ILm16EED1Ev@plt>:
  134b40:      	adrp	x16, 0x142000
  134b44:      	ldr	x17, [x16, #0xbb0]
  134b48:      	add	x16, x16, #0xbb0
  134b4c:      	br	x17
  134b50:      	nop
  134b54:      	nop

0000000000134b58 <_ZNSt6__ndk117__widen_from_utf8ILm32EED1Ev@plt>:
  134b58:      	adrp	x16, 0x142000
  134b5c:      	ldr	x17, [x16, #0xbb8]
  134b60:      	add	x16, x16, #0xbb8
  134b64:      	br	x17
  134b68:      	nop
  134b6c:      	nop

0000000000134b70 <_ZNSt6__ndk18numpunctIcED2Ev@plt>:
  134b70:      	adrp	x16, 0x142000
  134b74:      	ldr	x17, [x16, #0xbc0]
  134b78:      	add	x16, x16, #0xbc0
  134b7c:      	br	x17
  134b80:      	nop
  134b84:      	nop

0000000000134b88 <_ZNSt6__ndk18numpunctIcED1Ev@plt>:
  134b88:      	adrp	x16, 0x142000
  134b8c:      	ldr	x17, [x16, #0xbc8]
  134b90:      	add	x16, x16, #0xbc8
  134b94:      	br	x17
  134b98:      	nop
  134b9c:      	nop

0000000000134ba0 <_ZNSt6__ndk18numpunctIwED2Ev@plt>:
  134ba0:      	adrp	x16, 0x142000
  134ba4:      	ldr	x17, [x16, #0xbd0]
  134ba8:      	add	x16, x16, #0xbd0
  134bac:      	br	x17
  134bb0:      	nop
  134bb4:      	nop

0000000000134bb8 <_ZNSt6__ndk18numpunctIwED1Ev@plt>:
  134bb8:      	adrp	x16, 0x142000
  134bbc:      	ldr	x17, [x16, #0xbd8]
  134bc0:      	add	x16, x16, #0xbd8
  134bc4:      	br	x17
  134bc8:      	nop
  134bcc:      	nop

0000000000134bd0 <_ZNSt6__ndk115numpunct_bynameIcE6__initEPKc@plt>:
  134bd0:      	adrp	x16, 0x142000
  134bd4:      	ldr	x17, [x16, #0xbe0]
  134bd8:      	add	x16, x16, #0xbe0
  134bdc:      	br	x17
  134be0:      	nop
  134be4:      	nop

0000000000134be8 <localeconv@plt>:
  134be8:      	adrp	x16, 0x142000
  134bec:      	ldr	x17, [x16, #0xbe8]
  134bf0:      	add	x16, x16, #0xbe8
  134bf4:      	br	x17
  134bf8:      	nop
  134bfc:      	nop

0000000000134c00 <_ZNSt6__ndk115numpunct_bynameIcED1Ev@plt>:
  134c00:      	adrp	x16, 0x142000
  134c04:      	ldr	x17, [x16, #0xbf0]
  134c08:      	add	x16, x16, #0xbf0
  134c0c:      	br	x17
  134c10:      	nop
  134c14:      	nop

0000000000134c18 <_ZNSt6__ndk115numpunct_bynameIwE6__initEPKc@plt>:
  134c18:      	adrp	x16, 0x142000
  134c1c:      	ldr	x17, [x16, #0xbf8]
  134c20:      	add	x16, x16, #0xbf8
  134c24:      	br	x17
  134c28:      	nop
  134c2c:      	nop

0000000000134c30 <_ZNSt6__ndk115numpunct_bynameIwED1Ev@plt>:
  134c30:      	adrp	x16, 0x142000
  134c34:      	ldr	x17, [x16, #0xc00]
  134c38:      	add	x16, x16, #0xc00
  134c3c:      	br	x17
  134c40:      	nop
  134c44:      	nop

0000000000134c48 <_ZNSt6__ndk110__time_getC2EPKc@plt>:
  134c48:      	adrp	x16, 0x142000
  134c4c:      	ldr	x17, [x16, #0xc08]
  134c50:      	add	x16, x16, #0xc08
  134c54:      	br	x17
  134c58:      	nop
  134c5c:      	nop

0000000000134c60 <_ZNSt6__ndk110__time_getD2Ev@plt>:
  134c60:      	adrp	x16, 0x142000
  134c64:      	ldr	x17, [x16, #0xc10]
  134c68:      	add	x16, x16, #0xc10
  134c6c:      	br	x17
  134c70:      	nop
  134c74:      	nop

0000000000134c78 <_ZNSt6__ndk118__time_get_storageIcE9__analyzeEcRKNS_5ctypeIcEE@plt>:
  134c78:      	adrp	x16, 0x142000
  134c7c:      	ldr	x17, [x16, #0xc18]
  134c80:      	add	x16, x16, #0xc18
  134c84:      	br	x17
  134c88:      	nop
  134c8c:      	nop

0000000000134c90 <_ZNSt6__ndk118__time_get_storageIwE9__analyzeEcRKNS_5ctypeIwEE@plt>:
  134c90:      	adrp	x16, 0x142000
  134c94:      	ldr	x17, [x16, #0xc20]
  134c98:      	add	x16, x16, #0xc20
  134c9c:      	br	x17
  134ca0:      	nop
  134ca4:      	nop

0000000000134ca8 <_ZNSt6__ndk118__time_get_storageIcE4initERKNS_5ctypeIcEE@plt>:
  134ca8:      	adrp	x16, 0x142000
  134cac:      	ldr	x17, [x16, #0xc28]
  134cb0:      	add	x16, x16, #0xc28
  134cb4:      	br	x17
  134cb8:      	nop
  134cbc:      	nop

0000000000134cc0 <_ZNSt6__ndk118__time_get_storageIwE4initERKNS_5ctypeIwEE@plt>:
  134cc0:      	adrp	x16, 0x142000
  134cc4:      	ldr	x17, [x16, #0xc30]
  134cc8:      	add	x16, x16, #0xc30
  134ccc:      	br	x17
  134cd0:      	nop
  134cd4:      	nop

0000000000134cd8 <_ZNSt6__ndk112ctype_bynameIcED2Ev@plt>:
  134cd8:      	adrp	x16, 0x142000
  134cdc:      	ldr	x17, [x16, #0xc38]
  134ce0:      	add	x16, x16, #0xc38
  134ce4:      	br	x17
  134ce8:      	nop
  134cec:      	nop

0000000000134cf0 <_ZNSt6__ndk112ctype_bynameIwED2Ev@plt>:
  134cf0:      	adrp	x16, 0x142000
  134cf4:      	ldr	x17, [x16, #0xc40]
  134cf8:      	add	x16, x16, #0xc40
  134cfc:      	br	x17
  134d00:      	nop
  134d04:      	nop

0000000000134d08 <_ZNKSt6__ndk118__time_get_storageIcE15__do_date_orderEv@plt>:
  134d08:      	adrp	x16, 0x142000
  134d0c:      	ldr	x17, [x16, #0xc48]
  134d10:      	add	x16, x16, #0xc48
  134d14:      	br	x17
  134d18:      	nop
  134d1c:      	nop

0000000000134d20 <_ZNKSt6__ndk118__time_get_storageIwE15__do_date_orderEv@plt>:
  134d20:      	adrp	x16, 0x142000
  134d24:      	ldr	x17, [x16, #0xc50]
  134d28:      	add	x16, x16, #0xc50
  134d2c:      	br	x17
  134d30:      	nop
  134d34:      	nop

0000000000134d38 <_ZNSt6__ndk110__time_putD2Ev@plt>:
  134d38:      	adrp	x16, 0x142000
  134d3c:      	ldr	x17, [x16, #0xc58]
  134d40:      	add	x16, x16, #0xc58
  134d44:      	br	x17
  134d48:      	nop
  134d4c:      	nop

0000000000134d50 <strtoll_l@plt>:
  134d50:      	adrp	x16, 0x142000
  134d54:      	ldr	x17, [x16, #0xc60]
  134d58:      	add	x16, x16, #0xc60
  134d5c:      	br	x17
  134d60:      	nop
  134d64:      	nop

0000000000134d68 <strtoull_l@plt>:
  134d68:      	adrp	x16, 0x142000
  134d6c:      	ldr	x17, [x16, #0xc68]
  134d70:      	add	x16, x16, #0xc68
  134d74:      	br	x17
  134d78:      	nop
  134d7c:      	nop

0000000000134d80 <strtold_l@plt>:
  134d80:      	adrp	x16, 0x142000
  134d84:      	ldr	x17, [x16, #0xc70]
  134d88:      	add	x16, x16, #0xc70
  134d8c:      	br	x17
  134d90:      	nop
  134d94:      	nop

0000000000134d98 <_ZNSt6__ndk111regex_errorD1Ev@plt>:
  134d98:      	adrp	x16, 0x142000
  134d9c:      	ldr	x17, [x16, #0xc78]
  134da0:      	add	x16, x16, #0xc78
  134da4:      	br	x17
  134da8:      	nop
  134dac:      	nop

0000000000134db0 <_ZNSt6__ndk112strstreambufD1Ev@plt>:
  134db0:      	adrp	x16, 0x142000
  134db4:      	ldr	x17, [x16, #0xc80]
  134db8:      	add	x16, x16, #0xc80
  134dbc:      	br	x17
  134dc0:      	nop
  134dc4:      	nop

0000000000134dc8 <lstat@plt>:
  134dc8:      	adrp	x16, 0x142000
  134dcc:      	ldr	x17, [x16, #0xc88]
  134dd0:      	add	x16, x16, #0xc88
  134dd4:      	br	x17
  134dd8:      	nop
  134ddc:      	nop

0000000000134de0 <stat@plt>:
  134de0:      	adrp	x16, 0x142000
  134de4:      	ldr	x17, [x16, #0xc90]
  134de8:      	add	x16, x16, #0xc90
  134dec:      	br	x17
  134df0:      	nop
  134df4:      	nop

0000000000134df8 <_ZNSt6__ndk14__fs10filesystem18directory_iteratorC2ERKNS1_4pathEPNS_10error_codeENS1_17directory_optionsE@plt>:
  134df8:      	adrp	x16, 0x142000
  134dfc:      	ldr	x17, [x16, #0xc98]
  134e00:      	add	x16, x16, #0xc98
  134e04:      	br	x17
  134e08:      	nop
  134e0c:      	nop

0000000000134e10 <_ZNSt6__ndk14__fs10filesystem18directory_iterator11__incrementEPNS_10error_codeE@plt>:
  134e10:      	adrp	x16, 0x142000
  134e14:      	ldr	x17, [x16, #0xca0]
  134e18:      	add	x16, x16, #0xca0
  134e1c:      	br	x17
  134e20:      	nop
  134e24:      	nop

0000000000134e28 <readdir@plt>:
  134e28:      	adrp	x16, 0x142000
  134e2c:      	ldr	x17, [x16, #0xca8]
  134e30:      	add	x16, x16, #0xca8
  134e34:      	br	x17
  134e38:      	nop
  134e3c:      	nop

0000000000134e40 <closedir@plt>:
  134e40:      	adrp	x16, 0x142000
  134e44:      	ldr	x17, [x16, #0xcb0]
  134e48:      	add	x16, x16, #0xcb0
  134e4c:      	br	x17
  134e50:      	nop
  134e54:      	nop

0000000000134e58 <_ZNKSt6__ndk14__fs10filesystem18directory_iterator13__dereferenceEv@plt>:
  134e58:      	adrp	x16, 0x142000
  134e5c:      	ldr	x17, [x16, #0xcb8]
  134e60:      	add	x16, x16, #0xcb8
  134e64:      	br	x17
  134e68:      	nop
  134e6c:      	nop

0000000000134e70 <opendir@plt>:
  134e70:      	adrp	x16, 0x142000
  134e74:      	ldr	x17, [x16, #0xcc0]
  134e78:      	add	x16, x16, #0xcc0
  134e7c:      	br	x17
  134e80:      	nop
  134e84:      	nop

0000000000134e88 <_ZNSt6__ndk14__fs10filesystem28recursive_directory_iterator9__advanceEPNS_10error_codeE@plt>:
  134e88:      	adrp	x16, 0x142000
  134e8c:      	ldr	x17, [x16, #0xcc8]
  134e90:      	add	x16, x16, #0xcc8
  134e94:      	br	x17
  134e98:      	nop
  134e9c:      	nop

0000000000134ea0 <_ZNSt6__ndk14__fs10filesystem28recursive_directory_iterator15__try_recursionEPNS_10error_codeE@plt>:
  134ea0:      	adrp	x16, 0x142000
  134ea4:      	ldr	x17, [x16, #0xcd0]
  134ea8:      	add	x16, x16, #0xcd0
  134eac:      	br	x17
  134eb0:      	nop
  134eb4:      	nop

0000000000134eb8 <_ZNSt6__ndk14__fs10filesystem8__statusERKNS1_4pathEPNS_10error_codeE@plt>:
  134eb8:      	adrp	x16, 0x142000
  134ebc:      	ldr	x17, [x16, #0xcd8]
  134ec0:      	add	x16, x16, #0xcd8
  134ec4:      	br	x17
  134ec8:      	nop
  134ecc:      	nop

0000000000134ed0 <_ZNSt6__ndk14__fs10filesystem16__symlink_statusERKNS1_4pathEPNS_10error_codeE@plt>:
  134ed0:      	adrp	x16, 0x142000
  134ed4:      	ldr	x17, [x16, #0xce0]
  134ed8:      	add	x16, x16, #0xce0
  134edc:      	br	x17
  134ee0:      	nop
  134ee4:      	nop

0000000000134ee8 <_ZNSt6__ndk14__fs10filesystem14__current_pathEPNS_10error_codeE@plt>:
  134ee8:      	adrp	x16, 0x142000
  134eec:      	ldr	x17, [x16, #0xce8]
  134ef0:      	add	x16, x16, #0xce8
  134ef4:      	br	x17
  134ef8:      	nop
  134efc:      	nop

0000000000134f00 <_ZNSt6__ndk14__fs10filesystem11__canonicalERKNS1_4pathEPNS_10error_codeE@plt>:
  134f00:      	adrp	x16, 0x142000
  134f04:      	ldr	x17, [x16, #0xcf0]
  134f08:      	add	x16, x16, #0xcf0
  134f0c:      	br	x17
  134f10:      	nop
  134f14:      	nop

0000000000134f18 <realpath@plt>:
  134f18:      	adrp	x16, 0x142000
  134f1c:      	ldr	x17, [x16, #0xcf8]
  134f20:      	add	x16, x16, #0xcf8
  134f24:      	br	x17
  134f28:      	nop
  134f2c:      	nop

0000000000134f30 <_ZNSt6__ndk14__fs10filesystem6__copyERKNS1_4pathES4_NS1_12copy_optionsEPNS_10error_codeE@plt>:
  134f30:      	adrp	x16, 0x142000
  134f34:      	ldr	x17, [x16, #0xd00]
  134f38:      	add	x16, x16, #0xd00
  134f3c:      	br	x17
  134f40:      	nop
  134f44:      	nop

0000000000134f48 <_ZNSt6__ndk14__fs10filesystem14__copy_symlinkERKNS1_4pathES4_PNS_10error_codeE@plt>:
  134f48:      	adrp	x16, 0x142000
  134f4c:      	ldr	x17, [x16, #0xd08]
  134f50:      	add	x16, x16, #0xd08
  134f54:      	br	x17
  134f58:      	nop
  134f5c:      	nop

0000000000134f60 <_ZNSt6__ndk14__fs10filesystem18__create_directoryERKNS1_4pathES4_PNS_10error_codeE@plt>:
  134f60:      	adrp	x16, 0x142000
  134f64:      	ldr	x17, [x16, #0xd10]
  134f68:      	add	x16, x16, #0xd10
  134f6c:      	br	x17
  134f70:      	nop
  134f74:      	nop

0000000000134f78 <_ZNSt6__ndk14__fs10filesystem11__copy_fileERKNS1_4pathES4_NS1_12copy_optionsEPNS_10error_codeE@plt>:
  134f78:      	adrp	x16, 0x142000
  134f7c:      	ldr	x17, [x16, #0xd18]
  134f80:      	add	x16, x16, #0xd18
  134f84:      	br	x17
  134f88:      	nop
  134f8c:      	nop

0000000000134f90 <_ZNSt6__ndk14__fs10filesystem16__create_symlinkERKNS1_4pathES4_PNS_10error_codeE@plt>:
  134f90:      	adrp	x16, 0x142000
  134f94:      	ldr	x17, [x16, #0xd20]
  134f98:      	add	x16, x16, #0xd20
  134f9c:      	br	x17
  134fa0:      	nop
  134fa4:      	nop

0000000000134fa8 <_ZNSt6__ndk14__fs10filesystem18__create_hard_linkERKNS1_4pathES4_PNS_10error_codeE@plt>:
  134fa8:      	adrp	x16, 0x142000
  134fac:      	ldr	x17, [x16, #0xd28]
  134fb0:      	add	x16, x16, #0xd28
  134fb4:      	br	x17
  134fb8:      	nop
  134fbc:      	nop

0000000000134fc0 <_ZNSt6__ndk14__fs10filesystem14__read_symlinkERKNS1_4pathEPNS_10error_codeE@plt>:
  134fc0:      	adrp	x16, 0x142000
  134fc4:      	ldr	x17, [x16, #0xd30]
  134fc8:      	add	x16, x16, #0xd30
  134fcc:      	br	x17
  134fd0:      	nop
  134fd4:      	nop

0000000000134fd8 <symlink@plt>:
  134fd8:      	adrp	x16, 0x142000
  134fdc:      	ldr	x17, [x16, #0xd38]
  134fe0:      	add	x16, x16, #0xd38
  134fe4:      	br	x17
  134fe8:      	nop
  134fec:      	nop

0000000000134ff0 <link@plt>:
  134ff0:      	adrp	x16, 0x142000
  134ff4:      	ldr	x17, [x16, #0xd40]
  134ff8:      	add	x16, x16, #0xd40
  134ffc:      	br	x17
  135000:      	nop
  135004:      	nop

0000000000135008 <mkdir@plt>:
  135008:      	adrp	x16, 0x142000
  13500c:      	ldr	x17, [x16, #0xd48]
  135010:      	add	x16, x16, #0xd48
  135014:      	br	x17
  135018:      	nop
  13501c:      	nop

0000000000135020 <fchmod@plt>:
  135020:      	adrp	x16, 0x142000
  135024:      	ldr	x17, [x16, #0xd50]
  135028:      	add	x16, x16, #0xd50
  13502c:      	br	x17
  135030:      	nop
  135034:      	nop

0000000000135038 <ftruncate@plt>:
  135038:      	adrp	x16, 0x142000
  13503c:      	ldr	x17, [x16, #0xd58]
  135040:      	add	x16, x16, #0xd58
  135044:      	br	x17
  135048:      	nop
  13504c:      	nop

0000000000135050 <sendfile@plt>:
  135050:      	adrp	x16, 0x142000
  135054:      	ldr	x17, [x16, #0xd60]
  135058:      	add	x16, x16, #0xd60
  13505c:      	br	x17
  135060:      	nop
  135064:      	nop

0000000000135068 <readlink@plt>:
  135068:      	adrp	x16, 0x142000
  13506c:      	ldr	x17, [x16, #0xd68]
  135070:      	add	x16, x16, #0xd68
  135074:      	br	x17
  135078:      	nop
  13507c:      	nop

0000000000135080 <_ZNSt6__ndk14__fs10filesystem20__create_directoriesERKNS1_4pathEPNS_10error_codeE@plt>:
  135080:      	adrp	x16, 0x142000
  135084:      	ldr	x17, [x16, #0xd70]
  135088:      	add	x16, x16, #0xd70
  13508c:      	br	x17
  135090:      	nop
  135094:      	nop

0000000000135098 <_ZNSt6__ndk14__fs10filesystem18__create_directoryERKNS1_4pathEPNS_10error_codeE@plt>:
  135098:      	adrp	x16, 0x142000
  13509c:      	ldr	x17, [x16, #0xd78]
  1350a0:      	add	x16, x16, #0xd78
  1350a4:      	br	x17
  1350a8:      	nop
  1350ac:      	nop

00000000001350b0 <pathconf@plt>:
  1350b0:      	adrp	x16, 0x142000
  1350b4:      	ldr	x17, [x16, #0xd80]
  1350b8:      	add	x16, x16, #0xd80
  1350bc:      	br	x17
  1350c0:      	nop
  1350c4:      	nop

00000000001350c8 <getcwd@plt>:
  1350c8:      	adrp	x16, 0x142000
  1350cc:      	ldr	x17, [x16, #0xd88]
  1350d0:      	add	x16, x16, #0xd88
  1350d4:      	br	x17
  1350d8:      	nop
  1350dc:      	nop

00000000001350e0 <chdir@plt>:
  1350e0:      	adrp	x16, 0x142000
  1350e4:      	ldr	x17, [x16, #0xd90]
  1350e8:      	add	x16, x16, #0xd90
  1350ec:      	br	x17
  1350f0:      	nop
  1350f4:      	nop

00000000001350f8 <utimensat@plt>:
  1350f8:      	adrp	x16, 0x142000
  1350fc:      	ldr	x17, [x16, #0xd98]
  135100:      	add	x16, x16, #0xd98
  135104:      	br	x17
  135108:      	nop
  13510c:      	nop

0000000000135110 <fchmodat@plt>:
  135110:      	adrp	x16, 0x142000
  135114:      	ldr	x17, [x16, #0xda0]
  135118:      	add	x16, x16, #0xda0
  13511c:      	br	x17
  135120:      	nop
  135124:      	nop

0000000000135128 <remove@plt>:
  135128:      	adrp	x16, 0x142000
  13512c:      	ldr	x17, [x16, #0xda8]
  135130:      	add	x16, x16, #0xda8
  135134:      	br	x17
  135138:      	nop
  13513c:      	nop

0000000000135140 <openat@plt>:
  135140:      	adrp	x16, 0x142000
  135144:      	ldr	x17, [x16, #0xdb0]
  135148:      	add	x16, x16, #0xdb0
  13514c:      	br	x17
  135150:      	nop
  135154:      	nop

0000000000135158 <fdopendir@plt>:
  135158:      	adrp	x16, 0x142000
  13515c:      	ldr	x17, [x16, #0xdb8]
  135160:      	add	x16, x16, #0xdb8
  135164:      	br	x17
  135168:      	nop
  13516c:      	nop

0000000000135170 <unlinkat@plt>:
  135170:      	adrp	x16, 0x142000
  135174:      	ldr	x17, [x16, #0xdc0]
  135178:      	add	x16, x16, #0xdc0
  13517c:      	br	x17
  135180:      	nop
  135184:      	nop

0000000000135188 <rename@plt>:
  135188:      	adrp	x16, 0x142000
  13518c:      	ldr	x17, [x16, #0xdc8]
  135190:      	add	x16, x16, #0xdc8
  135194:      	br	x17
  135198:      	nop
  13519c:      	nop

00000000001351a0 <truncate@plt>:
  1351a0:      	adrp	x16, 0x142000
  1351a4:      	ldr	x17, [x16, #0xdd0]
  1351a8:      	add	x16, x16, #0xdd0
  1351ac:      	br	x17
  1351b0:      	nop
  1351b4:      	nop

00000000001351b8 <statvfs@plt>:
  1351b8:      	adrp	x16, 0x142000
  1351bc:      	ldr	x17, [x16, #0xdd8]
  1351c0:      	add	x16, x16, #0xdd8
  1351c4:      	br	x17
  1351c8:      	nop
  1351cc:      	nop

00000000001351d0 <getenv@plt>:
  1351d0:      	adrp	x16, 0x142000
  1351d4:      	ldr	x17, [x16, #0xde0]
  1351d8:      	add	x16, x16, #0xde0
  1351dc:      	br	x17
  1351e0:      	nop
  1351e4:      	nop

00000000001351e8 <fstat@plt>:
  1351e8:      	adrp	x16, 0x142000
  1351ec:      	ldr	x17, [x16, #0xde8]
  1351f0:      	add	x16, x16, #0xde8
  1351f4:      	br	x17
  1351f8:      	nop
  1351fc:      	nop

0000000000135200 <strncmp@plt>:
  135200:      	adrp	x16, 0x142000
  135204:      	ldr	x17, [x16, #0xdf0]
  135208:      	add	x16, x16, #0xdf0
  13520c:      	br	x17
  135210:      	nop
  135214:      	nop

0000000000135218 <pthread_rwlock_unlock@plt>:
  135218:      	adrp	x16, 0x142000
  13521c:      	ldr	x17, [x16, #0xdf8]
  135220:      	add	x16, x16, #0xdf8
  135224:      	br	x17
  135228:      	nop
  13522c:      	nop

0000000000135230 <__system_property_get@plt>:
  135230:      	adrp	x16, 0x142000
  135234:      	ldr	x17, [x16, #0xe00]
  135238:      	add	x16, x16, #0xe00
  13523c:      	br	x17
  135240:      	nop
  135244:      	nop

0000000000135248 <getauxval@plt>:
  135248:      	adrp	x16, 0x142000
  13524c:      	ldr	x17, [x16, #0xe08]
  135250:      	add	x16, x16, #0xe08
  135254:      	br	x17
  135258:      	nop
  13525c:      	nop

0000000000135260 <pthread_rwlock_rdlock@plt>:
  135260:      	adrp	x16, 0x142000
  135264:      	ldr	x17, [x16, #0xe10]
  135268:      	add	x16, x16, #0xe10
  13526c:      	br	x17
  135270:      	nop
  135274:      	nop

0000000000135278 <pthread_key_delete@plt>:
  135278:      	adrp	x16, 0x142000
  13527c:      	ldr	x17, [x16, #0xe18]
  135280:      	add	x16, x16, #0xe18
  135284:      	br	x17
  135288:      	nop
  13528c:      	nop

0000000000135290 <pthread_once@plt>:
  135290:      	adrp	x16, 0x142000
  135294:      	ldr	x17, [x16, #0xe20]
  135298:      	add	x16, x16, #0xe20
  13529c:      	br	x17
  1352a0:      	nop
  1352a4:      	nop

00000000001352a8 <pthread_rwlock_wrlock@plt>:
  1352a8:      	adrp	x16, 0x142000
  1352ac:      	ldr	x17, [x16, #0xe28]
  1352b0:      	add	x16, x16, #0xe28
  1352b4:      	br	x17
  1352b8:      	nop
  1352bc:      	nop

00000000001352c0 <getpid@plt>:
  1352c0:      	adrp	x16, 0x142000
  1352c4:      	ldr	x17, [x16, #0xe30]
  1352c8:      	add	x16, x16, #0xe30
  1352cc:      	br	x17
  1352d0:      	nop
  1352d4:      	nop

00000000001352d8 <dl_iterate_phdr@plt>:
  1352d8:      	adrp	x16, 0x142000
  1352dc:      	ldr	x17, [x16, #0xe38]
  1352e0:      	add	x16, x16, #0xe38
  1352e4:      	br	x17
  1352e8:      	nop
  1352ec:      	nop
