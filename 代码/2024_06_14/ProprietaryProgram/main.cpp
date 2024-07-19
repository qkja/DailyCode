#include "ProprietaryProgram.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include "Configuration.h"
#include "AttributeData.h"
Configuration configuration;  // һ��ȫ�ֱ���
void memu()
{

    AttributeData user;
    std::cout << "***********************************"<< std::endl;
    std::cout << "�������һ��ʹ�øó���, ������һЩ����" << std::endl;
    std::cout << "***********************************" << std::endl;
    std::cout << "�������������" << std::endl;
    std::cin >> user._name;
    user._name += "_user";
    std::cout << "����������Ա�" << std::endl;
    std::cout << "1 �� 2 Ů 3 ����" << std::endl;
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
