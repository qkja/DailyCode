#include <iostream>
#include <string>
using namespace std;
//typedef void (*ViPointer)();
//
//class A
//{
//public:
//    virtual void func()
//    {
//        cout << "a" << endl;
//    }
//
//private:
//    int _a = 1;
//};
//class B : public A
//{
//public:
//    virtual void func()
//    {
//        cout << "b" << endl;
//    }
//
//private:
//    int _a = 1;
//};
//class C : public A
//{
//public:
//    virtual void func()
//    {
//        cout << "c" << endl;
//    }
//
//private:
//    int _a = 1;
//};
//void print_virtual_function_table(void* p)
//{
//    ViPointer* ptr = (ViPointer*)(*((long long*)p));
//    int i = 0;
//
//     while (*(int*)(ptr+i) && ptr[i]!= nullptr)
//    //while (ptr[i] != (ViPointer)0x600db0)
//    {
//        printf("[%d] : %p\n", i, ptr[i]);
//        ptr[i]();
//        i++;
//    }
//}
/**
 * User: Qkj
 * Description:模拟
 * Date: 2023-07-09
 * Time: 22:07
 */
//#include <string>
//using namespace std;
//
//// https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
//class Solution
//{
//public:
//    string modifyString(string s)
//    {
//        for (int i = 0; i < s.size(); i++)
//        {
//            int prev = i - 1;
//            int next = i + 1;
//            if (s[i] == '?')
//            {
//                if (prev >= 0)
//                {
//                    // 只需要关心 next的
//                    if (next < s.size())
//                    {
//                        if (s[next] != '?')
//                        {
//                            for (int j = 0; j < 26; j++)
//                            {
//                                if ('a' + j != s[prev] && 'a' + j != s[next])
//                                {
//                                    s[i] = 'a' + j;
//                                    break;
//                                }
//                            }
//                        }
//                        else
//                        {
//                            s[i] = s[prev] == 'z' ? 'a' : s[prev] + 1;
//                        }
//                    }
//                    else if (next == s.size())
//                    {
//                        s[i] = s[prev] == 'z' ? 'a' : s[prev] + 1;
//                    }
//                }
//                else
//                {
//                    if (next < s.size())
//                    {
//                        if (s[next] != '?')
//                        {
//                            for (int j = 0; j < 26; j++)
//                            {
//                                if ('a' + j != s[next])
//                                {
//                                    s[i] = 'a' + j;
//                                    break;
//                                }
//                            }
//                        }
//                        else
//                        {
//                            s[i] = 'a';
//                        }
//                    }
//                    else if (next == s.size())
//                    {
//                        s[i] = 'a';
//                    }
//                }
//            }
//        }
//        return s;
//    }
//};
//int main()
//{
//    Solution().modifyString("??yw?ipkj?");
//    return 0;
//}
//int main()
//{
//    // cout << sizeof(A) << endl;
//    // A a;
//    // cout << sizeof(int *) << endl;
//    // print_virtual_function_table(&a);
//
//    A a;
//    B b;
//    //C c;
//    print_virtual_function_table(&a);
//    print_virtual_function_table(&b);
//    //print_virtual_function_table(&c);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//
//int is_prime_number(int val)
//{
//    for (int i = 2; i <= sqrt(1.0*val); i++)
//    {
//        if (val % i == 0)
//            return 0;
//    }
//    return 1;
//}
//
//int main()
//{
//    for (int i = 100; i < 200; i++)
//    {
//        if (is_prime_number(i) == 1)
//            printf("%d ", i);
//    }
//    printf("\n");
//
//    return 0;
//}
//#include <stdio.h>
//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}
//#include <stdio.h>
//int my_strlen(char* ret)
//{
//	int count = 0;
//	while (ret[count++] != '\0')
//	{
//	}
//	return count;
//}
//
//char* my_strcpy(char* destination, const char* source)
//{
//	int count = 0;
//	while (destination[count] = source[count++])
//	{
//	}
//	return destination;
//}
//
//int main()
//{
//	char arr1[10] = { 0 };
//	const char* arr2 = "abc";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}