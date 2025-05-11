#include "sgl/core/renderer/layout.h"


#include "sgl/core/assert.h"
namespace sgl
{
	size_t sglGetLayoutTypeCount(sglShaderLayoutType type)
	{
		switch (type)
		{
		case sglShaderLayoutType::UInt:
		case sglShaderLayoutType::Int:
		case sglShaderLayoutType::Float:
			return 1;
		case sglShaderLayoutType::UInt2:
		case sglShaderLayoutType::Int2:
		case sglShaderLayoutType::Float2:
			return 2;
		case sglShaderLayoutType::UInt3:
		case sglShaderLayoutType::Int3:
		case sglShaderLayoutType::Float3:
			return 3;
		case sglShaderLayoutType::UInt4:
		case sglShaderLayoutType::Int4:
		case sglShaderLayoutType::Float4:
			return 4;
		case sglShaderLayoutType::Mat3:
			return 3 * 3;
		case sglShaderLayoutType::Mat4:
			return 4 * 4;
		}
		SGL_ASSERT(false, "Unknown Layout Type!");
		return 0;

	}
	size_t sglGetLayoutTypeSize(sglShaderLayoutType type)
	{
		switch (type)
		{
		case sglShaderLayoutType::UInt:
			return sizeof(unsigned int) * 1;
		case sglShaderLayoutType::UInt2:
			return sizeof(unsigned int) * 2;
		case sglShaderLayoutType::UInt3:
			return sizeof(unsigned int) * 3;
		case sglShaderLayoutType::UInt4:
			return sizeof(unsigned int) * 4;
		case sglShaderLayoutType::Int:
			return sizeof(int) * 1;
		case sglShaderLayoutType::Int2:
			return sizeof(int) * 2;
		case sglShaderLayoutType::Int3:
			return sizeof(int) * 3;
		case sglShaderLayoutType::Int4:
			return sizeof(int) * 4;
		case sglShaderLayoutType::Float:
			return sizeof(float) * 1;
		case sglShaderLayoutType::Float2:
			return sizeof(float) * 2;
		case sglShaderLayoutType::Float3:
			return sizeof(float) * 3;
		case sglShaderLayoutType::Float4:
			return sizeof(float) * 4;
		case sglShaderLayoutType::Mat3:
			return sizeof(float) * 3 * 3;
		case sglShaderLayoutType::Mat4:
			return sizeof(float) * 4 * 4;
		}
		SGL_ASSERT(false,"Unknown Layout Type!");
		return 0;
	}
	std::vector<sglVertexLayout> sglGenerateVertexLayout(const std::vector<sglShaderLayoutType>& types)
	{
		std::vector<sglVertexLayout> layouts(types.size());
		size_t stride = 0;

		for (size_t index = 0; index < layouts.size(); index++)
		{
			auto& layout = layouts[index];
			auto& type = types[index];
			layout.type = type;
			layout.slot = static_cast<uint32_t>(index);
			layout.normalized = false;
			layout.offset = reinterpret_cast<void*>(stride);
			stride += sglGetLayoutTypeSize(type);
		}
		for (auto& layout : layouts)
			layout.stride = stride;
		return layouts;
	}

}