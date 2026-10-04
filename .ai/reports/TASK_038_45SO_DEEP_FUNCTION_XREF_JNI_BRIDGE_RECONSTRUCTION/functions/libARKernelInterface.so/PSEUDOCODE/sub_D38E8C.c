// Function: sub_D38E8C
// RVA: 0xd38e8c, Size: 248 bytes
int64_t sub_D38E8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glActiveTexture(...); // call PLT API at 0xd38eac
    sub_DA2FEC(...); // call internal at 0xd38eb4
    glUniform1i(...); // call PLT API at 0xd38ec8
    glActiveTexture(...); // call PLT API at 0xd38f20
    sub_DA2FEC(...); // call internal at 0xd38f28
    glUniform1iv(...); // call PLT API at 0xd38f50
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd38f80
}
