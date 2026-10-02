#ifdef GL_ES//for discriminate GLES & GL
#ifdef GL_FRAGMENT_PRECISION_HIGH
precision highp float;
#else
precision mediump float;
#endif
#else
#define highp
#define mediump
#define lowp
#endif

varying vec2 uv0;
varying vec2 uv1;
//opt
#define SUMPLE_NUM 8
varying vec2 textCoord[SUMPLE_NUM];

uniform sampler2D fabbyMask;
#define BG_MASK fabbyMask
#define textureCoordinate uv0
uniform float radius;

void main()
{
    if (radius > 0.0) {
        lowp vec4 outColor= texture2D(BG_MASK,uv0);
        
        lowp float color[SUMPLE_NUM];
        // float weight[4];
        color[0] = texture2D(BG_MASK,textCoord[0]).r;
        color[1] = texture2D(BG_MASK,textCoord[1]).r;
        color[2] = texture2D(BG_MASK,textCoord[2]).r;
        color[3] = texture2D(BG_MASK,textCoord[3]).r;
        color[4] = texture2D(BG_MASK,textCoord[4]).r;
        color[5] = texture2D(BG_MASK,textCoord[5]).r;
        color[6] = texture2D(BG_MASK,textCoord[6]).r;
        color[7] = texture2D(BG_MASK,textCoord[7]).r;
        
        lowp float max_color =max(max(max(color[0],color[1]),max(color[2],color[3])),
                                  max(max(color[4],color[5]),max(color[6],color[7])));
        max_color =max(max_color,outColor.r);
        
        gl_FragColor= vec4(max_color);
    } else {
        lowp vec4 outColor= texture2D(BG_MASK,uv0);
        
        lowp float color[SUMPLE_NUM];
        // float weight[4];
        color[0] = texture2D(BG_MASK,textCoord[0]).r;
        color[1] = texture2D(BG_MASK,textCoord[1]).r;
        color[2] = texture2D(BG_MASK,textCoord[2]).r;
        color[3] = texture2D(BG_MASK,textCoord[3]).r;
        
        color[4] = texture2D(BG_MASK,textCoord[4]).r;
        color[5] = texture2D(BG_MASK,textCoord[5]).r;
        color[6] = texture2D(BG_MASK,textCoord[6]).r;
        color[7] = texture2D(BG_MASK,textCoord[7]).r;
        
        lowp float min_color =min(min(min(color[0],color[1]),min(color[2],color[3])),
                                  min(min(color[4],color[5]),min(color[6],color[7])));
        min_color =min(min_color,outColor.r);
        
        gl_FragColor= vec4(min_color);
    }
}
