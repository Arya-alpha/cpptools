// cli.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <map>
#include <string>
#include <vector>
#include <iostream>

// TODO: 在此处引用程序需要的其他标头。
namespace cli {

	struct Options {
		std::string help;
	};

	struct CommandContext {
		std::vector<std::string> history;

	};

	class CommandParser {

	public:
		int execute(const std::string& command);
		std::vector<std::string> splitToArg(std::string str);
		bool splitToKv(const std::string& str, std::string& key, std::string& value);

		static std::string trim(std::string str);
	};
} // namespace cli