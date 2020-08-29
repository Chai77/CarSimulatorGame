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

void Game::updateProjectionMatrix() {
	this->ProjectionMatrix = glm::perspective(this->FOV,
			static_cast<float>(this->displayManager->getScreenWidth())/this->displayManager->getScreenHeight(),
			this->nearPlane, this->farPlane);
}

void Game::updateViewMatrix() {
	this->ViewMatrix = glm::mat4(1.f);
	this->ViewMatrix = glm::translate(this->ViewMatrix, glm::vec3(0.f, 0.f, -3.f));
}

void Game::update() {
	updateViewMatrix();
	updateProjectionMatrix();
	for(auto& model : models) {
		model->rotate(glm::vec3(1.f, 0.f, 0.f));
		model->update();
	}
}

void Game::render() {
	renderer->prepare();
	renderer->setUniforms(this->ViewMatrix, this->ProjectionMatrix);
	renderer->renderModels(this->models);
}

Game::Game(const char* title, int width,
		int height, GLenum resizable,
		int OPENGL_VERSION_MAJOR,
		int OPENGL_VERSION_MINOR,
		const float FOV, const float nearPlane, const float farPlane) :
		OPENGL_VERSION_MAJOR(OPENGL_VERSION_MAJOR),
		OPENGL_VERSION_MINOR(OPENGL_VERSION_MINOR),
		FOV(FOV), nearPlane(nearPlane), farPlane(farPlane)
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

		update();
		render();

		displayManager->renderWindow();
	}
}

void Game::addModel(Model* model) {
	this->models.push_back(model);
}
