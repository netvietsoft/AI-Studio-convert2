// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x577bbc
// Recovered Name: sub_577bbc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x577bbc | Size: 16 bytes | SHA256: df866437ad55ae69f9289abd31de1581b1ab71cc25db36586884a40171425479
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetMusicVolume(JF)V (table at 0x10cde98)

jlong sub_577bbc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x577bbc */ cbz x2, #0x577bc8;
    /* 0x577bc0 */ mov x0, x2;
    /* 0x577bc4 */ b #0x57577c;
    return x0;
}
