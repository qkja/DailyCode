#include <iostream>
#include<Python.h>
using namespace std;
int main()
{
	Py_Initialize();
	if (!Py_IsInitialized())
	{
		printf("faile！");
		return 0;
	}
	PyObject* pModule = NULL;
	PyObject* pFunc1 = NULL;

	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./x64/Release/myfft.py')");
	pModule = PyImport_ImportModule("myfft");
	if (pModule == NULL)
	{
		cout << "没找到" << endl;
	}
	Py_Finalize();

	system("pause");
	return 0;
}
