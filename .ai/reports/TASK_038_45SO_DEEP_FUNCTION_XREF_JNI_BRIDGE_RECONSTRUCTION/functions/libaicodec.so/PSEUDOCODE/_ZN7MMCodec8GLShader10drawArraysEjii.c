// Function: MMCodec::GLShader::drawArrays(unsigned int, int, int)
// RVA: 0x17af2c, Size: 240 bytes
int64_t _ZN7MMCodec8GLShader10drawArraysEjii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x17af54
    (*x8)(...); // indirect call at 0x17af6c
    _ZN7MMCodec2GL7bindVAOEj(...); // call imported API via PLT at 0x17af7c
    glBindBuffer(...); // call imported API via PLT at 0x17af88
    _ZN7MMCodec2GL9blendFuncEjjjj(...); // call imported API via PLT at 0x17af94
    _ZN7MMCodec9GLProgram3useEv(...); // call imported API via PLT at 0x17af9c
    (*x8)(...); // indirect call at 0x17afb0
    (*x8)(...); // indirect call at 0x17afc4
    glDrawArrays(...); // call imported API via PLT at 0x17afd4
    (*x8)(...); // indirect call at 0x17afe8
    glBindBuffer(...); // call imported API via PLT at 0x17b008
    return a0;
}
