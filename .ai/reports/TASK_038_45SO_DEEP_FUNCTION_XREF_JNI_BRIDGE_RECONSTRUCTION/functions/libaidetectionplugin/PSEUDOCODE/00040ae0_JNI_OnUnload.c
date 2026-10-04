// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x40ae0
// Recovered Name: JNI_OnUnload
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x40ae0 | Size: 68 bytes | SHA256: 5f560787add923e12b3cc7323095ad0cec4b4286f259f0b76839175a3ca966ea
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "JNI_OnUnload"

jlong JNI_OnUnload(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x40ae0 */ adrp x8, #0x82000;
    /* 0x40ae4 */ ldr x8, [x8, #0xd50];
    /* 0x40ae8 */ ldr w8, [x8];
    /* 0x40aec */ cmp w8, #5;
    /* 0x40af0 */ b.gt #0x40b20;
    /* 0x40af4 */ adrp x8, #0x82000;
    /* 0x40af8 */ nop ;
    /* 0x40afc */ adr x1, #0x30045;
    /* 0x40b00 */ ldr x8, [x8, #0xd58];
    /* 0x40b04 */ adrp x2, #0x30000;
    /* 0x40b08 */ add x2, x2, #0x56b;
    return x0;
}
