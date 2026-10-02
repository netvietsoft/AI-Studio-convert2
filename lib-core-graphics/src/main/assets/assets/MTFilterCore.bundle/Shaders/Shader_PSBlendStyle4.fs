uniform sampler2D inputTexture;
varying vec2 mt_index;
varying vec2 mt_CameraIndex;
uniform  sampler2D mt_mask_0;
uniform  sampler2D mt_mask_1;
uniform  sampler2D mt_mask_2;
uniform  sampler2D mt_mask_3;
uniform  sampler2D mt_mask_4;
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
void main()
{
    vec4 orgColor =texture2D(inputTexture, mt_CameraIndex);
    vec4 tempColor = orgColor;
    tempColor = lut3d(tempColor);
    vec4 temp = texture2D(mt_mask_1, mt_index); 
    temp.r=temp.r/temp.a;
    temp.g=temp.g/temp.a;
    temp.b=temp.b/temp.a;
    tempColor.r = mix(tempColor.r,texture2D( mt_mask_2, vec2(temp.r,tempColor.r)).r, temp.a);
    tempColor.g = mix(tempColor.g,texture2D( mt_mask_2, vec2(temp.g,tempColor.g)).g, temp.a);
    tempColor.b = mix(tempColor.b,texture2D( mt_mask_2, vec2(temp.b,tempColor.b)).b, temp.a);
    
    temp = texture2D(mt_mask_3, mt_index);
    temp.r=temp.r/temp.a;
    temp.g=temp.g/temp.a;
    temp.b=temp.b/temp.a;
    tempColor.r = mix(tempColor.r,texture2D( mt_mask_4, vec2(temp.r,tempColor.r)).r, temp.a);
    tempColor.g = mix(tempColor.g,texture2D( mt_mask_4, vec2(temp.g,tempColor.g)).g, temp.a);
    tempColor.b = mix(tempColor.b,texture2D( mt_mask_4, vec2(temp.b,tempColor.b)).b, temp.a);
    
    tempColor = mix(orgColor,tempColor,alpha);
    gl_FragColor = tempColor;
}
