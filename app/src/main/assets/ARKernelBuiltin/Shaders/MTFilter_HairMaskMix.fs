#ifdef GL_ES
precision highp float;
#else
#define highp
#define mediump
#define lowp
#endif

varying vec2 v_texCoord;
uniform sampler2D texturesrc;   // Raw hair mask (Channel R)
uniform sampler2D textureblack; // Exclusion mask (Channel R / G)

void main()
{
    vec4 src = texture2D(texturesrc, v_texCoord);
    vec4 black = texture2D(textureblack, v_texCoord);
    float blackvalue = 1.0 - black.r;
    float val = src.r;
    if (black.r > 0.0)
    {
        if (src.r > blackvalue)
        {
            val = blackvalue;
        }
    }
    gl_FragColor = vec4(val, val, val, val);
}
