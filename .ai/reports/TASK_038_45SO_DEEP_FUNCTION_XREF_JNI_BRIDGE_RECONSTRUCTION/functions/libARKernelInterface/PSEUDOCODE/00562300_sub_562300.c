// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x562300
// Recovered Name: sub_562300
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x562300 | Size: 280 bytes | SHA256: 1246e8e542f8dc4ed3d9f61053790c32318c76d6da6f3435717be35cbfc3f489
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetNeckPoints(JI)[F (table at 0x10cc620)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyPoints illegal index"
//   "arkernel"

jlong sub_562300(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x562300 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x562304 */ stp x22, x21, [sp, #0x10];
    /* 0x562308 */ stp x20, x19, [sp, #0x20];
    /* 0x56230c */ mov x29, sp;
    /* 0x562310 */ cbz x2, #0x5623fc;
    /* 0x562314 */ tbnz w3, #0x1f, #0x56239c;
    /* 0x562318 */ ldr w8, [x2, #0xc];
    /* 0x56231c */ cmp w8, w3;
    /* 0x562320 */ b.le #0x56239c;
    /* 0x562324 */ mov w8, #0x770;
    /* 0x562328 */ umaddl x8, w3, w8, x2;
    return x0;
    sub_5a6b20();
    __android_log_print();
}
