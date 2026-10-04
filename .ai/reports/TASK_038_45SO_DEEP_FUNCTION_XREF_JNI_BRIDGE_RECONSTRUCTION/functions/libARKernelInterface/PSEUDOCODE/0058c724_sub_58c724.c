// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c724
// Recovered Name: sub_58c724
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c724 | Size: 132 bytes | SHA256: 0e51cc2a627f34f6425d6067ebeb4ef673f8c14c6a28e60f038a9dfb38668b9e
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetMakeupColorOpacity(J)F (table at 0x10d0928)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "makeupcolor getMakeupColorOpacity"

jlong sub_58c724(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x58c724 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c728 */ str x19, [sp, #0x10];
    /* 0x58c72c */ mov x29, sp;
    /* 0x58c730 */ adrp x8, #0x10c5000;
    /* 0x58c734 */ mov x19, x2;
    /* 0x58c738 */ ldr x8, [x8, #0x7a8];
    /* 0x58c73c */ ldr w8, [x8];
    /* 0x58c740 */ cmp w8, #2;
    /* 0x58c744 */ b.gt #0x58c770;
    /* 0x58c748 */ adrp x8, #0x1108000;
    /* 0x58c74c */ add x8, x8, #0x8f8;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
