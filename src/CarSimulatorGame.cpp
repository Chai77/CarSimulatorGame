#include "renderEngine/DisplayManager.h"
#include "game/Game.h"
#include "models/Model.h"
#include "models/Vertex.h"
#include <glm.hpp>
#include <vec3.hpp>
#include <vec2.hpp>

Vertex vertices[] = {
	//Position								//Texcoords						//Color						//Normals
	glm::vec3(0.f, 0.5f, 0.f),				glm::vec2(0.5f, 1.f),			glm::vec3(1.f, 0.f, 0.f),	glm::vec3(0.f, 0.f, 1.f),
	glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec2(0.f, 0.f),			glm::vec3(1.f, 0.f, 0.f),	glm::vec3(0.f, 0.f, 1.f),
	glm::vec3(0.5f, -0.5f, 0.f),			glm::vec2(1.f, 0.f),			glm::vec3(1.f, 0.f, 0.f),	glm::vec3(0.f, 0.f, 1.f),
};
unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

GLuint indices[] = {
	0, 1, 2	//Triangle 1
};
unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);


int main() {
	Game game("CarSimulator", 640, 480, GLFW_FALSE, 4, 5);
	Model* model = new Model(vertices, nrOfVertices, indices, nrOfIndices);
	game.addModel(model);
	game.startGameLoop();
	return 0;
}
