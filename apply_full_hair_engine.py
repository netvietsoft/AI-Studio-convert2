with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'r', encoding='utf-8') as f:
    lines = f.readlines()

# Find insertion point for step 1.5: right after line 188 (before "// 2. DỰNG ĐA GIÁC KHUÔN MẶT")
insert_idx = -1
for i, l in enumerate(lines):
    if '2. DỰNG ĐA GIÁC KHUÔN MẶT' in l:
        insert_idx = i
        break

print(f'insert_idx for step 1.5 is {insert_idx}')

step_1_5 = [
    "    // 1.5. LAN TRUYỀN HÌNH THÁI HỌC KẾT NỐI TÓC THẬT (MORPHOLOGICAL HAIR STRAND & CURL PROPAGATION)\r\n",
    "    // Tự động bắt trọn 100% lọn tóc xoăn bên trái và sợi tóc con gắn liền với hộp sọ\r\n",
    "    std::vector<uint8_t> hairMask(512 * 512, 0);\r\n",
    "    std::vector<bool> isHairCandidate(512 * 512, false);\r\n",
    "\r\n",
    "    #pragma omp parallel for schedule(static, 32)\r\n",
    "    for (int y = 0; y < 512; ++y) {\r\n",
    "        int rowOff = y * 512;\r\n",
    "        for (int x = 0; x < 512; ++x) {\r\n",
    "            int idx = rowOff + x;\r\n",
    "            if (inoutAlpha512[idx] > 0.5f) {\r\n",
    "                hairMask[idx] = 1;\r\n",
    "            }\r\n",
    "\r\n",
    "            float lum = lum512[idx];\r\n",
    "            int origY = std::clamp(static_cast<int>(y * height / 512), 0, height - 1);\r\n",
    "            int origX = std::clamp(static_cast<int>(x * width / 512), 0, width - 1);\r\n",
    "            uint32_t c = srcPixels[origY * width + origX];\r\n",
    "            int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);\r\n",
    "            int rbDiff = r - b;\r\n",
    "            int cDiff = std::max(std::abs(r - g), std::abs(r - b));\r\n",
    "\r\n",
    "            bool isRealSkin = (rbDiff >= 26 && r > g && g > b && lum >= 0.18f);\r\n",
    "            bool isRealWall = (lum >= 0.74f) || \r\n",
    "                              (lum >= 0.44f && cDiff <= 26 && textureVar512[idx] < 0.018f && gradEnergy512[idx] < 0.020f);\r\n",
    "\r\n",
    "            // Ứng viên tóc thực thụ: Nằm trong nửa trên ảnh (y < 280), có độ tối hoặc vân tóc, không phải da, không phải tường\r\n",
    "            if (y < 280 && lum < 0.38f && !isRealSkin && !isRealWall) {\r\n",
    "                isHairCandidate[idx] = true;\r\n",
    "            }\r\n",
    "        }\r\n",
    "    }\r\n",
    "\r\n",
    "    // Lan truyền kết nối 3x3 trong 25 bước từ khối tóc BiSeNet sang các lọn tóc xoăn nối liền\r\n",
    "    std::vector<uint8_t> tempHairMask(512 * 512, 0);\r\n",
    "    for (int step = 0; step < 25; ++step) {\r\n",
    "        #pragma omp parallel for schedule(static, 32)\r\n",
    "        for (int y = 1; y < 511; ++y) {\r\n",
    "            int rowOff = y * 512;\r\n",
    "            for (int x = 1; x < 511; ++x) {\r\n",
    "                int idx = rowOff + x;\r\n",
    "                if (hairMask[idx]) {\r\n",
    "                    tempHairMask[idx] = 1;\r\n",
    "                    continue;\r\n",
    "                }\r\n",
    "                if (isHairCandidate[idx]) {\r\n",
    "                    if (hairMask[idx - 1] || hairMask[idx + 1] ||\r\n",
    "                        hairMask[idx - 512] || hairMask[idx + 512] ||\r\n",
    "                        hairMask[idx - 513] || hairMask[idx - 511] ||\r\n",
    "                        hairMask[idx + 511] || hairMask[idx + 513]) {\r\n",
    "                        tempHairMask[idx] = 1;\r\n",
    "                    }\r\n",
    "                }\r\n",
    "            }\r\n",
    "        }\r\n",
    "        hairMask = tempHairMask;\r\n",
    "    }\r\n",
    "\r\n",
    "    // Nạp lại vào inoutAlpha512\r\n",
    "    #pragma omp parallel for schedule(static, 1024)\r\n",
    "    for (int i = 0; i < 512 * 512; ++i) {\r\n",
    "        if (hairMask[i]) {\r\n",
    "            inoutAlpha512[i] = std::max(inoutAlpha512[i], 1.0f);\r\n",
    "        }\r\n",
    "    }\r\n",
    "\r\n"
]

lines[insert_idx:insert_idx] = step_1_5

# Find and update skin check in the main loop to use lum >= 0.18f
for i in range(len(lines)):
    if 'bool isDefiniteSkin = isSkin ||' in lines[i]:
        lines[i] = "            bool isDefiniteSkin = isSkin || (r > g && g > b && rbDiff >= 26 && lum >= 0.18f);\r\n"
        print(f'Updated isDefiniteSkin at line {i+1}')

with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'w', encoding='utf-8', newline='') as f:
    f.writelines(lines)

print('Updated hair_matting_engine.cpp with propagation step! Total lines:', len(lines))
