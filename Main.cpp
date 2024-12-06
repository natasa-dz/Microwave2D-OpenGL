#include "main.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>



int windowWidth = 2000;  // Width of your window
int windowHeight = 1000; // Height of your window
float plateAspect = 800.0f / 384.0f;

float scale = 1.7f;
float microwaveWidth = 0.8162f ;
float microwaveHeight = 0.83556f ;

float controlPanelWidth = 0.2f;

float plateWidth = microwaveWidth * 0.48f;
float plateHeight = plateWidth / plateAspect;

float doorWidth = microwaveWidth;
float doorHeight = microwaveHeight;

MousePosition mousePos = { 0.0f, 0.0f };


float cavityWidth = doorWidth;
float cavityHeight = doorHeight;


// --------------------- Vertices

GLfloat controlPanelVertices[] = {
	// X                              Y            R     G     B     U     V
	-controlPanelWidth / 2 + doorWidth / 2 + controlPanelWidth / 2, -microwaveHeight / 2, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
	-controlPanelWidth / 2 + doorWidth / 2 + controlPanelWidth / 2,  microwaveHeight / 2, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
	 controlPanelWidth / 2 + doorWidth / 2 + controlPanelWidth / 2,  microwaveHeight / 2, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
	 controlPanelWidth / 2 + doorWidth / 2 + controlPanelWidth / 2, -microwaveHeight / 2, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f
};

GLfloat plateVertices[] = {
	-plateWidth / 2 , -plateHeight / 2 - 0.14f,    1.0f, 1.0f, 1.0f,    0.0f, 0.0f, // Bottom-left
	-plateWidth / 2 ,  plateHeight / 2 - 0.14f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, // Top-left
	 plateWidth / 2 ,  plateHeight / 2 - 0.14f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, // Top-right
	 plateWidth / 2 , -plateHeight / 2 - 0.14f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f  // Bottom-right
};

GLfloat doorVertices[] = {
	// X         Y            R     G     B     U     V
	-doorWidth / 2, -doorHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
	-doorWidth / 2,  doorHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	 doorWidth / 2,  doorHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	 doorWidth / 2, -doorHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f  // Bottom-right
};

GLfloat glassVertices[] = {
	// X         Y            R     G     B     U     V
	-doorWidth / 2, -doorHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
	-doorWidth / 2,  doorHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	 doorWidth / 3,  doorHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	 doorWidth / 3, -doorHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f  // Bottom-right
};

GLfloat indicatorVertices[] = {
	// X         Y            R     G     B     U     V
	0.49f, -0.285f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
	0.49f,  -0.233f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	0.53f,  -0.233f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	0.53f, -0.285f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f  // Bottom-right
};

float nameplateWidth = 0.7f;
float nameplateHeight = 0.1f;


GLfloat nameplateVertices[] = {
	// X              Y                R     G     B     U     V
	-nameplateWidth / 2, doorHeight / 2 + nameplateHeight, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	-nameplateWidth / 2, doorHeight / 2,                   1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
	 nameplateWidth / 2, doorHeight / 2,                   1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // Bottom-right
	 nameplateWidth / 2, doorHeight / 2 + nameplateHeight, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f  // Top-right
};

float indicator = controlPanelWidth / 2 ;

GLfloat smokeVertices[] = {
	// X    Y      R     G     B     U     V
	-1.0f, -1.0f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,  // Bottom-left
	-1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	 1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	 1.0f, -1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f // Bottom-right
};

GLfloat cavityVertices[] = {
	// X         Y            R     G     B     U     V
	-cavityWidth / 2, -cavityHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
	-cavityWidth / 2,  cavityHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	 cavityWidth / 2,  cavityHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	 cavityWidth / 2, -cavityHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f  // Bottom-right
};

float lampScale = 0.3f; // Scale to fit inside the cavity


// ----------------- Indices 

