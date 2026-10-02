# SOURCE TRACEABILITY MATRIX: P0-B.1 GENERALIZATION ENGINE

## 1. MAPPING TO PRODUCTION CODEBASE (AS-IS)
- **Face Parsing Engine:**
  - File: `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp`
  - Class: `meitu::ai::BiSeNetFaceParser`
  - Function: `parseFace19(...)` [Lines 78-158]
  - Problem: Only extracts class 17 (`Face19Class::HAIR`), completely ignoring class 18 (`HAT`), causing total hair omission on voluminous hair/buzz fade (`sample_02`, `sample_08`, `sample_10`).
  - Fallback: `fallbackGeometricParse(...)` [Lines 169-258] hardcoded exclusively for `0.jpg` with arbitrary bounding boxes (`ny <= 0.26f`, `nx >= 0.15f`).

- **Hair Matting Engine:**
  - File: `lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp`
  - Class: `meitu_native::HairMattingEngine`
  - Function: `extractHairMatte(...)` [Lines 82-140]
  - Defect: Dilates coarse semantic mask with morphological operations and box filters, leaking onto face and background. Hard-zeros ear without checking for hair strands occluding the ear.

- **Hair Dyeing Core Engine:**
  - File: `lib-core-graphics/src/main/cpp/src/hair_dye_processor.cpp`
  - Class: `meitu_native::HairDyeProcessor`
  - Function: `process(...)`
  - Kept untouched: Applied identically across Version A, B, and C to guarantee that 100% of differences stem solely from the matting alpha matte.

## 2. P0-B.1 ISOLATED MODULAR PROTOTYPE (TO-BE)
- **C++ Benchmark Harness:** `scratch/p0_b1_device_bench.cpp`
- **Modules Implemented:**
  1. `AdaptiveHairAppearance`: Computes `HairSeedStats` (Lab color distribution), removes fixed `lum < 0.44`, applies perceptual Lab Mahalanobis distance.
  2. `HairHatResolver`: Disambiguates Class 18 via adjacency, Lab Delta E, texture variance, and rigid edge metrics.
  3. `SemanticTrimapGenerator`: Separates definite core hair ($P_{hair} > 0.62$), background, and unknown band.
  4. `FastGuidedHairMatting`: Box-filter guided refinement with $2\times$ downsampling.
  5. `LocalColorAffinity`: Euclidean color contrast weighting between foreground and background seeds.
  6. `EarOcclusionResolver`: Identifies hair strands flowing over ears while protecting bare ear skin.
  7. `HairBoundaryRefiner`: Hairline cosine softening and anatomical protection.
