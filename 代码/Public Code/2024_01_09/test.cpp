#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <set>
#include <boost/filesystem.hpp> // 引入boost库
using namespace std;

static bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list, const string& str)
{
	assert(file_list);
	namespace fs = boost::filesystem; // 这是一个习惯, C++支持
	fs::path root_path(src_path);     // 定义一个path对象

	if (fs::exists(root_path) == false) // 判断路径是不是存在
	{
		std::cerr << src_path << " 路径是不存在的" << std::endl;
		return false;
	}

	// 定义一个空的迭代器, 用来判断 迭代器递归结束
	fs::recursive_directory_iterator end;
	for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
	{
		// 保证是普通的文件
		if (fs::is_regular_file(*iter) == false)
		{
			continue;
		}

		// 普通文件需要 html 文件后缀结束
		if (iter->path().extension() != str)
		{
			continue;
		}
		file_list->push_back(iter->path().string());
	}

	return true;
}
string func(const string& str)
{
	auto pos1 = str.rfind('.');
	auto pos2 = str.rfind('\\');
	return str.substr(pos2 + 1, pos1 - pos2 - 1);
}
void parse(const vector<string>& v, set<string>* s)
{
	for (auto& e : v)
	{
		s->insert(func(e));
	}
}
int main()
{
	string path_images = "D:\\Code\\Yolov5\\Test08\\yolov5-master\\data\\mask\\release\\images\\val";
	string path_lables = "D:\\Code\\Yolov5\\Test08\\yolov5-master\\data\\mask\\release\\lables\\val";
	vector<string> images;
	vector<string> lables;
	EnumFile(path_images, &images, ".jpg");
	EnumFile(path_lables, &lables, ".txt");
	cout << images.size() << "   " << lables.size() << endl;
	cout << images[0] << endl;
	cout << lables[0] << endl;
	set<string> s;
	parse(images, &s);
	cout << *(s.begin()) << endl;

	for (auto& e : lables)
	{
		auto str = func(e);
		if (s.find(str) == s.end())
		{
			remove(e.c_str());
			cout << e << endl;
		}
	}
	return 0;
}
