# Đối chiếu nguồn Storytold với SO45

Phân loại: UPSTREAM_OPEN_SOURCE_REFERENCE. Đây là nguồn bên ngoài để tham khảo và so sánh; nguồn Meitu vẫn ở .ai/reconstruction/evidence. Không thay ledger, P0 hoặc cổng V4.

| Module nguồn | Chứng cứ Meitu / phạm vi | Quan hệ hiện đã xác minh |
|---|---|---|
| PhotoCraft color/src/blend.rs, soft_light_ps | RULES/REPORT/TASK_067_REPORT_R2/raw/C2.decoded.fs; APK assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs | Hai biểu thức theo kênh tương đương đại số khi A,B trong0..1. PhotoCraft clamp trước sqrt; shader Meitu mix theo uniform alpha và xuất alpha1. Parity toàn pixel, alpha, không gian màu và rounding vẫn UNKNOWN. Cả hai khác nhánh W3C với A nhỏ. |
| PhotoCraft algo/src/matting.rs | .ai/reconstruction/evidence/TASK_061/ghidra_decompiled/libMTFilterKernel.so_decompiled.txt; native blur entry0x2344e8 theo CEO receipt | Guided-filter refinement là ứng viên cùng miền xử lý mask, không phải bản khôi phục kernel blur Meitu. Input/quality/parity cần thử riêng sau Adapter P0. |
| PhotoCraft paint/src/lib.rs, ops/src/lib.rs, compose/src/lib.rs | NO_VERIFIED_COUNTERPART trong phạm vi chứng cứ đã kiểm tra; TASK063 vẫn BLOCKED | Tham khảo brush, history chia sẻ tile, layer/mask ở tầng editor. Không suy diễn đối ứng từ tên libLayerFlow. |
| LightCraft colorops/settings/LUT, FilmCraft color/LUT | NO_VERIFIED_COUNTERPART; TASK064C vẫn PLANNED | Bổ sung chỉnh màu/preset; app hiện có nativeApply3DLut. Không thay đường LUT chỉ vì trùng tên thuật toán. |
| FilmCraft edit/src/lib.rs | NO_VERIFIED_COUNTERPART; TASK064E vẫn PLANNED | Nguồn tham khảo logic timeline nếu cần video, chưa chứng minh codec/Android parity. |

Chứng cứ đã có: SHA native libMTFilterKernel.so f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4; body60b92fa0235d27cc37d088107f4ad9735fe2d2eecf15047bd36d63dc32a7d3cb. C2 decoded69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14. Kết quả Fraction mẫu A1/16,B3/4: Meitu/PhotoCraft5/32; W3C69/512; chênh11/512. Đây là kiểm đại số, không phải Android pixel benchmark.
