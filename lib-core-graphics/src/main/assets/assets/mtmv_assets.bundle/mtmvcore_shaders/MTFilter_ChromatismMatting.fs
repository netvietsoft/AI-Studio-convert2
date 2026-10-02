#ifdef GL_ES
precision highp float;
#else
#define highp
#define mediump
#define lowp
#endif

varying  vec2 vTexCoord;

uniform sampler2D uTexture0;
uniform int uAlphaPremultiplied;
uniform int uColorspace;
uniform float uIntensity;
uniform float uPercent;
uniform vec4 uMattingColorRgba;

//RGB2Lab Lab2RGB
const float param_13 = 1.0 / 3.0;
const float param_16116 = 16.0 / 116.0;
const float Xn = 0.950456;
const float Yn = 1.0;
const float Zn = 1.088754;

float log10(float x)
{
    return log(x) / log(10.0);
}

float gamma(float x)
{
    return x>0.04045?pow((x+0.055)/1.055,2.4):(x/12.92);
}

float HLGInverseOETF(float x)
{
    if (x > 1.0 / 2.)
    {
        return (exp((x - 0.55991073) / 0.17883277) + 0.28466892) / 12.;
    }
    return pow(x, 2.0) / 3.0;
}

float HLGOOTF(float x, float y, float gam, float gain)
{
    return gain * pow(y, gam - 1.0) * x;
}

float HLGOOTF_Lw(float x, float y, float Lw, float gain)
{
    float gam = 1.2 + 0.42 * log10(Lw / 1000.0);
    return HLGOOTF(x, y, gam, gain);
}

float HGL_EOTF_1(float x, float r, float g, float b, float Lw, float Lb, float gain)
{
    float gam = 1.2 + 0.42 * log10(Lw / 1000.0);
    float p = sqrt(3.0 * pow(Lb / Lw, 1.0 / gam));
    float y = 0.2627 * HLGInverseOETF(max(0.0, (1.0 - p) * r + p)) + 0.678 * HLGInverseOETF(max(0.0, (1.0 - p) * g + p)) + 0.0593 * HLGInverseOETF(max(0.0, (1.0 - p) * b + p));
    return HLGOOTF_Lw(HLGInverseOETF(max(0.0, (1.0 - p) * x + p)), y, Lw, gain);
}

vec4 HLG_EOTF(vec4 rgb)
{
    float Lw = 203.0;
    float Lb = 0.005;
    float gain = 1.0;
    vec4 d;
    d.x = HGL_EOTF_1(rgb.x, rgb.x, rgb.y, rgb.z, Lw, Lb, gain);
    d.y = HGL_EOTF_1(rgb.y, rgb.x, rgb.y, rgb.z, Lw, Lb, gain);
    d.z = HGL_EOTF_1(rgb.z, rgb.x, rgb.y, rgb.z, Lw, Lb, gain);
    d.w = 1.0;
    return d;
}

vec3 sRGB2XYZ(vec4 rgb) {
    vec3 xyz;
    float RR = gamma(rgb.x);
    float GG = gamma(rgb.y);
    float BB = gamma(rgb.z);

    xyz.x = 0.4124564 * RR + 0.3575761 * GG + 0.1804375 * BB;
    xyz.y = 0.2126729 * RR + 0.7151522 * GG + 0.0721750 * BB;
    xyz.z = 0.0193339 * RR + 0.1191920 * GG + 0.9503041 * BB;
    return xyz;
}

vec3 hlg2XYZ(vec4 origin)
{
    vec3 xyz;
    vec4 linearRGB = HLG_EOTF(origin);
    xyz.x = 0.6369580 * linearRGB.x + 0.1446169 * linearRGB.y + 0.1688810 * linearRGB.z;
    xyz.y = 0.2627002  * linearRGB.x + 0.6779981 * linearRGB.y + 0.0593017 * linearRGB.z;
    xyz.z = 0.0000000 * linearRGB.x + 0.0280727  * linearRGB.y + 1.0609851 * linearRGB.z;
    return xyz;
}

