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
//	// ����������ô������ �ò����Ƕ���������,��������ֱ��ȥ�����
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


// C++�е�ģ��  -- Ҳ���Ǿ�̬��̬

// ����ģ�� --> ��Ҫ���α���
//template < class T1...>
//T1 func(T1 t)

//˵һ��,���Ǻ���ģ��һ���ǲ���Ҫָ�����ǵ�ģ������ľ������͵�,�Ͼ����ǵ��βο����Ƶ�����,
//�����и���������,������ǵ�û���βο����Ƶ�,��ʱ��Ҫ��ʾָ������
//template < class T1...>
//T1 func(int t)             -----> func<double>(1)


// ��ģ��   --> ��ʾָ�����ǵ�����
// ���Ҹо���ģ��Ĵ�����Ҫ��Ϊ�����ǵ����е����ʹ��ڵ�,�Ͼ����Ǻ����STL,ע��һ�����ǵ���ģ���������ĳ�Ա����
// �����ģ����з���,��ôע��Ҫ������ģ��



// ģ���������ȱʡ,���ô�������,����������ô�������,��Ϊ��������޷�����
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

//����

// ģ�����  --> 
// ����ģ�����  --> ��֧����ʽ����ת��  --> �ǳ���
// ������ģ�����--> 











//ģ���ػ�
// ���ػ�
// ȫ�ػ�

//template<>
//bool Less<int*>(int* left, int* right)
//  ȫ�ػ�
//template<>
//class Data<int, char>
// ���ػ�
//template <class T2>
//class Data<int, T2>
// ���ػ�
// ���ػ�

//#define min(a,b) ((a) < (b) ? (a) : (b))
//const int size = 10;
//int ia[size];
//int main() {
//	int elem_cnt = 0;
//	int *p = &ia[0];
//	// ��������Ԫ�صĸ���
//	//((p++) < (b) ? (p++) : (b))
//	while (min(p++, &ia[size]) != &ia[size])
//		++elem_cnt;
//	cout << "elem_cnt : " << elem_cnt
//		<< "\texpecting: " << size << endl;
//	return 0;
//}