#pragma once
#include <string>

int multi(int& i) {
	i *= i;
	return i;
}

void specialtricks() {
	static int i = 5;
	printf("i is %d\n", ++i);
	i = 42;
	printf("i is %d\n", ++i);
}

const string& staticstring() {
	static string s = "This string right?";
	return s;
}