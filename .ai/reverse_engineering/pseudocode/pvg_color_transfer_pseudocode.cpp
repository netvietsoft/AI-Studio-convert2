// Clean-Room PVG Color Transfer & 3D LUT Mapper
#include <vector>
#include <algorithm>

namespace convert2 {
namespace color {

struct Vec3 { float r, g, b; };

Vec3 sample3DLut(const float* lut3D, int lutDim, Vec3 rgb) {
    int r0 = std::clamp(static_cast<int>(rgb.r * (lutDim - 1)), 0, lutDim - 1);
    int g0 = std::clamp(static_cast<int>(rgb.g * (lutDim - 1)), 0, lutDim - 1);
    int b0 = std::clamp(static_cast<int>(rgb.b * (lutDim - 1)), 0, lutDim - 1);
    int idx = (b0 * lutDim * lutDim + g0 * lutDim + r0) * 3;
    return { lut3D[idx], lut3D[idx + 1], lut3D[idx + 2] };
}

} // namespace color
} // namespace convert2
