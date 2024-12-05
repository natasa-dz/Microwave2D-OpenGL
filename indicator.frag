#version 330 core

out vec4 FragColor;

uniform float time;

void main() {
    float intensity = 0.5 - 0.5 * sin(time * 1.7);
    FragColor = vec4(intensity - 0.1, 0.0, 0.0, 1.0);
}



