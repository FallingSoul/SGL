#ifndef __SGL_PLATFORM_OPENGL_GRAPHICS_CONTEXT__
#define __SGL_PLATFORM_OPENGL_GRAPHICS_CONTEXT__

#include "sgl/core/renderer/graphics_context.h"

namespace sgl
{
	class SGL_API sglOpenGLGraphicsContext : public sglGraphicsContext
	{
	public:
		sglOpenGLGraphicsContext(const sglGraphicsContextProperties& prop);
		~sglOpenGLGraphicsContext();
	public:
		virtual sglGraphicsAPI get_api()const;
	private:

	private:
		std::unique_ptr<struct sglOpenGLGraphicsContextInfo> _info;
	};
}


#endif //!__SGL_PLATFORM_OPENGL_GRAPHICS_CONTEXT__