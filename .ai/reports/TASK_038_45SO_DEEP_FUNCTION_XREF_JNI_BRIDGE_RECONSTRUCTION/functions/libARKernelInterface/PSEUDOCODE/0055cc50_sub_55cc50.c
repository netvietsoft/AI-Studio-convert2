// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55cc50
// Recovered Name: sub_55cc50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55cc50 | Size: 2468 bytes | SHA256: 96324959b35d56dfee8fa250a7ca888b5d05ef19b9b2deefafc700819e948e73
// Callers: 1 | Callees: 53 | Imports: 0

// Strings referenced:
//   "JNI_OnLoad error:failed to ARKernelBodySlim3DDataInterfaceJNI"
//   "JNI_OnLoad error:failed to registerARAiStateInterfaceMethods"
//   "JNI_OnLoad error:failed to registerARKernelGroupDataInterfaceMethods"
//   "JNI_OnLoad error:failed to registerARKernelGroupDataMethods"
//   "JNI_OnLoad error:failed to registerAnimalInterfaceMethods"

void sub_55cc50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 617 instructions
    /* 0x55cc50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x55cc54 */ stp x20, x19, [sp, #0x10];
    /* 0x55cc58 */ mov x29, sp;
    /* 0x55cc5c */ mov x0, x2;
    /* 0x55cc60 */ mov x19, x2;
    /* 0x55cc64 */ mov x20, x1;
    sub_570e3c();
    /* 0x55cc6c */ tbnz w0, #0x1f, #0x55cfb8;
    /* 0x55cc70 */ mov x0, x19;
    /* 0x55cc74 */ mov x1, x20;
    sub_55e4bc();
    sub_56ca2c();
    sub_572b88();
    sub_573864();
    sub_56da4c();
    sub_5629e8();
    sub_563948();
    sub_55f200();
    sub_57c6bc();
    sub_5662fc();
    sub_5676e8();
    sub_5695ac();
    sub_579e74();
    sub_55dffc();
    sub_57b0e4();
    sub_578968();
    sub_58b3d4();
    sub_58b154();
    sub_58b5f4();
    sub_58ad14();
    sub_58b9b0();
    sub_565a7c();
    sub_560808();
    sub_57443c();
    sub_57b3a8();
    sub_57b73c();
    sub_57d248();
    sub_57d080();
    sub_58e290();
    sub_58d1f8();
    sub_58c82c();
    sub_58d960();
    sub_58ba4c();
    sub_57d9e0();
    sub_585628();
    sub_589928();
    sub_583ab4();
    sub_581e9c();
    sub_58ed18();
    sub_58be7c();
    sub_57179c();
    sub_58ab94();
    sub_58ac30();
    sub_58a1e4();
    sub_58a6d4();
    sub_58aa40();
    sub_58ab0c();
    sub_58a614();
    sub_58a4a8();
    sub_58e408();
    sub_578e78();
    sub_6975fc();
}
