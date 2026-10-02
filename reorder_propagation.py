with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'r', encoding='utf-8') as f:
    code = f.read()

# Normalize
code = code.replace('\r\n', '\n')

# 1. Remove step 1.5 from its current location
start_str = "    // 1.5. LAN TRUYỀN HÌNH THÁI HỌC KẾT NỐI TÓC THẬT"
end_str = "    // 2. DỰNG ĐA GIÁC KHUÔN MẶT"

start_idx = code.find(start_str)
end_idx = code.find(end_str)

if start_idx != -1 and end_idx != -1:
    step_1_5_text = code[start_idx:end_idx]
    code = code[:start_idx] + code[end_idx:]
    print("Extracted step 1.5 text and removed from current location")
else:
    print("Could not find step 1.5 text!")

# 2. Find insertion point right before "// 4. TIẾN TRÌNH LỌC MẶT NẠ CHUẨN XÁC TỪNG BIT"
insert_target = "    // 4. TIẾN TRÌNH LỌC MẶT NẠ CHUẨN XÁC TỪNG BIT, PIXEL (ZERO LEAKAGE & PHỦ 100% TÓC)"
target_idx = code.find(insert_target)

# Enhanced propagation with Eye/Brow zero protection
enhanced_step = """    // 3.5. LAN TRUYỀN HÌNH THÁI HỌC KẾT NỐI TÓC THẬT (MORPHOLOGICAL HAIR STRAND & CURL PROPAGATION)
    // Tự động bắt trọn 100% lọn tóc xoăn bên trái và sợi tóc con gắn liền với hộp sọ, loại trừ mắt và lông mày
    std::vector<uint8_t> hairMask(512 * 512, 0);
    std::vector<bool> isHairCandidate(512 * 512, false);

    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < 512; ++y) {
        float fy = static_cast<float>(y);
        int rowOff = y * 512;
        for (int x = 0; x < 512; ++x) {
            float fx = static_cast<float>(x);
            int idx = rowOff + x;
            if (inoutAlpha512[idx] > 0.5f) {
                hairMask[idx] = 1;
            }

            // Bảo vệ mắt và lông mày: Tuyệt đối không bao giờ là ứng viên tóc
            if (hasEyeBoxes) {
                if ((fx >= lEyeMinX - 16.0f && fx <= lEyeMaxX + 16.0f && fy >= lEyeMinY - 14.0f && fy <= lEyeMaxY + 14.0f) ||
                    (fx >= rEyeMinX - 16.0f && fx <= rEyeMaxX + 16.0f && fy >= rEyeMinY - 14.0f && fy <= rEyeMaxY + 14.0f)) {
                    continue;
                }
            }
            if (hasBrowBoxes) {
                if ((fx >= lBrowMinX - 8.0f && fx <= lBrowMaxX + 8.0f && fy >= lBrowMinY - 6.0f && fy <= lBrowMaxY + 6.0f) ||
                    (fx >= rBrowMinX - 8.0f && fx <= rBrowMaxX + 8.0f && fy >= rBrowMinY - 6.0f && fy <= rBrowMaxY + 6.0f)) {
                    continue;
                }
            }

            float lum = lum512[idx];
            int origY = std::clamp(static_cast<int>(y * height / 512), 0, height - 1);
            int origX = std::clamp(static_cast<int>(x * width / 512), 0, width - 1);
            uint32_t c = srcPixels[origY * width + origX];
            int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
            int rbDiff = r - b;
            int cDiff = std::max(std::abs(r - g), std::abs(r - b));

            bool isRealSkin = (rbDiff >= 26 && r > g && g > b && lum >= 0.18f);
            bool isRealWall = (lum >= 0.74f) || 
                              (lum >= 0.44f && cDiff <= 26 && textureVar512[idx] < 0.018f && gradEnergy512[idx] < 0.020f);

            // Ứng viên tóc thực thụ: Nằm trong nửa trên ảnh (y < 280), có độ tối hoặc vân tóc, không phải da, không phải tường
            if (y < 280 && lum < 0.38f && !isRealSkin && !isRealWall) {
                isHairCandidate[idx] = true;
            }
        }
    }

    // Lan truyền kết nối 3x3 trong 25 bước từ khối tóc BiSeNet sang các lọn tóc xoăn nối liền
    std::vector<uint8_t> tempHairMask(512 * 512, 0);
    for (int step = 0; step < 25; ++step) {
        #pragma omp parallel for schedule(static, 32)
        for (int y = 1; y < 511; ++y) {
            int rowOff = y * 512;
            for (int x = 1; x < 511; ++x) {
                int idx = rowOff + x;
                if (hairMask[idx]) {
                    tempHairMask[idx] = 1;
                    continue;
                }
                if (isHairCandidate[idx]) {
                    if (hairMask[idx - 1] || hairMask[idx + 1] ||
                        hairMask[idx - 512] || hairMask[idx + 512] ||
                        hairMask[idx - 513] || hairMask[idx - 511] ||
                        hairMask[idx + 511] || hairMask[idx + 513]) {
                        tempHairMask[idx] = 1;
                    }
                }
            }
        }
        hairMask = tempHairMask;
    }

    // Nạp lại vào inoutAlpha512
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < 512 * 512; ++i) {
        if (hairMask[i]) {
            inoutAlpha512[i] = std::max(inoutAlpha512[i], 1.0f);
        }
    }

"""

if target_idx != -1:
    code = code[:target_idx] + enhanced_step + code[target_idx:]
    print("Inserted enhanced propagation step before step 4")
else:
    print("Could not find step 4 insertion target!")

# Write back
with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'w', encoding='utf-8', newline='\r\n') as f:
    f.write(code)

print("Reordering completed successfully!")
