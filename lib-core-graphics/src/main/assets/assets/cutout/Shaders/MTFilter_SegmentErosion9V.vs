attribute vec3 a_position;
attribute vec2 a_texcoord;

uniform mat4 u_mvpMatrix;
uniform float u_singleStepOffset;
varying vec2 v_texcoord;
varying vec2 v_texcoordOffset[8];

void main(void)
{
    v_texcoordOffset[0] = a_texcoord + vec2(0.0,-4.0*u_singleStepOffset);
    v_texcoordOffset[1] = a_texcoord + vec2(0.0,-3.0*u_singleStepOffset);
    v_texcoordOffset[2] = a_texcoord + vec2(0.0,-2.0*u_singleStepOffset);
    v_texcoordOffset[3] = a_texcoord + vec2(0.0,-1.0*u_singleStepOffset);
    v_texcoordOffset[4] = a_texcoord + vec2(0.0,1.0*u_singleStepOffset);
    v_texcoordOffset[5] = a_texcoord + vec2(0.0,2.0*u_singleStepOffset);
    v_texcoordOffset[6] = a_texcoord + vec2(0.0,3.0*u_singleStepOffset);
    v_texcoordOffset[7] = a_texcoord + vec2(0.0,4.0*u_singleStepOffset);
    
	v_texcoord = a_texcoord;
	gl_Position = u_mvpMatrix * vec4(a_position, 1.0);
}
