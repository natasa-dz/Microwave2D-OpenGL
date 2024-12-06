#ifndef MAIN_H
#define MAIN_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../libraries/include/stb//stb_image.h"

#include "shader.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Texture.h"
#include "door.h"
#include "microwave.h"
#include "text.h"


struct MousePosition {
    float x;
    float y;
};
extern MousePosition mousePos;

extern int windowWidth;
extern int windowHeight;

// aspect ratios and scale factors

extern float scale;

extern float microwaveAspect;
extern float microwaveWidth;
extern float microwaveHeight;

extern float plateAspect;
extern float plateWidth;
extern float plateHeight;
//
extern float doorWidth;
extern float doorHeight;

//indices and vertices
extern GLfloat controlPanelVertices[];
extern GLfloat plateVertices[];
extern GLfloat doorVertices[];

extern GLuint microwaveIndices[];
extern GLuint plateIndices[];
extern GLuint doorIndices[];


// functions 
void mouseCallback(GLFWwindow* window, double mouseX, double mouseY);

#endif // MAIN_H