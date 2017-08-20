#version 330 
precision highp float;
in vec2 TexCoord;
out vec4 color;
uniform sampler2D gSampler;
float value;
void main() {
color =  texture2D(gSampler, TexCoord.xy); 
}