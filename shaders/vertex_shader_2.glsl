#version 330 
precision highp float;
layout(location=0) in vec3 position;
uniform mat4 mvpMatrix;
void main()
{
vec4 v = vec4(position,1.0f);
gl_Position = mvpMatrix * v;
}