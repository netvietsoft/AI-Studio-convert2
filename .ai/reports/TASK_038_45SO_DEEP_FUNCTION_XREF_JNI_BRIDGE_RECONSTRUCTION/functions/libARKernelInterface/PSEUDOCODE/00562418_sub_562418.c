// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x562418
// Recovered Name: sub_562418
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x562418 | Size: 292 bytes | SHA256: f1095e89d1354276addf9a7fb01f9c8c59102f553202337f486eaf619d1d38a9
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetNeckScores(JI)[F (table at 0x10cc638)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyScores illegal index"
//   "arkernel"

jlong sub_562418(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x562418 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x56241c */ stp x22, x21, [sp, #0x10];
    /* 0x562420 */ stp x20, x19, [sp, #0x20];
    /* 0x562424 */ mov x29, sp;
    /* 0x562428 */ cbz x2, #0x562520;
    /* 0x56242c */ tbnz w3, #0x1f, #0x5624b0;
    /* 0x562430 */ ldr w8, [x2, #0xc];
    /* 0x562434 */ cmp w8, w3;
    /* 0x562438 */ b.le #0x5624b0;
    /* 0x56243c */ mov w8, #0x770;
    /* 0x562440 */ ldr x9, [x0];
    return x0;
    sub_5a6b20();
    __android_log_print();
}
