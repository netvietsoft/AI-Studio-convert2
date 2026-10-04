// Function: sub_A7FA80
// RVA: 0xa7fa80, Size: 864 bytes
int64_t sub_A7FA80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0xa7fb64
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    const char* str = "maskcoord";
    (*x8)(...);
    const char* str = "offsetPixel";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xa7fc40
    sub_C41C20(...); // call internal at 0xa7fc4c
    glBindTexture(...); // call PLT API at 0xa7fc58
    const char* str = "texture";
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xa7fc7c
    sub_C41C20(...); // call internal at 0xa7fc88
    glBindTexture(...); // call PLT API at 0xa7fc94
    const char* str = "masktexture";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xa7fcc4
    (*x8)(...);
    (*x8)(...);
    (*x8)(...);
    const char* str = "arkernel";
    const char* str = "FilterLipstickTeethWhiten::SharpMouth: m_pRefSourceTextures[0] == NULL !";
    const char* str = "arkernel";
    const char* str = "FilterLipstickTeethWhiten::SharpMouth: m_pFilterProgram == NULL !";
    sub_5A6B20(...); // call internal at 0xa7fd78
    const char* str = "arkernel";
    const char* str = "FilterLipstickTeethWhiten::SharpMouth: m_pRefSourceTextures[0] == NULL !";
    const char* str = "arkernel";
    const char* str = "FilterLipstickTeethWhiten::SharpMouth: m_pFilterProgram == NULL !";
    __android_log_print(...); // call PLT API at 0xa7fda8
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa7fddc
}
