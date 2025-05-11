#include "sgl/core/renderer/shader.h"

#include "sgl/core/assert.h"
#include "sgl/platform/opengl/shader.h"
namespace sgl
{
	__sgl_Self__<sglShader> sglShader::create(sglGraphicsContext& gctx)
	{

		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglShader>::make<sglOpenGLShader>();
		}
		SGL_ASSERT(false,"Unknown Graphics API!");
		return {};
	}
}