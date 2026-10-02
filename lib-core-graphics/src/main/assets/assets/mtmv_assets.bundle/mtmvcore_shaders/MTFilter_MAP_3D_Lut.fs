#version 300 es
#ifdef GL_ES
precision highp float;
precision highp sampler3D;
precision highp sampler2D;
#else
#define highp
#endif

in vec2 vTexCoord;
out vec4 fragColor;

uniform sampler2D uTexture0;
uniform sampler3D uTexture1;
uniform float uLUTIntensity;

highp vec3 sampleLUT(highp vec3 color)
{
    return texture(uTexture1, vec3(color.r, (1.0 - color.g), color.b)).rgb;
}

void main()
{
    highp vec3 color  = texture(uTexture0, vTexCoord).rgb;  // 原始颜色
    highp vec3 lutColor = sampleLUT(color);                 // LUT 调整后的颜色

    // 根据 uLUTIntensity 混合原色和 LUT 颜色
    highp vec3 result = mix(color, lutColor, clamp(uLUTIntensity, 0.0, 1.0));
    fragColor = vec4(result, 1.0);
}
