#include "DisplayManager.h"

void APIENTRY glDebugOutput(GLenum source,
                            GLenum type,
                            unsigned int id,
                            GLenum severity,
                            GLsizei length,
                            const char *message,
                            const void *userParam)
{
    // ignore non-significant error/warning codes
    if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return;

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " <<  message << std::endl;

    switch (source)
    {
        case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
        case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
        case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break;
        case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
        case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
        case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
        case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
        case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;

    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
        case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
        case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << std::endl;
}


void DisplayManager::initWindow(const char* title, int width, int height, int gl_version_major , int gl_version_minor, GLenum resizable) {
	if(!glfwInit()) {
		throw std::runtime_error("GLFW could not be initialized");
	}

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_version_major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_version_minor);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	this->window = glfwCreateWindow(width, height, title, NULL, NULL);

	if(this->window == NULL) {
		glfwTerminate();
		throw std::runtime_error("There was an error creating a window for glfw");
	}

	glfwSetFramebufferSizeCallback(window, this->screenResizeCallback);
//	glfwGetFramebufferSize(window, &this->framebufferWidth, &this->framebufferHeight);
//	glViewport(0, 0, this->framebufferWidth, this->framebufferHeight);

	glfwMakeContextCurrent(window);
}

void DisplayManager::initGlew() {
	glewExperimental = GL_TRUE;

	if(glewInit() != GLEW_OK) {
		glfwTerminate();
		throw std::runtime_error("GLEW could not be initialized");
	}
}

void DisplayManager::initOpenGLOptions() {
	glEnable(GL_DEBUG_OUTPUT);
	glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
	glDebugMessageCallback(glDebugOutput, NULL);

	glEnable(GL_DEPTH_TEST);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void DisplayManager::screenResizeCallback(GLFWwindow* window, int framebufferWidth, int framebufferHeight) {
	glViewport(0, 0, framebufferWidth, framebufferHeight);
}

DisplayManager::DisplayManager() {
	this->framebufferWidth = 0;
	this->framebufferHeight = 0;
	this->window = NULL;
}

DisplayManager::~DisplayManager() {
	this->destroyWindow();
}

void DisplayManager::createWindow(const char* title, int width, int height, GLenum resizable, int gl_version_major, int gl_version_minor) {
	this->initWindow(title, width, height, gl_version_major, gl_version_minor, resizable);
	this->initGlew();
	this->initOpenGLOptions();
}


void DisplayManager::updateWindow() {
	if(!window) {
		glfwTerminate();
		throw std::runtime_error("The window must be created first with DisplayManager::createWindow");
	}
	glfwPollEvents();
}

void DisplayManager::renderWindow() {
	if(!window) {
		glfwTerminate();
		throw std::runtime_error("The window must be created first with DisplayManager::createWindow");
	}
	glfwSwapBuffers(window);
	glFlush();
}

void DisplayManager::destroyWindow() {
	if(!window) {
		glfwTerminate();
		throw std::runtime_error("The window must be created first with DisplayManager::createWindow");
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}

int DisplayManager::getScreenWidth() {
	return framebufferWidth;
}

int DisplayManager::getScreenHeight() {
	return framebufferHeight;
}

bool DisplayManager::getWindowShouldClose() {
	return glfwWindowShouldClose(window);
}

void DisplayManager::errorReceived(int messageType, const char* message) {
	std::cout << "Is there something coming" << "\n";
	std::cout << messageType << ": " << message << "\n";

}
