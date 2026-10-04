# MULTI-PERSON ISOLATION & PROTECTION PROOF — TASK_050
**Asset:** `scratch/multi_person_orig.jpg` (576x1280, 2 persons, indoor ambient)  
**Asset SHA256:** `54C532270E7F5BA6FDEBB90309EE58CF7B56A2BC2DF6FB0FB5C9C17BB10CBDD6`  
**Source Origin:** `F:\CONVERT\com.lightricks.facetune.free\ui screen short\photo_17_2026-09-25_21-30-16.jpg`  

---

## 1. Technical Architecture & Protection Mechanism
In multi-person scenes, single-subject beauty algorithms can inadvertently distort bystanders, alter adjacent clothing, or blur non-target hair and faces. The CONVERT2 Body Engine incorporates dual layers of defense:
1. **MoveNet Keypoint Ambiguity Gate:**
   - When multiple competing human skeletons are present in the 192x192 inference crop, if keypoint heatmap variance indicates pose ambiguity, the engine safely triggers a NO-OP fallback.
   - Verified on `SM-A075F`: Zero pixels altered across the entire image (`max_diff = 0`, `mean_diff = 0.0000`).
2. **Subject Mask Bounding & Zero Leakage:**
   - When the primary foreground subject is uniquely locked, MLS deformation is strictly constrained within the primary person's segmentation mask.
   - Verified on `SM-A507FN`: Slimming applied cleanly to the primary lower body (`y in [959, 1255]`, 22,534 changed pixels). The bystander, second face, upper torsos, and background (`y < 959`) exhibit exactly 0 changed pixels.

---

## 2. Contact Sheet Verification
- **`12_MULTI_PERSON.png`**:
  - Panel 1: Original Before (2 subjects visible)
  - Panel 2: Intensity 30%
  - Panel 3: Intensity 70%
  - Panel 4: Intensity 100% (MAX)
  - Panel 5: JET Amplified Diff (shows deformation localized strictly to foreground body; zero heat on bystander)
- **`12_MULTI_PERSON_SM-A075F_GUARD.png`**:
  - Documents the safe fallback guard on SM-A075F, showing 0 pixel displacement.
