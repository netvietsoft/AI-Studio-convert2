// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55d608
// Recovered Name: sub_55d608
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55d608 | Size: 44 bytes | SHA256: d0df7dff34b882246a19b8bd3d14ab7b474afbc38db2e9381addb22cc0809ba6
// Callers: 0 | Callees: 0 | Imports: 0

// Strings referenced:
//   "JNI_OnLoad error:failed to register_com_meitu_mtlab_arkernelinterface_freetype_GLXBitmap"

void sub_55d608(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x55d608 */ ldp x20, x19, [sp, #0x10];
    /* 0x55d60c */ ldp x29, x30, [sp], #0x20;
    return x0;
    /* 0x55d614 */ adrp x8, #0x10d0000;
    /* 0x55d618 */ add x8, x8, #0xc30;
    /* 0x55d61c */ ldr w8, [x8];
    /* 0x55d620 */ cmp w8, #4;
    /* 0x55d624 */ b.gt #0x55d604;
    /* 0x55d628 */ adrp x2, #0x1a6000;
    /* 0x55d62c */ add x2, x2, #0xe10;
    /* 0x55d630 */ b #0x55d5f4;
}
