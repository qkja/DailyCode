#include <iostream>
#include "FileRenamerTurbo.hpp"
int main()
{
	string str = "C:\\Users\\qkj12\\OneDrive\\书籍";
	file_renamer_turbo(str);
	/*if (0 == rename("E:\\DailyCode\\2023_10_19\\AllFiles.txt", "00 aaaa.txt"))
	{

	}
	else
	{
		cout << "失败" << endl;
	}*/
	return 0;
}














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
////    //文件句柄 
////    long  hFile = 0;
////    //文件信息 
////    struct _finddata_t fileinfo; //很少用的文件信息读取结构
////    string p; //string类很有意思的一个赋值函数:assign()，有很多重载版本
////    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
////    {
////        do
////        {
////            if ((fileinfo.attrib & _A_SUBDIR)) //判断是否为文件夹
////            {
////                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
////                {
////                    files.push_back(p.assign(path).append("\\").append(fileinfo.name));//保存文件夹名字
////                    getAllFiles(p.assign(path).append("\\").append(fileinfo.name), files);//递归当前文件夹
////                }
////            }
////            else  //文件处理
////            {
////                files.push_back(p.assign(path).append("\\").append(fileinfo.name));//文件名
////            }
////        } while (_findnext(hFile, &fileinfo) == 0); //寻找下一个，成功返回0，否则-1
////        _findclose(hFile);
////    }
////}
////
////int main()
////{
////    string DATA_DIR = "E:\\DailyCode\\2023_10_19";
////    vector<string> files;
////    //测试
////    const char* DistAll = "AllFiles.txt";
////    getAllFiles(DATA_DIR, files);//所有文件与文件夹的路径都输出
////    ofstream ofn(DistAll); //输出文件流
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
////测试
////int main()
////{
////    string DATA_DIR = "E:\\DailyCode\\2023_10_19";
////    vector<string> files;
////    //测试
////    //char* DistAll = "AllFiles.txt";
////    getAllFiles(DATA_DIR, files);//所有文件与文件夹的路径都输出
////    //ofstream ofn(DistAll); //输出文件流
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
////	// 这是一个文件属性的类型
////	struct _finddata_t fileinfo;
////	string p;
////	// _findfirst(p.assign(path).append("\\*").c_str() 将我们目录进行拼接
////	if (hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo) != -1)
////	{
////		do
////		{
////			if ((fileinfo.attrib & _A_SUBDIR))
////			{
////				// 是一个文件夹
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
//    namespace fs = boost::filesystem; // 这是一个习惯, C++支持
//    fs::path root_path(src_path);     // 定义一个path对象
//
//    if (fs::exists(root_path) == false) // 判断路径是不是存在
//    {
//        std::cerr << src_path << " 路径是不存在的" << std::endl;
//        return false;
//    }
//
//    // 定义一个空的迭代器, 用来判断 迭代器递归结束
//    fs::recursive_directory_iterator end;
//    for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
//    {
//        // 保证是普通的文件
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
//    //未标题.pdf
//    //001 未标题.pdf
//    string falg = "0123456789 ";
//    //清晰所有的001
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
//		std::cerr << "枚举文件名失败" << std::endl;
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
// /*   string oldName = "E:\\DailyCode\\2023_10_19\\未标题.pdf";
//    string newName = "E:\\DailyCode\\2023_10_19\\0001 未标题.pdf";*/
//
//    //rename(oldName.c_str(), newName.c_str());
//    // 重命名一个文件
//	return 0;
//}