precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_mask;
uniform vec3 color;
uniform float size;
uniform float textureHeight;
uniform float textureWidth;

varying vec2 v_texCoord;

vec4 imgWithDilateProcess(float size)
{
    float ratio = textureHeight / textureWidth;
    float ratioX = 1.0;
    float ratioY = 1.0;
    if (ratio > 1.0) { // 高大于宽, H/W
        ratioX = ratio;
    } else { // 宽大于等于高，W/H
        ratioY = 1.0 / ratio;
    }
    vec4 maxValue = vec4(0.0);
    int coreSize = 3;// 卷积核的尺寸  3x3
    int halfCoreSize = coreSize / 2; // 用于得到卷积中心
    float texelOffset = 1.0 / 100.0 * size; // 纹理坐标偏移量
    for(int y=0; y < coreSize; y++)
    {
        for(int x=0; x < coreSize; x++)
        {
            //计算卷积核覆盖区域像素点的最大值
            vec4 color = texture2D(u_mask, v_texCoord + vec2( float(-halfCoreSize+x) * texelOffset * ratioX, float(-halfCoreSize+y) * texelOffset * ratioY));
            maxValue = max(maxValue, color);
        }
    }
    return maxValue;
}

void main(void)
{
    vec4 scaleMaskColor = imgWithDilateProcess(size/16.0);
    vec4 srcColor = texture2D(u_texture, v_texCoord);

    // stroke边缘0.1部分，如果rgba都是0，则是无源数据，不显示
    if (v_texCoord.x > 0.9 || v_texCoord.x < 0.1 || v_texCoord.y > 0.9 || v_texCoord.y < 0.1) {
        if (srcColor.r == 0.0 && srcColor.g == 0.0 && srcColor.b == 0.0 && srcColor.a == 0.0) {
            gl_FragColor = srcColor;
        }
        else {
            gl_FragColor = vec4(srcColor.rgb, scaleMaskColor.r);
        }
    }
    else {
        gl_FragColor = vec4(srcColor.rgb, scaleMaskColor.r);
    }
    
}
