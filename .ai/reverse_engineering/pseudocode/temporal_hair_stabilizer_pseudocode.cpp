// temporal_hair_stabilizer_pseudocode.cpp — TRIỂN KHAI PHÒNG SẠCH C++ ỔN ĐỊNH THỜI GIAN VIDEO
// Thẩm quyền: Chủ tịch Tony (Chairman)
// Tiêu chuẩn Vận hành: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1
// Quy chuẩn Pháp lý: RULE 11 CLEAN-ROOM SPECIFICATION (100% C++ Tái Dựng Độc Lập)

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

namespace meitu::reborn::video {

class TemporalHairStabilizer {
public:
    TemporalHairStabilizer(int width, int height)
        : mWidth(width), mHeight(height) {
        mHistoryBuffer.resize(width * height * 4, 0);
        mHasHistory = false;
    }

    void ProcessFrame(
        const uint8_t* currRgba,       // Khung hình hiện tại (t)
        const float* opticalFlowMap,   // Vector (u, v) dịch chuyển
        uint8_t* outRgba,              // Kết quả xuất xưởng
        float feedbackAlpha = 0.20f    // Tỷ lệ lấy mẫu hiện tại [0.15 - 0.25]
    ) {
        if (!mHasHistory) {
            std::copy(currRgba, currRgba + mWidth * mHeight * 4, outRgba);
            std::copy(currRgba, currRgba + mWidth * mHeight * 4, mHistoryBuffer.data());
            mHasHistory = true;
            return;
        }

        #pragma omp parallel for schedule(static)
        for (int y = 0; y < mHeight; ++y) {
            for (int x = 0; x < mWidth; ++x) {
                int idx = (y * mWidth + x) * 4;

                // 1. Quét lân cận 3x3 để tìm Min/Max màu chống hiện tượng bóng ma (Ghosting)
                uint8_t minR = 255, minG = 255, minB = 255;
                uint8_t maxR = 0, maxG = 0, maxB = 0;

                for (int dy = -1; dy <= 1; ++dy) {
                    int ny = std::clamp(y + dy, 0, mHeight - 1);
                    for (int dx = -1; dx <= 1; ++dx) {
                        int nx = std::clamp(x + dx, 0, mWidth - 1);
                        int nIdx = (ny * mWidth + nx) * 4;

                        minR = std::min(minR, currRgba[nIdx + 0]);
                        maxR = std::max(maxR, currRgba[nIdx + 0]);
                        minG = std::min(minG, currRgba[nIdx + 1]);
                        maxG = std::max(maxG, currRgba[nIdx + 1]);
                        minB = std::min(minB, currRgba[nIdx + 2]);
                        maxB = std::max(maxB, currRgba[nIdx + 2]);
                    }
                }

                // 2. Dò tìm tọa độ trong khung hình trước theo Optical Flow
                float u = opticalFlowMap ? opticalFlowMap[(y * mWidth + x) * 2 + 0] : 0.0f;
                float v = opticalFlowMap ? opticalFlowMap[(y * mWidth + x) * 2 + 1] : 0.0f;

                float prevX = static_cast<float>(x) - u;
                float prevY = static_cast<float>(y) - v;

                uint8_t histR, histG, histB;
                SampleHistoryBilinear(prevX, prevY, histR, histG, histB);

                // 3. Kẹp màu lịch sử
                histR = std::clamp(histR, minR, maxR);
                histG = std::clamp(histG, minG, maxG);
                histB = std::clamp(histB, minB, maxB);

                // 4. Hòa trộn
                uint8_t resR = static_cast<uint8_t>(feedbackAlpha * currRgba[idx + 0] + (1.0f - feedbackAlpha) * histR + 0.5f);
                uint8_t resG = static_cast<uint8_t>(feedbackAlpha * currRgba[idx + 1] + (1.0f - feedbackAlpha) * histG + 0.5f);
                uint8_t resB = static_cast<uint8_t>(feedbackAlpha * currRgba[idx + 2] + (1.0f - feedbackAlpha) * histB + 0.5f);

                outRgba[idx + 0] = resR;
                outRgba[idx + 1] = resG;
                outRgba[idx + 2] = resB;
                outRgba[idx + 3] = currRgba[idx + 3];

                mHistoryBuffer[idx + 0] = resR;
                mHistoryBuffer[idx + 1] = resG;
                mHistoryBuffer[idx + 2] = resB;
                mHistoryBuffer[idx + 3] = currRgba[idx + 3];
            }
        }
    }

private:
    void SampleHistoryBilinear(float fx, float fy, uint8_t& outR, uint8_t& outG, uint8_t& outB) const {
        int x0 = std::clamp(static_cast<int>(std::floor(fx)), 0, mWidth - 1);
        int y0 = std::clamp(static_cast<int>(std::floor(fy)), 0, mHeight - 1);
        int x1 = std::clamp(x0 + 1, 0, mWidth - 1);
        int y1 = std::clamp(y0 + 1, 0, mHeight - 1);

        float dx = fx - std::floor(fx);
        float dy = fy - std::floor(fy);

        int idx00 = (y0 * mWidth + x0) * 4;
        int idx10 = (y0 * mWidth + x1) * 4;
        int idx01 = (y1 * mWidth + x0) * 4;
        int idx11 = (y1 * mWidth + x1) * 4;

        auto interp = [&](int offset) {
            float v0 = (1.0f - dx) * mHistoryBuffer[idx00 + offset] + dx * mHistoryBuffer[idx10 + offset];
            float v1 = (1.0f - dx) * mHistoryBuffer[idx01 + offset] + dx * mHistoryBuffer[idx11 + offset];
            return static_cast<uint8_t>(std::clamp((1.0f - dy) * v0 + dy * v1 + 0.5f, 0.0f, 255.0f));
        };

        outR = interp(0);
        outG = interp(1);
        outB = interp(2);
    }

    int mWidth;
    int mHeight;
    bool mHasHistory;
    std::vector<uint8_t> mHistoryBuffer;
};

} // namespace meitu::reborn::video
