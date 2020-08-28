#ifndef MODELS_VERTEX_H_
#define MODELS_VERTEX_H_

#include <glm.hpp>
#include <vec2.hpp>
#include <vec3.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec2 texcoord;
	glm::vec3 color;
	glm::vec3 normal;
};

#endif /* MODELS_VERTEX_H_ */
