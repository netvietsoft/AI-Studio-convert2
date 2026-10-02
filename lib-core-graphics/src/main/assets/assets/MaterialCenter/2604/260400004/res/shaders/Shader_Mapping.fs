precision highp float;

uniform sampler2D u_texture;
uniform sampler2D u_mask;
uniform vec3 color;
uniform float size;

varying vec2 v_texCoord;

void main(void)
{
    float lineWidth = (0.07 / 20.0) * size + 0.01;
    vec4 leftMaskColor = texture2D(u_mask, v_texCoord + vec2(lineWidth, 0.0)); // 带（向左）偏移的遮罩

    vec4 maskColor = texture2D(u_mask, v_texCoord); // 无偏遮罩
    vec4 srcColor = texture2D(u_texture, v_texCoord);

    leftMaskColor = step(0.5, leftMaskColor); // 对带偏移的遮罩进行二值化
    maskColor = step(0.5, maskColor); // 对无偏遮罩进行二值化

    vec4 strokeColor = vec4(color,1.0);
    vec4 leftStrokeColor = mix(srcColor, strokeColor, leftMaskColor.r); // 带偏遮罩的混色（描边颜色+原图颜色）
    leftMaskColor.r = max(leftMaskColor.r, maskColor.r); // 两种遮罩取大值（或运算）

    gl_FragColor = vec4(mix(leftStrokeColor, srcColor, maskColor.r).rgb /*无偏遮罩的混色*/, leftMaskColor.r);
}
