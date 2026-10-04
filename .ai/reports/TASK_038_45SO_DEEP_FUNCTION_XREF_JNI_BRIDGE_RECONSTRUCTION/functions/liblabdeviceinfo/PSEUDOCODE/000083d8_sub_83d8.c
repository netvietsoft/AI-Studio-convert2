// Library: liblabdeviceinfo.so
// Function ID: liblabdeviceinfo::0x83d8
// Recovered Name: sub_83d8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x83d8 | Size: 3132 bytes | SHA256: 36917b102120814594d9f0e8f4fab57d716d1fc0ad7d28e3a68607fa106e3507
// Callers: 0 | Callees: 41 | Imports: 3

// Calls external APIs: _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "()V"
//   "<init>"
//   "LabDeviceModel"
//   "Ljava/lang/String;"
//   "SupportApu version %s"

void sub_83d8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 783 instructions
    /* 0x83d8 */ stp x29, x30, [sp, #0xf0];
    /* 0x83dc */ stp x28, x27, [sp, #0x100];
    /* 0x83e0 */ stp x26, x25, [sp, #0x110];
    /* 0x83e4 */ stp x24, x23, [sp, #0x120];
    /* 0x83e8 */ stp x22, x21, [sp, #0x130];
    /* 0x83ec */ stp x20, x19, [sp, #0x140];
    /* 0x83f0 */ add x29, sp, #0xf0;
    /* 0x83f4 */ mrs x19, tpidr_el0;
    /* 0x83f8 */ mov x20, x0;
    /* 0x83fc */ sub x0, x29, #0x18;
    /* 0x8400 */ ldr x8, [x19, #0x28];
    sub_ca58();
    sub_cb28();
    sub_cbbc();
    sub_cc60();
    sub_ccc4();
    sub_ea98();
    _ZN7_JNIEnv9NewObjectEP7_jclassP10_jmethodIDz();
    sub_cb84();
    sub_cb78();
    sub_cba8();
    sub_cac0();
    sub_caf0();
    sub_cae4();
    sub_cb08();
    sub_cb14();
    sub_cab4();
    sub_caa8();
    sub_cc3c();
    sub_cc34();
    sub_cc48();
    sub_ccb8();
    sub_cd10();
    sub_cacc();
    sub_cad8();
    sub_cafc();
    sub_cb1c();
    sub_cbb0();
    sub_cb90();
    sub_cb9c();
    sub_cc54();
    sub_eb38();
    sub_eb2c();
    sub_ccb0();
    sub_9230();
    sub_9204();
    sub_caf0();
    __android_log_print();
    sub_cae4();
    __android_log_print();
    sub_ccb8();
    __android_log_print();
    sub_cd10();
    __android_log_print();
    sub_eb1c();
    sub_cd00();
    sub_cca0();
    sub_cc24();
    sub_cb68();
    sub_ca98();
    return x0;
    sub_eb1c();
    sub_cd00();
    sub_cca0();
    sub_cc24();
    sub_cb68();
    sub_ca98();
    sub_19798();
    __stack_chk_fail();
}
