with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'r', encoding='utf-8') as f:
    lines = f.readlines()

# 1. Update lines around 107-133 to always run hair_matting_mobile ensemble
start_idx = -1
end_idx = -1
for i, l in enumerate(lines):
    if 'ƯU TIÊN 2' in l:
        start_idx = i
    if start_idx != -1 and 'applySubpixelGuidedRefinement' in l:
        end_idx = i
        break

print(f'Replacing lines {start_idx} to {end_idx}')

ensemble_code = [
    "    // ƯU TIÊN 2: NCNN Hair Matting Mobile chuyên dụng (Ensemble tăng cường bao trọn 100% sợi tóc và lọn xoăn)\r\n",
    "    if (mInitialized && mNet) {\r\n",
    "        ncnn::Mat inMat = ncnn::Mat::from_pixels_resize(\r\n",
    "            reinterpret_cast<const unsigned char*>(pixels),\r\n",
    "            ncnn::Mat::PIXEL_RGBA2RGB,\r\n",
    "            width, height, 512, 512\r\n",
    "        );\r\n",
    "\r\n",
    "        const float mean_vals[3] = {127.5f, 127.5f, 127.5f};\r\n",
    "        const float norm_vals[3] = {1.0f / 127.5f, 1.0f / 127.5f, 1.0f / 127.5f};\r\n",
    "        inMat.substract_mean_normalize(mean_vals, norm_vals);\r\n",
    "\r\n",
    "        ncnn::Extractor ex = mNet->create_extractor();\r\n",
    "        ex.input(\"data\", inMat);\r\n",
    "\r\n",
    "        ncnn::Mat outMat;\r\n",
    "        int ret = ex.extract(\"alpha_mask\", outMat);\r\n",
    "        if (ret == 0 && outMat.w == 512 && outMat.h == 512) {\r\n",
    "            const float* ptr = (const float*)outMat.data;\r\n",
    "            #pragma omp parallel for schedule(static, 1024)\r\n",
    "            for (int i = 0; i < 512 * 512; ++i) {\r\n",
    "                float val = std::clamp(ptr[i], 0.0f, 1.0f);\r\n",
    "                outAlpha512[i] = std::max(outAlpha512[i], val);\r\n",
    "            }\r\n",
    "            ncnnSuccess = true;\r\n",
    "            LOGI(\"✅ HairMattingEngine: Combined BiSeNet + HairMattingMobile ensemble!\");\r\n",
    "        }\r\n",
    "    }\r\n",
    "\r\n"
]

lines[start_idx:end_idx] = ensemble_code

# 2. Update insideFace block so it only protects forehead center and doesn't wipe out temple curls
face_start = -1
face_end = -1
for i, l in enumerate(lines):
    if 'BẢO VỆ DA MẶT VÀ TRÁN' in l:
        face_start = i
    if face_start != -1 and 'Tường phông nền thực tế' in l:
        face_end = i
        break

print(f'Replacing face block {face_start} to {face_end}')

face_code = [
    "            // D. BẢO VỆ DA MẶT VÀ TRÁN (FOREHEAD HAIRLINE & FACE SHIELD - 100% ZERO LEAKAGE)\r\n",
    "            bool insideFace = !facePoly512.empty() ? isInsidePolygon512(fx, fy, facePoly512) : false;\r\n",
    "            bool isDefiniteSkin = isSkin || (r > g && g > b && rbDiff >= 26 && lum >= 0.32f);\r\n",
    "\r\n",
    "            // Bất kỳ pixel da người thực thụ nào (ngoại trừ tóc cạo sát buzz cut): Triệt tiêu tuyệt đối\r\n",
    "            if (isDefiniteSkin && !isRightBuzzCutZone) {\r\n",
    "                inoutAlpha512[idx] = 0.0f;\r\n",
    "                continue;\r\n",
    "            }\r\n",
    "\r\n",
    "            if (insideFace) {\r\n",
    "                // Vùng trán trung tâm giữa 2 lông mày nếu là da hoặc có độ sáng cao (không phải tóc)\r\n",
    "                if (fy > foreheadY512 && fx > (lBrowMinX + 10.0f) && fx < (rBrowMaxX - 10.0f)) {\r\n",
    "                    if (isDefiniteSkin || lum > 0.38f) {\r\n",
    "                        inoutAlpha512[idx] = 0.0f;\r\n",
    "                        continue;\r\n",
    "                    }\r\n",
    "                }\r\n",
    "            }\r\n",
    "\r\n"
]

lines[face_start:face_end] = face_code

with open('lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp', 'w', encoding='utf-8', newline='') as f:
    f.writelines(lines)

print('Updated hair_matting_engine.cpp successfully! Total lines:', len(lines))
