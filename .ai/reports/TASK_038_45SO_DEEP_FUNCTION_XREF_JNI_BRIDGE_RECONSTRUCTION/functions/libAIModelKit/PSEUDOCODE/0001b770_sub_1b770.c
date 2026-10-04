// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1b770
// Recovered Name: sub_1b770
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1b770 | Size: 692 bytes | SHA256: 42703d96f8a40e6c5592030b8934ea0ebc2dc9c00fd52eea73fad8fa86bfbd2e
// Callers: 0 | Callees: 0 | Imports: 6

// Calls external APIs: __android_log_print, cJSON_Delete, cJSON_GetObjectItem, cJSON_Parse, strncpy, strstr
// Strings referenced:
//   "AIModelKitJni"
//   "APU_isSupport"
//   "APU_version"
//   "CL_DEVICE_HALF_FP"
//   "CL_DEVICE_VERSION"

void sub_1b770(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 173 instructions
    /* 0x1b770 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1b774 */ str x19, [sp, #0x10];
    /* 0x1b778 */ mov x29, sp;
    cJSON_Parse();
    /* 0x1b780 */ cbz x0, #0x1ba18;
    /* 0x1b784 */ adrp x1, #0xf000;
    /* 0x1b788 */ add x1, x1, #0xf49;
    /* 0x1b78c */ mov x19, x0;
    cJSON_GetObjectItem();
    /* 0x1b794 */ cbz x0, #0x1b7c4;
    /* 0x1b798 */ ldr w8, [x0, #0x18];
    strstr();
    cJSON_GetObjectItem();
    strncpy();
    cJSON_GetObjectItem();
    strncpy();
    cJSON_GetObjectItem();
    strstr();
    cJSON_GetObjectItem();
    strncpy();
    cJSON_GetObjectItem();
    strstr();
    cJSON_GetObjectItem();
    strncpy();
    cJSON_GetObjectItem();
    strstr();
    cJSON_Delete();
    return x0;
}
