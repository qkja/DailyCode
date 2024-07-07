#pragma once
#include <iostream>

class A {
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}
	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

//class B {
//public:
//	B()
//	{
//
//	}
//	~B()
//	{
//
//	}
//private:
//	A a;
//};