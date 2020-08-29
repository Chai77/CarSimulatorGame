#ifndef SHADERS_SHADER_H_
#define SHADERS_SHADER_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdexcept>

#include <GL/glew.h>
#include <glm.hpp>
#include <mat4x4.hpp>
#include <vec3.hpp>
#include <vec4.hpp>
#include <vec2.hpp>
#include <gtc/type_ptr.hpp>

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

	void seti(const char* name, int value);
	void setMat4f(const char* name, glm::mat4 value);
};

#endif /* SHADERS_SHADER_H_ */
