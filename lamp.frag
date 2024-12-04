#version 330 core
in vec3 vertexColor;
in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D tex2; // The texture to display (light on)
uniform sampler2D tex3; // The texture when light is off

void main() {
    // Calculate the distance from the center of the texture coordinates
    float dist = distance(TexCoord, vec2(0.5, 0.5)); // (0.5, 0.5) is the center

    // If the distance is greater than the radius, make it transparent (mask the texture)
    if (dist > 0.5) {
        discard;  // Discard fragments outside the circle (i.e., transparency)
    }

    // Otherwise, sample the texture and show the circular part
    vec4 texColor = texture(tex2, TexCoord);

    // You can also apply the off texture if needed based on some condition
    if (texColor.a < 0.1) { // For example, if texture is too transparent, use the off texture
        texColor = texture(tex3, TexCoord);
    }

    FragColor = texColor; // Output the final color
}