GLfloat backgroundVertices[] = {
	// X    Y      R     G     B     U     V
	-1.0f, -1.0f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,  // Bottom-left
	-1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	 1.0f,  1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	 1.0f, -1.0f,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f // Bottom-right
};

GLuint backgroundIndices[] = {
	0, 1, 2, 0, 2, 3   // Background
};

GLuint microwaveIndices[] = {
	0, 1, 2, 0, 2, 3 // Microwave
};

GLuint plateIndices[] = {
	0, 1, 2, 0, 2, 3 // Plate
};

GLuint doorIndices[] = {
	0, 1, 2, 0, 2, 3   // Door
};

GLuint cavityIndices[] = {
	0, 1, 2, 0, 2, 3 
};

GLuint glassIndices[] = {
	0, 1, 2, 0, 2, 3  
};

GLuint lampIndices[] = {
	0, 1, 2, 0, 2, 3
};

GLuint smokeIndices[] = {
	0, 1, 2, 1, 2, 3
};

GLuint indicatorIndices[] = {
	0, 1, 2, 1, 2, 3
};

GLuint nameIndices[] = {
	0, 1, 2, 1, 2, 3
};

GLuint indices[] = {
	0, 1, 2, 0, 2, 3
};

GLfloat blackbackgroundVertices[] = {
	// X     Y   
	-1.0f, -1.0f,
	-1.0f,  1.0f,
	 1.0f,  1.0f,
	 1.0f, -1.0f,
};


// ----------------------------------------- METHODS 

void mouseCallback(GLFWwindow* window, double mouseX, double mouseY) {

	// Convert to normalized device coordinates (NDC)
	mousePos.x = (2.0f * mouseX) / windowWidth - 1.0f;
	mousePos.y = 1.0f - (2.0f * mouseY) / windowHeight;

	//std::cout << "Mouse clicked at: NDC (" << mousePos.x << ", " << mousePos.y << ")\n";


}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		// Convert screen coordinates to normalized device coordinates (NDC)
		int width, height;
		glfwGetWindowSize(window, &width, &height);

		float xNDC = (2.0f * xpos) / width - 1.0f;
		float yNDC = 1.0f - (2.0f * ypos) / height; // Flip y-axis

		std::cout << "Mouse clicked at: NDC (" << xNDC << ", " << yNDC << ")\n";

	}
}

void drawObject(Texture& texture, VAO& vao, GLenum drawMode = GL_TRIANGLES, GLuint count = 6) {
	texture.Bind();
	vao.Bind();
	glDrawElements(drawMode, count, GL_UNSIGNED_INT, (void*)0);
}

void setupObject(VAO& vao, float* vertices, size_t verticesSize, unsigned int* indices, size_t indicesSize) {
	VBO vbo = VBO(vertices, verticesSize);
	EBO ebo = EBO(indices, indicesSize);
	vao.LinkAttrib(vbo, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);  // Position
	vao.LinkAttrib(vbo, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float))); // Color
	vao.LinkAttrib(vbo, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float))); // Texture coords
	vao.Unbind();
	vbo.Unbind();
	ebo.Unbind();

	vbo.Delete();
	ebo.Delete();
}

