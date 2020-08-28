#ifndef RENDERENGINE_RENDERER_H_
#define RENDERENGINE_RENDERER_H_

#include "../models/Model.h"
#include "../shaders/Shader.h"

class Renderer {
private:
	Shader* shader;
public:
	Renderer(Shader* shader);
	~Renderer();

	void prepare();
	void renderModels(std::vector<Model*> models);
};

#endif /* RENDERENGINE_RENDERER_H_ */
