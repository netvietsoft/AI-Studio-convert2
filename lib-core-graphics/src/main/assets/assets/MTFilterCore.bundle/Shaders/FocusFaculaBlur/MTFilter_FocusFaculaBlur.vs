#ifdef GL_ES
precision highp float;
#else
#define highp
#define mediump
#define lowp
#endif

attribute vec3 a_position;
attribute vec2 a_texCoord;
varying vec2 v_texcoord;
void main()
{
	v_texcoord = a_texCoord.st; 
	gl_Position = vec4(a_position,1.0);
}
