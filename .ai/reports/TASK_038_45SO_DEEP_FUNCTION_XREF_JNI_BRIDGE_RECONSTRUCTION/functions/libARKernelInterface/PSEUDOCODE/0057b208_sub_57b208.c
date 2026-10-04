// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b208
// Recovered Name: sub_57b208
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b208 | Size: 416 bytes | SHA256: eb5affc0ec65025d785893413ee387c374d1f72ec8646417bd8a24970162f741
// Callers: 0 | Callees: 2 | Imports: 5

// Dynamic Registration: nativePushPointerData(JLjava/lang/String;Ljava/lang/String;JII)I (table at 0x10ce7e0)
// Calls external APIs: _ZdlPv, __memcpy_chk, __stack_chk_fail, memcpy, memset

jlong sub_57b208(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 104 instructions
    /* 0x57b208 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x57b20c */ str x28, [sp, #0x10];
    /* 0x57b210 */ stp x26, x25, [sp, #0x20];
    /* 0x57b214 */ stp x24, x23, [sp, #0x30];
    /* 0x57b218 */ stp x22, x21, [sp, #0x40];
    /* 0x57b21c */ stp x20, x19, [sp, #0x50];
    /* 0x57b220 */ mov x29, sp;
    /* 0x57b224 */ sub sp, sp, #0x260;
    /* 0x57b228 */ mrs x25, tpidr_el0;
    /* 0x57b22c */ ldr x8, [x25, #0x28];
    /* 0x57b230 */ stur x8, [x29, #-8];
    memset();
    sub_55dce4();
    __memcpy_chk();
    sub_55dce4();
    __memcpy_chk();
    memcpy();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_1042be4();
    __stack_chk_fail();
}
