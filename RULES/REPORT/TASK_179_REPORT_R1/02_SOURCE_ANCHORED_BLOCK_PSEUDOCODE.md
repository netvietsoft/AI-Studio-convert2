# TASK_179 — source-anchored block pseudocode for the unresolved export

**Classification:** static interpretation of the original ARM64 words and lifted p-code. This is a **register/block-level reconstruction**, not a whole-function Ghidra C-like decompilation and not a runtime-verified behavioral contract. The only new Ghidra C-like output is for a synthetic **scalar-tail fragment**, isolated by changing function metadata in a copied analyzed project. No original source bytes were patched.

Original: `libglide-webp.so` SHA-256 `2f7f38acc0d294a3333069aa8a3c07e69d4bc0a64f162215578bd55dbe1a4486`; `WebPConvertRGBA32ToUV_C` at ELF VA `0x328dc`, 624 bytes, body SHA-256 `fc4cf89d6b719a3d8d73009a57a1e755ca9ce11dda3bdd03da45c5b869053404`. `source_proof.json` maps exactly one original `PT_LOAD` range. `instruction_evidence.json` records every 4-byte word, all 156 Capstone instructions, historical Ghidra lines and p-code counts. `cfg_evidence.json` records eight branch/return sites and eleven blocks. Sixteen spread instruction words were independently re-read from the original body.

## Register-level control flow

The following names describe observed register use, not a recovered source-level signature: `x0=src`, `x1=dst_1`, `x2=dst_2`, `w3=count`. Source records are four interleaved little-endian 16-bit lanes per 8-byte record. The fourth lane is loaded by SIMD but does not enter the arithmetic or the two stores.

```text
at 0x328dc:
    if signed(count) < 1: return                     # 0x328dc-0x328e0
    n = zero_extend_32(count)
    prefix = 0

    if n >= 9:                                       # 0x328e4-0x328f0
        end_1 = dst_1 + n
        end_2 = dst_2 + n
        source_last_halfword = src + 8*n - 2
        overlap_12 = (end_2 > dst_1) && (end_1 > dst_2)
        overlap_s1 = (source_last_halfword > dst_1) && (end_1 > src)
        overlap_s2 = (source_last_halfword > dst_2) && (end_2 > src)
        # All comparisons above are unsigned-address HI comparisons.
        if !(overlap_12 || overlap_s1 || overlap_s2): # 0x328f4-0x32948
            tail_count = (n & 7) if ((n & 7) != 0) else 8
            prefix = n - tail_count                   # 0x3294c-0x3297c
            for i in range(0, prefix, 8):            # 0x329a8-0x32ab0
                # ld4 reads 8 records, deinterleaving the four halfword lanes.
                for lane in range(8):
                    c0 = uint16_le(src + 8*(i+lane) + 0)
                    c1 = uint16_le(src + 8*(i+lane) + 2)
                    c2 = uint16_le(src + 8*(i+lane) + 4)
                    sum_1 = -9719*c0 - 19081*c1 + 28800*c2 + 0x02020000
                    sum_2 = 28800*c0 - 24116*c1 - 4684*c2 + 0x02020000
                    dst_1[i+lane] = sat_shift18(sum_1)
                    dst_2[i+lane] = sat_shift18(sum_2)
                # The actual code computes eight lanes in 32-bit NEON vectors,
                # narrows 32→16→8, then stores one D register per destination.
            src = original_src + 8*prefix             # 0x32ab4

    # x9 is 0 when the vector gate branches to this block; otherwise it is prefix.
    p1 = dst_1 + prefix                              # 0x32ab8
    p2 = dst_2 + prefix
    remaining = n - prefix
    do:                                              # 0x32ae0-0x32b44
        c0 = uint16_le(src + 0)
        c1 = uint16_le(src + 2)
        c2 = uint16_le(src + 4)
        src += 8
        sum_1 = -9719*c0 - 19081*c1 + 28800*c2 + 0x02020000
        sum_2 = 28800*c0 - 24116*c1 - 4684*c2 + 0x02020000
        *p1++ = sat_shift18(sum_1)
        *p2++ = sat_shift18(sum_2)
        remaining -= 1
    while remaining != 0
    return                                           # 0x32b48

sat_shift18(s) = clamp(ARM64_arithmetic_shift_right_32(s, 18), 0, 255)
```

The `sum_1` coefficients are directly anchored in scalar instructions `0x32ac4`, `0x32ac8`, `0x32acc`, `0x32ad0`, `0x32af0`, `0x32af8`, `0x32b00`, `0x32b04`; `sum_2` additionally uses `0x32ad8`, `0x32adc`, `0x32af4`, `0x32afc`, `0x32b08`, `0x32b14`. The scalar clamps/stores are at `0x32b0c-0x32b3c`. The SIMD coefficient registers are initialized at `0x32958-0x32998`; `ld4` is `0x329a8`; `mul`/`mla`/`umull`/`umlal` implement the two weighted sums at `0x329b0-0x32a28`; signed shift and saturation masks occur at `0x32a04-0x32a94`; narrowing and stores occur at `0x32a80-0x32aac`. The original tail block's isolated Ghidra output in `scalar_tail_probe_raw.json` independently exposes the same coefficient constants and two byte stores but is **not** evidence that the vector path or entire original function decompiled.

`sum_1` and `sum_2` are bounded within signed 32-bit for arbitrary 16-bit input lanes (maximum absolute unrounded magnitude `28800*65535 = 1,887,408,000`; adding `0x02020000 = 33,685,504` remains below `2^31`). Thus the NEON 32-bit lane operations and scalar 32-bit operations can be compared without assuming a hidden wider arithmetic type. The fourth 16-bit source lane is consumed by `ld4` but unused in the weighted sums; this says nothing about its intended semantic name.

## Explicit residual gap

The historical whole-function Ghidra pass failed with `Recoverable Error: Unable to find unique hash for varnode`. TASK_175's `normalize` pass emitted no C-like text. TASK_179's different pass yielded only scalar-tail C-like from a synthetic function. The SIMD portion above is source-grounded block pseudocode; there is still **no whole-function C-like decompiler output**. No original binary execution, output-image comparison, input contract, calling-context analysis, or device validation was performed. In particular, the export's name alone does not prove a color-space contract or image-level parity.
