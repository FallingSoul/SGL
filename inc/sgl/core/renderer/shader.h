#ifndef __SGL_CORE_RENDERER_SHADER__
#define __SGL_CORE_RENDERER_SHADER__

#include "sgl/core/renderer/graphics_context.h"
#include "sgl/core/renderer/buffer.h"

namespace sgl
{
	class SGL_API sglShader
	{
	public:
		static __sgl_Self__<sglShader> create(sglGraphicsContext& gctx);
	public:
		sglShader(const sglShader&) = delete;
	public:
		sglShader(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{}
		virtual ~sglShader() = default;

		virtual void set_uniform_sampler(const char* uniform_name, uint32_t index) { this->_self->set_uniform_sampler(uniform_name, index); }
		virtual void set_uniform_binding(const char* uniform_name, uint32_t index) { this->_self->set_uniform_binding(uniform_name, index); }
		virtual void use()const { this->_self->use(); }
		virtual void compile(const std::string& vert_sources, const std::string& frag_sources) { this->_self->compile(vert_sources, frag_sources); }
		virtual uint32_t get_id()const { return this->_self->get_id(); }

		__sgl_Self__<sglShader>& get_self() { return this->_self; }
		const __sgl_Self__<sglShader>& get_self()const { return this->_self; }
	protected:
		sglShader(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglShader> _self;
	};
}


#endif //!__SGL_CORE_RENDERER_SHADER__