// Reconstructed Pseudocode for FN_libVERenderer_00051450 (backend::RenderContextGL::pushStatus())
// Library: libVERenderer.so | RVA: 0x51450 | Size: 704B | Visibility: FACT

/* Imported APIs: glGetIntegerv;_Znwm;_ZdlPv;__android_log_print;glGetString;strcmp;glBindFramebuffer;__stack_chk_fail */
/* String XREFs: t;  precision mediump int;;diump int;;ig;VERenderer;[%s(%d)]:> RenderContextGL::pushStatus status stack depth=%zu  possible push/pop */

int backend__RenderContextGL__pushStatus()(void* ctx) {
    // Function prologue: set up stack frame
    sub_51D24(ctx);
    sub_3F1A0(ctx);
    glGetIntegerv(...);
    _Znwm(...);
    _ZdlPv(...);
    __android_log_print(...);
    glGetString(...);
    return 0;
}
