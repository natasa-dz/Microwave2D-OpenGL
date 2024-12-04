﻿#ifndef SHADER_H
#define SHADER_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>


std::string get_file_contents(const char* filename);

class Shader
{
public:
	GLuint ID;

	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();
private:
	// Checks if the different Shaders have compiled properly
	void compileErrors(unsigned int shader, const char* type);
};

#endif