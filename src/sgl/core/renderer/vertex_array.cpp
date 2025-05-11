#include "sgl/core/renderer/vertex_array.h"

#include "sgl/core/assert.h"
#include "sgl/platform/opengl/vertex_array.h"

namespace sgl
{
	__sgl_Self__<sglVertexArray> sglVertexArray::create(sglGraphicsContext& gctx)
	{
		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglVertexArray>::make<sglOpenGLVertexArray>();
		}
		SGL_ASSERT(false,"Unknown Graphics API!");
		return {};
	}
}