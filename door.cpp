#include "door.h"
#include "main.h"
#include "microwave.h"

float updateDoorState(GLFWwindow* window, float doorOffset, DoorState& doorState, float& doorAnimationTime, MicrowaveState& microwaveState) {

	if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS && doorState == DoorState::CLOSED) {
        doorState = DoorState::OPENING;

        if (microwaveState == MicrowaveState::COOKING)
            microwaveState = MicrowaveState::PAUSED;
        doorAnimationTime = 0.0f;

    } else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS && doorState == DoorState::OPEN) {

        doorState = DoorState::CLOSING;
        doorAnimationTime = 0.0f;
    }

    if (doorState == DoorState::OPENING || doorState == DoorState::CLOSING) {

        doorAnimationTime += 0.3f;
        doorOffset = (doorState == DoorState::OPENING) ? doorAnimationTime : 1.0f - doorAnimationTime;

        if (doorOffset >= 1.0f) {
            doorOffset = 1.0f;
            doorState = DoorState::OPEN;
        }
        else if (doorOffset <= 0.0f) {
            doorOffset = 0.0f;
            doorState = DoorState::CLOSED;
        }
    }

    return doorOffset;
}

