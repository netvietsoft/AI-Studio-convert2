// Function: sub_823F00
// RVA: 0x823f00, Size: 140 bytes
int64_t sub_823F00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_823F8C(...); // call internal func at 0x823f34
    sub_821EEC(...); // call internal func at 0x823f54
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x823f88
}
