// =============================================================================
// HIGH-VALUE DISASSEMBLY: MTSoftHairFilter & CMTFilterSoftHair Pipeline
// Binary: libMTFilterKernel.so (SHA-256: F938FE73095FCEBA72875D1AB42F8AEB6A9F31F3933831BEC070404C0E7ECAC4)
// Toolchain: LLVM 19 / Capstone ARM64
// =============================================================================

// -----------------------------------------------------------------------------
// 1. MTFilterKernel::MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates
// Address: 0x0f3f58 | Host FBO Orchestration Method
// -----------------------------------------------------------------------------
0x0f3f58:  sub      sp, sp, #0xb0
0x0f3f5c:  stp      x29, x30, [sp, #0x50]
0x0f3f60:  str      x27, [sp, #0x60]
0x0f3f64:  stp      x26, x25, [sp, #0x70]
0x0f3f68:  stp      x24, x23, [sp, #0x80]
0x0f3f6c:  stp      x22, x21, [sp, #0x90]
0x0f3f70:  stp      x20, x19, [sp, #0xa0]
0x0f3f74:  add      x29, sp, #0x50
0x0f3f78:  mrs      x26, tpidr_el0
0x0f3f7c:  mov      x19, x4
0x0f3f80:  mov      x22, x3
0x0f3f84:  ldr      x8, [x26, #0x28]
0x0f3f88:  mov      x20, x0
0x0f3f8c:  mov      x21, x1
0x0f3f90:  stur     x8, [x29, #-8]
0x0f3f94:  ldr      x8, [x0, #0x1e8]
0x0f3f98:  cbz      x8, #0xf405c
0x0f3f9c:  ldr      x4, [x20, #0x1e8]
0x0f3fa0:  mov      x0, x20
0x0f3fa4:  mov      x1, x21
0x0f3fa8:  mov      x3, x22
0x0f3fac:  bl       #0xf42fc
0x0f3fb0:  ldr      x3, [x20, #0x1e8]
0x0f3fb4:  ldr      x4, [x20, #0x1f8]
0x0f3fb8:  mov      x0, x20
0x0f3fbc:  mov      x1, x21
0x0f3fc0:  bl       #0xf4400
0x0f3fc4:  ldr      x3, [x20, #0x1f8]
0x0f3fc8:  ldr      x4, [x20, #0x208]
0x0f3fcc:  mov      x0, x20
0x0f3fd0:  mov      x1, x21
0x0f3fd4:  bl       #0xf4528
0x0f3fd8:  ldr      x3, [x20, #0x208]
0x0f3fdc:  ldr      x4, [x20, #0x218]
0x0f3fe0:  mov      x0, x20
0x0f3fe4:  mov      x1, x21
0x0f3fe8:  bl       #0xf46d0
0x0f3fec:  ldr      x8, [x20, #0x60]
0x0f3ff0:  ldr      x9, [x20, #0x218]
0x0f3ff4:  mov      x0, x20
0x0f3ff8:  ldr      w3, [x22, #0xc]
0x0f3ffc:  mov      x1, x21
0x0f4000:  mov      x6, x19
0x0f4004:  ldr      x8, [x8, #0x188]
0x0f4008:  ldr      w4, [x9, #0xc]
0x0f400c:  mov      w9, #0x44a00000
0x0f4010:  fmov     s1, w9
0x0f4014:  ldr      w5, [x8, #0x50]
0x0f4018:  mov      w8, #0x8000
0x0f401c:  movk     w8, #0x4470, lsl #16
0x0f4020:  fmov     s0, w8
0x0f4024:  bl       #0xf4878
0x0f4028:  ldr      x8, [x26, #0x28]
0x0f402c:  ldur     x9, [x29, #-8]
0x0f4030:  cmp      x8, x9
0x0f4034:  b.ne     #0xf42f8
0x0f4038:  mov      x0, x19
0x0f403c:  ldp      x20, x19, [sp, #0xa0]
0x0f4040:  ldr      x27, [sp, #0x60]
0x0f4044:  ldp      x22, x21, [sp, #0x90]
0x0f4048:  ldp      x24, x23, [sp, #0x80]
0x0f404c:  ldp      x26, x25, [sp, #0x70]
0x0f4050:  ldp      x29, x30, [sp, #0x50]
0x0f4054:  add      sp, sp, #0xb0
0x0f4058:  ret      

// -----------------------------------------------------------------------------
// 2. MTFilterKernel::MTSoftHairFilter::grayFilterToFBO
// Address: 0x0f42fc | Luminance Map Extraction Pass
// -----------------------------------------------------------------------------
0x0f42fc:  stp      x29, x30, [sp, #-0x30]!
0x0f4300:  stp      x22, x21, [sp, #0x10]
0x0f4304:  stp      x20, x19, [sp, #0x20]
0x0f4308:  mov      x29, sp
0x0f430c:  mov      x20, x0
0x0f4310:  ldr      x19, [x0, #0x1c8]
0x0f4314:  mov      x0, x4
0x0f4318:  mov      x21, x3
0x0f431c:  mov      x22, x1
0x0f4320:  bl       #0x1644f0
0x0f4324:  mov      w0, #0x4000
0x0f4328:  bl       #0x1b4590
0x0f432c:  mov      x0, x19
0x0f4330:  bl       #0x167f68
0x0f4334:  mov      w0, #0x84c2
0x0f4338:  bl       #0x1b4780
0x0f433c:  ldr      w1, [x21, #0xc]
0x0f4340:  mov      w0, #0xde1
0x0f4344:  bl       #0x1b46f0
0x0f4348:  adrp     x1, #0x88000
0x0f434c:  add      x1, x1, #0x53d
0x0f4350:  mov      x0, x19
0x0f4354:  mov      w2, #2
0x0f4358:  mov      w3, #1
0x0f435c:  bl       #0x1685b0
0x0f4360:  ldr      x0, [x20, #0x60]
0x0f4364:  adrp     x21, #0x77000
0x0f4368:  add      x21, x21, #0xaa9
0x0f436c:  mov      x1, x22
0x0f4370:  mov      w2, #2
0x0f4374:  mov      w3, #4
0x0f4378:  mov      w4, wzr
0x0f437c:  mov      x5, x21
0x0f4380:  mov      x6, x20
0x0f4384:  mov      w7, #0xfd
0x0f4388:  bl       #0x15f808

// -----------------------------------------------------------------------------
// 3. MTFilterKernel::MTSoftHairFilter::hairMaskFilterToFBO
// Address: 0x0f4400 | Hair Mask Isolation Pass
// -----------------------------------------------------------------------------
0x0f4400:  stp      x29, x30, [sp, #-0x30]!
0x0f4404:  stp      x22, x21, [sp, #0x10]
0x0f4408:  stp      x20, x19, [sp, #0x20]
0x0f440c:  mov      x29, sp
0x0f4410:  mov      x20, x0
0x0f4414:  ldr      x19, [x0, #0x1d0]
0x0f4418:  mov      x0, x4
0x0f441c:  mov      x21, x3
0x0f4420:  mov      x22, x1
0x0f4424:  bl       #0x1644f0
0x0f4428:  mov      w0, #0x4000
0x0f442c:  bl       #0x1b4590
0x0f4430:  mov      x0, x19
0x0f4434:  bl       #0x167f68
0x0f4438:  fmov     s1, #1.00000000
0x0f443c:  ldp      s0, s2, [x21, #0x14]
0x0f4440:  adrp     x1, #0x7d000
0x0f4444:  add      x1, x1, #0xa97
0x0f4448:  mov      x0, x19
0x0f444c:  mov      w2, #1
0x0f4450:  fdiv     s0, s1, s0
0x0f4454:  fdiv     s1, s1, s2
0x0f4458:  bl       #0x168890
0x0f445c:  mov      w0, #0x84c2
0x0f4460:  bl       #0x1b4780
0x0f4464:  ldr      w1, [x21, #0xc]
0x0f4468:  mov      w0, #0xde1
0x0f446c:  bl       #0x1b46f0
0x0f4470:  adrp     x1, #0x88000
0x0f4474:  add      x1, x1, #0x53d
0x0f4478:  mov      x0, x19
0x0f447c:  mov      w2, #2
0x0f4480:  mov      w3, #1
0x0f4484:  bl       #0x1685b0
0x0f4488:  ldr      x0, [x20, #0x60]
0x0f448c:  adrp     x21, #0x77000

// -----------------------------------------------------------------------------
// 4. MTFilterKernel::MTSoftHairFilter::blurHFilterToFBO
// Address: 0x0f4528 | Horizontal Separable Gaussian Filter Pass
// Weights at 0x8edd8: (0.15967600047588348, 0.2633480131626129, 0.12211800366640091, 0.030572999268770218)
// Offsets at 0x8edc4: (0.0, 0.0022499999031424522, 0.0052559999749064445, 0.00827100034803152)
// -----------------------------------------------------------------------------
0x0f4528:  sub      sp, sp, #0x80
0x0f452c:  stp      x29, x30, [sp, #0x40]
0x0f4530:  str      x23, [sp, #0x50]
0x0f4534:  stp      x22, x21, [sp, #0x60]
0x0f4538:  stp      x20, x19, [sp, #0x70]
0x0f453c:  add      x29, sp, #0x40
0x0f4540:  mrs      x23, tpidr_el0
0x0f4544:  mov      x20, x0
0x0f4548:  mov      x22, x3
0x0f454c:  ldr      x8, [x23, #0x28]
0x0f4550:  mov      x21, x1
0x0f4554:  stur     x8, [x29, #-8]
0x0f4558:  ldr      x19, [x0, #0x1d8]
0x0f455c:  mov      x0, x4
0x0f4560:  bl       #0x1644f0
0x0f4564:  mov      w0, #0x4000
0x0f4568:  bl       #0x1b4590
0x0f456c:  nop      
0x0f4570:  adr      x8, #0x8edd8
0x0f4574:  mov      w9, #0x11d8
0x0f4578:  ldr      q0, [x8]
0x0f457c:  nop      
0x0f4580:  adr      x8, #0x8edc4
0x0f4584:  ldr      q1, [x8]
0x0f4588:  mov      w8, #0x1f71
0x0f458c:  movk     w9, #0x3b87, lsl #16
0x0f4590:  movk     w8, #0x3c39, lsl #16
0x0f4594:  mov      x0, x19
0x0f4598:  str      w9, [sp, #0x30]
0x0f459c:  str      q0, [sp, #0x20]
0x0f45a0:  str      q1, [sp]
0x0f45a4:  str      w8, [sp, #0x10]
0x0f45a8:  bl       #0x167f68
0x0f45ac:  adrp     x1, #0x8d000
0x0f45b0:  add      x1, x1, #0xe5
0x0f45b4:  add      x2, sp, #0x20
0x0f45b8:  mov      x0, x19
0x0f45bc:  mov      w3, #5
0x0f45c0:  mov      w4, #1
0x0f45c4:  bl       #0x168afc

// -----------------------------------------------------------------------------
// 5. MTFilterKernel::MTSoftHairFilter::blurVFilterToFBO
// Address: 0x0f46d0 | Vertical Separable Gaussian Filter Pass
// Weights at 0x8edd8: (0.15967600047588348, 0.2633480131626129, 0.12211800366640091, 0.030572999268770218)
// Offsets at 0x8edec: (0.0, 0.002993999980390072, 0.00699299992993474, 0.011005000211298466)
// -----------------------------------------------------------------------------
0x0f46d0:  sub      sp, sp, #0x80
0x0f46d4:  stp      x29, x30, [sp, #0x40]
0x0f46d8:  str      x23, [sp, #0x50]
0x0f46dc:  stp      x22, x21, [sp, #0x60]
0x0f46e0:  stp      x20, x19, [sp, #0x70]
0x0f46e4:  add      x29, sp, #0x40
0x0f46e8:  mrs      x23, tpidr_el0
0x0f46ec:  mov      x20, x0
0x0f46f0:  mov      x22, x3
0x0f46f4:  ldr      x8, [x23, #0x28]
0x0f46f8:  mov      x21, x1
0x0f46fc:  stur     x8, [x29, #-8]
0x0f4700:  ldr      x19, [x0, #0x1e0]
0x0f4704:  mov      x0, x4
0x0f4708:  bl       #0x1644f0
0x0f470c:  mov      w0, #0x4000
0x0f4710:  bl       #0x1b4590
0x0f4714:  nop      
0x0f4718:  adr      x8, #0x8edd8
0x0f471c:  mov      w9, #0x11d8
0x0f4720:  ldr      q0, [x8]
0x0f4724:  nop      
0x0f4728:  adr      x8, #0x8edec
0x0f472c:  ldr      q1, [x8]
0x0f4730:  mov      w8, #0x512b
0x0f4734:  movk     w9, #0x3b87, lsl #16
0x0f4738:  movk     w8, #0x3c76, lsl #16
0x0f473c:  mov      x0, x19
0x0f4740:  str      w9, [sp, #0x30]
0x0f4744:  str      q0, [sp, #0x20]
0x0f4748:  str      q1, [sp]
0x0f474c:  str      w8, [sp, #0x10]
0x0f4750:  bl       #0x167f68
0x0f4754:  adrp     x1, #0x8d000
0x0f4758:  add      x1, x1, #0xe5
0x0f475c:  add      x2, sp, #0x20
0x0f4760:  mov      x0, x19
0x0f4764:  mov      w3, #5
0x0f4768:  mov      w4, #1
0x0f476c:  bl       #0x168afc

// -----------------------------------------------------------------------------
// 6. MTFilterKernel::MTSoftHairFilter::softHairFilterToFBO
// Address: 0x0f4878 | Final Hair Soft Filter Shader Invocation
// -----------------------------------------------------------------------------
0x0f4878:  sub      sp, sp, #0x90
0x0f487c:  stp      d9, d8, [sp, #0x30]
0x0f4880:  stp      x29, x30, [sp, #0x40]
0x0f4884:  str      x25, [sp, #0x50]
0x0f4888:  stp      x24, x23, [sp, #0x60]
0x0f488c:  stp      x22, x21, [sp, #0x70]
0x0f4890:  stp      x20, x19, [sp, #0x80]
0x0f4894:  add      x29, sp, #0x40
0x0f4898:  mrs      x25, tpidr_el0
0x0f489c:  mov      x19, x0
0x0f48a0:  fmov     s8, s1
0x0f48a4:  ldr      x8, [x25, #0x28]
0x0f48a8:  fmov     s9, s0
0x0f48ac:  mov      w22, w5
0x0f48b0:  mov      w23, w4
0x0f48b4:  mov      w24, w3
0x0f48b8:  mov      x21, x1
0x0f48bc:  stur     x8, [x29, #-0x18]
0x0f48c0:  ldr      x20, [x0, #0x68]
0x0f48c4:  mov      x0, x6
0x0f48c8:  bl       #0x1644f0
0x0f48cc:  mov      w0, #0x4000
0x0f48d0:  bl       #0x1b4590
0x0f48d4:  nop      
0x0f48d8:  adr      x8, #0x8ee00
0x0f48dc:  mov      x0, x20
0x0f48e0:  ldp      q0, q1, [x8]
0x0f48e4:  ldr      x8, [x8, #0x20]
0x0f48e8:  str      x8, [sp, #0x20]
0x0f48ec:  stp      q0, q1, [sp]
0x0f48f0:  bl       #0x167f68
0x0f48f4:  ldr      s0, [x19, #0x228]
0x0f48f8:  adrp     x1, #0x76000
0x0f48fc:  add      x1, x1, #0x37a
0x0f4900:  mov      x0, x20
0x0f4904:  mov      w2, #1
0x0f4908:  bl       #0x1687dc
0x0f490c:  ldr      s0, [x19, #0x22c]
0x0f4910:  adrp     x1, #0x80000
0x0f4914:  add      x1, x1, #0x4f7
0x0f4918:  mov      x0, x20
0x0f491c:  mov      w2, #1
0x0f4920:  bl       #0x1687dc
0x0f4924:  fmov     s1, #1.00000000
0x0f4928:  adrp     x1, #0x7d000
0x0f492c:  add      x1, x1, #0xa97
0x0f4930:  mov      x0, x20
0x0f4934:  mov      w2, #1

// -----------------------------------------------------------------------------
// 7. MTFilterKernel::CMTFilterSoftHair::FilterToFBO
// Address: 0x1344e8 | Dynamic Filter Architecture FBO Pipeline
// -----------------------------------------------------------------------------
0x1344e8:  stp      x29, x30, [sp, #-0x60]!
0x1344ec:  stp      x28, x27, [sp, #0x10]
0x1344f0:  stp      x26, x25, [sp, #0x20]
0x1344f4:  stp      x24, x23, [sp, #0x30]
0x1344f8:  stp      x22, x21, [sp, #0x40]
0x1344fc:  stp      x20, x19, [sp, #0x50]
0x134500:  mov      x29, sp
0x134504:  sub      sp, sp, #0x250
0x134508:  stp      w2, w3, [sp]
0x13450c:  mrs      x8, tpidr_el0
0x134510:  mov      x19, x0
0x134514:  str      x8, [sp, #8]
0x134518:  mov      w22, w1
0x13451c:  ldr      x8, [x8, #0x28]
0x134520:  stur     x8, [x29, #-0x10]
0x134524:  ldr      x8, [x0, #0x90]
0x134528:  ldp      x8, x9, [x8, #0x58]
0x13452c:  sub      x8, x9, x8
0x134530:  mov      x9, #0x128d
0x134534:  movk     x9, #0xa33f, lsl #16
0x134538:  asr      x8, x8, #3
0x13453c:  movk     x9, #0xcfc4, lsl #32
0x134540:  movk     x9, #0xf128, lsl #48
0x134544:  mul      x8, x8, x9
0x134548:  cmp      w8, #1
0x13454c:  b.lt     #0x134674
0x134550:  and      x8, x8, #0xffffffff
0x134554:  mov      w9, #0x228
0x134558:  mov      x20, #0x6874
0x13455c:  umull    x26, w8, w9
0x134560:  movk     x20, #0x6572, lsl #16
0x134564:  add      x25, sp, #0x10
0x134568:  mov      w28, #0x6167
0x13456c:  movk     x20, #0x6873, lsl #32
0x134570:  mov      x24, xzr
0x134574:  orr      x27, x25, #1
0x134578:  movk     w28, #0x6e69, lsl #16
0x13457c:  movk     x20, #0x6c6f, lsl #48
0x134580:  mov      w23, #0x64
0x134584:  b        #0x134594
0x134588:  add      x24, x24, #0x228
0x13458c:  cmp      x26, x24
0x134590:  b.eq     #0x134674
0x134594:  ldr      x8, [x19, #0x90]
0x134598:  ldr      x21, [x8, #0x58]
0x13459c:  add      x8, x21, x24
0x1345a0:  ldrb     w9, [x8]
0x1345a4:  tbnz     w9, #0, #0x1345bc
0x1345a8:  ldr      x9, [x8, #0x10]
0x1345ac:  ldr      q0, [x8]
0x1345b0:  str      x9, [sp, #0x20]
0x1345b4:  str      q0, [sp, #0x10]
0x1345b8:  b        #0x1345c8
0x1345bc:  ldp      x2, x1, [x8, #8]
0x1345c0:  add      x0, sp, #0x10
0x1345c4:  bl       #0xc8b5c
0x1345c8:  add      x8, x21, x24
0x1345cc:  add      x0, x25, #0x18
0x1345d0:  mov      w2, #0x20c
0x1345d4:  add      x1, x8, #0x18
0x1345d8:  bl       #0x1b4290
0x1345dc:  ldrb     w8, [sp, #0x10]
0x1345e0:  ldr      x9, [sp, #0x18]
0x1345e4:  lsr      x10, x8, #1
0x1345e8:  tst      w8, #1
0x1345ec:  csel     x9, x10, x9, eq
0x1345f0:  cmp      x9, #4
0x1345f4:  b.eq     #0x134638
0x1345f8:  cmp      x9, #9
0x1345fc:  b.ne     #0x134664
0x134600:  ldr      x9, [sp, #0x20]
0x134604:  tst      w8, #1
0x134608:  csel     x9, x27, x9, eq
0x13460c:  ldr      x10, [x9]
0x134610:  ldrb     w9, [x9, #8]
0x134614:  cmp      x10, x20
0x134618:  ccmp     w9, w23, #0, eq
0x13461c:  b.ne     #0x134664
0x134620:  ldr      s1, [x19, #0x140]
0x134624:  ldr      s0, [sp, #0x2c]
0x134628:  fcmp     s1, s0
0x13462c:  b.eq     #0x134664
0x134630:  str      s0, [x19, #0x140]
0x134634:  b        #0x134664
0x134638:  ldr      x9, [sp, #0x20]
0x13463c:  tst      w8, #1
0x134640:  csel     x9, x27, x9, eq
0x134644:  ldr      w9, [x9]
0x134648:  cmp      w9, w28
0x13464c:  b.ne     #0x134664
0x134650:  ldr      s1, [x19, #0x144]
0x134654:  ldr      s0, [sp, #0x2c]
0x134658:  fcmp     s1, s0
0x13465c:  b.eq     #0x134664
0x134660:  str      s0, [x19, #0x144]
0x134664:  tbz      w8, #0, #0x134588
0x134668:  ldr      x0, [sp, #0x20]
0x13466c:  bl       #0x1b42e0
0x134670:  b        #0x134588
0x134674:  ldr      w8, [x19, #0x3c]
0x134678:  ldr      w9, [sp]
0x13467c:  cmp      w8, w22
0x134680:  b.ne     #0x134690
0x134684:  ldr      w8, [x19, #0x40]
0x134688:  cmp      w8, w9
0x13468c:  b.eq     #0x1346e8
0x134690:  adrp     x8, #0x8d000
0x134694:  mov      x0, x19
0x134698:  stp      w22, w9, [x19, #0x3c]
0x13469c:  ldr      q0, [x8, #0x5d0]
0x1346a0:  stur     q0, [x19, #0xe8]
0x1346a4:  bl       #0x1341bc
0x1346a8:  ldp      w1, w2, [x19, #0xf0]
0x1346ac:  add      x3, x19, #0x100
0x1346b0:  add      x4, x19, #0x104
0x1346b4:  bl       #0x1347ac
0x1346b8:  ldp      w1, w2, [x19, #0xf0]
0x1346bc:  add      x3, x19, #0x110
0x1346c0:  add      x4, x19, #0x114
0x1346c4:  bl       #0x1347ac
0x1346c8:  ldp      w1, w2, [x19, #0xe8]
0x1346cc:  add      x3, x19, #0x120
0x1346d0:  add      x4, x19, #0x124
0x1346d4:  bl       #0x1347ac
0x1346d8:  ldp      w1, w2, [x19, #0xe8]
0x1346dc:  add      x3, x19, #0x130
0x1346e0:  add      x4, x19, #0x134
0x1346e4:  bl       #0x1347ac
0x1346e8:  ldr      x8, [x19, #0x78]
0x1346ec:  ldr      w2, [x19, #0x100]
0x1346f0:  mov      x0, x19
0x1346f4:  ldp      w3, w4, [x19, #0xf0]
0x1346f8:  ldr      w1, [x8]
0x1346fc:  bl       #0x13488c
0x134700:  ldp      w3, w4, [x19, #0xf0]
0x134704:  ldr      w1, [x19, #0x104]
0x134708:  ldr      w2, [x19, #0x110]
0x13470c:  mov      x0, x19
0x134710:  bl       #0x134970
0x134714:  ldp      w3, w4, [x19, #0xe8]
0x134718:  ldr      w1, [x19, #0x114]
0x13471c:  ldr      w2, [x19, #0x120]
0x134720:  mov      x0, x19
0x134724:  bl       #0x134a90
0x134728:  ldp      w3, w4, [x19, #0xe8]
0x13472c:  ldr      w1, [x19, #0x124]
0x134730:  ldr      w2, [x19, #0x130]
0x134734:  mov      x0, x19
0x134738:  bl       #0x134c10
0x13473c:  ldr      x8, [x19, #0x78]
0x134740:  ldr      w2, [x19, #0x134]
0x134744:  mov      x0, x19
0x134748:  ldp      w5, w6, [x19, #0x3c]
0x13474c:  ldr      w3, [x19, #0x148]
0x134750:  ldr      w1, [x8]
0x134754:  ldr      w4, [x19, #0xa0]
0x134758:  bl       #0x134d90
0x13475c:  ldr      w21, [x19, #0xa4]
0x134760:  ldr      w8, [sp, #4]
0x134764:  tbz      w8, #0, #0x134770
0x134768:  mov      x0, x19
0x13476c:  bl       #0x11de88
0x134770:  ldr      x8, [sp, #8]
0x134774:  ldr      x8, [x8, #0x28]
0x134778:  ldur     x9, [x29, #-0x10]
0x13477c:  cmp      x8, x9
0x134780:  b.ne     #0x1347a8
0x134784:  mov      w0, w21
0x134788:  add      sp, sp, #0x250
0x13478c:  ldp      x20, x19, [sp, #0x50]
0x134790:  ldp      x22, x21, [sp, #0x40]
0x134794:  ldp      x24, x23, [sp, #0x30]
0x134798:  ldp      x26, x25, [sp, #0x20]
0x13479c:  ldp      x28, x27, [sp, #0x10]
0x1347a0:  ldp      x29, x30, [sp], #0x60
0x1347a4:  ret      

// -----------------------------------------------------------------------------
// 8. VERBATIM EMBEDDED GLSL SHADER SOURCE (MTSoftHairFilter.cpp @ .rodata 0x77b00)
// -----------------------------------------------------------------------------
/*
precision highp float; varying vec2 texCoord; uniform sampler2D inputImageTexture; uniform sampler2D inputImageMaskTexture; uniform sampler2D blurImageTexture; uniform float texWidthOffset; uniform float texHeightOffset; uniform int mode; void main() { lowp vec4 color = texture2D(inputImageTexture, texCoord); lowp vec4 maskColor = texture2D(inputImageMaskTexture, texCoord); lowp vec3 resultColor = color.rgb; lowp float mixture = maskColor.a; if (mode == 1) { mixture = maskColor.r; } if(mixture > 0.005) { vec2 horizontalStep = vec2(texWidthOffset, 0.0) * 2.3; vec2 verticalStep = vec2(0.0, texHeightOffset) * 2.3; vec3 sumColor = vec3(0.0, 0.0, 0.0); for(float t = -4.0; t < 4.5; t += 1.0) { for(float p = -4.0;p < 4.5; p += 1.0) { sumColor += texture2D(inputImageTexture,texCoord + t * horizontalStep + p * verticalStep).rgb; } } sumColor = sumColor * 0.0123; sumColor = clamp(sumColor + (color.rgb - sumColor) * 1.8, 0.0, 1.0); sumColor = max(color.rgb, sumColor); lowp vec3 blurColor = texture2D(blurImageTexture, texCoord).rgb; lowp vec3 diffColor = color.rgb - blurColor; diffColor = min(diffColor, 0.0); lowp float clarity = 0.4; sumColor += (diffColor + 0.015) * clarity; sumColor = clamp(sumColor, 0.0,1.0); resultColor = sumColor; } gl_FragColor = vec4(resultColor, 1.0); }
*/
