// EXPORTED & PLT DISASSEMBLY FOR libaicodec.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libaicodec.so (SHA-256: F957A5B290991053F65943356816E837AE5A9D996FA0B2809FC89F680FC8A3CC)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 3077, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libaicodec.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000001f45a0 <.plt>:
  1f45a0:      	stp	x16, x30, [sp, #-0x10]!
  1f45a4:      	adrp	x16, 0x203000
  1f45a8:      	ldr	x17, [x16, #0x488]
  1f45ac:      	add	x16, x16, #0x488
  1f45b0:      	br	x17
  1f45b4:      	nop
  1f45b8:      	nop
  1f45bc:      	nop

00000000001f45c0 <__cxa_finalize@plt>:
  1f45c0:      	adrp	x16, 0x203000
  1f45c4:      	ldr	x17, [x16, #0x490]
  1f45c8:      	add	x16, x16, #0x490
  1f45cc:      	br	x17

00000000001f45d0 <__cxa_atexit@plt>:
  1f45d0:      	adrp	x16, 0x203000
  1f45d4:      	ldr	x17, [x16, #0x498]
  1f45d8:      	add	x16, x16, #0x498
  1f45dc:      	br	x17

00000000001f45e0 <pthread_self@plt>:
  1f45e0:      	adrp	x16, 0x203000
  1f45e4:      	ldr	x17, [x16, #0x4a0]
  1f45e8:      	add	x16, x16, #0x4a0
  1f45ec:      	br	x17

00000000001f45f0 <__android_log_print@plt>:
  1f45f0:      	adrp	x16, 0x203000
  1f45f4:      	ldr	x17, [x16, #0x4a8]
  1f45f8:      	add	x16, x16, #0x4a8
  1f45fc:      	br	x17

00000000001f4600 <_ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz@plt>:
  1f4600:      	adrp	x16, 0x203000
  1f4604:      	ldr	x17, [x16, #0x4b0]
  1f4608:      	add	x16, x16, #0x4b0
  1f460c:      	br	x17

00000000001f4610 <_ZN7MMCodec16ExportStreamBaseD2Ev@plt>:
  1f4610:      	adrp	x16, 0x203000
  1f4614:      	ldr	x17, [x16, #0x4b8]
  1f4618:      	add	x16, x16, #0x4b8
  1f461c:      	br	x17

00000000001f4620 <__cxa_begin_catch@plt>:
  1f4620:      	adrp	x16, 0x203000
  1f4624:      	ldr	x17, [x16, #0x4c0]
  1f4628:      	add	x16, x16, #0x4c0
  1f462c:      	br	x17

00000000001f4630 <_ZSt9terminatev@plt>:
  1f4630:      	adrp	x16, 0x203000
  1f4634:      	ldr	x17, [x16, #0x4c8]
  1f4638:      	add	x16, x16, #0x4c8
  1f463c:      	br	x17

00000000001f4640 <_ZN7MMCodec11AudioStreamD1Ev@plt>:
  1f4640:      	adrp	x16, 0x203000
  1f4644:      	ldr	x17, [x16, #0x4d0]
  1f4648:      	add	x16, x16, #0x4d0
  1f464c:      	br	x17

00000000001f4650 <_ZdlPv@plt>:
  1f4650:      	adrp	x16, 0x203000
  1f4654:      	ldr	x17, [x16, #0x4d8]
  1f4658:      	add	x16, x16, #0x4d8
  1f465c:      	br	x17

00000000001f4660 <_ZN7MMCodec10MediaParam20readOutAudioSettingsEPNS_12AudioParam_tE@plt>:
  1f4660:      	adrp	x16, 0x203000
  1f4664:      	ldr	x17, [x16, #0x4e0]
  1f4668:      	add	x16, x16, #0x4e0
  1f466c:      	br	x17

00000000001f4670 <_ZN7MMCodec10MediaParam19readInAudioSettingsEPNS_12AudioParam_tE@plt>:
  1f4670:      	adrp	x16, 0x203000
  1f4674:      	ldr	x17, [x16, #0x4e8]
  1f4678:      	add	x16, x16, #0x4e8
  1f467c:      	br	x17

00000000001f4680 <avcodec_find_encoder_by_name@plt>:
  1f4680:      	adrp	x16, 0x203000
  1f4684:      	ldr	x17, [x16, #0x4f0]
  1f4688:      	add	x16, x16, #0x4f0
  1f468c:      	br	x17

00000000001f4690 <avcodec_find_encoder@plt>:
  1f4690:      	adrp	x16, 0x203000
  1f4694:      	ldr	x17, [x16, #0x4f8]
  1f4698:      	add	x16, x16, #0x4f8
  1f469c:      	br	x17

00000000001f46a0 <avcodec_get_name@plt>:
  1f46a0:      	adrp	x16, 0x203000
  1f46a4:      	ldr	x17, [x16, #0x500]
  1f46a8:      	add	x16, x16, #0x500
  1f46ac:      	br	x17

00000000001f46b0 <avformat_new_stream@plt>:
  1f46b0:      	adrp	x16, 0x203000
  1f46b4:      	ldr	x17, [x16, #0x508]
  1f46b8:      	add	x16, x16, #0x508
  1f46bc:      	br	x17

00000000001f46c0 <av_dict_set@plt>:
  1f46c0:      	adrp	x16, 0x203000
  1f46c4:      	ldr	x17, [x16, #0x510]
  1f46c8:      	add	x16, x16, #0x510
  1f46cc:      	br	x17

00000000001f46d0 <_ZN7MMCodec12makeErrorStrEi@plt>:
  1f46d0:      	adrp	x16, 0x203000
  1f46d4:      	ldr	x17, [x16, #0x518]
  1f46d8:      	add	x16, x16, #0x518
  1f46dc:      	br	x17

00000000001f46e0 <avcodec_alloc_context3@plt>:
  1f46e0:      	adrp	x16, 0x203000
  1f46e4:      	ldr	x17, [x16, #0x520]
  1f46e8:      	add	x16, x16, #0x520
  1f46ec:      	br	x17

00000000001f46f0 <av_channel_layout_uninit@plt>:
  1f46f0:      	adrp	x16, 0x203000
  1f46f4:      	ldr	x17, [x16, #0x528]
  1f46f8:      	add	x16, x16, #0x528
  1f46fc:      	br	x17

00000000001f4700 <av_channel_layout_default@plt>:
  1f4700:      	adrp	x16, 0x203000
  1f4704:      	ldr	x17, [x16, #0x530]
  1f4708:      	add	x16, x16, #0x530
  1f470c:      	br	x17

00000000001f4710 <_ZN7MMCodec19getAudioOuterFormatE14AVSampleFormat@plt>:
  1f4710:      	adrp	x16, 0x203000
  1f4714:      	ldr	x17, [x16, #0x538]
  1f4718:      	add	x16, x16, #0x538
  1f471c:      	br	x17

00000000001f4720 <avcodec_open2@plt>:
  1f4720:      	adrp	x16, 0x203000
  1f4724:      	ldr	x17, [x16, #0x540]
  1f4728:      	add	x16, x16, #0x540
  1f472c:      	br	x17

00000000001f4730 <avcodec_parameters_from_context@plt>:
  1f4730:      	adrp	x16, 0x203000
  1f4734:      	ldr	x17, [x16, #0x548]
  1f4738:      	add	x16, x16, #0x548
  1f473c:      	br	x17

00000000001f4740 <_ZN7MMCodec19getAudioInnerFormatENS_19AUDIO_SAMPLE_FORMATE@plt>:
  1f4740:      	adrp	x16, 0x203000
  1f4744:      	ldr	x17, [x16, #0x550]
  1f4748:      	add	x16, x16, #0x550
  1f474c:      	br	x17

00000000001f4750 <_ZN7MMCodec8initFifoEPP11AVAudioFifo14AVSampleFormatii@plt>:
  1f4750:      	adrp	x16, 0x203000
  1f4754:      	ldr	x17, [x16, #0x558]
  1f4758:      	add	x16, x16, #0x558
  1f475c:      	br	x17

00000000001f4760 <_Znwm@plt>:
  1f4760:      	adrp	x16, 0x203000
  1f4764:      	ldr	x17, [x16, #0x560]
  1f4768:      	add	x16, x16, #0x560
  1f476c:      	br	x17

00000000001f4770 <_ZN7MMCodec14FFmpegResampleC1Ev@plt>:
  1f4770:      	adrp	x16, 0x203000
  1f4774:      	ldr	x17, [x16, #0x568]
  1f4778:      	add	x16, x16, #0x568
  1f477c:      	br	x17

00000000001f4780 <_ZN7MMCodec14FFmpegResample20setTargetAudioParamsE14AVSampleFormatii@plt>:
  1f4780:      	adrp	x16, 0x203000
  1f4784:      	ldr	x17, [x16, #0x570]
  1f4788:      	add	x16, x16, #0x570
  1f478c:      	br	x17

00000000001f4790 <av_get_sample_fmt_name@plt>:
  1f4790:      	adrp	x16, 0x203000
  1f4794:      	ldr	x17, [x16, #0x578]
  1f4798:      	add	x16, x16, #0x578
  1f479c:      	br	x17

00000000001f47a0 <avcodec_close@plt>:
  1f47a0:      	adrp	x16, 0x203000
  1f47a4:      	ldr	x17, [x16, #0x580]
  1f47a8:      	add	x16, x16, #0x580
  1f47ac:      	br	x17

00000000001f47b0 <avcodec_free_context@plt>:
  1f47b0:      	adrp	x16, 0x203000
  1f47b4:      	ldr	x17, [x16, #0x588]
  1f47b8:      	add	x16, x16, #0x588
  1f47bc:      	br	x17

00000000001f47c0 <_ZN7MMCodec13ThreadContext7isValidEv@plt>:
  1f47c0:      	adrp	x16, 0x203000
  1f47c4:      	ldr	x17, [x16, #0x590]
  1f47c8:      	add	x16, x16, #0x590
  1f47cc:      	br	x17

00000000001f47d0 <av_sample_fmt_is_planar@plt>:
  1f47d0:      	adrp	x16, 0x203000
  1f47d4:      	ldr	x17, [x16, #0x598]
  1f47d8:      	add	x16, x16, #0x598
  1f47dc:      	br	x17

00000000001f47e0 <av_get_bytes_per_sample@plt>:
  1f47e0:      	adrp	x16, 0x203000
  1f47e4:      	ldr	x17, [x16, #0x5a0]
  1f47e8:      	add	x16, x16, #0x5a0
  1f47ec:      	br	x17

00000000001f47f0 <_ZN7MMCodec14FFmpegResample20getNextOutBufferSizeEii@plt>:
  1f47f0:      	adrp	x16, 0x203000
  1f47f4:      	ldr	x17, [x16, #0x5a8]
  1f47f8:      	add	x16, x16, #0x5a8
  1f47fc:      	br	x17

00000000001f4800 <_ZN7MMCodec8MMBuffer7reallocEm@plt>:
  1f4800:      	adrp	x16, 0x203000
  1f4804:      	ldr	x17, [x16, #0x5b0]
  1f4808:      	add	x16, x16, #0x5b0
  1f480c:      	br	x17

00000000001f4810 <_ZN7MMCodec11initAVFrameEP7AVFrame@plt>:
  1f4810:      	adrp	x16, 0x203000
  1f4814:      	ldr	x17, [x16, #0x5b8]
  1f4818:      	add	x16, x16, #0x5b8
  1f481c:      	br	x17

00000000001f4820 <_ZN7MMCodec14FFmpegResample8resampleEP7AVFramePhRmi@plt>:
  1f4820:      	adrp	x16, 0x203000
  1f4824:      	ldr	x17, [x16, #0x5c0]
  1f4828:      	add	x16, x16, #0x5c0
  1f482c:      	br	x17

00000000001f4830 <av_samples_get_buffer_size@plt>:
  1f4830:      	adrp	x16, 0x203000
  1f4834:      	ldr	x17, [x16, #0x5c8]
  1f4838:      	add	x16, x16, #0x5c8
  1f483c:      	br	x17

00000000001f4840 <av_samples_fill_arrays@plt>:
  1f4840:      	adrp	x16, 0x203000
  1f4844:      	ldr	x17, [x16, #0x5d0]
  1f4848:      	add	x16, x16, #0x5d0
  1f484c:      	br	x17

00000000001f4850 <_ZN7MMCodec13ThreadContext14getThreadStateEv@plt>:
  1f4850:      	adrp	x16, 0x203000
  1f4854:      	ldr	x17, [x16, #0x5d8]
  1f4858:      	add	x16, x16, #0x5d8
  1f485c:      	br	x17

00000000001f4860 <_ZN7MMCodec16addSamplesToFifoEP11AVAudioFifoPPhi@plt>:
  1f4860:      	adrp	x16, 0x203000
  1f4864:      	ldr	x17, [x16, #0x5e0]
  1f4868:      	add	x16, x16, #0x5e0
  1f486c:      	br	x17

00000000001f4870 <_ZN7MMCodec11AudioStream26_writeFIFODataToFrameQueueEb@plt>:
  1f4870:      	adrp	x16, 0x203000
  1f4874:      	ldr	x17, [x16, #0x5e8]
  1f4878:      	add	x16, x16, #0x5e8
  1f487c:      	br	x17

00000000001f4880 <_ZN7MMCodec8MMBufferC1Em@plt>:
  1f4880:      	adrp	x16, 0x203000
  1f4884:      	ldr	x17, [x16, #0x5f0]
  1f4888:      	add	x16, x16, #0x5f0
  1f488c:      	br	x17

00000000001f4890 <__stack_chk_fail@plt>:
  1f4890:      	adrp	x16, 0x203000
  1f4894:      	ldr	x17, [x16, #0x5f8]
  1f4898:      	add	x16, x16, #0x5f8
  1f489c:      	br	x17

00000000001f48a0 <av_audio_fifo_size@plt>:
  1f48a0:      	adrp	x16, 0x203000
  1f48a4:      	ldr	x17, [x16, #0x600]
  1f48a8:      	add	x16, x16, #0x600
  1f48ac:      	br	x17

00000000001f48b0 <_ZN7MMCodec14AICodecContext14acquireAVFrameEv@plt>:
  1f48b0:      	adrp	x16, 0x203000
  1f48b4:      	ldr	x17, [x16, #0x608]
  1f48b8:      	add	x16, x16, #0x608
  1f48bc:      	br	x17

00000000001f48c0 <av_buffer_pool_init@plt>:
  1f48c0:      	adrp	x16, 0x203000
  1f48c4:      	ldr	x17, [x16, #0x610]
  1f48c8:      	add	x16, x16, #0x610
  1f48cc:      	br	x17

00000000001f48d0 <av_buffer_pool_get@plt>:
  1f48d0:      	adrp	x16, 0x203000
  1f48d4:      	ldr	x17, [x16, #0x618]
  1f48d8:      	add	x16, x16, #0x618
  1f48dc:      	br	x17

00000000001f48e0 <av_audio_fifo_read@plt>:
  1f48e0:      	adrp	x16, 0x203000
  1f48e4:      	ldr	x17, [x16, #0x620]
  1f48e8:      	add	x16, x16, #0x620
  1f48ec:      	br	x17

00000000001f48f0 <_ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE3putERKS4_@plt>:
  1f48f0:      	adrp	x16, 0x203000
  1f48f4:      	ldr	x17, [x16, #0x628]
  1f48f8:      	add	x16, x16, #0x628
  1f48fc:      	br	x17

00000000001f4900 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  1f4900:      	adrp	x16, 0x203000
  1f4904:      	ldr	x17, [x16, #0x630]
  1f4908:      	add	x16, x16, #0x630
  1f490c:      	br	x17

00000000001f4910 <_ZN7MMCodec14AICodecContext14releaseAVFrameEP7AVFrame@plt>:
  1f4910:      	adrp	x16, 0x203000
  1f4914:      	ldr	x17, [x16, #0x638]
  1f4918:      	add	x16, x16, #0x638
  1f491c:      	br	x17

00000000001f4920 <__cxa_rethrow@plt>:
  1f4920:      	adrp	x16, 0x203000
  1f4924:      	ldr	x17, [x16, #0x640]
  1f4928:      	add	x16, x16, #0x640
  1f492c:      	br	x17

00000000001f4930 <__cxa_end_catch@plt>:
  1f4930:      	adrp	x16, 0x203000
  1f4934:      	ldr	x17, [x16, #0x648]
  1f4938:      	add	x16, x16, #0x648
  1f493c:      	br	x17

00000000001f4940 <_ZNSt6__ndk15mutex4lockEv@plt>:
  1f4940:      	adrp	x16, 0x203000
  1f4944:      	ldr	x17, [x16, #0x650]
  1f4948:      	add	x16, x16, #0x650
  1f494c:      	br	x17

00000000001f4950 <_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE@plt>:
  1f4950:      	adrp	x16, 0x203000
  1f4954:      	ldr	x17, [x16, #0x658]
  1f4958:      	add	x16, x16, #0x658
  1f495c:      	br	x17

00000000001f4960 <_ZNSt6__ndk15mutex6unlockEv@plt>:
  1f4960:      	adrp	x16, 0x203000
  1f4964:      	ldr	x17, [x16, #0x660]
  1f4968:      	add	x16, x16, #0x660
  1f496c:      	br	x17

00000000001f4970 <_ZNSt6__ndk118condition_variable10notify_oneEv@plt>:
  1f4970:      	adrp	x16, 0x203000
  1f4974:      	ldr	x17, [x16, #0x668]
  1f4978:      	add	x16, x16, #0x668
  1f497c:      	br	x17

00000000001f4980 <_ZNSt6__ndk118condition_variable10notify_allEv@plt>:
  1f4980:      	adrp	x16, 0x203000
  1f4984:      	ldr	x17, [x16, #0x670]
  1f4988:      	add	x16, x16, #0x670
  1f498c:      	br	x17

00000000001f4990 <av_audio_fifo_free@plt>:
  1f4990:      	adrp	x16, 0x203000
  1f4994:      	ldr	x17, [x16, #0x678]
  1f4998:      	add	x16, x16, #0x678
  1f499c:      	br	x17

00000000001f49a0 <av_buffer_pool_uninit@plt>:
  1f49a0:      	adrp	x16, 0x203000
  1f49a4:      	ldr	x17, [x16, #0x680]
  1f49a8:      	add	x16, x16, #0x680
  1f49ac:      	br	x17

00000000001f49b0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JNS_4pairIS7_S7_EEEEENSK_INS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEERKT_DpOT0_@plt>:
  1f49b0:      	adrp	x16, 0x203000
  1f49b4:      	ldr	x17, [x16, #0x688]
  1f49b8:      	add	x16, x16, #0x688
  1f49bc:      	br	x17

00000000001f49c0 <_ZNSt6__ndk14pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_ED2Ev@plt>:
  1f49c0:      	adrp	x16, 0x203000
  1f49c4:      	ldr	x17, [x16, #0x690]
  1f49c8:      	add	x16, x16, #0x690
  1f49cc:      	br	x17

00000000001f49d0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE14__assign_multiINS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEEEvT_SM_@plt>:
  1f49d0:      	adrp	x16, 0x203000
  1f49d4:      	ldr	x17, [x16, #0x698]
  1f49d8:      	add	x16, x16, #0x698
  1f49dc:      	br	x17

00000000001f49e0 <_ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEED2Ev@plt>:
  1f49e0:      	adrp	x16, 0x203000
  1f49e4:      	ldr	x17, [x16, #0x6a0]
  1f49e8:      	add	x16, x16, #0x6a0
  1f49ec:      	br	x17

00000000001f49f0 <_ZNSt6__ndk118condition_variableD1Ev@plt>:
  1f49f0:      	adrp	x16, 0x203000
  1f49f4:      	ldr	x17, [x16, #0x6a8]
  1f49f8:      	add	x16, x16, #0x6a8
  1f49fc:      	br	x17

00000000001f4a00 <_ZNSt6__ndk15mutexD1Ev@plt>:
  1f4a00:      	adrp	x16, 0x203000
  1f4a04:      	ldr	x17, [x16, #0x6b0]
  1f4a08:      	add	x16, x16, #0x6b0
  1f4a0c:      	br	x17

00000000001f4a10 <_ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEED2Ev@plt>:
  1f4a10:      	adrp	x16, 0x203000
  1f4a14:      	ldr	x17, [x16, #0x6b8]
  1f4a18:      	add	x16, x16, #0x6b8
  1f4a1c:      	br	x17

00000000001f4a20 <memcmp@plt>:
  1f4a20:      	adrp	x16, 0x203000
  1f4a24:      	ldr	x17, [x16, #0x6c0]
  1f4a28:      	add	x16, x16, #0x6c0
  1f4a2c:      	br	x17

00000000001f4a30 <_ZNSt6__ndk112__next_primeEm@plt>:
  1f4a30:      	adrp	x16, 0x203000
  1f4a34:      	ldr	x17, [x16, #0x6c8]
  1f4a38:      	add	x16, x16, #0x6c8
  1f4a3c:      	br	x17

00000000001f4a40 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE11__do_rehashILb1EEEvm@plt>:
  1f4a40:      	adrp	x16, 0x203000
  1f4a44:      	ldr	x17, [x16, #0x6d0]
  1f4a48:      	add	x16, x16, #0x6d0
  1f4a4c:      	br	x17

00000000001f4a50 <__cxa_allocate_exception@plt>:
  1f4a50:      	adrp	x16, 0x203000
  1f4a54:      	ldr	x17, [x16, #0x6d8]
  1f4a58:      	add	x16, x16, #0x6d8
  1f4a5c:      	br	x17

00000000001f4a60 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  1f4a60:      	adrp	x16, 0x203000
  1f4a64:      	ldr	x17, [x16, #0x6e0]
  1f4a68:      	add	x16, x16, #0x6e0
  1f4a6c:      	br	x17

00000000001f4a70 <__cxa_throw@plt>:
  1f4a70:      	adrp	x16, 0x203000
  1f4a74:      	ldr	x17, [x16, #0x6e8]
  1f4a78:      	add	x16, x16, #0x6e8
  1f4a7c:      	br	x17

00000000001f4a80 <memmove@plt>:
  1f4a80:      	adrp	x16, 0x203000
  1f4a84:      	ldr	x17, [x16, #0x6f0]
  1f4a88:      	add	x16, x16, #0x6f0
  1f4a8c:      	br	x17

00000000001f4a90 <__cxa_free_exception@plt>:
  1f4a90:      	adrp	x16, 0x203000
  1f4a94:      	ldr	x17, [x16, #0x6f8]
  1f4a98:      	add	x16, x16, #0x6f8
  1f4a9c:      	br	x17

00000000001f4aa0 <_ZNSt11logic_errorC2EPKc@plt>:
  1f4aa0:      	adrp	x16, 0x203000
  1f4aa4:      	ldr	x17, [x16, #0x700]
  1f4aa8:      	add	x16, x16, #0x700
  1f4aac:      	br	x17

00000000001f4ab0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  1f4ab0:      	adrp	x16, 0x203000
  1f4ab4:      	ldr	x17, [x16, #0x708]
  1f4ab8:      	add	x16, x16, #0x708
  1f4abc:      	br	x17

00000000001f4ac0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE15__emplace_multiIJRKNS_4pairIKS7_S7_EEEEENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEDpOT_@plt>:
  1f4ac0:      	adrp	x16, 0x203000
  1f4ac4:      	ldr	x17, [x16, #0x710]
  1f4ac8:      	add	x16, x16, #0x710
  1f4acc:      	br	x17

00000000001f4ad0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE16__construct_nodeIJRKNS_4pairIKS7_S7_EEEEENS_10unique_ptrINS_11__tree_nodeIS8_PvEENS_22__tree_node_destructorINS5_ISO_EEEEEEDpOT_@plt>:
  1f4ad0:      	adrp	x16, 0x203000
  1f4ad4:      	ldr	x17, [x16, #0x718]
  1f4ad8:      	add	x16, x16, #0x718
  1f4adc:      	br	x17

00000000001f4ae0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  1f4ae0:      	adrp	x16, 0x203000
  1f4ae4:      	ldr	x17, [x16, #0x720]
  1f4ae8:      	add	x16, x16, #0x720
  1f4aec:      	br	x17

00000000001f4af0 <_ZN7MMCodec11AudioStreamC1EPNS_14OutMediaHandleE@plt>:
  1f4af0:      	adrp	x16, 0x203000
  1f4af4:      	ldr	x17, [x16, #0x728]
  1f4af8:      	add	x16, x16, #0x728
  1f4afc:      	br	x17

00000000001f4b00 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA10_KcRA5_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4b00:      	adrp	x16, 0x203000
  1f4b04:      	ldr	x17, [x16, #0x730]
  1f4b08:      	add	x16, x16, #0x730
  1f4b0c:      	br	x17

00000000001f4b10 <strlen@plt>:
  1f4b10:      	adrp	x16, 0x203000
  1f4b14:      	ldr	x17, [x16, #0x738]
  1f4b18:      	add	x16, x16, #0x738
  1f4b1c:      	br	x17

00000000001f4b20 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA9_KcRA5_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4b20:      	adrp	x16, 0x203000
  1f4b24:      	ldr	x17, [x16, #0x740]
  1f4b28:      	add	x16, x16, #0x740
  1f4b2c:      	br	x17

00000000001f4b30 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA7_KcRA3_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4b30:      	adrp	x16, 0x203000
  1f4b34:      	ldr	x17, [x16, #0x748]
  1f4b38:      	add	x16, x16, #0x748
  1f4b3c:      	br	x17

00000000001f4b40 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA5_KcRA3_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4b40:      	adrp	x16, 0x203000
  1f4b44:      	ldr	x17, [x16, #0x750]
  1f4b48:      	add	x16, x16, #0x750
  1f4b4c:      	br	x17

00000000001f4b50 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA7_KcSC_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSE_OSF_@plt>:
  1f4b50:      	adrp	x16, 0x203000
  1f4b54:      	ldr	x17, [x16, #0x758]
  1f4b58:      	add	x16, x16, #0x758
  1f4b5c:      	br	x17

00000000001f4b60 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA8_KcRA5_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4b60:      	adrp	x16, 0x203000
  1f4b64:      	ldr	x17, [x16, #0x760]
  1f4b68:      	add	x16, x16, #0x760
  1f4b6c:      	br	x17

00000000001f4b70 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_ED2Ev@plt>:
  1f4b70:      	adrp	x16, 0x203000
  1f4b74:      	ldr	x17, [x16, #0x768]
  1f4b78:      	add	x16, x16, #0x768
  1f4b7c:      	br	x17

00000000001f4b80 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_SH_EElEERPNS_15__tree_end_nodeISJ_EESK_RKT_@plt>:
  1f4b80:      	adrp	x16, 0x203000
  1f4b84:      	ldr	x17, [x16, #0x770]
  1f4b88:      	add	x16, x16, #0x770
  1f4b8c:      	br	x17

00000000001f4b90 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA10_KcRA9_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4b90:      	adrp	x16, 0x203000
  1f4b94:      	ldr	x17, [x16, #0x778]
  1f4b98:      	add	x16, x16, #0x778
  1f4b9c:      	br	x17

00000000001f4ba0 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA9_KcSC_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSE_OSF_@plt>:
  1f4ba0:      	adrp	x16, 0x203000
  1f4ba4:      	ldr	x17, [x16, #0x780]
  1f4ba8:      	add	x16, x16, #0x780
  1f4bac:      	br	x17

00000000001f4bb0 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA5_KcSC_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSE_OSF_@plt>:
  1f4bb0:      	adrp	x16, 0x203000
  1f4bb4:      	ldr	x17, [x16, #0x788]
  1f4bb8:      	add	x16, x16, #0x788
  1f4bbc:      	br	x17

00000000001f4bc0 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA8_KcRA9_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4bc0:      	adrp	x16, 0x203000
  1f4bc4:      	ldr	x17, [x16, #0x790]
  1f4bc8:      	add	x16, x16, #0x790
  1f4bcc:      	br	x17

00000000001f4bd0 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA10_KcRA6_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4bd0:      	adrp	x16, 0x203000
  1f4bd4:      	ldr	x17, [x16, #0x798]
  1f4bd8:      	add	x16, x16, #0x798
  1f4bdc:      	br	x17

00000000001f4be0 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA9_KcRA6_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4be0:      	adrp	x16, 0x203000
  1f4be4:      	ldr	x17, [x16, #0x7a0]
  1f4be8:      	add	x16, x16, #0x7a0
  1f4bec:      	br	x17

00000000001f4bf0 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA7_KcRA6_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4bf0:      	adrp	x16, 0x203000
  1f4bf4:      	ldr	x17, [x16, #0x7a8]
  1f4bf8:      	add	x16, x16, #0x7a8
  1f4bfc:      	br	x17

00000000001f4c00 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA5_KcRA6_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4c00:      	adrp	x16, 0x203000
  1f4c04:      	ldr	x17, [x16, #0x7b0]
  1f4c08:      	add	x16, x16, #0x7b0
  1f4c0c:      	br	x17

00000000001f4c10 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA7_KcRA9_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4c10:      	adrp	x16, 0x203000
  1f4c14:      	ldr	x17, [x16, #0x7b8]
  1f4c18:      	add	x16, x16, #0x7b8
  1f4c1c:      	br	x17

00000000001f4c20 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA5_KcRA8_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4c20:      	adrp	x16, 0x203000
  1f4c24:      	ldr	x17, [x16, #0x7c0]
  1f4c28:      	add	x16, x16, #0x7c0
  1f4c2c:      	br	x17

00000000001f4c30 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA7_KcRA8_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4c30:      	adrp	x16, 0x203000
  1f4c34:      	ldr	x17, [x16, #0x7c8]
  1f4c38:      	add	x16, x16, #0x7c8
  1f4c3c:      	br	x17

00000000001f4c40 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA9_KcRA8_SA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSG_OSH_@plt>:
  1f4c40:      	adrp	x16, 0x203000
  1f4c44:      	ldr	x17, [x16, #0x7d0]
  1f4c48:      	add	x16, x16, #0x7d0
  1f4c4c:      	br	x17

00000000001f4c50 <_ZNSt6__ndk14pairIKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IRA8_KcSC_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEOSE_OSF_@plt>:
  1f4c50:      	adrp	x16, 0x203000
  1f4c54:      	ldr	x17, [x16, #0x7d8]
  1f4c58:      	add	x16, x16, #0x7d8
  1f4c5c:      	br	x17

00000000001f4c60 <_ZN7MMCodec11VideoStreamD1Ev@plt>:
  1f4c60:      	adrp	x16, 0x203000
  1f4c64:      	ldr	x17, [x16, #0x7e0]
  1f4c68:      	add	x16, x16, #0x7e0
  1f4c6c:      	br	x17

00000000001f4c70 <_ZN7MMCodec10MediaParam18readInVideoSettingEPNS_12VideoParam_tE@plt>:
  1f4c70:      	adrp	x16, 0x203000
  1f4c74:      	ldr	x17, [x16, #0x7e8]
  1f4c78:      	add	x16, x16, #0x7e8
  1f4c7c:      	br	x17

00000000001f4c80 <_ZN7MMCodec10MediaParam19readOutVideoSettingEPNS_12VideoParam_tE@plt>:
  1f4c80:      	adrp	x16, 0x203000
  1f4c84:      	ldr	x17, [x16, #0x7f0]
  1f4c88:      	add	x16, x16, #0x7f0
  1f4c8c:      	br	x17

00000000001f4c90 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_@plt>:
  1f4c90:      	adrp	x16, 0x203000
  1f4c94:      	ldr	x17, [x16, #0x7f8]
  1f4c98:      	add	x16, x16, #0x7f8
  1f4c9c:      	br	x17

00000000001f4ca0 <_ZN7MMCodec19getVideoInnerFormatENS_16VIDEO_PIX_FORMATE@plt>:
  1f4ca0:      	adrp	x16, 0x203000
  1f4ca4:      	ldr	x17, [x16, #0x800]
  1f4ca8:      	add	x16, x16, #0x800
  1f4cac:      	br	x17

00000000001f4cb0 <av_stream_new_side_data@plt>:
  1f4cb0:      	adrp	x16, 0x203000
  1f4cb4:      	ldr	x17, [x16, #0x808]
  1f4cb8:      	add	x16, x16, #0x808
  1f4cbc:      	br	x17

00000000001f4cc0 <_ZN7MMCodec27flip_rotation_transfer_exifEii@plt>:
  1f4cc0:      	adrp	x16, 0x203000
  1f4cc4:      	ldr	x17, [x16, #0x810]
  1f4cc8:      	add	x16, x16, #0x810
  1f4ccc:      	br	x17

00000000001f4cd0 <_ZN7MMCodec27exif_transfer_displaymatrixEiPi@plt>:
  1f4cd0:      	adrp	x16, 0x203000
  1f4cd4:      	ldr	x17, [x16, #0x818]
  1f4cd8:      	add	x16, x16, #0x818
  1f4cdc:      	br	x17

00000000001f4ce0 <_ZN7MMCodec16getFFmpegCodecIDENS_11MT_CODEC_IDE@plt>:
  1f4ce0:      	adrp	x16, 0x203000
  1f4ce4:      	ldr	x17, [x16, #0x820]
  1f4ce8:      	add	x16, x16, #0x820
  1f4cec:      	br	x17

00000000001f4cf0 <strcmp@plt>:
  1f4cf0:      	adrp	x16, 0x203000
  1f4cf4:      	ldr	x17, [x16, #0x828]
  1f4cf8:      	add	x16, x16, #0x828
  1f4cfc:      	br	x17

00000000001f4d00 <av_opt_set@plt>:
  1f4d00:      	adrp	x16, 0x203000
  1f4d04:      	ldr	x17, [x16, #0x830]
  1f4d08:      	add	x16, x16, #0x830
  1f4d0c:      	br	x17

00000000001f4d10 <_ZN7MMCodec9to_stringIiEENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEET_@plt>:
  1f4d10:      	adrp	x16, 0x203000
  1f4d14:      	ldr	x17, [x16, #0x838]
  1f4d18:      	add	x16, x16, #0x838
  1f4d1c:      	br	x17

00000000001f4d20 <av_buffer_unref@plt>:
  1f4d20:      	adrp	x16, 0x203000
  1f4d24:      	ldr	x17, [x16, #0x840]
  1f4d28:      	add	x16, x16, #0x840
  1f4d2c:      	br	x17

00000000001f4d30 <_ZN7MMCodec9to_stringIPcEENSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEET_@plt>:
  1f4d30:      	adrp	x16, 0x203000
  1f4d34:      	ldr	x17, [x16, #0x848]
  1f4d38:      	add	x16, x16, #0x848
  1f4d3c:      	br	x17

00000000001f4d40 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
  1f4d40:      	adrp	x16, 0x203000
  1f4d44:      	ldr	x17, [x16, #0x850]
  1f4d48:      	add	x16, x16, #0x850
  1f4d4c:      	br	x17

00000000001f4d50 <_ZN7MMCodec19getVideoOuterFormatE13AVPixelFormat@plt>:
  1f4d50:      	adrp	x16, 0x203000
  1f4d54:      	ldr	x17, [x16, #0x858]
  1f4d58:      	add	x16, x16, #0x858
  1f4d5c:      	br	x17

00000000001f4d60 <av_strlcpy@plt>:
  1f4d60:      	adrp	x16, 0x203000
  1f4d64:      	ldr	x17, [x16, #0x860]
  1f4d68:      	add	x16, x16, #0x860
  1f4d6c:      	br	x17

00000000001f4d70 <_ZN7MMCodec14getProfileNameE9AVCodecIDi@plt>:
  1f4d70:      	adrp	x16, 0x203000
  1f4d74:      	ldr	x17, [x16, #0x868]
  1f4d78:      	add	x16, x16, #0x868
  1f4d7c:      	br	x17

00000000001f4d80 <__strlen_chk@plt>:
  1f4d80:      	adrp	x16, 0x203000
  1f4d84:      	ldr	x17, [x16, #0x870]
  1f4d88:      	add	x16, x16, #0x870
  1f4d8c:      	br	x17

00000000001f4d90 <av_dict_free@plt>:
  1f4d90:      	adrp	x16, 0x203000
  1f4d94:      	ldr	x17, [x16, #0x878]
  1f4d98:      	add	x16, x16, #0x878
  1f4d9c:      	br	x17

00000000001f4da0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEErsERi@plt>:
  1f4da0:      	adrp	x16, 0x203000
  1f4da4:      	ldr	x17, [x16, #0x880]
  1f4da8:      	add	x16, x16, #0x880
  1f4dac:      	br	x17

00000000001f4db0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
  1f4db0:      	adrp	x16, 0x203000
  1f4db4:      	ldr	x17, [x16, #0x888]
  1f4db8:      	add	x16, x16, #0x888
  1f4dbc:      	br	x17

00000000001f4dc0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEED2Ev@plt>:
  1f4dc0:      	adrp	x16, 0x203000
  1f4dc4:      	ldr	x17, [x16, #0x890]
  1f4dc8:      	add	x16, x16, #0x890
  1f4dcc:      	br	x17

00000000001f4dd0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  1f4dd0:      	adrp	x16, 0x203000
  1f4dd4:      	ldr	x17, [x16, #0x898]
  1f4dd8:      	add	x16, x16, #0x898
  1f4ddc:      	br	x17

00000000001f4de0 <_ZNSt6__ndk119basic_istringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
  1f4de0:      	adrp	x16, 0x203000
  1f4de4:      	ldr	x17, [x16, #0x8a0]
  1f4de8:      	add	x16, x16, #0x8a0
  1f4dec:      	br	x17

00000000001f4df0 <vsnprintf@plt>:
  1f4df0:      	adrp	x16, 0x203000
  1f4df4:      	ldr	x17, [x16, #0x8a8]
  1f4df8:      	add	x16, x16, #0x8a8
  1f4dfc:      	br	x17

00000000001f4e00 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  1f4e00:      	adrp	x16, 0x203000
  1f4e04:      	ldr	x17, [x16, #0x8b0]
  1f4e08:      	add	x16, x16, #0x8b0
  1f4e0c:      	br	x17

00000000001f4e10 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  1f4e10:      	adrp	x16, 0x203000
  1f4e14:      	ldr	x17, [x16, #0x8b8]
  1f4e18:      	add	x16, x16, #0x8b8
  1f4e1c:      	br	x17

00000000001f4e20 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
  1f4e20:      	adrp	x16, 0x203000
  1f4e24:      	ldr	x17, [x16, #0x8c0]
  1f4e28:      	add	x16, x16, #0x8c0
  1f4e2c:      	br	x17

00000000001f4e30 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
  1f4e30:      	adrp	x16, 0x203000
  1f4e34:      	ldr	x17, [x16, #0x8c8]
  1f4e38:      	add	x16, x16, #0x8c8
  1f4e3c:      	br	x17

00000000001f4e40 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  1f4e40:      	adrp	x16, 0x203000
  1f4e44:      	ldr	x17, [x16, #0x8d0]
  1f4e48:      	add	x16, x16, #0x8d0
  1f4e4c:      	br	x17

00000000001f4e50 <_ZNSt6__ndk119basic_ostringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
  1f4e50:      	adrp	x16, 0x203000
  1f4e54:      	ldr	x17, [x16, #0x8d8]
  1f4e58:      	add	x16, x16, #0x8d8
  1f4e5c:      	br	x17

00000000001f4e60 <av_image_fill_arrays@plt>:
  1f4e60:      	adrp	x16, 0x203000
  1f4e64:      	ldr	x17, [x16, #0x8e0]
  1f4e68:      	add	x16, x16, #0x8e0
  1f4e6c:      	br	x17

00000000001f4e70 <av_get_time_base_q@plt>:
  1f4e70:      	adrp	x16, 0x203000
  1f4e74:      	ldr	x17, [x16, #0x8e8]
  1f4e78:      	add	x16, x16, #0x8e8
  1f4e7c:      	br	x17

00000000001f4e80 <av_rescale_q@plt>:
  1f4e80:      	adrp	x16, 0x203000
  1f4e84:      	ldr	x17, [x16, #0x8f0]
  1f4e88:      	add	x16, x16, #0x8f0
  1f4e8c:      	br	x17

00000000001f4e90 <memcpy@plt>:
  1f4e90:      	adrp	x16, 0x203000
  1f4e94:      	ldr	x17, [x16, #0x8f8]
  1f4e98:      	add	x16, x16, #0x8f8
  1f4e9c:      	br	x17

00000000001f4ea0 <_ZN7MMCodec19getVideoPlaneNumberENS_16VIDEO_PIX_FORMATE@plt>:
  1f4ea0:      	adrp	x16, 0x203000
  1f4ea4:      	ldr	x17, [x16, #0x900]
  1f4ea8:      	add	x16, x16, #0x900
  1f4eac:      	br	x17

00000000001f4eb0 <_ZN7MMCodec12getLibyuvFmtENS_16VIDEO_PIX_FORMATEb@plt>:
  1f4eb0:      	adrp	x16, 0x203000
  1f4eb4:      	ldr	x17, [x16, #0x908]
  1f4eb8:      	add	x16, x16, #0x908
  1f4ebc:      	br	x17

00000000001f4ec0 <_ZN7MMCodec15VideoFrameUtils13convertFormatEPKPKhPKimiiiiPPhPiRm@plt>:
  1f4ec0:      	adrp	x16, 0x203000
  1f4ec4:      	ldr	x17, [x16, #0x910]
  1f4ec8:      	add	x16, x16, #0x910
  1f4ecc:      	br	x17

00000000001f4ed0 <sws_getContext@plt>:
  1f4ed0:      	adrp	x16, 0x203000
  1f4ed4:      	ldr	x17, [x16, #0x918]
  1f4ed8:      	add	x16, x16, #0x918
  1f4edc:      	br	x17

00000000001f4ee0 <sws_getCoefficients@plt>:
  1f4ee0:      	adrp	x16, 0x203000
  1f4ee4:      	ldr	x17, [x16, #0x920]
  1f4ee8:      	add	x16, x16, #0x920
  1f4eec:      	br	x17

00000000001f4ef0 <sws_setColorspaceDetails@plt>:
  1f4ef0:      	adrp	x16, 0x203000
  1f4ef4:      	ldr	x17, [x16, #0x928]
  1f4ef8:      	add	x16, x16, #0x928
  1f4efc:      	br	x17

00000000001f4f00 <sws_scale@plt>:
  1f4f00:      	adrp	x16, 0x203000
  1f4f04:      	ldr	x17, [x16, #0x930]
  1f4f08:      	add	x16, x16, #0x930
  1f4f0c:      	br	x17

00000000001f4f10 <sws_freeContext@plt>:
  1f4f10:      	adrp	x16, 0x203000
  1f4f14:      	ldr	x17, [x16, #0x938]
  1f4f18:      	add	x16, x16, #0x938
  1f4f1c:      	br	x17

00000000001f4f20 <_ZNSt9exceptionD2Ev@plt>:
  1f4f20:      	adrp	x16, 0x203000
  1f4f24:      	ldr	x17, [x16, #0x940]
  1f4f28:      	add	x16, x16, #0x940
  1f4f2c:      	br	x17

00000000001f4f30 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  1f4f30:      	adrp	x16, 0x203000
  1f4f34:      	ldr	x17, [x16, #0x948]
  1f4f38:      	add	x16, x16, #0x948
  1f4f3c:      	br	x17

00000000001f4f40 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
  1f4f40:      	adrp	x16, 0x203000
  1f4f44:      	ldr	x17, [x16, #0x950]
  1f4f48:      	add	x16, x16, #0x950
  1f4f4c:      	br	x17

00000000001f4f50 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  1f4f50:      	adrp	x16, 0x203000
  1f4f54:      	ldr	x17, [x16, #0x958]
  1f4f58:      	add	x16, x16, #0x958
  1f4f5c:      	br	x17

00000000001f4f60 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  1f4f60:      	adrp	x16, 0x203000
  1f4f64:      	ldr	x17, [x16, #0x960]
  1f4f68:      	add	x16, x16, #0x960
  1f4f6c:      	br	x17

00000000001f4f70 <_ZNSt6__ndk16localeD1Ev@plt>:
  1f4f70:      	adrp	x16, 0x203000
  1f4f74:      	ldr	x17, [x16, #0x968]
  1f4f78:      	add	x16, x16, #0x968
  1f4f7c:      	br	x17

00000000001f4f80 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  1f4f80:      	adrp	x16, 0x203000
  1f4f84:      	ldr	x17, [x16, #0x970]
  1f4f88:      	add	x16, x16, #0x970
  1f4f8c:      	br	x17

00000000001f4f90 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
  1f4f90:      	adrp	x16, 0x203000
  1f4f94:      	ldr	x17, [x16, #0x978]
  1f4f98:      	add	x16, x16, #0x978
  1f4f9c:      	br	x17

00000000001f4fa0 <_ZNSt6__ndk18ios_base33__set_badbit_and_consider_rethrowEv@plt>:
  1f4fa0:      	adrp	x16, 0x203000
  1f4fa4:      	ldr	x17, [x16, #0x980]
  1f4fa8:      	add	x16, x16, #0x980
  1f4fac:      	br	x17

00000000001f4fb0 <memset@plt>:
  1f4fb0:      	adrp	x16, 0x203000
  1f4fb4:      	ldr	x17, [x16, #0x988]
  1f4fb8:      	add	x16, x16, #0x988
  1f4fbc:      	br	x17

00000000001f4fc0 <_ZN7MMCodec11VideoStreamC1EPNS_14OutMediaHandleE@plt>:
  1f4fc0:      	adrp	x16, 0x203000
  1f4fc4:      	ldr	x17, [x16, #0x990]
  1f4fc8:      	add	x16, x16, #0x990
  1f4fcc:      	br	x17

00000000001f4fd0 <avformat_free_context@plt>:
  1f4fd0:      	adrp	x16, 0x203000
  1f4fd4:      	ldr	x17, [x16, #0x998]
  1f4fd8:      	add	x16, x16, #0x998
  1f4fdc:      	br	x17

00000000001f4fe0 <free@plt>:
  1f4fe0:      	adrp	x16, 0x203000
  1f4fe4:      	ldr	x17, [x16, #0x9a0]
  1f4fe8:      	add	x16, x16, #0x9a0
  1f4fec:      	br	x17

00000000001f4ff0 <_ZN7MMCodec8MMBufferD1Ev@plt>:
  1f4ff0:      	adrp	x16, 0x203000
  1f4ff4:      	ldr	x17, [x16, #0x9a8]
  1f4ff8:      	add	x16, x16, #0x9a8
  1f4ffc:      	br	x17

00000000001f5000 <_ZN7MMCodec8HLSMuxer5setupEPNS_8HLSParamE@plt>:
  1f5000:      	adrp	x16, 0x203000
  1f5004:      	ldr	x17, [x16, #0x9b0]
  1f5008:      	add	x16, x16, #0x9b0
  1f500c:      	br	x17

00000000001f5010 <_ZN7MMCodec8HLSMuxer11writePacketEP8AVPacketb@plt>:
  1f5010:      	adrp	x16, 0x203000
  1f5014:      	ldr	x17, [x16, #0x9b8]
  1f5018:      	add	x16, x16, #0x9b8
  1f501c:      	br	x17

00000000001f5020 <av_interleaved_write_frame@plt>:
  1f5020:      	adrp	x16, 0x203000
  1f5024:      	ldr	x17, [x16, #0x9c0]
  1f5028:      	add	x16, x16, #0x9c0
  1f502c:      	br	x17

00000000001f5030 <realloc@plt>:
  1f5030:      	adrp	x16, 0x203000
  1f5034:      	ldr	x17, [x16, #0x9c8]
  1f5038:      	add	x16, x16, #0x9c8
  1f503c:      	br	x17

00000000001f5040 <_ZN7MMCodec8HLSMuxer5flushEv@plt>:
  1f5040:      	adrp	x16, 0x203000
  1f5044:      	ldr	x17, [x16, #0x9d0]
  1f5048:      	add	x16, x16, #0x9d0
  1f504c:      	br	x17

00000000001f5050 <_ZN7MMCodec8HLSMuxer5closeEv@plt>:
  1f5050:      	adrp	x16, 0x203000
  1f5054:      	ldr	x17, [x16, #0x9d8]
  1f5058:      	add	x16, x16, #0x9d8
  1f505c:      	br	x17

00000000001f5060 <av_write_trailer@plt>:
  1f5060:      	adrp	x16, 0x203000
  1f5064:      	ldr	x17, [x16, #0x9e0]
  1f5068:      	add	x16, x16, #0x9e0
  1f506c:      	br	x17

00000000001f5070 <avio_closep@plt>:
  1f5070:      	adrp	x16, 0x203000
  1f5074:      	ldr	x17, [x16, #0x9e8]
  1f5078:      	add	x16, x16, #0x9e8
  1f507c:      	br	x17

00000000001f5080 <_ZN7MMCodec8HLSMuxer9setPSDataEPhii@plt>:
  1f5080:      	adrp	x16, 0x203000
  1f5084:      	ldr	x17, [x16, #0x9f0]
  1f5088:      	add	x16, x16, #0x9f0
  1f508c:      	br	x17

00000000001f5090 <_ZN7MMCodec8HLSMuxer29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE@plt>:
  1f5090:      	adrp	x16, 0x203000
  1f5094:      	ldr	x17, [x16, #0x9f8]
  1f5098:      	add	x16, x16, #0x9f8
  1f509c:      	br	x17

00000000001f50a0 <_ZN7MMCodec8HLSMuxer32setTSSaveSegmentCompleteListenerENSt6__ndk18functionIFvvEEE@plt>:
  1f50a0:      	adrp	x16, 0x203000
  1f50a4:      	ldr	x17, [x16, #0xa00]
  1f50a8:      	add	x16, x16, #0xa00
  1f50ac:      	br	x17

00000000001f50b0 <_ZN7MMCodec8HLSMuxerC1Ev@plt>:
  1f50b0:      	adrp	x16, 0x203000
  1f50b4:      	ldr	x17, [x16, #0xa08]
  1f50b8:      	add	x16, x16, #0xa08
  1f50bc:      	br	x17

00000000001f50c0 <_ZN7MMCodec8HLSMuxerD1Ev@plt>:
  1f50c0:      	adrp	x16, 0x203000
  1f50c4:      	ldr	x17, [x16, #0xa10]
  1f50c8:      	add	x16, x16, #0xa10
  1f50cc:      	br	x17

00000000001f50d0 <_ZN7MMCodec17checkIsExitThreadERKNSt6__ndk16vectorIPNS_16ExportStreamBaseENS0_9allocatorIS3_EEEE@plt>:
  1f50d0:      	adrp	x16, 0x203000
  1f50d4:      	ldr	x17, [x16, #0xa18]
  1f50d8:      	add	x16, x16, #0xa18
  1f50dc:      	br	x17

00000000001f50e0 <_ZN7MMCodec13ThreadContext5abortEv@plt>:
  1f50e0:      	adrp	x16, 0x203000
  1f50e4:      	ldr	x17, [x16, #0xa20]
  1f50e8:      	add	x16, x16, #0xa20
  1f50ec:      	br	x17

00000000001f50f0 <av_get_media_type_string@plt>:
  1f50f0:      	adrp	x16, 0x203000
  1f50f4:      	ldr	x17, [x16, #0xa28]
  1f50f8:      	add	x16, x16, #0xa28
  1f50fc:      	br	x17

00000000001f5100 <_ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI7AVFrameEEE4takeERS4_i@plt>:
  1f5100:      	adrp	x16, 0x203000
  1f5104:      	ldr	x17, [x16, #0xa30]
  1f5108:      	add	x16, x16, #0xa30
  1f510c:      	br	x17

00000000001f5110 <av_gettime_relative@plt>:
  1f5110:      	adrp	x16, 0x203000
  1f5114:      	ldr	x17, [x16, #0xa38]
  1f5118:      	add	x16, x16, #0xa38
  1f511c:      	br	x17

00000000001f5120 <avcodec_send_frame@plt>:
  1f5120:      	adrp	x16, 0x203000
  1f5124:      	ldr	x17, [x16, #0xa40]
  1f5128:      	add	x16, x16, #0xa40
  1f512c:      	br	x17

00000000001f5130 <_ZN7MMCodec14AICodecContext15acquireAVPacketEv@plt>:
  1f5130:      	adrp	x16, 0x203000
  1f5134:      	ldr	x17, [x16, #0xa48]
  1f5138:      	add	x16, x16, #0xa48
  1f513c:      	br	x17

00000000001f5140 <avcodec_receive_packet@plt>:
  1f5140:      	adrp	x16, 0x203000
  1f5144:      	ldr	x17, [x16, #0xa50]
  1f5148:      	add	x16, x16, #0xa50
  1f514c:      	br	x17

00000000001f5150 <_ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE3putERKS4_@plt>:
  1f5150:      	adrp	x16, 0x203000
  1f5154:      	ldr	x17, [x16, #0xa58]
  1f5158:      	add	x16, x16, #0xa58
  1f515c:      	br	x17

00000000001f5160 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc@plt>:
  1f5160:      	adrp	x16, 0x203000
  1f5164:      	ldr	x17, [x16, #0xa60]
  1f5168:      	add	x16, x16, #0xa60
  1f516c:      	br	x17

00000000001f5170 <_ZN7MMCodec13MediaRecorder12addErrorInfoEPKc@plt>:
  1f5170:      	adrp	x16, 0x203000
  1f5174:      	ldr	x17, [x16, #0xa68]
  1f5178:      	add	x16, x16, #0xa68
  1f517c:      	br	x17

00000000001f5180 <_ZN7MMCodec13ThreadContext8markOverEv@plt>:
  1f5180:      	adrp	x16, 0x203000
  1f5184:      	ldr	x17, [x16, #0xa70]
  1f5188:      	add	x16, x16, #0xa70
  1f518c:      	br	x17

00000000001f5190 <_ZN7MMCodec14AICodecContext15releaseAVPacketEP8AVPacket@plt>:
  1f5190:      	adrp	x16, 0x203000
  1f5194:      	ldr	x17, [x16, #0xa78]
  1f5198:      	add	x16, x16, #0xa78
  1f519c:      	br	x17

00000000001f51a0 <_ZNSt6__ndk16chrono12steady_clock3nowEv@plt>:
  1f51a0:      	adrp	x16, 0x203000
  1f51a4:      	ldr	x17, [x16, #0xa80]
  1f51a8:      	add	x16, x16, #0xa80
  1f51ac:      	br	x17

00000000001f51b0 <_ZN7MMCodec20BoundedBlockingQueueINSt6__ndk110shared_ptrI8AVPacketEEE4takeERS4_i@plt>:
  1f51b0:      	adrp	x16, 0x203000
  1f51b4:      	ldr	x17, [x16, #0xa88]
  1f51b8:      	add	x16, x16, #0xa88
  1f51bc:      	br	x17

00000000001f51c0 <_ZN7MMCodec12initAVPacketEP8AVPacket@plt>:
  1f51c0:      	adrp	x16, 0x203000
  1f51c4:      	ldr	x17, [x16, #0xa90]
  1f51c8:      	add	x16, x16, #0xa90
  1f51cc:      	br	x17

00000000001f51d0 <_ZNSt6__ndk118condition_variable15__do_timed_waitERNS_11unique_lockINS_5mutexEEENS_6chrono10time_pointINS5_12system_clockENS5_8durationIxNS_5ratioILl1ELl1000000000EEEEEEE@plt>:
  1f51d0:      	adrp	x16, 0x203000
  1f51d4:      	ldr	x17, [x16, #0xa98]
  1f51d8:      	add	x16, x16, #0xa98
  1f51dc:      	br	x17

00000000001f51e0 <_ZNSt6__ndk16chrono12system_clock3nowEv@plt>:
  1f51e0:      	adrp	x16, 0x203000
  1f51e4:      	ldr	x17, [x16, #0xaa0]
  1f51e8:      	add	x16, x16, #0xaa0
  1f51ec:      	br	x17

00000000001f51f0 <_ZN7MMCodec19ExportStreamFactory9newStreamEPNS_14OutMediaHandleENS_11MediaType_tENS_12StreamType_tE@plt>:
  1f51f0:      	adrp	x16, 0x203000
  1f51f4:      	ldr	x17, [x16, #0xaa8]
  1f51f8:      	add	x16, x16, #0xaa8
  1f51fc:      	br	x17

00000000001f5200 <_ZN7MMCodec18AndroidVideoStreamC1EPNS_14OutMediaHandleE@plt>:
  1f5200:      	adrp	x16, 0x203000
  1f5204:      	ldr	x17, [x16, #0xab0]
  1f5208:      	add	x16, x16, #0xab0
  1f520c:      	br	x17

00000000001f5210 <malloc@plt>:
  1f5210:      	adrp	x16, 0x203000
  1f5214:      	ldr	x17, [x16, #0xab8]
  1f5218:      	add	x16, x16, #0xab8
  1f521c:      	br	x17

00000000001f5220 <_ZN7MMCodec10MediaParam15setAudioInParamEiiNS_19AUDIO_SAMPLE_FORMATE@plt>:
  1f5220:      	adrp	x16, 0x203000
  1f5224:      	ldr	x17, [x16, #0xac0]
  1f5228:      	add	x16, x16, #0xac0
  1f522c:      	br	x17

00000000001f5230 <_ZN7MMCodec10MediaParam16setAudioOutParamEiii@plt>:
  1f5230:      	adrp	x16, 0x203000
  1f5234:      	ldr	x17, [x16, #0xac8]
  1f5238:      	add	x16, x16, #0xac8
  1f523c:      	br	x17

00000000001f5240 <_ZN7MMCodec10MediaParam20setEnableAudioOutputEb@plt>:
  1f5240:      	adrp	x16, 0x203000
  1f5244:      	ldr	x17, [x16, #0xad0]
  1f5248:      	add	x16, x16, #0xad0
  1f524c:      	br	x17

00000000001f5250 <_ZN7MMCodec10MediaParam13setVideoInFmtENS_16VIDEO_PIX_FORMATE@plt>:
  1f5250:      	adrp	x16, 0x203000
  1f5254:      	ldr	x17, [x16, #0xad8]
  1f5258:      	add	x16, x16, #0xad8
  1f525c:      	br	x17

00000000001f5260 <_ZN7MMCodec10MediaParam15setVideoInParamEiiNS_16VIDEO_PIX_FORMATE@plt>:
  1f5260:      	adrp	x16, 0x203000
  1f5264:      	ldr	x17, [x16, #0xae0]
  1f5268:      	add	x16, x16, #0xae0
  1f526c:      	br	x17

00000000001f5270 <av_image_get_buffer_size@plt>:
  1f5270:      	adrp	x16, 0x203000
  1f5274:      	ldr	x17, [x16, #0xae8]
  1f5278:      	add	x16, x16, #0xae8
  1f527c:      	br	x17

00000000001f5280 <_ZN7MMCodec10MediaParam12setVideoCropEiiii@plt>:
  1f5280:      	adrp	x16, 0x203000
  1f5284:      	ldr	x17, [x16, #0xaf0]
  1f5288:      	add	x16, x16, #0xaf0
  1f528c:      	br	x17

00000000001f5290 <_ZN7MMCodec10MediaParam14setVideoOutFmtENS_16VIDEO_PIX_FORMATE@plt>:
  1f5290:      	adrp	x16, 0x203000
  1f5294:      	ldr	x17, [x16, #0xaf8]
  1f5298:      	add	x16, x16, #0xaf8
  1f529c:      	br	x17

00000000001f52a0 <_ZN7MMCodec10MediaParam16setVideoOutParamEiii@plt>:
  1f52a0:      	adrp	x16, 0x203000
  1f52a4:      	ldr	x17, [x16, #0xb00]
  1f52a8:      	add	x16, x16, #0xb00
  1f52ac:      	br	x17

00000000001f52b0 <_ZN7MMCodec10MediaParam20setEnableVideoOutputEb@plt>:
  1f52b0:      	adrp	x16, 0x203000
  1f52b4:      	ldr	x17, [x16, #0xb08]
  1f52b8:      	add	x16, x16, #0xb08
  1f52bc:      	br	x17

00000000001f52c0 <_ZN7MMCodec10MediaParam6setFpsEi@plt>:
  1f52c0:      	adrp	x16, 0x203000
  1f52c4:      	ldr	x17, [x16, #0xb10]
  1f52c8:      	add	x16, x16, #0xb10
  1f52cc:      	br	x17

00000000001f52d0 <_ZN7MMCodec10MediaParam11setVideoGopEi@plt>:
  1f52d0:      	adrp	x16, 0x203000
  1f52d4:      	ldr	x17, [x16, #0xb18]
  1f52d8:      	add	x16, x16, #0xb18
  1f52dc:      	br	x17

00000000001f52e0 <_ZN7MMCodec10MediaParam16setVideoOutCodecENS_11MT_CODEC_IDE@plt>:
  1f52e0:      	adrp	x16, 0x203000
  1f52e4:      	ldr	x17, [x16, #0xb20]
  1f52e8:      	add	x16, x16, #0xb20
  1f52ec:      	br	x17

00000000001f52f0 <_ZN7MMCodec10MediaParam18setVideoOutProfileENS_16MT_CODEC_PROFILEE@plt>:
  1f52f0:      	adrp	x16, 0x203000
  1f52f4:      	ldr	x17, [x16, #0xb28]
  1f52f8:      	add	x16, x16, #0xb28
  1f52fc:      	br	x17

00000000001f5300 <_ZN7MMCodec10MediaParam16setVideoOutLevelENS_14MT_CODEC_LEVELE@plt>:
  1f5300:      	adrp	x16, 0x203000
  1f5304:      	ldr	x17, [x16, #0xb30]
  1f5308:      	add	x16, x16, #0xb30
  1f530c:      	br	x17

00000000001f5310 <_ZN7MMCodec10MediaParam14setVideoRotateEi@plt>:
  1f5310:      	adrp	x16, 0x203000
  1f5314:      	ldr	x17, [x16, #0xb38]
  1f5318:      	add	x16, x16, #0xb38
  1f531c:      	br	x17

00000000001f5320 <_ZN7MMCodec10MediaParam14getVideoRotateEv@plt>:
  1f5320:      	adrp	x16, 0x203000
  1f5324:      	ldr	x17, [x16, #0xb40]
  1f5328:      	add	x16, x16, #0xb40
  1f532c:      	br	x17

00000000001f5330 <_ZN7MMCodec10MediaParam19setVideoSaveThreadsEi@plt>:
  1f5330:      	adrp	x16, 0x203000
  1f5334:      	ldr	x17, [x16, #0xb48]
  1f5338:      	add	x16, x16, #0xb48
  1f533c:      	br	x17

00000000001f5340 <_ZN7MMCodec10MediaParam18setVideoSavePresetEPKc@plt>:
  1f5340:      	adrp	x16, 0x203000
  1f5344:      	ldr	x17, [x16, #0xb50]
  1f5348:      	add	x16, x16, #0xb50
  1f534c:      	br	x17

00000000001f5350 <__strcpy_chk@plt>:
  1f5350:      	adrp	x16, 0x203000
  1f5354:      	ldr	x17, [x16, #0xb58]
  1f5358:      	add	x16, x16, #0xb58
  1f535c:      	br	x17

00000000001f5360 <_ZN7MMCodec10MediaParam16setVideoSaveTuneEPKc@plt>:
  1f5360:      	adrp	x16, 0x203000
  1f5364:      	ldr	x17, [x16, #0xb60]
  1f5368:      	add	x16, x16, #0xb60
  1f536c:      	br	x17

00000000001f5370 <_ZN7MMCodec10MediaParam30setVideoEnableRealTimeEncodingEb@plt>:
  1f5370:      	adrp	x16, 0x203000
  1f5374:      	ldr	x17, [x16, #0xb68]
  1f5378:      	add	x16, x16, #0xb68
  1f537c:      	br	x17

00000000001f5380 <strncpy@plt>:
  1f5380:      	adrp	x16, 0x203000
  1f5384:      	ldr	x17, [x16, #0xb70]
  1f5388:      	add	x16, x16, #0xb70
  1f538c:      	br	x17

00000000001f5390 <_ZN7MMCodec10MediaParam14getAudioTSPathEv@plt>:
  1f5390:      	adrp	x16, 0x203000
  1f5394:      	ldr	x17, [x16, #0xb78]
  1f5398:      	add	x16, x16, #0xb78
  1f539c:      	br	x17

00000000001f53a0 <_ZN7MMCodec10MediaParam14getVideoTSPathEv@plt>:
  1f53a0:      	adrp	x16, 0x203000
  1f53a4:      	ldr	x17, [x16, #0xb80]
  1f53a8:      	add	x16, x16, #0xb80
  1f53ac:      	br	x17

00000000001f53b0 <_ZN7MMCodec10MediaParam20getTSSegmentDurationEv@plt>:
  1f53b0:      	adrp	x16, 0x203000
  1f53b4:      	ldr	x17, [x16, #0xb88]
  1f53b8:      	add	x16, x16, #0xb88
  1f53bc:      	br	x17

00000000001f53c0 <_ZN7MMCodec10MediaParam8hasAudioEv@plt>:
  1f53c0:      	adrp	x16, 0x203000
  1f53c4:      	ldr	x17, [x16, #0xb90]
  1f53c8:      	add	x16, x16, #0xb90
  1f53cc:      	br	x17

00000000001f53d0 <_ZN7MMCodec10MediaParam8hasVideoEv@plt>:
  1f53d0:      	adrp	x16, 0x203000
  1f53d4:      	ldr	x17, [x16, #0xb98]
  1f53d8:      	add	x16, x16, #0xb98
  1f53dc:      	br	x17

00000000001f53e0 <_ZN7MMCodec10MediaParamC1Ev@plt>:
  1f53e0:      	adrp	x16, 0x203000
  1f53e4:      	ldr	x17, [x16, #0xba0]
  1f53e8:      	add	x16, x16, #0xba0
  1f53ec:      	br	x17

00000000001f53f0 <_ZN7MMCodec10MediaParamC1ERKS0_@plt>:
  1f53f0:      	adrp	x16, 0x203000
  1f53f4:      	ldr	x17, [x16, #0xba8]
  1f53f8:      	add	x16, x16, #0xba8
  1f53fc:      	br	x17

00000000001f5400 <_ZN7MMCodec10MediaParamD1Ev@plt>:
  1f5400:      	adrp	x16, 0x203000
  1f5404:      	ldr	x17, [x16, #0xbb0]
  1f5408:      	add	x16, x16, #0xbb0
  1f540c:      	br	x17

00000000001f5410 <_ZN7MMCodec6AVIRef6retainEv@plt>:
  1f5410:      	adrp	x16, 0x203000
  1f5414:      	ldr	x17, [x16, #0xbb8]
  1f5418:      	add	x16, x16, #0xbb8
  1f541c:      	br	x17

00000000001f5420 <av_match_ext@plt>:
  1f5420:      	adrp	x16, 0x203000
  1f5424:      	ldr	x17, [x16, #0xbc0]
  1f5428:      	add	x16, x16, #0xbc0
  1f542c:      	br	x17

00000000001f5430 <_ZN7MMCodec8GLShaderD1Ev@plt>:
  1f5430:      	adrp	x16, 0x203000
  1f5434:      	ldr	x17, [x16, #0xbc8]
  1f5438:      	add	x16, x16, #0xbc8
  1f543c:      	br	x17

00000000001f5440 <_ZN7MMCodec14OutMediaHandleD1Ev@plt>:
  1f5440:      	adrp	x16, 0x203000
  1f5444:      	ldr	x17, [x16, #0xbd0]
  1f5448:      	add	x16, x16, #0xbd0
  1f544c:      	br	x17

00000000001f5450 <_ZN7MMCodec6AVIRef7releaseEv@plt>:
  1f5450:      	adrp	x16, 0x203000
  1f5454:      	ldr	x17, [x16, #0xbd8]
  1f5458:      	add	x16, x16, #0xbd8
  1f545c:      	br	x17

00000000001f5460 <_ZN7MMCodec13MediaRecorder9glCleanupEv@plt>:
  1f5460:      	adrp	x16, 0x203000
  1f5464:      	ldr	x17, [x16, #0xbe0]
  1f5468:      	add	x16, x16, #0xbe0
  1f546c:      	br	x17

00000000001f5470 <_ZN7MMCodec13MediaRecorder11setCallbackENSt6__ndk18functionIFvPS0_NS_14RecorderModuleENS_20RecorderCallbackTypeEddPvEEE@plt>:
  1f5470:      	adrp	x16, 0x203000
  1f5474:      	ldr	x17, [x16, #0xbe8]
  1f5478:      	add	x16, x16, #0xbe8
  1f547c:      	br	x17

00000000001f5480 <_ZN7MMCodec13MediaRecorder21setEnableHardwareModeEb@plt>:
  1f5480:      	adrp	x16, 0x203000
  1f5484:      	ldr	x17, [x16, #0xbf0]
  1f5488:      	add	x16, x16, #0xbf0
  1f548c:      	br	x17

00000000001f5490 <_ZN7MMCodec13MediaRecorder22setCodecStrategyConfigENS_19CodecStrategyConfigE@plt>:
  1f5490:      	adrp	x16, 0x203000
  1f5494:      	ldr	x17, [x16, #0xbf8]
  1f5498:      	add	x16, x16, #0xbf8
  1f549c:      	br	x17

00000000001f54a0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSJ_IJEEEEEENS_4pairINS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_@plt>:
  1f54a0:      	adrp	x16, 0x203000
  1f54a4:      	ldr	x17, [x16, #0xc00]
  1f54a8:      	add	x16, x16, #0xc00
  1f54ac:      	br	x17

00000000001f54b0 <_ZN7MMCodec13MediaRecorder29setEnableAutoSwitchSoftEncodeEb@plt>:
  1f54b0:      	adrp	x16, 0x203000
  1f54b4:      	ldr	x17, [x16, #0xc08]
  1f54b8:      	add	x16, x16, #0xc08
  1f54bc:      	br	x17

00000000001f54c0 <_ZN7MMCodec13MediaRecorder11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE@plt>:
  1f54c0:      	adrp	x16, 0x203000
  1f54c4:      	ldr	x17, [x16, #0xc10]
  1f54c8:      	add	x16, x16, #0xc10
  1f54cc:      	br	x17

00000000001f54d0 <_ZNSt6__ndk14pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_EC2B8ne180000IPKcSA_TnNS_9enable_ifIXclsr10_CheckArgsE17__enable_implicitIT_T0_EEEiE4typeELi0EEEONS0_ISC_SD_EE@plt>:
  1f54d0:      	adrp	x16, 0x203000
  1f54d4:      	ldr	x17, [x16, #0xc18]
  1f54d8:      	add	x16, x16, #0xc18
  1f54dc:      	br	x17

00000000001f54e0 <_ZNSt6__ndk16vectorINS_4pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS5_IS8_EEE21__push_back_slow_pathIS8_EEPS8_OT_@plt>:
  1f54e0:      	adrp	x16, 0x203000
  1f54e4:      	ldr	x17, [x16, #0xc20]
  1f54e8:      	add	x16, x16, #0xc20
  1f54ec:      	br	x17

00000000001f54f0 <_ZN7MMCodec13MediaRecorder5startEv@plt>:
  1f54f0:      	adrp	x16, 0x203000
  1f54f4:      	ldr	x17, [x16, #0xc28]
  1f54f8:      	add	x16, x16, #0xc28
  1f54fc:      	br	x17

00000000001f5500 <_ZN7MMCodec14OutMediaHandle5closeEPNS_21EncodePerformanceInfoE@plt>:
  1f5500:      	adrp	x16, 0x203000
  1f5504:      	ldr	x17, [x16, #0xc30]
  1f5508:      	add	x16, x16, #0xc30
  1f550c:      	br	x17

00000000001f5510 <_ZN7MMCodec14OutMediaHandleC1EPNS_14AICodecContextE@plt>:
  1f5510:      	adrp	x16, 0x203000
  1f5514:      	ldr	x17, [x16, #0xc38]
  1f5518:      	add	x16, x16, #0xc38
  1f551c:      	br	x17

00000000001f5520 <_ZN7MMCodec14OutMediaHandle11setHardModeEb@plt>:
  1f5520:      	adrp	x16, 0x203000
  1f5524:      	ldr	x17, [x16, #0xc40]
  1f5528:      	add	x16, x16, #0xc40
  1f552c:      	br	x17

00000000001f5530 <_ZN7MMCodec14OutMediaHandle20enableAsyncSendVideoEb@plt>:
  1f5530:      	adrp	x16, 0x203000
  1f5534:      	ldr	x17, [x16, #0xc48]
  1f5538:      	add	x16, x16, #0xc48
  1f553c:      	br	x17

00000000001f5540 <_ZN7MMCodec14OutMediaHandle15enableFastStartEb@plt>:
  1f5540:      	adrp	x16, 0x203000
  1f5544:      	ldr	x17, [x16, #0xc50]
  1f5548:      	add	x16, x16, #0xc50
  1f554c:      	br	x17

00000000001f5550 <_ZN7MMCodec14OutMediaHandle29setTSSaveSegmentReadyListenerENSt6__ndk18functionIFvPKcEEE@plt>:
  1f5550:      	adrp	x16, 0x203000
  1f5554:      	ldr	x17, [x16, #0xc58]
  1f5558:      	add	x16, x16, #0xc58
  1f555c:      	br	x17

00000000001f5560 <_ZN7MMCodec14OutMediaHandle32setTSSaveSegmentCompleteListenerENSt6__ndk18functionIFvvEEE@plt>:
  1f5560:      	adrp	x16, 0x203000
  1f5564:      	ldr	x17, [x16, #0xc60]
  1f5568:      	add	x16, x16, #0xc60
  1f556c:      	br	x17

00000000001f5570 <_ZN7MMCodec14OutMediaHandle11setCallbackEPNS_13MediaRecorderENSt6__ndk18functionIFvS2_NS_14RecorderModuleENS_20RecorderCallbackTypeEddPvEEE@plt>:
  1f5570:      	adrp	x16, 0x203000
  1f5574:      	ldr	x17, [x16, #0xc68]
  1f5578:      	add	x16, x16, #0xc68
  1f557c:      	br	x17

00000000001f5580 <_ZN7MMCodec14OutMediaHandle4openEPhmPKc@plt>:
  1f5580:      	adrp	x16, 0x203000
  1f5584:      	ldr	x17, [x16, #0xc70]
  1f5588:      	add	x16, x16, #0xc70
  1f558c:      	br	x17

00000000001f5590 <_ZN7MMCodec14OutMediaHandle4openEPKc@plt>:
  1f5590:      	adrp	x16, 0x203000
  1f5594:      	ldr	x17, [x16, #0xc78]
  1f5598:      	add	x16, x16, #0xc78
  1f559c:      	br	x17

00000000001f55a0 <_ZN7MMCodec14OutMediaHandle11addMetaDataEPKcS2_NS_12CONTEXT_TYPEE@plt>:
  1f55a0:      	adrp	x16, 0x203000
  1f55a4:      	ldr	x17, [x16, #0xc80]
  1f55a8:      	add	x16, x16, #0xc80
  1f55ac:      	br	x17

00000000001f55b0 <_ZN7MMCodec14OutMediaHandle13setAttributesERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEE@plt>:
  1f55b0:      	adrp	x16, 0x203000
  1f55b4:      	ldr	x17, [x16, #0xc88]
  1f55b8:      	add	x16, x16, #0xc88
  1f55bc:      	br	x17

00000000001f55c0 <_ZN7MMCodec14OutMediaHandle5startERNS_10MediaParamEPNS_19EncodeConfigureInfoE@plt>:
  1f55c0:      	adrp	x16, 0x203000
  1f55c4:      	ldr	x17, [x16, #0xc90]
  1f55c8:      	add	x16, x16, #0xc90
  1f55cc:      	br	x17

00000000001f55d0 <_ZN7MMCodec13MediaRecorder10getContextEv@plt>:
  1f55d0:      	adrp	x16, 0x203000
  1f55d4:      	ldr	x17, [x16, #0xc98]
  1f55d8:      	add	x16, x16, #0xc98
  1f55dc:      	br	x17

00000000001f55e0 <_ZN7MMCodec13MediaRecorder11recordAudioEPhi@plt>:
  1f55e0:      	adrp	x16, 0x203000
  1f55e4:      	ldr	x17, [x16, #0xca0]
  1f55e8:      	add	x16, x16, #0xca0
  1f55ec:      	br	x17

00000000001f55f0 <_ZN7MMCodec19AICodecSampleBuffer6createENS_22AICodecSampleMediaTypeE@plt>:
  1f55f0:      	adrp	x16, 0x203000
  1f55f4:      	ldr	x17, [x16, #0xca8]
  1f55f8:      	add	x16, x16, #0xca8
  1f55fc:      	br	x17

00000000001f5600 <_ZN7MMCodec28AICodecFFmpegAudioDataBuffer6createEPKv@plt>:
  1f5600:      	adrp	x16, 0x203000
  1f5604:      	ldr	x17, [x16, #0xcb0]
  1f5608:      	add	x16, x16, #0xcb0
  1f560c:      	br	x17

00000000001f5610 <_ZN7MMCodec19AICodecSampleBuffer13setDataBufferEPNS_17AICodecDataBufferE@plt>:
  1f5610:      	adrp	x16, 0x203000
  1f5614:      	ldr	x17, [x16, #0xcb8]
  1f5618:      	add	x16, x16, #0xcb8
  1f561c:      	br	x17

00000000001f5620 <_ZNK7MMCodec19AICodecSampleBuffer13getDataBufferEv@plt>:
  1f5620:      	adrp	x16, 0x203000
  1f5624:      	ldr	x17, [x16, #0xcc0]
  1f5628:      	add	x16, x16, #0xcc0
  1f562c:      	br	x17

00000000001f5630 <_ZN7MMCodec13MediaRecorder23recordAudioSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE@plt>:
  1f5630:      	adrp	x16, 0x203000
  1f5634:      	ldr	x17, [x16, #0xcc8]
  1f5638:      	add	x16, x16, #0xcc8
  1f563c:      	br	x17

00000000001f5640 <_ZNK7MMCodec19AICodecSampleBuffer12getMediaTypeEv@plt>:
  1f5640:      	adrp	x16, 0x203000
  1f5644:      	ldr	x17, [x16, #0xcd0]
  1f5648:      	add	x16, x16, #0xcd0
  1f564c:      	br	x17

00000000001f5650 <_ZNK7MMCodec28AICodecFFmpegAudioDataBuffer18getAudioBufferSizeEv@plt>:
  1f5650:      	adrp	x16, 0x203000
  1f5654:      	ldr	x17, [x16, #0xcd8]
  1f5658:      	add	x16, x16, #0xcd8
  1f565c:      	br	x17

00000000001f5660 <_ZNK7MMCodec28AICodecFFmpegAudioDataBuffer14getAudioBufferEv@plt>:
  1f5660:      	adrp	x16, 0x203000
  1f5664:      	ldr	x17, [x16, #0xce0]
  1f5668:      	add	x16, x16, #0xce0
  1f566c:      	br	x17

00000000001f5670 <_ZN7MMCodec14OutMediaHandle8sendDataEPPhmPmlNS_11MediaType_tENSt6__ndk18functionIFvvEEE@plt>:
  1f5670:      	adrp	x16, 0x203000
  1f5674:      	ldr	x17, [x16, #0xce8]
  1f5678:      	add	x16, x16, #0xce8
  1f567c:      	br	x17

00000000001f5680 <_ZN7MMCodec13MediaRecorder18recordSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE@plt>:
  1f5680:      	adrp	x16, 0x203000
  1f5684:      	ldr	x17, [x16, #0xcf0]
  1f5688:      	add	x16, x16, #0xcf0
  1f568c:      	br	x17

00000000001f5690 <_ZN7MMCodec13MediaRecorder23recordVideoSampleBufferERNS_19AICodecSampleBufferENSt6__ndk18functionIFvvEEE@plt>:
  1f5690:      	adrp	x16, 0x203000
  1f5694:      	ldr	x17, [x16, #0xcf8]
  1f5698:      	add	x16, x16, #0xcf8
  1f569c:      	br	x17

00000000001f56a0 <_ZNK7MMCodec19AICodecSampleBuffer24getPresentationTimestampEv@plt>:
  1f56a0:      	adrp	x16, 0x203000
  1f56a4:      	ldr	x17, [x16, #0xd00]
  1f56a8:      	add	x16, x16, #0xd00
  1f56ac:      	br	x17

00000000001f56b0 <_ZN7MMCodec13MediaRecorder11recordVideoEPvdNSt6__ndk18functionIFvvEEE@plt>:
  1f56b0:      	adrp	x16, 0x203000
  1f56b4:      	ldr	x17, [x16, #0xd08]
  1f56b8:      	add	x16, x16, #0xd08
  1f56bc:      	br	x17

00000000001f56c0 <_ZN7MMCodec22AICodecVideoDataBufferC1EmmNS_16VIDEO_PIX_FORMATENS_14ColorSpaceTypeE@plt>:
  1f56c0:      	adrp	x16, 0x203000
  1f56c4:      	ldr	x17, [x16, #0xd10]
  1f56c8:      	add	x16, x16, #0xd10
  1f56cc:      	br	x17

00000000001f56d0 <_ZN7MMCodec19AICodecSampleBuffer24setPresentationTimestampEl@plt>:
  1f56d0:      	adrp	x16, 0x203000
  1f56d4:      	ldr	x17, [x16, #0xd18]
  1f56d8:      	add	x16, x16, #0xd18
  1f56dc:      	br	x17

00000000001f56e0 <_ZN7MMCodec13MediaRecorder11recordVideoEidNSt6__ndk18functionIFvvEEE@plt>:
  1f56e0:      	adrp	x16, 0x203000
  1f56e4:      	ldr	x17, [x16, #0xd20]
  1f56e8:      	add	x16, x16, #0xd20
  1f56ec:      	br	x17

00000000001f56f0 <eglGetCurrentContext@plt>:
  1f56f0:      	adrp	x16, 0x203000
  1f56f4:      	ldr	x17, [x16, #0xd28]
  1f56f8:      	add	x16, x16, #0xd28
  1f56fc:      	br	x17

00000000001f5700 <glGetIntegerv@plt>:
  1f5700:      	adrp	x16, 0x203000
  1f5704:      	ldr	x17, [x16, #0xd30]
  1f5708:      	add	x16, x16, #0xd30
  1f570c:      	br	x17

00000000001f5710 <_ZN7MMCodec8GLShaderC1Ev@plt>:
  1f5710:      	adrp	x16, 0x203000
  1f5714:      	ldr	x17, [x16, #0xd38]
  1f5718:      	add	x16, x16, #0xd38
  1f571c:      	br	x17

00000000001f5720 <_ZN7MMCodec8GLShader18initWithByteArraysERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
  1f5720:      	adrp	x16, 0x203000
  1f5724:      	ldr	x17, [x16, #0xd40]
  1f5728:      	add	x16, x16, #0xd40
  1f572c:      	br	x17

00000000001f5730 <_ZN7MMCodec19GLFramebufferObjectC1Eb@plt>:
  1f5730:      	adrp	x16, 0x203000
  1f5734:      	ldr	x17, [x16, #0xd48]
  1f5738:      	add	x16, x16, #0xd48
  1f573c:      	br	x17

00000000001f5740 <_ZNK7MMCodec19GLFramebufferObject6enableEv@plt>:
  1f5740:      	adrp	x16, 0x203000
  1f5744:      	ldr	x17, [x16, #0xd50]
  1f5748:      	add	x16, x16, #0xd50
  1f574c:      	br	x17

00000000001f5750 <_ZN7MMCodec12UniformValueC1Eji@plt>:
  1f5750:      	adrp	x16, 0x203000
  1f5754:      	ldr	x17, [x16, #0xd58]
  1f5758:      	add	x16, x16, #0xd58
  1f575c:      	br	x17

00000000001f5760 <_ZN7MMCodec12UniformValueD1Ev@plt>:
  1f5760:      	adrp	x16, 0x203000
  1f5764:      	ldr	x17, [x16, #0xd60]
  1f5768:      	add	x16, x16, #0xd60
  1f576c:      	br	x17

00000000001f5770 <_ZN7MMCodec19GLFramebufferObject15getRGBAWithSizeEiiRPhRmRi@plt>:
  1f5770:      	adrp	x16, 0x203000
  1f5774:      	ldr	x17, [x16, #0xd68]
  1f5778:      	add	x16, x16, #0xd68
  1f577c:      	br	x17

00000000001f5780 <glBindFramebuffer@plt>:
  1f5780:      	adrp	x16, 0x203000
  1f5784:      	ldr	x17, [x16, #0xd70]
  1f5788:      	add	x16, x16, #0xd70
  1f578c:      	br	x17

00000000001f5790 <glViewport@plt>:
  1f5790:      	adrp	x16, 0x203000
  1f5794:      	ldr	x17, [x16, #0xd78]
  1f5798:      	add	x16, x16, #0xd78
  1f579c:      	br	x17

00000000001f57a0 <_ZN7MMCodec14OutMediaHandle7sendPtsElNS_11MediaType_tE@plt>:
  1f57a0:      	adrp	x16, 0x203000
  1f57a4:      	ldr	x17, [x16, #0xd80]
  1f57a8:      	add	x16, x16, #0xd80
  1f57ac:      	br	x17

00000000001f57b0 <_ZN7MMCodec13MediaRecorder24getRenderablePixelBufferEv@plt>:
  1f57b0:      	adrp	x16, 0x203000
  1f57b4:      	ldr	x17, [x16, #0xd88]
  1f57b8:      	add	x16, x16, #0xd88
  1f57bc:      	br	x17

00000000001f57c0 <_ZN7MMCodec14OutMediaHandle18getRenderablePixelEi@plt>:
  1f57c0:      	adrp	x16, 0x203000
  1f57c4:      	ldr	x17, [x16, #0xd90]
  1f57c8:      	add	x16, x16, #0xd90
  1f57cc:      	br	x17

00000000001f57d0 <_ZN7MMCodec13MediaRecorder13getCVTexturesEm@plt>:
  1f57d0:      	adrp	x16, 0x203000
  1f57d4:      	ldr	x17, [x16, #0xd98]
  1f57d8:      	add	x16, x16, #0xd98
  1f57dc:      	br	x17

00000000001f57e0 <_ZN7MMCodec13MediaRecorder6finishEb@plt>:
  1f57e0:      	adrp	x16, 0x203000
  1f57e4:      	ldr	x17, [x16, #0xda0]
  1f57e8:      	add	x16, x16, #0xda0
  1f57ec:      	br	x17

00000000001f57f0 <_ZN7MMCodec14OutMediaHandle6finishEPNS_21EncodePerformanceInfoE@plt>:
  1f57f0:      	adrp	x16, 0x203000
  1f57f4:      	ldr	x17, [x16, #0xda8]
  1f57f8:      	add	x16, x16, #0xda8
  1f57fc:      	br	x17

00000000001f5800 <_ZN7MMCodec13MediaRecorder5closeEv@plt>:
  1f5800:      	adrp	x16, 0x203000
  1f5804:      	ldr	x17, [x16, #0xdb0]
  1f5808:      	add	x16, x16, #0xdb0
  1f580c:      	br	x17

00000000001f5810 <_ZN7MMCodec14OutMediaHandle7cleanupEv@plt>:
  1f5810:      	adrp	x16, 0x203000
  1f5814:      	ldr	x17, [x16, #0xdb8]
  1f5818:      	add	x16, x16, #0xdb8
  1f581c:      	br	x17

00000000001f5820 <_ZN7MMCodec13MediaRecorder18didEnterBackgroundEv@plt>:
  1f5820:      	adrp	x16, 0x203000
  1f5824:      	ldr	x17, [x16, #0xdc0]
  1f5828:      	add	x16, x16, #0xdc0
  1f582c:      	br	x17

00000000001f5830 <_ZN7MMCodec14OutMediaHandle18didEnterBackgroundEv@plt>:
  1f5830:      	adrp	x16, 0x203000
  1f5834:      	ldr	x17, [x16, #0xdc8]
  1f5838:      	add	x16, x16, #0xdc8
  1f583c:      	br	x17

00000000001f5840 <_ZN7MMCodec13MediaRecorder14restartEncoderEv@plt>:
  1f5840:      	adrp	x16, 0x203000
  1f5844:      	ldr	x17, [x16, #0xdd0]
  1f5848:      	add	x16, x16, #0xdd0
  1f584c:      	br	x17

00000000001f5850 <_ZN7MMCodec14OutMediaHandle14restartEncoderEv@plt>:
  1f5850:      	adrp	x16, 0x203000
  1f5854:      	ldr	x17, [x16, #0xdd8]
  1f5858:      	add	x16, x16, #0xdd8
  1f585c:      	br	x17

00000000001f5860 <_ZN7MMCodec13MediaRecorder20enableAsyncSendVideoEb@plt>:
  1f5860:      	adrp	x16, 0x203000
  1f5864:      	ldr	x17, [x16, #0xde0]
  1f5868:      	add	x16, x16, #0xde0
  1f586c:      	br	x17

00000000001f5870 <_ZN7MMCodec13MediaRecorder15enableFastStartEb@plt>:
  1f5870:      	adrp	x16, 0x203000
  1f5874:      	ldr	x17, [x16, #0xde8]
  1f5878:      	add	x16, x16, #0xde8
  1f587c:      	br	x17

00000000001f5880 <_ZN7MMCodec13MediaRecorder6resumeEv@plt>:
  1f5880:      	adrp	x16, 0x203000
  1f5884:      	ldr	x17, [x16, #0xdf0]
  1f5888:      	add	x16, x16, #0xdf0
  1f588c:      	br	x17

00000000001f5890 <_ZN7MMCodec13MediaRecorder22getEncodeConfigureInfoEv@plt>:
  1f5890:      	adrp	x16, 0x203000
  1f5894:      	ldr	x17, [x16, #0xdf8]
  1f5898:      	add	x16, x16, #0xdf8
  1f589c:      	br	x17

00000000001f58a0 <_ZN7MMCodec13MediaRecorder24getEncodePerformanceInfoEv@plt>:
  1f58a0:      	adrp	x16, 0x203000
  1f58a4:      	ldr	x17, [x16, #0xe00]
  1f58a8:      	add	x16, x16, #0xe00
  1f58ac:      	br	x17

00000000001f58b0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  1f58b0:      	adrp	x16, 0x203000
  1f58b4:      	ldr	x17, [x16, #0xe08]
  1f58b8:      	add	x16, x16, #0xe08
  1f58bc:      	br	x17

00000000001f58c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  1f58c0:      	adrp	x16, 0x203000
  1f58c4:      	ldr	x17, [x16, #0xe10]
  1f58c8:      	add	x16, x16, #0xe10
  1f58cc:      	br	x17

00000000001f58d0 <_ZN7MMCodec13MediaRecorderC1EPNS_14AICodecContextEPKcRKNS_10MediaParamE@plt>:
  1f58d0:      	adrp	x16, 0x203000
  1f58d4:      	ldr	x17, [x16, #0xe18]
  1f58d8:      	add	x16, x16, #0xe18
  1f58dc:      	br	x17

00000000001f58e0 <_ZN7MMCodec13MediaRecorderD1Ev@plt>:
  1f58e0:      	adrp	x16, 0x203000
  1f58e4:      	ldr	x17, [x16, #0xe20]
  1f58e8:      	add	x16, x16, #0xe20
  1f58ec:      	br	x17

00000000001f58f0 <av_mallocz@plt>:
  1f58f0:      	adrp	x16, 0x203000
  1f58f4:      	ldr	x17, [x16, #0xe28]
  1f58f8:      	add	x16, x16, #0xe28
  1f58fc:      	br	x17

00000000001f5900 <avio_alloc_context@plt>:
  1f5900:      	adrp	x16, 0x203000
  1f5904:      	ldr	x17, [x16, #0xe30]
  1f5908:      	add	x16, x16, #0xe30
  1f590c:      	br	x17

00000000001f5910 <av_free@plt>:
  1f5910:      	adrp	x16, 0x203000
  1f5914:      	ldr	x17, [x16, #0xe38]
  1f5918:      	add	x16, x16, #0xe38
  1f591c:      	br	x17

00000000001f5920 <_ZN7MMCodec14OutMediaHandle4stopEv@plt>:
  1f5920:      	adrp	x16, 0x203000
  1f5924:      	ldr	x17, [x16, #0xe40]
  1f5928:      	add	x16, x16, #0xe40
  1f592c:      	br	x17

00000000001f5930 <_ZN7MMCodec13ThreadContext4stopEv@plt>:
  1f5930:      	adrp	x16, 0x203000
  1f5934:      	ldr	x17, [x16, #0xe48]
  1f5938:      	add	x16, x16, #0xe48
  1f593c:      	br	x17

00000000001f5940 <_ZN7MMCodec13ThreadContext4joinEv@plt>:
  1f5940:      	adrp	x16, 0x203000
  1f5944:      	ldr	x17, [x16, #0xe50]
  1f5948:      	add	x16, x16, #0xe50
  1f594c:      	br	x17

00000000001f5950 <_ZN7MMCodec13ThreadContextD1Ev@plt>:
  1f5950:      	adrp	x16, 0x203000
  1f5954:      	ldr	x17, [x16, #0xe58]
  1f5958:      	add	x16, x16, #0xe58
  1f595c:      	br	x17

00000000001f5960 <_ZN7MMCodec14OutMediaHandle13_writeTrailerEv@plt>:
  1f5960:      	adrp	x16, 0x203000
  1f5964:      	ldr	x17, [x16, #0xe60]
  1f5968:      	add	x16, x16, #0xe60
  1f596c:      	br	x17

00000000001f5970 <av_freep@plt>:
  1f5970:      	adrp	x16, 0x203000
  1f5974:      	ldr	x17, [x16, #0xe68]
  1f5978:      	add	x16, x16, #0xe68
  1f597c:      	br	x17

00000000001f5980 <avformat_alloc_output_context2@plt>:
  1f5980:      	adrp	x16, 0x203000
  1f5984:      	ldr	x17, [x16, #0xe70]
  1f5988:      	add	x16, x16, #0xe70
  1f598c:      	br	x17

00000000001f5990 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
  1f5990:      	adrp	x16, 0x203000
  1f5994:      	ldr	x17, [x16, #0xe78]
  1f5998:      	add	x16, x16, #0xe78
  1f599c:      	br	x17

00000000001f59a0 <avio_open@plt>:
  1f59a0:      	adrp	x16, 0x203000
  1f59a4:      	ldr	x17, [x16, #0xe80]
  1f59a8:      	add	x16, x16, #0xe80
  1f59ac:      	br	x17

00000000001f59b0 <_ZN7MMCodec14OutMediaHandle12_writeHeaderEv@plt>:
  1f59b0:      	adrp	x16, 0x203000
  1f59b4:      	ldr	x17, [x16, #0xe88]
  1f59b8:      	add	x16, x16, #0xe88
  1f59bc:      	br	x17

00000000001f59c0 <_ZN7MMCodec13ThreadContext5startEv@plt>:
  1f59c0:      	adrp	x16, 0x203000
  1f59c4:      	ldr	x17, [x16, #0xe90]
  1f59c8:      	add	x16, x16, #0xe90
  1f59cc:      	br	x17

00000000001f59d0 <_ZN7MMCodec18getFFmpegMediaTypeENS_11MediaType_tE@plt>:
  1f59d0:      	adrp	x16, 0x203000
  1f59d4:      	ldr	x17, [x16, #0xe98]
  1f59d8:      	add	x16, x16, #0xe98
  1f59dc:      	br	x17

00000000001f59e0 <_ZnwmRKSt9nothrow_t@plt>:
  1f59e0:      	adrp	x16, 0x203000
  1f59e4:      	ldr	x17, [x16, #0xea0]
  1f59e8:      	add	x16, x16, #0xea0
  1f59ec:      	br	x17

00000000001f59f0 <_ZN7MMCodec13ThreadContextC1Ev@plt>:
  1f59f0:      	adrp	x16, 0x203000
  1f59f4:      	ldr	x17, [x16, #0xea8]
  1f59f8:      	add	x16, x16, #0xea8
  1f59fc:      	br	x17

00000000001f5a00 <_ZN7MMCodec18AndroidVideoStream14getEncoderTypeEv@plt>:
  1f5a00:      	adrp	x16, 0x203000
  1f5a04:      	ldr	x17, [x16, #0xeb0]
  1f5a08:      	add	x16, x16, #0xeb0
  1f5a0c:      	br	x17

00000000001f5a10 <_ZN7MMCodec13ThreadContext11setFunctionEPFPvS1_ES1_PKc@plt>:
  1f5a10:      	adrp	x16, 0x203000
  1f5a14:      	ldr	x17, [x16, #0xeb8]
  1f5a18:      	add	x16, x16, #0xeb8
  1f5a1c:      	br	x17

00000000001f5a20 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
  1f5a20:      	adrp	x16, 0x203000
  1f5a24:      	ldr	x17, [x16, #0xec0]
  1f5a28:      	add	x16, x16, #0xec0
  1f5a2c:      	br	x17

00000000001f5a30 <_ZdlPvRKSt9nothrow_t@plt>:
  1f5a30:      	adrp	x16, 0x203000
  1f5a34:      	ldr	x17, [x16, #0xec8]
  1f5a38:      	add	x16, x16, #0xec8
  1f5a3c:      	br	x17

00000000001f5a40 <avformat_write_header@plt>:
  1f5a40:      	adrp	x16, 0x203000
  1f5a44:      	ldr	x17, [x16, #0xed0]
  1f5a48:      	add	x16, x16, #0xed0
  1f5a4c:      	br	x17

00000000001f5a50 <_ZN7MMCodec20AudioResamplerEffectC1Ev@plt>:
  1f5a50:      	adrp	x16, 0x203000
  1f5a54:      	ldr	x17, [x16, #0xed8]
  1f5a58:      	add	x16, x16, #0xed8
  1f5a5c:      	br	x17

00000000001f5a60 <av_audio_fifo_alloc@plt>:
  1f5a60:      	adrp	x16, 0x203000
  1f5a64:      	ldr	x17, [x16, #0xee0]
  1f5a68:      	add	x16, x16, #0xee0
  1f5a6c:      	br	x17

00000000001f5a70 <av_audio_fifo_write@plt>:
  1f5a70:      	adrp	x16, 0x203000
  1f5a74:      	ldr	x17, [x16, #0xee8]
  1f5a78:      	add	x16, x16, #0xee8
  1f5a7c:      	br	x17

00000000001f5a80 <av_frame_alloc@plt>:
  1f5a80:      	adrp	x16, 0x203000
  1f5a84:      	ldr	x17, [x16, #0xef0]
  1f5a88:      	add	x16, x16, #0xef0
  1f5a8c:      	br	x17

00000000001f5a90 <av_frame_get_buffer@plt>:
  1f5a90:      	adrp	x16, 0x203000
  1f5a94:      	ldr	x17, [x16, #0xef8]
  1f5a98:      	add	x16, x16, #0xef8
  1f5a9c:      	br	x17

00000000001f5aa0 <_ZN7MMCodec20AudioResamplerEffectD1Ev@plt>:
  1f5aa0:      	adrp	x16, 0x203000
  1f5aa4:      	ldr	x17, [x16, #0xf00]
  1f5aa8:      	add	x16, x16, #0xf00
  1f5aac:      	br	x17

00000000001f5ab0 <swr_alloc_set_opts2@plt>:
  1f5ab0:      	adrp	x16, 0x203000
  1f5ab4:      	ldr	x17, [x16, #0xf08]
  1f5ab8:      	add	x16, x16, #0xf08
  1f5abc:      	br	x17

00000000001f5ac0 <swr_init@plt>:
  1f5ac0:      	adrp	x16, 0x203000
  1f5ac4:      	ldr	x17, [x16, #0xf10]
  1f5ac8:      	add	x16, x16, #0xf10
  1f5acc:      	br	x17

00000000001f5ad0 <swr_free@plt>:
  1f5ad0:      	adrp	x16, 0x203000
  1f5ad4:      	ldr	x17, [x16, #0xf18]
  1f5ad8:      	add	x16, x16, #0xf18
  1f5adc:      	br	x17

00000000001f5ae0 <swr_get_delay@plt>:
  1f5ae0:      	adrp	x16, 0x203000
  1f5ae4:      	ldr	x17, [x16, #0xf20]
  1f5ae8:      	add	x16, x16, #0xf20
  1f5aec:      	br	x17

00000000001f5af0 <av_rescale_rnd@plt>:
  1f5af0:      	adrp	x16, 0x203000
  1f5af4:      	ldr	x17, [x16, #0xf28]
  1f5af8:      	add	x16, x16, #0xf28
  1f5afc:      	br	x17

00000000001f5b00 <swr_set_compensation@plt>:
  1f5b00:      	adrp	x16, 0x203000
  1f5b04:      	ldr	x17, [x16, #0xf30]
  1f5b08:      	add	x16, x16, #0xf30
  1f5b0c:      	br	x17

00000000001f5b10 <swr_convert@plt>:
  1f5b10:      	adrp	x16, 0x203000
  1f5b14:      	ldr	x17, [x16, #0xf38]
  1f5b18:      	add	x16, x16, #0xf38
  1f5b1c:      	br	x17

00000000001f5b20 <_ZN7MMCodec14AndroidEncoder6createENS_18AndroidEncoderTypeE@plt>:
  1f5b20:      	adrp	x16, 0x203000
  1f5b24:      	ldr	x17, [x16, #0xf40]
  1f5b28:      	add	x16, x16, #0xf40
  1f5b2c:      	br	x17

00000000001f5b30 <_ZN7MMCodec14AndroidEncoder25createAndroidPixelEncoderEv@plt>:
  1f5b30:      	adrp	x16, 0x203000
  1f5b34:      	ldr	x17, [x16, #0xf48]
  1f5b38:      	add	x16, x16, #0xf48
  1f5b3c:      	br	x17

00000000001f5b40 <_ZN7MMCodec14AndroidEncoder25createAndroidMediaEncoderEv@plt>:
  1f5b40:      	adrp	x16, 0x203000
  1f5b44:      	ldr	x17, [x16, #0xf50]
  1f5b48:      	add	x16, x16, #0xf50
  1f5b4c:      	br	x17

00000000001f5b50 <_ZN7MMCodec14AndroidEncoderC2ENS_18AndroidEncoderTypeE@plt>:
  1f5b50:      	adrp	x16, 0x203000
  1f5b54:      	ldr	x17, [x16, #0xf58]
  1f5b58:      	add	x16, x16, #0xf58
  1f5b5c:      	br	x17

00000000001f5b60 <_ZN7MMCodec14AndroidEncoderD2Ev@plt>:
  1f5b60:      	adrp	x16, 0x203000
  1f5b64:      	ldr	x17, [x16, #0xf60]
  1f5b68:      	add	x16, x16, #0xf60
  1f5b6c:      	br	x17

00000000001f5b70 <_ZN7MMCodec14AndroidEncoder13_initKeyValueEv@plt>:
  1f5b70:      	adrp	x16, 0x203000
  1f5b74:      	ldr	x17, [x16, #0xf68]
  1f5b78:      	add	x16, x16, #0xf68
  1f5b7c:      	br	x17

00000000001f5b80 <_ZN9JniHelper6getEnvEv@plt>:
  1f5b80:      	adrp	x16, 0x203000
  1f5b84:      	ldr	x17, [x16, #0xf70]
  1f5b88:      	add	x16, x16, #0xf70
  1f5b8c:      	br	x17

00000000001f5b90 <_ZN7MMCodec10JniUtility12getJavaClassEPKc@plt>:
  1f5b90:      	adrp	x16, 0x203000
  1f5b94:      	ldr	x17, [x16, #0xf78]
  1f5b98:      	add	x16, x16, #0xf78
  1f5b9c:      	br	x17

00000000001f5ba0 <_ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz@plt>:
  1f5ba0:      	adrp	x16, 0x203000
  1f5ba4:      	ldr	x17, [x16, #0xf80]
  1f5ba8:      	add	x16, x16, #0xf80
  1f5bac:      	br	x17

00000000001f5bb0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz@plt>:
  1f5bb0:      	adrp	x16, 0x203000
  1f5bb4:      	ldr	x17, [x16, #0xf88]
  1f5bb8:      	add	x16, x16, #0xf88
  1f5bbc:      	br	x17

00000000001f5bc0 <_ZN7_JNIEnv14CallVoidMethodEP8_jobjectP10_jmethodIDz@plt>:
  1f5bc0:      	adrp	x16, 0x203000
  1f5bc4:      	ldr	x17, [x16, #0xf90]
  1f5bc8:      	add	x16, x16, #0xf90
  1f5bcc:      	br	x17

00000000001f5bd0 <_ZN7MMCodec13AICodecGlobal11getInstanceEv@plt>:
  1f5bd0:      	adrp	x16, 0x203000
  1f5bd4:      	ldr	x17, [x16, #0xf98]
  1f5bd8:      	add	x16, x16, #0xf98
  1f5bdc:      	br	x17

00000000001f5be0 <_ZN7MMCodec13AICodecGlobal13getSDKVersionEv@plt>:
  1f5be0:      	adrp	x16, 0x203000
  1f5be4:      	ldr	x17, [x16, #0xfa0]
  1f5be8:      	add	x16, x16, #0xfa0
  1f5bec:      	br	x17

00000000001f5bf0 <_ZN7MMCodec13AICodecGlobal23getEncoderOperatingRateEv@plt>:
  1f5bf0:      	adrp	x16, 0x203000
  1f5bf4:      	ldr	x17, [x16, #0xfa8]
  1f5bf8:      	add	x16, x16, #0xfa8
  1f5bfc:      	br	x17

00000000001f5c00 <_ZN7MMCodec13AICodecGlobal11getHardwareEv@plt>:
  1f5c00:      	adrp	x16, 0x203000
  1f5c04:      	ldr	x17, [x16, #0xfb0]
  1f5c08:      	add	x16, x16, #0xfb0
  1f5c0c:      	br	x17

00000000001f5c10 <_ZN7_JNIEnv17CallBooleanMethodEP8_jobjectP10_jmethodIDz@plt>:
  1f5c10:      	adrp	x16, 0x203000
  1f5c14:      	ldr	x17, [x16, #0xfb8]
  1f5c18:      	add	x16, x16, #0xfb8
  1f5c1c:      	br	x17

00000000001f5c20 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz@plt>:
  1f5c20:      	adrp	x16, 0x203000
  1f5c24:      	ldr	x17, [x16, #0xfc0]
  1f5c28:      	add	x16, x16, #0xfc0
  1f5c2c:      	br	x17

00000000001f5c30 <_ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz@plt>:
  1f5c30:      	adrp	x16, 0x203000
  1f5c34:      	ldr	x17, [x16, #0xfc8]
  1f5c38:      	add	x16, x16, #0xfc8
  1f5c3c:      	br	x17

00000000001f5c40 <_ZN7_JNIEnv16CallObjectMethodEP8_jobjectP10_jmethodIDz@plt>:
  1f5c40:      	adrp	x16, 0x203000
  1f5c44:      	ldr	x17, [x16, #0xfd0]
  1f5c48:      	add	x16, x16, #0xfd0
  1f5c4c:      	br	x17

00000000001f5c50 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiiEENS_22__unordered_map_hasherIiS2_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS2_S7_S5_Lb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSI_IJEEEEEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS2_PvEEEEbEERKT_DpOT0_@plt>:
  1f5c50:      	adrp	x16, 0x203000
  1f5c54:      	ldr	x17, [x16, #0xfd8]
  1f5c58:      	add	x16, x16, #0xfd8
  1f5c5c:      	br	x17

00000000001f5c60 <_ZN7MMCodec14AndroidEncoder9codecOpenEPv@plt>:
  1f5c60:      	adrp	x16, 0x203000
  1f5c64:      	ldr	x17, [x16, #0xfe0]
  1f5c68:      	add	x16, x16, #0xfe0
  1f5c6c:      	br	x17

00000000001f5c70 <_ZN7MMCodec14AndroidEncoder10codecCloseEPNS_21EncodePerformanceInfoE@plt>:
  1f5c70:      	adrp	x16, 0x203000
  1f5c74:      	ldr	x17, [x16, #0xfe8]
  1f5c78:      	add	x16, x16, #0xfe8
  1f5c7c:      	br	x17

00000000001f5c80 <av_packet_unref@plt>:
  1f5c80:      	adrp	x16, 0x203000
  1f5c84:      	ldr	x17, [x16, #0xff0]
  1f5c88:      	add	x16, x16, #0xff0
  1f5c8c:      	br	x17

00000000001f5c90 <av_buffer_alloc@plt>:
  1f5c90:      	adrp	x16, 0x203000
  1f5c94:      	ldr	x17, [x16, #0xff8]
  1f5c98:      	add	x16, x16, #0xff8
  1f5c9c:      	br	x17

00000000001f5ca0 <av_malloc@plt>:
  1f5ca0:      	adrp	x16, 0x204000
  1f5ca4:      	ldr	x17, [x16]
  1f5ca8:      	add	x16, x16, #0x0
  1f5cac:      	br	x17

00000000001f5cb0 <_ZNK7MMCodec14AndroidEncoder14getEncoderTypeEv@plt>:
  1f5cb0:      	adrp	x16, 0x204000
  1f5cb4:      	ldr	x17, [x16, #0x8]
  1f5cb8:      	add	x16, x16, #0x8
  1f5cbc:      	br	x17

00000000001f5cc0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiiEENS_22__unordered_map_hasherIiS2_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS2_S7_S5_Lb1EEENS_9allocatorIS2_EEE11__do_rehashILb1EEEvm@plt>:
  1f5cc0:      	adrp	x16, 0x204000
  1f5cc4:      	ldr	x17, [x16, #0x10]
  1f5cc8:      	add	x16, x16, #0x10
  1f5ccc:      	br	x17

00000000001f5cd0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiiEENS_22__unordered_map_hasherIiS2_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS2_S7_S5_Lb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIiJRKNS_4pairIKiiEEEEENSF_INS_15__hash_iteratorIPNS_11__hash_nodeIS2_PvEEEEbEERKT_DpOT0_@plt>:
  1f5cd0:      	adrp	x16, 0x204000
  1f5cd4:      	ldr	x17, [x16, #0x18]
  1f5cd8:      	add	x16, x16, #0x18
  1f5cdc:      	br	x17

00000000001f5ce0 <_ZN7MMCodec19AndroidMediaEncoderC1Ev@plt>:
  1f5ce0:      	adrp	x16, 0x204000
  1f5ce4:      	ldr	x17, [x16, #0x20]
  1f5ce8:      	add	x16, x16, #0x20
  1f5cec:      	br	x17

00000000001f5cf0 <_ZN7MMCodec19AndroidMediaEncoderD1Ev@plt>:
  1f5cf0:      	adrp	x16, 0x204000
  1f5cf4:      	ldr	x17, [x16, #0x28]
  1f5cf8:      	add	x16, x16, #0x28
  1f5cfc:      	br	x17

00000000001f5d00 <eglGetCurrentDisplay@plt>:
  1f5d00:      	adrp	x16, 0x204000
  1f5d04:      	ldr	x17, [x16, #0x30]
  1f5d08:      	add	x16, x16, #0x30
  1f5d0c:      	br	x17

00000000001f5d10 <eglGetCurrentSurface@plt>:
  1f5d10:      	adrp	x16, 0x204000
  1f5d14:      	ldr	x17, [x16, #0x38]
  1f5d18:      	add	x16, x16, #0x38
  1f5d1c:      	br	x17

00000000001f5d20 <ANativeWindow_release@plt>:
  1f5d20:      	adrp	x16, 0x204000
  1f5d24:      	ldr	x17, [x16, #0x40]
  1f5d28:      	add	x16, x16, #0x40
  1f5d2c:      	br	x17

00000000001f5d30 <ANativeWindow_fromSurface@plt>:
  1f5d30:      	adrp	x16, 0x204000
  1f5d34:      	ldr	x17, [x16, #0x48]
  1f5d38:      	add	x16, x16, #0x48
  1f5d3c:      	br	x17

00000000001f5d40 <eglMakeCurrent@plt>:
  1f5d40:      	adrp	x16, 0x204000
  1f5d44:      	ldr	x17, [x16, #0x50]
  1f5d48:      	add	x16, x16, #0x50
  1f5d4c:      	br	x17

00000000001f5d50 <_ZN7MMCodec7EglCore18makeNothingCurrentEv@plt>:
  1f5d50:      	adrp	x16, 0x204000
  1f5d54:      	ldr	x17, [x16, #0x58]
  1f5d58:      	add	x16, x16, #0x58
  1f5d5c:      	br	x17

00000000001f5d60 <_ZN7MMCodec10ThreadPoolC1EmNSt6__ndk18functionIFvvEEES4_@plt>:
  1f5d60:      	adrp	x16, 0x204000
  1f5d64:      	ldr	x17, [x16, #0x60]
  1f5d68:      	add	x16, x16, #0x60
  1f5d6c:      	br	x17

00000000001f5d70 <_ZN7MMCodec10ThreadPoolD1Ev@plt>:
  1f5d70:      	adrp	x16, 0x204000
  1f5d74:      	ldr	x17, [x16, #0x68]
  1f5d78:      	add	x16, x16, #0x68
  1f5d7c:      	br	x17

00000000001f5d80 <_ZN7MMCodec14EglSurfaceBase11makeCurrentEv@plt>:
  1f5d80:      	adrp	x16, 0x204000
  1f5d84:      	ldr	x17, [x16, #0x70]
  1f5d88:      	add	x16, x16, #0x70
  1f5d8c:      	br	x17

00000000001f5d90 <_ZN7MMCodec14EglSurfaceBase19setPresentationTimeEl@plt>:
  1f5d90:      	adrp	x16, 0x204000
  1f5d94:      	ldr	x17, [x16, #0x78]
  1f5d98:      	add	x16, x16, #0x78
  1f5d9c:      	br	x17

00000000001f5da0 <glFinish@plt>:
  1f5da0:      	adrp	x16, 0x204000
  1f5da4:      	ldr	x17, [x16, #0x80]
  1f5da8:      	add	x16, x16, #0x80
  1f5dac:      	br	x17

00000000001f5db0 <_ZN7MMCodec14EglSurfaceBase11swapBuffersEv@plt>:
  1f5db0:      	adrp	x16, 0x204000
  1f5db4:      	ldr	x17, [x16, #0x88]
  1f5db8:      	add	x16, x16, #0x88
  1f5dbc:      	br	x17

00000000001f5dc0 <_ZNSt6__ndk17promiseIvEC1Ev@plt>:
  1f5dc0:      	adrp	x16, 0x204000
  1f5dc4:      	ldr	x17, [x16, #0x90]
  1f5dc8:      	add	x16, x16, #0x90
  1f5dcc:      	br	x17

00000000001f5dd0 <_ZNSt6__ndk16futureIvED1Ev@plt>:
  1f5dd0:      	adrp	x16, 0x204000
  1f5dd4:      	ldr	x17, [x16, #0x98]
  1f5dd8:      	add	x16, x16, #0x98
  1f5ddc:      	br	x17

00000000001f5de0 <_ZNSt6__ndk17promiseIvE10get_futureEv@plt>:
  1f5de0:      	adrp	x16, 0x204000
  1f5de4:      	ldr	x17, [x16, #0xa0]
  1f5de8:      	add	x16, x16, #0xa0
  1f5dec:      	br	x17

00000000001f5df0 <_ZN7MMCodec10ThreadPool18syncWaitQueueEmptyEv@plt>:
  1f5df0:      	adrp	x16, 0x204000
  1f5df4:      	ldr	x17, [x16, #0xa8]
  1f5df8:      	add	x16, x16, #0xa8
  1f5dfc:      	br	x17

00000000001f5e00 <_ZN7MMCodec7EglCoreC1Ev@plt>:
  1f5e00:      	adrp	x16, 0x204000
  1f5e04:      	ldr	x17, [x16, #0xb0]
  1f5e08:      	add	x16, x16, #0xb0
  1f5e0c:      	br	x17

00000000001f5e10 <_ZN7MMCodec7EglCore4initEPvib@plt>:
  1f5e10:      	adrp	x16, 0x204000
  1f5e14:      	ldr	x17, [x16, #0xb8]
  1f5e18:      	add	x16, x16, #0xb8
  1f5e1c:      	br	x17

00000000001f5e20 <_ZN7MMCodec13WindowSurfaceC1ENSt6__ndk110shared_ptrINS_7EglCoreEEE@plt>:
  1f5e20:      	adrp	x16, 0x204000
  1f5e24:      	ldr	x17, [x16, #0xc0]
  1f5e28:      	add	x16, x16, #0xc0
  1f5e2c:      	br	x17

00000000001f5e30 <_ZN7MMCodec13WindowSurface4initEP13ANativeWindow@plt>:
  1f5e30:      	adrp	x16, 0x204000
  1f5e34:      	ldr	x17, [x16, #0xc8]
  1f5e38:      	add	x16, x16, #0xc8
  1f5e3c:      	br	x17

00000000001f5e40 <_ZN7MMCodec14EglSurfaceBase18makeNothingCurrentEv@plt>:
  1f5e40:      	adrp	x16, 0x204000
  1f5e44:      	ldr	x17, [x16, #0xd0]
  1f5e48:      	add	x16, x16, #0xd0
  1f5e4c:      	br	x17

00000000001f5e50 <_ZNSt6__ndk17promiseIvED1Ev@plt>:
  1f5e50:      	adrp	x16, 0x204000
  1f5e54:      	ldr	x17, [x16, #0xd8]
  1f5e58:      	add	x16, x16, #0xd8
  1f5e5c:      	br	x17

00000000001f5e60 <_ZNSt13exception_ptrD1Ev@plt>:
  1f5e60:      	adrp	x16, 0x204000
  1f5e64:      	ldr	x17, [x16, #0xe0]
  1f5e68:      	add	x16, x16, #0xe0
  1f5e6c:      	br	x17

00000000001f5e70 <_ZNSt6__ndk17promiseIvE9set_valueEv@plt>:
  1f5e70:      	adrp	x16, 0x204000
  1f5e74:      	ldr	x17, [x16, #0xe8]
  1f5e78:      	add	x16, x16, #0xe8
  1f5e7c:      	br	x17

00000000001f5e80 <_ZSt17current_exceptionv@plt>:
  1f5e80:      	adrp	x16, 0x204000
  1f5e84:      	ldr	x17, [x16, #0xf0]
  1f5e88:      	add	x16, x16, #0xf0
  1f5e8c:      	br	x17

00000000001f5e90 <_ZNSt6__ndk17promiseIvE13set_exceptionESt13exception_ptr@plt>:
  1f5e90:      	adrp	x16, 0x204000
  1f5e94:      	ldr	x17, [x16, #0xf8]
  1f5e98:      	add	x16, x16, #0xf8
  1f5e9c:      	br	x17

00000000001f5ea0 <_ZNSt6__ndk115future_categoryEv@plt>:
  1f5ea0:      	adrp	x16, 0x204000
  1f5ea4:      	ldr	x17, [x16, #0x100]
  1f5ea8:      	add	x16, x16, #0x100
  1f5eac:      	br	x17

00000000001f5eb0 <_ZNSt6__ndk112future_errorC1ENS_10error_codeE@plt>:
  1f5eb0:      	adrp	x16, 0x204000
  1f5eb4:      	ldr	x17, [x16, #0x108]
  1f5eb8:      	add	x16, x16, #0x108
  1f5ebc:      	br	x17

00000000001f5ec0 <_ZN7MMCodec19AndroidPixelEncoderC1Ev@plt>:
  1f5ec0:      	adrp	x16, 0x204000
  1f5ec4:      	ldr	x17, [x16, #0x110]
  1f5ec8:      	add	x16, x16, #0x110
  1f5ecc:      	br	x17

00000000001f5ed0 <_ZN7MMCodec19AndroidPixelEncoderD1Ev@plt>:
  1f5ed0:      	adrp	x16, 0x204000
  1f5ed4:      	ldr	x17, [x16, #0x118]
  1f5ed8:      	add	x16, x16, #0x118
  1f5edc:      	br	x17

00000000001f5ee0 <_ZN7MMCodec32getPlaneWidthAndHeightWithFormatENS_16VIDEO_PIX_FORMATEmmPmS1_@plt>:
  1f5ee0:      	adrp	x16, 0x204000
  1f5ee4:      	ldr	x17, [x16, #0x120]
  1f5ee8:      	add	x16, x16, #0x120
  1f5eec:      	br	x17

00000000001f5ef0 <_ZN7MMCodec18AndroidVideoStreamD1Ev@plt>:
  1f5ef0:      	adrp	x16, 0x204000
  1f5ef4:      	ldr	x17, [x16, #0x128]
  1f5ef8:      	add	x16, x16, #0x128
  1f5efc:      	br	x17

00000000001f5f00 <_ZN7MMCodec14AICodecContext18getSharedGLContextEv@plt>:
  1f5f00:      	adrp	x16, 0x204000
  1f5f04:      	ldr	x17, [x16, #0x130]
  1f5f08:      	add	x16, x16, #0x130
  1f5f0c:      	br	x17

00000000001f5f10 <_ZN7MMCodec14AndroidDecoder6createENS_18AndroidDecoderTypeE@plt>:
  1f5f10:      	adrp	x16, 0x204000
  1f5f14:      	ldr	x17, [x16, #0x138]
  1f5f18:      	add	x16, x16, #0x138
  1f5f1c:      	br	x17

00000000001f5f20 <_ZN7MMCodec14AndroidDecoder25createAndroidPixelDecoderEv@plt>:
  1f5f20:      	adrp	x16, 0x204000
  1f5f24:      	ldr	x17, [x16, #0x140]
  1f5f28:      	add	x16, x16, #0x140
  1f5f2c:      	br	x17

00000000001f5f30 <_ZN7MMCodec14AndroidDecoder25createAndroidMediaDecoderEv@plt>:
  1f5f30:      	adrp	x16, 0x204000
  1f5f34:      	ldr	x17, [x16, #0x148]
  1f5f38:      	add	x16, x16, #0x148
  1f5f3c:      	br	x17

00000000001f5f40 <_ZN7MMCodec14AndroidDecoderC2Ev@plt>:
  1f5f40:      	adrp	x16, 0x204000
  1f5f44:      	ldr	x17, [x16, #0x150]
  1f5f48:      	add	x16, x16, #0x150
  1f5f4c:      	br	x17

00000000001f5f50 <_ZN7MMCodec14AndroidDecoderD2Ev@plt>:
  1f5f50:      	adrp	x16, 0x204000
  1f5f54:      	ldr	x17, [x16, #0x158]
  1f5f58:      	add	x16, x16, #0x158
  1f5f5c:      	br	x17

00000000001f5f60 <_ZN7MMCodec17ffmpegToMTCodecIDE9AVCodecID@plt>:
  1f5f60:      	adrp	x16, 0x204000
  1f5f64:      	ldr	x17, [x16, #0x160]
  1f5f68:      	add	x16, x16, #0x160
  1f5f6c:      	br	x17

00000000001f5f70 <_ZN7MMCodec14AndroidDecoder9codecOpenEPv@plt>:
  1f5f70:      	adrp	x16, 0x204000
  1f5f74:      	ldr	x17, [x16, #0x168]
  1f5f78:      	add	x16, x16, #0x168
  1f5f7c:      	br	x17

00000000001f5f80 <_ZN7MMCodec14AndroidDecoder10codecCloseEv@plt>:
  1f5f80:      	adrp	x16, 0x204000
  1f5f84:      	ldr	x17, [x16, #0x170]
  1f5f88:      	add	x16, x16, #0x170
  1f5f8c:      	br	x17

00000000001f5f90 <_ZN7MMCodec14AndroidDecoder19deleteAdditionCodecEv@plt>:
  1f5f90:      	adrp	x16, 0x204000
  1f5f94:      	ldr	x17, [x16, #0x178]
  1f5f98:      	add	x16, x16, #0x178
  1f5f9c:      	br	x17

00000000001f5fa0 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz@plt>:
  1f5fa0:      	adrp	x16, 0x204000
  1f5fa4:      	ldr	x17, [x16, #0x180]
  1f5fa8:      	add	x16, x16, #0x180
  1f5fac:      	br	x17

00000000001f5fb0 <_ZN7MMCodec8protocol14parseFrameTypeEPhiiRiS2_@plt>:
  1f5fb0:      	adrp	x16, 0x204000
  1f5fb4:      	ldr	x17, [x16, #0x188]
  1f5fb8:      	add	x16, x16, #0x188
  1f5fbc:      	br	x17

00000000001f5fc0 <_ZN7MMCodec10FrameQueue15leftBufferFrameEv@plt>:
  1f5fc0:      	adrp	x16, 0x204000
  1f5fc4:      	ldr	x17, [x16, #0x190]
  1f5fc8:      	add	x16, x16, #0x190
  1f5fcc:      	br	x17

00000000001f5fd0 <_ZN7MMCodec10FrameQueue12peekWritableERPNS_12MMCodecFrameE@plt>:
  1f5fd0:      	adrp	x16, 0x204000
  1f5fd4:      	ldr	x17, [x16, #0x198]
  1f5fd8:      	add	x16, x16, #0x198
  1f5fdc:      	br	x17

00000000001f5fe0 <_ZN7MMCodec8protocol11shift_countEh@plt>:
  1f5fe0:      	adrp	x16, 0x204000
  1f5fe4:      	ldr	x17, [x16, #0x1a0]
  1f5fe8:      	add	x16, x16, #0x1a0
  1f5fec:      	br	x17

00000000001f5ff0 <_ZN7MMCodec14AndroidDecoder11resetStatusEv@plt>:
  1f5ff0:      	adrp	x16, 0x204000
  1f5ff4:      	ldr	x17, [x16, #0x1a8]
  1f5ff8:      	add	x16, x16, #0x1a8
  1f5ffc:      	br	x17

00000000001f6000 <_ZN7MMCodec13AICodecGlobal23getDecoderOperatingRateEv@plt>:
  1f6000:      	adrp	x16, 0x204000
  1f6004:      	ldr	x17, [x16, #0x1b0]
  1f6008:      	add	x16, x16, #0x1b0
  1f600c:      	br	x17

00000000001f6010 <_ZN7MMCodec14AndroidDecoder12initKeyValueEv@plt>:
  1f6010:      	adrp	x16, 0x204000
  1f6014:      	ldr	x17, [x16, #0x1b8]
  1f6018:      	add	x16, x16, #0x1b8
  1f601c:      	br	x17

00000000001f6020 <_ZN7MMCodec8protocol14parseVPSLayersEPh@plt>:
  1f6020:      	adrp	x16, 0x204000
  1f6024:      	ldr	x17, [x16, #0x1c0]
  1f6028:      	add	x16, x16, #0x1c0
  1f602c:      	br	x17

00000000001f6030 <_ZN7MMCodec14AndroidDecoder17needAdditionCodecEP7_JNIEnvP8_jstring@plt>:
  1f6030:      	adrp	x16, 0x204000
  1f6034:      	ldr	x17, [x16, #0x1c8]
  1f6038:      	add	x16, x16, #0x1c8
  1f603c:      	br	x17

00000000001f6040 <_ZN7MMCodec13AICodecGlobal27getEnableAdditionMediaCodecEv@plt>:
  1f6040:      	adrp	x16, 0x204000
  1f6044:      	ldr	x17, [x16, #0x1d0]
  1f6048:      	add	x16, x16, #0x1d0
  1f604c:      	br	x17

00000000001f6050 <_ZN7MMCodec14AndroidDecoder16newAdditionCodecEP8_jstringS2_P8_jobject@plt>:
  1f6050:      	adrp	x16, 0x204000
  1f6054:      	ldr	x17, [x16, #0x1d8]
  1f6058:      	add	x16, x16, #0x1d8
  1f605c:      	br	x17

00000000001f6060 <_ZN7MMCodec19AndroidMediaDecoderC1Ev@plt>:
  1f6060:      	adrp	x16, 0x204000
  1f6064:      	ldr	x17, [x16, #0x1e0]
  1f6068:      	add	x16, x16, #0x1e0
  1f606c:      	br	x17

00000000001f6070 <_ZN7MMCodec19AndroidMediaDecoderD1Ev@plt>:
  1f6070:      	adrp	x16, 0x204000
  1f6074:      	ldr	x17, [x16, #0x1e8]
  1f6078:      	add	x16, x16, #0x1e8
  1f607c:      	br	x17

00000000001f6080 <av_frame_unref@plt>:
  1f6080:      	adrp	x16, 0x204000
  1f6084:      	ldr	x17, [x16, #0x1f0]
  1f6088:      	add	x16, x16, #0x1f0
  1f608c:      	br	x17

00000000001f6090 <_ZN7MMCodec12UniformValueC1EPfi@plt>:
  1f6090:      	adrp	x16, 0x204000
  1f6094:      	ldr	x17, [x16, #0x1f8]
  1f6098:      	add	x16, x16, #0x1f8
  1f609c:      	br	x17

00000000001f60a0 <_ZN7MMCodec12UniformValueC1Ejib@plt>:
  1f60a0:      	adrp	x16, 0x204000
  1f60a4:      	ldr	x17, [x16, #0x200]
  1f60a8:      	add	x16, x16, #0x200
  1f60ac:      	br	x17

00000000001f60b0 <_ZN7MMCodec12UniformValueC1Ei@plt>:
  1f60b0:      	adrp	x16, 0x204000
  1f60b4:      	ldr	x17, [x16, #0x208]
  1f60b8:      	add	x16, x16, #0x208
  1f60bc:      	br	x17

00000000001f60c0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIPN7MMCodec13TextureVFrameEiEENS_22__unordered_map_hasherIS4_S5_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S5_SA_S8_Lb1EEENS_9allocatorIS5_EEE25__emplace_unique_key_argsIS4_JNS_4pairIS4_iEEEEENSI_INS_15__hash_iteratorIPNS_11__hash_nodeIS5_PvEEEEbEERKT_DpOT0_@plt>:
  1f60c0:      	adrp	x16, 0x204000
  1f60c4:      	ldr	x17, [x16, #0x210]
  1f60c8:      	add	x16, x16, #0x210
  1f60cc:      	br	x17

00000000001f60d0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIPN7MMCodec13TextureVFrameEiEENS_22__unordered_map_hasherIS4_S5_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S5_SA_S8_Lb1EEENS_9allocatorIS5_EEE4findIS4_EENS_15__hash_iteratorIPNS_11__hash_nodeIS5_PvEEEERKT_@plt>:
  1f60d0:      	adrp	x16, 0x204000
  1f60d4:      	ldr	x17, [x16, #0x218]
  1f60d8:      	add	x16, x16, #0x218
  1f60dc:      	br	x17

00000000001f60e0 <_ZN7MMCodec14EglSurfaceBaseC1ENSt6__ndk110shared_ptrINS_7EglCoreEEE@plt>:
  1f60e0:      	adrp	x16, 0x204000
  1f60e4:      	ldr	x17, [x16, #0x220]
  1f60e8:      	add	x16, x16, #0x220
  1f60ec:      	br	x17

00000000001f60f0 <_ZN7MMCodec14EglSurfaceBase20createPBufferSurfaceEii@plt>:
  1f60f0:      	adrp	x16, 0x204000
  1f60f4:      	ldr	x17, [x16, #0x228]
  1f60f8:      	add	x16, x16, #0x228
  1f60fc:      	br	x17

00000000001f6100 <_ZNSt6__ndk115__thread_structC1Ev@plt>:
  1f6100:      	adrp	x16, 0x204000
  1f6104:      	ldr	x17, [x16, #0x230]
  1f6108:      	add	x16, x16, #0x230
  1f610c:      	br	x17

00000000001f6110 <pthread_create@plt>:
  1f6110:      	adrp	x16, 0x204000
  1f6114:      	ldr	x17, [x16, #0x238]
  1f6118:      	add	x16, x16, #0x238
  1f611c:      	br	x17

00000000001f6120 <_ZNSt6__ndk16thread6detachEv@plt>:
  1f6120:      	adrp	x16, 0x204000
  1f6124:      	ldr	x17, [x16, #0x240]
  1f6128:      	add	x16, x16, #0x240
  1f612c:      	br	x17

00000000001f6130 <_ZNSt6__ndk16threadD1Ev@plt>:
  1f6130:      	adrp	x16, 0x204000
  1f6134:      	ldr	x17, [x16, #0x248]
  1f6138:      	add	x16, x16, #0x248
  1f613c:      	br	x17

00000000001f6140 <_ZNSt6__ndk120__throw_system_errorEiPKc@plt>:
  1f6140:      	adrp	x16, 0x204000
  1f6144:      	ldr	x17, [x16, #0x250]
  1f6148:      	add	x16, x16, #0x250
  1f614c:      	br	x17

00000000001f6150 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIPN7MMCodec13TextureVFrameEiEENS_22__unordered_map_hasherIS4_S5_NS_4hashIS4_EENS_8equal_toIS4_EELb1EEENS_21__unordered_map_equalIS4_S5_SA_S8_Lb1EEENS_9allocatorIS5_EEE11__do_rehashILb1EEEvm@plt>:
  1f6150:      	adrp	x16, 0x204000
  1f6154:      	ldr	x17, [x16, #0x258]
  1f6158:      	add	x16, x16, #0x258
  1f615c:      	br	x17

00000000001f6160 <_ZNSt6__ndk119__thread_local_dataEv@plt>:
  1f6160:      	adrp	x16, 0x204000
  1f6164:      	ldr	x17, [x16, #0x260]
  1f6168:      	add	x16, x16, #0x260
  1f616c:      	br	x17

00000000001f6170 <pthread_setspecific@plt>:
  1f6170:      	adrp	x16, 0x204000
  1f6174:      	ldr	x17, [x16, #0x268]
  1f6178:      	add	x16, x16, #0x268
  1f617c:      	br	x17

00000000001f6180 <_ZN7MMCodec14EglSurfaceBaseD1Ev@plt>:
  1f6180:      	adrp	x16, 0x204000
  1f6184:      	ldr	x17, [x16, #0x270]
  1f6188:      	add	x16, x16, #0x270
  1f618c:      	br	x17

00000000001f6190 <_ZNSt6__ndk115__thread_structD1Ev@plt>:
  1f6190:      	adrp	x16, 0x204000
  1f6194:      	ldr	x17, [x16, #0x278]
  1f6198:      	add	x16, x16, #0x278
  1f619c:      	br	x17

00000000001f61a0 <_ZN7MMCodec19AndroidPixelDecoderC1Ev@plt>:
  1f61a0:      	adrp	x16, 0x204000
  1f61a4:      	ldr	x17, [x16, #0x280]
  1f61a8:      	add	x16, x16, #0x280
  1f61ac:      	br	x17

00000000001f61b0 <_ZN7MMCodec19AndroidPixelDecoderD1Ev@plt>:
  1f61b0:      	adrp	x16, 0x204000
  1f61b4:      	ldr	x17, [x16, #0x288]
  1f61b8:      	add	x16, x16, #0x288
  1f61bc:      	br	x17

00000000001f61c0 <_ZN7MMCodec21getAICodecPixelFormatEi@plt>:
  1f61c0:      	adrp	x16, 0x204000
  1f61c4:      	ldr	x17, [x16, #0x290]
  1f61c8:      	add	x16, x16, #0x290
  1f61cc:      	br	x17

00000000001f61d0 <_ZN7MMCodec17FFmpegMediaStreamC2EPNS_18MediaHandleContextE@plt>:
  1f61d0:      	adrp	x16, 0x204000
  1f61d4:      	ldr	x17, [x16, #0x298]
  1f61d8:      	add	x16, x16, #0x298
  1f61dc:      	br	x17

00000000001f61e0 <_ZN7MMCodec17FFmpegMediaStreamD2Ev@plt>:
  1f61e0:      	adrp	x16, 0x204000
  1f61e4:      	ldr	x17, [x16, #0x2a0]
  1f61e8:      	add	x16, x16, #0x2a0
  1f61ec:      	br	x17

00000000001f61f0 <_ZN7MMCodec16ThreadITCContextD1Ev@plt>:
  1f61f0:      	adrp	x16, 0x204000
  1f61f4:      	ldr	x17, [x16, #0x2a8]
  1f61f8:      	add	x16, x16, #0x2a8
  1f61fc:      	br	x17

00000000001f6200 <_ZN7MMCodec18AndroidMediaStreamD1Ev@plt>:
  1f6200:      	adrp	x16, 0x204000
  1f6204:      	ldr	x17, [x16, #0x2b0]
  1f6208:      	add	x16, x16, #0x2b0
  1f620c:      	br	x17

00000000001f6210 <_ZN7MMCodec18MediaHandleContext17getAICodecContextEv@plt>:
  1f6210:      	adrp	x16, 0x204000
  1f6214:      	ldr	x17, [x16, #0x2b8]
  1f6218:      	add	x16, x16, #0x2b8
  1f621c:      	br	x17

00000000001f6220 <_ZN7MMCodec10FrameQueueC1EPNS_14AICodecContextE@plt>:
  1f6220:      	adrp	x16, 0x204000
  1f6224:      	ldr	x17, [x16, #0x2c0]
  1f6228:      	add	x16, x16, #0x2c0
  1f622c:      	br	x17

00000000001f6230 <_ZN7MMCodec17setVideoCodecInfoEPNS_18MediaHandleContextEPKcS3_@plt>:
  1f6230:      	adrp	x16, 0x204000
  1f6234:      	ldr	x17, [x16, #0x2c8]
  1f6238:      	add	x16, x16, #0x2c8
  1f623c:      	br	x17

00000000001f6240 <_ZN7MMCodec18MediaHandleContext16getTotalDurationEib@plt>:
  1f6240:      	adrp	x16, 0x204000
  1f6244:      	ldr	x17, [x16, #0x2d0]
  1f6248:      	add	x16, x16, #0x2d0
  1f624c:      	br	x17

00000000001f6250 <_ZN7MMCodec10FrameQueue4initEPNS_11PacketQueueEi@plt>:
  1f6250:      	adrp	x16, 0x204000
  1f6254:      	ldr	x17, [x16, #0x2d8]
  1f6258:      	add	x16, x16, #0x2d8
  1f625c:      	br	x17

00000000001f6260 <_ZN7MMCodec16ThreadITCContextC1Ei@plt>:
  1f6260:      	adrp	x16, 0x204000
  1f6264:      	ldr	x17, [x16, #0x2e0]
  1f6268:      	add	x16, x16, #0x2e0
  1f626c:      	br	x17

00000000001f6270 <_ZN7MMCodec11MediaFilterC1EPNS_18MediaHandleContextEPNS_10StreamBaseEP14AVCodecContext@plt>:
  1f6270:      	adrp	x16, 0x204000
  1f6274:      	ldr	x17, [x16, #0x2e8]
  1f6278:      	add	x16, x16, #0x2e8
  1f627c:      	br	x17

00000000001f6280 <_ZN7MMCodec13FrameHoldPoolC1EPNS_14AICodecContextENSt6__ndk18functionIFiRNS_12MMCodecFrameES6_EEENS4_IFiS6_EEE@plt>:
  1f6280:      	adrp	x16, 0x204000
  1f6284:      	ldr	x17, [x16, #0x2f0]
  1f6288:      	add	x16, x16, #0x2f0
  1f628c:      	br	x17

00000000001f6290 <_ZN7MMCodec14FrameCachePoolC1EPNS_14AICodecContextEddiNSt6__ndk18functionIFiRNS_12MMCodecFrameES6_EEENS4_IFiS6_EEEl@plt>:
  1f6290:      	adrp	x16, 0x204000
  1f6294:      	ldr	x17, [x16, #0x2f8]
  1f6298:      	add	x16, x16, #0x2f8
  1f629c:      	br	x17

00000000001f62a0 <_ZN7MMCodec17FFmpegMediaStream11streamCloseEv@plt>:
  1f62a0:      	adrp	x16, 0x204000
  1f62a4:      	ldr	x17, [x16, #0x300]
  1f62a8:      	add	x16, x16, #0x300
  1f62ac:      	br	x17

00000000001f62b0 <_ZN7MMCodec16ThreadITCContext7disableEv@plt>:
  1f62b0:      	adrp	x16, 0x204000
  1f62b4:      	ldr	x17, [x16, #0x308]
  1f62b8:      	add	x16, x16, #0x308
  1f62bc:      	br	x17

00000000001f62c0 <_ZN7MMCodec10StreamBase19findSmoothSeekFrameEliRPNS_12MMCodecFrameE@plt>:
  1f62c0:      	adrp	x16, 0x204000
  1f62c4:      	ldr	x17, [x16, #0x310]
  1f62c8:      	add	x16, x16, #0x310
  1f62cc:      	br	x17

00000000001f62d0 <_ZN7MMCodec10StreamBase13findNextFrameEiRPNS_12MMCodecFrameE@plt>:
  1f62d0:      	adrp	x16, 0x204000
  1f62d4:      	ldr	x17, [x16, #0x318]
  1f62d8:      	add	x16, x16, #0x318
  1f62dc:      	br	x17

00000000001f62e0 <_ZN7MMCodec10StreamBase13findBestFrameEliRPNS_12MMCodecFrameE@plt>:
  1f62e0:      	adrp	x16, 0x204000
  1f62e4:      	ldr	x17, [x16, #0x320]
  1f62e8:      	add	x16, x16, #0x320
  1f62ec:      	br	x17

00000000001f62f0 <_ZN7MMCodec9FrameData24getPresentationTimestampEv@plt>:
  1f62f0:      	adrp	x16, 0x204000
  1f62f4:      	ldr	x17, [x16, #0x328]
  1f62f8:      	add	x16, x16, #0x328
  1f62fc:      	br	x17

00000000001f6300 <_ZN7MMCodec9FrameData20setInVideoDataFormatERKNS_12VideoParam_tENS_10StreamTypeE@plt>:
  1f6300:      	adrp	x16, 0x204000
  1f6304:      	ldr	x17, [x16, #0x330]
  1f6308:      	add	x16, x16, #0x330
  1f630c:      	br	x17

00000000001f6310 <_ZN7MMCodec9FrameData5writeEPNS_12MMCodecFrameE@plt>:
  1f6310:      	adrp	x16, 0x204000
  1f6314:      	ldr	x17, [x16, #0x338]
  1f6318:      	add	x16, x16, #0x338
  1f631c:      	br	x17

00000000001f6320 <_ZN7MMCodec9FrameData8transferEv@plt>:
  1f6320:      	adrp	x16, 0x204000
  1f6324:      	ldr	x17, [x16, #0x340]
  1f6328:      	add	x16, x16, #0x340
  1f632c:      	br	x17

00000000001f6330 <_ZN7MMCodec9FrameData30setPrimalPresentationTimestampEl@plt>:
  1f6330:      	adrp	x16, 0x204000
  1f6334:      	ldr	x17, [x16, #0x348]
  1f6338:      	add	x16, x16, #0x348
  1f633c:      	br	x17

00000000001f6340 <_ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE25__emplace_unique_key_argsIS1_JRKS1_EEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEEbEERKT_DpOT0_@plt>:
  1f6340:      	adrp	x16, 0x204000
  1f6344:      	ldr	x17, [x16, #0x350]
  1f6348:      	add	x16, x16, #0x350
  1f634c:      	br	x17

00000000001f6350 <_ZN7MMCodec12MMCodecFrame5resetEv@plt>:
  1f6350:      	adrp	x16, 0x204000
  1f6354:      	ldr	x17, [x16, #0x358]
  1f6358:      	add	x16, x16, #0x358
  1f635c:      	br	x17

00000000001f6360 <_ZN7MMCodec10StreamBase11_unRefFrameERNS_12MMCodecFrameE@plt>:
  1f6360:      	adrp	x16, 0x204000
  1f6364:      	ldr	x17, [x16, #0x360]
  1f6368:      	add	x16, x16, #0x360
  1f636c:      	br	x17

00000000001f6370 <_ZN7MMCodec12MMCodecFrame7moveRefEPS0_S1_@plt>:
  1f6370:      	adrp	x16, 0x204000
  1f6374:      	ldr	x17, [x16, #0x368]
  1f6378:      	add	x16, x16, #0x368
  1f637c:      	br	x17

00000000001f6380 <_ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE11__do_rehashILb1EEEvm@plt>:
  1f6380:      	adrp	x16, 0x204000
  1f6384:      	ldr	x17, [x16, #0x370]
  1f6388:      	add	x16, x16, #0x370
  1f638c:      	br	x17

00000000001f6390 <_ZN7MMCodec18AndroidMediaStreamC1EPNS_18MediaHandleContextE@plt>:
  1f6390:      	adrp	x16, 0x204000
  1f6394:      	ldr	x17, [x16, #0x378]
  1f6398:      	add	x16, x16, #0x378
  1f639c:      	br	x17

00000000001f63a0 <pthread_getspecific@plt>:
  1f63a0:      	adrp	x16, 0x204000
  1f63a4:      	ldr	x17, [x16, #0x380]
  1f63a8:      	add	x16, x16, #0x380
  1f63ac:      	br	x17

00000000001f63b0 <_ZN9JniHelper8cacheEnvEP7_JavaVM@plt>:
  1f63b0:      	adrp	x16, 0x204000
  1f63b4:      	ldr	x17, [x16, #0x388]
  1f63b8:      	add	x16, x16, #0x388
  1f63bc:      	br	x17

00000000001f63c0 <_ZN9JniHelper9getJavaVMEv@plt>:
  1f63c0:      	adrp	x16, 0x204000
  1f63c4:      	ldr	x17, [x16, #0x390]
  1f63c8:      	add	x16, x16, #0x390
  1f63cc:      	br	x17

00000000001f63d0 <_ZN9JniHelper9setJavaVMEP7_JavaVM@plt>:
  1f63d0:      	adrp	x16, 0x204000
  1f63d4:      	ldr	x17, [x16, #0x398]
  1f63d8:      	add	x16, x16, #0x398
  1f63dc:      	br	x17

00000000001f63e0 <pthread_key_create@plt>:
  1f63e0:      	adrp	x16, 0x204000
  1f63e4:      	ldr	x17, [x16, #0x3a0]
  1f63e8:      	add	x16, x16, #0x3a0
  1f63ec:      	br	x17

00000000001f63f0 <_ZN9JniHelper14jstring2stringEP8_jstring@plt>:
  1f63f0:      	adrp	x16, 0x204000
  1f63f4:      	ldr	x17, [x16, #0x3a8]
  1f63f8:      	add	x16, x16, #0x3a8
  1f63fc:      	br	x17

00000000001f6400 <_Z15aicodec_set_jvmP7_JavaVM@plt>:
  1f6400:      	adrp	x16, 0x204000
  1f6404:      	ldr	x17, [x16, #0x3b0]
  1f6408:      	add	x16, x16, #0x3b0
  1f640c:      	br	x17

00000000001f6410 <_Z31register_aicodec_native_methodsP7_JNIEnv@plt>:
  1f6410:      	adrp	x16, 0x204000
  1f6414:      	ldr	x17, [x16, #0x3b8]
  1f6418:      	add	x16, x16, #0x3b8
  1f641c:      	br	x17

00000000001f6420 <_ZN7MMCodec39register_com_meitu_media_AndroidDecoderEP7_JNIEnv@plt>:
  1f6420:      	adrp	x16, 0x204000
  1f6424:      	ldr	x17, [x16, #0x3c0]
  1f6428:      	add	x16, x16, #0x3c0
  1f642c:      	br	x17

00000000001f6430 <_ZN7MMCodec39register_com_meitu_media_FlyMediaReaderEP7_JNIEnv@plt>:
  1f6430:      	adrp	x16, 0x204000
  1f6434:      	ldr	x17, [x16, #0x3c8]
  1f6438:      	add	x16, x16, #0x3c8
  1f643c:      	br	x17

00000000001f6440 <_ZN7MMCodec47register_com_meitu_media_encoder_MediaParameterEP7_JNIEnv@plt>:
  1f6440:      	adrp	x16, 0x204000
  1f6444:      	ldr	x17, [x16, #0x3d0]
  1f6448:      	add	x16, x16, #0x3d0
  1f644c:      	br	x17

00000000001f6450 <_ZN7MMCodec49register_com_meitu_media_encoder_FlyMediaRecorderEP7_JNIEnv@plt>:
  1f6450:      	adrp	x16, 0x204000
  1f6454:      	ldr	x17, [x16, #0x3d8]
  1f6458:      	add	x16, x16, #0x3d8
  1f645c:      	br	x17

00000000001f6460 <_ZN7MMCodec40register_com_meitu_media_aicodec_AICodecEP7_JNIEnv@plt>:
  1f6460:      	adrp	x16, 0x204000
  1f6464:      	ldr	x17, [x16, #0x3e0]
  1f6468:      	add	x16, x16, #0x3e0
  1f646c:      	br	x17

00000000001f6470 <_ZN7aicodec14AICodecVersion8ToStringEv@plt>:
  1f6470:      	adrp	x16, 0x204000
  1f6474:      	ldr	x17, [x16, #0x3e8]
  1f6478:      	add	x16, x16, #0x3e8
  1f647c:      	br	x17

00000000001f6480 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  1f6480:      	adrp	x16, 0x204000
  1f6484:      	ldr	x17, [x16, #0x3f0]
  1f6488:      	add	x16, x16, #0x3f0
  1f648c:      	br	x17

00000000001f6490 <_ZNSt6__ndk118basic_stringstreamIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
  1f6490:      	adrp	x16, 0x204000
  1f6494:      	ldr	x17, [x16, #0x3f8]
  1f6498:      	add	x16, x16, #0x3f8
  1f649c:      	br	x17

00000000001f64a0 <_ZN7MMCodec13MTMediaReader17getAICodecContextEv@plt>:
  1f64a0:      	adrp	x16, 0x204000
  1f64a4:      	ldr	x17, [x16, #0x400]
  1f64a8:      	add	x16, x16, #0x400
  1f64ac:      	br	x17

00000000001f64b0 <_ZN7MMCodec14AICodecContext18setSharedGLContextEPv@plt>:
  1f64b0:      	adrp	x16, 0x204000
  1f64b4:      	ldr	x17, [x16, #0x408]
  1f64b8:      	add	x16, x16, #0x408
  1f64bc:      	br	x17

00000000001f64c0 <_ZN7MMCodec13MTMediaReader20setAudioOutParameterEiiNS_19AUDIO_SAMPLE_FORMATE@plt>:
  1f64c0:      	adrp	x16, 0x204000
  1f64c4:      	ldr	x17, [x16, #0x410]
  1f64c8:      	add	x16, x16, #0x410
  1f64cc:      	br	x17

00000000001f64d0 <_ZNK7MMCodec13MTMediaReader12getMediaInfoEv@plt>:
  1f64d0:      	adrp	x16, 0x204000
  1f64d4:      	ldr	x17, [x16, #0x418]
  1f64d8:      	add	x16, x16, #0x418
  1f64dc:      	br	x17

00000000001f64e0 <_ZN7MMCodec13MTMediaReader13getAudioFrameENS_10ReadOptionERPhRNS_9FrameInfoE@plt>:
  1f64e0:      	adrp	x16, 0x204000
  1f64e4:      	ldr	x17, [x16, #0x420]
  1f64e8:      	add	x16, x16, #0x420
  1f64ec:      	br	x17

00000000001f64f0 <_ZN7MMCodec13AICodecGlobal27setEnableAdditionMediaCodecEi@plt>:
  1f64f0:      	adrp	x16, 0x204000
  1f64f4:      	ldr	x17, [x16, #0x428]
  1f64f8:      	add	x16, x16, #0x428
  1f64fc:      	br	x17

00000000001f6500 <_ZN7MMCodec13AICodecGlobal23setDecoderOperatingRateEi@plt>:
  1f6500:      	adrp	x16, 0x204000
  1f6504:      	ldr	x17, [x16, #0x430]
  1f6508:      	add	x16, x16, #0x430
  1f650c:      	br	x17

00000000001f6510 <_ZN7MMCodec13MTMediaReaderD1Ev@plt>:
  1f6510:      	adrp	x16, 0x204000
  1f6514:      	ldr	x17, [x16, #0x438]
  1f6518:      	add	x16, x16, #0x438
  1f651c:      	br	x17

00000000001f6520 <_ZN7MMCodec13MTMediaReaderC1EPKcPKhm@plt>:
  1f6520:      	adrp	x16, 0x204000
  1f6524:      	ldr	x17, [x16, #0x440]
  1f6528:      	add	x16, x16, #0x440
  1f652c:      	br	x17

00000000001f6530 <_ZN7MMCodec14AICodecContextC1Ev@plt>:
  1f6530:      	adrp	x16, 0x204000
  1f6534:      	ldr	x17, [x16, #0x448]
  1f6538:      	add	x16, x16, #0x448
  1f653c:      	br	x17

00000000001f6540 <_ZN7MMCodec13MTMediaReader17setAICodecContextEPNS_14AICodecContextE@plt>:
  1f6540:      	adrp	x16, 0x204000
  1f6544:      	ldr	x17, [x16, #0x450]
  1f6548:      	add	x16, x16, #0x450
  1f654c:      	br	x17

00000000001f6550 <_ZN7MMCodec13MTMediaReader4openEv@plt>:
  1f6550:      	adrp	x16, 0x204000
  1f6554:      	ldr	x17, [x16, #0x458]
  1f6558:      	add	x16, x16, #0x458
  1f655c:      	br	x17

00000000001f6560 <_ZN7MMCodec13MTMediaReader12startDecoderEPNS_14AICodecContextEll@plt>:
  1f6560:      	adrp	x16, 0x204000
  1f6564:      	ldr	x17, [x16, #0x460]
  1f6568:      	add	x16, x16, #0x460
  1f656c:      	br	x17

00000000001f6570 <_ZN7MMCodec13MTMediaReader11stopDecoderEv@plt>:
  1f6570:      	adrp	x16, 0x204000
  1f6574:      	ldr	x17, [x16, #0x468]
  1f6578:      	add	x16, x16, #0x468
  1f657c:      	br	x17

00000000001f6580 <_ZN7MMCodec13MTMediaReader5pauseEv@plt>:
  1f6580:      	adrp	x16, 0x204000
  1f6584:      	ldr	x17, [x16, #0x470]
  1f6588:      	add	x16, x16, #0x470
  1f658c:      	br	x17

00000000001f6590 <_ZN7MMCodec13MTMediaReader6resumeEv@plt>:
  1f6590:      	adrp	x16, 0x204000
  1f6594:      	ldr	x17, [x16, #0x478]
  1f6598:      	add	x16, x16, #0x478
  1f659c:      	br	x17

00000000001f65a0 <_ZN7MMCodec13MTMediaReader5closeEv@plt>:
  1f65a0:      	adrp	x16, 0x204000
  1f65a4:      	ldr	x17, [x16, #0x480]
  1f65a8:      	add	x16, x16, #0x480
  1f65ac:      	br	x17

00000000001f65b0 <_ZN7MMCodec29MediaReaderWrapperGetRotationEPv@plt>:
  1f65b0:      	adrp	x16, 0x204000
  1f65b4:      	ldr	x17, [x16, #0x488]
  1f65b8:      	add	x16, x16, #0x488
  1f65bc:      	br	x17

00000000001f65c0 <_ZN7MMCodec13MTMediaReader14setEnableAudioEb@plt>:
  1f65c0:      	adrp	x16, 0x204000
  1f65c4:      	ldr	x17, [x16, #0x490]
  1f65c8:      	add	x16, x16, #0x490
  1f65cc:      	br	x17

00000000001f65d0 <_ZN7MMCodec13MTMediaReader14setEnableVideoEb@plt>:
  1f65d0:      	adrp	x16, 0x204000
  1f65d4:      	ldr	x17, [x16, #0x498]
  1f65d8:      	add	x16, x16, #0x498
  1f65dc:      	br	x17

00000000001f65e0 <_ZN7MMCodec13MTMediaReader12setStartTimeEl@plt>:
  1f65e0:      	adrp	x16, 0x204000
  1f65e4:      	ldr	x17, [x16, #0x4a0]
  1f65e8:      	add	x16, x16, #0x4a0
  1f65ec:      	br	x17

00000000001f65f0 <_ZN7MMCodec13MTMediaReader11setDurationEl@plt>:
  1f65f0:      	adrp	x16, 0x204000
  1f65f4:      	ldr	x17, [x16, #0x4a8]
  1f65f8:      	add	x16, x16, #0x4a8
  1f65fc:      	br	x17

00000000001f6600 <_ZN7MMCodec13MTMediaReader13getVideoFrameElNS_10ReadOptionERNS_10VideoFrameERNS_9FrameInfoE@plt>:
  1f6600:      	adrp	x16, 0x204000
  1f6604:      	ldr	x17, [x16, #0x4b0]
  1f6608:      	add	x16, x16, #0x4b0
  1f660c:      	br	x17

00000000001f6610 <_ZN7MMCodec13MTImageReader11isSupportedEv@plt>:
  1f6610:      	adrp	x16, 0x204000
  1f6614:      	ldr	x17, [x16, #0x4b8]
  1f6618:      	add	x16, x16, #0x4b8
  1f661c:      	br	x17

00000000001f6620 <_ZN7MMCodec13MTImageReader4initEiiii@plt>:
  1f6620:      	adrp	x16, 0x204000
  1f6624:      	ldr	x17, [x16, #0x4c0]
  1f6628:      	add	x16, x16, #0x4c0
  1f662c:      	br	x17

00000000001f6630 <_ZN7MMCodec13MTImageReader18stopCallBackThreadEP7_JNIEnv@plt>:
  1f6630:      	adrp	x16, 0x204000
  1f6634:      	ldr	x17, [x16, #0x4c8]
  1f6638:      	add	x16, x16, #0x4c8
  1f663c:      	br	x17

00000000001f6640 <_ZN7MMCodec13MTImageReaderD1Ev@plt>:
  1f6640:      	adrp	x16, 0x204000
  1f6644:      	ldr	x17, [x16, #0x4d0]
  1f6648:      	add	x16, x16, #0x4d0
  1f664c:      	br	x17

00000000001f6650 <_ZN7MMCodec13MTImageReader10getSurfaceEv@plt>:
  1f6650:      	adrp	x16, 0x204000
  1f6654:      	ldr	x17, [x16, #0x4d8]
  1f6658:      	add	x16, x16, #0x4d8
  1f665c:      	br	x17

00000000001f6660 <_ZN7MMCodec13MTImageReader16acquireNextImageERPhRiS3_@plt>:
  1f6660:      	adrp	x16, 0x204000
  1f6664:      	ldr	x17, [x16, #0x4e0]
  1f6668:      	add	x16, x16, #0x4e0
  1f666c:      	br	x17

00000000001f6670 <_ZN7MMCodec13MTImageReader11jImageCloseERPv@plt>:
  1f6670:      	adrp	x16, 0x204000
  1f6674:      	ldr	x17, [x16, #0x4e8]
  1f6678:      	add	x16, x16, #0x4e8
  1f667c:      	br	x17

00000000001f6680 <_ZN7MMCodec13MTImageReader11newCallBackEPKNS0_16OnImageAvailableE@plt>:
  1f6680:      	adrp	x16, 0x204000
  1f6684:      	ldr	x17, [x16, #0x4f0]
  1f6688:      	add	x16, x16, #0x4f0
  1f668c:      	br	x17

00000000001f6690 <_ZN7MMCodec13MTImageReaderC1Ev@plt>:
  1f6690:      	adrp	x16, 0x204000
  1f6694:      	ldr	x17, [x16, #0x4f8]
  1f6698:      	add	x16, x16, #0x4f8
  1f669c:      	br	x17

00000000001f66a0 <_ZN7MMCodec13MMImageWriter11isSupportedEv@plt>:
  1f66a0:      	adrp	x16, 0x204000
  1f66a4:      	ldr	x17, [x16, #0x500]
  1f66a8:      	add	x16, x16, #0x500
  1f66ac:      	br	x17

00000000001f66b0 <_ZN7MMCodec13MMImageWriter7releaseEv@plt>:
  1f66b0:      	adrp	x16, 0x204000
  1f66b4:      	ldr	x17, [x16, #0x508]
  1f66b8:      	add	x16, x16, #0x508
  1f66bc:      	br	x17

00000000001f66c0 <glDeleteTextures@plt>:
  1f66c0:      	adrp	x16, 0x204000
  1f66c4:      	ldr	x17, [x16, #0x510]
  1f66c8:      	add	x16, x16, #0x510
  1f66cc:      	br	x17

00000000001f66d0 <_ZN7MMCodec13MMImageWriterD1Ev@plt>:
  1f66d0:      	adrp	x16, 0x204000
  1f66d4:      	ldr	x17, [x16, #0x518]
  1f66d8:      	add	x16, x16, #0x518
  1f66dc:      	br	x17

00000000001f66e0 <_ZN7MMCodec13MMImageWriter8_initJniEv@plt>:
  1f66e0:      	adrp	x16, 0x204000
  1f66e4:      	ldr	x17, [x16, #0x520]
  1f66e8:      	add	x16, x16, #0x520
  1f66ec:      	br	x17

00000000001f66f0 <_ZN7MMCodec13MMImageWriter4initEiiiPKNS0_16onFrameAvailableE@plt>:
  1f66f0:      	adrp	x16, 0x204000
  1f66f4:      	ldr	x17, [x16, #0x528]
  1f66f8:      	add	x16, x16, #0x528
  1f66fc:      	br	x17

00000000001f6700 <_ZN7MMCodec6GLUtil13CreateTextureEiii@plt>:
  1f6700:      	adrp	x16, 0x204000
  1f6704:      	ldr	x17, [x16, #0x530]
  1f6708:      	add	x16, x16, #0x530
  1f670c:      	br	x17

00000000001f6710 <ANativeWindow_setBuffersGeometry@plt>:
  1f6710:      	adrp	x16, 0x204000
  1f6714:      	ldr	x17, [x16, #0x538]
  1f6718:      	add	x16, x16, #0x538
  1f671c:      	br	x17

00000000001f6720 <_ZN7MMCodec13MMImageWriter15queueInputImageEPKhmi@plt>:
  1f6720:      	adrp	x16, 0x204000
  1f6724:      	ldr	x17, [x16, #0x540]
  1f6728:      	add	x16, x16, #0x540
  1f672c:      	br	x17

00000000001f6730 <_ZN7MMCodec13MMImageWriter17dequeueInputImageERiRPf@plt>:
  1f6730:      	adrp	x16, 0x204000
  1f6734:      	ldr	x17, [x16, #0x548]
  1f6738:      	add	x16, x16, #0x548
  1f673c:      	br	x17

00000000001f6740 <_ZN7MMCodec13MMImageWriterC1Ev@plt>:
  1f6740:      	adrp	x16, 0x204000
  1f6744:      	ldr	x17, [x16, #0x550]
  1f6748:      	add	x16, x16, #0x550
  1f674c:      	br	x17

00000000001f6750 <_ZN7MMCodec12PixelTexture7releaseEv@plt>:
  1f6750:      	adrp	x16, 0x204000
  1f6754:      	ldr	x17, [x16, #0x558]
  1f6758:      	add	x16, x16, #0x558
  1f675c:      	br	x17

00000000001f6760 <_ZN7MMCodec12PixelTextureD1Ev@plt>:
  1f6760:      	adrp	x16, 0x204000
  1f6764:      	ldr	x17, [x16, #0x560]
  1f6768:      	add	x16, x16, #0x560
  1f676c:      	br	x17

00000000001f6770 <glCreateShader@plt>:
  1f6770:      	adrp	x16, 0x204000
  1f6774:      	ldr	x17, [x16, #0x568]
  1f6778:      	add	x16, x16, #0x568
  1f677c:      	br	x17

00000000001f6780 <glShaderSource@plt>:
  1f6780:      	adrp	x16, 0x204000
  1f6784:      	ldr	x17, [x16, #0x570]
  1f6788:      	add	x16, x16, #0x570
  1f678c:      	br	x17

00000000001f6790 <glCompileShader@plt>:
  1f6790:      	adrp	x16, 0x204000
  1f6794:      	ldr	x17, [x16, #0x578]
  1f6798:      	add	x16, x16, #0x578
  1f679c:      	br	x17

00000000001f67a0 <glGetShaderiv@plt>:
  1f67a0:      	adrp	x16, 0x204000
  1f67a4:      	ldr	x17, [x16, #0x580]
  1f67a8:      	add	x16, x16, #0x580
  1f67ac:      	br	x17

00000000001f67b0 <glCreateProgram@plt>:
  1f67b0:      	adrp	x16, 0x204000
  1f67b4:      	ldr	x17, [x16, #0x588]
  1f67b8:      	add	x16, x16, #0x588
  1f67bc:      	br	x17

00000000001f67c0 <glAttachShader@plt>:
  1f67c0:      	adrp	x16, 0x204000
  1f67c4:      	ldr	x17, [x16, #0x590]
  1f67c8:      	add	x16, x16, #0x590
  1f67cc:      	br	x17

00000000001f67d0 <glLinkProgram@plt>:
  1f67d0:      	adrp	x16, 0x204000
  1f67d4:      	ldr	x17, [x16, #0x598]
  1f67d8:      	add	x16, x16, #0x598
  1f67dc:      	br	x17

00000000001f67e0 <glGetProgramiv@plt>:
  1f67e0:      	adrp	x16, 0x204000
  1f67e4:      	ldr	x17, [x16, #0x5a0]
  1f67e8:      	add	x16, x16, #0x5a0
  1f67ec:      	br	x17

00000000001f67f0 <glDetachShader@plt>:
  1f67f0:      	adrp	x16, 0x204000
  1f67f4:      	ldr	x17, [x16, #0x5a8]
  1f67f8:      	add	x16, x16, #0x5a8
  1f67fc:      	br	x17

00000000001f6800 <glDeleteShader@plt>:
  1f6800:      	adrp	x16, 0x204000
  1f6804:      	ldr	x17, [x16, #0x5b0]
  1f6808:      	add	x16, x16, #0x5b0
  1f680c:      	br	x17

00000000001f6810 <glGetShaderInfoLog@plt>:
  1f6810:      	adrp	x16, 0x204000
  1f6814:      	ldr	x17, [x16, #0x5b8]
  1f6818:      	add	x16, x16, #0x5b8
  1f681c:      	br	x17

00000000001f6820 <glGetProgramInfoLog@plt>:
  1f6820:      	adrp	x16, 0x204000
  1f6824:      	ldr	x17, [x16, #0x5c0]
  1f6828:      	add	x16, x16, #0x5c0
  1f682c:      	br	x17

00000000001f6830 <glDeleteProgram@plt>:
  1f6830:      	adrp	x16, 0x204000
  1f6834:      	ldr	x17, [x16, #0x5c8]
  1f6838:      	add	x16, x16, #0x5c8
  1f683c:      	br	x17

00000000001f6840 <glGenTextures@plt>:
  1f6840:      	adrp	x16, 0x204000
  1f6844:      	ldr	x17, [x16, #0x5d0]
  1f6848:      	add	x16, x16, #0x5d0
  1f684c:      	br	x17

00000000001f6850 <glBindTexture@plt>:
  1f6850:      	adrp	x16, 0x204000
  1f6854:      	ldr	x17, [x16, #0x5d8]
  1f6858:      	add	x16, x16, #0x5d8
  1f685c:      	br	x17

00000000001f6860 <glTexImage2D@plt>:
  1f6860:      	adrp	x16, 0x204000
  1f6864:      	ldr	x17, [x16, #0x5e0]
  1f6868:      	add	x16, x16, #0x5e0
  1f686c:      	br	x17

00000000001f6870 <glTexParameteri@plt>:
  1f6870:      	adrp	x16, 0x204000
  1f6874:      	ldr	x17, [x16, #0x5e8]
  1f6878:      	add	x16, x16, #0x5e8
  1f687c:      	br	x17

00000000001f6880 <_Znam@plt>:
  1f6880:      	adrp	x16, 0x204000
  1f6884:      	ldr	x17, [x16, #0x5f0]
  1f6888:      	add	x16, x16, #0x5f0
  1f688c:      	br	x17

00000000001f6890 <_ZdaPv@plt>:
  1f6890:      	adrp	x16, 0x204000
  1f6894:      	ldr	x17, [x16, #0x5f8]
  1f6898:      	add	x16, x16, #0x5f8
  1f689c:      	br	x17

00000000001f68a0 <eglGetDisplay@plt>:
  1f68a0:      	adrp	x16, 0x204000
  1f68a4:      	ldr	x17, [x16, #0x600]
  1f68a8:      	add	x16, x16, #0x600
  1f68ac:      	br	x17

00000000001f68b0 <eglInitialize@plt>:
  1f68b0:      	adrp	x16, 0x204000
  1f68b4:      	ldr	x17, [x16, #0x608]
  1f68b8:      	add	x16, x16, #0x608
  1f68bc:      	br	x17

00000000001f68c0 <eglQueryContext@plt>:
  1f68c0:      	adrp	x16, 0x204000
  1f68c4:      	ldr	x17, [x16, #0x610]
  1f68c8:      	add	x16, x16, #0x610
  1f68cc:      	br	x17

00000000001f68d0 <_ZN7MMCodec7EglCore10_getConfigEii@plt>:
  1f68d0:      	adrp	x16, 0x204000
  1f68d4:      	ldr	x17, [x16, #0x618]
  1f68d8:      	add	x16, x16, #0x618
  1f68dc:      	br	x17

00000000001f68e0 <eglCreateContext@plt>:
  1f68e0:      	adrp	x16, 0x204000
  1f68e4:      	ldr	x17, [x16, #0x620]
  1f68e8:      	add	x16, x16, #0x620
  1f68ec:      	br	x17

00000000001f68f0 <eglGetError@plt>:
  1f68f0:      	adrp	x16, 0x204000
  1f68f4:      	ldr	x17, [x16, #0x628]
  1f68f8:      	add	x16, x16, #0x628
  1f68fc:      	br	x17

00000000001f6900 <eglChooseConfig@plt>:
  1f6900:      	adrp	x16, 0x204000
  1f6904:      	ldr	x17, [x16, #0x630]
  1f6908:      	add	x16, x16, #0x630
  1f690c:      	br	x17

00000000001f6910 <_ZN7MMCodec7EglCore7releaseEv@plt>:
  1f6910:      	adrp	x16, 0x204000
  1f6914:      	ldr	x17, [x16, #0x638]
  1f6918:      	add	x16, x16, #0x638
  1f691c:      	br	x17

00000000001f6920 <eglReleaseThread@plt>:
  1f6920:      	adrp	x16, 0x204000
  1f6924:      	ldr	x17, [x16, #0x640]
  1f6928:      	add	x16, x16, #0x640
  1f692c:      	br	x17

00000000001f6930 <eglDestroyContext@plt>:
  1f6930:      	adrp	x16, 0x204000
  1f6934:      	ldr	x17, [x16, #0x648]
  1f6938:      	add	x16, x16, #0x648
  1f693c:      	br	x17

00000000001f6940 <_ZN7MMCodec7EglCoreD1Ev@plt>:
  1f6940:      	adrp	x16, 0x204000
  1f6944:      	ldr	x17, [x16, #0x650]
  1f6948:      	add	x16, x16, #0x650
  1f694c:      	br	x17

00000000001f6950 <_ZN7MMCodec7EglCore14releaseSurfaceEPv@plt>:
  1f6950:      	adrp	x16, 0x204000
  1f6954:      	ldr	x17, [x16, #0x658]
  1f6958:      	add	x16, x16, #0x658
  1f695c:      	br	x17

00000000001f6960 <eglDestroySurface@plt>:
  1f6960:      	adrp	x16, 0x204000
  1f6964:      	ldr	x17, [x16, #0x660]
  1f6968:      	add	x16, x16, #0x660
  1f696c:      	br	x17

00000000001f6970 <_ZN7MMCodec7EglCore19createWindowSurfaceEP13ANativeWindow@plt>:
  1f6970:      	adrp	x16, 0x204000
  1f6974:      	ldr	x17, [x16, #0x668]
  1f6978:      	add	x16, x16, #0x668
  1f697c:      	br	x17

00000000001f6980 <eglCreateWindowSurface@plt>:
  1f6980:      	adrp	x16, 0x204000
  1f6984:      	ldr	x17, [x16, #0x670]
  1f6988:      	add	x16, x16, #0x670
  1f698c:      	br	x17

00000000001f6990 <_ZN7MMCodec7EglCore20createPBufferSurfaceEii@plt>:
  1f6990:      	adrp	x16, 0x204000
  1f6994:      	ldr	x17, [x16, #0x678]
  1f6998:      	add	x16, x16, #0x678
  1f699c:      	br	x17

00000000001f69a0 <eglCreatePbufferSurface@plt>:
  1f69a0:      	adrp	x16, 0x204000
  1f69a4:      	ldr	x17, [x16, #0x680]
  1f69a8:      	add	x16, x16, #0x680
  1f69ac:      	br	x17

00000000001f69b0 <_ZN7MMCodec7EglCore22createOffscreenSurfaceEii@plt>:
  1f69b0:      	adrp	x16, 0x204000
  1f69b4:      	ldr	x17, [x16, #0x688]
  1f69b8:      	add	x16, x16, #0x688
  1f69bc:      	br	x17

00000000001f69c0 <_ZN7MMCodec7EglCore11makeCurrentEPv@plt>:
  1f69c0:      	adrp	x16, 0x204000
  1f69c4:      	ldr	x17, [x16, #0x690]
  1f69c8:      	add	x16, x16, #0x690
  1f69cc:      	br	x17

00000000001f69d0 <_ZN7MMCodec7EglCore11swapBuffersEPv@plt>:
  1f69d0:      	adrp	x16, 0x204000
  1f69d4:      	ldr	x17, [x16, #0x698]
  1f69d8:      	add	x16, x16, #0x698
  1f69dc:      	br	x17

00000000001f69e0 <eglSwapBuffers@plt>:
  1f69e0:      	adrp	x16, 0x204000
  1f69e4:      	ldr	x17, [x16, #0x6a0]
  1f69e8:      	add	x16, x16, #0x6a0
  1f69ec:      	br	x17

00000000001f69f0 <_ZN7MMCodec7EglCore12querySurfaceEPvi@plt>:
  1f69f0:      	adrp	x16, 0x204000
  1f69f4:      	ldr	x17, [x16, #0x6a8]
  1f69f8:      	add	x16, x16, #0x6a8
  1f69fc:      	br	x17

00000000001f6a00 <eglQuerySurface@plt>:
  1f6a00:      	adrp	x16, 0x204000
  1f6a04:      	ldr	x17, [x16, #0x6b0]
  1f6a08:      	add	x16, x16, #0x6b0
  1f6a0c:      	br	x17

00000000001f6a10 <_ZN7MMCodec7EglCore19setPresentationTimeEPvl@plt>:
  1f6a10:      	adrp	x16, 0x204000
  1f6a14:      	ldr	x17, [x16, #0x6b8]
  1f6a18:      	add	x16, x16, #0x6b8
  1f6a1c:      	br	x17

00000000001f6a20 <eglPresentationTimeANDROID@plt>:
  1f6a20:      	adrp	x16, 0x204000
  1f6a24:      	ldr	x17, [x16, #0x6c0]
  1f6a28:      	add	x16, x16, #0x6c0
  1f6a2c:      	br	x17

00000000001f6a30 <_ZN7MMCodec14EglSurfaceBaseC2ENSt6__ndk110shared_ptrINS_7EglCoreEEE@plt>:
  1f6a30:      	adrp	x16, 0x204000
  1f6a34:      	ldr	x17, [x16, #0x6c8]
  1f6a38:      	add	x16, x16, #0x6c8
  1f6a3c:      	br	x17

00000000001f6a40 <_ZN7MMCodec14EglSurfaceBaseD2Ev@plt>:
  1f6a40:      	adrp	x16, 0x204000
  1f6a44:      	ldr	x17, [x16, #0x6d0]
  1f6a48:      	add	x16, x16, #0x6d0
  1f6a4c:      	br	x17

00000000001f6a50 <_ZN7MMCodec14EglSurfaceBase17releaseEglSurfaceEv@plt>:
  1f6a50:      	adrp	x16, 0x204000
  1f6a54:      	ldr	x17, [x16, #0x6d8]
  1f6a58:      	add	x16, x16, #0x6d8
  1f6a5c:      	br	x17

00000000001f6a60 <_ZN7MMCodec14EglSurfaceBase19createWindowSurfaceEP13ANativeWindow@plt>:
  1f6a60:      	adrp	x16, 0x204000
  1f6a64:      	ldr	x17, [x16, #0x6e0]
  1f6a68:      	add	x16, x16, #0x6e0
  1f6a6c:      	br	x17

00000000001f6a70 <_ZN7MMCodec13WindowSurfaceD1Ev@plt>:
  1f6a70:      	adrp	x16, 0x204000
  1f6a74:      	ldr	x17, [x16, #0x6e8]
  1f6a78:      	add	x16, x16, #0x6e8
  1f6a7c:      	br	x17

00000000001f6a80 <_ZN7MMCodec10JniUtility4initEP7_JNIEnv@plt>:
  1f6a80:      	adrp	x16, 0x204000
  1f6a84:      	ldr	x17, [x16, #0x6f0]
  1f6a88:      	add	x16, x16, #0x6f0
  1f6a8c:      	br	x17

00000000001f6a90 <_ZN7MMCodec13AICodecGlobal17getAndroidContextEv@plt>:
  1f6a90:      	adrp	x16, 0x204000
  1f6a94:      	ldr	x17, [x16, #0x6f8]
  1f6a98:      	add	x16, x16, #0x6f8
  1f6a9c:      	br	x17

00000000001f6aa0 <getpid@plt>:
  1f6aa0:      	adrp	x16, 0x204000
  1f6aa4:      	ldr	x17, [x16, #0x700]
  1f6aa8:      	add	x16, x16, #0x700
  1f6aac:      	br	x17

00000000001f6ab0 <_ZN7MMCodec10JniUtility18createAndroidPdObjEP7_JNIEnvRKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERi@plt>:
  1f6ab0:      	adrp	x16, 0x204000
  1f6ab4:      	ldr	x17, [x16, #0x708]
  1f6ab8:      	add	x16, x16, #0x708
  1f6abc:      	br	x17

00000000001f6ac0 <_ZN7MMCodec10JniUtility17closeAndroidPdObjEP7_JNIEnvP8_jobject@plt>:
  1f6ac0:      	adrp	x16, 0x204000
  1f6ac4:      	ldr	x17, [x16, #0x710]
  1f6ac8:      	add	x16, x16, #0x710
  1f6acc:      	br	x17

00000000001f6ad0 <_ZN7MMCodec13AICodecGlobal23setEncoderOperatingRateEi@plt>:
  1f6ad0:      	adrp	x16, 0x204000
  1f6ad4:      	ldr	x17, [x16, #0x718]
  1f6ad8:      	add	x16, x16, #0x718
  1f6adc:      	br	x17

00000000001f6ae0 <_ZN7MMCodec7MMCurveC2ERKNS_11CurveParamsE@plt>:
  1f6ae0:      	adrp	x16, 0x204000
  1f6ae4:      	ldr	x17, [x16, #0x720]
  1f6ae8:      	add	x16, x16, #0x720
  1f6aec:      	br	x17

00000000001f6af0 <_ZN7MMCodec6AVIRefC2Ev@plt>:
  1f6af0:      	adrp	x16, 0x204000
  1f6af4:      	ldr	x17, [x16, #0x728]
  1f6af8:      	add	x16, x16, #0x728
  1f6afc:      	br	x17

00000000001f6b00 <_ZN7MMCodec11CurveParamsC1ERKS0_@plt>:
  1f6b00:      	adrp	x16, 0x204000
  1f6b04:      	ldr	x17, [x16, #0x730]
  1f6b08:      	add	x16, x16, #0x730
  1f6b0c:      	br	x17

00000000001f6b10 <_ZN7MMCodec6AVIRefD2Ev@plt>:
  1f6b10:      	adrp	x16, 0x204000
  1f6b14:      	ldr	x17, [x16, #0x738]
  1f6b18:      	add	x16, x16, #0x738
  1f6b1c:      	br	x17

00000000001f6b20 <_ZN7MMCodec7MMCurveD2Ev@plt>:
  1f6b20:      	adrp	x16, 0x204000
  1f6b24:      	ldr	x17, [x16, #0x740]
  1f6b28:      	add	x16, x16, #0x740
  1f6b2c:      	br	x17

00000000001f6b30 <_ZN7MMCodec7MMCurveD1Ev@plt>:
  1f6b30:      	adrp	x16, 0x204000
  1f6b34:      	ldr	x17, [x16, #0x748]
  1f6b38:      	add	x16, x16, #0x748
  1f6b3c:      	br	x17

00000000001f6b40 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiPKcEENS_22__unordered_map_hasherIiS4_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS4_S9_S7_Lb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_4pairIKiS3_EEEEENSH_INS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEEbEERKT_DpOT0_@plt>:
  1f6b40:      	adrp	x16, 0x204000
  1f6b44:      	ldr	x17, [x16, #0x750]
  1f6b48:      	add	x16, x16, #0x750
  1f6b4c:      	br	x17

00000000001f6b50 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiPKcEENS_22__unordered_map_hasherIiS4_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS4_S9_S7_Lb1EEENS_9allocatorIS4_EEE11__do_rehashILb1EEEvm@plt>:
  1f6b50:      	adrp	x16, 0x204000
  1f6b54:      	ldr	x17, [x16, #0x758]
  1f6b58:      	add	x16, x16, #0x758
  1f6b5c:      	br	x17

00000000001f6b60 <_ZN7MMCodec11CurveParamsC1ENS_9CurveTypeE@plt>:
  1f6b60:      	adrp	x16, 0x204000
  1f6b64:      	ldr	x17, [x16, #0x760]
  1f6b68:      	add	x16, x16, #0x760
  1f6b6c:      	br	x17

00000000001f6b70 <_ZN7MMCodec7MMCurveC1ERKNS_11CurveParamsE@plt>:
  1f6b70:      	adrp	x16, 0x204000
  1f6b74:      	ldr	x17, [x16, #0x768]
  1f6b78:      	add	x16, x16, #0x768
  1f6b7c:      	br	x17

00000000001f6b80 <_ZN7MMCodec8MMLinearC2ERKNS_11CurveParamsE@plt>:
  1f6b80:      	adrp	x16, 0x204000
  1f6b84:      	ldr	x17, [x16, #0x770]
  1f6b88:      	add	x16, x16, #0x770
  1f6b8c:      	br	x17

00000000001f6b90 <log@plt>:
  1f6b90:      	adrp	x16, 0x204000
  1f6b94:      	ldr	x17, [x16, #0x778]
  1f6b98:      	add	x16, x16, #0x778
  1f6b9c:      	br	x17

00000000001f6ba0 <_ZN7MMCodec8MMLinearD2Ev@plt>:
  1f6ba0:      	adrp	x16, 0x204000
  1f6ba4:      	ldr	x17, [x16, #0x780]
  1f6ba8:      	add	x16, x16, #0x780
  1f6bac:      	br	x17

00000000001f6bb0 <_ZN7MMCodec8MMLinearD1Ev@plt>:
  1f6bb0:      	adrp	x16, 0x204000
  1f6bb4:      	ldr	x17, [x16, #0x788]
  1f6bb8:      	add	x16, x16, #0x788
  1f6bbc:      	br	x17

00000000001f6bc0 <exp@plt>:
  1f6bc0:      	adrp	x16, 0x204000
  1f6bc4:      	ldr	x17, [x16, #0x790]
  1f6bc8:      	add	x16, x16, #0x790
  1f6bcc:      	br	x17

00000000001f6bd0 <_ZN7MMCodec8MMLinear7getXOfYEd@plt>:
  1f6bd0:      	adrp	x16, 0x204000
  1f6bd4:      	ldr	x17, [x16, #0x798]
  1f6bd8:      	add	x16, x16, #0x798
  1f6bdc:      	br	x17

00000000001f6be0 <_ZN7MMCodec8MMLinearC1ERKNS_11CurveParamsE@plt>:
  1f6be0:      	adrp	x16, 0x204000
  1f6be4:      	ldr	x17, [x16, #0x7a0]
  1f6be8:      	add	x16, x16, #0x7a0
  1f6bec:      	br	x17

00000000001f6bf0 <_ZN7MMCodec19MMLinearLessThanOneD1Ev@plt>:
  1f6bf0:      	adrp	x16, 0x204000
  1f6bf4:      	ldr	x17, [x16, #0x7a8]
  1f6bf8:      	add	x16, x16, #0x7a8
  1f6bfc:      	br	x17

00000000001f6c00 <_ZN7MMCodec19MMLinearLessThanOneC1ERKNS_11CurveParamsEd@plt>:
  1f6c00:      	adrp	x16, 0x204000
  1f6c04:      	ldr	x17, [x16, #0x7b0]
  1f6c08:      	add	x16, x16, #0x7b0
  1f6c0c:      	br	x17

00000000001f6c10 <_ZN7MMCodec12CurveFactory11createCurveERKNS_11CurveParamsEd@plt>:
  1f6c10:      	adrp	x16, 0x204000
  1f6c14:      	ldr	x17, [x16, #0x7b8]
  1f6c18:      	add	x16, x16, #0x7b8
  1f6c1c:      	br	x17

00000000001f6c20 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiPKcEENS_22__unordered_map_hasherIiS4_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS4_S9_S7_Lb1EEENS_9allocatorIS4_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJOiEEENSK_IJEEEEEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEEbEERKT_DpOT0_@plt>:
  1f6c20:      	adrp	x16, 0x204000
  1f6c24:      	ldr	x17, [x16, #0x7c0]
  1f6c28:      	add	x16, x16, #0x7c0
  1f6c2c:      	br	x17

00000000001f6c30 <_ZN7MMCodec7getYOfVEdd@plt>:
  1f6c30:      	adrp	x16, 0x204000
  1f6c34:      	ldr	x17, [x16, #0x7c8]
  1f6c38:      	add	x16, x16, #0x7c8
  1f6c3c:      	br	x17

00000000001f6c40 <_ZN7MMCodec7getVOfYEdd@plt>:
  1f6c40:      	adrp	x16, 0x204000
  1f6c44:      	ldr	x17, [x16, #0x7d0]
  1f6c48:      	add	x16, x16, #0x7d0
  1f6c4c:      	br	x17

00000000001f6c50 <_ZN7MMCodec11SpeedEffectC2ERKNS_16SpeedEffectParamERKNS_14AudioParameterE@plt>:
  1f6c50:      	adrp	x16, 0x204000
  1f6c54:      	ldr	x17, [x16, #0x7d8]
  1f6c58:      	add	x16, x16, #0x7d8
  1f6c5c:      	br	x17

00000000001f6c60 <_ZN7MMCodec11SpeedEffectD2Ev@plt>:
  1f6c60:      	adrp	x16, 0x204000
  1f6c64:      	ldr	x17, [x16, #0x7e0]
  1f6c68:      	add	x16, x16, #0x7e0
  1f6c6c:      	br	x17

00000000001f6c70 <_ZN7MMCodec16SpeedEffectParamC1ENS_9CurveTypeE@plt>:
  1f6c70:      	adrp	x16, 0x204000
  1f6c74:      	ldr	x17, [x16, #0x7e8]
  1f6c78:      	add	x16, x16, #0x7e8
  1f6c7c:      	br	x17

00000000001f6c80 <_ZN7MMCodec18SpeedEffectManagerD1Ev@plt>:
  1f6c80:      	adrp	x16, 0x204000
  1f6c84:      	ldr	x17, [x16, #0x7f0]
  1f6c88:      	add	x16, x16, #0x7f0
  1f6c8c:      	br	x17

00000000001f6c90 <_ZN7MMCodec18SpeedEffectManager33_findSpeedEffectWithFileTimestampEl@plt>:
  1f6c90:      	adrp	x16, 0x204000
  1f6c94:      	ldr	x17, [x16, #0x7f8]
  1f6c98:      	add	x16, x16, #0x7f8
  1f6c9c:      	br	x17

00000000001f6ca0 <_ZN7MMCodec16CurveSpeedEffectC1ERKNS_16SpeedEffectParamERKNS_14AudioParameterE@plt>:
  1f6ca0:      	adrp	x16, 0x204000
  1f6ca4:      	ldr	x17, [x16, #0x800]
  1f6ca8:      	add	x16, x16, #0x800
  1f6cac:      	br	x17

00000000001f6cb0 <_ZNSt6__ndk16__treeINS_4pairIPN7MMCodec11SpeedEffectEdEENS2_22SpeedEffectElementCompENS_9allocatorIS5_EEE25__emplace_unique_key_argsIS5_JS5_EEENS1_INS_15__tree_iteratorIS5_PNS_11__tree_nodeIS5_PvEElEEbEERKT_DpOT0_@plt>:
  1f6cb0:      	adrp	x16, 0x204000
  1f6cb4:      	ldr	x17, [x16, #0x808]
  1f6cb8:      	add	x16, x16, #0x808
  1f6cbc:      	br	x17

00000000001f6cc0 <_ZNSt6__ndk16__treeIN7MMCodec16SpeedEffectParamENS1_17SpeedParamSetCompENS_9allocatorIS2_EEE25__emplace_unique_key_argsIS2_JRKS2_EEENS_4pairINS_15__tree_iteratorIS2_PNS_11__tree_nodeIS2_PvEElEEbEERKT_DpOT0_@plt>:
  1f6cc0:      	adrp	x16, 0x204000
  1f6cc4:      	ldr	x17, [x16, #0x810]
  1f6cc8:      	add	x16, x16, #0x810
  1f6ccc:      	br	x17

00000000001f6cd0 <_ZN7MMCodec10MTResampleC1Ev@plt>:
  1f6cd0:      	adrp	x16, 0x204000
  1f6cd4:      	ldr	x17, [x16, #0x818]
  1f6cd8:      	add	x16, x16, #0x818
  1f6cdc:      	br	x17

00000000001f6ce0 <_ZN6rtSOLA5CSOLAC1Ev@plt>:
  1f6ce0:      	adrp	x16, 0x204000
  1f6ce4:      	ldr	x17, [x16, #0x820]
  1f6ce8:      	add	x16, x16, #0x820
  1f6cec:      	br	x17

00000000001f6cf0 <_ZN6rtSOLA5CSOLA11SOLAReStartEfi@plt>:
  1f6cf0:      	adrp	x16, 0x204000
  1f6cf4:      	ldr	x17, [x16, #0x828]
  1f6cf8:      	add	x16, x16, #0x828
  1f6cfc:      	br	x17

00000000001f6d00 <av_log@plt>:
  1f6d00:      	adrp	x16, 0x204000
  1f6d04:      	ldr	x17, [x16, #0x830]
  1f6d08:      	add	x16, x16, #0x830
  1f6d0c:      	br	x17

00000000001f6d10 <abort@plt>:
  1f6d10:      	adrp	x16, 0x204000
  1f6d14:      	ldr	x17, [x16, #0x838]
  1f6d18:      	add	x16, x16, #0x838
  1f6d1c:      	br	x17

00000000001f6d20 <_ZN7MMCodec10MTResample4initE14AVSampleFormatiiS1_ii@plt>:
  1f6d20:      	adrp	x16, 0x204000
  1f6d24:      	ldr	x17, [x16, #0x840]
  1f6d28:      	add	x16, x16, #0x840
  1f6d2c:      	br	x17

00000000001f6d30 <_ZN6rtSOLA5CSOLAD1Ev@plt>:
  1f6d30:      	adrp	x16, 0x204000
  1f6d34:      	ldr	x17, [x16, #0x848]
  1f6d38:      	add	x16, x16, #0x848
  1f6d3c:      	br	x17

00000000001f6d40 <_ZN7MMCodec16CurveSpeedEffectD1Ev@plt>:
  1f6d40:      	adrp	x16, 0x204000
  1f6d44:      	ldr	x17, [x16, #0x850]
  1f6d48:      	add	x16, x16, #0x850
  1f6d4c:      	br	x17

00000000001f6d50 <_ZN6rtSOLA5CSOLA14getNextSamplesEfi@plt>:
  1f6d50:      	adrp	x16, 0x204000
  1f6d54:      	ldr	x17, [x16, #0x858]
  1f6d58:      	add	x16, x16, #0x858
  1f6d5c:      	br	x17

00000000001f6d60 <_ZN6rtSOLA5CSOLA11SOLAProcessEPsiPKsii@plt>:
  1f6d60:      	adrp	x16, 0x204000
  1f6d64:      	ldr	x17, [x16, #0x860]
  1f6d68:      	add	x16, x16, #0x860
  1f6d6c:      	br	x17

00000000001f6d70 <_ZN7MMCodec10MTResample35getNextOutBufferSizeWithWantSamplesEi@plt>:
  1f6d70:      	adrp	x16, 0x204000
  1f6d74:      	ldr	x17, [x16, #0x868]
  1f6d78:      	add	x16, x16, #0x868
  1f6d7c:      	br	x17

00000000001f6d80 <_ZN7MMCodec10MTResample8resampleEPhmS1_Rmi@plt>:
  1f6d80:      	adrp	x16, 0x204000
  1f6d84:      	ldr	x17, [x16, #0x870]
  1f6d88:      	add	x16, x16, #0x870
  1f6d8c:      	br	x17

00000000001f6d90 <_ZN6rtSOLA5CSOLA8SOLAInitEfi@plt>:
  1f6d90:      	adrp	x16, 0x204000
  1f6d94:      	ldr	x17, [x16, #0x878]
  1f6d98:      	add	x16, x16, #0x878
  1f6d9c:      	br	x17

00000000001f6da0 <calloc@plt>:
  1f6da0:      	adrp	x16, 0x204000
  1f6da4:      	ldr	x17, [x16, #0x880]
  1f6da8:      	add	x16, x16, #0x880
  1f6dac:      	br	x17

00000000001f6db0 <_ZN6rtSOLA5CSOLA11planProcessEPsiPKsi@plt>:
  1f6db0:      	adrp	x16, 0x204000
  1f6db4:      	ldr	x17, [x16, #0x888]
  1f6db8:      	add	x16, x16, #0x888
  1f6dbc:      	br	x17

00000000001f6dc0 <_ZN6rtSOLA5CSOLA12crossProcessEPsiPKsi@plt>:
  1f6dc0:      	adrp	x16, 0x204000
  1f6dc4:      	ldr	x17, [x16, #0x890]
  1f6dc8:      	add	x16, x16, #0x890
  1f6dcc:      	br	x17

00000000001f6dd0 <_ZN7MMCodec15BezierTimeScale19BezierTimeScaleInitEifi@plt>:
  1f6dd0:      	adrp	x16, 0x204000
  1f6dd4:      	ldr	x17, [x16, #0x898]
  1f6dd8:      	add	x16, x16, #0x898
  1f6ddc:      	br	x17

00000000001f6de0 <_ZN7MMCodec15BezierTimeScale22RedistributionOfMemoryEPPfRli@plt>:
  1f6de0:      	adrp	x16, 0x204000
  1f6de4:      	ldr	x17, [x16, #0x8a0]
  1f6de8:      	add	x16, x16, #0x8a0
  1f6dec:      	br	x17

00000000001f6df0 <_ZN7MMCodec15BezierTimeScale11PlanProcessEPsiPKsi@plt>:
  1f6df0:      	adrp	x16, 0x204000
  1f6df4:      	ldr	x17, [x16, #0x8a8]
  1f6df8:      	add	x16, x16, #0x8a8
  1f6dfc:      	br	x17

00000000001f6e00 <_ZN7MMCodec15BezierTimeScale12CrossProcessEPsiPKsi@plt>:
  1f6e00:      	adrp	x16, 0x204000
  1f6e04:      	ldr	x17, [x16, #0x8b0]
  1f6e08:      	add	x16, x16, #0x8b0
  1f6e0c:      	br	x17

00000000001f6e10 <_ZNK7MMCodec17MotionEffectParam8isRewindEv@plt>:
  1f6e10:      	adrp	x16, 0x204000
  1f6e14:      	ldr	x17, [x16, #0x8b8]
  1f6e18:      	add	x16, x16, #0x8b8
  1f6e1c:      	br	x17

00000000001f6e20 <_ZN7MMCodec12MotionEffectD1Ev@plt>:
  1f6e20:      	adrp	x16, 0x204000
  1f6e24:      	ldr	x17, [x16, #0x8c0]
  1f6e28:      	add	x16, x16, #0x8c0
  1f6e2c:      	br	x17

00000000001f6e30 <_ZN7MMCodec12MotionEffect8getSpeedEl@plt>:
  1f6e30:      	adrp	x16, 0x204000
  1f6e34:      	ldr	x17, [x16, #0x8c8]
  1f6e38:      	add	x16, x16, #0x8c8
  1f6e3c:      	br	x17

00000000001f6e40 <_ZN7MMCodec12MotionEffect16getFileTimestampEl@plt>:
  1f6e40:      	adrp	x16, 0x204000
  1f6e44:      	ldr	x17, [x16, #0x8d0]
  1f6e48:      	add	x16, x16, #0x8d0
  1f6e4c:      	br	x17

00000000001f6e50 <_ZN7MMCodec12MotionEffect12getTimestampEl@plt>:
  1f6e50:      	adrp	x16, 0x204000
  1f6e54:      	ldr	x17, [x16, #0x8d8]
  1f6e58:      	add	x16, x16, #0x8d8
  1f6e5c:      	br	x17

00000000001f6e60 <_ZN7MMCodec12MotionEffect8getAudioEPNS_10AudioFrameEl@plt>:
  1f6e60:      	adrp	x16, 0x204000
  1f6e64:      	ldr	x17, [x16, #0x8e0]
  1f6e68:      	add	x16, x16, #0x8e0
  1f6e6c:      	br	x17

00000000001f6e70 <_ZNK7MMCodec12MotionEffect14getEffectParamEv@plt>:
  1f6e70:      	adrp	x16, 0x204000
  1f6e74:      	ldr	x17, [x16, #0x8e8]
  1f6e78:      	add	x16, x16, #0x8e8
  1f6e7c:      	br	x17

00000000001f6e80 <_ZN7MMCodec12MotionEffectC1ERKNS_17MotionEffectParamERKNS_14AudioParameterE@plt>:
  1f6e80:      	adrp	x16, 0x204000
  1f6e84:      	ldr	x17, [x16, #0x8f0]
  1f6e88:      	add	x16, x16, #0x8f0
  1f6e8c:      	br	x17

00000000001f6e90 <_ZN7MMCodec19MotionEffectManagerD1Ev@plt>:
  1f6e90:      	adrp	x16, 0x204000
  1f6e94:      	ldr	x17, [x16, #0x8f8]
  1f6e98:      	add	x16, x16, #0x8f8
  1f6e9c:      	br	x17

00000000001f6ea0 <_ZN7MMCodec19MotionEffectElementC1EPNS_12MotionEffectEdl@plt>:
  1f6ea0:      	adrp	x16, 0x204000
  1f6ea4:      	ldr	x17, [x16, #0x900]
  1f6ea8:      	add	x16, x16, #0x900
  1f6eac:      	br	x17

00000000001f6eb0 <_ZNSt6__ndk16vectorIN7MMCodec17MotionEffectParamENS_9allocatorIS2_EEE21__push_back_slow_pathIRKS2_EEPS2_OT_@plt>:
  1f6eb0:      	adrp	x16, 0x204000
  1f6eb4:      	ldr	x17, [x16, #0x908]
  1f6eb8:      	add	x16, x16, #0x908
  1f6ebc:      	br	x17

00000000001f6ec0 <_ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE5clearEv@plt>:
  1f6ec0:      	adrp	x16, 0x204000
  1f6ec4:      	ldr	x17, [x16, #0x910]
  1f6ec8:      	add	x16, x16, #0x910
  1f6ecc:      	br	x17

00000000001f6ed0 <_ZN7MMCodec10ObjectPoolI7AVFrameE5clearEv@plt>:
  1f6ed0:      	adrp	x16, 0x204000
  1f6ed4:      	ldr	x17, [x16, #0x918]
  1f6ed8:      	add	x16, x16, #0x918
  1f6edc:      	br	x17

00000000001f6ee0 <_ZN7MMCodec10ObjectPoolI8AVPacketE5clearEv@plt>:
  1f6ee0:      	adrp	x16, 0x204000
  1f6ee4:      	ldr	x17, [x16, #0x920]
  1f6ee8:      	add	x16, x16, #0x920
  1f6eec:      	br	x17

00000000001f6ef0 <_ZN7MMCodec14AICodecContextD1Ev@plt>:
  1f6ef0:      	adrp	x16, 0x204000
  1f6ef4:      	ldr	x17, [x16, #0x928]
  1f6ef8:      	add	x16, x16, #0x928
  1f6efc:      	br	x17

00000000001f6f00 <_ZN7MMCodec14AICodecContext12acquireFrameEv@plt>:
  1f6f00:      	adrp	x16, 0x204000
  1f6f04:      	ldr	x17, [x16, #0x930]
  1f6f08:      	add	x16, x16, #0x930
  1f6f0c:      	br	x17

00000000001f6f10 <_ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE14acquire_objectIJPNS_14AICodecContextEEEERS1_DpT_@plt>:
  1f6f10:      	adrp	x16, 0x204000
  1f6f14:      	ldr	x17, [x16, #0x938]
  1f6f18:      	add	x16, x16, #0x938
  1f6f1c:      	br	x17

00000000001f6f20 <_ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE14allocate_chunkIJPNS_14AICodecContextEEEEvDpT_@plt>:
  1f6f20:      	adrp	x16, 0x204000
  1f6f24:      	ldr	x17, [x16, #0x940]
  1f6f28:      	add	x16, x16, #0x940
  1f6f2c:      	br	x17

00000000001f6f30 <_ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE@plt>:
  1f6f30:      	adrp	x16, 0x204000
  1f6f34:      	ldr	x17, [x16, #0x948]
  1f6f38:      	add	x16, x16, #0x948
  1f6f3c:      	br	x17

00000000001f6f40 <_ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE14release_objectERS1_@plt>:
  1f6f40:      	adrp	x16, 0x204000
  1f6f44:      	ldr	x17, [x16, #0x950]
  1f6f48:      	add	x16, x16, #0x950
  1f6f4c:      	br	x17

00000000001f6f50 <_ZN7MMCodec10ObjectPoolI7AVFrameE14acquire_objectIJEEERS1_DpT_@plt>:
  1f6f50:      	adrp	x16, 0x204000
  1f6f54:      	ldr	x17, [x16, #0x958]
  1f6f58:      	add	x16, x16, #0x958
  1f6f5c:      	br	x17

00000000001f6f60 <_ZN7MMCodec10ObjectPoolI7AVFrameE14allocate_chunkIJEEEvDpT_@plt>:
  1f6f60:      	adrp	x16, 0x204000
  1f6f64:      	ldr	x17, [x16, #0x960]
  1f6f68:      	add	x16, x16, #0x960
  1f6f6c:      	br	x17

00000000001f6f70 <_ZN7MMCodec10ObjectPoolI7AVFrameE14release_objectERS1_@plt>:
  1f6f70:      	adrp	x16, 0x204000
  1f6f74:      	ldr	x17, [x16, #0x968]
  1f6f78:      	add	x16, x16, #0x968
  1f6f7c:      	br	x17

00000000001f6f80 <_ZN7MMCodec10ObjectPoolI8AVPacketE14acquire_objectIJEEERS1_DpT_@plt>:
  1f6f80:      	adrp	x16, 0x204000
  1f6f84:      	ldr	x17, [x16, #0x970]
  1f6f88:      	add	x16, x16, #0x970
  1f6f8c:      	br	x17

00000000001f6f90 <_ZN7MMCodec10ObjectPoolI8AVPacketE14allocate_chunkIJEEEvDpT_@plt>:
  1f6f90:      	adrp	x16, 0x204000
  1f6f94:      	ldr	x17, [x16, #0x978]
  1f6f98:      	add	x16, x16, #0x978
  1f6f9c:      	br	x17

00000000001f6fa0 <_ZN7MMCodec10ObjectPoolI8AVPacketE14release_objectERS1_@plt>:
  1f6fa0:      	adrp	x16, 0x204000
  1f6fa4:      	ldr	x17, [x16, #0x980]
  1f6fa8:      	add	x16, x16, #0x980
  1f6fac:      	br	x17

00000000001f6fb0 <_ZN7MMCodec12MMCodecFrameC1EPNS_14AICodecContextE@plt>:
  1f6fb0:      	adrp	x16, 0x204000
  1f6fb4:      	ldr	x17, [x16, #0x988]
  1f6fb8:      	add	x16, x16, #0x988
  1f6fbc:      	br	x17

00000000001f6fc0 <_ZN7MMCodec12MMCodecFrame14newObjectArrayEPNS_14AICodecContextEm@plt>:
  1f6fc0:      	adrp	x16, 0x204000
  1f6fc4:      	ldr	x17, [x16, #0x990]
  1f6fc8:      	add	x16, x16, #0x990
  1f6fcc:      	br	x17

00000000001f6fd0 <_ZN7MMCodec12MMCodecFrameC1Ev@plt>:
  1f6fd0:      	adrp	x16, 0x204000
  1f6fd4:      	ldr	x17, [x16, #0x998]
  1f6fd8:      	add	x16, x16, #0x998
  1f6fdc:      	br	x17

00000000001f6fe0 <_ZN7MMCodec12MMCodecFrameD1Ev@plt>:
  1f6fe0:      	adrp	x16, 0x204000
  1f6fe4:      	ldr	x17, [x16, #0x9a0]
  1f6fe8:      	add	x16, x16, #0x9a0
  1f6fec:      	br	x17

00000000001f6ff0 <av_frame_move_ref@plt>:
  1f6ff0:      	adrp	x16, 0x204000
  1f6ff4:      	ldr	x17, [x16, #0x9a8]
  1f6ff8:      	add	x16, x16, #0x9a8
  1f6ffc:      	br	x17

00000000001f7000 <_ZN7MMCodec12MMCodecFrame12allocAVFrameEv@plt>:
  1f7000:      	adrp	x16, 0x204000
  1f7004:      	ldr	x17, [x16, #0x9b0]
  1f7008:      	add	x16, x16, #0x9b0
  1f700c:      	br	x17

00000000001f7010 <_ZN7MMCodec13TextureVFrameD1Ev@plt>:
  1f7010:      	adrp	x16, 0x204000
  1f7014:      	ldr	x17, [x16, #0x9b8]
  1f7018:      	add	x16, x16, #0x9b8
  1f701c:      	br	x17

00000000001f7020 <_ZN7MMCodec12AudioParam_t13isFormatEqualERKS0_S2_@plt>:
  1f7020:      	adrp	x16, 0x204000
  1f7024:      	ldr	x17, [x16, #0x9c0]
  1f7028:      	add	x16, x16, #0x9c0
  1f702c:      	br	x17

00000000001f7030 <_ZNK7MMCodec12AudioParam_t7isValidEv@plt>:
  1f7030:      	adrp	x16, 0x204000
  1f7034:      	ldr	x17, [x16, #0x9c8]
  1f7038:      	add	x16, x16, #0x9c8
  1f703c:      	br	x17

00000000001f7040 <_ZN7MMCodec9FrameData20setInAudioDataFormatERKNS_12AudioParam_tE@plt>:
  1f7040:      	adrp	x16, 0x204000
  1f7044:      	ldr	x17, [x16, #0x9d0]
  1f7048:      	add	x16, x16, #0x9d0
  1f704c:      	br	x17

00000000001f7050 <_ZN7MMCodec9FrameData21setOutAudioDataFormatERKNS_12AudioParam_tE@plt>:
  1f7050:      	adrp	x16, 0x204000
  1f7054:      	ldr	x17, [x16, #0x9d8]
  1f7058:      	add	x16, x16, #0x9d8
  1f705c:      	br	x17

00000000001f7060 <_ZN7MMCodec9FrameData21setOutVideoDataFormatERKNS_12VideoParam_tE@plt>:
  1f7060:      	adrp	x16, 0x204000
  1f7064:      	ldr	x17, [x16, #0x9e0]
  1f7068:      	add	x16, x16, #0x9e0
  1f706c:      	br	x17

00000000001f7070 <_ZN7MMCodec28AICodecFFmpegPixelDataBuffer6createEmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f7070:      	adrp	x16, 0x204000
  1f7074:      	ldr	x17, [x16, #0x9e8]
  1f7078:      	add	x16, x16, #0x9e8
  1f707c:      	br	x17

00000000001f7080 <_ZN7MMCodec17AICodecDataBuffer30setAICodecDataBufferOriginTypeENS_27AICodecDataBufferOriginTypeE@plt>:
  1f7080:      	adrp	x16, 0x204000
  1f7084:      	ldr	x17, [x16, #0x9f0]
  1f7088:      	add	x16, x16, #0x9f0
  1f708c:      	br	x17

00000000001f7090 <_ZN7MMCodec28AICodecFFmpegPixelDataBuffer16transferAndWriteEP7AVFrameNS_16VIDEO_PIX_FORMATE@plt>:
  1f7090:      	adrp	x16, 0x204000
  1f7094:      	ldr	x17, [x16, #0x9f8]
  1f7098:      	add	x16, x16, #0x9f8
  1f709c:      	br	x17

00000000001f70a0 <_ZN7MMCodec28AICodecFFmpegAudioDataBuffer16transferAndWriteEP7AVFramePKv@plt>:
  1f70a0:      	adrp	x16, 0x204000
  1f70a4:      	ldr	x17, [x16, #0xa00]
  1f70a8:      	add	x16, x16, #0xa00
  1f70ac:      	br	x17

00000000001f70b0 <_ZN7MMCodec30AICodecOpenGLTextureDataBuffer6createEmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f70b0:      	adrp	x16, 0x204000
  1f70b4:      	ldr	x17, [x16, #0xa08]
  1f70b8:      	add	x16, x16, #0xa08
  1f70bc:      	br	x17

00000000001f70c0 <_ZN7MMCodec30AICodecOpenGLTextureDataBuffer16transferAndWriteEjmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f70c0:      	adrp	x16, 0x204000
  1f70c4:      	ldr	x17, [x16, #0xa10]
  1f70c8:      	add	x16, x16, #0xa10
  1f70cc:      	br	x17

00000000001f70d0 <_ZN7MMCodec9FrameData5resetEv@plt>:
  1f70d0:      	adrp	x16, 0x204000
  1f70d4:      	ldr	x17, [x16, #0xa18]
  1f70d8:      	add	x16, x16, #0xa18
  1f70dc:      	br	x17

00000000001f70e0 <_ZN7MMCodec9FrameData30getPrimalPresentationTimestampEv@plt>:
  1f70e0:      	adrp	x16, 0x204000
  1f70e4:      	ldr	x17, [x16, #0xa20]
  1f70e8:      	add	x16, x16, #0xa20
  1f70ec:      	br	x17

00000000001f70f0 <_ZN7MMCodec9FrameData10getFrameIdEv@plt>:
  1f70f0:      	adrp	x16, 0x204000
  1f70f4:      	ldr	x17, [x16, #0xa28]
  1f70f8:      	add	x16, x16, #0xa28
  1f70fc:      	br	x17

00000000001f7100 <_ZNK7MMCodec9FrameData16getOutDataBufferEv@plt>:
  1f7100:      	adrp	x16, 0x204000
  1f7104:      	ldr	x17, [x16, #0xa30]
  1f7108:      	add	x16, x16, #0xa30
  1f710c:      	br	x17

00000000001f7110 <_ZN7MMCodec9FrameData31purgeCodecDataBeforeTearingDownEv@plt>:
  1f7110:      	adrp	x16, 0x204000
  1f7114:      	ldr	x17, [x16, #0xa38]
  1f7118:      	add	x16, x16, #0xa38
  1f711c:      	br	x17

00000000001f7120 <_ZNK7MMCodec17AICodecDataBuffer30getAICodecDataBufferOriginTypeEv@plt>:
  1f7120:      	adrp	x16, 0x204000
  1f7124:      	ldr	x17, [x16, #0xa40]
  1f7128:      	add	x16, x16, #0xa40
  1f712c:      	br	x17

00000000001f7130 <_ZN7MMCodec9FrameData7cleanupEv@plt>:
  1f7130:      	adrp	x16, 0x204000
  1f7134:      	ldr	x17, [x16, #0xa48]
  1f7138:      	add	x16, x16, #0xa48
  1f713c:      	br	x17

00000000001f7140 <_ZN7MMCodec9FrameDataC1Ev@plt>:
  1f7140:      	adrp	x16, 0x204000
  1f7144:      	ldr	x17, [x16, #0xa50]
  1f7148:      	add	x16, x16, #0xa50
  1f714c:      	br	x17

00000000001f7150 <_ZN7MMCodec9FrameDataD1Ev@plt>:
  1f7150:      	adrp	x16, 0x204000
  1f7154:      	ldr	x17, [x16, #0xa58]
  1f7158:      	add	x16, x16, #0xa58
  1f715c:      	br	x17

00000000001f7160 <pthread_setname_np@plt>:
  1f7160:      	adrp	x16, 0x204000
  1f7164:      	ldr	x17, [x16, #0xa60]
  1f7168:      	add	x16, x16, #0xa60
  1f716c:      	br	x17

00000000001f7170 <pthread_join@plt>:
  1f7170:      	adrp	x16, 0x204000
  1f7174:      	ldr	x17, [x16, #0xa68]
  1f7178:      	add	x16, x16, #0xa68
  1f717c:      	br	x17

00000000001f7180 <_ZN7MMCodec16ThreadITCContext5condVEv@plt>:
  1f7180:      	adrp	x16, 0x204000
  1f7184:      	ldr	x17, [x16, #0xa70]
  1f7188:      	add	x16, x16, #0xa70
  1f718c:      	br	x17

00000000001f7190 <_ZN7MMCodec6AVIRefD1Ev@plt>:
  1f7190:      	adrp	x16, 0x204000
  1f7194:      	ldr	x17, [x16, #0xa78]
  1f7198:      	add	x16, x16, #0xa78
  1f719c:      	br	x17

00000000001f71a0 <_ZN7MMCodec17AICodecDataBufferD1Ev@plt>:
  1f71a0:      	adrp	x16, 0x204000
  1f71a4:      	ldr	x17, [x16, #0xa80]
  1f71a8:      	add	x16, x16, #0xa80
  1f71ac:      	br	x17

00000000001f71b0 <_ZNK7MMCodec17AICodecDataBuffer24getAICodecDataBufferTypeEv@plt>:
  1f71b0:      	adrp	x16, 0x204000
  1f71b4:      	ldr	x17, [x16, #0xa88]
  1f71b8:      	add	x16, x16, #0xa88
  1f71bc:      	br	x17

00000000001f71c0 <_ZN7MMCodec28AICodecFFmpegAudioDataBufferC1EPKv@plt>:
  1f71c0:      	adrp	x16, 0x204000
  1f71c4:      	ldr	x17, [x16, #0xa90]
  1f71c8:      	add	x16, x16, #0xa90
  1f71cc:      	br	x17

00000000001f71d0 <av_frame_free@plt>:
  1f71d0:      	adrp	x16, 0x204000
  1f71d4:      	ldr	x17, [x16, #0xa98]
  1f71d8:      	add	x16, x16, #0xa98
  1f71dc:      	br	x17

00000000001f71e0 <_ZN7MMCodec28AICodecFFmpegAudioDataBufferD1Ev@plt>:
  1f71e0:      	adrp	x16, 0x204000
  1f71e4:      	ldr	x17, [x16, #0xaa0]
  1f71e8:      	add	x16, x16, #0xaa0
  1f71ec:      	br	x17

00000000001f71f0 <av_fast_realloc@plt>:
  1f71f0:      	adrp	x16, 0x204000
  1f71f4:      	ldr	x17, [x16, #0xaa8]
  1f71f8:      	add	x16, x16, #0xaa8
  1f71fc:      	br	x17

00000000001f7200 <av_samples_copy@plt>:
  1f7200:      	adrp	x16, 0x204000
  1f7204:      	ldr	x17, [x16, #0xab0]
  1f7208:      	add	x16, x16, #0xab0
  1f720c:      	br	x17

00000000001f7210 <av_frame_ref@plt>:
  1f7210:      	adrp	x16, 0x204000
  1f7214:      	ldr	x17, [x16, #0xab8]
  1f7218:      	add	x16, x16, #0xab8
  1f721c:      	br	x17

00000000001f7220 <_ZNK7MMCodec28AICodecFFmpegAudioDataBuffer11getDataSizeEv@plt>:
  1f7220:      	adrp	x16, 0x204000
  1f7224:      	ldr	x17, [x16, #0xac0]
  1f7228:      	add	x16, x16, #0xac0
  1f722c:      	br	x17

00000000001f7230 <_ZN7MMCodec28AICodecFFmpegAudioDataBuffer16resampleByEffectERlPNS_18SpeedEffectManagerEPNS_19MotionEffectManagerE@plt>:
  1f7230:      	adrp	x16, 0x204000
  1f7234:      	ldr	x17, [x16, #0xac8]
  1f7238:      	add	x16, x16, #0xac8
  1f723c:      	br	x17

00000000001f7240 <_ZN7MMCodec22AICodecVideoDataBufferD1Ev@plt>:
  1f7240:      	adrp	x16, 0x204000
  1f7244:      	ldr	x17, [x16, #0xad0]
  1f7248:      	add	x16, x16, #0xad0
  1f724c:      	br	x17

00000000001f7250 <_ZNK7MMCodec22AICodecVideoDataBuffer14getVideoFormatEv@plt>:
  1f7250:      	adrp	x16, 0x204000
  1f7254:      	ldr	x17, [x16, #0xad8]
  1f7258:      	add	x16, x16, #0xad8
  1f725c:      	br	x17

00000000001f7260 <_ZN7MMCodec28AICodecFFmpegPixelDataBufferC1EmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f7260:      	adrp	x16, 0x204000
  1f7264:      	ldr	x17, [x16, #0xae0]
  1f7268:      	add	x16, x16, #0xae0
  1f726c:      	br	x17

00000000001f7270 <_ZN7MMCodec28AICodecFFmpegPixelDataBufferD1Ev@plt>:
  1f7270:      	adrp	x16, 0x204000
  1f7274:      	ldr	x17, [x16, #0xae8]
  1f7278:      	add	x16, x16, #0xae8
  1f727c:      	br	x17

00000000001f7280 <_ZN7MMCodec15VideoFrameUtils5scaleEPKPKhPKimiiiiiPPhPiRm@plt>:
  1f7280:      	adrp	x16, 0x204000
  1f7284:      	ldr	x17, [x16, #0xaf0]
  1f7288:      	add	x16, x16, #0xaf0
  1f728c:      	br	x17

00000000001f7290 <_ZN7MMCodec30AICodecOpenGLTextureDataBufferC1EmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f7290:      	adrp	x16, 0x204000
  1f7294:      	ldr	x17, [x16, #0xaf8]
  1f7298:      	add	x16, x16, #0xaf8
  1f729c:      	br	x17

00000000001f72a0 <_ZN7MMCodec30AICodecOpenGLTextureDataBufferD1Ev@plt>:
  1f72a0:      	adrp	x16, 0x204000
  1f72a4:      	ldr	x17, [x16, #0xb00]
  1f72a8:      	add	x16, x16, #0xb00
  1f72ac:      	br	x17

00000000001f72b0 <_ZN7MMCodec16OpenGLHWSContext6createEiiNS_16VIDEO_PIX_FORMATEiiS1_@plt>:
  1f72b0:      	adrp	x16, 0x204000
  1f72b4:      	ldr	x17, [x16, #0xb08]
  1f72b8:      	add	x16, x16, #0xb08
  1f72bc:      	br	x17

00000000001f72c0 <_ZN7MMCodec16OpenGLHWSContext12setHWUtilityEPNS_9HWUtilityE@plt>:
  1f72c0:      	adrp	x16, 0x204000
  1f72c4:      	ldr	x17, [x16, #0xb10]
  1f72c8:      	add	x16, x16, #0xb10
  1f72cc:      	br	x17

00000000001f72d0 <_ZN7MMCodec16OpenGLHWSContext20setColorspaceDetailsEiiii@plt>:
  1f72d0:      	adrp	x16, 0x204000
  1f72d4:      	ldr	x17, [x16, #0xb18]
  1f72d8:      	add	x16, x16, #0xb18
  1f72dc:      	br	x17

00000000001f72e0 <_ZN7MMCodec2GL13bindTexture2DEj@plt>:
  1f72e0:      	adrp	x16, 0x204000
  1f72e4:      	ldr	x17, [x16, #0xb20]
  1f72e8:      	add	x16, x16, #0xb20
  1f72ec:      	br	x17

00000000001f72f0 <_ZN7MMCodec16OpenGLHWSContext8transferEPKPKhPiPKPhS5_@plt>:
  1f72f0:      	adrp	x16, 0x204000
  1f72f4:      	ldr	x17, [x16, #0xb28]
  1f72f8:      	add	x16, x16, #0xb28
  1f72fc:      	br	x17

00000000001f7300 <_ZNK7MMCodec30AICodecOpenGLTextureDataBuffer16getOpenGLTextureEv@plt>:
  1f7300:      	adrp	x16, 0x204000
  1f7304:      	ldr	x17, [x16, #0xb30]
  1f7308:      	add	x16, x16, #0xb30
  1f730c:      	br	x17

00000000001f7310 <_ZN7MMCodec26AICodecDataVideoBufferPoolC1ENS_21AICodecDataBufferTypeEmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f7310:      	adrp	x16, 0x204000
  1f7314:      	ldr	x17, [x16, #0xb38]
  1f7318:      	add	x16, x16, #0xb38
  1f731c:      	br	x17

00000000001f7320 <_ZN7MMCodec24AICodecDataBufferUtility6createEv@plt>:
  1f7320:      	adrp	x16, 0x204000
  1f7324:      	ldr	x17, [x16, #0xb40]
  1f7328:      	add	x16, x16, #0xb40
  1f732c:      	br	x17

00000000001f7330 <_ZN7MMCodec24AICodecDataBufferUtilityC1Ev@plt>:
  1f7330:      	adrp	x16, 0x204000
  1f7334:      	ldr	x17, [x16, #0xb48]
  1f7338:      	add	x16, x16, #0xb48
  1f733c:      	br	x17

00000000001f7340 <_ZN7MMCodec24AICodecDataBufferUtilityD1Ev@plt>:
  1f7340:      	adrp	x16, 0x204000
  1f7344:      	ldr	x17, [x16, #0xb50]
  1f7348:      	add	x16, x16, #0xb50
  1f734c:      	br	x17

00000000001f7350 <_ZN7MMCodec24AICodecDataBufferUtility29createOpenGLTextureDataBufferEPNS_30AICodecOpenGLTextureDataBufferEmmNS_16VIDEO_PIX_FORMATE@plt>:
  1f7350:      	adrp	x16, 0x204000
  1f7354:      	ldr	x17, [x16, #0xb58]
  1f7358:      	add	x16, x16, #0xb58
  1f735c:      	br	x17

00000000001f7360 <_ZN7MMCodec24AICodecDataBufferUtility29createOpenGLTextureDataBufferEPNS_30AICodecOpenGLTextureDataBufferERS2_@plt>:
  1f7360:      	adrp	x16, 0x204000
  1f7364:      	ldr	x17, [x16, #0xb60]
  1f7368:      	add	x16, x16, #0xb60
  1f736c:      	br	x17

00000000001f7370 <_ZN7MMCodec19AICodecSampleBufferC1ENS_22AICodecSampleMediaTypeE@plt>:
  1f7370:      	adrp	x16, 0x204000
  1f7374:      	ldr	x17, [x16, #0xb68]
  1f7378:      	add	x16, x16, #0xb68
  1f737c:      	br	x17

00000000001f7380 <_ZN7MMCodec19AICodecSampleBufferD1Ev@plt>:
  1f7380:      	adrp	x16, 0x204000
  1f7384:      	ldr	x17, [x16, #0xb70]
  1f7388:      	add	x16, x16, #0xb70
  1f738c:      	br	x17

00000000001f7390 <_ZNK7MMCodec19AICodecSampleBuffer12getFrameDataEv@plt>:
  1f7390:      	adrp	x16, 0x204000
  1f7394:      	ldr	x17, [x16, #0xb78]
  1f7398:      	add	x16, x16, #0xb78
  1f739c:      	br	x17

00000000001f73a0 <_ZN7MMCodec19AICodecSampleBuffer6setKeyEPv@plt>:
  1f73a0:      	adrp	x16, 0x204000
  1f73a4:      	ldr	x17, [x16, #0xb80]
  1f73a8:      	add	x16, x16, #0xb80
  1f73ac:      	br	x17

00000000001f73b0 <_ZNK7MMCodec19AICodecSampleBuffer6getKeyEv@plt>:
  1f73b0:      	adrp	x16, 0x204000
  1f73b4:      	ldr	x17, [x16, #0xb88]
  1f73b8:      	add	x16, x16, #0xb88
  1f73bc:      	br	x17

00000000001f73c0 <_ZN7MMCodec19AICodecSampleBuffer29setReusingOnceGetSampleBufferEb@plt>:
  1f73c0:      	adrp	x16, 0x204000
  1f73c4:      	ldr	x17, [x16, #0xb90]
  1f73c8:      	add	x16, x16, #0xb90
  1f73cc:      	br	x17

00000000001f73d0 <_ZN7MMCodec19AICodecSampleBuffer30setPrimalPresentationTimestampEl@plt>:
  1f73d0:      	adrp	x16, 0x204000
  1f73d4:      	ldr	x17, [x16, #0xb98]
  1f73d8:      	add	x16, x16, #0xb98
  1f73dc:      	br	x17

00000000001f73e0 <_ZNK7MMCodec19AICodecSampleBuffer30getPrimalPresentationTimestampEv@plt>:
  1f73e0:      	adrp	x16, 0x204000
  1f73e4:      	ldr	x17, [x16, #0xba0]
  1f73e8:      	add	x16, x16, #0xba0
  1f73ec:      	br	x17

00000000001f73f0 <_ZN7MMCodec23AICodecSampleBufferPool6createENS_22AICodecSampleMediaTypeE@plt>:
  1f73f0:      	adrp	x16, 0x204000
  1f73f4:      	ldr	x17, [x16, #0xba8]
  1f73f8:      	add	x16, x16, #0xba8
  1f73fc:      	br	x17

00000000001f7400 <_ZN7MMCodec23AICodecSampleBufferPoolC1ENS_22AICodecSampleMediaTypeE@plt>:
  1f7400:      	adrp	x16, 0x204000
  1f7404:      	ldr	x17, [x16, #0xbb0]
  1f7408:      	add	x16, x16, #0xbb0
  1f740c:      	br	x17

00000000001f7410 <_ZN7MMCodec23AICodecSampleBufferPool25createAICodecSampleBufferEv@plt>:
  1f7410:      	adrp	x16, 0x204000
  1f7414:      	ldr	x17, [x16, #0xbb8]
  1f7418:      	add	x16, x16, #0xbb8
  1f741c:      	br	x17

00000000001f7420 <_ZN7MMCodec23AICodecSampleBufferPool26releaseAICodecSampleBufferERPNS_19AICodecSampleBufferE@plt>:
  1f7420:      	adrp	x16, 0x204000
  1f7424:      	ldr	x17, [x16, #0xbc0]
  1f7428:      	add	x16, x16, #0xbc0
  1f742c:      	br	x17

00000000001f7430 <_ZN7MMCodec23AICodecSampleBufferPool31purgeCodecDataBeforeTearingDownEv@plt>:
  1f7430:      	adrp	x16, 0x204000
  1f7434:      	ldr	x17, [x16, #0xbc8]
  1f7438:      	add	x16, x16, #0xbc8
  1f743c:      	br	x17

00000000001f7440 <_ZN7MMCodec23AICodecSampleBufferPool7cleanupEv@plt>:
  1f7440:      	adrp	x16, 0x204000
  1f7444:      	ldr	x17, [x16, #0xbd0]
  1f7448:      	add	x16, x16, #0xbd0
  1f744c:      	br	x17

00000000001f7450 <_ZN7MMCodec23AICodecSampleBufferPoolD1Ev@plt>:
  1f7450:      	adrp	x16, 0x204000
  1f7454:      	ldr	x17, [x16, #0xbd8]
  1f7458:      	add	x16, x16, #0xbd8
  1f745c:      	br	x17

00000000001f7460 <_ZN7MMCodec16OpenGLHWSContextC1EiiNS_16VIDEO_PIX_FORMATEiiS1_@plt>:
  1f7460:      	adrp	x16, 0x204000
  1f7464:      	ldr	x17, [x16, #0xbe0]
  1f7468:      	add	x16, x16, #0xbe0
  1f746c:      	br	x17

00000000001f7470 <_ZN7MMCodec16OpenGLHWSContextD1Ev@plt>:
  1f7470:      	adrp	x16, 0x204000
  1f7474:      	ldr	x17, [x16, #0xbe8]
  1f7478:      	add	x16, x16, #0xbe8
  1f747c:      	br	x17

00000000001f7480 <_ZN7MMCodec9HWUtilityD1Ev@plt>:
  1f7480:      	adrp	x16, 0x204000
  1f7484:      	ldr	x17, [x16, #0xbf0]
  1f7488:      	add	x16, x16, #0xbf0
  1f748c:      	br	x17

00000000001f7490 <_ZNSt6__ndk14pairIKNS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEN7MMCodec12HWCapabilityEED2Ev@plt>:
  1f7490:      	adrp	x16, 0x204000
  1f7494:      	ldr	x17, [x16, #0xbf8]
  1f7498:      	add	x16, x16, #0xbf8
  1f749c:      	br	x17

00000000001f74a0 <_ZNSt6__ndk13mapINS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEN7MMCodec12HWCapabilityENS_4lessIS6_EENS4_INS_4pairIKS6_S8_EEEEEC2B8ne180000IPKSD_EET_SJ_RKSA_@plt>:
  1f74a0:      	adrp	x16, 0x204000
  1f74a4:      	ldr	x17, [x16, #0xc00]
  1f74a8:      	add	x16, x16, #0xc00
  1f74ac:      	br	x17

00000000001f74b0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEN7MMCodec12HWCapabilityEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorISA_PNS_11__tree_nodeISA_SJ_EElEERPNS_15__tree_end_nodeISL_EESM_RKT_@plt>:
  1f74b0:      	adrp	x16, 0x204000
  1f74b4:      	ldr	x17, [x16, #0xc08]
  1f74b8:      	add	x16, x16, #0xc08
  1f74bc:      	br	x17

00000000001f74c0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEN7MMCodec12HWCapabilityEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE16__construct_nodeIJRKNS_4pairIKS7_S9_EEEEENS_10unique_ptrINS_11__tree_nodeISA_PvEENS_22__tree_node_destructorINS5_ISQ_EEEEEEDpOT_@plt>:
  1f74c0:      	adrp	x16, 0x204000
  1f74c4:      	ldr	x17, [x16, #0xc10]
  1f74c8:      	add	x16, x16, #0xc10
  1f74cc:      	br	x17

00000000001f74d0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE25__init_copy_ctor_externalEPKwm@plt>:
  1f74d0:      	adrp	x16, 0x204000
  1f74d4:      	ldr	x17, [x16, #0xc18]
  1f74d8:      	add	x16, x16, #0xc18
  1f74dc:      	br	x17

00000000001f74e0 <_ZNKSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEN7MMCodec12HWCapabilityEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE4findIS7_EENS_21__tree_const_iteratorISA_PNS_11__tree_nodeISA_PvEElEERKT_@plt>:
  1f74e0:      	adrp	x16, 0x204000
  1f74e4:      	ldr	x17, [x16, #0xc20]
  1f74e8:      	add	x16, x16, #0xc20
  1f74ec:      	br	x17

00000000001f74f0 <wmemchr@plt>:
  1f74f0:      	adrp	x16, 0x204000
  1f74f4:      	ldr	x17, [x16, #0xc28]
  1f74f8:      	add	x16, x16, #0xc28
  1f74fc:      	br	x17

00000000001f7500 <wmemcmp@plt>:
  1f7500:      	adrp	x16, 0x204000
  1f7504:      	ldr	x17, [x16, #0xc30]
  1f7508:      	add	x16, x16, #0xc30
  1f750c:      	br	x17

00000000001f7510 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6assignEPKw@plt>:
  1f7510:      	adrp	x16, 0x204000
  1f7514:      	ldr	x17, [x16, #0xc38]
  1f7518:      	add	x16, x16, #0xc38
  1f751c:      	br	x17

00000000001f7520 <_ZN7MMCodec13getColorDepthE13AVPixelFormat@plt>:
  1f7520:      	adrp	x16, 0x204000
  1f7524:      	ldr	x17, [x16, #0xc40]
  1f7528:      	add	x16, x16, #0xc40
  1f752c:      	br	x17

00000000001f7530 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEEEN7MMCodec12HWCapabilityEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE12__find_equalIS7_EERPNS_16__tree_node_baseIPvEERPNS_15__tree_end_nodeISL_EERKT_@plt>:
  1f7530:      	adrp	x16, 0x204000
  1f7534:      	ldr	x17, [x16, #0xc48]
  1f7538:      	add	x16, x16, #0xc48
  1f753c:      	br	x17

00000000001f7540 <av_log_get_level@plt>:
  1f7540:      	adrp	x16, 0x204000
  1f7544:      	ldr	x17, [x16, #0xc50]
  1f7548:      	add	x16, x16, #0xc50
  1f754c:      	br	x17

00000000001f7550 <av_log_format_line@plt>:
  1f7550:      	adrp	x16, 0x204000
  1f7554:      	ldr	x17, [x16, #0xc58]
  1f7558:      	add	x16, x16, #0xc58
  1f755c:      	br	x17

00000000001f7560 <_ZN7MMCodec13AICodecGlobalC1Ev@plt>:
  1f7560:      	adrp	x16, 0x204000
  1f7564:      	ldr	x17, [x16, #0xc60]
  1f7568:      	add	x16, x16, #0xc60
  1f756c:      	br	x17

00000000001f7570 <av_log_set_callback@plt>:
  1f7570:      	adrp	x16, 0x204000
  1f7574:      	ldr	x17, [x16, #0xc68]
  1f7578:      	add	x16, x16, #0xc68
  1f757c:      	br	x17

00000000001f7580 <avformat_network_init@plt>:
  1f7580:      	adrp	x16, 0x204000
  1f7584:      	ldr	x17, [x16, #0xc70]
  1f7588:      	add	x16, x16, #0xc70
  1f758c:      	br	x17

00000000001f7590 <av_jni_set_java_vm@plt>:
  1f7590:      	adrp	x16, 0x204000
  1f7594:      	ldr	x17, [x16, #0xc78]
  1f7598:      	add	x16, x16, #0xc78
  1f759c:      	br	x17

00000000001f75a0 <_ZN7MMCodec10DeviceInfoC1Ev@plt>:
  1f75a0:      	adrp	x16, 0x204000
  1f75a4:      	ldr	x17, [x16, #0xc80]
  1f75a8:      	add	x16, x16, #0xc80
  1f75ac:      	br	x17

00000000001f75b0 <_ZN7MMCodec13AICodecGlobal11setLogLevelENS_17AICODEC_LOG_LEVELE@plt>:
  1f75b0:      	adrp	x16, 0x204000
  1f75b4:      	ldr	x17, [x16, #0xc88]
  1f75b8:      	add	x16, x16, #0xc88
  1f75bc:      	br	x17

00000000001f75c0 <_ZN7MMCodec13AICodecGlobal14setLogCallbackEPFviPKcE@plt>:
  1f75c0:      	adrp	x16, 0x204000
  1f75c4:      	ldr	x17, [x16, #0xc90]
  1f75c8:      	add	x16, x16, #0xc90
  1f75cc:      	br	x17

00000000001f75d0 <_ZN7MMCodec13AICodecGlobal19setLogCallbackLevelENS_17AICODEC_LOG_LEVELE@plt>:
  1f75d0:      	adrp	x16, 0x204000
  1f75d4:      	ldr	x17, [x16, #0xc98]
  1f75d8:      	add	x16, x16, #0xc98
  1f75dc:      	br	x17

00000000001f75e0 <_ZN7MMCodec13AICodecGlobal11flushPacketEv@plt>:
  1f75e0:      	adrp	x16, 0x204000
  1f75e4:      	ldr	x17, [x16, #0xca0]
  1f75e8:      	add	x16, x16, #0xca0
  1f75ec:      	br	x17

00000000001f75f0 <_ZN7MMCodec13AICodecGlobal10skipPacketEv@plt>:
  1f75f0:      	adrp	x16, 0x204000
  1f75f4:      	ldr	x17, [x16, #0xca8]
  1f75f8:      	add	x16, x16, #0xca8
  1f75fc:      	br	x17

00000000001f7600 <_ZN7MMCodec13AICodecGlobal13getBuildModelEv@plt>:
  1f7600:      	adrp	x16, 0x204000
  1f7604:      	ldr	x17, [x16, #0xcb0]
  1f7608:      	add	x16, x16, #0xcb0
  1f760c:      	br	x17

00000000001f7610 <__cxa_guard_acquire@plt>:
  1f7610:      	adrp	x16, 0x204000
  1f7614:      	ldr	x17, [x16, #0xcb8]
  1f7618:      	add	x16, x16, #0xcb8
  1f761c:      	br	x17

00000000001f7620 <__cxa_guard_release@plt>:
  1f7620:      	adrp	x16, 0x204000
  1f7624:      	ldr	x17, [x16, #0xcc0]
  1f7628:      	add	x16, x16, #0xcc0
  1f762c:      	br	x17

00000000001f7630 <__cxa_guard_abort@plt>:
  1f7630:      	adrp	x16, 0x204000
  1f7634:      	ldr	x17, [x16, #0xcc8]
  1f7638:      	add	x16, x16, #0xcc8
  1f763c:      	br	x17

00000000001f7640 <_ZN7MMCodec13AICodecGlobal16isHDRBlacklistedEv@plt>:
  1f7640:      	adrp	x16, 0x204000
  1f7644:      	ldr	x17, [x16, #0xcd0]
  1f7648:      	add	x16, x16, #0xcd0
  1f764c:      	br	x17

00000000001f7650 <_ZN7MMCodec13AICodecGlobal13isBlacklistedEv@plt>:
  1f7650:      	adrp	x16, 0x204000
  1f7654:      	ldr	x17, [x16, #0xcd8]
  1f7658:      	add	x16, x16, #0xcd8
  1f765c:      	br	x17

00000000001f7660 <_ZN7MMCodec13AICodecGlobal17setAndroidContextEP8_jobject@plt>:
  1f7660:      	adrp	x16, 0x204000
  1f7664:      	ldr	x17, [x16, #0xce0]
  1f7668:      	add	x16, x16, #0xce0
  1f766c:      	br	x17

00000000001f7670 <_ZN7MMCodec13InMediaHandleC1Ev@plt>:
  1f7670:      	adrp	x16, 0x204000
  1f7674:      	ldr	x17, [x16, #0xce8]
  1f7678:      	add	x16, x16, #0xce8
  1f767c:      	br	x17

00000000001f7680 <_ZN7MMCodec13MTMediaReader21releasingSampleBufferERPNS_19AICodecSampleBufferE@plt>:
  1f7680:      	adrp	x16, 0x204000
  1f7684:      	ldr	x17, [x16, #0xcf0]
  1f7688:      	add	x16, x16, #0xcf0
  1f768c:      	br	x17

00000000001f7690 <_ZN7MMCodec13MTMediaReader4openEPS0_@plt>:
  1f7690:      	adrp	x16, 0x204000
  1f7694:      	ldr	x17, [x16, #0xcf8]
  1f7698:      	add	x16, x16, #0xcf8
  1f769c:      	br	x17

00000000001f76a0 <_ZN7MMCodec13InMediaHandle4openEPKhm@plt>:
  1f76a0:      	adrp	x16, 0x204000
  1f76a4:      	ldr	x17, [x16, #0xd00]
  1f76a8:      	add	x16, x16, #0xd00
  1f76ac:      	br	x17

00000000001f76b0 <_ZN7MMCodec13InMediaHandle4openEPKcPS0_@plt>:
  1f76b0:      	adrp	x16, 0x204000
  1f76b4:      	ldr	x17, [x16, #0xd08]
  1f76b8:      	add	x16, x16, #0xd08
  1f76bc:      	br	x17

00000000001f76c0 <_ZN7MMCodec13MTMediaReader16switchAudioTrackEi@plt>:
  1f76c0:      	adrp	x16, 0x204000
  1f76c4:      	ldr	x17, [x16, #0xd10]
  1f76c8:      	add	x16, x16, #0xd10
  1f76cc:      	br	x17

00000000001f76d0 <_ZN7MMCodec13InMediaHandle9isPictureEi@plt>:
  1f76d0:      	adrp	x16, 0x204000
  1f76d4:      	ldr	x17, [x16, #0xd18]
  1f76d8:      	add	x16, x16, #0xd18
  1f76dc:      	br	x17

00000000001f76e0 <_ZN7MMCodec13MTMediaReader13dumpMediaInfoEv@plt>:
  1f76e0:      	adrp	x16, 0x204000
  1f76e4:      	ldr	x17, [x16, #0xd20]
  1f76e8:      	add	x16, x16, #0xd20
  1f76ec:      	br	x17

00000000001f76f0 <_ZNK7MMCodec13MTMediaReader10isHDRMediaEv@plt>:
  1f76f0:      	adrp	x16, 0x204000
  1f76f4:      	ldr	x17, [x16, #0xd28]
  1f76f8:      	add	x16, x16, #0xd28
  1f76fc:      	br	x17

00000000001f7700 <_ZN7MMCodec13MTMediaReader7cleanupEv@plt>:
  1f7700:      	adrp	x16, 0x204000
  1f7704:      	ldr	x17, [x16, #0xd30]
  1f7708:      	add	x16, x16, #0xd30
  1f770c:      	br	x17

00000000001f7710 <_ZN7MMCodec13MTMediaReader18setScaleVideoFrameEf@plt>:
  1f7710:      	adrp	x16, 0x204000
  1f7714:      	ldr	x17, [x16, #0xd38]
  1f7718:      	add	x16, x16, #0xd38
  1f771c:      	br	x17

00000000001f7720 <_ZN7MMCodec13MTMediaReader14setVideoFormatENS_16VIDEO_PIX_FORMATE@plt>:
  1f7720:      	adrp	x16, 0x204000
  1f7724:      	ldr	x17, [x16, #0xd40]
  1f7728:      	add	x16, x16, #0xd40
  1f772c:      	br	x17

00000000001f7730 <_ZN7MMCodec13MTMediaReader17getOutVideoFormatEv@plt>:
  1f7730:      	adrp	x16, 0x204000
  1f7734:      	ldr	x17, [x16, #0xd48]
  1f7738:      	add	x16, x16, #0xd48
  1f773c:      	br	x17

00000000001f7740 <_ZN7MMCodec13InMediaHandle17getOutVideoFormatEi@plt>:
  1f7740:      	adrp	x16, 0x204000
  1f7744:      	ldr	x17, [x16, #0xd50]
  1f7748:      	add	x16, x16, #0xd50
  1f774c:      	br	x17

00000000001f7750 <_ZN7MMCodec13MTMediaReader17getOutAudioFormatEv@plt>:
  1f7750:      	adrp	x16, 0x204000
  1f7754:      	ldr	x17, [x16, #0xd58]
  1f7758:      	add	x16, x16, #0xd58
  1f775c:      	br	x17

00000000001f7760 <_ZN7MMCodec13MTMediaReader19getOutAudioChannelsEv@plt>:
  1f7760:      	adrp	x16, 0x204000
  1f7764:      	ldr	x17, [x16, #0xd60]
  1f7768:      	add	x16, x16, #0xd60
  1f776c:      	br	x17

00000000001f7770 <_ZN7MMCodec13MTMediaReader21getOutAudioSampleRateEv@plt>:
  1f7770:      	adrp	x16, 0x204000
  1f7774:      	ldr	x17, [x16, #0xd68]
  1f7778:      	add	x16, x16, #0xd68
  1f777c:      	br	x17

00000000001f7780 <_ZN7MMCodec13InMediaHandle23setEnableSeekFrameCacheEb@plt>:
  1f7780:      	adrp	x16, 0x204000
  1f7784:      	ldr	x17, [x16, #0xd70]
  1f7788:      	add	x16, x16, #0xd70
  1f778c:      	br	x17

00000000001f7790 <_ZN7MMCodec13MTMediaReader27setEnableDecodeKeyFrameOnlyEb@plt>:
  1f7790:      	adrp	x16, 0x204000
  1f7794:      	ldr	x17, [x16, #0xd78]
  1f7798:      	add	x16, x16, #0xd78
  1f779c:      	br	x17

00000000001f77a0 <_ZN7MMCodec13InMediaHandle27setEnableDecodeKeyFrameOnlyEb@plt>:
  1f77a0:      	adrp	x16, 0x204000
  1f77a4:      	ldr	x17, [x16, #0xd80]
  1f77a8:      	add	x16, x16, #0xd80
  1f77ac:      	br	x17

00000000001f77b0 <_ZN7MMCodec13InMediaHandle29setSpeedShiftEffectManagerRefEPNS_18SpeedEffectManagerE@plt>:
  1f77b0:      	adrp	x16, 0x204000
  1f77b4:      	ldr	x17, [x16, #0xd88]
  1f77b8:      	add	x16, x16, #0xd88
  1f77bc:      	br	x17

00000000001f77c0 <_ZN7MMCodec13InMediaHandle30setMotionShiftEffectManagerRefEPNS_19MotionEffectManagerE@plt>:
  1f77c0:      	adrp	x16, 0x204000
  1f77c4:      	ldr	x17, [x16, #0xd90]
  1f77c8:      	add	x16, x16, #0xd90
  1f77cc:      	br	x17

00000000001f77d0 <_ZN7MMCodec17createDemuxConfigEv@plt>:
  1f77d0:      	adrp	x16, 0x204000
  1f77d4:      	ldr	x17, [x16, #0xd98]
  1f77d8:      	add	x16, x16, #0xd98
  1f77dc:      	br	x17

00000000001f77e0 <_ZN7MMCodec13InMediaHandle13setAttributesERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES8_NS1_4lessIS8_EENS6_INS1_4pairIKS8_S8_EEEEEE@plt>:
  1f77e0:      	adrp	x16, 0x204000
  1f77e4:      	ldr	x17, [x16, #0xda0]
  1f77e8:      	add	x16, x16, #0xda0
  1f77ec:      	br	x17

00000000001f77f0 <_ZN7MMCodec15freeDemuxConfigEPPNS_13DemuxConfig_tE@plt>:
  1f77f0:      	adrp	x16, 0x204000
  1f77f4:      	ldr	x17, [x16, #0xda8]
  1f77f8:      	add	x16, x16, #0xda8
  1f77fc:      	br	x17

00000000001f7800 <_ZN7MMCodec13MTMediaReader15getSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE@plt>:
  1f7800:      	adrp	x16, 0x204000
  1f7804:      	ldr	x17, [x16, #0xdb0]
  1f7808:      	add	x16, x16, #0xdb0
  1f780c:      	br	x17

00000000001f7810 <_ZN7MMCodec13MTMediaReader20getVideoSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE@plt>:
  1f7810:      	adrp	x16, 0x204000
  1f7814:      	ldr	x17, [x16, #0xdb8]
  1f7818:      	add	x16, x16, #0xdb8
  1f781c:      	br	x17

00000000001f7820 <_ZN7MMCodec13MTMediaReader20getAudioSampleBufferERPNS_19AICodecSampleBufferElRKNS_10ReadOptionE@plt>:
  1f7820:      	adrp	x16, 0x204000
  1f7824:      	ldr	x17, [x16, #0xdc0]
  1f7828:      	add	x16, x16, #0xdc0
  1f782c:      	br	x17

00000000001f7830 <_ZN7MMCodec13MTMediaReader19releaseSampleBufferERPNS_19AICodecSampleBufferE@plt>:
  1f7830:      	adrp	x16, 0x204000
  1f7834:      	ldr	x17, [x16, #0xdc8]
  1f7838:      	add	x16, x16, #0xdc8
  1f783c:      	br	x17

00000000001f7840 <_ZN7MMCodec13MTMediaReader9seekTo_V2Eli@plt>:
  1f7840:      	adrp	x16, 0x204000
  1f7844:      	ldr	x17, [x16, #0xdd0]
  1f7848:      	add	x16, x16, #0xdd0
  1f784c:      	br	x17

00000000001f7850 <_ZN7MMCodec13MTMediaReader21seekToWithMicrosecondEli@plt>:
  1f7850:      	adrp	x16, 0x204000
  1f7854:      	ldr	x17, [x16, #0xdd8]
  1f7858:      	add	x16, x16, #0xdd8
  1f785c:      	br	x17

00000000001f7860 <_ZN7MMCodec13MTMediaReader13setDecodeModeEi@plt>:
  1f7860:      	adrp	x16, 0x204000
  1f7864:      	ldr	x17, [x16, #0xde0]
  1f7868:      	add	x16, x16, #0xde0
  1f786c:      	br	x17

00000000001f7870 <_ZN7MMCodec13MTMediaReader16setFindFrameModeEi@plt>:
  1f7870:      	adrp	x16, 0x204000
  1f7874:      	ldr	x17, [x16, #0xde8]
  1f7878:      	add	x16, x16, #0xde8
  1f787c:      	br	x17

00000000001f7880 <_ZN7MMCodec13MTMediaReader11setReadLoopEb@plt>:
  1f7880:      	adrp	x16, 0x204000
  1f7884:      	ldr	x17, [x16, #0xdf0]
  1f7888:      	add	x16, x16, #0xdf0
  1f788c:      	br	x17

00000000001f7890 <_ZN7MMCodec13MTMediaReader19setEnableMediaCodecENSt6__ndk18functionIFbvEEE@plt>:
  1f7890:      	adrp	x16, 0x204000
  1f7894:      	ldr	x17, [x16, #0xdf8]
  1f7898:      	add	x16, x16, #0xdf8
  1f789c:      	br	x17

00000000001f78a0 <_ZN7MMCodec13MTMediaReader25setEnableFFmpegMediaCodecEb@plt>:
  1f78a0:      	adrp	x16, 0x204000
  1f78a4:      	ldr	x17, [x16, #0xe00]
  1f78a8:      	add	x16, x16, #0xe00
  1f78ac:      	br	x17

00000000001f78b0 <_ZN7MMCodec13MTMediaReader22isVideoHardwareDecoderEv@plt>:
  1f78b0:      	adrp	x16, 0x204000
  1f78b4:      	ldr	x17, [x16, #0xe08]
  1f78b8:      	add	x16, x16, #0xe08
  1f78bc:      	br	x17

00000000001f78c0 <_ZN7MMCodec13MTMediaReader25setAlwaysUpdateVideoFrameEb@plt>:
  1f78c0:      	adrp	x16, 0x204000
  1f78c4:      	ldr	x17, [x16, #0xe10]
  1f78c8:      	add	x16, x16, #0xe10
  1f78cc:      	br	x17

00000000001f78d0 <_ZN7MMCodec13MTMediaReader22setCodecStrategyConfigENS_19CodecStrategyConfigE@plt>:
  1f78d0:      	adrp	x16, 0x204000
  1f78d4:      	ldr	x17, [x16, #0xe18]
  1f78d8:      	add	x16, x16, #0xe18
  1f78dc:      	br	x17

00000000001f78e0 <_ZN7MMCodec13MTMediaReader10setThreadsEi@plt>:
  1f78e0:      	adrp	x16, 0x204000
  1f78e4:      	ldr	x17, [x16, #0xe20]
  1f78e8:      	add	x16, x16, #0xe20
  1f78ec:      	br	x17

00000000001f78f0 <_ZNK7MMCodec13InMediaHandle11getMetadataEv@plt>:
  1f78f0:      	adrp	x16, 0x204000
  1f78f4:      	ldr	x17, [x16, #0xe28]
  1f78f8:      	add	x16, x16, #0xe28
  1f78fc:      	br	x17

00000000001f7900 <_ZN7MMCodec13InMediaHandle13setTimeConfigEll@plt>:
  1f7900:      	adrp	x16, 0x204000
  1f7904:      	ldr	x17, [x16, #0xe30]
  1f7908:      	add	x16, x16, #0xe30
  1f790c:      	br	x17

00000000001f7910 <_ZN7MMCodec13MTMediaReader11setCallbackENSt6__ndk18functionIFvidPvEEE@plt>:
  1f7910:      	adrp	x16, 0x204000
  1f7914:      	ldr	x17, [x16, #0xe38]
  1f7918:      	add	x16, x16, #0xe38
  1f791c:      	br	x17

00000000001f7920 <_ZN7MMCodec13MTMediaReader19setEnableMusicCoverEb@plt>:
  1f7920:      	adrp	x16, 0x204000
  1f7924:      	ldr	x17, [x16, #0xe40]
  1f7928:      	add	x16, x16, #0xe40
  1f792c:      	br	x17

00000000001f7930 <_ZN7MMCodec13InMediaHandle19setEnableMusicCoverEb@plt>:
  1f7930:      	adrp	x16, 0x204000
  1f7934:      	ldr	x17, [x16, #0xe48]
  1f7938:      	add	x16, x16, #0xe48
  1f793c:      	br	x17

00000000001f7940 <_ZN7MMCodec13InMediaHandle16isInSameVideoGOPEll@plt>:
  1f7940:      	adrp	x16, 0x204000
  1f7944:      	ldr	x17, [x16, #0xe50]
  1f7948:      	add	x16, x16, #0xe50
  1f794c:      	br	x17

00000000001f7950 <_ZN7MMCodec13MTMediaReader20getMediaAnalysisInfoEv@plt>:
  1f7950:      	adrp	x16, 0x204000
  1f7954:      	ldr	x17, [x16, #0xe58]
  1f7958:      	add	x16, x16, #0xe58
  1f795c:      	br	x17

00000000001f7960 <_ZN7MMCodec13InMediaHandle20getMediaAnalysisInfoEv@plt>:
  1f7960:      	adrp	x16, 0x204000
  1f7964:      	ldr	x17, [x16, #0xe60]
  1f7968:      	add	x16, x16, #0xe60
  1f796c:      	br	x17

00000000001f7970 <_ZN7MMCodec13MTMediaReader19getDecodeStaticInfoEv@plt>:
  1f7970:      	adrp	x16, 0x204000
  1f7974:      	ldr	x17, [x16, #0xe68]
  1f7978:      	add	x16, x16, #0xe68
  1f797c:      	br	x17

00000000001f7980 <_ZN7MMCodec13InMediaHandle19getDecodeStaticInfoEv@plt>:
  1f7980:      	adrp	x16, 0x204000
  1f7984:      	ldr	x17, [x16, #0xe70]
  1f7988:      	add	x16, x16, #0xe70
  1f798c:      	br	x17

00000000001f7990 <_ZN7MMCodec13MTMediaReader18getPerformanceInfoEv@plt>:
  1f7990:      	adrp	x16, 0x204000
  1f7994:      	ldr	x17, [x16, #0xe78]
  1f7998:      	add	x16, x16, #0xe78
  1f799c:      	br	x17

00000000001f79a0 <_ZN7MMCodec13InMediaHandle18getPerformanceInfoEv@plt>:
  1f79a0:      	adrp	x16, 0x204000
  1f79a4:      	ldr	x17, [x16, #0xe80]
  1f79a8:      	add	x16, x16, #0xe80
  1f79ac:      	br	x17

00000000001f79b0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_22__unordered_map_hasherIiS8_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS8_SD_SB_Lb1EEENS5_IS8_EEE25__emplace_unique_key_argsIiJRKNS_21piecewise_construct_tENS_5tupleIJRKiEEENSN_IJEEEEEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEERKT_DpOT0_@plt>:
  1f79b0:      	adrp	x16, 0x204000
  1f79b4:      	ldr	x17, [x16, #0xe88]
  1f79b8:      	add	x16, x16, #0xe88
  1f79bc:      	br	x17

00000000001f79c0 <_ZN7MMCodec23getErrorCodeWithAVErrorEi@plt>:
  1f79c0:      	adrp	x16, 0x204000
  1f79c4:      	ldr	x17, [x16, #0xe90]
  1f79c8:      	add	x16, x16, #0xe90
  1f79cc:      	br	x17

00000000001f79d0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_22__unordered_map_hasherIiS8_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS8_SD_SB_Lb1EEENS5_IS8_EEE25__emplace_unique_key_argsIiJRKNS_4pairIKiS7_EEEEENSK_INS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEERKT_DpOT0_@plt>:
  1f79d0:      	adrp	x16, 0x204000
  1f79d4:      	ldr	x17, [x16, #0xe98]
  1f79d8:      	add	x16, x16, #0xe98
  1f79dc:      	br	x17

00000000001f79e0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIiNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEEENS_22__unordered_map_hasherIiS8_NS_4hashIiEENS_8equal_toIiEELb1EEENS_21__unordered_map_equalIiS8_SD_SB_Lb1EEENS5_IS8_EEE11__do_rehashILb1EEEvm@plt>:
  1f79e0:      	adrp	x16, 0x204000
  1f79e4:      	ldr	x17, [x16, #0xea0]
  1f79e8:      	add	x16, x16, #0xea0
  1f79ec:      	br	x17

00000000001f79f0 <_ZN7MMCodec18MediaHandleContext12setCodecInfoENS_16CODEC_INFO_INDEXEPKcS3_@plt>:
  1f79f0:      	adrp	x16, 0x204000
  1f79f4:      	ldr	x17, [x16, #0xea8]
  1f79f8:      	add	x16, x16, #0xea8
  1f79fc:      	br	x17

00000000001f7a00 <_ZN7MMCodec10StreamBaseC2EPNS_18MediaHandleContextE@plt>:
  1f7a00:      	adrp	x16, 0x204000
  1f7a04:      	ldr	x17, [x16, #0xeb0]
  1f7a08:      	add	x16, x16, #0xeb0
  1f7a0c:      	br	x17

00000000001f7a10 <_ZN7MMCodec10StreamBaseD2Ev@plt>:
  1f7a10:      	adrp	x16, 0x204000
  1f7a14:      	ldr	x17, [x16, #0xeb8]
  1f7a18:      	add	x16, x16, #0xeb8
  1f7a1c:      	br	x17

00000000001f7a20 <_ZN7MMCodec17FFmpegMediaStreamD1Ev@plt>:
  1f7a20:      	adrp	x16, 0x204000
  1f7a24:      	ldr	x17, [x16, #0xec0]
  1f7a28:      	add	x16, x16, #0xec0
  1f7a2c:      	br	x17

00000000001f7a30 <_ZN7MMCodec17FFmpegMediaStream23findAudioCodecDelayInfoEv@plt>:
  1f7a30:      	adrp	x16, 0x204000
  1f7a34:      	ldr	x17, [x16, #0xec8]
  1f7a38:      	add	x16, x16, #0xec8
  1f7a3c:      	br	x17

00000000001f7a40 <_ZN7MMCodec9SWDecoderC1Ei@plt>:
  1f7a40:      	adrp	x16, 0x204000
  1f7a44:      	ldr	x17, [x16, #0xed0]
  1f7a48:      	add	x16, x16, #0xed0
  1f7a4c:      	br	x17

00000000001f7a50 <av_init_packet@plt>:
  1f7a50:      	adrp	x16, 0x204000
  1f7a54:      	ldr	x17, [x16, #0xed8]
  1f7a58:      	add	x16, x16, #0xed8
  1f7a5c:      	br	x17

00000000001f7a60 <av_seek_frame@plt>:
  1f7a60:      	adrp	x16, 0x204000
  1f7a64:      	ldr	x17, [x16, #0xee0]
  1f7a68:      	add	x16, x16, #0xee0
  1f7a6c:      	br	x17

00000000001f7a70 <av_read_frame@plt>:
  1f7a70:      	adrp	x16, 0x204000
  1f7a74:      	ldr	x17, [x16, #0xee8]
  1f7a78:      	add	x16, x16, #0xee8
  1f7a7c:      	br	x17

00000000001f7a80 <_ZN7MMCodec18MediaHandleContext9isPictureEi@plt>:
  1f7a80:      	adrp	x16, 0x204000
  1f7a84:      	ldr	x17, [x16, #0xef0]
  1f7a88:      	add	x16, x16, #0xef0
  1f7a8c:      	br	x17

00000000001f7a90 <_ZN7MMCodec10FrameQueue5abortEv@plt>:
  1f7a90:      	adrp	x16, 0x204000
  1f7a94:      	ldr	x17, [x16, #0xef8]
  1f7a98:      	add	x16, x16, #0xef8
  1f7a9c:      	br	x17

00000000001f7aa0 <_ZN7MMCodec10FrameQueue11queueSignalEv@plt>:
  1f7aa0:      	adrp	x16, 0x204000
  1f7aa4:      	ldr	x17, [x16, #0xf00]
  1f7aa8:      	add	x16, x16, #0xf00
  1f7aac:      	br	x17

00000000001f7ab0 <_ZN7MMCodec18MediaHandleContext14getPacketQueueEi@plt>:
  1f7ab0:      	adrp	x16, 0x204000
  1f7ab4:      	ldr	x17, [x16, #0xf08]
  1f7ab8:      	add	x16, x16, #0xf08
  1f7abc:      	br	x17

00000000001f7ac0 <_ZN7MMCodec11PacketQueue5abortEv@plt>:
  1f7ac0:      	adrp	x16, 0x204000
  1f7ac4:      	ldr	x17, [x16, #0xf10]
  1f7ac8:      	add	x16, x16, #0xf10
  1f7acc:      	br	x17

00000000001f7ad0 <_ZN7MMCodec10FrameQueue7releaseEv@plt>:
  1f7ad0:      	adrp	x16, 0x204000
  1f7ad4:      	ldr	x17, [x16, #0xf18]
  1f7ad8:      	add	x16, x16, #0xf18
  1f7adc:      	br	x17

00000000001f7ae0 <_ZN7MMCodec10FrameQueueD1Ev@plt>:
  1f7ae0:      	adrp	x16, 0x204000
  1f7ae4:      	ldr	x17, [x16, #0xf20]
  1f7ae8:      	add	x16, x16, #0xf20
  1f7aec:      	br	x17

00000000001f7af0 <_ZN7MMCodec10FrameQueue14notifyWritableEv@plt>:
  1f7af0:      	adrp	x16, 0x204000
  1f7af4:      	ldr	x17, [x16, #0xf28]
  1f7af8:      	add	x16, x16, #0xf28
  1f7afc:      	br	x17

00000000001f7b00 <_ZN7MMCodec10FrameQueue11nbRemainingEv@plt>:
  1f7b00:      	adrp	x16, 0x204000
  1f7b04:      	ldr	x17, [x16, #0xf30]
  1f7b08:      	add	x16, x16, #0xf30
  1f7b0c:      	br	x17

00000000001f7b10 <_ZN7MMCodec10FrameQueue12peekReadableEii@plt>:
  1f7b10:      	adrp	x16, 0x204000
  1f7b14:      	ldr	x17, [x16, #0xf38]
  1f7b18:      	add	x16, x16, #0xf38
  1f7b1c:      	br	x17

00000000001f7b20 <_ZN7MMCodec11PacketQueue6serialEv@plt>:
  1f7b20:      	adrp	x16, 0x204000
  1f7b24:      	ldr	x17, [x16, #0xf40]
  1f7b28:      	add	x16, x16, #0xf40
  1f7b2c:      	br	x17

00000000001f7b30 <memchr@plt>:
  1f7b30:      	adrp	x16, 0x204000
  1f7b34:      	ldr	x17, [x16, #0xf48]
  1f7b38:      	add	x16, x16, #0xf48
  1f7b3c:      	br	x17

00000000001f7b40 <_ZN7MMCodec17FFmpegMediaStream14findDelayIndexEP7AVFrame@plt>:
  1f7b40:      	adrp	x16, 0x204000
  1f7b44:      	ldr	x17, [x16, #0xf50]
  1f7b48:      	add	x16, x16, #0xf50
  1f7b4c:      	br	x17

00000000001f7b50 <_ZN7MMCodec17FFmpegMediaStream6decodeEv@plt>:
  1f7b50:      	adrp	x16, 0x204000
  1f7b54:      	ldr	x17, [x16, #0xf58]
  1f7b58:      	add	x16, x16, #0xf58
  1f7b5c:      	br	x17

00000000001f7b60 <_ZN7MMCodec10FrameQueue10getEofFlagEv@plt>:
  1f7b60:      	adrp	x16, 0x204000
  1f7b64:      	ldr	x17, [x16, #0xf60]
  1f7b68:      	add	x16, x16, #0xf60
  1f7b6c:      	br	x17

00000000001f7b70 <_ZN7MMCodec11PacketQueue5isEofEv@plt>:
  1f7b70:      	adrp	x16, 0x204000
  1f7b74:      	ldr	x17, [x16, #0xf68]
  1f7b78:      	add	x16, x16, #0xf68
  1f7b7c:      	br	x17

00000000001f7b80 <av_fast_malloc@plt>:
  1f7b80:      	adrp	x16, 0x204000
  1f7b84:      	ldr	x17, [x16, #0xf70]
  1f7b88:      	add	x16, x16, #0xf70
  1f7b8c:      	br	x17

00000000001f7b90 <av_channel_layout_copy@plt>:
  1f7b90:      	adrp	x16, 0x204000
  1f7b94:      	ldr	x17, [x16, #0xf78]
  1f7b98:      	add	x16, x16, #0xf78
  1f7b9c:      	br	x17

00000000001f7ba0 <fwrite@plt>:
  1f7ba0:      	adrp	x16, 0x204000
  1f7ba4:      	ldr	x17, [x16, #0xf80]
  1f7ba8:      	add	x16, x16, #0xf80
  1f7bac:      	br	x17

00000000001f7bb0 <_ZN7MMCodec10StreamBase9getFilterEv@plt>:
  1f7bb0:      	adrp	x16, 0x204000
  1f7bb4:      	ldr	x17, [x16, #0xf88]
  1f7bb8:      	add	x16, x16, #0xf88
  1f7bbc:      	br	x17

00000000001f7bc0 <_ZN7MMCodec18MediaHandleContext18processSeekRequestEPl@plt>:
  1f7bc0:      	adrp	x16, 0x204000
  1f7bc4:      	ldr	x17, [x16, #0xf90]
  1f7bc8:      	add	x16, x16, #0xf90
  1f7bcc:      	br	x17

00000000001f7bd0 <_ZN7MMCodec10FrameQueue5flushEv@plt>:
  1f7bd0:      	adrp	x16, 0x204000
  1f7bd4:      	ldr	x17, [x16, #0xf98]
  1f7bd8:      	add	x16, x16, #0xf98
  1f7bdc:      	br	x17

00000000001f7be0 <av_packet_move_ref@plt>:
  1f7be0:      	adrp	x16, 0x204000
  1f7be4:      	ldr	x17, [x16, #0xfa0]
  1f7be8:      	add	x16, x16, #0xfa0
  1f7bec:      	br	x17

00000000001f7bf0 <_ZN7MMCodec18MediaHandleContext12statCallbackEii@plt>:
  1f7bf0:      	adrp	x16, 0x204000
  1f7bf4:      	ldr	x17, [x16, #0xfa8]
  1f7bf8:      	add	x16, x16, #0xfa8
  1f7bfc:      	br	x17

00000000001f7c00 <_ZN7MMCodec11PacketQueue7isFlushEv@plt>:
  1f7c00:      	adrp	x16, 0x204000
  1f7c04:      	ldr	x17, [x16, #0xfb0]
  1f7c08:      	add	x16, x16, #0xfb0
  1f7c0c:      	br	x17

00000000001f7c10 <_ZN7MMCodec11PacketQueue6setEofEb@plt>:
  1f7c10:      	adrp	x16, 0x204000
  1f7c14:      	ldr	x17, [x16, #0xfb8]
  1f7c18:      	add	x16, x16, #0xfb8
  1f7c1c:      	br	x17

00000000001f7c20 <_ZN7MMCodec18MediaHandleContext12addErrorInfoEPKc@plt>:
  1f7c20:      	adrp	x16, 0x204000
  1f7c24:      	ldr	x17, [x16, #0xfc0]
  1f7c28:      	add	x16, x16, #0xfc0
  1f7c2c:      	br	x17

00000000001f7c30 <_ZN7MMCodec18MediaHandleContext8callbackEiidPv@plt>:
  1f7c30:      	adrp	x16, 0x204000
  1f7c34:      	ldr	x17, [x16, #0xfc8]
  1f7c38:      	add	x16, x16, #0xfc8
  1f7c3c:      	br	x17

00000000001f7c40 <_ZN7MMCodec11MediaFilter17filterVideoPacketEP8AVPacketlb@plt>:
  1f7c40:      	adrp	x16, 0x204000
  1f7c44:      	ldr	x17, [x16, #0xfd0]
  1f7c48:      	add	x16, x16, #0xfd0
  1f7c4c:      	br	x17

00000000001f7c50 <_ZNSt6__ndk13mapIllNS_4lessIlEENS_9allocatorINS_4pairIKllEEEEE6insertB8ne180000INS4_IllEEvEENS4_INS_14__map_iteratorINS_15__tree_iteratorINS_12__value_typeIllEEPNS_11__tree_nodeISE_PvEElEEEEbEEOT_@plt>:
  1f7c50:      	adrp	x16, 0x204000
  1f7c54:      	ldr	x17, [x16, #0xfd8]
  1f7c58:      	add	x16, x16, #0xfd8
  1f7c5c:      	br	x17

00000000001f7c60 <_ZN7MMCodec11MediaFilter16filterVideoFrameEP7AVFramelRKNS_11PacketQueue10PacketInfoERb@plt>:
  1f7c60:      	adrp	x16, 0x204000
  1f7c64:      	ldr	x17, [x16, #0xfe0]
  1f7c68:      	add	x16, x16, #0xfe0
  1f7c6c:      	br	x17

00000000001f7c70 <_ZN7MMCodec11MediaFilter16filterAudioFrameEP7AVFramelliRb@plt>:
  1f7c70:      	adrp	x16, 0x204000
  1f7c74:      	ldr	x17, [x16, #0xfe8]
  1f7c78:      	add	x16, x16, #0xfe8
  1f7c7c:      	br	x17

00000000001f7c80 <_ZN7MMCodec11MediaFilter29filterVideoFrameAfterWritableEPNS_12MMCodecFrameERb@plt>:
  1f7c80:      	adrp	x16, 0x204000
  1f7c84:      	ldr	x17, [x16, #0xff0]
  1f7c88:      	add	x16, x16, #0xff0
  1f7c8c:      	br	x17

00000000001f7c90 <_ZN7MMCodec10FrameQueue3putEv@plt>:
  1f7c90:      	adrp	x16, 0x204000
  1f7c94:      	ldr	x17, [x16, #0xff8]
  1f7c98:      	add	x16, x16, #0xff8
  1f7c9c:      	br	x17

00000000001f7ca0 <_ZN7MMCodec18MediaHandleContext12needSeekFileEli@plt>:
  1f7ca0:      	adrp	x16, 0x205000
  1f7ca4:      	ldr	x17, [x16]
  1f7ca8:      	add	x16, x16, #0x0
  1f7cac:      	br	x17

00000000001f7cb0 <_ZN7MMCodec11PacketQueue9nbPacketsEv@plt>:
  1f7cb0:      	adrp	x16, 0x205000
  1f7cb4:      	ldr	x17, [x16, #0x8]
  1f7cb8:      	add	x16, x16, #0x8
  1f7cbc:      	br	x17

00000000001f7cc0 <_ZN7MMCodec10FrameQueue10setEofFlagEb@plt>:
  1f7cc0:      	adrp	x16, 0x205000
  1f7cc4:      	ldr	x17, [x16, #0x10]
  1f7cc8:      	add	x16, x16, #0x10
  1f7ccc:      	br	x17

00000000001f7cd0 <_ZN7MMCodec10StreamBase17getOutVideoFormatEv@plt>:
  1f7cd0:      	adrp	x16, 0x205000
  1f7cd4:      	ldr	x17, [x16, #0x18]
  1f7cd8:      	add	x16, x16, #0x18
  1f7cdc:      	br	x17

00000000001f7ce0 <_ZN7MMCodec10StreamBase20getOutAudioParameterEv@plt>:
  1f7ce0:      	adrp	x16, 0x205000
  1f7ce4:      	ldr	x17, [x16, #0x20]
  1f7ce8:      	add	x16, x16, #0x20
  1f7cec:      	br	x17

00000000001f7cf0 <_ZN7MMCodec10StreamBase4seekElNS_10SeekMode_tE@plt>:
  1f7cf0:      	adrp	x16, 0x205000
  1f7cf4:      	ldr	x17, [x16, #0x28]
  1f7cf8:      	add	x16, x16, #0x28
  1f7cfc:      	br	x17

00000000001f7d00 <_ZN7MMCodec17FFmpegMediaStreamC1EPNS_18MediaHandleContextE@plt>:
  1f7d00:      	adrp	x16, 0x205000
  1f7d04:      	ldr	x17, [x16, #0x30]
  1f7d08:      	add	x16, x16, #0x30
  1f7d0c:      	br	x17

00000000001f7d10 <_ZN7MMCodec18MediaHandleContextC1Ev@plt>:
  1f7d10:      	adrp	x16, 0x205000
  1f7d14:      	ldr	x17, [x16, #0x38]
  1f7d18:      	add	x16, x16, #0x38
  1f7d1c:      	br	x17

00000000001f7d20 <_ZN7MMCodec13InMediaHandleD1Ev@plt>:
  1f7d20:      	adrp	x16, 0x205000
  1f7d24:      	ldr	x17, [x16, #0x40]
  1f7d28:      	add	x16, x16, #0x40
  1f7d2c:      	br	x17

00000000001f7d30 <_ZN7MMCodec13InMediaHandle5_openEPKcPS0_PKhm@plt>:
  1f7d30:      	adrp	x16, 0x205000
  1f7d34:      	ldr	x17, [x16, #0x48]
  1f7d38:      	add	x16, x16, #0x48
  1f7d3c:      	br	x17

00000000001f7d40 <avformat_alloc_context@plt>:
  1f7d40:      	adrp	x16, 0x205000
  1f7d44:      	ldr	x17, [x16, #0x50]
  1f7d48:      	add	x16, x16, #0x50
  1f7d4c:      	br	x17

00000000001f7d50 <av_stristart@plt>:
  1f7d50:      	adrp	x16, 0x205000
  1f7d54:      	ldr	x17, [x16, #0x58]
  1f7d58:      	add	x16, x16, #0x58
  1f7d5c:      	br	x17

00000000001f7d60 <av_dict_get@plt>:
  1f7d60:      	adrp	x16, 0x205000
  1f7d64:      	ldr	x17, [x16, #0x60]
  1f7d68:      	add	x16, x16, #0x60
  1f7d6c:      	br	x17

00000000001f7d70 <avformat_open_input@plt>:
  1f7d70:      	adrp	x16, 0x205000
  1f7d74:      	ldr	x17, [x16, #0x68]
  1f7d78:      	add	x16, x16, #0x68
  1f7d7c:      	br	x17

00000000001f7d80 <avformat_close_input@plt>:
  1f7d80:      	adrp	x16, 0x205000
  1f7d84:      	ldr	x17, [x16, #0x70]
  1f7d88:      	add	x16, x16, #0x70
  1f7d8c:      	br	x17

00000000001f7d90 <av_format_inject_global_side_data@plt>:
  1f7d90:      	adrp	x16, 0x205000
  1f7d94:      	ldr	x17, [x16, #0x78]
  1f7d98:      	add	x16, x16, #0x78
  1f7d9c:      	br	x17

00000000001f7da0 <avformat_find_stream_info@plt>:
  1f7da0:      	adrp	x16, 0x205000
  1f7da4:      	ldr	x17, [x16, #0x80]
  1f7da8:      	add	x16, x16, #0x80
  1f7dac:      	br	x17

00000000001f7db0 <_ZN7MMCodec18MediaHandleContext4openEP15AVFormatContext@plt>:
  1f7db0:      	adrp	x16, 0x205000
  1f7db4:      	ldr	x17, [x16, #0x88]
  1f7db8:      	add	x16, x16, #0x88
  1f7dbc:      	br	x17

00000000001f7dc0 <_ZN7MMCodec8Protocol11URIProtocolD2Ev@plt>:
  1f7dc0:      	adrp	x16, 0x205000
  1f7dc4:      	ldr	x17, [x16, #0x90]
  1f7dc8:      	add	x16, x16, #0x90
  1f7dcc:      	br	x17

00000000001f7dd0 <_ZN7MMCodec18MediaHandleContext15setStatCallbackEPFvPviidS1_ES1_@plt>:
  1f7dd0:      	adrp	x16, 0x205000
  1f7dd4:      	ldr	x17, [x16, #0x98]
  1f7dd8:      	add	x16, x16, #0x98
  1f7ddc:      	br	x17

00000000001f7de0 <_ZN7MMCodec18MediaHandleContextD1Ev@plt>:
  1f7de0:      	adrp	x16, 0x205000
  1f7de4:      	ldr	x17, [x16, #0xa0]
  1f7de8:      	add	x16, x16, #0xa0
  1f7dec:      	br	x17

00000000001f7df0 <_ZN7MMCodec18MediaHandleContext21setSpeedEffectManagerEPNS_18SpeedEffectManagerE@plt>:
  1f7df0:      	adrp	x16, 0x205000
  1f7df4:      	ldr	x17, [x16, #0xa8]
  1f7df8:      	add	x16, x16, #0xa8
  1f7dfc:      	br	x17

00000000001f7e00 <_ZN7MMCodec18MediaHandleContext22setMotionEffectManagerEPNS_19MotionEffectManagerE@plt>:
  1f7e00:      	adrp	x16, 0x205000
  1f7e04:      	ldr	x17, [x16, #0xb0]
  1f7e08:      	add	x16, x16, #0xb0
  1f7e0c:      	br	x17

00000000001f7e10 <_ZN7MMCodec18MediaHandleContext5startEPNS_14AICodecContextE@plt>:
  1f7e10:      	adrp	x16, 0x205000
  1f7e14:      	ldr	x17, [x16, #0xb8]
  1f7e18:      	add	x16, x16, #0xb8
  1f7e1c:      	br	x17

00000000001f7e20 <_ZN7MMCodec18MediaHandleContext16allocPacketQueueEim@plt>:
  1f7e20:      	adrp	x16, 0x205000
  1f7e24:      	ldr	x17, [x16, #0xc0]
  1f7e28:      	add	x16, x16, #0xc0
  1f7e2c:      	br	x17

00000000001f7e30 <_ZN7MMCodec18MediaHandleContext14initEGLContextEv@plt>:
  1f7e30:      	adrp	x16, 0x205000
  1f7e34:      	ldr	x17, [x16, #0xc8]
  1f7e38:      	add	x16, x16, #0xc8
  1f7e3c:      	br	x17

00000000001f7e40 <avformat_seek_file@plt>:
  1f7e40:      	adrp	x16, 0x205000
  1f7e44:      	ldr	x17, [x16, #0xd0]
  1f7e48:      	add	x16, x16, #0xd0
  1f7e4c:      	br	x17

00000000001f7e50 <_ZN7MMCodec18MediaHandleContext9markAbortEv@plt>:
  1f7e50:      	adrp	x16, 0x205000
  1f7e54:      	ldr	x17, [x16, #0xd8]
  1f7e58:      	add	x16, x16, #0xd8
  1f7e5c:      	br	x17

00000000001f7e60 <_ZN7MMCodec18MediaHandleContext15freePacketQueueEi@plt>:
  1f7e60:      	adrp	x16, 0x205000
  1f7e64:      	ldr	x17, [x16, #0xe0]
  1f7e68:      	add	x16, x16, #0xe0
  1f7e6c:      	br	x17

00000000001f7e70 <_ZN7MMCodec18MediaHandleContext17releaseEGLContextEv@plt>:
  1f7e70:      	adrp	x16, 0x205000
  1f7e74:      	ldr	x17, [x16, #0xe8]
  1f7e78:      	add	x16, x16, #0xe8
  1f7e7c:      	br	x17

00000000001f7e80 <_ZN7MMCodec18MediaHandleContext4stopEv@plt>:
  1f7e80:      	adrp	x16, 0x205000
  1f7e84:      	ldr	x17, [x16, #0xf0]
  1f7e88:      	add	x16, x16, #0xf0
  1f7e8c:      	br	x17

00000000001f7e90 <_ZN7MMCodec16getDisplayMatrixEP8AVStreamRi@plt>:
  1f7e90:      	adrp	x16, 0x205000
  1f7e94:      	ldr	x17, [x16, #0xf8]
  1f7e98:      	add	x16, x16, #0xf8
  1f7e9c:      	br	x17

00000000001f7ea0 <av_guess_sample_aspect_ratio@plt>:
  1f7ea0:      	adrp	x16, 0x205000
  1f7ea4:      	ldr	x17, [x16, #0x100]
  1f7ea8:      	add	x16, x16, #0x100
  1f7eac:      	br	x17

00000000001f7eb0 <av_mul_q@plt>:
  1f7eb0:      	adrp	x16, 0x205000
  1f7eb4:      	ldr	x17, [x16, #0x108]
  1f7eb8:      	add	x16, x16, #0x108
  1f7ebc:      	br	x17

00000000001f7ec0 <av_rescale@plt>:
  1f7ec0:      	adrp	x16, 0x205000
  1f7ec4:      	ldr	x17, [x16, #0x110]
  1f7ec8:      	add	x16, x16, #0x110
  1f7ecc:      	br	x17

00000000001f7ed0 <_ZN7MMCodec18MediaHandleContext15markSeekRequestElNS_10SeekMode_tE@plt>:
  1f7ed0:      	adrp	x16, 0x205000
  1f7ed4:      	ldr	x17, [x16, #0x118]
  1f7ed8:      	add	x16, x16, #0x118
  1f7edc:      	br	x17

00000000001f7ee0 <_ZN7MMCodec10StreamBase8syncWaitEli@plt>:
  1f7ee0:      	adrp	x16, 0x205000
  1f7ee4:      	ldr	x17, [x16, #0x120]
  1f7ee8:      	add	x16, x16, #0x120
  1f7eec:      	br	x17

00000000001f7ef0 <_ZN7MMCodec10StreamBase13interruptWaitEv@plt>:
  1f7ef0:      	adrp	x16, 0x205000
  1f7ef4:      	ldr	x17, [x16, #0x128]
  1f7ef8:      	add	x16, x16, #0x128
  1f7efc:      	br	x17

00000000001f7f00 <_ZN7MMCodec18MediaHandleContext11isInSameGOPElli@plt>:
  1f7f00:      	adrp	x16, 0x205000
  1f7f04:      	ldr	x17, [x16, #0x130]
  1f7f08:      	add	x16, x16, #0x130
  1f7f0c:      	br	x17

00000000001f7f10 <_ZN7MMCodec18MediaHandleContext27setEnableDecodeKeyFrameOnlyEb@plt>:
  1f7f10:      	adrp	x16, 0x205000
  1f7f14:      	ldr	x17, [x16, #0x138]
  1f7f18:      	add	x16, x16, #0x138
  1f7f1c:      	br	x17

00000000001f7f20 <_ZNK7MMCodec18MediaHandleContext11getMetadataEv@plt>:
  1f7f20:      	adrp	x16, 0x205000
  1f7f24:      	ldr	x17, [x16, #0x140]
  1f7f28:      	add	x16, x16, #0x140
  1f7f2c:      	br	x17

00000000001f7f30 <avio_context_free@plt>:
  1f7f30:      	adrp	x16, 0x205000
  1f7f34:      	ldr	x17, [x16, #0x148]
  1f7f38:      	add	x16, x16, #0x148
  1f7f3c:      	br	x17

00000000001f7f40 <_ZN7MMCodec8Protocol18AndroidURIProtocolD2Ev@plt>:
  1f7f40:      	adrp	x16, 0x205000
  1f7f44:      	ldr	x17, [x16, #0x150]
  1f7f48:      	add	x16, x16, #0x150
  1f7f4c:      	br	x17

00000000001f7f50 <__read_chk@plt>:
  1f7f50:      	adrp	x16, 0x205000
  1f7f54:      	ldr	x17, [x16, #0x158]
  1f7f58:      	add	x16, x16, #0x158
  1f7f5c:      	br	x17

00000000001f7f60 <write@plt>:
  1f7f60:      	adrp	x16, 0x205000
  1f7f64:      	ldr	x17, [x16, #0x160]
  1f7f68:      	add	x16, x16, #0x160
  1f7f6c:      	br	x17

00000000001f7f70 <lseek@plt>:
  1f7f70:      	adrp	x16, 0x205000
  1f7f74:      	ldr	x17, [x16, #0x168]
  1f7f78:      	add	x16, x16, #0x168
  1f7f7c:      	br	x17

00000000001f7f80 <_ZN7MMCodec18MediaHandleContext17isAnimatedPictureEPKc9AVCodecID@plt>:
  1f7f80:      	adrp	x16, 0x205000
  1f7f84:      	ldr	x17, [x16, #0x170]
  1f7f88:      	add	x16, x16, #0x170
  1f7f8c:      	br	x17

00000000001f7f90 <_ZN7MMCodec18MediaHandleContext15isWebpAnimationEv@plt>:
  1f7f90:      	adrp	x16, 0x205000
  1f7f94:      	ldr	x17, [x16, #0x178]
  1f7f98:      	add	x16, x16, #0x178
  1f7f9c:      	br	x17

00000000001f7fa0 <_ZN7MMCodec13KeyFrameTableD1Ev@plt>:
  1f7fa0:      	adrp	x16, 0x205000
  1f7fa4:      	ldr	x17, [x16, #0x180]
  1f7fa8:      	add	x16, x16, #0x180
  1f7fac:      	br	x17

00000000001f7fb0 <av_packet_free@plt>:
  1f7fb0:      	adrp	x16, 0x205000
  1f7fb4:      	ldr	x17, [x16, #0x188]
  1f7fb8:      	add	x16, x16, #0x188
  1f7fbc:      	br	x17

00000000001f7fc0 <_ZN7MMCodec18MediaHandleContext17loadKeyFrameEntryEv@plt>:
  1f7fc0:      	adrp	x16, 0x205000
  1f7fc4:      	ldr	x17, [x16, #0x190]
  1f7fc8:      	add	x16, x16, #0x190
  1f7fcc:      	br	x17

00000000001f7fd0 <av_find_best_stream@plt>:
  1f7fd0:      	adrp	x16, 0x205000
  1f7fd4:      	ldr	x17, [x16, #0x198]
  1f7fd8:      	add	x16, x16, #0x198
  1f7fdc:      	br	x17

00000000001f7fe0 <avformat_index_get_entries_count@plt>:
  1f7fe0:      	adrp	x16, 0x205000
  1f7fe4:      	ldr	x17, [x16, #0x1a0]
  1f7fe8:      	add	x16, x16, #0x1a0
  1f7fec:      	br	x17

00000000001f7ff0 <avformat_index_get_entry@plt>:
  1f7ff0:      	adrp	x16, 0x205000
  1f7ff4:      	ldr	x17, [x16, #0x1a8]
  1f7ff8:      	add	x16, x16, #0x1a8
  1f7ffc:      	br	x17

00000000001f8000 <_ZN7MMCodec13KeyFrameTableC1Ei@plt>:
  1f8000:      	adrp	x16, 0x205000
  1f8004:      	ldr	x17, [x16, #0x1b0]
  1f8008:      	add	x16, x16, #0x1b0
  1f800c:      	br	x17

00000000001f8010 <_ZN7MMCodec18MediaHandleContext15getRealDurationEi@plt>:
  1f8010:      	adrp	x16, 0x205000
  1f8014:      	ldr	x17, [x16, #0x1b8]
  1f8018:      	add	x16, x16, #0x1b8
  1f801c:      	br	x17

00000000001f8020 <_ZN7MMCodec13KeyFrameTable6insertEllii@plt>:
  1f8020:      	adrp	x16, 0x205000
  1f8024:      	ldr	x17, [x16, #0x1c0]
  1f8028:      	add	x16, x16, #0x1c0
  1f802c:      	br	x17

00000000001f8030 <_ZN7MMCodec13KeyFrameTable12getEntrySizeEv@plt>:
  1f8030:      	adrp	x16, 0x205000
  1f8034:      	ldr	x17, [x16, #0x1c8]
  1f8038:      	add	x16, x16, #0x1c8
  1f803c:      	br	x17

00000000001f8040 <av_packet_alloc@plt>:
  1f8040:      	adrp	x16, 0x205000
  1f8044:      	ldr	x17, [x16, #0x1d0]
  1f8048:      	add	x16, x16, #0x1d0
  1f804c:      	br	x17

00000000001f8050 <av_packet_clone@plt>:
  1f8050:      	adrp	x16, 0x205000
  1f8054:      	ldr	x17, [x16, #0x1d8]
  1f8058:      	add	x16, x16, #0x1d8
  1f805c:      	br	x17

00000000001f8060 <_ZN7MMCodec25MotionEffectFormatContextC1EPNS_18MediaHandleContextE@plt>:
  1f8060:      	adrp	x16, 0x205000
  1f8064:      	ldr	x17, [x16, #0x1e0]
  1f8068:      	add	x16, x16, #0x1e0
  1f806c:      	br	x17

00000000001f8070 <_ZN7MMCodec25MotionEffectFormatContext16setEffectManagerEPNS_19MotionEffectManagerEi@plt>:
  1f8070:      	adrp	x16, 0x205000
  1f8074:      	ldr	x17, [x16, #0x1e8]
  1f8078:      	add	x16, x16, #0x1e8
  1f807c:      	br	x17

00000000001f8080 <_ZN7MMCodec17LoopFormatContextC1EPNS_18MediaHandleContextE@plt>:
  1f8080:      	adrp	x16, 0x205000
  1f8084:      	ldr	x17, [x16, #0x1f0]
  1f8088:      	add	x16, x16, #0x1f0
  1f808c:      	br	x17

00000000001f8090 <_ZN7MMCodec20SectionFormatContextC1EPNS_18MediaHandleContextE@plt>:
  1f8090:      	adrp	x16, 0x205000
  1f8094:      	ldr	x17, [x16, #0x1f8]
  1f8098:      	add	x16, x16, #0x1f8
  1f809c:      	br	x17

00000000001f80a0 <_ZN7MMCodec18MediaHandleContext15findKeyFramePosElli@plt>:
  1f80a0:      	adrp	x16, 0x205000
  1f80a4:      	ldr	x17, [x16, #0x200]
  1f80a8:      	add	x16, x16, #0x200
  1f80ac:      	br	x17

00000000001f80b0 <_ZN7MMCodec13KeyFrameTable12setLeftEntryEl@plt>:
  1f80b0:      	adrp	x16, 0x205000
  1f80b4:      	ldr	x17, [x16, #0x208]
  1f80b8:      	add	x16, x16, #0x208
  1f80bc:      	br	x17

00000000001f80c0 <_ZN7MMCodec13KeyFrameTable9findEntryEl@plt>:
  1f80c0:      	adrp	x16, 0x205000
  1f80c4:      	ldr	x17, [x16, #0x210]
  1f80c8:      	add	x16, x16, #0x210
  1f80cc:      	br	x17

00000000001f80d0 <_ZN7MMCodec13KeyFrameTable10queryEntryElPib@plt>:
  1f80d0:      	adrp	x16, 0x205000
  1f80d4:      	ldr	x17, [x16, #0x218]
  1f80d8:      	add	x16, x16, #0x218
  1f80dc:      	br	x17

00000000001f80e0 <fopen@plt>:
  1f80e0:      	adrp	x16, 0x205000
  1f80e4:      	ldr	x17, [x16, #0x220]
  1f80e8:      	add	x16, x16, #0x220
  1f80ec:      	br	x17

00000000001f80f0 <fread@plt>:
  1f80f0:      	adrp	x16, 0x205000
  1f80f4:      	ldr	x17, [x16, #0x228]
  1f80f8:      	add	x16, x16, #0x228
  1f80fc:      	br	x17

00000000001f8100 <fclose@plt>:
  1f8100:      	adrp	x16, 0x205000
  1f8104:      	ldr	x17, [x16, #0x230]
  1f8108:      	add	x16, x16, #0x230
  1f810c:      	br	x17

00000000001f8110 <_ZN7MMCodec18MediaHandleContext15nextKeyFramePosERi@plt>:
  1f8110:      	adrp	x16, 0x205000
  1f8114:      	ldr	x17, [x16, #0x238]
  1f8118:      	add	x16, x16, #0x238
  1f811c:      	br	x17

00000000001f8120 <_ZN7MMCodec13KeyFrameTable9nextEntryERi@plt>:
  1f8120:      	adrp	x16, 0x205000
  1f8124:      	ldr	x17, [x16, #0x240]
  1f8128:      	add	x16, x16, #0x240
  1f812c:      	br	x17

00000000001f8130 <_ZN7MMCodec18MediaHandleContext17getKeyFrameTablesEi@plt>:
  1f8130:      	adrp	x16, 0x205000
  1f8134:      	ldr	x17, [x16, #0x248]
  1f8138:      	add	x16, x16, #0x248
  1f813c:      	br	x17

00000000001f8140 <_ZN7MMCodec18MediaHandleContext9rewindEOFEi@plt>:
  1f8140:      	adrp	x16, 0x205000
  1f8144:      	ldr	x17, [x16, #0x250]
  1f8148:      	add	x16, x16, #0x250
  1f814c:      	br	x17

00000000001f8150 <_ZN7MMCodec13KeyFrameTable9rewindEOFEv@plt>:
  1f8150:      	adrp	x16, 0x205000
  1f8154:      	ldr	x17, [x16, #0x258]
  1f8158:      	add	x16, x16, #0x258
  1f815c:      	br	x17

00000000001f8160 <_ZN7MMCodec11PacketQueue8tagFlushEv@plt>:
  1f8160:      	adrp	x16, 0x205000
  1f8164:      	ldr	x17, [x16, #0x260]
  1f8168:      	add	x16, x16, #0x260
  1f816c:      	br	x17

00000000001f8170 <_ZN7MMCodec18MediaHandleContext15waitSeekRequestEv@plt>:
  1f8170:      	adrp	x16, 0x205000
  1f8174:      	ldr	x17, [x16, #0x268]
  1f8178:      	add	x16, x16, #0x268
  1f817c:      	br	x17

00000000001f8180 <_ZN7MMCodec11PacketQueue5flushEv@plt>:
  1f8180:      	adrp	x16, 0x205000
  1f8184:      	ldr	x17, [x16, #0x270]
  1f8188:      	add	x16, x16, #0x270
  1f818c:      	br	x17

00000000001f8190 <_ZN7MMCodec11PacketQueue3putEP8AVPacketbbi@plt>:
  1f8190:      	adrp	x16, 0x205000
  1f8194:      	ldr	x17, [x16, #0x278]
  1f8198:      	add	x16, x16, #0x278
  1f819c:      	br	x17

00000000001f81a0 <_ZN7MMCodec11PacketQueueD1Ev@plt>:
  1f81a0:      	adrp	x16, 0x205000
  1f81a4:      	ldr	x17, [x16, #0x280]
  1f81a8:      	add	x16, x16, #0x280
  1f81ac:      	br	x17

00000000001f81b0 <_ZN7MMCodec11PacketQueueC1EPNS_14AICodecContextEm@plt>:
  1f81b0:      	adrp	x16, 0x205000
  1f81b4:      	ldr	x17, [x16, #0x288]
  1f81b8:      	add	x16, x16, #0x288
  1f81bc:      	br	x17

00000000001f81c0 <av_asprintf@plt>:
  1f81c0:      	adrp	x16, 0x205000
  1f81c4:      	ldr	x17, [x16, #0x290]
  1f81c8:      	add	x16, x16, #0x290
  1f81cc:      	br	x17

00000000001f81d0 <_ZN7MMCodec9SWDecoderD1Ev@plt>:
  1f81d0:      	adrp	x16, 0x205000
  1f81d4:      	ldr	x17, [x16, #0x298]
  1f81d8:      	add	x16, x16, #0x298
  1f81dc:      	br	x17

00000000001f81e0 <_ZNKSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_21__tree_const_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_@plt>:
  1f81e0:      	adrp	x16, 0x205000
  1f81e4:      	ldr	x17, [x16, #0x2a0]
  1f81e8:      	add	x16, x16, #0x2a0
  1f81ec:      	br	x17

00000000001f81f0 <avcodec_parameters_to_context@plt>:
  1f81f0:      	adrp	x16, 0x205000
  1f81f4:      	ldr	x17, [x16, #0x2a8]
  1f81f8:      	add	x16, x16, #0x2a8
  1f81fc:      	br	x17

00000000001f8200 <avcodec_find_decoder@plt>:
  1f8200:      	adrp	x16, 0x205000
  1f8204:      	ldr	x17, [x16, #0x2b0]
  1f8208:      	add	x16, x16, #0x2b0
  1f820c:      	br	x17

00000000001f8210 <avcodec_find_decoder_by_name@plt>:
  1f8210:      	adrp	x16, 0x205000
  1f8214:      	ldr	x17, [x16, #0x2b8]
  1f8218:      	add	x16, x16, #0x2b8
  1f821c:      	br	x17

00000000001f8220 <_ZN7MMCodec17filter_codec_optsEP12AVDictionary9AVCodecIDP15AVFormatContextP8AVStreamPK7AVCodec@plt>:
  1f8220:      	adrp	x16, 0x205000
  1f8224:      	ldr	x17, [x16, #0x2c0]
  1f8228:      	add	x16, x16, #0x2c0
  1f822c:      	br	x17

00000000001f8230 <av_dict_set_int@plt>:
  1f8230:      	adrp	x16, 0x205000
  1f8234:      	ldr	x17, [x16, #0x2c8]
  1f8238:      	add	x16, x16, #0x2c8
  1f823c:      	br	x17

00000000001f8240 <avcodec_send_packet@plt>:
  1f8240:      	adrp	x16, 0x205000
  1f8244:      	ldr	x17, [x16, #0x2d0]
  1f8248:      	add	x16, x16, #0x2d0
  1f824c:      	br	x17

00000000001f8250 <avcodec_receive_frame@plt>:
  1f8250:      	adrp	x16, 0x205000
  1f8254:      	ldr	x17, [x16, #0x2d8]
  1f8258:      	add	x16, x16, #0x2d8
  1f825c:      	br	x17

00000000001f8260 <av_hwframe_transfer_data@plt>:
  1f8260:      	adrp	x16, 0x205000
  1f8264:      	ldr	x17, [x16, #0x2e0]
  1f8268:      	add	x16, x16, #0x2e0
  1f826c:      	br	x17

00000000001f8270 <avcodec_flush_buffers@plt>:
  1f8270:      	adrp	x16, 0x205000
  1f8274:      	ldr	x17, [x16, #0x2e8]
  1f8278:      	add	x16, x16, #0x2e8
  1f827c:      	br	x17

00000000001f8280 <_ZN7MMCodec13FormatContextC2EPNS_18MediaHandleContextE@plt>:
  1f8280:      	adrp	x16, 0x205000
  1f8284:      	ldr	x17, [x16, #0x2f0]
  1f8288:      	add	x16, x16, #0x2f0
  1f828c:      	br	x17

00000000001f8290 <_ZN7MMCodec13FormatContextD2Ev@plt>:
  1f8290:      	adrp	x16, 0x205000
  1f8294:      	ldr	x17, [x16, #0x2f8]
  1f8298:      	add	x16, x16, #0x2f8
  1f829c:      	br	x17

00000000001f82a0 <_ZN7MMCodec13FormatContextD1Ev@plt>:
  1f82a0:      	adrp	x16, 0x205000
  1f82a4:      	ldr	x17, [x16, #0x300]
  1f82a8:      	add	x16, x16, #0x300
  1f82ac:      	br	x17

00000000001f82b0 <_ZN7MMCodec13FormatContext10readPacketEP8AVPacketi@plt>:
  1f82b0:      	adrp	x16, 0x205000
  1f82b4:      	ldr	x17, [x16, #0x308]
  1f82b8:      	add	x16, x16, #0x308
  1f82bc:      	br	x17

00000000001f82c0 <_ZN7MMCodec13FormatContext9seekFrameEliPl@plt>:
  1f82c0:      	adrp	x16, 0x205000
  1f82c4:      	ldr	x17, [x16, #0x310]
  1f82c8:      	add	x16, x16, #0x310
  1f82cc:      	br	x17

00000000001f82d0 <_ZN7MMCodec13KeyFrameTable8getEntryEi@plt>:
  1f82d0:      	adrp	x16, 0x205000
  1f82d4:      	ldr	x17, [x16, #0x318]
  1f82d8:      	add	x16, x16, #0x318
  1f82dc:      	br	x17

00000000001f82e0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIllEENS_22__unordered_map_hasherIlS2_NS_4hashIlEENS_8equal_toIlEELb1EEENS_21__unordered_map_equalIlS2_S7_S5_Lb1EEENS_9allocatorIS2_EEE25__emplace_unique_key_argsIlJNS_4pairIllEEEEENSF_INS_15__hash_iteratorIPNS_11__hash_nodeIS2_PvEEEEbEERKT_DpOT0_@plt>:
  1f82e0:      	adrp	x16, 0x205000
  1f82e4:      	ldr	x17, [x16, #0x320]
  1f82e8:      	add	x16, x16, #0x320
  1f82ec:      	br	x17

00000000001f82f0 <_ZN7MMCodec13FormatContext12receiveFrameEPNS_11DecoderBaseEiPNS_12MMCodecFrameE@plt>:
  1f82f0:      	adrp	x16, 0x205000
  1f82f4:      	ldr	x17, [x16, #0x328]
  1f82f8:      	add	x16, x16, #0x328
  1f82fc:      	br	x17

00000000001f8300 <_ZN7MMCodec13FormatContext10flushCodecEPNS_11DecoderBaseE@plt>:
  1f8300:      	adrp	x16, 0x205000
  1f8304:      	ldr	x17, [x16, #0x330]
  1f8308:      	add	x16, x16, #0x330
  1f830c:      	br	x17

00000000001f8310 <_ZN7MMCodec13FormatContext5clearEPNS_11DecoderBaseE@plt>:
  1f8310:      	adrp	x16, 0x205000
  1f8314:      	ldr	x17, [x16, #0x338]
  1f8318:      	add	x16, x16, #0x338
  1f831c:      	br	x17

00000000001f8320 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIllEENS_22__unordered_map_hasherIlS2_NS_4hashIlEENS_8equal_toIlEELb1EEENS_21__unordered_map_equalIlS2_S7_S5_Lb1EEENS_9allocatorIS2_EEE11__do_rehashILb1EEEvm@plt>:
  1f8320:      	adrp	x16, 0x205000
  1f8324:      	ldr	x17, [x16, #0x340]
  1f8328:      	add	x16, x16, #0x340
  1f832c:      	br	x17

00000000001f8330 <_ZN7MMCodec20SectionFormatContextC2EPNS_18MediaHandleContextE@plt>:
  1f8330:      	adrp	x16, 0x205000
  1f8334:      	ldr	x17, [x16, #0x348]
  1f8338:      	add	x16, x16, #0x348
  1f833c:      	br	x17

00000000001f8340 <_ZN7MMCodec20SectionFormatContextD2Ev@plt>:
  1f8340:      	adrp	x16, 0x205000
  1f8344:      	ldr	x17, [x16, #0x350]
  1f8348:      	add	x16, x16, #0x350
  1f834c:      	br	x17

00000000001f8350 <_ZN7MMCodec20SectionFormatContextD1Ev@plt>:
  1f8350:      	adrp	x16, 0x205000
  1f8354:      	ldr	x17, [x16, #0x358]
  1f8358:      	add	x16, x16, #0x358
  1f835c:      	br	x17

00000000001f8360 <_ZN7MMCodec20SectionFormatContext11_readPacketEP8AVPacketi@plt>:
  1f8360:      	adrp	x16, 0x205000
  1f8364:      	ldr	x17, [x16, #0x360]
  1f8368:      	add	x16, x16, #0x360
  1f836c:      	br	x17

00000000001f8370 <_ZN7MMCodec20SectionFormatContext10_seekFrameEliPl@plt>:
  1f8370:      	adrp	x16, 0x205000
  1f8374:      	ldr	x17, [x16, #0x368]
  1f8378:      	add	x16, x16, #0x368
  1f837c:      	br	x17

00000000001f8380 <_ZN7MMCodec20SectionFormatContext13needSeekFrameEli@plt>:
  1f8380:      	adrp	x16, 0x205000
  1f8384:      	ldr	x17, [x16, #0x370]
  1f8388:      	add	x16, x16, #0x370
  1f838c:      	br	x17

00000000001f8390 <_ZN7MMCodec20SectionFormatContext13_receiveFrameEPNS_11DecoderBaseEiPNS_12MMCodecFrameE@plt>:
  1f8390:      	adrp	x16, 0x205000
  1f8394:      	ldr	x17, [x16, #0x378]
  1f8398:      	add	x16, x16, #0x378
  1f839c:      	br	x17

00000000001f83a0 <_ZN7MMCodec17LoopFormatContextD1Ev@plt>:
  1f83a0:      	adrp	x16, 0x205000
  1f83a4:      	ldr	x17, [x16, #0x380]
  1f83a8:      	add	x16, x16, #0x380
  1f83ac:      	br	x17

00000000001f83b0 <_ZN7MMCodec25MotionEffectFormatContextD1Ev@plt>:
  1f83b0:      	adrp	x16, 0x205000
  1f83b4:      	ldr	x17, [x16, #0x388]
  1f83b8:      	add	x16, x16, #0x388
  1f83bc:      	br	x17

00000000001f83c0 <_ZN7MMCodec25MotionEffectFormatContext15_dumpCacheFrameEPNS_12MMCodecFrameEi@plt>:
  1f83c0:      	adrp	x16, 0x205000
  1f83c4:      	ldr	x17, [x16, #0x390]
  1f83c8:      	add	x16, x16, #0x390
  1f83cc:      	br	x17

00000000001f83d0 <_ZN7MMCodec12findFramePtsEPNS_18MediaHandleContextEl@plt>:
  1f83d0:      	adrp	x16, 0x205000
  1f83d4:      	ldr	x17, [x16, #0x398]
  1f83d8:      	add	x16, x16, #0x398
  1f83dc:      	br	x17

00000000001f83e0 <_ZN7MMCodec11MediaFilterD1Ev@plt>:
  1f83e0:      	adrp	x16, 0x205000
  1f83e4:      	ldr	x17, [x16, #0x3a0]
  1f83e8:      	add	x16, x16, #0x3a0
  1f83ec:      	br	x17

00000000001f83f0 <_ZN7MMCodec10FrameQueue8syncWaitEliNSt6__ndk18functionIFbllEEE@plt>:
  1f83f0:      	adrp	x16, 0x205000
  1f83f4:      	ldr	x17, [x16, #0x3a8]
  1f83f8:      	add	x16, x16, #0x3a8
  1f83fc:      	br	x17

00000000001f8400 <_ZN7MMCodec10FrameQueue13interruptWaitEv@plt>:
  1f8400:      	adrp	x16, 0x205000
  1f8404:      	ldr	x17, [x16, #0x3b0]
  1f8408:      	add	x16, x16, #0x3b0
  1f840c:      	br	x17

00000000001f8410 <_ZNSt6__ndk13mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES6_NS_4lessIS6_EENS4_INS_4pairIKS6_S6_EEEEE6insertB8ne180000INS_20__map_const_iteratorINS_21__tree_const_iteratorINS_12__value_typeIS6_S6_EEPNS_11__tree_nodeISI_PvEElEEEEEEvT_SP_@plt>:
  1f8410:      	adrp	x16, 0x205000
  1f8414:      	ldr	x17, [x16, #0x3b8]
  1f8418:      	add	x16, x16, #0x3b8
  1f841c:      	br	x17

00000000001f8420 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEES7_EENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJOS7_EEENSJ_IJEEEEEENS_4pairINS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_@plt>:
  1f8420:      	adrp	x16, 0x205000
  1f8424:      	ldr	x17, [x16, #0x3c0]
  1f8428:      	add	x16, x16, #0x3c0
  1f842c:      	br	x17

00000000001f8430 <gettimeofday@plt>:
  1f8430:      	adrp	x16, 0x205000
  1f8434:      	ldr	x17, [x16, #0x3c8]
  1f8438:      	add	x16, x16, #0x3c8
  1f843c:      	br	x17

00000000001f8440 <_ZNSt6__ndk112__hash_tableIPvNS_4hashIS1_EENS_8equal_toIS1_EENS_9allocatorIS1_EEE4findIS1_EENS_15__hash_iteratorIPNS_11__hash_nodeIS1_S1_EEEERKT_@plt>:
  1f8440:      	adrp	x16, 0x205000
  1f8444:      	ldr	x17, [x16, #0x3d0]
  1f8448:      	add	x16, x16, #0x3d0
  1f844c:      	br	x17

00000000001f8450 <_ZN7MMCodec10FrameQueue4nextEv@plt>:
  1f8450:      	adrp	x16, 0x205000
  1f8454:      	ldr	x17, [x16, #0x3d8]
  1f8458:      	add	x16, x16, #0x3d8
  1f845c:      	br	x17

00000000001f8460 <_ZN7MMCodec10FrameQueue9checkDropEPNS_12MMCodecFrameE@plt>:
  1f8460:      	adrp	x16, 0x205000
  1f8464:      	ldr	x17, [x16, #0x3e0]
  1f8468:      	add	x16, x16, #0x3e0
  1f846c:      	br	x17

00000000001f8470 <_ZN7MMCodec14FrameCachePool5clearEv@plt>:
  1f8470:      	adrp	x16, 0x205000
  1f8474:      	ldr	x17, [x16, #0x3e8]
  1f8478:      	add	x16, x16, #0x3e8
  1f847c:      	br	x17

00000000001f8480 <_ZN7MMCodec14FrameCachePoolD1Ev@plt>:
  1f8480:      	adrp	x16, 0x205000
  1f8484:      	ldr	x17, [x16, #0x3f0]
  1f8488:      	add	x16, x16, #0x3f0
  1f848c:      	br	x17

00000000001f8490 <_ZNSt6__ndk16__treeINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS2_11MMFrameCompENS_9allocatorIS4_EEE25__emplace_unique_key_argsIS4_JRKS4_EEENS_4pairINS_15__tree_iteratorIS4_PNS_11__tree_nodeIS4_PvEElEEbEERKT_DpOT0_@plt>:
  1f8490:      	adrp	x16, 0x205000
  1f8494:      	ldr	x17, [x16, #0x3f8]
  1f8498:      	add	x16, x16, #0x3f8
  1f849c:      	br	x17

00000000001f84a0 <_ZN7MMCodec13FrameHoldPool5clearEv@plt>:
  1f84a0:      	adrp	x16, 0x205000
  1f84a4:      	ldr	x17, [x16, #0x400]
  1f84a8:      	add	x16, x16, #0x400
  1f84ac:      	br	x17

00000000001f84b0 <_ZN7MMCodec13FrameHoldPoolD1Ev@plt>:
  1f84b0:      	adrp	x16, 0x205000
  1f84b4:      	ldr	x17, [x16, #0x408]
  1f84b8:      	add	x16, x16, #0x408
  1f84bc:      	br	x17

00000000001f84c0 <_ZNSt6__ndk112__hash_tableINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorIS4_EEE25__emplace_unique_key_argsIS4_JRKS4_EEENS_4pairINS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEEbEERKT_DpOT0_@plt>:
  1f84c0:      	adrp	x16, 0x205000
  1f84c4:      	ldr	x17, [x16, #0x410]
  1f84c8:      	add	x16, x16, #0x410
  1f84cc:      	br	x17

00000000001f84d0 <_ZNSt6__ndk112__hash_tableINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorIS4_EEE4findIS4_EENS_15__hash_iteratorIPNS_11__hash_nodeIS4_PvEEEERKT_@plt>:
  1f84d0:      	adrp	x16, 0x205000
  1f84d4:      	ldr	x17, [x16, #0x418]
  1f84d8:      	add	x16, x16, #0x418
  1f84dc:      	br	x17

00000000001f84e0 <_ZNSt6__ndk112__hash_tableINS_10shared_ptrIN7MMCodec12MMCodecFrameEEENS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorIS4_EEE11__do_rehashILb1EEEvm@plt>:
  1f84e0:      	adrp	x16, 0x205000
  1f84e4:      	ldr	x17, [x16, #0x420]
  1f84e8:      	add	x16, x16, #0x420
  1f84ec:      	br	x17

00000000001f84f0 <_ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEED2Ev@plt>:
  1f84f0:      	adrp	x16, 0x205000
  1f84f4:      	ldr	x17, [x16, #0x428]
  1f84f8:      	add	x16, x16, #0x428
  1f84fc:      	br	x17

00000000001f8500 <_ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE9force_putERKS2_@plt>:
  1f8500:      	adrp	x16, 0x205000
  1f8504:      	ldr	x17, [x16, #0x430]
  1f8508:      	add	x16, x16, #0x430
  1f850c:      	br	x17

00000000001f8510 <_ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE3putERKS2_@plt>:
  1f8510:      	adrp	x16, 0x205000
  1f8514:      	ldr	x17, [x16, #0x438]
  1f8518:      	add	x16, x16, #0x438
  1f851c:      	br	x17

00000000001f8520 <_ZN7MMCodec11PacketQueue8MMPacketD2Ev@plt>:
  1f8520:      	adrp	x16, 0x205000
  1f8524:      	ldr	x17, [x16, #0x440]
  1f8528:      	add	x16, x16, #0x440
  1f852c:      	br	x17

00000000001f8530 <_ZN7MMCodec11PacketQueue13putNullPacketEi@plt>:
  1f8530:      	adrp	x16, 0x205000
  1f8534:      	ldr	x17, [x16, #0x448]
  1f8538:      	add	x16, x16, #0x448
  1f853c:      	br	x17

00000000001f8540 <_ZN7MMCodec11PacketQueue3getEP8AVPacketbRNS0_10PacketInfoE@plt>:
  1f8540:      	adrp	x16, 0x205000
  1f8544:      	ldr	x17, [x16, #0x450]
  1f8548:      	add	x16, x16, #0x450
  1f854c:      	br	x17

00000000001f8550 <_ZN7MMCodec20BoundedBlockingQueueINS_11PacketQueue8MMPacketEE4takeERS2_i@plt>:
  1f8550:      	adrp	x16, 0x205000
  1f8554:      	ldr	x17, [x16, #0x458]
  1f8558:      	add	x16, x16, #0x458
  1f855c:      	br	x17

00000000001f8560 <mm_free_MMH264ExtraContext@plt>:
  1f8560:      	adrp	x16, 0x205000
  1f8564:      	ldr	x17, [x16, #0x460]
  1f8568:      	add	x16, x16, #0x460
  1f856c:      	br	x17

00000000001f8570 <mm_free_MMH264Context@plt>:
  1f8570:      	adrp	x16, 0x205000
  1f8574:      	ldr	x17, [x16, #0x468]
  1f8578:      	add	x16, x16, #0x468
  1f857c:      	br	x17

00000000001f8580 <_ZN7MMCodec11MediaFilter29filterVideoPacketWithSeekModeEP8AVPacketlb@plt>:
  1f8580:      	adrp	x16, 0x205000
  1f8584:      	ldr	x17, [x16, #0x470]
  1f8588:      	add	x16, x16, #0x470
  1f858c:      	br	x17

00000000001f8590 <_ZN7MMCodec11MediaFilter39filterVideoPacketWithCurrentRequestTimeEP8AVPacketl@plt>:
  1f8590:      	adrp	x16, 0x205000
  1f8594:      	ldr	x17, [x16, #0x478]
  1f8598:      	add	x16, x16, #0x478
  1f859c:      	br	x17

00000000001f85a0 <_ZN7MMCodec11MediaFilter17parseH2645ContextEP8AVPacket@plt>:
  1f85a0:      	adrp	x16, 0x205000
  1f85a4:      	ldr	x17, [x16, #0x480]
  1f85a8:      	add	x16, x16, #0x480
  1f85ac:      	br	x17

00000000001f85b0 <_ZN7MMCodec11MediaFilter22filterVideoWithSpeedUpEP7AVFramelRKNS_11PacketQueue10PacketInfoERb@plt>:
  1f85b0:      	adrp	x16, 0x205000
  1f85b4:      	ldr	x17, [x16, #0x488]
  1f85b8:      	add	x16, x16, #0x488
  1f85bc:      	br	x17

00000000001f85c0 <mm_alloc_MMH264ExtraContext@plt>:
  1f85c0:      	adrp	x16, 0x205000
  1f85c4:      	ldr	x17, [x16, #0x490]
  1f85c8:      	add	x16, x16, #0x490
  1f85cc:      	br	x17

00000000001f85d0 <mm_h264_decode_extradata@plt>:
  1f85d0:      	adrp	x16, 0x205000
  1f85d4:      	ldr	x17, [x16, #0x498]
  1f85d8:      	add	x16, x16, #0x498
  1f85dc:      	br	x17

00000000001f85e0 <mm_alloc_MMH264Context@plt>:
  1f85e0:      	adrp	x16, 0x205000
  1f85e4:      	ldr	x17, [x16, #0x4a0]
  1f85e8:      	add	x16, x16, #0x4a0
  1f85ec:      	br	x17

00000000001f85f0 <mm_decode_nal_units@plt>:
  1f85f0:      	adrp	x16, 0x205000
  1f85f4:      	ldr	x17, [x16, #0x4a8]
  1f85f8:      	add	x16, x16, #0x4a8
  1f85fc:      	br	x17

00000000001f8600 <_ZNSt6__ndk13mapIlPvNS_4lessIlEENS_9allocatorINS_4pairIKlS1_EEEEE6insertB8ne180000INS5_IlP13MMH264ContextEEvEENS5_INS_14__map_iteratorINS_15__tree_iteratorINS_12__value_typeIlS1_EEPNS_11__tree_nodeISH_S1_EElEEEEbEEOT_@plt>:
  1f8600:      	adrp	x16, 0x205000
  1f8604:      	ldr	x17, [x16, #0x4b0]
  1f8608:      	add	x16, x16, #0x4b0
  1f860c:      	br	x17

00000000001f8610 <usleep@plt>:
  1f8610:      	adrp	x16, 0x205000
  1f8614:      	ldr	x17, [x16, #0x4b8]
  1f8618:      	add	x16, x16, #0x4b8
  1f861c:      	br	x17

00000000001f8620 <av_strerror@plt>:
  1f8620:      	adrp	x16, 0x205000
  1f8624:      	ldr	x17, [x16, #0x4c0]
  1f8628:      	add	x16, x16, #0x4c0
  1f862c:      	br	x17

00000000001f8630 <hypot@plt>:
  1f8630:      	adrp	x16, 0x205000
  1f8634:      	ldr	x17, [x16, #0x4c8]
  1f8638:      	add	x16, x16, #0x4c8
  1f863c:      	br	x17

00000000001f8640 <atan2@plt>:
  1f8640:      	adrp	x16, 0x205000
  1f8644:      	ldr	x17, [x16, #0x4d0]
  1f8648:      	add	x16, x16, #0x4d0
  1f864c:      	br	x17

00000000001f8650 <av_stream_get_side_data@plt>:
  1f8650:      	adrp	x16, 0x205000
  1f8654:      	ldr	x17, [x16, #0x4d8]
  1f8658:      	add	x16, x16, #0x4d8
  1f865c:      	br	x17

00000000001f8660 <av_strtod@plt>:
  1f8660:      	adrp	x16, 0x205000
  1f8664:      	ldr	x17, [x16, #0x4e0]
  1f8668:      	add	x16, x16, #0x4e0
  1f866c:      	br	x17

00000000001f8670 <avcodec_get_class@plt>:
  1f8670:      	adrp	x16, 0x205000
  1f8674:      	ldr	x17, [x16, #0x4e8]
  1f8678:      	add	x16, x16, #0x4e8
  1f867c:      	br	x17

00000000001f8680 <strchr@plt>:
  1f8680:      	adrp	x16, 0x205000
  1f8684:      	ldr	x17, [x16, #0x4f0]
  1f8688:      	add	x16, x16, #0x4f0
  1f868c:      	br	x17

00000000001f8690 <avformat_match_stream_specifier@plt>:
  1f8690:      	adrp	x16, 0x205000
  1f8694:      	ldr	x17, [x16, #0x4f8]
  1f8698:      	add	x16, x16, #0x4f8
  1f869c:      	br	x17

00000000001f86a0 <av_opt_find@plt>:
  1f86a0:      	adrp	x16, 0x205000
  1f86a4:      	ldr	x17, [x16, #0x500]
  1f86a8:      	add	x16, x16, #0x500
  1f86ac:      	br	x17

00000000001f86b0 <av_realloc_array@plt>:
  1f86b0:      	adrp	x16, 0x205000
  1f86b4:      	ldr	x17, [x16, #0x508]
  1f86b8:      	add	x16, x16, #0x508
  1f86bc:      	br	x17

00000000001f86c0 <remove@plt>:
  1f86c0:      	adrp	x16, 0x205000
  1f86c4:      	ldr	x17, [x16, #0x510]
  1f86c8:      	add	x16, x16, #0x510
  1f86cc:      	br	x17

00000000001f86d0 <_ZN7MMCodec15VideoFrameUtils15ConvertVideoFmtEPhlS1_iiii@plt>:
  1f86d0:      	adrp	x16, 0x205000
  1f86d4:      	ldr	x17, [x16, #0x518]
  1f86d8:      	add	x16, x16, #0x518
  1f86dc:      	br	x17

00000000001f86e0 <_ZN7MMCodec15VideoFrameUtils7getBuffEm@plt>:
  1f86e0:      	adrp	x16, 0x205000
  1f86e4:      	ldr	x17, [x16, #0x520]
  1f86e8:      	add	x16, x16, #0x520
  1f86ec:      	br	x17

00000000001f86f0 <_ZN7MMCodec14copyAudioArrayE14AVSampleFormatiPPhS1_Rmi@plt>:
  1f86f0:      	adrp	x16, 0x205000
  1f86f4:      	ldr	x17, [x16, #0x528]
  1f86f8:      	add	x16, x16, #0x528
  1f86fc:      	br	x17

00000000001f8700 <_ZN7MMCodec14FFmpegResample7releaseEv@plt>:
  1f8700:      	adrp	x16, 0x205000
  1f8704:      	ldr	x17, [x16, #0x530]
  1f8708:      	add	x16, x16, #0x530
  1f870c:      	br	x17

00000000001f8710 <_ZN7MMCodec14FFmpegResampleD1Ev@plt>:
  1f8710:      	adrp	x16, 0x205000
  1f8714:      	ldr	x17, [x16, #0x538]
  1f8718:      	add	x16, x16, #0x538
  1f871c:      	br	x17

00000000001f8720 <_ZN7MMCodec14FFmpegResample17getNextOutSamplesEii@plt>:
  1f8720:      	adrp	x16, 0x205000
  1f8724:      	ldr	x17, [x16, #0x540]
  1f8728:      	add	x16, x16, #0x540
  1f872c:      	br	x17

00000000001f8730 <_ZN7MMCodec14FFmpegResample8resampleEP7AVFramePPhPii@plt>:
  1f8730:      	adrp	x16, 0x205000
  1f8734:      	ldr	x17, [x16, #0x548]
  1f8738:      	add	x16, x16, #0x548
  1f873c:      	br	x17

00000000001f8740 <_ZN7MMCodec10MTResampleD1Ev@plt>:
  1f8740:      	adrp	x16, 0x205000
  1f8744:      	ldr	x17, [x16, #0x550]
  1f8748:      	add	x16, x16, #0x550
  1f874c:      	br	x17

00000000001f8750 <_ZN7MMCodec10MTResample40getNextOutBufferSizeWithNextInputSamplesEi@plt>:
  1f8750:      	adrp	x16, 0x205000
  1f8754:      	ldr	x17, [x16, #0x558]
  1f8758:      	add	x16, x16, #0x558
  1f875c:      	br	x17

00000000001f8760 <_ZN7MMCodec10MTResample8resampleEPPhiS1_Rmi@plt>:
  1f8760:      	adrp	x16, 0x205000
  1f8764:      	ldr	x17, [x16, #0x560]
  1f8768:      	add	x16, x16, #0x560
  1f876c:      	br	x17

00000000001f8770 <_ZN7MMCodec10MTResample8resampleEPPhiS2_Pii@plt>:
  1f8770:      	adrp	x16, 0x205000
  1f8774:      	ldr	x17, [x16, #0x568]
  1f8778:      	add	x16, x16, #0x568
  1f877c:      	br	x17

00000000001f8780 <_ZN7MMCodec10MTResample7restartEv@plt>:
  1f8780:      	adrp	x16, 0x205000
  1f8784:      	ldr	x17, [x16, #0x570]
  1f8788:      	add	x16, x16, #0x570
  1f878c:      	br	x17

00000000001f8790 <_ZN7MMCodec10ThreadPool9fetchTaskEv@plt>:
  1f8790:      	adrp	x16, 0x205000
  1f8794:      	ldr	x17, [x16, #0x578]
  1f8798:      	add	x16, x16, #0x578
  1f879c:      	br	x17

00000000001f87a0 <_ZNSt6__ndk16thread4joinEv@plt>:
  1f87a0:      	adrp	x16, 0x205000
  1f87a4:      	ldr	x17, [x16, #0x580]
  1f87a8:      	add	x16, x16, #0x580
  1f87ac:      	br	x17

00000000001f87b0 <_ZN7MMCodec11PCMTransferD1Ev@plt>:
  1f87b0:      	adrp	x16, 0x205000
  1f87b4:      	ldr	x17, [x16, #0x588]
  1f87b8:      	add	x16, x16, #0x588
  1f87bc:      	br	x17

00000000001f87c0 <_ZN7MMCodec20getFFmpegAudioFormatENS_19AUDIO_SAMPLE_FORMATE@plt>:
  1f87c0:      	adrp	x16, 0x205000
  1f87c4:      	ldr	x17, [x16, #0x590]
  1f87c8:      	add	x16, x16, #0x590
  1f87cc:      	br	x17

00000000001f87d0 <_ZN7MMCodec11PCMTransfer5writeEPPhii@plt>:
  1f87d0:      	adrp	x16, 0x205000
  1f87d4:      	ldr	x17, [x16, #0x598]
  1f87d8:      	add	x16, x16, #0x598
  1f87dc:      	br	x17

00000000001f87e0 <av_audio_fifo_reset@plt>:
  1f87e0:      	adrp	x16, 0x205000
  1f87e4:      	ldr	x17, [x16, #0x5a0]
  1f87e8:      	add	x16, x16, #0x5a0
  1f87ec:      	br	x17

00000000001f87f0 <_ZNK7MMCodec4Mat411getRotationEPNS_10QuaternionE@plt>:
  1f87f0:      	adrp	x16, 0x205000
  1f87f4:      	ldr	x17, [x16, #0x5a8]
  1f87f8:      	add	x16, x16, #0x5a8
  1f87fc:      	br	x17

00000000001f8800 <_ZN7MMCodec4Vec3C1ERKS0_@plt>:
  1f8800:      	adrp	x16, 0x205000
  1f8804:      	ldr	x17, [x16, #0x5b0]
  1f8808:      	add	x16, x16, #0x5b0
  1f880c:      	br	x17

00000000001f8810 <_ZN7MMCodec4Vec39normalizeEv@plt>:
  1f8810:      	adrp	x16, 0x205000
  1f8814:      	ldr	x17, [x16, #0x5b8]
  1f8818:      	add	x16, x16, #0x5b8
  1f881c:      	br	x17

00000000001f8820 <sincosf@plt>:
  1f8820:      	adrp	x16, 0x205000
  1f8824:      	ldr	x17, [x16, #0x5c0]
  1f8828:      	add	x16, x16, #0x5c0
  1f882c:      	br	x17

00000000001f8830 <_ZN7MMCodec4Vec3D1Ev@plt>:
  1f8830:      	adrp	x16, 0x205000
  1f8834:      	ldr	x17, [x16, #0x5c8]
  1f8838:      	add	x16, x16, #0x5c8
  1f883c:      	br	x17

00000000001f8840 <_ZN7MMCodec10QuaternionC1Effff@plt>:
  1f8840:      	adrp	x16, 0x205000
  1f8844:      	ldr	x17, [x16, #0x5d0]
  1f8848:      	add	x16, x16, #0x5d0
  1f884c:      	br	x17

00000000001f8850 <_ZN7MMCodec10QuaternionD1Ev@plt>:
  1f8850:      	adrp	x16, 0x205000
  1f8854:      	ldr	x17, [x16, #0x5d8]
  1f8858:      	add	x16, x16, #0x5d8
  1f885c:      	br	x17

00000000001f8860 <_ZN7MMCodec10QuaternionC1ERKS0_@plt>:
  1f8860:      	adrp	x16, 0x205000
  1f8864:      	ldr	x17, [x16, #0x5e0]
  1f8868:      	add	x16, x16, #0x5e0
  1f886c:      	br	x17

00000000001f8870 <acosf@plt>:
  1f8870:      	adrp	x16, 0x205000
  1f8874:      	ldr	x17, [x16, #0x5e8]
  1f8878:      	add	x16, x16, #0x5e8
  1f887c:      	br	x17

00000000001f8880 <_ZN7MMCodec10Quaternion5slerpEfffffffffPfS1_S1_S1_@plt>:
  1f8880:      	adrp	x16, 0x205000
  1f8884:      	ldr	x17, [x16, #0x5f0]
  1f8888:      	add	x16, x16, #0x5f0
  1f888c:      	br	x17

00000000001f8890 <sinf@plt>:
  1f8890:      	adrp	x16, 0x205000
  1f8894:      	ldr	x17, [x16, #0x5f8]
  1f8898:      	add	x16, x16, #0x5f8
  1f889c:      	br	x17

00000000001f88a0 <atan2f@plt>:
  1f88a0:      	adrp	x16, 0x205000
  1f88a4:      	ldr	x17, [x16, #0x600]
  1f88a8:      	add	x16, x16, #0x600
  1f88ac:      	br	x17

00000000001f88b0 <_ZN7MMCodec4Vec2C1ERKS0_@plt>:
  1f88b0:      	adrp	x16, 0x205000
  1f88b4:      	ldr	x17, [x16, #0x608]
  1f88b8:      	add	x16, x16, #0x608
  1f88bc:      	br	x17

00000000001f88c0 <_ZN7MMCodec4Vec2D1Ev@plt>:
  1f88c0:      	adrp	x16, 0x205000
  1f88c4:      	ldr	x17, [x16, #0x610]
  1f88c8:      	add	x16, x16, #0x610
  1f88cc:      	br	x17

00000000001f88d0 <_ZN7MMCodec4Vec2C1Eff@plt>:
  1f88d0:      	adrp	x16, 0x205000
  1f88d4:      	ldr	x17, [x16, #0x618]
  1f88d8:      	add	x16, x16, #0x618
  1f88dc:      	br	x17

00000000001f88e0 <_ZN7MMCodec4Vec2C1Ev@plt>:
  1f88e0:      	adrp	x16, 0x205000
  1f88e4:      	ldr	x17, [x16, #0x620]
  1f88e8:      	add	x16, x16, #0x620
  1f88ec:      	br	x17

00000000001f88f0 <_ZN7MMCodec4Vec3C1EPKf@plt>:
  1f88f0:      	adrp	x16, 0x205000
  1f88f4:      	ldr	x17, [x16, #0x628]
  1f88f8:      	add	x16, x16, #0x628
  1f88fc:      	br	x17

00000000001f8900 <_ZN7MMCodec4Vec33dotERKS0_S2_@plt>:
  1f8900:      	adrp	x16, 0x205000
  1f8904:      	ldr	x17, [x16, #0x630]
  1f8908:      	add	x16, x16, #0x630
  1f890c:      	br	x17

00000000001f8910 <_ZN7MMCodec4Vec35crossERKS0_S2_PS0_@plt>:
  1f8910:      	adrp	x16, 0x205000
  1f8914:      	ldr	x17, [x16, #0x638]
  1f8918:      	add	x16, x16, #0x638
  1f891c:      	br	x17

00000000001f8920 <_ZNK7MMCodec4Vec36lengthEv@plt>:
  1f8920:      	adrp	x16, 0x205000
  1f8924:      	ldr	x17, [x16, #0x640]
  1f8928:      	add	x16, x16, #0x640
  1f892c:      	br	x17

00000000001f8930 <_ZNK7MMCodec4Vec313lengthSquaredEv@plt>:
  1f8930:      	adrp	x16, 0x205000
  1f8934:      	ldr	x17, [x16, #0x648]
  1f8938:      	add	x16, x16, #0x648
  1f893c:      	br	x17

00000000001f8940 <_ZN7MMCodec4Vec38subtractERKS0_@plt>:
  1f8940:      	adrp	x16, 0x205000
  1f8944:      	ldr	x17, [x16, #0x650]
  1f8948:      	add	x16, x16, #0x650
  1f894c:      	br	x17

00000000001f8950 <_ZN7MMCodec4Vec38subtractERKS0_S2_PS0_@plt>:
  1f8950:      	adrp	x16, 0x205000
  1f8954:      	ldr	x17, [x16, #0x658]
  1f8958:      	add	x16, x16, #0x658
  1f895c:      	br	x17

00000000001f8960 <_ZN7MMCodec4Vec3C1Efff@plt>:
  1f8960:      	adrp	x16, 0x205000
  1f8964:      	ldr	x17, [x16, #0x660]
  1f8968:      	add	x16, x16, #0x660
  1f896c:      	br	x17

00000000001f8970 <_ZN7MMCodec4Vec3C1Ev@plt>:
  1f8970:      	adrp	x16, 0x205000
  1f8974:      	ldr	x17, [x16, #0x668]
  1f8978:      	add	x16, x16, #0x668
  1f897c:      	br	x17

00000000001f8980 <_ZN7MMCodec4Vec3C1ERKS0_S2_@plt>:
  1f8980:      	adrp	x16, 0x205000
  1f8984:      	ldr	x17, [x16, #0x670]
  1f8988:      	add	x16, x16, #0x670
  1f898c:      	br	x17

00000000001f8990 <_ZN7MMCodec4Vec4C1EPKf@plt>:
  1f8990:      	adrp	x16, 0x205000
  1f8994:      	ldr	x17, [x16, #0x678]
  1f8998:      	add	x16, x16, #0x678
  1f899c:      	br	x17

00000000001f89a0 <_ZN7MMCodec4Vec4C1ERKS0_@plt>:
  1f89a0:      	adrp	x16, 0x205000
  1f89a4:      	ldr	x17, [x16, #0x680]
  1f89a8:      	add	x16, x16, #0x680
  1f89ac:      	br	x17

00000000001f89b0 <_ZN7MMCodec4Vec4C1Effff@plt>:
  1f89b0:      	adrp	x16, 0x205000
  1f89b4:      	ldr	x17, [x16, #0x688]
  1f89b8:      	add	x16, x16, #0x688
  1f89bc:      	br	x17

00000000001f89c0 <_ZN7MMCodec4Mat412createLookAtEfffffffffPS0_@plt>:
  1f89c0:      	adrp	x16, 0x205000
  1f89c4:      	ldr	x17, [x16, #0x690]
  1f89c8:      	add	x16, x16, #0x690
  1f89cc:      	br	x17

00000000001f89d0 <fmodf@plt>:
  1f89d0:      	adrp	x16, 0x205000
  1f89d4:      	ldr	x17, [x16, #0x698]
  1f89d8:      	add	x16, x16, #0x698
  1f89dc:      	br	x17

00000000001f89e0 <tanf@plt>:
  1f89e0:      	adrp	x16, 0x205000
  1f89e4:      	ldr	x17, [x16, #0x6a0]
  1f89e8:      	add	x16, x16, #0x6a0
  1f89ec:      	br	x17

00000000001f89f0 <_ZN7MMCodec4Mat421createBillboardHelperERKNS_4Vec3ES3_S3_PS2_PS0_@plt>:
  1f89f0:      	adrp	x16, 0x205000
  1f89f4:      	ldr	x17, [x16, #0x6a8]
  1f89f8:      	add	x16, x16, #0x6a8
  1f89fc:      	br	x17

00000000001f8a00 <_ZN7MMCodec4Mat4C1Ev@plt>:
  1f8a00:      	adrp	x16, 0x205000
  1f8a04:      	ldr	x17, [x16, #0x6b0]
  1f8a08:      	add	x16, x16, #0x6b0
  1f8a0c:      	br	x17

00000000001f8a10 <_ZN7MMCodec4Mat4D1Ev@plt>:
  1f8a10:      	adrp	x16, 0x205000
  1f8a14:      	ldr	x17, [x16, #0x6b8]
  1f8a18:      	add	x16, x16, #0x6b8
  1f8a1c:      	br	x17

00000000001f8a20 <_ZNK7MMCodec4Mat49decomposeEPNS_4Vec3EPNS_10QuaternionES2_@plt>:
  1f8a20:      	adrp	x16, 0x205000
  1f8a24:      	ldr	x17, [x16, #0x6c0]
  1f8a28:      	add	x16, x16, #0x6c0
  1f8a2c:      	br	x17

00000000001f8a30 <_ZN7MMCodec4Mat4C1ERKS0_@plt>:
  1f8a30:      	adrp	x16, 0x205000
  1f8a34:      	ldr	x17, [x16, #0x6c8]
  1f8a38:      	add	x16, x16, #0x6c8
  1f8a3c:      	br	x17

00000000001f8a40 <_ZN7MMCodec4Mat47inverseEv@plt>:
  1f8a40:      	adrp	x16, 0x205000
  1f8a44:      	ldr	x17, [x16, #0x6d0]
  1f8a48:      	add	x16, x16, #0x6d0
  1f8a4c:      	br	x17

00000000001f8a50 <_ZN7MMCodec8MathUtil14multiplyMatrixEPKfS2_Pf@plt>:
  1f8a50:      	adrp	x16, 0x205000
  1f8a54:      	ldr	x17, [x16, #0x6d8]
  1f8a58:      	add	x16, x16, #0x6d8
  1f8a5c:      	br	x17

00000000001f8a60 <_ZNK7MMCodec4Mat46rotateERKNS_4Vec3EfPS0_@plt>:
  1f8a60:      	adrp	x16, 0x205000
  1f8a64:      	ldr	x17, [x16, #0x6e0]
  1f8a68:      	add	x16, x16, #0x6e0
  1f8a6c:      	br	x17

00000000001f8a70 <_ZN7MMCodec4Mat4C1Effffffffffffffff@plt>:
  1f8a70:      	adrp	x16, 0x205000
  1f8a74:      	ldr	x17, [x16, #0x6e8]
  1f8a78:      	add	x16, x16, #0x6e8
  1f8a7c:      	br	x17

00000000001f8a80 <_ZN7MMCodec8protocol7read_ueEPPhRhRii@plt>:
  1f8a80:      	adrp	x16, 0x205000
  1f8a84:      	ldr	x17, [x16, #0x6f0]
  1f8a88:      	add	x16, x16, #0x6f0
  1f8a8c:      	br	x17

00000000001f8a90 <_ZN7MMCodec8protocol18createParseContextEiPKhi@plt>:
  1f8a90:      	adrp	x16, 0x205000
  1f8a94:      	ldr	x17, [x16, #0x6f8]
  1f8a98:      	add	x16, x16, #0x6f8
  1f8a9c:      	br	x17

00000000001f8aa0 <_ZN7MMCodec8protocol19releaseParseContextEPPv@plt>:
  1f8aa0:      	adrp	x16, 0x205000
  1f8aa4:      	ldr	x17, [x16, #0x700]
  1f8aa8:      	add	x16, x16, #0x700
  1f8aac:      	br	x17

00000000001f8ab0 <_ZN7MMCodec8protocol17isSupportKeyFrameEPviiPKhi@plt>:
  1f8ab0:      	adrp	x16, 0x205000
  1f8ab4:      	ldr	x17, [x16, #0x708]
  1f8ab8:      	add	x16, x16, #0x708
  1f8abc:      	br	x17

00000000001f8ac0 <MM_AV_RB32@plt>:
  1f8ac0:      	adrp	x16, 0x205000
  1f8ac4:      	ldr	x17, [x16, #0x710]
  1f8ac8:      	add	x16, x16, #0x710
  1f8acc:      	br	x17

00000000001f8ad0 <mm_init_get_bits@plt>:
  1f8ad0:      	adrp	x16, 0x205000
  1f8ad4:      	ldr	x17, [x16, #0x718]
  1f8ad8:      	add	x16, x16, #0x718
  1f8adc:      	br	x17

00000000001f8ae0 <mm_get_bits1@plt>:
  1f8ae0:      	adrp	x16, 0x205000
  1f8ae4:      	ldr	x17, [x16, #0x720]
  1f8ae8:      	add	x16, x16, #0x720
  1f8aec:      	br	x17

00000000001f8af0 <mm_get_bits@plt>:
  1f8af0:      	adrp	x16, 0x205000
  1f8af4:      	ldr	x17, [x16, #0x728]
  1f8af8:      	add	x16, x16, #0x728
  1f8afc:      	br	x17

00000000001f8b00 <mm_skip_bits@plt>:
  1f8b00:      	adrp	x16, 0x205000
  1f8b04:      	ldr	x17, [x16, #0x730]
  1f8b08:      	add	x16, x16, #0x730
  1f8b0c:      	br	x17

00000000001f8b10 <mm_show_bits_long@plt>:
  1f8b10:      	adrp	x16, 0x205000
  1f8b14:      	ldr	x17, [x16, #0x738]
  1f8b18:      	add	x16, x16, #0x738
  1f8b1c:      	br	x17

00000000001f8b20 <mm_get_bits_long@plt>:
  1f8b20:      	adrp	x16, 0x205000
  1f8b24:      	ldr	x17, [x16, #0x740]
  1f8b28:      	add	x16, x16, #0x740
  1f8b2c:      	br	x17

00000000001f8b30 <mm_skip_bits_long@plt>:
  1f8b30:      	adrp	x16, 0x205000
  1f8b34:      	ldr	x17, [x16, #0x748]
  1f8b38:      	add	x16, x16, #0x748
  1f8b3c:      	br	x17

00000000001f8b40 <mm_get_ue_golomb_31@plt>:
  1f8b40:      	adrp	x16, 0x205000
  1f8b44:      	ldr	x17, [x16, #0x750]
  1f8b48:      	add	x16, x16, #0x750
  1f8b4c:      	br	x17

00000000001f8b50 <mm_get_ue_golomb@plt>:
  1f8b50:      	adrp	x16, 0x205000
  1f8b54:      	ldr	x17, [x16, #0x758]
  1f8b58:      	add	x16, x16, #0x758
  1f8b5c:      	br	x17

00000000001f8b60 <av_log2@plt>:
  1f8b60:      	adrp	x16, 0x205000
  1f8b64:      	ldr	x17, [x16, #0x760]
  1f8b68:      	add	x16, x16, #0x760
  1f8b6c:      	br	x17

00000000001f8b70 <mm_get_se_golomb_long@plt>:
  1f8b70:      	adrp	x16, 0x205000
  1f8b74:      	ldr	x17, [x16, #0x768]
  1f8b78:      	add	x16, x16, #0x768
  1f8b7c:      	br	x17

00000000001f8b80 <mm_get_bit_length_1@plt>:
  1f8b80:      	adrp	x16, 0x205000
  1f8b84:      	ldr	x17, [x16, #0x770]
  1f8b88:      	add	x16, x16, #0x770
  1f8b8c:      	br	x17

00000000001f8b90 <printf@plt>:
  1f8b90:      	adrp	x16, 0x205000
  1f8b94:      	ldr	x17, [x16, #0x778]
  1f8b98:      	add	x16, x16, #0x778
  1f8b9c:      	br	x17

00000000001f8ba0 <mm_ff_h2645_packet_split@plt>:
  1f8ba0:      	adrp	x16, 0x205000
  1f8ba4:      	ldr	x17, [x16, #0x780]
  1f8ba8:      	add	x16, x16, #0x780
  1f8bac:      	br	x17

00000000001f8bb0 <av_malloc_array@plt>:
  1f8bb0:      	adrp	x16, 0x205000
  1f8bb4:      	ldr	x17, [x16, #0x788]
  1f8bb8:      	add	x16, x16, #0x788
  1f8bbc:      	br	x17

00000000001f8bc0 <_ZN7MMCodec2GL13deleteTextureEj@plt>:
  1f8bc0:      	adrp	x16, 0x205000
  1f8bc4:      	ldr	x17, [x16, #0x790]
  1f8bc8:      	add	x16, x16, #0x790
  1f8bcc:      	br	x17

00000000001f8bd0 <glDeleteFramebuffers@plt>:
  1f8bd0:      	adrp	x16, 0x205000
  1f8bd4:      	ldr	x17, [x16, #0x798]
  1f8bd8:      	add	x16, x16, #0x798
  1f8bdc:      	br	x17

00000000001f8be0 <_ZN7MMCodec19GLFramebufferObject17_resetImageReaderEv@plt>:
  1f8be0:      	adrp	x16, 0x205000
  1f8be4:      	ldr	x17, [x16, #0x7a0]
  1f8be8:      	add	x16, x16, #0x7a0
  1f8bec:      	br	x17

00000000001f8bf0 <_ZN7MMCodec19GLFramebufferObjectD1Ev@plt>:
  1f8bf0:      	adrp	x16, 0x205000
  1f8bf4:      	ldr	x17, [x16, #0x7a8]
  1f8bf8:      	add	x16, x16, #0x7a8
  1f8bfc:      	br	x17

00000000001f8c00 <glGenFramebuffers@plt>:
  1f8c00:      	adrp	x16, 0x205000
  1f8c04:      	ldr	x17, [x16, #0x7b0]
  1f8c08:      	add	x16, x16, #0x7b0
  1f8c0c:      	br	x17

00000000001f8c10 <glFramebufferTexture2D@plt>:
  1f8c10:      	adrp	x16, 0x205000
  1f8c14:      	ldr	x17, [x16, #0x7b8]
  1f8c18:      	add	x16, x16, #0x7b8
  1f8c1c:      	br	x17

00000000001f8c20 <glFramebufferRenderbuffer@plt>:
  1f8c20:      	adrp	x16, 0x205000
  1f8c24:      	ldr	x17, [x16, #0x7c0]
  1f8c28:      	add	x16, x16, #0x7c0
  1f8c2c:      	br	x17

00000000001f8c30 <glClearColor@plt>:
  1f8c30:      	adrp	x16, 0x205000
  1f8c34:      	ldr	x17, [x16, #0x7c8]
  1f8c38:      	add	x16, x16, #0x7c8
  1f8c3c:      	br	x17

00000000001f8c40 <glClear@plt>:
  1f8c40:      	adrp	x16, 0x205000
  1f8c44:      	ldr	x17, [x16, #0x7d0]
  1f8c48:      	add	x16, x16, #0x7d0
  1f8c4c:      	br	x17

00000000001f8c50 <glCheckFramebufferStatus@plt>:
  1f8c50:      	adrp	x16, 0x205000
  1f8c54:      	ldr	x17, [x16, #0x7d8]
  1f8c58:      	add	x16, x16, #0x7d8
  1f8c5c:      	br	x17

00000000001f8c60 <glGenRenderbuffers@plt>:
  1f8c60:      	adrp	x16, 0x205000
  1f8c64:      	ldr	x17, [x16, #0x7e0]
  1f8c68:      	add	x16, x16, #0x7e0
  1f8c6c:      	br	x17

00000000001f8c70 <glBindRenderbuffer@plt>:
  1f8c70:      	adrp	x16, 0x205000
  1f8c74:      	ldr	x17, [x16, #0x7e8]
  1f8c78:      	add	x16, x16, #0x7e8
  1f8c7c:      	br	x17

00000000001f8c80 <glRenderbufferStorage@plt>:
  1f8c80:      	adrp	x16, 0x205000
  1f8c84:      	ldr	x17, [x16, #0x7f0]
  1f8c88:      	add	x16, x16, #0x7f0
  1f8c8c:      	br	x17

00000000001f8c90 <glIsRenderbuffer@plt>:
  1f8c90:      	adrp	x16, 0x205000
  1f8c94:      	ldr	x17, [x16, #0x7f8]
  1f8c98:      	add	x16, x16, #0x7f8
  1f8c9c:      	br	x17

00000000001f8ca0 <glDeleteRenderbuffers@plt>:
  1f8ca0:      	adrp	x16, 0x205000
  1f8ca4:      	ldr	x17, [x16, #0x800]
  1f8ca8:      	add	x16, x16, #0x800
  1f8cac:      	br	x17

00000000001f8cb0 <glReadPixels@plt>:
  1f8cb0:      	adrp	x16, 0x205000
  1f8cb4:      	ldr	x17, [x16, #0x808]
  1f8cb8:      	add	x16, x16, #0x808
  1f8cbc:      	br	x17

00000000001f8cc0 <_ZN7MMCodec19GLFramebufferObject13clearAllLocksEv@plt>:
  1f8cc0:      	adrp	x16, 0x205000
  1f8cc4:      	ldr	x17, [x16, #0x810]
  1f8cc8:      	add	x16, x16, #0x810
  1f8ccc:      	br	x17

00000000001f8cd0 <_ZN7MMCodec19GLFramebufferObject6unlockEv@plt>:
  1f8cd0:      	adrp	x16, 0x205000
  1f8cd4:      	ldr	x17, [x16, #0x818]
  1f8cd8:      	add	x16, x16, #0x818
  1f8cdc:      	br	x17

00000000001f8ce0 <_ZN7MMCodec24GLFramebufferObjectCache30returnFramebufferObjectToCacheEPNS_19GLFramebufferObjectE@plt>:
  1f8ce0:      	adrp	x16, 0x205000
  1f8ce4:      	ldr	x17, [x16, #0x820]
  1f8ce8:      	add	x16, x16, #0x820
  1f8cec:      	br	x17

00000000001f8cf0 <_ZN7MMCodec19GLFramebufferObject4lockEv@plt>:
  1f8cf0:      	adrp	x16, 0x205000
  1f8cf4:      	ldr	x17, [x16, #0x828]
  1f8cf8:      	add	x16, x16, #0x828
  1f8cfc:      	br	x17

00000000001f8d00 <_ZN7MMCodec19GLFramebufferObject18_readPixelWithSizeEiiPhm@plt>:
  1f8d00:      	adrp	x16, 0x205000
  1f8d04:      	ldr	x17, [x16, #0x830]
  1f8d08:      	add	x16, x16, #0x830
  1f8d0c:      	br	x17

00000000001f8d10 <_ZN7MMCodec24GLFramebufferObjectCache29fetchFramebufferObjectForSizeEii@plt>:
  1f8d10:      	adrp	x16, 0x205000
  1f8d14:      	ldr	x17, [x16, #0x838]
  1f8d18:      	add	x16, x16, #0x838
  1f8d1c:      	br	x17

00000000001f8d20 <_ZN7MMCodec24GLFramebufferObjectCache11hashForSizeEii@plt>:
  1f8d20:      	adrp	x16, 0x205000
  1f8d24:      	ldr	x17, [x16, #0x840]
  1f8d28:      	add	x16, x16, #0x840
  1f8d2c:      	br	x17

00000000001f8d30 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE4findIS7_EENS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEERKT_@plt>:
  1f8d30:      	adrp	x16, 0x205000
  1f8d34:      	ldr	x17, [x16, #0x848]
  1f8d38:      	add	x16, x16, #0x848
  1f8d3c:      	br	x17

00000000001f8d40 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPN7MMCodec19GLFramebufferObjectEEENS_19__map_value_compareIS7_SB_NS_4lessIS7_EELb1EEENS5_ISB_EEE4findIS7_EENS_15__tree_iteratorISB_PNS_11__tree_nodeISB_PvEElEERKT_@plt>:
  1f8d40:      	adrp	x16, 0x205000
  1f8d44:      	ldr	x17, [x16, #0x850]
  1f8d48:      	add	x16, x16, #0x850
  1f8d4c:      	br	x17

00000000001f8d50 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_19__map_value_compareIS7_S8_NS_4lessIS7_EELb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JNS_4pairIS7_iEEEEENSG_INS_15__tree_iteratorIS8_PNS_11__tree_nodeIS8_PvEElEEbEERKT_DpOT0_@plt>:
  1f8d50:      	adrp	x16, 0x205000
  1f8d54:      	ldr	x17, [x16, #0x858]
  1f8d58:      	add	x16, x16, #0x858
  1f8d5c:      	br	x17

00000000001f8d60 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPN7MMCodec19GLFramebufferObjectEEENS_19__map_value_compareIS7_SB_NS_4lessIS7_EELb1EEENS5_ISB_EEE25__emplace_unique_key_argsIS7_JNS_4pairIS7_SA_EEEEENSJ_INS_15__tree_iteratorISB_PNS_11__tree_nodeISB_PvEElEEbEERKT_DpOT0_@plt>:
  1f8d60:      	adrp	x16, 0x205000
  1f8d64:      	ldr	x17, [x16, #0x860]
  1f8d68:      	add	x16, x16, #0x860
  1f8d6c:      	br	x17

00000000001f8d70 <_ZN7MMCodec9GLProgram20createWithByteArraysEPKcS2_@plt>:
  1f8d70:      	adrp	x16, 0x205000
  1f8d74:      	ldr	x17, [x16, #0x868]
  1f8d78:      	add	x16, x16, #0x868
  1f8d7c:      	br	x17

00000000001f8d80 <_ZN7MMCodec9GLProgramC1Ev@plt>:
  1f8d80:      	adrp	x16, 0x205000
  1f8d84:      	ldr	x17, [x16, #0x870]
  1f8d88:      	add	x16, x16, #0x870
  1f8d8c:      	br	x17

00000000001f8d90 <_ZN7MMCodec9GLProgram18initWithByteArraysEPKcS2_@plt>:
  1f8d90:      	adrp	x16, 0x205000
  1f8d94:      	ldr	x17, [x16, #0x878]
  1f8d98:      	add	x16, x16, #0x878
  1f8d9c:      	br	x17

00000000001f8da0 <_ZN7MMCodec9GLProgram4linkEv@plt>:
  1f8da0:      	adrp	x16, 0x205000
  1f8da4:      	ldr	x17, [x16, #0x880]
  1f8da8:      	add	x16, x16, #0x880
  1f8dac:      	br	x17

00000000001f8db0 <_ZN7MMCodec9GLProgram13compileShaderEPjjPKc@plt>:
  1f8db0:      	adrp	x16, 0x205000
  1f8db4:      	ldr	x17, [x16, #0x888]
  1f8db8:      	add	x16, x16, #0x888
  1f8dbc:      	br	x17

00000000001f8dc0 <_ZN7MMCodec9GLProgram27bindPredefinedVertexAttribsEv@plt>:
  1f8dc0:      	adrp	x16, 0x205000
  1f8dc4:      	ldr	x17, [x16, #0x890]
  1f8dc8:      	add	x16, x16, #0x890
  1f8dcc:      	br	x17

00000000001f8dd0 <_ZN7MMCodec2GL13deleteProgramEj@plt>:
  1f8dd0:      	adrp	x16, 0x205000
  1f8dd4:      	ldr	x17, [x16, #0x898]
  1f8dd8:      	add	x16, x16, #0x898
  1f8ddc:      	br	x17

00000000001f8de0 <_ZN7MMCodec9GLProgramD1Ev@plt>:
  1f8de0:      	adrp	x16, 0x205000
  1f8de4:      	ldr	x17, [x16, #0x8a0]
  1f8de8:      	add	x16, x16, #0x8a0
  1f8dec:      	br	x17

00000000001f8df0 <glBindAttribLocation@plt>:
  1f8df0:      	adrp	x16, 0x205000
  1f8df4:      	ldr	x17, [x16, #0x8a8]
  1f8df8:      	add	x16, x16, #0x8a8
  1f8dfc:      	br	x17

00000000001f8e00 <_ZN7MMCodec9GLProgram3useEv@plt>:
  1f8e00:      	adrp	x16, 0x205000
  1f8e04:      	ldr	x17, [x16, #0x8b0]
  1f8e08:      	add	x16, x16, #0x8b0
  1f8e0c:      	br	x17

00000000001f8e10 <_ZN7MMCodec2GL10useProgramEj@plt>:
  1f8e10:      	adrp	x16, 0x205000
  1f8e14:      	ldr	x17, [x16, #0x8b8]
  1f8e18:      	add	x16, x16, #0x8b8
  1f8e1c:      	br	x17

00000000001f8e20 <_ZN7MMCodec9GLProgram9getHandleERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
  1f8e20:      	adrp	x16, 0x205000
  1f8e24:      	ldr	x17, [x16, #0x8c0]
  1f8e28:      	add	x16, x16, #0x8c0
  1f8e2c:      	br	x17

00000000001f8e30 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE4findIS7_EENS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEERKT_@plt>:
  1f8e30:      	adrp	x16, 0x205000
  1f8e34:      	ldr	x17, [x16, #0x8c8]
  1f8e38:      	add	x16, x16, #0x8c8
  1f8e3c:      	br	x17

00000000001f8e40 <glGetAttribLocation@plt>:
  1f8e40:      	adrp	x16, 0x205000
  1f8e44:      	ldr	x17, [x16, #0x8d0]
  1f8e48:      	add	x16, x16, #0x8d0
  1f8e4c:      	br	x17

00000000001f8e50 <glGetUniformLocation@plt>:
  1f8e50:      	adrp	x16, 0x205000
  1f8e54:      	ldr	x17, [x16, #0x8d8]
  1f8e58:      	add	x16, x16, #0x8d8
  1f8e5c:      	br	x17

00000000001f8e60 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE25__emplace_unique_key_argsIS7_JNS_4pairIS7_iEEEEENSK_INS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEERKT_DpOT0_@plt>:
  1f8e60:      	adrp	x16, 0x205000
  1f8e64:      	ldr	x17, [x16, #0x8e0]
  1f8e68:      	add	x16, x16, #0x8e0
  1f8e6c:      	br	x17

00000000001f8e70 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEiEENS_22__unordered_map_hasherIS7_S8_NS_4hashIS7_EENS_8equal_toIS7_EELb1EEENS_21__unordered_map_equalIS7_S8_SD_SB_Lb1EEENS5_IS8_EEE11__do_rehashILb1EEEvm@plt>:
  1f8e70:      	adrp	x16, 0x205000
  1f8e74:      	ldr	x17, [x16, #0x8e8]
  1f8e78:      	add	x16, x16, #0x8e8
  1f8e7c:      	br	x17

00000000001f8e80 <_ZN7MMCodec12UniformValueaSERKS0_@plt>:
  1f8e80:      	adrp	x16, 0x205000
  1f8e84:      	ldr	x17, [x16, #0x8f0]
  1f8e88:      	add	x16, x16, #0x8f0
  1f8e8c:      	br	x17

00000000001f8e90 <glDeleteBuffers@plt>:
  1f8e90:      	adrp	x16, 0x205000
  1f8e94:      	ldr	x17, [x16, #0x8f8]
  1f8e98:      	add	x16, x16, #0x8f8
  1f8e9c:      	br	x17

00000000001f8ea0 <_ZN7MMCodec2GL7bindVAOEj@plt>:
  1f8ea0:      	adrp	x16, 0x205000
  1f8ea4:      	ldr	x17, [x16, #0x900]
  1f8ea8:      	add	x16, x16, #0x900
  1f8eac:      	br	x17

00000000001f8eb0 <glBindBuffer@plt>:
  1f8eb0:      	adrp	x16, 0x205000
  1f8eb4:      	ldr	x17, [x16, #0x908]
  1f8eb8:      	add	x16, x16, #0x908
  1f8ebc:      	br	x17

00000000001f8ec0 <_ZN7MMCodec2GL9blendFuncEjjjj@plt>:
  1f8ec0:      	adrp	x16, 0x205000
  1f8ec4:      	ldr	x17, [x16, #0x910]
  1f8ec8:      	add	x16, x16, #0x910
  1f8ecc:      	br	x17

00000000001f8ed0 <glDrawArrays@plt>:
  1f8ed0:      	adrp	x16, 0x205000
  1f8ed4:      	ldr	x17, [x16, #0x918]
  1f8ed8:      	add	x16, x16, #0x918
  1f8edc:      	br	x17

00000000001f8ee0 <glDrawElements@plt>:
  1f8ee0:      	adrp	x16, 0x205000
  1f8ee4:      	ldr	x17, [x16, #0x920]
  1f8ee8:      	add	x16, x16, #0x920
  1f8eec:      	br	x17

00000000001f8ef0 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN7MMCodec12UniformValueEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE25__emplace_unique_key_argsIS7_JRKNS_21piecewise_construct_tENS_5tupleIJRKS7_EEENSL_IJEEEEEENS_4pairINS_15__tree_iteratorISA_PNS_11__tree_nodeISA_PvEElEEbEERKT_DpOT0_@plt>:
  1f8ef0:      	adrp	x16, 0x205000
  1f8ef4:      	ldr	x17, [x16, #0x928]
  1f8ef8:      	add	x16, x16, #0x928
  1f8efc:      	br	x17

00000000001f8f00 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN7MMCodec12UniformValueEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE4findIS7_EENS_15__tree_iteratorISA_PNS_11__tree_nodeISA_PvEElEERKT_@plt>:
  1f8f00:      	adrp	x16, 0x205000
  1f8f04:      	ldr	x17, [x16, #0x930]
  1f8f08:      	add	x16, x16, #0x930
  1f8f0c:      	br	x17

00000000001f8f10 <_ZN7MMCodec12UniformValueC1ERKS0_@plt>:
  1f8f10:      	adrp	x16, 0x205000
  1f8f14:      	ldr	x17, [x16, #0x938]
  1f8f18:      	add	x16, x16, #0x938
  1f8f1c:      	br	x17

00000000001f8f20 <_ZN7MMCodec12UniformValueC1Ev@plt>:
  1f8f20:      	adrp	x16, 0x205000
  1f8f24:      	ldr	x17, [x16, #0x940]
  1f8f28:      	add	x16, x16, #0x940
  1f8f2c:      	br	x17

00000000001f8f30 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN7MMCodec12UniformValueEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE14__assign_multiINS_21__tree_const_iteratorISA_PNS_11__tree_nodeISA_PvEElEEEEvT_SO_@plt>:
  1f8f30:      	adrp	x16, 0x205000
  1f8f34:      	ldr	x17, [x16, #0x948]
  1f8f38:      	add	x16, x16, #0x948
  1f8f3c:      	br	x17

00000000001f8f40 <glGenBuffers@plt>:
  1f8f40:      	adrp	x16, 0x205000
  1f8f44:      	ldr	x17, [x16, #0x950]
  1f8f48:      	add	x16, x16, #0x950
  1f8f4c:      	br	x17

00000000001f8f50 <glBufferData@plt>:
  1f8f50:      	adrp	x16, 0x205000
  1f8f54:      	ldr	x17, [x16, #0x958]
  1f8f58:      	add	x16, x16, #0x958
  1f8f5c:      	br	x17

00000000001f8f60 <glEnableVertexAttribArray@plt>:
  1f8f60:      	adrp	x16, 0x205000
  1f8f64:      	ldr	x17, [x16, #0x960]
  1f8f68:      	add	x16, x16, #0x960
  1f8f6c:      	br	x17

00000000001f8f70 <glVertexAttribPointer@plt>:
  1f8f70:      	adrp	x16, 0x205000
  1f8f74:      	ldr	x17, [x16, #0x968]
  1f8f78:      	add	x16, x16, #0x968
  1f8f7c:      	br	x17

00000000001f8f80 <glDisableVertexAttribArray@plt>:
  1f8f80:      	adrp	x16, 0x205000
  1f8f84:      	ldr	x17, [x16, #0x970]
  1f8f88:      	add	x16, x16, #0x970
  1f8f8c:      	br	x17

00000000001f8f90 <glUniform1f@plt>:
  1f8f90:      	adrp	x16, 0x205000
  1f8f94:      	ldr	x17, [x16, #0x978]
  1f8f98:      	add	x16, x16, #0x978
  1f8f9c:      	br	x17

00000000001f8fa0 <glUniform1i@plt>:
  1f8fa0:      	adrp	x16, 0x205000
  1f8fa4:      	ldr	x17, [x16, #0x980]
  1f8fa8:      	add	x16, x16, #0x980
  1f8fac:      	br	x17

00000000001f8fb0 <_ZN7MMCodec2GL14bindTexture2DNEjj@plt>:
  1f8fb0:      	adrp	x16, 0x205000
  1f8fb4:      	ldr	x17, [x16, #0x988]
  1f8fb8:      	add	x16, x16, #0x988
  1f8fbc:      	br	x17

00000000001f8fc0 <glUniform4fv@plt>:
  1f8fc0:      	adrp	x16, 0x205000
  1f8fc4:      	ldr	x17, [x16, #0x990]
  1f8fc8:      	add	x16, x16, #0x990
  1f8fcc:      	br	x17

00000000001f8fd0 <glUniformMatrix3fv@plt>:
  1f8fd0:      	adrp	x16, 0x205000
  1f8fd4:      	ldr	x17, [x16, #0x998]
  1f8fd8:      	add	x16, x16, #0x998
  1f8fdc:      	br	x17

00000000001f8fe0 <glUniform2fv@plt>:
  1f8fe0:      	adrp	x16, 0x205000
  1f8fe4:      	ldr	x17, [x16, #0x9a0]
  1f8fe8:      	add	x16, x16, #0x9a0
  1f8fec:      	br	x17

00000000001f8ff0 <glUniform3i@plt>:
  1f8ff0:      	adrp	x16, 0x205000
  1f8ff4:      	ldr	x17, [x16, #0x9a8]
  1f8ff8:      	add	x16, x16, #0x9a8
  1f8ffc:      	br	x17

00000000001f9000 <glUniform4i@plt>:
  1f9000:      	adrp	x16, 0x205000
  1f9004:      	ldr	x17, [x16, #0x9b0]
  1f9008:      	add	x16, x16, #0x9b0
  1f900c:      	br	x17

00000000001f9010 <glUniform4f@plt>:
  1f9010:      	adrp	x16, 0x205000
  1f9014:      	ldr	x17, [x16, #0x9b8]
  1f9018:      	add	x16, x16, #0x9b8
  1f901c:      	br	x17

00000000001f9020 <glUniform2i@plt>:
  1f9020:      	adrp	x16, 0x205000
  1f9024:      	ldr	x17, [x16, #0x9c0]
  1f9028:      	add	x16, x16, #0x9c0
  1f902c:      	br	x17

00000000001f9030 <_ZN7MMCodec2GL20bindTextureExternalNEjjj@plt>:
  1f9030:      	adrp	x16, 0x205000
  1f9034:      	ldr	x17, [x16, #0x9c8]
  1f9038:      	add	x16, x16, #0x9c8
  1f903c:      	br	x17

00000000001f9040 <glUniform2f@plt>:
  1f9040:      	adrp	x16, 0x205000
  1f9044:      	ldr	x17, [x16, #0x9d0]
  1f9048:      	add	x16, x16, #0x9d0
  1f904c:      	br	x17

00000000001f9050 <glUniformMatrix4fv@plt>:
  1f9050:      	adrp	x16, 0x205000
  1f9054:      	ldr	x17, [x16, #0x9d8]
  1f9058:      	add	x16, x16, #0x9d8
  1f905c:      	br	x17

00000000001f9060 <glUniform3f@plt>:
  1f9060:      	adrp	x16, 0x205000
  1f9064:      	ldr	x17, [x16, #0x9e0]
  1f9068:      	add	x16, x16, #0x9e0
  1f906c:      	br	x17

00000000001f9070 <glUniform3fv@plt>:
  1f9070:      	adrp	x16, 0x205000
  1f9074:      	ldr	x17, [x16, #0x9e8]
  1f9078:      	add	x16, x16, #0x9e8
  1f907c:      	br	x17

00000000001f9080 <glUniform1fv@plt>:
  1f9080:      	adrp	x16, 0x205000
  1f9084:      	ldr	x17, [x16, #0x9f0]
  1f9088:      	add	x16, x16, #0x9f0
  1f908c:      	br	x17

00000000001f9090 <_ZNSt6__ndk16__treeINS_12__value_typeINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEN7MMCodec12UniformValueEEENS_19__map_value_compareIS7_SA_NS_4lessIS7_EELb1EEENS5_ISA_EEE15__emplace_multiIJRKNS_4pairIKS7_S9_EEEEENS_15__tree_iteratorISA_PNS_11__tree_nodeISA_PvEElEEDpOT_@plt>:
  1f9090:      	adrp	x16, 0x205000
  1f9094:      	ldr	x17, [x16, #0x9f8]
  1f9098:      	add	x16, x16, #0x9f8
  1f909c:      	br	x17

00000000001f90a0 <glUseProgram@plt>:
  1f90a0:      	adrp	x16, 0x205000
  1f90a4:      	ldr	x17, [x16, #0xa00]
  1f90a8:      	add	x16, x16, #0xa00
  1f90ac:      	br	x17

00000000001f90b0 <glDisable@plt>:
  1f90b0:      	adrp	x16, 0x205000
  1f90b4:      	ldr	x17, [x16, #0xa08]
  1f90b8:      	add	x16, x16, #0xa08
  1f90bc:      	br	x17

00000000001f90c0 <glEnable@plt>:
  1f90c0:      	adrp	x16, 0x205000
  1f90c4:      	ldr	x17, [x16, #0xa10]
  1f90c8:      	add	x16, x16, #0xa10
  1f90cc:      	br	x17

00000000001f90d0 <glBlendFunc@plt>:
  1f90d0:      	adrp	x16, 0x205000
  1f90d4:      	ldr	x17, [x16, #0xa18]
  1f90d8:      	add	x16, x16, #0xa18
  1f90dc:      	br	x17

00000000001f90e0 <glBlendFuncSeparate@plt>:
  1f90e0:      	adrp	x16, 0x205000
  1f90e4:      	ldr	x17, [x16, #0xa20]
  1f90e8:      	add	x16, x16, #0xa20
  1f90ec:      	br	x17

00000000001f90f0 <glActiveTexture@plt>:
  1f90f0:      	adrp	x16, 0x205000
  1f90f4:      	ldr	x17, [x16, #0xa28]
  1f90f8:      	add	x16, x16, #0xa28
  1f90fc:      	br	x17

00000000001f9100 <_ZN7MMCodec2GL13activeTextureEj@plt>:
  1f9100:      	adrp	x16, 0x205000
  1f9104:      	ldr	x17, [x16, #0xa30]
  1f9108:      	add	x16, x16, #0xa30
  1f910c:      	br	x17

00000000001f9110 <glBindVertexArrayOES@plt>:
  1f9110:      	adrp	x16, 0x205000
  1f9114:      	ldr	x17, [x16, #0xa38]
  1f9118:      	add	x16, x16, #0xa38
  1f911c:      	br	x17

00000000001f9120 <_ZNSt6__ndk13mapIN7MMCodec9Texture2D11PixelFormatEKNS2_15PixelFormatInfoENS_4lessIS3_EENS_9allocatorINS_4pairIKS3_S5_EEEEEC2B8ne180000IPKSB_EET_SH_RKS7_@plt>:
  1f9120:      	adrp	x16, 0x205000
  1f9124:      	ldr	x17, [x16, #0xa40]
  1f9128:      	add	x16, x16, #0xa40
  1f912c:      	br	x17

00000000001f9130 <_ZNSt6__ndk16__treeINS_12__value_typeIN7MMCodec9Texture2D11PixelFormatEKNS3_15PixelFormatInfoEEENS_19__map_value_compareIS4_S7_NS_4lessIS4_EELb1EEENS_9allocatorIS7_EEE12__find_equalIS4_EERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS7_PNS_11__tree_nodeIS7_SH_EElEERPNS_15__tree_end_nodeISJ_EESK_RKT_@plt>:
  1f9130:      	adrp	x16, 0x205000
  1f9134:      	ldr	x17, [x16, #0xa48]
  1f9138:      	add	x16, x16, #0xa48
  1f913c:      	br	x17

00000000001f9140 <_ZN7MMCodec9Texture2DC1Ev@plt>:
  1f9140:      	adrp	x16, 0x205000
  1f9144:      	ldr	x17, [x16, #0xa50]
  1f9148:      	add	x16, x16, #0xa50
  1f914c:      	br	x17

00000000001f9150 <_ZN7MMCodec9Texture2DD1Ev@plt>:
  1f9150:      	adrp	x16, 0x205000
  1f9154:      	ldr	x17, [x16, #0xa58]
  1f9158:      	add	x16, x16, #0xa58
  1f915c:      	br	x17

00000000001f9160 <glTexSubImage2D@plt>:
  1f9160:      	adrp	x16, 0x205000
  1f9164:      	ldr	x17, [x16, #0xa60]
  1f9168:      	add	x16, x16, #0xa60
  1f916c:      	br	x17

00000000001f9170 <glGetError@plt>:
  1f9170:      	adrp	x16, 0x205000
  1f9174:      	ldr	x17, [x16, #0xa68]
  1f9178:      	add	x16, x16, #0xa68
  1f917c:      	br	x17

00000000001f9180 <glPixelStorei@plt>:
  1f9180:      	adrp	x16, 0x205000
  1f9184:      	ldr	x17, [x16, #0xa70]
  1f9188:      	add	x16, x16, #0xa70
  1f918c:      	br	x17

00000000001f9190 <_ZN7MMCodec9Texture2D16setTexParametersERKNS0_10_TexParamsE@plt>:
  1f9190:      	adrp	x16, 0x205000
  1f9194:      	ldr	x17, [x16, #0xa78]
  1f9198:      	add	x16, x16, #0xa78
  1f919c:      	br	x17

00000000001f91a0 <_ZNK7MMCodec10ColorSpace10ColorSpace8toLinearERKNS0_7details5TVec3IfEE@plt>:
  1f91a0:      	adrp	x16, 0x205000
  1f91a4:      	ldr	x17, [x16, #0xa80]
  1f91a8:      	add	x16, x16, #0xa80
  1f91ac:      	br	x17

00000000001f91b0 <powf@plt>:
  1f91b0:      	adrp	x16, 0x205000
  1f91b4:      	ldr	x17, [x16, #0xa88]
  1f91b8:      	add	x16, x16, #0xa88
  1f91bc:      	br	x17

00000000001f91c0 <log10f@plt>:
  1f91c0:      	adrp	x16, 0x205000
  1f91c4:      	ldr	x17, [x16, #0xa90]
  1f91c8:      	add	x16, x16, #0xa90
  1f91cc:      	br	x17

00000000001f91d0 <_ZN7MMCodec10ColorSpace19ColorSpaceConnectorC1ERKNS0_10ColorSpaceES4_@plt>:
  1f91d0:      	adrp	x16, 0x205000
  1f91d4:      	ldr	x17, [x16, #0xa98]
  1f91d8:      	add	x16, x16, #0xa98
  1f91dc:      	br	x17

00000000001f91e0 <_ZNK7MMCodec10ColorSpace19ColorSpaceConnector9transformERKNS0_7details5TVec3IfEE@plt>:
  1f91e0:      	adrp	x16, 0x205000
  1f91e4:      	ldr	x17, [x16, #0xaa0]
  1f91e8:      	add	x16, x16, #0xaa0
  1f91ec:      	br	x17

00000000001f91f0 <_ZN7MMCodec10ColorSpace19ColorSpaceConnectorD2Ev@plt>:
  1f91f0:      	adrp	x16, 0x205000
  1f91f4:      	ldr	x17, [x16, #0xaa8]
  1f91f8:      	add	x16, x16, #0xaa8
  1f91fc:      	br	x17

00000000001f9200 <_ZN7MMCodec10ColorSpace10ColorSpace7makeRGBERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS0_7details6TMat33IfEENS1_18TransferParametersENS2_8functionIFffEEE@plt>:
  1f9200:      	adrp	x16, 0x205000
  1f9204:      	ldr	x17, [x16, #0xab0]
  1f9208:      	add	x16, x16, #0xab0
  1f920c:      	br	x17

00000000001f9210 <_ZN7MMCodec10ColorSpace10ColorSpaceC2ERKS1_@plt>:
  1f9210:      	adrp	x16, 0x205000
  1f9214:      	ldr	x17, [x16, #0xab8]
  1f9218:      	add	x16, x16, #0xab8
  1f921c:      	br	x17

00000000001f9220 <_ZN7MMCodec10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS0_7details6TMat33IfEENS1_18TransferParametersENS0_14ColorSpaceTypeENS2_8functionIFffEEE@plt>:
  1f9220:      	adrp	x16, 0x205000
  1f9224:      	ldr	x17, [x16, #0xac0]
  1f9228:      	add	x16, x16, #0xac0
  1f922c:      	br	x17

00000000001f9230 <_ZN7MMCodec10ColorSpace11skcms_ParseEPKvmPNS0_16skcms_ICCProfileE@plt>:
  1f9230:      	adrp	x16, 0x205000
  1f9234:      	ldr	x17, [x16, #0xac8]
  1f9238:      	add	x16, x16, #0xac8
  1f923c:      	br	x17

00000000001f9240 <_ZN7MMCodec10ColorSpace18skcms_sRGB_profileEv@plt>:
  1f9240:      	adrp	x16, 0x205000
  1f9244:      	ldr	x17, [x16, #0xad0]
  1f9248:      	add	x16, x16, #0xad0
  1f924c:      	br	x17

00000000001f9250 <_ZN7MMCodec10ColorSpace32skcms_ApproximatelyEqualProfilesEPKNS0_16skcms_ICCProfileES3_@plt>:
  1f9250:      	adrp	x16, 0x205000
  1f9254:      	ldr	x17, [x16, #0xad8]
  1f9258:      	add	x16, x16, #0xad8
  1f925c:      	br	x17

00000000001f9260 <_ZN7MMCodec10ColorSpace22skcms_Matrix3x3_invertEPKNS0_15skcms_Matrix3x3EPS1_@plt>:
  1f9260:      	adrp	x16, 0x205000
  1f9264:      	ldr	x17, [x16, #0xae0]
  1f9268:      	add	x16, x16, #0xae0
  1f926c:      	br	x17

00000000001f9270 <_ZN7MMCodec10ColorSpace35skcms_sRGB_Inverse_TransferFunctionEv@plt>:
  1f9270:      	adrp	x16, 0x205000
  1f9274:      	ldr	x17, [x16, #0xae8]
  1f9278:      	add	x16, x16, #0xae8
  1f927c:      	br	x17

00000000001f9280 <_ZN7MMCodec10ColorSpace32skcms_TRCs_AreApproximateInverseEPKNS0_16skcms_ICCProfileEPKNS0_22skcms_TransferFunctionE@plt>:
  1f9280:      	adrp	x16, 0x205000
  1f9284:      	ldr	x17, [x16, #0xaf0]
  1f9288:      	add	x16, x16, #0xaf0
  1f928c:      	br	x17

00000000001f9290 <_ZN7MMCodec10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_NS1_18TransferParametersENS0_14ColorSpaceTypeENS2_8functionIFffEEE@plt>:
  1f9290:      	adrp	x16, 0x205000
  1f9294:      	ldr	x17, [x16, #0xaf8]
  1f9298:      	add	x16, x16, #0xaf8
  1f929c:      	br	x17

00000000001f92a0 <_ZN7MMCodec10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_NS2_8functionIFffEEESM_NS0_14ColorSpaceTypeESM_@plt>:
  1f92a0:      	adrp	x16, 0x205000
  1f92a4:      	ldr	x17, [x16, #0xb00]
  1f92a8:      	add	x16, x16, #0xb00
  1f92ac:      	br	x17

00000000001f92b0 <_ZN7MMCodec10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_fNS0_14ColorSpaceTypeENS2_8functionIFffEEE@plt>:
  1f92b0:      	adrp	x16, 0x205000
  1f92b4:      	ldr	x17, [x16, #0xb08]
  1f92b8:      	add	x16, x16, #0xb08
  1f92bc:      	br	x17

00000000001f92c0 <_ZN7MMCodec10ColorSpace10ColorSpaceC1ERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEERKNS2_5arrayINS0_7details5TVec2IfEELm3EEERKSE_NS2_8functionIFffEEENSK_IFfffffEEEbNS0_14ColorSpaceTypeESM_@plt>:
  1f92c0:      	adrp	x16, 0x205000
  1f92c4:      	ldr	x17, [x16, #0xb10]
  1f92c8:      	add	x16, x16, #0xb10
  1f92cc:      	br	x17

00000000001f92d0 <_ZN7MMCodec10ColorSpace5powf_Eff@plt>:
  1f92d0:      	adrp	x16, 0x205000
  1f92d4:      	ldr	x17, [x16, #0xb18]
  1f92d8:      	add	x16, x16, #0xb18
  1f92dc:      	br	x17

00000000001f92e0 <_ZN7MMCodec10ColorSpace27skcms_TransferFunction_evalEPKNS0_22skcms_TransferFunctionEf@plt>:
  1f92e0:      	adrp	x16, 0x205000
  1f92e4:      	ldr	x17, [x16, #0xb20]
  1f92e8:      	add	x16, x16, #0xb20
  1f92ec:      	br	x17

00000000001f92f0 <_ZN7MMCodec10ColorSpace23skcms_MaxRoundtripErrorEPKNS0_11skcms_CurveEPKNS0_22skcms_TransferFunctionE@plt>:
  1f92f0:      	adrp	x16, 0x205000
  1f92f4:      	ldr	x17, [x16, #0xb28]
  1f92f8:      	add	x16, x16, #0xb28
  1f92fc:      	br	x17

00000000001f9300 <_ZN7MMCodec10ColorSpace23skcms_GetTagBySignatureEPKNS0_16skcms_ICCProfileEjPNS0_12skcms_ICCTagE@plt>:
  1f9300:      	adrp	x16, 0x205000
  1f9304:      	ldr	x17, [x16, #0xb30]
  1f9308:      	add	x16, x16, #0xb30
  1f930c:      	br	x17

00000000001f9310 <_ZN7MMCodec10ColorSpace26skcms_TransformWithPaletteEPKvNS0_17skcms_PixelFormatENS0_17skcms_AlphaFormatEPKNS0_16skcms_ICCProfileEPvS3_S4_S7_mS2_@plt>:
  1f9310:      	adrp	x16, 0x205000
  1f9314:      	ldr	x17, [x16, #0xb38]
  1f9318:      	add	x16, x16, #0xb38
  1f931c:      	br	x17

00000000001f9320 <_ZN7MMCodec10ColorSpace19skcms_AdaptToXYZD50EffPNS0_15skcms_Matrix3x3E@plt>:
  1f9320:      	adrp	x16, 0x205000
  1f9324:      	ldr	x17, [x16, #0xb40]
  1f9328:      	add	x16, x16, #0xb40
  1f932c:      	br	x17

00000000001f9330 <_ZN7MMCodec10ColorSpace22skcms_Matrix3x3_concatEPKNS0_15skcms_Matrix3x3ES3_@plt>:
  1f9330:      	adrp	x16, 0x205000
  1f9334:      	ldr	x17, [x16, #0xb48]
  1f9338:      	add	x16, x16, #0xb48
  1f933c:      	br	x17

00000000001f9340 <_ZN7MMCodec10ColorSpace29skcms_TransferFunction_invertEPKNS0_22skcms_TransferFunctionEPS1_@plt>:
  1f9340:      	adrp	x16, 0x205000
  1f9344:      	ldr	x17, [x16, #0xb50]
  1f9348:      	add	x16, x16, #0xb50
  1f934c:      	br	x17

00000000001f9350 <_ZN7MMCodec10ColorSpace22skcms_ApproximateCurveEPKNS0_11skcms_CurveEPNS0_22skcms_TransferFunctionEPf@plt>:
  1f9350:      	adrp	x16, 0x205000
  1f9354:      	ldr	x17, [x16, #0xb58]
  1f9358:      	add	x16, x16, #0xb58
  1f935c:      	br	x17

00000000001f9360 <__memcpy_chk@plt>:
  1f9360:      	adrp	x16, 0x205000
  1f9364:      	ldr	x17, [x16, #0xb60]
  1f9368:      	add	x16, x16, #0xb60
  1f936c:      	br	x17

00000000001f9370 <_ZN7MMCodec10ColorSpace29skcms_MakeUsableAsDestinationEPNS0_16skcms_ICCProfileE@plt>:
  1f9370:      	adrp	x16, 0x205000
  1f9374:      	ldr	x17, [x16, #0xb68]
  1f9378:      	add	x16, x16, #0xb68
  1f937c:      	br	x17

00000000001f9380 <_ZNSt6__ndk16__treeINS_12__value_typeIiiEENS_19__map_value_compareIiS2_NS_4lessIiEELb1EEENS_9allocatorIS2_EEE12__find_equalIiEERPNS_16__tree_node_baseIPvEENS_21__tree_const_iteratorIS2_PNS_11__tree_nodeIS2_SC_EElEERPNS_15__tree_end_nodeISE_EESF_RKT_@plt>:
  1f9380:      	adrp	x16, 0x205000
  1f9384:      	ldr	x17, [x16, #0xb70]
  1f9388:      	add	x16, x16, #0xb70
  1f938c:      	br	x17

00000000001f9390 <fgets@plt>:
  1f9390:      	adrp	x16, 0x205000
  1f9394:      	ldr	x17, [x16, #0xb78]
  1f9398:      	add	x16, x16, #0xb78
  1f939c:      	br	x17

00000000001f93a0 <strstr@plt>:
  1f93a0:      	adrp	x16, 0x205000
  1f93a4:      	ldr	x17, [x16, #0xb80]
  1f93a8:      	add	x16, x16, #0xb80
  1f93ac:      	br	x17

00000000001f93b0 <getauxval@plt>:
  1f93b0:      	adrp	x16, 0x205000
  1f93b4:      	ldr	x17, [x16, #0xb88]
  1f93b8:      	add	x16, x16, #0xb88
  1f93bc:      	br	x17

00000000001f93c0 <__system_property_get@plt>:
  1f93c0:      	adrp	x16, 0x205000
  1f93c4:      	ldr	x17, [x16, #0xb90]
  1f93c8:      	add	x16, x16, #0xb90
  1f93cc:      	br	x17

00000000001f93d0 <strncmp@plt>:
  1f93d0:      	adrp	x16, 0x205000
  1f93d4:      	ldr	x17, [x16, #0xb98]
  1f93d8:      	add	x16, x16, #0xb98
  1f93dc:      	br	x17

00000000001f93e0 <fprintf@plt>:
  1f93e0:      	adrp	x16, 0x205000
  1f93e4:      	ldr	x17, [x16, #0xba0]
  1f93e8:      	add	x16, x16, #0xba0
  1f93ec:      	br	x17

00000000001f93f0 <fflush@plt>:
  1f93f0:      	adrp	x16, 0x205000
  1f93f4:      	ldr	x17, [x16, #0xba8]
  1f93f8:      	add	x16, x16, #0xba8
  1f93fc:      	br	x17

00000000001f9400 <pthread_rwlock_wrlock@plt>:
  1f9400:      	adrp	x16, 0x205000
  1f9404:      	ldr	x17, [x16, #0xbb0]
  1f9408:      	add	x16, x16, #0xbb0
  1f940c:      	br	x17

00000000001f9410 <pthread_rwlock_unlock@plt>:
  1f9410:      	adrp	x16, 0x205000
  1f9414:      	ldr	x17, [x16, #0xbb8]
  1f9418:      	add	x16, x16, #0xbb8
  1f941c:      	br	x17

00000000001f9420 <dl_iterate_phdr@plt>:
  1f9420:      	adrp	x16, 0x205000
  1f9424:      	ldr	x17, [x16, #0xbc0]
  1f9428:      	add	x16, x16, #0xbc0
  1f942c:      	br	x17

00000000001f9430 <pthread_rwlock_rdlock@plt>:
  1f9430:      	adrp	x16, 0x205000
  1f9434:      	ldr	x17, [x16, #0xbc8]
  1f9438:      	add	x16, x16, #0xbc8
  1f943c:      	br	x17

00000000001f9440 <syscall@plt>:
  1f9440:      	adrp	x16, 0x205000
  1f9444:      	ldr	x17, [x16, #0xbd0]
  1f9448:      	add	x16, x16, #0xbd0
  1f944c:      	br	x17
