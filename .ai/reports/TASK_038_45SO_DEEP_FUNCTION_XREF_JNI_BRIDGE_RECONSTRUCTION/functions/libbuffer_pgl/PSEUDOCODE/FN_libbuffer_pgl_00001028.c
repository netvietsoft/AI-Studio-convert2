// Reconstructed Pseudocode for FN_libbuffer_pgl_00001028 (Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate)
// Library: libbuffer_pgl.so | RVA: 0x1028 | Size: 440B | Visibility: FACT

/* Imported APIs: open;lseek;close;ftruncate;__errno;strerror;mmap;__android_log_print */
/* String XREFs: java/io/IOException;inconsistent file length;java/io/IOException;Buffer;mmap failed  %s */

int Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MMapBuffer_nCreate(void* ctx) {
    // Function prologue: set up stack frame
    open(...);
    lseek(...);
    close(...);
    ftruncate(...);
    __errno(...);
    return 0;
}
