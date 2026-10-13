# TASK_182 R1 - source-anchored SIMD correction

**Classification: static register/block analysis, not recovered C.** The only new Ghidra pass replaced original function metadata in a byte-verified read-only project copy with a synthetic `0x3294c..0x32ab4` vector region. It did not modify original bytes. The `decompile` style returned `Recoverable Error: Unable to find unique hash for varnode` in 67.70 ms, with no C-like fragment. `VectorProbe182.java` verified the whole original 624-byte memory SHA, all 90 instructions and 999 p-code ops before that result. The historical source project hashes remained unchanged.

## Entry state, required for interpreting the fragment

The synthetic vector function is entered only after the original path at `0x328dc..0x32948`. `w3` passed signed `>=1` and unsigned `>=9` checks; `x8` received the zero-extended `w3` count at `0x328e8`. `x0` is the source pointer and `x1`/`x2` are destination pointers by observed loads/stores, without a verified calling-context contract. Three unsigned-address overlap tests must branch **not taken** before `0x3294c`; their address arithmetic and gate are visible in the original instruction/p-code records. Source and destinations are assumed valid only for static interpretation. No runtime path feasibility, pointer aliasing beyond that gate, or pixel contract was tested.

## Byte-anchored vector operations

The original `ld4 {v16.8h,v17.8h,v18.8h,v19.8h},[x0],#64` at `0x329a8` reads eight 8-byte records and deinterleaves four 16-bit lanes. The fourth lane is loaded but is not referenced by the weighted sums in this loop. Setup instructions `0x32958..0x32998` replicate signed 32-bit coefficients `-9719`, `-19081`, `-24116`, `-4684`; unsigned halfword coefficient `28800`, bias `0x02020000`, comparison constant `256`, and saturation mask `0xff` per 32-bit lane. These are decoded immediates, not values inferred from the export name.

For each lane, register operations `mul/mla/umull/umlal` at `0x329b0..0x32a28` implement two 32-bit sums under the recorded entry-state assumption:

```text
s1 = -9719*c0 - 19081*c1 + 28800*c2 + 0x02020000
s2 = 28800*c0 - 24116*c1 - 4684*c2 + 0x02020000
```

Here `c0/c1/c2` are the first three unsigned 16-bit source lanes. Lower and upper groups of four lanes use `ushll/ushll2` and `ext`; destination 1 uses `v22/v21 -> v18/v17`, destination 2 uses `v28/v20 -> v16/v19`. For any 16-bit lane values, each unrounded weighted sum lies between `-1,887,408,000` and `1,887,408,000`; adding the bias keeps it within signed 32-bit, so the vector arithmetic does not require a wider type for these sums.

`sshr ...,#0x12` at `0x32a04/0x32a14/0x32a28/0x32a3c` performs signed arithmetic shift by 18. `cmlt` tests negative pre-shift sums, and `cmhi` checks whether unsigned shifted values are below 256. The `mvn/bic/and/orr` mask sequence at `0x32a20..0x32a94` yields zero for negative sums, the shifted value for the range 0..255, and 255 for higher nonnegative sums. `xtn/xtn2` at `0x32a80..0x32aa8` narrows 32→16→8 bits after clamping. `str d17,[x13],#8` at `0x32aa0` and `str d16,[x12],#8` at `0x32aac` write eight bytes to each destination; `b.ne 0x329a8` repeats after `subs x11,x11,#8`. The metadata-only C-like failure means this source-anchored register interpretation is the delivered SIMD evidence, not whole-function decompilation.

## Limitations

TASK_179's scalar-tail C-like was not rerun. The TASK_182 vector-only Ghidra pass is the sole corrective heavy pass (1 CPU, 1 GiB, 19.24 seconds, zero fresh imports). Its C-like coverage is **0/90 vector instructions** and **0/156 whole-original instructions**. Source-byte and assembly coverage of this vector interval is 90/90; historical Ghidra p-code alignment is 999/999; neither establishes observed runtime path coverage or image/pixel equivalence. No product, P0, phase, V4 or P7 status changes follow from this report.
