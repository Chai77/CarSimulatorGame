#ifndef RENDERENGINE_DISPLAYMANAGER_H_
#define RENDERENGINE_DISPLAYMANAGER_H_

#include <stdexcept>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class DisplayManager {
private:
	static DisplayManager* display;
	GLFWwindow* window;
	int framebufferWidth;
	int framebufferHeight;

	void initWindow(const char* title, int width, int height, int glmajor, int glminor, GLenum resizable);
	void initOpenGLOptions();
	void initGlew();

	void destroyWindow();

	static void screenResizeCallback(GLFWwindow* window, int framebufferWidth, int framebufferHeight);
public:
	DisplayManager();
	~DisplayManager();

	void createWindow(const char* title, int width, int height, GLenum resizable, int glmajor=4, int glminor=5);
	void updateWindow();
	void renderWindow();

	bool getWindowShouldClose();

	int getScreenWidth();
	int getScreenHeight();

	static DisplayManager* getDisplay();
	static void deleteDisplay();

	static void errorReceived(int messageType, const char* message);
};

#endif
