// Reconstructed Pseudocode for FN_libffmpeg_002F3D14 (sub_2F3D14)
// Library: libffmpeg.so | RVA: 0x2F3D14 | Size: 200B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: ff_vlc_free;ff_mjpeg_build_vlc;memcpy */
/* String XREFs: of absolute Hadamard transformed differences */

int sub_2F3D14(void* ctx) {
    // Function prologue: set up stack frame
    sub_2F9C40(ctx);
    ff_vlc_free(...);
    ff_mjpeg_build_vlc(...);
    memcpy(...);
    return 0;
}
