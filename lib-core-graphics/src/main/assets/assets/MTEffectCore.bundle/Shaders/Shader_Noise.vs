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

attribute highp vec3 position;
attribute highp vec2 texcoord;
varying highp vec2 vTexcoord;
varying highp vec2 vEffectCoord;
uniform highp vec2 effectCenter;
uniform float textureWidth;
uniform float textureHeight;
void main() {
	vec2 aspectRatioCorrection = vec2(textureWidth/textureHeight,1.0);
	vTexcoord = texcoord;
	vEffectCoord = (vTexcoord - effectCenter)*aspectRatioCorrection;
	gl_Position = vec4(position,1.0);
}