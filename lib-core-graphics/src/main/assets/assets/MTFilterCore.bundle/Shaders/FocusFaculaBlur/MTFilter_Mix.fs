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
#define InputTexture0 texture
uniform sampler2D BlurResult;
#define InputTexture1 BlurResult
uniform sampler2D fabbyMask;

const float faceCount = 1.;
void main(void) 
{

    lowp vec4 blurResult = texture2D(InputTexture1,uv0);   
    lowp vec4 fgColor = texture2D(InputTexture0,uv0);
    lowp vec4 bgMask = texture2D(fabbyMask,uv0);
    lowp vec4 resultColor=fgColor;
    if(faceCount>0.1)
    {
        resultColor = vec4(mix(fgColor,blurResult,1. - bgMask.r).rgb,1.0);
    }

    gl_FragColor = resultColor;
}


