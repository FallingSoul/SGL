#include "sgl/core/renderer/buffer.h"

#include "sgl/core/assert.h"
#include "sgl/platform/opengl/buffer.h"

namespace sgl
{

	__sgl_Self__<sglVertexBuffer> sglVertexBuffer::create(sglGraphicsContext& gctx)
	{
		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglVertexBuffer>::make<sglOpenGLVertexBuffer>();
		}
		SGL_ASSERT(false,"Unknown Graphics API!");
		return {};
	}
	__sgl_Self__<sglIndexBuffer> sglIndexBuffer::create(sglGraphicsContext& gctx)
	{
		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglIndexBuffer>::make<sglOpenGLIndexBuffer>();
		}
		SGL_ASSERT(false, "Unknown Graphics API!");
		return {};

	}
	__sgl_Self__<sglUniformBuffer> sglUniformBuffer::create(sglGraphicsContext& gctx)
	{
		switch (gctx.get_api())
		{
		case sglGraphicsAPI::OpenGL:
			return __sgl_Self__<sglUniformBuffer>::make<sglOpenGLUniformBuffer>();
		}
		SGL_ASSERT(false, "Unknown Graphics API!");
		return {};

	}
}