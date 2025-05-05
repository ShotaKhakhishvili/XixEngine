#pragma once

#include "xe_window.hpp"
#include "xe_pipeline.hpp"

namespace Xe
{
	class FirstApp
	{
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 800;

		void run();

	private:
		XeWindow xeWindow{ WIDTH, HEIGHT, "First App Ahh Moment" };
		XeDevice xeDevice{ xeWindow };
		XePipeline xePipeline{
			xeDevice, 
			"SourceFiles/Shaders/simple_shader.vert.spv", 
			"SourceFiles/Shaders/simple_shader.frag.spv", 
			XePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
		};
};
}