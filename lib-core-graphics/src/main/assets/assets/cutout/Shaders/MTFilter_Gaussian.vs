attribute vec3 a_position;
attribute vec2 a_texcoord;
varying vec2 v_texcoord;

uniform mat4 u_mvpMatrix;

uniform float u_singleStepOffset;
varying vec2 v_texcoordOffset[8];

#ifdef MEITU_USE_MASK_TEXTURE
attribute vec2 a_maskTexcoord;
varying vec2 v_maskTexcoord;
#endif

void main() {
	v_texcoord = a_texcoord;
	gl_Position = u_mvpMatrix * vec4(a_position, 1.0);
#ifdef MEITU_HORIZONTAL_GAUSSIAN
    v_texcoordOffset[0] = v_texcoord + vec2(-4.0*u_singleStepOffset,0.0);
    v_texcoordOffset[1] = v_texcoord + vec2(-3.0*u_singleStepOffset,0.0);
    v_texcoordOffset[2] = v_texcoord + vec2(-2.0*u_singleStepOffset,0.0);
    v_texcoordOffset[3] = v_texcoord + vec2(-1.0*u_singleStepOffset,0.0);
    v_texcoordOffset[4] = v_texcoord + vec2(1.0*u_singleStepOffset,0.0);
    v_texcoordOffset[5] = v_texcoord + vec2(2.0*u_singleStepOffset,0.0);
    v_texcoordOffset[6] = v_texcoord + vec2(3.0*u_singleStepOffset,0.0);
    v_texcoordOffset[7] = v_texcoord + vec2(4.0*u_singleStepOffset,0.0);
#else // MEITU_VERTICAL_GAUSSIAN
    v_texcoordOffset[0] = v_texcoord + vec2(0.0,-4.0*u_singleStepOffset);
    v_texcoordOffset[1] = v_texcoord + vec2(0.0,-3.0*u_singleStepOffset);
    v_texcoordOffset[2] = v_texcoord + vec2(0.0,-2.0*u_singleStepOffset);
    v_texcoordOffset[3] = v_texcoord + vec2(0.0,-1.0*u_singleStepOffset);
    v_texcoordOffset[4] = v_texcoord + vec2(0.0,1.0*u_singleStepOffset);
    v_texcoordOffset[5] = v_texcoord + vec2(0.0,2.0*u_singleStepOffset);
    v_texcoordOffset[6] = v_texcoord + vec2(0.0,3.0*u_singleStepOffset);
    v_texcoordOffset[7] = v_texcoord + vec2(0.0,4.0*u_singleStepOffset);
#endif
}

