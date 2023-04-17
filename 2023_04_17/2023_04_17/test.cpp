#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//class A
//{
//public:
//	void func()const
//	{
//		std::cout << "a: " << a << std::endl;
//		std::cout << "b: " << b << std::endl;
//		
//		a = 20;
//	/*	A* p = const_cast<A*>(this);
//		p->a = 20;
//		p->b = 20;
//*/
//		std::cout << "a: " << a << std::endl;
//		std::cout << "b: " << b << std::endl;
//	}
//private:
//	mutable int a = 10;
//	int b = 10;
//};
//
//int main()
//{
//	A().func();
//	return 0;
//}

#include <cstring>

//char * strcpy(char * destination, const char * source);
//char * my_strcpy(char * destination, const char * source)
//{
//	// 首先我们这么不关心 该参数是都存在问题,有问题你直接去报错吧
//	int len = strlen(source);
//	for (int i = 0; i < len+1; i++)
//	{
//		*(destination + i) = *(source + i);
//	}
//	return destination;
//}
//
//int main()
//{
//	char arr[100] = { 0 };
//	const char* p = "abced";
//	p = my_strcpy(arr, p);
//	while (*(p) != '\0')
//	{
//		std::cout << *p << std::endl;
//		p++;
//	}
//	return 0;
//}
//Appends a copy of the source string to the destination string
//int main()
//{
//	char str[80];
//	strcpy(str, "these ");
//	strcat(str, "strings ");
//	strcat(str, "are ");
//	strcat(str, "concatenated.");
//	puts(str);
//	return 0;
//}

//////////////////////////////////////////////////////////////////////////////////////


// C++中的模板  -- 也就是静态多态

// 函数模板 --> 需要两次编译
//template < class T1...>
//T1 func(T1 t)

//说一下,我们函数模板一般是不需要指定我们的模板参数的具体类型的,毕竟我们的形参可以推导出来,
//这里有个特殊的情况,如果我们的没有形参可以推导,此时需要显示指定例如
//template < class T1...>
//T1 func(int t)             -----> func<double>(1)


// 类模板   --> 显示指定我们的类型
// 自我感觉类模板的存在主要是为了我们的类中的类型存在的,毕竟我们后面的STL,注意一下我们的类模板如果里面的成员函数
// 定义和模板进行分离,那么注意要带上类模板



// 模板参数可以缺省,不用从右往左,不过我们最好从右往左,因为下面的你无法调用
//template<class T = int, typename K>
//T func(int n)
//{
//	return n;
//}
//
//int main()
//{
//	int ret = func<double>(10);
//	std::cout << ret << std::endl;
//	return 0;
//}

//进阶

// 模板参数  --> 
// 类型模板参数  --> 不支持隐式类型转换  --> 非常好
// 非类型模板参数--> 











//模板特化
// 半特化
// 全特化

//template<>
//bool Less<int*>(int* left, int* right)
//  全特化
//template<>
//class Data<int, char>
// 半特化
//template <class T2>
//class Data<int, T2>
// 半特化
// 半特化

//#define min(a,b) ((a) < (b) ? (a) : (b))
//const int size = 10;
//int ia[size];
//int main() {
//	int elem_cnt = 0;
//	int *p = &ia[0];
//	// 计数数组元素的个数
//	//((p++) < (b) ? (p++) : (b))
//	while (min(p++, &ia[size]) != &ia[size])
//		++elem_cnt;
//	cout << "elem_cnt : " << elem_cnt
//		<< "\texpecting: " << size << endl;
//	return 0;
//}