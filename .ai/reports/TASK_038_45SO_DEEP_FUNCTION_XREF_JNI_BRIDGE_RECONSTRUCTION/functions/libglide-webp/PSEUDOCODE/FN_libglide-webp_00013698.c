// Reconstructed Pseudocode for FN_libglide-webp_00013698 (native_nativeRenderFrame_(IILandroid/graphics/Bitmap;)V)
// Library: libglide-webp.so | RVA: 0x13698 | Size: 1424B | Visibility: FACT

/* Imported APIs: AndroidBitmap_getInfo;WebPInitDecoderConfigInternal;WebPGetFeaturesInternal;AndroidBitmap_lockPixels;WebPDecode;AndroidBitmap_unlockPixels;__android_log_print;__stack_chk_fail */
/* String XREFs: Bad bitmap;Already disposed;Width or height is too small;Width or height is negative !;WebPGetFeatures failed */

int native_nativeRenderFrame_(IILandroid/graphics/Bitmap;)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_129A8(ctx);
    sub_129A8(ctx);
    sub_14DA0(ctx);
    sub_14E48(ctx);
    sub_128CC(ctx);
    AndroidBitmap_getInfo(...);
    WebPInitDecoderConfigInternal(...);
    WebPGetFeaturesInternal(...);
    AndroidBitmap_lockPixels(...);
    WebPDecode(...);
    return 0;
}
