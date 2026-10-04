// Function: sub_A74540
// RVA: 0xa74540, Size: 524 bytes
int64_t sub_A74540(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_unref(...); // call PLT API at 0xa745bc
    av_frame_free(...); // call PLT API at 0xa745c4
    _ZdlPv(...); // call PLT API at 0xa7460c
    sub_A74040(...); // call internal at 0xa74650
    _ZNSt6__ndk118condition_variableD1Ev(...); // call PLT API at 0xa74658
    _ZNSt6__ndk15mutexD1Ev(...); // call PLT API at 0xa74660
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa7468c
    sub_562D14(...); // call internal at 0xa74690
    _ZNSt6__ndk119__thread_local_dataEv(...); // call PLT API at 0xa746b8
    pthread_setspecific(...); // call PLT API at 0xa746c8
    (*x8)(...);
    sub_A7478C(...); // call internal at 0xa746f0
    _ZdlPv(...); // call PLT API at 0xa74708
    return a0;
    sub_A7474C(...); // call internal at 0xa7472c
    sub_106B814(...); // call internal at 0xa74744
    __stack_chk_fail(...); // call PLT API at 0xa74748
}
