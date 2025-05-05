#include "xe_pipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace Xe
{
	XePipeline::XePipeline(
		XeDevice& device,
		const std::string& vertFilePath,
		const std::string& fragFilePath,
		const PipelineConfigInfo& configInfo
	) : xeDevice(device)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath, configInfo);
	}
	void XePipeline::createGraphicsPipeline(
		const std::string&			vertFilePath,
		const std::string&			fragFilePath,
		const PipelineConfigInfo&	configInfo
	)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << vertCode.size() << ' ' << fragCode.size() << '\n';
	}

	void XePipeline::createShaderModule(const std::vector<char>& shaderCode, VkShaderModule* shaderModule)
	{
		VkShaderModuleCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
		createInfo.codeSize = shaderCode.size();
		createInfo.pCode = reinterpret_cast<const uint32_t*>(shaderCode.data()); 

		if (vkCreateShaderModule(xeDevice.device(), &createInfo, nullptr, shaderModule) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create a shader module");
		}
	}

	PipelineConfigInfo XePipeline::defaultPipelineConfigInfo(uint32_t width, uint32_t height)
	{
		return PipelineConfigInfo();
	}

	std::vector<char> XePipeline::readFile(const std::string& filePath)
	{
		std::ifstream file{ filePath, std::ios::ate | std::ios::binary };

		if (!file.is_open())
			throw std::runtime_error("Failed to open a shader file: " + filePath);

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);

		file.read(buffer.data(), fileSize);
		file.close();

		return buffer;
	}
}