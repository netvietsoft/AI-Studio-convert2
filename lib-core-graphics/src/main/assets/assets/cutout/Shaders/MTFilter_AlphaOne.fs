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
varying vec2 texcoordOut;
uniform sampler2D s_texture;

void main() {
	vec4 color = texture2D(s_texture,texcoordOut);
	gl_FragColor = vec4(color.rgb, 1.0);
}