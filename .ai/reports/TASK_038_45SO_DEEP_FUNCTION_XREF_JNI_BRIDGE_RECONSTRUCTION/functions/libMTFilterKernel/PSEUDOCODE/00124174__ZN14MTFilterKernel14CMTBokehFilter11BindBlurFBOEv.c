// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x124174
// Recovered Name: _ZN14MTFilterKernel14CMTBokehFilter11BindBlurFBOEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x124174 | Size: 448 bytes | SHA256: 164cc82de735eb752276e4f087722e5fd64dd07b6ad61fc41af1372d582abc7e
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: __android_log_print, glBindFramebuffer, glCheckFramebufferStatus, glFramebufferTexture2D, glGenFramebuffers
// Strings referenced:
//   "ERROR: glCheckFramebufferStatus status = %d"
//   "FilterKernel"

void _ZN14MTFilterKernel14CMTBokehFilter11BindBlurFBOEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 112 instructions
    /* 0x124174 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x124178 */ stp x20, x19, [sp, #0x10];
    /* 0x12417c */ mov x29, sp;
    /* 0x124180 */ ldr w8, [x0, #0xf4];
    /* 0x124184 */ mov x19, x0;
    /* 0x124188 */ cbz w8, #0x1241b8;
    /* 0x12418c */ mov x1, x19;
    /* 0x124190 */ ldr w8, [x1, #0xf0]!;
    /* 0x124194 */ cbz w8, #0x124230;
    /* 0x124198 */ mov w0, #0x8d40;
    /* 0x12419c */ mov w1, w8;
    glBindFramebuffer();
    return x0;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    glGenFramebuffers();
    glBindFramebuffer();
    glFramebufferTexture2D();
    glCheckFramebufferStatus();
    return x0;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
}
