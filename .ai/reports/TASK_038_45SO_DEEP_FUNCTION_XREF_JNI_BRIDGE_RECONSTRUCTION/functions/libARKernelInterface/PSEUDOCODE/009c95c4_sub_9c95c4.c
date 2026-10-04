// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x9c95c4
// Recovered Name: sub_9c95c4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9c95c4 | Size: 680 bytes | SHA256: 27ea24416689a6514646cda40d5b23369ce8cb401fcaea7589951b0dbde6b004
// Callers: 0 | Callees: 11 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __android_log_print, __dynamic_cast
// Strings referenced:
//   "CoreSlimV3Part::GetBodyEffectStatus - Create Effect Failed !!!"
//   "CoreSlimV3Part::GetBodyEffectStatus - pPoint or pScore is nullptr!!!"
//   "arkernel"

void sub_9c95c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 170 instructions
    /* 0x9c95c4 */ stp x29, x30, [sp, #0x20];
    /* 0x9c95c8 */ stp x28, x27, [sp, #0x30];
    /* 0x9c95cc */ stp x26, x25, [sp, #0x40];
    /* 0x9c95d0 */ stp x24, x23, [sp, #0x50];
    /* 0x9c95d4 */ stp x22, x21, [sp, #0x60];
    /* 0x9c95d8 */ stp x20, x19, [sp, #0x70];
    /* 0x9c95dc */ add x29, sp, #0x20;
    /* 0x9c95e0 */ ldr x19, [x0, #0x9f8];
    /* 0x9c95e4 */ ldr x20, [x0, #0xa00];
    /* 0x9c95e8 */ cmp x19, x20;
    /* 0x9c95ec */ b.eq #0x9c9774;
    sub_9c6a30();
    _Znwm();
    sub_94af90();
    _Znwm();
    sub_94b5a8();
    sub_94c3c4();
    sub_9ccbe0();
    sub_9ccc58();
    sub_9ccbe8();
    __dynamic_cast();
    sub_9de220();
    sub_9de5d4();
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    __android_log_print();
    sub_94afb0();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
