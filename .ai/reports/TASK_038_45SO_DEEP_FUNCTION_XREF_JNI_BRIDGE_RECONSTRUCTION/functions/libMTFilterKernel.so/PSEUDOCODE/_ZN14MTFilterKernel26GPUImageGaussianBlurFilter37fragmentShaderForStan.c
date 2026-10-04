// Function: MTFilterKernel::GPUImageGaussianBlurFilter::fragmentShaderForStandardBlurOfRadius(int, float)
// RVA: 0x166068, Size: 736 bytes
int64_t _ZN14MTFilterKernel26GPUImageGaussianBlurFilter37fragmentShaderForStandardBlurOfRadiusEif(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    calloc(...); // call PLT API at 0x1660ac
    exp(...); // call PLT API at 0x1660e4
    exp(...); // call PLT API at 0x166114
    strlen(...); // call PLT API at 0x166164
    _Znam(...); // call PLT API at 0x1661e0
    const char* str = "                uniform sampler2D inputImageTexture;
                
                varying highp vec2 blurCoordinates[%lu];
 ";
    sub_165FC4(...); // call internal at 0x166200
    const char* str = "%s                        sum += texture2D(inputImageTexture, blurCoordinates[%lu]) * %f;
";
    sub_165FC4(...); // call internal at 0x166238
    const char* str = "%s                gl_FragColor = sum;
                }
";
    sub_165FC4(...); // call internal at 0x16625c
    free(...); // call PLT API at 0x166264
    strlen(...); // call PLT API at 0x16626c
    const char* str = " mat4 ModelView; varying vec2 textureCoordinate; void main() { gl_Position = ModelView * position; textureCoordinate = inputText";
    _Znwm(...); // call PLT API at 0x16629c
    const char* str = "mat4 ModelView; varying vec2 textureCoordinate; void main() { gl_Position = ModelView * position; textureCoordinate = inputTextu";
    memcpy(...); // call PLT API at 0x1662bc
    _ZdaPv(...); // call PLT API at 0x1662e8
    _Znwm(...); // call PLT API at 0x1662f4
    memmove(...); // call PLT API at 0x166314
    return a0;
    sub_C3100(...); // call internal at 0x166344
}
