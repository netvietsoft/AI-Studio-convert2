// EXPORTED & PLT DISASSEMBLY FOR libffavc.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libffavc.so (SHA-256: 1E214164A6C153F74F25018C1625F3E71D1D5BA601F6592C4DD89385DCC4B0BC)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 2, JNI Methods: 1


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libffavc.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000101740 <.plt>:
  101740:      	stp	x16, x30, [sp, #-0x10]!
  101744:      	adrp	x16, 0x11e000
  101748:      	ldr	x17, [x16, #0xaf8]
  10174c:      	add	x16, x16, #0xaf8
  101750:      	br	x17
  101754:      	nop
  101758:      	nop
  10175c:      	nop

0000000000101760 <__cxa_finalize@plt>:
  101760:      	adrp	x16, 0x11e000
  101764:      	ldr	x17, [x16, #0xb00]
  101768:      	add	x16, x16, #0xb00
  10176c:      	br	x17

0000000000101770 <__cxa_atexit@plt>:
  101770:      	adrp	x16, 0x11e000
  101774:      	ldr	x17, [x16, #0xb08]
  101778:      	add	x16, x16, #0xb08
  10177c:      	br	x17

0000000000101780 <memcpy@plt>:
  101780:      	adrp	x16, 0x11e000
  101784:      	ldr	x17, [x16, #0xb10]
  101788:      	add	x16, x16, #0xb10
  10178c:      	br	x17

0000000000101790 <memset@plt>:
  101790:      	adrp	x16, 0x11e000
  101794:      	ldr	x17, [x16, #0xb18]
  101798:      	add	x16, x16, #0xb18
  10179c:      	br	x17

00000000001017a0 <__stack_chk_fail@plt>:
  1017a0:      	adrp	x16, 0x11e000
  1017a4:      	ldr	x17, [x16, #0xb20]
  1017a8:      	add	x16, x16, #0xb20
  1017ac:      	br	x17

00000000001017b0 <_ZN5ffavc14DecoderFactory9GetHandleEv@plt>:
  1017b0:      	adrp	x16, 0x11e000
  1017b4:      	ldr	x17, [x16, #0xb28]
  1017b8:      	add	x16, x16, #0xb28
  1017bc:      	br	x17

00000000001017c0 <pthread_once@plt>:
  1017c0:      	adrp	x16, 0x11e000
  1017c4:      	ldr	x17, [x16, #0xb30]
  1017c8:      	add	x16, x16, #0xb30
  1017cc:      	br	x17

00000000001017d0 <strcmp@plt>:
  1017d0:      	adrp	x16, 0x11e000
  1017d4:      	ldr	x17, [x16, #0xb38]
  1017d8:      	add	x16, x16, #0xb38
  1017dc:      	br	x17

00000000001017e0 <abort@plt>:
  1017e0:      	adrp	x16, 0x11e000
  1017e4:      	ldr	x17, [x16, #0xb40]
  1017e8:      	add	x16, x16, #0xb40
  1017ec:      	br	x17

00000000001017f0 <pthread_mutex_lock@plt>:
  1017f0:      	adrp	x16, 0x11e000
  1017f4:      	ldr	x17, [x16, #0xb48]
  1017f8:      	add	x16, x16, #0xb48
  1017fc:      	br	x17

0000000000101800 <pthread_mutex_unlock@plt>:
  101800:      	adrp	x16, 0x11e000
  101804:      	ldr	x17, [x16, #0xb50]
  101808:      	add	x16, x16, #0xb50
  10180c:      	br	x17

0000000000101810 <strlen@plt>:
  101810:      	adrp	x16, 0x11e000
  101814:      	ldr	x17, [x16, #0xb58]
  101818:      	add	x16, x16, #0xb58
  10181c:      	br	x17

0000000000101820 <bsearch@plt>:
  101820:      	adrp	x16, 0x11e000
  101824:      	ldr	x17, [x16, #0xb60]
  101828:      	add	x16, x16, #0xb60
  10182c:      	br	x17

0000000000101830 <memmove@plt>:
  101830:      	adrp	x16, 0x11e000
  101834:      	ldr	x17, [x16, #0xb68]
  101838:      	add	x16, x16, #0xb68
  10183c:      	br	x17

0000000000101840 <memcmp@plt>:
  101840:      	adrp	x16, 0x11e000
  101844:      	ldr	x17, [x16, #0xb70]
  101848:      	add	x16, x16, #0xb70
  10184c:      	br	x17

0000000000101850 <sscanf@plt>:
  101850:      	adrp	x16, 0x11e000
  101854:      	ldr	x17, [x16, #0xb78]
  101858:      	add	x16, x16, #0xb78
  10185c:      	br	x17

0000000000101860 <strncmp@plt>:
  101860:      	adrp	x16, 0x11e000
  101864:      	ldr	x17, [x16, #0xb80]
  101868:      	add	x16, x16, #0xb80
  10186c:      	br	x17

0000000000101870 <pthread_mutex_destroy@plt>:
  101870:      	adrp	x16, 0x11e000
  101874:      	ldr	x17, [x16, #0xb88]
  101878:      	add	x16, x16, #0xb88
  10187c:      	br	x17

0000000000101880 <pthread_cond_destroy@plt>:
  101880:      	adrp	x16, 0x11e000
  101884:      	ldr	x17, [x16, #0xb90]
  101888:      	add	x16, x16, #0xb90
  10188c:      	br	x17

0000000000101890 <pthread_mutex_init@plt>:
  101890:      	adrp	x16, 0x11e000
  101894:      	ldr	x17, [x16, #0xb98]
  101898:      	add	x16, x16, #0xb98
  10189c:      	br	x17

00000000001018a0 <pthread_cond_init@plt>:
  1018a0:      	adrp	x16, 0x11e000
  1018a4:      	ldr	x17, [x16, #0xba0]
  1018a8:      	add	x16, x16, #0xba0
  1018ac:      	br	x17

00000000001018b0 <pthread_cond_wait@plt>:
  1018b0:      	adrp	x16, 0x11e000
  1018b4:      	ldr	x17, [x16, #0xba8]
  1018b8:      	add	x16, x16, #0xba8
  1018bc:      	br	x17

00000000001018c0 <pthread_cond_signal@plt>:
  1018c0:      	adrp	x16, 0x11e000
  1018c4:      	ldr	x17, [x16, #0xbb0]
  1018c8:      	add	x16, x16, #0xbb0
  1018cc:      	br	x17

00000000001018d0 <pthread_cond_broadcast@plt>:
  1018d0:      	adrp	x16, 0x11e000
  1018d4:      	ldr	x17, [x16, #0xbb8]
  1018d8:      	add	x16, x16, #0xbb8
  1018dc:      	br	x17

00000000001018e0 <pthread_join@plt>:
  1018e0:      	adrp	x16, 0x11e000
  1018e4:      	ldr	x17, [x16, #0xbc0]
  1018e8:      	add	x16, x16, #0xbc0
  1018ec:      	br	x17

00000000001018f0 <pthread_create@plt>:
  1018f0:      	adrp	x16, 0x11e000
  1018f4:      	ldr	x17, [x16, #0xbc8]
  1018f8:      	add	x16, x16, #0xbc8
  1018fc:      	br	x17

0000000000101900 <snprintf@plt>:
  101900:      	adrp	x16, 0x11e000
  101904:      	ldr	x17, [x16, #0xbd0]
  101908:      	add	x16, x16, #0xbd0
  10190c:      	br	x17

0000000000101910 <prctl@plt>:
  101910:      	adrp	x16, 0x11e000
  101914:      	ldr	x17, [x16, #0xbd8]
  101918:      	add	x16, x16, #0xbd8
  10191c:      	br	x17

0000000000101920 <vsnprintf@plt>:
  101920:      	adrp	x16, 0x11e000
  101924:      	ldr	x17, [x16, #0xbe0]
  101928:      	add	x16, x16, #0xbe0
  10192c:      	br	x17

0000000000101930 <strspn@plt>:
  101930:      	adrp	x16, 0x11e000
  101934:      	ldr	x17, [x16, #0xbe8]
  101938:      	add	x16, x16, #0xbe8
  10193c:      	br	x17

0000000000101940 <strcspn@plt>:
  101940:      	adrp	x16, 0x11e000
  101944:      	ldr	x17, [x16, #0xbf0]
  101948:      	add	x16, x16, #0xbf0
  10194c:      	br	x17

0000000000101950 <strrchr@plt>:
  101950:      	adrp	x16, 0x11e000
  101954:      	ldr	x17, [x16, #0xbf8]
  101958:      	add	x16, x16, #0xbf8
  10195c:      	br	x17

0000000000101960 <strchr@plt>:
  101960:      	adrp	x16, 0x11e000
  101964:      	ldr	x17, [x16, #0xc00]
  101968:      	add	x16, x16, #0xc00
  10196c:      	br	x17

0000000000101970 <strftime@plt>:
  101970:      	adrp	x16, 0x11e000
  101974:      	ldr	x17, [x16, #0xc08]
  101978:      	add	x16, x16, #0xc08
  10197c:      	br	x17

0000000000101980 <memchr@plt>:
  101980:      	adrp	x16, 0x11e000
  101984:      	ldr	x17, [x16, #0xc10]
  101988:      	add	x16, x16, #0xc10
  10198c:      	br	x17

0000000000101990 <strtol@plt>:
  101990:      	adrp	x16, 0x11e000
  101994:      	ldr	x17, [x16, #0xc18]
  101998:      	add	x16, x16, #0xc18
  10199c:      	br	x17

00000000001019a0 <__errno@plt>:
  1019a0:      	adrp	x16, 0x11e000
  1019a4:      	ldr	x17, [x16, #0xc20]
  1019a8:      	add	x16, x16, #0xc20
  1019ac:      	br	x17

00000000001019b0 <strtoull@plt>:
  1019b0:      	adrp	x16, 0x11e000
  1019b4:      	ldr	x17, [x16, #0xc28]
  1019b8:      	add	x16, x16, #0xc28
  1019bc:      	br	x17

00000000001019c0 <scalbn@plt>:
  1019c0:      	adrp	x16, 0x11e000
  1019c4:      	ldr	x17, [x16, #0xc30]
  1019c8:      	add	x16, x16, #0xc30
  1019cc:      	br	x17

00000000001019d0 <fmod@plt>:
  1019d0:      	adrp	x16, 0x11e000
  1019d4:      	ldr	x17, [x16, #0xc38]
  1019d8:      	add	x16, x16, #0xc38
  1019dc:      	br	x17

00000000001019e0 <sched_getaffinity@plt>:
  1019e0:      	adrp	x16, 0x11e000
  1019e4:      	ldr	x17, [x16, #0xc40]
  1019e8:      	add	x16, x16, #0xc40
  1019ec:      	br	x17

00000000001019f0 <__sched_cpucount@plt>:
  1019f0:      	adrp	x16, 0x11e000
  1019f4:      	ldr	x17, [x16, #0xc48]
  1019f8:      	add	x16, x16, #0xc48
  1019fc:      	br	x17

0000000000101a00 <getauxval@plt>:
  101a00:      	adrp	x16, 0x11e000
  101a04:      	ldr	x17, [x16, #0xc50]
  101a08:      	add	x16, x16, #0xc50
  101a0c:      	br	x17

0000000000101a10 <gmtime_r@plt>:
  101a10:      	adrp	x16, 0x11e000
  101a14:      	ldr	x17, [x16, #0xc58]
  101a18:      	add	x16, x16, #0xc58
  101a1c:      	br	x17

0000000000101a20 <hypot@plt>:
  101a20:      	adrp	x16, 0x11e000
  101a24:      	ldr	x17, [x16, #0xc60]
  101a28:      	add	x16, x16, #0xc60
  101a2c:      	br	x17

0000000000101a30 <atan2@plt>:
  101a30:      	adrp	x16, 0x11e000
  101a34:      	ldr	x17, [x16, #0xc68]
  101a38:      	add	x16, x16, #0xc68
  101a3c:      	br	x17

0000000000101a40 <sincos@plt>:
  101a40:      	adrp	x16, 0x11e000
  101a44:      	ldr	x17, [x16, #0xc70]
  101a48:      	add	x16, x16, #0xc70
  101a4c:      	br	x17

0000000000101a50 <strerror_r@plt>:
  101a50:      	adrp	x16, 0x11e000
  101a54:      	ldr	x17, [x16, #0xc78]
  101a58:      	add	x16, x16, #0xc78
  101a5c:      	br	x17

0000000000101a60 <isatty@plt>:
  101a60:      	adrp	x16, 0x11e000
  101a64:      	ldr	x17, [x16, #0xc80]
  101a68:      	add	x16, x16, #0xc80
  101a6c:      	br	x17

0000000000101a70 <strcpy@plt>:
  101a70:      	adrp	x16, 0x11e000
  101a74:      	ldr	x17, [x16, #0xc88]
  101a78:      	add	x16, x16, #0xc88
  101a7c:      	br	x17

0000000000101a80 <getenv@plt>:
  101a80:      	adrp	x16, 0x11e000
  101a84:      	ldr	x17, [x16, #0xc90]
  101a88:      	add	x16, x16, #0xc90
  101a8c:      	br	x17

0000000000101a90 <fprintf@plt>:
  101a90:      	adrp	x16, 0x11e000
  101a94:      	ldr	x17, [x16, #0xc98]
  101a98:      	add	x16, x16, #0xc98
  101a9c:      	br	x17

0000000000101aa0 <strstr@plt>:
  101aa0:      	adrp	x16, 0x11e000
  101aa4:      	ldr	x17, [x16, #0xca0]
  101aa8:      	add	x16, x16, #0xca0
  101aac:      	br	x17

0000000000101ab0 <fputs@plt>:
  101ab0:      	adrp	x16, 0x11e000
  101ab4:      	ldr	x17, [x16, #0xca8]
  101ab8:      	add	x16, x16, #0xca8
  101abc:      	br	x17

0000000000101ac0 <exp@plt>:
  101ac0:      	adrp	x16, 0x11e000
  101ac4:      	ldr	x17, [x16, #0xcb0]
  101ac8:      	add	x16, x16, #0xcb0
  101acc:      	br	x17

0000000000101ad0 <posix_memalign@plt>:
  101ad0:      	adrp	x16, 0x11e000
  101ad4:      	ldr	x17, [x16, #0xcb8]
  101ad8:      	add	x16, x16, #0xcb8
  101adc:      	br	x17

0000000000101ae0 <realloc@plt>:
  101ae0:      	adrp	x16, 0x11e000
  101ae4:      	ldr	x17, [x16, #0xcc0]
  101ae8:      	add	x16, x16, #0xcc0
  101aec:      	br	x17

0000000000101af0 <free@plt>:
  101af0:      	adrp	x16, 0x11e000
  101af4:      	ldr	x17, [x16, #0xcc8]
  101af8:      	add	x16, x16, #0xcc8
  101afc:      	br	x17

0000000000101b00 <strtoul@plt>:
  101b00:      	adrp	x16, 0x11e000
  101b04:      	ldr	x17, [x16, #0xcd0]
  101b08:      	add	x16, x16, #0xcd0
  101b0c:      	br	x17

0000000000101b10 <exp2@plt>:
  101b10:      	adrp	x16, 0x11e000
  101b14:      	ldr	x17, [x16, #0xcd8]
  101b18:      	add	x16, x16, #0xcd8
  101b1c:      	br	x17

0000000000101b20 <pow@plt>:
  101b20:      	adrp	x16, 0x11e000
  101b24:      	ldr	x17, [x16, #0xce0]
  101b28:      	add	x16, x16, #0xce0
  101b2c:      	br	x17

0000000000101b30 <strtod@plt>:
  101b30:      	adrp	x16, 0x11e000
  101b34:      	ldr	x17, [x16, #0xce8]
  101b38:      	add	x16, x16, #0xce8
  101b3c:      	br	x17

0000000000101b40 <strtoll@plt>:
  101b40:      	adrp	x16, 0x11e000
  101b44:      	ldr	x17, [x16, #0xcf0]
  101b48:      	add	x16, x16, #0xcf0
  101b4c:      	br	x17

0000000000101b50 <localtime_r@plt>:
  101b50:      	adrp	x16, 0x11e000
  101b54:      	ldr	x17, [x16, #0xcf8]
  101b58:      	add	x16, x16, #0xcf8
  101b5c:      	br	x17

0000000000101b60 <mktime@plt>:
  101b60:      	adrp	x16, 0x11e000
  101b64:      	ldr	x17, [x16, #0xd00]
  101b68:      	add	x16, x16, #0xd00
  101b6c:      	br	x17

0000000000101b70 <arc4random_buf@plt>:
  101b70:      	adrp	x16, 0x11e000
  101b74:      	ldr	x17, [x16, #0xd08]
  101b78:      	add	x16, x16, #0xd08
  101b7c:      	br	x17

0000000000101b80 <frexp@plt>:
  101b80:      	adrp	x16, 0x11e000
  101b84:      	ldr	x17, [x16, #0xd10]
  101b88:      	add	x16, x16, #0xd10
  101b8c:      	br	x17

0000000000101b90 <gettimeofday@plt>:
  101b90:      	adrp	x16, 0x11e000
  101b94:      	ldr	x17, [x16, #0xd18]
  101b98:      	add	x16, x16, #0xd18
  101b9c:      	br	x17

0000000000101ba0 <clock_gettime@plt>:
  101ba0:      	adrp	x16, 0x11e000
  101ba4:      	ldr	x17, [x16, #0xd20]
  101ba8:      	add	x16, x16, #0xd20
  101bac:      	br	x17

0000000000101bb0 <nanosleep@plt>:
  101bb0:      	adrp	x16, 0x11e000
  101bb4:      	ldr	x17, [x16, #0xd28]
  101bb8:      	add	x16, x16, #0xd28
  101bbc:      	br	x17

0000000000101bc0 <syscall@plt>:
  101bc0:      	adrp	x16, 0x11e000
  101bc4:      	ldr	x17, [x16, #0xd30]
  101bc8:      	add	x16, x16, #0xd30
  101bcc:      	br	x17

0000000000101bd0 <fwrite@plt>:
  101bd0:      	adrp	x16, 0x11e000
  101bd4:      	ldr	x17, [x16, #0xd38]
  101bd8:      	add	x16, x16, #0xd38
  101bdc:      	br	x17

0000000000101be0 <vfprintf@plt>:
  101be0:      	adrp	x16, 0x11e000
  101be4:      	ldr	x17, [x16, #0xd40]
  101be8:      	add	x16, x16, #0xd40
  101bec:      	br	x17

0000000000101bf0 <fputc@plt>:
  101bf0:      	adrp	x16, 0x11e000
  101bf4:      	ldr	x17, [x16, #0xd48]
  101bf8:      	add	x16, x16, #0xd48
  101bfc:      	br	x17

0000000000101c00 <vasprintf@plt>:
  101c00:      	adrp	x16, 0x11e000
  101c04:      	ldr	x17, [x16, #0xd50]
  101c08:      	add	x16, x16, #0xd50
  101c0c:      	br	x17

0000000000101c10 <android_set_abort_message@plt>:
  101c10:      	adrp	x16, 0x11e000
  101c14:      	ldr	x17, [x16, #0xd58]
  101c18:      	add	x16, x16, #0xd58
  101c1c:      	br	x17

0000000000101c20 <openlog@plt>:
  101c20:      	adrp	x16, 0x11e000
  101c24:      	ldr	x17, [x16, #0xd60]
  101c28:      	add	x16, x16, #0xd60
  101c2c:      	br	x17

0000000000101c30 <syslog@plt>:
  101c30:      	adrp	x16, 0x11e000
  101c34:      	ldr	x17, [x16, #0xd68]
  101c38:      	add	x16, x16, #0xd68
  101c3c:      	br	x17

0000000000101c40 <closelog@plt>:
  101c40:      	adrp	x16, 0x11e000
  101c44:      	ldr	x17, [x16, #0xd70]
  101c48:      	add	x16, x16, #0xd70
  101c4c:      	br	x17

0000000000101c50 <malloc@plt>:
  101c50:      	adrp	x16, 0x11e000
  101c54:      	ldr	x17, [x16, #0xd78]
  101c58:      	add	x16, x16, #0xd78
  101c5c:      	br	x17

0000000000101c60 <pthread_getspecific@plt>:
  101c60:      	adrp	x16, 0x11e000
  101c64:      	ldr	x17, [x16, #0xd80]
  101c68:      	add	x16, x16, #0xd80
  101c6c:      	br	x17

0000000000101c70 <pthread_setspecific@plt>:
  101c70:      	adrp	x16, 0x11e000
  101c74:      	ldr	x17, [x16, #0xd88]
  101c78:      	add	x16, x16, #0xd88
  101c7c:      	br	x17

0000000000101c80 <pthread_key_delete@plt>:
  101c80:      	adrp	x16, 0x11e000
  101c84:      	ldr	x17, [x16, #0xd90]
  101c88:      	add	x16, x16, #0xd90
  101c8c:      	br	x17

0000000000101c90 <pthread_key_create@plt>:
  101c90:      	adrp	x16, 0x11e000
  101c94:      	ldr	x17, [x16, #0xd98]
  101c98:      	add	x16, x16, #0xd98
  101c9c:      	br	x17

0000000000101ca0 <__system_property_get@plt>:
  101ca0:      	adrp	x16, 0x11e000
  101ca4:      	ldr	x17, [x16, #0xda0]
  101ca8:      	add	x16, x16, #0xda0
  101cac:      	br	x17

0000000000101cb0 <fflush@plt>:
  101cb0:      	adrp	x16, 0x11e000
  101cb4:      	ldr	x17, [x16, #0xda8]
  101cb8:      	add	x16, x16, #0xda8
  101cbc:      	br	x17

0000000000101cc0 <pthread_rwlock_wrlock@plt>:
  101cc0:      	adrp	x16, 0x11e000
  101cc4:      	ldr	x17, [x16, #0xdb0]
  101cc8:      	add	x16, x16, #0xdb0
  101ccc:      	br	x17

0000000000101cd0 <pthread_rwlock_unlock@plt>:
  101cd0:      	adrp	x16, 0x11e000
  101cd4:      	ldr	x17, [x16, #0xdb8]
  101cd8:      	add	x16, x16, #0xdb8
  101cdc:      	br	x17

0000000000101ce0 <dl_iterate_phdr@plt>:
  101ce0:      	adrp	x16, 0x11e000
  101ce4:      	ldr	x17, [x16, #0xdc0]
  101ce8:      	add	x16, x16, #0xdc0
  101cec:      	br	x17

0000000000101cf0 <pthread_rwlock_rdlock@plt>:
  101cf0:      	adrp	x16, 0x11e000
  101cf4:      	ldr	x17, [x16, #0xdc8]
  101cf8:      	add	x16, x16, #0xdc8
  101cfc:      	br	x17
