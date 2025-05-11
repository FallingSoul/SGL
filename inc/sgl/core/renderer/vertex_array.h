#ifndef __SGL_CORE_RENDERER_VERTX_ARRAY__
#define __SGL_CORE_RENDERER_VERTX_ARRAY__

#include "sgl/core/renderer/graphics_context.h"
#include "sgl/core/renderer/buffer.h"
#include "sgl/core/renderer/layout.h"

namespace sgl
{
	class SGL_API sglVertexArray
	{
	public:
		__sgl_Self__<sglVertexArray> create(sglGraphicsContext& gctx);
	public:
		sglVertexArray(const sglVertexArray&) = delete;
	public:
		sglVertexArray(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{ }
		virtual ~sglVertexArray() = default;
	public:
		virtual void add_vertex_buffer(sglRef<sglVertexBuffer> buffer, const std::vector<sglVertexLayout>& layouts) { this->_self->add_vertex_buffer(buffer,layouts); }
		virtual void set_index_buffer(sglRef<sglIndexBuffer> buffer) { this->_self->set_index_buffer(buffer); }
		virtual void set_count(uint32_t count) { this->_self->set_count(count); }
		virtual uint32_t get_count()const { return this->_self->get_count(); }
		virtual uint32_t get_id()const { return this->_self->get_id(); }

		__sgl_Self__<sglVertexArray>& get_self() { return this->_self; }
		const __sgl_Self__<sglVertexArray>& get_self()const { return this->_self; }
	public:
		virtual void draw()const { this->_self->draw(); }
	protected:
		sglVertexArray(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglVertexArray> _self;
	};
}

#endif //!__SGL_CORE_RENDERER_VERTX_ARRAY__