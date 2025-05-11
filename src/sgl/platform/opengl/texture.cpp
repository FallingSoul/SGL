#include <glad/gl.h>
#include "sgl/platform/opengl/texture.h"


namespace sgl
{

	sglOpenGLTexture2D::sglOpenGLTexture2D()
		:_id(~0), _index(0), sglTexture2D(__sglImplConstruction__{})
	{
		GLuint texture;
		glGenTextures(1, &texture);
		this->_id = texture;
	}
	sglOpenGLTexture2D::~sglOpenGLTexture2D()
	{
		GLuint texture = this->_id;
		glDeleteTextures(1, &texture);
	}

	void sglOpenGLTexture2D::bind()const
	{
		glBindTexture(GL_TEXTURE_2D, this->_id);
	}
	void sglOpenGLTexture2D::unbind()const
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	void sglOpenGLTexture2D::image(const void* image_data, int width, int height)
	{
		this->bind();
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
		glGenerateMipmap(GL_TEXTURE_2D);
		this->unbind();
	}
	void sglOpenGLTexture2D::get_size(int* width, int* height)const
	{
		if (width)
		{
			GLint x;
			glGetTextureParameteriv(this->_id, GL_TEXTURE_WIDTH, &x);
			*width = x;
		}
		if (height)
		{
			GLint y;
			glGetTextureParameteriv(this->_id, GL_TEXTURE_WIDTH, &y);
			*height = y;
		}
	}
	void sglOpenGLTexture2D::upload(uint32_t index)
	{
		this->_index = index;
		glActiveTexture(GL_TEXTURE0 + index);
		this->bind();
	}
	uint32_t sglOpenGLTexture2D::get_index()const
	{
		return this->_index;
	}
	uint32_t sglOpenGLTexture2D::get_id()
	{
		return this->_id;
	}
}