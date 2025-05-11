#include "sgl/core/renderer/graphics_context.h"
#include "sgl/core/assert.h"
#include "sgl/platform/opengl/graphics_context.h"

namespace sgl
{

	__sgl_Self__<sglGraphicsContext> sglGraphicsContext::create(const sglGraphicsContextProperties& prop)
	{
		switch (prop.api)
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglGraphicsContext>::make<sglOpenGLGraphicsContext>(prop);
		}
		SGL_ASSERT(false, "Unkown Graphics API!");
		return {};
	}
}