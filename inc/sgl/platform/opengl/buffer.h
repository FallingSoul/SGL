#ifndef __SGL_PLATFORM_OPENGL_BUFFERS__
#define __SGL_PLATFORM_OPENGL_BUFFERS__

#include "sgl/core/renderer/buffer.h"

namespace sgl
{
	class SGL_API sglOpenGLVertexBuffer : public sglVertexBuffer
	{
	public:
		sglOpenGLVertexBuffer(const sglOpenGLVertexBuffer&) = delete;
	public:
		sglOpenGLVertexBuffer();
		virtual ~sglOpenGLVertexBuffer();
		void bind()const;
		void unbind()const;
		virtual void set_data(const float* vertices, size_t size);
		virtual void set_subdata(const void* data, size_t size, size_t offset);

		virtual uint32_t get_id()const;
	private:
		uint32_t _id;
	};
	class SGL_API sglOpenGLIndexBuffer : public sglIndexBuffer
	{
	public:
		sglOpenGLIndexBuffer(const sglOpenGLIndexBuffer&) = delete;
	public:
		sglOpenGLIndexBuffer();
		virtual ~sglOpenGLIndexBuffer();
		void bind()const;
		void unbind()const;
		virtual uint32_t get_count()const;
		virtual void set_data(const unsigned* indices, uint32_t count);

		virtual uint32_t get_id()const;
	private:
		uint32_t _id;
		uint32_t _count;
	};
	class SGL_API sglOpenGLUniformBuffer : public sglUniformBuffer
	{
	public:
		sglOpenGLUniformBuffer(const sglOpenGLUniformBuffer&) = delete;
	public:
		sglOpenGLUniformBuffer();
		virtual ~sglOpenGLUniformBuffer();
		void bind()const;
		void unbind()const;
		virtual void set_binding(uint32_t index);
		virtual void set_binding_range(uint32_t index, size_t size, size_t offset);
		virtual void set_data(const void* data, size_t size);
		virtual void set_subdata(const void* data, size_t size, size_t offset);

		virtual uint32_t get_id()const;
	private:
		uint32_t _id;
		uint32_t _index;
	};
}



#endif //!__SGL_PLATFORM_OPENGL_BUFFERS__