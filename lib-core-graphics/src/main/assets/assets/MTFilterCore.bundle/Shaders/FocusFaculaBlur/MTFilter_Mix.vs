#ifdef GL_ES
precision highp float;
#else
#define highp
#define mediump
#define lowp
#endif

attribute vec3 a_position;
attribute vec2 a_texCoord;
#define position a_position
#define texcoord a_texCoord

#define uv texcoord
varying vec2 uv0;
varying vec2 uv1;
void main()
{
	uv0 = uv.st;
    uv1 = uv;
    uv1.y = 1.0 - uv1.y;   
	gl_Position = vec4(position,1.0);
}
