// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d35c
// Recovered Name: sub_58d35c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58d35c | Size: 180 bytes | SHA256: 5d37fe7323a3ec48922ff11a7bdcb9ebc49b88bcb9cf00102369051a712c7fa6
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nativeGetEnableOption(J)I (table at 0x10d0a48)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "GetEnableOption: Not CPT_SlimV2 Type"
//   "arkernel"

jlong sub_58d35c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x58d35c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58d360 */ str x19, [sp, #0x10];
    /* 0x58d364 */ mov x29, sp;
    /* 0x58d368 */ cbz x2, #0x58d400;
    /* 0x58d36c */ mov x0, x2;
    /* 0x58d370 */ mov x19, x2;
    sub_8e0920();
    /* 0x58d378 */ cmp w0, #0x13e;
    /* 0x58d37c */ b.ne #0x58d3a8;
    /* 0x58d380 */ adrp x1, #0x10c5000;
    /* 0x58d384 */ adrp x2, #0x10c5000;
    __dynamic_cast();
    sub_5a6b20();
    __android_log_print();
    return x0;
}
