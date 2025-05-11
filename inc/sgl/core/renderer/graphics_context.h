#ifndef __SGL_CORE_RENDERER_GRAPHICS_CONTEXT__
#define __SGL_CORE_RENDERER_GRAPHICS_CONTEXT__

#include "sgl/core/window.h"

namespace sgl
{
	enum class sglGraphicsAPI
	{
		OpenGL
	};
	struct sglGraphicsContextProperties
	{
		sglRef<sglWindow> window;
		sglGraphicsAPI api;
	};
	class SGL_API sglGraphicsContext
	{
	public:
		static __sgl_Self__<sglGraphicsContext> create(const sglGraphicsContextProperties& prop);
	public:
		sglGraphicsContext(const sglGraphicsContextProperties& prop)
			:_self(create(prop))
		{ }
		virtual ~sglGraphicsContext() = default;
	public:
		virtual sglGraphicsAPI get_api()const { return this->_self->get_api(); }


		__sgl_Self__<sglGraphicsContext>& get_self() { return this->_self; }
		const __sgl_Self__<sglGraphicsContext>& get_self()const { return this->_self; }
	protected:
		sglGraphicsContext(const sglGraphicsContext&) = delete;
		sglGraphicsContext(__sglImplConstruction__ impl) {};

	private:
		__sgl_Self__<sglGraphicsContext> _self;
	};
}


#endif //!__SGL_CORE_RENDERER_GRAPHICS_CONTEXT__