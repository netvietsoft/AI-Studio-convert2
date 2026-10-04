// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e610
// Recovered Name: sub_56e610
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e610 | Size: 112 bytes | SHA256: 6abcf1cbc28783834c7a85923074d730ecfd45df92c413047fb3597ea14749c7
// Callers: 0 | Callees: 2 | Imports: 1

// Dynamic Registration: nativeIsStopedSoundService()Z (table at 0x10cd4f0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelGlobalInterfaceJNI::IsStopedSoundService"
//   "arkernel"

jlong sub_56e610(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 28 instructions
    /* 0x56e610 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x56e614 */ mov x29, sp;
    /* 0x56e618 */ adrp x8, #0x10d0000;
    /* 0x56e61c */ add x8, x8, #0xc30;
    /* 0x56e620 */ ldr w8, [x8];
    /* 0x56e624 */ cmp w8, #2;
    /* 0x56e628 */ b.gt #0x56e670;
    /* 0x56e62c */ adrp x8, #0x1108000;
    /* 0x56e630 */ add x8, x8, #0x8f8;
    /* 0x56e634 */ ldr x8, [x8];
    /* 0x56e638 */ cbz x8, #0x56e658;
    sub_5a6b20();
    __android_log_print();
    sub_6061cc();
    return x0;
}
