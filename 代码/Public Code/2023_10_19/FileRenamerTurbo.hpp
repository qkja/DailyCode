#include <iostream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
using namespace std;


static bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list)
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

        if (iter->path().extension() != ".pdf")
        {
            continue;
        }
        file_list->push_back(iter->path().string());
    }

    return true;
}


static string parce(const string& str)
{
    //δ����.pdf
    //001 δ����.pdf
    string falg = "0123456789 ";
    //�������е�001
    int i = 0;
    for (; i < str.size(); i++)
    {
        if (falg.find(str[i]) == std::string::npos)
            break;
    }
    return str.substr(i);
}

void file_renamer_turbo(const string& src_path)
{
    std::vector<std::string> file_list;
    if (false == EnumFile(src_path, &file_list))
    {
        std::cerr << "ö���ļ���ʧ��" << std::endl;
        return;
    }

    // ϣ���� 001 --- 999
   /* if (file_list.size() != 49)
    {
        cout << "��������" << endl;
        return;
    }*/
    for (int i = 0; i < file_list.size(); i++)
    {
        string oldName = file_list[i];
        int pos = oldName.rfind('\\');
        if (pos == string::npos)
        {
            continue;
        }
        string title = oldName.substr(0, pos);
        title += "\\";

        string newName = to_string(i + 1);
        if (newName.size() == 1)
        {
            newName = "00";
            newName += to_string(i + 1);
        }
        else if (newName.size() == 2)
        {
            newName = "0";
            newName += to_string(i + 1);
        }
        newName += " ";
        newName += parce(oldName.substr(pos + 1));

        newName = title + newName;
    /*    printf("%s\n",  newName.c_str());*/

        if (rename(oldName.c_str(), newName.c_str()) == 0)
            printf("%s\n",  newName.c_str());
        else
            printf("ʧ��\n");
    }
}


