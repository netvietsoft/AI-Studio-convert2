# TASK_173 R1 — manual register-level pseudocode for two unresolved NEON exports

**Evidence class:** human register-level reconstruction from the pinned original AArch64 bytes, Capstone's complete instruction ranges, and Ghidra raw/normalized p-code. This is **not** Ghidra C-like decompilation, a compiled replacement, or proven behavioral equivalence. The only alternative Ghidra `normalize` call for each target completed but returned an empty C body; see `alternative_2283_raw.json`, `alternative_2330_raw.json`, commands, stdout, stderr, and their hashes in `COMPLETE.json`.

Notation: each `u8x16` operation is lane-wise on 16 unsigned byte samples, and `R_n(a)=(a+2^(n-1))>>n` denotes the rounding shift followed by narrowing used by `RSHRN`. `select(mask,new,old)` denotes AArch64 `BIT` at each bit. All pointer increments, vector transposes, and branch conditions below are tied to exact instruction addresses. The complete **per-instruction** evidence for every byte of both bodies is in `source_assembly_2283.txt` (184 instructions), `source_assembly_2330.txt` (58 instructions), and the `instructions` plus `raw_pcode` arrays in the two Ghidra raw files. No branch destination is omitted from those files.

## Index 2283, `x264_8_deblock_h_luma_intra_neon`, VA 0x658fe8, 736 bytes

Original body SHA-256: `94017dc1deb91f10d8a4fd18f131f5d7741d0512c73c533de6d9845fbe095cee`. This function takes `x0` as the initial pixel pointer, `x1` as the row stride, and `w2`,`w3` as `alpha`,`beta` byte thresholds. `ORR/CMP/B.NE/RET` at 0x658fe8–0x658ff4 returns when both thresholds are zero. `DUP` at 0x658ff8–0x658ffc broadcasts the thresholds.

`SUB x0,#4` at 0x659000 moves the read window four bytes left. The 16 `LD1` instructions at 0x659004–0x659040 load an 8-column by 16-row byte tile: each vector first receives eight low bytes from one row, then eight high bytes from a row eight strides later. The 24 `TRN1/TRN2` instructions at 0x659044–0x6590a0 transpose it. Replaying the literal interleave widths 1, 2, then 4 bytes in `scripts/task_173_codex_exports/symbolic_transpose.py` gives this byte-lane map, for lane `i=0..15`:

| Register after transpose | Tile source | Boundary role |
|---|---|---|
| `v4[i]` | row `i`, column 0 | `p3` |
| `v5[i]` | row `i`, column 1 | `p2` |
| `v6[i]` | row `i`, column 2 | `p1` |
| `v7[i]` | row `i`, column 3 | `p0` |
| `v0[i]` | row `i`, column 4 | `q0` |
| `v1[i]` | row `i`, column 5 | `q1` |
| `v2[i]` | row `i`, column 6 | `q2` |
| `v3[i]` | row `i`, column 7 | `q3` |

The following is a **manual lane-wise transcription** of the vector arithmetic; every expression maps to the specific instruction span shown. The `>` comparisons are strict because the original uses unsigned `CMHI`.

```text
# 0x6590a4–0x6590d0: UABD/CMHI/MOVI/USHR/ADD/AND
base = (alpha > abs(p0-q0))
     & (beta > abs(p1-p0))
     & (beta > abs(q1-q0))
strong_edge = ((alpha >> 2) + 2) > abs(p0-q0)

# 0x6590d4–0x6590dc: SHRN/MOV/CBZ; if no lane in base is set, return
if all lanes of base are false: return

# 0x6590e0–0x65911c: USHLL/UADDW/RSHRN
weak_p0 = R_2(2*p1 + p0 + q1)
weak_q0 = R_2(2*q1 + q0 + p1)

# 0x659120–0x65914c: UABD/CMHI/AND/MVN
strong_p = base & strong_edge & (beta > abs(p2-p0))
strong_q = base & strong_edge & (beta > abs(q2-q0))
weak_only_p = base & ~strong_p
weak_only_q = base & ~strong_q

# 0x659150–0x6591a4: UADDL/UADDW/ADD/SHL/RSHRN
strong_p0 = R_3(p2 + 2*p1 + 2*p0 + 2*q0 + q1)
strong_p1 = R_2(p2 + p1 + p0 + q0)
strong_p2 = R_3(2*p3 + 3*p2 + p1 + p0 + q0)

# 0x6591a8–0x6591fc: mirrored q-side vector instructions
strong_q0 = R_3(q2 + 2*q1 + 2*q0 + 2*p0 + p1)
strong_q1 = R_2(q2 + q1 + q0 + p0)
strong_q2 = R_3(2*q3 + 3*q2 + q1 + q0 + p0)

# 0x659200–0x65921c: BIT, preserving original bytes on unset masks
p0 = select(strong_p, strong_p0, select(weak_only_p, weak_p0, p0))
p1 = select(strong_p, strong_p1, p1)
p2 = select(strong_p, strong_p2, p2)
q0 = select(strong_q, strong_q0, select(weak_only_q, weak_q0, q0))
q1 = select(strong_q, strong_q1, q1)
q2 = select(strong_q, strong_q2, q2)
# p3 and q3 remain the loaded values.
```

