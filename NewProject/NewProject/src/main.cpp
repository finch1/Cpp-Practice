#include <iostream>
#include <string>

using namespace std;

#include "../log.h"

#define LESSON_0 0
#define LESSON_1 1
#define LESSON_2 0

//const used with functions
class Dog {
	int age;
	string name;

	public: Dog() {
		age = 3;
		name = "dummy";
	}
	
	void setAge(const int& a) {
			age = a;
			//a++; //as a is now read only, can't be modified
	}

	void setAge(int& a) {
		age = a;
		//a++; //as a is now read only, can't be modified
	}


	//const return value. in this case we are sending the addresss of the actual copy from the class.
	//so it is important that we make the receiver const so not to alter the value.
	const string& getName() {
		return name;
	}

	//this function will not change any member varables of this class. so ex. age++ gives error.
	//a const func can only call another const func in order to maintain const correctness. ex. getName() inside gives error. 
	void printDogName()const {
		cout << name << " cosnt" << endl;
	}

	//overloading:
	//function without const is different from above. this one shall be called when Dog is not declared const
	void printDogName(){
		cout << name << " non-cosnt" << endl;
	}

};

int main() {

#if LESSON_0
	bool a;
	char b;
	short c;

	std::cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << " " << std::endl;
	int x = 5;
	bool compareResult = x == 5; //== is an equality operator. evaluates condition and returns true or false.
	Log("hello bro");
#endif // 

#if LESSON_1
	/*
		why use const
			const can guards against the wrong behaviour at compile time
			self documenting - this value will not change
			enables compiler to do more optimization
			const means that car can be put in ROM
	*/
	//const - a compile time constraint that an object can not be modified
	const int i = 9;
	int j = 10;
	const int *p1 = &i;	//data pointed to by p1 must be constant, pointer aint
	p1 = &j;		//works ok
	//*p1 = 8;		//cannot assign to a variable declared const	
	//*p1++;		//increments pointer
	//p1++;			//increments pointer
	//(*p1)++;		//if not pointing to const, will dereference and increment 

	int* const p2 = &j; //pointer is constant, data is not. cant point to cont vars

	const int* const p3 = &j; //data and pointer are both const

	double* var = (double*)&i; //single pointers are stored in the stack
	char* buffer = new char[8];
	memset(buffer, 0, 8);
	int a = 5;
	int b = 8;
	int& ref = a; //this is a reference. kinda var of type int address
	ref = b; //now contents of b are passed to a

#endif

#if LESSON_2
	Dog d;

	int i = 9;
	d.setAge(i);
	cout << i << endl;

	string n = d.getName();
	n = "hello";
	cout << n << endl;

	const Dog d2;

	d.printDogName();
	d2.printDogName();

	d.setAge(++i);
	d2.setAge(--i);

#endif


	std::cin.get();

	return 0;
}