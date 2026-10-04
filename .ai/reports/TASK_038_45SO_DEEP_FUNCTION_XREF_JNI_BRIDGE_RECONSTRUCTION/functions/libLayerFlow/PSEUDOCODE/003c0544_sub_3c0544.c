// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3c0544
// Recovered Name: sub_3c0544
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3c0544 | Size: 268 bytes | SHA256: 9db471d6f127c7823bdd976e7ea82cc1a2bab3f024ea9c49fd9a19e15e2e976f
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, __stack_chk_fail
// Strings referenced:
//   "blurCallbackObj1"
//   "iklf"
//   "jniFormulaRender<%s:%d> env is null, unable to delete GlobalRef to %s, memory leak!!!"
//   "jniFormulaRender<%s:%d> javaVm is null, %s may memory leak!!!!"
//   "releaseGlobalRef"

void sub_3c0544(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0x3c0544 */ stp x29, x30, [sp, #0x10];
    /* 0x3c0548 */ stp x22, x21, [sp, #0x20];
    /* 0x3c054c */ stp x20, x19, [sp, #0x30];
    /* 0x3c0550 */ add x29, sp, #0x10;
    /* 0x3c0554 */ mrs x22, tpidr_el0;
    /* 0x3c0558 */ mov x20, x3;
    /* 0x3c055c */ mov x19, x2;
    /* 0x3c0560 */ ldr x8, [x22, #0x28];
    /* 0x3c0564 */ mov x21, x0;
    /* 0x3c0568 */ str x8, [sp, #8];
    /* 0x3c056c */ ldr x8, [x2, #0x608];
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    __stack_chk_fail();
}
