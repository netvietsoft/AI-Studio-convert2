// Function: sub_CC3FC8
// RVA: 0xcc3fc8, Size: 120 bytes
int64_t sub_CC3FC8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    AAsset_seek64(...); // call imported API via PLT at 0xcc3fe4
    AAsset_read(...); // call imported API via PLT at 0xcc4000
    return a0;
    sub_562D14(...); // call internal func at 0xcc403c
}
