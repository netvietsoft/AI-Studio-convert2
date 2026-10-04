// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e144
// Recovered Name: sub_2e144
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e144 | Size: 396 bytes | SHA256: 8b6e134c7f21a212c4990c1334452e0b314a94138aaa9bd50da3692d821a32a8
// Callers: 0 | Callees: 3 | Imports: 6

// Calls external APIs: _ZN3MFX10MFXManager26getMaximumNbSamplePerBlockEv, _ZN3MFX10MFXManager38getAudioParameterSupportedByProcessingEv, _ZN3MFX21transformSampleFormatENS_13FormatLibTypeEiS0_, _ZN3MFX25AudioSourceAnalyzedResultC1Ev, _Znwm, __stack_chk_fail

void sub_2e144(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 99 instructions
    /* 0x2e144 */ stp x29, x30, [sp, #0xf0];
    /* 0x2e148 */ str x28, [sp, #0x100];
    /* 0x2e14c */ stp x24, x23, [sp, #0x110];
    /* 0x2e150 */ stp x22, x21, [sp, #0x120];
    /* 0x2e154 */ stp x20, x19, [sp, #0x130];
    /* 0x2e158 */ add x29, sp, #0xf0;
    /* 0x2e15c */ mrs x23, tpidr_el0;
    /* 0x2e160 */ mov x19, x8;
    /* 0x2e164 */ mov x20, x0;
    /* 0x2e168 */ ldr x8, [x23, #0x28];
    /* 0x2e16c */ add x24, sp, #0x48;
    _ZN3MFX10MFXManager38getAudioParameterSupportedByProcessingEv();
    _ZN3MFX21transformSampleFormatENS_13FormatLibTypeEiS0_();
    _ZN3MFX10MFXManager26getMaximumNbSamplePerBlockEv();
    _ZN3MFX25AudioSourceAnalyzedResultC1Ev();
    _Znwm();
    sub_378a8();
    return x0;
    sub_2e2d0();
    sub_76b64();
    __stack_chk_fail();
}
