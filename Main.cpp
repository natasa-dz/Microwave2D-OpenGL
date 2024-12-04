#include "main.h"

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

GLfloat cavityVertices[] = {
	// X         Y            R     G     B     U     V
	-cavityWidth / 2, -cavityHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Bottom-left
	-cavityWidth / 2,  cavityHeight / 2,  1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // Top-left
	 cavityWidth / 2,  cavityHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // Top-right
	 cavityWidth / 2, -cavityHeight / 2,  1.0f, 1.0f, 1.0f, 1.0f, 0.0f  // Bottom-right
};

// Scale factor for the lamp (as a fraction of the cavity size)
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


void mouseCallback(GLFWwindow* window, double mouseX, double mouseY) {

	// Convert to normalized device coordinates (NDC)
	mousePos.x = (2.0f * mouseX) / windowWidth - 1.0f;
	mousePos.y = 1.0f - (2.0f * mouseY) / windowHeight;

	// Print the normalized coordinates
	std::cout << "Mouse X: " << mousePos.x << ", Mouse Y: " << mousePos.y << std::endl;
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

	if (window == NULL) //Ako prozor nije napravljen
	{
		std::cout << "Error! Window creation failed! :(\n";
		glfwTerminate(); //Gasi GLFW
		return 2; //Vrati kod za gresku
	}

	glfwSetWindowPos(window, xPos, yPos);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) //Slicno kao glfwInit. GLEW_OK je predefinisani izlazni kod za uspjesnu inicijalizaciju sadrzan unutar biblioteke
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


	// dobavi varijable 
	GLuint uniID = glGetUniformLocation(defaultShader.ID, "scale");



	// Microwave (control Panel)
	VAO controlPanelVAO;
	controlPanelVAO.Bind();

	VBO controlPanelVBO(controlPanelVertices, sizeof(controlPanelVertices));
	EBO controlPanelEBO(microwaveIndices, sizeof(microwaveIndices));
	controlPanelVAO.LinkAttrib(controlPanelVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	controlPanelVAO.LinkAttrib(controlPanelVBO, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float)));
	controlPanelVAO.LinkAttrib(controlPanelVBO, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float)));
	controlPanelVAO.Unbind();
	controlPanelVBO.Unbind();
	controlPanelEBO.Unbind();


	// Lamp VAO, VBO, EBO
	//VAO lightVAO;
	//lightVAO.Bind();

	//VBO lightVBO(lamp, sizeof(lamp));
	//EBO lightEBO(lampIndices, sizeof(lampIndices));

	//lightVAO.LinkAttrib(lightVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0); // Position
	//lightVAO.LinkAttrib(lightVBO, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float))); // Color
	//lightVAO.LinkAttrib(lightVBO, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float))); // Texture coordinates

	//lightVAO.Unbind();
	//lightVBO.Unbind();
	//lightEBO.Unbind();


	// Door
	VAO doorVAO;
	doorVAO.Bind();

	VBO doorVBO(doorVertices, sizeof(doorVertices));
	EBO doorEBO(doorIndices, sizeof(doorIndices));
	doorVAO.LinkAttrib(doorVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	doorVAO.LinkAttrib(doorVBO, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float)));
	doorVAO.LinkAttrib(doorVBO, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float)));
	doorVAO.Unbind();
	doorVBO.Unbind();
	doorEBO.Unbind();


	// Microwave Cavity VAO, VBO, EBO
	VAO cavityVAO;
	cavityVAO.Bind();

	VBO cavityVBO(cavityVertices, sizeof(cavityVertices));
	EBO cavityEBO(cavityIndices, sizeof(cavityIndices));
	cavityVAO.LinkAttrib(cavityVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	cavityVAO.LinkAttrib(cavityVBO, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float)));
	cavityVAO.LinkAttrib(cavityVBO, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float)));
	cavityVAO.Unbind();
	cavityVBO.Unbind();
	cavityEBO.Unbind();


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

	VBO plateVBO(plateVertices, sizeof(plateVertices));
	EBO plateEBO(plateIndices, sizeof(plateIndices));
	plateVAO.LinkAttrib(plateVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	plateVAO.LinkAttrib(plateVBO, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float)));
	plateVAO.LinkAttrib(plateVBO, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float)));
	plateVAO.Unbind();
	plateVBO.Unbind();
	plateEBO.Unbind();


	//Background

	VAO backgroundVAO;
	backgroundVAO.Bind();

	VBO backgroundVBO(backgroundVertices, sizeof(backgroundVertices));
	EBO backgroundEBO(backgroundIndices, sizeof(backgroundIndices));
	backgroundVAO.LinkAttrib(backgroundVBO, 0, 2, GL_FLOAT, 7 * sizeof(float), (void*)0);
	backgroundVAO.LinkAttrib(backgroundVBO, 1, 3, GL_FLOAT, 7 * sizeof(float), (void*)(2 * sizeof(float)));
	backgroundVAO.LinkAttrib(backgroundVBO, 2, 2, GL_FLOAT, 7 * sizeof(float), (void*)(5 * sizeof(float)));
	backgroundVAO.Unbind();
	backgroundVBO.Unbind();
	backgroundEBO.Unbind();


	// Texture

	Texture microwave("../images/keyboard_sharp.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	microwave.assignUnit(defaultShader, "tex0", 0);

	Texture plate("../images/food_plate.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	plate.assignUnit(defaultShader, "tex1", 1);


	Texture lightOn("../images/light_on.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	lightOn.assignUnit(defaultShader, "tex2", 3);

	Texture lightOff("../images/light_off.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	lightOff.assignUnit(defaultShader, "tex3", 3);

	Texture door("../images/sharp_doors.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
	door.assignUnit(defaultShader, "tex4", 4);

	Texture cavity("../images/alu_inside.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	cavity.assignUnit(defaultShader, "tex5", 5);


	Texture background("../images/bg2.jpeg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	background.assignUnit(defaultShader, "tex6", 6);


	glfwSetCursorPosCallback(window, mouseCallback);


	// ---------------------------------- Inicijalno stanje sistema!!!! 
	MicrowaveState microwaveState = MicrowaveState::IDLE;
	DoorState doorState = DoorState::CLOSED;
	static float doorAnimation = 0.0f;
	static float doorOffset = 0.0f;


	// --------------------------- MAIN WHILE LOOP
	// Variables to control frame rate
	const double TARGET_FPS = 60.0;
	const double TARGET_FRAME_TIME = 1.0 / TARGET_FPS;  // ~16.67 ms per frame

	double lastFrameTime = 0.0;  // Store the time of the last frame
	double currentFrameTime = 0.0;
	double deltaTime = 0.0;  // Store the time difference between frames
	float indicatorTime = 0.0f;


	// Main while loop
	while (!glfwWindowShouldClose(window)) {


		// Get the current time
		currentFrameTime = glfwGetTime();
		deltaTime = currentFrameTime - lastFrameTime;
		// If enough time has passed to render a new frame
		if (deltaTime >= TARGET_FRAME_TIME) {
			// Update the last frame time
			lastFrameTime = currentFrameTime;

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			defaultShader.Activate();

			//numClick(window);
			//checkButtonClick(window, microwaveState, doorState);

			glUniform1f(uniID, 0.5f);

			background.Bind();
			backgroundVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);


			// Draw Inside (bind the inside texture)
			cavity.Bind();
			cavityVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);


			microwave.Bind();
			controlPanelVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);

			// Draw Food Plate inside the microwave
			plate.Bind();
			plateVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);


			doorOffset = updateDoorState(window, doorOffset, doorState, doorAnimation, microwaveState);

			// Microwave glass
			glassShader.Activate();
			//glUniform1f(glGetUniformLocation(glassShader.ID, "doorOffset"), doorOffset); // prosledi vrednost u SHADER NA OBRADU!
			glassVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);


			// Door 
			doorShader.Activate();
			glUniform1f(glGetUniformLocation(doorShader.ID, "doorOffset"), doorOffset); 
			door.Bind();
			doorVAO.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);



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
	controlPanelVBO.Delete();
	controlPanelEBO.Delete();

	doorVAO.Delete();
	doorVBO.Delete();
	doorEBO.Delete();

	cavityVAO.Delete();
	cavityVBO.Delete();
	cavityEBO.Delete();

	microwave.Delete();
	plate.Delete();
	lightOn.Delete();
	lightOff.Delete();
	door.Delete();
	cavity.Delete();

	glassVAO.Delete();
	glassVBO.Delete();
	glassEBO.Delete();

	//lightVAO.Delete();
	//lightVBO.Delete();
	//lightEBO.Delete();

	defaultShader.Delete();
	glassShader.Delete();
	doorShader.Delete();


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;



}

