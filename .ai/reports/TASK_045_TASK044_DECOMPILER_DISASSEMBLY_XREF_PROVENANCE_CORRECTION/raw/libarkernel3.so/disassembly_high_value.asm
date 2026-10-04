// =============================================================================
// HIGH-VALUE DISASSEMBLY: mtlabar3::DataRequire Hair Mask Bitfield Query Logic
// Binary: libarkernel3.so (SHA-256: E08C1D494EEF98759AA92594CA26420E097DF51965A4407CC639A97BBAF35442)
// =============================================================================

// -----------------------------------------------------------------------------
// 1. mtlabar3::DataRequire::requireHairMask (0x56b70c)
// Checks bit 5 of flags byte (flags >> 5 & 1)
// -----------------------------------------------------------------------------
0x56b70c:  ldrb     w8, [x0, #4]
0x56b710:  ubfx     w0, w8, #5, #1
0x56b714:  ret      
0x56b718:  ldrb     w8, [x0, #4]

// -----------------------------------------------------------------------------
// 2. mtlabar3::DataRequire::requireHairMaskAdditionCPU (0x56b718)
// Checks bit 6 of flags byte (flags >> 6 & 1)
// -----------------------------------------------------------------------------
0x56b718:  ldrb     w8, [x0, #4]
0x56b71c:  ubfx     w0, w8, #6, #1
0x56b720:  ret      
0x56b724:  ldrb     w8, [x0, #4]

// -----------------------------------------------------------------------------
// 3. mtlabar3::DataRequire::requireHairMaskAdditionGPU (0x56b724)
// Checks bit 7 of flags byte (flags >> 7)
// -----------------------------------------------------------------------------
0x56b724:  ldrb     w8, [x0, #4]
0x56b728:  lsr      w0, w8, #7
0x56b72c:  ret      
0x56b730:  ldrb     w8, [x0, #5]

// -----------------------------------------------------------------------------
// 4. Facial Morph Control Constants (Refuting TASK_044 kFaceliftControl Conflation)
// Found in FaceliftHeadPart::SliderControlParameter:
//   • kFaceliftControl_LowerLip (.rodata 0x18d407)
//   • kFaceliftControl_RightEyeUpDown (.rodata 0x18d421)
// Proves that kFaceliftControl is facial morphing, not hair shine specular blend!
// -----------------------------------------------------------------------------
