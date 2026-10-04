// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d604
// Recovered Name: sub_57d604
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d604 | Size: 12 bytes | SHA256: 3d0d78cd2429394b1e6a948116a1da4c0a619ce628d950658f76cfd12c276ccd
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerVertexMarkRadius(JI)V (table at 0x10cede0)

jlong sub_57d604(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x57d604 */ cbz x2, #0x57d60c;
    /* 0x57d608 */ str w3, [x2, #0x14];
    return x0;
}
