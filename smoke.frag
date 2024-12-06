#version 330 core

out vec4 FragColor;

uniform float time;  // Time value passed from the main program
uniform float flickerIntensity;  // Flicker effect strength
uniform vec3 objectColor;  // Color of the object (e.g., for smoke or the microwave light)

void main() {
    // Simulate flickering with a sine wave and some randomness
    float flicker = (sin(time * 10.0) + 1.0) * 0.5;
    flicker = mix(flicker, fract(sin(dot(gl_FragCoord.xy, vec2(12.9898, 78.233))) * 43758.5453) * 0.1, flickerIntensity);  // Random fluctuation for flickering
    
    // Apply the flickering effect
    FragColor = vec4(objectColor * flicker, 1.0);
}
