uniform sampler2D inputTexture;
varying  vec2 mt_index;
varying  vec2 mt_CameraIndex;
uniform sampler2D mt_mask_0;
uniform sampler2D mt_mask_1;
uniform float height;
uniform float width;
uniform float alpha;
vec4 lut3d(highp vec4 textureColor)
{
    float blueColor = textureColor.b * 15.0;
    vec2 quad1;
    quad1.y = max(min(4.0,floor(floor(blueColor) / 4.0)),0.0);
    quad1.x = max(min(4.0,floor(blueColor) - (quad1.y * 4.0)),0.0);
    
    vec2 quad2;
    quad2.y = max(min(floor(ceil(blueColor) / 4.0),4.0),0.0);
    quad2.x = max(min(ceil(blueColor) - (quad2.y * 4.0),4.0),0.0);
    
    vec2 texPos1;
    texPos1.x = (quad1.x * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.r);
    texPos1.y = (quad1.y * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.g);
    
    vec2 texPos2;
    texPos2.x = (quad2.x * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.r);
    texPos2.y = (quad2.y * 0.25) + 0.5/64.0 + ((0.25 - 1.0/64.0) * textureColor.g);
    
    vec4 newColor1 = texture2D(mt_mask_0, texPos1);
    vec4 newColor2 = texture2D(mt_mask_0, texPos2);
    vec4 newColor = mix(newColor1, newColor2, fract(blueColor));
    return newColor;
}
void main(void)
{
    vec4 oral =texture2D(inputTexture, mt_CameraIndex);
    vec4 final =oral;
    vec4 ret ;
    float tx = 1.0 / height;
    float ty = 1.0 / width;

    vec3 gauss = 0.25*oral.rgb;
    gauss += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(-tx,0.0)).rgb;
    gauss += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(tx,0.0)).rgb;
    gauss += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(0.0,-ty)).rgb;
    gauss += 0.125*texture2D(inputTexture,mt_CameraIndex+vec2(0.0,ty)).rgb;
    gauss += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(tx,ty)).rgb;
    gauss += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(-tx,-ty)).rgb;
    gauss += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(-tx,ty)).rgb;
    gauss += 0.0625*texture2D(inputTexture,mt_CameraIndex+vec2(tx,-ty)).rgb;
    
    vec4 temp = vec4(0, 0, 0, 0);
    vec4 resultColor = vec4(0, 0, 0, 0);
    temp.rgb = (oral.rgb - gauss.rgb + 1.0)/float(2.0);
    resultColor.r = texture2D( mt_mask_1, vec2(temp.r,oral.r)).r;
    resultColor.g = texture2D( mt_mask_1, vec2(temp.g,oral.g)).g;
    resultColor.b = texture2D( mt_mask_1, vec2(temp.b,oral.b)).b;
    
    resultColor = lut3d(resultColor);
    
    resultColor.r = mix(oral.r,resultColor.r,alpha);
    resultColor.g = mix(oral.g,resultColor.g,alpha);
    resultColor.b = mix(oral.b,resultColor.b,alpha);
    
    gl_FragColor = resultColor;
}
