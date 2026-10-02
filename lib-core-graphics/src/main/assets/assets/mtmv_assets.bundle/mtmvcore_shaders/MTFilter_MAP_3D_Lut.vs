#version 300 es

layout(location = 0) in vec4 aPosition;
layout(location = 1) in vec2 aTexCoord0;

out vec2 vTexCoord;

void main()
{
    gl_Position = aPosition;
    vTexCoord = aTexCoord0;
}
