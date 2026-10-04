// tetrahedral_3d_lut_pseudocode.cpp — TRIỂN KHAI PHÒNG SẠCH C++ NỘI SUY TỨ DIỆN 3D LUT
// Thẩm quyền: Chủ tịch Tony (Chairman)
// Tiêu chuẩn Vận hành: 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD & Development Workspace Standard V2.1
// Quy chuẩn Pháp lý: RULE 11 CLEAN-ROOM SPECIFICATION (100% C++ Tái Dựng Độc Lập)

#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

#if defined(__ARM_NEON) || defined(__ARM_NEON__)
#include <arm_neon.h>
#endif

namespace meitu::reborn::color {

struct ColorRGB {
    float r, g, b;
};

class TetrahedralLutProcessor {
public:
    static constexpr int LUT_SIZE = 33;
    static constexpr float INV_SIZE = 1.0f / 33.0f;

    TetrahedralLutProcessor() = default;

    void SetLutData(const std::vector<float>& lutRgba) {
        // lutRgba size = 33 * 33 * 33 * 4 floats
        mLutTable = lutRgba;
    }

    ColorRGB SamplePoint(const ColorRGB& inColor) const {
        float r = std::clamp(inColor.r, 0.0f, 1.0f) * (LUT_SIZE - 1);
        float g = std::clamp(inColor.g, 0.0f, 1.0f) * (LUT_SIZE - 1);
        float b = std::clamp(inColor.b, 0.0f, 1.0f) * (LUT_SIZE - 1);

        int i0 = static_cast<int>(r);
        int j0 = static_cast<int>(g);
        int k0 = static_cast<int>(b);

        int i1 = std::min(i0 + 1, LUT_SIZE - 1);
        int j1 = std::min(j0 + 1, LUT_SIZE - 1);
        int k1 = std::min(k0 + 1, LUT_SIZE - 1);

        float dr = r - static_cast<float>(i0);
        float dg = g - static_cast<float>(j0);
        float db = b - static_cast<float>(k0);

        ColorRGB c000 = GetLutEntry(i0, j0, k0);
        ColorRGB c111 = GetLutEntry(i1, j1, k1);

        ColorRGB out;

        if (dr >= dg) {
            if (dg >= db) {
                // Case 1: dr >= dg >= db
                ColorRGB c100 = GetLutEntry(i1, j0, k0);
                ColorRGB c110 = GetLutEntry(i1, j1, k0);
                out.r = (1.0f - dr) * c000.r + (dr - dg) * c100.r + (dg - db) * c110.r + db * c111.r;
                out.g = (1.0f - dr) * c000.g + (dr - dg) * c100.g + (dg - db) * c110.g + db * c111.g;
                out.b = (1.0f - dr) * c000.b + (dr - dg) * c100.b + (dg - db) * c110.b + db * c111.b;
            } else if (dr >= db) {
                // Case 2: dr >= db > dg
                ColorRGB c100 = GetLutEntry(i1, j0, k0);
                ColorRGB c101 = GetLutEntry(i1, j0, k1);
                out.r = (1.0f - dr) * c000.r + (dr - db) * c100.r + (db - dg) * c101.r + dg * c111.r;
                out.g = (1.0f - dr) * c000.g + (dr - db) * c100.g + (db - dg) * c101.g + dg * c111.g;
                out.b = (1.0f - dr) * c000.b + (dr - db) * c100.b + (db - dg) * c101.b + dg * c111.b;
            } else {
                // Case 5: db > dr >= dg
                ColorRGB c001 = GetLutEntry(i0, j0, k1);
                ColorRGB c101 = GetLutEntry(i1, j0, k1);
                out.r = (1.0f - db) * c000.r + (db - dr) * c001.r + (dr - dg) * c101.r + dg * c111.r;
                out.g = (1.0f - db) * c000.g + (db - dr) * c001.g + (dr - dg) * c101.g + dg * c111.g;
                out.b = (1.0f - db) * c000.b + (db - dr) * c001.b + (dr - dg) * c101.b + dg * c111.b;
            }
        } else {
            if (dr >= db) {
                // Case 3: dg > dr >= db
                ColorRGB c010 = GetLutEntry(i0, j1, k0);
                ColorRGB c110 = GetLutEntry(i1, j1, k0);
                out.r = (1.0f - dg) * c000.r + (dg - dr) * c010.r + (dr - db) * c110.r + db * c111.r;
                out.g = (1.0f - dg) * c000.g + (dg - dr) * c010.g + (dr - db) * c110.g + db * c111.g;
                out.b = (1.0f - dg) * c000.b + (dg - dr) * c010.b + (dr - db) * c110.b + db * c111.b;
            } else if (dg >= db) {
                // Case 4: dg >= db > dr
                ColorRGB c010 = GetLutEntry(i0, j1, k0);
                ColorRGB c011 = GetLutEntry(i0, j1, k1);
                out.r = (1.0f - dg) * c000.r + (dg - db) * c010.r + (db - dr) * c011.r + dr * c111.r;
                out.g = (1.0f - dg) * c000.g + (dg - db) * c010.g + (db - dr) * c011.g + dr * c111.g;
                out.b = (1.0f - dg) * c000.b + (dg - db) * c010.b + (db - dr) * c011.b + dr * c111.b;
            } else {
                // Case 6: db > dg > dr
                ColorRGB c001 = GetLutEntry(i0, j0, k1);
                ColorRGB c011 = GetLutEntry(i0, j1, k1);
                out.r = (1.0f - db) * c000.r + (db - dg) * c001.r + (dg - dr) * c011.r + dr * c111.r;
                out.g = (1.0f - db) * c000.g + (db - dg) * c001.g + (dg - dr) * c011.g + dr * c111.g;
                out.b = (1.0f - db) * c000.b + (db - dg) * c001.b + (dg - dr) * c011.b + dr * c111.r;
            }
        }
        return out;
    }

private:
    ColorRGB GetLutEntry(int x, int y, int z) const {
        size_t index = (static_cast<size_t>(z) * LUT_SIZE * LUT_SIZE +
                        static_cast<size_t>(y) * LUT_SIZE +
                        static_cast<size_t>(x)) * 4;
        if (index + 2 < mLutTable.size()) {
            return { mLutTable[index], mLutTable[index + 1], mLutTable[index + 2] };
        }
        return { 0.0f, 0.0f, 0.0f };
    }

    std::vector<float> mLutTable;
};

} // namespace meitu::reborn::color
