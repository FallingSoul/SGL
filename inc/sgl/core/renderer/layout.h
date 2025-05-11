#ifndef __SGL_CORE_RENDERER_LAYOUT__
#define __SGL_CORE_RENDERER_LAYOUT__

#include "sgl/core/renderer/graphics_context.h"

namespace sgl
{
	enum class sglShaderLayoutType
	{
		UInt,
		UInt2,
		UInt3,
		UInt4,
		Int,
		Int2,
		Int3,
		Int4,
		Float,
		Float2,
		Float3,
		Float4,
		Mat3,
		Mat4
	};
	struct sglIndexLayout
	{
		sglShaderLayoutType type;
	};
	struct sglVertexLayout
	{
		sglShaderLayoutType type;
		uint32_t slot;
		bool normalized;
		size_t stride;
		void* offset;
	};
	struct sglUniformLayout
	{
		sglShaderLayoutType type;
		std::string name;
	};
	size_t SGL_API sglGetLayoutTypeCount(sglShaderLayoutType type);
	size_t SGL_API sglGetLayoutTypeSize(sglShaderLayoutType type);

	std::vector<sglVertexLayout> SGL_API sglGenerateVertexLayout(const std::vector<sglShaderLayoutType>& types);
}


#endif //!__SGL_CORE_RENDERER_LAYOUT__