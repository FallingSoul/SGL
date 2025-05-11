#include <glad/gl.h>
#include "sgl/platform/opengl/buffer.h"

namespace sgl
{
	sglOpenGLVertexBuffer::sglOpenGLVertexBuffer() 
		:_id(~0), sglVertexBuffer(__sglImplConstruction__{})
	{
		GLuint buffer;
		glGenBuffers(1, &buffer);
		this->_id = buffer;
	}
	sglOpenGLVertexBuffer::~sglOpenGLVertexBuffer() 
	{
		GLuint buffer = this->_id;
		glDeleteBuffers(1,&buffer);
	}
	void sglOpenGLVertexBuffer::bind()const 
	{
		glBindBuffer(GL_ARRAY_BUFFER,this->_id);
	}
	void sglOpenGLVertexBuffer::unbind()const 
	{
		glBindBuffer(GL_ARRAY_BUFFER,0);
	}
	void sglOpenGLVertexBuffer::set_data(const float* vertices, size_t size)
	{
		this->bind();
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		this->unbind();
	}
	void sglOpenGLVertexBuffer::set_subdata(const void* data, size_t size, size_t offset)
	{
		this->bind();
		glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
		this->unbind();
	}
	uint32_t sglOpenGLVertexBuffer::get_id()const
	{
		return this->_id;
	}

	sglOpenGLIndexBuffer::sglOpenGLIndexBuffer()
		:_id(~0), _count(0), sglIndexBuffer(__sglImplConstruction__{})
	{
		GLuint buffer;
		glGenBuffers(1, &buffer);
		this->_id = buffer;
	}
	sglOpenGLIndexBuffer::~sglOpenGLIndexBuffer() 
	{
		GLuint buffer = this->_id;
		glDeleteBuffers(1, &buffer);
	}
	void sglOpenGLIndexBuffer::bind()const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->_id);
	}
	void sglOpenGLIndexBuffer::unbind()const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	uint32_t sglOpenGLIndexBuffer::get_count()const
	{
		return this->_count;
	}
	void sglOpenGLIndexBuffer::set_data(const unsigned* indices, uint32_t count) 
	{
		this->bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,count * sizeof(unsigned),indices,GL_STATIC_DRAW);
		this->_count = count;
		this->unbind();
	}
	uint32_t sglOpenGLIndexBuffer::get_id()const
	{
		return this->_id;
	}


	sglOpenGLUniformBuffer::sglOpenGLUniformBuffer()
		:_id(~0), _index(~0), sglUniformBuffer(__sglImplConstruction__{})
	{
		GLuint buffer;
		glGenBuffers(1, &buffer);
		this->_id = buffer;
	}
	sglOpenGLUniformBuffer::~sglOpenGLUniformBuffer() 
	{
		GLuint buffer = this->_id;
		glDeleteBuffers(1, &buffer);
	}
	void sglOpenGLUniformBuffer::bind()const 
	{
		glBindBuffer(GL_UNIFORM_BUFFER,this->_id);
	}
	void sglOpenGLUniformBuffer::unbind()const 
	{
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
	void sglOpenGLUniformBuffer::set_binding(uint32_t index)
	{
		glBindBufferBase(GL_UNIFORM_BUFFER, index, this->_id);
	}
	void sglOpenGLUniformBuffer::set_binding_range(uint32_t index, size_t size, size_t offset)
	{
		glBindBufferRange(GL_UNIFORM_BUFFER, index, this->_id, offset, size);
	}
	void sglOpenGLUniformBuffer::set_data(const void* data, size_t size)
	{
		this->bind();
		glBufferData(GL_UNIFORM_BUFFER, size, data, GL_STATIC_DRAW);
		this->unbind();
	}
	void sglOpenGLUniformBuffer::set_subdata(const void* data, size_t size, size_t offset)
	{
		this->bind();
		glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
		this->unbind();
	}
	uint32_t sglOpenGLUniformBuffer::get_id()const
	{
		return this->_id;
	}
}