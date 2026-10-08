#ifdef GL_ES
precision highp  float;
#else
#define highp
#define mediump
#define lowp
#endif
varying vec2 texcoordOut;
uniform sampler2D s_texture;
uniform sampler2D overlay_texture;
uniform float alpha;

float SoftLight_Fcn(float A, float B)
{
	float C = 0.0;
	if (B <= 0.5)
	{
		C = A * B / 0.5 + A * A * ( 1.0 - 2.0 * B);
	}
	else
	{
		C = A * (1.0 - B) / 0.5 + sqrt(A) * (2.0 * B - 1.0);
	}
	
	return C;
}

void main()
{
	vec3 src_color = texture2D(s_texture, texcoordOut).rgb;
	vec3 overlay_color = texture2D(overlay_texture, texcoordOut).rgb;
	
	vec3 res_color;
	res_color.r = SoftLight_Fcn(src_color.r, overlay_color.r);
	res_color.g = SoftLight_Fcn(src_color.g, overlay_color.g);
	res_color.b = SoftLight_Fcn(src_color.b, overlay_color.b);
	
	gl_FragColor = vec4(mix(src_color, res_color, alpha), 1.0);
}