// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ccac
// Recovered Name: sub_58ccac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58ccac | Size: 200 bytes | SHA256: ce197440400739e03ce554b1dbf1147a4e57357e0057acdbb5564f69f3e238d9
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetHairMakingupInfo(JJ)V (table at 0x10d0988)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

jlong sub_58ccac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x58ccac */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58ccb0 */ stp x20, x19, [sp, #0x10];
    /* 0x58ccb4 */ mov x29, sp;
    /* 0x58ccb8 */ cbz x2, #0x58cd48;
    /* 0x58ccbc */ cbz x3, #0x58cd48;
    /* 0x58ccc0 */ mov x0, x2;
    /* 0x58ccc4 */ mov x19, x3;
    /* 0x58ccc8 */ mov x20, x2;
    sub_8e0920();
    /* 0x58ccd0 */ cmp w0, #0x6e;
    /* 0x58ccd4 */ b.ne #0x58cd04;
    __dynamic_cast();
    return x0;
}
