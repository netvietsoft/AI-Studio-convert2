// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c35c
// Recovered Name: sub_58c35c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c35c | Size: 132 bytes | SHA256: bdc689e49370758394785bc5d77ddcd95226911a23e59617679e636d66ba90e6
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetMakeupColorAlpha(J)I (table at 0x10d08c8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "makeupcolor getMakeupColorAlpha"

jlong sub_58c35c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x58c35c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c360 */ str x19, [sp, #0x10];
    /* 0x58c364 */ mov x29, sp;
    /* 0x58c368 */ adrp x8, #0x10c5000;
    /* 0x58c36c */ mov x19, x2;
    /* 0x58c370 */ ldr x8, [x8, #0x7a8];
    /* 0x58c374 */ ldr w8, [x8];
    /* 0x58c378 */ cmp w8, #2;
    /* 0x58c37c */ b.gt #0x58c3a8;
    /* 0x58c380 */ adrp x8, #0x1108000;
    /* 0x58c384 */ add x8, x8, #0x8f8;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
