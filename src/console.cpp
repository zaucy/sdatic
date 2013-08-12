#include <cstring>
#include <cstdio>
#include <fstream>
#include <iostream>

#include "sdatic.h"

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sigIntHandler(sig_atomic_t sig) {
	std::cout << "\n";
	exit(0);
}

int main(int argc, char *argv[]) {
	if(argc > 1) {
		for(std::size_t i=1; argc > i; i++) {
			if(std::string(argv[i]) == "-s" || std::string(argv[i]) == "-S") {
				i++;
				std::fstream file(argv[i]);
				if(file.is_open()) {
					file.seekg(0, std::ios_base::end);
					auto fileSize = file.tellg();
					file.seekg(0, std::ios_base::beg);
					char* buf = new char[fileSize];
					file.read(buf, fileSize);
					std::cout << "parsing '" << argv[i] << "'\n";
					sdatic::parse(std::string(buf, fileSize));
				} else {
					std::cout << "'" << argv[i] << "' won't open!\n";
				}
			}
		}
	} else {

		signal(SIGINT, sigIntHandler);

		for(;;) {
			std::string src;
			std::cout << "> ";
			std::getline(std::cin, src);

			if(!src.empty()) {
				sdatic::parse(src);
			} else {
				std::cout << "\b\b";
			}
		}
	}

	return 0;
}
