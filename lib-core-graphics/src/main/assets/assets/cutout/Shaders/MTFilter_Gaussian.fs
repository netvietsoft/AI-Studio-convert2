#ifdef MEITU_USE_GL_EXT_shader_framebuffer_fetch
#extension GL_EXT_shader_framebuffer_fetch : require
#endif
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

#ifndef MEITU_GAUSSIAN_RADIUS
#define MEITU_GAUSSIAN_RADIUS 9
#endif

varying vec2 v_texcoord;
uniform sampler2D s_texture;
varying vec2 v_texcoordOffset[8];

#ifndef MEITU_MASK_CHANNEL
#define MEITU_MASK_CHANNEL(x) ((x).r)
#endif

#ifdef MEITU_USE_MASK_TEXTURE
varying vec2 v_maskTexcoord;
uniform sampler2D s_maskTexture;
#endif

#if MEITU_GAUSSIAN_RADIUS == 9 
vec4 gauss() {
	vec4 sum = vec4(0.0);
	//9x9
	sum += texture2D(s_texture, v_texcoordOffset[0]) * 0.05;
	sum += texture2D(s_texture, v_texcoordOffset[1]) * 0.09;
	sum += texture2D(s_texture, v_texcoordOffset[2]) * 0.12;
	sum += texture2D(s_texture, v_texcoordOffset[3]) * 0.15;
	sum += texture2D(s_texture, v_texcoord) * 0.18;
	sum += texture2D(s_texture, v_texcoordOffset[4]) * 0.15;
	sum += texture2D(s_texture, v_texcoordOffset[5]) * 0.12;
	sum += texture2D(s_texture, v_texcoordOffset[6]) * 0.09;
	sum += texture2D(s_texture, v_texcoordOffset[7]) * 0.05;
	return sum;
}
#elif MEITU_GAUSSIAN_RADIUS == 7
vec4 gauss() {
	vec4 sum = vec4(0.0);
	//7x7
	//sum += texture2D(s_texture, v_texcoordOffset[0]) * 0.0;
	sum += texture2D(s_texture, v_texcoordOffset[1]) * 0.10;
	sum += texture2D(s_texture, v_texcoordOffset[2]) * 0.13;
	sum += texture2D(s_texture, v_texcoordOffset[3]) * 0.17;
	sum += texture2D(s_texture, v_texcoord) * 0.20;
	sum += texture2D(s_texture, v_texcoordOffset[4]) * 0.17;
	sum += texture2D(s_texture, v_texcoordOffset[5]) * 0.13;
	sum += texture2D(s_texture, v_texcoordOffset[6]) * 0.10;
	//sum += texture2D(s_texture, v_texcoordOffset[7]) * 0.0;
	return sum;
}
#elif MEITU_GAUSSIAN_RADIUS == 5
vec4 gauss() {
	vec4 sum = vec4(0.0);
	//5x5
	//sum += texture2D(s_texture, v_texcoordOffset[0]) * 0.0;
	//sum += texture2D(s_texture, v_texcoordOffset[1]) * 0.0;
	sum += texture2D(s_texture, v_texcoordOffset[2]) * 0.06542;
	sum += texture2D(s_texture, v_texcoordOffset[3]) * 0.24299;
	sum += texture2D(s_texture, v_texcoord) * 0.38318;
	sum += texture2D(s_texture, v_texcoordOffset[4]) * 0.24299;
	sum += texture2D(s_texture, v_texcoordOffset[5]) * 0.06542;
	//sum += texture2D(s_texture, v_texcoordOffset[6]) * 0.0;
	//sum += texture2D(s_texture, v_texcoordOffset[7]) * 0.0;
	return sum;
}
#elif MEITU_GAUSSIAN_RADIUS == 3
vec4 gauss() {
	vec4 sum = vec4(0.0);
	//3x3
	//sum += texture2D(s_texture, v_texcoordOffset[0]) * 0.0;
	//sum += texture2D(s_texture, v_texcoordOffset[1]) * 0.0;
	//sum += texture2D(s_texture, v_texcoordOffset[2]) * 0.0;
	sum += texture2D(s_texture, v_texcoordOffset[3]) * 0.25;
	sum += texture2D(s_texture, v_texcoord) * 0.5;
	sum += texture2D(s_texture, v_texcoordOffset[4]) * 0.25;
	//sum += texture2D(s_texture, v_texcoordOffset[5]) * 0.0;
	//sum += texture2D(s_texture, v_texcoordOffset[6]) * 0.0;
	//sum += texture2D(s_texture, v_texcoordOffset[7]) * 0.0;	
	return sum;
}
#endif

void main() {
    vec4 resultColor = gauss();
#ifdef MEITU_USE_MASK_TEXTURE
    vec4 sourceColor = texture2D(s_texture, v_texcoord);
	float factor = MEITU_MASK_CHANNEL(texture2D(s_maskTexture,v_maskTexcoord));
	gl_FragColor = vec4(mix(sourceColor.rgb, resultColor.rgb, factor), 1.0);
#else
    gl_FragColor = resultColor;
#endif
}


