// EXPORTED & PLT DISASSEMBLY FOR libhiai_ir.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhiai_ir.so (SHA-256: C96AF03947BDE73255F4B77E3C253AE63130FDFED8B259196D24BBF3BA84A7D1)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 1103, JNI Methods: 0


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libhiai_ir.so:	file format elf64-littleaarch64

Disassembly of section .plt:

00000000000cecc0 <.plt>:
   cecc0:      	stp	x16, x30, [sp, #-0x10]!
   cecc4:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cecc8:      	ldr	x17, [x16, #0x840]
   ceccc:      	add	x16, x16, #0x840
   cecd0:      	br	x17
   cecd4:      	nop
   cecd8:      	nop
   cecdc:      	nop

00000000000cece0 <__cxa_finalize@plt>:
   cece0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cece4:      	ldr	x17, [x16, #0x848]
   cece8:      	add	x16, x16, #0x848
   cecec:      	br	x17

00000000000cecf0 <__cxa_atexit@plt>:
   cecf0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cecf4:      	ldr	x17, [x16, #0x850]
   cecf8:      	add	x16, x16, #0x850
   cecfc:      	br	x17

00000000000ced00 <strlen@plt>:
   ced00:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced04:      	ldr	x17, [x16, #0x858]
   ced08:      	add	x16, x16, #0x858
   ced0c:      	br	x17

00000000000ced10 <_Znwm@plt>:
   ced10:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced14:      	ldr	x17, [x16, #0x860]
   ced18:      	add	x16, x16, #0x860
   ced1c:      	br	x17

00000000000ced20 <memmove@plt>:
   ced20:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced24:      	ldr	x17, [x16, #0x868]
   ced28:      	add	x16, x16, #0x868
   ced2c:      	br	x17

00000000000ced30 <_ZN4hiai12ProtoFactory8InstanceEv@plt>:
   ced30:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced34:      	ldr	x17, [x16, #0x870]
   ced38:      	add	x16, x16, #0x870
   ced3c:      	br	x17

00000000000ced40 <_ZN4hiai12ProtoFactory18CreateNamedAttrDefEv@plt>:
   ced40:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced44:      	ldr	x17, [x16, #0x878]
   ced48:      	add	x16, x16, #0x878
   ced4c:      	br	x17

00000000000ced50 <_ZN4hiai12ProtoFactory19DestroyNamedAttrDefEPNS_13INamedAttrDefE@plt>:
   ced50:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced54:      	ldr	x17, [x16, #0x880]
   ced58:      	add	x16, x16, #0x880
   ced5c:      	br	x17

00000000000ced60 <_ZN2ge9AttrValue10NamedAttrsD1Ev@plt>:
   ced60:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced64:      	ldr	x17, [x16, #0x888]
   ced68:      	add	x16, x16, #0x888
   ced6c:      	br	x17

00000000000ced70 <_ZdlPv@plt>:
   ced70:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced74:      	ldr	x17, [x16, #0x890]
   ced78:      	add	x16, x16, #0x890
   ced7c:      	br	x17

00000000000ced80 <_ZN2ge9AttrValue10NamedAttrsaSERKS1_@plt>:
   ced80:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced84:      	ldr	x17, [x16, #0x898]
   ced88:      	add	x16, x16, #0x898
   ced8c:      	br	x17

00000000000ced90 <_ZNK2ge9AttrValue10NamedAttrs7GetItemERKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE@plt>:
   ced90:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ced94:      	ldr	x17, [x16, #0x8a0]
   ced98:      	add	x16, x16, #0x8a0
   ced9c:      	br	x17

00000000000ceda0 <__strrchr_chk@plt>:
   ceda0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceda4:      	ldr	x17, [x16, #0x8a8]
   ceda8:      	add	x16, x16, #0x8a8
   cedac:      	br	x17

00000000000cedb0 <AI_Log_Print@plt>:
   cedb0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cedb4:      	ldr	x17, [x16, #0x8b0]
   cedb8:      	add	x16, x16, #0x8b0
   cedbc:      	br	x17

00000000000cedc0 <__cxa_guard_acquire@plt>:
   cedc0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cedc4:      	ldr	x17, [x16, #0x8b8]
   cedc8:      	add	x16, x16, #0x8b8
   cedcc:      	br	x17

00000000000cedd0 <_ZN2ge9AttrValueC1EPN4hiai8IAttrDefEb@plt>:
   cedd0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cedd4:      	ldr	x17, [x16, #0x8c0]
   cedd8:      	add	x16, x16, #0x8c0
   ceddc:      	br	x17

00000000000cede0 <_ZN2ge9AttrValueD1Ev@plt>:
   cede0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cede4:      	ldr	x17, [x16, #0x8c8]
   cede8:      	add	x16, x16, #0x8c8
   cedec:      	br	x17

00000000000cedf0 <__cxa_guard_release@plt>:
   cedf0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cedf4:      	ldr	x17, [x16, #0x8d0]
   cedf8:      	add	x16, x16, #0x8d0
   cedfc:      	br	x17

00000000000cee00 <__stack_chk_fail@plt>:
   cee00:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee04:      	ldr	x17, [x16, #0x8d8]
   cee08:      	add	x16, x16, #0x8d8
   cee0c:      	br	x17

00000000000cee10 <_ZN2ge9AttrValueC2Ev@plt>:
   cee10:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee14:      	ldr	x17, [x16, #0x8e0]
   cee18:      	add	x16, x16, #0x8e0
   cee1c:      	br	x17

00000000000cee20 <_ZN4hiai12ProtoFactory13CreateAttrDefEv@plt>:
   cee20:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee24:      	ldr	x17, [x16, #0x8e8]
   cee28:      	add	x16, x16, #0x8e8
   cee2c:      	br	x17

00000000000cee30 <_ZN4hiai12ProtoFactory14DestroyAttrDefEPNS_8IAttrDefE@plt>:
   cee30:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee34:      	ldr	x17, [x16, #0x8f0]
   cee38:      	add	x16, x16, #0x8f0
   cee3c:      	br	x17

00000000000cee40 <_ZN2ge9AttrValueaSERKS0_@plt>:
   cee40:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee44:      	ldr	x17, [x16, #0x8f8]
   cee48:      	add	x16, x16, #0x8f8
   cee4c:      	br	x17

00000000000cee50 <_ZNK2ge9AttrValue11SerializeToEPN4hiai8IAttrDefE@plt>:
   cee50:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee54:      	ldr	x17, [x16, #0x900]
   cee58:      	add	x16, x16, #0x900
   cee5c:      	br	x17

00000000000cee60 <_ZdaPv@plt>:
   cee60:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee64:      	ldr	x17, [x16, #0x908]
   cee68:      	add	x16, x16, #0x908
   cee6c:      	br	x17

00000000000cee70 <_ZN2ge9AttrValue6SetIntEl@plt>:
   cee70:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee74:      	ldr	x17, [x16, #0x910]
   cee78:      	add	x16, x16, #0x910
   cee7c:      	br	x17

00000000000cee80 <_ZNK2ge9AttrValue6GetIntEv@plt>:
   cee80:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee84:      	ldr	x17, [x16, #0x918]
   cee88:      	add	x16, x16, #0x918
   cee8c:      	br	x17

00000000000cee90 <_ZN2ge9AttrValue10CreateFromEl@plt>:
   cee90:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cee94:      	ldr	x17, [x16, #0x920]
   cee98:      	add	x16, x16, #0x920
   cee9c:      	br	x17

00000000000ceea0 <_ZN2ge9AttrValueC1Ev@plt>:
   ceea0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceea4:      	ldr	x17, [x16, #0x928]
   ceea8:      	add	x16, x16, #0x928
   ceeac:      	br	x17

00000000000ceeb0 <_ZN2ge9AttrValue8SetFloatEf@plt>:
   ceeb0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceeb4:      	ldr	x17, [x16, #0x930]
   ceeb8:      	add	x16, x16, #0x930
   ceebc:      	br	x17

00000000000ceec0 <_ZNK2ge9AttrValue8GetFloatEv@plt>:
   ceec0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceec4:      	ldr	x17, [x16, #0x938]
   ceec8:      	add	x16, x16, #0x938
   ceecc:      	br	x17

00000000000ceed0 <_ZN2ge9AttrValue10CreateFromEf@plt>:
   ceed0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceed4:      	ldr	x17, [x16, #0x940]
   ceed8:      	add	x16, x16, #0x940
   ceedc:      	br	x17

00000000000ceee0 <_ZN2ge9AttrValue7SetBoolEb@plt>:
   ceee0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceee4:      	ldr	x17, [x16, #0x948]
   ceee8:      	add	x16, x16, #0x948
   ceeec:      	br	x17

00000000000ceef0 <_ZNK2ge9AttrValue7GetBoolEv@plt>:
   ceef0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceef4:      	ldr	x17, [x16, #0x950]
   ceef8:      	add	x16, x16, #0x950
   ceefc:      	br	x17

00000000000cef00 <_ZN2ge9AttrValue10CreateFromEb@plt>:
   cef00:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef04:      	ldr	x17, [x16, #0x958]
   cef08:      	add	x16, x16, #0x958
   cef0c:      	br	x17

00000000000cef10 <_ZN2ge9AttrValue9SetStringERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cef10:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef14:      	ldr	x17, [x16, #0x960]
   cef18:      	add	x16, x16, #0x960
   cef1c:      	br	x17

00000000000cef20 <_ZNK2ge9AttrValue9GetStringEv@plt>:
   cef20:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef24:      	ldr	x17, [x16, #0x968]
   cef28:      	add	x16, x16, #0x968
   cef2c:      	br	x17

00000000000cef30 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cef30:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef34:      	ldr	x17, [x16, #0x970]
   cef38:      	add	x16, x16, #0x970
   cef3c:      	br	x17

00000000000cef40 <_ZN2ge9AttrValue9SetTensorERKNSt6__ndk110shared_ptrINS_6TensorEEE@plt>:
   cef40:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef44:      	ldr	x17, [x16, #0x978]
   cef48:      	add	x16, x16, #0x978
   cef4c:      	br	x17

00000000000cef50 <_ZNK2ge6Tensor11SerializeToEPN4hiai10ITensorDefE@plt>:
   cef50:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef54:      	ldr	x17, [x16, #0x980]
   cef58:      	add	x16, x16, #0x980
   cef5c:      	br	x17

00000000000cef60 <_ZNK2ge9AttrValue9GetTensorEv@plt>:
   cef60:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef64:      	ldr	x17, [x16, #0x988]
   cef68:      	add	x16, x16, #0x988
   cef6c:      	br	x17

00000000000cef70 <_ZnwmRKSt9nothrow_t@plt>:
   cef70:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef74:      	ldr	x17, [x16, #0x990]
   cef78:      	add	x16, x16, #0x990
   cef7c:      	br	x17

00000000000cef80 <_ZN2ge6TensorC1EPN4hiai10ITensorDefEb@plt>:
   cef80:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef84:      	ldr	x17, [x16, #0x998]
   cef88:      	add	x16, x16, #0x998
   cef8c:      	br	x17

00000000000cef90 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk110shared_ptrINS_6TensorEEE@plt>:
   cef90:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cef94:      	ldr	x17, [x16, #0x9a0]
   cef98:      	add	x16, x16, #0x9a0
   cef9c:      	br	x17

00000000000cefa0 <_ZN2ge9AttrValue13SetNamedAttrsERKNS0_10NamedAttrsE@plt>:
   cefa0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cefa4:      	ldr	x17, [x16, #0x9a8]
   cefa8:      	add	x16, x16, #0x9a8
   cefac:      	br	x17

00000000000cefb0 <_ZNK2ge9AttrValue13GetNamedAttrsEv@plt>:
   cefb0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cefb4:      	ldr	x17, [x16, #0x9b0]
   cefb8:      	add	x16, x16, #0x9b0
   cefbc:      	br	x17

00000000000cefc0 <_ZN2ge9AttrValue10NamedAttrsC1EPN4hiai13INamedAttrDefEb@plt>:
   cefc0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cefc4:      	ldr	x17, [x16, #0x9b8]
   cefc8:      	add	x16, x16, #0x9b8
   cefcc:      	br	x17

00000000000cefd0 <_ZN2ge9AttrValue10CreateFromERKNS0_10NamedAttrsE@plt>:
   cefd0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cefd4:      	ldr	x17, [x16, #0x9c0]
   cefd8:      	add	x16, x16, #0x9c0
   cefdc:      	br	x17

00000000000cefe0 <_ZN2ge9AttrValue8SetGraphERKNSt6__ndk110shared_ptrINS_12ComputeGraphEEE@plt>:
   cefe0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cefe4:      	ldr	x17, [x16, #0x9c8]
   cefe8:      	add	x16, x16, #0x9c8
   cefec:      	br	x17

00000000000ceff0 <_ZN4hiai12ProtoFactory14CreateGraphDefEv@plt>:
   ceff0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   ceff4:      	ldr	x17, [x16, #0x9d0]
   ceff8:      	add	x16, x16, #0x9d0
   ceffc:      	br	x17

00000000000cf000 <_ZNK2ge15GraphSerializer11SerializeToEPN4hiai9IGraphDefE@plt>:
   cf000:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf004:      	ldr	x17, [x16, #0x9d8]
   cf008:      	add	x16, x16, #0x9d8
   cf00c:      	br	x17

00000000000cf010 <_ZN4hiai12ProtoFactory15DestroyGraphDefEPNS_9IGraphDefE@plt>:
   cf010:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf014:      	ldr	x17, [x16, #0x9e0]
   cf018:      	add	x16, x16, #0x9e0
   cf01c:      	br	x17

00000000000cf020 <_ZNK2ge9AttrValue8GetGraphEv@plt>:
   cf020:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf024:      	ldr	x17, [x16, #0x9e8]
   cf028:      	add	x16, x16, #0x9e8
   cf02c:      	br	x17

00000000000cf030 <_ZN2ge12ComputeGraph4MakeEPN4hiai9IGraphDefEb@plt>:
   cf030:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf034:      	ldr	x17, [x16, #0x9f0]
   cf038:      	add	x16, x16, #0x9f0
   cf03c:      	br	x17

00000000000cf040 <_ZN2ge15GraphSerializer11UnSerializeEv@plt>:
   cf040:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf044:      	ldr	x17, [x16, #0x9f8]
   cf048:      	add	x16, x16, #0x9f8
   cf04c:      	br	x17

00000000000cf050 <_ZNSt6__ndk119__shared_weak_count14__release_weakEv@plt>:
   cf050:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf054:      	ldr	x17, [x16, #0xa00]
   cf058:      	add	x16, x16, #0xa00
   cf05c:      	br	x17

00000000000cf060 <_ZN2ge9AttrValue9SetBufferERKNS_6BufferE@plt>:
   cf060:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf064:      	ldr	x17, [x16, #0xa08]
   cf068:      	add	x16, x16, #0xa08
   cf06c:      	br	x17

00000000000cf070 <_ZNK2ge6Buffer7GetDataEv@plt>:
   cf070:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf074:      	ldr	x17, [x16, #0xa10]
   cf078:      	add	x16, x16, #0xa10
   cf07c:      	br	x17

00000000000cf080 <_ZNK2ge6Buffer7GetSizeEv@plt>:
   cf080:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf084:      	ldr	x17, [x16, #0xa18]
   cf088:      	add	x16, x16, #0xa18
   cf08c:      	br	x17

00000000000cf090 <_ZNK2ge9AttrValue9GetBufferEv@plt>:
   cf090:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf094:      	ldr	x17, [x16, #0xa20]
   cf098:      	add	x16, x16, #0xa20
   cf09c:      	br	x17

00000000000cf0a0 <_ZN2ge6BufferC1EPNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEb@plt>:
   cf0a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf0a4:      	ldr	x17, [x16, #0xa28]
   cf0a8:      	add	x16, x16, #0xa28
   cf0ac:      	br	x17

00000000000cf0b0 <_ZN2ge9AttrValue10CreateFromERKNS_6BufferE@plt>:
   cf0b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf0b4:      	ldr	x17, [x16, #0xa30]
   cf0b8:      	add	x16, x16, #0xa30
   cf0bc:      	br	x17

00000000000cf0c0 <_ZN2ge9AttrValue13SetTensorDescERKNS_10TensorDescE@plt>:
   cf0c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf0c4:      	ldr	x17, [x16, #0xa38]
   cf0c8:      	add	x16, x16, #0xa38
   cf0cc:      	br	x17

00000000000cf0d0 <_ZNK2ge10TensorDesc11SerializeToEPN4hiai14ITensorDescDefE@plt>:
   cf0d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf0d4:      	ldr	x17, [x16, #0xa40]
   cf0d8:      	add	x16, x16, #0xa40
   cf0dc:      	br	x17

00000000000cf0e0 <_ZNK2ge9AttrValue13GetTensorDescEv@plt>:
   cf0e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf0e4:      	ldr	x17, [x16, #0xa48]
   cf0e8:      	add	x16, x16, #0xa48
   cf0ec:      	br	x17

00000000000cf0f0 <_ZN2ge10TensorDescC1EPN4hiai14ITensorDescDefEb@plt>:
   cf0f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf0f4:      	ldr	x17, [x16, #0xa50]
   cf0f8:      	add	x16, x16, #0xa50
   cf0fc:      	br	x17

00000000000cf100 <_ZN2ge9AttrValue10SetIntListERKNSt6__ndk16vectorIlNS1_9allocatorIlEEEE@plt>:
   cf100:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf104:      	ldr	x17, [x16, #0xa58]
   cf108:      	add	x16, x16, #0xa58
   cf10c:      	br	x17

00000000000cf110 <_ZNK2ge9AttrValue10GetIntListEv@plt>:
   cf110:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf114:      	ldr	x17, [x16, #0xa60]
   cf118:      	add	x16, x16, #0xa60
   cf11c:      	br	x17

00000000000cf120 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorIlNS1_9allocatorIlEEEE@plt>:
   cf120:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf124:      	ldr	x17, [x16, #0xa68]
   cf128:      	add	x16, x16, #0xa68
   cf12c:      	br	x17

00000000000cf130 <_ZN2ge9AttrValue12SetFloatListERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   cf130:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf134:      	ldr	x17, [x16, #0xa70]
   cf138:      	add	x16, x16, #0xa70
   cf13c:      	br	x17

00000000000cf140 <_ZNK2ge9AttrValue12GetFloatListEv@plt>:
   cf140:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf144:      	ldr	x17, [x16, #0xa78]
   cf148:      	add	x16, x16, #0xa78
   cf14c:      	br	x17

00000000000cf150 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE@plt>:
   cf150:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf154:      	ldr	x17, [x16, #0xa80]
   cf158:      	add	x16, x16, #0xa80
   cf15c:      	br	x17

00000000000cf160 <_ZN2ge9AttrValue11SetBoolListERKNSt6__ndk16vectorIbNS1_9allocatorIbEEEE@plt>:
   cf160:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf164:      	ldr	x17, [x16, #0xa88]
   cf168:      	add	x16, x16, #0xa88
   cf16c:      	br	x17

00000000000cf170 <_ZNK2ge9AttrValue11GetBoolListEv@plt>:
   cf170:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf174:      	ldr	x17, [x16, #0xa90]
   cf178:      	add	x16, x16, #0xa90
   cf17c:      	br	x17

00000000000cf180 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorIbNS1_9allocatorIbEEEE@plt>:
   cf180:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf184:      	ldr	x17, [x16, #0xa98]
   cf188:      	add	x16, x16, #0xa98
   cf18c:      	br	x17

00000000000cf190 <_ZN2ge9AttrValue13SetStringListERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   cf190:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf194:      	ldr	x17, [x16, #0xaa0]
   cf198:      	add	x16, x16, #0xaa0
   cf19c:      	br	x17

00000000000cf1a0 <_ZNK2ge9AttrValue13GetStringListEv@plt>:
   cf1a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf1a4:      	ldr	x17, [x16, #0xaa8]
   cf1a8:      	add	x16, x16, #0xaa8
   cf1ac:      	br	x17

00000000000cf1b0 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEE@plt>:
   cf1b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf1b4:      	ldr	x17, [x16, #0xab0]
   cf1b8:      	add	x16, x16, #0xab0
   cf1bc:      	br	x17

00000000000cf1c0 <_ZN2ge9AttrValue13SetTensorListERKNSt6__ndk16vectorINS1_10shared_ptrINS_6TensorEEENS1_9allocatorIS5_EEEE@plt>:
   cf1c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf1c4:      	ldr	x17, [x16, #0xab8]
   cf1c8:      	add	x16, x16, #0xab8
   cf1cc:      	br	x17

00000000000cf1d0 <_ZNK2ge9AttrValue13GetTensorListEv@plt>:
   cf1d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf1d4:      	ldr	x17, [x16, #0xac0]
   cf1d8:      	add	x16, x16, #0xac0
   cf1dc:      	br	x17

00000000000cf1e0 <_ZN2ge9AttrValue17SetTensorDescListERKNSt6__ndk16vectorINS_10TensorDescENS1_9allocatorIS3_EEEE@plt>:
   cf1e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf1e4:      	ldr	x17, [x16, #0xac8]
   cf1e8:      	add	x16, x16, #0xac8
   cf1ec:      	br	x17

00000000000cf1f0 <_ZN2ge10TensorDescC1ERKS0_@plt>:
   cf1f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf1f4:      	ldr	x17, [x16, #0xad0]
   cf1f8:      	add	x16, x16, #0xad0
   cf1fc:      	br	x17

00000000000cf200 <_ZN2ge10TensorDescD1Ev@plt>:
   cf200:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf204:      	ldr	x17, [x16, #0xad8]
   cf208:      	add	x16, x16, #0xad8
   cf20c:      	br	x17

00000000000cf210 <_ZN2ge9AttrValue14SetIntListListERKNSt6__ndk16vectorINS2_IlNS1_9allocatorIlEEEENS3_IS5_EEEE@plt>:
   cf210:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf214:      	ldr	x17, [x16, #0xae0]
   cf218:      	add	x16, x16, #0xae0
   cf21c:      	br	x17

00000000000cf220 <_ZNK2ge9AttrValue14GetIntListListEv@plt>:
   cf220:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf224:      	ldr	x17, [x16, #0xae8]
   cf228:      	add	x16, x16, #0xae8
   cf22c:      	br	x17

00000000000cf230 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorINS2_IlNS1_9allocatorIlEEEENS3_IS5_EEEE@plt>:
   cf230:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf234:      	ldr	x17, [x16, #0xaf0]
   cf238:      	add	x16, x16, #0xaf0
   cf23c:      	br	x17

00000000000cf240 <_ZN2ge9AttrValue16SetFloatListListERKNSt6__ndk16vectorINS2_IfNS1_9allocatorIfEEEENS3_IS5_EEEE@plt>:
   cf240:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf244:      	ldr	x17, [x16, #0xaf8]
   cf248:      	add	x16, x16, #0xaf8
   cf24c:      	br	x17

00000000000cf250 <_ZNK2ge9AttrValue16GetFloatListListEv@plt>:
   cf250:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf254:      	ldr	x17, [x16, #0xb00]
   cf258:      	add	x16, x16, #0xb00
   cf25c:      	br	x17

00000000000cf260 <_ZN2ge9AttrValue10CreateFromERKNSt6__ndk16vectorINS2_IfNS1_9allocatorIfEEEENS3_IS5_EEEE@plt>:
   cf260:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf264:      	ldr	x17, [x16, #0xb08]
   cf268:      	add	x16, x16, #0xb08
   cf26c:      	br	x17

00000000000cf270 <_ZNK2ge9AttrValue12GetValueTypeEv@plt>:
   cf270:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf274:      	ldr	x17, [x16, #0xb10]
   cf278:      	add	x16, x16, #0xb10
   cf27c:      	br	x17

00000000000cf280 <_ZNK2ge9AttrValue7IsEmptyEv@plt>:
   cf280:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf284:      	ldr	x17, [x16, #0xb18]
   cf288:      	add	x16, x16, #0xb18
   cf28c:      	br	x17

00000000000cf290 <_ZNSt6__ndk122__libcpp_verbose_abortEPKcz@plt>:
   cf290:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf294:      	ldr	x17, [x16, #0xb20]
   cf298:      	add	x16, x16, #0xb20
   cf29c:      	br	x17

00000000000cf2a0 <memcmp@plt>:
   cf2a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf2a4:      	ldr	x17, [x16, #0xb28]
   cf2a8:      	add	x16, x16, #0xb28
   cf2ac:      	br	x17

00000000000cf2b0 <_ZNSt6__ndk119__shared_weak_countD2Ev@plt>:
   cf2b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf2b4:      	ldr	x17, [x16, #0xb30]
   cf2b8:      	add	x16, x16, #0xb30
   cf2bc:      	br	x17

00000000000cf2c0 <_ZN2ge9AttrValue10NamedAttrsC1Ev@plt>:
   cf2c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf2c4:      	ldr	x17, [x16, #0xb38]
   cf2c8:      	add	x16, x16, #0xb38
   cf2cc:      	br	x17

00000000000cf2d0 <_ZN2ge10AttrHolder7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_9AttrValueE@plt>:
   cf2d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf2d4:      	ldr	x17, [x16, #0xb40]
   cf2d8:      	add	x16, x16, #0xb40
   cf2dc:      	br	x17

00000000000cf2e0 <_ZN2ge10AttrHolder11MutableAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf2e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf2e4:      	ldr	x17, [x16, #0xb48]
   cf2e8:      	add	x16, x16, #0xb48
   cf2ec:      	br	x17

00000000000cf2f0 <_ZNK2ge10AttrHolder7GetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_9AttrValueE@plt>:
   cf2f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf2f4:      	ldr	x17, [x16, #0xb50]
   cf2f8:      	add	x16, x16, #0xb50
   cf2fc:      	br	x17

00000000000cf300 <_ZNK2ge10AttrHolder7GetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf300:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf304:      	ldr	x17, [x16, #0xb58]
   cf308:      	add	x16, x16, #0xb58
   cf30c:      	br	x17

00000000000cf310 <_ZNK2ge10AttrHolder7HasAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf310:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf314:      	ldr	x17, [x16, #0xb60]
   cf318:      	add	x16, x16, #0xb60
   cf31c:      	br	x17

00000000000cf320 <_ZN2ge10AttrHolder7DelAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf320:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf324:      	ldr	x17, [x16, #0xb68]
   cf328:      	add	x16, x16, #0xb68
   cf32c:      	br	x17

00000000000cf330 <_ZNK2ge10AttrHolder11GetAllAttrsEv@plt>:
   cf330:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf334:      	ldr	x17, [x16, #0xb70]
   cf338:      	add	x16, x16, #0xb70
   cf33c:      	br	x17

00000000000cf340 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_@plt>:
   cf340:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf344:      	ldr	x17, [x16, #0xb78]
   cf348:      	add	x16, x16, #0xb78
   cf34c:      	br	x17

00000000000cf350 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6resizeEmc@plt>:
   cf350:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf354:      	ldr	x17, [x16, #0xb80]
   cf358:      	add	x16, x16, #0xb80
   cf35c:      	br	x17

00000000000cf360 <_ZN2ge6Buffer8CopyFromEPKhmRS0_@plt>:
   cf360:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf364:      	ldr	x17, [x16, #0xb88]
   cf368:      	add	x16, x16, #0xb88
   cf36c:      	br	x17

00000000000cf370 <_ZN2ge6Buffer6ResizeEm@plt>:
   cf370:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf374:      	ldr	x17, [x16, #0xb90]
   cf378:      	add	x16, x16, #0xb90
   cf37c:      	br	x17

00000000000cf380 <_ZN2ge6Buffer5ClearEv@plt>:
   cf380:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf384:      	ldr	x17, [x16, #0xb98]
   cf388:      	add	x16, x16, #0xb98
   cf38c:      	br	x17

00000000000cf390 <_ZN2ge6BufferaSERKS0_@plt>:
   cf390:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf394:      	ldr	x17, [x16, #0xba0]
   cf398:      	add	x16, x16, #0xba0
   cf39c:      	br	x17

00000000000cf3a0 <_ZN2ge6Buffer11MutableDataEv@plt>:
   cf3a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf3a4:      	ldr	x17, [x16, #0xba8]
   cf3a8:      	add	x16, x16, #0xba8
   cf3ac:      	br	x17

00000000000cf3b0 <_ZN2ge6Buffer5RefToERKS0_@plt>:
   cf3b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf3b4:      	ldr	x17, [x16, #0xbb0]
   cf3b8:      	add	x16, x16, #0xbb0
   cf3bc:      	br	x17

00000000000cf3c0 <_ZN2ge6BufferC1Emh@plt>:
   cf3c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf3c4:      	ldr	x17, [x16, #0xbb8]
   cf3c8:      	add	x16, x16, #0xbb8
   cf3cc:      	br	x17

00000000000cf3d0 <_ZN2ge6BufferD1Ev@plt>:
   cf3d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf3d4:      	ldr	x17, [x16, #0xbc0]
   cf3d8:      	add	x16, x16, #0xbc0
   cf3dc:      	br	x17

00000000000cf3e0 <_ZN2ge12GraphBuilder5BuildERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS1_6vectorINS_8OperatorENS5_ISB_EEEE@plt>:
   cf3e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf3e4:      	ldr	x17, [x16, #0xbc8]
   cf3e8:      	add	x16, x16, #0xbc8
   cf3ec:      	br	x17

00000000000cf3f0 <_ZNK2ge5Graph7GetImplEv@plt>:
   cf3f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf3f4:      	ldr	x17, [x16, #0xbd0]
   cf3f8:      	add	x16, x16, #0xbd0
   cf3fc:      	br	x17

00000000000cf400 <_ZNK2ge5Graph7IsValidEv@plt>:
   cf400:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf404:      	ldr	x17, [x16, #0xbd8]
   cf408:      	add	x16, x16, #0xbd8
   cf40c:      	br	x17

00000000000cf410 <_ZN2ge5GraphC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf410:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf414:      	ldr	x17, [x16, #0xbe0]
   cf418:      	add	x16, x16, #0xbe0
   cf41c:      	br	x17

00000000000cf420 <_ZN2ge5GraphC1ERKNSt6__ndk110shared_ptrINS_9GraphImplEEE@plt>:
   cf420:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf424:      	ldr	x17, [x16, #0xbe8]
   cf428:      	add	x16, x16, #0xbe8
   cf42c:      	br	x17

00000000000cf430 <_ZNK2ge9GraphSpec4NameEv@plt>:
   cf430:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf434:      	ldr	x17, [x16, #0xbf0]
   cf438:      	add	x16, x16, #0xbf0
   cf43c:      	br	x17

00000000000cf440 <_ZNK2ge8Operator7GetImplEv@plt>:
   cf440:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf444:      	ldr	x17, [x16, #0xbf8]
   cf448:      	add	x16, x16, #0xbf8
   cf44c:      	br	x17

00000000000cf450 <_ZNK2ge11GraphFinder8FindNodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf450:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf454:      	ldr	x17, [x16, #0xc00]
   cf458:      	add	x16, x16, #0xc00
   cf45c:      	br	x17

00000000000cf460 <_ZN2ge13GraphModifier10SetOutputsERKNSt6__ndk16vectorIPNS_4NodeENS1_9allocatorIS4_EEEE@plt>:
   cf460:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf464:      	ldr	x17, [x16, #0xc08]
   cf468:      	add	x16, x16, #0xc08
   cf46c:      	br	x17

00000000000cf470 <_ZN2ge5ModelC2Ev@plt>:
   cf470:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf474:      	ldr	x17, [x16, #0xc10]
   cf478:      	add	x16, x16, #0xc10
   cf47c:      	br	x17

00000000000cf480 <_ZN4hiai12ProtoFactory14CreateModelDefEv@plt>:
   cf480:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf484:      	ldr	x17, [x16, #0xc18]
   cf488:      	add	x16, x16, #0xc18
   cf48c:      	br	x17

00000000000cf490 <_ZN4hiai12ProtoFactory15DestroyModelDefEPNS_9IModelDefE@plt>:
   cf490:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf494:      	ldr	x17, [x16, #0xc20]
   cf498:      	add	x16, x16, #0xc20
   cf49c:      	br	x17

00000000000cf4a0 <_ZN2ge5ModelD1Ev@plt>:
   cf4a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf4a4:      	ldr	x17, [x16, #0xc28]
   cf4a8:      	add	x16, x16, #0xc28
   cf4ac:      	br	x17

00000000000cf4b0 <_ZNK2ge5Model11SerializeToEPN4hiai9IModelDefE@plt>:
   cf4b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf4b4:      	ldr	x17, [x16, #0xc30]
   cf4b8:      	add	x16, x16, #0xc30
   cf4bc:      	br	x17

00000000000cf4c0 <_ZN2ge10GraphUtils15GetComputeGraphERKNS_5GraphE@plt>:
   cf4c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf4c4:      	ldr	x17, [x16, #0xc38]
   cf4c8:      	add	x16, x16, #0xc38
   cf4cc:      	br	x17

00000000000cf4d0 <_ZN2ge10GraphUtils27CreateGraphFromComputeGraphENSt6__ndk110shared_ptrINS_12ComputeGraphEEE@plt>:
   cf4d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf4d4:      	ldr	x17, [x16, #0xc40]
   cf4d8:      	add	x16, x16, #0xc40
   cf4dc:      	br	x17

00000000000cf4e0 <_ZNSt6__ndk19to_stringEj@plt>:
   cf4e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf4e4:      	ldr	x17, [x16, #0xc48]
   cf4e8:      	add	x16, x16, #0xc48
   cf4ec:      	br	x17

00000000000cf4f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm@plt>:
   cf4f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf4f4:      	ldr	x17, [x16, #0xc50]
   cf4f8:      	add	x16, x16, #0xc50
   cf4fc:      	br	x17

00000000000cf500 <_ZN2ge8OperatorC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_i@plt>:
   cf500:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf504:      	ldr	x17, [x16, #0xc58]
   cf508:      	add	x16, x16, #0xc58
   cf50c:      	br	x17

00000000000cf510 <_ZN2ge8Operator7SetAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE@plt>:
   cf510:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf514:      	ldr	x17, [x16, #0xc60]
   cf518:      	add	x16, x16, #0xc60
   cf51c:      	br	x17

00000000000cf520 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKcm@plt>:
   cf520:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf524:      	ldr	x17, [x16, #0xc68]
   cf528:      	add	x16, x16, #0xc68
   cf52c:      	br	x17

00000000000cf530 <_ZNK2ge6OpDesc20GetOutputIndexByNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf530:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf534:      	ldr	x17, [x16, #0xc70]
   cf538:      	add	x16, x16, #0xc70
   cf53c:      	br	x17

00000000000cf540 <_ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_@plt>:
   cf540:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf544:      	ldr	x17, [x16, #0xc78]
   cf548:      	add	x16, x16, #0xc78
   cf54c:      	br	x17

00000000000cf550 <_ZNK2ge6OpDesc19GetInputIndexByNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf550:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf554:      	ldr	x17, [x16, #0xc80]
   cf558:      	add	x16, x16, #0xc80
   cf55c:      	br	x17

00000000000cf560 <_ZNK2ge6OpDesc7GetTypeEv@plt>:
   cf560:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf564:      	ldr	x17, [x16, #0xc88]
   cf568:      	add	x16, x16, #0xc88
   cf56c:      	br	x17

00000000000cf570 <_ZN2ge8Operator17SetOpIsInputConstEbj@plt>:
   cf570:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf574:      	ldr	x17, [x16, #0xc90]
   cf578:      	add	x16, x16, #0xc90
   cf57c:      	br	x17

00000000000cf580 <_ZNK2ge8Operator17GetOpIsInputConstEv@plt>:
   cf580:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf584:      	ldr	x17, [x16, #0xc98]
   cf588:      	add	x16, x16, #0xc98
   cf58c:      	br	x17

00000000000cf590 <_ZNK2ge6OpDesc15GetIsInputConstEv@plt>:
   cf590:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf594:      	ldr	x17, [x16, #0xca0]
   cf598:      	add	x16, x16, #0xca0
   cf59c:      	br	x17

00000000000cf5a0 <_ZN2ge6OpDesc15SetIsInputConstERKNSt6__ndk16vectorIbNS1_9allocatorIbEEEE@plt>:
   cf5a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf5a4:      	ldr	x17, [x16, #0xca8]
   cf5a8:      	add	x16, x16, #0xca8
   cf5ac:      	br	x17

00000000000cf5b0 <_ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS1_4pairINS1_8weak_ptrINS_12OperatorImplEEEiEE@plt>:
   cf5b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf5b4:      	ldr	x17, [x16, #0xcb0]
   cf5b8:      	add	x16, x16, #0xcb0
   cf5bc:      	br	x17

00000000000cf5c0 <_ZNSt6__ndk119__shared_weak_count4lockEv@plt>:
   cf5c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf5c4:      	ldr	x17, [x16, #0xcb8]
   cf5c8:      	add	x16, x16, #0xcb8
   cf5cc:      	br	x17

00000000000cf5d0 <_ZN2ge8Operator8SetInputERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKS0_S9_@plt>:
   cf5d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf5d4:      	ldr	x17, [x16, #0xcc0]
   cf5d8:      	add	x16, x16, #0xcc0
   cf5dc:      	br	x17

00000000000cf5e0 <_ZNSt6__ndk19to_stringEi@plt>:
   cf5e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf5e4:      	ldr	x17, [x16, #0xcc8]
   cf5e8:      	add	x16, x16, #0xcc8
   cf5ec:      	br	x17

00000000000cf5f0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc@plt>:
   cf5f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf5f4:      	ldr	x17, [x16, #0xcd0]
   cf5f8:      	add	x16, x16, #0xcd0
   cf5fc:      	br	x17

00000000000cf600 <_ZN2ge12AscendStringC1EPKc@plt>:
   cf600:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf604:      	ldr	x17, [x16, #0xcd8]
   cf608:      	add	x16, x16, #0xcd8
   cf60c:      	br	x17

00000000000cf610 <_ZN2ge8Operator13InputRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf610:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf614:      	ldr	x17, [x16, #0xce0]
   cf618:      	add	x16, x16, #0xce0
   cf61c:      	br	x17

00000000000cf620 <_ZN2ge8Operator14OutputRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf620:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf624:      	ldr	x17, [x16, #0xce8]
   cf628:      	add	x16, x16, #0xce8
   cf62c:      	br	x17

00000000000cf630 <_ZN2ge8Operator12AttrRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS_9AttrValue9ValueTypeE@plt>:
   cf630:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf634:      	ldr	x17, [x16, #0xcf0]
   cf638:      	add	x16, x16, #0xcf0
   cf63c:      	br	x17

00000000000cf640 <_ZN2ge8Operator20OptionalAttrRegisterERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEONS_9AttrValueE@plt>:
   cf640:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf644:      	ldr	x17, [x16, #0xcf8]
   cf648:      	add	x16, x16, #0xcf8
   cf64c:      	br	x17

00000000000cf650 <_ZN2ge10TensorDescC1Ev@plt>:
   cf650:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf654:      	ldr	x17, [x16, #0xd00]
   cf658:      	add	x16, x16, #0xd00
   cf65c:      	br	x17

00000000000cf660 <memset@plt>:
   cf660:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf664:      	ldr	x17, [x16, #0xd08]
   cf668:      	add	x16, x16, #0xd08
   cf66c:      	br	x17

00000000000cf670 <_ZN2ge8OperatorC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_i@plt>:
   cf670:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf674:      	ldr	x17, [x16, #0xd10]
   cf678:      	add	x16, x16, #0xd10
   cf67c:      	br	x17

00000000000cf680 <_ZN2ge8OperatorC1EONSt6__ndk110shared_ptrINS_12OperatorImplEEE@plt>:
   cf680:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf684:      	ldr	x17, [x16, #0xd18]
   cf688:      	add	x16, x16, #0xd18
   cf68c:      	br	x17

00000000000cf690 <_ZN2ge6OpDescC1ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   cf690:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf694:      	ldr	x17, [x16, #0xd20]
   cf698:      	add	x16, x16, #0xd20
   cf69c:      	br	x17

00000000000cf6a0 <_ZNK2ge6OpDesc7GetNameEv@plt>:
   cf6a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf6a4:      	ldr	x17, [x16, #0xd28]
   cf6a8:      	add	x16, x16, #0xd28
   cf6ac:      	br	x17

00000000000cf6b0 <_ZN2ge6OpDesc15UpdateInputDescEjRKNS_10TensorDescE@plt>:
   cf6b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf6b4:      	ldr	x17, [x16, #0xd30]
   cf6b8:      	add	x16, x16, #0xd30
   cf6bc:      	br	x17

00000000000cf6c0 <_ZNK2ge6OpDesc20GetOutputNameByIndexEj@plt>:
   cf6c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf6c4:      	ldr	x17, [x16, #0xd38]
   cf6c8:      	add	x16, x16, #0xd38
   cf6cc:      	br	x17

00000000000cf6d0 <_ZNK2ge6OpDesc19GetInputNameByIndexEj@plt>:
   cf6d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf6d4:      	ldr	x17, [x16, #0xd40]
   cf6d8:      	add	x16, x16, #0xd40
   cf6dc:      	br	x17

00000000000cf6e0 <_ZN2ge5ShapeC1Ev@plt>:
   cf6e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf6e4:      	ldr	x17, [x16, #0xd48]
   cf6e8:      	add	x16, x16, #0xd48
   cf6ec:      	br	x17

00000000000cf6f0 <_ZN2ge10TensorDescC1ENS_5ShapeENS_6FormatENS_8DataTypeE@plt>:
   cf6f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf6f4:      	ldr	x17, [x16, #0xd50]
   cf6f8:      	add	x16, x16, #0xd50
   cf6fc:      	br	x17

00000000000cf700 <_ZN2ge6OpDesc12AddInputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_10TensorDescE@plt>:
   cf700:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf704:      	ldr	x17, [x16, #0xd58]
   cf708:      	add	x16, x16, #0xd58
   cf70c:      	br	x17

00000000000cf710 <_ZN2ge5ShapeD1Ev@plt>:
   cf710:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf714:      	ldr	x17, [x16, #0xd60]
   cf718:      	add	x16, x16, #0xd60
   cf71c:      	br	x17

00000000000cf720 <_ZN2ge6OpDesc18AddInputsParamTypeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   cf720:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf724:      	ldr	x17, [x16, #0xd68]
   cf728:      	add	x16, x16, #0xd68
   cf72c:      	br	x17

00000000000cf730 <_ZN2ge6OpDesc20AddOptionalInputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_10TensorDescE@plt>:
   cf730:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf734:      	ldr	x17, [x16, #0xd70]
   cf738:      	add	x16, x16, #0xd70
   cf73c:      	br	x17

00000000000cf740 <_ZN2ge6OpDesc19AddDynamicInputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEj@plt>:
   cf740:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf744:      	ldr	x17, [x16, #0xd78]
   cf748:      	add	x16, x16, #0xd78
   cf74c:      	br	x17

00000000000cf750 <_ZN2ge6OpDesc13AddOutputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_10TensorDescE@plt>:
   cf750:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf754:      	ldr	x17, [x16, #0xd80]
   cf758:      	add	x16, x16, #0xd80
   cf75c:      	br	x17

00000000000cf760 <_ZN2ge6OpDesc19AddOutPutsParamTypeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   cf760:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf764:      	ldr	x17, [x16, #0xd88]
   cf768:      	add	x16, x16, #0xd88
   cf76c:      	br	x17

00000000000cf770 <_ZN2ge6OpDesc20AddDynamicOutputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEj@plt>:
   cf770:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf774:      	ldr	x17, [x16, #0xd90]
   cf778:      	add	x16, x16, #0xd90
   cf77c:      	br	x17

00000000000cf780 <_ZN2ge6OpDesc15AddRequiredAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS_9AttrValue9ValueTypeE@plt>:
   cf780:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf784:      	ldr	x17, [x16, #0xd98]
   cf788:      	add	x16, x16, #0xd98
   cf78c:      	br	x17

00000000000cf790 <_ZN2ge6OpDesc7AddAttrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf790:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf794:      	ldr	x17, [x16, #0xda0]
   cf798:      	add	x16, x16, #0xda0
   cf79c:      	br	x17

00000000000cf7a0 <_ZN2ge6OpDesc15UpdateInputDescERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_10TensorDescE@plt>:
   cf7a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf7a4:      	ldr	x17, [x16, #0xda8]
   cf7a8:      	add	x16, x16, #0xda8
   cf7ac:      	br	x17

00000000000cf7b0 <_ZN2ge6OpDesc7SetNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf7b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf7b4:      	ldr	x17, [x16, #0xdb0]
   cf7b8:      	add	x16, x16, #0xdb0
   cf7bc:      	br	x17

00000000000cf7c0 <_ZN2ge6OpDesc7SetTypeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf7c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf7c4:      	ldr	x17, [x16, #0xdb8]
   cf7c8:      	add	x16, x16, #0xdb8
   cf7cc:      	br	x17

00000000000cf7d0 <_ZNK2ge6OpDesc12GetInputDescEj@plt>:
   cf7d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf7d4:      	ldr	x17, [x16, #0xdc0]
   cf7d8:      	add	x16, x16, #0xdc0
   cf7dc:      	br	x17

00000000000cf7e0 <_ZN4hiai12ProtoFactory14CreateShapeDefEv@plt>:
   cf7e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf7e4:      	ldr	x17, [x16, #0xdc8]
   cf7e8:      	add	x16, x16, #0xdc8
   cf7ec:      	br	x17

00000000000cf7f0 <_ZN4hiai12ProtoFactory15DestroyShapeDefEPNS_9IShapeDefE@plt>:
   cf7f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf7f4:      	ldr	x17, [x16, #0xdd0]
   cf7f8:      	add	x16, x16, #0xdd0
   cf7fc:      	br	x17

00000000000cf800 <_ZN2ge5Shape5RefToERKS0_@plt>:
   cf800:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf804:      	ldr	x17, [x16, #0xdd8]
   cf808:      	add	x16, x16, #0xdd8
   cf80c:      	br	x17

00000000000cf810 <_ZNK2ge5Shape9GetDimNumEv@plt>:
   cf810:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf814:      	ldr	x17, [x16, #0xde0]
   cf818:      	add	x16, x16, #0xde0
   cf81c:      	br	x17

00000000000cf820 <_ZNK2ge5Shape6GetDimEm@plt>:
   cf820:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf824:      	ldr	x17, [x16, #0xde8]
   cf828:      	add	x16, x16, #0xde8
   cf82c:      	br	x17

00000000000cf830 <_ZNK2ge5Shape7GetDimsEv@plt>:
   cf830:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf834:      	ldr	x17, [x16, #0xdf0]
   cf838:      	add	x16, x16, #0xdf0
   cf83c:      	br	x17

00000000000cf840 <_ZNK2ge5Shape14GetTotalDimNumEv@plt>:
   cf840:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf844:      	ldr	x17, [x16, #0xdf8]
   cf848:      	add	x16, x16, #0xdf8
   cf84c:      	br	x17

00000000000cf850 <_ZNK2ge5Shape12GetShapeSizeEv@plt>:
   cf850:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf854:      	ldr	x17, [x16, #0xe00]
   cf858:      	add	x16, x16, #0xe00
   cf85c:      	br	x17

00000000000cf860 <_ZN2ge5ShapeaSERKS0_@plt>:
   cf860:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf864:      	ldr	x17, [x16, #0xe08]
   cf868:      	add	x16, x16, #0xe08
   cf86c:      	br	x17

00000000000cf870 <_ZN2ge5ShapeC1EPN4hiai9IShapeDefEb@plt>:
   cf870:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf874:      	ldr	x17, [x16, #0xe10]
   cf878:      	add	x16, x16, #0xe10
   cf87c:      	br	x17

00000000000cf880 <_ZN2ge5ShapeC1ENSt6__ndk16vectorIlNS1_9allocatorIlEEEE@plt>:
   cf880:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf884:      	ldr	x17, [x16, #0xe18]
   cf888:      	add	x16, x16, #0xe18
   cf88c:      	br	x17

00000000000cf890 <_ZN2ge5ShapeC1ERKS0_@plt>:
   cf890:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf894:      	ldr	x17, [x16, #0xe20]
   cf898:      	add	x16, x16, #0xe20
   cf89c:      	br	x17

00000000000cf8a0 <_ZN2ge10TensorDescC2Ev@plt>:
   cf8a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf8a4:      	ldr	x17, [x16, #0xe28]
   cf8a8:      	add	x16, x16, #0xe28
   cf8ac:      	br	x17

00000000000cf8b0 <_ZN4hiai12ProtoFactory19CreateTensorDescDefEv@plt>:
   cf8b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf8b4:      	ldr	x17, [x16, #0xe30]
   cf8b8:      	add	x16, x16, #0xe30
   cf8bc:      	br	x17

00000000000cf8c0 <_ZN2ge10TensorDescC2EPN4hiai14ITensorDescDefEb@plt>:
   cf8c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf8c4:      	ldr	x17, [x16, #0xe38]
   cf8c8:      	add	x16, x16, #0xe38
   cf8cc:      	br	x17

00000000000cf8d0 <_ZN4hiai12ProtoFactory20DestroyTensorDescDefEPNS_14ITensorDescDefE@plt>:
   cf8d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf8d4:      	ldr	x17, [x16, #0xe40]
   cf8d8:      	add	x16, x16, #0xe40
   cf8dc:      	br	x17

00000000000cf8e0 <_ZNK2ge10TensorDesc14ShapeReferenceEv@plt>:
   cf8e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf8e4:      	ldr	x17, [x16, #0xe48]
   cf8e8:      	add	x16, x16, #0xe48
   cf8ec:      	br	x17

00000000000cf8f0 <_ZNSt6__ndk19to_stringEl@plt>:
   cf8f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf8f4:      	ldr	x17, [x16, #0xe50]
   cf8f8:      	add	x16, x16, #0xe50
   cf8fc:      	br	x17

00000000000cf900 <_ZN2ge9AttrUtils10SetListStrEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_6vectorIS9_NS7_IS9_EEEE@plt>:
   cf900:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf904:      	ldr	x17, [x16, #0xe58]
   cf908:      	add	x16, x16, #0xe58
   cf90c:      	br	x17

00000000000cf910 <_ZN2ge10TensorDescaSERKS0_@plt>:
   cf910:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf914:      	ldr	x17, [x16, #0xe60]
   cf918:      	add	x16, x16, #0xe60
   cf91c:      	br	x17

00000000000cf920 <_ZNK2ge10TensorDesc7GetNameEv@plt>:
   cf920:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf924:      	ldr	x17, [x16, #0xe68]
   cf928:      	add	x16, x16, #0xe68
   cf92c:      	br	x17

00000000000cf930 <_ZN2ge10TensorDesc7SetNameERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cf930:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf934:      	ldr	x17, [x16, #0xe70]
   cf938:      	add	x16, x16, #0xe70
   cf93c:      	br	x17

00000000000cf940 <_ZNK2ge10TensorDesc8GetShapeEv@plt>:
   cf940:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf944:      	ldr	x17, [x16, #0xe78]
   cf948:      	add	x16, x16, #0xe78
   cf94c:      	br	x17

00000000000cf950 <_ZN2ge10TensorDesc8SetShapeERKNS_5ShapeE@plt>:
   cf950:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf954:      	ldr	x17, [x16, #0xe80]
   cf958:      	add	x16, x16, #0xe80
   cf95c:      	br	x17

00000000000cf960 <_ZNK2ge10TensorDesc9GetFormatEv@plt>:
   cf960:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf964:      	ldr	x17, [x16, #0xe88]
   cf968:      	add	x16, x16, #0xe88
   cf96c:      	br	x17

00000000000cf970 <_ZN2ge10TensorDesc9SetFormatENS_6FormatE@plt>:
   cf970:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf974:      	ldr	x17, [x16, #0xe90]
   cf978:      	add	x16, x16, #0xe90
   cf97c:      	br	x17

00000000000cf980 <_ZNK2ge10TensorDesc11GetDataTypeEv@plt>:
   cf980:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf984:      	ldr	x17, [x16, #0xe98]
   cf988:      	add	x16, x16, #0xe98
   cf98c:      	br	x17

00000000000cf990 <_ZN2ge10TensorDesc11SetDataTypeENS_8DataTypeE@plt>:
   cf990:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf994:      	ldr	x17, [x16, #0xea0]
   cf998:      	add	x16, x16, #0xea0
   cf99c:      	br	x17

00000000000cf9a0 <_ZN2ge6TensorC2Ev@plt>:
   cf9a0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf9a4:      	ldr	x17, [x16, #0xea8]
   cf9a8:      	add	x16, x16, #0xea8
   cf9ac:      	br	x17

00000000000cf9b0 <_ZN4hiai12ProtoFactory15CreateTensorDefEv@plt>:
   cf9b0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf9b4:      	ldr	x17, [x16, #0xeb0]
   cf9b8:      	add	x16, x16, #0xeb0
   cf9bc:      	br	x17

00000000000cf9c0 <_ZN2ge6TensorC2EPN4hiai10ITensorDefEb@plt>:
   cf9c0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf9c4:      	ldr	x17, [x16, #0xeb8]
   cf9c8:      	add	x16, x16, #0xeb8
   cf9cc:      	br	x17

00000000000cf9d0 <_ZN4hiai12ProtoFactory16DestroyTensorDefEPNS_10ITensorDefE@plt>:
   cf9d0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf9d4:      	ldr	x17, [x16, #0xec0]
   cf9d8:      	add	x16, x16, #0xec0
   cf9dc:      	br	x17

00000000000cf9e0 <_ZN2ge6TensorD1Ev@plt>:
   cf9e0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf9e4:      	ldr	x17, [x16, #0xec8]
   cf9e8:      	add	x16, x16, #0xec8
   cf9ec:      	br	x17

00000000000cf9f0 <_ZNK2ge6Tensor13DescReferenceEv@plt>:
   cf9f0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cf9f4:      	ldr	x17, [x16, #0xed0]
   cf9f8:      	add	x16, x16, #0xed0
   cf9fc:      	br	x17

00000000000cfa00 <_ZNK2ge6Tensor15BufferReferenceEv@plt>:
   cfa00:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa04:      	ldr	x17, [x16, #0xed8]
   cfa08:      	add	x16, x16, #0xed8
   cfa0c:      	br	x17

00000000000cfa10 <_ZNK2ge6Tensor13GetTensorDescEv@plt>:
   cfa10:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa14:      	ldr	x17, [x16, #0xee0]
   cfa18:      	add	x16, x16, #0xee0
   cfa1c:      	br	x17

00000000000cfa20 <_ZN2ge6Tensor17MutableTensorDescEv@plt>:
   cfa20:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa24:      	ldr	x17, [x16, #0xee8]
   cfa28:      	add	x16, x16, #0xee8
   cfa2c:      	br	x17

00000000000cfa30 <_ZN2ge6Tensor13SetTensorDescERKNS_10TensorDescE@plt>:
   cfa30:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa34:      	ldr	x17, [x16, #0xef0]
   cfa38:      	add	x16, x16, #0xef0
   cfa3c:      	br	x17

00000000000cfa40 <_ZNK2ge6Tensor7GetDataEv@plt>:
   cfa40:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa44:      	ldr	x17, [x16, #0xef8]
   cfa48:      	add	x16, x16, #0xef8
   cfa4c:      	br	x17

00000000000cfa50 <_ZN2ge6Tensor7SetDataEPKhm@plt>:
   cfa50:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa54:      	ldr	x17, [x16, #0xf00]
   cfa58:      	add	x16, x16, #0xf00
   cfa5c:      	br	x17

00000000000cfa60 <_ZN2ge10TensorDescC1ENS_5ShapeENS_8DataTypeE@plt>:
   cfa60:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa64:      	ldr	x17, [x16, #0xf08]
   cfa68:      	add	x16, x16, #0xf08
   cfa6c:      	br	x17

00000000000cfa70 <_ZN2ge6TensorC1Ev@plt>:
   cfa70:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa74:      	ldr	x17, [x16, #0xf10]
   cfa78:      	add	x16, x16, #0xf10
   cfa7c:      	br	x17

00000000000cfa80 <_ZN2ge6TensorC1ERKNS_10TensorDescE@plt>:
   cfa80:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa84:      	ldr	x17, [x16, #0xf18]
   cfa88:      	add	x16, x16, #0xf18
   cfa8c:      	br	x17

00000000000cfa90 <_ZN2ge6TensorC1ERKNS_10TensorDescEPKhm@plt>:
   cfa90:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfa94:      	ldr	x17, [x16, #0xf20]
   cfa98:      	add	x16, x16, #0xf20
   cfa9c:      	br	x17

00000000000cfaa0 <_ZN2ge6TensorC1ERKNS_10TensorDescERKNS_6BufferE@plt>:
   cfaa0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfaa4:      	ldr	x17, [x16, #0xf28]
   cfaa8:      	add	x16, x16, #0xf28
   cfaac:      	br	x17

00000000000cfab0 <strcmp@plt>:
   cfab0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfab4:      	ldr	x17, [x16, #0xf30]
   cfab8:      	add	x16, x16, #0xf30
   cfabc:      	br	x17

00000000000cfac0 <memchr@plt>:
   cfac0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfac4:      	ldr	x17, [x16, #0xf38]
   cfac8:      	add	x16, x16, #0xf38
   cfacc:      	br	x17

00000000000cfad0 <_ZN4hiai15OperatorFactory8InstanceEv@plt>:
   cfad0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfad4:      	ldr	x17, [x16, #0xf40]
   cfad8:      	add	x16, x16, #0xf40
   cfadc:      	br	x17

00000000000cfae0 <_ZN4hiai15OperatorFactory14CreateOperatorERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   cfae0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfae4:      	ldr	x17, [x16, #0xf48]
   cfae8:      	add	x16, x16, #0xf48
   cfaec:      	br	x17

00000000000cfaf0 <_ZN2ge12ComputeGraph4MakeENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cfaf0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfaf4:      	ldr	x17, [x16, #0xf50]
   cfaf8:      	add	x16, x16, #0xf50
   cfafc:      	br	x17

00000000000cfb00 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc@plt>:
   cfb00:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb04:      	ldr	x17, [x16, #0xf58]
   cfb08:      	add	x16, x16, #0xf58
   cfb0c:      	br	x17

00000000000cfb10 <_ZN2ge11LegacyGraphD2Ev@plt>:
   cfb10:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb14:      	ldr	x17, [x16, #0xf60]
   cfb18:      	add	x16, x16, #0xf60
   cfb1c:      	br	x17

00000000000cfb20 <_ZN2ge11NodeChecker16IsGraphInputTypeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   cfb20:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb24:      	ldr	x17, [x16, #0xf68]
   cfb28:      	add	x16, x16, #0xf68
   cfb2c:      	br	x17

00000000000cfb30 <_ZN2ge8EndpointC1ERNS_4NodeEi@plt>:
   cfb30:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb34:      	ldr	x17, [x16, #0xf70]
   cfb38:      	add	x16, x16, #0xf70
   cfb3c:      	br	x17

00000000000cfb40 <_ZN2ge13GraphModifier7AddEdgeERKNS_8EndpointES3_@plt>:
   cfb40:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb44:      	ldr	x17, [x16, #0xf78]
   cfb48:      	add	x16, x16, #0xf78
   cfb4c:      	br	x17

00000000000cfb50 <_ZN2ge13GraphModifier13SetInputOrderENSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEjNS1_4lessIS8_EENS6_INS1_4pairIKS8_jEEEEEE@plt>:
   cfb50:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb54:      	ldr	x17, [x16, #0xf80]
   cfb58:      	add	x16, x16, #0xf80
   cfb5c:      	br	x17

00000000000cfb60 <_ZNK2ge9GraphSpec7IsValidEv@plt>:
   cfb60:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb64:      	ldr	x17, [x16, #0xf88]
   cfb68:      	add	x16, x16, #0xf88
   cfb6c:      	br	x17

00000000000cfb70 <_ZN2ge13GraphModifier7AddNodeERKNSt6__ndk110shared_ptrINS_6OpDescEEE@plt>:
   cfb70:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb74:      	ldr	x17, [x16, #0xf90]
   cfb78:      	add	x16, x16, #0xf90
   cfb7c:      	br	x17

00000000000cfb80 <_ZNK2ge8NodeSpec4TypeEv@plt>:
   cfb80:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb84:      	ldr	x17, [x16, #0xf98]
   cfb88:      	add	x16, x16, #0xf98
   cfb8c:      	br	x17

00000000000cfb90 <_ZN2ge8NodeSpec6OpDescEv@plt>:
   cfb90:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfb94:      	ldr	x17, [x16, #0xfa0]
   cfb98:      	add	x16, x16, #0xfa0
   cfb9c:      	br	x17

00000000000cfba0 <_ZN2ge12NodeSubGraph11AddSubGraphERNSt6__ndk110shared_ptrINS_12ComputeGraphEEE@plt>:
   cfba0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfba4:      	ldr	x17, [x16, #0xfa8]
   cfba8:      	add	x16, x16, #0xfa8
   cfbac:      	br	x17

00000000000cfbb0 <_ZNSt6__ndk112__next_primeEm@plt>:
   cfbb0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfbb4:      	ldr	x17, [x16, #0xfb0]
   cfbb8:      	add	x16, x16, #0xfb0
   cfbbc:      	br	x17

00000000000cfbc0 <_ZN2ge13GraphBypasser8PreCheckERKNS_4NodeE@plt>:
   cfbc0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfbc4:      	ldr	x17, [x16, #0xfb8]
   cfbc8:      	add	x16, x16, #0xfb8
   cfbcc:      	br	x17

00000000000cfbd0 <_ZNK2ge8NodeSpec14InDataEdgeSizeEv@plt>:
   cfbd0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfbd4:      	ldr	x17, [x16, #0xfc0]
   cfbd8:      	add	x16, x16, #0xfc0
   cfbdc:      	br	x17

00000000000cfbe0 <_ZNK2ge8NodeSpec15OutDataEdgeSizeEv@plt>:
   cfbe0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfbe4:      	ldr	x17, [x16, #0xfc8]
   cfbe8:      	add	x16, x16, #0xfc8
   cfbec:      	br	x17

00000000000cfbf0 <_ZNK2ge8NodeSpec15OutCtrlEdgeSizeEv@plt>:
   cfbf0:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfbf4:      	ldr	x17, [x16, #0xfd0]
   cfbf8:      	add	x16, x16, #0xfd0
   cfbfc:      	br	x17

00000000000cfc00 <_ZNK2ge8NodeSpec14InCtrlEdgeSizeEv@plt>:
   cfc00:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfc04:      	ldr	x17, [x16, #0xfd8]
   cfc08:      	add	x16, x16, #0xfd8
   cfc0c:      	br	x17

00000000000cfc10 <_ZN2ge13GraphBypasser10ByPassNodeERKNS_4NodeE@plt>:
   cfc10:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfc14:      	ldr	x17, [x16, #0xfe0]
   cfc18:      	add	x16, x16, #0xfe0
   cfc1c:      	br	x17

00000000000cfc20 <_ZN2ge10NodeWalker11ListInEdgesENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   cfc20:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfc24:      	ldr	x17, [x16, #0xfe8]
   cfc28:      	add	x16, x16, #0xfe8
   cfc2c:      	br	x17

00000000000cfc30 <_ZN2ge10NodeWalker12ListOutEdgesENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   cfc30:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfc34:      	ldr	x17, [x16, #0xff0]
   cfc38:      	add	x16, x16, #0xff0
   cfc3c:      	br	x17

00000000000cfc40 <_ZN2ge13GraphModifier10RemoveNodeERKNS_4NodeE@plt>:
   cfc40:      	adrp	x16, 0xda000 <_ZTVN4hiai10ProtoOpDefE+0x2128>
   cfc44:      	ldr	x17, [x16, #0xff8]
   cfc48:      	add	x16, x16, #0xff8
   cfc4c:      	br	x17

00000000000cfc50 <_ZNK2ge8Endpoint6IsDataEv@plt>:
   cfc50:      	adrp	x16, 0xdb000
   cfc54:      	ldr	x17, [x16]
   cfc58:      	add	x16, x16, #0x0
   cfc5c:      	br	x17

00000000000cfc60 <_ZNK2ge8Endpoint6IsCtrlEv@plt>:
   cfc60:      	adrp	x16, 0xdb000
   cfc64:      	ldr	x17, [x16, #0x8]
   cfc68:      	add	x16, x16, #0x8
   cfc6c:      	br	x17

00000000000cfc70 <_ZNK2ge8Endpoint4NodeEv@plt>:
   cfc70:      	adrp	x16, 0xdb000
   cfc74:      	ldr	x17, [x16, #0x10]
   cfc78:      	add	x16, x16, #0x10
   cfc7c:      	br	x17

00000000000cfc80 <_ZN2ge4EdgeC1ERKNS_8EndpointES3_@plt>:
   cfc80:      	adrp	x16, 0xdb000
   cfc84:      	ldr	x17, [x16, #0x18]
   cfc88:      	add	x16, x16, #0x18
   cfc8c:      	br	x17

00000000000cfc90 <_ZNK2ge4Edge7SrcNodeEv@plt>:
   cfc90:      	adrp	x16, 0xdb000
   cfc94:      	ldr	x17, [x16, #0x20]
   cfc98:      	add	x16, x16, #0x20
   cfc9c:      	br	x17

00000000000cfca0 <_ZNK2ge4Edge6SrcIdxEv@plt>:
   cfca0:      	adrp	x16, 0xdb000
   cfca4:      	ldr	x17, [x16, #0x28]
   cfca8:      	add	x16, x16, #0x28
   cfcac:      	br	x17

00000000000cfcb0 <_ZNK2ge4Edge7DstNodeEv@plt>:
   cfcb0:      	adrp	x16, 0xdb000
   cfcb4:      	ldr	x17, [x16, #0x30]
   cfcb8:      	add	x16, x16, #0x30
   cfcbc:      	br	x17

00000000000cfcc0 <_ZNK2ge4Edge6DstIdxEv@plt>:
   cfcc0:      	adrp	x16, 0xdb000
   cfcc4:      	ldr	x17, [x16, #0x38]
   cfcc8:      	add	x16, x16, #0x38
   cfccc:      	br	x17

00000000000cfcd0 <_ZNK2ge11GraphFinder8FindNodeERKNSt6__ndk18functionIFbRNS_4NodeEEEE@plt>:
   cfcd0:      	adrp	x16, 0xdb000
   cfcd4:      	ldr	x17, [x16, #0x40]
   cfcd8:      	add	x16, x16, #0x40
   cfcdc:      	br	x17

00000000000cfce0 <_ZNK2ge11GraphFinder11FindNodePtrERKNS_4NodeE@plt>:
   cfce0:      	adrp	x16, 0xdb000
   cfce4:      	ldr	x17, [x16, #0x48]
   cfce8:      	add	x16, x16, #0x48
   cfcec:      	br	x17

00000000000cfcf0 <_ZNK2ge8NodeSpec4NameEv@plt>:
   cfcf0:      	adrp	x16, 0xdb000
   cfcf4:      	ldr	x17, [x16, #0x50]
   cfcf8:      	add	x16, x16, #0x50
   cfcfc:      	br	x17

00000000000cfd00 <_ZNK2ge8NodeSpec2IdEv@plt>:
   cfd00:      	adrp	x16, 0xdb000
   cfd04:      	ldr	x17, [x16, #0x58]
   cfd08:      	add	x16, x16, #0x58
   cfd0c:      	br	x17

00000000000cfd10 <_ZN2ge15GraphListWalker12WalkAllNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   cfd10:      	adrp	x16, 0xdb000
   cfd14:      	ldr	x17, [x16, #0x60]
   cfd18:      	add	x16, x16, #0x60
   cfd1c:      	br	x17

00000000000cfd20 <_ZN2ge15GraphListWalker22WalkAllNodesModifiableERKNSt6__ndk18functionIFbRNS_4NodeEEEENS2_IFjS4_EEE@plt>:
   cfd20:      	adrp	x16, 0xdb000
   cfd24:      	ldr	x17, [x16, #0x68]
   cfd28:      	add	x16, x16, #0x68
   cfd2c:      	br	x17

00000000000cfd30 <_ZN2ge15GraphListWalker11WalkInNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   cfd30:      	adrp	x16, 0xdb000
   cfd34:      	ldr	x17, [x16, #0x70]
   cfd38:      	add	x16, x16, #0x70
   cfd3c:      	br	x17

00000000000cfd40 <_ZN2ge11GraphSorter10StableSortERNSt6__ndk16vectorIPNS_4NodeENS1_9allocatorIS4_EEEERKNS1_3mapINS1_12basic_stringIcNS1_11char_traitsIcEENS5_IcEEEEjNS1_4lessISE_EENS5_INS1_4pairIKSE_jEEEEEERKNS1_8functionIFbjjEEE@plt>:
   cfd40:      	adrp	x16, 0xdb000
   cfd44:      	ldr	x17, [x16, #0x78]
   cfd48:      	add	x16, x16, #0x78
   cfd4c:      	br	x17

00000000000cfd50 <_ZN2ge15GraphListWalker12WalkOutNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   cfd50:      	adrp	x16, 0xdb000
   cfd54:      	ldr	x17, [x16, #0x80]
   cfd58:      	add	x16, x16, #0x80
   cfd5c:      	br	x17

00000000000cfd60 <_ZN2ge11NodeFunctor5TypedENSt6__ndk16vectorINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEENS6_IS8_EEEENS1_8functionIFjRNS_4NodeEEEE@plt>:
   cfd60:      	adrp	x16, 0xdb000
   cfd64:      	ldr	x17, [x16, #0x88]
   cfd68:      	add	x16, x16, #0x88
   cfd6c:      	br	x17

00000000000cfd70 <_ZN2ge17AutoGraphListenerC1ERNS_13GraphNotifierERNS_13GraphListenerE@plt>:
   cfd70:      	adrp	x16, 0xdb000
   cfd74:      	ldr	x17, [x16, #0x90]
   cfd78:      	add	x16, x16, #0x90
   cfd7c:      	br	x17

00000000000cfd80 <_ZN2ge17AutoGraphListenerD1Ev@plt>:
   cfd80:      	adrp	x16, 0xdb000
   cfd84:      	ldr	x17, [x16, #0x98]
   cfd88:      	add	x16, x16, #0x98
   cfd8c:      	br	x17

00000000000cfd90 <_ZN2ge13GraphModifier7AddNodeENSt6__ndk110shared_ptrINS_4NodeEEE@plt>:
   cfd90:      	adrp	x16, 0xdb000
   cfd94:      	ldr	x17, [x16, #0xa0]
   cfd98:      	add	x16, x16, #0xa0
   cfd9c:      	br	x17

00000000000cfda0 <_ZN2ge6OpDesc5SetIdEl@plt>:
   cfda0:      	adrp	x16, 0xdb000
   cfda4:      	ldr	x17, [x16, #0xa8]
   cfda8:      	add	x16, x16, #0xa8
   cfdac:      	br	x17

00000000000cfdb0 <_ZN2ge8NodeSpec20SetOwnerComputeGraphERKNSt6__ndk110shared_ptrINS_12ComputeGraphEEE@plt>:
   cfdb0:      	adrp	x16, 0xdb000
   cfdb4:      	ldr	x17, [x16, #0xb0]
   cfdb8:      	add	x16, x16, #0xb0
   cfdbc:      	br	x17

00000000000cfdc0 <_ZN2ge13GraphModifier12AddNodeFrontERKNSt6__ndk110shared_ptrINS_6OpDescEEE@plt>:
   cfdc0:      	adrp	x16, 0xdb000
   cfdc4:      	ldr	x17, [x16, #0xb8]
   cfdc8:      	add	x16, x16, #0xb8
   cfdcc:      	br	x17

00000000000cfdd0 <_ZN2ge10NodeWalker15ListInDataEdgesENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   cfdd0:      	adrp	x16, 0xdb000
   cfdd4:      	ldr	x17, [x16, #0xc0]
   cfdd8:      	add	x16, x16, #0xc0
   cfddc:      	br	x17

00000000000cfde0 <_ZN2ge13GraphModifier10RemoveEdgeERKNS_4EdgeE@plt>:
   cfde0:      	adrp	x16, 0xdb000
   cfde4:      	ldr	x17, [x16, #0xc8]
   cfde8:      	add	x16, x16, #0xc8
   cfdec:      	br	x17

00000000000cfdf0 <_ZNK2ge8NodeSpec11OutEdgeSizeEv@plt>:
   cfdf0:      	adrp	x16, 0xdb000
   cfdf4:      	ldr	x17, [x16, #0xd0]
   cfdf8:      	add	x16, x16, #0xd0
   cfdfc:      	br	x17

00000000000cfe00 <_ZN2ge13GraphModifier11RemoveNodesERKNSt6__ndk16vectorIPNS_4NodeENS1_9allocatorIS4_EEEE@plt>:
   cfe00:      	adrp	x16, 0xdb000
   cfe04:      	ldr	x17, [x16, #0xd8]
   cfe08:      	add	x16, x16, #0xd8
   cfe0c:      	br	x17

00000000000cfe10 <_ZN2ge13GraphModifier8AddInputERNS_4NodeE@plt>:
   cfe10:      	adrp	x16, 0xdb000
   cfe14:      	ldr	x17, [x16, #0xe0]
   cfe18:      	add	x16, x16, #0xe0
   cfe1c:      	br	x17

00000000000cfe20 <_ZN2ge13GraphModifier9AddOutputERNS_4NodeE@plt>:
   cfe20:      	adrp	x16, 0xdb000
   cfe24:      	ldr	x17, [x16, #0xe8]
   cfe28:      	add	x16, x16, #0xe8
   cfe2c:      	br	x17

00000000000cfe30 <_ZNK2ge8Endpoint3IdxEv@plt>:
   cfe30:      	adrp	x16, 0xdb000
   cfe34:      	ldr	x17, [x16, #0xf0]
   cfe38:      	add	x16, x16, #0xf0
   cfe3c:      	br	x17

00000000000cfe40 <_ZN2ge13GraphModifier12InsertBeforeERNS_4NodeEmS2_@plt>:
   cfe40:      	adrp	x16, 0xdb000
   cfe44:      	ldr	x17, [x16, #0xf8]
   cfe48:      	add	x16, x16, #0xf8
   cfe4c:      	br	x17

00000000000cfe50 <_ZN2ge10NodeWalker10InDataEdgeEm@plt>:
   cfe50:      	adrp	x16, 0xdb000
   cfe54:      	ldr	x17, [x16, #0x100]
   cfe58:      	add	x16, x16, #0x100
   cfe5c:      	br	x17

00000000000cfe60 <_ZN2ge13GraphModifier10RemoveEdgeERKNS_8EndpointES3_@plt>:
   cfe60:      	adrp	x16, 0xdb000
   cfe64:      	ldr	x17, [x16, #0x108]
   cfe68:      	add	x16, x16, #0x108
   cfe6c:      	br	x17

00000000000cfe70 <_ZNK2ge8NodeSpec18IdleInputEndpointsEv@plt>:
   cfe70:      	adrp	x16, 0xdb000
   cfe74:      	ldr	x17, [x16, #0x110]
   cfe78:      	add	x16, x16, #0x110
   cfe7c:      	br	x17

00000000000cfe80 <_ZN2ge13GraphModifier11InsertAfterERNS_4NodeEmS2_@plt>:
   cfe80:      	adrp	x16, 0xdb000
   cfe84:      	ldr	x17, [x16, #0x118]
   cfe88:      	add	x16, x16, #0x118
   cfe8c:      	br	x17

00000000000cfe90 <_ZN2ge10NodeWalker16ListOutDataEdgesEmNSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   cfe90:      	adrp	x16, 0xdb000
   cfe94:      	ldr	x17, [x16, #0x120]
   cfe98:      	add	x16, x16, #0x120
   cfe9c:      	br	x17

00000000000cfea0 <_ZNK2ge8NodeSpec9IsConstOpEv@plt>:
   cfea0:      	adrp	x16, 0xdb000
   cfea4:      	ldr	x17, [x16, #0x128]
   cfea8:      	add	x16, x16, #0x128
   cfeac:      	br	x17

00000000000cfeb0 <_ZN2ge10NodeWalker15ListInDataNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   cfeb0:      	adrp	x16, 0xdb000
   cfeb4:      	ldr	x17, [x16, #0x130]
   cfeb8:      	add	x16, x16, #0x130
   cfebc:      	br	x17

00000000000cfec0 <_ZN2ge10NodeWalker15ListInCtrlNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   cfec0:      	adrp	x16, 0xdb000
   cfec4:      	ldr	x17, [x16, #0x138]
   cfec8:      	add	x16, x16, #0x138
   cfecc:      	br	x17

00000000000cfed0 <_ZN2ge15GraphSerializer14CreateAllNodesERNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_4NodeENS1_4lessIS8_EENS6_INS1_4pairIKS8_SA_EEEEEERNS1_6vectorINS_15NodeNameNodeReqENS6_ISK_EEEE@plt>:
   cfed0:      	adrp	x16, 0xdb000
   cfed4:      	ldr	x17, [x16, #0x140]
   cfed8:      	add	x16, x16, #0x140
   cfedc:      	br	x17

00000000000cfee0 <_ZN2ge15GraphSerializer16CreateInputNodesERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_4NodeENS1_4lessIS8_EENS6_INS1_4pairIKS8_SA_EEEEEE@plt>:
   cfee0:      	adrp	x16, 0xdb000
   cfee4:      	ldr	x17, [x16, #0x148]
   cfee8:      	add	x16, x16, #0x148
   cfeec:      	br	x17

00000000000cfef0 <_ZN2ge15GraphSerializer17CreateOutputNodesERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_4NodeENS1_4lessIS8_EENS6_INS1_4pairIKS8_SA_EEEEEE@plt>:
   cfef0:      	adrp	x16, 0xdb000
   cfef4:      	ldr	x17, [x16, #0x150]
   cfef8:      	add	x16, x16, #0x150
   cfefc:      	br	x17

00000000000cff00 <_ZN2ge15GraphSerializer17HandleNodeNameRefERKNSt6__ndk13mapINS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEPNS_4NodeENS1_4lessIS8_EENS6_INS1_4pairIKS8_SA_EEEEEERKNS1_6vectorINS_15NodeNameNodeReqENS6_ISL_EEEE@plt>:
   cff00:      	adrp	x16, 0xdb000
   cff04:      	ldr	x17, [x16, #0x158]
   cff08:      	add	x16, x16, #0x158
   cff0c:      	br	x17

00000000000cff10 <_ZN2ge6OpDesc11UnSerializeEv@plt>:
   cff10:      	adrp	x16, 0xdb000
   cff14:      	ldr	x17, [x16, #0x160]
   cff18:      	add	x16, x16, #0x160
   cff1c:      	br	x17

00000000000cff20 <_ZN2ge14NodeSerializer20UnSerializeSubGraphsEv@plt>:
   cff20:      	adrp	x16, 0xdb000
   cff24:      	ldr	x17, [x16, #0x168]
   cff28:      	add	x16, x16, #0x168
   cff2c:      	br	x17

00000000000cff30 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2ERKS5_mmRKS4_@plt>:
   cff30:      	adrp	x16, 0xdb000
   cff34:      	ldr	x17, [x16, #0x170]
   cff38:      	add	x16, x16, #0x170
   cff3c:      	br	x17

00000000000cff40 <strtol@plt>:
   cff40:      	adrp	x16, 0xdb000
   cff44:      	ldr	x17, [x16, #0x178]
   cff48:      	add	x16, x16, #0x178
   cff4c:      	br	x17

00000000000cff50 <_ZN2ge13OutDataAnchor6LinkToENSt6__ndk110shared_ptrINS_12InDataAnchorEEE@plt>:
   cff50:      	adrp	x16, 0xdb000
   cff54:      	ldr	x17, [x16, #0x180]
   cff58:      	add	x16, x16, #0x180
   cff5c:      	br	x17

00000000000cff60 <_ZN2ge16OutControlAnchor6LinkToENSt6__ndk110shared_ptrINS_15InControlAnchorEEE@plt>:
   cff60:      	adrp	x16, 0xdb000
   cff64:      	ldr	x17, [x16, #0x188]
   cff68:      	add	x16, x16, #0x188
   cff6c:      	br	x17

00000000000cff70 <_ZN2ge14NodeSerializer11SerializeToEPN4hiai6IOpDefE@plt>:
   cff70:      	adrp	x16, 0xdb000
   cff74:      	ldr	x17, [x16, #0x190]
   cff78:      	add	x16, x16, #0x190
   cff7c:      	br	x17

00000000000cff80 <_ZN2ge11GraphSorter12SortNodesDFSEv@plt>:
   cff80:      	adrp	x16, 0xdb000
   cff84:      	ldr	x17, [x16, #0x198]
   cff88:      	add	x16, x16, #0x198
   cff8c:      	br	x17

00000000000cff90 <_ZN2ge11GraphSorter10StableSortERNSt6__ndk14listIPNS_4NodeENS1_9allocatorIS4_EEEERKNS1_3mapINS1_12basic_stringIcNS1_11char_traitsIcEENS5_IcEEEEjNS1_4lessISE_EENS5_INS1_4pairIKSE_jEEEEEERKNS1_8functionIFbjjEEE@plt>:
   cff90:      	adrp	x16, 0xdb000
   cff94:      	ldr	x17, [x16, #0x1a0]
   cff98:      	add	x16, x16, #0x1a0
   cff9c:      	br	x17

00000000000cffa0 <_ZN2ge12NodeSubGraph13WalkSubGraphsENSt6__ndk18functionIFjRNS1_10shared_ptrINS_12ComputeGraphEEEEEE@plt>:
   cffa0:      	adrp	x16, 0xdb000
   cffa4:      	ldr	x17, [x16, #0x1a8]
   cffa8:      	add	x16, x16, #0x1a8
   cffac:      	br	x17

00000000000cffb0 <_ZNK2ge8NodeSpec10InEdgeSizeEv@plt>:
   cffb0:      	adrp	x16, 0xdb000
   cffb4:      	ldr	x17, [x16, #0x1b0]
   cffb8:      	add	x16, x16, #0x1b0
   cffbc:      	br	x17

00000000000cffc0 <_ZNK2ge9GraphSpec8NodesNumEv@plt>:
   cffc0:      	adrp	x16, 0xdb000
   cffc4:      	ldr	x17, [x16, #0x1b8]
   cffc8:      	add	x16, x16, #0x1b8
   cffcc:      	br	x17

00000000000cffd0 <_ZNK2ge9GraphSpec10InNodesNumEv@plt>:
   cffd0:      	adrp	x16, 0xdb000
   cffd4:      	ldr	x17, [x16, #0x1c0]
   cffd8:      	add	x16, x16, #0x1c0
   cffdc:      	br	x17

00000000000cffe0 <_ZN2ge12GraphChecker19IsInputsFullyLinkedERKNS_12ComputeGraphEb@plt>:
   cffe0:      	adrp	x16, 0xdb000
   cffe4:      	ldr	x17, [x16, #0x1c8]
   cffe8:      	add	x16, x16, #0x1c8
   cffec:      	br	x17

00000000000cfff0 <_ZNK2ge9GraphSpec9OwnerNodeEv@plt>:
   cfff0:      	adrp	x16, 0xdb000
   cfff4:      	ldr	x17, [x16, #0x1d0]
   cfff8:      	add	x16, x16, #0x1d0
   cfffc:      	br	x17

00000000000d0000 <_ZN2ge9GraphSpec12SetOwnerNodeEPNS_4NodeE@plt>:
   d0000:      	adrp	x16, 0xdb000
   d0004:      	ldr	x17, [x16, #0x1d8]
   d0008:      	add	x16, x16, #0x1d8
   d000c:      	br	x17

00000000000d0010 <_ZNK2ge8NodeSpec7IsValidEv@plt>:
   d0010:      	adrp	x16, 0xdb000
   d0014:      	ldr	x17, [x16, #0x1e0]
   d0018:      	add	x16, x16, #0x1e0
   d001c:      	br	x17

00000000000d0020 <_ZN2ge10NodeWalker12ListOutNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   d0020:      	adrp	x16, 0xdb000
   d0024:      	ldr	x17, [x16, #0x1e8]
   d0028:      	add	x16, x16, #0x1e8
   d002c:      	br	x17

00000000000d0030 <_ZNSt6__ndk15mutex4lockEv@plt>:
   d0030:      	adrp	x16, 0xdb000
   d0034:      	ldr	x17, [x16, #0x1f0]
   d0038:      	add	x16, x16, #0x1f0
   d003c:      	br	x17

00000000000d0040 <_ZNSt6__ndk15mutex6unlockEv@plt>:
   d0040:      	adrp	x16, 0xdb000
   d0044:      	ldr	x17, [x16, #0x1f8]
   d0048:      	add	x16, x16, #0x1f8
   d004c:      	br	x17

00000000000d0050 <_ZNK2ge4Edge6IsDataEv@plt>:
   d0050:      	adrp	x16, 0xdb000
   d0054:      	ldr	x17, [x16, #0x200]
   d0058:      	add	x16, x16, #0x200
   d005c:      	br	x17

00000000000d0060 <_ZNK2ge4Edge6IsCtrlEv@plt>:
   d0060:      	adrp	x16, 0xdb000
   d0064:      	ldr	x17, [x16, #0x208]
   d0068:      	add	x16, x16, #0x208
   d006c:      	br	x17

00000000000d0070 <_ZN2ge10NodeWalker16ListOutCtrlNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   d0070:      	adrp	x16, 0xdb000
   d0074:      	ldr	x17, [x16, #0x210]
   d0078:      	add	x16, x16, #0x210
   d007c:      	br	x17

00000000000d0080 <_ZNSt6__ndk15mutexD1Ev@plt>:
   d0080:      	adrp	x16, 0xdb000
   d0084:      	ldr	x17, [x16, #0x218]
   d0088:      	add	x16, x16, #0x218
   d008c:      	br	x17

00000000000d0090 <_ZNK2ge11LegacyGraph14GetDirectNodesEv@plt>:
   d0090:      	adrp	x16, 0xdb000
   d0094:      	ldr	x17, [x16, #0x220]
   d0098:      	add	x16, x16, #0x220
   d009c:      	br	x17

00000000000d00a0 <_ZN2ge11LegacyGraph10RemoveNodeERNS_4NodeE@plt>:
   d00a0:      	adrp	x16, 0xdb000
   d00a4:      	ldr	x17, [x16, #0x228]
   d00a8:      	add	x16, x16, #0x228
   d00ac:      	br	x17

00000000000d00b0 <_ZNK2ge11LegacyGraph18GetDirectSubGraphsEv@plt>:
   d00b0:      	adrp	x16, 0xdb000
   d00b4:      	ldr	x17, [x16, #0x230]
   d00b8:      	add	x16, x16, #0x230
   d00bc:      	br	x17

00000000000d00c0 <_ZNK2ge6Anchor8IsTypeOfENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   d00c0:      	adrp	x16, 0xdb000
   d00c4:      	ldr	x17, [x16, #0x238]
   d00c8:      	add	x16, x16, #0x238
   d00cc:      	br	x17

00000000000d00d0 <_ZNK2ge6Anchor14GetPeerAnchorsEv@plt>:
   d00d0:      	adrp	x16, 0xdb000
   d00d4:      	ldr	x17, [x16, #0x240]
   d00d8:      	add	x16, x16, #0x240
   d00dc:      	br	x17

00000000000d00e0 <_ZNK2ge6Anchor12GetOwnerNodeEv@plt>:
   d00e0:      	adrp	x16, 0xdb000
   d00e4:      	ldr	x17, [x16, #0x248]
   d00e8:      	add	x16, x16, #0x248
   d00ec:      	br	x17

00000000000d00f0 <_ZN2ge6Anchor9UnlinkAllEv@plt>:
   d00f0:      	adrp	x16, 0xdb000
   d00f4:      	ldr	x17, [x16, #0x250]
   d00f8:      	add	x16, x16, #0x250
   d00fc:      	br	x17

00000000000d0100 <_ZN2ge6Anchor6UnlinkENSt6__ndk110shared_ptrIS0_EE@plt>:
   d0100:      	adrp	x16, 0xdb000
   d0104:      	ldr	x17, [x16, #0x258]
   d0108:      	add	x16, x16, #0x258
   d010c:      	br	x17

00000000000d0110 <_ZN2ge6Anchor11ReplacePeerENSt6__ndk110shared_ptrIS0_EES3_S3_@plt>:
   d0110:      	adrp	x16, 0xdb000
   d0114:      	ldr	x17, [x16, #0x260]
   d0118:      	add	x16, x16, #0x260
   d011c:      	br	x17

00000000000d0120 <_ZNK2ge6Anchor6GetIdxEv@plt>:
   d0120:      	adrp	x16, 0xdb000
   d0124:      	ldr	x17, [x16, #0x268]
   d0128:      	add	x16, x16, #0x268
   d012c:      	br	x17

00000000000d0130 <_ZN2ge10DataAnchorC2ENSt6__ndk110shared_ptrINS_4NodeEEEi@plt>:
   d0130:      	adrp	x16, 0xdb000
   d0134:      	ldr	x17, [x16, #0x270]
   d0138:      	add	x16, x16, #0x270
   d013c:      	br	x17

00000000000d0140 <_ZNK2ge10DataAnchor8IsTypeOfENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   d0140:      	adrp	x16, 0xdb000
   d0144:      	ldr	x17, [x16, #0x278]
   d0148:      	add	x16, x16, #0x278
   d014c:      	br	x17

00000000000d0150 <_ZNK2ge12InDataAnchor16GetPeerOutAnchorEv@plt>:
   d0150:      	adrp	x16, 0xdb000
   d0154:      	ldr	x17, [x16, #0x280]
   d0158:      	add	x16, x16, #0x280
   d015c:      	br	x17

00000000000d0160 <_ZN2ge6Anchor8IsTypeOfINS_13OutDataAnchorEEEbv@plt>:
   d0160:      	adrp	x16, 0xdb000
   d0164:      	ldr	x17, [x16, #0x288]
   d0168:      	add	x16, x16, #0x288
   d016c:      	br	x17

00000000000d0170 <_ZN2ge6Anchor8IsTypeOfINS_12InDataAnchorEEEbv@plt>:
   d0170:      	adrp	x16, 0xdb000
   d0174:      	ldr	x17, [x16, #0x290]
   d0178:      	add	x16, x16, #0x290
   d017c:      	br	x17

00000000000d0180 <_ZNK2ge13OutDataAnchor20GetPeerInDataAnchorsEv@plt>:
   d0180:      	adrp	x16, 0xdb000
   d0184:      	ldr	x17, [x16, #0x298]
   d0188:      	add	x16, x16, #0x298
   d018c:      	br	x17

00000000000d0190 <_ZN2ge13ControlAnchorC2ENSt6__ndk110shared_ptrINS_4NodeEEE@plt>:
   d0190:      	adrp	x16, 0xdb000
   d0194:      	ldr	x17, [x16, #0x2a0]
   d0198:      	add	x16, x16, #0x2a0
   d019c:      	br	x17

00000000000d01a0 <_ZNK2ge13ControlAnchor8IsTypeOfENSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   d01a0:      	adrp	x16, 0xdb000
   d01a4:      	ldr	x17, [x16, #0x2a8]
   d01a8:      	add	x16, x16, #0x2a8
   d01ac:      	br	x17

00000000000d01b0 <_ZNK2ge15InControlAnchor24GetPeerOutControlAnchorsEv@plt>:
   d01b0:      	adrp	x16, 0xdb000
   d01b4:      	ldr	x17, [x16, #0x2b0]
   d01b8:      	add	x16, x16, #0x2b0
   d01bc:      	br	x17

00000000000d01c0 <_ZN2ge6Anchor8IsTypeOfINS_16OutControlAnchorEEEbv@plt>:
   d01c0:      	adrp	x16, 0xdb000
   d01c4:      	ldr	x17, [x16, #0x2b8]
   d01c8:      	add	x16, x16, #0x2b8
   d01cc:      	br	x17

00000000000d01d0 <_ZN2ge6Anchor8IsTypeOfINS_15InControlAnchorEEEbv@plt>:
   d01d0:      	adrp	x16, 0xdb000
   d01d4:      	ldr	x17, [x16, #0x2c0]
   d01d8:      	add	x16, x16, #0x2c0
   d01dc:      	br	x17

00000000000d01e0 <_ZNK2ge16OutControlAnchor23GetPeerInControlAnchorsEv@plt>:
   d01e0:      	adrp	x16, 0xdb000
   d01e4:      	ldr	x17, [x16, #0x2c8]
   d01e8:      	add	x16, x16, #0x2c8
   d01ec:      	br	x17

00000000000d01f0 <_ZN2ge6AnchorD2Ev@plt>:
   d01f0:      	adrp	x16, 0xdb000
   d01f4:      	ldr	x17, [x16, #0x2d0]
   d01f8:      	add	x16, x16, #0x2d0
   d01fc:      	br	x17

00000000000d0200 <_ZN2ge12InDataAnchorC1ENSt6__ndk110shared_ptrINS_4NodeEEEi@plt>:
   d0200:      	adrp	x16, 0xdb000
   d0204:      	ldr	x17, [x16, #0x2d8]
   d0208:      	add	x16, x16, #0x2d8
   d020c:      	br	x17

00000000000d0210 <_ZN2ge13OutDataAnchorC1ENSt6__ndk110shared_ptrINS_4NodeEEEi@plt>:
   d0210:      	adrp	x16, 0xdb000
   d0214:      	ldr	x17, [x16, #0x2e0]
   d0218:      	add	x16, x16, #0x2e0
   d021c:      	br	x17

00000000000d0220 <_ZN2ge15InControlAnchorC1ENSt6__ndk110shared_ptrINS_4NodeEEE@plt>:
   d0220:      	adrp	x16, 0xdb000
   d0224:      	ldr	x17, [x16, #0x2e8]
   d0228:      	add	x16, x16, #0x2e8
   d022c:      	br	x17

00000000000d0230 <_ZN2ge16OutControlAnchorC1ENSt6__ndk110shared_ptrINS_4NodeEEE@plt>:
   d0230:      	adrp	x16, 0xdb000
   d0234:      	ldr	x17, [x16, #0x2f0]
   d0238:      	add	x16, x16, #0x2f0
   d023c:      	br	x17

00000000000d0240 <_ZNK2ge4Edge3SrcEv@plt>:
   d0240:      	adrp	x16, 0xdb000
   d0244:      	ldr	x17, [x16, #0x2f8]
   d0248:      	add	x16, x16, #0x2f8
   d024c:      	br	x17

00000000000d0250 <_ZNK2ge4Edge3DstEv@plt>:
   d0250:      	adrp	x16, 0xdb000
   d0254:      	ldr	x17, [x16, #0x300]
   d0258:      	add	x16, x16, #0x300
   d025c:      	br	x17

00000000000d0260 <_ZN2ge4EdgeC1ERNS_4NodeEiS2_i@plt>:
   d0260:      	adrp	x16, 0xdb000
   d0264:      	ldr	x17, [x16, #0x308]
   d0268:      	add	x16, x16, #0x308
   d026c:      	br	x17

00000000000d0270 <_ZNK2ge10LegacyNode20GetAllOutDataAnchorsEv@plt>:
   d0270:      	adrp	x16, 0xdb000
   d0274:      	ldr	x17, [x16, #0x310]
   d0278:      	add	x16, x16, #0x310
   d027c:      	br	x17

00000000000d0280 <_ZN2ge6OpDesc12AddInputDescERKNS_10TensorDescE@plt>:
   d0280:      	adrp	x16, 0xdb000
   d0284:      	ldr	x17, [x16, #0x318]
   d0288:      	add	x16, x16, #0x318
   d028c:      	br	x17

00000000000d0290 <_ZNK2ge10LegacyNode9GetOpDescEv@plt>:
   d0290:      	adrp	x16, 0xdb000
   d0294:      	ldr	x17, [x16, #0x320]
   d0298:      	add	x16, x16, #0x320
   d029c:      	br	x17

00000000000d02a0 <_ZNK2ge10LegacyNode19GetAllInDataAnchorsEv@plt>:
   d02a0:      	adrp	x16, 0xdb000
   d02a4:      	ldr	x17, [x16, #0x328]
   d02a8:      	add	x16, x16, #0x328
   d02ac:      	br	x17

00000000000d02b0 <_ZNK2ge10LegacyNode15GetInDataAnchorEi@plt>:
   d02b0:      	adrp	x16, 0xdb000
   d02b4:      	ldr	x17, [x16, #0x330]
   d02b8:      	add	x16, x16, #0x330
   d02bc:      	br	x17

00000000000d02c0 <_ZNK2ge10LegacyNode16GetOutDataAnchorEi@plt>:
   d02c0:      	adrp	x16, 0xdb000
   d02c4:      	ldr	x17, [x16, #0x338]
   d02c8:      	add	x16, x16, #0x338
   d02cc:      	br	x17

00000000000d02d0 <_ZNK2ge10LegacyNode18GetInControlAnchorEv@plt>:
   d02d0:      	adrp	x16, 0xdb000
   d02d4:      	ldr	x17, [x16, #0x340]
   d02d8:      	add	x16, x16, #0x340
   d02dc:      	br	x17

00000000000d02e0 <_ZNK2ge10LegacyNode19GetOutControlAnchorEv@plt>:
   d02e0:      	adrp	x16, 0xdb000
   d02e4:      	ldr	x17, [x16, #0x348]
   d02e8:      	add	x16, x16, #0x348
   d02ec:      	br	x17

00000000000d02f0 <_ZNK2ge10LegacyNode14GetInDataNodesEv@plt>:
   d02f0:      	adrp	x16, 0xdb000
   d02f4:      	ldr	x17, [x16, #0x350]
   d02f8:      	add	x16, x16, #0x350
   d02fc:      	br	x17

00000000000d0300 <_ZNK2ge10LegacyNode17GetInControlNodesEv@plt>:
   d0300:      	adrp	x16, 0xdb000
   d0304:      	ldr	x17, [x16, #0x358]
   d0308:      	add	x16, x16, #0x358
   d030c:      	br	x17

00000000000d0310 <_ZNK2ge12NodeSubGraph9SubGraphsEv@plt>:
   d0310:      	adrp	x16, 0xdb000
   d0314:      	ldr	x17, [x16, #0x360]
   d0318:      	add	x16, x16, #0x360
   d031c:      	br	x17

00000000000d0320 <_ZN2ge15NodeCompatibler21TransConstInputToAttrEmNSt6__ndk18functionIFjRKNS_6TensorERNS_6OpDescEEEE@plt>:
   d0320:      	adrp	x16, 0xdb000
   d0324:      	ldr	x17, [x16, #0x368]
   d0328:      	add	x16, x16, #0x368
   d032c:      	br	x17

00000000000d0330 <_ZN2ge10NodeWalker10InDataNodeEm@plt>:
   d0330:      	adrp	x16, 0xdb000
   d0334:      	ldr	x17, [x16, #0x370]
   d0338:      	add	x16, x16, #0x370
   d033c:      	br	x17

00000000000d0340 <_ZN2ge9AttrUtils13MutableTensorEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_10shared_ptrINS_6TensorEEE@plt>:
   d0340:      	adrp	x16, 0xdb000
   d0344:      	ldr	x17, [x16, #0x378]
   d0348:      	add	x16, x16, #0x378
   d034c:      	br	x17

00000000000d0350 <_ZN2ge15NodeCompatibler19RemoveSpecificInputEm@plt>:
   d0350:      	adrp	x16, 0xdb000
   d0354:      	ldr	x17, [x16, #0x380]
   d0358:      	add	x16, x16, #0x380
   d035c:      	br	x17

00000000000d0360 <_ZNK2ge8NodeSpec17OwnerComputeGraphEv@plt>:
   d0360:      	adrp	x16, 0xdb000
   d0364:      	ldr	x17, [x16, #0x388]
   d0368:      	add	x16, x16, #0x388
   d036c:      	br	x17

00000000000d0370 <_ZN2ge15NodeCompatibler18RemoveIdleEndpointEv@plt>:
   d0370:      	adrp	x16, 0xdb000
   d0374:      	ldr	x17, [x16, #0x390]
   d0378:      	add	x16, x16, #0x390
   d037c:      	br	x17

00000000000d0380 <_ZN2ge15NodeCompatibler23TransTensorToConstInputENSt6__ndk16vectorINS1_10shared_ptrINS_6TensorEEENS1_9allocatorIS5_EEEE@plt>:
   d0380:      	adrp	x16, 0xdb000
   d0384:      	ldr	x17, [x16, #0x398]
   d0388:      	add	x16, x16, #0x398
   d038c:      	br	x17

00000000000d0390 <_ZNK2ge6OpDesc19GetUnSetInputIndexsERNSt6__ndk16vectorIjNS1_9allocatorIjEEEE@plt>:
   d0390:      	adrp	x16, 0xdb000
   d0394:      	ldr	x17, [x16, #0x3a0]
   d0398:      	add	x16, x16, #0x3a0
   d039c:      	br	x17

00000000000d03a0 <_ZN2ge15NodeCompatibler23TransTensorToConstInputERKNSt6__ndk110shared_ptrINS_6TensorEEEi@plt>:
   d03a0:      	adrp	x16, 0xdb000
   d03a4:      	ldr	x17, [x16, #0x3a8]
   d03a8:      	add	x16, x16, #0x3a8
   d03ac:      	br	x17

00000000000d03b0 <_ZN2ge9AttrUtils9SetTensorEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_10shared_ptrINS_6TensorEEE@plt>:
   d03b0:      	adrp	x16, 0xdb000
   d03b4:      	ldr	x17, [x16, #0x3b0]
   d03b8:      	add	x16, x16, #0x3b0
   d03bc:      	br	x17

00000000000d03c0 <_ZNSt6__ndk19to_stringEm@plt>:
   d03c0:      	adrp	x16, 0xdb000
   d03c4:      	ldr	x17, [x16, #0x3b8]
   d03c8:      	add	x16, x16, #0x3b8
   d03cc:      	br	x17

00000000000d03d0 <_ZN2ge6OpDesc13AddOutputDescERKNS_10TensorDescE@plt>:
   d03d0:      	adrp	x16, 0xdb000
   d03d4:      	ldr	x17, [x16, #0x3c0]
   d03d8:      	add	x16, x16, #0x3c0
   d03dc:      	br	x17

00000000000d03e0 <_ZNK2ge6OpDesc17GetInputsDescSizeEv@plt>:
   d03e0:      	adrp	x16, 0xdb000
   d03e4:      	ldr	x17, [x16, #0x3c8]
   d03e8:      	add	x16, x16, #0x3c8
   d03ec:      	br	x17

00000000000d03f0 <_ZNK2ge6OpDesc16GetAllInputsDescEv@plt>:
   d03f0:      	adrp	x16, 0xdb000
   d03f4:      	ldr	x17, [x16, #0x3d0]
   d03f8:      	add	x16, x16, #0x3d0
   d03fc:      	br	x17

00000000000d0400 <_ZN2ge6OpDesc18ClearAllInputsDescEv@plt>:
   d0400:      	adrp	x16, 0xdb000
   d0404:      	ldr	x17, [x16, #0x3d8]
   d0408:      	add	x16, x16, #0x3d8
   d040c:      	br	x17

00000000000d0410 <_ZN2ge6OpDescC1Ev@plt>:
   d0410:      	adrp	x16, 0xdb000
   d0414:      	ldr	x17, [x16, #0x3e0]
   d0418:      	add	x16, x16, #0x3e0
   d041c:      	br	x17

00000000000d0420 <_ZN2ge14NodeSerializer13SaveSubGraphsEv@plt>:
   d0420:      	adrp	x16, 0xdb000
   d0424:      	ldr	x17, [x16, #0x3e8]
   d0428:      	add	x16, x16, #0x3e8
   d042c:      	br	x17

00000000000d0430 <_ZNK2ge6OpDesc11SerializeToEPN4hiai6IOpDefE@plt>:
   d0430:      	adrp	x16, 0xdb000
   d0434:      	ldr	x17, [x16, #0x3f0]
   d0438:      	add	x16, x16, #0x3f0
   d043c:      	br	x17

00000000000d0440 <_ZN2ge14NodeSerializer8SaveEdgeEPN4hiai6IOpDefE@plt>:
   d0440:      	adrp	x16, 0xdb000
   d0444:      	ldr	x17, [x16, #0x3f8]
   d0448:      	add	x16, x16, #0x3f8
   d044c:      	br	x17

00000000000d0450 <_ZN2ge14NodeSerializer20SaveSubGraphInIfNodeEv@plt>:
   d0450:      	adrp	x16, 0xdb000
   d0454:      	ldr	x17, [x16, #0x400]
   d0458:      	add	x16, x16, #0x400
   d045c:      	br	x17

00000000000d0460 <_ZN2ge14NodeSerializer22SaveSubGraphInCaseNodeEv@plt>:
   d0460:      	adrp	x16, 0xdb000
   d0464:      	ldr	x17, [x16, #0x408]
   d0468:      	add	x16, x16, #0x408
   d046c:      	br	x17

00000000000d0470 <_ZN2ge14NodeSerializer23SaveSubGraphInWhileNodeEv@plt>:
   d0470:      	adrp	x16, 0xdb000
   d0474:      	ldr	x17, [x16, #0x410]
   d0478:      	add	x16, x16, #0x410
   d047c:      	br	x17

00000000000d0480 <_ZN2ge14NodeSerializer19GetSubGraphInIfNodeEv@plt>:
   d0480:      	adrp	x16, 0xdb000
   d0484:      	ldr	x17, [x16, #0x418]
   d0488:      	add	x16, x16, #0x418
   d048c:      	br	x17

00000000000d0490 <_ZN2ge14NodeSerializer21GetSubGraphInCaseNodeEv@plt>:
   d0490:      	adrp	x16, 0xdb000
   d0494:      	ldr	x17, [x16, #0x420]
   d0498:      	add	x16, x16, #0x420
   d049c:      	br	x17

00000000000d04a0 <_ZN2ge14NodeSerializer22GetSubGraphInWhileNodeEv@plt>:
   d04a0:      	adrp	x16, 0xdb000
   d04a4:      	ldr	x17, [x16, #0x428]
   d04a8:      	add	x16, x16, #0x428
   d04ac:      	br	x17

00000000000d04b0 <_ZN2ge14NodeSerializer17GetSubGraphInNodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   d04b0:      	adrp	x16, 0xdb000
   d04b4:      	ldr	x17, [x16, #0x430]
   d04b8:      	add	x16, x16, #0x430
   d04bc:      	br	x17

00000000000d04c0 <_ZN2ge9AttrUtils10GetListStrEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_6vectorIS9_NS7_IS9_EEEE@plt>:
   d04c0:      	adrp	x16, 0xdb000
   d04c4:      	ldr	x17, [x16, #0x438]
   d04c8:      	add	x16, x16, #0x438
   d04cc:      	br	x17

00000000000d04d0 <_ZN2ge9AttrUtils8GetGraphEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_10shared_ptrINS_12ComputeGraphEEE@plt>:
   d04d0:      	adrp	x16, 0xdb000
   d04d4:      	ldr	x17, [x16, #0x440]
   d04d8:      	add	x16, x16, #0x440
   d04dc:      	br	x17

00000000000d04e0 <_ZN2ge14NodeSerializer18SaveSubGraphInNodeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   d04e0:      	adrp	x16, 0xdb000
   d04e4:      	ldr	x17, [x16, #0x448]
   d04e8:      	add	x16, x16, #0x448
   d04ec:      	br	x17

00000000000d04f0 <_ZNK2ge12NodeSubGraph15FindSubGraphPtrERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   d04f0:      	adrp	x16, 0xdb000
   d04f4:      	ldr	x17, [x16, #0x450]
   d04f8:      	add	x16, x16, #0x450
   d04fc:      	br	x17

00000000000d0500 <_ZN2ge9AttrUtils8SetGraphEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_10shared_ptrINS_12ComputeGraphEEE@plt>:
   d0500:      	adrp	x16, 0xdb000
   d0504:      	ldr	x17, [x16, #0x458]
   d0508:      	add	x16, x16, #0x458
   d050c:      	br	x17

00000000000d0510 <_ZN2ge9AttrUtils6GetStrEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERS9_@plt>:
   d0510:      	adrp	x16, 0xdb000
   d0514:      	ldr	x17, [x16, #0x460]
   d0518:      	add	x16, x16, #0x460
   d051c:      	br	x17

00000000000d0520 <_ZNK2ge6OpDesc5GetIdEv@plt>:
   d0520:      	adrp	x16, 0xdb000
   d0524:      	ldr	x17, [x16, #0x468]
   d0528:      	add	x16, x16, #0x468
   d052c:      	br	x17

00000000000d0530 <_ZNK2ge8NodeSpec14InNonConstSizeEv@plt>:
   d0530:      	adrp	x16, 0xdb000
   d0534:      	ldr	x17, [x16, #0x470]
   d0538:      	add	x16, x16, #0x470
   d053c:      	br	x17

00000000000d0540 <_ZNK2ge8NodeSpec18IsInputFullyLinkedEv@plt>:
   d0540:      	adrp	x16, 0xdb000
   d0544:      	ldr	x17, [x16, #0x478]
   d0548:      	add	x16, x16, #0x478
   d054c:      	br	x17

00000000000d0550 <_ZNK2ge6OpDesc20GetOptionalInputsIdxEv@plt>:
   d0550:      	adrp	x16, 0xdb000
   d0554:      	ldr	x17, [x16, #0x480]
   d0558:      	add	x16, x16, #0x480
   d055c:      	br	x17

00000000000d0560 <_ZNK2ge12NodeSubGraph13SubGraphsSizeEv@plt>:
   d0560:      	adrp	x16, 0xdb000
   d0564:      	ldr	x17, [x16, #0x488]
   d0568:      	add	x16, x16, #0x488
   d056c:      	br	x17

00000000000d0570 <_ZN2ge10NodeWalker11ListInNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   d0570:      	adrp	x16, 0xdb000
   d0574:      	ldr	x17, [x16, #0x490]
   d0578:      	add	x16, x16, #0x490
   d057c:      	br	x17

00000000000d0580 <_ZN2ge10NodeWalker11OutDataNodeEmm@plt>:
   d0580:      	adrp	x16, 0xdb000
   d0584:      	ldr	x17, [x16, #0x498]
   d0588:      	add	x16, x16, #0x498
   d058c:      	br	x17

00000000000d0590 <_ZN2ge10NodeWalker16ListOutDataNodesENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   d0590:      	adrp	x16, 0xdb000
   d0594:      	ldr	x17, [x16, #0x4a0]
   d0598:      	add	x16, x16, #0x4a0
   d059c:      	br	x17

00000000000d05a0 <_ZN2ge10NodeWalker23ListInDataEdgesNonConstENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   d05a0:      	adrp	x16, 0xdb000
   d05a4:      	ldr	x17, [x16, #0x4a8]
   d05a8:      	add	x16, x16, #0x4a8
   d05ac:      	br	x17

00000000000d05b0 <_ZN2ge10NodeWalker15ListInCtrlEdgesENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   d05b0:      	adrp	x16, 0xdb000
   d05b4:      	ldr	x17, [x16, #0x4b0]
   d05b8:      	add	x16, x16, #0x4b0
   d05bc:      	br	x17

00000000000d05c0 <_ZN2ge10NodeWalker16ListOutDataEdgesENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   d05c0:      	adrp	x16, 0xdb000
   d05c4:      	ldr	x17, [x16, #0x4b8]
   d05c8:      	add	x16, x16, #0x4b8
   d05cc:      	br	x17

00000000000d05d0 <_ZN2ge10NodeWalker16ListOutCtrlEdgesENSt6__ndk18functionIFjRNS_4EdgeEEEE@plt>:
   d05d0:      	adrp	x16, 0xdb000
   d05d4:      	ldr	x17, [x16, #0x4c0]
   d05d8:      	add	x16, x16, #0x4c0
   d05dc:      	br	x17

00000000000d05e0 <_ZN2ge6OpDescC2ERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEES9_@plt>:
   d05e0:      	adrp	x16, 0xdb000
   d05e4:      	ldr	x17, [x16, #0x4c8]
   d05e8:      	add	x16, x16, #0x4c8
   d05ec:      	br	x17

00000000000d05f0 <_ZN2ge6OpDescC2EPN4hiai6IOpDefEb@plt>:
   d05f0:      	adrp	x16, 0xdb000
   d05f4:      	ldr	x17, [x16, #0x4d0]
   d05f8:      	add	x16, x16, #0x4d0
   d05fc:      	br	x17

00000000000d0600 <_ZN2ge6OpDescD2Ev@plt>:
   d0600:      	adrp	x16, 0xdb000
   d0604:      	ldr	x17, [x16, #0x4d8]
   d0608:      	add	x16, x16, #0x4d8
   d060c:      	br	x17

00000000000d0610 <_ZN2ge17ConstHolderOpDescD1Ev@plt>:
   d0610:      	adrp	x16, 0xdb000
   d0614:      	ldr	x17, [x16, #0x4e0]
   d0618:      	add	x16, x16, #0x4e0
   d061c:      	br	x17

00000000000d0620 <_ZN2ge17ConstHolderOpDesc15IsConstHolderOpERKNS_6OpDescE@plt>:
   d0620:      	adrp	x16, 0xdb000
   d0624:      	ldr	x17, [x16, #0x4e8]
   d0628:      	add	x16, x16, #0x4e8
   d062c:      	br	x17

00000000000d0630 <_ZN2ge17ConstHolderOpDesc15SetHoldedOpDescEPNS_6OpDescE@plt>:
   d0630:      	adrp	x16, 0xdb000
   d0634:      	ldr	x17, [x16, #0x4f0]
   d0638:      	add	x16, x16, #0x4f0
   d063c:      	br	x17

00000000000d0640 <_ZNK2ge17ConstHolderOpDesc15GetHoldedOpDescEv@plt>:
   d0640:      	adrp	x16, 0xdb000
   d0644:      	ldr	x17, [x16, #0x4f8]
   d0648:      	add	x16, x16, #0x4f8
   d064c:      	br	x17

00000000000d0650 <_ZN4hiai12ProtoFactory11CreateOpDefEv@plt>:
   d0650:      	adrp	x16, 0xdb000
   d0654:      	ldr	x17, [x16, #0x500]
   d0658:      	add	x16, x16, #0x500
   d065c:      	br	x17

00000000000d0660 <_ZN4hiai12ProtoFactory12DestroyOpDefEPNS_6IOpDefE@plt>:
   d0660:      	adrp	x16, 0xdb000
   d0664:      	ldr	x17, [x16, #0x508]
   d0668:      	add	x16, x16, #0x508
   d066c:      	br	x17

00000000000d0670 <_ZN2ge17ConstHolderOpDescC1EPN4hiai6IOpDefEb@plt>:
   d0670:      	adrp	x16, 0xdb000
   d0674:      	ldr	x17, [x16, #0x510]
   d0678:      	add	x16, x16, #0x510
   d067c:      	br	x17

00000000000d0680 <_ZN2ge6OpDescC2Ev@plt>:
   d0680:      	adrp	x16, 0xdb000
   d0684:      	ldr	x17, [x16, #0x518]
   d0688:      	add	x16, x16, #0x518
   d068c:      	br	x17

00000000000d0690 <_ZN2ge6OpDescD1Ev@plt>:
   d0690:      	adrp	x16, 0xdb000
   d0694:      	ldr	x17, [x16, #0x520]
   d0698:      	add	x16, x16, #0x520
   d069c:      	br	x17

00000000000d06a0 <_ZN2ge6OpDescC1EPN4hiai6IOpDefEb@plt>:
   d06a0:      	adrp	x16, 0xdb000
   d06a4:      	ldr	x17, [x16, #0x528]
   d06a8:      	add	x16, x16, #0x528
   d06ac:      	br	x17

00000000000d06b0 <_ZNK2ge6OpDesc16MutableInputDescEj@plt>:
   d06b0:      	adrp	x16, 0xdb000
   d06b4:      	ldr	x17, [x16, #0x530]
   d06b8:      	add	x16, x16, #0x530
   d06bc:      	br	x17

00000000000d06c0 <_ZNK2ge6OpDesc13GetInputsSizeEv@plt>:
   d06c0:      	adrp	x16, 0xdb000
   d06c4:      	ldr	x17, [x16, #0x538]
   d06c8:      	add	x16, x16, #0x538
   d06cc:      	br	x17

00000000000d06d0 <_ZN2ge6OpDesc16UpdateOutputDescEjRKNS_10TensorDescE@plt>:
   d06d0:      	adrp	x16, 0xdb000
   d06d4:      	ldr	x17, [x16, #0x540]
   d06d8:      	add	x16, x16, #0x540
   d06dc:      	br	x17

00000000000d06e0 <_ZN2ge6OpDesc19ClearAllOutputsDescEv@plt>:
   d06e0:      	adrp	x16, 0xdb000
   d06e4:      	ldr	x17, [x16, #0x548]
   d06e8:      	add	x16, x16, #0x548
   d06ec:      	br	x17

00000000000d06f0 <_ZNK2ge6OpDesc14GetIrAttrNamesEv@plt>:
   d06f0:      	adrp	x16, 0xdb000
   d06f4:      	ldr	x17, [x16, #0x550]
   d06f8:      	add	x16, x16, #0x550
   d06fc:      	br	x17

00000000000d0700 <_ZNK2ge6OpDesc12IsInputConstEi@plt>:
   d0700:      	adrp	x16, 0xdb000
   d0704:      	ldr	x17, [x16, #0x558]
   d0708:      	add	x16, x16, #0x558
   d070c:      	br	x17

00000000000d0710 <_ZN2ge6OpDesc18GetInputsParamTypeEv@plt>:
   d0710:      	adrp	x16, 0xdb000
   d0714:      	ldr	x17, [x16, #0x560]
   d0718:      	add	x16, x16, #0x560
   d071c:      	br	x17

00000000000d0720 <_ZN2ge6OpDesc19GetOutPutsParamTypeEv@plt>:
   d0720:      	adrp	x16, 0xdb000
   d0724:      	ldr	x17, [x16, #0x568]
   d0728:      	add	x16, x16, #0x568
   d072c:      	br	x17

00000000000d0730 <_ZNK4hiai13PatternDefine13VerifyPatternEv@plt>:
   d0730:      	adrp	x16, 0xdb000
   d0734:      	ldr	x17, [x16, #0x570]
   d0738:      	add	x16, x16, #0x570
   d073c:      	br	x17

00000000000d0740 <_ZN4hiai13PatternDefine20VerifyInputsHomologyEPNS_14PatternMappingE@plt>:
   d0740:      	adrp	x16, 0xdb000
   d0744:      	ldr	x17, [x16, #0x578]
   d0748:      	add	x16, x16, #0x578
   d074c:      	br	x17

00000000000d0750 <wmemchr@plt>:
   d0750:      	adrp	x16, 0xdb000
   d0754:      	ldr	x17, [x16, #0x580]
   d0758:      	add	x16, x16, #0x580
   d075c:      	br	x17

00000000000d0760 <_ZN4hiai13PatternDefine13VerifyOutNodeERKN2ge4NodeE@plt>:
   d0760:      	adrp	x16, 0xdb000
   d0764:      	ldr	x17, [x16, #0x588]
   d0768:      	add	x16, x16, #0x588
   d076c:      	br	x17

00000000000d0770 <_ZN4hiai13PatternDefine13BfsFromOutputERKN2ge12ComputeGraphERKNS1_4NodeE@plt>:
   d0770:      	adrp	x16, 0xdb000
   d0774:      	ldr	x17, [x16, #0x590]
   d0778:      	add	x16, x16, #0x590
   d077c:      	br	x17

00000000000d0780 <_ZN4hiai13PatternDefine5MatchERKN2ge4NodeERKNS1_12ComputeGraphE@plt>:
   d0780:      	adrp	x16, 0xdb000
   d0784:      	ldr	x17, [x16, #0x598]
   d0788:      	add	x16, x16, #0x598
   d078c:      	br	x17

00000000000d0790 <dlopen@plt>:
   d0790:      	adrp	x16, 0xdb000
   d0794:      	ldr	x17, [x16, #0x5a0]
   d0798:      	add	x16, x16, #0x5a0
   d079c:      	br	x17

00000000000d07a0 <dlerror@plt>:
   d07a0:      	adrp	x16, 0xdb000
   d07a4:      	ldr	x17, [x16, #0x5a8]
   d07a8:      	add	x16, x16, #0x5a8
   d07ac:      	br	x17

00000000000d07b0 <dlclose@plt>:
   d07b0:      	adrp	x16, 0xdb000
   d07b4:      	ldr	x17, [x16, #0x5b0]
   d07b8:      	add	x16, x16, #0x5b0
   d07bc:      	br	x17

00000000000d07c0 <_ZN2ge11AnchorUtils9GetFormatENSt6__ndk110shared_ptrINS_10DataAnchorEEE@plt>:
   d07c0:      	adrp	x16, 0xdb000
   d07c4:      	ldr	x17, [x16, #0x5b8]
   d07c8:      	add	x16, x16, #0x5b8
   d07cc:      	br	x17

00000000000d07d0 <_ZN2ge11AnchorUtils9SetFormatENSt6__ndk110shared_ptrINS_10DataAnchorEEENS_6FormatE@plt>:
   d07d0:      	adrp	x16, 0xdb000
   d07d4:      	ldr	x17, [x16, #0x5c0]
   d07d8:      	add	x16, x16, #0x5c0
   d07dc:      	br	x17

00000000000d07e0 <_ZN2ge9AttrUtils6SetIntEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKl@plt>:
   d07e0:      	adrp	x16, 0xdb000
   d07e4:      	ldr	x17, [x16, #0x5c8]
   d07e8:      	add	x16, x16, #0x5c8
   d07ec:      	br	x17

00000000000d07f0 <_ZN2ge9AttrUtils6GetIntEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERl@plt>:
   d07f0:      	adrp	x16, 0xdb000
   d07f4:      	ldr	x17, [x16, #0x5d0]
   d07f8:      	add	x16, x16, #0x5d0
   d07fc:      	br	x17

00000000000d0800 <_ZN2ge9AttrUtils8SetFloatEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKf@plt>:
   d0800:      	adrp	x16, 0xdb000
   d0804:      	ldr	x17, [x16, #0x5d8]
   d0808:      	add	x16, x16, #0x5d8
   d080c:      	br	x17

00000000000d0810 <_ZN2ge9AttrUtils8GetFloatEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERf@plt>:
   d0810:      	adrp	x16, 0xdb000
   d0814:      	ldr	x17, [x16, #0x5e0]
   d0818:      	add	x16, x16, #0x5e0
   d081c:      	br	x17

00000000000d0820 <_ZN2ge9AttrUtils7SetBoolEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKb@plt>:
   d0820:      	adrp	x16, 0xdb000
   d0824:      	ldr	x17, [x16, #0x5e8]
   d0828:      	add	x16, x16, #0x5e8
   d082c:      	br	x17

00000000000d0830 <_ZN2ge9AttrUtils7GetBoolEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERb@plt>:
   d0830:      	adrp	x16, 0xdb000
   d0834:      	ldr	x17, [x16, #0x5f0]
   d0838:      	add	x16, x16, #0x5f0
   d083c:      	br	x17

00000000000d0840 <_ZN2ge9AttrUtils6SetStrEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEESB_@plt>:
   d0840:      	adrp	x16, 0xdb000
   d0844:      	ldr	x17, [x16, #0x5f8]
   d0848:      	add	x16, x16, #0x5f8
   d084c:      	br	x17

00000000000d0850 <_ZN2ge9AttrUtils9GetTensorEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_10shared_ptrINS_6TensorEEE@plt>:
   d0850:      	adrp	x16, 0xdb000
   d0854:      	ldr	x17, [x16, #0x600]
   d0858:      	add	x16, x16, #0x600
   d085c:      	br	x17

00000000000d0860 <_ZN2ge9AttrUtils10SetListIntEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_6vectorIlNS7_IlEEEE@plt>:
   d0860:      	adrp	x16, 0xdb000
   d0864:      	ldr	x17, [x16, #0x608]
   d0868:      	add	x16, x16, #0x608
   d086c:      	br	x17

00000000000d0870 <_ZN2ge9AttrUtils10GetListIntEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_6vectorIlNS7_IlEEEE@plt>:
   d0870:      	adrp	x16, 0xdb000
   d0874:      	ldr	x17, [x16, #0x610]
   d0878:      	add	x16, x16, #0x610
   d087c:      	br	x17

00000000000d0880 <_ZN2ge9AttrUtils12SetListFloatEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_6vectorIfNS7_IfEEEE@plt>:
   d0880:      	adrp	x16, 0xdb000
   d0884:      	ldr	x17, [x16, #0x618]
   d0888:      	add	x16, x16, #0x618
   d088c:      	br	x17

00000000000d0890 <_ZN2ge9AttrUtils12GetListFloatEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_6vectorIfNS7_IfEEEE@plt>:
   d0890:      	adrp	x16, 0xdb000
   d0894:      	ldr	x17, [x16, #0x620]
   d0898:      	add	x16, x16, #0x620
   d089c:      	br	x17

00000000000d08a0 <_ZN2ge9AttrUtils13SetListTensorEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_6vectorINS3_10shared_ptrINS_6TensorEEENS7_ISF_EEEE@plt>:
   d08a0:      	adrp	x16, 0xdb000
   d08a4:      	ldr	x17, [x16, #0x628]
   d08a8:      	add	x16, x16, #0x628
   d08ac:      	br	x17

00000000000d08b0 <_ZN2ge9AttrUtils6GetIntEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERi@plt>:
   d08b0:      	adrp	x16, 0xdb000
   d08b4:      	ldr	x17, [x16, #0x630]
   d08b8:      	add	x16, x16, #0x630
   d08bc:      	br	x17

00000000000d08c0 <_ZN2ge9AttrUtils6GetIntEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERj@plt>:
   d08c0:      	adrp	x16, 0xdb000
   d08c4:      	ldr	x17, [x16, #0x638]
   d08c8:      	add	x16, x16, #0x638
   d08cc:      	br	x17

00000000000d08d0 <_ZN2ge9AttrUtils10GetListIntEONS0_22ConstAttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERNS3_6vectorIiNS7_IiEEEE@plt>:
   d08d0:      	adrp	x16, 0xdb000
   d08d4:      	ldr	x17, [x16, #0x640]
   d08d8:      	add	x16, x16, #0x640
   d08dc:      	br	x17

00000000000d08e0 <_ZN2ge9AttrUtils10SetListIntEONS0_17AttrHolderAdapterERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEERKNS3_6vectorIiNS7_IiEEEE@plt>:
   d08e0:      	adrp	x16, 0xdb000
   d08e4:      	ldr	x17, [x16, #0x648]
   d08e8:      	add	x16, x16, #0x648
   d08ec:      	br	x17

00000000000d08f0 <memcpy@plt>:
   d08f0:      	adrp	x16, 0xdb000
   d08f4:      	ldr	x17, [x16, #0x650]
   d08f8:      	add	x16, x16, #0x650
   d08fc:      	br	x17

00000000000d0900 <_ZN2ge10GraphUtils7AddEdgeENSt6__ndk110shared_ptrINS_13OutDataAnchorEEENS2_INS_12InDataAnchorEEE@plt>:
   d0900:      	adrp	x16, 0xdb000
   d0904:      	ldr	x17, [x16, #0x658]
   d0908:      	add	x16, x16, #0x658
   d090c:      	br	x17

00000000000d0910 <_ZN2ge10GraphUtils10RemoveEdgeENSt6__ndk110shared_ptrINS_13OutDataAnchorEEENS2_INS_12InDataAnchorEEE@plt>:
   d0910:      	adrp	x16, 0xdb000
   d0914:      	ldr	x17, [x16, #0x660]
   d0918:      	add	x16, x16, #0x660
   d091c:      	br	x17

00000000000d0920 <_ZN2ge10GraphUtils19RecordOriginalNamesERKNSt6__ndk16vectorIPNS_4NodeENS1_9allocatorIS4_EEEERKS3_@plt>:
   d0920:      	adrp	x16, 0xdb000
   d0924:      	ldr	x17, [x16, #0x668]
   d0928:      	add	x16, x16, #0x668
   d092c:      	br	x17

00000000000d0930 <_ZN2ge10GraphUtils16WalkAllSubGraphsERKNS_12ComputeGraphENSt6__ndk18functionIFjRNS4_10shared_ptrIS1_EEEEE@plt>:
   d0930:      	adrp	x16, 0xdb000
   d0934:      	ldr	x17, [x16, #0x670]
   d0938:      	add	x16, x16, #0x670
   d093c:      	br	x17

00000000000d0940 <_ZN2ge10GraphUtils20WalkAllSubGraphNodesERKNS_12ComputeGraphENSt6__ndk18functionIFjRNS_4NodeEEEE@plt>:
   d0940:      	adrp	x16, 0xdb000
   d0944:      	ldr	x17, [x16, #0x678]
   d0948:      	add	x16, x16, #0x678
   d094c:      	br	x17

00000000000d0950 <_ZN2ge11OpDescUtils10SetWeightsERNS_6OpDescENSt6__ndk110shared_ptrINS_6TensorEEE@plt>:
   d0950:      	adrp	x16, 0xdb000
   d0954:      	ldr	x17, [x16, #0x680]
   d0958:      	add	x16, x16, #0x680
   d095c:      	br	x17

00000000000d0960 <_ZN2ge11OpDescUtils10GetWeightsERKNS_4NodeE@plt>:
   d0960:      	adrp	x16, 0xdb000
   d0964:      	ldr	x17, [x16, #0x688]
   d0968:      	add	x16, x16, #0x688
   d096c:      	br	x17

00000000000d0970 <_ZN2ge11OpDescUtils14MutableWeightsERKNS_4NodeE@plt>:
   d0970:      	adrp	x16, 0xdb000
   d0974:      	ldr	x17, [x16, #0x690]
   d0978:      	add	x16, x16, #0x690
   d097c:      	br	x17

00000000000d0980 <_ZN2ge11OpDescUtils14GetConstInputsERKNS_4NodeE@plt>:
   d0980:      	adrp	x16, 0xdb000
   d0984:      	ldr	x17, [x16, #0x698]
   d0988:      	add	x16, x16, #0x698
   d098c:      	br	x17

00000000000d0990 <_ZN2ge11OpDescUtils26GetNonConstInputTensorDescERKNS_4NodeEm@plt>:
   d0990:      	adrp	x16, 0xdb000
   d0994:      	ldr	x17, [x16, #0x6a0]
   d0998:      	add	x16, x16, #0x6a0
   d099c:      	br	x17

00000000000d09a0 <_ZN2ge11OpDescUtils15IsNonConstInputERKNS_4NodeEm@plt>:
   d09a0:      	adrp	x16, 0xdb000
   d09a4:      	ldr	x17, [x16, #0x6a8]
   d09a8:      	add	x16, x16, #0x6a8
   d09ac:      	br	x17

00000000000d09b0 <_ZN2ge11OpDescUtils21GetNonConstTensorDescERKNS_4NodeE@plt>:
   d09b0:      	adrp	x16, 0xdb000
   d09b4:      	ldr	x17, [x16, #0x6b0]
   d09b8:      	add	x16, x16, #0x6b0
   d09bc:      	br	x17

00000000000d09c0 <_ZN2ge11OpDescUtils10SetWeightsERNS_4NodeERKNSt6__ndk16vectorINS3_10shared_ptrINS_6TensorEEENS3_9allocatorIS7_EEEE@plt>:
   d09c0:      	adrp	x16, 0xdb000
   d09c4:      	ldr	x17, [x16, #0x6b8]
   d09c8:      	add	x16, x16, #0x6b8
   d09cc:      	br	x17

00000000000d09d0 <_ZN2ge11OpDescUtils12ClearWeightsERNS_4NodeE@plt>:
   d09d0:      	adrp	x16, 0xdb000
   d09d4:      	ldr	x17, [x16, #0x6c0]
   d09d8:      	add	x16, x16, #0x6c0
   d09dc:      	br	x17

00000000000d09e0 <_ZN2ge11OpDescUtils19GetOpDescFromOpTypeERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEE@plt>:
   d09e0:      	adrp	x16, 0xdb000
   d09e4:      	ldr	x17, [x16, #0x6c8]
   d09e8:      	add	x16, x16, #0x6c8
   d09ec:      	br	x17

00000000000d09f0 <_ZN2ge16GraphSrcBoundary11InDataEdgesEv@plt>:
   d09f0:      	adrp	x16, 0xdb000
   d09f4:      	ldr	x17, [x16, #0x6d0]
   d09f8:      	add	x16, x16, #0x6d0
   d09fc:      	br	x17

00000000000d0a00 <_ZN2ge16GraphSrcBoundary12RelinkInputsERKNS_16GraphDstBoundaryE@plt>:
   d0a00:      	adrp	x16, 0xdb000
   d0a04:      	ldr	x17, [x16, #0x6d8]
   d0a08:      	add	x16, x16, #0x6d8
   d0a0c:      	br	x17

00000000000d0a10 <_ZN2ge16GraphSrcBoundary13RelinkOutputsERKNS_16GraphDstBoundaryE@plt>:
   d0a10:      	adrp	x16, 0xdb000
   d0a14:      	ldr	x17, [x16, #0x6e0]
   d0a18:      	add	x16, x16, #0x6e0
   d0a1c:      	br	x17

00000000000d0a20 <_ZN2ge16GraphSrcBoundary14RemoveAllNodesEv@plt>:
   d0a20:      	adrp	x16, 0xdb000
   d0a24:      	ldr	x17, [x16, #0x6e8]
   d0a28:      	add	x16, x16, #0x6e8
   d0a2c:      	br	x17

00000000000d0a30 <_ZN2ge16GraphSrcBoundary13MarkRecursiveEPNS_4NodeERNSt6__ndk16vectorIS2_NS3_9allocatorIS2_EEEE@plt>:
   d0a30:      	adrp	x16, 0xdb000
   d0a34:      	ldr	x17, [x16, #0x6f0]
   d0a38:      	add	x16, x16, #0x6f0
   d0a3c:      	br	x17

00000000000d0a40 <_ZN2ge16GraphSrcBoundary15MarkConstInputsEPNS_4NodeERNSt6__ndk16vectorIS2_NS3_9allocatorIS2_EEEE@plt>:
   d0a40:      	adrp	x16, 0xdb000
   d0a44:      	ldr	x17, [x16, #0x6f8]
   d0a48:      	add	x16, x16, #0x6f8
   d0a4c:      	br	x17

00000000000d0a50 <_ZN2ge16GraphSrcBoundary12MarkBackwardEPNS_4NodeERNSt6__ndk16vectorIS2_NS3_9allocatorIS2_EEEE@plt>:
   d0a50:      	adrp	x16, 0xdb000
   d0a54:      	ldr	x17, [x16, #0x700]
   d0a58:      	add	x16, x16, #0x700
   d0a5c:      	br	x17

00000000000d0a60 <_ZN2ge16GraphSrcBoundary11MarkForwardEPNS_4NodeERNSt6__ndk16vectorIS2_NS3_9allocatorIS2_EEEE@plt>:
   d0a60:      	adrp	x16, 0xdb000
   d0a64:      	ldr	x17, [x16, #0x708]
   d0a68:      	add	x16, x16, #0x708
   d0a6c:      	br	x17

00000000000d0a70 <_ZN2ge11TensorUtils13GetWeightSizeERKNS_10TensorDescE@plt>:
   d0a70:      	adrp	x16, 0xdb000
   d0a74:      	ldr	x17, [x16, #0x710]
   d0a78:      	add	x16, x16, #0x710
   d0a7c:      	br	x17

00000000000d0a80 <_ZN2ge11TensorUtils13GetWeightAddrERKNS_6TensorEPKh@plt>:
   d0a80:      	adrp	x16, 0xdb000
   d0a84:      	ldr	x17, [x16, #0x718]
   d0a88:      	add	x16, x16, #0x718
   d0a8c:      	br	x17

00000000000d0a90 <_ZN2ge11TensorUtils13SetWeightSizeERNS_10TensorDescEj@plt>:
   d0a90:      	adrp	x16, 0xdb000
   d0a94:      	ldr	x17, [x16, #0x720]
   d0a98:      	add	x16, x16, #0x720
   d0a9c:      	br	x17

00000000000d0aa0 <_ZN2ge11TensorUtils13SetRealDimCntERNS_10TensorDescEj@plt>:
   d0aa0:      	adrp	x16, 0xdb000
   d0aa4:      	ldr	x17, [x16, #0x728]
   d0aa8:      	add	x16, x16, #0x728
   d0aac:      	br	x17

00000000000d0ab0 <_ZN2ge11TensorUtils24GetAlloffsetQuantizeInfoERKNS_10TensorDescERNS_21AllOffsetQuantizeInfoE@plt>:
   d0ab0:      	adrp	x16, 0xdb000
   d0ab4:      	ldr	x17, [x16, #0x730]
   d0ab8:      	add	x16, x16, #0x730
   d0abc:      	br	x17

00000000000d0ac0 <_ZN2ge11TensorUtils10DeleteAttrERNS_10TensorDescERKNSt6__ndk112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEE@plt>:
   d0ac0:      	adrp	x16, 0xdb000
   d0ac4:      	ldr	x17, [x16, #0x738]
   d0ac8:      	add	x16, x16, #0x738
   d0acc:      	br	x17

00000000000d0ad0 <_ZN4hiai13IRTransformer23TransferToTargetVersionENSt6__ndk110shared_ptrIN2ge12ComputeGraphEEENS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERb@plt>:
   d0ad0:      	adrp	x16, 0xdb000
   d0ad4:      	ldr	x17, [x16, #0x740]
   d0ad8:      	add	x16, x16, #0x740
   d0adc:      	br	x17

00000000000d0ae0 <strncmp@plt>:
   d0ae0:      	adrp	x16, 0xdb000
   d0ae4:      	ldr	x17, [x16, #0x748]
   d0ae8:      	add	x16, x16, #0x748
   d0aec:      	br	x17

00000000000d0af0 <_ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7compareEPKc@plt>:
   d0af0:      	adrp	x16, 0xdb000
   d0af4:      	ldr	x17, [x16, #0x750]
   d0af8:      	add	x16, x16, #0x750
   d0afc:      	br	x17

00000000000d0b00 <_ZnamRKSt9nothrow_t@plt>:
   d0b00:      	adrp	x16, 0xdb000
   d0b04:      	ldr	x17, [x16, #0x758]
   d0b08:      	add	x16, x16, #0x758
   d0b0c:      	br	x17

00000000000d0b10 <_ZN2ge7tagFp167toFloatEv@plt>:
   d0b10:      	adrp	x16, 0xdb000
   d0b14:      	ldr	x17, [x16, #0x760]
   d0b18:      	add	x16, x16, #0x760
   d0b1c:      	br	x17

00000000000d0b20 <_ZN2ge7tagFp16aSERKf@plt>:
   d0b20:      	adrp	x16, 0xdb000
   d0b24:      	ldr	x17, [x16, #0x768]
   d0b28:      	add	x16, x16, #0x768
   d0b2c:      	br	x17

00000000000d0b30 <_ZNSt6__ndk14stoiERKNS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEEPmi@plt>:
   d0b30:      	adrp	x16, 0xdb000
   d0b34:      	ldr	x17, [x16, #0x770]
   d0b38:      	add	x16, x16, #0x770
   d0b3c:      	br	x17

00000000000d0b40 <_ZN4hiai22TransTensorHALFToFloatERKNS_9tagTensorEPKvS2_Pv@plt>:
   d0b40:      	adrp	x16, 0xdb000
   d0b44:      	ldr	x17, [x16, #0x778]
   d0b48:      	add	x16, x16, #0x778
   d0b4c:      	br	x17

00000000000d0b50 <_ZNK2ge7tagFp16cvfEv@plt>:
   d0b50:      	adrp	x16, 0xdb000
   d0b54:      	ldr	x17, [x16, #0x780]
   d0b58:      	add	x16, x16, #0x780
   d0b5c:      	br	x17

00000000000d0b60 <_ZN4hiai13ProtoGraphDefC1ERNS_5proto8GraphDefE@plt>:
   d0b60:      	adrp	x16, 0xdb000
   d0b64:      	ldr	x17, [x16, #0x788]
   d0b68:      	add	x16, x16, #0x788
   d0b6c:      	br	x17

00000000000d0b70 <_ZN4hiai13ProtoGraphDefC2ERNS_5proto8GraphDefE@plt>:
   d0b70:      	adrp	x16, 0xdb000
   d0b74:      	ldr	x17, [x16, #0x790]
   d0b78:      	add	x16, x16, #0x790
   d0b7c:      	br	x17

00000000000d0b80 <_ZN4hiai13ProtoGraphDefD2Ev@plt>:
   d0b80:      	adrp	x16, 0xdb000
   d0b84:      	ldr	x17, [x16, #0x798]
   d0b88:      	add	x16, x16, #0x798
   d0b8c:      	br	x17

00000000000d0b90 <_ZN4hiai13ProtoGraphDefD1Ev@plt>:
   d0b90:      	adrp	x16, 0xdb000
   d0b94:      	ldr	x17, [x16, #0x7a0]
   d0b98:      	add	x16, x16, #0x7a0
   d0b9c:      	br	x17

00000000000d0ba0 <_ZNK4hiai13ProtoGraphDef12lazy_op_initEv@plt>:
   d0ba0:      	adrp	x16, 0xdb000
   d0ba4:      	ldr	x17, [x16, #0x7a8]
   d0ba8:      	add	x16, x16, #0x7a8
   d0bac:      	br	x17

00000000000d0bb0 <_ZN4hiai10ProtoOpDefC1ERNS_5proto5OpDefE@plt>:
   d0bb0:      	adrp	x16, 0xdb000
   d0bb4:      	ldr	x17, [x16, #0x7b0]
   d0bb8:      	add	x16, x16, #0x7b0
   d0bbc:      	br	x17

00000000000d0bc0 <_ZNK4hiai13ProtoGraphDef14lazy_attr_initEv@plt>:
   d0bc0:      	adrp	x16, 0xdb000
   d0bc4:      	ldr	x17, [x16, #0x7b8]
   d0bc8:      	add	x16, x16, #0x7b8
   d0bcc:      	br	x17

00000000000d0bd0 <realpath@plt>:
   d0bd0:      	adrp	x16, 0xdb000
   d0bd4:      	ldr	x17, [x16, #0x7c0]
   d0bd8:      	add	x16, x16, #0x7c0
   d0bdc:      	br	x17

00000000000d0be0 <open@plt>:
   d0be0:      	adrp	x16, 0xdb000
   d0be4:      	ldr	x17, [x16, #0x7c8]
   d0be8:      	add	x16, x16, #0x7c8
   d0bec:      	br	x17

00000000000d0bf0 <close@plt>:
   d0bf0:      	adrp	x16, 0xdb000
   d0bf4:      	ldr	x17, [x16, #0x7d0]
   d0bf8:      	add	x16, x16, #0x7d0
   d0bfc:      	br	x17

00000000000d0c00 <_ZN4hiai10ProtoOpDefC2ERNS_5proto5OpDefE@plt>:
   d0c00:      	adrp	x16, 0xdb000
   d0c04:      	ldr	x17, [x16, #0x7d8]
   d0c08:      	add	x16, x16, #0x7d8
   d0c0c:      	br	x17

00000000000d0c10 <_ZN4hiai10ProtoOpDefD2Ev@plt>:
   d0c10:      	adrp	x16, 0xdb000
   d0c14:      	ldr	x17, [x16, #0x7e0]
   d0c18:      	add	x16, x16, #0x7e0
   d0c1c:      	br	x17

00000000000d0c20 <_ZN4hiai10ProtoOpDefD1Ev@plt>:
   d0c20:      	adrp	x16, 0xdb000
   d0c24:      	ldr	x17, [x16, #0x7e8]
   d0c28:      	add	x16, x16, #0x7e8
   d0c2c:      	br	x17

00000000000d0c30 <_ZNK4hiai10ProtoOpDef14lazy_attr_initEv@plt>:
   d0c30:      	adrp	x16, 0xdb000
   d0c34:      	ldr	x17, [x16, #0x7f0]
   d0c38:      	add	x16, x16, #0x7f0
   d0c3c:      	br	x17

00000000000d0c40 <_ZNK4hiai10ProtoOpDef20lazy_input_desc_initEv@plt>:
   d0c40:      	adrp	x16, 0xdb000
   d0c44:      	ldr	x17, [x16, #0x7f8]
   d0c48:      	add	x16, x16, #0x7f8
   d0c4c:      	br	x17

00000000000d0c50 <_ZNK4hiai10ProtoOpDef21lazy_output_desc_initEv@plt>:
   d0c50:      	adrp	x16, 0xdb000
   d0c54:      	ldr	x17, [x16, #0x800]
   d0c58:      	add	x16, x16, #0x800
   d0c5c:      	br	x17

00000000000d0c60 <_Znam@plt>:
   d0c60:      	adrp	x16, 0xdb000
   d0c64:      	ldr	x17, [x16, #0x808]
   d0c68:      	add	x16, x16, #0x808
   d0c6c:      	br	x17

00000000000d0c70 <__android_log_vprint@plt>:
   d0c70:      	adrp	x16, 0xdb000
   d0c74:      	ldr	x17, [x16, #0x810]
   d0c78:      	add	x16, x16, #0x810
   d0c7c:      	br	x17

00000000000d0c80 <__android_log_write@plt>:
   d0c80:      	adrp	x16, 0xdb000
   d0c84:      	ldr	x17, [x16, #0x818]
   d0c88:      	add	x16, x16, #0x818
   d0c8c:      	br	x17

00000000000d0c90 <pthread_key_create@plt>:
   d0c90:      	adrp	x16, 0xdb000
   d0c94:      	ldr	x17, [x16, #0x820]
   d0c98:      	add	x16, x16, #0x820
   d0c9c:      	br	x17

00000000000d0ca0 <pthread_getspecific@plt>:
   d0ca0:      	adrp	x16, 0xdb000
   d0ca4:      	ldr	x17, [x16, #0x828]
   d0ca8:      	add	x16, x16, #0x828
   d0cac:      	br	x17

00000000000d0cb0 <pthread_setspecific@plt>:
   d0cb0:      	adrp	x16, 0xdb000
   d0cb4:      	ldr	x17, [x16, #0x830]
   d0cb8:      	add	x16, x16, #0x830
   d0cbc:      	br	x17

00000000000d0cc0 <pthread_self@plt>:
   d0cc0:      	adrp	x16, 0xdb000
   d0cc4:      	ldr	x17, [x16, #0x838]
   d0cc8:      	add	x16, x16, #0x838
   d0ccc:      	br	x17

00000000000d0cd0 <_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE7reserveEm@plt>:
   d0cd0:      	adrp	x16, 0xdb000
   d0cd4:      	ldr	x17, [x16, #0x840]
   d0cd8:      	add	x16, x16, #0x840
   d0cdc:      	br	x17

00000000000d0ce0 <__errno@plt>:
   d0ce0:      	adrp	x16, 0xdb000
   d0ce4:      	ldr	x17, [x16, #0x848]
   d0ce8:      	add	x16, x16, #0x848
   d0cec:      	br	x17

00000000000d0cf0 <strerror@plt>:
   d0cf0:      	adrp	x16, 0xdb000
   d0cf4:      	ldr	x17, [x16, #0x850]
   d0cf8:      	add	x16, x16, #0x850
   d0cfc:      	br	x17

00000000000d0d00 <write@plt>:
   d0d00:      	adrp	x16, 0xdb000
   d0d04:      	ldr	x17, [x16, #0x858]
   d0d08:      	add	x16, x16, #0x858
   d0d0c:      	br	x17

00000000000d0d10 <vsnprintf@plt>:
   d0d10:      	adrp	x16, 0xdb000
   d0d14:      	ldr	x17, [x16, #0x860]
   d0d18:      	add	x16, x16, #0x860
   d0d1c:      	br	x17

00000000000d0d20 <_ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv@plt>:
   d0d20:      	adrp	x16, 0xdb000
   d0d24:      	ldr	x17, [x16, #0x868]
   d0d28:      	add	x16, x16, #0x868
   d0d2c:      	br	x17

00000000000d0d30 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev@plt>:
   d0d30:      	adrp	x16, 0xdb000
   d0d34:      	ldr	x17, [x16, #0x870]
   d0d38:      	add	x16, x16, #0x870
   d0d3c:      	br	x17

00000000000d0d40 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEED2Ev@plt>:
   d0d40:      	adrp	x16, 0xdb000
   d0d44:      	ldr	x17, [x16, #0x878]
   d0d48:      	add	x16, x16, #0x878
   d0d4c:      	br	x17

00000000000d0d50 <_ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev@plt>:
   d0d50:      	adrp	x16, 0xdb000
   d0d54:      	ldr	x17, [x16, #0x880]
   d0d58:      	add	x16, x16, #0x880
   d0d5c:      	br	x17

00000000000d0d60 <_ZNSt6__ndk18ios_base4initEPv@plt>:
   d0d60:      	adrp	x16, 0xdb000
   d0d64:      	ldr	x17, [x16, #0x888]
   d0d68:      	add	x16, x16, #0x888
   d0d6c:      	br	x17

00000000000d0d70 <_ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEEC2Ev@plt>:
   d0d70:      	adrp	x16, 0xdb000
   d0d74:      	ldr	x17, [x16, #0x890]
   d0d78:      	add	x16, x16, #0x890
   d0d7c:      	br	x17

00000000000d0d80 <abort@plt>:
   d0d80:      	adrp	x16, 0xdb000
   d0d84:      	ldr	x17, [x16, #0x898]
   d0d88:      	add	x16, x16, #0x898
   d0d8c:      	br	x17

00000000000d0d90 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEi@plt>:
   d0d90:      	adrp	x16, 0xdb000
   d0d94:      	ldr	x17, [x16, #0x8a0]
   d0d98:      	add	x16, x16, #0x8a0
   d0d9c:      	br	x17

00000000000d0da0 <fputs@plt>:
   d0da0:      	adrp	x16, 0xdb000
   d0da4:      	ldr	x17, [x16, #0x8a8]
   d0da8:      	add	x16, x16, #0x8a8
   d0dac:      	br	x17

00000000000d0db0 <fflush@plt>:
   d0db0:      	adrp	x16, 0xdb000
   d0db4:      	ldr	x17, [x16, #0x8b0]
   d0db8:      	add	x16, x16, #0x8b0
   d0dbc:      	br	x17

00000000000d0dc0 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryC1ERS3_@plt>:
   d0dc0:      	adrp	x16, 0xdb000
   d0dc4:      	ldr	x17, [x16, #0x8b8]
   d0dc8:      	add	x16, x16, #0x8b8
   d0dcc:      	br	x17

00000000000d0dd0 <_ZNKSt6__ndk18ios_base6getlocEv@plt>:
   d0dd0:      	adrp	x16, 0xdb000
   d0dd4:      	ldr	x17, [x16, #0x8c0]
   d0dd8:      	add	x16, x16, #0x8c0
   d0ddc:      	br	x17

00000000000d0de0 <_ZNKSt6__ndk16locale9use_facetERNS0_2idE@plt>:
   d0de0:      	adrp	x16, 0xdb000
   d0de4:      	ldr	x17, [x16, #0x8c8]
   d0de8:      	add	x16, x16, #0x8c8
   d0dec:      	br	x17

00000000000d0df0 <_ZNSt6__ndk16localeD1Ev@plt>:
   d0df0:      	adrp	x16, 0xdb000
   d0df4:      	ldr	x17, [x16, #0x8d0]
   d0df8:      	add	x16, x16, #0x8d0
   d0dfc:      	br	x17

00000000000d0e00 <_ZNSt6__ndk18ios_base5clearEj@plt>:
   d0e00:      	adrp	x16, 0xdb000
   d0e04:      	ldr	x17, [x16, #0x8d8]
   d0e08:      	add	x16, x16, #0x8d8
   d0e0c:      	br	x17

00000000000d0e10 <_ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEE6sentryD1Ev@plt>:
   d0e10:      	adrp	x16, 0xdb000
   d0e14:      	ldr	x17, [x16, #0x8e0]
   d0e18:      	add	x16, x16, #0x8e0
   d0e1c:      	br	x17

00000000000d0e20 <getauxval@plt>:
   d0e20:      	adrp	x16, 0xdb000
   d0e24:      	ldr	x17, [x16, #0x8e8]
   d0e28:      	add	x16, x16, #0x8e8
   d0e2c:      	br	x17

00000000000d0e30 <__system_property_get@plt>:
   d0e30:      	adrp	x16, 0xdb000
   d0e34:      	ldr	x17, [x16, #0x8f0]
   d0e38:      	add	x16, x16, #0x8f0
   d0e3c:      	br	x17
