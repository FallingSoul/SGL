#include <glad/gl.h>
#include "sgl/platform/opengl/shader.h"

namespace sgl
{
	GLuint sglCompileShader(GLint target, const std::string& source)
	{
		GLuint shader = glCreateShader(target);
		const char* src[] = { source.c_str() };
		GLint length[] = { static_cast<GLint>(source.size()) };
		glShaderSource(shader, 1, src, length);
		glCompileShader(shader);
		GLint compile_status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
		if (!compile_status)
		{
			GLint info_len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_len);
			std::string info;
			info.resize(info_len);
			glGetShaderInfoLog(shader, info_len, nullptr, info.data());
			SGL_ASSERT(false,"Failed to Compile Shader: {}",info.c_str());
		}
		return shader;
	}

	sglOpenGLShader::sglOpenGLShader() 
		:_id(glCreateProgram()), sglShader(__sglImplConstruction__{})
	{
	}
	sglOpenGLShader::~sglOpenGLShader() 
	{
		glDeleteProgram(this->_id);
	}
	void sglOpenGLShader::compile(const std::string& vert_source, const std::string& frag_source)
	{
		GLuint vert_shader = sglCompileShader(GL_VERTEX_SHADER, vert_source);
		GLuint frag_shader = sglCompileShader(GL_FRAGMENT_SHADER, frag_source);

		glAttachShader(this->_id, vert_shader);
		glAttachShader(this->_id, frag_shader);
		glLinkProgram(this->_id);
		GLint link_status;
		glGetProgramiv(this->_id, GL_LINK_STATUS, &link_status);
		if (!link_status)
		{
			GLint info_len;
			glGetProgramiv(this->_id, GL_INFO_LOG_LENGTH, &info_len);
			std::string info;
			info.resize(info_len);
			glGetProgramInfoLog(this->_id, info_len, nullptr, info.data());
			SGL_ASSERT(false,"Failed to Link Shader Program: {}",info.c_str());
		}

		glDeleteShader(frag_shader);
		glDeleteShader(vert_shader);
	}
	void sglOpenGLShader::set_uniform_sampler(const char* uniform_name, uint32_t index)
	{
		this->use();
		auto location = glGetUniformLocation(this->_id, uniform_name);
		glUniform1i(location, index);
	}
	void sglOpenGLShader::set_uniform_binding(const char* uniform_name, uint32_t index)
	{
		GLuint block = glGetUniformBlockIndex(this->_id, uniform_name);
		glUniformBlockBinding(this->_id, block, index);
	}
	void sglOpenGLShader::use()const
	{
		glUseProgram(this->_id);
	}
	uint32_t sglOpenGLShader::get_id()const
	{
		return this->_id;
	}
}