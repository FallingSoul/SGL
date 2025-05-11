#ifndef __SGL_CORE_RENDERER_RENDERER__
#define __SGL_CORE_RENDERER_RENDERER__


#include "sgl/core/renderer/renderer_api.h"
#include "sgl/core/renderer/shader.h"
#include "sgl/core/renderer/buffer.h"

namespace sgl
{
	class sglRenderer
	{
	public:
		sglRenderer(sglRef<sglRendererAPI> api)
			:_api(api)
		{}
		~sglRenderer()
		{}
	public:
		void begin_scene() 
		{

		}
		void submit(sglRef<sglVertexArray> vertex_array)
		{
			this->_api->draw_indexed(vertex_array);
		}
		void submit(sglRef<sglVertexArray> vertex_array, sglRef<sglShader> shader)
		{
			shader->use();
			this->_api->draw_indexed(vertex_array);
		}


		void end_scene()
		{

		}
	public:
		sglRef<sglRendererAPI> set_api(sglRef<sglRendererAPI> new_api)
		{
			auto old_api = this->_api;
			this->_api = new_api;
			return old_api;
		}
		sglRef<sglRendererAPI> get_api() { return this->_api; }
	private:
		sglRef<sglRendererAPI> _api;
	};
}


#endif //!__SGL_CORE_RENDERER_RENDERER__