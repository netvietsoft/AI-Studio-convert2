// Function: sub_A59100
// RVA: 0xa59100, Size: 360 bytes
int64_t sub_A59100(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0xa59130
    (*x8)(...);
    glActiveTexture(...); // call PLT API at 0xa59148
    glBindTexture(...); // call PLT API at 0xa59154
    const char* str = "texture";
    (*x8)(...);
    const char* str = "alpha";
    (*x8)(...);
    const char* str = "mvpMatrix";
    (*x8)(...);
    const char* str = "position";
    (*x8)(...);
    const char* str = "texcoord";
    (*x8)(...);
    glDrawArrays(...); // call PLT API at 0xa59220
    (*x8)(...);
    (*x8)(...);
    glBindTexture(...); // call PLT API at 0xa59264
}
