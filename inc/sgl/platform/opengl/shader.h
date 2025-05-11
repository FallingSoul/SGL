#ifndef __SGL_PLATFORM_OPENGL_SHADER__
#define __SGL_PLATFORM_OPENGL_SHADER__

#include "sgl/core/renderer/shader.h"

namespace sgl
{
	class SGL_API sglOpenGLShader : public sglShader
	{
	public:
		sglOpenGLShader(const sglOpenGLShader&) = delete;
	public:
		sglOpenGLShader();
		virtual ~sglOpenGLShader();
	public:
		virtual void set_uniform_sampler(const char* uniform_name, uint32_t index);
		virtual void set_uniform_binding(const char* uniform_name, uint32_t index);
		virtual void use()const;
		virtual void compile(const std::string& vert_source, const std::string& frag_source);
		virtual uint32_t get_id()const;
	private:
		uint32_t _id;
	};
}

#endif //!