// Library: libglide-webp.so
// Function ID: libglide-webp::0x14a0c
// Recovered Name: sub_14a0c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x14a0c | Size: 16 bytes | SHA256: 354c138fb0e9846b7eef9b60608c7fd2e0ce46d9d2fcd7b9ad08d5224e3fb94b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeDecodeStream(Ljava/io/InputStream;Landroid/graphics/BitmapFactory$Options;F[B)Landroid/graphics/Bitmap; (table at 0x680c0)

jlong sub_14a0c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x14a0c */ sub sp, sp, #0x50;
    /* 0x14a10 */ str d8, [sp, #0x20];
    /* 0x14a14 */ str x21, [sp, #0x28];
    /* 0x14a18 */ stp x20, x19, [sp, #0x30];
}
