#version 330 core

out vec4 FragColor;

uniform int lightState; // 0 = off (black), 1 = on (yellow)

void main() {
    if (lightState == 1) {
        FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f); // Yellow when light is on
    } else {
        FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f); // Black when light is off
    }
}
