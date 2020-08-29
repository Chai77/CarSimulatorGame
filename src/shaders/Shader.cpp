#include "Shader.h"

std::string Shader::getShaderSource(const char* fileName) {
	std::stringstream srcStringStream;

	std::ifstream in_file(fileName);
	if(!in_file) {
		std::stringstream stream;
		stream << "The file named " << fileName << " could not be loaded" << "\n";
		throw std::runtime_error(stream.str());
	}

	std::string line;

	while(std::getline(in_file, line)) {
		srcStringStream << line << "\n";
	}

	std::string val = srcStringStream.str();

	return val;
}

GLint Shader::compileShader(const char* shaderSrc, GLenum shaderType) {
	GLint shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSrc, NULL);
	glCompileShader(shader);
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success) {
		std::stringstream stream;
		const char* shaderTypeString = shaderType == GL_VERTEX_SHADER ? "Vertex Shader" : GL_FRAGMENT_SHADER ? "Fragment Shader" : "Shader";
		stream << "There was an error compiling the " << shaderTypeString << "\n";
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << infoLog << "\n";
		throw std::runtime_error(stream.str());
	}
	return shader;
}

void Shader::generateProgram(GLint& vertexShader, GLint& fragmentShader) {
	this->programId = glCreateProgram();
	glAttachShader(this->programId, vertexShader);
	glAttachShader(this->programId, fragmentShader);
	glLinkProgram(this->programId);

	int success;
	char infoLog[512];

	glGetProgramiv(this->programId, GL_LINK_STATUS, &success);
	if(!success) {
	    glGetProgramInfoLog(this->programId, 512, NULL, infoLog);
	    std::cout << infoLog << "\n";
		std::stringstream stream;
		stream << "There was an error linking the shader program";
		throw std::runtime_error(stream.str());
	}


	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexShaderFileName, const char* fragmentShaderFileName) {
	std::string vertexShaderSrcString = this->getShaderSource(vertexShaderFileName);
	std::string fragmentShaderSrcString = this->getShaderSource(fragmentShaderFileName);

	const char* vertexShaderSrc = vertexShaderSrcString.c_str();
	const char* fragmentShaderSrc = fragmentShaderSrcString.c_str();

	GLint vertexShader = this->compileShader(vertexShaderSrc, GL_VERTEX_SHADER);
	GLint fragmentShader = this->compileShader(fragmentShaderSrc, GL_FRAGMENT_SHADER);

	this->generateProgram(vertexShader, fragmentShader);
}

Shader::~Shader() {
	glDeleteProgram(this->programId);
}

void Shader::use() {
	glUseProgram(this->programId);
}

void Shader::unuse() {
	glUseProgram(0);
}

void Shader::seti(const char* name, int value) {
	this->use();
	glUniform1i(glGetUniformLocation(this->programId, name), value);
	this->unuse();
}

void Shader::setMat4f(const char* name, glm::mat4 value) {
	this->use();
	glUniformMatrix4fv(glGetUniformLocation(this->programId, name), 1, GL_FALSE, glm::value_ptr(value));
	this->unuse();
}
