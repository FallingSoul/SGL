#ifndef __SGL_PLATFORM_OPENGL_RENDERER_API__
#define __SGL_PLATFORM_OPENGL_RENDERER_API__

#include "sgl/core/renderer/renderer_api.h"

namespace sgl
{
	class SGL_API sglOpenGLRendererAPI : public sglRendererAPI
	{
	public:
		sglOpenGLRendererAPI(const sglOpenGLRendererAPI&) = delete;
	public:
		sglOpenGLRendererAPI();
		virtual ~sglOpenGLRendererAPI() = default;

	public:
		virtual void set_clear_color(float r, float g, float b, float a);
		virtual void clear();
		virtual void draw_array(sglRef<sglVertexArray> vertex_array);
		virtual void draw_indexed(sglRef<sglVertexArray> vertex_array);
		virtual sglGraphicsAPI get_api()const;
	};
}


#endif //!__SGL_PLATFORM_OPENGL_RENDERER_API__