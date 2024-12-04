// DoorState.h
#ifndef DOOR_H
#define DOOR_H

#include <GL/glew.h>    // Include GLEW first
#include <GLFW/glfw3.h>  // GLFW or other OpenGL-related libraries
#include <GL/gl.h> 

enum class MicrowaveState;

enum class DoorState {
    OPEN,       
    CLOSED,     
    OPENING,
	CLOSING 
};

float updateDoorState(GLFWwindow* window, float doorOffset, DoorState& doorState, float& doorAnimationTime, MicrowaveState& microwaveState);

#endif // DOOR_H
