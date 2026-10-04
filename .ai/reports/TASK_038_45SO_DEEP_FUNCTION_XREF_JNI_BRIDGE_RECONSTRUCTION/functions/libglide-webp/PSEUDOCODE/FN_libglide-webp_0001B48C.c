// Reconstructed Pseudocode for FN_libglide-webp_0001B48C (VP8GetHeaders)
// Library: libglide-webp.so | RVA: 0x1B48C | Size: 1864B | Visibility: FACT

/* Imported APIs: VP8ResetProba;VP8InitBitReader;VP8GetValue;VP8GetSignedValue;VP8ParseQuant;VP8ParseProba */
/* String XREFs: OK;Truncated header.;null VP8Io passed to VP8GetHeaders();Incorrect keyframe parameters.;Frame not displayable. */

int VP8GetHeaders(void* ctx) {
    // Function prologue: set up stack frame
    VP8ResetProba(...);
    VP8InitBitReader(...);
    VP8GetValue(...);
    VP8GetSignedValue(...);
    VP8ParseQuant(...);
    return 0;
}
