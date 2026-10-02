# HAIR COLOR ENGINE (HCE) — SHARED CONTRACT SPECIFICATION
**Contract Version:** `HCE_CONTRACT_V1`  
**Document:** `Docs/Architecture/HairEngine/HCE_CONTRACT_V1.md`  
**Governing Authority:** Agent 1 (Architect) & Agent 0 (CEO / Orchestrator)  
**Status:** FROZEN & IMMUTABLE (Any modification requires a formal Change Request)  
**Target Platform:** C++17 / Native Android (OpenMP + Vulkan Compute) / iOS Metal-ready  

---

## 1. Mục Đích & Nguyên Tắc Đóng Băng
Hợp đồng `HCE_CONTRACT_V1` là giao ước kỹ thuật bắt buộc giữa Phase P0 (Hair Matting đã đóng băng) và các Phase phát triển song song P1–P6.
- Mọi module P1–P6 phải tuân thủ chính xác kiểu dữ liệu, ngữ nghĩa và bất biến của hợp đồng này.
- Cấm tự ý sửa đổi struct, thêm bớt trường mà không có Change Request được Architect và Orchestrator phê duyệt.
- Mọi dữ liệu phải hỗ trợ cả xử lý CPU song song và GPU Compute Buffers.

---

## 2. Đặc Tả 10 Hợp Đồng Bắt Buộc (Contracts A -> J)

### CONTRACT A: P0 Hair Matte Adapter
- **Mục đích:** Bọc đầu ra bất biến của P0 `HairMattingEngine::extractFullSizeMatte` để cung cấp cho downstream.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct P0HairMatteAdapter {
      int width = 0;
      int height = 0;
      const float* alphaData = nullptr; // Con trỏ tới mảng W * H giá trị [0.0f, 1.0f]
      size_t strideBytes = 0;           // width * sizeof(float)
      bool isValid = false;
      
      // Vùng bao (ROI) của tóc để tối ưu dispatch
      int roiMinX = 0, roiMinY = 0;
      int roiMaxX = 0, roiMaxY = 0;
      
      // Trạng thái bảo vệ
      bool hasUiOrNonHairProtected = true;
  };
  ```
- **Bất biến:**
  - $\alpha(x, y) = 0.0f$: Vùng bảo vệ tuyệt đối (mặt, mắt, môi, tai, cổ, áo, UI). Mọi downstream engine áp dụng độ biến đổi màu = 0%.
  - $\alpha(x, y) = 1.0f$: Vùng lõi tóc chắc chắn.
  - $\alpha(x, y) \in (0.0f, 1.0f)$: Rìa chuyển tiếp sub-pixel.

---

### CONTRACT B: Hair Orientation Field (P1 Flow Field)
- **Mục đích:** Biểu diễn trường vector tiếp tuyến cục bộ của sợi tóc, đảm bảo tính tuần hoàn $\pi$ (Pi-periodic).
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairOrientationField {
      int width = 0;
      int height = 0;
      
      // Biểu diễn góc kép (doubled-angle representation):
      // vx = cos(2 * theta), vy = sin(2 * theta)
      // theta = 0.5f * atan2(vy, vx) in [-pi/2, pi/2]
      std::vector<float> dirX;       // vx(x, y) [-1.0f, 1.0f]
      std::vector<float> dirY;       // vy(x, y) [-1.0f, 1.0f]
      std::vector<float> confidence; // C(x, y) [0.0f, 1.0f] (Structure tensor coherence)
      
      bool isContinuous = true;
      bool isValid = false;
  };
  ```
- **Bất biến:**
  - Không nội suy trực tiếp góc $\theta$ để tránh lỗi wrap boundary. Mọi phép làm mịn, nội suy và upsample thực hiện trên cặp $(v_x, v_y)$.
  - Tại vùng $\alpha = 0.0f$, $dirX = 0, dirY = 0, confidence = 0$.

---

