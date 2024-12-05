#include <iostream>
#include "microwave.h"
#include "main.h"
#include <vector>  // Include this header for std::vector
#include <thread>  // Include the thread header to use std::this_thread::sleep_for
#include <GLFW/glfw3.h>  // Make sure GLFW is included here


struct Button {
    std::string label;
    float xMin, xMax, yMin, yMax; // Bounding box in NDC
};


Smoke smoke = { 1.0f, -0.1f }; // Starting with full opacity and near the microwave

std::vector<Button> buttons = {
    {"1", 0.44f, 0.47f, -0.08f, -0.04f},  // Button 1
    {"2", 0.49f, 0.51f, -0.08f, -0.04f},  // Button 2
    {"3", 0.55f, 0.57f, -0.08f, -0.04f},  // Button 3
    {"4", 0.44f, 0.46f, -0.1f, -0.084f},  // Button 4
    {"5", 0.49f, 0.53f, -0.12f, -0.10f},  // Button 5
    {"6", 0.55f, 0.57f, -0.107f, -0.08f},  // Button 6
    {"7", 0.44f, 0.46f, -0.15f, -0.13f},  // Button 7
    {"8", 0.49f, 0.52f, -0.15f, -0.125f},  // Button 8
    {"9", 0.55f, 0.57f, -0.16f, -0.12f},  // Button 9
    {"0", 0.49f, 0.51f, -0.2f, -0.166f},  // Button 0
    {"START", 0.53f, 0.63f, -0.28f, -0.21f},  // Start Button
    {"STOP", 0.43f, 0.5f, -0.28f, -0.21f},  // Stop Button
};

bool isInsideRectangle(float x, float y, float xMin, float xMax, float yMin, float yMax) {
    return x >= xMin && x <= xMax && y >= yMin && y <= yMax;
}

void breakMicrowaveAndStartSmoke(GLFWwindow* window,MicrowaveState& microwaveState, Smoke& smoke) {
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {  // Check if "X" key is pressed
        if (microwaveState != MicrowaveState::ERROR) {

            microwaveState = MicrowaveState::ERROR;  // Set microwave to ERROR state
            std::cout << "Microwave has malfunctioned. ERROR state activated.\n";

            // Start the smoke effect
            smoke.opacity = 1.0f;  // Reset opacity to full
            smoke.positionY = -0.1f;  // Start the smoke from a low position
        }
    }
}

// Function to validate the timer format (mm:ss)
bool isValidTime(const std::string& timer) {
	if (timer.length() == 5 && timer[2] == ':' and timer!="00:00") {
		int minutes = std::stoi(timer.substr(0, 2));
		int seconds = std::stoi(timer.substr(3, 2));

		return (minutes >= 0 && minutes <= 99) && (seconds >= 0 && seconds <= 59);
	}
	return false;
}

bool updateTimer(std::string& timer) {

	int minutes = std::stoi(timer.substr(0, 2));
	int seconds = std::stoi(timer.substr(3, 2));

	if (seconds > 0) {
		seconds--;
	}
	else if (minutes > 0) {
		minutes--;
		seconds = 59;
	}

	timer = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
	if (timer == "00:00")
		return true;
	return false;
}

void updateTimer(std::string& timer, int number) {
	// Extract current minutes and seconds from the timer
	int minutes = std::stoi(timer.substr(0, 2));
	int seconds = std::stoi(timer.substr(3, 2));

	// If we are still filling the minutes part (first two digits)
	if (seconds < 60) {
		seconds = seconds * 10 + number;  // Add digit to seconds
	}

	// If seconds exceed 59, move to minutes
	if (seconds >= 60) {
		seconds = 0;  // Reset seconds to 0
		minutes += 1; // Add 1 minute
	}

	// Format the updated timer as mm:ss
	timer = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":"
		+ (seconds < 10 ? "0" : "") + std::to_string(seconds);

	//std::cout << timer<<"\n";
}


void countdownTimer(MicrowaveState& microwaveState, std::string& timer) {
	if (microwaveState == MicrowaveState::COOKING) {
		std::cout << "\n---------------- Countdown Started -------------------" << "\n";

		while (timer != "00:00") {
			int minutes = std::stoi(timer.substr(0, 2));
			int seconds = std::stoi(timer.substr(3, 2));

			if (seconds > 0) {
				seconds--;
			}
			else if (minutes > 0) {
				minutes--;
				seconds = 59;  // Reset seconds to 59 when a minute is subtracted
			}

			// Update the timer string
			timer = (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

			// Print the timer value
			std::cout << "Timer: " << timer << std::endl;

			// Introduce a 1-second delay before the next print
			//std::this_thread::sleep_for(std::chrono::seconds(1));
		}

		microwaveState = MicrowaveState::DONE;
		std::cout << "Microwave timer done! Timer: " << timer << std::endl;
	}
}


void handleMicrowaveLogic(GLFWwindow* window, MicrowaveState& microwaveState, DoorState& doorState,
	std::string& timer, bool& isLampOn) {


    static bool wasMousePressed = false;
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    float xNDC = (2.0f * mouseX) / windowWidth - 1.0f;
    float yNDC = 1.0f - (2.0f * mouseY) / windowHeight;  // Invert Y to match OpenGL coordinates

    for (const auto& button : buttons) {

        if (isInsideRectangle(xNDC, yNDC, button.xMin, button.xMax, button.yMin, button.yMax)) {
            if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS && !wasMousePressed) {

                wasMousePressed = true;
                std::string keypadClicked =  std::string(button.label);  // Explicit conversion, but not required

				if (microwaveState == MicrowaveState::IDLE) {

					if (keypadClicked != "START" && keypadClicked != "STOP" && keypadClicked != "RESET") {

						if (!keypadClicked.empty() && keypadClicked.length() == 1) {

							int num = keypadClicked[0] - '0'; 
							updateTimer(timer, num);
							std::cout << "Current timer: " << timer << std::endl; // <-- Print here
						}
					}
				}

				if (keypadClicked == "START" && isValidTime(timer) && (microwaveState == MicrowaveState::IDLE || microwaveState == MicrowaveState::DONE)) {
					microwaveState = MicrowaveState::COOKING;
					isLampOn = true;
					countdownTimer(microwaveState, timer);

				}

				else if (keypadClicked == "RESET") {
					microwaveState = MicrowaveState::IDLE;
					timer = "00:00";
					std::cout << "Microwave reset!" << std::endl;
				}

				else if (keypadClicked == "STOP" && microwaveState == MicrowaveState::COOKING) {
					microwaveState = MicrowaveState::PAUSED;
					std::cout << "Microwave paused!" << std::endl;
				}

				// Timer countdown logic for COOKING state
				else if (microwaveState == MicrowaveState::COOKING) {
					if (updateTimer(timer)) {
						microwaveState = MicrowaveState::DONE;
						std::cout << "Microwave timer done! Timer: " << timer << std::endl;
					}
				}
            }
        }
    }

    if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
        wasMousePressed = false;
    }

}


