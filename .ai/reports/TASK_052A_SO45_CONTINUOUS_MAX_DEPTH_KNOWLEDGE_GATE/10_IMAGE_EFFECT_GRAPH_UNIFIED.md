# 10_IMAGE_EFFECT_GRAPH_UNIFIED.md — ĐỒ THỊ HIỆU ỨNG HÌNH ẢNH HỢP NHẤT (UNIFIED IMAGE EFFECT GRAPH)

**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Mã Nhiệm vụ:** `TASK_052A_SO45_CONTINUOUS_MAX_DEPTH_KNOWLEDGE_GATE_ACTIVE`  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  

---

```mermaid
flowchart TD
    subgraph UI_LAYER["TẦNG ĐIỀU KHIỂN GIAO DIỆN (UI & USER INTENT)"]
        UI_HAIR["User Chọn Màu Tóc: HairDyeItem (lutPath, opacity, softness)"]
        UI_FACE["User Tinh Chỉnh Khuôn Mặt: FaceSlender, EyeEnlarge"]
        UI_SKIN["User Làm Đẹp Da: SkinSmooth, Whitening, MicroPore Preserved"]
    end

    subgraph JNI_LAYER["CẦU NỐI JNI & NATIVE BRIDGE"]
        JNI_HAIR["MTIKHairFilter.java & EffectDenseHairDataJNI.java"]
        JNI_FACE["BeautyEngineJNI.java & MTFaceEngine.java"]
        JNI_CORE["libmeitu_reborn_native.so (Clean-Room Engine)"]
    end

    subgraph P0_HAIR_NATIVE["LÕI XỬ LÝ NHUỘM TÓC (libMTFilterKernel.so: CMTFilterSoftHair)"]
        H_PASS1["Pass 1: GrayFilterToFBO (ITU-R BT.601 Luminance)"]
        H_PASS2["Pass 2: HairMaskFilterToFBO (2D Structure Tensor & Double Angle)"]
        H_PASS3["Pass 3: BlurHFilterToFBO (Horizontal 5-Tap Gaussian Blur)"]
        H_PASS4["Pass 4: BlurVFilterToFBO (Vertical 5-Tap Gaussian Blur)"]
        H_PASS5["Pass 5: SoftHairFilterToFBO (Directional LIC + Pegtop SoftLight Composite)"]
    end

    subgraph P0_COLOR_NATIVE["LÕI PHỐI MÀU & PHÂN LỚP (libLayerFlow.so & libPVGColorFunctions.so)"]
        LF_DENSE["CLFDenseHairLayer::Render (LUT Color Transformation)"]
        PVG_HSL["PVGColorFunctions::ApplyHslAdjustments (NEON Vector Math)"]
    end

    subgraph OUTPUT["KẾT QUẢ ĐỒ HỌA ĐÍCH (FINAL RENDERING)"]
        OUT_FBO["FBO Đầu Ra Hoàn Hảo: Từng Sợi Tóc Có Chiều Sâu, Sáng Tự Nhiên, Zero Lem Trán/Tai"]
    end

    UI_HAIR --> JNI_HAIR
    UI_FACE --> JNI_FACE
    UI_SKIN --> JNI_CORE

    JNI_HAIR --> H_PASS1
    H_PASS1 --> H_PASS2
    H_PASS2 --> H_PASS3
    H_PASS3 --> H_PASS4
    H_PASS4 --> H_PASS5

    H_PASS5 --> LF_DENSE
    LF_DENSE --> PVG_HSL
    PVG_HSL --> OUT_FBO
```

---

## 2. NGUYÊN LÝ BẢO LƯU CHIỀU SÂU VI SỢI TÓC (MICRO-STRAND PRESERVATION)
Nhờ việc làm mượt dọc theo trường hướng ten-xơ góc kép thay vì làm mờ cầu đẳng hướng, năng lượng vi mô của từng lọn tóc được giữ nguyên vẹn. Khi hòa trộn bằng Pegtop SoftLight, vùng highlight giữ được độ bóng sáng tự nhiên mà không bao giờ bị bệt màu như sơn.
