#include "sgl/core/renderer/texture.h"
#include "sgl/platform/opengl/texture.h"

namespace sgl
{

	__sgl_Self__<sglTexture2D> sglTexture2D::create(sglGraphicsContext& gctx)
	{
		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglTexture2D>::make<sglOpenGLTexture2D>();
		}
		SGL_ASSERT(false, "Unknown Graphics API!");
		return {};
	}

}