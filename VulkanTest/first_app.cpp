#include "first_app.hpp"

namespace XE
{
	void FirstApp::run()
	{
		while (!xeWindow.shouldClose())
		{
			glfwPollEvents();
		}
	}
}