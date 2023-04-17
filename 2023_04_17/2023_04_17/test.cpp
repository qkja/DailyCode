#include <iostream>
class A
{
public:
	void func()const
	{
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		
		a = 20;
	/*	A* p = const_cast<A*>(this);
		p->a = 20;
		p->b = 20;
*/
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}
private:
	mutable int a = 10;
	int b = 10;
};

int main()
{
	A().func();
	return 0;
}