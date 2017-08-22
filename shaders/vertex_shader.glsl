#version 330 
precision highp float;
layout(location=0) in vec3 position;
layout(location=1) in vec2 texCoord;
out vec2 TexCoord;
uniform mat4 mvpMatrix;
void main()
{
vec4 v = vec4(position,1.0f);
gl_Position = mvpMatrix * v;
TexCoord=texCoord;
}