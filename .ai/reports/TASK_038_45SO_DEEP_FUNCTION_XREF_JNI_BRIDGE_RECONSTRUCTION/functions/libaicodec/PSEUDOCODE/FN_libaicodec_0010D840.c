// Reconstructed Pseudocode for FN_libaicodec_0010D840 (MMCodec::GLUtil::loadShadersAndCreateProgram(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&, std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&))
// Library: libaicodec.so | RVA: 0x10D840 | Size: 1256B | Visibility: FACT

/* Imported APIs: glCreateShader;glShaderSource;glCompileShader;glGetShaderiv;__android_log_print;_ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz;glCreateProgram;glAttachShader;glLinkProgram;glGetProgramiv */
/* String XREFs: MTMV_AICodec;[%s(%d)]:> Linking program;loadShadersAndCreateProgram;%s/MTMV_AICodec: [%s(%d)]:> Linking program;loadShadersAndCreateProgram */

int MMCodec__GLUtil__loadShadersAndCreateProgram(std____ndk1__basic_string<char,_std____ndk1__char_traits<char>,_std____ndk1__allocator<char>>_const&,_std____ndk1__basic_string<char,_std____ndk1__char_traits<char>,_std____ndk1__allocator<char>>_const&)(void* ctx) {
    // Function prologue: set up stack frame
    sub_1F00EC(ctx);
    glCreateShader(...);
    glShaderSource(...);
    glCompileShader(...);
    glGetShaderiv(...);
    __android_log_print(...);
    return 0;
}
