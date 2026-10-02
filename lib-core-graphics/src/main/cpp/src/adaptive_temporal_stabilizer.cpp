#include "adaptive_temporal_stabilizer.h"
#include <algorithm>
#include <cmath>

namespace MeituReborn {

AdaptiveTemporalStabilizer::AdaptiveTemporalStabilizer() {
    prevMesh478.resize(478 * 3, 0.0f);
    prev106.resize(106 * 2, 0.0f);
}

void AdaptiveTemporalStabilizer::reset() {
    hasPrevMesh = false;
    hasPrev106 = false;
}

float AdaptiveTemporalStabilizer::getZoneAlpha478(int pointIdx) {
    // 1. Vung mat & con nguoi (33..160, 263..387, 468..477):
    if ((pointIdx >= 33 && pointIdx <= 160) ||
        (pointIdx >= 263 && pointIdx <= 387) ||
        (pointIdx >= 468 && pointIdx <= 477)) {
        return 0.40f;
    }
    // 2. Vung mieng & moi (0..17, 61..291):
    if ((pointIdx >= 0 && pointIdx <= 17) || (pointIdx >= 61 && pointIdx <= 91)) {
        return 0.45f;
    }
    // 3. Mui & Chan may (1, 2, 4, 5, 195, 197...):
    if (pointIdx == 1 || pointIdx == 4 || pointIdx == 195 || pointIdx == 197) {
        return 0.70f;
    }
    // 4. Duong vien ham & Ma (Contour):
    return 0.85f;
}

float AdaptiveTemporalStabilizer::getZoneAlpha106(int pointIdx) {
    if (pointIdx >= 62 && pointIdx <= 81) return 0.40f;
    if (pointIdx >= 82 && pointIdx <= 105) return 0.45f;
    if (pointIdx >= 33 && pointIdx <= 61) return 0.70f;
    return 0.85f;
}

void AdaptiveTemporalStabilizer::stabilizeMesh478(const float* currentMesh, float* stabilizedMesh, float dt) {
    if (!currentMesh || !stabilizedMesh) return;

    if (!hasPrevMesh) {
        for (int i = 0; i < 478 * 3; ++i) {
            stabilizedMesh[i] = currentMesh[i];
            prevMesh478[i] = currentMesh[i];
        }
        hasPrevMesh = true;
        return;
    }

    // Kiem tra buoc nhay vi tri tam mat (Nose tip point 1 hoac 4):
    // Neu tam mat cach nhau > 60px -> Day la anh moi hoac goc quay dot ngot, can snap ngay!
    float centerDiff = std::hypot(currentMesh[1 * 3] - prevMesh478[1 * 3], currentMesh[1 * 3 + 1] - prevMesh478[1 * 3 + 1]);
    if (centerDiff > 60.0f) {
        for (int i = 0; i < 478 * 3; ++i) {
            stabilizedMesh[i] = currentMesh[i];
            prevMesh478[i] = currentMesh[i];
        }
        hasPrevMesh = true;
        return;
    }

    const float maxJump = 45.0f;

    for (int i = 0; i < 478; ++i) {
        float alpha = getZoneAlpha478(i);

        for (int c = 0; c < 3; ++c) {
            int idx = i * 3 + c;
            float cur = currentMesh[idx];
            float prv = prevMesh478[idx];

            float diff = cur - prv;
            if (std::abs(diff) > maxJump) {
                diff = (diff > 0 ? 1.0f : -1.0f) * maxJump;
            }

            float filtered = prv + (1.0f - alpha) * diff;
            stabilizedMesh[idx] = filtered;
            prevMesh478[idx] = filtered;
        }
    }
}

void AdaptiveTemporalStabilizer::stabilizeLandmarks106(const float* current106, float* stabilized106, float dt) {
    if (!current106 || !stabilized106) return;

    if (!hasPrev106) {
        for (int i = 0; i < 106 * 2; ++i) {
            stabilized106[i] = current106[i];
            prev106[i] = current106[i];
        }
        hasPrev106 = true;
        return;
    }

    // Kiem tra buoc nhay tam mui (106 index 46):
    float centerDiff = std::hypot(current106[46 * 2] - prev106[46 * 2], current106[46 * 2 + 1] - prev106[46 * 2 + 1]);
    if (centerDiff > 60.0f) {
        for (int i = 0; i < 106 * 2; ++i) {
            stabilized106[i] = current106[i];
            prev106[i] = current106[i];
        }
        hasPrev106 = true;
        return;
    }

    const float maxJump = 40.0f;

    for (int i = 0; i < 106; ++i) {
        float alpha = getZoneAlpha106(i);

        for (int c = 0; c < 2; ++c) {
            int idx = i * 2 + c;
            float cur = current106[idx];
            float prv = prev106[idx];

            float diff = cur - prv;
            if (std::abs(diff) > maxJump) {
                diff = (diff > 0 ? 1.0f : -1.0f) * maxJump;
            }

            float filtered = prv + (1.0f - alpha) * diff;
            stabilized106[idx] = filtered;
            prev106[idx] = filtered;
        }
    }
}

} // namespace MeituReborn