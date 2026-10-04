# Master Cross-App Algorithm Bank

## 1. Hair Recoloring & Directional Synthesis
- **Meitu / BeautyPlus**: 5-pass Directional LIC FBO pipeline.
  - Pass 1: BT.601 Luminance ($L = 0.298912 R + 0.586611 G + 0.114478 B$).
  - Pass 2: Double-angle structure tensor orientation field $\vec{g} = (g_x^2 - g_y^2, 2g_x g_y) / |\nabla I|^2$.
  - Pass 3-4: Separable 5-tap Gaussian blur `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]`.
  - Pass 5: Line-integral convolution along tangent vectors + Pegtop SoftLight $f(a,b)=(1-2b)a^2+2ba$.
- **Facetune**: Alpha-masked soft light with skin boundary repulsion.
- **FaceApp**: Server-side generative latent morphing.

## 2. Facial Liquify & Reshape
- **Facetune Radial Falloff**: Displacement vector $\vec{d}(p) = \vec{v} \cdot (1 - \frac{|p - c|^2}{R^2})^3$.
- **Meitu 3D Mesh Warp**: Affine transformation per Delaunay triangle guided by 106 landmarks.

## 3. Skin Smoothing & Micro-Pore Preservation
- **Frequency Separation**: $I_{high} = I - I_{low}$; apply bilateral blur to $I_{low}$, preserve $I_{high}$ pores with dynamic thresholding $\ge 75\%$.

## 4. 3D LUT Tetrahedral Color Grading
- **VSCO Tetrahedral Sampling**: Decomposes each cube voxel into 6 simplices, avoiding diagonal color tearing across color borders.
