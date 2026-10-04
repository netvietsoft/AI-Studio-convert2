// EXPORTED & PLT DISASSEMBLY FOR libhiai_ir_build.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhiai_ir_build.so (SHA-256: 5357C178714545BA0EC715556F70252BF650DD53099170B3FE5519B6EC42CEDD)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 9, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhiai_ir_build.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000009ab0 <.plt>:
    9ab0:      	stp	x16, x30, [sp, #-0x10]!
    9ab4:      	adrp	x16, 0xe000
    9ab8:      	ldr	x17, [x16, #0x80]
    9abc:      	add	x16, x16, #0x80
    9ac0:      	br	x17
    9ac4:      	nop
    9ac8:      	nop
    9acc:      	nop

0000000000009ad0 <__cxa_finalize@plt>:
    9ad0:      	adrp	x16, 0xe000
    9ad4:      	ldr	x17, [x16, #0x88]
    9ad8:      	add	x16, x16, #0x88
    9adc:      	br	x17

0000000000009ae0 <__cxa_atexit@plt>:
    9ae0:      	adrp	x16, 0xe000
    9ae4:      	ldr	x17, [x16, #0x90]
    9ae8:      	add	x16, x16, #0x90
    9aec:      	br	x17

0000000000009af0 <_ZdlPv@plt>:
    9af0:      	adrp	x16, 0xe000
    9af4:      	ldr	x17, [x16, #0x98]
    9af8:      	add	x16, x16, #0x98
    9afc:      	br	x17

0000000000009b00 <__stack_chk_fail@plt>:
    9b00:      	adrp	x16, 0xe000
    9b04:      	ldr	x17, [x16, #0xa0]
    9b08:      	add	x16, x16, #0xa0
    9b0c:      	br	x17

0000000000009b10 <strlen@plt>:
    9b10:      	adrp	x16, 0xe000
    9b14:      	ldr	x17, [x16, #0xa8]
    9b18:      	add	x16, x16, #0xa8
    9b1c:      	br	x17

0000000000009b20 <_Znwm@plt>:
    9b20:      	adrp	x16, 0xe000
    9b24:      	ldr	x17, [x16, #0xb0]
    9b28:      	add	x16, x16, #0xb0
    9b2c:      	br	x17

0000000000009b30 <memmove@plt>:
    9b30:      	adrp	x16, 0xe000
    9b34:      	ldr	x17, [x16, #0xb8]
    9b38:      	add	x16, x16, #0xb8
    9b3c:      	br	x17

0000000000009b40 <_ZN4hiai11HiaiIrBuild15CreateModelBuffERN2ge5ModelERNS_15ModelBufferDataEj@plt>:
    9b40:      	adrp	x16, 0xe000
    9b44:      	ldr	x17, [x16, #0xc0]
    9b48:      	add	x16, x16, #0xc0
    9b4c:      	br	x17

0000000000009b50 <__strrchr_chk@plt>:
    9b50:      	adrp	x16, 0xe000
    9b54:      	ldr	x17, [x16, #0xc8]
    9b58:      	add	x16, x16, #0xc8
    9b5c:      	br	x17

0000000000009b60 <AI_Log_Print@plt>:
    9b60:      	adrp	x16, 0xe000
    9b64:      	ldr	x17, [x16, #0xd0]
    9b68:      	add	x16, x16, #0xd0
    9b6c:      	br	x17

0000000000009b70 <dlopen@plt>:
    9b70:      	adrp	x16, 0xe000
    9b74:      	ldr	x17, [x16, #0xd8]
    9b78:      	add	x16, x16, #0xd8
    9b7c:      	br	x17

0000000000009b80 <dlsym@plt>:
    9b80:      	adrp	x16, 0xe000
    9b84:      	ldr	x17, [x16, #0xe0]
    9b88:      	add	x16, x16, #0xe0
    9b8c:      	br	x17

0000000000009b90 <dlerror@plt>:
    9b90:      	adrp	x16, 0xe000
    9b94:      	ldr	x17, [x16, #0xe8]
    9b98:      	add	x16, x16, #0xe8
    9b9c:      	br	x17

0000000000009ba0 <_ZN2ge6BufferC1Ev@plt>:
    9ba0:      	adrp	x16, 0xe000
    9ba4:      	ldr	x17, [x16, #0xf0]
    9ba8:      	add	x16, x16, #0xf0
    9bac:      	br	x17

0000000000009bb0 <_ZNK2ge5Model4SaveERNS_6BufferE@plt>:
    9bb0:      	adrp	x16, 0xe000
    9bb4:      	ldr	x17, [x16, #0xf8]
    9bb8:      	add	x16, x16, #0xf8
    9bbc:      	br	x17

0000000000009bc0 <malloc@plt>:
    9bc0:      	adrp	x16, 0xe000
    9bc4:      	ldr	x17, [x16, #0x100]
    9bc8:      	add	x16, x16, #0x100
    9bcc:      	br	x17

0000000000009bd0 <_ZNK2ge6Buffer7GetSizeEv@plt>:
    9bd0:      	adrp	x16, 0xe000
    9bd4:      	ldr	x17, [x16, #0x108]
    9bd8:      	add	x16, x16, #0x108
    9bdc:      	br	x17

0000000000009be0 <free@plt>:
    9be0:      	adrp	x16, 0xe000
    9be4:      	ldr	x17, [x16, #0x110]
    9be8:      	add	x16, x16, #0x110
    9bec:      	br	x17

0000000000009bf0 <_ZN2ge6BufferD1Ev@plt>:
    9bf0:      	adrp	x16, 0xe000
    9bf4:      	ldr	x17, [x16, #0x118]
    9bf8:      	add	x16, x16, #0x118
    9bfc:      	br	x17

0000000000009c00 <dlclose@plt>:
    9c00:      	adrp	x16, 0xe000
    9c04:      	ldr	x17, [x16, #0x120]
    9c08:      	add	x16, x16, #0x120
    9c0c:      	br	x17

0000000000009c10 <_ZNK2ge5Model7GetNameEv@plt>:
    9c10:      	adrp	x16, 0xe000
    9c14:      	ldr	x17, [x16, #0x128]
    9c18:      	add	x16, x16, #0x128
    9c1c:      	br	x17

0000000000009c20 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
    9c20:      	adrp	x16, 0xe000
    9c24:      	ldr	x17, [x16, #0x130]
    9c28:      	add	x16, x16, #0x130
    9c2c:      	br	x17

0000000000009c30 <_ZN4hiai17CreateLocalBufferEPvmb@plt>:
    9c30:      	adrp	x16, 0xe000
    9c34:      	ldr	x17, [x16, #0x138]
    9c38:      	add	x16, x16, #0x138
    9c3c:      	br	x17

0000000000009c40 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
    9c40:      	adrp	x16, 0xe000
    9c44:      	ldr	x17, [x16, #0x140]
    9c48:      	add	x16, x16, #0x140
    9c4c:      	br	x17

0000000000009c50 <_ZN4hiai11HiaiIrBuild12BuildIRModelERN2ge5ModelERNS_15ModelBufferDataERKNS_12BuildOptionsE@plt>:
    9c50:      	adrp	x16, 0xe000
    9c54:      	ldr	x17, [x16, #0x148]
    9c58:      	add	x16, x16, #0x148
    9c5c:      	br	x17

0000000000009c60 <_ZN2ge9AttrUtils6SetIntEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKl@plt>:
    9c60:      	adrp	x16, 0xe000
    9c64:      	ldr	x17, [x16, #0x150]
    9c68:      	add	x16, x16, #0x150
    9c6c:      	br	x17

0000000000009c70 <_ZNK2ge5Model8GetGraphEv@plt>:
    9c70:      	adrp	x16, 0xe000
    9c74:      	ldr	x17, [x16, #0x158]
    9c78:      	add	x16, x16, #0x158
    9c7c:      	br	x17

0000000000009c80 <_ZN2ge10GraphUtils15GetComputeGraphERKNS_5GraphE@plt>:
    9c80:      	adrp	x16, 0xe000
    9c84:      	ldr	x17, [x16, #0x160]
    9c88:      	add	x16, x16, #0x160
    9c8c:      	br	x17

0000000000009c90 <_ZN4hiai13IRTransformer21VerifyIrReservedFieldENSt6__ndk110shared_ptrIN2ge12ComputeGraphEEE@plt>:
    9c90:      	adrp	x16, 0xe000
    9c94:      	ldr	x17, [x16, #0x168]
    9c98:      	add	x16, x16, #0x168
    9c9c:      	br	x17

0000000000009ca0 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
    9ca0:      	adrp	x16, 0xe000
    9ca4:      	ldr	x17, [x16, #0x170]
    9ca8:      	add	x16, x16, #0x170
    9cac:      	br	x17

0000000000009cb0 <_ZnwmRKSt9nothrow_t@plt>:
    9cb0:      	adrp	x16, 0xe000
    9cb4:      	ldr	x17, [x16, #0x178]
    9cb8:      	add	x16, x16, #0x178
    9cbc:      	br	x17

0000000000009cc0 <_ZN2ge15GraphListWalker12WalkOutNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
    9cc0:      	adrp	x16, 0xe000
    9cc4:      	ldr	x17, [x16, #0x180]
    9cc8:      	add	x16, x16, #0x180
    9ccc:      	br	x17

0000000000009cd0 <_ZN4hiai18CreateModelBuilderEv@plt>:
    9cd0:      	adrp	x16, 0xe000
    9cd4:      	ldr	x17, [x16, #0x188]
    9cd8:      	add	x16, x16, #0x188
    9cdc:      	br	x17

0000000000009ce0 <_ZNK2ge6Buffer7GetDataEv@plt>:
    9ce0:      	adrp	x16, 0xe000
    9ce4:      	ldr	x17, [x16, #0x190]
    9ce8:      	add	x16, x16, #0x190
    9cec:      	br	x17

0000000000009cf0 <_ZN2ge8NodeSpec6OpDescEv@plt>:
    9cf0:      	adrp	x16, 0xe000
    9cf4:      	ldr	x17, [x16, #0x198]
    9cf8:      	add	x16, x16, #0x198
    9cfc:      	br	x17

0000000000009d00 <_ZN2ge9AttrUtils10GetListIntEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_6vectorIlNS7_IlEEEE@plt>:
    9d00:      	adrp	x16, 0xe000
    9d04:      	ldr	x17, [x16, #0x1a0]
    9d08:      	add	x16, x16, #0x1a0
    9d0c:      	br	x17

0000000000009d10 <_ZNK2ge6OpDesc17GetInputsDescSizeEv@plt>:
    9d10:      	adrp	x16, 0xe000
    9d14:      	ldr	x17, [x16, #0x1a8]
    9d18:      	add	x16, x16, #0x1a8
    9d1c:      	br	x17

0000000000009d20 <_ZN2ge10AttrHolder7DelAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
    9d20:      	adrp	x16, 0xe000
    9d24:      	ldr	x17, [x16, #0x1b0]
    9d28:      	add	x16, x16, #0x1b0
    9d2c:      	br	x17

0000000000009d30 <_ZN2ge9AttrUtils7SetBoolEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKb@plt>:
    9d30:      	adrp	x16, 0xe000
    9d34:      	ldr	x17, [x16, #0x1b8]
    9d38:      	add	x16, x16, #0x1b8
    9d3c:      	br	x17

0000000000009d40 <_ZN2ge10TensorDesc11SetDataTypeENS_8DataTypeE@plt>:
    9d40:      	adrp	x16, 0xe000
    9d44:      	ldr	x17, [x16, #0x1c0]
    9d48:      	add	x16, x16, #0x1c0
    9d4c:      	br	x17

0000000000009d50 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
    9d50:      	adrp	x16, 0xe000
    9d54:      	ldr	x17, [x16, #0x1c8]
    9d58:      	add	x16, x16, #0x1c8
    9d5c:      	br	x17

0000000000009d60 <memset@plt>:
    9d60:      	adrp	x16, 0xe000
    9d64:      	ldr	x17, [x16, #0x1d0]
    9d68:      	add	x16, x16, #0x1d0
    9d6c:      	br	x17

0000000000009d70 <memcmp@plt>:
    9d70:      	adrp	x16, 0xe000
    9d74:      	ldr	x17, [x16, #0x1d8]
    9d78:      	add	x16, x16, #0x1d8
    9d7c:      	br	x17

0000000000009d80 <getauxval@plt>:
    9d80:      	adrp	x16, 0xe000
    9d84:      	ldr	x17, [x16, #0x1e0]
    9d88:      	add	x16, x16, #0x1e0
    9d8c:      	br	x17

0000000000009d90 <__system_property_get@plt>:
    9d90:      	adrp	x16, 0xe000
    9d94:      	ldr	x17, [x16, #0x1e8]
    9d98:      	add	x16, x16, #0x1e8
    9d9c:      	br	x17

0000000000009da0 <strncmp@plt>:
    9da0:      	adrp	x16, 0xe000
    9da4:      	ldr	x17, [x16, #0x1f0]
    9da8:      	add	x16, x16, #0x1f0
    9dac:      	br	x17
