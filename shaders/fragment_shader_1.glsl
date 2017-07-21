#version 330 
precision mediump float;
in float intensity_f;
void main() {
gl_FragColor = vec4 (intensity_f, intensity_f /2.0 , 0.0, 1.0);
}