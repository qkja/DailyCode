#include "Test.h"

Test::Test(QWidget *parent)
	: QWidget(parent)
{}

Test::~Test()
{}

void Test::func()
{
	std::string str = "qqq";
	emit mySig(str);
}
