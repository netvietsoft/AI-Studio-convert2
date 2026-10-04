// EXPORTED & PLT DISASSEMBLY FOR libkoom-strip-dump.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libkoom-strip-dump.so (SHA-256: DB0DB1BDEF5F51386EA2036682C0129B842AA5E3445A26D60EA6C5D29113FAA3)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 997, JNI Methods: 6


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libkoom-strip-dump.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000000851a0 <.plt>:
   851a0:      	stp	x16, x30, [sp, #-0x10]!
   851a4:      	adrp	x16, 0x8f000
   851a8:      	ldr	x17, [x16, #0x178]
   851ac:      	add	x16, x16, #0x178
   851b0:      	br	x17
   851b4:      	nop
   851b8:      	nop
   851bc:      	nop

00000000000851c0 <__cxa_finalize@plt>:
   851c0:      	adrp	x16, 0x8f000
   851c4:      	ldr	x17, [x16, #0x180]
   851c8:      	add	x16, x16, #0x180
   851cc:      	br	x17

00000000000851d0 <__cxa_atexit@plt>:
   851d0:      	adrp	x16, 0x8f000
   851d4:      	ldr	x17, [x16, #0x188]
   851d8:      	add	x16, x16, #0x188
   851dc:      	br	x17

00000000000851e0 <__register_atfork@plt>:
   851e0:      	adrp	x16, 0x8f000
   851e4:      	ldr	x17, [x16, #0x190]
   851e8:      	add	x16, x16, #0x190
   851ec:      	br	x17

00000000000851f0 <_ZN4kwai12leak_monitor9HprofDump11GetInstanceEv@plt>:
   851f0:      	adrp	x16, 0x8f000
   851f4:      	ldr	x17, [x16, #0x198]
   851f8:      	add	x16, x16, #0x198
   851fc:      	br	x17

0000000000085200 <__cxa_guard_acquire@plt>:
   85200:      	adrp	x16, 0x8f000
   85204:      	ldr	x17, [x16, #0x1a0]
   85208:      	add	x16, x16, #0x1a0
   8520c:      	br	x17

0000000000085210 <_ZN4kwai12leak_monitor9HprofDumpC1Ev@plt>:
   85210:      	adrp	x16, 0x8f000
   85214:      	ldr	x17, [x16, #0x1a8]
   85218:      	add	x16, x16, #0x1a8
   8521c:      	br	x17

0000000000085220 <__cxa_guard_release@plt>:
   85220:      	adrp	x16, 0x8f000
   85224:      	ldr	x17, [x16, #0x1b0]
   85228:      	add	x16, x16, #0x1b0
   8522c:      	br	x17

0000000000085230 <__cxa_guard_abort@plt>:
   85230:      	adrp	x16, 0x8f000
   85234:      	ldr	x17, [x16, #0x1b8]
   85238:      	add	x16, x16, #0x1b8
   8523c:      	br	x17

0000000000085240 <__system_property_get@plt>:
   85240:      	adrp	x16, 0x8f000
   85244:      	ldr	x17, [x16, #0x1c0]
   85248:      	add	x16, x16, #0x1c0
   8524c:      	br	x17

0000000000085250 <atoi@plt>:
   85250:      	adrp	x16, 0x8f000
   85254:      	ldr	x17, [x16, #0x1c8]
   85258:      	add	x16, x16, #0x1c8
   8525c:      	br	x17

0000000000085260 <__stack_chk_fail@plt>:
   85260:      	adrp	x16, 0x8f000
   85264:      	ldr	x17, [x16, #0x1d0]
   85268:      	add	x16, x16, #0x1d0
   8526c:      	br	x17

0000000000085270 <_ZN4kwai12leak_monitor9HprofDump10InitializeEv@plt>:
   85270:      	adrp	x16, 0x8f000
   85274:      	ldr	x17, [x16, #0x1d8]
   85278:      	add	x16, x16, #0x1d8
   8527c:      	br	x17

0000000000085280 <_ZN4kwai6linker5DlFcn6dlopenEPKci@plt>:
   85280:      	adrp	x16, 0x8f000
   85284:      	ldr	x17, [x16, #0x1e0]
   85288:      	add	x16, x16, #0x1e0
   8528c:      	br	x17

0000000000085290 <__errno@plt>:
   85290:      	adrp	x16, 0x8f000
   85294:      	ldr	x17, [x16, #0x1e8]
   85298:      	add	x16, x16, #0x1e8
   8529c:      	br	x17

00000000000852a0 <async_safe_format_log@plt>:
   852a0:      	adrp	x16, 0x8f000
   852a4:      	ldr	x17, [x16, #0x1f0]
   852a8:      	add	x16, x16, #0x1f0
   852ac:      	br	x17

00000000000852b0 <_Znam@plt>:
   852b0:      	adrp	x16, 0x8f000
   852b4:      	ldr	x17, [x16, #0x1f8]
   852b8:      	add	x16, x16, #0x1f8
   852bc:      	br	x17

00000000000852c0 <_ZNSt6__ndk110unique_ptrIA_cNS_14default_deleteIS1_EEE5resetB8ne180000IPcTnNS_9enable_ifIXsr28_CheckArrayPointerConversionIT_EE5valueEiE4typeELi0EEEvS8_@plt>:
   852c0:      	adrp	x16, 0x8f000
   852c4:      	ldr	x17, [x16, #0x200]
   852c8:      	add	x16, x16, #0x200
   852cc:      	br	x17

00000000000852d0 <_ZN4kwai6linker5DlFcn7dlcloseEPv@plt>:
   852d0:      	adrp	x16, 0x8f000
   852d4:      	ldr	x17, [x16, #0x208]
   852d8:      	add	x16, x16, #0x208
   852dc:      	br	x17

00000000000852e0 <_ZN4kwai12leak_monitor9HprofDump14SuspendAndForkEv@plt>:
   852e0:      	adrp	x16, 0x8f000
   852e4:      	ldr	x17, [x16, #0x210]
   852e8:      	add	x16, x16, #0x210
   852ec:      	br	x17

00000000000852f0 <fork@plt>:
   852f0:      	adrp	x16, 0x8f000
   852f4:      	ldr	x17, [x16, #0x218]
   852f8:      	add	x16, x16, #0x218
   852fc:      	br	x17

0000000000085300 <alarm@plt>:
   85300:      	adrp	x16, 0x8f000
   85304:      	ldr	x17, [x16, #0x220]
   85308:      	add	x16, x16, #0x220
   8530c:      	br	x17

0000000000085310 <prctl@plt>:
   85310:      	adrp	x16, 0x8f000
   85314:      	ldr	x17, [x16, #0x228]
   85318:      	add	x16, x16, #0x228
   8531c:      	br	x17

0000000000085320 <_ZN4kwai12leak_monitor9HprofDump13ResumeAndWaitEi@plt>:
   85320:      	adrp	x16, 0x8f000
   85324:      	ldr	x17, [x16, #0x230]
   85328:      	add	x16, x16, #0x230
   8532c:      	br	x17

0000000000085330 <waitpid@plt>:
   85330:      	adrp	x16, 0x8f000
   85334:      	ldr	x17, [x16, #0x238]
   85338:      	add	x16, x16, #0x238
   8533c:      	br	x17

0000000000085340 <__android_log_print@plt>:
   85340:      	adrp	x16, 0x8f000
   85344:      	ldr	x17, [x16, #0x240]
   85348:      	add	x16, x16, #0x240
   8534c:      	br	x17

0000000000085350 <_ZdaPv@plt>:
   85350:      	adrp	x16, 0x8f000
   85354:      	ldr	x17, [x16, #0x248]
   85358:      	add	x16, x16, #0x248
   8535c:      	br	x17

0000000000085360 <strerror@plt>:
   85360:      	adrp	x16, 0x8f000
   85364:      	ldr	x17, [x16, #0x250]
   85368:      	add	x16, x16, #0x250
   8536c:      	br	x17

0000000000085370 <_ZN4kwai6linker5DlFcn5dlsymEPvPKc@plt>:
   85370:      	adrp	x16, 0x8f000
   85374:      	ldr	x17, [x16, #0x258]
   85378:      	add	x16, x16, #0x258
   8537c:      	br	x17

0000000000085380 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ne180000ILi0EEEPKc@plt>:
   85380:      	adrp	x16, 0x8f000
   85384:      	ldr	x17, [x16, #0x260]
   85388:      	add	x16, x16, #0x260
   8538c:      	br	x17

0000000000085390 <strlen@plt>:
   85390:      	adrp	x16, 0x8f000
   85394:      	ldr	x17, [x16, #0x268]
   85398:      	add	x16, x16, #0x268
   8539c:      	br	x17

00000000000853a0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEPKcm@plt>:
   853a0:      	adrp	x16, 0x8f000
   853a4:      	ldr	x17, [x16, #0x270]
   853a8:      	add	x16, x16, #0x270
   853ac:      	br	x17

00000000000853b0 <_ZN4kwai12leak_monitor10HprofStrip8HookInitEv@plt>:
   853b0:      	adrp	x16, 0x8f000
   853b4:      	ldr	x17, [x16, #0x278]
   853b8:      	add	x16, x16, #0x278
   853bc:      	br	x17

00000000000853c0 <bytehook_init@plt>:
   853c0:      	adrp	x16, 0x8f000
   853c4:      	ldr	x17, [x16, #0x280]
   853c8:      	add	x16, x16, #0x280
   853cc:      	br	x17

00000000000853d0 <bytehook_hook_single@plt>:
   853d0:      	adrp	x16, 0x8f000
   853d4:      	ldr	x17, [x16, #0x288]
   853d8:      	add	x16, x16, #0x288
   853dc:      	br	x17

00000000000853e0 <bytehook_get_prev_func@plt>:
   853e0:      	adrp	x16, 0x8f000
   853e4:      	ldr	x17, [x16, #0x290]
   853e8:      	add	x16, x16, #0x290
   853ec:      	br	x17

00000000000853f0 <strstr@plt>:
   853f0:      	adrp	x16, 0x8f000
   853f4:      	ldr	x17, [x16, #0x298]
   853f8:      	add	x16, x16, #0x298
   853fc:      	br	x17

0000000000085400 <bytehook_get_mode@plt>:
   85400:      	adrp	x16, 0x8f000
   85404:      	ldr	x17, [x16, #0x2a0]
   85408:      	add	x16, x16, #0x2a0
   8540c:      	br	x17

0000000000085410 <bytehook_pop_stack@plt>:
   85410:      	adrp	x16, 0x8f000
   85414:      	ldr	x17, [x16, #0x2a8]
   85418:      	add	x16, x16, #0x2a8
   8541c:      	br	x17

0000000000085420 <_ZN4kwai12leak_monitor10HprofStrip11GetInstanceEv@plt>:
   85420:      	adrp	x16, 0x8f000
   85424:      	ldr	x17, [x16, #0x2b0]
   85428:      	add	x16, x16, #0x2b0
   8542c:      	br	x17

0000000000085430 <_ZN4kwai12leak_monitor10HprofStripC1Ev@plt>:
   85430:      	adrp	x16, 0x8f000
   85434:      	ldr	x17, [x16, #0x2b8]
   85438:      	add	x16, x16, #0x2b8
   8543c:      	br	x17

0000000000085440 <_ZN4kwai12leak_monitor10HprofStrip12SetHprofNameEPKc@plt>:
   85440:      	adrp	x16, 0x8f000
   85444:      	ldr	x17, [x16, #0x2c0]
   85448:      	add	x16, x16, #0x2c0
   8544c:      	br	x17

0000000000085450 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   85450:      	adrp	x16, 0x8f000
   85454:      	ldr	x17, [x16, #0x2c8]
   85458:      	add	x16, x16, #0x2c8
   8545c:      	br	x17

0000000000085460 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED2Ev@plt>:
   85460:      	adrp	x16, 0x8f000
   85464:      	ldr	x17, [x16, #0x2d0]
   85468:      	add	x16, x16, #0x2d0
   8546c:      	br	x17

0000000000085470 <getpid@plt>:
   85470:      	adrp	x16, 0x8f000
   85474:      	ldr	x17, [x16, #0x2d8]
   85478:      	add	x16, x16, #0x2d8
   8547c:      	br	x17

0000000000085480 <_exit@plt>:
   85480:      	adrp	x16, 0x8f000
   85484:      	ldr	x17, [x16, #0x2e0]
   85488:      	add	x16, x16, #0x2e0
   8548c:      	br	x17

0000000000085490 <_ZN4kwai6linker9ElfReader10IsValidElfEv@plt>:
   85490:      	adrp	x16, 0x8f000
   85494:      	ldr	x17, [x16, #0x2e8]
   85498:      	add	x16, x16, #0x2e8
   8549c:      	br	x17

00000000000854a0 <_ZN4kwai6linker9ElfReader4InitEv@plt>:
   854a0:      	adrp	x16, 0x8f000
   854a4:      	ldr	x17, [x16, #0x2f0]
   854a8:      	add	x16, x16, #0x2f0
   854ac:      	br	x17

00000000000854b0 <strcmp@plt>:
   854b0:      	adrp	x16, 0x8f000
   854b4:      	ldr	x17, [x16, #0x2f8]
   854b8:      	add	x16, x16, #0x2f8
   854bc:      	br	x17

00000000000854c0 <_ZN4kwai6linker9ElfReader12BuildGnuHashEPj@plt>:
   854c0:      	adrp	x16, 0x8f000
   854c4:      	ldr	x17, [x16, #0x300]
   854c8:      	add	x16, x16, #0x300
   854cc:      	br	x17

00000000000854d0 <_ZN4kwai6linker9ElfReader9BuildHashEPj@plt>:
   854d0:      	adrp	x16, 0x8f000
   854d4:      	ldr	x17, [x16, #0x308]
   854d8:      	add	x16, x16, #0x308
   854dc:      	br	x17

00000000000854e0 <_ZN4kwai6linker9ElfReader12LookupSymbolEPKcyb@plt>:
   854e0:      	adrp	x16, 0x8f000
   854e4:      	ldr	x17, [x16, #0x310]
   854e8:      	add	x16, x16, #0x310
   854ec:      	br	x17

00000000000854f0 <_ZN4kwai6linker9ElfReader15LookupByGnuHashEPKc@plt>:
   854f0:      	adrp	x16, 0x8f000
   854f4:      	ldr	x17, [x16, #0x318]
   854f8:      	add	x16, x16, #0x318
   854fc:      	br	x17

0000000000085500 <_ZN4kwai6linker9ElfReader15LookupByElfHashEPKc@plt>:
   85500:      	adrp	x16, 0x8f000
   85504:      	ldr	x17, [x16, #0x320]
   85508:      	add	x16, x16, #0x320
   8550c:      	br	x17

0000000000085510 <_ZN4kwai6linker9ElfReader15DecGnuDebugdataERNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   85510:      	adrp	x16, 0x8f000
   85514:      	ldr	x17, [x16, #0x328]
   85518:      	add	x16, x16, #0x328
   8551c:      	br	x17

0000000000085520 <_ZN4kwai6linker9ElfReaderC1ENSt6__ndk110shared_ptrINS0_10ElfWrapperEEE@plt>:
   85520:      	adrp	x16, 0x8f000
   85524:      	ldr	x17, [x16, #0x330]
   85528:      	add	x16, x16, #0x330
   8552c:      	br	x17

0000000000085530 <_ZN4kwai6linker9ElfReader7GnuHash4HashEPKh@plt>:
   85530:      	adrp	x16, 0x8f000
   85534:      	ldr	x17, [x16, #0x338]
   85538:      	add	x16, x16, #0x338
   8553c:      	br	x17

0000000000085540 <_ZN4kwai6linker9ElfReader7ElfHash4HashEPKh@plt>:
   85540:      	adrp	x16, 0x8f000
   85544:      	ldr	x17, [x16, #0x340]
   85548:      	add	x16, x16, #0x340
   8554c:      	br	x17

0000000000085550 <XzUnpacker_Construct@plt>:
   85550:      	adrp	x16, 0x8f000
   85554:      	ldr	x17, [x16, #0x348]
   85558:      	add	x16, x16, #0x348
   8555c:      	br	x17

0000000000085560 <CrcGenerateTable@plt>:
   85560:      	adrp	x16, 0x8f000
   85564:      	ldr	x17, [x16, #0x350]
   85568:      	add	x16, x16, #0x350
   8556c:      	br	x17

0000000000085570 <Crc64GenerateTable@plt>:
   85570:      	adrp	x16, 0x8f000
   85574:      	ldr	x17, [x16, #0x358]
   85578:      	add	x16, x16, #0x358
   8557c:      	br	x17

0000000000085580 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6__initEmc@plt>:
   85580:      	adrp	x16, 0x8f000
   85584:      	ldr	x17, [x16, #0x360]
   85588:      	add	x16, x16, #0x360
   8558c:      	br	x17

0000000000085590 <XzUnpacker_Code@plt>:
   85590:      	adrp	x16, 0x8f000
   85594:      	ldr	x17, [x16, #0x368]
   85598:      	add	x16, x16, #0x368
   8559c:      	br	x17

00000000000855a0 <XzUnpacker_Free@plt>:
   855a0:      	adrp	x16, 0x8f000
   855a4:      	ldr	x17, [x16, #0x370]
   855a8:      	add	x16, x16, #0x370
   855ac:      	br	x17

00000000000855b0 <XzUnpacker_IsStreamWasFinished@plt>:
   855b0:      	adrp	x16, 0x8f000
   855b4:      	ldr	x17, [x16, #0x378]
   855b8:      	add	x16, x16, #0x378
   855bc:      	br	x17

00000000000855c0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   855c0:      	adrp	x16, 0x8f000
   855c4:      	ldr	x17, [x16, #0x380]
   855c8:      	add	x16, x16, #0x380
   855cc:      	br	x17

00000000000855d0 <malloc@plt>:
   855d0:      	adrp	x16, 0x8f000
   855d4:      	ldr	x17, [x16, #0x388]
   855d8:      	add	x16, x16, #0x388
   855dc:      	br	x17

00000000000855e0 <free@plt>:
   855e0:      	adrp	x16, 0x8f000
   855e4:      	ldr	x17, [x16, #0x390]
   855e8:      	add	x16, x16, #0x390
   855ec:      	br	x17

00000000000855f0 <_ZdlPv@plt>:
   855f0:      	adrp	x16, 0x8f000
   855f4:      	ldr	x17, [x16, #0x398]
   855f8:      	add	x16, x16, #0x398
   855fc:      	br	x17

0000000000085600 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   85600:      	adrp	x16, 0x8f000
   85604:      	ldr	x17, [x16, #0x3a0]
   85608:      	add	x16, x16, #0x3a0
   8560c:      	br	x17

0000000000085610 <_ZNSt6__ndk118__allocation_guardINS_9allocatorINS_20__shared_ptr_emplaceIN4kwai6linker16MemoryElfWrapperENS1_IS5_EEEEEEEC2B8ne180000IS6_EET_m@plt>:
   85610:      	adrp	x16, 0x8f000
   85614:      	ldr	x17, [x16, #0x3a8]
   85618:      	add	x16, x16, #0x3a8
   8561c:      	br	x17

0000000000085620 <_ZNSt6__ndk120__shared_ptr_emplaceIN4kwai6linker16MemoryElfWrapperENS_9allocatorIS3_EEEC2B8ne180000IJRNS_12basic_stringIcNS_11char_traitsIcEENS4_IcEEEEES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   85620:      	adrp	x16, 0x8f000
   85624:      	ldr	x17, [x16, #0x3b0]
   85628:      	add	x16, x16, #0x3b0
   8562c:      	br	x17

0000000000085630 <_ZN4kwai6linker16MemoryElfWrapperC2ERNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   85630:      	adrp	x16, 0x8f000
   85634:      	ldr	x17, [x16, #0x3b8]
   85638:      	add	x16, x16, #0x3b8
   8563c:      	br	x17

0000000000085640 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   85640:      	adrp	x16, 0x8f000
   85644:      	ldr	x17, [x16, #0x3c0]
   85648:      	add	x16, x16, #0x3c0
   8564c:      	br	x17

0000000000085650 <_Znwm@plt>:
   85650:      	adrp	x16, 0x8f000
   85654:      	ldr	x17, [x16, #0x3c8]
   85658:      	add	x16, x16, #0x3c8
   8565c:      	br	x17

0000000000085660 <__cxa_allocate_exception@plt>:
   85660:      	adrp	x16, 0x8f000
   85664:      	ldr	x17, [x16, #0x3d0]
   85668:      	add	x16, x16, #0x3d0
   8566c:      	br	x17

0000000000085670 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
   85670:      	adrp	x16, 0x8f000
   85674:      	ldr	x17, [x16, #0x3d8]
   85678:      	add	x16, x16, #0x3d8
   8567c:      	br	x17

0000000000085680 <_ZNSt20bad_array_new_lengthD1Ev@plt>:
   85680:      	adrp	x16, 0x8f000
   85684:      	ldr	x17, [x16, #0x3e0]
   85688:      	add	x16, x16, #0x3e0
   8568c:      	br	x17

0000000000085690 <__cxa_throw@plt>:
   85690:      	adrp	x16, 0x8f000
   85694:      	ldr	x17, [x16, #0x3e8]
   85698:      	add	x16, x16, #0x3e8
   8569c:      	br	x17

00000000000856a0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4kwai6linker16MemoryElfWrapperENS_9allocatorIS3_EEED2Ev@plt>:
   856a0:      	adrp	x16, 0x8f000
   856a4:      	ldr	x17, [x16, #0x3f0]
   856a8:      	add	x16, x16, #0x3f0
   856ac:      	br	x17

00000000000856b0 <_ZN4kwai6linker16MemoryElfWrapperD2Ev@plt>:
   856b0:      	adrp	x16, 0x8f000
   856b4:      	ldr	x17, [x16, #0x3f8]
   856b8:      	add	x16, x16, #0x3f8
   856bc:      	br	x17

00000000000856c0 <dl_iterate_phdr@plt>:
   856c0:      	adrp	x16, 0x8f000
   856c4:      	ldr	x17, [x16, #0x400]
   856c8:      	add	x16, x16, #0x400
   856cc:      	br	x17

00000000000856d0 <dlopen@plt>:
   856d0:      	adrp	x16, 0x8f000
   856d4:      	ldr	x17, [x16, #0x408]
   856d8:      	add	x16, x16, #0x408
   856dc:      	br	x17

00000000000856e0 <dlsym@plt>:
   856e0:      	adrp	x16, 0x8f000
   856e4:      	ldr	x17, [x16, #0x410]
   856e8:      	add	x16, x16, #0x410
   856ec:      	br	x17

00000000000856f0 <dlclose@plt>:
   856f0:      	adrp	x16, 0x8f000
   856f4:      	ldr	x17, [x16, #0x418]
   856f8:      	add	x16, x16, #0x418
   856fc:      	br	x17

0000000000085700 <_ZnwmRKSt9nothrow_t@plt>:
   85700:      	adrp	x16, 0x8f000
   85704:      	ldr	x17, [x16, #0x420]
   85708:      	add	x16, x16, #0x420
   8570c:      	br	x17

0000000000085710 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   85710:      	adrp	x16, 0x8f000
   85714:      	ldr	x17, [x16, #0x428]
   85718:      	add	x16, x16, #0x428
   8571c:      	br	x17

0000000000085720 <fopen@plt>:
   85720:      	adrp	x16, 0x8f000
   85724:      	ldr	x17, [x16, #0x430]
   85728:      	add	x16, x16, #0x430
   8572c:      	br	x17

0000000000085730 <fgets@plt>:
   85730:      	adrp	x16, 0x8f000
   85734:      	ldr	x17, [x16, #0x438]
   85738:      	add	x16, x16, #0x438
   8573c:      	br	x17

0000000000085740 <_ZZN4kwai6linker7MapUtil17GetLoadInfoByMapsERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPyRS8_ENKUlPcRNS1_8MapEntryERiE_clESD_SF_SG_@plt>:
   85740:      	adrp	x16, 0x8f000
   85744:      	ldr	x17, [x16, #0x440]
   85748:      	add	x16, x16, #0x440
   8574c:      	br	x17

0000000000085750 <__strlen_chk@plt>:
   85750:      	adrp	x16, 0x8f000
   85754:      	ldr	x17, [x16, #0x448]
   85758:      	add	x16, x16, #0x448
   8575c:      	br	x17

0000000000085760 <_ZN4kwai6linker7MapUtil8EndsWithEPKcS3_@plt>:
   85760:      	adrp	x16, 0x8f000
   85764:      	ldr	x17, [x16, #0x450]
   85768:      	add	x16, x16, #0x450
   8576c:      	br	x17

0000000000085770 <_ZN4kwai6linker7MapUtil12ReadLoadBiasERNS1_8MapEntryEPy@plt>:
   85770:      	adrp	x16, 0x8f000
   85774:      	ldr	x17, [x16, #0x458]
   85778:      	add	x16, x16, #0x458
   8577c:      	br	x17

0000000000085780 <_ZN4kwai6linker7MapUtil8MapEntryaSERKS2_@plt>:
   85780:      	adrp	x16, 0x8f000
   85784:      	ldr	x17, [x16, #0x460]
   85788:      	add	x16, x16, #0x460
   8578c:      	br	x17

0000000000085790 <fclose@plt>:
   85790:      	adrp	x16, 0x8f000
   85794:      	ldr	x17, [x16, #0x468]
   85798:      	add	x16, x16, #0x468
   8579c:      	br	x17

00000000000857a0 <_ZZN4kwai6linker7MapUtil15GetLoadInfoByDlERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEEPyRS8_ENKUlP12dl_phdr_infomPvE_clESE_mSF_@plt>:
   857a0:      	adrp	x16, 0x8f000
   857a4:      	ldr	x17, [x16, #0x470]
   857a8:      	add	x16, x16, #0x470
   857ac:      	br	x17

00000000000857b0 <sscanf@plt>:
   857b0:      	adrp	x16, 0x8f000
   857b4:      	ldr	x17, [x16, #0x478]
   857b8:      	add	x16, x16, #0x478
   857bc:      	br	x17

00000000000857c0 <_ZN4kwai6linker7MapUtil6GetValItEEbRNS1_8MapEntryEmPT_@plt>:
   857c0:      	adrp	x16, 0x8f000
   857c4:      	ldr	x17, [x16, #0x480]
   857c8:      	add	x16, x16, #0x480
   857cc:      	br	x17

00000000000857d0 <_ZN4kwai6linker7MapUtil6GetValIyEEbRNS1_8MapEntryEmPT_@plt>:
   857d0:      	adrp	x16, 0x8f000
   857d4:      	ldr	x17, [x16, #0x488]
   857d8:      	add	x16, x16, #0x488
   857dc:      	br	x17

00000000000857e0 <_ZN4kwai6linker7MapUtil6GetValIjEEbRNS1_8MapEntryEmPT_@plt>:
   857e0:      	adrp	x16, 0x8f000
   857e4:      	ldr	x17, [x16, #0x490]
   857e8:      	add	x16, x16, #0x490
   857ec:      	br	x17

00000000000857f0 <__cxa_begin_catch@plt>:
   857f0:      	adrp	x16, 0x8f000
   857f4:      	ldr	x17, [x16, #0x498]
   857f8:      	add	x16, x16, #0x498
   857fc:      	br	x17

0000000000085800 <_ZSt9terminatev@plt>:
   85800:      	adrp	x16, 0x8f000
   85804:      	ldr	x17, [x16, #0x4a0]
   85808:      	add	x16, x16, #0x4a0
   8580c:      	br	x17

0000000000085810 <_ZNSt12length_errorD1Ev@plt>:
   85810:      	adrp	x16, 0x8f000
   85814:      	ldr	x17, [x16, #0x4a8]
   85818:      	add	x16, x16, #0x4a8
   8581c:      	br	x17

0000000000085820 <__cxa_free_exception@plt>:
   85820:      	adrp	x16, 0x8f000
   85824:      	ldr	x17, [x16, #0x4b0]
   85828:      	add	x16, x16, #0x4b0
   8582c:      	br	x17

0000000000085830 <_ZNSt11logic_errorC2EPKc@plt>:
   85830:      	adrp	x16, 0x8f000
   85834:      	ldr	x17, [x16, #0x4b8]
   85838:      	add	x16, x16, #0x4b8
   8583c:      	br	x17

0000000000085840 <_ZNSt6__ndk118__allocation_guardINS_9allocatorINS_20__shared_ptr_emplaceIN4kwai6linker14FileElfWrapperENS1_IS5_EEEEEEEC2B8ne180000IS6_EET_m@plt>:
   85840:      	adrp	x16, 0x8f000
   85844:      	ldr	x17, [x16, #0x4c0]
   85848:      	add	x16, x16, #0x4c0
   8584c:      	br	x17

0000000000085850 <_ZNSt6__ndk120__shared_ptr_emplaceIN4kwai6linker14FileElfWrapperENS_9allocatorIS3_EEEC2B8ne180000IJRPKcES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   85850:      	adrp	x16, 0x8f000
   85854:      	ldr	x17, [x16, #0x4c8]
   85858:      	add	x16, x16, #0x4c8
   8585c:      	br	x17

0000000000085860 <_ZN4kwai6linker14FileElfWrapperC2EPKc@plt>:
   85860:      	adrp	x16, 0x8f000
   85864:      	ldr	x17, [x16, #0x4d0]
   85868:      	add	x16, x16, #0x4d0
   8586c:      	br	x17

0000000000085870 <_ZNSt6__ndk120__shared_ptr_emplaceIN4kwai6linker14FileElfWrapperENS_9allocatorIS3_EEED2Ev@plt>:
   85870:      	adrp	x16, 0x8f000
   85874:      	ldr	x17, [x16, #0x4d8]
   85878:      	add	x16, x16, #0x4d8
   8587c:      	br	x17

0000000000085880 <__open_2@plt>:
   85880:      	adrp	x16, 0x8f000
   85884:      	ldr	x17, [x16, #0x4e0]
   85888:      	add	x16, x16, #0x4e0
   8588c:      	br	x17

0000000000085890 <lseek@plt>:
   85890:      	adrp	x16, 0x8f000
   85894:      	ldr	x17, [x16, #0x4e8]
   85898:      	add	x16, x16, #0x4e8
   8589c:      	br	x17

00000000000858a0 <mmap@plt>:
   858a0:      	adrp	x16, 0x8f000
   858a4:      	ldr	x17, [x16, #0x4f0]
   858a8:      	add	x16, x16, #0x4f0
   858ac:      	br	x17

00000000000858b0 <_ZN4kwai6linker14FileElfWrapperD2Ev@plt>:
   858b0:      	adrp	x16, 0x8f000
   858b4:      	ldr	x17, [x16, #0x4f8]
   858b8:      	add	x16, x16, #0x4f8
   858bc:      	br	x17

00000000000858c0 <munmap@plt>:
   858c0:      	adrp	x16, 0x8f000
   858c4:      	ldr	x17, [x16, #0x500]
   858c8:      	add	x16, x16, #0x500
   858cc:      	br	x17

00000000000858d0 <close@plt>:
   858d0:      	adrp	x16, 0x8f000
   858d4:      	ldr	x17, [x16, #0x508]
   858d8:      	add	x16, x16, #0x508
   858dc:      	br	x17

00000000000858e0 <_ZNSt6__ndk120__shared_ptr_emplaceIN4kwai6linker14FileElfWrapperENS_9allocatorIS3_EEEC2B8ne180000IJPKcES5_TnNS_9enable_ifIXntsr7is_sameINT0_10value_typeENS_19__for_overwrite_tagEEE5valueEiE4typeELi0EEES5_DpOT_@plt>:
   858e0:      	adrp	x16, 0x8f000
   858e4:      	ldr	x17, [x16, #0x510]
   858e8:      	add	x16, x16, #0x510
   858ec:      	br	x17

00000000000858f0 <pthread_once@plt>:
   858f0:      	adrp	x16, 0x8f000
   858f4:      	ldr	x17, [x16, #0x518]
   858f8:      	add	x16, x16, #0x518
   858fc:      	br	x17

0000000000085900 <SzBitUi32s_Free@plt>:
   85900:      	adrp	x16, 0x8f000
   85904:      	ldr	x17, [x16, #0x520]
   85908:      	add	x16, x16, #0x520
   8590c:      	br	x17

0000000000085910 <SzBitUi64s_Free@plt>:
   85910:      	adrp	x16, 0x8f000
   85914:      	ldr	x17, [x16, #0x528]
   85918:      	add	x16, x16, #0x528
   8591c:      	br	x17

0000000000085920 <SzArEx_Free@plt>:
   85920:      	adrp	x16, 0x8f000
   85924:      	ldr	x17, [x16, #0x530]
   85928:      	add	x16, x16, #0x530
   8592c:      	br	x17

0000000000085930 <SzGetNextFolderItem@plt>:
   85930:      	adrp	x16, 0x8f000
   85934:      	ldr	x17, [x16, #0x538]
   85938:      	add	x16, x16, #0x538
   8593c:      	br	x17

0000000000085940 <SzAr_GetFolderUnpackSize@plt>:
   85940:      	adrp	x16, 0x8f000
   85944:      	ldr	x17, [x16, #0x540]
   85948:      	add	x16, x16, #0x540
   8594c:      	br	x17

0000000000085950 <LookInStream_Read2@plt>:
   85950:      	adrp	x16, 0x8f000
   85954:      	ldr	x17, [x16, #0x548]
   85958:      	add	x16, x16, #0x548
   8595c:      	br	x17

0000000000085960 <CrcCalc@plt>:
   85960:      	adrp	x16, 0x8f000
   85964:      	ldr	x17, [x16, #0x550]
   85968:      	add	x16, x16, #0x550
   8596c:      	br	x17

0000000000085970 <LookInStream_SeekTo@plt>:
   85970:      	adrp	x16, 0x8f000
   85974:      	ldr	x17, [x16, #0x558]
   85978:      	add	x16, x16, #0x558
   8597c:      	br	x17

0000000000085980 <Buf_Create@plt>:
   85980:      	adrp	x16, 0x8f000
   85984:      	ldr	x17, [x16, #0x560]
   85988:      	add	x16, x16, #0x560
   8598c:      	br	x17

0000000000085990 <LookInStream_Read@plt>:
   85990:      	adrp	x16, 0x8f000
   85994:      	ldr	x17, [x16, #0x568]
   85998:      	add	x16, x16, #0x568
   8599c:      	br	x17

00000000000859a0 <Buf_Init@plt>:
   859a0:      	adrp	x16, 0x8f000
   859a4:      	ldr	x17, [x16, #0x570]
   859a8:      	add	x16, x16, #0x570
   859ac:      	br	x17

00000000000859b0 <memcpy@plt>:
   859b0:      	adrp	x16, 0x8f000
   859b4:      	ldr	x17, [x16, #0x578]
   859b8:      	add	x16, x16, #0x578
   859bc:      	br	x17

00000000000859c0 <SzAr_DecodeFolder@plt>:
   859c0:      	adrp	x16, 0x8f000
   859c4:      	ldr	x17, [x16, #0x580]
   859c8:      	add	x16, x16, #0x580
   859cc:      	br	x17

00000000000859d0 <memset@plt>:
   859d0:      	adrp	x16, 0x8f000
   859d4:      	ldr	x17, [x16, #0x588]
   859d8:      	add	x16, x16, #0x588
   859dc:      	br	x17

00000000000859e0 <Buf_Free@plt>:
   859e0:      	adrp	x16, 0x8f000
   859e4:      	ldr	x17, [x16, #0x590]
   859e8:      	add	x16, x16, #0x590
   859ec:      	br	x17

00000000000859f0 <CrcUpdate@plt>:
   859f0:      	adrp	x16, 0x8f000
   859f4:      	ldr	x17, [x16, #0x598]
   859f8:      	add	x16, x16, #0x598
   859fc:      	br	x17

0000000000085a00 <Bcj2Dec_Init@plt>:
   85a00:      	adrp	x16, 0x8f000
   85a04:      	ldr	x17, [x16, #0x5a0]
   85a08:      	add	x16, x16, #0x5a0
   85a0c:      	br	x17

0000000000085a10 <Bcj2Dec_Decode@plt>:
   85a10:      	adrp	x16, 0x8f000
   85a14:      	ldr	x17, [x16, #0x5a8]
   85a18:      	add	x16, x16, #0x5a8
   85a1c:      	br	x17

0000000000085a20 <Delta_Init@plt>:
   85a20:      	adrp	x16, 0x8f000
   85a24:      	ldr	x17, [x16, #0x5b0]
   85a28:      	add	x16, x16, #0x5b0
   85a2c:      	br	x17

0000000000085a30 <Delta_Decode@plt>:
   85a30:      	adrp	x16, 0x8f000
   85a34:      	ldr	x17, [x16, #0x5b8]
   85a38:      	add	x16, x16, #0x5b8
   85a3c:      	br	x17

0000000000085a40 <Lzma2Dec_AllocateProbs@plt>:
   85a40:      	adrp	x16, 0x8f000
   85a44:      	ldr	x17, [x16, #0x5c0]
   85a48:      	add	x16, x16, #0x5c0
   85a4c:      	br	x17

0000000000085a50 <Lzma2Dec_Init@plt>:
   85a50:      	adrp	x16, 0x8f000
   85a54:      	ldr	x17, [x16, #0x5c8]
   85a58:      	add	x16, x16, #0x5c8
   85a5c:      	br	x17

0000000000085a60 <Lzma2Dec_DecodeToDic@plt>:
   85a60:      	adrp	x16, 0x8f000
   85a64:      	ldr	x17, [x16, #0x5d0]
   85a68:      	add	x16, x16, #0x5d0
   85a6c:      	br	x17

0000000000085a70 <LzmaDec_AllocateProbs@plt>:
   85a70:      	adrp	x16, 0x8f000
   85a74:      	ldr	x17, [x16, #0x5d8]
   85a78:      	add	x16, x16, #0x5d8
   85a7c:      	br	x17

0000000000085a80 <LzmaDec_Init@plt>:
   85a80:      	adrp	x16, 0x8f000
   85a84:      	ldr	x17, [x16, #0x5e0]
   85a88:      	add	x16, x16, #0x5e0
   85a8c:      	br	x17

0000000000085a90 <LzmaDec_DecodeToDic@plt>:
   85a90:      	adrp	x16, 0x8f000
   85a94:      	ldr	x17, [x16, #0x5e8]
   85a98:      	add	x16, x16, #0x5e8
   85a9c:      	br	x17

0000000000085aa0 <x86_Convert@plt>:
   85aa0:      	adrp	x16, 0x8f000
   85aa4:      	ldr	x17, [x16, #0x5f0]
   85aa8:      	add	x16, x16, #0x5f0
   85aac:      	br	x17

0000000000085ab0 <LzmaDec_FreeProbs@plt>:
   85ab0:      	adrp	x16, 0x8f000
   85ab4:      	ldr	x17, [x16, #0x5f8]
   85ab8:      	add	x16, x16, #0x5f8
   85abc:      	br	x17

0000000000085ac0 <IA64_Convert@plt>:
   85ac0:      	adrp	x16, 0x8f000
   85ac4:      	ldr	x17, [x16, #0x600]
   85ac8:      	add	x16, x16, #0x600
   85acc:      	br	x17

0000000000085ad0 <ARMT_Convert@plt>:
   85ad0:      	adrp	x16, 0x8f000
   85ad4:      	ldr	x17, [x16, #0x608]
   85ad8:      	add	x16, x16, #0x608
   85adc:      	br	x17

0000000000085ae0 <SPARC_Convert@plt>:
   85ae0:      	adrp	x16, 0x8f000
   85ae4:      	ldr	x17, [x16, #0x610]
   85ae8:      	add	x16, x16, #0x610
   85aec:      	br	x17

0000000000085af0 <ARM_Convert@plt>:
   85af0:      	adrp	x16, 0x8f000
   85af4:      	ldr	x17, [x16, #0x618]
   85af8:      	add	x16, x16, #0x618
   85afc:      	br	x17

0000000000085b00 <PPC_Convert@plt>:
   85b00:      	adrp	x16, 0x8f000
   85b04:      	ldr	x17, [x16, #0x620]
   85b08:      	add	x16, x16, #0x620
   85b0c:      	br	x17

0000000000085b10 <File_Read@plt>:
   85b10:      	adrp	x16, 0x8f000
   85b14:      	ldr	x17, [x16, #0x628]
   85b18:      	add	x16, x16, #0x628
   85b1c:      	br	x17

0000000000085b20 <fread@plt>:
   85b20:      	adrp	x16, 0x8f000
   85b24:      	ldr	x17, [x16, #0x630]
   85b28:      	add	x16, x16, #0x630
   85b2c:      	br	x17

0000000000085b30 <ferror@plt>:
   85b30:      	adrp	x16, 0x8f000
   85b34:      	ldr	x17, [x16, #0x638]
   85b38:      	add	x16, x16, #0x638
   85b3c:      	br	x17

0000000000085b40 <File_Write@plt>:
   85b40:      	adrp	x16, 0x8f000
   85b44:      	ldr	x17, [x16, #0x640]
   85b48:      	add	x16, x16, #0x640
   85b4c:      	br	x17

0000000000085b50 <fwrite@plt>:
   85b50:      	adrp	x16, 0x8f000
   85b54:      	ldr	x17, [x16, #0x648]
   85b58:      	add	x16, x16, #0x648
   85b5c:      	br	x17

0000000000085b60 <File_Seek@plt>:
   85b60:      	adrp	x16, 0x8f000
   85b64:      	ldr	x17, [x16, #0x650]
   85b68:      	add	x16, x16, #0x650
   85b6c:      	br	x17

0000000000085b70 <fseek@plt>:
   85b70:      	adrp	x16, 0x8f000
   85b74:      	ldr	x17, [x16, #0x658]
   85b78:      	add	x16, x16, #0x658
   85b7c:      	br	x17

0000000000085b80 <ftell@plt>:
   85b80:      	adrp	x16, 0x8f000
   85b84:      	ldr	x17, [x16, #0x660]
   85b88:      	add	x16, x16, #0x660
   85b8c:      	br	x17

0000000000085b90 <SeqInStream_Read2@plt>:
   85b90:      	adrp	x16, 0x8f000
   85b94:      	ldr	x17, [x16, #0x668]
   85b98:      	add	x16, x16, #0x668
   85b9c:      	br	x17

0000000000085ba0 <SeqInStream_Read@plt>:
   85ba0:      	adrp	x16, 0x8f000
   85ba4:      	ldr	x17, [x16, #0x670]
   85ba8:      	add	x16, x16, #0x670
   85bac:      	br	x17

0000000000085bb0 <SeqInStream_ReadByte@plt>:
   85bb0:      	adrp	x16, 0x8f000
   85bb4:      	ldr	x17, [x16, #0x678]
   85bb8:      	add	x16, x16, #0x678
   85bbc:      	br	x17

0000000000085bc0 <LookInStream_LookRead@plt>:
   85bc0:      	adrp	x16, 0x8f000
   85bc4:      	ldr	x17, [x16, #0x680]
   85bc8:      	add	x16, x16, #0x680
   85bcc:      	br	x17

0000000000085bd0 <SecToRead_CreateVTable@plt>:
   85bd0:      	adrp	x16, 0x8f000
   85bd4:      	ldr	x17, [x16, #0x688]
   85bd8:      	add	x16, x16, #0x688
   85bdc:      	br	x17

0000000000085be0 <AesCbc_Encode@plt>:
   85be0:      	adrp	x16, 0x8f000
   85be4:      	ldr	x17, [x16, #0x690]
   85be8:      	add	x16, x16, #0x690
   85bec:      	br	x17

0000000000085bf0 <AesCbc_Decode@plt>:
   85bf0:      	adrp	x16, 0x8f000
   85bf4:      	ldr	x17, [x16, #0x698]
   85bf8:      	add	x16, x16, #0x698
   85bfc:      	br	x17

0000000000085c00 <AesCtr_Code@plt>:
   85c00:      	adrp	x16, 0x8f000
   85c04:      	ldr	x17, [x16, #0x6a0]
   85c08:      	add	x16, x16, #0x6a0
   85c0c:      	br	x17

0000000000085c10 <Aes_SetKey_Enc@plt>:
   85c10:      	adrp	x16, 0x8f000
   85c14:      	ldr	x17, [x16, #0x6a8]
   85c18:      	add	x16, x16, #0x6a8
   85c1c:      	br	x17

0000000000085c20 <MyAlloc@plt>:
   85c20:      	adrp	x16, 0x8f000
   85c24:      	ldr	x17, [x16, #0x6b0]
   85c28:      	add	x16, x16, #0x6b0
   85c2c:      	br	x17

0000000000085c30 <MyFree@plt>:
   85c30:      	adrp	x16, 0x8f000
   85c34:      	ldr	x17, [x16, #0x6b8]
   85c38:      	add	x16, x16, #0x6b8
   85c3c:      	br	x17

0000000000085c40 <AlignOffsetAlloc_CreateVTable@plt>:
   85c40:      	adrp	x16, 0x8f000
   85c44:      	ldr	x17, [x16, #0x6c0]
   85c48:      	add	x16, x16, #0x6c0
   85c4c:      	br	x17

0000000000085c50 <Delta_Encode@plt>:
   85c50:      	adrp	x16, 0x8f000
   85c54:      	ldr	x17, [x16, #0x6c8]
   85c58:      	add	x16, x16, #0x6c8
   85c5c:      	br	x17

0000000000085c60 <MatchFinder_ReduceOffsets@plt>:
   85c60:      	adrp	x16, 0x8f000
   85c64:      	ldr	x17, [x16, #0x6d0]
   85c68:      	add	x16, x16, #0x6d0
   85c6c:      	br	x17

0000000000085c70 <MatchFinder_MoveBlock@plt>:
   85c70:      	adrp	x16, 0x8f000
   85c74:      	ldr	x17, [x16, #0x6d8]
   85c78:      	add	x16, x16, #0x6d8
   85c7c:      	br	x17

0000000000085c80 <memmove@plt>:
   85c80:      	adrp	x16, 0x8f000
   85c84:      	ldr	x17, [x16, #0x6e0]
   85c88:      	add	x16, x16, #0x6e0
   85c8c:      	br	x17

0000000000085c90 <MatchFinder_NeedMove@plt>:
   85c90:      	adrp	x16, 0x8f000
   85c94:      	ldr	x17, [x16, #0x6e8]
   85c98:      	add	x16, x16, #0x6e8
   85c9c:      	br	x17

0000000000085ca0 <MatchFinder_Construct@plt>:
   85ca0:      	adrp	x16, 0x8f000
   85ca4:      	ldr	x17, [x16, #0x6f0]
   85ca8:      	add	x16, x16, #0x6f0
   85cac:      	br	x17

0000000000085cb0 <MatchFinder_Free@plt>:
   85cb0:      	adrp	x16, 0x8f000
   85cb4:      	ldr	x17, [x16, #0x6f8]
   85cb8:      	add	x16, x16, #0x6f8
   85cbc:      	br	x17

0000000000085cc0 <MatchFinder_Create@plt>:
   85cc0:      	adrp	x16, 0x8f000
   85cc4:      	ldr	x17, [x16, #0x700]
   85cc8:      	add	x16, x16, #0x700
   85ccc:      	br	x17

0000000000085cd0 <MatchFinder_Init_LowHash@plt>:
   85cd0:      	adrp	x16, 0x8f000
   85cd4:      	ldr	x17, [x16, #0x708]
   85cd8:      	add	x16, x16, #0x708
   85cdc:      	br	x17

0000000000085ce0 <MatchFinder_Init_HighHash@plt>:
   85ce0:      	adrp	x16, 0x8f000
   85ce4:      	ldr	x17, [x16, #0x710]
   85ce8:      	add	x16, x16, #0x710
   85cec:      	br	x17

0000000000085cf0 <MatchFinder_Init_3@plt>:
   85cf0:      	adrp	x16, 0x8f000
   85cf4:      	ldr	x17, [x16, #0x718]
   85cf8:      	add	x16, x16, #0x718
   85cfc:      	br	x17

0000000000085d00 <MatchFinder_Normalize3@plt>:
   85d00:      	adrp	x16, 0x8f000
   85d04:      	ldr	x17, [x16, #0x720]
   85d08:      	add	x16, x16, #0x720
   85d0c:      	br	x17

0000000000085d10 <GetMatchesSpec1@plt>:
   85d10:      	adrp	x16, 0x8f000
   85d14:      	ldr	x17, [x16, #0x728]
   85d18:      	add	x16, x16, #0x728
   85d1c:      	br	x17

0000000000085d20 <MatchFinder_CreateVTable@plt>:
   85d20:      	adrp	x16, 0x8f000
   85d24:      	ldr	x17, [x16, #0x730]
   85d28:      	add	x16, x16, #0x730
   85d2c:      	br	x17

0000000000085d30 <Lzma2Dec_Allocate@plt>:
   85d30:      	adrp	x16, 0x8f000
   85d34:      	ldr	x17, [x16, #0x738]
   85d38:      	add	x16, x16, #0x738
   85d3c:      	br	x17

0000000000085d40 <LzmaDec_Allocate@plt>:
   85d40:      	adrp	x16, 0x8f000
   85d44:      	ldr	x17, [x16, #0x740]
   85d48:      	add	x16, x16, #0x740
   85d4c:      	br	x17

0000000000085d50 <LzmaDec_InitDicAndState@plt>:
   85d50:      	adrp	x16, 0x8f000
   85d54:      	ldr	x17, [x16, #0x748]
   85d58:      	add	x16, x16, #0x748
   85d5c:      	br	x17

0000000000085d60 <Lzma2Dec_DecodeToBuf@plt>:
   85d60:      	adrp	x16, 0x8f000
   85d64:      	ldr	x17, [x16, #0x750]
   85d68:      	add	x16, x16, #0x750
   85d6c:      	br	x17

0000000000085d70 <Lzma2EncProps_Init@plt>:
   85d70:      	adrp	x16, 0x8f000
   85d74:      	ldr	x17, [x16, #0x758]
   85d78:      	add	x16, x16, #0x758
   85d7c:      	br	x17

0000000000085d80 <LzmaEncProps_Init@plt>:
   85d80:      	adrp	x16, 0x8f000
   85d84:      	ldr	x17, [x16, #0x760]
   85d88:      	add	x16, x16, #0x760
   85d8c:      	br	x17

0000000000085d90 <Lzma2EncProps_Normalize@plt>:
   85d90:      	adrp	x16, 0x8f000
   85d94:      	ldr	x17, [x16, #0x768]
   85d98:      	add	x16, x16, #0x768
   85d9c:      	br	x17

0000000000085da0 <LzmaEncProps_Normalize@plt>:
   85da0:      	adrp	x16, 0x8f000
   85da4:      	ldr	x17, [x16, #0x770]
   85da8:      	add	x16, x16, #0x770
   85dac:      	br	x17

0000000000085db0 <Lzma2Enc_Create@plt>:
   85db0:      	adrp	x16, 0x8f000
   85db4:      	ldr	x17, [x16, #0x778]
   85db8:      	add	x16, x16, #0x778
   85dbc:      	br	x17

0000000000085dc0 <Lzma2Enc_Destroy@plt>:
   85dc0:      	adrp	x16, 0x8f000
   85dc4:      	ldr	x17, [x16, #0x780]
   85dc8:      	add	x16, x16, #0x780
   85dcc:      	br	x17

0000000000085dd0 <LzmaEnc_Destroy@plt>:
   85dd0:      	adrp	x16, 0x8f000
   85dd4:      	ldr	x17, [x16, #0x788]
   85dd8:      	add	x16, x16, #0x788
   85ddc:      	br	x17

0000000000085de0 <Lzma2Enc_SetProps@plt>:
   85de0:      	adrp	x16, 0x8f000
   85de4:      	ldr	x17, [x16, #0x790]
   85de8:      	add	x16, x16, #0x790
   85dec:      	br	x17

0000000000085df0 <Lzma2Enc_WriteProperties@plt>:
   85df0:      	adrp	x16, 0x8f000
   85df4:      	ldr	x17, [x16, #0x798]
   85df8:      	add	x16, x16, #0x798
   85dfc:      	br	x17

0000000000085e00 <LzmaEncProps_GetDictSize@plt>:
   85e00:      	adrp	x16, 0x8f000
   85e04:      	ldr	x17, [x16, #0x7a0]
   85e08:      	add	x16, x16, #0x7a0
   85e0c:      	br	x17

0000000000085e10 <Lzma2Enc_Encode2@plt>:
   85e10:      	adrp	x16, 0x8f000
   85e14:      	ldr	x17, [x16, #0x7a8]
   85e18:      	add	x16, x16, #0x7a8
   85e1c:      	br	x17

0000000000085e20 <LzmaEnc_Create@plt>:
   85e20:      	adrp	x16, 0x8f000
   85e24:      	ldr	x17, [x16, #0x7b0]
   85e28:      	add	x16, x16, #0x7b0
   85e2c:      	br	x17

0000000000085e30 <LzmaEnc_SetDataSize@plt>:
   85e30:      	adrp	x16, 0x8f000
   85e34:      	ldr	x17, [x16, #0x7b8]
   85e38:      	add	x16, x16, #0x7b8
   85e3c:      	br	x17

0000000000085e40 <LzmaEnc_PrepareForLzma2@plt>:
   85e40:      	adrp	x16, 0x8f000
   85e44:      	ldr	x17, [x16, #0x7c0]
   85e48:      	add	x16, x16, #0x7c0
   85e4c:      	br	x17

0000000000085e50 <LzmaEnc_MemPrepare@plt>:
   85e50:      	adrp	x16, 0x8f000
   85e54:      	ldr	x17, [x16, #0x7c8]
   85e58:      	add	x16, x16, #0x7c8
   85e5c:      	br	x17

0000000000085e60 <LzmaEnc_SaveState@plt>:
   85e60:      	adrp	x16, 0x8f000
   85e64:      	ldr	x17, [x16, #0x7d0]
   85e68:      	add	x16, x16, #0x7d0
   85e6c:      	br	x17

0000000000085e70 <LzmaEnc_CodeOneMemBlock@plt>:
   85e70:      	adrp	x16, 0x8f000
   85e74:      	ldr	x17, [x16, #0x7d8]
   85e78:      	add	x16, x16, #0x7d8
   85e7c:      	br	x17

0000000000085e80 <LzmaEnc_GetCurBuf@plt>:
   85e80:      	adrp	x16, 0x8f000
   85e84:      	ldr	x17, [x16, #0x7e0]
   85e88:      	add	x16, x16, #0x7e0
   85e8c:      	br	x17

0000000000085e90 <LzmaEnc_RestoreState@plt>:
   85e90:      	adrp	x16, 0x8f000
   85e94:      	ldr	x17, [x16, #0x7e8]
   85e98:      	add	x16, x16, #0x7e8
   85e9c:      	br	x17

0000000000085ea0 <LzmaEnc_Finish@plt>:
   85ea0:      	adrp	x16, 0x8f000
   85ea4:      	ldr	x17, [x16, #0x7f0]
   85ea8:      	add	x16, x16, #0x7f0
   85eac:      	br	x17

0000000000085eb0 <LzmaEnc_SetProps@plt>:
   85eb0:      	adrp	x16, 0x8f000
   85eb4:      	ldr	x17, [x16, #0x7f8]
   85eb8:      	add	x16, x16, #0x7f8
   85ebc:      	br	x17

0000000000085ec0 <LzmaEnc_WriteProperties@plt>:
   85ec0:      	adrp	x16, 0x8f000
   85ec4:      	ldr	x17, [x16, #0x800]
   85ec8:      	add	x16, x16, #0x800
   85ecc:      	br	x17

0000000000085ed0 <LzmaDecode@plt>:
   85ed0:      	adrp	x16, 0x8f000
   85ed4:      	ldr	x17, [x16, #0x808]
   85ed8:      	add	x16, x16, #0x808
   85edc:      	br	x17

0000000000085ee0 <LzmaEncode@plt>:
   85ee0:      	adrp	x16, 0x8f000
   85ee4:      	ldr	x17, [x16, #0x810]
   85ee8:      	add	x16, x16, #0x810
   85eec:      	br	x17

0000000000085ef0 <LzmaDec_Free@plt>:
   85ef0:      	adrp	x16, 0x8f000
   85ef4:      	ldr	x17, [x16, #0x818]
   85ef8:      	add	x16, x16, #0x818
   85efc:      	br	x17

0000000000085f00 <LzmaProps_Decode@plt>:
   85f00:      	adrp	x16, 0x8f000
   85f04:      	ldr	x17, [x16, #0x820]
   85f08:      	add	x16, x16, #0x820
   85f0c:      	br	x17

0000000000085f10 <LzmaEnc_Construct@plt>:
   85f10:      	adrp	x16, 0x8f000
   85f14:      	ldr	x17, [x16, #0x828]
   85f18:      	add	x16, x16, #0x828
   85f1c:      	br	x17

0000000000085f20 <LzmaEnc_FreeLits@plt>:
   85f20:      	adrp	x16, 0x8f000
   85f24:      	ldr	x17, [x16, #0x830]
   85f28:      	add	x16, x16, #0x830
   85f2c:      	br	x17

0000000000085f30 <LzmaEnc_Destruct@plt>:
   85f30:      	adrp	x16, 0x8f000
   85f34:      	ldr	x17, [x16, #0x838]
   85f38:      	add	x16, x16, #0x838
   85f3c:      	br	x17

0000000000085f40 <LzmaEnc_Init@plt>:
   85f40:      	adrp	x16, 0x8f000
   85f44:      	ldr	x17, [x16, #0x840]
   85f48:      	add	x16, x16, #0x840
   85f4c:      	br	x17

0000000000085f50 <LzmaEnc_InitPrices@plt>:
   85f50:      	adrp	x16, 0x8f000
   85f54:      	ldr	x17, [x16, #0x848]
   85f58:      	add	x16, x16, #0x848
   85f5c:      	br	x17

0000000000085f60 <LzmaEnc_MemEncode@plt>:
   85f60:      	adrp	x16, 0x8f000
   85f64:      	ldr	x17, [x16, #0x850]
   85f68:      	add	x16, x16, #0x850
   85f6c:      	br	x17

0000000000085f70 <Ppmd7_MakeEscFreq@plt>:
   85f70:      	adrp	x16, 0x8f000
   85f74:      	ldr	x17, [x16, #0x858]
   85f78:      	add	x16, x16, #0x858
   85f7c:      	br	x17

0000000000085f80 <Ppmd7_Update1@plt>:
   85f80:      	adrp	x16, 0x8f000
   85f84:      	ldr	x17, [x16, #0x860]
   85f88:      	add	x16, x16, #0x860
   85f8c:      	br	x17

0000000000085f90 <Ppmd7_Update1_0@plt>:
   85f90:      	adrp	x16, 0x8f000
   85f94:      	ldr	x17, [x16, #0x868]
   85f98:      	add	x16, x16, #0x868
   85f9c:      	br	x17

0000000000085fa0 <Ppmd7_UpdateBin@plt>:
   85fa0:      	adrp	x16, 0x8f000
   85fa4:      	ldr	x17, [x16, #0x870]
   85fa8:      	add	x16, x16, #0x870
   85fac:      	br	x17

0000000000085fb0 <Ppmd7_Update2@plt>:
   85fb0:      	adrp	x16, 0x8f000
   85fb4:      	ldr	x17, [x16, #0x878]
   85fb8:      	add	x16, x16, #0x878
   85fbc:      	br	x17

0000000000085fc0 <Sha256_Init@plt>:
   85fc0:      	adrp	x16, 0x8f000
   85fc4:      	ldr	x17, [x16, #0x880]
   85fc8:      	add	x16, x16, #0x880
   85fcc:      	br	x17

0000000000085fd0 <Sha256_Update@plt>:
   85fd0:      	adrp	x16, 0x8f000
   85fd4:      	ldr	x17, [x16, #0x888]
   85fd8:      	add	x16, x16, #0x888
   85fdc:      	br	x17

0000000000085fe0 <Sha256_Final@plt>:
   85fe0:      	adrp	x16, 0x8f000
   85fe4:      	ldr	x17, [x16, #0x890]
   85fe8:      	add	x16, x16, #0x890
   85fec:      	br	x17

0000000000085ff0 <Xz_WriteVarInt@plt>:
   85ff0:      	adrp	x16, 0x8f000
   85ff4:      	ldr	x17, [x16, #0x898]
   85ff8:      	add	x16, x16, #0x898
   85ffc:      	br	x17

0000000000086000 <Xz_Construct@plt>:
   86000:      	adrp	x16, 0x8f000
   86004:      	ldr	x17, [x16, #0x8a0]
   86008:      	add	x16, x16, #0x8a0
   8600c:      	br	x17

0000000000086010 <Xz_Free@plt>:
   86010:      	adrp	x16, 0x8f000
   86014:      	ldr	x17, [x16, #0x8a8]
   86018:      	add	x16, x16, #0x8a8
   8601c:      	br	x17

0000000000086020 <XzFlags_GetCheckSize@plt>:
   86020:      	adrp	x16, 0x8f000
   86024:      	ldr	x17, [x16, #0x8b0]
   86028:      	add	x16, x16, #0x8b0
   8602c:      	br	x17

0000000000086030 <XzCheck_Init@plt>:
   86030:      	adrp	x16, 0x8f000
   86034:      	ldr	x17, [x16, #0x8b8]
   86038:      	add	x16, x16, #0x8b8
   8603c:      	br	x17

0000000000086040 <XzCheck_Update@plt>:
   86040:      	adrp	x16, 0x8f000
   86044:      	ldr	x17, [x16, #0x8c0]
   86048:      	add	x16, x16, #0x8c0
   8604c:      	br	x17

0000000000086050 <Crc64Update@plt>:
   86050:      	adrp	x16, 0x8f000
   86054:      	ldr	x17, [x16, #0x8c8]
   86058:      	add	x16, x16, #0x8c8
   8605c:      	br	x17

0000000000086060 <XzCheck_Final@plt>:
   86060:      	adrp	x16, 0x8f000
   86064:      	ldr	x17, [x16, #0x8d0]
   86068:      	add	x16, x16, #0x8d0
   8606c:      	br	x17

0000000000086070 <XzCrc64UpdateT4@plt>:
   86070:      	adrp	x16, 0x8f000
   86074:      	ldr	x17, [x16, #0x8d8]
   86078:      	add	x16, x16, #0x8d8
   8607c:      	br	x17

0000000000086080 <Xz_ReadVarInt@plt>:
   86080:      	adrp	x16, 0x8f000
   86084:      	ldr	x17, [x16, #0x8e0]
   86088:      	add	x16, x16, #0x8e0
   8608c:      	br	x17

0000000000086090 <BraState_SetFromMethod@plt>:
   86090:      	adrp	x16, 0x8f000
   86094:      	ldr	x17, [x16, #0x8e8]
   86098:      	add	x16, x16, #0x8e8
   8609c:      	br	x17

00000000000860a0 <Xz_ParseHeader@plt>:
   860a0:      	adrp	x16, 0x8f000
   860a4:      	ldr	x17, [x16, #0x8f0]
   860a8:      	add	x16, x16, #0x8f0
   860ac:      	br	x17

00000000000860b0 <XzBlock_Parse@plt>:
   860b0:      	adrp	x16, 0x8f000
   860b4:      	ldr	x17, [x16, #0x8f8]
   860b8:      	add	x16, x16, #0x8f8
   860bc:      	br	x17

00000000000860c0 <memcmp@plt>:
   860c0:      	adrp	x16, 0x8f000
   860c4:      	ldr	x17, [x16, #0x900]
   860c8:      	add	x16, x16, #0x900
   860cc:      	br	x17

00000000000860d0 <XzUnpacker_GetExtraSize@plt>:
   860d0:      	adrp	x16, 0x8f000
   860d4:      	ldr	x17, [x16, #0x908]
   860d8:      	add	x16, x16, #0x908
   860dc:      	br	x17

00000000000860e0 <XzProps_Init@plt>:
   860e0:      	adrp	x16, 0x8f000
   860e4:      	ldr	x17, [x16, #0x910]
   860e8:      	add	x16, x16, #0x910
   860ec:      	br	x17

00000000000860f0 <XzEnc_Create@plt>:
   860f0:      	adrp	x16, 0x8f000
   860f4:      	ldr	x17, [x16, #0x918]
   860f8:      	add	x16, x16, #0x918
   860fc:      	br	x17

0000000000086100 <XzEnc_Destroy@plt>:
   86100:      	adrp	x16, 0x8f000
   86104:      	ldr	x17, [x16, #0x920]
   86108:      	add	x16, x16, #0x920
   8610c:      	br	x17

0000000000086110 <XzEnc_Encode@plt>:
   86110:      	adrp	x16, 0x8f000
   86114:      	ldr	x17, [x16, #0x928]
   86118:      	add	x16, x16, #0x928
   8611c:      	br	x17

0000000000086120 <Xz_ReadHeader@plt>:
   86120:      	adrp	x16, 0x8f000
   86124:      	ldr	x17, [x16, #0x930]
   86128:      	add	x16, x16, #0x930
   8612c:      	br	x17

0000000000086130 <Xz_GetUnpackSize@plt>:
   86130:      	adrp	x16, 0x8f000
   86134:      	ldr	x17, [x16, #0x938]
   86138:      	add	x16, x16, #0x938
   8613c:      	br	x17

0000000000086140 <Xz_GetPackSize@plt>:
   86140:      	adrp	x16, 0x8f000
   86144:      	ldr	x17, [x16, #0x940]
   86148:      	add	x16, x16, #0x940
   8614c:      	br	x17

0000000000086150 <strrchr@plt>:
   86150:      	adrp	x16, 0x8f000
   86154:      	ldr	x17, [x16, #0x948]
   86158:      	add	x16, x16, #0x948
   8615c:      	br	x17

0000000000086160 <process_vm_readv@plt>:
   86160:      	adrp	x16, 0x8f000
   86164:      	ldr	x17, [x16, #0x950]
   86168:      	add	x16, x16, #0x950
   8616c:      	br	x17

0000000000086170 <process_vm_writev@plt>:
   86170:      	adrp	x16, 0x8f000
   86174:      	ldr	x17, [x16, #0x958]
   86178:      	add	x16, x16, #0x958
   8617c:      	br	x17

0000000000086180 <kwai_set_abort_message@plt>:
   86180:      	adrp	x16, 0x8f000
   86184:      	ldr	x17, [x16, #0x960]
   86188:      	add	x16, x16, #0x960
   8618c:      	br	x17

0000000000086190 <android_set_abort_message@plt>:
   86190:      	adrp	x16, 0x8f000
   86194:      	ldr	x17, [x16, #0x968]
   86198:      	add	x16, x16, #0x968
   8619c:      	br	x17

00000000000861a0 <kwai_getprogname@plt>:
   861a0:      	adrp	x16, 0x8f000
   861a4:      	ldr	x17, [x16, #0x970]
   861a8:      	add	x16, x16, #0x970
   861ac:      	br	x17

00000000000861b0 <getprogname@plt>:
   861b0:      	adrp	x16, 0x8f000
   861b4:      	ldr	x17, [x16, #0x978]
   861b8:      	add	x16, x16, #0x978
   861bc:      	br	x17

00000000000861c0 <__system_property_read_callback@plt>:
   861c0:      	adrp	x16, 0x8f000
   861c4:      	ldr	x17, [x16, #0x980]
   861c8:      	add	x16, x16, #0x980
   861cc:      	br	x17

00000000000861d0 <strncmp@plt>:
   861d0:      	adrp	x16, 0x8f000
   861d4:      	ldr	x17, [x16, #0x988]
   861d8:      	add	x16, x16, #0x988
   861dc:      	br	x17

00000000000861e0 <__system_property_wait@plt>:
   861e0:      	adrp	x16, 0x8f000
   861e4:      	ldr	x17, [x16, #0x990]
   861e8:      	add	x16, x16, #0x990
   861ec:      	br	x17

00000000000861f0 <kwai__system_property_area_serial@plt>:
   861f0:      	adrp	x16, 0x8f000
   861f4:      	ldr	x17, [x16, #0x998]
   861f8:      	add	x16, x16, #0x998
   861fc:      	br	x17

0000000000086200 <__system_property_area_serial@plt>:
   86200:      	adrp	x16, 0x8f000
   86204:      	ldr	x17, [x16, #0x9a0]
   86208:      	add	x16, x16, #0x9a0
   8620c:      	br	x17

0000000000086210 <kwai__system_property_serial@plt>:
   86210:      	adrp	x16, 0x8f000
   86214:      	ldr	x17, [x16, #0x9a8]
   86218:      	add	x16, x16, #0x9a8
   8621c:      	br	x17

0000000000086220 <__system_property_serial@plt>:
   86220:      	adrp	x16, 0x8f000
   86224:      	ldr	x17, [x16, #0x9b0]
   86228:      	add	x16, x16, #0x9b0
   8622c:      	br	x17

0000000000086230 <syscall@plt>:
   86230:      	adrp	x16, 0x8f000
   86234:      	ldr	x17, [x16, #0x9b8]
   86238:      	add	x16, x16, #0x9b8
   8623c:      	br	x17

0000000000086240 <__android_log_assert@plt>:
   86240:      	adrp	x16, 0x8f000
   86244:      	ldr	x17, [x16, #0x9c0]
   86248:      	add	x16, x16, #0x9c0
   8624c:      	br	x17

0000000000086250 <async_safe_format_buffer_va_list@plt>:
   86250:      	adrp	x16, 0x8f000
   86254:      	ldr	x17, [x16, #0x9c8]
   86258:      	add	x16, x16, #0x9c8
   8625c:      	br	x17

0000000000086260 <_ZN18BufferOutputStream4SendEPKci@plt>:
   86260:      	adrp	x16, 0x8f000
   86264:      	ldr	x17, [x16, #0x9d0]
   86268:      	add	x16, x16, #0x9d0
   8626c:      	br	x17

0000000000086270 <async_safe_format_fd_va_list@plt>:
   86270:      	adrp	x16, 0x8f000
   86274:      	ldr	x17, [x16, #0x9d8]
   86278:      	add	x16, x16, #0x9d8
   8627c:      	br	x17

0000000000086280 <_ZN14FdOutputStream4SendEPKci@plt>:
   86280:      	adrp	x16, 0x8f000
   86284:      	ldr	x17, [x16, #0x9e0]
   86288:      	add	x16, x16, #0x9e0
   8628c:      	br	x17

0000000000086290 <async_safe_write_log@plt>:
   86290:      	adrp	x16, 0x8f000
   86294:      	ldr	x17, [x16, #0x9e8]
   86298:      	add	x16, x16, #0x9e8
   8629c:      	br	x17

00000000000862a0 <__strlcpy_chk@plt>:
   862a0:      	adrp	x16, 0x8f000
   862a4:      	ldr	x17, [x16, #0x9f0]
   862a8:      	add	x16, x16, #0x9f0
   862ac:      	br	x17

00000000000862b0 <connect@plt>:
   862b0:      	adrp	x16, 0x8f000
   862b4:      	ldr	x17, [x16, #0x9f8]
   862b8:      	add	x16, x16, #0x9f8
   862bc:      	br	x17

00000000000862c0 <gettid@plt>:
   862c0:      	adrp	x16, 0x8f000
   862c4:      	ldr	x17, [x16, #0xa00]
   862c8:      	add	x16, x16, #0xa00
   862cc:      	br	x17

00000000000862d0 <clock_gettime@plt>:
   862d0:      	adrp	x16, 0x8f000
   862d4:      	ldr	x17, [x16, #0xa08]
   862d8:      	add	x16, x16, #0xa08
   862dc:      	br	x17

00000000000862e0 <writev@plt>:
   862e0:      	adrp	x16, 0x8f000
   862e4:      	ldr	x17, [x16, #0xa10]
   862e8:      	add	x16, x16, #0xa10
   862ec:      	br	x17

00000000000862f0 <__android_log_write@plt>:
   862f0:      	adrp	x16, 0x8f000
   862f4:      	ldr	x17, [x16, #0xa18]
   862f8:      	add	x16, x16, #0xa18
   862fc:      	br	x17

0000000000086300 <async_safe_format_log_va_list@plt>:
   86300:      	adrp	x16, 0x8f000
   86304:      	ldr	x17, [x16, #0xa20]
   86308:      	add	x16, x16, #0xa20
   8630c:      	br	x17

0000000000086310 <async_safe_fatal_va_list@plt>:
   86310:      	adrp	x16, 0x8f000
   86314:      	ldr	x17, [x16, #0xa28]
   86318:      	add	x16, x16, #0xa28
   8631c:      	br	x17

0000000000086320 <__write_chk@plt>:
   86320:      	adrp	x16, 0x8f000
   86324:      	ldr	x17, [x16, #0xa30]
   86328:      	add	x16, x16, #0xa30
   8632c:      	br	x17

0000000000086330 <__assert@plt>:
   86330:      	adrp	x16, 0x8f000
   86334:      	ldr	x17, [x16, #0xa38]
   86338:      	add	x16, x16, #0xa38
   8633c:      	br	x17

0000000000086340 <_ZN11EventTagMap13emplaceUniqueEjRKNSt6__ndk14pairINS0_17basic_string_viewIcNS0_11char_traitsIcEEEES5_EEb@plt>:
   86340:      	adrp	x16, 0x8f000
   86344:      	ldr	x17, [x16, #0xa40]
   86348:      	add	x16, x16, #0xa40
   8634c:      	br	x17

0000000000086350 <_ZN7android6RWLock9writeLockEv@plt>:
   86350:      	adrp	x16, 0x8f000
   86354:      	ldr	x17, [x16, #0xa48]
   86358:      	add	x16, x16, #0xa48
   8635c:      	br	x17

0000000000086360 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE4findIjEENS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEERKT_@plt>:
   86360:      	adrp	x16, 0x8f000
   86364:      	ldr	x17, [x16, #0xa50]
   86368:      	add	x16, x16, #0xa50
   8636c:      	br	x17

0000000000086370 <fprintf@plt>:
   86370:      	adrp	x16, 0x8f000
   86374:      	ldr	x17, [x16, #0xa58]
   86378:      	add	x16, x16, #0xa58
   8637c:      	br	x17

0000000000086380 <_ZNSt6__ndk113unordered_mapIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES5_EENS_4hashIjEENS_8equal_toIjEENS_9allocatorINS1_IKjS6_EEEEE7emplaceB8ne180000IJNS1_IjS6_EEEEENS1_INS_19__hash_map_iteratorINS_15__hash_iteratorIPNS_11__hash_nodeINS_17__hash_value_typeIjS6_EEPvEEEEEEbEEDpOT_@plt>:
   86380:      	adrp	x16, 0x8f000
   86384:      	ldr	x17, [x16, #0xa60]
   86388:      	add	x16, x16, #0xa60
   8638c:      	br	x17

0000000000086390 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE4findIS5_EENS_15__hash_iteratorIPNS_11__hash_nodeIS6_PvEEEERKT_@plt>:
   86390:      	adrp	x16, 0x8f000
   86394:      	ldr	x17, [x16, #0xa68]
   86398:      	add	x16, x16, #0xa68
   8639c:      	br	x17

00000000000863a0 <_ZNSt6__ndk113unordered_mapINS_17basic_string_viewIcNS_11char_traitsIcEEEEjNS_4hashIS4_EENS_8equal_toIS4_EENS_9allocatorINS_4pairIKS4_jEEEEE7emplaceB8ne180000IJNSA_IS4_jEEEEENSA_INS_19__hash_map_iteratorINS_15__hash_iteratorIPNS_11__hash_nodeINS_17__hash_value_typeIS4_jEEPvEEEEEEbEEDpOT_@plt>:
   863a0:      	adrp	x16, 0x8f000
   863a4:      	ldr	x17, [x16, #0xa70]
   863a8:      	add	x16, x16, #0xa70
   863ac:      	br	x17

00000000000863b0 <_ZN7android6RWLock9AutoWLockD2Ev@plt>:
   863b0:      	adrp	x16, 0x8f000
   863b4:      	ldr	x17, [x16, #0xa78]
   863b8:      	add	x16, x16, #0xa78
   863bc:      	br	x17

00000000000863c0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE16__emplace_uniqueB8ne180000INS2_IjS7_EEEENS2_INS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEEOT_@plt>:
   863c0:      	adrp	x16, 0x8f000
   863c4:      	ldr	x17, [x16, #0xa80]
   863c8:      	add	x16, x16, #0xa80
   863cc:      	br	x17

00000000000863d0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE16__emplace_uniqueB8ne180000INS_4pairIS5_jEEEENSJ_INS_15__hash_iteratorIPNS_11__hash_nodeIS6_PvEEEEbEEOT_@plt>:
   863d0:      	adrp	x16, 0x8f000
   863d4:      	ldr	x17, [x16, #0xa88]
   863d8:      	add	x16, x16, #0xa88
   863dc:      	br	x17

00000000000863e0 <pthread_rwlock_unlock@plt>:
   863e0:      	adrp	x16, 0x8f000
   863e4:      	ldr	x17, [x16, #0xa90]
   863e8:      	add	x16, x16, #0xa90
   863ec:      	br	x17

00000000000863f0 <_ZNK11EventTagMap4findEj@plt>:
   863f0:      	adrp	x16, 0x8f000
   863f4:      	ldr	x17, [x16, #0xa98]
   863f8:      	add	x16, x16, #0xa98
   863fc:      	br	x17

0000000000086400 <_ZN7android6RWLock8readLockEv@plt>:
   86400:      	adrp	x16, 0x8f000
   86404:      	ldr	x17, [x16, #0xaa0]
   86408:      	add	x16, x16, #0xaa0
   8640c:      	br	x17

0000000000086410 <_ZNKSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE4findIjEENS_21__hash_const_iteratorIPNS_11__hash_nodeIS8_PvEEEERKT_@plt>:
   86410:      	adrp	x16, 0x8f000
   86414:      	ldr	x17, [x16, #0xaa8]
   86418:      	add	x16, x16, #0xaa8
   8641c:      	br	x17

0000000000086420 <_ZN7android6RWLock9AutoRLockD2Ev@plt>:
   86420:      	adrp	x16, 0x8f000
   86424:      	ldr	x17, [x16, #0xab0]
   86428:      	add	x16, x16, #0xab0
   8642c:      	br	x17

0000000000086430 <_ZNKSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE4findIS5_EENS_21__hash_const_iteratorIPNS_11__hash_nodeIS6_PvEEEERKT_@plt>:
   86430:      	adrp	x16, 0x8f000
   86434:      	ldr	x17, [x16, #0xab8]
   86438:      	add	x16, x16, #0xab8
   8643c:      	br	x17

0000000000086440 <_ZN11EventTagMapC2Ev@plt>:
   86440:      	adrp	x16, 0x8f000
   86444:      	ldr	x17, [x16, #0xac0]
   86448:      	add	x16, x16, #0xac0
   8644c:      	br	x17

0000000000086450 <strtoul@plt>:
   86450:      	adrp	x16, 0x8f000
   86454:      	ldr	x17, [x16, #0xac8]
   86458:      	add	x16, x16, #0xac8
   8645c:      	br	x17

0000000000086460 <__strchr_chk@plt>:
   86460:      	adrp	x16, 0x8f000
   86464:      	ldr	x17, [x16, #0xad0]
   86468:      	add	x16, x16, #0xad0
   8646c:      	br	x17

0000000000086470 <_ZN7android6RWLockC2Ev@plt>:
   86470:      	adrp	x16, 0x8f000
   86474:      	ldr	x17, [x16, #0xad8]
   86478:      	add	x16, x16, #0xad8
   8647c:      	br	x17

0000000000086480 <_ZN11EventTagMapD2Ev@plt>:
   86480:      	adrp	x16, 0x8f000
   86484:      	ldr	x17, [x16, #0xae0]
   86488:      	add	x16, x16, #0xae0
   8648c:      	br	x17

0000000000086490 <_ZN7android6RWLockD2Ev@plt>:
   86490:      	adrp	x16, 0x8f000
   86494:      	ldr	x17, [x16, #0xae8]
   86498:      	add	x16, x16, #0xae8
   8649c:      	br	x17

00000000000864a0 <android_lookupEventTag_len@plt>:
   864a0:      	adrp	x16, 0x8f000
   864a4:      	ldr	x17, [x16, #0xaf0]
   864a8:      	add	x16, x16, #0xaf0
   864ac:      	br	x17

00000000000864b0 <android_lookupEventFormat_len@plt>:
   864b0:      	adrp	x16, 0x8f000
   864b4:      	ldr	x17, [x16, #0xaf8]
   864b8:      	add	x16, x16, #0xaf8
   864bc:      	br	x17

00000000000864c0 <pthread_rwlock_wrlock@plt>:
   864c0:      	adrp	x16, 0x8f000
   864c4:      	ldr	x17, [x16, #0xb00]
   864c8:      	add	x16, x16, #0xb00
   864cc:      	br	x17

00000000000864d0 <pthread_rwlock_rdlock@plt>:
   864d0:      	adrp	x16, 0x8f000
   864d4:      	ldr	x17, [x16, #0xb08]
   864d8:      	add	x16, x16, #0xb08
   864dc:      	br	x17

00000000000864e0 <pthread_rwlock_init@plt>:
   864e0:      	adrp	x16, 0x8f000
   864e4:      	ldr	x17, [x16, #0xb10]
   864e8:      	add	x16, x16, #0xb10
   864ec:      	br	x17

00000000000864f0 <pthread_rwlock_destroy@plt>:
   864f0:      	adrp	x16, 0x8f000
   864f4:      	ldr	x17, [x16, #0xb18]
   864f8:      	add	x16, x16, #0xb18
   864fc:      	br	x17

0000000000086500 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE25__emplace_unique_key_argsIjJNS2_IjS7_EEEEENS2_INS_15__hash_iteratorIPNS_11__hash_nodeIS8_PvEEEEbEERKT_DpOT0_@plt>:
   86500:      	adrp	x16, 0x8f000
   86504:      	ldr	x17, [x16, #0xb20]
   86508:      	add	x16, x16, #0xb20
   8650c:      	br	x17

0000000000086510 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE21__construct_node_hashINS2_IjS7_EEJEEENS_10unique_ptrINS_11__hash_nodeIS8_PvEENS_22__hash_node_destructorINSH_ISP_EEEEEEmOT_DpOT0_@plt>:
   86510:      	adrp	x16, 0x8f000
   86514:      	ldr	x17, [x16, #0xb28]
   86518:      	add	x16, x16, #0xb28
   8651c:      	br	x17

0000000000086520 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE8__rehashILb1EEEvm@plt>:
   86520:      	adrp	x16, 0x8f000
   86524:      	ldr	x17, [x16, #0xb30]
   86528:      	add	x16, x16, #0xb30
   8652c:      	br	x17

0000000000086530 <_ZNSt6__ndk112__next_primeEm@plt>:
   86530:      	adrp	x16, 0x8f000
   86534:      	ldr	x17, [x16, #0xb38]
   86538:      	add	x16, x16, #0xb38
   8653c:      	br	x17

0000000000086540 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES6_EEEENS_22__unordered_map_hasherIjS8_NS_4hashIjEENS_8equal_toIjEELb1EEENS_21__unordered_map_equalIjS8_SD_SB_Lb1EEENS_9allocatorIS8_EEE11__do_rehashILb1EEEvm@plt>:
   86540:      	adrp	x16, 0x8f000
   86544:      	ldr	x17, [x16, #0xb40]
   86548:      	add	x16, x16, #0xb40
   8654c:      	br	x17

0000000000086550 <_ZNSt6__ndk110unique_ptrIA_PNS_16__hash_node_baseIPNS_11__hash_nodeINS_17__hash_value_typeIjNS_4pairINS_17basic_string_viewIcNS_11char_traitsIcEEEES8_EEEEPvEEEENS_25__bucket_list_deallocatorINS_9allocatorISF_EEEEE5resetB8ne180000IPSF_TnNS_9enable_ifIXsr28_CheckArrayPointerConversionIT_EE5valueEiE4typeELi0EEEvSP_@plt>:
   86550:      	adrp	x16, 0x8f000
   86554:      	ldr	x17, [x16, #0xb48]
   86558:      	add	x16, x16, #0xb48
   8655c:      	br	x17

0000000000086560 <_ZNKSt6__ndk117basic_string_viewIcNS_11char_traitsIcEEE7compareES3_@plt>:
   86560:      	adrp	x16, 0x8f000
   86564:      	ldr	x17, [x16, #0xb50]
   86568:      	add	x16, x16, #0xb50
   8656c:      	br	x17

0000000000086570 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE25__emplace_unique_key_argsIS5_JNS_4pairIS5_jEEEEENSJ_INS_15__hash_iteratorIPNS_11__hash_nodeIS6_PvEEEEbEERKT_DpOT0_@plt>:
   86570:      	adrp	x16, 0x8f000
   86574:      	ldr	x17, [x16, #0xb58]
   86578:      	add	x16, x16, #0xb58
   8657c:      	br	x17

0000000000086580 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE21__construct_node_hashINS_4pairIS5_jEEJEEENS_10unique_ptrINS_11__hash_nodeIS6_PvEENS_22__hash_node_destructorINSF_ISO_EEEEEEmOT_DpOT0_@plt>:
   86580:      	adrp	x16, 0x8f000
   86584:      	ldr	x17, [x16, #0xb60]
   86588:      	add	x16, x16, #0xb60
   8658c:      	br	x17

0000000000086590 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE8__rehashILb1EEEvm@plt>:
   86590:      	adrp	x16, 0x8f000
   86594:      	ldr	x17, [x16, #0xb68]
   86598:      	add	x16, x16, #0xb68
   8659c:      	br	x17

00000000000865a0 <_ZNSt6__ndk112__hash_tableINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEENS_22__unordered_map_hasherIS5_S6_NS_4hashIS5_EENS_8equal_toIS5_EELb1EEENS_21__unordered_map_equalIS5_S6_SB_S9_Lb1EEENS_9allocatorIS6_EEE11__do_rehashILb1EEEvm@plt>:
   865a0:      	adrp	x16, 0x8f000
   865a4:      	ldr	x17, [x16, #0xb70]
   865a8:      	add	x16, x16, #0xb70
   865ac:      	br	x17

00000000000865b0 <_ZNSt6__ndk110unique_ptrIA_PNS_16__hash_node_baseIPNS_11__hash_nodeINS_17__hash_value_typeINS_17basic_string_viewIcNS_11char_traitsIcEEEEjEEPvEEEENS_25__bucket_list_deallocatorINS_9allocatorISD_EEEEE5resetB8ne180000IPSD_TnNS_9enable_ifIXsr28_CheckArrayPointerConversionIT_EE5valueEiE4typeELi0EEEvSN_@plt>:
   865b0:      	adrp	x16, 0x8f000
   865b4:      	ldr	x17, [x16, #0xb78]
   865b8:      	add	x16, x16, #0xb78
   865bc:      	br	x17

00000000000865c0 <create_android_logger@plt>:
   865c0:      	adrp	x16, 0x8f000
   865c4:      	ldr	x17, [x16, #0xb80]
   865c8:      	add	x16, x16, #0xb80
   865cc:      	br	x17

00000000000865d0 <android_log_destroy@plt>:
   865d0:      	adrp	x16, 0x8f000
   865d4:      	ldr	x17, [x16, #0xb88]
   865d8:      	add	x16, x16, #0xb88
   865dc:      	br	x17

00000000000865e0 <android_log_write_int32@plt>:
   865e0:      	adrp	x16, 0x8f000
   865e4:      	ldr	x17, [x16, #0xb90]
   865e8:      	add	x16, x16, #0xb90
   865ec:      	br	x17

00000000000865f0 <android_log_write_string8_len@plt>:
   865f0:      	adrp	x16, 0x8f000
   865f4:      	ldr	x17, [x16, #0xb98]
   865f8:      	add	x16, x16, #0xb98
   865fc:      	br	x17

0000000000086600 <strnlen@plt>:
   86600:      	adrp	x16, 0x8f000
   86604:      	ldr	x17, [x16, #0xba0]
   86608:      	add	x16, x16, #0xba0
   8660c:      	br	x17

0000000000086610 <android_log_write_list@plt>:
   86610:      	adrp	x16, 0x8f000
   86614:      	ldr	x17, [x16, #0xba8]
   86618:      	add	x16, x16, #0xba8
   8661c:      	br	x17

0000000000086620 <__android_log_bwrite@plt>:
   86620:      	adrp	x16, 0x8f000
   86624:      	ldr	x17, [x16, #0xbb0]
   86628:      	add	x16, x16, #0xbb0
   8662c:      	br	x17

0000000000086630 <__android_log_stats_bwrite@plt>:
   86630:      	adrp	x16, 0x8f000
   86634:      	ldr	x17, [x16, #0xbb8]
   86638:      	add	x16, x16, #0xbb8
   8663c:      	br	x17

0000000000086640 <__android_log_security_bwrite@plt>:
   86640:      	adrp	x16, 0x8f000
   86644:      	ldr	x17, [x16, #0xbc0]
   86648:      	add	x16, x16, #0xbc0
   8664c:      	br	x17

0000000000086650 <calloc@plt>:
   86650:      	adrp	x16, 0x8f000
   86654:      	ldr	x17, [x16, #0xbc8]
   86658:      	add	x16, x16, #0xbc8
   8665c:      	br	x17

0000000000086660 <_ZN8log_timeC2Ei@plt>:
   86660:      	adrp	x16, 0x8f000
   86664:      	ldr	x17, [x16, #0xbd0]
   86668:      	add	x16, x16, #0xbd0
   8666c:      	br	x17

0000000000086670 <localtime_r@plt>:
   86670:      	adrp	x16, 0x8f000
   86674:      	ldr	x17, [x16, #0xbd8]
   86678:      	add	x16, x16, #0xbd8
   8667c:      	br	x17

0000000000086680 <strcpy@plt>:
   86680:      	adrp	x16, 0x8f000
   86684:      	ldr	x17, [x16, #0xbe0]
   86688:      	add	x16, x16, #0xbe0
   8668c:      	br	x17

0000000000086690 <mktime@plt>:
   86690:      	adrp	x16, 0x8f000
   86694:      	ldr	x17, [x16, #0xbe8]
   86698:      	add	x16, x16, #0xbe8
   8669c:      	br	x17

00000000000866a0 <strptime@plt>:
   866a0:      	adrp	x16, 0x8f000
   866a4:      	ldr	x17, [x16, #0xbf0]
   866a8:      	add	x16, x16, #0xbf0
   866ac:      	br	x17

00000000000866b0 <SendLogdControlMessage@plt>:
   866b0:      	adrp	x16, 0x8f000
   866b4:      	ldr	x17, [x16, #0xbf8]
   866b8:      	add	x16, x16, #0xbf8
   866bc:      	br	x17

00000000000866c0 <sysconf@plt>:
   866c0:      	adrp	x16, 0x8f000
   866c4:      	ldr	x17, [x16, #0xc00]
   866c8:      	add	x16, x16, #0xc00
   866cc:      	br	x17

00000000000866d0 <__read_chk@plt>:
   866d0:      	adrp	x16, 0x8f000
   866d4:      	ldr	x17, [x16, #0xc08]
   866d8:      	add	x16, x16, #0xc08
   866dc:      	br	x17

00000000000866e0 <poll@plt>:
   866e0:      	adrp	x16, 0x8f000
   866e4:      	ldr	x17, [x16, #0xc10]
   866e8:      	add	x16, x16, #0xc10
   866ec:      	br	x17

00000000000866f0 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
   866f0:      	adrp	x16, 0x8f000
   866f4:      	ldr	x17, [x16, #0xc18]
   866f8:      	add	x16, x16, #0xc18
   866fc:      	br	x17

0000000000086700 <socket@plt>:
   86700:      	adrp	x16, 0x8f000
   86704:      	ldr	x17, [x16, #0xc20]
   86708:      	add	x16, x16, #0xc20
   8670c:      	br	x17

0000000000086710 <setsockopt@plt>:
   86710:      	adrp	x16, 0x8f000
   86714:      	ldr	x17, [x16, #0xc28]
   86718:      	add	x16, x16, #0xc28
   8671c:      	br	x17

0000000000086720 <android_logger_get_id@plt>:
   86720:      	adrp	x16, 0x8f000
   86724:      	ldr	x17, [x16, #0xc30]
   86728:      	add	x16, x16, #0xc30
   8672c:      	br	x17

0000000000086730 <__vsnprintf_chk@plt>:
   86730:      	adrp	x16, 0x8f000
   86734:      	ldr	x17, [x16, #0xc38]
   86738:      	add	x16, x16, #0xc38
   8673c:      	br	x17

0000000000086740 <_ZN7android4base8ParseIntIlEEbPKcPT_S4_S4_@plt>:
   86740:      	adrp	x16, 0x8f000
   86744:      	ldr	x17, [x16, #0xc40]
   86748:      	add	x16, x16, #0xc40
   8674c:      	br	x17

0000000000086750 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc@plt>:
   86750:      	adrp	x16, 0x8f000
   86754:      	ldr	x17, [x16, #0xc48]
   86758:      	add	x16, x16, #0xc48
   8675c:      	br	x17

0000000000086760 <LogdRead@plt>:
   86760:      	adrp	x16, 0x8f000
   86764:      	ldr	x17, [x16, #0xc50]
   86768:      	add	x16, x16, #0xc50
   8676c:      	br	x17

0000000000086770 <recvfrom@plt>:
   86770:      	adrp	x16, 0x8f000
   86774:      	ldr	x17, [x16, #0xc58]
   86778:      	add	x16, x16, #0xc58
   8677c:      	br	x17

0000000000086780 <__strcpy_chk@plt>:
   86780:      	adrp	x16, 0x8f000
   86784:      	ldr	x17, [x16, #0xc60]
   86788:      	add	x16, x16, #0xc60
   8678c:      	br	x17

0000000000086790 <LogdClose@plt>:
   86790:      	adrp	x16, 0x8f000
   86794:      	ldr	x17, [x16, #0xc68]
   86798:      	add	x16, x16, #0xc68
   8679c:      	br	x17

00000000000867a0 <strtoll@plt>:
   867a0:      	adrp	x16, 0x8f000
   867a4:      	ldr	x17, [x16, #0xc70]
   867a8:      	add	x16, x16, #0xc70
   867ac:      	br	x17

00000000000867b0 <_Z9LogdClosev@plt>:
   867b0:      	adrp	x16, 0x8f000
   867b4:      	ldr	x17, [x16, #0xc78]
   867b8:      	add	x16, x16, #0xc78
   867bc:      	br	x17

00000000000867c0 <_Z9LogdWrite6log_idP8timespecP5iovecm@plt>:
   867c0:      	adrp	x16, 0x8f000
   867c4:      	ldr	x17, [x16, #0xc80]
   867c8:      	add	x16, x16, #0xc80
   867cc:      	br	x17

00000000000867d0 <getuid@plt>:
   867d0:      	adrp	x16, 0x8f000
   867d4:      	ldr	x17, [x16, #0xc88]
   867d8:      	add	x16, x16, #0xc88
   867dc:      	br	x17

00000000000867e0 <android_logger_list_alloc@plt>:
   867e0:      	adrp	x16, 0x8f000
   867e4:      	ldr	x17, [x16, #0xc90]
   867e8:      	add	x16, x16, #0xc90
   867ec:      	br	x17

00000000000867f0 <android_logger_open@plt>:
   867f0:      	adrp	x16, 0x8f000
   867f4:      	ldr	x17, [x16, #0xc98]
   867f8:      	add	x16, x16, #0xc98
   867fc:      	br	x17

0000000000086800 <android_logger_list_free@plt>:
   86800:      	adrp	x16, 0x8f000
   86804:      	ldr	x17, [x16, #0xca0]
   86808:      	add	x16, x16, #0xca0
   8680c:      	br	x17

0000000000086810 <PmsgClose@plt>:
   86810:      	adrp	x16, 0x8f000
   86814:      	ldr	x17, [x16, #0xca8]
   86818:      	add	x16, x16, #0xca8
   8681c:      	br	x17

0000000000086820 <PmsgRead@plt>:
   86820:      	adrp	x16, 0x8f000
   86824:      	ldr	x17, [x16, #0xcb0]
   86828:      	add	x16, x16, #0xcb0
   8682c:      	br	x17

0000000000086830 <_Z9PmsgClosev@plt>:
   86830:      	adrp	x16, 0x8f000
   86834:      	ldr	x17, [x16, #0xcb8]
   86838:      	add	x16, x16, #0xcb8
   8683c:      	br	x17

0000000000086840 <_Z13GetDefaultTagv@plt>:
   86840:      	adrp	x16, 0x8f000
   86844:      	ldr	x17, [x16, #0xcc0]
   86848:      	add	x16, x16, #0xcc0
   8684c:      	br	x17

0000000000086850 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignERKS5_mm@plt>:
   86850:      	adrp	x16, 0x8f000
   86854:      	ldr	x17, [x16, #0xcc8]
   86858:      	add	x16, x16, #0xcc8
   8685c:      	br	x17

0000000000086860 <__android_log_get_minimum_priority@plt>:
   86860:      	adrp	x16, 0x8f000
   86864:      	ldr	x17, [x16, #0xcd0]
   86868:      	add	x16, x16, #0xcd0
   8686c:      	br	x17

0000000000086870 <time@plt>:
   86870:      	adrp	x16, 0x8f000
   86874:      	ldr	x17, [x16, #0xcd8]
   86878:      	add	x16, x16, #0xcd8
   8687c:      	br	x17

0000000000086880 <strftime@plt>:
   86880:      	adrp	x16, 0x8f000
   86884:      	ldr	x17, [x16, #0xce0]
   86888:      	add	x16, x16, #0xce0
   8688c:      	br	x17

0000000000086890 <__android_log_security@plt>:
   86890:      	adrp	x16, 0x8f000
   86894:      	ldr	x17, [x16, #0xce8]
   86898:      	add	x16, x16, #0xce8
   8689c:      	br	x17

00000000000868a0 <_Z9PmsgWrite6log_idP8timespecP5iovecm@plt>:
   868a0:      	adrp	x16, 0x8f000
   868a4:      	ldr	x17, [x16, #0xcf0]
   868a8:      	add	x16, x16, #0xcf0
   868ac:      	br	x17

00000000000868b0 <geteuid@plt>:
   868b0:      	adrp	x16, 0x8f000
   868b4:      	ldr	x17, [x16, #0xcf8]
   868b8:      	add	x16, x16, #0xcf8
   868bc:      	br	x17

00000000000868c0 <getgid@plt>:
   868c0:      	adrp	x16, 0x8f000
   868c4:      	ldr	x17, [x16, #0xd00]
   868c8:      	add	x16, x16, #0xd00
   868cc:      	br	x17

00000000000868d0 <getegid@plt>:
   868d0:      	adrp	x16, 0x8f000
   868d4:      	ldr	x17, [x16, #0xd08]
   868d8:      	add	x16, x16, #0xd08
   868dc:      	br	x17

00000000000868e0 <getgroups@plt>:
   868e0:      	adrp	x16, 0x8f000
   868e4:      	ldr	x17, [x16, #0xd10]
   868e8:      	add	x16, x16, #0xd10
   868ec:      	br	x17

00000000000868f0 <abort@plt>:
   868f0:      	adrp	x16, 0x8f000
   868f4:      	ldr	x17, [x16, #0xd18]
   868f8:      	add	x16, x16, #0xd18
   868fc:      	br	x17

0000000000086900 <getenv@plt>:
   86900:      	adrp	x16, 0x8f000
   86904:      	ldr	x17, [x16, #0xd20]
   86908:      	add	x16, x16, #0xd20
   8690c:      	br	x17

0000000000086910 <strdup@plt>:
   86910:      	adrp	x16, 0x8f000
   86914:      	ldr	x17, [x16, #0xd28]
   86918:      	add	x16, x16, #0xd28
   8691c:      	br	x17

0000000000086920 <tzset@plt>:
   86920:      	adrp	x16, 0x8f000
   86924:      	ldr	x17, [x16, #0xd30]
   86928:      	add	x16, x16, #0xd30
   8692c:      	br	x17

0000000000086930 <strcasecmp@plt>:
   86930:      	adrp	x16, 0x8f000
   86934:      	ldr	x17, [x16, #0xd38]
   86938:      	add	x16, x16, #0xd38
   8693c:      	br	x17

0000000000086940 <unsetenv@plt>:
   86940:      	adrp	x16, 0x8f000
   86944:      	ldr	x17, [x16, #0xd40]
   86948:      	add	x16, x16, #0xd40
   8694c:      	br	x17

0000000000086950 <android_log_addFilterRule@plt>:
   86950:      	adrp	x16, 0x8f000
   86954:      	ldr	x17, [x16, #0xd48]
   86958:      	add	x16, x16, #0xd48
   8695c:      	br	x17

0000000000086960 <strcspn@plt>:
   86960:      	adrp	x16, 0x8f000
   86964:      	ldr	x17, [x16, #0xd50]
   86968:      	add	x16, x16, #0xd50
   8696c:      	br	x17

0000000000086970 <strsep@plt>:
   86970:      	adrp	x16, 0x8f000
   86974:      	ldr	x17, [x16, #0xd58]
   86978:      	add	x16, x16, #0xd58
   8697c:      	br	x17

0000000000086980 <_Z16convertPrintablePcPKcm@plt>:
   86980:      	adrp	x16, 0x8f000
   86984:      	ldr	x17, [x16, #0xd60]
   86988:      	add	x16, x16, #0xd60
   8698c:      	br	x17

0000000000086990 <mbrtowc@plt>:
   86990:      	adrp	x16, 0x8f000
   86994:      	ldr	x17, [x16, #0xd68]
   86998:      	add	x16, x16, #0xd68
   8699c:      	br	x17

00000000000869a0 <__strncpy_chk@plt>:
   869a0:      	adrp	x16, 0x8f000
   869a4:      	ldr	x17, [x16, #0xd70]
   869a8:      	add	x16, x16, #0xd70
   869ac:      	br	x17

00000000000869b0 <android_log_formatLogLine@plt>:
   869b0:      	adrp	x16, 0x8f000
   869b4:      	ldr	x17, [x16, #0xd78]
   869b8:      	add	x16, x16, #0xd78
   869bc:      	br	x17

00000000000869c0 <popen@plt>:
   869c0:      	adrp	x16, 0x8f000
   869c4:      	ldr	x17, [x16, #0xd80]
   869c8:      	add	x16, x16, #0xd80
   869cc:      	br	x17

00000000000869d0 <getline@plt>:
   869d0:      	adrp	x16, 0x8f000
   869d4:      	ldr	x17, [x16, #0xd88]
   869d8:      	add	x16, x16, #0xd88
   869dc:      	br	x17

00000000000869e0 <setenv@plt>:
   869e0:      	adrp	x16, 0x8f000
   869e4:      	ldr	x17, [x16, #0xd90]
   869e8:      	add	x16, x16, #0xd90
   869ec:      	br	x17

00000000000869f0 <pclose@plt>:
   869f0:      	adrp	x16, 0x8f000
   869f4:      	ldr	x17, [x16, #0xd98]
   869f8:      	add	x16, x16, #0xd98
   869fc:      	br	x17

0000000000086a00 <getpwuid@plt>:
   86a00:      	adrp	x16, 0x8f000
   86a04:      	ldr	x17, [x16, #0xda0]
   86a08:      	add	x16, x16, #0xda0
   86a0c:      	br	x17

0000000000086a10 <strcat@plt>:
   86a10:      	adrp	x16, 0x8f000
   86a14:      	ldr	x17, [x16, #0xda8]
   86a18:      	add	x16, x16, #0xda8
   86a1c:      	br	x17

0000000000086a20 <strncat@plt>:
   86a20:      	adrp	x16, 0x8f000
   86a24:      	ldr	x17, [x16, #0xdb0]
   86a28:      	add	x16, x16, #0xdb0
   86a2c:      	br	x17

0000000000086a30 <__memmove_chk@plt>:
   86a30:      	adrp	x16, 0x8f000
   86a34:      	ldr	x17, [x16, #0xdb8]
   86a38:      	add	x16, x16, #0xdb8
   86a3c:      	br	x17

0000000000086a40 <strpbrk@plt>:
   86a40:      	adrp	x16, 0x8f000
   86a44:      	ldr	x17, [x16, #0xdc0]
   86a48:      	add	x16, x16, #0xdc0
   86a4c:      	br	x17

0000000000086a50 <strchr@plt>:
   86a50:      	adrp	x16, 0x8f000
   86a54:      	ldr	x17, [x16, #0xdc8]
   86a58:      	add	x16, x16, #0xdc8
   86a5c:      	br	x17

0000000000086a60 <realloc@plt>:
   86a60:      	adrp	x16, 0x8f000
   86a64:      	ldr	x17, [x16, #0xdd0]
   86a68:      	add	x16, x16, #0xdd0
   86a6c:      	br	x17

0000000000086a70 <strtoull@plt>:
   86a70:      	adrp	x16, 0x8f000
   86a74:      	ldr	x17, [x16, #0xdd8]
   86a78:      	add	x16, x16, #0xdd8
   86a7c:      	br	x17

0000000000086a80 <__android_log_is_debuggable@plt>:
   86a80:      	adrp	x16, 0x8f000
   86a84:      	ldr	x17, [x16, #0xde0]
   86a88:      	add	x16, x16, #0xde0
   86a8c:      	br	x17

0000000000086a90 <__android_log_is_loggable_len@plt>:
   86a90:      	adrp	x16, 0x8f000
   86a94:      	ldr	x17, [x16, #0xde8]
   86a98:      	add	x16, x16, #0xde8
   86a9c:      	br	x17

0000000000086aa0 <pthread_mutex_trylock@plt>:
   86aa0:      	adrp	x16, 0x8f000
   86aa4:      	ldr	x17, [x16, #0xdf0]
   86aa8:      	add	x16, x16, #0xdf0
   86aac:      	br	x17

0000000000086ab0 <strncpy@plt>:
   86ab0:      	adrp	x16, 0x8f000
   86ab4:      	ldr	x17, [x16, #0xdf8]
   86ab8:      	add	x16, x16, #0xdf8
   86abc:      	br	x17

0000000000086ac0 <pthread_mutex_unlock@plt>:
   86ac0:      	adrp	x16, 0x8f000
   86ac4:      	ldr	x17, [x16, #0xe00]
   86ac8:      	add	x16, x16, #0xe00
   86acc:      	br	x17

0000000000086ad0 <__system_property_find@plt>:
   86ad0:      	adrp	x16, 0x8f000
   86ad4:      	ldr	x17, [x16, #0xe08]
   86ad8:      	add	x16, x16, #0xe08
   86adc:      	br	x17

0000000000086ae0 <__system_property_read@plt>:
   86ae0:      	adrp	x16, 0x8f000
   86ae4:      	ldr	x17, [x16, #0xe10]
   86ae8:      	add	x16, x16, #0xe10
   86aec:      	br	x17

0000000000086af0 <_ZNSt14overflow_errorD1Ev@plt>:
   86af0:      	adrp	x16, 0x8f000
   86af4:      	ldr	x17, [x16, #0xe18]
   86af8:      	add	x16, x16, #0xe18
   86afc:      	br	x17

0000000000086b00 <_ZNSt13runtime_errorC2EPKc@plt>:
   86b00:      	adrp	x16, 0x8f000
   86b04:      	ldr	x17, [x16, #0xe20]
   86b08:      	add	x16, x16, #0xe20
   86b0c:      	br	x17

0000000000086b10 <_ZNSt6__ndk112bad_weak_ptrD1Ev@plt>:
   86b10:      	adrp	x16, 0x8f000
   86b14:      	ldr	x17, [x16, #0xe28]
   86b18:      	add	x16, x16, #0xe28
   86b1c:      	br	x17

0000000000086b20 <_ZNSt9exceptionD2Ev@plt>:
   86b20:      	adrp	x16, 0x8f000
   86b24:      	ldr	x17, [x16, #0xe30]
   86b28:      	add	x16, x16, #0xe30
   86b2c:      	br	x17

0000000000086b30 <pthread_mutex_lock@plt>:
   86b30:      	adrp	x16, 0x8f000
   86b34:      	ldr	x17, [x16, #0xe38]
   86b38:      	add	x16, x16, #0xe38
   86b3c:      	br	x17

0000000000086b40 <_ZNSt9bad_allocC1Ev@plt>:
   86b40:      	adrp	x16, 0x8f000
   86b44:      	ldr	x17, [x16, #0xe40]
   86b48:      	add	x16, x16, #0xe40
   86b4c:      	br	x17

0000000000086b50 <_ZNSt9bad_allocD1Ev@plt>:
   86b50:      	adrp	x16, 0x8f000
   86b54:      	ldr	x17, [x16, #0xe48]
   86b58:      	add	x16, x16, #0xe48
   86b5c:      	br	x17

0000000000086b60 <_ZNSt13runtime_errorC1EPKc@plt>:
   86b60:      	adrp	x16, 0x8f000
   86b64:      	ldr	x17, [x16, #0xe50]
   86b68:      	add	x16, x16, #0xe50
   86b6c:      	br	x17

0000000000086b70 <_ZNSt13runtime_errorD1Ev@plt>:
   86b70:      	adrp	x16, 0x8f000
   86b74:      	ldr	x17, [x16, #0xe58]
   86b78:      	add	x16, x16, #0xe58
   86b7c:      	br	x17

0000000000086b80 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7replaceEmmPKcm@plt>:
   86b80:      	adrp	x16, 0x8f000
   86b84:      	ldr	x17, [x16, #0xe60]
   86b88:      	add	x16, x16, #0xe60
   86b8c:      	br	x17

0000000000086b90 <memchr@plt>:
   86b90:      	adrp	x16, 0x8f000
   86b94:      	ldr	x17, [x16, #0xe68]
   86b98:      	add	x16, x16, #0xe68
   86b9c:      	br	x17

0000000000086ba0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
   86ba0:      	adrp	x16, 0x8f000
   86ba4:      	ldr	x17, [x16, #0xe70]
   86ba8:      	add	x16, x16, #0xe70
   86bac:      	br	x17

0000000000086bb0 <__cxa_end_catch@plt>:
   86bb0:      	adrp	x16, 0x8f000
   86bb4:      	ldr	x17, [x16, #0xe78]
   86bb8:      	add	x16, x16, #0xe78
   86bbc:      	br	x17

0000000000086bc0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   86bc0:      	adrp	x16, 0x8f000
   86bc4:      	ldr	x17, [x16, #0xe80]
   86bc8:      	add	x16, x16, #0xe80
   86bcc:      	br	x17

0000000000086bd0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEmc@plt>:
   86bd0:      	adrp	x16, 0x8f000
   86bd4:      	ldr	x17, [x16, #0xe88]
   86bd8:      	add	x16, x16, #0xe88
   86bdc:      	br	x17

0000000000086be0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE7replaceEmmPKwm@plt>:
   86be0:      	adrp	x16, 0x8f000
   86be4:      	ldr	x17, [x16, #0xe90]
   86be8:      	add	x16, x16, #0xe90
   86bec:      	br	x17

0000000000086bf0 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE21__grow_by_and_replaceEmmmmmmPKw@plt>:
   86bf0:      	adrp	x16, 0x8f000
   86bf4:      	ldr	x17, [x16, #0xe98]
   86bf8:      	add	x16, x16, #0xe98
   86bfc:      	br	x17

0000000000086c00 <wcslen@plt>:
   86c00:      	adrp	x16, 0x8f000
   86c04:      	ldr	x17, [x16, #0xea0]
   86c08:      	add	x16, x16, #0xea0
   86c0c:      	br	x17

0000000000086c10 <wmemchr@plt>:
   86c10:      	adrp	x16, 0x8f000
   86c14:      	ldr	x17, [x16, #0xea8]
   86c18:      	add	x16, x16, #0xea8
   86c1c:      	br	x17

0000000000086c20 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6insertEmPKwm@plt>:
   86c20:      	adrp	x16, 0x8f000
   86c24:      	ldr	x17, [x16, #0xeb0]
   86c28:      	add	x16, x16, #0xeb0
   86c2c:      	br	x17

0000000000086c30 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEmw@plt>:
   86c30:      	adrp	x16, 0x8f000
   86c34:      	ldr	x17, [x16, #0xeb8]
   86c38:      	add	x16, x16, #0xeb8
   86c3c:      	br	x17

0000000000086c40 <wmemcmp@plt>:
   86c40:      	adrp	x16, 0x8f000
   86c44:      	ldr	x17, [x16, #0xec0]
   86c48:      	add	x16, x16, #0xec0
   86c4c:      	br	x17

0000000000086c50 <_ZNSt12out_of_rangeD1Ev@plt>:
   86c50:      	adrp	x16, 0x8f000
   86c54:      	ldr	x17, [x16, #0xec8]
   86c58:      	add	x16, x16, #0xec8
   86c5c:      	br	x17

0000000000086c60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEED1Ev@plt>:
   86c60:      	adrp	x16, 0x8f000
   86c64:      	ldr	x17, [x16, #0xed0]
   86c68:      	add	x16, x16, #0xed0
   86c6c:      	br	x17

0000000000086c70 <strtof@plt>:
   86c70:      	adrp	x16, 0x8f000
   86c74:      	ldr	x17, [x16, #0xed8]
   86c78:      	add	x16, x16, #0xed8
   86c7c:      	br	x17

0000000000086c80 <strtod@plt>:
   86c80:      	adrp	x16, 0x8f000
   86c84:      	ldr	x17, [x16, #0xee0]
   86c88:      	add	x16, x16, #0xee0
   86c8c:      	br	x17

0000000000086c90 <strtold@plt>:
   86c90:      	adrp	x16, 0x8f000
   86c94:      	ldr	x17, [x16, #0xee8]
   86c98:      	add	x16, x16, #0xee8
   86c9c:      	br	x17

0000000000086ca0 <wcstoul@plt>:
   86ca0:      	adrp	x16, 0x8f000
   86ca4:      	ldr	x17, [x16, #0xef0]
   86ca8:      	add	x16, x16, #0xef0
   86cac:      	br	x17

0000000000086cb0 <wcstoll@plt>:
   86cb0:      	adrp	x16, 0x8f000
   86cb4:      	ldr	x17, [x16, #0xef8]
   86cb8:      	add	x16, x16, #0xef8
   86cbc:      	br	x17

0000000000086cc0 <wcstoull@plt>:
   86cc0:      	adrp	x16, 0x8f000
   86cc4:      	ldr	x17, [x16, #0xf00]
   86cc8:      	add	x16, x16, #0xf00
   86ccc:      	br	x17

0000000000086cd0 <wcstof@plt>:
   86cd0:      	adrp	x16, 0x8f000
   86cd4:      	ldr	x17, [x16, #0xf08]
   86cd8:      	add	x16, x16, #0xf08
   86cdc:      	br	x17

0000000000086ce0 <wcstod@plt>:
   86ce0:      	adrp	x16, 0x8f000
   86ce4:      	ldr	x17, [x16, #0xf10]
   86ce8:      	add	x16, x16, #0xf10
   86cec:      	br	x17

0000000000086cf0 <wcstold@plt>:
   86cf0:      	adrp	x16, 0x8f000
   86cf4:      	ldr	x17, [x16, #0xf18]
   86cf8:      	add	x16, x16, #0xf18
   86cfc:      	br	x17

0000000000086d00 <snprintf@plt>:
   86d00:      	adrp	x16, 0x8f000
   86d04:      	ldr	x17, [x16, #0xf20]
   86d08:      	add	x16, x16, #0xf20
   86d0c:      	br	x17

0000000000086d10 <swprintf@plt>:
   86d10:      	adrp	x16, 0x8f000
   86d14:      	ldr	x17, [x16, #0xf28]
   86d18:      	add	x16, x16, #0xf28
   86d1c:      	br	x17

0000000000086d20 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEED1Ev@plt>:
   86d20:      	adrp	x16, 0x8f000
   86d24:      	ldr	x17, [x16, #0xf30]
   86d28:      	add	x16, x16, #0xf30
   86d2c:      	br	x17

0000000000086d30 <strtol@plt>:
   86d30:      	adrp	x16, 0x8f000
   86d34:      	ldr	x17, [x16, #0xf38]
   86d38:      	add	x16, x16, #0xf38
   86d3c:      	br	x17

0000000000086d40 <_ZNSt16invalid_argumentD1Ev@plt>:
   86d40:      	adrp	x16, 0x8f000
   86d44:      	ldr	x17, [x16, #0xf40]
   86d48:      	add	x16, x16, #0xf40
   86d4c:      	br	x17

0000000000086d50 <wcstol@plt>:
   86d50:      	adrp	x16, 0x8f000
   86d54:      	ldr	x17, [x16, #0xf48]
   86d58:      	add	x16, x16, #0xf48
   86d5c:      	br	x17

0000000000086d60 <__cxa_get_globals@plt>:
   86d60:      	adrp	x16, 0x8f000
   86d64:      	ldr	x17, [x16, #0xf50]
   86d68:      	add	x16, x16, #0xf50
   86d6c:      	br	x17

0000000000086d70 <__cxa_get_globals_fast@plt>:
   86d70:      	adrp	x16, 0x8f000
   86d74:      	ldr	x17, [x16, #0xf58]
   86d78:      	add	x16, x16, #0xf58
   86d7c:      	br	x17

0000000000086d80 <pthread_cond_wait@plt>:
   86d80:      	adrp	x16, 0x8f000
   86d84:      	ldr	x17, [x16, #0xf60]
   86d88:      	add	x16, x16, #0xf60
   86d8c:      	br	x17

0000000000086d90 <pthread_cond_broadcast@plt>:
   86d90:      	adrp	x16, 0x8f000
   86d94:      	ldr	x17, [x16, #0xf68]
   86d98:      	add	x16, x16, #0xf68
   86d9c:      	br	x17

0000000000086da0 <_ZSt14get_unexpectedv@plt>:
   86da0:      	adrp	x16, 0x8f000
   86da4:      	ldr	x17, [x16, #0xf70]
   86da8:      	add	x16, x16, #0xf70
   86dac:      	br	x17

0000000000086db0 <_ZSt13get_terminatev@plt>:
   86db0:      	adrp	x16, 0x8f000
   86db4:      	ldr	x17, [x16, #0xf78]
   86db8:      	add	x16, x16, #0xf78
   86dbc:      	br	x17

0000000000086dc0 <_ZSt15get_new_handlerv@plt>:
   86dc0:      	adrp	x16, 0x8f000
   86dc4:      	ldr	x17, [x16, #0xf80]
   86dc8:      	add	x16, x16, #0xf80
   86dcc:      	br	x17

0000000000086dd0 <__cxa_demangle@plt>:
   86dd0:      	adrp	x16, 0x8f000
   86dd4:      	ldr	x17, [x16, #0xf88]
   86dd8:      	add	x16, x16, #0xf88
   86ddc:      	br	x17

0000000000086de0 <__emutls_get_address@plt>:
   86de0:      	adrp	x16, 0x8f000
   86de4:      	ldr	x17, [x16, #0xf90]
   86de8:      	add	x16, x16, #0xf90
   86dec:      	br	x17

0000000000086df0 <_ZNSt9exceptionD1Ev@plt>:
   86df0:      	adrp	x16, 0x8f000
   86df4:      	ldr	x17, [x16, #0xf98]
   86df8:      	add	x16, x16, #0xf98
   86dfc:      	br	x17

0000000000086e00 <_ZNSt13bad_exceptionD1Ev@plt>:
   86e00:      	adrp	x16, 0x8f000
   86e04:      	ldr	x17, [x16, #0xfa0]
   86e08:      	add	x16, x16, #0xfa0
   86e0c:      	br	x17

0000000000086e10 <_ZNSt11logic_errorD1Ev@plt>:
   86e10:      	adrp	x16, 0x8f000
   86e14:      	ldr	x17, [x16, #0xfa8]
   86e18:      	add	x16, x16, #0xfa8
   86e1c:      	br	x17

0000000000086e20 <_ZNSt12domain_errorD1Ev@plt>:
   86e20:      	adrp	x16, 0x8f000
   86e24:      	ldr	x17, [x16, #0xfb0]
   86e28:      	add	x16, x16, #0xfb0
   86e2c:      	br	x17

0000000000086e30 <_ZNSt11range_errorD1Ev@plt>:
   86e30:      	adrp	x16, 0x8f000
   86e34:      	ldr	x17, [x16, #0xfb8]
   86e38:      	add	x16, x16, #0xfb8
   86e3c:      	br	x17

0000000000086e40 <_ZNSt15underflow_errorD1Ev@plt>:
   86e40:      	adrp	x16, 0x8f000
   86e44:      	ldr	x17, [x16, #0xfc0]
   86e48:      	add	x16, x16, #0xfc0
   86e4c:      	br	x17

0000000000086e50 <_ZNSt9type_infoD2Ev@plt>:
   86e50:      	adrp	x16, 0x8f000
   86e54:      	ldr	x17, [x16, #0xfc8]
   86e58:      	add	x16, x16, #0xfc8
   86e5c:      	br	x17

0000000000086e60 <_ZNSt9type_infoD1Ev@plt>:
   86e60:      	adrp	x16, 0x8f000
   86e64:      	ldr	x17, [x16, #0xfd0]
   86e68:      	add	x16, x16, #0xfd0
   86e6c:      	br	x17

0000000000086e70 <_ZNSt8bad_castD1Ev@plt>:
   86e70:      	adrp	x16, 0x8f000
   86e74:      	ldr	x17, [x16, #0xfd8]
   86e78:      	add	x16, x16, #0xfd8
   86e7c:      	br	x17

0000000000086e80 <_ZNSt10bad_typeidD1Ev@plt>:
   86e80:      	adrp	x16, 0x8f000
   86e84:      	ldr	x17, [x16, #0xfe0]
   86e88:      	add	x16, x16, #0xfe0
   86e8c:      	br	x17

0000000000086e90 <vfprintf@plt>:
   86e90:      	adrp	x16, 0x8f000
   86e94:      	ldr	x17, [x16, #0xfe8]
   86e98:      	add	x16, x16, #0xfe8
   86e9c:      	br	x17

0000000000086ea0 <fputc@plt>:
   86ea0:      	adrp	x16, 0x8f000
   86ea4:      	ldr	x17, [x16, #0xff0]
   86ea8:      	add	x16, x16, #0xff0
   86eac:      	br	x17

0000000000086eb0 <vasprintf@plt>:
   86eb0:      	adrp	x16, 0x8f000
   86eb4:      	ldr	x17, [x16, #0xff8]
   86eb8:      	add	x16, x16, #0xff8
   86ebc:      	br	x17

0000000000086ec0 <openlog@plt>:
   86ec0:      	adrp	x16, 0x90000
   86ec4:      	ldr	x17, [x16]
   86ec8:      	add	x16, x16, #0x0
   86ecc:      	br	x17

0000000000086ed0 <syslog@plt>:
   86ed0:      	adrp	x16, 0x90000
   86ed4:      	ldr	x17, [x16, #0x8]
   86ed8:      	add	x16, x16, #0x8
   86edc:      	br	x17

0000000000086ee0 <closelog@plt>:
   86ee0:      	adrp	x16, 0x90000
   86ee4:      	ldr	x17, [x16, #0x10]
   86ee8:      	add	x16, x16, #0x10
   86eec:      	br	x17

0000000000086ef0 <__dynamic_cast@plt>:
   86ef0:      	adrp	x16, 0x90000
   86ef4:      	ldr	x17, [x16, #0x18]
   86ef8:      	add	x16, x16, #0x18
   86efc:      	br	x17

0000000000086f00 <_ZnwmSt11align_val_t@plt>:
   86f00:      	adrp	x16, 0x90000
   86f04:      	ldr	x17, [x16, #0x20]
   86f08:      	add	x16, x16, #0x20
   86f0c:      	br	x17

0000000000086f10 <posix_memalign@plt>:
   86f10:      	adrp	x16, 0x90000
   86f14:      	ldr	x17, [x16, #0x28]
   86f18:      	add	x16, x16, #0x28
   86f1c:      	br	x17

0000000000086f20 <_ZnamSt11align_val_t@plt>:
   86f20:      	adrp	x16, 0x90000
   86f24:      	ldr	x17, [x16, #0x30]
   86f28:      	add	x16, x16, #0x30
   86f2c:      	br	x17

0000000000086f30 <_ZdlPvSt11align_val_t@plt>:
   86f30:      	adrp	x16, 0x90000
   86f34:      	ldr	x17, [x16, #0x38]
   86f38:      	add	x16, x16, #0x38
   86f3c:      	br	x17

0000000000086f40 <_ZdaPvSt11align_val_t@plt>:
   86f40:      	adrp	x16, 0x90000
   86f44:      	ldr	x17, [x16, #0x40]
   86f48:      	add	x16, x16, #0x40
   86f4c:      	br	x17

0000000000086f50 <__cxa_rethrow@plt>:
   86f50:      	adrp	x16, 0x90000
   86f54:      	ldr	x17, [x16, #0x48]
   86f58:      	add	x16, x16, #0x48
   86f5c:      	br	x17

0000000000086f60 <__assert2@plt>:
   86f60:      	adrp	x16, 0x90000
   86f64:      	ldr	x17, [x16, #0x50]
   86f68:      	add	x16, x16, #0x50
   86f6c:      	br	x17

0000000000086f70 <pthread_getspecific@plt>:
   86f70:      	adrp	x16, 0x90000
   86f74:      	ldr	x17, [x16, #0x58]
   86f78:      	add	x16, x16, #0x58
   86f7c:      	br	x17

0000000000086f80 <pthread_setspecific@plt>:
   86f80:      	adrp	x16, 0x90000
   86f84:      	ldr	x17, [x16, #0x60]
   86f88:      	add	x16, x16, #0x60
   86f8c:      	br	x17

0000000000086f90 <pthread_key_delete@plt>:
   86f90:      	adrp	x16, 0x90000
   86f94:      	ldr	x17, [x16, #0x68]
   86f98:      	add	x16, x16, #0x68
   86f9c:      	br	x17

0000000000086fa0 <pthread_key_create@plt>:
   86fa0:      	adrp	x16, 0x90000
   86fa4:      	ldr	x17, [x16, #0x70]
   86fa8:      	add	x16, x16, #0x70
   86fac:      	br	x17

0000000000086fb0 <getauxval@plt>:
   86fb0:      	adrp	x16, 0x90000
   86fb4:      	ldr	x17, [x16, #0x78]
   86fb8:      	add	x16, x16, #0x78
   86fbc:      	br	x17

0000000000086fc0 <fflush@plt>:
   86fc0:      	adrp	x16, 0x90000
   86fc4:      	ldr	x17, [x16, #0x80]
   86fc8:      	add	x16, x16, #0x80
   86fcc:      	br	x17
