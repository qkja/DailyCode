#include <iostream>
//#include "FileRenamerTurbo.hpp"
//int main()
//{
//	string str = "C:\\Users\\qkj12\\OneDrive\\�鼮";
//	file_renamer_turbo(str);
//	/*if (0 == rename("E:\\DailyCode\\2023_10_19\\AllFiles.txt", "00 aaaa.txt"))
//	{
//
//	}
//	else
//	{
//		cout << "ʧ��" << endl;
//	}*/
//	return 0;
//}
//


//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <assert.h>
//#include <stdio.h>
//#include <fstream>
//#include <string>
//#include <boost/filesystem.hpp>
//using namespace std;
////
////#include <fstream>
////#include <iostream>
////#include <string>
////#include <sstream>
////#include <vector>
////using namespace std;
////void getAllFiles(string path, vector<string>& files)
////{
////    //�ļ���� 
////    long  hFile = 0;
////    //�ļ���Ϣ 
////    struct _finddata_t fileinfo; //�����õ��ļ���Ϣ��ȡ�ṹ
////    string p; //string�������˼��һ����ֵ����:assign()���кܶ����ذ汾
////    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
////    {
////        do
////        {
////            if ((fileinfo.attrib & _A_SUBDIR)) //�ж��Ƿ�Ϊ�ļ���
////            {
////                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
////                {
////                    files.push_back(p.assign(path).append("\\").append(fileinfo.name));//�����ļ�������
////                    getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);//�ݹ鵱ǰ�ļ���
////                }
////            }
////            else  //�ļ�����
////            {
////                files.push_back(p.assign(path).append("\\").append(fileinfo.name));//�ļ���
////            }
////        } while (_findnext(hFile, &fileinfo) == 0); //Ѱ����һ�����ɹ�����0������-1
////        _findclose(hFile);
////    }
////}
////
////int main()
////{
////    string DATA_DIR = "E:\\DailyCode\\2023_10_19";
////    vector<string> files;
////    //����
////    const char* DistAll = "AllFiles.txt";
////    getAllFiles(DATA_DIR, files);//�����ļ����ļ��е�·�������
////    ofstream ofn(DistAll); //����ļ���
////    int size = files.size();
////    int FaiNum = 0;
////    ofn << size << endl;
////    for (int i = 0; i < size; i++)
////    {
////        ofn << files[i] << endl;
////    }
////    ofn.close();
////    return 0;
////}
////����
////int main()
////{
////    string DATA_DIR = "E:\\DailyCode\\2023_10_19";
////    vector<string> files;
////    //����
////    //char* DistAll = "AllFiles.txt";
////    getAllFiles(DATA_DIR, files);//�����ļ����ļ��е�·�������
////    //ofstream ofn(DistAll); //����ļ���
////    int size = files.size();
////    	for (auto str : files)
////		cout << str << endl;
////    //int FaiNum = 0;
////    //ofn << size << endl;
////   /* for (int i = 0; i < size; i++)
////    {
////        ofn << files[i] << endl;
////    }
////    ofn.close();*/
////    return 0;
////}
//
//
////void getAllFiles(string path, vector<string>& files)
////{
////	long hFile = 0;
////	// ����һ���ļ����Ե�����
////	struct _finddata_t fileinfo;
////	string p;
////	// _findfirst(p.assign(path).append("\\*").c_str() ������Ŀ¼����ƴ��
////	if (hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo) != -1)
////	{
////		do
////		{
////			if ((fileinfo.attrib & _A_SUBDIR))
////			{
////				// ��һ���ļ���
////				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
////				{
////					files.push_back(p.assign(path).append("/").append(fileinfo.name));
////					getAllFiles(p.assign(path).append("/").append(fileinfo.name), files);
////				}
////			}
////			else
////			{
////				files.push_back(p.assign(path).append("/").append(fileinfo.name));
////			}
////		} while (_findnext(hFile, &fileinfo) == 0);
////		_findclose(hFile);
////
////	}
////}
////
////int main()
////{
////	//std::string str;
////	//std::string base = "E:\\ReadBook";
////
////	// used in the same order as described above:
////
////	/*str.assign(base);
////	std::cout << str.append("\\*") << '\n';*/
////	//std::cout << str << '\n';
////	string path = "E:\\DailyCode\\2023_10_19";
////	//cout << path << endl;
////
////	vector<string> files;
////	getAllFiles(path, files);
////	for (auto str : files)
////		cout << str << endl;
////	return 0;
//// 
//// D:\VS2022\install\boost_1_83_0
////}
//
//
////b2.exe install --prefix="D:/VS2022/install/boost/Boost/x64" --build-type=complete --toolset=msvc-14.3 threading=multi --build-type=complete address-model=64
//
////b2.exe install --prefix = "C:/tool/Boost/x86" --build - type = complete --toolset = msvc - 14.3 threading = multi --build - type = complete address - model = 32
//
//
//static bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list)
//{
//    assert(file_list);
//    namespace fs = boost::filesystem; // ����һ��ϰ��, C++֧��
//    fs::path root_path(src_path);     // ����һ��path����
//
//    if (fs::exists(root_path) == false) // �ж�·���ǲ��Ǵ���
//    {
//        std::cerr << src_path << " ·���ǲ����ڵ�" << std::endl;
//        return false;
//    }
//
//    // ����һ���յĵ�����, �����ж� �������ݹ����
//    fs::recursive_directory_iterator end;
//    for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
//    {
//        // ��֤����ͨ���ļ�
//        if (fs::is_regular_file(*iter) == false)
//        {
//            continue;
//        }
//
//        if (iter->path().extension() != ".pdf")
//        {
//            continue;
//        }
//        file_list->push_back(iter->path().string());
//    }
//
//    return true;
//}
//
//string func(string str)
//{
//    //δ����.pdf
//    //001 δ����.pdf
//    string falg = "0123456789 ";
//    //�������е�001
//    int i = 0;
//    for ( ;i < str.size(); i++)
//    {
//        if (falg.find(str[i]) == std::string::npos)
//        {
//            break;
//        }
//    }
//    return str.substr(i);
//}
//
//int main()
//{
//	std::vector<std::string> file_list;
//    string src_path = "E:\\DailyCode\\2023_10_19";
//	if (false == EnumFile(src_path, &file_list))
//	{
//		std::cerr << "ö���ļ���ʧ��" << std::endl;
//		return 1;
//	}
//
//	for (int i = 0; i < file_list.size(); i++)
//	{
//		//cout << file_list[i] << endl;
//        string oldName = file_list[i];
//        string title;
//        int pos = oldName.rfind('\\');
//        //if (pos == std::string::npos)
//   
//        title = oldName.substr(0, pos);
//        cout << title << endl;
//        
//        cout << func(oldName.substr(pos + 1)) << endl;
//       
//
//	}
// /*   string oldName = "E:\\DailyCode\\2023_10_19\\δ����.pdf";
//    string newName = "E:\\DailyCode\\2023_10_19\\0001 δ����.pdf";*/
//
//    //rename(oldName.c_str(), newName.c_str());
//    // ������һ���ļ�
//	return 0;
//}
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int* p = (int*)malloc(0);
//	*p = 1;
//	cout << *p << endl;
//	return 0;
//}
//#include <stdio.h>
//typedef struct List_t
//{
//	struct List_t* next;
//	struct List_t* prev;
//	char data[0];
//}list_t;
//int main()
//{
//	printf("%d", sizeof(list_t));
//	return 0;
//}

