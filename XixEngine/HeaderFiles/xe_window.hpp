#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW//glfw3.h>

#include <string>
namespace Xe
{
	class XeWindow
	{
	public:
		XeWindow(int w, int h, std::string name);
		~XeWindow();

		XeWindow(const XeWindow&) = delete;
		XeWindow& operator=(const XeWindow&) = delete;

		bool shouldClose() {
			return glfwWindowShouldClose(window);
		}

		void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

	private:
		void initWindow();

		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;
	};
}