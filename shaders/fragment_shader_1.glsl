#version 330 
precision highp float;
in float intensity_f;
in vec2 TexCoord;
out vec4 color;
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
float value;
void main() {

	color = mix(texture(ourTexture1, TexCoord), texture(ourTexture2, TexCoord),intensity_f);
	
}