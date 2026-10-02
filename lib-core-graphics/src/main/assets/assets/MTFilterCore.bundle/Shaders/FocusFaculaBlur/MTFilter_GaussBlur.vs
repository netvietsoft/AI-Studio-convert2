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
#define uv a_texCoord

varying vec2 uv0;

void main(void)
{
    gl_Position = vec4(position,1.0);
    uv0 = uv.st;
}
