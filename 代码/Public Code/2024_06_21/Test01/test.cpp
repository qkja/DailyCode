#include <iostream>


//int main()
//{
//	int a = 5;
//	int b = 6;
//	a += b++;
//
//	printf("%d", a);
//	return 0;
//}
//class Date
//{
//protected:
//	int year;
//	int mon;
//public:
//	//bool operator==(Date& x)
//	//{
//	//	return this->year == x.year && this->mon == x.mon;
//	//}
//};
//
//bool operator==(Date& d1, Date& d2)
//{
//	return d1.year == d2.year && d1.mon == d1.mon;
//}
//
//
//
//int main()
//{
//	Date d1;
//	Date d2;
//	if (d1 == d2)
//	{
//		std::cout << "xxx" << std::endl;
//	}
//	return 0;
//}

void fun(int* n)
{

	while ((*n)--)
	{
		std::cout << *n << std::endl;
	}
	std::cout << *n << std::endl;

	printf("%d", ++(*n));
}


int main()
{
	int a = 1;
	fun(&a);
}
