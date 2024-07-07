#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
struct Data
{

	int _time;                                      // 时间戳
	double _density;                                // 密度
	double _differentialPressure;                   // 一次风动压测点
	double  _primaryAirTemperatureMeasuringPoint;   //一次风温测点
	double pulverizedCoalTemperatureMeasuringPoint; //煤粉温度测点
	double MixedTemperatureMeasuringPoint;          //混合温度测点
};
using namespace std;
int theNumberOfDataInARow(const std::string& str)
{
	if (str.empty())
		return 0;
	int num = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ',')
			num++;
	}
	return num;
}

void slicedString(std::vector<std::string>* v, const std::string& str)
{
	
}

int main()
{
	//读取文件中的数据
	ifstream ifs;							//创建流对象

	ifs.open("./test.csv", ios::in);	//打开文件

	if (!ifs.is_open())						//判断文件是否打开
	{
		return 0;
	}
	vector<string> v;		//用于存放文件中的一行数据
	string str;			    //存放一行数据

	while (getline(ifs, str))  //利用 getline（）读取文件中的每一行，并放入到 item 中
	{
		v.push_back(str);
	}

	// 计算一行数据的个数
	std::cout << theNumberOfDataInARow(v[0]) << std::endl;
	int num = theNumberOfDataInARow(v[0]);
	std::vector<std::string> tmp;

	slicedString(&tmp, v[0]);
	for (int i = 0; i < tmp.size(); i++)
	{
		std::cout << i << " : " << tmp[i] << std::endl;
	} 

	for (int i = 1; i < v.size(); ++i)
	{
		std::vector<std::string> tmp;

	}
	// 处理每一个数据



	
	//std::cout << item[0] << std::endl;

	//遍历文件中的每一行数据
	//for (auto it = item.begin(); it != item.end(); it++)
	//{
	//	string str;

	//	//其作用是把字符串分解为单词(在此处就是把一行数据分为单个数据)
	//	istringstream istr(*it);

	//	//将字符串流 istr 中的字符读入到 str 字符串中，读取方式是以逗号为分隔符 
	//	getline(istr, str, ',');
	//	cout << str << "\t";            // str 对应第一列数据
	//	//atoi(str.c_str())该函数将字符转化为 int 数据            

	//	getline(istr, str, ',');
	//	cout << str << "\t";            // str 对应第二列数据 

	//	getline(istr, str, ',');
	//	cout << str << "\t";            // str 对应第三列数据   

	//	getline(istr, str, ',');
	//	cout << str << "\t";            // str 对应第四列数据 

	//	getline(istr, str, ',');
	//	cout << str << "\t";            // str 对应第五列数据 

	//	getline(istr, str, ',');
	//	cout << str << endl;            // str 对应第六列数据    
	//}

	system("pause");
	return 0;
}