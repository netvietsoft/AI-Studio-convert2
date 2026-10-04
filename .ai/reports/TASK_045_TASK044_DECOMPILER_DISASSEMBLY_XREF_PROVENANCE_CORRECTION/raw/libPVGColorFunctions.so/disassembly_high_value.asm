// =============================================================================
// HIGH-VALUE DISASSEMBLY: PVGColorFunctions Color Management & Profile Logic
// Binary: libPVGColorFunctions.so (SHA-256: 3AAB7535EEFD304FEF426EFD49C1FEE51300261EDC766CDC551355C3EEBB04E6)
// =============================================================================

// -----------------------------------------------------------------------------
// PVGCOLOR::PVGColorFunctions::getDisplayP3ICCProfile (0x20f70)
// Returns: const unsigned char* pointer to embedded Display-P3 ICC profile at 0xe11b
// -----------------------------------------------------------------------------
0x020f70:  nop      
0x020f74:  adr      x0, #0xe11b
0x020f78:  ret      
0x020f7c:  mov      w0, #0x218

// -----------------------------------------------------------------------------
// PVGCOLOR::PVGColorFunctions::getDisplayP3ICCProfileSize (0x20f7c)
// Returns: 0x218 (536 bytes)
// -----------------------------------------------------------------------------
0x020f7c:  mov      w0, #0x218
0x020f80:  ret      
0x020f84:  nop      
0x020f88:  adr      x0, #0xe333

// -----------------------------------------------------------------------------
// PVGCOLOR::PVGColorFunctions::getAdobeRGBICCProfile (0x20f84)
// Returns: const unsigned char* pointer to embedded AdobeRGB ICC profile at 0xe333
// -----------------------------------------------------------------------------
0x020f84:  nop      
0x020f88:  adr      x0, #0xe333
0x020f8c:  ret      
0x020f90:  mov      w0, #0x230

// -----------------------------------------------------------------------------
// PVGCOLOR::PVGColorFunctions::getAdobeRGBICCProfileSize (0x20f90)
// Returns: 0x230 (560 bytes)
// -----------------------------------------------------------------------------
0x020f90:  mov      w0, #0x230
0x020f94:  ret      
0x020f98:  stp      x29, x30, [sp, #-0x40]!
0x020f9c:  stp      x24, x23, [sp, #0x10]

// -----------------------------------------------------------------------------
// PVGCOLOR::PVGColorFunctions::getSRGBICCProfile (0x20f60)
// Returns: nullptr (sRGB is default color space; zero size at 0x20f68)
// -----------------------------------------------------------------------------
0x020f60:  mov      x0, xzr
0x020f64:  ret      
0x020f68:  mov      x0, xzr
0x020f6c:  ret      

// -----------------------------------------------------------------------------
// EMBEDDED APPLE DISPLAY-P3 ICC PROFILE HEADER (.rodata 0xe11b)
// -----------------------------------------------------------------------------
// Raw bytes (536 bytes total, magic: 'acsp'):
// Header hex: 000002186170706c040000006d6e74725247422058595a2007e6000100010000
