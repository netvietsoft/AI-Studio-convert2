precision highp float;

uniform sampler2D u_mask;
uniform vec3 color;

varying vec2 v_texCoord;

void main(void)
{
    vec4 pen = texture2D(u_mask, v_texCoord);
    float alpha = 0.0;
    if (pen.r > 0.5) {
    	alpha = 1.0;
    }
    gl_FragColor = vec4(color, alpha);
}

