#include <iostream>
#include "log.h"
void Log1(const char* message) {
	std::cout << message << std::endl;
}
void Log(const char* message) {
	Log1("message");
	std::cout << message << std::endl;
}