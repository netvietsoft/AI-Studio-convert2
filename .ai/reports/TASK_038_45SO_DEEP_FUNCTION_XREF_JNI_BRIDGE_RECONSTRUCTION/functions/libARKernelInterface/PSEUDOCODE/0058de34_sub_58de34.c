// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58de34
// Recovered Name: sub_58de34
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58de34 | Size: 180 bytes | SHA256: d4e7dc182740c9eeb6dceef543729344dcfd26272fce8281c5f3efd2f9d29857
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nativeGetEyeShadowType(J)I (table at 0x10d0b38)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "GetEyeShadowType"
//   "arkernel"

jlong sub_58de34(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x58de34 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58de38 */ str x19, [sp, #0x10];
    /* 0x58de3c */ mov x29, sp;
    /* 0x58de40 */ adrp x8, #0x10c5000;
    /* 0x58de44 */ mov x19, x2;
    /* 0x58de48 */ ldr x8, [x8, #0x7a8];
    /* 0x58de4c */ ldr w8, [x8];
    /* 0x58de50 */ cmp w8, #2;
    /* 0x58de54 */ b.gt #0x58de80;
    /* 0x58de58 */ adrp x8, #0x10c5000;
    /* 0x58de5c */ ldr x8, [x8, #0x7c8];
    sub_5a6b20();
    sub_8e0920();
    __dynamic_cast();
    __android_log_print();
    return x0;
}
