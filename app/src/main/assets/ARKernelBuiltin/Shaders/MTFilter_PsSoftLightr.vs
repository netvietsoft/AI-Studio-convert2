attribute vec4 position;
attribute vec4 texcoord;
varying vec2 texcoordOut;

void main()
{
    gl_Position = position;
    texcoordOut = texcoord.xy;
}
