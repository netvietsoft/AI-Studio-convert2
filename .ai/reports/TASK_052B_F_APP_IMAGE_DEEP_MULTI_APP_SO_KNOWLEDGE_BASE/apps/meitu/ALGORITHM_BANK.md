# Algorithm Bank: Meitu

## 1. Primary Engine Algorithms (Meitu)
### Domain: Hair
- **Line Integral Convolution (LIC)**: Tangent vector integration along hair orientation fields.
- **SoftLight Blending**: Pegtop formula $f(a,b) = (1-2b)a^2 + 2ba$ preserving hair highlights.

### Domain: Face
- **Barycentric Mesh Deformation**: 106/240 landmark Delaunay triangulation and local affine warp.
- **Radial Falloff Liquify**: $w(r) = (1 - (r/R)^2)^3$ for smooth deformation with zero boundary tears.

### Domain: Skin
- **Bilateral / Frequency Separation**: High/low frequency split isolating color tone from pore texture.

### Domain: Body
- **Optimized GPU Shaders**: Hardware-accelerated OpenGL ES 3.0 fragment processing.

### Domain: Reshape
- **Barycentric Mesh Deformation**: 106/240 landmark Delaunay triangulation and local affine warp.
- **Radial Falloff Liquify**: $w(r) = (1 - (r/R)^2)^3$ for smooth deformation with zero boundary tears.

### Domain: Retouch
- **Bilateral / Frequency Separation**: High/low frequency split isolating color tone from pore texture.

### Domain: Color
- **3D LUT Tetrahedral Interpolation**: Simplex decomposition of 64x64x64 color cube preventing chromatic distortion.

### Domain: Segmentation
- **MobileNet/FaceSSD/BiSeNet Segmentation**: Real-time neural alpha matting.

### Domain: Matting
- **Optimized GPU Shaders**: Hardware-accelerated OpenGL ES 3.0 fragment processing.

### Domain: Render
- **Optimized GPU Shaders**: Hardware-accelerated OpenGL ES 3.0 fragment processing.

### Domain: Video
- **Optimized GPU Shaders**: Hardware-accelerated OpenGL ES 3.0 fragment processing.

