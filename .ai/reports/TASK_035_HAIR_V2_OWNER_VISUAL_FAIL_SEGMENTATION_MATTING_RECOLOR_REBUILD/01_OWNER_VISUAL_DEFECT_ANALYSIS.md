# 01. OWNER VISUAL DEFECT ANALYSIS
**Task ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_SEGMENTATION_MATTING_NATURAL_RECOLOR_REBUILD_ACTIVE`  
**Command ID:** `TASK_035_HAIR_V2_OWNER_VISUAL_FAIL_REBUILD_20261004T090300+0700`  
**Reference Document:** [Google Docs Task Specification](https://docs.google.com/document/d/1mZEHQORjr3wPQlNXJTOjtrYUSGbWUgdfxyPf9lGGxjs/edit?usp=drivesdk)

---

## 1. Background & Owner Visual Rejection
During previous test cycles, automated synthetic metric suites produced passing numbers by comparing against loose thresholds. However, upon manual visual inspection on physical Samsung Galaxy test devices, Chairman Tony identified severe, unacceptable visual defects that compromised production quality.

Chairman Tony delivered authoritative ground truth through two visual evidence records:
- `owner_evidence_0.png` (Portrait A: Male curly hair recolor failure)
- `owner_evidence_1.png` (Portrait B: Blonde female in black sheer clothing recolor failure)

---

## 2. Failure Case A: Flat Chalky Paint & Forehead Pigment Bleed (`owner_evidence_0.png`)

### Visual Symptoms:
1. **Loss of 3D Strand Depth & Texture:**
   - The recolored hair appeared as a solid, opaque, chalky gray helmet.
   - Individual curl definition, micro-luminance variations, highlights, and shadow crevices were completely crushed.
2. **Forehead & Hairline Pigment Leakage:**
   - The gray hair pigment bled across the anatomical hairline onto the left temple and forehead skin.
   - The boundary between hair and skin was sharp, harsh, and painted, completely lacking natural root transition and flyaway semi-transparency.

### Root Cause Analysis:
1. **Aggressive Direct OKLab Target Assignment:**
   - The legacy recoloring algorithm attempted to replace the pixel luminance $L$ directly towards the target hair color luminance, destroying the high-frequency spatial variation that creates the perception of individual strands.
2. **Absence of Melanin Lift / Illumination Decomposition:**
   - In real-world salon bleaching and dyeing, the melanin in the hair cortex is lifted, but the specular reflection from hair cuticles and ambient illumination remains. Legacy code treated hair as a Lambertian flat surface with uniform albedo.
3. **Forehead Skin False Positives in Coarse Segmentation:**
   - BiSeNet's 512x512 coarse segmentation map has edge uncertainty around curly wisps. When upsampled to original resolution (e.g. 960x1280), forehead skin pixels in the shadow of curls were classified as hair (label 17) with non-zero probability.
   - The matting stage lacked strict anatomical face oval skin protection, allowing pigment deposition directly into pore-bearing skin regions.

---

## 3. Failure Case B: Sheer Clothing Misclassification & Dye Spill (`owner_evidence_1.png`)

### Visual Symptoms:
1. **Massive Dye Spill on Black Sheer Clothing:**
   - The subject is a blonde woman wearing a black sheer/lace blouse.
   - The hair mask erroneously identified the entire sheer black sleeve, left shoulder, chest fabric, and lower back as hair.
   - Vivid red/burgundy dye (`RGB [85, 36, 39]`) was deposited over the clothing down to the bottom of the torso and sleeve (`Y=180..1151`), creating a grotesque red cowl/hood effect over clothing.
2. **Zero Coloration of Actual Blonde Hair:**
   - The actual blonde hair in the front and right side received virtually no recolor, because the model's appearance statistics were overwhelmed by the dark fabric pixels.

### Root Cause Analysis:
1. **BiSeNet Class 17 Confusion on Dark Textured Fabric:**
   - BiSeNet was trained on datasets where dark textured regions frequently correlate with dark female hair. Sheer black lace over skin produced high-frequency dark patterns that BiSeNet misclassified as hair (class 17) rather than clothing (class 16).
2. **Unconstrained Hair Seed Collection:**
   - The previous seed collection sampled hair pixels from anywhere above `chin_y + 0.12 * face_h`. In profile/three-quarter poses, the subject's shoulder and sleeve are physically positioned at or above chin level ($Y=180..450$).
   - The seed collector ingested tens of thousands of black clothing pixels alongside blonde hair pixels, corrupting the appearance model (`mean_hL` dropped from 0.57 to 0.30, and `sigmaL` inflated to 0.35).
3. **Failure to Gate Clothing Outside Cranial Crown:**
   - The candidate validation check was previously restricted to `belowChin`. Pixels on the shoulder and upper chest above chin level bypassed color validation entirely.
   - The sheer black sleeve pixels, having entered the hair candidate set, formed a continuous path that connected into the hair mask and flood-filled down the entire arm.

---

## 4. Rebuild Directives & Success Criteria
To address both root causes with absolute precision:
1. **Scalp Cranial Crown Anchor:** Hair seeds must be extracted exclusively from the cranium crown above facial features (`y <= min_fy + 0.08 * face_h`, horizontally centered within `abs(x - face_cx) <= face_w * 0.95`).
2. **Strict Color Consistency & Sheer Rejection:** Any candidate hair pixel outside the cranial crown must match the scalp appearance model. For blonde/light hair ($L \ge 0.32$), dark sheer clothing ($L < 0.26$ or $RGB < 65$) must be rejected immediately.
3. **Multi-Zone Strict Protected Region Gate:** Semantic classes 1..15, 16 (Cloth), and 18 (Hat), along with dynamic forehead skin gating, must have hard zero alpha.
4. **Physically Plausible Salon Dye:** Hair must be decomposed into low-pass base illumination and high-frequency strand fibers (7x7 box filter). 100% of original strand fibers must be linearly re-injected into the output.
