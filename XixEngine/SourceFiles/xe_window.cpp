#include "xe_window.hpp"

namespace Xe
{
	XeWindow::XeWindow(int w, int h, std::string name)
		: width(w), height(h), windowName(name)
	{
		initWindow();
	}
	XeWindow::~XeWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void XeWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
	{
	}
	void XeWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}