// EXPORTED & PLT DISASSEMBLY FOR libffmpegfilter.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libffmpegfilter.so (SHA-256: F22A7EA6DA3194D046ECBCE5CE3B602BCB56EDFD96444A6E29E1A3C3449CF981)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 248, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libffmpegfilter.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000003ccc0 <.plt>:
   3ccc0:      	stp	x16, x30, [sp, #-0x10]!
   3ccc4:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ccc8:      	ldr	x17, [x16, #0x3a8]
   3cccc:      	add	x16, x16, #0x3a8
   3ccd0:      	br	x17
   3ccd4:      	nop
   3ccd8:      	nop
   3ccdc:      	nop

000000000003cce0 <__cxa_finalize@plt>:
   3cce0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cce4:      	ldr	x17, [x16, #0x3b0]
   3cce8:      	add	x16, x16, #0x3b0
   3ccec:      	br	x17

000000000003ccf0 <__cxa_atexit@plt>:
   3ccf0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ccf4:      	ldr	x17, [x16, #0x3b8]
   3ccf8:      	add	x16, x16, #0x3b8
   3ccfc:      	br	x17

000000000003cd00 <cos@plt>:
   3cd00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd04:      	ldr	x17, [x16, #0x3c0]
   3cd08:      	add	x16, x16, #0x3c0
   3cd0c:      	br	x17

000000000003cd10 <av_realloc_array@plt>:
   3cd10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd14:      	ldr	x17, [x16, #0x3c8]
   3cd18:      	add	x16, x16, #0x3c8
   3cd1c:      	br	x17

000000000003cd20 <ff_set_common_formats_from_list2@plt>:
   3cd20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd24:      	ldr	x17, [x16, #0x3d0]
   3cd28:      	add	x16, x16, #0x3d0
   3cd2c:      	br	x17

000000000003cd30 <ff_set_common_samplerates_from_list2@plt>:
   3cd30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd34:      	ldr	x17, [x16, #0x3d8]
   3cd38:      	add	x16, x16, #0x3d8
   3cd3c:      	br	x17

000000000003cd40 <ff_set_common_channel_layouts_from_list2@plt>:
   3cd40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd44:      	ldr	x17, [x16, #0x3e0]
   3cd48:      	add	x16, x16, #0x3e0
   3cd4c:      	br	x17

000000000003cd50 <swr_alloc@plt>:
   3cd50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd54:      	ldr	x17, [x16, #0x3e8]
   3cd58:      	add	x16, x16, #0x3e8
   3cd5c:      	br	x17

000000000003cd60 <swr_free@plt>:
   3cd60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd64:      	ldr	x17, [x16, #0x3f0]
   3cd68:      	add	x16, x16, #0x3f0
   3cd6c:      	br	x17

000000000003cd70 <av_opt_set_int@plt>:
   3cd70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd74:      	ldr	x17, [x16, #0x3f8]
   3cd78:      	add	x16, x16, #0x3f8
   3cd7c:      	br	x17

000000000003cd80 <av_opt_get_sample_fmt@plt>:
   3cd80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd84:      	ldr	x17, [x16, #0x400]
   3cd88:      	add	x16, x16, #0x400
   3cd8c:      	br	x17

000000000003cd90 <av_opt_get_int@plt>:
   3cd90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cd94:      	ldr	x17, [x16, #0x408]
   3cd98:      	add	x16, x16, #0x408
   3cd9c:      	br	x17

000000000003cda0 <ff_all_formats@plt>:
   3cda0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cda4:      	ldr	x17, [x16, #0x410]
   3cda8:      	add	x16, x16, #0x410
   3cdac:      	br	x17

000000000003cdb0 <ff_formats_ref@plt>:
   3cdb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cdb4:      	ldr	x17, [x16, #0x418]
   3cdb8:      	add	x16, x16, #0x418
   3cdbc:      	br	x17

000000000003cdc0 <ff_all_samplerates@plt>:
   3cdc0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cdc4:      	ldr	x17, [x16, #0x420]
   3cdc8:      	add	x16, x16, #0x420
   3cdcc:      	br	x17

000000000003cdd0 <ff_all_channel_counts@plt>:
   3cdd0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cdd4:      	ldr	x17, [x16, #0x428]
   3cdd8:      	add	x16, x16, #0x428
   3cddc:      	br	x17

000000000003cde0 <ff_channel_layouts_ref@plt>:
   3cde0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cde4:      	ldr	x17, [x16, #0x430]
   3cde8:      	add	x16, x16, #0x430
   3cdec:      	br	x17

000000000003cdf0 <av_opt_get_chlayout@plt>:
   3cdf0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cdf4:      	ldr	x17, [x16, #0x438]
   3cdf8:      	add	x16, x16, #0x438
   3cdfc:      	br	x17

000000000003ce00 <av_channel_layout_check@plt>:
   3ce00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce04:      	ldr	x17, [x16, #0x440]
   3ce08:      	add	x16, x16, #0x440
   3ce0c:      	br	x17

000000000003ce10 <ff_make_channel_layout_list@plt>:
   3ce10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce14:      	ldr	x17, [x16, #0x448]
   3ce18:      	add	x16, x16, #0x448
   3ce1c:      	br	x17

000000000003ce20 <av_channel_layout_uninit@plt>:
   3ce20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce24:      	ldr	x17, [x16, #0x450]
   3ce28:      	add	x16, x16, #0x450
   3ce2c:      	br	x17

000000000003ce30 <ff_outlink_get_status@plt>:
   3ce30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce34:      	ldr	x17, [x16, #0x458]
   3ce38:      	add	x16, x16, #0x458
   3ce3c:      	br	x17

000000000003ce40 <ff_inlink_set_status@plt>:
   3ce40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce44:      	ldr	x17, [x16, #0x460]
   3ce48:      	add	x16, x16, #0x460
   3ce4c:      	br	x17

000000000003ce50 <ff_inlink_acknowledge_status@plt>:
   3ce50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce54:      	ldr	x17, [x16, #0x468]
   3ce58:      	add	x16, x16, #0x468
   3ce5c:      	br	x17

000000000003ce60 <ff_inlink_queued_frames@plt>:
   3ce60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce64:      	ldr	x17, [x16, #0x470]
   3ce68:      	add	x16, x16, #0x470
   3ce6c:      	br	x17

000000000003ce70 <ff_inlink_consume_frame@plt>:
   3ce70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce74:      	ldr	x17, [x16, #0x478]
   3ce78:      	add	x16, x16, #0x478
   3ce7c:      	br	x17

000000000003ce80 <swr_get_delay@plt>:
   3ce80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce84:      	ldr	x17, [x16, #0x480]
   3ce88:      	add	x16, x16, #0x480
   3ce8c:      	br	x17

000000000003ce90 <ff_get_audio_buffer@plt>:
   3ce90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ce94:      	ldr	x17, [x16, #0x488]
   3ce98:      	add	x16, x16, #0x488
   3ce9c:      	br	x17

000000000003cea0 <av_frame_copy_props@plt>:
   3cea0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cea4:      	ldr	x17, [x16, #0x490]
   3cea8:      	add	x16, x16, #0x490
   3ceac:      	br	x17

000000000003ceb0 <av_channel_layout_copy@plt>:
   3ceb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ceb4:      	ldr	x17, [x16, #0x498]
   3ceb8:      	add	x16, x16, #0x498
   3cebc:      	br	x17

000000000003cec0 <av_rescale@plt>:
   3cec0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cec4:      	ldr	x17, [x16, #0x4a0]
   3cec8:      	add	x16, x16, #0x4a0
   3cecc:      	br	x17

000000000003ced0 <swr_next_pts@plt>:
   3ced0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ced4:      	ldr	x17, [x16, #0x4a8]
   3ced8:      	add	x16, x16, #0x4a8
   3cedc:      	br	x17

000000000003cee0 <swr_convert@plt>:
   3cee0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cee4:      	ldr	x17, [x16, #0x4b0]
   3cee8:      	add	x16, x16, #0x4b0
   3ceec:      	br	x17

000000000003cef0 <ff_filter_frame@plt>:
   3cef0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cef4:      	ldr	x17, [x16, #0x4b8]
   3cef8:      	add	x16, x16, #0x4b8
   3cefc:      	br	x17

000000000003cf00 <ff_avfilter_link_set_in_status@plt>:
   3cf00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf04:      	ldr	x17, [x16, #0x4c0]
   3cf08:      	add	x16, x16, #0x4c0
   3cf0c:      	br	x17

000000000003cf10 <ff_outlink_frame_wanted@plt>:
   3cf10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf14:      	ldr	x17, [x16, #0x4c8]
   3cf18:      	add	x16, x16, #0x4c8
   3cf1c:      	br	x17

000000000003cf20 <ff_inlink_request_frame@plt>:
   3cf20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf24:      	ldr	x17, [x16, #0x4d0]
   3cf28:      	add	x16, x16, #0x4d0
   3cf2c:      	br	x17

000000000003cf30 <ff_filter_set_ready@plt>:
   3cf30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf34:      	ldr	x17, [x16, #0x4d8]
   3cf38:      	add	x16, x16, #0x4d8
   3cf3c:      	br	x17

000000000003cf40 <swr_alloc_set_opts2@plt>:
   3cf40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf44:      	ldr	x17, [x16, #0x4e0]
   3cf48:      	add	x16, x16, #0x4e0
   3cf4c:      	br	x17

000000000003cf50 <swr_init@plt>:
   3cf50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf54:      	ldr	x17, [x16, #0x4e8]
   3cf58:      	add	x16, x16, #0x4e8
   3cf5c:      	br	x17

000000000003cf60 <av_channel_layout_compare@plt>:
   3cf60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf64:      	ldr	x17, [x16, #0x4f0]
   3cf68:      	add	x16, x16, #0x4f0
   3cf6c:      	br	x17

000000000003cf70 <av_channel_layout_describe@plt>:
   3cf70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf74:      	ldr	x17, [x16, #0x4f8]
   3cf78:      	add	x16, x16, #0x4f8
   3cf7c:      	br	x17

000000000003cf80 <av_get_sample_fmt_name@plt>:
   3cf80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf84:      	ldr	x17, [x16, #0x500]
   3cf88:      	add	x16, x16, #0x500
   3cf8c:      	br	x17

000000000003cf90 <av_log@plt>:
   3cf90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cf94:      	ldr	x17, [x16, #0x508]
   3cf98:      	add	x16, x16, #0x508
   3cf9c:      	br	x17

000000000003cfa0 <abort@plt>:
   3cfa0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cfa4:      	ldr	x17, [x16, #0x510]
   3cfa8:      	add	x16, x16, #0x510
   3cfac:      	br	x17

000000000003cfb0 <swr_get_class@plt>:
   3cfb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cfb4:      	ldr	x17, [x16, #0x518]
   3cfb8:      	add	x16, x16, #0x518
   3cfbc:      	br	x17

000000000003cfc0 <ff_make_format_list@plt>:
   3cfc0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cfc4:      	ldr	x17, [x16, #0x520]
   3cfc8:      	add	x16, x16, #0x520
   3cfcc:      	br	x17

000000000003cfd0 <av_frame_free@plt>:
   3cfd0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cfd4:      	ldr	x17, [x16, #0x528]
   3cfd8:      	add	x16, x16, #0x528
   3cfdc:      	br	x17

000000000003cfe0 <ff_filter_process_command@plt>:
   3cfe0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cfe4:      	ldr	x17, [x16, #0x530]
   3cfe8:      	add	x16, x16, #0x530
   3cfec:      	br	x17

000000000003cff0 <av_rescale_q@plt>:
   3cff0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3cff4:      	ldr	x17, [x16, #0x538]
   3cff8:      	add	x16, x16, #0x538
   3cffc:      	br	x17

000000000003d000 <av_get_bytes_per_sample@plt>:
   3d000:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d004:      	ldr	x17, [x16, #0x540]
   3d008:      	add	x16, x16, #0x540
   3d00c:      	br	x17

000000000003d010 <av_calloc@plt>:
   3d010:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d014:      	ldr	x17, [x16, #0x548]
   3d018:      	add	x16, x16, #0x548
   3d01c:      	br	x17

000000000003d020 <av_tx_init@plt>:
   3d020:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d024:      	ldr	x17, [x16, #0x550]
   3d028:      	add	x16, x16, #0x550
   3d02c:      	br	x17

000000000003d030 <av_malloc_array@plt>:
   3d030:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d034:      	ldr	x17, [x16, #0x558]
   3d038:      	add	x16, x16, #0x558
   3d03c:      	br	x17

000000000003d040 <memcpy@plt>:
   3d040:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d044:      	ldr	x17, [x16, #0x560]
   3d048:      	add	x16, x16, #0x560
   3d04c:      	br	x17

000000000003d050 <memset@plt>:
   3d050:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d054:      	ldr	x17, [x16, #0x568]
   3d058:      	add	x16, x16, #0x568
   3d05c:      	br	x17

000000000003d060 <av_freep@plt>:
   3d060:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d064:      	ldr	x17, [x16, #0x570]
   3d068:      	add	x16, x16, #0x570
   3d06c:      	br	x17

000000000003d070 <av_tx_uninit@plt>:
   3d070:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d074:      	ldr	x17, [x16, #0x578]
   3d078:      	add	x16, x16, #0x578
   3d07c:      	br	x17

000000000003d080 <ff_request_frame@plt>:
   3d080:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d084:      	ldr	x17, [x16, #0x580]
   3d088:      	add	x16, x16, #0x580
   3d08c:      	br	x17

000000000003d090 <av_filter_iterate@plt>:
   3d090:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d094:      	ldr	x17, [x16, #0x588]
   3d098:      	add	x16, x16, #0x588
   3d09c:      	br	x17

000000000003d0a0 <avfilter_get_by_name@plt>:
   3d0a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d0a4:      	ldr	x17, [x16, #0x590]
   3d0a8:      	add	x16, x16, #0x590
   3d0ac:      	br	x17

000000000003d0b0 <strcmp@plt>:
   3d0b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d0b4:      	ldr	x17, [x16, #0x598]
   3d0b8:      	add	x16, x16, #0x598
   3d0bc:      	br	x17

000000000003d0c0 <ff_set_common_formats@plt>:
   3d0c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d0c4:      	ldr	x17, [x16, #0x5a0]
   3d0c8:      	add	x16, x16, #0x5a0
   3d0cc:      	br	x17

000000000003d0d0 <ff_set_common_samplerates_from_list@plt>:
   3d0d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d0d4:      	ldr	x17, [x16, #0x5a8]
   3d0d8:      	add	x16, x16, #0x5a8
   3d0dc:      	br	x17

000000000003d0e0 <ff_set_common_channel_layouts_from_list@plt>:
   3d0e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d0e4:      	ldr	x17, [x16, #0x5b0]
   3d0e8:      	add	x16, x16, #0x5b0
   3d0ec:      	br	x17

000000000003d0f0 <ff_default_get_audio_buffer@plt>:
   3d0f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d0f4:      	ldr	x17, [x16, #0x5b8]
   3d0f8:      	add	x16, x16, #0x5b8
   3d0fc:      	br	x17

000000000003d100 <av_cpu_max_align@plt>:
   3d100:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d104:      	ldr	x17, [x16, #0x5c0]
   3d108:      	add	x16, x16, #0x5c0
   3d10c:      	br	x17

000000000003d110 <ff_frame_pool_get_audio_config@plt>:
   3d110:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d114:      	ldr	x17, [x16, #0x5c8]
   3d118:      	add	x16, x16, #0x5c8
   3d11c:      	br	x17

000000000003d120 <ff_frame_pool_uninit@plt>:
   3d120:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d124:      	ldr	x17, [x16, #0x5d0]
   3d128:      	add	x16, x16, #0x5d0
   3d12c:      	br	x17

000000000003d130 <ff_frame_pool_audio_init@plt>:
   3d130:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d134:      	ldr	x17, [x16, #0x5d8]
   3d138:      	add	x16, x16, #0x5d8
   3d13c:      	br	x17

000000000003d140 <ff_frame_pool_get@plt>:
   3d140:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d144:      	ldr	x17, [x16, #0x5e0]
   3d148:      	add	x16, x16, #0x5e0
   3d14c:      	br	x17

000000000003d150 <av_samples_set_silence@plt>:
   3d150:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d154:      	ldr	x17, [x16, #0x5e8]
   3d158:      	add	x16, x16, #0x5e8
   3d15c:      	br	x17

000000000003d160 <av_strtod@plt>:
   3d160:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d164:      	ldr	x17, [x16, #0x5f0]
   3d168:      	add	x16, x16, #0x5f0
   3d16c:      	br	x17

000000000003d170 <av_channel_layout_from_string@plt>:
   3d170:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d174:      	ldr	x17, [x16, #0x5f8]
   3d178:      	add	x16, x16, #0x5f8
   3d17c:      	br	x17

000000000003d180 <ff_append_inpad@plt>:
   3d180:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d184:      	ldr	x17, [x16, #0x600]
   3d188:      	add	x16, x16, #0x600
   3d18c:      	br	x17

000000000003d190 <ff_append_outpad@plt>:
   3d190:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d194:      	ldr	x17, [x16, #0x608]
   3d198:      	add	x16, x16, #0x608
   3d19c:      	br	x17

000000000003d1a0 <ff_append_outpad_free_name@plt>:
   3d1a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d1a4:      	ldr	x17, [x16, #0x610]
   3d1a8:      	add	x16, x16, #0x610
   3d1ac:      	br	x17

000000000003d1b0 <avfilter_link@plt>:
   3d1b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d1b4:      	ldr	x17, [x16, #0x618]
   3d1b8:      	add	x16, x16, #0x618
   3d1bc:      	br	x17

000000000003d1c0 <av_mallocz@plt>:
   3d1c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d1c4:      	ldr	x17, [x16, #0x620]
   3d1c8:      	add	x16, x16, #0x620
   3d1cc:      	br	x17

000000000003d1d0 <ff_framequeue_init@plt>:
   3d1d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d1d4:      	ldr	x17, [x16, #0x628]
   3d1d8:      	add	x16, x16, #0x628
   3d1dc:      	br	x17

000000000003d1e0 <av_get_media_type_string@plt>:
   3d1e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d1e4:      	ldr	x17, [x16, #0x630]
   3d1e8:      	add	x16, x16, #0x630
   3d1ec:      	br	x17

000000000003d1f0 <ff_framequeue_free@plt>:
   3d1f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d1f4:      	ldr	x17, [x16, #0x638]
   3d1f8:      	add	x16, x16, #0x638
   3d1fc:      	br	x17

000000000003d200 <av_buffer_unref@plt>:
   3d200:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d204:      	ldr	x17, [x16, #0x640]
   3d208:      	add	x16, x16, #0x640
   3d20c:      	br	x17

000000000003d210 <ff_filter_config_links@plt>:
   3d210:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d214:      	ldr	x17, [x16, #0x648]
   3d218:      	add	x16, x16, #0x648
   3d21c:      	br	x17

000000000003d220 <av_buffer_ref@plt>:
   3d220:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d224:      	ldr	x17, [x16, #0x650]
   3d228:      	add	x16, x16, #0x650
   3d22c:      	br	x17

000000000003d230 <avfilter_insert_filter@plt>:
   3d230:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d234:      	ldr	x17, [x16, #0x658]
   3d238:      	add	x16, x16, #0x658
   3d23c:      	br	x17

000000000003d240 <ff_formats_changeref@plt>:
   3d240:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d244:      	ldr	x17, [x16, #0x660]
   3d248:      	add	x16, x16, #0x660
   3d24c:      	br	x17

000000000003d250 <ff_channel_layouts_changeref@plt>:
   3d250:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d254:      	ldr	x17, [x16, #0x668]
   3d258:      	add	x16, x16, #0x668
   3d25c:      	br	x17

000000000003d260 <avfilter_process_command@plt>:
   3d260:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d264:      	ldr	x17, [x16, #0x670]
   3d268:      	add	x16, x16, #0x670
   3d26c:      	br	x17

000000000003d270 <av_strlcatf@plt>:
   3d270:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d274:      	ldr	x17, [x16, #0x678]
   3d278:      	add	x16, x16, #0x678
   3d27c:      	br	x17

000000000003d280 <av_strdup@plt>:
   3d280:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d284:      	ldr	x17, [x16, #0x680]
   3d288:      	add	x16, x16, #0x680
   3d28c:      	br	x17

000000000003d290 <av_expr_parse@plt>:
   3d290:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d294:      	ldr	x17, [x16, #0x688]
   3d298:      	add	x16, x16, #0x688
   3d29c:      	br	x17

000000000003d2a0 <av_expr_free@plt>:
   3d2a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d2a4:      	ldr	x17, [x16, #0x690]
   3d2a8:      	add	x16, x16, #0x690
   3d2ac:      	br	x17

000000000003d2b0 <av_free@plt>:
   3d2b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d2b4:      	ldr	x17, [x16, #0x698]
   3d2b8:      	add	x16, x16, #0x698
   3d2bc:      	br	x17

000000000003d2c0 <ff_filter_alloc@plt>:
   3d2c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d2c4:      	ldr	x17, [x16, #0x6a0]
   3d2c8:      	add	x16, x16, #0x6a0
   3d2cc:      	br	x17

000000000003d2d0 <av_opt_set_defaults@plt>:
   3d2d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d2d4:      	ldr	x17, [x16, #0x6a8]
   3d2d8:      	add	x16, x16, #0x6a8
   3d2dc:      	br	x17

000000000003d2e0 <av_memdup@plt>:
   3d2e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d2e4:      	ldr	x17, [x16, #0x6b0]
   3d2e8:      	add	x16, x16, #0x6b0
   3d2ec:      	br	x17

000000000003d2f0 <avfilter_free@plt>:
   3d2f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d2f4:      	ldr	x17, [x16, #0x6b8]
   3d2f8:      	add	x16, x16, #0x6b8
   3d2fc:      	br	x17

000000000003d300 <ff_filter_graph_remove_filter@plt>:
   3d300:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d304:      	ldr	x17, [x16, #0x6c0]
   3d308:      	add	x16, x16, #0x6c0
   3d30c:      	br	x17

000000000003d310 <av_opt_free@plt>:
   3d310:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d314:      	ldr	x17, [x16, #0x6c8]
   3d318:      	add	x16, x16, #0x6c8
   3d31c:      	br	x17

000000000003d320 <ff_formats_unref@plt>:
   3d320:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d324:      	ldr	x17, [x16, #0x6d0]
   3d328:      	add	x16, x16, #0x6d0
   3d32c:      	br	x17

000000000003d330 <ff_channel_layouts_unref@plt>:
   3d330:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d334:      	ldr	x17, [x16, #0x6d8]
   3d338:      	add	x16, x16, #0x6d8
   3d33c:      	br	x17

000000000003d340 <ff_filter_get_nb_threads@plt>:
   3d340:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d344:      	ldr	x17, [x16, #0x6e0]
   3d348:      	add	x16, x16, #0x6e0
   3d34c:      	br	x17

000000000003d350 <ff_filter_opt_parse@plt>:
   3d350:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d354:      	ldr	x17, [x16, #0x6e8]
   3d358:      	add	x16, x16, #0x6e8
   3d35c:      	br	x17

000000000003d360 <av_opt_next@plt>:
   3d360:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d364:      	ldr	x17, [x16, #0x6f0]
   3d368:      	add	x16, x16, #0x6f0
   3d36c:      	br	x17

000000000003d370 <av_opt_get_key_value@plt>:
   3d370:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d374:      	ldr	x17, [x16, #0x6f8]
   3d378:      	add	x16, x16, #0x6f8
   3d37c:      	br	x17

000000000003d380 <av_dict_set@plt>:
   3d380:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d384:      	ldr	x17, [x16, #0x700]
   3d388:      	add	x16, x16, #0x700
   3d38c:      	br	x17

000000000003d390 <av_strerror@plt>:
   3d390:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d394:      	ldr	x17, [x16, #0x708]
   3d398:      	add	x16, x16, #0x708
   3d39c:      	br	x17

000000000003d3a0 <av_opt_find2@plt>:
   3d3a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d3a4:      	ldr	x17, [x16, #0x710]
   3d3a8:      	add	x16, x16, #0x710
   3d3ac:      	br	x17

000000000003d3b0 <av_opt_set@plt>:
   3d3b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d3b4:      	ldr	x17, [x16, #0x718]
   3d3b8:      	add	x16, x16, #0x718
   3d3bc:      	br	x17

000000000003d3c0 <avfilter_init_dict@plt>:
   3d3c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d3c4:      	ldr	x17, [x16, #0x720]
   3d3c8:      	add	x16, x16, #0x720
   3d3cc:      	br	x17

000000000003d3d0 <av_opt_set_dict2@plt>:
   3d3d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d3d4:      	ldr	x17, [x16, #0x728]
   3d3d8:      	add	x16, x16, #0x728
   3d3dc:      	br	x17

000000000003d3e0 <avfilter_init_str@plt>:
   3d3e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d3e4:      	ldr	x17, [x16, #0x730]
   3d3e8:      	add	x16, x16, #0x730
   3d3ec:      	br	x17

000000000003d3f0 <av_dict_iterate@plt>:
   3d3f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d3f4:      	ldr	x17, [x16, #0x738]
   3d3f8:      	add	x16, x16, #0x738
   3d3fc:      	br	x17

000000000003d400 <av_dict_free@plt>:
   3d400:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d404:      	ldr	x17, [x16, #0x740]
   3d408:      	add	x16, x16, #0x740
   3d40c:      	br	x17

000000000003d410 <ff_framequeue_add@plt>:
   3d410:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d414:      	ldr	x17, [x16, #0x748]
   3d418:      	add	x16, x16, #0x748
   3d41c:      	br	x17

000000000003d420 <ff_filter_activate@plt>:
   3d420:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d424:      	ldr	x17, [x16, #0x750]
   3d428:      	add	x16, x16, #0x750
   3d42c:      	br	x17

000000000003d430 <ff_inlink_consume_samples@plt>:
   3d430:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d434:      	ldr	x17, [x16, #0x758]
   3d438:      	add	x16, x16, #0x758
   3d43c:      	br	x17

000000000003d440 <ff_inlink_make_frame_writable@plt>:
   3d440:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d444:      	ldr	x17, [x16, #0x760]
   3d448:      	add	x16, x16, #0x760
   3d44c:      	br	x17

000000000003d450 <ff_inlink_process_commands@plt>:
   3d450:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d454:      	ldr	x17, [x16, #0x768]
   3d458:      	add	x16, x16, #0x768
   3d45c:      	br	x17

000000000003d460 <ff_inlink_evaluate_timeline_at_frame@plt>:
   3d460:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d464:      	ldr	x17, [x16, #0x770]
   3d468:      	add	x16, x16, #0x770
   3d46c:      	br	x17

000000000003d470 <ff_avfilter_graph_update_heap@plt>:
   3d470:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d474:      	ldr	x17, [x16, #0x778]
   3d478:      	add	x16, x16, #0x778
   3d47c:      	br	x17

000000000003d480 <ff_inlink_check_available_samples@plt>:
   3d480:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d484:      	ldr	x17, [x16, #0x780]
   3d488:      	add	x16, x16, #0x780
   3d48c:      	br	x17

000000000003d490 <ff_framequeue_peek@plt>:
   3d490:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d494:      	ldr	x17, [x16, #0x788]
   3d498:      	add	x16, x16, #0x788
   3d49c:      	br	x17

000000000003d4a0 <av_samples_copy@plt>:
   3d4a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d4a4:      	ldr	x17, [x16, #0x790]
   3d4a8:      	add	x16, x16, #0x790
   3d4ac:      	br	x17

000000000003d4b0 <ff_framequeue_skip_samples@plt>:
   3d4b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d4b4:      	ldr	x17, [x16, #0x798]
   3d4b8:      	add	x16, x16, #0x798
   3d4bc:      	br	x17

000000000003d4c0 <av_frame_is_writable@plt>:
   3d4c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d4c4:      	ldr	x17, [x16, #0x7a0]
   3d4c8:      	add	x16, x16, #0x7a0
   3d4cc:      	br	x17

000000000003d4d0 <ff_get_video_buffer@plt>:
   3d4d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d4d4:      	ldr	x17, [x16, #0x7a8]
   3d4d8:      	add	x16, x16, #0x7a8
   3d4dc:      	br	x17

000000000003d4e0 <av_frame_copy@plt>:
   3d4e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d4e4:      	ldr	x17, [x16, #0x7b0]
   3d4e8:      	add	x16, x16, #0x7b0
   3d4ec:      	br	x17

000000000003d4f0 <av_expr_eval@plt>:
   3d4f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d4f4:      	ldr	x17, [x16, #0x7b8]
   3d4f8:      	add	x16, x16, #0x7b8
   3d4fc:      	br	x17

000000000003d500 <ff_framequeue_take@plt>:
   3d500:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d504:      	ldr	x17, [x16, #0x7c0]
   3d508:      	add	x16, x16, #0x7c0
   3d50c:      	br	x17

000000000003d510 <ff_filter_execute@plt>:
   3d510:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d514:      	ldr	x17, [x16, #0x7c8]
   3d518:      	add	x16, x16, #0x7c8
   3d51c:      	br	x17

000000000003d520 <ff_framequeue_global_init@plt>:
   3d520:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d524:      	ldr	x17, [x16, #0x7d0]
   3d528:      	add	x16, x16, #0x7d0
   3d52c:      	br	x17

000000000003d530 <ff_graph_thread_free@plt>:
   3d530:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d534:      	ldr	x17, [x16, #0x7d8]
   3d538:      	add	x16, x16, #0x7d8
   3d53c:      	br	x17

000000000003d540 <avfilter_graph_create_filter@plt>:
   3d540:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d544:      	ldr	x17, [x16, #0x7e0]
   3d548:      	add	x16, x16, #0x7e0
   3d54c:      	br	x17

000000000003d550 <avfilter_graph_alloc_filter@plt>:
   3d550:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d554:      	ldr	x17, [x16, #0x7e8]
   3d558:      	add	x16, x16, #0x7e8
   3d55c:      	br	x17

000000000003d560 <ff_graph_thread_init@plt>:
   3d560:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d564:      	ldr	x17, [x16, #0x7f0]
   3d568:      	add	x16, x16, #0x7f0
   3d56c:      	br	x17

000000000003d570 <ff_fmt_is_regular_yuv@plt>:
   3d570:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d574:      	ldr	x17, [x16, #0x7f8]
   3d578:      	add	x16, x16, #0x7f8
   3d57c:      	br	x17

000000000003d580 <av_pix_fmt_desc_get@plt>:
   3d580:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d584:      	ldr	x17, [x16, #0x800]
   3d588:      	add	x16, x16, #0x800
   3d58c:      	br	x17

000000000003d590 <ff_fmt_is_forced_full_range@plt>:
   3d590:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d594:      	ldr	x17, [x16, #0x808]
   3d598:      	add	x16, x16, #0x808
   3d59c:      	br	x17

000000000003d5a0 <ff_filter_get_negotiation@plt>:
   3d5a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d5a4:      	ldr	x17, [x16, #0x810]
   3d5a8:      	add	x16, x16, #0x810
   3d5ac:      	br	x17

000000000003d5b0 <snprintf@plt>:
   3d5b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d5b4:      	ldr	x17, [x16, #0x818]
   3d5b8:      	add	x16, x16, #0x818
   3d5bc:      	br	x17

000000000003d5c0 <av_bprint_init@plt>:
   3d5c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d5c4:      	ldr	x17, [x16, #0x820]
   3d5c8:      	add	x16, x16, #0x820
   3d5cc:      	br	x17

000000000003d5d0 <av_bprintf@plt>:
   3d5d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d5d4:      	ldr	x17, [x16, #0x828]
   3d5d8:      	add	x16, x16, #0x828
   3d5dc:      	br	x17

000000000003d5e0 <ff_add_format@plt>:
   3d5e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d5e4:      	ldr	x17, [x16, #0x830]
   3d5e8:      	add	x16, x16, #0x830
   3d5ec:      	br	x17

000000000003d5f0 <ff_add_channel_layout@plt>:
   3d5f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d5f4:      	ldr	x17, [x16, #0x838]
   3d5f8:      	add	x16, x16, #0x838
   3d5fc:      	br	x17

000000000003d600 <av_get_packed_sample_fmt@plt>:
   3d600:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d604:      	ldr	x17, [x16, #0x840]
   3d608:      	add	x16, x16, #0x840
   3d60c:      	br	x17

000000000003d610 <av_get_planar_sample_fmt@plt>:
   3d610:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d614:      	ldr	x17, [x16, #0x848]
   3d618:      	add	x16, x16, #0x848
   3d61c:      	br	x17

000000000003d620 <av_channel_layout_subset@plt>:
   3d620:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d624:      	ldr	x17, [x16, #0x850]
   3d628:      	add	x16, x16, #0x850
   3d62c:      	br	x17

000000000003d630 <av_channel_layout_channel_from_index@plt>:
   3d630:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d634:      	ldr	x17, [x16, #0x858]
   3d638:      	add	x16, x16, #0x858
   3d63c:      	br	x17

000000000003d640 <av_image_check_size2@plt>:
   3d640:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d644:      	ldr	x17, [x16, #0x860]
   3d648:      	add	x16, x16, #0x860
   3d64c:      	br	x17

000000000003d650 <avfilter_graph_send_command@plt>:
   3d650:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d654:      	ldr	x17, [x16, #0x868]
   3d658:      	add	x16, x16, #0x868
   3d65c:      	br	x17

000000000003d660 <av_buffersink_get_frame_flags@plt>:
   3d660:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d664:      	ldr	x17, [x16, #0x870]
   3d668:      	add	x16, x16, #0x870
   3d66c:      	br	x17

000000000003d670 <ff_filter_graph_run_once@plt>:
   3d670:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d674:      	ldr	x17, [x16, #0x878]
   3d678:      	add	x16, x16, #0x878
   3d67c:      	br	x17

000000000003d680 <ff_default_query_formats@plt>:
   3d680:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d684:      	ldr	x17, [x16, #0x880]
   3d688:      	add	x16, x16, #0x880
   3d68c:      	br	x17

000000000003d690 <ff_formats_check_pixel_formats@plt>:
   3d690:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d694:      	ldr	x17, [x16, #0x888]
   3d698:      	add	x16, x16, #0x888
   3d69c:      	br	x17

000000000003d6a0 <ff_formats_check_color_spaces@plt>:
   3d6a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d6a4:      	ldr	x17, [x16, #0x890]
   3d6a8:      	add	x16, x16, #0x890
   3d6ac:      	br	x17

000000000003d6b0 <ff_formats_check_color_ranges@plt>:
   3d6b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d6b4:      	ldr	x17, [x16, #0x898]
   3d6b8:      	add	x16, x16, #0x898
   3d6bc:      	br	x17

000000000003d6c0 <ff_formats_check_sample_formats@plt>:
   3d6c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d6c4:      	ldr	x17, [x16, #0x8a0]
   3d6c8:      	add	x16, x16, #0x8a0
   3d6cc:      	br	x17

000000000003d6d0 <ff_formats_check_sample_rates@plt>:
   3d6d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d6d4:      	ldr	x17, [x16, #0x8a8]
   3d6d8:      	add	x16, x16, #0x8a8
   3d6dc:      	br	x17

000000000003d6e0 <ff_formats_check_channel_layouts@plt>:
   3d6e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d6e4:      	ldr	x17, [x16, #0x8b0]
   3d6e8:      	add	x16, x16, #0x8b0
   3d6ec:      	br	x17

000000000003d6f0 <av_find_best_pix_fmt_of_2@plt>:
   3d6f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d6f4:      	ldr	x17, [x16, #0x8b8]
   3d6f8:      	add	x16, x16, #0x8b8
   3d6fc:      	br	x17

000000000003d700 <av_get_pix_fmt_name@plt>:
   3d700:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d704:      	ldr	x17, [x16, #0x8c0]
   3d708:      	add	x16, x16, #0x8c0
   3d70c:      	br	x17

000000000003d710 <av_sample_fmt_is_planar@plt>:
   3d710:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d714:      	ldr	x17, [x16, #0x8c8]
   3d718:      	add	x16, x16, #0x8c8
   3d71c:      	br	x17

000000000003d720 <av_channel_layout_from_mask@plt>:
   3d720:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d724:      	ldr	x17, [x16, #0x8d0]
   3d728:      	add	x16, x16, #0x8d0
   3d72c:      	br	x17

000000000003d730 <ff_set_common_color_spaces@plt>:
   3d730:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d734:      	ldr	x17, [x16, #0x8d8]
   3d738:      	add	x16, x16, #0x8d8
   3d73c:      	br	x17

000000000003d740 <ff_set_common_color_ranges@plt>:
   3d740:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d744:      	ldr	x17, [x16, #0x8e0]
   3d748:      	add	x16, x16, #0x8e0
   3d74c:      	br	x17

000000000003d750 <strchr@plt>:
   3d750:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d754:      	ldr	x17, [x16, #0x8e8]
   3d758:      	add	x16, x16, #0x8e8
   3d75c:      	br	x17

000000000003d760 <ff_set_common_channel_layouts@plt>:
   3d760:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d764:      	ldr	x17, [x16, #0x8f0]
   3d768:      	add	x16, x16, #0x8f0
   3d76c:      	br	x17

000000000003d770 <ff_set_common_samplerates@plt>:
   3d770:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d774:      	ldr	x17, [x16, #0x8f8]
   3d778:      	add	x16, x16, #0x8f8
   3d77c:      	br	x17

000000000003d780 <av_frame_move_ref@plt>:
   3d780:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d784:      	ldr	x17, [x16, #0x900]
   3d788:      	add	x16, x16, #0x900
   3d78c:      	br	x17

000000000003d790 <av_frame_ref@plt>:
   3d790:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d794:      	ldr	x17, [x16, #0x908]
   3d798:      	add	x16, x16, #0x908
   3d79c:      	br	x17

000000000003d7a0 <av_buffersrc_add_frame_flags@plt>:
   3d7a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d7a4:      	ldr	x17, [x16, #0x910]
   3d7a8:      	add	x16, x16, #0x910
   3d7ac:      	br	x17

000000000003d7b0 <av_buffersrc_close@plt>:
   3d7b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d7b4:      	ldr	x17, [x16, #0x918]
   3d7b8:      	add	x16, x16, #0x918
   3d7bc:      	br	x17

000000000003d7c0 <av_color_space_name@plt>:
   3d7c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d7c4:      	ldr	x17, [x16, #0x920]
   3d7c8:      	add	x16, x16, #0x920
   3d7cc:      	br	x17

000000000003d7d0 <av_frame_alloc@plt>:
   3d7d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d7d4:      	ldr	x17, [x16, #0x928]
   3d7d8:      	add	x16, x16, #0x928
   3d7dc:      	br	x17

000000000003d7e0 <av_frame_clone@plt>:
   3d7e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d7e4:      	ldr	x17, [x16, #0x930]
   3d7e8:      	add	x16, x16, #0x930
   3d7ec:      	br	x17

000000000003d7f0 <av_ts_make_time_string2@plt>:
   3d7f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d7f4:      	ldr	x17, [x16, #0x938]
   3d7f8:      	add	x16, x16, #0x938
   3d7fc:      	br	x17

000000000003d800 <av_color_range_name@plt>:
   3d800:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d804:      	ldr	x17, [x16, #0x940]
   3d808:      	add	x16, x16, #0x940
   3d80c:      	br	x17

000000000003d810 <ff_ccfifo_uninit@plt>:
   3d810:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d814:      	ldr	x17, [x16, #0x948]
   3d818:      	add	x16, x16, #0x948
   3d81c:      	br	x17

000000000003d820 <av_fifo_freep2@plt>:
   3d820:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d824:      	ldr	x17, [x16, #0x950]
   3d828:      	add	x16, x16, #0x950
   3d82c:      	br	x17

000000000003d830 <av_fifo_alloc2@plt>:
   3d830:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d834:      	ldr	x17, [x16, #0x958]
   3d838:      	add	x16, x16, #0x958
   3d83c:      	br	x17

000000000003d840 <ff_ccfifo_injectbytes@plt>:
   3d840:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d844:      	ldr	x17, [x16, #0x960]
   3d848:      	add	x16, x16, #0x960
   3d84c:      	br	x17

000000000003d850 <av_fifo_can_read@plt>:
   3d850:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d854:      	ldr	x17, [x16, #0x968]
   3d858:      	add	x16, x16, #0x968
   3d85c:      	br	x17

000000000003d860 <av_fifo_read@plt>:
   3d860:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d864:      	ldr	x17, [x16, #0x970]
   3d868:      	add	x16, x16, #0x970
   3d86c:      	br	x17

000000000003d870 <av_frame_new_side_data@plt>:
   3d870:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d874:      	ldr	x17, [x16, #0x978]
   3d878:      	add	x16, x16, #0x978
   3d87c:      	br	x17

000000000003d880 <ff_ccfifo_extractbytes@plt>:
   3d880:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d884:      	ldr	x17, [x16, #0x980]
   3d888:      	add	x16, x16, #0x980
   3d88c:      	br	x17

000000000003d890 <av_log_once@plt>:
   3d890:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d894:      	ldr	x17, [x16, #0x988]
   3d898:      	add	x16, x16, #0x988
   3d89c:      	br	x17

000000000003d8a0 <av_fifo_write@plt>:
   3d8a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d8a4:      	ldr	x17, [x16, #0x990]
   3d8a8:      	add	x16, x16, #0x990
   3d8ac:      	br	x17

000000000003d8b0 <av_frame_get_side_data@plt>:
   3d8b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d8b4:      	ldr	x17, [x16, #0x998]
   3d8b8:      	add	x16, x16, #0x998
   3d8bc:      	br	x17

000000000003d8c0 <av_frame_remove_side_data@plt>:
   3d8c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d8c4:      	ldr	x17, [x16, #0x9a0]
   3d8c8:      	add	x16, x16, #0x9a0
   3d8cc:      	br	x17

000000000003d8d0 <ff_matrix_invert_3x3@plt>:
   3d8d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d8d4:      	ldr	x17, [x16, #0x9a8]
   3d8d8:      	add	x16, x16, #0x9a8
   3d8dc:      	br	x17

000000000003d8e0 <ff_matrix_mul_3x3_vec@plt>:
   3d8e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d8e4:      	ldr	x17, [x16, #0x9b0]
   3d8e8:      	add	x16, x16, #0x9b0
   3d8ec:      	br	x17

000000000003d8f0 <ff_fill_rgb2yuv_table@plt>:
   3d8f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d8f4:      	ldr	x17, [x16, #0x9b8]
   3d8f8:      	add	x16, x16, #0x9b8
   3d8fc:      	br	x17

000000000003d900 <av_d2q@plt>:
   3d900:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d904:      	ldr	x17, [x16, #0x9c0]
   3d908:      	add	x16, x16, #0x9c0
   3d90c:      	br	x17

000000000003d910 <ff_fill_rgba_map@plt>:
   3d910:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d914:      	ldr	x17, [x16, #0x9c8]
   3d918:      	add	x16, x16, #0x9c8
   3d91c:      	br	x17

000000000003d920 <ff_draw_init2@plt>:
   3d920:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d924:      	ldr	x17, [x16, #0x9d0]
   3d928:      	add	x16, x16, #0x9d0
   3d92c:      	br	x17

000000000003d930 <av_csp_luma_coeffs_from_avcsp@plt>:
   3d930:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d934:      	ldr	x17, [x16, #0x9d8]
   3d938:      	add	x16, x16, #0x9d8
   3d93c:      	br	x17

000000000003d940 <ff_draw_init@plt>:
   3d940:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d944:      	ldr	x17, [x16, #0x9e0]
   3d948:      	add	x16, x16, #0x9e0
   3d94c:      	br	x17

000000000003d950 <ff_draw_color@plt>:
   3d950:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d954:      	ldr	x17, [x16, #0x9e8]
   3d958:      	add	x16, x16, #0x9e8
   3d95c:      	br	x17

000000000003d960 <ff_copy_rectangle2@plt>:
   3d960:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d964:      	ldr	x17, [x16, #0x9f0]
   3d968:      	add	x16, x16, #0x9f0
   3d96c:      	br	x17

000000000003d970 <ff_fill_rectangle@plt>:
   3d970:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d974:      	ldr	x17, [x16, #0x9f8]
   3d978:      	add	x16, x16, #0x9f8
   3d97c:      	br	x17

000000000003d980 <ff_draw_round_to_sub@plt>:
   3d980:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d984:      	ldr	x17, [x16, #0xa00]
   3d988:      	add	x16, x16, #0xa00
   3d98c:      	br	x17

000000000003d990 <ff_draw_supported_pixel_formats@plt>:
   3d990:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d994:      	ldr	x17, [x16, #0xa08]
   3d998:      	add	x16, x16, #0xa08
   3d99c:      	br	x17

000000000003d9a0 <av_fast_realloc@plt>:
   3d9a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d9a4:      	ldr	x17, [x16, #0xa10]
   3d9a8:      	add	x16, x16, #0xa10
   3d9ac:      	br	x17

000000000003d9b0 <ff_fmt_is_in@plt>:
   3d9b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d9b4:      	ldr	x17, [x16, #0xa18]
   3d9b8:      	add	x16, x16, #0xa18
   3d9bc:      	br	x17

000000000003d9c0 <ff_make_formats_list_singleton@plt>:
   3d9c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d9c4:      	ldr	x17, [x16, #0xa20]
   3d9c8:      	add	x16, x16, #0xa20
   3d9cc:      	br	x17

000000000003d9d0 <ff_formats_pixdesc_filter@plt>:
   3d9d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d9d4:      	ldr	x17, [x16, #0xa28]
   3d9d8:      	add	x16, x16, #0xa28
   3d9dc:      	br	x17

000000000003d9e0 <ff_all_color_spaces@plt>:
   3d9e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d9e4:      	ldr	x17, [x16, #0xa30]
   3d9e8:      	add	x16, x16, #0xa30
   3d9ec:      	br	x17

000000000003d9f0 <ff_all_color_ranges@plt>:
   3d9f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3d9f4:      	ldr	x17, [x16, #0xa38]
   3d9f8:      	add	x16, x16, #0xa38
   3d9fc:      	br	x17

000000000003da00 <ff_set_common_all_channel_counts@plt>:
   3da00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da04:      	ldr	x17, [x16, #0xa40]
   3da08:      	add	x16, x16, #0xa40
   3da0c:      	br	x17

000000000003da10 <ff_set_common_all_samplerates@plt>:
   3da10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da14:      	ldr	x17, [x16, #0xa48]
   3da18:      	add	x16, x16, #0xa48
   3da1c:      	br	x17

000000000003da20 <ff_set_common_all_color_spaces@plt>:
   3da20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da24:      	ldr	x17, [x16, #0xa50]
   3da28:      	add	x16, x16, #0xa50
   3da2c:      	br	x17

000000000003da30 <ff_set_common_all_color_ranges@plt>:
   3da30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da34:      	ldr	x17, [x16, #0xa58]
   3da38:      	add	x16, x16, #0xa58
   3da3c:      	br	x17

000000000003da40 <ff_set_common_formats_from_list@plt>:
   3da40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da44:      	ldr	x17, [x16, #0xa60]
   3da48:      	add	x16, x16, #0xa60
   3da4c:      	br	x17

000000000003da50 <ff_set_common_channel_layouts2@plt>:
   3da50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da54:      	ldr	x17, [x16, #0xa68]
   3da58:      	add	x16, x16, #0xa68
   3da5c:      	br	x17

000000000003da60 <ff_set_common_samplerates2@plt>:
   3da60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da64:      	ldr	x17, [x16, #0xa70]
   3da68:      	add	x16, x16, #0xa70
   3da6c:      	br	x17

000000000003da70 <ff_set_common_color_spaces2@plt>:
   3da70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da74:      	ldr	x17, [x16, #0xa78]
   3da78:      	add	x16, x16, #0xa78
   3da7c:      	br	x17

000000000003da80 <ff_set_common_color_ranges2@plt>:
   3da80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da84:      	ldr	x17, [x16, #0xa80]
   3da88:      	add	x16, x16, #0xa80
   3da8c:      	br	x17

000000000003da90 <ff_set_common_formats2@plt>:
   3da90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3da94:      	ldr	x17, [x16, #0xa88]
   3da98:      	add	x16, x16, #0xa88
   3da9c:      	br	x17

000000000003daa0 <memmove@plt>:
   3daa0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3daa4:      	ldr	x17, [x16, #0xa90]
   3daa8:      	add	x16, x16, #0xa90
   3daac:      	br	x17

000000000003dab0 <ff_frame_pool_video_init@plt>:
   3dab0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dab4:      	ldr	x17, [x16, #0xa98]
   3dab8:      	add	x16, x16, #0xa98
   3dabc:      	br	x17

000000000003dac0 <av_image_fill_plane_sizes@plt>:
   3dac0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dac4:      	ldr	x17, [x16, #0xaa0]
   3dac8:      	add	x16, x16, #0xaa0
   3dacc:      	br	x17

000000000003dad0 <av_buffer_pool_init@plt>:
   3dad0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dad4:      	ldr	x17, [x16, #0xaa8]
   3dad8:      	add	x16, x16, #0xaa8
   3dadc:      	br	x17

000000000003dae0 <av_image_fill_linesizes@plt>:
   3dae0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dae4:      	ldr	x17, [x16, #0xab0]
   3dae8:      	add	x16, x16, #0xab0
   3daec:      	br	x17

000000000003daf0 <av_buffer_pool_uninit@plt>:
   3daf0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3daf4:      	ldr	x17, [x16, #0xab8]
   3daf8:      	add	x16, x16, #0xab8
   3dafc:      	br	x17

000000000003db00 <av_samples_get_buffer_size@plt>:
   3db00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db04:      	ldr	x17, [x16, #0xac0]
   3db08:      	add	x16, x16, #0xac0
   3db0c:      	br	x17

000000000003db10 <ff_frame_pool_get_video_config@plt>:
   3db10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db14:      	ldr	x17, [x16, #0xac8]
   3db18:      	add	x16, x16, #0xac8
   3db1c:      	br	x17

000000000003db20 <av_buffer_pool_get@plt>:
   3db20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db24:      	ldr	x17, [x16, #0xad0]
   3db28:      	add	x16, x16, #0xad0
   3db2c:      	br	x17

000000000003db30 <avpriv_set_systematic_pal2@plt>:
   3db30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db34:      	ldr	x17, [x16, #0xad8]
   3db38:      	add	x16, x16, #0xad8
   3db3c:      	br	x17

000000000003db40 <ff_framesync_preinit@plt>:
   3db40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db44:      	ldr	x17, [x16, #0xae0]
   3db48:      	add	x16, x16, #0xae0
   3db4c:      	br	x17

000000000003db50 <ff_framesync_init@plt>:
   3db50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db54:      	ldr	x17, [x16, #0xae8]
   3db58:      	add	x16, x16, #0xae8
   3db5c:      	br	x17

000000000003db60 <ff_framesync_configure@plt>:
   3db60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db64:      	ldr	x17, [x16, #0xaf0]
   3db68:      	add	x16, x16, #0xaf0
   3db6c:      	br	x17

000000000003db70 <av_gcd_q@plt>:
   3db70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db74:      	ldr	x17, [x16, #0xaf8]
   3db78:      	add	x16, x16, #0xaf8
   3db7c:      	br	x17

000000000003db80 <ff_framesync_get_frame@plt>:
   3db80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db84:      	ldr	x17, [x16, #0xb00]
   3db88:      	add	x16, x16, #0xb00
   3db8c:      	br	x17

000000000003db90 <ff_framesync_uninit@plt>:
   3db90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3db94:      	ldr	x17, [x16, #0xb08]
   3db98:      	add	x16, x16, #0xb08
   3db9c:      	br	x17

000000000003dba0 <ff_framesync_activate@plt>:
   3dba0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dba4:      	ldr	x17, [x16, #0xb10]
   3dba8:      	add	x16, x16, #0xb10
   3dbac:      	br	x17

000000000003dbb0 <ff_framesync_init_dualinput@plt>:
   3dbb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dbb4:      	ldr	x17, [x16, #0xb18]
   3dbb8:      	add	x16, x16, #0xb18
   3dbbc:      	br	x17

000000000003dbc0 <ff_framesync_dualinput_get@plt>:
   3dbc0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dbc4:      	ldr	x17, [x16, #0xb20]
   3dbc8:      	add	x16, x16, #0xb20
   3dbcc:      	br	x17

000000000003dbd0 <ff_framesync_dualinput_get_writable@plt>:
   3dbd0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dbd4:      	ldr	x17, [x16, #0xb28]
   3dbd8:      	add	x16, x16, #0xb28
   3dbdc:      	br	x17

000000000003dbe0 <av_malloc@plt>:
   3dbe0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dbe4:      	ldr	x17, [x16, #0xb30]
   3dbe8:      	add	x16, x16, #0xb30
   3dbec:      	br	x17

000000000003dbf0 <av_bprint_init_for_buffer@plt>:
   3dbf0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dbf4:      	ldr	x17, [x16, #0xb38]
   3dbf8:      	add	x16, x16, #0xb38
   3dbfc:      	br	x17

000000000003dc00 <strlen@plt>:
   3dc00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc04:      	ldr	x17, [x16, #0xb40]
   3dc08:      	add	x16, x16, #0xb40
   3dc0c:      	br	x17

000000000003dc10 <av_bprint_chars@plt>:
   3dc10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc14:      	ldr	x17, [x16, #0xb48]
   3dc18:      	add	x16, x16, #0xb48
   3dc1c:      	br	x17

000000000003dc20 <av_channel_layout_describe_bprint@plt>:
   3dc20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc24:      	ldr	x17, [x16, #0xb50]
   3dc28:      	add	x16, x16, #0xb50
   3dc2c:      	br	x17

000000000003dc30 <avfilter_inout_free@plt>:
   3dc30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc34:      	ldr	x17, [x16, #0xb58]
   3dc38:      	add	x16, x16, #0xb58
   3dc3c:      	br	x17

000000000003dc40 <avfilter_graph_parse2@plt>:
   3dc40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc44:      	ldr	x17, [x16, #0xb60]
   3dc48:      	add	x16, x16, #0xb60
   3dc4c:      	br	x17

000000000003dc50 <avfilter_graph_segment_parse@plt>:
   3dc50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc54:      	ldr	x17, [x16, #0xb68]
   3dc58:      	add	x16, x16, #0xb68
   3dc5c:      	br	x17

000000000003dc60 <avfilter_graph_segment_apply@plt>:
   3dc60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc64:      	ldr	x17, [x16, #0xb70]
   3dc68:      	add	x16, x16, #0xb70
   3dc6c:      	br	x17

000000000003dc70 <avfilter_graph_segment_free@plt>:
   3dc70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc74:      	ldr	x17, [x16, #0xb78]
   3dc78:      	add	x16, x16, #0xb78
   3dc7c:      	br	x17

000000000003dc80 <strspn@plt>:
   3dc80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc84:      	ldr	x17, [x16, #0xb80]
   3dc88:      	add	x16, x16, #0xb80
   3dc8c:      	br	x17

000000000003dc90 <strncmp@plt>:
   3dc90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dc94:      	ldr	x17, [x16, #0xb88]
   3dc98:      	add	x16, x16, #0xb88
   3dc9c:      	br	x17

000000000003dca0 <av_get_token@plt>:
   3dca0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dca4:      	ldr	x17, [x16, #0xb90]
   3dca8:      	add	x16, x16, #0xb90
   3dcac:      	br	x17

000000000003dcb0 <av_dynarray_add_nofree@plt>:
   3dcb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dcb4:      	ldr	x17, [x16, #0xb98]
   3dcb8:      	add	x16, x16, #0xb98
   3dcbc:      	br	x17

000000000003dcc0 <av_strlcpy@plt>:
   3dcc0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dcc4:      	ldr	x17, [x16, #0xba0]
   3dcc8:      	add	x16, x16, #0xba0
   3dccc:      	br	x17

000000000003dcd0 <avfilter_graph_segment_create_filters@plt>:
   3dcd0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dcd4:      	ldr	x17, [x16, #0xba8]
   3dcd8:      	add	x16, x16, #0xba8
   3dcdc:      	br	x17

000000000003dce0 <avfilter_graph_segment_apply_opts@plt>:
   3dce0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dce4:      	ldr	x17, [x16, #0xbb0]
   3dce8:      	add	x16, x16, #0xbb0
   3dcec:      	br	x17

000000000003dcf0 <avfilter_graph_segment_init@plt>:
   3dcf0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dcf4:      	ldr	x17, [x16, #0xbb8]
   3dcf8:      	add	x16, x16, #0xbb8
   3dcfc:      	br	x17

000000000003dd00 <avfilter_graph_segment_link@plt>:
   3dd00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd04:      	ldr	x17, [x16, #0xbc0]
   3dd08:      	add	x16, x16, #0xbc0
   3dd0c:      	br	x17

000000000003dd10 <av_set_options_string@plt>:
   3dd10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd14:      	ldr	x17, [x16, #0xbc8]
   3dd18:      	add	x16, x16, #0xbc8
   3dd1c:      	br	x17

000000000003dd20 <av_dict_count@plt>:
   3dd20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd24:      	ldr	x17, [x16, #0xbd0]
   3dd28:      	add	x16, x16, #0xbd0
   3dd2c:      	br	x17

000000000003dd30 <avpriv_slicethread_create@plt>:
   3dd30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd34:      	ldr	x17, [x16, #0xbd8]
   3dd38:      	add	x16, x16, #0xbd8
   3dd3c:      	br	x17

000000000003dd40 <avpriv_slicethread_free@plt>:
   3dd40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd44:      	ldr	x17, [x16, #0xbe0]
   3dd48:      	add	x16, x16, #0xbe0
   3dd4c:      	br	x17

000000000003dd50 <avpriv_slicethread_execute@plt>:
   3dd50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd54:      	ldr	x17, [x16, #0xbe8]
   3dd58:      	add	x16, x16, #0xbe8
   3dd5c:      	br	x17

000000000003dd60 <ff_scale_adjust_dimensions@plt>:
   3dd60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd64:      	ldr	x17, [x16, #0xbf0]
   3dd68:      	add	x16, x16, #0xbf0
   3dd6c:      	br	x17

000000000003dd70 <av_expr_parse_and_eval@plt>:
   3dd70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd74:      	ldr	x17, [x16, #0xbf8]
   3dd78:      	add	x16, x16, #0xbf8
   3dd7c:      	br	x17

000000000003dd80 <av_find_input_format@plt>:
   3dd80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd84:      	ldr	x17, [x16, #0xc00]
   3dd88:      	add	x16, x16, #0xc00
   3dd8c:      	br	x17

000000000003dd90 <avformat_open_input@plt>:
   3dd90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dd94:      	ldr	x17, [x16, #0xc08]
   3dd98:      	add	x16, x16, #0xc08
   3dd9c:      	br	x17

000000000003dda0 <avformat_find_stream_info@plt>:
   3dda0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dda4:      	ldr	x17, [x16, #0xc10]
   3dda8:      	add	x16, x16, #0xc10
   3ddac:      	br	x17

000000000003ddb0 <av_seek_frame@plt>:
   3ddb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ddb4:      	ldr	x17, [x16, #0xc18]
   3ddb8:      	add	x16, x16, #0xc18
   3ddbc:      	br	x17

000000000003ddc0 <av_packet_alloc@plt>:
   3ddc0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ddc4:      	ldr	x17, [x16, #0xc20]
   3ddc8:      	add	x16, x16, #0xc20
   3ddcc:      	br	x17

000000000003ddd0 <av_strtok@plt>:
   3ddd0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ddd4:      	ldr	x17, [x16, #0xc28]
   3ddd8:      	add	x16, x16, #0xc28
   3dddc:      	br	x17

000000000003dde0 <sscanf@plt>:
   3dde0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dde4:      	ldr	x17, [x16, #0xc30]
   3dde8:      	add	x16, x16, #0xc30
   3ddec:      	br	x17

000000000003ddf0 <av_find_best_stream@plt>:
   3ddf0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ddf4:      	ldr	x17, [x16, #0xc38]
   3ddf8:      	add	x16, x16, #0xc38
   3ddfc:      	br	x17

000000000003de00 <avformat_match_stream_specifier@plt>:
   3de00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de04:      	ldr	x17, [x16, #0xc40]
   3de08:      	add	x16, x16, #0xc40
   3de0c:      	br	x17

000000000003de10 <av_asprintf@plt>:
   3de10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de14:      	ldr	x17, [x16, #0xc48]
   3de18:      	add	x16, x16, #0xc48
   3de1c:      	br	x17

000000000003de20 <av_channel_layout_default@plt>:
   3de20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de24:      	ldr	x17, [x16, #0xc50]
   3de28:      	add	x16, x16, #0xc50
   3de2c:      	br	x17

000000000003de30 <avcodec_find_decoder@plt>:
   3de30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de34:      	ldr	x17, [x16, #0xc58]
   3de38:      	add	x16, x16, #0xc58
   3de3c:      	br	x17

000000000003de40 <avcodec_alloc_context3@plt>:
   3de40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de44:      	ldr	x17, [x16, #0xc60]
   3de48:      	add	x16, x16, #0xc60
   3de4c:      	br	x17

000000000003de50 <avcodec_parameters_to_context@plt>:
   3de50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de54:      	ldr	x17, [x16, #0xc68]
   3de58:      	add	x16, x16, #0xc68
   3de5c:      	br	x17

000000000003de60 <avcodec_open2@plt>:
   3de60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de64:      	ldr	x17, [x16, #0xc70]
   3de68:      	add	x16, x16, #0xc70
   3de6c:      	br	x17

000000000003de70 <avcodec_free_context@plt>:
   3de70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de74:      	ldr	x17, [x16, #0xc78]
   3de78:      	add	x16, x16, #0xc78
   3de7c:      	br	x17

000000000003de80 <av_packet_free@plt>:
   3de80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de84:      	ldr	x17, [x16, #0xc80]
   3de88:      	add	x16, x16, #0xc80
   3de8c:      	br	x17

000000000003de90 <avformat_close_input@plt>:
   3de90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3de94:      	ldr	x17, [x16, #0xc88]
   3de98:      	add	x16, x16, #0xc88
   3de9c:      	br	x17

000000000003dea0 <avcodec_flush_buffers@plt>:
   3dea0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dea4:      	ldr	x17, [x16, #0xc90]
   3dea8:      	add	x16, x16, #0xc90
   3deac:      	br	x17

000000000003deb0 <av_read_frame@plt>:
   3deb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3deb4:      	ldr	x17, [x16, #0xc98]
   3deb8:      	add	x16, x16, #0xc98
   3debc:      	br	x17

000000000003dec0 <av_packet_unref@plt>:
   3dec0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dec4:      	ldr	x17, [x16, #0xca0]
   3dec8:      	add	x16, x16, #0xca0
   3decc:      	br	x17

000000000003ded0 <avcodec_send_packet@plt>:
   3ded0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3ded4:      	ldr	x17, [x16, #0xca8]
   3ded8:      	add	x16, x16, #0xca8
   3dedc:      	br	x17

000000000003dee0 <avcodec_default_get_buffer2@plt>:
   3dee0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dee4:      	ldr	x17, [x16, #0xcb0]
   3dee8:      	add	x16, x16, #0xcb0
   3deec:      	br	x17

000000000003def0 <avcodec_align_dimensions2@plt>:
   3def0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3def4:      	ldr	x17, [x16, #0xcb8]
   3def8:      	add	x16, x16, #0xcb8
   3defc:      	br	x17

000000000003df00 <ff_default_get_video_buffer@plt>:
   3df00:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df04:      	ldr	x17, [x16, #0xcc0]
   3df08:      	add	x16, x16, #0xcc0
   3df0c:      	br	x17

000000000003df10 <av_frame_unref@plt>:
   3df10:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df14:      	ldr	x17, [x16, #0xcc8]
   3df18:      	add	x16, x16, #0xcc8
   3df1c:      	br	x17

000000000003df20 <avcodec_receive_frame@plt>:
   3df20:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df24:      	ldr	x17, [x16, #0xcd0]
   3df28:      	add	x16, x16, #0xcd0
   3df2c:      	br	x17

000000000003df30 <av_rescale_q_rnd@plt>:
   3df30:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df34:      	ldr	x17, [x16, #0xcd8]
   3df38:      	add	x16, x16, #0xcd8
   3df3c:      	br	x17

000000000003df40 <av_image_fill_max_pixsteps@plt>:
   3df40:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df44:      	ldr	x17, [x16, #0xce0]
   3df48:      	add	x16, x16, #0xce0
   3df4c:      	br	x17

000000000003df50 <av_mul_q@plt>:
   3df50:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df54:      	ldr	x17, [x16, #0xce8]
   3df58:      	add	x16, x16, #0xce8
   3df5c:      	br	x17

000000000003df60 <av_reduce@plt>:
   3df60:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df64:      	ldr	x17, [x16, #0xcf0]
   3df68:      	add	x16, x16, #0xcf0
   3df6c:      	br	x17

000000000003df70 <av_get_pix_fmt@plt>:
   3df70:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df74:      	ldr	x17, [x16, #0xcf8]
   3df78:      	add	x16, x16, #0xcf8
   3df7c:      	br	x17

000000000003df80 <strtol@plt>:
   3df80:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df84:      	ldr	x17, [x16, #0xd00]
   3df88:      	add	x16, x16, #0xd00
   3df8c:      	br	x17

000000000003df90 <av_color_space_from_name@plt>:
   3df90:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3df94:      	ldr	x17, [x16, #0xd08]
   3df98:      	add	x16, x16, #0xd08
   3df9c:      	br	x17

000000000003dfa0 <av_color_range_from_name@plt>:
   3dfa0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dfa4:      	ldr	x17, [x16, #0xd10]
   3dfa8:      	add	x16, x16, #0xd10
   3dfac:      	br	x17

000000000003dfb0 <ff_null_get_video_buffer@plt>:
   3dfb0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dfb4:      	ldr	x17, [x16, #0xd18]
   3dfb8:      	add	x16, x16, #0xd18
   3dfbc:      	br	x17

000000000003dfc0 <av_pix_fmt_count_planes@plt>:
   3dfc0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dfc4:      	ldr	x17, [x16, #0xd20]
   3dfc8:      	add	x16, x16, #0xd20
   3dfcc:      	br	x17

000000000003dfd0 <av_frame_get_plane_buffer@plt>:
   3dfd0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dfd4:      	ldr	x17, [x16, #0xd28]
   3dfd8:      	add	x16, x16, #0xd28
   3dfdc:      	br	x17

000000000003dfe0 <av_div_q@plt>:
   3dfe0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dfe4:      	ldr	x17, [x16, #0xd30]
   3dfe8:      	add	x16, x16, #0xd30
   3dfec:      	br	x17

000000000003dff0 <sws_alloc_context@plt>:
   3dff0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3dff4:      	ldr	x17, [x16, #0xd38]
   3dff8:      	add	x16, x16, #0xd38
   3dffc:      	br	x17

000000000003e000 <av_parse_video_size@plt>:
   3e000:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e004:      	ldr	x17, [x16, #0xd40]
   3e008:      	add	x16, x16, #0xd40
   3e00c:      	br	x17

000000000003e010 <av_opt_set_double@plt>:
   3e010:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e014:      	ldr	x17, [x16, #0xd48]
   3e018:      	add	x16, x16, #0xd48
   3e01c:      	br	x17

000000000003e020 <sws_freeContext@plt>:
   3e020:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e024:      	ldr	x17, [x16, #0xd50]
   3e028:      	add	x16, x16, #0xd50
   3e02c:      	br	x17

000000000003e030 <av_pix_fmt_desc_next@plt>:
   3e030:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e034:      	ldr	x17, [x16, #0xd58]
   3e038:      	add	x16, x16, #0xd58
   3e03c:      	br	x17

000000000003e040 <av_pix_fmt_desc_get_id@plt>:
   3e040:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e044:      	ldr	x17, [x16, #0xd60]
   3e048:      	add	x16, x16, #0xd60
   3e04c:      	br	x17

000000000003e050 <sws_isSupportedInput@plt>:
   3e050:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e054:      	ldr	x17, [x16, #0xd68]
   3e058:      	add	x16, x16, #0xd68
   3e05c:      	br	x17

000000000003e060 <sws_isSupportedEndiannessConversion@plt>:
   3e060:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e064:      	ldr	x17, [x16, #0xd70]
   3e068:      	add	x16, x16, #0xd70
   3e06c:      	br	x17

000000000003e070 <sws_isSupportedOutput@plt>:
   3e070:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e074:      	ldr	x17, [x16, #0xd78]
   3e078:      	add	x16, x16, #0xd78
   3e07c:      	br	x17

000000000003e080 <av_opt_copy@plt>:
   3e080:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e084:      	ldr	x17, [x16, #0xd80]
   3e088:      	add	x16, x16, #0xd80
   3e08c:      	br	x17

000000000003e090 <sws_init_context@plt>:
   3e090:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e094:      	ldr	x17, [x16, #0xd88]
   3e098:      	add	x16, x16, #0xd88
   3e09c:      	br	x17

000000000003e0a0 <sws_getColorspaceDetails@plt>:
   3e0a0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e0a4:      	ldr	x17, [x16, #0xd90]
   3e0a8:      	add	x16, x16, #0xd90
   3e0ac:      	br	x17

000000000003e0b0 <sws_getCoefficients@plt>:
   3e0b0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e0b4:      	ldr	x17, [x16, #0xd98]
   3e0b8:      	add	x16, x16, #0xd98
   3e0bc:      	br	x17

000000000003e0c0 <sws_setColorspaceDetails@plt>:
   3e0c0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e0c4:      	ldr	x17, [x16, #0xda0]
   3e0c8:      	add	x16, x16, #0xda0
   3e0cc:      	br	x17

000000000003e0d0 <av_opt_get@plt>:
   3e0d0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e0d4:      	ldr	x17, [x16, #0xda8]
   3e0d8:      	add	x16, x16, #0xda8
   3e0dc:      	br	x17

000000000003e0e0 <av_chroma_location_enum_to_pos@plt>:
   3e0e0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e0e4:      	ldr	x17, [x16, #0xdb0]
   3e0e8:      	add	x16, x16, #0xdb0
   3e0ec:      	br	x17

000000000003e0f0 <av_expr_count_vars@plt>:
   3e0f0:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e0f4:      	ldr	x17, [x16, #0xdb8]
   3e0f8:      	add	x16, x16, #0xdb8
   3e0fc:      	br	x17

000000000003e100 <sws_scale_frame@plt>:
   3e100:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e104:      	ldr	x17, [x16, #0xdc0]
   3e108:      	add	x16, x16, #0xdc0
   3e10c:      	br	x17

000000000003e110 <sws_get_class@plt>:
   3e110:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e114:      	ldr	x17, [x16, #0xdc8]
   3e118:      	add	x16, x16, #0xdc8
   3e11c:      	br	x17

000000000003e120 <ff_default_get_video_buffer2@plt>:
   3e120:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e124:      	ldr	x17, [x16, #0xdd0]
   3e128:      	add	x16, x16, #0xdd0
   3e12c:      	br	x17

000000000003e130 <av_hwframe_get_buffer@plt>:
   3e130:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e134:      	ldr	x17, [x16, #0xdd8]
   3e138:      	add	x16, x16, #0xdd8
   3e13c:      	br	x17

000000000003e140 <av_image_check_size@plt>:
   3e140:      	adrp	x16, 0x48000 <ff_vsrc_nullsrc+0x338>
   3e144:      	ldr	x17, [x16, #0xde0]
   3e148:      	add	x16, x16, #0xde0
   3e14c:      	br	x17
