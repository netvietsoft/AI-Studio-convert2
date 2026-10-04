// Function: MTFilterKernel::GPUImageGaussianBlurFilter::vertexShaderForStandardBlurOfRadius(int, float)
// RVA: 0x165d88, Size: 572 bytes
int64_t _ZN14MTFilterKernel26GPUImageGaussianBlurFilter35vertexShaderForStandardBlurOfRadiusEif(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _Znam(...); // call PLT API at 0x165dc0
    const char* str = "                attribute vec4 position;
                attribute vec4 inputTextureCoordinate;
                
               ";
    sub_165FC4(...); // call internal at 0x165de0
    const char* str = "%s                        blurCoordinates[%ld] = inputTextureCoordinate.xy - singleStepOffset * %f;
";
    const char* str = "%s                        blurCoordinates[%ld] = inputTextureCoordinate.xy;
";
    const char* str = "%s                        blurCoordinates[%ld] = inputTextureCoordinate.xy + singleStepOffset * %f;
";
    sub_165FC4(...); // call internal at 0x165e30
    sub_165FC4(...); // call internal at 0x165e7c
    const char* str = "%s                }
";
    sub_165FC4(...); // call internal at 0x165ea4
    strlen(...); // call PLT API at 0x165eac
    strlen(...); // call PLT API at 0x165ee8
    _Znwm(...); // call PLT API at 0x165f18
    memcpy(...); // call PLT API at 0x165f38
    _ZdaPv(...); // call PLT API at 0x165f60
    _Znwm(...); // call PLT API at 0x165f6c
    memmove(...); // call PLT API at 0x165f8c
    return a0;
    sub_C3100(...); // call internal at 0x165fb8
    sub_C3100(...); // call internal at 0x165fc0
}
