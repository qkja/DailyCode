#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <string>

/*
* ����һ���˵�����
*/
struct AttributeData
{
public:
	AttributeData();
	~AttributeData();
	std::string _name; // ����
	std::string _gender;    // �Ա�
	short _age;        // ���
	short _height;     // ���  cm
	double _weight;    // ����  kg
};

