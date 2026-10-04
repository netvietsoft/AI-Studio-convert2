// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9713b0
// Recovered Name: sub_9713b0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9713b0 | Size: 500 bytes | SHA256: e15ecb48be53c9efa14ed66bb113b91bf012798ba5e2ef7b6f855151b184b7d4
// Callers: 0 | Callees: 11 | Imports: 3

// Calls external APIs: _ZdlPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "CoreSlimManualPart::SetManualSlimBodyEnable: bodyID->%d, eType->%d, p is nullptr"
//   "arkernel"

void sub_9713b0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 125 instructions
    /* 0x9713b0 */ stp x29, x30, [sp, #0x40];
    /* 0x9713b4 */ stp x22, x21, [sp, #0x50];
    /* 0x9713b8 */ stp x20, x19, [sp, #0x60];
    /* 0x9713bc */ add x29, sp, #0x40;
    /* 0x9713c0 */ mrs x22, tpidr_el0;
    /* 0x9713c4 */ mov w19, w3;
    /* 0x9713c8 */ mov x20, x0;
    /* 0x9713cc */ ldr x8, [x22, #0x28];
    /* 0x9713d0 */ stur x8, [x29, #-8];
    /* 0x9713d4 */ ldr x8, [x0, #0x998];
    /* 0x9713d8 */ stp w2, w1, [x29, #-0x1c];
    sub_970334();
    sub_97264c();
    sub_972880();
    sub_969c64();
    sub_5a6b20();
    sub_95d0d8();
    sub_9534cc();
    sub_9670a8();
    sub_96bd0c();
    sub_59c78c();
    sub_96bd14();
    _ZdlPv();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
