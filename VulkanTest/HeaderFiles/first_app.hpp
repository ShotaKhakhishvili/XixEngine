#pragma once

#include "xe_window.hpp"
#include "xe_pipeline.hpp"

namespace XE
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 800;

		void run();

	private:
		XEWindow xeWindow{ WIDTH, HEIGHT, "First App Ahh Moment" };
		XEPipeline xePipeline{"SourceFiles/Shaders/simple_shader.vert.spv", "SourceFiles/Shaders/simple_shader.frag.spv"};
};
}