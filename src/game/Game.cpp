#include "Game.h"

void Game::initDisplay(const char* title, int width, int height, GLenum resizable) {
	this->displayManager = new DisplayManager();
	this->displayManager->createWindow(title, width, height, resizable,
			this->OPENGL_VERSION_MAJOR, this->OPENGL_VERSION_MINOR);
}

void Game::initRenderer() {
	Shader* shader = new Shader("./src/shaderScripts/vertexShader.glsl", "./src/shaderScripts/fragmentShader.glsl");
	this->renderer = new Renderer(shader);
}

Game::Game(const char* title, int width,
		int height, GLenum resizable,
		int OPENGL_VERSION_MAJOR,
		int OPENGL_VERSION_MINOR) :
		OPENGL_VERSION_MAJOR(OPENGL_VERSION_MAJOR),
		OPENGL_VERSION_MINOR(OPENGL_VERSION_MINOR)
{
	this->initDisplay(title, width, height, resizable);
	this->initRenderer();
}

Game::~Game() {
	delete this->displayManager;
	delete this->renderer;

	for(auto*& model : this->models) {
		delete model;
	}
}

void Game::startGameLoop() {
	while(!displayManager->getWindowShouldClose()) {
		displayManager->updateWindow();

		renderer->prepare();
		renderer->renderModels(this->models);

		displayManager->renderWindow();
	}
}

void Game::addModel(Model* model) {
	this->models.push_back(model);
}
