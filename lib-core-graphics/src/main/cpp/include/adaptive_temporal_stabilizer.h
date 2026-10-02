#ifndef MEITU_ADAPTIVE_TEMPORAL_STABILIZER_H
#define MEITU_ADAPTIVE_TEMPORAL_STABILIZER_H

#include <vector>
#include <cstdint>

namespace MeituReborn {

class AdaptiveTemporalStabilizer {
public:
    AdaptiveTemporalStabilizer();
    void reset();

    // Loc on dinh 478 diem Dense Mesh voi he so thich nghi tung phan vung
    void stabilizeMesh478(const float* currentMesh, float* stabilizedMesh, float dt = 0.033f);

    // Loc on dinh 106 diem Landmark
    void stabilizeLandmarks106(const float* current106, float* stabilized106, float dt = 0.033f);

private:
    std::vector<float> prevMesh478;
    std::vector<float> prev106;
    bool hasPrevMesh = false;
    bool hasPrev106 = false;

    static float getZoneAlpha478(int pointIdx);
    static float getZoneAlpha106(int pointIdx);
};

} // namespace MeituReborn

#endif // MEITU_ADAPTIVE_TEMPORAL_STABILIZER_H
