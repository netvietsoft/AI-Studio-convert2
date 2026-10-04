// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1347ac
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1347ac | Size: 224 bytes | SHA256: 2cb0329f0772071a6dbf92f884d7176e4a5d5dec6a71162f05aacfbe6fb9e579
// Callers: 1 | Callees: 2 | Imports: 5

// Calls external APIs: __android_log_print, glBindFramebuffer, glCheckFramebufferStatus, glFramebufferTexture2D, glGenFramebuffers
// Strings referenced:
//   "ERROR: create texture failed,m_FrameBufferTexture == 0"
//   "ERROR: glCheckFramebufferStatus status = %d"
//   "FilterKernel"

void _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x1347ac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1347b0 */ str x21, [sp, #0x10];
    /* 0x1347b4 */ stp x20, x19, [sp, #0x20];
    /* 0x1347b8 */ mov x29, sp;
    /* 0x1347bc */ mov w0, w1;
    /* 0x1347c0 */ mov w1, w2;
    /* 0x1347c4 */ mov x20, x4;
    /* 0x1347c8 */ mov x21, x3;
    _ZN14MTFilterKernel7GLUtils16CreateTexture_WHEii();
    /* 0x1347d0 */ str w0, [x20];
    /* 0x1347d4 */ cbz w0, #0x134850;
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
