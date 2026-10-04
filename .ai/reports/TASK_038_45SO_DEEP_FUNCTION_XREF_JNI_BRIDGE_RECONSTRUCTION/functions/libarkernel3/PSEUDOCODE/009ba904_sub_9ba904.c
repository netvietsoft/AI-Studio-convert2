// Library: libarkernel3.so
// Function ID: libarkernel3::0x9ba904
// Recovered Name: sub_9ba904
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ba904 | Size: 1120 bytes | SHA256: f88b61ef9d8013c7b72e39aee26562fe0b26c00b179729e1bb1fc8c678ea0b6f
// Callers: 0 | Callees: 6 | Imports: 5

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuBufferGetMappedRange, wgpuBufferUnmap, wgpuDeviceCreateBuffer
// Strings referenced:
//   "Kira07"
//   "Kira10"
//   "Kira16"
//   "Kira19"
//   "Kira22"

void sub_9ba904(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 280 instructions
    /* 0x9ba904 */ stp x29, x30, [sp, #0x40];
    /* 0x9ba908 */ str x21, [sp, #0x50];
    /* 0x9ba90c */ stp x20, x19, [sp, #0x60];
    /* 0x9ba910 */ add x29, sp, #0x40;
    /* 0x9ba914 */ mrs x21, tpidr_el0;
    /* 0x9ba918 */ mov x19, x0;
    /* 0x9ba91c */ ldr x8, [x21, #0x28];
    /* 0x9ba920 */ stur x8, [x29, #-8];
    sub_a7fc58();
    /* 0x9ba928 */ mov x20, x0;
    /* 0x9ba92c */ adrp x1, #0x1e3000;
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_5604d4();
    sub_a7b154();
    sub_cc02e0();
    _ZdlPv();
    sub_a7fc40();
    sub_a81778();
    wgpuDeviceCreateBuffer();
    wgpuBufferGetMappedRange();
    wgpuBufferUnmap();
    return x0;
    __stack_chk_fail();
}
