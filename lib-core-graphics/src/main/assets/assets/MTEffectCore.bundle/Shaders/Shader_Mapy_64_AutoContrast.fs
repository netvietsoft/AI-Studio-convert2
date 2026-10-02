varying highp vec2 textureCoordinate; 
uniform sampler2D inputImageTexture;
uniform sampler2D faceMaskTexture;
uniform sampler2D mt_tempData1;
uniform lowp float alpha;
uniform highp float levelBlack;
uniform highp float levelRangeInv;
uniform highp float levelGamma;
uniform highp float default_levelBlack;
uniform highp float default_levelRangeInv;
uniform lowp float autoContrastAlpha;
uniform lowp float autoContrastAlphaForFace;

void main() {
    highp vec4 textureColor = texture2D(inputImageTexture, textureCoordinate);
    
    lowp float vFaceMask = texture2D(faceMaskTexture, textureCoordinate).r;
    highp vec3 color = clamp((textureColor.rgb - vec3(levelBlack, levelBlack, levelBlack)) * levelRangeInv, 0.0, 1.0);
    color=clamp(pow(color,vec3(levelGamma)),0.0,1.0);
    highp vec3 colorDefault = clamp((textureColor.rgb - vec3(default_levelBlack, default_levelBlack, default_levelBlack)) * default_levelRangeInv, 0.0, 1.0);
    color = mix(color, colorDefault, 0.8 * vFaceMask * autoContrastAlphaForFace);
    textureColor.rgb = mix(textureColor.rgb, color, autoContrastAlpha);
    
	highp float blueColor = textureColor.b * 63.0;
	highp vec2 quad1; 
	quad1.y = floor(floor(blueColor) / 8.0); 
	quad1.x = floor(blueColor) - (quad1.y * 8.0); 
	highp vec2 quad2; quad2.y = floor(ceil(blueColor) / 8.0); 
	quad2.x = ceil(blueColor) - (quad2.y * 8.0); 
	highp vec2 texPos1; 
	texPos1.x = (quad1.x * 0.125) + 0.5/512.0 + ((0.125 - 1.0/512.0) * textureColor.r); 
	texPos1.y = (quad1.y * 0.125) + 0.5/512.0 + ((0.125 - 1.0/512.0) * textureColor.g); 
	highp vec2 texPos2; texPos2.x = (quad2.x * 0.125) + 0.5/512.0 + ((0.125 - 1.0/512.0) * textureColor.r); 
	texPos2.y = (quad2.y * 0.125) + 0.5/512.0 + ((0.125 - 1.0/512.0) * textureColor.g); 
	lowp vec4 newColor1 = texture2D(mt_tempData1, texPos1);
	lowp vec4 newColor2 = texture2D(mt_tempData1, texPos2); 
	lowp vec4 newColor = mix(newColor1, newColor2, fract(blueColor)); 
	gl_FragColor = mix(textureColor, vec4(newColor.rgb, textureColor.w), alpha); 
}
