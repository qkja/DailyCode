#include <iostream>
#include "FileRenamerTurbo.hpp"
int main()
{
	string str = "C:\\Users\\qkj12\\OneDrive\\�鼮";
	file_renamer_turbo(str);
	/*if (0 == rename("E:\\DailyCode\\2023_10_19\\AllFiles.txt", "00 aaaa.txt"))
	{

	}
	else
	{
		cout << "ʧ��" << endl;
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