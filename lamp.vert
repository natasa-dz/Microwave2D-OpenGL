#version 330 core

// Define the input variables
layout(location = 0) in vec3 position;   // Position of the vertex
layout(location = 1) in vec2 texCoord;   // Texture coordinates for the texture mapping

// Output variables to the fragment shader
out vec2 TexCoord;    // Texture coordinates to pass to the fragment shader

void main()
{
    // Set the position of the vertex
    gl_Position = vec4(position, 1.0f);
    
    // Pass the texture coordinates to the fragment shader
    TexCoord = texCoord;
}
