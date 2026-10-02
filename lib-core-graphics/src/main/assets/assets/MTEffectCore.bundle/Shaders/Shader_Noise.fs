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


varying highp vec2 vTexcoord;
varying highp vec2 vEffectCoord;
uniform lowp sampler2D texture;
// 偏移程度的样子
uniform highp float shift;
// 半径
uniform highp float effectStartDistance;
// 中心
uniform highp vec2 effectCenter;
// 中心的大小 似乎和X坐标没关系 好像 
uniform highp vec2 distanceFieldCorrectionVector;

uniform float textureWidth;
uniform float textureHeight;
uniform int textureIndex;

uniform float alpha;

//const int kSamplesNum = 14;
const int kSamplesNum = 5;
const float kRedShiftFactor = 1.0;
const float kBlueShiftFactor = 2.0;
const float kGreenShiftFactor = 1.5;
const highp float kEpsilon = 0.000001;
const highp vec2 effectTranslation = vec2(0.0, 0.0);

const int iter = 8;

float hash12(vec2 p)
{
	vec3 p3  = fract(vec3(p.xyx) * 0.1031);
    p3 += dot(p3, p3.yzx + 19.19);
    return fract((p3.x + p3.y) * p3.z);
}

float lag_noise(vec2 p){
	float a = 0.0;
    for (int t = 0; t < iter; t++)
    {
        float v = float(t + 1)*1.5;
        vec2 pos = (p * v + float(textureIndex) * 10.0);
        a += hash12(pos);
    }
    return a / float(iter);
}

void main() {
    
	//vec4 srcColor = vec4(outputColor,1.0);
    
	float noiseGray = lag_noise(vTexcoord*vec2(textureWidth,textureHeight));
	
    noiseGray = clamp((noiseGray + 1.0) / 2.0, 0.0, 1.0);
	
	gl_FragColor = vec4(noiseGray, noiseGray, noiseGray, 1.0);
}
