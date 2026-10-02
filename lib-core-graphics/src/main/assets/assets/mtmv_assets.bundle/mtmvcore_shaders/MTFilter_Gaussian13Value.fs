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
uniform sampler2D uTexture0;

const lowp int GAUSSIAN_SAMPLES = 13;

varying highp vec2 textureCoordinate;
varying highp vec2 blurCoordinates0;
varying highp vec2 blurCoordinates1;
varying highp vec2 blurCoordinates2;
varying highp vec2 blurCoordinates3;
varying highp vec2 blurCoordinates4;
varying highp vec2 blurCoordinates5;
varying highp vec2 blurCoordinates6;
varying highp vec2 blurCoordinates7;
varying highp vec2 blurCoordinates8;
varying highp vec2 blurCoordinates9;
varying highp vec2 blurCoordinates10;
varying highp vec2 blurCoordinates11;
varying highp vec2 blurCoordinates12;

uniform int uAlphaPremultiplied;
void main()
{
    vec4 src = texture2D(uTexture0, blurCoordinates6);
    //13x13
    highp vec4 sum = vec4(0.0);
    sum += texture2D(uTexture0, blurCoordinates0) * 0.046118;
    sum += texture2D(uTexture0, blurCoordinates1) * 0.058552;
    sum += texture2D(uTexture0, blurCoordinates2) * 0.071181;
    sum += texture2D(uTexture0, blurCoordinates3) * 0.082860;
    sum += texture2D(uTexture0, blurCoordinates4) * 0.092356;
    sum += texture2D(uTexture0, blurCoordinates5) * 0.098568;
    sum += texture2D(uTexture0, blurCoordinates6) * 0.100731;
    sum += texture2D(uTexture0, blurCoordinates7) * 0.098568;
    sum += texture2D(uTexture0, blurCoordinates8) * 0.092356;
    sum += texture2D(uTexture0, blurCoordinates9) * 0.082860;
    sum += texture2D(uTexture0, blurCoordinates10) * 0.071181;
    sum += texture2D(uTexture0, blurCoordinates11) * 0.058552;
    sum += texture2D(uTexture0, blurCoordinates12) * 0.046118;
    if (uAlphaPremultiplied == 0) {
        gl_FragColor = vec4(sum.rgb * sum.a, sum.a);
    }else {
        gl_FragColor = sum;
    }
}
