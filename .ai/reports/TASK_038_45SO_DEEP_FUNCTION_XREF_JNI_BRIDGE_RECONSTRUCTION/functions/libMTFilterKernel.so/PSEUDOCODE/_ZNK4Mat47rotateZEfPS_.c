// Function: Mat4::rotateZ(float, Mat4*) const
// RVA: 0x13a290, Size: 180 bytes
int64_t _ZNK4Mat47rotateZEfPS_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN4Mat4C1Ev(...); // call internal at 0x13a2c4
    sincosf(...); // call PLT API at 0x13a2ec
    _ZN8MathUtil14multiplyMatrixEPKfS1_Pf(...); // call internal at 0x13a30c
    _ZN4Mat4D2Ev(...); // call internal at 0x13a314
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x13a340
}
