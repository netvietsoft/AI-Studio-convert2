# TASK_038 — HAIR SHADER PASS & MATHEMATICS RECONSTRUCTION

## 1. Pass Sequence
1. **Pass 1 (Luminance Extraction):** `GrayFilterToFBO` extracts base strand luminosity.
   $$Y = 0.299 \cdot R + 0.587 \cdot G + 0.114 \cdot B$$

2. **Pass 2 & 3 (Separated Gaussian Blur):** `BlurH` (horizontal) and `BlurV` (vertical) 5-point kernel.
   - Kernel weights: `[0.06136, 0.24477, 0.38774, 0.24477, 0.06136]`

3. **Pass 4 (Photoshop Soft Light Blending):** `MTFilter_PsSoftLightr.fs`
   $$C_\text{out} = \begin{cases} 2AB + A^2(1 - 2B) & \text{if } B \le 0.5 \\ 2A(1-B) + \sqrt{A}(2B - 1) & \text{if } B > 0.5 \end{cases}$$

4. **Pass 5 (Hair Shine & Gloss Composite):** `MakeupHairSoftPart`
   $$C_\text{final} = C_\text{out} \cdot (1 - \text{gloss}) + \text{specular} \cdot \text{gloss}$$
