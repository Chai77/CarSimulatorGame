#ifndef RENDERENGINE_RENDERER_H_
#define RENDERENGINE_RENDERER_H_

#include "../models/Model.h"
#include "../shaders/Shader.h"

#include <vector>

class Renderer {
private:
	Shader* shader;
public:
	Renderer(Shader* shader);
	~Renderer();

	void prepare();
	void renderModels(std::vector<Model*> models);

	void setUniforms(glm::mat4 ViewMatrix, glm::mat4 ProjectionMatrix);
};

#endif /* RENDERENGINE_RENDERER_H_ */
