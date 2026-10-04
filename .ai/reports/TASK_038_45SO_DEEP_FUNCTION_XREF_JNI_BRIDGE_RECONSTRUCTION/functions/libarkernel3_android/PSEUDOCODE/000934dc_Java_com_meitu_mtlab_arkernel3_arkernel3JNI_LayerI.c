// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x934dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getLockScreen
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x934dc | Size: 28 bytes | SHA256: 1265e963164bbba8389c4c3007372b4226efec6841cde9fc57ab6cf484fad793
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction13getLockScreenEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getLockScreen(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x934dc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x934e0 */ mov x29, sp;
    /* 0x934e4 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction13getLockScreenEv();
    /* 0x934ec */ and w0, w0, #1;
    /* 0x934f0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
