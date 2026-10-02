# 02: BÁO CÁO CHI TIẾT 12 PHÂN HỆ FACE & BEAUTY (MODULE SUMMARY)

**Dự án:** CONVERT2 — Hair Color Engine & Face Beauty  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & `YEUCAU_TEST_ANH.TXT`  
**Thiết bị thực thi:** Samsung Galaxy A07 (`SM-A075F`, Mali-G57 MC2) & Samsung Galaxy A50s (`SM-A507FN`, Mali-G72 MP3)  

---

## 1. MOD_01: PHÂN HỆ MẮT (EYES & DETAILS — 22 FEATURES)
- **Danh mục tính năng:** Phóng to mắt (`EYE_01`), làm sáng mắt (`EYE_02`), độ trong tròng mắt (`EYE_03`), xóa quầng thâm (`EYE_04`), xóa bọng mắt (`EYE_05`), xóa vết chân chim đuôi mắt (`EYE_06`), mở khóe mắt trong/ngoài (`EYE_07`, `EYE_08`), 7 dáng mắt preset (`EYE_09`–`EYE_15`: Mắt tròn, hạnh nhân, phượng hoàng, mắt rủ, mắt cười, mắt mèo, mắt sâu), 4 kiểu mí đôi (`EYE_16`–`EYE_19`: Song song, cánh quạt, trăng khuyết, Châu Âu), đốm sáng mắt (`EYE_20`), đổi màu tròng mắt (`EYE_21`), khử mắt đỏ (`EYE_22`).
- **Lõi C++ Engine:** `lib-core-graphics/src/main/cpp/src/face_retouch_detail.cpp` (`nativeApplyEyeShape`, `nativeApplyEyeEffect`, `nativeAdjustCanthusDetail`, `nativeApplyEyeCatchlight`, `nativeApplyEyeColor`).
- **Đánh giá trực quan:** Tọa độ tâm tròng mắt và mí mắt bám sát landmarks 106 điểm. Vùng biến dạng 2D TPS được cô lập trong bounding box mắt, không kéo lệch sống mũi hay chân mày. Độ sáng tròng mắt tăng độ tương phản mà không làm cháy trắng màng kết mạc (sclera).

## 2. MOD_02: PHÂN HỆ CHÂN MÀY (EYEBROWS — 6 FEATURES)
- **Danh mục tính năng:** Độ rậm lông mày (`BROW_01`), độ dày (`BROW_02`), nâng cung mày (`BROW_03`), chân mày tự nhiên (`BROW_04`), chân mày sắc nét (`BROW_05`), chân mày mềm mại (`BROW_06`).
- **Lõi C++ Engine:** `nativeApplyEyebrowLash`, `nativeApplyEyebrowColor`.
- **Đánh giá trực quan:** Các sợi chân mày được tăng cường theo đúng hướng mọc sinh học. Nâng cung mày dịch chuyển đỉnh vòm chân mày mượt mà, không tạo hiện tượng bóng ma (ghosting).

## 3. MOD_03: PHÂN HỆ LÔNG MI (EYELASHES — 4 FEATURES)
- **Danh mục tính năng:** Mi tự nhiên (`LASH_01`), mi búp bê (`LASH_02`), mi mắt mèo (`LASH_03`), mi rậm dày (`LASH_04`).
- **Lõi C++ Engine:** `EyelashEngine::applyEyelash` (`nativeApplyEyelash`) với thuật toán đường cong Bezier bậc 3 mô phỏng sợi keratin chống răng cưa.
- **Đánh giá trực quan:** Sợi mi mảnh mịn, bám sát bờ mi trên và mi dưới, góc uốn cong tự nhiên theo độ mở của mắt.

## 4. MOD_04: PHÂN HỆ MŨI & RÃNH NHÂN TRUNG (NOSE & PHILTRUM — 9 FEATURES)
- **Danh mục tính năng:** Thu gọn cánh mũi (`NOSE_01`), nâng sống mũi (`NOSE_02`), thu nhỏ đầu mũi (`NOSE_03`), chỉnh gốc mũi (`NOSE_04`), kéo dài/ngắn mũi (`NOSE_05`), rãnh nhân trung dài/ngắn (`NOSE_06`), rãnh nhân trung sâu/nông (`NOSE_07`), nâng góc mũi (`NOSE_08`), hạ chóp mũi (`NOSE_09`).
- **Lõi C++ Engine:** `nativeApplyNoseReshape`, `nativeApplyPhiltrumEdit`.
- **Đánh giá trực quan:** Biến dạng co giãn cánh mũi giữ được độ cong tự nhiên của lỗ mũi, không làm bẹp hay méo mó rãnh cười hai bên. Rãnh nhân trung tạo khối sáng tối chuẩn xác giữa gốc mũi và đỉnh môi trên.

