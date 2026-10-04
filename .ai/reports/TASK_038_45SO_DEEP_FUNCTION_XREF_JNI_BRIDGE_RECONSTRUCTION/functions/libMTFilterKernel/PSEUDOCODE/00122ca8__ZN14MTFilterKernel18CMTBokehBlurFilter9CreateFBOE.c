// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x122ca8
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilter9CreateFBOEiiRjS1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x122ca8 | Size: 224 bytes | SHA256: 5a2e68f8d79d93f797cf2f27253d216a11d842cebfef69e2d27ded22b664dd2b
// Callers: 1 | Callees: 2 | Imports: 5

// Calls external APIs: __android_log_print, glBindFramebuffer, glCheckFramebufferStatus, glFramebufferTexture2D, glGenFramebuffers
// Strings referenced:
//   "ERROR: create texture failed,m_FrameBufferTexture == 0"
//   "ERROR: glCheckFramebufferStatus status = %d"
//   "FilterKernel"

void _ZN14MTFilterKernel18CMTBokehBlurFilter9CreateFBOEiiRjS1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x122ca8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x122cac */ str x21, [sp, #0x10];
    /* 0x122cb0 */ stp x20, x19, [sp, #0x20];
    /* 0x122cb4 */ mov x29, sp;
    /* 0x122cb8 */ mov w0, w1;
    /* 0x122cbc */ mov w1, w2;
    /* 0x122cc0 */ mov x20, x4;
    /* 0x122cc4 */ mov x21, x3;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    /* 0x122ccc */ str w0, [x20];
    /* 0x122cd0 */ cbz w0, #0x122d4c;
    glGenFramebuffers();
    glBindFramebuffer();
    glFramebufferTexture2D();
    glCheckFramebufferStatus();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
}