### CONTRACT C: Hair Structure / Texture Representation (P2 Texture)
- **Mục đích:** Bảo toàn và tách bạch chi tiết lọn tóc, vi sợi vi mô dọc theo trường hướng.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairTextureContext {
      int width = 0;
      int height = 0;
      
      std::vector<float> lowFreqBase;        // Ánh sáng và cấu trúc vĩ mô
      std::vector<float> highFreqDetail;     // Chi tiết sợi tóc vi mô (micro-strands)
      std::vector<float> directionalResponse;// Phản ứng lọc định hướng theo P1 flow
      std::vector<float> textureConfidence;  // Độ tin cậy kết cấu [0.0f, 1.0f]
      
      bool isValid = false;
  };
  ```
- **Bất biến:**
  - Giữ lại 100% kết cấu sợi tự nhiên ban đầu. Tuyệt đối không sinh họa tiết giả (fake procedural texture) trên toàn bộ khối tóc.

---

### CONTRACT D: Hair Appearance Context (P3 Appearance / Depth)
- **Mục đích:** Phân tách độ sáng nền, khe bóng đổ sâu (shadow crevices), và ánh sáng phản xạ để duy trì chiều sâu 3D.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairAppearanceContext {
      int width = 0;
      int height = 0;
      
      std::vector<float> baseLuminance;   // Độ sáng gốc [0.0f, 255.0f]
      std::vector<float> shadowFactor;    // Hệ số khe bóng đổ [0.0f: bóng tối sâu, 1.0f: đỉnh lọn]
      std::vector<float> highlightMask;   // Vùng ánh sáng phản xạ tự nhiên [0.0f, 1.0f]
      std::vector<float> localContrast;   // Độ tương phản cục bộ
      std::vector<float> rootDepthContext;// Chiều sâu chân tóc / da đầu
      
      bool isValid = false;
  };
  ```
- **Bất biến:**
  - Không dùng quy tắc cào bằng "pixel tối = bóng đổ". Khe bóng đổ giữa các lọn tóc xoăn/dày phải được bảo tồn để màu nhuộm không bị bệt như đổ sơn.

---

### CONTRACT E: Hair Dye Material Parameters (P4 Material)
- **Mục đích:** Định nghĩa chất liệu màu nhuộm salon theo không gian màu tri giác (Lab/OKLab), thay thế việc xoay hue HSV đơn giản.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairDyeMaterialParams {
      // Màu đích chuẩn (Target Palette)
      float targetLightness = 50.0f; // L* in OKLab/Lab [0.0f, 100.0f]
      float targetChroma = 30.0f;    // C* độ rực màu
      float targetHue = 45.0f;       // Góc sắc hue [0.0f, 360.0f]
      
      // Tham số vật lý chất nhuộm
      float bleachPower = 0.0f;      // Hệ số nâng tông / tẩy melanin [0.0f, 1.0f]
      float blendIntensity = 0.8f;   // Mức độ ăn màu [0.0f, 1.0f]
      float rootStrength = 0.9f;     // Giữ độ sẫm chân tóc [0.0f, 1.0f]
      float shadowPreservation = 0.85f;// Giữ khe bóng đổ [0.0f, 1.0f]
      float saturationLimit = 1.0f;  // Giới hạn chống gắt màu (gamut clamp)
      
      // Tùy chọn Ombre / Gradient
      float ombrePosition = 0.5f;    // Vị trí chuyển màu ngọn
      bool enableOmbre = false;
  };
  ```

---

### CONTRACT F: Hair Specular Parameters (P5 Specular)
- **Mục đích:** Mô hình phản xạ dị hướng Marschner/Kajiya-Kay chạy dọc theo sống sợi tóc.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairSpecularParams {
      float apparentShine = 0.5f;     // Cường độ bóng biểu kiến [0.0f, 1.0f]
      float roughness = 0.35f;        // Độ nhám vảy biểu bì (cuticle roughness)
      float longitudinalShift = 3.0f; // Độ dịch góc vệt sáng biểu bì (độ)
      float specularTint = 0.2f;      // Tỷ lệ màu thuốc nhuộm nhuộm vào vệt bóng
      bool preserveOriginalGlint = true;
  };
  ```

---

