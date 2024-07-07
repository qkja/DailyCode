#include <iostream>
#include<Python.h>
using namespace std;
int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		printf("初始化失败！");
		return 0;
	}
	PyObject* pModule = NULL;//声明变量
	PyObject* pFunc1 = NULL;// 声明变量
	//初始化python系统文件路径，保证可以访问到 .py文件
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./')");
	pModule = PyImport_ImportModule("fft");//这里是要调用的文件名
	if (pModule == NULL)
	{
		cout << "没找到" << endl;
	}
	Py_Finalize();

	system("pause");
	return 0;
}