vec3 XYZ2Lab(float X, float Y, float Z) {
    vec3 lab;
    float fX, fY, fZ;

    X /= (Xn);
    Y /= (Yn);
    Z /= (Zn);

    if (Y > 0.008856)
        fY = pow(Y, param_13);
    else
        fY = 7.787 * Y + param_16116;

    if (X > 0.008856)
        fX = pow(X, param_13);
    else
        fX = 7.787 * X + param_16116;

    if (Z > 0.008856)
        fZ = pow(Z, param_13);
    else
        fZ = 7.787 * Z + param_16116;

    lab.x = 116.0 * fY - 16.0;
    lab.x = lab.x > 0.0 ? lab.x : 0.0;
    lab.y = 500.0 * (fX - fY);
    lab.z = 200.0 * (fY - fZ);
    return lab;
}

void main(void)
{
    vec4 origin = texture2D(uTexture0, vTexCoord).rgba;

    vec3 originLab;
    vec3 mattingColorLab;
    if (uColorspace == 3) {
        vec3 originXyz = hlg2XYZ(origin);
        originLab = XYZ2Lab(originXyz.x,originXyz.y,originXyz.z);
        
        originXyz = hlg2XYZ(uMattingColorRgba);
        mattingColorLab = XYZ2Lab(originXyz.x,originXyz.y,originXyz.z);
    } else {
        vec3 originXyz = sRGB2XYZ(origin);
        originLab = XYZ2Lab(originXyz.x,originXyz.y,originXyz.z);
        
        originXyz = sRGB2XYZ(uMattingColorRgba);
        mattingColorLab = XYZ2Lab(originXyz.x,originXyz.y,originXyz.z);
    }

    float e = sqrt((mattingColorLab.x - originLab.x) * (mattingColorLab.x - originLab.x) + (mattingColorLab.y - originLab.y) * (mattingColorLab.y - originLab.y) + (mattingColorLab.z - originLab.z) * (mattingColorLab.z - originLab.z));

    if (e < uIntensity) {
        origin.r = origin.r - uMattingColorRgba.r;
        origin.g = origin.g - uMattingColorRgba.g;
        origin.b = origin.b - uMattingColorRgba.b;
        origin.a = origin.a - uMattingColorRgba.a;
        if (uPercent > 0.0 && e - (1.0 - uPercent) * uIntensity > 0.0) {
            origin.r = origin.r + uMattingColorRgba.r * (e - (1.0 - uPercent) * uIntensity) / (uPercent * uIntensity);
            origin.g = origin.g + uMattingColorRgba.g * (e - (1.0 - uPercent) * uIntensity) / (uPercent * uIntensity);
            origin.b = origin.b + uMattingColorRgba.b * (e - (1.0 - uPercent) * uIntensity) / (uPercent * uIntensity);
            origin.a = origin.a + uMattingColorRgba.a * (e - (1.0 - uPercent) * uIntensity) / (uPercent * uIntensity);
        }
//        float uIntensityPer = 0.6 * uIntensity / 200.0;//控制模糊补充颜色范围
//        if (uPercent > 0.0 && e - (1.0 - uIntensityPer * uPercent) * uIntensity > 0.0) {
//            float mattingColorRgbaPer = 1.3 * (e - (1.0 - uPercent) * uIntensity) / (uPercent * uIntensity);//控制模糊补色强度
//            if (mattingColorRgbaPer > 1.0) {
//                mattingColorRgbaPer = 1.0;
//            }
//            origin.r = origin.r + uMattingColorRgba.r * mattingColorRgbaPer;
//            origin.g = origin.g + uMattingColorRgba.g * mattingColorRgbaPer;
//            origin.b = origin.b + uMattingColorRgba.b * mattingColorRgbaPer;
//            origin.a = origin.a + uMattingColorRgba.a * mattingColorRgbaPer;
//        }
    }
    if (uAlphaPremultiplied == 1) {
        gl_FragColor = vec4(origin.rgb * origin.a, origin.a);
    } else {
        gl_FragColor = origin;
    }
}
