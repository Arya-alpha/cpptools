// cli.cpp: 定义应用程序的入口点。
//

#include "cli.h"

using namespace std;
using namespace cli;

int CommandParser::execute(const std::string& str) {
	std::string s = trim(str);
	if (s.empty()) {
		return 0;
	}

	//std::cout << "trim" << s;
	std::vector<std::string> args = splitToArg(str);
	// exit
	if (args[0] == "exit") {
		return -999;
	}

	return 0;
}

std::vector<std::string> CommandParser::splitToArg(std::string str) {
	std::vector<std::string> list;
	return list;
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
		string line;
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
