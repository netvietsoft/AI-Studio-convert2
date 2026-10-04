// EXPORTED & PLT DISASSEMBLY FOR libfftw3.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfftw3.so (SHA-256: 0968CEE954C2BCBBB8DF9DACA5A9D122343B280462AAAD9533F083F15A4B1C32)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 382, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libfftw3.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000075a00 <.plt>:
   75a00:      	stp	x16, x30, [sp, #-0x10]!
   75a04:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a08:      	ldr	x17, [x16, #0xfc0]
   75a0c:      	add	x16, x16, #0xfc0
   75a10:      	br	x17
   75a14:      	nop
   75a18:      	nop
   75a1c:      	nop

0000000000075a20 <__cxa_finalize@plt>:
   75a20:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a24:      	ldr	x17, [x16, #0xfc8]
   75a28:      	add	x16, x16, #0xfc8
   75a2c:      	br	x17

0000000000075a30 <__cxa_atexit@plt>:
   75a30:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a34:      	ldr	x17, [x16, #0xfd0]
   75a38:      	add	x16, x16, #0xfd0
   75a3c:      	br	x17

0000000000075a40 <log@plt>:
   75a40:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a44:      	ldr	x17, [x16, #0xfd8]
   75a48:      	add	x16, x16, #0xfd8
   75a4c:      	br	x17

0000000000075a50 <sincos@plt>:
   75a50:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a54:      	ldr	x17, [x16, #0xfe0]
   75a58:      	add	x16, x16, #0xfe0
   75a5c:      	br	x17

0000000000075a60 <fftwf_alignment_of@plt>:
   75a60:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a64:      	ldr	x17, [x16, #0xfe8]
   75a68:      	add	x16, x16, #0xfe8
   75a6c:      	br	x17

0000000000075a70 <fftwf_malloc_plain@plt>:
   75a70:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a74:      	ldr	x17, [x16, #0xff0]
   75a78:      	add	x16, x16, #0xff0
   75a7c:      	br	x17

0000000000075a80 <fftwf_kernel_malloc@plt>:
   75a80:      	adrp	x16, 0x7d000 <fftwf_rdft_hc2cb_genus+0x2278>
   75a84:      	ldr	x17, [x16, #0xff8]
   75a88:      	add	x16, x16, #0xff8
   75a8c:      	br	x17

0000000000075a90 <fftwf_assertion_failed@plt>:
   75a90:      	adrp	x16, 0x7e000
   75a94:      	ldr	x17, [x16]
   75a98:      	add	x16, x16, #0x0
   75a9c:      	br	x17

0000000000075aa0 <fftwf_ifree@plt>:
   75aa0:      	adrp	x16, 0x7e000
   75aa4:      	ldr	x17, [x16, #0x8]
   75aa8:      	add	x16, x16, #0x8
   75aac:      	br	x17

0000000000075ab0 <fftwf_kernel_free@plt>:
   75ab0:      	adrp	x16, 0x7e000
   75ab4:      	ldr	x17, [x16, #0x10]
   75ab8:      	add	x16, x16, #0x10
   75abc:      	br	x17

0000000000075ac0 <fftwf_ifree0@plt>:
   75ac0:      	adrp	x16, 0x7e000
   75ac4:      	ldr	x17, [x16, #0x18]
   75ac8:      	add	x16, x16, #0x18
   75acc:      	br	x17

0000000000075ad0 <fftwf_mkapiplan@plt>:
   75ad0:      	adrp	x16, 0x7e000
   75ad4:      	ldr	x17, [x16, #0x20]
   75ad8:      	add	x16, x16, #0x20
   75adc:      	br	x17

0000000000075ae0 <fftwf_the_planner@plt>:
   75ae0:      	adrp	x16, 0x7e000
   75ae4:      	ldr	x17, [x16, #0x28]
   75ae8:      	add	x16, x16, #0x28
   75aec:      	br	x17

0000000000075af0 <fftwf_get_crude_time@plt>:
   75af0:      	adrp	x16, 0x7e000
   75af4:      	ldr	x17, [x16, #0x30]
   75af8:      	add	x16, x16, #0x30
   75afc:      	br	x17

0000000000075b00 <fftwf_plan_destroy_internal@plt>:
   75b00:      	adrp	x16, 0x7e000
   75b04:      	ldr	x17, [x16, #0x38]
   75b08:      	add	x16, x16, #0x38
   75b0c:      	br	x17

0000000000075b10 <fftwf_mapflags@plt>:
   75b10:      	adrp	x16, 0x7e000
   75b14:      	ldr	x17, [x16, #0x40]
   75b18:      	add	x16, x16, #0x40
   75b1c:      	br	x17

0000000000075b20 <fftwf_plan_awake@plt>:
   75b20:      	adrp	x16, 0x7e000
   75b24:      	ldr	x17, [x16, #0x48]
   75b28:      	add	x16, x16, #0x48
   75b2c:      	br	x17

0000000000075b30 <fftwf_problem_destroy@plt>:
   75b30:      	adrp	x16, 0x7e000
   75b34:      	ldr	x17, [x16, #0x50]
   75b38:      	add	x16, x16, #0x50
   75b3c:      	br	x17

0000000000075b40 <fflush@plt>:
   75b40:      	adrp	x16, 0x7e000
   75b44:      	ldr	x17, [x16, #0x58]
   75b48:      	add	x16, x16, #0x58
   75b4c:      	br	x17

0000000000075b50 <fprintf@plt>:
   75b50:      	adrp	x16, 0x7e000
   75b54:      	ldr	x17, [x16, #0x60]
   75b58:      	add	x16, x16, #0x60
   75b5c:      	br	x17

0000000000075b60 <abort@plt>:
   75b60:      	adrp	x16, 0x7e000
   75b64:      	ldr	x17, [x16, #0x68]
   75b68:      	add	x16, x16, #0x68
   75b6c:      	br	x17

0000000000075b70 <fftwf_nbuf@plt>:
   75b70:      	adrp	x16, 0x7e000
   75b74:      	ldr	x17, [x16, #0x70]
   75b78:      	add	x16, x16, #0x70
   75b7c:      	br	x17

0000000000075b80 <fftwf_imax@plt>:
   75b80:      	adrp	x16, 0x7e000
   75b84:      	ldr	x17, [x16, #0x78]
   75b88:      	add	x16, x16, #0x78
   75b8c:      	br	x17

0000000000075b90 <fftwf_imin@plt>:
   75b90:      	adrp	x16, 0x7e000
   75b94:      	ldr	x17, [x16, #0x80]
   75b98:      	add	x16, x16, #0x80
   75b9c:      	br	x17

0000000000075ba0 <fftwf_bufdist@plt>:
   75ba0:      	adrp	x16, 0x7e000
   75ba4:      	ldr	x17, [x16, #0x88]
   75ba8:      	add	x16, x16, #0x88
   75bac:      	br	x17

0000000000075bb0 <fftwf_modulo@plt>:
   75bb0:      	adrp	x16, 0x7e000
   75bb4:      	ldr	x17, [x16, #0x90]
   75bb8:      	add	x16, x16, #0x90
   75bbc:      	br	x17

0000000000075bc0 <fftwf_toobig@plt>:
   75bc0:      	adrp	x16, 0x7e000
   75bc4:      	ldr	x17, [x16, #0x98]
   75bc8:      	add	x16, x16, #0x98
   75bcc:      	br	x17

0000000000075bd0 <fftwf_nbuf_redundant@plt>:
   75bd0:      	adrp	x16, 0x7e000
   75bd4:      	ldr	x17, [x16, #0xa0]
   75bd8:      	add	x16, x16, #0xa0
   75bdc:      	br	x17

0000000000075be0 <fftwf_mksolver@plt>:
   75be0:      	adrp	x16, 0x7e000
   75be4:      	ldr	x17, [x16, #0xa8]
   75be8:      	add	x16, x16, #0xa8
   75bec:      	br	x17

0000000000075bf0 <fftwf_solver_register@plt>:
   75bf0:      	adrp	x16, 0x7e000
   75bf4:      	ldr	x17, [x16, #0xb0]
   75bf8:      	add	x16, x16, #0xb0
   75bfc:      	br	x17

0000000000075c00 <fftwf_tensor_tornk1@plt>:
   75c00:      	adrp	x16, 0x7e000
   75c04:      	ldr	x17, [x16, #0xb8]
   75c08:      	add	x16, x16, #0xb8
   75c0c:      	br	x17

0000000000075c10 <fftwf_tensor_inplace_strides2@plt>:
   75c10:      	adrp	x16, 0x7e000
   75c14:      	ldr	x17, [x16, #0xc0]
   75c18:      	add	x16, x16, #0xc0
   75c1c:      	br	x17

0000000000075c20 <fftwf_tensor_sz@plt>:
   75c20:      	adrp	x16, 0x7e000
   75c24:      	ldr	x17, [x16, #0xc8]
   75c28:      	add	x16, x16, #0xc8
   75c2c:      	br	x17

0000000000075c30 <fftwf_mktensor_1d@plt>:
   75c30:      	adrp	x16, 0x7e000
   75c34:      	ldr	x17, [x16, #0xd0]
   75c38:      	add	x16, x16, #0xd0
   75c3c:      	br	x17

0000000000075c40 <fftwf_mkproblem_rdft_d@plt>:
   75c40:      	adrp	x16, 0x7e000
   75c44:      	ldr	x17, [x16, #0xd8]
   75c48:      	add	x16, x16, #0xd8
   75c4c:      	br	x17

0000000000075c50 <fftwf_mkplan_f_d@plt>:
   75c50:      	adrp	x16, 0x7e000
   75c54:      	ldr	x17, [x16, #0xe0]
   75c58:      	add	x16, x16, #0xe0
   75c5c:      	br	x17

0000000000075c60 <fftwf_mktensor_2d@plt>:
   75c60:      	adrp	x16, 0x7e000
   75c64:      	ldr	x17, [x16, #0xe8]
   75c68:      	add	x16, x16, #0xe8
   75c6c:      	br	x17

0000000000075c70 <fftwf_mkproblem_rdft_0_d@plt>:
   75c70:      	adrp	x16, 0x7e000
   75c74:      	ldr	x17, [x16, #0xf0]
   75c78:      	add	x16, x16, #0xf0
   75c7c:      	br	x17

0000000000075c80 <fftwf_mkplan_d@plt>:
   75c80:      	adrp	x16, 0x7e000
   75c84:      	ldr	x17, [x16, #0xf8]
   75c88:      	add	x16, x16, #0xf8
   75c8c:      	br	x17

0000000000075c90 <fftwf_tensor_copy@plt>:
   75c90:      	adrp	x16, 0x7e000
   75c94:      	ldr	x17, [x16, #0x100]
   75c98:      	add	x16, x16, #0x100
   75c9c:      	br	x17

0000000000075ca0 <fftwf_mkplan_rdft@plt>:
   75ca0:      	adrp	x16, 0x7e000
   75ca4:      	ldr	x17, [x16, #0x108]
   75ca8:      	add	x16, x16, #0x108
   75cac:      	br	x17

0000000000075cb0 <fftwf_ops_add@plt>:
   75cb0:      	adrp	x16, 0x7e000
   75cb4:      	ldr	x17, [x16, #0x110]
   75cb8:      	add	x16, x16, #0x110
   75cbc:      	br	x17

0000000000075cc0 <fftwf_ops_madd@plt>:
   75cc0:      	adrp	x16, 0x7e000
   75cc4:      	ldr	x17, [x16, #0x118]
   75cc8:      	add	x16, x16, #0x118
   75ccc:      	br	x17

0000000000075cd0 <__stack_chk_fail@plt>:
   75cd0:      	adrp	x16, 0x7e000
   75cd4:      	ldr	x17, [x16, #0x120]
   75cd8:      	add	x16, x16, #0x120
   75cdc:      	br	x17

0000000000075ce0 <fftwf_rdft2_inplace_strides@plt>:
   75ce0:      	adrp	x16, 0x7e000
   75ce4:      	ldr	x17, [x16, #0x128]
   75ce8:      	add	x16, x16, #0x128
   75cec:      	br	x17

0000000000075cf0 <fftwf_mkproblem_rdft2_d@plt>:
   75cf0:      	adrp	x16, 0x7e000
   75cf4:      	ldr	x17, [x16, #0x130]
   75cf8:      	add	x16, x16, #0x130
   75cfc:      	br	x17

0000000000075d00 <fftwf_mktensor_0d@plt>:
   75d00:      	adrp	x16, 0x7e000
   75d04:      	ldr	x17, [x16, #0x138]
   75d08:      	add	x16, x16, #0x138
   75d0c:      	br	x17

0000000000075d10 <fftwf_mkproblem_dft_d@plt>:
   75d10:      	adrp	x16, 0x7e000
   75d14:      	ldr	x17, [x16, #0x140]
   75d18:      	add	x16, x16, #0x140
   75d1c:      	br	x17

0000000000075d20 <fftwf_mkplan_rdft2@plt>:
   75d20:      	adrp	x16, 0x7e000
   75d24:      	ldr	x17, [x16, #0x148]
   75d28:      	add	x16, x16, #0x148
   75d2c:      	br	x17

0000000000075d30 <fftwf_reodft_conf_standard@plt>:
   75d30:      	adrp	x16, 0x7e000
   75d34:      	ldr	x17, [x16, #0x150]
   75d38:      	add	x16, x16, #0x150
   75d3c:      	br	x17

0000000000075d40 <fftwf_solvtab_exec@plt>:
   75d40:      	adrp	x16, 0x7e000
   75d44:      	ldr	x17, [x16, #0x158]
   75d48:      	add	x16, x16, #0x158
   75d4c:      	br	x17

0000000000075d50 <fftwf_rdft_conf_standard@plt>:
   75d50:      	adrp	x16, 0x7e000
   75d54:      	ldr	x17, [x16, #0x160]
   75d58:      	add	x16, x16, #0x160
   75d5c:      	br	x17

0000000000075d60 <fftwf_have_simd_neon@plt>:
   75d60:      	adrp	x16, 0x7e000
   75d64:      	ldr	x17, [x16, #0x168]
   75d68:      	add	x16, x16, #0x168
   75d6c:      	br	x17

0000000000075d70 <fftwf_configure_planner@plt>:
   75d70:      	adrp	x16, 0x7e000
   75d74:      	ldr	x17, [x16, #0x170]
   75d78:      	add	x16, x16, #0x170
   75d7c:      	br	x17

0000000000075d80 <fftwf_cpy2d@plt>:
   75d80:      	adrp	x16, 0x7e000
   75d84:      	ldr	x17, [x16, #0x178]
   75d88:      	add	x16, x16, #0x178
   75d8c:      	br	x17

0000000000075d90 <fftwf_cpy2d_ci@plt>:
   75d90:      	adrp	x16, 0x7e000
   75d94:      	ldr	x17, [x16, #0x180]
   75d98:      	add	x16, x16, #0x180
   75d9c:      	br	x17

0000000000075da0 <fftwf_cpy2d_co@plt>:
   75da0:      	adrp	x16, 0x7e000
   75da4:      	ldr	x17, [x16, #0x188]
   75da8:      	add	x16, x16, #0x188
   75dac:      	br	x17

0000000000075db0 <fftwf_compute_tilesz@plt>:
   75db0:      	adrp	x16, 0x7e000
   75db4:      	ldr	x17, [x16, #0x190]
   75db8:      	add	x16, x16, #0x190
   75dbc:      	br	x17

0000000000075dc0 <fftwf_tile2d@plt>:
   75dc0:      	adrp	x16, 0x7e000
   75dc4:      	ldr	x17, [x16, #0x198]
   75dc8:      	add	x16, x16, #0x198
   75dcc:      	br	x17

0000000000075dd0 <fftwf_regsolver_hc2c_direct@plt>:
   75dd0:      	adrp	x16, 0x7e000
   75dd4:      	ldr	x17, [x16, #0x1a0]
   75dd8:      	add	x16, x16, #0x1a0
   75ddc:      	br	x17

0000000000075de0 <fftwf_mksolver_hc2c@plt>:
   75de0:      	adrp	x16, 0x7e000
   75de4:      	ldr	x17, [x16, #0x1a8]
   75de8:      	add	x16, x16, #0x1a8
   75dec:      	br	x17

0000000000075df0 <fftwf_ct_uglyp@plt>:
   75df0:      	adrp	x16, 0x7e000
   75df4:      	ldr	x17, [x16, #0x1b0]
   75df8:      	add	x16, x16, #0x1b0
   75dfc:      	br	x17

0000000000075e00 <fftwf_mkplan_hc2c@plt>:
   75e00:      	adrp	x16, 0x7e000
   75e04:      	ldr	x17, [x16, #0x1b8]
   75e08:      	add	x16, x16, #0x1b8
   75e0c:      	br	x17

0000000000075e10 <fftwf_ops_zero@plt>:
   75e10:      	adrp	x16, 0x7e000
   75e14:      	ldr	x17, [x16, #0x1c0]
   75e18:      	add	x16, x16, #0x1c0
   75e1c:      	br	x17

0000000000075e20 <fftwf_ops_madd2@plt>:
   75e20:      	adrp	x16, 0x7e000
   75e24:      	ldr	x17, [x16, #0x1c8]
   75e28:      	add	x16, x16, #0x1c8
   75e2c:      	br	x17

0000000000075e30 <fftwf_twiddle_awake@plt>:
   75e30:      	adrp	x16, 0x7e000
   75e34:      	ldr	x17, [x16, #0x1d0]
   75e38:      	add	x16, x16, #0x1d0
   75e3c:      	br	x17

0000000000075e40 <fftwf_twiddle_length@plt>:
   75e40:      	adrp	x16, 0x7e000
   75e44:      	ldr	x17, [x16, #0x1d8]
   75e48:      	add	x16, x16, #0x1d8
   75e4c:      	br	x17

0000000000075e50 <fftwf_cpy2d_pair_ci@plt>:
   75e50:      	adrp	x16, 0x7e000
   75e54:      	ldr	x17, [x16, #0x1e0]
   75e58:      	add	x16, x16, #0x1e0
   75e5c:      	br	x17

0000000000075e60 <fftwf_cpy2d_pair_co@plt>:
   75e60:      	adrp	x16, 0x7e000
   75e64:      	ldr	x17, [x16, #0x1e8]
   75e68:      	add	x16, x16, #0x1e8
   75e6c:      	br	x17

0000000000075e70 <fftwf_choose_radix@plt>:
   75e70:      	adrp	x16, 0x7e000
   75e74:      	ldr	x17, [x16, #0x1f0]
   75e78:      	add	x16, x16, #0x1f0
   75e7c:      	br	x17

0000000000075e80 <fftwf_mktensor_3d@plt>:
   75e80:      	adrp	x16, 0x7e000
   75e84:      	ldr	x17, [x16, #0x1f8]
   75e88:      	add	x16, x16, #0x1f8
   75e8c:      	br	x17

0000000000075e90 <fftwf_mkproblem_rdft_1_d@plt>:
   75e90:      	adrp	x16, 0x7e000
   75e94:      	ldr	x17, [x16, #0x200]
   75e98:      	add	x16, x16, #0x200
   75e9c:      	br	x17

0000000000075ea0 <fftwf_mkplan@plt>:
   75ea0:      	adrp	x16, 0x7e000
   75ea4:      	ldr	x17, [x16, #0x208]
   75ea8:      	add	x16, x16, #0x208
   75eac:      	br	x17

0000000000075eb0 <fftwf_cpy1d@plt>:
   75eb0:      	adrp	x16, 0x7e000
   75eb4:      	ldr	x17, [x16, #0x210]
   75eb8:      	add	x16, x16, #0x210
   75ebc:      	br	x17

0000000000075ec0 <fftwf_tensor_append@plt>:
   75ec0:      	adrp	x16, 0x7e000
   75ec4:      	ldr	x17, [x16, #0x218]
   75ec8:      	add	x16, x16, #0x218
   75ecc:      	br	x17

0000000000075ed0 <fftwf_mkproblem_rdft_1@plt>:
   75ed0:      	adrp	x16, 0x7e000
   75ed4:      	ldr	x17, [x16, #0x220]
   75ed8:      	add	x16, x16, #0x220
   75edc:      	br	x17

0000000000075ee0 <fftwf_tensor_destroy2@plt>:
   75ee0:      	adrp	x16, 0x7e000
   75ee4:      	ldr	x17, [x16, #0x228]
   75ee8:      	add	x16, x16, #0x228
   75eec:      	br	x17

0000000000075ef0 <fftwf_mkplan_dft@plt>:
   75ef0:      	adrp	x16, 0x7e000
   75ef4:      	ldr	x17, [x16, #0x230]
   75ef8:      	add	x16, x16, #0x230
   75efc:      	br	x17

0000000000075f00 <fftwf_is_prime@plt>:
   75f00:      	adrp	x16, 0x7e000
   75f04:      	ldr	x17, [x16, #0x238]
   75f08:      	add	x16, x16, #0x238
   75f0c:      	br	x17

0000000000075f10 <fftwf_factors_into_small_primes@plt>:
   75f10:      	adrp	x16, 0x7e000
   75f14:      	ldr	x17, [x16, #0x240]
   75f18:      	add	x16, x16, #0x240
   75f1c:      	br	x17

0000000000075f20 <fftwf_factors_into@plt>:
   75f20:      	adrp	x16, 0x7e000
   75f24:      	ldr	x17, [x16, #0x248]
   75f28:      	add	x16, x16, #0x248
   75f2c:      	br	x17

0000000000075f30 <fftwf_find_generator@plt>:
   75f30:      	adrp	x16, 0x7e000
   75f34:      	ldr	x17, [x16, #0x250]
   75f38:      	add	x16, x16, #0x250
   75f3c:      	br	x17

0000000000075f40 <fftwf_power_mod@plt>:
   75f40:      	adrp	x16, 0x7e000
   75f44:      	ldr	x17, [x16, #0x258]
   75f48:      	add	x16, x16, #0x258
   75f4c:      	br	x17

0000000000075f50 <fftwf_rader_tl_find@plt>:
   75f50:      	adrp	x16, 0x7e000
   75f54:      	ldr	x17, [x16, #0x260]
   75f58:      	add	x16, x16, #0x260
   75f5c:      	br	x17

0000000000075f60 <fftwf_mktriggen@plt>:
   75f60:      	adrp	x16, 0x7e000
   75f64:      	ldr	x17, [x16, #0x268]
   75f68:      	add	x16, x16, #0x268
   75f6c:      	br	x17

0000000000075f70 <fftwf_safe_mulmod@plt>:
   75f70:      	adrp	x16, 0x7e000
   75f74:      	ldr	x17, [x16, #0x270]
   75f78:      	add	x16, x16, #0x270
   75f7c:      	br	x17

0000000000075f80 <fftwf_triggen_destroy@plt>:
   75f80:      	adrp	x16, 0x7e000
   75f84:      	ldr	x17, [x16, #0x278]
   75f88:      	add	x16, x16, #0x278
   75f8c:      	br	x17

0000000000075f90 <fftwf_rader_tl_delete@plt>:
   75f90:      	adrp	x16, 0x7e000
   75f94:      	ldr	x17, [x16, #0x280]
   75f98:      	add	x16, x16, #0x280
   75f9c:      	br	x17

0000000000075fa0 <memset@plt>:
   75fa0:      	adrp	x16, 0x7e000
   75fa4:      	ldr	x17, [x16, #0x288]
   75fa8:      	add	x16, x16, #0x288
   75fac:      	br	x17

0000000000075fb0 <fftwf_rader_tl_insert@plt>:
   75fb0:      	adrp	x16, 0x7e000
   75fb4:      	ldr	x17, [x16, #0x290]
   75fb8:      	add	x16, x16, #0x290
   75fbc:      	br	x17

0000000000075fc0 <fftwf_mksolver_rdft_r2c_direct@plt>:
   75fc0:      	adrp	x16, 0x7e000
   75fc4:      	ldr	x17, [x16, #0x298]
   75fc8:      	add	x16, x16, #0x298
   75fcc:      	br	x17

0000000000075fd0 <fftwf_mksolver_rdft_r2c_directbuf@plt>:
   75fd0:      	adrp	x16, 0x7e000
   75fd4:      	ldr	x17, [x16, #0x2a0]
   75fd8:      	add	x16, x16, #0x2a0
   75fdc:      	br	x17

0000000000075fe0 <fftwf_rdft_kind_str@plt>:
   75fe0:      	adrp	x16, 0x7e000
   75fe4:      	ldr	x17, [x16, #0x2a8]
   75fe8:      	add	x16, x16, #0x2a8
   75fec:      	br	x17

0000000000075ff0 <fftwf_mksolver_rdft2_direct@plt>:
   75ff0:      	adrp	x16, 0x7e000
   75ff4:      	ldr	x17, [x16, #0x2b0]
   75ff8:      	add	x16, x16, #0x2b0
   75ffc:      	br	x17

0000000000076000 <fftwf_hash@plt>:
   76000:      	adrp	x16, 0x7e000
   76004:      	ldr	x17, [x16, #0x2b8]
   76008:      	add	x16, x16, #0x2b8
   7600c:      	br	x17

0000000000076010 <fftwf_khc2c_register@plt>:
   76010:      	adrp	x16, 0x7e000
   76014:      	ldr	x17, [x16, #0x2c0]
   76018:      	add	x16, x16, #0x2c0
   7601c:      	br	x17

0000000000076020 <fftwf_regsolver_hc2hc_direct@plt>:
   76020:      	adrp	x16, 0x7e000
   76024:      	ldr	x17, [x16, #0x2c8]
   76028:      	add	x16, x16, #0x2c8
   7602c:      	br	x17

0000000000076030 <fftwf_mksolver_hc2hc@plt>:
   76030:      	adrp	x16, 0x7e000
   76034:      	ldr	x17, [x16, #0x2d0]
   76038:      	add	x16, x16, #0x2d0
   7603c:      	br	x17

0000000000076040 <fftwf_mkplan_hc2hc@plt>:
   76040:      	adrp	x16, 0x7e000
   76044:      	ldr	x17, [x16, #0x2d8]
   76048:      	add	x16, x16, #0x2d8
   7604c:      	br	x17

0000000000076050 <fftwf_khc2hc_register@plt>:
   76050:      	adrp	x16, 0x7e000
   76054:      	ldr	x17, [x16, #0x2e0]
   76058:      	add	x16, x16, #0x2e0
   7605c:      	br	x17

0000000000076060 <fftwf_iabs@plt>:
   76060:      	adrp	x16, 0x7e000
   76064:      	ldr	x17, [x16, #0x2e8]
   76068:      	add	x16, x16, #0x2e8
   7606c:      	br	x17

0000000000076070 <fftwf_tensor_copy_inplace@plt>:
   76070:      	adrp	x16, 0x7e000
   76074:      	ldr	x17, [x16, #0x2f0]
   76078:      	add	x16, x16, #0x2f0
   7607c:      	br	x17

0000000000076080 <fftwf_tensor_min_istride@plt>:
   76080:      	adrp	x16, 0x7e000
   76084:      	ldr	x17, [x16, #0x2f8]
   76088:      	add	x16, x16, #0x2f8
   7608c:      	br	x17

0000000000076090 <fftwf_tensor_min_ostride@plt>:
   76090:      	adrp	x16, 0x7e000
   76094:      	ldr	x17, [x16, #0x300]
   76098:      	add	x16, x16, #0x300
   7609c:      	br	x17

00000000000760a0 <malloc@plt>:
   760a0:      	adrp	x16, 0x7e000
   760a4:      	ldr	x17, [x16, #0x308]
   760a8:      	add	x16, x16, #0x308
   760ac:      	br	x17

00000000000760b0 <free@plt>:
   760b0:      	adrp	x16, 0x7e000
   760b4:      	ldr	x17, [x16, #0x310]
   760b8:      	add	x16, x16, #0x310
   760bc:      	br	x17

00000000000760c0 <fftwf_kr2c_register@plt>:
   760c0:      	adrp	x16, 0x7e000
   760c4:      	ldr	x17, [x16, #0x318]
   760c8:      	add	x16, x16, #0x318
   760cc:      	br	x17

00000000000760d0 <fftwf_map_r2r_kind@plt>:
   760d0:      	adrp	x16, 0x7e000
   760d4:      	ldr	x17, [x16, #0x320]
   760d8:      	add	x16, x16, #0x320
   760dc:      	br	x17

00000000000760e0 <fftwf_md5putc@plt>:
   760e0:      	adrp	x16, 0x7e000
   760e4:      	ldr	x17, [x16, #0x328]
   760e8:      	add	x16, x16, #0x328
   760ec:      	br	x17

00000000000760f0 <fftwf_md5puts@plt>:
   760f0:      	adrp	x16, 0x7e000
   760f4:      	ldr	x17, [x16, #0x330]
   760f8:      	add	x16, x16, #0x330
   760fc:      	br	x17

0000000000076100 <fftwf_md5int@plt>:
   76100:      	adrp	x16, 0x7e000
   76104:      	ldr	x17, [x16, #0x338]
   76108:      	add	x16, x16, #0x338
   7610c:      	br	x17

0000000000076110 <fftwf_md5INT@plt>:
   76110:      	adrp	x16, 0x7e000
   76114:      	ldr	x17, [x16, #0x340]
   76118:      	add	x16, x16, #0x340
   7611c:      	br	x17

0000000000076120 <fftwf_md5unsigned@plt>:
   76120:      	adrp	x16, 0x7e000
   76124:      	ldr	x17, [x16, #0x348]
   76128:      	add	x16, x16, #0x348
   7612c:      	br	x17

0000000000076130 <fftwf_md5begin@plt>:
   76130:      	adrp	x16, 0x7e000
   76134:      	ldr	x17, [x16, #0x350]
   76138:      	add	x16, x16, #0x350
   7613c:      	br	x17

0000000000076140 <fftwf_md5end@plt>:
   76140:      	adrp	x16, 0x7e000
   76144:      	ldr	x17, [x16, #0x358]
   76148:      	add	x16, x16, #0x358
   7614c:      	br	x17

0000000000076150 <fftwf_mktensor_rowmajor@plt>:
   76150:      	adrp	x16, 0x7e000
   76154:      	ldr	x17, [x16, #0x360]
   76158:      	add	x16, x16, #0x360
   7615c:      	br	x17

0000000000076160 <fftwf_mktensor@plt>:
   76160:      	adrp	x16, 0x7e000
   76164:      	ldr	x17, [x16, #0x368]
   76168:      	add	x16, x16, #0x368
   7616c:      	br	x17

0000000000076170 <fftwf_many_kosherp@plt>:
   76170:      	adrp	x16, 0x7e000
   76174:      	ldr	x17, [x16, #0x370]
   76178:      	add	x16, x16, #0x370
   7617c:      	br	x17

0000000000076180 <fftwf_tensor_inplace_strides@plt>:
   76180:      	adrp	x16, 0x7e000
   76184:      	ldr	x17, [x16, #0x378]
   76188:      	add	x16, x16, #0x378
   7618c:      	br	x17

0000000000076190 <fftwf_ops_other@plt>:
   76190:      	adrp	x16, 0x7e000
   76194:      	ldr	x17, [x16, #0x380]
   76198:      	add	x16, x16, #0x380
   7619c:      	br	x17

00000000000761a0 <fftwf_ops_add2@plt>:
   761a0:      	adrp	x16, 0x7e000
   761a4:      	ldr	x17, [x16, #0x388]
   761a8:      	add	x16, x16, #0x388
   761ac:      	br	x17

00000000000761b0 <fftwf_pickdim@plt>:
   761b0:      	adrp	x16, 0x7e000
   761b4:      	ldr	x17, [x16, #0x390]
   761b8:      	add	x16, x16, #0x390
   761bc:      	br	x17

00000000000761c0 <fftwf_plan_many_r2r@plt>:
   761c0:      	adrp	x16, 0x7e000
   761c4:      	ldr	x17, [x16, #0x398]
   761c8:      	add	x16, x16, #0x398
   761cc:      	br	x17

00000000000761d0 <fftwf_plan_r2r@plt>:
   761d0:      	adrp	x16, 0x7e000
   761d4:      	ldr	x17, [x16, #0x3a0]
   761d8:      	add	x16, x16, #0x3a0
   761dc:      	br	x17

00000000000761e0 <fftwf_mkplanner@plt>:
   761e0:      	adrp	x16, 0x7e000
   761e4:      	ldr	x17, [x16, #0x3a8]
   761e8:      	add	x16, x16, #0x3a8
   761ec:      	br	x17

00000000000761f0 <fftwf_solver_use@plt>:
   761f0:      	adrp	x16, 0x7e000
   761f4:      	ldr	x17, [x16, #0x3b0]
   761f8:      	add	x16, x16, #0x3b0
   761fc:      	br	x17

0000000000076200 <strcmp@plt>:
   76200:      	adrp	x16, 0x7e000
   76204:      	ldr	x17, [x16, #0x3b8]
   76208:      	add	x16, x16, #0x3b8
   7620c:      	br	x17

0000000000076210 <fftwf_planner_destroy@plt>:
   76210:      	adrp	x16, 0x7e000
   76214:      	ldr	x17, [x16, #0x3c0]
   76218:      	add	x16, x16, #0x3c0
   7621c:      	br	x17

0000000000076220 <fftwf_solver_destroy@plt>:
   76220:      	adrp	x16, 0x7e000
   76224:      	ldr	x17, [x16, #0x3c8]
   76228:      	add	x16, x16, #0x3c8
   7622c:      	br	x17

0000000000076230 <fftwf_elapsed_since@plt>:
   76230:      	adrp	x16, 0x7e000
   76234:      	ldr	x17, [x16, #0x3d0]
   76238:      	add	x16, x16, #0x3d0
   7623c:      	br	x17

0000000000076240 <fftwf_measure_execution_time@plt>:
   76240:      	adrp	x16, 0x7e000
   76244:      	ldr	x17, [x16, #0x3d8]
   76248:      	add	x16, x16, #0x3d8
   7624c:      	br	x17

0000000000076250 <fftwf_next_prime@plt>:
   76250:      	adrp	x16, 0x7e000
   76254:      	ldr	x17, [x16, #0x3e0]
   76258:      	add	x16, x16, #0x3e0
   7625c:      	br	x17

0000000000076260 <fftwf_isqrt@plt>:
   76260:      	adrp	x16, 0x7e000
   76264:      	ldr	x17, [x16, #0x3e8]
   76268:      	add	x16, x16, #0x3e8
   7626c:      	br	x17

0000000000076270 <fftwf_tensor_inplace_locations@plt>:
   76270:      	adrp	x16, 0x7e000
   76274:      	ldr	x17, [x16, #0x3f0]
   76278:      	add	x16, x16, #0x3f0
   7627c:      	br	x17

0000000000076280 <fftwf_mkproblem@plt>:
   76280:      	adrp	x16, 0x7e000
   76284:      	ldr	x17, [x16, #0x3f8]
   76288:      	add	x16, x16, #0x3f8
   7628c:      	br	x17

0000000000076290 <fftwf_tensor_compress@plt>:
   76290:      	adrp	x16, 0x7e000
   76294:      	ldr	x17, [x16, #0x400]
   76298:      	add	x16, x16, #0x400
   7629c:      	br	x17

00000000000762a0 <fftwf_tensor_compress_contiguous@plt>:
   762a0:      	adrp	x16, 0x7e000
   762a4:      	ldr	x17, [x16, #0x408]
   762a8:      	add	x16, x16, #0x408
   762ac:      	br	x17

00000000000762b0 <fftwf_mkproblem_unsolvable@plt>:
   762b0:      	adrp	x16, 0x7e000
   762b4:      	ldr	x17, [x16, #0x410]
   762b8:      	add	x16, x16, #0x410
   762bc:      	br	x17

00000000000762c0 <fftwf_tensor_md5@plt>:
   762c0:      	adrp	x16, 0x7e000
   762c4:      	ldr	x17, [x16, #0x418]
   762c8:      	add	x16, x16, #0x418
   762cc:      	br	x17

00000000000762d0 <fftwf_dft_zerotens@plt>:
   762d0:      	adrp	x16, 0x7e000
   762d4:      	ldr	x17, [x16, #0x420]
   762d8:      	add	x16, x16, #0x420
   762dc:      	br	x17

00000000000762e0 <fftwf_tensor_destroy@plt>:
   762e0:      	adrp	x16, 0x7e000
   762e4:      	ldr	x17, [x16, #0x428]
   762e8:      	add	x16, x16, #0x428
   762ec:      	br	x17

00000000000762f0 <fftwf_mkproblem_rdft@plt>:
   762f0:      	adrp	x16, 0x7e000
   762f4:      	ldr	x17, [x16, #0x430]
   762f8:      	add	x16, x16, #0x430
   762fc:      	br	x17

0000000000076300 <fftwf_dimcmp@plt>:
   76300:      	adrp	x16, 0x7e000
   76304:      	ldr	x17, [x16, #0x438]
   76308:      	add	x16, x16, #0x438
   7630c:      	br	x17

0000000000076310 <fftwf_mkproblem_rdft2@plt>:
   76310:      	adrp	x16, 0x7e000
   76314:      	ldr	x17, [x16, #0x440]
   76318:      	add	x16, x16, #0x440
   7631c:      	br	x17

0000000000076320 <fftwf_tensor_copy_except@plt>:
   76320:      	adrp	x16, 0x7e000
   76324:      	ldr	x17, [x16, #0x448]
   76328:      	add	x16, x16, #0x448
   7632c:      	br	x17

0000000000076330 <fftwf_tensor_copy_sub@plt>:
   76330:      	adrp	x16, 0x7e000
   76334:      	ldr	x17, [x16, #0x450]
   76338:      	add	x16, x16, #0x450
   7633c:      	br	x17

0000000000076340 <fftwf_tensor_min_stride@plt>:
   76340:      	adrp	x16, 0x7e000
   76344:      	ldr	x17, [x16, #0x458]
   76348:      	add	x16, x16, #0x458
   7634c:      	br	x17

0000000000076350 <fftwf_rdft2_tensor_max_index@plt>:
   76350:      	adrp	x16, 0x7e000
   76354:      	ldr	x17, [x16, #0x460]
   76358:      	add	x16, x16, #0x460
   7635c:      	br	x17

0000000000076360 <fftwf_tensor_split@plt>:
   76360:      	adrp	x16, 0x7e000
   76364:      	ldr	x17, [x16, #0x468]
   76368:      	add	x16, x16, #0x468
   7636c:      	br	x17

0000000000076370 <fftwf_tensor_destroy4@plt>:
   76370:      	adrp	x16, 0x7e000
   76374:      	ldr	x17, [x16, #0x470]
   76378:      	add	x16, x16, #0x470
   7637c:      	br	x17

0000000000076380 <fftwf_tensor_max_index@plt>:
   76380:      	adrp	x16, 0x7e000
   76384:      	ldr	x17, [x16, #0x478]
   76388:      	add	x16, x16, #0x478
   7638c:      	br	x17

0000000000076390 <memcpy@plt>:
   76390:      	adrp	x16, 0x7e000
   76394:      	ldr	x17, [x16, #0x480]
   76398:      	add	x16, x16, #0x480
   7639c:      	br	x17

00000000000763a0 <fftwf_rdft2_strides@plt>:
   763a0:      	adrp	x16, 0x7e000
   763a4:      	ldr	x17, [x16, #0x488]
   763a8:      	add	x16, x16, #0x488
   763ac:      	br	x17

00000000000763b0 <signal@plt>:
   763b0:      	adrp	x16, 0x7e000
   763b4:      	ldr	x17, [x16, #0x490]
   763b8:      	add	x16, x16, #0x490
   763bc:      	br	x17

00000000000763c0 <setjmp@plt>:
   763c0:      	adrp	x16, 0x7e000
   763c4:      	ldr	x17, [x16, #0x498]
   763c8:      	add	x16, x16, #0x498
   763cc:      	br	x17

00000000000763d0 <longjmp@plt>:
   763d0:      	adrp	x16, 0x7e000
   763d4:      	ldr	x17, [x16, #0x4a0]
   763d8:      	add	x16, x16, #0x4a0
   763dc:      	br	x17

00000000000763e0 <qsort@plt>:
   763e0:      	adrp	x16, 0x7e000
   763e4:      	ldr	x17, [x16, #0x4a8]
   763e8:      	add	x16, x16, #0x4a8
   763ec:      	br	x17

00000000000763f0 <gettimeofday@plt>:
   763f0:      	adrp	x16, 0x7e000
   763f4:      	ldr	x17, [x16, #0x4b0]
   763f8:      	add	x16, x16, #0x4b0
   763fc:      	br	x17

0000000000076400 <clock_gettime@plt>:
   76400:      	adrp	x16, 0x7e000
   76404:      	ldr	x17, [x16, #0x4b8]
   76408:      	add	x16, x16, #0x4b8
   7640c:      	br	x17

0000000000076410 <memmove@plt>:
   76410:      	adrp	x16, 0x7e000
   76414:      	ldr	x17, [x16, #0x4c0]
   76418:      	add	x16, x16, #0x4c0
   7641c:      	br	x17
