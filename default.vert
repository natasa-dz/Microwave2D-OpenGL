#version 330 core

layout (location = 0) in vec2 aPos;   // Vertex positions
layout (location = 1) in vec3 aColor; // Vertex colors (not used here)
layout (location = 2) in vec2 aTex;   // Texture coordinates

out vec2 texCoord;

uniform float scale;

void main()
{
	gl_Position = vec4(aPos, 0.0, 1.0);

    texCoord = aTex; // Pass texture coordinates to the fragment shader
}