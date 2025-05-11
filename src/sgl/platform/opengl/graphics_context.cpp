#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include "sgl/core/assert.h"
#include "sgl/platform/opengl/graphics_context.h"

namespace sgl
{

	class sglOpenGLInitializer
	{
	public:
		sglOpenGLInitializer()
		{

			auto version = gladLoadGL(glfwGetProcAddress);
			SGL_ASSERT(version,"Failed to Initialize OpenGL!");
			SGL_LOG_D("OpenGL Vendor: {}", (const char *)glGetString(GL_VENDOR));
			SGL_LOG_D("OpenGL Renderer: {}", (const char*)glGetString(GL_RENDERER));
			SGL_LOG_D("OpenGL Version: {}", (const char*)glGetString(GL_VERSION));
			
		}
		~sglOpenGLInitializer()
		{
		}

	};
	struct sglOpenGLGraphicsContextInfo
	{

	};

	sglOpenGLGraphicsContext::sglOpenGLGraphicsContext(const sglGraphicsContextProperties& prop) 
		:sglGraphicsContext(__sglImplConstruction__{})
	{
		static sglOpenGLInitializer __sgl_opengl_initializer__;
	}
	sglOpenGLGraphicsContext::~sglOpenGLGraphicsContext() {}
	sglGraphicsAPI sglOpenGLGraphicsContext::get_api()const
	{
		return sglGraphicsAPI::OpenGL;
	}
}