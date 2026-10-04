// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x573dac
// Recovered Name: sub_573dac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x573dac | Size: 28 bytes | SHA256: 05d231a901f22fcba548f4557393297ade4ac30530548f5475607cd033bfe6ae
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetImageDataUserDefineFlag(JI)I (table at 0x10cdb38)

jlong sub_573dac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x573dac */ cbz x2, #0x573dc0;
    /* 0x573db0 */ mov w8, #0x58;
    /* 0x573db4 */ smaddl x8, w3, w8, x2;
    /* 0x573db8 */ ldr w0, [x8, #0x20];
    return x0;
    /* 0x573dc0 */ mov w0, wzr;
    return x0;
}
