# Microwave2D-OpenGL

## Overview  
**InteractiveMicrowave2D-OpenGL** is a feature-rich 2D microwave simulation created using OpenGL. This project showcases advanced graphics programming techniques and interactive functionalities, adhering to detailed specifications for a virtual microwave.

---

## Features  
1. **Door with Semi-Transparent Glass:**  
   - Doors can be opened (`O`) and closed (`Z`) interactively.  
   - Glass transparency can be toggled.  

2. **Realistic Lighting:**  
   - A round lamp illuminates the food inside while the microwave is running.  
   - Dynamic lighting effects simulate real-life visuals.  

3. **Numerical Keypad and Timer:**  
   - Clickable keypad to set the timer (format: MM:SS).  
   - Timer decrements in real-time, stopping at zero.  

4. **Control Buttons:**  
   - **Start:** Begins microwave operation.  
   - **Stop:** Pauses the operation.  
   - **Reset:** Resets the timer and lamp.  

5. **Operational Constraints:**  
   - Microwave halts when the door opens and cannot start unless closed.  
   - Microwave will not start if the timer is zero.  

6. **Completion Indicator:**  
   - An external lamp blinks when the timer reaches zero.  

7. **Malfunction Simulation (X Key):**  
   - Gradual scene darkening.  
   - Animated smoke rising and dissipating.  
   - Timer displays `ERROR` and blinks.  
   - Microwave becomes non-operational.  

8. **Servicing Mode:**  
   - Reactivates microwave, removes smoke, and resets the scene to its original state.  

9. **Credits Display:**  
   - Author’s name, surname, and student ID are shown in a corner of the screen.  

---

## Controls  
| Key      | Function                        |
|----------|---------------------------------|
| `O`      | Open the microwave door.       |
| `Z`      | Close the microwave door.      |
| `X`      | Simulate microwave malfunction.|
| `S`      | Servicing mode.                |
| `Mouse`  | Interact with buttons and keypad.|

---

## Setup Instructions  
### Prerequisites  
1. Install **GLFW**, **GLEW**, and **GLM** libraries.  
2. A modern C++ compiler (e.g., GCC, Clang, MSVC).  
3. Git for version control.  

### Installation  
1. Clone this repository:  
   ```bash
   git clone https://github.com/username/InteractiveMicrowave2D-OpenGL.git
   cd InteractiveMicrowave2D-OpenGL