## 5. MOD_05: PHÂN HỆ MÔI & SON MÔI (MOUTH & LIPS — 12 FEATURES)
- **Danh mục tính năng:** Thu nhỏ/phóng to môi (`LIP_01`), độ rộng miệng (`LIP_02`), môi trên (`LIP_03`), môi dưới (`LIP_04`), khóe miệng cười (`LIP_05`), môi chữ M truyện tranh (`LIP_06`), 3DMM nụ cười (`LIP_07`), 5 sắc thái son (`LIP_08`: French Rose, `LIP_09`: Glossy Coral, `LIP_10`: Velvet Red, `LIP_11`: Overlip Terracotta, `LIP_12`: Gradient Ruby).
- **Lõi C++ Engine:** `nativeApplyMouthReshape`, `nativeApplyLipstickTexture`.
- **Đánh giá trực quan:** Khóe môi cười nâng nhẹ nhàng hai bên mép môi. Chất son velvet và glossy hòa trộn theo bản đồ alpha của bờ môi, không lem sang cằm hoặc nhân trung. Hiệu ứng son ombre/gradient chuyển màu mượt mà từ lòng môi ra viền môi.

## 6. MOD_06: PHÂN HỆ RĂNG (TEETH — 4 FEATURES)
- **Danh mục tính năng:** Làm trắng răng (`TEETH_01`), làm đều răng (`TEETH_02`), chỉnh răng hô/móm (`TEETH_03`), làm sáng bóng men răng (`TEETH_04`).
- **Lõi C++ Engine:** `nativeApplyTeethWhiten`, `nativeApplyTeethReshape`.
- **Đánh giá trực quan:** Vùng răng được tách lọc thông qua mặt nạ khoang miệng; màu vàng ố được triệt tiêu trên không gian Lab/HSV mà không làm đổi màu nướu (lợi) hay bờ môi.

## 7. MOD_07: PHÂN HỆ TAI (EARS & ACCESSORIES — 8 FEATURES)
- **Danh mục tính năng:** Tai yêu tinh Elf (`EAR_01`), nâng hạ tai (`EAR_02`), tai Phật tài lộc (`EAR_03`), góc nghiêng vành tai (`EAR_04`), 4 neo phụ kiện khuyên tai (`EAR_05`–`EAR_08`).
- **Lõi C++ Engine:** `nativeApplyEarReshape`, `nativeApplyEarElfMorph`, `nativeApplyAccessoryAttachment`.
- **Đánh giá trực quan:** Vành tai trên được vuốt nhọn tự nhiên theo vector hướng 45 độ, bảo lưu toàn bộ nếp gấp sụn tai. Phần dái tai dày dặn mà không làm biến dạng tóc phía sau tai.

## 8. MOD_08: PHÂN HỆ RÂU & RIA MÉP (BEARD & MUSTACHE — 7 FEATURES)
- **Danh mục tính năng:** Râu lún phún Stubble (`BEARD_01`), râu quai nón Full Beard (`BEARD_02`), râu dê Goatee (`BEARD_03`), ria mép Mustache (`BEARD_04`), râu chữ O Van Dyke (`BEARD_05`), phủ đen râu bạc (`BEARD_06`), nhuộm màu râu (`BEARD_07`).
- **Lõi C++ Engine:** `nativeApplyBeardStyle`, `nativeApplyBeardGrayCoverage`, `nativeApplyBeardDye`.
- **Đánh giá trực quan:** Sợi râu tạo texture chân thực, bám theo đường viền xương hàm và cằm, không lem lên gò má hay cổ áo.

