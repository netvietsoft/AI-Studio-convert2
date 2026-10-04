// Library: libffmpeg.so
// Function ID: libffmpeg::0x22960c
// Recovered Name: sub_22960c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x22960c | Size: 24 bytes | SHA256: de8127651e8a54f1a98dc011eec29453c4d7fa7a47bd8a99909e8369132c9987
// Callers: 2 | Callees: 0 | Imports: 0

// Strings referenced:
//   "segmentation_tree_probs[i].prob"
//   "segmentation_tree_probs[i].prob_coded"

void sub_22960c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x22960c */ adrp x22, #0xd9000;
    /* 0x229610 */ add x22, x22, #0x462;
    /* 0x229614 */ mov w27, #1;
    /* 0x229618 */ adrp x23, #0xa4000;
    /* 0x22961c */ add x23, x23, #0x40c;
    return x0;
}
