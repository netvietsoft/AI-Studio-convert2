// Function: sub_A7DA48
// RVA: 0xa7da48, Size: 312 bytes
int64_t sub_A7DA48(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xa7da94
    malloc(...); // call imported API via PLT at 0xa7daa8
    (*x8)(...); // indirect call at 0xa7dad4
    _Znwm(...); // call imported API via PLT at 0xa7dae0
    sub_A7DD6C(...); // call internal func at 0xa7daf0
    sub_CC2DB4(...); // call internal func at 0xa7db00
    (*x8)(...); // indirect call at 0xa7db18
    return a0;
    free(...); // call imported API via PLT at 0xa7db48
    sub_CC2D50(...); // call internal func at 0xa7db74
    __stack_chk_fail(...); // call imported API via PLT at 0xa7db78
    sub_562D14(...); // call internal func at 0xa7db7c
}
