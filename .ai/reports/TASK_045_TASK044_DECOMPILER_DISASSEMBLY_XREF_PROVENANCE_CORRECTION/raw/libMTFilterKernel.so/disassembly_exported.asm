// EXPORTED & PLT DISASSEMBLY FOR libMTFilterKernel.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so (SHA-256: F938FE73095FCEBA72875D1AB42F8AEB6A9F31F3933831BEC070404C0E7ECAC4)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 3113, JNI Methods: 2


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libMTFilterKernel.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000001b4210 <.plt>:
  1b4210:      	stp	x16, x30, [sp, #-0x10]!
  1b4214:      	adrp	x16, 0x1c5000
  1b4218:      	ldr	x17, [x16, #0xb88]
  1b421c:      	add	x16, x16, #0xb88
  1b4220:      	br	x17
  1b4224:      	nop
  1b4228:      	nop
  1b422c:      	nop

00000000001b4230 <__cxa_finalize@plt>:
  1b4230:      	adrp	x16, 0x1c5000
  1b4234:      	ldr	x17, [x16, #0xb90]
  1b4238:      	add	x16, x16, #0xb90
  1b423c:      	br	x17

00000000001b4240 <__cxa_atexit@plt>:
  1b4240:      	adrp	x16, 0x1c5000
  1b4244:      	ldr	x17, [x16, #0xb98]
  1b4248:      	add	x16, x16, #0xb98
  1b424c:      	br	x17

00000000001b4250 <calloc@plt>:
  1b4250:      	adrp	x16, 0x1c5000
  1b4254:      	ldr	x17, [x16, #0xba0]
  1b4258:      	add	x16, x16, #0xba0
  1b425c:      	br	x17

00000000001b4260 <free@plt>:
  1b4260:      	adrp	x16, 0x1c5000
  1b4264:      	ldr	x17, [x16, #0xba8]
  1b4268:      	add	x16, x16, #0xba8
  1b426c:      	br	x17

00000000001b4270 <__android_log_print@plt>:
  1b4270:      	adrp	x16, 0x1c5000
  1b4274:      	ldr	x17, [x16, #0xbb0]
  1b4278:      	add	x16, x16, #0xbb0
  1b427c:      	br	x17

00000000001b4280 <__stack_chk_fail@plt>:
  1b4280:      	adrp	x16, 0x1c5000
  1b4284:      	ldr	x17, [x16, #0xbb8]
  1b4288:      	add	x16, x16, #0xbb8
  1b428c:      	br	x17

00000000001b4290 <memcpy@plt>:
  1b4290:      	adrp	x16, 0x1c5000
  1b4294:      	ldr	x17, [x16, #0xbc0]
  1b4298:      	add	x16, x16, #0xbc0
  1b429c:      	br	x17

00000000001b42a0 <_Znam@plt>:
  1b42a0:      	adrp	x16, 0x1c5000
  1b42a4:      	ldr	x17, [x16, #0xbc8]
  1b42a8:      	add	x16, x16, #0xbc8
  1b42ac:      	br	x17

00000000001b42b0 <_ZdaPv@plt>:
  1b42b0:      	adrp	x16, 0x1c5000
  1b42b4:      	ldr	x17, [x16, #0xbd0]
  1b42b8:      	add	x16, x16, #0xbd0
  1b42bc:      	br	x17

00000000001b42c0 <memset@plt>:
  1b42c0:      	adrp	x16, 0x1c5000
  1b42c4:      	ldr	x17, [x16, #0xbd8]
  1b42c8:      	add	x16, x16, #0xbd8
  1b42cc:      	br	x17

00000000001b42d0 <_Znwm@plt>:
  1b42d0:      	adrp	x16, 0x1c5000
  1b42d4:      	ldr	x17, [x16, #0xbe0]
  1b42d8:      	add	x16, x16, #0xbe0
  1b42dc:      	br	x17

00000000001b42e0 <_ZdlPv@plt>:
  1b42e0:      	adrp	x16, 0x1c5000
  1b42e4:      	ldr	x17, [x16, #0xbe8]
  1b42e8:      	add	x16, x16, #0xbe8
  1b42ec:      	br	x17

00000000001b42f0 <__cxa_begin_catch@plt>:
  1b42f0:      	adrp	x16, 0x1c5000
  1b42f4:      	ldr	x17, [x16, #0xbf0]
  1b42f8:      	add	x16, x16, #0xbf0
  1b42fc:      	br	x17

00000000001b4300 <_ZSt9terminatev@plt>:
  1b4300:      	adrp	x16, 0x1c5000
  1b4304:      	ldr	x17, [x16, #0xbf8]
  1b4308:      	add	x16, x16, #0xbf8
  1b430c:      	br	x17

00000000001b4310 <strlen@plt>:
  1b4310:      	adrp	x16, 0x1c5000
  1b4314:      	ldr	x17, [x16, #0xc00]
  1b4318:      	add	x16, x16, #0xc00
  1b431c:      	br	x17

00000000001b4320 <strcpy@plt>:
  1b4320:      	adrp	x16, 0x1c5000
  1b4324:      	ldr	x17, [x16, #0xc08]
  1b4328:      	add	x16, x16, #0xc08
  1b432c:      	br	x17

00000000001b4330 <sysconf@plt>:
  1b4330:      	adrp	x16, 0x1c5000
  1b4334:      	ldr	x17, [x16, #0xc10]
  1b4338:      	add	x16, x16, #0xc10
  1b433c:      	br	x17

00000000001b4340 <__vsprintf_chk@plt>:
  1b4340:      	adrp	x16, 0x1c5000
  1b4344:      	ldr	x17, [x16, #0xc18]
  1b4348:      	add	x16, x16, #0xc18
  1b434c:      	br	x17

00000000001b4350 <strstr@plt>:
  1b4350:      	adrp	x16, 0x1c5000
  1b4354:      	ldr	x17, [x16, #0xc20]
  1b4358:      	add	x16, x16, #0xc20
  1b435c:      	br	x17

00000000001b4360 <pthread_getspecific@plt>:
  1b4360:      	adrp	x16, 0x1c5000
  1b4364:      	ldr	x17, [x16, #0xc28]
  1b4368:      	add	x16, x16, #0xc28
  1b436c:      	br	x17

00000000001b4370 <pthread_self@plt>:
  1b4370:      	adrp	x16, 0x1c5000
  1b4374:      	ldr	x17, [x16, #0xc30]
  1b4378:      	add	x16, x16, #0xc30
  1b437c:      	br	x17

00000000001b4380 <pthread_key_create@plt>:
  1b4380:      	adrp	x16, 0x1c5000
  1b4384:      	ldr	x17, [x16, #0xc38]
  1b4388:      	add	x16, x16, #0xc38
  1b438c:      	br	x17

00000000001b4390 <pthread_setspecific@plt>:
  1b4390:      	adrp	x16, 0x1c5000
  1b4394:      	ldr	x17, [x16, #0xc40]
  1b4398:      	add	x16, x16, #0xc40
  1b439c:      	br	x17

00000000001b43a0 <memmove@plt>:
  1b43a0:      	adrp	x16, 0x1c5000
  1b43a4:      	ldr	x17, [x16, #0xc48]
  1b43a8:      	add	x16, x16, #0xc48
  1b43ac:      	br	x17

00000000001b43b0 <__cxa_allocate_exception@plt>:
  1b43b0:      	adrp	x16, 0x1c5000
  1b43b4:      	ldr	x17, [x16, #0xc50]
  1b43b8:      	add	x16, x16, #0xc50
  1b43bc:      	br	x17

00000000001b43c0 <__cxa_throw@plt>:
  1b43c0:      	adrp	x16, 0x1c5000
  1b43c4:      	ldr	x17, [x16, #0xc58]
  1b43c8:      	add	x16, x16, #0xc58
  1b43cc:      	br	x17

00000000001b43d0 <__cxa_free_exception@plt>:
  1b43d0:      	adrp	x16, 0x1c5000
  1b43d4:      	ldr	x17, [x16, #0xc60]
  1b43d8:      	add	x16, x16, #0xc60
  1b43dc:      	br	x17

00000000001b43e0 <_ZNSt11logic_errorC2EPKc@plt>:
  1b43e0:      	adrp	x16, 0x1c5000
  1b43e4:      	ldr	x17, [x16, #0xc68]
  1b43e8:      	add	x16, x16, #0xc68
  1b43ec:      	br	x17

00000000001b43f0 <AAssetManager_fromJava@plt>:
  1b43f0:      	adrp	x16, 0x1c5000
  1b43f4:      	ldr	x17, [x16, #0xc70]
  1b43f8:      	add	x16, x16, #0xc70
  1b43fc:      	br	x17

00000000001b4400 <fseek@plt>:
  1b4400:      	adrp	x16, 0x1c5000
  1b4404:      	ldr	x17, [x16, #0xc78]
  1b4408:      	add	x16, x16, #0xc78
  1b440c:      	br	x17

00000000001b4410 <ftell@plt>:
  1b4410:      	adrp	x16, 0x1c5000
  1b4414:      	ldr	x17, [x16, #0xc80]
  1b4418:      	add	x16, x16, #0xc80
  1b441c:      	br	x17

00000000001b4420 <fread@plt>:
  1b4420:      	adrp	x16, 0x1c5000
  1b4424:      	ldr	x17, [x16, #0xc88]
  1b4428:      	add	x16, x16, #0xc88
  1b442c:      	br	x17

00000000001b4430 <fclose@plt>:
  1b4430:      	adrp	x16, 0x1c5000
  1b4434:      	ldr	x17, [x16, #0xc90]
  1b4438:      	add	x16, x16, #0xc90
  1b443c:      	br	x17

00000000001b4440 <AAssetManager_open@plt>:
  1b4440:      	adrp	x16, 0x1c5000
  1b4444:      	ldr	x17, [x16, #0xc98]
  1b4448:      	add	x16, x16, #0xc98
  1b444c:      	br	x17

00000000001b4450 <strrchr@plt>:
  1b4450:      	adrp	x16, 0x1c5000
  1b4454:      	ldr	x17, [x16, #0xca0]
  1b4458:      	add	x16, x16, #0xca0
  1b445c:      	br	x17

00000000001b4460 <__strcpy_chk@plt>:
  1b4460:      	adrp	x16, 0x1c5000
  1b4464:      	ldr	x17, [x16, #0xca8]
  1b4468:      	add	x16, x16, #0xca8
  1b446c:      	br	x17

00000000001b4470 <__strlen_chk@plt>:
  1b4470:      	adrp	x16, 0x1c5000
  1b4474:      	ldr	x17, [x16, #0xcb0]
  1b4478:      	add	x16, x16, #0xcb0
  1b447c:      	br	x17

00000000001b4480 <__strlcpy_chk@plt>:
  1b4480:      	adrp	x16, 0x1c5000
  1b4484:      	ldr	x17, [x16, #0xcb8]
  1b4488:      	add	x16, x16, #0xcb8
  1b448c:      	br	x17

00000000001b4490 <__strrchr_chk@plt>:
  1b4490:      	adrp	x16, 0x1c5000
  1b4494:      	ldr	x17, [x16, #0xcc0]
  1b4498:      	add	x16, x16, #0xcc0
  1b449c:      	br	x17

00000000001b44a0 <AAsset_getLength@plt>:
  1b44a0:      	adrp	x16, 0x1c5000
  1b44a4:      	ldr	x17, [x16, #0xcc8]
  1b44a8:      	add	x16, x16, #0xcc8
  1b44ac:      	br	x17

00000000001b44b0 <AAsset_read@plt>:
  1b44b0:      	adrp	x16, 0x1c5000
  1b44b4:      	ldr	x17, [x16, #0xcd0]
  1b44b8:      	add	x16, x16, #0xcd0
  1b44bc:      	br	x17

00000000001b44c0 <AAsset_seek@plt>:
  1b44c0:      	adrp	x16, 0x1c5000
  1b44c4:      	ldr	x17, [x16, #0xcd8]
  1b44c8:      	add	x16, x16, #0xcd8
  1b44cc:      	br	x17

00000000001b44d0 <AAsset_close@plt>:
  1b44d0:      	adrp	x16, 0x1c5000
  1b44d4:      	ldr	x17, [x16, #0xce0]
  1b44d8:      	add	x16, x16, #0xce0
  1b44dc:      	br	x17

00000000001b44e0 <fopen@plt>:
  1b44e0:      	adrp	x16, 0x1c5000
  1b44e4:      	ldr	x17, [x16, #0xce8]
  1b44e8:      	add	x16, x16, #0xce8
  1b44ec:      	br	x17

00000000001b44f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
  1b44f0:      	adrp	x16, 0x1c5000
  1b44f4:      	ldr	x17, [x16, #0xcf0]
  1b44f8:      	add	x16, x16, #0xcf0
  1b44fc:      	br	x17

00000000001b4500 <gettimeofday@plt>:
  1b4500:      	adrp	x16, 0x1c5000
  1b4504:      	ldr	x17, [x16, #0xcf8]
  1b4508:      	add	x16, x16, #0xcf8
  1b450c:      	br	x17

00000000001b4510 <glDeleteTextures@plt>:
  1b4510:      	adrp	x16, 0x1c5000
  1b4514:      	ldr	x17, [x16, #0xd00]
  1b4518:      	add	x16, x16, #0xd00
  1b451c:      	br	x17

00000000001b4520 <atof@plt>:
  1b4520:      	adrp	x16, 0x1c5000
  1b4524:      	ldr	x17, [x16, #0xd08]
  1b4528:      	add	x16, x16, #0xd08
  1b452c:      	br	x17

00000000001b4530 <atoi@plt>:
  1b4530:      	adrp	x16, 0x1c5000
  1b4534:      	ldr	x17, [x16, #0xd10]
  1b4538:      	add	x16, x16, #0xd10
  1b453c:      	br	x17

00000000001b4540 <memchr@plt>:
  1b4540:      	adrp	x16, 0x1c5000
  1b4544:      	ldr	x17, [x16, #0xd18]
  1b4548:      	add	x16, x16, #0xd18
  1b454c:      	br	x17

00000000001b4550 <memcmp@plt>:
  1b4550:      	adrp	x16, 0x1c5000
  1b4554:      	ldr	x17, [x16, #0xd20]
  1b4558:      	add	x16, x16, #0xd20
  1b455c:      	br	x17

00000000001b4560 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
  1b4560:      	adrp	x16, 0x1c5000
  1b4564:      	ldr	x17, [x16, #0xd28]
  1b4568:      	add	x16, x16, #0xd28
  1b456c:      	br	x17

00000000001b4570 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
  1b4570:      	adrp	x16, 0x1c5000
  1b4574:      	ldr	x17, [x16, #0xd30]
  1b4578:      	add	x16, x16, #0xd30
  1b457c:      	br	x17

00000000001b4580 <glClearColor@plt>:
  1b4580:      	adrp	x16, 0x1c5000
  1b4584:      	ldr	x17, [x16, #0xd38]
  1b4588:      	add	x16, x16, #0xd38
  1b458c:      	br	x17

00000000001b4590 <glClear@plt>:
  1b4590:      	adrp	x16, 0x1c5000
  1b4594:      	ldr	x17, [x16, #0xd40]
  1b4598:      	add	x16, x16, #0xd40
  1b459c:      	br	x17

00000000001b45a0 <glEnable@plt>:
  1b45a0:      	adrp	x16, 0x1c5000
  1b45a4:      	ldr	x17, [x16, #0xd48]
  1b45a8:      	add	x16, x16, #0xd48
  1b45ac:      	br	x17

00000000001b45b0 <glBlendFuncSeparate@plt>:
  1b45b0:      	adrp	x16, 0x1c5000
  1b45b4:      	ldr	x17, [x16, #0xd50]
  1b45b8:      	add	x16, x16, #0xd50
  1b45bc:      	br	x17

00000000001b45c0 <glBlendFunc@plt>:
  1b45c0:      	adrp	x16, 0x1c5000
  1b45c4:      	ldr	x17, [x16, #0xd58]
  1b45c8:      	add	x16, x16, #0xd58
  1b45cc:      	br	x17

00000000001b45d0 <glDisable@plt>:
  1b45d0:      	adrp	x16, 0x1c5000
  1b45d4:      	ldr	x17, [x16, #0xd60]
  1b45d8:      	add	x16, x16, #0xd60
  1b45dc:      	br	x17

00000000001b45e0 <_ZNSt20bad_array_new_lengthC1Ev@plt>:
  1b45e0:      	adrp	x16, 0x1c5000
  1b45e4:      	ldr	x17, [x16, #0xd68]
  1b45e8:      	add	x16, x16, #0xd68
  1b45ec:      	br	x17

00000000001b45f0 <ARGBScale@plt>:
  1b45f0:      	adrp	x16, 0x1c5000
  1b45f4:      	ldr	x17, [x16, #0xd70]
  1b45f8:      	add	x16, x16, #0xd70
  1b45fc:      	br	x17

00000000001b4600 <ScalePlane@plt>:
  1b4600:      	adrp	x16, 0x1c5000
  1b4604:      	ldr	x17, [x16, #0xd78]
  1b4608:      	add	x16, x16, #0xd78
  1b460c:      	br	x17

00000000001b4610 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
  1b4610:      	adrp	x16, 0x1c5000
  1b4614:      	ldr	x17, [x16, #0xd80]
  1b4618:      	add	x16, x16, #0xd80
  1b461c:      	br	x17

00000000001b4620 <printf@plt>:
  1b4620:      	adrp	x16, 0x1c5000
  1b4624:      	ldr	x17, [x16, #0xd88]
  1b4628:      	add	x16, x16, #0xd88
  1b462c:      	br	x17

00000000001b4630 <malloc@plt>:
  1b4630:      	adrp	x16, 0x1c5000
  1b4634:      	ldr	x17, [x16, #0xd90]
  1b4638:      	add	x16, x16, #0xd90
  1b463c:      	br	x17

00000000001b4640 <pthread_attr_init@plt>:
  1b4640:      	adrp	x16, 0x1c5000
  1b4644:      	ldr	x17, [x16, #0xd98]
  1b4648:      	add	x16, x16, #0xd98
  1b464c:      	br	x17

00000000001b4650 <pthread_attr_setdetachstate@plt>:
  1b4650:      	adrp	x16, 0x1c5000
  1b4654:      	ldr	x17, [x16, #0xda0]
  1b4658:      	add	x16, x16, #0xda0
  1b465c:      	br	x17

00000000001b4660 <pthread_create@plt>:
  1b4660:      	adrp	x16, 0x1c5000
  1b4664:      	ldr	x17, [x16, #0xda8]
  1b4668:      	add	x16, x16, #0xda8
  1b466c:      	br	x17

00000000001b4670 <pthread_attr_destroy@plt>:
  1b4670:      	adrp	x16, 0x1c5000
  1b4674:      	ldr	x17, [x16, #0xdb0]
  1b4678:      	add	x16, x16, #0xdb0
  1b467c:      	br	x17

00000000001b4680 <pthread_join@plt>:
  1b4680:      	adrp	x16, 0x1c5000
  1b4684:      	ldr	x17, [x16, #0xdb8]
  1b4688:      	add	x16, x16, #0xdb8
  1b468c:      	br	x17

00000000001b4690 <atan2f@plt>:
  1b4690:      	adrp	x16, 0x1c5000
  1b4694:      	ldr	x17, [x16, #0xdc0]
  1b4698:      	add	x16, x16, #0xdc0
  1b469c:      	br	x17

00000000001b46a0 <prctl@plt>:
  1b46a0:      	adrp	x16, 0x1c5000
  1b46a4:      	ldr	x17, [x16, #0xdc8]
  1b46a8:      	add	x16, x16, #0xdc8
  1b46ac:      	br	x17

00000000001b46b0 <pthread_exit@plt>:
  1b46b0:      	adrp	x16, 0x1c5000
  1b46b4:      	ldr	x17, [x16, #0xdd0]
  1b46b8:      	add	x16, x16, #0xdd0
  1b46bc:      	br	x17

00000000001b46c0 <time@plt>:
  1b46c0:      	adrp	x16, 0x1c5000
  1b46c4:      	ldr	x17, [x16, #0xdd8]
  1b46c8:      	add	x16, x16, #0xdd8
  1b46cc:      	br	x17

00000000001b46d0 <localtime@plt>:
  1b46d0:      	adrp	x16, 0x1c5000
  1b46d4:      	ldr	x17, [x16, #0xde0]
  1b46d8:      	add	x16, x16, #0xde0
  1b46dc:      	br	x17

00000000001b46e0 <glDeleteFramebuffers@plt>:
  1b46e0:      	adrp	x16, 0x1c5000
  1b46e4:      	ldr	x17, [x16, #0xde8]
  1b46e8:      	add	x16, x16, #0xde8
  1b46ec:      	br	x17

00000000001b46f0 <glBindTexture@plt>:
  1b46f0:      	adrp	x16, 0x1c5000
  1b46f4:      	ldr	x17, [x16, #0xdf0]
  1b46f8:      	add	x16, x16, #0xdf0
  1b46fc:      	br	x17

00000000001b4700 <glTexImage2D@plt>:
  1b4700:      	adrp	x16, 0x1c5000
  1b4704:      	ldr	x17, [x16, #0xdf8]
  1b4708:      	add	x16, x16, #0xdf8
  1b470c:      	br	x17

00000000001b4710 <glTexParameterf@plt>:
  1b4710:      	adrp	x16, 0x1c5000
  1b4714:      	ldr	x17, [x16, #0xe00]
  1b4718:      	add	x16, x16, #0xe00
  1b471c:      	br	x17

00000000001b4720 <glTexParameteri@plt>:
  1b4720:      	adrp	x16, 0x1c5000
  1b4724:      	ldr	x17, [x16, #0xe08]
  1b4728:      	add	x16, x16, #0xe08
  1b472c:      	br	x17

00000000001b4730 <glGenFramebuffers@plt>:
  1b4730:      	adrp	x16, 0x1c5000
  1b4734:      	ldr	x17, [x16, #0xe10]
  1b4738:      	add	x16, x16, #0xe10
  1b473c:      	br	x17

00000000001b4740 <glBindFramebuffer@plt>:
  1b4740:      	adrp	x16, 0x1c5000
  1b4744:      	ldr	x17, [x16, #0xe18]
  1b4748:      	add	x16, x16, #0xe18
  1b474c:      	br	x17

00000000001b4750 <glFramebufferTexture2D@plt>:
  1b4750:      	adrp	x16, 0x1c5000
  1b4754:      	ldr	x17, [x16, #0xe20]
  1b4758:      	add	x16, x16, #0xe20
  1b475c:      	br	x17

00000000001b4760 <glCheckFramebufferStatus@plt>:
  1b4760:      	adrp	x16, 0x1c5000
  1b4764:      	ldr	x17, [x16, #0xe28]
  1b4768:      	add	x16, x16, #0xe28
  1b476c:      	br	x17

00000000001b4770 <glUniform1f@plt>:
  1b4770:      	adrp	x16, 0x1c5000
  1b4774:      	ldr	x17, [x16, #0xe30]
  1b4778:      	add	x16, x16, #0xe30
  1b477c:      	br	x17

00000000001b4780 <glActiveTexture@plt>:
  1b4780:      	adrp	x16, 0x1c5000
  1b4784:      	ldr	x17, [x16, #0xe38]
  1b4788:      	add	x16, x16, #0xe38
  1b478c:      	br	x17

00000000001b4790 <sinf@plt>:
  1b4790:      	adrp	x16, 0x1c5000
  1b4794:      	ldr	x17, [x16, #0xe40]
  1b4798:      	add	x16, x16, #0xe40
  1b479c:      	br	x17

00000000001b47a0 <glEnableVertexAttribArray@plt>:
  1b47a0:      	adrp	x16, 0x1c5000
  1b47a4:      	ldr	x17, [x16, #0xe48]
  1b47a8:      	add	x16, x16, #0xe48
  1b47ac:      	br	x17

00000000001b47b0 <glVertexAttribPointer@plt>:
  1b47b0:      	adrp	x16, 0x1c5000
  1b47b4:      	ldr	x17, [x16, #0xe50]
  1b47b8:      	add	x16, x16, #0xe50
  1b47bc:      	br	x17

00000000001b47c0 <glDrawArrays@plt>:
  1b47c0:      	adrp	x16, 0x1c5000
  1b47c4:      	ldr	x17, [x16, #0xe58]
  1b47c8:      	add	x16, x16, #0xe58
  1b47cc:      	br	x17

00000000001b47d0 <glUniformMatrix4fv@plt>:
  1b47d0:      	adrp	x16, 0x1c5000
  1b47d4:      	ldr	x17, [x16, #0xe60]
  1b47d8:      	add	x16, x16, #0xe60
  1b47dc:      	br	x17

00000000001b47e0 <glUniform1i@plt>:
  1b47e0:      	adrp	x16, 0x1c5000
  1b47e4:      	ldr	x17, [x16, #0xe68]
  1b47e8:      	add	x16, x16, #0xe68
  1b47ec:      	br	x17

00000000001b47f0 <glUniform4f@plt>:
  1b47f0:      	adrp	x16, 0x1c5000
  1b47f4:      	ldr	x17, [x16, #0xe70]
  1b47f8:      	add	x16, x16, #0xe70
  1b47fc:      	br	x17

00000000001b4800 <glUniform3f@plt>:
  1b4800:      	adrp	x16, 0x1c5000
  1b4804:      	ldr	x17, [x16, #0xe78]
  1b4808:      	add	x16, x16, #0xe78
  1b480c:      	br	x17

00000000001b4810 <glUniform2f@plt>:
  1b4810:      	adrp	x16, 0x1c5000
  1b4814:      	ldr	x17, [x16, #0xe80]
  1b4818:      	add	x16, x16, #0xe80
  1b481c:      	br	x17

00000000001b4820 <glUniformMatrix2fv@plt>:
  1b4820:      	adrp	x16, 0x1c5000
  1b4824:      	ldr	x17, [x16, #0xe88]
  1b4828:      	add	x16, x16, #0xe88
  1b482c:      	br	x17

00000000001b4830 <glUniformMatrix3fv@plt>:
  1b4830:      	adrp	x16, 0x1c5000
  1b4834:      	ldr	x17, [x16, #0xe90]
  1b4838:      	add	x16, x16, #0xe90
  1b483c:      	br	x17

00000000001b4840 <glGetError@plt>:
  1b4840:      	adrp	x16, 0x1c5000
  1b4844:      	ldr	x17, [x16, #0xe98]
  1b4848:      	add	x16, x16, #0xe98
  1b484c:      	br	x17

00000000001b4850 <__cxa_end_catch@plt>:
  1b4850:      	adrp	x16, 0x1c5000
  1b4854:      	ldr	x17, [x16, #0xea0]
  1b4858:      	add	x16, x16, #0xea0
  1b485c:      	br	x17

00000000001b4860 <glFlush@plt>:
  1b4860:      	adrp	x16, 0x1c5000
  1b4864:      	ldr	x17, [x16, #0xea8]
  1b4868:      	add	x16, x16, #0xea8
  1b486c:      	br	x17

00000000001b4870 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
  1b4870:      	adrp	x16, 0x1c5000
  1b4874:      	ldr	x17, [x16, #0xeb0]
  1b4878:      	add	x16, x16, #0xeb0
  1b487c:      	br	x17

00000000001b4880 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
  1b4880:      	adrp	x16, 0x1c5000
  1b4884:      	ldr	x17, [x16, #0xeb8]
  1b4888:      	add	x16, x16, #0xeb8
  1b488c:      	br	x17

00000000001b4890 <__dynamic_cast@plt>:
  1b4890:      	adrp	x16, 0x1c5000
  1b4894:      	ldr	x17, [x16, #0xec0]
  1b4898:      	add	x16, x16, #0xec0
  1b489c:      	br	x17

00000000001b48a0 <access@plt>:
  1b48a0:      	adrp	x16, 0x1c5000
  1b48a4:      	ldr	x17, [x16, #0xec8]
  1b48a8:      	add	x16, x16, #0xec8
  1b48ac:      	br	x17

00000000001b48b0 <glFinish@plt>:
  1b48b0:      	adrp	x16, 0x1c5000
  1b48b4:      	ldr	x17, [x16, #0xed0]
  1b48b8:      	add	x16, x16, #0xed0
  1b48bc:      	br	x17

00000000001b48c0 <__cxa_guard_acquire@plt>:
  1b48c0:      	adrp	x16, 0x1c5000
  1b48c4:      	ldr	x17, [x16, #0xed8]
  1b48c8:      	add	x16, x16, #0xed8
  1b48cc:      	br	x17

00000000001b48d0 <__cxa_guard_release@plt>:
  1b48d0:      	adrp	x16, 0x1c5000
  1b48d4:      	ldr	x17, [x16, #0xee0]
  1b48d8:      	add	x16, x16, #0xee0
  1b48dc:      	br	x17

00000000001b48e0 <glDeleteProgram@plt>:
  1b48e0:      	adrp	x16, 0x1c5000
  1b48e4:      	ldr	x17, [x16, #0xee8]
  1b48e8:      	add	x16, x16, #0xee8
  1b48ec:      	br	x17

00000000001b48f0 <glGetUniformLocation@plt>:
  1b48f0:      	adrp	x16, 0x1c5000
  1b48f4:      	ldr	x17, [x16, #0xef0]
  1b48f8:      	add	x16, x16, #0xef0
  1b48fc:      	br	x17

00000000001b4900 <glViewport@plt>:
  1b4900:      	adrp	x16, 0x1c5000
  1b4904:      	ldr	x17, [x16, #0xef8]
  1b4908:      	add	x16, x16, #0xef8
  1b490c:      	br	x17

00000000001b4910 <glUseProgram@plt>:
  1b4910:      	adrp	x16, 0x1c5000
  1b4914:      	ldr	x17, [x16, #0xf00]
  1b4918:      	add	x16, x16, #0xf00
  1b491c:      	br	x17

00000000001b4920 <glReadPixels@plt>:
  1b4920:      	adrp	x16, 0x1c5000
  1b4924:      	ldr	x17, [x16, #0xf08]
  1b4928:      	add	x16, x16, #0xf08
  1b492c:      	br	x17

00000000001b4930 <glDisableVertexAttribArray@plt>:
  1b4930:      	adrp	x16, 0x1c5000
  1b4934:      	ldr	x17, [x16, #0xf10]
  1b4938:      	add	x16, x16, #0xf10
  1b493c:      	br	x17

00000000001b4940 <glGetAttribLocation@plt>:
  1b4940:      	adrp	x16, 0x1c5000
  1b4944:      	ldr	x17, [x16, #0xf18]
  1b4948:      	add	x16, x16, #0xf18
  1b494c:      	br	x17

00000000001b4950 <expf@plt>:
  1b4950:      	adrp	x16, 0x1c5000
  1b4954:      	ldr	x17, [x16, #0xf20]
  1b4958:      	add	x16, x16, #0xf20
  1b495c:      	br	x17

00000000001b4960 <rand@plt>:
  1b4960:      	adrp	x16, 0x1c5000
  1b4964:      	ldr	x17, [x16, #0xf28]
  1b4968:      	add	x16, x16, #0xf28
  1b496c:      	br	x17

00000000001b4970 <glTexSubImage2D@plt>:
  1b4970:      	adrp	x16, 0x1c5000
  1b4974:      	ldr	x17, [x16, #0xf30]
  1b4978:      	add	x16, x16, #0xf30
  1b497c:      	br	x17

00000000001b4980 <glGenTextures@plt>:
  1b4980:      	adrp	x16, 0x1c5000
  1b4984:      	ldr	x17, [x16, #0xf38]
  1b4988:      	add	x16, x16, #0xf38
  1b498c:      	br	x17

00000000001b4990 <fmodf@plt>:
  1b4990:      	adrp	x16, 0x1c5000
  1b4994:      	ldr	x17, [x16, #0xf40]
  1b4998:      	add	x16, x16, #0xf40
  1b499c:      	br	x17

00000000001b49a0 <tanf@plt>:
  1b49a0:      	adrp	x16, 0x1c5000
  1b49a4:      	ldr	x17, [x16, #0xf48]
  1b49a8:      	add	x16, x16, #0xf48
  1b49ac:      	br	x17

00000000001b49b0 <sincosf@plt>:
  1b49b0:      	adrp	x16, 0x1c5000
  1b49b4:      	ldr	x17, [x16, #0xf50]
  1b49b8:      	add	x16, x16, #0xf50
  1b49bc:      	br	x17

00000000001b49c0 <__cxa_guard_abort@plt>:
  1b49c0:      	adrp	x16, 0x1c5000
  1b49c4:      	ldr	x17, [x16, #0xf58]
  1b49c8:      	add	x16, x16, #0xf58
  1b49cc:      	br	x17

00000000001b49d0 <acosf@plt>:
  1b49d0:      	adrp	x16, 0x1c5000
  1b49d4:      	ldr	x17, [x16, #0xf60]
  1b49d8:      	add	x16, x16, #0xf60
  1b49dc:      	br	x17

00000000001b49e0 <glUniform1iv@plt>:
  1b49e0:      	adrp	x16, 0x1c5000
  1b49e4:      	ldr	x17, [x16, #0xf68]
  1b49e8:      	add	x16, x16, #0xf68
  1b49ec:      	br	x17

00000000001b49f0 <glUniform3fv@plt>:
  1b49f0:      	adrp	x16, 0x1c5000
  1b49f4:      	ldr	x17, [x16, #0xf70]
  1b49f8:      	add	x16, x16, #0xf70
  1b49fc:      	br	x17

00000000001b4a00 <glUniform4fv@plt>:
  1b4a00:      	adrp	x16, 0x1c5000
  1b4a04:      	ldr	x17, [x16, #0xf78]
  1b4a08:      	add	x16, x16, #0xf78
  1b4a0c:      	br	x17

00000000001b4a10 <glUniform1fv@plt>:
  1b4a10:      	adrp	x16, 0x1c5000
  1b4a14:      	ldr	x17, [x16, #0xf80]
  1b4a18:      	add	x16, x16, #0xf80
  1b4a1c:      	br	x17

00000000001b4a20 <glUniform2fv@plt>:
  1b4a20:      	adrp	x16, 0x1c5000
  1b4a24:      	ldr	x17, [x16, #0xf88]
  1b4a28:      	add	x16, x16, #0xf88
  1b4a2c:      	br	x17

00000000001b4a30 <glCreateShader@plt>:
  1b4a30:      	adrp	x16, 0x1c5000
  1b4a34:      	ldr	x17, [x16, #0xf90]
  1b4a38:      	add	x16, x16, #0xf90
  1b4a3c:      	br	x17

00000000001b4a40 <glShaderSource@plt>:
  1b4a40:      	adrp	x16, 0x1c5000
  1b4a44:      	ldr	x17, [x16, #0xf98]
  1b4a48:      	add	x16, x16, #0xf98
  1b4a4c:      	br	x17

00000000001b4a50 <glCompileShader@plt>:
  1b4a50:      	adrp	x16, 0x1c5000
  1b4a54:      	ldr	x17, [x16, #0xfa0]
  1b4a58:      	add	x16, x16, #0xfa0
  1b4a5c:      	br	x17

00000000001b4a60 <glGetShaderiv@plt>:
  1b4a60:      	adrp	x16, 0x1c5000
  1b4a64:      	ldr	x17, [x16, #0xfa8]
  1b4a68:      	add	x16, x16, #0xfa8
  1b4a6c:      	br	x17

00000000001b4a70 <glGetShaderInfoLog@plt>:
  1b4a70:      	adrp	x16, 0x1c5000
  1b4a74:      	ldr	x17, [x16, #0xfb0]
  1b4a78:      	add	x16, x16, #0xfb0
  1b4a7c:      	br	x17

00000000001b4a80 <glDeleteShader@plt>:
  1b4a80:      	adrp	x16, 0x1c5000
  1b4a84:      	ldr	x17, [x16, #0xfb8]
  1b4a88:      	add	x16, x16, #0xfb8
  1b4a8c:      	br	x17

00000000001b4a90 <strcmp@plt>:
  1b4a90:      	adrp	x16, 0x1c5000
  1b4a94:      	ldr	x17, [x16, #0xfc0]
  1b4a98:      	add	x16, x16, #0xfc0
  1b4a9c:      	br	x17

00000000001b4aa0 <glCreateProgram@plt>:
  1b4aa0:      	adrp	x16, 0x1c5000
  1b4aa4:      	ldr	x17, [x16, #0xfc8]
  1b4aa8:      	add	x16, x16, #0xfc8
  1b4aac:      	br	x17

00000000001b4ab0 <glAttachShader@plt>:
  1b4ab0:      	adrp	x16, 0x1c5000
  1b4ab4:      	ldr	x17, [x16, #0xfd0]
  1b4ab8:      	add	x16, x16, #0xfd0
  1b4abc:      	br	x17

00000000001b4ac0 <glLinkProgram@plt>:
  1b4ac0:      	adrp	x16, 0x1c5000
  1b4ac4:      	ldr	x17, [x16, #0xfd8]
  1b4ac8:      	add	x16, x16, #0xfd8
  1b4acc:      	br	x17

00000000001b4ad0 <glGetProgramiv@plt>:
  1b4ad0:      	adrp	x16, 0x1c5000
  1b4ad4:      	ldr	x17, [x16, #0xfe0]
  1b4ad8:      	add	x16, x16, #0xfe0
  1b4adc:      	br	x17

00000000001b4ae0 <glGetProgramInfoLog@plt>:
  1b4ae0:      	adrp	x16, 0x1c5000
  1b4ae4:      	ldr	x17, [x16, #0xfe8]
  1b4ae8:      	add	x16, x16, #0xfe8
  1b4aec:      	br	x17

00000000001b4af0 <__emutls_get_address@plt>:
  1b4af0:      	adrp	x16, 0x1c5000
  1b4af4:      	ldr	x17, [x16, #0xff0]
  1b4af8:      	add	x16, x16, #0xff0
  1b4afc:      	br	x17

00000000001b4b00 <__memcpy_chk@plt>:
  1b4b00:      	adrp	x16, 0x1c5000
  1b4b04:      	ldr	x17, [x16, #0xff8]
  1b4b08:      	add	x16, x16, #0xff8
  1b4b0c:      	br	x17

00000000001b4b10 <AndroidBitmap_getInfo@plt>:
  1b4b10:      	adrp	x16, 0x1c6000
  1b4b14:      	ldr	x17, [x16]
  1b4b18:      	add	x16, x16, #0x0
  1b4b1c:      	br	x17

00000000001b4b20 <AndroidBitmap_lockPixels@plt>:
  1b4b20:      	adrp	x16, 0x1c6000
  1b4b24:      	ldr	x17, [x16, #0x8]
  1b4b28:      	add	x16, x16, #0x8
  1b4b2c:      	br	x17

00000000001b4b30 <AndroidBitmap_unlockPixels@plt>:
  1b4b30:      	adrp	x16, 0x1c6000
  1b4b34:      	ldr	x17, [x16, #0x10]
  1b4b38:      	add	x16, x16, #0x10
  1b4b3c:      	br	x17

00000000001b4b40 <glPixelStorei@plt>:
  1b4b40:      	adrp	x16, 0x1c6000
  1b4b44:      	ldr	x17, [x16, #0x18]
  1b4b48:      	add	x16, x16, #0x18
  1b4b4c:      	br	x17

00000000001b4b50 <__memset_chk@plt>:
  1b4b50:      	adrp	x16, 0x1c6000
  1b4b54:      	ldr	x17, [x16, #0x20]
  1b4b58:      	add	x16, x16, #0x20
  1b4b5c:      	br	x17

00000000001b4b60 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
  1b4b60:      	adrp	x16, 0x1c6000
  1b4b64:      	ldr	x17, [x16, #0x28]
  1b4b68:      	add	x16, x16, #0x28
  1b4b6c:      	br	x17

00000000001b4b70 <realloc@plt>:
  1b4b70:      	adrp	x16, 0x1c6000
  1b4b74:      	ldr	x17, [x16, #0x30]
  1b4b78:      	add	x16, x16, #0x30
  1b4b7c:      	br	x17

00000000001b4b80 <fwrite@plt>:
  1b4b80:      	adrp	x16, 0x1c6000
  1b4b84:      	ldr	x17, [x16, #0x38]
  1b4b88:      	add	x16, x16, #0x38
  1b4b8c:      	br	x17

00000000001b4b90 <glGetIntegerv@plt>:
  1b4b90:      	adrp	x16, 0x1c6000
  1b4b94:      	ldr	x17, [x16, #0x40]
  1b4b98:      	add	x16, x16, #0x40
  1b4b9c:      	br	x17

00000000001b4ba0 <glGetString@plt>:
  1b4ba0:      	adrp	x16, 0x1c6000
  1b4ba4:      	ldr	x17, [x16, #0x48]
  1b4ba8:      	add	x16, x16, #0x48
  1b4bac:      	br	x17

00000000001b4bb0 <_ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev@plt>:
  1b4bb0:      	adrp	x16, 0x1c6000
  1b4bb4:      	ldr	x17, [x16, #0x50]
  1b4bb8:      	add	x16, x16, #0x50
  1b4bbc:      	br	x17

00000000001b4bc0 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
  1b4bc0:      	adrp	x16, 0x1c6000
  1b4bc4:      	ldr	x17, [x16, #0x58]
  1b4bc8:      	add	x16, x16, #0x58
  1b4bcc:      	br	x17

00000000001b4bd0 <_ZNSt6__ndk18ios_base4initEPv@plt>:
  1b4bd0:      	adrp	x16, 0x1c6000
  1b4bd4:      	ldr	x17, [x16, #0x60]
  1b4bd8:      	add	x16, x16, #0x60
  1b4bdc:      	br	x17

00000000001b4be0 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
  1b4be0:      	adrp	x16, 0x1c6000
  1b4be4:      	ldr	x17, [x16, #0x68]
  1b4be8:      	add	x16, x16, #0x68
  1b4bec:      	br	x17

00000000001b4bf0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE6sentryC1ERS3_b@plt>:
  1b4bf0:      	adrp	x16, 0x1c6000
  1b4bf4:      	ldr	x17, [x16, #0x70]
  1b4bf8:      	add	x16, x16, #0x70
  1b4bfc:      	br	x17

00000000001b4c00 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9push_backEc@plt>:
  1b4c00:      	adrp	x16, 0x1c6000
  1b4c04:      	ldr	x17, [x16, #0x78]
  1b4c08:      	add	x16, x16, #0x78
  1b4c0c:      	br	x17

00000000001b4c10 <_ZNSt6__ndk18ios_base5clearEj@plt>:
  1b4c10:      	adrp	x16, 0x1c6000
  1b4c14:      	ldr	x17, [x16, #0x80]
  1b4c18:      	add	x16, x16, #0x80
  1b4c1c:      	br	x17

00000000001b4c20 <__cxa_rethrow@plt>:
  1b4c20:      	adrp	x16, 0x1c6000
  1b4c24:      	ldr	x17, [x16, #0x88]
  1b4c28:      	add	x16, x16, #0x88
  1b4c2c:      	br	x17

00000000001b4c30 <strtol@plt>:
  1b4c30:      	adrp	x16, 0x1c6000
  1b4c34:      	ldr	x17, [x16, #0x90]
  1b4c38:      	add	x16, x16, #0x90
  1b4c3c:      	br	x17

00000000001b4c40 <strncmp@plt>:
  1b4c40:      	adrp	x16, 0x1c6000
  1b4c44:      	ldr	x17, [x16, #0x98]
  1b4c48:      	add	x16, x16, #0x98
  1b4c4c:      	br	x17

00000000001b4c50 <ldexpf@plt>:
  1b4c50:      	adrp	x16, 0x1c6000
  1b4c54:      	ldr	x17, [x16, #0xa0]
  1b4c58:      	add	x16, x16, #0xa0
  1b4c5c:      	br	x17

00000000001b4c60 <powf@plt>:
  1b4c60:      	adrp	x16, 0x1c6000
  1b4c64:      	ldr	x17, [x16, #0xa8]
  1b4c68:      	add	x16, x16, #0xa8
  1b4c6c:      	br	x17

00000000001b4c70 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
  1b4c70:      	adrp	x16, 0x1c6000
  1b4c74:      	ldr	x17, [x16, #0xb0]
  1b4c78:      	add	x16, x16, #0xb0
  1b4c7c:      	br	x17

00000000001b4c80 <pthread_mutex_init@plt>:
  1b4c80:      	adrp	x16, 0x1c6000
  1b4c84:      	ldr	x17, [x16, #0xb8]
  1b4c88:      	add	x16, x16, #0xb8
  1b4c8c:      	br	x17

00000000001b4c90 <pthread_mutex_destroy@plt>:
  1b4c90:      	adrp	x16, 0x1c6000
  1b4c94:      	ldr	x17, [x16, #0xc0]
  1b4c98:      	add	x16, x16, #0xc0
  1b4c9c:      	br	x17

00000000001b4ca0 <pthread_mutex_lock@plt>:
  1b4ca0:      	adrp	x16, 0x1c6000
  1b4ca4:      	ldr	x17, [x16, #0xc8]
  1b4ca8:      	add	x16, x16, #0xc8
  1b4cac:      	br	x17

00000000001b4cb0 <pthread_mutex_unlock@plt>:
  1b4cb0:      	adrp	x16, 0x1c6000
  1b4cb4:      	ldr	x17, [x16, #0xd0]
  1b4cb8:      	add	x16, x16, #0xd0
  1b4cbc:      	br	x17

00000000001b4cc0 <glDeleteRenderbuffers@plt>:
  1b4cc0:      	adrp	x16, 0x1c6000
  1b4cc4:      	ldr	x17, [x16, #0xd8]
  1b4cc8:      	add	x16, x16, #0xd8
  1b4ccc:      	br	x17

00000000001b4cd0 <_ZNSt6__ndk1plIcNS_11char_traitsIcEENS_9allocatorIcEEEENS_12basic_stringIT_T0_T1_EEPKS6_RKS9_@plt>:
  1b4cd0:      	adrp	x16, 0x1c6000
  1b4cd4:      	ldr	x17, [x16, #0xe0]
  1b4cd8:      	add	x16, x16, #0xe0
  1b4cdc:      	br	x17

00000000001b4ce0 <glGenRenderbuffers@plt>:
  1b4ce0:      	adrp	x16, 0x1c6000
  1b4ce4:      	ldr	x17, [x16, #0xe8]
  1b4ce8:      	add	x16, x16, #0xe8
  1b4cec:      	br	x17

00000000001b4cf0 <glBindRenderbuffer@plt>:
  1b4cf0:      	adrp	x16, 0x1c6000
  1b4cf4:      	ldr	x17, [x16, #0xf0]
  1b4cf8:      	add	x16, x16, #0xf0
  1b4cfc:      	br	x17

00000000001b4d00 <glRenderbufferStorage@plt>:
  1b4d00:      	adrp	x16, 0x1c6000
  1b4d04:      	ldr	x17, [x16, #0xf8]
  1b4d08:      	add	x16, x16, #0xf8
  1b4d0c:      	br	x17

00000000001b4d10 <basename@plt>:
  1b4d10:      	adrp	x16, 0x1c6000
  1b4d14:      	ldr	x17, [x16, #0x100]
  1b4d18:      	add	x16, x16, #0x100
  1b4d1c:      	br	x17

00000000001b4d20 <glIsTexture@plt>:
  1b4d20:      	adrp	x16, 0x1c6000
  1b4d24:      	ldr	x17, [x16, #0x108]
  1b4d28:      	add	x16, x16, #0x108
  1b4d2c:      	br	x17

00000000001b4d30 <glIsFramebuffer@plt>:
  1b4d30:      	adrp	x16, 0x1c6000
  1b4d34:      	ldr	x17, [x16, #0x110]
  1b4d38:      	add	x16, x16, #0x110
  1b4d3c:      	br	x17

00000000001b4d40 <exp@plt>:
  1b4d40:      	adrp	x16, 0x1c6000
  1b4d44:      	ldr	x17, [x16, #0x118]
  1b4d48:      	add	x16, x16, #0x118
  1b4d4c:      	br	x17

00000000001b4d50 <log@plt>:
  1b4d50:      	adrp	x16, 0x1c6000
  1b4d54:      	ldr	x17, [x16, #0x120]
  1b4d58:      	add	x16, x16, #0x120
  1b4d5c:      	br	x17

00000000001b4d60 <glIsProgram@plt>:
  1b4d60:      	adrp	x16, 0x1c6000
  1b4d64:      	ldr	x17, [x16, #0x128]
  1b4d68:      	add	x16, x16, #0x128
  1b4d6c:      	br	x17

00000000001b4d70 <glDrawElements@plt>:
  1b4d70:      	adrp	x16, 0x1c6000
  1b4d74:      	ldr	x17, [x16, #0x130]
  1b4d78:      	add	x16, x16, #0x130
  1b4d7c:      	br	x17

00000000001b4d80 <glDeleteBuffers@plt>:
  1b4d80:      	adrp	x16, 0x1c6000
  1b4d84:      	ldr	x17, [x16, #0x138]
  1b4d88:      	add	x16, x16, #0x138
  1b4d8c:      	br	x17

00000000001b4d90 <glGenBuffers@plt>:
  1b4d90:      	adrp	x16, 0x1c6000
  1b4d94:      	ldr	x17, [x16, #0x140]
  1b4d98:      	add	x16, x16, #0x140
  1b4d9c:      	br	x17

00000000001b4da0 <glBindBuffer@plt>:
  1b4da0:      	adrp	x16, 0x1c6000
  1b4da4:      	ldr	x17, [x16, #0x148]
  1b4da8:      	add	x16, x16, #0x148
  1b4dac:      	br	x17

00000000001b4db0 <glBufferData@plt>:
  1b4db0:      	adrp	x16, 0x1c6000
  1b4db4:      	ldr	x17, [x16, #0x150]
  1b4db8:      	add	x16, x16, #0x150
  1b4dbc:      	br	x17

00000000001b4dc0 <glBufferSubData@plt>:
  1b4dc0:      	adrp	x16, 0x1c6000
  1b4dc4:      	ldr	x17, [x16, #0x158]
  1b4dc8:      	add	x16, x16, #0x158
  1b4dcc:      	br	x17

00000000001b4dd0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
  1b4dd0:      	adrp	x16, 0x1c6000
  1b4dd4:      	ldr	x17, [x16, #0x160]
  1b4dd8:      	add	x16, x16, #0x160
  1b4ddc:      	br	x17

00000000001b4de0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm@plt>:
  1b4de0:      	adrp	x16, 0x1c6000
  1b4de4:      	ldr	x17, [x16, #0x168]
  1b4de8:      	add	x16, x16, #0x168
  1b4dec:      	br	x17

00000000001b4df0 <wcslen@plt>:
  1b4df0:      	adrp	x16, 0x1c6000
  1b4df4:      	ldr	x17, [x16, #0x170]
  1b4df8:      	add	x16, x16, #0x170
  1b4dfc:      	br	x17

00000000001b4e00 <setlocale@plt>:
  1b4e00:      	adrp	x16, 0x1c6000
  1b4e04:      	ldr	x17, [x16, #0x178]
  1b4e08:      	add	x16, x16, #0x178
  1b4e0c:      	br	x17

00000000001b4e10 <wcstombs@plt>:
  1b4e10:      	adrp	x16, 0x1c6000
  1b4e14:      	ldr	x17, [x16, #0x180]
  1b4e18:      	add	x16, x16, #0x180
  1b4e1c:      	br	x17

00000000001b4e20 <mbstowcs@plt>:
  1b4e20:      	adrp	x16, 0x1c6000
  1b4e24:      	ldr	x17, [x16, #0x188]
  1b4e28:      	add	x16, x16, #0x188
  1b4e2c:      	br	x17

00000000001b4e30 <swprintf@plt>:
  1b4e30:      	adrp	x16, 0x1c6000
  1b4e34:      	ldr	x17, [x16, #0x190]
  1b4e38:      	add	x16, x16, #0x190
  1b4e3c:      	br	x17

00000000001b4e40 <swscanf@plt>:
  1b4e40:      	adrp	x16, 0x1c6000
  1b4e44:      	ldr	x17, [x16, #0x198]
  1b4e48:      	add	x16, x16, #0x198
  1b4e4c:      	br	x17

00000000001b4e50 <atoll@plt>:
  1b4e50:      	adrp	x16, 0x1c6000
  1b4e54:      	ldr	x17, [x16, #0x1a0]
  1b4e58:      	add	x16, x16, #0x1a0
  1b4e5c:      	br	x17

00000000001b4e60 <wcscpy@plt>:
  1b4e60:      	adrp	x16, 0x1c6000
  1b4e64:      	ldr	x17, [x16, #0x1a8]
  1b4e68:      	add	x16, x16, #0x1a8
  1b4e6c:      	br	x17

00000000001b4e70 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
  1b4e70:      	adrp	x16, 0x1c6000
  1b4e74:      	ldr	x17, [x16, #0x1b0]
  1b4e78:      	add	x16, x16, #0x1b0
  1b4e7c:      	br	x17

00000000001b4e80 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4copyEPcmm@plt>:
  1b4e80:      	adrp	x16, 0x1c6000
  1b4e84:      	ldr	x17, [x16, #0x1b8]
  1b4e88:      	add	x16, x16, #0x1b8
  1b4e8c:      	br	x17

00000000001b4e90 <strtok@plt>:
  1b4e90:      	adrp	x16, 0x1c6000
  1b4e94:      	ldr	x17, [x16, #0x1c0]
  1b4e98:      	add	x16, x16, #0x1c0
  1b4e9c:      	br	x17

00000000001b4ea0 <_ZNSt6__ndk113basic_ostreamIwNS_11char_traitsIwEEE5writeEPKwl@plt>:
  1b4ea0:      	adrp	x16, 0x1c6000
  1b4ea4:      	ldr	x17, [x16, #0x1c8]
  1b4ea8:      	add	x16, x16, #0x1c8
  1b4eac:      	br	x17

00000000001b4eb0 <strtod@plt>:
  1b4eb0:      	adrp	x16, 0x1c6000
  1b4eb4:      	ldr	x17, [x16, #0x1d0]
  1b4eb8:      	add	x16, x16, #0x1d0
  1b4ebc:      	br	x17

00000000001b4ec0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5tellgEv@plt>:
  1b4ec0:      	adrp	x16, 0x1c6000
  1b4ec4:      	ldr	x17, [x16, #0x1d8]
  1b4ec8:      	add	x16, x16, #0x1d8
  1b4ecc:      	br	x17

00000000001b4ed0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE5seekgENS_4fposI9mbstate_tEE@plt>:
  1b4ed0:      	adrp	x16, 0x1c6000
  1b4ed4:      	ldr	x17, [x16, #0x1e0]
  1b4ed8:      	add	x16, x16, #0x1e0
  1b4edc:      	br	x17

00000000001b4ee0 <_ZNSt6__ndk113basic_istreamIcNS_11char_traitsIcEEE4readEPcl@plt>:
  1b4ee0:      	adrp	x16, 0x1c6000
  1b4ee4:      	ldr	x17, [x16, #0x1e8]
  1b4ee8:      	add	x16, x16, #0x1e8
  1b4eec:      	br	x17

00000000001b4ef0 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5tellgEv@plt>:
  1b4ef0:      	adrp	x16, 0x1c6000
  1b4ef4:      	ldr	x17, [x16, #0x1f0]
  1b4ef8:      	add	x16, x16, #0x1f0
  1b4efc:      	br	x17

00000000001b4f00 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5seekgExNS_8ios_base7seekdirE@plt>:
  1b4f00:      	adrp	x16, 0x1c6000
  1b4f04:      	ldr	x17, [x16, #0x1f8]
  1b4f08:      	add	x16, x16, #0x1f8
  1b4f0c:      	br	x17

00000000001b4f10 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE5seekgENS_4fposI9mbstate_tEE@plt>:
  1b4f10:      	adrp	x16, 0x1c6000
  1b4f14:      	ldr	x17, [x16, #0x200]
  1b4f18:      	add	x16, x16, #0x200
  1b4f1c:      	br	x17

00000000001b4f20 <_ZNSt6__ndk113basic_istreamIwNS_11char_traitsIwEEE4readEPwl@plt>:
  1b4f20:      	adrp	x16, 0x1c6000
  1b4f24:      	ldr	x17, [x16, #0x208]
  1b4f28:      	add	x16, x16, #0x208
  1b4f2c:      	br	x17

00000000001b4f30 <ferror@plt>:
  1b4f30:      	adrp	x16, 0x1c6000
  1b4f34:      	ldr	x17, [x16, #0x210]
  1b4f38:      	add	x16, x16, #0x210
  1b4f3c:      	br	x17

00000000001b4f40 <_ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6resizeEmw@plt>:
  1b4f40:      	adrp	x16, 0x1c6000
  1b4f44:      	ldr	x17, [x16, #0x218]
  1b4f48:      	add	x16, x16, #0x218
  1b4f4c:      	br	x17

00000000001b4f50 <_ZNSt9bad_allocC1Ev@plt>:
  1b4f50:      	adrp	x16, 0x1c6000
  1b4f54:      	ldr	x17, [x16, #0x220]
  1b4f58:      	add	x16, x16, #0x220
  1b4f5c:      	br	x17

00000000001b4f60 <_ZNSt9exceptionD2Ev@plt>:
  1b4f60:      	adrp	x16, 0x1c6000
  1b4f64:      	ldr	x17, [x16, #0x228]
  1b4f68:      	add	x16, x16, #0x228
  1b4f6c:      	br	x17

00000000001b4f70 <fmod@plt>:
  1b4f70:      	adrp	x16, 0x1c6000
  1b4f74:      	ldr	x17, [x16, #0x230]
  1b4f78:      	add	x16, x16, #0x230
  1b4f7c:      	br	x17

00000000001b4f80 <strchr@plt>:
  1b4f80:      	adrp	x16, 0x1c6000
  1b4f84:      	ldr	x17, [x16, #0x238]
  1b4f88:      	add	x16, x16, #0x238
  1b4f8c:      	br	x17

00000000001b4f90 <__strchr_chk@plt>:
  1b4f90:      	adrp	x16, 0x1c6000
  1b4f94:      	ldr	x17, [x16, #0x240]
  1b4f98:      	add	x16, x16, #0x240
  1b4f9c:      	br	x17

00000000001b4fa0 <abort@plt>:
  1b4fa0:      	adrp	x16, 0x1c6000
  1b4fa4:      	ldr	x17, [x16, #0x248]
  1b4fa8:      	add	x16, x16, #0x248
  1b4fac:      	br	x17

00000000001b4fb0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
  1b4fb0:      	adrp	x16, 0x1c6000
  1b4fb4:      	ldr	x17, [x16, #0x250]
  1b4fb8:      	add	x16, x16, #0x250
  1b4fbc:      	br	x17

00000000001b4fc0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
  1b4fc0:      	adrp	x16, 0x1c6000
  1b4fc4:      	ldr	x17, [x16, #0x258]
  1b4fc8:      	add	x16, x16, #0x258
  1b4fcc:      	br	x17

00000000001b4fd0 <_ZNSt6__ndk16localeD1Ev@plt>:
  1b4fd0:      	adrp	x16, 0x1c6000
  1b4fd4:      	ldr	x17, [x16, #0x260]
  1b4fd8:      	add	x16, x16, #0x260
  1b4fdc:      	br	x17

00000000001b4fe0 <_ZNSt6__ndk18ios_baseD2Ev@plt>:
  1b4fe0:      	adrp	x16, 0x1c6000
  1b4fe4:      	ldr	x17, [x16, #0x268]
  1b4fe8:      	add	x16, x16, #0x268
  1b4fec:      	br	x17

00000000001b4ff0 <_ZSt18uncaught_exceptionv@plt>:
  1b4ff0:      	adrp	x16, 0x1c6000
  1b4ff4:      	ldr	x17, [x16, #0x270]
  1b4ff8:      	add	x16, x16, #0x270
  1b4ffc:      	br	x17

00000000001b5000 <fflush@plt>:
  1b5000:      	adrp	x16, 0x1c6000
  1b5004:      	ldr	x17, [x16, #0x278]
  1b5008:      	add	x16, x16, #0x278
  1b500c:      	br	x17

00000000001b5010 <fseeko@plt>:
  1b5010:      	adrp	x16, 0x1c6000
  1b5014:      	ldr	x17, [x16, #0x280]
  1b5018:      	add	x16, x16, #0x280
  1b501c:      	br	x17

00000000001b5020 <ftello@plt>:
  1b5020:      	adrp	x16, 0x1c6000
  1b5024:      	ldr	x17, [x16, #0x288]
  1b5028:      	add	x16, x16, #0x288
  1b502c:      	br	x17

00000000001b5030 <getauxval@plt>:
  1b5030:      	adrp	x16, 0x1c6000
  1b5034:      	ldr	x17, [x16, #0x290]
  1b5038:      	add	x16, x16, #0x290
  1b503c:      	br	x17

00000000001b5040 <__system_property_get@plt>:
  1b5040:      	adrp	x16, 0x1c6000
  1b5044:      	ldr	x17, [x16, #0x298]
  1b5048:      	add	x16, x16, #0x298
  1b504c:      	br	x17

00000000001b5050 <fprintf@plt>:
  1b5050:      	adrp	x16, 0x1c6000
  1b5054:      	ldr	x17, [x16, #0x2a0]
  1b5058:      	add	x16, x16, #0x2a0
  1b505c:      	br	x17

00000000001b5060 <pthread_rwlock_wrlock@plt>:
  1b5060:      	adrp	x16, 0x1c6000
  1b5064:      	ldr	x17, [x16, #0x2a8]
  1b5068:      	add	x16, x16, #0x2a8
  1b506c:      	br	x17

00000000001b5070 <pthread_rwlock_unlock@plt>:
  1b5070:      	adrp	x16, 0x1c6000
  1b5074:      	ldr	x17, [x16, #0x2b0]
  1b5078:      	add	x16, x16, #0x2b0
  1b507c:      	br	x17

00000000001b5080 <dl_iterate_phdr@plt>:
  1b5080:      	adrp	x16, 0x1c6000
  1b5084:      	ldr	x17, [x16, #0x2b8]
  1b5088:      	add	x16, x16, #0x2b8
  1b508c:      	br	x17

00000000001b5090 <pthread_rwlock_rdlock@plt>:
  1b5090:      	adrp	x16, 0x1c6000
  1b5094:      	ldr	x17, [x16, #0x2c0]
  1b5098:      	add	x16, x16, #0x2c0
  1b509c:      	br	x17

00000000001b50a0 <getpid@plt>:
  1b50a0:      	adrp	x16, 0x1c6000
  1b50a4:      	ldr	x17, [x16, #0x2c8]
  1b50a8:      	add	x16, x16, #0x2c8
  1b50ac:      	br	x17

00000000001b50b0 <syscall@plt>:
  1b50b0:      	adrp	x16, 0x1c6000
  1b50b4:      	ldr	x17, [x16, #0x2d0]
  1b50b8:      	add	x16, x16, #0x2d0
  1b50bc:      	br	x17