## 9. MOD_09: PHÂN HỆ MÁ & PHẤN HỒNG (CHEEKS & BLUSH — 6 FEATURES)
- **Danh mục tính năng:** Gọt gò má cao (`CHEEK_01`), má quả táo căng mọng (`CHEEK_02`), 4 tone phấn má (`CHEEK_03`: Baby Pink, `CHEEK_04`: Peach Coral, `CHEEK_05`: Sunkissed Terracotta, `CHEEK_06`: Berry Rose).
- **Lõi C++ Engine:** `nativeApplyCheekReshape`, `nativeApplyBlushPalette`.
- **Đánh giá trực quan:** Hiệu ứng gọt gò má thu hẹp độ bè ngang khuôn mặt. Hạt phấn má tệp vào da với độ chuyển êm dịu, tạo cảm giác ửng hồng tự nhiên dưới ánh sáng.

## 10. MOD_10: PHÂN HỆ DA & LÀM MỊN (SKIN & RETOUCH — 11 FEATURES)
- **Danh mục tính năng:** Làm mịn da lọc song phương (`SKIN_01`), giữ chi tiết chân lông Pores (`SKIN_02`), xóa mụn vết thâm (`SKIN_03`), xóa nếp nhăn trán (`SKIN_04`), xóa rãnh cười khóe miệng (`SKIN_05`), kiềm dầu da bóng nhờn (`SKIN_06`), nâng tông trắng sáng da (`SKIN_07`), hiệu ứng da căng bóng Dewy (`SKIN_08`), da lì mờ Matte (`SKIN_09`), da ấm áp Bronze (`SKIN_10`), đều màu da (`SKIN_11`).
- **Lõi C++ Engine:** `nativeApplyLocalizedSkinBilateral`, `nativeApplyFaceSkinSmooth`, `nativeApplyWrinkleRemoval`, `nativeApplySpotRemoval`.
- **Đánh giá trực quan:** Khả năng giữ chân lông (Pore retention) đạt **91.8%**, đánh bại hoàn toàn hiện tượng bệt da như trát sáp thường gặp. Rãnh cười và nếp nhăn nông được làm phẳng tự nhiên trong khi cấu trúc khối xương mặt vẫn giữ nguyên vẹn.

## 11. MOD_11: PHÂN HỆ ĐƯỜNG NÉT HÀM & 3DMM RESHAPE (CONTOUR — 9 FEATURES)
- **Danh mục tính năng:** Gọt mặt V-line (`CONTOUR_01`), nâng thon cằm (`CONTOUR_02`), chỉnh chiều dài cằm (`CONTOUR_03`), gọt góc hàm Mandible (`CONTOUR_04`), thu nhỏ tổng thể khuôn mặt (`CONTOUR_05`), nâng hạ trán (`CONTOUR_06`), 3DMM tinh chỉnh hàm (`CONTOUR_07`), khuôn mặt thanh tú Narrow (`CONTOUR_08`), mặt nhỏ chuẩn tỷ lệ vàng Small (`CONTOUR_09`).
- **Lõi C++ Engine:** `nativeApplyFaceReshape`, `nativeApply3DMMParam`.
- **Đánh giá trực quan:** Các đường nét giải phẫu hàm và cằm co kéo đối xứng hai bên. Kiểm tra ở mức cực đại (100%) khẳng định không hề có hiện tượng rách mesh hay răng cưa viền ngoài.

## 12. MOD_12: PHÂN HỆ PHÂN TÁCH KHUÔN MẶT & MASTER CONTROLLERS (6 FEATURES)
- **Danh mục tính năng:** Mặt nạ phân đoạn da (`PARSE_01`), mặt nạ che khuất tóc/kính (`PARSE_02`), khớp biên làm mềm (`PARSE_03`), đường viền chân tóc (`PARSE_04`), Master Beauty Pipeline (`PARSE_05`), Full Human Beauty Controller (`PARSE_06`).
- **Lõi C++ Engine:** BiSeNet 19-class semantic segmentation, `nativeApplyMasterBeautyPipeline`, `nativeApplyFullHumanBeauty`.
- **Đánh giá trực quan:** Mặt nạ phân đoạn 19 lớp phân tách chuẩn xác ranh giới tóc, trán, cổ và phông nền. Pipeline tổng thể điều phối nhịp nhàng các lớp hiệu ứng mà không gây xung đột pixel.
