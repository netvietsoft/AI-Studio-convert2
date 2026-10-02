uniform sampler2D inputTexture;
varying vec2 mt_index;
varying vec2 mt_CameraIndex;
uniform sampler2D mt_mask_0;
uniform float alpha;

void main(void)
{
    vec4 oralData = texture2D(inputTexture,mt_CameraIndex);
    vec4 temp = oralData;
    vec2 arbr=vec2(oralData.r,0.5);
    oralData.r = texture2D(mt_mask_0,arbr).r;
    arbr=vec2(oralData.g,0.5);
    oralData.g = texture2D(mt_mask_0,arbr).g;
    arbr=vec2(oralData.b,0.5);
    oralData.b = texture2D(mt_mask_0,arbr).b;
    oralData = mix(temp,oralData,alpha);
    gl_FragColor = oralData;
}
