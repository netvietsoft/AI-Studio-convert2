// Clean-Room Structure Tensor & LIC Implementation
#include <vector>
#include <cmath>

namespace convert2 {
namespace hair {

void computeDoubleAngleTensor(const float* luma, int w, int h, float* outTheta) {
    for (int y = 1; y < h - 1; ++y) {
        for (int x = 1; x < w - 1; ++x) {
            float dx = (luma[y * w + (x + 1)] - luma[y * w + (x - 1)]) * 0.5f;
            float dy = (luma[(y + 1) * w + x] - luma[(y - 1) * w + x]) * 0.5f;
            float jxx = dx * dx;
            float jyy = dy * dy;
            float jxy = dx * dy;
            outTheta[y * w + x] = 0.5f * std::atan2(2.0f * jxy, jxx - jyy);
        }
    }
}

} // namespace hair
} // namespace convert2
