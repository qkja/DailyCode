#include <iostream>
#include<Python.h>
using namespace std;
//int main()
//{
//	Py_Initialize();
//	if (!Py_IsInitialized())
//	{
//		printf("初始化失败！");
//		return 0;
//	}
//	PyObject* pModule = NULL;//声明变量
//	PyObject* pFunc1 = NULL;// 声明变量
//	//初始化python系统文件路径，保证可以访问到 .py文件
//	PyRun_SimpleString("import sys");
//	PyRun_SimpleString("sys.path.append('')");
//	pModule = PyImport_ImportModule("fft_new");//这里是要调用的文件名
//	if (pModule == NULL)
//	{
//		cout << "没找到" << endl;
//	}
//
//	Py_Finalize();
//
//	system("pause");
//	return 0;
//}
//int main()
//{
//	Py_Initialize();
//
//	PyRun_SimpleString("print ('hello')");
//
//	PyRun_SimpleString("import numpy as np");
//
//	Py_Finalize();
//
//	system("pause");
//	return 0;
//}
//#include<Python.h>
//
//int main() {
//
//	Py_Initialize();  //必要，初始化python解释器
//	Py_Initialize();
//	if (!Py_IsInitialized()) {
//		std::system("pause");
//		return -99;
//	}//查看是否成功初始化
//
//	/*  需要执行的python语句  */
//
//	PyRun_SimpleString("import sys");
//	PyRun_SimpleString("print ('hello')");
//
//	/*  结束需要执行的python  */
//
//	Py_Finalize(); //释放Python资源
//
//	return 0;
//}

//int main()
//{
//	Py_Initialize(); //初始化python解释器
//	if (!Py_IsInitialized()) {
//		std::system("pause");
//		return -99;
//	} //查看python解释器是否成功初始化
//
//	PyObject* pName, * pModule, * pDict, * pFunc; //定义python对象
//
//	pName = PyUnicode_FromString("./fft_new");
//	pModule = PyImport_Import(pName); //载入plot3dfun的模块
//	if (!pModule) {
//		cout << "Can't find fft.py" << endl;
//		std::system("pause");
//		return -98;
//	} //查看是否载入了模块
//
//	pFunc = PyObject_GetAttrString(pModule, "print_test1");
//	if (!pFunc || !PyCallable_Check(pFunc)) {
//		cout << "error: pFunc" << endl;
//		std::system("pause");
//		return -96;
//	}
//
//	//调用print_test函数
//	PyObject_CallObject(pFunc, NULL);
//
//	//销毁python相关
//	Py_DECREF(pName);
//	Py_DECREF(pModule);
//	Py_Finalize();
//}

#include "Python.h"

//int main()
//{
//	Py_Initialize();    // 初始化
//
//	PyRun_SimpleString("print('hello')");
//
//	Py_Finalize();      //释放资源
//}
//#include <fstream>
//
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
	PyRun_SimpleString("sys.path.append('./x64/Release/fft_new.py')");



	pModule = PyImport_ImportModule("fft_new");//这里是要调用的文件名
	if (pModule == NULL)
	{
		cout << "没找到" << endl;
	}

	Py_Finalize();

	//std::cout << "请输入:";
	//std::string str;
	//std::cin >> str;

	return 0;
}

