#pragma once

#include <string>
#include <vector>

namespace Xe
{
	class XePipeline
	{
	private:
		static std::vector<char> readFile(const std::string& filePath);
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	public:
		XePipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	};
}