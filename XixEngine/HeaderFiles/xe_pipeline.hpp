#pragma once

#include "xe_device.hpp"

// std
#include <string>
#include <vector>

namespace Xe
{
	struct PipelineConfigInfo 
	{

	};

	class XePipeline
	{
	private:
		XeDevice& xeDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

		static std::vector<char> readFile(const std::string& filePath);

		void createGraphicsPipeline(
			const std::string&			vertFilePath, 
			const std::string&			fragFilePath, 
			const PipelineConfigInfo&	configInfo
		);

		void createShaderModule(const std::vector<char>& shaderCode, VkShaderModule* shaderModule);

	public:
		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

		XePipeline(
			XeDevice&				device,
			const std::string&			vertFilePath,
			const std::string&			fragFilePath,
			const PipelineConfigInfo&	configInfo
		);
		~XePipeline(){}

		XePipeline(const XePipeline&) = delete;
		void operator=(const XePipeline&) = delete;
	};
}