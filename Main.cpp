#include "main.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//#include <ft2build.h>
//#include FT_FREETYPE_H


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
	// Positions         // Colors
	-1.0f, -1.0f,        0.1f, 0.1f, 0.1f,  // Bottom-left
	-1.0f,  1.0f,        0.2f, 0.2f, 0.2f,  // Top-left
	 1.0f, -1.0f,        0.0f, 0.0f, 0.0f,  // Bottom-right
	 1.0f,  1.0f,        0.8f, 0.8f, 0.8f   // Top-right
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

		// Check if click is within a button's area
		//checkButtonClicked(xNDC, yNDC);
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

// -------------------------------- BROKEN STATE DRAMATIC EFFECTS


void handleBrokenState(float& light_intensity, float& smoke_scale, float& smoke_opacity,
	MicrowaveState& microwaveState, float& sceneBrightness) {

	static float flickerTimer = 0.0f;  // Timer for "ERROR" flickering
	static float smokeOscillation = 0.0f; // Oscillation effect for smoke
	static bool lightFlicker = true; // Simulates light flickering before turning off

	if (sceneBrightness > 0.0f) {
		sceneBrightness -= 0.005f; // Gradual dimming
	}

	if (smoke_scale < 1.8f) {
		smoke_scale += 0.005f; // Smoke spreads faster
	}
	if (smoke_opacity < 1.0f) {
		smoke_opacity += 0.02f; // Smoke becomes more visible
	}

	smokeOscillation += 0.1f;

	if (smoke_opacity > 0.0f && smoke_scale >= 1.5f) {
		smoke_opacity -= 0.01f; // Smoke fades slowly
	}

	if (light_intensity > 0.0f) {
		if (lightFlicker) {
			light_intensity -= 0.02f; // Reduce intensity
			if (light_intensity <= 0.2f) {
				lightFlicker = false;
			}
		}
		else {
			light_intensity += 0.02f; // Increase intensity
			if (light_intensity >= 0.5f) {
				lightFlicker = true;
			}
		}
	}
	else {
		light_intensity = 0.0f; // Fully turn off light
	}

	flickerTimer += 0.05f;

	if (sceneBrightness <= 0.0f) {
		microwaveState = MicrowaveState::ERROR;
	}
}


void handleRepairState(float& light_intensity, float& smoke_scale, float& smoke_opacity,
	MicrowaveState& microwaveState, float& sceneBrightness) {
	static float recoveryFlicker = 0.0f; // Flicker effect during recovery
	static bool flickerDirection = true; // Flicker direction (increasing or decreasing)
	static float recoveryOscillation = 0.0f; // Oscillation effect during recovery

	// Gradually decrease light intensity to normal levels
	if (light_intensity > 0.5f) {
		light_intensity -= 0.006f; // Smoothly reduce intensity
	}

	// Flickering effect to signify recovery
	if (flickerDirection) {
		recoveryFlicker += 0.01f; // Increase flicker intensity
		if (recoveryFlicker >= 0.05f) {
			flickerDirection = false;
		}
	}
	else {
		recoveryFlicker -= 0.01f; // Decrease flicker intensity
		if (recoveryFlicker <= -0.05f) {
			flickerDirection = true;
		}
	}
	sceneBrightness = std::min(1.0f, sceneBrightness + 0.005f + recoveryFlicker); // Brighten with flickering

	// Decrease smoke effects when repairing
	if (smoke_scale > 0.0f) {
		smoke_scale -= 0.003f; // Shrink smoke gradually
	}
	if (smoke_opacity > 0.0f) {
		smoke_opacity -= 0.02f; // Fade out smoke quickly
	}

	// Add gentle oscillations for a calming effect as the microwave recovers
	recoveryOscillation += 0.05f;
	float smokeOffsetX = sin(recoveryOscillation) * 0.01f; // Smooth side-to-side sway
	float smokeOffsetY = cos(recoveryOscillation) * 0.005f; // Gentle vertical sway

	// Check if all recovery conditions are met
	if (light_intensity <= 0.5f && smoke_scale <= 0.0f && smoke_opacity <= 0.0f) {
		microwaveState = MicrowaveState::IDLE; // Reset to normal state
		sceneBrightness = 1.0f; // Restore full brightness
	}

	// Ensure no negative values for smoke or brightness
	smoke_scale = std::max(0.0f, smoke_scale);
	smoke_opacity = std::max(0.0f, smoke_opacity);
	light_intensity = std::max(0.0f, light_intensity);
}

