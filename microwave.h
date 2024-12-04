#ifndef MICROWAVE_H
#define MICROWAVE_H

#include <GL/glew.h>    // Include GLEW first
#include <GLFW/glfw3.h>  // GLFW or other OpenGL-related libraries
#include <GL/gl.h> 
#include "door.h"

enum class MicrowaveState {
	IDLE,       // Microwave is on but not running (e.g., waiting for user input)
	COOKING,    // Microwave is actively cooking
	PAUSED,     // Microwave cooking is paused
	ERROR       // Microwave encountered an error (e.g., overheating or malfunction)
};

enum ButtonType {
	START,
	STOP,
	RESET
};
void checkButtonClick(GLFWwindow* window, MicrowaveState& microwaveState, DoorState doorState);
void keypadPressed(GLFWwindow* window);

#endif