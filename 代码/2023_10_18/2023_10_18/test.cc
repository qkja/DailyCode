#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//void fun(char **p)
//{
//	int i;
//	for (i = 0; i < 4; i++)
//		printf("%s", p[i]);
//}
//int main()
//{
//	char *s[6] = { "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
//	printf("%p\n", s);
//	printf("%p\n", s + 1);
//	printf("%p\n", s + 2);
//
//	//fun(s);
//	printf("\n");
//	return 0;
//}

//int main()
//{
//	int *k[10][30];
//	printf("%d\n", sizeof(k));
//	return 0;
//}

//class Solution {
//public:
//	/**
//	* 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	*
//	*
//	* @param str string字符串
//	* @return int整型
//	*/
//	int FirstNotRepeatingChar(string str) {
//		// write code here
//		unordered_map<char, int> m;
//		for (auto & ch : str)
//			m[ch]++;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			auto iter = m.find(str[i]);
//			if (iter->second == 1)
//			{
//				return i;
//			}
//		}
//		return -1;
//	}
//};
//class Solution {
//public:
//	bool isUnique(string astr) {
//		unordered_set<char> s;
//		for (auto& ch : astr)
//			s.insert(ch);
//		return s.size() == astr.size();
//	}
//};

//#include<stdio.h>
//int main()
//{
//	static char *s[] = { "black", "white", "pink", "violet" };
//	char **ptr[] = { s + 3, s + 2, s + 1, s }, ***p;
//	p = ptr;
//	++p;
//	printf("%s", **p + 1);
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	
//	printf("%d\n", sizeof("ab"));
//	return 0;
//}

//class Solution {
//public:
//	bool CheckPermutation(string s1, string s2) {
//		unordered_map<char,int> m;
//		for (auto e : s1)
//		{
//			m[e]++;
//		}
//		for (auto e : s2)
//		{
//			auto iter = m.find(e);
//			if (iter == m.end())
//			{
//				return false;
//			}
//			m[e]--;
//			if (m[e] == 0)
//			{
//				m.erase(e);
//			}
//		}
//		return m.empty();
//	}
//};

//class Solution {
//public:
//	bool canPermutePalindrome(string s) {
//		unordered_map<char, int> m;
//		for (auto e : s)
//		{
//			m[e]++;
//			if (m[e] % 2 == 0)
//			{
//				m.erase(e);
//			}
//		}
//		return m.size() <= 1;
//
//	}
//};

//#include <stdio.h>
//int main()
//{
//	char *str[3] = { "stra", "strb", "strc" };
//	char *p = str[0];
//	int i = 0;
//	while (i < 3)
//	{
//		printf("%s ", p++);
//		i++;
//	}
//	return 0;
//}

//#include <stdio.h>
//int main() {
//	int m[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	int(*p)[4] = (int(*)[4])m;
//	printf("%d", p[1][2]);
//	return 0;
//}

//int main()
//{
//	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
//	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
//	printf("%s", str);
//	return 0;
//}

//#include<stdio.h>
//char* f(char* str, char ch)
//{
//	char* it1 = str;
//	char* it2 = str;
//	while (*it2 != '\0')
//	{
//		while (*it2 == ch)
//		{
//			it2++;
//		}
//		*it1++ = *it2++;
//	}
//	return str;
//}
//int main() {
//	char a[10];
//	strcpy(a, "abcdcccd");
//	printf("%s", f(a, 'c'));
//	return 0;
//}

//#include <cstdio>
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	getchar();
//	for (int i = 0; i < n; i++)
//	{
//		string str;
//		getline(cin, str);
//		if (str.size() >= 10)
//		{
//			string result;
//			result += str[0];
//			result += to_string(str.size() - 2);
//			result += str.back();
//			cout << result << endl;
//		}
//		else
//		{
//			cout << str << endl;
//		}
//	}
//	return 0;
//}
// 64 位输出请用 printf("%lld")
#include <iostream>
#include <string>

using namespace std;
//class Solution {
//public:
//	string replaceSpaces(string S, int length) {
//		string result;
//		for (int i = 0; i < length; ++i)
//		{
//			if (S[i] == ' ')
//			{
//				result += "%20";
//
//			}
//			else
//			{
//				result += S[i];
//			}
//		}
//		return result;
//	}
//};

//int main()
//{
//	char arr[2][4];
//	strcpy(arr[0], "you");
//	strcpy(arr[1], "me");
//	arr[0][3] = '&';
//	printf("%s \n", arr);
//	return 0;
//}
//struct st
//{
//	int *p;
//	int i;
//	char a;
//};
//int sz = sizeof(struct st);
//
//int main()
//{
//	printf("%d \n", sz);
//	return 0;
//}

//enum weekday
//{
//	sun,
//	mon = 3,
//	tue,
//	wed
//};
//
//
//int main()
//{
//	enum weekday workday;
//	workday = wed;
//	printf("%d\n", workday);
//	return 0;
//}

//union D
//{
//	int d1;
//	float d2;
//}d;
//
//int main()
//{
//	/*d.d1 = 10;
//	printf("%lf\n", d.d2);*/
//	d.d2 = 10;
//	printf("%d\n", d.d1);
//
//	return 0;
//}
//class Solution {
//public:
//	string compressString(string s) {
//		if (s.empty())
//			return s;
//		char flag = s[0];
//		int count = 0;
//		string result;
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (s[i] == flag)
//			{
//				count++;
//			}
//			else
//			{
//				result += flag;
//				result += to_string(count);
//				count = 1;
//				flag = s[i];
//			}
//		}
//		result += flag;
//		result += to_string(count);
//		return result.size() < s.size() ? result : s;
//	}
//};

class Solution {
public:
	int exchangeBits(int num) {
		int x = num & 0x55555555;
		int y = num & 0xaaaaaaaa;
		return (x << 1) | (y >> 1);
	}
};