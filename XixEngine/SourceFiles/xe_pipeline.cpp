#include "xe_pipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

namespace Xe
{
	std::vector<char> XePipeline::readFile(const std::string& filePath)
	{
		std::ifstream file{filePath, std::ios::ate | std::ios::binary};

		if (!file.is_open())
			throw std::runtime_error("Failed to open a shader file: " + filePath);

		size_t fileSize = static_cast<size_t>(file.tellg());
		std::vector<char> buffer(fileSize);

		file.seekg(0);

		file.read(buffer.data(), fileSize);
		file.close();

		return buffer;
	}
	void XePipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		auto vertCode = readFile(vertFilePath);
		auto fragCode = readFile(fragFilePath);

		std::cout << vertCode.size() << ' ' << fragCode.size() << '\n';
	}
	XePipeline::XePipeline(const std::string& vertFilePath, const std::string& fragFilePath)
	{
		createGraphicsPipeline(vertFilePath, fragFilePath);
	}
}