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
	float tempMin = 1.0;
	float temp ;
	
	temp = texture2D(s_texture, v_texcoord).a;
	tempMin = min(temp , tempMin);
	
	if (tempMin == 0.0)
	{
		gl_FragColor = vec4(tempMin,tempMin,tempMin,tempMin);
		return ;
	}
	
	temp = texture2D(s_texture, v_texcoordOffset[3]).b;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[4]).b;
	tempMin = min(temp , tempMin);
	
	temp = texture2D(s_texture, v_texcoordOffset[2]).b;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[5]).b;
	tempMin = min(temp , tempMin);
	
	temp = texture2D(s_texture, v_texcoordOffset[1]).g;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[6]).g;
	tempMin = min(temp , tempMin);
	
	temp = texture2D(s_texture, v_texcoordOffset[0]).r;
	tempMin = min(temp , tempMin);
	temp = texture2D(s_texture, v_texcoordOffset[7]).r;
	tempMin = min(temp , tempMin);
	
	gl_FragColor = vec4(tempMin,tempMin,tempMin,tempMin);
	
}


