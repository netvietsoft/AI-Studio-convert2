// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94964
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_HumanControl_1setFaceIDs
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94964 | Size: 32 bytes | SHA256: 914c6f2c440a17178c51c955fd4771cbc13aab9208bfbe2004d2425cd48a547f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar312HumanControl10setFaceIDsERKNSt6__ndk16vectorIiNS1_9allocatorIiEEEE
// Strings referenced:
//   "std::vector< int > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_HumanControl_1setFaceIDs(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x94964 */ cbz x4, #0x94974;
    /* 0x94968 */ mov x0, x2;
    /* 0x9496c */ mov x1, x4;
    /* 0x94970 */ b #0xa4000;
    /* 0x94974 */ adrp x2, #0x6d000;
    /* 0x94978 */ add x2, x2, #0x988;
    /* 0x9497c */ mov w1, #7;
    /* 0x94980 */ b #0x882c8;
}
