#ifndef __SGL_CORE_RENDERER_RENDERER_API__
#define __SGL_CORE_RENDERER_RENDERER_API__

#include "sgl/core/renderer/graphics_context.h"
#include "sgl/core/renderer/vertex_array.h"

namespace sgl
{
	class SGL_API sglRendererAPI
	{
	public:
		static __sgl_Self__<sglRendererAPI> create(sglGraphicsContext& gctx);
	public:
		sglRendererAPI(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{}
		virtual ~sglRendererAPI() = default;
	public:
		virtual void set_clear_color(float r, float g, float b, float a) { this->_self->set_clear_color(r,g,b,a); }
		virtual void clear() { this->_self->clear(); }
		virtual void draw_array(sglRef<sglVertexArray> vertex_array) { this->_self->draw_array(vertex_array); }
		virtual void draw_indexed(sglRef<sglVertexArray> vertex_array) { this->_self->draw_indexed(vertex_array); }
		virtual sglGraphicsAPI get_api()const { return this->_self->get_api(); }


		__sgl_Self__<sglRendererAPI>& get_self() { return this->_self; }
		const __sgl_Self__<sglRendererAPI>& get_self()const { return this->_self; }
	protected:
		sglRendererAPI(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglRendererAPI> _self;
	};
}


#endif //!__SGL_CORE_RENDERER_RENDERER_API__