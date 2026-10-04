// Function: sub_AD4E78
// RVA: 0xad4e78, Size: 596 bytes
int64_t sub_AD4E78(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0xad4eb4
    glUseProgram(...); // call PLT API at 0xad4ebc
    glActiveTexture(...); // call PLT API at 0xad4ec4
    glBindTexture(...); // call PLT API at 0xad4ed0
    const char* str = "srcMap";
    sub_AD4C3C(...); // call internal at 0xad4ee4
    glActiveTexture(...); // call PLT API at 0xad4f00
    glBindTexture(...); // call PLT API at 0xad4f10
    const char* str = "additionalMap";
    sub_AD4C3C(...); // call internal at 0xad4f24
    sub_FC2A84(...); // call internal at 0xad4f8c
    const char* str = "mvpMatrix";
    sub_AD4A2C(...); // call internal at 0xad4fe8
    const char* str = "vSrcUV";
    sub_AD4CDC(...); // call internal at 0xad500c
    const char* str = "vPosition";
    sub_AD4CDC(...); // call internal at 0xad5030
    glGetError(...); // call PLT API at 0xad5034
    glGetError(...); // call PLT API at 0xad5038
    const char* str = "GL error 0x%X detected
";
    fprintf(...); // call PLT API at 0xad505c
    glGetError(...); // call PLT API at 0xad5060
    glDrawElements(...); // call PLT API at 0xad507c
    const char* str = "vSrcUV";
    sub_AD50CC(...); // call internal at 0xad508c
    const char* str = "vPosition";
    sub_AD50CC(...); // call internal at 0xad509c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xad50c8
}
