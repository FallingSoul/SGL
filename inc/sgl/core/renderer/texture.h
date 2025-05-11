#ifndef __SGL_RENDERER_TEXTURE__
#define __SGL_RENDERER_TEXTURE__

#include "sgl/core/renderer/graphics_context.h"

namespace sgl
{

	class SGL_API sglTexture2D
	{
	public:
		static __sgl_Self__<sglTexture2D> create(sglGraphicsContext& gctx);
	public:
		sglTexture2D(const sglTexture2D&) = delete;
	public:
		sglTexture2D(sglGraphicsContext& gctx)
			:_self(create(gctx))
		{
		}
		virtual ~sglTexture2D() = default;

		virtual void upload(uint32_t index) { this->_self->upload(index); }
		virtual uint32_t get_index()const { return this->_self->get_index(); }
		virtual void image(const void* image_data, int width, int height) { this->_self->image(image_data, width, height); }
		virtual void get_size(int* width, int* height)const { this->_self->get_size(width, height); }
		virtual uint32_t get_id() { return this->_self->get_id(); }

		__sgl_Self__<sglTexture2D>& get_self() { return this->_self; }
		const __sgl_Self__<sglTexture2D>& get_self()const { return this->_self; }
	protected:
		sglTexture2D(__sglImplConstruction__) {}
	private:
		__sgl_Self__<sglTexture2D> _self;
	};
};


#endif //!__SGL_RENDERER_TEXTURE__