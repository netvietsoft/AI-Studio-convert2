// EXPORTED & PLT DISASSEMBLY FOR libMTARMPM.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTARMPM.so (SHA-256: A8CC628D8542EF953BCBEA36252DF569FF03EFCEA40C3E99A01A5D01489965B4)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 44, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTARMPM.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000016ae0 <.plt>:
   16ae0:      	stp	x16, x30, [sp, #-0x10]!
   16ae4:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ae8:      	ldr	x17, [x16, #0x9b0]
   16aec:      	add	x16, x16, #0x9b0
   16af0:      	br	x17
   16af4:      	nop
   16af8:      	nop
   16afc:      	nop

0000000000016b00 <__cxa_finalize@plt>:
   16b00:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b04:      	ldr	x17, [x16, #0x9b8]
   16b08:      	add	x16, x16, #0x9b8
   16b0c:      	br	x17

0000000000016b10 <__cxa_atexit@plt>:
   16b10:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b14:      	ldr	x17, [x16, #0x9c0]
   16b18:      	add	x16, x16, #0x9c0
   16b1c:      	br	x17

0000000000016b20 <__register_atfork@plt>:
   16b20:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b24:      	ldr	x17, [x16, #0x9c8]
   16b28:      	add	x16, x16, #0x9c8
   16b2c:      	br	x17

0000000000016b30 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   16b30:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b34:      	ldr	x17, [x16, #0x9d0]
   16b38:      	add	x16, x16, #0x9d0
   16b3c:      	br	x17

0000000000016b40 <__stack_chk_fail@plt>:
   16b40:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b44:      	ldr	x17, [x16, #0x9d8]
   16b48:      	add	x16, x16, #0x9d8
   16b4c:      	br	x17

0000000000016b50 <_Znwm@plt>:
   16b50:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b54:      	ldr	x17, [x16, #0x9e0]
   16b58:      	add	x16, x16, #0x9e0
   16b5c:      	br	x17

0000000000016b60 <_ZdlPv@plt>:
   16b60:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b64:      	ldr	x17, [x16, #0x9e8]
   16b68:      	add	x16, x16, #0x9e8
   16b6c:      	br	x17

0000000000016b70 <strlen@plt>:
   16b70:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b74:      	ldr	x17, [x16, #0x9f0]
   16b78:      	add	x16, x16, #0x9f0
   16b7c:      	br	x17

0000000000016b80 <memmove@plt>:
   16b80:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b84:      	ldr	x17, [x16, #0x9f8]
   16b88:      	add	x16, x16, #0x9f8
   16b8c:      	br	x17

0000000000016b90 <__cxa_begin_catch@plt>:
   16b90:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16b94:      	ldr	x17, [x16, #0xa00]
   16b98:      	add	x16, x16, #0xa00
   16b9c:      	br	x17

0000000000016ba0 <_ZSt9terminatev@plt>:
   16ba0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ba4:      	ldr	x17, [x16, #0xa08]
   16ba8:      	add	x16, x16, #0xa08
   16bac:      	br	x17

0000000000016bb0 <__cxa_allocate_exception@plt>:
   16bb0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16bb4:      	ldr	x17, [x16, #0xa10]
   16bb8:      	add	x16, x16, #0xa10
   16bbc:      	br	x17

0000000000016bc0 <__cxa_throw@plt>:
   16bc0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16bc4:      	ldr	x17, [x16, #0xa18]
   16bc8:      	add	x16, x16, #0xa18
   16bcc:      	br	x17

0000000000016bd0 <__cxa_free_exception@plt>:
   16bd0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16bd4:      	ldr	x17, [x16, #0xa20]
   16bd8:      	add	x16, x16, #0xa20
   16bdc:      	br	x17

0000000000016be0 <_ZNSt11logic_errorC2EPKc@plt>:
   16be0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16be4:      	ldr	x17, [x16, #0xa28]
   16be8:      	add	x16, x16, #0xa28
   16bec:      	br	x17

0000000000016bf0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
   16bf0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16bf4:      	ldr	x17, [x16, #0xa30]
   16bf8:      	add	x16, x16, #0xa30
   16bfc:      	br	x17

0000000000016c00 <_ZNSt6__ndk15mutexD1Ev@plt>:
   16c00:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c04:      	ldr	x17, [x16, #0xa38]
   16c08:      	add	x16, x16, #0xa38
   16c0c:      	br	x17

0000000000016c10 <_ZNSt6__ndk15mutex4lockEv@plt>:
   16c10:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c14:      	ldr	x17, [x16, #0xa40]
   16c18:      	add	x16, x16, #0xa40
   16c1c:      	br	x17

0000000000016c20 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
   16c20:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c24:      	ldr	x17, [x16, #0xa48]
   16c28:      	add	x16, x16, #0xa48
   16c2c:      	br	x17

0000000000016c30 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   16c30:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c34:      	ldr	x17, [x16, #0xa50]
   16c38:      	add	x16, x16, #0xa50
   16c3c:      	br	x17

0000000000016c40 <_ZNSt6__ndk16thread4joinEv@plt>:
   16c40:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c44:      	ldr	x17, [x16, #0xa58]
   16c48:      	add	x16, x16, #0xa58
   16c4c:      	br	x17

0000000000016c50 <swr_free@plt>:
   16c50:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c54:      	ldr	x17, [x16, #0xa60]
   16c58:      	add	x16, x16, #0xa60
   16c5c:      	br	x17

0000000000016c60 <avcodec_close@plt>:
   16c60:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c64:      	ldr	x17, [x16, #0xa68]
   16c68:      	add	x16, x16, #0xa68
   16c6c:      	br	x17

0000000000016c70 <avformat_close_input@plt>:
   16c70:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c74:      	ldr	x17, [x16, #0xa70]
   16c78:      	add	x16, x16, #0xa70
   16c7c:      	br	x17

0000000000016c80 <av_freep@plt>:
   16c80:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c84:      	ldr	x17, [x16, #0xa78]
   16c88:      	add	x16, x16, #0xa78
   16c8c:      	br	x17

0000000000016c90 <avformat_alloc_context@plt>:
   16c90:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16c94:      	ldr	x17, [x16, #0xa80]
   16c98:      	add	x16, x16, #0xa80
   16c9c:      	br	x17

0000000000016ca0 <avformat_open_input@plt>:
   16ca0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ca4:      	ldr	x17, [x16, #0xa88]
   16ca8:      	add	x16, x16, #0xa88
   16cac:      	br	x17

0000000000016cb0 <av_format_inject_global_side_data@plt>:
   16cb0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16cb4:      	ldr	x17, [x16, #0xa90]
   16cb8:      	add	x16, x16, #0xa90
   16cbc:      	br	x17

0000000000016cc0 <avformat_find_stream_info@plt>:
   16cc0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16cc4:      	ldr	x17, [x16, #0xa98]
   16cc8:      	add	x16, x16, #0xa98
   16ccc:      	br	x17

0000000000016cd0 <av_log@plt>:
   16cd0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16cd4:      	ldr	x17, [x16, #0xaa0]
   16cd8:      	add	x16, x16, #0xaa0
   16cdc:      	br	x17

0000000000016ce0 <av_strerror@plt>:
   16ce0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ce4:      	ldr	x17, [x16, #0xaa8]
   16ce8:      	add	x16, x16, #0xaa8
   16cec:      	br	x17

0000000000016cf0 <strerror@plt>:
   16cf0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16cf4:      	ldr	x17, [x16, #0xab0]
   16cf8:      	add	x16, x16, #0xab0
   16cfc:      	br	x17

0000000000016d00 <strcmp@plt>:
   16d00:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d04:      	ldr	x17, [x16, #0xab8]
   16d08:      	add	x16, x16, #0xab8
   16d0c:      	br	x17

0000000000016d10 <avformat_seek_file@plt>:
   16d10:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d14:      	ldr	x17, [x16, #0xac0]
   16d18:      	add	x16, x16, #0xac0
   16d1c:      	br	x17

0000000000016d20 <av_dump_format@plt>:
   16d20:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d24:      	ldr	x17, [x16, #0xac8]
   16d28:      	add	x16, x16, #0xac8
   16d2c:      	br	x17

0000000000016d30 <av_find_best_stream@plt>:
   16d30:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d34:      	ldr	x17, [x16, #0xad0]
   16d38:      	add	x16, x16, #0xad0
   16d3c:      	br	x17

0000000000016d40 <avcodec_alloc_context3@plt>:
   16d40:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d44:      	ldr	x17, [x16, #0xad8]
   16d48:      	add	x16, x16, #0xad8
   16d4c:      	br	x17

0000000000016d50 <avcodec_parameters_to_context@plt>:
   16d50:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d54:      	ldr	x17, [x16, #0xae0]
   16d58:      	add	x16, x16, #0xae0
   16d5c:      	br	x17

0000000000016d60 <avcodec_find_decoder@plt>:
   16d60:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d64:      	ldr	x17, [x16, #0xae8]
   16d68:      	add	x16, x16, #0xae8
   16d6c:      	br	x17

0000000000016d70 <av_opt_set_int@plt>:
   16d70:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d74:      	ldr	x17, [x16, #0xaf0]
   16d78:      	add	x16, x16, #0xaf0
   16d7c:      	br	x17

0000000000016d80 <av_dict_get@plt>:
   16d80:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d84:      	ldr	x17, [x16, #0xaf8]
   16d88:      	add	x16, x16, #0xaf8
   16d8c:      	br	x17

0000000000016d90 <av_dict_set@plt>:
   16d90:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16d94:      	ldr	x17, [x16, #0xb00]
   16d98:      	add	x16, x16, #0xb00
   16d9c:      	br	x17

0000000000016da0 <avcodec_open2@plt>:
   16da0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16da4:      	ldr	x17, [x16, #0xb08]
   16da8:      	add	x16, x16, #0xb08
   16dac:      	br	x17

0000000000016db0 <av_channel_layout_default@plt>:
   16db0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16db4:      	ldr	x17, [x16, #0xb10]
   16db8:      	add	x16, x16, #0xb10
   16dbc:      	br	x17

0000000000016dc0 <av_rescale_q@plt>:
   16dc0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16dc4:      	ldr	x17, [x16, #0xb18]
   16dc8:      	add	x16, x16, #0xb18
   16dcc:      	br	x17

0000000000016dd0 <av_samples_get_buffer_size@plt>:
   16dd0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16dd4:      	ldr	x17, [x16, #0xb20]
   16dd8:      	add	x16, x16, #0xb20
   16ddc:      	br	x17

0000000000016de0 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
   16de0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16de4:      	ldr	x17, [x16, #0xb28]
   16de8:      	add	x16, x16, #0xb28
   16dec:      	br	x17

0000000000016df0 <pthread_create@plt>:
   16df0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16df4:      	ldr	x17, [x16, #0xb30]
   16df8:      	add	x16, x16, #0xb30
   16dfc:      	br	x17

0000000000016e00 <avcodec_free_context@plt>:
   16e00:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e04:      	ldr	x17, [x16, #0xb38]
   16e08:      	add	x16, x16, #0xb38
   16e0c:      	br	x17

0000000000016e10 <av_dict_free@plt>:
   16e10:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e14:      	ldr	x17, [x16, #0xb40]
   16e18:      	add	x16, x16, #0xb40
   16e1c:      	br	x17

0000000000016e20 <fwrite@plt>:
   16e20:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e24:      	ldr	x17, [x16, #0xb48]
   16e28:      	add	x16, x16, #0xb48
   16e2c:      	br	x17

0000000000016e30 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
   16e30:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e34:      	ldr	x17, [x16, #0xb50]
   16e38:      	add	x16, x16, #0xb50
   16e3c:      	br	x17

0000000000016e40 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
   16e40:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e44:      	ldr	x17, [x16, #0xb58]
   16e48:      	add	x16, x16, #0xb58
   16e4c:      	br	x17

0000000000016e50 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   16e50:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e54:      	ldr	x17, [x16, #0xb60]
   16e58:      	add	x16, x16, #0xb60
   16e5c:      	br	x17

0000000000016e60 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
   16e60:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e64:      	ldr	x17, [x16, #0xb68]
   16e68:      	add	x16, x16, #0xb68
   16e6c:      	br	x17

0000000000016e70 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
   16e70:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e74:      	ldr	x17, [x16, #0xb70]
   16e78:      	add	x16, x16, #0xb70
   16e7c:      	br	x17

0000000000016e80 <memset@plt>:
   16e80:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e84:      	ldr	x17, [x16, #0xb78]
   16e88:      	add	x16, x16, #0xb78
   16e8c:      	br	x17

0000000000016e90 <__android_log_print@plt>:
   16e90:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16e94:      	ldr	x17, [x16, #0xb80]
   16e98:      	add	x16, x16, #0xb80
   16e9c:      	br	x17

0000000000016ea0 <av_channel_layout_from_mask@plt>:
   16ea0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ea4:      	ldr	x17, [x16, #0xb88]
   16ea8:      	add	x16, x16, #0xb88
   16eac:      	br	x17

0000000000016eb0 <swr_alloc_set_opts2@plt>:
   16eb0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16eb4:      	ldr	x17, [x16, #0xb90]
   16eb8:      	add	x16, x16, #0xb90
   16ebc:      	br	x17

0000000000016ec0 <swr_init@plt>:
   16ec0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ec4:      	ldr	x17, [x16, #0xb98]
   16ec8:      	add	x16, x16, #0xb98
   16ecc:      	br	x17

0000000000016ed0 <av_get_sample_fmt_name@plt>:
   16ed0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ed4:      	ldr	x17, [x16, #0xba0]
   16ed8:      	add	x16, x16, #0xba0
   16edc:      	br	x17

0000000000016ee0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEl@plt>:
   16ee0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ee4:      	ldr	x17, [x16, #0xba8]
   16ee8:      	add	x16, x16, #0xba8
   16eec:      	br	x17

0000000000016ef0 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   16ef0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ef4:      	ldr	x17, [x16, #0xbb0]
   16ef8:      	add	x16, x16, #0xbb0
   16efc:      	br	x17

0000000000016f00 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   16f00:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f04:      	ldr	x17, [x16, #0xbb8]
   16f08:      	add	x16, x16, #0xbb8
   16f0c:      	br	x17

0000000000016f10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   16f10:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f14:      	ldr	x17, [x16, #0xbc0]
   16f18:      	add	x16, x16, #0xbc0
   16f1c:      	br	x17

0000000000016f20 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   16f20:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f24:      	ldr	x17, [x16, #0xbc8]
   16f28:      	add	x16, x16, #0xbc8
   16f2c:      	br	x17

0000000000016f30 <av_fast_malloc@plt>:
   16f30:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f34:      	ldr	x17, [x16, #0xbd0]
   16f38:      	add	x16, x16, #0xbd0
   16f3c:      	br	x17

0000000000016f40 <swr_convert@plt>:
   16f40:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f44:      	ldr	x17, [x16, #0xbd8]
   16f48:      	add	x16, x16, #0xbd8
   16f4c:      	br	x17

0000000000016f50 <av_read_frame@plt>:
   16f50:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f54:      	ldr	x17, [x16, #0xbe0]
   16f58:      	add	x16, x16, #0xbe0
   16f5c:      	br	x17

0000000000016f60 <av_init_packet@plt>:
   16f60:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f64:      	ldr	x17, [x16, #0xbe8]
   16f68:      	add	x16, x16, #0xbe8
   16f6c:      	br	x17

0000000000016f70 <av_frame_alloc@plt>:
   16f70:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f74:      	ldr	x17, [x16, #0xbf0]
   16f78:      	add	x16, x16, #0xbf0
   16f7c:      	br	x17

0000000000016f80 <av_seek_frame@plt>:
   16f80:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f84:      	ldr	x17, [x16, #0xbf8]
   16f88:      	add	x16, x16, #0xbf8
   16f8c:      	br	x17

0000000000016f90 <avcodec_flush_buffers@plt>:
   16f90:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16f94:      	ldr	x17, [x16, #0xc00]
   16f98:      	add	x16, x16, #0xc00
   16f9c:      	br	x17

0000000000016fa0 <avcodec_send_packet@plt>:
   16fa0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16fa4:      	ldr	x17, [x16, #0xc08]
   16fa8:      	add	x16, x16, #0xc08
   16fac:      	br	x17

0000000000016fb0 <avcodec_receive_frame@plt>:
   16fb0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16fb4:      	ldr	x17, [x16, #0xc10]
   16fb8:      	add	x16, x16, #0xc10
   16fbc:      	br	x17

0000000000016fc0 <printf@plt>:
   16fc0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16fc4:      	ldr	x17, [x16, #0xc18]
   16fc8:      	add	x16, x16, #0xc18
   16fcc:      	br	x17

0000000000016fd0 <swr_set_compensation@plt>:
   16fd0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16fd4:      	ldr	x17, [x16, #0xc20]
   16fd8:      	add	x16, x16, #0xc20
   16fdc:      	br	x17

0000000000016fe0 <av_get_bytes_per_sample@plt>:
   16fe0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16fe4:      	ldr	x17, [x16, #0xc28]
   16fe8:      	add	x16, x16, #0xc28
   16fec:      	br	x17

0000000000016ff0 <av_frame_unref@plt>:
   16ff0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   16ff4:      	ldr	x17, [x16, #0xc30]
   16ff8:      	add	x16, x16, #0xc30
   16ffc:      	br	x17

0000000000017000 <av_packet_unref@plt>:
   17000:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17004:      	ldr	x17, [x16, #0xc38]
   17008:      	add	x16, x16, #0xc38
   1700c:      	br	x17

0000000000017010 <av_frame_free@plt>:
   17010:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17014:      	ldr	x17, [x16, #0xc40]
   17018:      	add	x16, x16, #0xc40
   1701c:      	br	x17

0000000000017020 <_ZNSt9exceptionD2Ev@plt>:
   17020:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17024:      	ldr	x17, [x16, #0xc48]
   17028:      	add	x16, x16, #0xc48
   1702c:      	br	x17

0000000000017030 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   17030:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17034:      	ldr	x17, [x16, #0xc50]
   17038:      	add	x16, x16, #0xc50
   1703c:      	br	x17

0000000000017040 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   17040:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17044:      	ldr	x17, [x16, #0xc58]
   17048:      	add	x16, x16, #0xc58
   1704c:      	br	x17

0000000000017050 <_ZNSt6__ndk16threadD1Ev@plt>:
   17050:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17054:      	ldr	x17, [x16, #0xc60]
   17058:      	add	x16, x16, #0xc60
   1705c:      	br	x17

0000000000017060 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
   17060:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17064:      	ldr	x17, [x16, #0xc68]
   17068:      	add	x16, x16, #0xc68
   1706c:      	br	x17

0000000000017070 <pthread_setspecific@plt>:
   17070:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17074:      	ldr	x17, [x16, #0xc70]
   17078:      	add	x16, x16, #0xc70
   1707c:      	br	x17

0000000000017080 <memcmp@plt>:
   17080:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17084:      	ldr	x17, [x16, #0xc78]
   17088:      	add	x16, x16, #0xc78
   1708c:      	br	x17

0000000000017090 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   17090:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17094:      	ldr	x17, [x16, #0xc80]
   17098:      	add	x16, x16, #0xc80
   1709c:      	br	x17

00000000000170a0 <log@plt>:
   170a0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   170a4:      	ldr	x17, [x16, #0xc88]
   170a8:      	add	x16, x16, #0xc88
   170ac:      	br	x17

00000000000170b0 <_Znam@plt>:
   170b0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   170b4:      	ldr	x17, [x16, #0xc90]
   170b8:      	add	x16, x16, #0xc90
   170bc:      	br	x17

00000000000170c0 <_ZdaPv@plt>:
   170c0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   170c4:      	ldr	x17, [x16, #0xc98]
   170c8:      	add	x16, x16, #0xc98
   170cc:      	br	x17

00000000000170d0 <__cxa_rethrow@plt>:
   170d0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   170d4:      	ldr	x17, [x16, #0xca0]
   170d8:      	add	x16, x16, #0xca0
   170dc:      	br	x17

00000000000170e0 <__cxa_end_catch@plt>:
   170e0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   170e4:      	ldr	x17, [x16, #0xca8]
   170e8:      	add	x16, x16, #0xca8
   170ec:      	br	x17

00000000000170f0 <calloc@plt>:
   170f0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   170f4:      	ldr	x17, [x16, #0xcb0]
   170f8:      	add	x16, x16, #0xcb0
   170fc:      	br	x17

0000000000017100 <free@plt>:
   17100:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17104:      	ldr	x17, [x16, #0xcb8]
   17108:      	add	x16, x16, #0xcb8
   1710c:      	br	x17

0000000000017110 <malloc@plt>:
   17110:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17114:      	ldr	x17, [x16, #0xcc0]
   17118:      	add	x16, x16, #0xcc0
   1711c:      	br	x17

0000000000017120 <pthread_getspecific@plt>:
   17120:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17124:      	ldr	x17, [x16, #0xcc8]
   17128:      	add	x16, x16, #0xcc8
   1712c:      	br	x17

0000000000017130 <pthread_self@plt>:
   17130:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17134:      	ldr	x17, [x16, #0xcd0]
   17138:      	add	x16, x16, #0xcd0
   1713c:      	br	x17

0000000000017140 <pthread_key_create@plt>:
   17140:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17144:      	ldr	x17, [x16, #0xcd8]
   17148:      	add	x16, x16, #0xcd8
   1714c:      	br	x17

0000000000017150 <pthread_mutex_init@plt>:
   17150:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17154:      	ldr	x17, [x16, #0xce0]
   17158:      	add	x16, x16, #0xce0
   1715c:      	br	x17

0000000000017160 <pthread_mutex_destroy@plt>:
   17160:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17164:      	ldr	x17, [x16, #0xce8]
   17168:      	add	x16, x16, #0xce8
   1716c:      	br	x17

0000000000017170 <pthread_mutex_lock@plt>:
   17170:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17174:      	ldr	x17, [x16, #0xcf0]
   17178:      	add	x16, x16, #0xcf0
   1717c:      	br	x17

0000000000017180 <pthread_mutex_unlock@plt>:
   17180:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17184:      	ldr	x17, [x16, #0xcf8]
   17188:      	add	x16, x16, #0xcf8
   1718c:      	br	x17

0000000000017190 <pthread_cond_init@plt>:
   17190:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17194:      	ldr	x17, [x16, #0xd00]
   17198:      	add	x16, x16, #0xd00
   1719c:      	br	x17

00000000000171a0 <pthread_cond_destroy@plt>:
   171a0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   171a4:      	ldr	x17, [x16, #0xd08]
   171a8:      	add	x16, x16, #0xd08
   171ac:      	br	x17

00000000000171b0 <pthread_cond_signal@plt>:
   171b0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   171b4:      	ldr	x17, [x16, #0xd10]
   171b8:      	add	x16, x16, #0xd10
   171bc:      	br	x17

00000000000171c0 <gettimeofday@plt>:
   171c0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   171c4:      	ldr	x17, [x16, #0xd18]
   171c8:      	add	x16, x16, #0xd18
   171cc:      	br	x17

00000000000171d0 <pthread_cond_timedwait@plt>:
   171d0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   171d4:      	ldr	x17, [x16, #0xd20]
   171d8:      	add	x16, x16, #0xd20
   171dc:      	br	x17

00000000000171e0 <__strlcpy_chk@plt>:
   171e0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   171e4:      	ldr	x17, [x16, #0xd28]
   171e8:      	add	x16, x16, #0xd28
   171ec:      	br	x17

00000000000171f0 <pthread_getschedparam@plt>:
   171f0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   171f4:      	ldr	x17, [x16, #0xd30]
   171f8:      	add	x16, x16, #0xd30
   171fc:      	br	x17

0000000000017200 <sched_get_priority_min@plt>:
   17200:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17204:      	ldr	x17, [x16, #0xd38]
   17208:      	add	x16, x16, #0xd38
   1720c:      	br	x17

0000000000017210 <sched_get_priority_max@plt>:
   17210:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17214:      	ldr	x17, [x16, #0xd40]
   17218:      	add	x16, x16, #0xd40
   1721c:      	br	x17

0000000000017220 <pthread_setschedparam@plt>:
   17220:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17224:      	ldr	x17, [x16, #0xd48]
   17228:      	add	x16, x16, #0xd48
   1722c:      	br	x17

0000000000017230 <pthread_join@plt>:
   17230:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17234:      	ldr	x17, [x16, #0xd50]
   17238:      	add	x16, x16, #0xd50
   1723c:      	br	x17

0000000000017240 <memcpy@plt>:
   17240:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17244:      	ldr	x17, [x16, #0xd58]
   17248:      	add	x16, x16, #0xd58
   1724c:      	br	x17

0000000000017250 <getauxval@plt>:
   17250:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17254:      	ldr	x17, [x16, #0xd60]
   17258:      	add	x16, x16, #0xd60
   1725c:      	br	x17

0000000000017260 <__system_property_get@plt>:
   17260:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17264:      	ldr	x17, [x16, #0xd68]
   17268:      	add	x16, x16, #0xd68
   1726c:      	br	x17

0000000000017270 <strncmp@plt>:
   17270:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17274:      	ldr	x17, [x16, #0xd70]
   17278:      	add	x16, x16, #0xd70
   1727c:      	br	x17

0000000000017280 <fprintf@plt>:
   17280:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17284:      	ldr	x17, [x16, #0xd78]
   17288:      	add	x16, x16, #0xd78
   1728c:      	br	x17

0000000000017290 <fflush@plt>:
   17290:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17294:      	ldr	x17, [x16, #0xd80]
   17298:      	add	x16, x16, #0xd80
   1729c:      	br	x17

00000000000172a0 <abort@plt>:
   172a0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   172a4:      	ldr	x17, [x16, #0xd88]
   172a8:      	add	x16, x16, #0xd88
   172ac:      	br	x17

00000000000172b0 <pthread_rwlock_wrlock@plt>:
   172b0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   172b4:      	ldr	x17, [x16, #0xd90]
   172b8:      	add	x16, x16, #0xd90
   172bc:      	br	x17

00000000000172c0 <pthread_rwlock_unlock@plt>:
   172c0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   172c4:      	ldr	x17, [x16, #0xd98]
   172c8:      	add	x16, x16, #0xd98
   172cc:      	br	x17

00000000000172d0 <dl_iterate_phdr@plt>:
   172d0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   172d4:      	ldr	x17, [x16, #0xda0]
   172d8:      	add	x16, x16, #0xda0
   172dc:      	br	x17

00000000000172e0 <pthread_rwlock_rdlock@plt>:
   172e0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   172e4:      	ldr	x17, [x16, #0xda8]
   172e8:      	add	x16, x16, #0xda8
   172ec:      	br	x17

00000000000172f0 <getpid@plt>:
   172f0:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   172f4:      	ldr	x17, [x16, #0xdb0]
   172f8:      	add	x16, x16, #0xdb0
   172fc:      	br	x17

0000000000017300 <syscall@plt>:
   17300:      	adrp	x16, 0x1b000 <syscall@plt+0x3d00>
   17304:      	ldr	x17, [x16, #0xdb8]
   17308:      	add	x16, x16, #0xdb8
   1730c:      	br	x17
