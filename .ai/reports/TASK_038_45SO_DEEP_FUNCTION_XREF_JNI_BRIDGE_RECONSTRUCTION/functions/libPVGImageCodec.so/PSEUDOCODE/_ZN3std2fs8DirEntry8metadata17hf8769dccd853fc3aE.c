// Function: std::fs::DirEntry::metadata::hf8769dccd853fc3a
// RVA: 0x2fccf4, Size: 196 bytes
int64_t _ZN3std2fs8DirEntry8metadata17hf8769dccd853fc3aE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    dirfd(...); // call PLT API at 0x2fcd10
    fstatat(...); // call PLT API at 0x2fcd3c
    return a0;
    __errno(...); // call PLT API at 0x2fcd90
    return a0;
}
