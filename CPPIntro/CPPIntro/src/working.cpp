#include <cstdio>
using namespace std;
#include "functions.h"

const char* prompt() {
	puts("choose an option:");
	puts("1. Function fa()");
	puts("2. Function fb()");
	puts("3. Function fc()");
	puts("4. Function fd()");
	puts("5. Function fe()");
	puts("Q. Quit.");
	printf(">> ");

	fflush(stdout);					//flush after prompt
	const int buffsz = 3;			//constant for buffer size
	static char response[buffsz];	//static storage for response buffer
	fgets(response, buffsz, stdin);	//get response from console

	return response;
}

void fa() { printf("this is fa()\n"); }
void fb() { printf("this is fb()\n"); }
void fc() { printf("this is fc()\n"); }
void fd() { printf("this is fd()\n"); }
void fe() { printf("this is fe()\n"); }

void(*funcs[])() = { fa, fb, fc, fd, fe, nullptr }; //array of function pointers

int jump(const char* rs) {
	char code = rs[0];
	if (code == 'q' || code == 'Q') return 0;

	//count the length of the func array
	int func_length = 0;
	while (funcs[func_length] != NULL) func_length++;

	int i = (int)code - '0'; //convert ASCII numeral to int
	i--; //list is zero-based - user types one, convert to zero
	if (i < 0 || i >= func_length) {
		puts("invalid choice");
		return 1;
	}
	else {
		funcs[i]();
		return 1;
	}

}

unsigned long int factorial(unsigned long int n) {

	unsigned long int ans = 1;

	for (; n > 1; n--) {
		ans *= n;
	}

	return ans;
}

int main(int argc, char** argv) {
	puts("Hello, World!");

	int ia[] = { 1,2,3,4,5 };
	for (auto i : ia) {
		printf("i is %d\n", i);
	}

	printf("Pointers & References\n");
	int x = 7;
	int y = 42;
	int* ip = &x;

	printf("x = %d y = %d *ip = %d\n", x, y, *ip);
	ip = &y;
	printf("ip = &y. x = %d y = %d *ip = %d\n", x, y, *ip);
	int &ay = y;
	printf("&ay = y. x = %d y = %d *ip = %d ay = %d\n", x, y, *ip, ay);
	ay = 100;
	printf("ay = 100. x = %d y = %d *ip = %d ay = %d\n", x, y, *ip, ay);
	ip = &y;
	printf("ip = &y. x = %d y = %d *ip = %d\n", x, y, *ip);
	ay = x;
	printf("ay = x. x = %d y = %d *ip = %d ay = %d\n", x, y, *ip, ay);

	printf("Arrays\n");

	int numbers[5];
	numbers[4] = 10;
	numbers[0] = 01;
	printf("numbers[0] = 01. *numbers = %d, *numbers = %d\n", numbers[0], *numbers);
	*numbers = 2;
	printf("*numbers = 2. numbers[0] = %d, *numbers = %d\n", numbers[0], *numbers);
	int* inumbers = numbers;
	printf("*inumbers = numbers. inumbers = %d\n", *inumbers);
	inumbers = &numbers[0];
	printf("inumbers = &numbers[0]. &[]inumbers = %d\n", *inumbers);

	*++inumbers = 3;
	*(++inumbers) = 4;

	for (auto i : numbers) {
		printf("numbers = %d\n", i);
	}

	*inumbers++ = 5;
	*(inumbers++) = 6;

	for (auto i : numbers) {
		printf("numbers = %d\n", i);
	}
	printf("last one = %d\n", *++inumbers);

	char s[] = { 's', 't', 'r'};

	printf("word = %c\n", s[0]);

	for (int p = 0; s[p]; p++) {
		printf("letter1 = %c\n", s[p]);
	}

	for (auto i : s) {
		printf("letter2 = %c\n", i);
	}

	const int iONE = 1;
	const int iTWO = 2;
	const int iTHREE = 3;
	const int iFOUR = 4;
	const int iFIVE = 5;
	int t = 2;

	switch (t)
	{
		case iONE:
			puts("one");
			break;
		case iTWO:
		case iFIVE:
			puts("two");
			break;
		case iTHREE:
			puts("three");
			break;
		case iFOUR:
			puts("four");
			break;
		default:
			break;
	}


	x = 2;
	printf("function returns: %d\n",multi(x));
	printf("new x is: %d\n", x);
	
	specialtricks();
	specialtricks();
	printf("function returns: %s\n", staticstring().c_str());

	//while (jump(prompt()));
	puts("\nDone.");

	unsigned long int fac = 7;
	printf("factorial od %ld is %ld\n", fac, factorial(fac));

	printf("MSC version is %d\n", _MSC_VER);
	return 0;
}