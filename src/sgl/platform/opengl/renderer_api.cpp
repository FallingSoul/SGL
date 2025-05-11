#include <glad/gl.h>
#include "sgl/platform/opengl/renderer_api.h"

#include "sgl/platform/opengl/vertex_array.h"
#include "sgl/platform/opengl/shader.h"

namespace sgl
{
	sglOpenGLRendererAPI::sglOpenGLRendererAPI()
		:sglRendererAPI(__sglImplConstruction__{})
	{ }
	void sglOpenGLRendererAPI::set_clear_color(float r, float g, float b, float a) 
	{
		glClearColor(r,g,b,a);
	}
	void sglOpenGLRendererAPI::clear() 
	{
		// Clear All
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	void sglOpenGLRendererAPI::draw_array(sglRef<sglVertexArray> vertex_array)
	{
		vertex_array->get_self().dynamic_self_cast<sglOpenGLVertexArray>()->bind();
		glDrawArrays(GL_TRIANGLES, 0, vertex_array->get_count());
		vertex_array->get_self().dynamic_self_cast<sglOpenGLVertexArray>()->unbind();
	}
	void sglOpenGLRendererAPI::draw_indexed(sglRef<sglVertexArray> vertex_array)
	{
		vertex_array->get_self().dynamic_self_cast<sglOpenGLVertexArray>()->bind();
		glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(vertex_array->get_count()), GL_UNSIGNED_INT, nullptr);
		vertex_array->get_self().dynamic_self_cast<sglOpenGLVertexArray>()->unbind();
	}
	sglGraphicsAPI sglOpenGLRendererAPI::get_api()const
	{
		return sglGraphicsAPI::OpenGL;
	}
}