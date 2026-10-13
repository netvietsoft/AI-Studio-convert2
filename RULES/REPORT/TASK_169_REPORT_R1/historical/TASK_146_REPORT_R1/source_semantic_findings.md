# TASK_146 R1 source-only findings

- **L1 OBSERVED**: The selected JNI hair-clean-alpha get/set bodies each have two source instructions: load or store the double register d0 at the pointer in x2, then return.
  - Limits: These two bodies contain no clamp or validity check; caller-side validation, pointer meaning, and range are unknown.

- **L2 OBSERVED**: CLFDenseHairProcessor::needFace is a two-instruction constant-one return body in this SO.
  - Limits: This specific method does not establish overall face-dependency behavior in external modules.

- **L3 OBSERVED**: The 12,980-byte CLFDenseHairProcessor::applyLayer body decodes to 3,245 AArch64 instructions and includes source/PLT/GOT/relocation-backed calls to hair mask, dye material/alpha, hair effect, AI request, and renderer methods.
  - Limits: Callsite presence does not prove branch execution, parameter meanings, GPU formula, or pixels. Thirty indirect call targets remain unresolved in this body.

- **L4 BLOCKED_INPUT**: libmtImageKit.so is DT_NEEDED but absent from the current SO45 directory; selected CMTIKHairFilter calls are undefined imports in libLayerFlow.so.
  - Limits: Absence is limited to this 45-SO input set; the provider may exist in another original distribution.
