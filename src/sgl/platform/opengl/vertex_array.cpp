#include <glad/gl.h>
#include "sgl/platform/opengl/vertex_array.h"

namespace sgl
{
	GLenum sglConvertLayoutType(sglShaderLayoutType type)
	{
		switch (type)
		{
		case sglShaderLayoutType::UInt:
		case sglShaderLayoutType::UInt2:
		case sglShaderLayoutType::UInt3:
		case sglShaderLayoutType::UInt4:
			return GL_UNSIGNED_INT;
		case sglShaderLayoutType::Int:
		case sglShaderLayoutType::Int2:
		case sglShaderLayoutType::Int3:
		case sglShaderLayoutType::Int4:
			return GL_INT;
		case sglShaderLayoutType::Float:
		case sglShaderLayoutType::Float2:
		case sglShaderLayoutType::Float3:
		case sglShaderLayoutType::Float4:
			return GL_FLOAT;
		case sglShaderLayoutType::Mat3:
		case sglShaderLayoutType::Mat4:
			return GL_FLOAT;
		}
		SGL_ASSERT(false,"Unknown Layout Type!");
		return ~0;
	}
	sglOpenGLVertexArray::sglOpenGLVertexArray()
		:_id(~0),_count(0), sglVertexArray(__sglImplConstruction__{})
	{
		GLuint vertex_array;
		glGenVertexArrays(1, &vertex_array);
		this->_id = vertex_array;
	}
	sglOpenGLVertexArray::~sglOpenGLVertexArray() 
	{
		GLuint vertex_array = this->_id;
		glDeleteVertexArrays(1,&vertex_array);
	}
	void sglOpenGLVertexArray::bind()const 
	{
		glBindVertexArray(this->_id);
		if (this->_ibo)this->_ibo->get_self().dynamic_self_cast<sglOpenGLIndexBuffer>()->bind();
	}
	void sglOpenGLVertexArray::unbind()const 
	{
		if (this->_ibo)this->_ibo->get_self().dynamic_self_cast<sglOpenGLIndexBuffer>()->unbind();
		glBindVertexArray(0);
	}
	void sglOpenGLVertexArray::add_vertex_buffer(sglRef<sglVertexBuffer> buffer, const std::vector<sglVertexLayout>& layouts)
	{
		this->bind();
		buffer->get_self().dynamic_self_cast<sglOpenGLVertexBuffer>()->bind();
		for(auto& layout : layouts)
		{
			glEnableVertexAttribArray(layout.slot);
			glVertexAttribPointer(
				layout.slot,
				static_cast<GLsizei>(sglGetLayoutTypeCount(layout.type)), 
				sglConvertLayoutType(layout.type),
				layout.normalized ? GL_TRUE  : GL_FALSE,
				static_cast<GLint>(layout.stride), 
				layout.offset);
		}
		buffer->get_self().dynamic_self_cast<sglOpenGLVertexBuffer>()->unbind();
		this->unbind();
	}
	void sglOpenGLVertexArray::set_index_buffer(sglRef<sglIndexBuffer> buffer)
	{
		this->_ibo = buffer;
		this->_count = this->_ibo->get_count();
	}
	void sglOpenGLVertexArray::set_count(uint32_t count)
	{
		this->_count = count;
	}
	uint32_t sglOpenGLVertexArray::get_count()const
	{
		return this->_count;
	}
	uint32_t sglOpenGLVertexArray::get_id()const
	{
		return this->_id;
	} 
	void sglOpenGLVertexArray::draw()const
	{
		if (this->_ibo)
		{
			this->bind();
			this->_ibo->get_self().dynamic_self_cast<sglOpenGLIndexBuffer>()->bind();
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(this->_count), GL_UNSIGNED_INT, nullptr);
			this->_ibo->get_self().dynamic_self_cast<sglOpenGLIndexBuffer>()->unbind();
			this->unbind();
		}
		else
		{
			glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(this->get_count()));
		}
	}
}