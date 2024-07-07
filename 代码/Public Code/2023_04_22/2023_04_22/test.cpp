#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <string>

//int main()
//{
//	// 构造一个 ifstream 输入文件对象
//	std::string ifile = "test.txt";
//	std::ifstream infile(ifile.c_str());
//	char ch = infile.get();
//	while (infile.good())
//	{
//		std::cout << ch;
//		ch = infile.get();
//	}
//	return 0;
//}

//int main() {
//	std::filebuf fb;
//	if (fb.open("test.txt", std::ios::in))
//	{
//		std::istream is(&fb);
//		while (is)
//			printf("%c", char(is.get()));
//		fb.close();
//	}
//	return 0;
//}

//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string ifile;
//	cout << "Please enter file to sort: ";
//	cin >> ifile;
//	// 构造一个 ifstream 输入文件对象
//	ifstream infile(ifile.c_str()); // 以读的方式打开一个文件
//
//	if (!infile) {
//		cerr << "error: unable to open input file: "
//			<< ifile << endl;
//		return -1;
//	}
//	string ofile = ifile + ".sort";  
//	// 构造一个 ofstream 输出文件对象
//	ofstream outfile(ofile.c_str()); //应该是以写的方式打开一个文件
//	if (!outfile) {
//		cerr << "error: unable to open output file: "
//			<< ofile << endl;
//		return -2;
//	}
//
//	string buffer;
//	vector< string > text;
//	int cnt = 1;
//	while (infile >> buffer) {
//		// 这里应该是我们按照一个空格来风格一个字符,毕竟空格是空白字符
//		text.push_back(buffer);
//		// 这里应该是为了格式化输出更加好看些
//		//每一行占据8个字符,字符与字符之间经行以空格分割
//		cout << buffer << (cnt++ % 8 ? " " : "\n");
//	}
//
//	sort(text.begin(), text.end());
//	// ok: 把排序后的词打印到 outfile
//	vector<string>::iterator iter = text.begin();
//	for (cnt = 1; iter != text.end(); ++iter, ++cnt)
//		outfile << *iter
//		<< (cnt % 8 ? " " : "\n");
//	return 0;
//}

#include <string>
#include <sstream>
using namespace std;

string program_name("our_program");
string version("0.01");
// ...
string mumble(int *array, int size)
{
	if (!array) {
		ostringstream out_message; // 这里应该是 把 数据写入到一个字符串
		out_message << "error: "
			<< program_name << "--" << version
			<< ": " << __FILE__ << ": " << __LINE__
			<< " -- ptr is set to 0; "
			<< " must address some array.\n";
		// 返回底层 string 对象
		return out_message.str();
	}
	// ...
}

int  main()
{
	int a = 10;

	return 0;
}