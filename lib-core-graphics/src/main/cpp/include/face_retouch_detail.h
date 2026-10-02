#ifndef MEITU_FACE_RETOUCH_DETAIL_H
#define MEITU_FACE_RETOUCH_DETAIL_H

#include <cstdint>
#include <vector>
#include "dense_facemesh_478.h"

namespace MeituReborn {

class FaceRetouchDetail {
public:
    // 1. Trang diem con nguoi (Iris Track, Lens Tint, Limbal Ring & Catchlight)
    static bool applyIrisMakeup(
        uint32_t* pixels, int width, int height,
        const IrisTrackResult& iris,
        float pupilScale, float glowIntensity,
        int toneId, float toneIntensity,
        int catchlightType, float catchlightIntensity
    );

    // 2. Nan chi tiet khoe mat (Inner & Outer Canthus Adjustment khong mot vet gon)
    static bool adjustCanthusDetail(
        uint32_t* pixels, int width, int height,
        const Point3D& leftOuter, const Point3D& leftInner,
        const Point3D& rightInner, const Point3D& rightOuter,
        float innerCanthusOpen, float outerCanthusLift, float eyeSpan
    );

    // 3. Xoa ranh cuoi & duong cuoi mui ma (Nasolabial fold smoothing & lifting khong mot vet gon)
    static bool applyNasolabialSmoothing(
        uint32_t* pixels, int width, int height,
        const std::vector<Point3D>& leftSmileLine,
        const std::vector<Point3D>& rightSmileLine,
        float intensity
    );
};

} // namespace MeituReborn

#endif // MEITU_FACE_RETOUCH_DETAIL_H