void updateMicrowaveState(bool& repairMicrowave,bool& isMicrowaveBroken,float& light_intensity,float& smoke_scale,float& smoke_opacity, MicrowaveState& microwaveState, float& sceneBrightness) {

	if (repairMicrowave)
	{
		handleRepairState(light_intensity, smoke_scale, smoke_opacity, microwaveState, sceneBrightness);

	}
	else if (isMicrowaveBroken)
	{
		handleBrokenState(light_intensity, smoke_scale, smoke_opacity, microwaveState, sceneBrightness);

	}
}

std::string formatTime(int remainingSeconds) {
	int minutes = remainingSeconds / 60;
	int seconds = remainingSeconds % 60;
	return (minutes < 10 ? "0" : "") + std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
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

	glfwSetCursorPosCallback(window, mouseCallback);


	// ---------------------------------- Inicijalno stanje sistema!!!! --- POMOCNE PROMENLJIVE
	static float doorAnimation = 0.0f;
	static float doorOffset = 0.0f;


	const double TARGET_FPS = 60.0;
	const double TARGET_FRAME_TIME = 1.0 / TARGET_FPS;  // ~16.67 ms per frame

	double lastFrameTime = 0.0;  // Store the time of the last frame
	double currentFrameTime = 0.0;
	double deltaTime = 0.0;  // Store the time difference between frames
	float indicatorTime = 0.0f;

	static bool glassOn = true;
	static bool glassOff = true;
	static bool isLampOn = false;

	static bool isMicrowaveBroken = false;
	static bool XPressed = false;
	static bool RPressed = false;

	float smokeScale = 0.0f;
	float lightIntensity = 0.0f;
	float smokeOpacity = 0.0f;
	float sceneBrightness = 1.0f;

	static bool shouldRepairMicrowave = false;

	std::string timer = "00:00";
	MicrowaveState microwaveState = MicrowaveState::IDLE;
	MicrowaveState beforeState = MicrowaveState::IDLE;
	DoorState doorState = DoorState::CLOSED;


	float lastTime = 0.0f;



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

			if (microwaveState != beforeState) {

				if (beforeState == MicrowaveState::ERROR) {
					smokeScale = 0.7f;
					smokeOpacity = 0.0f;
				}

				beforeState = microwaveState;
			}

			handleMicrowaveLogic(window, microwaveState, doorState, timer, isLampOn);

			defaultShader.Activate();
			glUniform1f(uniID, 0.5f);

			drawObject(background, backgroundVAO);

			if(isMicrowaveBroken)
			{
				smokeShader.Activate();

				glUniform1f(glGetUniformLocation(smokeShader.ID, "scale"), smokeScale);
				glUniform1f(glGetUniformLocation(smokeShader.ID, "opacity"), smokeOpacity);

				smoke.Bind();
				smokeVAO.Bind();
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

			// Handle R key (repair microwave)
			if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && !RPressed && microwaveState == MicrowaveState::ERROR) {
				shouldRepairMicrowave = true;
				RPressed = true;
			}

			//updateMicrowaveState(shouldRepairMicrowave, isMicrowaveBroken, lightIntensity, smokeScale, smokeOpacity, microwaveState, sceneBrightness);

			if (shouldRepairMicrowave) {

				if (sceneBrightness >= 0.0f) {
					sceneBrightness -= 0.006f;
				}
				else
				{
					isMicrowaveBroken = false;
					microwaveState = MicrowaveState::IDLE;
					shouldRepairMicrowave = false;
					timer = "00:00";
				}
			}
			else if (isMicrowaveBroken) {
				if (sceneBrightness < 0.8f) {
					sceneBrightness += 0.006f;
				}
				if (sceneBrightness > 0.79f) {
					microwaveState = MicrowaveState::ERROR;
				}
			}

			//lightningShader.Activate();
			//glUniform1f(lightIntensityLoc, sceneBrightness);

			//blackVAO.Bind();
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);



			if (shouldRepairMicrowave) {
				if (smokeScale > 0.7f)
					smokeScale -= 0.002f; // Smanji dim
				if (smokeOpacity > 0.0f)
					smokeOpacity -= 0.01f;
			}
			else if (isMicrowaveBroken) {
				if (smokeScale < 1.4f)
					smokeScale += 0.002f; // Povećavaj dim
				if (smokeOpacity < 1.0f) {
					smokeOpacity += 0.01f; // Smanji opacitet dima
				}
			}


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
