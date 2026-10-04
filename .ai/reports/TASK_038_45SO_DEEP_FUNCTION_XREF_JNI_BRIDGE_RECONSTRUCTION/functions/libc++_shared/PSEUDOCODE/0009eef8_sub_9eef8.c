// Library: libc++_shared.so
// Function ID: libc++_shared::0x9eef8
// Recovered Name: sub_9eef8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9eef8 | Size: 28 bytes | SHA256: 22e4fb96aeaf463ce7d903476cbdd21c86086bbc6aed202859d12465dbe64513
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: pthread_mutex_lock
// Strings referenced:
//   "unexpected"

void sub_9eef8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9eef8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9eefc */ mov x29, sp;
    /* 0x9ef00 */ adrp x8, #0x146000;
    /* 0x9ef04 */ adrp x9, #0x55000;
    /* 0x9ef08 */ add x9, x9, #0xb24;
    /* 0x9ef0c */ str x9, [x8, #0xe50];
    pthread_mutex_lock();
}
