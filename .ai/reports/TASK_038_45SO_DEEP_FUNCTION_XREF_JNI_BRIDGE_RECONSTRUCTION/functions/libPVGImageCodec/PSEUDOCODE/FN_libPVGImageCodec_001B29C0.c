// Reconstructed Pseudocode for FN_libPVGImageCodec_001B29C0 (sub_1B29C0)
// Library: libPVGImageCodec.so | RVA: 0x1B29C0 | Size: 2460B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: pthread_self;__android_log_print;setjmp;free;_ZNK8PVGIMAGE8PVGFrame9getFormatEv;_ZNK8PVGIMAGE8PVGFrame8getWidthEv;_ZNK8PVGIMAGE8PVGFrame9getHeightEv;malloc;_ZN8PVGIMAGE22getPVGIccProfileLengthENS_14ColorSpaceTypeE;_ZN8PVGIMAGE16getPVGIccProfileENS_14ColorSpaceTypeE */
/* String XREFs: PVGImage;F[%s  L(%d)]  T(%p):> [png] output file is NULL;sendFrame;1.6.16;PVGImage */

int sub_1B29C0(void* ctx) {
    // Function prologue: set up stack frame
    sub_3A8698(ctx);
    sub_38AF34(ctx);
    sub_390CEC(ctx);
    sub_3A9098(ctx);
    sub_1A1B98(ctx);
    pthread_self(...);
    __android_log_print(...);
    setjmp(...);
    free(...);
    _ZNK8PVGIMAGE8PVGFrame9getFormatEv(...);
    return 0;
}
