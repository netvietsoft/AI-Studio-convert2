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

uniform sampler2D s_texture;
varying vec2 v_texcoord;
varying vec2 v_texcoordOffset[8];

void main()
{
	vec4 res ;
	float tempMin = 1.0;
	float temp = 0.0;
	
	temp = texture2D(s_texture, v_texcoord).g;
	tempMin = min(temp , tempMin);
	res.r = tempMin;
	res.g = tempMin;
	res.b = tempMin;
	res.a = tempMin;
	
	if (tempMin == 0.0)
	{
		gl_FragColor = res;
		return ;
	}
	
	temp = texture2D(s_texture, v_texcoordOffset[3]).g;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[4]).g;
	tempMin = min(temp , tempMin);
	res.g = tempMin;
		
	temp = texture2D(s_texture, v_texcoordOffset[2]).g;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[5]).g;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[1]).g;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[6]).g;
	tempMin = min(temp , tempMin);
	res.b = tempMin;
	
	temp = texture2D(s_texture, v_texcoordOffset[0]).g;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[7]).g;
	tempMin = min(temp , tempMin);
	res.a = tempMin;
	
	gl_FragColor = res;
}


