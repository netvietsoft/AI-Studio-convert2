// EXPORTED & PLT DISASSEMBLY FOR libPVGCodec.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGCodec.so (SHA-256: 4FA5F275C8DDECF7CAA960C812108EC9E801365BFE5BC9CF38598233BC449FFC)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 551, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libPVGCodec.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000132780 <.plt>:
  132780:      	stp	x16, x30, [sp, #-0x10]!
  132784:      	adrp	x16, 0x13b000
  132788:      	ldr	x17, [x16, #0x3e0]
  13278c:      	add	x16, x16, #0x3e0
  132790:      	br	x17
  132794:      	nop
  132798:      	nop
  13279c:      	nop

00000000001327a0 <__cxa_finalize@plt>:
  1327a0:      	adrp	x16, 0x13b000
  1327a4:      	ldr	x17, [x16, #0x3e8]
  1327a8:      	add	x16, x16, #0x3e8
  1327ac:      	br	x17

00000000001327b0 <__cxa_atexit@plt>:
  1327b0:      	adrp	x16, 0x13b000
  1327b4:      	ldr	x17, [x16, #0x3f0]
  1327b8:      	add	x16, x16, #0x3f0
  1327bc:      	br	x17

00000000001327c0 <_ZNSt6__ndk15mutexD1Ev@plt>:
  1327c0:      	adrp	x16, 0x13b000
  1327c4:      	ldr	x17, [x16, #0x3f8]
  1327c8:      	add	x16, x16, #0x3f8
  1327cc:      	br	x17

00000000001327d0 <_ZdlPv@plt>:
  1327d0:      	adrp	x16, 0x13b000
  1327d4:      	ldr	x17, [x16, #0x400]
  1327d8:      	add	x16, x16, #0x400
  1327dc:      	br	x17

00000000001327e0 <_ZNSt6__ndk15mutex4lockEv@plt>:
  1327e0:      	adrp	x16, 0x13b000
  1327e4:      	ldr	x17, [x16, #0x408]
  1327e8:      	add	x16, x16, #0x408
  1327ec:      	br	x17

00000000001327f0 <_ZNSt6__ndk15mutex6unlockEv@plt>:
  1327f0:      	adrp	x16, 0x13b000
  1327f4:      	ldr	x17, [x16, #0x410]
  1327f8:      	add	x16, x16, #0x410
  1327fc:      	br	x17

0000000000132800 <pthread_self@plt>:
  132800:      	adrp	x16, 0x13b000
  132804:      	ldr	x17, [x16, #0x418]
  132808:      	add	x16, x16, #0x418
  13280c:      	br	x17

0000000000132810 <__android_log_print@plt>:
  132810:      	adrp	x16, 0x13b000
  132814:      	ldr	x17, [x16, #0x420]
  132818:      	add	x16, x16, #0x420
  13281c:      	br	x17

0000000000132820 <_ZN3PVG19logCallbackInternalEiPKcz@plt>:
  132820:      	adrp	x16, 0x13b000
  132824:      	ldr	x17, [x16, #0x428]
  132828:      	add	x16, x16, #0x428
  13282c:      	br	x17

0000000000132830 <usleep@plt>:
  132830:      	adrp	x16, 0x13b000
  132834:      	ldr	x17, [x16, #0x430]
  132838:      	add	x16, x16, #0x430
  13283c:      	br	x17

0000000000132840 <av_free@plt>:
  132840:      	adrp	x16, 0x13b000
  132844:      	ldr	x17, [x16, #0x438]
  132848:      	add	x16, x16, #0x438
  13284c:      	br	x17

0000000000132850 <avio_context_free@plt>:
  132850:      	adrp	x16, 0x13b000
  132854:      	ldr	x17, [x16, #0x440]
  132858:      	add	x16, x16, #0x440
  13285c:      	br	x17

0000000000132860 <__cxa_begin_catch@plt>:
  132860:      	adrp	x16, 0x13b000
  132864:      	ldr	x17, [x16, #0x448]
  132868:      	add	x16, x16, #0x448
  13286c:      	br	x17

0000000000132870 <_ZSt9terminatev@plt>:
  132870:      	adrp	x16, 0x13b000
  132874:      	ldr	x17, [x16, #0x450]
  132878:      	add	x16, x16, #0x450
  13287c:      	br	x17

0000000000132880 <av_malloc@plt>:
  132880:      	adrp	x16, 0x13b000
  132884:      	ldr	x17, [x16, #0x458]
  132888:      	add	x16, x16, #0x458
  13288c:      	br	x17

0000000000132890 <avio_alloc_context@plt>:
  132890:      	adrp	x16, 0x13b000
  132894:      	ldr	x17, [x16, #0x460]
  132898:      	add	x16, x16, #0x460
  13289c:      	br	x17

00000000001328a0 <_Znwm@plt>:
  1328a0:      	adrp	x16, 0x13b000
  1328a4:      	ldr	x17, [x16, #0x468]
  1328a8:      	add	x16, x16, #0x468
  1328ac:      	br	x17

00000000001328b0 <memcpy@plt>:
  1328b0:      	adrp	x16, 0x13b000
  1328b4:      	ldr	x17, [x16, #0x470]
  1328b8:      	add	x16, x16, #0x470
  1328bc:      	br	x17

00000000001328c0 <_ZN3PVG13MediaCombiner7releaseEv@plt>:
  1328c0:      	adrp	x16, 0x13b000
  1328c4:      	ldr	x17, [x16, #0x478]
  1328c8:      	add	x16, x16, #0x478
  1328cc:      	br	x17

00000000001328d0 <av_bsf_free@plt>:
  1328d0:      	adrp	x16, 0x13b000
  1328d4:      	ldr	x17, [x16, #0x480]
  1328d8:      	add	x16, x16, #0x480
  1328dc:      	br	x17

00000000001328e0 <avformat_free_context@plt>:
  1328e0:      	adrp	x16, 0x13b000
  1328e4:      	ldr	x17, [x16, #0x488]
  1328e8:      	add	x16, x16, #0x488
  1328ec:      	br	x17

00000000001328f0 <_ZN3PVG13MediaCombinerD1Ev@plt>:
  1328f0:      	adrp	x16, 0x13b000
  1328f4:      	ldr	x17, [x16, #0x490]
  1328f8:      	add	x16, x16, #0x490
  1328fc:      	br	x17

0000000000132900 <_ZN3PVG13MediaCombiner4initERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_S8_b@plt>:
  132900:      	adrp	x16, 0x13b000
  132904:      	ldr	x17, [x16, #0x498]
  132908:      	add	x16, x16, #0x498
  13290c:      	br	x17

0000000000132910 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  132910:      	adrp	x16, 0x13b000
  132914:      	ldr	x17, [x16, #0x4a0]
  132918:      	add	x16, x16, #0x4a0
  13291c:      	br	x17

0000000000132920 <avformat_find_stream_info@plt>:
  132920:      	adrp	x16, 0x13b000
  132924:      	ldr	x17, [x16, #0x4a8]
  132928:      	add	x16, x16, #0x4a8
  13292c:      	br	x17

0000000000132930 <_ZN3PVG13MediaCombiner12_initOutFileEv@plt>:
  132930:      	adrp	x16, 0x13b000
  132934:      	ldr	x17, [x16, #0x4b0]
  132938:      	add	x16, x16, #0x4b0
  13293c:      	br	x17

0000000000132940 <av_strerror@plt>:
  132940:      	adrp	x16, 0x13b000
  132944:      	ldr	x17, [x16, #0x4b8]
  132948:      	add	x16, x16, #0x4b8
  13294c:      	br	x17

0000000000132950 <av_match_ext@plt>:
  132950:      	adrp	x16, 0x13b000
  132954:      	ldr	x17, [x16, #0x4c0]
  132958:      	add	x16, x16, #0x4c0
  13295c:      	br	x17

0000000000132960 <avformat_alloc_output_context2@plt>:
  132960:      	adrp	x16, 0x13b000
  132964:      	ldr	x17, [x16, #0x4c8]
  132968:      	add	x16, x16, #0x4c8
  13296c:      	br	x17

0000000000132970 <strcpy@plt>:
  132970:      	adrp	x16, 0x13b000
  132974:      	ldr	x17, [x16, #0x4d0]
  132978:      	add	x16, x16, #0x4d0
  13297c:      	br	x17

0000000000132980 <avcodec_parameters_copy@plt>:
  132980:      	adrp	x16, 0x13b000
  132984:      	ldr	x17, [x16, #0x4d8]
  132988:      	add	x16, x16, #0x4d8
  13298c:      	br	x17

0000000000132990 <av_dict_copy@plt>:
  132990:      	adrp	x16, 0x13b000
  132994:      	ldr	x17, [x16, #0x4e0]
  132998:      	add	x16, x16, #0x4e0
  13299c:      	br	x17

00000000001329a0 <avformat_new_stream@plt>:
  1329a0:      	adrp	x16, 0x13b000
  1329a4:      	ldr	x17, [x16, #0x4e8]
  1329a8:      	add	x16, x16, #0x4e8
  1329ac:      	br	x17

00000000001329b0 <avio_open@plt>:
  1329b0:      	adrp	x16, 0x13b000
  1329b4:      	ldr	x17, [x16, #0x4f0]
  1329b8:      	add	x16, x16, #0x4f0
  1329bc:      	br	x17

00000000001329c0 <av_dict_set@plt>:
  1329c0:      	adrp	x16, 0x13b000
  1329c4:      	ldr	x17, [x16, #0x4f8]
  1329c8:      	add	x16, x16, #0x4f8
  1329cc:      	br	x17

00000000001329d0 <avformat_write_header@plt>:
  1329d0:      	adrp	x16, 0x13b000
  1329d4:      	ldr	x17, [x16, #0x500]
  1329d8:      	add	x16, x16, #0x500
  1329dc:      	br	x17

00000000001329e0 <av_dict_free@plt>:
  1329e0:      	adrp	x16, 0x13b000
  1329e4:      	ldr	x17, [x16, #0x508]
  1329e8:      	add	x16, x16, #0x508
  1329ec:      	br	x17

00000000001329f0 <av_bsf_get_by_name@plt>:
  1329f0:      	adrp	x16, 0x13b000
  1329f4:      	ldr	x17, [x16, #0x510]
  1329f8:      	add	x16, x16, #0x510
  1329fc:      	br	x17

0000000000132a00 <av_bsf_alloc@plt>:
  132a00:      	adrp	x16, 0x13b000
  132a04:      	ldr	x17, [x16, #0x518]
  132a08:      	add	x16, x16, #0x518
  132a0c:      	br	x17

0000000000132a10 <__stack_chk_fail@plt>:
  132a10:      	adrp	x16, 0x13b000
  132a14:      	ldr	x17, [x16, #0x520]
  132a18:      	add	x16, x16, #0x520
  132a1c:      	br	x17

0000000000132a20 <_ZN3PVG13MediaCombiner7processEv@plt>:
  132a20:      	adrp	x16, 0x13b000
  132a24:      	ldr	x17, [x16, #0x528]
  132a28:      	add	x16, x16, #0x528
  132a2c:      	br	x17

0000000000132a30 <av_read_frame@plt>:
  132a30:      	adrp	x16, 0x13b000
  132a34:      	ldr	x17, [x16, #0x530]
  132a38:      	add	x16, x16, #0x530
  132a3c:      	br	x17

0000000000132a40 <av_rescale_q_rnd@plt>:
  132a40:      	adrp	x16, 0x13b000
  132a44:      	ldr	x17, [x16, #0x538]
  132a48:      	add	x16, x16, #0x538
  132a4c:      	br	x17

0000000000132a50 <av_packet_unref@plt>:
  132a50:      	adrp	x16, 0x13b000
  132a54:      	ldr	x17, [x16, #0x540]
  132a58:      	add	x16, x16, #0x540
  132a5c:      	br	x17

0000000000132a60 <av_rescale_q@plt>:
  132a60:      	adrp	x16, 0x13b000
  132a64:      	ldr	x17, [x16, #0x548]
  132a68:      	add	x16, x16, #0x548
  132a6c:      	br	x17

0000000000132a70 <av_bsf_send_packet@plt>:
  132a70:      	adrp	x16, 0x13b000
  132a74:      	ldr	x17, [x16, #0x550]
  132a78:      	add	x16, x16, #0x550
  132a7c:      	br	x17

0000000000132a80 <av_bsf_receive_packet@plt>:
  132a80:      	adrp	x16, 0x13b000
  132a84:      	ldr	x17, [x16, #0x558]
  132a88:      	add	x16, x16, #0x558
  132a8c:      	br	x17

0000000000132a90 <avformat_seek_file@plt>:
  132a90:      	adrp	x16, 0x13b000
  132a94:      	ldr	x17, [x16, #0x560]
  132a98:      	add	x16, x16, #0x560
  132a9c:      	br	x17

0000000000132aa0 <av_packet_rescale_ts@plt>:
  132aa0:      	adrp	x16, 0x13b000
  132aa4:      	ldr	x17, [x16, #0x568]
  132aa8:      	add	x16, x16, #0x568
  132aac:      	br	x17

0000000000132ab0 <av_interleaved_write_frame@plt>:
  132ab0:      	adrp	x16, 0x13b000
  132ab4:      	ldr	x17, [x16, #0x570]
  132ab8:      	add	x16, x16, #0x570
  132abc:      	br	x17

0000000000132ac0 <av_get_media_type_string@plt>:
  132ac0:      	adrp	x16, 0x13b000
  132ac4:      	ldr	x17, [x16, #0x578]
  132ac8:      	add	x16, x16, #0x578
  132acc:      	br	x17

0000000000132ad0 <av_write_trailer@plt>:
  132ad0:      	adrp	x16, 0x13b000
  132ad4:      	ldr	x17, [x16, #0x580]
  132ad8:      	add	x16, x16, #0x580
  132adc:      	br	x17

0000000000132ae0 <_ZN3PVG13MediaCombinerC1Ev@plt>:
  132ae0:      	adrp	x16, 0x13b000
  132ae4:      	ldr	x17, [x16, #0x588]
  132ae8:      	add	x16, x16, #0x588
  132aec:      	br	x17

0000000000132af0 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  132af0:      	adrp	x16, 0x13b000
  132af4:      	ldr	x17, [x16, #0x590]
  132af8:      	add	x16, x16, #0x590
  132afc:      	br	x17

0000000000132b00 <_ZN3PVG11MediaConcatD1Ev@plt>:
  132b00:      	adrp	x16, 0x13b000
  132b04:      	ldr	x17, [x16, #0x598]
  132b08:      	add	x16, x16, #0x598
  132b0c:      	br	x17

0000000000132b10 <_ZN3PVG11MediaConcat8addMediaERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  132b10:      	adrp	x16, 0x13b000
  132b14:      	ldr	x17, [x16, #0x5a0]
  132b18:      	add	x16, x16, #0x5a0
  132b1c:      	br	x17

0000000000132b20 <_ZNK3PVG11MediaConcat11getDurationEv@plt>:
  132b20:      	adrp	x16, 0x13b000
  132b24:      	ldr	x17, [x16, #0x5a8]
  132b28:      	add	x16, x16, #0x5a8
  132b2c:      	br	x17

0000000000132b30 <_ZN3PVG11MediaConcat11setListenerENSt6__ndk110shared_ptrINS_11PVGListenerEEE@plt>:
  132b30:      	adrp	x16, 0x13b000
  132b34:      	ldr	x17, [x16, #0x5b0]
  132b38:      	add	x16, x16, #0x5b0
  132b3c:      	br	x17

0000000000132b40 <_ZN3PVG11MediaConcat7processERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  132b40:      	adrp	x16, 0x13b000
  132b44:      	ldr	x17, [x16, #0x5b8]
  132b48:      	add	x16, x16, #0x5b8
  132b4c:      	br	x17

0000000000132b50 <av_packet_alloc@plt>:
  132b50:      	adrp	x16, 0x13b000
  132b54:      	ldr	x17, [x16, #0x5c0]
  132b58:      	add	x16, x16, #0x5c0
  132b5c:      	br	x17

0000000000132b60 <strcmp@plt>:
  132b60:      	adrp	x16, 0x13b000
  132b64:      	ldr	x17, [x16, #0x5c8]
  132b68:      	add	x16, x16, #0x5c8
  132b6c:      	br	x17

0000000000132b70 <av_get_time_base_q@plt>:
  132b70:      	adrp	x16, 0x13b000
  132b74:      	ldr	x17, [x16, #0x5d0]
  132b78:      	add	x16, x16, #0x5d0
  132b7c:      	br	x17

0000000000132b80 <avio_closep@plt>:
  132b80:      	adrp	x16, 0x13b000
  132b84:      	ldr	x17, [x16, #0x5d8]
  132b88:      	add	x16, x16, #0x5d8
  132b8c:      	br	x17

0000000000132b90 <av_packet_free@plt>:
  132b90:      	adrp	x16, 0x13b000
  132b94:      	ldr	x17, [x16, #0x5e0]
  132b98:      	add	x16, x16, #0x5e0
  132b9c:      	br	x17

0000000000132ba0 <__cxa_rethrow@plt>:
  132ba0:      	adrp	x16, 0x13b000
  132ba4:      	ldr	x17, [x16, #0x5e8]
  132ba8:      	add	x16, x16, #0x5e8
  132bac:      	br	x17

0000000000132bb0 <__cxa_end_catch@plt>:
  132bb0:      	adrp	x16, 0x13b000
  132bb4:      	ldr	x17, [x16, #0x5f0]
  132bb8:      	add	x16, x16, #0x5f0
  132bbc:      	br	x17

0000000000132bc0 <_ZN3PVG11MediaConcat5abortEv@plt>:
  132bc0:      	adrp	x16, 0x13b000
  132bc4:      	ldr	x17, [x16, #0x5f8]
  132bc8:      	add	x16, x16, #0x5f8
  132bcc:      	br	x17

0000000000132bd0 <memmove@plt>:
  132bd0:      	adrp	x16, 0x13b000
  132bd4:      	ldr	x17, [x16, #0x600]
  132bd8:      	add	x16, x16, #0x600
  132bdc:      	br	x17

0000000000132be0 <__cxa_allocate_exception@plt>:
  132be0:      	adrp	x16, 0x13b000
  132be4:      	ldr	x17, [x16, #0x608]
  132be8:      	add	x16, x16, #0x608
  132bec:      	br	x17

0000000000132bf0 <__cxa_throw@plt>:
  132bf0:      	adrp	x16, 0x13b000
  132bf4:      	ldr	x17, [x16, #0x610]
  132bf8:      	add	x16, x16, #0x610
  132bfc:      	br	x17

0000000000132c00 <__cxa_free_exception@plt>:
  132c00:      	adrp	x16, 0x13b000
  132c04:      	ldr	x17, [x16, #0x618]
  132c08:      	add	x16, x16, #0x618
  132c0c:      	br	x17

0000000000132c10 <_ZNSt11logic_errorC2EPKc@plt>:
  132c10:      	adrp	x16, 0x13b000
  132c14:      	ldr	x17, [x16, #0x620]
  132c18:      	add	x16, x16, #0x620
  132c1c:      	br	x17

0000000000132c20 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  132c20:      	adrp	x16, 0x13b000
  132c24:      	ldr	x17, [x16, #0x628]
  132c28:      	add	x16, x16, #0x628
  132c2c:      	br	x17

0000000000132c30 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  132c30:      	adrp	x16, 0x13b000
  132c34:      	ldr	x17, [x16, #0x630]
  132c38:      	add	x16, x16, #0x630
  132c3c:      	br	x17

0000000000132c40 <_ZN3PVG11MediaConcatC1Ev@plt>:
  132c40:      	adrp	x16, 0x13b000
  132c44:      	ldr	x17, [x16, #0x638]
  132c48:      	add	x16, x16, #0x638
  132c4c:      	br	x17

0000000000132c50 <avcodec_free_context@plt>:
  132c50:      	adrp	x16, 0x13b000
  132c54:      	ldr	x17, [x16, #0x640]
  132c58:      	add	x16, x16, #0x640
  132c5c:      	br	x17

0000000000132c60 <sws_freeContext@plt>:
  132c60:      	adrp	x16, 0x13b000
  132c64:      	ldr	x17, [x16, #0x648]
  132c68:      	add	x16, x16, #0x648
  132c6c:      	br	x17

0000000000132c70 <_ZN3PVG13MediaReverser13StreamContextD1Ev@plt>:
  132c70:      	adrp	x16, 0x13b000
  132c74:      	ldr	x17, [x16, #0x650]
  132c78:      	add	x16, x16, #0x650
  132c7c:      	br	x17

0000000000132c80 <_ZN3PVG13MediaReverserD1Ev@plt>:
  132c80:      	adrp	x16, 0x13b000
  132c84:      	ldr	x17, [x16, #0x658]
  132c88:      	add	x16, x16, #0x658
  132c8c:      	br	x17

0000000000132c90 <_ZN3PVG13MediaReverser4openERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  132c90:      	adrp	x16, 0x13b000
  132c94:      	ldr	x17, [x16, #0x660]
  132c98:      	add	x16, x16, #0x660
  132c9c:      	br	x17

0000000000132ca0 <_ZN3PVG13MediaReverser5_openEPKcPKhm@plt>:
  132ca0:      	adrp	x16, 0x13b000
  132ca4:      	ldr	x17, [x16, #0x668]
  132ca8:      	add	x16, x16, #0x668
  132cac:      	br	x17

0000000000132cb0 <avcodec_find_decoder@plt>:
  132cb0:      	adrp	x16, 0x13b000
  132cb4:      	ldr	x17, [x16, #0x670]
  132cb8:      	add	x16, x16, #0x670
  132cbc:      	br	x17

0000000000132cc0 <avcodec_alloc_context3@plt>:
  132cc0:      	adrp	x16, 0x13b000
  132cc4:      	ldr	x17, [x16, #0x678]
  132cc8:      	add	x16, x16, #0x678
  132ccc:      	br	x17

0000000000132cd0 <avcodec_parameters_to_context@plt>:
  132cd0:      	adrp	x16, 0x13b000
  132cd4:      	ldr	x17, [x16, #0x680]
  132cd8:      	add	x16, x16, #0x680
  132cdc:      	br	x17

0000000000132ce0 <av_guess_frame_rate@plt>:
  132ce0:      	adrp	x16, 0x13b000
  132ce4:      	ldr	x17, [x16, #0x688]
  132ce8:      	add	x16, x16, #0x688
  132cec:      	br	x17

0000000000132cf0 <avcodec_open2@plt>:
  132cf0:      	adrp	x16, 0x13b000
  132cf4:      	ldr	x17, [x16, #0x690]
  132cf8:      	add	x16, x16, #0x690
  132cfc:      	br	x17

0000000000132d00 <_ZN3PVG13MediaReverser11setListenerENSt6__ndk110shared_ptrINS_11PVGListenerEEE@plt>:
  132d00:      	adrp	x16, 0x13b000
  132d04:      	ldr	x17, [x16, #0x698]
  132d08:      	add	x16, x16, #0x698
  132d0c:      	br	x17

0000000000132d10 <_ZN3PVG13MediaReverser13_getKeyFramesEv@plt>:
  132d10:      	adrp	x16, 0x13b000
  132d14:      	ldr	x17, [x16, #0x6a0]
  132d18:      	add	x16, x16, #0x6a0
  132d1c:      	br	x17

0000000000132d20 <_ZN3PVG13MediaReverser12_decodeFrameEP8AVPacketRKNSt6__ndk14pairIllEES7_RNS3_6vectorI8FrameRefNS3_9allocatorIS9_EEEEP7__sFILE@plt>:
  132d20:      	adrp	x16, 0x13b000
  132d24:      	ldr	x17, [x16, #0x6a8]
  132d28:      	add	x16, x16, #0x6a8
  132d2c:      	br	x17

0000000000132d30 <av_frame_alloc@plt>:
  132d30:      	adrp	x16, 0x13b000
  132d34:      	ldr	x17, [x16, #0x6b0]
  132d38:      	add	x16, x16, #0x6b0
  132d3c:      	br	x17

0000000000132d40 <avcodec_send_packet@plt>:
  132d40:      	adrp	x16, 0x13b000
  132d44:      	ldr	x17, [x16, #0x6b8]
  132d48:      	add	x16, x16, #0x6b8
  132d4c:      	br	x17

0000000000132d50 <avcodec_receive_frame@plt>:
  132d50:      	adrp	x16, 0x13b000
  132d54:      	ldr	x17, [x16, #0x6c0]
  132d58:      	add	x16, x16, #0x6c0
  132d5c:      	br	x17

0000000000132d60 <av_frame_get_buffer@plt>:
  132d60:      	adrp	x16, 0x13b000
  132d64:      	ldr	x17, [x16, #0x6c8]
  132d68:      	add	x16, x16, #0x6c8
  132d6c:      	br	x17

0000000000132d70 <sws_getContext@plt>:
  132d70:      	adrp	x16, 0x13b000
  132d74:      	ldr	x17, [x16, #0x6d0]
  132d78:      	add	x16, x16, #0x6d0
  132d7c:      	br	x17

0000000000132d80 <sws_scale@plt>:
  132d80:      	adrp	x16, 0x13b000
  132d84:      	ldr	x17, [x16, #0x6d8]
  132d88:      	add	x16, x16, #0x6d8
  132d8c:      	br	x17

0000000000132d90 <av_frame_clone@plt>:
  132d90:      	adrp	x16, 0x13b000
  132d94:      	ldr	x17, [x16, #0x6e0]
  132d98:      	add	x16, x16, #0x6e0
  132d9c:      	br	x17

0000000000132da0 <_ZN3PVG13MediaReverser24_serialize_frame_to_fileEP7__sFILEP7AVFrameRlS5_@plt>:
  132da0:      	adrp	x16, 0x13b000
  132da4:      	ldr	x17, [x16, #0x6e8]
  132da8:      	add	x16, x16, #0x6e8
  132dac:      	br	x17

0000000000132db0 <av_frame_free@plt>:
  132db0:      	adrp	x16, 0x13b000
  132db4:      	ldr	x17, [x16, #0x6f0]
  132db8:      	add	x16, x16, #0x6f0
  132dbc:      	br	x17

0000000000132dc0 <av_frame_unref@plt>:
  132dc0:      	adrp	x16, 0x13b000
  132dc4:      	ldr	x17, [x16, #0x6f8]
  132dc8:      	add	x16, x16, #0x6f8
  132dcc:      	br	x17

0000000000132dd0 <av_image_get_buffer_size@plt>:
  132dd0:      	adrp	x16, 0x13b000
  132dd4:      	ldr	x17, [x16, #0x700]
  132dd8:      	add	x16, x16, #0x700
  132ddc:      	br	x17

0000000000132de0 <av_image_copy_to_buffer@plt>:
  132de0:      	adrp	x16, 0x13b000
  132de4:      	ldr	x17, [x16, #0x708]
  132de8:      	add	x16, x16, #0x708
  132dec:      	br	x17

0000000000132df0 <fseeko@plt>:
  132df0:      	adrp	x16, 0x13b000
  132df4:      	ldr	x17, [x16, #0x710]
  132df8:      	add	x16, x16, #0x710
  132dfc:      	br	x17

0000000000132e00 <ftello@plt>:
  132e00:      	adrp	x16, 0x13b000
  132e04:      	ldr	x17, [x16, #0x718]
  132e08:      	add	x16, x16, #0x718
  132e0c:      	br	x17

0000000000132e10 <fwrite@plt>:
  132e10:      	adrp	x16, 0x13b000
  132e14:      	ldr	x17, [x16, #0x720]
  132e18:      	add	x16, x16, #0x720
  132e1c:      	br	x17

0000000000132e20 <ferror@plt>:
  132e20:      	adrp	x16, 0x13b000
  132e24:      	ldr	x17, [x16, #0x728]
  132e28:      	add	x16, x16, #0x728
  132e2c:      	br	x17

0000000000132e30 <__errno@plt>:
  132e30:      	adrp	x16, 0x13b000
  132e34:      	ldr	x17, [x16, #0x730]
  132e38:      	add	x16, x16, #0x730
  132e3c:      	br	x17

0000000000132e40 <fflush@plt>:
  132e40:      	adrp	x16, 0x13b000
  132e44:      	ldr	x17, [x16, #0x738]
  132e48:      	add	x16, x16, #0x738
  132e4c:      	br	x17

0000000000132e50 <_ZN3PVG13MediaReverser15_sectionReverseENSt6__ndk14pairIllEES3_@plt>:
  132e50:      	adrp	x16, 0x13b000
  132e54:      	ldr	x17, [x16, #0x740]
  132e58:      	add	x16, x16, #0x740
  132e5c:      	br	x17

0000000000132e60 <av_seek_frame@plt>:
  132e60:      	adrp	x16, 0x13b000
  132e64:      	ldr	x17, [x16, #0x748]
  132e68:      	add	x16, x16, #0x748
  132e6c:      	br	x17

0000000000132e70 <tmpfile@plt>:
  132e70:      	adrp	x16, 0x13b000
  132e74:      	ldr	x17, [x16, #0x750]
  132e78:      	add	x16, x16, #0x750
  132e7c:      	br	x17

0000000000132e80 <getenv@plt>:
  132e80:      	adrp	x16, 0x13b000
  132e84:      	ldr	x17, [x16, #0x758]
  132e88:      	add	x16, x16, #0x758
  132e8c:      	br	x17

0000000000132e90 <_ZN3PVG9PVGGlobal11getInstanceEv@plt>:
  132e90:      	adrp	x16, 0x13b000
  132e94:      	ldr	x17, [x16, #0x760]
  132e98:      	add	x16, x16, #0x760
  132e9c:      	br	x17

0000000000132ea0 <_ZN3PVG9PVGGlobal17getAndroidContextEv@plt>:
  132ea0:      	adrp	x16, 0x13b000
  132ea4:      	ldr	x17, [x16, #0x768]
  132ea8:      	add	x16, x16, #0x768
  132eac:      	br	x17

0000000000132eb0 <avcodec_flush_buffers@plt>:
  132eb0:      	adrp	x16, 0x13b000
  132eb4:      	ldr	x17, [x16, #0x770]
  132eb8:      	add	x16, x16, #0x770
  132ebc:      	br	x17

0000000000132ec0 <_ZN3PVG13MediaReverser13_frameReverseERNSt6__ndk16vectorI8FrameRefNS1_9allocatorIS3_EEEEP7__sFILE@plt>:
  132ec0:      	adrp	x16, 0x13b000
  132ec4:      	ldr	x17, [x16, #0x778]
  132ec8:      	add	x16, x16, #0x778
  132ecc:      	br	x17

0000000000132ed0 <fclose@plt>:
  132ed0:      	adrp	x16, 0x13b000
  132ed4:      	ldr	x17, [x16, #0x780]
  132ed8:      	add	x16, x16, #0x780
  132edc:      	br	x17

0000000000132ee0 <memcmp@plt>:
  132ee0:      	adrp	x16, 0x13b000
  132ee4:      	ldr	x17, [x16, #0x788]
  132ee8:      	add	x16, x16, #0x788
  132eec:      	br	x17

0000000000132ef0 <stat@plt>:
  132ef0:      	adrp	x16, 0x13b000
  132ef4:      	ldr	x17, [x16, #0x790]
  132ef8:      	add	x16, x16, #0x790
  132efc:      	br	x17

0000000000132f00 <access@plt>:
  132f00:      	adrp	x16, 0x13b000
  132f04:      	ldr	x17, [x16, #0x798]
  132f08:      	add	x16, x16, #0x798
  132f0c:      	br	x17

0000000000132f10 <memset@plt>:
  132f10:      	adrp	x16, 0x13b000
  132f14:      	ldr	x17, [x16, #0x7a0]
  132f18:      	add	x16, x16, #0x7a0
  132f1c:      	br	x17

0000000000132f20 <mkstemp@plt>:
  132f20:      	adrp	x16, 0x13b000
  132f24:      	ldr	x17, [x16, #0x7a8]
  132f28:      	add	x16, x16, #0x7a8
  132f2c:      	br	x17

0000000000132f30 <unlink@plt>:
  132f30:      	adrp	x16, 0x13b000
  132f34:      	ldr	x17, [x16, #0x7b0]
  132f38:      	add	x16, x16, #0x7b0
  132f3c:      	br	x17

0000000000132f40 <fdopen@plt>:
  132f40:      	adrp	x16, 0x13b000
  132f44:      	ldr	x17, [x16, #0x7b8]
  132f48:      	add	x16, x16, #0x7b8
  132f4c:      	br	x17

0000000000132f50 <close@plt>:
  132f50:      	adrp	x16, 0x13b000
  132f54:      	ldr	x17, [x16, #0x7c0]
  132f58:      	add	x16, x16, #0x7c0
  132f5c:      	br	x17

0000000000132f60 <strerror@plt>:
  132f60:      	adrp	x16, 0x13b000
  132f64:      	ldr	x17, [x16, #0x7c8]
  132f68:      	add	x16, x16, #0x7c8
  132f6c:      	br	x17

0000000000132f70 <_ZN3PVG13MediaReverser28_deserialize_frame_from_fileEP7__sFILElPP7AVFrame@plt>:
  132f70:      	adrp	x16, 0x13b000
  132f74:      	ldr	x17, [x16, #0x7d0]
  132f78:      	add	x16, x16, #0x7d0
  132f7c:      	br	x17

0000000000132f80 <_ZN3PVG13MediaReverser17_encodeWriteFrameEP7AVFramej@plt>:
  132f80:      	adrp	x16, 0x13b000
  132f84:      	ldr	x17, [x16, #0x7d8]
  132f88:      	add	x16, x16, #0x7d8
  132f8c:      	br	x17

0000000000132f90 <fread@plt>:
  132f90:      	adrp	x16, 0x13b000
  132f94:      	ldr	x17, [x16, #0x7e0]
  132f98:      	add	x16, x16, #0x7e0
  132f9c:      	br	x17

0000000000132fa0 <feof@plt>:
  132fa0:      	adrp	x16, 0x13b000
  132fa4:      	ldr	x17, [x16, #0x7e8]
  132fa8:      	add	x16, x16, #0x7e8
  132fac:      	br	x17

0000000000132fb0 <av_buffer_create@plt>:
  132fb0:      	adrp	x16, 0x13b000
  132fb4:      	ldr	x17, [x16, #0x7f0]
  132fb8:      	add	x16, x16, #0x7f0
  132fbc:      	br	x17

0000000000132fc0 <av_image_fill_arrays@plt>:
  132fc0:      	adrp	x16, 0x13b000
  132fc4:      	ldr	x17, [x16, #0x7f8]
  132fc8:      	add	x16, x16, #0x7f8
  132fcc:      	br	x17

0000000000132fd0 <av_buffer_unref@plt>:
  132fd0:      	adrp	x16, 0x13b000
  132fd4:      	ldr	x17, [x16, #0x800]
  132fd8:      	add	x16, x16, #0x800
  132fdc:      	br	x17

0000000000132fe0 <avcodec_send_frame@plt>:
  132fe0:      	adrp	x16, 0x13b000
  132fe4:      	ldr	x17, [x16, #0x808]
  132fe8:      	add	x16, x16, #0x808
  132fec:      	br	x17

0000000000132ff0 <avcodec_receive_packet@plt>:
  132ff0:      	adrp	x16, 0x13b000
  132ff4:      	ldr	x17, [x16, #0x810]
  132ff8:      	add	x16, x16, #0x810
  132ffc:      	br	x17

0000000000133000 <_ZN8PVGCOLOR17PVGColorFunctions9transcodeEPKPKhPKiPKPhS6_@plt>:
  133000:      	adrp	x16, 0x13b000
  133004:      	ldr	x17, [x16, #0x818]
  133008:      	add	x16, x16, #0x818
  13300c:      	br	x17

0000000000133010 <_ZN3PVG13MediaReverser7processERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133010:      	adrp	x16, 0x13b000
  133014:      	ldr	x17, [x16, #0x820]
  133018:      	add	x16, x16, #0x820
  13301c:      	br	x17

0000000000133020 <_ZN3PVG13MediaReverser15_openOutputFileEPKc@plt>:
  133020:      	adrp	x16, 0x13b000
  133024:      	ldr	x17, [x16, #0x828]
  133028:      	add	x16, x16, #0x828
  13302c:      	br	x17

0000000000133030 <_ZN8PVGVIDEO6PVGRef7releaseEv@plt>:
  133030:      	adrp	x16, 0x13b000
  133034:      	ldr	x17, [x16, #0x830]
  133038:      	add	x16, x16, #0x830
  13303c:      	br	x17

0000000000133040 <_ZN3PVG13MediaReverser17_openVideoEncoderEP8AVStreamRP14AVCodecContextPK7AVCodecRP12AVDictionaryj@plt>:
  133040:      	adrp	x16, 0x13b000
  133044:      	ldr	x17, [x16, #0x838]
  133048:      	add	x16, x16, #0x838
  13304c:      	br	x17

0000000000133050 <av_channel_layout_copy@plt>:
  133050:      	adrp	x16, 0x13b000
  133054:      	ldr	x17, [x16, #0x840]
  133058:      	add	x16, x16, #0x840
  13305c:      	br	x17

0000000000133060 <avcodec_find_encoder@plt>:
  133060:      	adrp	x16, 0x13b000
  133064:      	ldr	x17, [x16, #0x848]
  133068:      	add	x16, x16, #0x848
  13306c:      	br	x17

0000000000133070 <av_stream_new_side_data@plt>:
  133070:      	adrp	x16, 0x13b000
  133074:      	ldr	x17, [x16, #0x850]
  133078:      	add	x16, x16, #0x850
  13307c:      	br	x17

0000000000133080 <avcodec_get_supported_config@plt>:
  133080:      	adrp	x16, 0x13b000
  133084:      	ldr	x17, [x16, #0x858]
  133088:      	add	x16, x16, #0x858
  13308c:      	br	x17

0000000000133090 <av_opt_set@plt>:
  133090:      	adrp	x16, 0x13b000
  133094:      	ldr	x17, [x16, #0x860]
  133098:      	add	x16, x16, #0x860
  13309c:      	br	x17

00000000001330a0 <_ZN3PVG13MediaReverser5abortEv@plt>:
  1330a0:      	adrp	x16, 0x13b000
  1330a4:      	ldr	x17, [x16, #0x868]
  1330a8:      	add	x16, x16, #0x868
  1330ac:      	br	x17

00000000001330b0 <avcodec_parameters_from_context@plt>:
  1330b0:      	adrp	x16, 0x13b000
  1330b4:      	ldr	x17, [x16, #0x870]
  1330b8:      	add	x16, x16, #0x870
  1330bc:      	br	x17

00000000001330c0 <strlen@plt>:
  1330c0:      	adrp	x16, 0x13b000
  1330c4:      	ldr	x17, [x16, #0x878]
  1330c8:      	add	x16, x16, #0x878
  1330cc:      	br	x17

00000000001330d0 <vsnprintf@plt>:
  1330d0:      	adrp	x16, 0x13b000
  1330d4:      	ldr	x17, [x16, #0x880]
  1330d8:      	add	x16, x16, #0x880
  1330dc:      	br	x17

00000000001330e0 <_ZN3PVG13MediaReverserC1Ev@plt>:
  1330e0:      	adrp	x16, 0x13b000
  1330e4:      	ldr	x17, [x16, #0x888]
  1330e8:      	add	x16, x16, #0x888
  1330ec:      	br	x17

00000000001330f0 <_ZnwmRKSt9nothrow_t@plt>:
  1330f0:      	adrp	x16, 0x13b000
  1330f4:      	ldr	x17, [x16, #0x890]
  1330f8:      	add	x16, x16, #0x890
  1330fc:      	br	x17

0000000000133100 <_ZN3PVG15PVGAudioDecoder20setAudioOutParameterEiiNS_9PVGFormatE@plt>:
  133100:      	adrp	x16, 0x13b000
  133104:      	ldr	x17, [x16, #0x898]
  133108:      	add	x16, x16, #0x898
  13310c:      	br	x17

0000000000133110 <_ZN3PVG15PVGAudioDecoder22setEnablePositiveValueEb@plt>:
  133110:      	adrp	x16, 0x13b000
  133114:      	ldr	x17, [x16, #0x8a0]
  133118:      	add	x16, x16, #0x8a0
  13311c:      	br	x17

0000000000133120 <_ZN3PVG15PVGAudioDecoder21setAudioSmoothingTimeEd@plt>:
  133120:      	adrp	x16, 0x13b000
  133124:      	ldr	x17, [x16, #0x8a8]
  133128:      	add	x16, x16, #0x8a8
  13312c:      	br	x17

0000000000133130 <_ZN3PVG15PVGAudioDecoder20setAudioDecoderParamEdd@plt>:
  133130:      	adrp	x16, 0x13b000
  133134:      	ldr	x17, [x16, #0x8b0]
  133138:      	add	x16, x16, #0x8b0
  13313c:      	br	x17

0000000000133140 <_ZN3PVG15PVGAudioDecoder4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133140:      	adrp	x16, 0x13b000
  133144:      	ldr	x17, [x16, #0x8b8]
  133148:      	add	x16, x16, #0x8b8
  13314c:      	br	x17

0000000000133150 <_ZN3PVG15PVGAudioDecoder5closeEv@plt>:
  133150:      	adrp	x16, 0x13b000
  133154:      	ldr	x17, [x16, #0x8c0]
  133158:      	add	x16, x16, #0x8c0
  13315c:      	br	x17

0000000000133160 <_ZN3PVG15PVGAudioDecoder8getAudioIhEENSt6__ndk16vectorIT_NS2_9allocatorIS4_EEEEv@plt>:
  133160:      	adrp	x16, 0x13b000
  133164:      	ldr	x17, [x16, #0x8c8]
  133168:      	add	x16, x16, #0x8c8
  13316c:      	br	x17

0000000000133170 <av_get_bytes_per_sample@plt>:
  133170:      	adrp	x16, 0x13b000
  133174:      	ldr	x17, [x16, #0x8d0]
  133178:      	add	x16, x16, #0x8d0
  13317c:      	br	x17

0000000000133180 <_ZN3PVG15PVGAudioDecoder16getAudioFrameS16Ev@plt>:
  133180:      	adrp	x16, 0x13b000
  133184:      	ldr	x17, [x16, #0x8d8]
  133188:      	add	x16, x16, #0x8d8
  13318c:      	br	x17

0000000000133190 <_ZN3PVG15PVGAudioDecoder8getAudioIsEENSt6__ndk16vectorIT_NS2_9allocatorIS4_EEEEv@plt>:
  133190:      	adrp	x16, 0x13b000
  133194:      	ldr	x17, [x16, #0x8e0]
  133198:      	add	x16, x16, #0x8e0
  13319c:      	br	x17

00000000001331a0 <_ZN3PVG15PVGAudioDecoder8getAudioIiEENSt6__ndk16vectorIT_NS2_9allocatorIS4_EEEEv@plt>:
  1331a0:      	adrp	x16, 0x13b000
  1331a4:      	ldr	x17, [x16, #0x8e8]
  1331a8:      	add	x16, x16, #0x8e8
  1331ac:      	br	x17

00000000001331b0 <_ZN3PVG15PVGAudioDecoder8getAudioIfEENSt6__ndk16vectorIT_NS2_9allocatorIS4_EEEEv@plt>:
  1331b0:      	adrp	x16, 0x13b000
  1331b4:      	ldr	x17, [x16, #0x8f0]
  1331b8:      	add	x16, x16, #0x8f0
  1331bc:      	br	x17

00000000001331c0 <_ZN3PVG15PVGAudioDecoder8getAudioIdEENSt6__ndk16vectorIT_NS2_9allocatorIS4_EEEEv@plt>:
  1331c0:      	adrp	x16, 0x13b000
  1331c4:      	ldr	x17, [x16, #0x8f8]
  1331c8:      	add	x16, x16, #0x8f8
  1331cc:      	br	x17

00000000001331d0 <_ZN3PVG15PVGAudioDecoderD1Ev@plt>:
  1331d0:      	adrp	x16, 0x13b000
  1331d4:      	ldr	x17, [x16, #0x900]
  1331d8:      	add	x16, x16, #0x900
  1331dc:      	br	x17

00000000001331e0 <_ZN3PVG6PVGRef7releaseEv@plt>:
  1331e0:      	adrp	x16, 0x13b000
  1331e4:      	ldr	x17, [x16, #0x908]
  1331e8:      	add	x16, x16, #0x908
  1331ec:      	br	x17

00000000001331f0 <_ZN3PVG17PVGAudioExtractorD1Ev@plt>:
  1331f0:      	adrp	x16, 0x13b000
  1331f4:      	ldr	x17, [x16, #0x910]
  1331f8:      	add	x16, x16, #0x910
  1331fc:      	br	x17

0000000000133200 <_ZN3PVG17PVGAudioExtractor13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133200:      	adrp	x16, 0x13b000
  133204:      	ldr	x17, [x16, #0x918]
  133208:      	add	x16, x16, #0x918
  13320c:      	br	x17

0000000000133210 <_ZN3PVG17PVGAudioExtractor7processERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133210:      	adrp	x16, 0x13b000
  133214:      	ldr	x17, [x16, #0x920]
  133218:      	add	x16, x16, #0x920
  13321c:      	br	x17

0000000000133220 <_ZN3PVG17PVGAudioTranscode6createEv@plt>:
  133220:      	adrp	x16, 0x13b000
  133224:      	ldr	x17, [x16, #0x928]
  133228:      	add	x16, x16, #0x928
  13322c:      	br	x17

0000000000133230 <_ZN3PVG17PVGAudioTranscode4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133230:      	adrp	x16, 0x13b000
  133234:      	ldr	x17, [x16, #0x930]
  133238:      	add	x16, x16, #0x930
  13323c:      	br	x17

0000000000133240 <_ZN3PVG17PVGAudioTranscodeD1Ev@plt>:
  133240:      	adrp	x16, 0x13b000
  133244:      	ldr	x17, [x16, #0x938]
  133248:      	add	x16, x16, #0x938
  13324c:      	br	x17

0000000000133250 <_ZN3PVG17PVGAudioTranscode13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133250:      	adrp	x16, 0x13b000
  133254:      	ldr	x17, [x16, #0x940]
  133258:      	add	x16, x16, #0x940
  13325c:      	br	x17

0000000000133260 <_ZN3PVG17PVGAudioTranscode9transcodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133260:      	adrp	x16, 0x13b000
  133264:      	ldr	x17, [x16, #0x948]
  133268:      	add	x16, x16, #0x948
  13326c:      	br	x17

0000000000133270 <_ZN3PVG17PVGAudioTranscode5closeEv@plt>:
  133270:      	adrp	x16, 0x13b000
  133274:      	ldr	x17, [x16, #0x950]
  133278:      	add	x16, x16, #0x950
  13327c:      	br	x17

0000000000133280 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERd@plt>:
  133280:      	adrp	x16, 0x13b000
  133284:      	ldr	x17, [x16, #0x958]
  133288:      	add	x16, x16, #0x958
  13328c:      	br	x17

0000000000133290 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
  133290:      	adrp	x16, 0x13b000
  133294:      	ldr	x17, [x16, #0x960]
  133298:      	add	x16, x16, #0x960
  13329c:      	br	x17

00000000001332a0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
  1332a0:      	adrp	x16, 0x13b000
  1332a4:      	ldr	x17, [x16, #0x968]
  1332a8:      	add	x16, x16, #0x968
  1332ac:      	br	x17

00000000001332b0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  1332b0:      	adrp	x16, 0x13b000
  1332b4:      	ldr	x17, [x16, #0x970]
  1332b8:      	add	x16, x16, #0x970
  1332bc:      	br	x17

00000000001332c0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
  1332c0:      	adrp	x16, 0x13b000
  1332c4:      	ldr	x17, [x16, #0x978]
  1332c8:      	add	x16, x16, #0x978
  1332cc:      	br	x17

00000000001332d0 <av_channel_layout_default@plt>:
  1332d0:      	adrp	x16, 0x13b000
  1332d4:      	ldr	x17, [x16, #0x980]
  1332d8:      	add	x16, x16, #0x980
  1332dc:      	br	x17

00000000001332e0 <av_channel_layout_uninit@plt>:
  1332e0:      	adrp	x16, 0x13b000
  1332e4:      	ldr	x17, [x16, #0x988]
  1332e8:      	add	x16, x16, #0x988
  1332ec:      	br	x17

00000000001332f0 <swr_alloc_set_opts2@plt>:
  1332f0:      	adrp	x16, 0x13b000
  1332f4:      	ldr	x17, [x16, #0x990]
  1332f8:      	add	x16, x16, #0x990
  1332fc:      	br	x17

0000000000133300 <swr_init@plt>:
  133300:      	adrp	x16, 0x13b000
  133304:      	ldr	x17, [x16, #0x998]
  133308:      	add	x16, x16, #0x998
  13330c:      	br	x17

0000000000133310 <av_audio_fifo_alloc@plt>:
  133310:      	adrp	x16, 0x13b000
  133314:      	ldr	x17, [x16, #0x9a0]
  133318:      	add	x16, x16, #0x9a0
  13331c:      	br	x17

0000000000133320 <av_audio_fifo_size@plt>:
  133320:      	adrp	x16, 0x13b000
  133324:      	ldr	x17, [x16, #0x9a8]
  133328:      	add	x16, x16, #0x9a8
  13332c:      	br	x17

0000000000133330 <av_audio_fifo_read@plt>:
  133330:      	adrp	x16, 0x13b000
  133334:      	ldr	x17, [x16, #0x9b0]
  133338:      	add	x16, x16, #0x9b0
  13333c:      	br	x17

0000000000133340 <swr_free@plt>:
  133340:      	adrp	x16, 0x13b000
  133344:      	ldr	x17, [x16, #0x9b8]
  133348:      	add	x16, x16, #0x9b8
  13334c:      	br	x17

0000000000133350 <av_audio_fifo_free@plt>:
  133350:      	adrp	x16, 0x13b000
  133354:      	ldr	x17, [x16, #0x9c0]
  133358:      	add	x16, x16, #0x9c0
  13335c:      	br	x17

0000000000133360 <swr_get_delay@plt>:
  133360:      	adrp	x16, 0x13b000
  133364:      	ldr	x17, [x16, #0x9c8]
  133368:      	add	x16, x16, #0x9c8
  13336c:      	br	x17

0000000000133370 <av_rescale_rnd@plt>:
  133370:      	adrp	x16, 0x13b000
  133374:      	ldr	x17, [x16, #0x9d0]
  133378:      	add	x16, x16, #0x9d0
  13337c:      	br	x17

0000000000133380 <swr_convert@plt>:
  133380:      	adrp	x16, 0x13b000
  133384:      	ldr	x17, [x16, #0x9d8]
  133388:      	add	x16, x16, #0x9d8
  13338c:      	br	x17

0000000000133390 <av_audio_fifo_realloc@plt>:
  133390:      	adrp	x16, 0x13b000
  133394:      	ldr	x17, [x16, #0x9e0]
  133398:      	add	x16, x16, #0x9e0
  13339c:      	br	x17

00000000001333a0 <av_audio_fifo_write@plt>:
  1333a0:      	adrp	x16, 0x13b000
  1333a4:      	ldr	x17, [x16, #0x9e8]
  1333a8:      	add	x16, x16, #0x9e8
  1333ac:      	br	x17

00000000001333b0 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  1333b0:      	adrp	x16, 0x13b000
  1333b4:      	ldr	x17, [x16, #0x9f0]
  1333b8:      	add	x16, x16, #0x9f0
  1333bc:      	br	x17

00000000001333c0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  1333c0:      	adrp	x16, 0x13b000
  1333c4:      	ldr	x17, [x16, #0x9f8]
  1333c8:      	add	x16, x16, #0x9f8
  1333cc:      	br	x17

00000000001333d0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEd@plt>:
  1333d0:      	adrp	x16, 0x13b000
  1333d4:      	ldr	x17, [x16, #0xa00]
  1333d8:      	add	x16, x16, #0xa00
  1333dc:      	br	x17

00000000001333e0 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
  1333e0:      	adrp	x16, 0x13b000
  1333e4:      	ldr	x17, [x16, #0xa08]
  1333e8:      	add	x16, x16, #0xa08
  1333ec:      	br	x17

00000000001333f0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  1333f0:      	adrp	x16, 0x13b000
  1333f4:      	ldr	x17, [x16, #0xa10]
  1333f8:      	add	x16, x16, #0xa10
  1333fc:      	br	x17

0000000000133400 <_ZN3PVG17PVGAudioExtractor5abortEv@plt>:
  133400:      	adrp	x16, 0x13b000
  133404:      	ldr	x17, [x16, #0xa18]
  133408:      	add	x16, x16, #0xa18
  13340c:      	br	x17

0000000000133410 <_ZN3PVG17PVGAudioTranscode5abortEv@plt>:
  133410:      	adrp	x16, 0x13b000
  133414:      	ldr	x17, [x16, #0xa20]
  133418:      	add	x16, x16, #0xa20
  13341c:      	br	x17

0000000000133420 <_ZN3PVG17PVGAudioExtractor19setProgressListenerEPNS_11PVGListenerE@plt>:
  133420:      	adrp	x16, 0x13b000
  133424:      	ldr	x17, [x16, #0xa28]
  133428:      	add	x16, x16, #0xa28
  13342c:      	br	x17

0000000000133430 <_ZN3PVG6PVGRef6retainEv@plt>:
  133430:      	adrp	x16, 0x13b000
  133434:      	ldr	x17, [x16, #0xa30]
  133438:      	add	x16, x16, #0xa30
  13343c:      	br	x17

0000000000133440 <_ZNSt6__ndk112__next_primeEm@plt>:
  133440:      	adrp	x16, 0x13b000
  133444:      	ldr	x17, [x16, #0xa38]
  133448:      	add	x16, x16, #0xa38
  13344c:      	br	x17

0000000000133450 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  133450:      	adrp	x16, 0x13b000
  133454:      	ldr	x17, [x16, #0xa40]
  133458:      	add	x16, x16, #0xa40
  13345c:      	br	x17

0000000000133460 <_ZN3PVG17PVGAudioExtractorC1Ev@plt>:
  133460:      	adrp	x16, 0x13b000
  133464:      	ldr	x17, [x16, #0xa48]
  133468:      	add	x16, x16, #0xa48
  13346c:      	br	x17

0000000000133470 <_ZN3PVG22PVGAudioNoiseReduction4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133470:      	adrp	x16, 0x13b000
  133474:      	ldr	x17, [x16, #0xa50]
  133478:      	add	x16, x16, #0xa50
  13347c:      	br	x17

0000000000133480 <_ZN8PVGVIDEO13PVGVideoCodec6createENS_12PVGCodecTypeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
  133480:      	adrp	x16, 0x13b000
  133484:      	ldr	x17, [x16, #0xa58]
  133488:      	add	x16, x16, #0xa58
  13348c:      	br	x17

0000000000133490 <_ZN8PVGVIDEO12PVGAudioInfo5validEv@plt>:
  133490:      	adrp	x16, 0x13b000
  133494:      	ldr	x17, [x16, #0xa60]
  133498:      	add	x16, x16, #0xa60
  13349c:      	br	x17

00000000001334a0 <_ZN8PVGVIDEO10PVGContextC1Ev@plt>:
  1334a0:      	adrp	x16, 0x13b000
  1334a4:      	ldr	x17, [x16, #0xa68]
  1334a8:      	add	x16, x16, #0xa68
  1334ac:      	br	x17

00000000001334b0 <_ZN8PVGVIDEO10PVGContext16setCodecStrategyENS_16PVGCodecStrategyE@plt>:
  1334b0:      	adrp	x16, 0x13b000
  1334b4:      	ldr	x17, [x16, #0xa70]
  1334b8:      	add	x16, x16, #0xa70
  1334bc:      	br	x17

00000000001334c0 <_ZN8PVGVIDEO10PVGContext14setCodecParamsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  1334c0:      	adrp	x16, 0x13b000
  1334c4:      	ldr	x17, [x16, #0xa78]
  1334c8:      	add	x16, x16, #0xa78
  1334cc:      	br	x17

00000000001334d0 <_ZN3PVG22PVGAudioNoiseReduction19setProgressListenerEPNS_11PVGListenerE@plt>:
  1334d0:      	adrp	x16, 0x13b000
  1334d4:      	ldr	x17, [x16, #0xa80]
  1334d8:      	add	x16, x16, #0xa80
  1334dc:      	br	x17

00000000001334e0 <_ZN3PVG6PVGRefC2Ev@plt>:
  1334e0:      	adrp	x16, 0x13b000
  1334e4:      	ldr	x17, [x16, #0xa88]
  1334e8:      	add	x16, x16, #0xa88
  1334ec:      	br	x17

00000000001334f0 <_ZN3PVG22PVGAudioNoiseReduction13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  1334f0:      	adrp	x16, 0x13b000
  1334f4:      	ldr	x17, [x16, #0xa90]
  1334f8:      	add	x16, x16, #0xa90
  1334fc:      	br	x17

0000000000133500 <_ZN3PVG22PVGAudioNoiseReduction16noiseSuppressionERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133500:      	adrp	x16, 0x13b000
  133504:      	ldr	x17, [x16, #0xa98]
  133508:      	add	x16, x16, #0xa98
  13350c:      	br	x17

0000000000133510 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERl@plt>:
  133510:      	adrp	x16, 0x13b000
  133514:      	ldr	x17, [x16, #0xaa0]
  133518:      	add	x16, x16, #0xaa0
  13351c:      	br	x17

0000000000133520 <__memcpy_chk@plt>:
  133520:      	adrp	x16, 0x13b000
  133524:      	ldr	x17, [x16, #0xaa8]
  133528:      	add	x16, x16, #0xaa8
  13352c:      	br	x17

0000000000133530 <_ZN8PVGVIDEO10PVGContext27setExpectedInputAudioFormatENS_9PVGFormatE@plt>:
  133530:      	adrp	x16, 0x13b000
  133534:      	ldr	x17, [x16, #0xab0]
  133538:      	add	x16, x16, #0xab0
  13353c:      	br	x17

0000000000133540 <_ZN8PVGVIDEO10PVGContext19setInputAudioFormatEii@plt>:
  133540:      	adrp	x16, 0x13b000
  133544:      	ldr	x17, [x16, #0xab8]
  133548:      	add	x16, x16, #0xab8
  13354c:      	br	x17

0000000000133550 <_ZN8PVGVIDEO10PVGContext15setAudioBitrateEl@plt>:
  133550:      	adrp	x16, 0x13b000
  133554:      	ldr	x17, [x16, #0xac0]
  133558:      	add	x16, x16, #0xac0
  13355c:      	br	x17

0000000000133560 <av_sample_fmt_is_planar@plt>:
  133560:      	adrp	x16, 0x13b000
  133564:      	ldr	x17, [x16, #0xac8]
  133568:      	add	x16, x16, #0xac8
  13356c:      	br	x17

0000000000133570 <_ZnamRKSt9nothrow_t@plt>:
  133570:      	adrp	x16, 0x13b000
  133574:      	ldr	x17, [x16, #0xad0]
  133578:      	add	x16, x16, #0xad0
  13357c:      	br	x17

0000000000133580 <_ZNK8PVGVIDEO13PVGAudioFrame12getSamplesNbEv@plt>:
  133580:      	adrp	x16, 0x13b000
  133584:      	ldr	x17, [x16, #0xad8]
  133588:      	add	x16, x16, #0xad8
  13358c:      	br	x17

0000000000133590 <_ZN8PVGVIDEO14PVGPCMTransfer4readEPPhPii@plt>:
  133590:      	adrp	x16, 0x13b000
  133594:      	ldr	x17, [x16, #0xae0]
  133598:      	add	x16, x16, #0xae0
  13359c:      	br	x17

00000000001335a0 <_ZdaPv@plt>:
  1335a0:      	adrp	x16, 0x13b000
  1335a4:      	ldr	x17, [x16, #0xae8]
  1335a8:      	add	x16, x16, #0xae8
  1335ac:      	br	x17

00000000001335b0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi@plt>:
  1335b0:      	adrp	x16, 0x13b000
  1335b4:      	ldr	x17, [x16, #0xaf0]
  1335b8:      	add	x16, x16, #0xaf0
  1335bc:      	br	x17

00000000001335c0 <_ZN8PVGVIDEO14PVGPCMTransferC1Ev@plt>:
  1335c0:      	adrp	x16, 0x13b000
  1335c4:      	ldr	x17, [x16, #0xaf8]
  1335c8:      	add	x16, x16, #0xaf8
  1335cc:      	br	x17

00000000001335d0 <_ZN8PVGVIDEO14PVGPCMTransfer4initENS_9PVGFormatEiiS1_ii@plt>:
  1335d0:      	adrp	x16, 0x13b000
  1335d4:      	ldr	x17, [x16, #0xb00]
  1335d8:      	add	x16, x16, #0xb00
  1335dc:      	br	x17

00000000001335e0 <_ZdlPvRKSt9nothrow_t@plt>:
  1335e0:      	adrp	x16, 0x13b000
  1335e4:      	ldr	x17, [x16, #0xb08]
  1335e8:      	add	x16, x16, #0xb08
  1335ec:      	br	x17

00000000001335f0 <_ZN8PVGVIDEO14PVGPCMTransfer5writeEPPhi@plt>:
  1335f0:      	adrp	x16, 0x13b000
  1335f4:      	ldr	x17, [x16, #0xb10]
  1335f8:      	add	x16, x16, #0xb10
  1335fc:      	br	x17

0000000000133600 <_ZN8PVGVIDEO14PVGPCMTransfer4readEPPhPi@plt>:
  133600:      	adrp	x16, 0x13b000
  133604:      	ldr	x17, [x16, #0xb18]
  133608:      	add	x16, x16, #0xb18
  13360c:      	br	x17

0000000000133610 <_ZN3PVG6PVGRefD2Ev@plt>:
  133610:      	adrp	x16, 0x13b000
  133614:      	ldr	x17, [x16, #0xb20]
  133618:      	add	x16, x16, #0xb20
  13361c:      	br	x17

0000000000133620 <_ZN3PVG22PVGAudioNoiseReductionD1Ev@plt>:
  133620:      	adrp	x16, 0x13b000
  133624:      	ldr	x17, [x16, #0xb28]
  133628:      	add	x16, x16, #0xb28
  13362c:      	br	x17

0000000000133630 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
  133630:      	adrp	x16, 0x13b000
  133634:      	ldr	x17, [x16, #0xb30]
  133638:      	add	x16, x16, #0xb30
  13363c:      	br	x17

0000000000133640 <_ZN8PVGVIDEO14queryPVGReturnENS_9PVGReturnE@plt>:
  133640:      	adrp	x16, 0x13b000
  133644:      	ldr	x17, [x16, #0xb38]
  133648:      	add	x16, x16, #0xb38
  13364c:      	br	x17

0000000000133650 <_ZN3PVG25PVGAudioWaveformGeneratorC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133650:      	adrp	x16, 0x13b000
  133654:      	ldr	x17, [x16, #0xb40]
  133658:      	add	x16, x16, #0xb40
  13365c:      	br	x17

0000000000133660 <log10f@plt>:
  133660:      	adrp	x16, 0x13b000
  133664:      	ldr	x17, [x16, #0xb48]
  133668:      	add	x16, x16, #0xb48
  13366c:      	br	x17

0000000000133670 <_ZN8PVGVIDEO13PVGVideoCodec13createDecoderEPKhm@plt>:
  133670:      	adrp	x16, 0x13b000
  133674:      	ldr	x17, [x16, #0xb50]
  133678:      	add	x16, x16, #0xb50
  13367c:      	br	x17

0000000000133680 <_ZN8PVGVIDEO12PVGVideoInfo5validEv@plt>:
  133680:      	adrp	x16, 0x13b000
  133684:      	ldr	x17, [x16, #0xb58]
  133688:      	add	x16, x16, #0xb58
  13368c:      	br	x17

0000000000133690 <PVGCCodecCreateDecoder@plt>:
  133690:      	adrp	x16, 0x13b000
  133694:      	ldr	x17, [x16, #0xb60]
  133698:      	add	x16, x16, #0xb60
  13369c:      	br	x17

00000000001336a0 <PVGCCodecRelease@plt>:
  1336a0:      	adrp	x16, 0x13b000
  1336a4:      	ldr	x17, [x16, #0xb68]
  1336a8:      	add	x16, x16, #0xb68
  1336ac:      	br	x17

00000000001336b0 <PVGCCodecGetMediaInfo@plt>:
  1336b0:      	adrp	x16, 0x13b000
  1336b4:      	ldr	x17, [x16, #0xb70]
  1336b8:      	add	x16, x16, #0xb70
  1336bc:      	br	x17

00000000001336c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  1336c0:      	adrp	x16, 0x13b000
  1336c4:      	ldr	x17, [x16, #0xb78]
  1336c8:      	add	x16, x16, #0xb78
  1336cc:      	br	x17

00000000001336d0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
  1336d0:      	adrp	x16, 0x13b000
  1336d4:      	ldr	x17, [x16, #0xb80]
  1336d8:      	add	x16, x16, #0xb80
  1336dc:      	br	x17

00000000001336e0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEf@plt>:
  1336e0:      	adrp	x16, 0x13b000
  1336e4:      	ldr	x17, [x16, #0xb88]
  1336e8:      	add	x16, x16, #0xb88
  1336ec:      	br	x17

00000000001336f0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
  1336f0:      	adrp	x16, 0x13b000
  1336f4:      	ldr	x17, [x16, #0xb90]
  1336f8:      	add	x16, x16, #0xb90
  1336fc:      	br	x17

0000000000133700 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  133700:      	adrp	x16, 0x13b000
  133704:      	ldr	x17, [x16, #0xb98]
  133708:      	add	x16, x16, #0xb98
  13370c:      	br	x17

0000000000133710 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEb@plt>:
  133710:      	adrp	x16, 0x13b000
  133714:      	ldr	x17, [x16, #0xba0]
  133718:      	add	x16, x16, #0xba0
  13371c:      	br	x17

0000000000133720 <PVGCCodecSetParams@plt>:
  133720:      	adrp	x16, 0x13b000
  133724:      	ldr	x17, [x16, #0xba8]
  133728:      	add	x16, x16, #0xba8
  13372c:      	br	x17

0000000000133730 <_ZN8PVGVIDEO10PVGContext17setInputDimensionEii@plt>:
  133730:      	adrp	x16, 0x13b000
  133734:      	ldr	x17, [x16, #0xbb0]
  133738:      	add	x16, x16, #0xbb0
  13373c:      	br	x17

0000000000133740 <_ZN8PVGVIDEO10PVGContext27setExpectedInputVideoFormatENS_9PVGFormatE@plt>:
  133740:      	adrp	x16, 0x13b000
  133744:      	ldr	x17, [x16, #0xbb8]
  133748:      	add	x16, x16, #0xbb8
  13374c:      	br	x17

0000000000133750 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERf@plt>:
  133750:      	adrp	x16, 0x13b000
  133754:      	ldr	x17, [x16, #0xbc0]
  133758:      	add	x16, x16, #0xbc0
  13375c:      	br	x17

0000000000133760 <_ZN8PVGVIDEO10PVGContext12setFramerateEf@plt>:
  133760:      	adrp	x16, 0x13b000
  133764:      	ldr	x17, [x16, #0xbc8]
  133768:      	add	x16, x16, #0xbc8
  13376c:      	br	x17

0000000000133770 <_ZN8PVGVIDEO10PVGContext10setGOPSizeEi@plt>:
  133770:      	adrp	x16, 0x13b000
  133774:      	ldr	x17, [x16, #0xbd0]
  133778:      	add	x16, x16, #0xbd0
  13377c:      	br	x17

0000000000133780 <_ZN8PVGVIDEO10PVGContext15setVideoBitrateEl@plt>:
  133780:      	adrp	x16, 0x13b000
  133784:      	ldr	x17, [x16, #0xbd8]
  133788:      	add	x16, x16, #0xbd8
  13378c:      	br	x17

0000000000133790 <_ZN8PVGVIDEO10PVGContext10setProfileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133790:      	adrp	x16, 0x13b000
  133794:      	ldr	x17, [x16, #0xbe0]
  133798:      	add	x16, x16, #0xbe0
  13379c:      	br	x17

00000000001337a0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4findEcm@plt>:
  1337a0:      	adrp	x16, 0x13b000
  1337a4:      	ldr	x17, [x16, #0xbe8]
  1337a8:      	add	x16, x16, #0xbe8
  1337ac:      	br	x17

00000000001337b0 <_ZN8PVGVIDEO10PVGContext11addMetadataERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  1337b0:      	adrp	x16, 0x13b000
  1337b4:      	ldr	x17, [x16, #0xbf0]
  1337b8:      	add	x16, x16, #0xbf0
  1337bc:      	br	x17

00000000001337c0 <_ZN8PVGVIDEO10PVGContext6setDarENS_11PVGRationalE@plt>:
  1337c0:      	adrp	x16, 0x13b000
  1337c4:      	ldr	x17, [x16, #0xbf8]
  1337c8:      	add	x16, x16, #0xbf8
  1337cc:      	br	x17

00000000001337d0 <PVGCCodecStart@plt>:
  1337d0:      	adrp	x16, 0x13b000
  1337d4:      	ldr	x17, [x16, #0xc00]
  1337d8:      	add	x16, x16, #0xc00
  1337dc:      	br	x17

00000000001337e0 <eglGetCurrentContext@plt>:
  1337e0:      	adrp	x16, 0x13b000
  1337e4:      	ldr	x17, [x16, #0xc08]
  1337e8:      	add	x16, x16, #0xc08
  1337ec:      	br	x17

00000000001337f0 <eglGetCurrentDisplay@plt>:
  1337f0:      	adrp	x16, 0x13b000
  1337f4:      	ldr	x17, [x16, #0xc10]
  1337f8:      	add	x16, x16, #0xc10
  1337fc:      	br	x17

0000000000133800 <_ZN8PVGVIDEO12PVGHWContextC1ENS_16PVGHWContextTypeE@plt>:
  133800:      	adrp	x16, 0x13b000
  133804:      	ldr	x17, [x16, #0xc18]
  133808:      	add	x16, x16, #0xc18
  13380c:      	br	x17

0000000000133810 <_ZN8PVGVIDEO10PVGContext12setHWContextEPNS_12PVGHWContextE@plt>:
  133810:      	adrp	x16, 0x13b000
  133814:      	ldr	x17, [x16, #0xc20]
  133818:      	add	x16, x16, #0xc20
  13381c:      	br	x17

0000000000133820 <glDeleteTextures@plt>:
  133820:      	adrp	x16, 0x13b000
  133824:      	ldr	x17, [x16, #0xc28]
  133828:      	add	x16, x16, #0xc28
  13382c:      	br	x17

0000000000133830 <PVGCCodecStop@plt>:
  133830:      	adrp	x16, 0x13b000
  133834:      	ldr	x17, [x16, #0xc30]
  133838:      	add	x16, x16, #0xc30
  13383c:      	br	x17

0000000000133840 <_ZN8PVGVIDEO14PVGPCMTransfer7restartEv@plt>:
  133840:      	adrp	x16, 0x13b000
  133844:      	ldr	x17, [x16, #0xc38]
  133848:      	add	x16, x16, #0xc38
  13384c:      	br	x17

0000000000133850 <PVGCCodecCleanup@plt>:
  133850:      	adrp	x16, 0x13b000
  133854:      	ldr	x17, [x16, #0xc40]
  133858:      	add	x16, x16, #0xc40
  13385c:      	br	x17

0000000000133860 <_ZN8PVGCOLOR17PVGColorFunctions7cleanupEv@plt>:
  133860:      	adrp	x16, 0x13b000
  133864:      	ldr	x17, [x16, #0xc48]
  133868:      	add	x16, x16, #0xc48
  13386c:      	br	x17

0000000000133870 <av_samples_get_buffer_size@plt>:
  133870:      	adrp	x16, 0x13b000
  133874:      	ldr	x17, [x16, #0xc50]
  133878:      	add	x16, x16, #0xc50
  13387c:      	br	x17

0000000000133880 <av_samples_fill_arrays@plt>:
  133880:      	adrp	x16, 0x13b000
  133884:      	ldr	x17, [x16, #0xc58]
  133888:      	add	x16, x16, #0xc58
  13388c:      	br	x17

0000000000133890 <PVGCCodecReleaseFrame@plt>:
  133890:      	adrp	x16, 0x13b000
  133894:      	ldr	x17, [x16, #0xc60]
  133898:      	add	x16, x16, #0xc60
  13389c:      	br	x17

00000000001338a0 <_ZN8PVGCOLOR17PVGColorFunctions6createEiiNS_14PVGPixelFormatEiiS1_@plt>:
  1338a0:      	adrp	x16, 0x13b000
  1338a4:      	ldr	x17, [x16, #0xc68]
  1338a8:      	add	x16, x16, #0xc68
  1338ac:      	br	x17

00000000001338b0 <_ZN8PVGCOLOR17PVGColorFunctions12setHWContextERKNS_12PVGHWContextE@plt>:
  1338b0:      	adrp	x16, 0x13b000
  1338b4:      	ldr	x17, [x16, #0xc70]
  1338b8:      	add	x16, x16, #0xc70
  1338bc:      	br	x17

00000000001338c0 <_ZN8PVGCOLOR17PVGColorFunctions20setColorspaceDetailsENS_17PVGColorPrimariesENS_16PVGColorTransferENS_14PVGColorMatrixENS_13PVGColorRangeES1_S2_S3_S4_@plt>:
  1338c0:      	adrp	x16, 0x13b000
  1338c4:      	ldr	x17, [x16, #0xc78]
  1338c8:      	add	x16, x16, #0xc78
  1338cc:      	br	x17

00000000001338d0 <_ZN8PVGCOLOR17PVGColorFunctions11setMetaDataEPKcS2_@plt>:
  1338d0:      	adrp	x16, 0x13b000
  1338d4:      	ldr	x17, [x16, #0xc80]
  1338d8:      	add	x16, x16, #0xc80
  1338dc:      	br	x17

00000000001338e0 <_ZN8PVGCOLOR9PVGOpenGL15createTexture2DEiii@plt>:
  1338e0:      	adrp	x16, 0x13b000
  1338e4:      	ldr	x17, [x16, #0xc88]
  1338e8:      	add	x16, x16, #0xc88
  1338ec:      	br	x17

00000000001338f0 <_ZN8PVGCOLOR14queryPVGReturnENS_9PVGReturnE@plt>:
  1338f0:      	adrp	x16, 0x13b000
  1338f4:      	ldr	x17, [x16, #0xc90]
  1338f8:      	add	x16, x16, #0xc90
  1338fc:      	br	x17

0000000000133900 <glFlush@plt>:
  133900:      	adrp	x16, 0x13b000
  133904:      	ldr	x17, [x16, #0xc98]
  133908:      	add	x16, x16, #0xc98
  13390c:      	br	x17

0000000000133910 <PVGCCodecReceiveFrame@plt>:
  133910:      	adrp	x16, 0x13b000
  133914:      	ldr	x17, [x16, #0xca0]
  133918:      	add	x16, x16, #0xca0
  13391c:      	br	x17

0000000000133920 <_ZN8PVGVIDEO13PVGAudioFrame6createEv@plt>:
  133920:      	adrp	x16, 0x13b000
  133924:      	ldr	x17, [x16, #0xca8]
  133928:      	add	x16, x16, #0xca8
  13392c:      	br	x17

0000000000133930 <_ZN8PVGVIDEO13PVGVideoFrame6createEv@plt>:
  133930:      	adrp	x16, 0x13b000
  133934:      	ldr	x17, [x16, #0xcb0]
  133938:      	add	x16, x16, #0xcb0
  13393c:      	br	x17

0000000000133940 <_ZN3PVG14PVGGifMetaDataC1Ev@plt>:
  133940:      	adrp	x16, 0x13b000
  133944:      	ldr	x17, [x16, #0xcb8]
  133948:      	add	x16, x16, #0xcb8
  13394c:      	br	x17

0000000000133950 <_ZN3PVG14PVGGifMetaData13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133950:      	adrp	x16, 0x13b000
  133954:      	ldr	x17, [x16, #0xcc0]
  133958:      	add	x16, x16, #0xcc0
  13395c:      	br	x17

0000000000133960 <_ZN3PVG14PVGGifMetaData9transcodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133960:      	adrp	x16, 0x13b000
  133964:      	ldr	x17, [x16, #0xcc8]
  133968:      	add	x16, x16, #0xcc8
  13396c:      	br	x17

0000000000133970 <_ZNSt6__ndk19to_stringEd@plt>:
  133970:      	adrp	x16, 0x13b000
  133974:      	ldr	x17, [x16, #0xcd0]
  133978:      	add	x16, x16, #0xcd0
  13397c:      	br	x17

0000000000133980 <avformat_alloc_context@plt>:
  133980:      	adrp	x16, 0x13b000
  133984:      	ldr	x17, [x16, #0xcd8]
  133988:      	add	x16, x16, #0xcd8
  13398c:      	br	x17

0000000000133990 <avformat_open_input@plt>:
  133990:      	adrp	x16, 0x13b000
  133994:      	ldr	x17, [x16, #0xce0]
  133998:      	add	x16, x16, #0xce0
  13399c:      	br	x17

00000000001339a0 <avformat_close_input@plt>:
  1339a0:      	adrp	x16, 0x13b000
  1339a4:      	ldr	x17, [x16, #0xce8]
  1339a8:      	add	x16, x16, #0xce8
  1339ac:      	br	x17

00000000001339b0 <malloc@plt>:
  1339b0:      	adrp	x16, 0x13b000
  1339b4:      	ldr	x17, [x16, #0xcf0]
  1339b8:      	add	x16, x16, #0xcf0
  1339bc:      	br	x17

00000000001339c0 <av_dict_get@plt>:
  1339c0:      	adrp	x16, 0x13b000
  1339c4:      	ldr	x17, [x16, #0xcf8]
  1339c8:      	add	x16, x16, #0xcf8
  1339cc:      	br	x17

00000000001339d0 <av_packet_side_data_get@plt>:
  1339d0:      	adrp	x16, 0x13b000
  1339d4:      	ldr	x17, [x16, #0xd00]
  1339d8:      	add	x16, x16, #0xd00
  1339dc:      	br	x17

00000000001339e0 <av_strtod@plt>:
  1339e0:      	adrp	x16, 0x13b000
  1339e4:      	ldr	x17, [x16, #0xd08]
  1339e8:      	add	x16, x16, #0xd08
  1339ec:      	br	x17

00000000001339f0 <hypot@plt>:
  1339f0:      	adrp	x16, 0x13b000
  1339f4:      	ldr	x17, [x16, #0xd10]
  1339f8:      	add	x16, x16, #0xd10
  1339fc:      	br	x17

0000000000133a00 <atan2@plt>:
  133a00:      	adrp	x16, 0x13b000
  133a04:      	ldr	x17, [x16, #0xd18]
  133a08:      	add	x16, x16, #0xd18
  133a0c:      	br	x17

0000000000133a10 <PVGCFrameGetPlaneCount@plt>:
  133a10:      	adrp	x16, 0x13b000
  133a14:      	ldr	x17, [x16, #0xd20]
  133a18:      	add	x16, x16, #0xd20
  133a1c:      	br	x17

0000000000133a20 <PVGCFrameGetPlaneData@plt>:
  133a20:      	adrp	x16, 0x13b000
  133a24:      	ldr	x17, [x16, #0xd28]
  133a28:      	add	x16, x16, #0xd28
  133a2c:      	br	x17

0000000000133a30 <PVGCFrameGetPlaneLinesize@plt>:
  133a30:      	adrp	x16, 0x13b000
  133a34:      	ldr	x17, [x16, #0xd30]
  133a38:      	add	x16, x16, #0xd30
  133a3c:      	br	x17

0000000000133a40 <av_find_best_stream@plt>:
  133a40:      	adrp	x16, 0x13b000
  133a44:      	ldr	x17, [x16, #0xd38]
  133a48:      	add	x16, x16, #0xd38
  133a4c:      	br	x17

0000000000133a50 <av_init_packet@plt>:
  133a50:      	adrp	x16, 0x13b000
  133a54:      	ldr	x17, [x16, #0xd40]
  133a58:      	add	x16, x16, #0xd40
  133a5c:      	br	x17

0000000000133a60 <getRealDuration@plt>:
  133a60:      	adrp	x16, 0x13b000
  133a64:      	ldr	x17, [x16, #0xd48]
  133a68:      	add	x16, x16, #0xd48
  133a6c:      	br	x17

0000000000133a70 <PVGCheckIsAudioFile@plt>:
  133a70:      	adrp	x16, 0x13b000
  133a74:      	ldr	x17, [x16, #0xd50]
  133a78:      	add	x16, x16, #0xd50
  133a7c:      	br	x17

0000000000133a80 <_ZN3PVG9PVGGlobal11setLogLevelENS_11PVGLogLevelE@plt>:
  133a80:      	adrp	x16, 0x13b000
  133a84:      	ldr	x17, [x16, #0xd58]
  133a88:      	add	x16, x16, #0xd58
  133a8c:      	br	x17

0000000000133a90 <_ZNSt9exceptionD2Ev@plt>:
  133a90:      	adrp	x16, 0x13b000
  133a94:      	ldr	x17, [x16, #0xd60]
  133a98:      	add	x16, x16, #0xd60
  133a9c:      	br	x17

0000000000133aa0 <PVGCMetadataMapFree@plt>:
  133aa0:      	adrp	x16, 0x13b000
  133aa4:      	ldr	x17, [x16, #0xd68]
  133aa8:      	add	x16, x16, #0xd68
  133aac:      	br	x17

0000000000133ab0 <_ZN3PVG15PVGVideoToImage6createEv@plt>:
  133ab0:      	adrp	x16, 0x13b000
  133ab4:      	ldr	x17, [x16, #0xd70]
  133ab8:      	add	x16, x16, #0xd70
  133abc:      	br	x17

0000000000133ac0 <_ZN3PVG15PVGVideoToImage19setProgressListenerEPNS_11PVGListenerE@plt>:
  133ac0:      	adrp	x16, 0x13b000
  133ac4:      	ldr	x17, [x16, #0xd78]
  133ac8:      	add	x16, x16, #0xd78
  133acc:      	br	x17

0000000000133ad0 <_ZN3PVG15PVGVideoToImage13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133ad0:      	adrp	x16, 0x13b000
  133ad4:      	ldr	x17, [x16, #0xd80]
  133ad8:      	add	x16, x16, #0xd80
  133adc:      	br	x17

0000000000133ae0 <_ZN3PVG15PVGVideoToImage4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133ae0:      	adrp	x16, 0x13b000
  133ae4:      	ldr	x17, [x16, #0xd88]
  133ae8:      	add	x16, x16, #0xd88
  133aec:      	br	x17

0000000000133af0 <_ZN3PVG15PVGVideoToImage9transcodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133af0:      	adrp	x16, 0x13b000
  133af4:      	ldr	x17, [x16, #0xd90]
  133af8:      	add	x16, x16, #0xd90
  133afc:      	br	x17

0000000000133b00 <_ZN3PVG15PVGVideoToImage5abortEv@plt>:
  133b00:      	adrp	x16, 0x13b000
  133b04:      	ldr	x17, [x16, #0xd98]
  133b08:      	add	x16, x16, #0xd98
  133b0c:      	br	x17

0000000000133b10 <_ZN3PVG15PVGVideoToImage5closeEv@plt>:
  133b10:      	adrp	x16, 0x13b000
  133b14:      	ldr	x17, [x16, #0xda0]
  133b18:      	add	x16, x16, #0xda0
  133b1c:      	br	x17

0000000000133b20 <_ZN3PVG8PVGCodec6createENS_7PVGTypeE@plt>:
  133b20:      	adrp	x16, 0x13b000
  133b24:      	ldr	x17, [x16, #0xda8]
  133b28:      	add	x16, x16, #0xda8
  133b2c:      	br	x17

0000000000133b30 <_ZN3PVG8PVGCodecC1ENS_7PVGTypeE@plt>:
  133b30:      	adrp	x16, 0x13b000
  133b34:      	ldr	x17, [x16, #0xdb0]
  133b38:      	add	x16, x16, #0xdb0
  133b3c:      	br	x17

0000000000133b40 <_ZN3PVG8PVGCodec13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133b40:      	adrp	x16, 0x13b000
  133b44:      	ldr	x17, [x16, #0xdb8]
  133b48:      	add	x16, x16, #0xdb8
  133b4c:      	br	x17

0000000000133b50 <_ZN8PVGVIDEO9PVGGlobal11getInstanceEv@plt>:
  133b50:      	adrp	x16, 0x13b000
  133b54:      	ldr	x17, [x16, #0xdc0]
  133b58:      	add	x16, x16, #0xdc0
  133b5c:      	br	x17

0000000000133b60 <_ZN8PVGVIDEO9PVGGlobal11setLogLevelENS_11PVGLogLevelE@plt>:
  133b60:      	adrp	x16, 0x13b000
  133b64:      	ldr	x17, [x16, #0xdc8]
  133b68:      	add	x16, x16, #0xdc8
  133b6c:      	br	x17

0000000000133b70 <_ZN3PVG8PVGCodec17getInputMediaInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133b70:      	adrp	x16, 0x13b000
  133b74:      	ldr	x17, [x16, #0xdd0]
  133b78:      	add	x16, x16, #0xdd0
  133b7c:      	br	x17

0000000000133b80 <_ZN3PVG8PVGCodec4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133b80:      	adrp	x16, 0x13b000
  133b84:      	ldr	x17, [x16, #0xdd8]
  133b88:      	add	x16, x16, #0xdd8
  133b8c:      	br	x17

0000000000133b90 <_ZN8PVGVIDEO13PVGVideoCodec6createENS_12PVGCodecTypeERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPPS0_PNS_12PVGErrorInfoE@plt>:
  133b90:      	adrp	x16, 0x13b000
  133b94:      	ldr	x17, [x16, #0xde0]
  133b98:      	add	x16, x16, #0xde0
  133b9c:      	br	x17

0000000000133ba0 <_ZN8PVGVIDEO13PVGVideoCodec13createDecoderEPKhmPPS0_PNS_12PVGErrorInfoE@plt>:
  133ba0:      	adrp	x16, 0x13b000
  133ba4:      	ldr	x17, [x16, #0xde8]
  133ba8:      	add	x16, x16, #0xde8
  133bac:      	br	x17

0000000000133bb0 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
  133bb0:      	adrp	x16, 0x13b000
  133bb4:      	ldr	x17, [x16, #0xdf0]
  133bb8:      	add	x16, x16, #0xdf0
  133bbc:      	br	x17

0000000000133bc0 <_ZN3PVG8PVGCodec16processAudioFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133bc0:      	adrp	x16, 0x13b000
  133bc4:      	ldr	x17, [x16, #0xdf8]
  133bc8:      	add	x16, x16, #0xdf8
  133bcc:      	br	x17

0000000000133bd0 <_ZN3PVG8PVGCodec9transcodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133bd0:      	adrp	x16, 0x13b000
  133bd4:      	ldr	x17, [x16, #0xe00]
  133bd8:      	add	x16, x16, #0xe00
  133bdc:      	br	x17

0000000000133be0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
  133be0:      	adrp	x16, 0x13b000
  133be4:      	ldr	x17, [x16, #0xe08]
  133be8:      	add	x16, x16, #0xe08
  133bec:      	br	x17

0000000000133bf0 <pthread_create@plt>:
  133bf0:      	adrp	x16, 0x13b000
  133bf4:      	ldr	x17, [x16, #0xe10]
  133bf8:      	add	x16, x16, #0xe10
  133bfc:      	br	x17

0000000000133c00 <_ZNSt6__ndk16thread4joinEv@plt>:
  133c00:      	adrp	x16, 0x13b000
  133c04:      	ldr	x17, [x16, #0xe18]
  133c08:      	add	x16, x16, #0xe18
  133c0c:      	br	x17

0000000000133c10 <_ZNSt6__ndk16threadD1Ev@plt>:
  133c10:      	adrp	x16, 0x13b000
  133c14:      	ldr	x17, [x16, #0xe20]
  133c18:      	add	x16, x16, #0xe20
  133c1c:      	br	x17

0000000000133c20 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
  133c20:      	adrp	x16, 0x13b000
  133c24:      	ldr	x17, [x16, #0xe28]
  133c28:      	add	x16, x16, #0xe28
  133c2c:      	br	x17

0000000000133c30 <_ZN3PVG8PVGCodec12seekGetFrameEd@plt>:
  133c30:      	adrp	x16, 0x13b000
  133c34:      	ldr	x17, [x16, #0xe30]
  133c38:      	add	x16, x16, #0xe30
  133c3c:      	br	x17

0000000000133c40 <free@plt>:
  133c40:      	adrp	x16, 0x13b000
  133c44:      	ldr	x17, [x16, #0xe38]
  133c48:      	add	x16, x16, #0xe38
  133c4c:      	br	x17

0000000000133c50 <_ZN3PVG8PVGCodec13startGetFrameEiPiS1_@plt>:
  133c50:      	adrp	x16, 0x13b000
  133c54:      	ldr	x17, [x16, #0xe40]
  133c58:      	add	x16, x16, #0xe40
  133c5c:      	br	x17

0000000000133c60 <_ZN3PVG8PVGCodec8getFrameEdPPhPiPd@plt>:
  133c60:      	adrp	x16, 0x13b000
  133c64:      	ldr	x17, [x16, #0xe48]
  133c68:      	add	x16, x16, #0xe48
  133c6c:      	br	x17

0000000000133c70 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
  133c70:      	adrp	x16, 0x13b000
  133c74:      	ldr	x17, [x16, #0xe50]
  133c78:      	add	x16, x16, #0xe50
  133c7c:      	br	x17

0000000000133c80 <_ZN3PVG8PVGCodec5closeEv@plt>:
  133c80:      	adrp	x16, 0x13b000
  133c84:      	ldr	x17, [x16, #0xe58]
  133c88:      	add	x16, x16, #0xe58
  133c8c:      	br	x17

0000000000133c90 <_ZN3PVG8PVGCodec5abortEv@plt>:
  133c90:      	adrp	x16, 0x13b000
  133c94:      	ldr	x17, [x16, #0xe60]
  133c98:      	add	x16, x16, #0xe60
  133c9c:      	br	x17

0000000000133ca0 <_ZN3PVG8PVGCodec19setProgressListenerEPNS_11PVGListenerE@plt>:
  133ca0:      	adrp	x16, 0x13b000
  133ca4:      	ldr	x17, [x16, #0xe68]
  133ca8:      	add	x16, x16, #0xe68
  133cac:      	br	x17

0000000000133cb0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
  133cb0:      	adrp	x16, 0x13b000
  133cb4:      	ldr	x17, [x16, #0xe70]
  133cb8:      	add	x16, x16, #0xe70
  133cbc:      	br	x17

0000000000133cc0 <_ZN3PVG8PVGCodecD1Ev@plt>:
  133cc0:      	adrp	x16, 0x13b000
  133cc4:      	ldr	x17, [x16, #0xe78]
  133cc8:      	add	x16, x16, #0xe78
  133ccc:      	br	x17

0000000000133cd0 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
  133cd0:      	adrp	x16, 0x13b000
  133cd4:      	ldr	x17, [x16, #0xe80]
  133cd8:      	add	x16, x16, #0xe80
  133cdc:      	br	x17

0000000000133ce0 <pthread_setspecific@plt>:
  133ce0:      	adrp	x16, 0x13b000
  133ce4:      	ldr	x17, [x16, #0xe88]
  133ce8:      	add	x16, x16, #0xe88
  133cec:      	br	x17

0000000000133cf0 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
  133cf0:      	adrp	x16, 0x13b000
  133cf4:      	ldr	x17, [x16, #0xe90]
  133cf8:      	add	x16, x16, #0xe90
  133cfc:      	br	x17

0000000000133d00 <_ZNSt13exception_ptrD1Ev@plt>:
  133d00:      	adrp	x16, 0x13b000
  133d04:      	ldr	x17, [x16, #0xe98]
  133d08:      	add	x16, x16, #0xe98
  133d0c:      	br	x17

0000000000133d10 <_ZNSt6__ndk115future_categoryEv@plt>:
  133d10:      	adrp	x16, 0x13b000
  133d14:      	ldr	x17, [x16, #0xea0]
  133d18:      	add	x16, x16, #0xea0
  133d1c:      	br	x17

0000000000133d20 <_ZNSt6__ndk112future_errorC1ENS_10error_codeE@plt>:
  133d20:      	adrp	x16, 0x13b000
  133d24:      	ldr	x17, [x16, #0xea8]
  133d28:      	add	x16, x16, #0xea8
  133d2c:      	br	x17

0000000000133d30 <_ZNSt11logic_errorC2ERKS_@plt>:
  133d30:      	adrp	x16, 0x13b000
  133d34:      	ldr	x17, [x16, #0xeb0]
  133d38:      	add	x16, x16, #0xeb0
  133d3c:      	br	x17

0000000000133d40 <_ZNSt6__ndk112future_errorD1Ev@plt>:
  133d40:      	adrp	x16, 0x13b000
  133d44:      	ldr	x17, [x16, #0xeb8]
  133d48:      	add	x16, x16, #0xeb8
  133d4c:      	br	x17

0000000000133d50 <_ZSt17current_exceptionv@plt>:
  133d50:      	adrp	x16, 0x13b000
  133d54:      	ldr	x17, [x16, #0xec0]
  133d58:      	add	x16, x16, #0xec0
  133d5c:      	br	x17

0000000000133d60 <_ZNSt6__ndk117__assoc_sub_state13set_exceptionESt13exception_ptr@plt>:
  133d60:      	adrp	x16, 0x13b000
  133d64:      	ldr	x17, [x16, #0xec8]
  133d68:      	add	x16, x16, #0xec8
  133d6c:      	br	x17

0000000000133d70 <_ZNSt6__ndk114__shared_countD2Ev@plt>:
  133d70:      	adrp	x16, 0x13b000
  133d74:      	ldr	x17, [x16, #0xed0]
  133d78:      	add	x16, x16, #0xed0
  133d7c:      	br	x17

0000000000133d80 <_ZN8PVGCOLOR9PVGOpenGL15createGLContextEPPvS2_S2_S2_S1_@plt>:
  133d80:      	adrp	x16, 0x13b000
  133d84:      	ldr	x17, [x16, #0xed8]
  133d88:      	add	x16, x16, #0xed8
  133d8c:      	br	x17

0000000000133d90 <_ZN8PVGCOLOR9PVGOpenGL18makeCurrentContextEPvS1_S1_S1_@plt>:
  133d90:      	adrp	x16, 0x13b000
  133d94:      	ldr	x17, [x16, #0xee0]
  133d98:      	add	x16, x16, #0xee0
  133d9c:      	br	x17

0000000000133da0 <memchr@plt>:
  133da0:      	adrp	x16, 0x13b000
  133da4:      	ldr	x17, [x16, #0xee8]
  133da8:      	add	x16, x16, #0xee8
  133dac:      	br	x17

0000000000133db0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5eraseEmm@plt>:
  133db0:      	adrp	x16, 0x13b000
  133db4:      	ldr	x17, [x16, #0xef0]
  133db8:      	add	x16, x16, #0xef0
  133dbc:      	br	x17

0000000000133dc0 <_ZNK8PVGVIDEO13PVGVideoFrame27getMasteringDisplayMetadataEv@plt>:
  133dc0:      	adrp	x16, 0x13b000
  133dc4:      	ldr	x17, [x16, #0xef8]
  133dc8:      	add	x16, x16, #0xef8
  133dcc:      	br	x17

0000000000133dd0 <_ZN8PVGVIDEO10PVGContext27setMasteringDisplayMetadataERKNS_24MasteringDisplayMetadataE@plt>:
  133dd0:      	adrp	x16, 0x13b000
  133dd4:      	ldr	x17, [x16, #0xf00]
  133dd8:      	add	x16, x16, #0xf00
  133ddc:      	br	x17

0000000000133de0 <_ZNK8PVGVIDEO13PVGVideoFrame23getContentLightMetadataEv@plt>:
  133de0:      	adrp	x16, 0x13b000
  133de4:      	ldr	x17, [x16, #0xf08]
  133de8:      	add	x16, x16, #0xf08
  133dec:      	br	x17

0000000000133df0 <_ZN8PVGVIDEO10PVGContext23setContentLightMetadataERKNS_20ContentLightMetadataE@plt>:
  133df0:      	adrp	x16, 0x13b000
  133df4:      	ldr	x17, [x16, #0xf10]
  133df8:      	add	x16, x16, #0xf10
  133dfc:      	br	x17

0000000000133e00 <_ZN8PVGVIDEO10PVGContext28setAmbientViewingEnvironmentERKNS_25AmbientViewingEnvironmentE@plt>:
  133e00:      	adrp	x16, 0x13b000
  133e04:      	ldr	x17, [x16, #0xf18]
  133e08:      	add	x16, x16, #0xf18
  133e0c:      	br	x17

0000000000133e10 <_ZNK8PVGVIDEO8PVGFrame30getPrimalPresentationTimestampEv@plt>:
  133e10:      	adrp	x16, 0x13b000
  133e14:      	ldr	x17, [x16, #0xf20]
  133e18:      	add	x16, x16, #0xf20
  133e1c:      	br	x17

0000000000133e20 <_ZN8PVGCOLOR17PVGColorFunctions9setHWSyncEb@plt>:
  133e20:      	adrp	x16, 0x13b000
  133e24:      	ldr	x17, [x16, #0xf28]
  133e28:      	add	x16, x16, #0xf28
  133e2c:      	br	x17

0000000000133e30 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5writeEPKcl@plt>:
  133e30:      	adrp	x16, 0x13b000
  133e34:      	ldr	x17, [x16, #0xf30]
  133e38:      	add	x16, x16, #0xf30
  133e3c:      	br	x17

0000000000133e40 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEED1Ev@plt>:
  133e40:      	adrp	x16, 0x13b000
  133e44:      	ldr	x17, [x16, #0xf38]
  133e48:      	add	x16, x16, #0xf38
  133e4c:      	br	x17

0000000000133e50 <_ZN8PVGCOLOR9PVGOpenGL16destroyGLContextEPPvS2_S2_S2_@plt>:
  133e50:      	adrp	x16, 0x13b000
  133e54:      	ldr	x17, [x16, #0xf40]
  133e58:      	add	x16, x16, #0xf40
  133e5c:      	br	x17

0000000000133e60 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEEC1Ev@plt>:
  133e60:      	adrp	x16, 0x13b000
  133e64:      	ldr	x17, [x16, #0xf48]
  133e68:      	add	x16, x16, #0xf48
  133e6c:      	br	x17

0000000000133e70 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj@plt>:
  133e70:      	adrp	x16, 0x13b000
  133e74:      	ldr	x17, [x16, #0xf50]
  133e78:      	add	x16, x16, #0xf50
  133e7c:      	br	x17

0000000000133e80 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  133e80:      	adrp	x16, 0x13b000
  133e84:      	ldr	x17, [x16, #0xf58]
  133e88:      	add	x16, x16, #0xf58
  133e8c:      	br	x17

0000000000133e90 <realloc@plt>:
  133e90:      	adrp	x16, 0x13b000
  133e94:      	ldr	x17, [x16, #0xf60]
  133e98:      	add	x16, x16, #0xf60
  133e9c:      	br	x17

0000000000133ea0 <_ZNSt6__ndk117__assoc_sub_state10__sub_waitERNS_11unique_lockINS_5mutexEEE@plt>:
  133ea0:      	adrp	x16, 0x13b000
  133ea4:      	ldr	x17, [x16, #0xf68]
  133ea8:      	add	x16, x16, #0xf68
  133eac:      	br	x17

0000000000133eb0 <_ZNSt13exception_ptrC1ERKS_@plt>:
  133eb0:      	adrp	x16, 0x13b000
  133eb4:      	ldr	x17, [x16, #0xf70]
  133eb8:      	add	x16, x16, #0xf70
  133ebc:      	br	x17

0000000000133ec0 <_ZSt17rethrow_exceptionSt13exception_ptr@plt>:
  133ec0:      	adrp	x16, 0x13b000
  133ec4:      	ldr	x17, [x16, #0xf78]
  133ec8:      	add	x16, x16, #0xf78
  133ecc:      	br	x17

0000000000133ed0 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
  133ed0:      	adrp	x16, 0x13b000
  133ed4:      	ldr	x17, [x16, #0xf80]
  133ed8:      	add	x16, x16, #0xf80
  133edc:      	br	x17

0000000000133ee0 <_ZN8PVGCOLOR18PVGRotateFunctions9transcodeEPKPKhPKiPKPhS6_@plt>:
  133ee0:      	adrp	x16, 0x13b000
  133ee4:      	ldr	x17, [x16, #0xf88]
  133ee8:      	add	x16, x16, #0xf88
  133eec:      	br	x17

0000000000133ef0 <_ZN8PVGCOLOR18PVGRotateFunctions6createEiiNS_14PVGPixelFormatEi@plt>:
  133ef0:      	adrp	x16, 0x13b000
  133ef4:      	ldr	x17, [x16, #0xf90]
  133ef8:      	add	x16, x16, #0xf90
  133efc:      	br	x17

0000000000133f00 <_ZN8PVGCOLOR18PVGRotateFunctions12setHWContextERKNS_12PVGHWContextE@plt>:
  133f00:      	adrp	x16, 0x13b000
  133f04:      	ldr	x17, [x16, #0xf98]
  133f08:      	add	x16, x16, #0xf98
  133f0c:      	br	x17

0000000000133f10 <_ZN3PVG19PVGExtractVideoClipD1Ev@plt>:
  133f10:      	adrp	x16, 0x13b000
  133f14:      	ldr	x17, [x16, #0xfa0]
  133f18:      	add	x16, x16, #0xfa0
  133f1c:      	br	x17

0000000000133f20 <_ZN3PVG19PVGExtractVideoClipC1Ev@plt>:
  133f20:      	adrp	x16, 0x13b000
  133f24:      	ldr	x17, [x16, #0xfa8]
  133f28:      	add	x16, x16, #0xfa8
  133f2c:      	br	x17

0000000000133f30 <_ZN3PVG18PVGFormatTranscode6createEv@plt>:
  133f30:      	adrp	x16, 0x13b000
  133f34:      	ldr	x17, [x16, #0xfb0]
  133f38:      	add	x16, x16, #0xfb0
  133f3c:      	br	x17

0000000000133f40 <_ZN3PVG18PVGFormatTranscodeC1Ev@plt>:
  133f40:      	adrp	x16, 0x13b000
  133f44:      	ldr	x17, [x16, #0xfb8]
  133f48:      	add	x16, x16, #0xfb8
  133f4c:      	br	x17

0000000000133f50 <_ZN3PVG18PVGFormatTranscode5closeEv@plt>:
  133f50:      	adrp	x16, 0x13b000
  133f54:      	ldr	x17, [x16, #0xfc0]
  133f58:      	add	x16, x16, #0xfc0
  133f5c:      	br	x17

0000000000133f60 <_ZN3PVG18PVGFormatTranscode13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  133f60:      	adrp	x16, 0x13b000
  133f64:      	ldr	x17, [x16, #0xfc8]
  133f68:      	add	x16, x16, #0xfc8
  133f6c:      	br	x17

0000000000133f70 <_ZN3PVG18PVGFormatTranscode17getInputMediaInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133f70:      	adrp	x16, 0x13b000
  133f74:      	ldr	x17, [x16, #0xfd0]
  133f78:      	add	x16, x16, #0xfd0
  133f7c:      	br	x17

0000000000133f80 <_ZN3PVG18PVGFormatTranscode4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133f80:      	adrp	x16, 0x13b000
  133f84:      	ldr	x17, [x16, #0xfd8]
  133f88:      	add	x16, x16, #0xfd8
  133f8c:      	br	x17

0000000000133f90 <_ZN3PVG18PVGFormatTranscode19openDecoderIfNeededEv@plt>:
  133f90:      	adrp	x16, 0x13b000
  133f94:      	ldr	x17, [x16, #0xfe0]
  133f98:      	add	x16, x16, #0xfe0
  133f9c:      	br	x17

0000000000133fa0 <_ZN3PVG18PVGFormatTranscode10openOutputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  133fa0:      	adrp	x16, 0x13b000
  133fa4:      	ldr	x17, [x16, #0xfe8]
  133fa8:      	add	x16, x16, #0xfe8
  133fac:      	br	x17

0000000000133fb0 <avformat_query_codec@plt>:
  133fb0:      	adrp	x16, 0x13b000
  133fb4:      	ldr	x17, [x16, #0xff0]
  133fb8:      	add	x16, x16, #0xff0
  133fbc:      	br	x17

0000000000133fc0 <av_guess_codec@plt>:
  133fc0:      	adrp	x16, 0x13b000
  133fc4:      	ldr	x17, [x16, #0xff8]
  133fc8:      	add	x16, x16, #0xff8
  133fcc:      	br	x17

0000000000133fd0 <av_d2q@plt>:
  133fd0:      	adrp	x16, 0x13c000
  133fd4:      	ldr	x17, [x16]
  133fd8:      	add	x16, x16, #0x0
  133fdc:      	br	x17

0000000000133fe0 <av_mul_q@plt>:
  133fe0:      	adrp	x16, 0x13c000
  133fe4:      	ldr	x17, [x16, #0x8]
  133fe8:      	add	x16, x16, #0x8
  133fec:      	br	x17

0000000000133ff0 <av_reduce@plt>:
  133ff0:      	adrp	x16, 0x13c000
  133ff4:      	ldr	x17, [x16, #0x10]
  133ff8:      	add	x16, x16, #0x10
  133ffc:      	br	x17

0000000000134000 <av_opt_set_int@plt>:
  134000:      	adrp	x16, 0x13c000
  134004:      	ldr	x17, [x16, #0x18]
  134008:      	add	x16, x16, #0x18
  13400c:      	br	x17

0000000000134010 <_ZN3PVG18PVGFormatTranscode17writePacketLockedEPvP14AVCodecContextP8AVStream@plt>:
  134010:      	adrp	x16, 0x13c000
  134014:      	ldr	x17, [x16, #0x20]
  134018:      	add	x16, x16, #0x20
  13401c:      	br	x17

0000000000134020 <_ZN3PVG18PVGFormatTranscode16encodeVideoFrameEP7AVFrame@plt>:
  134020:      	adrp	x16, 0x13c000
  134024:      	ldr	x17, [x16, #0x28]
  134028:      	add	x16, x16, #0x28
  13402c:      	br	x17

0000000000134030 <_ZN3PVG18PVGFormatTranscode16encodeAudioFrameEP7AVFrame@plt>:
  134030:      	adrp	x16, 0x13c000
  134034:      	ldr	x17, [x16, #0x30]
  134038:      	add	x16, x16, #0x30
  13403c:      	br	x17

0000000000134040 <_ZN3PVG18PVGFormatTranscode14transcodeVideoEv@plt>:
  134040:      	adrp	x16, 0x13c000
  134044:      	ldr	x17, [x16, #0x38]
  134048:      	add	x16, x16, #0x38
  13404c:      	br	x17

0000000000134050 <_ZN3PVG18PVGFormatTranscode14transcodeAudioEv@plt>:
  134050:      	adrp	x16, 0x13c000
  134054:      	ldr	x17, [x16, #0x40]
  134058:      	add	x16, x16, #0x40
  13405c:      	br	x17

0000000000134060 <av_samples_alloc_array_and_samples@plt>:
  134060:      	adrp	x16, 0x13c000
  134064:      	ldr	x17, [x16, #0x48]
  134068:      	add	x16, x16, #0x48
  13406c:      	br	x17

0000000000134070 <av_freep@plt>:
  134070:      	adrp	x16, 0x13c000
  134074:      	ldr	x17, [x16, #0x50]
  134078:      	add	x16, x16, #0x50
  13407c:      	br	x17

0000000000134080 <_ZN3PVG18PVGFormatTranscode7processERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134080:      	adrp	x16, 0x13c000
  134084:      	ldr	x17, [x16, #0x58]
  134088:      	add	x16, x16, #0x58
  13408c:      	br	x17

0000000000134090 <_ZN3PVG18PVGFormatTranscode5abortEv@plt>:
  134090:      	adrp	x16, 0x13c000
  134094:      	ldr	x17, [x16, #0x60]
  134098:      	add	x16, x16, #0x60
  13409c:      	br	x17

00000000001340a0 <_ZN3PVG18PVGFormatTranscode19setProgressListenerEPNS_11PVGListenerE@plt>:
  1340a0:      	adrp	x16, 0x13c000
  1340a4:      	ldr	x17, [x16, #0x68]
  1340a8:      	add	x16, x16, #0x68
  1340ac:      	br	x17

00000000001340b0 <_ZN3PVG18PVGFormatTranscodeD1Ev@plt>:
  1340b0:      	adrp	x16, 0x13c000
  1340b4:      	ldr	x17, [x16, #0x70]
  1340b8:      	add	x16, x16, #0x70
  1340bc:      	br	x17

00000000001340c0 <_ZN3PVG14PVGGifMetaDataD1Ev@plt>:
  1340c0:      	adrp	x16, 0x13c000
  1340c4:      	ldr	x17, [x16, #0x78]
  1340c8:      	add	x16, x16, #0x78
  1340cc:      	br	x17

00000000001340d0 <_ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv@plt>:
  1340d0:      	adrp	x16, 0x13c000
  1340d4:      	ldr	x17, [x16, #0x80]
  1340d8:      	add	x16, x16, #0x80
  1340dc:      	br	x17

00000000001340e0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE3putEc@plt>:
  1340e0:      	adrp	x16, 0x13c000
  1340e4:      	ldr	x17, [x16, #0x88]
  1340e8:      	add	x16, x16, #0x88
  1340ec:      	br	x17

00000000001340f0 <__emutls_get_address@plt>:
  1340f0:      	adrp	x16, 0x13c000
  1340f4:      	ldr	x17, [x16, #0x90]
  1340f8:      	add	x16, x16, #0x90
  1340fc:      	br	x17

0000000000134100 <__vsnprintf_chk@plt>:
  134100:      	adrp	x16, 0x13c000
  134104:      	ldr	x17, [x16, #0x98]
  134108:      	add	x16, x16, #0x98
  13410c:      	br	x17

0000000000134110 <_ZN3PVG9PVGGlobalC1Ev@plt>:
  134110:      	adrp	x16, 0x13c000
  134114:      	ldr	x17, [x16, #0xa0]
  134118:      	add	x16, x16, #0xa0
  13411c:      	br	x17

0000000000134120 <_ZN3PVG9PVGGlobal10getVersionEv@plt>:
  134120:      	adrp	x16, 0x13c000
  134124:      	ldr	x17, [x16, #0xa8]
  134128:      	add	x16, x16, #0xa8
  13412c:      	br	x17

0000000000134130 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  134130:      	adrp	x16, 0x13c000
  134134:      	ldr	x17, [x16, #0xb0]
  134138:      	add	x16, x16, #0xb0
  13413c:      	br	x17

0000000000134140 <_ZN3PVG9PVGGlobal23getPVGVideoCodecVersionEv@plt>:
  134140:      	adrp	x16, 0x13c000
  134144:      	ldr	x17, [x16, #0xb8]
  134148:      	add	x16, x16, #0xb8
  13414c:      	br	x17

0000000000134150 <_ZN8PVGVIDEO10getVersionEv@plt>:
  134150:      	adrp	x16, 0x13c000
  134154:      	ldr	x17, [x16, #0xc0]
  134158:      	add	x16, x16, #0xc0
  13415c:      	br	x17

0000000000134160 <_ZN3PVG9PVGGlobal23getPVGImageCodecVersionEv@plt>:
  134160:      	adrp	x16, 0x13c000
  134164:      	ldr	x17, [x16, #0xc8]
  134168:      	add	x16, x16, #0xc8
  13416c:      	br	x17

0000000000134170 <_ZN8PVGIMAGE10getVersionEv@plt>:
  134170:      	adrp	x16, 0x13c000
  134174:      	ldr	x17, [x16, #0xd0]
  134178:      	add	x16, x16, #0xd0
  13417c:      	br	x17

0000000000134180 <_ZN3PVG9PVGGlobal26getPVGColorFunctionVersionEv@plt>:
  134180:      	adrp	x16, 0x13c000
  134184:      	ldr	x17, [x16, #0xd8]
  134188:      	add	x16, x16, #0xd8
  13418c:      	br	x17

0000000000134190 <_ZN8PVGCOLOR10getVersionEv@plt>:
  134190:      	adrp	x16, 0x13c000
  134194:      	ldr	x17, [x16, #0xe0]
  134198:      	add	x16, x16, #0xe0
  13419c:      	br	x17

00000000001341a0 <_ZN8PVGIMAGE9PVGGlobal11getInstanceEv@plt>:
  1341a0:      	adrp	x16, 0x13c000
  1341a4:      	ldr	x17, [x16, #0xe8]
  1341a8:      	add	x16, x16, #0xe8
  1341ac:      	br	x17

00000000001341b0 <_ZN8PVGIMAGE9PVGGlobal19setPVGImageLogLevelENS_11PVGLogLevelE@plt>:
  1341b0:      	adrp	x16, 0x13c000
  1341b4:      	ldr	x17, [x16, #0xf0]
  1341b8:      	add	x16, x16, #0xf0
  1341bc:      	br	x17

00000000001341c0 <_ZN3PVG9PVGGlobal19setLogCallbackLevelEi@plt>:
  1341c0:      	adrp	x16, 0x13c000
  1341c4:      	ldr	x17, [x16, #0xf8]
  1341c8:      	add	x16, x16, #0xf8
  1341cc:      	br	x17

00000000001341d0 <_ZN3PVG9PVGGlobal14setLogCallbackENSt6__ndk18functionIFviPKcEEE@plt>:
  1341d0:      	adrp	x16, 0x13c000
  1341d4:      	ldr	x17, [x16, #0x100]
  1341d8:      	add	x16, x16, #0x100
  1341dc:      	br	x17

00000000001341e0 <_ZN3PVG9PVGGlobal17setAndroidContextEP8_jobject@plt>:
  1341e0:      	adrp	x16, 0x13c000
  1341e4:      	ldr	x17, [x16, #0x108]
  1341e8:      	add	x16, x16, #0x108
  1341ec:      	br	x17

00000000001341f0 <_ZN8PVGVIDEO9PVGGlobal17setAndroidContextEP8_jobject@plt>:
  1341f0:      	adrp	x16, 0x13c000
  1341f4:      	ldr	x17, [x16, #0x110]
  1341f8:      	add	x16, x16, #0x110
  1341fc:      	br	x17

0000000000134200 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
  134200:      	adrp	x16, 0x13c000
  134204:      	ldr	x17, [x16, #0x118]
  134208:      	add	x16, x16, #0x118
  13420c:      	br	x17

0000000000134210 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  134210:      	adrp	x16, 0x13c000
  134214:      	ldr	x17, [x16, #0x120]
  134218:      	add	x16, x16, #0x120
  13421c:      	br	x17

0000000000134220 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  134220:      	adrp	x16, 0x13c000
  134224:      	ldr	x17, [x16, #0x128]
  134228:      	add	x16, x16, #0x128
  13422c:      	br	x17

0000000000134230 <_ZNSt6__ndk16localeD1Ev@plt>:
  134230:      	adrp	x16, 0x13c000
  134234:      	ldr	x17, [x16, #0x130]
  134238:      	add	x16, x16, #0x130
  13423c:      	br	x17

0000000000134240 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
  134240:      	adrp	x16, 0x13c000
  134244:      	ldr	x17, [x16, #0x138]
  134248:      	add	x16, x16, #0x138
  13424c:      	br	x17

0000000000134250 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
  134250:      	adrp	x16, 0x13c000
  134254:      	ldr	x17, [x16, #0x140]
  134258:      	add	x16, x16, #0x140
  13425c:      	br	x17

0000000000134260 <_ZN3PVG10PVGGopClipC1ENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_@plt>:
  134260:      	adrp	x16, 0x13c000
  134264:      	ldr	x17, [x16, #0x148]
  134268:      	add	x16, x16, #0x148
  13426c:      	br	x17

0000000000134270 <_ZN3PVG10PVGGopClipD1Ev@plt>:
  134270:      	adrp	x16, 0x13c000
  134274:      	ldr	x17, [x16, #0x150]
  134278:      	add	x16, x16, #0x150
  13427c:      	br	x17

0000000000134280 <_ZN3PVG15PVGMediaEntriesC1Ev@plt>:
  134280:      	adrp	x16, 0x13c000
  134284:      	ldr	x17, [x16, #0x158]
  134288:      	add	x16, x16, #0x158
  13428c:      	br	x17

0000000000134290 <_ZN3PVG10PVGHWCheck6createEv@plt>:
  134290:      	adrp	x16, 0x13c000
  134294:      	ldr	x17, [x16, #0x160]
  134298:      	add	x16, x16, #0x160
  13429c:      	br	x17

00000000001342a0 <_ZN3PVG10PVGHWCheckC1Ev@plt>:
  1342a0:      	adrp	x16, 0x13c000
  1342a4:      	ldr	x17, [x16, #0x168]
  1342a8:      	add	x16, x16, #0x168
  1342ac:      	br	x17

00000000001342b0 <_ZN3PVG10PVGHWCheck24CheckIsSupportCudaDecodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  1342b0:      	adrp	x16, 0x13c000
  1342b4:      	ldr	x17, [x16, #0x170]
  1342b8:      	add	x16, x16, #0x170
  1342bc:      	br	x17

00000000001342c0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEPNS_15basic_streambufIcS2_EE@plt>:
  1342c0:      	adrp	x16, 0x13c000
  1342c4:      	ldr	x17, [x16, #0x178]
  1342c8:      	add	x16, x16, #0x178
  1342cc:      	br	x17

00000000001342d0 <avcodec_get_name@plt>:
  1342d0:      	adrp	x16, 0x13c000
  1342d4:      	ldr	x17, [x16, #0x180]
  1342d8:      	add	x16, x16, #0x180
  1342dc:      	br	x17

00000000001342e0 <_ZN3PVG10PVGHWCheckD1Ev@plt>:
  1342e0:      	adrp	x16, 0x13c000
  1342e4:      	ldr	x17, [x16, #0x188]
  1342e8:      	add	x16, x16, #0x188
  1342ec:      	br	x17

00000000001342f0 <_ZN8PVGIMAGE13PVGImageCodec6createERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS_12PVGCodecTypeEb@plt>:
  1342f0:      	adrp	x16, 0x13c000
  1342f4:      	ldr	x17, [x16, #0x190]
  1342f8:      	add	x16, x16, #0x190
  1342fc:      	br	x17

0000000000134300 <_ZN3PVG14PVGImageDecEnc8DecFrameEPiS1_S1_@plt>:
  134300:      	adrp	x16, 0x13c000
  134304:      	ldr	x17, [x16, #0x198]
  134308:      	add	x16, x16, #0x198
  13430c:      	br	x17

0000000000134310 <_ZN8PVGIMAGE10PVGContextC1Ev@plt>:
  134310:      	adrp	x16, 0x13c000
  134314:      	ldr	x17, [x16, #0x1a0]
  134318:      	add	x16, x16, #0x1a0
  13431c:      	br	x17

0000000000134320 <_ZN8PVGIMAGE13PVGImageCodec9codecOpenEPNS_10PVGContextE@plt>:
  134320:      	adrp	x16, 0x13c000
  134324:      	ldr	x17, [x16, #0x1a8]
  134328:      	add	x16, x16, #0x1a8
  13432c:      	br	x17

0000000000134330 <_ZN8PVGIMAGE13PVGImageCodec14getInformationEv@plt>:
  134330:      	adrp	x16, 0x13c000
  134334:      	ldr	x17, [x16, #0x1b0]
  134338:      	add	x16, x16, #0x1b0
  13433c:      	br	x17

0000000000134340 <_ZN8PVGIMAGE13PVGImageCodec6createEPKhlNS_12PVGCodecTypeEb@plt>:
  134340:      	adrp	x16, 0x13c000
  134344:      	ldr	x17, [x16, #0x1b8]
  134348:      	add	x16, x16, #0x1b8
  13434c:      	br	x17

0000000000134350 <_ZN8PVGIMAGE13PVGImageCodec12dequeueFrameEPPNS_8PVGFrameE@plt>:
  134350:      	adrp	x16, 0x13c000
  134354:      	ldr	x17, [x16, #0x1c0]
  134358:      	add	x16, x16, #0x1c0
  13435c:      	br	x17

0000000000134360 <_ZN8PVGIMAGE13PVGImageCodec12receiveFrameEPNS_8PVGFrameE@plt>:
  134360:      	adrp	x16, 0x13c000
  134364:      	ldr	x17, [x16, #0x1c8]
  134368:      	add	x16, x16, #0x1c8
  13436c:      	br	x17

0000000000134370 <_ZNK8PVGIMAGE8PVGFrame12getPlaneDataEi@plt>:
  134370:      	adrp	x16, 0x13c000
  134374:      	ldr	x17, [x16, #0x1d0]
  134378:      	add	x16, x16, #0x1d0
  13437c:      	br	x17

0000000000134380 <_ZNK8PVGIMAGE8PVGFrame16getPlaneLinesizeEi@plt>:
  134380:      	adrp	x16, 0x13c000
  134384:      	ldr	x17, [x16, #0x1d8]
  134388:      	add	x16, x16, #0x1d8
  13438c:      	br	x17

0000000000134390 <_ZNK8PVGIMAGE8PVGFrame9getFormatEv@plt>:
  134390:      	adrp	x16, 0x13c000
  134394:      	ldr	x17, [x16, #0x1e0]
  134398:      	add	x16, x16, #0x1e0
  13439c:      	br	x17

00000000001343a0 <_ZNK8PVGIMAGE8PVGFrame13getColorRangeEv@plt>:
  1343a0:      	adrp	x16, 0x13c000
  1343a4:      	ldr	x17, [x16, #0x1e8]
  1343a8:      	add	x16, x16, #0x1e8
  1343ac:      	br	x17

00000000001343b0 <_ZNK8PVGIMAGE8PVGFrame17getColorPrimariesEv@plt>:
  1343b0:      	adrp	x16, 0x13c000
  1343b4:      	ldr	x17, [x16, #0x1f0]
  1343b8:      	add	x16, x16, #0x1f0
  1343bc:      	br	x17

00000000001343c0 <_ZNK8PVGIMAGE8PVGFrame16getColorTransferEv@plt>:
  1343c0:      	adrp	x16, 0x13c000
  1343c4:      	ldr	x17, [x16, #0x1f8]
  1343c8:      	add	x16, x16, #0x1f8
  1343cc:      	br	x17

00000000001343d0 <_ZNK8PVGIMAGE8PVGFrame14getColorMatrixEv@plt>:
  1343d0:      	adrp	x16, 0x13c000
  1343d4:      	ldr	x17, [x16, #0x200]
  1343d8:      	add	x16, x16, #0x200
  1343dc:      	br	x17

00000000001343e0 <_ZN8PVGCOLOR15PVGImageConvert15transcodeFormatENS_14PVGPixelFormatEPKhjS1_PPhPj@plt>:
  1343e0:      	adrp	x16, 0x13c000
  1343e4:      	ldr	x17, [x16, #0x208]
  1343e8:      	add	x16, x16, #0x208
  1343ec:      	br	x17

00000000001343f0 <_ZN8PVGCOLOR17PVGColorFunctions13setICCProfileEPKhiS2_i@plt>:
  1343f0:      	adrp	x16, 0x13c000
  1343f4:      	ldr	x17, [x16, #0x210]
  1343f8:      	add	x16, x16, #0x210
  1343fc:      	br	x17

0000000000134400 <_ZN8PVGCOLOR17PVGColorFunctions7setTypeENS_14PVGProfileTypeE@plt>:
  134400:      	adrp	x16, 0x13c000
  134404:      	ldr	x17, [x16, #0x218]
  134408:      	add	x16, x16, #0x218
  13440c:      	br	x17

0000000000134410 <_ZN8PVGIMAGE13PVGImageCodec12releaseFrameEPPNS_8PVGFrameE@plt>:
  134410:      	adrp	x16, 0x13c000
  134414:      	ldr	x17, [x16, #0x220]
  134418:      	add	x16, x16, #0x220
  13441c:      	br	x17

0000000000134420 <_ZN8PVGIMAGE10PVGContext12setDimensionEii@plt>:
  134420:      	adrp	x16, 0x13c000
  134424:      	ldr	x17, [x16, #0x228]
  134428:      	add	x16, x16, #0x228
  13442c:      	br	x17

0000000000134430 <_ZN8PVGIMAGE10PVGContext18setImageOutQualityEi@plt>:
  134430:      	adrp	x16, 0x13c000
  134434:      	ldr	x17, [x16, #0x230]
  134438:      	add	x16, x16, #0x230
  13443c:      	br	x17

0000000000134440 <_ZN8PVGIMAGE10PVGContext8setCodecERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134440:      	adrp	x16, 0x13c000
  134444:      	ldr	x17, [x16, #0x238]
  134448:      	add	x16, x16, #0x238
  13444c:      	br	x17

0000000000134450 <_ZN8PVGIMAGE10PVGContext14setImageFormatENS_9PVGFormatE@plt>:
  134450:      	adrp	x16, 0x13c000
  134454:      	ldr	x17, [x16, #0x240]
  134458:      	add	x16, x16, #0x240
  13445c:      	br	x17

0000000000134460 <_ZN8PVGIMAGE10PVGContext18setImageColorSpaceENS_14ColorSpaceTypeE@plt>:
  134460:      	adrp	x16, 0x13c000
  134464:      	ldr	x17, [x16, #0x248]
  134468:      	add	x16, x16, #0x248
  13446c:      	br	x17

0000000000134470 <_ZN8PVGIMAGE10PVGContextD1Ev@plt>:
  134470:      	adrp	x16, 0x13c000
  134474:      	ldr	x17, [x16, #0x250]
  134478:      	add	x16, x16, #0x250
  13447c:      	br	x17

0000000000134480 <_ZN8PVGIMAGE8PVGFrame24setPresentationTimestampEl@plt>:
  134480:      	adrp	x16, 0x13c000
  134484:      	ldr	x17, [x16, #0x258]
  134488:      	add	x16, x16, #0x258
  13448c:      	br	x17

0000000000134490 <_ZN8PVGIMAGE8PVGFrame11setDurationEl@plt>:
  134490:      	adrp	x16, 0x13c000
  134494:      	ldr	x17, [x16, #0x260]
  134498:      	add	x16, x16, #0x260
  13449c:      	br	x17

00000000001344a0 <_ZN8PVGIMAGE8PVGFrame7setExifEi@plt>:
  1344a0:      	adrp	x16, 0x13c000
  1344a4:      	ldr	x17, [x16, #0x268]
  1344a8:      	add	x16, x16, #0x268
  1344ac:      	br	x17

00000000001344b0 <_ZN8PVGIMAGE8PVGFrame9mapBufferEPPhPi@plt>:
  1344b0:      	adrp	x16, 0x13c000
  1344b4:      	ldr	x17, [x16, #0x270]
  1344b8:      	add	x16, x16, #0x270
  1344bc:      	br	x17

00000000001344c0 <puts@plt>:
  1344c0:      	adrp	x16, 0x13c000
  1344c4:      	ldr	x17, [x16, #0x278]
  1344c8:      	add	x16, x16, #0x278
  1344cc:      	br	x17

00000000001344d0 <_ZN8PVGIMAGE13PVGImageCodec9sendFrameEPNS_8PVGFrameE@plt>:
  1344d0:      	adrp	x16, 0x13c000
  1344d4:      	ldr	x17, [x16, #0x280]
  1344d8:      	add	x16, x16, #0x280
  1344dc:      	br	x17

00000000001344e0 <_ZN8PVGIMAGE13PVGImageCodec10codecCloseEv@plt>:
  1344e0:      	adrp	x16, 0x13c000
  1344e4:      	ldr	x17, [x16, #0x288]
  1344e8:      	add	x16, x16, #0x288
  1344ec:      	br	x17

00000000001344f0 <_ZN3PVG17PVGImageTranscode19setProgressListenerEPNS_11PVGListenerE@plt>:
  1344f0:      	adrp	x16, 0x13c000
  1344f4:      	ldr	x17, [x16, #0x290]
  1344f8:      	add	x16, x16, #0x290
  1344fc:      	br	x17

0000000000134500 <_ZN3PVG17PVGImageTranscode6createEv@plt>:
  134500:      	adrp	x16, 0x13c000
  134504:      	ldr	x17, [x16, #0x298]
  134508:      	add	x16, x16, #0x298
  13450c:      	br	x17

0000000000134510 <_ZN3PVG17PVGImageTranscode4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134510:      	adrp	x16, 0x13c000
  134514:      	ldr	x17, [x16, #0x2a0]
  134518:      	add	x16, x16, #0x2a0
  13451c:      	br	x17

0000000000134520 <_ZN3PVG17PVGImageTranscode4openEPKhm@plt>:
  134520:      	adrp	x16, 0x13c000
  134524:      	ldr	x17, [x16, #0x2a8]
  134528:      	add	x16, x16, #0x2a8
  13452c:      	br	x17

0000000000134530 <_ZN3PVG17PVGImageTranscode10parseInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134530:      	adrp	x16, 0x13c000
  134534:      	ldr	x17, [x16, #0x2b0]
  134538:      	add	x16, x16, #0x2b0
  13453c:      	br	x17

0000000000134540 <_ZN8PVGIMAGE13PVGImageCodec10parseInputEPKhlRNS_14PVGInformationEb@plt>:
  134540:      	adrp	x16, 0x13c000
  134544:      	ldr	x17, [x16, #0x2b8]
  134548:      	add	x16, x16, #0x2b8
  13454c:      	br	x17

0000000000134550 <_ZN8PVGIMAGE13PVGImageCodec10parseInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_14PVGInformationEb@plt>:
  134550:      	adrp	x16, 0x13c000
  134554:      	ldr	x17, [x16, #0x2c0]
  134558:      	add	x16, x16, #0x2c0
  13455c:      	br	x17

0000000000134560 <_ZN3PVG17PVGImageTranscode10parseInputEPKhm@plt>:
  134560:      	adrp	x16, 0x13c000
  134564:      	ldr	x17, [x16, #0x2c8]
  134568:      	add	x16, x16, #0x2c8
  13456c:      	br	x17

0000000000134570 <_ZN3PVG17PVGImageTranscode13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  134570:      	adrp	x16, 0x13c000
  134574:      	ldr	x17, [x16, #0x2d0]
  134578:      	add	x16, x16, #0x2d0
  13457c:      	br	x17

0000000000134580 <_ZN3PVG17PVGImageTranscode9transcodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134580:      	adrp	x16, 0x13c000
  134584:      	ldr	x17, [x16, #0x2d8]
  134588:      	add	x16, x16, #0x2d8
  13458c:      	br	x17

0000000000134590 <_ZNK8PVGIMAGE8PVGFrame8getWidthEv@plt>:
  134590:      	adrp	x16, 0x13c000
  134594:      	ldr	x17, [x16, #0x2e0]
  134598:      	add	x16, x16, #0x2e0
  13459c:      	br	x17

00000000001345a0 <_ZNK8PVGIMAGE8PVGFrame9getHeightEv@plt>:
  1345a0:      	adrp	x16, 0x13c000
  1345a4:      	ldr	x17, [x16, #0x2e8]
  1345a8:      	add	x16, x16, #0x2e8
  1345ac:      	br	x17

00000000001345b0 <_ZNK8PVGIMAGE8PVGFrame7getExifEv@plt>:
  1345b0:      	adrp	x16, 0x13c000
  1345b4:      	ldr	x17, [x16, #0x2f0]
  1345b8:      	add	x16, x16, #0x2f0
  1345bc:      	br	x17

00000000001345c0 <_ZN8PVGIMAGE13PVGImageCodec24getImageIccProfileLengthENS_14ColorSpaceTypeE@plt>:
  1345c0:      	adrp	x16, 0x13c000
  1345c4:      	ldr	x17, [x16, #0x2f8]
  1345c8:      	add	x16, x16, #0x2f8
  1345cc:      	br	x17

00000000001345d0 <_ZN8PVGIMAGE13PVGImageCodec22getImageIccProfileDataENS_14ColorSpaceTypeE@plt>:
  1345d0:      	adrp	x16, 0x13c000
  1345d4:      	ldr	x17, [x16, #0x300]
  1345d8:      	add	x16, x16, #0x300
  1345dc:      	br	x17

00000000001345e0 <_ZN8PVGIMAGE8PVGFrame9setFormatENS_9PVGFormatE@plt>:
  1345e0:      	adrp	x16, 0x13c000
  1345e4:      	ldr	x17, [x16, #0x308]
  1345e8:      	add	x16, x16, #0x308
  1345ec:      	br	x17

00000000001345f0 <_ZN8PVGIMAGE8PVGFrame13setColorRangeENS_13PVGColorRangeE@plt>:
  1345f0:      	adrp	x16, 0x13c000
  1345f4:      	ldr	x17, [x16, #0x310]
  1345f8:      	add	x16, x16, #0x310
  1345fc:      	br	x17

0000000000134600 <_ZN8PVGIMAGE8PVGFrame17setColorPrimariesENS_17PVGColorPrimariesE@plt>:
  134600:      	adrp	x16, 0x13c000
  134604:      	ldr	x17, [x16, #0x318]
  134608:      	add	x16, x16, #0x318
  13460c:      	br	x17

0000000000134610 <_ZN8PVGIMAGE8PVGFrame16setColorTransferENS_16PVGColorTransferE@plt>:
  134610:      	adrp	x16, 0x13c000
  134614:      	ldr	x17, [x16, #0x320]
  134618:      	add	x16, x16, #0x320
  13461c:      	br	x17

0000000000134620 <_ZN8PVGIMAGE8PVGFrame14setColorMatrixENS_14PVGColorMatrixE@plt>:
  134620:      	adrp	x16, 0x13c000
  134624:      	ldr	x17, [x16, #0x328]
  134628:      	add	x16, x16, #0x328
  13462c:      	br	x17

0000000000134630 <_ZN3PVG17PVGImageTranscode5closeEv@plt>:
  134630:      	adrp	x16, 0x13c000
  134634:      	ldr	x17, [x16, #0x330]
  134638:      	add	x16, x16, #0x330
  13463c:      	br	x17

0000000000134640 <_ZN3PVG17PVGImageTranscode11checkIsSRGBEv@plt>:
  134640:      	adrp	x16, 0x13c000
  134644:      	ldr	x17, [x16, #0x338]
  134648:      	add	x16, x16, #0x338
  13464c:      	br	x17

0000000000134650 <_ZN3PVG17PVGImageTranscode10checkIsHDREv@plt>:
  134650:      	adrp	x16, 0x13c000
  134654:      	ldr	x17, [x16, #0x340]
  134658:      	add	x16, x16, #0x340
  13465c:      	br	x17

0000000000134660 <_ZN3PVG17PVGImageTranscode13checkHasAlphaEv@plt>:
  134660:      	adrp	x16, 0x13c000
  134664:      	ldr	x17, [x16, #0x348]
  134668:      	add	x16, x16, #0x348
  13466c:      	br	x17

0000000000134670 <_ZN3PVG17PVGImageTranscode17getInputImageInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134670:      	adrp	x16, 0x13c000
  134674:      	ldr	x17, [x16, #0x350]
  134678:      	add	x16, x16, #0x350
  13467c:      	br	x17

0000000000134680 <_ZN3PVG17PVGImageTranscode16copySrcExifToDstERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  134680:      	adrp	x16, 0x13c000
  134684:      	ldr	x17, [x16, #0x358]
  134688:      	add	x16, x16, #0x358
  13468c:      	br	x17

0000000000134690 <_ZN8PVGIMAGE15PVGExiv2Manager16copySrcExifToDstERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_Phm@plt>:
  134690:      	adrp	x16, 0x13c000
  134694:      	ldr	x17, [x16, #0x360]
  134698:      	add	x16, x16, #0x360
  13469c:      	br	x17

00000000001346a0 <_ZN3PVG17PVGImageTranscode11getExivInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPKc@plt>:
  1346a0:      	adrp	x16, 0x13c000
  1346a4:      	ldr	x17, [x16, #0x368]
  1346a8:      	add	x16, x16, #0x368
  1346ac:      	br	x17

00000000001346b0 <_ZN8PVGIMAGE15PVGExiv2Manager6createERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  1346b0:      	adrp	x16, 0x13c000
  1346b4:      	ldr	x17, [x16, #0x370]
  1346b8:      	add	x16, x16, #0x370
  1346bc:      	br	x17

00000000001346c0 <_ZN8PVGIMAGE15PVGExiv2Manager11getExivInfoEPKc@plt>:
  1346c0:      	adrp	x16, 0x13c000
  1346c4:      	ldr	x17, [x16, #0x378]
  1346c8:      	add	x16, x16, #0x378
  1346cc:      	br	x17

00000000001346d0 <_ZN3PVG17PVGImageTranscode11setExivInfoERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPKcSB_@plt>:
  1346d0:      	adrp	x16, 0x13c000
  1346d4:      	ldr	x17, [x16, #0x380]
  1346d8:      	add	x16, x16, #0x380
  1346dc:      	br	x17

00000000001346e0 <_ZN8PVGIMAGE15PVGExiv2Manager11setExivInfoEPKcS2_@plt>:
  1346e0:      	adrp	x16, 0x13c000
  1346e4:      	ldr	x17, [x16, #0x388]
  1346e8:      	add	x16, x16, #0x388
  1346ec:      	br	x17

00000000001346f0 <_ZN3PVG17PVGImageTranscodeD1Ev@plt>:
  1346f0:      	adrp	x16, 0x13c000
  1346f4:      	ldr	x17, [x16, #0x390]
  1346f8:      	add	x16, x16, #0x390
  1346fc:      	br	x17

0000000000134700 <_ZN3PVG14PVGMOOVDecoderC1Ev@plt>:
  134700:      	adrp	x16, 0x13c000
  134704:      	ldr	x17, [x16, #0x398]
  134708:      	add	x16, x16, #0x398
  13470c:      	br	x17

0000000000134710 <_ZN3PVG14PVGMOOVDecoder13parseMoovAtomEv@plt>:
  134710:      	adrp	x16, 0x13c000
  134714:      	ldr	x17, [x16, #0x3a0]
  134718:      	add	x16, x16, #0x3a0
  13471c:      	br	x17

0000000000134720 <_ZN3PVG14PVGMOOVDecoder8findMoovEv@plt>:
  134720:      	adrp	x16, 0x13c000
  134724:      	ldr	x17, [x16, #0x3a8]
  134728:      	add	x16, x16, #0x3a8
  13472c:      	br	x17

0000000000134730 <_Znam@plt>:
  134730:      	adrp	x16, 0x13c000
  134734:      	ldr	x17, [x16, #0x3b0]
  134738:      	add	x16, x16, #0x3b0
  13473c:      	br	x17

0000000000134740 <_ZN3PVG14PVGMOOVDecoder13createDecoderEv@plt>:
  134740:      	adrp	x16, 0x13c000
  134744:      	ldr	x17, [x16, #0x3b8]
  134748:      	add	x16, x16, #0x3b8
  13474c:      	br	x17

0000000000134750 <_ZN3PVG14PVGMOOVDecoder15getPacketRangesElb@plt>:
  134750:      	adrp	x16, 0x13c000
  134754:      	ldr	x17, [x16, #0x3c0]
  134758:      	add	x16, x16, #0x3c0
  13475c:      	br	x17

0000000000134760 <avformat_index_get_entries_count@plt>:
  134760:      	adrp	x16, 0x13c000
  134764:      	ldr	x17, [x16, #0x3c8]
  134768:      	add	x16, x16, #0x3c8
  13476c:      	br	x17

0000000000134770 <avformat_index_get_entry@plt>:
  134770:      	adrp	x16, 0x13c000
  134774:      	ldr	x17, [x16, #0x3d0]
  134778:      	add	x16, x16, #0x3d0
  13477c:      	br	x17

0000000000134780 <_ZNSt6__ndk16__sortIRNS_6__lessIllEEPlEEvT0_S5_T_@plt>:
  134780:      	adrp	x16, 0x13c000
  134784:      	ldr	x17, [x16, #0x3d8]
  134788:      	add	x16, x16, #0x3d8
  13478c:      	br	x17

0000000000134790 <printf@plt>:
  134790:      	adrp	x16, 0x13c000
  134794:      	ldr	x17, [x16, #0x3e0]
  134798:      	add	x16, x16, #0x3e0
  13479c:      	br	x17

00000000001347a0 <_ZN3PVG15PVGMediaEntries5closeEv@plt>:
  1347a0:      	adrp	x16, 0x13c000
  1347a4:      	ldr	x17, [x16, #0x3e8]
  1347a8:      	add	x16, x16, #0x3e8
  1347ac:      	br	x17

00000000001347b0 <_ZN3PVG15PVGMediaEntriesD1Ev@plt>:
  1347b0:      	adrp	x16, 0x13c000
  1347b4:      	ldr	x17, [x16, #0x3f0]
  1347b8:      	add	x16, x16, #0x3f0
  1347bc:      	br	x17

00000000001347c0 <_ZN3PVG15PVGMediaEntries11setListenerENSt6__ndk110shared_ptrINS_11PVGListenerEEE@plt>:
  1347c0:      	adrp	x16, 0x13c000
  1347c4:      	ldr	x17, [x16, #0x3f8]
  1347c8:      	add	x16, x16, #0x3f8
  1347cc:      	br	x17

00000000001347d0 <_ZN8PVGVIDEO34PVGMediaWrapperReleaseParseContextEPPv@plt>:
  1347d0:      	adrp	x16, 0x13c000
  1347d4:      	ldr	x17, [x16, #0x400]
  1347d8:      	add	x16, x16, #0x400
  1347dc:      	br	x17

00000000001347e0 <_ZN8PVGVIDEO33PVGMediaWrapperCreateParseContextEiPKhi@plt>:
  1347e0:      	adrp	x16, 0x13c000
  1347e4:      	ldr	x17, [x16, #0x408]
  1347e8:      	add	x16, x16, #0x408
  1347ec:      	br	x17

00000000001347f0 <_ZN8PVGVIDEO32PVGMediaWrapperIsSupportKeyFrameEPviiPKhi@plt>:
  1347f0:      	adrp	x16, 0x13c000
  1347f4:      	ldr	x17, [x16, #0x410]
  1347f8:      	add	x16, x16, #0x410
  1347fc:      	br	x17

0000000000134800 <_ZN3PVG6PVGRefD1Ev@plt>:
  134800:      	adrp	x16, 0x13c000
  134804:      	ldr	x17, [x16, #0x418]
  134808:      	add	x16, x16, #0x418
  13480c:      	br	x17

0000000000134810 <av_stream_add_side_data@plt>:
  134810:      	adrp	x16, 0x13c000
  134814:      	ldr	x17, [x16, #0x420]
  134818:      	add	x16, x16, #0x420
  13481c:      	br	x17

0000000000134820 <avio_size@plt>:
  134820:      	adrp	x16, 0x13c000
  134824:      	ldr	x17, [x16, #0x428]
  134828:      	add	x16, x16, #0x428
  13482c:      	br	x17

0000000000134830 <fopen@plt>:
  134830:      	adrp	x16, 0x13c000
  134834:      	ldr	x17, [x16, #0x430]
  134838:      	add	x16, x16, #0x430
  13483c:      	br	x17

0000000000134840 <_ZNSt6__ndk19to_stringEm@plt>:
  134840:      	adrp	x16, 0x13c000
  134844:      	ldr	x17, [x16, #0x438]
  134848:      	add	x16, x16, #0x438
  13484c:      	br	x17

0000000000134850 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE5flushEv@plt>:
  134850:      	adrp	x16, 0x13c000
  134854:      	ldr	x17, [x16, #0x440]
  134858:      	add	x16, x16, #0x440
  13485c:      	br	x17

0000000000134860 <av_log_set_level@plt>:
  134860:      	adrp	x16, 0x13c000
  134864:      	ldr	x17, [x16, #0x448]
  134868:      	add	x16, x16, #0x448
  13486c:      	br	x17

0000000000134870 <av_log_set_callback@plt>:
  134870:      	adrp	x16, 0x13c000
  134874:      	ldr	x17, [x16, #0x450]
  134878:      	add	x16, x16, #0x450
  13487c:      	br	x17

0000000000134880 <av_color_range_name@plt>:
  134880:      	adrp	x16, 0x13c000
  134884:      	ldr	x17, [x16, #0x458]
  134888:      	add	x16, x16, #0x458
  13488c:      	br	x17

0000000000134890 <av_color_primaries_name@plt>:
  134890:      	adrp	x16, 0x13c000
  134894:      	ldr	x17, [x16, #0x460]
  134898:      	add	x16, x16, #0x460
  13489c:      	br	x17

00000000001348a0 <av_color_transfer_name@plt>:
  1348a0:      	adrp	x16, 0x13c000
  1348a4:      	ldr	x17, [x16, #0x468]
  1348a8:      	add	x16, x16, #0x468
  1348ac:      	br	x17

00000000001348b0 <av_color_space_name@plt>:
  1348b0:      	adrp	x16, 0x13c000
  1348b4:      	ldr	x17, [x16, #0x470]
  1348b8:      	add	x16, x16, #0x470
  1348bc:      	br	x17

00000000001348c0 <av_get_pix_fmt_name@plt>:
  1348c0:      	adrp	x16, 0x13c000
  1348c4:      	ldr	x17, [x16, #0x478]
  1348c8:      	add	x16, x16, #0x478
  1348cc:      	br	x17

00000000001348d0 <av_log_get_level@plt>:
  1348d0:      	adrp	x16, 0x13c000
  1348d4:      	ldr	x17, [x16, #0x480]
  1348d8:      	add	x16, x16, #0x480
  1348dc:      	br	x17

00000000001348e0 <atoi@plt>:
  1348e0:      	adrp	x16, 0x13c000
  1348e4:      	ldr	x17, [x16, #0x488]
  1348e8:      	add	x16, x16, #0x488
  1348ec:      	br	x17

00000000001348f0 <av_gettime_relative@plt>:
  1348f0:      	adrp	x16, 0x13c000
  1348f4:      	ldr	x17, [x16, #0x490]
  1348f8:      	add	x16, x16, #0x490
  1348fc:      	br	x17

0000000000134900 <avcodec_close@plt>:
  134900:      	adrp	x16, 0x13c000
  134904:      	ldr	x17, [x16, #0x498]
  134908:      	add	x16, x16, #0x498
  13490c:      	br	x17

0000000000134910 <av_buffer_pool_uninit@plt>:
  134910:      	adrp	x16, 0x13c000
  134914:      	ldr	x17, [x16, #0x4a0]
  134918:      	add	x16, x16, #0x4a0
  13491c:      	br	x17

0000000000134920 <av_dump_format@plt>:
  134920:      	adrp	x16, 0x13c000
  134924:      	ldr	x17, [x16, #0x4a8]
  134928:      	add	x16, x16, #0x4a8
  13492c:      	br	x17

0000000000134930 <exit@plt>:
  134930:      	adrp	x16, 0x13c000
  134934:      	ldr	x17, [x16, #0x4b0]
  134938:      	add	x16, x16, #0x4b0
  13493c:      	br	x17

0000000000134940 <av_mastering_display_metadata_alloc@plt>:
  134940:      	adrp	x16, 0x13c000
  134944:      	ldr	x17, [x16, #0x4b8]
  134948:      	add	x16, x16, #0x4b8
  13494c:      	br	x17

0000000000134950 <av_content_light_metadata_alloc@plt>:
  134950:      	adrp	x16, 0x13c000
  134954:      	ldr	x17, [x16, #0x4c0]
  134958:      	add	x16, x16, #0x4c0
  13495c:      	br	x17

0000000000134960 <av_ambient_viewing_environment_alloc@plt>:
  134960:      	adrp	x16, 0x13c000
  134964:      	ldr	x17, [x16, #0x4c8]
  134968:      	add	x16, x16, #0x4c8
  13496c:      	br	x17

0000000000134970 <av_mallocz@plt>:
  134970:      	adrp	x16, 0x13c000
  134974:      	ldr	x17, [x16, #0x4d0]
  134978:      	add	x16, x16, #0x4d0
  13497c:      	br	x17

0000000000134980 <_ZNSt6__ndk19to_stringEi@plt>:
  134980:      	adrp	x16, 0x13c000
  134984:      	ldr	x17, [x16, #0x4d8]
  134988:      	add	x16, x16, #0x4d8
  13498c:      	br	x17

0000000000134990 <avcodec_is_open@plt>:
  134990:      	adrp	x16, 0x13c000
  134994:      	ldr	x17, [x16, #0x4e0]
  134998:      	add	x16, x16, #0x4e0
  13499c:      	br	x17

00000000001349a0 <av_opt_free@plt>:
  1349a0:      	adrp	x16, 0x13c000
  1349a4:      	ldr	x17, [x16, #0x4e8]
  1349a8:      	add	x16, x16, #0x4e8
  1349ac:      	br	x17

00000000001349b0 <av_buffer_pool_init@plt>:
  1349b0:      	adrp	x16, 0x13c000
  1349b4:      	ldr	x17, [x16, #0x4f0]
  1349b8:      	add	x16, x16, #0x4f0
  1349bc:      	br	x17

00000000001349c0 <av_buffer_pool_get@plt>:
  1349c0:      	adrp	x16, 0x13c000
  1349c4:      	ldr	x17, [x16, #0x4f8]
  1349c8:      	add	x16, x16, #0x4f8
  1349cc:      	br	x17

00000000001349d0 <av_buffer_alloc@plt>:
  1349d0:      	adrp	x16, 0x13c000
  1349d4:      	ldr	x17, [x16, #0x500]
  1349d8:      	add	x16, x16, #0x500
  1349dc:      	br	x17

00000000001349e0 <sws_getCoefficients@plt>:
  1349e0:      	adrp	x16, 0x13c000
  1349e4:      	ldr	x17, [x16, #0x508]
  1349e8:      	add	x16, x16, #0x508
  1349ec:      	br	x17

00000000001349f0 <sws_setColorspaceDetails@plt>:
  1349f0:      	adrp	x16, 0x13c000
  1349f4:      	ldr	x17, [x16, #0x510]
  1349f8:      	add	x16, x16, #0x510
  1349fc:      	br	x17

0000000000134a00 <fprintf@plt>:
  134a00:      	adrp	x16, 0x13c000
  134a04:      	ldr	x17, [x16, #0x518]
  134a08:      	add	x16, x16, #0x518
  134a0c:      	br	x17

0000000000134a10 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
  134a10:      	adrp	x16, 0x13c000
  134a14:      	ldr	x17, [x16, #0x520]
  134a18:      	add	x16, x16, #0x520
  134a1c:      	br	x17

0000000000134a20 <_ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE@plt>:
  134a20:      	adrp	x16, 0x13c000
  134a24:      	ldr	x17, [x16, #0x528]
  134a28:      	add	x16, x16, #0x528
  134a2c:      	br	x17

0000000000134a30 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
  134a30:      	adrp	x16, 0x13c000
  134a34:      	ldr	x17, [x16, #0x530]
  134a38:      	add	x16, x16, #0x530
  134a3c:      	br	x17

0000000000134a40 <_ZN3PVG13PVGTextReader4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134a40:      	adrp	x16, 0x13c000
  134a44:      	ldr	x17, [x16, #0x538]
  134a48:      	add	x16, x16, #0x538
  134a4c:      	br	x17

0000000000134a50 <_ZN3PVG13PVGTextReader4initEv@plt>:
  134a50:      	adrp	x16, 0x13c000
  134a54:      	ldr	x17, [x16, #0x540]
  134a58:      	add	x16, x16, #0x540
  134a5c:      	br	x17

0000000000134a60 <_ZN3PVG13PVGTextReader19transferCharsetTypeEv@plt>:
  134a60:      	adrp	x16, 0x13c000
  134a64:      	ldr	x17, [x16, #0x548]
  134a68:      	add	x16, x16, #0x548
  134a6c:      	br	x17

0000000000134a70 <_ZN3PVG13PVGTextReaderD1Ev@plt>:
  134a70:      	adrp	x16, 0x13c000
  134a74:      	ldr	x17, [x16, #0x550]
  134a78:      	add	x16, x16, #0x550
  134a7c:      	br	x17

0000000000134a80 <_ZN3PVG18PVGSubtitlesParser9setHandleEPNS_13PVGTextReaderE@plt>:
  134a80:      	adrp	x16, 0x13c000
  134a84:      	ldr	x17, [x16, #0x558]
  134a88:      	add	x16, x16, #0x558
  134a8c:      	br	x17

0000000000134a90 <_ZNK3PVG18PVGSubtitlesParser12isDecodeDoneEv@plt>:
  134a90:      	adrp	x16, 0x13c000
  134a94:      	ldr	x17, [x16, #0x560]
  134a98:      	add	x16, x16, #0x560
  134a9c:      	br	x17

0000000000134aa0 <_ZN3PVG13PVGVideo2PassD1Ev@plt>:
  134aa0:      	adrp	x16, 0x13c000
  134aa4:      	ldr	x17, [x16, #0x568]
  134aa8:      	add	x16, x16, #0x568
  134aac:      	br	x17

0000000000134ab0 <_ZN3PVG13PVGVideo2Pass7runPassERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_S9_i@plt>:
  134ab0:      	adrp	x16, 0x13c000
  134ab4:      	ldr	x17, [x16, #0x570]
  134ab8:      	add	x16, x16, #0x570
  134abc:      	br	x17

0000000000134ac0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSEc@plt>:
  134ac0:      	adrp	x16, 0x13c000
  134ac4:      	ldr	x17, [x16, #0x578]
  134ac8:      	add	x16, x16, #0x578
  134acc:      	br	x17

0000000000134ad0 <sws_getCachedContext@plt>:
  134ad0:      	adrp	x16, 0x13c000
  134ad4:      	ldr	x17, [x16, #0x580]
  134ad8:      	add	x16, x16, #0x580
  134adc:      	br	x17

0000000000134ae0 <av_frame_make_writable@plt>:
  134ae0:      	adrp	x16, 0x13c000
  134ae4:      	ldr	x17, [x16, #0x588]
  134ae8:      	add	x16, x16, #0x588
  134aec:      	br	x17

0000000000134af0 <_ZN3PVG12PVGVideoInfoD1Ev@plt>:
  134af0:      	adrp	x16, 0x13c000
  134af4:      	ldr	x17, [x16, #0x590]
  134af8:      	add	x16, x16, #0x590
  134afc:      	br	x17

0000000000134b00 <av_log@plt>:
  134b00:      	adrp	x16, 0x13c000
  134b04:      	ldr	x17, [x16, #0x598]
  134b08:      	add	x16, x16, #0x598
  134b0c:      	br	x17

0000000000134b10 <_ZN3PVG15PVGVideoToImageD1Ev@plt>:
  134b10:      	adrp	x16, 0x13c000
  134b14:      	ldr	x17, [x16, #0x5a0]
  134b18:      	add	x16, x16, #0x5a0
  134b1c:      	br	x17

0000000000134b20 <_ZN3PVG12PVGWaterMark6createEv@plt>:
  134b20:      	adrp	x16, 0x13c000
  134b24:      	ldr	x17, [x16, #0x5a8]
  134b28:      	add	x16, x16, #0x5a8
  134b2c:      	br	x17

0000000000134b30 <_ZN3PVG12PVGWaterMark4openERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134b30:      	adrp	x16, 0x13c000
  134b34:      	ldr	x17, [x16, #0x5b0]
  134b38:      	add	x16, x16, #0x5b0
  134b3c:      	br	x17

0000000000134b40 <_ZN3PVG12PVGWaterMark13setParamHintsERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  134b40:      	adrp	x16, 0x13c000
  134b44:      	ldr	x17, [x16, #0x5b8]
  134b48:      	add	x16, x16, #0x5b8
  134b4c:      	br	x17

0000000000134b50 <_ZN3PVG12PVGWaterMark12setWatermarkERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEiiiiff@plt>:
  134b50:      	adrp	x16, 0x13c000
  134b54:      	ldr	x17, [x16, #0x5c0]
  134b58:      	add	x16, x16, #0x5c0
  134b5c:      	br	x17

0000000000134b60 <_ZN3PVG12PVGWaterMark9transcodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134b60:      	adrp	x16, 0x13c000
  134b64:      	ldr	x17, [x16, #0x5c8]
  134b68:      	add	x16, x16, #0x5c8
  134b6c:      	br	x17

0000000000134b70 <_ZN3PVG12PVGWaterMark5closeEv@plt>:
  134b70:      	adrp	x16, 0x13c000
  134b74:      	ldr	x17, [x16, #0x5d0]
  134b78:      	add	x16, x16, #0x5d0
  134b7c:      	br	x17

0000000000134b80 <_ZN3PVG12PVGWaterMark5abortEv@plt>:
  134b80:      	adrp	x16, 0x13c000
  134b84:      	ldr	x17, [x16, #0x5d8]
  134b88:      	add	x16, x16, #0x5d8
  134b8c:      	br	x17

0000000000134b90 <_ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE@plt>:
  134b90:      	adrp	x16, 0x13c000
  134b94:      	ldr	x17, [x16, #0x5e0]
  134b98:      	add	x16, x16, #0x5e0
  134b9c:      	br	x17

0000000000134ba0 <_ZN3PVG12PVGWaterMarkD1Ev@plt>:
  134ba0:      	adrp	x16, 0x13c000
  134ba4:      	ldr	x17, [x16, #0x5e8]
  134ba8:      	add	x16, x16, #0x5e8
  134bac:      	br	x17

0000000000134bb0 <_ZN3PVG12MediaClipper7releaseEv@plt>:
  134bb0:      	adrp	x16, 0x13c000
  134bb4:      	ldr	x17, [x16, #0x5f0]
  134bb8:      	add	x16, x16, #0x5f0
  134bbc:      	br	x17

0000000000134bc0 <_ZN3PVG12MediaClipperD1Ev@plt>:
  134bc0:      	adrp	x16, 0x13c000
  134bc4:      	ldr	x17, [x16, #0x5f8]
  134bc8:      	add	x16, x16, #0x5f8
  134bcc:      	br	x17

0000000000134bd0 <_ZN3PVG12MediaClipper8addMediaERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEdddd@plt>:
  134bd0:      	adrp	x16, 0x13c000
  134bd4:      	ldr	x17, [x16, #0x600]
  134bd8:      	add	x16, x16, #0x600
  134bdc:      	br	x17

0000000000134be0 <_ZNK3PVG12MediaClipper11getDurationEv@plt>:
  134be0:      	adrp	x16, 0x13c000
  134be4:      	ldr	x17, [x16, #0x608]
  134be8:      	add	x16, x16, #0x608
  134bec:      	br	x17

0000000000134bf0 <_ZN3PVG12MediaClipper11setListenerENSt6__ndk110shared_ptrINS_11PVGListenerEEE@plt>:
  134bf0:      	adrp	x16, 0x13c000
  134bf4:      	ldr	x17, [x16, #0x610]
  134bf8:      	add	x16, x16, #0x610
  134bfc:      	br	x17

0000000000134c00 <_ZN3PVG12MediaClipper7processERNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  134c00:      	adrp	x16, 0x13c000
  134c04:      	ldr	x17, [x16, #0x618]
  134c08:      	add	x16, x16, #0x618
  134c0c:      	br	x17

0000000000134c10 <_ZN3PVG12MediaClipper5abortEv@plt>:
  134c10:      	adrp	x16, 0x13c000
  134c14:      	ldr	x17, [x16, #0x620]
  134c18:      	add	x16, x16, #0x620
  134c1c:      	br	x17

0000000000134c20 <_ZN3PVG12MediaClipperC1Ev@plt>:
  134c20:      	adrp	x16, 0x13c000
  134c24:      	ldr	x17, [x16, #0x628]
  134c28:      	add	x16, x16, #0x628
  134c2c:      	br	x17

0000000000134c30 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
  134c30:      	adrp	x16, 0x13c000
  134c34:      	ldr	x17, [x16, #0x630]
  134c38:      	add	x16, x16, #0x630
  134c3c:      	br	x17

0000000000134c40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  134c40:      	adrp	x16, 0x13c000
  134c44:      	ldr	x17, [x16, #0x638]
  134c48:      	add	x16, x16, #0x638
  134c4c:      	br	x17

0000000000134c50 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
  134c50:      	adrp	x16, 0x13c000
  134c54:      	ldr	x17, [x16, #0x640]
  134c58:      	add	x16, x16, #0x640
  134c5c:      	br	x17

0000000000134c60 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgENS_4fposI9mbstate_tEE@plt>:
  134c60:      	adrp	x16, 0x13c000
  134c64:      	ldr	x17, [x16, #0x648]
  134c68:      	add	x16, x16, #0x648
  134c6c:      	br	x17

0000000000134c70 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4peekEv@plt>:
  134c70:      	adrp	x16, 0x13c000
  134c74:      	ldr	x17, [x16, #0x650]
  134c78:      	add	x16, x16, #0x650
  134c7c:      	br	x17

0000000000134c80 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgExNS_8ios_base7seekdirE@plt>:
  134c80:      	adrp	x16, 0x13c000
  134c84:      	ldr	x17, [x16, #0x658]
  134c88:      	add	x16, x16, #0x658
  134c8c:      	br	x17

0000000000134c90 <av_fast_malloc@plt>:
  134c90:      	adrp	x16, 0x13c000
  134c94:      	ldr	x17, [x16, #0x660]
  134c98:      	add	x16, x16, #0x660
  134c9c:      	br	x17

0000000000134ca0 <calloc@plt>:
  134ca0:      	adrp	x16, 0x13c000
  134ca4:      	ldr	x17, [x16, #0x668]
  134ca8:      	add	x16, x16, #0x668
  134cac:      	br	x17

0000000000134cb0 <_ZN3PVG13PVGTextReader11_fillBufferEv@plt>:
  134cb0:      	adrp	x16, 0x13c000
  134cb4:      	ldr	x17, [x16, #0x670]
  134cb8:      	add	x16, x16, #0x670
  134cbc:      	br	x17

0000000000134cc0 <fseek@plt>:
  134cc0:      	adrp	x16, 0x13c000
  134cc4:      	ldr	x17, [x16, #0x678]
  134cc8:      	add	x16, x16, #0x678
  134ccc:      	br	x17

0000000000134cd0 <ftell@plt>:
  134cd0:      	adrp	x16, 0x13c000
  134cd4:      	ldr	x17, [x16, #0x680]
  134cd8:      	add	x16, x16, #0x680
  134cdc:      	br	x17

0000000000134ce0 <_ZN3PVG21PVGSubtitlesParserASS19_parserContentStyleERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS1_6vectorIS7_NS5_IS7_EEEE@plt>:
  134ce0:      	adrp	x16, 0x13c000
  134ce4:      	ldr	x17, [x16, #0x688]
  134ce8:      	add	x16, x16, #0x688
  134cec:      	br	x17

0000000000134cf0 <_ZN3PVG21PVGSubtitlesParserASS10parserLineENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_15PVGSubtitleItemE@plt>:
  134cf0:      	adrp	x16, 0x13c000
  134cf4:      	ldr	x17, [x16, #0x690]
  134cf8:      	add	x16, x16, #0x690
  134cfc:      	br	x17

0000000000134d00 <sscanf@plt>:
  134d00:      	adrp	x16, 0x13c000
  134d04:      	ldr	x17, [x16, #0x698]
  134d08:      	add	x16, x16, #0x698
  134d0c:      	br	x17

0000000000134d10 <strtol@plt>:
  134d10:      	adrp	x16, 0x13c000
  134d14:      	ldr	x17, [x16, #0x6a0]
  134d18:      	add	x16, x16, #0x6a0
  134d1c:      	br	x17

0000000000134d20 <_ZN3PVG21PVGSubtitlesParserLRC10parserLineENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_15PVGSubtitleItemE@plt>:
  134d20:      	adrp	x16, 0x13c000
  134d24:      	ldr	x17, [x16, #0x6a8]
  134d28:      	add	x16, x16, #0x6a8
  134d2c:      	br	x17

0000000000134d30 <cosf@plt>:
  134d30:      	adrp	x16, 0x13c000
  134d34:      	ldr	x17, [x16, #0x6b0]
  134d38:      	add	x16, x16, #0x6b0
  134d3c:      	br	x17

0000000000134d40 <sincosf@plt>:
  134d40:      	adrp	x16, 0x13c000
  134d44:      	ldr	x17, [x16, #0x6b8]
  134d48:      	add	x16, x16, #0x6b8
  134d4c:      	br	x17

0000000000134d50 <logf@plt>:
  134d50:      	adrp	x16, 0x13c000
  134d54:      	ldr	x17, [x16, #0x6c0]
  134d58:      	add	x16, x16, #0x6c0
  134d5c:      	br	x17

0000000000134d60 <expf@plt>:
  134d60:      	adrp	x16, 0x13c000
  134d64:      	ldr	x17, [x16, #0x6c8]
  134d68:      	add	x16, x16, #0x6c8
  134d6c:      	br	x17

0000000000134d70 <powf@plt>:
  134d70:      	adrp	x16, 0x13c000
  134d74:      	ldr	x17, [x16, #0x6d0]
  134d78:      	add	x16, x16, #0x6d0
  134d7c:      	br	x17

0000000000134d80 <tanhf@plt>:
  134d80:      	adrp	x16, 0x13c000
  134d84:      	ldr	x17, [x16, #0x6d8]
  134d88:      	add	x16, x16, #0x6d8
  134d8c:      	br	x17

0000000000134d90 <glBindFramebuffer@plt>:
  134d90:      	adrp	x16, 0x13c000
  134d94:      	ldr	x17, [x16, #0x6e0]
  134d98:      	add	x16, x16, #0x6e0
  134d9c:      	br	x17

0000000000134da0 <glDeleteFramebuffers@plt>:
  134da0:      	adrp	x16, 0x13c000
  134da4:      	ldr	x17, [x16, #0x6e8]
  134da8:      	add	x16, x16, #0x6e8
  134dac:      	br	x17

0000000000134db0 <glBindTexture@plt>:
  134db0:      	adrp	x16, 0x13c000
  134db4:      	ldr	x17, [x16, #0x6f0]
  134db8:      	add	x16, x16, #0x6f0
  134dbc:      	br	x17

0000000000134dc0 <glBindRenderbuffer@plt>:
  134dc0:      	adrp	x16, 0x13c000
  134dc4:      	ldr	x17, [x16, #0x6f8]
  134dc8:      	add	x16, x16, #0x6f8
  134dcc:      	br	x17

0000000000134dd0 <glDeleteRenderbuffers@plt>:
  134dd0:      	adrp	x16, 0x13c000
  134dd4:      	ldr	x17, [x16, #0x700]
  134dd8:      	add	x16, x16, #0x700
  134ddc:      	br	x17

0000000000134de0 <glGenTextures@plt>:
  134de0:      	adrp	x16, 0x13c000
  134de4:      	ldr	x17, [x16, #0x708]
  134de8:      	add	x16, x16, #0x708
  134dec:      	br	x17

0000000000134df0 <glTexImage2D@plt>:
  134df0:      	adrp	x16, 0x13c000
  134df4:      	ldr	x17, [x16, #0x710]
  134df8:      	add	x16, x16, #0x710
  134dfc:      	br	x17

0000000000134e00 <glTexParameterf@plt>:
  134e00:      	adrp	x16, 0x13c000
  134e04:      	ldr	x17, [x16, #0x718]
  134e08:      	add	x16, x16, #0x718
  134e0c:      	br	x17

0000000000134e10 <glTexParameteri@plt>:
  134e10:      	adrp	x16, 0x13c000
  134e14:      	ldr	x17, [x16, #0x720]
  134e18:      	add	x16, x16, #0x720
  134e1c:      	br	x17

0000000000134e20 <glGenFramebuffers@plt>:
  134e20:      	adrp	x16, 0x13c000
  134e24:      	ldr	x17, [x16, #0x728]
  134e28:      	add	x16, x16, #0x728
  134e2c:      	br	x17

0000000000134e30 <glGenRenderbuffers@plt>:
  134e30:      	adrp	x16, 0x13c000
  134e34:      	ldr	x17, [x16, #0x730]
  134e38:      	add	x16, x16, #0x730
  134e3c:      	br	x17

0000000000134e40 <glRenderbufferStorage@plt>:
  134e40:      	adrp	x16, 0x13c000
  134e44:      	ldr	x17, [x16, #0x738]
  134e48:      	add	x16, x16, #0x738
  134e4c:      	br	x17

0000000000134e50 <glFramebufferRenderbuffer@plt>:
  134e50:      	adrp	x16, 0x13c000
  134e54:      	ldr	x17, [x16, #0x740]
  134e58:      	add	x16, x16, #0x740
  134e5c:      	br	x17

0000000000134e60 <glFramebufferTexture2D@plt>:
  134e60:      	adrp	x16, 0x13c000
  134e64:      	ldr	x17, [x16, #0x748]
  134e68:      	add	x16, x16, #0x748
  134e6c:      	br	x17

0000000000134e70 <glCheckFramebufferStatus@plt>:
  134e70:      	adrp	x16, 0x13c000
  134e74:      	ldr	x17, [x16, #0x750]
  134e78:      	add	x16, x16, #0x750
  134e7c:      	br	x17

0000000000134e80 <glGetIntegerv@plt>:
  134e80:      	adrp	x16, 0x13c000
  134e84:      	ldr	x17, [x16, #0x758]
  134e88:      	add	x16, x16, #0x758
  134e8c:      	br	x17

0000000000134e90 <glViewport@plt>:
  134e90:      	adrp	x16, 0x13c000
  134e94:      	ldr	x17, [x16, #0x760]
  134e98:      	add	x16, x16, #0x760
  134e9c:      	br	x17

0000000000134ea0 <glCreateShader@plt>:
  134ea0:      	adrp	x16, 0x13c000
  134ea4:      	ldr	x17, [x16, #0x768]
  134ea8:      	add	x16, x16, #0x768
  134eac:      	br	x17

0000000000134eb0 <glShaderSource@plt>:
  134eb0:      	adrp	x16, 0x13c000
  134eb4:      	ldr	x17, [x16, #0x770]
  134eb8:      	add	x16, x16, #0x770
  134ebc:      	br	x17

0000000000134ec0 <glCompileShader@plt>:
  134ec0:      	adrp	x16, 0x13c000
  134ec4:      	ldr	x17, [x16, #0x778]
  134ec8:      	add	x16, x16, #0x778
  134ecc:      	br	x17

0000000000134ed0 <glGetShaderiv@plt>:
  134ed0:      	adrp	x16, 0x13c000
  134ed4:      	ldr	x17, [x16, #0x780]
  134ed8:      	add	x16, x16, #0x780
  134edc:      	br	x17

0000000000134ee0 <glCreateProgram@plt>:
  134ee0:      	adrp	x16, 0x13c000
  134ee4:      	ldr	x17, [x16, #0x788]
  134ee8:      	add	x16, x16, #0x788
  134eec:      	br	x17

0000000000134ef0 <glAttachShader@plt>:
  134ef0:      	adrp	x16, 0x13c000
  134ef4:      	ldr	x17, [x16, #0x790]
  134ef8:      	add	x16, x16, #0x790
  134efc:      	br	x17

0000000000134f00 <glLinkProgram@plt>:
  134f00:      	adrp	x16, 0x13c000
  134f04:      	ldr	x17, [x16, #0x798]
  134f08:      	add	x16, x16, #0x798
  134f0c:      	br	x17

0000000000134f10 <glGetProgramiv@plt>:
  134f10:      	adrp	x16, 0x13c000
  134f14:      	ldr	x17, [x16, #0x7a0]
  134f18:      	add	x16, x16, #0x7a0
  134f1c:      	br	x17

0000000000134f20 <glDetachShader@plt>:
  134f20:      	adrp	x16, 0x13c000
  134f24:      	ldr	x17, [x16, #0x7a8]
  134f28:      	add	x16, x16, #0x7a8
  134f2c:      	br	x17

0000000000134f30 <glDeleteShader@plt>:
  134f30:      	adrp	x16, 0x13c000
  134f34:      	ldr	x17, [x16, #0x7b0]
  134f38:      	add	x16, x16, #0x7b0
  134f3c:      	br	x17

0000000000134f40 <glGetShaderInfoLog@plt>:
  134f40:      	adrp	x16, 0x13c000
  134f44:      	ldr	x17, [x16, #0x7b8]
  134f48:      	add	x16, x16, #0x7b8
  134f4c:      	br	x17

0000000000134f50 <glGetProgramInfoLog@plt>:
  134f50:      	adrp	x16, 0x13c000
  134f54:      	ldr	x17, [x16, #0x7c0]
  134f58:      	add	x16, x16, #0x7c0
  134f5c:      	br	x17

0000000000134f60 <glDeleteProgram@plt>:
  134f60:      	adrp	x16, 0x13c000
  134f64:      	ldr	x17, [x16, #0x7c8]
  134f68:      	add	x16, x16, #0x7c8
  134f6c:      	br	x17

0000000000134f70 <glGetUniformLocation@plt>:
  134f70:      	adrp	x16, 0x13c000
  134f74:      	ldr	x17, [x16, #0x7d0]
  134f78:      	add	x16, x16, #0x7d0
  134f7c:      	br	x17

0000000000134f80 <glGetAttribLocation@plt>:
  134f80:      	adrp	x16, 0x13c000
  134f84:      	ldr	x17, [x16, #0x7d8]
  134f88:      	add	x16, x16, #0x7d8
  134f8c:      	br	x17

0000000000134f90 <glEnable@plt>:
  134f90:      	adrp	x16, 0x13c000
  134f94:      	ldr	x17, [x16, #0x7e0]
  134f98:      	add	x16, x16, #0x7e0
  134f9c:      	br	x17

0000000000134fa0 <glBlendFunc@plt>:
  134fa0:      	adrp	x16, 0x13c000
  134fa4:      	ldr	x17, [x16, #0x7e8]
  134fa8:      	add	x16, x16, #0x7e8
  134fac:      	br	x17

0000000000134fb0 <glBlendFuncSeparate@plt>:
  134fb0:      	adrp	x16, 0x13c000
  134fb4:      	ldr	x17, [x16, #0x7f0]
  134fb8:      	add	x16, x16, #0x7f0
  134fbc:      	br	x17

0000000000134fc0 <glUseProgram@plt>:
  134fc0:      	adrp	x16, 0x13c000
  134fc4:      	ldr	x17, [x16, #0x7f8]
  134fc8:      	add	x16, x16, #0x7f8
  134fcc:      	br	x17

0000000000134fd0 <glActiveTexture@plt>:
  134fd0:      	adrp	x16, 0x13c000
  134fd4:      	ldr	x17, [x16, #0x800]
  134fd8:      	add	x16, x16, #0x800
  134fdc:      	br	x17

0000000000134fe0 <glUniform1i@plt>:
  134fe0:      	adrp	x16, 0x13c000
  134fe4:      	ldr	x17, [x16, #0x808]
  134fe8:      	add	x16, x16, #0x808
  134fec:      	br	x17

0000000000134ff0 <glBindBuffer@plt>:
  134ff0:      	adrp	x16, 0x13c000
  134ff4:      	ldr	x17, [x16, #0x810]
  134ff8:      	add	x16, x16, #0x810
  134ffc:      	br	x17

0000000000135000 <glUniformMatrix4fv@plt>:
  135000:      	adrp	x16, 0x13c000
  135004:      	ldr	x17, [x16, #0x818]
  135008:      	add	x16, x16, #0x818
  13500c:      	br	x17

0000000000135010 <glEnableVertexAttribArray@plt>:
  135010:      	adrp	x16, 0x13c000
  135014:      	ldr	x17, [x16, #0x820]
  135018:      	add	x16, x16, #0x820
  13501c:      	br	x17

0000000000135020 <glVertexAttribPointer@plt>:
  135020:      	adrp	x16, 0x13c000
  135024:      	ldr	x17, [x16, #0x828]
  135028:      	add	x16, x16, #0x828
  13502c:      	br	x17

0000000000135030 <glDrawArrays@plt>:
  135030:      	adrp	x16, 0x13c000
  135034:      	ldr	x17, [x16, #0x830]
  135038:      	add	x16, x16, #0x830
  13503c:      	br	x17

0000000000135040 <glDisableVertexAttribArray@plt>:
  135040:      	adrp	x16, 0x13c000
  135044:      	ldr	x17, [x16, #0x838]
  135048:      	add	x16, x16, #0x838
  13504c:      	br	x17

0000000000135050 <glDisable@plt>:
  135050:      	adrp	x16, 0x13c000
  135054:      	ldr	x17, [x16, #0x840]
  135058:      	add	x16, x16, #0x840
  13505c:      	br	x17

0000000000135060 <__read_chk@plt>:
  135060:      	adrp	x16, 0x13c000
  135064:      	ldr	x17, [x16, #0x848]
  135068:      	add	x16, x16, #0x848
  13506c:      	br	x17

0000000000135070 <write@plt>:
  135070:      	adrp	x16, 0x13c000
  135074:      	ldr	x17, [x16, #0x850]
  135078:      	add	x16, x16, #0x850
  13507c:      	br	x17

0000000000135080 <lseek@plt>:
  135080:      	adrp	x16, 0x13c000
  135084:      	ldr	x17, [x16, #0x858]
  135088:      	add	x16, x16, #0x858
  13508c:      	br	x17

0000000000135090 <pthread_getspecific@plt>:
  135090:      	adrp	x16, 0x13c000
  135094:      	ldr	x17, [x16, #0x860]
  135098:      	add	x16, x16, #0x860
  13509c:      	br	x17

00000000001350a0 <pthread_key_create@plt>:
  1350a0:      	adrp	x16, 0x13c000
  1350a4:      	ldr	x17, [x16, #0x868]
  1350a8:      	add	x16, x16, #0x868
  1350ac:      	br	x17

00000000001350b0 <getauxval@plt>:
  1350b0:      	adrp	x16, 0x13c000
  1350b4:      	ldr	x17, [x16, #0x870]
  1350b8:      	add	x16, x16, #0x870
  1350bc:      	br	x17

00000000001350c0 <__system_property_get@plt>:
  1350c0:      	adrp	x16, 0x13c000
  1350c4:      	ldr	x17, [x16, #0x878]
  1350c8:      	add	x16, x16, #0x878
  1350cc:      	br	x17

00000000001350d0 <strncmp@plt>:
  1350d0:      	adrp	x16, 0x13c000
  1350d4:      	ldr	x17, [x16, #0x880]
  1350d8:      	add	x16, x16, #0x880
  1350dc:      	br	x17

00000000001350e0 <abort@plt>:
  1350e0:      	adrp	x16, 0x13c000
  1350e4:      	ldr	x17, [x16, #0x888]
  1350e8:      	add	x16, x16, #0x888
  1350ec:      	br	x17

00000000001350f0 <pthread_rwlock_wrlock@plt>:
  1350f0:      	adrp	x16, 0x13c000
  1350f4:      	ldr	x17, [x16, #0x890]
  1350f8:      	add	x16, x16, #0x890
  1350fc:      	br	x17

0000000000135100 <pthread_rwlock_unlock@plt>:
  135100:      	adrp	x16, 0x13c000
  135104:      	ldr	x17, [x16, #0x898]
  135108:      	add	x16, x16, #0x898
  13510c:      	br	x17

0000000000135110 <dl_iterate_phdr@plt>:
  135110:      	adrp	x16, 0x13c000
  135114:      	ldr	x17, [x16, #0x8a0]
  135118:      	add	x16, x16, #0x8a0
  13511c:      	br	x17

0000000000135120 <pthread_rwlock_rdlock@plt>:
  135120:      	adrp	x16, 0x13c000
  135124:      	ldr	x17, [x16, #0x8a8]
  135128:      	add	x16, x16, #0x8a8
  13512c:      	br	x17

0000000000135130 <getpid@plt>:
  135130:      	adrp	x16, 0x13c000
  135134:      	ldr	x17, [x16, #0x8b0]
  135138:      	add	x16, x16, #0x8b0
  13513c:      	br	x17

0000000000135140 <syscall@plt>:
  135140:      	adrp	x16, 0x13c000
  135144:      	ldr	x17, [x16, #0x8b8]
  135148:      	add	x16, x16, #0x8b8
  13514c:      	br	x17
