// EXPORTED & PLT DISASSEMBLY FOR libMTGif.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTGif.so (SHA-256: A896D526A7EE74611FFD9A611B797C65505E60B4C60FF27FAB75ECABBE69A134)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 135, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTGif.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000012a60 <.plt>:
   12a60:      	stp	x16, x30, [sp, #-0x10]!
   12a64:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12a68:      	ldr	x17, [x16, #0x800]
   12a6c:      	add	x16, x16, #0x800
   12a70:      	br	x17
   12a74:      	nop
   12a78:      	nop
   12a7c:      	nop

0000000000012a80 <__cxa_finalize@plt>:
   12a80:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12a84:      	ldr	x17, [x16, #0x808]
   12a88:      	add	x16, x16, #0x808
   12a8c:      	br	x17

0000000000012a90 <__cxa_atexit@plt>:
   12a90:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12a94:      	ldr	x17, [x16, #0x810]
   12a98:      	add	x16, x16, #0x810
   12a9c:      	br	x17

0000000000012aa0 <malloc@plt>:
   12aa0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12aa4:      	ldr	x17, [x16, #0x818]
   12aa8:      	add	x16, x16, #0x818
   12aac:      	br	x17

0000000000012ab0 <av_packet_alloc@plt>:
   12ab0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ab4:      	ldr	x17, [x16, #0x820]
   12ab8:      	add	x16, x16, #0x820
   12abc:      	br	x17

0000000000012ac0 <pthread_mutex_unlock@plt>:
   12ac0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ac4:      	ldr	x17, [x16, #0x828]
   12ac8:      	add	x16, x16, #0x828
   12acc:      	br	x17

0000000000012ad0 <pthread_mutex_lock@plt>:
   12ad0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ad4:      	ldr	x17, [x16, #0x830]
   12ad8:      	add	x16, x16, #0x830
   12adc:      	br	x17

0000000000012ae0 <pthread_cond_wait@plt>:
   12ae0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ae4:      	ldr	x17, [x16, #0x838]
   12ae8:      	add	x16, x16, #0x838
   12aec:      	br	x17

0000000000012af0 <av_read_frame@plt>:
   12af0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12af4:      	ldr	x17, [x16, #0x840]
   12af8:      	add	x16, x16, #0x840
   12afc:      	br	x17

0000000000012b00 <avcodec_send_packet@plt>:
   12b00:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b04:      	ldr	x17, [x16, #0x848]
   12b08:      	add	x16, x16, #0x848
   12b0c:      	br	x17

0000000000012b10 <av_packet_unref@plt>:
   12b10:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b14:      	ldr	x17, [x16, #0x850]
   12b18:      	add	x16, x16, #0x850
   12b1c:      	br	x17

0000000000012b20 <av_frame_alloc@plt>:
   12b20:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b24:      	ldr	x17, [x16, #0x858]
   12b28:      	add	x16, x16, #0x858
   12b2c:      	br	x17

0000000000012b30 <avcodec_receive_frame@plt>:
   12b30:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b34:      	ldr	x17, [x16, #0x860]
   12b38:      	add	x16, x16, #0x860
   12b3c:      	br	x17

0000000000012b40 <av_frame_get_best_effort_timestamp@plt>:
   12b40:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b44:      	ldr	x17, [x16, #0x868]
   12b48:      	add	x16, x16, #0x868
   12b4c:      	br	x17

0000000000012b50 <_ZN13FormatConvert18VideoFormatTranser13_ImageConvertEPP7AVFrame@plt>:
   12b50:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b54:      	ldr	x17, [x16, #0x870]
   12b58:      	add	x16, x16, #0x870
   12b5c:      	br	x17

0000000000012b60 <_Znwm@plt>:
   12b60:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b64:      	ldr	x17, [x16, #0x878]
   12b68:      	add	x16, x16, #0x878
   12b6c:      	br	x17

0000000000012b70 <pthread_cond_signal@plt>:
   12b70:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b74:      	ldr	x17, [x16, #0x880]
   12b78:      	add	x16, x16, #0x880
   12b7c:      	br	x17

0000000000012b80 <av_frame_free@plt>:
   12b80:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b84:      	ldr	x17, [x16, #0x888]
   12b88:      	add	x16, x16, #0x888
   12b8c:      	br	x17

0000000000012b90 <av_packet_free@plt>:
   12b90:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12b94:      	ldr	x17, [x16, #0x890]
   12b98:      	add	x16, x16, #0x890
   12b9c:      	br	x17

0000000000012ba0 <_ZN13FormatConvert18VideoFormatTranser6_flushEv@plt>:
   12ba0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ba4:      	ldr	x17, [x16, #0x898]
   12ba8:      	add	x16, x16, #0x898
   12bac:      	br	x17

0000000000012bb0 <_ZN13FormatConvert18VideoFormatTranser8_releaseEv@plt>:
   12bb0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12bb4:      	ldr	x17, [x16, #0x8a0]
   12bb8:      	add	x16, x16, #0x8a0
   12bbc:      	br	x17

0000000000012bc0 <__stack_chk_fail@plt>:
   12bc0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12bc4:      	ldr	x17, [x16, #0x8a8]
   12bc8:      	add	x16, x16, #0x8a8
   12bcc:      	br	x17

0000000000012bd0 <av_image_alloc@plt>:
   12bd0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12bd4:      	ldr	x17, [x16, #0x8b0]
   12bd8:      	add	x16, x16, #0x8b0
   12bdc:      	br	x17

0000000000012be0 <sws_scale@plt>:
   12be0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12be4:      	ldr	x17, [x16, #0x8b8]
   12be8:      	add	x16, x16, #0x8b8
   12bec:      	br	x17

0000000000012bf0 <av_freep@plt>:
   12bf0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12bf4:      	ldr	x17, [x16, #0x8c0]
   12bf8:      	add	x16, x16, #0x8c0
   12bfc:      	br	x17

0000000000012c00 <exit@plt>:
   12c00:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c04:      	ldr	x17, [x16, #0x8c8]
   12c08:      	add	x16, x16, #0x8c8
   12c0c:      	br	x17

0000000000012c10 <avcodec_is_open@plt>:
   12c10:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c14:      	ldr	x17, [x16, #0x8d0]
   12c18:      	add	x16, x16, #0x8d0
   12c1c:      	br	x17

0000000000012c20 <avcodec_close@plt>:
   12c20:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c24:      	ldr	x17, [x16, #0x8d8]
   12c28:      	add	x16, x16, #0x8d8
   12c2c:      	br	x17

0000000000012c30 <avcodec_free_context@plt>:
   12c30:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c34:      	ldr	x17, [x16, #0x8e0]
   12c38:      	add	x16, x16, #0x8e0
   12c3c:      	br	x17

0000000000012c40 <avformat_close_input@plt>:
   12c40:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c44:      	ldr	x17, [x16, #0x8e8]
   12c48:      	add	x16, x16, #0x8e8
   12c4c:      	br	x17

0000000000012c50 <sws_freeContext@plt>:
   12c50:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c54:      	ldr	x17, [x16, #0x8f0]
   12c58:      	add	x16, x16, #0x8f0
   12c5c:      	br	x17

0000000000012c60 <pthread_cond_init@plt>:
   12c60:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c64:      	ldr	x17, [x16, #0x8f8]
   12c68:      	add	x16, x16, #0x8f8
   12c6c:      	br	x17

0000000000012c70 <pthread_mutex_init@plt>:
   12c70:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c74:      	ldr	x17, [x16, #0x900]
   12c78:      	add	x16, x16, #0x900
   12c7c:      	br	x17

0000000000012c80 <_ZdlPv@plt>:
   12c80:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c84:      	ldr	x17, [x16, #0x908]
   12c88:      	add	x16, x16, #0x908
   12c8c:      	br	x17

0000000000012c90 <_ZN13FormatConvert18VideoFormatTranser7prepareEv@plt>:
   12c90:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12c94:      	ldr	x17, [x16, #0x910]
   12c98:      	add	x16, x16, #0x910
   12c9c:      	br	x17

0000000000012ca0 <av_register_all@plt>:
   12ca0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ca4:      	ldr	x17, [x16, #0x918]
   12ca8:      	add	x16, x16, #0x918
   12cac:      	br	x17

0000000000012cb0 <avformat_network_init@plt>:
   12cb0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12cb4:      	ldr	x17, [x16, #0x920]
   12cb8:      	add	x16, x16, #0x920
   12cbc:      	br	x17

0000000000012cc0 <_ZN13FormatConvert18VideoFormatTranser18_InputMediaInitialEv@plt>:
   12cc0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12cc4:      	ldr	x17, [x16, #0x928]
   12cc8:      	add	x16, x16, #0x928
   12ccc:      	br	x17

0000000000012cd0 <_ZN13FormatConvert18VideoFormatTranser19_OutputMediaInitialEv@plt>:
   12cd0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12cd4:      	ldr	x17, [x16, #0x930]
   12cd8:      	add	x16, x16, #0x930
   12cdc:      	br	x17

0000000000012ce0 <_ZN13FormatConvert18VideoFormatTranser16_SwsMediaInitialEv@plt>:
   12ce0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ce4:      	ldr	x17, [x16, #0x938]
   12ce8:      	add	x16, x16, #0x938
   12cec:      	br	x17

0000000000012cf0 <avformat_open_input@plt>:
   12cf0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12cf4:      	ldr	x17, [x16, #0x940]
   12cf8:      	add	x16, x16, #0x940
   12cfc:      	br	x17

0000000000012d00 <avformat_find_stream_info@plt>:
   12d00:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d04:      	ldr	x17, [x16, #0x948]
   12d08:      	add	x16, x16, #0x948
   12d0c:      	br	x17

0000000000012d10 <av_find_best_stream@plt>:
   12d10:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d14:      	ldr	x17, [x16, #0x950]
   12d18:      	add	x16, x16, #0x950
   12d1c:      	br	x17

0000000000012d20 <avcodec_find_decoder@plt>:
   12d20:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d24:      	ldr	x17, [x16, #0x958]
   12d28:      	add	x16, x16, #0x958
   12d2c:      	br	x17

0000000000012d30 <avcodec_alloc_context3@plt>:
   12d30:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d34:      	ldr	x17, [x16, #0x960]
   12d38:      	add	x16, x16, #0x960
   12d3c:      	br	x17

0000000000012d40 <avcodec_parameters_to_context@plt>:
   12d40:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d44:      	ldr	x17, [x16, #0x968]
   12d48:      	add	x16, x16, #0x968
   12d4c:      	br	x17

0000000000012d50 <av_dict_get@plt>:
   12d50:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d54:      	ldr	x17, [x16, #0x970]
   12d58:      	add	x16, x16, #0x970
   12d5c:      	br	x17

0000000000012d60 <atoi@plt>:
   12d60:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d64:      	ldr	x17, [x16, #0x978]
   12d68:      	add	x16, x16, #0x978
   12d6c:      	br	x17

0000000000012d70 <av_image_get_buffer_size@plt>:
   12d70:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d74:      	ldr	x17, [x16, #0x980]
   12d78:      	add	x16, x16, #0x980
   12d7c:      	br	x17

0000000000012d80 <av_dump_format@plt>:
   12d80:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d84:      	ldr	x17, [x16, #0x988]
   12d88:      	add	x16, x16, #0x988
   12d8c:      	br	x17

0000000000012d90 <avcodec_open2@plt>:
   12d90:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12d94:      	ldr	x17, [x16, #0x990]
   12d98:      	add	x16, x16, #0x990
   12d9c:      	br	x17

0000000000012da0 <avformat_alloc_output_context2@plt>:
   12da0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12da4:      	ldr	x17, [x16, #0x998]
   12da8:      	add	x16, x16, #0x998
   12dac:      	br	x17

0000000000012db0 <avio_open@plt>:
   12db0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12db4:      	ldr	x17, [x16, #0x9a0]
   12db8:      	add	x16, x16, #0x9a0
   12dbc:      	br	x17

0000000000012dc0 <strlen@plt>:
   12dc0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12dc4:      	ldr	x17, [x16, #0x9a8]
   12dc8:      	add	x16, x16, #0x9a8
   12dcc:      	br	x17

0000000000012dd0 <__strncpy_chk@plt>:
   12dd0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12dd4:      	ldr	x17, [x16, #0x9b0]
   12dd8:      	add	x16, x16, #0x9b0
   12ddc:      	br	x17

0000000000012de0 <avcodec_find_encoder_by_name@plt>:
   12de0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12de4:      	ldr	x17, [x16, #0x9b8]
   12de8:      	add	x16, x16, #0x9b8
   12dec:      	br	x17

0000000000012df0 <avformat_new_stream@plt>:
   12df0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12df4:      	ldr	x17, [x16, #0x9c0]
   12df8:      	add	x16, x16, #0x9c0
   12dfc:      	br	x17

0000000000012e00 <av_opt_set@plt>:
   12e00:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e04:      	ldr	x17, [x16, #0x9c8]
   12e08:      	add	x16, x16, #0x9c8
   12e0c:      	br	x17

0000000000012e10 <av_dict_set@plt>:
   12e10:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e14:      	ldr	x17, [x16, #0x9d0]
   12e18:      	add	x16, x16, #0x9d0
   12e1c:      	br	x17

0000000000012e20 <av_dict_free@plt>:
   12e20:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e24:      	ldr	x17, [x16, #0x9d8]
   12e28:      	add	x16, x16, #0x9d8
   12e2c:      	br	x17

0000000000012e30 <avcodec_parameters_from_context@plt>:
   12e30:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e34:      	ldr	x17, [x16, #0x9e0]
   12e38:      	add	x16, x16, #0x9e0
   12e3c:      	br	x17

0000000000012e40 <sws_getContext@plt>:
   12e40:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e44:      	ldr	x17, [x16, #0x9e8]
   12e48:      	add	x16, x16, #0x9e8
   12e4c:      	br	x17

0000000000012e50 <_ZN13FormatConvert18VideoFormatTranser12receiveFrameEPPhPl@plt>:
   12e50:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e54:      	ldr	x17, [x16, #0x9f0]
   12e58:      	add	x16, x16, #0x9f0
   12e5c:      	br	x17

0000000000012e60 <av_mallocz@plt>:
   12e60:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e64:      	ldr	x17, [x16, #0x9f8]
   12e68:      	add	x16, x16, #0x9f8
   12e6c:      	br	x17

0000000000012e70 <memcpy@plt>:
   12e70:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e74:      	ldr	x17, [x16, #0xa00]
   12e78:      	add	x16, x16, #0xa00
   12e7c:      	br	x17

0000000000012e80 <av_rescale_q@plt>:
   12e80:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e84:      	ldr	x17, [x16, #0xa08]
   12e88:      	add	x16, x16, #0xa08
   12e8c:      	br	x17

0000000000012e90 <_ZN13FormatConvert18VideoFormatTranser4stopEv@plt>:
   12e90:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12e94:      	ldr	x17, [x16, #0xa10]
   12e98:      	add	x16, x16, #0xa10
   12e9c:      	br	x17

0000000000012ea0 <pthread_join@plt>:
   12ea0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ea4:      	ldr	x17, [x16, #0xa18]
   12ea8:      	add	x16, x16, #0xa18
   12eac:      	br	x17

0000000000012eb0 <pthread_cond_destroy@plt>:
   12eb0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12eb4:      	ldr	x17, [x16, #0xa20]
   12eb8:      	add	x16, x16, #0xa20
   12ebc:      	br	x17

0000000000012ec0 <pthread_mutex_destroy@plt>:
   12ec0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ec4:      	ldr	x17, [x16, #0xa28]
   12ec8:      	add	x16, x16, #0xa28
   12ecc:      	br	x17

0000000000012ed0 <_ZN13FormatConvert18VideoFormatTranser9doConvertEv@plt>:
   12ed0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ed4:      	ldr	x17, [x16, #0xa30]
   12ed8:      	add	x16, x16, #0xa30
   12edc:      	br	x17

0000000000012ee0 <avformat_write_header@plt>:
   12ee0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ee4:      	ldr	x17, [x16, #0xa38]
   12ee8:      	add	x16, x16, #0xa38
   12eec:      	br	x17

0000000000012ef0 <pthread_create@plt>:
   12ef0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ef4:      	ldr	x17, [x16, #0xa40]
   12ef8:      	add	x16, x16, #0xa40
   12efc:      	br	x17

0000000000012f00 <_ZN13FormatConvert18VideoFormatTranser11_TransMediaEPP8AVPacket@plt>:
   12f00:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f04:      	ldr	x17, [x16, #0xa48]
   12f08:      	add	x16, x16, #0xa48
   12f0c:      	br	x17

0000000000012f10 <av_interleaved_write_frame@plt>:
   12f10:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f14:      	ldr	x17, [x16, #0xa50]
   12f18:      	add	x16, x16, #0xa50
   12f1c:      	br	x17

0000000000012f20 <avcodec_send_frame@plt>:
   12f20:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f24:      	ldr	x17, [x16, #0xa58]
   12f28:      	add	x16, x16, #0xa58
   12f2c:      	br	x17

0000000000012f30 <avcodec_receive_packet@plt>:
   12f30:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f34:      	ldr	x17, [x16, #0xa60]
   12f38:      	add	x16, x16, #0xa60
   12f3c:      	br	x17

0000000000012f40 <free@plt>:
   12f40:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f44:      	ldr	x17, [x16, #0xa68]
   12f48:      	add	x16, x16, #0xa68
   12f4c:      	br	x17

0000000000012f50 <__cxa_begin_catch@plt>:
   12f50:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f54:      	ldr	x17, [x16, #0xa70]
   12f58:      	add	x16, x16, #0xa70
   12f5c:      	br	x17

0000000000012f60 <_ZSt9terminatev@plt>:
   12f60:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f64:      	ldr	x17, [x16, #0xa78]
   12f68:      	add	x16, x16, #0xa78
   12f6c:      	br	x17

0000000000012f70 <_ZN13FormatConvert18VideoFormatTranser22setInputVideoMediaFileEPc@plt>:
   12f70:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f74:      	ldr	x17, [x16, #0xa80]
   12f78:      	add	x16, x16, #0xa80
   12f7c:      	br	x17

0000000000012f80 <av_strdup@plt>:
   12f80:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f84:      	ldr	x17, [x16, #0xa88]
   12f88:      	add	x16, x16, #0xa88
   12f8c:      	br	x17

0000000000012f90 <_ZN13FormatConvert18VideoFormatTranser23setVideoOutputPixFormatENS_16IMAGE_PIX_FORMATE@plt>:
   12f90:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12f94:      	ldr	x17, [x16, #0xa90]
   12f98:      	add	x16, x16, #0xa90
   12f9c:      	br	x17

0000000000012fa0 <_ZN13FormatConvert18VideoFormatTranser18setVideoOutputSizeEii@plt>:
   12fa0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12fa4:      	ldr	x17, [x16, #0xa98]
   12fa8:      	add	x16, x16, #0xa98
   12fac:      	br	x17

0000000000012fb0 <_ZN13FormatConvert18VideoFormatTranserC1Ev@plt>:
   12fb0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12fb4:      	ldr	x17, [x16, #0xaa0]
   12fb8:      	add	x16, x16, #0xaa0
   12fbc:      	br	x17

0000000000012fc0 <_ZN13FormatConvert18VideoFormatTranserD1Ev@plt>:
   12fc0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12fc4:      	ldr	x17, [x16, #0xaa8]
   12fc8:      	add	x16, x16, #0xaa8
   12fcc:      	br	x17

0000000000012fd0 <_ZN11CMTImageGifC1Ev@plt>:
   12fd0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12fd4:      	ldr	x17, [x16, #0xab0]
   12fd8:      	add	x16, x16, #0xab0
   12fdc:      	br	x17

0000000000012fe0 <_ZN5MTGif13SaveGifHeaderEPKciiii@plt>:
   12fe0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12fe4:      	ldr	x17, [x16, #0xab8]
   12fe8:      	add	x16, x16, #0xab8
   12fec:      	br	x17

0000000000012ff0 <_ZN11CMTImageGif13SaveGifHeaderEPKciiii@plt>:
   12ff0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   12ff4:      	ldr	x17, [x16, #0xac0]
   12ff8:      	add	x16, x16, #0xac0
   12ffc:      	br	x17

0000000000013000 <_ZN11CMTImageGif12SaveGifFrameEPhi@plt>:
   13000:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13004:      	ldr	x17, [x16, #0xac8]
   13008:      	add	x16, x16, #0xac8
   1300c:      	br	x17

0000000000013010 <_ZN5MTGif12SaveGifFrameEPhi@plt>:
   13010:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13014:      	ldr	x17, [x16, #0xad0]
   13018:      	add	x16, x16, #0xad0
   1301c:      	br	x17

0000000000013020 <_ZN5MTGif9SaveCloseEv@plt>:
   13020:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13024:      	ldr	x17, [x16, #0xad8]
   13028:      	add	x16, x16, #0xad8
   1302c:      	br	x17

0000000000013030 <_ZN11CMTImageGif9SaveCloseEv@plt>:
   13030:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13034:      	ldr	x17, [x16, #0xae0]
   13038:      	add	x16, x16, #0xae0
   1303c:      	br	x17

0000000000013040 <_ZN11CMTImageGif12SetThreadNumEi@plt>:
   13040:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13044:      	ldr	x17, [x16, #0xae8]
   13048:      	add	x16, x16, #0xae8
   1304c:      	br	x17

0000000000013050 <_ZN5MTGifC1Ev@plt>:
   13050:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13054:      	ldr	x17, [x16, #0xaf0]
   13058:      	add	x16, x16, #0xaf0
   1305c:      	br	x17

0000000000013060 <_ZN5MTGifD1Ev@plt>:
   13060:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13064:      	ldr	x17, [x16, #0xaf8]
   13068:      	add	x16, x16, #0xaf8
   1306c:      	br	x17

0000000000013070 <get_nearest_index@plt>:
   13070:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13074:      	ldr	x17, [x16, #0xb00]
   13078:      	add	x16, x16, #0xb00
   1307c:      	br	x17

0000000000013080 <fclose@plt>:
   13080:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13084:      	ldr	x17, [x16, #0xb08]
   13088:      	add	x16, x16, #0xb08
   1308c:      	br	x17

0000000000013090 <_ZN11CMTImageGifD1Ev@plt>:
   13090:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13094:      	ldr	x17, [x16, #0xb10]
   13098:      	add	x16, x16, #0xb10
   1309c:      	br	x17

00000000000130a0 <_ZN11CMTImageGif11compressLZWEiPhP6CxFile@plt>:
   130a0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   130a4:      	ldr	x17, [x16, #0xb18]
   130a8:      	add	x16, x16, #0xb18
   130ac:      	br	x17

00000000000130b0 <memset@plt>:
   130b0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   130b4:      	ldr	x17, [x16, #0xb20]
   130b8:      	add	x16, x16, #0xb20
   130bc:      	br	x17

00000000000130c0 <_ZN11CMTImageGif6outputEs@plt>:
   130c0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   130c4:      	ldr	x17, [x16, #0xb28]
   130c8:      	add	x16, x16, #0xb28
   130cc:      	br	x17

00000000000130d0 <_ZN11CMTImageGif12DecreaseBpp2EPv@plt>:
   130d0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   130d4:      	ldr	x17, [x16, #0xb30]
   130d8:      	add	x16, x16, #0xb30
   130dc:      	br	x17

00000000000130e0 <_Znam@plt>:
   130e0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   130e4:      	ldr	x17, [x16, #0xb38]
   130e8:      	add	x16, x16, #0xb38
   130ec:      	br	x17

00000000000130f0 <_ZdaPv@plt>:
   130f0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   130f4:      	ldr	x17, [x16, #0xb40]
   130f8:      	add	x16, x16, #0xb40
   130fc:      	br	x17

0000000000013100 <pthread_exit@plt>:
   13100:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13104:      	ldr	x17, [x16, #0xb48]
   13108:      	add	x16, x16, #0xb48
   1310c:      	br	x17

0000000000013110 <fopen@plt>:
   13110:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13114:      	ldr	x17, [x16, #0xb50]
   13118:      	add	x16, x16, #0xb50
   1311c:      	br	x17

0000000000013120 <_ZN10CQuantizerC1Ejj@plt>:
   13120:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13124:      	ldr	x17, [x16, #0xb58]
   13128:      	add	x16, x16, #0xb58
   1312c:      	br	x17

0000000000013130 <_ZN10CQuantizer13SetColorTableEPh@plt>:
   13130:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13134:      	ldr	x17, [x16, #0xb60]
   13138:      	add	x16, x16, #0xb60
   1313c:      	br	x17

0000000000013140 <_ZN10CQuantizer13ProcessImage2EPhii@plt>:
   13140:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13144:      	ldr	x17, [x16, #0xb68]
   13148:      	add	x16, x16, #0xb68
   1314c:      	br	x17

0000000000013150 <sysconf@plt>:
   13150:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13154:      	ldr	x17, [x16, #0xb70]
   13158:      	add	x16, x16, #0xb70
   1315c:      	br	x17

0000000000013160 <pthread_attr_init@plt>:
   13160:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13164:      	ldr	x17, [x16, #0xb78]
   13168:      	add	x16, x16, #0xb78
   1316c:      	br	x17

0000000000013170 <fputc@plt>:
   13170:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13174:      	ldr	x17, [x16, #0xb80]
   13178:      	add	x16, x16, #0xb80
   1317c:      	br	x17

0000000000013180 <fread@plt>:
   13180:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13184:      	ldr	x17, [x16, #0xb88]
   13188:      	add	x16, x16, #0xb88
   1318c:      	br	x17

0000000000013190 <fwrite@plt>:
   13190:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13194:      	ldr	x17, [x16, #0xb90]
   13198:      	add	x16, x16, #0xb90
   1319c:      	br	x17

00000000000131a0 <fseek@plt>:
   131a0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   131a4:      	ldr	x17, [x16, #0xb98]
   131a8:      	add	x16, x16, #0xb98
   131ac:      	br	x17

00000000000131b0 <ftell@plt>:
   131b0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   131b4:      	ldr	x17, [x16, #0xba0]
   131b8:      	add	x16, x16, #0xba0
   131bc:      	br	x17

00000000000131c0 <fflush@plt>:
   131c0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   131c4:      	ldr	x17, [x16, #0xba8]
   131c8:      	add	x16, x16, #0xba8
   131cc:      	br	x17

00000000000131d0 <feof@plt>:
   131d0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   131d4:      	ldr	x17, [x16, #0xbb0]
   131d8:      	add	x16, x16, #0xbb0
   131dc:      	br	x17

00000000000131e0 <ferror@plt>:
   131e0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   131e4:      	ldr	x17, [x16, #0xbb8]
   131e8:      	add	x16, x16, #0xbb8
   131ec:      	br	x17

00000000000131f0 <getc@plt>:
   131f0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   131f4:      	ldr	x17, [x16, #0xbc0]
   131f8:      	add	x16, x16, #0xbc0
   131fc:      	br	x17

0000000000013200 <fgets@plt>:
   13200:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13204:      	ldr	x17, [x16, #0xbc8]
   13208:      	add	x16, x16, #0xbc8
   1320c:      	br	x17

0000000000013210 <fscanf@plt>:
   13210:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13214:      	ldr	x17, [x16, #0xbd0]
   13218:      	add	x16, x16, #0xbd0
   1321c:      	br	x17

0000000000013220 <_ZN10CQuantizer10DeleteTreeEPP5_NODE@plt>:
   13220:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13224:      	ldr	x17, [x16, #0xbd8]
   13228:      	add	x16, x16, #0xbd8
   1322c:      	br	x17

0000000000013230 <_ZN10CQuantizerD1Ev@plt>:
   13230:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13234:      	ldr	x17, [x16, #0xbe0]
   13238:      	add	x16, x16, #0xbe0
   1323c:      	br	x17

0000000000013240 <calloc@plt>:
   13240:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13244:      	ldr	x17, [x16, #0xbe8]
   13248:      	add	x16, x16, #0xbe8
   1324c:      	br	x17

0000000000013250 <_ZN10CQuantizer10ReduceTreeEjPjPP5_NODE@plt>:
   13250:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13254:      	ldr	x17, [x16, #0xbf0]
   13258:      	add	x16, x16, #0xbf0
   1325c:      	br	x17

0000000000013260 <_ZN10CQuantizer16GetPaletteColorsEP5_NODEPhPj@plt>:
   13260:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13264:      	ldr	x17, [x16, #0xbf8]
   13268:      	add	x16, x16, #0xbf8
   1326c:      	br	x17

0000000000013270 <strcpy@plt>:
   13270:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13274:      	ldr	x17, [x16, #0xc00]
   13278:      	add	x16, x16, #0xc00
   1327c:      	br	x17

0000000000013280 <_ZN7CGif89a4openEPcb@plt>:
   13280:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13284:      	ldr	x17, [x16, #0xc08]
   13288:      	add	x16, x16, #0xc08
   1328c:      	br	x17

0000000000013290 <_ZN7CGif89a11checkFramesEv@plt>:
   13290:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13294:      	ldr	x17, [x16, #0xc10]
   13298:      	add	x16, x16, #0xc10
   1329c:      	br	x17

00000000000132a0 <_ZN7CGif89a12getAllFramesEv@plt>:
   132a0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   132a4:      	ldr	x17, [x16, #0xc18]
   132a8:      	add	x16, x16, #0xc18
   132ac:      	br	x17

00000000000132b0 <_ZN7CGif89a5closeEv@plt>:
   132b0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   132b4:      	ldr	x17, [x16, #0xc20]
   132b8:      	add	x16, x16, #0xc20
   132bc:      	br	x17

00000000000132c0 <_ZN7CGif89a11extractDataEP5FRAME@plt>:
   132c0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   132c4:      	ldr	x17, [x16, #0xc28]
   132c8:      	add	x16, x16, #0xc28
   132cc:      	br	x17

00000000000132d0 <_ZN7CGif89a12getNextFrameEv@plt>:
   132d0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   132d4:      	ldr	x17, [x16, #0xc30]
   132d8:      	add	x16, x16, #0xc30
   132dc:      	br	x17

00000000000132e0 <_ZN5mtgif9Video2GifC1Ev@plt>:
   132e0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   132e4:      	ldr	x17, [x16, #0xc38]
   132e8:      	add	x16, x16, #0xc38
   132ec:      	br	x17

00000000000132f0 <memmove@plt>:
   132f0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   132f4:      	ldr	x17, [x16, #0xc40]
   132f8:      	add	x16, x16, #0xc40
   132fc:      	br	x17

0000000000013300 <_ZN5mtgif9Video2Gif4initENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES7_iiif@plt>:
   13300:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13304:      	ldr	x17, [x16, #0xc48]
   13308:      	add	x16, x16, #0xc48
   1330c:      	br	x17

0000000000013310 <_ZN5mtgif9Video2Gif3runEv@plt>:
   13310:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13314:      	ldr	x17, [x16, #0xc50]
   13318:      	add	x16, x16, #0xc50
   1331c:      	br	x17

0000000000013320 <__android_log_print@plt>:
   13320:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13324:      	ldr	x17, [x16, #0xc58]
   13328:      	add	x16, x16, #0xc58
   1332c:      	br	x17

0000000000013330 <_ZN5mtgif9Video2GifD1Ev@plt>:
   13330:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13334:      	ldr	x17, [x16, #0xc60]
   13338:      	add	x16, x16, #0xc60
   1333c:      	br	x17

0000000000013340 <__cxa_allocate_exception@plt>:
   13340:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13344:      	ldr	x17, [x16, #0xc68]
   13348:      	add	x16, x16, #0xc68
   1334c:      	br	x17

0000000000013350 <__cxa_throw@plt>:
   13350:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13354:      	ldr	x17, [x16, #0xc70]
   13358:      	add	x16, x16, #0xc70
   1335c:      	br	x17

0000000000013360 <__cxa_free_exception@plt>:
   13360:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13364:      	ldr	x17, [x16, #0xc78]
   13368:      	add	x16, x16, #0xc78
   1336c:      	br	x17

0000000000013370 <_ZNSt11logic_errorC2EPKc@plt>:
   13370:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13374:      	ldr	x17, [x16, #0xc80]
   13378:      	add	x16, x16, #0xc80
   1337c:      	br	x17

0000000000013380 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   13380:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13384:      	ldr	x17, [x16, #0xc88]
   13388:      	add	x16, x16, #0xc88
   1338c:      	br	x17

0000000000013390 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   13390:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13394:      	ldr	x17, [x16, #0xc90]
   13398:      	add	x16, x16, #0xc90
   1339c:      	br	x17

00000000000133a0 <dl_iterate_phdr@plt>:
   133a0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   133a4:      	ldr	x17, [x16, #0xc98]
   133a8:      	add	x16, x16, #0xc98
   133ac:      	br	x17

00000000000133b0 <fprintf@plt>:
   133b0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   133b4:      	ldr	x17, [x16, #0xca0]
   133b8:      	add	x16, x16, #0xca0
   133bc:      	br	x17

00000000000133c0 <abort@plt>:
   133c0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   133c4:      	ldr	x17, [x16, #0xca8]
   133c8:      	add	x16, x16, #0xca8
   133cc:      	br	x17

00000000000133d0 <pthread_rwlock_wrlock@plt>:
   133d0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   133d4:      	ldr	x17, [x16, #0xcb0]
   133d8:      	add	x16, x16, #0xcb0
   133dc:      	br	x17

00000000000133e0 <pthread_rwlock_unlock@plt>:
   133e0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   133e4:      	ldr	x17, [x16, #0xcb8]
   133e8:      	add	x16, x16, #0xcb8
   133ec:      	br	x17

00000000000133f0 <pthread_rwlock_rdlock@plt>:
   133f0:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   133f4:      	ldr	x17, [x16, #0xcc0]
   133f8:      	add	x16, x16, #0xcc0
   133fc:      	br	x17

0000000000013400 <getpid@plt>:
   13400:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13404:      	ldr	x17, [x16, #0xcc8]
   13408:      	add	x16, x16, #0xcc8
   1340c:      	br	x17

0000000000013410 <syscall@plt>:
   13410:      	adrp	x16, 0x17000 <syscall@plt+0x3bf0>
   13414:      	ldr	x17, [x16, #0xcd0]
   13418:      	add	x16, x16, #0xcd0
   1341c:      	br	x17
