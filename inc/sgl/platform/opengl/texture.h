#ifndef __SGL_PLATFORM_OPENGL_TEXTURE__
#define __SGL_PLATFORM_OPENGL_TEXTURE__
#include "sgl/core/renderer/texture.h"

namespace sgl
{
	class sglOpenGLTexture2D : public sglTexture2D
	{
	public:
		sglOpenGLTexture2D();
		~sglOpenGLTexture2D();

		void bind()const;
		void unbind()const;
		virtual void upload(uint32_t index);
		virtual uint32_t get_index()const;
		virtual void image(const void* image_data, int width, int height);
		virtual void get_size(int* width, int* height)const;
		virtual uint32_t get_id();
	private:
		uint32_t _index;
		uint32_t _id;
	};
}

#endif //!__SGL_PLATFORM_OPENGL_TEXTURE__