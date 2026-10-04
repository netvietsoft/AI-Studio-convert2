// Function: MTFilterKernel::GPUImageGaussianBlurFilter::vertexShaderForOptimizedBlurOfRadius(int, float)
// RVA: 0x164930, Size: 1348 bytes
int64_t _ZN14MTFilterKernel26GPUImageGaussianBlurFilter36vertexShaderForOptimizedBlurOfRadiusEif(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    calloc(...); // call PLT API at 0x164970
    exp(...); // call PLT API at 0x1649a8
    exp(...); // call PLT API at 0x1649d8
    strlen(...); // call PLT API at 0x164a28
    calloc(...); // call PLT API at 0x164abc
    _Znam(...); // call PLT API at 0x164bd4
    const char* str = "         attribute vec4 position;
         attribute vec4 inputTextureCoordinate;
         
         uniform float texelWidthOff";
    sub_165FC4(...); // call internal at 0x164bf0
    const char* str = "%s                blurCoordinates[0] = inputTextureCoordinate.xy;
";
    sub_165FC4(...); // call internal at 0x164c08
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164c38
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164c6c
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164ca0
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164cd4
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164d08
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164d3c
    const char* str = "%s                    blurCoordinates[%lu] = inputTextureCoordinate.xy + singleStepOffset * %f;
                    blurCoordina";
    sub_165FC4(...); // call internal at 0x164d70
    const char* str = "%s                }
";
    sub_165FC4(...); // call internal at 0x164d88
    free(...); // call PLT API at 0x164d90
    free(...); // call PLT API at 0x164d98
    strlen(...); // call PLT API at 0x164da0
    _Znwm(...); // call PLT API at 0x164dd0
    memcpy(...); // call PLT API at 0x164df0
    _ZdaPv(...); // call PLT API at 0x164e18
    _Znwm(...); // call PLT API at 0x164e24
    memmove(...); // call PLT API at 0x164e44
    return a0;
    sub_C3100(...); // call internal at 0x164e70
}
