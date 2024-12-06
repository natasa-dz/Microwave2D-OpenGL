#ifndef VBO_H
#define VBO_H

#include <GL/glew.h>

class VBO
{
public:
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO(GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();

	VBO();
};

#endif