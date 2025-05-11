
#include "sgl/core/assert.h"
#include "sgl/core/renderer/renderer_api.h"
#include "sgl/platform/opengl/renderer_api.h"

namespace sgl
{
	__sgl_Self__<sglRendererAPI> sglRendererAPI::create(sglGraphicsContext& gctx)
	{
		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglRendererAPI>::make<sglOpenGLRendererAPI>();
		}
		SGL_ASSERT(false,"Unknown Graphics API!");
		return {};
	}

}