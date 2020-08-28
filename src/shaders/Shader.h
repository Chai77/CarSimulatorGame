#ifndef SHADERS_SHADER_H_
#define SHADERS_SHADER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

#include <GL/glew.h>

class Shader {
private:
	GLint programId;

	std::string getShaderSource(const char* fileName);
	GLint compileShader(const char* shaderSrc, GLenum shaderType);
	void generateProgram(GLint& vertexShader, GLint& fragmentShader);
public:
	Shader(const char* vertexShaderFileName, const char* fragmentShaderFileName);
	~Shader();

	void use();
	void unuse();
};

#endif /* SHADERS_SHADER_H_ */
