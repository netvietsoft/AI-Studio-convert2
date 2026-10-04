// EXPORTED & PLT DISASSEMBLY FOR libbytehook.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libbytehook.so (SHA-256: 1FA39F206CF1CB5863DC3770EC3A21339921364E647A3AB4DBB094EAB83676D8)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 20, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libbytehook.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000000d210 <.plt>:
    d210:      	stp	x16, x30, [sp, #-0x10]!
    d214:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d218:      	ldr	x17, [x16, #0xb18]
    d21c:      	add	x16, x16, #0xb18
    d220:      	br	x17
    d224:      	nop
    d228:      	nop
    d22c:      	nop

000000000000d230 <__cxa_finalize@plt>:
    d230:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d234:      	ldr	x17, [x16, #0xb20]
    d238:      	add	x16, x16, #0xb20
    d23c:      	br	x17

000000000000d240 <__cxa_atexit@plt>:
    d240:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d244:      	ldr	x17, [x16, #0xb28]
    d248:      	add	x16, x16, #0xb28
    d24c:      	br	x17

000000000000d250 <realloc@plt>:
    d250:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d254:      	ldr	x17, [x16, #0xb30]
    d258:      	add	x16, x16, #0xb30
    d25c:      	br	x17

000000000000d260 <free@plt>:
    d260:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d264:      	ldr	x17, [x16, #0xb38]
    d268:      	add	x16, x16, #0xb38
    d26c:      	br	x17

000000000000d270 <malloc@plt>:
    d270:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d274:      	ldr	x17, [x16, #0xb40]
    d278:      	add	x16, x16, #0xb40
    d27c:      	br	x17

000000000000d280 <dlopen@plt>:
    d280:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d284:      	ldr	x17, [x16, #0xb48]
    d288:      	add	x16, x16, #0xb48
    d28c:      	br	x17

000000000000d290 <dlsym@plt>:
    d290:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d294:      	ldr	x17, [x16, #0xb50]
    d298:      	add	x16, x16, #0xb50
    d29c:      	br	x17

000000000000d2a0 <dlclose@plt>:
    d2a0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d2a4:      	ldr	x17, [x16, #0xb58]
    d2a8:      	add	x16, x16, #0xb58
    d2ac:      	br	x17

000000000000d2b0 <gettid@plt>:
    d2b0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d2b4:      	ldr	x17, [x16, #0xb60]
    d2b8:      	add	x16, x16, #0xb60
    d2bc:      	br	x17

000000000000d2c0 <syscall@plt>:
    d2c0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d2c4:      	ldr	x17, [x16, #0xb68]
    d2c8:      	add	x16, x16, #0xb68
    d2cc:      	br	x17

000000000000d2d0 <sigsetjmp@plt>:
    d2d0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d2d4:      	ldr	x17, [x16, #0xb70]
    d2d8:      	add	x16, x16, #0xb70
    d2dc:      	br	x17

000000000000d2e0 <__stack_chk_fail@plt>:
    d2e0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d2e4:      	ldr	x17, [x16, #0xb78]
    d2e8:      	add	x16, x16, #0xb78
    d2ec:      	br	x17

000000000000d2f0 <getauxval@plt>:
    d2f0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d2f4:      	ldr	x17, [x16, #0xb80]
    d2f8:      	add	x16, x16, #0xb80
    d2fc:      	br	x17

000000000000d300 <calloc@plt>:
    d300:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d304:      	ldr	x17, [x16, #0xb88]
    d308:      	add	x16, x16, #0xb88
    d30c:      	br	x17

000000000000d310 <__open_2@plt>:
    d310:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d314:      	ldr	x17, [x16, #0xb90]
    d318:      	add	x16, x16, #0xb90
    d31c:      	br	x17

000000000000d320 <fstat@plt>:
    d320:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d324:      	ldr	x17, [x16, #0xb98]
    d328:      	add	x16, x16, #0xb98
    d32c:      	br	x17

000000000000d330 <close@plt>:
    d330:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d334:      	ldr	x17, [x16, #0xba0]
    d338:      	add	x16, x16, #0xba0
    d33c:      	br	x17

000000000000d340 <strcmp@plt>:
    d340:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d344:      	ldr	x17, [x16, #0xba8]
    d348:      	add	x16, x16, #0xba8
    d34c:      	br	x17

000000000000d350 <strncmp@plt>:
    d350:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d354:      	ldr	x17, [x16, #0xbb0]
    d358:      	add	x16, x16, #0xbb0
    d35c:      	br	x17

000000000000d360 <lseek@plt>:
    d360:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d364:      	ldr	x17, [x16, #0xbb8]
    d368:      	add	x16, x16, #0xbb8
    d36c:      	br	x17

000000000000d370 <__errno@plt>:
    d370:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d374:      	ldr	x17, [x16, #0xbc0]
    d378:      	add	x16, x16, #0xbc0
    d37c:      	br	x17

000000000000d380 <__read_chk@plt>:
    d380:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d384:      	ldr	x17, [x16, #0xbc8]
    d388:      	add	x16, x16, #0xbc8
    d38c:      	br	x17

000000000000d390 <dl_iterate_phdr@plt>:
    d390:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d394:      	ldr	x17, [x16, #0xbd0]
    d398:      	add	x16, x16, #0xbd0
    d39c:      	br	x17

000000000000d3a0 <__android_log_print@plt>:
    d3a0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d3a4:      	ldr	x17, [x16, #0xbd8]
    d3a8:      	add	x16, x16, #0xbd8
    d3ac:      	br	x17

000000000000d3b0 <pthread_mutex_lock@plt>:
    d3b0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d3b4:      	ldr	x17, [x16, #0xbe0]
    d3b8:      	add	x16, x16, #0xbe0
    d3bc:      	br	x17

000000000000d3c0 <pthread_key_create@plt>:
    d3c0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d3c4:      	ldr	x17, [x16, #0xbe8]
    d3c8:      	add	x16, x16, #0xbe8
    d3cc:      	br	x17

000000000000d3d0 <bytehook_get_mode@plt>:
    d3d0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d3d4:      	ldr	x17, [x16, #0xbf0]
    d3d8:      	add	x16, x16, #0xbf0
    d3dc:      	br	x17

000000000000d3e0 <pthread_mutex_unlock@plt>:
    d3e0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d3e4:      	ldr	x17, [x16, #0xbf8]
    d3e8:      	add	x16, x16, #0xbf8
    d3ec:      	br	x17

000000000000d3f0 <pthread_rwlock_unlock@plt>:
    d3f0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d3f4:      	ldr	x17, [x16, #0xc00]
    d3f8:      	add	x16, x16, #0xc00
    d3fc:      	br	x17

000000000000d400 <bytehook_get_prev_func@plt>:
    d400:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d404:      	ldr	x17, [x16, #0xc08]
    d408:      	add	x16, x16, #0xc08
    d40c:      	br	x17

000000000000d410 <bytehook_get_return_address@plt>:
    d410:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d414:      	ldr	x17, [x16, #0xc10]
    d418:      	add	x16, x16, #0xc10
    d41c:      	br	x17

000000000000d420 <bytehook_pop_stack@plt>:
    d420:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d424:      	ldr	x17, [x16, #0xc18]
    d428:      	add	x16, x16, #0xc18
    d42c:      	br	x17

000000000000d430 <pthread_rwlock_rdlock@plt>:
    d430:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d434:      	ldr	x17, [x16, #0xc20]
    d438:      	add	x16, x16, #0xc20
    d43c:      	br	x17

000000000000d440 <pthread_getspecific@plt>:
    d440:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d444:      	ldr	x17, [x16, #0xc28]
    d448:      	add	x16, x16, #0xc28
    d44c:      	br	x17

000000000000d450 <pthread_setspecific@plt>:
    d450:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d454:      	ldr	x17, [x16, #0xc30]
    d458:      	add	x16, x16, #0xc30
    d45c:      	br	x17

000000000000d460 <__vsnprintf_chk@plt>:
    d460:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d464:      	ldr	x17, [x16, #0xc38]
    d468:      	add	x16, x16, #0xc38
    d46c:      	br	x17

000000000000d470 <pthread_rwlock_wrlock@plt>:
    d470:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d474:      	ldr	x17, [x16, #0xc40]
    d478:      	add	x16, x16, #0xc40
    d47c:      	br	x17

000000000000d480 <strdup@plt>:
    d480:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d484:      	ldr	x17, [x16, #0xc48]
    d488:      	add	x16, x16, #0xc48
    d48c:      	br	x17

000000000000d490 <pthread_mutex_init@plt>:
    d490:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d494:      	ldr	x17, [x16, #0xc50]
    d498:      	add	x16, x16, #0xc50
    d49c:      	br	x17

000000000000d4a0 <pthread_cond_init@plt>:
    d4a0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d4a4:      	ldr	x17, [x16, #0xc58]
    d4a8:      	add	x16, x16, #0xc58
    d4ac:      	br	x17

000000000000d4b0 <pthread_mutex_destroy@plt>:
    d4b0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d4b4:      	ldr	x17, [x16, #0xc60]
    d4b8:      	add	x16, x16, #0xc60
    d4bc:      	br	x17

000000000000d4c0 <pthread_cond_destroy@plt>:
    d4c0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d4c4:      	ldr	x17, [x16, #0xc68]
    d4c8:      	add	x16, x16, #0xc68
    d4cc:      	br	x17

000000000000d4d0 <abort@plt>:
    d4d0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d4d4:      	ldr	x17, [x16, #0xc70]
    d4d8:      	add	x16, x16, #0xc70
    d4dc:      	br	x17

000000000000d4e0 <pthread_cond_signal@plt>:
    d4e0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d4e4:      	ldr	x17, [x16, #0xc78]
    d4e8:      	add	x16, x16, #0xc78
    d4ec:      	br	x17

000000000000d4f0 <gettimeofday@plt>:
    d4f0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d4f4:      	ldr	x17, [x16, #0xc80]
    d4f8:      	add	x16, x16, #0xc80
    d4fc:      	br	x17

000000000000d500 <pthread_cond_wait@plt>:
    d500:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d504:      	ldr	x17, [x16, #0xc88]
    d508:      	add	x16, x16, #0xc88
    d50c:      	br	x17

000000000000d510 <memcpy@plt>:
    d510:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d514:      	ldr	x17, [x16, #0xc90]
    d518:      	add	x16, x16, #0xc90
    d51c:      	br	x17

000000000000d520 <bytehook_get_version@plt>:
    d520:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d524:      	ldr	x17, [x16, #0xc98]
    d528:      	add	x16, x16, #0xc98
    d52c:      	br	x17

000000000000d530 <bytehook_init@plt>:
    d530:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d534:      	ldr	x17, [x16, #0xca0]
    d538:      	add	x16, x16, #0xca0
    d53c:      	br	x17

000000000000d540 <bytehook_add_ignore@plt>:
    d540:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d544:      	ldr	x17, [x16, #0xca8]
    d548:      	add	x16, x16, #0xca8
    d54c:      	br	x17

000000000000d550 <bytehook_get_debug@plt>:
    d550:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d554:      	ldr	x17, [x16, #0xcb0]
    d558:      	add	x16, x16, #0xcb0
    d55c:      	br	x17

000000000000d560 <bytehook_set_debug@plt>:
    d560:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d564:      	ldr	x17, [x16, #0xcb8]
    d568:      	add	x16, x16, #0xcb8
    d56c:      	br	x17

000000000000d570 <bytehook_get_recordable@plt>:
    d570:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d574:      	ldr	x17, [x16, #0xcc0]
    d578:      	add	x16, x16, #0xcc0
    d57c:      	br	x17

000000000000d580 <bytehook_set_recordable@plt>:
    d580:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d584:      	ldr	x17, [x16, #0xcc8]
    d588:      	add	x16, x16, #0xcc8
    d58c:      	br	x17

000000000000d590 <bytehook_get_records@plt>:
    d590:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d594:      	ldr	x17, [x16, #0xcd0]
    d598:      	add	x16, x16, #0xcd0
    d59c:      	br	x17

000000000000d5a0 <strrchr@plt>:
    d5a0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d5a4:      	ldr	x17, [x16, #0xcd8]
    d5a8:      	add	x16, x16, #0xcd8
    d5ac:      	br	x17

000000000000d5b0 <strlen@plt>:
    d5b0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d5b4:      	ldr	x17, [x16, #0xce0]
    d5b8:      	add	x16, x16, #0xce0
    d5bc:      	br	x17

000000000000d5c0 <__strlen_chk@plt>:
    d5c0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d5c4:      	ldr	x17, [x16, #0xce8]
    d5c8:      	add	x16, x16, #0xce8
    d5cc:      	br	x17

000000000000d5d0 <dladdr@plt>:
    d5d0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d5d4:      	ldr	x17, [x16, #0xcf0]
    d5d8:      	add	x16, x16, #0xcf0
    d5dc:      	br	x17

000000000000d5e0 <strlcpy@plt>:
    d5e0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d5e4:      	ldr	x17, [x16, #0xcf8]
    d5e8:      	add	x16, x16, #0xcf8
    d5ec:      	br	x17

000000000000d5f0 <memcmp@plt>:
    d5f0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d5f4:      	ldr	x17, [x16, #0xd00]
    d5f8:      	add	x16, x16, #0xd00
    d5fc:      	br	x17

000000000000d600 <pthread_rwlock_init@plt>:
    d600:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d604:      	ldr	x17, [x16, #0xd08]
    d608:      	add	x16, x16, #0xd08
    d60c:      	br	x17

000000000000d610 <pthread_rwlock_destroy@plt>:
    d610:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d614:      	ldr	x17, [x16, #0xd10]
    d618:      	add	x16, x16, #0xd10
    d61c:      	br	x17

000000000000d620 <vsnprintf@plt>:
    d620:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d624:      	ldr	x17, [x16, #0xd18]
    d628:      	add	x16, x16, #0xd18
    d62c:      	br	x17

000000000000d630 <shadowhook_register_dl_init_callback@plt>:
    d630:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d634:      	ldr	x17, [x16, #0xd20]
    d638:      	add	x16, x16, #0xd20
    d63c:      	br	x17

000000000000d640 <shadowhook_register_dl_fini_callback@plt>:
    d640:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d644:      	ldr	x17, [x16, #0xd28]
    d648:      	add	x16, x16, #0xd28
    d64c:      	br	x17

000000000000d650 <memset@plt>:
    d650:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d654:      	ldr	x17, [x16, #0xd30]
    d658:      	add	x16, x16, #0xd30
    d65c:      	br	x17

000000000000d660 <prctl@plt>:
    d660:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d664:      	ldr	x17, [x16, #0xd38]
    d668:      	add	x16, x16, #0xd38
    d66c:      	br	x17

000000000000d670 <mmap@plt>:
    d670:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d674:      	ldr	x17, [x16, #0xd40]
    d678:      	add	x16, x16, #0xd40
    d67c:      	br	x17

000000000000d680 <munmap@plt>:
    d680:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d684:      	ldr	x17, [x16, #0xd48]
    d688:      	add	x16, x16, #0xd48
    d68c:      	br	x17

000000000000d690 <getpagesize@plt>:
    d690:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d694:      	ldr	x17, [x16, #0xd50]
    d698:      	add	x16, x16, #0xd50
    d69c:      	br	x17

000000000000d6a0 <__system_property_get@plt>:
    d6a0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d6a4:      	ldr	x17, [x16, #0xd58]
    d6a8:      	add	x16, x16, #0xd58
    d6ac:      	br	x17

000000000000d6b0 <atoi@plt>:
    d6b0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d6b4:      	ldr	x17, [x16, #0xd60]
    d6b8:      	add	x16, x16, #0xd60
    d6bc:      	br	x17

000000000000d6c0 <fopen@plt>:
    d6c0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d6c4:      	ldr	x17, [x16, #0xd68]
    d6c8:      	add	x16, x16, #0xd68
    d6cc:      	br	x17

000000000000d6d0 <fgets@plt>:
    d6d0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d6d4:      	ldr	x17, [x16, #0xd70]
    d6d8:      	add	x16, x16, #0xd70
    d6dc:      	br	x17

000000000000d6e0 <fclose@plt>:
    d6e0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d6e4:      	ldr	x17, [x16, #0xd78]
    d6e8:      	add	x16, x16, #0xd78
    d6ec:      	br	x17

000000000000d6f0 <write@plt>:
    d6f0:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d6f4:      	ldr	x17, [x16, #0xd80]
    d6f8:      	add	x16, x16, #0xd80
    d6fc:      	br	x17

000000000000d700 <mprotect@plt>:
    d700:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d704:      	ldr	x17, [x16, #0xd88]
    d708:      	add	x16, x16, #0xd88
    d70c:      	br	x17

000000000000d710 <sigfillset64@plt>:
    d710:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d714:      	ldr	x17, [x16, #0xd90]
    d718:      	add	x16, x16, #0xd90
    d71c:      	br	x17

000000000000d720 <sigfillset@plt>:
    d720:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d724:      	ldr	x17, [x16, #0xd98]
    d728:      	add	x16, x16, #0xd98
    d72c:      	br	x17

000000000000d730 <sigemptyset64@plt>:
    d730:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d734:      	ldr	x17, [x16, #0xda0]
    d738:      	add	x16, x16, #0xda0
    d73c:      	br	x17

000000000000d740 <sigismember64@plt>:
    d740:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d744:      	ldr	x17, [x16, #0xda8]
    d748:      	add	x16, x16, #0xda8
    d74c:      	br	x17

000000000000d750 <sigaddset64@plt>:
    d750:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d754:      	ldr	x17, [x16, #0xdb0]
    d758:      	add	x16, x16, #0xdb0
    d75c:      	br	x17

000000000000d760 <sigemptyset@plt>:
    d760:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d764:      	ldr	x17, [x16, #0xdb8]
    d768:      	add	x16, x16, #0xdb8
    d76c:      	br	x17

000000000000d770 <sigismember@plt>:
    d770:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d774:      	ldr	x17, [x16, #0xdc0]
    d778:      	add	x16, x16, #0xdc0
    d77c:      	br	x17

000000000000d780 <sigaddset@plt>:
    d780:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d784:      	ldr	x17, [x16, #0xdc8]
    d788:      	add	x16, x16, #0xdc8
    d78c:      	br	x17

000000000000d790 <siglongjmp@plt>:
    d790:      	adrp	x16, 0x11000 <siglongjmp@plt+0x3870>
    d794:      	ldr	x17, [x16, #0xdd0]
    d798:      	add	x16, x16, #0xdd0
    d79c:      	br	x17
