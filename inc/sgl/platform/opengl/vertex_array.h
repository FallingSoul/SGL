#ifndef __SGL_PLATFORM_OPENGL_VERTEX_ARRAY__
#define __SGL_PLATFORM_OPENGL_VERTEX_ARRAY__

#include "sgl/core/renderer/vertex_array.h"
#include "sgl/platform/opengl/buffer.h"


namespace sgl
{
	class SGL_API sglOpenGLVertexArray : public sglVertexArray
	{
	public:
		sglOpenGLVertexArray(const sglOpenGLVertexArray&) = delete;
	public:
		sglOpenGLVertexArray();
		virtual ~sglOpenGLVertexArray();
		void bind()const;
		void unbind()const;
		virtual void add_vertex_buffer(sglRef<sglVertexBuffer> buffer, const std::vector<sglVertexLayout>& layouts);
		virtual void set_index_buffer(sglRef<sglIndexBuffer> buffer);
		virtual void set_count(uint32_t count);
		virtual uint32_t get_count()const;
		virtual uint32_t get_id()const;
		virtual void draw()const;

	private:
		uint32_t _id;
		uint32_t _count;
		sglRef<sglIndexBuffer> _ibo;
	};
}

#endif //!__SGL_PLATFORM_OPENGL_VERTEX_ARRAY__