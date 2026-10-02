attribute vec3 a_position;
attribute vec2 a_texcoord;
varying vec2 texcoordOut;
uniform mat4 u_mvpMatrix;

void main()
{
	texcoordOut = a_texcoord;
	gl_Position = u_mvpMatrix * vec4(a_position,1.0);
}