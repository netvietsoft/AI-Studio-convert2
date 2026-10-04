// Function: MMCodec::GLShader::loadUniform(unsigned int, MMCodec::UniformValue&)
// RVA: 0x17bcf4, Size: 984 bytes
int64_t _ZN7MMCodec8GLShader11loadUniformEjRNS_12UniformValueE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glUniform1i(...); // call imported API via PLT at 0x17bd3c
    (*x8)(...); // indirect call at 0x17bd50
    _ZN7MMCodec2GL14bindTexture2DNEjj(...); // call imported API via PLT at 0x17bd5c
    glUniform1i(...); // call imported API via PLT at 0x17bd70
    (*x8)(...); // indirect call at 0x17bd84
    _ZN7MMCodec2GL14bindTexture2DNEjj(...); // call imported API via PLT at 0x17bd90
    glUniform1i(...); // call imported API via PLT at 0x17bda4
    glUniform4fv(...); // call imported API via PLT at 0x17bdbc
    glUniform1f(...); // call imported API via PLT at 0x17bdd0
    glUniformMatrix3fv(...); // call imported API via PLT at 0x17bdec
    glUniform2fv(...); // call imported API via PLT at 0x17be04
    glUniform3i(...); // call imported API via PLT at 0x17be20
    (*x8)(...); // indirect call at 0x17be34
    _ZN7MMCodec2GL14bindTexture2DNEjj(...); // call imported API via PLT at 0x17be40
    glUniform1i(...); // call imported API via PLT at 0x17be54
    glUniform4i(...); // call imported API via PLT at 0x17be70
    glUniform4f(...); // call imported API via PLT at 0x17be88
    glUniform2i(...); // call imported API via PLT at 0x17be9c
    (*x8)(...); // indirect call at 0x17beb0
    _ZN7MMCodec2GL14bindTexture2DNEjj(...); // call imported API via PLT at 0x17bebc
    glUniform1i(...); // call imported API via PLT at 0x17bed0
    _ZN7MMCodec2GL20bindTextureExternalNEjjj(...); // call imported API via PLT at 0x17bee0
    glUniform1i(...); // call imported API via PLT at 0x17bef4
    glUniform2f(...); // call imported API via PLT at 0x17bf08
    _ZN7MMCodec2GL20bindTextureExternalNEjjj(...); // call imported API via PLT at 0x17bf18
    glUniform1i(...); // call imported API via PLT at 0x17bf2c
    glUniformMatrix4fv(...); // call imported API via PLT at 0x17bf48
    glUniform3f(...); // call imported API via PLT at 0x17bf60
    (*x8)(...); // indirect call at 0x17bf74
    _ZN7MMCodec2GL14bindTexture2DNEjj(...); // call imported API via PLT at 0x17bf80
    glUniform1i(...); // call imported API via PLT at 0x17bf94
    glUniform3fv(...); // call imported API via PLT at 0x17bfac
    glUniform1fv(...); // call imported API via PLT at 0x17bfc4
    _ZN7MMCodec2GL20bindTextureExternalNEjjj(...); // call imported API via PLT at 0x17bfd4
    glUniform1i(...); // call imported API via PLT at 0x17bfe8
    _ZN7MMCodec2GL20bindTextureExternalNEjjj(...); // call imported API via PLT at 0x17bff8
    glUniform1i(...); // call imported API via PLT at 0x17c00c
    _ZN7MMCodec2GL20bindTextureExternalNEjjj(...); // call imported API via PLT at 0x17c01c
    glUniform1i(...); // call imported API via PLT at 0x17c030
    const char* s_7e78a = "loadUniform"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e764 = "[%s(%d)]:> [%s] value.type is invalid"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17c074
    const char* s_7e78a = "loadUniform"; // string xref
    const char* s_6b6a7 = "%s/MTMV_AICodec: [%s(%d)]:> [%s] value.type is invalid
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17c0bc
    return a0;
}
