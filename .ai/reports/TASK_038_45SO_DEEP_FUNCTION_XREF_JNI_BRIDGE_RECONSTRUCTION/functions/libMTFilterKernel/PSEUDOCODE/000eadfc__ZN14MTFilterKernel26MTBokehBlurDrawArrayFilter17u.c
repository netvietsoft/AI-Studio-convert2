// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xeadfc
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter17unlockFrameBufferEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xeadfc | Size: 80 bytes | SHA256: 7b6d37f491099fe5943d7eeed5f16e8ed4e443eb5e04ee6a59c96a032e73dcad
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter17unlockFrameBufferEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0xeadfc */ stp x29, x30, [sp, #-0x20]!;
    /* 0xeae00 */ str x19, [sp, #0x10];
    /* 0xeae04 */ mov x29, sp;
    /* 0xeae08 */ mov x19, x0;
    /* 0xeae0c */ ldr x0, [x0, #0x1c8];
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    /* 0xeae14 */ ldr x0, [x19, #0x1d0];
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    /* 0xeae1c */ ldr x0, [x19, #0x1d8];
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    /* 0xeae24 */ ldr x0, [x19, #0x1e0];
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
    _ZN14MTFilterKernel19GPUImageFramebuffer6unlockEv();
}
