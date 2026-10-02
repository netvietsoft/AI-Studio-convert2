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

#define INTENSITY_POWER     10.3
#define luminanceWeighting      vec3(0.2125, 0.7154, 0.0721)
#define PI              3.1415927
varying vec2 v_texcoord;
#define textureCoordinate v_texcoord
uniform sampler2D inputImage;
uniform sampler2D diaphragmImage;
uniform sampler2D maskResult;

uniform highp float imageheight;
uniform highp float imagewidth; //
uniform highp float maskradius; //素材的宽
uniform highp float farDepth;   //0.496911
uniform highp float nearDepth;  //1.0
uniform highp float farRadius;  //0.0
uniform highp float nearRadius; //12.5
uniform highp float highlights; //高光 0-1.0
uniform highp float vivid;      //鲜艳 0-1.0
uniform highp float mattebox;   //0.0

const highp vec3 W = vec3(0.2125, 0.7154, 0.0721);
highp float make_highlights_vivid(highp vec4 sampleColor, highp float highlights, highp float vivid)
{
    highp float maxColor = max(max(sampleColor.r, sampleColor.g), sampleColor.b);
    highp float minColor = min(min(sampleColor.r, sampleColor.g), sampleColor.b);
    
    highp float gray = 0.2                                    // basic weight for black color
    + maxColor                              // weight of lightness
    + (maxColor - minColor) * vivid         // weight of saturation
    + smoothstep(0.92, 1.0, maxColor);      // weight of exposure bias
    return exp(1.0 + gray * highlights) * 0.01;
}

void main()
{
    
    lowp float alpha_mask = 1.0 - texture2D(maskResult,textureCoordinate).r;
    highp vec4 sampleColor = texture2D(inputImage, textureCoordinate);
    if(alpha_mask > 0.01)
    {
        alpha_mask=clamp(pow(alpha_mask,1.0/2.0),0.0,1.0);
        
        highp vec2 inputSize = vec2(imagewidth,imageheight);
        
        highp float centerDepth = sampleColor.a;//alpha_mask;
        highp vec2 destCoord = vec2(textureCoordinate.x*imagewidth,textureCoordinate.y*imageheight);
        
        highp float extraDepth = 0.0;
        
        
        highp float nearIntensity = nearRadius / max(farRadius, nearRadius);
        highp float farIntensity = farRadius / max(farRadius, nearRadius);
        highp float intensityScale = (nearIntensity - farIntensity) * float((centerDepth - extraDepth) - farDepth) / float(nearDepth - farDepth) + farIntensity;
        
        highp float highlight = pow(highlights, 0.5) * intensityScale * 4.0;
        intensityScale = pow(intensityScale, INTENSITY_POWER);
        
        highp float radius = maskradius;
        highp float centralIndex = ((radius - 1.0) / 2.0);
        highp float centralScale = floor(centralIndex * intensityScale + 0.5);
        highp float radiusScale = 1.0 / intensityScale;
        
        highp float intensityMulti = (nearIntensity - farIntensity) / (nearDepth - farDepth);
        highp float matteCentral = centralIndex * (1.0 + mattebox * 0.1);
        
        // mattebox clipping bounds
        highp vec4 render_bounds;
        
        render_bounds = vec4(-centralScale, -centralScale, centralScale, centralScale);
        
        highp vec3 sum = vec3(0.0);
        highp vec3 gaussianWeight;
        highp vec3 gaussianWeightTotal = vec3(0.0);
        highp float curDepth;
        highp float matteCentral2 = pow(matteCentral / radiusScale, 2.0);
        
        for (highp float i = render_bounds.y; i <= render_bounds.w; i ++)
        {
            highp float space = floor(sqrt(max(0.0, matteCentral2 - i * i)));
            highp float left = max(render_bounds.x, -space);
            highp float right = min(render_bounds.z, space);
            for (highp float j = left; j <= right; j++)
            {
                highp vec2 coordinate = destCoord + vec2(j, -i) * alpha_mask;
                sampleColor = texture2D(inputImage, vec2(coordinate.x/imagewidth,coordinate.y/imageheight));
                curDepth = sampleColor.a;//texture2D(maskResult, vec2(coordinate.x/imagewidth,coordinate.y/imageheight)).a;
                highp float depthIntensity = intensityMulti * ((curDepth - extraDepth) - farDepth) + farIntensity;
                depthIntensity = pow(depthIntensity, INTENSITY_POWER);
                
                highp vec2 offset = vec2(j, i) * radiusScale;
                offset *= intensityScale / (depthIntensity + 0.0001);
                
                gaussianWeight = texture2D(diaphragmImage, (offset + vec2(centralIndex))/maskradius).rgb;
                gaussianWeight *= make_highlights_vivid(sampleColor, highlight, vivid);
                sum += sampleColor.rgb * gaussianWeight;
                gaussianWeightTotal += gaussianWeight;
            }
        }
        
        sampleColor = texture2D(inputImage, textureCoordinate);
        sum = sum / max(gaussianWeightTotal, vec3(0.001));
        sum = mix(sampleColor.rgb, sum, step(vec3(0.001), gaussianWeightTotal.rgb));
        
        if (vivid > 0.0)
        {
            highp float saturation = 1.0 + vivid * intensityScale * 0.3;
            highp float luminance = dot(sum, luminanceWeighting);
            sum = mix(vec3(luminance), sum, saturation);
        }
        
        sum = clamp(sum, vec3(0.0), vec3(1.0));
        sampleColor = vec4(sum*1.0, min(1.0, centralIndex * intensityScale));
    }
    
    gl_FragColor = sampleColor;//vec4(alpha_mask, alpha_mask, alpha_mask, 1.0);
}


