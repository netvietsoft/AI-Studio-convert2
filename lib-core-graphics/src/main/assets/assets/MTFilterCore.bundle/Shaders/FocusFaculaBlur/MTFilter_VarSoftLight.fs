#ifdef GL_ES//for discriminate GLES & GL
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#else
#define highp
#define mediump
#define lowp
#endif

varying vec2 uv0;
varying vec2 uv1;
uniform sampler2D texture;
uniform sampler2D blurTexture;

vec3 blendSoftLight(vec3 base, vec3 blend)
{
    vec3 color1 = 2.0 * base * blend + base * base * (vec3(1.0) - 2.0 * blend);
    vec3 color2 = sqrt(base) * (2.0 * blend - vec3(1.0)) + 2.0 * base * (vec3(1.0) - blend);
    return mix(color1, color2, step(vec3(0.5), blend));
}

void main(void)
{
    lowp vec3 ori = texture2D(texture,uv0).rgb;
    lowp vec3 box = texture2D(blurTexture,uv0).rgb;
    vec3 blendColor = clamp(ori - box + vec3(0.5), vec3(0.0), vec3(1.0));
    gl_FragColor = vec4(blendSoftLight(ori, blendColor), 1.0);
}


