// Function: Mat4::rotateX(float, Mat4*) const
// RVA: 0x139fc8, Size: 180 bytes
int64_t _ZNK4Mat47rotateXEfPS_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN4Mat4C1Ev(...); // call internal at 0x139ffc
    sincosf(...); // call PLT API at 0x13a024
    _ZN8MathUtil14multiplyMatrixEPKfS1_Pf(...); // call internal at 0x13a044
    _ZN4Mat4D2Ev(...); // call internal at 0x13a04c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x13a078
}
