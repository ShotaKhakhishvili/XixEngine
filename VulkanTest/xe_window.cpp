#include "xe_window.hpp"

namespace XE
{
	XEWindow::XEWindow(int w, int h, std::string name)
		: width(w), height(h), windowName(name)
	{
		initWindow();
	}
	XEWindow::~XEWindow()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void XEWindow::initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
}