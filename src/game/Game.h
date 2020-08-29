#ifndef GAME_GAME_H_
#define GAME_GAME_H_

class Game;

#include <vector>

#include "../renderEngine/DisplayManager.h"
#include "../models/Model.h"
#include "../renderEngine/Renderer.h"

class Game {
private:
	DisplayManager* displayManager;
	Renderer* renderer;
	const int OPENGL_VERSION_MAJOR;
	const int OPENGL_VERSION_MINOR;

	std::vector<Model*> models;

	const float FOV;
	const float nearPlane;
	const float farPlane;
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;

	void initDisplay(const char* title, int width, int height, GLenum resizable);
	void initRenderer();

	void render();
	void update();
	void updateProjectionMatrix();
	void updateViewMatrix();

public:
	Game(const char* title, int width, int height, GLenum resizable,
			int OPENGL_VERSION_MAJOR, int OPENGL_VERSION_MINOR,
			const float FOV=45.f, const float nearPlane=0.1f, const float farPlane=1000.f);
	~Game();

	void startGameLoop();

	void addModel(Model* model);
};

#endif /* GAME_GAME_H_ */
