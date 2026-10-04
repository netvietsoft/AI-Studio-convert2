// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5615c0
// Recovered Name: sub_5615c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5615c0 | Size: 104 bytes | SHA256: e26c625d4345df1231bbaa576b3895e4486a0b694b52f8819df95fcf8048df25
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetBodyCount(JI)V (table at 0x10cc518)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::SetBodyCount exceed max body count"
//   "arkernel"

jlong sub_5615c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x5615c0 */ cmp w3, #0xb;
    /* 0x5615c4 */ b.lt #0x561604;
    /* 0x5615c8 */ adrp x8, #0x10d0000;
    /* 0x5615cc */ add x8, x8, #0xc30;
    /* 0x5615d0 */ ldr w8, [x8];
    /* 0x5615d4 */ cmp w8, #5;
    /* 0x5615d8 */ b.gt #0x56160c;
    /* 0x5615dc */ adrp x8, #0x1108000;
    /* 0x5615e0 */ add x8, x8, #0x8f8;
    /* 0x5615e4 */ ldr x8, [x8];
    /* 0x5615e8 */ cbz x8, #0x561610;
    return x0;
}
