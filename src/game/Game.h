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

	void initDisplay(const char* title, int width, int height, GLenum resizable);
	void initRenderer();

public:
	Game(const char* title, int width, int height, GLenum resizable, int OPENGL_VERSION_MAJOR, int OPENGL_VERSION_MINOR);
	~Game();

	void startGameLoop();

	void addModel(Model* model);
};

#endif /* GAME_GAME_H_ */
