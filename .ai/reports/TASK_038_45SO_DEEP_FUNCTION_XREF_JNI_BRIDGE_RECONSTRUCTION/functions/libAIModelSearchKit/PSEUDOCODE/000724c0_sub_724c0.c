// Library: libAIModelSearchKit.so
// Function ID: libAIModelSearchKit::0x724c0
// Recovered Name: sub_724c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x724c0 | Size: 156 bytes | SHA256: dd23a635f70f9cac1ce9140e427058e629627e30115bd785a160064d80edbd08
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __cxa_atexit
// Strings referenced:
//   "strategyPath"

void sub_724c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x724c0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x724c4 */ str x21, [sp, #0x10];
    /* 0x724c8 */ stp x20, x19, [sp, #0x20];
    /* 0x724cc */ mov x29, sp;
    /* 0x724d0 */ nop ;
    /* 0x724d4 */ adr x19, #0x102500;
    /* 0x724d8 */ mov w8, #0x12;
    /* 0x724dc */ strb w8, [x19];
    /* 0x724e0 */ nop ;
    /* 0x724e4 */ adr x8, #0x49556;
    /* 0x724e8 */ ldr x8, [x8];
    __cxa_atexit();
}
