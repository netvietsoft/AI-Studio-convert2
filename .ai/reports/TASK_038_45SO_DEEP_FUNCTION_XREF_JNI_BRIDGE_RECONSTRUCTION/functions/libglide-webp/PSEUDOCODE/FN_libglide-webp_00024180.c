// Reconstructed Pseudocode for FN_libglide-webp_00024180 (VP8FiltersInit)
// Library: libglide-webp.so | RVA: 0x24180 | Size: 304B | Visibility: FACT

/* Imported APIs: pthread_mutex_lock;VP8FiltersInitNEON */
/* String XREFs:  */

int VP8FiltersInit(void* ctx) {
    // Function prologue: set up stack frame
    pthread_mutex_lock(...);
    VP8FiltersInitNEON(...);
    return 0;
}
