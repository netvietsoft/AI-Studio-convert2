// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93468
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getScissorRect
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93468 | Size: 52 bytes | SHA256: 3466f3e6fe1a33cf845ec2c3e5bfcd769f1469a146c36c615fc56a44ea764994
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN8mtlabar316LayerInteraction14getScissorRectEv, _Znwm

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getScissorRect(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x93468 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9346c */ stp x20, x19, [sp, #0x10];
    /* 0x93470 */ mov x29, sp;
    /* 0x93474 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction14getScissorRectEv();
    /* 0x9347c */ mov x19, x0;
    /* 0x93480 */ mov w0, #0x10;
    /* 0x93484 */ mov x20, x1;
    _Znwm();
    /* 0x9348c */ stp x19, x20, [x0];
    /* 0x93490 */ ldp x20, x19, [sp, #0x10];
    return x0;
}
