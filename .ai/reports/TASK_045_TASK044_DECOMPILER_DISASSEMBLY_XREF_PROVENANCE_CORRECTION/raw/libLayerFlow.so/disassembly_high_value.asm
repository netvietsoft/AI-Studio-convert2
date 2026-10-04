// =============================================================================
// HIGH-VALUE DISASSEMBLY: CLFDenseHairProcessor (libLayerFlow.so)
// Binary: libLayerFlow.so (SHA-256: EF8D1581038778B72ABCA3CA8FD5046E49FD44E0465871B023647FE42A582262)
// =============================================================================

// -----------------------------------------------------------------------------
// 1. CLFDenseHairProcessor::decodeHairDyeConfig (XREF 0x3fc088, 0x3fc0e8)
// Error message: 'CLFDenseHairProcessor<%s:%d> 染发素材包中的 config.json 解析失败: %s - %s'
// -----------------------------------------------------------------------------
0x3fc070:  adrp     x0, #0x1d9000
0x3fc074:  add      x0, x0, #0x93c
0x3fc078:  mov      w1, #6
0x3fc07c:  adrp     x2, #0x1e7000
0x3fc080:  add      x2, x2, #0x42b
0x3fc084:  adrp     x3, #0x1dc000
0x3fc088:  add      x3, x3, #0x829
0x3fc08c:  mov      w4, #0x6e
0x3fc090:  mov      x5, x24
0x3fc094:  bl       #0x52a2c0
0x3fc098:  b        #0x3fc0f8
0x3fc09c:  cmp      w24, #3
0x3fc0a0:  b.ne     #0x3fc674
0x3fc0a4:  mov      x0, x19
0x3fc0a8:  bl       #0x52a3c0
0x3fc0ac:  ldrb     w8, [sp, #0x128]
0x3fc0b0:  ldr      x9, [x0]
0x3fc0b4:  ldr      x10, [sp, #0x138]
0x3fc0b8:  tst      w8, #1
0x3fc0bc:  ldr      x8, [x9, #0x10]
0x3fc0c0:  ldr      x9, [sp, #0x30]
0x3fc0c4:  csel     x24, x9, x10, eq
0x3fc0c8:  blr      x8
0x3fc0cc:  mov      x6, x0
0x3fc0d0:  adrp     x0, #0x1d9000
0x3fc0d4:  add      x0, x0, #0x93c
0x3fc0d8:  mov      w1, #6
0x3fc0dc:  adrp     x2, #0x1ea000
0x3fc0e0:  add      x2, x2, #0xe97
0x3fc0e4:  adrp     x3, #0x1dc000
0x3fc0e8:  add      x3, x3, #0x829
0x3fc0ec:  mov      w4, #0x71
0x3fc0f0:  mov      x5, x24
0x3fc0f4:  bl       #0x52a2c0
0x3fc0f8:  mov      w8, #0x3f800000
0x3fc0fc:  str      xzr, [sp, #0x2e8]
0x3fc100:  str      xzr, [sp, #0x2e0]
0x3fc104:  str      xzr, [sp, #0x2f0]
0x3fc108:  str      w8, [sp, #0x2f8]
0x3fc10c:  strb     wzr, [sp, #0x2fc]
0x3fc110:  bl       #0x52a620
0x3fc114:  ldr      x28, [sp, #0x48]
0x3fc118:  adrp     x26, #0x1d9000
0x3fc11c:  add      x26, x26, #0x93c
0x3fc120:  b        #0x3fb6bc
0x3fc124:  mov      x25, x1
0x3fc128:  mov      x19, x0
0x3fc12c:  ldrb     w8, [sp, #0x2e0]

// -----------------------------------------------------------------------------
// 2. CLFDenseHairProcessor::loadHairDyeConfig (XREF 0x3fa328, 0x3fa454)
// Error message: 'CLFDenseHairProcessor<%s:%d> 无法打开染发素材 config 文件: %s/config.json'
// -----------------------------------------------------------------------------
0x3fa438:  ldr      x8, [sp, #0x30]
0x3fa43c:  csel     x5, x8, x9, eq
0x3fa440:  mov      x0, x26
0x3fa444:  mov      w1, #6
0x3fa448:  adrp     x2, #0x1e3000
0x3fa44c:  add      x2, x2, #0xfd1
0x3fa450:  adrp     x3, #0x1de000
0x3fa454:  add      x3, x3, #0xa88
0x3fa458:  mov      w4, #0x25
0x3fa45c:  bl       #0x52a2c0
0x3fa460:  mov      w19, wzr
0x3fa464:  b        #0x3faa84
0x3fa468:  orr      x8, x26, #0xf
0x3fa46c:  add      x24, x8, #1
0x3fa470:  mov      x0, x24
0x3fa474:  bl       #0x52a270
0x3fa478:  orr      x8, x24, #1
0x3fa47c:  mov      x28, x0
0x3fa480:  str      x0, [sp, #0x318]
0x3fa484:  str      x8, [sp, #0x308]
0x3fa488:  str      x26, [sp, #0x310]
0x3fa48c:  ldr      x8, [sp, #0x2f0]
0x3fa490:  ldr      x9, [sp, #0x38]
0x3fa494:  tst      w19, #1
0x3fa498:  mov      x0, x28
0x3fa49c:  mov      x2, x25
0x3fa4a0:  csel     x1, x9, x8, eq
0x3fa4a4:  bl       #0x52a370
0x3fa4a8:  adrp     x8, #0x1e8000
0x3fa4ac:  add      x8, x8, #0x65e
0x3fa4b0:  add      x9, x28, x25
0x3fa4b4:  ldr      x8, [x8]
0x3fa4b8:  strb     wzr, [x9, #0xb]
0x3fa4bc:  str      x8, [x9]
0x3fa4c0:  mov      w8, #0x736a
0x3fa4c4:  movk     w8, #0x6e6f, lsl #16
0x3fa4c8:  stur     w8, [x9, #7]
0x3fa4cc:  ldrb     w8, [sp, #0x308]
0x3fa4d0:  ldr      x9, [sp, #0x318]
0x3fa4d4:  tst      w8, #1
0x3fa4d8:  ldr      x8, [sp, #0x28]
0x3fa4dc:  csel     x0, x8, x9, eq
0x3fa4e0:  bl       #0x52a7c0
0x3fa4e4:  ldr      x28, [sp, #0x48]

