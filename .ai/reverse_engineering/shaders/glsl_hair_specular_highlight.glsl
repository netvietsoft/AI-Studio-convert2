#version 300 es
precision mediump float;
in vec2 v_TexCoord;
out vec4 fragColor;

uniform sampler2D u_OrientationMap; // Bản đồ góc theta từ Structure Tensor
uniform float u_ShineStrength;      // Cường độ ánh kim lọn tóc
uniform vec2 u_LightDir;            // Hướng nguồn sáng chính (mặc định [0.0, 1.0])

void main() {
    vec4 orientSample = texture(u_OrientationMap, v_TexCoord);
    float theta = orientSample.r * 3.14159265;
    vec2 tangent = vec2(cos(theta), sin(theta));
    
    // Tính toán góc phản xạ Kajiya-Kay theo sợi tóc
    float cosTL = dot(tangent, normalize(u_LightDir));
    float sinTL = sqrt(max(0.0, 1.0 - cosTL * cosTL));
    float specular = pow(sinTL, 16.0) * u_ShineStrength;
    
    fragColor = vec4(vec3(specular), 1.0);
}
