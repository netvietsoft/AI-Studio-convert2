uniform sampler2D inputTexture;
varying  vec2 mt_index;
varying  vec2 mt_CameraIndex;
uniform  sampler2D mt_mask_0;
uniform float alpha;
lowp vec4 lut3d(highp vec4 textureColor)
{
    mediump float blueColor = textureColor.b * 15.0;
    mediump vec2 quad1;
    quad1.y = max(min(4.0,floor(floor(blueColor) / 4.0)),0.0);
    quad1.x = max(min(4.0,floor(blueColor) - (quad1.y * 4.0)),0.0);
    mediump vec2 quad2;
    quad2.y = max(min(floor(ceil(blueColor) / 4.0),4.0),0.0);
    quad2.x = max(min(ceil(blueColor) - (quad2.y * 4.0),4.0),0.0);
    highp vec2 texPos1;
    texPos1.x = (quad1.x * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.r);
    texPos1.y = (quad1.y * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.g);
    highp vec2 texPos2;
    texPos2.x = (quad2.x * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.r);
    texPos2.y = (quad2.y * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.g);
    lowp vec4 newColor1 = texture2D(mt_mask_0, texPos1);
    lowp vec4 newColor2 = texture2D(mt_mask_0, texPos2);
    mediump vec4 newColor = mix(newColor1, newColor2, fract(blueColor));
    return newColor;
}
void main(void)
{
    vec4 oral =texture2D(inputTexture, mt_CameraIndex);
    vec4 final =oral;
    vec4 ret ;
    float tx = 1.0 / float(852);
    float ty = 1.0 / float(640);

    vec3 sum = 0.25*oral.rgb;
    sum += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(-tx,0.0)).rgb;
    sum += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(tx,0.0)).rgb;
    sum += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(0.0,-ty)).rgb;
    sum += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(0.0,ty)).rgb;
    sum += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(tx,ty)).rgb;
    sum += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(-tx,-ty)).rgb;
    sum += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(-tx,ty)).rgb;
    sum += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(tx,-ty)).rgb;
    
    vec3 a = 1.0 - sum;
    a = oral.rgb + 2.0*a - 1.0;
    a = clamp(a, 0.0, 1.0);
    a = mix(a, oral.rgb, 0.5);
    vec3 flag = step(0.5, a);
    
    vec4 color;
    color.r = mix((2.0*a.x*final.r), (1.0-2.0*(1.0-a.x)*(1.0-final.r)), flag.x);
    color.g = mix((2.0*a.y*final.g), (1.0-2.0*(1.0-a.y)*(1.0-final.g)), flag.y);
    color.b = mix((2.0*a.z*final.b), (1.0-2.0*(1.0-a.z)*(1.0-final.b)), flag.z);
    color.a = 1.0;
    color = lut3d(color);
    ret = mix(final,color,alpha);

    gl_FragColor = ret;
}
