// Function: MTFilterKernel::GPUImageGaussianBlurFilter::fragmentShaderForOptimizedBlurOfRadius(int, float)
// RVA: 0x164e74, Size: 1424 bytes
int64_t _ZN14MTFilterKernel26GPUImageGaussianBlurFilter38fragmentShaderForOptimizedBlurOfRadiusEif(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    calloc(...); // call PLT API at 0x164eb8
    exp(...); // call PLT API at 0x164ef0
    exp(...); // call PLT API at 0x164f20
    strlen(...); // call PLT API at 0x164f70
    _Znam(...); // call PLT API at 0x165000
    const char* str = "         uniform sampler2D inputImageTexture;
         uniform highp float texelWidthOffset;
         uniform highp float texelH";
    sub_165FC4(...); // call internal at 0x16501c
    const char* str = "%s                sum += texture2D(inputImageTexture, blurCoordinates[0]) * %f;
";
    sub_165FC4(...); // call internal at 0x16503c
    const char* str = "%s                    sum += texture2D(inputImageTexture, blurCoordinates[%lu]) * %f;
";
    sub_165FC4(...); // call internal at 0x165070
    sub_165FC4(...); // call internal at 0x16508c
    sub_165FC4(...); // call internal at 0x1650bc
    sub_165FC4(...); // call internal at 0x1650d8
    sub_165FC4(...); // call internal at 0x165108
    sub_165FC4(...); // call internal at 0x165124
    sub_165FC4(...); // call internal at 0x165154
    sub_165FC4(...); // call internal at 0x165170
    sub_165FC4(...); // call internal at 0x1651a0
    sub_165FC4(...); // call internal at 0x1651bc
    sub_165FC4(...); // call internal at 0x1651ec
    sub_165FC4(...); // call internal at 0x165208
    sub_165FC4(...); // call internal at 0x165238
    sub_165FC4(...); // call internal at 0x165254
    const char* str = "%s                    highp vec2 singleStepOffset = vec2(texelWidthOffset, texelHeightOffset);
";
    sub_165FC4(...); // call internal at 0x165274
    const char* str = "%s                        sum += texture2D(inputImageTexture, blurCoordinates[0] + singleStepOffset * %f) * %f;
";
    const char* str = "%s                        sum += texture2D(inputImageTexture, blurCoordinates[0] - singleStepOffset * %f) * %f;
";
    sub_165FC4(...); // call internal at 0x1652d8
    sub_165FC4(...); // call internal at 0x1652f4
    const char* str = "%s                gl_FragColor = sum;
                }
";
    sub_165FC4(...); // call internal at 0x165318
    free(...); // call PLT API at 0x165320
    strlen(...); // call PLT API at 0x165328
    const char* str = "ure2D(inputImageTexture, textureShift_2.zw).rgb; sum += texture2D(inputImageTexture, textureShift_3.xy).rgb; sum += texture2D(in";
    _Znwm(...); // call PLT API at 0x165358
    const char* str = "re2D(inputImageTexture, textureShift_2.zw).rgb; sum += texture2D(inputImageTexture, textureShift_3.xy).rgb; sum += texture2D(inp";
    memcpy(...); // call PLT API at 0x165378
    _ZdaPv(...); // call PLT API at 0x1653a4
    const char* str = "ure2D(inputImageTexture, textureShift_2.zw).rgb; sum += texture2D(inputImageTexture, textureShift_3.xy).rgb; sum += texture2D(in";
    _Znwm(...); // call PLT API at 0x1653b0
    const char* str = "re2D(inputImageTexture, textureShift_2.zw).rgb; sum += texture2D(inputImageTexture, textureShift_3.xy).rgb; sum += texture2D(inp";
    memmove(...); // call PLT API at 0x1653d0
    return a0;
    sub_C3100(...); // call internal at 0x165400
}
