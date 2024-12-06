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
	DONE,		// Microwave is done with the task (finished)
	ERROR       // Microwave encountered an error (e.g., overheating or malfunction)
};

extern std::atomic<bool> isRunning;  // Atomic flag to check if the timer is running
extern std::atomic<bool> isPaused;  // Atomic flag to check if the timer is paused


// Struct to hold smoke properties
struct Smoke {
	float opacity; // Opacity of the smoke
	float positionY; // Position of the smoke (how high it is)

	void update() {
		opacity -= 0.01f; // Gradually reduce opacity to make it more transparent
		if (opacity < 0.0f) opacity = 0.0f; // Ensure opacity doesn't go below 0
		positionY += 0.02f; // Move the smoke upwards
	}
};

enum ButtonType {
	START,
	STOP,
	RESET
};

void breakMicrowaveAndStartSmoke(GLFWwindow* window, MicrowaveState& microwaveState, Smoke& smoke);
void handleMicrowaveLogic(GLFWwindow* window, MicrowaveState& microwaveState, DoorState& doorState,
	std::string& timer, bool& isLampOn);
void updateTimer(std::string& timer, int num);
//void countdownTimer(MicrowaveState& microwaveState, std::string& timer);
void countdownTimer(std::string& timer, MicrowaveState& microwaveState);
bool updateTimer(std::string& timer);

#endif