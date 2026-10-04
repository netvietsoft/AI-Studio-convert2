// Function: manisEngine::ScriptController::initialize(char const*)
// RVA: 0x9019cc, Size: 476 bytes
int64_t _ZN11manisEngine16ScriptController10initializeEPKc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_917004(...); // call internal at 0x9019e8
    sub_922038(...); // call internal at 0x9019f8
    sub_902DE8(...); // call internal at 0x901a04
    sub_8F9BD0(...); // call internal at 0x901a0c
    sub_8F9BEC(...); // call internal at 0x901a18
    sub_90184C(...); // call internal at 0x901a24
    const char* str = "do
    local oldLoadfile = loadfile
    loadfile = function(filename)
        if filename ~= nil and not FileSystem.isAbsolutePa";
    sub_916658(...); // call internal at 0x901a38
    sub_913C20(...); // call internal at 0x901a5c
    const char* str = "do
    local oldDofile = dofile
    dofile = function(filename)
        if filename ~= nil and not FileSystem.isAbsolutePath(fil";
    sub_916658(...); // call internal at 0x901a74
    sub_913C20(...); // call internal at 0x901a98
    return a0;
    const char* str = "%s -- ";
    const char* str = "initialize";
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901ac4
    sub_911DF8(...); // call internal at 0x901ad8
    const char* str = "Failed to load custom loadfile() function with error: '%s'.";
    const char* str = "%s -- ";
    const char* str = "initialize";
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b00
    sub_911DF8(...); // call internal at 0x901b14
    const char* str = "Failed to load custom dofile() function with error: '%s'.";
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b28
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b38
    exit(...); // call PLT API at 0x901b40
    const char* str = "%s -- ";
    const char* str = "initialize";
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b58
    const char* str = "Failed to initialize ScriptController::Impl.";
    const char* str = "%s -- ";
    const char* str = "initialize";
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b7c
    const char* str = "Failed to initialize Lua scripting engine.";
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b8c
    _ZN11manisEngine6Logger3logENS0_5LevelEPKcz(...); // call PLT API at 0x901b9c
    exit(...); // call PLT API at 0x901ba4
}
