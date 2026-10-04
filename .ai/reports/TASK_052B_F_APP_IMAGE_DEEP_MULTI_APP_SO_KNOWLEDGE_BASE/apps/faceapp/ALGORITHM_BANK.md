# Algorithm Bank: FaceApp

## 1. Primary Engine Algorithms (FaceApp)
### Domain: Hair
- **Line Integral Convolution (LIC)**: Tangent vector integration along hair orientation fields.
- **SoftLight Blending**: Pegtop formula $f(a,b) = (1-2b)a^2 + 2ba$ preserving hair highlights.

### Domain: Face
- **Barycentric Mesh Deformation**: 106/240 landmark Delaunay triangulation and local affine warp.
- **Radial Falloff Liquify**: $w(r) = (1 - (r/R)^2)^3$ for smooth deformation with zero boundary tears.

### Domain: Skin
- **Bilateral / Frequency Separation**: High/low frequency split isolating color tone from pore texture.

### Domain: Relight
- **Optimized GPU Shaders**: Hardware-accelerated OpenGL ES 3.0 fragment processing.

### Domain: Segmentation
- **MobileNet/FaceSSD/BiSeNet Segmentation**: Real-time neural alpha matting.

