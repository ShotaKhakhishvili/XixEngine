#pragma once

#include <string>
#include <vector>

namespace XE
{
	class XEPipeline
	{
	private:
		static std::vector<char> readFile(const std::string& filePath);
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	public:
		XEPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
	};
}