The repeated 24 `TRN1/TRN2` instructions at 0x659220–0x65927c reverse the tile layout. `SUB x0,x0,x1,lsl #4` at 0x659280 restores the tile start. The 16 `ST1` instructions at 0x659284–0x6592c0 write eight low bytes and eight high bytes for each of 16 rows, postincrementing by the stride; `RET` at 0x6592c4 exits. The register-lane formulas describe this static path only; no dynamic pixel equivalence test was run.

## Index 2330, `x264_8_frame_init_lowres_core_neon`, VA 0x65aea8, 232 bytes

Original body SHA-256: `0b7e289d57ad0368923c5a802869b755b47eb70e43ff290fcd1096388ca46439`. At 0x65aea8, `w8=[sp]` is the outer count. At 0x65aeac–0x65aeb0, `x10=(x6-zeroExtend(w7)) & ~15` is the output row adjustment after stores. At 0x65aeb4–0x65aec0, `w9=w7`, `x11=x0`, `x12=x0+x5`, `x13=x0+2*x5`; there is no pre-loop zero-count guard in this body.

Define `load2(P)` as the exact `LD2 {Va.16b,Vb.16b},[P],#32`: deinterleave 32 consecutive source bytes into even and odd 16-byte vectors and advance the pointer by 32. Define `avg(A,B)` as byte-lane `(A+B+1)>>1` from `URHADD`, and `shift1(A,B)` as bytes 1..16 of the concatenated 32-byte `A||B` from `EXT ...,#1`. The following transcription preserves vector-register dependencies, the output pointer order, and both loop branches:

```text
# 0x65aec4–0x65aecc: first LD2 from x11, x12, x13
(v0,v1)=load2(x11); (v2,v3)=load2(x12); (v4,v5)=load2(x13)
# 0x65aed0–0x65aee0: first adjacent-row averages and width decrement
v20=avg(v0,v2); v22=avg(v2,v4); w9=w9-16
v21=avg(v1,v3); v23=avg(v3,v5)

# 0x65aee4–0x65aef4: next three LD2 and their even-byte averages
(v0,v1)=load2(x11); (v2,v3)=load2(x12); (v4,v5)=load2(x13)
v30=avg(v0,v2); v31=avg(v2,v4)

# 0x65aef8–0x65af1c: first 16-pixel output group
v24=shift1(v20,v30); v25=shift1(v22,v31)
v16=avg(v20,v21); v18=avg(v22,v23)
v17=avg(v21,v24); v19=avg(v23,v25)
store16(x1,v16); store16(x3,v18); store16(x2,v17); store16(x4,v19)
# Each ST1 at 0x65af10–0x65af1c advances its own output pointer by 16.
if signed(w9) <= 0: goto outer_tail          # B.LE 0x65af20

# 0x65af24–0x65af68: alternating second output group
w9=w9-16; v21=avg(v1,v3); v23=avg(v3,v5)
(v0,v1)=load2(x11); (v2,v3)=load2(x12); (v4,v5)=load2(x13)
v20=avg(v0,v2); v22=avg(v2,v4)
v24=shift1(v30,v20); v25=shift1(v31,v22)
v16=avg(v30,v21); v18=avg(v31,v23)
v17=avg(v21,v24); v19=avg(v23,v25)
store16(x1,v16); store16(x3,v18); store16(x2,v17); store16(x4,v19)
if signed(w9) > 0: goto 0x65aed8             # B.GT 0x65af6c

outer_tail:                                     # 0x65af70–0x65af8c
w8=w8-1; x0=x0+2*x5
x1=x1+x10; x2=x2+x10; x3=x3+x10; x4=x4+x10
if signed(w8) > 0: goto 0x65aeb4             # B.GT 0x65af88
return
```

The expressions describe the exact observed `LD2`, `URHADD`, `EXT`, `ST1`, `SUBS`, and conditional-branch spans. They do not assert safe dimensions, buffer boundaries, higher-level image meaning, or equivalence to a product implementation. The pinned source bytes and full disassembly are the authoritative evidence if any pseudocode wording is ambiguous.
