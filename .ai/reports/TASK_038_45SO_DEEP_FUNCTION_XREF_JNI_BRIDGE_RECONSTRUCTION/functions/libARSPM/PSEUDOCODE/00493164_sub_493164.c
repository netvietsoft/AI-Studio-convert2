// Library: libARSPM.so
// Function ID: libARSPM::0x493164
// Recovered Name: sub_493164
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x493164 | Size: 1588 bytes | SHA256: 216536d028538b7372397d742d68732a5ebeb06f4326fafb73a113aa7b048109
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: strchr, strlen, strncmp
// Strings referenced:
//   "Unknown font style: %s."
//   "black"
//   "bold"
//   "demi"
//   "demibold"

void sub_493164(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 397 instructions
    /* 0x493164 */ stp x29, x30, [sp, #0x60];
    /* 0x493168 */ str x23, [sp, #0x70];
    /* 0x49316c */ stp x22, x21, [sp, #0x80];
    /* 0x493170 */ stp x20, x19, [sp, #0x90];
    /* 0x493174 */ add x29, sp, #0x60;
    /* 0x493178 */ mov x19, x0;
    /* 0x49317c */ add x0, sp, #8;
    /* 0x493180 */ mov x2, #-1;
    sub_493ba4();
    /* 0x493188 */ ldr x8, [sp, #8];
    /* 0x49318c */ sub x21, x8, #1;
    strchr();
    strlen();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strncmp();
    strchr();
    strncmp();
    strncmp();
    strlen();
    sub_469084();
    sub_493dc4();
    return x0;
}
