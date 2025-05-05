#include "first_app.hpp"

namespace Xe
{
	void FirstApp::run()
	{
		while (!xeWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}
}