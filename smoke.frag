﻿#version 330 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D tex0;
uniform float opacity;

void main()
{
    vec4 texColor = texture(tex0, texCoord);
    if(texColor.a < 0.01)
		discard;
    texColor.a = opacity;
    FragColor = texColor;
}