### CONTRACT G: Hair Render Inputs
- **Mục đích:** Gói toàn bộ dữ liệu đầu vào cần thiết cho một lượt render Hair Color Engine.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairRenderInputs {
      const uint32_t* srcPixels = nullptr; // RGBA_8888 W * H
      int width = 0;
      int height = 0;
      
      P0HairMatteAdapter p0Matte;
      HairOrientationField orientation;
      HairTextureContext texture;
      HairAppearanceContext appearance;
      HairDyeMaterialParams material;
      HairSpecularParams specular;
      
      int executionTier = 0; // 0: High-end GPU, 1: Mid-range, 2: Fallback CPU
  };
  ```

---

### CONTRACT H: Hair Render Output
- **Mục đích:** Kết quả xuất xưởng của engine sau khi đổi màu hoàn tất.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairRenderOutput {
      uint32_t* dstPixels = nullptr; // RGBA_8888 W * H
      int width = 0;
      int height = 0;
      
      bool success = false;
      float renderTimeMs = 0.0f;
      const char* backendUsed = "CPU_REFERENCE"; // "CPU_OPENMP", "GPU_VULKAN", "GPU_METAL"
  };
  ```

---

### CONTRACT I: Device / GPU Capability Contract (P6 GPU)
- **Mục đích:** Phát hiện phần cứng và lựa chọn đường ống render tối ưu.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct DeviceGpuCapability {
      bool hasVulkanCompute = false;
      bool hasMetalCompute = false;
      bool hasOpenMP = true;
      int maxComputeWorkGroupInvocations = 0;
      size_t dedicatedVideoMemoryBytes = 0;
      bool isThermalThrottled = false;
      int recommendedQualityTier = 0; // TIER_A, TIER_B, TIER_C
  };
  ```

---

### CONTRACT J: Debug / Benchmark Contract
- **Mục đích:** Xuất các artifact trung gian và thu thập số đo hiệu năng mà không rò rỉ dữ liệu nhạy cảm.
- **Cấu trúc dữ liệu C++:**
  ```cpp
  struct HairDebugArtifacts {
      bool exportIntermediateStages = false;
      std::vector<uint32_t> debugFlowOverlay;    // Vector hướng tóc phủ màu
      std::vector<uint8_t>  debugConfidenceMap;  // Bản đồ độ tin cậy
      std::vector<uint8_t>  debugShadowMap;      // Bản đồ bóng đổ
      std::vector<uint8_t>  debugSpecularMap;    // Bản đồ vệt sáng dị hướng
      
      float timeP1OrientationMs = 0.0f;
      float timeP2TextureMs = 0.0f;
      float timeP3AppearanceMs = 0.0f;
      float timeP4MaterialMs = 0.0f;
      float timeP5SpecularMs = 0.0f;
      float timeP6GpuDispatchMs = 0.0f;
      float timeTotalMs = 0.0f;
  };
  ```

---

## 3. Quy Định Chữ Ký Hàm C++ Chuẩn (Canonical C++ API Prototypes)

```cpp
namespace meitu_native::hce {

// P1: Ước lượng trường hướng sợi tóc
bool computeHairOrientationField(
    const uint32_t* srcPixels,
    const P0HairMatteAdapter& p0Matte,
    HairOrientationField& outOrientation
);

// P2: Phân tách và bảo tồn kết cấu theo trường hướng
bool extractFlowAwareTexture(
    const uint32_t* srcPixels,
    const P0HairMatteAdapter& p0Matte,
    const HairOrientationField& orientation,
    HairTextureContext& outTexture
);

// P3: Tách chi tiết ánh sáng, bóng đổ và highlight
bool extractHairAppearanceContext(
    const uint32_t* srcPixels,
    const P0HairMatteAdapter& p0Matte,
    HairAppearanceContext& outAppearance
);

// P4: Áp dụng biến đổi màu nhuộm vật lý
bool applyHairDyeMaterial(
    const uint32_t* srcPixels,
    const P0HairMatteAdapter& p0Matte,
    const HairAppearanceContext& appearance,
    const HairTextureContext& texture,
    const HairDyeMaterialParams& params,
    std::vector<uint32_t>& outRecoloredPixels
);

// P5: Tính toán phản xạ dị hướng Marschner
bool applyAnisotropicSpecular(
    const std::vector<uint32_t>& recoloredPixels,
    const P0HairMatteAdapter& p0Matte,
    const HairOrientationField& orientation,
    const HairAppearanceContext& appearance,
    const HairSpecularParams& params,
    std::vector<uint32_t>& inoutFinalPixels
);

// Pipeline Tổng Hợp (Integrated Pipeline)
bool renderHairColor(
    const HairRenderInputs& inputs,
    HairRenderOutput& output,
    HairDebugArtifacts* debugArtifacts = nullptr
);

} // namespace meitu_native::hce
```
