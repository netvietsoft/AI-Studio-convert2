// Function: sub_82F9D0
// RVA: 0x82f9d0, Size: 100 bytes
int64_t sub_82F9D0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_82FA34(...); // call internal func at 0x82fa04
    sub_82F588(...); // call internal func at 0x82fa0c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x82fa30
}
