// Function: sub_CCCD34
// RVA: 0xcccd34, Size: 148 bytes
int64_t sub_CCCD34(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    syscall(...); // call PLT API at 0xcccd90
    sched_setaffinity(...); // call PLT API at 0xcccd9c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xcccdc0
    sub_562D14(...); // call internal at 0xcccdc4
}