int main()
{

	if (!glfwInit())
	{
		std::cout << "GLFW didn't load correctly! :(\n";
		return 1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);

	int xPos = (videoMode->width - windowWidth) / 2;
	int yPos = (videoMode->height - windowHeight) / 2;

	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Microwave", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Error! Window creation failed! :(\n";
		glfwTerminate(); //Gasi GLFW
		return 2; //Vrati kod za gresku
	}

	glfwSetWindowPos(window, xPos, yPos);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
	{
		std::cout << "GLEW nije mogao da se ucita! :'(\n";
		return 3;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	//program Shaders-microwave, doors, glass, led indicator, error indicator... 
	Shader defaultShader("default.vert", "default.frag");
	Shader glassShader("glass.vert", "glass.frag");
	Shader doorShader("door.vert", "door.frag");
	Shader indicatorShader("indicator.vert", "indicator.frag");
	Shader lampShader("light.vert", "light.frag");
	Shader smokeShader("smoke.vert", "smoke.frag");
	Shader lightningShader("lightning.vert", "lightning.frag");
	Shader textShader("text.vert", "text.frag");


	// dobavi varijable 
	GLuint uniID = glGetUniformLocation(defaultShader.ID, "scale");
	GLuint timeUniformLocation = glGetUniformLocation(indicatorShader.ID, "time");
	GLboolean glassOnShader = glGetUniformLocation(glassShader.ID, "isGlass");
	GLfloat lightIntensityLoc = glGetUniformLocation(lightningShader.ID, "lightning");
	GLuint microwaveStateUniformLocation = glGetUniformLocation(indicatorShader.ID, "isMicrowaveRunning");

	// Microwave (control Panel)
	VAO controlPanelVAO;
	controlPanelVAO.Bind();
	setupObject(controlPanelVAO, controlPanelVertices, sizeof(controlPanelVertices), microwaveIndices, sizeof(microwaveIndices));

	// Name(above the control panel)
	VAO nameVAO;
	nameVAO.Bind();
	setupObject(nameVAO, nameplateVertices, sizeof(nameplateVertices), nameIndices, sizeof(nameIndices));


	// Door
	VAO doorVAO;
	doorVAO.Bind();
	setupObject(doorVAO,  doorVertices, sizeof(doorVertices), doorIndices, sizeof(doorIndices));


	// Microwave Cavity VAO, VBO, EBO
	VAO cavityVAO;
	cavityVAO.Bind();
	setupObject(cavityVAO, cavityVertices, sizeof(cavityVertices), cavityIndices, sizeof(cavityIndices));

	// Smoke
	VAO smokeVAO;
	smokeVAO.Bind();
	setupObject(smokeVAO, smokeVertices, sizeof(smokeVertices), smokeIndices, sizeof(smokeIndices));


	// Led Indicator 
	VAO indicatorVAO;
	indicatorVAO.Bind();
	VBO indicatorVBO(indicatorVertices, sizeof(indicatorVertices));
	EBO indicatorEBO(indicatorIndices, sizeof(indicatorIndices));
	indicatorVAO.LinkAttrib(indicatorVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	indicatorVAO.Unbind();
	indicatorEBO.Unbind();
	indicatorVBO.Unbind();

	// Microwave glass 
	VAO glassVAO;
	glassVAO.Bind();

	VBO glassVBO(glassVertices, sizeof(glassVertices));
	EBO glassEBO(glassIndices, sizeof(glassIndices));
	glassVAO.LinkAttrib(glassVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	glassVAO.Unbind();
	glassVBO.Unbind();
	glassEBO.Unbind();

	// Plate
	VAO plateVAO;
	plateVAO.Bind();

	setupObject(plateVAO, plateVertices, sizeof(plateVertices), plateIndices, sizeof(plateIndices));


	VAO blackVAO;
	blackVAO.Bind();

	EBO sharedEBO(indices, sizeof(indices));
	sharedEBO.Bind();

	VBO blackVBO(blackbackgroundVertices, sizeof(blackbackgroundVertices));
	blackVAO.LinkAttrib(blackVBO, 0, 2, GL_FLOAT, 2 * sizeof(float), (void*)0);
	blackVAO.Unbind();
	blackVBO.Unbind();
	sharedEBO.Unbind();


	//Background
	VAO backgroundVAO;
	backgroundVAO.Bind();
	setupObject(backgroundVAO, backgroundVertices, sizeof(backgroundVertices), backgroundIndices, sizeof(backgroundIndices));

#define CRES 100 // Circle Resolution = Rezolucija kruga

	float circle[(CRES + 2) * 2];
	float r = 0.05f; // Radius

	circle[0] = 0; // Center X
	circle[1] = 0; // Center Y
	for (int i = 0; i <= CRES; i++) {
		float angle = glm::radians(i * 360.0f / CRES);
		circle[2 + 2 * i] = r * cos(angle); // X
		circle[2 + 2 * i + 1] = r * sin(angle); // Y
	}

	unsigned int VAO[2];
	glGenVertexArrays(2, VAO);
	unsigned int VBO[2];
	glGenBuffers(2, VBO);

	glBindVertexArray(VAO[1]);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(circle), circle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	// Texture
	Texture microwave("../images/keyboard_sharp.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	microwave.assignUnit(defaultShader, "tex0", 0);

	Texture plate("../images/food_plate.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	plate.assignUnit(defaultShader, "tex1", 1);

	Texture door("../images/sharp_doors.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	door.assignUnit(defaultShader, "tex4", 4);

	Texture cavity("../images/alu_inside.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	cavity.assignUnit(defaultShader, "tex5", 5);

	Texture background("../images/bg2.jpeg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	background.assignUnit(defaultShader, "tex6", 6);

	Texture namePlate("../images/ime_prezime.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	namePlate.assignUnit(defaultShader, "tex7", 7);

	Texture smoke("../images/smoke.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	smoke.assignUnit(defaultShader, "tex8", 8);

	//Text timeRenderer("fonts/digital-7.ttf", &textShader, windowWidth, windowHeight);


	glfwSetCursorPosCallback(window, mouseCallback);


	// ---------------------------------- Inicijalno stanje sistema!!!! --- POMOCNE PROMENLJIVE
	static float doorAnimation = 0.0f;
	static float doorOffset = 0.0f;


	const double TARGET_FPS = 60.0;
	const double TARGET_FRAME_TIME = 1.0 / TARGET_FPS;  // ~16.67 ms per frame

	double lastFrameTime = 0.0;  // Store the time of the last frame
	double currentFrameTime = 0.0;
	double deltaTime = 0.0;  // Store the time difference between frames

	static bool glassOn = true;
	static bool glassOff = true;
	static bool isLampOn = true;

	static bool isMicrowaveBroken = false;
	static bool XPressed = false;
	static bool RPressed = false;

	float smokeOpacity = 0.0f;
	float darknessLevel = 0.0f;

	float flickerIntensity = (rand() % 2 == 0) ? 1.0f : 0.0f;  // Random flicker (0 or 1)

	std::string timer = "00:00";
	MicrowaveState microwaveState = MicrowaveState::IDLE;
	DoorState doorState = DoorState::CLOSED;

	// --------------------------- MAIN WHILE LOOP
	float timeValue = 0.0f;


	while (!glfwWindowShouldClose(window)) {
		currentFrameTime = glfwGetTime();

		deltaTime = currentFrameTime - lastFrameTime;

		if (deltaTime >= TARGET_FRAME_TIME) {

			lastFrameTime = currentFrameTime;
			timeValue += 0.16f;


			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			handleMicrowaveLogic(window, microwaveState, doorState, timer, isLampOn);

			defaultShader.Activate();
			glUniform1f(uniID, 0.5f);

			drawObject(background, backgroundVAO);


			// Gradually darken the scene if microwave is broken
			if (isMicrowaveBroken) {
				smokeShader.Activate();

				glUniform1f(glGetUniformLocation(smokeShader.ID, "scale"), darknessLevel);
				glUniform1f(glGetUniformLocation(smokeShader.ID, "opacity"), smokeOpacity);
				glUniform1f(glGetUniformLocation(smokeShader.ID, "flickerIntensity"), flickerIntensity);  // Apply flicker


				smoke.Bind();
				smokeVAO.Bind();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

				isLampOn = false;
				darknessLevel += 0.01f;
				if (darknessLevel > 1.0f) darknessLevel = 1.0f;

				smokeOpacity += 0.01f;
				if (smokeOpacity > 1.0f) smokeOpacity = 1.0f;

				flickerIntensity = (rand() % 2 == 0) ? 0.0f : 1.0f;


				// Turn off the microwave after smoke opacity reaches full
				if (smokeOpacity >= 1.0f) {
					microwaveState = MicrowaveState::ERROR;
				}

				lightningShader.Activate();
				glUniform1f(lightIntensityLoc, darknessLevel);

				blackVAO.Bind();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

			}

			defaultShader.Activate();

			drawObject(microwave, controlPanelVAO);

			drawObject(namePlate, nameVAO);

			drawObject(cavity, cavityVAO);

			drawObject(plate, plateVAO);

			doorOffset = updateDoorState(window, doorOffset, doorState, doorAnimation, microwaveState);

			// Set lamp state (on = yellow, off = black)
			lampShader.Activate();
			GLint lightStateLocation = glGetUniformLocation(lampShader.ID, "lightState");
			glUniform1i(lightStateLocation, isLampOn); // Pass the state of the lamp (either 0 or 1)
			glBindVertexArray(VAO[1]);
			glDrawArrays(GL_TRIANGLE_FAN, 0, sizeof(circle) / (2 * sizeof(float)));
			glUseProgram(0);
			glBindVertexArray(0);

			
			// ----------------------------- GLASS 
			glassShader.Activate();

			bool isGKeyPressed = glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS;

			//// Toggle the glass visibility when 'G' is pressed and glass is not off
			if (isGKeyPressed && !glassOff) {
				glassOn = !glassOn;  // Toggle the glass state (on/off)
			}

			//// Update the shader uniform to reflect the glass visibility
			glUniform1i(glassOnShader, glassOn ? 1 : 0);

			//// Track the state of the 'G' key to prevent rapid toggling
			glassOff = isGKeyPressed;

			//// Bind the glass's Vertex Array Object and draw the object
			glassVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

			// ----------- LED INDICATOR
			indicatorShader.Activate();
			// Pass the time value to the shader
			glUniform1f(timeUniformLocation, timeValue);

			// Pass the microwave state to the shader (whether it's running or not)
			glUniform1i(microwaveStateUniformLocation, isRunning);
			

			indicatorVAO.Bind();
			glDrawArrays(GL_TRIANGLE_FAN, 0, 4); // 4 vertices for a quad

			////  ---------- DOOR 
			doorShader.Activate();
			glUniform1f(glGetUniformLocation(doorShader.ID, "doorOffset"), doorOffset);
			drawObject(door, doorVAO);


			// Handle X key (break microwave)
			if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS && !XPressed) {
				isMicrowaveBroken = true;
				XPressed = true;
			}


			if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && !RPressed && microwaveState == MicrowaveState::ERROR) {

				isLampOn = true;
				isMicrowaveBroken = false;  // Set broken state to false
				RPressed = true;
				microwaveState = MicrowaveState::IDLE;  // Set the microwave back to cooking state
				isPaused = false;  // Unpause the microwave
				timer = "00:00";  // Reset repair timer
				std::cout << "Microwave repaired and scene restored.\n";
			}
			if (!isMicrowaveBroken) {


				if (darknessLevel > 0.0f) {
					darknessLevel -= 0.01f;
					if (darknessLevel < 0.0f) darknessLevel = 0.0f;
				}

				lightningShader.Activate();
				glUniform1f(lightIntensityLoc, darknessLevel);

				blackVAO.Bind();
				glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
			}

			//timeRenderer.RenderText(timer, 1360.0f, 200.0f, 1.2f, 0.5f, 0.7f, 1.0f);




			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);
			glfwSwapBuffers(window);
			glfwPollEvents();


		}
		else {
			glfwWaitEventsTimeout(TARGET_FRAME_TIME - deltaTime);
		}

	}

	controlPanelVAO.Delete();
	doorVAO.Delete();
	cavityVAO.Delete();


	microwave.Delete();
	plate.Delete();

	door.Delete();
	cavity.Delete();

	glassVAO.Delete();
	glassVBO.Delete();
	glassEBO.Delete();


	defaultShader.Delete();
	glassShader.Delete();
	doorShader.Delete();


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}
