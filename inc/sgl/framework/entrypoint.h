#ifndef __SGL_FRAMEWORK_ENTRYPOINT__
#define __SGL_FRAMEWORK_ENTRYPOINT__

#include "sgl/framework/application.h"

namespace sgl
{
}

int main(int argc, const char* argv[])
{
	auto app = sgl::sglCreateApplication();
	if (app)
	{
		app->run();
		sgl::sglReleaseApplication(app);
	}
	return 0;
}
#endif //!__SGL_FRAMEWORK_ENTRYPOINT__