//#include<stdio.h>
//void fut(int** s, int p[2][3])
//{
//	**s = p[1][1];
//}
//int main()
//{
//	int a[2][3] = { 1,3,5,7,9,11 }, * p;
//	p = (int*)malloc(sizeof(int));
//	fut(&p, a);
//	printf("%d", *p);
//	return 0;
//}


//class Solution {
//public:
//    int multiply(int A, int B) {
//        if (B == 1)
//            return A;
//        return A + multiply(A, B - 1);
//    }
//};

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int result = 0;
//    for (int i = 1; i <= n; ++i)
//    {
//        if (i % 7 == 0 || to_string(i).find('7') != string::npos)
//        {
//            ++result;
//        }
//    }
//    cout << result << endl;
//    return 0;
//}
//// 64 λ������� printf("%lld")

//#include <stdio.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//#define _CRT_SECURE_NO_WARNINGS
//
//void fun(const char* fname, const char* st)
//{
//	
//	std::FILE* myf = nullptr;
//	int i;
//	myf = std::fopen(fname, "w");
//	for (i = 0; i < strlen(st); i++) fputc(st[i], myf);
//	fclose(myf);
//}
//int main()
//{
//	fun("test.txt", "new world");
//	fun("test.txt", "hello,");
//	return 0;
//}

