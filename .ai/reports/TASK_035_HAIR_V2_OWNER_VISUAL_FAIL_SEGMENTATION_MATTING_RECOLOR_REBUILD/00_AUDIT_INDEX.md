# TASK_035: HAIR V2 OWNER VISUAL FAIL REBUILD — AUDIT INDEX
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Authority:** Chairman Tony (CONVERT2_COMMAND_V2 / Autonomous Execution Master Standard)  
**Execution Lane:** `hair-v2-owner-fail-rebuild` (Runner: `GITHUB_ACTIONS_37170164992` / `CONVERT2-WINDOWS-03`)  
**Audit Date:** 2026-10-04  
**Status:** `TECHNICAL_PASS_AWAITING_OWNER_VISUAL` (Awaiting Chairman Tony's Final Visual Sign-Off)

---

## 1. Executive Summary & Problem Context
Following automated testing on Hair V2, Chairman Tony conducted visual inspection on physical test hardware and identified two critical visual failures that required an immediate, comprehensive rebuild of the hair segmentation, matting, and recoloring pipeline:

1. **Owner Failure A (`owner_evidence_0.png` / `portrait_0_curly.png`):**
   - Flat, chalky, opaque paint effect with complete loss of hair curl depth, 3D strand luminance, and micro-texture.
   - Severe pigment bleeding directly onto the subject's left forehead and temple skin, creating an unnatural painted boundary.
2. **Owner Failure B (`owner_evidence_1.png` / `owner_fail_B_orig.png`):**
   - Blonde subject wearing sheer black clothing.
   - The hair mask completely misclassified the sheer black sleeve, shoulder, and back clothing as hair, spilling vivid red dye (`RGB [85, 36, 39]`) down to the bottom of the torso/arm (`Y=181..1151`), while leaving true blonde hair uncolored.

---

## 2. Rebuilt Hair V3 Engine Architecture
Under the governing constraint to preserve V1 (`HairStrandDyeEngine`) and V2 baseline (`HairPipelineV2`) for zero-regression rollback capability, the rebuilt **Hair V3 Engine** was implemented behind a clean runtime version switch:
- `VERSION_V1 = 1`: Legacy Hair V1 (`HairStrandDyeEngine`)
- `VERSION_V2_BASELINE = 2`: Preserved Hair V2 Baseline
- `VERSION_V3_REBUILD = 3`: Rebuilt Hair V3 (Active Default)

### Core Architectural Pillars in Hair V3:
1. **Anatomical Cranial Crown Seed Extraction:**
   - Hair seeds are strictly sampled from the cranium crown above facial features (`y <= min_fy + 0.08 * face_h`, centered within skull `abs(x - face_cx) <= face_w * 0.95`).
   - Completely prevents shoulders, torso, arms, and sheer clothing from contaminating the hair appearance model.
2. **Multi-Zone Strict Protected Region Gating:**
   - 100% hard zero alpha gating on semantic non-hair classes: Face Skin (1), Eyes/Brows (2..6), Ears (7..9), Nose/Mouth (10..13), Neck (14..15), Cloth (16), Hat (18).
   - Dynamic anatomical forehead & face oval skin protection with YCbCr Cr/Cb skin tone gating.
3. **OKLab Scalp Hair Appearance & Clothing Rejection:**
   - Establishes statistical appearance model ($L, a, b$) of true scalp hair.
   - Rejects candidate hair outside cranium if color distance $\Delta E > 2.80$, or if hair is blonde/light ($L \ge 0.32$) while candidate pixel is dark sheer clothing ($L < 0.26$ or $RGB < 65$).
4. **Topological BFS Reachability:**
   - 4-connected flood fill strictly initiated from cranial scalp seeds, pruning all disconnected clothing, arm, or background artifacts.
5. **Edge-Preserving Matting:**
   - Full-resolution trimap with box-guided filter ($r=4, \epsilon=10^{-3}$) with zero-tolerance hard zero mask on skin and cloth.
6. **Physically Plausible Natural Salon Dye Transform:**
   - Hair decomposed into low-pass base illumination and high-frequency strand fibers via 7x7 spatial filter.
   - Salon melanin lift curve applied to base luminance; toner deposited with bell-curve midtone weighting ($4L(1-L)$).
   - 100% linear high-frequency strand micro-fibers injected back into composited output, guaranteeing zero chalkiness.
   - Anisotropic specular sheen glint preserved from original hair highlights.
   - Exact bit-level pass-through on intensity 0.0 and non-hair pixels.

---

## 3. Physical Test Device Deployment & Evidence
Evidence collected directly from two physical Samsung Android test devices:
- **Device 1:** Samsung Galaxy A07 (`SM-A075F`, MediaTek Helio G99 MT6789, Android 16) @ `192.168.1.18:40159`
- **Device 2:** Samsung Galaxy A50s (`SM-A507FN`, Samsung Exynos 9611, Android 11) @ `192.168.1.2:41775`

Target Package: `com.meitu.reborn`  
Native Library: `libmeitu_reborn_native.so`  
APK SHA256: Verified against target build.

---

## 4. Report Document Index
| Document | Title | Purpose |
|---|---|---|
| `00_AUDIT_INDEX.md` | Audit Index | Master index, executive summary, and governance tracking. |
| `01_OWNER_VISUAL_DEFECT_ANALYSIS.md` | Owner Visual Defect Analysis | Detailed root cause analysis of Failures A and B. |
| `02_MATTING_NATURAL_DYE_REBUILD_ARCHITECTURE.md` | Matting & Natural Dye Rebuild Architecture | Full C++ engine architectural specification. |
| `03_PHYSICAL_DEVICE_DEPLOYMENT_PROOF.md` | Physical Device Deployment Proof | Device properties, package dumps, ADB screencaps. |
| `04_A07_TEST_MATRIX_EVIDENCE.md` | SM-A075F Test Matrix Evidence | Complete 20-case test run on Galaxy A07. |
| `05_A50S_TEST_MATRIX_EVIDENCE.md` | SM-A507FN Test Matrix Evidence | Complete 20-case test run on Galaxy A50s. |
| `06_FOREHEAD_SKIN_ZERO_LEAK_PROOF.md` | Forehead Skin Zero-Leak Proof | 400% zoom crops and numerical metrics on hairline skin. |
| `07_BODY_CLOTHING_ZERO_SPILL_PROOF.md` | Body/Clothing Zero-Spill Proof | 400% zoom crops on sheer sleeve/shoulder spill elimination. |
| `08_HAIR_STRAND_DEPTH_AND_TEXTURE_PRESERVATION.md` | Texture & Strand Preservation | Laplacian edge correlation proving $\ge 88\%$ texture depth. |
| `09_NATURAL_SALON_DYE_REALISM_EVIDENCE.md` | Salon Dye Realism Evidence | Presets side-by-side (Smokey Silver, Platinum, Burgundy, etc.). |
| `10_REVERSIBILITY_AND_NEGATIVE_CONTROLS.md` | Reversibility & Negative Controls | Monk bald subject & intensity 0.0 bit-exact proof. |
| `11_RELEASE_PACKAGE_MANIFEST.md` | Release Package Manifest | File hashes, git commits, code change diffs. |
| `12_REPORT_DRIVE_MIRROR.md` | Report Drive Mirror Status | Drive sync manifest and process defect notes. |
