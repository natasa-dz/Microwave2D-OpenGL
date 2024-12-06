#version 330 core

in vec2 texCoord;
out vec4 FragColor;

uniform sampler2D text;
uniform vec3 textColor;

void main() {
    float alpha = texture(text, texCoord).r;
    FragColor = vec4(textColor, alpha);
}