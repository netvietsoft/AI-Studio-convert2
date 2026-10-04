// EXPORTED & PLT DISASSEMBLY FOR libAIModelKit.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libAIModelKit.so (SHA-256: 96EB16089DA9B1B797928A73EC4B4DDD27C43BC557940C96CA167CF657A89B9C)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 351, JNI Methods: 14


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libAIModelKit.so:	file format elf64-littleaarch64

Disassembly of section .plt:

000000000003fa00 <.plt>:
   3fa00:      	stp	x16, x30, [sp, #-0x10]!
   3fa04:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa08:      	ldr	x17, [x16, #0xb40]
   3fa0c:      	add	x16, x16, #0xb40
   3fa10:      	br	x17
   3fa14:      	nop
   3fa18:      	nop
   3fa1c:      	nop

000000000003fa20 <__cxa_finalize@plt>:
   3fa20:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa24:      	ldr	x17, [x16, #0xb48]
   3fa28:      	add	x16, x16, #0xb48
   3fa2c:      	br	x17

000000000003fa30 <__cxa_atexit@plt>:
   3fa30:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa34:      	ldr	x17, [x16, #0xb50]
   3fa38:      	add	x16, x16, #0xb50
   3fa3c:      	br	x17

000000000003fa40 <__register_atfork@plt>:
   3fa40:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa44:      	ldr	x17, [x16, #0xb58]
   3fa48:      	add	x16, x16, #0xb58
   3fa4c:      	br	x17

000000000003fa50 <strncpy@plt>:
   3fa50:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa54:      	ldr	x17, [x16, #0xb60]
   3fa58:      	add	x16, x16, #0xb60
   3fa5c:      	br	x17

000000000003fa60 <strstr@plt>:
   3fa60:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa64:      	ldr	x17, [x16, #0xb68]
   3fa68:      	add	x16, x16, #0xb68
   3fa6c:      	br	x17

000000000003fa70 <_Z17loadLibraryHandlev@plt>:
   3fa70:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa74:      	ldr	x17, [x16, #0xb70]
   3fa78:      	add	x16, x16, #0xb70
   3fa7c:      	br	x17

000000000003fa80 <dlerror@plt>:
   3fa80:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa84:      	ldr	x17, [x16, #0xb78]
   3fa88:      	add	x16, x16, #0xb78
   3fa8c:      	br	x17

000000000003fa90 <__android_log_print@plt>:
   3fa90:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fa94:      	ldr	x17, [x16, #0xb80]
   3fa98:      	add	x16, x16, #0xb80
   3fa9c:      	br	x17

000000000003faa0 <__cxa_guard_acquire@plt>:
   3faa0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3faa4:      	ldr	x17, [x16, #0xb88]
   3faa8:      	add	x16, x16, #0xb88
   3faac:      	br	x17

000000000003fab0 <dlopen@plt>:
   3fab0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fab4:      	ldr	x17, [x16, #0xb90]
   3fab8:      	add	x16, x16, #0xb90
   3fabc:      	br	x17

000000000003fac0 <__cxa_guard_release@plt>:
   3fac0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fac4:      	ldr	x17, [x16, #0xb98]
   3fac8:      	add	x16, x16, #0xb98
   3facc:      	br	x17

000000000003fad0 <__cxa_guard_abort@plt>:
   3fad0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fad4:      	ldr	x17, [x16, #0xba0]
   3fad8:      	add	x16, x16, #0xba0
   3fadc:      	br	x17

000000000003fae0 <_Z20parseManisDeviceInfoPKci@plt>:
   3fae0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fae4:      	ldr	x17, [x16, #0xba8]
   3fae8:      	add	x16, x16, #0xba8
   3faec:      	br	x17

000000000003faf0 <cJSON_Parse@plt>:
   3faf0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3faf4:      	ldr	x17, [x16, #0xbb0]
   3faf8:      	add	x16, x16, #0xbb0
   3fafc:      	br	x17

000000000003fb00 <cJSON_GetObjectItem@plt>:
   3fb00:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb04:      	ldr	x17, [x16, #0xbb8]
   3fb08:      	add	x16, x16, #0xbb8
   3fb0c:      	br	x17

000000000003fb10 <cJSON_Delete@plt>:
   3fb10:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb14:      	ldr	x17, [x16, #0xbc0]
   3fb18:      	add	x16, x16, #0xbc0
   3fb1c:      	br	x17

000000000003fb20 <_Z27ensureManisDeviceInfoLoadedv@plt>:
   3fb20:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb24:      	ldr	x17, [x16, #0xbc8]
   3fb28:      	add	x16, x16, #0xbc8
   3fb2c:      	br	x17

000000000003fb30 <dlsym@plt>:
   3fb30:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb34:      	ldr	x17, [x16, #0xbd0]
   3fb38:      	add	x16, x16, #0xbd0
   3fb3c:      	br	x17

000000000003fb40 <__stack_chk_fail@plt>:
   3fb40:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb44:      	ldr	x17, [x16, #0xbd8]
   3fb48:      	add	x16, x16, #0xbd8
   3fb4c:      	br	x17

000000000003fb50 <free@plt>:
   3fb50:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb54:      	ldr	x17, [x16, #0xbe0]
   3fb58:      	add	x16, x16, #0xbe0
   3fb5c:      	br	x17

000000000003fb60 <malloc@plt>:
   3fb60:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb64:      	ldr	x17, [x16, #0xbe8]
   3fb68:      	add	x16, x16, #0xbe8
   3fb6c:      	br	x17

000000000003fb70 <strncmp@plt>:
   3fb70:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb74:      	ldr	x17, [x16, #0xbf0]
   3fb78:      	add	x16, x16, #0xbf0
   3fb7c:      	br	x17

000000000003fb80 <pow@plt>:
   3fb80:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb84:      	ldr	x17, [x16, #0xbf8]
   3fb88:      	add	x16, x16, #0xbf8
   3fb8c:      	br	x17

000000000003fb90 <memset@plt>:
   3fb90:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fb94:      	ldr	x17, [x16, #0xc00]
   3fb98:      	add	x16, x16, #0xc00
   3fb9c:      	br	x17

000000000003fba0 <strlen@plt>:
   3fba0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fba4:      	ldr	x17, [x16, #0xc08]
   3fba8:      	add	x16, x16, #0xc08
   3fbac:      	br	x17

000000000003fbb0 <strcpy@plt>:
   3fbb0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fbb4:      	ldr	x17, [x16, #0xc10]
   3fbb8:      	add	x16, x16, #0xc10
   3fbbc:      	br	x17

000000000003fbc0 <memcpy@plt>:
   3fbc0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fbc4:      	ldr	x17, [x16, #0xc18]
   3fbc8:      	add	x16, x16, #0xc18
   3fbcc:      	br	x17

000000000003fbd0 <cJSON_DetachItemFromObject@plt>:
   3fbd0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fbd4:      	ldr	x17, [x16, #0xc20]
   3fbd8:      	add	x16, x16, #0xc20
   3fbdc:      	br	x17

000000000003fbe0 <cJSON_Duplicate@plt>:
   3fbe0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fbe4:      	ldr	x17, [x16, #0xc28]
   3fbe8:      	add	x16, x16, #0xc28
   3fbec:      	br	x17

000000000003fbf0 <__vsprintf_chk@plt>:
   3fbf0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fbf4:      	ldr	x17, [x16, #0xc30]
   3fbf8:      	add	x16, x16, #0xc30
   3fbfc:      	br	x17

000000000003fc00 <__strchr_chk@plt>:
   3fc00:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc04:      	ldr	x17, [x16, #0xc38]
   3fc08:      	add	x16, x16, #0xc38
   3fc0c:      	br	x17

000000000003fc10 <__cxa_get_globals@plt>:
   3fc10:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc14:      	ldr	x17, [x16, #0xc40]
   3fc18:      	add	x16, x16, #0xc40
   3fc1c:      	br	x17

000000000003fc20 <__cxa_get_globals_fast@plt>:
   3fc20:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc24:      	ldr	x17, [x16, #0xc48]
   3fc28:      	add	x16, x16, #0xc48
   3fc2c:      	br	x17

000000000003fc30 <pthread_mutex_lock@plt>:
   3fc30:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc34:      	ldr	x17, [x16, #0xc50]
   3fc38:      	add	x16, x16, #0xc50
   3fc3c:      	br	x17

000000000003fc40 <syscall@plt>:
   3fc40:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc44:      	ldr	x17, [x16, #0xc58]
   3fc48:      	add	x16, x16, #0xc58
   3fc4c:      	br	x17

000000000003fc50 <pthread_cond_wait@plt>:
   3fc50:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc54:      	ldr	x17, [x16, #0xc60]
   3fc58:      	add	x16, x16, #0xc60
   3fc5c:      	br	x17

000000000003fc60 <pthread_mutex_unlock@plt>:
   3fc60:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc64:      	ldr	x17, [x16, #0xc68]
   3fc68:      	add	x16, x16, #0xc68
   3fc6c:      	br	x17

000000000003fc70 <pthread_cond_broadcast@plt>:
   3fc70:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc74:      	ldr	x17, [x16, #0xc70]
   3fc78:      	add	x16, x16, #0xc70
   3fc7c:      	br	x17

000000000003fc80 <__cxa_begin_catch@plt>:
   3fc80:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc84:      	ldr	x17, [x16, #0xc78]
   3fc88:      	add	x16, x16, #0xc78
   3fc8c:      	br	x17

000000000003fc90 <_ZSt9terminatev@plt>:
   3fc90:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fc94:      	ldr	x17, [x16, #0xc80]
   3fc98:      	add	x16, x16, #0xc80
   3fc9c:      	br	x17

000000000003fca0 <_ZSt14get_unexpectedv@plt>:
   3fca0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fca4:      	ldr	x17, [x16, #0xc88]
   3fca8:      	add	x16, x16, #0xc88
   3fcac:      	br	x17

000000000003fcb0 <_ZSt13get_terminatev@plt>:
   3fcb0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fcb4:      	ldr	x17, [x16, #0xc90]
   3fcb8:      	add	x16, x16, #0xc90
   3fcbc:      	br	x17

000000000003fcc0 <_ZSt15get_new_handlerv@plt>:
   3fcc0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fcc4:      	ldr	x17, [x16, #0xc98]
   3fcc8:      	add	x16, x16, #0xc98
   3fccc:      	br	x17

000000000003fcd0 <__cxa_demangle@plt>:
   3fcd0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fcd4:      	ldr	x17, [x16, #0xca0]
   3fcd8:      	add	x16, x16, #0xca0
   3fcdc:      	br	x17

000000000003fce0 <__emutls_get_address@plt>:
   3fce0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fce4:      	ldr	x17, [x16, #0xca8]
   3fce8:      	add	x16, x16, #0xca8
   3fcec:      	br	x17

000000000003fcf0 <_ZNSt9exceptionD2Ev@plt>:
   3fcf0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fcf4:      	ldr	x17, [x16, #0xcb0]
   3fcf8:      	add	x16, x16, #0xcb0
   3fcfc:      	br	x17

000000000003fd00 <_ZNSt9exceptionD1Ev@plt>:
   3fd00:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd04:      	ldr	x17, [x16, #0xcb8]
   3fd08:      	add	x16, x16, #0xcb8
   3fd0c:      	br	x17

000000000003fd10 <_ZNSt13bad_exceptionD1Ev@plt>:
   3fd10:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd14:      	ldr	x17, [x16, #0xcc0]
   3fd18:      	add	x16, x16, #0xcc0
   3fd1c:      	br	x17

000000000003fd20 <_ZNSt9bad_allocD1Ev@plt>:
   3fd20:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd24:      	ldr	x17, [x16, #0xcc8]
   3fd28:      	add	x16, x16, #0xcc8
   3fd2c:      	br	x17

000000000003fd30 <_ZNSt20bad_array_new_lengthD1Ev@plt>:
   3fd30:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd34:      	ldr	x17, [x16, #0xcd0]
   3fd38:      	add	x16, x16, #0xcd0
   3fd3c:      	br	x17

000000000003fd40 <_ZdlPv@plt>:
   3fd40:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd44:      	ldr	x17, [x16, #0xcd8]
   3fd48:      	add	x16, x16, #0xcd8
   3fd4c:      	br	x17

000000000003fd50 <_ZNSt9bad_allocC1Ev@plt>:
   3fd50:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd54:      	ldr	x17, [x16, #0xce0]
   3fd58:      	add	x16, x16, #0xce0
   3fd5c:      	br	x17

000000000003fd60 <_ZNSt9type_infoD2Ev@plt>:
   3fd60:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd64:      	ldr	x17, [x16, #0xce8]
   3fd68:      	add	x16, x16, #0xce8
   3fd6c:      	br	x17

000000000003fd70 <_ZNSt9type_infoD1Ev@plt>:
   3fd70:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd74:      	ldr	x17, [x16, #0xcf0]
   3fd78:      	add	x16, x16, #0xcf0
   3fd7c:      	br	x17

000000000003fd80 <_ZNSt8bad_castD1Ev@plt>:
   3fd80:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd84:      	ldr	x17, [x16, #0xcf8]
   3fd88:      	add	x16, x16, #0xcf8
   3fd8c:      	br	x17

000000000003fd90 <_ZNSt10bad_typeidD1Ev@plt>:
   3fd90:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fd94:      	ldr	x17, [x16, #0xd00]
   3fd98:      	add	x16, x16, #0xd00
   3fd9c:      	br	x17

000000000003fda0 <fwrite@plt>:
   3fda0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fda4:      	ldr	x17, [x16, #0xd08]
   3fda8:      	add	x16, x16, #0xd08
   3fdac:      	br	x17

000000000003fdb0 <vfprintf@plt>:
   3fdb0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fdb4:      	ldr	x17, [x16, #0xd10]
   3fdb8:      	add	x16, x16, #0xd10
   3fdbc:      	br	x17

000000000003fdc0 <fputc@plt>:
   3fdc0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fdc4:      	ldr	x17, [x16, #0xd18]
   3fdc8:      	add	x16, x16, #0xd18
   3fdcc:      	br	x17

000000000003fdd0 <vasprintf@plt>:
   3fdd0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fdd4:      	ldr	x17, [x16, #0xd20]
   3fdd8:      	add	x16, x16, #0xd20
   3fddc:      	br	x17

000000000003fde0 <android_set_abort_message@plt>:
   3fde0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fde4:      	ldr	x17, [x16, #0xd28]
   3fde8:      	add	x16, x16, #0xd28
   3fdec:      	br	x17

000000000003fdf0 <openlog@plt>:
   3fdf0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fdf4:      	ldr	x17, [x16, #0xd30]
   3fdf8:      	add	x16, x16, #0xd30
   3fdfc:      	br	x17

000000000003fe00 <syslog@plt>:
   3fe00:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe04:      	ldr	x17, [x16, #0xd38]
   3fe08:      	add	x16, x16, #0xd38
   3fe0c:      	br	x17

000000000003fe10 <closelog@plt>:
   3fe10:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe14:      	ldr	x17, [x16, #0xd40]
   3fe18:      	add	x16, x16, #0xd40
   3fe1c:      	br	x17

000000000003fe20 <abort@plt>:
   3fe20:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe24:      	ldr	x17, [x16, #0xd48]
   3fe28:      	add	x16, x16, #0xd48
   3fe2c:      	br	x17

000000000003fe30 <__dynamic_cast@plt>:
   3fe30:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe34:      	ldr	x17, [x16, #0xd50]
   3fe38:      	add	x16, x16, #0xd50
   3fe3c:      	br	x17

000000000003fe40 <strcmp@plt>:
   3fe40:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe44:      	ldr	x17, [x16, #0xd58]
   3fe48:      	add	x16, x16, #0xd58
   3fe4c:      	br	x17

000000000003fe50 <realloc@plt>:
   3fe50:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe54:      	ldr	x17, [x16, #0xd60]
   3fe58:      	add	x16, x16, #0xd60
   3fe5c:      	br	x17

000000000003fe60 <fprintf@plt>:
   3fe60:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe64:      	ldr	x17, [x16, #0xd68]
   3fe68:      	add	x16, x16, #0xd68
   3fe6c:      	br	x17

000000000003fe70 <memcmp@plt>:
   3fe70:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe74:      	ldr	x17, [x16, #0xd70]
   3fe78:      	add	x16, x16, #0xd70
   3fe7c:      	br	x17

000000000003fe80 <memmove@plt>:
   3fe80:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe84:      	ldr	x17, [x16, #0xd78]
   3fe88:      	add	x16, x16, #0xd78
   3fe8c:      	br	x17

000000000003fe90 <memchr@plt>:
   3fe90:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fe94:      	ldr	x17, [x16, #0xd80]
   3fe98:      	add	x16, x16, #0xd80
   3fe9c:      	br	x17

000000000003fea0 <snprintf@plt>:
   3fea0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fea4:      	ldr	x17, [x16, #0xd88]
   3fea8:      	add	x16, x16, #0xd88
   3feac:      	br	x17

000000000003feb0 <_Znwm@plt>:
   3feb0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3feb4:      	ldr	x17, [x16, #0xd90]
   3feb8:      	add	x16, x16, #0xd90
   3febc:      	br	x17

000000000003fec0 <_Znam@plt>:
   3fec0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fec4:      	ldr	x17, [x16, #0xd98]
   3fec8:      	add	x16, x16, #0xd98
   3fecc:      	br	x17

000000000003fed0 <__cxa_allocate_exception@plt>:
   3fed0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fed4:      	ldr	x17, [x16, #0xda0]
   3fed8:      	add	x16, x16, #0xda0
   3fedc:      	br	x17

000000000003fee0 <__cxa_throw@plt>:
   3fee0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fee4:      	ldr	x17, [x16, #0xda8]
   3fee8:      	add	x16, x16, #0xda8
   3feec:      	br	x17

000000000003fef0 <__cxa_end_catch@plt>:
   3fef0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fef4:      	ldr	x17, [x16, #0xdb0]
   3fef8:      	add	x16, x16, #0xdb0
   3fefc:      	br	x17

000000000003ff00 <_ZdaPv@plt>:
   3ff00:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff04:      	ldr	x17, [x16, #0xdb8]
   3ff08:      	add	x16, x16, #0xdb8
   3ff0c:      	br	x17

000000000003ff10 <_ZnwmSt11align_val_t@plt>:
   3ff10:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff14:      	ldr	x17, [x16, #0xdc0]
   3ff18:      	add	x16, x16, #0xdc0
   3ff1c:      	br	x17

000000000003ff20 <posix_memalign@plt>:
   3ff20:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff24:      	ldr	x17, [x16, #0xdc8]
   3ff28:      	add	x16, x16, #0xdc8
   3ff2c:      	br	x17

000000000003ff30 <_ZnamSt11align_val_t@plt>:
   3ff30:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff34:      	ldr	x17, [x16, #0xdd0]
   3ff38:      	add	x16, x16, #0xdd0
   3ff3c:      	br	x17

000000000003ff40 <_ZdlPvSt11align_val_t@plt>:
   3ff40:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff44:      	ldr	x17, [x16, #0xdd8]
   3ff48:      	add	x16, x16, #0xdd8
   3ff4c:      	br	x17

000000000003ff50 <_ZdaPvSt11align_val_t@plt>:
   3ff50:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff54:      	ldr	x17, [x16, #0xde0]
   3ff58:      	add	x16, x16, #0xde0
   3ff5c:      	br	x17

000000000003ff60 <__cxa_rethrow@plt>:
   3ff60:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff64:      	ldr	x17, [x16, #0xde8]
   3ff68:      	add	x16, x16, #0xde8
   3ff6c:      	br	x17

000000000003ff70 <__assert2@plt>:
   3ff70:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff74:      	ldr	x17, [x16, #0xdf0]
   3ff78:      	add	x16, x16, #0xdf0
   3ff7c:      	br	x17

000000000003ff80 <pthread_getspecific@plt>:
   3ff80:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff84:      	ldr	x17, [x16, #0xdf8]
   3ff88:      	add	x16, x16, #0xdf8
   3ff8c:      	br	x17

000000000003ff90 <pthread_once@plt>:
   3ff90:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ff94:      	ldr	x17, [x16, #0xe00]
   3ff98:      	add	x16, x16, #0xe00
   3ff9c:      	br	x17

000000000003ffa0 <pthread_setspecific@plt>:
   3ffa0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ffa4:      	ldr	x17, [x16, #0xe08]
   3ffa8:      	add	x16, x16, #0xe08
   3ffac:      	br	x17

000000000003ffb0 <pthread_key_delete@plt>:
   3ffb0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ffb4:      	ldr	x17, [x16, #0xe10]
   3ffb8:      	add	x16, x16, #0xe10
   3ffbc:      	br	x17

000000000003ffc0 <pthread_key_create@plt>:
   3ffc0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ffc4:      	ldr	x17, [x16, #0xe18]
   3ffc8:      	add	x16, x16, #0xe18
   3ffcc:      	br	x17

000000000003ffd0 <getauxval@plt>:
   3ffd0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ffd4:      	ldr	x17, [x16, #0xe20]
   3ffd8:      	add	x16, x16, #0xe20
   3ffdc:      	br	x17

000000000003ffe0 <__system_property_get@plt>:
   3ffe0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3ffe4:      	ldr	x17, [x16, #0xe28]
   3ffe8:      	add	x16, x16, #0xe28
   3ffec:      	br	x17

000000000003fff0 <fflush@plt>:
   3fff0:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   3fff4:      	ldr	x17, [x16, #0xe30]
   3fff8:      	add	x16, x16, #0xe30
   3fffc:      	br	x17

0000000000040000 <pthread_rwlock_wrlock@plt>:
   40000:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   40004:      	ldr	x17, [x16, #0xe38]
   40008:      	add	x16, x16, #0xe38
   4000c:      	br	x17

0000000000040010 <pthread_rwlock_unlock@plt>:
   40010:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   40014:      	ldr	x17, [x16, #0xe40]
   40018:      	add	x16, x16, #0xe40
   4001c:      	br	x17

0000000000040020 <dl_iterate_phdr@plt>:
   40020:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   40024:      	ldr	x17, [x16, #0xe48]
   40028:      	add	x16, x16, #0xe48
   4002c:      	br	x17

0000000000040030 <pthread_rwlock_rdlock@plt>:
   40030:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   40034:      	ldr	x17, [x16, #0xe50]
   40038:      	add	x16, x16, #0xe50
   4003c:      	br	x17

0000000000040040 <getpid@plt>:
   40040:      	adrp	x16, 0x47000 <_ZTISt10bad_typeid+0x2290>
   40044:      	ldr	x17, [x16, #0xe58]
   40048:      	add	x16, x16, #0xe58
   4004c:      	br	x17
