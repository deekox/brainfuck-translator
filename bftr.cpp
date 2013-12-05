#include <iterator>
#include <string>
#include <fstream>
#include <iostream>
#include "Generator.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " file\n";
		exit(EXIT_FAILURE);
	}

	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "can't open file" << argv[1] << std::endl;
		exit(EXIT_FAILURE);
	}

	std::istreambuf_iterator<char> iit(file.rdbuf()), eos;
	std::string cnt(iit, eos);
	file.close();
	std::cout << "file size: " << cnt.size() << std::endl;
	Generator g(cnt);
}
