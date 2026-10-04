// Function: sub_17B8C4
// RVA: 0x17b8c4, Size: 100 bytes
int64_t sub_17B8C4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenBuffers(...); // call imported API via PLT at 0x17b8f0
    glBindBuffer(...); // call imported API via PLT at 0x17b8fc
    glBufferData(...); // call imported API via PLT at 0x17b914
    return a0;
}
