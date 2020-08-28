#ifndef MODELS_TEXTUREMODEL_H_
#define MODELS_TEXTUREMODEL_H_

#include "Model.h"

class TextureModel : public Model {
public:
	TextureModel(Vertex* vertices, int nrOfVertices, GLuint* indices, int nrOfIndices, Texture* texture);
	~TextureModel();
};

#endif /* MODELS_TEXTUREMODEL_H_ */
