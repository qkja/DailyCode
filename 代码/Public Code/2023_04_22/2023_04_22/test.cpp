#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <string>

//int main()
//{
//	// ����һ�� ifstream �����ļ�����
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
//	// ����һ�� ifstream �����ļ�����
//	ifstream infile(ifile.c_str()); // �Զ��ķ�ʽ��һ���ļ�
//
//	if (!infile) {
//		cerr << "error: unable to open input file: "
//			<< ifile << endl;
//		return -1;
//	}
//	string ofile = ifile + ".sort";  
//	// ����һ�� ofstream ����ļ�����
//	ofstream outfile(ofile.c_str()); //Ӧ������д�ķ�ʽ��һ���ļ�
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
//		// ����Ӧ�������ǰ���һ���ո������һ���ַ�,�Ͼ��ո��ǿհ��ַ�
//		text.push_back(buffer);
//		// ����Ӧ����Ϊ�˸�ʽ��������Ӻÿ�Щ
//		//ÿһ��ռ��8���ַ�,�ַ����ַ�֮�侭���Կո�ָ�
//		cout << buffer << (cnt++ % 8 ? " " : "\n");
//	}
//
//	sort(text.begin(), text.end());
//	// ok: �������Ĵʴ�ӡ�� outfile
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
		ostringstream out_message; // ����Ӧ���� �� ����д�뵽һ���ַ���
		out_message << "error: "
			<< program_name << "--" << version
			<< ": " << __FILE__ << ": " << __LINE__
			<< " -- ptr is set to 0; "
			<< " must address some array.\n";
		// ���صײ� string ����
		return out_message.str();
	}
	// ...
}

int  main()
{
	int a = 10;

	return 0;
}