// Library: libhiai.so
// Function ID: libhiai::0x26990
// Recovered Name: sub_26990
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x26990 | Size: 456 bytes | SHA256: cc067f21fa07102b2ebddfc3257869c03b0678a146b7c235dc3d222bbac84886
// Callers: 0 | Callees: 1 | Imports: 5

// Calls external APIs: AI_Log_Print, HIAI_MR_ModelBuildOptions_GetEstimatedOutputSize, HIAI_MR_ModelBuildOptions_GetFormatModeOption, _ZN4hiai13ModelTypeUtil12GetModelTypeEPKvmRNS_9ModelTypeE, __strrchr_chk
// Strings referenced:
//   "%s %s(%d)::"BuildOption isn't supported, please reset.""
//   "%s %s(%d)::"GetModelType failed""
//   "%s %s(%d)::"estimatedOutputSize is too large.""
//   "%s %s(%d)::"param is invalid.""
//   "%s %s(%d)::"start to build model by direct""

void sub_26990(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 114 instructions
    /* 0x26990 */ stp x29, x30, [sp, #0x100];
    /* 0x26994 */ stp x26, x25, [sp, #0x110];
    /* 0x26998 */ stp x24, x23, [sp, #0x120];
    /* 0x2699c */ stp x22, x21, [sp, #0x130];
    /* 0x269a0 */ stp x20, x19, [sp, #0x140];
    /* 0x269a4 */ mrs x26, tpidr_el0;
    /* 0x269a8 */ mov x23, x2;
    /* 0x269ac */ mov x20, x1;
    /* 0x269b0 */ ldr x8, [x26, #0x28];
    /* 0x269b4 */ mov x21, x0;
    /* 0x269b8 */ adrp x0, #0x1d000;
    __strrchr_chk();
    AI_Log_Print();
    sub_2b478();
    _ZN4hiai13ModelTypeUtil12GetModelTypeEPKvmRNS_9ModelTypeE();
    __strrchr_chk();
    __strrchr_chk();
    __strrchr_chk();
    HIAI_MR_ModelBuildOptions_GetFormatModeOption();
    HIAI_MR_ModelBuildOptions_GetEstimatedOutputSize();
    __strrchr_chk();
    AI_Log_Print();
}
