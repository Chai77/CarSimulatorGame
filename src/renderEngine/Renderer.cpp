#include "Renderer.h"

Renderer::Renderer(Shader* shader) {
	this->shader = shader;
}

Renderer::~Renderer() {
	delete this->shader;
}

void Renderer::prepare() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void Renderer::renderModels(std::vector<Model*> models) {
	shader->use();
	for (auto& model : models) {
		model->render();
	}
	shader->unuse();
}
