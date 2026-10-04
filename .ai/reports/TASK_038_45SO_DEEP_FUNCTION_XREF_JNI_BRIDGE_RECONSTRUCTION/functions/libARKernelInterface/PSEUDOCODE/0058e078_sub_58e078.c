// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58e078
// Recovered Name: sub_58e078
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58e078 | Size: 180 bytes | SHA256: d9f9812bc883d82257ba069ab3dc316ba1373fa6f7f00931531f59f20ddd0392
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nativeGetOperation(J)I (table at 0x10d0b80)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "GetEyeShadowType"
//   "arkernel"

jlong sub_58e078(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x58e078 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58e07c */ str x19, [sp, #0x10];
    /* 0x58e080 */ mov x29, sp;
    /* 0x58e084 */ adrp x8, #0x10c5000;
    /* 0x58e088 */ mov x19, x2;
    /* 0x58e08c */ ldr x8, [x8, #0x7a8];
    /* 0x58e090 */ ldr w8, [x8];
    /* 0x58e094 */ cmp w8, #2;
    /* 0x58e098 */ b.gt #0x58e0c4;
    /* 0x58e09c */ adrp x8, #0x10c5000;
    /* 0x58e0a0 */ ldr x8, [x8, #0x7c8];
    sub_5a6b20();
    sub_8e0920();
    __dynamic_cast();
    __android_log_print();
    return x0;
}
