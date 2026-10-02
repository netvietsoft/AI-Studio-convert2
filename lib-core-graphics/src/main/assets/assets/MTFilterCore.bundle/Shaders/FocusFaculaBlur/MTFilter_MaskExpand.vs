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
varying vec2 uv1;
//opt
varying vec2 textCoord[8];
uniform float textureWidth;
uniform float textureHeight;
uniform float radius;

void main(void)
{
    
    uv0 = uv.st;
    uv1 = uv;
    uv1.y = 1.0 - uv1.y;
    
    vec2 resolution = vec2(textureWidth,textureHeight);
    vec2 step = vec2(1.0)/resolution * abs(radius);
    vec2 step1 = vec2(1.0)/resolution * abs(radius) * (1.0/sqrt(2.0));
    textCoord[0] = uv0 + step * vec2(1.0,0.0);
    textCoord[1] = uv0 + step * vec2(-1.0,0.0);
    textCoord[2] = uv0 + step * vec2(0.0,1.0);
    textCoord[3] = uv0 + step * vec2(0.0,-1.0);
    
    textCoord[4] = uv0 + step1 * vec2(1.0,1.0);
    textCoord[5] = uv0 + step1 * vec2(-1.0,1.0);
    textCoord[6] = uv0 + step1 * vec2(1.0,-1.0);
    textCoord[7] = uv0 + step1 * vec2(-1.0,-1.0);
    gl_Position = vec4(position,1.0);
    
}
