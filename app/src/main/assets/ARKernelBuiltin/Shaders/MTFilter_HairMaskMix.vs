attribute vec4 position;
attribute vec4 inputTextureCoordinate;
varying vec2 v_texCoord;

void main()
{
    gl_Position = position;
    v_texCoord = inputTextureCoordinate.xy;
}
