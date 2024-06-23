#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <string>

/*
* 这是一个人的属性
*/
struct AttributeData
{
public:
	AttributeData();
	~AttributeData();
	std::string _name; // 姓名
	std::string _gender;    // 性别
	short _age;        // 年纪
	short _height;     // 身高  cm
	double _weight;    // 体重  kg
};

