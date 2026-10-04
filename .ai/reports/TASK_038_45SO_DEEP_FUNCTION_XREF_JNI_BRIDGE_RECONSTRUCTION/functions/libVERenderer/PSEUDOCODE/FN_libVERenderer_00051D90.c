// Reconstructed Pseudocode for FN_libVERenderer_00051D90 (backend::RenderPipelineGL::updateBlendState(backend::BlendDescriptor const&))
// Library: libVERenderer.so | RVA: 0x51D90 | Size: 224B | Visibility: FACT

/* Imported APIs: _ZN7backend7UtilsGL18toGLBlendOperationENS_14BlendOperationE;_ZN7backend7UtilsGL15toGLBlendFactorENS_11BlendFactorE;glEnable;glBlendEquationSeparate;glBlendFuncSeparate;glDisable */
/* String XREFs:  */

int backend__RenderPipelineGL__updateBlendState(backend__BlendDescriptor_const&)(void* ctx) {
    // Function prologue: set up stack frame
    _ZN7backend7UtilsGL18toGLBlendOperationENS_14BlendOperationE(...);
    _ZN7backend7UtilsGL15toGLBlendFactorENS_11BlendFactorE(...);
    glEnable(...);
    glBlendEquationSeparate(...);
    glBlendFuncSeparate(...);
    return 0;
}
