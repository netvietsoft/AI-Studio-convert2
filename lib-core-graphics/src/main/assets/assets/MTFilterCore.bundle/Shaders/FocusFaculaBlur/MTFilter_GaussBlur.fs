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
#define textureCoordinate uv0
uniform sampler2D texture;
#define inputImageTexture texture
uniform float type;
uniform float singleStepOffsetWidth;
uniform float singleStepOffsetHeight;

void main()
{
	mediump vec3 sum = texture2D(inputImageTexture, textureCoordinate).rgb;
	if (type > 0.0) {
		vec2 singleStepOffset = vec2(singleStepOffsetWidth, singleStepOffsetHeight);
		sum += texture2D(inputImageTexture, uv0 - singleStepOffset).rgb; 
		sum += texture2D(inputImageTexture, uv0 + singleStepOffset).rgb; 
		sum += texture2D(inputImageTexture, uv0 - 2.0 * singleStepOffset).rgb; 
		sum += texture2D(inputImageTexture, uv0 + 2.0 * singleStepOffset).rgb;
		gl_FragColor = vec4(sum * 0.20, 1.0); 
	} else {
		float alpha = sum.r;
		vec2 singleStepOffset = vec2(singleStepOffsetWidth, singleStepOffsetHeight) * (1.0 - alpha);
		sum += texture2D(inputImageTexture, uv0 - singleStepOffset).rgb; 
		sum += texture2D(inputImageTexture, uv0 + singleStepOffset).rgb; 
		sum += texture2D(inputImageTexture, uv0 - 2.0 * singleStepOffset).rgb; 
		sum += texture2D(inputImageTexture, uv0 + 2.0 * singleStepOffset).rgb;
		gl_FragColor = vec4(sum * 0.20, 1.0);
	}
}
