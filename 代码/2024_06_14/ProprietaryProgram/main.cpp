#include "ProprietaryProgram.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Configuration.h"
#include "AttributeData.h"
Configuration configuration;  // 一个全局变量
void memu()
{

    AttributeData user;
    std::cout << "***********************************"<< std::endl;
    std::cout << "由于你第一次使用该程序, 下面做一些配置" << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "请输入你的名字" << std::endl;
    std::cin >> user._name;
    user._name += "_user";
    std::cout << "请输入你的性别" << std::endl;
    std::cout << "1 男 2 女 3 保密" << std::endl;
    int gender = 0;
    std::cin >> gender;
    switch (gender)
    {
    case 1:
        user._gender = "man";
        break;
    case 2:
        user._gender = "nv";
        break;
    case 3:
        user._gender = "1";
        break;
    default:
        user._gender = "2";
        break;
    }

    configuration.write(user);

}

int main(int argc, char *argv[])
{
    
    if (!configuration.read())
    {
        memu();
    }
    QApplication a(argc, argv);
    ProprietaryProgram w(nullptr, &configuration);
    w.show();
    return a.exec();
}
