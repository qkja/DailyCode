//#include <boost/filesystem.hpp> // ����boost��
//#include <iostream> 
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <fstream>
//
//#include <cstdio>
//#include <set>
//
//bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list, const std::string& suffix)
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
//        // ��ͨ�ļ���Ҫ html �ļ���׺����
//        if (iter->path().extension() != suffix)
//        {
//            continue;
//        }
//        file_list->push_back(iter->path().string());
//    }
//
//    return true;
//}
//bool isEmpty(const std::string& path)
//{
//    std::ifstream ifs;
//    ifs.open(path, std::ios::in);
//    std::string line;
//    std::getline(ifs, line);
//    ifs.close();
//    return line.empty();
//}
//
//
//void porse(std::vector<std::string>& v)
//{
//    for (auto& e : v)
//    {
//        auto p1 = e.rfind('.');
//        auto p2 = e.rfind('\\');
//        e = e.substr(p2 + 1, p1 - p2 - 1);
//    }
//}
//
//
//
//
//int main()
//{
//    std::string path1 = "labels\\val";
//    std::string suffix1 = ".txt";
//    std::vector<std::string> file_list1;
//    EnumFile(path1, &file_list1, suffix1);
//
//    // ����ͼƬ��
//    std::string path2 = "images\\val";
//    std::string suffix2 = ".jpg";
//    std::vector<std::string> file_list2;
//    EnumFile(path2, &file_list2, suffix2);
//
//
//    std::cout << file_list1.size() << std::endl;
//    std::cout << file_list2.size() << std::endl;
//
//    porse(file_list1);
//    porse(file_list2);
//
//    std::set<std::string> s;
//    for (auto& e : file_list1)
//    {
//        s.insert(e);
//    }
//
//    int count = 0;
//    for (auto& e : file_list2)
//    {
//        auto iter = s.find(e);
//        if (iter == s.end())
//        {
//            std::string path = "./images/val/";
//            path += e;
//            path += ".jpg";
//            std::cout << path << std::endl;
//            remove(path.c_str());
//            //++count;
//        }
//    }
//    //std::cout << count << "  " << file_list2.size() - file_list1.size() << std::endl;
//    return 0;
//}
//







#include <boost/filesystem.hpp> // ����boost��
#include <iostream> 
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <set>

bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list, const std::string& suffix)
{
    assert(file_list);
    namespace fs = boost::filesystem; // ����һ��ϰ��, C++֧��
    fs::path root_path(src_path);     // ����һ��path����

    if (fs::exists(root_path) == false) // �ж�·���ǲ��Ǵ���
    {
        std::cerr << src_path << " ·���ǲ����ڵ�" << std::endl;
        return false;
    }

    // ����һ���յĵ�����, �����ж� �������ݹ����
    fs::recursive_directory_iterator end;
    for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
    {
        // ��֤����ͨ���ļ�
        if (fs::is_regular_file(*iter) == false)
        {
            continue;
        }

        // ��ͨ�ļ���Ҫ html �ļ���׺����
        if (iter->path().extension() != suffix)
        {
            continue;
        }
        file_list->push_back(iter->path().string());
    }

    return true;
}


void porse(std::vector<std::string>& v)
{
    for (auto& e : v)
    {
        auto p1 = e.rfind('.');
        auto p2 = e.rfind('\\');
        e = e.substr(p2 + 1, p1 - p2 - 1);
    }
}

int main()
{
    std::string path1 = "labels\\train";
    std::string suffix1 = ".txt";
    std::vector<std::string> file_list1;
    EnumFile(path1, &file_list1, suffix1);

    // ����ͼƬ��
    std::string path2 = "images\\train";
    std::string suffix2 = ".jpg";
    std::vector<std::string> file_list2;
    EnumFile(path2, &file_list2, suffix2);


    porse(file_list1);
    porse(file_list2);

    std::set<std::string> s;
    for (auto& e : file_list1)
    {
        s.insert(e);
    }

    int count = 0;
    for (auto& e : file_list2)
    {
        auto iter = s.find(e);
        std::cout << e << std::endl;

        if (iter == s.end())
            ++count;
    }
    std::cout << count << std::endl;
    return 0;
}