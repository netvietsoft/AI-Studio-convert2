// Reconstructed Pseudocode for FN_libglide-webp_000131B0 (native_nativeGetFrame_(I)Lcom/bumptech/glide/integration/webp/WebpFrame;)
// Library: libglide-webp.so | RVA: 0x131B0 | Size: 724B | Visibility: FACT

/* Imported APIs: WebPDemuxGetFrame;WebPDemuxReleaseIterator;__stack_chk_fail */
/* String XREFs: Already disposed;unable to get frame */

int native_nativeGetFrame_(I)Lcom/bumptech/glide/integration/webp/WebpFrame;(void* ctx) {
    // Function prologue: set up stack frame
    sub_12F3C(ctx);
    sub_14DE4(ctx);
    sub_14DA0(ctx);
    sub_129A8(ctx);
    sub_129A8(ctx);
    WebPDemuxGetFrame(...);
    WebPDemuxReleaseIterator(...);
    __stack_chk_fail(...);
    return 0;
}
