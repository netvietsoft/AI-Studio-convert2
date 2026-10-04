// EXPORTED & PLT DISASSEMBLY FOR libbuffer_pgl.so
// Source: F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libbuffer_pgl.so (SHA-256: D416381C202993E4A03FD6AE0C5B407F1531F61FC45F518AD5B7F4620D5A2133)
// Machine: EM_AARCH64 (64-bit Little Endian AArch64)
// Defined Symbols: 12, JNI Methods: 11


F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a\libbuffer_pgl.so:	file format elf64-littleaarch64

Disassembly of section .plt:

0000000000001820 <.plt>:
    1820:      	stp	x16, x30, [sp, #-0x10]!
    1824:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1828:      	ldr	x17, [x16, #0xb28]
    182c:      	add	x16, x16, #0xb28
    1830:      	br	x17
    1834:      	nop
    1838:      	nop
    183c:      	nop

0000000000001840 <__cxa_finalize@plt>:
    1840:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1844:      	ldr	x17, [x16, #0xb30]
    1848:      	add	x16, x16, #0xb30
    184c:      	br	x17

0000000000001850 <__cxa_atexit@plt>:
    1850:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1854:      	ldr	x17, [x16, #0xb38]
    1858:      	add	x16, x16, #0xb38
    185c:      	br	x17

0000000000001860 <open@plt>:
    1860:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1864:      	ldr	x17, [x16, #0xb40]
    1868:      	add	x16, x16, #0xb40
    186c:      	br	x17

0000000000001870 <lseek@plt>:
    1870:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1874:      	ldr	x17, [x16, #0xb48]
    1878:      	add	x16, x16, #0xb48
    187c:      	br	x17

0000000000001880 <close@plt>:
    1880:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1884:      	ldr	x17, [x16, #0xb50]
    1888:      	add	x16, x16, #0xb50
    188c:      	br	x17

0000000000001890 <ftruncate@plt>:
    1890:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1894:      	ldr	x17, [x16, #0xb58]
    1898:      	add	x16, x16, #0xb58
    189c:      	br	x17

00000000000018a0 <__errno@plt>:
    18a0:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    18a4:      	ldr	x17, [x16, #0xb60]
    18a8:      	add	x16, x16, #0xb60
    18ac:      	br	x17

00000000000018b0 <strerror@plt>:
    18b0:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    18b4:      	ldr	x17, [x16, #0xb68]
    18b8:      	add	x16, x16, #0xb68
    18bc:      	br	x17

00000000000018c0 <mmap@plt>:
    18c0:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    18c4:      	ldr	x17, [x16, #0xb70]
    18c8:      	add	x16, x16, #0xb70
    18cc:      	br	x17

00000000000018d0 <__android_log_print@plt>:
    18d0:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    18d4:      	ldr	x17, [x16, #0xb78]
    18d8:      	add	x16, x16, #0xb78
    18dc:      	br	x17

00000000000018e0 <munmap@plt>:
    18e0:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    18e4:      	ldr	x17, [x16, #0xb80]
    18e8:      	add	x16, x16, #0xb80
    18ec:      	br	x17

00000000000018f0 <msync@plt>:
    18f0:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    18f4:      	ldr	x17, [x16, #0xb88]
    18f8:      	add	x16, x16, #0xb88
    18fc:      	br	x17

0000000000001900 <calloc@plt>:
    1900:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1904:      	ldr	x17, [x16, #0xb90]
    1908:      	add	x16, x16, #0xb90
    190c:      	br	x17

0000000000001910 <__read_chk@plt>:
    1910:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1914:      	ldr	x17, [x16, #0xb98]
    1918:      	add	x16, x16, #0xb98
    191c:      	br	x17

0000000000001920 <free@plt>:
    1920:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1924:      	ldr	x17, [x16, #0xba0]
    1928:      	add	x16, x16, #0xba0
    192c:      	br	x17

0000000000001930 <write@plt>:
    1930:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1934:      	ldr	x17, [x16, #0xba8]
    1938:      	add	x16, x16, #0xba8
    193c:      	br	x17

0000000000001940 <mremap@plt>:
    1940:      	adrp	x16, 0x5000 <mremap@plt+0x36c0>
    1944:      	ldr	x17, [x16, #0xbb0]
    1948:      	add	x16, x16, #0xbb0
    194c:      	br	x17
