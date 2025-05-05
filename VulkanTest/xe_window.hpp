#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW//glfw3.h>

#include <string>
namespace XE
{
	class XEWindow
	{
	public:
		XEWindow(int w, int h, std::string name);
		~XEWindow();

		XEWindow(const XEWindow&) = delete;
		XEWindow& operator=(const XEWindow&) = delete;

		bool shouldClose() {
			return glfwWindowShouldClose(window);
		}

	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}