// Function: MMCodec::Texture2D::load(void const*, long, MMCodec::Texture2D::PixelFormat, int, int)
// RVA: 0x17d3d0, Size: 1848 bytes
int64_t _ZN7MMCodec9Texture2D4loadEPKvlNS0_11PixelFormatEii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    void* g_202008 = (void*)0x202008; // global ref
    void* g_202008 = (void*)0x202008; // global ref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e796 = "[%s(%d)]:> the "pixelFormat" param must be a certain value!"; // string xref
    const char* s_6cc6a = "load"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17d4c8
    const char* s_8033a = "%s/MTMV_AICodec: [%s(%d)]:> the "pixelFormat" param must be a certain value!
"; // string xref
    const char* s_6cc6a = "load"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17d504
    const char* s_6cc6a = "load"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_79d00 = "[%s(%d)]:> [%s]Invalid size"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17d54c
    const char* s_6cc6a = "load"; // string xref
    const char* s_7c274 = "%s/MTMV_AICodec: [%s(%d)]:> [%s]Invalid size
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7e7d2 = "[%s(%d)]:> Image (%d x %d) is bigger than the supported (%d x %d)"; // string xref
    const char* s_6cc6a = "load"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17d5dc
    const char* s_90842 = "%s/MTMV_AICodec: [%s(%d)]:> Image (%d x %d) is bigger than the supported (%d x %d)
"; // string xref
    const char* s_6cc6a = "load"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17d628
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_74732 = "[%s(%d)]:> MTMCore: WARNING: unsupported pixelformat: %lx"; // string xref
    const char* s_6cc6a = "load"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17d67c
    const char* s_6a655 = "%s/MTMV_AICodec: [%s(%d)]:> MTMCore: WARNING: unsupported pixelformat: %lx
"; // string xref
    const char* s_6cc6a = "load"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17d6bc
    return a0;
    const char* s_683cd = "map::at:  key not found"; // string xref
    sub_D85FC(...); // call internal func at 0x17d728
    (*x8)(...); // indirect call at 0x17d76c
    _ZN7MMCodec2GL13bindTexture2DEj(...); // call imported API via PLT at 0x17d770
    _ZN7MMCodec2GL13activeTextureEj(...); // call imported API via PLT at 0x17d778
    glTexSubImage2D(...); // call imported API via PLT at 0x17d798
    glGetError(...); // call imported API via PLT at 0x17d79c
    glDeleteTextures(...); // call imported API via PLT at 0x17d7b0
    const char* s_6cc6a = "load"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8163c = "[%s(%d)]:> OpenGL error 0x%04X in %s %s %d
"; // string xref
    const char* s_788db = "/Users/meitu/apollo-ws/proj/android/aicodec/src/main/cpp/src/graphics/opengl/MTTexture2D.cpp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17d80c
    const char* s_77723 = "%s/MTMV_AICodec: [%s(%d)]:> OpenGL error 0x%04X in %s %s %d

"; // string xref
    const char* s_788db = "/Users/meitu/apollo-ws/proj/android/aicodec/src/main/cpp/src/graphics/opengl/MTTexture2D.cpp"; // string xref
    const char* s_6cc6a = "load"; // string xref
    _ZN7MMCodec2GL13deleteTextureEj(...); // call imported API via PLT at 0x17d880
    glGenTextures(...); // call imported API via PLT at 0x17d8a8
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_7c2a2 = "[%s(%d)]:> ERROR in loadTexture!"; // string xref
    const char* s_6cc6a = "load"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17d92c
    const char* s_7c2c3 = "%s/MTMV_AICodec: [%s(%d)]:> ERROR in loadTexture!
"; // string xref
    const char* s_6cc6a = "load"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17d968
    glPixelStorei(...); // call imported API via PLT at 0x17d980
    _ZN7MMCodec2GL13bindTexture2DEj(...); // call imported API via PLT at 0x17d990
    glTexImage2D(...); // call imported API via PLT at 0x17d9b0
    glTexParameteri(...); // call imported API via PLT at 0x17d9c0
    glTexParameteri(...); // call imported API via PLT at 0x17d9d0
    glTexParameteri(...); // call imported API via PLT at 0x17d9e0
    glTexParameteri(...); // call imported API via PLT at 0x17d9f0
    glTexImage2D(...); // call imported API via PLT at 0x17da10
    glPixelStorei(...); // call imported API via PLT at 0x17da1c
    glGetError(...); // call imported API via PLT at 0x17da20
    glDeleteTextures(...); // call imported API via PLT at 0x17da34
    const char* s_6cc6a = "load"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_8163c = "[%s(%d)]:> OpenGL error 0x%04X in %s %s %d
"; // string xref
    const char* s_788db = "/Users/meitu/apollo-ws/proj/android/aicodec/src/main/cpp/src/graphics/opengl/MTTexture2D.cpp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x17da90
    const char* s_77723 = "%s/MTMV_AICodec: [%s(%d)]:> OpenGL error 0x%04X in %s %s %d

"; // string xref
    const char* s_788db = "/Users/meitu/apollo-ws/proj/android/aicodec/src/main/cpp/src/graphics/opengl/MTTexture2D.cpp"; // string xref
    const char* s_6cc6a = "load"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x17dae4
    __stack_chk_fail(...); // call imported API via PLT at 0x17db04
}
