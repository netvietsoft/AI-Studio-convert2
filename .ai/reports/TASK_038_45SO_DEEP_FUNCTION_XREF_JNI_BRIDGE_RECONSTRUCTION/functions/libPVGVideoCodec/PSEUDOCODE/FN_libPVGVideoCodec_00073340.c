// Reconstructed Pseudocode for FN_libPVGVideoCodec_00073340 (JNI_OnLoad)
// Library: libPVGVideoCodec.so | RVA: 0x73340 | Size: 192B | Visibility: FACT

/* Imported APIs: pthread_self;_Z15vllog_tag_print13vllog_level_tPKcS1_S1_z */
/* String XREFs: PVGVideoCodec;F[%s  L(%d)]  T(%p):> JNI_OnLoad;JNI_OnLoad;PVGVideoCodec;F[%s  L(%d)]  T(%p):> aicodec_set_jvm failed */

int JNI_OnLoad(void* ctx) {
    // Function prologue: set up stack frame
    sub_97FB0(ctx);
    pthread_self(...);
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z(...);
    return 0;
}