//class Solution {
//public:
//    int trailingZeroes(int n) {
//        int count = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            int j = i;
//            while (j)
//            {
//                if (j % 5 == 0)
//                {
//                    // count++;cout <<i <<"  -> "<< j << endl;
//                    j = j / 5;
//                    count++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//        return count;
//    }
//};

//class Solution {
//public:
//    int trailingZeroes(int n) {
//        int count = 0;
//        while (n != 0) {
//            n = n / 5;
//            count = count + n;
//        }
//        return count;
//    }
//};

//#include <stdio.h>
//
//#define AP 0.0000000001
//
//int main()
//{
//    float n = 0.0f;
//    scanf("%f", &n);
//    int ret = (int)n;
//    if (n - ret >= 0.5)
//    {
//        printf("%d\n", ret + 1);
//    }
//    else
//    {
//        printf("%d\n", ret);
//    }
//    return 0;
//}

//#include<stdio.h>
//#define Mul(x,y) ++x*++y
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int c = 3;
//	printf("%d" , Mul(a + b, b + c));
//	return 0;
//}

//#include <stdio.h>
//#define a 10
//void foo();
//int main()
//{
//	printf("%d..", a);
//	foo();
//	printf("%d", a);
//	return 0;
//}
//void foo() {
//#undef a
//#define a 50
//}

//#include <iostream>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	unordered_map<int, int> m;
//	m[1] = 1;
//	m[2] = 2;
//	while (n--)
//	{
//		int k = 0;
//		cin >> k;
//		auto iter = m.find(k);
//		if (iter == m.end())
//		{
//			for (int i = 3; i <= k; i++)
//			{
//				if (m.find(i) == m.end())
//				{
//					// ����û�� i
//					m[i] = (2 * m[i - 1] + m[i - 2]) % 32767;
//				}
//			}
//		}
//		cout << m[k] << endl;
//	}
//	return 0;
//}
// 64 λ������� printf("%lld")

//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string str;
//    getline(cin, str);
//    int english_count = 0;
//    int array_count = 0;
//    int space_count = 0;
//    int other_count = 0;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] >= 'a' && str[i] <= 'z' \
//            || str[i] >= 'A' && str[i] <= 'B')
//        {
//            english_count++;
//        }
//        else if (str[i] >= '0' && str[i] <= '9')
//        {
//            array_count++;
//        }
//        else if (str[i] == ' ')
//        {
//            space_count++;
//        }
//        else
//        {
//            other_count++;
//        }
//    }
//    cout << english_count << endl;
//    cout << space_count << endl;
//
//    cout << array_count << endl;
//    cout << other_count << endl;
//
//    return 0;
//}
//// 64 λ������� printf("%lld")

#include <vector>
using namespace std;

//class Solution {
//public:
//    vector<int> runningSum(vector<int>& nums) {
//        vector<int> result(nums.size());
//        for (int i = 0; i < nums.size(); i++)
//        {
//            if (i != 0)
//            {
//                result[i] = result[i - 1] + nums[i];
//            }
//            else
//            {
//                result[0] =  nums[i];
//            }
//        }
//        return result;
//    }
//};

//class Solution {
//public:
//    int searchInsert(vector<int>& nums, int target)
//    {
//        
//        int left = 0;
//        int right = nums.size() - 1;
//        while (left <= right)
//        {
//            int mid = (left + right) / 2;
//            if (nums[mid] == target)
//            {
//                return mid;
//            }
//            else if (nums[mid] < target)
//            {
//                left = mid + 1;
//            }
//            else
//            {
//                right = mid - 1;
//            }
//        }
//
//        return left;
//    }
//};

//int main()
//{
//    return 0;
//}

//#include <string>
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//class Solution {
//public:
//    int getDecimalValue(ListNode* head) {
//        string result;
//        while (head)
//        {
//            result += to_string(head->val);
//            head = head->next;
//        }
//        char* ret;
//        int x = (int)strtol(result.c_str(), &ret, 2);
//        return x;
//    }
//};