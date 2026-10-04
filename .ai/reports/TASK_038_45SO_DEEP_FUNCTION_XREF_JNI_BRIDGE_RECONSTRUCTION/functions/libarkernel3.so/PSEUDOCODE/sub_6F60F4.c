// Function: sub_6F60F4
// RVA: 0x6f60f4, Size: 200 bytes
int64_t sub_6F60F4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuDeviceCreateBuffer(...); // call PLT API at 0x6f6140
    wgpuBufferGetMappedRange(...); // call PLT API at 0x6f6150
    memcpy(...); // call PLT API at 0x6f6160
    wgpuBufferUnmap(...); // call PLT API at 0x6f6168
    const char* str = "mtlabar3";
    const char* str = "createBuffer";
    const char* str = "buffer mapped return is nullptr!";
    sub_CCCFE0(...); // call internal at 0x6f618c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x6f61b8
}
