// EXPORTED & PLT DISASSEMBLY FOR libffmpeg.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libffmpeg.so (SHA-256: D8DF8C5CB7A6B5A7EB771782D74A38E0B8D3CFACD1FBEF1AE67A96171E3325C9)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 3247, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libffmpeg.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000006d7500 <.plt>:
  6d7500:      	stp	x16, x30, [sp, #-0x10]!
  6d7504:      	adrp	x16, 0x734000
  6d7508:      	ldr	x17, [x16, #0xfa8]
  6d750c:      	add	x16, x16, #0xfa8
  6d7510:      	br	x17
  6d7514:      	nop
  6d7518:      	nop
  6d751c:      	nop

00000000006d7520 <__cxa_finalize@plt>:
  6d7520:      	adrp	x16, 0x734000
  6d7524:      	ldr	x17, [x16, #0xfb0]
  6d7528:      	add	x16, x16, #0xfb0
  6d752c:      	br	x17

00000000006d7530 <__cxa_atexit@plt>:
  6d7530:      	adrp	x16, 0x734000
  6d7534:      	ldr	x17, [x16, #0xfb8]
  6d7538:      	add	x16, x16, #0xfb8
  6d753c:      	br	x17

00000000006d7540 <log10@plt>:
  6d7540:      	adrp	x16, 0x734000
  6d7544:      	ldr	x17, [x16, #0xfc0]
  6d7548:      	add	x16, x16, #0xfc0
  6d754c:      	br	x17

00000000006d7550 <atan2f@plt>:
  6d7550:      	adrp	x16, 0x734000
  6d7554:      	ldr	x17, [x16, #0xfc8]
  6d7558:      	add	x16, x16, #0xfc8
  6d755c:      	br	x17

00000000006d7560 <exp2f@plt>:
  6d7560:      	adrp	x16, 0x734000
  6d7564:      	ldr	x17, [x16, #0xfd0]
  6d7568:      	add	x16, x16, #0xfd0
  6d756c:      	br	x17

00000000006d7570 <tan@plt>:
  6d7570:      	adrp	x16, 0x734000
  6d7574:      	ldr	x17, [x16, #0xfd8]
  6d7578:      	add	x16, x16, #0xfd8
  6d757c:      	br	x17

00000000006d7580 <pow@plt>:
  6d7580:      	adrp	x16, 0x734000
  6d7584:      	ldr	x17, [x16, #0xfe0]
  6d7588:      	add	x16, x16, #0xfe0
  6d758c:      	br	x17

00000000006d7590 <powf@plt>:
  6d7590:      	adrp	x16, 0x734000
  6d7594:      	ldr	x17, [x16, #0xfe8]
  6d7598:      	add	x16, x16, #0xfe8
  6d759c:      	br	x17

00000000006d75a0 <sinf@plt>:
  6d75a0:      	adrp	x16, 0x734000
  6d75a4:      	ldr	x17, [x16, #0xff0]
  6d75a8:      	add	x16, x16, #0xff0
  6d75ac:      	br	x17

00000000006d75b0 <atan@plt>:
  6d75b0:      	adrp	x16, 0x734000
  6d75b4:      	ldr	x17, [x16, #0xff8]
  6d75b8:      	add	x16, x16, #0xff8
  6d75bc:      	br	x17

00000000006d75c0 <log@plt>:
  6d75c0:      	adrp	x16, 0x735000
  6d75c4:      	ldr	x17, [x16]
  6d75c8:      	add	x16, x16, #0x0
  6d75cc:      	br	x17

00000000006d75d0 <log10f@plt>:
  6d75d0:      	adrp	x16, 0x735000
  6d75d4:      	ldr	x17, [x16, #0x8]
  6d75d8:      	add	x16, x16, #0x8
  6d75dc:      	br	x17

00000000006d75e0 <atanf@plt>:
  6d75e0:      	adrp	x16, 0x735000
  6d75e4:      	ldr	x17, [x16, #0x10]
  6d75e8:      	add	x16, x16, #0x10
  6d75ec:      	br	x17

00000000006d75f0 <scalbn@plt>:
  6d75f0:      	adrp	x16, 0x735000
  6d75f4:      	ldr	x17, [x16, #0x18]
  6d75f8:      	add	x16, x16, #0x18
  6d75fc:      	br	x17

00000000006d7600 <atan2@plt>:
  6d7600:      	adrp	x16, 0x735000
  6d7604:      	ldr	x17, [x16, #0x20]
  6d7608:      	add	x16, x16, #0x20
  6d760c:      	br	x17

00000000006d7610 <sincos@plt>:
  6d7610:      	adrp	x16, 0x735000
  6d7614:      	ldr	x17, [x16, #0x28]
  6d7618:      	add	x16, x16, #0x28
  6d761c:      	br	x17

00000000006d7620 <logf@plt>:
  6d7620:      	adrp	x16, 0x735000
  6d7624:      	ldr	x17, [x16, #0x30]
  6d7628:      	add	x16, x16, #0x30
  6d762c:      	br	x17

00000000006d7630 <log2@plt>:
  6d7630:      	adrp	x16, 0x735000
  6d7634:      	ldr	x17, [x16, #0x38]
  6d7638:      	add	x16, x16, #0x38
  6d763c:      	br	x17

00000000006d7640 <log2f@plt>:
  6d7640:      	adrp	x16, 0x735000
  6d7644:      	ldr	x17, [x16, #0x40]
  6d7648:      	add	x16, x16, #0x40
  6d764c:      	br	x17

00000000006d7650 <hypot@plt>:
  6d7650:      	adrp	x16, 0x735000
  6d7654:      	ldr	x17, [x16, #0x48]
  6d7658:      	add	x16, x16, #0x48
  6d765c:      	br	x17

00000000006d7660 <cbrt@plt>:
  6d7660:      	adrp	x16, 0x735000
  6d7664:      	ldr	x17, [x16, #0x50]
  6d7668:      	add	x16, x16, #0x50
  6d766c:      	br	x17

00000000006d7670 <exp@plt>:
  6d7670:      	adrp	x16, 0x735000
  6d7674:      	ldr	x17, [x16, #0x58]
  6d7678:      	add	x16, x16, #0x58
  6d767c:      	br	x17

00000000006d7680 <ldexpf@plt>:
  6d7680:      	adrp	x16, 0x735000
  6d7684:      	ldr	x17, [x16, #0x60]
  6d7688:      	add	x16, x16, #0x60
  6d768c:      	br	x17

00000000006d7690 <frexp@plt>:
  6d7690:      	adrp	x16, 0x735000
  6d7694:      	ldr	x17, [x16, #0x68]
  6d7698:      	add	x16, x16, #0x68
  6d769c:      	br	x17

00000000006d76a0 <cbrtf@plt>:
  6d76a0:      	adrp	x16, 0x735000
  6d76a4:      	ldr	x17, [x16, #0x70]
  6d76a8:      	add	x16, x16, #0x70
  6d76ac:      	br	x17

00000000006d76b0 <sin@plt>:
  6d76b0:      	adrp	x16, 0x735000
  6d76b4:      	ldr	x17, [x16, #0x78]
  6d76b8:      	add	x16, x16, #0x78
  6d76bc:      	br	x17

00000000006d76c0 <sincosf@plt>:
  6d76c0:      	adrp	x16, 0x735000
  6d76c4:      	ldr	x17, [x16, #0x80]
  6d76c8:      	add	x16, x16, #0x80
  6d76cc:      	br	x17

00000000006d76d0 <expf@plt>:
  6d76d0:      	adrp	x16, 0x735000
  6d76d4:      	ldr	x17, [x16, #0x88]
  6d76d8:      	add	x16, x16, #0x88
  6d76dc:      	br	x17

00000000006d76e0 <fmod@plt>:
  6d76e0:      	adrp	x16, 0x735000
  6d76e4:      	ldr	x17, [x16, #0x90]
  6d76e8:      	add	x16, x16, #0x90
  6d76ec:      	br	x17

00000000006d76f0 <cos@plt>:
  6d76f0:      	adrp	x16, 0x735000
  6d76f4:      	ldr	x17, [x16, #0x98]
  6d76f8:      	add	x16, x16, #0x98
  6d76fc:      	br	x17

00000000006d7700 <exp2@plt>:
  6d7700:      	adrp	x16, 0x735000
  6d7704:      	ldr	x17, [x16, #0xa0]
  6d7708:      	add	x16, x16, #0xa0
  6d770c:      	br	x17

00000000006d7710 <inflateReset@plt>:
  6d7710:      	adrp	x16, 0x735000
  6d7714:      	ldr	x17, [x16, #0xa8]
  6d7718:      	add	x16, x16, #0xa8
  6d771c:      	br	x17

00000000006d7720 <deflate@plt>:
  6d7720:      	adrp	x16, 0x735000
  6d7724:      	ldr	x17, [x16, #0xb0]
  6d7728:      	add	x16, x16, #0xb0
  6d772c:      	br	x17

00000000006d7730 <deflateReset@plt>:
  6d7730:      	adrp	x16, 0x735000
  6d7734:      	ldr	x17, [x16, #0xb8]
  6d7738:      	add	x16, x16, #0xb8
  6d773c:      	br	x17

00000000006d7740 <deflateEnd@plt>:
  6d7740:      	adrp	x16, 0x735000
  6d7744:      	ldr	x17, [x16, #0xc0]
  6d7748:      	add	x16, x16, #0xc0
  6d774c:      	br	x17

00000000006d7750 <deflateBound@plt>:
  6d7750:      	adrp	x16, 0x735000
  6d7754:      	ldr	x17, [x16, #0xc8]
  6d7758:      	add	x16, x16, #0xc8
  6d775c:      	br	x17

00000000006d7760 <uncompress@plt>:
  6d7760:      	adrp	x16, 0x735000
  6d7764:      	ldr	x17, [x16, #0xd0]
  6d7768:      	add	x16, x16, #0xd0
  6d776c:      	br	x17

00000000006d7770 <inflateEnd@plt>:
  6d7770:      	adrp	x16, 0x735000
  6d7774:      	ldr	x17, [x16, #0xd8]
  6d7778:      	add	x16, x16, #0xd8
  6d777c:      	br	x17

00000000006d7780 <zlibCompileFlags@plt>:
  6d7780:      	adrp	x16, 0x735000
  6d7784:      	ldr	x17, [x16, #0xe0]
  6d7788:      	add	x16, x16, #0xe0
  6d778c:      	br	x17

00000000006d7790 <inflateInit_@plt>:
  6d7790:      	adrp	x16, 0x735000
  6d7794:      	ldr	x17, [x16, #0xe8]
  6d7798:      	add	x16, x16, #0xe8
  6d779c:      	br	x17

00000000006d77a0 <inflate@plt>:
  6d77a0:      	adrp	x16, 0x735000
  6d77a4:      	ldr	x17, [x16, #0xf0]
  6d77a8:      	add	x16, x16, #0xf0
  6d77ac:      	br	x17

00000000006d77b0 <inflateInit2_@plt>:
  6d77b0:      	adrp	x16, 0x735000
  6d77b4:      	ldr	x17, [x16, #0xf8]
  6d77b8:      	add	x16, x16, #0xf8
  6d77bc:      	br	x17

00000000006d77c0 <deflateInit_@plt>:
  6d77c0:      	adrp	x16, 0x735000
  6d77c4:      	ldr	x17, [x16, #0x100]
  6d77c8:      	add	x16, x16, #0x100
  6d77cc:      	br	x17

00000000006d77d0 <ANativeWindow_release@plt>:
  6d77d0:      	adrp	x16, 0x735000
  6d77d4:      	ldr	x17, [x16, #0x108]
  6d77d8:      	add	x16, x16, #0x108
  6d77dc:      	br	x17

00000000006d77e0 <ANativeWindow_fromSurface@plt>:
  6d77e0:      	adrp	x16, 0x735000
  6d77e4:      	ldr	x17, [x16, #0x110]
  6d77e8:      	add	x16, x16, #0x110
  6d77ec:      	br	x17

00000000006d77f0 <ANativeWindow_acquire@plt>:
  6d77f0:      	adrp	x16, 0x735000
  6d77f4:      	ldr	x17, [x16, #0x118]
  6d77f8:      	add	x16, x16, #0x118
  6d77fc:      	br	x17

00000000006d7800 <AMediaFormat_setString@plt>:
  6d7800:      	adrp	x16, 0x735000
  6d7804:      	ldr	x17, [x16, #0x120]
  6d7808:      	add	x16, x16, #0x120
  6d780c:      	br	x17

00000000006d7810 <AMediaCodec_getOutputBuffer@plt>:
  6d7810:      	adrp	x16, 0x735000
  6d7814:      	ldr	x17, [x16, #0x128]
  6d7818:      	add	x16, x16, #0x128
  6d781c:      	br	x17

00000000006d7820 <AMediaFormat_setInt64@plt>:
  6d7820:      	adrp	x16, 0x735000
  6d7824:      	ldr	x17, [x16, #0x130]
  6d7828:      	add	x16, x16, #0x130
  6d782c:      	br	x17

00000000006d7830 <AMediaFormat_getBuffer@plt>:
  6d7830:      	adrp	x16, 0x735000
  6d7834:      	ldr	x17, [x16, #0x138]
  6d7838:      	add	x16, x16, #0x138
  6d783c:      	br	x17

00000000006d7840 <AMediaCodec_configure@plt>:
  6d7840:      	adrp	x16, 0x735000
  6d7844:      	ldr	x17, [x16, #0x140]
  6d7848:      	add	x16, x16, #0x140
  6d784c:      	br	x17

00000000006d7850 <AMediaCodec_start@plt>:
  6d7850:      	adrp	x16, 0x735000
  6d7854:      	ldr	x17, [x16, #0x148]
  6d7858:      	add	x16, x16, #0x148
  6d785c:      	br	x17

00000000006d7860 <AMediaFormat_delete@plt>:
  6d7860:      	adrp	x16, 0x735000
  6d7864:      	ldr	x17, [x16, #0x150]
  6d7868:      	add	x16, x16, #0x150
  6d786c:      	br	x17

00000000006d7870 <AMediaCodec_releaseOutputBufferAtTime@plt>:
  6d7870:      	adrp	x16, 0x735000
  6d7874:      	ldr	x17, [x16, #0x158]
  6d7878:      	add	x16, x16, #0x158
  6d787c:      	br	x17

00000000006d7880 <AMediaCodec_stop@plt>:
  6d7880:      	adrp	x16, 0x735000
  6d7884:      	ldr	x17, [x16, #0x160]
  6d7888:      	add	x16, x16, #0x160
  6d788c:      	br	x17

00000000006d7890 <AMediaFormat_getInt32@plt>:
  6d7890:      	adrp	x16, 0x735000
  6d7894:      	ldr	x17, [x16, #0x168]
  6d7898:      	add	x16, x16, #0x168
  6d789c:      	br	x17

00000000006d78a0 <AMediaCodec_dequeueInputBuffer@plt>:
  6d78a0:      	adrp	x16, 0x735000
  6d78a4:      	ldr	x17, [x16, #0x170]
  6d78a8:      	add	x16, x16, #0x170
  6d78ac:      	br	x17

00000000006d78b0 <AMediaFormat_toString@plt>:
  6d78b0:      	adrp	x16, 0x735000
  6d78b4:      	ldr	x17, [x16, #0x178]
  6d78b8:      	add	x16, x16, #0x178
  6d78bc:      	br	x17

00000000006d78c0 <AMediaCodec_createCodecByName@plt>:
  6d78c0:      	adrp	x16, 0x735000
  6d78c4:      	ldr	x17, [x16, #0x180]
  6d78c8:      	add	x16, x16, #0x180
  6d78cc:      	br	x17

00000000006d78d0 <AMediaCodec_createDecoderByType@plt>:
  6d78d0:      	adrp	x16, 0x735000
  6d78d4:      	ldr	x17, [x16, #0x188]
  6d78d8:      	add	x16, x16, #0x188
  6d78dc:      	br	x17

00000000006d78e0 <AMediaCodec_delete@plt>:
  6d78e0:      	adrp	x16, 0x735000
  6d78e4:      	ldr	x17, [x16, #0x190]
  6d78e8:      	add	x16, x16, #0x190
  6d78ec:      	br	x17

00000000006d78f0 <AMediaFormat_setInt32@plt>:
  6d78f0:      	adrp	x16, 0x735000
  6d78f4:      	ldr	x17, [x16, #0x198]
  6d78f8:      	add	x16, x16, #0x198
  6d78fc:      	br	x17

00000000006d7900 <AMediaFormat_getFloat@plt>:
  6d7900:      	adrp	x16, 0x735000
  6d7904:      	ldr	x17, [x16, #0x1a0]
  6d7908:      	add	x16, x16, #0x1a0
  6d790c:      	br	x17

00000000006d7910 <AMediaFormat_new@plt>:
  6d7910:      	adrp	x16, 0x735000
  6d7914:      	ldr	x17, [x16, #0x1a8]
  6d7918:      	add	x16, x16, #0x1a8
  6d791c:      	br	x17

00000000006d7920 <AMediaFormat_setBuffer@plt>:
  6d7920:      	adrp	x16, 0x735000
  6d7924:      	ldr	x17, [x16, #0x1b0]
  6d7928:      	add	x16, x16, #0x1b0
  6d792c:      	br	x17

00000000006d7930 <AMediaFormat_getString@plt>:
  6d7930:      	adrp	x16, 0x735000
  6d7934:      	ldr	x17, [x16, #0x1b8]
  6d7938:      	add	x16, x16, #0x1b8
  6d793c:      	br	x17

00000000006d7940 <AMediaCodec_queueInputBuffer@plt>:
  6d7940:      	adrp	x16, 0x735000
  6d7944:      	ldr	x17, [x16, #0x1c0]
  6d7948:      	add	x16, x16, #0x1c0
  6d794c:      	br	x17

00000000006d7950 <AMediaCodec_dequeueOutputBuffer@plt>:
  6d7950:      	adrp	x16, 0x735000
  6d7954:      	ldr	x17, [x16, #0x1c8]
  6d7958:      	add	x16, x16, #0x1c8
  6d795c:      	br	x17

00000000006d7960 <AMediaFormat_setFloat@plt>:
  6d7960:      	adrp	x16, 0x735000
  6d7964:      	ldr	x17, [x16, #0x1d0]
  6d7968:      	add	x16, x16, #0x1d0
  6d796c:      	br	x17

00000000006d7970 <AMediaCodec_getInputBuffer@plt>:
  6d7970:      	adrp	x16, 0x735000
  6d7974:      	ldr	x17, [x16, #0x1d8]
  6d7978:      	add	x16, x16, #0x1d8
  6d797c:      	br	x17

00000000006d7980 <AMediaCodec_getOutputFormat@plt>:
  6d7980:      	adrp	x16, 0x735000
  6d7984:      	ldr	x17, [x16, #0x1e0]
  6d7988:      	add	x16, x16, #0x1e0
  6d798c:      	br	x17

00000000006d7990 <AMediaCodec_createEncoderByType@plt>:
  6d7990:      	adrp	x16, 0x735000
  6d7994:      	ldr	x17, [x16, #0x1e8]
  6d7998:      	add	x16, x16, #0x1e8
  6d799c:      	br	x17

00000000006d79a0 <AMediaCodec_flush@plt>:
  6d79a0:      	adrp	x16, 0x735000
  6d79a4:      	ldr	x17, [x16, #0x1f0]
  6d79a8:      	add	x16, x16, #0x1f0
  6d79ac:      	br	x17

00000000006d79b0 <AMediaCodec_releaseOutputBuffer@plt>:
  6d79b0:      	adrp	x16, 0x735000
  6d79b4:      	ldr	x17, [x16, #0x1f8]
  6d79b8:      	add	x16, x16, #0x1f8
  6d79bc:      	br	x17

00000000006d79c0 <AMediaFormat_getInt64@plt>:
  6d79c0:      	adrp	x16, 0x735000
  6d79c4:      	ldr	x17, [x16, #0x200]
  6d79c8:      	add	x16, x16, #0x200
  6d79cc:      	br	x17

00000000006d79d0 <avpriv_strtod@plt>:
  6d79d0:      	adrp	x16, 0x735000
  6d79d4:      	ldr	x17, [x16, #0x208]
  6d79d8:      	add	x16, x16, #0x208
  6d79dc:      	br	x17

00000000006d79e0 <av_strncasecmp@plt>:
  6d79e0:      	adrp	x16, 0x735000
  6d79e4:      	ldr	x17, [x16, #0x210]
  6d79e8:      	add	x16, x16, #0x210
  6d79ec:      	br	x17

00000000006d79f0 <strtod@plt>:
  6d79f0:      	adrp	x16, 0x735000
  6d79f4:      	ldr	x17, [x16, #0x218]
  6d79f8:      	add	x16, x16, #0x218
  6d79fc:      	br	x17

00000000006d7a00 <strtoll@plt>:
  6d7a00:      	adrp	x16, 0x735000
  6d7a04:      	ldr	x17, [x16, #0x220]
  6d7a08:      	add	x16, x16, #0x220
  6d7a0c:      	br	x17

00000000006d7a10 <ff_adts_header_parse_buf@plt>:
  6d7a10:      	adrp	x16, 0x735000
  6d7a14:      	ldr	x17, [x16, #0x228]
  6d7a18:      	add	x16, x16, #0x228
  6d7a1c:      	br	x17

00000000006d7a20 <avpriv_adts_header_parse@plt>:
  6d7a20:      	adrp	x16, 0x735000
  6d7a24:      	ldr	x17, [x16, #0x230]
  6d7a28:      	add	x16, x16, #0x230
  6d7a2c:      	br	x17

00000000006d7a30 <av_mallocz@plt>:
  6d7a30:      	adrp	x16, 0x735000
  6d7a34:      	ldr	x17, [x16, #0x238]
  6d7a38:      	add	x16, x16, #0x238
  6d7a3c:      	br	x17

00000000006d7a40 <av_freep@plt>:
  6d7a40:      	adrp	x16, 0x735000
  6d7a44:      	ldr	x17, [x16, #0x240]
  6d7a48:      	add	x16, x16, #0x240
  6d7a4c:      	br	x17

00000000006d7a50 <ff_msmpeg4_common_init@plt>:
  6d7a50:      	adrp	x16, 0x735000
  6d7a54:      	ldr	x17, [x16, #0x248]
  6d7a58:      	add	x16, x16, #0x248
  6d7a5c:      	br	x17

00000000006d7a60 <ff_init_scantable@plt>:
  6d7a60:      	adrp	x16, 0x735000
  6d7a64:      	ldr	x17, [x16, #0x250]
  6d7a68:      	add	x16, x16, #0x250
  6d7a6c:      	br	x17

00000000006d7a70 <ff_permute_scantable@plt>:
  6d7a70:      	adrp	x16, 0x735000
  6d7a74:      	ldr	x17, [x16, #0x258]
  6d7a78:      	add	x16, x16, #0x258
  6d7a7c:      	br	x17

00000000006d7a80 <pthread_once@plt>:
  6d7a80:      	adrp	x16, 0x735000
  6d7a84:      	ldr	x17, [x16, #0x260]
  6d7a88:      	add	x16, x16, #0x260
  6d7a8c:      	br	x17

00000000006d7a90 <ff_rl_init@plt>:
  6d7a90:      	adrp	x16, 0x735000
  6d7a94:      	ldr	x17, [x16, #0x268]
  6d7a98:      	add	x16, x16, #0x268
  6d7a9c:      	br	x17

00000000006d7aa0 <ff_msmpeg4_coded_block_pred@plt>:
  6d7aa0:      	adrp	x16, 0x735000
  6d7aa4:      	ldr	x17, [x16, #0x270]
  6d7aa8:      	add	x16, x16, #0x270
  6d7aac:      	br	x17

00000000006d7ab0 <ff_msmpeg4_pred_dc@plt>:
  6d7ab0:      	adrp	x16, 0x735000
  6d7ab4:      	ldr	x17, [x16, #0x278]
  6d7ab8:      	add	x16, x16, #0x278
  6d7abc:      	br	x17

00000000006d7ac0 <ff_mediacodec_surface_ref@plt>:
  6d7ac0:      	adrp	x16, 0x735000
  6d7ac4:      	ldr	x17, [x16, #0x280]
  6d7ac8:      	add	x16, x16, #0x280
  6d7acc:      	br	x17

00000000006d7ad0 <ff_jni_get_env@plt>:
  6d7ad0:      	adrp	x16, 0x735000
  6d7ad4:      	ldr	x17, [x16, #0x288]
  6d7ad8:      	add	x16, x16, #0x288
  6d7adc:      	br	x17

00000000006d7ae0 <av_log@plt>:
  6d7ae0:      	adrp	x16, 0x735000
  6d7ae4:      	ldr	x17, [x16, #0x290]
  6d7ae8:      	add	x16, x16, #0x290
  6d7aec:      	br	x17

00000000006d7af0 <ff_mediacodec_surface_unref@plt>:
  6d7af0:      	adrp	x16, 0x735000
  6d7af4:      	ldr	x17, [x16, #0x298]
  6d7af8:      	add	x16, x16, #0x298
  6d7afc:      	br	x17

00000000006d7b00 <av_free@plt>:
  6d7b00:      	adrp	x16, 0x735000
  6d7b04:      	ldr	x17, [x16, #0x2a0]
  6d7b08:      	add	x16, x16, #0x2a0
  6d7b0c:      	br	x17

00000000006d7b10 <ff_dovi_configure_ext@plt>:
  6d7b10:      	adrp	x16, 0x735000
  6d7b14:      	ldr	x17, [x16, #0x2a8]
  6d7b18:      	add	x16, x16, #0x2a8
  6d7b1c:      	br	x17

00000000006d7b20 <ff_dovi_guess_profile_hevc@plt>:
  6d7b20:      	adrp	x16, 0x735000
  6d7b24:      	ldr	x17, [x16, #0x2b0]
  6d7b28:      	add	x16, x16, #0x2b0
  6d7b2c:      	br	x17

00000000006d7b30 <av_dovi_alloc@plt>:
  6d7b30:      	adrp	x16, 0x735000
  6d7b34:      	ldr	x17, [x16, #0x2b8]
  6d7b38:      	add	x16, x16, #0x2b8
  6d7b3c:      	br	x17

00000000006d7b40 <av_packet_side_data_add@plt>:
  6d7b40:      	adrp	x16, 0x735000
  6d7b44:      	ldr	x17, [x16, #0x2c0]
  6d7b48:      	add	x16, x16, #0x2c0
  6d7b4c:      	br	x17

00000000006d7b50 <abort@plt>:
  6d7b50:      	adrp	x16, 0x735000
  6d7b54:      	ldr	x17, [x16, #0x2c8]
  6d7b58:      	add	x16, x16, #0x2c8
  6d7b5c:      	br	x17

00000000006d7b60 <avcodec_parameters_alloc@plt>:
  6d7b60:      	adrp	x16, 0x735000
  6d7b64:      	ldr	x17, [x16, #0x2d0]
  6d7b68:      	add	x16, x16, #0x2d0
  6d7b6c:      	br	x17

00000000006d7b70 <avcodec_parameters_from_context@plt>:
  6d7b70:      	adrp	x16, 0x735000
  6d7b74:      	ldr	x17, [x16, #0x2d8]
  6d7b78:      	add	x16, x16, #0x2d8
  6d7b7c:      	br	x17

00000000006d7b80 <av_frame_side_data_get_c@plt>:
  6d7b80:      	adrp	x16, 0x735000
  6d7b84:      	ldr	x17, [x16, #0x2e0]
  6d7b88:      	add	x16, x16, #0x2e0
  6d7b8c:      	br	x17

00000000006d7b90 <avcodec_parameters_to_context@plt>:
  6d7b90:      	adrp	x16, 0x735000
  6d7b94:      	ldr	x17, [x16, #0x2e8]
  6d7b98:      	add	x16, x16, #0x2e8
  6d7b9c:      	br	x17

00000000006d7ba0 <avcodec_parameters_free@plt>:
  6d7ba0:      	adrp	x16, 0x735000
  6d7ba4:      	ldr	x17, [x16, #0x2f0]
  6d7ba8:      	add	x16, x16, #0x2f0
  6d7bac:      	br	x17

00000000006d7bb0 <ff_dovi_rpu_generate@plt>:
  6d7bb0:      	adrp	x16, 0x735000
  6d7bb4:      	ldr	x17, [x16, #0x2f8]
  6d7bb8:      	add	x16, x16, #0x2f8
  6d7bbc:      	br	x17

00000000006d7bc0 <memcmp@plt>:
  6d7bc0:      	adrp	x16, 0x735000
  6d7bc4:      	ldr	x17, [x16, #0x300]
  6d7bc8:      	add	x16, x16, #0x300
  6d7bcc:      	br	x17

00000000006d7bd0 <ff_refstruct_unref@plt>:
  6d7bd0:      	adrp	x16, 0x735000
  6d7bd4:      	ldr	x17, [x16, #0x308]
  6d7bd8:      	add	x16, x16, #0x308
  6d7bdc:      	br	x17

00000000006d7be0 <av_fast_padded_malloc@plt>:
  6d7be0:      	adrp	x16, 0x735000
  6d7be4:      	ldr	x17, [x16, #0x310]
  6d7be8:      	add	x16, x16, #0x310
  6d7bec:      	br	x17

00000000006d7bf0 <memcpy@plt>:
  6d7bf0:      	adrp	x16, 0x735000
  6d7bf4:      	ldr	x17, [x16, #0x318]
  6d7bf8:      	add	x16, x16, #0x318
  6d7bfc:      	br	x17

00000000006d7c00 <av_crc_get_table@plt>:
  6d7c00:      	adrp	x16, 0x735000
  6d7c04:      	ldr	x17, [x16, #0x320]
  6d7c08:      	add	x16, x16, #0x320
  6d7c0c:      	br	x17

00000000006d7c10 <av_crc@plt>:
  6d7c10:      	adrp	x16, 0x735000
  6d7c14:      	ldr	x17, [x16, #0x328]
  6d7c18:      	add	x16, x16, #0x328
  6d7c1c:      	br	x17

00000000006d7c20 <av_malloc@plt>:
  6d7c20:      	adrp	x16, 0x735000
  6d7c24:      	ldr	x17, [x16, #0x330]
  6d7c28:      	add	x16, x16, #0x330
  6d7c2c:      	br	x17

00000000006d7c30 <ff_copy_bits@plt>:
  6d7c30:      	adrp	x16, 0x735000
  6d7c34:      	ldr	x17, [x16, #0x338]
  6d7c38:      	add	x16, x16, #0x338
  6d7c3c:      	br	x17

00000000006d7c40 <ff_refstruct_alloc_ext_c@plt>:
  6d7c40:      	adrp	x16, 0x735000
  6d7c44:      	ldr	x17, [x16, #0x340]
  6d7c48:      	add	x16, x16, #0x340
  6d7c4c:      	br	x17

00000000006d7c50 <av_mul_q@plt>:
  6d7c50:      	adrp	x16, 0x735000
  6d7c54:      	ldr	x17, [x16, #0x348]
  6d7c58:      	add	x16, x16, #0x348
  6d7c5c:      	br	x17

00000000006d7c60 <ff_bsf_get_packet_ref@plt>:
  6d7c60:      	adrp	x16, 0x735000
  6d7c64:      	ldr	x17, [x16, #0x350]
  6d7c68:      	add	x16, x16, #0x350
  6d7c6c:      	br	x17

00000000006d7c70 <av_packet_get_side_data@plt>:
  6d7c70:      	adrp	x16, 0x735000
  6d7c74:      	ldr	x17, [x16, #0x358]
  6d7c78:      	add	x16, x16, #0x358
  6d7c7c:      	br	x17

00000000006d7c80 <ff_cbs_read_packet_side_data@plt>:
  6d7c80:      	adrp	x16, 0x735000
  6d7c84:      	ldr	x17, [x16, #0x360]
  6d7c88:      	add	x16, x16, #0x360
  6d7c8c:      	br	x17

00000000006d7c90 <ff_cbs_write_fragment_data@plt>:
  6d7c90:      	adrp	x16, 0x735000
  6d7c94:      	ldr	x17, [x16, #0x368]
  6d7c98:      	add	x16, x16, #0x368
  6d7c9c:      	br	x17

00000000006d7ca0 <av_packet_new_side_data@plt>:
  6d7ca0:      	adrp	x16, 0x735000
  6d7ca4:      	ldr	x17, [x16, #0x370]
  6d7ca8:      	add	x16, x16, #0x370
  6d7cac:      	br	x17

00000000006d7cb0 <ff_cbs_fragment_reset@plt>:
  6d7cb0:      	adrp	x16, 0x735000
  6d7cb4:      	ldr	x17, [x16, #0x378]
  6d7cb8:      	add	x16, x16, #0x378
  6d7cbc:      	br	x17

00000000006d7cc0 <ff_cbs_read_packet@plt>:
  6d7cc0:      	adrp	x16, 0x735000
  6d7cc4:      	ldr	x17, [x16, #0x380]
  6d7cc8:      	add	x16, x16, #0x380
  6d7ccc:      	br	x17

00000000006d7cd0 <ff_cbs_write_packet@plt>:
  6d7cd0:      	adrp	x16, 0x735000
  6d7cd4:      	ldr	x17, [x16, #0x388]
  6d7cd8:      	add	x16, x16, #0x388
  6d7cdc:      	br	x17

00000000006d7ce0 <av_packet_unref@plt>:
  6d7ce0:      	adrp	x16, 0x735000
  6d7ce4:      	ldr	x17, [x16, #0x390]
  6d7ce8:      	add	x16, x16, #0x390
  6d7cec:      	br	x17

00000000006d7cf0 <ff_cbs_bsf_generic_init@plt>:
  6d7cf0:      	adrp	x16, 0x735000
  6d7cf4:      	ldr	x17, [x16, #0x398]
  6d7cf8:      	add	x16, x16, #0x398
  6d7cfc:      	br	x17

00000000006d7d00 <ff_cbs_init@plt>:
  6d7d00:      	adrp	x16, 0x735000
  6d7d04:      	ldr	x17, [x16, #0x3a0]
  6d7d08:      	add	x16, x16, #0x3a0
  6d7d0c:      	br	x17

00000000006d7d10 <ff_cbs_read_extradata@plt>:
  6d7d10:      	adrp	x16, 0x735000
  6d7d14:      	ldr	x17, [x16, #0x3a8]
  6d7d18:      	add	x16, x16, #0x3a8
  6d7d1c:      	br	x17

00000000006d7d20 <ff_cbs_write_extradata@plt>:
  6d7d20:      	adrp	x16, 0x735000
  6d7d24:      	ldr	x17, [x16, #0x3b0]
  6d7d28:      	add	x16, x16, #0x3b0
  6d7d2c:      	br	x17

00000000006d7d30 <ff_cbs_bsf_generic_close@plt>:
  6d7d30:      	adrp	x16, 0x735000
  6d7d34:      	ldr	x17, [x16, #0x3b8]
  6d7d38:      	add	x16, x16, #0x3b8
  6d7d3c:      	br	x17

00000000006d7d40 <ff_cbs_fragment_free@plt>:
  6d7d40:      	adrp	x16, 0x735000
  6d7d44:      	ldr	x17, [x16, #0x3c0]
  6d7d48:      	add	x16, x16, #0x3c0
  6d7d4c:      	br	x17

00000000006d7d50 <ff_cbs_close@plt>:
  6d7d50:      	adrp	x16, 0x735000
  6d7d54:      	ldr	x17, [x16, #0x3c8]
  6d7d58:      	add	x16, x16, #0x3c8
  6d7d5c:      	br	x17

00000000006d7d60 <ff_h274_apply_film_grain@plt>:
  6d7d60:      	adrp	x16, 0x735000
  6d7d64:      	ldr	x17, [x16, #0x3d0]
  6d7d68:      	add	x16, x16, #0x3d0
  6d7d6c:      	br	x17

00000000006d7d70 <av_image_copy_plane@plt>:
  6d7d70:      	adrp	x16, 0x735000
  6d7d74:      	ldr	x17, [x16, #0x3d8]
  6d7d78:      	add	x16, x16, #0x3d8
  6d7d7c:      	br	x17

00000000006d7d80 <ff_v4l2_format_avcodec_to_v4l2@plt>:
  6d7d80:      	adrp	x16, 0x735000
  6d7d84:      	ldr	x17, [x16, #0x3e0]
  6d7d88:      	add	x16, x16, #0x3e0
  6d7d8c:      	br	x17

00000000006d7d90 <ff_v4l2_format_avfmt_to_v4l2@plt>:
  6d7d90:      	adrp	x16, 0x735000
  6d7d94:      	ldr	x17, [x16, #0x3e8]
  6d7d98:      	add	x16, x16, #0x3e8
  6d7d9c:      	br	x17

00000000006d7da0 <ff_v4l2_format_v4l2_to_avfmt@plt>:
  6d7da0:      	adrp	x16, 0x735000
  6d7da4:      	ldr	x17, [x16, #0x3f0]
  6d7da8:      	add	x16, x16, #0x3f0
  6d7dac:      	br	x17

00000000006d7db0 <ff_rl_init_level_run@plt>:
  6d7db0:      	adrp	x16, 0x735000
  6d7db4:      	ldr	x17, [x16, #0x3f8]
  6d7db8:      	add	x16, x16, #0x3f8
  6d7dbc:      	br	x17

00000000006d7dc0 <ff_rl_init_vlc@plt>:
  6d7dc0:      	adrp	x16, 0x735000
  6d7dc4:      	ldr	x17, [x16, #0x400]
  6d7dc8:      	add	x16, x16, #0x400
  6d7dcc:      	br	x17

00000000006d7dd0 <memset@plt>:
  6d7dd0:      	adrp	x16, 0x735000
  6d7dd4:      	ldr	x17, [x16, #0x408]
  6d7dd8:      	add	x16, x16, #0x408
  6d7ddc:      	br	x17

00000000006d7de0 <ff_vlc_init_sparse@plt>:
  6d7de0:      	adrp	x16, 0x735000
  6d7de4:      	ldr	x17, [x16, #0x410]
  6d7de8:      	add	x16, x16, #0x410
  6d7dec:      	br	x17

00000000006d7df0 <av_reallocp_array@plt>:
  6d7df0:      	adrp	x16, 0x735000
  6d7df4:      	ldr	x17, [x16, #0x418]
  6d7df8:      	add	x16, x16, #0x418
  6d7dfc:      	br	x17

00000000006d7e00 <ff_hap_parse_section_header@plt>:
  6d7e00:      	adrp	x16, 0x735000
  6d7e04:      	ldr	x17, [x16, #0x420]
  6d7e08:      	add	x16, x16, #0x420
  6d7e0c:      	br	x17

00000000006d7e10 <avcodec_default_execute@plt>:
  6d7e10:      	adrp	x16, 0x735000
  6d7e14:      	ldr	x17, [x16, #0x428]
  6d7e18:      	add	x16, x16, #0x428
  6d7e1c:      	br	x17

00000000006d7e20 <avcodec_open2@plt>:
  6d7e20:      	adrp	x16, 0x735000
  6d7e24:      	ldr	x17, [x16, #0x430]
  6d7e28:      	add	x16, x16, #0x430
  6d7e2c:      	br	x17

00000000006d7e30 <av_dict_get@plt>:
  6d7e30:      	adrp	x16, 0x735000
  6d7e34:      	ldr	x17, [x16, #0x438]
  6d7e38:      	add	x16, x16, #0x438
  6d7e3c:      	br	x17

00000000006d7e40 <av_opt_set@plt>:
  6d7e40:      	adrp	x16, 0x735000
  6d7e44:      	ldr	x17, [x16, #0x440]
  6d7e48:      	add	x16, x16, #0x440
  6d7e4c:      	br	x17

00000000006d7e50 <av_match_list@plt>:
  6d7e50:      	adrp	x16, 0x735000
  6d7e54:      	ldr	x17, [x16, #0x448]
  6d7e58:      	add	x16, x16, #0x448
  6d7e5c:      	br	x17

00000000006d7e60 <av_codec_is_decoder@plt>:
  6d7e60:      	adrp	x16, 0x735000
  6d7e64:      	ldr	x17, [x16, #0x450]
  6d7e68:      	add	x16, x16, #0x450
  6d7e6c:      	br	x17

00000000006d7e70 <ff_decode_internal_alloc@plt>:
  6d7e70:      	adrp	x16, 0x735000
  6d7e74:      	ldr	x17, [x16, #0x458]
  6d7e78:      	add	x16, x16, #0x458
  6d7e7c:      	br	x17

00000000006d7e80 <ff_encode_internal_alloc@plt>:
  6d7e80:      	adrp	x16, 0x735000
  6d7e84:      	ldr	x17, [x16, #0x460]
  6d7e88:      	add	x16, x16, #0x460
  6d7e8c:      	br	x17

00000000006d7e90 <av_frame_alloc@plt>:
  6d7e90:      	adrp	x16, 0x735000
  6d7e94:      	ldr	x17, [x16, #0x468]
  6d7e98:      	add	x16, x16, #0x468
  6d7e9c:      	br	x17

00000000006d7ea0 <av_packet_alloc@plt>:
  6d7ea0:      	adrp	x16, 0x735000
  6d7ea4:      	ldr	x17, [x16, #0x470]
  6d7ea8:      	add	x16, x16, #0x470
  6d7eac:      	br	x17

00000000006d7eb0 <av_opt_set_defaults@plt>:
  6d7eb0:      	adrp	x16, 0x735000
  6d7eb4:      	ldr	x17, [x16, #0x478]
  6d7eb8:      	add	x16, x16, #0x478
  6d7ebc:      	br	x17

00000000006d7ec0 <av_opt_set_dict2@plt>:
  6d7ec0:      	adrp	x16, 0x735000
  6d7ec4:      	ldr	x17, [x16, #0x480]
  6d7ec8:      	add	x16, x16, #0x480
  6d7ecc:      	br	x17

00000000006d7ed0 <ff_set_dimensions@plt>:
  6d7ed0:      	adrp	x16, 0x735000
  6d7ed4:      	ldr	x17, [x16, #0x488]
  6d7ed8:      	add	x16, x16, #0x488
  6d7edc:      	br	x17

00000000006d7ee0 <av_image_check_sar@plt>:
  6d7ee0:      	adrp	x16, 0x735000
  6d7ee4:      	ldr	x17, [x16, #0x490]
  6d7ee8:      	add	x16, x16, #0x490
  6d7eec:      	br	x17

00000000006d7ef0 <av_channel_layout_check@plt>:
  6d7ef0:      	adrp	x16, 0x735000
  6d7ef4:      	ldr	x17, [x16, #0x498]
  6d7ef8:      	add	x16, x16, #0x498
  6d7efc:      	br	x17

00000000006d7f00 <avcodec_descriptor_get@plt>:
  6d7f00:      	adrp	x16, 0x735000
  6d7f04:      	ldr	x17, [x16, #0x4a0]
  6d7f08:      	add	x16, x16, #0x4a0
  6d7f0c:      	br	x17

00000000006d7f10 <av_codec_is_encoder@plt>:
  6d7f10:      	adrp	x16, 0x735000
  6d7f14:      	ldr	x17, [x16, #0x4a8]
  6d7f18:      	add	x16, x16, #0x4a8
  6d7f1c:      	br	x17

00000000006d7f20 <ff_encode_preinit@plt>:
  6d7f20:      	adrp	x16, 0x735000
  6d7f24:      	ldr	x17, [x16, #0x4b0]
  6d7f28:      	add	x16, x16, #0x4b0
  6d7f2c:      	br	x17

00000000006d7f30 <ff_decode_preinit@plt>:
  6d7f30:      	adrp	x16, 0x735000
  6d7f34:      	ldr	x17, [x16, #0x4b8]
  6d7f38:      	add	x16, x16, #0x4b8
  6d7f3c:      	br	x17

00000000006d7f40 <ff_thread_init@plt>:
  6d7f40:      	adrp	x16, 0x735000
  6d7f44:      	ldr	x17, [x16, #0x4c0]
  6d7f48:      	add	x16, x16, #0x4c0
  6d7f4c:      	br	x17

00000000006d7f50 <ff_codec_close@plt>:
  6d7f50:      	adrp	x16, 0x735000
  6d7f54:      	ldr	x17, [x16, #0x4c8]
  6d7f58:      	add	x16, x16, #0x4c8
  6d7f5c:      	br	x17

00000000006d7f60 <avcodec_find_decoder@plt>:
  6d7f60:      	adrp	x16, 0x735000
  6d7f64:      	ldr	x17, [x16, #0x4d0]
  6d7f68:      	add	x16, x16, #0x4d0
  6d7f6c:      	br	x17

00000000006d7f70 <avcodec_find_encoder@plt>:
  6d7f70:      	adrp	x16, 0x735000
  6d7f74:      	ldr	x17, [x16, #0x4d8]
  6d7f78:      	add	x16, x16, #0x4d8
  6d7f7c:      	br	x17

00000000006d7f80 <avcodec_is_open@plt>:
  6d7f80:      	adrp	x16, 0x735000
  6d7f84:      	ldr	x17, [x16, #0x4e0]
  6d7f88:      	add	x16, x16, #0x4e0
  6d7f8c:      	br	x17

00000000006d7f90 <pthread_mutex_lock@plt>:
  6d7f90:      	adrp	x16, 0x735000
  6d7f94:      	ldr	x17, [x16, #0x4e8]
  6d7f98:      	add	x16, x16, #0x4e8
  6d7f9c:      	br	x17

00000000006d7fa0 <pthread_mutex_unlock@plt>:
  6d7fa0:      	adrp	x16, 0x735000
  6d7fa4:      	ldr	x17, [x16, #0x4f0]
  6d7fa8:      	add	x16, x16, #0x4f0
  6d7fac:      	br	x17

00000000006d7fb0 <av_get_bits_per_sample@plt>:
  6d7fb0:      	adrp	x16, 0x735000
  6d7fb4:      	ldr	x17, [x16, #0x4f8]
  6d7fb8:      	add	x16, x16, #0x4f8
  6d7fbc:      	br	x17

00000000006d7fc0 <ff_frame_thread_encoder_free@plt>:
  6d7fc0:      	adrp	x16, 0x735000
  6d7fc4:      	ldr	x17, [x16, #0x500]
  6d7fc8:      	add	x16, x16, #0x500
  6d7fcc:      	br	x17

00000000006d7fd0 <ff_thread_free@plt>:
  6d7fd0:      	adrp	x16, 0x735000
  6d7fd4:      	ldr	x17, [x16, #0x508]
  6d7fd8:      	add	x16, x16, #0x508
  6d7fdc:      	br	x17

00000000006d7fe0 <av_frame_free@plt>:
  6d7fe0:      	adrp	x16, 0x735000
  6d7fe4:      	ldr	x17, [x16, #0x510]
  6d7fe8:      	add	x16, x16, #0x510
  6d7fec:      	br	x17

00000000006d7ff0 <av_packet_free@plt>:
  6d7ff0:      	adrp	x16, 0x735000
  6d7ff4:      	ldr	x17, [x16, #0x518]
  6d7ff8:      	add	x16, x16, #0x518
  6d7ffc:      	br	x17

00000000006d8000 <ff_decode_internal_uninit@plt>:
  6d8000:      	adrp	x16, 0x735000
  6d8004:      	ldr	x17, [x16, #0x520]
  6d8008:      	add	x16, x16, #0x520
  6d800c:      	br	x17

00000000006d8010 <ff_hwaccel_uninit@plt>:
  6d8010:      	adrp	x16, 0x735000
  6d8014:      	ldr	x17, [x16, #0x528]
  6d8018:      	add	x16, x16, #0x528
  6d801c:      	br	x17

00000000006d8020 <av_bsf_free@plt>:
  6d8020:      	adrp	x16, 0x735000
  6d8024:      	ldr	x17, [x16, #0x530]
  6d8028:      	add	x16, x16, #0x530
  6d802c:      	br	x17

00000000006d8030 <av_channel_layout_uninit@plt>:
  6d8030:      	adrp	x16, 0x735000
  6d8034:      	ldr	x17, [x16, #0x538]
  6d8038:      	add	x16, x16, #0x538
  6d803c:      	br	x17

00000000006d8040 <av_frame_side_data_free@plt>:
  6d8040:      	adrp	x16, 0x735000
  6d8044:      	ldr	x17, [x16, #0x540]
  6d8048:      	add	x16, x16, #0x540
  6d804c:      	br	x17

00000000006d8050 <av_buffer_unref@plt>:
  6d8050:      	adrp	x16, 0x735000
  6d8054:      	ldr	x17, [x16, #0x548]
  6d8058:      	add	x16, x16, #0x548
  6d805c:      	br	x17

00000000006d8060 <av_opt_free@plt>:
  6d8060:      	adrp	x16, 0x735000
  6d8064:      	ldr	x17, [x16, #0x550]
  6d8068:      	add	x16, x16, #0x550
  6d806c:      	br	x17

00000000006d8070 <avcodec_flush_buffers@plt>:
  6d8070:      	adrp	x16, 0x735000
  6d8074:      	ldr	x17, [x16, #0x558]
  6d8078:      	add	x16, x16, #0x558
  6d807c:      	br	x17

00000000006d8080 <ff_decode_flush_buffers@plt>:
  6d8080:      	adrp	x16, 0x735000
  6d8084:      	ldr	x17, [x16, #0x560]
  6d8088:      	add	x16, x16, #0x560
  6d808c:      	br	x17

00000000006d8090 <ff_encode_flush_buffers@plt>:
  6d8090:      	adrp	x16, 0x735000
  6d8094:      	ldr	x17, [x16, #0x568]
  6d8098:      	add	x16, x16, #0x568
  6d809c:      	br	x17

00000000006d80a0 <av_frame_unref@plt>:
  6d80a0:      	adrp	x16, 0x735000
  6d80a4:      	ldr	x17, [x16, #0x570]
  6d80a8:      	add	x16, x16, #0x570
  6d80ac:      	br	x17

00000000006d80b0 <ff_thread_flush@plt>:
  6d80b0:      	adrp	x16, 0x735000
  6d80b4:      	ldr	x17, [x16, #0x578]
  6d80b8:      	add	x16, x16, #0x578
  6d80bc:      	br	x17

00000000006d80c0 <avsubtitle_free@plt>:
  6d80c0:      	adrp	x16, 0x735000
  6d80c4:      	ldr	x17, [x16, #0x580]
  6d80c8:      	add	x16, x16, #0x580
  6d80cc:      	br	x17

00000000006d80d0 <avcodec_string@plt>:
  6d80d0:      	adrp	x16, 0x735000
  6d80d4:      	ldr	x17, [x16, #0x588]
  6d80d8:      	add	x16, x16, #0x588
  6d80dc:      	br	x17

00000000006d80e0 <av_bprint_init_for_buffer@plt>:
  6d80e0:      	adrp	x16, 0x735000
  6d80e4:      	ldr	x17, [x16, #0x590]
  6d80e8:      	add	x16, x16, #0x590
  6d80ec:      	br	x17

00000000006d80f0 <av_get_media_type_string@plt>:
  6d80f0:      	adrp	x16, 0x735000
  6d80f4:      	ldr	x17, [x16, #0x598]
  6d80f8:      	add	x16, x16, #0x598
  6d80fc:      	br	x17

00000000006d8100 <avcodec_get_name@plt>:
  6d8100:      	adrp	x16, 0x735000
  6d8104:      	ldr	x17, [x16, #0x5a0]
  6d8108:      	add	x16, x16, #0x5a0
  6d810c:      	br	x17

00000000006d8110 <avcodec_profile_name@plt>:
  6d8110:      	adrp	x16, 0x735000
  6d8114:      	ldr	x17, [x16, #0x5a8]
  6d8118:      	add	x16, x16, #0x5a8
  6d811c:      	br	x17

00000000006d8120 <av_bprintf@plt>:
  6d8120:      	adrp	x16, 0x735000
  6d8124:      	ldr	x17, [x16, #0x5b0]
  6d8128:      	add	x16, x16, #0x5b0
  6d812c:      	br	x17

00000000006d8130 <strcmp@plt>:
  6d8130:      	adrp	x16, 0x735000
  6d8134:      	ldr	x17, [x16, #0x5b8]
  6d8138:      	add	x16, x16, #0x5b8
  6d813c:      	br	x17

00000000006d8140 <av_log_get_level@plt>:
  6d8140:      	adrp	x16, 0x735000
  6d8144:      	ldr	x17, [x16, #0x5c0]
  6d8148:      	add	x16, x16, #0x5c0
  6d814c:      	br	x17

00000000006d8150 <av_fourcc_make_string@plt>:
  6d8150:      	adrp	x16, 0x735000
  6d8154:      	ldr	x17, [x16, #0x5c8]
  6d8158:      	add	x16, x16, #0x5c8
  6d815c:      	br	x17

00000000006d8160 <av_get_pix_fmt_name@plt>:
  6d8160:      	adrp	x16, 0x735000
  6d8164:      	ldr	x17, [x16, #0x5d0]
  6d8168:      	add	x16, x16, #0x5d0
  6d816c:      	br	x17

00000000006d8170 <av_gcd@plt>:
  6d8170:      	adrp	x16, 0x735000
  6d8174:      	ldr	x17, [x16, #0x5d8]
  6d8178:      	add	x16, x16, #0x5d8
  6d817c:      	br	x17

00000000006d8180 <av_channel_layout_describe_bprint@plt>:
  6d8180:      	adrp	x16, 0x735000
  6d8184:      	ldr	x17, [x16, #0x5e0]
  6d8188:      	add	x16, x16, #0x5e0
  6d818c:      	br	x17

00000000006d8190 <av_get_sample_fmt_name@plt>:
  6d8190:      	adrp	x16, 0x735000
  6d8194:      	ldr	x17, [x16, #0x5e8]
  6d8198:      	add	x16, x16, #0x5e8
  6d819c:      	br	x17

00000000006d81a0 <av_get_bytes_per_sample@plt>:
  6d81a0:      	adrp	x16, 0x735000
  6d81a4:      	ldr	x17, [x16, #0x5f0]
  6d81a8:      	add	x16, x16, #0x5f0
  6d81ac:      	br	x17

00000000006d81b0 <av_bprint_chars@plt>:
  6d81b0:      	adrp	x16, 0x735000
  6d81b4:      	ldr	x17, [x16, #0x5f8]
  6d81b8:      	add	x16, x16, #0x5f8
  6d81bc:      	br	x17

00000000006d81c0 <av_pix_fmt_desc_get@plt>:
  6d81c0:      	adrp	x16, 0x735000
  6d81c4:      	ldr	x17, [x16, #0x600]
  6d81c8:      	add	x16, x16, #0x600
  6d81cc:      	br	x17

00000000006d81d0 <av_color_range_name@plt>:
  6d81d0:      	adrp	x16, 0x735000
  6d81d4:      	ldr	x17, [x16, #0x608]
  6d81d8:      	add	x16, x16, #0x608
  6d81dc:      	br	x17

00000000006d81e0 <av_color_space_name@plt>:
  6d81e0:      	adrp	x16, 0x735000
  6d81e4:      	ldr	x17, [x16, #0x610]
  6d81e8:      	add	x16, x16, #0x610
  6d81ec:      	br	x17

00000000006d81f0 <av_color_primaries_name@plt>:
  6d81f0:      	adrp	x16, 0x735000
  6d81f4:      	ldr	x17, [x16, #0x618]
  6d81f8:      	add	x16, x16, #0x618
  6d81fc:      	br	x17

00000000006d8200 <av_color_transfer_name@plt>:
  6d8200:      	adrp	x16, 0x735000
  6d8204:      	ldr	x17, [x16, #0x620]
  6d8208:      	add	x16, x16, #0x620
  6d820c:      	br	x17

00000000006d8210 <av_chroma_location_name@plt>:
  6d8210:      	adrp	x16, 0x735000
  6d8214:      	ldr	x17, [x16, #0x628]
  6d8218:      	add	x16, x16, #0x628
  6d821c:      	br	x17

00000000006d8220 <av_reduce@plt>:
  6d8220:      	adrp	x16, 0x735000
  6d8224:      	ldr	x17, [x16, #0x630]
  6d8228:      	add	x16, x16, #0x630
  6d822c:      	br	x17

00000000006d8230 <avcodec_receive_frame@plt>:
  6d8230:      	adrp	x16, 0x735000
  6d8234:      	ldr	x17, [x16, #0x638]
  6d8238:      	add	x16, x16, #0x638
  6d823c:      	br	x17

00000000006d8240 <ff_decode_receive_frame@plt>:
  6d8240:      	adrp	x16, 0x735000
  6d8244:      	ldr	x17, [x16, #0x640]
  6d8248:      	add	x16, x16, #0x640
  6d824c:      	br	x17

00000000006d8250 <ff_encode_receive_frame@plt>:
  6d8250:      	adrp	x16, 0x735000
  6d8254:      	ldr	x17, [x16, #0x648]
  6d8258:      	add	x16, x16, #0x648
  6d825c:      	br	x17

00000000006d8260 <ff_default_get_supported_config@plt>:
  6d8260:      	adrp	x16, 0x735000
  6d8264:      	ldr	x17, [x16, #0x650]
  6d8268:      	add	x16, x16, #0x650
  6d826c:      	br	x17

00000000006d8270 <avcodec_get_supported_config@plt>:
  6d8270:      	adrp	x16, 0x735000
  6d8274:      	ldr	x17, [x16, #0x658]
  6d8278:      	add	x16, x16, #0x658
  6d827c:      	br	x17

00000000006d8280 <av_image_check_size2@plt>:
  6d8280:      	adrp	x16, 0x735000
  6d8284:      	ldr	x17, [x16, #0x660]
  6d8288:      	add	x16, x16, #0x660
  6d828c:      	br	x17

00000000006d8290 <ff_mpa_l2_select_table@plt>:
  6d8290:      	adrp	x16, 0x735000
  6d8294:      	ldr	x17, [x16, #0x668]
  6d8298:      	add	x16, x16, #0x668
  6d829c:      	br	x17

00000000006d82a0 <av_fast_mallocz@plt>:
  6d82a0:      	adrp	x16, 0x735000
  6d82a4:      	ldr	x17, [x16, #0x670]
  6d82a8:      	add	x16, x16, #0x670
  6d82ac:      	br	x17

00000000006d82b0 <av_fast_padded_mallocz@plt>:
  6d82b0:      	adrp	x16, 0x735000
  6d82b4:      	ldr	x17, [x16, #0x678]
  6d82b8:      	add	x16, x16, #0x678
  6d82bc:      	br	x17

00000000006d82c0 <av_fast_malloc@plt>:
  6d82c0:      	adrp	x16, 0x735000
  6d82c4:      	ldr	x17, [x16, #0x680]
  6d82c8:      	add	x16, x16, #0x680
  6d82cc:      	br	x17

00000000006d82d0 <ff_set_sar@plt>:
  6d82d0:      	adrp	x16, 0x735000
  6d82d4:      	ldr	x17, [x16, #0x688]
  6d82d8:      	add	x16, x16, #0x688
  6d82dc:      	br	x17

00000000006d82e0 <ff_side_data_update_matrix_encoding@plt>:
  6d82e0:      	adrp	x16, 0x735000
  6d82e4:      	ldr	x17, [x16, #0x690]
  6d82e8:      	add	x16, x16, #0x690
  6d82ec:      	br	x17

00000000006d82f0 <av_frame_get_side_data@plt>:
  6d82f0:      	adrp	x16, 0x735000
  6d82f4:      	ldr	x17, [x16, #0x698]
  6d82f8:      	add	x16, x16, #0x698
  6d82fc:      	br	x17

00000000006d8300 <av_frame_new_side_data@plt>:
  6d8300:      	adrp	x16, 0x735000
  6d8304:      	ldr	x17, [x16, #0x6a0]
  6d8308:      	add	x16, x16, #0x6a0
  6d830c:      	br	x17

00000000006d8310 <avcodec_align_dimensions2@plt>:
  6d8310:      	adrp	x16, 0x735000
  6d8314:      	ldr	x17, [x16, #0x6a8]
  6d8318:      	add	x16, x16, #0x6a8
  6d831c:      	br	x17

00000000006d8320 <av_samples_get_buffer_size@plt>:
  6d8320:      	adrp	x16, 0x735000
  6d8324:      	ldr	x17, [x16, #0x6b0]
  6d8328:      	add	x16, x16, #0x6b0
  6d832c:      	br	x17

00000000006d8330 <av_sample_fmt_is_planar@plt>:
  6d8330:      	adrp	x16, 0x735000
  6d8334:      	ldr	x17, [x16, #0x6b8]
  6d8338:      	add	x16, x16, #0x6b8
  6d833c:      	br	x17

00000000006d8340 <av_calloc@plt>:
  6d8340:      	adrp	x16, 0x735000
  6d8344:      	ldr	x17, [x16, #0x6c0]
  6d8348:      	add	x16, x16, #0x6c0
  6d834c:      	br	x17

00000000006d8350 <av_samples_fill_arrays@plt>:
  6d8350:      	adrp	x16, 0x735000
  6d8354:      	ldr	x17, [x16, #0x6c8]
  6d8358:      	add	x16, x16, #0x6c8
  6d835c:      	br	x17

00000000006d8360 <avpriv_codec_get_cap_skip_frame_fill_param@plt>:
  6d8360:      	adrp	x16, 0x735000
  6d8364:      	ldr	x17, [x16, #0x6d0]
  6d8368:      	add	x16, x16, #0x6d0
  6d836c:      	br	x17

00000000006d8370 <av_get_exact_bits_per_sample@plt>:
  6d8370:      	adrp	x16, 0x735000
  6d8374:      	ldr	x17, [x16, #0x6d8]
  6d8378:      	add	x16, x16, #0x6d8
  6d837c:      	br	x17

00000000006d8380 <av_get_audio_frame_duration@plt>:
  6d8380:      	adrp	x16, 0x735000
  6d8384:      	ldr	x17, [x16, #0x6e0]
  6d8388:      	add	x16, x16, #0x6e0
  6d838c:      	br	x17

00000000006d8390 <av_get_audio_frame_duration2@plt>:
  6d8390:      	adrp	x16, 0x735000
  6d8394:      	ldr	x17, [x16, #0x6e8]
  6d8398:      	add	x16, x16, #0x6e8
  6d839c:      	br	x17

00000000006d83a0 <av_xiphlacing@plt>:
  6d83a0:      	adrp	x16, 0x735000
  6d83a4:      	ldr	x17, [x16, #0x6f0]
  6d83a8:      	add	x16, x16, #0x6f0
  6d83ac:      	br	x17

00000000006d83b0 <ff_match_2uint16@plt>:
  6d83b0:      	adrp	x16, 0x735000
  6d83b4:      	ldr	x17, [x16, #0x6f8]
  6d83b8:      	add	x16, x16, #0x6f8
  6d83bc:      	br	x17

00000000006d83c0 <avcodec_get_hw_config@plt>:
  6d83c0:      	adrp	x16, 0x735000
  6d83c4:      	ldr	x17, [x16, #0x700]
  6d83c8:      	add	x16, x16, #0x700
  6d83cc:      	br	x17

00000000006d83d0 <ff_thread_ref_frame@plt>:
  6d83d0:      	adrp	x16, 0x735000
  6d83d4:      	ldr	x17, [x16, #0x708]
  6d83d8:      	add	x16, x16, #0x708
  6d83dc:      	br	x17

00000000006d83e0 <av_frame_ref@plt>:
  6d83e0:      	adrp	x16, 0x735000
  6d83e4:      	ldr	x17, [x16, #0x710]
  6d83e8:      	add	x16, x16, #0x710
  6d83ec:      	br	x17

00000000006d83f0 <ff_refstruct_ref@plt>:
  6d83f0:      	adrp	x16, 0x735000
  6d83f4:      	ldr	x17, [x16, #0x718]
  6d83f8:      	add	x16, x16, #0x718
  6d83fc:      	br	x17

00000000006d8400 <ff_thread_replace_frame@plt>:
  6d8400:      	adrp	x16, 0x735000
  6d8404:      	ldr	x17, [x16, #0x720]
  6d8408:      	add	x16, x16, #0x720
  6d840c:      	br	x17

00000000006d8410 <av_frame_replace@plt>:
  6d8410:      	adrp	x16, 0x735000
  6d8414:      	ldr	x17, [x16, #0x728]
  6d8418:      	add	x16, x16, #0x728
  6d841c:      	br	x17

00000000006d8420 <ff_refstruct_replace@plt>:
  6d8420:      	adrp	x16, 0x735000
  6d8424:      	ldr	x17, [x16, #0x730]
  6d8428:      	add	x16, x16, #0x730
  6d842c:      	br	x17

00000000006d8430 <avpriv_find_start_code@plt>:
  6d8430:      	adrp	x16, 0x735000
  6d8434:      	ldr	x17, [x16, #0x738]
  6d8438:      	add	x16, x16, #0x738
  6d843c:      	br	x17

00000000006d8440 <av_cpb_properties_alloc@plt>:
  6d8440:      	adrp	x16, 0x735000
  6d8444:      	ldr	x17, [x16, #0x740]
  6d8448:      	add	x16, x16, #0x740
  6d844c:      	br	x17

00000000006d8450 <av_get_bits_per_pixel@plt>:
  6d8450:      	adrp	x16, 0x735000
  6d8454:      	ldr	x17, [x16, #0x748]
  6d8458:      	add	x16, x16, #0x748
  6d845c:      	br	x17

00000000006d8460 <ff_v4l2_context_set_status@plt>:
  6d8460:      	adrp	x16, 0x735000
  6d8464:      	ldr	x17, [x16, #0x750]
  6d8468:      	add	x16, x16, #0x750
  6d846c:      	br	x17

00000000006d8470 <ioctl@plt>:
  6d8470:      	adrp	x16, 0x735000
  6d8474:      	ldr	x17, [x16, #0x758]
  6d8478:      	add	x16, x16, #0x758
  6d847c:      	br	x17

00000000006d8480 <__errno@plt>:
  6d8480:      	adrp	x16, 0x735000
  6d8484:      	ldr	x17, [x16, #0x760]
  6d8488:      	add	x16, x16, #0x760
  6d848c:      	br	x17

00000000006d8490 <ff_v4l2_buffer_avframe_to_buf@plt>:
  6d8490:      	adrp	x16, 0x735000
  6d8494:      	ldr	x17, [x16, #0x768]
  6d8498:      	add	x16, x16, #0x768
  6d849c:      	br	x17

00000000006d84a0 <ff_v4l2_buffer_enqueue@plt>:
  6d84a0:      	adrp	x16, 0x735000
  6d84a4:      	ldr	x17, [x16, #0x770]
  6d84a8:      	add	x16, x16, #0x770
  6d84ac:      	br	x17

00000000006d84b0 <ff_v4l2_buffer_avpkt_to_buf@plt>:
  6d84b0:      	adrp	x16, 0x735000
  6d84b4:      	ldr	x17, [x16, #0x778]
  6d84b8:      	add	x16, x16, #0x778
  6d84bc:      	br	x17

00000000006d84c0 <ff_v4l2_buffer_buf_to_avframe@plt>:
  6d84c0:      	adrp	x16, 0x735000
  6d84c4:      	ldr	x17, [x16, #0x780]
  6d84c8:      	add	x16, x16, #0x780
  6d84cc:      	br	x17

00000000006d84d0 <poll@plt>:
  6d84d0:      	adrp	x16, 0x735000
  6d84d4:      	ldr	x17, [x16, #0x788]
  6d84d8:      	add	x16, x16, #0x788
  6d84dc:      	br	x17

00000000006d84e0 <av_strerror@plt>:
  6d84e0:      	adrp	x16, 0x735000
  6d84e4:      	ldr	x17, [x16, #0x790]
  6d84e8:      	add	x16, x16, #0x790
  6d84ec:      	br	x17

00000000006d84f0 <ff_v4l2_m2m_codec_reinit@plt>:
  6d84f0:      	adrp	x16, 0x735000
  6d84f4:      	ldr	x17, [x16, #0x798]
  6d84f8:      	add	x16, x16, #0x798
  6d84fc:      	br	x17

00000000006d8500 <ff_v4l2_buffer_buf_to_avpkt@plt>:
  6d8500:      	adrp	x16, 0x735000
  6d8504:      	ldr	x17, [x16, #0x7a0]
  6d8508:      	add	x16, x16, #0x7a0
  6d850c:      	br	x17

00000000006d8510 <ff_v4l2_context_get_format@plt>:
  6d8510:      	adrp	x16, 0x735000
  6d8514:      	ldr	x17, [x16, #0x7a8]
  6d8518:      	add	x16, x16, #0x7a8
  6d851c:      	br	x17

00000000006d8520 <ff_v4l2_context_set_format@plt>:
  6d8520:      	adrp	x16, 0x735000
  6d8524:      	ldr	x17, [x16, #0x7b0]
  6d8528:      	add	x16, x16, #0x7b0
  6d852c:      	br	x17

00000000006d8530 <ff_v4l2_context_release@plt>:
  6d8530:      	adrp	x16, 0x735000
  6d8534:      	ldr	x17, [x16, #0x7b8]
  6d8538:      	add	x16, x16, #0x7b8
  6d853c:      	br	x17

00000000006d8540 <munmap@plt>:
  6d8540:      	adrp	x16, 0x735000
  6d8544:      	ldr	x17, [x16, #0x7c0]
  6d8548:      	add	x16, x16, #0x7c0
  6d854c:      	br	x17

00000000006d8550 <ff_v4l2_context_init@plt>:
  6d8550:      	adrp	x16, 0x735000
  6d8554:      	ldr	x17, [x16, #0x7c8]
  6d8558:      	add	x16, x16, #0x7c8
  6d855c:      	br	x17

00000000006d8560 <ff_v4l2_buffer_initialize@plt>:
  6d8560:      	adrp	x16, 0x735000
  6d8564:      	ldr	x17, [x16, #0x7d0]
  6d8568:      	add	x16, x16, #0x7d0
  6d856c:      	br	x17

00000000006d8570 <strerror@plt>:
  6d8570:      	adrp	x16, 0x735000
  6d8574:      	ldr	x17, [x16, #0x7d8]
  6d8578:      	add	x16, x16, #0x7d8
  6d857c:      	br	x17

00000000006d8580 <ff_j_rev_dct@plt>:
  6d8580:      	adrp	x16, 0x735000
  6d8584:      	ldr	x17, [x16, #0x7e0]
  6d8588:      	add	x16, x16, #0x7e0
  6d858c:      	br	x17

00000000006d8590 <ff_j_rev_dct4@plt>:
  6d8590:      	adrp	x16, 0x735000
  6d8594:      	ldr	x17, [x16, #0x7e8]
  6d8598:      	add	x16, x16, #0x7e8
  6d859c:      	br	x17

00000000006d85a0 <ff_j_rev_dct2@plt>:
  6d85a0:      	adrp	x16, 0x735000
  6d85a4:      	ldr	x17, [x16, #0x7f0]
  6d85a8:      	add	x16, x16, #0x7f0
  6d85ac:      	br	x17

00000000006d85b0 <ff_put_pixels_clamped_c@plt>:
  6d85b0:      	adrp	x16, 0x735000
  6d85b4:      	ldr	x17, [x16, #0x7f8]
  6d85b8:      	add	x16, x16, #0x7f8
  6d85bc:      	br	x17

00000000006d85c0 <ff_add_pixels_clamped_c@plt>:
  6d85c0:      	adrp	x16, 0x735000
  6d85c4:      	ldr	x17, [x16, #0x800]
  6d85c8:      	add	x16, x16, #0x800
  6d85cc:      	br	x17

00000000006d85d0 <ff_mpeg_update_thread_context@plt>:
  6d85d0:      	adrp	x16, 0x735000
  6d85d4:      	ldr	x17, [x16, #0x808]
  6d85d8:      	add	x16, x16, #0x808
  6d85dc:      	br	x17

00000000006d85e0 <ff_mpv_decode_init@plt>:
  6d85e0:      	adrp	x16, 0x735000
  6d85e4:      	ldr	x17, [x16, #0x810]
  6d85e8:      	add	x16, x16, #0x810
  6d85ec:      	br	x17

00000000006d85f0 <ff_mpeg12_init_vlcs@plt>:
  6d85f0:      	adrp	x16, 0x735000
  6d85f4:      	ldr	x17, [x16, #0x818]
  6d85f8:      	add	x16, x16, #0x818
  6d85fc:      	br	x17

00000000006d8600 <ff_mpv_unref_picture@plt>:
  6d8600:      	adrp	x16, 0x735000
  6d8604:      	ldr	x17, [x16, #0x820]
  6d8608:      	add	x16, x16, #0x820
  6d860c:      	br	x17

00000000006d8610 <av_timecode_make_mpeg_tc_string@plt>:
  6d8610:      	adrp	x16, 0x735000
  6d8614:      	ldr	x17, [x16, #0x828]
  6d8618:      	add	x16, x16, #0x828
  6d861c:      	br	x17

00000000006d8620 <av_dict_set@plt>:
  6d8620:      	adrp	x16, 0x735000
  6d8624:      	ldr	x17, [x16, #0x830]
  6d8628:      	add	x16, x16, #0x830
  6d862c:      	br	x17

00000000006d8630 <ff_mpv_common_init@plt>:
  6d8630:      	adrp	x16, 0x735000
  6d8634:      	ldr	x17, [x16, #0x838]
  6d8638:      	add	x16, x16, #0x838
  6d863c:      	br	x17

00000000006d8640 <ff_mpv_decode_close@plt>:
  6d8640:      	adrp	x16, 0x735000
  6d8644:      	ldr	x17, [x16, #0x840]
  6d8648:      	add	x16, x16, #0x840
  6d864c:      	br	x17

00000000006d8650 <ff_mpeg_flush@plt>:
  6d8650:      	adrp	x16, 0x735000
  6d8654:      	ldr	x17, [x16, #0x848]
  6d8658:      	add	x16, x16, #0x848
  6d865c:      	br	x17

00000000006d8660 <ff_idctdsp_init@plt>:
  6d8660:      	adrp	x16, 0x735000
  6d8664:      	ldr	x17, [x16, #0x850]
  6d8668:      	add	x16, x16, #0x850
  6d866c:      	br	x17

00000000006d8670 <ff_get_buffer@plt>:
  6d8670:      	adrp	x16, 0x735000
  6d8674:      	ldr	x17, [x16, #0x858]
  6d8678:      	add	x16, x16, #0x858
  6d867c:      	br	x17

00000000006d8680 <ff_mpeg1_decode_block_intra@plt>:
  6d8680:      	adrp	x16, 0x735000
  6d8684:      	ldr	x17, [x16, #0x860]
  6d8688:      	add	x16, x16, #0x860
  6d868c:      	br	x17

00000000006d8690 <ff_mpv_frame_start@plt>:
  6d8690:      	adrp	x16, 0x735000
  6d8694:      	ldr	x17, [x16, #0x868]
  6d8698:      	add	x16, x16, #0x868
  6d869c:      	br	x17

00000000006d86a0 <ff_mpeg_er_frame_start@plt>:
  6d86a0:      	adrp	x16, 0x735000
  6d86a4:      	ldr	x17, [x16, #0x870]
  6d86a8:      	add	x16, x16, #0x870
  6d86ac:      	br	x17

00000000006d86b0 <ff_mpv_alloc_dummy_frames@plt>:
  6d86b0:      	adrp	x16, 0x735000
  6d86b4:      	ldr	x17, [x16, #0x878]
  6d86b8:      	add	x16, x16, #0x878
  6d86bc:      	br	x17

00000000006d86c0 <ff_frame_new_side_data@plt>:
  6d86c0:      	adrp	x16, 0x735000
  6d86c4:      	ldr	x17, [x16, #0x880]
  6d86c8:      	add	x16, x16, #0x880
  6d86cc:      	br	x17

00000000006d86d0 <ff_frame_new_side_data_from_buf@plt>:
  6d86d0:      	adrp	x16, 0x735000
  6d86d4:      	ldr	x17, [x16, #0x888]
  6d86d8:      	add	x16, x16, #0x888
  6d86dc:      	br	x17

00000000006d86e0 <av_stereo3d_create_side_data@plt>:
  6d86e0:      	adrp	x16, 0x735000
  6d86e4:      	ldr	x17, [x16, #0x890]
  6d86e8:      	add	x16, x16, #0x890
  6d86ec:      	br	x17

00000000006d86f0 <ff_thread_finish_setup@plt>:
  6d86f0:      	adrp	x16, 0x735000
  6d86f4:      	ldr	x17, [x16, #0x898]
  6d86f8:      	add	x16, x16, #0x898
  6d86fc:      	br	x17

00000000006d8700 <ff_er_add_slice@plt>:
  6d8700:      	adrp	x16, 0x735000
  6d8704:      	ldr	x17, [x16, #0x8a0]
  6d8708:      	add	x16, x16, #0x8a0
  6d870c:      	br	x17

00000000006d8710 <ff_update_duplicate_context@plt>:
  6d8710:      	adrp	x16, 0x735000
  6d8714:      	ldr	x17, [x16, #0x8a8]
  6d8718:      	add	x16, x16, #0x8a8
  6d871c:      	br	x17

00000000006d8720 <av_d2q@plt>:
  6d8720:      	adrp	x16, 0x735000
  6d8724:      	ldr	x17, [x16, #0x8b0]
  6d8728:      	add	x16, x16, #0x8b0
  6d872c:      	br	x17

00000000006d8730 <av_div_q@plt>:
  6d8730:      	adrp	x16, 0x735000
  6d8734:      	ldr	x17, [x16, #0x8b8]
  6d8738:      	add	x16, x16, #0x8b8
  6d873c:      	br	x17

00000000006d8740 <av_buffer_realloc@plt>:
  6d8740:      	adrp	x16, 0x735000
  6d8744:      	ldr	x17, [x16, #0x8c0]
  6d8748:      	add	x16, x16, #0x8c0
  6d874c:      	br	x17

00000000006d8750 <ff_mpv_common_end@plt>:
  6d8750:      	adrp	x16, 0x735000
  6d8754:      	ldr	x17, [x16, #0x8c8]
  6d8758:      	add	x16, x16, #0x8c8
  6d875c:      	br	x17

00000000006d8760 <ff_er_frame_end@plt>:
  6d8760:      	adrp	x16, 0x735000
  6d8764:      	ldr	x17, [x16, #0x8d0]
  6d8768:      	add	x16, x16, #0x8d0
  6d876c:      	br	x17

00000000006d8770 <ff_mpv_frame_end@plt>:
  6d8770:      	adrp	x16, 0x735000
  6d8774:      	ldr	x17, [x16, #0x8d8]
  6d8778:      	add	x16, x16, #0x8d8
  6d877c:      	br	x17

00000000006d8780 <ff_print_debug_info@plt>:
  6d8780:      	adrp	x16, 0x735000
  6d8784:      	ldr	x17, [x16, #0x8e0]
  6d8788:      	add	x16, x16, #0x8e0
  6d878c:      	br	x17

00000000006d8790 <ff_mpv_export_qp_table@plt>:
  6d8790:      	adrp	x16, 0x735000
  6d8794:      	ldr	x17, [x16, #0x8e8]
  6d8798:      	add	x16, x16, #0x8e8
  6d879c:      	br	x17

00000000006d87a0 <ff_get_format@plt>:
  6d87a0:      	adrp	x16, 0x735000
  6d87a4:      	ldr	x17, [x16, #0x8f0]
  6d87a8:      	add	x16, x16, #0x8f0
  6d87ac:      	br	x17

00000000006d87b0 <ff_mpeg1_clean_buffers@plt>:
  6d87b0:      	adrp	x16, 0x735000
  6d87b4:      	ldr	x17, [x16, #0x8f8]
  6d87b8:      	add	x16, x16, #0x8f8
  6d87bc:      	br	x17

00000000006d87c0 <ff_init_block_index@plt>:
  6d87c0:      	adrp	x16, 0x735000
  6d87c4:      	ldr	x17, [x16, #0x900]
  6d87c8:      	add	x16, x16, #0x900
  6d87cc:      	br	x17

00000000006d87d0 <ff_mpv_reconstruct_mb@plt>:
  6d87d0:      	adrp	x16, 0x735000
  6d87d4:      	ldr	x17, [x16, #0x908]
  6d87d8:      	add	x16, x16, #0x908
  6d87dc:      	br	x17

00000000006d87e0 <ff_mpeg_draw_horiz_band@plt>:
  6d87e0:      	adrp	x16, 0x735000
  6d87e4:      	ldr	x17, [x16, #0x910]
  6d87e8:      	add	x16, x16, #0x910
  6d87ec:      	br	x17

00000000006d87f0 <ff_mpv_report_decode_progress@plt>:
  6d87f0:      	adrp	x16, 0x735000
  6d87f4:      	ldr	x17, [x16, #0x918]
  6d87f8:      	add	x16, x16, #0x918
  6d87fc:      	br	x17

00000000006d8800 <ff_jpegls_init_state@plt>:
  6d8800:      	adrp	x16, 0x735000
  6d8804:      	ldr	x17, [x16, #0x920]
  6d8808:      	add	x16, x16, #0x920
  6d880c:      	br	x17

00000000006d8810 <ff_jpegls_reset_coding_parameters@plt>:
  6d8810:      	adrp	x16, 0x735000
  6d8814:      	ldr	x17, [x16, #0x928]
  6d8818:      	add	x16, x16, #0x928
  6d881c:      	br	x17

00000000006d8820 <ff_h264_hl_decode_mb@plt>:
  6d8820:      	adrp	x16, 0x735000
  6d8824:      	ldr	x17, [x16, #0x930]
  6d8828:      	add	x16, x16, #0x930
  6d882c:      	br	x17

00000000006d8830 <ff_thread_await_progress@plt>:
  6d8830:      	adrp	x16, 0x735000
  6d8834:      	ldr	x17, [x16, #0x938]
  6d8838:      	add	x16, x16, #0x938
  6d883c:      	br	x17

00000000006d8840 <ff_h264_pred_weight_table@plt>:
  6d8840:      	adrp	x16, 0x735000
  6d8844:      	ldr	x17, [x16, #0x940]
  6d8848:      	add	x16, x16, #0x940
  6d884c:      	br	x17

00000000006d8850 <avpriv_request_sample@plt>:
  6d8850:      	adrp	x16, 0x735000
  6d8854:      	ldr	x17, [x16, #0x948]
  6d8858:      	add	x16, x16, #0x948
  6d885c:      	br	x17

00000000006d8860 <ff_h264_check_intra4x4_pred_mode@plt>:
  6d8860:      	adrp	x16, 0x735000
  6d8864:      	ldr	x17, [x16, #0x950]
  6d8868:      	add	x16, x16, #0x950
  6d886c:      	br	x17

00000000006d8870 <ff_h264_check_intra_pred_mode@plt>:
  6d8870:      	adrp	x16, 0x735000
  6d8874:      	ldr	x17, [x16, #0x958]
  6d8878:      	add	x16, x16, #0x958
  6d887c:      	br	x17

00000000006d8880 <ff_h264_parse_ref_count@plt>:
  6d8880:      	adrp	x16, 0x735000
  6d8884:      	ldr	x17, [x16, #0x960]
  6d8888:      	add	x16, x16, #0x960
  6d888c:      	br	x17

00000000006d8890 <ff_h264_init_poc@plt>:
  6d8890:      	adrp	x16, 0x735000
  6d8894:      	ldr	x17, [x16, #0x968]
  6d8898:      	add	x16, x16, #0x968
  6d889c:      	br	x17

00000000006d88a0 <ff_h264_decode_extradata@plt>:
  6d88a0:      	adrp	x16, 0x735000
  6d88a4:      	ldr	x17, [x16, #0x970]
  6d88a8:      	add	x16, x16, #0x970
  6d88ac:      	br	x17

00000000006d88b0 <ff_h2645_packet_split@plt>:
  6d88b0:      	adrp	x16, 0x735000
  6d88b4:      	ldr	x17, [x16, #0x978]
  6d88b8:      	add	x16, x16, #0x978
  6d88bc:      	br	x17

00000000006d88c0 <ff_h264_decode_seq_parameter_set@plt>:
  6d88c0:      	adrp	x16, 0x735000
  6d88c4:      	ldr	x17, [x16, #0x980]
  6d88c8:      	add	x16, x16, #0x980
  6d88cc:      	br	x17

00000000006d88d0 <ff_h264_decode_picture_parameter_set@plt>:
  6d88d0:      	adrp	x16, 0x735000
  6d88d4:      	ldr	x17, [x16, #0x988]
  6d88d8:      	add	x16, x16, #0x988
  6d88dc:      	br	x17

00000000006d88e0 <ff_h2645_packet_uninit@plt>:
  6d88e0:      	adrp	x16, 0x735000
  6d88e4:      	ldr	x17, [x16, #0x990]
  6d88e8:      	add	x16, x16, #0x990
  6d88ec:      	br	x17

00000000006d88f0 <ff_h264_get_profile@plt>:
  6d88f0:      	adrp	x16, 0x735000
  6d88f4:      	ldr	x17, [x16, #0x998]
  6d88f8:      	add	x16, x16, #0x998
  6d88fc:      	br	x17

00000000006d8900 <ff_cbs_trace_header@plt>:
  6d8900:      	adrp	x16, 0x735000
  6d8904:      	ldr	x17, [x16, #0x9a0]
  6d8908:      	add	x16, x16, #0x9a0
  6d890c:      	br	x17

00000000006d8910 <ff_cbs_read_simple_unsigned@plt>:
  6d8910:      	adrp	x16, 0x735000
  6d8914:      	ldr	x17, [x16, #0x9a8]
  6d8918:      	add	x16, x16, #0x9a8
  6d891c:      	br	x17

00000000006d8920 <ff_cbs_append_unit_data@plt>:
  6d8920:      	adrp	x16, 0x735000
  6d8924:      	ldr	x17, [x16, #0x9b0]
  6d8928:      	add	x16, x16, #0x9b0
  6d892c:      	br	x17

00000000006d8930 <ff_cbs_alloc_unit_content@plt>:
  6d8930:      	adrp	x16, 0x735000
  6d8934:      	ldr	x17, [x16, #0x9b8]
  6d8938:      	add	x16, x16, #0x9b8
  6d893c:      	br	x17

00000000006d8940 <av_buffer_ref@plt>:
  6d8940:      	adrp	x16, 0x735000
  6d8944:      	ldr	x17, [x16, #0x9c0]
  6d8948:      	add	x16, x16, #0x9c0
  6d894c:      	br	x17

00000000006d8950 <ff_cbs_read_unsigned@plt>:
  6d8950:      	adrp	x16, 0x735000
  6d8954:      	ldr	x17, [x16, #0x9c8]
  6d8958:      	add	x16, x16, #0x9c8
  6d895c:      	br	x17

00000000006d8960 <ff_cbs_write_unsigned@plt>:
  6d8960:      	adrp	x16, 0x735000
  6d8964:      	ldr	x17, [x16, #0x9d0]
  6d8968:      	add	x16, x16, #0x9d0
  6d896c:      	br	x17

00000000006d8970 <ff_cbs_write_simple_unsigned@plt>:
  6d8970:      	adrp	x16, 0x735000
  6d8974:      	ldr	x17, [x16, #0x9d8]
  6d8978:      	add	x16, x16, #0x9d8
  6d897c:      	br	x17

00000000006d8980 <av_buffer_alloc@plt>:
  6d8980:      	adrp	x16, 0x735000
  6d8984:      	ldr	x17, [x16, #0x9e0]
  6d8988:      	add	x16, x16, #0x9e0
  6d898c:      	br	x17

00000000006d8990 <ff_init_scantable_permutation@plt>:
  6d8990:      	adrp	x16, 0x735000
  6d8994:      	ldr	x17, [x16, #0x9e8]
  6d8998:      	add	x16, x16, #0x9e8
  6d899c:      	br	x17

00000000006d89a0 <ff_xvid_idct_init@plt>:
  6d89a0:      	adrp	x16, 0x735000
  6d89a4:      	ldr	x17, [x16, #0x9f0]
  6d89a8:      	add	x16, x16, #0x9f0
  6d89ac:      	br	x17

00000000006d89b0 <ff_idctdsp_init_aarch64@plt>:
  6d89b0:      	adrp	x16, 0x735000
  6d89b4:      	ldr	x17, [x16, #0x9f8]
  6d89b8:      	add	x16, x16, #0x9f8
  6d89bc:      	br	x17

00000000006d89c0 <ff_simple_idct_int16_8bit@plt>:
  6d89c0:      	adrp	x16, 0x735000
  6d89c4:      	ldr	x17, [x16, #0xa00]
  6d89c8:      	add	x16, x16, #0xa00
  6d89cc:      	br	x17

00000000006d89d0 <ff_h264_replace_picture@plt>:
  6d89d0:      	adrp	x16, 0x735000
  6d89d4:      	ldr	x17, [x16, #0xa08]
  6d89d8:      	add	x16, x16, #0xa08
  6d89dc:      	br	x17

00000000006d89e0 <ff_h2645_sei_ctx_replace@plt>:
  6d89e0:      	adrp	x16, 0x735000
  6d89e4:      	ldr	x17, [x16, #0xa10]
  6d89e8:      	add	x16, x16, #0xa10
  6d89ec:      	br	x17

00000000006d89f0 <ff_h264_execute_ref_pic_marking@plt>:
  6d89f0:      	adrp	x16, 0x735000
  6d89f4:      	ldr	x17, [x16, #0xa18]
  6d89f8:      	add	x16, x16, #0xa18
  6d89fc:      	br	x17

00000000006d8a00 <av_pix_fmt_get_chroma_sub_sample@plt>:
  6d8a00:      	adrp	x16, 0x735000
  6d8a04:      	ldr	x17, [x16, #0xa20]
  6d8a08:      	add	x16, x16, #0xa20
  6d8a0c:      	br	x17

00000000006d8a10 <ff_h264_free_tables@plt>:
  6d8a10:      	adrp	x16, 0x735000
  6d8a14:      	ldr	x17, [x16, #0xa28]
  6d8a18:      	add	x16, x16, #0xa28
  6d8a1c:      	br	x17

00000000006d8a20 <ff_h264_alloc_tables@plt>:
  6d8a20:      	adrp	x16, 0x735000
  6d8a24:      	ldr	x17, [x16, #0xa30]
  6d8a28:      	add	x16, x16, #0xa30
  6d8a2c:      	br	x17

00000000006d8a30 <ff_h264dsp_init@plt>:
  6d8a30:      	adrp	x16, 0x735000
  6d8a34:      	ldr	x17, [x16, #0xa38]
  6d8a38:      	add	x16, x16, #0xa38
  6d8a3c:      	br	x17

00000000006d8a40 <ff_h264chroma_init@plt>:
  6d8a40:      	adrp	x16, 0x735000
  6d8a44:      	ldr	x17, [x16, #0xa40]
  6d8a48:      	add	x16, x16, #0xa40
  6d8a4c:      	br	x17

00000000006d8a50 <ff_h264qpel_init@plt>:
  6d8a50:      	adrp	x16, 0x735000
  6d8a54:      	ldr	x17, [x16, #0xa48]
  6d8a58:      	add	x16, x16, #0xa48
  6d8a5c:      	br	x17

00000000006d8a60 <ff_h264_pred_init@plt>:
  6d8a60:      	adrp	x16, 0x735000
  6d8a64:      	ldr	x17, [x16, #0xa50]
  6d8a68:      	add	x16, x16, #0xa50
  6d8a6c:      	br	x17

00000000006d8a70 <ff_videodsp_init@plt>:
  6d8a70:      	adrp	x16, 0x735000
  6d8a74:      	ldr	x17, [x16, #0xa58]
  6d8a78:      	add	x16, x16, #0xa58
  6d8a7c:      	br	x17

00000000006d8a80 <ff_h264_slice_context_init@plt>:
  6d8a80:      	adrp	x16, 0x735000
  6d8a84:      	ldr	x17, [x16, #0xa60]
  6d8a88:      	add	x16, x16, #0xa60
  6d8a8c:      	br	x17

00000000006d8a90 <ff_h264_queue_decode_slice@plt>:
  6d8a90:      	adrp	x16, 0x735000
  6d8a94:      	ldr	x17, [x16, #0xa68]
  6d8a98:      	add	x16, x16, #0xa68
  6d8a9c:      	br	x17

00000000006d8aa0 <ff_h264_decode_ref_pic_list_reordering@plt>:
  6d8aa0:      	adrp	x16, 0x735000
  6d8aa4:      	ldr	x17, [x16, #0xa70]
  6d8aa8:      	add	x16, x16, #0xa70
  6d8aac:      	br	x17

00000000006d8ab0 <ff_h264_decode_ref_pic_marking@plt>:
  6d8ab0:      	adrp	x16, 0x735000
  6d8ab4:      	ldr	x17, [x16, #0xa78]
  6d8ab8:      	add	x16, x16, #0xa78
  6d8abc:      	br	x17

00000000006d8ac0 <ff_h264_execute_decode_slices@plt>:
  6d8ac0:      	adrp	x16, 0x735000
  6d8ac4:      	ldr	x17, [x16, #0xa80]
  6d8ac8:      	add	x16, x16, #0xa80
  6d8acc:      	br	x17

00000000006d8ad0 <ff_h264_field_end@plt>:
  6d8ad0:      	adrp	x16, 0x735000
  6d8ad4:      	ldr	x17, [x16, #0xa88]
  6d8ad8:      	add	x16, x16, #0xa88
  6d8adc:      	br	x17

00000000006d8ae0 <ff_thread_report_progress@plt>:
  6d8ae0:      	adrp	x16, 0x735000
  6d8ae4:      	ldr	x17, [x16, #0xa90]
  6d8ae8:      	add	x16, x16, #0xa90
  6d8aec:      	br	x17

00000000006d8af0 <ff_h264_build_ref_list@plt>:
  6d8af0:      	adrp	x16, 0x735000
  6d8af4:      	ldr	x17, [x16, #0xa98]
  6d8af8:      	add	x16, x16, #0xa98
  6d8afc:      	br	x17

00000000006d8b00 <ff_h264_direct_dist_scale_factor@plt>:
  6d8b00:      	adrp	x16, 0x735000
  6d8b04:      	ldr	x17, [x16, #0xaa0]
  6d8b08:      	add	x16, x16, #0xaa0
  6d8b0c:      	br	x17

00000000006d8b10 <ff_h264_direct_ref_list_init@plt>:
  6d8b10:      	adrp	x16, 0x735000
  6d8b14:      	ldr	x17, [x16, #0xaa8]
  6d8b18:      	add	x16, x16, #0xaa8
  6d8b1c:      	br	x17

00000000006d8b20 <ff_h264_flush_change@plt>:
  6d8b20:      	adrp	x16, 0x735000
  6d8b24:      	ldr	x17, [x16, #0xab0]
  6d8b28:      	add	x16, x16, #0xab0
  6d8b2c:      	br	x17

00000000006d8b30 <ff_thread_release_ext_buffer@plt>:
  6d8b30:      	adrp	x16, 0x735000
  6d8b34:      	ldr	x17, [x16, #0xab8]
  6d8b38:      	add	x16, x16, #0xab8
  6d8b3c:      	br	x17

00000000006d8b40 <av_memcpy_backptr@plt>:
  6d8b40:      	adrp	x16, 0x735000
  6d8b44:      	ldr	x17, [x16, #0xac0]
  6d8b48:      	add	x16, x16, #0xac0
  6d8b4c:      	br	x17

00000000006d8b50 <ff_h264_sei_process_picture_timing@plt>:
  6d8b50:      	adrp	x16, 0x735000
  6d8b54:      	ldr	x17, [x16, #0xac8]
  6d8b58:      	add	x16, x16, #0xac8
  6d8b5c:      	br	x17

00000000006d8b60 <av_get_picture_type_char@plt>:
  6d8b60:      	adrp	x16, 0x735000
  6d8b64:      	ldr	x17, [x16, #0xad0]
  6d8b68:      	add	x16, x16, #0xad0
  6d8b6c:      	br	x17

00000000006d8b70 <ff_h2645_sei_to_frame@plt>:
  6d8b70:      	adrp	x16, 0x735000
  6d8b74:      	ldr	x17, [x16, #0xad8]
  6d8b78:      	add	x16, x16, #0xad8
  6d8b7c:      	br	x17

00000000006d8b80 <av_timecode_get_smpte@plt>:
  6d8b80:      	adrp	x16, 0x735000
  6d8b84:      	ldr	x17, [x16, #0xae0]
  6d8b88:      	add	x16, x16, #0xae0
  6d8b8c:      	br	x17

00000000006d8b90 <av_timecode_make_smpte_tc_string2@plt>:
  6d8b90:      	adrp	x16, 0x735000
  6d8b94:      	ldr	x17, [x16, #0xae8]
  6d8b98:      	add	x16, x16, #0xae8
  6d8b9c:      	br	x17

00000000006d8ba0 <ff_init_cabac_decoder@plt>:
  6d8ba0:      	adrp	x16, 0x735000
  6d8ba4:      	ldr	x17, [x16, #0xaf0]
  6d8ba8:      	add	x16, x16, #0xaf0
  6d8bac:      	br	x17

00000000006d8bb0 <ff_h264_init_cabac_states@plt>:
  6d8bb0:      	adrp	x16, 0x735000
  6d8bb4:      	ldr	x17, [x16, #0xaf8]
  6d8bb8:      	add	x16, x16, #0xaf8
  6d8bbc:      	br	x17

00000000006d8bc0 <ff_h264_decode_mb_cabac@plt>:
  6d8bc0:      	adrp	x16, 0x735000
  6d8bc4:      	ldr	x17, [x16, #0xb00]
  6d8bc8:      	add	x16, x16, #0xb00
  6d8bcc:      	br	x17

00000000006d8bd0 <ff_h264_decode_mb_cavlc@plt>:
  6d8bd0:      	adrp	x16, 0x735000
  6d8bd4:      	ldr	x17, [x16, #0xb08]
  6d8bd8:      	add	x16, x16, #0xb08
  6d8bdc:      	br	x17

00000000006d8be0 <ff_h264_filter_mb@plt>:
  6d8be0:      	adrp	x16, 0x735000
  6d8be4:      	ldr	x17, [x16, #0xb10]
  6d8be8:      	add	x16, x16, #0xb10
  6d8bec:      	br	x17

00000000006d8bf0 <ff_h264_filter_mb_fast@plt>:
  6d8bf0:      	adrp	x16, 0x735000
  6d8bf4:      	ldr	x17, [x16, #0xb18]
  6d8bf8:      	add	x16, x16, #0xb18
  6d8bfc:      	br	x17

00000000006d8c00 <ff_thread_can_start_frame@plt>:
  6d8c00:      	adrp	x16, 0x735000
  6d8c04:      	ldr	x17, [x16, #0xb20]
  6d8c08:      	add	x16, x16, #0xb20
  6d8c0c:      	br	x17

00000000006d8c10 <ff_thread_get_ext_buffer@plt>:
  6d8c10:      	adrp	x16, 0x735000
  6d8c14:      	ldr	x17, [x16, #0xb28]
  6d8c18:      	add	x16, x16, #0xb28
  6d8c1c:      	br	x17

00000000006d8c20 <ff_thread_get_buffer@plt>:
  6d8c20:      	adrp	x16, 0x735000
  6d8c24:      	ldr	x17, [x16, #0xb30]
  6d8c28:      	add	x16, x16, #0xb30
  6d8c2c:      	br	x17

00000000006d8c30 <ff_hwaccel_frame_priv_alloc@plt>:
  6d8c30:      	adrp	x16, 0x735000
  6d8c34:      	ldr	x17, [x16, #0xb38]
  6d8c38:      	add	x16, x16, #0xb38
  6d8c3c:      	br	x17

00000000006d8c40 <ff_refstruct_pool_get@plt>:
  6d8c40:      	adrp	x16, 0x735000
  6d8c44:      	ldr	x17, [x16, #0xb40]
  6d8c48:      	add	x16, x16, #0xb40
  6d8c4c:      	br	x17

00000000006d8c50 <ff_refstruct_ref_c@plt>:
  6d8c50:      	adrp	x16, 0x735000
  6d8c54:      	ldr	x17, [x16, #0xb48]
  6d8c58:      	add	x16, x16, #0xb48
  6d8c5c:      	br	x17

00000000006d8c60 <ff_h264_unref_picture@plt>:
  6d8c60:      	adrp	x16, 0x735000
  6d8c64:      	ldr	x17, [x16, #0xb50]
  6d8c68:      	add	x16, x16, #0xb50
  6d8c6c:      	br	x17

00000000006d8c70 <ff_h264_set_erpic@plt>:
  6d8c70:      	adrp	x16, 0x735000
  6d8c74:      	ldr	x17, [x16, #0xb58]
  6d8c78:      	add	x16, x16, #0xb58
  6d8c7c:      	br	x17

00000000006d8c80 <ff_h264_ref_picture@plt>:
  6d8c80:      	adrp	x16, 0x735000
  6d8c84:      	ldr	x17, [x16, #0xb60]
  6d8c88:      	add	x16, x16, #0xb60
  6d8c8c:      	br	x17

00000000006d8c90 <ff_er_frame_start@plt>:
  6d8c90:      	adrp	x16, 0x735000
  6d8c94:      	ldr	x17, [x16, #0xb68]
  6d8c98:      	add	x16, x16, #0xb68
  6d8c9c:      	br	x17

00000000006d8ca0 <ff_refstruct_pool_alloc@plt>:
  6d8ca0:      	adrp	x16, 0x735000
  6d8ca4:      	ldr	x17, [x16, #0xb70]
  6d8ca8:      	add	x16, x16, #0xb70
  6d8cac:      	br	x17

00000000006d8cb0 <ff_h264_draw_horiz_band@plt>:
  6d8cb0:      	adrp	x16, 0x735000
  6d8cb4:      	ldr	x17, [x16, #0xb78]
  6d8cb8:      	add	x16, x16, #0xb78
  6d8cbc:      	br	x17

00000000006d8cc0 <ff_flacdsp_init@plt>:
  6d8cc0:      	adrp	x16, 0x735000
  6d8cc4:      	ldr	x17, [x16, #0xb80]
  6d8cc8:      	add	x16, x16, #0xb80
  6d8ccc:      	br	x17

00000000006d8cd0 <ff_toupper4@plt>:
  6d8cd0:      	adrp	x16, 0x735000
  6d8cd4:      	ldr	x17, [x16, #0xb88]
  6d8cd8:      	add	x16, x16, #0xb88
  6d8cdc:      	br	x17

00000000006d8ce0 <ff_get_encode_buffer@plt>:
  6d8ce0:      	adrp	x16, 0x735000
  6d8ce4:      	ldr	x17, [x16, #0xb90]
  6d8ce8:      	add	x16, x16, #0xb90
  6d8cec:      	br	x17

00000000006d8cf0 <ff_mjpeg_build_vlc@plt>:
  6d8cf0:      	adrp	x16, 0x735000
  6d8cf4:      	ldr	x17, [x16, #0xb98]
  6d8cf8:      	add	x16, x16, #0xb98
  6d8cfc:      	br	x17

00000000006d8d00 <ff_vlc_init_from_lengths@plt>:
  6d8d00:      	adrp	x16, 0x735000
  6d8d04:      	ldr	x17, [x16, #0xba0]
  6d8d08:      	add	x16, x16, #0xba0
  6d8d0c:      	br	x17

00000000006d8d10 <ff_vlc_init_tables_sparse@plt>:
  6d8d10:      	adrp	x16, 0x735000
  6d8d14:      	ldr	x17, [x16, #0xba8]
  6d8d18:      	add	x16, x16, #0xba8
  6d8d1c:      	br	x17

00000000006d8d20 <ff_vlc_init_table_sparse@plt>:
  6d8d20:      	adrp	x16, 0x735000
  6d8d24:      	ldr	x17, [x16, #0xbb0]
  6d8d28:      	add	x16, x16, #0xbb0
  6d8d2c:      	br	x17

00000000006d8d30 <ff_vlc_init_tables_from_lengths@plt>:
  6d8d30:      	adrp	x16, 0x735000
  6d8d34:      	ldr	x17, [x16, #0xbb8]
  6d8d38:      	add	x16, x16, #0xbb8
  6d8d3c:      	br	x17

00000000006d8d40 <ff_ps_init_common@plt>:
  6d8d40:      	adrp	x16, 0x735000
  6d8d44:      	ldr	x17, [x16, #0xbc0]
  6d8d48:      	add	x16, x16, #0xbc0
  6d8d4c:      	br	x17

00000000006d8d50 <ff_aac_output_configure@plt>:
  6d8d50:      	adrp	x16, 0x735000
  6d8d54:      	ldr	x17, [x16, #0xbc8]
  6d8d58:      	add	x16, x16, #0xbc8
  6d8d5c:      	br	x17

00000000006d8d60 <av_channel_layout_from_mask@plt>:
  6d8d60:      	adrp	x16, 0x735000
  6d8d64:      	ldr	x17, [x16, #0xbd0]
  6d8d68:      	add	x16, x16, #0xbd0
  6d8d6c:      	br	x17

00000000006d8d70 <av_channel_layout_copy@plt>:
  6d8d70:      	adrp	x16, 0x735000
  6d8d74:      	ldr	x17, [x16, #0xbd8]
  6d8d78:      	add	x16, x16, #0xbd8
  6d8d7c:      	br	x17

00000000006d8d80 <ff_aac_set_default_channel_config@plt>:
  6d8d80:      	adrp	x16, 0x735000
  6d8d84:      	ldr	x17, [x16, #0xbe0]
  6d8d88:      	add	x16, x16, #0xbe0
  6d8d8c:      	br	x17

00000000006d8d90 <ff_aac_get_che@plt>:
  6d8d90:      	adrp	x16, 0x735000
  6d8d94:      	ldr	x17, [x16, #0xbe8]
  6d8d98:      	add	x16, x16, #0xbe8
  6d8d9c:      	br	x17

00000000006d8da0 <ff_aac_decode_init@plt>:
  6d8da0:      	adrp	x16, 0x735000
  6d8da4:      	ldr	x17, [x16, #0xbf0]
  6d8da8:      	add	x16, x16, #0xbf0
  6d8dac:      	br	x17

00000000006d8db0 <av_tx_init@plt>:
  6d8db0:      	adrp	x16, 0x735000
  6d8db4:      	ldr	x17, [x16, #0xbf8]
  6d8db8:      	add	x16, x16, #0xbf8
  6d8dbc:      	br	x17

00000000006d8dc0 <ff_aac_decode_tns@plt>:
  6d8dc0:      	adrp	x16, 0x735000
  6d8dc4:      	ldr	x17, [x16, #0xc00]
  6d8dc8:      	add	x16, x16, #0xc00
  6d8dcc:      	br	x17

00000000006d8dd0 <ff_aac_decode_ics@plt>:
  6d8dd0:      	adrp	x16, 0x735000
  6d8dd4:      	ldr	x17, [x16, #0xc08]
  6d8dd8:      	add	x16, x16, #0xc08
  6d8ddc:      	br	x17

00000000006d8de0 <avpriv_report_missing_feature@plt>:
  6d8de0:      	adrp	x16, 0x735000
  6d8de4:      	ldr	x17, [x16, #0xc10]
  6d8de8:      	add	x16, x16, #0xc10
  6d8dec:      	br	x17

00000000006d8df0 <ff_aac_decode_init_float@plt>:
  6d8df0:      	adrp	x16, 0x735000
  6d8df4:      	ldr	x17, [x16, #0xc18]
  6d8df8:      	add	x16, x16, #0xc18
  6d8dfc:      	br	x17

00000000006d8e00 <ff_aac_usac_reset_state@plt>:
  6d8e00:      	adrp	x16, 0x735000
  6d8e04:      	ldr	x17, [x16, #0xc20]
  6d8e08:      	add	x16, x16, #0xc20
  6d8e0c:      	br	x17

00000000006d8e10 <ff_mpeg4audio_get_config_gb@plt>:
  6d8e10:      	adrp	x16, 0x735000
  6d8e14:      	ldr	x17, [x16, #0xc28]
  6d8e18:      	add	x16, x16, #0xc28
  6d8e1c:      	br	x17

00000000006d8e20 <ff_aac_usac_config_decode@plt>:
  6d8e20:      	adrp	x16, 0x735000
  6d8e24:      	ldr	x17, [x16, #0xc30]
  6d8e28:      	add	x16, x16, #0xc30
  6d8e2c:      	br	x17

00000000006d8e30 <ff_adts_header_parse@plt>:
  6d8e30:      	adrp	x16, 0x735000
  6d8e34:      	ldr	x17, [x16, #0xc38]
  6d8e38:      	add	x16, x16, #0xc38
  6d8e3c:      	br	x17

00000000006d8e40 <sscanf@plt>:
  6d8e40:      	adrp	x16, 0x735000
  6d8e44:      	ldr	x17, [x16, #0xc40]
  6d8e48:      	add	x16, x16, #0xc40
  6d8e4c:      	br	x17

00000000006d8e50 <ff_aac_usac_decode_frame@plt>:
  6d8e50:      	adrp	x16, 0x735000
  6d8e54:      	ldr	x17, [x16, #0xc48]
  6d8e58:      	add	x16, x16, #0xc48
  6d8e5c:      	br	x17

00000000006d8e60 <av_channel_layout_compare@plt>:
  6d8e60:      	adrp	x16, 0x735000
  6d8e64:      	ldr	x17, [x16, #0xc50]
  6d8e68:      	add	x16, x16, #0xc50
  6d8e6c:      	br	x17

00000000006d8e70 <av_tx_uninit@plt>:
  6d8e70:      	adrp	x16, 0x735000
  6d8e74:      	ldr	x17, [x16, #0xc58]
  6d8e78:      	add	x16, x16, #0xc58
  6d8e7c:      	br	x17

00000000006d8e80 <avpriv_alloc_fixed_dsp@plt>:
  6d8e80:      	adrp	x16, 0x735000
  6d8e84:      	ldr	x17, [x16, #0xc60]
  6d8e88:      	add	x16, x16, #0xc60
  6d8e8c:      	br	x17

00000000006d8e90 <ff_cbrt_tableinit_fixed@plt>:
  6d8e90:      	adrp	x16, 0x735000
  6d8e94:      	ldr	x17, [x16, #0xc68]
  6d8e98:      	add	x16, x16, #0xc68
  6d8e9c:      	br	x17

00000000006d8ea0 <ff_kbd_window_init_fixed@plt>:
  6d8ea0:      	adrp	x16, 0x735000
  6d8ea4:      	ldr	x17, [x16, #0xc70]
  6d8ea8:      	add	x16, x16, #0xc70
  6d8eac:      	br	x17

00000000006d8eb0 <memmove@plt>:
  6d8eb0:      	adrp	x16, 0x735000
  6d8eb4:      	ldr	x17, [x16, #0xc78]
  6d8eb8:      	add	x16, x16, #0xc78
  6d8ebc:      	br	x17

00000000006d8ec0 <avpriv_float_dsp_alloc@plt>:
  6d8ec0:      	adrp	x16, 0x735000
  6d8ec4:      	ldr	x17, [x16, #0xc80]
  6d8ec8:      	add	x16, x16, #0xc80
  6d8ecc:      	br	x17

00000000006d8ed0 <ff_cbrt_tableinit@plt>:
  6d8ed0:      	adrp	x16, 0x735000
  6d8ed4:      	ldr	x17, [x16, #0xc88]
  6d8ed8:      	add	x16, x16, #0xc88
  6d8edc:      	br	x17

00000000006d8ee0 <ff_kbd_window_init@plt>:
  6d8ee0:      	adrp	x16, 0x735000
  6d8ee4:      	ldr	x17, [x16, #0xc90]
  6d8ee8:      	add	x16, x16, #0xc90
  6d8eec:      	br	x17

00000000006d8ef0 <ff_sine_window_init@plt>:
  6d8ef0:      	adrp	x16, 0x735000
  6d8ef4:      	ldr	x17, [x16, #0xc98]
  6d8ef8:      	add	x16, x16, #0xc98
  6d8efc:      	br	x17

00000000006d8f00 <ff_init_ff_sine_windows@plt>:
  6d8f00:      	adrp	x16, 0x735000
  6d8f04:      	ldr	x17, [x16, #0xca0]
  6d8f08:      	add	x16, x16, #0xca0
  6d8f0c:      	br	x17

00000000006d8f10 <ff_aac_float_common_init@plt>:
  6d8f10:      	adrp	x16, 0x735000
  6d8f14:      	ldr	x17, [x16, #0xca8]
  6d8f18:      	add	x16, x16, #0xca8
  6d8f1c:      	br	x17

00000000006d8f20 <ff_aac_ac_map_process@plt>:
  6d8f20:      	adrp	x16, 0x735000
  6d8f24:      	ldr	x17, [x16, #0xcb0]
  6d8f28:      	add	x16, x16, #0xcb0
  6d8f2c:      	br	x17

00000000006d8f30 <ff_aac_ac_get_context@plt>:
  6d8f30:      	adrp	x16, 0x735000
  6d8f34:      	ldr	x17, [x16, #0xcb8]
  6d8f38:      	add	x16, x16, #0xcb8
  6d8f3c:      	br	x17

00000000006d8f40 <ff_aac_ac_get_pk@plt>:
  6d8f40:      	adrp	x16, 0x735000
  6d8f44:      	ldr	x17, [x16, #0xcc0]
  6d8f48:      	add	x16, x16, #0xcc0
  6d8f4c:      	br	x17

00000000006d8f50 <ff_aac_ac_update_context@plt>:
  6d8f50:      	adrp	x16, 0x735000
  6d8f54:      	ldr	x17, [x16, #0xcc8]
  6d8f58:      	add	x16, x16, #0xcc8
  6d8f5c:      	br	x17

00000000006d8f60 <ff_aac_ac_init@plt>:
  6d8f60:      	adrp	x16, 0x735000
  6d8f64:      	ldr	x17, [x16, #0xcd0]
  6d8f68:      	add	x16, x16, #0xcd0
  6d8f6c:      	br	x17

00000000006d8f70 <ff_aac_ac_decode@plt>:
  6d8f70:      	adrp	x16, 0x735000
  6d8f74:      	ldr	x17, [x16, #0xcd8]
  6d8f78:      	add	x16, x16, #0xcd8
  6d8f7c:      	br	x17

00000000006d8f80 <ff_aac_ac_finish@plt>:
  6d8f80:      	adrp	x16, 0x735000
  6d8f84:      	ldr	x17, [x16, #0xce0]
  6d8f88:      	add	x16, x16, #0xce0
  6d8f8c:      	br	x17

00000000006d8f90 <av_channel_layout_custom_init@plt>:
  6d8f90:      	adrp	x16, 0x735000
  6d8f94:      	ldr	x17, [x16, #0xce8]
  6d8f98:      	add	x16, x16, #0xce8
  6d8f9c:      	br	x17

00000000006d8fa0 <av_channel_layout_retype@plt>:
  6d8fa0:      	adrp	x16, 0x735000
  6d8fa4:      	ldr	x17, [x16, #0xcf0]
  6d8fa8:      	add	x16, x16, #0xcf0
  6d8fac:      	br	x17

00000000006d8fb0 <av_realloc@plt>:
  6d8fb0:      	adrp	x16, 0x735000
  6d8fb4:      	ldr	x17, [x16, #0xcf8]
  6d8fb8:      	add	x16, x16, #0xcf8
  6d8fbc:      	br	x17

00000000006d8fc0 <av_realloc_array@plt>:
  6d8fc0:      	adrp	x16, 0x735000
  6d8fc4:      	ldr	x17, [x16, #0xd00]
  6d8fc8:      	add	x16, x16, #0xd00
  6d8fcc:      	br	x17

00000000006d8fd0 <ff_aac_ldp_parse_channel_stream@plt>:
  6d8fd0:      	adrp	x16, 0x735000
  6d8fd4:      	ldr	x17, [x16, #0xd08]
  6d8fd8:      	add	x16, x16, #0xd08
  6d8fdc:      	br	x17

00000000006d8fe0 <ff_aac_parse_fac_data@plt>:
  6d8fe0:      	adrp	x16, 0x735000
  6d8fe4:      	ldr	x17, [x16, #0xd10]
  6d8fe8:      	add	x16, x16, #0xd10
  6d8fec:      	br	x17

00000000006d8ff0 <ff_h264chroma_init_aarch64@plt>:
  6d8ff0:      	adrp	x16, 0x735000
  6d8ff4:      	ldr	x17, [x16, #0xd18]
  6d8ff8:      	add	x16, x16, #0xd18
  6d8ffc:      	br	x17

00000000006d9000 <ff_pixblockdsp_init@plt>:
  6d9000:      	adrp	x16, 0x735000
  6d9004:      	ldr	x17, [x16, #0xd20]
  6d9008:      	add	x16, x16, #0xd20
  6d900c:      	br	x17

00000000006d9010 <ff_pixblockdsp_init_aarch64@plt>:
  6d9010:      	adrp	x16, 0x735000
  6d9014:      	ldr	x17, [x16, #0xd28]
  6d9018:      	add	x16, x16, #0xd28
  6d901c:      	br	x17

00000000006d9020 <ff_mpa_decode_header@plt>:
  6d9020:      	adrp	x16, 0x735000
  6d9024:      	ldr	x17, [x16, #0xd30]
  6d9028:      	add	x16, x16, #0xd30
  6d902c:      	br	x17

00000000006d9030 <av_channel_layout_default@plt>:
  6d9030:      	adrp	x16, 0x735000
  6d9034:      	ldr	x17, [x16, #0xd38]
  6d9038:      	add	x16, x16, #0xd38
  6d903c:      	br	x17

00000000006d9040 <ff_combine_frame@plt>:
  6d9040:      	adrp	x16, 0x735000
  6d9044:      	ldr	x17, [x16, #0xd40]
  6d9048:      	add	x16, x16, #0xd40
  6d904c:      	br	x17

00000000006d9050 <ff_AMediaCodecProfile_getProfileFromAVCodecContext@plt>:
  6d9050:      	adrp	x16, 0x735000
  6d9054:      	ldr	x17, [x16, #0xd48]
  6d9058:      	add	x16, x16, #0xd48
  6d905c:      	br	x17

00000000006d9060 <ff_AMediaCodecList_getCodecNameByType@plt>:
  6d9060:      	adrp	x16, 0x735000
  6d9064:      	ldr	x17, [x16, #0xd50]
  6d9068:      	add	x16, x16, #0xd50
  6d906c:      	br	x17

00000000006d9070 <ff_jni_init_jfields@plt>:
  6d9070:      	adrp	x16, 0x735000
  6d9074:      	ldr	x17, [x16, #0xd58]
  6d9078:      	add	x16, x16, #0xd58
  6d907c:      	br	x17

00000000006d9080 <ff_jni_exception_check@plt>:
  6d9080:      	adrp	x16, 0x735000
  6d9084:      	ldr	x17, [x16, #0xd60]
  6d9088:      	add	x16, x16, #0xd60
  6d908c:      	br	x17

00000000006d9090 <ff_jni_jstring_to_utf_chars@plt>:
  6d9090:      	adrp	x16, 0x735000
  6d9094:      	ldr	x17, [x16, #0xd68]
  6d9098:      	add	x16, x16, #0xd68
  6d909c:      	br	x17

00000000006d90a0 <strstr@plt>:
  6d90a0:      	adrp	x16, 0x735000
  6d90a4:      	ldr	x17, [x16, #0xd70]
  6d90a8:      	add	x16, x16, #0xd70
  6d90ac:      	br	x17

00000000006d90b0 <av_strcasecmp@plt>:
  6d90b0:      	adrp	x16, 0x735000
  6d90b4:      	ldr	x17, [x16, #0xd78]
  6d90b8:      	add	x16, x16, #0xd78
  6d90bc:      	br	x17

00000000006d90c0 <ff_jni_reset_jfields@plt>:
  6d90c0:      	adrp	x16, 0x735000
  6d90c4:      	ldr	x17, [x16, #0xd80]
  6d90c8:      	add	x16, x16, #0xd80
  6d90cc:      	br	x17

00000000006d90d0 <ff_AMediaFormat_new@plt>:
  6d90d0:      	adrp	x16, 0x735000
  6d90d4:      	ldr	x17, [x16, #0xd88]
  6d90d8:      	add	x16, x16, #0xd88
  6d90dc:      	br	x17

00000000006d90e0 <ff_AMediaCodec_createCodecByName@plt>:
  6d90e0:      	adrp	x16, 0x735000
  6d90e4:      	ldr	x17, [x16, #0xd90]
  6d90e8:      	add	x16, x16, #0xd90
  6d90ec:      	br	x17

00000000006d90f0 <ff_AMediaCodec_createDecoderByType@plt>:
  6d90f0:      	adrp	x16, 0x735000
  6d90f4:      	ldr	x17, [x16, #0xd98]
  6d90f8:      	add	x16, x16, #0xd98
  6d90fc:      	br	x17

00000000006d9100 <ff_Build_SDK_INT@plt>:
  6d9100:      	adrp	x16, 0x735000
  6d9104:      	ldr	x17, [x16, #0xda0]
  6d9108:      	add	x16, x16, #0xda0
  6d910c:      	br	x17

00000000006d9110 <ff_AMediaFormatColorRange_to_AVColorRange@plt>:
  6d9110:      	adrp	x16, 0x735000
  6d9114:      	ldr	x17, [x16, #0xda8]
  6d9118:      	add	x16, x16, #0xda8
  6d911c:      	br	x17

00000000006d9120 <ff_AMediaFormatColorStandard_to_AVColorSpace@plt>:
  6d9120:      	adrp	x16, 0x735000
  6d9124:      	ldr	x17, [x16, #0xdb0]
  6d9128:      	add	x16, x16, #0xdb0
  6d912c:      	br	x17

00000000006d9130 <ff_AMediaFormatColorStandard_to_AVColorPrimaries@plt>:
  6d9130:      	adrp	x16, 0x735000
  6d9134:      	ldr	x17, [x16, #0xdb8]
  6d9138:      	add	x16, x16, #0xdb8
  6d913c:      	br	x17

00000000006d9140 <ff_AMediaFormatColorTransfer_to_AVColorTransfer@plt>:
  6d9140:      	adrp	x16, 0x735000
  6d9144:      	ldr	x17, [x16, #0xdc0]
  6d9148:      	add	x16, x16, #0xdc0
  6d914c:      	br	x17

00000000006d9150 <dlclose@plt>:
  6d9150:      	adrp	x16, 0x735000
  6d9154:      	ldr	x17, [x16, #0xdc8]
  6d9158:      	add	x16, x16, #0xdc8
  6d915c:      	br	x17

00000000006d9160 <av_strdup@plt>:
  6d9160:      	adrp	x16, 0x735000
  6d9164:      	ldr	x17, [x16, #0xdd0]
  6d9168:      	add	x16, x16, #0xdd0
  6d916c:      	br	x17

00000000006d9170 <dlsym@plt>:
  6d9170:      	adrp	x16, 0x735000
  6d9174:      	ldr	x17, [x16, #0xdd8]
  6d9178:      	add	x16, x16, #0xdd8
  6d917c:      	br	x17

00000000006d9180 <ff_jni_utf_chars_to_jstring@plt>:
  6d9180:      	adrp	x16, 0x735000
  6d9184:      	ldr	x17, [x16, #0xde0]
  6d9188:      	add	x16, x16, #0xde0
  6d918c:      	br	x17

00000000006d9190 <dlopen@plt>:
  6d9190:      	adrp	x16, 0x735000
  6d9194:      	ldr	x17, [x16, #0xde8]
  6d9198:      	add	x16, x16, #0xde8
  6d919c:      	br	x17

00000000006d91a0 <ff_af_queue_init@plt>:
  6d91a0:      	adrp	x16, 0x735000
  6d91a4:      	ldr	x17, [x16, #0xdf0]
  6d91a8:      	add	x16, x16, #0xdf0
  6d91ac:      	br	x17

00000000006d91b0 <ff_af_queue_add@plt>:
  6d91b0:      	adrp	x16, 0x735000
  6d91b4:      	ldr	x17, [x16, #0xdf8]
  6d91b8:      	add	x16, x16, #0xdf8
  6d91bc:      	br	x17

00000000006d91c0 <ff_alloc_packet@plt>:
  6d91c0:      	adrp	x16, 0x735000
  6d91c4:      	ldr	x17, [x16, #0xe00]
  6d91c8:      	add	x16, x16, #0xe00
  6d91cc:      	br	x17

00000000006d91d0 <ff_af_queue_remove@plt>:
  6d91d0:      	adrp	x16, 0x735000
  6d91d4:      	ldr	x17, [x16, #0xe08]
  6d91d8:      	add	x16, x16, #0xe08
  6d91dc:      	br	x17

00000000006d91e0 <ff_af_queue_close@plt>:
  6d91e0:      	adrp	x16, 0x735000
  6d91e4:      	ldr	x17, [x16, #0xe10]
  6d91e8:      	add	x16, x16, #0xe10
  6d91ec:      	br	x17

00000000006d91f0 <ff_adpcm_argo_expand_nibble@plt>:
  6d91f0:      	adrp	x16, 0x735000
  6d91f4:      	ldr	x17, [x16, #0xe18]
  6d91f8:      	add	x16, x16, #0xe18
  6d91fc:      	br	x17

00000000006d9200 <ff_mpeg4_init_rl_intra@plt>:
  6d9200:      	adrp	x16, 0x735000
  6d9204:      	ldr	x17, [x16, #0xe20]
  6d9208:      	add	x16, x16, #0xe20
  6d920c:      	br	x17

00000000006d9210 <ff_mpeg4_get_video_packet_prefix_length@plt>:
  6d9210:      	adrp	x16, 0x735000
  6d9214:      	ldr	x17, [x16, #0xe28]
  6d9218:      	add	x16, x16, #0xe28
  6d921c:      	br	x17

00000000006d9220 <ff_mpeg4_clean_buffers@plt>:
  6d9220:      	adrp	x16, 0x735000
  6d9224:      	ldr	x17, [x16, #0xe30]
  6d9228:      	add	x16, x16, #0xe30
  6d922c:      	br	x17

00000000006d9230 <ff_mpeg4_init_direct_mv@plt>:
  6d9230:      	adrp	x16, 0x735000
  6d9234:      	ldr	x17, [x16, #0xe38]
  6d9238:      	add	x16, x16, #0xe38
  6d923c:      	br	x17

00000000006d9240 <ff_mpeg4_set_direct_mv@plt>:
  6d9240:      	adrp	x16, 0x735000
  6d9244:      	ldr	x17, [x16, #0xe40]
  6d9248:      	add	x16, x16, #0xe40
  6d924c:      	br	x17

00000000006d9250 <ff_h264_pred_direct_motion@plt>:
  6d9250:      	adrp	x16, 0x735000
  6d9254:      	ldr	x17, [x16, #0xe48]
  6d9258:      	add	x16, x16, #0xe48
  6d925c:      	br	x17

00000000006d9260 <ff_flac_decode_frame_header@plt>:
  6d9260:      	adrp	x16, 0x735000
  6d9264:      	ldr	x17, [x16, #0xe50]
  6d9268:      	add	x16, x16, #0xe50
  6d926c:      	br	x17

00000000006d9270 <ff_flac_set_channel_layout@plt>:
  6d9270:      	adrp	x16, 0x735000
  6d9274:      	ldr	x17, [x16, #0xe58]
  6d9278:      	add	x16, x16, #0xe58
  6d927c:      	br	x17

00000000006d9280 <av_fast_realloc@plt>:
  6d9280:      	adrp	x16, 0x735000
  6d9284:      	ldr	x17, [x16, #0xe60]
  6d9288:      	add	x16, x16, #0xe60
  6d928c:      	br	x17

00000000006d9290 <ff_pngdsp_init@plt>:
  6d9290:      	adrp	x16, 0x735000
  6d9294:      	ldr	x17, [x16, #0xe68]
  6d9298:      	add	x16, x16, #0xe68
  6d929c:      	br	x17

00000000006d92a0 <ff_add_png_paeth_prediction@plt>:
  6d92a0:      	adrp	x16, 0x735000
  6d92a4:      	ldr	x17, [x16, #0xe70]
  6d92a8:      	add	x16, x16, #0xe70
  6d92ac:      	br	x17

00000000006d92b0 <ff_hpeldsp_init@plt>:
  6d92b0:      	adrp	x16, 0x735000
  6d92b4:      	ldr	x17, [x16, #0xe78]
  6d92b8:      	add	x16, x16, #0xe78
  6d92bc:      	br	x17

00000000006d92c0 <ff_hpeldsp_init_aarch64@plt>:
  6d92c0:      	adrp	x16, 0x735000
  6d92c4:      	ldr	x17, [x16, #0xe80]
  6d92c8:      	add	x16, x16, #0xe80
  6d92cc:      	br	x17

00000000006d92d0 <ff_wma_init@plt>:
  6d92d0:      	adrp	x16, 0x735000
  6d92d4:      	ldr	x17, [x16, #0xe88]
  6d92d8:      	add	x16, x16, #0xe88
  6d92dc:      	br	x17

00000000006d92e0 <ff_wma_get_frame_len_bits@plt>:
  6d92e0:      	adrp	x16, 0x735000
  6d92e4:      	ldr	x17, [x16, #0xe90]
  6d92e8:      	add	x16, x16, #0xe90
  6d92ec:      	br	x17

00000000006d92f0 <av_malloc_array@plt>:
  6d92f0:      	adrp	x16, 0x735000
  6d92f4:      	ldr	x17, [x16, #0xe98]
  6d92f8:      	add	x16, x16, #0xe98
  6d92fc:      	br	x17

00000000006d9300 <ff_wma_total_gain_to_bits@plt>:
  6d9300:      	adrp	x16, 0x735000
  6d9304:      	ldr	x17, [x16, #0xea0]
  6d9308:      	add	x16, x16, #0xea0
  6d930c:      	br	x17

00000000006d9310 <ff_vlc_free@plt>:
  6d9310:      	adrp	x16, 0x735000
  6d9314:      	ldr	x17, [x16, #0xea8]
  6d9318:      	add	x16, x16, #0xea8
  6d931c:      	br	x17

00000000006d9320 <ff_wma_get_large_val@plt>:
  6d9320:      	adrp	x16, 0x735000
  6d9324:      	ldr	x17, [x16, #0xeb0]
  6d9328:      	add	x16, x16, #0xeb0
  6d932c:      	br	x17

00000000006d9330 <av_packet_side_data_free@plt>:
  6d9330:      	adrp	x16, 0x735000
  6d9334:      	ldr	x17, [x16, #0xeb8]
  6d9338:      	add	x16, x16, #0xeb8
  6d933c:      	br	x17

00000000006d9340 <avcodec_parameters_copy@plt>:
  6d9340:      	adrp	x16, 0x735000
  6d9344:      	ldr	x17, [x16, #0xec0]
  6d9348:      	add	x16, x16, #0xec0
  6d934c:      	br	x17

00000000006d9350 <av_memdup@plt>:
  6d9350:      	adrp	x16, 0x735000
  6d9354:      	ldr	x17, [x16, #0xec8]
  6d9358:      	add	x16, x16, #0xec8
  6d935c:      	br	x17

00000000006d9360 <ff_jpeg2000dsp_init@plt>:
  6d9360:      	adrp	x16, 0x735000
  6d9364:      	ldr	x17, [x16, #0xed0]
  6d9368:      	add	x16, x16, #0xed0
  6d936c:      	br	x17

00000000006d9370 <ff_jpeg2000_init_tier1_luts@plt>:
  6d9370:      	adrp	x16, 0x735000
  6d9374:      	ldr	x17, [x16, #0xed8]
  6d9378:      	add	x16, x16, #0xed8
  6d937c:      	br	x17

00000000006d9380 <ff_jpeg2000_init_component@plt>:
  6d9380:      	adrp	x16, 0x735000
  6d9384:      	ldr	x17, [x16, #0xee0]
  6d9388:      	add	x16, x16, #0xee0
  6d938c:      	br	x17

00000000006d9390 <ff_jpeg2000_cleanup@plt>:
  6d9390:      	adrp	x16, 0x735000
  6d9394:      	ldr	x17, [x16, #0xee8]
  6d9398:      	add	x16, x16, #0xee8
  6d939c:      	br	x17

00000000006d93a0 <ff_mqc_initdec@plt>:
  6d93a0:      	adrp	x16, 0x735000
  6d93a4:      	ldr	x17, [x16, #0xef0]
  6d93a8:      	add	x16, x16, #0xef0
  6d93ac:      	br	x17

00000000006d93b0 <ff_mqc_decode@plt>:
  6d93b0:      	adrp	x16, 0x735000
  6d93b4:      	ldr	x17, [x16, #0xef8]
  6d93b8:      	add	x16, x16, #0xef8
  6d93bc:      	br	x17

00000000006d93c0 <ff_mqc_init_contexts@plt>:
  6d93c0:      	adrp	x16, 0x735000
  6d93c4:      	ldr	x17, [x16, #0xf00]
  6d93c8:      	add	x16, x16, #0xf00
  6d93cc:      	br	x17

00000000006d93d0 <ff_jpeg2000_decode_htj2k@plt>:
  6d93d0:      	adrp	x16, 0x735000
  6d93d4:      	ldr	x17, [x16, #0xf08]
  6d93d8:      	add	x16, x16, #0xf08
  6d93dc:      	br	x17

00000000006d93e0 <ff_dwt_decode@plt>:
  6d93e0:      	adrp	x16, 0x735000
  6d93e4:      	ldr	x17, [x16, #0xf10]
  6d93e8:      	add	x16, x16, #0xf10
  6d93ec:      	br	x17

00000000006d93f0 <ff_jpeg2000_set_significance@plt>:
  6d93f0:      	adrp	x16, 0x735000
  6d93f4:      	ldr	x17, [x16, #0xf18]
  6d93f8:      	add	x16, x16, #0xf18
  6d93fc:      	br	x17

00000000006d9400 <ff_h263dsp_init@plt>:
  6d9400:      	adrp	x16, 0x735000
  6d9404:      	ldr	x17, [x16, #0xf20]
  6d9408:      	add	x16, x16, #0xf20
  6d940c:      	br	x17

00000000006d9410 <ff_quantize_band_cost_cache_init@plt>:
  6d9410:      	adrp	x16, 0x735000
  6d9414:      	ldr	x17, [x16, #0xf28]
  6d9418:      	add	x16, x16, #0xf28
  6d941c:      	br	x17

00000000006d9420 <av_channel_layout_describe@plt>:
  6d9420:      	adrp	x16, 0x735000
  6d9424:      	ldr	x17, [x16, #0xf30]
  6d9428:      	add	x16, x16, #0xf30
  6d942c:      	br	x17

00000000006d9430 <ff_put_string@plt>:
  6d9430:      	adrp	x16, 0x735000
  6d9434:      	ldr	x17, [x16, #0xf38]
  6d9438:      	add	x16, x16, #0xf38
  6d943c:      	br	x17

00000000006d9440 <ff_psy_init@plt>:
  6d9440:      	adrp	x16, 0x735000
  6d9444:      	ldr	x17, [x16, #0xf40]
  6d9448:      	add	x16, x16, #0xf40
  6d944c:      	br	x17

00000000006d9450 <ff_psy_preprocess_init@plt>:
  6d9450:      	adrp	x16, 0x735000
  6d9454:      	ldr	x17, [x16, #0xf48]
  6d9458:      	add	x16, x16, #0xf48
  6d945c:      	br	x17

00000000006d9460 <ff_lpc_init@plt>:
  6d9460:      	adrp	x16, 0x735000
  6d9464:      	ldr	x17, [x16, #0xf50]
  6d9468:      	add	x16, x16, #0xf50
  6d946c:      	br	x17

00000000006d9470 <ff_psy_preprocess@plt>:
  6d9470:      	adrp	x16, 0x735000
  6d9474:      	ldr	x17, [x16, #0xf58]
  6d9478:      	add	x16, x16, #0xf58
  6d947c:      	br	x17

00000000006d9480 <ff_psy_end@plt>:
  6d9480:      	adrp	x16, 0x735000
  6d9484:      	ldr	x17, [x16, #0xf60]
  6d9488:      	add	x16, x16, #0xf60
  6d948c:      	br	x17

00000000006d9490 <ff_lpc_end@plt>:
  6d9490:      	adrp	x16, 0x735000
  6d9494:      	ldr	x17, [x16, #0xf68]
  6d9498:      	add	x16, x16, #0xf68
  6d949c:      	br	x17

00000000006d94a0 <ff_psy_preprocess_end@plt>:
  6d94a0:      	adrp	x16, 0x735000
  6d94a4:      	ldr	x17, [x16, #0xf70]
  6d94a8:      	add	x16, x16, #0xf70
  6d94ac:      	br	x17

00000000006d94b0 <ff_opus_parse_extradata@plt>:
  6d94b0:      	adrp	x16, 0x735000
  6d94b4:      	ldr	x17, [x16, #0xf78]
  6d94b8:      	add	x16, x16, #0xf78
  6d94bc:      	br	x17

00000000006d94c0 <swr_alloc@plt>:
  6d94c0:      	adrp	x16, 0x735000
  6d94c4:      	ldr	x17, [x16, #0xf80]
  6d94c8:      	add	x16, x16, #0xf80
  6d94cc:      	br	x17

00000000006d94d0 <av_opt_set_int@plt>:
  6d94d0:      	adrp	x16, 0x735000
  6d94d4:      	ldr	x17, [x16, #0xf88]
  6d94d8:      	add	x16, x16, #0xf88
  6d94dc:      	br	x17

00000000006d94e0 <av_opt_set_chlayout@plt>:
  6d94e0:      	adrp	x16, 0x735000
  6d94e4:      	ldr	x17, [x16, #0xf90]
  6d94e8:      	add	x16, x16, #0xf90
  6d94ec:      	br	x17

00000000006d94f0 <ff_silk_init@plt>:
  6d94f0:      	adrp	x16, 0x735000
  6d94f4:      	ldr	x17, [x16, #0xf98]
  6d94f8:      	add	x16, x16, #0xf98
  6d94fc:      	br	x17

00000000006d9500 <ff_celt_init@plt>:
  6d9500:      	adrp	x16, 0x735000
  6d9504:      	ldr	x17, [x16, #0xfa0]
  6d9508:      	add	x16, x16, #0xfa0
  6d950c:      	br	x17

00000000006d9510 <av_audio_fifo_alloc@plt>:
  6d9510:      	adrp	x16, 0x735000
  6d9514:      	ldr	x17, [x16, #0xfa8]
  6d9518:      	add	x16, x16, #0xfa8
  6d951c:      	br	x17

00000000006d9520 <av_audio_fifo_size@plt>:
  6d9520:      	adrp	x16, 0x735000
  6d9524:      	ldr	x17, [x16, #0xfb0]
  6d9528:      	add	x16, x16, #0xfb0
  6d952c:      	br	x17

00000000006d9530 <ff_opus_parse_packet@plt>:
  6d9530:      	adrp	x16, 0x735000
  6d9534:      	ldr	x17, [x16, #0xfb8]
  6d9538:      	add	x16, x16, #0xfb8
  6d953c:      	br	x17

00000000006d9540 <av_audio_fifo_read@plt>:
  6d9540:      	adrp	x16, 0x735000
  6d9544:      	ldr	x17, [x16, #0xfc0]
  6d9548:      	add	x16, x16, #0xfc0
  6d954c:      	br	x17

00000000006d9550 <swr_is_initialized@plt>:
  6d9550:      	adrp	x16, 0x735000
  6d9554:      	ldr	x17, [x16, #0xfc8]
  6d9558:      	add	x16, x16, #0xfc8
  6d955c:      	br	x17

00000000006d9560 <av_opt_get_int@plt>:
  6d9560:      	adrp	x16, 0x735000
  6d9564:      	ldr	x17, [x16, #0xfd0]
  6d9568:      	add	x16, x16, #0xfd0
  6d956c:      	br	x17

00000000006d9570 <swr_convert@plt>:
  6d9570:      	adrp	x16, 0x735000
  6d9574:      	ldr	x17, [x16, #0xfd8]
  6d9578:      	add	x16, x16, #0xfd8
  6d957c:      	br	x17

00000000006d9580 <swr_close@plt>:
  6d9580:      	adrp	x16, 0x735000
  6d9584:      	ldr	x17, [x16, #0xfe0]
  6d9588:      	add	x16, x16, #0xfe0
  6d958c:      	br	x17

00000000006d9590 <ff_opus_rc_dec_init@plt>:
  6d9590:      	adrp	x16, 0x735000
  6d9594:      	ldr	x17, [x16, #0xfe8]
  6d9598:      	add	x16, x16, #0xfe8
  6d959c:      	br	x17

00000000006d95a0 <ff_silk_decode_superframe@plt>:
  6d95a0:      	adrp	x16, 0x735000
  6d95a4:      	ldr	x17, [x16, #0xff0]
  6d95a8:      	add	x16, x16, #0xff0
  6d95ac:      	br	x17

00000000006d95b0 <ff_silk_flush@plt>:
  6d95b0:      	adrp	x16, 0x735000
  6d95b4:      	ldr	x17, [x16, #0xff8]
  6d95b8:      	add	x16, x16, #0xff8
  6d95bc:      	br	x17

00000000006d95c0 <ff_opus_rc_dec_log@plt>:
  6d95c0:      	adrp	x16, 0x736000
  6d95c4:      	ldr	x17, [x16]
  6d95c8:      	add	x16, x16, #0x0
  6d95cc:      	br	x17

00000000006d95d0 <ff_opus_rc_dec_uint@plt>:
  6d95d0:      	adrp	x16, 0x736000
  6d95d4:      	ldr	x17, [x16, #0x8]
  6d95d8:      	add	x16, x16, #0x8
  6d95dc:      	br	x17

00000000006d95e0 <swr_init@plt>:
  6d95e0:      	adrp	x16, 0x736000
  6d95e4:      	ldr	x17, [x16, #0x10]
  6d95e8:      	add	x16, x16, #0x10
  6d95ec:      	br	x17

00000000006d95f0 <av_audio_fifo_drain@plt>:
  6d95f0:      	adrp	x16, 0x736000
  6d95f4:      	ldr	x17, [x16, #0x18]
  6d95f8:      	add	x16, x16, #0x18
  6d95fc:      	br	x17

00000000006d9600 <ff_opus_rc_dec_raw_init@plt>:
  6d9600:      	adrp	x16, 0x736000
  6d9604:      	ldr	x17, [x16, #0x20]
  6d9608:      	add	x16, x16, #0x20
  6d960c:      	br	x17

00000000006d9610 <ff_celt_decode_frame@plt>:
  6d9610:      	adrp	x16, 0x736000
  6d9614:      	ldr	x17, [x16, #0x28]
  6d9618:      	add	x16, x16, #0x28
  6d961c:      	br	x17

00000000006d9620 <av_audio_fifo_write@plt>:
  6d9620:      	adrp	x16, 0x736000
  6d9624:      	ldr	x17, [x16, #0x30]
  6d9628:      	add	x16, x16, #0x30
  6d962c:      	br	x17

00000000006d9630 <ff_silk_free@plt>:
  6d9630:      	adrp	x16, 0x736000
  6d9634:      	ldr	x17, [x16, #0x38]
  6d9638:      	add	x16, x16, #0x38
  6d963c:      	br	x17

00000000006d9640 <ff_celt_free@plt>:
  6d9640:      	adrp	x16, 0x736000
  6d9644:      	ldr	x17, [x16, #0x40]
  6d9648:      	add	x16, x16, #0x40
  6d964c:      	br	x17

00000000006d9650 <av_audio_fifo_free@plt>:
  6d9650:      	adrp	x16, 0x736000
  6d9654:      	ldr	x17, [x16, #0x48]
  6d9658:      	add	x16, x16, #0x48
  6d965c:      	br	x17

00000000006d9660 <swr_free@plt>:
  6d9660:      	adrp	x16, 0x736000
  6d9664:      	ldr	x17, [x16, #0x50]
  6d9668:      	add	x16, x16, #0x50
  6d966c:      	br	x17

00000000006d9670 <ff_celt_flush@plt>:
  6d9670:      	adrp	x16, 0x736000
  6d9674:      	ldr	x17, [x16, #0x58]
  6d9678:      	add	x16, x16, #0x58
  6d967c:      	br	x17

00000000006d9680 <ff_opus_rc_get_raw@plt>:
  6d9680:      	adrp	x16, 0x736000
  6d9684:      	ldr	x17, [x16, #0x60]
  6d9688:      	add	x16, x16, #0x60
  6d968c:      	br	x17

00000000006d9690 <ff_opus_rc_dec_cdf@plt>:
  6d9690:      	adrp	x16, 0x736000
  6d9694:      	ldr	x17, [x16, #0x68]
  6d9698:      	add	x16, x16, #0x68
  6d969c:      	br	x17

00000000006d96a0 <ff_opus_rc_dec_laplace@plt>:
  6d96a0:      	adrp	x16, 0x736000
  6d96a4:      	ldr	x17, [x16, #0x70]
  6d96a8:      	add	x16, x16, #0x70
  6d96ac:      	br	x17

00000000006d96b0 <ff_celt_bitalloc@plt>:
  6d96b0:      	adrp	x16, 0x736000
  6d96b4:      	ldr	x17, [x16, #0x78]
  6d96b8:      	add	x16, x16, #0x78
  6d96bc:      	br	x17

00000000006d96c0 <ff_celt_quant_bands@plt>:
  6d96c0:      	adrp	x16, 0x736000
  6d96c4:      	ldr	x17, [x16, #0x80]
  6d96c8:      	add	x16, x16, #0x80
  6d96cc:      	br	x17

00000000006d96d0 <ff_celt_pvq_uninit@plt>:
  6d96d0:      	adrp	x16, 0x736000
  6d96d4:      	ldr	x17, [x16, #0x88]
  6d96d8:      	add	x16, x16, #0x88
  6d96dc:      	br	x17

00000000006d96e0 <ff_celt_pvq_init@plt>:
  6d96e0:      	adrp	x16, 0x736000
  6d96e4:      	ldr	x17, [x16, #0x90]
  6d96e8:      	add	x16, x16, #0x90
  6d96ec:      	br	x17

00000000006d96f0 <ff_opus_dsp_init@plt>:
  6d96f0:      	adrp	x16, 0x736000
  6d96f4:      	ldr	x17, [x16, #0x98]
  6d96f8:      	add	x16, x16, #0x98
  6d96fc:      	br	x17

00000000006d9700 <ff_opus_rc_dec_uint_step@plt>:
  6d9700:      	adrp	x16, 0x736000
  6d9704:      	ldr	x17, [x16, #0xa0]
  6d9708:      	add	x16, x16, #0xa0
  6d970c:      	br	x17

00000000006d9710 <ff_opus_rc_dec_uint_tri@plt>:
  6d9710:      	adrp	x16, 0x736000
  6d9714:      	ldr	x17, [x16, #0xa8]
  6d9718:      	add	x16, x16, #0xa8
  6d971c:      	br	x17

00000000006d9720 <ff_opus_rc_enc_cdf@plt>:
  6d9720:      	adrp	x16, 0x736000
  6d9724:      	ldr	x17, [x16, #0xb0]
  6d9728:      	add	x16, x16, #0xb0
  6d972c:      	br	x17

00000000006d9730 <ff_opus_rc_enc_log@plt>:
  6d9730:      	adrp	x16, 0x736000
  6d9734:      	ldr	x17, [x16, #0xb8]
  6d9738:      	add	x16, x16, #0xb8
  6d973c:      	br	x17

00000000006d9740 <ff_opus_rc_enc_uint@plt>:
  6d9740:      	adrp	x16, 0x736000
  6d9744:      	ldr	x17, [x16, #0xc0]
  6d9748:      	add	x16, x16, #0xc0
  6d974c:      	br	x17

00000000006d9750 <ff_opus_dsp_init_aarch64@plt>:
  6d9750:      	adrp	x16, 0x736000
  6d9754:      	ldr	x17, [x16, #0xc8]
  6d9758:      	add	x16, x16, #0xc8
  6d975c:      	br	x17

00000000006d9760 <ff_opus_rc_put_raw@plt>:
  6d9760:      	adrp	x16, 0x736000
  6d9764:      	ldr	x17, [x16, #0xd0]
  6d9768:      	add	x16, x16, #0xd0
  6d976c:      	br	x17

00000000006d9770 <ff_mpv_common_defaults@plt>:
  6d9770:      	adrp	x16, 0x736000
  6d9774:      	ldr	x17, [x16, #0xd8]
  6d9778:      	add	x16, x16, #0xd8
  6d977c:      	br	x17

00000000006d9780 <ff_mpv_idct_init@plt>:
  6d9780:      	adrp	x16, 0x736000
  6d9784:      	ldr	x17, [x16, #0xe0]
  6d9788:      	add	x16, x16, #0xe0
  6d978c:      	br	x17

00000000006d9790 <ff_thread_sync_ref@plt>:
  6d9790:      	adrp	x16, 0x736000
  6d9794:      	ldr	x17, [x16, #0xe8]
  6d9798:      	add	x16, x16, #0xe8
  6d979c:      	br	x17

00000000006d97a0 <ff_mpv_alloc_pic_pool@plt>:
  6d97a0:      	adrp	x16, 0x736000
  6d97a4:      	ldr	x17, [x16, #0xf0]
  6d97a8:      	add	x16, x16, #0xf0
  6d97ac:      	br	x17

00000000006d97b0 <ff_mpv_common_frame_size_change@plt>:
  6d97b0:      	adrp	x16, 0x736000
  6d97b4:      	ldr	x17, [x16, #0xf8]
  6d97b8:      	add	x16, x16, #0xf8
  6d97bc:      	br	x17

00000000006d97c0 <ff_mpv_replace_picture@plt>:
  6d97c0:      	adrp	x16, 0x736000
  6d97c4:      	ldr	x17, [x16, #0x100]
  6d97c8:      	add	x16, x16, #0x100
  6d97cc:      	br	x17

00000000006d97d0 <ff_mpv_free_context_frame@plt>:
  6d97d0:      	adrp	x16, 0x736000
  6d97d4:      	ldr	x17, [x16, #0x108]
  6d97d8:      	add	x16, x16, #0x108
  6d97dc:      	br	x17

00000000006d97e0 <av_image_check_size@plt>:
  6d97e0:      	adrp	x16, 0x736000
  6d97e4:      	ldr	x17, [x16, #0x110]
  6d97e8:      	add	x16, x16, #0x110
  6d97ec:      	br	x17

00000000006d97f0 <ff_mpv_init_context_frame@plt>:
  6d97f0:      	adrp	x16, 0x736000
  6d97f4:      	ldr	x17, [x16, #0x118]
  6d97f8:      	add	x16, x16, #0x118
  6d97fc:      	br	x17

00000000006d9800 <ff_mpv_init_duplicate_contexts@plt>:
  6d9800:      	adrp	x16, 0x736000
  6d9804:      	ldr	x17, [x16, #0x120]
  6d9808:      	add	x16, x16, #0x120
  6d980c:      	br	x17

00000000006d9810 <ff_thread_progress_report@plt>:
  6d9810:      	adrp	x16, 0x736000
  6d9814:      	ldr	x17, [x16, #0x128]
  6d9818:      	add	x16, x16, #0x128
  6d981c:      	br	x17

00000000006d9820 <ff_mpv_workpic_from_pic@plt>:
  6d9820:      	adrp	x16, 0x736000
  6d9824:      	ldr	x17, [x16, #0x130]
  6d9828:      	add	x16, x16, #0x130
  6d982c:      	br	x17

00000000006d9830 <avcodec_default_get_buffer2@plt>:
  6d9830:      	adrp	x16, 0x736000
  6d9834:      	ldr	x17, [x16, #0x138]
  6d9838:      	add	x16, x16, #0x138
  6d983c:      	br	x17

00000000006d9840 <ff_mpv_pic_check_linesize@plt>:
  6d9840:      	adrp	x16, 0x736000
  6d9844:      	ldr	x17, [x16, #0x140]
  6d9848:      	add	x16, x16, #0x140
  6d984c:      	br	x17

00000000006d9850 <ff_mpv_alloc_pic_accessories@plt>:
  6d9850:      	adrp	x16, 0x736000
  6d9854:      	ldr	x17, [x16, #0x148]
  6d9858:      	add	x16, x16, #0x148
  6d985c:      	br	x17

00000000006d9860 <ff_print_debug_info2@plt>:
  6d9860:      	adrp	x16, 0x736000
  6d9864:      	ldr	x17, [x16, #0x150]
  6d9868:      	add	x16, x16, #0x150
  6d986c:      	br	x17

00000000006d9870 <av_video_enc_params_create_side_data@plt>:
  6d9870:      	adrp	x16, 0x736000
  6d9874:      	ldr	x17, [x16, #0x158]
  6d9878:      	add	x16, x16, #0x158
  6d987c:      	br	x17

00000000006d9880 <ff_draw_horiz_band@plt>:
  6d9880:      	adrp	x16, 0x736000
  6d9884:      	ldr	x17, [x16, #0x160]
  6d9888:      	add	x16, x16, #0x160
  6d988c:      	br	x17

00000000006d9890 <ff_clean_intra_table_entries@plt>:
  6d9890:      	adrp	x16, 0x736000
  6d9894:      	ldr	x17, [x16, #0x168]
  6d9898:      	add	x16, x16, #0x168
  6d989c:      	br	x17

00000000006d98a0 <ff_mpeg4_decode_studio@plt>:
  6d98a0:      	adrp	x16, 0x736000
  6d98a4:      	ldr	x17, [x16, #0x170]
  6d98a8:      	add	x16, x16, #0x170
  6d98ac:      	br	x17

00000000006d98b0 <ff_mpv_motion@plt>:
  6d98b0:      	adrp	x16, 0x736000
  6d98b4:      	ldr	x17, [x16, #0x178]
  6d98b8:      	add	x16, x16, #0x178
  6d98bc:      	br	x17

00000000006d98c0 <ff_thread_progress_await@plt>:
  6d98c0:      	adrp	x16, 0x736000
  6d98c4:      	ldr	x17, [x16, #0x180]
  6d98c8:      	add	x16, x16, #0x180
  6d98cc:      	br	x17

00000000006d98d0 <ff_hevc_decode_nal_sei@plt>:
  6d98d0:      	adrp	x16, 0x736000
  6d98d4:      	ldr	x17, [x16, #0x188]
  6d98d8:      	add	x16, x16, #0x188
  6d98dc:      	br	x17

00000000006d98e0 <ff_h2645_sei_message_decode@plt>:
  6d98e0:      	adrp	x16, 0x736000
  6d98e4:      	ldr	x17, [x16, #0x190]
  6d98e8:      	add	x16, x16, #0x190
  6d98ec:      	br	x17

00000000006d98f0 <ff_hevc_set_neighbour_available@plt>:
  6d98f0:      	adrp	x16, 0x736000
  6d98f4:      	ldr	x17, [x16, #0x198]
  6d98f8:      	add	x16, x16, #0x198
  6d98fc:      	br	x17

00000000006d9900 <ff_hevc_luma_mv_merge_mode@plt>:
  6d9900:      	adrp	x16, 0x736000
  6d9904:      	ldr	x17, [x16, #0x1a0]
  6d9908:      	add	x16, x16, #0x1a0
  6d990c:      	br	x17

00000000006d9910 <ff_hevc_luma_mv_mvp_mode@plt>:
  6d9910:      	adrp	x16, 0x736000
  6d9914:      	ldr	x17, [x16, #0x1a8]
  6d9918:      	add	x16, x16, #0x1a8
  6d991c:      	br	x17

00000000006d9920 <ff_progress_frame_await@plt>:
  6d9920:      	adrp	x16, 0x736000
  6d9924:      	ldr	x17, [x16, #0x1b0]
  6d9928:      	add	x16, x16, #0x1b0
  6d992c:      	br	x17

00000000006d9930 <ff_hevc_get_ref_list@plt>:
  6d9930:      	adrp	x16, 0x736000
  6d9934:      	ldr	x17, [x16, #0x1b8]
  6d9938:      	add	x16, x16, #0x1b8
  6d993c:      	br	x17

00000000006d9940 <ff_hevc_unref_frame@plt>:
  6d9940:      	adrp	x16, 0x736000
  6d9944:      	ldr	x17, [x16, #0x1c0]
  6d9948:      	add	x16, x16, #0x1c0
  6d994c:      	br	x17

00000000006d9950 <ff_progress_frame_ref@plt>:
  6d9950:      	adrp	x16, 0x736000
  6d9954:      	ldr	x17, [x16, #0x1c8]
  6d9958:      	add	x16, x16, #0x1c8
  6d995c:      	br	x17

00000000006d9960 <av_buffer_replace@plt>:
  6d9960:      	adrp	x16, 0x736000
  6d9964:      	ldr	x17, [x16, #0x1d0]
  6d9968:      	add	x16, x16, #0x1d0
  6d996c:      	br	x17

00000000006d9970 <ff_dovi_ctx_replace@plt>:
  6d9970:      	adrp	x16, 0x736000
  6d9974:      	ldr	x17, [x16, #0x1d8]
  6d9978:      	add	x16, x16, #0x1d8
  6d997c:      	br	x17

00000000006d9980 <ff_slice_thread_init_progress@plt>:
  6d9980:      	adrp	x16, 0x736000
  6d9984:      	ldr	x17, [x16, #0x1e0]
  6d9988:      	add	x16, x16, #0x1e0
  6d998c:      	br	x17

00000000006d9990 <ff_container_fifo_alloc_avframe@plt>:
  6d9990:      	adrp	x16, 0x736000
  6d9994:      	ldr	x17, [x16, #0x1e8]
  6d9998:      	add	x16, x16, #0x1e8
  6d999c:      	br	x17

00000000006d99a0 <av_md5_alloc@plt>:
  6d99a0:      	adrp	x16, 0x736000
  6d99a4:      	ldr	x17, [x16, #0x1f0]
  6d99a8:      	add	x16, x16, #0x1f0
  6d99ac:      	br	x17

00000000006d99b0 <ff_bswapdsp_init@plt>:
  6d99b0:      	adrp	x16, 0x736000
  6d99b4:      	ldr	x17, [x16, #0x1f8]
  6d99b8:      	add	x16, x16, #0x1f8
  6d99bc:      	br	x17

00000000006d99c0 <ff_h2645_sei_reset@plt>:
  6d99c0:      	adrp	x16, 0x736000
  6d99c4:      	ldr	x17, [x16, #0x200]
  6d99c8:      	add	x16, x16, #0x200
  6d99cc:      	br	x17

00000000006d99d0 <ff_h2645_sei_to_context@plt>:
  6d99d0:      	adrp	x16, 0x736000
  6d99d4:      	ldr	x17, [x16, #0x208]
  6d99d8:      	add	x16, x16, #0x208
  6d99dc:      	br	x17

00000000006d99e0 <ff_get_coded_side_data@plt>:
  6d99e0:      	adrp	x16, 0x736000
  6d99e4:      	ldr	x17, [x16, #0x210]
  6d99e8:      	add	x16, x16, #0x210
  6d99ec:      	br	x17

00000000006d99f0 <ff_container_fifo_can_read@plt>:
  6d99f0:      	adrp	x16, 0x736000
  6d99f4:      	ldr	x17, [x16, #0x218]
  6d99f8:      	add	x16, x16, #0x218
  6d99fc:      	br	x17

00000000006d9a00 <ff_container_fifo_read@plt>:
  6d9a00:      	adrp	x16, 0x736000
  6d9a04:      	ldr	x17, [x16, #0x220]
  6d9a08:      	add	x16, x16, #0x220
  6d9a0c:      	br	x17

00000000006d9a10 <av_frame_remove_side_data@plt>:
  6d9a10:      	adrp	x16, 0x736000
  6d9a14:      	ldr	x17, [x16, #0x228]
  6d9a18:      	add	x16, x16, #0x228
  6d9a1c:      	br	x17

00000000006d9a20 <ff_decode_get_packet@plt>:
  6d9a20:      	adrp	x16, 0x736000
  6d9a24:      	ldr	x17, [x16, #0x230]
  6d9a28:      	add	x16, x16, #0x230
  6d9a2c:      	br	x17

00000000006d9a30 <ff_hevc_output_frames@plt>:
  6d9a30:      	adrp	x16, 0x736000
  6d9a34:      	ldr	x17, [x16, #0x238]
  6d9a38:      	add	x16, x16, #0x238
  6d9a3c:      	br	x17

00000000006d9a40 <ff_hevc_decode_nal_vps@plt>:
  6d9a40:      	adrp	x16, 0x736000
  6d9a44:      	ldr	x17, [x16, #0x240]
  6d9a48:      	add	x16, x16, #0x240
  6d9a4c:      	br	x17

00000000006d9a50 <ff_hevc_decode_nal_pps@plt>:
  6d9a50:      	adrp	x16, 0x736000
  6d9a54:      	ldr	x17, [x16, #0x248]
  6d9a58:      	add	x16, x16, #0x248
  6d9a5c:      	br	x17

00000000006d9a60 <ff_hevc_decode_nal_sps@plt>:
  6d9a60:      	adrp	x16, 0x736000
  6d9a64:      	ldr	x17, [x16, #0x250]
  6d9a68:      	add	x16, x16, #0x250
  6d9a6c:      	br	x17

00000000006d9a70 <av_film_grain_params_select@plt>:
  6d9a70:      	adrp	x16, 0x736000
  6d9a74:      	ldr	x17, [x16, #0x258]
  6d9a78:      	add	x16, x16, #0x258
  6d9a7c:      	br	x17

00000000006d9a80 <ff_aom_apply_film_grain@plt>:
  6d9a80:      	adrp	x16, 0x736000
  6d9a84:      	ldr	x17, [x16, #0x260]
  6d9a88:      	add	x16, x16, #0x260
  6d9a8c:      	br	x17

00000000006d9a90 <av_md5_init@plt>:
  6d9a90:      	adrp	x16, 0x736000
  6d9a94:      	ldr	x17, [x16, #0x268]
  6d9a98:      	add	x16, x16, #0x268
  6d9a9c:      	br	x17

00000000006d9aa0 <av_md5_update@plt>:
  6d9aa0:      	adrp	x16, 0x736000
  6d9aa4:      	ldr	x17, [x16, #0x270]
  6d9aa8:      	add	x16, x16, #0x270
  6d9aac:      	br	x17

00000000006d9ab0 <av_md5_final@plt>:
  6d9ab0:      	adrp	x16, 0x736000
  6d9ab4:      	ldr	x17, [x16, #0x278]
  6d9ab8:      	add	x16, x16, #0x278
  6d9abc:      	br	x17

00000000006d9ac0 <av_strlcatf@plt>:
  6d9ac0:      	adrp	x16, 0x736000
  6d9ac4:      	ldr	x17, [x16, #0x280]
  6d9ac8:      	add	x16, x16, #0x280
  6d9acc:      	br	x17

00000000006d9ad0 <ff_progress_frame_report@plt>:
  6d9ad0:      	adrp	x16, 0x736000
  6d9ad4:      	ldr	x17, [x16, #0x288]
  6d9ad8:      	add	x16, x16, #0x288
  6d9adc:      	br	x17

00000000006d9ae0 <ff_dovi_rpu_parse@plt>:
  6d9ae0:      	adrp	x16, 0x736000
  6d9ae4:      	ldr	x17, [x16, #0x290]
  6d9ae8:      	add	x16, x16, #0x290
  6d9aec:      	br	x17

00000000006d9af0 <ff_dovi_ctx_unref@plt>:
  6d9af0:      	adrp	x16, 0x736000
  6d9af4:      	ldr	x17, [x16, #0x298]
  6d9af8:      	add	x16, x16, #0x298
  6d9afc:      	br	x17

00000000006d9b00 <ff_container_fifo_free@plt>:
  6d9b00:      	adrp	x16, 0x736000
  6d9b04:      	ldr	x17, [x16, #0x2a0]
  6d9b08:      	add	x16, x16, #0x2a0
  6d9b0c:      	br	x17

00000000006d9b10 <ff_hevc_ps_uninit@plt>:
  6d9b10:      	adrp	x16, 0x736000
  6d9b14:      	ldr	x17, [x16, #0x2a8]
  6d9b18:      	add	x16, x16, #0x2a8
  6d9b1c:      	br	x17

00000000006d9b20 <ff_hevc_flush_dpb@plt>:
  6d9b20:      	adrp	x16, 0x736000
  6d9b24:      	ldr	x17, [x16, #0x2b0]
  6d9b28:      	add	x16, x16, #0x2b0
  6d9b2c:      	br	x17

00000000006d9b30 <ff_dovi_ctx_flush@plt>:
  6d9b30:      	adrp	x16, 0x736000
  6d9b34:      	ldr	x17, [x16, #0x2b8]
  6d9b38:      	add	x16, x16, #0x2b8
  6d9b3c:      	br	x17

00000000006d9b40 <ff_hevc_pred_init@plt>:
  6d9b40:      	adrp	x16, 0x736000
  6d9b44:      	ldr	x17, [x16, #0x2c0]
  6d9b48:      	add	x16, x16, #0x2c0
  6d9b4c:      	br	x17

00000000006d9b50 <ff_hevc_dsp_init@plt>:
  6d9b50:      	adrp	x16, 0x736000
  6d9b54:      	ldr	x17, [x16, #0x2c8]
  6d9b58:      	add	x16, x16, #0x2c8
  6d9b5c:      	br	x17

00000000006d9b60 <ff_hevc_decode_extradata@plt>:
  6d9b60:      	adrp	x16, 0x736000
  6d9b64:      	ldr	x17, [x16, #0x2d0]
  6d9b68:      	add	x16, x16, #0x2d0
  6d9b6c:      	br	x17

00000000006d9b70 <ff_hevc_compute_poc@plt>:
  6d9b70:      	adrp	x16, 0x736000
  6d9b74:      	ldr	x17, [x16, #0x2d8]
  6d9b78:      	add	x16, x16, #0x2d8
  6d9b7c:      	br	x17

00000000006d9b80 <ff_hevc_frame_nb_refs@plt>:
  6d9b80:      	adrp	x16, 0x736000
  6d9b84:      	ldr	x17, [x16, #0x2e0]
  6d9b88:      	add	x16, x16, #0x2e0
  6d9b8c:      	br	x17

00000000006d9b90 <ff_hevc_decode_short_term_rps@plt>:
  6d9b90:      	adrp	x16, 0x736000
  6d9b94:      	ldr	x17, [x16, #0x2e8]
  6d9b98:      	add	x16, x16, #0x2e8
  6d9b9c:      	br	x17

00000000006d9ba0 <ff_hevc_slice_rpl@plt>:
  6d9ba0:      	adrp	x16, 0x736000
  6d9ba4:      	ldr	x17, [x16, #0x2f0]
  6d9ba8:      	add	x16, x16, #0x2f0
  6d9bac:      	br	x17

00000000006d9bb0 <ff_hevc_clear_refs@plt>:
  6d9bb0:      	adrp	x16, 0x736000
  6d9bb4:      	ldr	x17, [x16, #0x2f8]
  6d9bb8:      	add	x16, x16, #0x2f8
  6d9bbc:      	br	x17

00000000006d9bc0 <ff_hevc_set_new_ref@plt>:
  6d9bc0:      	adrp	x16, 0x736000
  6d9bc4:      	ldr	x17, [x16, #0x300]
  6d9bc8:      	add	x16, x16, #0x300
  6d9bcc:      	br	x17

00000000006d9bd0 <ff_hevc_frame_rps@plt>:
  6d9bd0:      	adrp	x16, 0x736000
  6d9bd4:      	ldr	x17, [x16, #0x308]
  6d9bd8:      	add	x16, x16, #0x308
  6d9bdc:      	br	x17

00000000006d9be0 <ff_hevc_cabac_init@plt>:
  6d9be0:      	adrp	x16, 0x736000
  6d9be4:      	ldr	x17, [x16, #0x310]
  6d9be8:      	add	x16, x16, #0x310
  6d9bec:      	br	x17

00000000006d9bf0 <ff_hevc_save_states@plt>:
  6d9bf0:      	adrp	x16, 0x736000
  6d9bf4:      	ldr	x17, [x16, #0x318]
  6d9bf8:      	add	x16, x16, #0x318
  6d9bfc:      	br	x17

00000000006d9c00 <ff_hevc_hls_filters@plt>:
  6d9c00:      	adrp	x16, 0x736000
  6d9c04:      	ldr	x17, [x16, #0x320]
  6d9c08:      	add	x16, x16, #0x320
  6d9c0c:      	br	x17

00000000006d9c10 <ff_hevc_hls_filter@plt>:
  6d9c10:      	adrp	x16, 0x736000
  6d9c14:      	ldr	x17, [x16, #0x328]
  6d9c18:      	add	x16, x16, #0x328
  6d9c1c:      	br	x17

00000000006d9c20 <av_frame_new_side_data_from_buf@plt>:
  6d9c20:      	adrp	x16, 0x736000
  6d9c24:      	ldr	x17, [x16, #0x330]
  6d9c28:      	add	x16, x16, #0x330
  6d9c2c:      	br	x17

00000000006d9c30 <ff_dovi_attach_side_data@plt>:
  6d9c30:      	adrp	x16, 0x736000
  6d9c34:      	ldr	x17, [x16, #0x338]
  6d9c38:      	add	x16, x16, #0x338
  6d9c3c:      	br	x17

00000000006d9c40 <av_frame_copy_props@plt>:
  6d9c40:      	adrp	x16, 0x736000
  6d9c44:      	ldr	x17, [x16, #0x340]
  6d9c48:      	add	x16, x16, #0x340
  6d9c4c:      	br	x17

00000000006d9c50 <av_log_once@plt>:
  6d9c50:      	adrp	x16, 0x736000
  6d9c54:      	ldr	x17, [x16, #0x348]
  6d9c58:      	add	x16, x16, #0x348
  6d9c5c:      	br	x17

00000000006d9c60 <ff_slice_thread_allocz_entries@plt>:
  6d9c60:      	adrp	x16, 0x736000
  6d9c64:      	ldr	x17, [x16, #0x350]
  6d9c68:      	add	x16, x16, #0x350
  6d9c6c:      	br	x17

00000000006d9c70 <ff_thread_await_progress2@plt>:
  6d9c70:      	adrp	x16, 0x736000
  6d9c74:      	ldr	x17, [x16, #0x358]
  6d9c78:      	add	x16, x16, #0x358
  6d9c7c:      	br	x17

00000000006d9c80 <ff_thread_report_progress2@plt>:
  6d9c80:      	adrp	x16, 0x736000
  6d9c84:      	ldr	x17, [x16, #0x360]
  6d9c88:      	add	x16, x16, #0x360
  6d9c8c:      	br	x17

00000000006d9c90 <ff_hevc_sao_merge_flag_decode@plt>:
  6d9c90:      	adrp	x16, 0x736000
  6d9c94:      	ldr	x17, [x16, #0x368]
  6d9c98:      	add	x16, x16, #0x368
  6d9c9c:      	br	x17

00000000006d9ca0 <ff_hevc_sao_type_idx_decode@plt>:
  6d9ca0:      	adrp	x16, 0x736000
  6d9ca4:      	ldr	x17, [x16, #0x370]
  6d9ca8:      	add	x16, x16, #0x370
  6d9cac:      	br	x17

00000000006d9cb0 <ff_hevc_sao_offset_abs_decode@plt>:
  6d9cb0:      	adrp	x16, 0x736000
  6d9cb4:      	ldr	x17, [x16, #0x378]
  6d9cb8:      	add	x16, x16, #0x378
  6d9cbc:      	br	x17

00000000006d9cc0 <ff_hevc_sao_offset_sign_decode@plt>:
  6d9cc0:      	adrp	x16, 0x736000
  6d9cc4:      	ldr	x17, [x16, #0x380]
  6d9cc8:      	add	x16, x16, #0x380
  6d9ccc:      	br	x17

00000000006d9cd0 <ff_hevc_sao_band_position_decode@plt>:
  6d9cd0:      	adrp	x16, 0x736000
  6d9cd4:      	ldr	x17, [x16, #0x388]
  6d9cd8:      	add	x16, x16, #0x388
  6d9cdc:      	br	x17

00000000006d9ce0 <ff_hevc_sao_eo_class_decode@plt>:
  6d9ce0:      	adrp	x16, 0x736000
  6d9ce4:      	ldr	x17, [x16, #0x390]
  6d9ce8:      	add	x16, x16, #0x390
  6d9cec:      	br	x17

00000000006d9cf0 <ff_hevc_split_coding_unit_flag_decode@plt>:
  6d9cf0:      	adrp	x16, 0x736000
  6d9cf4:      	ldr	x17, [x16, #0x398]
  6d9cf8:      	add	x16, x16, #0x398
  6d9cfc:      	br	x17

00000000006d9d00 <ff_hevc_cu_transquant_bypass_flag_decode@plt>:
  6d9d00:      	adrp	x16, 0x736000
  6d9d04:      	ldr	x17, [x16, #0x3a0]
  6d9d08:      	add	x16, x16, #0x3a0
  6d9d0c:      	br	x17

00000000006d9d10 <ff_hevc_skip_flag_decode@plt>:
  6d9d10:      	adrp	x16, 0x736000
  6d9d14:      	ldr	x17, [x16, #0x3a8]
  6d9d18:      	add	x16, x16, #0x3a8
  6d9d1c:      	br	x17

00000000006d9d20 <ff_hevc_deblocking_boundary_strengths@plt>:
  6d9d20:      	adrp	x16, 0x736000
  6d9d24:      	ldr	x17, [x16, #0x3b0]
  6d9d28:      	add	x16, x16, #0x3b0
  6d9d2c:      	br	x17

00000000006d9d30 <ff_hevc_pred_mode_decode@plt>:
  6d9d30:      	adrp	x16, 0x736000
  6d9d34:      	ldr	x17, [x16, #0x3b8]
  6d9d38:      	add	x16, x16, #0x3b8
  6d9d3c:      	br	x17

00000000006d9d40 <ff_hevc_part_mode_decode@plt>:
  6d9d40:      	adrp	x16, 0x736000
  6d9d44:      	ldr	x17, [x16, #0x3c0]
  6d9d48:      	add	x16, x16, #0x3c0
  6d9d4c:      	br	x17

00000000006d9d50 <ff_hevc_prev_intra_luma_pred_flag_decode@plt>:
  6d9d50:      	adrp	x16, 0x736000
  6d9d54:      	ldr	x17, [x16, #0x3c8]
  6d9d58:      	add	x16, x16, #0x3c8
  6d9d5c:      	br	x17

00000000006d9d60 <ff_hevc_mpm_idx_decode@plt>:
  6d9d60:      	adrp	x16, 0x736000
  6d9d64:      	ldr	x17, [x16, #0x3d0]
  6d9d68:      	add	x16, x16, #0x3d0
  6d9d6c:      	br	x17

00000000006d9d70 <ff_hevc_rem_intra_luma_pred_mode_decode@plt>:
  6d9d70:      	adrp	x16, 0x736000
  6d9d74:      	ldr	x17, [x16, #0x3d8]
  6d9d78:      	add	x16, x16, #0x3d8
  6d9d7c:      	br	x17

00000000006d9d80 <ff_hevc_no_residual_syntax_flag_decode@plt>:
  6d9d80:      	adrp	x16, 0x736000
  6d9d84:      	ldr	x17, [x16, #0x3e0]
  6d9d88:      	add	x16, x16, #0x3e0
  6d9d8c:      	br	x17

00000000006d9d90 <ff_hevc_set_qPy@plt>:
  6d9d90:      	adrp	x16, 0x736000
  6d9d94:      	ldr	x17, [x16, #0x3e8]
  6d9d98:      	add	x16, x16, #0x3e8
  6d9d9c:      	br	x17

00000000006d9da0 <ff_hevc_end_of_slice_flag_decode@plt>:
  6d9da0:      	adrp	x16, 0x736000
  6d9da4:      	ldr	x17, [x16, #0x3f0]
  6d9da8:      	add	x16, x16, #0x3f0
  6d9dac:      	br	x17

00000000006d9db0 <ff_hevc_pcm_flag_decode@plt>:
  6d9db0:      	adrp	x16, 0x736000
  6d9db4:      	ldr	x17, [x16, #0x3f8]
  6d9db8:      	add	x16, x16, #0x3f8
  6d9dbc:      	br	x17

00000000006d9dc0 <ff_hevc_merge_flag_decode@plt>:
  6d9dc0:      	adrp	x16, 0x736000
  6d9dc4:      	ldr	x17, [x16, #0x400]
  6d9dc8:      	add	x16, x16, #0x400
  6d9dcc:      	br	x17

00000000006d9dd0 <ff_hevc_merge_idx_decode@plt>:
  6d9dd0:      	adrp	x16, 0x736000
  6d9dd4:      	ldr	x17, [x16, #0x408]
  6d9dd8:      	add	x16, x16, #0x408
  6d9ddc:      	br	x17

00000000006d9de0 <ff_hevc_inter_pred_idc_decode@plt>:
  6d9de0:      	adrp	x16, 0x736000
  6d9de4:      	ldr	x17, [x16, #0x410]
  6d9de8:      	add	x16, x16, #0x410
  6d9dec:      	br	x17

00000000006d9df0 <ff_hevc_ref_idx_lx_decode@plt>:
  6d9df0:      	adrp	x16, 0x736000
  6d9df4:      	ldr	x17, [x16, #0x418]
  6d9df8:      	add	x16, x16, #0x418
  6d9dfc:      	br	x17

00000000006d9e00 <ff_hevc_hls_mvd_coding@plt>:
  6d9e00:      	adrp	x16, 0x736000
  6d9e04:      	ldr	x17, [x16, #0x420]
  6d9e08:      	add	x16, x16, #0x420
  6d9e0c:      	br	x17

00000000006d9e10 <ff_hevc_mvp_lx_flag_decode@plt>:
  6d9e10:      	adrp	x16, 0x736000
  6d9e14:      	ldr	x17, [x16, #0x428]
  6d9e18:      	add	x16, x16, #0x428
  6d9e1c:      	br	x17

00000000006d9e20 <ff_hevc_cbf_luma_decode@plt>:
  6d9e20:      	adrp	x16, 0x736000
  6d9e24:      	ldr	x17, [x16, #0x430]
  6d9e28:      	add	x16, x16, #0x430
  6d9e2c:      	br	x17

00000000006d9e30 <ff_hevc_cbf_cb_cr_decode@plt>:
  6d9e30:      	adrp	x16, 0x736000
  6d9e34:      	ldr	x17, [x16, #0x438]
  6d9e38:      	add	x16, x16, #0x438
  6d9e3c:      	br	x17

00000000006d9e40 <ff_hevc_cu_qp_delta_abs@plt>:
  6d9e40:      	adrp	x16, 0x736000
  6d9e44:      	ldr	x17, [x16, #0x440]
  6d9e48:      	add	x16, x16, #0x440
  6d9e4c:      	br	x17

00000000006d9e50 <ff_hevc_cu_qp_delta_sign_flag@plt>:
  6d9e50:      	adrp	x16, 0x736000
  6d9e54:      	ldr	x17, [x16, #0x448]
  6d9e58:      	add	x16, x16, #0x448
  6d9e5c:      	br	x17

00000000006d9e60 <ff_hevc_split_transform_flag_decode@plt>:
  6d9e60:      	adrp	x16, 0x736000
  6d9e64:      	ldr	x17, [x16, #0x450]
  6d9e68:      	add	x16, x16, #0x450
  6d9e6c:      	br	x17

00000000006d9e70 <ff_hevc_cu_chroma_qp_offset_flag@plt>:
  6d9e70:      	adrp	x16, 0x736000
  6d9e74:      	ldr	x17, [x16, #0x458]
  6d9e78:      	add	x16, x16, #0x458
  6d9e7c:      	br	x17

00000000006d9e80 <ff_hevc_cu_chroma_qp_offset_idx@plt>:
  6d9e80:      	adrp	x16, 0x736000
  6d9e84:      	ldr	x17, [x16, #0x460]
  6d9e88:      	add	x16, x16, #0x460
  6d9e8c:      	br	x17

00000000006d9e90 <ff_hevc_hls_residual_coding@plt>:
  6d9e90:      	adrp	x16, 0x736000
  6d9e94:      	ldr	x17, [x16, #0x468]
  6d9e98:      	add	x16, x16, #0x468
  6d9e9c:      	br	x17

00000000006d9ea0 <ff_hevc_log2_res_scale_abs@plt>:
  6d9ea0:      	adrp	x16, 0x736000
  6d9ea4:      	ldr	x17, [x16, #0x470]
  6d9ea8:      	add	x16, x16, #0x470
  6d9eac:      	br	x17

00000000006d9eb0 <ff_hevc_res_scale_sign_flag@plt>:
  6d9eb0:      	adrp	x16, 0x736000
  6d9eb4:      	ldr	x17, [x16, #0x478]
  6d9eb8:      	add	x16, x16, #0x478
  6d9ebc:      	br	x17

00000000006d9ec0 <ff_hevc_intra_chroma_pred_mode_decode@plt>:
  6d9ec0:      	adrp	x16, 0x736000
  6d9ec4:      	ldr	x17, [x16, #0x480]
  6d9ec8:      	add	x16, x16, #0x480
  6d9ecc:      	br	x17

00000000006d9ed0 <ff_hevc_parse_sps@plt>:
  6d9ed0:      	adrp	x16, 0x736000
  6d9ed4:      	ldr	x17, [x16, #0x488]
  6d9ed8:      	add	x16, x16, #0x488
  6d9edc:      	br	x17

00000000006d9ee0 <ff_h2645_decode_common_vui_params@plt>:
  6d9ee0:      	adrp	x16, 0x736000
  6d9ee4:      	ldr	x17, [x16, #0x490]
  6d9ee8:      	add	x16, x16, #0x490
  6d9eec:      	br	x17

00000000006d9ef0 <ff_hevc_dsp_init_aarch64@plt>:
  6d9ef0:      	adrp	x16, 0x736000
  6d9ef4:      	ldr	x17, [x16, #0x498]
  6d9ef8:      	add	x16, x16, #0x498
  6d9efc:      	br	x17

00000000006d9f00 <ff_progress_frame_unref@plt>:
  6d9f00:      	adrp	x16, 0x736000
  6d9f04:      	ldr	x17, [x16, #0x4a0]
  6d9f08:      	add	x16, x16, #0x4a0
  6d9f0c:      	br	x17

00000000006d9f10 <ff_progress_frame_alloc@plt>:
  6d9f10:      	adrp	x16, 0x736000
  6d9f14:      	ldr	x17, [x16, #0x4a8]
  6d9f18:      	add	x16, x16, #0x4a8
  6d9f1c:      	br	x17

00000000006d9f20 <ff_progress_frame_get_buffer@plt>:
  6d9f20:      	adrp	x16, 0x736000
  6d9f24:      	ldr	x17, [x16, #0x4b0]
  6d9f28:      	add	x16, x16, #0x4b0
  6d9f2c:      	br	x17

00000000006d9f30 <av_frame_side_data_new@plt>:
  6d9f30:      	adrp	x16, 0x736000
  6d9f34:      	ldr	x17, [x16, #0x4b8]
  6d9f38:      	add	x16, x16, #0x4b8
  6d9f3c:      	br	x17

00000000006d9f40 <ff_container_fifo_write@plt>:
  6d9f40:      	adrp	x16, 0x736000
  6d9f44:      	ldr	x17, [x16, #0x4c0]
  6d9f48:      	add	x16, x16, #0x4c0
  6d9f4c:      	br	x17

00000000006d9f50 <ff_mpeg12_find_best_frame_rate@plt>:
  6d9f50:      	adrp	x16, 0x736000
  6d9f54:      	ldr	x17, [x16, #0x4c8]
  6d9f58:      	add	x16, x16, #0x4c8
  6d9f5c:      	br	x17

00000000006d9f60 <av_rescale_q@plt>:
  6d9f60:      	adrp	x16, 0x736000
  6d9f64:      	ldr	x17, [x16, #0x4d0]
  6d9f68:      	add	x16, x16, #0x4d0
  6d9f6c:      	br	x17

00000000006d9f70 <ff_wmv2_encode_picture_header@plt>:
  6d9f70:      	adrp	x16, 0x736000
  6d9f74:      	ldr	x17, [x16, #0x4d8]
  6d9f78:      	add	x16, x16, #0x4d8
  6d9f7c:      	br	x17

00000000006d9f80 <ff_msmpeg4_code012@plt>:
  6d9f80:      	adrp	x16, 0x736000
  6d9f84:      	ldr	x17, [x16, #0x4e0]
  6d9f88:      	add	x16, x16, #0x4e0
  6d9f8c:      	br	x17

00000000006d9f90 <ff_wmv2_encode_mb@plt>:
  6d9f90:      	adrp	x16, 0x736000
  6d9f94:      	ldr	x17, [x16, #0x4e8]
  6d9f98:      	add	x16, x16, #0x4e8
  6d9f9c:      	br	x17

00000000006d9fa0 <ff_msmpeg4_handle_slices@plt>:
  6d9fa0:      	adrp	x16, 0x736000
  6d9fa4:      	ldr	x17, [x16, #0x4f0]
  6d9fa8:      	add	x16, x16, #0x4f0
  6d9fac:      	br	x17

00000000006d9fb0 <ff_h263_pred_motion@plt>:
  6d9fb0:      	adrp	x16, 0x736000
  6d9fb4:      	ldr	x17, [x16, #0x4f8]
  6d9fb8:      	add	x16, x16, #0x4f8
  6d9fbc:      	br	x17

00000000006d9fc0 <ff_msmpeg4_encode_motion@plt>:
  6d9fc0:      	adrp	x16, 0x736000
  6d9fc4:      	ldr	x17, [x16, #0x500]
  6d9fc8:      	add	x16, x16, #0x500
  6d9fcc:      	br	x17

00000000006d9fd0 <ff_msmpeg4_encode_block@plt>:
  6d9fd0:      	adrp	x16, 0x736000
  6d9fd4:      	ldr	x17, [x16, #0x508]
  6d9fd8:      	add	x16, x16, #0x508
  6d9fdc:      	br	x17

00000000006d9fe0 <ff_mpv_encode_init@plt>:
  6d9fe0:      	adrp	x16, 0x736000
  6d9fe4:      	ldr	x17, [x16, #0x510]
  6d9fe8:      	add	x16, x16, #0x510
  6d9fec:      	br	x17

00000000006d9ff0 <ff_wmv2_common_init@plt>:
  6d9ff0:      	adrp	x16, 0x736000
  6d9ff4:      	ldr	x17, [x16, #0x518]
  6d9ff8:      	add	x16, x16, #0x518
  6d9ffc:      	br	x17

00000000006da000 <bsearch@plt>:
  6da000:      	adrp	x16, 0x736000
  6da004:      	ldr	x17, [x16, #0x520]
  6da008:      	add	x16, x16, #0x520
  6da00c:      	br	x17

00000000006da010 <avcodec_get_type@plt>:
  6da010:      	adrp	x16, 0x736000
  6da014:      	ldr	x17, [x16, #0x528]
  6da018:      	add	x16, x16, #0x528
  6da01c:      	br	x17

00000000006da020 <ff_tag_tree_zero@plt>:
  6da020:      	adrp	x16, 0x736000
  6da024:      	ldr	x17, [x16, #0x530]
  6da028:      	add	x16, x16, #0x530
  6da02c:      	br	x17

00000000006da030 <ff_jpeg2000_dwt_init@plt>:
  6da030:      	adrp	x16, 0x736000
  6da034:      	ldr	x17, [x16, #0x538]
  6da038:      	add	x16, x16, #0x538
  6da03c:      	br	x17

00000000006da040 <ff_dwt_destroy@plt>:
  6da040:      	adrp	x16, 0x736000
  6da044:      	ldr	x17, [x16, #0x540]
  6da048:      	add	x16, x16, #0x540
  6da04c:      	br	x17

00000000006da050 <ff_h264qpel_init_aarch64@plt>:
  6da050:      	adrp	x16, 0x736000
  6da054:      	ldr	x17, [x16, #0x548]
  6da058:      	add	x16, x16, #0x548
  6da05c:      	br	x17

00000000006da060 <ff_h265_get_profile@plt>:
  6da060:      	adrp	x16, 0x736000
  6da064:      	ldr	x17, [x16, #0x550]
  6da068:      	add	x16, x16, #0x550
  6da06c:      	br	x17

00000000006da070 <ff_h265_guess_level@plt>:
  6da070:      	adrp	x16, 0x736000
  6da074:      	ldr	x17, [x16, #0x558]
  6da078:      	add	x16, x16, #0x558
  6da07c:      	br	x17

00000000006da080 <ff_flac_is_extradata_valid@plt>:
  6da080:      	adrp	x16, 0x736000
  6da084:      	ldr	x17, [x16, #0x560]
  6da088:      	add	x16, x16, #0x560
  6da08c:      	br	x17

00000000006da090 <ff_flac_parse_streaminfo@plt>:
  6da090:      	adrp	x16, 0x736000
  6da094:      	ldr	x17, [x16, #0x568]
  6da098:      	add	x16, x16, #0x568
  6da09c:      	br	x17

00000000006da0a0 <av_parser_init@plt>:
  6da0a0:      	adrp	x16, 0x736000
  6da0a4:      	ldr	x17, [x16, #0x570]
  6da0a8:      	add	x16, x16, #0x570
  6da0ac:      	br	x17

00000000006da0b0 <av_parser_iterate@plt>:
  6da0b0:      	adrp	x16, 0x736000
  6da0b4:      	ldr	x17, [x16, #0x578]
  6da0b8:      	add	x16, x16, #0x578
  6da0bc:      	br	x17

00000000006da0c0 <ff_fetch_timestamp@plt>:
  6da0c0:      	adrp	x16, 0x736000
  6da0c4:      	ldr	x17, [x16, #0x580]
  6da0c8:      	add	x16, x16, #0x580
  6da0cc:      	br	x17

00000000006da0d0 <av_parser_parse2@plt>:
  6da0d0:      	adrp	x16, 0x736000
  6da0d4:      	ldr	x17, [x16, #0x588]
  6da0d8:      	add	x16, x16, #0x588
  6da0dc:      	br	x17

00000000006da0e0 <av_parser_close@plt>:
  6da0e0:      	adrp	x16, 0x736000
  6da0e4:      	ldr	x17, [x16, #0x590]
  6da0e8:      	add	x16, x16, #0x590
  6da0ec:      	br	x17

00000000006da0f0 <ff_convert_matrix@plt>:
  6da0f0:      	adrp	x16, 0x736000
  6da0f4:      	ldr	x17, [x16, #0x598]
  6da0f8:      	add	x16, x16, #0x598
  6da0fc:      	br	x17

00000000006da100 <ff_write_quant_matrix@plt>:
  6da100:      	adrp	x16, 0x736000
  6da104:      	ldr	x17, [x16, #0x5a0]
  6da108:      	add	x16, x16, #0x5a0
  6da10c:      	br	x17

00000000006da110 <ff_block_permute@plt>:
  6da110:      	adrp	x16, 0x736000
  6da114:      	ldr	x17, [x16, #0x5a8]
  6da118:      	add	x16, x16, #0x5a8
  6da11c:      	br	x17

00000000006da120 <ff_mpeg1_encode_init@plt>:
  6da120:      	adrp	x16, 0x736000
  6da124:      	ldr	x17, [x16, #0x5b0]
  6da128:      	add	x16, x16, #0x5b0
  6da12c:      	br	x17

00000000006da130 <ff_mpegvideoencdsp_init@plt>:
  6da130:      	adrp	x16, 0x736000
  6da134:      	ldr	x17, [x16, #0x5b8]
  6da138:      	add	x16, x16, #0x5b8
  6da13c:      	br	x17

00000000006da140 <ff_me_cmp_init@plt>:
  6da140:      	adrp	x16, 0x736000
  6da144:      	ldr	x17, [x16, #0x5c0]
  6da148:      	add	x16, x16, #0x5c0
  6da14c:      	br	x17

00000000006da150 <ff_me_init@plt>:
  6da150:      	adrp	x16, 0x736000
  6da154:      	ldr	x17, [x16, #0x5c8]
  6da158:      	add	x16, x16, #0x5c8
  6da15c:      	br	x17

00000000006da160 <ff_h263_encode_init@plt>:
  6da160:      	adrp	x16, 0x736000
  6da164:      	ldr	x17, [x16, #0x5d0]
  6da168:      	add	x16, x16, #0x5d0
  6da16c:      	br	x17

00000000006da170 <ff_msmpeg4_encode_init@plt>:
  6da170:      	adrp	x16, 0x736000
  6da174:      	ldr	x17, [x16, #0x5d8]
  6da178:      	add	x16, x16, #0x5d8
  6da17c:      	br	x17

00000000006da180 <ff_rate_control_init@plt>:
  6da180:      	adrp	x16, 0x736000
  6da184:      	ldr	x17, [x16, #0x5e0]
  6da188:      	add	x16, x16, #0x5e0
  6da18c:      	br	x17

00000000006da190 <av_frame_get_buffer@plt>:
  6da190:      	adrp	x16, 0x736000
  6da194:      	ldr	x17, [x16, #0x5e8]
  6da198:      	add	x16, x16, #0x5e8
  6da19c:      	br	x17

00000000006da1a0 <ff_encode_add_cpb_side_data@plt>:
  6da1a0:      	adrp	x16, 0x736000
  6da1a4:      	ldr	x17, [x16, #0x5f0]
  6da1a8:      	add	x16, x16, #0x5f0
  6da1ac:      	br	x17

00000000006da1b0 <ff_rate_control_uninit@plt>:
  6da1b0:      	adrp	x16, 0x736000
  6da1b4:      	ldr	x17, [x16, #0x5f8]
  6da1b8:      	add	x16, x16, #0x5f8
  6da1bc:      	br	x17

00000000006da1c0 <av_frame_move_ref@plt>:
  6da1c0:      	adrp	x16, 0x736000
  6da1c4:      	ldr	x17, [x16, #0x600]
  6da1c8:      	add	x16, x16, #0x600
  6da1cc:      	br	x17

00000000006da1d0 <ff_set_mpeg4_time@plt>:
  6da1d0:      	adrp	x16, 0x736000
  6da1d4:      	ldr	x17, [x16, #0x608]
  6da1d8:      	add	x16, x16, #0x608
  6da1dc:      	br	x17

00000000006da1e0 <ff_get_2pass_fcode@plt>:
  6da1e0:      	adrp	x16, 0x736000
  6da1e4:      	ldr	x17, [x16, #0x610]
  6da1e8:      	add	x16, x16, #0x610
  6da1ec:      	br	x17

00000000006da1f0 <ff_me_init_pic@plt>:
  6da1f0:      	adrp	x16, 0x736000
  6da1f4:      	ldr	x17, [x16, #0x618]
  6da1f8:      	add	x16, x16, #0x618
  6da1fc:      	br	x17

00000000006da200 <ff_get_best_fcode@plt>:
  6da200:      	adrp	x16, 0x736000
  6da204:      	ldr	x17, [x16, #0x620]
  6da208:      	add	x16, x16, #0x620
  6da20c:      	br	x17

00000000006da210 <ff_fix_long_p_mvs@plt>:
  6da210:      	adrp	x16, 0x736000
  6da214:      	ldr	x17, [x16, #0x628]
  6da218:      	add	x16, x16, #0x628
  6da21c:      	br	x17

00000000006da220 <ff_fix_long_mvs@plt>:
  6da220:      	adrp	x16, 0x736000
  6da224:      	ldr	x17, [x16, #0x630]
  6da228:      	add	x16, x16, #0x630
  6da22c:      	br	x17

00000000006da230 <ff_mpeg1_encode_picture_header@plt>:
  6da230:      	adrp	x16, 0x736000
  6da234:      	ldr	x17, [x16, #0x638]
  6da238:      	add	x16, x16, #0x638
  6da23c:      	br	x17

00000000006da240 <ff_msmpeg4_encode_picture_header@plt>:
  6da240:      	adrp	x16, 0x736000
  6da244:      	ldr	x17, [x16, #0x640]
  6da248:      	add	x16, x16, #0x640
  6da24c:      	br	x17

00000000006da250 <ff_mpeg4_encode_picture_header@plt>:
  6da250:      	adrp	x16, 0x736000
  6da254:      	ldr	x17, [x16, #0x648]
  6da258:      	add	x16, x16, #0x648
  6da25c:      	br	x17

00000000006da260 <ff_h263_encode_picture_header@plt>:
  6da260:      	adrp	x16, 0x736000
  6da264:      	ldr	x17, [x16, #0x650]
  6da268:      	add	x16, x16, #0x650
  6da26c:      	br	x17

00000000006da270 <ff_write_pass1_stats@plt>:
  6da270:      	adrp	x16, 0x736000
  6da274:      	ldr	x17, [x16, #0x658]
  6da278:      	add	x16, x16, #0x658
  6da27c:      	br	x17

00000000006da280 <ff_side_data_set_encoder_stats@plt>:
  6da280:      	adrp	x16, 0x736000
  6da284:      	ldr	x17, [x16, #0x660]
  6da288:      	add	x16, x16, #0x660
  6da28c:      	br	x17

00000000006da290 <ff_vbv_update@plt>:
  6da290:      	adrp	x16, 0x736000
  6da294:      	ldr	x17, [x16, #0x668]
  6da298:      	add	x16, x16, #0x668
  6da29c:      	br	x17

00000000006da2a0 <av_packet_add_side_data@plt>:
  6da2a0:      	adrp	x16, 0x736000
  6da2a4:      	ldr	x17, [x16, #0x670]
  6da2a8:      	add	x16, x16, #0x670
  6da2ac:      	br	x17

00000000006da2b0 <ff_encode_reordered_opaque@plt>:
  6da2b0:      	adrp	x16, 0x736000
  6da2b4:      	ldr	x17, [x16, #0x678]
  6da2b8:      	add	x16, x16, #0x678
  6da2bc:      	br	x17

00000000006da2c0 <av_packet_shrink_side_data@plt>:
  6da2c0:      	adrp	x16, 0x736000
  6da2c4:      	ldr	x17, [x16, #0x680]
  6da2c8:      	add	x16, x16, #0x680
  6da2cc:      	br	x17

00000000006da2d0 <avcodec_alloc_context3@plt>:
  6da2d0:      	adrp	x16, 0x736000
  6da2d4:      	ldr	x17, [x16, #0x688]
  6da2d8:      	add	x16, x16, #0x688
  6da2dc:      	br	x17

00000000006da2e0 <avcodec_free_context@plt>:
  6da2e0:      	adrp	x16, 0x736000
  6da2e4:      	ldr	x17, [x16, #0x690]
  6da2e8:      	add	x16, x16, #0x690
  6da2ec:      	br	x17

00000000006da2f0 <ff_mpv_reallocate_putbitbuffer@plt>:
  6da2f0:      	adrp	x16, 0x736000
  6da2f4:      	ldr	x17, [x16, #0x698]
  6da2f8:      	add	x16, x16, #0x698
  6da2fc:      	br	x17

00000000006da300 <ff_encode_alloc_frame@plt>:
  6da300:      	adrp	x16, 0x736000
  6da304:      	ldr	x17, [x16, #0x6a0]
  6da308:      	add	x16, x16, #0x6a0
  6da30c:      	br	x17

00000000006da310 <avcodec_send_frame@plt>:
  6da310:      	adrp	x16, 0x736000
  6da314:      	ldr	x17, [x16, #0x6a8]
  6da318:      	add	x16, x16, #0x6a8
  6da31c:      	br	x17

00000000006da320 <avcodec_receive_packet@plt>:
  6da320:      	adrp	x16, 0x736000
  6da324:      	ldr	x17, [x16, #0x6b0]
  6da328:      	add	x16, x16, #0x6b0
  6da32c:      	br	x17

00000000006da330 <ff_rate_estimate_qscale@plt>:
  6da330:      	adrp	x16, 0x736000
  6da334:      	ldr	x17, [x16, #0x6b8]
  6da338:      	add	x16, x16, #0x6b8
  6da33c:      	br	x17

00000000006da340 <ff_clean_h263_qscales@plt>:
  6da340:      	adrp	x16, 0x736000
  6da344:      	ldr	x17, [x16, #0x6c0]
  6da348:      	add	x16, x16, #0x6c0
  6da34c:      	br	x17

00000000006da350 <ff_clean_mpeg4_qscales@plt>:
  6da350:      	adrp	x16, 0x736000
  6da354:      	ldr	x17, [x16, #0x6c8]
  6da358:      	add	x16, x16, #0x6c8
  6da35c:      	br	x17

00000000006da360 <ff_pre_estimate_p_frame_motion@plt>:
  6da360:      	adrp	x16, 0x736000
  6da364:      	ldr	x17, [x16, #0x6d0]
  6da368:      	add	x16, x16, #0x6d0
  6da36c:      	br	x17

00000000006da370 <ff_estimate_b_frame_motion@plt>:
  6da370:      	adrp	x16, 0x736000
  6da374:      	ldr	x17, [x16, #0x6d8]
  6da378:      	add	x16, x16, #0x6d8
  6da37c:      	br	x17

00000000006da380 <ff_estimate_p_frame_motion@plt>:
  6da380:      	adrp	x16, 0x736000
  6da384:      	ldr	x17, [x16, #0x6e0]
  6da388:      	add	x16, x16, #0x6e0
  6da38c:      	br	x17

00000000006da390 <ff_set_qscale@plt>:
  6da390:      	adrp	x16, 0x736000
  6da394:      	ldr	x17, [x16, #0x6e8]
  6da398:      	add	x16, x16, #0x6e8
  6da39c:      	br	x17

00000000006da3a0 <ff_mpeg4_init_partitions@plt>:
  6da3a0:      	adrp	x16, 0x736000
  6da3a4:      	ldr	x17, [x16, #0x6f0]
  6da3a8:      	add	x16, x16, #0x6f0
  6da3ac:      	br	x17

00000000006da3b0 <ff_h263_encode_gob_header@plt>:
  6da3b0:      	adrp	x16, 0x736000
  6da3b4:      	ldr	x17, [x16, #0x6f8]
  6da3b8:      	add	x16, x16, #0x6f8
  6da3bc:      	br	x17

00000000006da3c0 <ff_mpeg1_encode_slice_header@plt>:
  6da3c0:      	adrp	x16, 0x736000
  6da3c4:      	ldr	x17, [x16, #0x700]
  6da3c8:      	add	x16, x16, #0x700
  6da3cc:      	br	x17

00000000006da3d0 <ff_mpeg4_encode_video_packet_header@plt>:
  6da3d0:      	adrp	x16, 0x736000
  6da3d4:      	ldr	x17, [x16, #0x708]
  6da3d8:      	add	x16, x16, #0x708
  6da3dc:      	br	x17

00000000006da3e0 <ff_h263_update_mb@plt>:
  6da3e0:      	adrp	x16, 0x736000
  6da3e4:      	ldr	x17, [x16, #0x710]
  6da3e8:      	add	x16, x16, #0x710
  6da3ec:      	br	x17

00000000006da3f0 <ff_h263_loop_filter@plt>:
  6da3f0:      	adrp	x16, 0x736000
  6da3f4:      	ldr	x17, [x16, #0x718]
  6da3f8:      	add	x16, x16, #0x718
  6da3fc:      	br	x17

00000000006da400 <ff_msmpeg4_encode_ext_header@plt>:
  6da400:      	adrp	x16, 0x736000
  6da404:      	ldr	x17, [x16, #0x720]
  6da408:      	add	x16, x16, #0x720
  6da40c:      	br	x17

00000000006da410 <ff_mpeg4_merge_partitions@plt>:
  6da410:      	adrp	x16, 0x736000
  6da414:      	ldr	x17, [x16, #0x728]
  6da418:      	add	x16, x16, #0x728
  6da41c:      	br	x17

00000000006da420 <ff_mpeg4_stuffing@plt>:
  6da420:      	adrp	x16, 0x736000
  6da424:      	ldr	x17, [x16, #0x730]
  6da428:      	add	x16, x16, #0x730
  6da42c:      	br	x17

00000000006da430 <ff_h263_encode_mb@plt>:
  6da430:      	adrp	x16, 0x736000
  6da434:      	ldr	x17, [x16, #0x738]
  6da438:      	add	x16, x16, #0x738
  6da43c:      	br	x17

00000000006da440 <ff_msmpeg4_encode_mb@plt>:
  6da440:      	adrp	x16, 0x736000
  6da444:      	ldr	x17, [x16, #0x740]
  6da448:      	add	x16, x16, #0x740
  6da44c:      	br	x17

00000000006da450 <ff_mpeg1_encode_mb@plt>:
  6da450:      	adrp	x16, 0x736000
  6da454:      	ldr	x17, [x16, #0x748]
  6da458:      	add	x16, x16, #0x748
  6da45c:      	br	x17

00000000006da460 <ff_mpeg4_encode_mb@plt>:
  6da460:      	adrp	x16, 0x736000
  6da464:      	ldr	x17, [x16, #0x750]
  6da468:      	add	x16, x16, #0x750
  6da46c:      	br	x17

00000000006da470 <ff_set_cmp@plt>:
  6da470:      	adrp	x16, 0x736000
  6da474:      	ldr	x17, [x16, #0x758]
  6da478:      	add	x16, x16, #0x758
  6da47c:      	br	x17

00000000006da480 <ff_psdsp_init_fixed@plt>:
  6da480:      	adrp	x16, 0x736000
  6da484:      	ldr	x17, [x16, #0x760]
  6da488:      	add	x16, x16, #0x760
  6da48c:      	br	x17

00000000006da490 <ff_h264_sei_uninit@plt>:
  6da490:      	adrp	x16, 0x736000
  6da494:      	ldr	x17, [x16, #0x768]
  6da498:      	add	x16, x16, #0x768
  6da49c:      	br	x17

00000000006da4a0 <ff_h2645_extract_rbsp@plt>:
  6da4a0:      	adrp	x16, 0x736000
  6da4a4:      	ldr	x17, [x16, #0x770]
  6da4a8:      	add	x16, x16, #0x770
  6da4ac:      	br	x17

00000000006da4b0 <ff_h264_sei_decode@plt>:
  6da4b0:      	adrp	x16, 0x736000
  6da4b4:      	ldr	x17, [x16, #0x778]
  6da4b8:      	add	x16, x16, #0x778
  6da4bc:      	br	x17

00000000006da4c0 <ff_h264_ps_uninit@plt>:
  6da4c0:      	adrp	x16, 0x736000
  6da4c4:      	ldr	x17, [x16, #0x780]
  6da4c8:      	add	x16, x16, #0x780
  6da4cc:      	br	x17

00000000006da4d0 <av_rescale@plt>:
  6da4d0:      	adrp	x16, 0x736000
  6da4d4:      	ldr	x17, [x16, #0x788]
  6da4d8:      	add	x16, x16, #0x788
  6da4dc:      	br	x17

00000000006da4e0 <ff_blockdsp_init@plt>:
  6da4e0:      	adrp	x16, 0x736000
  6da4e4:      	ldr	x17, [x16, #0x790]
  6da4e8:      	add	x16, x16, #0x790
  6da4ec:      	br	x17

00000000006da4f0 <ff_wmv2dsp_init@plt>:
  6da4f0:      	adrp	x16, 0x736000
  6da4f4:      	ldr	x17, [x16, #0x798]
  6da4f8:      	add	x16, x16, #0x798
  6da4fc:      	br	x17

00000000006da500 <ff_mspel_motion@plt>:
  6da500:      	adrp	x16, 0x736000
  6da504:      	ldr	x17, [x16, #0x7a0]
  6da508:      	add	x16, x16, #0x7a0
  6da50c:      	br	x17

00000000006da510 <ff_aac_is_encoding_err@plt>:
  6da510:      	adrp	x16, 0x736000
  6da514:      	ldr	x17, [x16, #0x7a8]
  6da518:      	add	x16, x16, #0x7a8
  6da51c:      	br	x17

00000000006da520 <ff_quantize_and_encode_band_cost@plt>:
  6da520:      	adrp	x16, 0x736000
  6da524:      	ldr	x17, [x16, #0x7b0]
  6da528:      	add	x16, x16, #0x7b0
  6da52c:      	br	x17

00000000006da530 <ff_aom_parse_film_grain_sets@plt>:
  6da530:      	adrp	x16, 0x736000
  6da534:      	ldr	x17, [x16, #0x7b8]
  6da538:      	add	x16, x16, #0x7b8
  6da53c:      	br	x17

00000000006da540 <av_film_grain_params_alloc@plt>:
  6da540:      	adrp	x16, 0x736000
  6da544:      	ldr	x17, [x16, #0x7c0]
  6da548:      	add	x16, x16, #0x7c0
  6da54c:      	br	x17

00000000006da550 <av_buffer_create@plt>:
  6da550:      	adrp	x16, 0x736000
  6da554:      	ldr	x17, [x16, #0x7c8]
  6da558:      	add	x16, x16, #0x7c8
  6da55c:      	br	x17

00000000006da560 <ff_aom_uninit_film_grain_params@plt>:
  6da560:      	adrp	x16, 0x736000
  6da564:      	ldr	x17, [x16, #0x7d0]
  6da568:      	add	x16, x16, #0x7d0
  6da56c:      	br	x17

00000000006da570 <ff_aom_attach_film_grain_sets@plt>:
  6da570:      	adrp	x16, 0x736000
  6da574:      	ldr	x17, [x16, #0x7d8]
  6da578:      	add	x16, x16, #0x7d8
  6da57c:      	br	x17

00000000006da580 <ff_ac3_compute_coupling_strategy@plt>:
  6da580:      	adrp	x16, 0x736000
  6da584:      	ldr	x17, [x16, #0x7e0]
  6da588:      	add	x16, x16, #0x7e0
  6da58c:      	br	x17

00000000006da590 <ff_ac3_bit_alloc_calc_psd@plt>:
  6da590:      	adrp	x16, 0x736000
  6da594:      	ldr	x17, [x16, #0x7e8]
  6da598:      	add	x16, x16, #0x7e8
  6da59c:      	br	x17

00000000006da5a0 <ff_ac3_bit_alloc_calc_mask@plt>:
  6da5a0:      	adrp	x16, 0x736000
  6da5a4:      	ldr	x17, [x16, #0x7f0]
  6da5a8:      	add	x16, x16, #0x7f0
  6da5ac:      	br	x17

00000000006da5b0 <ff_ac3_encode_init@plt>:
  6da5b0:      	adrp	x16, 0x736000
  6da5b4:      	ldr	x17, [x16, #0x7f8]
  6da5b8:      	add	x16, x16, #0x7f8
  6da5bc:      	br	x17

00000000006da5c0 <av_channel_layout_subset@plt>:
  6da5c0:      	adrp	x16, 0x736000
  6da5c4:      	ldr	x17, [x16, #0x800]
  6da5c8:      	add	x16, x16, #0x800
  6da5cc:      	br	x17

00000000006da5d0 <ff_audiodsp_init@plt>:
  6da5d0:      	adrp	x16, 0x736000
  6da5d4:      	ldr	x17, [x16, #0x808]
  6da5d8:      	add	x16, x16, #0x808
  6da5dc:      	br	x17

00000000006da5e0 <ff_ac3dsp_init@plt>:
  6da5e0:      	adrp	x16, 0x736000
  6da5e4:      	ldr	x17, [x16, #0x810]
  6da5e8:      	add	x16, x16, #0x810
  6da5ec:      	br	x17

00000000006da5f0 <ff_psdsp_init@plt>:
  6da5f0:      	adrp	x16, 0x736000
  6da5f4:      	ldr	x17, [x16, #0x818]
  6da5f8:      	add	x16, x16, #0x818
  6da5fc:      	br	x17

00000000006da600 <ff_psdsp_init_aarch64@plt>:
  6da600:      	adrp	x16, 0x736000
  6da604:      	ldr	x17, [x16, #0x820]
  6da608:      	add	x16, x16, #0x820
  6da60c:      	br	x17

00000000006da610 <ff_mpegvideoencdsp_init_aarch64@plt>:
  6da610:      	adrp	x16, 0x736000
  6da614:      	ldr	x17, [x16, #0x828]
  6da618:      	add	x16, x16, #0x828
  6da61c:      	br	x17

00000000006da620 <ff_proresdsp_init@plt>:
  6da620:      	adrp	x16, 0x736000
  6da624:      	ldr	x17, [x16, #0x830]
  6da628:      	add	x16, x16, #0x830
  6da62c:      	br	x17

00000000006da630 <ff_prores_idct_10@plt>:
  6da630:      	adrp	x16, 0x736000
  6da634:      	ldr	x17, [x16, #0x838]
  6da638:      	add	x16, x16, #0x838
  6da63c:      	br	x17

00000000006da640 <ff_prores_idct_12@plt>:
  6da640:      	adrp	x16, 0x736000
  6da644:      	ldr	x17, [x16, #0x840]
  6da648:      	add	x16, x16, #0x840
  6da64c:      	br	x17

00000000006da650 <ff_h264_idct_add_9_c@plt>:
  6da650:      	adrp	x16, 0x736000
  6da654:      	ldr	x17, [x16, #0x848]
  6da658:      	add	x16, x16, #0x848
  6da65c:      	br	x17

00000000006da660 <ff_h264_idct8_add_9_c@plt>:
  6da660:      	adrp	x16, 0x736000
  6da664:      	ldr	x17, [x16, #0x850]
  6da668:      	add	x16, x16, #0x850
  6da66c:      	br	x17

00000000006da670 <ff_h264_idct_dc_add_9_c@plt>:
  6da670:      	adrp	x16, 0x736000
  6da674:      	ldr	x17, [x16, #0x858]
  6da678:      	add	x16, x16, #0x858
  6da67c:      	br	x17

00000000006da680 <ff_h264_idct8_dc_add_9_c@plt>:
  6da680:      	adrp	x16, 0x736000
  6da684:      	ldr	x17, [x16, #0x860]
  6da688:      	add	x16, x16, #0x860
  6da68c:      	br	x17

00000000006da690 <ff_h264_idct_add_12_c@plt>:
  6da690:      	adrp	x16, 0x736000
  6da694:      	ldr	x17, [x16, #0x868]
  6da698:      	add	x16, x16, #0x868
  6da69c:      	br	x17

00000000006da6a0 <ff_h264_idct8_add_12_c@plt>:
  6da6a0:      	adrp	x16, 0x736000
  6da6a4:      	ldr	x17, [x16, #0x870]
  6da6a8:      	add	x16, x16, #0x870
  6da6ac:      	br	x17

00000000006da6b0 <ff_h264_idct_dc_add_12_c@plt>:
  6da6b0:      	adrp	x16, 0x736000
  6da6b4:      	ldr	x17, [x16, #0x878]
  6da6b8:      	add	x16, x16, #0x878
  6da6bc:      	br	x17

00000000006da6c0 <ff_h264_idct8_dc_add_12_c@plt>:
  6da6c0:      	adrp	x16, 0x736000
  6da6c4:      	ldr	x17, [x16, #0x880]
  6da6c8:      	add	x16, x16, #0x880
  6da6cc:      	br	x17

00000000006da6d0 <ff_h264_idct_add_10_c@plt>:
  6da6d0:      	adrp	x16, 0x736000
  6da6d4:      	ldr	x17, [x16, #0x888]
  6da6d8:      	add	x16, x16, #0x888
  6da6dc:      	br	x17

00000000006da6e0 <ff_h264_idct8_add_10_c@plt>:
  6da6e0:      	adrp	x16, 0x736000
  6da6e4:      	ldr	x17, [x16, #0x890]
  6da6e8:      	add	x16, x16, #0x890
  6da6ec:      	br	x17

00000000006da6f0 <ff_h264_idct_dc_add_10_c@plt>:
  6da6f0:      	adrp	x16, 0x736000
  6da6f4:      	ldr	x17, [x16, #0x898]
  6da6f8:      	add	x16, x16, #0x898
  6da6fc:      	br	x17

00000000006da700 <ff_h264_idct8_dc_add_10_c@plt>:
  6da700:      	adrp	x16, 0x736000
  6da704:      	ldr	x17, [x16, #0x8a0]
  6da708:      	add	x16, x16, #0x8a0
  6da70c:      	br	x17

00000000006da710 <ff_h264_idct_add_14_c@plt>:
  6da710:      	adrp	x16, 0x736000
  6da714:      	ldr	x17, [x16, #0x8a8]
  6da718:      	add	x16, x16, #0x8a8
  6da71c:      	br	x17

00000000006da720 <ff_h264_idct8_add_14_c@plt>:
  6da720:      	adrp	x16, 0x736000
  6da724:      	ldr	x17, [x16, #0x8b0]
  6da728:      	add	x16, x16, #0x8b0
  6da72c:      	br	x17

00000000006da730 <ff_h264_idct_dc_add_14_c@plt>:
  6da730:      	adrp	x16, 0x736000
  6da734:      	ldr	x17, [x16, #0x8b8]
  6da738:      	add	x16, x16, #0x8b8
  6da73c:      	br	x17

00000000006da740 <ff_h264_idct8_dc_add_14_c@plt>:
  6da740:      	adrp	x16, 0x736000
  6da744:      	ldr	x17, [x16, #0x8c0]
  6da748:      	add	x16, x16, #0x8c0
  6da74c:      	br	x17

00000000006da750 <ff_h264_idct_add_8_c@plt>:
  6da750:      	adrp	x16, 0x736000
  6da754:      	ldr	x17, [x16, #0x8c8]
  6da758:      	add	x16, x16, #0x8c8
  6da75c:      	br	x17

00000000006da760 <ff_h264_idct8_add_8_c@plt>:
  6da760:      	adrp	x16, 0x736000
  6da764:      	ldr	x17, [x16, #0x8d0]
  6da768:      	add	x16, x16, #0x8d0
  6da76c:      	br	x17

00000000006da770 <ff_h264_idct_dc_add_8_c@plt>:
  6da770:      	adrp	x16, 0x736000
  6da774:      	ldr	x17, [x16, #0x8d8]
  6da778:      	add	x16, x16, #0x8d8
  6da77c:      	br	x17

00000000006da780 <ff_h264_idct8_dc_add_8_c@plt>:
  6da780:      	adrp	x16, 0x736000
  6da784:      	ldr	x17, [x16, #0x8e0]
  6da788:      	add	x16, x16, #0x8e0
  6da78c:      	br	x17

00000000006da790 <ff_h264dsp_init_aarch64@plt>:
  6da790:      	adrp	x16, 0x736000
  6da794:      	ldr	x17, [x16, #0x8e8]
  6da798:      	add	x16, x16, #0x8e8
  6da79c:      	br	x17

00000000006da7a0 <ff_mediacodec_sw_buffer_copy_yuv420_planar@plt>:
  6da7a0:      	adrp	x16, 0x736000
  6da7a4:      	ldr	x17, [x16, #0x8f0]
  6da7a8:      	add	x16, x16, #0x8f0
  6da7ac:      	br	x17

00000000006da7b0 <ff_mediacodec_sw_buffer_copy_yuv420_semi_planar@plt>:
  6da7b0:      	adrp	x16, 0x736000
  6da7b4:      	ldr	x17, [x16, #0x8f8]
  6da7b8:      	add	x16, x16, #0x8f8
  6da7bc:      	br	x17

00000000006da7c0 <ff_mediacodec_sw_buffer_copy_yuv420_packed_semi_planar@plt>:
  6da7c0:      	adrp	x16, 0x736000
  6da7c4:      	ldr	x17, [x16, #0x900]
  6da7c8:      	add	x16, x16, #0x900
  6da7cc:      	br	x17

00000000006da7d0 <ff_mediacodec_sw_buffer_copy_yuv420_packed_semi_planar_64x32Tile2m8ka@plt>:
  6da7d0:      	adrp	x16, 0x736000
  6da7d4:      	ldr	x17, [x16, #0x908]
  6da7d8:      	add	x16, x16, #0x908
  6da7dc:      	br	x17

00000000006da7e0 <ff_mpeg4videodsp_init@plt>:
  6da7e0:      	adrp	x16, 0x736000
  6da7e4:      	ldr	x17, [x16, #0x910]
  6da7e8:      	add	x16, x16, #0x910
  6da7ec:      	br	x17

00000000006da7f0 <ff_cbs_make_unit_refcounted@plt>:
  6da7f0:      	adrp	x16, 0x736000
  6da7f4:      	ldr	x17, [x16, #0x918]
  6da7f8:      	add	x16, x16, #0x918
  6da7fc:      	br	x17

00000000006da800 <ff_cbs_read_signed@plt>:
  6da800:      	adrp	x16, 0x736000
  6da804:      	ldr	x17, [x16, #0x920]
  6da808:      	add	x16, x16, #0x920
  6da80c:      	br	x17

00000000006da810 <ff_cbs_write_signed@plt>:
  6da810:      	adrp	x16, 0x736000
  6da814:      	ldr	x17, [x16, #0x928]
  6da818:      	add	x16, x16, #0x928
  6da81c:      	br	x17

00000000006da820 <avpriv_mpegaudio_decode_header@plt>:
  6da820:      	adrp	x16, 0x736000
  6da824:      	ldr	x17, [x16, #0x930]
  6da828:      	add	x16, x16, #0x930
  6da82c:      	br	x17

00000000006da830 <ff_inflate_init@plt>:
  6da830:      	adrp	x16, 0x736000
  6da834:      	ldr	x17, [x16, #0x938]
  6da838:      	add	x16, x16, #0x938
  6da83c:      	br	x17

00000000006da840 <ff_inflate_end@plt>:
  6da840:      	adrp	x16, 0x736000
  6da844:      	ldr	x17, [x16, #0x940]
  6da848:      	add	x16, x16, #0x940
  6da84c:      	br	x17

00000000006da850 <ff_deflate_init@plt>:
  6da850:      	adrp	x16, 0x736000
  6da854:      	ldr	x17, [x16, #0x948]
  6da858:      	add	x16, x16, #0x948
  6da85c:      	br	x17

00000000006da860 <ff_deflate_end@plt>:
  6da860:      	adrp	x16, 0x736000
  6da864:      	ldr	x17, [x16, #0x950]
  6da868:      	add	x16, x16, #0x950
  6da86c:      	br	x17

00000000006da870 <ff_g722_update_low_predictor@plt>:
  6da870:      	adrp	x16, 0x736000
  6da874:      	ldr	x17, [x16, #0x958]
  6da878:      	add	x16, x16, #0x958
  6da87c:      	br	x17

00000000006da880 <ff_g722_update_high_predictor@plt>:
  6da880:      	adrp	x16, 0x736000
  6da884:      	ldr	x17, [x16, #0x960]
  6da888:      	add	x16, x16, #0x960
  6da88c:      	br	x17

00000000006da890 <ff_h263_init_rl_inter@plt>:
  6da890:      	adrp	x16, 0x736000
  6da894:      	ldr	x17, [x16, #0x968]
  6da898:      	add	x16, x16, #0x968
  6da89c:      	br	x17

00000000006da8a0 <ff_h263_update_motion_val@plt>:
  6da8a0:      	adrp	x16, 0x736000
  6da8a4:      	ldr	x17, [x16, #0x970]
  6da8a8:      	add	x16, x16, #0x970
  6da8ac:      	br	x17

00000000006da8b0 <ff_evc_parse_sps@plt>:
  6da8b0:      	adrp	x16, 0x736000
  6da8b4:      	ldr	x17, [x16, #0x978]
  6da8b8:      	add	x16, x16, #0x978
  6da8bc:      	br	x17

00000000006da8c0 <ff_evc_parse_pps@plt>:
  6da8c0:      	adrp	x16, 0x736000
  6da8c4:      	ldr	x17, [x16, #0x980]
  6da8c8:      	add	x16, x16, #0x980
  6da8cc:      	br	x17

00000000006da8d0 <ff_evc_ps_free@plt>:
  6da8d0:      	adrp	x16, 0x736000
  6da8d4:      	ldr	x17, [x16, #0x988]
  6da8d8:      	add	x16, x16, #0x988
  6da8dc:      	br	x17

00000000006da8e0 <ff_xvid_idct@plt>:
  6da8e0:      	adrp	x16, 0x736000
  6da8e4:      	ldr	x17, [x16, #0x990]
  6da8e8:      	add	x16, x16, #0x990
  6da8ec:      	br	x17

00000000006da8f0 <ff_adx_calculate_coeffs@plt>:
  6da8f0:      	adrp	x16, 0x736000
  6da8f4:      	ldr	x17, [x16, #0x998]
  6da8f8:      	add	x16, x16, #0x998
  6da8fc:      	br	x17

00000000006da900 <avpriv_split_xiph_headers@plt>:
  6da900:      	adrp	x16, 0x736000
  6da904:      	ldr	x17, [x16, #0x9a0]
  6da908:      	add	x16, x16, #0x9a0
  6da90c:      	br	x17

00000000006da910 <av_bprint_init@plt>:
  6da910:      	adrp	x16, 0x736000
  6da914:      	ldr	x17, [x16, #0x9a8]
  6da918:      	add	x16, x16, #0x9a8
  6da91c:      	br	x17

00000000006da920 <av_bprint_clear@plt>:
  6da920:      	adrp	x16, 0x736000
  6da924:      	ldr	x17, [x16, #0x9b0]
  6da928:      	add	x16, x16, #0x9b0
  6da92c:      	br	x17

00000000006da930 <av_bprint_finalize@plt>:
  6da930:      	adrp	x16, 0x736000
  6da934:      	ldr	x17, [x16, #0x9b8]
  6da938:      	add	x16, x16, #0x9b8
  6da93c:      	br	x17

00000000006da940 <ff_mpeg1_init_uni_ac_vlc@plt>:
  6da940:      	adrp	x16, 0x736000
  6da944:      	ldr	x17, [x16, #0x9c0]
  6da948:      	add	x16, x16, #0x9c0
  6da94c:      	br	x17

00000000006da950 <av_rescale_rnd@plt>:
  6da950:      	adrp	x16, 0x736000
  6da954:      	ldr	x17, [x16, #0x9c8]
  6da958:      	add	x16, x16, #0x9c8
  6da95c:      	br	x17

00000000006da960 <av_timecode_adjust_ntsc_framenum2@plt>:
  6da960:      	adrp	x16, 0x736000
  6da964:      	ldr	x17, [x16, #0x9d0]
  6da968:      	add	x16, x16, #0x9d0
  6da96c:      	br	x17

00000000006da970 <av_nearer_q@plt>:
  6da970:      	adrp	x16, 0x736000
  6da974:      	ldr	x17, [x16, #0x9d8]
  6da978:      	add	x16, x16, #0x9d8
  6da97c:      	br	x17

00000000006da980 <av_timecode_init_from_string@plt>:
  6da980:      	adrp	x16, 0x736000
  6da984:      	ldr	x17, [x16, #0x9e0]
  6da988:      	add	x16, x16, #0x9e0
  6da98c:      	br	x17

00000000006da990 <ff_png_get_nb_channels@plt>:
  6da990:      	adrp	x16, 0x736000
  6da994:      	ldr	x17, [x16, #0x9e8]
  6da998:      	add	x16, x16, #0x9e8
  6da99c:      	br	x17

00000000006da9a0 <ff_png_pass_row_size@plt>:
  6da9a0:      	adrp	x16, 0x736000
  6da9a4:      	ldr	x17, [x16, #0x9f0]
  6da9a8:      	add	x16, x16, #0x9f0
  6da9ac:      	br	x17

00000000006da9b0 <ff_cbs_flush@plt>:
  6da9b0:      	adrp	x16, 0x736000
  6da9b4:      	ldr	x17, [x16, #0x9f8]
  6da9b8:      	add	x16, x16, #0x9f8
  6da9bc:      	br	x17

00000000006da9c0 <av_reallocp@plt>:
  6da9c0:      	adrp	x16, 0x736000
  6da9c4:      	ldr	x17, [x16, #0xa00]
  6da9c8:      	add	x16, x16, #0xa00
  6da9cc:      	br	x17

00000000006da9d0 <ff_cbs_trace_read_log@plt>:
  6da9d0:      	adrp	x16, 0x736000
  6da9d4:      	ldr	x17, [x16, #0xa08]
  6da9d8:      	add	x16, x16, #0xa08
  6da9dc:      	br	x17

00000000006da9e0 <snprintf@plt>:
  6da9e0:      	adrp	x16, 0x736000
  6da9e4:      	ldr	x17, [x16, #0xa10]
  6da9e8:      	add	x16, x16, #0xa10
  6da9ec:      	br	x17

00000000006da9f0 <strlen@plt>:
  6da9f0:      	adrp	x16, 0x736000
  6da9f4:      	ldr	x17, [x16, #0xa18]
  6da9f8:      	add	x16, x16, #0xa18
  6da9fc:      	br	x17

00000000006daa00 <ff_cbs_insert_unit_content@plt>:
  6daa00:      	adrp	x16, 0x736000
  6daa04:      	ldr	x17, [x16, #0xa20]
  6daa08:      	add	x16, x16, #0xa20
  6daa0c:      	br	x17

00000000006daa10 <ff_cbs_delete_unit@plt>:
  6daa10:      	adrp	x16, 0x736000
  6daa14:      	ldr	x17, [x16, #0xa28]
  6daa18:      	add	x16, x16, #0xa28
  6daa1c:      	br	x17

00000000006daa20 <ff_cbs_make_unit_writable@plt>:
  6daa20:      	adrp	x16, 0x736000
  6daa24:      	ldr	x17, [x16, #0xa30]
  6daa28:      	add	x16, x16, #0xa30
  6daa2c:      	br	x17

00000000006daa30 <ff_refstruct_exclusive@plt>:
  6daa30:      	adrp	x16, 0x736000
  6daa34:      	ldr	x17, [x16, #0xa38]
  6daa38:      	add	x16, x16, #0xa38
  6daa3c:      	br	x17

00000000006daa40 <ff_cbs_discard_units@plt>:
  6daa40:      	adrp	x16, 0x736000
  6daa44:      	ldr	x17, [x16, #0xa40]
  6daa48:      	add	x16, x16, #0xa40
  6daa4c:      	br	x17

00000000006daa50 <ff_sbrdsp_init@plt>:
  6daa50:      	adrp	x16, 0x736000
  6daa54:      	ldr	x17, [x16, #0xa48]
  6daa58:      	add	x16, x16, #0xa48
  6daa5c:      	br	x17

00000000006daa60 <ff_sbrdsp_init_aarch64@plt>:
  6daa60:      	adrp	x16, 0x736000
  6daa64:      	ldr	x17, [x16, #0xa50]
  6daa68:      	add	x16, x16, #0xa50
  6daa6c:      	br	x17

00000000006daa70 <ff_me_cmp_init_aarch64@plt>:
  6daa70:      	adrp	x16, 0x736000
  6daa74:      	ldr	x17, [x16, #0xa58]
  6daa78:      	add	x16, x16, #0xa58
  6daa7c:      	br	x17

00000000006daa80 <ff_lzw_decode_open@plt>:
  6daa80:      	adrp	x16, 0x736000
  6daa84:      	ldr	x17, [x16, #0xa60]
  6daa88:      	add	x16, x16, #0xa60
  6daa8c:      	br	x17

00000000006daa90 <ff_reget_buffer@plt>:
  6daa90:      	adrp	x16, 0x736000
  6daa94:      	ldr	x17, [x16, #0xa68]
  6daa98:      	add	x16, x16, #0xa68
  6daa9c:      	br	x17

00000000006daaa0 <ff_lzw_decode_init@plt>:
  6daaa0:      	adrp	x16, 0x736000
  6daaa4:      	ldr	x17, [x16, #0xa70]
  6daaa8:      	add	x16, x16, #0xa70
  6daaac:      	br	x17

00000000006daab0 <ff_lzw_decode@plt>:
  6daab0:      	adrp	x16, 0x736000
  6daab4:      	ldr	x17, [x16, #0xa78]
  6daab8:      	add	x16, x16, #0xa78
  6daabc:      	br	x17

00000000006daac0 <ff_lzw_decode_tail@plt>:
  6daac0:      	adrp	x16, 0x736000
  6daac4:      	ldr	x17, [x16, #0xa80]
  6daac8:      	add	x16, x16, #0xa80
  6daacc:      	br	x17

00000000006daad0 <ff_lzw_decode_close@plt>:
  6daad0:      	adrp	x16, 0x736000
  6daad4:      	ldr	x17, [x16, #0xa88]
  6daad8:      	add	x16, x16, #0xa88
  6daadc:      	br	x17

00000000006daae0 <ff_mpeg4_mcsel_motion@plt>:
  6daae0:      	adrp	x16, 0x736000
  6daae4:      	ldr	x17, [x16, #0xa90]
  6daae8:      	add	x16, x16, #0xa90
  6daaec:      	br	x17

00000000006daaf0 <av_opt_set_defaults2@plt>:
  6daaf0:      	adrp	x16, 0x736000
  6daaf4:      	ldr	x17, [x16, #0xa98]
  6daaf8:      	add	x16, x16, #0xa98
  6daafc:      	br	x17

00000000006dab00 <av_codec_iterate@plt>:
  6dab00:      	adrp	x16, 0x736000
  6dab04:      	ldr	x17, [x16, #0xaa0]
  6dab08:      	add	x16, x16, #0xaa0
  6dab0c:      	br	x17

00000000006dab10 <ff_mjpeg_decode_dht@plt>:
  6dab10:      	adrp	x16, 0x736000
  6dab14:      	ldr	x17, [x16, #0xaa8]
  6dab18:      	add	x16, x16, #0xaa8
  6dab1c:      	br	x17

00000000006dab20 <ff_mjpeg_decode_dqt@plt>:
  6dab20:      	adrp	x16, 0x736000
  6dab24:      	ldr	x17, [x16, #0xab0]
  6dab28:      	add	x16, x16, #0xab0
  6dab2c:      	br	x17

00000000006dab30 <ff_mjpeg_decode_sof@plt>:
  6dab30:      	adrp	x16, 0x736000
  6dab34:      	ldr	x17, [x16, #0xab8]
  6dab38:      	add	x16, x16, #0xab8
  6dab3c:      	br	x17

00000000006dab40 <ff_mjpeg_decode_sos@plt>:
  6dab40:      	adrp	x16, 0x736000
  6dab44:      	ldr	x17, [x16, #0xac0]
  6dab48:      	add	x16, x16, #0xac0
  6dab4c:      	br	x17

00000000006dab50 <ff_jpegls_decode_picture@plt>:
  6dab50:      	adrp	x16, 0x736000
  6dab54:      	ldr	x17, [x16, #0xac8]
  6dab58:      	add	x16, x16, #0xac8
  6dab5c:      	br	x17

00000000006dab60 <ff_mjpeg_find_marker@plt>:
  6dab60:      	adrp	x16, 0x736000
  6dab64:      	ldr	x17, [x16, #0xad0]
  6dab68:      	add	x16, x16, #0xad0
  6dab6c:      	br	x17

00000000006dab70 <ff_mjpeg_decode_frame_from_buf@plt>:
  6dab70:      	adrp	x16, 0x736000
  6dab74:      	ldr	x17, [x16, #0xad8]
  6dab78:      	add	x16, x16, #0xad8
  6dab7c:      	br	x17

00000000006dab80 <av_dict_free@plt>:
  6dab80:      	adrp	x16, 0x736000
  6dab84:      	ldr	x17, [x16, #0xae0]
  6dab88:      	add	x16, x16, #0xae0
  6dab8c:      	br	x17

00000000006dab90 <ff_jpegls_decode_lse@plt>:
  6dab90:      	adrp	x16, 0x736000
  6dab94:      	ldr	x17, [x16, #0xae8]
  6dab98:      	add	x16, x16, #0xae8
  6dab9c:      	br	x17

00000000006daba0 <strncmp@plt>:
  6daba0:      	adrp	x16, 0x736000
  6daba4:      	ldr	x17, [x16, #0xaf0]
  6daba8:      	add	x16, x16, #0xaf0
  6dabac:      	br	x17

00000000006dabb0 <av_stereo3d_alloc@plt>:
  6dabb0:      	adrp	x16, 0x736000
  6dabb4:      	ldr	x17, [x16, #0xaf8]
  6dabb8:      	add	x16, x16, #0xaf8
  6dabbc:      	br	x17

00000000006dabc0 <ff_tdecode_header@plt>:
  6dabc0:      	adrp	x16, 0x736000
  6dabc4:      	ldr	x17, [x16, #0xb00]
  6dabc8:      	add	x16, x16, #0xb00
  6dabcc:      	br	x17

00000000006dabd0 <ff_exif_decode_ifd@plt>:
  6dabd0:      	adrp	x16, 0x736000
  6dabd4:      	ldr	x17, [x16, #0xb08]
  6dabd8:      	add	x16, x16, #0xb08
  6dabdc:      	br	x17

00000000006dabe0 <av_pix_fmt_count_planes@plt>:
  6dabe0:      	adrp	x16, 0x736000
  6dabe4:      	ldr	x17, [x16, #0xb10]
  6dabe8:      	add	x16, x16, #0xb10
  6dabec:      	br	x17

00000000006dabf0 <strspn@plt>:
  6dabf0:      	adrp	x16, 0x736000
  6dabf4:      	ldr	x17, [x16, #0xb18]
  6dabf8:      	add	x16, x16, #0xb18
  6dabfc:      	br	x17

00000000006dac00 <strtol@plt>:
  6dac00:      	adrp	x16, 0x736000
  6dac04:      	ldr	x17, [x16, #0xb20]
  6dac08:      	add	x16, x16, #0xb20
  6dac0c:      	br	x17

00000000006dac10 <av_display_rotation_set@plt>:
  6dac10:      	adrp	x16, 0x736000
  6dac14:      	ldr	x17, [x16, #0xb28]
  6dac18:      	add	x16, x16, #0xb28
  6dac1c:      	br	x17

00000000006dac20 <av_display_matrix_flip@plt>:
  6dac20:      	adrp	x16, 0x736000
  6dac24:      	ldr	x17, [x16, #0xb30]
  6dac28:      	add	x16, x16, #0xb30
  6dac2c:      	br	x17

00000000006dac30 <av_dict_copy@plt>:
  6dac30:      	adrp	x16, 0x736000
  6dac34:      	ldr	x17, [x16, #0xb38]
  6dac38:      	add	x16, x16, #0xb38
  6dac3c:      	br	x17

00000000006dac40 <ff_g722dsp_init@plt>:
  6dac40:      	adrp	x16, 0x736000
  6dac44:      	ldr	x17, [x16, #0xb40]
  6dac48:      	add	x16, x16, #0xb40
  6dac4c:      	br	x17

00000000006dac50 <ff_dovi_get_metadata@plt>:
  6dac50:      	adrp	x16, 0x736000
  6dac54:      	ldr	x17, [x16, #0xb48]
  6dac58:      	add	x16, x16, #0xb48
  6dac5c:      	br	x17

00000000006dac60 <av_dovi_metadata_alloc@plt>:
  6dac60:      	adrp	x16, 0x736000
  6dac64:      	ldr	x17, [x16, #0xb50]
  6dac68:      	add	x16, x16, #0xb50
  6dac6c:      	br	x17

00000000006dac70 <ff_psy_find_group@plt>:
  6dac70:      	adrp	x16, 0x736000
  6dac74:      	ldr	x17, [x16, #0xb58]
  6dac78:      	add	x16, x16, #0xb58
  6dac7c:      	br	x17

00000000006dac80 <ff_iir_filter_init_coeffs@plt>:
  6dac80:      	adrp	x16, 0x736000
  6dac84:      	ldr	x17, [x16, #0xb60]
  6dac88:      	add	x16, x16, #0xb60
  6dac8c:      	br	x17

00000000006dac90 <ff_iir_filter_init_state@plt>:
  6dac90:      	adrp	x16, 0x736000
  6dac94:      	ldr	x17, [x16, #0xb68]
  6dac98:      	add	x16, x16, #0xb68
  6dac9c:      	br	x17

00000000006daca0 <ff_iir_filter_init@plt>:
  6daca0:      	adrp	x16, 0x736000
  6daca4:      	ldr	x17, [x16, #0xb70]
  6daca8:      	add	x16, x16, #0xb70
  6dacac:      	br	x17

00000000006dacb0 <ff_iir_filter_free_coeffsp@plt>:
  6dacb0:      	adrp	x16, 0x736000
  6dacb4:      	ldr	x17, [x16, #0xb78]
  6dacb8:      	add	x16, x16, #0xb78
  6dacbc:      	br	x17

00000000006dacc0 <ff_iir_filter_free_statep@plt>:
  6dacc0:      	adrp	x16, 0x736000
  6dacc4:      	ldr	x17, [x16, #0xb80]
  6dacc8:      	add	x16, x16, #0xb80
  6daccc:      	br	x17

00000000006dacd0 <ff_lpc_calc_ref_coefs_f@plt>:
  6dacd0:      	adrp	x16, 0x736000
  6dacd4:      	ldr	x17, [x16, #0xb88]
  6dacd8:      	add	x16, x16, #0xb88
  6dacdc:      	br	x17

00000000006dace0 <ff_lpc_calc_coefs@plt>:
  6dace0:      	adrp	x16, 0x736000
  6dace4:      	ldr	x17, [x16, #0xb90]
  6dace8:      	add	x16, x16, #0xb90
  6dacec:      	br	x17

00000000006dacf0 <avpriv_init_lls@plt>:
  6dacf0:      	adrp	x16, 0x736000
  6dacf4:      	ldr	x17, [x16, #0xb98]
  6dacf8:      	add	x16, x16, #0xb98
  6dacfc:      	br	x17

00000000006dad00 <avpriv_solve_lls@plt>:
  6dad00:      	adrp	x16, 0x736000
  6dad04:      	ldr	x17, [x16, #0xba0]
  6dad08:      	add	x16, x16, #0xba0
  6dad0c:      	br	x17

00000000006dad10 <ff_evc_parse_slice_header@plt>:
  6dad10:      	adrp	x16, 0x736000
  6dad14:      	ldr	x17, [x16, #0xba8]
  6dad18:      	add	x16, x16, #0xba8
  6dad1c:      	br	x17

00000000006dad20 <ff_evc_derive_poc@plt>:
  6dad20:      	adrp	x16, 0x736000
  6dad24:      	ldr	x17, [x16, #0xbb0]
  6dad28:      	add	x16, x16, #0xbb0
  6dad2c:      	br	x17

00000000006dad30 <av_crc_init@plt>:
  6dad30:      	adrp	x16, 0x736000
  6dad34:      	ldr	x17, [x16, #0xbb8]
  6dad38:      	add	x16, x16, #0xbb8
  6dad3c:      	br	x17

00000000006dad40 <ff_mlp_checksum16@plt>:
  6dad40:      	adrp	x16, 0x736000
  6dad44:      	ldr	x17, [x16, #0xbc0]
  6dad48:      	add	x16, x16, #0xbc0
  6dad4c:      	br	x17

00000000006dad50 <ff_refstruct_pool_alloc_ext_c@plt>:
  6dad50:      	adrp	x16, 0x736000
  6dad54:      	ldr	x17, [x16, #0xbc8]
  6dad58:      	add	x16, x16, #0xbc8
  6dad5c:      	br	x17

00000000006dad60 <pthread_mutex_init@plt>:
  6dad60:      	adrp	x16, 0x736000
  6dad64:      	ldr	x17, [x16, #0xbd0]
  6dad68:      	add	x16, x16, #0xbd0
  6dad6c:      	br	x17

00000000006dad70 <pthread_mutex_destroy@plt>:
  6dad70:      	adrp	x16, 0x736000
  6dad74:      	ldr	x17, [x16, #0xbd8]
  6dad78:      	add	x16, x16, #0xbd8
  6dad7c:      	br	x17

00000000006dad80 <ff_h263_decode_init@plt>:
  6dad80:      	adrp	x16, 0x736000
  6dad84:      	ldr	x17, [x16, #0xbe0]
  6dad88:      	add	x16, x16, #0xbe0
  6dad8c:      	br	x17

00000000006dad90 <ff_h263_decode_init_vlc@plt>:
  6dad90:      	adrp	x16, 0x736000
  6dad94:      	ldr	x17, [x16, #0xbe8]
  6dad98:      	add	x16, x16, #0xbe8
  6dad9c:      	br	x17

00000000006dada0 <ff_mpeg4_decode_picture_header@plt>:
  6dada0:      	adrp	x16, 0x736000
  6dada4:      	ldr	x17, [x16, #0xbf0]
  6dada8:      	add	x16, x16, #0xbf0
  6dadac:      	br	x17

00000000006dadb0 <ff_h263_decode_picture_header@plt>:
  6dadb0:      	adrp	x16, 0x736000
  6dadb4:      	ldr	x17, [x16, #0xbf8]
  6dadb8:      	add	x16, x16, #0xbf8
  6dadbc:      	br	x17

00000000006dadc0 <ff_mpeg4_workaround_bugs@plt>:
  6dadc0:      	adrp	x16, 0x736000
  6dadc4:      	ldr	x17, [x16, #0xc00]
  6dadc8:      	add	x16, x16, #0xc00
  6dadcc:      	br	x17

00000000006dadd0 <ff_decode_frame_props@plt>:
  6dadd0:      	adrp	x16, 0x736000
  6dadd4:      	ldr	x17, [x16, #0xc08]
  6dadd8:      	add	x16, x16, #0xc08
  6daddc:      	br	x17

00000000006dade0 <ff_h263_resync@plt>:
  6dade0:      	adrp	x16, 0x736000
  6dade4:      	ldr	x17, [x16, #0xc10]
  6dade8:      	add	x16, x16, #0xc10
  6dadec:      	br	x17

00000000006dadf0 <ff_mpeg4_frame_end@plt>:
  6dadf0:      	adrp	x16, 0x736000
  6dadf4:      	ldr	x17, [x16, #0xc18]
  6dadf8:      	add	x16, x16, #0xc18
  6dadfc:      	br	x17

00000000006dae00 <ff_mpeg4_decode_studio_slice_header@plt>:
  6dae00:      	adrp	x16, 0x736000
  6dae04:      	ldr	x17, [x16, #0xc20]
  6dae08:      	add	x16, x16, #0xc20
  6dae0c:      	br	x17

00000000006dae10 <ff_mpeg4_decode_partitions@plt>:
  6dae10:      	adrp	x16, 0x736000
  6dae14:      	ldr	x17, [x16, #0xc28]
  6dae18:      	add	x16, x16, #0xc28
  6dae1c:      	br	x17

00000000006dae20 <ff_thread_progress_init@plt>:
  6dae20:      	adrp	x16, 0x736000
  6dae24:      	ldr	x17, [x16, #0xc30]
  6dae28:      	add	x16, x16, #0xc30
  6dae2c:      	br	x17

00000000006dae30 <ff_pthread_init@plt>:
  6dae30:      	adrp	x16, 0x736000
  6dae34:      	ldr	x17, [x16, #0xc38]
  6dae38:      	add	x16, x16, #0xc38
  6dae3c:      	br	x17

00000000006dae40 <ff_thread_progress_destroy@plt>:
  6dae40:      	adrp	x16, 0x736000
  6dae44:      	ldr	x17, [x16, #0xc40]
  6dae48:      	add	x16, x16, #0xc40
  6dae4c:      	br	x17

00000000006dae50 <ff_pthread_free@plt>:
  6dae50:      	adrp	x16, 0x736000
  6dae54:      	ldr	x17, [x16, #0xc48]
  6dae58:      	add	x16, x16, #0xc48
  6dae5c:      	br	x17

00000000006dae60 <pthread_cond_broadcast@plt>:
  6dae60:      	adrp	x16, 0x736000
  6dae64:      	ldr	x17, [x16, #0xc50]
  6dae68:      	add	x16, x16, #0xc50
  6dae6c:      	br	x17

00000000006dae70 <pthread_cond_wait@plt>:
  6dae70:      	adrp	x16, 0x736000
  6dae74:      	ldr	x17, [x16, #0xc58]
  6dae78:      	add	x16, x16, #0xc58
  6dae7c:      	br	x17

00000000006dae80 <ff_llvidencdsp_init@plt>:
  6dae80:      	adrp	x16, 0x736000
  6dae84:      	ldr	x17, [x16, #0xc60]
  6dae88:      	add	x16, x16, #0xc60
  6dae8c:      	br	x17

00000000006dae90 <ff_ps_apply_fixed@plt>:
  6dae90:      	adrp	x16, 0x736000
  6dae94:      	ldr	x17, [x16, #0xc68]
  6dae98:      	add	x16, x16, #0xc68
  6dae9c:      	br	x17

00000000006daea0 <ff_ps_init_fixed@plt>:
  6daea0:      	adrp	x16, 0x736000
  6daea4:      	ldr	x17, [x16, #0xc70]
  6daea8:      	add	x16, x16, #0xc70
  6daeac:      	br	x17

00000000006daeb0 <ff_h263_encode_motion@plt>:
  6daeb0:      	adrp	x16, 0x736000
  6daeb4:      	ldr	x17, [x16, #0xc78]
  6daeb8:      	add	x16, x16, #0xc78
  6daebc:      	br	x17

00000000006daec0 <ff_h263_aspect_to_info@plt>:
  6daec0:      	adrp	x16, 0x736000
  6daec4:      	ldr	x17, [x16, #0xc80]
  6daec8:      	add	x16, x16, #0xc80
  6daecc:      	br	x17

00000000006daed0 <ff_qpeldsp_init@plt>:
  6daed0:      	adrp	x16, 0x736000
  6daed4:      	ldr	x17, [x16, #0xc88]
  6daed8:      	add	x16, x16, #0xc88
  6daedc:      	br	x17

00000000006daee0 <av_dynamic_hdr_plus_alloc@plt>:
  6daee0:      	adrp	x16, 0x736000
  6daee4:      	ldr	x17, [x16, #0xc90]
  6daee8:      	add	x16, x16, #0xc90
  6daeec:      	br	x17

00000000006daef0 <av_dynamic_hdr_plus_from_t35@plt>:
  6daef0:      	adrp	x16, 0x736000
  6daef4:      	ldr	x17, [x16, #0xc98]
  6daef8:      	add	x16, x16, #0xc98
  6daefc:      	br	x17

00000000006daf00 <av_dynamic_hdr_vivid_alloc@plt>:
  6daf00:      	adrp	x16, 0x736000
  6daf04:      	ldr	x17, [x16, #0xca0]
  6daf08:      	add	x16, x16, #0xca0
  6daf0c:      	br	x17

00000000006daf10 <ff_parse_itu_t_t35_to_dynamic_hdr_vivid@plt>:
  6daf10:      	adrp	x16, 0x736000
  6daf14:      	ldr	x17, [x16, #0xca8]
  6daf18:      	add	x16, x16, #0xca8
  6daf1c:      	br	x17

00000000006daf20 <ff_parse_a53_cc@plt>:
  6daf20:      	adrp	x16, 0x736000
  6daf24:      	ldr	x17, [x16, #0xcb0]
  6daf28:      	add	x16, x16, #0xcb0
  6daf2c:      	br	x17

00000000006daf30 <av_film_grain_params_create_side_data@plt>:
  6daf30:      	adrp	x16, 0x736000
  6daf34:      	ldr	x17, [x16, #0xcb8]
  6daf38:      	add	x16, x16, #0xcb8
  6daf3c:      	br	x17

00000000006daf40 <av_frame_side_data_add@plt>:
  6daf40:      	adrp	x16, 0x736000
  6daf44:      	ldr	x17, [x16, #0xcc0]
  6daf48:      	add	x16, x16, #0xcc0
  6daf4c:      	br	x17

00000000006daf50 <av_ambient_viewing_environment_alloc@plt>:
  6daf50:      	adrp	x16, 0x736000
  6daf54:      	ldr	x17, [x16, #0xcc8]
  6daf58:      	add	x16, x16, #0xcc8
  6daf5c:      	br	x17

00000000006daf60 <ff_frame_new_side_data_from_buf_ext@plt>:
  6daf60:      	adrp	x16, 0x736000
  6daf64:      	ldr	x17, [x16, #0xcd0]
  6daf68:      	add	x16, x16, #0xcd0
  6daf6c:      	br	x17

00000000006daf70 <ff_decode_mastering_display_new_ext@plt>:
  6daf70:      	adrp	x16, 0x736000
  6daf74:      	ldr	x17, [x16, #0xcd8]
  6daf78:      	add	x16, x16, #0xcd8
  6daf7c:      	br	x17

00000000006daf80 <ff_decode_content_light_new_ext@plt>:
  6daf80:      	adrp	x16, 0x736000
  6daf84:      	ldr	x17, [x16, #0xce0]
  6daf88:      	add	x16, x16, #0xce0
  6daf8c:      	br	x17

00000000006daf90 <av_jni_get_java_vm@plt>:
  6daf90:      	adrp	x16, 0x736000
  6daf94:      	ldr	x17, [x16, #0xce8]
  6daf98:      	add	x16, x16, #0xce8
  6daf9c:      	br	x17

00000000006dafa0 <ff_ps_apply@plt>:
  6dafa0:      	adrp	x16, 0x736000
  6dafa4:      	ldr	x17, [x16, #0xcf0]
  6dafa8:      	add	x16, x16, #0xcf0
  6dafac:      	br	x17

00000000006dafb0 <ff_ps_init@plt>:
  6dafb0:      	adrp	x16, 0x736000
  6dafb4:      	ldr	x17, [x16, #0xcf8]
  6dafb8:      	add	x16, x16, #0xcf8
  6dafbc:      	br	x17

00000000006dafc0 <ff_frame_thread_encoder_init@plt>:
  6dafc0:      	adrp	x16, 0x736000
  6dafc4:      	ldr	x17, [x16, #0xd00]
  6dafc8:      	add	x16, x16, #0xd00
  6dafcc:      	br	x17

00000000006dafd0 <av_cpu_count@plt>:
  6dafd0:      	adrp	x16, 0x736000
  6dafd4:      	ldr	x17, [x16, #0xd08]
  6dafd8:      	add	x16, x16, #0xd08
  6dafdc:      	br	x17

00000000006dafe0 <av_opt_copy@plt>:
  6dafe0:      	adrp	x16, 0x736000
  6dafe4:      	ldr	x17, [x16, #0xd10]
  6dafe8:      	add	x16, x16, #0xd10
  6dafec:      	br	x17

00000000006daff0 <pthread_create@plt>:
  6daff0:      	adrp	x16, 0x736000
  6daff4:      	ldr	x17, [x16, #0xd18]
  6daff8:      	add	x16, x16, #0xd18
  6daffc:      	br	x17

00000000006db000 <ff_encode_encode_cb@plt>:
  6db000:      	adrp	x16, 0x736000
  6db004:      	ldr	x17, [x16, #0xd20]
  6db008:      	add	x16, x16, #0xd20
  6db00c:      	br	x17

00000000006db010 <pthread_cond_signal@plt>:
  6db010:      	adrp	x16, 0x736000
  6db014:      	ldr	x17, [x16, #0xd28]
  6db018:      	add	x16, x16, #0xd28
  6db01c:      	br	x17

00000000006db020 <pthread_join@plt>:
  6db020:      	adrp	x16, 0x736000
  6db024:      	ldr	x17, [x16, #0xd30]
  6db028:      	add	x16, x16, #0xd30
  6db02c:      	br	x17

00000000006db030 <ff_thread_video_encode_frame@plt>:
  6db030:      	adrp	x16, 0x736000
  6db034:      	ldr	x17, [x16, #0xd38]
  6db038:      	add	x16, x16, #0xd38
  6db03c:      	br	x17

00000000006db040 <av_packet_move_ref@plt>:
  6db040:      	adrp	x16, 0x736000
  6db044:      	ldr	x17, [x16, #0xd40]
  6db048:      	add	x16, x16, #0xd40
  6db04c:      	br	x17

00000000006db050 <ff_vlc_init_table_from_lengths@plt>:
  6db050:      	adrp	x16, 0x736000
  6db054:      	ldr	x17, [x16, #0xd48]
  6db058:      	add	x16, x16, #0xd48
  6db05c:      	br	x17

00000000006db060 <av_realloc_f@plt>:
  6db060:      	adrp	x16, 0x736000
  6db064:      	ldr	x17, [x16, #0xd50]
  6db068:      	add	x16, x16, #0xd50
  6db06c:      	br	x17

00000000006db070 <ff_h263_show_pict_info@plt>:
  6db070:      	adrp	x16, 0x736000
  6db074:      	ldr	x17, [x16, #0xd58]
  6db078:      	add	x16, x16, #0xd58
  6db07c:      	br	x17

00000000006db080 <ff_h263_decode_mba@plt>:
  6db080:      	adrp	x16, 0x736000
  6db084:      	ldr	x17, [x16, #0xd60]
  6db088:      	add	x16, x16, #0xd60
  6db08c:      	br	x17

00000000006db090 <ff_h263_decode_motion@plt>:
  6db090:      	adrp	x16, 0x736000
  6db094:      	ldr	x17, [x16, #0xd68]
  6db098:      	add	x16, x16, #0xd68
  6db09c:      	br	x17

00000000006db0a0 <ff_mpeg4_decode_video_packet_header@plt>:
  6db0a0:      	adrp	x16, 0x736000
  6db0a4:      	ldr	x17, [x16, #0xd70]
  6db0a8:      	add	x16, x16, #0xd70
  6db0ac:      	br	x17

00000000006db0b0 <ff_png_filter_row@plt>:
  6db0b0:      	adrp	x16, 0x736000
  6db0b4:      	ldr	x17, [x16, #0xd78]
  6db0b8:      	add	x16, x16, #0xd78
  6db0bc:      	br	x17

00000000006db0c0 <ff_progress_frame_replace@plt>:
  6db0c0:      	adrp	x16, 0x736000
  6db0c4:      	ldr	x17, [x16, #0xd80]
  6db0c8:      	add	x16, x16, #0xd80
  6db0cc:      	br	x17

00000000006db0d0 <ff_decode_content_light_new@plt>:
  6db0d0:      	adrp	x16, 0x736000
  6db0d4:      	ldr	x17, [x16, #0xd88]
  6db0d8:      	add	x16, x16, #0xd88
  6db0dc:      	br	x17

00000000006db0e0 <ff_decode_mastering_display_new@plt>:
  6db0e0:      	adrp	x16, 0x736000
  6db0e4:      	ldr	x17, [x16, #0xd90]
  6db0e8:      	add	x16, x16, #0xd90
  6db0ec:      	br	x17

00000000006db0f0 <av_csp_primaries_id_from_desc@plt>:
  6db0f0:      	adrp	x16, 0x736000
  6db0f4:      	ldr	x17, [x16, #0xd98]
  6db0f8:      	add	x16, x16, #0xd98
  6db0fc:      	br	x17

00000000006db100 <av_image_get_linesize@plt>:
  6db100:      	adrp	x16, 0x736000
  6db104:      	ldr	x17, [x16, #0xda0]
  6db108:      	add	x16, x16, #0xda0
  6db10c:      	br	x17

00000000006db110 <av_frame_copy@plt>:
  6db110:      	adrp	x16, 0x736000
  6db114:      	ldr	x17, [x16, #0xda8]
  6db118:      	add	x16, x16, #0xda8
  6db11c:      	br	x17

00000000006db120 <memchr@plt>:
  6db120:      	adrp	x16, 0x736000
  6db124:      	ldr	x17, [x16, #0xdb0]
  6db128:      	add	x16, x16, #0xdb0
  6db12c:      	br	x17

00000000006db130 <av_bprint_get_buffer@plt>:
  6db130:      	adrp	x16, 0x736000
  6db134:      	ldr	x17, [x16, #0xdb8]
  6db138:      	add	x16, x16, #0xdb8
  6db13c:      	br	x17

00000000006db140 <ff_ac3dsp_downmix_fixed@plt>:
  6db140:      	adrp	x16, 0x736000
  6db144:      	ldr	x17, [x16, #0xdc0]
  6db148:      	add	x16, x16, #0xdc0
  6db14c:      	br	x17

00000000006db150 <ff_ac3dsp_downmix@plt>:
  6db150:      	adrp	x16, 0x736000
  6db154:      	ldr	x17, [x16, #0xdc8]
  6db158:      	add	x16, x16, #0xdc8
  6db15c:      	br	x17

00000000006db160 <ff_ac3dsp_init_aarch64@plt>:
  6db160:      	adrp	x16, 0x736000
  6db164:      	ldr	x17, [x16, #0xdd0]
  6db168:      	add	x16, x16, #0xdd0
  6db16c:      	br	x17

00000000006db170 <ff_container_fifo_alloc@plt>:
  6db170:      	adrp	x16, 0x736000
  6db174:      	ldr	x17, [x16, #0xdd8]
  6db178:      	add	x16, x16, #0xdd8
  6db17c:      	br	x17

00000000006db180 <av_fifo_alloc2@plt>:
  6db180:      	adrp	x16, 0x736000
  6db184:      	ldr	x17, [x16, #0xde0]
  6db188:      	add	x16, x16, #0xde0
  6db18c:      	br	x17

00000000006db190 <av_fifo_freep2@plt>:
  6db190:      	adrp	x16, 0x736000
  6db194:      	ldr	x17, [x16, #0xde8]
  6db198:      	add	x16, x16, #0xde8
  6db19c:      	br	x17

00000000006db1a0 <av_fifo_write@plt>:
  6db1a0:      	adrp	x16, 0x736000
  6db1a4:      	ldr	x17, [x16, #0xdf0]
  6db1a8:      	add	x16, x16, #0xdf0
  6db1ac:      	br	x17

00000000006db1b0 <av_fifo_can_read@plt>:
  6db1b0:      	adrp	x16, 0x736000
  6db1b4:      	ldr	x17, [x16, #0xdf8]
  6db1b8:      	add	x16, x16, #0xdf8
  6db1bc:      	br	x17

00000000006db1c0 <av_fifo_read@plt>:
  6db1c0:      	adrp	x16, 0x736000
  6db1c4:      	ldr	x17, [x16, #0xe00]
  6db1c8:      	add	x16, x16, #0xe00
  6db1cc:      	br	x17

00000000006db1d0 <ff_ac3_find_syncword@plt>:
  6db1d0:      	adrp	x16, 0x736000
  6db1d4:      	ldr	x17, [x16, #0xe08]
  6db1d8:      	add	x16, x16, #0xe08
  6db1dc:      	br	x17

00000000006db1e0 <avpriv_ac3_parse_header@plt>:
  6db1e0:      	adrp	x16, 0x736000
  6db1e4:      	ldr	x17, [x16, #0xe10]
  6db1e8:      	add	x16, x16, #0xe10
  6db1ec:      	br	x17

00000000006db1f0 <av_bsf_get_by_name@plt>:
  6db1f0:      	adrp	x16, 0x736000
  6db1f4:      	ldr	x17, [x16, #0xe18]
  6db1f8:      	add	x16, x16, #0xe18
  6db1fc:      	br	x17

00000000006db200 <ff_epzs_motion_search@plt>:
  6db200:      	adrp	x16, 0x736000
  6db204:      	ldr	x17, [x16, #0xe20]
  6db208:      	add	x16, x16, #0xe20
  6db20c:      	br	x17

00000000006db210 <avcodec_find_decoder_by_name@plt>:
  6db210:      	adrp	x16, 0x736000
  6db214:      	ldr	x17, [x16, #0xe28]
  6db218:      	add	x16, x16, #0xe28
  6db21c:      	br	x17

00000000006db220 <ff_lcevc_alloc@plt>:
  6db220:      	adrp	x16, 0x736000
  6db224:      	ldr	x17, [x16, #0xe30]
  6db228:      	add	x16, x16, #0xe30
  6db22c:      	br	x17

00000000006db230 <ff_cbs_sei_alloc_message_payload@plt>:
  6db230:      	adrp	x16, 0x736000
  6db234:      	ldr	x17, [x16, #0xe38]
  6db238:      	add	x16, x16, #0xe38
  6db23c:      	br	x17

00000000006db240 <ff_cbs_sei_list_add@plt>:
  6db240:      	adrp	x16, 0x736000
  6db244:      	ldr	x17, [x16, #0xe40]
  6db248:      	add	x16, x16, #0xe40
  6db24c:      	br	x17

00000000006db250 <ff_cbs_sei_free_message_list@plt>:
  6db250:      	adrp	x16, 0x736000
  6db254:      	ldr	x17, [x16, #0xe48]
  6db258:      	add	x16, x16, #0xe48
  6db25c:      	br	x17

00000000006db260 <ff_cbs_sei_add_message@plt>:
  6db260:      	adrp	x16, 0x736000
  6db264:      	ldr	x17, [x16, #0xe50]
  6db268:      	add	x16, x16, #0xe50
  6db26c:      	br	x17

00000000006db270 <ff_cbs_sei_find_type@plt>:
  6db270:      	adrp	x16, 0x736000
  6db274:      	ldr	x17, [x16, #0xe58]
  6db278:      	add	x16, x16, #0xe58
  6db27c:      	br	x17

00000000006db280 <ff_cbs_sei_find_message@plt>:
  6db280:      	adrp	x16, 0x736000
  6db284:      	ldr	x17, [x16, #0xe60]
  6db288:      	add	x16, x16, #0xe60
  6db28c:      	br	x17

00000000006db290 <ff_cbs_sei_delete_message_type@plt>:
  6db290:      	adrp	x16, 0x736000
  6db294:      	ldr	x17, [x16, #0xe68]
  6db298:      	add	x16, x16, #0xe68
  6db29c:      	br	x17

00000000006db2a0 <av_init_packet@plt>:
  6db2a0:      	adrp	x16, 0x736000
  6db2a4:      	ldr	x17, [x16, #0xe70]
  6db2a8:      	add	x16, x16, #0xe70
  6db2ac:      	br	x17

00000000006db2b0 <av_packet_free_side_data@plt>:
  6db2b0:      	adrp	x16, 0x736000
  6db2b4:      	ldr	x17, [x16, #0xe78]
  6db2b8:      	add	x16, x16, #0xe78
  6db2bc:      	br	x17

00000000006db2c0 <av_new_packet@plt>:
  6db2c0:      	adrp	x16, 0x736000
  6db2c4:      	ldr	x17, [x16, #0xe80]
  6db2c8:      	add	x16, x16, #0xe80
  6db2cc:      	br	x17

00000000006db2d0 <av_shrink_packet@plt>:
  6db2d0:      	adrp	x16, 0x736000
  6db2d4:      	ldr	x17, [x16, #0xe88]
  6db2d8:      	add	x16, x16, #0xe88
  6db2dc:      	br	x17

00000000006db2e0 <av_grow_packet@plt>:
  6db2e0:      	adrp	x16, 0x736000
  6db2e4:      	ldr	x17, [x16, #0xe90]
  6db2e8:      	add	x16, x16, #0xe90
  6db2ec:      	br	x17

00000000006db2f0 <av_buffer_is_writable@plt>:
  6db2f0:      	adrp	x16, 0x736000
  6db2f4:      	ldr	x17, [x16, #0xe98]
  6db2f8:      	add	x16, x16, #0xe98
  6db2fc:      	br	x17

00000000006db300 <av_packet_from_data@plt>:
  6db300:      	adrp	x16, 0x736000
  6db304:      	ldr	x17, [x16, #0xea0]
  6db308:      	add	x16, x16, #0xea0
  6db30c:      	br	x17

00000000006db310 <av_packet_pack_dictionary@plt>:
  6db310:      	adrp	x16, 0x736000
  6db314:      	ldr	x17, [x16, #0xea8]
  6db318:      	add	x16, x16, #0xea8
  6db31c:      	br	x17

00000000006db320 <av_dict_iterate@plt>:
  6db320:      	adrp	x16, 0x736000
  6db324:      	ldr	x17, [x16, #0xeb0]
  6db328:      	add	x16, x16, #0xeb0
  6db32c:      	br	x17

00000000006db330 <av_packet_unpack_dictionary@plt>:
  6db330:      	adrp	x16, 0x736000
  6db334:      	ldr	x17, [x16, #0xeb8]
  6db338:      	add	x16, x16, #0xeb8
  6db33c:      	br	x17

00000000006db340 <av_packet_copy_props@plt>:
  6db340:      	adrp	x16, 0x736000
  6db344:      	ldr	x17, [x16, #0xec0]
  6db348:      	add	x16, x16, #0xec0
  6db34c:      	br	x17

00000000006db350 <av_packet_ref@plt>:
  6db350:      	adrp	x16, 0x736000
  6db354:      	ldr	x17, [x16, #0xec8]
  6db358:      	add	x16, x16, #0xec8
  6db35c:      	br	x17

00000000006db360 <av_packet_clone@plt>:
  6db360:      	adrp	x16, 0x736000
  6db364:      	ldr	x17, [x16, #0xed0]
  6db368:      	add	x16, x16, #0xed0
  6db36c:      	br	x17

00000000006db370 <av_packet_make_refcounted@plt>:
  6db370:      	adrp	x16, 0x736000
  6db374:      	ldr	x17, [x16, #0xed8]
  6db378:      	add	x16, x16, #0xed8
  6db37c:      	br	x17

00000000006db380 <av_packet_make_writable@plt>:
  6db380:      	adrp	x16, 0x736000
  6db384:      	ldr	x17, [x16, #0xee0]
  6db388:      	add	x16, x16, #0xee0
  6db38c:      	br	x17

00000000006db390 <av_packet_rescale_ts@plt>:
  6db390:      	adrp	x16, 0x736000
  6db394:      	ldr	x17, [x16, #0xee8]
  6db398:      	add	x16, x16, #0xee8
  6db39c:      	br	x17

00000000006db3a0 <avpriv_packet_list_put@plt>:
  6db3a0:      	adrp	x16, 0x736000
  6db3a4:      	ldr	x17, [x16, #0xef0]
  6db3a8:      	add	x16, x16, #0xef0
  6db3ac:      	br	x17

00000000006db3b0 <avpriv_packet_list_get@plt>:
  6db3b0:      	adrp	x16, 0x736000
  6db3b4:      	ldr	x17, [x16, #0xef8]
  6db3b8:      	add	x16, x16, #0xef8
  6db3bc:      	br	x17

00000000006db3c0 <avpriv_packet_list_free@plt>:
  6db3c0:      	adrp	x16, 0x736000
  6db3c4:      	ldr	x17, [x16, #0xf00]
  6db3c8:      	add	x16, x16, #0xf00
  6db3cc:      	br	x17

00000000006db3d0 <ff_side_data_set_prft@plt>:
  6db3d0:      	adrp	x16, 0x736000
  6db3d4:      	ldr	x17, [x16, #0xf08]
  6db3d8:      	add	x16, x16, #0xf08
  6db3dc:      	br	x17

00000000006db3e0 <av_packet_side_data_get@plt>:
  6db3e0:      	adrp	x16, 0x736000
  6db3e4:      	ldr	x17, [x16, #0xf10]
  6db3e8:      	add	x16, x16, #0xf10
  6db3ec:      	br	x17

00000000006db3f0 <av_packet_side_data_new@plt>:
  6db3f0:      	adrp	x16, 0x736000
  6db3f4:      	ldr	x17, [x16, #0xf18]
  6db3f8:      	add	x16, x16, #0xf18
  6db3fc:      	br	x17

00000000006db400 <av_packet_side_data_remove@plt>:
  6db400:      	adrp	x16, 0x736000
  6db404:      	ldr	x17, [x16, #0xf20]
  6db408:      	add	x16, x16, #0xf20
  6db40c:      	br	x17

00000000006db410 <ff_fmt_convert_init@plt>:
  6db410:      	adrp	x16, 0x736000
  6db414:      	ldr	x17, [x16, #0xf28]
  6db418:      	add	x16, x16, #0xf28
  6db41c:      	br	x17

00000000006db420 <av_lfg_init@plt>:
  6db420:      	adrp	x16, 0x736000
  6db424:      	ldr	x17, [x16, #0xf30]
  6db428:      	add	x16, x16, #0xf30
  6db42c:      	br	x17

00000000006db430 <av_lfg_init_from_data@plt>:
  6db430:      	adrp	x16, 0x736000
  6db434:      	ldr	x17, [x16, #0xf38]
  6db438:      	add	x16, x16, #0xf38
  6db43c:      	br	x17

00000000006db440 <ff_ac3_parse_header@plt>:
  6db440:      	adrp	x16, 0x736000
  6db444:      	ldr	x17, [x16, #0xf40]
  6db448:      	add	x16, x16, #0xf40
  6db44c:      	br	x17

00000000006db450 <av_channel_layout_index_from_channel@plt>:
  6db450:      	adrp	x16, 0x736000
  6db454:      	ldr	x17, [x16, #0xf48]
  6db458:      	add	x16, x16, #0xf48
  6db45c:      	br	x17

00000000006db460 <av_downmix_info_update_side_data@plt>:
  6db460:      	adrp	x16, 0x736000
  6db464:      	ldr	x17, [x16, #0xf50]
  6db468:      	add	x16, x16, #0xf50
  6db46c:      	br	x17

00000000006db470 <av_bsf_alloc@plt>:
  6db470:      	adrp	x16, 0x736000
  6db474:      	ldr	x17, [x16, #0xf58]
  6db478:      	add	x16, x16, #0xf58
  6db47c:      	br	x17

00000000006db480 <av_bsf_init@plt>:
  6db480:      	adrp	x16, 0x736000
  6db484:      	ldr	x17, [x16, #0xf60]
  6db488:      	add	x16, x16, #0xf60
  6db48c:      	br	x17

00000000006db490 <av_bsf_flush@plt>:
  6db490:      	adrp	x16, 0x736000
  6db494:      	ldr	x17, [x16, #0xf68]
  6db498:      	add	x16, x16, #0xf68
  6db49c:      	br	x17

00000000006db4a0 <av_bsf_send_packet@plt>:
  6db4a0:      	adrp	x16, 0x736000
  6db4a4:      	ldr	x17, [x16, #0xf70]
  6db4a8:      	add	x16, x16, #0xf70
  6db4ac:      	br	x17

00000000006db4b0 <av_bsf_receive_packet@plt>:
  6db4b0:      	adrp	x16, 0x736000
  6db4b4:      	ldr	x17, [x16, #0xf78]
  6db4b8:      	add	x16, x16, #0xf78
  6db4bc:      	br	x17

00000000006db4c0 <ff_bsf_get_packet@plt>:
  6db4c0:      	adrp	x16, 0x736000
  6db4c4:      	ldr	x17, [x16, #0xf80]
  6db4c8:      	add	x16, x16, #0xf80
  6db4cc:      	br	x17

00000000006db4d0 <av_bsf_list_alloc@plt>:
  6db4d0:      	adrp	x16, 0x736000
  6db4d4:      	ldr	x17, [x16, #0xf88]
  6db4d8:      	add	x16, x16, #0xf88
  6db4dc:      	br	x17

00000000006db4e0 <av_bsf_list_free@plt>:
  6db4e0:      	adrp	x16, 0x736000
  6db4e4:      	ldr	x17, [x16, #0xf90]
  6db4e8:      	add	x16, x16, #0xf90
  6db4ec:      	br	x17

00000000006db4f0 <av_bsf_list_append@plt>:
  6db4f0:      	adrp	x16, 0x736000
  6db4f4:      	ldr	x17, [x16, #0xf98]
  6db4f8:      	add	x16, x16, #0xf98
  6db4fc:      	br	x17

00000000006db500 <av_dynarray_add_nofree@plt>:
  6db500:      	adrp	x16, 0x736000
  6db504:      	ldr	x17, [x16, #0xfa0]
  6db508:      	add	x16, x16, #0xfa0
  6db50c:      	br	x17

00000000006db510 <av_opt_next@plt>:
  6db510:      	adrp	x16, 0x736000
  6db514:      	ldr	x17, [x16, #0xfa8]
  6db518:      	add	x16, x16, #0xfa8
  6db51c:      	br	x17

00000000006db520 <av_opt_set_from_string@plt>:
  6db520:      	adrp	x16, 0x736000
  6db524:      	ldr	x17, [x16, #0xfb0]
  6db528:      	add	x16, x16, #0xfb0
  6db52c:      	br	x17

00000000006db530 <av_bsf_list_finalize@plt>:
  6db530:      	adrp	x16, 0x736000
  6db534:      	ldr	x17, [x16, #0xfb8]
  6db538:      	add	x16, x16, #0xfb8
  6db53c:      	br	x17

00000000006db540 <av_bsf_list_parse_str@plt>:
  6db540:      	adrp	x16, 0x736000
  6db544:      	ldr	x17, [x16, #0xfc0]
  6db548:      	add	x16, x16, #0xfc0
  6db54c:      	br	x17

00000000006db550 <av_get_token@plt>:
  6db550:      	adrp	x16, 0x736000
  6db554:      	ldr	x17, [x16, #0xfc8]
  6db558:      	add	x16, x16, #0xfc8
  6db55c:      	br	x17

00000000006db560 <av_strtok@plt>:
  6db560:      	adrp	x16, 0x736000
  6db564:      	ldr	x17, [x16, #0xfd0]
  6db568:      	add	x16, x16, #0xfd0
  6db56c:      	br	x17

00000000006db570 <av_bsf_get_null_filter@plt>:
  6db570:      	adrp	x16, 0x736000
  6db574:      	ldr	x17, [x16, #0xfd8]
  6db578:      	add	x16, x16, #0xfd8
  6db57c:      	br	x17

00000000006db580 <ff_sbrdsp_init_fixed@plt>:
  6db580:      	adrp	x16, 0x736000
  6db584:      	ldr	x17, [x16, #0xfe0]
  6db588:      	add	x16, x16, #0xfe0
  6db58c:      	br	x17

00000000006db590 <ff_ps_read_data@plt>:
  6db590:      	adrp	x16, 0x736000
  6db594:      	ldr	x17, [x16, #0xfe8]
  6db598:      	add	x16, x16, #0xfe8
  6db59c:      	br	x17

00000000006db5a0 <sem_wait@plt>:
  6db5a0:      	adrp	x16, 0x736000
  6db5a4:      	ldr	x17, [x16, #0xff0]
  6db5a8:      	add	x16, x16, #0xff0
  6db5ac:      	br	x17

00000000006db5b0 <opendir@plt>:
  6db5b0:      	adrp	x16, 0x736000
  6db5b4:      	ldr	x17, [x16, #0xff8]
  6db5b8:      	add	x16, x16, #0xff8
  6db5bc:      	br	x17

00000000006db5c0 <readdir@plt>:
  6db5c0:      	adrp	x16, 0x737000
  6db5c4:      	ldr	x17, [x16]
  6db5c8:      	add	x16, x16, #0x0
  6db5cc:      	br	x17

00000000006db5d0 <close@plt>:
  6db5d0:      	adrp	x16, 0x737000
  6db5d4:      	ldr	x17, [x16, #0x8]
  6db5d8:      	add	x16, x16, #0x8
  6db5dc:      	br	x17

00000000006db5e0 <closedir@plt>:
  6db5e0:      	adrp	x16, 0x737000
  6db5e4:      	ldr	x17, [x16, #0x10]
  6db5e8:      	add	x16, x16, #0x10
  6db5ec:      	br	x17

00000000006db5f0 <sem_destroy@plt>:
  6db5f0:      	adrp	x16, 0x737000
  6db5f4:      	ldr	x17, [x16, #0x18]
  6db5f8:      	add	x16, x16, #0x18
  6db5fc:      	br	x17

00000000006db600 <sem_init@plt>:
  6db600:      	adrp	x16, 0x737000
  6db604:      	ldr	x17, [x16, #0x20]
  6db608:      	add	x16, x16, #0x20
  6db60c:      	br	x17

00000000006db610 <open@plt>:
  6db610:      	adrp	x16, 0x737000
  6db614:      	ldr	x17, [x16, #0x28]
  6db618:      	add	x16, x16, #0x28
  6db61c:      	br	x17

00000000006db620 <mmap@plt>:
  6db620:      	adrp	x16, 0x737000
  6db624:      	ldr	x17, [x16, #0x30]
  6db628:      	add	x16, x16, #0x30
  6db62c:      	br	x17

00000000006db630 <sem_post@plt>:
  6db630:      	adrp	x16, 0x737000
  6db634:      	ldr	x17, [x16, #0x38]
  6db638:      	add	x16, x16, #0x38
  6db63c:      	br	x17

00000000006db640 <av_hwframe_get_buffer@plt>:
  6db640:      	adrp	x16, 0x737000
  6db644:      	ldr	x17, [x16, #0x40]
  6db648:      	add	x16, x16, #0x40
  6db64c:      	br	x17

00000000006db650 <av_image_fill_linesizes@plt>:
  6db650:      	adrp	x16, 0x737000
  6db654:      	ldr	x17, [x16, #0x48]
  6db658:      	add	x16, x16, #0x48
  6db65c:      	br	x17

00000000006db660 <av_buffer_pool_init@plt>:
  6db660:      	adrp	x16, 0x737000
  6db664:      	ldr	x17, [x16, #0x50]
  6db668:      	add	x16, x16, #0x50
  6db66c:      	br	x17

00000000006db670 <av_image_fill_plane_sizes@plt>:
  6db670:      	adrp	x16, 0x737000
  6db674:      	ldr	x17, [x16, #0x58]
  6db678:      	add	x16, x16, #0x58
  6db67c:      	br	x17

00000000006db680 <av_buffer_allocz@plt>:
  6db680:      	adrp	x16, 0x737000
  6db684:      	ldr	x17, [x16, #0x60]
  6db688:      	add	x16, x16, #0x60
  6db68c:      	br	x17

00000000006db690 <av_buffer_pool_get@plt>:
  6db690:      	adrp	x16, 0x737000
  6db694:      	ldr	x17, [x16, #0x68]
  6db698:      	add	x16, x16, #0x68
  6db69c:      	br	x17

00000000006db6a0 <av_buffer_pool_uninit@plt>:
  6db6a0:      	adrp	x16, 0x737000
  6db6a4:      	ldr	x17, [x16, #0x70]
  6db6a8:      	add	x16, x16, #0x70
  6db6ac:      	br	x17

00000000006db6b0 <avcodec_pix_fmt_to_codec_tag@plt>:
  6db6b0:      	adrp	x16, 0x737000
  6db6b4:      	ldr	x17, [x16, #0x78]
  6db6b8:      	add	x16, x16, #0x78
  6db6bc:      	br	x17

00000000006db6c0 <avpriv_pix_fmt_find@plt>:
  6db6c0:      	adrp	x16, 0x737000
  6db6c4:      	ldr	x17, [x16, #0x80]
  6db6c8:      	add	x16, x16, #0x80
  6db6cc:      	br	x17

00000000006db6d0 <av_expr_parse@plt>:
  6db6d0:      	adrp	x16, 0x737000
  6db6d4:      	ldr	x17, [x16, #0x88]
  6db6d8:      	add	x16, x16, #0x88
  6db6dc:      	br	x17

00000000006db6e0 <strchr@plt>:
  6db6e0:      	adrp	x16, 0x737000
  6db6e4:      	ldr	x17, [x16, #0x90]
  6db6e8:      	add	x16, x16, #0x90
  6db6ec:      	br	x17

00000000006db6f0 <av_expr_eval@plt>:
  6db6f0:      	adrp	x16, 0x737000
  6db6f4:      	ldr	x17, [x16, #0x98]
  6db6f8:      	add	x16, x16, #0x98
  6db6fc:      	br	x17

00000000006db700 <av_expr_free@plt>:
  6db700:      	adrp	x16, 0x737000
  6db704:      	ldr	x17, [x16, #0xa0]
  6db708:      	add	x16, x16, #0xa0
  6db70c:      	br	x17

00000000006db710 <ff_mpv_common_init_neon@plt>:
  6db710:      	adrp	x16, 0x737000
  6db714:      	ldr	x17, [x16, #0xa8]
  6db718:      	add	x16, x16, #0xa8
  6db71c:      	br	x17

00000000006db720 <av_get_cpu_flags@plt>:
  6db720:      	adrp	x16, 0x737000
  6db724:      	ldr	x17, [x16, #0xb0]
  6db728:      	add	x16, x16, #0xb0
  6db72c:      	br	x17

00000000006db730 <ff_slice_thread_free@plt>:
  6db730:      	adrp	x16, 0x737000
  6db734:      	ldr	x17, [x16, #0xb8]
  6db738:      	add	x16, x16, #0xb8
  6db73c:      	br	x17

00000000006db740 <avpriv_slicethread_free@plt>:
  6db740:      	adrp	x16, 0x737000
  6db744:      	ldr	x17, [x16, #0xc0]
  6db748:      	add	x16, x16, #0xc0
  6db74c:      	br	x17

00000000006db750 <pthread_cond_destroy@plt>:
  6db750:      	adrp	x16, 0x737000
  6db754:      	ldr	x17, [x16, #0xc8]
  6db758:      	add	x16, x16, #0xc8
  6db75c:      	br	x17

00000000006db760 <avpriv_slicethread_execute@plt>:
  6db760:      	adrp	x16, 0x737000
  6db764:      	ldr	x17, [x16, #0xd0]
  6db768:      	add	x16, x16, #0xd0
  6db76c:      	br	x17

00000000006db770 <ff_slice_thread_init@plt>:
  6db770:      	adrp	x16, 0x737000
  6db774:      	ldr	x17, [x16, #0xd8]
  6db778:      	add	x16, x16, #0xd8
  6db77c:      	br	x17

00000000006db780 <avpriv_slicethread_create@plt>:
  6db780:      	adrp	x16, 0x737000
  6db784:      	ldr	x17, [x16, #0xe0]
  6db788:      	add	x16, x16, #0xe0
  6db78c:      	br	x17

00000000006db790 <pthread_cond_init@plt>:
  6db790:      	adrp	x16, 0x737000
  6db794:      	ldr	x17, [x16, #0xe8]
  6db798:      	add	x16, x16, #0xe8
  6db79c:      	br	x17

00000000006db7a0 <ff_av1_extract_obu@plt>:
  6db7a0:      	adrp	x16, 0x737000
  6db7a4:      	ldr	x17, [x16, #0xf0]
  6db7a8:      	add	x16, x16, #0xf0
  6db7ac:      	br	x17

00000000006db7b0 <ff_av1_packet_split@plt>:
  6db7b0:      	adrp	x16, 0x737000
  6db7b4:      	ldr	x17, [x16, #0xf8]
  6db7b8:      	add	x16, x16, #0xf8
  6db7bc:      	br	x17

00000000006db7c0 <ff_av1_packet_uninit@plt>:
  6db7c0:      	adrp	x16, 0x737000
  6db7c4:      	ldr	x17, [x16, #0x100]
  6db7c8:      	add	x16, x16, #0x100
  6db7cc:      	br	x17

00000000006db7d0 <av_dirac_parse_sequence_header@plt>:
  6db7d0:      	adrp	x16, 0x737000
  6db7d4:      	ldr	x17, [x16, #0x108]
  6db7d8:      	add	x16, x16, #0x108
  6db7dc:      	br	x17

00000000006db7e0 <ff_h264_sei_stereo_mode@plt>:
  6db7e0:      	adrp	x16, 0x737000
  6db7e4:      	ldr	x17, [x16, #0x110]
  6db7e8:      	add	x16, x16, #0x110
  6db7ec:      	br	x17

00000000006db7f0 <ff_frame_thread_init@plt>:
  6db7f0:      	adrp	x16, 0x737000
  6db7f4:      	ldr	x17, [x16, #0x118]
  6db7f8:      	add	x16, x16, #0x118
  6db7fc:      	br	x17

00000000006db800 <ff_frame_thread_free@plt>:
  6db800:      	adrp	x16, 0x737000
  6db804:      	ldr	x17, [x16, #0x120]
  6db808:      	add	x16, x16, #0x120
  6db80c:      	br	x17

00000000006db810 <ff_thread_receive_frame@plt>:
  6db810:      	adrp	x16, 0x737000
  6db814:      	ldr	x17, [x16, #0x128]
  6db818:      	add	x16, x16, #0x128
  6db81c:      	br	x17

00000000006db820 <ff_decode_internal_sync@plt>:
  6db820:      	adrp	x16, 0x737000
  6db824:      	ldr	x17, [x16, #0x130]
  6db828:      	add	x16, x16, #0x130
  6db82c:      	br	x17

00000000006db830 <av_frame_side_data_clone@plt>:
  6db830:      	adrp	x16, 0x737000
  6db834:      	ldr	x17, [x16, #0x138]
  6db838:      	add	x16, x16, #0x138
  6db83c:      	br	x17

00000000006db840 <ff_thread_get_packet@plt>:
  6db840:      	adrp	x16, 0x737000
  6db844:      	ldr	x17, [x16, #0x140]
  6db848:      	add	x16, x16, #0x140
  6db84c:      	br	x17

00000000006db850 <prctl@plt>:
  6db850:      	adrp	x16, 0x737000
  6db854:      	ldr	x17, [x16, #0x148]
  6db858:      	add	x16, x16, #0x148
  6db85c:      	br	x17

00000000006db860 <ff_decode_receive_frame_internal@plt>:
  6db860:      	adrp	x16, 0x737000
  6db864:      	ldr	x17, [x16, #0x150]
  6db868:      	add	x16, x16, #0x150
  6db86c:      	br	x17

00000000006db870 <ff_llauddsp_init@plt>:
  6db870:      	adrp	x16, 0x737000
  6db874:      	ldr	x17, [x16, #0x158]
  6db878:      	add	x16, x16, #0x158
  6db87c:      	br	x17

00000000006db880 <ff_put_pixels8_l2_8@plt>:
  6db880:      	adrp	x16, 0x737000
  6db884:      	ldr	x17, [x16, #0x160]
  6db888:      	add	x16, x16, #0x160
  6db88c:      	br	x17

00000000006db890 <ff_init_2d_vlc_rl@plt>:
  6db890:      	adrp	x16, 0x737000
  6db894:      	ldr	x17, [x16, #0x168]
  6db898:      	add	x16, x16, #0x168
  6db89c:      	br	x17

00000000006db8a0 <pthread_getspecific@plt>:
  6db8a0:      	adrp	x16, 0x737000
  6db8a4:      	ldr	x17, [x16, #0x170]
  6db8a8:      	add	x16, x16, #0x170
  6db8ac:      	br	x17

00000000006db8b0 <pthread_setspecific@plt>:
  6db8b0:      	adrp	x16, 0x737000
  6db8b4:      	ldr	x17, [x16, #0x178]
  6db8b8:      	add	x16, x16, #0x178
  6db8bc:      	br	x17

00000000006db8c0 <pthread_key_create@plt>:
  6db8c0:      	adrp	x16, 0x737000
  6db8c4:      	ldr	x17, [x16, #0x180]
  6db8c8:      	add	x16, x16, #0x180
  6db8cc:      	br	x17

00000000006db8d0 <ff_jni_exception_get_summary@plt>:
  6db8d0:      	adrp	x16, 0x737000
  6db8d4:      	ldr	x17, [x16, #0x188]
  6db8d8:      	add	x16, x16, #0x188
  6db8dc:      	br	x17

00000000006db8e0 <ff_mlp_read_major_sync@plt>:
  6db8e0:      	adrp	x16, 0x737000
  6db8e4:      	ldr	x17, [x16, #0x190]
  6db8e8:      	add	x16, x16, #0x190
  6db8ec:      	br	x17

00000000006db8f0 <ff_mediacodec_dec_init@plt>:
  6db8f0:      	adrp	x16, 0x737000
  6db8f4:      	ldr	x17, [x16, #0x198]
  6db8f8:      	add	x16, x16, #0x198
  6db8fc:      	br	x17

00000000006db900 <ff_mediacodec_dec_close@plt>:
  6db900:      	adrp	x16, 0x737000
  6db904:      	ldr	x17, [x16, #0x1a0]
  6db908:      	add	x16, x16, #0x1a0
  6db90c:      	br	x17

00000000006db910 <ff_mediacodec_dec_send@plt>:
  6db910:      	adrp	x16, 0x737000
  6db914:      	ldr	x17, [x16, #0x1a8]
  6db918:      	add	x16, x16, #0x1a8
  6db91c:      	br	x17

00000000006db920 <ff_mediacodec_dec_receive@plt>:
  6db920:      	adrp	x16, 0x737000
  6db924:      	ldr	x17, [x16, #0x1b0]
  6db928:      	add	x16, x16, #0x1b0
  6db92c:      	br	x17

00000000006db930 <ff_mediacodec_dec_flush@plt>:
  6db930:      	adrp	x16, 0x737000
  6db934:      	ldr	x17, [x16, #0x1b8]
  6db938:      	add	x16, x16, #0x1b8
  6db93c:      	br	x17

00000000006db940 <ff_mediacodec_dec_is_flushing@plt>:
  6db940:      	adrp	x16, 0x737000
  6db944:      	ldr	x17, [x16, #0x1c0]
  6db948:      	add	x16, x16, #0x1c0
  6db94c:      	br	x17

00000000006db950 <ff_alloc_a53_sei@plt>:
  6db950:      	adrp	x16, 0x737000
  6db954:      	ldr	x17, [x16, #0x1c8]
  6db958:      	add	x16, x16, #0x1c8
  6db95c:      	br	x17

00000000006db960 <ff_mpv_framesize_alloc@plt>:
  6db960:      	adrp	x16, 0x737000
  6db964:      	ldr	x17, [x16, #0x1d0]
  6db968:      	add	x16, x16, #0x1d0
  6db96c:      	br	x17

00000000006db970 <ff_mpeg_er_init@plt>:
  6db970:      	adrp	x16, 0x737000
  6db974:      	ldr	x17, [x16, #0x1d8]
  6db978:      	add	x16, x16, #0x1d8
  6db97c:      	br	x17

00000000006db980 <ff_fmt_convert_init_aarch64@plt>:
  6db980:      	adrp	x16, 0x737000
  6db984:      	ldr	x17, [x16, #0x1e0]
  6db988:      	add	x16, x16, #0x1e0
  6db98c:      	br	x17

00000000006db990 <av_ac3_parse_header@plt>:
  6db990:      	adrp	x16, 0x737000
  6db994:      	ldr	x17, [x16, #0x1e8]
  6db998:      	add	x16, x16, #0x1e8
  6db99c:      	br	x17

00000000006db9a0 <ff_flacencdsp_init@plt>:
  6db9a0:      	adrp	x16, 0x737000
  6db9a4:      	ldr	x17, [x16, #0x1f0]
  6db9a8:      	add	x16, x16, #0x1f0
  6db9ac:      	br	x17

00000000006db9b0 <av_bessel_i0@plt>:
  6db9b0:      	adrp	x16, 0x737000
  6db9b4:      	ldr	x17, [x16, #0x1f8]
  6db9b8:      	add	x16, x16, #0x1f8
  6db9bc:      	br	x17

00000000006db9c0 <av_find_best_pix_fmt_of_2@plt>:
  6db9c0:      	adrp	x16, 0x737000
  6db9c4:      	ldr	x17, [x16, #0x200]
  6db9c8:      	add	x16, x16, #0x200
  6db9cc:      	br	x17

00000000006db9d0 <avpriv_mpeg4audio_get_config2@plt>:
  6db9d0:      	adrp	x16, 0x737000
  6db9d4:      	ldr	x17, [x16, #0x208]
  6db9d8:      	add	x16, x16, #0x208
  6db9dc:      	br	x17

00000000006db9e0 <av_vorbis_parse_frame_flags@plt>:
  6db9e0:      	adrp	x16, 0x737000
  6db9e4:      	ldr	x17, [x16, #0x210]
  6db9e8:      	add	x16, x16, #0x210
  6db9ec:      	br	x17

00000000006db9f0 <av_vorbis_parse_reset@plt>:
  6db9f0:      	adrp	x16, 0x737000
  6db9f4:      	ldr	x17, [x16, #0x218]
  6db9f8:      	add	x16, x16, #0x218
  6db9fc:      	br	x17

00000000006dba00 <av_vorbis_parse_free@plt>:
  6dba00:      	adrp	x16, 0x737000
  6dba04:      	ldr	x17, [x16, #0x220]
  6dba08:      	add	x16, x16, #0x220
  6dba0c:      	br	x17

00000000006dba10 <av_vorbis_parse_init@plt>:
  6dba10:      	adrp	x16, 0x737000
  6dba14:      	ldr	x17, [x16, #0x228]
  6dba18:      	add	x16, x16, #0x228
  6dba1c:      	br	x17

00000000006dba20 <ff_h264_pred_init_aarch64@plt>:
  6dba20:      	adrp	x16, 0x737000
  6dba24:      	ldr	x17, [x16, #0x230]
  6dba28:      	add	x16, x16, #0x230
  6dba2c:      	br	x17

00000000006dba30 <ff_videodsp_init_aarch64@plt>:
  6dba30:      	adrp	x16, 0x737000
  6dba34:      	ldr	x17, [x16, #0x238]
  6dba38:      	add	x16, x16, #0x238
  6dba3c:      	br	x17

00000000006dba40 <av_csp_primaries_desc_from_id@plt>:
  6dba40:      	adrp	x16, 0x737000
  6dba44:      	ldr	x17, [x16, #0x240]
  6dba48:      	add	x16, x16, #0x240
  6dba4c:      	br	x17

00000000006dba50 <av_csp_approximate_trc_gamma@plt>:
  6dba50:      	adrp	x16, 0x737000
  6dba54:      	ldr	x17, [x16, #0x248]
  6dba58:      	add	x16, x16, #0x248
  6dba5c:      	br	x17

00000000006dba60 <ff_h263_encode_mba@plt>:
  6dba60:      	adrp	x16, 0x737000
  6dba64:      	ldr	x17, [x16, #0x250]
  6dba68:      	add	x16, x16, #0x250
  6dba6c:      	br	x17

00000000006dba70 <ff_h264_guess_level@plt>:
  6dba70:      	adrp	x16, 0x737000
  6dba74:      	ldr	x17, [x16, #0x258]
  6dba78:      	add	x16, x16, #0x258
  6dba7c:      	br	x17

00000000006dba80 <av_buffer_get_ref_count@plt>:
  6dba80:      	adrp	x16, 0x737000
  6dba84:      	ldr	x17, [x16, #0x260]
  6dba88:      	add	x16, x16, #0x260
  6dba8c:      	br	x17

00000000006dba90 <ff_h264_remove_all_refs@plt>:
  6dba90:      	adrp	x16, 0x737000
  6dba94:      	ldr	x17, [x16, #0x268]
  6dba98:      	add	x16, x16, #0x268
  6dba9c:      	br	x17

00000000006dbaa0 <ff_tis_ifd@plt>:
  6dbaa0:      	adrp	x16, 0x737000
  6dbaa4:      	ldr	x17, [x16, #0x270]
  6dbaa8:      	add	x16, x16, #0x270
  6dbaac:      	br	x17

00000000006dbab0 <ff_tget_short@plt>:
  6dbab0:      	adrp	x16, 0x737000
  6dbab4:      	ldr	x17, [x16, #0x278]
  6dbab8:      	add	x16, x16, #0x278
  6dbabc:      	br	x17

00000000006dbac0 <ff_tget_long@plt>:
  6dbac0:      	adrp	x16, 0x737000
  6dbac4:      	ldr	x17, [x16, #0x280]
  6dbac8:      	add	x16, x16, #0x280
  6dbacc:      	br	x17

00000000006dbad0 <ff_tget_double@plt>:
  6dbad0:      	adrp	x16, 0x737000
  6dbad4:      	ldr	x17, [x16, #0x288]
  6dbad8:      	add	x16, x16, #0x288
  6dbadc:      	br	x17

00000000006dbae0 <ff_tadd_rational_metadata@plt>:
  6dbae0:      	adrp	x16, 0x737000
  6dbae4:      	ldr	x17, [x16, #0x290]
  6dbae8:      	add	x16, x16, #0x290
  6dbaec:      	br	x17

00000000006dbaf0 <ff_tadd_long_metadata@plt>:
  6dbaf0:      	adrp	x16, 0x737000
  6dbaf4:      	ldr	x17, [x16, #0x298]
  6dbaf8:      	add	x16, x16, #0x298
  6dbafc:      	br	x17

00000000006dbb00 <ff_tadd_doubles_metadata@plt>:
  6dbb00:      	adrp	x16, 0x737000
  6dbb04:      	ldr	x17, [x16, #0x2a0]
  6dbb08:      	add	x16, x16, #0x2a0
  6dbb0c:      	br	x17

00000000006dbb10 <ff_tadd_shorts_metadata@plt>:
  6dbb10:      	adrp	x16, 0x737000
  6dbb14:      	ldr	x17, [x16, #0x2a8]
  6dbb18:      	add	x16, x16, #0x2a8
  6dbb1c:      	br	x17

00000000006dbb20 <ff_tadd_bytes_metadata@plt>:
  6dbb20:      	adrp	x16, 0x737000
  6dbb24:      	ldr	x17, [x16, #0x2b0]
  6dbb28:      	add	x16, x16, #0x2b0
  6dbb2c:      	br	x17

00000000006dbb30 <ff_tadd_string_metadata@plt>:
  6dbb30:      	adrp	x16, 0x737000
  6dbb34:      	ldr	x17, [x16, #0x2b8]
  6dbb38:      	add	x16, x16, #0x2b8
  6dbb3c:      	br	x17

00000000006dbb40 <ff_tread_tag@plt>:
  6dbb40:      	adrp	x16, 0x737000
  6dbb44:      	ldr	x17, [x16, #0x2c0]
  6dbb48:      	add	x16, x16, #0x2c0
  6dbb4c:      	br	x17

00000000006dbb50 <avpriv_h264_has_num_reorder_frames@plt>:
  6dbb50:      	adrp	x16, 0x737000
  6dbb54:      	ldr	x17, [x16, #0x2c8]
  6dbb58:      	add	x16, x16, #0x2c8
  6dbb5c:      	br	x17

00000000006dbb60 <av_image_copy@plt>:
  6dbb60:      	adrp	x16, 0x737000
  6dbb64:      	ldr	x17, [x16, #0x2d0]
  6dbb68:      	add	x16, x16, #0x2d0
  6dbb6c:      	br	x17

00000000006dbb70 <ff_mpeg4_pred_ac@plt>:
  6dbb70:      	adrp	x16, 0x737000
  6dbb74:      	ldr	x17, [x16, #0x2d8]
  6dbb78:      	add	x16, x16, #0x2d8
  6dbb7c:      	br	x17

00000000006dbb80 <avpriv_exif_decode_ifd@plt>:
  6dbb80:      	adrp	x16, 0x737000
  6dbb84:      	ldr	x17, [x16, #0x2e0]
  6dbb88:      	add	x16, x16, #0x2e0
  6dbb8c:      	br	x17

00000000006dbb90 <ff_encode_get_frame@plt>:
  6dbb90:      	adrp	x16, 0x737000
  6dbb94:      	ldr	x17, [x16, #0x2e8]
  6dbb98:      	add	x16, x16, #0x2e8
  6dbb9c:      	br	x17

00000000006dbba0 <av_samples_copy@plt>:
  6dbba0:      	adrp	x16, 0x737000
  6dbba4:      	ldr	x17, [x16, #0x2f0]
  6dbba8:      	add	x16, x16, #0x2f0
  6dbbac:      	br	x17

00000000006dbbb0 <av_samples_set_silence@plt>:
  6dbbb0:      	adrp	x16, 0x737000
  6dbbb4:      	ldr	x17, [x16, #0x2f8]
  6dbbb8:      	add	x16, x16, #0x2f8
  6dbbbc:      	br	x17

00000000006dbbc0 <av_get_planar_sample_fmt@plt>:
  6dbbc0:      	adrp	x16, 0x737000
  6dbbc4:      	ldr	x17, [x16, #0x300]
  6dbbc8:      	add	x16, x16, #0x300
  6dbbcc:      	br	x17

00000000006dbbd0 <av_adler32_update@plt>:
  6dbbd0:      	adrp	x16, 0x737000
  6dbbd4:      	ldr	x17, [x16, #0x308]
  6dbbd8:      	add	x16, x16, #0x308
  6dbbdc:      	br	x17

00000000006dbbe0 <av_ts_make_time_string2@plt>:
  6dbbe0:      	adrp	x16, 0x737000
  6dbbe4:      	ldr	x17, [x16, #0x310]
  6dbbe8:      	add	x16, x16, #0x310
  6dbbec:      	br	x17

00000000006dbbf0 <av_fifo_can_write@plt>:
  6dbbf0:      	adrp	x16, 0x737000
  6dbbf4:      	ldr	x17, [x16, #0x318]
  6dbbf8:      	add	x16, x16, #0x318
  6dbbfc:      	br	x17

00000000006dbc00 <av_tree_find@plt>:
  6dbc00:      	adrp	x16, 0x737000
  6dbc04:      	ldr	x17, [x16, #0x320]
  6dbc08:      	add	x16, x16, #0x320
  6dbc0c:      	br	x17

00000000006dbc10 <av_tree_insert@plt>:
  6dbc10:      	adrp	x16, 0x737000
  6dbc14:      	ldr	x17, [x16, #0x328]
  6dbc18:      	add	x16, x16, #0x328
  6dbc1c:      	br	x17

00000000006dbc20 <av_tree_enumerate@plt>:
  6dbc20:      	adrp	x16, 0x737000
  6dbc24:      	ldr	x17, [x16, #0x330]
  6dbc28:      	add	x16, x16, #0x330
  6dbc2c:      	br	x17

00000000006dbc30 <av_tree_destroy@plt>:
  6dbc30:      	adrp	x16, 0x737000
  6dbc34:      	ldr	x17, [x16, #0x338]
  6dbc38:      	add	x16, x16, #0x338
  6dbc3c:      	br	x17

00000000006dbc40 <av_tree_node_alloc@plt>:
  6dbc40:      	adrp	x16, 0x737000
  6dbc44:      	ldr	x17, [x16, #0x340]
  6dbc48:      	add	x16, x16, #0x340
  6dbc4c:      	br	x17

00000000006dbc50 <av_rescale_q_rnd@plt>:
  6dbc50:      	adrp	x16, 0x737000
  6dbc54:      	ldr	x17, [x16, #0x348]
  6dbc58:      	add	x16, x16, #0x348
  6dbc5c:      	br	x17

00000000006dbc60 <av_strlcat@plt>:
  6dbc60:      	adrp	x16, 0x737000
  6dbc64:      	ldr	x17, [x16, #0x350]
  6dbc68:      	add	x16, x16, #0x350
  6dbc6c:      	br	x17

00000000006dbc70 <av_gettime@plt>:
  6dbc70:      	adrp	x16, 0x737000
  6dbc74:      	ldr	x17, [x16, #0x358]
  6dbc78:      	add	x16, x16, #0x358
  6dbc7c:      	br	x17

00000000006dbc80 <av_frame_make_writable@plt>:
  6dbc80:      	adrp	x16, 0x737000
  6dbc84:      	ldr	x17, [x16, #0x360]
  6dbc88:      	add	x16, x16, #0x360
  6dbc8c:      	br	x17

00000000006dbc90 <av_vlog@plt>:
  6dbc90:      	adrp	x16, 0x737000
  6dbc94:      	ldr	x17, [x16, #0x368]
  6dbc98:      	add	x16, x16, #0x368
  6dbc9c:      	br	x17

00000000006dbca0 <avcodec_send_packet@plt>:
  6dbca0:      	adrp	x16, 0x737000
  6dbca4:      	ldr	x17, [x16, #0x370]
  6dbca8:      	add	x16, x16, #0x370
  6dbcac:      	br	x17

00000000006dbcb0 <av_frame_apply_cropping@plt>:
  6dbcb0:      	adrp	x16, 0x737000
  6dbcb4:      	ldr	x17, [x16, #0x378]
  6dbcb8:      	add	x16, x16, #0x378
  6dbcbc:      	br	x17

00000000006dbcc0 <avcodec_decode_subtitle2@plt>:
  6dbcc0:      	adrp	x16, 0x737000
  6dbcc4:      	ldr	x17, [x16, #0x380]
  6dbcc8:      	add	x16, x16, #0x380
  6dbccc:      	br	x17

00000000006dbcd0 <avcodec_get_hw_frames_parameters@plt>:
  6dbcd0:      	adrp	x16, 0x737000
  6dbcd4:      	ldr	x17, [x16, #0x388]
  6dbcd8:      	add	x16, x16, #0x388
  6dbcdc:      	br	x17

00000000006dbce0 <av_hwframe_ctx_init@plt>:
  6dbce0:      	adrp	x16, 0x737000
  6dbce4:      	ldr	x17, [x16, #0x390]
  6dbce8:      	add	x16, x16, #0x390
  6dbcec:      	br	x17

00000000006dbcf0 <av_hwdevice_get_type_name@plt>:
  6dbcf0:      	adrp	x16, 0x737000
  6dbcf4:      	ldr	x17, [x16, #0x398]
  6dbcf8:      	add	x16, x16, #0x398
  6dbcfc:      	br	x17

00000000006dbd00 <av_hwframe_ctx_alloc@plt>:
  6dbd00:      	adrp	x16, 0x737000
  6dbd04:      	ldr	x17, [x16, #0x3a0]
  6dbd08:      	add	x16, x16, #0x3a0
  6dbd0c:      	br	x17

00000000006dbd10 <ff_decode_frame_props_from_pkt@plt>:
  6dbd10:      	adrp	x16, 0x737000
  6dbd14:      	ldr	x17, [x16, #0x3a8]
  6dbd18:      	add	x16, x16, #0x3a8
  6dbd1c:      	br	x17

00000000006dbd20 <av_buffer_make_writable@plt>:
  6dbd20:      	adrp	x16, 0x737000
  6dbd24:      	ldr	x17, [x16, #0x3b0]
  6dbd28:      	add	x16, x16, #0x3b0
  6dbd2c:      	br	x17

00000000006dbd30 <ff_attach_decode_data@plt>:
  6dbd30:      	adrp	x16, 0x737000
  6dbd34:      	ldr	x17, [x16, #0x3b8]
  6dbd38:      	add	x16, x16, #0x3b8
  6dbd3c:      	br	x17

00000000006dbd40 <av_frame_is_writable@plt>:
  6dbd40:      	adrp	x16, 0x737000
  6dbd44:      	ldr	x17, [x16, #0x3c0]
  6dbd48:      	add	x16, x16, #0x3c0
  6dbd4c:      	br	x17

00000000006dbd50 <av_frame_side_data_remove@plt>:
  6dbd50:      	adrp	x16, 0x737000
  6dbd54:      	ldr	x17, [x16, #0x3c8]
  6dbd58:      	add	x16, x16, #0x3c8
  6dbd5c:      	br	x17

00000000006dbd60 <av_mastering_display_metadata_alloc_size@plt>:
  6dbd60:      	adrp	x16, 0x737000
  6dbd64:      	ldr	x17, [x16, #0x3d0]
  6dbd68:      	add	x16, x16, #0x3d0
  6dbd6c:      	br	x17

00000000006dbd70 <av_mastering_display_metadata_create_side_data@plt>:
  6dbd70:      	adrp	x16, 0x737000
  6dbd74:      	ldr	x17, [x16, #0x3d8]
  6dbd78:      	add	x16, x16, #0x3d8
  6dbd7c:      	br	x17

00000000006dbd80 <av_content_light_metadata_alloc@plt>:
  6dbd80:      	adrp	x16, 0x737000
  6dbd84:      	ldr	x17, [x16, #0x3e0]
  6dbd88:      	add	x16, x16, #0x3e0
  6dbd8c:      	br	x17

00000000006dbd90 <av_content_light_metadata_create_side_data@plt>:
  6dbd90:      	adrp	x16, 0x737000
  6dbd94:      	ldr	x17, [x16, #0x3e8]
  6dbd98:      	add	x16, x16, #0x3e8
  6dbd9c:      	br	x17

00000000006dbda0 <ffio_init_write_context@plt>:
  6dbda0:      	adrp	x16, 0x737000
  6dbda4:      	ldr	x17, [x16, #0x3f0]
  6dbda8:      	add	x16, x16, #0x3f0
  6dbdac:      	br	x17

00000000006dbdb0 <avio_w8@plt>:
  6dbdb0:      	adrp	x16, 0x737000
  6dbdb4:      	ldr	x17, [x16, #0x3f8]
  6dbdb8:      	add	x16, x16, #0x3f8
  6dbdbc:      	br	x17

00000000006dbdc0 <avio_wl32@plt>:
  6dbdc0:      	adrp	x16, 0x737000
  6dbdc4:      	ldr	x17, [x16, #0x400]
  6dbdc8:      	add	x16, x16, #0x400
  6dbdcc:      	br	x17

00000000006dbdd0 <avio_wl16@plt>:
  6dbdd0:      	adrp	x16, 0x737000
  6dbdd4:      	ldr	x17, [x16, #0x408]
  6dbdd8:      	add	x16, x16, #0x408
  6dbddc:      	br	x17

00000000006dbde0 <avio_write@plt>:
  6dbde0:      	adrp	x16, 0x737000
  6dbde4:      	ldr	x17, [x16, #0x410]
  6dbde8:      	add	x16, x16, #0x410
  6dbdec:      	br	x17

00000000006dbdf0 <ff_put_guid@plt>:
  6dbdf0:      	adrp	x16, 0x737000
  6dbdf4:      	ldr	x17, [x16, #0x418]
  6dbdf8:      	add	x16, x16, #0x418
  6dbdfc:      	br	x17

00000000006dbe00 <avio_wl64@plt>:
  6dbe00:      	adrp	x16, 0x737000
  6dbe04:      	ldr	x17, [x16, #0x420]
  6dbe08:      	add	x16, x16, #0x420
  6dbe0c:      	br	x17

00000000006dbe10 <avio_seek@plt>:
  6dbe10:      	adrp	x16, 0x737000
  6dbe14:      	ldr	x17, [x16, #0x428]
  6dbe18:      	add	x16, x16, #0x428
  6dbe1c:      	br	x17

00000000006dbe20 <ff_metadata_conv@plt>:
  6dbe20:      	adrp	x16, 0x737000
  6dbe24:      	ldr	x17, [x16, #0x430]
  6dbe28:      	add	x16, x16, #0x430
  6dbe2c:      	br	x17

00000000006dbe30 <ff_parse_creation_time_metadata@plt>:
  6dbe30:      	adrp	x16, 0x737000
  6dbe34:      	ldr	x17, [x16, #0x438]
  6dbe38:      	add	x16, x16, #0x438
  6dbe3c:      	br	x17

00000000006dbe40 <av_dict_count@plt>:
  6dbe40:      	adrp	x16, 0x737000
  6dbe44:      	ldr	x17, [x16, #0x440]
  6dbe48:      	add	x16, x16, #0x440
  6dbe4c:      	br	x17

00000000006dbe50 <avpriv_set_pts_info@plt>:
  6dbe50:      	adrp	x16, 0x737000
  6dbe54:      	ldr	x17, [x16, #0x448]
  6dbe58:      	add	x16, x16, #0x448
  6dbe5c:      	br	x17

00000000006dbe60 <ff_convert_lang_to@plt>:
  6dbe60:      	adrp	x16, 0x737000
  6dbe64:      	ldr	x17, [x16, #0x450]
  6dbe68:      	add	x16, x16, #0x450
  6dbe6c:      	br	x17

00000000006dbe70 <avio_put_str16le@plt>:
  6dbe70:      	adrp	x16, 0x737000
  6dbe74:      	ldr	x17, [x16, #0x458]
  6dbe78:      	add	x16, x16, #0x458
  6dbe7c:      	br	x17

00000000006dbe80 <avio_open_dyn_buf@plt>:
  6dbe80:      	adrp	x16, 0x737000
  6dbe84:      	ldr	x17, [x16, #0x460]
  6dbe88:      	add	x16, x16, #0x460
  6dbe8c:      	br	x17

00000000006dbe90 <ffio_reset_dyn_buf@plt>:
  6dbe90:      	adrp	x16, 0x737000
  6dbe94:      	ldr	x17, [x16, #0x468]
  6dbe98:      	add	x16, x16, #0x468
  6dbe9c:      	br	x17

00000000006dbea0 <avio_get_dyn_buf@plt>:
  6dbea0:      	adrp	x16, 0x737000
  6dbea4:      	ldr	x17, [x16, #0x470]
  6dbea8:      	add	x16, x16, #0x470
  6dbeac:      	br	x17

00000000006dbeb0 <ff_put_wav_header@plt>:
  6dbeb0:      	adrp	x16, 0x737000
  6dbeb4:      	ldr	x17, [x16, #0x478]
  6dbeb8:      	add	x16, x16, #0x478
  6dbebc:      	br	x17

00000000006dbec0 <ff_put_bmp_header@plt>:
  6dbec0:      	adrp	x16, 0x737000
  6dbec4:      	ldr	x17, [x16, #0x480]
  6dbec8:      	add	x16, x16, #0x480
  6dbecc:      	br	x17

00000000006dbed0 <ffio_free_dyn_buf@plt>:
  6dbed0:      	adrp	x16, 0x737000
  6dbed4:      	ldr	x17, [x16, #0x488]
  6dbed8:      	add	x16, x16, #0x488
  6dbedc:      	br	x17

00000000006dbee0 <ffio_fill@plt>:
  6dbee0:      	adrp	x16, 0x737000
  6dbee4:      	ldr	x17, [x16, #0x490]
  6dbee8:      	add	x16, x16, #0x490
  6dbeec:      	br	x17

00000000006dbef0 <avio_write_marker@plt>:
  6dbef0:      	adrp	x16, 0x737000
  6dbef4:      	ldr	x17, [x16, #0x498]
  6dbef8:      	add	x16, x16, #0x498
  6dbefc:      	br	x17

00000000006dbf00 <ff_end_tag@plt>:
  6dbf00:      	adrp	x16, 0x737000
  6dbf04:      	ldr	x17, [x16, #0x4a0]
  6dbf08:      	add	x16, x16, #0x4a0
  6dbf0c:      	br	x17

00000000006dbf10 <ff_start_tag@plt>:
  6dbf10:      	adrp	x16, 0x737000
  6dbf14:      	ldr	x17, [x16, #0x4a8]
  6dbf18:      	add	x16, x16, #0x4a8
  6dbf1c:      	br	x17

00000000006dbf20 <strtoull@plt>:
  6dbf20:      	adrp	x16, 0x737000
  6dbf24:      	ldr	x17, [x16, #0x4b0]
  6dbf28:      	add	x16, x16, #0x4b0
  6dbf2c:      	br	x17

00000000006dbf30 <avio_wb64@plt>:
  6dbf30:      	adrp	x16, 0x737000
  6dbf34:      	ldr	x17, [x16, #0x4b8]
  6dbf38:      	add	x16, x16, #0x4b8
  6dbf3c:      	br	x17

00000000006dbf40 <avio_put_str@plt>:
  6dbf40:      	adrp	x16, 0x737000
  6dbf44:      	ldr	x17, [x16, #0x4c0]
  6dbf48:      	add	x16, x16, #0x4c0
  6dbf4c:      	br	x17

00000000006dbf50 <ff_riff_write_info@plt>:
  6dbf50:      	adrp	x16, 0x737000
  6dbf54:      	ldr	x17, [x16, #0x4c8]
  6dbf58:      	add	x16, x16, #0x4c8
  6dbf5c:      	br	x17

00000000006dbf60 <localtime_r@plt>:
  6dbf60:      	adrp	x16, 0x737000
  6dbf64:      	ldr	x17, [x16, #0x4d0]
  6dbf68:      	add	x16, x16, #0x4d0
  6dbf6c:      	br	x17

00000000006dbf70 <strftime@plt>:
  6dbf70:      	adrp	x16, 0x737000
  6dbf74:      	ldr	x17, [x16, #0x4d8]
  6dbf78:      	add	x16, x16, #0x4d8
  6dbf7c:      	br	x17

00000000006dbf80 <avio_wb32@plt>:
  6dbf80:      	adrp	x16, 0x737000
  6dbf84:      	ldr	x17, [x16, #0x4e0]
  6dbf88:      	add	x16, x16, #0x4e0
  6dbf8c:      	br	x17

00000000006dbf90 <ff_codec_get_id@plt>:
  6dbf90:      	adrp	x16, 0x737000
  6dbf94:      	ldr	x17, [x16, #0x4e8]
  6dbf98:      	add	x16, x16, #0x4e8
  6dbf9c:      	br	x17

00000000006dbfa0 <ff_vorbis_stream_comment@plt>:
  6dbfa0:      	adrp	x16, 0x737000
  6dbfa4:      	ldr	x17, [x16, #0x4f0]
  6dbfa8:      	add	x16, x16, #0x4f0
  6dbfac:      	br	x17

00000000006dbfb0 <ff_alloc_extradata@plt>:
  6dbfb0:      	adrp	x16, 0x737000
  6dbfb4:      	ldr	x17, [x16, #0x4f8]
  6dbfb8:      	add	x16, x16, #0x4f8
  6dbfbc:      	br	x17

00000000006dbfc0 <av_iamf_audio_element_free@plt>:
  6dbfc0:      	adrp	x16, 0x737000
  6dbfc4:      	ldr	x17, [x16, #0x500]
  6dbfc8:      	add	x16, x16, #0x500
  6dbfcc:      	br	x17

00000000006dbfd0 <av_iamf_mix_presentation_free@plt>:
  6dbfd0:      	adrp	x16, 0x737000
  6dbfd4:      	ldr	x17, [x16, #0x508]
  6dbfd8:      	add	x16, x16, #0x508
  6dbfdc:      	br	x17

00000000006dbfe0 <av_url_split@plt>:
  6dbfe0:      	adrp	x16, 0x737000
  6dbfe4:      	ldr	x17, [x16, #0x510]
  6dbfe8:      	add	x16, x16, #0x510
  6dbfec:      	br	x17

00000000006dbff0 <av_find_info_tag@plt>:
  6dbff0:      	adrp	x16, 0x737000
  6dbff4:      	ldr	x17, [x16, #0x518]
  6dbff8:      	add	x16, x16, #0x518
  6dbffc:      	br	x17

00000000006dc000 <getaddrinfo@plt>:
  6dc000:      	adrp	x16, 0x737000
  6dc004:      	ldr	x17, [x16, #0x520]
  6dc008:      	add	x16, x16, #0x520
  6dc00c:      	br	x17

00000000006dc010 <gai_strerror@plt>:
  6dc010:      	adrp	x16, 0x737000
  6dc014:      	ldr	x17, [x16, #0x528]
  6dc018:      	add	x16, x16, #0x528
  6dc01c:      	br	x17

00000000006dc020 <ff_socket@plt>:
  6dc020:      	adrp	x16, 0x737000
  6dc024:      	ldr	x17, [x16, #0x530]
  6dc028:      	add	x16, x16, #0x530
  6dc02c:      	br	x17

00000000006dc030 <ff_listen@plt>:
  6dc030:      	adrp	x16, 0x737000
  6dc034:      	ldr	x17, [x16, #0x538]
  6dc038:      	add	x16, x16, #0x538
  6dc03c:      	br	x17

00000000006dc040 <ff_listen_bind@plt>:
  6dc040:      	adrp	x16, 0x737000
  6dc044:      	ldr	x17, [x16, #0x540]
  6dc048:      	add	x16, x16, #0x540
  6dc04c:      	br	x17

00000000006dc050 <freeaddrinfo@plt>:
  6dc050:      	adrp	x16, 0x737000
  6dc054:      	ldr	x17, [x16, #0x548]
  6dc058:      	add	x16, x16, #0x548
  6dc05c:      	br	x17

00000000006dc060 <ff_connect_parallel@plt>:
  6dc060:      	adrp	x16, 0x737000
  6dc064:      	ldr	x17, [x16, #0x550]
  6dc068:      	add	x16, x16, #0x550
  6dc06c:      	br	x17

00000000006dc070 <ffurl_alloc@plt>:
  6dc070:      	adrp	x16, 0x737000
  6dc074:      	ldr	x17, [x16, #0x558]
  6dc078:      	add	x16, x16, #0x558
  6dc07c:      	br	x17

00000000006dc080 <ff_accept@plt>:
  6dc080:      	adrp	x16, 0x737000
  6dc084:      	ldr	x17, [x16, #0x560]
  6dc088:      	add	x16, x16, #0x560
  6dc08c:      	br	x17

00000000006dc090 <ffurl_closep@plt>:
  6dc090:      	adrp	x16, 0x737000
  6dc094:      	ldr	x17, [x16, #0x568]
  6dc098:      	add	x16, x16, #0x568
  6dc09c:      	br	x17

00000000006dc0a0 <ff_network_wait_fd_timeout@plt>:
  6dc0a0:      	adrp	x16, 0x737000
  6dc0a4:      	ldr	x17, [x16, #0x570]
  6dc0a8:      	add	x16, x16, #0x570
  6dc0ac:      	br	x17

00000000006dc0b0 <recv@plt>:
  6dc0b0:      	adrp	x16, 0x737000
  6dc0b4:      	ldr	x17, [x16, #0x578]
  6dc0b8:      	add	x16, x16, #0x578
  6dc0bc:      	br	x17

00000000006dc0c0 <send@plt>:
  6dc0c0:      	adrp	x16, 0x737000
  6dc0c4:      	ldr	x17, [x16, #0x580]
  6dc0c8:      	add	x16, x16, #0x580
  6dc0cc:      	br	x17

00000000006dc0d0 <getsockopt@plt>:
  6dc0d0:      	adrp	x16, 0x737000
  6dc0d4:      	ldr	x17, [x16, #0x588]
  6dc0d8:      	add	x16, x16, #0x588
  6dc0dc:      	br	x17

00000000006dc0e0 <shutdown@plt>:
  6dc0e0:      	adrp	x16, 0x737000
  6dc0e4:      	ldr	x17, [x16, #0x590]
  6dc0e8:      	add	x16, x16, #0x590
  6dc0ec:      	br	x17

00000000006dc0f0 <bind@plt>:
  6dc0f0:      	adrp	x16, 0x737000
  6dc0f4:      	ldr	x17, [x16, #0x598]
  6dc0f8:      	add	x16, x16, #0x598
  6dc0fc:      	br	x17

00000000006dc100 <ff_log_net_error@plt>:
  6dc100:      	adrp	x16, 0x737000
  6dc104:      	ldr	x17, [x16, #0x5a0]
  6dc108:      	add	x16, x16, #0x5a0
  6dc10c:      	br	x17

00000000006dc110 <setsockopt@plt>:
  6dc110:      	adrp	x16, 0x737000
  6dc114:      	ldr	x17, [x16, #0x5a8]
  6dc118:      	add	x16, x16, #0x5a8
  6dc11c:      	br	x17

00000000006dc120 <av_get_packet@plt>:
  6dc120:      	adrp	x16, 0x737000
  6dc124:      	ldr	x17, [x16, #0x5b0]
  6dc128:      	add	x16, x16, #0x5b0
  6dc12c:      	br	x17

00000000006dc130 <ffio_limit@plt>:
  6dc130:      	adrp	x16, 0x737000
  6dc134:      	ldr	x17, [x16, #0x5b8]
  6dc138:      	add	x16, x16, #0x5b8
  6dc13c:      	br	x17

00000000006dc140 <avio_read@plt>:
  6dc140:      	adrp	x16, 0x737000
  6dc144:      	ldr	x17, [x16, #0x5c0]
  6dc148:      	add	x16, x16, #0x5c0
  6dc14c:      	br	x17

00000000006dc150 <av_append_packet@plt>:
  6dc150:      	adrp	x16, 0x737000
  6dc154:      	ldr	x17, [x16, #0x5c8]
  6dc158:      	add	x16, x16, #0x5c8
  6dc15c:      	br	x17

00000000006dc160 <av_filename_number_test@plt>:
  6dc160:      	adrp	x16, 0x737000
  6dc164:      	ldr	x17, [x16, #0x5d0]
  6dc168:      	add	x16, x16, #0x5d0
  6dc16c:      	br	x17

00000000006dc170 <av_get_frame_filename@plt>:
  6dc170:      	adrp	x16, 0x737000
  6dc174:      	ldr	x17, [x16, #0x5d8]
  6dc178:      	add	x16, x16, #0x5d8
  6dc17c:      	br	x17

00000000006dc180 <ff_get_frame_filename@plt>:
  6dc180:      	adrp	x16, 0x737000
  6dc184:      	ldr	x17, [x16, #0x5e0]
  6dc188:      	add	x16, x16, #0x5e0
  6dc18c:      	br	x17

00000000006dc190 <ff_codec_get_tag@plt>:
  6dc190:      	adrp	x16, 0x737000
  6dc194:      	ldr	x17, [x16, #0x5e8]
  6dc198:      	add	x16, x16, #0x5e8
  6dc19c:      	br	x17

00000000006dc1a0 <ff_get_pcm_codec_id@plt>:
  6dc1a0:      	adrp	x16, 0x737000
  6dc1a4:      	ldr	x17, [x16, #0x5f0]
  6dc1a8:      	add	x16, x16, #0x5f0
  6dc1ac:      	br	x17

00000000006dc1b0 <av_codec_get_tag@plt>:
  6dc1b0:      	adrp	x16, 0x737000
  6dc1b4:      	ldr	x17, [x16, #0x5f8]
  6dc1b8:      	add	x16, x16, #0x5f8
  6dc1bc:      	br	x17

00000000006dc1c0 <av_codec_get_tag2@plt>:
  6dc1c0:      	adrp	x16, 0x737000
  6dc1c4:      	ldr	x17, [x16, #0x600]
  6dc1c8:      	add	x16, x16, #0x600
  6dc1cc:      	br	x17

00000000006dc1d0 <av_codec_get_id@plt>:
  6dc1d0:      	adrp	x16, 0x737000
  6dc1d4:      	ldr	x17, [x16, #0x608]
  6dc1d8:      	add	x16, x16, #0x608
  6dc1dc:      	br	x17

00000000006dc1e0 <ff_ntp_time@plt>:
  6dc1e0:      	adrp	x16, 0x737000
  6dc1e4:      	ldr	x17, [x16, #0x610]
  6dc1e8:      	add	x16, x16, #0x610
  6dc1ec:      	br	x17

00000000006dc1f0 <ff_get_formatted_ntp_time@plt>:
  6dc1f0:      	adrp	x16, 0x737000
  6dc1f4:      	ldr	x17, [x16, #0x618]
  6dc1f8:      	add	x16, x16, #0x618
  6dc1fc:      	br	x17

00000000006dc200 <av_strlcpy@plt>:
  6dc200:      	adrp	x16, 0x737000
  6dc204:      	ldr	x17, [x16, #0x620]
  6dc208:      	add	x16, x16, #0x620
  6dc20c:      	br	x17

00000000006dc210 <strcspn@plt>:
  6dc210:      	adrp	x16, 0x737000
  6dc214:      	ldr	x17, [x16, #0x628]
  6dc218:      	add	x16, x16, #0x628
  6dc21c:      	br	x17

00000000006dc220 <atoi@plt>:
  6dc220:      	adrp	x16, 0x737000
  6dc224:      	ldr	x17, [x16, #0x630]
  6dc228:      	add	x16, x16, #0x630
  6dc22c:      	br	x17

00000000006dc230 <mkdir@plt>:
  6dc230:      	adrp	x16, 0x737000
  6dc234:      	ldr	x17, [x16, #0x638]
  6dc238:      	add	x16, x16, #0x638
  6dc23c:      	br	x17

00000000006dc240 <ff_data_to_hex@plt>:
  6dc240:      	adrp	x16, 0x737000
  6dc244:      	ldr	x17, [x16, #0x640]
  6dc248:      	add	x16, x16, #0x640
  6dc24c:      	br	x17

00000000006dc250 <ff_hex_to_data@plt>:
  6dc250:      	adrp	x16, 0x737000
  6dc254:      	ldr	x17, [x16, #0x648]
  6dc258:      	add	x16, x16, #0x648
  6dc25c:      	br	x17

00000000006dc260 <ff_parse_key_value@plt>:
  6dc260:      	adrp	x16, 0x737000
  6dc264:      	ldr	x17, [x16, #0x650]
  6dc268:      	add	x16, x16, #0x650
  6dc26c:      	br	x17

00000000006dc270 <ff_network_init@plt>:
  6dc270:      	adrp	x16, 0x737000
  6dc274:      	ldr	x17, [x16, #0x658]
  6dc278:      	add	x16, x16, #0x658
  6dc27c:      	br	x17

00000000006dc280 <ff_tls_init@plt>:
  6dc280:      	adrp	x16, 0x737000
  6dc284:      	ldr	x17, [x16, #0x660]
  6dc288:      	add	x16, x16, #0x660
  6dc28c:      	br	x17

00000000006dc290 <ff_network_close@plt>:
  6dc290:      	adrp	x16, 0x737000
  6dc294:      	ldr	x17, [x16, #0x668]
  6dc298:      	add	x16, x16, #0x668
  6dc29c:      	br	x17

00000000006dc2a0 <ff_tls_deinit@plt>:
  6dc2a0:      	adrp	x16, 0x737000
  6dc2a4:      	ldr	x17, [x16, #0x670]
  6dc2a8:      	add	x16, x16, #0x670
  6dc2ac:      	br	x17

00000000006dc2b0 <avio_find_protocol_name@plt>:
  6dc2b0:      	adrp	x16, 0x737000
  6dc2b4:      	ldr	x17, [x16, #0x678]
  6dc2b8:      	add	x16, x16, #0x678
  6dc2bc:      	br	x17

00000000006dc2c0 <fprintf@plt>:
  6dc2c0:      	adrp	x16, 0x737000
  6dc2c4:      	ldr	x17, [x16, #0x680]
  6dc2c8:      	add	x16, x16, #0x680
  6dc2cc:      	br	x17

00000000006dc2d0 <fwrite@plt>:
  6dc2d0:      	adrp	x16, 0x737000
  6dc2d4:      	ldr	x17, [x16, #0x688]
  6dc2d8:      	add	x16, x16, #0x688
  6dc2dc:      	br	x17

00000000006dc2e0 <av_hex_dump_log@plt>:
  6dc2e0:      	adrp	x16, 0x737000
  6dc2e4:      	ldr	x17, [x16, #0x690]
  6dc2e8:      	add	x16, x16, #0x690
  6dc2ec:      	br	x17

00000000006dc2f0 <fputc@plt>:
  6dc2f0:      	adrp	x16, 0x737000
  6dc2f4:      	ldr	x17, [x16, #0x698]
  6dc2f8:      	add	x16, x16, #0x698
  6dc2fc:      	br	x17

00000000006dc300 <av_display_rotation_get@plt>:
  6dc300:      	adrp	x16, 0x737000
  6dc304:      	ldr	x17, [x16, #0x6a0]
  6dc308:      	add	x16, x16, #0x6a0
  6dc30c:      	br	x17

00000000006dc310 <av_spherical_projection_name@plt>:
  6dc310:      	adrp	x16, 0x737000
  6dc314:      	ldr	x17, [x16, #0x6a8]
  6dc318:      	add	x16, x16, #0x6a8
  6dc31c:      	br	x17

00000000006dc320 <av_spherical_tile_bounds@plt>:
  6dc320:      	adrp	x16, 0x737000
  6dc324:      	ldr	x17, [x16, #0x6b0]
  6dc328:      	add	x16, x16, #0x6b0
  6dc32c:      	br	x17

00000000006dc330 <av_stereo3d_type_name@plt>:
  6dc330:      	adrp	x16, 0x737000
  6dc334:      	ldr	x17, [x16, #0x6b8]
  6dc338:      	add	x16, x16, #0x6b8
  6dc33c:      	br	x17

00000000006dc340 <av_stereo3d_view_name@plt>:
  6dc340:      	adrp	x16, 0x737000
  6dc344:      	ldr	x17, [x16, #0x6c0]
  6dc348:      	add	x16, x16, #0x6c0
  6dc34c:      	br	x17

00000000006dc350 <av_stereo3d_primary_eye_name@plt>:
  6dc350:      	adrp	x16, 0x737000
  6dc354:      	ldr	x17, [x16, #0x6c8]
  6dc358:      	add	x16, x16, #0x6c8
  6dc35c:      	br	x17

00000000006dc360 <av_stristr@plt>:
  6dc360:      	adrp	x16, 0x737000
  6dc364:      	ldr	x17, [x16, #0x6d0]
  6dc368:      	add	x16, x16, #0x6d0
  6dc36c:      	br	x17

00000000006dc370 <ff_socket_nonblock@plt>:
  6dc370:      	adrp	x16, 0x737000
  6dc374:      	ldr	x17, [x16, #0x6d8]
  6dc378:      	add	x16, x16, #0x6d8
  6dc37c:      	br	x17

00000000006dc380 <fcntl@plt>:
  6dc380:      	adrp	x16, 0x737000
  6dc384:      	ldr	x17, [x16, #0x6e0]
  6dc388:      	add	x16, x16, #0x6e0
  6dc38c:      	br	x17

00000000006dc390 <avpriv_update_cur_dts@plt>:
  6dc390:      	adrp	x16, 0x737000
  6dc394:      	ldr	x17, [x16, #0x6e8]
  6dc398:      	add	x16, x16, #0x6e8
  6dc39c:      	br	x17

00000000006dc3a0 <ff_reduce_index@plt>:
  6dc3a0:      	adrp	x16, 0x737000
  6dc3a4:      	ldr	x17, [x16, #0x6f0]
  6dc3a8:      	add	x16, x16, #0x6f0
  6dc3ac:      	br	x17

00000000006dc3b0 <ff_add_index_entry@plt>:
  6dc3b0:      	adrp	x16, 0x737000
  6dc3b4:      	ldr	x17, [x16, #0x6f8]
  6dc3b8:      	add	x16, x16, #0x6f8
  6dc3bc:      	br	x17

00000000006dc3c0 <ff_index_search_timestamp@plt>:
  6dc3c0:      	adrp	x16, 0x737000
  6dc3c4:      	ldr	x17, [x16, #0x700]
  6dc3c8:      	add	x16, x16, #0x700
  6dc3cc:      	br	x17

00000000006dc3d0 <av_add_index_entry@plt>:
  6dc3d0:      	adrp	x16, 0x737000
  6dc3d4:      	ldr	x17, [x16, #0x708]
  6dc3d8:      	add	x16, x16, #0x708
  6dc3dc:      	br	x17

00000000006dc3e0 <ff_wrap_timestamp@plt>:
  6dc3e0:      	adrp	x16, 0x737000
  6dc3e4:      	ldr	x17, [x16, #0x710]
  6dc3e8:      	add	x16, x16, #0x710
  6dc3ec:      	br	x17

00000000006dc3f0 <ff_configure_buffers_for_index@plt>:
  6dc3f0:      	adrp	x16, 0x737000
  6dc3f4:      	ldr	x17, [x16, #0x718]
  6dc3f8:      	add	x16, x16, #0x718
  6dc3fc:      	br	x17

00000000006dc400 <ffio_realloc_buf@plt>:
  6dc400:      	adrp	x16, 0x737000
  6dc404:      	ldr	x17, [x16, #0x720]
  6dc408:      	add	x16, x16, #0x720
  6dc40c:      	br	x17

00000000006dc410 <av_index_search_timestamp@plt>:
  6dc410:      	adrp	x16, 0x737000
  6dc414:      	ldr	x17, [x16, #0x728]
  6dc418:      	add	x16, x16, #0x728
  6dc41c:      	br	x17

00000000006dc420 <ff_seek_frame_binary@plt>:
  6dc420:      	adrp	x16, 0x737000
  6dc424:      	ldr	x17, [x16, #0x730]
  6dc428:      	add	x16, x16, #0x730
  6dc42c:      	br	x17

00000000006dc430 <ff_gen_search@plt>:
  6dc430:      	adrp	x16, 0x737000
  6dc434:      	ldr	x17, [x16, #0x738]
  6dc438:      	add	x16, x16, #0x738
  6dc43c:      	br	x17

00000000006dc440 <ff_find_last_ts@plt>:
  6dc440:      	adrp	x16, 0x737000
  6dc444:      	ldr	x17, [x16, #0x740]
  6dc448:      	add	x16, x16, #0x740
  6dc44c:      	br	x17

00000000006dc450 <ff_read_frame_flush@plt>:
  6dc450:      	adrp	x16, 0x737000
  6dc454:      	ldr	x17, [x16, #0x748]
  6dc458:      	add	x16, x16, #0x748
  6dc45c:      	br	x17

00000000006dc460 <ff_flush_packet_queue@plt>:
  6dc460:      	adrp	x16, 0x737000
  6dc464:      	ldr	x17, [x16, #0x750]
  6dc468:      	add	x16, x16, #0x750
  6dc46c:      	br	x17

00000000006dc470 <avio_size@plt>:
  6dc470:      	adrp	x16, 0x737000
  6dc474:      	ldr	x17, [x16, #0x758]
  6dc478:      	add	x16, x16, #0x758
  6dc47c:      	br	x17

00000000006dc480 <av_seek_frame@plt>:
  6dc480:      	adrp	x16, 0x737000
  6dc484:      	ldr	x17, [x16, #0x760]
  6dc488:      	add	x16, x16, #0x760
  6dc48c:      	br	x17

00000000006dc490 <av_find_default_stream_index@plt>:
  6dc490:      	adrp	x16, 0x737000
  6dc494:      	ldr	x17, [x16, #0x768]
  6dc498:      	add	x16, x16, #0x768
  6dc49c:      	br	x17

00000000006dc4a0 <avformat_queue_attached_pictures@plt>:
  6dc4a0:      	adrp	x16, 0x737000
  6dc4a4:      	ldr	x17, [x16, #0x770]
  6dc4a8:      	add	x16, x16, #0x770
  6dc4ac:      	br	x17

00000000006dc4b0 <avformat_seek_file@plt>:
  6dc4b0:      	adrp	x16, 0x737000
  6dc4b4:      	ldr	x17, [x16, #0x778]
  6dc4b8:      	add	x16, x16, #0x778
  6dc4bc:      	br	x17

00000000006dc4c0 <av_read_frame@plt>:
  6dc4c0:      	adrp	x16, 0x737000
  6dc4c4:      	ldr	x17, [x16, #0x780]
  6dc4c8:      	add	x16, x16, #0x780
  6dc4cc:      	br	x17

00000000006dc4d0 <avio_skip@plt>:
  6dc4d0:      	adrp	x16, 0x737000
  6dc4d4:      	ldr	x17, [x16, #0x788]
  6dc4d8:      	add	x16, x16, #0x788
  6dc4dc:      	br	x17

00000000006dc4e0 <avio_rl16@plt>:
  6dc4e0:      	adrp	x16, 0x737000
  6dc4e4:      	ldr	x17, [x16, #0x790]
  6dc4e8:      	add	x16, x16, #0x790
  6dc4ec:      	br	x17

00000000006dc4f0 <avio_rl32@plt>:
  6dc4f0:      	adrp	x16, 0x737000
  6dc4f4:      	ldr	x17, [x16, #0x798]
  6dc4f8:      	add	x16, x16, #0x798
  6dc4fc:      	br	x17

00000000006dc500 <avio_r8@plt>:
  6dc500:      	adrp	x16, 0x737000
  6dc504:      	ldr	x17, [x16, #0x7a0]
  6dc508:      	add	x16, x16, #0x7a0
  6dc50c:      	br	x17

00000000006dc510 <avformat_new_stream@plt>:
  6dc510:      	adrp	x16, 0x737000
  6dc514:      	ldr	x17, [x16, #0x7a8]
  6dc518:      	add	x16, x16, #0x7a8
  6dc51c:      	br	x17

00000000006dc520 <ff_ape_parse_tag@plt>:
  6dc520:      	adrp	x16, 0x737000
  6dc524:      	ldr	x17, [x16, #0x7b0]
  6dc528:      	add	x16, x16, #0x7b0
  6dc52c:      	br	x17

00000000006dc530 <avio_feof@plt>:
  6dc530:      	adrp	x16, 0x737000
  6dc534:      	ldr	x17, [x16, #0x7b8]
  6dc538:      	add	x16, x16, #0x7b8
  6dc53c:      	br	x17

00000000006dc540 <ff_rtmp_calc_digest@plt>:
  6dc540:      	adrp	x16, 0x737000
  6dc544:      	ldr	x17, [x16, #0x7c0]
  6dc548:      	add	x16, x16, #0x7c0
  6dc54c:      	br	x17

00000000006dc550 <av_hmac_alloc@plt>:
  6dc550:      	adrp	x16, 0x737000
  6dc554:      	ldr	x17, [x16, #0x7c8]
  6dc558:      	add	x16, x16, #0x7c8
  6dc55c:      	br	x17

00000000006dc560 <av_hmac_init@plt>:
  6dc560:      	adrp	x16, 0x737000
  6dc564:      	ldr	x17, [x16, #0x7d0]
  6dc568:      	add	x16, x16, #0x7d0
  6dc56c:      	br	x17

00000000006dc570 <av_hmac_update@plt>:
  6dc570:      	adrp	x16, 0x737000
  6dc574:      	ldr	x17, [x16, #0x7d8]
  6dc578:      	add	x16, x16, #0x7d8
  6dc57c:      	br	x17

00000000006dc580 <av_hmac_final@plt>:
  6dc580:      	adrp	x16, 0x737000
  6dc584:      	ldr	x17, [x16, #0x7e0]
  6dc588:      	add	x16, x16, #0x7e0
  6dc58c:      	br	x17

00000000006dc590 <av_hmac_free@plt>:
  6dc590:      	adrp	x16, 0x737000
  6dc594:      	ldr	x17, [x16, #0x7e8]
  6dc598:      	add	x16, x16, #0x7e8
  6dc59c:      	br	x17

00000000006dc5a0 <ff_rtmp_calc_digest_pos@plt>:
  6dc5a0:      	adrp	x16, 0x737000
  6dc5a4:      	ldr	x17, [x16, #0x7f0]
  6dc5a8:      	add	x16, x16, #0x7f0
  6dc5ac:      	br	x17

00000000006dc5b0 <ff_nal_find_startcode@plt>:
  6dc5b0:      	adrp	x16, 0x737000
  6dc5b4:      	ldr	x17, [x16, #0x7f8]
  6dc5b8:      	add	x16, x16, #0x7f8
  6dc5bc:      	br	x17

00000000006dc5c0 <ff_nal_parse_units@plt>:
  6dc5c0:      	adrp	x16, 0x737000
  6dc5c4:      	ldr	x17, [x16, #0x800]
  6dc5c8:      	add	x16, x16, #0x800
  6dc5cc:      	br	x17

00000000006dc5d0 <ff_nal_units_create_list@plt>:
  6dc5d0:      	adrp	x16, 0x737000
  6dc5d4:      	ldr	x17, [x16, #0x808]
  6dc5d8:      	add	x16, x16, #0x808
  6dc5dc:      	br	x17

00000000006dc5e0 <ff_nal_units_write_list@plt>:
  6dc5e0:      	adrp	x16, 0x737000
  6dc5e4:      	ldr	x17, [x16, #0x810]
  6dc5e8:      	add	x16, x16, #0x810
  6dc5ec:      	br	x17

00000000006dc5f0 <ff_nal_parse_units_buf@plt>:
  6dc5f0:      	adrp	x16, 0x737000
  6dc5f4:      	ldr	x17, [x16, #0x818]
  6dc5f8:      	add	x16, x16, #0x818
  6dc5fc:      	br	x17

00000000006dc600 <avio_close_dyn_buf@plt>:
  6dc600:      	adrp	x16, 0x737000
  6dc604:      	ldr	x17, [x16, #0x820]
  6dc608:      	add	x16, x16, #0x820
  6dc60c:      	br	x17

00000000006dc610 <ff_nal_unit_extract_rbsp@plt>:
  6dc610:      	adrp	x16, 0x737000
  6dc614:      	ldr	x17, [x16, #0x828]
  6dc618:      	add	x16, x16, #0x828
  6dc61c:      	br	x17

00000000006dc620 <ff_iamf_add_audio_element@plt>:
  6dc620:      	adrp	x16, 0x737000
  6dc624:      	ldr	x17, [x16, #0x830]
  6dc628:      	add	x16, x16, #0x830
  6dc62c:      	br	x17

00000000006dc630 <ff_iamf_add_mix_presentation@plt>:
  6dc630:      	adrp	x16, 0x737000
  6dc634:      	ldr	x17, [x16, #0x838]
  6dc638:      	add	x16, x16, #0x838
  6dc63c:      	br	x17

00000000006dc640 <ff_iamf_write_descriptors@plt>:
  6dc640:      	adrp	x16, 0x737000
  6dc644:      	ldr	x17, [x16, #0x840]
  6dc648:      	add	x16, x16, #0x840
  6dc64c:      	br	x17

00000000006dc650 <ffio_write_leb@plt>:
  6dc650:      	adrp	x16, 0x737000
  6dc654:      	ldr	x17, [x16, #0x848]
  6dc658:      	add	x16, x16, #0x848
  6dc65c:      	br	x17

00000000006dc660 <avio_wb16@plt>:
  6dc660:      	adrp	x16, 0x737000
  6dc664:      	ldr	x17, [x16, #0x850]
  6dc668:      	add	x16, x16, #0x850
  6dc66c:      	br	x17

00000000006dc670 <avio_wb24@plt>:
  6dc670:      	adrp	x16, 0x737000
  6dc674:      	ldr	x17, [x16, #0x858]
  6dc678:      	add	x16, x16, #0x858
  6dc67c:      	br	x17

00000000006dc680 <ff_iamf_write_parameter_blocks@plt>:
  6dc680:      	adrp	x16, 0x737000
  6dc684:      	ldr	x17, [x16, #0x860]
  6dc688:      	add	x16, x16, #0x860
  6dc68c:      	br	x17

00000000006dc690 <ff_iamf_write_audio_frame@plt>:
  6dc690:      	adrp	x16, 0x737000
  6dc694:      	ldr	x17, [x16, #0x868]
  6dc698:      	add	x16, x16, #0x868
  6dc69c:      	br	x17

00000000006dc6a0 <ff_id3v2_read@plt>:
  6dc6a0:      	adrp	x16, 0x737000
  6dc6a4:      	ldr	x17, [x16, #0x870]
  6dc6a8:      	add	x16, x16, #0x870
  6dc6ac:      	br	x17

00000000006dc6b0 <ff_id3v2_parse_apic@plt>:
  6dc6b0:      	adrp	x16, 0x737000
  6dc6b4:      	ldr	x17, [x16, #0x878]
  6dc6b8:      	add	x16, x16, #0x878
  6dc6bc:      	br	x17

00000000006dc6c0 <ff_id3v2_parse_chapters@plt>:
  6dc6c0:      	adrp	x16, 0x737000
  6dc6c4:      	ldr	x17, [x16, #0x880]
  6dc6c8:      	add	x16, x16, #0x880
  6dc6cc:      	br	x17

00000000006dc6d0 <ff_id3v2_free_extra_meta@plt>:
  6dc6d0:      	adrp	x16, 0x737000
  6dc6d4:      	ldr	x17, [x16, #0x888]
  6dc6d8:      	add	x16, x16, #0x888
  6dc6dc:      	br	x17

00000000006dc6e0 <avio_rb16@plt>:
  6dc6e0:      	adrp	x16, 0x737000
  6dc6e4:      	ldr	x17, [x16, #0x890]
  6dc6e8:      	add	x16, x16, #0x890
  6dc6ec:      	br	x17

00000000006dc6f0 <avio_rb32@plt>:
  6dc6f0:      	adrp	x16, 0x737000
  6dc6f4:      	ldr	x17, [x16, #0x898]
  6dc6f8:      	add	x16, x16, #0x898
  6dc6fc:      	br	x17

00000000006dc700 <avio_rb64@plt>:
  6dc700:      	adrp	x16, 0x737000
  6dc704:      	ldr	x17, [x16, #0x8a0]
  6dc708:      	add	x16, x16, #0x8a0
  6dc70c:      	br	x17

00000000006dc710 <ff_get_extradata@plt>:
  6dc710:      	adrp	x16, 0x737000
  6dc714:      	ldr	x17, [x16, #0x8a8]
  6dc718:      	add	x16, x16, #0x8a8
  6dc71c:      	br	x17

00000000006dc720 <ff_mov_read_chan@plt>:
  6dc720:      	adrp	x16, 0x737000
  6dc724:      	ldr	x17, [x16, #0x8b0]
  6dc728:      	add	x16, x16, #0x8b0
  6dc72c:      	br	x17

00000000006dc730 <ff_replaygain_export@plt>:
  6dc730:      	adrp	x16, 0x737000
  6dc734:      	ldr	x17, [x16, #0x8b8]
  6dc738:      	add	x16, x16, #0x8b8
  6dc73c:      	br	x17

00000000006dc740 <ff_pcm_read_seek@plt>:
  6dc740:      	adrp	x16, 0x737000
  6dc744:      	ldr	x17, [x16, #0x8c0]
  6dc748:      	add	x16, x16, #0x8c0
  6dc74c:      	br	x17

00000000006dc750 <ff_replaygain_export_raw@plt>:
  6dc750:      	adrp	x16, 0x737000
  6dc754:      	ldr	x17, [x16, #0x8c8]
  6dc758:      	add	x16, x16, #0x8c8
  6dc75c:      	br	x17

00000000006dc760 <ffurl_get_protocols@plt>:
  6dc760:      	adrp	x16, 0x737000
  6dc764:      	ldr	x17, [x16, #0x8d0]
  6dc768:      	add	x16, x16, #0x8d0
  6dc76c:      	br	x17

00000000006dc770 <av_match_name@plt>:
  6dc770:      	adrp	x16, 0x737000
  6dc774:      	ldr	x17, [x16, #0x8d8]
  6dc778:      	add	x16, x16, #0x8d8
  6dc77c:      	br	x17

00000000006dc780 <ff_mov_generate_squashed_ttml_packet@plt>:
  6dc780:      	adrp	x16, 0x737000
  6dc784:      	ldr	x17, [x16, #0x8e0]
  6dc788:      	add	x16, x16, #0x8e0
  6dc78c:      	br	x17

00000000006dc790 <avformat_alloc_output_context2@plt>:
  6dc790:      	adrp	x16, 0x737000
  6dc794:      	ldr	x17, [x16, #0x8e8]
  6dc798:      	add	x16, x16, #0x8e8
  6dc79c:      	br	x17

00000000006dc7a0 <avformat_free_context@plt>:
  6dc7a0:      	adrp	x16, 0x737000
  6dc7a4:      	ldr	x17, [x16, #0x8f0]
  6dc7a8:      	add	x16, x16, #0x8f0
  6dc7ac:      	br	x17

00000000006dc7b0 <avformat_write_header@plt>:
  6dc7b0:      	adrp	x16, 0x737000
  6dc7b4:      	ldr	x17, [x16, #0x8f8]
  6dc7b8:      	add	x16, x16, #0x8f8
  6dc7bc:      	br	x17

00000000006dc7c0 <av_write_frame@plt>:
  6dc7c0:      	adrp	x16, 0x737000
  6dc7c4:      	ldr	x17, [x16, #0x900]
  6dc7c8:      	add	x16, x16, #0x900
  6dc7cc:      	br	x17

00000000006dc7d0 <av_write_trailer@plt>:
  6dc7d0:      	adrp	x16, 0x737000
  6dc7d4:      	ldr	x17, [x16, #0x908]
  6dc7d8:      	add	x16, x16, #0x908
  6dc7dc:      	br	x17

00000000006dc7e0 <ff_mov_iso639_to_lang@plt>:
  6dc7e0:      	adrp	x16, 0x737000
  6dc7e4:      	ldr	x17, [x16, #0x910]
  6dc7e8:      	add	x16, x16, #0x910
  6dc7ec:      	br	x17

00000000006dc7f0 <ff_mov_lang_to_iso639@plt>:
  6dc7f0:      	adrp	x16, 0x737000
  6dc7f4:      	ldr	x17, [x16, #0x918]
  6dc7f8:      	add	x16, x16, #0x918
  6dc7fc:      	br	x17

00000000006dc800 <ff_mp4_read_descr_len@plt>:
  6dc800:      	adrp	x16, 0x737000
  6dc804:      	ldr	x17, [x16, #0x920]
  6dc808:      	add	x16, x16, #0x920
  6dc80c:      	br	x17

00000000006dc810 <ff_mp4_read_descr@plt>:
  6dc810:      	adrp	x16, 0x737000
  6dc814:      	ldr	x17, [x16, #0x928]
  6dc818:      	add	x16, x16, #0x928
  6dc81c:      	br	x17

00000000006dc820 <ff_mp4_parse_es_descr@plt>:
  6dc820:      	adrp	x16, 0x737000
  6dc824:      	ldr	x17, [x16, #0x930]
  6dc828:      	add	x16, x16, #0x930
  6dc82c:      	br	x17

00000000006dc830 <ff_mp4_read_dec_config_descr@plt>:
  6dc830:      	adrp	x16, 0x737000
  6dc834:      	ldr	x17, [x16, #0x938]
  6dc838:      	add	x16, x16, #0x938
  6dc83c:      	br	x17

00000000006dc840 <avio_rb24@plt>:
  6dc840:      	adrp	x16, 0x737000
  6dc844:      	ldr	x17, [x16, #0x940]
  6dc848:      	add	x16, x16, #0x940
  6dc84c:      	br	x17

00000000006dc850 <av_parse_time@plt>:
  6dc850:      	adrp	x16, 0x737000
  6dc854:      	ldr	x17, [x16, #0x948]
  6dc858:      	add	x16, x16, #0x948
  6dc85c:      	br	x17

00000000006dc860 <av_chroma_location_enum_to_pos@plt>:
  6dc860:      	adrp	x16, 0x737000
  6dc864:      	ldr	x17, [x16, #0x950]
  6dc868:      	add	x16, x16, #0x950
  6dc86c:      	br	x17

00000000006dc870 <ff_isom_put_dvcc_dvvc@plt>:
  6dc870:      	adrp	x16, 0x737000
  6dc874:      	ldr	x17, [x16, #0x958]
  6dc878:      	add	x16, x16, #0x958
  6dc87c:      	br	x17

00000000006dc880 <ff_metadata_conv_ctx@plt>:
  6dc880:      	adrp	x16, 0x737000
  6dc884:      	ldr	x17, [x16, #0x960]
  6dc888:      	add	x16, x16, #0x960
  6dc88c:      	br	x17

00000000006dc890 <ff_format_shift_data@plt>:
  6dc890:      	adrp	x16, 0x737000
  6dc894:      	ldr	x17, [x16, #0x968]
  6dc898:      	add	x16, x16, #0x968
  6dc89c:      	br	x17

00000000006dc8a0 <av_get_random_seed@plt>:
  6dc8a0:      	adrp	x16, 0x737000
  6dc8a4:      	ldr	x17, [x16, #0x970]
  6dc8a8:      	add	x16, x16, #0x970
  6dc8ac:      	br	x17

00000000006dc8b0 <ff_stream_add_bitstream_filter@plt>:
  6dc8b0:      	adrp	x16, 0x737000
  6dc8b4:      	ldr	x17, [x16, #0x978]
  6dc8b8:      	add	x16, x16, #0x978
  6dc8bc:      	br	x17

00000000006dc8c0 <ff_flac_is_native_layout@plt>:
  6dc8c0:      	adrp	x16, 0x737000
  6dc8c4:      	ldr	x17, [x16, #0x980]
  6dc8c8:      	add	x16, x16, #0x980
  6dc8cc:      	br	x17

00000000006dc8d0 <ff_isom_write_av1c@plt>:
  6dc8d0:      	adrp	x16, 0x737000
  6dc8d4:      	ldr	x17, [x16, #0x988]
  6dc8d8:      	add	x16, x16, #0x988
  6dc8dc:      	br	x17

00000000006dc8e0 <ff_isom_write_hvcc@plt>:
  6dc8e0:      	adrp	x16, 0x737000
  6dc8e4:      	ldr	x17, [x16, #0x990]
  6dc8e8:      	add	x16, x16, #0x990
  6dc8ec:      	br	x17

00000000006dc8f0 <ff_isom_write_avcc@plt>:
  6dc8f0:      	adrp	x16, 0x737000
  6dc8f4:      	ldr	x17, [x16, #0x998]
  6dc8f8:      	add	x16, x16, #0x998
  6dc8fc:      	br	x17

00000000006dc900 <ff_flac_write_header@plt>:
  6dc900:      	adrp	x16, 0x737000
  6dc904:      	ldr	x17, [x16, #0x9a0]
  6dc908:      	add	x16, x16, #0x9a0
  6dc90c:      	br	x17

00000000006dc910 <ff_vorbiscomment_length@plt>:
  6dc910:      	adrp	x16, 0x737000
  6dc914:      	ldr	x17, [x16, #0x9a8]
  6dc918:      	add	x16, x16, #0x9a8
  6dc91c:      	br	x17

00000000006dc920 <ff_vorbiscomment_write@plt>:
  6dc920:      	adrp	x16, 0x737000
  6dc924:      	ldr	x17, [x16, #0x9b0]
  6dc928:      	add	x16, x16, #0x9b0
  6dc92c:      	br	x17

00000000006dc930 <strrchr@plt>:
  6dc930:      	adrp	x16, 0x737000
  6dc934:      	ldr	x17, [x16, #0x9b8]
  6dc938:      	add	x16, x16, #0x9b8
  6dc93c:      	br	x17

00000000006dc940 <av_dynamic_hdr_plus_to_t35@plt>:
  6dc940:      	adrp	x16, 0x737000
  6dc944:      	ldr	x17, [x16, #0x9c0]
  6dc948:      	add	x16, x16, #0x9c0
  6dc94c:      	br	x17

00000000006dc950 <ff_wv_parse_header@plt>:
  6dc950:      	adrp	x16, 0x737000
  6dc954:      	ldr	x17, [x16, #0x9c8]
  6dc958:      	add	x16, x16, #0x9c8
  6dc95c:      	br	x17

00000000006dc960 <ff_av1_filter_obus@plt>:
  6dc960:      	adrp	x16, 0x737000
  6dc964:      	ldr	x17, [x16, #0x9d0]
  6dc968:      	add	x16, x16, #0x9d0
  6dc96c:      	br	x17

00000000006dc970 <ff_format_io_close@plt>:
  6dc970:      	adrp	x16, 0x737000
  6dc974:      	ldr	x17, [x16, #0x9d8]
  6dc978:      	add	x16, x16, #0x9d8
  6dc97c:      	br	x17

00000000006dc980 <av_compare_ts@plt>:
  6dc980:      	adrp	x16, 0x737000
  6dc984:      	ldr	x17, [x16, #0x9e0]
  6dc988:      	add	x16, x16, #0x9e0
  6dc98c:      	br	x17

00000000006dc990 <ff_write_chained@plt>:
  6dc990:      	adrp	x16, 0x737000
  6dc994:      	ldr	x17, [x16, #0x9e8]
  6dc998:      	add	x16, x16, #0x9e8
  6dc99c:      	br	x17

00000000006dc9a0 <av_match_ext@plt>:
  6dc9a0:      	adrp	x16, 0x737000
  6dc9a4:      	ldr	x17, [x16, #0x9f0]
  6dc9a8:      	add	x16, x16, #0x9f0
  6dc9ac:      	br	x17

00000000006dc9b0 <avformat_match_stream_specifier@plt>:
  6dc9b0:      	adrp	x16, 0x737000
  6dc9b4:      	ldr	x17, [x16, #0x9f8]
  6dc9b8:      	add	x16, x16, #0x9f8
  6dc9bc:      	br	x17

00000000006dc9c0 <av_guess_format@plt>:
  6dc9c0:      	adrp	x16, 0x737000
  6dc9c4:      	ldr	x17, [x16, #0xa00]
  6dc9c8:      	add	x16, x16, #0xa00
  6dc9cc:      	br	x17

00000000006dc9d0 <avformat_init_output@plt>:
  6dc9d0:      	adrp	x16, 0x737000
  6dc9d4:      	ldr	x17, [x16, #0xa08]
  6dc9d8:      	add	x16, x16, #0xa08
  6dc9dc:      	br	x17

00000000006dc9e0 <avio_context_free@plt>:
  6dc9e0:      	adrp	x16, 0x737000
  6dc9e4:      	ldr	x17, [x16, #0xa10]
  6dc9e8:      	add	x16, x16, #0xa10
  6dc9ec:      	br	x17

00000000006dc9f0 <avio_printf@plt>:
  6dc9f0:      	adrp	x16, 0x737000
  6dc9f4:      	ldr	x17, [x16, #0xa18]
  6dc9f8:      	add	x16, x16, #0xa18
  6dc9fc:      	br	x17

00000000006dca00 <ff_rename@plt>:
  6dca00:      	adrp	x16, 0x737000
  6dca04:      	ldr	x17, [x16, #0xa20]
  6dca08:      	add	x16, x16, #0xa20
  6dca0c:      	br	x17

00000000006dca10 <avio_flush@plt>:
  6dca10:      	adrp	x16, 0x737000
  6dca14:      	ldr	x17, [x16, #0xa28]
  6dca18:      	add	x16, x16, #0xa28
  6dca1c:      	br	x17

00000000006dca20 <av_timecode_make_string@plt>:
  6dca20:      	adrp	x16, 0x737000
  6dca24:      	ldr	x17, [x16, #0xa30]
  6dca28:      	add	x16, x16, #0xa30
  6dca2c:      	br	x17

00000000006dca30 <av_escape@plt>:
  6dca30:      	adrp	x16, 0x737000
  6dca34:      	ldr	x17, [x16, #0xa38]
  6dca38:      	add	x16, x16, #0xa38
  6dca3c:      	br	x17

00000000006dca40 <ff_stream_clone@plt>:
  6dca40:      	adrp	x16, 0x737000
  6dca44:      	ldr	x17, [x16, #0xa40]
  6dca48:      	add	x16, x16, #0xa40
  6dca4c:      	br	x17

00000000006dca50 <time@plt>:
  6dca50:      	adrp	x16, 0x737000
  6dca54:      	ldr	x17, [x16, #0xa48]
  6dca58:      	add	x16, x16, #0xa48
  6dca5c:      	br	x17

00000000006dca60 <ff_format_set_url@plt>:
  6dca60:      	adrp	x16, 0x737000
  6dca64:      	ldr	x17, [x16, #0xa50]
  6dca68:      	add	x16, x16, #0xa50
  6dca6c:      	br	x17

00000000006dca70 <av_basename@plt>:
  6dca70:      	adrp	x16, 0x737000
  6dca74:      	ldr	x17, [x16, #0xa58]
  6dca78:      	add	x16, x16, #0xa58
  6dca7c:      	br	x17

00000000006dca80 <avio_alloc_context@plt>:
  6dca80:      	adrp	x16, 0x737000
  6dca84:      	ldr	x17, [x16, #0xa60]
  6dca88:      	add	x16, x16, #0xa60
  6dca8c:      	br	x17

00000000006dca90 <ff_raw_read_partial_packet@plt>:
  6dca90:      	adrp	x16, 0x737000
  6dca94:      	ldr	x17, [x16, #0xa68]
  6dca98:      	add	x16, x16, #0xa68
  6dca9c:      	br	x17

00000000006dcaa0 <ff_http_do_new_request2@plt>:
  6dcaa0:      	adrp	x16, 0x737000
  6dcaa4:      	ldr	x17, [x16, #0xa70]
  6dcaa8:      	add	x16, x16, #0xa70
  6dcaac:      	br	x17

00000000006dcab0 <av_opt_set_dict@plt>:
  6dcab0:      	adrp	x16, 0x737000
  6dcab4:      	ldr	x17, [x16, #0xa78]
  6dcab8:      	add	x16, x16, #0xa78
  6dcabc:      	br	x17

00000000006dcac0 <ffurl_write2@plt>:
  6dcac0:      	adrp	x16, 0x737000
  6dcac4:      	ldr	x17, [x16, #0xa80]
  6dcac8:      	add	x16, x16, #0xa80
  6dcacc:      	br	x17

00000000006dcad0 <ffurl_read2@plt>:
  6dcad0:      	adrp	x16, 0x737000
  6dcad4:      	ldr	x17, [x16, #0xa88]
  6dcad8:      	add	x16, x16, #0xa88
  6dcadc:      	br	x17

00000000006dcae0 <getenv@plt>:
  6dcae0:      	adrp	x16, 0x737000
  6dcae4:      	ldr	x17, [x16, #0xa90]
  6dcae8:      	add	x16, x16, #0xa90
  6dcaec:      	br	x17

00000000006dcaf0 <ff_http_match_no_proxy@plt>:
  6dcaf0:      	adrp	x16, 0x737000
  6dcaf4:      	ldr	x17, [x16, #0xa98]
  6dcaf8:      	add	x16, x16, #0xa98
  6dcafc:      	br	x17

00000000006dcb00 <av_strstart@plt>:
  6dcb00:      	adrp	x16, 0x737000
  6dcb04:      	ldr	x17, [x16, #0xaa0]
  6dcb08:      	add	x16, x16, #0xaa0
  6dcb0c:      	br	x17

00000000006dcb10 <ff_url_join@plt>:
  6dcb10:      	adrp	x16, 0x737000
  6dcb14:      	ldr	x17, [x16, #0xaa8]
  6dcb18:      	add	x16, x16, #0xaa8
  6dcb1c:      	br	x17

00000000006dcb20 <ffurl_open_whitelist@plt>:
  6dcb20:      	adrp	x16, 0x737000
  6dcb24:      	ldr	x17, [x16, #0xab0]
  6dcb28:      	add	x16, x16, #0xab0
  6dcb2c:      	br	x17

00000000006dcb30 <ff_http_auth_create_response@plt>:
  6dcb30:      	adrp	x16, 0x737000
  6dcb34:      	ldr	x17, [x16, #0xab8]
  6dcb38:      	add	x16, x16, #0xab8
  6dcb3c:      	br	x17

00000000006dcb40 <av_bprint_append_data@plt>:
  6dcb40:      	adrp	x16, 0x737000
  6dcb44:      	ldr	x17, [x16, #0xac0]
  6dcb48:      	add	x16, x16, #0xac0
  6dcb4c:      	br	x17

00000000006dcb50 <av_timegm@plt>:
  6dcb50:      	adrp	x16, 0x737000
  6dcb54:      	ldr	x17, [x16, #0xac8]
  6dcb58:      	add	x16, x16, #0xac8
  6dcb5c:      	br	x17

00000000006dcb60 <av_asprintf@plt>:
  6dcb60:      	adrp	x16, 0x737000
  6dcb64:      	ldr	x17, [x16, #0xad0]
  6dcb68:      	add	x16, x16, #0xad0
  6dcb6c:      	br	x17

00000000006dcb70 <ff_network_sleep_interruptible@plt>:
  6dcb70:      	adrp	x16, 0x737000
  6dcb74:      	ldr	x17, [x16, #0xad8]
  6dcb78:      	add	x16, x16, #0xad8
  6dcb7c:      	br	x17

00000000006dcb80 <ff_http_averror@plt>:
  6dcb80:      	adrp	x16, 0x737000
  6dcb84:      	ldr	x17, [x16, #0xae0]
  6dcb88:      	add	x16, x16, #0xae0
  6dcb8c:      	br	x17

00000000006dcb90 <av_dict_set_int@plt>:
  6dcb90:      	adrp	x16, 0x737000
  6dcb94:      	ldr	x17, [x16, #0xae8]
  6dcb98:      	add	x16, x16, #0xae8
  6dcb9c:      	br	x17

00000000006dcba0 <ffurl_accept@plt>:
  6dcba0:      	adrp	x16, 0x737000
  6dcba4:      	ldr	x17, [x16, #0xaf0]
  6dcba8:      	add	x16, x16, #0xaf0
  6dcbac:      	br	x17

00000000006dcbb0 <ffurl_handshake@plt>:
  6dcbb0:      	adrp	x16, 0x737000
  6dcbb4:      	ldr	x17, [x16, #0xaf8]
  6dcbb8:      	add	x16, x16, #0xaf8
  6dcbbc:      	br	x17

00000000006dcbc0 <ffurl_get_file_handle@plt>:
  6dcbc0:      	adrp	x16, 0x737000
  6dcbc4:      	ldr	x17, [x16, #0xb00]
  6dcbc8:      	add	x16, x16, #0xb00
  6dcbcc:      	br	x17

00000000006dcbd0 <ffurl_get_short_seek@plt>:
  6dcbd0:      	adrp	x16, 0x737000
  6dcbd4:      	ldr	x17, [x16, #0xb08]
  6dcbd8:      	add	x16, x16, #0xb08
  6dcbdc:      	br	x17

00000000006dcbe0 <av_stristart@plt>:
  6dcbe0:      	adrp	x16, 0x737000
  6dcbe4:      	ldr	x17, [x16, #0xb10]
  6dcbe8:      	add	x16, x16, #0xb10
  6dcbec:      	br	x17

00000000006dcbf0 <strtoul@plt>:
  6dcbf0:      	adrp	x16, 0x737000
  6dcbf4:      	ldr	x17, [x16, #0xb18]
  6dcbf8:      	add	x16, x16, #0xb18
  6dcbfc:      	br	x17

00000000006dcc00 <av_strndup@plt>:
  6dcc00:      	adrp	x16, 0x737000
  6dcc04:      	ldr	x17, [x16, #0xb20]
  6dcc08:      	add	x16, x16, #0xb20
  6dcc0c:      	br	x17

00000000006dcc10 <ff_make_absolute_url@plt>:
  6dcc10:      	adrp	x16, 0x737000
  6dcc14:      	ldr	x17, [x16, #0xb28]
  6dcc18:      	add	x16, x16, #0xb28
  6dcc1c:      	br	x17

00000000006dcc20 <ff_http_auth_handle_header@plt>:
  6dcc20:      	adrp	x16, 0x737000
  6dcc24:      	ldr	x17, [x16, #0xb30]
  6dcc28:      	add	x16, x16, #0xb30
  6dcc2c:      	br	x17

00000000006dcc30 <av_small_strptime@plt>:
  6dcc30:      	adrp	x16, 0x737000
  6dcc34:      	ldr	x17, [x16, #0xb38]
  6dcc38:      	add	x16, x16, #0xb38
  6dcc3c:      	br	x17

00000000006dcc40 <ffurl_close@plt>:
  6dcc40:      	adrp	x16, 0x737000
  6dcc44:      	ldr	x17, [x16, #0xb40]
  6dcc48:      	add	x16, x16, #0xb40
  6dcc4c:      	br	x17

00000000006dcc50 <ff_add_param_change@plt>:
  6dcc50:      	adrp	x16, 0x737000
  6dcc54:      	ldr	x17, [x16, #0xb48]
  6dcc58:      	add	x16, x16, #0xb48
  6dcc5c:      	br	x17

00000000006dcc60 <avio_seek_time@plt>:
  6dcc60:      	adrp	x16, 0x737000
  6dcc64:      	ldr	x17, [x16, #0xb50]
  6dcc68:      	add	x16, x16, #0xb50
  6dcc6c:      	br	x17

00000000006dcc70 <avpriv_dict_set_timestamp@plt>:
  6dcc70:      	adrp	x16, 0x737000
  6dcc74:      	ldr	x17, [x16, #0xb58]
  6dcc78:      	add	x16, x16, #0xb58
  6dcc7c:      	br	x17

00000000006dcc80 <ff_hevc_annexb2mp4@plt>:
  6dcc80:      	adrp	x16, 0x737000
  6dcc84:      	ldr	x17, [x16, #0xb60]
  6dcc88:      	add	x16, x16, #0xb60
  6dcc8c:      	br	x17

00000000006dcc90 <ff_hevc_annexb2mp4_buf@plt>:
  6dcc90:      	adrp	x16, 0x737000
  6dcc94:      	ldr	x17, [x16, #0xb68]
  6dcc98:      	add	x16, x16, #0xb68
  6dcc9c:      	br	x17

00000000006dcca0 <ff_isom_write_lhvc@plt>:
  6dcca0:      	adrp	x16, 0x737000
  6dcca4:      	ldr	x17, [x16, #0xb70]
  6dcca8:      	add	x16, x16, #0xb70
  6dccac:      	br	x17

00000000006dccb0 <avformat_alloc_context@plt>:
  6dccb0:      	adrp	x16, 0x737000
  6dccb4:      	ldr	x17, [x16, #0xb78]
  6dccb8:      	add	x16, x16, #0xb78
  6dccbc:      	br	x17

00000000006dccc0 <ff_is_intra_only@plt>:
  6dccc0:      	adrp	x16, 0x737000
  6dccc4:      	ldr	x17, [x16, #0xb80]
  6dccc8:      	add	x16, x16, #0xb80
  6dcccc:      	br	x17

00000000006dccd0 <ff_interleave_add_packet@plt>:
  6dccd0:      	adrp	x16, 0x737000
  6dccd4:      	ldr	x17, [x16, #0xb88]
  6dccd8:      	add	x16, x16, #0xb88
  6dccdc:      	br	x17

00000000006dcce0 <ff_get_muxer_ts_offset@plt>:
  6dcce0:      	adrp	x16, 0x737000
  6dcce4:      	ldr	x17, [x16, #0xb90]
  6dcce8:      	add	x16, x16, #0xb90
  6dccec:      	br	x17

00000000006dccf0 <ff_interleaved_peek@plt>:
  6dccf0:      	adrp	x16, 0x737000
  6dccf4:      	ldr	x17, [x16, #0xb98]
  6dccf8:      	add	x16, x16, #0xb98
  6dccfc:      	br	x17

00000000006dcd00 <av_interleaved_write_frame@plt>:
  6dcd00:      	adrp	x16, 0x737000
  6dcd04:      	ldr	x17, [x16, #0xba0]
  6dcd08:      	add	x16, x16, #0xba0
  6dcd0c:      	br	x17

00000000006dcd10 <av_set_options_string@plt>:
  6dcd10:      	adrp	x16, 0x737000
  6dcd14:      	ldr	x17, [x16, #0xba8]
  6dcd18:      	add	x16, x16, #0xba8
  6dcd1c:      	br	x17

00000000006dcd20 <ff_raw_write_packet@plt>:
  6dcd20:      	adrp	x16, 0x737000
  6dcd24:      	ldr	x17, [x16, #0xbb0]
  6dcd28:      	add	x16, x16, #0xbb0
  6dcd2c:      	br	x17

00000000006dcd30 <ff_udp_set_remote_url@plt>:
  6dcd30:      	adrp	x16, 0x737000
  6dcd34:      	ldr	x17, [x16, #0xbb8]
  6dcd38:      	add	x16, x16, #0xbb8
  6dcd3c:      	br	x17

00000000006dcd40 <ff_udp_get_local_port@plt>:
  6dcd40:      	adrp	x16, 0x737000
  6dcd44:      	ldr	x17, [x16, #0xbc0]
  6dcd48:      	add	x16, x16, #0xbc0
  6dcd4c:      	br	x17

00000000006dcd50 <av_dict_parse_string@plt>:
  6dcd50:      	adrp	x16, 0x737000
  6dcd54:      	ldr	x17, [x16, #0xbc8]
  6dcd58:      	add	x16, x16, #0xbc8
  6dcd5c:      	br	x17

00000000006dcd60 <ff_ip_reset_filters@plt>:
  6dcd60:      	adrp	x16, 0x737000
  6dcd64:      	ldr	x17, [x16, #0xbd0]
  6dcd68:      	add	x16, x16, #0xbd0
  6dcd6c:      	br	x17

00000000006dcd70 <ff_check_interrupt@plt>:
  6dcd70:      	adrp	x16, 0x737000
  6dcd74:      	ldr	x17, [x16, #0xbd8]
  6dcd78:      	add	x16, x16, #0xbd8
  6dcd7c:      	br	x17

00000000006dcd80 <recvfrom@plt>:
  6dcd80:      	adrp	x16, 0x737000
  6dcd84:      	ldr	x17, [x16, #0xbe0]
  6dcd88:      	add	x16, x16, #0xbe0
  6dcd8c:      	br	x17

00000000006dcd90 <ff_ip_check_source_lists@plt>:
  6dcd90:      	adrp	x16, 0x737000
  6dcd94:      	ldr	x17, [x16, #0xbe8]
  6dcd98:      	add	x16, x16, #0xbe8
  6dcd9c:      	br	x17

00000000006dcda0 <ff_network_wait_fd@plt>:
  6dcda0:      	adrp	x16, 0x737000
  6dcda4:      	ldr	x17, [x16, #0xbf0]
  6dcda8:      	add	x16, x16, #0xbf0
  6dcdac:      	br	x17

00000000006dcdb0 <sendto@plt>:
  6dcdb0:      	adrp	x16, 0x737000
  6dcdb4:      	ldr	x17, [x16, #0xbf8]
  6dcdb8:      	add	x16, x16, #0xbf8
  6dcdbc:      	br	x17

00000000006dcdc0 <vsnprintf@plt>:
  6dcdc0:      	adrp	x16, 0x737000
  6dcdc4:      	ldr	x17, [x16, #0xc00]
  6dcdc8:      	add	x16, x16, #0xc00
  6dcdcc:      	br	x17

00000000006dcdd0 <ff_ip_parse_sources@plt>:
  6dcdd0:      	adrp	x16, 0x737000
  6dcdd4:      	ldr	x17, [x16, #0xc08]
  6dcdd8:      	add	x16, x16, #0xc08
  6dcddc:      	br	x17

00000000006dcde0 <ff_ip_parse_blocks@plt>:
  6dcde0:      	adrp	x16, 0x737000
  6dcde4:      	ldr	x17, [x16, #0xc10]
  6dcde8:      	add	x16, x16, #0xc10
  6dcdec:      	br	x17

00000000006dcdf0 <ff_mov_init_hinting@plt>:
  6dcdf0:      	adrp	x16, 0x737000
  6dcdf4:      	ldr	x17, [x16, #0xc18]
  6dcdf8:      	add	x16, x16, #0xc18
  6dcdfc:      	br	x17

00000000006dce00 <ff_rtp_chain_mux_open@plt>:
  6dce00:      	adrp	x16, 0x737000
  6dce04:      	ldr	x17, [x16, #0xc20]
  6dce08:      	add	x16, x16, #0xc20
  6dce0c:      	br	x17

00000000006dce10 <ff_mov_add_hinted_packet@plt>:
  6dce10:      	adrp	x16, 0x737000
  6dce14:      	ldr	x17, [x16, #0xc28]
  6dce18:      	add	x16, x16, #0xc28
  6dce1c:      	br	x17

00000000006dce20 <ffio_open_dyn_packet_buf@plt>:
  6dce20:      	adrp	x16, 0x737000
  6dce24:      	ldr	x17, [x16, #0xc30]
  6dce28:      	add	x16, x16, #0xc30
  6dce2c:      	br	x17

00000000006dce30 <ff_mov_write_packet@plt>:
  6dce30:      	adrp	x16, 0x737000
  6dce34:      	ldr	x17, [x16, #0xc38]
  6dce38:      	add	x16, x16, #0xc38
  6dce3c:      	br	x17

00000000006dce40 <ff_mov_close_hinting@plt>:
  6dce40:      	adrp	x16, 0x737000
  6dce44:      	ldr	x17, [x16, #0xc40]
  6dce48:      	add	x16, x16, #0xc40
  6dce4c:      	br	x17

00000000006dce50 <ff_get_qtpalette@plt>:
  6dce50:      	adrp	x16, 0x737000
  6dce54:      	ldr	x17, [x16, #0xc48]
  6dce58:      	add	x16, x16, #0xc48
  6dce5c:      	br	x17

00000000006dce60 <ff_avc_decode_sps@plt>:
  6dce60:      	adrp	x16, 0x737000
  6dce64:      	ldr	x17, [x16, #0xc50]
  6dce68:      	add	x16, x16, #0xc50
  6dce6c:      	br	x17

00000000006dce70 <ff_avc_write_annexb_extradata@plt>:
  6dce70:      	adrp	x16, 0x737000
  6dce74:      	ldr	x17, [x16, #0xc58]
  6dce78:      	add	x16, x16, #0xc58
  6dce7c:      	br	x17

00000000006dce80 <ff_rtp_get_payload_type@plt>:
  6dce80:      	adrp	x16, 0x737000
  6dce84:      	ldr	x17, [x16, #0xc60]
  6dce88:      	add	x16, x16, #0xc60
  6dce8c:      	br	x17

00000000006dce90 <av_opt_flag_is_set@plt>:
  6dce90:      	adrp	x16, 0x737000
  6dce94:      	ldr	x17, [x16, #0xc68]
  6dce98:      	add	x16, x16, #0xc68
  6dce9c:      	br	x17

00000000006dcea0 <ff_vvc_annexb2mp4@plt>:
  6dcea0:      	adrp	x16, 0x737000
  6dcea4:      	ldr	x17, [x16, #0xc70]
  6dcea8:      	add	x16, x16, #0xc70
  6dceac:      	br	x17

00000000006dceb0 <ff_vvc_annexb2mp4_buf@plt>:
  6dceb0:      	adrp	x16, 0x737000
  6dceb4:      	ldr	x17, [x16, #0xc78]
  6dceb8:      	add	x16, x16, #0xc78
  6dcebc:      	br	x17

00000000006dcec0 <ff_isom_write_vvcc@plt>:
  6dcec0:      	adrp	x16, 0x737000
  6dcec4:      	ldr	x17, [x16, #0xc80]
  6dcec8:      	add	x16, x16, #0xc80
  6dcecc:      	br	x17

00000000006dced0 <ff_mov_cenc_write_packet@plt>:
  6dced0:      	adrp	x16, 0x737000
  6dced4:      	ldr	x17, [x16, #0xc88]
  6dced8:      	add	x16, x16, #0xc88
  6dcedc:      	br	x17

00000000006dcee0 <av_aes_ctr_get_iv@plt>:
  6dcee0:      	adrp	x16, 0x737000
  6dcee4:      	ldr	x17, [x16, #0xc90]
  6dcee8:      	add	x16, x16, #0xc90
  6dceec:      	br	x17

00000000006dcef0 <av_aes_ctr_crypt@plt>:
  6dcef0:      	adrp	x16, 0x737000
  6dcef4:      	ldr	x17, [x16, #0xc98]
  6dcef8:      	add	x16, x16, #0xc98
  6dcefc:      	br	x17

00000000006dcf00 <av_aes_ctr_increment_iv@plt>:
  6dcf00:      	adrp	x16, 0x737000
  6dcf04:      	ldr	x17, [x16, #0xca0]
  6dcf08:      	add	x16, x16, #0xca0
  6dcf0c:      	br	x17

00000000006dcf10 <ff_mov_cenc_avc_parse_nal_units@plt>:
  6dcf10:      	adrp	x16, 0x737000
  6dcf14:      	ldr	x17, [x16, #0xca8]
  6dcf18:      	add	x16, x16, #0xca8
  6dcf1c:      	br	x17

00000000006dcf20 <ff_mov_cenc_avc_write_nal_units@plt>:
  6dcf20:      	adrp	x16, 0x737000
  6dcf24:      	ldr	x17, [x16, #0xcb0]
  6dcf28:      	add	x16, x16, #0xcb0
  6dcf2c:      	br	x17

00000000006dcf30 <ff_mov_cenc_write_stbl_atoms@plt>:
  6dcf30:      	adrp	x16, 0x737000
  6dcf34:      	ldr	x17, [x16, #0xcb8]
  6dcf38:      	add	x16, x16, #0xcb8
  6dcf3c:      	br	x17

00000000006dcf40 <ff_mov_cenc_write_sinf_tag@plt>:
  6dcf40:      	adrp	x16, 0x737000
  6dcf44:      	ldr	x17, [x16, #0xcc0]
  6dcf48:      	add	x16, x16, #0xcc0
  6dcf4c:      	br	x17

00000000006dcf50 <ff_mov_cenc_init@plt>:
  6dcf50:      	adrp	x16, 0x737000
  6dcf54:      	ldr	x17, [x16, #0xcc8]
  6dcf58:      	add	x16, x16, #0xcc8
  6dcf5c:      	br	x17

00000000006dcf60 <av_aes_ctr_alloc@plt>:
  6dcf60:      	adrp	x16, 0x737000
  6dcf64:      	ldr	x17, [x16, #0xcd0]
  6dcf68:      	add	x16, x16, #0xcd0
  6dcf6c:      	br	x17

00000000006dcf70 <av_aes_ctr_init@plt>:
  6dcf70:      	adrp	x16, 0x737000
  6dcf74:      	ldr	x17, [x16, #0xcd8]
  6dcf78:      	add	x16, x16, #0xcd8
  6dcf7c:      	br	x17

00000000006dcf80 <av_aes_ctr_set_random_iv@plt>:
  6dcf80:      	adrp	x16, 0x737000
  6dcf84:      	ldr	x17, [x16, #0xce0]
  6dcf88:      	add	x16, x16, #0xce0
  6dcf8c:      	br	x17

00000000006dcf90 <ff_mov_cenc_free@plt>:
  6dcf90:      	adrp	x16, 0x737000
  6dcf94:      	ldr	x17, [x16, #0xce8]
  6dcf98:      	add	x16, x16, #0xce8
  6dcf9c:      	br	x17

00000000006dcfa0 <av_aes_ctr_free@plt>:
  6dcfa0:      	adrp	x16, 0x737000
  6dcfa4:      	ldr	x17, [x16, #0xcf0]
  6dcfa8:      	add	x16, x16, #0xcf0
  6dcfac:      	br	x17

00000000006dcfb0 <av_base64_encode@plt>:
  6dcfb0:      	adrp	x16, 0x737000
  6dcfb4:      	ldr	x17, [x16, #0xcf8]
  6dcfb8:      	add	x16, x16, #0xcf8
  6dcfbc:      	br	x17

00000000006dcfc0 <ff_urldecode@plt>:
  6dcfc0:      	adrp	x16, 0x737000
  6dcfc4:      	ldr	x17, [x16, #0xd00]
  6dcfc8:      	add	x16, x16, #0xd00
  6dcfcc:      	br	x17

00000000006dcfd0 <ff_id3v1_read@plt>:
  6dcfd0:      	adrp	x16, 0x737000
  6dcfd4:      	ldr	x17, [x16, #0xd08]
  6dcfd8:      	add	x16, x16, #0xd08
  6dcfdc:      	br	x17

00000000006dcfe0 <ff_id3v2_match@plt>:
  6dcfe0:      	adrp	x16, 0x737000
  6dcfe4:      	ldr	x17, [x16, #0xd10]
  6dcfe8:      	add	x16, x16, #0xd10
  6dcfec:      	br	x17

00000000006dcff0 <ff_id3v2_tag_len@plt>:
  6dcff0:      	adrp	x16, 0x737000
  6dcff4:      	ldr	x17, [x16, #0xd18]
  6dcff8:      	add	x16, x16, #0xd18
  6dcffc:      	br	x17

00000000006dd000 <ffio_init_read_context@plt>:
  6dd000:      	adrp	x16, 0x737000
  6dd004:      	ldr	x17, [x16, #0xd20]
  6dd008:      	add	x16, x16, #0xd20
  6dd00c:      	br	x17

00000000006dd010 <ff_id3v2_read_dict@plt>:
  6dd010:      	adrp	x16, 0x737000
  6dd014:      	ldr	x17, [x16, #0xd28]
  6dd018:      	add	x16, x16, #0xd28
  6dd01c:      	br	x17

00000000006dd020 <ff_id3v2_parse_priv_dict@plt>:
  6dd020:      	adrp	x16, 0x737000
  6dd024:      	ldr	x17, [x16, #0xd30]
  6dd028:      	add	x16, x16, #0xd30
  6dd02c:      	br	x17

00000000006dd030 <ff_vorbis_comment@plt>:
  6dd030:      	adrp	x16, 0x737000
  6dd034:      	ldr	x17, [x16, #0xd38]
  6dd038:      	add	x16, x16, #0xd38
  6dd03c:      	br	x17

00000000006dd040 <av_base64_decode@plt>:
  6dd040:      	adrp	x16, 0x737000
  6dd044:      	ldr	x17, [x16, #0xd40]
  6dd048:      	add	x16, x16, #0xd40
  6dd04c:      	br	x17

00000000006dd050 <ff_flac_parse_picture@plt>:
  6dd050:      	adrp	x16, 0x737000
  6dd054:      	ldr	x17, [x16, #0xd48]
  6dd058:      	add	x16, x16, #0xd48
  6dd05c:      	br	x17

00000000006dd060 <avpriv_new_chapter@plt>:
  6dd060:      	adrp	x16, 0x737000
  6dd064:      	ldr	x17, [x16, #0xd50]
  6dd068:      	add	x16, x16, #0xd50
  6dd06c:      	br	x17

00000000006dd070 <avpriv_open@plt>:
  6dd070:      	adrp	x16, 0x737000
  6dd074:      	ldr	x17, [x16, #0xd58]
  6dd078:      	add	x16, x16, #0xd58
  6dd07c:      	br	x17

00000000006dd080 <fstat@plt>:
  6dd080:      	adrp	x16, 0x737000
  6dd084:      	ldr	x17, [x16, #0xd60]
  6dd088:      	add	x16, x16, #0xd60
  6dd08c:      	br	x17

00000000006dd090 <read@plt>:
  6dd090:      	adrp	x16, 0x737000
  6dd094:      	ldr	x17, [x16, #0xd68]
  6dd098:      	add	x16, x16, #0xd68
  6dd09c:      	br	x17

00000000006dd0a0 <write@plt>:
  6dd0a0:      	adrp	x16, 0x737000
  6dd0a4:      	ldr	x17, [x16, #0xd70]
  6dd0a8:      	add	x16, x16, #0xd70
  6dd0ac:      	br	x17

00000000006dd0b0 <lseek64@plt>:
  6dd0b0:      	adrp	x16, 0x737000
  6dd0b4:      	ldr	x17, [x16, #0xd78]
  6dd0b8:      	add	x16, x16, #0xd78
  6dd0bc:      	br	x17

00000000006dd0c0 <access@plt>:
  6dd0c0:      	adrp	x16, 0x737000
  6dd0c4:      	ldr	x17, [x16, #0xd80]
  6dd0c8:      	add	x16, x16, #0xd80
  6dd0cc:      	br	x17

00000000006dd0d0 <ff_alloc_dir_entry@plt>:
  6dd0d0:      	adrp	x16, 0x737000
  6dd0d4:      	ldr	x17, [x16, #0xd88]
  6dd0d8:      	add	x16, x16, #0xd88
  6dd0dc:      	br	x17

00000000006dd0e0 <av_append_path_component@plt>:
  6dd0e0:      	adrp	x16, 0x737000
  6dd0e4:      	ldr	x17, [x16, #0xd90]
  6dd0e8:      	add	x16, x16, #0xd90
  6dd0ec:      	br	x17

00000000006dd0f0 <lstat@plt>:
  6dd0f0:      	adrp	x16, 0x737000
  6dd0f4:      	ldr	x17, [x16, #0xd98]
  6dd0f8:      	add	x16, x16, #0xd98
  6dd0fc:      	br	x17

00000000006dd100 <rmdir@plt>:
  6dd100:      	adrp	x16, 0x737000
  6dd104:      	ldr	x17, [x16, #0xda0]
  6dd108:      	add	x16, x16, #0xda0
  6dd10c:      	br	x17

00000000006dd110 <unlink@plt>:
  6dd110:      	adrp	x16, 0x737000
  6dd114:      	ldr	x17, [x16, #0xda8]
  6dd118:      	add	x16, x16, #0xda8
  6dd11c:      	br	x17

00000000006dd120 <rename@plt>:
  6dd120:      	adrp	x16, 0x737000
  6dd124:      	ldr	x17, [x16, #0xdb0]
  6dd128:      	add	x16, x16, #0xdb0
  6dd12c:      	br	x17

00000000006dd130 <ff_standardize_creation_time@plt>:
  6dd130:      	adrp	x16, 0x737000
  6dd134:      	ldr	x17, [x16, #0xdb8]
  6dd138:      	add	x16, x16, #0xdb8
  6dd13c:      	br	x17

00000000006dd140 <ff_isom_write_vpcc@plt>:
  6dd140:      	adrp	x16, 0x737000
  6dd144:      	ldr	x17, [x16, #0xdc0]
  6dd148:      	add	x16, x16, #0xdc0
  6dd14c:      	br	x17

00000000006dd150 <avio_rl64@plt>:
  6dd150:      	adrp	x16, 0x737000
  6dd154:      	ldr	x17, [x16, #0xdc8]
  6dd158:      	add	x16, x16, #0xdc8
  6dd15c:      	br	x17

00000000006dd160 <ff_get_guid@plt>:
  6dd160:      	adrp	x16, 0x737000
  6dd164:      	ldr	x17, [x16, #0xdd0]
  6dd168:      	add	x16, x16, #0xdd0
  6dd16c:      	br	x17

00000000006dd170 <avio_get_str16le@plt>:
  6dd170:      	adrp	x16, 0x737000
  6dd174:      	ldr	x17, [x16, #0xdd8]
  6dd178:      	add	x16, x16, #0xdd8
  6dd17c:      	br	x17

00000000006dd180 <ff_get_wav_header@plt>:
  6dd180:      	adrp	x16, 0x737000
  6dd184:      	ldr	x17, [x16, #0xde0]
  6dd188:      	add	x16, x16, #0xde0
  6dd18c:      	br	x17

00000000006dd190 <ff_asfcrypt_dec@plt>:
  6dd190:      	adrp	x16, 0x737000
  6dd194:      	ldr	x17, [x16, #0xde8]
  6dd198:      	add	x16, x16, #0xde8
  6dd19c:      	br	x17

00000000006dd1a0 <__assert2@plt>:
  6dd1a0:      	adrp	x16, 0x737000
  6dd1a4:      	ldr	x17, [x16, #0xdf0]
  6dd1a8:      	add	x16, x16, #0xdf0
  6dd1ac:      	br	x17

00000000006dd1b0 <ff_asf_handle_byte_array@plt>:
  6dd1b0:      	adrp	x16, 0x737000
  6dd1b4:      	ldr	x17, [x16, #0xdf8]
  6dd1b8:      	add	x16, x16, #0xdf8
  6dd1bc:      	br	x17

00000000006dd1c0 <av_muxer_iterate@plt>:
  6dd1c0:      	adrp	x16, 0x737000
  6dd1c4:      	ldr	x17, [x16, #0xe00]
  6dd1c8:      	add	x16, x16, #0xe00
  6dd1cc:      	br	x17

00000000006dd1d0 <av_demuxer_iterate@plt>:
  6dd1d0:      	adrp	x16, 0x737000
  6dd1d4:      	ldr	x17, [x16, #0xe08]
  6dd1d8:      	add	x16, x16, #0xe08
  6dd1dc:      	br	x17

00000000006dd1e0 <av_chroma_location_pos_to_enum@plt>:
  6dd1e0:      	adrp	x16, 0x737000
  6dd1e4:      	ldr	x17, [x16, #0xe10]
  6dd1e8:      	add	x16, x16, #0xe10
  6dd1ec:      	br	x17

00000000006dd1f0 <av_stereo3d_alloc_size@plt>:
  6dd1f0:      	adrp	x16, 0x737000
  6dd1f4:      	ldr	x17, [x16, #0xe18]
  6dd1f8:      	add	x16, x16, #0xe18
  6dd1fc:      	br	x17

00000000006dd200 <av_spherical_alloc@plt>:
  6dd200:      	adrp	x16, 0x737000
  6dd204:      	ldr	x17, [x16, #0xe20]
  6dd208:      	add	x16, x16, #0xe20
  6dd20c:      	br	x17

00000000006dd210 <ff_isom_parse_dvcc_dvvc@plt>:
  6dd210:      	adrp	x16, 0x737000
  6dd214:      	ldr	x17, [x16, #0xe28]
  6dd218:      	add	x16, x16, #0xe28
  6dd21c:      	br	x17

00000000006dd220 <ff_add_attached_pic@plt>:
  6dd220:      	adrp	x16, 0x737000
  6dd224:      	ldr	x17, [x16, #0xe30]
  6dd228:      	add	x16, x16, #0xe30
  6dd22c:      	br	x17

00000000006dd230 <av_lzo1x_decode@plt>:
  6dd230:      	adrp	x16, 0x737000
  6dd234:      	ldr	x17, [x16, #0xe38]
  6dd238:      	add	x16, x16, #0xe38
  6dd23c:      	br	x17

00000000006dd240 <ff_rm_reorder_sipr_data@plt>:
  6dd240:      	adrp	x16, 0x737000
  6dd244:      	ldr	x17, [x16, #0xe40]
  6dd248:      	add	x16, x16, #0xe40
  6dd24c:      	br	x17

00000000006dd250 <av_fifo_grow2@plt>:
  6dd250:      	adrp	x16, 0x737000
  6dd254:      	ldr	x17, [x16, #0xe48]
  6dd258:      	add	x16, x16, #0xe48
  6dd25c:      	br	x17

00000000006dd260 <av_fifo_read_to_cb@plt>:
  6dd260:      	adrp	x16, 0x737000
  6dd264:      	ldr	x17, [x16, #0xe50]
  6dd268:      	add	x16, x16, #0xe50
  6dd26c:      	br	x17

00000000006dd270 <ff_remove_stream@plt>:
  6dd270:      	adrp	x16, 0x737000
  6dd274:      	ldr	x17, [x16, #0xe58]
  6dd278:      	add	x16, x16, #0xe58
  6dd27c:      	br	x17

00000000006dd280 <avio_pause@plt>:
  6dd280:      	adrp	x16, 0x737000
  6dd284:      	ldr	x17, [x16, #0xe60]
  6dd288:      	add	x16, x16, #0xe60
  6dd28c:      	br	x17

00000000006dd290 <ff_generate_avci_extradata@plt>:
  6dd290:      	adrp	x16, 0x737000
  6dd294:      	ldr	x17, [x16, #0xe68]
  6dd298:      	add	x16, x16, #0xe68
  6dd29c:      	br	x17

00000000006dd2a0 <ffio_read_size@plt>:
  6dd2a0:      	adrp	x16, 0x737000
  6dd2a4:      	ldr	x17, [x16, #0xe70]
  6dd2a8:      	add	x16, x16, #0xe70
  6dd2ac:      	br	x17

00000000006dd2b0 <ff_find_stream_index@plt>:
  6dd2b0:      	adrp	x16, 0x737000
  6dd2b4:      	ldr	x17, [x16, #0xe78]
  6dd2b8:      	add	x16, x16, #0xe78
  6dd2bc:      	br	x17

00000000006dd2c0 <ffurl_seek2@plt>:
  6dd2c0:      	adrp	x16, 0x737000
  6dd2c4:      	ldr	x17, [x16, #0xe80]
  6dd2c8:      	add	x16, x16, #0xe80
  6dd2cc:      	br	x17

00000000006dd2d0 <ffurl_read_complete@plt>:
  6dd2d0:      	adrp	x16, 0x737000
  6dd2d4:      	ldr	x17, [x16, #0xe88]
  6dd2d8:      	add	x16, x16, #0xe88
  6dd2dc:      	br	x17

00000000006dd2e0 <av_opt_set_bin@plt>:
  6dd2e0:      	adrp	x16, 0x737000
  6dd2e4:      	ldr	x17, [x16, #0xe90]
  6dd2e8:      	add	x16, x16, #0xe90
  6dd2ec:      	br	x17

00000000006dd2f0 <ff_rtmp_packet_read@plt>:
  6dd2f0:      	adrp	x16, 0x737000
  6dd2f4:      	ldr	x17, [x16, #0xe98]
  6dd2f8:      	add	x16, x16, #0xe98
  6dd2fc:      	br	x17

00000000006dd300 <ff_rtmp_packet_create@plt>:
  6dd300:      	adrp	x16, 0x737000
  6dd304:      	ldr	x17, [x16, #0xea0]
  6dd308:      	add	x16, x16, #0xea0
  6dd30c:      	br	x17

00000000006dd310 <ff_amf_write_string@plt>:
  6dd310:      	adrp	x16, 0x737000
  6dd314:      	ldr	x17, [x16, #0xea8]
  6dd318:      	add	x16, x16, #0xea8
  6dd31c:      	br	x17

00000000006dd320 <ff_amf_write_number@plt>:
  6dd320:      	adrp	x16, 0x737000
  6dd324:      	ldr	x17, [x16, #0xeb0]
  6dd328:      	add	x16, x16, #0xeb0
  6dd32c:      	br	x17

00000000006dd330 <ff_amf_write_object_start@plt>:
  6dd330:      	adrp	x16, 0x737000
  6dd334:      	ldr	x17, [x16, #0xeb8]
  6dd338:      	add	x16, x16, #0xeb8
  6dd33c:      	br	x17

00000000006dd340 <ff_amf_write_array_start@plt>:
  6dd340:      	adrp	x16, 0x737000
  6dd344:      	ldr	x17, [x16, #0xec0]
  6dd348:      	add	x16, x16, #0xec0
  6dd34c:      	br	x17

00000000006dd350 <ff_amf_write_bool@plt>:
  6dd350:      	adrp	x16, 0x737000
  6dd354:      	ldr	x17, [x16, #0xec8]
  6dd358:      	add	x16, x16, #0xec8
  6dd35c:      	br	x17

00000000006dd360 <ff_amf_write_object_end@plt>:
  6dd360:      	adrp	x16, 0x737000
  6dd364:      	ldr	x17, [x16, #0xed0]
  6dd368:      	add	x16, x16, #0xed0
  6dd36c:      	br	x17

00000000006dd370 <ff_amf_write_field_name@plt>:
  6dd370:      	adrp	x16, 0x737000
  6dd374:      	ldr	x17, [x16, #0xed8]
  6dd378:      	add	x16, x16, #0xed8
  6dd37c:      	br	x17

00000000006dd380 <ff_amf_write_null@plt>:
  6dd380:      	adrp	x16, 0x737000
  6dd384:      	ldr	x17, [x16, #0xee0]
  6dd388:      	add	x16, x16, #0xee0
  6dd38c:      	br	x17

00000000006dd390 <ff_amf_read_string@plt>:
  6dd390:      	adrp	x16, 0x737000
  6dd394:      	ldr	x17, [x16, #0xee8]
  6dd398:      	add	x16, x16, #0xee8
  6dd39c:      	br	x17

00000000006dd3a0 <ff_amf_read_number@plt>:
  6dd3a0:      	adrp	x16, 0x737000
  6dd3a4:      	ldr	x17, [x16, #0xef0]
  6dd3a8:      	add	x16, x16, #0xef0
  6dd3ac:      	br	x17

00000000006dd3b0 <ff_amf_get_field_value@plt>:
  6dd3b0:      	adrp	x16, 0x737000
  6dd3b4:      	ldr	x17, [x16, #0xef8]
  6dd3b8:      	add	x16, x16, #0xef8
  6dd3bc:      	br	x17

00000000006dd3c0 <ff_rtmp_packet_destroy@plt>:
  6dd3c0:      	adrp	x16, 0x737000
  6dd3c4:      	ldr	x17, [x16, #0xf00]
  6dd3c8:      	add	x16, x16, #0xf00
  6dd3cc:      	br	x17

00000000006dd3d0 <ff_rtmp_check_alloc_array@plt>:
  6dd3d0:      	adrp	x16, 0x737000
  6dd3d4:      	ldr	x17, [x16, #0xf08]
  6dd3d8:      	add	x16, x16, #0xf08
  6dd3dc:      	br	x17

00000000006dd3e0 <ff_rtmp_packet_read_internal@plt>:
  6dd3e0:      	adrp	x16, 0x737000
  6dd3e4:      	ldr	x17, [x16, #0xf10]
  6dd3e8:      	add	x16, x16, #0xf10
  6dd3ec:      	br	x17

00000000006dd3f0 <ff_amf_get_string@plt>:
  6dd3f0:      	adrp	x16, 0x737000
  6dd3f4:      	ldr	x17, [x16, #0xf18]
  6dd3f8:      	add	x16, x16, #0xf18
  6dd3fc:      	br	x17

00000000006dd400 <ff_amf_tag_size@plt>:
  6dd400:      	adrp	x16, 0x737000
  6dd404:      	ldr	x17, [x16, #0xf20]
  6dd408:      	add	x16, x16, #0xf20
  6dd40c:      	br	x17

00000000006dd410 <ff_rtmp_packet_write@plt>:
  6dd410:      	adrp	x16, 0x737000
  6dd414:      	ldr	x17, [x16, #0xf28]
  6dd418:      	add	x16, x16, #0xf28
  6dd41c:      	br	x17

00000000006dd420 <ff_amf_match_string@plt>:
  6dd420:      	adrp	x16, 0x737000
  6dd424:      	ldr	x17, [x16, #0xf30]
  6dd428:      	add	x16, x16, #0xf30
  6dd42c:      	br	x17

00000000006dd430 <ff_amf_read_null@plt>:
  6dd430:      	adrp	x16, 0x737000
  6dd434:      	ldr	x17, [x16, #0xf38]
  6dd438:      	add	x16, x16, #0xf38
  6dd43c:      	br	x17

00000000006dd440 <ff_amf_write_string2@plt>:
  6dd440:      	adrp	x16, 0x737000
  6dd444:      	ldr	x17, [x16, #0xf40]
  6dd448:      	add	x16, x16, #0xf40
  6dd44c:      	br	x17

00000000006dd450 <av_des_alloc@plt>:
  6dd450:      	adrp	x16, 0x737000
  6dd454:      	ldr	x17, [x16, #0xf48]
  6dd458:      	add	x16, x16, #0xf48
  6dd45c:      	br	x17

00000000006dd460 <av_rc4_alloc@plt>:
  6dd460:      	adrp	x16, 0x737000
  6dd464:      	ldr	x17, [x16, #0xf50]
  6dd468:      	add	x16, x16, #0xf50
  6dd46c:      	br	x17

00000000006dd470 <av_rc4_init@plt>:
  6dd470:      	adrp	x16, 0x737000
  6dd474:      	ldr	x17, [x16, #0xf58]
  6dd478:      	add	x16, x16, #0xf58
  6dd47c:      	br	x17

00000000006dd480 <av_rc4_crypt@plt>:
  6dd480:      	adrp	x16, 0x737000
  6dd484:      	ldr	x17, [x16, #0xf60]
  6dd488:      	add	x16, x16, #0xf60
  6dd48c:      	br	x17

00000000006dd490 <av_des_init@plt>:
  6dd490:      	adrp	x16, 0x737000
  6dd494:      	ldr	x17, [x16, #0xf68]
  6dd498:      	add	x16, x16, #0xf68
  6dd49c:      	br	x17

00000000006dd4a0 <av_des_crypt@plt>:
  6dd4a0:      	adrp	x16, 0x737000
  6dd4a4:      	ldr	x17, [x16, #0xf70]
  6dd4a8:      	add	x16, x16, #0xf70
  6dd4ac:      	br	x17

00000000006dd4b0 <ff_id3v2_write_simple@plt>:
  6dd4b0:      	adrp	x16, 0x737000
  6dd4b4:      	ldr	x17, [x16, #0xf78]
  6dd4b8:      	add	x16, x16, #0xf78
  6dd4bc:      	br	x17

00000000006dd4c0 <ff_ape_write_tag@plt>:
  6dd4c0:      	adrp	x16, 0x737000
  6dd4c4:      	ldr	x17, [x16, #0xf80]
  6dd4c8:      	add	x16, x16, #0xf80
  6dd4cc:      	br	x17

00000000006dd4d0 <ffio_ensure_seekback@plt>:
  6dd4d0:      	adrp	x16, 0x737000
  6dd4d4:      	ldr	x17, [x16, #0xf88]
  6dd4d8:      	add	x16, x16, #0xf88
  6dd4dc:      	br	x17

00000000006dd4e0 <avio_read_to_bprint@plt>:
  6dd4e0:      	adrp	x16, 0x737000
  6dd4e4:      	ldr	x17, [x16, #0xf90]
  6dd4e8:      	add	x16, x16, #0xf90
  6dd4ec:      	br	x17

00000000006dd4f0 <avio_read_partial@plt>:
  6dd4f0:      	adrp	x16, 0x737000
  6dd4f4:      	ldr	x17, [x16, #0xf98]
  6dd4f8:      	add	x16, x16, #0xf98
  6dd4fc:      	br	x17

00000000006dd500 <av_opt_get@plt>:
  6dd500:      	adrp	x16, 0x737000
  6dd504:      	ldr	x17, [x16, #0xfa0]
  6dd508:      	add	x16, x16, #0xfa0
  6dd50c:      	br	x17

00000000006dd510 <ffio_open_whitelist@plt>:
  6dd510:      	adrp	x16, 0x737000
  6dd514:      	ldr	x17, [x16, #0xfa8]
  6dd518:      	add	x16, x16, #0xfa8
  6dd51c:      	br	x17

00000000006dd520 <avio_close@plt>:
  6dd520:      	adrp	x16, 0x737000
  6dd524:      	ldr	x17, [x16, #0xfb0]
  6dd528:      	add	x16, x16, #0xfb0
  6dd52c:      	br	x17

00000000006dd530 <ff_free_stream@plt>:
  6dd530:      	adrp	x16, 0x737000
  6dd534:      	ldr	x17, [x16, #0xfb8]
  6dd538:      	add	x16, x16, #0xfb8
  6dd53c:      	br	x17

00000000006dd540 <avformat_stream_group_create@plt>:
  6dd540:      	adrp	x16, 0x737000
  6dd544:      	ldr	x17, [x16, #0xfc0]
  6dd548:      	add	x16, x16, #0xfc0
  6dd54c:      	br	x17

00000000006dd550 <av_iamf_audio_element_alloc@plt>:
  6dd550:      	adrp	x16, 0x737000
  6dd554:      	ldr	x17, [x16, #0xfc8]
  6dd558:      	add	x16, x16, #0xfc8
  6dd55c:      	br	x17

00000000006dd560 <av_iamf_mix_presentation_alloc@plt>:
  6dd560:      	adrp	x16, 0x737000
  6dd564:      	ldr	x17, [x16, #0xfd0]
  6dd568:      	add	x16, x16, #0xfd0
  6dd56c:      	br	x17

00000000006dd570 <ff_free_stream_group@plt>:
  6dd570:      	adrp	x16, 0x737000
  6dd574:      	ldr	x17, [x16, #0xfd8]
  6dd578:      	add	x16, x16, #0xfd8
  6dd57c:      	br	x17

00000000006dd580 <avformat_stream_group_add_stream@plt>:
  6dd580:      	adrp	x16, 0x737000
  6dd584:      	ldr	x17, [x16, #0xfe0]
  6dd588:      	add	x16, x16, #0xfe0
  6dd58c:      	br	x17

00000000006dd590 <av_iamf_audio_element_get_class@plt>:
  6dd590:      	adrp	x16, 0x737000
  6dd594:      	ldr	x17, [x16, #0xfe8]
  6dd598:      	add	x16, x16, #0xfe8
  6dd59c:      	br	x17

00000000006dd5a0 <av_iamf_mix_presentation_get_class@plt>:
  6dd5a0:      	adrp	x16, 0x737000
  6dd5a4:      	ldr	x17, [x16, #0xff0]
  6dd5a8:      	add	x16, x16, #0xff0
  6dd5ac:      	br	x17

00000000006dd5b0 <ff_read_riff_info@plt>:
  6dd5b0:      	adrp	x16, 0x737000
  6dd5b4:      	ldr	x17, [x16, #0xff8]
  6dd5b8:      	add	x16, x16, #0xff8
  6dd5bc:      	br	x17

00000000006dd5c0 <ff_id3v2_parse_priv@plt>:
  6dd5c0:      	adrp	x16, 0x738000
  6dd5c4:      	ldr	x17, [x16]
  6dd5c8:      	add	x16, x16, #0x0
  6dd5cc:      	br	x17

00000000006dd5d0 <avio_get_str@plt>:
  6dd5d0:      	adrp	x16, 0x738000
  6dd5d4:      	ldr	x17, [x16, #0x8]
  6dd5d8:      	add	x16, x16, #0x8
  6dd5dc:      	br	x17

00000000006dd5e0 <ff_pcm_default_packet_size@plt>:
  6dd5e0:      	adrp	x16, 0x738000
  6dd5e4:      	ldr	x17, [x16, #0x10]
  6dd5e8:      	add	x16, x16, #0x10
  6dd5ec:      	br	x17

00000000006dd5f0 <avio_rl24@plt>:
  6dd5f0:      	adrp	x16, 0x738000
  6dd5f4:      	ldr	x17, [x16, #0x18]
  6dd5f8:      	add	x16, x16, #0x18
  6dd5fc:      	br	x17

00000000006dd600 <ff_isom_write_evcc@plt>:
  6dd600:      	adrp	x16, 0x738000
  6dd604:      	ldr	x17, [x16, #0x20]
  6dd608:      	add	x16, x16, #0x20
  6dd60c:      	br	x17

00000000006dd610 <ff_iamf_parse_obu_header@plt>:
  6dd610:      	adrp	x16, 0x738000
  6dd614:      	ldr	x17, [x16, #0x28]
  6dd618:      	add	x16, x16, #0x28
  6dd61c:      	br	x17

00000000006dd620 <ff_iamfdec_read_descriptors@plt>:
  6dd620:      	adrp	x16, 0x738000
  6dd624:      	ldr	x17, [x16, #0x30]
  6dd628:      	add	x16, x16, #0x30
  6dd62c:      	br	x17

00000000006dd630 <ffio_init_context@plt>:
  6dd630:      	adrp	x16, 0x738000
  6dd634:      	ldr	x17, [x16, #0x38]
  6dd638:      	add	x16, x16, #0x38
  6dd63c:      	br	x17

00000000006dd640 <av_iamf_mix_presentation_add_submix@plt>:
  6dd640:      	adrp	x16, 0x738000
  6dd644:      	ldr	x17, [x16, #0x40]
  6dd648:      	add	x16, x16, #0x40
  6dd64c:      	br	x17

00000000006dd650 <av_iamf_submix_add_element@plt>:
  6dd650:      	adrp	x16, 0x738000
  6dd654:      	ldr	x17, [x16, #0x48]
  6dd658:      	add	x16, x16, #0x48
  6dd65c:      	br	x17

00000000006dd660 <ffio_read_leb@plt>:
  6dd660:      	adrp	x16, 0x738000
  6dd664:      	ldr	x17, [x16, #0x50]
  6dd668:      	add	x16, x16, #0x50
  6dd66c:      	br	x17

00000000006dd670 <av_iamf_submix_add_layout@plt>:
  6dd670:      	adrp	x16, 0x738000
  6dd674:      	ldr	x17, [x16, #0x58]
  6dd678:      	add	x16, x16, #0x58
  6dd67c:      	br	x17

00000000006dd680 <av_iamf_audio_element_add_layer@plt>:
  6dd680:      	adrp	x16, 0x738000
  6dd684:      	ldr	x17, [x16, #0x60]
  6dd688:      	add	x16, x16, #0x60
  6dd68c:      	br	x17

00000000006dd690 <av_iamf_param_definition_alloc@plt>:
  6dd690:      	adrp	x16, 0x738000
  6dd694:      	ldr	x17, [x16, #0x68]
  6dd698:      	add	x16, x16, #0x68
  6dd69c:      	br	x17

00000000006dd6a0 <avformat_open_input@plt>:
  6dd6a0:      	adrp	x16, 0x738000
  6dd6a4:      	ldr	x17, [x16, #0x70]
  6dd6a8:      	add	x16, x16, #0x70
  6dd6ac:      	br	x17

00000000006dd6b0 <av_probe_input_buffer2@plt>:
  6dd6b0:      	adrp	x16, 0x738000
  6dd6b4:      	ldr	x17, [x16, #0x78]
  6dd6b8:      	add	x16, x16, #0x78
  6dd6bc:      	br	x17

00000000006dd6c0 <av_probe_input_format2@plt>:
  6dd6c0:      	adrp	x16, 0x738000
  6dd6c4:      	ldr	x17, [x16, #0x80]
  6dd6c8:      	add	x16, x16, #0x80
  6dd6cc:      	br	x17

00000000006dd6d0 <avio_closep@plt>:
  6dd6d0:      	adrp	x16, 0x738000
  6dd6d4:      	ldr	x17, [x16, #0x88]
  6dd6d8:      	add	x16, x16, #0x88
  6dd6dc:      	br	x17

00000000006dd6e0 <avformat_close_input@plt>:
  6dd6e0:      	adrp	x16, 0x738000
  6dd6e4:      	ldr	x17, [x16, #0x90]
  6dd6e8:      	add	x16, x16, #0x90
  6dd6ec:      	br	x17

00000000006dd6f0 <ff_buffer_packet@plt>:
  6dd6f0:      	adrp	x16, 0x738000
  6dd6f4:      	ldr	x17, [x16, #0x98]
  6dd6f8:      	add	x16, x16, #0x98
  6dd6fc:      	br	x17

00000000006dd700 <av_find_program_from_stream@plt>:
  6dd700:      	adrp	x16, 0x738000
  6dd704:      	ldr	x17, [x16, #0xa0]
  6dd708:      	add	x16, x16, #0xa0
  6dd70c:      	br	x17

00000000006dd710 <ff_read_packet@plt>:
  6dd710:      	adrp	x16, 0x738000
  6dd714:      	ldr	x17, [x16, #0xa8]
  6dd718:      	add	x16, x16, #0xa8
  6dd71c:      	br	x17

00000000006dd720 <av_probe_input_format3@plt>:
  6dd720:      	adrp	x16, 0x738000
  6dd724:      	ldr	x17, [x16, #0xb0]
  6dd728:      	add	x16, x16, #0xb0
  6dd72c:      	br	x17

00000000006dd730 <av_compare_mod@plt>:
  6dd730:      	adrp	x16, 0x738000
  6dd734:      	ldr	x17, [x16, #0xb8]
  6dd738:      	add	x16, x16, #0xb8
  6dd73c:      	br	x17

00000000006dd740 <av_opt_get_dict_val@plt>:
  6dd740:      	adrp	x16, 0x738000
  6dd744:      	ldr	x17, [x16, #0xc0]
  6dd748:      	add	x16, x16, #0xc0
  6dd74c:      	br	x17

00000000006dd750 <av_opt_set_dict_val@plt>:
  6dd750:      	adrp	x16, 0x738000
  6dd754:      	ldr	x17, [x16, #0xc8]
  6dd758:      	add	x16, x16, #0xc8
  6dd75c:      	br	x17

00000000006dd760 <ff_rfps_add_frame@plt>:
  6dd760:      	adrp	x16, 0x738000
  6dd764:      	ldr	x17, [x16, #0xd0]
  6dd768:      	add	x16, x16, #0xd0
  6dd76c:      	br	x17

00000000006dd770 <ff_rfps_calculate@plt>:
  6dd770:      	adrp	x16, 0x738000
  6dd774:      	ldr	x17, [x16, #0xd8]
  6dd778:      	add	x16, x16, #0xd8
  6dd77c:      	br	x17

00000000006dd780 <avformat_find_stream_info@plt>:
  6dd780:      	adrp	x16, 0x738000
  6dd784:      	ldr	x17, [x16, #0xe0]
  6dd788:      	add	x16, x16, #0xe0
  6dd78c:      	br	x17

00000000006dd790 <av_opt_ptr@plt>:
  6dd790:      	adrp	x16, 0x738000
  6dd794:      	ldr	x17, [x16, #0xe8]
  6dd798:      	add	x16, x16, #0xe8
  6dd79c:      	br	x17

00000000006dd7a0 <qsort@plt>:
  6dd7a0:      	adrp	x16, 0x738000
  6dd7a4:      	ldr	x17, [x16, #0xf0]
  6dd7a8:      	add	x16, x16, #0xf0
  6dd7ac:      	br	x17

00000000006dd7b0 <ff_find_decoder@plt>:
  6dd7b0:      	adrp	x16, 0x738000
  6dd7b4:      	ldr	x17, [x16, #0xf8]
  6dd7b8:      	add	x16, x16, #0xf8
  6dd7bc:      	br	x17

00000000006dd7c0 <av_add_stable@plt>:
  6dd7c0:      	adrp	x16, 0x738000
  6dd7c4:      	ldr	x17, [x16, #0x100]
  6dd7c8:      	add	x16, x16, #0x100
  6dd7cc:      	br	x17

00000000006dd7d0 <ff_parse_specific_params@plt>:
  6dd7d0:      	adrp	x16, 0x738000
  6dd7d4:      	ldr	x17, [x16, #0x108]
  6dd7d8:      	add	x16, x16, #0x108
  6dd7dc:      	br	x17

00000000006dd7e0 <ff_riff_write_info_tag@plt>:
  6dd7e0:      	adrp	x16, 0x738000
  6dd7e4:      	ldr	x17, [x16, #0x110]
  6dd7e8:      	add	x16, x16, #0x110
  6dd7ec:      	br	x17

00000000006dd7f0 <ff_check_h264_startcode@plt>:
  6dd7f0:      	adrp	x16, 0x738000
  6dd7f4:      	ldr	x17, [x16, #0x118]
  6dd7f8:      	add	x16, x16, #0x118
  6dd7fc:      	br	x17

00000000006dd800 <ff_get_packet_palette@plt>:
  6dd800:      	adrp	x16, 0x738000
  6dd804:      	ldr	x17, [x16, #0x120]
  6dd808:      	add	x16, x16, #0x120
  6dd80c:      	br	x17

00000000006dd810 <ff_reshuffle_raw_rgb@plt>:
  6dd810:      	adrp	x16, 0x738000
  6dd814:      	ldr	x17, [x16, #0x128]
  6dd818:      	add	x16, x16, #0x128
  6dd81c:      	br	x17

00000000006dd820 <ff_id3v2_start@plt>:
  6dd820:      	adrp	x16, 0x738000
  6dd824:      	ldr	x17, [x16, #0x130]
  6dd828:      	add	x16, x16, #0x130
  6dd82c:      	br	x17

00000000006dd830 <ff_id3v2_write_metadata@plt>:
  6dd830:      	adrp	x16, 0x738000
  6dd834:      	ldr	x17, [x16, #0x138]
  6dd838:      	add	x16, x16, #0x138
  6dd83c:      	br	x17

00000000006dd840 <ff_id3v2_finish@plt>:
  6dd840:      	adrp	x16, 0x738000
  6dd844:      	ldr	x17, [x16, #0x140]
  6dd848:      	add	x16, x16, #0x140
  6dd84c:      	br	x17

00000000006dd850 <ff_id3v2_write_apic@plt>:
  6dd850:      	adrp	x16, 0x738000
  6dd854:      	ldr	x17, [x16, #0x148]
  6dd858:      	add	x16, x16, #0x148
  6dd85c:      	br	x17

00000000006dd860 <ff_guess_image2_codec@plt>:
  6dd860:      	adrp	x16, 0x738000
  6dd864:      	ldr	x17, [x16, #0x150]
  6dd868:      	add	x16, x16, #0x150
  6dd86c:      	br	x17

00000000006dd870 <av_gettime_relative@plt>:
  6dd870:      	adrp	x16, 0x738000
  6dd874:      	ldr	x17, [x16, #0x158]
  6dd878:      	add	x16, x16, #0x158
  6dd87c:      	br	x17

00000000006dd880 <av_usleep@plt>:
  6dd880:      	adrp	x16, 0x738000
  6dd884:      	ldr	x17, [x16, #0x160]
  6dd888:      	add	x16, x16, #0x160
  6dd88c:      	br	x17

00000000006dd890 <ff_is_multicast_address@plt>:
  6dd890:      	adrp	x16, 0x738000
  6dd894:      	ldr	x17, [x16, #0x168]
  6dd898:      	add	x16, x16, #0x168
  6dd89c:      	br	x17

00000000006dd8a0 <socket@plt>:
  6dd8a0:      	adrp	x16, 0x738000
  6dd8a4:      	ldr	x17, [x16, #0x170]
  6dd8a8:      	add	x16, x16, #0x170
  6dd8ac:      	br	x17

00000000006dd8b0 <listen@plt>:
  6dd8b0:      	adrp	x16, 0x738000
  6dd8b4:      	ldr	x17, [x16, #0x178]
  6dd8b8:      	add	x16, x16, #0x178
  6dd8bc:      	br	x17

00000000006dd8c0 <accept@plt>:
  6dd8c0:      	adrp	x16, 0x738000
  6dd8c4:      	ldr	x17, [x16, #0x180]
  6dd8c8:      	add	x16, x16, #0x180
  6dd8cc:      	br	x17

00000000006dd8d0 <ff_listen_connect@plt>:
  6dd8d0:      	adrp	x16, 0x738000
  6dd8d4:      	ldr	x17, [x16, #0x188]
  6dd8d8:      	add	x16, x16, #0x188
  6dd8dc:      	br	x17

00000000006dd8e0 <connect@plt>:
  6dd8e0:      	adrp	x16, 0x738000
  6dd8e4:      	ldr	x17, [x16, #0x190]
  6dd8e8:      	add	x16, x16, #0x190
  6dd8ec:      	br	x17

00000000006dd8f0 <getnameinfo@plt>:
  6dd8f0:      	adrp	x16, 0x738000
  6dd8f4:      	ldr	x17, [x16, #0x198]
  6dd8f8:      	add	x16, x16, #0x198
  6dd8fc:      	br	x17

00000000006dd900 <ff_hls_senc_read_audio_setup_info@plt>:
  6dd900:      	adrp	x16, 0x738000
  6dd904:      	ldr	x17, [x16, #0x1a0]
  6dd908:      	add	x16, x16, #0x1a0
  6dd90c:      	br	x17

00000000006dd910 <ff_hls_senc_parse_audio_setup_info@plt>:
  6dd910:      	adrp	x16, 0x738000
  6dd914:      	ldr	x17, [x16, #0x1a8]
  6dd918:      	add	x16, x16, #0x1a8
  6dd91c:      	br	x17

00000000006dd920 <ff_hls_senc_decrypt_frame@plt>:
  6dd920:      	adrp	x16, 0x738000
  6dd924:      	ldr	x17, [x16, #0x1b0]
  6dd928:      	add	x16, x16, #0x1b0
  6dd92c:      	br	x17

00000000006dd930 <av_aes_crypt@plt>:
  6dd930:      	adrp	x16, 0x738000
  6dd934:      	ldr	x17, [x16, #0x1b8]
  6dd938:      	add	x16, x16, #0x1b8
  6dd93c:      	br	x17

00000000006dd940 <av_aes_init@plt>:
  6dd940:      	adrp	x16, 0x738000
  6dd944:      	ldr	x17, [x16, #0x1c0]
  6dd948:      	add	x16, x16, #0x1c0
  6dd94c:      	br	x17

00000000006dd950 <ff_url_decompose@plt>:
  6dd950:      	adrp	x16, 0x738000
  6dd954:      	ldr	x17, [x16, #0x1c8]
  6dd958:      	add	x16, x16, #0x1c8
  6dd95c:      	br	x17

00000000006dd960 <ff_make_absolute_url2@plt>:
  6dd960:      	adrp	x16, 0x738000
  6dd964:      	ldr	x17, [x16, #0x1d0]
  6dd968:      	add	x16, x16, #0x1d0
  6dd96c:      	br	x17

00000000006dd970 <av_dynarray_add@plt>:
  6dd970:      	adrp	x16, 0x738000
  6dd974:      	ldr	x17, [x16, #0x1d8]
  6dd978:      	add	x16, x16, #0x1d8
  6dd97c:      	br	x17

00000000006dd980 <atof@plt>:
  6dd980:      	adrp	x16, 0x738000
  6dd984:      	ldr	x17, [x16, #0x1e0]
  6dd988:      	add	x16, x16, #0x1e0
  6dd98c:      	br	x17

00000000006dd990 <ff_get_chomp_line@plt>:
  6dd990:      	adrp	x16, 0x738000
  6dd994:      	ldr	x17, [x16, #0x1e8]
  6dd998:      	add	x16, x16, #0x1e8
  6dd99c:      	br	x17

00000000006dd9a0 <ff_codec_guid_get_id@plt>:
  6dd9a0:      	adrp	x16, 0x738000
  6dd9a4:      	ldr	x17, [x16, #0x1f0]
  6dd9a8:      	add	x16, x16, #0x1f0
  6dd9ac:      	br	x17

00000000006dd9b0 <ff_wav_codec_get_id@plt>:
  6dd9b0:      	adrp	x16, 0x738000
  6dd9b4:      	ldr	x17, [x16, #0x1f8]
  6dd9b8:      	add	x16, x16, #0x1f8
  6dd9bc:      	br	x17

00000000006dd9c0 <ff_get_bmp_header@plt>:
  6dd9c0:      	adrp	x16, 0x738000
  6dd9c4:      	ldr	x17, [x16, #0x200]
  6dd9c8:      	add	x16, x16, #0x200
  6dd9cc:      	br	x17

00000000006dd9d0 <ff_iamf_read_packet@plt>:
  6dd9d0:      	adrp	x16, 0x738000
  6dd9d4:      	ldr	x17, [x16, #0x208]
  6dd9d8:      	add	x16, x16, #0x208
  6dd9dc:      	br	x17

00000000006dd9e0 <ff_iamf_read_deinit@plt>:
  6dd9e0:      	adrp	x16, 0x738000
  6dd9e4:      	ldr	x17, [x16, #0x210]
  6dd9e8:      	add	x16, x16, #0x210
  6dd9ec:      	br	x17

00000000006dd9f0 <ff_mov_get_channel_layout_tag@plt>:
  6dd9f0:      	adrp	x16, 0x738000
  6dd9f4:      	ldr	x17, [x16, #0x218]
  6dd9f8:      	add	x16, x16, #0x218
  6dd9fc:      	br	x17

00000000006dda00 <av_channel_layout_channel_from_index@plt>:
  6dda00:      	adrp	x16, 0x738000
  6dda04:      	ldr	x17, [x16, #0x220]
  6dda08:      	add	x16, x16, #0x220
  6dda0c:      	br	x17

00000000006dda10 <ff_mov_get_channel_config_from_layout@plt>:
  6dda10:      	adrp	x16, 0x738000
  6dda14:      	ldr	x17, [x16, #0x228]
  6dda18:      	add	x16, x16, #0x228
  6dda1c:      	br	x17

00000000006dda20 <ff_mov_get_channel_layout_from_config@plt>:
  6dda20:      	adrp	x16, 0x738000
  6dda24:      	ldr	x17, [x16, #0x230]
  6dda28:      	add	x16, x16, #0x230
  6dda2c:      	br	x17

00000000006dda30 <ff_mov_get_channel_positions_from_layout@plt>:
  6dda30:      	adrp	x16, 0x738000
  6dda34:      	ldr	x17, [x16, #0x238]
  6dda38:      	add	x16, x16, #0x238
  6dda3c:      	br	x17

00000000006dda40 <ff_mov_read_chnl@plt>:
  6dda40:      	adrp	x16, 0x738000
  6dda44:      	ldr	x17, [x16, #0x240]
  6dda48:      	add	x16, x16, #0x240
  6dda4c:      	br	x17

00000000006dda50 <ff_crc04C11DB7_update@plt>:
  6dda50:      	adrp	x16, 0x738000
  6dda54:      	ldr	x17, [x16, #0x248]
  6dda58:      	add	x16, x16, #0x248
  6dda5c:      	br	x17

00000000006dda60 <ffio_get_checksum@plt>:
  6dda60:      	adrp	x16, 0x738000
  6dda64:      	ldr	x17, [x16, #0x250]
  6dda68:      	add	x16, x16, #0x250
  6dda6c:      	br	x17

00000000006dda70 <ffio_init_checksum@plt>:
  6dda70:      	adrp	x16, 0x738000
  6dda74:      	ldr	x17, [x16, #0x258]
  6dda78:      	add	x16, x16, #0x258
  6dda7c:      	br	x17

00000000006dda80 <ffio_read_indirect@plt>:
  6dda80:      	adrp	x16, 0x738000
  6dda84:      	ldr	x17, [x16, #0x260]
  6dda88:      	add	x16, x16, #0x260
  6dda8c:      	br	x17

00000000006dda90 <ff_get_line@plt>:
  6dda90:      	adrp	x16, 0x738000
  6dda94:      	ldr	x17, [x16, #0x268]
  6dda98:      	add	x16, x16, #0x268
  6dda9c:      	br	x17

00000000006ddaa0 <ff_read_string_to_bprint_overwrite@plt>:
  6ddaa0:      	adrp	x16, 0x738000
  6ddaa4:      	ldr	x17, [x16, #0x270]
  6ddaa8:      	add	x16, x16, #0x270
  6ddaac:      	br	x17

00000000006ddab0 <avio_get_str16be@plt>:
  6ddab0:      	adrp	x16, 0x738000
  6ddab4:      	ldr	x17, [x16, #0x278]
  6ddab8:      	add	x16, x16, #0x278
  6ddabc:      	br	x17

00000000006ddac0 <ffio_copy_url_options@plt>:
  6ddac0:      	adrp	x16, 0x738000
  6ddac4:      	ldr	x17, [x16, #0x280]
  6ddac8:      	add	x16, x16, #0x280
  6ddacc:      	br	x17

00000000006ddad0 <ffio_rewind_with_probe_data@plt>:
  6ddad0:      	adrp	x16, 0x738000
  6ddad4:      	ldr	x17, [x16, #0x288]
  6ddad8:      	add	x16, x16, #0x288
  6ddadc:      	br	x17

00000000006ddae0 <avio_vprintf@plt>:
  6ddae0:      	adrp	x16, 0x738000
  6ddae4:      	ldr	x17, [x16, #0x290]
  6ddae8:      	add	x16, x16, #0x290
  6ddaec:      	br	x17

00000000006ddaf0 <av_vbprintf@plt>:
  6ddaf0:      	adrp	x16, 0x738000
  6ddaf4:      	ldr	x17, [x16, #0x298]
  6ddaf8:      	add	x16, x16, #0x298
  6ddafc:      	br	x17

00000000006ddb00 <ffio_open_null_buf@plt>:
  6ddb00:      	adrp	x16, 0x738000
  6ddb04:      	ldr	x17, [x16, #0x2a0]
  6ddb08:      	add	x16, x16, #0x2a0
  6ddb0c:      	br	x17

00000000006ddb10 <ffio_close_null_buf@plt>:
  6ddb10:      	adrp	x16, 0x738000
  6ddb14:      	ldr	x17, [x16, #0x2a8]
  6ddb18:      	add	x16, x16, #0x2a8
  6ddb1c:      	br	x17

00000000006ddb20 <ff_get_codec_guid@plt>:
  6ddb20:      	adrp	x16, 0x738000
  6ddb24:      	ldr	x17, [x16, #0x2b0]
  6ddb28:      	add	x16, x16, #0x2b0
  6ddb2c:      	br	x17

00000000006ddb30 <ff_mov_read_esds@plt>:
  6ddb30:      	adrp	x16, 0x738000
  6ddb34:      	ldr	x17, [x16, #0x2b8]
  6ddb38:      	add	x16, x16, #0x2b8
  6ddb3c:      	br	x17

00000000006ddb40 <ffio_fdopen@plt>:
  6ddb40:      	adrp	x16, 0x738000
  6ddb44:      	ldr	x17, [x16, #0x2c0]
  6ddb48:      	add	x16, x16, #0x2c0
  6ddb4c:      	br	x17

00000000006ddb50 <ff_remove_stream_group@plt>:
  6ddb50:      	adrp	x16, 0x738000
  6ddb54:      	ldr	x17, [x16, #0x2c8]
  6ddb58:      	add	x16, x16, #0x2c8
  6ddb5c:      	br	x17

00000000006ddb60 <av_stream_add_side_data@plt>:
  6ddb60:      	adrp	x16, 0x738000
  6ddb64:      	ldr	x17, [x16, #0x2d0]
  6ddb68:      	add	x16, x16, #0x2d0
  6ddb6c:      	br	x17

00000000006ddb70 <av_new_program@plt>:
  6ddb70:      	adrp	x16, 0x738000
  6ddb74:      	ldr	x17, [x16, #0x2d8]
  6ddb78:      	add	x16, x16, #0x2d8
  6ddb7c:      	br	x17

00000000006ddb80 <av_program_add_stream_index@plt>:
  6ddb80:      	adrp	x16, 0x738000
  6ddb84:      	ldr	x17, [x16, #0x2e0]
  6ddb88:      	add	x16, x16, #0x2e0
  6ddb8c:      	br	x17

00000000006ddb90 <ff_copy_whiteblacklists@plt>:
  6ddb90:      	adrp	x16, 0x738000
  6ddb94:      	ldr	x17, [x16, #0x2e8]
  6ddb98:      	add	x16, x16, #0x2e8
  6ddb9c:      	br	x17

00000000006ddba0 <ff_sdp_write_media@plt>:
  6ddba0:      	adrp	x16, 0x738000
  6ddba4:      	ldr	x17, [x16, #0x2f0]
  6ddba8:      	add	x16, x16, #0x2f0
  6ddbac:      	br	x17

00000000006ddbb0 <ffio_geturlcontext@plt>:
  6ddbb0:      	adrp	x16, 0x738000
  6ddbb4:      	ldr	x17, [x16, #0x2f8]
  6ddbb8:      	add	x16, x16, #0x2f8
  6ddbbc:      	br	x17

00000000006ddbc0 <ffurl_connect@plt>:
  6ddbc0:      	adrp	x16, 0x738000
  6ddbc4:      	ldr	x17, [x16, #0x300]
  6ddbc8:      	add	x16, x16, #0x300
  6ddbcc:      	br	x17

00000000006ddbd0 <strcpy@plt>:
  6ddbd0:      	adrp	x16, 0x738000
  6ddbd4:      	ldr	x17, [x16, #0x308]
  6ddbd8:      	add	x16, x16, #0x308
  6ddbdc:      	br	x17

00000000006ddbe0 <avio_open2@plt>:
  6ddbe0:      	adrp	x16, 0x738000
  6ddbe4:      	ldr	x17, [x16, #0x310]
  6ddbe8:      	add	x16, x16, #0x310
  6ddbec:      	br	x17

00000000006ddbf0 <avio_check@plt>:
  6ddbf0:      	adrp	x16, 0x738000
  6ddbf4:      	ldr	x17, [x16, #0x318]
  6ddbf8:      	add	x16, x16, #0x318
  6ddbfc:      	br	x17

00000000006ddc00 <ffurl_move@plt>:
  6ddc00:      	adrp	x16, 0x738000
  6ddc04:      	ldr	x17, [x16, #0x320]
  6ddc08:      	add	x16, x16, #0x320
  6ddc0c:      	br	x17

00000000006ddc10 <avio_free_directory_entry@plt>:
  6ddc10:      	adrp	x16, 0x738000
  6ddc14:      	ldr	x17, [x16, #0x328]
  6ddc18:      	add	x16, x16, #0x328
  6ddc1c:      	br	x17

00000000006ddc20 <ff_av1_filter_obus_buf@plt>:
  6ddc20:      	adrp	x16, 0x738000
  6ddc24:      	ldr	x17, [x16, #0x330]
  6ddc28:      	add	x16, x16, #0x330
  6ddc2c:      	br	x17

00000000006ddc30 <av_channel_layout_from_string@plt>:
  6ddc30:      	adrp	x16, 0x738000
  6ddc34:      	ldr	x17, [x16, #0x338]
  6ddc38:      	add	x16, x16, #0x338
  6ddc3c:      	br	x17

00000000006ddc40 <av_channel_layout_ambisonic_order@plt>:
  6ddc40:      	adrp	x16, 0x738000
  6ddc44:      	ldr	x17, [x16, #0x340]
  6ddc48:      	add	x16, x16, #0x340
  6ddc4c:      	br	x17

00000000006ddc50 <av_sub_q@plt>:
  6ddc50:      	adrp	x16, 0x738000
  6ddc54:      	ldr	x17, [x16, #0x348]
  6ddc58:      	add	x16, x16, #0x348
  6ddc5c:      	br	x17

00000000006ddc60 <ff_ip_resolve_host@plt>:
  6ddc60:      	adrp	x16, 0x738000
  6ddc64:      	ldr	x17, [x16, #0x350]
  6ddc68:      	add	x16, x16, #0x350
  6ddc6c:      	br	x17

00000000006ddc70 <av_dynarray2_add@plt>:
  6ddc70:      	adrp	x16, 0x738000
  6ddc74:      	ldr	x17, [x16, #0x358]
  6ddc78:      	add	x16, x16, #0x358
  6ddc7c:      	br	x17

00000000006ddc80 <ff_parse_mpeg2_descriptor@plt>:
  6ddc80:      	adrp	x16, 0x738000
  6ddc84:      	ldr	x17, [x16, #0x360]
  6ddc88:      	add	x16, x16, #0x360
  6ddc8c:      	br	x17

00000000006ddc90 <ff_match_url_ext@plt>:
  6ddc90:      	adrp	x16, 0x738000
  6ddc94:      	ldr	x17, [x16, #0x368]
  6ddc98:      	add	x16, x16, #0x368
  6ddc9c:      	br	x17

00000000006ddca0 <av_find_input_format@plt>:
  6ddca0:      	adrp	x16, 0x738000
  6ddca4:      	ldr	x17, [x16, #0x370]
  6ddca8:      	add	x16, x16, #0x370
  6ddcac:      	br	x17

00000000006ddcb0 <av_probe_input_buffer@plt>:
  6ddcb0:      	adrp	x16, 0x738000
  6ddcb4:      	ldr	x17, [x16, #0x378]
  6ddcb8:      	add	x16, x16, #0x378
  6ddcbc:      	br	x17

00000000006ddcc0 <ff_isom_get_vpcc_features@plt>:
  6ddcc0:      	adrp	x16, 0x738000
  6ddcc4:      	ldr	x17, [x16, #0x380]
  6ddcc8:      	add	x16, x16, #0x380
  6ddccc:      	br	x17

00000000006ddcd0 <av_get_pix_fmt@plt>:
  6ddcd0:      	adrp	x16, 0x738000
  6ddcd4:      	ldr	x17, [x16, #0x388]
  6ddcd8:      	add	x16, x16, #0x388
  6ddcdc:      	br	x17

00000000006ddce0 <stat@plt>:
  6ddce0:      	adrp	x16, 0x738000
  6ddce4:      	ldr	x17, [x16, #0x390]
  6ddce8:      	add	x16, x16, #0x390
  6ddcec:      	br	x17

00000000006ddcf0 <ff_mov_read_stsd_entries@plt>:
  6ddcf0:      	adrp	x16, 0x738000
  6ddcf4:      	ldr	x17, [x16, #0x398]
  6ddcf8:      	add	x16, x16, #0x398
  6ddcfc:      	br	x17

00000000006ddd00 <av_timecode_init@plt>:
  6ddd00:      	adrp	x16, 0x738000
  6ddd04:      	ldr	x17, [x16, #0x3a0]
  6ddd08:      	add	x16, x16, #0x3a0
  6ddd0c:      	br	x17

00000000006ddd10 <av_aes_ctr_set_full_iv@plt>:
  6ddd10:      	adrp	x16, 0x738000
  6ddd14:      	ldr	x17, [x16, #0x3a8]
  6ddd18:      	add	x16, x16, #0x3a8
  6ddd1c:      	br	x17

00000000006ddd20 <av_encryption_info_add_side_data@plt>:
  6ddd20:      	adrp	x16, 0x738000
  6ddd24:      	ldr	x17, [x16, #0x3b0]
  6ddd28:      	add	x16, x16, #0x3b0
  6ddd2c:      	br	x17

00000000006ddd30 <av_aes_alloc@plt>:
  6ddd30:      	adrp	x16, 0x738000
  6ddd34:      	ldr	x17, [x16, #0x3b8]
  6ddd38:      	add	x16, x16, #0x3b8
  6ddd3c:      	br	x17

00000000006ddd40 <av_sha_alloc@plt>:
  6ddd40:      	adrp	x16, 0x738000
  6ddd44:      	ldr	x17, [x16, #0x3c0]
  6ddd48:      	add	x16, x16, #0x3c0
  6ddd4c:      	br	x17

00000000006ddd50 <av_sha_update@plt>:
  6ddd50:      	adrp	x16, 0x738000
  6ddd54:      	ldr	x17, [x16, #0x3c8]
  6ddd58:      	add	x16, x16, #0x3c8
  6ddd5c:      	br	x17

00000000006ddd60 <av_sha_init@plt>:
  6ddd60:      	adrp	x16, 0x738000
  6ddd64:      	ldr	x17, [x16, #0x3d0]
  6ddd68:      	add	x16, x16, #0x3d0
  6ddd6c:      	br	x17

00000000006ddd70 <av_add_q@plt>:
  6ddd70:      	adrp	x16, 0x738000
  6ddd74:      	ldr	x17, [x16, #0x3d8]
  6ddd78:      	add	x16, x16, #0x3d8
  6ddd7c:      	br	x17

00000000006ddd80 <av_encryption_info_free@plt>:
  6ddd80:      	adrp	x16, 0x738000
  6ddd84:      	ldr	x17, [x16, #0x3e0]
  6ddd88:      	add	x16, x16, #0x3e0
  6ddd8c:      	br	x17

00000000006ddd90 <av_encryption_init_info_alloc@plt>:
  6ddd90:      	adrp	x16, 0x738000
  6ddd94:      	ldr	x17, [x16, #0x3e8]
  6ddd98:      	add	x16, x16, #0x3e8
  6ddd9c:      	br	x17

00000000006ddda0 <av_encryption_init_info_get_side_data@plt>:
  6ddda0:      	adrp	x16, 0x738000
  6ddda4:      	ldr	x17, [x16, #0x3f0]
  6ddda8:      	add	x16, x16, #0x3f0
  6dddac:      	br	x17

00000000006dddb0 <av_encryption_init_info_free@plt>:
  6dddb0:      	adrp	x16, 0x738000
  6dddb4:      	ldr	x17, [x16, #0x3f8]
  6dddb8:      	add	x16, x16, #0x3f8
  6dddbc:      	br	x17

00000000006dddc0 <av_encryption_init_info_add_side_data@plt>:
  6dddc0:      	adrp	x16, 0x738000
  6dddc4:      	ldr	x17, [x16, #0x400]
  6dddc8:      	add	x16, x16, #0x400
  6dddcc:      	br	x17

00000000006dddd0 <av_encryption_info_clone@plt>:
  6dddd0:      	adrp	x16, 0x738000
  6dddd4:      	ldr	x17, [x16, #0x408]
  6dddd8:      	add	x16, x16, #0x408
  6ddddc:      	br	x17

00000000006ddde0 <av_encryption_info_alloc@plt>:
  6ddde0:      	adrp	x16, 0x738000
  6ddde4:      	ldr	x17, [x16, #0x410]
  6ddde8:      	add	x16, x16, #0x410
  6dddec:      	br	x17

00000000006dddf0 <av_sha_final@plt>:
  6dddf0:      	adrp	x16, 0x738000
  6dddf4:      	ldr	x17, [x16, #0x418]
  6dddf8:      	add	x16, x16, #0x418
  6dddfc:      	br	x17

00000000006dde00 <getsockname@plt>:
  6dde00:      	adrp	x16, 0x738000
  6dde04:      	ldr	x17, [x16, #0x420]
  6dde08:      	add	x16, x16, #0x420
  6dde0c:      	br	x17

00000000006dde10 <av_int2i@plt>:
  6dde10:      	adrp	x16, 0x738000
  6dde14:      	ldr	x17, [x16, #0x428]
  6dde18:      	add	x16, x16, #0x428
  6dde1c:      	br	x17

00000000006dde20 <av_mul_i@plt>:
  6dde20:      	adrp	x16, 0x738000
  6dde24:      	ldr	x17, [x16, #0x430]
  6dde28:      	add	x16, x16, #0x430
  6dde2c:      	br	x17

00000000006dde30 <av_shr_i@plt>:
  6dde30:      	adrp	x16, 0x738000
  6dde34:      	ldr	x17, [x16, #0x438]
  6dde38:      	add	x16, x16, #0x438
  6dde3c:      	br	x17

00000000006dde40 <av_add_i@plt>:
  6dde40:      	adrp	x16, 0x738000
  6dde44:      	ldr	x17, [x16, #0x440]
  6dde48:      	add	x16, x16, #0x440
  6dde4c:      	br	x17

00000000006dde50 <av_div_i@plt>:
  6dde50:      	adrp	x16, 0x738000
  6dde54:      	ldr	x17, [x16, #0x448]
  6dde58:      	add	x16, x16, #0x448
  6dde5c:      	br	x17

00000000006dde60 <av_cmp_i@plt>:
  6dde60:      	adrp	x16, 0x738000
  6dde64:      	ldr	x17, [x16, #0x450]
  6dde68:      	add	x16, x16, #0x450
  6dde6c:      	br	x17

00000000006dde70 <av_i2int@plt>:
  6dde70:      	adrp	x16, 0x738000
  6dde74:      	ldr	x17, [x16, #0x458]
  6dde78:      	add	x16, x16, #0x458
  6dde7c:      	br	x17

00000000006dde80 <strtof@plt>:
  6dde80:      	adrp	x16, 0x738000
  6dde84:      	ldr	x17, [x16, #0x460]
  6dde88:      	add	x16, x16, #0x460
  6dde8c:      	br	x17

00000000006dde90 <gettimeofday@plt>:
  6dde90:      	adrp	x16, 0x738000
  6dde94:      	ldr	x17, [x16, #0x468]
  6dde98:      	add	x16, x16, #0x468
  6dde9c:      	br	x17

00000000006ddea0 <clock_gettime@plt>:
  6ddea0:      	adrp	x16, 0x738000
  6ddea4:      	ldr	x17, [x16, #0x470]
  6ddea8:      	add	x16, x16, #0x470
  6ddeac:      	br	x17

00000000006ddeb0 <nanosleep@plt>:
  6ddeb0:      	adrp	x16, 0x738000
  6ddeb4:      	ldr	x17, [x16, #0x478]
  6ddeb8:      	add	x16, x16, #0x478
  6ddebc:      	br	x17

00000000006ddec0 <av_hwdevice_ctx_alloc@plt>:
  6ddec0:      	adrp	x16, 0x738000
  6ddec4:      	ldr	x17, [x16, #0x480]
  6ddec8:      	add	x16, x16, #0x480
  6ddecc:      	br	x17

00000000006dded0 <av_hwframe_transfer_data@plt>:
  6dded0:      	adrp	x16, 0x738000
  6dded4:      	ldr	x17, [x16, #0x488]
  6dded8:      	add	x16, x16, #0x488
  6ddedc:      	br	x17

00000000006ddee0 <av_hwframe_map@plt>:
  6ddee0:      	adrp	x16, 0x738000
  6ddee4:      	ldr	x17, [x16, #0x490]
  6ddee8:      	add	x16, x16, #0x490
  6ddeec:      	br	x17

00000000006ddef0 <av_hwframe_constraints_free@plt>:
  6ddef0:      	adrp	x16, 0x738000
  6ddef4:      	ldr	x17, [x16, #0x498]
  6ddef8:      	add	x16, x16, #0x498
  6ddefc:      	br	x17

00000000006ddf00 <av_hwdevice_ctx_create_derived_opts@plt>:
  6ddf00:      	adrp	x16, 0x738000
  6ddf04:      	ldr	x17, [x16, #0x4a0]
  6ddf08:      	add	x16, x16, #0x4a0
  6ddf0c:      	br	x17

00000000006ddf10 <strerror_r@plt>:
  6ddf10:      	adrp	x16, 0x738000
  6ddf14:      	ldr	x17, [x16, #0x4a8]
  6ddf18:      	add	x16, x16, #0x4a8
  6ddf1c:      	br	x17

00000000006ddf20 <av_detection_bbox_alloc@plt>:
  6ddf20:      	adrp	x16, 0x738000
  6ddf24:      	ldr	x17, [x16, #0x4b0]
  6ddf28:      	add	x16, x16, #0x4b0
  6ddf2c:      	br	x17

00000000006ddf30 <av_fifo_drain2@plt>:
  6ddf30:      	adrp	x16, 0x738000
  6ddf34:      	ldr	x17, [x16, #0x4b8]
  6ddf38:      	add	x16, x16, #0x4b8
  6ddf3c:      	br	x17

00000000006ddf40 <av_fifo_peek@plt>:
  6ddf40:      	adrp	x16, 0x738000
  6ddf44:      	ldr	x17, [x16, #0x4c0]
  6ddf48:      	add	x16, x16, #0x4c0
  6ddf4c:      	br	x17

00000000006ddf50 <av_fifo_reset2@plt>:
  6ddf50:      	adrp	x16, 0x738000
  6ddf54:      	ldr	x17, [x16, #0x4c8]
  6ddf58:      	add	x16, x16, #0x4c8
  6ddf5c:      	br	x17

00000000006ddf60 <av_blowfish_crypt_ecb@plt>:
  6ddf60:      	adrp	x16, 0x738000
  6ddf64:      	ldr	x17, [x16, #0x4d0]
  6ddf68:      	add	x16, x16, #0x4d0
  6ddf6c:      	br	x17

00000000006ddf70 <av_sscanf@plt>:
  6ddf70:      	adrp	x16, 0x738000
  6ddf74:      	ldr	x17, [x16, #0x4d8]
  6ddf78:      	add	x16, x16, #0x4d8
  6ddf7c:      	br	x17

00000000006ddf80 <av_murmur3_alloc@plt>:
  6ddf80:      	adrp	x16, 0x738000
  6ddf84:      	ldr	x17, [x16, #0x4e0]
  6ddf88:      	add	x16, x16, #0x4e0
  6ddf8c:      	br	x17

00000000006ddf90 <av_murmur3_init@plt>:
  6ddf90:      	adrp	x16, 0x738000
  6ddf94:      	ldr	x17, [x16, #0x4e8]
  6ddf98:      	add	x16, x16, #0x4e8
  6ddf9c:      	br	x17

00000000006ddfa0 <av_murmur3_update@plt>:
  6ddfa0:      	adrp	x16, 0x738000
  6ddfa4:      	ldr	x17, [x16, #0x4f0]
  6ddfa8:      	add	x16, x16, #0x4f0
  6ddfac:      	br	x17

00000000006ddfb0 <av_murmur3_final@plt>:
  6ddfb0:      	adrp	x16, 0x738000
  6ddfb4:      	ldr	x17, [x16, #0x4f8]
  6ddfb8:      	add	x16, x16, #0x4f8
  6ddfbc:      	br	x17

00000000006ddfc0 <av_get_sample_fmt@plt>:
  6ddfc0:      	adrp	x16, 0x738000
  6ddfc4:      	ldr	x17, [x16, #0x500]
  6ddfc8:      	add	x16, x16, #0x500
  6ddfcc:      	br	x17

00000000006ddfd0 <av_get_packed_sample_fmt@plt>:
  6ddfd0:      	adrp	x16, 0x738000
  6ddfd4:      	ldr	x17, [x16, #0x508]
  6ddfd8:      	add	x16, x16, #0x508
  6ddfdc:      	br	x17

00000000006ddfe0 <av_samples_alloc@plt>:
  6ddfe0:      	adrp	x16, 0x738000
  6ddfe4:      	ldr	x17, [x16, #0x510]
  6ddfe8:      	add	x16, x16, #0x510
  6ddfec:      	br	x17

00000000006ddff0 <av_read_image_line2@plt>:
  6ddff0:      	adrp	x16, 0x738000
  6ddff4:      	ldr	x17, [x16, #0x518]
  6ddff8:      	add	x16, x16, #0x518
  6ddffc:      	br	x17

00000000006de000 <av_write_image_line2@plt>:
  6de000:      	adrp	x16, 0x738000
  6de004:      	ldr	x17, [x16, #0x520]
  6de008:      	add	x16, x16, #0x520
  6de00c:      	br	x17

00000000006de010 <av_get_padded_bits_per_pixel@plt>:
  6de010:      	adrp	x16, 0x738000
  6de014:      	ldr	x17, [x16, #0x528]
  6de018:      	add	x16, x16, #0x528
  6de01c:      	br	x17

00000000006de020 <av_pix_fmt_swap_endianness@plt>:
  6de020:      	adrp	x16, 0x738000
  6de024:      	ldr	x17, [x16, #0x530]
  6de028:      	add	x16, x16, #0x530
  6de02c:      	br	x17

00000000006de030 <av_get_pix_fmt_loss@plt>:
  6de030:      	adrp	x16, 0x738000
  6de034:      	ldr	x17, [x16, #0x538]
  6de038:      	add	x16, x16, #0x538
  6de03c:      	br	x17

00000000006de040 <av_uuid_parse@plt>:
  6de040:      	adrp	x16, 0x738000
  6de044:      	ldr	x17, [x16, #0x540]
  6de048:      	add	x16, x16, #0x540
  6de04c:      	br	x17

00000000006de050 <av_uuid_parse_range@plt>:
  6de050:      	adrp	x16, 0x738000
  6de054:      	ldr	x17, [x16, #0x548]
  6de058:      	add	x16, x16, #0x548
  6de05c:      	br	x17

00000000006de060 <av_md5_sum@plt>:
  6de060:      	adrp	x16, 0x738000
  6de064:      	ldr	x17, [x16, #0x550]
  6de068:      	add	x16, x16, #0x550
  6de06c:      	br	x17

00000000006de070 <ff_scalarproduct_double_c@plt>:
  6de070:      	adrp	x16, 0x738000
  6de074:      	ldr	x17, [x16, #0x558]
  6de078:      	add	x16, x16, #0x558
  6de07c:      	br	x17

00000000006de080 <ff_float_dsp_init_aarch64@plt>:
  6de080:      	adrp	x16, 0x738000
  6de084:      	ldr	x17, [x16, #0x560]
  6de088:      	add	x16, x16, #0x560
  6de08c:      	br	x17

00000000006de090 <av_image_fill_pointers@plt>:
  6de090:      	adrp	x16, 0x738000
  6de094:      	ldr	x17, [x16, #0x568]
  6de098:      	add	x16, x16, #0x568
  6de09c:      	br	x17

00000000006de0a0 <av_audio_fifo_realloc@plt>:
  6de0a0:      	adrp	x16, 0x738000
  6de0a4:      	ldr	x17, [x16, #0x570]
  6de0a8:      	add	x16, x16, #0x570
  6de0ac:      	br	x17

00000000006de0b0 <av_audio_fifo_peek_at@plt>:
  6de0b0:      	adrp	x16, 0x738000
  6de0b4:      	ldr	x17, [x16, #0x578]
  6de0b8:      	add	x16, x16, #0x578
  6de0bc:      	br	x17

00000000006de0c0 <ff_tx_init_tabs_float@plt>:
  6de0c0:      	adrp	x16, 0x738000
  6de0c4:      	ldr	x17, [x16, #0x580]
  6de0c8:      	add	x16, x16, #0x580
  6de0cc:      	br	x17

00000000006de0d0 <ff_tx_mdct_gen_exp_float@plt>:
  6de0d0:      	adrp	x16, 0x738000
  6de0d4:      	ldr	x17, [x16, #0x588]
  6de0d8:      	add	x16, x16, #0x588
  6de0dc:      	br	x17

00000000006de0e0 <ff_tx_gen_ptwo_revtab@plt>:
  6de0e0:      	adrp	x16, 0x738000
  6de0e4:      	ldr	x17, [x16, #0x590]
  6de0e8:      	add	x16, x16, #0x590
  6de0ec:      	br	x17

00000000006de0f0 <ff_tx_gen_pfa_input_map@plt>:
  6de0f0:      	adrp	x16, 0x738000
  6de0f4:      	ldr	x17, [x16, #0x598]
  6de0f8:      	add	x16, x16, #0x598
  6de0fc:      	br	x17

00000000006de100 <ff_tx_gen_default_map@plt>:
  6de100:      	adrp	x16, 0x738000
  6de104:      	ldr	x17, [x16, #0x5a0]
  6de108:      	add	x16, x16, #0x5a0
  6de10c:      	br	x17

00000000006de110 <ff_tx_init_subtx@plt>:
  6de110:      	adrp	x16, 0x738000
  6de114:      	ldr	x17, [x16, #0x5a8]
  6de118:      	add	x16, x16, #0x5a8
  6de11c:      	br	x17

00000000006de120 <ff_tx_gen_inplace_map@plt>:
  6de120:      	adrp	x16, 0x738000
  6de124:      	ldr	x17, [x16, #0x5b0]
  6de128:      	add	x16, x16, #0x5b0
  6de12c:      	br	x17

00000000006de130 <ff_tx_decompose_length@plt>:
  6de130:      	adrp	x16, 0x738000
  6de134:      	ldr	x17, [x16, #0x5b8]
  6de138:      	add	x16, x16, #0x5b8
  6de13c:      	br	x17

00000000006de140 <ff_tx_clear_ctx@plt>:
  6de140:      	adrp	x16, 0x738000
  6de144:      	ldr	x17, [x16, #0x5c0]
  6de148:      	add	x16, x16, #0x5c0
  6de14c:      	br	x17

00000000006de150 <ff_tx_gen_compound_mapping@plt>:
  6de150:      	adrp	x16, 0x738000
  6de154:      	ldr	x17, [x16, #0x5c8]
  6de158:      	add	x16, x16, #0x5c8
  6de15c:      	br	x17

00000000006de160 <av_thread_message_flush@plt>:
  6de160:      	adrp	x16, 0x738000
  6de164:      	ldr	x17, [x16, #0x5d0]
  6de168:      	add	x16, x16, #0x5d0
  6de16c:      	br	x17

00000000006de170 <av_timecode_init_from_components@plt>:
  6de170:      	adrp	x16, 0x738000
  6de174:      	ldr	x17, [x16, #0x5d8]
  6de178:      	add	x16, x16, #0x5d8
  6de17c:      	br	x17

00000000006de180 <av_sha512_alloc@plt>:
  6de180:      	adrp	x16, 0x738000
  6de184:      	ldr	x17, [x16, #0x5e0]
  6de188:      	add	x16, x16, #0x5e0
  6de18c:      	br	x17

00000000006de190 <av_sha512_init@plt>:
  6de190:      	adrp	x16, 0x738000
  6de194:      	ldr	x17, [x16, #0x5e8]
  6de198:      	add	x16, x16, #0x5e8
  6de19c:      	br	x17

00000000006de1a0 <av_sha512_update@plt>:
  6de1a0:      	adrp	x16, 0x738000
  6de1a4:      	ldr	x17, [x16, #0x5f0]
  6de1a8:      	add	x16, x16, #0x5f0
  6de1ac:      	br	x17

00000000006de1b0 <av_sha512_final@plt>:
  6de1b0:      	adrp	x16, 0x738000
  6de1b4:      	ldr	x17, [x16, #0x5f8]
  6de1b8:      	add	x16, x16, #0x5f8
  6de1bc:      	br	x17

00000000006de1c0 <mkstemp@plt>:
  6de1c0:      	adrp	x16, 0x738000
  6de1c4:      	ldr	x17, [x16, #0x600]
  6de1c8:      	add	x16, x16, #0x600
  6de1cc:      	br	x17

00000000006de1d0 <fdopen@plt>:
  6de1d0:      	adrp	x16, 0x738000
  6de1d4:      	ldr	x17, [x16, #0x608]
  6de1d8:      	add	x16, x16, #0x608
  6de1dc:      	br	x17

00000000006de1e0 <av_video_hint_alloc@plt>:
  6de1e0:      	adrp	x16, 0x738000
  6de1e4:      	ldr	x17, [x16, #0x610]
  6de1e8:      	add	x16, x16, #0x610
  6de1ec:      	br	x17

00000000006de1f0 <av_strtod@plt>:
  6de1f0:      	adrp	x16, 0x738000
  6de1f4:      	ldr	x17, [x16, #0x618]
  6de1f8:      	add	x16, x16, #0x618
  6de1fc:      	br	x17

00000000006de200 <av_expr_parse_and_eval@plt>:
  6de200:      	adrp	x16, 0x738000
  6de204:      	ldr	x17, [x16, #0x620]
  6de208:      	add	x16, x16, #0x620
  6de20c:      	br	x17

00000000006de210 <av_dict_get_string@plt>:
  6de210:      	adrp	x16, 0x738000
  6de214:      	ldr	x17, [x16, #0x628]
  6de218:      	add	x16, x16, #0x628
  6de21c:      	br	x17

00000000006de220 <gmtime_r@plt>:
  6de220:      	adrp	x16, 0x738000
  6de224:      	ldr	x17, [x16, #0x630]
  6de228:      	add	x16, x16, #0x630
  6de22c:      	br	x17

00000000006de230 <av_bprint_escape@plt>:
  6de230:      	adrp	x16, 0x738000
  6de234:      	ldr	x17, [x16, #0x638]
  6de238:      	add	x16, x16, #0x638
  6de23c:      	br	x17

00000000006de240 <av_opt_find2@plt>:
  6de240:      	adrp	x16, 0x738000
  6de244:      	ldr	x17, [x16, #0x640]
  6de248:      	add	x16, x16, #0x640
  6de24c:      	br	x17

00000000006de250 <av_opt_eval_flags@plt>:
  6de250:      	adrp	x16, 0x738000
  6de254:      	ldr	x17, [x16, #0x648]
  6de258:      	add	x16, x16, #0x648
  6de25c:      	br	x17

00000000006de260 <av_opt_find@plt>:
  6de260:      	adrp	x16, 0x738000
  6de264:      	ldr	x17, [x16, #0x650]
  6de268:      	add	x16, x16, #0x650
  6de26c:      	br	x17

00000000006de270 <av_opt_get_q@plt>:
  6de270:      	adrp	x16, 0x738000
  6de274:      	ldr	x17, [x16, #0x658]
  6de278:      	add	x16, x16, #0x658
  6de27c:      	br	x17

00000000006de280 <av_opt_query_ranges@plt>:
  6de280:      	adrp	x16, 0x738000
  6de284:      	ldr	x17, [x16, #0x660]
  6de288:      	add	x16, x16, #0x660
  6de28c:      	br	x17

00000000006de290 <av_opt_freep_ranges@plt>:
  6de290:      	adrp	x16, 0x738000
  6de294:      	ldr	x17, [x16, #0x668]
  6de298:      	add	x16, x16, #0x668
  6de29c:      	br	x17

00000000006de2a0 <av_parse_color@plt>:
  6de2a0:      	adrp	x16, 0x738000
  6de2a4:      	ldr	x17, [x16, #0x670]
  6de2a8:      	add	x16, x16, #0x670
  6de2ac:      	br	x17

00000000006de2b0 <av_parse_video_size@plt>:
  6de2b0:      	adrp	x16, 0x738000
  6de2b4:      	ldr	x17, [x16, #0x678]
  6de2b8:      	add	x16, x16, #0x678
  6de2bc:      	br	x17

00000000006de2c0 <av_parse_video_rate@plt>:
  6de2c0:      	adrp	x16, 0x738000
  6de2c4:      	ldr	x17, [x16, #0x680]
  6de2c8:      	add	x16, x16, #0x680
  6de2cc:      	br	x17

00000000006de2d0 <av_opt_get_key_value@plt>:
  6de2d0:      	adrp	x16, 0x738000
  6de2d4:      	ldr	x17, [x16, #0x688]
  6de2d8:      	add	x16, x16, #0x688
  6de2dc:      	br	x17

00000000006de2e0 <av_opt_is_set_to_default@plt>:
  6de2e0:      	adrp	x16, 0x738000
  6de2e4:      	ldr	x17, [x16, #0x690]
  6de2e8:      	add	x16, x16, #0x690
  6de2ec:      	br	x17

00000000006de2f0 <arc4random_buf@plt>:
  6de2f0:      	adrp	x16, 0x738000
  6de2f4:      	ldr	x17, [x16, #0x698]
  6de2f8:      	add	x16, x16, #0x698
  6de2fc:      	br	x17

00000000006de300 <av_log_format_line2@plt>:
  6de300:      	adrp	x16, 0x738000
  6de304:      	ldr	x17, [x16, #0x6a0]
  6de308:      	add	x16, x16, #0x6a0
  6de30c:      	br	x17

00000000006de310 <isatty@plt>:
  6de310:      	adrp	x16, 0x738000
  6de314:      	ldr	x17, [x16, #0x6a8]
  6de318:      	add	x16, x16, #0x6a8
  6de31c:      	br	x17

00000000006de320 <fputs@plt>:
  6de320:      	adrp	x16, 0x738000
  6de324:      	ldr	x17, [x16, #0x6b0]
  6de328:      	add	x16, x16, #0x6b0
  6de32c:      	br	x17

00000000006de330 <ff_get_cpu_flags_aarch64@plt>:
  6de330:      	adrp	x16, 0x738000
  6de334:      	ldr	x17, [x16, #0x6b8]
  6de338:      	add	x16, x16, #0x6b8
  6de33c:      	br	x17

00000000006de340 <sched_getaffinity@plt>:
  6de340:      	adrp	x16, 0x738000
  6de344:      	ldr	x17, [x16, #0x6c0]
  6de348:      	add	x16, x16, #0x6c0
  6de34c:      	br	x17

00000000006de350 <__sched_cpucount@plt>:
  6de350:      	adrp	x16, 0x738000
  6de354:      	ldr	x17, [x16, #0x6c8]
  6de358:      	add	x16, x16, #0x6c8
  6de35c:      	br	x17

00000000006de360 <ff_get_cpu_max_align_aarch64@plt>:
  6de360:      	adrp	x16, 0x738000
  6de364:      	ldr	x17, [x16, #0x6d0]
  6de368:      	add	x16, x16, #0x6d0
  6de36c:      	br	x17

00000000006de370 <ff_getauxval@plt>:
  6de370:      	adrp	x16, 0x738000
  6de374:      	ldr	x17, [x16, #0x6d8]
  6de378:      	add	x16, x16, #0x6d8
  6de37c:      	br	x17

00000000006de380 <getauxval@plt>:
  6de380:      	adrp	x16, 0x738000
  6de384:      	ldr	x17, [x16, #0x6e0]
  6de388:      	add	x16, x16, #0x6e0
  6de38c:      	br	x17

00000000006de390 <av_channel_name_bprint@plt>:
  6de390:      	adrp	x16, 0x738000
  6de394:      	ldr	x17, [x16, #0x6e8]
  6de398:      	add	x16, x16, #0x6e8
  6de39c:      	br	x17

00000000006de3a0 <av_channel_name@plt>:
  6de3a0:      	adrp	x16, 0x738000
  6de3a4:      	ldr	x17, [x16, #0x6f0]
  6de3a8:      	add	x16, x16, #0x6f0
  6de3ac:      	br	x17

00000000006de3b0 <av_channel_description_bprint@plt>:
  6de3b0:      	adrp	x16, 0x738000
  6de3b4:      	ldr	x17, [x16, #0x6f8]
  6de3b8:      	add	x16, x16, #0x6f8
  6de3bc:      	br	x17

00000000006de3c0 <av_channel_from_string@plt>:
  6de3c0:      	adrp	x16, 0x738000
  6de3c4:      	ldr	x17, [x16, #0x700]
  6de3c8:      	add	x16, x16, #0x700
  6de3cc:      	br	x17

00000000006de3d0 <av_channel_layout_index_from_string@plt>:
  6de3d0:      	adrp	x16, 0x738000
  6de3d4:      	ldr	x17, [x16, #0x708]
  6de3d8:      	add	x16, x16, #0x708
  6de3dc:      	br	x17

00000000006de3e0 <av_image_fill_max_pixsteps@plt>:
  6de3e0:      	adrp	x16, 0x738000
  6de3e4:      	ldr	x17, [x16, #0x710]
  6de3e8:      	add	x16, x16, #0x710
  6de3ec:      	br	x17

00000000006de3f0 <avpriv_set_systematic_pal2@plt>:
  6de3f0:      	adrp	x16, 0x738000
  6de3f4:      	ldr	x17, [x16, #0x718]
  6de3f8:      	add	x16, x16, #0x718
  6de3fc:      	br	x17

00000000006de400 <av_image_alloc@plt>:
  6de400:      	adrp	x16, 0x738000
  6de404:      	ldr	x17, [x16, #0x720]
  6de408:      	add	x16, x16, #0x720
  6de40c:      	br	x17

00000000006de410 <av_image_get_buffer_size@plt>:
  6de410:      	adrp	x16, 0x738000
  6de414:      	ldr	x17, [x16, #0x728]
  6de418:      	add	x16, x16, #0x728
  6de41c:      	br	x17

00000000006de420 <av_image_fill_color@plt>:
  6de420:      	adrp	x16, 0x738000
  6de424:      	ldr	x17, [x16, #0x730]
  6de428:      	add	x16, x16, #0x730
  6de42c:      	br	x17

00000000006de430 <ff_tx_init_tabs_int32@plt>:
  6de430:      	adrp	x16, 0x738000
  6de434:      	ldr	x17, [x16, #0x738]
  6de438:      	add	x16, x16, #0x738
  6de43c:      	br	x17

00000000006de440 <ff_tx_mdct_gen_exp_int32@plt>:
  6de440:      	adrp	x16, 0x738000
  6de444:      	ldr	x17, [x16, #0x740]
  6de448:      	add	x16, x16, #0x740
  6de44c:      	br	x17

00000000006de450 <av_video_enc_params_alloc@plt>:
  6de450:      	adrp	x16, 0x738000
  6de454:      	ldr	x17, [x16, #0x748]
  6de458:      	add	x16, x16, #0x748
  6de45c:      	br	x17

00000000006de460 <av_parse_ratio@plt>:
  6de460:      	adrp	x16, 0x738000
  6de464:      	ldr	x17, [x16, #0x750]
  6de468:      	add	x16, x16, #0x750
  6de46c:      	br	x17

00000000006de470 <mktime@plt>:
  6de470:      	adrp	x16, 0x738000
  6de474:      	ldr	x17, [x16, #0x758]
  6de478:      	add	x16, x16, #0x758
  6de47c:      	br	x17

00000000006de480 <posix_memalign@plt>:
  6de480:      	adrp	x16, 0x738000
  6de484:      	ldr	x17, [x16, #0x760]
  6de488:      	add	x16, x16, #0x760
  6de48c:      	br	x17

00000000006de490 <realloc@plt>:
  6de490:      	adrp	x16, 0x738000
  6de494:      	ldr	x17, [x16, #0x768]
  6de498:      	add	x16, x16, #0x768
  6de49c:      	br	x17

00000000006de4a0 <free@plt>:
  6de4a0:      	adrp	x16, 0x738000
  6de4a4:      	ldr	x17, [x16, #0x770]
  6de4a8:      	add	x16, x16, #0x770
  6de4ac:      	br	x17

00000000006de4b0 <av_ripemd_alloc@plt>:
  6de4b0:      	adrp	x16, 0x738000
  6de4b4:      	ldr	x17, [x16, #0x778]
  6de4b8:      	add	x16, x16, #0x778
  6de4bc:      	br	x17

00000000006de4c0 <av_ripemd_init@plt>:
  6de4c0:      	adrp	x16, 0x738000
  6de4c4:      	ldr	x17, [x16, #0x780]
  6de4c8:      	add	x16, x16, #0x780
  6de4cc:      	br	x17

00000000006de4d0 <av_ripemd_update@plt>:
  6de4d0:      	adrp	x16, 0x738000
  6de4d4:      	ldr	x17, [x16, #0x788]
  6de4d8:      	add	x16, x16, #0x788
  6de4dc:      	br	x17

00000000006de4e0 <av_ripemd_final@plt>:
  6de4e0:      	adrp	x16, 0x738000
  6de4e4:      	ldr	x17, [x16, #0x790]
  6de4e8:      	add	x16, x16, #0x790
  6de4ec:      	br	x17

00000000006de4f0 <av_sub_i@plt>:
  6de4f0:      	adrp	x16, 0x738000
  6de4f4:      	ldr	x17, [x16, #0x798]
  6de4f8:      	add	x16, x16, #0x798
  6de4fc:      	br	x17

00000000006de500 <av_log2_i@plt>:
  6de500:      	adrp	x16, 0x738000
  6de504:      	ldr	x17, [x16, #0x7a0]
  6de508:      	add	x16, x16, #0x7a0
  6de50c:      	br	x17

00000000006de510 <av_mod_i@plt>:
  6de510:      	adrp	x16, 0x738000
  6de514:      	ldr	x17, [x16, #0x7a8]
  6de518:      	add	x16, x16, #0x7a8
  6de51c:      	br	x17

00000000006de520 <av_hash_final@plt>:
  6de520:      	adrp	x16, 0x738000
  6de524:      	ldr	x17, [x16, #0x7b0]
  6de528:      	add	x16, x16, #0x7b0
  6de52c:      	br	x17

00000000006de530 <ff_tx_init_tabs_double@plt>:
  6de530:      	adrp	x16, 0x738000
  6de534:      	ldr	x17, [x16, #0x7b8]
  6de538:      	add	x16, x16, #0x7b8
  6de53c:      	br	x17

00000000006de540 <ff_tx_mdct_gen_exp_double@plt>:
  6de540:      	adrp	x16, 0x738000
  6de544:      	ldr	x17, [x16, #0x7c0]
  6de548:      	add	x16, x16, #0x7c0
  6de54c:      	br	x17

00000000006de550 <swri_resample_dsp_init@plt>:
  6de550:      	adrp	x16, 0x738000
  6de554:      	ldr	x17, [x16, #0x7c8]
  6de558:      	add	x16, x16, #0x7c8
  6de55c:      	br	x17

00000000006de560 <swri_realloc_audio@plt>:
  6de560:      	adrp	x16, 0x738000
  6de564:      	ldr	x17, [x16, #0x7d0]
  6de568:      	add	x16, x16, #0x7d0
  6de56c:      	br	x17

00000000006de570 <swri_get_dither@plt>:
  6de570:      	adrp	x16, 0x738000
  6de574:      	ldr	x17, [x16, #0x7d8]
  6de578:      	add	x16, x16, #0x7d8
  6de57c:      	br	x17

00000000006de580 <swri_dither_init@plt>:
  6de580:      	adrp	x16, 0x738000
  6de584:      	ldr	x17, [x16, #0x7e0]
  6de588:      	add	x16, x16, #0x7e0
  6de58c:      	br	x17

00000000006de590 <swri_noise_shaping_int16@plt>:
  6de590:      	adrp	x16, 0x738000
  6de594:      	ldr	x17, [x16, #0x7e8]
  6de598:      	add	x16, x16, #0x7e8
  6de59c:      	br	x17

00000000006de5a0 <swri_noise_shaping_int32@plt>:
  6de5a0:      	adrp	x16, 0x738000
  6de5a4:      	ldr	x17, [x16, #0x7f0]
  6de5a8:      	add	x16, x16, #0x7f0
  6de5ac:      	br	x17

00000000006de5b0 <swri_noise_shaping_float@plt>:
  6de5b0:      	adrp	x16, 0x738000
  6de5b4:      	ldr	x17, [x16, #0x7f8]
  6de5b8:      	add	x16, x16, #0x7f8
  6de5bc:      	br	x17

00000000006de5c0 <swri_noise_shaping_double@plt>:
  6de5c0:      	adrp	x16, 0x738000
  6de5c4:      	ldr	x17, [x16, #0x800]
  6de5c8:      	add	x16, x16, #0x800
  6de5cc:      	br	x17

00000000006de5d0 <swr_config_frame@plt>:
  6de5d0:      	adrp	x16, 0x738000
  6de5d4:      	ldr	x17, [x16, #0x808]
  6de5d8:      	add	x16, x16, #0x808
  6de5dc:      	br	x17

00000000006de5e0 <swr_get_delay@plt>:
  6de5e0:      	adrp	x16, 0x738000
  6de5e4:      	ldr	x17, [x16, #0x810]
  6de5e8:      	add	x16, x16, #0x810
  6de5ec:      	br	x17

00000000006de5f0 <swri_resample_dsp_aarch64_init@plt>:
  6de5f0:      	adrp	x16, 0x738000
  6de5f4:      	ldr	x17, [x16, #0x818]
  6de5f8:      	add	x16, x16, #0x818
  6de5fc:      	br	x17

00000000006de600 <swr_build_matrix2@plt>:
  6de600:      	adrp	x16, 0x738000
  6de604:      	ldr	x17, [x16, #0x820]
  6de608:      	add	x16, x16, #0x820
  6de60c:      	br	x17

00000000006de610 <swri_rematrix_init@plt>:
  6de610:      	adrp	x16, 0x738000
  6de614:      	ldr	x17, [x16, #0x828]
  6de618:      	add	x16, x16, #0x828
  6de61c:      	br	x17

00000000006de620 <swri_rematrix_free@plt>:
  6de620:      	adrp	x16, 0x738000
  6de624:      	ldr	x17, [x16, #0x830]
  6de628:      	add	x16, x16, #0x830
  6de62c:      	br	x17

00000000006de630 <swri_rematrix@plt>:
  6de630:      	adrp	x16, 0x738000
  6de634:      	ldr	x17, [x16, #0x838]
  6de638:      	add	x16, x16, #0x838
  6de63c:      	br	x17

00000000006de640 <swri_audio_convert_alloc@plt>:
  6de640:      	adrp	x16, 0x738000
  6de644:      	ldr	x17, [x16, #0x840]
  6de648:      	add	x16, x16, #0x840
  6de64c:      	br	x17

00000000006de650 <swri_audio_convert_init_aarch64@plt>:
  6de650:      	adrp	x16, 0x738000
  6de654:      	ldr	x17, [x16, #0x848]
  6de658:      	add	x16, x16, #0x848
  6de65c:      	br	x17

00000000006de660 <swri_audio_convert_free@plt>:
  6de660:      	adrp	x16, 0x738000
  6de664:      	ldr	x17, [x16, #0x850]
  6de668:      	add	x16, x16, #0x850
  6de66c:      	br	x17

00000000006de670 <swri_audio_convert@plt>:
  6de670:      	adrp	x16, 0x738000
  6de674:      	ldr	x17, [x16, #0x858]
  6de678:      	add	x16, x16, #0x858
  6de67c:      	br	x17

00000000006de680 <swr_drop_output@plt>:
  6de680:      	adrp	x16, 0x738000
  6de684:      	ldr	x17, [x16, #0x860]
  6de688:      	add	x16, x16, #0x860
  6de68c:      	br	x17

00000000006de690 <swr_inject_silence@plt>:
  6de690:      	adrp	x16, 0x738000
  6de694:      	ldr	x17, [x16, #0x868]
  6de698:      	add	x16, x16, #0x868
  6de69c:      	br	x17

00000000006de6a0 <swr_set_compensation@plt>:
  6de6a0:      	adrp	x16, 0x738000
  6de6a4:      	ldr	x17, [x16, #0x870]
  6de6a8:      	add	x16, x16, #0x870
  6de6ac:      	br	x17

00000000006de6b0 <sws_setColorspaceDetails@plt>:
  6de6b0:      	adrp	x16, 0x738000
  6de6b4:      	ldr	x17, [x16, #0x878]
  6de6b8:      	add	x16, x16, #0x878
  6de6bc:      	br	x17

00000000006de6c0 <ff_sws_init_range_convert@plt>:
  6de6c0:      	adrp	x16, 0x738000
  6de6c4:      	ldr	x17, [x16, #0x880]
  6de6c8:      	add	x16, x16, #0x880
  6de6cc:      	br	x17

00000000006de6d0 <ff_sws_init_range_convert_aarch64@plt>:
  6de6d0:      	adrp	x16, 0x738000
  6de6d4:      	ldr	x17, [x16, #0x888]
  6de6d8:      	add	x16, x16, #0x888
  6de6dc:      	br	x17

00000000006de6e0 <sws_init_context@plt>:
  6de6e0:      	adrp	x16, 0x738000
  6de6e4:      	ldr	x17, [x16, #0x890]
  6de6e8:      	add	x16, x16, #0x890
  6de6ec:      	br	x17

00000000006de6f0 <ff_yuv2rgb_c_init_tables@plt>:
  6de6f0:      	adrp	x16, 0x738000
  6de6f4:      	ldr	x17, [x16, #0x898]
  6de6f8:      	add	x16, x16, #0x898
  6de6fc:      	br	x17

00000000006de700 <sws_alloc_context@plt>:
  6de700:      	adrp	x16, 0x738000
  6de704:      	ldr	x17, [x16, #0x8a0]
  6de708:      	add	x16, x16, #0x8a0
  6de70c:      	br	x17

00000000006de710 <sws_getContext@plt>:
  6de710:      	adrp	x16, 0x738000
  6de714:      	ldr	x17, [x16, #0x8a8]
  6de718:      	add	x16, x16, #0x8a8
  6de71c:      	br	x17

00000000006de720 <ff_free_filters@plt>:
  6de720:      	adrp	x16, 0x738000
  6de724:      	ldr	x17, [x16, #0x8b0]
  6de728:      	add	x16, x16, #0x8b0
  6de72c:      	br	x17

00000000006de730 <ff_init_filters@plt>:
  6de730:      	adrp	x16, 0x738000
  6de734:      	ldr	x17, [x16, #0x8b8]
  6de738:      	add	x16, x16, #0x8b8
  6de73c:      	br	x17

00000000006de740 <ff_get_unscaled_swscale@plt>:
  6de740:      	adrp	x16, 0x738000
  6de744:      	ldr	x17, [x16, #0x8c0]
  6de748:      	add	x16, x16, #0x8c0
  6de74c:      	br	x17

00000000006de750 <sws_freeContext@plt>:
  6de750:      	adrp	x16, 0x738000
  6de754:      	ldr	x17, [x16, #0x8c8]
  6de758:      	add	x16, x16, #0x8c8
  6de75c:      	br	x17

00000000006de760 <ff_sws_init_scale@plt>:
  6de760:      	adrp	x16, 0x738000
  6de764:      	ldr	x17, [x16, #0x8d0]
  6de768:      	add	x16, x16, #0x8d0
  6de76c:      	br	x17

00000000006de770 <sws_allocVec@plt>:
  6de770:      	adrp	x16, 0x738000
  6de774:      	ldr	x17, [x16, #0x8d8]
  6de778:      	add	x16, x16, #0x8d8
  6de77c:      	br	x17

00000000006de780 <sws_getGaussianVec@plt>:
  6de780:      	adrp	x16, 0x738000
  6de784:      	ldr	x17, [x16, #0x8e0]
  6de788:      	add	x16, x16, #0x8e0
  6de78c:      	br	x17

00000000006de790 <sws_normalizeVec@plt>:
  6de790:      	adrp	x16, 0x738000
  6de794:      	ldr	x17, [x16, #0x8e8]
  6de798:      	add	x16, x16, #0x8e8
  6de79c:      	br	x17

00000000006de7a0 <sws_scaleVec@plt>:
  6de7a0:      	adrp	x16, 0x738000
  6de7a4:      	ldr	x17, [x16, #0x8f0]
  6de7a8:      	add	x16, x16, #0x8f0
  6de7ac:      	br	x17

00000000006de7b0 <sws_freeVec@plt>:
  6de7b0:      	adrp	x16, 0x738000
  6de7b4:      	ldr	x17, [x16, #0x8f8]
  6de7b8:      	add	x16, x16, #0x8f8
  6de7bc:      	br	x17

00000000006de7c0 <ff_range_add@plt>:
  6de7c0:      	adrp	x16, 0x738000
  6de7c4:      	ldr	x17, [x16, #0x900]
  6de7c8:      	add	x16, x16, #0x900
  6de7cc:      	br	x17

00000000006de7d0 <ff_sws_init_input_funcs@plt>:
  6de7d0:      	adrp	x16, 0x738000
  6de7d4:      	ldr	x17, [x16, #0x908]
  6de7d8:      	add	x16, x16, #0x908
  6de7dc:      	br	x17

00000000006de7e0 <ff_init_desc_fmt_convert@plt>:
  6de7e0:      	adrp	x16, 0x738000
  6de7e4:      	ldr	x17, [x16, #0x910]
  6de7e8:      	add	x16, x16, #0x910
  6de7ec:      	br	x17

00000000006de7f0 <ff_init_desc_hscale@plt>:
  6de7f0:      	adrp	x16, 0x738000
  6de7f4:      	ldr	x17, [x16, #0x918]
  6de7f8:      	add	x16, x16, #0x918
  6de7fc:      	br	x17

00000000006de800 <ff_init_desc_cfmt_convert@plt>:
  6de800:      	adrp	x16, 0x738000
  6de804:      	ldr	x17, [x16, #0x920]
  6de808:      	add	x16, x16, #0x920
  6de80c:      	br	x17

00000000006de810 <ff_init_desc_chscale@plt>:
  6de810:      	adrp	x16, 0x738000
  6de814:      	ldr	x17, [x16, #0x928]
  6de818:      	add	x16, x16, #0x928
  6de81c:      	br	x17

00000000006de820 <ff_init_desc_no_chr@plt>:
  6de820:      	adrp	x16, 0x738000
  6de824:      	ldr	x17, [x16, #0x930]
  6de828:      	add	x16, x16, #0x930
  6de82c:      	br	x17

00000000006de830 <ff_rgb24toyv12_c@plt>:
  6de830:      	adrp	x16, 0x738000
  6de834:      	ldr	x17, [x16, #0x938]
  6de838:      	add	x16, x16, #0x938
  6de83c:      	br	x17

00000000006de840 <rgb2rgb_init_aarch64@plt>:
  6de840:      	adrp	x16, 0x738000
  6de844:      	ldr	x17, [x16, #0x940]
  6de848:      	add	x16, x16, #0x940
  6de84c:      	br	x17

00000000006de850 <ff_rotate_slice@plt>:
  6de850:      	adrp	x16, 0x738000
  6de854:      	ldr	x17, [x16, #0x948]
  6de858:      	add	x16, x16, #0x948
  6de85c:      	br	x17

00000000006de860 <ff_init_slice_from_src@plt>:
  6de860:      	adrp	x16, 0x738000
  6de864:      	ldr	x17, [x16, #0x950]
  6de868:      	add	x16, x16, #0x950
  6de86c:      	br	x17

00000000006de870 <ff_init_half2float_tables@plt>:
  6de870:      	adrp	x16, 0x738000
  6de874:      	ldr	x17, [x16, #0x958]
  6de878:      	add	x16, x16, #0x958
  6de87c:      	br	x17

00000000006de880 <ff_init_gamma_convert@plt>:
  6de880:      	adrp	x16, 0x738000
  6de884:      	ldr	x17, [x16, #0x960]
  6de888:      	add	x16, x16, #0x960
  6de88c:      	br	x17

00000000006de890 <ff_init_vscale@plt>:
  6de890:      	adrp	x16, 0x738000
  6de894:      	ldr	x17, [x16, #0x968]
  6de898:      	add	x16, x16, #0x968
  6de89c:      	br	x17

00000000006de8a0 <ff_sws_init_output_funcs@plt>:
  6de8a0:      	adrp	x16, 0x738000
  6de8a4:      	ldr	x17, [x16, #0x970]
  6de8a8:      	add	x16, x16, #0x970
  6de8ac:      	br	x17

00000000006de8b0 <ff_init_vscale_pfn@plt>:
  6de8b0:      	adrp	x16, 0x738000
  6de8b4:      	ldr	x17, [x16, #0x978]
  6de8b8:      	add	x16, x16, #0x978
  6de8bc:      	br	x17

00000000006de8c0 <ff_sws_init_swscale_aarch64@plt>:
  6de8c0:      	adrp	x16, 0x738000
  6de8c4:      	ldr	x17, [x16, #0x980]
  6de8c8:      	add	x16, x16, #0x980
  6de8cc:      	br	x17

00000000006de8d0 <sws_frame_end@plt>:
  6de8d0:      	adrp	x16, 0x738000
  6de8d4:      	ldr	x17, [x16, #0x988]
  6de8d8:      	add	x16, x16, #0x988
  6de8dc:      	br	x17

00000000006de8e0 <sws_frame_start@plt>:
  6de8e0:      	adrp	x16, 0x738000
  6de8e4:      	ldr	x17, [x16, #0x990]
  6de8e8:      	add	x16, x16, #0x990
  6de8ec:      	br	x17

00000000006de8f0 <sws_send_slice@plt>:
  6de8f0:      	adrp	x16, 0x738000
  6de8f4:      	ldr	x17, [x16, #0x998]
  6de8f8:      	add	x16, x16, #0x998
  6de8fc:      	br	x17

00000000006de900 <sws_receive_slice@plt>:
  6de900:      	adrp	x16, 0x738000
  6de904:      	ldr	x17, [x16, #0x9a0]
  6de908:      	add	x16, x16, #0x9a0
  6de90c:      	br	x17

00000000006de910 <ff_copyPlane@plt>:
  6de910:      	adrp	x16, 0x738000
  6de914:      	ldr	x17, [x16, #0x9a8]
  6de918:      	add	x16, x16, #0x9a8
  6de91c:      	br	x17

00000000006de920 <ff_yuv2rgb_get_func_ptr@plt>:
  6de920:      	adrp	x16, 0x738000
  6de924:      	ldr	x17, [x16, #0x9b0]
  6de928:      	add	x16, x16, #0x9b0
  6de92c:      	br	x17

00000000006de930 <ff_get_unscaled_swscale_aarch64@plt>:
  6de930:      	adrp	x16, 0x738000
  6de934:      	ldr	x17, [x16, #0x9b8]
  6de938:      	add	x16, x16, #0x9b8
  6de93c:      	br	x17

00000000006de940 <vfprintf@plt>:
  6de940:      	adrp	x16, 0x738000
  6de944:      	ldr	x17, [x16, #0x9c0]
  6de948:      	add	x16, x16, #0x9c0
  6de94c:      	br	x17

00000000006de950 <memalign@plt>:
  6de950:      	adrp	x16, 0x738000
  6de954:      	ldr	x17, [x16, #0x9c8]
  6de958:      	add	x16, x16, #0x9c8
  6de95c:      	br	x17

00000000006de960 <fopen@plt>:
  6de960:      	adrp	x16, 0x738000
  6de964:      	ldr	x17, [x16, #0x9d0]
  6de968:      	add	x16, x16, #0x9d0
  6de96c:      	br	x17

00000000006de970 <fseeko@plt>:
  6de970:      	adrp	x16, 0x738000
  6de974:      	ldr	x17, [x16, #0x9d8]
  6de978:      	add	x16, x16, #0x9d8
  6de97c:      	br	x17

00000000006de980 <ftello@plt>:
  6de980:      	adrp	x16, 0x738000
  6de984:      	ldr	x17, [x16, #0x9e0]
  6de988:      	add	x16, x16, #0x9e0
  6de98c:      	br	x17

00000000006de990 <fread@plt>:
  6de990:      	adrp	x16, 0x738000
  6de994:      	ldr	x17, [x16, #0x9e8]
  6de998:      	add	x16, x16, #0x9e8
  6de99c:      	br	x17

00000000006de9a0 <fclose@plt>:
  6de9a0:      	adrp	x16, 0x738000
  6de9a4:      	ldr	x17, [x16, #0x9f0]
  6de9a8:      	add	x16, x16, #0x9f0
  6de9ac:      	br	x17

00000000006de9b0 <malloc@plt>:
  6de9b0:      	adrp	x16, 0x738000
  6de9b4:      	ldr	x17, [x16, #0x9f8]
  6de9b8:      	add	x16, x16, #0x9f8
  6de9bc:      	br	x17

00000000006de9c0 <strdup@plt>:
  6de9c0:      	adrp	x16, 0x738000
  6de9c4:      	ldr	x17, [x16, #0xa00]
  6de9c8:      	add	x16, x16, #0xa00
  6de9cc:      	br	x17

00000000006de9d0 <strcasecmp@plt>:
  6de9d0:      	adrp	x16, 0x738000
  6de9d4:      	ldr	x17, [x16, #0xa08]
  6de9d8:      	add	x16, x16, #0xa08
  6de9dc:      	br	x17

00000000006de9e0 <strncasecmp@plt>:
  6de9e0:      	adrp	x16, 0x738000
  6de9e4:      	ldr	x17, [x16, #0xa10]
  6de9e8:      	add	x16, x16, #0xa10
  6de9ec:      	br	x17

00000000006de9f0 <strtok_r@plt>:
  6de9f0:      	adrp	x16, 0x738000
  6de9f4:      	ldr	x17, [x16, #0xa18]
  6de9f8:      	add	x16, x16, #0xa18
  6de9fc:      	br	x17

00000000006dea00 <sprintf@plt>:
  6dea00:      	adrp	x16, 0x738000
  6dea04:      	ldr	x17, [x16, #0xa20]
  6dea08:      	add	x16, x16, #0xa20
  6dea0c:      	br	x17

00000000006dea10 <sysconf@plt>:
  6dea10:      	adrp	x16, 0x738000
  6dea14:      	ldr	x17, [x16, #0xa28]
  6dea18:      	add	x16, x16, #0xa28
  6dea1c:      	br	x17

00000000006dea20 <calloc@plt>:
  6dea20:      	adrp	x16, 0x738000
  6dea24:      	ldr	x17, [x16, #0xa30]
  6dea28:      	add	x16, x16, #0xa30
  6dea2c:      	br	x17

00000000006dea30 <nice@plt>:
  6dea30:      	adrp	x16, 0x738000
  6dea34:      	ldr	x17, [x16, #0xa38]
  6dea38:      	add	x16, x16, #0xa38
  6dea3c:      	br	x17

00000000006dea40 <fileno@plt>:
  6dea40:      	adrp	x16, 0x738000
  6dea44:      	ldr	x17, [x16, #0xa40]
  6dea48:      	add	x16, x16, #0xa40
  6dea4c:      	br	x17

00000000006dea50 <x264_8_cabac_encode_terminal_asm@plt>:
  6dea50:      	adrp	x16, 0x738000
  6dea54:      	ldr	x17, [x16, #0xa48]
  6dea58:      	add	x16, x16, #0xa48
  6dea5c:      	br	x17

00000000006dea60 <strpbrk@plt>:
  6dea60:      	adrp	x16, 0x738000
  6dea64:      	ldr	x17, [x16, #0xa50]
  6dea68:      	add	x16, x16, #0xa50
  6dea6c:      	br	x17

00000000006dea70 <strcat@plt>:
  6dea70:      	adrp	x16, 0x738000
  6dea74:      	ldr	x17, [x16, #0xa58]
  6dea78:      	add	x16, x16, #0xa58
  6dea7c:      	br	x17

00000000006dea80 <x264_8_pixel_sad_16x16_neon@plt>:
  6dea80:      	adrp	x16, 0x738000
  6dea84:      	ldr	x17, [x16, #0xa60]
  6dea88:      	add	x16, x16, #0xa60
  6dea8c:      	br	x17

00000000006dea90 <x264_8_pixel_sad_8x16_neon@plt>:
  6dea90:      	adrp	x16, 0x738000
  6dea94:      	ldr	x17, [x16, #0xa68]
  6dea98:      	add	x16, x16, #0xa68
  6dea9c:      	br	x17

00000000006deaa0 <x264_8_pixel_sad_8x8_neon@plt>:
  6deaa0:      	adrp	x16, 0x738000
  6deaa4:      	ldr	x17, [x16, #0xa70]
  6deaa8:      	add	x16, x16, #0xa70
  6deaac:      	br	x17

00000000006deab0 <x264_8_pixel_sad_4x4_neon@plt>:
  6deab0:      	adrp	x16, 0x738000
  6deab4:      	ldr	x17, [x16, #0xa78]
  6deab8:      	add	x16, x16, #0xa78
  6deabc:      	br	x17

00000000006deac0 <x264_8_pixel_satd_16x16_neon@plt>:
  6deac0:      	adrp	x16, 0x738000
  6deac4:      	ldr	x17, [x16, #0xa80]
  6deac8:      	add	x16, x16, #0xa80
  6deacc:      	br	x17

00000000006dead0 <x264_8_pixel_satd_16x8_neon@plt>:
  6dead0:      	adrp	x16, 0x738000
  6dead4:      	ldr	x17, [x16, #0xa88]
  6dead8:      	add	x16, x16, #0xa88
  6deadc:      	br	x17

00000000006deae0 <x264_8_pixel_satd_8x16_neon@plt>:
  6deae0:      	adrp	x16, 0x738000
  6deae4:      	ldr	x17, [x16, #0xa90]
  6deae8:      	add	x16, x16, #0xa90
  6deaec:      	br	x17

00000000006deaf0 <x264_8_pixel_satd_8x8_neon@plt>:
  6deaf0:      	adrp	x16, 0x738000
  6deaf4:      	ldr	x17, [x16, #0xa98]
  6deaf8:      	add	x16, x16, #0xa98
  6deafc:      	br	x17

00000000006deb00 <x264_8_pixel_satd_8x4_neon@plt>:
  6deb00:      	adrp	x16, 0x738000
  6deb04:      	ldr	x17, [x16, #0xaa0]
  6deb08:      	add	x16, x16, #0xaa0
  6deb0c:      	br	x17

00000000006deb10 <x264_8_pixel_satd_4x8_neon@plt>:
  6deb10:      	adrp	x16, 0x738000
  6deb14:      	ldr	x17, [x16, #0xaa8]
  6deb18:      	add	x16, x16, #0xaa8
  6deb1c:      	br	x17

00000000006deb20 <x264_8_pixel_satd_4x4_neon@plt>:
  6deb20:      	adrp	x16, 0x738000
  6deb24:      	ldr	x17, [x16, #0xab0]
  6deb28:      	add	x16, x16, #0xab0
  6deb2c:      	br	x17

00000000006deb30 <x264_8_pixel_sa8d_8x8_neon@plt>:
  6deb30:      	adrp	x16, 0x738000
  6deb34:      	ldr	x17, [x16, #0xab8]
  6deb38:      	add	x16, x16, #0xab8
  6deb3c:      	br	x17

00000000006deb40 <x264_8_predict_4x4_v_aarch64@plt>:
  6deb40:      	adrp	x16, 0x738000
  6deb44:      	ldr	x17, [x16, #0xac0]
  6deb48:      	add	x16, x16, #0xac0
  6deb4c:      	br	x17

00000000006deb50 <x264_8_predict_4x4_h_aarch64@plt>:
  6deb50:      	adrp	x16, 0x738000
  6deb54:      	ldr	x17, [x16, #0xac8]
  6deb58:      	add	x16, x16, #0xac8
  6deb5c:      	br	x17

00000000006deb60 <x264_8_predict_4x4_dc_neon@plt>:
  6deb60:      	adrp	x16, 0x738000
  6deb64:      	ldr	x17, [x16, #0xad0]
  6deb68:      	add	x16, x16, #0xad0
  6deb6c:      	br	x17

00000000006deb70 <x264_8_predict_8x8_v_neon@plt>:
  6deb70:      	adrp	x16, 0x738000
  6deb74:      	ldr	x17, [x16, #0xad8]
  6deb78:      	add	x16, x16, #0xad8
  6deb7c:      	br	x17

00000000006deb80 <x264_8_predict_8x8_h_neon@plt>:
  6deb80:      	adrp	x16, 0x738000
  6deb84:      	ldr	x17, [x16, #0xae0]
  6deb88:      	add	x16, x16, #0xae0
  6deb8c:      	br	x17

00000000006deb90 <x264_8_predict_8x8_dc_neon@plt>:
  6deb90:      	adrp	x16, 0x738000
  6deb94:      	ldr	x17, [x16, #0xae8]
  6deb98:      	add	x16, x16, #0xae8
  6deb9c:      	br	x17

00000000006deba0 <x264_8_predict_8x8c_dc_neon@plt>:
  6deba0:      	adrp	x16, 0x738000
  6deba4:      	ldr	x17, [x16, #0xaf0]
  6deba8:      	add	x16, x16, #0xaf0
  6debac:      	br	x17

00000000006debb0 <x264_8_predict_8x8c_h_neon@plt>:
  6debb0:      	adrp	x16, 0x738000
  6debb4:      	ldr	x17, [x16, #0xaf8]
  6debb8:      	add	x16, x16, #0xaf8
  6debbc:      	br	x17

00000000006debc0 <x264_8_predict_8x8c_v_aarch64@plt>:
  6debc0:      	adrp	x16, 0x738000
  6debc4:      	ldr	x17, [x16, #0xb00]
  6debc8:      	add	x16, x16, #0xb00
  6debcc:      	br	x17

00000000006debd0 <x264_8_predict_8x16c_dc_neon@plt>:
  6debd0:      	adrp	x16, 0x738000
  6debd4:      	ldr	x17, [x16, #0xb08]
  6debd8:      	add	x16, x16, #0xb08
  6debdc:      	br	x17

00000000006debe0 <x264_8_predict_8x16c_h_neon@plt>:
  6debe0:      	adrp	x16, 0x738000
  6debe4:      	ldr	x17, [x16, #0xb10]
  6debe8:      	add	x16, x16, #0xb10
  6debec:      	br	x17

00000000006debf0 <x264_8_predict_8x16c_v_neon@plt>:
  6debf0:      	adrp	x16, 0x738000
  6debf4:      	ldr	x17, [x16, #0xb18]
  6debf8:      	add	x16, x16, #0xb18
  6debfc:      	br	x17

00000000006dec00 <x264_8_predict_16x16_v_neon@plt>:
  6dec00:      	adrp	x16, 0x738000
  6dec04:      	ldr	x17, [x16, #0xb20]
  6dec08:      	add	x16, x16, #0xb20
  6dec0c:      	br	x17

00000000006dec10 <x264_8_predict_16x16_h_neon@plt>:
  6dec10:      	adrp	x16, 0x738000
  6dec14:      	ldr	x17, [x16, #0xb28]
  6dec18:      	add	x16, x16, #0xb28
  6dec1c:      	br	x17

00000000006dec20 <x264_8_predict_16x16_dc_neon@plt>:
  6dec20:      	adrp	x16, 0x738000
  6dec24:      	ldr	x17, [x16, #0xb30]
  6dec28:      	add	x16, x16, #0xb30
  6dec2c:      	br	x17

00000000006dec30 <x264_8_sub8x8_dct8_neon@plt>:
  6dec30:      	adrp	x16, 0x738000
  6dec34:      	ldr	x17, [x16, #0xb38]
  6dec38:      	add	x16, x16, #0xb38
  6dec3c:      	br	x17

00000000006dec40 <x264_8_add8x8_idct8_neon@plt>:
  6dec40:      	adrp	x16, 0x738000
  6dec44:      	ldr	x17, [x16, #0xb40]
  6dec48:      	add	x16, x16, #0xb40
  6dec4c:      	br	x17

00000000006dec50 <x264_8_cabac_encode_decision_asm@plt>:
  6dec50:      	adrp	x16, 0x738000
  6dec54:      	ldr	x17, [x16, #0xb48]
  6dec58:      	add	x16, x16, #0xb48
  6dec5c:      	br	x17

00000000006dec60 <x264_8_cabac_encode_bypass_asm@plt>:
  6dec60:      	adrp	x16, 0x738000
  6dec64:      	ldr	x17, [x16, #0xb50]
  6dec68:      	add	x16, x16, #0xb50
  6dec6c:      	br	x17

00000000006dec70 <x264_8_plane_copy_core_neon@plt>:
  6dec70:      	adrp	x16, 0x738000
  6dec74:      	ldr	x17, [x16, #0xb58]
  6dec78:      	add	x16, x16, #0xb58
  6dec7c:      	br	x17

00000000006dec80 <x264_8_plane_copy_swap_core_neon@plt>:
  6dec80:      	adrp	x16, 0x738000
  6dec84:      	ldr	x17, [x16, #0xb60]
  6dec88:      	add	x16, x16, #0xb60
  6dec8c:      	br	x17

00000000006dec90 <x264_8_plane_copy_interleave_core_neon@plt>:
  6dec90:      	adrp	x16, 0x738000
  6dec94:      	ldr	x17, [x16, #0xb68]
  6dec98:      	add	x16, x16, #0xb68
  6dec9c:      	br	x17

00000000006deca0 <x264_8_mbtree_propagate_list_internal_neon@plt>:
  6deca0:      	adrp	x16, 0x738000
  6deca4:      	ldr	x17, [x16, #0xb70]
  6deca8:      	add	x16, x16, #0xb70
  6decac:      	br	x17

00000000006decb0 <x264_10_cabac_encode_terminal_asm@plt>:
  6decb0:      	adrp	x16, 0x738000
  6decb4:      	ldr	x17, [x16, #0xb78]
  6decb8:      	add	x16, x16, #0xb78
  6decbc:      	br	x17

00000000006decc0 <x264_10_cabac_encode_decision_asm@plt>:
  6decc0:      	adrp	x16, 0x738000
  6decc4:      	ldr	x17, [x16, #0xb80]
  6decc8:      	add	x16, x16, #0xb80
  6deccc:      	br	x17

00000000006decd0 <x264_10_cabac_encode_bypass_asm@plt>:
  6decd0:      	adrp	x16, 0x738000
  6decd4:      	ldr	x17, [x16, #0xb88]
  6decd8:      	add	x16, x16, #0xb88
  6decdc:      	br	x17

00000000006dece0 <x264_8_add8x4_idct_neon@plt>:
  6dece0:      	adrp	x16, 0x738000
  6dece4:      	ldr	x17, [x16, #0xb90]
  6dece8:      	add	x16, x16, #0xb90
  6decec:      	br	x17

00000000006decf0 <vprintf@plt>:
  6decf0:      	adrp	x16, 0x738000
  6decf4:      	ldr	x17, [x16, #0xb98]
  6decf8:      	add	x16, x16, #0xb98
  6decfc:      	br	x17

00000000006ded00 <getchar@plt>:
  6ded00:      	adrp	x16, 0x738000
  6ded04:      	ldr	x17, [x16, #0xba0]
  6ded08:      	add	x16, x16, #0xba0
  6ded0c:      	br	x17

00000000006ded10 <vsprintf@plt>:
  6ded10:      	adrp	x16, 0x738000
  6ded14:      	ldr	x17, [x16, #0xba8]
  6ded18:      	add	x16, x16, #0xba8
  6ded1c:      	br	x17

00000000006ded20 <strncpy@plt>:
  6ded20:      	adrp	x16, 0x738000
  6ded24:      	ldr	x17, [x16, #0xbb0]
  6ded28:      	add	x16, x16, #0xbb0
  6ded2c:      	br	x17

00000000006ded30 <fseek@plt>:
  6ded30:      	adrp	x16, 0x738000
  6ded34:      	ldr	x17, [x16, #0xbb8]
  6ded38:      	add	x16, x16, #0xbb8
  6ded3c:      	br	x17

00000000006ded40 <ftell@plt>:
  6ded40:      	adrp	x16, 0x738000
  6ded44:      	ldr	x17, [x16, #0xbc0]
  6ded48:      	add	x16, x16, #0xbc0
  6ded4c:      	br	x17

00000000006ded50 <fflush@plt>:
  6ded50:      	adrp	x16, 0x738000
  6ded54:      	ldr	x17, [x16, #0xbc8]
  6ded58:      	add	x16, x16, #0xbc8
  6ded5c:      	br	x17

00000000006ded60 <fgets@plt>:
  6ded60:      	adrp	x16, 0x738000
  6ded64:      	ldr	x17, [x16, #0xbd0]
  6ded68:      	add	x16, x16, #0xbd0
  6ded6c:      	br	x17

00000000006ded70 <feof@plt>:
  6ded70:      	adrp	x16, 0x738000
  6ded74:      	ldr	x17, [x16, #0xbd8]
  6ded78:      	add	x16, x16, #0xbd8
  6ded7c:      	br	x17

00000000006ded80 <exit@plt>:
  6ded80:      	adrp	x16, 0x738000
  6ded84:      	ldr	x17, [x16, #0xbe0]
  6ded88:      	add	x16, x16, #0xbe0
  6ded8c:      	br	x17

00000000006ded90 <__system_property_get@plt>:
  6ded90:      	adrp	x16, 0x738000
  6ded94:      	ldr	x17, [x16, #0xbe8]
  6ded98:      	add	x16, x16, #0xbe8
  6ded9c:      	br	x17
