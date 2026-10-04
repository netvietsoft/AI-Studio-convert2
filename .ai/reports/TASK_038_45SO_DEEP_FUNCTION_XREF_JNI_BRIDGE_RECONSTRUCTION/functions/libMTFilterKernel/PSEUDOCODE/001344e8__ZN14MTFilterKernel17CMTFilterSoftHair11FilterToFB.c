// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1344e8
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHair11FilterToFBOEiib
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1344e8 | Size: 708 bytes | SHA256: 43141de9e6018648c4f197c40bc0d073e83a171583e616202a381f8a54cf6f45
// Callers: 0 | Callees: 9 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memcpy

void _ZN14MTFilterKernel17CMTFilterSoftHair11FilterToFBOEiib(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 177 instructions
    /* 0x1344e8 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x1344ec */ stp x28, x27, [sp, #0x10];
    /* 0x1344f0 */ stp x26, x25, [sp, #0x20];
    /* 0x1344f4 */ stp x24, x23, [sp, #0x30];
    /* 0x1344f8 */ stp x22, x21, [sp, #0x40];
    /* 0x1344fc */ stp x20, x19, [sp, #0x50];
    /* 0x134500 */ mov x29, sp;
    /* 0x134504 */ sub sp, sp, #0x250;
    /* 0x134508 */ stp w2, w3, [sp];
    /* 0x13450c */ mrs x8, tpidr_el0;
    /* 0x134510 */ mov x19, x0;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm();
    memcpy();
    _ZdlPv();
    _ZN14MTFilterKernel17CMTFilterSoftHair25ReleaseFramebufferTextureEv();
    _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_();
    _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_();
    _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_();
    _ZN14MTFilterKernel17CMTFilterSoftHair9CreateFBOEiiRjS1_();
    _ZN14MTFilterKernel17CMTFilterSoftHair15GrayFilterToFBOEiiii();
    _ZN14MTFilterKernel17CMTFilterSoftHair19HairMaskFilterToFBOEiiii();
    _ZN14MTFilterKernel17CMTFilterSoftHair16BlurHFilterToFBOEiiii();
    _ZN14MTFilterKernel17CMTFilterSoftHair16BlurVFilterToFBOEiiii();
    _ZN14MTFilterKernel17CMTFilterSoftHair19SoftHairFilterToFBOEiiiiii();
    _ZN14MTFilterKernel16CMTDynamicFilter13ReadFBOPixelsEv();
    return x0;
    __stack_chk_fail();
}
