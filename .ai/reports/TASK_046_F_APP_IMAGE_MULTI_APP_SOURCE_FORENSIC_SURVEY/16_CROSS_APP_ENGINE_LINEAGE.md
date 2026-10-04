# BÁO CÁO 16: PHẢ HỆ VÀ CỤM CÔNG NGHỆ (CROSS-APP ENGINE LINEAGE)
## DỰ ÁN: CONVERT2 — TECHNICAL BENCHMARK & RECONSTRUCTION STUDY

---

## 1. PHÂN CỤM PHẢ HỆ ĐỘC QUYỀN

Qua phân tích mã máy, bảng biểu tượng JNI và chữ ký tệp tin, 14 ứng dụng khảo sát phân tách rõ rệt thành 5 cụm phả hệ công nghệ chính:

```mermaid
graph TD
    subgraph Cluster1["CỤM 1: MEITU DYNASTY (ĐẾ CHẾ MEITU)"]
        MT["Meitu (com.mt.mtxx.mtxx)"] --- BP["BeautyPlus (com.commsource.beautyplus)"]
        MT --- WK["Wink (com.meitu.wink)"]
        MT --> Core1["Lõi Chung: ARKernel3, MTFilterKernel, Manis AI, 3DFace, LayerFlow"]
    end

    subgraph Cluster2["CỤM 2: BYTEDANCE ECOSYSTEM (HỆ SINH THÁI TIKTOK)"]
        UL["Ulike (com.gorgeous.lite)"] --- SE["SnapEdit (snapedit.app.remove)"]
        UL --> Core2["Lõi Chung: ByteDance EffectSDK, AGFX Engine, Xeno Engine, ByteVC1"]
    end

    subgraph Cluster3["CỤM 3: SENSETIME ECOSYSTEM (AR CHÂU Á)"]
        B612["B612 (com.linecorp.b612.android)"] --> Core3["Lõi Chung: SenseTime SenseME SDK, Lưới 3D 2,396 điểm, PGL Buffer"]
    end

    subgraph Cluster4["CỤM 4: WESTERN COMPUTATIONAL PHOTOGRAPHY (ÂU MỸ)"]
        FT["Facetune (Lightricks)"] --- VSCO["VSCO (Visual Supply Co)"]
        FT --- REM["Remini (Bending Spoons)"]
        FT --- FA["FaceApp (FaceApp Ltd)"]
        FT --> Core4["Đặc Trưng: 3DMM Tensors, Rust UniFFI, ONNX Edge, GLES 3.0 3D LUT"]
    end

    subgraph Cluster5["CỤM 5: TIỆN ÍCH CHUYÊN BIỆT"]
        TW["Time Warp Scan (com.video.timewarp)"]
        FUT["Future Self Aging"]
        UP["Uptodown Container"]
    end
```

---

## 2. BẢNG ĐỐI SOÁT TÁI SỬ DỤNG VÀ DẪN XUẤT CÔNG NGHỆ

| Thành Phần Công Nghệ | Ứng Dụng Xuất Hiện | Mức Độ Trùng Khớp Kỹ Thuật | Đánh Giá Tái Sử Dụng |
| :--- | :--- | :--- | :--- |
| **ARKernel / MTFilterKernel** | Meitu, BeautyPlus, Wink | 100% Cấu trúc nhị phân C++ gốc từ Meitu Xiamen | **CHUẨN MỰC THAM CHIẾU TỐI CAO CHO CONVERT2** |
| **Xeno Engine** | Facetune, SnapEdit | SnapEdit mua license thương mại bộ engine render của ByteDance (cùng gốc Xeno) | **THAM KHẢO KIẾN TRÚC RENDER GRAPH** |
| **SenseME AR SDK** | B612, SNOW | Thư viện thương mại đóng gói từ SenseTime Group | **THAM KHẢO BỘ DỮ LIỆU ĐIỂM MỐC 2,396 ĐỈNH** |
| **ONNX Runtime + NMS C++** | Remini | Bộ mã nguồn mở Microsoft ONNX + thuật toán C++ NMS tối ưu | **ỨNG DỤNG CHO ON-DEVICE AI INFERENCE** |
| **Rust UniFFI Core** | VSCO | Lõi tính toán bằng ngôn ngữ Rust kết nối Kotlin | **MẪU HÌNH VỀ ĐỘ CHÍNH XÁC ĐA NỀN TẢNG** |
