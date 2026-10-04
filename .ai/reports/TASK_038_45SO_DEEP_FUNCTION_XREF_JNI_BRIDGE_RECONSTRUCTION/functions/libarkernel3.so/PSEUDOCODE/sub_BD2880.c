// Function: sub_BD2880
// RVA: 0xbd2880, Size: 248 bytes
int64_t sub_BD2880(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call imported API via PLT at 0xbd2898
    glDeleteFramebuffers(...); // call imported API via PLT at 0xbd28a8
    glDeleteProgram(...); // call imported API via PLT at 0xbd28b4
    glDeleteVertexArrays(...); // call imported API via PLT at 0xbd28c4
    glDeleteBuffers(...); // call imported API via PLT at 0xbd28d4
    (*x8)(...); // indirect call at 0xbd28f8
    (*x8)(...); // indirect call at 0xbd2918
    (*x8)(...); // indirect call at 0xbd2938
    glFlush(...); // call imported API via PLT at 0xbd2948
    const char* s_2c8e27 = "ZN11WGPUHwAccel18MediaCodecTransfer5cleanEvE3$_0"; // string xref
    return a0;
    void* g_10a7e00 = (void*)0x10a7e00; // global ref
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0xbd2974
}
