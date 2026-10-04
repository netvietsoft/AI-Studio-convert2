// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x60244
// Recovered Name: _ZN17MMDetectionPlugin13SegmentModule16unregisterModuleEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x60244 | Size: 20 bytes | SHA256: 0120ebecfb3458fdb3568793173c81474e59fa6b4b36c1f4f4ac9e27471f02d2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: vlai_engine_session_module_unload

void _ZN17MMDetectionPlugin13SegmentModule16unregisterModuleEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x60244 */ ldr x0, [x0, #0x20];
    /* 0x60248 */ cbz x0, #0x60254;
    /* 0x6024c */ mov w1, #0x3e8;
    /* 0x60250 */ b #0x7a090;
    return x0;
}
