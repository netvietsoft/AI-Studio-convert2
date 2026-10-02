#include "landmark_fusion.h"
#include <cmath>
#include <algorithm>

namespace MeituReborn {

LandmarkFusionEngine& LandmarkFusionEngine::getInstance() {
    static LandmarkFusionEngine s_inst;
    return s_inst;
}

void LandmarkFusionEngine::reset() {
    mLastFused = FusedFaceGeometry();
}

FusedFaceGeometry LandmarkFusionEngine::fuse(
    const float* stabilized106,
    const float* stabilized478,
    float faceX1, float faceY1, float faceX2, float faceY2
) {
    FusedFaceGeometry geo;
    geo.boxX1 = faceX1;
    geo.boxY1 = faceY1;
    geo.boxX2 = faceX2;
    geo.boxY2 = faceY2;

    // 1. Sao chep 106 Semantic Anchors
    geo.anchors106.resize(106 * 2, 0.0f);
    if (stabilized106 != nullptr) {
        for (int i = 0; i < 106 * 2; ++i) {
            geo.anchors106[i] = stabilized106[i];
        }
    }

    // 2. Sao chep 478 Dense Mesh
    geo.dense478.resize(478, {0.0f, 0.0f, 0.0f});
    if (stabilized478 != nullptr) {
        for (int i = 0; i < 478; ++i) {
            geo.dense478[i] = {
                stabilized478[i * 3],
                stabilized478[i * 3 + 1],
                stabilized478[i * 3 + 2]
            };
        }

        // 3. Trich xuat Iris Track
        geo.iris.leftCenter = geo.dense478[468];
        geo.iris.leftRadius = std::hypot(geo.dense478[469].x - geo.dense478[468].x, geo.dense478[469].y - geo.dense478[468].y);
        geo.iris.rightCenter = geo.dense478[473];
        geo.iris.rightRadius = std::hypot(geo.dense478[474].x - geo.dense478[473].x, geo.dense478[474].y - geo.dense478[473].y);

        // 4. Trich xuat Ranh cuoi (Nasolabial Folds):
        geo.leftSmileLine = { geo.dense478[205], geo.dense478[50], geo.dense478[118], geo.dense478[123] };
        geo.rightSmileLine = { geo.dense478[425], geo.dense478[280], geo.dense478[347], geo.dense478[352] };

        // 5. Khoe mat (Canthus):
        geo.leftOuterCanthus = geo.dense478[33];
        geo.leftInnerCanthus = geo.dense478[133];
        geo.rightInnerCanthus = geo.dense478[362];
        geo.rightOuterCanthus = geo.dense478[263];
    } else if (stabilized106 != nullptr) {
        // Fallback: Khi Dense Mesh 478 chua co hoac goc nghieng khoe,
        // tai tao bo khung Dense Mesh co ban tu 106 Semantic Landmarks cho Jawline va Râu
        static const int SPINE_478[21] = {
            234, 93, 132, 58, 172, 136, 150, 149, 176, 148, 152, 377, 400, 378, 379, 365, 397, 288, 361, 323, 454
        };
        static const int MAP_106_CONTOUR[21] = {
            0, 1, 3, 5, 7, 9, 11, 13, 14, 15, 16, 17, 18, 19, 21, 23, 25, 27, 29, 31, 32
        };
        for (int k = 0; k < 21; ++k) {
            int p106 = MAP_106_CONTOUR[k];
            int p478 = SPINE_478[k];
            geo.dense478[p478] = { stabilized106[p106 * 2], stabilized106[p106 * 2 + 1], 0.0f };
        }

        // Dinh cam (152) = 106[16]
        geo.dense478[152] = { stabilized106[16 * 2], stabilized106[16 * 2 + 1], 0.0f };
        // Dinh mui (1) = 106[46], chan mui (2) = 106[49]
        geo.dense478[1] = { stabilized106[46 * 2], stabilized106[46 * 2 + 1], 0.0f };
        geo.dense478[2] = { stabilized106[49 * 2], stabilized106[49 * 2 + 1], 0.0f };
        // Dinh tran (10) = trung diem 2 dau long may (33, 34)
        geo.dense478[10] = { (stabilized106[33 * 2] + stabilized106[34 * 2]) * 0.5f,
                             (stabilized106[33 * 2 + 1] + stabilized106[34 * 2 + 1]) * 0.5f, 0.0f };
        // Moi tren (0) = 106[76], moi duoi (17) = 106[82]
        geo.dense478[0] = { stabilized106[76 * 2], stabilized106[76 * 2 + 1], 0.0f };
        geo.dense478[17] = { stabilized106[82 * 2], stabilized106[82 * 2 + 1], 0.0f };
        // Khoe mieng trai (61) = 106[52], phai (291) = 106[61]
        geo.dense478[61] = { stabilized106[52 * 2], stabilized106[52 * 2 + 1], 0.0f };
        geo.dense478[291] = { stabilized106[61 * 2], stabilized106[61 * 2 + 1], 0.0f };
        // Diem tham chieu da (118)
        geo.dense478[118] = { (stabilized106[52 * 2] + stabilized106[4 * 2]) * 0.5f,
                              (stabilized106[52 * 2 + 1] + stabilized106[4 * 2 + 1]) * 0.5f, 0.0f };
        // Diem ma trai (127), ma phai (356)
        geo.dense478[127] = { stabilized106[2 * 2], stabilized106[2 * 2 + 1], 0.0f };
        geo.dense478[356] = { stabilized106[30 * 2], stabilized106[30 * 2 + 1], 0.0f };

        // Canh mui, goc mui & vach ngan tu 106
        geo.dense478[98]  = { stabilized106[48 * 2], stabilized106[48 * 2 + 1], 0.0f };
        geo.dense478[97]  = { stabilized106[47 * 2], stabilized106[47 * 2 + 1], 0.0f };
        geo.dense478[327] = { stabilized106[50 * 2], stabilized106[50 * 2 + 1], 0.0f };
        geo.dense478[326] = { stabilized106[51 * 2], stabilized106[51 * 2 + 1], 0.0f };
        geo.dense478[164] = { stabilized106[49 * 2], stabilized106[49 * 2 + 1], 0.0f };

        // Lips outer contour
        static const int LIPS_OUTER_INDICES[20] = {
            61, 146, 91, 181, 84, 17, 314, 405, 321, 375, 291,
            308, 324, 318, 402, 317, 14, 87, 178, 88
        };
        for (int i = 0; i < 20; ++i) {
            int p106 = 52 + (i % 20);
            if (p106 <= 71) {
                geo.dense478[LIPS_OUTER_INDICES[i]] = { stabilized106[p106 * 2], stabilized106[p106 * 2 + 1], 0.0f };
            }
        }
    }

    mLastFused = geo;
    return geo;
}

} // namespace MeituReborn