#version 330 core

out vec4 FragColor;

uniform float time;  // Time value passed from the main program
uniform bool isMicrowaveRunning;  // Microwave running state

void main() {
    float brightness = 0.0;

    if (isMicrowaveRunning) {
        // Calculate pulsating brightness (oscillates between 0.0 and 1.0)
        brightness = (sin(time * 2.0) + 1.0) / 2.0;
    }

    // Set the color of the indicator to pulsate red (with brightness)
    FragColor = vec4(brightness, 0.0, 0.0, 1.0);  // Red channel pulsates, green and blue are 0
}
