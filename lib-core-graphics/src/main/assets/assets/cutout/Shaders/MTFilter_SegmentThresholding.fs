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
varying vec2 v_texcoord;
uniform sampler2D s_texture;

uniform float u_threshold;

void main() {
	float gray = texture2D(s_texture,v_texcoord).g;
	float res = 0.0;
	if (gray >= u_threshold) {
		res = 1.0;//gray;//(gray - u_threshold)/(1.0 - u_threshold);
	}
	else {
		res = 0.0;
	}
	gl_FragColor = vec4(res,res,res,res);
}