// cli.cpp: 定义应用程序的入口点。
//

#include "cli.h"
#include <sstream>

using namespace std;
using namespace cli;

int CommandParser::execute(const std::string& str) {
	std::string s = trim(str);
	if (s.empty()) {
		return 0;
	}

	std::vector<std::string> args = splitToArg(str);
	for (size_t i = 0; i < args.size(); i++) {
		const std::string& arg = args[i];
		std::string key = arg;
		std::string value;
		if (arg.rfind("--", 0) == std::string::npos) {
			bool result = splitToKv(arg, key, value);
			if (result) {
				std::cout << "k=" << key << ",v=" << value;
			}
			else {

			}
		}
	}
	if (args[0] == "help") {
		std::cout << "help content" << std::endl;
	}

	// for (auto &arg : args) {
	// 	std::cout << arg << std::endl;
	// }

	// exit
	if (args[0] == "exit") {
		return -999;
	}

	return 0;
}

std::vector<std::string> CommandParser::splitToArg(std::string str) {
	std::vector<std::string> vectors;
	std::stringstream ss(str);
	std::string word;
	while (ss >> word) {
		vectors.push_back(word);
	}

	return vectors;
}

bool CommandParser::splitToKv(const std::string& str, std::string& key, std::string& value) {
	size_t pos = str.find('=');
	if (pos == std::string::npos) {
		return false;
	}
	key = str.substr(0, pos);
	value = str.substr(pos + 1, str.size() - 1);
	return true;
}

std::string CommandParser::trim(std::string str) {
	auto is_space = [](unsigned char ch) {
		return isspace(ch);
	};
	while (!str.empty() && is_space(str.front())) {
		str.erase(str.begin());
	}
	while (!str.empty() && is_space(str.back())) {
		str.pop_back();
	}
	return str;
}

int main(int argc, char** argv) {
	std::cout << "CLI (type 'help' for help, 'exit' to quit)\n";

	CommandParser parser;
	while (true) {
		std::string line;
		if (!std::getline(std::cin, line)) {
			std::cout << "\n";
			break;
		}
		int code = parser.execute(line);
		// -999 exit
		if (code == -999) {
			break;
		}
	}
	for (int i = 0; i < argc; i++) {
		std::cout << i << ":" << argv[i];
	}
	return 0;
}
